#pragma once
#include "..\Element/Element_CR.h"
#include <vector>
#include "..\LowLevelTracing\Interaction\InteractionRay_LLT.h"
#include "..\LowLevelTracing\OpticalSystem_LLT.h"
//#include "para"

//#include "D:\Tarik\traceopen-master\SurfaceElements\PlanElement.h"
//#include "D:\Tarik\traceopen-master\SurfaceElements\SphericalElement.h"

enum kindOfParameter { radius, position };
enum parameterVariable { only_radius_var, only_position_var, radiusAndPosition_var, radiusAndPosFix };

struct stepsWithoutMinWithoutMax
{
public:
	stepsWithoutMinWithoutMax();
	stepsWithoutMinWithoutMax(unsigned int surfaceNum, real steps, real withoutMin, real withoutMax);
	~stepsWithoutMinWithoutMax();

	//get surface num
	unsigned int getSurfaceNum() const&;
	//set surface num
	void setSurfaceNum(unsigned int const& surfaceNum);
	//get steps
	real getSteps() const&;
	//set steps
	void setSteps(real const& steps);
	//get without min
	real getWithoutMin() const&;
	//set without min 
	void setWithoutMin(real const& withoutMin);
	//get without max
	real getWithoutMax() const&;
	//set without max
	void setWithoutMax(real const& withoutMax);

private:
	unsigned int mSurfaceNum;
	real mSteps;
	real mWithoutMin;
	real mWithoutMax;

};

struct parameterTypeModeStruct
{
public:
	parameterTypeModeStruct();
	parameterTypeModeStruct(unsigned int surNum, kindOfParameter kindParam, typeModifier typeMode);
	~parameterTypeModeStruct();

	unsigned int getSurfaceNum() const&;
	void setSurfaceNum(unsigned int const& surfaceNum);

	kindOfParameter getKindParam() const&;
	void setKindParam(kindOfParameter const& kindParam);

	typeModifier getTypeMode() const&;
	void setTypeMode(typeModifier const& typeMode);

	parameterVariable getParameterVariable();
	void setParameterVaiable(parameterVariable paraVar);

private:
	unsigned int mSurfaceNumber;
	kindOfParameter mKindParam;
	typeModifier mTypeMode;
	parameterVariable mParamVariable;
};

struct PositionAndElementStruct
{

public:
	PositionAndElementStruct();
	~PositionAndElementStruct();

	// set position of element in optical system
	void setPosition(unsigned int pos);
	// get position of element in optical system
	unsigned int getPosition();
	// set element in optical system
	void setElementInOptSys_ptr(std::shared_ptr<Element_CR> setElement);
	// get element in optical system
	std::shared_ptr<Element_CR> getElementInOptSys_ptr();

private:
	unsigned int position;
	std::shared_ptr<Element_CR> element;
};

class OpticalSystemElement
{
public:

	OpticalSystemElement();
	~OpticalSystemElement();

	// here we take an std::vec  with pointer so the surfaces
	// we build the optical system with the default interaction "refraction" 
	OpticalSystemElement(std::vector<std::shared_ptr<Element_CR>> elements_ptr, std::vector<std::shared_ptr<InteractionRay_LLT>> interaction_ptr);

	

	// fill the optical system with elements
	void fillPosAndElementAndInteraction(unsigned int position, std::shared_ptr<Element_CR> element, std::shared_ptr<InteractionRay_LLT> interaction);
	void fillPosAndElementAndInteraction(std::vector<std::shared_ptr<Element_CR>> elements, std::vector<std::shared_ptr<InteractionRay_LLT>> interactions);

	// get the size of the optical system
	unsigned int getSizeOptSys();

	PositionAndElementStruct crossPosElement(int a);

	void setRefractiveIndexAccordingToWavelength(real wavelenght);

	// convert HLT to LLT
	void convertHLTtoLLT();
	void convertHLTSurfacesToLLTSurfaces();

	// get pos and interaction LLT
	std::vector<PosAndInteractionStruct> getPosAndInteraction_LLT();

	// get pos and intersection
	std::vector<PosAndIntsectionSurfaceStruct> getPosAndIntersection_LLT();

	//// get position and element
	std::vector<PositionAndElementStruct> getPosAndElement();

	//printing values
	void printValues();

	//position of the element
	//void generateELementPosition();
	void setLength(real len);
	real getLength();

	// get LLT convertion
	OpticalSystem_LLT getLLTconversion_doConversion();

	// get LLT opt sys
	OpticalSystem_LLT getOpticalSystem_LLT();

	// clear mPosAndInteraction_LLT
	void clear_mPosAndInteraction_LLT();

	// clear mPosAndIntersecSurface_LLT
	void clear_mPosAndIntersecSurface_LLT();

	// clear all
	void clearALL();

	// get deep copy of the optical system element
	OpticalSystemElement getDeepCopyOptSysEle();

	// get optical system element
	OpticalSystemElement getOpticalSystemElement();

	void cleanSurfaceAndInteractionStartAt_i(unsigned int aimSize);

	// reverste optical system
	OpticalSystemElement reverseOptSysEle(OpticalSystemElement optSysEle);

	// fill in Element at position i
	void fillInElementAndInteractionAtPos_i(unsigned int pos, std::shared_ptr<Element_CR> element_prt, std::shared_ptr<InteractionRay_LLT> interaction);

	// fill pos and element
	void fillPosAndElement(unsigned int position, std::shared_ptr<Element_CR> element);

	// get relavant infos about the aperture stop
	infosAS getInfoAS();

	unsigned int getPosApertureStop();

	void convertSurfacesToLLT();
	OpticalSystem_LLT getOptSys_LLT_buildSystem();
	OpticalSystemElement convertOptSys_LLT_T0_OptSys_HLT(OpticalSystemElement optSys_Ele, OpticalSystem_LLT optSys_LLT);
	OpticalSystemElement convertOptSys_LLT_T0_OptSys_HLT(OpticalSystemElement optSys_Ele, OpticalSystem_LLT optSys_LLT, std::vector<parameterTypeModeStruct> parameter, std::vector< stepsWithoutMinWithoutMax> stepsWitoutMinMax);
	OpticalSystemElement setRefractivIndexAccWave(OpticalSystemElement optSysEle, real wavelength);
	std::vector<OpticalSystemElement> setRefractivIndexOptSysEle(std::vector<OpticalSystemElement> optSysEleVec, real waveLength);
	void setNewElement_vec(std::vector<std::shared_ptr<Element_CR>> elements_ptr);
	void delSurfaceNumber_from_TO(int startSurfaceNo, int endSurfaceNo);

protected:
	std::vector<PositionAndElementStruct> mPosAndElement;
	std::vector<PosAndInteractionStruct> mPosAndInteraction_LLT;
	std::vector<PosAndIntsectionSurfaceStruct> mPosAndIntersecSurface_LLT;
	OpticalSystem_LLT mOpticalSystem_LLT;
	unsigned int mSizeOptSys;

	Parameter<real> lengthOpticalSystem;
	//Parameter<real> elementPosition;

};
