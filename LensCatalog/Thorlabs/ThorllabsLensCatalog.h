#pragma once
#include "..\..\Glasses\Glasses.h"
#include "..\..\LensElements\LensesThreeSurfaces.h"
#include "..\..\LensElements\LensesFourSurfaces.h"

class ThorlabsLensCatalog
{
public:
	ThorlabsLensCatalog();
	~ThorlabsLensCatalog();


	// load the lens catalog from Thorlabs

	// *** Achromativ Doublets AR_Coated lenses
	void loadLensCatalogThorlabs_Achromativ_Doublets_AR_Coated_lenses(); // https://www.thorlabs.com/newgrouppage9.cfm?objectgroup_id=12767
	std::vector<LensThreeSurfaces> getAll_Thorlabs_Achromativ_Doublets_AR_Coated_lenses();
	// ***

	// *** N BK7 Plano Convex Lenses AR Coating 400 1100 nm
	void loadLensCatalogThorlabs_N_BK7_Plano_Convex_Lenses_AR_Coating_400_1100_nm(); // https://www.thorlabs.de/newgrouppage9.cfm?objectgroup_id=13685
	std::vector<LensesTwoSurfaces> getAll_Thorlabs_N_BK7_Plano_Convex_Lenses_AR_Coating_400_1100_nm();
	// ***

	// *** N BK7 Bi-Convex Lenses AR Coating: 350 - 700 nm
	void loadLensCatalogThorlabs_N_BK7_Bi_Convex_Lenses_AR_Coating_350_700_nm(); // https://www.thorlabs.de/newgrouppage9.cfm?objectgroup_id=4848
	std::vector<LensesTwoSurfaces> getAll_Thorlabs_N_BK7_Bi_Convex_Lenses_AR_Coating_350_700_nm();
	// ***

	// *** N-BK7 Plano-Concave Lenses, AR Coating 350 - 700 nm
	void loadLensCatalogThorlabs_N_BK7_Plano_Concave_Lenses_AR_Coating_350_700_nm(); //	https://www.thorlabs.de/newgrouppage9.cfm?objectgroup_id=6509
	std::vector<LensesTwoSurfaces> getAll_Thorlabs_N_BK7_Plano_Concave_Lenses_AR_Coating_350_700_nm();

	// *** N-BK7 and N-SF11 Bi-Concave Lenses, AR Coating 350 - 700 nm
	void loadLensCatalogThorlabs_N_BK7_and_N_SF11_Bi_Concave_Lenses_AR_Coating_350_700_nm(); /// https://www.thorlabs.de/newgrouppage9.cfm?objectgroup_id=9733
	std::vector<LensesTwoSurfaces> getAll_Thorlabs_N_BK7_and_N_SF11_BiSConcave_Lenses_AR_Coating_350_700_nm();

	// *** Ø1" N-BK7 Best Form Spherical Lenses, AR Coating: 350-700 nm
	void loadLensCatalogThorlabs_1Zoll_N_BK7_Best_Form_Spherical_Lenses_AR_Coating_350_700_nm(); // https://www.thorlabs.de/newgrouppage9.cfm?objectgroup_id=4874
	std::vector<LensesTwoSurfaces> getAll_Thorlabs_1Zoll_N_BK7_Best_Form_Spherical_Lenses_AR_Coating_350_700_nm();

	// *** N-BK7 Positive Meniscus Lenses
	void loadLensCatalogThorlabs_N_BK7_Positive_Meniscus_Lenses_Uncoated(); // https://www.thorlabs.de/newgrouppage9.cfm?objectgroup_id=130
	std::vector<LensesTwoSurfaces> getAll_Thorlabs_N_BK7_Positive_Meniscus_Lenses_Uncoated();

	// *** Ø1" N-BK7 Negative Meniscus Lenses Uncoated
	void loadLensCatalogThorlabs_1Zoll_N_BK7_Negative_Meniscus_Lenses_Uncoated(); // https://www.thorlabs.de/newgrouppage9.cfm?objectgroup_id=902
	std::vector<LensesTwoSurfaces> getAll_1Zoll_N_BK7_Negative_Meniscus_Lenses_Uncoated();

