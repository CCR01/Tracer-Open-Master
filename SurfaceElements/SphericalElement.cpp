#include "SphericalElement.h"
#include <iomanip>   

SphericalElement::SphericalElement() {};

SphericalElement::SphericalElement(real radius, real  semiHeight, VectorStructR3 point, VectorStructR3 direction, real refractiveSideA, real refractiveSideB)
{
	mRadiusParam.set(radius);
	mSemiHeightElePara.set(semiHeight);

	mPointParamX.set(point.getX());
	mPointParamY.set(point.getY());
	mPointParamZ.set(point.getZ());

	mDirectionParamX.set(direction.getX());
	mDirectionParamY.set(direction.getY());
	mDirectionParamZ.set(direction.getZ());

	mRefractiveiSideA_Param.set(refractiveSideA);
	mRefractiveSideB_Param.set(refractiveSideB);


	buildSurface_LLT();
	setAllParameterFix();
};

SphericalElement::SphericalElement(real /*radius*/ radius, real /*semi height*/  semiHeight, VectorStructR3 /*point*/ point, VectorStructR3 /*direction*/ direction, MaterialSellmeier1 /*glass A*/ glassA, MaterialSellmeier1 /*glass B*/glassB)
{
	mRadiusParam.set(radius);
	mSemiHeightElePara.set(semiHeight);

	mPointParamX.set(point.getX());
	mPointParamY.set(point.getY());
	mPointParamZ.set(point.getZ());

	mDirectionParamX.set(direction.getX());
	mDirectionParamY.set(direction.getY());
	mDirectionParamZ.set(direction.getZ());

	mGlassA = glassA;
	mGlassB = glassB;

	mRefractiveiSideA_Param.set(999);
	mRefractiveSideB_Param.set(999);

	buildSurface_LLT();
	setAllParameterFix();
}

SphericalElement::~SphericalElement() {};

real SphericalElement::getPointElementValue_Z()
{
	return mPointParamZ.getValue();
}

real SphericalElement::getDirectionElementValue_Z()
{
	return mDirectionParamZ.getValue();
}

real SphericalElement::getSemiHeightElementValue()
{
	return mSemiHeightElePara.getValue();
}

// make all parameter of the sphere fix
void SphericalElement::setAllParameterFix()
{
	mRadiusParam.setModifier(typeModifierFixed);
	mSemiHeightElePara.setModifier(typeModifierFixed);

	mPointParamX.setModifier(typeModifierFixed);
	mPointParamY.setModifier(typeModifierFixed);
	mPointParamZ.setModifier(typeModifierFixed);

	mDirectionParamX.setModifier(typeModifierFixed);
	mDirectionParamY.setModifier(typeModifierFixed);
	mDirectionParamZ.setModifier(typeModifierFixed);

	mRefractiveiSideA_Param.setModifier(typeModifierFixed);
	mRefractiveSideB_Param.setModifier(typeModifierFixed);

}

// set radiu value
void SphericalElement::setRadiusValue(real const& Radius)
{
	mRadiusParam.set(Radius);
}
// get radius value 
real SphericalElement::getRadiusValue() const&
{
	return mRadiusParam.getValue();
}
// set semi height value
void SphericalElement::setSemiHeightValue(real const& semiHeight)
{
	return mSemiHeightElePara.set(semiHeight);
}
// get semi height value
real SphericalElement::getSemiHeightValue() const&
{
	return mSemiHeightElePara.getValue();
}
// set origin value
void SphericalElement::setOriginValue(VectorStructR3 const& originValue)
{
	mPointParamX.set(originValue.getX());
	mPointParamY.set(originValue.getY());
	mPointParamZ.set(originValue.getZ());
}
// get origin value
VectorStructR3 SphericalElement::getOriginValue() const&
{
	VectorStructR3 returnOriginValue;
	returnOriginValue.setX(mPointParamX.getValue());
	returnOriginValue.setY(mPointParamY.getValue());
	returnOriginValue.setZ(mPointParamZ.getValue());

	return returnOriginValue;
}
// set direction value
void SphericalElement::setDirectionValue(VectorStructR3 const& directionValue)
{
	mDirectionParamX.set(directionValue.getX());
	mDirectionParamY.set(directionValue.getY());
	mDirectionParamZ.set(directionValue.getZ());
}

