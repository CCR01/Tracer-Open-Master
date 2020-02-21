#include "BechmarkMath.h"
#include "..\..\LowLevelTracing\Math_LLT.h"



// check methodes of class FillEntrancePupilWithLightRays
bool BenchmarkMath::checkMethodesMath()
{
	std::vector<bool> checkMath;

	

	// *****************************************************************************************************************
	// *****************************************************************************************************************
	std::vector<double> testVec1 = {-5.0, 3.0, -10.0, 7.0, 1.0, 0.5, -0.5, -0.1};
	VectorElementAndPosition test1 = Math::ValueInVectorNearZeroPosSide(testVec1);
	VectorElementAndPosition test2 = Math::ValueInVectorNearZeroNegSide(testVec1);
	bool checkTestNum1 = Math::compareTwoNumbers_decimals(test1.getValue(),0.5,1);
	bool checkTestPos1 = Math::compareTwoNumbers_decimals(test1.getPosInVector(), 5.0, 1);
	bool checkTestNum2 = Math::compareTwoNumbers_decimals(test2.getValue(), -0.1, 1);
	bool checkchekTestPos2 = Math::compareTwoNumbers_decimals(test2.getPosInVector(), 7.0, 1);
	checkMath.push_back(checkTestNum1);
	checkMath.push_back(checkTestNum2);
	// *****************************************************************************************************************
	// *****************************************************************************************************************
	std::vector<double> testVec2 = { -5.0, 3.0, -10.0, 7.0, 1.0, 0.5, -0.5, -0.1,-100.0,100.0,5.0 };
	double test3 = Math::minValueOfVector(testVec2);
	double test4 = Math::maxValueOfVactor(testVec2);
	bool checkTest3 = Math::compareTwoNumbers_decimals(test3, -100.0, 1);
	bool checkTest4 = Math::compareTwoNumbers_decimals(test4, 100.0, 1);
	checkMath.push_back(checkTest3);
	checkMath.push_back(checkTest4);
	// *****************************************************************************************************************
	// *****************************************************************************************************************
	std::vector<real> test5 = Math::linDistriAlongTwoValues_double(-5.0, 5.0, 11);
	std::vector<real> checkTest5 = { -5.0, -4.0,-3.0,-2.0,-1.0,0.0,1.0,2.0,3.0,4.0, 5.0 };
	std::vector<real> test6 = Math::linDistriAlongTwoValues_double(3.0, 5.0, 11);
	std::vector<real> checkTest6 = { 3.0, 3.2,3.4,3.6,3.8,4.0,4.2,4.4,4.6,4.8,5.0 };
	bool checkcheckTest5 = Math::compareTwoSTDVecors(test5, checkTest5, 2);
	bool checkcheckTest6 = Math::compareTwoSTDVecors(test6, checkTest6, 2);
	checkMath.push_back(checkcheckTest5);
	checkMath.push_back(checkcheckTest6);
	// *****************************************************************************************************************
	// *****************************************************************************************************************
	// test functions on VectorStructR2
	VectorStructR2 Vec2D0{ 0 , 1 };
	VectorStructR2 checkVec2D{ 1 , 0 };
	VectorStructR2 testVec2D0 = Math::calcOrtoVec2D_Unit(Vec2D0);
	bool checkVec0 = Math::compareTwoVectorStruct2D_decimals(testVec2D0, checkVec2D, 5);
	checkMath.push_back(checkVec0);
	VectorStructR2 Vec2D1{ 1 , 0 };
	VectorStructR2 checkVec2D1{ 0 , 1 };
	VectorStructR2 testVec2D1 = Math::calcOrtoVec2D_Unit(Vec2D1);
	bool checkVec1 = Math::compareTwoVectorStruct2D_decimals(testVec2D1, checkVec2D1, 5);
	checkMath.push_back(checkVec1);
	VectorStructR2 Vec2D2{ 1 , 1 };
	VectorStructR2 checkVec2D2{ 0.707106 , -0.707106 };
	VectorStructR2 testVec222 = Math::calcOrtoVec2D_Unit(Vec2D2);
	bool checkVec2 = Math::compareTwoVectorStruct2D_decimals(testVec222, checkVec2D2, 5);
	checkMath.push_back(checkVec2);
	VectorStructR2 Vec2D3{ -1 , 1 };
	VectorStructR2 checkVec2D3{ 0.707106 , 0.707106 };
	VectorStructR2 testVec2D3 = Math::calcOrtoVec2D_Unit(Vec2D3);
	bool checkVec3 = Math::compareTwoVectorStruct2D_decimals(testVec2D3, checkVec2D3, 5);
	checkMath.push_back(checkVec3);
	VectorStructR2 Vec2D4{ -3 , 1 };
	VectorStructR2 checkVec2D4{ 0.31622777 , 0.948683298 };
	VectorStructR2 testVec2D4 = Math::calcOrtoVec2D_Unit(Vec2D4);
	bool checkVec4 = Math::compareTwoVectorStruct2D_decimals(testVec2D4, checkVec2D4, 5);
	checkMath.push_back(checkVec4);
	VectorStructR2 Vec2D5{ 1 , 5 };
	VectorStructR2 checkVec2D5{ 0.980580676, -0.196116135 };
	VectorStructR2 testVec2D5 = Math::calcOrtoVec2D_Unit(Vec2D5);
	bool checkVec5 = Math::compareTwoVectorStruct2D_decimals(testVec2D5, checkVec2D5, 5);
	checkMath.push_back(checkVec5);
	// *****************************************************************************************************************
	// *****************************************************************************************************************
	// check maxValueOfVactor
	std::vector<real> findMaxVec0{ 1.0,0.5,0.1,0.43,12.0,14.0,0.1 };
	real max0 = Math::maxValueOfVactor(findMaxVec0);
	bool checkMaxEle0 = max0 == 14;
	checkMath.push_back(checkMaxEle0);
	std::vector<real> findMaxVec1{ -1.0,-0.5,-0.1,-0.43,-12.0,-14.0,-0.1 };
	real max1 = Math::maxValueOfVactor(findMaxVec1);
	bool checkMaxEle1 = max1 == -0.1;
	checkMath.push_back(checkMaxEle1);
	std::vector<real> findMaxVec2{ -1.0,-0.5,-0.1,-0.43,-12.0,-14.0,-0.1,99.0 };
	real max2 = Math::maxValueOfVactor(findMaxVec2);
	bool checkMaxEle2 = max2 == 99.0;
	checkMath.push_back(checkMaxEle2);
	// *****************************************************************************************************************
	// *****************************************************************************************************************
	// check findAbsMax_X_inStdV_VectorStructR3
	std::vector<VectorStructR3> testStdVec_VecStrR3;
	testStdVec_VecStrR3.push_back({ -1.0,-6.0,9.0 }); 
	testStdVec_VecStrR3.push_back({ 1.0,-6.0,9.0 }); 
	testStdVec_VecStrR3.push_back({ -5.0,6.0,3.0 });
	testStdVec_VecStrR3.push_back({ -9.0,8.0,9.0 });
	testStdVec_VecStrR3.push_back({ 0.0,-8.0,10.0 });
	VectorStructR3 refPoint{ -1.0,1.0,-1.0 };
	VectorStructR3 absDeltaMax_X_Y_Z = Math::findMaxDelta_X_Y_Z_inStdV_VectorStructR3(testStdVec_VecStrR3,refPoint);
	bool checkFindAbsMax_X_Y_Z = Math::compareTwoVectorStructR3_decimals(absDeltaMax_X_Y_Z, { 8.0,9.0,11.0 }, 5);
	checkMath.push_back(checkFindAbsMax_X_Y_Z);
	// *****************************************************************************************************************
	// *****************************************************************************************************************
	real a = 1.0;
	real b = 1.5;
	real c = -0.5;
	real d = -1.0;
	real sum = Math::add4values_ptr(&a, &b, &c, &d);
	bool checkAdder = sum == 1.0;
	checkMath.push_back(checkAdder);
	// *****************************************************************************************************************
	// *****************************************************************************************************************

	bool output = Math::checkTrueOfVectorElements(checkMath);
	// *****************************************************************************************************************

	return output;
}