	// *** Steinheil Triplet Achromatic Lenses, Visible
	void loadLensCatalogThorlabs_Steinheil_Triplet_Achromatic_Lenses_Visible(); // https://www.thorlabs.de/newgrouppage9.cfm?objectgroup_id=5370
	std::vector<LensFourSurfaces> getAll_Steinheil_Triplet_Achromatic_Lenses_Visible();

	// *** Hastings Triplet Achromatic Lenses, Visible
	void loadLensCatalogThorlabs_Hastings_Triplet_Achromatic_Lenses_Visible(); // https://www.thorlabs.de/newgrouppage9.cfm?objectgroup_id=5368
	std::vector<LensFourSurfaces> getAll_Hastings_Triplet_Achromatic_Lenses_Visible();

	// Unmounted Achromatic Doublets, AR Coated: 400 - 1100 nm
	// https://www.thorlabs.com/newgrouppage9.cfm?objectgroup_id=12767
	LensThreeSurfaces getT_AC127019AB();
	LensThreeSurfaces getT_AC127025AB();
	LensThreeSurfaces getT_AC127030AB();
	LensThreeSurfaces getT_AC127050AB();
	LensThreeSurfaces getT_AC127075AB();
	//	LensThreeSurfaces getT_AC254030AB();
	LensThreeSurfaces getT_AC254050AB();
	LensThreeSurfaces getT_AC254075AB();
	LensThreeSurfaces getT_AC254100AB();
	LensThreeSurfaces getT_AC254150AB();
	LensThreeSurfaces getT_AC254200AB();
	LensThreeSurfaces getT_AC508080AB();
	LensThreeSurfaces getT_AC508180AB();
	LensThreeSurfaces getT_AC508300AB();
	LensThreeSurfaces getT_AC508400AB();
	LensThreeSurfaces getT_AC508500AB();
	LensThreeSurfaces getT_AC508600AB();


	//  *** N BK7 Plano Convex Lenses AR Coating 400 1100 nm
	// https://www.thorlabs.de/newgrouppage9.cfm?objectgroup_id=13685
	LensesTwoSurfaces getT_LA1540AB();
	LensesTwoSurfaces getT_LA1074AB();
	LensesTwoSurfaces getT_LA1560AB();
	LensesTwoSurfaces getT_LA1289AB();
	LensesTwoSurfaces getT_LA1304AB();
	LensesTwoSurfaces getT_LA1213AB();
	LensesTwoSurfaces getT_LA1207AB();
	LensesTwoSurfaces getT_LA1951AB();
	LensesTwoSurfaces getT_LA1805AB();
	LensesTwoSurfaces getT_LA1027AB();
	LensesTwoSurfaces getT_LA1422AB();
	LensesTwoSurfaces getT_LA1131AB();
	LensesTwoSurfaces getT_LA1134AB();
	LensesTwoSurfaces getT_LA1608AB();
	LensesTwoSurfaces getT_LA1986AB();
	LensesTwoSurfaces getT_LA1433AB();
	LensesTwoSurfaces getT_LA1229AB();
	LensesTwoSurfaces getT_LA1708AB();
	LensesTwoSurfaces getT_LA1461AB();
	LensesTwoSurfaces getT_LA1484AB();
	LensesTwoSurfaces getT_LA1172AB();
	LensesTwoSurfaces getT_LA1908AB();
	LensesTwoSurfaces getT_LA1978AB();
	LensesTwoSurfaces getT_LA1464AB();
	LensesTwoSurfaces getT_LA1254AB();
	LensesTwoSurfaces getT_LA1258AB();
	LensesTwoSurfaces getT_LA1259AB();
	LensesTwoSurfaces getT_LA1401AB();
	LensesTwoSurfaces getT_LA1145AB();
	LensesTwoSurfaces getT_LA1050AB();
	LensesTwoSurfaces getT_LA1384AB();
	LensesTwoSurfaces getT_LA1417AB();
	LensesTwoSurfaces getT_LA1399AB();
	LensesTwoSurfaces getT_LA1979AB();
	LensesTwoSurfaces getT_LA1301AB();
	LensesTwoSurfaces getT_LA1256AB();
	LensesTwoSurfaces getT_LA1725AB();
	LensesTwoSurfaces getT_LA1380AB();
	LensesTwoSurfaces getT_LA1727AB();
	LensesTwoSurfaces getT_LA1779AB();

