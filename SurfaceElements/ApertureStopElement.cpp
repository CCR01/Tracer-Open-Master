#include "ApertureStopElement.h"
#include <iomanip>   


ApertureStopElement::ApertureStopElement() {};
ApertureStopElement::ApertureStopElement(real semiHeight, VectorStructR3 point, VectorStructR3 direction, real refractiveIndex)
{
	mSemiHeightApertureElePara.set(semiHeight);

	mPointParamX.set(point.getX());
	mPointParamY.set(point.getY());
	mPointParamZ.set(point.getZ());

	mDirectionParamX.set(direction.getX());
	mDirectionParamY.set(direction.getY());
	mDirectionParamZ.set(direction.getZ());

	mRrefractiveIndex.set(refractiveIndex);

	buildSurface_LLT();
	setAllParameterFix();
};

ApertureStopElement::ApertureStopElement(real /* semi height*/ semiHeight, VectorStructR3 /*point*/ point, VectorStructR3 /*direction*/ direction, MaterialSellmeier1 /*glass*/ glass)
{
	mSemiHeightApertureElePara.set(semiHeight);

	mPointParamX.set(point.getX());
	mPointParamY.set(point.getY());
	mPointParamZ.set(point.getZ());

	mDirectionParamX.set(direction.getX());
	mDirectionParamY.set(direction.getY());
	mDirectionParamZ.set(direction.getZ());

	mRrefractiveIndex.set(999);
	mGlass = glass;

	buildSurface_LLT();
	setAllParameterFix();
}


ApertureStopElement::~ApertureStopElement() {};

real ApertureStopElement::getPointElementValue_Z()
{
	return mPointParamZ.getValue();
}

real ApertureStopElement::getDirectionElementValue_Z()
{
	return mDirectionParamZ.getValue();
}

real ApertureStopElement::getSemiHeightElementValue()
{
	return mSemiHeightApertureElePara.getValue();
}


void ApertureStopElement::buildSurface_LLT()
{
	ApertureStop_LLT aperStop_LLT;

	aperStop_LLT.setSemiHeight(mSemiHeightApertureElePara.getValue());

	VectorStructR3 pointR3{ mPointParamX.getValue(), mPointParamY.getValue(), mPointParamZ.getValue() };
	aperStop_LLT.setPoint(pointR3);

	VectorStructR3 directionR3{ mDirectionParamX.getValue(), mDirectionParamY.getValue(), mDirectionParamZ.getValue() };
	aperStop_LLT.setDirection(directionR3);
	aperStop_LLT.setRefractiveIndexSide_A(mRrefractiveIndex.getValue());

	mAperture_LLT = aperStop_LLT.clone();
}



// get pointer to surface LLT for ray tracing
std::shared_ptr<SurfaceIntersectionRay_LLT> ApertureStopElement::getSurfaceForLLT_ptr()
{
	return mAperture_LLT;
}

real ApertureStopElement::fRand(real min, real max) {


	real f = (real)rand() / RAND_MAX;

	return min + f * (max - min);
}



// set parameter of semi-height parameter
void ApertureStopElement::setSemiHeightParameter(real min, real max, real stdDev, typeModifier modi)
{
	mSemiHeightApertureElePara.setMinimum(min);
	mSemiHeightApertureElePara.setMaximum(max);
	mSemiHeightApertureElePara.setStdDev(stdDev);
	mSemiHeightApertureElePara.setModifier(modi);

}



void ApertureStopElement::setSemiHeightParaValue(real semiHeight)
{
	mSemiHeightApertureElePara.set(semiHeight);
}

void ApertureStopElement::setPointZ(real min, real max, real stdDev, typeModifier modi) {
	mPointParamZ.setMinimum(min);
	mPointParamZ.setMaximum(max);
	mPointParamZ.setStdDev(stdDev);
	mPointParamZ.setModifier(modi);

}


