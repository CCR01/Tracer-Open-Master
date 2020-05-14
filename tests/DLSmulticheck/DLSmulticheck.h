#pragma once

// glass catalogue
#include "..\..\Glasses\Glasses.h"

// interactions
#include "..\..\LowLevelTracing\Interaction\Absorb_LLT.h"
#include "..\..\LowLevelTracing\Interaction\RefractedRay_LLT.h"
#include "..\..\LowLevelTracing\Interaction\DoNothingInteraction_LLT.h"

class DLSmulticheck
{
public:
	DLSmulticheck();
	~DLSmulticheck();

	void loadImportantStuff();

	// check super function
	bool checkSuperFuction();

	// checkSystem E0
	bool checkE0();

	// checkSystem E1
	bool checkE1();

	// checkSystem E2
	bool checkE2();

	// checkSystem E3
	bool checkE3();

	// checkSystem E4
	bool checkE4();

	// checkSystem E5
	bool checkE5();

	// checkSystem E6
	bool checkE6();

	// checkSystem E7
	bool checkE7();

	// checkSystem E8
	bool checkE8();

	// checkSystem E9
	bool checkE9();

	// checkSystem E10
	bool checkE10();

	// checkSystem E11
	bool checkE11();

	// checkSystem E12
	bool checkE12();

	// checkSystem E13
	bool checkE13();

	// checkSystem E14
	bool checkE14();

	// checkSystem E15
	bool checkE15();

	// checkSystem E16
	bool checkE16();

	// checkSystem E17
	bool checkE17();

	// checkSystem E18
	bool checkE18();

	// checkSystem E19
	bool checkE19();

	// checkSystem E20
	bool checkE20();

	// checkSystem E21
	bool checkE21();


private:

	std::vector<double> mFactorBetter_vec;
	std::vector<double> mFactorWorst_vec;

	double mTolerance;
	glass glasses;

	RefractedRay_LLT refrac{};
	Absorb_LLT absorb{};
	DoNothingInteraction_LLT doNothing{};

	// wave
	real mWave587{};
	real mWave486{};
	real mWave656{};
	std::vector<real> mWavelength_vec{};

	// field
	VectorStructR3 mField0{};
	VectorStructR3 mField1{};
	VectorStructR3 mField2{};
	VectorStructR3 mField3{};
	VectorStructR3 mField4{};
	std::vector<VectorStructR3> mFields_vec012{};
	std::vector<VectorStructR3> mFields_vec024{};
};