	// *** N BK7 Bi-Convex Lenses AR Coating: 350 - 700 nm
	// https://www.thorlabs.de/newgrouppage9.cfm?objectgroup_id=4848
	LensesTwoSurfaces getT_LB1157A();
	LensesTwoSurfaces getT_LB1406A();
	LensesTwoSurfaces getT_LB1494A();
	LensesTwoSurfaces getT_LB1212A();
	LensesTwoSurfaces getT_LB1092A();
	LensesTwoSurfaces getT_LB1450A();
	LensesTwoSurfaces getT_LB1014A();
	LensesTwoSurfaces getT_LB1258A();
	LensesTwoSurfaces getT_LB1378A();
	LensesTwoSurfaces getT_LB1844A();
	LensesTwoSurfaces getT_LB1187A();
	LensesTwoSurfaces getT_LB1761A();
	LensesTwoSurfaces getT_LB1757A();
	LensesTwoSurfaces getT_LB1811A();
	LensesTwoSurfaces getT_LB1027A();
	LensesTwoSurfaces getT_LB1471A();
	LensesTwoSurfaces getT_LB1596A();
	LensesTwoSurfaces getT_LB1901A();
	LensesTwoSurfaces getT_LB1676A();
	LensesTwoSurfaces getT_LB1904A();
	LensesTwoSurfaces getT_LB1437A();
	LensesTwoSurfaces getT_LB1294A();
	LensesTwoSurfaces getT_LB1945A();
	LensesTwoSurfaces getT_LB1056A();
	LensesTwoSurfaces getT_LB1779A();
	LensesTwoSurfaces getT_LB1391A();
	LensesTwoSurfaces getT_LB1869A();
	LensesTwoSurfaces getT_LB1475A();
	LensesTwoSurfaces getT_LB1409A();
	LensesTwoSurfaces getT_LB1723A();
	LensesTwoSurfaces getT_LB1309A();
	LensesTwoSurfaces getT_LB1630A();
	LensesTwoSurfaces getT_LB1106A();
	LensesTwoSurfaces getT_LB1374A();
	LensesTwoSurfaces getT_LB1607A();
	LensesTwoSurfaces getT_LB1199A();
	LensesTwoSurfaces getT_LB1889A();
	LensesTwoSurfaces getT_LB1917A();
	LensesTwoSurfaces getT_LB1862A();
	LensesTwoSurfaces getT_LB1909A();
	LensesTwoSurfaces getT_LB1247A();
	LensesTwoSurfaces getT_LB1859A();

	// *** N-BK7 Plano-Concave Lenses, AR Coating 350 - 700 nm
	//	https://www.thorlabs.de/newgrouppage9.cfm?objectgroup_id=6509
	LensesTwoSurfaces getT_LC1975A();
	LensesTwoSurfaces getT_LC1906A();
	LensesTwoSurfaces getT_LC1054A();
	LensesTwoSurfaces getT_LC1060A();
	LensesTwoSurfaces getT_LC1439A();
	LensesTwoSurfaces getT_LC1259A();
	LensesTwoSurfaces getT_LC1258A();
	LensesTwoSurfaces getT_LC1254A();
	LensesTwoSurfaces getT_LC1715A();
	LensesTwoSurfaces getT_LC1582A();
	LensesTwoSurfaces getT_LC1120A();
	LensesTwoSurfaces getT_LC1315A();
	LensesTwoSurfaces getT_LC1093A();
	LensesTwoSurfaces getT_LC1611A();