// get direction value
VectorStructR3 SphericalElement::getDirectionValue() const&
{
	VectorStructR3 returnDirectionValue;
	returnDirectionValue.setX(mDirectionParamX.getValue());
	returnDirectionValue.setY(mDirectionParamY.getValue());
	returnDirectionValue.setZ(mDirectionParamZ.getValue());

	return returnDirectionValue;
}
//set refracive index value A
void SphericalElement::setRefIndexValue_A(real const& refIndex)
{
	mRefractiveiSideA_Param.set(refIndex);
}


//set refractive index value B
void SphericalElement::setRefIndexValue_B(real const& refIndex)
{
	mRefractiveSideB_Param.set(refIndex);
}


void SphericalElement::buildSurface_LLT()
{
	SphericalSurface_LLT sphericalSurface_LLT;

	sphericalSurface_LLT.setRadius(mRadiusParam.getValue());
	sphericalSurface_LLT.setSemiHeight(mSemiHeightElePara.getValue());

	VectorStructR3 pointR3{ mPointParamX.getValue(), mPointParamY.getValue(), mPointParamZ.getValue() };
	sphericalSurface_LLT.setPoint(pointR3);

	VectorStructR3 directionR3{ mDirectionParamX.getValue(), mDirectionParamY.getValue(), mDirectionParamZ.getValue() };
	sphericalSurface_LLT.setDirection(directionR3);

	sphericalSurface_LLT.setRefractiveIndexSide_A(mRefractiveiSideA_Param.getValue());
	sphericalSurface_LLT.setRefractiveIndexSide_B(mRefractiveSideB_Param.getValue());
	sphericalSurface_LLT.calcCenterSphereAfterRotation();

	mSphericalSurface_LLT = sphericalSurface_LLT.clone();
}



real SphericalElement::fRand_real(real min, real max)
{

	real f = (real)rand() / RAND_MAX;

	return min + f * (max - min);
}







// set parameter of semi-height parameter
void SphericalElement::setSemiHeight(/*min*/ real min, /*max*/ real max, /*stdDev*/ real stdDev, /*modifier*/ typeModifier modi)
{
	mSemiHeightElePara.setMinimum(min);
	mSemiHeightElePara.setMaximum(max);
	mSemiHeightElePara.setStdDev(stdDev);
	mSemiHeightElePara.setModifier(modi);

}



// get pointer to surface LLT for ray tracing
std::shared_ptr<SurfaceIntersectionRay_LLT> SphericalElement::getSurfaceForLLT_ptr()

{
	return mSphericalSurface_LLT;
}


//LLT_Package SphericalElement::getLLT_Package()
//{
//	return LLT_Package{&mSphericalSurface_LLT , mInteraction };
//
//	/*
//	LLT_Package p;
//	p.surface_ptr = &mSphericalSurface_LLT;
//	p.interaton_ptr = &mRefraction_LLT;
//	return p;
//	*/
//}

std::shared_ptr<Element_CR> SphericalElement::crossover_ptr(std::shared_ptr<Element_CR> A, std::shared_ptr<Element_CR> B)
{

	//SphericalElement* crossA = dynamic_cast<SphericalElement*>(A);
	//SphericalElement* crossB = dynamic_cast<SphericalElement*>(B);

	std::shared_ptr<Element_CR> crossNewSphere;
	crossNewSphere = getDeepCopyElement_ptr(A);

	unsigned int chanceRadius = rand() % 10 + 1;
	unsigned int chanceSemiheight = rand() % 10 + 1;
	unsigned int chancePosition = rand() % 10 + 1;

	if (chanceSemiheight > 5) {
		crossNewSphere->setSemiHeightElementValue(B->getSemiHeightElementValue());
	}

	if (chanceRadius > 5) {
		crossNewSphere->setRadiusElementValue(B->getRadiusElementValue());
	}
	if (chancePosition > 5) {
		crossNewSphere->setPointElementValue_Z(B->getPointElementValue_Z());
	}

	crossNewSphere->buildSurface_LLT();



	return crossNewSphere;

}


