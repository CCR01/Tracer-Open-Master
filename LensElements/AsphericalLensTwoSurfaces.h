#pragma once

#include "..\..\Glasses\GlassDispersionFormulas\MaterialSellmeier1.h"
#include "..\OpticalSystemElement\OpticalSystemElement.h"

class  AsphericalLensTwoSurfaces
{
public:
	 AsphericalLensTwoSurfaces();
	~ AsphericalLensTwoSurfaces();

	//https://www.edmundoptics.de/f/precision-aspheric-lenses/13139/
	void buildAsphericalLensTwoSurfaces 
	( 	/*diameter*/ real  diameter,
		/*max tolerance diameter*/ real  maxDiamterTolerance,
		/*min tolerance diameter*/ real  minDiamterTolerance,
		/*numerical Aperture*/ real  numericalAperture,
		/*design wavelength*/ real  designWavelength,
		/*tolerance center thickness*/ real  toleraceCenterThickness,
		/*material*/ MaterialSellmeier1  material,
		/*Aspherical shape defect (µm RMS)*/ real  asphericalShapeDefects,
		/*edge thickness*/ real  edgeThickness,
		/*aperture*/ real  aperture,
		/*min wavelength range*/ real  minWavelength,
		/*max wavelength range*/ real  maxWavelength,
		/*focal length*/ real  focalLength,
		/*back focal length*/ real  backFocalLength,
		/*center thickness*/ real  thickness,
		/*Coating*/ std::string  coating,
		/*free Aperture*/ real  freeAperture,
		/*max surface quality*/ real  maxSurfaceQuality,
		/*min surface quality*/ real  minSurfaceQuality,
		/*Centering (arc minutes)*/ real  centering,
		/*radius first surface*/ real  radiusFirstSurface,
		/*conic*/ real  conic,
		/*2nd term*/ real  second,
		/*4nd term*/ real  fourth,
		/*6nd term*/ real  sixth,
		/*8nd term*/ real  eighth,
		/*10nd term*/ real  tenth,
		/*12nd term*/ real  twelfth,
		/*14nd term*/ real  fourteenth,
		/*16nd term*/ real  sixteenth,
		/*radius second surface*/ real  radiusSecondSurface
	);

	// TODO: Write all set and get function!!!

		

private:

	/*diameter*/ real mDiameter;
	/*max tolerance diameter*/ real mMaxDiamterTolerance;
	/*min tolerance diameter*/ real mMinDiamterTolerance;
	/*numerical Aperture*/ real mNumericalAperture;
	/*design wavelength*/ real mDesignWavelength;
	/*tolerance center thickness*/ real mToleraceCenterThickness;
	/*material*/ MaterialSellmeier1 mMaterial;
	/*Aspherical shape defect (µm RMS)*/ real mAsphericalShapeDefects;
	/*edge thickness*/ real mEdgeThickness;
	/*aperture*/ real mAperture;
	/*min wavelength range*/ real mMinWavelength;
	/*max wavelength range*/ real mMaxWavelength;
	/*focal length*/ real mFocalLength;
	/*back focal length*/ real mBackFocalLength;
	/*center thickness*/ real mThickness;
	/*Coating*/ std::string mCoating;
	/*free Aperture*/ real mFreeAperture;
	/*max surface quality*/ real mMaxSurfaceQuality;
	/*min surface quality*/ real mMinSurfaceQuality;
	/*Centering (arc minutes)*/ real mCentering;
	/*radius first surface*/ real mRadiusFirstSurface;
	/*conic*/ real mConic;
	/*2nd term*/ real mSecond;
	/*4nd term*/ real mFourth;
	/*6nd term*/ real mSixth;
	/*8nd term*/ real mEighth;
	/*10nd term*/ real mTenth;
	/*12nd term*/ real mTwelfth;
	/*14nd term*/ real mFourteenth;
	/*16nd term*/ real mSixteenth;
	/*radius second surface*/ real mRadiusSecondSurface;
};
