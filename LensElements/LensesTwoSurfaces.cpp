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

void LensesTwoSurfaces::buildLensTwoSurfaces_PCX //https://www.edmundoptics.de/f/micro-plano-convex-pcx-lenses/39529/
(
	/*lens catalog*/ std::string lensCatalog,
	/*catalog number*/ unsigned int catalogNumber,
	/*diameter*/ real const diameter,
	/*max tolerance diameter*/ real const maxDiamterTolerance,
	/*min tolerance diameter*/ real const minDiamterTolerance,
	/*Effective Focal Length EFL(mm)*/ real focalLength,
	/*back focal length*/ real const backFocalLength,
	/*Coating*/ std::string const coating,
	/*Coating Specification*/ std::string coatingSpecification,
	/*Coating min wavelength*/ real coatingMinWavelength,
	/*Coating max wavelength*/ real coatingMaxWavelength,
	/*material*/ MaterialSellmeier1 const material,
	/*max surface quality*/ real const maxSurfaceQuality,
	/*min surface quality*/ real const minSurfaceQuality,
	/*Power(P-V)@632.8nm:*/ real powerPV,
	/*Irregularity(P-V)@632.8nm*/ real irregularity,
	/*tolerance focal lenght*/ real const toleranceFocalLenght,
	/*min centering*/ real const minCenter,
	/*max centering*/ real const maxCenter,
	/*center thickness*/ real const thickness,
	/*tolerance center thickness*/ real const toleraceCenterThickness,
	/*edge thickness*/ real const edgeThickness,
	/*radius first surface*/ real const radiusFirstSurface,
	/*free aperture CA*/ real freeAperture,
	/*F-Number*/ real F_Number,
	/*numerical Aperture*/ real const numericalAperture,
	/*type*/ std::string type,
	/*Bevel*/ std::string bevel,
	/*Typical Energy Density Limit*/ std::string typicalEnergyDensityLimit,
	/*min wavelength range*/ real const minWavelength,
	/*max wavelength range*/ real const maxWavelength,
	/*price*/ real const price
)
{
	/*lens catalog*/ setLensCatalog(lensCatalog);
	/*catalog number*/ setCatalogNumber(catalogNumber);
	/*diameter*/ setDiameter(diameter);
	/*max tolerance diameter*/ setMaxDiaTolerance(maxDiamterTolerance);
	/*min tolerance diameter*/ setMinDiaTolerance(minDiamterTolerance);
	/*Effective Focal Length EFL(mm)*/ setFocalLength(focalLength);
	/*back focal length*/setBackFocalLength(backFocalLength);
	/*Coating*/ setCoating(coating);
	/*Coating Specification*/ setCoatingSpec(coatingSpecification);
	/*Coating min wavelength*/ setMinCoatinWavelength(coatingMinWavelength);
	/*Coating max wavelength*/ setMaxCoatinWavelength(coatingMaxWavelength);
	/*material*/ setMaterial(material);
	/*max surface quality*/ setMaxSurfaceQuality(maxSurfaceQuality);
	/*min surface quality*/ setMinSurfaceQuality(minSurfaceQuality);
	/*Power(P-V)@632.8nm:*/ setPowerPV(powerPV);
	/*Irregularity(P-V)@632.8nm*/ setIrregilarity(irregularity);
	/*tolerance focal lenght*/ setToleranceFocallength(toleranceFocalLenght);
	/*min centering*/ setMinCenter(minCenter);
	/*max centering*/setMaxCenter(maxCenter);
	/*center thickness*/ setThickness(thickness);
	/*tolerance center thickness*/ setToleranceCenterThickness(toleraceCenterThickness);
	/*edge thickness*/ setEdgeThickness(edgeThickness);
	/*radius first surface*/ setRadiusFirstSurface(radiusFirstSurface);
	/*free aperture CA*/ setFreeAperture(freeAperture);
	/*F-Number*/ setF_Number(F_Number);
	/*numerical Aperture*/ setNumericalAperture(numericalAperture);
	/*type*/ setType(type);
	/*Bevel*/ setBevel(bevel);
	/*Typical Energy Density Limit*/ setTypicalEnergyDensityLimit(typicalEnergyDensityLimit);
	/*min wavelength range*/ setMinWavelength(minWavelength);
	/*max wavelength range*/ setMaxWavelength(maxWavelength);
	/*price*/ setPrice(price);

	buildOpticalSystemTwoSurfaces_OneSurfacePlan();
}

