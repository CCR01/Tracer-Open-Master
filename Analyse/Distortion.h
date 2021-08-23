#pragma once

#include "opencv2/core/core.hpp"
#include "opencv2/core/mat.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"

// optical System LLT
#include "..\LowLevelTracing\OpticalSystem_LLT.h"


//struct DistortionXandY
//{
//public:
//	DistortionXandY();
//	~DistortionXandY();
//	DistortionXandY(real disX, real disY);
//
//	// X
//	real getDistortionX();
//	void setDistortionX(real disX);
//
//	// Y
//	real getDistrotionY();
//	void setDistortionY(real disY);
//
//private:
//	real mDistortionX{};
//	real mDistortionY{};
//
//};

struct loadParameterDistortion
{
public:
	loadParameterDistortion();
	~loadParameterDistortion();



private:

};

class Distortion
{
public:
	Distortion();
	~Distortion();

	void calcDistortedIma(cv::Mat& inputImam, cv::Mat& distortedIma, cv::Mat mapX, cv::Mat& mapY);
	real calcDistortion_obj(OpticalSystem_LLT optSys_LLT, VectorStructR3 startPoint, Light_LLT light);

	void calculateDistortion_superFunction_obj(/*image*/cv::Mat& image,/*optical system LLT*/ OpticalSystem_LLT optSys_LLT,/*lght*/ Light_LLT light,/*sampling height*/ unsigned int samplingHeight,/*sampling width*/ unsigned int samplingWidth,/*hight object*/ real heightObject,/*width object*/ real widthObject,/*start point Z*/ real startPointZ);

	void calculateDistortionMap();
	void calculateMagnificationUsingRayTracing();
	void calculateDistortedImageUsingRemap();
	void calculateBarrelDistortion();
	void calcPincushionDistortion();

	// *** bilinear interpolation to fill holes in OPD matrix --> Q0
	void bilinearInterpolToFillHolesInDistortionMap_Q0();
	void holizontal_bilinear_Interpolation_Q0();
	void horizontalInterpolation_oneStep_Q0();
	void vertical_bilinear_Interpolation_Q0();
	void verticalInterpolation_oneStep_Q0();
	// look negativ x direction
	void lookNegativ_X_multiSteps_Q0(unsigned int posX, unsigned int posY);
	void lookNegativ_X_oneStep_Q0(unsigned int posX, unsigned int posY);
	// look positiv x direction
	void lookPositiv_X_multiSteps_Q0(unsigned int posX, unsigned int posY);
	void lookPositive_X_oneStep_Q0(unsigned int posX, unsigned int posY);
	// look negativ y direction
	void lookNegativ_Y_multiSteps_Q0(unsigned int posX, unsigned int posY);
	void lookNegative_Y_oneStep_Q0(unsigned int posX, unsigned int posY);
	// look positiv y direction
	void lookPositiv_Y_multiSteps_Q0(unsigned int posX, unsigned int posY);
	void lookPositive_Y_oneStep_Q0(unsigned int posX, unsigned int posY);
	// ***

	// *** bilinear interpolation to fill holes in distortion map --> RemapX
	void bilinearInterpolToFillHolesInDistortionMap_RemapX();
	void holizontal_bilinear_Interpolation_RemapX();
	void horizontalInterpolation_oneStep_RemapX();
	void vertical_bilinear_Interpolation_RemapX();
	void verticalInterpolation_oneStep_RemapX();
	// look negativ x direction
	void lookNegativ_X_multiSteps_RemapX(unsigned int posX, unsigned int posY);
	void lookNegativ_X_oneStep_RemapX(unsigned int posX, unsigned int posY);
	// look positiv x direction
	void lookPositiv_X_multiSteps_RemapX(unsigned int posX, unsigned int posY);
	void lookPositive_X_oneStep_RemapX(unsigned int posX, unsigned int posY);
	// look negativ y direction
	void lookNegativ_Y_multiSteps_RemapX(unsigned int posX, unsigned int posY);
	void lookNegative_Y_oneStep_RemapX(unsigned int posX, unsigned int posY);
	// look positiv y direction
	void lookPositiv_Y_multiSteps_RemapX(unsigned int posX, unsigned int posY);
	void lookPositive_Y_oneStep_RemapX(unsigned int posX, unsigned int posY);
	// ***

