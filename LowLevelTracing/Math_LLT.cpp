#include <cmath>

#include "Math_LLT.h"
#include "..\oftenUseNamespace\oftenUseNamespace.h"
#include <iostream>
#include <algorithm>


// calc new value variance percent
real Math::calcNewValueVariancePercent(real initilaValue, real percent)
{
	return initilaValue * (percent + 100.0) / 100.0;
}


// convert an angle in direction
VectorStructR3 Math::convertAngleInDirection(real angleDegreesX, real angleDegreesY)
{
	//real prefix_X = 1.0;
	//real prefix_Y = 1.0;

	////*** strange things about Zemax *** //
	//if (angleDegreesX != 0.0 && angleDegreesY != 0.0)
	//{
	//	if (angleDegreesX < 0.0)
	//	{
	//		prefix_X = -1.0;
	//	}
	//
	//	if (angleDegreesY < 0.0)
	//	{
	//		prefix_Y = -1.0;
	//	}
	//
	//	angleDegreesX = prefix_X * std::sqrt(std::abs(angleDegreesX));
	//	angleDegreesY = prefix_Y * std::sqrt(std::abs(angleDegreesY));
	//}
	//// *** *** //

	VectorStructR3 returnVec3(0.0,0.0,1.0);
	returnVec3.setY((tan(angleDegreesY * PI / 180)));
	returnVec3.setX((tan(angleDegreesX * PI / 180)));

	   	 

	return returnVec3;
}

twoVaulesReal Math::convertDirectionInAngle(VectorStructR3 direction)
{
	real dir_X = direction.getX();
	real dir_Y = direction.getY();
	real dir_Z = direction.getZ();

	twoVaulesReal returnTwoVal_angles;

	returnTwoVal_angles.setVal_1(tan(dir_X / dir_Z) * 180 / PI); // angle X
	returnTwoVal_angles.setVal_2(tan(dir_Y / dir_Z) * 180 / PI); // angle Y

	return returnTwoVal_angles;
}

void Math::print(VectorStructR3 VectorPrint)
{
	std::cout << VectorPrint.getX() << std::endl
		<< VectorPrint.getY() << std::endl
		<< VectorPrint.getZ() << std::endl;
}
real Math::sumAllVectorValues(std::vector<real> vec)
{
	real sum_of_elems{};
	for (auto& n : vec) sum_of_elems += n;

	return sum_of_elems;
}

// multiply two system matrixes
std::vector<std::vector<real>> Math::multiplyTwoSystemMatrixes2x2(std::vector<std::vector<real>> m1, std::vector<std::vector<real>> m2)
{
	std::vector<std::vector<real>> returnSystemMatrix{};
	returnSystemMatrix.resize(2);
	returnSystemMatrix[0].resize(2);
	returnSystemMatrix[1].resize(2);

	real A = m1[0][0] * m2[0][0] + m1[1][0] * m2[0][1];
	real B = m1[0][0] * m2[1][0] + m1[1][0] * m2[1][1];
	real C = m1[0][1] * m2[0][0] + m1[1][1] * m2[0][1];
	real D = m1[0][1] * m2[1][0] + m1[1][1] * m2[1][1];

	returnSystemMatrix[0][0] = A;
	returnSystemMatrix[1][0] = B;
	returnSystemMatrix[0][1] = C;
	returnSystemMatrix[1][1] = D;

	return returnSystemMatrix;
}

// just for debugging
void Math::printSystemMatrix2x2(std::vector<std::vector<real>> m)
{
	std::cout << "[ " << m[0][0] << " " << m[1][0] << std::endl;
	std::cout << "  " << m[0][1] << " " << m[1][1] << " ]" << std::endl;
}


// scale a Vector
VectorStructR3 Math::scaleVector(real const scaleFactor, const VectorStructR3&  Vscale)
{
	VectorStructR3 ReturnVectorScale{};
	ReturnVectorScale.setX(scaleFactor * Vscale.getX());
	ReturnVectorScale.setY(scaleFactor * Vscale.getY());
	ReturnVectorScale.setZ(scaleFactor * Vscale.getZ());

	return ReturnVectorScale;
}

