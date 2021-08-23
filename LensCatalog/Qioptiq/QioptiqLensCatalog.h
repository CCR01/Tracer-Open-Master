#pragma once

#include "..\..\LensElements\LensesThreeSurfaces.h"
#include "..\..\LensElements\LensesFourSurfaces.h"

class QioptiqLensCatalog
{
public:
	QioptiqLensCatalog();
	~QioptiqLensCatalog();

	// load lens catalog from qioptiq
	// *** Plano-convex lenses, unmounted, ARB2 VIS
	void loadLensCatalogQioptiq_PlanoConvex_lenses_unmounted_ARB2_VIS(); // https://www.qioptiq-shop.com/en/Precision-Optics/Singlets/Plano-Convex-Lenses/Plano-convex-lenses-unmounted.html
	std::vector<LensesTwoSurfaces> getAll_Qioptiq_PlanoConvex_lenses_unmounted_ARB2_VIS();
	// ***

	// *** Symmetric - convex lenses, unmounted, ARB2 VIS
	void loadLensCatalogQioptiq_Symmetric_convex_lenses_unmounted_ARB2_VIS(); // https://www.qioptiq-shop.com/en/Precision-Optics/Singlets/Symmetric-Convex-Lenses/Symmetric-convex-lenses-unmounted.html
	std::vector<LensesTwoSurfaces> getAll_Symmetric_convex_lenses_unmounted_ARB2_VIS();
	// ***

	// *** Plano - concave lenses, unmounted (N - BK7), ARB2 VIS
	void loadLensCatalogQioptiq_Plano_concave_lenses_unmounted_N_BK7_ARB2_VIS(); // https://www.qioptiq-shop.com/en/Precision-Optics/Singlets/Plano-Concave-Lenses/Plano-concave-lenses-unmounted-N-BK7.html
	std::vector<LensesTwoSurfaces> getAll_Plano_concave_lenses_unmounted_N_BK7_ARB2_VIS();
	// ***

	// *** Symmetric - concave lenses, unmounted (N - BK7), ARB2 VIS
	void loadLensCatalogQioptiq_Symmetric_concave_lenses_unmounted_N_BK7_ARB2_VIS(); // https://www.qioptiq-shop.com/en/Precision-Optics/Singlets/Symmetric-Concave-Lenses/Symmetric-concave-lenses-unmounted-N-BK7.html
	std::vector<LensesTwoSurfaces> getAll_Symmetric_concave_lenses_unmounted_N_BK7_ARB2_VIS();
	// ***

	// *** Achromats VIS, Positive, dia. 3 mm to 31.5 mm, unmounted, ARB2 VIS
	void loadLensCatalogQioptiq_Achromats_VIS_Positive_dia_3_mm_to_31_5_mm_unmounted_N_BK7_ARB2_VIS(); // https://www.qioptiq-shop.com/en/Precision-Optics/LINOS-Achromats-Lens-Systems/Achromats-positive/Achromats-VIS-Positive-dia-3-mm-to-31-5-mm-unmounted.html
	std::vector<LensThreeSurfaces> getAll_Achromats_VIS_Positive_dia_3_mm_to_31_5_mm_unmounted_N_BK7_ARB2_VIS();
	// ***

	// *** Achromats VIS, Positive from 40 mm diameter, unmounted, ARB2 VIS
	void loadLensCatalogQioptiq_Achromats_VIS_Positive_from_40_mm_diameter_unmounted_N_BK7_ARB2_VIS(); // https://www.qioptiq-shop.com/en/Precision-Optics/LINOS-Achromats-Lens-Systems/Achromats-positive/Achromats-VIS-Positive-from-40-mm-diameter-unmounted.html
	std::vector<LensThreeSurfaces> getAll_Achromats_VIS_Positive_from_40_mm_diameter_unmounted_N_BK7_ARB2_VIS();
	// ***

	// *** Achromats, Negative, Unmounted, ARB2 VIS
	void loadLensCatalogQioptiq_Achromats_Negative_Unmounted_ARB2_VIS(); // https://www.qioptiq-shop.com/en/Precision-Optics/LINOS-Achromats-Lens-Systems/Achromats-negative/Achromats-Negative-Unmounted.html
	std::vector<LensThreeSurfaces> getAll_Achromats_Negative_Unmounted_ARB2_VIS();
	// ***

	//  *** Plano-Convex lenses, unmounted, ARB2-VIS
	// https://www.qioptiq-shop.com/en/Precision-Optics/Singlets/Plano-Convex-Lenses/Plano-convex-lenses-unmounted.html
	LensesTwoSurfaces getQ_G312003000();