void LensesTwoSurfaces::buildLensTwoSurfaces_PCX //https://www.edmundoptics.de/f/micro-plano-convex-pcx-lenses/39529/
(
	/*lens catalog*/ std::string lensCatalog,
	/*catalog number*/ unsigned int catalogNumber,
	/*diameter*/ real const diameter,
	/*max tolerance diameter*/ real const maxDiamterTolerance,
	/*min tolerance diameter*/ real const minDiamterTolerance,
	/*Effective Focal Length EFL(mm)*/ real focalLength,
	/*back focal length*/ real const backFocalLength,
	/*Coating*/ std::string const coating,
	/*Coating Specification*/ std::string coatingSpecification,
	/*Coating min wavelength*/ real coatingMinWavelength,
	/*Coating max wavelength*/ real coatingMaxWavelength,
	/*material*/ MaterialSellmeier1 const material,
	/*max surface quality*/ real const maxSurfaceQuality,
	/*min surface quality*/ real const minSurfaceQuality,
	/*Power(P-V)@632.8nm:*/ real powerPV,
	/*Irregularity(P-V)@632.8nm*/ real irregularity,
	/*tolerance focal lenght*/ real const toleranceFocalLenght,
	/*max centering*/ real const maxCenter,
	/*center thickness*/ real const thickness,
	/*tolerance center thickness*/ real const toleraceCenterThickness,
	/*edge thickness*/ real const edgeThickness,
	/*radius first surface*/ real const radiusFirstSurface,
	/*free aperture CA*/ real freeAperture,
	/*F-Number*/ real F_Number,
	/*numerical Aperture*/ real const numericalAperture,
	/*type*/ std::string type,
	/*Bevel*/ std::string bevel,
	/*Typical Energy Density Limit*/ std::string typicalEnergyDensityLimit,
	/*min wavelength range*/ real const minWavelength,
	/*max wavelength range*/ real const maxWavelength,
	/*price*/ real const price
)
{
	/*lens catalog*/ setLensCatalog(lensCatalog);
	/*catalog number*/ setCatalogNumber(catalogNumber);
	/*diameter*/ setDiameter(diameter);
	/*max tolerance diameter*/ setMaxDiaTolerance(maxDiamterTolerance);
	/*min tolerance diameter*/ setMinDiaTolerance(minDiamterTolerance);
	/*Effective Focal Length EFL(mm)*/ setFocalLength(focalLength);
	/*back focal length*/setBackFocalLength(backFocalLength);
	/*Coating*/ setCoating(coating);
	/*Coating Specification*/ setCoatingSpec(coatingSpecification);
	/*Coating min wavelength*/ setMinCoatinWavelength(coatingMinWavelength);
	/*Coating max wavelength*/ setMaxCoatinWavelength(coatingMaxWavelength);
	/*material*/ setMaterial(material);
	/*max surface quality*/ setMaxSurfaceQuality(maxSurfaceQuality);
	/*min surface quality*/ setMinSurfaceQuality(minSurfaceQuality);
	/*Power(P-V)@632.8nm:*/ setPowerPV(powerPV);
	/*Irregularity(P-V)@632.8nm*/ setIrregilarity(irregularity);
	/*tolerance focal lenght*/ setToleranceFocallength(toleranceFocalLenght);
	/*max centering*/setMaxCenter(maxCenter);
	/*center thickness*/ setThickness(thickness);
	/*tolerance center thickness*/ setToleranceCenterThickness(toleraceCenterThickness);
	/*edge thickness*/ setEdgeThickness(edgeThickness);
	/*radius first surface*/ setRadiusFirstSurface(radiusFirstSurface);
	/*free aperture CA*/ setFreeAperture(freeAperture);
	/*F-Number*/ setF_Number(F_Number);
	/*numerical Aperture*/ setNumericalAperture(numericalAperture);
	/*type*/ setType(type);
	/*Bevel*/ setBevel(bevel);
	/*Typical Energy Density Limit*/ setTypicalEnergyDensityLimit(typicalEnergyDensityLimit);
	/*min wavelength range*/ setMinWavelength(minWavelength);
	/*max wavelength range*/ setMaxWavelength(maxWavelength);
	/*price*/ setPrice(price);

	buildOpticalSystemTwoSurfaces_OneSurfacePlan();
}

void LensesTwoSurfaces::buildLensTwoSurfaces_PCX //https://www.edmundoptics.de/f/micro-plano-convex-pcx-lenses/39529/
(
	/*lens catalog*/ std::string lensCatalog,
	/*catalog number*/ unsigned int catalogNumber,
	/*diameter*/ real const diameter,
	/*max tolerance diameter*/ real const maxDiamterTolerance,
	/*min tolerance diameter*/ real const minDiamterTolerance,
	/*Effective Focal Length EFL(mm)*/ real focalLength,
	/*back focal length*/ real const backFocalLength,
	/*Coating*/ std::string const coating,
	/*Coating Specification*/ std::string coatingSpecification,
	/*Coating min wavelength*/ real coatingMinWavelength,
	/*Coating max wavelength*/ real coatingMaxWavelength,
	/*material*/ MaterialSellmeier1 const material,
	/*max surface quality*/ real const maxSurfaceQuality,
	/*min surface quality*/ real const minSurfaceQuality,
	/*Power(P-V)@632.8nm:*/ real powerPV,
	/*Irregularity(P-V)@632.8nm*/ real irregularity,
	/*tolerance focal lenght*/ real const toleranceFocalLenght,
	/*max centering*/ real const maxCenter,
	/*center thickness*/ real const thickness,
	/*tolerance center thickness*/ real const toleraceCenterThickness,
	/*edge thickness*/ real const edgeThickness,
	/*radius first surface*/ real const radiusFirstSurface,
	/*free aperture CA*/ real freeAperture,
	/*F-Number*/ real F_Number,
	/*numerical Aperture*/ real const numericalAperture,
	/*type*/ std::string type,
	/*Bevel*/ std::string bevel,
	/*min wavelength range*/ real const minWavelength,
	/*max wavelength range*/ real const maxWavelength,
	/*price*/ real const price
)
{
	/*lens catalog*/ setLensCatalog(lensCatalog);
	/*catalog number*/ setCatalogNumber(catalogNumber);
	/*diameter*/ setDiameter(diameter);
	/*max tolerance diameter*/ setMaxDiaTolerance(maxDiamterTolerance);
	/*min tolerance diameter*/ setMinDiaTolerance(minDiamterTolerance);
	/*Effective Focal Length EFL(mm)*/ setFocalLength(focalLength);
	/*back focal length*/setBackFocalLength(backFocalLength);
	/*Coating*/ setCoating(coating);
	/*Coating Specification*/ setCoatingSpec(coatingSpecification);
	/*Coating min wavelength*/ setMinCoatinWavelength(coatingMinWavelength);
	/*Coating max wavelength*/ setMaxCoatinWavelength(coatingMaxWavelength);
	/*material*/ setMaterial(material);
	/*max surface quality*/ setMaxSurfaceQuality(maxSurfaceQuality);
	/*min surface quality*/ setMinSurfaceQuality(minSurfaceQuality);
	/*Power(P-V)@632.8nm:*/ setPowerPV(powerPV);
	/*Irregularity(P-V)@632.8nm*/ setIrregilarity(irregularity);
	/*tolerance focal lenght*/ setToleranceFocallength(toleranceFocalLenght);
	/*max centering*/setMaxCenter(maxCenter);
	/*center thickness*/ setThickness(thickness);
	/*tolerance center thickness*/ setToleranceCenterThickness(toleraceCenterThickness);
	/*edge thickness*/ setEdgeThickness(edgeThickness);
	/*radius first surface*/ setRadiusFirstSurface(radiusFirstSurface);
	/*free aperture CA*/ setFreeAperture(freeAperture);
	/*F-Number*/ setF_Number(F_Number);
	/*numerical Aperture*/ setNumericalAperture(numericalAperture);
	/*type*/ setType(type);
	/*Bevel*/ setBevel(bevel);
	/*min wavelength range*/ setMinWavelength(minWavelength);
	/*max wavelength range*/ setMaxWavelength(maxWavelength);
	/*price*/ setPrice(price);

	buildOpticalSystemTwoSurfaces_OneSurfacePlan();
}