	// *** N-BK7 and N-SF11 Bi-Concave Lenses, AR Coating 350 - 700 nm
	// https://www.thorlabs.de/newgrouppage9.cfm?objectgroup_id=9733
	LensesTwoSurfaces getT_LD2746A();
	LensesTwoSurfaces getT_LD2568A();
	LensesTwoSurfaces getT_LD1357A();
	LensesTwoSurfaces getT_LD2060A();
	LensesTwoSurfaces getT_LD2297A();
	LensesTwoSurfaces getT_LD1464A();
	LensesTwoSurfaces getT_LD1170A();
	LensesTwoSurfaces getT_LD1613A();

	// *** Ø1" N-BK7 Best Form Spherical Lenses, AR Coating: 350-700 nm
	// https://www.thorlabs.de/newgrouppage9.cfm?objectgroup_id=4874
	LensesTwoSurfaces getT_LBF254040A();
	LensesTwoSurfaces getT_LBF254050A();
	LensesTwoSurfaces getT_LBF254075A();
	LensesTwoSurfaces getT_LBF254100A();
	LensesTwoSurfaces getT_LBF254150A();
	LensesTwoSurfaces getT_LBF254200A();

	// *** N-BK7 Positive Meniscus Lenses Uncoated
	// https://www.thorlabs.de/newgrouppage9.cfm?objectgroup_id=130
	LensesTwoSurfaces getT_LE1234();
	LensesTwoSurfaces getT_LE1234A();
	LensesTwoSurfaces getT_LE1234B();
	LensesTwoSurfaces getT_LE1234C();
	LensesTwoSurfaces getT_LE1156();
	LensesTwoSurfaces getT_LE1156A();
	LensesTwoSurfaces getT_LE1156B();
	LensesTwoSurfaces getT_LE1156C();
	LensesTwoSurfaces getT_LE1104();
	LensesTwoSurfaces getT_LE1104A();
	LensesTwoSurfaces getT_LE1104B();
	LensesTwoSurfaces getT_LE1104C();
	LensesTwoSurfaces getT_LE1202();
	LensesTwoSurfaces getT_LE1202A();
	LensesTwoSurfaces getT_LE1202B();
	LensesTwoSurfaces getT_LE1202C();
	LensesTwoSurfaces getT_LE1929();
	LensesTwoSurfaces getT_LE1929A();
	LensesTwoSurfaces getT_LE1929B();
	LensesTwoSurfaces getT_LE1929C();
	LensesTwoSurfaces getT_LE1076();
	LensesTwoSurfaces getT_LE1076A();
	LensesTwoSurfaces getT_LE1076B();
	LensesTwoSurfaces getT_LE1076C();
	LensesTwoSurfaces getT_LE1418();
	LensesTwoSurfaces getT_LE1418A();
	LensesTwoSurfaces getT_LE1418B();
	LensesTwoSurfaces getT_LE1418C();
	LensesTwoSurfaces getT_LE1015();
	LensesTwoSurfaces getT_LE1015A();
	LensesTwoSurfaces getT_LE1015B();
	LensesTwoSurfaces getT_LE1015C();
	LensesTwoSurfaces getT_LE1613();
	LensesTwoSurfaces getT_LE1613A();
	LensesTwoSurfaces getT_LE1613B();
	LensesTwoSurfaces getT_LE1613C();
	LensesTwoSurfaces getT_LE1985();
	LensesTwoSurfaces getT_LE1985A();
	LensesTwoSurfaces getT_LE1985B();
	LensesTwoSurfaces getT_LE1985C();

	// *** Ø1" N-BK7 Negative Meniscus Lenses Uncoated
	// https://www.thorlabs.de/newgrouppage9.cfm?objectgroup_id=902
	LensesTwoSurfaces getT_LF1822();
	LensesTwoSurfaces getT_LF1547();
	LensesTwoSurfaces getT_LF1097();
	LensesTwoSurfaces getT_LF1015();
	LensesTwoSurfaces getT_LF1544();
	LensesTwoSurfaces getT_LF1988();
	LensesTwoSurfaces getT_LF1141();

