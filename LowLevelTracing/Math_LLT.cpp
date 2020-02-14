#include <cmath>

#include "Math_LLT.h"
#include <iostream>
#include <algorithm>


// calc new value variance percent
/*CR*/real Math::calcNewValueVariancePercent(real initilaValue, real percent)
{
	return initilaValue * (percent + 100.0) / 100.0;
}


// convert an angle in direction
/*CR*/ VectorStructR3 Math::convertAngleInDirection(real angleDegreesX, real angleDegreesY)
{
	VectorStructR3 returnVec3;
	returnVec3.setX(tan(angleDegreesX * PI / 180));
	returnVec3.setY(tan(angleDegreesY * PI / 180));
	returnVec3.setZ(1);

	return returnVec3;
}

/*CR*/ twoVaulesReal Math::convertDirectionInAngle(VectorStructR3 direction)
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
VectorStructR3 Math::scaleVector(double const& scaleFactor, VectorStructR3 const& Vscale)
{
	VectorStructR3 ReturnVectorScale;
	ReturnVectorScale.setX(scaleFactor * Vscale.getX());
	ReturnVectorScale.setY(scaleFactor * Vscale.getY());
	ReturnVectorScale.setZ(scaleFactor * Vscale.getZ());

	return ReturnVectorScale;
}

// calculate unit vector
VectorStructR3 Math::unitVector(VectorStructR3 const& V)
{
	double lenghtOfVector = 1 / (std::sqrt(V.getX()*V.getX() + V.getY()*V.getY() + V.getZ()*V.getZ()));
	return scaleVector(lenghtOfVector, V);
}


// subtract two vectors
VectorStructR3 Math::subVectors(VectorStructR3 V1sub, VectorStructR3 V2sub)
{
	VectorStructR3 VectorReturnSub;
	VectorReturnSub.setX(V1sub.getX() - V2sub.getX());
	VectorReturnSub.setY(V1sub.getY() - V2sub.getY());
	VectorReturnSub.setZ(V1sub.getZ() - V2sub.getZ());

	return VectorReturnSub;
}

//calculate cross product
VectorStructR3 Math::DoCrossProduct(VectorStructR3 CrProVec1, VectorStructR3 CrProVec2)
{
	VectorStructR3 ReturnCrossProductVector;

	VectorStructR3 helpVector1;
	helpVector1.setX(CrProVec1.getY() * CrProVec2.getZ());
	helpVector1.setY(CrProVec1.getZ() * CrProVec2.getX());
	helpVector1.setZ(CrProVec1.getX() * CrProVec2.getY());

	VectorStructR3 helpVector2;
	helpVector2.setX(CrProVec1.getZ() * CrProVec2.getY());
	helpVector2.setY(CrProVec1.getX() * CrProVec2.getZ());
	helpVector2.setZ(CrProVec1.getY() * CrProVec2.getX());

	return ReturnCrossProductVector = subVectors(helpVector1, helpVector2);
}

// Check if two vectors are linearly dependent
bool Math::checkLinearlyDependent(VectorStructR3 const& V1, VectorStructR3 const& V2)
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
VectorStructR3 Math::multiplyMatrix3x3VectorR3(double mat[3][3], VectorStructR3 vec)
{
	VectorStructR3 returnVector;
	returnVector.setX(mat[0][0] * vec.getX() + mat[0][1] * vec.getY() + mat[0][2] * vec.getZ());
	returnVector.setY(mat[1][0] * vec.getX() + mat[1][1] * vec.getY() + mat[1][2] * vec.getZ());
	returnVector.setZ(mat[2][0] * vec.getX() + mat[2][1] * vec.getY() + mat[2][2] * vec.getZ());
	return returnVector;

}


//calculate length of vector
double Math::lengthOfVector(VectorStructR3 vLength)
{
	return sqrt(vLength.getX()*vLength.getX() + vLength.getY()*vLength.getY() + vLength.getZ()*vLength.getZ());
}