// calculate unit vector
VectorStructR3 Math::unitVector(const VectorStructR3& V)
{
	real OneByLenghtOfVector = 1 / (std::sqrt(V.getX() * V.getX() + V.getY() * V.getY() + V.getZ() * V.getZ()));
	return scaleVector(OneByLenghtOfVector, V);
}


// subtract two vectors
VectorStructR3 Math::subVectors(const VectorStructR3& V1sub, const VectorStructR3& V2sub)
{
	VectorStructR3 VectorReturnSub{};
	VectorReturnSub.setX(V1sub.getX() - V2sub.getX());
	VectorReturnSub.setY(V1sub.getY() - V2sub.getY());
	VectorReturnSub.setZ(V1sub.getZ() - V2sub.getZ());

	return VectorReturnSub;
}

//calculate cross product
VectorStructR3 Math::DoCrossProduct(const VectorStructR3&  CrProVec1, const VectorStructR3& CrProVec2)
{

	VectorStructR3 helpVector1{};
	helpVector1.setX(CrProVec1.getY() * CrProVec2.getZ());
	helpVector1.setY(CrProVec1.getZ() * CrProVec2.getX());
	helpVector1.setZ(CrProVec1.getX() * CrProVec2.getY());

	VectorStructR3 helpVector2;
	helpVector2.setX(CrProVec1.getZ() * CrProVec2.getY());
	helpVector2.setY(CrProVec1.getX() * CrProVec2.getZ());
	helpVector2.setZ(CrProVec1.getY() * CrProVec2.getX());

	return subVectors(helpVector1, helpVector2);
}

// Check if two vectors are linearly dependent
bool Math::checkLinearlyDependent(VectorStructR3 const V1, VectorStructR3 const V2)
{
	double first = V1.getX() / V2.getX();
	double second = V1.getY() / V2.getY();
	double third = V1.getZ() / V2.getZ();

	double tolerance = 0.0000000001; //TODO Question: Welche Tolerant ist hier sinnvoll???

	if (first + tolerance >= second && first - tolerance <= second && first + tolerance >= third && first - tolerance <= third && second + tolerance >= third && second - tolerance <= third)
	{
		return true;
	}
	else
	{
		return false;
	}

}

// multiply matrix3x3 with vector in R3
VectorStructR3 Math::multiplyMatrix3x3VectorR3(const std::vector<std::vector<real>> mat, const VectorStructR3& vec)
{
	VectorStructR3 returnVector;
	returnVector.setX(mat[0][0] * vec.getX() + mat[1][0] * vec.getY() + mat[2][0] * vec.getZ());
	returnVector.setY(mat[0][1] * vec.getX() + mat[1][1] * vec.getY() + mat[2][1] * vec.getZ());
	returnVector.setZ(mat[0][2] * vec.getX() + mat[1][2] * vec.getY() + mat[2][2] * vec.getZ());
	return returnVector;

}


//calculate length of vector
double Math::lengthOfVector(const VectorStructR3& vLength)
{
	return sqrt(vLength.getX()*vLength.getX() + vLength.getY()*vLength.getY() + vLength.getZ()*vLength.getZ());
}

// calculate distance between two points in R3
double Math::distanceTwoVectors(VectorStructR3 const V1, VectorStructR3 const V2)
{
	return sqrt(pow(V1.getX() - V2.getX(), 2) + pow(V1.getY() - V2.getY(), 2) + pow(V1.getZ() - V2.getZ(), 2));
}