//set variable as other elements
std::shared_ptr<Element_CR> ApertureStopElement::generate_ptr()
{

	std::shared_ptr<Element_CR> modApertureStop(new ApertureStopElement);



	//getting the semiheight value for the plan element
	modApertureStop->setSemiHeightElementValue(mSemiHeightApertureElePara.getValue());
	modApertureStop->setParameterSemiHeight(mSemiHeightApertureElePara.getMinimum(), mSemiHeightApertureElePara.getMaximum(), mSemiHeightApertureElePara.getStdDev(), mSemiHeightApertureElePara.getModifier());

	modApertureStop->setDirectionX_value(mDirectionParamX.getValue());
	modApertureStop->setDirectionY_value(mDirectionParamY.getValue());
	modApertureStop->setDirectionZ_value(mDirectionParamZ.getValue());

	modApertureStop->setGlassA(mGlass);

	//getting the point parameters for the plane
	modApertureStop->setPointElementValue_X(mPointParamX.getValue());
	modApertureStop->setPointElementValue_Y(mPointParamY.getValue());
	modApertureStop->setPointElementValue_Z(mPointParamZ.getValue());


	modApertureStop->setParameterPointX(mPointParamX.getMinimum(), mPointParamX.getMaximum(), mPointParamX.getStdDev(), mPointParamX.getModifier());

	modApertureStop->setParameterPointY(mPointParamY.getMinimum(), mPointParamY.getMaximum(), mPointParamY.getStdDev(), mPointParamY.getModifier());

	modApertureStop->setParameterPointZ(mPointParamZ.getMinimum(), mPointParamZ.getMaximum(), mPointParamZ.getStdDev(), mPointParamZ.getModifier());

	//getting the refractive index into the plane element
	modApertureStop->setRefIndex_A_value(mRrefractiveIndex.getValue());

	//getting the typmodifier from the plane element
	typeModifier typMode = mSemiHeightApertureElePara.getModifier();

	//#tarik# check for the modifier ~ variable or fixed
	if (typMode == typeModifierVariable) {

		//#tarik# get the max and min range for the semiheight
		real maxSemiHeight = mSemiHeightApertureElePara.getMaximum();
		real minSemiHeight = mSemiHeightApertureElePara.getMinimum();

		//#tarik# randomizing in the range of min and max
		real generateSemiHeight = fRand(minSemiHeight, maxSemiHeight);

		//#tarik# set the randomized value as the current semiheight value
		modApertureStop->setSemiHeightElementValue(generateSemiHeight);

	}


	typeModifier typPoint = mPointParamZ.getModifier();

	if (typPoint == typeModifierVariable) {
		real generatePointZ = fRand(mPointParamZ.getMinimum(), mPointParamZ.getMaximum());
		modApertureStop->setPointElementValue_Z(generatePointZ);
	}

	else if (typPoint == typeModifierFixed) {
		modApertureStop->setPointElementValue_Z(mPointParamZ.getValue());
	}



	modApertureStop->buildSurface_LLT();
	return modApertureStop;
}



std::shared_ptr<Element_CR> ApertureStopElement::crossover_ptr(std::shared_ptr<Element_CR> A, std::shared_ptr<Element_CR> B)
{


	//ApertureStopElement* crossApertureA = dynamic_cast<ApertureStopElement*>(A);
	//ApertureStopElement* crossApertureB = dynamic_cast<ApertureStopElement*>(B);

	std::shared_ptr<Element_CR> crossAperture;
	crossAperture = getDeepCopyElement_ptr(A);

	unsigned int chance = rand() % 10 + 1;
	unsigned int position = rand() % 10 + 1;

	if (chance > 5) {

		crossAperture->setSemiHeightElementValue(B->getSemiHeightElementValue());
	}

	if (position > 5) {
		crossAperture->setPointElementValue_Z(B->getPointElementValue_Z());
	}

	crossAperture->buildSurface_LLT();
	return crossAperture;

}

