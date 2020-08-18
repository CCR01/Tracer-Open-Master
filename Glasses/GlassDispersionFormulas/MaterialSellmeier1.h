#pragma once
//#include "..\..\basicdefinitions.h"
//#include "..\..\basicdefinitions.h"
#include <string>

class MaterialSellmeier1 {
public:
	MaterialSellmeier1();
	//MaterialSellmeier1(double const& k1, double const& l1, double const& k2, double const& l2, double const& k3, double const& l3);
	MaterialSellmeier1(std::string catalog, std::string name, double k1, double l1, double k2, double l2, double k3, double l3,
		double th1, double th2, double th3, double th4, double th5, double th6, double wl0, double wl1,
		double climate, double acid, double alkali, double stain);
	~MaterialSellmeier1();



	// set the parameter
	void setParameterAndCalcVd_Ve(std::string catalog, std::string name, double k1, double l1, double k2,
		double l2, double k3, double l3, double th1, double th2, double th3, double th4, double th5, double th6, double wl0, double wl1,
		double climate, double acid, double alkali, double stain);

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
	bool getRealGlass();
	void setRefractiveIndex(double refractiveIndex);
	double getRefractivIndex();
	void setNameGlas(std::string nameGlas);
	std::string getNameGlas();
	

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
	std::string mCatalog{};
	std::string mName{};

	double mK1{};
	double mK2{};
	double mK3{};
	double mL1{};
	double mL2{};
	double mL3{};

	double mTh1{};
	double mTh2{};
	double mTh3{};
	double mTh4{};
	double mTh5{};
	double mTh6{};
	double mWl0{};
	double mWl1{};
	double mClimate{};
	double mAcid{};
	double mAlkali{};
	double mStain{};

	// Abbe number (old definition)
	double mVd{};

	// Abbe number (new definition)
	double mVe{};

	bool mRealGlass{};
	double mRefractiveIndes{};
};