#include "LensesFourSurfaces.h"

#include "..\LowLevelTracing\Interaction\RefractedRay_LLT.h"
#include "..\SurfaceElements\SphericalElement.h"

LensFourSurfaces::LensFourSurfaces() {}
LensFourSurfaces::~LensFourSurfaces() {}

void LensFourSurfaces::buildLensFourSurfaces
(
	// https://www.thorlabs.de/newgrouppage9.cfm?objectgroup_id=5370
	/*lens catalog*/ std::string lensCatalog,
	/*catalog number*/ std::string Item,
	/*diameter*/ real  diameter,
	/*focallength*/ real focalLenght,
	/*tolerance focal length */ real toleranceFocalLength,
	/*back focal length*/ real backFocalLength,
	/*working distance*/ real workingDistance,
	/*radius first surface*/ real radiusFirstSurface,
	/*radius second surface*/ real radiusSecondSurface,
	/*radius third surface*/ real radiusThirdSurface,
	/*radius tourth surface*/ real radiusFourthSurface,
	/*first thickness*/ real firstThicknessCT1,
	/*second thickness*/ real secondThicknessCT2,
	/*third thickness*/ real thirdThicknessCT3,
	/*material first*/ MaterialSellmeier1 materialFirst,
	/*material second*/ MaterialSellmeier1 materialSecond,
	/*material third*/ MaterialSellmeier1 materialThird,
	/*edge thickness*/ real edgeThickness,
	/*first design wavelength*/ real firstDesignWavelength,
	/*second design wavelength*/ real secondDesignWavelength,
	/*third design wavelength*/ real thirdDesignWavelength,
	/*free aperture CA*/ real freeApertureCA,
	/*max surface quality*/ real maxSurfaceQuality,
	/*min surface quality*/ real minSurfaceQuality,
	/*centration*/ real centration,
	/*max diameter tolerance*/ real maxDiamterTolerance,
	/*min diameter tolerance*/ real minDiamterTolerance,
	/*tolerance center thickness*/ real toleraceCenterThickness,
	/*coating*/ std::string coating,
	/*min wavelength*/ real minWavelength,
	/*max wavelength*/ real maxWavelenght,
	/*price*/ real price
)
{
	setLensCatalog(lensCatalog);
	setItem(Item);
	setDiameter(diameter);
	setFocalLength(focalLenght);
	setToleranceFocalLength(toleranceFocalLength);
	setBackFocalLength(backFocalLength);
	setWorkingDistance(workingDistance);
	setRadiusFirstSurface(radiusFirstSurface);
	setRadiusSecondSurface(radiusSecondSurface);
	setRadiusThirdSurface(radiusThirdSurface);
	setRadiusFourthSurface(radiusFourthSurface),
		setFirstThickness(firstThicknessCT1);
	setSecondThickness(secondThicknessCT2);
	setThirdThickness(thirdThicknessCT3);
	setMaterialFirst(materialFirst);
	setMaterialSecond(materialSecond);
	setMaterialThird(materialThird);
	setEdgeThickness(edgeThickness);
	setFirstDesignWavelength(firstDesignWavelength);
	setSecondDesignWavelength(secondDesignWavelength);
	setThirdDesignWavelength(thirdDesignWavelength);
	setFreeApertureCA(freeApertureCA);
	setMaxSurfaceQuality(maxSurfaceQuality);
	setMinSurfaceQuality(minSurfaceQuality);
	setCentration(centration);
	setMaxDiameterTolerance(maxDiamterTolerance);
	setMinDiameterTolerance(minDiamterTolerance);
	setToleranceCenterThickness(toleraceCenterThickness);
	setCoating(coating);
	setMinimalWavelength(minWavelength);
	setMaximumWavelength(maxWavelenght);
	setPrice(price);

	setWavelenghtToTrace(secondDesignWavelength);

	// build the optical system with three surfaces
	buildOpticalSystemFourSurfaces();
}


