#pragma once

// images
#include "..\..\Image\Images.h"

class testSharpnessEvaluation
{
public:
	testSharpnessEvaluation();
	~testSharpnessEvaluation();

	// load all images
	void loadImages();

	// test sharpness evaluation super function
	bool testSharpnessEvaluation_superFct();
	// test brenner
	bool test_brenner();
	// test tennegrad
	bool test_tennegrad();
	// test laplacian
	bool test_laplacian();
	// test SMD
	bool test_SMD();
	// test SMD2
	bool test_SMD2();
	// test energy gradient function
	bool testEnergyGradFct();
	// test EVA
	bool test_EVA();
	// NRSS
	bool test_NRSS();
	// blur noise IQA
	bool test_blur_noise_IQA();

private:

	// object
	cv::Mat object_antelope;
	cv::Mat object_dragonfly;
	cv::Mat object_elefant;
	cv::Mat object_flower1;
	cv::Mat object_flower2;
	cv::Mat object_flower3;
	cv::Mat object_landscape;
	cv::Mat object_pinguin;
	cv::Mat object_rhino;
	cv::Mat object_salad;

	// sim images
	cv::Mat  simIma_antelope;
	cv::Mat  simIma_dragonfly;
	cv::Mat  simIma_elefant;
	cv::Mat  simIma_flower1;
	cv::Mat  simIma_flower2;
	cv::Mat  simIma_flower3;
	cv::Mat  simIma_landscape;
	cv::Mat  simIma_pinguin;
	cv::Mat  simIma_rhino;
	cv::Mat  simIma_salad;
};

