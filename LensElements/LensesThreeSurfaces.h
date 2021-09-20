#pragma once
#include "LensesTwoSurfaces.h"

class LensThreeSurfaces
{
public:
	LensThreeSurfaces();
	~LensThreeSurfaces();

	// build an lens with three surfaces (achromat)
	void buildLensThreeSurfaces
	(
		/*lens catalog*/ std::string lensCatalog,
		/*catalog number*/ unsigned int catalogNumber,
		/*diameter*/ real  diameter,
		/*max diameter tolerance*/ real maxDiamterTolerance,
		/*min diameter tolerance*/ real minDiamterTolerance,
		/*focallength*/ real focalLenght,
		/*tolerance focal length*/ real toleranceFocalLength,
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
		/*radius third surface*/ real radiusThirdSurface,
		/*edge thickness*/ real edgeThickness,
		/*material first*/ MaterialSellmeier1 materialFirst,
		/*material second*/ MaterialSellmeier1 materialSecond,
		/*max surface quality*/ real maxSurfaceQuality,
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
	);


	void buildLensThreeSurfaces
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
		/*tolerance center thickness*/ real toleraceCenterThickness,
		/*radius first surface*/ real radiusFirstSurface,
		/*radius second surface*/ real radiusSecondSurface,
		/*radius third surface*/ real radiusThirdSurface,
		/*edge thickness*/ real edgeThickness,
		/*material first*/ MaterialSellmeier1 materialFirst,
		/*material second*/ MaterialSellmeier1 materialSecond,
		/*max surface quality*/ real maxSurfaceQuality,
		/*min surface quality*/ real minSurfaceQuality,
		/*F-Number*/ real F_Number,
		/*numerical aperture*/ real numericalAperture,
		/*coating*/ std::string coating,
		/*coating specification*/ real coatingtionSpecification,
		/*min wavelength coatingting*/ real minWavlengthCoating,
		/*max wavelength coatingting*/ real maxWavlengthCoating,
		/*power PV*/ real powerPV,
		/*curvature PV*/ real curvaturePV,
		/*bevel*/ std::string bevel,
		/*type*/ std::string type,
		/*min wavelength*/ real minWavelength,
		/*max wavelength*/ real maxWavelenght,
		/*price*/ real price,
		/*wavelength to trace*/ real wavelengthToTrace

	);

	void buildLensThreeSurfaces
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
		/*tolerance center thickness*/ real toleraceCenterThickness,
		/*radius first surface*/ real radiusFirstSurface,
		/*radius second surface*/ real radiusSecondSurface,
		/*radius third surface*/ real radiusThirdSurface,
		/*edge thickness*/ real edgeThickness,
		/*material first*/ MaterialSellmeier1 materialFirst,
		/*material second*/ MaterialSellmeier1 materialSecond,
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
		/*price*/ real price,
		/*wavelength to trace*/ real wavelengthToTrace

	);

	void buildLensThreeSurfaces
	(
		/*lens catalog*/ std::string lensCatalog,
		/*catalog number*/ unsigned int catalogNumber,
		/*diameter*/ real  diameter,
		/*max diameter tolerance*/ real maxDiamterTolerance,
		/*min diameter tolerance*/ real minDiamterTolerance,
		/*focallength*/ real focalLenght,
		/*tolerance focal length*/ real toleranceFocalLength,
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
		/*radius third surface*/ real radiusThirdSurface,
		/*edge thickness*/ real edgeThickness,
		/*material first*/ MaterialSellmeier1 materialFirst,
		/*material second*/ MaterialSellmeier1 materialSecond,
		/*max surface quality*/ real maxSurfaceQuality,
		/*min surface quality*/ real minSurfaceQuality,
		/*stop*/ real stop,
		/*numerical aperture*/ real numericalAperture,
		/*coating*/ std::string coating,
		/*coating specification 1*/ std::string coatingtionSpecification1,
		/*coating specification 2*/ std::string coatingtionSpecification2,
		/*coating specification 3*/ std::string coatingtionSpecification3,
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
	);

	void buildLensThreeSurfaces
	(
		/*lens catalog*/ std::string lensCatalog,
		/*catalog number*/ unsigned int catalogNumber,
		/*diameter*/ real  diameter,
		/*max diameter tolerance*/ real maxDiamterTolerance,
		/*min diameter tolerance*/ real minDiamterTolerance,
		/*focallength*/ real focalLenght,
		/*tolerance focal length*/ real toleranceFocalLength,
		/*back focal length*/ real backFocalLength,
		/*design wavelength*/ real designWavelength,
		/*free aperture CA*/ real freeApertureCA,
		/*max centering*/ real maxCentering,
		/*first thickness*/ real firstThicknessCT1,
		/*second thickness*/ real secondThicknessCT2,
		/*tolerance center thickness*/ real toleraceCenterThickness,
		/*radius first surface*/ real radiusFirstSurface,
		/*radius second surface*/ real radiusSecondSurface,
		/*radius third surface*/ real radiusThirdSurface,
		/*edge thickness*/ real edgeThickness,
		/*material first*/ MaterialSellmeier1 materialFirst,
		/*material second*/ MaterialSellmeier1 materialSecond,
		/*max surface quality*/ real maxSurfaceQuality,
		/*min surface quality*/ real minSurfaceQuality,
		/*stop*/ real stop,
		/*numerical aperture*/ real numericalAperture,
		/*coating*/ std::string coating,
		/*coating specification 1*/ std::string coatingtionSpecification1,
		/*coating specification 2*/ std::string coatingtionSpecification2,
		/*coating specification 3*/ std::string coatingtionSpecification3,
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
	);

	void buildLensThreeSurfaces
	(
		/*lens catalog*/ std::string lensCatalog,
		/*catalog number*/ unsigned int catalogNumber,
		/*diameter*/ real  diameter,
		/*max diameter tolerance*/ real maxDiamterTolerance,
		/*min diameter tolerance*/ real minDiamterTolerance,
		/*focallength*/ real focalLenght,
		/*tolerance focal length*/ real toleranceFocalLength,
		/*back focal length*/ real backFocalLength,
		/*design wavelength*/ real designWavelength,
		/*free aperture CA*/ real freeApertureCA,
		/*max centering*/ real maxCentering,
		/*first thickness*/ real firstThicknessCT1,
		/*second thickness*/ real secondThicknessCT2,
		/*tolerance center thickness*/ real toleraceCenterThickness,
		/*radius first surface*/ real radiusFirstSurface,
		/*radius second surface*/ real radiusSecondSurface,
		/*radius third surface*/ real radiusThirdSurface,
		/*edge thickness*/ real edgeThickness,
		/*material first*/ MaterialSellmeier1 materialFirst,
		/*material second*/ MaterialSellmeier1 materialSecond,
		/*max surface quality*/ real maxSurfaceQuality,
		/*min surface quality*/ real minSurfaceQuality,
		/*numerical aperture*/ real numericalAperture,
		/*coating*/ std::string coating,
		/*coating specification 1*/ std::string coatingtionSpecification1,
		/*coating specification 2*/ std::string coatingtionSpecification2,
		/*coating specification 3*/ std::string coatingtionSpecification3,
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
	);


	void buildLensThreeSurfaces
	(

		// https://www.thorlabs.com/newgrouppage9.cfm?objectgroup_id=12767
		/*lens catalog*/ std::string lensCatalog,
		/*catalog number*/ std::string Item,
		/*diameter*/ real  diameter,
		/* focallength*/ real focalLenght,
		/*back focal length*/ real backFocalLength,
		/*radius first surface*/ real radiusFirstSurface,
		/*radius second surface*/ real radiusSecondSurface,
		/*radius third surface*/ real radiusThirdSurface,
		/*first thickness*/ real firstThicknessCT1,
		/*second thickness*/ real secondThicknessCT2,
		/*edge thickness*/ real edgeThickness,
		/*material first*/ MaterialSellmeier1 materialFirst,
		/*material second*/ MaterialSellmeier1 materialSecond,
		/*price*/ real price,
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
		/*max wavelength*/ real maxWavelenght
	);

	void buildLensThreeSurfaces_Qioptiq_lenses
	(
		// https://www.qioptiq-shop.com/en/Precision-Optics/LINOS-Achromats-Lens-Systems/Achromats-positive/Achromats-VIS-Positive-dia-3-mm-to-31-5-mm-unmounted.html#popup_G322218000

		/*lens catalog*/ std::string lensCatalog,
		/*catalog number*/ std::string partNumber,
		/*diameter*/ real  diameter,
		/*focallength*/ real focalLenght,
		/*optical centering accurancy*/ real centering,
		/*surface quality*/ std::string surfaceQuality,
		/*edge thickness*/ real edgeThickness,
		/*back focal length*/ real backFocalLength,
		/*min wavelength*/ real minWavelength,
		/*max wavelength*/ real maxWavelenght,
		/*coating*/ std::string coating,
		/*caoting specification*/ std::string coatinSpecification,
		/*radius first surface*/ real radiusFirstSurface,
		/*radius second surface*/ real radiusSecondSurface,
		/*radius thrid surface*/ real radiusThridSurface,
		/*thickness first*/ real centerThicknessFirst,
		/*thickness second*/ real centerThicknessSecond,
		/*tolerance center thickness*/ real toleranceCenterThickness,
		/*material first*/ MaterialSellmeier1 materialFirst,
		/*material second*/ MaterialSellmeier1 materialSecond,
		/*price*/ real price
	);

	// build an optical system with three surfaces
	void buildOpticalSystemThreeSurfaces();

	// get HLT three surfaces
	OpticalSystemElement getHLT_ThreeSurfaces();




	// set functions
	// set lens catalog
	void setLensCatalog(std::string lensCatalog);
	// set number in catalog
	void setCatalogNumber(std::string catalogNumber);
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
	// set tolerance center Thickness
	void setToleranceCenterThickness(real const toleranceCenterThickness);
	// set radius first surface
	void setRadiusFirstSurface(real const radiusFirstSurface);
	// set radius second surface
	void setRadiusSecondSurface(real const radiusSecondSurface);
	// set radius third surface
	void setRadiusThirdSurface(real const radiusThirdSurface);
	// set edge thickness 
	void setEdgeThickness(real const edgeThickness);
	// set material first
	void setMaterialFirst(MaterialSellmeier1 const materialFirst);
	// set material second
	void setMaterialSecond(MaterialSellmeier1 const materialSecond);
	// set max surface quality
	void setMaxSurfaceQuality(real const maxSurfaceQuality);
	// set min surface quality
	void setMinSurfaceQuality(real const minSurfaceQuality);
	// set surface quality
	void setSurfaceQuality(std::string surfaceQuality);
	// set stop
	void setStop(real const stop);
	// set numerical aperture
	void setNumericalAperture(real const numericalAperture);
	// set coating
	void setCoating(std::string const coating);
	//set coating specification
	void setCoatingSpecification(real const coatingSpecification);
	//set coating specification
	void setCoatingSpecification(std::string coatingSpecification);
	//set coating specification 1
	void setCoatingSpecification1(std::string coatingSpecification1);
	//set coating specification 2
	void setCoatingSpecification2(std::string coatingSpecification2);
	//set coating specification 3
	void setCoatingSpecification3(std::string coatingSpecification3);
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
	// set first design wavelength
	void setFirstDesignWavelength(real firstDW);
	// set second design wavelength
	void setSecondDesignWavelength(real secondDW);
	// set third design wavelength
	void setThirdDesignWavelength(real thirdDW);
	// set centration
	void setCentration(real centration);
	// set f number
	void setF_Number(real F_Number);
	/*min wavelength coatingting*/
	void setMinWavelengthCoating(real minWavlengthCoating);
	/*max wavelength coatingting*/
	void setMaxWavelengthCoating(real maxWavlengthCoating);

	// *** *** // get functions
	// get lens catalog
	std::string getLensCatalog();
	// get number in catalog
	std::string getCatalogNumber();
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
	// get tolerance center Thickness
	real getToleranceCenterThickness();
	// get radius first surface
	real getRadisuFirstSurface();
	// get radius second surface
	real getRadisuSecondSurface();
	// get radius third surface
	real getRadiusThirdSurface();
	// get edge thickness 
	real getEdgeThickness();
	// get material first
	MaterialSellmeier1 getMaterialFirst();
	// get material second
	MaterialSellmeier1 getMaterialSecond();
	// get max surface quality
	real getMaxSurfaceQuality();
	// get min surface quality
	real getMinSurfaceQuality();
	// get surface quality
	std::string getSurfaceQuality();
	// get stop
	real getStop();
	// get numerical aperture
	real getNumericalAperture();
	// get coating
	std::string getCoating();
	//get coating specification
	real getCoatingSpecification();
	//get coating specification
	std::string getCoatingSpecification_string();
	//get coating specification 1
	std::string getCoatingSpecification1_string();
	//get coating specification 2
	std::string getCoatingSpecification2_string();
	//get coating specification 3
	std::string getCoatingSpecification3_string();

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
	// get first design wavelength
	real getFirstDesignWavelength();
	// get second design wavelength
	real getSecondDesignWavelength();
	// get third design wavelength
	real getThirdDesignWavelength();
	// get centration
	real getCentration();
	// get f number
	real getF_Number(real F_Number);
	/*min wavelength coatingting*/
	real getMinWavelengthCoating(real minWavlengthCoating);
	/*max wavelength coatingting*/
	real getMaxWavelengthCoating(real maxWavlengthCoating);