void LensesTwoSurfaces::buildLensTwoSurfaces_PCX_uncoated //https://www.edmundoptics.de/f/micro-plano-convex-pcx-lenses/39529/
(
	/*lens catalog*/ std::string lensCatalog,
	/*catalog number*/ unsigned int catalogNumber,
	/*diameter*/ real const diameter,
	/*max tolerance diameter*/ real const maxDiamterTolerance,
	/*min tolerance diameter*/ real const minDiamterTolerance,
	/*Effective Focal Length EFL(mm)*/ real focalLength,
	/*back focal length*/ real const backFocalLength,
	/*material*/ MaterialSellmeier1 const material,
	/*max surface quality*/ real const maxSurfaceQuality,
	/*min surface quality*/ real const minSurfaceQuality,
	/*Power(P-V)@632.8nm:*/ real powerPV,
	/*Irregularity(P-V)@632.8nm*/ real irregularity,
	/*tolerance focal lenght*/ real const toleranceFocalLenght,
	/*max centering*/ real const maxCenter,
	/*center thickness*/ real const thickness,
	/*tolerance center thickness*/ real const toleraceCenterThickness,
	/*edge thickness*/ real const edgeThickness,
	/*radius first surface*/ real const radiusFirstSurface,
	/*free aperture CA*/ real freeAperture,
	/*F-Number*/ real F_Number,
	/*numerical Aperture*/ real const numericalAperture,
	/*type*/ std::string type,
	/*Bevel*/ std::string bevel,
	/*min wavelength range*/ real const minWavelength,
	/*max wavelength range*/ real const maxWavelength,
	/*price*/ real const price
)
{
	/*lens catalog*/ setLensCatalog(lensCatalog);
	/*catalog number*/ setCatalogNumber(catalogNumber);
	/*diameter*/ setDiameter(diameter);
	/*max tolerance diameter*/ setMaxDiaTolerance(maxDiamterTolerance);
	/*min tolerance diameter*/ setMinDiaTolerance(minDiamterTolerance);
	/*Effective Focal Length EFL(mm)*/ setFocalLength(focalLength);
	/*back focal length*/setBackFocalLength(backFocalLength);
	/*material*/ setMaterial(material);
	/*max surface quality*/ setMaxSurfaceQuality(maxSurfaceQuality);
	/*min surface quality*/ setMinSurfaceQuality(minSurfaceQuality);
	/*Power(P-V)@632.8nm:*/ setPowerPV(powerPV);
	/*Irregularity(P-V)@632.8nm*/ setIrregilarity(irregularity);
	/*tolerance focal lenght*/ setToleranceFocallength(toleranceFocalLenght);
	/*max centering*/setMaxCenter(maxCenter);
	/*center thickness*/ setThickness(thickness);
	/*tolerance center thickness*/ setToleranceCenterThickness(toleraceCenterThickness);
	/*edge thickness*/ setEdgeThickness(edgeThickness);
	/*radius first surface*/ setRadiusFirstSurface(radiusFirstSurface);
	/*free aperture CA*/ setFreeAperture(freeAperture);
	/*F-Number*/ setF_Number(F_Number);
	/*numerical Aperture*/ setNumericalAperture(numericalAperture);
	/*type*/ setType(type);
	/*Bevel*/ setBevel(bevel);
	/*min wavelength range*/ setMinWavelength(minWavelength);
	/*max wavelength range*/ setMaxWavelength(maxWavelength);
	/*price*/ setPrice(price);

	buildOpticalSystemTwoSurfaces_OneSurfacePlan();
}

