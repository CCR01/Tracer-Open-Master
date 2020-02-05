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

void BaseTransformation_LLT::FillMatrixRowWise(VectorStructR3 V1, VectorStructR3 V2, VectorStructR3 V3, double mat[3][3])
{
	mat[0][0] = V1.getX();
	mat[0][1] = V2.getX();
	mat[0][2] = V3.getX();

	mat[1][0] = V1.getY();
	mat[1][1] = V2.getY();
	mat[1][2] = V3.getY();

	mat[2][0] = V1.getZ();
	mat[2][1] = V2.getZ();
	mat[2][2] = V3.getZ();

}


Matrix3x3AndExist BaseTransformation_LLT::CalcBaseTransformationMatrix(VectorStructR3 direction)
{


	Matrix3x3AndExist returnTransMatrix;
	returnTransMatrix.ExistMatrix = 0;
	//returnTransMatrix.Matrix[3][3] = Matrix[3][3];

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
	real Matrix[3][3];
	FillMatrixRowWise(BaseVector1, BaseVector2, BaseVector3, Matrix);
	// For the algorithm we have to fill the matrix row wise 
	returnTransMatrix = calcInversMatrix(Matrix);


	return returnTransMatrix;
}



Matrix3x3AndExist  BaseTransformation_LLT::calcInversMatrix(real mat[3][3]) // Quelle: https://www.thecrazyprogrammer.com/2017/02/c-c-program-find-inverse-matrix.html
																				  // Bsp.: double mat[3][3] = { { 2.0,-1.0,0.0 },{ 1.0,2.0,-2.0 },{ 0.0,-1.0,1.0 } } -> invers matrix: 0.2 0.2 0.0
																				  //	-0.2 0.3 1.0
																				  //  0.2 -0.3 0.0
{
	int i, j;
	real determinant = 0.0;
	real saveMatrix[3][3];
	Matrix3x3AndExist returnMatrix;
	returnMatrix.ExistMatrix = 1;
	double tolerance = 0.00000000001; // TODO Question: Welche Toleranz ist hier sinnvoll???

									  //finding determinant
	for (i = 0; i < 3; i++)
		determinant = determinant + (mat[0][i] * (mat[1][(i + 1) % 3] * mat[2][(i + 2) % 3] - mat[1][(i + 2) % 3] * mat[2][(i + 1) % 3]));
	//std::cout << "______________________________\n";
	//std::cout <<determinant << std::endl;
	//std::cout << "______________________________\n";
	if (abs(determinant) < tolerance)
	{
		returnMatrix.ExistMatrix = 0;
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
			saveMatrix[i][j] = ((mat[(j + 1) % 3][(i + 1) % 3] * mat[(j + 2) % 3][(i + 2) % 3]) - (mat[(j + 1) % 3][(i + 2) % 3] * mat[(j + 2) % 3][(i + 1) % 3])) / determinant;
		//std::cout << ((mat[(j + 1) % 3][(i + 1) % 3] * mat[(j + 2) % 3][(i + 2) % 3]) - (mat[(j + 1) % 3][(i + 2) % 3] * mat[(j + 2) % 3][(i + 1) % 3])) / determinant << "\t";
		//std::cout << "\n";
	}

	//std::cout << "______________________________\n";
	//std::cout << "save matrix \n";
	//printMatrix(saveMatrix);
	//std::cout << "______________________________\n";


	returnMatrix.saveMatrix(saveMatrix);
	return returnMatrix;

}


// calculat shift of point to new base point'
VectorStructR3 BaseTransformation_LLT::calcPointInNewBase(/*transformation matrix*/ double mat[3][3], /*shift*/ VectorStructR3 PointOldBase, VectorStructR3 NewBaseInGlobalCoord)
{
	VectorStructR3 VecPointOldBasNewBaseGlobalCoord = PointOldBase - NewBaseInGlobalCoord;

	VectorStructR3 transPoint = Math::multiplyMatrix3x3VectorR3(mat, VecPointOldBasNewBaseGlobalCoord);
	return transPoint; //shiftVctor

}



Ray_LLT BaseTransformation_LLT::transformRayInNewBase(Ray_LLT ray, real transMatrix[3][3], VectorStructR3 shiftVec)
{
	Ray_LLT returnRay_LLT_trans;
	VectorStructR3 transPointRay = BaseTransformation_LLT::calcPointInNewBase(transMatrix, ray.getOriginRay(), shiftVec);
	VectorStructR3 transDirectionRayUNIT = Math::multiplyMatrix3x3VectorR3(transMatrix, ray.getDirectionRayUnit());
	returnRay_LLT_trans.setOriginRay(transPointRay);
	returnRay_LLT_trans.setDirectionRayUnit(transDirectionRayUNIT);

	return returnRay_LLT_trans;
}

