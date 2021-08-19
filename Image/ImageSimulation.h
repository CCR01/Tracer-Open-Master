#pragma once

#include "opencv2/core/core.hpp"
#include "opencv2/core/mat.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"

#include "..\LowLevelTracing\ImportantStructures.h"
#include "..\OpticalSystemElement\OpticalSystemElement.h"



struct  loadParaImaSim
{
public:
	loadParaImaSim();
	~loadParaImaSim();

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
	// size matrix to save OPD
	unsigned int getSizeMatrixToSaveOPD();
	void setSizeMatrixToSaveOPD(unsigned int sizeMatrixOPD);
	// inf of obj
	void setInfOrObj(objectPoint_inf_obj inf_obj);
	objectPoint_inf_obj getInfOrObj();
	// row and col resize OPD
	void setRowColResizeOPD(unsigned int rowAndCol);
	unsigned int getRowAndColResizeOPD();
	// sampling _x
	void setSampling_x(unsigned int sampling_x);
	unsigned getSampling_x();
	// sampling _x
	void setSampling_y(unsigned int sampling_y);
	unsigned getSampling_y();
	// semi height object
	void setSemiHeightObj(real semiHeightObject);
	real getSemiHeightObj();
	// semi weidth object
	void setSemiWeidthObj(real semiWeigthObject);
	real getSemiWidthObj();
	// position Z object
	void setPosition_Z_Object(real pos_Z_obj);
	real getPosition_Z_Object();
	// up sample PSF
	void setUpSamplePSF(bool upSamplePSF);
	bool getUpSamplePSF();
	// resize OPD linear
	void setResizeOPD_linear(bool resizeOPD_linear);
	bool getResizeOPD_linear();
	// padding factor PSF
	void setPaddingFactorPSF(unsigned int paddingFactor);
	unsigned int getPaddingFactorPSF();
	// calc distortion
	void setCalcDistortion(bool calcDistortion);
	bool getCalcDistortion();
	// sampling distortion height
	void setSamplingDistortionHeight(unsigned int samplingDisHeight);
	unsigned int getSamplingDistortionHeight();
	// sampling distortion height
	void setSamplingDistortionWidth(unsigned int samplingDisWidth);
	unsigned int getSamplingDistortionWidth();

	void loadImportandStuff();


private:
	unsigned int mRow_BiggerForConv{};
	unsigned int mCol_BiggerForConv{};
	real mWavelength_blue{};
	real mWavelength_green{};
	real mWavelength_red{};
	unsigned int mRayDesnity{};
	Light_LLT mLight{};
	
	unsigned int mSizeMatrixToSaveOPD{};
	objectPoint_inf_obj mInf_obj{};
	unsigned int mRowColResizeOPD{};
	unsigned int mSampling_x{};
	unsigned int mSampling_y{};
	real mSemiHeightObject{};
	real mSemiWeidthObject{};
	real mPosition_Z_Object{};

	bool mUpSamplePSF{};
	bool mResizeOPD_linear{};

	unsigned int mPaddingFactorPSF{};
	
	bool mCalcDistortion{};
	unsigned int mSamplingDistortionHeight{};
	unsigned int mSamplingDistortionWidth{};

};

class ImageSimulationFunctions
{
public:
	ImageSimulationFunctions();
	~ImageSimulationFunctions();
	
	void setInitialObject(cv::Mat initialObj);
	
	// ***
	void setOpticalSystemElement(OpticalSystemElement optSysEle);
	void setInitialParameters(loadParaImaSim initialParaImaSim);

	void loadPSFs_blue(std::vector<cv::Mat> PSF_vec_blue);
	void loadPSFs_green(std::vector<cv::Mat> PSF_vec_green);
	void loadPSFs_red(std::vector<cv::Mat> PSF_vec_red);
	// ***
	void imageSimulationSuperFct(/*optical System Element*/ OpticalSystemElement optSysEle, cv::Mat initialObj, loadParaImaSim defaulPara);
	// ***
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
	cv::Mat convolution_BGR_uint8(const cv::Mat obj,const cv::Mat PSF);
	cv::Mat convolution_Gray_unit8(const cv::Mat obj,const cv::Mat PSF);
	void fillingBlackStrips();
	// put the image grides together
	void putImaGridsTogether();
	void putImaGridsTogether_save_doNotUseThatFunction();
	// norm the separated images between min and max
	void normSepImagesMinAndMax();
	// put all channles together, scale the image and save the image as CV_8UC 
	void putAllChannlesTogetherScaleAndSaveIma();
	// get the simulated image initial size
	cv::Mat getSimulatedImage_initialSize();
	// get the simulated image size for confolution
	cv::Mat getSimulatedImage_sizeForConvolution();
	// check refractive index before first surface
	void getRefIndexBeforeFirstSurface();
	// calculate distorted images
	void calcDistortedImages();

