
#pragma once
#include "ImportantStructures.h"
#include <vector>


//***********************************************************************
// add two vectors in R3
VectorStructR3 operator+ (VectorStructR3 const l, VectorStructR3 const  r);

// subtract two vectors in R3
VectorStructR3 operator-(VectorStructR3 const l, VectorStructR3 const  r);

// divide two vectors in R3
VectorStructR3 operator/ (VectorStructR3 const l, double const d);

// devide two vectors in R3
VectorStructR3 operator/ (double const  d, VectorStructR3 const l);

// multiply two vectors in R3
VectorStructR3 operator*(VectorStructR3 const v, double const s);

// multiply two vectors in R3
VectorStructR3 operator*(double const s, VectorStructR3 const v);

// calculate scalarproduct of two vectors in R3
double operator*(VectorStructR3 const l, VectorStructR3 const v);


//***********************************************************************
//***********************************************************************
// add two vectors in R2
VectorStructR2 operator+ (VectorStructR2 const l, VectorStructR2 const  r);

// subtract two vectors in R2
VectorStructR2 operator-(VectorStructR2 const l, VectorStructR2 const  r);

// divide two vectors in R2
VectorStructR2 operator/ (VectorStructR2 const l, double const  d);

// devide two vectors in R2
VectorStructR2 operator/ (double const  d, VectorStructR2 const l);

// multiply two vectors in R2
VectorStructR2 operator*(VectorStructR2 const v, double const s);

// multiply two vectors in R2
VectorStructR2 operator*(double const s, VectorStructR2 const v);

// calculate scalarproduct of two vectors in R2
double operator*(VectorStructR2 const l, VectorStructR2 const v);
//***********************************************************************

// subtract two std vectors
std::vector<real> operator- (const std::vector<real> l, const std::vector<real> r);

// add two std vectors
std::vector<real> operator+ (const std::vector<real> l, const std::vector<real> r);

// multiply scalar with matrix (std::vector<std::vectot<real>>)
std::vector<std::vector<real>> operator* (const real& s, std::vector<std::vector<real>>& matrix);

// multiply scalar with std::vector 
std::vector<real> operator*(const real& s, std::vector<real>& v);



namespace Math {

	// calc new value variance percent
	real calcNewValueVariancePercent(real initilaValue, real percent);

	// convert an angle in direction
	// convert an angle in direction
	 VectorStructR3 convertAngleInDirection(real angleDegreesX, real angleDegreesY);

	// convert an direction in angle
	twoVaulesReal convertDirectionInAngle(VectorStructR3 direction);

	// sum all values in a vector
	real sumAllVectorValues(std::vector<real> vec);

	// print the vector
	void print(VectorStructR3 VectorPrint);

	// multiply two system matrixes
	std::vector<std::vector<real>> multiplyTwoSystemMatrixes2x2(std::vector<std::vector<real>> m1, std::vector<std::vector<real>> m2);

	// just for debugging
	void printSystemMatrix2x2(std::vector<std::vector<real>> m);

	// print the vector
	void print(VectorStructR3 VectorPrint);

	// scale a Vector
	VectorStructR3 scaleVector(double const scaleFactor, VectorStructR3 const Vscale);

	// calculate unit vector
	VectorStructR3 unitVector(VectorStructR3 const V);

	// subtract two vectors
	VectorStructR3 subVectors(VectorStructR3 V1sub, VectorStructR3 V2sub);

	// calculate cross product
	VectorStructR3 DoCrossProduct(VectorStructR3 CrProVec1, VectorStructR3 CrProVec2);

	// calculate length of vector
	double lengthOfVector(VectorStructR3 vLength);

	// calculate distance between two points in R3
	double distanceTwoVectors(VectorStructR3 const V1, VectorStructR3 const V2);

	// check if two vectors are linearly dependent
	bool checkLinearlyDependent(VectorStructR3 const V1, VectorStructR3 const V2);

	// calculate rotate matrix around an axis n
	// source https://en.wikipedia.org/wiki/Rotation_matrix
	Matrix3x3AndExist calcRotationMatrixAroundVector(VectorStructR3 const direction, double const /*in radiant*/ rotationAngle);

	// Multiply matrix (3x3) with Vector in R3
	VectorStructR3 multiplyMatrix3x3VectorR3(double mat[3][3], VectorStructR3 vec);

	// to compare two numbers it is sometimes helpful to round them
	//source: https://www.c-plusplus.net/forum/39342-full
	double roundNumber(double Zahl, unsigned int Stellen);

