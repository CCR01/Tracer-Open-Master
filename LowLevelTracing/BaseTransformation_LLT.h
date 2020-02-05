// Quelle: http://www.virtual-maxim.de/matrix-invertieren-in-c-plus-plus/
 // Test: http://www.virtual-maxim.de/basistransformationsmatrix-berechnen/
#pragma once

#include "ImportantStructures.h"
#include "Ray_LLT.h"

  namespace BaseTransformation_LLT
{

	   // Print 3x3 matrix
	   void printMatrix(const double mat[3][3]);
	
	   // Swaps two lines in a NxM matrix.
	   void swapLine(double mat[3][6], int line1, int line2);
	
	   // Fill 3x3 matrix with vectors
	   void FillMatrixRowWise(VectorStructR3 V1, VectorStructR3 V2, VectorStructR3 V3, double mat[3][3]);
	
	   // Calculate the transformation Matrix
	   Matrix3x3AndExist CalcBaseTransformationMatrix(VectorStructR3 direction);
	
	   // Calculate the invers matrix for back transformation
	   Matrix3x3AndExist calcInversMatrix(real mat[3][3]);
	
	
	
	   // transform a Ray in an new Base
	   // in com
	   Ray_LLT transformRayInNewBase(Ray_LLT ray, real transMatrix[3][3], VectorStructR3 shiftVec);
	
	   // calculat shift of point to new base point
	   VectorStructR3  calcPointInNewBase(/*transformation matrix*/ double transMatrix[3][3], /*shift*/ VectorStructR3 shiftVec, VectorStructR3 point);
  }






