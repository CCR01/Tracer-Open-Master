#include "PlanElement.h"
#include <iomanip>   

PlanElement::PlanElement() {};
PlanElement::~PlanElement() {};
PlanElement::PlanElement(double semiHeight, VectorStructR3 point, VectorStructR3 direction, double refractiveSideA, double refractiveSideB)
{

	mSemiHeightPlanEleParam.set(semiHeight);

	mRadiusPlanEleParam.set(999999.0);

	mPointParamX.set(point.getX());
	mPointParamY.set(point.getY());
	mPointParamZ.set(point.getZ());

	mDirectionParamX.set(direction.getX());
	mDirectionParamY.set(direction.getY());
	mDirectionParamZ.set(direction.getZ());



	mRefractiveIndexA_PlanParam.set(refractiveSideA);
	mRefractiveIndexB_PlanParam.set(refractiveSideB);

	buildSurface_LLT();
	setAllParameterFix();
};

PlanElement::PlanElement(double /*semi height*/ semiHeight, VectorStructR3 /*point*/ point, VectorStructR3 /*direction*/ direction, MaterialSellmeier1 /*glass sinde A*/ glassA, MaterialSellmeier1 /*glass side B*/ glassB)
{
	mSemiHeightPlanEleParam.set(semiHeight);
	mRadiusPlanEleParam.set(999999.0);

	mPointParamX.set(point.getX());
	mPointParamY.set(point.getY());
	mPointParamZ.set(point.getZ());

	mDirectionParamX.set(direction.getX());
	mDirectionParamY.set(direction.getY());
	mDirectionParamZ.set(direction.getZ());



	mRefractiveIndexA_PlanParam.set(999);
	mRefractiveIndexB_PlanParam.set(999);

	mGlassA = glassA;
	mGlassB = glassB;

	buildSurface_LLT();
	setAllParameterFix();
}


void PlanElement::setAllParameterFix()
{

	mSemiHeightPlanEleParam.setModifier(typeModifierFixed);
	mRadiusPlanEleParam.setModifier(typeModifierFixed);

	mRefractiveIndexA_PlanParam.setModifier(typeModifierFixed);
	mRefractiveIndexB_PlanParam.setModifier(typeModifierFixed);

	mPointParamX.setModifier(typeModifierFixed);
	mPointParamY.setModifier(typeModifierFixed);
	mPointParamZ.setModifier(typeModifierFixed);

	mDirectionParamX.setModifier(typeModifierFixed);
	mDirectionParamY.setModifier(typeModifierFixed);
	mDirectionParamZ.setModifier(typeModifierFixed);

}


real PlanElement::getSemiHeightElementValue()
{
	return mSemiHeightPlanEleParam.getValue();
}

// we need a low level System for ray tracing
void PlanElement::buildSurface_LLT()
{
	PlanGeometry_LLT planGeo_LLT;

	planGeo_LLT.setSemiHeight(mSemiHeightPlanEleParam.getValue());

	VectorStructR3 pointR3{ mPointParamX.getValue(),mPointParamY.getValue(), mPointParamZ.getValue() };
	planGeo_LLT.setPoint(pointR3);

	VectorStructR3 directionR3{ mDirectionParamX.getValue(), mDirectionParamY.getValue(), mDirectionParamZ.getValue() };
	planGeo_LLT.setDirection(directionR3);

	planGeo_LLT.setRefractiveIndexSide_A(mRefractiveIndexA_PlanParam.getValue());
	planGeo_LLT.setRefractiveIndexSide_B(mRefractiveIndexB_PlanParam.getValue());

	mPlanGeometry_LLT = planGeo_LLT.clone();

}

//mSemiHeightPlanParam
void PlanElement::setSemiHeightPlanParameter(/*min*/ real min, /*max*/ real max, /*stdDev*/ real stdDev, /*modifier*/ typeModifier modi)
{
	mSemiHeightPlanEleParam.setMinimum(min);
	mSemiHeightPlanEleParam.setMaximum(max);
	mSemiHeightPlanEleParam.setStdDev(stdDev);
	mSemiHeightPlanEleParam.setModifier(modi);
}

void PlanElement::setSemiHeitPlanParaValue(real semiHeight)
{
	mSemiHeightPlanEleParam.set(semiHeight);
}



void PlanElement::setParameterPointZ(real min, real max, real stdDev, typeModifier modi)
{
	mPointParamZ.setMinimum(min);
	mPointParamZ.setMaximum(max);
	mPointParamZ.setStdDev(stdDev);
	mPointParamZ.setModifier(modi);
}

