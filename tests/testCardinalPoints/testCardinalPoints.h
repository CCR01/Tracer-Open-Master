#pragma once

class testCardinalPoints
{
public:
	testCardinalPoints();
	~testCardinalPoints();

	bool superFuncTestCalcCardinalPoints();

	// obj
	bool testCalcCardinalPointsE0_obj();
	bool testCalcCardinalPointsE1_obj();
	bool testCalcCardinalPointsE2_obj();
	bool testCalcCardinalPointsE3_obj();
	bool testCalcCardinalPointsE4_obj();
	bool testCalcCardinalPointsE5_obj();
	bool testCalcCardinalPointsE10_obj();
	bool testCalcCardinalPointsE11_obj();
	bool testCalcCardinalPointsE12_obj();
	bool testCalcCardinalPointsE13_obj();
	bool testCalcCardinalPointsE14_obj();
	bool testCalcCardinalPointsE15_obj();
	// inf
	bool testCalcCardinalPointsE6_inf();
	bool testCalcCardinalPointsE7_inf();
	bool testCalcCardinalPointsE8_inf();
	bool testCalcCardinalPointsE9_inf();
	bool testCalcCardinalPointsE16_inf();
	bool testCalcCardinalPointsE17_inf();
	bool testCalcCardinalPointsE18_inf();
	bool testCalcCardinalPointsE19_inf();
	bool testCalcCardinalPointsE20_inf();
	bool testCalcCardinalPointsE21_inf();
	bool testCalcCardinalPointsE22_inf();
	bool testCalcCardinalPointsE23_inf();
	bool testCalcCardinalPointsE24_inf();

	bool testCalcCardinalPointsE25_obj();


private:

	double mGlobalTolerance{};
	double mGlobalToleranceExtender{};
};

