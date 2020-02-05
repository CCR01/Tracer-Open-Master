#pragma once

#include "..\OpticalSystemElement\OpticalSystemElement.h"




enum buildWhat { buildLLT, buildElement, buildLLT_and_Element };

class BuildSystemsForCombination
{
public:
	BuildSystemsForCombination();
	BuildSystemsForCombination(OpticalSystemElement optSysEle, std::vector<stepsWithoutMinWithoutMax> addInfosVariable, real primWavelength, buildWhat build);
	~BuildSystemsForCombination();

	void superFct(OpticalSystemElement optSysEle, std::vector<stepsWithoutMinWithoutMax> addInfosVariable, real primWavelength, buildWhat build);

	void saveParaAndVariable();
	void buildVectorPossibilitiesVar();
	void buildVectorForPossibleOpticalSystem_LLT();
	void buildVectorForPossibleOpticalSystem_Element();

	void checkForVariableSurfaces();

	void buildOpticalSystemCombination_superFkt_LLT();
	void buildOpticalSystemCombination_superFkt_Element();

	void buildOpticalSystemCombination_2Surfaces_LLT();
	void buildOpticalSystemCombination_2Surfaces_Element();
	void buildOpticalSystemCombination_3Surfaces_LLT();
	void buildOpticalSystemCombination_3Surfaces_Element();
	void buildOpticalSystemCombination_4Surfaces_LLT();
	void buildOpticalSystemCombination_4Surfaces_Element();
	void buildOpticalSystemCombination_5Surfaces_LLT();
	void buildOpticalSystemCombination_5Surfaces_Element();
	void buildOpticalSystemCombination_6Surfaces_LLT();
	void buildOpticalSystemCombination_6Surfaces_Element();
	void buildOpticalSystemCombination_7Surfaces_LLT();
	void buildOpticalSystemCombination_7Surfaces_Element();
	void buildOpticalSystemCombination_8Surfaces_LLT();
	void buildOpticalSystemCombination_8Surfaces_Element();
	void buildOpticalSystemCombination_9Surfaces_LLT();
	void buildOpticalSystemCombination_9Surfaces_Element();
	void buildOpticalSystemCombination_10Surfaces_LLT();
	void buildOpticalSystemCombination_10Surfaces_Element();
	void buildOpticalSystemCombination_11Surfaces_LLT();
	void buildOpticalSystemCombination_11Surfaces_Element();
	void buildOpticalSystemCombination_12Surfaces_LLT();
	void buildOpticalSystemCombination_12Surfaces_Element();
	void buildOpticalSystemCombination_13Surfaces_LLT();
	void buildOpticalSystemCombination_13Surfaces_Element();
	void buildOpticalSystemCombination_14Surfaces_LLT();
	void buildOpticalSystemCombination_14Surfaces_Element();
	void buildOpticalSystemCombination_15Surfaces_LLT();
	void buildOpticalSystemCombination_15Surfaces_Element();
	void buildOpticalSystemCombination_16Surfaces_LLT();
	void buildOpticalSystemCombination_16Surfaces_Element();
	void buildOpticalSystemCombination_17Surfaces_LLT();
	void buildOpticalSystemCombination_17Surfaces_Element();
	void buildOpticalSystemCombination_18Surfaces_LLT();
	void buildOpticalSystemCombination_18Surfaces_Element();
	void buildOpticalSystemCombination_19Surfaces_LLT();
	void buildOpticalSystemCombination_19Surfaces_Element();
	void buildOpticalSystemCombination_20Surfaces_LLT();
	void buildOpticalSystemCombination_20Surfaces_Element();


	//std::vector<std::shared_ptr<SurfaceIntersectionRay_LLT>> combinateVaribaleRadiusAndDistance(std::shared_ptr<SurfaceIntersectionRay_LLT> surface, std::vector<real> radius_vec, std::vector<real> positon_vec);

	void saveDistances();
	void setAllDistances_LLT();
	void setAllDistances_Element();

	void setRefractiveIndexesAccordingToPrimWavelength();

	void checkIfOnePositionIsVariable();
	void saveVariableSurfaceNum();

	bool checkDistances();
	bool checkInteractions();
	bool checkCombinations_LLT(unsigned int expectedVectorSize, std::vector<unsigned int> expectedCombination_vec);
	bool checkCombination_Element(unsigned int expectedVectorSize, std::vector<unsigned int> expectedCombination_vec);
	bool checkCombiRadiusPosAtSurface_n(unsigned int surfaceNum, std::vector<real> radius_vec, std::vector<real> pos_vec, real tolerance);
	bool checkCombiRadiusAtSurface(unsigned int surfaceNum, std::vector<real> radius_vec, real tolerance);
	bool checkCombiPosAtSurface(unsigned int surfaceNum, std::vector<real> pos_vec, real tolerance);

	// get all possible optical systems LLT
	std::vector<OpticalSystem_LLT> getAllPosOptSys_LLT();

	// get all possible optilca system element
	std::vector<OpticalSystemElement> getAllPosOptSys_Element();

	void clearAll();

private:

	real mPrimWavelength;

	std::vector<parameterTypeModeStruct> mParamVariableStructVec;
	OpticalSystemElement mOptSysEle;
	std::vector<stepsWithoutMinWithoutMax> mAddInfosVar;
	std::vector<std::vector<real>> mPossibilitiesVariables;

	unsigned int variableSurfaces;
	std::vector<unsigned int> mVariableSurfaceNum;

	std::vector<std::vector<std::shared_ptr<SurfaceIntersectionRay_LLT>>> mVector_vectorWithSurfacePointer_LLT;
	std::vector<std::vector<std::shared_ptr<Element_CR>>> mVector_vectorWithSurfacePointer_Element;

	std::vector<OpticalSystem_LLT> mPossibleOpticalSystem_LLT;
	std::vector<OpticalSystemElement> mPossibleOpticalSys_Element;

	std::vector<real> mSaveDistances;

	bool isOnePositionVariable;
	buildWhat mBuildWhat;

};