void SphericalElement::pushPosition(real push)
{
	mPointParamZ.set(mPointParamZ.getValue() + push);
	buildSurface_LLT();
}

void SphericalElement::print()
{
	std::cout << "Spherical Element" << "\n";
	std::cout << "Semi-Height : " << std::setprecision(10) << mSemiHeightElePara.getValue() << "\n";
	std::cout << "Radius : " << std::setprecision(10) << mRadiusParam.getValue() << "\n";
	std::cout << "Position on optical axis : " << std::setprecision(10) << mPointParamZ.getValue() << "\n";

}

//void SphericalElement::localOptimization_semiheight(real step) {
//
//	if (mSemiHeightElePara.getModifier() == typeModifierVariable) {
//		if ((mSemiHeightElePara.getValue() + step) <= mSemiHeightElePara.getMaximum()) {
//			mSemiHeightElePara.set(mSemiHeightElePara.getValue() + step);
//			buildSurface_LLT();
//		}
//	}
//
//}



void SphericalElement::localOptimization_radius(real step)
{

	if (mRadiusParam.getModifier() == typeModifierVariable) {
		if ((mRadiusParam.getValue() + step) <= mRadiusParam.getMaximum()) {
			mRadiusParam.set(mRadiusParam.getValue() + step);
			buildSurface_LLT();
		}
	}

}

void SphericalElement::localOptimization_position(real step) {

	if (mPointParamZ.getModifier() == typeModifierVariable) {
		if ((mPointParamZ.getValue() + step) <= mPointParamZ.getMaximum()) {
			mPointParamZ.set(mPointParamZ.getValue() + step);

			buildSurface_LLT();
		}
	}

}




real SphericalElement::minPosValue_Z() {
	return mPointParamZ.getMinimum();
}
real SphericalElement::maxPosValue_Z() {
	return mPointParamZ.getMaximum();
}



