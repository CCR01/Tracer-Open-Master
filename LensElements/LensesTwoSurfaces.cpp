#include "LensesTwoSurfaces.h"
#include "..\LowLevelTracing\Interaction\RefractedRay_LLT.h"
#include "..\SurfaceElements\SphericalElement.h"
#include "..\SurfaceElements\PlanElement.h"

LensesTwoSurfaces::LensesTwoSurfaces() {};
LensesTwoSurfaces::~LensesTwoSurfaces() {};



// build lens with two surfaces
void LensesTwoSurfaces::buildLensTwoSurfaces_DCX //https://www.edmundoptics.de/f/vis-nir-coated-double-convex-dcx-lenses/13504/
(
	/*lens catalog*/ std::string lensCatalog,
	/*catalog number*/ unsigned int catalogNumber,
	/*diameter*/ real const diameter,
	/*max tolerance diameter*/ real const maxDiamterTolerance,
	/*min tolerance diameter*/ real const minDiamterTolerance,
	/*focal length*/ real const focalLength,
	/*max surface quality*/ real const maxSurfaceQuality,
	/*min surface quality*/ real const minSurfaceQuality,
	/*curvature (P-V)*/ real const curvaturePV,
	/*tolerance center thickness*/ real const toleraceCenterThickness,
	/*radius first surface*/ real const radiusFirstSurface,
	/*radius second surface*/ real const radiusSecondSurface,
	/*tolerance focal lenght*/ real const toleranceFocalLenght,
	/*min wavelength range*/ real const minWavelength,
	/*max wavelength range*/ real const maxWavelength,
	/*back focal length*/ real const backFocalLength,
	/*Coating*/ std::string const coating,
	/*material*/ MaterialSellmeier1 const material,
	/*power (P-V)*/ real const powerPV,
	/*min centering*/ real const minCenter,
	/*max centering*/ real const maxCenter,
	/*center thickness*/ real const thickness,
	/*edge thickness*/ real const edgeThickness,
	/*free aperture CA*/ real const freeAperture,
	/*design wavelength*/ real const designWavelength,
	/*numerical Aperture*/ real const numericalAperture,
	/*price*/ real const price,
	/*wavelength to trace through optical system*/ real const wavelenghtToTrace)
{
	// set lens catalog
	setLensCatalog(lensCatalog);
	// set catalog number
	setCatalogNumber(catalogNumber);
	// set diameter
	setDiameter(diameter);
	// set max diametertolerance
	setMaxDiaTolerance(maxDiamterTolerance);
	// set min diameter tolerance
	setMinDiaTolerance(minDiamterTolerance);
	// set focal Lenght
	setFocalLength(focalLength);
	// set real max surface quality 
	setMaxSurfaceQuality(maxSurfaceQuality);
	// set real min surface quality 
	setMinSurfaceQuality(minSurfaceQuality);
	// set curvature PV
	setCurvaturePV(curvaturePV);
	// set tolerance center thickness
	setToleranceCenterThickness(toleraceCenterThickness);
	// set radius first surface
	setRadiusFirstSurface(radiusFirstSurface);
	// set radius second surface
	setRadiusSecondSurface(radiusSecondSurface);
	// tolerance focal length
	setToleranceFocallength(toleranceFocalLenght);
	// set min wavelength
	setMinWavelength(minWavelength);
	// set max wavelength
	setMaxWavelength(maxWavelength);
	// set back focal length
	setBackFocalLength(backFocalLength);
	// set coating
	setCoating(coating);
	// set material
	setMaterial(material);
	// set power PV
	setPowerPV(powerPV);
	// set min center
	setMinCenter(minCenter);
	// set max center
	setMaxCenter(maxCenter);
	// set thickness
	setThickness(thickness);
	// set edge thickness
	setEdgeThickness(edgeThickness);
	// set free aperture
	setFreeAperture(freeAperture);
	// set design wavelength
	setDesignWavelength(designWavelength);
	// set numerical aperture
	setNumericalAperture(numericalAperture);
	// set price
	setPrice(price);
	// set wavelength to trace
	setWavelengthToTrace(wavelenghtToTrace);

	// build the optical system with two surfaces
	buildOpticalSystemTwoSurfaces();

};