	// compare two reounded numbers
	bool compareTwoNumbers_decimals(double num1, double num2, unsigned int decimals);
	bool compareTwoNumbers_tolerance(real num1, real num2, real tolerance);

	// compare two vectors struct R3
	bool compareTwoVectorStructR3_decimals(VectorStructR3 const V1, VectorStructR3 const V2, unsigned int decimals);
	bool compareTwoVectorStructR3_tolerance(VectorStructR3 const V1, VectorStructR3 const V2, real tolerance);


	// compate two vectors struct R2
	bool compareTwoVectorStruct2D_decimals(VectorStructR2 const V1, VectorStructR2 const V2, unsigned int const decimals);
	bool compareTwoVectorStruct2D_tolerance(VectorStructR2 const V1, VectorStructR2 const V2, real tolerance);

	// check if all vector elements are true
	bool checkTrueOfVectorElements(std::vector<bool> V);

	// round the numbers of a matrix to compare them
	Matrix3x3AndExist RoundNumberMatrix(real Matrix[3][3], int decimals);

	// compare numbers of a 3x3 matrix
	bool compareRoundedTwoMatrices3x3(real Matrix1[3][3], real Matrix[3][3], unsigned int decimals);

	// compare all vector elements
	bool compareAllVectorElements(std::vector<VectorStructR3> V1, std::vector<VectorStructR3> V2, unsigned int decimals);

	// calculate "d" of an plane using coordinate form and Point P
	real calc_D_ofPlane(VectorStructR3 const normalVector, VectorStructR3 const P);

	// calc "t" (steps to walk) unsing line and plan (coordinate form)
	real calc_T_ofPlanAndLine(VectorStructR3  const originLine, VectorStructR3  const coordFormPlan, double const d_coordForm);

	// find value in vector near zero positiv side
	VectorElementAndPosition ValueInVectorNearZeroPosSide(std::vector<real> vector);

	// find value in vector near zero negative side
	VectorElementAndPosition ValueInVectorNearZeroNegSide(std::vector<real> vector);

	// find min value of a vector
	real minValueOfVector(std::vector<real> vector);

	// find max value of a vector
	real maxValueOfVactor(std::vector<real> vector);

	// find pos value in a vector
	unsigned int posMinValueInVector(std::vector<real> vector);

	// check if all values in vactor are heigher than
	bool checkValuesHeigherThan(real value, std::vector<real> vec);

	// linear distribution along two values -> double and steps
	std::vector<real> linDistriAlongTwoValues_double_steps(real valueMin, real ValueMax, real delta);

	// linear distribution along two values -> double
	std::vector<real> linDistriAlongTwoValues_double(real valueMin, real ValueMax, unsigned int number);

	// linear distribution along two values -> float
	std::vector<float> linDistriAlongTwoValues_float(float const valueMin, float const ValueMax, unsigned int const number);

	// linear distribution along two values -> int
	std::vector<int> linDistriAlongTwoValues_int(int const valueMin, int const ValueMax, unsigned int const number);

	// vector with reals between min and max
	std::vector<real> calcVecRealMinMaxSteps_withoutMinMax(real min, real max, real steps, real withoutMin, real withoutMax);

	// compare two std::vecor<real>
	bool compareTwoSTDVecors(std::vector<real> V1, std::vector<real> V2, unsigned decimals);

	// calculate orthogonal vector in 2D
	VectorStructR2 calcOrtoVec2D_Unit(VectorStructR2 vector);

	// calculate unit vector 2D
	VectorStructR2 unitVec2D(VectorStructR2 v);

	// find max delta X,Y,Z in std::vector<VectorStructR3>
	VectorStructR3 findMaxDelta_X_Y_Z_inStdV_VectorStructR3(std::vector<VectorStructR3> const stdV_VecStrR3, VectorStructR3 refPoint);

	// add 4 values
	real add4values_ptr(real* a, real* b, real* c, real* d);

	// calculate the inverse matrix 
	// we got the code from the internet --> see https://martin-thoma.com/inverting-matrices/
	std::vector<std::vector<real>> calculateInverse(const std::vector<std::vector<real>>& inpusMatrix);

	
	// add all values in std::vector
	real addAllValuesInVector_real(std::vector<real> v);
	float addAllValuesInVector_float(std::vector<float> v);
	int addAllValuesInVector_int(std::vector<int> v);
	unsigned int addAllValuesInVector_unsignedInt(std::vector<unsigned int> v);


}







