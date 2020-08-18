#include "MaterialSellmeier1.h"
#include <cmath>

MaterialSellmeier1::MaterialSellmeier1() {};
MaterialSellmeier1::~MaterialSellmeier1() {};

MaterialSellmeier1::MaterialSellmeier1(std::string catalog, std::string name, double k1, double l1, double k2,
	double l2, double k3, double l3, double th1, double th2, double th3, double th4, double th5, double th6, double wl0, double wl1,
	double climate, double acid, double alkali, double stain) :
	mCatalog(catalog),
	mName(name),
	mK1(k1),
	mL1(l1),
	mK2(k2),
	mL2(l2),
	mK3(k3),
	mL3(l3),
	mTh1(th1),
	mTh2(th2),
	mTh3(th3),
	mTh4(th4),
	mTh5(th5),
	mTh6(th6),
	mWl0(wl0),
	mWl1(wl1),
	mClimate(climate),
	mAcid(acid),
	mAlkali(alkali),
	mStain(stain)
{
	// Abbe number (old definition)
	mVd = calcVd();
	// Abbe number (new definition)
	mVe = calcVe();

	mRealGlass = true;
};

// set the parameter
void MaterialSellmeier1::setParameterAndCalcVd_Ve(std::string catalog, std::string name, double k1, double l1, double k2,
	double l2, double k3, double l3, double th1, double th2, double th3, double th4, double th5, double th6, double wl0, double wl1,
	double climate, double acid, double alkali, double stain)
{
	mCatalog = catalog;
	mName = name;
	mK1 = k1;
	mL1 = l1;
	mK2 = k2;
	mL2 = l2;
	mK3 = k3;
	mL3 = l3;
	mTh1 = th1;
	mTh2 = th2;
	mTh3 = th3;
	mTh4 = th4;
	mTh5 = th5;
	mTh6 = th6;
	mWl0 = wl0;
	mWl1 = wl1;
	mClimate = climate;
	mAcid = acid;
	mAlkali = alkali;
	mStain = stain;

	mVd = calcVd();
	mVe = calcVe();

	mRealGlass = true;
}

// calculate the refractive index with the snellmeier 1 fomula
double MaterialSellmeier1::calcRefractiveIndexSnellmeier1(double wavelength)
{
	double RefractiveIndex;

	if (mRealGlass)
	{
		double wavelengthInMicrometer = wavelength / 1000;
		double powWavelength2_Micrometer = pow(wavelengthInMicrometer, 2);
		RefractiveIndex = std::sqrt(1 + ((mK1*powWavelength2_Micrometer / (powWavelength2_Micrometer - mL1)) + (mK2*powWavelength2_Micrometer) / (powWavelength2_Micrometer - mL2) + (mK3*powWavelength2_Micrometer) / (powWavelength2_Micrometer - mL3)));
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
bool MaterialSellmeier1::getRealGlass()
{
	return mRealGlass;
}

void MaterialSellmeier1::setRefractiveIndex(double refractiveIndex)
{
	mRefractiveIndes = refractiveIndex;
}
double MaterialSellmeier1::getRefractivIndex()
{
	return mRefractiveIndes;
}
void MaterialSellmeier1::setNameGlas(std::string nameGlas)
{
	mName = nameGlas;
}
std::string MaterialSellmeier1::getNameGlas()
{
	return mName;
}