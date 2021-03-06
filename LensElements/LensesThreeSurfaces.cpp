#include "LensesThreeSurfaces.h"

#include "..\LowLevelTracing\Interaction\RefractedRay_LLT.h"
#include "..\SurfaceElements\SphericalElement.h"

LensThreeSurfaces::LensThreeSurfaces() {};
LensThreeSurfaces::~LensThreeSurfaces() {};


// set functions
// set lens catalog
void LensThreeSurfaces::setLensCatalog(std::string lensCatalog)
{
	mLensCatalog = lensCatalog;
}
// set number in catalog
void LensThreeSurfaces::setCatalogNumber(unsigned int catalogNumber)
{
	mCatalogNumber = catalogNumber;
}
// set diameter
void LensThreeSurfaces::setDiameter(real const diameter)
{
	mDiameter = diameter;
}
// set max diameter tolerance
void LensThreeSurfaces::setMaxDiameterTolerance(real const maxDiaTolerance)
{
	mMaxDiamterTolerance = maxDiaTolerance;
}
// set min diameter tolerance
void LensThreeSurfaces::setMinDiameterTolerance(real const minDiaTolerance)
{
	mMinDiamterTolerance = minDiaTolerance;
}
// set focal lenght
void LensThreeSurfaces::setFocalLength(real const focalLength)
{
	mFocalLength = focalLength;
}
// set tolerance focal length
void LensThreeSurfaces::setToleranceFocalLength(real const toleranceFocalLength)
{
	mToleranceFocallength = toleranceFocalLength;
}
// set back focal lenght
void LensThreeSurfaces::setBackFocalLength(real const backFocalLength)
{
	mBackFocalLength = backFocalLength;
}
// set design wavelength
void LensThreeSurfaces::setDesignWavelength(real const designWavelenght)
{
	mDesignWavelength = designWavelenght;
}
// set free aperture
void LensThreeSurfaces::setFreeAperture(real const freeAperture)
{
	mFreeApertureCA = freeAperture;
}
// set min centering
void LensThreeSurfaces::setMinCentering(real const minCentering)
{
	mMinCentering = minCentering;
}
// set max centering
void LensThreeSurfaces::setMaxCentering(real const maxCentering)
{
	mMaxCentering = mMaxCentering;
}
// set first thickness
void LensThreeSurfaces::setFirstThickness(real const firstThickness)
{
	mFirstThicknessCT1 = firstThickness;
}
// set second thickness
void LensThreeSurfaces::setSecondThickness(real const secondThickness)
{
	mSecondThicknessCT2 = secondThickness;
}
// set tolerance center Thickness
void LensThreeSurfaces::setToleranceCenterThickness(real const toleranceCenterThickness)
{
	mToleraceCenterThickness = toleranceCenterThickness;
}
// set radius first surface
void LensThreeSurfaces::setRadiusFirstSurface(real const radiusFirstSurface)
{
	mRadiusFirstSurface = radiusFirstSurface;
}
// set radius second surface
void LensThreeSurfaces::setRadisuSecondSurface(real const radiusSecondSurface)
{
	mRadiusSecondSurface = radiusSecondSurface;
}
// set radius third surface
void LensThreeSurfaces::setRadisuthirdSurface(real const radiusThirdSurface)
{
	mRadiusThirdSurface = radiusThirdSurface;
}
// set edge thickness 
void LensThreeSurfaces::setEdgeThickness(real const edgeThickness)
{
	mEdgeThickness = edgeThickness;
}
// set material first
void LensThreeSurfaces::setMaterialFirst(MaterialSellmeier1 const materialFirst)
{
	mMaterialFirst = materialFirst;
}
// set material second
void LensThreeSurfaces::setMaterialSecond(MaterialSellmeier1 const materialSecond)
{
	mMaterialSecond = materialSecond;
}
// set max surface quality
void LensThreeSurfaces::setMaxSurfaceQuality(real const maxSurfaceQuality)
{
	mMaxSurfaceQuality = maxSurfaceQuality;
}
// set min surface quality
void LensThreeSurfaces::setMinSurfaceQuality(real const minSurfaceQuality)
{
	mMinSurfaceQuality = minSurfaceQuality;
}
// set stop
void LensThreeSurfaces::setStop(real const stop)
{
	mStop = stop;
}
// set numerical aperture
void LensThreeSurfaces::setNumericalAperture(real const numericalAperture)
{
	mNumericalAperture = numericalAperture;
}
// set coating
void LensThreeSurfaces::setCoating(std::string const coating)
{
	mCoating = coating;
}
//set coating specification
void LensThreeSurfaces::setCoatingSpecification(real const coatingSpecification)
{
	mCoatingtionSpecification = coatingSpecification;
}
// set power wavelength
void LensThreeSurfaces::setPowerWavelength(real const powerWave)
{
	mPowerWavelength = powerWave;
}
// set power PV
void LensThreeSurfaces::setPowerPV(real const powerPV)
{
	mPowerPV = powerPV;
}
// set curvature wavelength
void LensThreeSurfaces::setCurvatureWave(real const curvatureWave)
{
	mCurvatureWavelength = curvatureWave;
}
// set curvature PV
void LensThreeSurfaces::setCurvaturePV(real const curvaturePV)
{
	mCurvaturePV = curvaturePV;
}
// set bevel
void LensThreeSurfaces::setBevel(std::string const bevel)
{
	mBevel = bevel;
}
// set type
void LensThreeSurfaces::setType(std::string const type)
{
	mType = type;
}
// set minimal wavelength
void LensThreeSurfaces::setMinimalWavelength(real const minWave)
{
	mMinWavelength = minWave;
}
// set maximum wavelength
void LensThreeSurfaces::setMaximumWavelength(real const maxWave)
{
	mMaxWavelenght = maxWave;
}
// set price
void LensThreeSurfaces::setPrice(real const price)
{
	mPrice = price;
}
// set wavelengthToTrace
void LensThreeSurfaces::setWavelenghtToTrace(real const waveToTrace)
{
	mWavelengthToTrace = waveToTrace;
}


