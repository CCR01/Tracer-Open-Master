#pragma once

#include "opencv2/core/core.hpp"
#include "opencv2/core/mat.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"


class ImageSimulationFunctions
{
public:
	ImageSimulationFunctions();
	~ImageSimulationFunctions();
	ImageSimulationFunctions(cv::Mat& ObjectMatrix, int GridFactor);


	// used by CR
	// ***
	void loadPSFs_blue(std::vector<cv::Mat> PSF_vec_blue);
	void loadPSFs_green(std::vector<cv::Mat> PSF_vec_green);
	void loadPSFs_red(std::vector<cv::Mat> PSF_vec_red);
	void setGridFactor(unsigned int gridFactor);
	void imageSimulationSuperFct(cv::Mat initialObj);
	void adaptTheObjectForSimulation();
	cv::Mat getTheAdaptedObject();
	void splitTheBGRImageInColors();
	cv::Mat getAdaptedObj_blue();
	cv::Mat getAdaptedObj_green();
	cv::Mat getAdaptedObj_red();
	
	void separateTheImageInNtimesMimages_final();
	// plot all object grids
	void plotAllObjektGrids(std::vector<cv::Mat> objGrid_vec);
	// get object grid
	std::vector<std::vector<cv::Mat>> getObjGrid();
	// convolution of adapted opject grid with PSF grid
	void convoluteObjectGridWithPSF();
	// 2D convulution
	cv::Mat convolution(const cv::Mat& obj,const cv::Mat& PSF);
	void fillingBlackStrips();
	// put the image grides together
	void putImaGridsTogether_final();
	// put all channles together, scale the image and save the image as CV_8UC 
	void putAllChannlesTogetherScaleAndSaveIma();
	// get the simulated image
	cv::Mat getSimulatedImage();
	void setPixBiggerForConvolution_Row(unsigned int pixBiggerRow);
	void setPixBiggerForConvolution_Col(unsigned int pixBiggerCol);
	// 

	// save that fct
	void separateTheImageInNtimesMimages_saveThatFct_1();
	void separateTheImageInNtimesMimages_saveThatFct_2();
	void putImaGridsTogether_saveThatFct_1();
	void putImaGridsTogether_saveThatFct_2();
	// ***





private:
	cv::Mat mObject;
	cv::Mat mObjectAdapted;
	std::vector<cv::Mat> mObjGrid_CR;
	std::vector<std::vector<cv::Mat>> mObjectGridsMatrix;
	cv::Mat mSimulatedImage;
	
	cv::Mat OTFReady;
	cv::Mat MTFReady;

	cv::Mat ObjectAdapted;
	std::vector<std::vector<cv::Mat>> ObjectGridsMatrix;

	// used by CR
	// ***
	std::vector<cv::Mat> mLoadedPSFs_vec_blue{};
	std::vector<cv::Mat> mLoadedPSFs_vec_green{};
	std::vector<cv::Mat> mLoadedPSFs_vec_red{};
	unsigned int mGridFactor{};
	cv::Mat mInitialObj{};
	cv::Mat mAdaptedObj{};
	cv::Mat mAdaptedObj_blue{};
	cv::Mat mAdaptedObj_green{};
	cv::Mat mAdaptedObj_red{};
	std::vector<cv::Mat> mObjectGrid_blue{};
	std::vector<cv::Mat> mObjectGrid_green{};
	std::vector<cv::Mat> mObjectGrid_red{};
	std::vector<cv::Mat> mSimulatedImageGrid_blue{};
	std::vector<cv::Mat> mSimulatedImageGrid_green{};
	std::vector<cv::Mat> mSimulatedImageGrid_red{};
	cv::Mat mSimulatedIma_blue{};
	cv::Mat mSimulatedIma_green{};
	cv::Mat mSimulatedIma_red{};
	unsigned int mRow_BiggerForConv{};
	unsigned int mCol_BiggerForConv{};

	cv::Mat mSimulatedIma_bgr_unscaled{};
	cv::Mat mSimulatedIma_bgr_final{};
	
	// ***
};

