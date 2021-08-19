#include "AsphericalElement.h"
#include <iomanip>  

AsphericalElement::AsphericalElement() {};
AsphericalElement::~AsphericalElement() {};

AsphericalElement::AsphericalElement(real const& radius, real const& semiHeight, VectorStructR3 const& point, VectorStructR3 const& direction, real refractiveSideA, real refractiveSideB, real const& conic,
	/*higher order aspheric terms*/ real const& A1, real const& A2, real const& A3, real const& A4, real const& A5, real const& A6, real const& A7, real const& A8)
{

	mRadiusAsphereParam.set(radius);
	mSemiHeightAsphereElePara.set(semiHeight);
	mRefractiveSideA_AsphereParam.set(refractiveSideA);
	mRefractiveSideB_AsphereParam.set(refractiveSideB);

	mPointParamX.set(point.getX());
	mPointParamY.set(point.getY());
	mPointParamZ.set(point.getZ());

	mDirectionParamX.set(direction.getX());
	mDirectionParamY.set(direction.getY());
	mDirectionParamZ.set(direction.getZ());


	mConic.set(conic);
	m_A1_Param.set(A);
	m_A2_Param.set(A2);
	m_A3_Param.set(A3);
	m_A4_Param.set(A4);
	m_A5_Param.set(A5);
	m_A6_Param.set(A6);
	m_A7_Param.set(A7);
	m_A8_Param.set(A8);

	buildSurface_LLT();
	setAllParameterFix();
};

AsphericalElement::AsphericalElement(real const& radius, real const& semiHeight, VectorStructR3 const& point, VectorStructR3 const& direction, MaterialSellmeier1 glassA, MaterialSellmeier1 glassB, real const& conic,
	/*higher order aspheric terms*/ real const& A1, real const& A2, real const& A3, real const& A4, real const& A5, real const& A6, real const& A7, real const& A8)
{
	mRadiusAsphereParam.set(radius);
	mSemiHeightAsphereElePara.set(semiHeight);

	mRefractiveSideA_AsphereParam.set(999);
	mRefractiveSideB_AsphereParam.set(999);

	mGlassA = glassA;
	mGlassB = glassB;


	mPointParamX.set(point.getX());
	mPointParamY.set(point.getY());
	mPointParamZ.set(point.getZ());

	mDirectionParamX.set(direction.getX());
	mDirectionParamY.set(direction.getY());
	mDirectionParamZ.set(direction.getZ());


	mConic.set(conic);
	m_A1_Param.set(A);
	m_A2_Param.set(A2);
	m_A3_Param.set(A3);
	m_A4_Param.set(A4);
	m_A5_Param.set(A5);
	m_A6_Param.set(A6);
	m_A7_Param.set(A7);
	m_A8_Param.set(A8);

	buildSurface_LLT();
	setAllParameterFix();
}

void AsphericalElement::setAllParameterFix()
{


	mRadiusAsphereParam.setModifier(typeModifierFixed);
	mSemiHeightAsphereElePara.setModifier(typeModifierFixed);


	mPointParamX.setModifier(typeModifierFixed);
	mPointParamY.setModifier(typeModifierFixed);
	mPointParamZ.setModifier(typeModifierFixed);

	mDirectionParamX.setModifier(typeModifierFixed);
	mDirectionParamY.setModifier(typeModifierFixed);
	mDirectionParamZ.setModifier(typeModifierFixed);

	mRefractiveSideA_AsphereParam.setModifier(typeModifierFixed);
	mRefractiveSideB_AsphereParam.setModifier(typeModifierFixed);
	mConic.setModifier(typeModifierFixed);
	m_A1_Param.setModifier(typeModifierFixed);
	m_A2_Param.setModifier(typeModifierFixed);
	m_A3_Param.setModifier(typeModifierFixed);
	m_A4_Param.setModifier(typeModifierFixed);
	m_A5_Param.setModifier(typeModifierFixed);
	m_A6_Param.setModifier(typeModifierFixed);
	m_A7_Param.setModifier(typeModifierFixed);
	m_A8_Param.setModifier(typeModifierFixed);
}

