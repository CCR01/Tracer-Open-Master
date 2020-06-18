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
	//---

	// *** *** // -> get functions
	// focal length
	real getFocalLength();
	// thickness
	real getThickness();
	// semi height
	real getSemiHeight();

private:
	std::string mLensCatalog{};
	unsigned int mCatalogNumber{};
	real mDiameter{};
	real mMaxDiamterTolerance{};
	real mMinDiamterTolerance{};
	real mBackFocalLength{};
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

	OpticalSystemElement mOptSysTwoSurfaces_HLT{};

};

