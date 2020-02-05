#pragma once
#include "..\..\Glasses\GlassDispersionFormulas\MaterialSellmeier1.h"
#include "..\..\OpticalSystemElement\OpticalSystemElement.h"

class LensThreeSurfaces 
{
	public:
		LensThreeSurfaces();
		~LensThreeSurfaces();

		// build an lens with three surfaces (achromat)
		void buildLensThreeSurfaces
		(
			/*diameter*/ real  diameter,
			/*max diameter tolerance*/ real maxDiamterTolerance,
			/*min diameter tolerance*/ real minDiamterTolerance,
			/* focallength*/ real focalLenght,
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
		);

		// build an optical system with three surfaces
		void buildOpticalSystemThreeSurfaces();

		// get HLT three surfaces
		OpticalSystemElement getHLT_ThreeSurfaces();

			
		

		// set functions
		// set diameter
		void setDiameter(real const& diameter);
		// set max diameter tolerance
		void setMaxDiameterTolerance(real const& maxDiaTolerance);
		// set min diameter tolerance
		void setMinDiameterTolerance(real const& minDiaTolerance);
		// set focal lenght
		void setFocalLength(real const& focalLength);
		// set tolerance focal length
		void setToleranceFocalLength(real const& toleranceFocalLength);
		// set back focal lenght
		void setBackFocalLength(real const& backFocalLength);
		// set design wavelength
		void setDesignWavelength(real const& designWavelenght);
		// set free aperture
		void setFreeAperture(real const& freeAperture);
		// set min centering
		void setMinCentering(real const& minCentering);
		// set max centering
		void setMaxCentering(real const& maxCentering);
		// set first thickness
		void setFirstThickness(real const& firstThickness);
		// set second thickness
		void setSecondThickness(real const& secondThickness);
		// set tolerance center Thickness
		void setToleranceCenterThickness(real const& toleranceCenterThickness);
		// set radius first surface
		void setRadisuFirstSurface(real const& radiusFirstSurface);
		// set radius second surface
		void setRadisuSecondSurface(real const& radiusSecondSurface);
		// set radius third surface
		void setRadisuthirdSurface(real const& radiusThirdSurface);
		// set edge thickness 
		void setEdgeThickness(real const& edgeThickness);
		// set material first
		void setMaterialFirst(MaterialSellmeier1 const& materialFirst);
		// set material second
		void setMaterialSecond(MaterialSellmeier1 const& materialSecond);
		// set max surface quality
		void setMaxSurfaceQuality(real const& maxSurfaceQuality);
		// set min surface quality
		void setMinSurfaceQuality(real const& minSurfaceQuality);
		// set stop
		void setStop(real const& stop);
		// set numerical aperture
		void setNumericalAperture(real const& numericalAperture);
		// set coating
		void setCoating(std::string const& coating);
		//set coating specification
		void setCoatingSpecification(real const& coatingSpecification);
		// set power wavelength
		void setPowerWavelength(real const& powerWave);
		// set power PV
		void setPowerPV(real const& powerPV);
		// set curvature wavelength
		void setCurvatureWave(real const& curvatureWave);
		// set curvature PV
		void setCurvaturePV(real const& curvaturePV);
		// set bevel
		void setBevel(std::string const& bevel);
		// set type
		void setType(std::string const& type);
		// set minimal wavelength
		void setMinimalWavelength(real const& minWave);
		// set maximum wavelength
		void setMaximumWavelength(real const& maxWave);
		// set price
		void setPrice(real const& price);
		// set wavelengthToTrace
		void setWavelenghtToTrace(real const& waveToTrace);

		// *** *** // get functions
		// focal length
		real getFocalLenth();
		// thickness 
		real getThickness();
		// semi height
		real getSemiHeight();

	private:

		real mDiameter;
		real mMaxDiamterTolerance;
		real mMinDiamterTolerance;
		real mToleranceFocallength;
		real mBackFocalLength;
		real mDesignWavelength;
		real mFreeApertureCA;
		real mMinCentering;
		real mMaxCentering;
		real mFirstThicknessCT1;
		real mSecondThicknessCT2;
		real mToleraceCenterThickness;
		real mRadiusFirstSurface;
		real mRadiusSecondSurface;
		real mRadiusThirdSurface;
		real mEdgeThickness;
		MaterialSellmeier1 mMaterialFirst;
		MaterialSellmeier1 mMaterialSecond;
		real mMaxSurfaceQuality;
		real mMinSurfaceQuality;
		real mStop;
		real mNumericalAperture;
		std::string mCoating;
		real mCoatingtionSpecification;
		real mPowerWavelength;
		real mPowerPV;
		real mCurvatureWavelength;
		real mCurvaturePV;
		std::string mBevel;
		std::string mType;
		real mMinWavelength;
		real mMaxWavelenght;
		real mPrice;
		real mWavelengthToTrace;
		real mFocalLength;

		OpticalSystemElement mOptSysThreeSurfaces_HLT;
};