real AsphericalElement::getPointElementValue_Z()
{
	return mPointParamZ.getValue();
}


real AsphericalElement::getDirectionElementValue_Z()
{
	return mDirectionParamZ.getValue();
}

real AsphericalElement::getSemiHeightElementValue()
{
	return mSemiHeightAsphereElePara.getValue();
}

real AsphericalElement::fRand(real min, real max) {

	real f = (real)rand() / RAND_MAX;

	return min + f * (max - min);
}

void AsphericalElement::buildSurface_LLT()
{
	AsphericalSurface_LLT asphericalSurface_LLT;

	asphericalSurface_LLT.setRadiusAsphere(mRadiusAsphereParam.getMaximum());
	asphericalSurface_LLT.setSemiHeight(mSemiHeightAsphereElePara.getValue());


	VectorStructR3 pointR3{ mPointParamX.getValue(), mPointParamY.getValue(), mPointParamZ.getValue() };
	asphericalSurface_LLT.setPoint(pointR3);

	VectorStructR3 directionR3{ mDirectionParamX.getValue(), mDirectionParamY.getValue(), mDirectionParamZ.getValue() };
	asphericalSurface_LLT.setDirection(directionR3);

	asphericalSurface_LLT.setRefractiveIndexSide_A(mRefractiveSideA_AsphereParam.getValue());
	asphericalSurface_LLT.setRefractiveIndexSide_B(mRefractiveSideB_AsphereParam.getValue());
	asphericalSurface_LLT.setConic(mConic.getValue());
	asphericalSurface_LLT.setA1(m_A1_Param.getValue());
	asphericalSurface_LLT.setA2(m_A2_Param.getValue());
	asphericalSurface_LLT.setA3(m_A3_Param.getValue());
	asphericalSurface_LLT.setA4(m_A4_Param.getValue());
	asphericalSurface_LLT.setA5(m_A5_Param.getValue());
	asphericalSurface_LLT.setA6(m_A6_Param.getValue());
	asphericalSurface_LLT.setA7(m_A7_Param.getValue());
	asphericalSurface_LLT.setA8(m_A8_Param.getValue());

	mAsphericalSurface_LLT = asphericalSurface_LLT.clone();
}



// get pointer to surface LLT for ray tracing
std::shared_ptr<SurfaceIntersectionRay_LLT> AsphericalElement::getSurfaceForLLT_ptr()

{
	return mAsphericalSurface_LLT;
}