// build an lens with three surfaces (achromat)
void LensThreeSurfaces::buildLensThreeSurfaces
(
	/*lens catalog*/ std::string lensCatalog,
	/*catalog number*/ unsigned int catalogNumber,
	/*diameter*/ real  diameter,
	/*max diameter tolerance*/ real maxDiamterTolerance,
	/*min diameter tolerance*/ real minDiamterTolerance,
	/* focallength*/ real focalLength,
	/* tolerance focal length*/ real toleranceFocalLength,
	/*back focal length*/ real backFocalLength,
	/*design wavelength*/ real designWavelength,
	/*free aperture CA*/ real freeApertureCA,
	/*min centering*/ real minCentering,
	/*max centering*/ real maxCentering,
	/*first thickness*/ real firstThicknessCT1,
	/*second thickness*/ real secondThicknessCT2,
	/*tolerance center thickness*/ real toleraceCenterThickness,
	/*radius first surface*/ real radiusFirstSurface,
	/*radius second surface*/ real radiusSecondSurface,
	/*radisu third surface*/ real radiusThirdSurface,
	/*edge thickness*/ real edgeThickness,
	/*material first*/ MaterialSellmeier1 materialFirst,
	/*material second*/ MaterialSellmeier1 materialSecond,
	/*nax surface quality*/ real maxSurfaceQuality,
	/*min surface quality*/ real minSurfaceQuality,
	/*stop*/ real stop,
	/*numerical aperture*/ real numericalAperture,
	/*coating*/ std::string coating,
	/*coating specification*/ real coatingtionSpecification,
	/*power wavelength*/ real powerWavelength,
	/*power PV*/ real powerPV,
	/*vurvature wavelength*/ real curvatureWavelength,
	/*curvature PV*/ real curvaturePV,
	/*bevel*/ std::string bevel,
	/*type*/ std::string type,
	/*min wavelength*/ real minWavelength,
	/*max wavelength*/ real maxWavelenght,
	/*price*/ real price,
	/*wavelength to trace*/ real wavelengthToTrace

)
{
	// set lens catalog
	setLensCatalog(lensCatalog);
	// set catalog number
	setCatalogNumber(catalogNumber);
	// set diameter
	setDiameter(diameter);
	// set max diameter tolerance
	setMaxDiameterTolerance(maxDiamterTolerance);
	// set min diameter tolerance
	setMinDiameterTolerance(minDiamterTolerance);
	// set focal lenght
	setFocalLength(focalLength);
	// set tolerance focal length
	setToleranceFocalLength( toleranceFocalLength);
	// set back focal lenght
	setBackFocalLength( backFocalLength);
	// set design wavelength
	setDesignWavelength(designWavelength);
	// set free aperture
	setFreeAperture(freeApertureCA);
	// set min centering
	setMinCentering( minCentering);
	// set max centering
	setMaxCentering(maxCentering);
	// set first thickness
	setFirstThickness(firstThicknessCT1);
	// set second thickness
	setSecondThickness(secondThicknessCT2);
	// set tolerance center Thickness
	setToleranceCenterThickness(toleraceCenterThickness);
	// set radius first surface
	setRadiusFirstSurface(radiusFirstSurface);
	// set radius second surface
	setRadisuSecondSurface(radiusSecondSurface);
	// set radius third surface
	setRadisuthirdSurface(radiusThirdSurface);
	// set edge thickness 
	setEdgeThickness(edgeThickness);
	// set material first
	setMaterialFirst(materialFirst);
	// set material second
	setMaterialSecond(materialSecond);
	// set max surface quality
	setMaxSurfaceQuality(maxSurfaceQuality);
	// set min surface quality
	setMinSurfaceQuality(minSurfaceQuality);
	// set stop
	setStop(stop);
	// set numerical aperture
	setNumericalAperture(numericalAperture);
	// set coating
	setCoating(coating);
	//set coating specification
	setCoatingSpecification(coatingtionSpecification);
	// set power wavelength
	setPowerWavelength(powerWavelength);
	// set power PV
	setPowerPV(powerPV);
	// set curvature wavelength
	setCurvatureWave(curvatureWavelength);
	// set curvature PV
	setCurvaturePV(curvaturePV);
	// set bevel
	setBevel(bevel);
	// set type
	setType(type);
	// set minimal wavelength
	setMinimalWavelength(minWavelength);
	// set maximum wavelength
	setMaximumWavelength(maxWavelenght);
	// set price
	setPrice(price);
	// set wavelengthToTrace
	setWavelenghtToTrace(wavelengthToTrace);

	// build the optical system with three surfaces
	buildOpticalSystemThreeSurfaces();

}

