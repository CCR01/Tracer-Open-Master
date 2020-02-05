#include "AsphericalLensTwoSurfaces.h"

AsphericalLensTwoSurfaces::AsphericalLensTwoSurfaces() {};

AsphericalLensTwoSurfaces::~AsphericalLensTwoSurfaces() {};

//https://www.edmundoptics.de/f/precision-aspheric-lenses/13139/
void AsphericalLensTwoSurfaces::buildAsphericalLensTwoSurfaces(
	/*diameter*/ real diameter,	/*max tolerance diameter*/ real  maxDiamterTolerance, /*min tolerance diameter*/ real  minDiamterTolerance, 
	/*numerical Aperture*/ real  numericalAperture,	/*design wavelength*/ real  designWavelength, /*tolerance center thickness*/ real  toleraceCenterThickness, 
	/*material*/ MaterialSellmeier1  material, /*Aspherical shape defect (µm RMS)*/ real  asphericalShapeDefects, /*edge thickness*/ real  edgeThickness, 	
	/*aperture*/ real  aperture, /*min wavelength range*/ real  minWavelength,	/*max wavelength range*/ real  maxWavelength, /*focal length*/ real  focalLength,	
	/*back focal length*/ real  backFocalLength, /*center thickness*/ real  thickness, /*Coating*/ std::string  coating, /*free Aperture*/ real  freeAperture, 
	/*max surface quality*/ real  maxSurfaceQuality, /*min surface quality*/ real  minSurfaceQuality, /*Centering (arc minutes)*/ real  centering,
	/*radius first surface*/ real  radiusFirstSurface, /*conic*/ real  conic, /*2nd term*/ real  second, /*4nd term*/ real  fourth, /*6nd term*/ real  sixth,
	/*8nd term*/ real  eighth, /*10nd term*/ real  tenth, /*12nd term*/ real  twelfth, /*14nd term*/ real  fourteenth, /*16nd term*/ real  sixteenth,
	/*radius second surface*/ real  radiusSecondSurface) 
{

}
	


