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
	LensesTwoSurfaces getQ_G312004000();
	LensesTwoSurfaces getQ_G312006000();
	LensesTwoSurfaces getQ_G312007000();
	LensesTwoSurfaces getQ_G312008000();
	LensesTwoSurfaces getQ_G312201000();
	LensesTwoSurfaces getQ_G312009000();
	LensesTwoSurfaces getQ_G312010000();
	LensesTwoSurfaces getQ_G312011000();
	LensesTwoSurfaces getQ_G312236000();
	LensesTwoSurfaces getQ_G312329000();
	LensesTwoSurfaces getQ_G312330000();
	LensesTwoSurfaces getQ_G312351000();
	LensesTwoSurfaces getQ_G312352000();
	LensesTwoSurfaces getQ_G312353000();
	LensesTwoSurfaces getQ_G312354000();
	LensesTwoSurfaces getQ_G312355000();
	LensesTwoSurfaces getQ_G312356000();
	LensesTwoSurfaces getQ_G312357000();
	LensesTwoSurfaces getQ_G312358000();
	LensesTwoSurfaces getQ_G312331000();
	LensesTwoSurfaces getQ_G312314000();
	LensesTwoSurfaces getQ_G312315000();
	LensesTwoSurfaces getQ_G312316000();
	LensesTwoSurfaces getQ_G312317000();
	LensesTwoSurfaces getQ_G312318000();
	LensesTwoSurfaces getQ_G312319000();
	LensesTwoSurfaces getQ_G312320000();
	LensesTwoSurfaces getQ_G312321000();
	LensesTwoSurfaces getQ_G312322000();
	LensesTwoSurfaces getQ_G312323000();
	LensesTwoSurfaces getQ_G312324000();
	LensesTwoSurfaces getQ_G312325000();
	LensesTwoSurfaces getQ_G312326000();
	LensesTwoSurfaces getQ_G312327000();
	LensesTwoSurfaces getQ_G312328000();
	LensesTwoSurfaces getQ_G312401000();
	LensesTwoSurfaces getQ_G312402000();
	LensesTwoSurfaces getQ_G312332000();
	LensesTwoSurfaces getQ_G312403000();
	LensesTwoSurfaces getQ_G312333000();
	LensesTwoSurfaces getQ_G312404000();
	LensesTwoSurfaces getQ_G312405000();
	LensesTwoSurfaces getQ_G312406000();
	LensesTwoSurfaces getQ_G312407000();
	LensesTwoSurfaces getQ_G312312000();
	LensesTwoSurfaces getQ_G312340000();
	LensesTwoSurfaces getQ_G312350000();
	LensesTwoSurfaces getQ_G312341000();
	LensesTwoSurfaces getQ_G312334000();
	LensesTwoSurfaces getQ_G312335000();
	LensesTwoSurfaces getQ_G312361000();
	LensesTwoSurfaces getQ_G312363000();
	LensesTwoSurfaces getQ_G312001000();
	LensesTwoSurfaces getQ_G312362000();

	// *** Symmetric - convex lenses, unmounted, ARB2 VIS
	// https://www.qioptiq-shop.com/en/Precision-Optics/Singlets/Symmetric-Convex-Lenses/Symmetric-convex-lenses-unmounted.html
	LensesTwoSurfaces getQ_G311328000();
	LensesTwoSurfaces getQ_G311329000();
	LensesTwoSurfaces getQ_G311300000();
	LensesTwoSurfaces getQ_G311377000();
	LensesTwoSurfaces getQ_G311381000();
	LensesTwoSurfaces getQ_G311382000();
	LensesTwoSurfaces getQ_G311383000();
	LensesTwoSurfaces getQ_G311384000();
	LensesTwoSurfaces getQ_G311385000();
	LensesTwoSurfaces getQ_G311386000();
	LensesTwoSurfaces getQ_G311387000();
	LensesTwoSurfaces getQ_G311378000();
	LensesTwoSurfaces getQ_G311338000();
	LensesTwoSurfaces getQ_G311308000();
	LensesTwoSurfaces getQ_G311310000();
	LensesTwoSurfaces getQ_G311314000();
	LensesTwoSurfaces getQ_G311315000();
	LensesTwoSurfaces getQ_G311316000();
	LensesTwoSurfaces getQ_G311317000();
	LensesTwoSurfaces getQ_G311318000();
	LensesTwoSurfaces getQ_G311319000();
	LensesTwoSurfaces getQ_G311320000();
	LensesTwoSurfaces getQ_G311321000();
	LensesTwoSurfaces getQ_G311322000();
	LensesTwoSurfaces getQ_G311323000();
	LensesTwoSurfaces getQ_G311324000();
	LensesTwoSurfaces getQ_G311325000();
	LensesTwoSurfaces getQ_G311331000();
	LensesTwoSurfaces getQ_G311339000();
	LensesTwoSurfaces getQ_G311351000();
	LensesTwoSurfaces getQ_G311357000();
	LensesTwoSurfaces getQ_G311333000();
	LensesTwoSurfaces getQ_G311335000();
	LensesTwoSurfaces getQ_G311347000();
	LensesTwoSurfaces getQ_G311348000();
	LensesTwoSurfaces getQ_G311341000();
	LensesTwoSurfaces getQ_G311345000();
	LensesTwoSurfaces getQ_G311346000();

	// *** Plano - concave lenses, unmounted (N - BK7), ARB2 VIS
	// https://www.qioptiq-shop.com/en/Precision-Optics/Singlets/Plano-Concave-Lenses/Plano-concave-lenses-unmounted-N-BK7.html
	LensesTwoSurfaces getQ_G314001000();
	LensesTwoSurfaces getQ_G314304000();
	LensesTwoSurfaces getQ_G314002000();
	LensesTwoSurfaces getQ_G314003000();
	LensesTwoSurfaces getQ_G314005000();
	LensesTwoSurfaces getQ_G314331000();
	LensesTwoSurfaces getQ_G314332000();
	LensesTwoSurfaces getQ_G314333000();
	LensesTwoSurfaces getQ_G314334000();
	LensesTwoSurfaces getQ_G314335000();
	LensesTwoSurfaces getQ_G314301000();
	LensesTwoSurfaces getQ_G314315000();
	LensesTwoSurfaces getQ_G314316000();
	LensesTwoSurfaces getQ_G314317000();
	LensesTwoSurfaces getQ_G314321000();
	LensesTwoSurfaces getQ_G314322000();
	LensesTwoSurfaces getQ_G314323000();
	LensesTwoSurfaces getQ_G314324000();
	LensesTwoSurfaces getQ_G314325000();

	// *** Symmetric - concave lenses, unmounted (N - BK7), ARB2 VIS
	// https://www.qioptiq-shop.com/en/Precision-Optics/Singlets/Symmetric-Concave-Lenses/Symmetric-concave-lenses-unmounted-N-BK7.html
	LensesTwoSurfaces getQ_G313210000();
	LensesTwoSurfaces getQ_G313373000();
	LensesTwoSurfaces getQ_G313374000();
	LensesTwoSurfaces getQ_G313375000();
	LensesTwoSurfaces getQ_G313376000();
	LensesTwoSurfaces getQ_G313205000();
	LensesTwoSurfaces getQ_G313206000();
	LensesTwoSurfaces getQ_G313214000();
	LensesTwoSurfaces getQ_G313215000();
	LensesTwoSurfaces getQ_G313216000();
	LensesTwoSurfaces getQ_G313217000();
	LensesTwoSurfaces getQ_G313337000();
	LensesTwoSurfaces getQ_G313339000();
	LensesTwoSurfaces getQ_G313249000();

	// *** Achromats VIS, Positive, dia. 3 mm to 31.5 mm, unmounted, ARB2 VIS
	// https://www.qioptiq-shop.com/en/Precision-Optics/LINOS-Achromats-Lens-Systems/Achromats-positive/Achromats-VIS-Positive-dia-3-mm-to-31-5-mm-unmounted.html
	LensThreeSurfaces getQ_G322218000();
	LensThreeSurfaces getQ_G322219000();
	LensThreeSurfaces getQ_G322250000();
	LensThreeSurfaces getQ_G322220000();
	LensThreeSurfaces getQ_G322206000();
	LensThreeSurfaces getQ_G322222000();
	LensThreeSurfaces getQ_G322223000();
	LensThreeSurfaces getQ_G322207000();
	LensThreeSurfaces getQ_G322356322();
	LensThreeSurfaces getQ_G322357322();
	LensThreeSurfaces getQ_G322358322();
	LensThreeSurfaces getQ_G322359322();
	LensThreeSurfaces getQ_G322360322();
	//LensThreeSurfaces getQ_G322361322();
	LensThreeSurfaces getQ_G322362322();
	LensThreeSurfaces getQ_G322363322();
	LensThreeSurfaces getQ_G322364322();
	LensThreeSurfaces getQ_G322365322();
	LensThreeSurfaces getQ_G322366322();
	LensThreeSurfaces getQ_G322367322();
	LensThreeSurfaces getQ_G322368322();
	LensThreeSurfaces getQ_G322201000();
	LensThreeSurfaces getQ_G322284000();
	LensThreeSurfaces getQ_G322285000();
	LensThreeSurfaces getQ_G322286000();
	LensThreeSurfaces getQ_G322337000();
	LensThreeSurfaces getQ_G322338000();
	LensThreeSurfaces getQ_G322339000();
	LensThreeSurfaces getQ_G322341000();
	LensThreeSurfaces getQ_G322343000();
	LensThreeSurfaces getQ_G322345000();
	LensThreeSurfaces getQ_G322320322();
	LensThreeSurfaces getQ_G322325322();
	LensThreeSurfaces getQ_G322327322();
	//LensThreeSurfaces getQ_G322209000();
	LensThreeSurfaces getQ_G322265000();
	LensThreeSurfaces getQ_G322266000();
	LensThreeSurfaces getQ_G322210000();
	LensThreeSurfaces getQ_G322236000();
	LensThreeSurfaces getQ_G322331322();
	LensThreeSurfaces getQ_G322332322();
	LensThreeSurfaces getQ_G322321322();
	LensThreeSurfaces getQ_G322321000();
	LensThreeSurfaces getQ_G322322000();
	LensThreeSurfaces getQ_G322323000();
	LensThreeSurfaces getQ_G322324000();
	LensThreeSurfaces getQ_G322326000();
	LensThreeSurfaces getQ_G322333322();
	LensThreeSurfaces getQ_G322328000();
	LensThreeSurfaces getQ_G322334322();
	LensThreeSurfaces getQ_G322329000();
	LensThreeSurfaces getQ_G322306322();
	LensThreeSurfaces getQ_G322307322();
	LensThreeSurfaces getQ_G322308322();
	LensThreeSurfaces getQ_G322309322();
	LensThreeSurfaces getQ_G322351000();
	LensThreeSurfaces getQ_G322352000();
	LensThreeSurfaces getQ_G322353000();
	LensThreeSurfaces getQ_G322336322();
	LensThreeSurfaces getQ_G322340322();
	LensThreeSurfaces getQ_G322355000();
	LensThreeSurfaces getQ_G322287322();
	LensThreeSurfaces getQ_G322288322();
	LensThreeSurfaces getQ_G322269322();
	LensThreeSurfaces getQ_G322239322();
	LensThreeSurfaces getQ_G322227322();
	LensThreeSurfaces getQ_G322270322();
	LensThreeSurfaces getQ_G322342322();
	LensThreeSurfaces getQ_G322271322();
	LensThreeSurfaces getQ_G322272322();
	LensThreeSurfaces getQ_G322273322();
	LensThreeSurfaces getQ_G322275322();
	//LensThreeSurfaces getQ_G322277322();

	// *** Achromats VIS, Positive from 40 mm diameter, unmounted, ARB2 VIS
	// https://www.qioptiq-shop.com/en/Precision-Optics/LINOS-Achromats-Lens-Systems/Achromats-positive/Achromats-VIS-Positive-from-40-mm-diameter-unmounted.html
	LensThreeSurfaces getQ_G322389000();
	LensThreeSurfaces getQ_G322388000();
	LensThreeSurfaces getQ_G322384000();
	LensThreeSurfaces getQ_G322246000();
	LensThreeSurfaces getQ_G322293000();
	LensThreeSurfaces getQ_G322294000();
	LensThreeSurfaces getQ_G322295000();
	//LensThreeSurfaces getQ_G322373322();
	LensThreeSurfaces getQ_G322301000();
	LensThreeSurfaces getQ_G322302000();
	LensThreeSurfaces getQ_G322303000();
	//LensThreeSurfaces getQ_G322369322();
	LensThreeSurfaces getQ_G322304000();
	LensThreeSurfaces getQ_G322305000();
	LensThreeSurfaces getQ_G322310000();
	LensThreeSurfaces getQ_G322311000();
	LensThreeSurfaces getQ_G322312000();
	LensThreeSurfaces getQ_G322383000();
	LensThreeSurfaces getQ_G322230000();
	LensThreeSurfaces getQ_G322232000();
	LensThreeSurfaces getQ_G322267000();
	LensThreeSurfaces getQ_G322278000();
	LensThreeSurfaces getQ_G322279000();
	LensThreeSurfaces getQ_G322316000();
	//LensThreeSurfaces getQ_G322313000();
	//LensThreeSurfaces getQ_G322386000();

	// *** Achromats, Negative, Unmounted, ARB2 VIS
	// https://www.qioptiq-shop.com/en/Precision-Optics/LINOS-Achromats-Lens-Systems/Achromats-negative/Achromats-Negative-Unmounted.html
	LensThreeSurfaces getQ_G325221000();