	// *** bilinear interpolation to fill holes in distortion map --> RemapY
	void bilinearInterpolToFillHolesInDistortionMap_RemapY();
	void holizontal_bilinear_Interpolation_RemapY();
	void horizontalInterpolation_oneStep_RemapY();
	void vertical_bilinear_Interpolation_RemapY();
	void verticalInterpolation_oneStep_RemapY();
	// look negativ x direction
	void lookNegativ_X_multiSteps_RemapY(unsigned int posX, unsigned int posY);
	void lookNegativ_X_oneStep_RemapY(unsigned int posX, unsigned int posY);
	// look positiv x direction
	void lookPositiv_X_multiSteps_RemapY(unsigned int posX, unsigned int posY);
	void lookPositive_X_oneStep_RemapY(unsigned int posX, unsigned int posY);
	// look negativ y direction
	void lookNegativ_Y_multiSteps_RemapY(unsigned int posX, unsigned int posY);
	void lookNegative_Y_oneStep_RemapY(unsigned int posX, unsigned int posY);
	// look positiv y direction
	void lookPositiv_Y_multiSteps_RemapY(unsigned int posX, unsigned int posY);
	void lookPositive_Y_oneStep_RemapY(unsigned int posX, unsigned int posY);
	// ***
	//
	//// *** bilinear interpolation to fill holes in distortion map correctDistortion --> RemapX
	//void bilinearInterpolToFillHolesInDistortionMap_RemapX_correctDistortion();
	//void holizontal_bilinear_Interpolation_RemapX_correctDistortion();
	//void horizontalInterpolation_oneStep_RemapX_correctDistortion();
	//void vertical_bilinear_Interpolation_RemapX_correctDistortion();
	//void verticalInterpolation_oneStep_RemapX_correctDistortion();
	//// look negativ x direction
	//void lookNegativ_X_multiSteps_RemapX_correctDistortion(unsigned int posX, unsigned int posY);
	//void lookNegativ_X_oneStep_RemapX_correctDistortion(unsigned int posX, unsigned int posY);
	//// look positiv x direction
	//void lookPositiv_X_multiSteps_RemapX_correctDistortion(unsigned int posX, unsigned int posY);
	//void lookPositive_X_oneStep_RemapX_correctDistortion(unsigned int posX, unsigned int posY);
	//// look negativ y direction
	//void lookNegativ_Y_multiSteps_RemapX_correctDistortion(unsigned int posX, unsigned int posY);
	//void lookNegative_Y_oneStep_RemapX_correctDistortion(unsigned int posX, unsigned int posY);
	//// look positiv y direction
	//void lookPositiv_Y_multiSteps_RemapX_correctDistortion(unsigned int posX, unsigned int posY);
	//void lookPositive_Y_oneStep_RemapX_correctDistortion(unsigned int posX, unsigned int posY);
	//// ***

	//// *** bilinear interpolation to fill holes in distortion map correctDistortion --> RemapY
	//void bilinearInterpolToFillHolesInDistortionMap_RemapY_correctDistortion();
	//void holizontal_bilinear_Interpolation_RemapY_correctDistortion();
	//void horizontalInterpolation_oneStep_RemapY_correctDistortion();
	//void vertical_bilinear_Interpolation_RemapY_correctDistortion();
	//void verticalInterpolation_oneStep_RemapY_correctDistortion();
	//// look negativ x direction
	//void lookNegativ_X_multiSteps_RemapY_correctDistortion(unsigned int posX, unsigned int posY);
	//void lookNegativ_X_oneStep_RemapY_correctDistortion(unsigned int posX, unsigned int posY);
	//// look positiv x direction
	//void lookPositiv_X_multiSteps_RemapY_correctDistortion(unsigned int posX, unsigned int posY);
	//void lookPositive_X_oneStep_RemapY_correctDistortion(unsigned int posX, unsigned int posY);
	//// look negativ y direction
	//void lookNegativ_Y_multiSteps_RemapY_correctDistortion(unsigned int posX, unsigned int posY);
	//void lookNegative_Y_oneStep_RemapY_correctDistortion(unsigned int posX, unsigned int posY);
	//// look positiv y direction
	//void lookPositiv_Y_multiSteps_RemapY_correctDistortion(unsigned int posX, unsigned int posY);
	//void lookPositive_Y_oneStep_RemapY_correctDistortion(unsigned int posX, unsigned int posY);
	//// ***