void LensesTwoSurfaces::buildLensTwoSurfaces_PCX( //https://www.edmundoptics.de/f/vis-nir-coated-plano-convex-pcx-lenses/12278/

	/*lens catalog*/ std::string lensCatalog,
	/*catalog number*/ unsigned int catalogNumber,
	/*diameter*/ real const diameter,
	/*max tolerance diameter*/ real const maxDiamterTolerance,
	/*min tolerance diameter*/ real const minDiamterTolerance,
	/*back focal length*/ real const backFocalLength,
	/*max surface quality*/ real const maxSurfaceQuality,
	/*min surface quality*/ real const minSurfaceQuality,
	/*curvature (P-V)*/ real const curvaturePV,
	/*min centering*/ real const minCenter,
	/*max centering*/ real const maxCenter,
	/*tolerance center thickness*/ real const toleraceCenterThickness,
	/*radius first surface*/ real const radiusFirstSurface,
	/*design wavelength*/ real const designWavelength,
	/*min wavelength range*/ real const minWavelength,
	/*max wavelength range*/ real const maxWavelength,
	/*focal length*/ real const focalLength,
	/*Coating*/ std::string const coating,
	/*material*/ MaterialSellmeier1 const material,
	/*power (P-V)*/ real const powerPV,
	/*tolerance focal lenght*/ real const toleranceFocalLenght,
	/*center thickness*/ real const thickness,
	/*edge thickness*/ real const edgeThickness,
	/*free aperture CA*/ real const freeAperture,
	/*numerical Aperture*/ real const numericalAperture,
	/*price*/ real const price,
	/*wavelength to trace through optical system*/ real const wavelenghtToTrace)
{
	// set lens catalog
	setLensCatalog(lensCatalog);
	// set catalog number
	setCatalogNumber(catalogNumber);
	// set diameter
	setDiameter(diameter);
	// set max diametertolerance
	setMaxDiaTolerance(maxDiamterTolerance);
	// set min diameter tolerance
	setMinDiaTolerance(minDiamterTolerance);
	// set real max surface quality 
	setMaxSurfaceQuality(maxSurfaceQuality);
	// set real min surface quality 
	setMinSurfaceQuality(minSurfaceQuality);
	// set back focel length
	setBackFocalLength(backFocalLength);
	// set curvature PV
	setCurvaturePV(curvaturePV);
	// set tolerance center thickness
	setToleranceCenterThickness(toleraceCenterThickness);
	// set radius first surface
	setRadiusFirstSurface(radiusFirstSurface);
	// set radius second surface
	setRadiusSecondSurface(std::numeric_limits<double>::quiet_NaN());
	// tolerance focal length
	setToleranceFocallength(toleranceFocalLenght);
	// set min wavelength
	setMinWavelength(minWavelength);
	// set max wavelength
	setMaxWavelength(maxWavelength);
	// set focal Lenght
	setFocalLength(focalLength);
	// set coating
	setCoating(coating);
	// set material
	setMaterial(material);
	// set power PV
	setPowerPV(powerPV);
	// set min center
	setMinCenter(minCenter);
	// set max center
	setMaxCenter(maxCenter);
	// set thickness
	setThickness(thickness);
	// set edge thickness
	setEdgeThickness(edgeThickness);
	// set free aperture
	setFreeAperture(freeAperture);
	// set design wavelength
	setDesignWavelength(designWavelength);
	// set numerical aperture
	setNumericalAperture(numericalAperture);
	// set price
	setPrice(price);
	// set wavelength to trace
	setWavelengthToTrace(wavelenghtToTrace);

	// build the optical system with two surfaces
	buildOpticalSystemTwoSurfaces_OneSurfacePlan();
}