void LensFourSurfaces::buildLensFourSurfaces
(
	// https://www.thorlabs.de/newgrouppage9.cfm?objectgroup_id=5370
	/*lens catalog*/ std::string lensCatalog,
	/*catalog number*/ std::string Item,
	/*diameter*/ real  diameter,
	/*focallength*/ real focalLenght,
	/*tolerance focal length */ real toleranceFocalLength,
	/*back focal length*/ real backFocalLength,
	/*working distance1*/ real workingDistance1,
	/*working distance2*/ real workingDistance2,
	/*radius first surface*/ real radiusFirstSurface,
	/*radius second surface*/ real radiusSecondSurface,
	/*radius third surface*/ real radiusThirdSurface,
	/*radius tourth surface*/ real radiusFourthSurface,
	/*first thickness*/ real firstThicknessCT1,
	/*second thickness*/ real secondThicknessCT2,
	/*third thickness*/ real thirdThicknessCT3,
	/*material first*/ MaterialSellmeier1 materialFirst,
	/*material second*/ MaterialSellmeier1 materialSecond,
	/*material third*/ MaterialSellmeier1 materialThird,
	/*edge thickness*/ real edgeThickness,
	/*first design wavelength*/ real firstDesignWavelength,
	/*second design wavelength*/ real secondDesignWavelength,
	/*third design wavelength*/ real thirdDesignWavelength,
	/*free aperture CA*/ real freeApertureCA,
	/*max surface quality*/ real maxSurfaceQuality,
	/*min surface quality*/ real minSurfaceQuality,
	/*centration*/ real centration,
	/*max diameter tolerance*/ real maxDiamterTolerance,
	/*min diameter tolerance*/ real minDiamterTolerance,
	/*tolerance center thickness*/ real toleraceCenterThickness,
	/*coating*/ std::string coating,
	/*min wavelength*/ real minWavelength,
	/*max wavelength*/ real maxWavelenght,
	/*price*/ real price
)
{
	setLensCatalog(lensCatalog);
	setItem(Item);
	setDiameter(diameter);
	setFocalLength(focalLenght);
	setToleranceFocalLength(toleranceFocalLength);
	setBackFocalLength(backFocalLength);
	setWorkingDistance(workingDistance1);
	setWorkingDistance2(workingDistance2);
	setRadiusFirstSurface(radiusFirstSurface);
	setRadiusSecondSurface(radiusSecondSurface);
	setRadiusThirdSurface(radiusThirdSurface);
	setRadiusFourthSurface(radiusFourthSurface),
		setFirstThickness(firstThicknessCT1);
	setSecondThickness(secondThicknessCT2);
	setThirdThickness(thirdThicknessCT3);
	setMaterialFirst(materialFirst);
	setMaterialSecond(materialSecond);
	setMaterialThird(materialThird);
	setEdgeThickness(edgeThickness);
	setFirstDesignWavelength(firstDesignWavelength);
	setSecondDesignWavelength(secondDesignWavelength);
	setThirdDesignWavelength(thirdDesignWavelength);
	setFreeApertureCA(freeApertureCA);
	setMaxSurfaceQuality(maxSurfaceQuality);
	setMinSurfaceQuality(minSurfaceQuality);
	setCentration(centration);
	setMaxDiameterTolerance(maxDiamterTolerance);
	setMinDiameterTolerance(minDiamterTolerance);
	setToleranceCenterThickness(toleraceCenterThickness);
	setCoating(coating);
	setMinimalWavelength(minWavelength);
	setMaximumWavelength(maxWavelenght);
	setPrice(price);

	setWavelenghtToTrace(secondDesignWavelength);

	// build the optical system with three surfaces
	buildOpticalSystemFourSurfaces();
}


