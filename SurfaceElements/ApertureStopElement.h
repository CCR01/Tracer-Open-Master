#pragma once

#include "../LowLevelTracing/LLT_Package.h"
#include "../LowLevelTracing/Surfaces/ApertureStop_LLT.h"
#include "../LowLevelTracing/Interaction/RefractedRay_LLT.h"
#include "..\Parameter\parameter.h"
#include "..\Element\Element_CR.h"
#include <ctime>

class ApertureStopElement : public Element_CR

{
public:
	ApertureStopElement();
	std::shared_ptr<Element_CR> clone() override;
	ApertureStopElement& operator=(ApertureStopElement& source);
	ApertureStopElement(real /* semi height*/ semiHeight, VectorStructR3 /*point*/ point, VectorStructR3 /*direction*/ direction, real /*refractiv index*/ refractiveIndex);
	ApertureStopElement(real /* semi height*/ semiHeight, VectorStructR3 /*point*/ point, VectorStructR3 /*direction*/ direction, MaterialSellmeier1 /*glass*/ glass);
	virtual ~ApertureStopElement();
	ApertureStopElement(ApertureStopElement &source);

	real fRand(real fMin, real fMax);

	// build LLT version of the apertur stop element
	void buildSurface_LLT() override;

	//fix all parameter
	virtual void setAllParameterFix() override;

	// get pointer to surface LLT for ray tracing
	virtual std::shared_ptr<SurfaceIntersectionRay_LLT> getSurfaceForLLT_ptr() override;


	// set parameter of semi-height parameter
	void setSemiHeightParameter(real min, real max, real stdDev, typeModifier modi);

	// get position
	VectorStructR3 getPositionValueR3() const&;

	// get Direction
	VectorStructR3 getDirectionValueR3() const&;

	void setSemiHeightParaValue(real semiHeight);

	void setPointZ(real min, real max, real stdDev, typeModifier modi);

	// generate random parameter values for a element
	virtual std::shared_ptr<Element_CR> generate_ptr() override;

	// crossover function ~mixing two elements parameters
	virtual std::shared_ptr<Element_CR> crossover_ptr(std::shared_ptr<Element_CR> A, std::shared_ptr<Element_CR> B) override;

	virtual void print() override;

	//virtual void localOptimization_semiheight(real step) override;

	virtual void localOptimization_radius(real step) override;

	virtual void localOptimization_position(real step) override;

	virtual real getPointElementValue_Z() override;

	virtual real getDirectionElementValue_Z() override;

	virtual real getSemiHeightElementValue() override;

	virtual real minPosValue_Z() override;
	virtual real maxPosValue_Z() override;

	virtual void pushPosition(real push) override;

	// get direction type modifier
	virtual typeModifier getDirectionTypeModifier_Z() override;

	// get point type modifier
	virtual typeModifier getPointTypeModifier_Z() override;

	virtual real getRadiusElementValue() override;

	virtual typeModifier getRadiusTypeModifier() override;

	virtual  std::shared_ptr<Element_CR> getDeepCopyElement_ptr(std::shared_ptr<Element_CR> element) override;

	virtual void setRadiusElementValue(real Radius) override;

	virtual void setSemiHeightElementValue(real semiHeight) override;

	virtual void setParameterSemiHeight(real min, real max, real stdDev, typeModifier typeMode) override;
	virtual void setParameterRadius(real min, real max, real stdDev, typeModifier typeMode) override;

	virtual void setParameterDirectionX(real min, real max, real stdDev, typeModifier typeMode) override;
	virtual void setParameterDirectionY(real min, real max, real stdDev, typeModifier typeMode) override;
	virtual void setParameterDirectionZ(real min, real max, real stdDev, typeModifier typeMode) override;

	virtual void setDirectionX_value(real directionX) override;
	virtual void setDirectionY_value(real directionY) override;
	virtual void setDirectionZ_value(real directionZ) override;

	virtual void setParameterPointX(real min, real max, real stdDev, typeModifier typeMode) override;
	virtual void setParameterPointY(real min, real max, real stdDev, typeModifier typeMode) override;
	virtual void setParameterPointZ(real min, real max, real stdDev, typeModifier typeMode) override;

	virtual void setRefIndex_A_value(real refIndexA) override;
	virtual void setRefIndex_B_value(real refIndexB) override;

	virtual void setPointElementValue_X(real pointX) override;
	virtual void setPointElementValue_Y(real pointY) override;
	virtual void setPointElementValue_Z(real pointZ) override;

	virtual void setGlassA(MaterialSellmeier1 glassA) override;
	virtual void setGlassB(MaterialSellmeier1 glassB) override;


	// calculate refractive indexes side A and B
	void calRefIndex_A_and_B_andSet(real wavelenth) override;

	virtual Parameter<real> getParameterRadius() override;
	virtual Parameter<real> getParameterPositionZ() override;

	virtual real getRefIndexValue_A() override;
	virtual real getRefIndexValue_B() override;

	virtual MaterialSellmeier1 getGlassA() override;
	virtual MaterialSellmeier1 getGlassB() override;

	virtual std::shared_ptr<Element_CR> buildElement(std::shared_ptr<SurfaceIntersectionRay_LLT> surface_LLT, MaterialSellmeier1 glassA, MaterialSellmeier1 glassB) override;

	virtual std::string getSurfaceType() override;

private:

	std::shared_ptr<SurfaceIntersectionRay_LLT> mAperture_LLT;

	Parameter<real> mSemiHeightApertureElePara;

	Parameter<real> mRrefractiveIndex;

	Parameter<real> mPointParamX;
	Parameter<real> mPointParamY;
	Parameter<real> mPointParamZ;

	Parameter<real> mDirectionParamX;
	Parameter<real> mDirectionParamY;
	Parameter<real> mDirectionParamZ;

	MaterialSellmeier1 mGlass;

};