void LensesTwoSurfaces::buildLensTwoSurfaces_DCV
(
	/*lens catalog*/ std::string lensCatalog,
	/*catalog number*/ unsigned int catalogNumber,
	/*diameter*/ real const diameter,
	/*max tolerance diameter*/ real const maxDiamterTolerance,
	/*min tolerance diameter*/ real const minDiamterTolerance,
	/*back focal length*/ real const backFocalLength,
	/*max surface quality*/ real const maxSurfaceQuality,
	/*min surface quality*/ real const minSurfaceQuality,
	/*curvature (P-V)*/ real const curvaturePV,
	/*center thickness*/ real const thickness,
	/*Centering (arc minutes)*/ real const centering,
	/*edge thickness*/ real const edgeThickness,
	/*design wavelength*/ real const designWavelength,
	/*numerical Aperture*/ real const numericalAperture,
	/*min wavelength range*/ real const minWavelength,
	/*max wavelength range*/ real const maxWavelength,
	/*focal length*/ real const focalLength,
	/*Coating*/ std::string const coating,
	/*material*/ MaterialSellmeier1 const material,
	/*power (P-V)*/ real const powerPV,
	/*free aperture CA*/ real const freeAperture,
	/*tolerance center thickness*/ real const toleraceCenterThickness,
	/*tolerance focal lenght*/ real const toleranceFocalLenght,
	/*radius*/ real const radius,
	/*price*/ real const price,
	/*wavelength to trace through optical system*/ real const wavelenghtToTrace
)
{
	// set lens catalog
	setLensCatalog(lensCatalog);
	// set catalog number
	setCatalogNumber(catalogNumber);
	// set diameter
	setDiameter(diameter);
	// set max diametertolerance
	setMaxDiaTolerance(maxDiamterTolerance);
	// set min diameter tolerance
	setMinDiaTolerance(minDiamterTolerance);
	// set real max surface quality 
	setMaxSurfaceQuality(maxSurfaceQuality);
	// set back focel length
	setBackFocalLength(backFocalLength);
	// set real min surface quality 
	setMinSurfaceQuality(minSurfaceQuality);
	// set curvature PV
	setCurvaturePV(curvaturePV);
	// set thickness
	setThickness(thickness);
	// set Centering (arc minutes)
	setCentering(centering),
	// set edge thickness
	setEdgeThickness(edgeThickness);
	// set design wavelength
	setDesignWavelength(designWavelength);
	// set numerical aperture
	setNumericalAperture(numericalAperture);
	// set min wavelength
	setMinWavelength(minWavelength);
	// set max wavelength
	setMaxWavelength(maxWavelength);
	// set focal length
	setFocalLength(focalLength);
	// set coating
	setCoating(coating);
	// set material
	setMaterial(material);
	// set power PV
	setPowerPV(powerPV);
	// set free aperture
	setFreeAperture(freeAperture);
	// set tolerance center thickness
	setToleranceCenterThickness(toleraceCenterThickness);
	// tolerance focal length
	setToleranceFocallength(toleranceFocalLenght);
	// set radius first surface
	setRadiusFirstSurface(radius);
	// set radius second surface
	setRadiusSecondSurface(-radius);
	// set price
	setPrice(price);
	// set wavelength to trace
	setWavelengthToTrace(wavelenghtToTrace);

	// build the optical system with two surfaces
	buildOpticalSystemTwoSurfaces();

}

	void LensesTwoSurfaces::buildLensTwoSurfaces_PCV // https://www.edmundoptics.de/f/vis-nir-coated-plano-concave-pcv-lenses/13512/
	(
		/*lens catalog*/ std::string lensCatalog,
		/*catalog number*/ unsigned int catalogNumber,
		/*diameter*/ real const diameter,
		/*max tolerance diameter*/ real const maxDiamterTolerance,
		/*min tolerance diameter*/ real const minDiamterTolerance,
		/*back focal length*/ real const backFocalLength,
		/*max surface quality*/ real const maxSurfaceQuality,
		/*min surface quality*/ real const minSurfaceQuality,
		/*irregularity */ real const curvaturePV,
		/*tolerance center thickness*/ real const toleraceCenterThickness,
		/*design wavelength*/ real const designWavelength,
		/*free aperture CA*/ real const freeAperture,
		/*radius*/ real const radius,
		/*numerical Aperture*/ real const numericalAperture,
		/*min wavelength range*/ real const minWavelength,
		/*max wavelength range*/ real const maxWavelength,
		/*focal length*/ real const focalLength,
		/*Coating*/ std::string const coating,
		/*material*/ MaterialSellmeier1 const material,
		/*power (P-V)*/ real const powerPV,
		/*center thickness*/ real const thickness,
		/*tolerance focal lenght*/ real const toleranceFocalLenght,
		/*Centering (arc minutes)*/ real const centering,
		/*edge thickness*/ real const edgeThickness,
		/*price*/ real const price,
		/*wavelength to trace through optical system*/ real const wavelenghtToTrace
	)
	{
		// set lens catalog
		setLensCatalog(lensCatalog);
		// set catalog number
		setCatalogNumber(catalogNumber);
		// set diameter
		setDiameter(diameter);
		// set max diametertolerance
		setMaxDiaTolerance(maxDiamterTolerance);
		// set min diameter tolerance
		setMinDiaTolerance(minDiamterTolerance);
		// set back focel length
		setBackFocalLength(backFocalLength);
		// set real max surface quality 
		setMaxSurfaceQuality(maxSurfaceQuality);
		// set real min surface quality 
		setMinSurfaceQuality(minSurfaceQuality);
		// set curvature PV
		setCurvaturePV(curvaturePV);
		// set tolerance center thickness
		setToleranceCenterThickness(toleraceCenterThickness);
		// set design wavelength
		setDesignWavelength(designWavelength);
		// set free aperture
		setFreeAperture(freeAperture);
		// set radius first surface
		setRadiusFirstSurface(radius);
		// set numerical aperture
		setNumericalAperture(numericalAperture);
		// set min wavelength
		setMinWavelength(minWavelength);
		// set max wavelength
		setMaxWavelength(maxWavelength);
		// set focal length
		setFocalLength(focalLength);
		// set coating
		setCoating(coating);
		// set material
		setMaterial(material);
		// set power PV
		setPowerPV(powerPV);
		// set thickness
		setThickness(thickness);
		// tolerance focal length
		setToleranceFocallength(toleranceFocalLenght);
		// set Centering (arc minutes)
		setCentering(centering),
		// set edge thickness
		setEdgeThickness(edgeThickness);
		// set price
		setPrice(price);
		// set wavelength to trace
		setWavelengthToTrace(wavelenghtToTrace);

		buildOpticalSystemTwoSurfaces_OneSurfacePlan();
	}