void LensFourSurfaces::buildLensFourSurfaces
(
	/*lens catalog*/ std::string lensCatalog,
	/*catalog number*/ real catalogNumber,
	/*diameter*/ real  diameter,
	/*max diameter tolerance*/ real maxDiameterTolerance,
	/*min diameter tolerance*/ real minDiameterTolerance,
	/* focallength*/ real focalLenght,
	/* tolerance focal length*/ real toleranceFocalLength,
	/*back focal length*/ real backFocalLength,
	/*design wavelength*/ real designWavelength,
	/*free aperture CA*/ real freeApertureCA,
	/*max centering*/ real maxCentering,
	/*first thickness*/ real firstThicknessCT1,
	/*second thickness*/ real secondThicknessCT2,
	/*third thickness*/ real thridThicknessCT3,
	/*tolerance center thickness*/ real toleraceCenterThickness,
	/*radius first surface*/ real radiusFirstSurface,
	/*radius second surface*/ real radiusSecondSurface,
	/*radius third surface*/ real radiusThirdSurface,
	/*radius fourth surface*/ real radiusFourthSurface,
	/*edge thickness*/ real edgeThickness,
	/*material first*/ MaterialSellmeier1 materialFirst,
	/*material second*/ MaterialSellmeier1 materialSecond,
	/*material third*/ MaterialSellmeier1 materialThrid,
	/*max surface quality*/ real maxSurfaceQuality,
	/*min surface quality*/ real minSurfaceQuality,
	/*F-Number*/ real F_Number,
	/*numerical aperture*/ real numericalAperture,
	/*coating*/ std::string coating,
	/*coating specification*/ real coatingtionSpecification,
	/*min wavelength coatingting*/ real minWavlengthCoating,
	/*max wavelength coatingting*/ real maxWavlengthCoating,
	/*bevel*/ std::string bevel,
	/*type*/ std::string type,
	/*min wavelength*/ real minWavelength,
	/*max wavelength*/ real maxWavelenght,
	/*price*/ real price
)
{
	setLensCatalog(lensCatalog);
	setCatalogNumber(catalogNumber);
	setDiameter(diameter);
	setMaxDiameterTolerance(maxDiameterTolerance);
	setMinDiameterTolerance(minDiameterTolerance);
	setFocalLength(focalLenght);
	setToleranceFocalLength(toleranceFocalLength);
	setBackFocalLength(backFocalLength);
	setDesignWavelength(designWavelength);
	setFreeApertureCA(freeApertureCA);
	setCentration(maxCentering);
	setFirstThickness(firstThicknessCT1);
	setSecondThickness(secondThicknessCT2);
	setThirdThickness(thridThicknessCT3);
	setToleranceCenterThickness(toleraceCenterThickness);
	setRadiusFirstSurface(radiusFirstSurface);
	setRadiusSecondSurface(radiusSecondSurface);
	setRadiusThirdSurface(radiusThirdSurface);
	setRadiusFourthSurface(radiusFourthSurface);
	setEdgeThickness(edgeThickness);
	setMaterialFirst(materialFirst);
	setMaterialSecond(materialSecond);
	setMaterialThird(materialThrid);
	setMaxSurfaceQuality(maxSurfaceQuality);
	setMinSurfaceQuality(minSurfaceQuality);
	setF_Number(F_Number);
	setNumericalAperture(numericalAperture);
	setCoating(coating);
	setCoatingSpecification(coatingtionSpecification);
	setMinWavlengthCoating(minWavlengthCoating);
	setMaxWavlengthCoating(maxWavlengthCoating);
	setBevel(bevel);
	setType(type);
	setMinimalWavelength(minWavelength);
	setMaximumWavelength(maxWavelenght);
	setPrice(price);

	// build the optical system with three surfaces
	buildOpticalSystemFourSurfaces();
}

