#pragma once
#include "../LowLevelTracing/LLT_Package.h"
#include "../LowLevelTracing/Surfaces\SphericalSurface_LLT.h"

#include "..\LowLevelTracing\Interaction\RefractedRay_LLT.h"
#include "..\Parameter\parameter.h"
#include "..\Element\Element_CR.h"



class SphericalElement : public Element_CR
{
public:

	SphericalElement();
	SphericalElement(SphericalElement &source);
	SphericalElement& operator=(SphericalElement& source);
	SphericalElement(real /*radius*/ radius, real /*semi height*/  semiHeight, VectorStructR3 /*point*/ point, VectorStructR3 /*direction*/ direction, real /*refractive index A*/ refractiveSideA, real /*refractive index B*/refractiveSideB);
	SphericalElement(real /*radius*/ radius, real /*semi height*/  semiHeight, VectorStructR3 /*point*/ point, VectorStructR3 /*direction*/ direction, MaterialSellmeier1 /*glass A*/ glassA, MaterialSellmeier1 /*glass B*/glassB);
	virtual ~SphericalElement() override;
	std::shared_ptr<Element_CR> clone() override;
	// make all parameter of the sphere fix
	virtual void setAllParameterFix() override;

	// get a random value between two values
	real fRand_real(real min, real max);

	// get pointer to surface LLT for ray tracing
	virtual std::shared_ptr<SurfaceIntersectionRay_LLT> getSurfaceForLLT_ptr() override;

	// we need a low level System for ray tracing
	void buildSurface_LLT() override;

	// set parameter of semi-height parameter
	void setSemiHeight(/*min*/ real min, /*max*/ real max, /*stdDev*/ real stdDev, /*modifier*/ typeModifier modi);

	// generate random parameter values for a element
	virtual std::shared_ptr<Element_CR> generate_ptr() override;

	// crossover function mixing two elements parameters
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

	virtual MaterialSellmeier1 getGlassA() override;
	virtual MaterialSellmeier1 getGlassB() override;

	// set radiu value
	void setRadiusValue(real const& Radius);
	// get radius value 
	real getRadiusValue() const&;
	// set semi height value
	void setSemiHeightValue(real const& semiHeight);
	// get semi height value
	real getSemiHeightValue() const&;
	// set origin value
	void setOriginValue(VectorStructR3 const& originValue);
	// get origin value
	VectorStructR3 getOriginValue() const&;
	// set direction value
	void setDirectionValue(VectorStructR3 const& directionValue);
	// get direction value
	VectorStructR3 getDirectionValue() const&;
	//set refracive index value A
	void setRefIndexValue_A(real const& refIndex);
	//set refractive index value B
	void setRefIndexValue_B(real const& refIndex);


	// calculate refractive index side A
	void calcRefIndex_A_andSet(real wavelength);
	// calculate rearactive index side B
	void calcRefIndex_B_andSet(real wavelength);
	// calculate refractive indexes side A and B
	void calRefIndex_A_and_B_andSet(real wavelength) override;

	virtual Parameter<real> getParameterRadius() override;
	virtual Parameter<real> getParameterPositionZ() override;

	virtual real getRefIndexValue_A() override;
	virtual real getRefIndexValue_B() override;

	virtual std::shared_ptr<Element_CR> buildElement(std::shared_ptr<SurfaceIntersectionRay_LLT> surface_LLT, MaterialSellmeier1 glassA, MaterialSellmeier1 glassB) override;

private:

	std::shared_ptr<SurfaceIntersectionRay_LLT> mSphericalSurface_LLT;

	Parameter<real> mRadiusParam;
	Parameter<real> mSemiHeightElePara;

	Parameter<real> mPointParamX;
	Parameter<real> mPointParamY;
	Parameter<real> mPointParamZ;

	Parameter<real> mDirectionParamX;
	Parameter<real> mDirectionParamY;
	Parameter<real> mDirectionParamZ;

	Parameter<real> mRefractiveiSideA_Param;
	Parameter<real> mRefractiveSideB_Param;

	MaterialSellmeier1 mGlassA;
	MaterialSellmeier1 mGlassB;




};