void LensesTwoSurfaces::buildOpticalSystemTwoSurfaces_OneSurfacePlan()
{
	typedef std::shared_ptr< Element_CR > surfacePtr;
	RefractedRay_LLT refrac;
	std::shared_ptr<InteractionRay_LLT> refrac_ptr = refrac.clone();

	VectorStructR3 directionFirstSurface{ 0.0,0.0,1.0 };
	VectorStructR3 directionSecondSurface{ 0.0,0.0,1.0 };
	// paramenter first surface
	real radiusFirstSurface;
	real refIndex_A_FirstSurface;
	real refIndex_B_FirstSurface;

	if (mRadiusFirstSurface > 0)
	{
		radiusFirstSurface = std::abs(mRadiusFirstSurface);
		refIndex_A_FirstSurface = refractiveIndexAir;
		refIndex_B_FirstSurface = mMaterial.calcRefractiveIndexSnellmeier1(mWavelengthToTrace);
	}


	if (mRadiusFirstSurface < 0)
	{
		// flip direction
		directionFirstSurface.setZ(-1.0);

		radiusFirstSurface = std::abs(mRadiusFirstSurface);
		refIndex_A_FirstSurface = mMaterial.calcRefractiveIndexSnellmeier1(mWavelengthToTrace);
		refIndex_B_FirstSurface = refractiveIndexAir;

	}

	//// build first surface
	SphericalElement firstSurface;
	firstSurface.setRadiusValue(radiusFirstSurface);
	firstSurface.setSemiHeightValue(mDiameter / 2);
	firstSurface.setOriginValue({ 0.0,0.0,0.0 });
	firstSurface.setDirectionValue(directionFirstSurface);
	firstSurface.setRefIndexValue_A(refIndex_A_FirstSurface);
	firstSurface.setRefIndexValue_B(refIndex_B_FirstSurface);
	firstSurface.buildSurface_LLT();
	surfacePtr firstSurface_ptr = firstSurface.clone();

	// build second surface
	PlanElement secondSurface;
	secondSurface.setSemiHeightElementValue(mDiameter / 2);
	secondSurface.setPointElementValue_X(0.0);
	secondSurface.setPointElementValue_Y(0.0);
	secondSurface.setPointElementValue_Z(mThickness);
	secondSurface.setDirectionX_value(directionSecondSurface.getX());
	secondSurface.setDirectionY_value(directionSecondSurface.getY());
	secondSurface.setDirectionZ_value(directionSecondSurface.getZ());
	secondSurface.setRefIndex_A_value(mMaterial.calcRefractiveIndexSnellmeier1(mWavelengthToTrace));
	secondSurface.setRefIndex_B_value(1.0);
	secondSurface.buildSurface_LLT();
	surfacePtr secondSurface_ptr = secondSurface.clone();


	mOptSysTwoSurfaces_HLT.fillPosAndElementAndInteraction(0, firstSurface_ptr, refrac_ptr);
	mOptSysTwoSurfaces_HLT.fillPosAndElementAndInteraction(1, secondSurface_ptr, refrac_ptr);
	mOptSysTwoSurfaces_HLT.convertHLTSurfacesToLLTSurfaces();
}