void LensFourSurfaces::buildLensFourSurfaces
(
	/*lens catalog*/ std::string lensCatalog,
	/*catalog number*/ real catalogNumber,
	/*diameter*/ real  diameter,
	/*max diameter tolerance*/ real maxDiameterTolerance,
	/*min diameter tolerance*/ real minDiameterTolerance,
	/* focallength*/ real focalLenght,
	/* tolerance focal length*/ real toleranceFocalLength,
	/*back focal length*/ real backFocalLength,
	/*design wavelength*/ real designWavelength,
	/*max centering*/ real maxCentering,
	/*first thickness*/ real firstThicknessCT1,
	/*second thickness*/ real secondThicknessCT2,
	/*third thickness*/ real thridThicknessCT3,
	/*tolerance center thickness*/ real toleraceCenterThickness,
	/*radius first surface*/ real radiusFirstSurface,
	/*radius second surface*/ real radiusSecondSurface,
	/*radius third surface*/ real radiusThirdSurface,
	/*radius fourth surface*/ real radiusFourthSurface,
	/*edge thickness*/ real edgeThickness,
	/*material first*/ MaterialSellmeier1 materialFirst,
	/*material second*/ MaterialSellmeier1 materialSecond,
	/*material third*/ MaterialSellmeier1 materialThrid,
	/*max surface quality*/ real maxSurfaceQuality,
	/*min surface quality*/ real minSurfaceQuality,
	/*F-Number*/ real F_Number,
	/*numerical aperture*/ real numericalAperture,
	/*coating*/ std::string coating,
	/*coating specification*/ real coatingtionSpecification,
	/*min wavelength coatingting*/ real minWavlengthCoating,
	/*max wavelength coatingting*/ real maxWavlengthCoating,
	/*Power(P-V)@632.8nm*/ real powerP_V,
	/*Irregularity(P-V)@632.8nm*/ real irregularity,
	/*bevel*/ std::string bevel,
	/*type*/ std::string type,
	/*min wavelength*/ real minWavelength,
	/*max wavelength*/ real maxWavelenght,
	/*price*/ real price
)
{
	setLensCatalog(lensCatalog);
	setCatalogNumber(catalogNumber);
	setDiameter(diameter);
	setMaxDiameterTolerance(maxDiameterTolerance);
	setMinDiameterTolerance(minDiameterTolerance);
	setFocalLength(focalLenght);
	setToleranceFocalLength(toleranceFocalLength);
	setBackFocalLength(backFocalLength);
	setDesignWavelength(designWavelength);
	setCentration(maxCentering);
	setFirstThickness(firstThicknessCT1);
	setSecondThickness(secondThicknessCT2);
	setThirdThickness(thridThicknessCT3);
	setToleranceCenterThickness(toleraceCenterThickness);
	setRadiusFirstSurface(radiusFirstSurface);
	setRadiusSecondSurface(radiusSecondSurface);
	setRadiusThirdSurface(radiusThirdSurface);
	setRadiusFourthSurface(radiusFourthSurface);
	setEdgeThickness(edgeThickness);
	setMaterialFirst(materialFirst);
	setMaterialSecond(materialSecond);
	setMaterialThird(materialThrid);
	setMaxSurfaceQuality(maxSurfaceQuality);
	setMinSurfaceQuality(minSurfaceQuality);
	setF_Number(F_Number);
	setNumericalAperture(numericalAperture);
	setCoating(coating);
	setCoatingSpecification(coatingtionSpecification);
	setMinWavlengthCoating(minWavlengthCoating);
	setMaxWavlengthCoating(maxWavlengthCoating);
	setPowerPV(powerP_V);
	setIrregularityPV(irregularity);
	setBevel(bevel);
	setType(type);
	setMinimalWavelength(minWavelength);
	setMaximumWavelength(maxWavelenght);
	setPrice(price);

	// build the optical system with three surfaces
	buildOpticalSystemFourSurfaces();
}