void LensesTwoSurfaces::buildLensTwoSurfaces_PCX //https://www.edmundoptics.de/f/micro-plano-convex-pcx-lenses/39529/
(
	/*lens catalog*/ std::string lensCatalog,
	/*catalog number*/ unsigned int catalogNumber,
	/*diameter*/ real const diameter,
	/*max tolerance diameter*/ real const maxDiamterTolerance,
	/*min tolerance diameter*/ real const minDiamterTolerance,
	/*Effective Focal Length EFL(mm)*/ real focalLength,
	/*back focal length*/ real const backFocalLength,
	/*Coating*/ std::string const coating,
	/*Coating Specification*/ std::string coatingSpecification,
	/*Coating min wavelength*/ real coatingMinWavelength,
	/*Coating max wavelength*/ real coatingMaxWavelength,
	/*material*/ MaterialSellmeier1 const material,
	/*max surface quality*/ real const maxSurfaceQuality,
	/*min surface quality*/ real const minSurfaceQuality,
	/*Power(P-V)@632.8nm:*/ real powerPV,
	/*Irregularity(P-V)@632.8nm*/ real irregularity,
	/*tolerance focal lenght*/ real const toleranceFocalLenght,
	/*min centering*/ real const minCenter,
	/*max centering*/ real const maxCenter,
	/*center thickness*/ real const thickness,
	/*tolerance center thickness*/ real const toleraceCenterThickness,
	/*edge thickness*/ real const edgeThickness,
	/*radius first surface*/ real const radiusFirstSurface,
	/*free aperture CA*/ real freeAperture,
	/*F-Number*/ real F_Number,
	/*numerical Aperture*/ real const numericalAperture,
	/*type*/ std::string type,
	/*Bevel*/ std::string bevel,
	/*min wavelength range*/ real const minWavelength,
	/*max wavelength range*/ real const maxWavelength,
	/*price*/ real const price
)
{
	/*lens catalog*/ setLensCatalog(lensCatalog);
	/*catalog number*/ setCatalogNumber(catalogNumber);
	/*diameter*/ setDiameter(diameter);
	/*max tolerance diameter*/ setMaxDiaTolerance(maxDiamterTolerance);
	/*min tolerance diameter*/ setMinDiaTolerance(minDiamterTolerance);
	/*Effective Focal Length EFL(mm)*/ setFocalLength(focalLength);
	/*back focal length*/setBackFocalLength(backFocalLength);
	/*Coating*/ setCoating(coating);
	/*Coating Specification*/ setCoatingSpec(coatingSpecification);
	/*Coating min wavelength*/ setMinCoatinWavelength(coatingMinWavelength);
	/*Coating max wavelength*/ setMaxCoatinWavelength(coatingMaxWavelength);
	/*material*/ setMaterial(material);
	/*max surface quality*/ setMaxSurfaceQuality(maxSurfaceQuality);
	/*min surface quality*/ setMinSurfaceQuality(minSurfaceQuality);
	/*Power(P-V)@632.8nm:*/ setPowerPV(powerPV);
	/*Irregularity(P-V)@632.8nm*/ setIrregilarity(irregularity);
	/*tolerance focal lenght*/ setToleranceFocallength(toleranceFocalLenght);
	/*min centering*/ setMinCenter(minCenter);
	/*max centering*/setMaxCenter(maxCenter);
	/*center thickness*/ setThickness(thickness);
	/*tolerance center thickness*/ setToleranceCenterThickness(toleraceCenterThickness);
	/*edge thickness*/ setEdgeThickness(edgeThickness);
	/*radius first surface*/ setRadiusFirstSurface(radiusFirstSurface);
	/*free aperture CA*/ setFreeAperture(freeAperture);
	/*F-Number*/ setF_Number(F_Number);
	/*numerical Aperture*/ setNumericalAperture(numericalAperture);
	/*type*/ setType(type);
	/*Bevel*/ setBevel(bevel);
	/*min wavelength range*/ setMinWavelength(minWavelength);
	/*max wavelength range*/ setMaxWavelength(maxWavelength);
	/*price*/ setPrice(price);

	buildOpticalSystemTwoSurfaces_OneSurfacePlan();
}

void LensesTwoSurfaces::buildLensTwoSurfaces_PCX_uncoated //https://www.edmundoptics.de/f/micro-plano-convex-pcx-lenses/39529/
(
	/*lens catalog*/ std::string lensCatalog,
	/*catalog number*/ unsigned int catalogNumber,
	/*diameter*/ real const diameter,
	/*max tolerance diameter*/ real const maxDiamterTolerance,
	/*min tolerance diameter*/ real const minDiamterTolerance,
	/*Effective Focal Length EFL(mm)*/ real focalLength,
	/*back focal length*/ real const backFocalLength,
	/*material*/ MaterialSellmeier1 const material,
	/*max surface quality*/ real const maxSurfaceQuality,
	/*min surface quality*/ real const minSurfaceQuality,
	/*Power(P-V)@632.8nm:*/ real powerPV,
	/*Irregularity(P-V)@632.8nm*/ real irregularity,
	/*tolerance focal lenght*/ real const toleranceFocalLenght,
	/*min centering*/ real const minCenter,
	/*max centering*/ real const maxCenter,
	/*center thickness*/ real const thickness,
	/*tolerance center thickness*/ real const toleraceCenterThickness,
	/*edge thickness*/ real const edgeThickness,
	/*radius first surface*/ real const radiusFirstSurface,
	/*free aperture CA*/ real freeAperture,
	/*F-Number*/ real F_Number,
	/*numerical Aperture*/ real const numericalAperture,
	/*type*/ std::string type,
	/*Bevel*/ std::string bevel,
	/*min wavelength range*/ real const minWavelength,
	/*max wavelength range*/ real const maxWavelength,
	/*price*/ real const price
)
{
	/*lens catalog*/ setLensCatalog(lensCatalog);
	/*catalog number*/ setCatalogNumber(catalogNumber);
	/*diameter*/ setDiameter(diameter);
	/*max tolerance diameter*/ setMaxDiaTolerance(maxDiamterTolerance);
	/*min tolerance diameter*/ setMinDiaTolerance(minDiamterTolerance);
	/*Effective Focal Length EFL(mm)*/ setFocalLength(focalLength);
	/*back focal length*/setBackFocalLength(backFocalLength);
	/*material*/ setMaterial(material);
	/*max surface quality*/ setMaxSurfaceQuality(maxSurfaceQuality);
	/*min surface quality*/ setMinSurfaceQuality(minSurfaceQuality);
	/*Power(P-V)@632.8nm:*/ setPowerPV(powerPV);
	/*Irregularity(P-V)@632.8nm*/ setIrregilarity(irregularity);
	/*tolerance focal lenght*/ setToleranceFocallength(toleranceFocalLenght);
	/*min centering*/ setMinCenter(minCenter);
	/*max centering*/setMaxCenter(maxCenter);
	/*center thickness*/ setThickness(thickness);
	/*tolerance center thickness*/ setToleranceCenterThickness(toleraceCenterThickness);
	/*edge thickness*/ setEdgeThickness(edgeThickness);
	/*radius first surface*/ setRadiusFirstSurface(radiusFirstSurface);
	/*free aperture CA*/ setFreeAperture(freeAperture);
	/*F-Number*/ setF_Number(F_Number);
	/*numerical Aperture*/ setNumericalAperture(numericalAperture);
	/*type*/ setType(type);
	/*Bevel*/ setBevel(bevel);
	/*min wavelength range*/ setMinWavelength(minWavelength);
	/*max wavelength range*/ setMaxWavelength(maxWavelength);
	/*price*/ setPrice(price);

	buildOpticalSystemTwoSurfaces_OneSurfacePlan();
}

