#pragma once

#include <string>
// glasses
#include "..\..\Glasses\GlassDispersionFormulas\MaterialSellmeier1.h"
// optical system element
#include "..\..\OpticalSystemElement\OpticalSystemElement.h"

class LensFourSurfaces
{
public:
	LensFourSurfaces();
	~LensFourSurfaces();

	void buildLensFourSurfaces
	(
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
	);

	void buildLensFourSurfaces
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
	);

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
	);

	void buildLensFourSurfaces
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
	);


	// build the optical system wit four surfaces
	void buildOpticalSystemFourSurfaces();
	// get HLT three surfaces
	OpticalSystemElement getHLT_FourSurfaces();


	// set functions
	// set lens catalog
	void setLensCatalog(std::string lensCatalog);
	// set number in catalog
	void setCatalogNumber(unsigned int catalogNumber);
	// set diameter
	void setDiameter(real const diameter);
	// set max diameter tolerance
	void setMaxDiameterTolerance(real const maxDiaTolerance);
	// set min diameter tolerance
	void setMinDiameterTolerance(real const minDiaTolerance);
	// set focal lenght
	void setFocalLength(real const focalLength);
	// set tolerance focal length
	void setToleranceFocalLength(real const toleranceFocalLength);
	// set back focal lenght
	void setBackFocalLength(real const backFocalLength);
	// set design wavelength
	void setDesignWavelength(real const designWavelenght);
	// set free aperture
	void setFreeApertureCA(real const freeAperture);
	// set min centering
	void setMinCentering(real const minCentering);
	// set max centering
	void setMaxCentering(real const maxCentering);
	// set first thickness
	void setFirstThickness(real const firstThickness);
	// set second thickness
	void setSecondThickness(real const secondThickness);
	// set third thickness
	void setThirdThickness(real thirdThickness);
	// set tolerance center Thickness
	void setToleranceCenterThickness(real const toleranceCenterThickness);
	// set radius first surface
	void setRadiusFirstSurface(real const radiusFirstSurface);
	// set radius second surface
	void setRadiusSecondSurface(real const radiusSecondSurface);
	// set radius third surface
	void setRadiusThirdSurface(real const radiusThirdSurface);
	// set radius fourth surface
	void setRadiusFourthSurface(real radiusFourthSurface);
	// set edge thickness 
	void setEdgeThickness(real const edgeThickness);
	// set material first
	void setMaterialFirst(MaterialSellmeier1 const materialFirst);
	// set material second
	void setMaterialSecond(MaterialSellmeier1 const materialSecond);
	// set material third
	void setMaterialThird(MaterialSellmeier1 materialThird);
	// set max surface quality
	void setMaxSurfaceQuality(real const maxSurfaceQuality);
	// set min surface quality
	void setMinSurfaceQuality(real const minSurfaceQuality);
	// set stop
	void setStop(real const stop);
	// set numerical aperture
	void setNumericalAperture(real const numericalAperture);
	// set coating
	void setCoating(std::string const coating);
	//set coating specification
	void setCoatingSpecification(real const coatingSpecification);
	// set power wavelength
	void setPowerWavelength(real const powerWave);
	// set power PV
	void setPowerPV(real const powerPV);
	// set curvature wavelength
	void setCurvatureWave(real const curvatureWave);
	// set curvature PV
	void setCurvaturePV(real const curvaturePV);
	// set bevel
	void setBevel(std::string const bevel);
	// set type
	void setType(std::string const type);
	// set minimal wavelength
	void setMinimalWavelength(real const minWave);
	// set maximum wavelength
	void setMaximumWavelength(real const maxWave);
	// set price
	void setPrice(real const price);
	// set wavelengthToTrace
	void setWavelenghtToTrace(real const waveToTrace);
	// set item
	void setItem(std::string item);
	// set first design wavelength
	void setFirstDesignWavelength(real firstDW);
	// set second design wavelength
	void setSecondDesignWavelength(real secondDW);
	// set third design wavelength
	void setThirdDesignWavelength(real thirdDW);
	// set centration
	void setCentration(real centration);
	// working distance
	void setWorkingDistance(real workingDistance);
	void setWorkingDistance2(real workingDistance2);
	void setF_Number(real F_Number);
	void setMinWavlengthCoating(real minWavlengthCoating);
	void setMaxWavlengthCoating(real maxWavlengthCoating);
	void setIrregularityPV(real irregularity);

	// *** *** // get functions
	// get lens catalog
	std::string getLensCatalog();
	// get number in catalog
	unsigned int getCatalogNumber();
	// get diameter
	real getDiameter();
	// get max diameter tolerance
	real getMaxDiameterTolerance();
	// get min diameter tolerance
	real getMinDiameterTolerance();
	// get focal lenght
	real getFocalLength();
	// get tolerance focal length
	real getToleranceFocalLength();
	// get back focal lenght
	real getBackFocalLength();
	// get design wavelength
	real getDesignWavelength();
	// get free aperture
	real getFreeAperture();
	// get min centering
	real getMinCentering();
	// get max centering
	real getMaxCentering();
	// get first thickness
	real getFirstThickness();
	// get second thickness
	real getSecondThickness();
	// get third thickness
	real getThirdThickness();
	// get tolerance center Thickness
	real getToleranceCenterThickness();
	// get radius first surface
	real getRadisuFirstSurface();
	// get radius second surface
	real getRadisuSecondSurface();
	// get radius third surface
	real getRadiusThirdSurface();
	// get radius fourth surface
	real getRadiusFourthSurface();
	// get edge thickness 
	real getEdgeThickness();
	// get material first
	MaterialSellmeier1 getMaterialFirst();
	// get material second
	MaterialSellmeier1 getMaterialSecond();
	// get material third
	MaterialSellmeier1 getMaterialThird();
	// get max surface quality
	real getMaxSurfaceQuality();
	// get min surface quality
	real getMinSurfaceQuality();
	// get stop
	real getStop();
	// get numerical aperture
	real getNumericalAperture();
	// get coating
	std::string getCoating();
	//get coating specification
	real getCoatingSpecification();
	// get power wavelength
	real getPowerWavelength();
	// get power PV
	real getPowerPV();
	// get curvature wavelength
	real getCurvatureWave();
	// get curvature PV
	real getCurvaturePV();
	// get bevel
	std::string getBevel();
	// get type
	std::string getType();
	// get minimal wavelength
	real getMinimalWavelength();
	// get maximum wavelength
	real getMaximumWavelength();
	// get price
	real getPrice();
	// get wavelengthToTrace
	real getWavelenghtToTrace();
	// get item
	std::string getItem();
	// get first design wavelength
	real getFirstDesignWavelength();
	// get second design wavelength
	real getSecondDesignWavelength();
	// get third design wavelength
	real getThirdDesignWavelength();
	// get centration
	real getCentration();
	// get working distance
	real getWorkingDistance();
	real getWorkingDistance2();
	real getF_Number();
	real getMinWavlengthCoating();
	real getMaxWavlengthCoating();
	real getIrregularityPV();

