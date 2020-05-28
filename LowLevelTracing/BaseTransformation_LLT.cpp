#include "BaseTransformation_LLT.h"
#include <iostream>
#include "Math_LLT.h"

// print 3x3 matrix
void BaseTransformation_LLT::printMatrix(const double mat[3][3])
{
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
			std::cout << mat[i][j] << " ";

		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void BaseTransformation_LLT::swapLine(double mat[3][6], int line1, int line2)
{
	for (int i = 0; i < 6; ++i)
	{
		double t = mat[line1][i];
		mat[line1][i] = mat[line2][i];
		mat[line2][i] = t;
	}
}

std::vector<std::vector<real>> BaseTransformation_LLT::FillMatrixRowWise(const VectorStructR3& V1, const VectorStructR3& V2, const VectorStructR3& V3)
{
	std::vector<std::vector<real>> matrix;
	matrix.resize(3);
	matrix[0].resize(3);
	matrix[1].resize(3);
	matrix[2].resize(3);

	matrix[0][0] = V1.getX();
	matrix[0][1] = V2.getX();
	matrix[0][2] = V3.getX();

	matrix[1][0] = V1.getY();
	matrix[1][1] = V2.getY();
	matrix[1][2] = V3.getY();

	matrix[2][0] = V1.getZ();
	matrix[2][1] = V2.getZ();
	matrix[2][2] = V3.getZ();

	return matrix;

}


std::vector<std::vector<real>> BaseTransformation_LLT::CalcBaseTransformationMatrix(const VectorStructR3& direction)
{

	// check linearity to build Base Vector1
	VectorStructR3 BaseVector1;
	if (Math::checkLinearlyDependent(direction, { 1.0,0.0,0.0 }))
	{
		BaseVector1 = { 0.0,1.0,0.0 }; //y-direction
	}
	else
	{
		BaseVector1 = { 1.0,0.0,0.0 }; //x-direction
	}

	VectorStructR3 BaseVector3 = Math::unitVector(direction); //z-direction
	VectorStructR3 BaseVector2 = -1 * Math::unitVector(Math::DoCrossProduct(BaseVector1, BaseVector3)); //y-direction 
	std::vector<std::vector<real>> returnTransMatrix;
	
	// For the algorithm we have to fill the matrix row wise 
	returnTransMatrix = calcInversMatrix(FillMatrixRowWise(BaseVector1, BaseVector2, BaseVector3));


	return returnTransMatrix;
}



std::vector<std::vector<real>> BaseTransformation_LLT::calcInversMatrix(const std::vector<std::vector<real>>& matrix) // Quelle: https://www.thecrazyprogrammer.com/2017/02/c-c-program-find-inverse-matrix.html
																		  // Bsp.: double mat[3][3] = { { 2.0,-1.0,0.0 },{ 1.0,2.0,-2.0 },{ 0.0,-1.0,1.0 } } -> invers matrix: 0.2 0.2 0.0
																		  //	-0.2 0.3 1.0
																		  //  0.2 -0.3 0.0
{
	int i, j;
	real determinant = 0.0;
	std::vector<std::vector<real>> returnMatrix;
	returnMatrix.resize(3);
	returnMatrix[0].resize(3);
	returnMatrix[1].resize(3);
	returnMatrix[2].resize(3);

	double tolerance = 0.00000000001; // TODO Question: Welche Toleranz ist hier sinnvoll???

									  //finding determinant
	for (i = 0; i < 3; i++)
	{
		determinant = determinant + (matrix[0][i] * (matrix[1][(i + 1) % 3] * matrix[2][(i + 2) % 3] - matrix[1][(i + 2) % 3] * matrix[2][(i + 1) % 3]));
	};
	//std::cout << "______________________________\n";
	//std::cout <<determinant << std::endl;
	//std::cout << "______________________________\n";
	if (abs(determinant) < tolerance)
	{
		std::cout << "There's been a mistake. There is no inverse matrix" << std::endl;
		return returnMatrix;
	}

	////check___
	//std::cout << "______________________________\n";
	//std::cout << "matrix vor invertierung \n";
	//for (int i = 0; i < 3; ++i)
	//{
	//	for (int j = 0; j < 3; ++j)
	//		std::cout << mat[i][j] << " ";
	//
	//	std::cout << std::endl;
	//}
	//std::cout << std::endl;
	//
	//std::cout << "______________________________\n";
	//check___

	// calc invers matrix;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
			returnMatrix[i][j] = ((matrix[(j + 1) % 3][(i + 1) % 3] * matrix[(j + 2) % 3][(i + 2) % 3]) - (matrix[(j + 1) % 3][(i + 2) % 3] * matrix[(j + 2) % 3][(i + 1) % 3])) / determinant;
		//std::cout << ((mat[(j + 1) % 3][(i + 1) % 3] * mat[(j + 2) % 3][(i + 2) % 3]) - (mat[(j + 1) % 3][(i + 2) % 3] * mat[(j + 2) % 3][(i + 1) % 3])) / determinant << "\t";
		//std::cout << "\n";
	}

	//std::cout << "______________________________\n";
	//std::cout << "save matrix \n";
	//printMatrix(saveMatrix);
	//std::cout << "______________________________\n";


	return returnMatrix;

}


// calculat shift of point to new base point'
VectorStructR3 BaseTransformation_LLT::calcPointInNewBase(/*transformation matrix*/ std::vector<std::vector<real>> mat, /*shift*/ VectorStructR3 PointOldBase, VectorStructR3 NewBaseInGlobalCoord)
{
	VectorStructR3 VecPointOldBasNewBaseGlobalCoord = PointOldBase - NewBaseInGlobalCoord;

	VectorStructR3 transPoint = Math::multiplyMatrix3x3VectorR3(mat, VecPointOldBasNewBaseGlobalCoord);
	return transPoint; //shiftVctor

}



Ray_LLT BaseTransformation_LLT::transformRayInNewBase(Ray_LLT ray, std::vector<std::vector<real>> transMatrix, VectorStructR3 shiftVec)
{
	Ray_LLT returnRay_LLT_trans;
	VectorStructR3 transPointRay = BaseTransformation_LLT::calcPointInNewBase(transMatrix, ray.getOriginRay(), shiftVec);
	VectorStructR3 transDirectionRayUNIT = Math::multiplyMatrix3x3VectorR3(transMatrix, ray.getDirectionRayUnit());
	returnRay_LLT_trans.setOriginRay(transPointRay);
	returnRay_LLT_trans.setDirectionRayUnit(transDirectionRayUNIT);

	return returnRay_LLT_trans;
}