std::shared_ptr<Element_CR> AsphericalElement::generate_ptr()
{
	//TODO: make that function corret!!!

	std::shared_ptr<Element_CR> modAsphereElement;


	modAsphereElement->setSemiHeightElementValue(mSemiHeightAsphereElePara.getValue());
	modAsphereElement->setRadiusElementValue(mRadiusAsphereParam.getValue());

	//	modSphereElement->mRadiusParam.setModifier(mRadiusParam.getModifier());

	//getting the direction parameters for sphere
	modAsphereElement->setDirectionX_value(mDirectionParamX.getValue());
	modAsphereElement->setDirectionY_value(mDirectionParamY.getValue());
	modAsphereElement->setDirectionZ_value(mDirectionParamZ.getValue());

	//getting the point parameters from sphere
	modAsphereElement->setPointElementValue_X(mPointParamX.getValue());
	modAsphereElement->setPointElementValue_Y(mPointParamY.getValue());
	modAsphereElement->setPointElementValue_Z(mPointParamZ.getValue());

	//getting the refractive index for sphere
	modAsphereElement->setRefIndex_A_value(mRefractiveSideA_AsphereParam.getValue());
	modAsphereElement->setRefIndex_B_value(mRefractiveSideB_AsphereParam.getValue());

	//building the vectors for direction and point for the sphere now
	VectorStructR3 mPoint = { mPointParamX.getValue(),mPointParamY.getValue(),mPointParamZ.getValue() };
	VectorStructR3 mDirection = { mDirectionParamX.getValue(),mDirectionParamY.getValue(),mDirectionParamZ.getValue() };

	//getting the modifier type for the radius parameter of the sphere
	typeModifier typModeRadius = mRadiusAsphereParam.getModifier();

	//generate a random radius for the sphere
	if (typModeRadius == typeModifierVariable) {

		real maxRadius = mRadiusAsphereParam.getMaximum();
		real minRadius = mRadiusAsphereParam.getMinimum();

		real generateRadius;

		generateRadius = fRand(minRadius, maxRadius);

		modAsphereElement->setRadiusElementValue(generateRadius);

	}

	else if (typModeRadius == typeModifierFixed)
	{
		modAsphereElement->setRadiusElementValue(mRadiusAsphereParam.getValue());
	}

	typeModifier typModSemiHeight = mSemiHeightAsphereElePara.getModifier();

	//generate a random semiheight
	if (typModSemiHeight == typeModifierVariable) {

		real maxSemiHeight = mSemiHeightAsphereElePara.getMaximum();
		real minSemiHeight = mSemiHeightAsphereElePara.getMinimum();

		real generateSemiHeight;

		generateSemiHeight = fRand(minSemiHeight, maxSemiHeight);

		modAsphereElement->setSemiHeightElementValue(generateSemiHeight);

	}

	else if (typModSemiHeight == typeModifierFixed)
	{
		modAsphereElement->setSemiHeightElementValue(mSemiHeightAsphereElePara.getValue());
	}

	//mPointParamZ.setModifier(typeModifierVariable);
	typeModifier typPoint = mPointParamZ.getModifier();

	if (typPoint == typeModifierVariable) {
		real generatePointZ = fRand(mPointParamZ.getMinimum(), mPointParamZ.getMaximum());
		modAsphereElement->setPointElementValue_Z(generatePointZ);
	}
	else if (typPoint == typeModifierFixed) {
		modAsphereElement->setPointElementValue_Z(mPointParamZ.getValue());
	}

	modAsphereElement->setParameterSemiHeight(mSemiHeightAsphereElePara.getMinimum(), mSemiHeightAsphereElePara.getMaximum(), mSemiHeightAsphereElePara.getStdDev(), mSemiHeightAsphereElePara.getModifier());

	modAsphereElement->setParameterRadius(mRadiusAsphereParam.getMinimum(), mRadiusAsphereParam.getMaximum(), mRadiusAsphereParam.getStdDev(), mRadiusAsphereParam.getModifier());

	modAsphereElement->setParameterPointX(mPointParamX.getMinimum(), mPointParamX.getMaximum(), mPointParamX.getStdDev(), mPointParamX.getModifier());

	modAsphereElement->setParameterPointY(mPointParamY.getMinimum(), mPointParamY.getMaximum(), mPointParamY.getStdDev(), mPointParamY.getModifier());

	modAsphereElement->setParameterPointZ(mPointParamZ.getMinimum(), mPointParamZ.getMaximum(), mPointParamZ.getStdDev(), mPointParamZ.getModifier());

	//randomizing the asphere parameters

	real lowerLimit = -1.0;
	real upperLimit = 1.0;

	m_A1_Param.set(fRand(lowerLimit, upperLimit));
	m_A2_Param.set(fRand(lowerLimit, upperLimit));
	m_A3_Param.set(fRand(lowerLimit, upperLimit));
	m_A4_Param.set(fRand(lowerLimit, upperLimit));
	m_A5_Param.set(fRand(lowerLimit, upperLimit));
	m_A6_Param.set(fRand(lowerLimit, upperLimit));
	m_A7_Param.set(fRand(lowerLimit, upperLimit));
	m_A8_Param.set(fRand(lowerLimit, upperLimit));

	modAsphereElement->buildSurface_LLT();
	return modAsphereElement;


}

void AsphericalElement::setParameterRadius(real min, real max, real stdDev, typeModifier modi)
{

	mRadiusAsphereParam.setMinimum(min);
	mRadiusAsphereParam.setMaximum(max);
	mRadiusAsphereParam.setStdDev(stdDev);
	mRadiusAsphereParam.setModifier(modi);

}

