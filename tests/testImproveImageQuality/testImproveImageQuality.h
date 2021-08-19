#pragma once

// interactions
#include "..\..\LowLevelTracing\Interaction\RefractedRay_LLT.h"
#include "..\..\LowLevelTracing\Interaction\DoNothingInteraction_LLT.h"
#include "..\..\LowLevelTracing\Interaction\Absorb_LLT.h"

// include glasses
#include "..\..\Glasses\Glasses.h"

// open cv
#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"

// improve image qualitys
#include "..\..\Image\ImproveImageQuality.h"

class testImproveImageQuality
{
public:
	testImproveImageQuality();
	~testImproveImageQuality();

	
	// detail enhancement
	// ***************************** 
	bool checkDetailEnhance_BFA_superFunc();
	// test 0
	bool testDE_BFA_0();
	//test 1
	bool testDE_BFA_1();
	// ***************************** 

	// unsharp masking
	// ***************************** 
	bool checkUnsharpMasking_BFA_superFunc();
	//test 0
	bool testUM_BFA_0();
	// test 1
	bool testUM_BFA_1();
	// ***************************** 

	// test improve image quality super function
	// ***************************** 
	bool checkImproverImaQuality_superFunc();
	// test 0
	bool testImpImaQual_E0_WD24();
	// test 1 
	bool testImpImaQual_E1_UnsMas24();
	// test 2
	bool testImpImaQual_E2_DetEnh24();
	// test 3
	bool testImpQual_E3_RemChromAber();
	// test 4
	bool testImaQual_E4_UnsMas_gray();
	// test 5
	bool testImaQual_E5_Flower2_UnsMas_DetEnh_WD_24();

	// ***************************** 

	bool checkImproveImageQuality_openCV_Func();
	
	// load important things
	void loadImportantStuff();

	// export all PSFs to CSV
	void exportAllPSFsToCSV(std::vector<cv::Mat> psf_vec_blue, std::vector<cv::Mat> psf_vec_green, std::vector<cv::Mat> psf_vec_red, std::string location);
	// inport all PSFs to Mat
	std::vector<cv::Mat> inportManyPSFsToMat(std::string name, std::string location, unsigned int size);

	// collect function
	std::vector<real> collectParameterWD(ImaProcSuperFct imaProcSuperFct);
	std::vector<real> collectParameterUnsharpMasking(ImaProcSuperFct imaProcSuperFct);
	std::vector<real> collectParameterDetailEnhancement(ImaProcSuperFct imaProcSuperFct);
	std::vector<real> collectParameterRemoveChromaticAberrations(ImaProcSuperFct imaProcSuperFct);

private:
	// interactions
	DoNothingInteraction_LLT mDoNothing{};
	RefractedRay_LLT mRefrac{};
	Absorb_LLT mAbsorb{};

	// glasses
	glass mGlasses{};
	// wavelenth
	std::vector<real> mWavelenght_vec_dFC{};
	// object 
	std::vector<VectorStructR3> mObject_vec_012{};

};

