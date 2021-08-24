#include "testLensCatalog_Qioptiq.h"
// Quioptiq lens catalog
#include "..\..\LensCatalog\Qioptiq\QioptiqLensCatalog.h"
// test lens catalog
#include "testLensCatalogNameSpace.h"


testLensCata_Qioptiq::testLensCata_Qioptiq() {}

testLensCata_Qioptiq::~testLensCata_Qioptiq() {}

bool testLensCata_Qioptiq::testLensCata_PlanoConvex_lenses_unmounted_ARB2_VIS()
{
	std::vector<bool> workTheSystem;
	real wavelength = 550.0;
	real tolerance = 0.05;

	// https://www.qioptiq-shop.com/en/Precision-Optics/Singlets/Plano-Convex-Lenses/Plano-convex-lenses-unmounted.html
	QioptiqLensCatalog qioptiqLensCata;
	qioptiqLensCata.loadLensCatalogQioptiq_PlanoConvex_lenses_unmounted_ARB2_VIS();

	// G312003000
	OpticalSystemElement G312003000 = qioptiqLensCata.getQ_G312003000().getHLT_TwoSurfaces();
	bool checkG312003000 = testLensCata::testOneLensTwoSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*lens*/ G312003000, /*position image plan*/{ 0.0,0.0,15.0 }, /*rms*/ 3901.55, /*tolerance*/ tolerance);
	workTheSystem.push_back(checkG312003000);


	bool checker = Math::checkTrueOfVectorElements(workTheSystem);
	return checker;

}


bool testLensCata_Qioptiq::testLensCata_Symmetric_convex_lenses_unmounted_ARB2_VIS()
{
	std::vector<bool> workTheSystem;
	real wavelength = 550.0;
	real tolerance = 0.05;

	// https://www.qioptiq-shop.com/en/Precision-Optics/Singlets/Symmetric-Convex-Lenses/Symmetric-convex-lenses-unmounted.html
	QioptiqLensCatalog qioptiqLensCata;
	qioptiqLensCata.loadLensCatalogQioptiq_Symmetric_convex_lenses_unmounted_ARB2_VIS();

	// G311328000
	OpticalSystemElement G311328000 = qioptiqLensCata.getQ_G311328000().getHLT_TwoSurfaces();
	bool checkG311328000 = testLensCata::testOneLensTwoSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*lens*/ G311328000, /*position image plan*/{ 0.0,0.0,15.0 }, /*rms*/ 1170.12, /*tolerance*/ tolerance);
	workTheSystem.push_back(checkG311328000);


	bool checker = Math::checkTrueOfVectorElements(workTheSystem);
	return checker;
}


bool testLensCata_Qioptiq::testLensCata_Plano_concave_lenses_unmounted_N_BK7_ARB2_VIS()
{
	std::vector<bool> workTheSystem;
	real wavelength = 550.0;
	real tolerance = 0.05;

	// https://www.qioptiq-shop.com/en/Precision-Optics/Singlets/Plano-Concave-Lenses/Plano-concave-lenses-unmounted-N-BK7.html#popup_G314001000
	QioptiqLensCatalog qioptiqLensCata;
	qioptiqLensCata.loadLensCatalogQioptiq_Plano_concave_lenses_unmounted_N_BK7_ARB2_VIS();

	// G314001000
	OpticalSystemElement G314001000 = qioptiqLensCata.getQ_G313210000().getHLT_TwoSurfaces();
	bool checkG314001000 = testLensCata::testOneLensTwoSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*lens*/ G314001000, /*position image plan*/{ 0.0,0.0,15.0 }, /*rms*/ 2600.50, /*tolerance*/ tolerance);
	workTheSystem.push_back(checkG314001000);


	bool checker = Math::checkTrueOfVectorElements(workTheSystem);
	return checker;
}


