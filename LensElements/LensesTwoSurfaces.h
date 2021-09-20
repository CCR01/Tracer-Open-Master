#pragma once
#include <string>


#include "..\..\Glasses\GlassDispersionFormulas\MaterialSellmeier1.h"
#include "..\..\OpticalSystemElement\OpticalSystemElement.h"

class LensesTwoSurfaces
{
public:
	LensesTwoSurfaces();
	~LensesTwoSurfaces();



	// build lens with two surfaces // https://www.edmundoptics.de/f/vis-nir-coated-double-convex-dcx-lenses/13504/
	void buildLensTwoSurfaces_DCX(

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
		/*wavelength to trace through optical system*/ real const wavelenghtToTrace);

	void buildLensTwoSurfaces_PCX //https://www.edmundoptics.de/f/vis-nir-coated-plano-convex-pcx-lenses/12278/
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
		/*wavelength to trace through optical system*/ real const wavelenghtToTrace
	);

	void buildLensTwoSurfaces_PCX //https://www.edmundoptics.de/f/micro-plano-convex-pcx-lenses/39529/
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
	);

	void buildLensTwoSurfaces_PCX //https://www.edmundoptics.de/f/micro-plano-convex-pcx-lenses/39529/
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
	);

	void buildLensTwoSurfaces_PCX //https://www.edmundoptics.de/f/micro-plano-convex-pcx-lenses/39529/
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
	);

	void buildLensTwoSurfaces_PCX_uncoated //https://www.edmundoptics.de/f/micro-plano-convex-pcx-lenses/39529/
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
	);


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
	);

	void buildLensTwoSurfaces_PCX_uncoated //https://www.edmundoptics.de/f/micro-plano-convex-pcx-lenses/39529/
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
	);

	void buildLensTwoSurfaces_PCX //https://www.edmundoptics.de/f/large-pcx-condenser-lenses/13572/
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
	);


	void buildLensTwoSurfaces_Thorlabs_oneSurfacePlan
	(
		// https://www.thorlabs.de/newgrouppage9.cfm?objectgroup_id=13685
		// https://www.thorlabs.de/newgrouppage9.cfm?objectgroup_id=6509

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
	);

	void buildLensTwoSurfaces_Qioptiq_oneSurfacePlan
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
	);

	void buildLensTwoSurfaces_Qioptiq_lenses
	(
		// https://www.qioptiq-shop.com/en/Precision-Optics/Singlets/Symmetric-Convex-Lenses/Symmetric-convex-lenses-unmounted.html

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
	);


	void buildLensTwoSurfaces_DCV // https://www.edmundoptics.de/f/vis-nir-coated-double-concave-dcv-lenses/13540/
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
	);

	void buildLensTwoSurfaces_thorlabs
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
	);

	void buildLensTwoSurfaces_thorlabs_Uncoated
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
	);

	void buildLensTwoSurfaces_thorlabs_coated
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
	);


	void buildLensTwoSurfaces_PCV // https://www.edmundoptics.de/f/vis-nir-coated-plano-concave-pcv-lenses/13512/
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
	);


	// build optical System with two surfaces
	void buildOpticalSystemTwoSurfaces();
	void buildOpticalSystemTwoSurfaces_OneSurfacePlan();
	// get HLT of the two lenses
	OpticalSystemElement getHLT_TwoSurfaces();

	// set functions
	//---
	// set lens catalog
	void setLensCatalog(std::string lensCatalog);
	// set number in catalog
	void setCatalogNumber(unsigned int catalogNumber);
	void setCatalogNumber(std::string catalogNumber);
	// set diameter
	void setDiameter(real const diamerter);
	// set min diameter tolerance
	void setMinDiaTolerance(real const minDiaTolerance);
	// set max diameter tolerance
	void setMaxDiaTolerance(real maxDiaTolerace);
	// set real max surface quality; 
	void setMaxSurfaceQuality(real const maxSurQual);
	// set real min surface quality; 
	void setMinSurfaceQuality(real const minSurQual);
	// set surface quality
	void setSurfaceQuality(std::string surfaceQual);
	// set curvature PV
	void setCurvaturePV(real const curvaturePV);
	// set tolerance center thickness
	void setToleranceCenterThickness(real const toleranceCenterThickness);
	// set radius first surface
	void setRadiusFirstSurface(real radiusFirstSurface);
	// set radius second surface
	void setRadiusSecondSurface(real const radiusSecondSurface);
	// tolerance focal length
	void setToleranceFocallength(real const toleranceFocallength);
	// set min wavelength
	void setMinWavelength(real const minWave);
	// set max wavelength
	void setMaxWavelength(real const maxWave);
	// set coating
	void setCoating(std::string const coating);
	// set material
	void setMaterial(MaterialSellmeier1 const material);
	// set power PV
	void setPowerPV(real const powerPV);
	// set min center
	void setMinCenter(real const minCenter);
	// set max center
	void setMaxCenter(real const maxCenter);
	// set thickness
	void setThickness(real const thickness);
	// set edge thickness
	void setEdgeThickness(real const edgeThickness);
	// set design wavelength
	void setDesignWavelength(real const wavelength);
	// set numerical aperture
	void setNumericalAperture(real const numericalAperture);
	// set price
	void setPrice(real const price);
	// set wavelength to trace
	void setWavelengthToTrace(real const wavelengthToTrace);
	// set optical system two surfaces
	void setOpticalSystemTwoSurfaces(OpticalSystemElement const lenseTwoSurfaces);
	// set centering
	void setCentering(real const centering);
	// set focal length
	void setFocalLength(real const focalLength);
	// set free apertur
	void setFreeAperture(real const freeAperture);
	// set back focal length
	void setBackFocalLength(real const backFocalLength);
	// set centration
	void setCentration(real centration);
	/*Coating Specification*/
	void setCoatingSpec(std::string coatingSpecification);
	/*Coating min wavelength*/
	void setMinCoatinWavelength(real coatingMinWavelength);
	/*Coating max wavelength*/
	void setMaxCoatinWavelength(real coatingMaxWavelength);
	/*Irregularity(P-V)@632.8nm*/
	void setIrregilarity(real irregularity);
	/*F-Number*/
	void setF_Number(real F_Number);
	/*type*/
	void setType(std::string type);
	/*Bevel*/
	void setBevel(std::string bevel);
	/*Typical Energy Density Limit*/
	void setTypicalEnergyDensityLimit(std::string typicalEnergyDensityLimit);
	//---

	// get functions
	//---
	// get lens catalog
	std::string getLensCatalog();
	// get number in catalog
	std::string getCatalogNumber();
	// get diameter
	real getDiameter();
	// get min diameter tolerance
	real getMinDiaTolerance();
	// get max diameter tolerance
	real getMaxDiaTolerance();
	// get real max surface quality; 
	real getMaxSurfaceQuality();
	// get real min surface quality; 
	real getMinSurfaceQuality();
	// get surface quality
	std::string getSurfaceQuality();
	// get curvature PV
	real getCurvaturePV();
	// get tolerance center thickness
	real getToleranceCenterThickness();
	// get radius first surface
	real getRadiusFirstSurface();
	// get radius second surface
	real getRadiusSecondSurface();
	// tolerance focal length
	real getToleranceFocallength();
	// get min wavelength
	real getMinWavelength();
	// get max wavelength
	real getMaxWavelength();
	// get coating
	std::string getCoating();
	// get material
	MaterialSellmeier1 getMaterial();
	// get power PV
	real getPowerPV();
	// get min center
	real getMinCenter();
	// get max center
	real getMaxCenter();
	// get thickness
	real getThickness();
	// get edge thickness
	real getEdgeThickness();
	// get design wavelength
	real getDesignWavelength();
	// get numerical aperture
	real getNumericalAperture();
	// get price
	real getPrice();
	// get wavelength to trace
	real getWavelengthToTrace();
	// get optical system two surfaces
	OpticalSystemElement getOpticalSystemTwoSurfaces();
	// get centering
	real getCentering();
	// get focal length
	real getFocalLength();
	// get free apertur
	real getFreeAperture();
	// get back focal length
	real getBackFocalLength();
	// get centration
	real getCentration();
	/*Coating Specification*/
	std::string getCoatingSpec();
	/*Coating min wavelength*/
	real getMinCoatinWavelength();
	/*Coating max wavelength*/
	real getMaxCoatinWavelength();
	/*Irregularity(P-V)@632.8nm*/
	real getIrregilarity();
	/*F-Number*/
	real getF_Number();
	/*type*/
	std::string getType();
	/*Bevel*/
	std::string  getBevel();
	/*Typical Energy Density Limit*/
	std::string  getTypicalEnergyDensityLimit();
	//---

