#include "QioptiqLensCatalog.h"
// glasses
#include "..\..\Glasses\Glasses.h"

QioptiqLensCatalog::QioptiqLensCatalog() {}

QioptiqLensCatalog::~QioptiqLensCatalog() {}

// *** Plano-convex lenses, unmounted, ARB2 VIS
void QioptiqLensCatalog::loadLensCatalogQioptiq_PlanoConvex_lenses_unmounted_ARB2_VIS()
{
	glass glasses;
	glasses.loadGlassCatalog_Schott();

	// https://www.qioptiq-shop.com/en/Precision-Optics/Singlets/Plano-Convex-Lenses/Plano-convex-lenses-unmounted.html

	mQ_G312003000.buildLensTwoSurfaces_Qioptiq_oneSurfacePlan(/*lens catalog*/ "Qioptiq", /*catalog number*/ "G312003322", /*diameter*/ 3.0,
		/*focallength*/ 2.5, /*tolerance focal length*/ 2.0,	/*material*/ glasses.getNLASF9_S1(), /*optical centering accurancy*/6.0,
		/*surface quality*/ "3x0.063", /*thickness*/ 1.0, /*tolerance center thickness*/ 0.02, /*edge thickness*/ 0.38, /*min diameter tolerance*/ -0.02,
		/*back focal length*/ 1.96, /*radius*/ 2.126, /*price*/ 43.0, /*coating*/ "ARB2-VIS", /*min wavelength*/ 450.0, /*max wavelength*/ 700.0);
			



}
std::vector<LensesTwoSurfaces> QioptiqLensCatalog::getAll_Qioptiq_PlanoConvex_lenses_unmounted_ARB2_VIS()
{
	// https://www.qioptiq-shop.com/en/Precision-Optics/Singlets/Plano-Convex-Lenses/Plano-convex-lenses-unmounted.html

	std::vector<LensesTwoSurfaces> return_Qioptiq_PlanoConvex_lenses_unmounted_ARB2_VIS;
	return_Qioptiq_PlanoConvex_lenses_unmounted_ARB2_VIS.push_back(mQ_G312003000);

	return return_Qioptiq_PlanoConvex_lenses_unmounted_ARB2_VIS;
}

// *** Symmetric - convex lenses, unmounted, ARB2 VIS
void QioptiqLensCatalog::loadLensCatalogQioptiq_Symmetric_convex_lenses_unmounted_ARB2_VIS()
{
	glass glasses;
	glasses.loadGlassCatalog_Schott();

	// https://www.qioptiq-shop.com/en/Precision-Optics/Singlets/Symmetric-Convex-Lenses/Symmetric-convex-lenses-unmounted.html

	mQ_G311328000.buildLensTwoSurfaces_Qioptiq_lenses(/*lens catalog*/ "Qioptiq", /*catalog number*/ "G311328000", /*diameter*/ 6.0,
		/*focallength*/ 5.0, /*tolerance focal length*/ 2.0, /*material*/ glasses.getNBAK4_S1(), /*optical centering accurancy*/10.0,
		/*surface quality*/ "3x0.1", /*thickness*/ 2.9, /*tolerance center thickness*/ 0.1, /*edge thickness*/ 0.9, /*min diameter tolerance*/ -0.075,
		/*back focal length*/ 3.95, /*radius first surface*/ 5.085, /*radius second surface*/ -5.085, /*price*/ 49.0, /*coating*/ "ARB2-VIS", 
		/*min wavelength*/ 450.0, /*max wavelength*/ 700.0);

}

std::vector<LensesTwoSurfaces> QioptiqLensCatalog::getAll_Symmetric_convex_lenses_unmounted_ARB2_VIS()
{
	// https://www.qioptiq-shop.com/en/Precision-Optics/Singlets/Symmetric-Convex-Lenses/Symmetric-convex-lenses-unmounted.html

	std::vector<LensesTwoSurfaces> return_Qioptiq_Symmetric_convex_lenses_unmounted_ARB2_VIS;
	return_Qioptiq_Symmetric_convex_lenses_unmounted_ARB2_VIS.push_back(mQ_G311328000);



	return return_Qioptiq_Symmetric_convex_lenses_unmounted_ARB2_VIS;
}
// ***