	// *** get function
	cv::Mat getDistortionMap_Q0();
	cv::Mat getDistortionMap_Q0_upsampled();
	cv::Mat getDistortionMap_Q1();
	cv::Mat getDistortionMap_Q0_Q1();
	cv::Mat getDistortionMap_Q2_Q3();
	cv::Mat getTotalDistortionMap();

	cv::Mat getRemap_X();
	cv::Mat getRemap_Y();


	cv::Mat getDistortedImage();
	// ***

	// correct distortion
	cv::Mat correctDistortion();

private:
	cv::Mat mImage{};
	unsigned int mPixelImage_Height{};
	unsigned int mPixelImage_Width{};
	real mStartPointZ;
	OpticalSystem_LLT mOpticalSystem_LLT{};
	Light_LLT mLight{};
	float mSamplingHeight{};
	float mSamplingWidth{};
	real mHeightObject{};
	real mWidthObject{};
	
	real mStartRefIndex{};
	cv::Mat mDistortionMap_Total{};
	cv::Mat mDistortionMap_Q0{};
	cv::Mat mDistortionMap_Q1{};
	cv::Mat mDistortionMap_Q0_Q1{};
	cv::Mat mDistortionMap_Q2_Q3{};
	real mMagnificationUsingRayTracing{};

	// *** bilinear interpolation
	unsigned int mFilledPoints_horizontal{};
	unsigned int mFilledPoints_vertical{};
	float mToleranceToCheckZero{};
	cv::Mat mDistortionMap_Q0_upsampled{};
	unsigned int mMaxIterationBilinInterpol{};
	unsigned int mMaxStepToLook{};
	unsigned int mSizeMatrix_horizontal{};
	unsigned int mSizeMatrix_vertical{};


	bool mLook_Pos_X_oneStep_trueVal{};
	bool mLook_Neg_X_oneStep_trueVal{};
	bool mLook_Pos_Y_oneStep_trueVal{};
	bool mLook_Neg_Y_oneStep_trueVal{};
	float mValOneStep_posX{};
	float mValOneStep_negX{};
	float mValOneStep_posY{};
	float mValOneStep_negY{};
	
	PosX_PosY_Val_tureVal mLook_Pos_X{};
	PosX_PosY_Val_tureVal mLook_Neg_X{};
	PosX_PosY_Val_tureVal mLook_Pos_Y{};
	PosX_PosY_Val_tureVal mLook_Neg_Y{};
	// *** 

	cv::Mat mMapX_forRemap{};
	cv::Mat mMapX_forRemap_CorrectDistortion{};
	cv::Mat mMapX_forRemap_upsampled{};
	//cv::Mat mMapX_forRemap_upsampled_correctDistortion{};
	cv::Mat mMapY_forRemap{};
	cv::Mat mMapY_forRemap_CorrectDistortion{};
	cv::Mat mMapY_forRemap_upsampled{};
	//cv::Mat mMapY_forRemap_upsampled_correctDistortion{};
	
	cv::Mat mDistortedImage{};
	cv::Mat mDistortedImage_ROI{};

	real mDecissionValue{};

	cv::Mat mExandetImaToCorrectDistortion{};
	cv::Rect mROI{};
};



