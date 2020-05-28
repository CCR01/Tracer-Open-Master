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
	   std::vector<std::vector<real>> FillMatrixRowWise(const VectorStructR3& V1, const VectorStructR3& V2, const VectorStructR3& V3);
	
	   // Calculate the transformation Matrix
	   std::vector<std::vector<real>> CalcBaseTransformationMatrix(const VectorStructR3& direction);
	
	   // Calculate the invers matrix for back transformation
	   std::vector<std::vector<real>> calcInversMatrix(const std::vector<std::vector<real>>& matrix);
	
	
	
	   // transform a Ray in an new Base
	   // in com
	   Ray_LLT transformRayInNewBase(Ray_LLT ray, std::vector<std::vector<real>> transMatrix, VectorStructR3 shiftVec);
	
	   // calculat shift of point to new base point
	   VectorStructR3  calcPointInNewBase(/*transformation matrix*/ std::vector<std::vector<real>> transMatrix, /*shift*/ VectorStructR3 shiftVec, VectorStructR3 point);
  }






