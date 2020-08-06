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


	// inf
	bool testCalcCardinalPointsE6_inf();
	bool testCalcCardinalPointsE7_inf();
	bool testCalcCardinalPointsE8_inf();


private:

	double mGlobalTolerance{};
	double mGlobalToleranceExtender{};
};