// get pointer to surface LLT for ray tracing
std::shared_ptr<SurfaceIntersectionRay_LLT> PlanElement::getSurfaceForLLT_ptr()
{
	return mPlanGeometry_LLT;
}


real PlanElement::fRand(real min, real max) {


	real f = (real)rand() / RAND_MAX;

	return min + f * (max - min);
}


//#tarik# generate random parameter values for the plan-elements from the optical system of elements.
std::shared_ptr<Element_CR> PlanElement::generate_ptr()
{

	std::shared_ptr<Element_CR> modPlanElement(new PlanElement);

	//getting the semiheight value for the plan element
	modPlanElement->setSemiHeightElementValue(mSemiHeightPlanEleParam.getValue());

	//getting the direction parameters for the plane
	modPlanElement->setDirectionX_value(mDirectionParamX.getValue());
	modPlanElement->setDirectionY_value(mDirectionParamY.getValue());
	modPlanElement->setDirectionZ_value(mDirectionParamZ.getValue());

	modPlanElement->setGlassA(mGlassA);
	modPlanElement->setGlassB(mGlassB);

	//getting the point parameters for the plane
	modPlanElement->setPointElementValue_X(mPointParamX.getValue());
	modPlanElement->setPointElementValue_Y(mPointParamY.getValue());
	modPlanElement->setPointElementValue_Z(mPointParamZ.getValue());

	//getting the refractive index into the plane element
	modPlanElement->setRefIndex_A_value(mRefractiveIndexA_PlanParam.getValue());
	modPlanElement->setRefIndex_B_value(mRefractiveIndexB_PlanParam.getValue());

	////building the vectors for position and direction from the parameters Point and Direction
	//VectorStructR3 mDirection = { modPlanElement->mDirectionParamX.getValue(),modPlanElement->mDirectionParamY.getValue(),modPlanElement->mDirectionParamZ.getValue() };
	//VectorStructR3 mPosition = { modPlanElement->mPointParamX.getValue(),modPlanElement->mPointParamY.getValue(),modPlanElement->mPointParamZ.getValue() };

	//getting the point and direction vectors into the plane element
	modPlanElement->setDirectionX_value(mDirectionParamX.getValue());
	modPlanElement->setDirectionY_value(mDirectionParamY.getValue());
	modPlanElement->setDirectionZ_value(mDirectionParamZ.getValue());

	modPlanElement->setPointElementValue_X(mPointParamX.getValue());
	modPlanElement->setPointElementValue_Y(mPointParamY.getValue());
	modPlanElement->setPointElementValue_Z(mPointParamZ.getValue());

	//getting the typmodifier from the plane element
	typeModifier typMode = mSemiHeightPlanEleParam.getModifier();

	//#tarik# check for the modifier ~ variable or fixed
	if (typMode == typeModifierVariable) {

		//#tarik# get the max and min range for the semiheight
		real maxSemiHeight = mSemiHeightPlanEleParam.getMaximum();
		real minSemiHeight = mSemiHeightPlanEleParam.getMinimum();

		//#tarik# randomizing in the range of min and max
		real generateSemiHeight = fRand(minSemiHeight, maxSemiHeight);

		//#tarik# set the randomized value as the current semiheight value
		modPlanElement->setSemiHeightElementValue(generateSemiHeight);

	}

	typeModifier typPoint = mPointParamZ.getModifier();

	if (typPoint == typeModifierVariable) {
		real generatePointZ = fRand(mPointParamZ.getMinimum(), mPointParamZ.getMaximum());
		modPlanElement->setPointElementValue_Z(generatePointZ);
	}

	else if (typPoint == typeModifierFixed) {
		modPlanElement->setPointElementValue_Z(mPointParamZ.getValue());
	}

	modPlanElement->setParameterSemiHeight(mSemiHeightPlanEleParam.getMinimum(), mSemiHeightPlanEleParam.getMaximum(), mSemiHeightPlanEleParam.getStdDev(), mSemiHeightPlanEleParam.getModifier());

	modPlanElement->setParameterPointX(mPointParamX.getMinimum(), mPointParamX.getMaximum(), mPointParamX.getStdDev(), mPointParamX.getModifier());

	modPlanElement->setParameterPointY(mPointParamY.getMinimum(), mPointParamY.getMaximum(), mPointParamY.getStdDev(), mPointParamY.getModifier());

	modPlanElement->setParameterPointZ(mPointParamZ.getMinimum(), mPointParamZ.getMaximum(), mPointParamZ.getStdDev(), mPointParamZ.getModifier());


	modPlanElement->buildSurface_LLT();
	return modPlanElement;
}

