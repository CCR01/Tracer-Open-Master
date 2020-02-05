#pragma once
//#include "..\..\basicdefinitions.h"
//#include "..\..\basicdefinitions.h"

class MaterialSellmeier1 {
	public:
		MaterialSellmeier1();
		MaterialSellmeier1(double const& k1, double const& l1, double const& k2, double const& l2, double const& k3, double const& l3);
		~MaterialSellmeier1();
	

	
	 // set the parameter
	 void setParameterAndCalcVd_Ve(double const& k1, double const& l1, double const& k2, double const& l2, double const& k3, double const& l3);

	// calculate the refractive index with the snellmeier 1 fomula
	double calcRefractiveIndexSnellmeier1(double wavelength);

	// calculate Vd
	double calcVd();
	// calculate Ve
	double calcVe();
	
	// get Abbe numner old and new definition
	double getAbbeNumberOldDef();
	double getAbbeNumerNewDef();

	void setRealGlass(bool realGlass);
	void setRefractiveIndex(double refractiveIndex);


	/*
	//Fraunhofer lines
	//587,5618 nm
	double nd = calcRefractiveIndexSnellmeier1(0.5875618);
	//546,0740 nm
	double  ne = calcRefractiveIndexSnellmeier1(0.5460740);
	//486,1327 nm
	double nF = calcRefractiveIndexSnellmeier1(0.4861327);
	//656,2725 nm
	double nC = calcRefractiveIndexSnellmeier1(0.6562725);
	// 479,9914 nm
	double nFstripe = calcRefractiveIndexSnellmeier1(0.4799914);
	// 643,8469 nm
	double nCstripe = calcRefractiveIndexSnellmeier1(0.6438469);
	*/

private:
	double mK1;
	double mK2;
	double mK3;
	double mL1;
	double mL2;
	double mL3;

	// Abbe number (old definition)
	double mVd;

	// Abbe number (new definition)
	double mVe;

	bool mRealGlass;
	double mRefractiveIndes;
};