void AsphericalElement::setParameterRadiusValue(real radius)
{
	mRadiusAsphereParam.set(radius);
}

void AsphericalElement::setSemiHeight(real min, real max, real stdDev, typeModifier modi)
{
	mSemiHeightAsphereElePara.setMinimum(min);
	mSemiHeightAsphereElePara.setMaximum(max);
	mSemiHeightAsphereElePara.setStdDev(stdDev);
	mSemiHeightAsphereElePara.setModifier(modi);

}

void AsphericalElement::setSemiHeigtEleValue(real semiHeight)
{
	mSemiHeightAsphereElePara.set(semiHeight);
}

void AsphericalElement::setPointZ(real min, real max, real stdDev, typeModifier modi)
{
	mPointParamZ.setMinimum(min);
	mPointParamZ.setMaximum(max);
	mPointParamZ.setStdDev(stdDev);
	mPointParamZ.setModifier(modi);

}



real AsphericalElement::minPosValue_Z() {
	return mPointParamZ.getMinimum();
}
real AsphericalElement::maxPosValue_Z() {
	return mPointParamZ.getMaximum();
}




void AsphericalElement::pushPosition(real push) {
	mPointParamZ.set(mPointParamZ.getValue() + push);
	buildSurface_LLT();
}

void AsphericalElement::print()
{
	std::cout << "Spherical Element" << "\n";
	std::cout << "Semi-Height : " << std::setprecision(10) << mSemiHeightAsphereElePara.getValue() << "\n";
	std::cout << "Radius : " << std::setprecision(10) << mRadiusAsphereParam.getValue() << "\n";
	std::cout << "Position on optical axis : " << std::setprecision(10) << mPointParamZ.getValue() << "\n";

}

//void AsphericalElement::localOptimization_semiheight(real step) {
//
//	if (mSemiHeightAsphereElePara.getModifier() == typeModifierVariable) {
//		if ((mSemiHeightAsphereElePara.getValue() + step) <= mSemiHeightAsphereElePara.getMaximum()) {
//			mSemiHeightAsphereElePara.set(mSemiHeightAsphereElePara.getValue() + step);
//			buildSurface_LLT();
//		}
//	}
//
//}



void AsphericalElement::localOptimization_radius(real step) {

	if (mRadiusAsphereParam.getModifier() == typeModifierVariable)
	{
		if ((mRadiusAsphereParam.getValue() + step) <= mRadiusAsphereParam.getMaximum()) {
			mRadiusAsphereParam.set(mRadiusAsphereParam.getValue() + step);
			buildSurface_LLT();
		}
	}

}

void AsphericalElement::localOptimization_position(real step) {

	if (mPointParamZ.getModifier() == typeModifierVariable) {
		if ((mPointParamZ.getValue() + step) <= mPointParamZ.getMaximum()) {
			mPointParamZ.set(mPointParamZ.getValue() + step);
			buildSurface_LLT();
		}
	}

}


std::shared_ptr<Element_CR> AsphericalElement::crossover_ptr(std::shared_ptr<Element_CR> A, std::shared_ptr<Element_CR> B)
{
	//AsphericalElement* crossA = dynamic_cast<AsphericalElement*>(A);
	//AsphericalElement* crossB = dynamic_cast<AsphericalElement*>(B);

	std::shared_ptr<Element_CR> crossNewAsphere;
	crossNewAsphere = getDeepCopyElement_ptr(A);

	unsigned int chanceRadius = rand() % 10 + 1;
	unsigned int chanceSemiheight = rand() % 10 + 1;
	unsigned int chancePosition = rand() % 10 + 1;

	if (chanceSemiheight > 5) {
		crossNewAsphere->setSemiHeightElementValue(B->getSemiHeightElementValue());
	}

	if (chanceRadius > 5) {
		crossNewAsphere->setRadiusElementValue(B->getRadiusElementValue());
	}
	if (chancePosition > 5) {
		crossNewAsphere->setPointElementValue_Z(B->getPointElementValue_Z());
	}

	crossNewAsphere->buildSurface_LLT();
	return crossNewAsphere;
}

