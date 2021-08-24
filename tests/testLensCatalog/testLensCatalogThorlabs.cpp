#include "testLensCatalogThorlabs.h"
// thorlabs lens catalog
#include "..\..\LensCatalog\Thorlabs\ThorllabsLensCatalog.h"
// test lens catalog
#include "testLensCatalogNameSpace.h"

testLensCatalogThorlabs::testLensCatalogThorlabs() {}
testLensCatalogThorlabs::~testLensCatalogThorlabs() {}

// https://www.thorlabs.com/newgrouppage9.cfm?objectgroup_id=12767
bool testLensCatalogThorlabs::testLensCataThorlabs_Unmounted_Achromatic_Doublets_AR_Coated()
{
	std::vector<bool> workTheSystem;

	real wavelength = 550.0;
	real tolerance = 0.05;

	ThorlabsLensCatalog thorLensCata;
	thorLensCata.loadLensCatalogThorlabs_Achromativ_Doublets_AR_Coated_lenses();

	// AC127-019-AB
	OpticalSystemElement AC127019AB = thorLensCata.getT_AC127019AB().getHLT_ThreeSurfaces();
	bool checkAC127019AB = testLensCata::testOneLensThreeSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*achromat*/ AC127019AB, /*position image plan*/{ 0.0,0.0,15.0 }, /*rms*/ 291.575, /*tolerance*/ tolerance);
	workTheSystem.push_back(checkAC127019AB);

	// AC127-025-AB
	OpticalSystemElement AC127025AB = thorLensCata.getT_AC127025AB().getHLT_ThreeSurfaces();
	bool checkAC127025AB = testLensCata::testOneLensThreeSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*achromat*/ AC127025AB, /*position image plan*/{ 0.0,0.0,15.0 }, /*rms*/ 423.662, /*tolerance*/ tolerance);
	workTheSystem.push_back(checkAC127025AB);


	bool checker = Math::checkTrueOfVectorElements(workTheSystem);
	return checker;
}

// https://www.thorlabs.de/newgrouppage9.cfm?objectgroup_id=13685
bool testLensCatalogThorlabs::testLensCataThorlas_N_BK7_Plano_Convex_Lenses_AR_Coating_400_1100_nm()
{
	std::vector<bool> workTheSystem;

	real wavelength = 550.0;
	real tolerance = 0.05;

	ThorlabsLensCatalog thorLensCata;
	thorLensCata.loadLensCatalogThorlabs_N_BK7_Plano_Convex_Lenses_AR_Coating_400_1100_nm();

	// LA1540-AB
	OpticalSystemElement LA1540AB = thorLensCata.getT_LA1540AB().getHLT_TwoSurfaces();
	bool checkLA1540AB = testLensCata::testOneLensTwoSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*achromat*/ LA1540AB, /*position image plan*/{ 0.0,0.0,15.0 }, /*rms*/ 132.812, /*tolerance*/ tolerance);
	workTheSystem.push_back(checkLA1540AB);



	bool checker = Math::checkTrueOfVectorElements(workTheSystem);
	return checker;
}

// https://www.thorlabs.de/newgrouppage9.cfm?objectgroup_id=4848
bool testLensCatalogThorlabs::testLensCataTorlabs_N_BK7_Bi_Convex_Lenses_AR_Coating_350_700_nm()
{
	std::vector<bool> workTheSystem;

	real wavelength = 550.0;
	real tolerance = 0.05;

	ThorlabsLensCatalog thorLensCata;
	thorLensCata.loadLensCatalogThorlabs_N_BK7_Bi_Convex_Lenses_AR_Coating_350_700_nm();

	// LB1157-A
	OpticalSystemElement LB1157A = thorLensCata.getT_LB1157A().getHLT_TwoSurfaces();
	bool checkLB1157A = testLensCata::testOneLensTwoSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*achromat*/ LB1157A, /*position image plan*/{ 0.0,0.0,15.0 }, /*rms*/ 199.931, /*tolerance*/ tolerance);
	workTheSystem.push_back(checkLB1157A);



	bool checker = Math::checkTrueOfVectorElements(workTheSystem);
	return checker;
}