// build optical System with two surfaces
void LensesTwoSurfaces::buildOpticalSystemTwoSurfaces()
{
	MaterialSellmeier1 materialAir;
	materialAir.setParameterAndCalcVd_Ve("Schott", "Air", 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0); // refractive index is 1

	typedef std::shared_ptr< Element_CR > surfacePtr;
	RefractedRay_LLT refrac;
	std::shared_ptr<InteractionRay_LLT> refrac_ptr = refrac.clone();


	VectorStructR3 directionFirstSurface{ 0.0,0.0,1.0 };
	VectorStructR3 directionSecondSurface{ 0.0,0.0,1.0 };
	// paramenter first surface
	real radiusFirstSurface;
	real refIndex_A_FirstSurface;
	real refIndex_B_FirstSurface;
	MaterialSellmeier1 materialSellmeier_A_FirstSurface;
	MaterialSellmeier1 materialSellmeier_B_FirstSurface;
	// parameter second surface
	real radiusSecondSurface;
	real refIndex_A_SecondSurface;
	real refIndex_B_SecondSurface;
	MaterialSellmeier1 materialSellmeier_A_SecondSurface;
	MaterialSellmeier1 materialSellmeier_B_SecondSurface;



	if (mRadiusFirstSurface > 0)
	{
		radiusFirstSurface = std::abs(mRadiusFirstSurface);
		refIndex_A_FirstSurface = refractiveIndexAir;
		refIndex_B_FirstSurface = mMaterial.calcRefractiveIndexSnellmeier1(mWavelengthToTrace);
		materialSellmeier_A_FirstSurface = materialAir;
		materialSellmeier_B_FirstSurface = mMaterial;
	}

	if (mRadiusSecondSurface > 0)
	{
		radiusSecondSurface = std::abs(mRadiusSecondSurface);
		refIndex_A_SecondSurface = mMaterial.calcRefractiveIndexSnellmeier1(mWavelengthToTrace);
		refIndex_B_SecondSurface = refractiveIndexAir;
		materialSellmeier_A_SecondSurface = mMaterial;
		materialSellmeier_B_SecondSurface = materialAir;
	}

	if (mRadiusFirstSurface < 0)
	{
		// flip direction
		directionFirstSurface.setZ(-1.0);

		radiusFirstSurface = std::abs(mRadiusFirstSurface);
		refIndex_A_FirstSurface = mMaterial.calcRefractiveIndexSnellmeier1(mWavelengthToTrace);
		refIndex_B_FirstSurface = refractiveIndexAir;
		materialSellmeier_A_FirstSurface = mMaterial;
		materialSellmeier_B_FirstSurface = materialAir;

	}
	if (mRadiusSecondSurface < 0)
	{
		// flip direction
		directionSecondSurface.setZ(-1.0);

		radiusSecondSurface = std::abs(mRadiusSecondSurface);
		refIndex_A_SecondSurface = refractiveIndexAir;
		refIndex_B_SecondSurface = mMaterial.calcRefractiveIndexSnellmeier1(mWavelengthToTrace);
		materialSellmeier_A_SecondSurface = materialAir;
		materialSellmeier_B_SecondSurface = mMaterial;
	}

	// TODO: We have to fix that.Write function setRadiusValue, setSemiHeightValue, ...

	//// build first surface
	SphericalElement firstSurface;
	firstSurface.setRadiusValue(radiusFirstSurface);
	firstSurface.setSemiHeightValue(mDiameter / 2);
	firstSurface.setOriginValue({ 0.0,0.0,0.0 });
	firstSurface.setDirectionValue(directionFirstSurface);
	firstSurface.setRefIndexValue_A(refIndex_A_FirstSurface);
	firstSurface.setRefIndexValue_B(refIndex_B_FirstSurface);
	firstSurface.setAllParameterFix();
	firstSurface.buildSurface_LLT();
	surfacePtr firstSurface_ptr = firstSurface.clone();


	//
	//
	// build second surface
	SphericalElement secondSurface;
	secondSurface.setRadiusValue(radiusSecondSurface);
	secondSurface.setSemiHeightValue(mDiameter / 2);
	secondSurface.setOriginValue({ 0.0,0.0,mThickness });
	secondSurface.setDirectionValue(directionSecondSurface);
	secondSurface.setRefIndexValue_A(refIndex_A_SecondSurface);
	secondSurface.setRefIndexValue_B(refIndex_B_SecondSurface);
	secondSurface.setAllParameterFix();
	secondSurface.buildSurface_LLT();
	surfacePtr secondSurface_ptr = secondSurface.clone();


	mOptSysTwoSurfaces_HLT.fillPosAndElementAndInteraction(0, firstSurface_ptr, refrac_ptr);
	mOptSysTwoSurfaces_HLT.fillPosAndElementAndInteraction(1, secondSurface_ptr, refrac_ptr);
	mOptSysTwoSurfaces_HLT.convertHLTSurfacesToLLTSurfaces();

}