// get direction type modifier
typeModifier AsphericalElement::getDirectionTypeModifier_Z()
{
	return mDirectionParamZ.getModifier();
}

// get point type modifier
typeModifier AsphericalElement::getPointTypeModifier_Z()
{
	return mPointParamZ.getModifier();
}

real AsphericalElement::getRadiusElementValue()
{
	return mRadiusAsphereParam.getValue();
}

typeModifier AsphericalElement::getRadiusTypeModifier()
{
	return mRadiusAsphereParam.getModifier();
}

std::shared_ptr<Element_CR> AsphericalElement::getDeepCopyElement_ptr(std::shared_ptr<Element_CR> element)
{

	std::shared_ptr<Element_CR> deepCopySphereEle = element->clone();
	return deepCopySphereEle;
}

void AsphericalElement::setRadiusElementValue(real Radius)
{
	mRadiusAsphereParam.set(Radius);
}

void AsphericalElement::setSemiHeightElementValue(real semiHeight)
{
	mSemiHeightAsphereElePara.set(semiHeight);
}

void AsphericalElement::setParameterSemiHeight(real min, real max, real stdDev, typeModifier typeMode)
{
	mSemiHeightAsphereElePara.setMinimum(min);
	mSemiHeightAsphereElePara.setMaximum(max);
	mSemiHeightAsphereElePara.setStdDev(stdDev);
	mSemiHeightAsphereElePara.setModifier(typeMode);
}


void AsphericalElement::setParameterPointZ(real min, real max, real stdDev, typeModifier typeMode)
{
	mPointParamZ.setMinimum(min);
	mPointParamZ.setMaximum(max);
	mPointParamZ.setStdDev(stdDev);
	mPointParamZ.setModifier(typeMode);
}

void AsphericalElement::setParameterDirectionX(real min, real max, real stdDev, typeModifier typeMode)
{
	mDirectionParamX.setMinimum(min);
	mDirectionParamX.setMaximum(max);
	mDirectionParamX.setStdDev(stdDev);
	mDirectionParamX.setModifier(typeMode);
}

void AsphericalElement::setParameterDirectionY(real min, real max, real stdDev, typeModifier typeMode)
{
	mDirectionParamY.setMinimum(min);
	mDirectionParamY.setMaximum(max);
	mDirectionParamY.setStdDev(stdDev);
	mDirectionParamY.setModifier(typeMode);
}

void AsphericalElement::setParameterDirectionZ(real min, real max, real stdDev, typeModifier typeMode)
{
	mDirectionParamZ.setMinimum(min);
	mDirectionParamZ.setMaximum(max);
	mDirectionParamZ.setStdDev(stdDev);
	mDirectionParamZ.setModifier(typeMode);
}

void AsphericalElement::setParameterPointX(real min, real max, real stdDev, typeModifier typeMode)
{
	mPointParamX.setMinimum(min);
	mPointParamX.setMaximum(max);
	mPointParamX.setStdDev(stdDev);
	mPointParamX.setModifier(typeMode);
}

void AsphericalElement::setParameterPointY(real min, real max, real stdDev, typeModifier typeMode)
{
	mPointParamY.setMinimum(min);
	mPointParamY.setMaximum(max);
	mPointParamY.setStdDev(stdDev);
	mPointParamY.setModifier(typeMode);

}


void AsphericalElement::setRefIndex_A_value(real refIndexA)
{
	mRefractiveSideA_AsphereParam.set(refIndexA);
}
void AsphericalElement::setRefIndex_B_value(real refIndexB)
{
	mRefractiveSideB_AsphereParam.set(refIndexB);
}

void AsphericalElement::setDirectionX_value(real directionX)
{
	mDirectionParamX.set(directionX);
}
void AsphericalElement::setDirectionY_value(real directionY)
{
	mDirectionParamY.set(directionY);
}
void AsphericalElement::setDirectionZ_value(real directionZ)
{
	mDirectionParamZ.set(directionZ);
}