// https://www.thorlabs.de/newgrouppage9.cfm?objectgroup_id=6509
bool testLensCatalogThorlabs::testLensCataTorlabs_N_BK7_Plano_Concave_Lenses_AR_Coating_350_700_nm()
{
	std::vector<bool> workTheSystem;

	real wavelength = 550.0;
	real tolerance = 0.05;

	ThorlabsLensCatalog thorLensCata;
	thorLensCata.loadLensCatalogThorlabs_N_BK7_Plano_Concave_Lenses_AR_Coating_350_700_nm();

	// LC1975-A
	OpticalSystemElement LC1975A = thorLensCata.getT_LC1975A().getHLT_TwoSurfaces();
	bool checkLC1975A = testLensCata::testOneLensTwoSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*achromat*/ LC1975A, /*position image plan*/{ 0.0,0.0,15.0 }, /*rms*/ 1187.74, /*tolerance*/ tolerance);
	workTheSystem.push_back(checkLC1975A);



	bool checker = Math::checkTrueOfVectorElements(workTheSystem);
	return checker;
}


// https://www.thorlabs.de/newgrouppage9.cfm?objectgroup_id=9733
bool testLensCatalogThorlabs::testLensCataTorlabs_N_BK7_and_N_SF11_BiSConcave_Lenses_AR_Coating_350_700_nm()
{
	std::vector<bool> workTheSystem;

	real wavelength = 550.0;
	real tolerance = 0.05;

	ThorlabsLensCatalog thorLensCata;
	thorLensCata.loadLensCatalogThorlabs_N_BK7_and_N_SF11_Bi_Concave_Lenses_AR_Coating_350_700_nm();

	// LD2746-A
	OpticalSystemElement LD2746A = thorLensCata.getT_LD2746A().getHLT_TwoSurfaces();
	bool checkLD2746A = testLensCata::testOneLensTwoSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*achromat*/ LD2746A, /*position image plan*/{ 0.0,0.0,15.0 }, /*rms*/ 2459.56, /*tolerance*/ tolerance);
	workTheSystem.push_back(checkLD2746A);



	bool checker = Math::checkTrueOfVectorElements(workTheSystem);
	return checker;
}

// https://www.thorlabs.de/newgrouppage9.cfm?objectgroup_id=4874
bool testLensCatalogThorlabs::testLensCataTorlabs_1Zoll_N_BK7_Best_Form_Spherical_Lenses_AR_Coating_350_700_nm()
{
	std::vector<bool> workTheSystem;

	real wavelength = 550.0;
	real tolerance = 0.05;

	ThorlabsLensCatalog thorLensCata;
	thorLensCata.loadLensCatalogThorlabs_1Zoll_N_BK7_Best_Form_Spherical_Lenses_AR_Coating_350_700_nm();

	// LBF254-040-A
	OpticalSystemElement LBF254040A = thorLensCata.getT_LBF254040A().getHLT_TwoSurfaces();
	bool checkLBF254040A = testLensCata::testOneLensTwoSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*achromat*/ LBF254040A, /*position image plan*/{ 0.0,0.0,15.0 }, /*rms*/ 547.356, /*tolerance*/ tolerance);
	workTheSystem.push_back(checkLBF254040A);



	bool checker = Math::checkTrueOfVectorElements(workTheSystem);
	return checker;
}