	// *** Symmetric - convex lenses, unmounted, ARB2 VIS
	// https://www.qioptiq-shop.com/en/Precision-Optics/Singlets/Symmetric-Convex-Lenses/Symmetric-convex-lenses-unmounted.html
	LensesTwoSurfaces getQ_G311328000();

	// *** Plano - concave lenses, unmounted (N - BK7), ARB2 VIS
	// https://www.qioptiq-shop.com/en/Precision-Optics/Singlets/Plano-Concave-Lenses/Plano-concave-lenses-unmounted-N-BK7.html
	LensesTwoSurfaces getQ_G314001322();

	// *** Symmetric - concave lenses, unmounted (N - BK7), ARB2 VIS
	// https://www.qioptiq-shop.com/en/Precision-Optics/Singlets/Symmetric-Concave-Lenses/Symmetric-concave-lenses-unmounted-N-BK7.html
	LensesTwoSurfaces getQ_G313210000();

	// *** Achromats VIS, Positive, dia. 3 mm to 31.5 mm, unmounted, ARB2 VIS
	// https://www.qioptiq-shop.com/en/Precision-Optics/LINOS-Achromats-Lens-Systems/Achromats-positive/Achromats-VIS-Positive-dia-3-mm-to-31-5-mm-unmounted.html
	LensThreeSurfaces getQ_G322218000();

	// *** Achromats VIS, Positive from 40 mm diameter, unmounted, ARB2 VIS
	// https://www.qioptiq-shop.com/en/Precision-Optics/LINOS-Achromats-Lens-Systems/Achromats-positive/Achromats-VIS-Positive-from-40-mm-diameter-unmounted.html
	LensThreeSurfaces getQ_G322389000();

	// *** Achromats, Negative, Unmounted, ARB2 VIS
	// https://www.qioptiq-shop.com/en/Precision-Optics/LINOS-Achromats-Lens-Systems/Achromats-negative/Achromats-Negative-Unmounted.html
	LensThreeSurfaces getQ_G325221000();

private:

	//  *** Plano-Convex lenses, unmounted, ARB2-VIS
	// https://www.qioptiq-shop.com/en/Precision-Optics/Singlets/Plano-Convex-Lenses/Plano-convex-lenses-unmounted.html
	LensesTwoSurfaces mQ_G312003000{};

	// *** Symmetric - convex lenses, unmounted, ARB2 VIS
	// https://www.qioptiq-shop.com/en/Precision-Optics/Singlets/Symmetric-Convex-Lenses/Symmetric-convex-lenses-unmounted.html
	LensesTwoSurfaces mQ_G311328000{};

	// *** Plano - concave lenses, unmounted (N - BK7), ARB2 VIS
	// https://www.qioptiq-shop.com/en/Precision-Optics/Singlets/Plano-Concave-Lenses/Plano-concave-lenses-unmounted-N-BK7.html
	LensesTwoSurfaces mQ_G314001322{};

	// *** Symmetric - concave lenses, unmounted (N - BK7), ARB2 VIS
	// https://www.qioptiq-shop.com/en/Precision-Optics/Singlets/Symmetric-Concave-Lenses/Symmetric-concave-lenses-unmounted-N-BK7.html
	LensesTwoSurfaces mQ_G313210000{};

	// *** Achromats VIS, Positive, dia. 3 mm to 31.5 mm, unmounted, ARB2 VIS
	// https://www.qioptiq-shop.com/en/Precision-Optics/LINOS-Achromats-Lens-Systems/Achromats-positive/Achromats-VIS-Positive-dia-3-mm-to-31-5-mm-unmounted.html
	LensThreeSurfaces mQ_G322218000{};

	// *** Achromats VIS, Positive from 40 mm diameter, unmounted, ARB2 VIS
	// https://www.qioptiq-shop.com/en/Precision-Optics/LINOS-Achromats-Lens-Systems/Achromats-positive/Achromats-VIS-Positive-from-40-mm-diameter-unmounted.html
	LensThreeSurfaces mQ_G322389000{};

	// *** Achromats VIS, Positive from 40 mm diameter, unmounted, ARB2 VIS
	// https://www.qioptiq-shop.com/en/Precision-Optics/LINOS-Achromats-Lens-Systems/Achromats-negative/Achromats-Negative-Unmounted.html
	LensThreeSurfaces mQ_G325221000{};
};