void LensesTwoSurfaces::buildLensTwoSurfaces_PCX //https://www.edmundoptics.de/f/large-pcx-condenser-lenses/13572/
(
	/*lens catalog*/ std::string lensCatalog,
	/*catalog number*/ unsigned int catalogNumber,
	/*diameter*/ real const diameter,
	/*max tolerance diameter*/ real const maxDiamterTolerance,
	/*min tolerance diameter*/ real const minDiamterTolerance,
	/*Effective Focal Length EFL(mm)*/ real focalLength,
	/*back focal length*/ real const backFocalLength,
	/*Coating*/ std::string const coating,
	/*material*/ MaterialSellmeier1 const material,
	/*max surface quality*/ real const maxSurfaceQuality,
	/*min surface quality*/ real const minSurfaceQuality,
	/*center thickness*/ real const thickness,
	/*edge thickness*/ real const edgeThickness,
	/*radius first surface*/ real const radiusFirstSurface,
	/*free aperture CA*/ real freeAperture,
	/*F-Number*/ real F_Number,
	/*numerical Aperture*/ real const numericalAperture,
	/*type*/ std::string type,
	/*Bevel*/ std::string bevel,
	/*min wavelength range*/ real const minWavelength,
	/*max wavelength range*/ real const maxWavelength,
	/*price*/ real const price
)
{
	/*lens catalog*/ setLensCatalog(lensCatalog);
	/*catalog number*/ setCatalogNumber(catalogNumber);
	/*diameter*/ setDiameter(diameter);
	/*max tolerance diameter*/ setMaxDiaTolerance(maxDiamterTolerance);
	/*min tolerance diameter*/ setMinDiaTolerance(minDiamterTolerance);
	/*Effective Focal Length EFL(mm)*/ setFocalLength(focalLength);
	/*back focal length*/setBackFocalLength(backFocalLength);
	/*Coating*/ setCoating(coating);
	/*material*/ setMaterial(material);
	/*max surface quality*/ setMaxSurfaceQuality(maxSurfaceQuality);
	/*min surface quality*/ setMinSurfaceQuality(minSurfaceQuality);
	/*center thickness*/ setThickness(thickness);
	/*edge thickness*/ setEdgeThickness(edgeThickness);
	/*radius first surface*/ setRadiusFirstSurface(radiusFirstSurface);
	/*free aperture CA*/ setFreeAperture(freeAperture);
	/*F-Number*/ setF_Number(F_Number);
	/*numerical Aperture*/ setNumericalAperture(numericalAperture);
	/*type*/ setType(type);
	/*Bevel*/ setBevel(bevel);
	/*min wavelength range*/ setMinWavelength(minWavelength);
	/*max wavelength range*/ setMaxWavelength(maxWavelength);
	/*price*/ setPrice(price);

	buildOpticalSystemTwoSurfaces_OneSurfacePlan();
}

void LensesTwoSurfaces::buildLensTwoSurfaces_Thorlabs_oneSurfacePlan
(
	// https://www.thorlabs.de/newgrouppage9.cfm?objectgroup_id=13685

	/*lens catalog*/ std::string lensCatalog,
	/*catalog number*/ std::string item,
	/*diameter*/ real  diameter,
	/* focallength*/ real focalLenght,
	/*back focal length*/ real backFocalLength,
	/*radius*/ real radius,
	/*thickness*/ real centerThickness,
	/*edge thickness*/ real edgeThickness,
	/*material*/ MaterialSellmeier1 material,
	/*price*/ real price,
	/*design wavelength*/ real designWavelength,
	/*free aperture CA*/ real freeApertureCA,
	/*max surface quality*/ real maxSurfaceQuality,
	/*min surface quality*/ real minSurfaceQuality,
	/*centration*/ real centration,
	/*max diameter tolerance*/ real maxDiamterTolerance,
	/*min diameter tolerance*/ real minDiamterTolerance,
	/*tolerance center thickness*/ real toleraceCenterThickness,
	/*coating*/ std::string coating,
	/*min wavelength*/ real minWavelength,
	/*max wavelength*/ real maxWavelenght
)
{
	setLensCatalog(lensCatalog);
	setCatalogNumber(item);
	setDiameter(diameter);
	setFocalLength(focalLenght);
	setBackFocalLength(backFocalLength);
	setRadiusFirstSurface(radius);
	setRadiusSecondSurface(std::numeric_limits<double>::quiet_NaN());
	setThickness(centerThickness);
	setEdgeThickness(edgeThickness);
	setMaterial(material);
	setPrice(price);
	setDesignWavelength(designWavelength);
	setFreeAperture(freeApertureCA);
	setMaxSurfaceQuality(maxSurfaceQuality);
	setMinSurfaceQuality(minSurfaceQuality);
	setCentration(centration);
	setMaxDiaTolerance(maxDiamterTolerance);
	setMinDiaTolerance(minDiamterTolerance);
	setToleranceCenterThickness(toleraceCenterThickness);
	setCoating(coating);
	setMinWavelength(minWavelength);
	setMaxWavelength(maxWavelenght);

	buildOpticalSystemTwoSurfaces_OneSurfacePlan();
}