std::shared_ptr<Element_CR> SphericalElement::generate_ptr()
{
	//std::shared_ptr<SphericalElement>  (new int);
	std::shared_ptr<Element_CR> modSphereElement(new SphericalElement);

	modSphereElement->setSemiHeightElementValue(mSemiHeightElePara.getValue());
	modSphereElement->setRadiusElementValue(mRadiusParam.getValue());

	modSphereElement->setGlassA(mGlassA);
	modSphereElement->setGlassB(mGlassB);

	//	modSphereElement->mRadiusParam.setModifier(mRadiusParam.getModifier());

		//getting the direction parameters for sphere
	modSphereElement->setDirectionX_value(mDirectionParamX.getValue());
	modSphereElement->setDirectionY_value(mDirectionParamY.getValue());
	modSphereElement->setDirectionZ_value(mDirectionParamZ.getValue());

	//getting the point parameters from sphere
	modSphereElement->setPointElementValue_X(mPointParamX.getValue());
	modSphereElement->setPointElementValue_Y(mPointParamY.getValue());
	modSphereElement->setPointElementValue_Z(mPointParamZ.getValue());

	//getting the refractive index for sphere
	modSphereElement->setRefIndex_A_value(mRefractiveiSideA_Param.getValue());
	modSphereElement->setRefIndex_B_value(mRefractiveSideB_Param.getValue());


	//generate a random radius for the sphere


	typeModifier typModeRadius = mRadiusParam.getModifier();

	if (typModeRadius == typeModifierVariable) {

		real maxRadius = mRadiusParam.getMaximum();
		real minRadius = mRadiusParam.getMinimum();

		real generateRadius;

		generateRadius = fRand_real(minRadius, maxRadius);

		modSphereElement->setRadiusElementValue(generateRadius);

	}

	else if (typModeRadius == typeModifierFixed)
	{
		modSphereElement->setRadiusElementValue(mRadiusParam.getValue());
	}



	typeModifier typModSemiHeight = mSemiHeightElePara.getModifier();

	//generate a random semiheight
	if (typModSemiHeight == typeModifierVariable) {

		real maxSemiHeight = mSemiHeightElePara.getMaximum();
		real minSemiHeight = mSemiHeightElePara.getMinimum();

		real generateSemiHeight;

		generateSemiHeight = fRand_real(minSemiHeight, maxSemiHeight);

		///real generateSemiHeight = 10.0;

		modSphereElement->setSemiHeightElementValue(generateSemiHeight);

	}

	else if (typModSemiHeight == typeModifierFixed)
	{
		modSphereElement->setSemiHeightElementValue(mSemiHeightElePara.getValue());
	}

	//mPointParamZ.setModifier(typeModifierVariable);
	typeModifier typPoint = mPointParamZ.getModifier();

	if (typPoint == typeModifierVariable) {
		real generatePointZ = fRand_real(mPointParamZ.getMinimum(), mPointParamZ.getMaximum());
		modSphereElement->setPointElementValue_Z(generatePointZ);
	}
	else if (typPoint == typeModifierFixed) {
		modSphereElement->setPointElementValue_Z(mPointParamZ.getValue());
	}

	modSphereElement->setParameterSemiHeight(mSemiHeightElePara.getMinimum(), mSemiHeightElePara.getMaximum(), mSemiHeightElePara.getStdDev(), mSemiHeightElePara.getModifier());

	modSphereElement->setParameterRadius(mRadiusParam.getMinimum(), mRadiusParam.getMaximum(), mRadiusParam.getStdDev(), mRadiusParam.getModifier());

	modSphereElement->setParameterPointX(mPointParamX.getMinimum(), mPointParamX.getMaximum(), mPointParamX.getStdDev(), mPointParamX.getModifier());

	modSphereElement->setParameterPointY(mPointParamY.getMinimum(), mPointParamY.getMaximum(), mPointParamY.getStdDev(), mPointParamY.getModifier());

	modSphereElement->setParameterPointZ(mPointParamZ.getMinimum(), mPointParamZ.getMaximum(), mPointParamZ.getStdDev(), mPointParamZ.getModifier());

	modSphereElement->buildSurface_LLT();
	//delete modSphereElement;
	//	SphericalElement* crossA = dynamic_cast<SphericalElement*>(A);

		//return std::make_shared<Element_CR>(dynamic_cast<SphericalElement*>(modSphereElement));


	return modSphereElement;
	//	std::cout << "stop\n";
}

// get direction type modifier
typeModifier SphericalElement::getDirectionTypeModifier_Z()
{
	return mDirectionParamZ.getModifier();
}

// get point type modifier
typeModifier SphericalElement::getPointTypeModifier_Z()
{
	return mPointParamZ.getModifier();
}

real SphericalElement::getRadiusElementValue()
{
	return mRadiusParam.getValue();
}

typeModifier SphericalElement::getRadiusTypeModifier()
{
	return mRadiusParam.getModifier();
}

std::shared_ptr<Element_CR> SphericalElement::getDeepCopyElement_ptr(std::shared_ptr<Element_CR> element)
{
	std::shared_ptr<Element_CR> deepCopySphereEle = element->clone();

	return deepCopySphereEle;
}


void SphericalElement::setRadiusElementValue(real Radius)
{
	mRadiusParam.set(Radius);
}

void SphericalElement::setSemiHeightElementValue(real semiHeight)
{
	mSemiHeightElePara.set(semiHeight);
}

void SphericalElement::setParameterSemiHeight(real min, real max, real stdDev, typeModifier typeMode)
{
	mSemiHeightElePara.setMinimum(min);
	mSemiHeightElePara.setMaximum(max);
	mSemiHeightElePara.setStdDev(stdDev);
	mSemiHeightElePara.setModifier(typeMode);
}

void SphericalElement::setParameterRadius(real min, real max, real stdDev, typeModifier typeMode)
{
	mRadiusParam.setMinimum(min);
	mRadiusParam.setMaximum(max);
	mRadiusParam.setStdDev(stdDev);
	mRadiusParam.setModifier(typeMode);

}

void SphericalElement::setParameterDirectionX(real min, real max, real stdDev, typeModifier typeMode)
{
	mDirectionParamX.setMinimum(min);
	mDirectionParamX.setMaximum(max);
	mDirectionParamX.setStdDev(stdDev);
	mDirectionParamX.setModifier(typeMode);
}

