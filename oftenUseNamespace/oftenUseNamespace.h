#pragma once

#include "..\LowLevelTracing\ImportantStructures.h"
#include "..\LowLevelTracing\OpticalSystem_LLT.h"
#include "..\OpticalSystemElement\OpticalSystemElement.h"

enum compareTOM_Zemax{comEqual, comBetter};

namespace oftenUse
{
	bool checkRayTracing(/*start point ray*/ VectorStructR3 startPoint,/*direction ray*/ VectorStructR3 direction,/*target point*/ VectorStructR3 targetPoint,/*optical system LLT*/ OpticalSystem_LLT optSys_LLT,/*surface num*/ unsigned int surfaceNum,/*tolerance*/ real tolerande);
	bool checkIfUnsIntIsInVector(/*search for unsingt int*/ unsigned int target, /*vector with unsigned int*/ std::vector<unsigned int> vectorUnsInt);

	void resizeAllRowsMatrix(std::vector<std::vector<real>>& matrix, unsigned int rows);
	
	// print
	void print(std::vector< std::vector<double> > A);
	void print(std::vector<real> V);

	// get very height number
	real getInfReal();
	float getInfFloat();
	int getInfInt();
	//unsigned getInfUnsignedInt();

	// check if two values have the same prefix
	bool checkSamePrefixTwoVal(real v1, real v2);

	Light_LLT getDefaultLight();
	Light_LLT buildDefaultLight(real wavelength);
	
	// build default Light vector
	std::vector<Light_LLT> buildDefaultLight_Vec(std::vector<real> wavelength_vec);

	// check optical system HLT better / eauel than zemax
	bool checkOptSysELement_Equal_Better_Zemax(OpticalSystemElement optimizedSystemHLT, std::vector<VectorStructR3> fieldPoints, std::vector<real> wavelength_vec, std::vector<real> rmsValZemax, real tolerance, compareTOM_Zemax compare);
	
	// check optical system LLT better / equal than zemax
	bool checkOptSysLLT_Equal_Better_Zemax(OpticalSystem_LLT optSys_LLT, std::vector<VectorStructR3> fieldPoints, std::vector<real> rmsValZemax, real tolerance, compareTOM_Zemax compare);

	// check the thickness between surfaces
	bool checkThickness(OpticalSystem_LLT optSys_LLT, std::vector<real> thickness_vec, real tolerance);

}