void LensesTwoSurfaces::buildLensTwoSurfaces_Qioptiq_oneSurfacePlan
(
	// https://www.qioptiq-shop.com/en/Precision-Optics/Singlets/Plano-Convex-Lenses/Plano-convex-lenses-unmounted.html

	/*lens catalog*/ std::string lensCatalog,
	/*catalog number*/ std::string partNumber,
	/*diameter*/ real  diameter,
	/*focallength*/ real focalLenght,
	/*tolerance focal length*/ real toleranceFocalLength,
	/*material*/ MaterialSellmeier1 material,
	/*optical centering accurancy*/ real centering,
	/*surface quality*/ std::string surfaceQuality,
	/*thickness*/ real centerThickness,
	/*tolerance center thickness*/ real toleraceCenterThickness,
	/*edge thickness*/ real edgeThickness,
	/*min diameter tolerance*/ real minDiamterTolerance,
	/*back focal length*/ real backFocalLength,
	/*radius*/ real radius,
	/*price*/ real price,
	/*coating*/ std::string coating,
	/*min wavelength*/ real minWavelength,
	/*max wavelength*/ real maxWavelenght
)
{
	setLensCatalog(lensCatalog);
	setCatalogNumber(partNumber);
	setDiameter(diameter);
	setFocalLength(focalLenght);
	setToleranceFocallength(toleranceFocalLength);
	setMaterial(material);
	setCentering(centering);
	setSurfaceQuality(surfaceQuality);
	setThickness(centerThickness);
	setToleranceCenterThickness(toleraceCenterThickness);
	setEdgeThickness(edgeThickness);
	setMinDiaTolerance(minDiamterTolerance);
	setBackFocalLength(backFocalLength);
	setRadiusFirstSurface(radius);
	setPrice(price);
	setCoating(coating);
	setMinWavelength(minWavelength);
	setMaxWavelength(maxWavelenght);

	// build optical system
	buildOpticalSystemTwoSurfaces_OneSurfacePlan();
}