std::shared_ptr<Element_CR> PlanElement::crossover_ptr(std::shared_ptr<Element_CR> A, std::shared_ptr<Element_CR> B)
{

	//PlanElement* crossPlanA = dynamic_cast<PlanElement*>(A);
	//PlanElement* crossPlanB = dynamic_cast<PlanElement*>(B);
	std::shared_ptr<Element_CR> crossNew;
	crossNew = getDeepCopyElement_ptr(A);

	unsigned int chanceSemiHeight = rand() % 10 + 1;
	unsigned int chancePosition = rand() % 10 + 1;
	if (chanceSemiHeight > 5) {

		crossNew->setSemiHeightElementValue(B->getSemiHeightElementValue());
	}

	if (chancePosition > 5) {
		crossNew->setPointElementValue_Z(B->getPointElementValue_Z());
	}

	crossNew->buildSurface_LLT();
	return crossNew;

}



void PlanElement::pushPosition(real push) {
	mPointParamZ.set(mPointParamZ.getValue() + push);
	buildSurface_LLT();
}

void PlanElement::print()
{
	std::cout << "Plane Element" << "\n";
	std::cout << "Semi-Height : " << std::setprecision(10) << mSemiHeightPlanEleParam.getValue() << "\n";
	std::cout << "Position on optical axis : " << std::setprecision(10) << mPointParamZ.getValue() << "\n";

}

//void PlanElement::localOptimization_semiheight(real step/*, Element_CR* element*/)
//{
//
//	if (mSemiHeightPlanEleParam.getModifier() == typeModifierVariable) {
//		if ((mSemiHeightPlanEleParam.getValue() + step) <= mSemiHeightPlanEleParam.getMaximum()) {
//			mSemiHeightPlanEleParam.set(mSemiHeightPlanEleParam.getValue() + step);
//			buildSurface_LLT();
//
//		}
//	}
//
//}
//
void PlanElement::localOptimization_radius(real step)
{
	//plane got no radius
}

void PlanElement::localOptimization_position(real step)
{

	if (mPointParamZ.getModifier() == typeModifierVariable)
	{
		if ((mPointParamZ.getValue() + step) <= mPointParamZ.getMaximum()) {
			mPointParamZ.set(mPointParamZ.getValue() + step);
			buildSurface_LLT();
		}
	}

}




real PlanElement::minPosValue_Z() {
	return mPointParamZ.getMinimum();
}
real PlanElement::maxPosValue_Z() {
	return mPointParamZ.getMaximum();
}


// get direction type modifier
typeModifier PlanElement::getDirectionTypeModifier_Z()
{
	return mDirectionParamZ.getModifier();
}

// get point type modifier
typeModifier PlanElement::getPointTypeModifier_Z()
{
	return mPointParamZ.getModifier();
}

real PlanElement::getPointElementValue_Z()
{
	return mPointParamZ.getValue();
}

real PlanElement::getDirectionElementValue_Z()
{
	return mDirectionParamZ.getValue();
}


real PlanElement::getRadiusElementValue()
{
	return 999999999999.0;
}

typeModifier PlanElement::getRadiusTypeModifier()
{
	return typeModifierFixed;
}


std::shared_ptr<Element_CR> PlanElement::getDeepCopyElement_ptr(std::shared_ptr<Element_CR> element)
{

	std::shared_ptr<Element_CR> deepCopySphereEle = element->clone();
	return deepCopySphereEle;

	return deepCopySphereEle;
}

void PlanElement::setRadiusElementValue(real Radius)
{
	std::cout << "plan element has no radius!!!" << std::endl;
}

void PlanElement::setSemiHeightElementValue(real semiHeight)
{
	mSemiHeightPlanEleParam.set(semiHeight);
}

void PlanElement::setParameterSemiHeight(real min, real max, real stdDev, typeModifier typeMode)
{
	mSemiHeightPlanEleParam.setMinimum(min);
	mSemiHeightPlanEleParam.setMaximum(max);
	mSemiHeightPlanEleParam.setStdDev(stdDev);
	mSemiHeightPlanEleParam.setModifier(typeMode);
}

void PlanElement::setParameterRadius(real min, real max, real stdDev, typeModifier typeMode)
{
	std::cout << "the plan element has no parameter radius" << std::endl;

}