// https://www.thorlabs.de/newgrouppage9.cfm?objectgroup_id=130
bool testLensCatalogThorlabs::testLensCataTorlabs_N_BK7_Positive_Meniscus_Lenses_Uncoated()
{
	std::vector<bool> workTheSystem;

	real wavelength = 550.0;
	real tolerance = 0.05;

	ThorlabsLensCatalog thorLensCata;
	thorLensCata.loadLensCatalogThorlabs_N_BK7_Positive_Meniscus_Lenses_Uncoated();

	// LE1234
	OpticalSystemElement LE1234 = thorLensCata.getT_LE1234().getHLT_TwoSurfaces();
	bool checkLE1234 = testLensCata::testOneLensTwoSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*achromat*/ LE1234, /*position image plan*/{ 0.0,0.0,15.0 }, /*rms*/ 652.057, /*tolerance*/ tolerance);
	workTheSystem.push_back(checkLE1234);


	bool checker = Math::checkTrueOfVectorElements(workTheSystem);
	return checker;

}

// https://www.thorlabs.de/newgrouppage9.cfm?objectgroup_id=902
bool testLensCatalogThorlabs::testLensCataTorlabs_N_BK7_Negative_Meniscus_Lenses_Uncoated()
{
	std::vector<bool> workTheSystem;

	real wavelength = 550.0;
	real tolerance = 0.05;

	ThorlabsLensCatalog thorLensCata;
	thorLensCata.loadLensCatalogThorlabs_1Zoll_N_BK7_Negative_Meniscus_Lenses_Uncoated();

	// LF1822
	OpticalSystemElement LF1822 = thorLensCata.getT_LF1822().getHLT_TwoSurfaces();
	bool checkLF1822 = testLensCata::testOneLensTwoSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*achromat*/ LF1822, /*position image plan*/{ 0.0,0.0,15.0 }, /*rms*/ 837.137, /*tolerance*/ tolerance);
	workTheSystem.push_back(checkLF1822);


	bool checker = Math::checkTrueOfVectorElements(workTheSystem);
	return checker;

}

// https://www.thorlabs.de/newgrouppage9.cfm?objectgroup_id=5370
bool testLensCatalogThorlabs::testLensCataTorlabs_Steinheil_Triplet_Achromatic_Lenses_Visible()
{
	std::vector<bool> workTheSystem;

	real wavelength = 550.0;
	real tolerance = 0.05;

	ThorlabsLensCatalog thorLensCata;
	thorLensCata.loadLensCatalogThorlabs_Steinheil_Triplet_Achromatic_Lenses_Visible();

	// TRS064-010-A
	OpticalSystemElement TRS064010A = thorLensCata.getT_TRS064010A().getHLT_FourSurfaces();
	bool checkTRS064010A = testLensCata::testOneLensFourSurfaces_start0(/*wavelength*/ wavelength, /*achromat*/ TRS064010A, /*position image plan*/{ 0.0,0.0,30.0 }, /*rms*/ 673.121, /*tolerance*/ tolerance);
	workTheSystem.push_back(checkTRS064010A);


	bool checker = Math::checkTrueOfVectorElements(workTheSystem);
	return checker;

}

// https://www.thorlabs.de/newgrouppage9.cfm?objectgroup_id=5368
bool testLensCatalogThorlabs::testLensCataTorlabs_Hastings_Triplet_Achromatic_Lenses_Visible()
{
	std::vector<bool> workTheSystem;

	real wavelength = 550.0;
	real tolerance = 0.05;

	ThorlabsLensCatalog thorLensCata;
	thorLensCata.loadLensCatalogThorlabs_Hastings_Triplet_Achromatic_Lenses_Visible();

	// TRH064010A
	OpticalSystemElement TRH064010A = thorLensCata.getT_TRH064010A().getHLT_FourSurfaces();
	bool checkTRH064010A2 = testLensCata::testOneLensFourSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*achromat*/ TRH064010A, /*position image plan*/{ 0.0,0.0,15.0 }, /*rms*/ 18.439, /*tolerance*/ tolerance);
	workTheSystem.push_back(checkTRH064010A2);


	bool checker = Math::checkTrueOfVectorElements(workTheSystem);
	return checker;
}