// calculate rotate matrix around an axis n
// source https://en.wikipedia.org/wiki/Rotation_matrix
std::vector<std::vector<real>> Math::calcRotationMatrixAroundVector(VectorStructR3 const direction, double const /*in radiant*/ rotationAngle)
{


	std::vector<std::vector<real>> returnMatrix;
	returnMatrix.resize(3);
	returnMatrix[0].resize(3);
	returnMatrix[1].resize(3);
	returnMatrix[2].resize(3);

	real const cosRotationAngle = cos(rotationAngle);
	real const sinRotationAngle = sin(rotationAngle);
	real const oneMinusCosRotationAngle = 1 - cosRotationAngle;

	returnMatrix[0][0] = cosRotationAngle + pow(direction.getX(), 2) * oneMinusCosRotationAngle;
	returnMatrix[1][0] = direction.getX() * direction.getY() * oneMinusCosRotationAngle - direction.getZ() * sinRotationAngle;
	returnMatrix[2][0] = direction.getX() * direction.getZ() * oneMinusCosRotationAngle + direction.getY() * sinRotationAngle;

	returnMatrix[0][1] = direction.getY() * direction.getX() * oneMinusCosRotationAngle + direction.getZ() * sinRotationAngle;
	returnMatrix[1][1] = cosRotationAngle + pow(direction.getY(), 2) * oneMinusCosRotationAngle;
	returnMatrix[2][1] = direction.getY() * direction.getZ() * oneMinusCosRotationAngle - direction.getX() * sinRotationAngle;
	
	returnMatrix[0][2] = direction.getZ() * direction.getX() * oneMinusCosRotationAngle - direction.getY() * sinRotationAngle;
	returnMatrix[1][2] = direction.getZ() * direction.getY() * oneMinusCosRotationAngle + direction.getX() * sinRotationAngle;
	returnMatrix[2][2] = cosRotationAngle + pow(direction.getZ(), 2)* oneMinusCosRotationAngle;

	return  returnMatrix;
}


// to compare two numbers it is sometimes helpful to round them
//Quelle: https://www.c-plusplus.net/forum/39342-full
double Math::roundNumber(double Zahl, unsigned int decimals)
{
	if (decimals <= 17)
	{
		std::vector<real> v = { 1, 10, 1e2, 1e3, 1e4, 1e5, 1e6, 1e7, 1e8, 1e9, 1e10, 1e11, 1e12, 1e13, 1e14, 1e15, 1e16 };
		return floor(Zahl * v[decimals] + 0.5) / v[decimals];
	}
	else
	{
		std::cout << "ERROR: the decimals have to be smaller than 18 to round the numer";
		return 0.0;
	}
}

//TODO QUESTION: This methode does not really fit to this class -> create maybe a class called "BasicMath"
// compare two reounded numbers
bool  Math::compareTwoNumbers_decimals(double num1, double num2, unsigned int decimals)
{
	double roundedNumber1 = roundNumber(num1, decimals);
	double roundedNumber2 = roundNumber(num2, decimals);
	//std::cout << roundedNumber1 << std::endl;
	//std::cout << roundedNumber2 << std::endl;
	if (roundedNumber1 == roundedNumber2)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Math::compareTwoNumbers_tolerance(real num1, real num2, real tolerance)
{
	if (std::abs(num1 - num2) < tolerance)
	{
		return true;
	}

	return false;
}


// Round the numbers of a matrix
std::vector<std::vector<real>> Math::RoundNumberMatrix(std::vector<std::vector<real>> Matrix, int decimal)
{
	std::vector<std::vector<real>> returnMatrix;
	returnMatrix.resize(3);
	returnMatrix[0].resize(3);
	returnMatrix[1].resize(3);
	returnMatrix[2].resize(3);

	//#pragma omp parallel for
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
			Matrix[i][j] = roundNumber(Matrix[i][j], decimal);
	}

	return returnMatrix;
}

// compare two vectors struct R3
bool Math::compareTwoVectorStructR3_decimals(VectorStructR3 const V1, VectorStructR3 const V2, unsigned int decimals)
{
	bool bEqual = true;

	if (!(roundNumber(V1.getX(), decimals) == roundNumber(V2.getX(), decimals)))	bEqual = false;
	else if (!(roundNumber(V1.getY(), decimals) == roundNumber(V2.getY(), decimals)))	bEqual = false;
	else if (!(roundNumber(V1.getZ(), decimals) == roundNumber(V2.getZ(), decimals)))	bEqual = false;

	return bEqual;
}

bool Math::compareTwoVectorStructR3_tolerance(VectorStructR3 const V1, VectorStructR3 const V2, real tolerance)
{
	bool check0 = compareTwoNumbers_tolerance(V1.getX(), V2.getX(), tolerance);
	bool check1 = compareTwoNumbers_tolerance(V1.getY(), V2.getY(), tolerance);
	bool check2 = compareTwoNumbers_tolerance(V1.getZ(), V2.getZ(), tolerance);

	return(check0 && check1 && check2);
}

// compate two vectors struct R2
bool Math::compareTwoVectorStruct2D_decimals(VectorStructR2 const V1, VectorStructR2 const V2, unsigned int const decimals)
{
	bool bEqual = true;

	if (!(roundNumber(V1.getX(), decimals) == roundNumber(V2.getX(), decimals)))	bEqual = false;
	else if (!(roundNumber(V1.getY(), decimals) == roundNumber(V2.getY(), decimals)))	bEqual = false;

	return bEqual;

}

