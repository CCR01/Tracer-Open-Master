#include "BenchSphericalElement.h"

#include "..\..\..\SurfaceElements\SphericalElement.h"

bool BenchSphericalElement::checkMethodesSphericalElement()
{
	SphericalElement SphereE(10.0, 5.0, { 0.0,0.0,5.0 }, { 0.0,0.0,1.0 }, 1.0, 1.5);
	SphereE.setParameterRadius(4.0, 6.0, 0.0, typeModifierFixed);

	return true;
}