// build the optical system wit four surfaces
void LensFourSurfaces::buildOpticalSystemFourSurfaces()
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
	// parameter third surface
	real radiusFourthSurface;
	VectorStructR3 directionFourthSurface{ 0.0,0.0,1.0 };
	real refIndex_A_FourthSurface;
	real refIndex_B_FourthSurface;
	MaterialSellmeier1 materialSellmeier_A_FourthSurface;
	MaterialSellmeier1 materialSellmeier_B_FourthSurface;


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
		refIndex_B_ThirdSurface = mMaterialThird.calcRefractiveIndexSnellmeier1(mWavelengthToTrace);
		materialSellmeier_A_ThirdSurface = mMaterialSecond;
		materialSellmeier_B_ThirdSurface = mMaterialThird;
	}

	if (mRadiusFourthSurface > 0)
	{
		radiusFourthSurface = std::abs(mRadiusFourthSurface);
		refIndex_A_FourthSurface = mMaterialThird.calcRefractiveIndexSnellmeier1(mWavelengthToTrace);
		refIndex_B_FourthSurface = refractiveIndexAir;
		materialSellmeier_A_ThirdSurface = mMaterialThird;
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
		refIndex_A_ThirdSurface = mMaterialThird.calcRefractiveIndexSnellmeier1(mWavelengthToTrace);
		refIndex_B_ThirdSurface = mMaterialSecond.calcRefractiveIndexSnellmeier1(mWavelengthToTrace);
		materialSellmeier_A_ThirdSurface = mMaterialThird;
		materialSellmeier_B_ThirdSurface = mMaterialSecond;
	}

	if (mRadiusFourthSurface < 0)
	{	// flip direction
		directionFourthSurface.setZ(-1.0);

		radiusFourthSurface = std::abs(mRadiusFourthSurface);
		refIndex_A_FourthSurface = refractiveIndexAir;
		refIndex_B_FourthSurface = mMaterialThird.calcRefractiveIndexSnellmeier1(mWavelengthToTrace);
		materialSellmeier_A_FourthSurface = materialAir;
		materialSellmeier_B_FourthSurface = mMaterialThird;
	}

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
	secondSurface.setOriginValue({ 0.0,0.0,mFirstThicknessCT1 });
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

	SphericalElement toruthSurface;
	toruthSurface.setRadiusValue(radiusFourthSurface);
	toruthSurface.setSemiHeightValue(mDiameter / 2);
	toruthSurface.setOriginValue({ 0.0,0.0,mFirstThicknessCT1 + mSecondThicknessCT2 + mThirdThicknessCT3 });
	toruthSurface.setDirectionValue(directionFourthSurface);
	toruthSurface.setRefIndexValue_A(refIndex_A_FourthSurface);
	toruthSurface.setRefIndexValue_B(refIndex_B_FourthSurface);
	toruthSurface.setGlassA(materialSellmeier_A_FourthSurface);
	toruthSurface.setGlassB(materialSellmeier_B_FourthSurface);
	toruthSurface.setAllParameterFix();
	toruthSurface.buildSurface_LLT();
	surfacePtr toruthSurface_ptr = toruthSurface.clone();

	// build the optical system
	mOptSysFourSurfaces_HLT.fillPosAndElementAndInteraction(0, firstSurface_ptr, refrac_ptr);
	mOptSysFourSurfaces_HLT.fillPosAndElementAndInteraction(1, secondSurface_ptr, refrac_ptr);
	mOptSysFourSurfaces_HLT.fillPosAndElementAndInteraction(2, thirdSurface_ptr, refrac_ptr);
	mOptSysFourSurfaces_HLT.fillPosAndElementAndInteraction(3, toruthSurface_ptr, refrac_ptr);
	mOptSysFourSurfaces_HLT.convertHLTSurfacesToLLTSurfaces();
}

// get HLT three surfaces
OpticalSystemElement LensFourSurfaces::getHLT_FourSurfaces()
{
	return mOptSysFourSurfaces_HLT;
}