void PlanElement::setParameterDirectionX(real min, real max, real stdDev, typeModifier typeMode)
{
	mDirectionParamX.setMinimum(min);
	mDirectionParamX.setMaximum(max);
	mDirectionParamX.setStdDev(stdDev);
	mDirectionParamX.setModifier(typeMode);
}

void PlanElement::setParameterDirectionY(real min, real max, real stdDev, typeModifier typeMode)
{
	mDirectionParamY.setMinimum(min);
	mDirectionParamY.setMaximum(max);
	mDirectionParamY.setStdDev(stdDev);
	mDirectionParamY.setModifier(typeMode);
}

void PlanElement::setParameterDirectionZ(real min, real max, real stdDev, typeModifier typeMode)
{
	mDirectionParamZ.setMinimum(min);
	mDirectionParamZ.setMaximum(max);
	mDirectionParamZ.setStdDev(stdDev);
	mDirectionParamZ.setModifier(typeMode);
}

void PlanElement::setParameterPointX(real min, real max, real stdDev, typeModifier typeMode)
{
	mPointParamX.setMinimum(min);
	mPointParamX.setMaximum(max);
	mPointParamX.setStdDev(stdDev);
	mPointParamX.setModifier(typeMode);
}

void PlanElement::setParameterPointY(real min, real max, real stdDev, typeModifier typeMode)
{
	mPointParamY.setMinimum(min);
	mPointParamY.setMaximum(max);
	mPointParamY.setStdDev(stdDev);
	mPointParamY.setModifier(typeMode);

}


void PlanElement::setRefIndex_A_value(real refIndexA)
{
	mRefractiveIndexA_PlanParam.set(refIndexA);
}
void PlanElement::setRefIndex_B_value(real refIndexB)
{
	mRefractiveIndexB_PlanParam.set(refIndexB);
}

void PlanElement::setDirectionX_value(real directionX)
{
	mDirectionParamX.set(directionX);
}
void PlanElement::setDirectionY_value(real directionY)
{
	mDirectionParamY.set(directionY);
}
void PlanElement::setDirectionZ_value(real directionZ)
{
	mDirectionParamZ.set(directionZ);
}

void PlanElement::setPointElementValue_X(real pointX)
{
	mPointParamX.set(pointX);
}
void PlanElement::setPointElementValue_Y(real pointY)
{
	mPointParamY.set(pointY);
}
void PlanElement::setPointElementValue_Z(real pointZ)
{
	mPointParamZ.set(pointZ);
}

PlanElement::PlanElement(PlanElement &source)
{
	if (this == &source)
	{
		return;
	}
	mPlanGeometry_LLT = source.mPlanGeometry_LLT;

	mSemiHeightPlanEleParam = source.mSemiHeightPlanEleParam;
	mRadiusPlanEleParam = source.mRadiusPlanEleParam;

	mRefractiveIndexA_PlanParam = source.mRefractiveIndexA_PlanParam;
	mRefractiveIndexB_PlanParam = source.mRefractiveIndexB_PlanParam;

	mPointParamX = source.mPointParamX;
	mPointParamY = source.mPointParamY;
	mPointParamZ = source.mPointParamZ;

	mDirectionParamX = source.mDirectionParamX;
	mDirectionParamY = source.mDirectionParamY;
	mDirectionParamZ = source.mDirectionParamZ;

	mGlassA = source.mGlassA;
	mGlassB = source.mGlassB;
}



std::shared_ptr<Element_CR> PlanElement::clone()
{
	std::shared_ptr<Element_CR> element(new PlanElement(*this));

	return element;

}

PlanElement& PlanElement::operator=(PlanElement& source)
{
	if (this == &source)
	{
		return *this;
	}
	mPlanGeometry_LLT = source.mPlanGeometry_LLT;

	mSemiHeightPlanEleParam = source.mSemiHeightPlanEleParam;

	mRadiusPlanEleParam = source.mRadiusPlanEleParam;

	mRefractiveIndexA_PlanParam = source.mRefractiveIndexA_PlanParam;
	mRefractiveIndexB_PlanParam = source.mRefractiveIndexB_PlanParam;

	mPointParamX = source.mPointParamX;
	mPointParamY = source.mPointParamY;
	mPointParamZ = source.mPointParamZ;

	mDirectionParamX = source.mDirectionParamX;
	mDirectionParamY = source.mDirectionParamY;
	mDirectionParamZ = source.mDirectionParamZ;

	mGlassA = source.mGlassA;
	mGlassB = source.mGlassB;

	return *this;
}

