#pragma once

#include "opencv2/core/core.hpp"
#include "opencv2/core/mat.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"

#include "..\LowLevelTracing\ImportantStructures.h"
#include "..\OpticalSystemElement\OpticalSystemElement.h"


struct  defautParaImaSim
{
public:
	defautParaImaSim();
	~defautParaImaSim();

	// row bigger for convolution
	unsigned int getRowBiggerForConv();
	void setRowBiggerForConV(unsigned int rowBiggerConv);
	// col bigger for convolution
	unsigned int getColBiggerForConv();
	void setColBiggerForConv(unsigned int colBiggerConv);
	// wave blue
	real getWavelengthBlue();
	void setWavelengthBlue(real waveBlue);
	// wave green
	real getWavelengthGreen();
	void setWavelengthGreen(real waveGreen);
	// wave red
	real getWavelengthRed();
	void setWavelengthRed(real waveRed);
	// ray density
	real getRayDensity();
	void setRayDensity(unsigned int rayDensity);
	// light
	Light_LLT getLight();
	void setLight(Light_LLT light);
	// start refractive index
	real getStartRefIndex();
	void setStartRefIndex(real startRefIndex);
	// size matrix to save OPD
	unsigned int getSizeMatrixToSaveOPD();
	void setSizeMatrixToSaveOPD(unsigned int sizeMatrixOPD);
	// inf of obj
	void setInfOrObj(objectPoint_inf_obj inf_obj);
	objectPoint_inf_obj getInfOrObj();
	// row and col resize OPD
	void setRowColResizeOPD(unsigned int rowAndCol);
	unsigned int getRowAndColResizeOPD();

private:
	unsigned int mRow_BiggerForConv{};
	unsigned int mCol_BiggerForConv{};
	real mWavelength_blue{};
	real mWavelength_green{};
	real mWavelength_red{};
	unsigned int mRayDesnity{};
	Light_LLT mLight{};
	real mStartRefIndex{};
	unsigned int mSizeMatrixToSaveOPD{};
	objectPoint_inf_obj mInf_obj{};
	unsigned int mRowColResizeOPD{};
};

class ImageSimulationFunctions
{
public:
	ImageSimulationFunctions();
	~ImageSimulationFunctions();
	ImageSimulationFunctions(cv::Mat& ObjectMatrix, int GridFactor);


	
	// ***
	void setOpticalSystemElement(OpticalSystemElement optSysEle);

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
	
	void separateTheImageInNtimesMimages();
	void separateTheImageInNtimesMimages_saveDoNotUseThat();
	// plot all object grids
	void plotAllObjektGrids(std::vector<cv::Mat> objGrid_vec);
	// convolution of adapted opject grid with PSF grid
	void convoluteObjectGridWithPSF();
	// 2D convulution
	cv::Mat convolution(const cv::Mat& obj,const cv::Mat& PSF);
	void fillingBlackStrips();
	// put the image grides together
	void putImaGridsTogether();
	void putImaGridsTogether_save_doNotUseThatFunction();
	// put all channles together, scale the image and save the image as CV_8UC 
	void putAllChannlesTogetherScaleAndSaveIma();
	// get the simulated image
	cv::Mat getSimulatedImage();

	// 

	// save that fct
	void separateTheImageInNtimesMimages_saveThatFct_1();
	void separateTheImageInNtimesMimages_saveThatFct_2();
	void putImaGridsTogether_saveThatFct_1();
	void putImaGridsTogether_saveThatFct_2();
	// ***

	// calc points to sampling image 
	void calcPointsToSampleObject(/*semi weidth object*/ real semiWeidthObject, /*semi height object*/ real semiHeigtObject, /*sampling*/ unsigned int sampling, /*z pos obejct*/ real zPosObject);
	std::vector<VectorStructR3> getPointsToSampleObj();

	// build optical systems according to the wavelength
	void buildAllOptSysLLT_BGR();
	void buildOpticalSystemBlue();
	void buildOpticalSystemGreen();
	void buildOpticalSystemRed();



	// calculate OPDs
	void calcALL_OPDs();
	void calcOPD_blue();
	void calcOPD_green();
	void calcOPD_red();

	// default parameters
	//***
	void setDefaulParameter(defautParaImaSim defaulParaImaSim);

	void setRowBiggerForConv(unsigned int pixBiggerRow);
	void setColBiggerForConv(unsigned int pixBiggerCol);