// set functions
// set lens catalog
void LensFourSurfaces::setLensCatalog(std::string lensCatalog)
{
	mLensCatalog = lensCatalog;
}
// set number in catalog
void LensFourSurfaces::setCatalogNumber(unsigned int catalogNumber)
{
	mCatalogNumber = catalogNumber;
}
// set diameter
void LensFourSurfaces::setDiameter(real const diameter)
{
	mDiameter = diameter;
}
// set max diameter tolerance
void LensFourSurfaces::setMaxDiameterTolerance(real const maxDiaTolerance)
{
	mMaxDiamterTolerance = maxDiaTolerance;
}
// set min diameter tolerance
void LensFourSurfaces::setMinDiameterTolerance(real const minDiaTolerance)
{
	mMinDiamterTolerance = minDiaTolerance;
}
// set focal lenght
void LensFourSurfaces::setFocalLength(real const focalLength)
{
	mFocalLength = focalLength;
}
// set tolerance focal length
void LensFourSurfaces::setToleranceFocalLength(real const toleranceFocalLength)
{
	mToleranceFocallength = toleranceFocalLength;
}
// set back focal lenght
void LensFourSurfaces::setBackFocalLength(real const backFocalLength)
{
	mBackFocalLength = backFocalLength;
}
// set design wavelength
void LensFourSurfaces::setDesignWavelength(real const designWavelenght)
{
	mDesignWavelength = designWavelenght;
}
// set free aperture
void LensFourSurfaces::setFreeApertureCA(real const freeAperture)
{
	mFreeApertureCA = freeAperture;
}
// set min centering
void LensFourSurfaces::setMinCentering(real const minCentering)
{
	mMinCentering = minCentering;
}
// set max centering
void LensFourSurfaces::setMaxCentering(real const maxCentering)
{
	mMaxCentering = mMaxCentering;
}
// set first thickness
void LensFourSurfaces::setFirstThickness(real const firstThickness)
{
	mFirstThicknessCT1 = firstThickness;
}
// set second thickness
void LensFourSurfaces::setSecondThickness(real const secondThickness)
{
	mSecondThicknessCT2 = secondThickness;
}
// set third thickness
void LensFourSurfaces::setThirdThickness(real thirdThickness)
{
	mThirdThicknessCT3 = thirdThickness;
}
// set tolerance center Thickness
void LensFourSurfaces::setToleranceCenterThickness(real const toleranceCenterThickness)
{
	mToleraceCenterThickness = toleranceCenterThickness;
}
// set radius first surface
void LensFourSurfaces::setRadiusFirstSurface(real const radiusFirstSurface)
{
	mRadiusFirstSurface = radiusFirstSurface;
}
// set radius second surface
void LensFourSurfaces::setRadiusSecondSurface(real const radiusSecondSurface)
{
	mRadiusSecondSurface = radiusSecondSurface;
}
// set radius third surface
void LensFourSurfaces::setRadiusThirdSurface(real const radiusThirdSurface)
{
	mRadiusThirdSurface = radiusThirdSurface;
}
// set radius fourth surface
void LensFourSurfaces::setRadiusFourthSurface(real radiusFourthSurface)
{
	mRadiusFourthSurface = radiusFourthSurface;
}
// set edge thickness 
void LensFourSurfaces::setEdgeThickness(real const edgeThickness)
{
	mEdgeThickness = edgeThickness;
}
// set material first
void LensFourSurfaces::setMaterialFirst(MaterialSellmeier1 const materialFirst)
{
	mMaterialFirst = materialFirst;
}
// set material second
void LensFourSurfaces::setMaterialSecond(MaterialSellmeier1 const materialSecond)
{
	mMaterialSecond = materialSecond;
}
// set material third
void LensFourSurfaces::setMaterialThird(MaterialSellmeier1 materialThird)
{
	mMaterialThird = materialThird;
}
// set max surface quality
void LensFourSurfaces::setMaxSurfaceQuality(real const maxSurfaceQuality)
{
	mMaxSurfaceQuality = maxSurfaceQuality;
}
// set min surface quality
void LensFourSurfaces::setMinSurfaceQuality(real const minSurfaceQuality)
{
	mMinSurfaceQuality = minSurfaceQuality;
}
// set stop
void LensFourSurfaces::setStop(real const stop)
{
	mStop = stop;
}
// set numerical aperture
void LensFourSurfaces::setNumericalAperture(real const numericalAperture)
{
	mNumericalAperture = numericalAperture;
}
// set coating
void LensFourSurfaces::setCoating(std::string const coating)
{
	mCoating = coating;
}
//set coating specification
void LensFourSurfaces::setCoatingSpecification(real const coatingSpecification)
{
	mCoatingtionSpecification = coatingSpecification;
}
// set power wavelength
void LensFourSurfaces::setPowerWavelength(real const powerWave)
{
	mPowerWavelength = powerWave;
}
// set power PV
void LensFourSurfaces::setPowerPV(real const powerPV)
{
	mPowerPV = powerPV;
}
// set curvature wavelength
void LensFourSurfaces::setCurvatureWave(real const curvatureWave)
{
	mCurvatureWavelength = curvatureWave;
}
// set curvature PV
void LensFourSurfaces::setCurvaturePV(real const curvaturePV)
{
	mCurvaturePV = curvaturePV;
}
// set bevel
void LensFourSurfaces::setBevel(std::string const bevel)
{
	mBevel = bevel;
}
// set type
void LensFourSurfaces::setType(std::string const type)
{
	mType = type;
}
// set minimal wavelength
void LensFourSurfaces::setMinimalWavelength(real const minWave)
{
	mMinWavelength = minWave;
}
// set maximum wavelength
void LensFourSurfaces::setMaximumWavelength(real const maxWave)
{
	mMaxWavelenght = maxWave;
}
// set price
void LensFourSurfaces::setPrice(real const price)
{
	mPrice = price;
}
// set wavelengthToTrace
void LensFourSurfaces::setWavelenghtToTrace(real const waveToTrace)
{
	mWavelengthToTrace = waveToTrace;
}
// set item
void LensFourSurfaces::setItem(std::string item)
{
	mItem = item;
}
// set first design wavelength
void LensFourSurfaces::setFirstDesignWavelength(real firstDW)
{
	mFirstDesignWavelength = firstDW;
}
// set second design wavelength
void LensFourSurfaces::setSecondDesignWavelength(real secondDW)
{
	mSecondDesignWavelength = secondDW;
}
// set third design wavelength
void LensFourSurfaces::setThirdDesignWavelength(real thirdDW)
{
	mThirdDesignWavelength = thirdDW;
}
// set centration
void LensFourSurfaces::setCentration(real centration)
{
	mCentration = centration;
}
// working distance
void LensFourSurfaces::setWorkingDistance(real workingDistance)
{
	mWorkingDistance = workingDistance;
}
void LensFourSurfaces::setWorkingDistance2(real workingDistance)
{
	mWorkingDistance2 = workingDistance;
}