private:
	std::string mLensCatalog{};
	std::string mCatalogNumber{};
	real mDiameter{};
	real mMaxDiamterTolerance{};
	real mMinDiamterTolerance{};
	real mBackFocalLength{};
	std::string mSurfaceQuality{};
	real mMaxSurfaceQuality{};
	real mMinSurfaceQuality{};
	real mCurvaturePV{};
	real mToleraceCenterThickness{};
	real mRadiusFirstSurface{};
	real mRadiusSecondSurface{};
	real mToleranceFocallength{};
	real mMinWavelength{};
	real mMaxWavelenght{};
	std::string mCoating{};
	MaterialSellmeier1 mMaterial{};
	real mPowerPV{};
	real mMinCenter{};
	real mMaxCenter{};
	real mThickness{};
	real mEdgeThickness{};
	real mDesignWavelength{};
	real mNumericalAperture{};
	real mPrice{};
	real mWavelengthToTrace{};
	real mCentering{};
	real mFocalLength{};
	real mFreeAperture{};

	real mCentration{};

	/*Coating Specification*/
	std::string mCoatingSpecification{};
	/*Coating min wavelength*/
	real mCoatingMinWavelength{};
	/*Coating max wavelength*/
	real mCcoatingMaxWavelength{};
	/*Irregularity(P-V)@632.8nm*/
	real mIrregularity{};
	/*F-Number*/
	real mF_Number{};
	/*type*/
	std::string mType{};
	/*Bevel*/
	std::string mBevel{};
	/*Typical Energy Density Limit*/
	std::string mTypicalEnergyDensityLimit{};
	//---

	OpticalSystemElement mOptSysTwoSurfaces_HLT{};

};