void AsphericalElement::setPointElementValue_X(real pointX)
{
	mPointParamX.set(pointX);
}
void AsphericalElement::setPointElementValue_Y(real pointY)
{
	mPointParamY.set(pointY);
}
void AsphericalElement::setPointElementValue_Z(real pointZ)
{
	mPointParamZ.set(pointZ);
}

AsphericalElement::AsphericalElement(AsphericalElement &source)
{
	if (this == &source)
	{
		return;
	}

	mAsphericalSurface_LLT = source.mAsphericalSurface_LLT;

	mRefraction_LLT = source.mRefraction_LLT;

	mRadiusAsphereParam = source.mRadiusAsphereParam;
	mSemiHeightAsphereElePara = source.mSemiHeightAsphereElePara;

	mPointParamX = source.mPointParamX;
	mPointParamY = source.mPointParamY;
	mPointParamZ = source.mPointParamZ;

	mDirectionParamX = source.mDirectionParamX;
	mDirectionParamY = source.mDirectionParamY;
	mDirectionParamZ = source.mDirectionParamZ;

	mRefractiveSideA_AsphereParam = source.mRefractiveSideA_AsphereParam;
	mRefractiveSideB_AsphereParam = source.mRefractiveSideB_AsphereParam;
	mConic = source.mConic;
	m_A1_Param = source.m_A1_Param;
	m_A2_Param = source.m_A2_Param;
	m_A3_Param = source.m_A3_Param;
	m_A4_Param = source.m_A4_Param;
	m_A5_Param = source.m_A5_Param;
	m_A6_Param = source.m_A6_Param;
	m_A7_Param = source.m_A7_Param;
	m_A8_Param = source.m_A8_Param;

	mGlassA = source.mGlassA;
	mGlassB = source.mGlassB;
}

std::shared_ptr<Element_CR> AsphericalElement::clone()
{
	std::shared_ptr<Element_CR> element(new AsphericalElement(*this));

	return element;

}

AsphericalElement& AsphericalElement::operator=(AsphericalElement& source)
{
	if (this == &source)
	{
		return *this;
	}

	mAsphericalSurface_LLT = source.mAsphericalSurface_LLT;

	mRefraction_LLT = source.mRefraction_LLT;

	mRadiusAsphereParam = source.mRadiusAsphereParam;
	mSemiHeightAsphereElePara = source.mSemiHeightAsphereElePara;

	mPointParamX = source.mPointParamX;
	mPointParamY = source.mPointParamY;
	mPointParamZ = source.mPointParamZ;

	mDirectionParamX = source.mDirectionParamX;
	mDirectionParamY = source.mDirectionParamY;
	mDirectionParamZ = source.mDirectionParamZ;

	mRefractiveSideA_AsphereParam = source.mRefractiveSideA_AsphereParam;
	mRefractiveSideB_AsphereParam = source.mRefractiveSideB_AsphereParam;
	mConic = source.mConic;
	m_A1_Param = source.m_A1_Param;
	m_A2_Param = source.m_A2_Param;
	m_A3_Param = source.m_A3_Param;
	m_A4_Param = source.m_A4_Param;
	m_A5_Param = source.m_A5_Param;
	m_A6_Param = source.m_A6_Param;
	m_A7_Param = source.m_A7_Param;
	m_A8_Param = source.m_A8_Param;

	mGlassA = source.mGlassA;
	mGlassB = source.mGlassB;

	return *this;
}

// calculate refractive index side A
void AsphericalElement::calcRefIndex_A_andSet(real wavelength)
{
	std::shared_ptr<SurfaceIntersectionRay_LLT> modAsphere(new AsphericalSurface_LLT);
	modAsphere = mAsphericalSurface_LLT;
	
	real temRefIndex_A{};

	if (mGlassA.getRealGlass())
	{
		mGlassA.setRefractiveIndex(mAsphericalSurface_LLT->getRefractiveIndex_A());
		temRefIndex_A = mGlassA.calcRefractiveIndexSnellmeier1(wavelength);
		mRefractiveSideA_AsphereParam.set(temRefIndex_A);
	}
	else
	{
		temRefIndex_A = mGlassA.getRefractivIndex();
		mRefractiveSideA_AsphereParam.set(temRefIndex_A);
	}


	modAsphere->setRefractiveIndexSide_A(mRefractiveSideA_AsphereParam.getValue());
	mAsphericalSurface_LLT = modAsphere;
}