// *** Plano - concave lenses, unmounted (N - BK7), ARB2 VIS
void QioptiqLensCatalog::loadLensCatalogQioptiq_Plano_concave_lenses_unmounted_N_BK7_ARB2_VIS()
{
	glass glasses;
	glasses.loadGlassCatalog_Schott();

	// https://www.qioptiq-shop.com/en/Precision-Optics/Singlets/Plano-Concave-Lenses/Plano-concave-lenses-unmounted-N-BK7.html

	mQ_G313210000.buildLensTwoSurfaces_Qioptiq_oneSurfacePlan(/*lens catalog*/ "Qioptiq", /*catalog number*/ "G314001000", /*diameter*/ 6.0,
		/*focallength*/ -6.0, /*tolerance focal length*/ 2.0,	/*material*/ glasses.getNBK7_S1(), /*optical centering accurancy*/10.0,
		/*surface quality*/ "3x0.1", /*thickness*/ 0.5, /*tolerance center thickness*/ 0.02, /*edge thickness*/ 2.82, /*min diameter tolerance*/ -0.02,
		/*back focal length*/ -6.33, /*radius*/ -3.101, /*price*/ 56.0, /*coating*/ "ARB2-VIS", /*min wavelength*/ 450.0, /*max wavelength*/ 700.0);
}

std::vector<LensesTwoSurfaces> QioptiqLensCatalog::getAll_Plano_concave_lenses_unmounted_N_BK7_ARB2_VIS()
{
	// https://www.qioptiq-shop.com/en/Precision-Optics/Singlets/Plano-Concave-Lenses/Plano-concave-lenses-unmounted-N-BK7.html

	std::vector<LensesTwoSurfaces> return_Qioptiq_Plano_concave_lenses_unmounted_N_BK7_ARB2_VIS;
	return_Qioptiq_Plano_concave_lenses_unmounted_N_BK7_ARB2_VIS.push_back(mQ_G313210000);



	return return_Qioptiq_Plano_concave_lenses_unmounted_N_BK7_ARB2_VIS;
}
// ***


// *** Symmetric - concave lenses, unmounted (N - BK7), ARB2 VIS
void QioptiqLensCatalog::loadLensCatalogQioptiq_Symmetric_concave_lenses_unmounted_N_BK7_ARB2_VIS()
{
	glass glasses;
	glasses.loadGlassCatalog_Schott();

	// https://www.qioptiq-shop.com/en/Precision-Optics/Singlets/Symmetric-Concave-Lenses/Symmetric-concave-lenses-unmounted-N-BK7.html

	mQ_G313210000.buildLensTwoSurfaces_Qioptiq_lenses(/*lens catalog*/ "Qioptiq", /*catalog number*/ "G313210000", /*diameter*/ 10.0,
		/*focallength*/ 10.0, /*tolerance focal length*/ 2.0, /*material*/ glasses.getNBK7_S1(), /*optical centering accurancy*/10.0,
		/*surface quality*/ "3x0.16", /*thickness*/ 1.0, /*tolerance center thickness*/ 0.15, /*edge thickness*/ 3.5, /*min diameter tolerance*/ -0.09,
		/*back focal length*/ -10.48, /*radius first surface*/ -10.669, /*radius second surface*/ 10.669, /*price*/ 46.0, /*coating*/ "ARB2-VIS", 
		/*min wavelength*/ 450.0, /*max wavelength*/ 700.0);


}
std::vector<LensesTwoSurfaces> QioptiqLensCatalog::getAll_Symmetric_concave_lenses_unmounted_N_BK7_ARB2_VIS()
{

	// https://www.qioptiq-shop.com/en/Precision-Optics/Singlets/Symmetric-Concave-Lenses/Symmetric-concave-lenses-unmounted-N-BK7.html

	std::vector<LensesTwoSurfaces> return_Qioptiq_Symmetric_concave_lenses_unmounted_N_BK7_ARB2_VIS;
	return_Qioptiq_Symmetric_concave_lenses_unmounted_N_BK7_ARB2_VIS.push_back(mQ_G313210000);



	return return_Qioptiq_Symmetric_concave_lenses_unmounted_N_BK7_ARB2_VIS;
}
// ***