// build an optical system with three surfaces
void LensThreeSurfaces::buildOpticalSystemThreeSurfaces()
{
	MaterialSellmeier1 materialAir;
	materialAir.setParameterAndCalcVd_Ve("Schott", "Air", 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0); // refractive index is 1

	typedef std::shared_ptr< Element_CR > surfacePtr;
	RefractedRay_LLT refrac;
	std::shared_ptr<InteractionRay_LLT> refrac_ptr = refrac.clone();

	// paramenter first surface
	real radiusFirstSurface;
	VectorStructR3 directionFirstSurface{ 0.0,0.0,1.0 };
	real refIndex_A_FirstSurface;
	real refIndex_B_FirstSurface;
	MaterialSellmeier1 materialSellmeier_A_FirstSurface;
	MaterialSellmeier1 materialSellmeier_B_FirstSurface;
	// parameter second surface
	real radiusSecondSurface;
	VectorStructR3 directionSecondSurface{ 0.0,0.0,1.0 };
	real refIndex_A_SecondSurface;
	real refIndex_B_SecondSurface;
	MaterialSellmeier1 materialSellmeier_A_SecondSurface;
	MaterialSellmeier1 materialSellmeier_B_SecondSurface;
	// parameter third surface
	real radiusThirdSurface;
	VectorStructR3 directionThirdSurface{ 0.0,0.0,1.0 };
	real refIndex_A_ThirdSurface;
	real refIndex_B_ThirdSurface;
	MaterialSellmeier1 materialSellmeier_A_ThirdSurface;
	MaterialSellmeier1 materialSellmeier_B_ThirdSurface;





	if (mRadiusFirstSurface > 0)
	{
		radiusFirstSurface = std::abs(mRadiusFirstSurface);
		refIndex_A_FirstSurface = refractiveIndexAir;
		refIndex_B_FirstSurface = mMaterialFirst.calcRefractiveIndexSnellmeier1(mWavelengthToTrace);
		materialSellmeier_A_FirstSurface = materialAir;
		materialSellmeier_B_FirstSurface = mMaterialFirst;

	}

	if (mRadiusSecondSurface > 0)
	{
		radiusSecondSurface = std::abs(mRadiusSecondSurface);
		refIndex_A_SecondSurface = mMaterialFirst.calcRefractiveIndexSnellmeier1(mWavelengthToTrace);
		refIndex_B_SecondSurface = mMaterialSecond.calcRefractiveIndexSnellmeier1(mWavelengthToTrace);
		materialSellmeier_A_SecondSurface = mMaterialFirst;
		materialSellmeier_B_SecondSurface = mMaterialSecond;
	}

	if (mRadiusThirdSurface > 0)
	{
		radiusThirdSurface = std::abs(mRadiusThirdSurface);
		refIndex_A_ThirdSurface = mMaterialSecond.calcRefractiveIndexSnellmeier1(mWavelengthToTrace);
		refIndex_B_ThirdSurface = refractiveIndexAir;
		materialSellmeier_A_ThirdSurface = mMaterialSecond;
		materialSellmeier_B_ThirdSurface = materialAir;
	}

	if (mRadiusFirstSurface < 0)
	{
		// flip direction
		directionFirstSurface.setZ(-1.0);

		radiusFirstSurface = std::abs(mRadiusFirstSurface);
		refIndex_A_FirstSurface = mMaterialFirst.calcRefractiveIndexSnellmeier1(mWavelengthToTrace);
		refIndex_B_FirstSurface = refractiveIndexAir;
		materialSellmeier_A_FirstSurface = mMaterialFirst;
		materialSellmeier_B_FirstSurface = materialAir;

	}
	if (mRadiusSecondSurface < 0)
	{
		// flip direction
		directionSecondSurface.setZ(-1.0);

		radiusSecondSurface = std::abs(mRadiusSecondSurface);
		refIndex_A_SecondSurface = mMaterialSecond.calcRefractiveIndexSnellmeier1(mWavelengthToTrace);
		refIndex_B_SecondSurface = mMaterialFirst.calcRefractiveIndexSnellmeier1(mWavelengthToTrace);
		materialSellmeier_A_SecondSurface = mMaterialSecond;
		materialSellmeier_B_SecondSurface = mMaterialFirst;
	}

	if (mRadiusThirdSurface < 0)
	{	// flip direction
		directionThirdSurface.setZ(-1.0);

		radiusThirdSurface = std::abs(mRadiusThirdSurface);
		refIndex_A_ThirdSurface = refractiveIndexAir;
		refIndex_B_ThirdSurface = mMaterialSecond.calcRefractiveIndexSnellmeier1(mWavelengthToTrace);
		materialSellmeier_A_ThirdSurface = materialAir;
		materialSellmeier_B_ThirdSurface = mMaterialSecond;
	}

	//TODO: We have to fix that. Write function setRadiusValue, setSemiHeightValue,...

	// build first surface
	SphericalElement firstSurface;
	firstSurface.setRadiusValue(radiusFirstSurface);
	firstSurface.setSemiHeightValue(mDiameter / 2);
	firstSurface.setOriginValue({ 0.0,0.0,0.0 });
	firstSurface.setDirectionValue(directionFirstSurface);
	firstSurface.setRefIndexValue_A(refIndex_A_FirstSurface);
	firstSurface.setRefIndexValue_B(refIndex_B_FirstSurface);
	firstSurface.setGlassA(materialSellmeier_A_FirstSurface);	
	firstSurface.setGlassB(materialSellmeier_B_FirstSurface);	
	firstSurface.setAllParameterFix();
	firstSurface.buildSurface_LLT();
	surfacePtr firstSurface_ptr = firstSurface.clone();


	// build second surface
	SphericalElement secondSurface;
	secondSurface.setRadiusValue(radiusSecondSurface);
	secondSurface.setSemiHeightValue(mDiameter / 2);
	secondSurface.setOriginValue({ 0.0,0.0,mFirstThicknessCT1});
	secondSurface.setDirectionValue(directionSecondSurface);
	secondSurface.setRefIndexValue_A(refIndex_A_SecondSurface);
	secondSurface.setRefIndexValue_B(refIndex_B_SecondSurface);
	secondSurface.setGlassA(materialSellmeier_A_SecondSurface);
	secondSurface.setGlassB(materialSellmeier_B_SecondSurface);
	secondSurface.setAllParameterFix();
	secondSurface.buildSurface_LLT();
	surfacePtr secondSurface_ptr = secondSurface.clone();

	// build third surface
	SphericalElement thirdSurface;
	thirdSurface.setRadiusValue(radiusThirdSurface);
	thirdSurface.setSemiHeightValue(mDiameter / 2);
	thirdSurface.setOriginValue({ 0.0,0.0,mFirstThicknessCT1 + mSecondThicknessCT2 });
	thirdSurface.setDirectionValue(directionThirdSurface);
	thirdSurface.setRefIndexValue_A(refIndex_A_ThirdSurface);
	thirdSurface.setRefIndexValue_B(refIndex_B_ThirdSurface);
	thirdSurface.setGlassA(materialSellmeier_A_ThirdSurface);
	thirdSurface.setGlassB(materialSellmeier_B_ThirdSurface);
	thirdSurface.setAllParameterFix();
	thirdSurface.buildSurface_LLT();
	surfacePtr thirdSurface_ptr = thirdSurface.clone();

	// build the optical system
	mOptSysThreeSurfaces_HLT.fillPosAndElementAndInteraction(0, firstSurface_ptr, refrac_ptr);
	mOptSysThreeSurfaces_HLT.fillPosAndElementAndInteraction(1, secondSurface_ptr, refrac_ptr);
	mOptSysThreeSurfaces_HLT.fillPosAndElementAndInteraction(2, thirdSurface_ptr, refrac_ptr);
	mOptSysThreeSurfaces_HLT.convertHLTSurfacesToLLTSurfaces();

}

