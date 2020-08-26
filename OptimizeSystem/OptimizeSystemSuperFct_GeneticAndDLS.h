#pragma once

//#include "..\OpticalSystemElement\OpticalSystemElement.h"
#include "..\OptimizeSystem\Genetic.h"
#include "..\OptimizeSystem\DampedLeastSquares.h"

class OptimizeSystemSuperFct_GeneticAndDLS
{
public:
	OptimizeSystemSuperFct_GeneticAndDLS();
	// obj
	OptimizeSystemSuperFct_GeneticAndDLS(OpticalSystemElement /*optSysEle*/ optSysEle, std::vector<VectorStructR3> /*fields*/ fields, std::vector<real> /*wavelengths*/ wavelengths, unsigned int /*rings*/ rings, unsigned int /*arms*/ arms, unsigned int /*populatuion*/ population, defaultParaGenetic defaultGenetic, defaultParaDLS defaultDLS);
	OptimizeSystemSuperFct_GeneticAndDLS(OpticalSystemElement /*optSysEle*/ optSysEle, std::vector<VectorStructR3> /*fields*/ fields, std::vector<real> /*wavelengths*/ wavelengths, unsigned int /*rings*/ rings, unsigned int /*arms*/ arms, unsigned int /*populatuion*/ population, targetCardinalPointsStruct targetCarPoints, defaultParaGenetic defaultGenetic, defaultParaDLS defaultDLS);
	// inf
	OptimizeSystemSuperFct_GeneticAndDLS(OpticalSystemElement /*optSysEle*/ optSysEle, std::vector<real> /*angleX*/ angleX, std::vector<real> /*angleY*/ angleY, std::vector<real> /*wavelengths*/ wavelengths, unsigned int /*rings*/ rings, unsigned int /*arms*/ arms, unsigned int /*populatuion*/ population, targetCardinalPointsStruct targetCarPoints, defaultParaGenetic defaultGenetic, defaultParaDLS defaultDLS);
	~OptimizeSystemSuperFct_GeneticAndDLS(); 

	// parallel the optimisation including genetic and DLS on 12 cores

	OpticalSystemElement optimizeSuperFct_GeneticAndDLS_12Cores();
	OpticalSystemElement optimizeSuperFct_GeneticAndDLS_12Cores_obj();
	OpticalSystemElement optimizeSuperFct_GeneticAndDLS_12Cores_inf();

	// get optimized optical system
	OpticalSystemElement getOptimizedOpticalSystem();
	// get object point inf or obj
	objectPoint_inf_obj getObjPoint_inf_obj();

	void loadBestFactorBetterFactorWorstCombinations();

private:
	OpticalSystemElement mOptSysEle{};
	std::vector<VectorStructR3> mFields_vec{};
	std::vector<real> mAngleX{};
	std::vector<real> mAngleY{};
	std::vector<real> mWavelength_vec{};
	unsigned int mRings{};
	unsigned int mArms{};
	unsigned int mPopulation{};

	defaultParaGenetic mDefaultParameterGenetic{};
	defaultParaDLS mDefaultPrameterDLS{};

	real mFactorBetter_1{};
	real mFactorWorst_1{};
	real mFactorBetter_2{};
	real mFactorWorst_2{};

	OpticalSystemElement mOptimizedOpticalSystemElement_firstIteration{};
	OpticalSystemElement mOptimizedOpticalSystemElement_secondIteration{};
	std::vector<real> mAllMeritVal_vec{};
	real mBestMeritVal{};

	std::vector<real> factorBetter_vec{};
	std::vector<real> factorWorst_vec{};
	
	targetCardinalPointsStruct mTargetCarPoints{};

	objectPoint_inf_obj mObjPoint_inf_obj;

};