// set functions
//---
	// set lens catalog
void LensesTwoSurfaces::setLensCatalog(std::string lensCatalog)
{
	mLensCatalog = lensCatalog;
}
// set number in catalog
void LensesTwoSurfaces::setCatalogNumber(unsigned int catalogNumber)
{
	mCatalogNumber = catalogNumber;
}

// set diameter
void LensesTwoSurfaces::setDiameter(real const diamerter)
{
	mDiameter = diamerter;
}
// set min diameter tolerance
void LensesTwoSurfaces::setMinDiaTolerance(real const minDiaTolerance)
{
	mMinDiamterTolerance = minDiaTolerance;
}
// set max diameter tolerance
void LensesTwoSurfaces::setMaxDiaTolerance(real maxDiaTolerace)
{
	mMaxDiamterTolerance = maxDiaTolerace;
}
// set radius first surface
void LensesTwoSurfaces::setRadiusFirstSurface(real radiusFirstSurface)
{
	mRadiusFirstSurface = radiusFirstSurface;
}
// set radius second surface
void LensesTwoSurfaces::setRadiusSecondSurface(real const radiusSecondSurface)
{
	mRadiusSecondSurface = radiusSecondSurface;
}
// set thickness
void LensesTwoSurfaces::setThickness(real const thickness)
{
	mThickness = thickness;
}
// set material
void LensesTwoSurfaces::setMaterial(MaterialSellmeier1 const material)
{
	mMaterial = material;
}
// set back focal length
void LensesTwoSurfaces::setBackFocalLength(real const backFocalLength)
{
	mBackFocalLength = backFocalLength;
}
// set coating
void LensesTwoSurfaces::setCoating(std::string const coating)
{
	mCoating = coating;
}
// set power PV
void LensesTwoSurfaces::setPowerPV(real const powerPV)
{
	mPowerPV = powerPV;
}
// set curvature PV
void LensesTwoSurfaces::setCurvaturePV(real const curvaturePV)
{
	mCurvaturePV = curvaturePV;
}
// set min center
void LensesTwoSurfaces::setMinCenter(real const minCenter)
{
	mMinCenter = minCenter;
}
// set max center
void LensesTwoSurfaces::setMaxCenter(real const maxCenter)
{
	mMaxCenter = maxCenter;
}
// set tolerance center thickness
void LensesTwoSurfaces::setToleranceCenterThickness(real const toleranceCenterThickness)
{
	mToleraceCenterThickness = toleranceCenterThickness;
}
// set numerical aperture
void LensesTwoSurfaces::setNumericalAperture(real const numericalAperture)
{
	mNumericalAperture = numericalAperture;
}
// set min wavelength
void LensesTwoSurfaces::setMinWavelength(real const minWave)
{
	mMinWavelength = minWave;
}
// set max wavelength
void LensesTwoSurfaces::setMaxWavelength(real const maxWave)
{
	mMaxWavelenght = maxWave;
}
// set price
void LensesTwoSurfaces::setPrice(real const price)
{
	mPrice = price;
}
// set wavelength to trace
void LensesTwoSurfaces::setWavelengthToTrace(real const wavelengthToTrace)
{
	mWavelengthToTrace = wavelengthToTrace;
}