	LensesTwoSurfaces getT_LF1822A();
	LensesTwoSurfaces getT_LF1547A();
	LensesTwoSurfaces getT_LF1097A();
	LensesTwoSurfaces getT_LF1015A();
	LensesTwoSurfaces getT_LF1544A();
	LensesTwoSurfaces getT_LF1988A();
	LensesTwoSurfaces getT_LF1141A();

	LensesTwoSurfaces getT_LF1822B();
	LensesTwoSurfaces getT_LF1547B();
	LensesTwoSurfaces getT_LF1097B();
	LensesTwoSurfaces getT_LF1015B();
	LensesTwoSurfaces getT_LF1544B();
	LensesTwoSurfaces getT_LF1988B();
	LensesTwoSurfaces getT_LF1141B();

	LensesTwoSurfaces getT_LF1822C();
	LensesTwoSurfaces getT_LF1547C();
	LensesTwoSurfaces getT_LF1097C();
	LensesTwoSurfaces getT_LF1015C();
	LensesTwoSurfaces getT_LF1544C();
	LensesTwoSurfaces getT_LF1988C();
	LensesTwoSurfaces getT_LF1141C();

	// Steinheil Triplet Achromatic Lenses, Visible
	// https://www.thorlabs.de/newgrouppage9.cfm?objectgroup_id=5370
	LensFourSurfaces getT_TRS064010A();
	LensFourSurfaces getT_TRS127020A();
	LensFourSurfaces getT_TRS254040A();

	LensFourSurfaces getT_TRS127020AML();
	LensFourSurfaces getT_TRS254040AML();

	// Hastings Triplet Achromatic Lenses, Visible
	// https://www.thorlabs.de/newgrouppage9.cfm?objectgroup_id=5368
	LensFourSurfaces getT_TRH064010A();
	LensFourSurfaces getT_TRH127020A();
	LensFourSurfaces getT_TRH254020A();

	LensFourSurfaces getT_TRH127020AML();
	LensFourSurfaces getT_TRH254020AML();


private:

	// https://www.thorlabs.com/newgrouppage9.cfm?objectgroup_id=12767
	// Achromativ lenses
	LensThreeSurfaces mT_AC127019AB{};
	LensThreeSurfaces mT_AC127025AB{};
	LensThreeSurfaces mT_AC127030AB{};
	LensThreeSurfaces mT_AC127050AB{};
	LensThreeSurfaces mT_AC127075AB{};
	//LensThreeSurfaces mT_AC254030AB{};
	LensThreeSurfaces mT_AC254050AB{};
	LensThreeSurfaces mT_AC254075AB{};
	LensThreeSurfaces mT_AC254100AB{};
	LensThreeSurfaces mT_AC254150AB{};
	LensThreeSurfaces mT_AC254200AB{};
	LensThreeSurfaces mT_AC508080AB{};
	LensThreeSurfaces mT_AC508180AB{};
	LensThreeSurfaces mT_AC508300AB{};
	LensThreeSurfaces mT_AC508400AB{};
	LensThreeSurfaces mT_AC508500AB{};
	LensThreeSurfaces mT_AC508600AB{};