// get position
VectorStructR3 ApertureStopElement::getPositionValueR3() const&
{
	VectorStructR3 returnPositioValR3;
	returnPositioValR3.setX(mPointParamX.getValue());
	returnPositioValR3.setY(mPointParamY.getValue());
	returnPositioValR3.setZ(mPointParamZ.getValue());

	return returnPositioValR3;
}

// get Direction
VectorStructR3 ApertureStopElement::getDirectionValueR3() const&
{
	VectorStructR3 returnDirectionR3;
	returnDirectionR3.setX(mDirectionParamX.getValue());
	returnDirectionR3.setY(mDirectionParamY.getValue());
	returnDirectionR3.setZ(mDirectionParamZ.getValue());

	return returnDirectionR3;
}

void ApertureStopElement::print() {

	std::cout << "Aperture Element" << "\n";
	std::cout << "Semi-Height : " << std::setprecision(10) << mSemiHeightApertureElePara.getValue() << "\n";
	std::cout << "Position on optical axis : " << std::setprecision(10) << mPointParamZ.getValue() << "\n";


}

////set as other elements local optimized
//void ApertureStopElement::localOptimization_semiheight(real step)
//{
//
//	if (mSemiHeightApertureElePara.getModifier() == typeModifierVariable) {
//		if ((mSemiHeightApertureElePara.getValue() + step) <= mSemiHeightApertureElePara.getMaximum()) {
//			mSemiHeightApertureElePara.set(mSemiHeightApertureElePara.getValue() + step);
//			buildSurface_LLT();
//		}
//	}
//
//}

void ApertureStopElement::localOptimization_radius(real step) {
	//aperture got no radius therefore no otpimization
}


void ApertureStopElement::localOptimization_position(real step) {


	if (mPointParamZ.getModifier() == typeModifierVariable)
	{
		if ((mPointParamZ.getValue() + step) <= mPointParamZ.getMaximum()) {
			mPointParamZ.set(mPointParamZ.getValue() + step);
			buildSurface_LLT();
		}
	}

}



real ApertureStopElement::minPosValue_Z() {
	return mPointParamZ.getMinimum();
}
real ApertureStopElement::maxPosValue_Z() {
	return mPointParamZ.getMaximum();
}

void ApertureStopElement::pushPosition(real push)
{
	mPointParamZ.set(mPointParamZ.getValue() + push);
	buildSurface_LLT();
}

// get direction type modifier
typeModifier ApertureStopElement::getDirectionTypeModifier_Z()
{
	return mDirectionParamZ.getModifier();
}

// get point type modifier
typeModifier ApertureStopElement::getPointTypeModifier_Z()
{
	return mPointParamZ.getModifier();
}

real ApertureStopElement::getRadiusElementValue()
{
	return 999999999999.0;
}

typeModifier ApertureStopElement::getRadiusTypeModifier()
{
	return typeModifierFixed;
}


std::shared_ptr<Element_CR> ApertureStopElement::getDeepCopyElement_ptr(std::shared_ptr<Element_CR> element)
{
	std::shared_ptr<Element_CR> deepCopySphereEle = element->clone();
	return deepCopySphereEle;

}

void ApertureStopElement::setRadiusElementValue(real Radius)
{
	std::cout << "apterture stop element has no radius!!!" << std::endl;
}

void ApertureStopElement::setSemiHeightElementValue(real semiHeight)
{
	mSemiHeightApertureElePara.set(semiHeight);
}

void ApertureStopElement::setParameterSemiHeight(real min, real max, real stdDev, typeModifier typeMode)
{
	mSemiHeightApertureElePara.setMinimum(min);
	mSemiHeightApertureElePara.setMaximum(max);
	mSemiHeightApertureElePara.setStdDev(stdDev);
	mSemiHeightApertureElePara.setModifier(typeMode);
}

void ApertureStopElement::setParameterRadius(real min, real max, real stdDev, typeModifier typeMode)
{
	std::cout << "the aperture stop element has no parameter radius" << std::endl;

}