void LensesTwoSurfaces::setMaxSurfaceQuality(real const maxSurQual)
{
	mMaxSurfaceQuality = maxSurQual;
}
// set real min surface quality; 
void LensesTwoSurfaces::setMinSurfaceQuality(real const minSurQual)
{
	mMinSurfaceQuality = minSurQual;
}
// tolerance focal length
void LensesTwoSurfaces::setToleranceFocallength(real const toleranceFocallength)
{
	mToleranceFocallength = toleranceFocallength;
}
// set edge thickness
void LensesTwoSurfaces::setEdgeThickness(real const edgeThickness)
{
	mEdgeThickness = edgeThickness;
}
// set design wavelength
void LensesTwoSurfaces::setDesignWavelength(real const wavelength)
{
	mDesignWavelength = wavelength;
}
// set optical system two surfaces
void LensesTwoSurfaces::setOpticalSystemTwoSurfaces(OpticalSystemElement const lenseTwoSurfaces)
{
	mOptSysTwoSurfaces_HLT = lenseTwoSurfaces;
}
// set centering
void LensesTwoSurfaces::setCentering(real const centering)
{
	mCentering = centering;
}
// set focal length
void LensesTwoSurfaces::setFocalLength(real const focalLength)
{
	mFocalLength = focalLength;
}
// set free apertur
void LensesTwoSurfaces::setFreeAperture(real const freeAperture)
{
	mFreeAperture = freeAperture;
}
//---


