#pragma once
#include "..\..\Image\ImageSimulation.h"

// include interactions
#include "..\..\LowLevelTracing\Interaction\RefractedRay_LLT.h"
#include "..\..\LowLevelTracing\Interaction\DoNothingInteraction_LLT.h"
#include "..\..\LowLevelTracing\Interaction\Absorb_LLT.h"

// include glasses
#include "..\..\Glasses\Glasses.h"

class TestImageSimulation
{
public:
	TestImageSimulation();
	~TestImageSimulation();

	bool testSuperFct();

	bool test0();
	bool test1();
	bool test2();
	bool test3();
	bool test4();
	bool test5();
	bool test6();
	bool test7();
	bool test8();
	bool test9();
	bool test10();
	bool test11();
	bool test12();

	void loadImportantStuff();

	bool checkImaSim_test10(ImageSimulationFunctions imaSim, bool shows);

	// show all PSFs in an image
	void showAllPSFsInAnImageAndSave(const std::vector<cv::Mat>& psf_vec, cv::Size targetSize, std::string location, std::string nameSave, bool show);

private:
	DoNothingInteraction_LLT mDoNothing{};
	RefractedRay_LLT mRefrac{};
	Absorb_LLT mAbsorb{};

	glass glasses{};
	std::vector<real> mWavelenght_vec_dFC{};
	std::vector<VectorStructR3> mObject_vec_012{};

	loadParaImaSim mDefaulParaImaSim;
	
};