void ApertureStopElement::setParameterDirectionX(real min, real max, real stdDev, typeModifier typeMode)
{
	mDirectionParamX.setMinimum(min);
	mDirectionParamX.setMaximum(max);
	mDirectionParamX.setStdDev(stdDev);
	mDirectionParamX.setModifier(typeMode);
}

void ApertureStopElement::setParameterDirectionY(real min, real max, real stdDev, typeModifier typeMode)
{
	mDirectionParamY.setMinimum(min);
	mDirectionParamY.setMaximum(max);
	mDirectionParamY.setStdDev(stdDev);
	mDirectionParamY.setModifier(typeMode);
}

void ApertureStopElement::setParameterDirectionZ(real min, real max, real stdDev, typeModifier typeMode)
{
	mDirectionParamZ.setMinimum(min);
	mDirectionParamZ.setMaximum(max);
	mDirectionParamZ.setStdDev(stdDev);
	mDirectionParamZ.setModifier(typeMode);
}

void ApertureStopElement::setParameterPointX(real min, real max, real stdDev, typeModifier typeMode)
{
	mPointParamX.setMinimum(min);
	mPointParamX.setMaximum(max);
	mPointParamX.setStdDev(stdDev);
	mPointParamX.setModifier(typeMode);
}

void ApertureStopElement::setParameterPointY(real min, real max, real stdDev, typeModifier typeMode)
{
	mPointParamY.setMinimum(min);
	mPointParamY.setMaximum(max);
	mPointParamY.setStdDev(stdDev);
	mPointParamY.setModifier(typeMode);

}
void ApertureStopElement::setParameterPointZ(real min, real max, real stdDev, typeModifier typeMode)
{
	mPointParamZ.setMinimum(min);
	mPointParamZ.setMaximum(max);
	mPointParamZ.setStdDev(stdDev);
	mPointParamZ.setModifier(typeMode);

}

void ApertureStopElement::setRefIndex_A_value(real refIndexA)
{
	mRrefractiveIndex.set(refIndexA);
}
void ApertureStopElement::setRefIndex_B_value(real refIndexB)
{
	mRrefractiveIndex.set(refIndexB);
}

void ApertureStopElement::setDirectionX_value(real directionX)
{
	mDirectionParamX.set(directionX);
}
void ApertureStopElement::setDirectionY_value(real directionY)
{
	mDirectionParamY.set(directionY);
}
void ApertureStopElement::setDirectionZ_value(real directionZ)
{
	mDirectionParamZ.set(directionZ);
}

void ApertureStopElement::setPointElementValue_X(real pointX)
{
	mPointParamX.set(pointX);
}
void ApertureStopElement::setPointElementValue_Y(real pointY)
{
	mPointParamY.set(pointY);
}
void ApertureStopElement::setPointElementValue_Z(real pointZ)
{
	mPointParamZ.set(pointZ);
}

ApertureStopElement::ApertureStopElement(ApertureStopElement &source)
{
	if (this == &source)
	{
		return;
	}

	mAperture_LLT = source.mAperture_LLT;

	mSemiHeightApertureElePara = source.mSemiHeightApertureElePara;

	mRrefractiveIndex = source.mRrefractiveIndex;

	mPointParamX = source.mPointParamX;
	mPointParamY = source.mPointParamY;
	mPointParamZ = source.mPointParamZ;

	mDirectionParamX = source.mDirectionParamX;
	mDirectionParamY = source.mDirectionParamY;
	mDirectionParamZ = source.mDirectionParamZ;

	mGlass = source.mGlass;

}

std::shared_ptr<Element_CR> ApertureStopElement::clone()
{
	std::shared_ptr<Element_CR> element(new ApertureStopElement(*this));

	return element;

}

