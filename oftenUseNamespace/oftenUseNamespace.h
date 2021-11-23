#pragma once

#include "..\LowLevelTracing\ImportantStructures.h"
#include "..\LowLevelTracing\OpticalSystem_LLT.h"
#include "..\OpticalSystemElement\OpticalSystemElement.h"
#include "..\OptimizeSystem\DampedLeastSquares.h"
#include "..\OptimizeSystem\Genetic.h"
#include "..\Noise\Noise.h"

// structs for statistic evaluation
#include "..\tests\testLensReplaceAndOptimiz_statistic\testLensRepAndOptimize_statisticStruct.h"

enum class compareTOM_Zemax { comEqual, comBetter };

namespace oftenUse
{
	bool checkRayTracing(/*start point ray*/ VectorStructR3 startPoint,/*direction ray*/ VectorStructR3 direction,/*target point*/ VectorStructR3 targetPoint,/*optical system LLT*/ OpticalSystem_LLT optSys_LLT,/*surface num*/ unsigned int surfaceNum,/*tolerance*/ real tolerance);
	bool checkIfUnsIntIsInVector(/*search for unsingt int*/ unsigned int target, /*vector with unsigned int*/ std::vector<unsigned int> vectorUnsInt);

	void resizeAllRowsMatrix(std::vector<std::vector<real>>& matrix, unsigned int rows);
	void resizeAllRowsMatrix(std::vector<std::vector<float>>& matrix, unsigned int rows);

	// print
	void print(std::vector< std::vector<double> > A);
	void print(std::vector<real> V);
	void print(OpticalSystemElement opticalSysElement, real Wavelength);
	void print(OpticalSystem_LLT optSys);

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

	// check optical system HLT better / eqauel than zemax
	bool checkOptSysELement_Equal_Better_Zemax(OpticalSystemElement optimizedSystemHLT, std::vector<VectorStructR3> fieldPoints, std::vector<real> wavelength_vec, std::vector<real> rmsValZemax, real tolerance, compareTOM_Zemax compare);
	bool checkOptSysELement_Equal_Better_Zemax(OpticalSystemElement optimizedSystemHLT, VectorStructR3 fieldPoint, real wavelength, real rmsValZemax, real tolerance, compareTOM_Zemax compare);
	bool checkOptSysELement_Equal_Better_Zemax(OpticalSystemElement optimizedSystemHLT, VectorStructR3 fieldPoint, std::vector<real> wavelength_vec, real rmsValZemax, real tolerance, compareTOM_Zemax compare);
	bool checkOptSysELement_Equal_Better_Zemax(OpticalSystemElement optimizedSystemHLT, std::vector<VectorStructR3> fieldPoint_vec, real wavelength, std::vector<real> rmsValZemax_vec, real tolerance, compareTOM_Zemax compare);

	// check optical system HLT better / eauel than zemax
	bool checkOptSysELement_Equal_Better_Zemax(OpticalSystemElement optimizedSystemHLT, std::vector<real> anglesX_vec, std::vector<real> anglesY_vec, std::vector<real> wavelength_vec, std::vector<real> rmsValZemax, real tolerance, compareTOM_Zemax compare);
	bool checkOptSysELement_Equal_Better_Zemax(OpticalSystemElement optimizedSystemHLT, real anglesX, real anglesY, std::vector<real> wavelength_vec, std::vector<real> rmsValZemax, real tolerance, compareTOM_Zemax compare);
	bool checkOptSysELement_Equal_Better_Zemax(OpticalSystemElement optimizedSystemHLT, real anglesX, real anglesY, real wavelength, real rmsValZemax, real tolerance, compareTOM_Zemax compare);

	// get rms valus of optical system HLT
	std::vector<real> getRMSoptSysHLT(OpticalSystemElement optimizedSystemHLT, std::vector<VectorStructR3> fieldPoints, std::vector<real> wavelength_vec, unsigned int rings, unsigned int arms);
	std::vector<real> getRMSoptSysHLT(OpticalSystemElement optimizedSystemHLT, std::vector<real> fieldAngle_X, std::vector<real> fieldAngle_Y, std::vector<real> wavelength_vec, unsigned int rings, unsigned int arms);

	// check optical system LLT better / equal than zemax
	bool checkOptSysLLT_Equal_Better_Zemax(OpticalSystem_LLT optSys_LLT, std::vector<VectorStructR3> fieldPoints, std::vector<real> rmsValZemax, real tolerance, compareTOM_Zemax compare);
	bool checkOptSysLLT_Equal_Better_Zemax(OpticalSystem_LLT optSys_LLT, VectorStructR3 fieldPoints, real rmsValZemax, real tolerance, compareTOM_Zemax compare);
	bool checkOptSysLLT_Equal_Better_Zemax(OpticalSystem_LLT optSys_LLT, std::vector<real> fieldAngle_X, std::vector<real> fieldAngle_Y, std::vector<real> rmsValZemax, real tolerance, compareTOM_Zemax compare);

	// check the thickness between surfaces
	bool checkThickness(OpticalSystem_LLT optSys_LLT, std::vector<real> thickness_vec, real tolerance);

	// we use that function to find the best parameters for optimization with DLS multiplicativ damping
	bool DLSmulticheck(DLS startDLS, std::vector<real> factorBetter_vec, std::vector<real> factorWorst_vec, std::vector<real> rmsZ_vec, unsigned int systemNum);

	std::vector<real> getVariablesOfOptSysHLT(OpticalSystemElement optSysEle);

	// check if one value in the vector is true
	bool checkIf_ONE_valueIsTrue(const std::vector<bool>& vector);

	bool checkDeltaVariables(OpticalSystemElement optSysEle, std::vector<real> bestValue, real delta);