	// save that fct
	void separateTheImageInNtimesMimages_saveThatFct_1();
	void separateTheImageInNtimesMimages_saveThatFct_2();
	void putImaGridsTogether_saveThatFct_1();
	void putImaGridsTogether_saveThatFct_2();
	// ***

	// calc width object according to height
	void calcWidthAccordingToHeight();
	// calc points to sampling image 
	void calcPointsToSampleObject();
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
	// check for resize OPD linear
	void checkForResizeOPD();
	// check for up sampling psf
	void checkForUpSamplingPSF();

	// check Intensity distorted images
	void checkIntensityDistortedImages();

	// adapet size PSF for convolution
	void adapetSizeObject_ForConv();

	// calculate ray density according to OPD size
	void calcRayDensityAccordingToOPDsize();

	// calcualte target pixel size
	void calcTargetPixcelSize();

	void normImageToMaxVal();

	// load parameters
	//***
	void setDefaulParameter(loadParaImaSim defaulParaImaSim);

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

	// size matrix to save OPD
	unsigned int getSizeMatrixToSaveOPD();
	void setSizeMatrixToSaveOPD(unsigned int sizeMatrixOPD);

	// inf of obj
	void setInfOrObj(objectPoint_inf_obj inf_obj);
	objectPoint_inf_obj getInfOrObj();

	// sampling
	void setSampling(unsigned int sampling);
	unsigned getSampling();

	// semi height object
	void setSemiHeightObj(real semiHeightObject);
	real getSemiHeightObj();

	// semi weidth object
	void setSemiWeidthObj(real semiWeigthObject);
	real getSemiWeidthOj();

	// position Z object
	void setPosition_Z_Object(real pos_Z_obj);
	real getPosition_Z_Object();

	// up sample PSF
	void setUpSamplePSF(bool upSamplePSF);
	bool getUpSamplePSF();

	// resize OPD linear
	void setResizeOPD_linear(bool resizeOPD_linear);
	bool getResizeOPD_linear();

	// padding factor PSF
	void setPaddingFactorPSF(unsigned int paddingFactor);
	unsigned int getPaddingFactorPSF();
	// ***

	// export all calculated OPDs 
	void exportAllCalcOPDs_blue(std::string location);
	void exportAllCalcOPDs_green(std::string location);
	void exportAllCalcOPDs_red(std::string location);

	// row and col resize OPD
	void setRowColResizeOPD(unsigned int rowAndCol);
	unsigned int getRowAndColResizeOPD();

	// scall up all OPDs
	void resizeAllOPDs_unsign_LANCZOS4();

	// calc all PSFs
	void calcAllPSFs();
	void calcAllPSF_blue();
	void calcAllPSF_green();
	void calcAllPSF_red();

	// normalieze all PSFs
	void normalizeAllPSFs();

	// sample up PSF
	void upSample_PSFs_horizontal();
	void upSample_PSFs_vertical();

	// rotate matrix by 90°
	cv::Mat rotateMatrixBy_90degrees(cv::Mat& mat);

	cv::Mat flipMatrixHorizontal(cv::Mat& mat);
	cv::Mat flipMatrixVertical(cv::Mat& mat);

	// calculate all PSFs for convolution
	void calcAllPSFsForConv_Q1();
	void calcAllPSFsForConv_Q2andQ3();

	// resize all PSFs
	//void resizeAllPSFs_using_LANCZOS4();

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

	// get calculated PSFs
	std::vector<cv::Mat> getCalcPSF_blue();
	std::vector<cv::Mat> getCalcPSF_green();
	std::vector<cv::Mat> getCalcPSF_red();

	// get sampled UP PSF horizontal
	std::vector<cv::Mat> getSampledUpPSF_horizontal_blue();
	std::vector<cv::Mat> getSampledUpPSF_horizontal_green();
	std::vector<cv::Mat> getSampledUpPSF_horizontal_red();

	// get sampled UP PSF vertical
	std::vector<cv::Mat> getSampledUpPSF_vertical_blue();
	std::vector<cv::Mat> getSampledUpPSF_vertical_green();
	std::vector<cv::Mat> getSampledUpPSF_vertical_red();

	// get all PSFs for convolution
	std::vector<cv::Mat> getAllPSFsForConvolution_blue();
	std::vector<cv::Mat> getAllPSFsForConvolution_green();
	std::vector<cv::Mat> getAllPSFsForConvolution_red();

	// get simulated image grids
	std::vector<cv::Mat> getSimulatedImaGrid_blue();
	std::vector<cv::Mat> getSimulatedImaGrid_green();
	std::vector<cv::Mat> getSimulatedImaGrid_red();