ApertureStopElement& ApertureStopElement::operator=(ApertureStopElement& source)
{
	if (this == &source)
	{
		return *this;
	}

	mAperture_LLT = source.mAperture_LLT;

	mSemiHeightApertureElePara = source.mSemiHeightApertureElePara;

	mRrefractiveIndex = source.mRrefractiveIndex;

	mPointParamX = source.mPointParamX;
	mPointParamY = source.mPointParamY;
	mPointParamZ = source.mPointParamZ;

	mDirectionParamX = source.mDirectionParamX;
	mDirectionParamY = source.mDirectionParamY;
	mDirectionParamZ = source.mDirectionParamZ;

	mGlass = source.mGlass;


	return *this;
}



// calculate refractive indexes side A and B
void ApertureStopElement::calRefIndex_A_and_B_andSet(real wavelenth)
{
	std::shared_ptr<SurfaceIntersectionRay_LLT> modAperStop_LLT(new ApertureStop_LLT);
	modAperStop_LLT = mAperture_LLT;

	real temRefIndex = mGlass.calcRefractiveIndexSnellmeier1(wavelenth);
	mRrefractiveIndex.set(temRefIndex);
	modAperStop_LLT->setRefractiveIndexSide_A(mRrefractiveIndex.getValue());

	mAperture_LLT = modAperStop_LLT;

}

void ApertureStopElement::setGlassA(MaterialSellmeier1 glassA)
{
	mGlass = glassA;
}
void ApertureStopElement::setGlassB(MaterialSellmeier1 glassB)
{
	mGlass = glassB;
}

Parameter<real> ApertureStopElement::getParameterRadius()
{
	//TODO: we ask here for the radius parameters. They do not exit for a plan surface!
	// maybe we cen change that to infinity
	return mPointParamZ;
}
Parameter<real> ApertureStopElement::getParameterPositionZ()
{
	return mPointParamZ;
}

real ApertureStopElement::getRefIndexValue_A()
{
	return mRrefractiveIndex.getValue();
}
real ApertureStopElement::getRefIndexValue_B()
{
	return mRrefractiveIndex.getValue();
}

MaterialSellmeier1 ApertureStopElement::getGlassA()
{
	return mGlass;
}
MaterialSellmeier1 ApertureStopElement::getGlassB()
{
	return mGlass;
}

/*Peter*/std::shared_ptr<Element_CR> ApertureStopElement::buildElement(std::shared_ptr<SurfaceIntersectionRay_LLT> surface_LLT, MaterialSellmeier1 glassA, MaterialSellmeier1 glassB)
{
	std::shared_ptr<Element_CR> returnApertureStopElement(new ApertureStopElement);

	real semiHeight = surface_LLT->getSemiHeight();
	VectorStructR3 point = surface_LLT->getPoint();
	VectorStructR3 direction = surface_LLT->getDirection();

	// semi Height
	returnApertureStopElement->setSemiHeightElementValue(semiHeight);
	// point
	returnApertureStopElement->setPointElementValue_X(point.getX());
	returnApertureStopElement->setPointElementValue_Y(point.getY());
	returnApertureStopElement->setPointElementValue_Z(point.getZ());
	// diretion
	returnApertureStopElement->setDirectionX_value(direction.getX());
	returnApertureStopElement->setDirectionY_value(direction.getY());
	returnApertureStopElement->setDirectionZ_value(direction.getZ());
	// glass A
	returnApertureStopElement->setGlassA(glassA);
	// glass B
	returnApertureStopElement->setGlassB(glassB);

	/*Peter*/ returnApertureStopElement->setAllParameterFix();

	return returnApertureStopElement;
}

//fix all parameter
void ApertureStopElement::setAllParameterFix()
{
	mSemiHeightApertureElePara.setModifier(typeModifierFixed);

	mPointParamX.setModifier(typeModifierFixed);
	mPointParamY.setModifier(typeModifierFixed);
	mPointParamZ.setModifier(typeModifierFixed);

	mDirectionParamX.setModifier(typeModifierFixed);
	mDirectionParamY.setModifier(typeModifierFixed);
	mDirectionParamZ.setModifier(typeModifierFixed);

	mRrefractiveIndex.setModifier(typeModifierFixed);
}