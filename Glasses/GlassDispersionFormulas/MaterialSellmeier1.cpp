#include "MaterialSellmeier1.h"
#include <cmath>

MaterialSellmeier1::MaterialSellmeier1() {};
MaterialSellmeier1::~MaterialSellmeier1() {};

MaterialSellmeier1::MaterialSellmeier1(double const& k1, double const& l1, double const& k2, double const& l2, double const& k3, double const& l3) :
	mK1(k1),
	mL1(l1),
	mK2(k2),
	mL2(l2),
	mK3(k3),
	mL3(l3)
{
	// Abbe number (old definition)
	mVd = calcVd();
	// Abbe number (new definition)
	mVe = calcVe();

	mRealGlass = true;
};

// set the parameter
void MaterialSellmeier1::setParameterAndCalcVd_Ve(double const& k1, double const& l1, double const& k2, double const& l2, double const& k3, double const& l3)
{
	mK1 = k1;
	mK2 = k2;
	mK3 = k3;
	mL1 = l1;
	mL2 = l2;
	mL3 = l3;

	mVd = calcVd();
	mVe = calcVe();

	mRealGlass = true;
}

// calculate the refractive index with the snellmeier 1 fomula
double MaterialSellmeier1::calcRefractiveIndexSnellmeier1(double wavelength)
{	
	double RefractiveIndex;

	if(mRealGlass)
	{
	double wavelengthInMicrometer = wavelength / 1000;
	double powWavelength2_Micrometer = pow(wavelengthInMicrometer, 2);
	RefractiveIndex = std::sqrt(1+((mK1*powWavelength2_Micrometer / (powWavelength2_Micrometer-mL1)) + (mK2*powWavelength2_Micrometer)/(powWavelength2_Micrometer-mL2)+(mK3*powWavelength2_Micrometer)/ (powWavelength2_Micrometer-mL3)));
	}
	else
	{
		RefractiveIndex = mRefractiveIndes;
	}

	return RefractiveIndex;
}

double MaterialSellmeier1::getAbbeNumberOldDef()
{
	return mVd;
}

double MaterialSellmeier1::getAbbeNumerNewDef()
{
	return mVe;
}

// calculate Vd
double MaterialSellmeier1::calcVd()
{
	return (calcRefractiveIndexSnellmeier1(587.5618) - 1) / (calcRefractiveIndexSnellmeier1(486.1327) - calcRefractiveIndexSnellmeier1(656.2725));
}

// calculate Ve
double MaterialSellmeier1::calcVe()
{
	return (calcRefractiveIndexSnellmeier1(546.0740) - 1) / (calcRefractiveIndexSnellmeier1(479.9914) - calcRefractiveIndexSnellmeier1(643.8469));
}

void MaterialSellmeier1::setRealGlass(bool realGlass)
{
	mRealGlass = realGlass;
}

void MaterialSellmeier1::setRefractiveIndex(double refractiveIndex)
{
	mRefractiveIndes = refractiveIndex;
}