// get HLT three surfaces
OpticalSystemElement LensThreeSurfaces::getHLT_ThreeSurfaces()
{
	return mOptSysThreeSurfaces_HLT;
}


// *** *** // get functions

// get lens catalog
std::string LensThreeSurfaces::getLensCatalog()
{
	return mLensCatalog;
}
// get number in catalog
unsigned int LensThreeSurfaces::getCatalogNumber()
{
	return mCatalogNumber;
}
// get diameter
real LensThreeSurfaces::getDiameter()
{
	return mDiameter;
}
// get max diameter tolerance
real LensThreeSurfaces::getMaxDiameterTolerance()
{
	return mMaxDiamterTolerance;
}
// get min diameter tolerance
real LensThreeSurfaces::getMinDiameterTolerance()
{
	return mMinDiamterTolerance;
}
// get focal lenght
real LensThreeSurfaces::getFocalLength()
{
	return mFocalLength;
}
// get tolerance focal length
real LensThreeSurfaces::getToleranceFocalLength()
{
	return mToleranceFocallength;
}
// get back focal lenght
real LensThreeSurfaces::getBackFocalLength()
{
	return mBackFocalLength;
}
// get design wavelength
real LensThreeSurfaces::getDesignWavelength()
{
	return mDesignWavelength;
}
// get free aperture
real LensThreeSurfaces::getFreeAperture()
{
	return mFreeApertureCA;
}
// get min centering
real LensThreeSurfaces::getMinCentering()
{
	return mMinCentering;
}
// get max centering
real LensThreeSurfaces::getMaxCentering()
{
	return mMaxCentering;
}
// get first thickness
real LensThreeSurfaces::getFirstThickness()
{
	return mFirstThicknessCT1;
}
// get second thickness
real LensThreeSurfaces::getSecondThickness()
{
	return mSecondThicknessCT2;
}
// get tolerance center Thickness
real LensThreeSurfaces::getToleranceCenterThickness()
{
	return mToleraceCenterThickness;
}
// get radius first surface
real LensThreeSurfaces::getRadisuFirstSurface()
{
	return mRadiusFirstSurface;
}
// get radius second surface
real LensThreeSurfaces::getRadisuSecondSurface()
{
	return mRadiusSecondSurface;
}
// get radius third surface
real LensThreeSurfaces::getRadiusThirdSurface()
{
	return mRadiusThirdSurface;
}
// get edge thickness 
real LensThreeSurfaces::getEdgeThickness()
{
	return mEdgeThickness;
}
// get material first
MaterialSellmeier1 LensThreeSurfaces::getMaterialFirst()
{
	return mMaterialFirst;
}
// get material second
MaterialSellmeier1 LensThreeSurfaces::getMaterialSecond()
{
	return mMaterialSecond;
}
// get max surface quality
real LensThreeSurfaces::getMaxSurfaceQuality()
{
	return mMaxSurfaceQuality;
}
// get min surface quality
real LensThreeSurfaces::getMinSurfaceQuality()
{
	return mMinSurfaceQuality;
}
// get stop
real LensThreeSurfaces::getStop()
{
	return mStop;
}
// get numerical aperture
real LensThreeSurfaces::getNumericalAperture()
{
	return mNumericalAperture;
}
// get coating
std::string LensThreeSurfaces::getCoating()
{
	return mCoating;
}
//get coating specification
real LensThreeSurfaces::getCoatingSpecification()
{
	return mCoatingtionSpecification;
}
// get power wavelength
real LensThreeSurfaces::getPowerWavelength()
{
	return mPowerWavelength;
}
// get power PV
real LensThreeSurfaces::getPowerPV()
{
	return mPowerPV;
}
// get curvature wavelength
real LensThreeSurfaces::getCurvatureWave()
{
	return mCurvatureWavelength;
}
// get curvature PV
real LensThreeSurfaces::getCurvaturePV()
{
	return mCurvaturePV;
}
// get bevel
std::string LensThreeSurfaces::getBevel()
{
	return mBevel;
}
// get type
std::string LensThreeSurfaces::getType()
{
	return mType;
}
// get minimal wavelength
real LensThreeSurfaces::getMinimalWavelength()
{
	return mMinWavelength;
}
// get maximum wavelength
real LensThreeSurfaces::getMaximumWavelength()
{
	return mMaxWavelenght;
}
// get price
real LensThreeSurfaces::getPrice()
{
	return mPrice;
}
// get wavelengthToTrace
real LensThreeSurfaces::getWavelenghtToTrace()
{
	return mWavelengthToTrace;
}