	// check number for histogram
	std::vector<real> makeHistogram(std::vector<real> number, real min, real max, unsigned int sampling);

	// check intersectinformations 
	bool checkIntersectInfos(const IntersectInformationStruct& intersectInfos, const IntersectInformationStruct& controleIntersectInfos, real tolerance);

	// check if all values in a vevtor are less than a specific value
	bool checkValInVacLessThan(std::vector<real> vec, real minVal);

	// check if average of values in vecor are less than specific value
	bool checkAverageOfVecValLessThan(std::vector<real> vec, real minVal);

	// convert type mode variable to string
	std::string convertTypeModeToString(typeModifier typeMode);

	real sum(std::vector<real> vec);

	bool checkDLS_resultRMS(DLS dls, real tolerance);
	bool checkDLS_resultTargetCarPoints(DLS dls, real tolerance);


	std::vector<real> weightingRMS_fields(std::vector<real> rms_vec, std::vector<real> weightRMS_vec);

	// resize weight wavelength vector
	std::vector<real> resizeWeightWave_vec(std::vector<real> wave_vec, std::vector<unsigned int> weightWave_vec);

	// check optimized target cardinal point
	bool optimizedTargetBetterThanStartCardinalPoint(/*start value*/ real startValue, /*optimized value*/ real optVal, /*target val*/ real targetVal);

	// get default values for DLS optimization
	defaultParaDLS getDefaultPara_DLS(bool rayTracing);


	// get default values for genetic optimisation
	defaultParaGenetic getDafulatPara_Genetic(bool rayTracing);

	std::string replacePointByComma(std::string inputString);

	// check for nan in VectorStructR3
	bool checkFor_No_Nan(VectorStructR3 vec);

	// error protocol
	void errorProtocol_stopSystem(/*error*/ std::string error, /*location*/ std::string location, /*error number*/ unsigned int errorNumber, /*stop program*/ bool stopProgram);

	bool checkForEvenNumber(int number);
	bool checkForOddNumber(int number);

	// get start refractiv index
	real getStartRefIndex(OpticalSystem_LLT optSys_LLT);

	LightRayStruct findMarginalRay_inf(OpticalSystemElement optSysEle, real primWavelength, Light_LLT light);
	LightRayStruct findChiefRay_inf(OpticalSystemElement optSysEle, real primWavelength, real maxAngelY, Light_LLT light);

	LightRayStruct findMarginalRay_obj(OpticalSystemElement optSysEle, real primWavelength, Light_LLT light);
	LightRayStruct findChiefRay_obj(OpticalSystemElement optSysEle, real primWavelength, VectorStructR3 maxStartPoint, Light_LLT light);

	// find lenses in optical system
	std::vector<OpticalSystem_LLT> findLensesInOptSys_LLT(OpticalSystem_LLT optSys_LLT);
	std::vector<OpticalSystem_LLT> findLensesInOptSysEle(OpticalSystemElement optSysEle);

	// compare two optical systems LLT
	bool compareTwoOpticalSystemsSurfaces(OpticalSystemElement optSysEle1, OpticalSystemElement optSysEle2, real tolerance);

	// get max start point 
	VectorStructR3 getMaxStartPoint(VectorStructR3 referencePoint, std::vector<VectorStructR3> startPointVec);

	// calculate faculty
	int calcFacultyInt(unsigned int value);

	// calculate all possible sequences int
	std::vector<std::vector<unsigned int>> calcAllPossibleSequencesInt(std::vector<unsigned int> vec);

	// check refractiv index 
	bool checkRefractivIndex(OpticalSystem_LLT optSyeLLT);
	bool checkRefractivIndex(OpticalSystemElement optSyeEle);

	// check if two optical systems are the same
	bool checkOpticalSystemsSameParameter(OpticalSystemElement optSysEle_1, OpticalSystemElement optSysEle_2);

	// get name location
	std::string getNameFolder(replaceSequence repSequence);
	// get name replace seq
	std::string getRepSequence_string(replaceSequence repSequence);
	// get name optimization methode
	std::string getNameOptimizationMetode(optimizeMethode optiMethode);

	// do the statistic evaluation left to right, right to left, max seidel, min seidel save intermediate results
	saveLRaO_GeneticAndDLS_12_statistic  doTheStatisticEvaluation_lensSystem_LTR_RTL_MaxSei_MinSei_obj_saveIntermediateResults(OpticalSystemElement optSysEle, std::vector<VectorStructR3> field_vec, std::vector<real> wavelength_vec, targetCardinalPointsStruct targetCarPoints, std::string location, std::string example, replaceSequence repSequence, optimizeMethode optiMethode, unsigned int numberBestFitLenses, bool debugMode, bool firstInteration);
	saveLRaO_GeneticAndDLS_12_statistic  doTheStatisticEvaluation_lensSystem_givenSequence_saveIntermediateResults(OpticalSystemElement optSysEle, std::vector<VectorStructR3> field_vec, std::vector<real> wavelength_vec, targetCardinalPointsStruct targetCarPoints, std::string location, std::string example, optimizeMethode optiMethode, unsigned int numberBestFitLenses, bool debugMode, bool firstInteration, std::vector<unsigned int> givenSequnce);
	
	// export data lens replace
	void exportDataReplace_THREE_LensesGeneticAndDLS_12(std::string location, std::string repSeq, saveLRaO_GeneticAndDLS_12_statistic dataToExport);
	void exportDataReplace_FOUR_LensesGeneticAndDLS_12(std::string location, std::string repSeq, saveLRaO_GeneticAndDLS_12_statistic dataToExport);

	// get camera parameter Vistec Eco655
	cameraParameterStruct getCamPara_VistecEco655();
	// get camera parameter Ximea
	cameraParameterStruct getCamPara_Ximea();

}
