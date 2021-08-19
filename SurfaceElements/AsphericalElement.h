#pragma once
#include "..\LowLevelTracing\LLT_Package.h"
#include "..\LowLevelTracing\Surfaces\AsphericalSurface_LLT.h"

#include "..\LowLevelTracing\Interaction\RefractedRay_LLT.h"
#include "..\Parameter\parameter.h"
#include "..\Element\Element_CR.h"


class AsphericalElement : public Element_CR
{
public:
	AsphericalElement();
	virtual ~AsphericalElement();
	AsphericalElement& operator=(AsphericalElement& source);
	std::shared_ptr<Element_CR> clone() override;
	AsphericalElement(AsphericalElement &source);
	AsphericalElement(real const& radius, real const& semiHeight, VectorStructR3 const& point, VectorStructR3 const& direction, real refractiveSideA, real refractiveSideB, real const& conic,
		/*higher order aspheric terms*/ real const& A1, real const& A2, real const& A3, real const& A4, real const& A5, real const& A6, real const& A7, real const& A8);
	AsphericalElement(real const& radius, real const& semiHeight, VectorStructR3 const& point, VectorStructR3 const& direction, MaterialSellmeier1 glassA, MaterialSellmeier1 glassB, real const& conic,
		/*higher order aspheric terms*/ real const& A1, real const& A2, real const& A3, real const& A4, real const& A5, real const& A6, real const& A7, real const& A8);


	real fRand(real min, real max);

	virtual void setAllParameterFix() override;

	virtual std::shared_ptr<SurfaceIntersectionRay_LLT> getSurfaceForLLT_ptr() override;

	// get the LLT package
	LLT_Package getLLT_Package(); //TODO: nullptr? Subelements -> Vector?

	// we need a low level System for ray tracing
	void buildSurface_LLT() override;


	virtual std::shared_ptr<Element_CR> generate_ptr() override;

	void setParameterRadiusValue(real radius);

	// set parameter of semi-height parameter
	void setSemiHeight(/*min*/ real min, /*max*/ real max, /*stdDev*/ real stdDev, /*modifier*/ typeModifier modi);

	void setSemiHeigtEleValue(real semiHeight);

	void setPointZ(real min, real max, real stdDev, typeModifier modi);

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

	virtual MaterialSellmeier1 getGlassA() override;
	virtual MaterialSellmeier1 getGlassB() override;

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

	/*Peter*/ virtual std::shared_ptr<Element_CR> buildElement(std::shared_ptr<SurfaceIntersectionRay_LLT> surface_LLT, MaterialSellmeier1 glassA, MaterialSellmeier1 glassB) override;

	virtual std::string getSurfaceType() override;

private:
	std::shared_ptr<SurfaceIntersectionRay_LLT> mAsphericalSurface_LLT;

	// TODO!!!
	// add LLT interaction --> have to be switchable
	RefractedRay_LLT mRefraction_LLT;

	Parameter<real>  mRadiusAsphereParam;
	Parameter<real>  mSemiHeightAsphereElePara;

	Parameter<real> mPointParamX;
	Parameter<real> mPointParamY;
	Parameter<real> mPointParamZ;

	Parameter<real> mDirectionParamX;
	Parameter<real> mDirectionParamY;
	Parameter<real> mDirectionParamZ;

	Parameter<real> mRefractiveSideA_AsphereParam;
	Parameter<real> mRefractiveSideB_AsphereParam;
	Parameter<real> mConic;
	Parameter<real> m_A1_Param;
	Parameter<real> m_A2_Param;
	Parameter<real> m_A3_Param;
	Parameter<real> m_A4_Param;
	Parameter<real> m_A5_Param;
	Parameter<real> m_A6_Param;
	Parameter<real> m_A7_Param;
	Parameter<real> m_A8_Param;

	MaterialSellmeier1 mGlassA;
	MaterialSellmeier1 mGlassB;
};