// *** Achromats VIS, Positive, dia. 3 mm to 31.5 mm, unmounted, ARB2 VIS
void QioptiqLensCatalog::loadLensCatalogQioptiq_Achromats_VIS_Positive_dia_3_mm_to_31_5_mm_unmounted_N_BK7_ARB2_VIS()
{
	glass glasses;
	glasses.loadGlassCatalog_Schott();

	// https://www.qioptiq-shop.com/en/Precision-Optics/LINOS-Achromats-Lens-Systems/Achromats-positive/Achromats-VIS-Positive-dia-3-mm-to-31-5-mm-unmounted.html

	mQ_G322218000.buildLensThreeSurfaces_Qioptiq_lenses(/*lenscatalog*/ "Qioptiq", /*catalog number*/"G322218000", /*diameter*/ 3.0,
		/*focallength*/ 4.0, /*optical centering accurancy*/ 3.0, /*surface quality*/ "3x0.1", /*edge thickness*/ 1.8, /*back focal length*/ 2.83, 
		/*min wavelength*/450.0, /*max wavelength*/ 700.0, /*coating*/ "ARB2-VIS", /*caoting specification*/ "2xR<0.5%", 
		/*radius first surface*/ 2.75, /*radius second surface*/ -1.85, /*radius thrid surface*/ -5.848, /*thickness first*/ 1.645, 
		/*thickness second*/ 0.75, /*tolerance center thickness*/ 0.1,/*material first*/glasses.getNSSK8_S1(), /*material second*/ glasses.getNSF56_S1(), 
		/*price*/ 90.0);

}

std::vector<LensThreeSurfaces> QioptiqLensCatalog::getAll_Achromats_VIS_Positive_dia_3_mm_to_31_5_mm_unmounted_N_BK7_ARB2_VIS()
{
	// https://www.qioptiq-shop.com/en/Precision-Optics/LINOS-Achromats-Lens-Systems/Achromats-positive/Achromats-VIS-Positive-dia-3-mm-to-31-5-mm-unmounted.html

	std::vector<LensThreeSurfaces> return_Qioptiq_Achromats_VIS_Positive_dia_3_mm_to_31_5_mm_unmounted_N_BK7_ARB2_VIS;
	return_Qioptiq_Achromats_VIS_Positive_dia_3_mm_to_31_5_mm_unmounted_N_BK7_ARB2_VIS.push_back(mQ_G322218000);



	return return_Qioptiq_Achromats_VIS_Positive_dia_3_mm_to_31_5_mm_unmounted_N_BK7_ARB2_VIS;
}
// ***

// *** Achromats VIS, Positive from 40 mm diameter, unmounted, ARB2 VIS
void QioptiqLensCatalog::loadLensCatalogQioptiq_Achromats_VIS_Positive_from_40_mm_diameter_unmounted_N_BK7_ARB2_VIS()
{

	glass glasses;
	glasses.loadGlassCatalog_Schott();

	// https://www.qioptiq-shop.com/en/Precision-Optics/LINOS-Achromats-Lens-Systems/Achromats-positive/Achromats-VIS-Positive-from-40-mm-diameter-unmounted.html
	mQ_G322389000.buildLensThreeSurfaces_Qioptiq_lenses(/*lenscatalog*/ "Qioptiq", /*catalog number*/"G322389000", /*diameter*/ 40.0,
		/*focallength*/ 90.0, /*optical centering accurancy*/ 6.0, /*surface quality*/ "5x0.4", /*edge thickness*/ 9.8, /*back focal length*/ 81.78,
		/*min wavelength*/450.0, /*max wavelength*/ 700.0, /*coating*/ "ARB2-VIS", /*caoting specification*/ "2xR<0.5%",
		/*radius first surface*/ 55.835, /*radius second surface*/ -33.86, /*radius thrid surface*/ -263.22, /*thickness first*/ 12.25,
		/*thickness second*/ 2.0, /*tolerance center thickness*/ 0.2,/*material first*/glasses.getNBAK1_S1(), /*material second*/ glasses.getNF2_S1(),
		/*price*/ 131.0);

}
std::vector<LensThreeSurfaces> QioptiqLensCatalog::getAll_Achromats_VIS_Positive_from_40_mm_diameter_unmounted_N_BK7_ARB2_VIS()
{
	// https://www.qioptiq-shop.com/en/Precision-Optics/LINOS-Achromats-Lens-Systems/Achromats-positive/Achromats-VIS-Positive-from-40-mm-diameter-unmounted.html

	std::vector<LensThreeSurfaces> return_Qioptiq_Achromats_VIS_Positive_from_40_mm_diameter_unmounted_N_BK7_ARB2_VIS;
	return_Qioptiq_Achromats_VIS_Positive_from_40_mm_diameter_unmounted_N_BK7_ARB2_VIS.push_back(mQ_G322389000);



	return return_Qioptiq_Achromats_VIS_Positive_from_40_mm_diameter_unmounted_N_BK7_ARB2_VIS;
}
// ***

