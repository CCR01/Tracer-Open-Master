#pragma once

// interactions
// include interactions
#include "..\..\LowLevelTracing\Interaction\RefractedRay_LLT.h"
#include "..\..\LowLevelTracing\Interaction\DoNothingInteraction_LLT.h"
#include "..\..\LowLevelTracing\Interaction\Absorb_LLT.h"

// include glasses
#include "..\..\Glasses\Glasses.h"

class testWienerDeconvolution
{
public:
	testWienerDeconvolution();
	~testWienerDeconvolution();

	// ***************************** 
	// Wiener deconvolution
	bool checkImproveImageQuality_WienerDeconvolution_superFct();
	// test 0
	bool test0_WD_Andrey_Smorodov_Gray();
	// test 1
	bool test1_WD_OpenCV();
	// test 2
	bool test2_WD_CR();
	// test 3
	bool test3_WD_Andrey_Smorodov_BGR_Ima();
	// test4
	bool test4_WD_Andrey_Smorodov_BGR_Ima();
	// test5
	bool test5_WS_OpenCV_BGR();
	// test6
	bool test6_WD_CR();
	// test 7
	bool test7_WD();
	//// E0
	bool checkFuncE0();
	//// ***************************** 

	// load important things
	void loadImportantStuff();

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

