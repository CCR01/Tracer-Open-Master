#pragma once
#include "..\LowLevelTracing\SurfaceIntersectionRay_LLT.h"
#include "..\Parameter\parameter.h"
#include <memory>

#include "..\Glasses\GlassDispersionFormulas\MaterialSellmeier1.h"

class Element_CR {
public:
	Element_CR() {};

	virtual std::shared_ptr<Element_CR> clone() = 0;  // your clone() function should be virtual too.
	virtual ~Element_CR() {};  // virtual destructor.
	//Element_CR(Element_CR & source);

	//virtual void buildSurfaceForRT() = 0; // TODO Ques Sergej: Ergibt das Sinn?
	/*template <class Surface>
	virtual Surface getSurfaceForLLT() ; // TODO Ques Sergej: Ergibt das Sinn?*/
	// TODO Ques Sergej: Welche Methoden sollten hier noch rein?

	virtual std::shared_ptr<SurfaceIntersectionRay_LLT> getSurfaceForLLT_ptr() = 0;

	virtual std::shared_ptr<Element_CR> generate_ptr() = 0;

	virtual std::shared_ptr<Element_CR> crossover_ptr(std::shared_ptr<Element_CR> A, std::shared_ptr<Element_CR>) = 0;

	//virtual Element_CR* crossover_ptr(Element_CR* A, Element_CR* B) = 0;

	virtual void calRefIndex_A_and_B_andSet(real wavelength) = 0;

	virtual void pushPosition(real push) = 0;

	virtual real getPointElementValue_Z() = 0;

	virtual real getDirectionElementValue_Z() = 0;

	virtual real getRadiusElementValue() = 0;

	virtual void setRadiusElementValue(real Radius) = 0;

	virtual typeModifier getRadiusTypeModifier() = 0;

	virtual real getSemiHeightElementValue() = 0;

	virtual void setSemiHeightElementValue(real semiHeight) = 0;

	virtual void print() = 0;

	//virtual void localOptimization_semiheight(real step) = 0;

	virtual void localOptimization_radius(real step) = 0;

	virtual void localOptimization_position(real step) = 0;

	virtual real minPosValue_Z() = 0;
	virtual real maxPosValue_Z() = 0;

	virtual void buildSurface_LLT() = 0;

	virtual typeModifier getDirectionTypeModifier_Z() = 0;

	virtual typeModifier getPointTypeModifier_Z() = 0;

	virtual  std::shared_ptr<Element_CR> getDeepCopyElement_ptr(std::shared_ptr<Element_CR> element) = 0;

	virtual void setParameterSemiHeight(real min, real max, real stdDev, typeModifier typeMode) = 0;
	virtual void setParameterRadius(real min, real max, real stdDev, typeModifier typeMode) = 0;
	virtual Parameter<real> getParameterRadius() = 0;

	virtual void setParameterDirectionX(real min, real max, real stdDev, typeModifier typeMode) = 0;
	virtual void setParameterDirectionY(real min, real max, real stdDev, typeModifier typeMode) = 0;
	virtual void setParameterDirectionZ(real min, real max, real stdDev, typeModifier typeMode) = 0;

	virtual void setDirectionX_value(real directionX) = 0;
	virtual void setDirectionY_value(real directionY) = 0;
	virtual void setDirectionZ_value(real directionZ) = 0;

	virtual void setParameterPointX(real min, real max, real stdDev, typeModifier typeMode) = 0;
	virtual void setParameterPointY(real min, real max, real stdDev, typeModifier typeMode) = 0;
	virtual void setParameterPointZ(real min, real max, real stdDev, typeModifier typeMode) = 0;
	virtual Parameter<real> getParameterPositionZ() = 0;

	virtual void setPointElementValue_X(real pointX) = 0;
	virtual void setPointElementValue_Y(real pointY) = 0;
	virtual void setPointElementValue_Z(real pointZ) = 0;

	virtual void setRefIndex_A_value(real refIndexA) = 0;
	virtual void setRefIndex_B_value(real refIndexB) = 0;

	virtual real getRefIndexValue_A() = 0;
	virtual real getRefIndexValue_B() = 0;

	virtual void setGlassA(MaterialSellmeier1 glassA) = 0;
	virtual MaterialSellmeier1 getGlassA() = 0;
	virtual void setGlassB(MaterialSellmeier1 glassB) = 0;
	virtual MaterialSellmeier1 getGlassB() = 0;

	virtual void setAllParameterFix() = 0;
	virtual std::shared_ptr<Element_CR> buildElement(std::shared_ptr<SurfaceIntersectionRay_LLT> surface_LLT, MaterialSellmeier1 glassA, MaterialSellmeier1 glassB) = 0;

private:

	VectorStructR3 mPosition;


};

/*

void swap(Element& element);                   ///< swap operation
Element& operator=(Element& element);          ///< assignment OP

virtual Element* copy(bool deep = true);       ///< creates and copies
virtual void show();				 ///< just for debugging purposes


void setPosition(real x, real y, real z);  ///< Position relativ to ParentElement
Point* getPosition();                      ///< get the Posiiton of the element

// TODO: add fourth angle parameter: rotation around orientation direction,
// plus rotation direction (default is counter-clock-wise rotation along direction) ?
void setOrientation(real alpha, real beta, real gamma);  ///< orientation relativ to Par
Direction* getOrientation();               ///< get the Posiiton of the surface

// TODO: this is not correct for all combinations of arbitrary elements. delete?
void addSubElement(Element* const e,  Material* const m);

int getCntSubElements() {return mSubElements.size();}
Element* getElement(int nr);               ///< get subElement nr

// TODO: move to 'lense elements'? not all 'elements' have this?
// we want this for the optimizer at some point,
// but this is not crucial (entscheidend) for the functioning of the optical system itself?
// abstract away into an optional package or something like that?
void setWeight(real weight);		     ///< set the weight in g
real getWeight();		             ///< get the weight in g
void setPrice(real price);		     ///< set the price in Euro
real getPrice();		             ///< get the price in Euro


void setMaterials(Material* left, Material* right); ///< set the materials
Material* getMaterialLeft();			 ///< get the left material
Material* getMaterialRight();			 ///< get the right material

*/