bool Math::compareTwoVectorStruct2D_tolerance(VectorStructR2 const V1, VectorStructR2 const V2, real tolerance)
{
	bool check0 = compareTwoNumbers_tolerance(V1.getX(), V2.getX(), tolerance);
	bool check1 = compareTwoNumbers_tolerance(V1.getY(), V2.getY(), tolerance);


	return(check0 && check1);
}

// check if all vector elements are true
bool Math::checkTrueOfVectorElements(std::vector<bool> V)
{
	bool bEqual = true;
	//#pragma omp parallel for
	for (int n = 0; n < V.size(); ++n)
	{
		if (V.at(n) == false)
		{
			bEqual = false;
			// n = V.size(); using omp we can not modifi n
		}
	}

	return bEqual;
}

// compare numbers of a 3x3 matrix
bool Math::compareRoundedTwoMatrices3x3(std::vector<std::vector<real>> Matrix1, std::vector<std::vector<real>> Matrix2, unsigned int decimals)
{

	bool check[3][3];
	bool beEqual = true;
	// #pragma omp parallel for <-- that would need more time
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
			if (!compareTwoNumbers_decimals(Matrix1[i][j], Matrix2[i][j], decimals)) beEqual = false;
	}

	return beEqual;

}

// compare all vector elements
bool Math::compareAllVectorElements(std::vector<VectorStructR3> V1, std::vector<VectorStructR3> V2, unsigned int decimals)
{

	bool bEqual = true;
	//#pragma omp parallel for
	for (int n = 0; n < V2.size(); ++n)
	{
		if (!(roundNumber(V1[n].getX(), decimals) == roundNumber(V2[n].getX(), decimals)))	bEqual = false;
		if (!(roundNumber(V1[n].getY(), decimals) == roundNumber(V2[n].getY(), decimals)))	bEqual = false;
		if (!(roundNumber(V1[n].getZ(), decimals) == roundNumber(V2[n].getZ(), decimals)))	bEqual = false;
	}

	return bEqual;
}

double  Math::calc_D_ofPlane(VectorStructR3 const normalVector, VectorStructR3 const P)
{
	return normalVector.getX()*P.getX() + normalVector.getY()*P.getY() + normalVector.getZ()*P.getZ();
}
// calc "t" (steps to walk) unsing line and plan (coordinate form)
double Math::calc_T_ofPlanAndLine(VectorStructR3  const originLine, VectorStructR3  const coordFormPlan, double const d_coordForm)
{
	double numerator = d_coordForm - (coordFormPlan*originLine);
	double denominator = coordFormPlan * coordFormPlan;

	return numerator / denominator;
}


// find min value of a vector
double Math::minValueOfVector(std::vector<double> vector)
{
	real min = vector.at(0);
	unsigned int posMinElement;
	std::vector<real>::iterator result;

	result = std::min_element(vector.begin(), vector.end());
	posMinElement = std::distance(vector.begin(), result);
	min = vector.at(posMinElement);
	return min;
}

// find max value of a vector
double Math::maxValueOfVactor(std::vector<double> vector)
{
	real max = vector.at(0);
	unsigned int posMaxElement;
	std::vector<real>::iterator result;

	result = std::max_element(vector.begin(), vector.end());
	posMaxElement = std::distance(vector.begin(), result);
	max = vector.at(posMaxElement);
	return max;
}


// find value in vector near zero positiv side
VectorElementAndPosition Math::ValueInVectorNearZeroPosSide(std::vector<double> vector)
{

	double save = maxValueOfVactor(vector);
	unsigned int saveInteration{};


	//#pragma omp parallel for
	for (unsigned int iteration = 0; iteration < vector.size(); iteration++)
	{
		if (vector.at(iteration) > 0.0)
		{
			if (vector.at(iteration) <= save)
			{
				save = vector.at(iteration);
				saveInteration = iteration;
			}
		}
		else if (vector.at(iteration) == 0.0)
		{
			save = vector.at(iteration);
			saveInteration = iteration;

		};
	}

	VectorElementAndPosition output( save, saveInteration );

	return output;

}