// calculate distance between two points in R3
double Math::distanceTwoVectors(VectorStructR3 const& V1, VectorStructR3 const& V2)
{
	return sqrt(pow(V1.getX() - V2.getX(), 2) + pow(V1.getY() - V2.getY(), 2) + pow(V1.getZ() - V2.getZ(), 2));
}


// calculate rotate matrix around an axis n
// source https://en.wikipedia.org/wiki/Rotation_matrix
Matrix3x3AndExist Math::calcRotationMatrixAroundVector(VectorStructR3 const& direction, double const& /*in radiant*/ rotationAngle)
{


	Matrix3x3AndExist returnMatrixAndExist;
	returnMatrixAndExist.ExistMatrix = 1;
	real const & cosRotationAngle = cos(rotationAngle);
	real const & sinRotationAngle = sin(rotationAngle);
	real const & oneMinusCosRotationAngle = 1 - cosRotationAngle;
	returnMatrixAndExist.Matrix[0][0] = cosRotationAngle + pow(direction.getX(), 2)* oneMinusCosRotationAngle;
	returnMatrixAndExist.Matrix[1][0] = direction.getX() * direction.getY() * oneMinusCosRotationAngle - direction.getZ() * sinRotationAngle;
	returnMatrixAndExist.Matrix[2][0] = direction.getX() * direction.getZ() * oneMinusCosRotationAngle + direction.getY() * sinRotationAngle;
	returnMatrixAndExist.Matrix[0][1] = direction.getY() * direction.getX() * oneMinusCosRotationAngle + direction.getZ() * sinRotationAngle;
	returnMatrixAndExist.Matrix[1][1] = cosRotationAngle + pow(direction.getY(), 2)* oneMinusCosRotationAngle;
	returnMatrixAndExist.Matrix[2][1] = direction.getY() * direction.getZ() * oneMinusCosRotationAngle - direction.getX() * sinRotationAngle;
	returnMatrixAndExist.Matrix[0][2] = direction.getZ() * direction.getX() * oneMinusCosRotationAngle - direction.getY() * sinRotationAngle;
	returnMatrixAndExist.Matrix[1][2] = direction.getZ() * direction.getY() * oneMinusCosRotationAngle + direction.getX() * sinRotationAngle;
	returnMatrixAndExist.Matrix[2][2] = cosRotationAngle + pow(direction.getZ(), 2)* oneMinusCosRotationAngle;

	return  returnMatrixAndExist;
}


// to compare two numbers it is sometimes helpful to round them
//Quelle: https://www.c-plusplus.net/forum/39342-full
double Math::roundNumber(double Zahl, unsigned int decimals)
{
	if (decimals <= 17)
	{
		double v[] = { 1, 10, 1e2, 1e3, 1e4, 1e5, 1e6, 1e7, 1e8, 1e9, 1e10, 1e11, 1e12, 1e13, 1e14, 1e15, 1e16 };
		return floor(Zahl * v[decimals] + 0.5) / v[decimals];
	}
	else
	{
		std::cout << "ERROR: the decimals have to be smaller than 18 to round the numer";
		return 0;
	}
}

//TODO QUESTION: This methode does not really fit to this class -> create maybe a class called "BasicMath"
// compare two reounded numbers
bool  Math::compareTwoNumbers(double num1, double num2, unsigned int decimals)
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



// Round the numbers of a matrix
Matrix3x3AndExist Math::RoundNumberMatrix(real Matrix[3][3], int decimal)
{
	Matrix3x3AndExist retunMatrixAndExist;
	retunMatrixAndExist.ExistMatrix = 1;

	//#pragma omp parallel for
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
			Matrix[i][j] = roundNumber(Matrix[i][j], decimal);
	}

	return retunMatrixAndExist;
}