	// the wavelength for image simulation
	void setWavelengthBlue(real waveBlue);
	void setWavelengthGreen(real waveGreen);
	void setWavelengthRed(real waveRed);

	// ray density
	real getRayDensity();
	void setRayDensity(unsigned int rayDensity);

	// light
	Light_LLT getLight();
	void setLight(Light_LLT light);

	// start refractive index
	real getStartRefIndex();
	void setStartRefIndex(real startRefIndex);

	// size matrix to save OPD
	unsigned int getSizeMatrixToSaveOPD();
	void setSizeMatrixToSaveOPD(unsigned int sizeMatrixOPD);

	// inf of obj
	void setInfOrObj(objectPoint_inf_obj inf_obj);
	objectPoint_inf_obj getInfOrObj();
	// ***

	// export all calculated OPDs 
	void exportAllCalcOPDs_blue(std::string location);
	void exportAllCalcOPDs_green(std::string location);
	void exportAllCalcOPDs_red(std::string location);

	// row and col resize OPD
	void setRowColResizeOPD(unsigned int rowAndCol);
	unsigned int getRowAndColResizeOPD();

	// scall up all OPDs
	void resizeAllOPDs();

	// calc all PSFs
	void calcAllPSFs();
	void calcAllPSF_blue();
	void calcAllPSF_green();
	void calcAllPSF_red();

	// sample up PSF
	void sampleUP_PSFs_horizontal(unsigned int sampling);
	void sampleUP_PSFs_vertical(unsigned int sampling);

	// rotate matrix by 90°
	cv::Mat rotateMatrixBy_90degrees(cv::Mat& mat);

	cv::Mat flipMatrixHorizontal(cv::Mat& mat);
	cv::Mat flipMatrixVertical(cv::Mat& mat);

	// calculate all PSFs for convolution
	void calcAllPSFsForConv_Q1(unsigned int sampling);
	void calcAllPSFsForConv_Q2andQ3(unsigned int sampling);

	// get functions
	// ***
	// get the LLT systems
	OpticalSystem_LLT getOptSys_blue();
	OpticalSystem_LLT getOptSys_green();
	OpticalSystem_LLT getOptSys_red();

	// get OPDs
	std::vector<cv::Mat> getOPD_blue();
	std::vector<cv::Mat> getOPD_green();
	std::vector<cv::Mat> getOPD_red();

	// get resized OPDs
	std::vector<cv::Mat> getOPD_resized_blue();
	std::vector<cv::Mat> getOPD_resized_green();
	std::vector<cv::Mat> getOPD_resized_red();



	// ***

private:


	// used by CR
	// ***
	defautParaImaSim mDefaultParameterImaSim{};

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


	cv::Mat mSimulatedIma_bgr_unscaled{};
	cv::Mat mSimulatedIma_bgr_final{};
	
	std::vector<VectorStructR3> mObjectPointsSampling{};

	OpticalSystemElement mOptSysEle{};
	OpticalSystem_LLT mOptSysLLT_blue{};	
	OpticalSystem_LLT mOptSysLLT_green{};
	OpticalSystem_LLT mOptSysLLT_red{};
	
	std::vector<cv::Mat> mOPD_vec_blue{};
	std::vector<cv::Mat> mOPD_vec_green{};
	std::vector<cv::Mat> mOPD_vec_red{};

	std::vector<cv::Mat> mOPD_vec_blue_resized{};
	std::vector<cv::Mat> mOPD_vec_green_resized{};
	std::vector<cv::Mat> mOPD_vec_red_resized{};

	std::vector<cv::Mat> mPSF_vec_blue{};
	std::vector<cv::Mat> mPSF_vec_green{};
	std::vector<cv::Mat> mPSF_vec_red{};

	std::vector<cv::Mat> mPSF_vec_blue_sampledUp_horizontal{};
	std::vector<cv::Mat> mPSF_vec_green_sampledUp_horizontal{};
	std::vector<cv::Mat> mPSF_vec_red_sampledUp_horizontal{};

	std::vector<cv::Mat> mPSF_vec_blue_sampledUp_vertical{};
	std::vector<cv::Mat> mPSF_vec_green_sampledUp_vertical{};
	std::vector<cv::Mat> mPSF_vec_red_sampledUp_vertical{};

	std::vector<cv::Mat> mAllPSFForConv_blue{};
	std::vector<cv::Mat> mAllPSFForConv_green{};
	std::vector<cv::Mat> mAllPSFForConv_red{};

	std::vector<VectorStructR3> mPointsInAS{};
	// ***
};