void LensesTwoSurfaces::buildLensTwoSurfaces_Qioptiq_lenses
(
	// https://www.qioptiq-shop.com/en/Precision-Optics/Singlets/Symmetric-Convex-Lenses/Symmetric-convex-lenses-unmounted.html
	// https://www.qioptiq-shop.com/en/Precision-Optics/Singlets/Symmetric-Concave-Lenses/Symmetric-concave-lenses-unmounted-N-BK7.html

	/*lens catalog*/ std::string lensCatalog,
	/*catalog number*/ std::string partNumber,
	/*diameter*/ real  diameter,
	/*focallength*/ real focalLenght,
	/*tolerance focal length*/ real toleranceFocalLength,
	/*material*/ MaterialSellmeier1 material,
	/*optical centering accurancy*/ real centering,
	/*surface quality*/ std::string surfaceQuality,
	/*thickness*/ real centerThickness,
	/*tolerance center thickness*/ real toleraceCenterThickness,
	/*edge thickness*/ real edgeThickness,
	/*min diameter tolerance*/ real minDiamterTolerance,
	/*back focal length*/ real backFocalLength,
	/*radius first surface*/ real radiusFirstSurface,
	/*radius second surface*/ real radiusSecondSurface,
	/*price*/ real price,
	/*coating*/ std::string coating,
	/*min wavelength*/ real minWavelength,
	/*max wavelength*/ real maxWavelenght
)
{
	setLensCatalog(lensCatalog);
	setCatalogNumber(partNumber);
	setDiameter(diameter);
	setFocalLength(focalLenght);
	setToleranceFocallength(toleranceFocalLength);
	setMaterial(material);
	setCentering(centering);
	setSurfaceQuality(surfaceQuality);
	setThickness(centerThickness);
	setToleranceCenterThickness(toleraceCenterThickness);
	setEdgeThickness(edgeThickness);
	setMinDiaTolerance(minDiamterTolerance);
	setBackFocalLength(backFocalLength);
	setRadiusFirstSurface(radiusFirstSurface);
	setRadiusSecondSurface(radiusSecondSurface);
	setPrice(price);
	setCoating(coating);
	setMinWavelength(minWavelength);
	setMaxWavelength(maxWavelenght);

	// build optical system
	buildOpticalSystemTwoSurfaces();
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

void LensesTwoSurfaces::buildLensTwoSurfaces_thorlabs
(
	// https://www.thorlabs.de/newgrouppage9.cfm?objectgroup_id=4848
	/*item*/ std::string lensCatalog,
	/*catalog number*/ std::string item,
	/*diameter*/ real  diameter,
	/* focallength*/ real focalLenght,
	/*back focal length*/ real backFocalLength,
	/*radius first surface*/ real radiusFirstSurface,
	/*radius second surface*/ real radiusSecondSurface,
	/*thickness*/ real centerThickness,
	/*edge thickness*/ real edgeThickness,
	/*material*/ MaterialSellmeier1 material,
	/*price*/ real price,
	/*design wavelength*/ real designWavelength,
	/*free aperture CA*/ real freeApertureCA,
	/*max surface quality*/ real maxSurfaceQuality,
	/*min surface quality*/ real minSurfaceQuality,
	/*centration*/ real centration,
	/*max diameter tolerance*/ real maxDiamterTolerance,
	/*min diameter tolerance*/ real minDiamterTolerance,
	/*tolerance center thickness*/ real toleraceCenterThickness,
	/*coating*/ std::string coating,
	/*min wavelength*/ real minWavelength,
	/*max wavelength*/ real maxWavelenght
)
{
	setLensCatalog(lensCatalog);
	setCatalogNumber(item);
	setDiameter(diameter);
	setFocalLength(focalLenght);
	setBackFocalLength(backFocalLength);
	setRadiusFirstSurface(radiusFirstSurface);
	setRadiusSecondSurface(radiusSecondSurface);
	setThickness(centerThickness);
	setEdgeThickness(edgeThickness);
	setMaterial(material);
	setPrice(price);
	setDesignWavelength(designWavelength);
	setFreeAperture(freeApertureCA);
	setMaxSurfaceQuality(maxSurfaceQuality);
	setMinSurfaceQuality(minSurfaceQuality);
	setCentration(centration);
	setMaxDiaTolerance(maxDiamterTolerance);
	setMinDiaTolerance(minDiamterTolerance);
	setToleranceCenterThickness(toleraceCenterThickness);
	setCoating(coating);
	setMinWavelength(minWavelength);
	setMaxWavelength(maxWavelenght);

	buildOpticalSystemTwoSurfaces();
}

void LensesTwoSurfaces::buildLensTwoSurfaces_thorlabs_Uncoated
(
	// https://www.thorlabs.de/newgrouppage9.cfm?objectgroup_id=130
	/*item*/ std::string lensCatalog,
	/*catalog number*/ std::string item,
	/*diameter*/ real  diameter,
	/* focallength*/ real focalLenght,
	/*back focal length*/ real backFocalLength,
	/*radius first surface*/ real radiusFirstSurface,
	/*radius second surface*/ real radiusSecondSurface,
	/*thickness*/ real centerThickness,
	/*edge thickness*/ real edgeThickness,
	/*material*/ MaterialSellmeier1 material,
	/*price*/ real price,
	/*design wavelength*/ real designWavelength,
	/*free aperture CA*/ real freeApertureCA,
	/*max surface quality*/ real maxSurfaceQuality,
	/*min surface quality*/ real minSurfaceQuality,
	/*centration*/ real centration,
	/*max diameter tolerance*/ real maxDiamterTolerance,
	/*min diameter tolerance*/ real minDiamterTolerance,
	/*tolerance center thickness*/ real toleraceCenterThickness
)
{
	setLensCatalog(lensCatalog);
	setCatalogNumber(item);
	setDiameter(diameter);
	setFocalLength(focalLenght);
	setBackFocalLength(backFocalLength);
	setRadiusFirstSurface(radiusFirstSurface);
	setRadiusSecondSurface(radiusSecondSurface);
	setThickness(centerThickness);
	setEdgeThickness(edgeThickness);
	setMaterial(material);
	setPrice(price);
	setDesignWavelength(designWavelength);
	setFreeAperture(freeApertureCA);
	setMaxSurfaceQuality(maxSurfaceQuality);
	setMinSurfaceQuality(minSurfaceQuality);
	setCentration(centration);
	setMaxDiaTolerance(maxDiamterTolerance);
	setMinDiaTolerance(minDiamterTolerance);
	setToleranceCenterThickness(toleraceCenterThickness);

	buildOpticalSystemTwoSurfaces();
}

void LensesTwoSurfaces::buildLensTwoSurfaces_thorlabs_coated
(
	// https://www.thorlabs.de/newgrouppage9.cfm?objectgroup_id=130
	/*item*/ std::string lensCatalog,
	/*catalog number*/ std::string item,
	/*diameter*/ real  diameter,
	/* focallength*/ real focalLenght,
	/*back focal length*/ real backFocalLength,
	/*radius first surface*/ real radiusFirstSurface,
	/*radius second surface*/ real radiusSecondSurface,
	/*thickness*/ real centerThickness,
	/*edge thickness*/ real edgeThickness,
	/*material*/ MaterialSellmeier1 material,
	/*price*/ real price,
	/*design wavelength*/ real designWavelength,
	/*free aperture CA*/ real freeApertureCA,
	/*max surface quality*/ real maxSurfaceQuality,
	/*min surface quality*/ real minSurfaceQuality,
	/*centration*/ real centration,
	/*max diameter tolerance*/ real maxDiamterTolerance,
	/*min diameter tolerance*/ real minDiamterTolerance,
	/*tolerance center thickness*/ real toleraceCenterThickness,
	/*coating*/ std::string coating,
	/*min wavelength coating*/ real minWavelengthCoating,
	/*max wavelength coating*/ real maxWavelengthCoating
)
{
	setLensCatalog(lensCatalog);
	setCatalogNumber(item);
	setDiameter(diameter);
	setFocalLength(focalLenght);
	setBackFocalLength(backFocalLength);
	setRadiusFirstSurface(radiusFirstSurface);
	setRadiusSecondSurface(radiusSecondSurface);
	setThickness(centerThickness);
	setEdgeThickness(edgeThickness);
	setMaterial(material);
	setPrice(price);
	setDesignWavelength(designWavelength);
	setFreeAperture(freeApertureCA);
	setMaxSurfaceQuality(maxSurfaceQuality);
	setMinSurfaceQuality(minSurfaceQuality);
	setCentration(centration);
	setMaxDiaTolerance(maxDiamterTolerance);
	setMinDiaTolerance(minDiamterTolerance);
	setToleranceCenterThickness(toleraceCenterThickness);
	setCoating(coating);
	setMinCoatinWavelength(minWavelengthCoating);
	setMaxCoatinWavelength(maxWavelengthCoating);

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

	MaterialSellmeier1 glassA;
	MaterialSellmeier1 glassB;

	MaterialSellmeier1 materialAir;
	materialAir.setParameterAndCalcVd_Ve("Schott", "Air", 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0); // refractive index is 1

	if (mRadiusFirstSurface > 0)
	{
		radiusFirstSurface = std::abs(mRadiusFirstSurface);
		refIndex_A_FirstSurface = refractiveIndexAir;
		refIndex_B_FirstSurface = mMaterial.calcRefractiveIndexSnellmeier1(mWavelengthToTrace);
		glassA = materialAir;
		glassB = mMaterial;
	}


	if (mRadiusFirstSurface < 0)
	{
		// flip direction
		directionFirstSurface.setZ(-1.0);

		radiusFirstSurface = std::abs(mRadiusFirstSurface);
		refIndex_A_FirstSurface = mMaterial.calcRefractiveIndexSnellmeier1(mWavelengthToTrace);
		refIndex_B_FirstSurface = refractiveIndexAir;
		glassA = mMaterial;
		glassB = materialAir;

	}

	//// build first surface
	SphericalElement firstSurface;
	firstSurface.setRadiusValue(radiusFirstSurface);
	firstSurface.setSemiHeightValue(mDiameter / 2);
	firstSurface.setOriginValue({ 0.0,0.0,0.0 });
	firstSurface.setDirectionValue(directionFirstSurface);
	firstSurface.setRefIndexValue_A(refIndex_A_FirstSurface);
	firstSurface.setGlassA(glassA);
	firstSurface.setRefIndexValue_B(refIndex_B_FirstSurface);
	firstSurface.setGlassB(glassB);
	firstSurface.setAllParameterFix();
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
	secondSurface.setGlassA(mMaterial);
	secondSurface.setGlassB(materialAir);
	secondSurface.setRefIndex_B_value(1.0);
	secondSurface.setAllParameterFix();
	secondSurface.buildSurface_LLT();
	surfacePtr secondSurface_ptr = secondSurface.clone();


	mOptSysTwoSurfaces_HLT.fillPosAndElementAndInteraction(0, firstSurface_ptr, refrac_ptr);
	mOptSysTwoSurfaces_HLT.fillPosAndElementAndInteraction(1, secondSurface_ptr, refrac_ptr);
	mOptSysTwoSurfaces_HLT.convertHLTSurfacesToLLTSurfaces();
}


// build optical System with two surfaces
void LensesTwoSurfaces::buildOpticalSystemTwoSurfaces()
{
	if (mWavelengthToTrace < 0.001)
	{
		mWavelengthToTrace = 550.0;
	}

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


	//// build first surface
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
	secondSurface.setOriginValue({ 0.0,0.0,mThickness });
	secondSurface.setDirectionValue(directionSecondSurface);
	secondSurface.setRefIndexValue_A(refIndex_A_SecondSurface);
	secondSurface.setRefIndexValue_B(refIndex_B_SecondSurface);
	secondSurface.setGlassA(materialSellmeier_A_SecondSurface);
	secondSurface.setGlassB(materialSellmeier_B_SecondSurface);
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
	std::string catalogNumber_str = std::to_string(catalogNumber);

	mCatalogNumber = catalogNumber_str;
}
void LensesTwoSurfaces::setCatalogNumber(std::string catalogNumber)
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
// set centration
void LensesTwoSurfaces::setCentration(real centration)
{
	mCentering = centration;
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
// set surface quality
void LensesTwoSurfaces::setSurfaceQuality(std::string surfaceQual)
{
	mSurfaceQuality = surfaceQual;
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
/*Coating Specification*/
void LensesTwoSurfaces::setCoatingSpec(std::string coatingSpecification)
{
	mCoatingSpecification = coatingSpecification;
}
/*Coating min wavelength*/
void LensesTwoSurfaces::setMinCoatinWavelength(real coatingMinWavelength)
{
	mCoatingMinWavelength = coatingMinWavelength;
}
/*Coating max wavelength*/
void LensesTwoSurfaces::setMaxCoatinWavelength(real coatingMaxWavelength)
{
	mCcoatingMaxWavelength = coatingMaxWavelength;
}
/*Irregularity(P-V)@632.8nm*/
void LensesTwoSurfaces::setIrregilarity(real irregularity)
{
	mIrregularity = irregularity;
}
/*F-Number*/
void LensesTwoSurfaces::setF_Number(real F_Number)
{
	mF_Number = F_Number;
}
/*type*/
void LensesTwoSurfaces::setType(std::string type)
{
	mType = type;
}
/*Bevel*/
void LensesTwoSurfaces::setBevel(std::string bevel)
{
	mBevel = bevel;
}
/*Typical Energy Density Limit*/
void LensesTwoSurfaces::setTypicalEnergyDensityLimit(std::string typicalEnergyDensityLimit)
{
	mTypicalEnergyDensityLimit = typicalEnergyDensityLimit;
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
std::string LensesTwoSurfaces::getCatalogNumber()
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
// get surface quality
std::string LensesTwoSurfaces::getSurfaceQuality()
{
	return mSurfaceQuality;
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
// get centration
real LensesTwoSurfaces::getCentration()
{
	return mCentering;
}
/*Coating Specification*/
std::string LensesTwoSurfaces::getCoatingSpec()
{
	return mCoatingSpecification;
}
/*Coating min wavelength*/
real LensesTwoSurfaces::getMinCoatinWavelength()
{
	return mCoatingMinWavelength;
}
/*Coating max wavelength*/
real LensesTwoSurfaces::getMaxCoatinWavelength()
{
	return mCcoatingMaxWavelength;;
}
/*Irregularity(P-V)@632.8nm*/
real LensesTwoSurfaces::getIrregilarity()
{
	return mIrregularity;
}
/*F-Number*/
real LensesTwoSurfaces::getF_Number()
{
	return mF_Number;
}
/*type*/
std::string LensesTwoSurfaces::getType()
{
	return mType;
}
/*Bevel*/
std::string  LensesTwoSurfaces::getBevel()
{
	return mBevel;
}
/*Typical Energy Density Limit*/
std::string  LensesTwoSurfaces::getTypicalEnergyDensityLimit()
{
	return mTypicalEnergyDensityLimit;
}
//---
//---
