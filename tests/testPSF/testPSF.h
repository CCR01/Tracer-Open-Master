#pragma once
#include "opencv2/core/mat.hpp"

class TestPSF {
public:
	TestPSF() {};
	~TestPSF() {};


	// check methodes 
	bool testPSF_superFct();


	// test 0
	bool test0();
	// test 1;
	bool test1();
	// test 2
	bool test2();
	// test 3
	bool test3();
	//test 4
	bool test4();
	// test 5
	bool test5();
	// test 6
	bool test6();

	// calculate airy disc according to Pixel Size -> only valid for diffraction limited images
	double calcSizeInnerDiscPSF(cv::Mat difLim_PSF, double pixlSize);
};