// get HLT of the two lenses
OpticalSystemElement LensesTwoSurfaces::getHLT_TwoSurfaces()
{
	return mOptSysTwoSurfaces_HLT;
}

// get functions
//---
// get lens catalog
std::string LensesTwoSurfaces::getLensCatalog()
{
	return mLensCatalog;
}
// get number in catalog
unsigned int LensesTwoSurfaces::getCatalogNumber()
{
	return mCatalogNumber;
}
// get diameter
real LensesTwoSurfaces::getDiameter()
{
	return mDiameter;
}
// get min diameter tolerance
real LensesTwoSurfaces::getMinDiaTolerance()
{
	return mMinDiamterTolerance;
}
// get max diameter tolerance
real LensesTwoSurfaces::getMaxDiaTolerance()
{
	return mMaxDiamterTolerance;
}
// get real max surface quality; 
real LensesTwoSurfaces::getMaxSurfaceQuality()
{
	return mMaxSurfaceQuality;
}
// get real min surface quality; 
real LensesTwoSurfaces::getMinSurfaceQuality()
{
	return mMinSurfaceQuality;
}

// get curvature PV
real LensesTwoSurfaces::getCurvaturePV()
{
	return mCurvaturePV;
}
// get tolerance center thickness
real LensesTwoSurfaces::getToleranceCenterThickness()
{
	return mToleraceCenterThickness;
}
// get radius first surface
real LensesTwoSurfaces::getRadiusFirstSurface()
{
	return mRadiusFirstSurface;
}
// get radius second surface
real LensesTwoSurfaces::getRadiusSecondSurface()
{
	return mRadiusSecondSurface;
}
// tolerance focal length
real LensesTwoSurfaces::getToleranceFocallength()
{
	return mToleranceFocallength;
}
// get min wavelength
real LensesTwoSurfaces::getMinWavelength()
{
	return mMinWavelength;
}
// get max wavelength
real LensesTwoSurfaces::getMaxWavelength()
{
	return mMaxWavelenght;
}
// get coating
std::string LensesTwoSurfaces::getCoating()
{
	return mCoating;
}
// get material
MaterialSellmeier1 LensesTwoSurfaces::getMaterial()
{
	return mMaterial;
}
// get power PV
real LensesTwoSurfaces::getPowerPV()
{
	return mPowerPV;
}
// get min center
real LensesTwoSurfaces::getMinCenter()
{
	return mMinCenter;
}
// get max center
real LensesTwoSurfaces::getMaxCenter()
{
	return mMaxCenter;
}
// get thickness
real LensesTwoSurfaces::getThickness()
{
	return mThickness;
}
// get edge thickness
real LensesTwoSurfaces::getEdgeThickness()
{
	return mEdgeThickness;
}
// get design wavelength
real LensesTwoSurfaces::getDesignWavelength()
{
	return mDesignWavelength;
}
// get numerical aperture
real LensesTwoSurfaces::getNumericalAperture()
{
	return mNumericalAperture;
}
// get price
real LensesTwoSurfaces::getPrice()
{
	return mPrice;
}
// get wavelength to trace
real LensesTwoSurfaces::getWavelengthToTrace()
{
	return mWavelengthToTrace;
}
// get optical system two surfaces
OpticalSystemElement LensesTwoSurfaces::getOpticalSystemTwoSurfaces()
{
	return mOptSysTwoSurfaces_HLT;
}
// get centering
real LensesTwoSurfaces::getCentering()
{
	return mCentering;
}
// get focal length
real LensesTwoSurfaces::getFocalLength()
{
	return mFocalLength;
}
// get free apertur
real LensesTwoSurfaces::getFreeAperture()
{
	return mFreeAperture;
}
// get back focal length
real LensesTwoSurfaces::getBackFocalLength()
{
	return mBackFocalLength;
}
//---
