#pragma once

class testAsphericalSurface_LLT
{
public:
	testAsphericalSurface_LLT();
	~testAsphericalSurface_LLT();

	// test aspherical surface in LLT
	bool checkAsphericalSurfaceSuperFct_LLT();

	// E0
	bool checkAsphere_LLT_E0();
	// E1
	bool checkAsphere_LLT_E1();
	// E2
	bool checkAsphere_LLT_E2();
	// E3
	bool checkAsphere_LLT_E3();
	// E4
	bool checkAsphere_LLT_E4();

};