// calculate rearactive index side B
void AsphericalElement::calcRefIndex_B_andSet(real wavelength)
{
	std::shared_ptr<SurfaceIntersectionRay_LLT> modAsphere(new AsphericalSurface_LLT);
	modAsphere = mAsphericalSurface_LLT;
	
	real tempRefIndexB{};

	if (mGlassB.getRealGlass())
	{
		mGlassB.setRefractiveIndex(mAsphericalSurface_LLT->getRefractiveIndex_B());
		tempRefIndexB = mGlassB.calcRefractiveIndexSnellmeier1(wavelength);
		mRefractiveSideB_AsphereParam.set(tempRefIndexB);
	}
	else
	{
		tempRefIndexB = mGlassB.getRefractivIndex();
		mRefractiveSideB_AsphereParam.set(tempRefIndexB);
	}

	modAsphere->setRefractiveIndexSide_B(mRefractiveSideB_AsphereParam.getValue());

	mAsphericalSurface_LLT = modAsphere;
}

// calculate refractive indexes side A and B
void AsphericalElement::calRefIndex_A_and_B_andSet(real wavelength)
{
	calcRefIndex_A_andSet(wavelength);
	calcRefIndex_B_andSet(wavelength);
}

void AsphericalElement::setGlassA(MaterialSellmeier1 glassA)
{
	mGlassA = glassA;
}
void AsphericalElement::setGlassB(MaterialSellmeier1 glassB)
{
	mGlassB = glassB;
}

Parameter<real> AsphericalElement::getParameterRadius()
{
	return mRadiusAsphereParam;
}
Parameter<real> AsphericalElement::getParameterPositionZ()
{
	return mPointParamZ;
}

real AsphericalElement::getRefIndexValue_A()
{
	return mRefractiveSideA_AsphereParam.getValue();
}
real AsphericalElement::getRefIndexValue_B()
{
	return mRefractiveSideB_AsphereParam.getValue();
}

MaterialSellmeier1 AsphericalElement::getGlassA()
{
	return mGlassA;
}
MaterialSellmeier1 AsphericalElement::getGlassB()
{
	return mGlassB;
}

/*Peter*/std::shared_ptr<Element_CR> AsphericalElement::buildElement(std::shared_ptr<SurfaceIntersectionRay_LLT> surface_LLT, MaterialSellmeier1 glassA, MaterialSellmeier1 glassB)
{
	std::shared_ptr<Element_CR> returnAsphericalElement(new AsphericalElement);

	real radius = surface_LLT->getRadius();
	real semiHeight = surface_LLT->getSemiHeight();
	VectorStructR3 point = surface_LLT->getPoint();
	VectorStructR3 direction = surface_LLT->getDirection();

	// radius
	returnAsphericalElement->setRadiusElementValue(radius);
	// semi Height
	returnAsphericalElement->setSemiHeightElementValue(semiHeight);
	// point
	returnAsphericalElement->setPointElementValue_X(point.getX());
	returnAsphericalElement->setPointElementValue_Y(point.getY());
	returnAsphericalElement->setPointElementValue_Z(point.getZ());
	// diretion
	returnAsphericalElement->setDirectionX_value(direction.getX());
	returnAsphericalElement->setDirectionY_value(direction.getY());
	returnAsphericalElement->setDirectionZ_value(direction.getZ());
	// glass A
	returnAsphericalElement->setGlassA(glassA);
	// glass B
	returnAsphericalElement->setGlassB(glassB);

	/*Peter*/ returnAsphericalElement->setAllParameterFix();

	return returnAsphericalElement;

}

std::string AsphericalElement::getSurfaceType()
{
	return "Aspherical";
}