void LensFourSurfaces::setF_Number(real F_Number)
{
	mF_Number = F_Number;
}
void LensFourSurfaces::setMinWavlengthCoating(real minWavlengthCoating)
{
	mMinWavlengthCoating = minWavlengthCoating;
}
void LensFourSurfaces::setMaxWavlengthCoating(real maxWavlengthCoating)
{
	mMaxWavlengthCoating = mMaxWavlengthCoating;
}
void LensFourSurfaces::setIrregularityPV(real irregularity)
{
	mIrregularityPV = irregularity;
}

// *** *** // get functions
// get lens catalog
std::string LensFourSurfaces::getLensCatalog()
{
	return mLensCatalog;
}
// get number in catalog
unsigned int LensFourSurfaces::getCatalogNumber()
{
	return mCatalogNumber;
}
// get diameter
real LensFourSurfaces::getDiameter()
{
	return mDiameter;
}
// get max diameter tolerance
real LensFourSurfaces::getMaxDiameterTolerance()
{
	return mMaxDiamterTolerance;
}
// get min diameter tolerance
real LensFourSurfaces::getMinDiameterTolerance()
{
	return mMinDiamterTolerance;
}
// get focal lenght
real LensFourSurfaces::getFocalLength()
{
	return mFocalLength;
}
// get tolerance focal length
real LensFourSurfaces::getToleranceFocalLength()
{
	return mToleranceFocallength;
}
// get back focal lenght
real LensFourSurfaces::getBackFocalLength()
{
	return mBackFocalLength;
}
// get design wavelength
real LensFourSurfaces::getDesignWavelength()
{
	return mDesignWavelength;
}
// get free aperture
real LensFourSurfaces::getFreeAperture()
{
	return mFreeApertureCA;
}
// get min centering
real LensFourSurfaces::getMinCentering()
{
	return mMinCentering;
}
// get max centering
real LensFourSurfaces::getMaxCentering()
{
	return mMaxCentering;
}
// get first thickness
real LensFourSurfaces::getFirstThickness()
{
	return mFirstThicknessCT1;
}
// get second thickness
real LensFourSurfaces::getSecondThickness()
{
	return mSecondThicknessCT2;
}
// get third thickness
real LensFourSurfaces::getThirdThickness()
{
	return mThirdThicknessCT3;
}
// get tolerance center Thickness
real LensFourSurfaces::getToleranceCenterThickness()
{
	return mToleraceCenterThickness;
}
// get radius first surface
real LensFourSurfaces::getRadisuFirstSurface()
{
	return mRadiusFirstSurface;
}
// get radius second surface
real LensFourSurfaces::getRadisuSecondSurface()
{
	return mRadiusSecondSurface;
}
// get radius third surface
real LensFourSurfaces::getRadiusThirdSurface()
{
	return mRadiusThirdSurface;
}
// get radius fourth surface
real LensFourSurfaces::getRadiusFourthSurface()
{
	return mRadiusFourthSurface;
}
// get edge thickness 
real LensFourSurfaces::getEdgeThickness()
{
	return mEdgeThickness;
}
// get material first
MaterialSellmeier1 LensFourSurfaces::getMaterialFirst()
{
	return mMaterialFirst;
}
// get material second
MaterialSellmeier1 LensFourSurfaces::getMaterialSecond()
{
	return mMaterialSecond;
}
// get material third
MaterialSellmeier1 LensFourSurfaces::getMaterialThird()
{
	return mMaterialThird;
}
// get max surface quality
real LensFourSurfaces::getMaxSurfaceQuality()
{
	return mMaxSurfaceQuality;
}
// get min surface quality
real LensFourSurfaces::getMinSurfaceQuality()
{
	return mMinSurfaceQuality;
}
// get stop
real LensFourSurfaces::getStop()
{
	return mStop;
}
// get numerical aperture
real LensFourSurfaces::getNumericalAperture()
{
	return mNumericalAperture;
}
// get coating
std::string LensFourSurfaces::getCoating()
{
	return mCoating;
}
//get coating specification
real LensFourSurfaces::getCoatingSpecification()
{
	return mCoatingtionSpecification;
}
// get power wavelength
real LensFourSurfaces::getPowerWavelength()
{
	return mPowerWavelength;
}
// get power PV
real LensFourSurfaces::getPowerPV()
{
	return mPowerPV;
}
// get curvature wavelength
real LensFourSurfaces::getCurvatureWave()
{
	return mCurvatureWavelength;
}
// get curvature PV
real LensFourSurfaces::getCurvaturePV()
{
	return mCurvaturePV;
}
// get bevel
std::string LensFourSurfaces::getBevel()
{
	return mBevel;
}
// get type
std::string LensFourSurfaces::getType()
{
	return mType;
}
// get minimal wavelength
real LensFourSurfaces::getMinimalWavelength()
{
	return mMinWavelength;
}
// get maximum wavelength
real LensFourSurfaces::getMaximumWavelength()
{
	return mMaxWavelenght;
}
// get price
real LensFourSurfaces::getPrice()
{
	return mPrice;
}
// get wavelengthToTrace
real LensFourSurfaces::getWavelenghtToTrace()
{
	return mWavelengthToTrace;
}
// get item
std::string LensFourSurfaces::getItem()
{
	return mItem;
}

// get first design wavelength
real LensFourSurfaces::getFirstDesignWavelength()
{
	return mFirstDesignWavelength;
}
// get second design wavelength
real LensFourSurfaces::getSecondDesignWavelength()
{
	return mSecondDesignWavelength;
}
// get third design wavelength
real LensFourSurfaces::getThirdDesignWavelength()
{
	return mThirdDesignWavelength;
}
// get centration
real LensFourSurfaces::getCentration()
{
	return mCentration;
}
// get working distance
real LensFourSurfaces::getWorkingDistance()
{
	return mWorkingDistance;
}
real LensFourSurfaces::getWorkingDistance2()
{
	return mWorkingDistance2;
}


real LensFourSurfaces::getF_Number()
{
	return mF_Number;
}
real LensFourSurfaces::getMinWavlengthCoating()
{
	return mMinWavlengthCoating;
}
real LensFourSurfaces::getMaxWavlengthCoating()
{
	return mMaxWavlengthCoating;
}
real LensFourSurfaces::getIrregularityPV()
{
	return mIrregularityPV;
}