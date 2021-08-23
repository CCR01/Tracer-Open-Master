#pragma once

#include "structDetailEnhancement_superFct.h"


class DetailEnhancement_BGR
{
public:
	DetailEnhancement_BGR();
	~DetailEnhancement_BGR();

	void improveImageQuality_DetailEnhancement_BGR(const cv::Mat& sharpImage, const cv::Mat& blueredImage);

	bestParameterStruct_detailEnhance getBestParameter();
	parameterDetailEnhancement getInitialParameter();
	void setInitialParameter(parameterDetailEnhancement paraDE_initial);
	// calc roi to calc dif
	void calcROI_toCalcDif();
	// find best parameter and save
	void findBestParameter();

	// get filtered image
	cv::Mat getFilteredIma();

private:

	cv::Mat mSharpImage{};
	cv::Mat mBlueredImage{};
	cv::Mat mTempFilteredIma{};

	parameterDetailEnhancement mParaDE{};
	bestParameterStruct_detailEnhance mBestParaDE{};

	cv::Mat mTempDifMat;
	cv::Rect mRoiToCalcDif;
};

class DetailEnhancement_BGR_parallel
{
public:

	void improveImageQuality_DetailEnhancement_BGR_parallel(const cv::Mat& sharpImage, const cv::Mat& blueredImage);
	void initializePrameterDifCores();

	void findBestParameter_DE_parallel();

	void setParameter_global(parameterDetailEnhancement paraDE_global);
	parameterDetailEnhancement getInitalParameter_global();
	bestParameterStruct_detailEnhance getBestParameter();

	void findBestParameterAllCores();

	cv::Mat getFilteredIma();

private:
	cv::Mat mSharpImage{};
	cv::Mat mBlueredImage{};
	cv::Mat mTempFilteredIma{};

	std::vector<bestParameterStruct_detailEnhance> mBestParameter_vec{};
	std::vector<real> mImprovement_vec{};
	std::vector<real> mSharpness_vec{};

	parameterDetailEnhancement mParaDE_core1{};
	parameterDetailEnhancement mParaDE_core2{};
	parameterDetailEnhancement mParaDE_core3{};
	parameterDetailEnhancement mParaDE_core4{};
	parameterDetailEnhancement mParaDE_core5{};
	parameterDetailEnhancement mParaDE_core6{};
	parameterDetailEnhancement mParaDE_core7{};
	parameterDetailEnhancement mParaDE_core8{};
	parameterDetailEnhancement mParaDE_core9{};
	parameterDetailEnhancement mParaDE_core10{};
	parameterDetailEnhancement mParaDE_core11{};
	parameterDetailEnhancement mParaDE_core12{};
	parameterDetailEnhancement mParaDE_core13{};
	parameterDetailEnhancement mParaDE_core14{};
	parameterDetailEnhancement mParaDE_core15{};
	parameterDetailEnhancement mParaDE_core16{};
	parameterDetailEnhancement mParaDE_core17{};
	parameterDetailEnhancement mParaDE_core18{};
	parameterDetailEnhancement mParaDE_core19{};
	parameterDetailEnhancement mParaDE_core20{};
	parameterDetailEnhancement mParaDE_core21{};
	parameterDetailEnhancement mParaDE_core22{};
	parameterDetailEnhancement mParaDE_core23{};
	parameterDetailEnhancement mParaDE_core24{};

	DetailEnhancement_BGR mDE_core1{};
	DetailEnhancement_BGR mDE_core2{};
	DetailEnhancement_BGR mDE_core3{};
	DetailEnhancement_BGR mDE_core4{};
	DetailEnhancement_BGR mDE_core5{};
	DetailEnhancement_BGR mDE_core6{};
	DetailEnhancement_BGR mDE_core7{};
	DetailEnhancement_BGR mDE_core8{};
	DetailEnhancement_BGR mDE_core9{};
	DetailEnhancement_BGR mDE_core10{};
	DetailEnhancement_BGR mDE_core11{};
	DetailEnhancement_BGR mDE_core12{};
	DetailEnhancement_BGR mDE_core13{};
	DetailEnhancement_BGR mDE_core14{};
	DetailEnhancement_BGR mDE_core15{};
	DetailEnhancement_BGR mDE_core16{};
	DetailEnhancement_BGR mDE_core17{};
	DetailEnhancement_BGR mDE_core18{};
	DetailEnhancement_BGR mDE_core19{};
	DetailEnhancement_BGR mDE_core20{};
	DetailEnhancement_BGR mDE_core21{};
	DetailEnhancement_BGR mDE_core22{};
	DetailEnhancement_BGR mDE_core23{};
	DetailEnhancement_BGR mDE_core24{};

	parameterDetailEnhancement mParaDE_global{};
	bestParameterStruct_detailEnhance mBestParaDE_global{};

	cv::Mat mTempDifMat;
	cv::Rect mRoiToCalcDif;
};