void SphericalElement::setParameterDirectionY(real min, real max, real stdDev, typeModifier typeMode)
{
	mDirectionParamY.setMinimum(min);
	mDirectionParamY.setMaximum(max);
	mDirectionParamY.setStdDev(stdDev);
	mDirectionParamY.setModifier(typeMode);
}

void SphericalElement::setParameterDirectionZ(real min, real max, real stdDev, typeModifier typeMode)
{
	mDirectionParamZ.setMinimum(min);
	mDirectionParamZ.setMaximum(max);
	mDirectionParamZ.setStdDev(stdDev);
	mDirectionParamZ.setModifier(typeMode);
}

void SphericalElement::setParameterPointX(real min, real max, real stdDev, typeModifier typeMode)
{
	mPointParamX.setMinimum(min);
	mPointParamX.setMaximum(max);
	mPointParamX.setStdDev(stdDev);
	mPointParamX.setModifier(typeMode);
}

void SphericalElement::setParameterPointY(real min, real max, real stdDev, typeModifier typeMode)
{
	mPointParamY.setMinimum(min);
	mPointParamY.setMaximum(max);
	mPointParamY.setStdDev(stdDev);
	mPointParamY.setModifier(typeMode);

}
void SphericalElement::setParameterPointZ(real min, real max, real stdDev, typeModifier typeMode)
{
	mPointParamZ.setMinimum(min);
	mPointParamZ.setMaximum(max);
	mPointParamZ.setStdDev(stdDev);
	mPointParamZ.setModifier(typeMode);

}

void SphericalElement::setRefIndex_A_value(real refIndexA)
{
	mRefractiveiSideA_Param.set(refIndexA);
}
void SphericalElement::setRefIndex_B_value(real refIndexB)
{
	mRefractiveSideB_Param.set(refIndexB);
}

void SphericalElement::setDirectionX_value(real directionX)
{
	mDirectionParamX.set(directionX);
}
void SphericalElement::setDirectionY_value(real directionY)
{
	mDirectionParamY.set(directionY);
}
void SphericalElement::setDirectionZ_value(real directionZ)
{
	mDirectionParamZ.set(directionZ);
}

void SphericalElement::setPointElementValue_X(real pointX)
{
	mPointParamX.set(pointX);
}
void SphericalElement::setPointElementValue_Y(real pointY)
{
	mPointParamY.set(pointY);
}
void SphericalElement::setPointElementValue_Z(real pointZ)
{
	mPointParamZ.set(pointZ);
}

std::shared_ptr<Element_CR> SphericalElement::clone()
{
	std::shared_ptr<Element_CR> element(new SphericalElement(*this));

	return element;

}

SphericalElement::SphericalElement(SphericalElement &source)
{
	if (this == &source)
	{
		return;
	}
	mSphericalSurface_LLT = source.mSphericalSurface_LLT;
	mRadiusParam = source.mRadiusParam;
	mSemiHeightElePara = source.mSemiHeightElePara;

	mPointParamX = source.mPointParamX;
	mPointParamY = source.mPointParamY;
	mPointParamZ = source.mPointParamZ;

	mDirectionParamX = source.mDirectionParamX;
	mDirectionParamY = source.mDirectionParamX;
	mDirectionParamZ = source.mDirectionParamZ;

	mRefractiveiSideA_Param = source.mRefractiveiSideA_Param;
	mRefractiveSideB_Param = source.mRefractiveSideB_Param;

	mGlassA = source.mGlassA;
	mGlassB = source.mGlassB;


}

SphericalElement& SphericalElement::operator=(SphericalElement& source)
{
	if (this == &source)
	{
		return *this;
	}

	mSphericalSurface_LLT = source.mSphericalSurface_LLT;
	mRadiusParam = source.mRadiusParam;
	mSemiHeightElePara = source.mSemiHeightElePara;

	mPointParamX = source.mPointParamX;
	mPointParamY = source.mPointParamY;
	mPointParamZ = source.mPointParamZ;

	mDirectionParamX = source.mDirectionParamX;
	mDirectionParamY = source.mDirectionParamX;
	mDirectionParamZ = source.mDirectionParamZ;

	mRefractiveiSideA_Param = source.mRefractiveiSideA_Param;
	mRefractiveSideB_Param = source.mRefractiveSideB_Param;

	mGlassA = source.mGlassA;
	mGlassB = source.mGlassB;

	return *this;
}