private:
	std::string mLensCatalog{};
	unsigned int mCatalogNumber{};
	real mDiameter{};
	real mMaxDiamterTolerance{};
	real mMinDiamterTolerance{};
	real mToleranceFocallength{};
	real mBackFocalLength{};
	real mDesignWavelength{};
	real mFreeApertureCA{};
	real mMinCentering{};
	real mMaxCentering{};
	real mFirstThicknessCT1{};
	real mSecondThicknessCT2{};
	real mThirdThicknessCT3{};
	real mToleraceCenterThickness{};
	real mRadiusFirstSurface{};
	real mRadiusSecondSurface{};
	real mRadiusThirdSurface{};
	real mRadiusFourthSurface{};
	real mEdgeThickness{};
	MaterialSellmeier1 mMaterialFirst{};
	MaterialSellmeier1 mMaterialSecond{};
	MaterialSellmeier1 mMaterialThird{};
	real mMaxSurfaceQuality{};
	real mMinSurfaceQuality{};
	real mStop{};
	real mNumericalAperture{};
	std::string mCoating{};
	real mCoatingtionSpecification{};
	real mPowerWavelength{};
	real mPowerPV{};
	real mIrregularityPV{};
	real mCurvatureWavelength{};
	real mCurvaturePV{};
	std::string mBevel{};
	std::string mType{};
	real mMinWavelength{};
	real mMaxWavelenght{};
	real mPrice{};
	real mWavelengthToTrace{};
	real mFocalLength{};
	std::string mItem{};

	real mFirstDesignWavelength{};
	real mSecondDesignWavelength{};
	real mThirdDesignWavelength{};

	real mWorkingDistance{};
	real mWorkingDistance2{};
	real mCentration{};

	real mMaxDiameterTolerance{};
	real mMinDiameterTolerance{};
	real mF_Number{};
	real mMinWavlengthCoating{};
	real mMaxWavlengthCoating{};

	OpticalSystemElement mOptSysFourSurfaces_HLT{};
};