// find pos value in a vector
unsigned int Math::posMinValueInVector(std::vector<real> vector)
{
	std::vector<real>::iterator result = std::min_element(std::begin(vector), std::end(vector));

	return std::distance(vector.begin(), result);

}

// check if all values in vactor are heigher than
bool Math::checkValuesHeigherThan(real value, std::vector<real> vec)
{
	unsigned int sizeVector = vec.size();

	for (unsigned int i = 0; i < sizeVector; ++i)
	{
		if (vec[i] < value)
		{
			return false;
		}
	}

	return true;
}

// find value in vector near zero negative side
VectorElementAndPosition Math::ValueInVectorNearZeroNegSide(std::vector<double> vector)
{
	double save = minValueOfVector(vector);
	unsigned int saveInteration{};

	//#pragma omp parallel for
	for (int iteration = 0; iteration < vector.size(); iteration++)
	{
		if (vector.at(iteration) < 0.0)
		{
			if (vector.at(iteration) > save)
			{
				save = vector.at(iteration);
				saveInteration = iteration;
			}
		}
		else if (vector.at(iteration) == 0.0)
		{
			save = vector.at(iteration);
			saveInteration = iteration;
		};
	}

	VectorElementAndPosition output( save, saveInteration );
	return output;
}

// linear distribution along two values -> double and steps
std::vector<real> Math::linDistriAlongTwoValues_double_steps(real valueMin, real ValueMax, real delta)
{
	std::vector<real> output;
	real tempValue = valueMin;
	while (tempValue <= ValueMax)
	{
		output.push_back(tempValue);
		tempValue = tempValue + delta;
	}

	return output;

}

// linear distribution along two values -> double
std::vector<real> Math::linDistriAlongTwoValues_double(real valueMin, real ValueMax, unsigned int number)
{

	std::vector<real> output;
	real delta = std::abs(valueMin - ValueMax) / (number - 1);

	// this loop can not be parallelized so easily using omp
	for (unsigned int i = 0; i <= number - 1; i++)
	{
		output.push_back(valueMin + delta * i);

	}

	return output;

}

// linear distribution along two values -> float
std::vector<float> Math::linDistriAlongTwoValues_float(float const valueMin, float const ValueMax, unsigned int const number)
{
	std::vector<float> output;
	real delta = std::abs(valueMin - ValueMax) / (number - 1);

	// this loop can not be parallelized so easily using omp
	for (unsigned int i = 0; i <= number - 1; i++)
	{
		output.push_back(valueMin + delta * i);

	}

	return output;
}

// vector with reals between min and max
std::vector<real> Math::calcVecRealMinMaxSteps_withoutMinMax(real min, real max, real steps, real withoutMin, real withoutMax)
{
	std::vector<real> output;
	real tempValue = min;
	output.push_back(min);
	bool smallerEqualMax = true;

	while (smallerEqualMax)
	{
		tempValue = tempValue + steps;

		if (min < tempValue && tempValue < withoutMin || withoutMax < tempValue && tempValue <= max)
		{
			output.push_back(tempValue);
		}

		if (tempValue >= max)
		{
			smallerEqualMax = false;

		}

	}

	return output;

}

// linear distribution along two values -> int
std::vector<int> Math::linDistriAlongTwoValues_int(int const valueMin, int const ValueMax, unsigned int const number)
{
	std::vector<int> output;

	real delta = std::abs(ceil(valueMin - ValueMax) / number);

	// this loop can not be parallelized so easily using omp
	for (unsigned int i = 0; i <= number; i++)
	{
		output.push_back(valueMin + delta * i);

	}

	return output;
}

// compare two std::vecor<real>
bool Math::compareTwoSTDVecors_decimals(std::vector<real> V1, std::vector<real> V2, unsigned int decimals)
{
	std::vector<bool> bool_vec;
	//#pragma omp parallel if(V1,V2,decimals)
	if (V1.size() == V2.size())
	{
		bool_vec.resize(V1.size());
		//#pragma omp for
		for (int i = 0; i < V1.size(); i++)
		{
			bool_vec[i] = compareTwoNumbers_decimals(V1.at(i), V2.at(i), decimals);
		}
	}

	else // vectros has different sizes
	{
		return false;
		std::cout << "vectros has different sizes" << std::endl;
	}


	return checkTrueOfVectorElements(bool_vec);

}

