#pragma once

// Noise
#include "..\..\Noise\Noise.h"

class testNoise
{
public:
	testNoise();
	~testNoise();

	// load camera parameter
	void loadCameraParameter();

	bool testNoise_superFct();
	//E0
	bool testNoise_E0();
	//E1
	bool testNoise_E1();
	//E2
	bool testNoise_E2();


private:
	
	cameraParameterStruct mCaraPara_VistecEco655;
	cameraParameterStruct mCaraPara_Ximea;

};