private:
	std::string mLensCatalog{};
	std::string mCatalogNumber{};
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
	real mToleraceCenterThickness{};
	real mRadiusFirstSurface{};
	real mRadiusSecondSurface{};
	real mRadiusThirdSurface{};
	real mEdgeThickness{};
	MaterialSellmeier1 mMaterialFirst{};
	MaterialSellmeier1 mMaterialSecond{};
	real mMaxSurfaceQuality{};
	real mMinSurfaceQuality{};
	std::string mSurfaceQuality{};
	real mStop{};
	real mNumericalAperture{};
	std::string mCoating{};
	real mCoatingtionSpecification{};
	std::string mCoatingtionSpec{};

	std::string mCoatingtionSpec1{};
	std::string mCoatingtionSpec2{};
	std::string mCoatingtionSpec3{};

	real mPowerWavelength{};
	real mPowerPV{};
	real mCurvatureWavelength{};
	real mCurvaturePV{};
	std::string mBevel{};
	std::string mType{};
	real mMinWavelength{};
	real mMaxWavelenght{};
	real mPrice{};
	real mWavelengthToTrace{};
	real mFocalLength{};

	real mFirstDesignWavelength{};
	real mSecondDesignWavelength{};
	real mThirdDesignWavelength{};

	real mF_Number{};
	real mMinWavelengthCoating{};
	real mMaxWavelengthCoating{};

	real mCentration{};

	OpticalSystemElement mOptSysThreeSurfaces_HLT{};
};