bool Math::compateTwoSTDVector_tolerance(std::vector<real> V1, std::vector<real> V2, real tolerance)
{
	std::vector<bool> bool_vec;
	//#pragma omp parallel if(V1,V2,decimals)
	if (V1.size() == V2.size())
	{
		bool_vec.resize(V1.size());
		//#pragma omp for
		for (int i = 0; i < V1.size(); i++)
		{
			bool_vec[i] = compareTwoNumbers_tolerance(V1.at(i), V2.at(i),tolerance );
		}
	}

	else // vectros has different sizes
	{
		return false;
		std::cout << "vectros has different sizes" << std::endl;
	}
	

	return checkTrueOfVectorElements(bool_vec);

}


// calculate orthogonal vector in 2D
VectorStructR2 Math::calcOrtoVec2D_Unit(VectorStructR2 vector)
{
	if (vector.getX() == 0 && vector.getY() != 0)
	{
		return VectorStructR2{ 1,0 };
	}

	if (vector.getY() == 0 && vector.getX() != 0)
	{
		return VectorStructR2{ 0,1 };
	}

	else
	{
		//x * a + b * x = 0
		// set a = 1 --> b = -x/y
		// unit = 1/sqrt((a^2 + b^2)) * {a , b}
		// unit = 1/sqrt((1 + b^2)) * {a , b}
		real b = -vector.getX() / vector.getY();
		real denom = std::sqrt(1 + std::pow(b, 2));
		return{ 1 / denom , b / denom };
	}

}

// calculate unit vector 2D
VectorStructR2 Math::unitVec2D(VectorStructR2 v)
{
	real denominator = std::sqrt(std::pow(v.getX(), 2) + std::pow(v.getY(), 2));
	return 1 / denominator * v;
}

// find max delta X,Y,Z in std::vector<VectorStructR3>
VectorStructR3 Math::findMaxDelta_X_Y_Z_inStdV_VectorStructR3(std::vector<VectorStructR3> const stdV_VecStrR3, VectorStructR3 refPoint)
{
	unsigned int const sizeStdV = stdV_VecStrR3.size();
	real X = stdV_VecStrR3.at(0).getX();
	real Y = stdV_VecStrR3.at(0).getY();
	real Z = stdV_VecStrR3.at(0).getZ();

	real const Ref_X = refPoint.getX();
	real const Ref_Y = refPoint.getY();
	real const Ref_Z = refPoint.getZ();

	VectorStructR3 startAbsMaxDeltaVec = { std::abs(X - Ref_X) , std::abs(Y - Ref_Y) , std::abs(Z - Ref_Z) };

//#pragma parallel for
	for (unsigned int i = 1; i < sizeStdV; i++)
	{
		real absTempDeltaValue_X = std::abs(stdV_VecStrR3.at(i).getX() - Ref_X);
		real absTempDeltaValue_Y = std::abs(stdV_VecStrR3.at(i).getY() - Ref_Y);
		real absTempDeltaValue_Z = std::abs(stdV_VecStrR3.at(i).getZ() - Ref_Z);

		if (absTempDeltaValue_X > startAbsMaxDeltaVec.getX())
		{
			startAbsMaxDeltaVec.setX(absTempDeltaValue_X);
		}

		if (absTempDeltaValue_Y > startAbsMaxDeltaVec.getY())
		{
			startAbsMaxDeltaVec.setY(absTempDeltaValue_Y);
		}

		if (absTempDeltaValue_Z > startAbsMaxDeltaVec.getZ())
		{
			startAbsMaxDeltaVec.setZ(absTempDeltaValue_Z);
		}


	}

	return startAbsMaxDeltaVec;

}