// *** Achromats, Negative, Unmounted, ARB2 VIS
void QioptiqLensCatalog::loadLensCatalogQioptiq_Achromats_Negative_Unmounted_ARB2_VIS()
{
	// https://www.qioptiq-shop.com/en/Precision-Optics/LINOS-Achromats-Lens-Systems/Achromats-negative/Achromats-Negative-Unmounted.html
	// there was no Zemax file online
}

std::vector<LensThreeSurfaces> QioptiqLensCatalog::getAll_Achromats_Negative_Unmounted_ARB2_VIS()
{
	// https://www.qioptiq-shop.com/en/Precision-Optics/LINOS-Achromats-Lens-Systems/Achromats-negative/Achromats-Negative-Unmounted.html

	std::vector<LensThreeSurfaces> return_Qioptiq_Achromats_Negative_Unmounted_ARB2_VIS{};
	// there was no Zemax file online

	return return_Qioptiq_Achromats_Negative_Unmounted_ARB2_VIS;
}
// ***

//  *** Plano-Convex lenses, unmounted, ARB2-VIS
// https://www.qioptiq-shop.com/en/Precision-Optics/Singlets/Plano-Convex-Lenses/Plano-convex-lenses-unmounted.html
LensesTwoSurfaces QioptiqLensCatalog::getQ_G312003000()
{
	return mQ_G312003000;
}


// *** Symmetric - convex lenses, unmounted, ARB2 VIS
// https://www.qioptiq-shop.com/en/Precision-Optics/Singlets/Symmetric-Convex-Lenses/Symmetric-convex-lenses-unmounted.html
LensesTwoSurfaces QioptiqLensCatalog::getQ_G311328000()
{
	return mQ_G311328000;
}

// *** Plano - concave lenses, unmounted (N - BK7), ARB2 VIS
// https://www.qioptiq-shop.com/en/Precision-Optics/Singlets/Plano-Concave-Lenses/Plano-concave-lenses-unmounted-N-BK7.html
LensesTwoSurfaces QioptiqLensCatalog::getQ_G314001322()
{
	return mQ_G314001322;
}

// *** Symmetric - concave lenses, unmounted (N - BK7), ARB2 VIS
// https://www.qioptiq-shop.com/en/Precision-Optics/Singlets/Symmetric-Concave-Lenses/Symmetric-concave-lenses-unmounted-N-BK7.html
LensesTwoSurfaces QioptiqLensCatalog::getQ_G313210000()
{
	return mQ_G313210000;
}

// *** Achromats VIS, Positive, dia. 3 mm to 31.5 mm, unmounted, ARB2 VIS
// https://www.qioptiq-shop.com/en/Precision-Optics/LINOS-Achromats-Lens-Systems/Achromats-positive/Achromats-VIS-Positive-dia-3-mm-to-31-5-mm-unmounted.html
LensThreeSurfaces QioptiqLensCatalog::getQ_G322218000()
{
	return mQ_G322218000;
}

// *** Achromats VIS, Positive from 40 mm diameter, unmounted, ARB2 VIS
// https://www.qioptiq-shop.com/en/Precision-Optics/LINOS-Achromats-Lens-Systems/Achromats-positive/Achromats-VIS-Positive-from-40-mm-diameter-unmounted.html
LensThreeSurfaces QioptiqLensCatalog::getQ_G322389000()
{
	return mQ_G322389000;
}

// *** Achromats VIS, Positive from 40 mm diameter, unmounted, ARB2 VIS
// https://www.qioptiq-shop.com/en/Precision-Optics/LINOS-Achromats-Lens-Systems/Achromats-negative/Achromats-Negative-Unmounted.html
LensThreeSurfaces QioptiqLensCatalog::getQ_G325221000()
{
	return mQ_G325221000;
}