// calculate refractive index side A
void SphericalElement::calcRefIndex_A_andSet(real wavelength)
{
	std::shared_ptr<SurfaceIntersectionRay_LLT> modSphere_LLT(new SphericalSurface_LLT);
	modSphere_LLT = mSphericalSurface_LLT;
	real tempRefIndexA = mGlassA.calcRefractiveIndexSnellmeier1(wavelength);
	mRefractiveiSideA_Param.set(tempRefIndexA);
	modSphere_LLT->setRefractiveIndexSide_A(mRefractiveiSideA_Param.getValue());
	mSphericalSurface_LLT = modSphere_LLT;
}

// calculate rearactive index side B
void SphericalElement::calcRefIndex_B_andSet(real wavelength)
{
	std::shared_ptr<SurfaceIntersectionRay_LLT> modSphere_LLT(new SphericalSurface_LLT);
	modSphere_LLT = mSphericalSurface_LLT;
	real tempRefIndexB = mGlassB.calcRefractiveIndexSnellmeier1(wavelength);
	mRefractiveSideB_Param.set(tempRefIndexB);
	modSphere_LLT->setRefractiveIndexSide_B(mRefractiveSideB_Param.getValue());
	mSphericalSurface_LLT = modSphere_LLT;
}

// calculate refractive indexes side A and B
void SphericalElement::calRefIndex_A_and_B_andSet(real wavelength)
{

	calcRefIndex_A_andSet(wavelength);
	calcRefIndex_B_andSet(wavelength);

}

void SphericalElement::setGlassA(MaterialSellmeier1 glassA)
{
	mGlassA = glassA;
}
void SphericalElement::setGlassB(MaterialSellmeier1 glassB)
{
	mGlassB = glassB;
}

Parameter<real> SphericalElement::getParameterRadius()
{
	return mRadiusParam;
}
Parameter<real> SphericalElement::getParameterPositionZ()
{
	return mPointParamZ;
}

real SphericalElement::getRefIndexValue_A()
{
	return mRefractiveiSideA_Param.getValue();
}
real SphericalElement::getRefIndexValue_B()
{
	return mRefractiveSideB_Param.getValue();
}

MaterialSellmeier1 SphericalElement::getGlassA()
{
	return mGlassA;
}
MaterialSellmeier1 SphericalElement::getGlassB()
{
	return mGlassB;
}

std::shared_ptr<Element_CR> SphericalElement::buildElement(std::shared_ptr<SurfaceIntersectionRay_LLT> surface_LLT, MaterialSellmeier1 glassA, MaterialSellmeier1 glassB)
{
	std::shared_ptr<Element_CR> returnSphereElement(new SphericalElement);

	real radius = surface_LLT->getRadius();
	real semiHeight = surface_LLT->getSemiHeight();
	VectorStructR3 point = surface_LLT->getPoint();
	VectorStructR3 direction = surface_LLT->getDirection();

	// radius
	returnSphereElement->setRadiusElementValue(radius);
	// semi Height
	returnSphereElement->setSemiHeightElementValue(semiHeight);
	// point
	returnSphereElement->setPointElementValue_X(point.getX());
	returnSphereElement->setPointElementValue_Y(point.getY());
	returnSphereElement->setPointElementValue_Z(point.getZ());
	// diretion
	returnSphereElement->setDirectionX_value(direction.getX());
	returnSphereElement->setDirectionY_value(direction.getY());
	returnSphereElement->setDirectionZ_value(direction.getZ());
	// glass A
	returnSphereElement->setGlassA(glassA);
	// glass B
	returnSphereElement->setGlassB(glassB);

	/*Peter*/ returnSphereElement->setAllParameterFix();

	return returnSphereElement;
}