std::vector<std::vector<real>> Math::calculateInverse(const std::vector<std::vector<real>>& inpusMatrix)
{


	std::vector<std::vector<real>> workMatrix = inpusMatrix;

	unsigned int sizeInputCol = inpusMatrix[0].size();
	oftenUse::resizeAllRowsMatrix(workMatrix, 2 * sizeInputCol);

	for (unsigned int i = 0; i < sizeInputCol; i++) 
	{
		workMatrix[i][sizeInputCol + i] = 1.0;
	}

	for (int i = 0; i < sizeInputCol; i++) {
		// Search for maximum in this column
		double maxEl = abs(workMatrix[i][i]);
		int maxRow = i;
		for (int k = i + 1; k < sizeInputCol; k++) {
			if (abs(workMatrix[k][i]) > maxEl) {
				maxEl = workMatrix[k][i];
				maxRow = k;
			}
		}

		// Swap maximum row with current row (column by column)
		for (int k = i; k < 2 * sizeInputCol; k++) {
			double tmp = workMatrix[maxRow][k];
			workMatrix[maxRow][k] = workMatrix[i][k];
			workMatrix[i][k] = tmp;
		}

		// Make all rows below this one 0 in current column
		for (int k = i + 1; k < sizeInputCol; k++) {
			double c = -workMatrix[k][i] / workMatrix[i][i];
			for (int j = i; j < 2 * sizeInputCol; j++) {
				if (i == j) {
					workMatrix[k][j] = 0;
				}
				else {
					workMatrix[k][j] += c * workMatrix[i][j];
				}
			}
		}
	}

	// Solve equation Ax=b for an upper triangular matrix A
	for (int i = sizeInputCol - 1; i >= 0; i--) {
		for (int k = sizeInputCol; k < 2 * sizeInputCol; k++) {
			workMatrix[i][k] /= workMatrix[i][i];
		}


		for (int rowModify = i - 1; rowModify >= 0; rowModify--) {
			for (int columModify = sizeInputCol; columModify < 2 * sizeInputCol; columModify++) {
				workMatrix[rowModify][columModify] -= workMatrix[i][columModify]
					* workMatrix[rowModify][i];
			}

		}
	}

	// save only the inverted matrix
	std::vector<std::vector<real>> outputMatrix;

	outputMatrix.resize(sizeInputCol);
	oftenUse::resizeAllRowsMatrix(outputMatrix, sizeInputCol);
	for (unsigned int i = sizeInputCol; i < 2 * sizeInputCol; ++i)
	{
		for(unsigned int j = 0; j < sizeInputCol; ++j)
		
		outputMatrix[j][i - sizeInputCol] = workMatrix[j][i];
	}

	//outputMatrix
	//= inpusMatrix;

	return outputMatrix;

}

// add 4 values
real Math::add4values_ptr(real* a, real* b, real* c, real* d)
{
	real sum;

	sum = *a + *b + *c + *d;

	return sum;
}

// add all values in std::vector
real Math::addAllValuesInVector_real(std::vector<real> v)
{
	real sum_of_elems{};
	for (real& n : v) 	sum_of_elems += n;

	return sum_of_elems;
}

float Math::addAllValuesInVector_float(std::vector<float> v)
{
	float sum_of_elems{};
	for (float& n : v) 	sum_of_elems += n;

	return sum_of_elems;
}
int Math::addAllValuesInVector_int(std::vector<int> v)
{
	int sum_of_elems{};
	for (int& n : v) 	sum_of_elems += n;

	return sum_of_elems;
}
unsigned int Math::addAllValuesInVector_unsignedInt(std::vector<unsigned int> v)
{
	unsigned int sum_of_elems;
	for (unsigned int& n : v) 	sum_of_elems += n;

	return sum_of_elems;
}

//***********************************************************************
// add two vectors in R3
VectorStructR3 operator+ (VectorStructR3 const l, VectorStructR3 const  r)
{
	return VectorStructR3
	{ l.getX() + r.getX() ,
	l.getY() + r.getY() ,
	l.getZ() + r.getZ() };

}

//decide two vectors in R3
VectorStructR3 operator/ (VectorStructR3 const l, double const  d)
{
	return VectorStructR3
	{ l.getX() / d ,
	l.getY() / d ,
	l.getZ() / d };

}

//decide two vectors in R3
VectorStructR3 operator/ (double const  d, VectorStructR3 const l)
{
	return VectorStructR3
	{ l.getX() / d ,
	l.getY() / d ,
	l.getZ() / d };
}

// multiply two vectors in R3
double operator*(VectorStructR3 const l, VectorStructR3 const  r)
{
	return double{
		l.getX() * r.getX() +
		l.getY() * r.getY() +
		l.getZ() * r.getZ() };
}

// multiply two vectors in R3
VectorStructR3 operator*(VectorStructR3 const v, double const s)
{
	return VectorStructR3{
		v.getX() * s,
		v.getY() * s,
		v.getZ() * s };
}

