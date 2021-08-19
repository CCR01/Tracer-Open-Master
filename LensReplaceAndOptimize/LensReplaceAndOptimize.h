#pragma once

// Optical System Element
#include "..\OpticalSystemElement\OpticalSystemElement.h"
// Damped Least Squares
#include "..\OptimizeSystem\DampedLeastSquares.h"
// important optimization strucs
#include "..\OptimizeSystem\importantOptimizeStructs.h"
// lens replace
#include "..\lensReplace\LensReplace.h"
// Genetich and DLS
#include "..\OptimizeSystem\OptimizeSystemSuperFct_GeneticAndDLS.h"

enum class optimizeMethode{DLS, DLS_12, GeneticAndDLS, GeneticAndDLS_12};

class LensReplaceAndOptimize
{
public:
	LensReplaceAndOptimize();
	~LensReplaceAndOptimize();

	void lensReplaceAndOptimize_superFct(OpticalSystemElement optSysEle, std::vector<VectorStructR3> fieldPointsVec, std::vector<real> wavelength_vec, unsigned int rings, unsigned int arms, optimizeMethode optMethode, /*number best fit lenses*/ unsigned int numberBestFitLenses, bool firstInteration, replaceSequence repSequence, Light_LLT light);
	void lensReplaceAndOptimize(OpticalSystemElement optSysEle, std::vector<VectorStructR3> fieldPointsVec, std::vector<real> wavelength_vec, unsigned int rings, unsigned int arms, optimizeMethode optMethode, unsigned int numberLensToReplace, /*number best fit lenses*/ unsigned int numberBestFitLenses, bool firstInteration);
	
	void lensReplaceAndOpti_DLS(unsigned int numberLensToReplace, /*number best fit lenses*/ unsigned int numberBestFitLenses, bool firstInteration);
	void lensReplaceAndOpti_DLS_12(unsigned int numberLensToReplace, /*number best fit lenses*/ unsigned int numberBestFitLenses, bool firstInteration);
	void lensReplaceAndOpti_GeneticAndDLS(unsigned int numberLensToReplace, /*number best fit lenses*/ unsigned int numberBestFitLenses, bool firstInteration);
	void lensReplaceAndOpti_GeneticAndDLS_12(unsigned int numberLensToReplace, /*number best fit lenses*/ unsigned int numberBestFitLenses, bool firstInteration);

	// carindal points
	void setTargetCardinalPoints(targetCardinalPointsStruct tarCarPoints);
	targetCardinalPointsStruct getTargetCardinalPoints();
	// ***

	// DLS
	void setDefaulParaDLS(defaultParaDLS deParaDLS);
	defaultParaDLS getDefaulParaDLS();
	// ***
	
	// Genetic
	void setDefaultParaGenetic(defaultParaGenetic deParaGenetic);
	defaultParaGenetic getDefaultParaGenetic();
	void setPopulation(unsigned int population);
	unsigned int getPopulation();
	// ***

	void setLoadLensCatalogs(std::vector<lensTypes> lensCataVec);
	void saveBestReplacedOpticalSystem();
	std::vector<OptSysEle_Merit_LensType> flipOptSysEleBy180Degrees(std::vector < OptSysEle_Merit_LensType> initialBestOptSysReplace);
	OpticalSystemElement getBestReplacedOpticalSystem();

	// save best parameter cataloge lens for replace
	void saveBestParameterCatalogLensForReplace(unsigned int numberLensToReplace);
	// print best parameter catalog lens for replace
	void printBestParameterCatalogForReplace();
	// export best parameter catalog for replace
	void exportBestParameterCatalogForReplaceTXT(std::string locationTXT, std::string nameTXT);
	// find best replace optical system
	void findBestReplaceOpticalSystem();
	// get replaced sequence
	std::vector<int> getReplacedSequence();
	// get best catalog lenese for replace
	std::vector<OptSysEle_Merit_LensType> getBestCatalogLensesForreplace();
	// load sequence
	void loadSequence(std::vector<unsigned int> sequence);
	// debug mode
	void turn_ON_DebugMode();
	void turn_OFF_DebugMode();

private:
	std::vector<lensTypes> mLoadLensCatalogEO_vec;
	std::vector<OpticalSystemElement> mReplaceOpticalSysEle{};
	std::vector<OpticalSystemElement> mReplaceOpticalSysEle_opti{};
	std::vector<real> mReplaceMeritVal_opti{};
	OpticalSystemElement mBestReplacedOptSysEle{};

	OpticalSystemElement mInitalOpticalSystemEle_SuperFct{};
	OpticalSystemElement mInitalOpticalSystemEle_LensReplaceAndOptimize{};
	
	OpticalSystemElement mOptimizedOpticalSystemEle{};
	std::vector<VectorStructR3> mFieldPointsVec{};
	std::vector<real> mWavelength_vec{};
	unsigned int mRings{};
	unsigned int mArms{};

	targetCardinalPointsStruct mTargetCardinalPoints{};
	defaultParaDLS mDefaulParaDLS{};
	defaultParaGenetic mDefaultParaGenetic{};
	unsigned int mPopulation{};

	unsigned int mPosBestMeritVal{};
	std::vector<OptSysEle_Merit_LensType> mBestLensToReplace_vec{};
	std::vector<OptSysEle_Merit_LensType> mBestLensToReplace_vec_includingFlipedLenses{};
	std::vector<OptSysEle_Merit_LensType> mBestCatalogLensesForReplace{};
	std::vector<unsigned int> mLoadSequence{};
	real mBestMeritVal{};

	std::vector<std::vector<OptSysEle_Merit_LensType>> mSaveAllBestLensToReplace_vec_includingFlipedLenses{};
	std::vector<OpticalSystemElement> mSaveAllBestReplacedOpticalSystem{};
	std::vector<real> mSaveAllBestMeritVal{};
	std::vector<int> mSaveReplacedSequence{};
	std::vector<std::vector<int>> mAllPossibleSequencesInt{};

	bool mDebugMode{};
};

