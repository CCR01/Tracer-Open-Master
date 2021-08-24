#pragma once
#include "..\..\OpticalSystemElement\OpticalSystemElement.h"

namespace testLensCata
{
	// obj
	bool testOneLensThreeSurfaces_start0(real wavelength, OpticalSystemElement optSys_HLT, VectorStructR3 positionImageSurface, real rms, real tolerance);
	bool testOneLensFourSurfaces_start0(real wavelength, OpticalSystemElement optSys_HLT, VectorStructR3 positionImageSurface, real rms, real tolerance);


	// inf
	bool testOneLensTwoSurfaces_startInf_0deg(real wavelength, OpticalSystemElement optSys_HLT, VectorStructR3 positionImageSurface, real rms, real tolerance);
	bool testOneLensThreeSurfaces_startInf_0deg(real wavelength, OpticalSystemElement optSys_HLT, VectorStructR3 positionImageSurface, real rms, real tolerance);
	bool testOneLensFourSurfaces_startInf_0deg(real wavelength, OpticalSystemElement optSys_HLT, VectorStructR3 positionImageSurface, real rms, real tolerance);

	bool testOneLensTwoSurfaces_startInf_0deg(/*size aperture stop*/ real sizeAperStop, real wavelength, OpticalSystemElement optSys_HLT, VectorStructR3 positionImageSurface, real rms, real tolerance);
}