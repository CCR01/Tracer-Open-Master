#pragma once

// important structs
#include "..\LowLevelTracing\ImportantStructures.h"

// open cv
#include <opencv2\opencv.hpp>



class SharpnessEvaluation
{
public:
	SharpnessEvaluation();
	~SharpnessEvaluation();

	// there are different methodes to evaluate the sharpness of an image
	// Some of them can be found here: https://programmersought.com/article/6657657740/
	// We used the code from there and modyfied it for our purpose

	// Brenner gradient function
	// from https://programmersought.com/article/6657657740/
	real sharpnessEval_brenner_gray8UN(cv::Mat& gray_img);
	real sharpnessEval_brenner_colorUN(cv::Mat& color_ima);

	// Tenengrad gradient method
	// from https://programmersought.com/article/6657657740/
	real sharpnessEval_tenengrad_gray8UN(cv::Mat& gray_ima);
	real sharpnessEval_tenegrad_colorUN(cv::Mat& color_ima);

	// Laplacian gradient function
	// from https://programmersought.com/article/6657657740/
	real sharpnessEval_laplacian_gray8UN(cv::Mat& gray_ima);
	real sharpnessEval_laplacian_colorUN(cv::Mat& color_ima);

	// SMD function
	// from https://programmersought.com/article/6657657740/
	real sharpnessEval_SMD_gray8UN(cv::Mat& gray_ima);
	real sharpnessEval_SMD_colorUN(cv::Mat& color_ima);

	//  SMD2 function
	// from https://programmersought.com/article/6657657740/
	real sharpnessEval_SMD2_gray8UN(cv::Mat& gray_ima);
	real sharpnessEval_SMD2_colorUN(cv::Mat& color_ima);

	// energy gradient function
	// from https://programmersought.com/article/6657657740/
	real sharpnessEval_EnergyGradFct_gray8UN(cv::Mat& gray_ima);
	real sharpnessEval_EnergyGradFct_colorUN(cv::Mat& color_ima);

	// EAV point sharpness algorithm function
	// from https://programmersought.com/article/6657657740/
	real sharpnessEval_EVA_gray8UN(cv::Mat& gray_ima);
	real sharpnessEval_EVA_colorUN(cv::Mat& color_ima);

	// NRSS gradient structure similarity
	// from https://programmersought.com/article/6657657740/
	real sharpnessEval_NRSS_gray8UN(cv::Mat& gray_ima);
	real ssim(cv::Mat& i1, cv::Mat& i2);
	real sharpnessEval_NRSS_colorUN(cv::Mat& color_ima);

	// No-Reference Image Quality Assessment  using Blur and Noise
	// from https://programmersought.com/article/6657657740/
	real sharpnessEval_blur_noise_IQA_gray8UN(cv::Mat& gray_ima);
	void comput_blur_IQA(cv::Mat& src, float& blur_mean, float& blur_ratio);
	void compute_noise_IQA(cv::Mat& gray_img, float& noise_mean, float& noise_ratio);
	real sharpnessEval_blur_noise_IQA_colorUN(cv::Mat& color_ima);

	real calculateSharpness_superFct(sharpnessEvalMethode sharpEvalMeth, cv::Mat ima);


private:

};