// calculate refractive index side A
void PlanElement::calcRefIndex_A_andSet(real wavelength)
{
	std::shared_ptr<SurfaceIntersectionRay_LLT> modPLanG_LLT(new PlanGeometry_LLT);
	modPLanG_LLT = mPlanGeometry_LLT;

	real tempRefIndexA{};

	if (mGlassA.getRealGlass())
	{
		mGlassA.setRefractiveIndex(mPlanGeometry_LLT->getRefractiveIndex_A());
		tempRefIndexA = mGlassA.calcRefractiveIndexSnellmeier1(wavelength);
		mRefractiveIndexA_PlanParam.set(tempRefIndexA);
	}
	else
	{
		tempRefIndexA = mGlassA.getRefractivIndex();
		mRefractiveIndexA_PlanParam.set(tempRefIndexA);
	}


	modPLanG_LLT->setRefractiveIndexSide_A(mRefractiveIndexA_PlanParam.getValue());
	mPlanGeometry_LLT = modPLanG_LLT;


}

// calculate rearactive index side B
void PlanElement::calcRefIndex_B_andSet(real wavelength)
{
	std::shared_ptr<SurfaceIntersectionRay_LLT> modPLanG_LLT(new PlanGeometry_LLT);
	modPLanG_LLT = mPlanGeometry_LLT;

	real tempRefIndexB{};

	if (mGlassB.getRealGlass())
	{
		mGlassB.setRefractiveIndex(mPlanGeometry_LLT->getRefractiveIndex_B());
		tempRefIndexB = mGlassB.calcRefractiveIndexSnellmeier1(wavelength);
		mRefractiveIndexB_PlanParam.set(tempRefIndexB);
	}
	else
	{
		tempRefIndexB = mGlassB.getRefractivIndex();
		mRefractiveIndexB_PlanParam.set(tempRefIndexB);
	}

	modPLanG_LLT->setRefractiveIndexSide_B(mRefractiveIndexB_PlanParam.getValue());

	mPlanGeometry_LLT = modPLanG_LLT;
}

// calculate refractive indexes side A and B
void PlanElement::calRefIndex_A_and_B_andSet(real wavelength)
{
	calcRefIndex_A_andSet(wavelength);
	calcRefIndex_B_andSet(wavelength);
}

void PlanElement::setGlassA(MaterialSellmeier1 glassA)
{
	mGlassA = glassA;
}
void PlanElement::setGlassB(MaterialSellmeier1 glassB)
{
	mGlassB = glassB;
}

Parameter<real> PlanElement::getParameterRadius()
{
	return mRadiusPlanEleParam;
}
Parameter<real> PlanElement::getParameterPositionZ()
{
	return mPointParamZ;
}

real PlanElement::getRefIndexValue_A()
{
	return mRefractiveIndexA_PlanParam.getValue();
}
real PlanElement::getRefIndexValue_B()
{
	return mRefractiveIndexB_PlanParam.getValue();
}


MaterialSellmeier1 PlanElement::getGlassA()
{
	return mGlassA;
}
MaterialSellmeier1 PlanElement::getGlassB()
{
	return mGlassB;
}

std::shared_ptr<Element_CR> PlanElement::buildElement(std::shared_ptr<SurfaceIntersectionRay_LLT> surface_LLT, MaterialSellmeier1 glassA, MaterialSellmeier1 glassB)
{
	std::shared_ptr<Element_CR> returnPlanElement(new PlanElement);

	real semiHeight = surface_LLT->getSemiHeight();
	VectorStructR3 point = surface_LLT->getPoint();
	VectorStructR3 direction = surface_LLT->getDirection();

	// semi Height
	returnPlanElement->setSemiHeightElementValue(semiHeight);
	// point
	returnPlanElement->setPointElementValue_X(point.getX());
	returnPlanElement->setPointElementValue_Y(point.getY());
	returnPlanElement->setPointElementValue_Z(point.getZ());
	// diretion
	returnPlanElement->setDirectionX_value(direction.getX());
	returnPlanElement->setDirectionY_value(direction.getY());
	returnPlanElement->setDirectionZ_value(direction.getZ());
	// glass A
	returnPlanElement->setGlassA(glassA);
	// glass B
	returnPlanElement->setGlassB(glassB);

	/*Peter*/ returnPlanElement->setAllParameterFix();

	return returnPlanElement;
}

std::string PlanElement::getSurfaceType()
{
	return "Plan     ";
}