// compare two vectors struct R3
bool Math::compareTwoVectorStructR3(VectorStructR3 const& V1, VectorStructR3 const& V2, unsigned int const& decimals)
{
	bool bEqual = true;

	if (!(roundNumber(V1.getX(), decimals) == roundNumber(V2.getX(), decimals)))	bEqual = false;
	else if (!(roundNumber(V1.getY(), decimals) == roundNumber(V2.getY(), decimals)))	bEqual = false;
	else if (!(roundNumber(V1.getZ(), decimals) == roundNumber(V2.getZ(), decimals)))	bEqual = false;

	return bEqual;
}

// compate two vectors struct R2
bool Math::compareTwoVectorStruct2D(VectorStructR2 const& V1, VectorStructR2 const& V2, unsigned int const& decimals)
{
	bool bEqual = true;

	if (!(roundNumber(V1.getX(), decimals) == roundNumber(V2.getX(), decimals)))	bEqual = false;
	else if (!(roundNumber(V1.getY(), decimals) == roundNumber(V2.getY(), decimals)))	bEqual = false;

	return bEqual;

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
bool Math::compareRoundedTwoMatrices3x3(real Matrix1[3][3], real Matrix2[3][3], unsigned int decimals)
{

	bool check[3][3];
	bool beEqual = true;
	// #pragma omp parallel for <-- that would need more time
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
			if (!compareTwoNumbers(Matrix1[i][j], Matrix2[i][j], decimals)) beEqual = false;
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

double  Math::calc_D_ofPlane(VectorStructR3 const& normalVector, VectorStructR3 const& P)
{
	return normalVector.getX()*P.getX() + normalVector.getY()*P.getY() + normalVector.getZ()*P.getZ();
}
// calc "t" (steps to walk) unsing line and plan (coordinate form)
double Math::calc_T_ofPlanAndLine(VectorStructR3  const& originLine, VectorStructR3  const& coordFormPlan, double const& d_coordForm)
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
	unsigned int saveInteration;


	//#pragma omp parallel for
	for (int iteration = 0; iteration < vector.size(); iteration++)
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

	VectorElementAndPosition output{ save, saveInteration };

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
	unsigned int saveInteration;

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

	VectorElementAndPosition output{ save, saveInteration };
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
	real delta = std::abs(valueMin - ValueMax) / (number);

	// this loop can not be parallelized so easily using omp
	for (unsigned int i = 0; i <= number; i++)
	{
		output.push_back(valueMin + delta * i);

	}

	return output;

}

// linear distribution along two values -> float
std::vector<float> Math::linDistriAlongTwoValues_float(float const& valueMin, float const& ValueMax, unsigned int const& number)
{
	std::vector<float> output;
	real delta = std::abs(valueMin - ValueMax) / (number);

	// this loop can not be parallelized so easily using omp
	for (unsigned int i = 0; i <= number; i++)
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
std::vector<int> Math::linDistriAlongTwoValues_int(int const& valueMin, int const& ValueMax, unsigned int const& number)
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
bool Math::compareTwoSTDVecors(std::vector<real> V1, std::vector<real> V2, unsigned decimals)
{
	bool output = true;

	//#pragma omp parallel if(V1,V2,decimals)
	if (V1.size() == V2.size())
	{
		//#pragma omp for
		for (int i = 0; i < V1.size(); i++)
		{
			output = compareTwoNumbers(V1.at(i), V2.at(i), decimals);
		}
	}

	else // vectros has different sizes
	{
		output = false;
		std::cout << "vectros has different sizes" << std::endl;
	}

	return output;

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
VectorStructR3 Math::findMaxDelta_X_Y_Z_inStdV_VectorStructR3(std::vector<VectorStructR3> const& stdV_VecStrR3, VectorStructR3 refPoint)
{
	unsigned int const& sizeStdV = stdV_VecStrR3.size();
	real X = stdV_VecStrR3.at(0).getX();
	real Y = stdV_VecStrR3.at(0).getY();
	real Z = stdV_VecStrR3.at(0).getZ();

	real const& Ref_X = refPoint.getX();
	real const& Ref_Y = refPoint.getY();
	real const& Ref_Z = refPoint.getZ();

	VectorStructR3 startAbsMaxDeltaVec = { std::abs(X - Ref_X) , std::abs(Y - Ref_Y) , std::abs(Z - Ref_Z) };

#pragma parallel for
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

// add 4 values
real Math::add4values_ptr(real* a, real* b, real* c, real* d)
{
	real sum;

	sum = *a + *b + *c + *d;

	return sum;
}

//***********************************************************************
// add two vectors in R3
VectorStructR3 operator+ (VectorStructR3 const& l, VectorStructR3 const&  r)
{
	return VectorStructR3
	{ l.getX() + r.getX() ,
	l.getY() + r.getY() ,
	l.getZ() + r.getZ() };

}

//decide two vectors in R3
VectorStructR3 operator/ (VectorStructR3 const& l, double const&  d)
{
	return VectorStructR3
	{ l.getX() / d ,
	l.getY() / d ,
	l.getZ() / d };

}

//decide two vectors in R3
VectorStructR3 operator/ (double const&  d, VectorStructR3 const& l)
{
	return VectorStructR3
	{ l.getX() / d ,
	l.getY() / d ,
	l.getZ() / d };
}

// multiply two vectors in R3
double operator*(VectorStructR3 const& l, VectorStructR3 const&  r)
{
	return double{
		l.getX() * r.getX() +
		l.getY() * r.getY() +
		l.getZ() * r.getZ() };
}

// multiply two vectors in R3
VectorStructR3 operator*(VectorStructR3 const& v, double const s)
{
	return VectorStructR3{
		v.getX() * s,
		v.getY() * s,
		v.getZ() * s };
}

// subtract two vectors in R3
VectorStructR3 operator-(VectorStructR3 const& l, VectorStructR3 const&  r)
{
	return VectorStructR3{
		l.getX() - r.getX(),
		l.getY() - r.getY(),
		l.getZ() - r.getZ() };
}



// calculate scalarproduct of two vectors in R3
VectorStructR3 operator*(double const& s, VectorStructR3 const& v)
{
	return VectorStructR3{
		v.getX() * s,
		v.getY() * s,
		v.getZ() * s };
}
//***********************************************************************

//***********************************************************************
// add two vectors in R2
VectorStructR2 operator+ (VectorStructR2 const& l, VectorStructR2 const&  r)
{
	return VectorStructR2
	{ l.getX() + r.getX() ,
		l.getY() + r.getY() };

}

//decide two vectors in R3
VectorStructR2 operator/ (VectorStructR2 const& l, double const&  d)
{
	return VectorStructR2
	{ l.getX() / d ,
		l.getY() / d };

}

//decide two vectors in R3
VectorStructR2 operator/ (double const&  d, VectorStructR2 const& l)
{
	return VectorStructR2
	{ l.getX() / d ,
		l.getY() / d };
}

// multiply two vectors in R3
double operator*(VectorStructR2 const& l, VectorStructR2 const&  r)
{
	return double{
		l.getX() * r.getX() +
		l.getY() * r.getY() };
}

// multiply two vectors in R3
VectorStructR2 operator*(VectorStructR2 const& v, double const s)
{
	return VectorStructR2{
		v.getX() * s,
		v.getY() * s };
}

// subtract two vectors in R3
VectorStructR2 operator-(VectorStructR2 const& l, VectorStructR2 const&  r)
{
	return VectorStructR2{
		l.getX() - r.getX(),
		l.getY() - r.getY() };
}

// calculate scalarproduct of two vectors in R3
VectorStructR2 operator*(double const& s, VectorStructR2 const& v)
{
	return VectorStructR2{
		v.getX() * s,
		v.getY() * s };
}
//***********************************************************************