	//  N BK7 Plano Convex Lenses AR Coating 400 1100 nm
	// https://www.thorlabs.de/newgrouppage9.cfm?objectgroup_id=13685
	LensesTwoSurfaces mT_LA1540AB{};
	LensesTwoSurfaces mT_LA1074AB{};
	LensesTwoSurfaces mT_LA1560AB{};
	LensesTwoSurfaces mT_LA1289AB{};
	LensesTwoSurfaces mT_LA1304AB{};
	LensesTwoSurfaces mT_LA1213AB{};
	LensesTwoSurfaces mT_LA1207AB{};
	LensesTwoSurfaces mT_LA1951AB{};
	LensesTwoSurfaces mT_LA1805AB{};
	LensesTwoSurfaces mT_LA1027AB{};
	LensesTwoSurfaces mT_LA1422AB{};
	LensesTwoSurfaces mT_LA1131AB{};
	LensesTwoSurfaces mT_LA1134AB{};
	LensesTwoSurfaces mT_LA1608AB{};
	LensesTwoSurfaces mT_LA1986AB{};
	LensesTwoSurfaces mT_LA1433AB{};
	LensesTwoSurfaces mT_LA1229AB{};
	LensesTwoSurfaces mT_LA1708AB{};
	LensesTwoSurfaces mT_LA1461AB{};
	LensesTwoSurfaces mT_LA1484AB{};
	LensesTwoSurfaces mT_LA1172AB{};
	LensesTwoSurfaces mT_LA1908AB{};
	LensesTwoSurfaces mT_LA1978AB{};
	LensesTwoSurfaces mT_LA1464AB{};
	LensesTwoSurfaces mT_LA1254AB{};
	LensesTwoSurfaces mT_LA1258AB{};
	LensesTwoSurfaces mT_LA1259AB{};
	LensesTwoSurfaces mT_LA1401AB{};
	LensesTwoSurfaces mT_LA1145AB{};
	LensesTwoSurfaces mT_LA1050AB{};
	LensesTwoSurfaces mT_LA1384AB{};
	LensesTwoSurfaces mT_LA1417AB{};
	LensesTwoSurfaces mT_LA1399AB{};
	LensesTwoSurfaces mT_LA1979AB{};
	LensesTwoSurfaces mT_LA1301AB{};
	LensesTwoSurfaces mT_LA1256AB{};
	LensesTwoSurfaces mT_LA1725AB{};
	LensesTwoSurfaces mT_LA1380AB{};
	LensesTwoSurfaces mT_LA1727AB{};
	LensesTwoSurfaces mT_LA1779AB{};


	// *** N BK7 Bi-Convex Lenses AR Coating: 350 - 700 nm
	// https://www.thorlabs.de/newgrouppage9.cfm?objectgroup_id=4848
	LensesTwoSurfaces mT_LB1157A{};
	LensesTwoSurfaces mT_LB1406A{};
	LensesTwoSurfaces mT_LB1494A{};
	LensesTwoSurfaces mT_LB1212A{};
	LensesTwoSurfaces mT_LB1092A{};
	LensesTwoSurfaces mT_LB1450A{};
	LensesTwoSurfaces mT_LB1014A{};
	LensesTwoSurfaces mT_LB1258A{};
	LensesTwoSurfaces mT_LB1378A{};
	LensesTwoSurfaces mT_LB1844A{};
	LensesTwoSurfaces mT_LB1187A{};
	LensesTwoSurfaces mT_LB1761A{};
	LensesTwoSurfaces mT_LB1757A{};
	LensesTwoSurfaces mT_LB1811A{};
	LensesTwoSurfaces mT_LB1027A{};
	LensesTwoSurfaces mT_LB1471A{};
	LensesTwoSurfaces mT_LB1596A{};
	LensesTwoSurfaces mT_LB1901A{};
	LensesTwoSurfaces mT_LB1676A{};
	LensesTwoSurfaces mT_LB1904A{};
	LensesTwoSurfaces mT_LB1437A{};
	LensesTwoSurfaces mT_LB1294A{};
	LensesTwoSurfaces mT_LB1945A{};
	LensesTwoSurfaces mT_LB1056A{};
	LensesTwoSurfaces mT_LB1779A{};
	LensesTwoSurfaces mT_LB1391A{};
	LensesTwoSurfaces mT_LB1869A{};
	LensesTwoSurfaces mT_LB1475A{};
	LensesTwoSurfaces mT_LB1409A{};
	LensesTwoSurfaces mT_LB1723A{};
	LensesTwoSurfaces mT_LB1309A{};
	LensesTwoSurfaces mT_LB1630A{};
	LensesTwoSurfaces mT_LB1106A{};
	LensesTwoSurfaces mT_LB1374A{};
	LensesTwoSurfaces mT_LB1607A{};
	LensesTwoSurfaces mT_LB1199A{};
	LensesTwoSurfaces mT_LB1889A{};
	LensesTwoSurfaces mT_LB1917A{};
	LensesTwoSurfaces mT_LB1862A{};
	LensesTwoSurfaces mT_LB1909A{};
	LensesTwoSurfaces mT_LB1247A{};
	LensesTwoSurfaces mT_LB1859A{};