// subtract two vectors in R3
VectorStructR3 operator-(VectorStructR3 const l, VectorStructR3 const  r)
{
	return VectorStructR3{
		l.getX() - r.getX(),
		l.getY() - r.getY(),
		l.getZ() - r.getZ() };
}



// calculate scalarproduct of two vectors in R3
VectorStructR3 operator*(double const s, VectorStructR3 const v)
{
	return VectorStructR3{
		v.getX() * s,
		v.getY() * s,
		v.getZ() * s };
}
//***********************************************************************

//***********************************************************************
// add two vectors in R2
VectorStructR2 operator+ (VectorStructR2 const l, VectorStructR2 const  r)
{
	return VectorStructR2
	{ l.getX() + r.getX() ,
		l.getY() + r.getY() };

}

//decide two vectors in R3
VectorStructR2 operator/ (VectorStructR2 const l, double const  d)
{
	return VectorStructR2
	{ l.getX() / d ,
		l.getY() / d };

}

//decide two vectors in R3
VectorStructR2 operator/ (double const d, VectorStructR2 const l)
{
	return VectorStructR2
	{ l.getX() / d ,
		l.getY() / d };
}

// multiply two vectors in R3
double operator*(VectorStructR2 const l, VectorStructR2 const r)
{
	return double{
		l.getX() * r.getX() +
		l.getY() * r.getY() };
}

// multiply two vectors in R3
VectorStructR2 operator*(VectorStructR2 const v, double const s)
{
	return VectorStructR2{
		v.getX() * s,
		v.getY() * s };
}

// subtract two vectors in R3
VectorStructR2 operator-(VectorStructR2 const l, VectorStructR2 const  r)
{
	return VectorStructR2{
		l.getX() - r.getX(),
		l.getY() - r.getY() };
}

// calculate scalarproduct of two vectors in R3
VectorStructR2 operator*(double const s, VectorStructR2 const v)
{
	return VectorStructR2{
		v.getX() * s,
		v.getY() * s };
}
//***********************************************************************

// subtract two std vectors
std::vector<real> operator- (const std::vector<real> l, const std::vector<real> r)
{
	unsigned int size_l = l.size();
	unsigned int size_r = r.size();
	
	std::vector<real> returnVec{};

	if (size_l != size_r)
	{
		std::cout << "the std::vectors must have the same size!!!!" << std::endl;
		return returnVec;
	}

	returnVec.resize(size_l);

	for (unsigned int i = 0; i < size_l; ++i)
	{
		returnVec[i] = l[i] - r[i];
	}

	return returnVec;
}

// add two std vectors
std::vector<real> operator+ (const std::vector<real> l, const std::vector<real> r)
{
	unsigned int size_l = l.size();
	unsigned int size_r = r.size();

	std::vector<real> returnVec{};

	if (size_l != size_r)
	{
		std::cout << "the std::vectors must have the same size!!!!" << std::endl;
		return returnVec;
	}

	returnVec.resize(size_l);

	for (unsigned int i = 0; i < size_l; ++i)
	{
		returnVec[i] = l[i] + r[i];
	}

	return returnVec;
}

// multiply scalar with matrix (std::vector<std::vectot<real>>)
std::vector<std::vector<real>> operator* (const real& s, std::vector<std::vector<real>>& matrix)
{
	std::vector<std::vector<real>> returnMatrix = matrix;

	unsigned int numColumns = matrix.size();
	unsigned int numRows = matrix[0].size();
	returnMatrix.resize(numColumns);
	oftenUse::resizeAllRowsMatrix(returnMatrix, numRows);

	for (unsigned int i = 0; i < numColumns; ++i)
	{
		for (unsigned int j = 0; j < numRows; ++j)
		{
			returnMatrix[i][j] = s * matrix[i][j];
		}

	}

	return returnMatrix;

}

// multiply scalar with std::vector 
std::vector<real> operator*(const real& s, std::vector<real>& v)
{
	std::vector<real> returnVector;
	unsigned int sizeVector = v.size();
	returnVector.resize(sizeVector);

	for (unsigned int i = 0; i < sizeVector; ++i)
	{
		returnVector[i] = s * v[i];
	}

	return returnVector;
}