bool testLensCata_Qioptiq::testLensCata_Symmetric_concave_lenses_unmounted_N_BK7_ARB2_VIS()
{
	std::vector<bool> workTheSystem;
	real wavelength = 550.0;
	real tolerance = 0.05;

	// https://www.qioptiq-shop.com/en/Precision-Optics/Singlets/Symmetric-Concave-Lenses/Symmetric-concave-lenses-unmounted-N-BK7.html#popup_G313210000
	QioptiqLensCatalog qioptiqLensCata;
	qioptiqLensCata.loadLensCatalogQioptiq_Symmetric_concave_lenses_unmounted_N_BK7_ARB2_VIS();

	// G313210000
	OpticalSystemElement G313210000 = qioptiqLensCata.getQ_G313210000().getHLT_TwoSurfaces();
	bool checkG31321000 = testLensCata::testOneLensTwoSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*lens*/ G313210000, /*position image plan*/{ 0.0,0.0,15.0 }, /*rms*/ 1771.68, /*tolerance*/ tolerance);
	workTheSystem.push_back(checkG31321000);


	bool checker = Math::checkTrueOfVectorElements(workTheSystem);
	return checker;
}


bool testLensCata_Qioptiq::testLensCata_Achromats_VIS_Positive_dia_3_mm_to_31_5_mm_unmounted_N_BK7_ARB2_VIS()
{
	std::vector<bool> workTheSystem;
	real wavelength = 550.0;
	real tolerance = 0.05;

	// https://www.qioptiq-shop.com/en/Precision-Optics/LINOS-Achromats-Lens-Systems/Achromats-positive/Achromats-VIS-Positive-dia-3-mm-to-31-5-mm-unmounted.html#popup_G322218000
	QioptiqLensCatalog qioptiqLensCata;
	qioptiqLensCata.loadLensCatalogQioptiq_Achromats_VIS_Positive_dia_3_mm_to_31_5_mm_unmounted_N_BK7_ARB2_VIS();

	// G322218000
	OpticalSystemElement G322218000 = qioptiqLensCata.getQ_G322218000().getHLT_ThreeSurfaces();
	bool checkG322218000 = testLensCata::testOneLensThreeSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*lens*/ G322218000, /*position image plan*/{ 0.0,0.0,15.0 }, /*rms*/ 1721.08, /*tolerance*/ tolerance);
	workTheSystem.push_back(checkG322218000);

	bool checker = Math::checkTrueOfVectorElements(workTheSystem);
	return checker;
}


bool testLensCata_Qioptiq::testLensCata_Achromats_VIS_Positive_from_40_mm_diameter_unmounted_N_BK7_ARB2_VIS()
{
	std::vector<bool> workTheSystem;
	real wavelength = 550.0;
	real tolerance = 0.05;

	// https://www.qioptiq-shop.com/en/Precision-Optics/LINOS-Achromats-Lens-Systems/Achromats-positive/Achromats-VIS-Positive-from-40-mm-diameter-unmounted.html#popup_G322389000
	QioptiqLensCatalog qioptiqLensCata;
	qioptiqLensCata.loadLensCatalogQioptiq_Achromats_VIS_Positive_from_40_mm_diameter_unmounted_N_BK7_ARB2_VIS();

	// G322389000
	OpticalSystemElement G322389000 = qioptiqLensCata.getQ_G322389000().getHLT_ThreeSurfaces();
	bool checkG322389000 = testLensCata::testOneLensThreeSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*lens*/ G322389000, /*position image plan*/{ 0.0,0.0,50.0 }, /*rms*/ 397.675, /*tolerance*/ tolerance);
	workTheSystem.push_back(checkG322389000);

	bool checker = Math::checkTrueOfVectorElements(workTheSystem);
	return checker;
}


bool testLensCata_Qioptiq::testLensCata_Achromats_Negative_Unmounted_ARB2_VIS()
{
	std::vector<bool> workTheSystem;
	real wavelength = 550.0;
	real tolerance = 0.05;

	// https://www.qioptiq-shop.com/en/Precision-Optics/LINOS-Achromats-Lens-Systems/Achromats-negative/Achromats-Negative-Unmounted.html

	QioptiqLensCatalog qioptiqLensCata;
	qioptiqLensCata.loadLensCatalogQioptiq_Achromats_Negative_Unmounted_ARB2_VIS();

	// G063191000 --> ATTENTION --> there was no Zemax file online
	//OpticalSystemElement G063191000 = qioptiqLensCata.getQ_G325221000().getHLT_ThreeSurfaces();
	//bool checkG322389000 = testLensCata::testOneLensThreeSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*lens*/ G063191000, /*position image plan*/{ 0.0,0.0,50.0 }, /*rms*/ , /*tolerance*/ tolerance);
	//workTheSystem.push_back(checkG322389000);

	bool checker = Math::checkTrueOfVectorElements(workTheSystem);
	return checker;

}