	// simulated image single color
	cv::Mat getSimulatedImage_blue();
	cv::Mat getSimulatedImage_green();
	cv::Mat getSimulatedImage_red();

	// load parameter image simulation
	loadParaImaSim getLoadParameterImaSim();

	// ***

	// *** distortion *** 
	// ***
	// test 0
	// see: https://answers.opencv.org/question/57179/creation-of-images-with-warpdistortion-due-to-natural-effects-on-camera-lens/?sort=votes
	void calculateDistortedIma_test0(cv::Mat& inputIma, cv::Mat& distortedIma, real k);
	float calc_shift_test0(float x1, float x2, float cx, float k);
	float getRadialX_test0(float x, float y, float cx, float cy, float k, bool scale, cv::Vec4f props);
	float getRadialY_test0(float x, float y, float cx, float cy, float k, bool scale, cv::Vec4f props);
	// ***
	// test 1
	// see: https://stackoverflow.com/questions/6199636/formulas-for-barrel-pincushion-distortion
	cv::Mat barrel_pincusion_dist(cv::Mat img, double Cx, double Cy, double kx, double ky);
	// ***
	// test CR
	// see: https://answers.opencv.org/question/57179/creation-of-images-with-warpdistortion-due-to-natural-effects-on-camera-lens/?sort=votes
	void calculateDistortedIma_testCR_doNotUseThat(cv::Mat& inputIma, cv::Mat& distortedIma, real k);
	float calc_shift_testCR_doNotUseThat(float x1, float x2, float cx, float k);
	float getRadialX_testCR_doNotUseThat(float x, float y, float cx, float cy, float k, bool scale, cv::Vec4f props);
	float getRadialY_testCR_doNotUseThat(float x, float y, float cx, float cy, float k, bool scale, cv::Vec4f props);
	// cv::remap
	void remapImage(cv::Mat& inputImag, cv::Mat& remapedIma, int remapNumber);
	void update_map(int& ind, cv::Mat& map_x, cv::Mat& map_y);
	// cv::remap for distortion
	void distorImaUsingRemap(cv::Mat& inputIma, cv::Mat& distortedIma, real factor);
	cv::Size getSizeResizedObjForConv();
	cv::Size getSizeInitialObj();
	// ***



private:


	// used by CR
	// ***
	loadParaImaSim mLoadParameterImaSim{};

	std::vector<cv::Mat> mLoadedPSFs_vec_blue{};
	std::vector<cv::Mat> mLoadedPSFs_vec_green{};
	std::vector<cv::Mat> mLoadedPSFs_vec_red{};
	//unsigned int mGridFactor{};
	cv::Mat mInitialObj{};
	cv::Mat mResizedObjectForConvolution{};
	cv::Mat mAdaptedObj{};
	cv::Mat mAdaptedObj_blue{};
	cv::Mat mAdaptedObj_green{};
	cv::Mat mAdaptedObj_red{};
	std::vector<cv::Mat> mObjectGrid_blue{};
	std::vector<cv::Mat> mObjectGrid_green{};
	std::vector<cv::Mat> mObjectGrid_red{};
	
	//std::vector<real> mMaxBlue_vec{};
	//std::vector<real> mMinBlue_vec{};
	//std::vector<real> mMaxGreen_vec{};
	//std::vector<real> mMinGreen_vec{};
	//std::vector<real> mMaxRed_vec{};
	//std::vector<real> mMinRed_vec{};

	std::vector<cv::Mat> mSimulatedImageGrid_blue{};
	std::vector<cv::Mat> mSimulatedImageGrid_green{};
	std::vector<cv::Mat> mSimulatedImageGrid_red{};
	cv::Mat mSimulatedIma_blue{};
	cv::Mat mSimulatedIma_green{};
	cv::Mat mSimulatedIma_red{};


	cv::Mat mSimulatedIma_blue_initialSize{};
	cv::Mat mSimulatedIma_green_initialSize{};
	cv::Mat mSimulatedIma_red_initialSize{};

	cv::Mat mSimulatedIma_bgr_initialSize{};
	cv::Mat mSimulatedIma_bgr_final_initialSize{};
	cv::Mat mSimulatedIma_bgr_noDistortion_initialSize{};
	
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

	real mStartRefIndex{};


	real mEXPD_blue{};
	real mEXPP_blue{};
	real mMagni_blue{};
	real mTargetPixelSize_blue_µm{};

	real mEXPD_green{};
	real mEXPP_green{};
	real mMagni_green{};
	real mTargetPixelSize_green_µm{};

	real mEXPD_red{};
	real mEXPP_red{};
	real mMagni_red{};
	real mTargetPixelSize_red_µm{};

	cv::Size mSizeResizedObjForConv{};
	cv::Size mSizeInitialObj{};
	// ***


};