private:

	//  *** Plano-Convex lenses, unmounted, ARB2-VIS
	// https://www.qioptiq-shop.com/en/Precision-Optics/Singlets/Plano-Convex-Lenses/Plano-convex-lenses-unmounted.html
	LensesTwoSurfaces mQ_G312003000{};
	LensesTwoSurfaces mQ_G312004000{};
	LensesTwoSurfaces mQ_G312006000{};
	LensesTwoSurfaces mQ_G312007000{};
	LensesTwoSurfaces mQ_G312008000{};
	LensesTwoSurfaces mQ_G312201000{};
	LensesTwoSurfaces mQ_G312009000{};
	LensesTwoSurfaces mQ_G312010000{};
	LensesTwoSurfaces mQ_G312011000{};
	LensesTwoSurfaces mQ_G312236000{};
	LensesTwoSurfaces mQ_G312329000{};
	LensesTwoSurfaces mQ_G312330000{};
	LensesTwoSurfaces mQ_G312351000{};
	LensesTwoSurfaces mQ_G312352000{};
	LensesTwoSurfaces mQ_G312353000{};
	LensesTwoSurfaces mQ_G312354000{};
	LensesTwoSurfaces mQ_G312355000{};
	LensesTwoSurfaces mQ_G312356000{};
	LensesTwoSurfaces mQ_G312357000{};
	LensesTwoSurfaces mQ_G312358000{};
	LensesTwoSurfaces mQ_G312331000{};
	LensesTwoSurfaces mQ_G312314000{};
	LensesTwoSurfaces mQ_G312315000{};
	LensesTwoSurfaces mQ_G312316000{};
	LensesTwoSurfaces mQ_G312317000{};
	LensesTwoSurfaces mQ_G312318000{};
	LensesTwoSurfaces mQ_G312319000{};
	LensesTwoSurfaces mQ_G312320000{};
	LensesTwoSurfaces mQ_G312321000{};
	LensesTwoSurfaces mQ_G312322000{};
	LensesTwoSurfaces mQ_G312323000{};
	LensesTwoSurfaces mQ_G312324000{};
	LensesTwoSurfaces mQ_G312325000{};
	LensesTwoSurfaces mQ_G312326000{};
	LensesTwoSurfaces mQ_G312327000{};
	LensesTwoSurfaces mQ_G312328000{};
	LensesTwoSurfaces mQ_G312401000{};
	LensesTwoSurfaces mQ_G312402000{};
	LensesTwoSurfaces mQ_G312332000{};
	LensesTwoSurfaces mQ_G312403000{};
	LensesTwoSurfaces mQ_G312333000{};
	LensesTwoSurfaces mQ_G312404000{};
	LensesTwoSurfaces mQ_G312405000{};
	LensesTwoSurfaces mQ_G312406000{};
	LensesTwoSurfaces mQ_G312407000{};
	LensesTwoSurfaces mQ_G312312000{};
	LensesTwoSurfaces mQ_G312340000{};
	LensesTwoSurfaces mQ_G312350000{};
	LensesTwoSurfaces mQ_G312341000{};
	LensesTwoSurfaces mQ_G312334000{};
	LensesTwoSurfaces mQ_G312335000{};
	LensesTwoSurfaces mQ_G312361000{};
	LensesTwoSurfaces mQ_G312363000{};
	LensesTwoSurfaces mQ_G312001000{};
	LensesTwoSurfaces mQ_G312362000{};



	// *** Symmetric - convex lenses, unmounted, ARB2 VIS
	// https://www.qioptiq-shop.com/en/Precision-Optics/Singlets/Symmetric-Convex-Lenses/Symmetric-convex-lenses-unmounted.html
	LensesTwoSurfaces mQ_G311328000{};
	LensesTwoSurfaces mQ_G311329000{};
	LensesTwoSurfaces mQ_G311300000{};
	LensesTwoSurfaces mQ_G311377000{};
	LensesTwoSurfaces mQ_G311381000{};
	LensesTwoSurfaces mQ_G311382000{};
	LensesTwoSurfaces mQ_G311383000{};
	LensesTwoSurfaces mQ_G311384000{};
	LensesTwoSurfaces mQ_G311385000{};
	LensesTwoSurfaces mQ_G311386000{};
	LensesTwoSurfaces mQ_G311387000{};
	LensesTwoSurfaces mQ_G311378000{};
	LensesTwoSurfaces mQ_G311338000{};
	LensesTwoSurfaces mQ_G311308000{};
	LensesTwoSurfaces mQ_G311310000{};
	LensesTwoSurfaces mQ_G311314000{};
	LensesTwoSurfaces mQ_G311315000{};
	LensesTwoSurfaces mQ_G311316000{};
	LensesTwoSurfaces mQ_G311317000{};
	LensesTwoSurfaces mQ_G311318000{};
	LensesTwoSurfaces mQ_G311319000{};
	LensesTwoSurfaces mQ_G311320000{};
	LensesTwoSurfaces mQ_G311321000{};
	LensesTwoSurfaces mQ_G311322000{};
	LensesTwoSurfaces mQ_G311323000{};
	LensesTwoSurfaces mQ_G311324000{};
	LensesTwoSurfaces mQ_G311325000{};
	LensesTwoSurfaces mQ_G311331000{};
	LensesTwoSurfaces mQ_G311339000{};
	LensesTwoSurfaces mQ_G311351000{};
	LensesTwoSurfaces mQ_G311357000{};
	LensesTwoSurfaces mQ_G311333000{};
	LensesTwoSurfaces mQ_G311335000{};
	LensesTwoSurfaces mQ_G311347000{};
	LensesTwoSurfaces mQ_G311348000{};
	LensesTwoSurfaces mQ_G311341000{};
	LensesTwoSurfaces mQ_G311345000{};
	LensesTwoSurfaces mQ_G311346000{};


	// *** Plano - concave lenses, unmounted (N - BK7), ARB2 VIS
	// https://www.qioptiq-shop.com/en/Precision-Optics/Singlets/Plano-Concave-Lenses/Plano-concave-lenses-unmounted-N-BK7.html
	LensesTwoSurfaces mQ_G314001000{};
	LensesTwoSurfaces mQ_G314304000{};
	LensesTwoSurfaces mQ_G314002000{};
	LensesTwoSurfaces mQ_G314003000{};
	LensesTwoSurfaces mQ_G314005000{};
	LensesTwoSurfaces mQ_G314331000{};
	LensesTwoSurfaces mQ_G314332000{};
	LensesTwoSurfaces mQ_G314333000{};
	LensesTwoSurfaces mQ_G314334000{};
	LensesTwoSurfaces mQ_G314335000{};
	LensesTwoSurfaces mQ_G314301000{};
	LensesTwoSurfaces mQ_G314315000{};
	LensesTwoSurfaces mQ_G314316000{};
	LensesTwoSurfaces mQ_G314317000{};
	LensesTwoSurfaces mQ_G314321000{};
	LensesTwoSurfaces mQ_G314322000{};
	LensesTwoSurfaces mQ_G314323000{};
	LensesTwoSurfaces mQ_G314324000{};
	LensesTwoSurfaces mQ_G314325000{};

	// *** Symmetric - concave lenses, unmounted (N - BK7), ARB2 VIS
	// https://www.qioptiq-shop.com/en/Precision-Optics/Singlets/Symmetric-Concave-Lenses/Symmetric-concave-lenses-unmounted-N-BK7.html
	LensesTwoSurfaces mQ_G313210000{};
	LensesTwoSurfaces mQ_G313373000{};
	LensesTwoSurfaces mQ_G313374000{};
	LensesTwoSurfaces mQ_G313375000{};
	LensesTwoSurfaces mQ_G313376000{};
	LensesTwoSurfaces mQ_G313205000{};
	LensesTwoSurfaces mQ_G313206000{};
	LensesTwoSurfaces mQ_G313214000{};
	LensesTwoSurfaces mQ_G313215000{};
	LensesTwoSurfaces mQ_G313216000{};
	LensesTwoSurfaces mQ_G313217000{};
	LensesTwoSurfaces mQ_G313337000{};
	LensesTwoSurfaces mQ_G313339000{};
	LensesTwoSurfaces mQ_G313249000{};

	// *** Achromats VIS, Positive, dia. 3 mm to 31.5 mm, unmounted, ARB2 VIS
	// https://www.qioptiq-shop.com/en/Precision-Optics/LINOS-Achromats-Lens-Systems/Achromats-positive/Achromats-VIS-Positive-dia-3-mm-to-31-5-mm-unmounted.html
	LensThreeSurfaces mQ_G322218000{};
	LensThreeSurfaces mQ_G322219000{};
	LensThreeSurfaces mQ_G322250000{};
	LensThreeSurfaces mQ_G322220000{};
	LensThreeSurfaces mQ_G322206000{};
	LensThreeSurfaces mQ_G322222000{};
	LensThreeSurfaces mQ_G322223000{};
	LensThreeSurfaces mQ_G322207000{};
	LensThreeSurfaces mQ_G322356322{};
	LensThreeSurfaces mQ_G322357322{};
	LensThreeSurfaces mQ_G322358322{};
	LensThreeSurfaces mQ_G322359322{};
	LensThreeSurfaces mQ_G322360322{};
	//LensThreeSurfaces mQ_G322361322{};
	LensThreeSurfaces mQ_G322362322{};
	LensThreeSurfaces mQ_G322363322{};
	LensThreeSurfaces mQ_G322364322{};
	LensThreeSurfaces mQ_G322365322{};
	LensThreeSurfaces mQ_G322366322{};
	LensThreeSurfaces mQ_G322367322{};
	LensThreeSurfaces mQ_G322368322{};
	LensThreeSurfaces mQ_G322201000{};
	LensThreeSurfaces mQ_G322284000{};
	LensThreeSurfaces mQ_G322285000{};
	LensThreeSurfaces mQ_G322286000{};
	LensThreeSurfaces mQ_G322337000{};
	LensThreeSurfaces mQ_G322338000{};
	LensThreeSurfaces mQ_G322339000{};
	LensThreeSurfaces mQ_G322341000{};
	LensThreeSurfaces mQ_G322343000{};
	LensThreeSurfaces mQ_G322345000{};
	LensThreeSurfaces mQ_G322320322{};
	LensThreeSurfaces mQ_G322325322{};
	LensThreeSurfaces mQ_G322327322{};
	//LensThreeSurfaces mQ_G322209000{};
	LensThreeSurfaces mQ_G322265000{};
	LensThreeSurfaces mQ_G322266000{};
	LensThreeSurfaces mQ_G322210000{};
	LensThreeSurfaces mQ_G322236000{};
	LensThreeSurfaces mQ_G322331322{};
	LensThreeSurfaces mQ_G322332322{};
	LensThreeSurfaces mQ_G322321000{};
	LensThreeSurfaces mQ_G322322000{};
	LensThreeSurfaces mQ_G322323000{};
	LensThreeSurfaces mQ_G322324000{};
	LensThreeSurfaces mQ_G322326000{};
	LensThreeSurfaces mQ_G322333322{};
	LensThreeSurfaces mQ_G322328000{};
	LensThreeSurfaces mQ_G322334322{};
	LensThreeSurfaces mQ_G322329000{};
	LensThreeSurfaces mQ_G322306322{};
	LensThreeSurfaces mQ_G322307322{};
	LensThreeSurfaces mQ_G322308322{};
	LensThreeSurfaces mQ_G322309322{};
	LensThreeSurfaces mQ_G322351000{};
	LensThreeSurfaces mQ_G322352000{};
	LensThreeSurfaces mQ_G322353000{};
	LensThreeSurfaces mQ_G322336322{};
	LensThreeSurfaces mQ_G322340322{};
	LensThreeSurfaces mQ_G322355000{};
	LensThreeSurfaces mQ_G322287322{};
	LensThreeSurfaces mQ_G322288322{};
	LensThreeSurfaces mQ_G322269322{};
	LensThreeSurfaces mQ_G322239322{};
	LensThreeSurfaces mQ_G322227322{};
	LensThreeSurfaces mQ_G322270322{};
	LensThreeSurfaces mQ_G322342322{};
	LensThreeSurfaces mQ_G322271322{};
	LensThreeSurfaces mQ_G322272322{};
	LensThreeSurfaces mQ_G322273322{};
	LensThreeSurfaces mQ_G322275322{};
	//LensThreeSurfaces mQ_G322277322{};


	// *** Achromats VIS, Positive from 40 mm diameter, unmounted, ARB2 VIS
	// https://www.qioptiq-shop.com/en/Precision-Optics/LINOS-Achromats-Lens-Systems/Achromats-positive/Achromats-VIS-Positive-from-40-mm-diameter-unmounted.html
	LensThreeSurfaces mQ_G322389000{};
	LensThreeSurfaces mQ_G322388000{};
	LensThreeSurfaces mQ_G322384000{};
	LensThreeSurfaces mQ_G322246000{};
	LensThreeSurfaces mQ_G322293000{};
	LensThreeSurfaces mQ_G322294000{};
	LensThreeSurfaces mQ_G322295000{};
	//LensThreeSurfaces mQ_G322373322{};
	LensThreeSurfaces mQ_G322301000{};
	LensThreeSurfaces mQ_G322302000{};
	LensThreeSurfaces mQ_G322303000{};
	//LensThreeSurfaces mQ_G322369322{};
	LensThreeSurfaces mQ_G322304000{};
	LensThreeSurfaces mQ_G322305000{};
	LensThreeSurfaces mQ_G322310000{};
	LensThreeSurfaces mQ_G322311000{};
	LensThreeSurfaces mQ_G322312000{};
	LensThreeSurfaces mQ_G322383000{};
	LensThreeSurfaces mQ_G322230000{};
	LensThreeSurfaces mQ_G322232000{};
	LensThreeSurfaces mQ_G322267000{};
	LensThreeSurfaces mQ_G322278000{};
	LensThreeSurfaces mQ_G322279000{};
	LensThreeSurfaces mQ_G322316000{};
	//LensThreeSurfaces mQ_G322313000{};
	//LensThreeSurfaces mQ_G322386000{};

	// *** Achromats VIS, Negative from 40 mm diameter, unmounted, ARB2 VIS
	// https://www.qioptiq-shop.com/en/Precision-Optics/LINOS-Achromats-Lens-Systems/Achromats-negative/Achromats-Negative-Unmounted.html
	LensThreeSurfaces mQ_G325221000{};
};