	// *** N-BK7 Plano-Concave Lenses, AR Coating 350 - 700 nm
	//	https://www.thorlabs.de/newgrouppage9.cfm?objectgroup_id=6509
	LensesTwoSurfaces mT_LC1975A{};
	LensesTwoSurfaces mT_LC1906A{};
	LensesTwoSurfaces mT_LC1054A{};
	LensesTwoSurfaces mT_LC1060A{};
	LensesTwoSurfaces mT_LC1439A{};
	LensesTwoSurfaces mT_LC1259A{};
	LensesTwoSurfaces mT_LC1258A{};
	LensesTwoSurfaces mT_LC1254A{};
	LensesTwoSurfaces mT_LC1715A{};
	LensesTwoSurfaces mT_LC1582A{};
	LensesTwoSurfaces mT_LC1120A{};
	LensesTwoSurfaces mT_LC1315A{};
	LensesTwoSurfaces mT_LC1093A{};
	LensesTwoSurfaces mT_LC1611A{};


	// *** N-BK7 and N-SF11 Bi-Concave Lenses, AR Coating 350 - 700 nm
	// https://www.thorlabs.de/newgrouppage9.cfm?objectgroup_id=9733
	LensesTwoSurfaces mT_LD2746A{};
	LensesTwoSurfaces mT_LD2568A{};
	LensesTwoSurfaces mT_LD1357A{};
	LensesTwoSurfaces mT_LD2060A{};
	LensesTwoSurfaces mT_LD2297A{};
	LensesTwoSurfaces mT_LD1464A{};
	LensesTwoSurfaces mT_LD1170A{};
	LensesTwoSurfaces mT_LD1613A{};

	// *** Ø1" N-BK7 Best Form Spherical Lenses, AR Coating: 350-700 nm
	// https://www.thorlabs.de/newgrouppage9.cfm?objectgroup_id=4874
	LensesTwoSurfaces mT_LBF254040A{};
	LensesTwoSurfaces mT_LBF254050A{};
	LensesTwoSurfaces mT_LBF254075A{};
	LensesTwoSurfaces mT_LBF254100A{};
	LensesTwoSurfaces mT_LBF254150A{};
	LensesTwoSurfaces mT_LBF254200A{};

	// *** N-BK7 Positive Meniscus Lenses Uncoated
	// https://www.thorlabs.de/newgrouppage9.cfm?objectgroup_id=130
	LensesTwoSurfaces mT_LE1234{};
	LensesTwoSurfaces mT_LE1234A{};
	LensesTwoSurfaces mT_LE1234B{};
	LensesTwoSurfaces mT_LE1234C{};
	LensesTwoSurfaces mT_LE1156{};
	LensesTwoSurfaces mT_LE1156A{};
	LensesTwoSurfaces mT_LE1156B{};
	LensesTwoSurfaces mT_LE1156C{};
	LensesTwoSurfaces mT_LE1104{};
	LensesTwoSurfaces mT_LE1104A{};
	LensesTwoSurfaces mT_LE1104B{};
	LensesTwoSurfaces mT_LE1104C{};
	LensesTwoSurfaces mT_LE1202{};
	LensesTwoSurfaces mT_LE1202A{};
	LensesTwoSurfaces mT_LE1202B{};
	LensesTwoSurfaces mT_LE1202C{};
	LensesTwoSurfaces mT_LE1929{};
	LensesTwoSurfaces mT_LE1929A{};
	LensesTwoSurfaces mT_LE1929B{};
	LensesTwoSurfaces mT_LE1929C{};
	LensesTwoSurfaces mT_LE1076{};
	LensesTwoSurfaces mT_LE1076A{};
	LensesTwoSurfaces mT_LE1076B{};
	LensesTwoSurfaces mT_LE1076C{};
	LensesTwoSurfaces mT_LE1418{};
	LensesTwoSurfaces mT_LE1418A{};
	LensesTwoSurfaces mT_LE1418B{};
	LensesTwoSurfaces mT_LE1418C{};
	LensesTwoSurfaces mT_LE1015{};
	LensesTwoSurfaces mT_LE1015A{};
	LensesTwoSurfaces mT_LE1015B{};
	LensesTwoSurfaces mT_LE1015C{};
	LensesTwoSurfaces mT_LE1613{};
	LensesTwoSurfaces mT_LE1613A{};
	LensesTwoSurfaces mT_LE1613B{};
	LensesTwoSurfaces mT_LE1613C{};
	LensesTwoSurfaces mT_LE1985{};
	LensesTwoSurfaces mT_LE1985A{};
	LensesTwoSurfaces mT_LE1985B{};
	LensesTwoSurfaces mT_LE1985C{};

	// *** N-BK7 Positive Meniscus Lenses Uncoated
	// https://www.thorlabs.de/newgrouppage9.cfm?objectgroup_id=902
	LensesTwoSurfaces mT_LF1822{};
	LensesTwoSurfaces mT_LF1547{};
	LensesTwoSurfaces mT_LF1097{};
	LensesTwoSurfaces mT_LF1015{};
	LensesTwoSurfaces mT_LF1544{};
	LensesTwoSurfaces mT_LF1988{};
	LensesTwoSurfaces mT_LF1141{};

	LensesTwoSurfaces mT_LF1822A{};
	LensesTwoSurfaces mT_LF1547A{};
	LensesTwoSurfaces mT_LF1097A{};
	LensesTwoSurfaces mT_LF1015A{};
	LensesTwoSurfaces mT_LF1544A{};
	LensesTwoSurfaces mT_LF1988A{};
	LensesTwoSurfaces mT_LF1141A{};

	LensesTwoSurfaces mT_LF1822B{};
	LensesTwoSurfaces mT_LF1547B{};
	LensesTwoSurfaces mT_LF1097B{};
	LensesTwoSurfaces mT_LF1015B{};
	LensesTwoSurfaces mT_LF1544B{};
	LensesTwoSurfaces mT_LF1988B{};
	LensesTwoSurfaces mT_LF1141B{};

	LensesTwoSurfaces mT_LF1822C{};
	LensesTwoSurfaces mT_LF1547C{};
	LensesTwoSurfaces mT_LF1097C{};
	LensesTwoSurfaces mT_LF1015C{};
	LensesTwoSurfaces mT_LF1544C{};
	LensesTwoSurfaces mT_LF1988C{};
	LensesTwoSurfaces mT_LF1141C{};


	// Steinheil Triplet Achromatic Lenses, Visible
	// https://www.thorlabs.de/newgrouppage9.cfm?objectgroup_id=5370
	LensFourSurfaces mT_TRS064010A{};
	LensFourSurfaces mT_TRS127020A{};
	LensFourSurfaces mT_TRS254040A{};

	LensFourSurfaces mT_TRS127020AML{};
	LensFourSurfaces mT_TRS254040AML{};

	// *** Hastings Triplet Achromatic Lenses, Visible
	// https://www.thorlabs.de/newgrouppage9.cfm?objectgroup_id=5368
	LensFourSurfaces mT_TRH064010A{};
	LensFourSurfaces mT_TRH127020A{};
	LensFourSurfaces mT_TRH254040A{};

	LensFourSurfaces mT_TRH127020AML{};
	LensFourSurfaces mT_TRH254040AML{};
};
