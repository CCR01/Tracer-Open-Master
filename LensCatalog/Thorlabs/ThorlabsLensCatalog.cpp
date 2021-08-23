#include "ThorllabsLensCatalog.h"

ThorlabsLensCatalog::ThorlabsLensCatalog() {}
ThorlabsLensCatalog::~ThorlabsLensCatalog() {}

// load the lens catalog from Thorlabs

// *** Achromativ Doublets AR_Coated lenses
void ThorlabsLensCatalog::loadLensCatalogThorlabs_Achromativ_Doublets_AR_Coated_lenses() // https://www.thorlabs.com/newgrouppage9.cfm?objectgroup_id=12767
{
	glass glasses;
	glasses.loadGlassCatalog_Schott();

	mT_AC127019AB.buildLensThreeSurfaces(/*lens catalog*/ "Thorlabs", /*catalog number*/ "AC127-019-AB", /*diameter*/ 12.7, /* focallength*/ 19.0, /*back focal length*/ 16.29,
		/*radius first surface*/ 14.28778757, /*radius second surface*/ -13.7623555,  /*radius third surface*/ -68.5159061, /*first thickness*/ 4.0,
		/*second thickness*/ 0.999802414, /*edge thickness*/ 3.2, /*material first*/ glasses.getNLAK10_S1(), /*material second*/ glasses.getNSF57_S1(), /*price*/ 74.90,
		/*first design wavelength*/ 488.0, /*second design wavelength*/ 707.0, /*third design wavelength*/ 1064, /*free aperture CA*/ 11.43,
		/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*centration*/ 3.0,	/*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.1,
		/*tolerance center thickness*/ 0.2, /*coating*/ "BBAR", /*min wavelength*/ 400.0,  /*max wavelength*/ 1100);

	mT_AC127025AB.buildLensThreeSurfaces(/*lens catalog*/ "Thorlabs", /*catalog number*/ "AC127-025-AB", /*diameter*/ 12.7, /* focallength*/ 25.0, /*back focal length*/ 21.89,
		/*radius first surface*/ 19.11919830, /*radius second surface*/ -17.8215611,  /*radius third surface*/ -82.3211287, /*first thickness*/ 4.000100906,
		/*second thickness*/ 2.0, /*edge thickness*/ 4.6, /*material first*/ glasses.getNLAK10_S1(), /*material second*/ glasses.getNSF57_S1(), /*price*/ 74.90,
		/*first design wavelength*/ 488.0, /*second design wavelength*/ 707.0, /*third design wavelength*/ 1064, /*free aperture CA*/ 11.43,
		/*max surface quality*/ 40.0,  /*min surface quality*/ 20.0, /*centration*/ 3.0, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.1,
		/*tolerance center thickness*/ 0.2, /*coating*/ "BBAR", /*min wavelength*/ 400.0,  /*max wavelength*/ 1100);

	mT_AC127030AB.buildLensThreeSurfaces(/*lens catalog*/ "Thorlabs", /*catalog number*/ "AC127-030-AB", /*diameter*/ 12.7, /* focallength*/ 30.0, /*back focal length*/ 27.16,
		/*radius first surface*/ 16.749, /*radius second surface*/ -13.823,  /*radius third surface*/ -52.14, /*first thickness*/ 4.000053,
		/*second thickness*/ 1.0, /*edge thickness*/ 3.3, /*material first*/ glasses.getNBK7_S1(), /*material second*/ glasses.getNSF2_S1(), /*price*/ 74.90,
		/*first design wavelength*/ 488.0, /*second design wavelength*/ 707.0, /*third design wavelength*/ 1064, /*free aperture CA*/ 11.43,	/*max surface quality*/ 40.0,  /*min surface quality*/ 20.0, /*centration*/ 3.0,
		/*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.2, /*coating*/ "BBAR", /*min wavelength*/ 400.0,  /*max wavelength*/ 1100);

	mT_AC127050AB.buildLensThreeSurfaces(/*lens catalog*/ "Thorlabs", /*catalog number*/ "AC127-050-AB", /*diameter*/ 12.7, /* focallength*/ 50.0, /*back focal length*/ 46.56,
		/*radius first surface*/ 26.334904, /*radius second surface*/ -22.638651,  /*radius third surface*/ -102.438579, /*first thickness*/ 4.0,
		/*second thickness*/ 2.0, /*edge thickness*/ 5.0, /*material first*/ glasses.getNBK7_S1(), /*material second*/ glasses.getNSF2_S1(), /*price*/ 74.90,
		/*first design wavelength*/ 488.0, /*second design wavelength*/ 707.0, /*third design wavelength*/ 1064, /*free aperture CA*/ 11.43,
		/*max surface quality*/ 40.0,  /*min surface quality*/ 20.0, /*centration*/ 3.0, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.1,
		/*tolerance center thickness*/ 0.2, /*coating*/ "BBAR", /*min wavelength*/ 400.0,  /*max wavelength*/ 1100);

	mT_AC127075AB.buildLensThreeSurfaces(/*lens catalog*/ "Thorlabs", /*catalog number*/ "AC127-075-AB", /*diameter*/ 12.7, /* focallength*/ 75.0, /*back focal length*/ 72.67,
		/*radius first surface*/ 38.364265, /*radius second surface*/ -34.962059,  /*radius third surface*/ -177.900072, /*first thickness*/ 2.5,
		/*second thickness*/ 1.5, /*edge thickness*/ 3.3, /*material first*/ glasses.getNBK7_S1(), /*material second*/ glasses.getNSF2_S1(), /*price*/ 74.90,
		/*first design wavelength*/ 488.0, /*second design wavelength*/ 707.0, /*third design wavelength*/ 1064, /*free aperture CA*/ 11.43,
		/*max surface quality*/ 40.0,  /*min surface quality*/ 20.0, /*centration*/ 3.0, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.1,
		/*tolerance center thickness*/ 0.2, /*coating*/ "BBAR", /*min wavelength*/ 400.0,  /*max wavelength*/ 1100);

	//mT_AC254030AB.buildLensThreeSurfaces(/*lens catalog*/ "Thorlabs", /*catalog number*/ "AC254-030-AB", /*diameter*/ 25.4, /* focallength*/ 30.0, /*back focal length*/ 21.22,
	//	/*radius first surface*/ 20.027309, /*radius second surface*/ -17.440017,  /*radius third surface*/ -93.081768, /*first thickness*/ 12.0,
	//	/*second thickness*/ 3.0, /*edge thickness*/ 9.5, /*material first*/ glasses.getNSBAH11_S1(), /*material second*/ glasses.getNSTIH6_S1(), /*price*/ 93.63,
	//	/*first design wavelength*/ 488.0, /*second design wavelength*/ 707.0, /*third design wavelength*/ 1064, /*free aperture CA*/ 22.86,
	//	/*max surface quality*/ 40.0,  /*min surface quality*/ 20.0, /*centration*/ 3.0, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.1,
	//	/*tolerance center thickness*/ 0.2, /*coating*/ "BBAR", /*min wavelength*/ 400.0,  /*max wavelength*/ 1100);

	mT_AC254050AB.buildLensThreeSurfaces(/*lens catalog*/ "Thorlabs", /*catalog number*/ "AC254-050-AB", /*diameter*/ 25.4, /* focallength*/ 50.0, /*back focal length*/ 43.39,
		/*radius first surface*/ 34.929986, /*radius second surface*/ -28.765973,  /*radius third surface*/ -137.534571, /*first thickness*/ 9.0,
		/*second thickness*/ 3.5, /*edge thickness*/ 9.5, /*material first*/ glasses.getNBAF10_S1(), /*material second*/ glasses.getNSF6_S1(), /*price*/ 93.63,
		/*first design wavelength*/ 488.0, /*second design wavelength*/ 707.0, /*third design wavelength*/ 1064, /*free aperture CA*/ 22.86,
		/*max surface quality*/ 40.0,  /*min surface quality*/ 20.0, /*centration*/ 3.0, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.1,
		/*tolerance center thickness*/ 0.2, /*coating*/ "BBAR", /*min wavelength*/ 400.0,  /*max wavelength*/ 1100);

	mT_AC254075AB.buildLensThreeSurfaces(/*lens catalog*/ "Thorlabs", /*catalog number*/ "AC254-075-AB", /*diameter*/ 25.4, /* focallength*/ 75.0, /*back focal length*/ 68.72,
		/*radius first surface*/ 51.982628, /*radius second surface*/ -43.363376,  /*radius third surface*/ -217.362305, /*first thickness*/ 8.0,
		/*second thickness*/ 4.0, /*edge thickness*/ 10.0, /*material first*/ glasses.getNBAF10_S1(), /*material second*/ glasses.getNSF6_S1(), /*price*/ 93.63,
		/*first design wavelength*/ 488.0, /*second design wavelength*/ 707.0, /*third design wavelength*/ 1064, /*free aperture CA*/ 22.86,
		/*max surface quality*/ 40.0,  /*min surface quality*/ 20.0, /*centration*/ 3.0, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.1,
		/*tolerance center thickness*/ 0.2, /*coating*/ "BBAR", /*min wavelength*/ 400.0,  /*max wavelength*/ 1100);

	mT_AC254100AB.buildLensThreeSurfaces(/*lens catalog*/ "Thorlabs", /*catalog number*/ "AC254-100-AB", /*diameter*/ 25.4, /* focallength*/ 100.0, /*back focal length*/ 95.03,
		/*radius first surface*/ 92.397332, /*radius second surface*/ -48.176552,  /*radius third surface*/ -152.819346, /*first thickness*/ 8.0,
		/*second thickness*/ 4.0, /*edge thickness*/ 10.5, /*material first*/ glasses.getNLAK22_S1(), /*material second*/ glasses.getNSF10_S1(), /*price*/ 93.63,
		/*first design wavelength*/ 488.0, /*second design wavelength*/ 707.0, /*third design wavelength*/ 1064, /*free aperture CA*/ 22.86,
		/*max surface quality*/ 40.0,  /*min surface quality*/ 20.0, /*centration*/ 3.0, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.1,
		/*tolerance center thickness*/ 0.2, /*coating*/ "BBAR", /*min wavelength*/ 400.0,  /*max wavelength*/ 1100);

	mT_AC254150AB.buildLensThreeSurfaces(/*lens catalog*/ "Thorlabs", /*catalog number*/ "AC254-150-AB", /*diameter*/ 25.4, /* focallength*/ 150.0, /*back focal length*/ 143.68,
		/*radius first surface*/ 87.860963, /*radius second surface*/ -105.644377,  /*radius third surface*/ 9999999999999999999.99, /*first thickness*/ 6.000001,
		/*second thickness*/ 3.0, /*edge thickness*/ 8.0, /*material first*/ glasses.getNLAK22_S1(), /*material second*/ glasses.getNSF10_S1(), /*price*/ 93.63,
		/*first design wavelength*/ 488.0, /*second design wavelength*/ 707.0, /*third design wavelength*/ 1064, /*free aperture CA*/ 22.86,
		/*max surface quality*/ 40.0,  /*min surface quality*/ 20.0, /*centration*/ 3.0, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.1,
		/*tolerance center thickness*/ 0.2, /*coating*/ "BBAR", /*min wavelength*/ 400.0,  /*max wavelength*/ 1100);

	mT_AC254200AB.buildLensThreeSurfaces(/*lens catalog*/ "Thorlabs", /*catalog number*/ "AC254-200-AB", /*diameter*/ 25.4, /* focallength*/ 200.0, /*back focal length*/ 194.15,
		/*radius first surface*/ 117.123549, /*radius second surface*/ -142.118057,  /*radius third surface*/ 9999999999999999999.99, /*first thickness*/ 5.0,
		/*second thickness*/ 3.0, /*edge thickness*/ 7.3, /*material first*/ glasses.getNLAK22_S1(), /*material second*/ glasses.getNSF10_S1(), /*price*/ 93.63,
		/*first design wavelength*/ 488.0, /*second design wavelength*/ 707.0, /*third design wavelength*/ 1064, /*free aperture CA*/ 22.86,
		/*max surface quality*/ 40.0,  /*min surface quality*/ 20.0, /*centration*/ 3.0, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.1,
		/*tolerance center thickness*/ 0.2, /*coating*/ "BBAR", /*min wavelength*/ 400.0,  /*max wavelength*/ 1100);

	mT_AC508080AB.buildLensThreeSurfaces(/*lens catalog*/ "Thorlabs", /*catalog number*/ "AC508-080-AB", /*diameter*/ 50.8, /* focallength*/ 80.0, /*back focal length*/ 72.73,
		/*radius first surface*/ 63.621029, /*radius second surface*/ -80.621465,  /*radius third surface*/ -181.701828, /*first thickness*/ 12.0,
		/*second thickness*/ 3.0, /*edge thickness*/ 10.2, /*material first*/ glasses.getNLAK22_S1(), /*material second*/ glasses.getNSF6_S1(), /*price*/ 140.44,
		/*first design wavelength*/ 488.0, /*second design wavelength*/ 707.0, /*third design wavelength*/ 1064, /*free aperture CA*/ 45.72,
		/*max surface quality*/ 40.0,  /*min surface quality*/ 20.0, /*centration*/ 3.0, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.1,
		/*tolerance center thickness*/ 0.2, /*coating*/ "BBAR", /*min wavelength*/ 400.0,  /*max wavelength*/ 1100);

	mT_AC508180AB.buildLensThreeSurfaces(/*lens catalog*/ "Thorlabs", /*catalog number*/ "AC508-180-AB", /*diameter*/ 50.8, /* focallength*/ 180.0, /*back focal length*/ 173.52,
		/*radius first surface*/ 144.444419, /*radius second surface*/ -115.428068,  /*radius third surface*/ -328.201132, /*first thickness*/ 9.5,
		/*second thickness*/ 4.0, /*edge thickness*/ 7.8, /*material first*/ glasses.getNLAK22_S1(), /*material second*/ glasses.getNSF6_S1(), /*price*/ 140.44,
		/*first design wavelength*/ 488.0, /*second design wavelength*/ 707.0, /*third design wavelength*/ 1064, /*free aperture CA*/ 45.72,
		/*max surface quality*/ 40.0,  /*min surface quality*/ 20.0, /*centration*/ 3.0, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.1,
		/*tolerance center thickness*/ 0.2, /*coating*/ "BBAR", /*min wavelength*/ 400.0,  /*max wavelength*/ 1100);

	mT_AC508300AB.buildLensThreeSurfaces(/*lens catalog*/ "Thorlabs", /*catalog number*/ "AC508-300-AB", /*diameter*/ 50.8, /* focallength*/ 300.0, /*back focal length*/ 289.81,
		/*radius first surface*/ 167.715317, /*radius second surface*/ -285.815330,  /*radius third surface*/ 999999999999999999.99, /*first thickness*/ 9.0,
		/*second thickness*/ 4.0, /*edge thickness*/ 11.0, /*material first*/ glasses.getNLAK22_S1(), /*material second*/ glasses.getNSF6_S1(), /*price*/ 140.44,
		/*first design wavelength*/ 488.0, /*second design wavelength*/ 707.0, /*third design wavelength*/ 1064, /*free aperture CA*/ 45.72,
		/*max surface quality*/ 40.0,  /*min surface quality*/ 20.0, /*centration*/ 3.0, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.1,
		/*tolerance center thickness*/ 0.2, /*coating*/ "BBAR", /*min wavelength*/ 400.0,  /*max wavelength*/ 1100);

	mT_AC508400AB.buildLensThreeSurfaces(/*lens catalog*/ "Thorlabs", /*catalog number*/ "AC508-400-AB", /*diameter*/ 50.8, /* focallength*/ 400.0, /*back focal length*/ 388.56,
		/*radius first surface*/ 184.251652, /*radius second surface*/ -274.022145,  /*radius third surface*/ 999999999999999999.99, /*first thickness*/ 9.0,
		/*second thickness*/ 4.0, /*edge thickness*/ 11.2, /*material first*/ glasses.getNBAK4_S1(), /*material second*/ glasses.getNSF10_S1(), /*price*/ 140.44,
		/*first design wavelength*/ 488.0, /*second design wavelength*/ 707.0, /*third design wavelength*/ 1064, /*free aperture CA*/ 45.72,
		/*max surface quality*/ 40.0,  /*min surface quality*/ 20.0, /*centration*/ 3.0, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.1,
		/*tolerance center thickness*/ 0.2, /*coating*/ "BBAR", /*min wavelength*/ 400.0,  /*max wavelength*/ 1100);

	mT_AC508500AB.buildLensThreeSurfaces(/*lens catalog*/ "Thorlabs", /*catalog number*/ "AC508-500-AB", /*diameter*/ 50.8, /* focallength*/ 500.0, /*back focal length*/ 488.04,
		/*radius first surface*/ 230.336040, /*radius second surface*/ -343.935141,  /*radius third surface*/ 999999999999999999.99, /*first thickness*/ 9.0,
		/*second thickness*/ 4.0, /*edge thickness*/ 11.5, /*material first*/ glasses.getNBAK4_S1(), /*material second*/ glasses.getNSF10_S1(), /*price*/ 140.44,
		/*first design wavelength*/ 488.0, /*second design wavelength*/ 707.0, /*third design wavelength*/ 1064, /*free aperture CA*/ 45.72,
		/*max surface quality*/ 40.0,  /*min surface quality*/ 20.0, /*centration*/ 3.0, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.1,
		/*tolerance center thickness*/ 0.2, /*coating*/ "BBAR", /*min wavelength*/ 400.0,  /*max wavelength*/ 1100);

	mT_AC508600AB.buildLensThreeSurfaces(/*lens catalog*/ "Thorlabs", /*catalog number*/ "AC508-600-AB", /*diameter*/ 50.8, /* focallength*/ 600.0, /*back focal length*/ 590.52,
		/*radius first surface*/ 276.420837, /*radius second surface*/ -413.852031,  /*radius third surface*/ 999999999999999999.99, /*first thickness*/ 9.0,
		/*second thickness*/ 4.0, /*edge thickness*/ 11.8, /*material first*/ glasses.getNBAK4_S1(), /*material second*/ glasses.getNSF10_S1(), /*price*/ 140.44,
		/*first design wavelength*/ 488.0, /*second design wavelength*/ 707.0, /*third design wavelength*/ 1064, /*free aperture CA*/ 45.72,
		/*max surface quality*/ 40.0,  /*min surface quality*/ 20.0, /*centration*/ 3.0, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.1,
		/*tolerance center thickness*/ 0.2, /*coating*/ "BBAR", /*min wavelength*/ 400.0,  /*max wavelength*/ 1100);

}

std::vector<LensThreeSurfaces> ThorlabsLensCatalog::getAll_Thorlabs_Achromativ_Doublets_AR_Coated_lenses()
{
	// https://www.thorlabs.com/newgrouppage9.cfm?objectgroup_id=12767

	std::vector<LensThreeSurfaces> returnAchromaticDoubletsLenses;

	returnAchromaticDoubletsLenses.push_back(mT_AC127019AB);
	returnAchromaticDoubletsLenses.push_back(mT_AC127025AB);
	returnAchromaticDoubletsLenses.push_back(mT_AC127030AB);
	returnAchromaticDoubletsLenses.push_back(mT_AC127050AB);
	returnAchromaticDoubletsLenses.push_back(mT_AC127075AB);
	//returnAchromaticDoubletsLenses.push_back(mT_AC254030AB);
	returnAchromaticDoubletsLenses.push_back(mT_AC254050AB);
	returnAchromaticDoubletsLenses.push_back(mT_AC254075AB);
	returnAchromaticDoubletsLenses.push_back(mT_AC254100AB);
	returnAchromaticDoubletsLenses.push_back(mT_AC254150AB);
	returnAchromaticDoubletsLenses.push_back(mT_AC254200AB);
	returnAchromaticDoubletsLenses.push_back(mT_AC508080AB);
	returnAchromaticDoubletsLenses.push_back(mT_AC508180AB);
	returnAchromaticDoubletsLenses.push_back(mT_AC508300AB);
	returnAchromaticDoubletsLenses.push_back(mT_AC508400AB);

	return returnAchromaticDoubletsLenses;
}

// *** N BK7 Plano Convex Lenses AR Coating 400 1100 nm
void ThorlabsLensCatalog::loadLensCatalogThorlabs_N_BK7_Plano_Convex_Lenses_AR_Coating_400_1100_nm() // https://www.thorlabs.de/newgrouppage9.cfm?objectgroup_id=13685
{
	glass glasses;
	glasses.loadGlassCatalog_Schott();

	mT_LA1540AB.buildLensTwoSurfaces_Thorlabs_oneSurfacePlan(/*lens catalog*/ "thorlabs", /*catalog number*/ "LA1540-AB", /*diameter*/  12.7,
		/* focallength*/ 15.0, /*back focal length*/ 11.6, /*radius*/ 7.72, /*thickness*/ 5.12, /*edge thickness*/ 1.8, /*material*/ glasses.getNBK7_S1(),
		/*price*/ 31.82, /*design wavelength*/ 587.6, /*free aperture CA*/ 11.4, /*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*centration*/ 3.0,
		/*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1,
		/*coating*/ "BBAR", /*min wavelength*/ 400.0, /*max wavelength*/ 1100.0);

	mT_LA1074AB.buildLensTwoSurfaces_Thorlabs_oneSurfacePlan(/*lens catalog*/ "thorlabs", /*catalog number*/ "LA1074-AB", /*diameter*/  12.7,
		/* focallength*/ 19.9, /*back focal length*/ 17.3, /*radius*/ 10.3, /*thickness*/ 3.98, /*edge thickness*/ 1.8, /*material*/ glasses.getNBK7_S1(),
		/*price*/ 32.72, /*design wavelength*/ 587.6, /*free aperture CA*/ 11.4, /*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*centration*/ 3.0,
		/*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1,
		/*coating*/ "BBAR",	/*min wavelength*/ 400.0, /*max wavelength*/ 1100.0);

	mT_LA1560AB.buildLensTwoSurfaces_Thorlabs_oneSurfacePlan(/*lens catalog*/ "thorlabs", /*catalog number*/ "LA1560-AB", /*diameter*/  12.7,
		/* focallength*/ 25.0, /*back focal length*/ 22.6, /*radius*/ 12.87, /*thickness*/ 3.47, /*edge thickness*/ 1.8, /*material*/ glasses.getNBK7_S1(),
		/*price*/ 32.72, /*design wavelength*/ 587.6, /*free aperture CA*/ 11.4, /*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*centration*/ 3.0,
		/*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1,
		/*coating*/ "BBAR",	/*min wavelength*/ 400.0, /*max wavelength*/ 1100.0);

	mT_LA1289AB.buildLensTwoSurfaces_Thorlabs_oneSurfacePlan(/*lens catalog*/ "thorlabs", /*catalog number*/ "LA1289-AB", /*diameter*/  12.7,
		/* focallength*/ 29.9, /*back focal length*/ 27.8, /*radius*/ 15.45, /*thickness*/ 3.16, /*edge thickness*/ 1.8, /*material*/ glasses.getNBK7_S1(),
		/*price*/ 31.82, /*design wavelength*/ 587.6, /*free aperture CA*/ 11.4, /*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*centration*/ 3.0,
		/*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1,
		/*coating*/ "BBAR", /*min wavelength*/ 400.0, /*max wavelength*/ 1100.0);

	mT_LA1207AB.buildLensTwoSurfaces_Thorlabs_oneSurfacePlan(/*lens catalog*/ "thorlabs", /*catalog number*/ "LA1207-AB", /*diameter*/  12.7,
		/* focallength*/ 100.0, /*back focal length*/ 98.2, /*radius*/ 51.5, /*thickness*/ 2.19, /*edge thickness*/ 1.8, /*material*/ glasses.getNBK7_S1(),
		/*price*/ 31.82, /*design wavelength*/ 587.6, /*free aperture CA*/ 11.4, /*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*centration*/ 3.0,
		/*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1,
		/*coating*/ "BBAR", /*min wavelength*/ 400.0, /*max wavelength*/ 1100.0);

	mT_LA1951AB.buildLensTwoSurfaces_Thorlabs_oneSurfacePlan(/*lens catalog*/ "thorlabs", /*catalog number*/ "LA1951-AB", /*diameter*/ 25.4,
		/* focallength*/ 25.4, /*back focal length*/ 17.6, /*radius*/ 13.08, /*thickness*/ 11.74, /*edge thickness*/ 1.8, /*material*/ glasses.getNBK7_S1(),
		/*price*/ 36.36, /*design wavelength*/ 587.6, /*free aperture CA*/ 22.9, /*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*centration*/ 3.0,
		/*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1,
		/*coating*/ "BBAR", /*min wavelength*/ 400.0, /*max wavelength*/ 1100.0);

	mT_LA1805AB.buildLensTwoSurfaces_Thorlabs_oneSurfacePlan(/*lens catalog*/ "thorlabs", /*catalog number*/ "LA1805-AB", /*diameter*/ 25.4,
		/* focallength*/ 30.0, /*back focal length*/ 24.2, /*radius*/ 15.45, /*thickness*/ 8.64, /*edge thickness*/ 2.0, /*material*/ glasses.getNBK7_S1(),
		/*price*/ 36.36, /*design wavelength*/ 587.6, /*free aperture CA*/ 22.9, /*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*centration*/ 3.0,
		/*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1,
		/*coating*/ "BBAR", /*min wavelength*/ 400.0, /*max wavelength*/ 1100.0);

	mT_LA1027AB.buildLensTwoSurfaces_Thorlabs_oneSurfacePlan(/*lens catalog*/ "thorlabs", /*catalog number*/ "LA1027-AB", /*diameter*/ 25.4,
		/* focallength*/ 34.9, /*back focal length*/ 30.1, /*radius*/ 18.02, /*thickness*/ 7.23, /*edge thickness*/ 2.0, /*material*/ glasses.getNBK7_S1(),
		/*price*/ 36.36, /*design wavelength*/ 587.6, /*free aperture CA*/ 22.9, /*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*centration*/ 3.0,
		/*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1,
		/*coating*/ "BBAR", /*min wavelength*/ 400.0, /*max wavelength*/ 1100.0);

	mT_LA1422AB.buildLensTwoSurfaces_Thorlabs_oneSurfacePlan(/*lens catalog*/ "thorlabs", /*catalog number*/ "LA1422-AB", /*diameter*/ 25.4,
		/* focallength*/ 39.0, /*back focal length*/ 35.7, /*radius*/ 20.6, /*thickness*/ 6.37, /*edge thickness*/ 2.0, /*material*/ glasses.getNBK7_S1(),
		/*price*/ 39.09, /*design wavelength*/ 587.6, /*free aperture CA*/ 22.9, /*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*centration*/ 3.0,
		/*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1,
		/*coating*/ "BBAR", /*min wavelength*/ 400.0, /*max wavelength*/ 1100.0);

	mT_LA1131AB.buildLensTwoSurfaces_Thorlabs_oneSurfacePlan(/*lens catalog*/ "thorlabs", /*catalog number*/ "LA1131-AB", /*diameter*/ 25.4,
		/* focallength*/ 49.8, /*back focal length*/ 46.3, /*radius*/ 25.75, /*thickness*/ 5.34, /*edge thickness*/ 2.0, /*material*/ glasses.getNBK7_S1(),
		/*price*/ 36.36, /*design wavelength*/ 587.6, /*free aperture CA*/ 22.9, /*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*centration*/ 3.0,
		/*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1,
		/*coating*/ "BBAR", /*min wavelength*/ 400.0, /*max wavelength*/ 1100.0);

	mT_LA1134AB.buildLensTwoSurfaces_Thorlabs_oneSurfacePlan(/*lens catalog*/ "thorlabs", /*catalog number*/ "LA1134-AB", /*diameter*/ 25.4,
		/* focallength*/ 59.8, /*back focal length*/ 56.7, /*radius*/ 30.9, /*thickness*/ 4.73, /*edge thickness*/ 2.0, /*material*/ glasses.getNBK7_S1(),
		/*price*/ 40.00, /*design wavelength*/ 587.6, /*free aperture CA*/ 22.9, /*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*centration*/ 3.0,
		/*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1,
		/*coating*/ "BBAR", /*min wavelength*/ 400.0, /*max wavelength*/ 1100.0);

	mT_LA1608AB.buildLensTwoSurfaces_Thorlabs_oneSurfacePlan(/*lens catalog*/ "thorlabs", /*catalog number*/ "LA1608-AB", /*diameter*/ 25.4,
		/* focallength*/ 75.0, /*back focal length*/ 72.0, /*radius*/ 38.63, /*thickness*/ 4.14, /*edge thickness*/ 2.0, /*material*/ glasses.getNBK7_S1(),
		/*price*/ 36.36, /*design wavelength*/ 587.6, /*free aperture CA*/ 22.9, /*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*centration*/ 3.0,
		/*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1,
		/*coating*/ "BBAR", /*min wavelength*/ 400.0, /*max wavelength*/ 1100.0);

	mT_LA1986AB.buildLensTwoSurfaces_Thorlabs_oneSurfacePlan(/*lens catalog*/ "thorlabs", /*catalog number*/ "LA1986-AB", /*diameter*/ 25.4,
		/* focallength*/ 125.0, /*back focal length*/ 122.4, /*radius*/ 64.38, /*thickness*/ 3.26, /*edge thickness*/ 2.0, /*material*/ glasses.getNBK7_S1(),
		/*price*/ 36.36, /*design wavelength*/ 587.6, /*free aperture CA*/ 22.9, /*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*centration*/ 3.0,
		/*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1,
		/*coating*/ "BBAR", /*min wavelength*/ 400.0, /*max wavelength*/ 1100.0);

	mT_LA1433AB.buildLensTwoSurfaces_Thorlabs_oneSurfacePlan(/*lens catalog*/ "thorlabs", /*catalog number*/ "LA1433-AB", /*diameter*/ 25.4,
		/* focallength*/ 149.5, /*back focal length*/ 147.5, /*radius*/ 77.26, /*thickness*/ 3.05, /*edge thickness*/ 2.0, /*material*/ glasses.getNBK7_S1(),
		/*price*/ 36.36, /*design wavelength*/ 587.6, /*free aperture CA*/ 22.9, /*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*centration*/ 3.0,
		/*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1,
		/*coating*/ "BBAR", /*min wavelength*/ 400.0, /*max wavelength*/ 1100.0);

	mT_LA1229AB.buildLensTwoSurfaces_Thorlabs_oneSurfacePlan(/*lens catalog*/ "thorlabs", /*catalog number*/ "LA1229-AB", /*diameter*/ 25.4,
		/* focallength*/ 174.4, /*back focal length*/ 172.5, /*radius*/ 90.13, /*thickness*/ 2.89, /*edge thickness*/ 2.0, /*material*/ glasses.getNBK7_S1(),
		/*price*/ 36.36, /*design wavelength*/ 587.6, /*free aperture CA*/ 22.9, /*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*centration*/ 3.0,
		/*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1,
		/*coating*/ "BBAR", /*min wavelength*/ 400.0, /*max wavelength*/ 1100.0);

	mT_LA1708AB.buildLensTwoSurfaces_Thorlabs_oneSurfacePlan(/*lens catalog*/ "thorlabs", /*catalog number*/ "LA1708-AB", /*diameter*/ 25.4,
		/* focallength*/ 200.0, /*back focal length*/ 197.5, /*radius*/ 103.01, /*thickness*/ 2.78, /*edge thickness*/ 2.0, /*material*/ glasses.getNBK7_S1(),
		/*price*/ 36.36, /*design wavelength*/ 587.6, /*free aperture CA*/ 22.9, /*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*centration*/ 3.0,
		/*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1,
		/*coating*/ "BBAR", /*min wavelength*/ 400.0, /*max wavelength*/ 1100.0);

	mT_LA1461AB.buildLensTwoSurfaces_Thorlabs_oneSurfacePlan(/*lens catalog*/ "thorlabs", /*catalog number*/ "LA1461-AB", /*diameter*/ 25.4,
		/* focallength*/ 249.2, /*back focal length*/ 247.4, /*radius*/ 128.77, /*thickness*/ 2.62, /*edge thickness*/ 2.0, /*material*/ glasses.getNBK7_S1(),
		/*price*/ 36.36, /*design wavelength*/ 587.6, /*free aperture CA*/ 22.9, /*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*centration*/ 3.0,
		/*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1,
		/*coating*/ "BBAR", /*min wavelength*/ 400.0, /*max wavelength*/ 1100.0);

	mT_LA1484AB.buildLensTwoSurfaces_Thorlabs_oneSurfacePlan(/*lens catalog*/ "thorlabs", /*catalog number*/ "LA1484-AB", /*diameter*/ 25.4,
		/* focallength*/ 300.0, /*back focal length*/ 297.3, /*radius*/ 154.52, /*thickness*/ 2.52, /*edge thickness*/ 2.0, /*material*/ glasses.getNBK7_S1(),
		/*price*/ 36.36, /*design wavelength*/ 587.6, /*free aperture CA*/ 22.9, /*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*centration*/ 3.0,
		/*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1,
		/*coating*/ "BBAR", /*min wavelength*/ 400.0, /*max wavelength*/ 1100.0);

	mT_LA1172AB.buildLensTwoSurfaces_Thorlabs_oneSurfacePlan(/*lens catalog*/ "thorlabs", /*catalog number*/ "LA1172-AB", /*diameter*/ 25.4,
		/* focallength*/ 398.7, /*back focal length*/ 397.1, /*radius*/ 206.03, /*thickness*/ 2.39, /*edge thickness*/ 2.0, /*material*/ glasses.getNBK7_S1(),
		/*price*/ 36.36, /*design wavelength*/ 587.6, /*free aperture CA*/ 22.9, /*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*centration*/ 3.0,
		/*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1,
		/*coating*/ "BBAR", /*min wavelength*/ 400.0, /*max wavelength*/ 1100.0);

	mT_LA1908AB.buildLensTwoSurfaces_Thorlabs_oneSurfacePlan(/*lens catalog*/ "thorlabs", /*catalog number*/ "LA1908-AB", /*diameter*/ 25.4,
		/* focallength*/ 500.0, /*back focal length*/ 496.8, /*radius*/ 257.54, /*thickness*/ 2.31, /*edge thickness*/ 2.0, /*material*/ glasses.getNBK7_S1(),
		/*price*/ 36.36, /*design wavelength*/ 587.6, /*free aperture CA*/ 22.9, /*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*centration*/ 3.0,
		/*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1,
		/*coating*/ "BBAR", /*min wavelength*/ 400.0, /*max wavelength*/ 1100.0);

	mT_LA1978AB.buildLensTwoSurfaces_Thorlabs_oneSurfacePlan(/*lens catalog*/ "thorlabs", /*catalog number*/ "LA1978-AB", /*diameter*/ 25.4,
		/* focallength*/ 750.0, /*back focal length*/ 746.1, /*radius*/ 386.31, /*thickness*/ 2.2, /*edge thickness*/ 2.0, /*material*/ glasses.getNBK7_S1(),
		/*price*/ 36.36, /*design wavelength*/ 587.6, /*free aperture CA*/ 22.9, /*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*centration*/ 3.0,
		/*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1,
		/*coating*/ "BBAR", /*min wavelength*/ 400.0, /*max wavelength*/ 1100.0);

	mT_LA1464AB.buildLensTwoSurfaces_Thorlabs_oneSurfacePlan(/*lens catalog*/ "thorlabs", /*catalog number*/ "LA1464-AB", /*diameter*/ 25.4,
		/* focallength*/ 996.7, /*back focal length*/ 995.3, /*radius*/ 515.08, /*thickness*/ 2.15, /*edge thickness*/ 2.0, /*material*/ glasses.getNBK7_S1(),
		/*price*/ 39.09, /*design wavelength*/ 587.6, /*free aperture CA*/ 22.9, /*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*centration*/ 3.0,
		/*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1,
		/*coating*/ "BBAR", /*min wavelength*/ 400.0, /*max wavelength*/ 1100.0);

	mT_LA1254AB.buildLensTwoSurfaces_Thorlabs_oneSurfacePlan(/*lens catalog*/ "thorlabs", /*catalog number*/ "LA1254-AB", /*diameter*/ 25.4,
		/* focallength*/ 1500.0, /*back focal length*/ 1498.6, /*radius*/ 775.2, /*thickness*/ 2.1, /*edge thickness*/ 2.1, /*material*/ glasses.getNBK7_S1(),
		/*price*/ 36.36, /*design wavelength*/ 587.6, /*free aperture CA*/ 22.9, /*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*centration*/ 3.0,
		/*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1,
		/*coating*/ "BBAR", /*min wavelength*/ 400.0, /*max wavelength*/ 1100.0);

	mT_LA1258AB.buildLensTwoSurfaces_Thorlabs_oneSurfacePlan(/*lens catalog*/ "thorlabs", /*catalog number*/ "LA1258-AB", /*diameter*/ 25.4,
		/* focallength*/ 2000.0, /*back focal length*/ 1998.6, /*radius*/ 1033.6, /*thickness*/ 2.1, /*edge thickness*/ 2.0, /*material*/ glasses.getNBK7_S1(),
		/*price*/ 36.36, /*design wavelength*/ 587.6, /*free aperture CA*/ 22.9, /*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*centration*/ 3.0,
		/*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1,
		/*coating*/ "BBAR", /*min wavelength*/ 400.0, /*max wavelength*/ 1100.0);

	mT_LA1259AB.buildLensTwoSurfaces_Thorlabs_oneSurfacePlan(/*lens catalog*/ "thorlabs", /*catalog number*/ "LA1259-AB", /*diameter*/ 25.4,
		/* focallength*/ 2500.0, /*back focal length*/ 2498.6, /*radius*/ 1292.0, /*thickness*/ 2.1, /*edge thickness*/ 2.1, /*material*/ glasses.getNBK7_S1(),
		/*price*/ 36.36, /*design wavelength*/ 587.6, /*free aperture CA*/ 22.9, /*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*centration*/ 3.0,
		/*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1,
		/*coating*/ "BBAR", /*min wavelength*/ 400.0, /*max wavelength*/ 1100.0);

	mT_LA1401AB.buildLensTwoSurfaces_Thorlabs_oneSurfacePlan(/*lens catalog*/ "thorlabs", /*catalog number*/ "LA1401-AB", /*diameter*/ 50.8,
		/* focallength*/ 59.8, /*back focal length*/ 49.1, /*radius*/ 30.9, /*thickness*/ 16.29, /*edge thickness*/ 3.0, /*material*/ glasses.getNBK7_S1(),
		/*price*/ 50.90, /*design wavelength*/ 587.6, /*free aperture CA*/ 45.77, /*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*centration*/ 3.0,
		/*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1,
		/*coating*/ "BBAR", /*min wavelength*/ 400.0, /*max wavelength*/ 1100.0);

	mT_LA1145AB.buildLensTwoSurfaces_Thorlabs_oneSurfacePlan(/*lens catalog*/ "thorlabs", /*catalog number*/ "LA1145-AB", /*diameter*/ 50.8,
		/* focallength*/ 74.1, /*back focal length*/ 66.5, /*radius*/ 38.63, /*thickness*/ 12.52, /*edge thickness*/ 3.0, /*material*/ glasses.getNBK7_S1(),
		/*price*/ 50.90, /*design wavelength*/ 587.6, /*free aperture CA*/ 45.77, /*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*centration*/ 3.0,
		/*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1,
		/*coating*/ "BBAR", /*min wavelength*/ 400.0, /*max wavelength*/ 1100.0);

	mT_LA1050AB.buildLensTwoSurfaces_Thorlabs_oneSurfacePlan(/*lens catalog*/ "thorlabs", /*catalog number*/ "LA1050-AB", /*diameter*/ 50.8,
		/* focallength*/ 99.7, /*back focal length*/ 93.3, /*radius*/ 51.5, /*thickness*/ 9.69, /*edge thickness*/ 3.0, /*material*/ glasses.getNBK7_S1(),
		/*price*/ 50.90, /*design wavelength*/ 587.6, /*free aperture CA*/ 45.77, /*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*centration*/ 3.0,
		/*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1,
		/*coating*/ "BBAR", /*min wavelength*/ 400.0, /*max wavelength*/ 1100.0);

	mT_LA1384AB.buildLensTwoSurfaces_Thorlabs_oneSurfacePlan(/*lens catalog*/ "thorlabs", /*catalog number*/ "LA1384-AB", /*diameter*/ 50.8,
		/* focallength*/ 124.6, /*back focal length*/ 119.2, /*radius*/ 64.38, /*thickness*/ 8.22, /*edge thickness*/ 3.0, /*material*/ glasses.getNBK7_S1(),
		/*price*/ 50.90, /*design wavelength*/ 587.6, /*free aperture CA*/ 45.77, /*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*centration*/ 3.0,
		/*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1,
		/*coating*/ "BBAR", /*min wavelength*/ 400.0, /*max wavelength*/ 1100.0);

	mT_LA1417AB.buildLensTwoSurfaces_Thorlabs_oneSurfacePlan(/*lens catalog*/ "thorlabs", /*catalog number*/ "LA1417-AB", /*diameter*/ 50.8,
		/* focallength*/ 149.5, /*back focal length*/ 144.7, /*radius*/ 77.26, /*thickness*/ 7.29, /*edge thickness*/ 3.0, /*material*/ glasses.getNBK7_S1(),
		/*price*/ 50.90, /*design wavelength*/ 587.6, /*free aperture CA*/ 45.77, /*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*centration*/ 3.0,
		/*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1,
		/*coating*/ "BBAR", /*min wavelength*/ 400.0, /*max wavelength*/ 1100.0);

	mT_LA1399AB.buildLensTwoSurfaces_Thorlabs_oneSurfacePlan(/*lens catalog*/ "thorlabs", /*catalog number*/ "LA1399-AB", /*diameter*/ 50.8,
		/* focallength*/ 174.4, /*back focal length*/ 170.0, /*radius*/ 90.13, /*thickness*/ 6.65, /*edge thickness*/ 3.0, /*material*/ glasses.getNBK7_S1(),
		/*price*/ 50.90, /*design wavelength*/ 587.6, /*free aperture CA*/ 45.77, /*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*centration*/ 3.0,
		/*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1,
		/*coating*/ "BBAR", /*min wavelength*/ 400.0, /*max wavelength*/ 1100.0);

	mT_LA1979AB.buildLensTwoSurfaces_Thorlabs_oneSurfacePlan(/*lens catalog*/ "thorlabs", /*catalog number*/ "LA1979-AB", /*diameter*/ 50.8,
		/* focallength*/ 200.0, /*back focal length*/ 195.3, /*radius*/ 103.01, /*thickness*/ 6.18, /*edge thickness*/ 3.0, /*material*/ glasses.getNBK7_S1(),
		/*price*/ 50.90, /*design wavelength*/ 587.6, /*free aperture CA*/ 45.77, /*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*centration*/ 3.0,
		/*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1,
		/*coating*/ "BBAR", /*min wavelength*/ 400.0, /*max wavelength*/ 1100.0);

	mT_LA1301AB.buildLensTwoSurfaces_Thorlabs_oneSurfacePlan(/*lens catalog*/ "thorlabs", /*catalog number*/ "LA1301-AB", /*diameter*/ 50.8,
		/* focallength*/ 249.2, /*back focal length*/ 245.5, /*radius*/ 128.77, /*thickness*/ 5.52, /*edge thickness*/ 3.0, /*material*/ glasses.getNBK7_S1(),
		/*price*/ 50.90, /*design wavelength*/ 587.6, /*free aperture CA*/ 45.77, /*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*centration*/ 3.0,
		/*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1,
		/*coating*/ "BBAR", /*min wavelength*/ 400.0, /*max wavelength*/ 1100.0);

	mT_LA1256AB.buildLensTwoSurfaces_Thorlabs_oneSurfacePlan(/*lens catalog*/ "thorlabs", /*catalog number*/ "LA1256-AB", /*diameter*/ 50.8,
		/* focallength*/ 299.0, /*back focal length*/ 295.6, /*radius*/ 154.52, /*thickness*/ 5.1, /*edge thickness*/ 3.0, /*material*/ glasses.getNBK7_S1(),
		/*price*/ 50.90, /*design wavelength*/ 587.6, /*free aperture CA*/ 45.77, /*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*centration*/ 3.0,
		/*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1,
		/*coating*/ "BBAR", /*min wavelength*/ 400.0, /*max wavelength*/ 1100.0);

	mT_LA1725AB.buildLensTwoSurfaces_Thorlabs_oneSurfacePlan(/*lens catalog*/ "thorlabs", /*catalog number*/ "LA-1725AB", /*diameter*/ 50.8,
		/* focallength*/ 400.0, /*back focal length*/ 395.7, /*radius*/ 206.03, /*thickness*/ 4.57, /*edge thickness*/ 3.0, /*material*/ glasses.getNBK7_S1(),
		/*price*/ 51.81, /*design wavelength*/ 587.6, /*free aperture CA*/ 45.77, /*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*centration*/ 3.0,
		/*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1,
		/*coating*/ "BBAR", /*min wavelength*/ 400.0, /*max wavelength*/ 1100.0);

	mT_LA1380AB.buildLensTwoSurfaces_Thorlabs_oneSurfacePlan(/*lens catalog*/ "thorlabs", /*catalog number*/ "LA1380-AB", /*diameter*/ 50.8,
		/* focallength*/ 498.3, /*back focal length*/ 495.5, /*radius*/ 257.54, /*thickness*/ 4.25, /*edge thickness*/ 3.0, /*material*/ glasses.getNBK7_S1(),
		/*price*/ 50.90, /*design wavelength*/ 587.6, /*free aperture CA*/ 45.77, /*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*centration*/ 3.0,
		/*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1,
		/*coating*/ "BBAR", /*min wavelength*/ 400.0, /*max wavelength*/ 1100.0);

	mT_LA1727AB.buildLensTwoSurfaces_Thorlabs_oneSurfacePlan(/*lens catalog*/ "thorlabs", /*catalog number*/ "LA1727-AB", /*diameter*/ 50.8,
		/* focallength*/ 750.0, /*back focal length*/ 745.0, /*radius*/ 386.31, /*thickness*/ 3.83, /*edge thickness*/ 3.0, /*material*/ glasses.getNBK7_S1(),
		/*price*/ 51.81, /*design wavelength*/ 587.6, /*free aperture CA*/ 45.77, /*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*centration*/ 3.0,
		/*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1,
		/*coating*/ "BBAR", /*min wavelength*/ 400.0, /*max wavelength*/ 1100.0);

	mT_LA1779AB.buildLensTwoSurfaces_Thorlabs_oneSurfacePlan(/*lens catalog*/ "thorlabs", /*catalog number*/ "LA1779-AB", /*diameter*/ 50.8,
		/* focallength*/ 1000.0, /*back focal length*/ 994.3, /*radius*/ 515.08, /*thickness*/ 3.62, /*edge thickness*/ 3.0, /*material*/ glasses.getNBK7_S1(),
		/*price*/ 50.90, /*design wavelength*/ 587.6, /*free aperture CA*/ 45.77, /*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*centration*/ 3.0,
		/*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1,
		/*coating*/ "BBAR", /*min wavelength*/ 400.0, /*max wavelength*/ 1100.0);

}


std::vector<LensesTwoSurfaces> ThorlabsLensCatalog::getAll_Thorlabs_N_BK7_Plano_Convex_Lenses_AR_Coating_400_1100_nm()
{
	// https://www.thorlabs.de/newgrouppage9.cfm?objectgroup_id=13685

	std::vector<LensesTwoSurfaces> return_B_BK7_Plano_Convex_Lenses_AR_Coating_400_1000;

	return_B_BK7_Plano_Convex_Lenses_AR_Coating_400_1000.push_back(mT_LA1540AB);
	return_B_BK7_Plano_Convex_Lenses_AR_Coating_400_1000.push_back(mT_LA1074AB);
	return_B_BK7_Plano_Convex_Lenses_AR_Coating_400_1000.push_back(mT_LA1560AB);
	return_B_BK7_Plano_Convex_Lenses_AR_Coating_400_1000.push_back(mT_LA1289AB);
	return_B_BK7_Plano_Convex_Lenses_AR_Coating_400_1000.push_back(mT_LA1304AB);
	return_B_BK7_Plano_Convex_Lenses_AR_Coating_400_1000.push_back(mT_LA1213AB);
	return_B_BK7_Plano_Convex_Lenses_AR_Coating_400_1000.push_back(mT_LA1207AB);
	return_B_BK7_Plano_Convex_Lenses_AR_Coating_400_1000.push_back(mT_LA1951AB);
	return_B_BK7_Plano_Convex_Lenses_AR_Coating_400_1000.push_back(mT_LA1805AB);
	return_B_BK7_Plano_Convex_Lenses_AR_Coating_400_1000.push_back(mT_LA1027AB);
	return_B_BK7_Plano_Convex_Lenses_AR_Coating_400_1000.push_back(mT_LA1422AB);
	return_B_BK7_Plano_Convex_Lenses_AR_Coating_400_1000.push_back(mT_LA1131AB);
	return_B_BK7_Plano_Convex_Lenses_AR_Coating_400_1000.push_back(mT_LA1134AB);
	return_B_BK7_Plano_Convex_Lenses_AR_Coating_400_1000.push_back(mT_LA1608AB);
	return_B_BK7_Plano_Convex_Lenses_AR_Coating_400_1000.push_back(mT_LA1986AB);
	return_B_BK7_Plano_Convex_Lenses_AR_Coating_400_1000.push_back(mT_LA1433AB);
	return_B_BK7_Plano_Convex_Lenses_AR_Coating_400_1000.push_back(mT_LA1229AB);
	return_B_BK7_Plano_Convex_Lenses_AR_Coating_400_1000.push_back(mT_LA1708AB);
	return_B_BK7_Plano_Convex_Lenses_AR_Coating_400_1000.push_back(mT_LA1461AB);
	return_B_BK7_Plano_Convex_Lenses_AR_Coating_400_1000.push_back(mT_LA1484AB);
	return_B_BK7_Plano_Convex_Lenses_AR_Coating_400_1000.push_back(mT_LA1172AB);
	return_B_BK7_Plano_Convex_Lenses_AR_Coating_400_1000.push_back(mT_LA1908AB);
	return_B_BK7_Plano_Convex_Lenses_AR_Coating_400_1000.push_back(mT_LA1978AB);
	return_B_BK7_Plano_Convex_Lenses_AR_Coating_400_1000.push_back(mT_LA1464AB);
	return_B_BK7_Plano_Convex_Lenses_AR_Coating_400_1000.push_back(mT_LA1254AB);
	return_B_BK7_Plano_Convex_Lenses_AR_Coating_400_1000.push_back(mT_LA1258AB);
	return_B_BK7_Plano_Convex_Lenses_AR_Coating_400_1000.push_back(mT_LA1259AB);
	return_B_BK7_Plano_Convex_Lenses_AR_Coating_400_1000.push_back(mT_LA1401AB);
	return_B_BK7_Plano_Convex_Lenses_AR_Coating_400_1000.push_back(mT_LA1145AB);
	return_B_BK7_Plano_Convex_Lenses_AR_Coating_400_1000.push_back(mT_LA1050AB);
	return_B_BK7_Plano_Convex_Lenses_AR_Coating_400_1000.push_back(mT_LA1384AB);
	return_B_BK7_Plano_Convex_Lenses_AR_Coating_400_1000.push_back(mT_LA1417AB);
	return_B_BK7_Plano_Convex_Lenses_AR_Coating_400_1000.push_back(mT_LA1399AB);
	return_B_BK7_Plano_Convex_Lenses_AR_Coating_400_1000.push_back(mT_LA1979AB);
	return_B_BK7_Plano_Convex_Lenses_AR_Coating_400_1000.push_back(mT_LA1301AB);
	return_B_BK7_Plano_Convex_Lenses_AR_Coating_400_1000.push_back(mT_LA1256AB);
	return_B_BK7_Plano_Convex_Lenses_AR_Coating_400_1000.push_back(mT_LA1725AB);
	return_B_BK7_Plano_Convex_Lenses_AR_Coating_400_1000.push_back(mT_LA1380AB);
	return_B_BK7_Plano_Convex_Lenses_AR_Coating_400_1000.push_back(mT_LA1727AB);
	return_B_BK7_Plano_Convex_Lenses_AR_Coating_400_1000.push_back(mT_LA1779AB);


	return return_B_BK7_Plano_Convex_Lenses_AR_Coating_400_1000;

}
// ***

// *** N BK7 Bi-Convex Lenses AR Coating: 350 - 700 nm
void ThorlabsLensCatalog::loadLensCatalogThorlabs_N_BK7_Bi_Convex_Lenses_AR_Coating_350_700_nm()
{
	glass glasses;
	glasses.loadGlassCatalog_Schott();

	mT_LB1157A.buildLensTwoSurfaces_thorlabs(/*lens catalog*/ "Thorlabs", /*item*/ "LB1157-A", /*diameter*/ 6.0, /* focallength*/ 10.0, /*back focal length*/ 9.2,
		/*radius first surface*/ 9.87, /*radius second surface*/ -9.87, /*thickness*/ 2.43, /*edge thickness*/ 1.5, /*material*/ glasses.getNBK7_S1(), /*price*/ 31.48, /*design wavelength*/ 587.6,
		/*free aperture CA*/ 0.9 * 6.0, /*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*centration*/ 3.0, /*max diameter tolerance*/ 0.0,
		/*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1, /*coating*/ "BBAR", /*min wavelength*/ 350.0, /*max wavelength*/ 700.0);

	mT_LB1406A.buildLensTwoSurfaces_thorlabs(/*lens catalog*/ "Thorlabs", /*item*/ "LB1406-A", /*diameter*/ 6.0, /* focallength*/ 12.0, /*back focal length*/ 11.2,
		/*radius first surface*/ 11.96, /*radius second surface*/ -11.96, /*thickness*/ 2.26, /*edge thickness*/ 1.5, /*material*/ glasses.getNBK7_S1(), /*price*/ 30.00,
		/*design wavelength*/ 587.6, /*free aperture CA*/ 0.9 * 6.0, /*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*centration*/ 3.0,
		/*max diameter tolerance*/ 0.0,	/*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1, /*coating*/ "BBAR",
		/*min wavelength*/ 350.0, /*max wavelength*/ 700.0);

	mT_LB1494A.buildLensTwoSurfaces_thorlabs(/*lens catalog*/ "Thorlabs", /*item*/ "LB1494-A", /*diameter*/ 9.0, /* focallength*/ 12.0, /*back focal length*/ 10.7,
		/*radius first surface*/ 11.71, /*radius second surface*/ -11.71, /*thickness*/ 3.6, /*edge thickness*/ 1.8, /*material*/ glasses.getNBK7_S1(), /*price*/ 32.21,
		/*design wavelength*/ 587.6, /*free aperture CA*/ 0.9 * 9.0, /*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*centration*/ 3.0,
		/*max diameter tolerance*/ 0.0,	/*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1, /*coating*/ "BBAR",
		/*min wavelength*/ 350.0, /*max wavelength*/ 700.0);

	mT_LB1212A.buildLensTwoSurfaces_thorlabs(/*lens catalog*/ "Thorlabs", /*item*/ "LB1212-A", /*diameter*/ 9.0, /* focallength*/ 20.0, /*back focal length*/ 19.0,
		/*radius first surface*/ 20.11, /*radius second surface*/ -20.11, /*thickness*/ 2.82, /*edge thickness*/ 1.8, /*material*/ glasses.getNBK7_S1(), /*price*/ 30.00,
		/*design wavelength*/ 587.6, /*free aperture CA*/ 0.9 * 9.0, /*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*centration*/ 3.0,
		/*max diameter tolerance*/ 0.0,	/*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1, /*coating*/ "BBAR",
		/*min wavelength*/ 350.0, /*max wavelength*/ 700.0);

	mT_LB1092A.buildLensTwoSurfaces_thorlabs(/*lens catalog*/ "Thorlabs", /*item*/ "LB1092-A", /*diameter*/ 12.7, /* focallength*/ 15.0, /*back focal length*/ 13.4,
		/*radius first surface*/ 14.6, /*radius second surface*/ -14.6, /*thickness*/ 4.7, /*edge thickness*/ 1.8, /*material*/ glasses.getNBK7_S1(), /*price*/ 32.21,
		/*design wavelength*/ 587.6, /*free aperture CA*/ 0.9 * 12.7, /*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*centration*/ 3.0,
		/*max diameter tolerance*/ 0.0,	/*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1, /*coating*/ "BBAR",
		/*min wavelength*/ 350.0, /*max wavelength*/ 700.0);

	mT_LB1450A.buildLensTwoSurfaces_thorlabs(/*lens catalog*/ "Thorlabs", /*item*/ "LB1450-A", /*diameter*/ 12.7, /* focallength*/ 20.0, /*back focal length*/ 18.7,
		/*radius first surface*/ 19.92, /*radius second surface*/ -19.92, /*thickness*/ 3.88, /*edge thickness*/ 1.8, /*material*/ glasses.getNBK7_S1(), /*price*/ 31.96,
		/*design wavelength*/ 587.6, /*free aperture CA*/ 0.9 * 12.7, /*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*centration*/ 3.0,
		/*max diameter tolerance*/ 0.0,	/*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1, /*coating*/ "BBAR",
		/*min wavelength*/ 350.0, /*max wavelength*/ 700.0);

	mT_LB1014A.buildLensTwoSurfaces_thorlabs(/*lens catalog*/ "Thorlabs", /*item*/ "LB1014-A", /*diameter*/ 12.7, /* focallength*/ 25.0, /*back focal length*/ 23.8,
		/*radius first surface*/ 25.15, /*radius second surface*/ -25.15, /*thickness*/ 3.43, /*edge thickness*/ 1.8, /*material*/ glasses.getNBK7_S1(), /*price*/ 30.50,
		/*design wavelength*/ 587.6, /*free aperture CA*/ 0.9 * 12.7, /*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*centration*/ 3.0,
		/*max diameter tolerance*/ 0.0,	/*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1, /*coating*/ "BBAR",
		/*min wavelength*/ 350.0, /*max wavelength*/ 700.0);

	mT_LB1258A.buildLensTwoSurfaces_thorlabs(/*lens catalog*/ "Thorlabs", /*item*/ "LB1258-A", /*diameter*/ 12.7, /* focallength*/ 30.0, /*back focal length*/ 28.9,
		/*radius first surface*/ 30.36, /*radius second surface*/ -30.36, /*thickness*/ 3.14, /*edge thickness*/ 1.8, /*material*/ glasses.getNBK7_S1(), /*price*/ 30.00,
		/*design wavelength*/ 587.6, /*free aperture CA*/ 0.9 * 12.7, /*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*centration*/ 3.0,
		/*max diameter tolerance*/ 0.0,	/*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1, /*coating*/ "BBAR",
		/*min wavelength*/ 350.0, /*max wavelength*/ 700.0);

	mT_LB1378A.buildLensTwoSurfaces_thorlabs(/*lens catalog*/ "Thorlabs", /*item*/ "LB1378-A", /*diameter*/ 12.7, /* focallength*/ 40.0, /*back focal length*/ 39.1,
		/*radius first surface*/ 40.72, /*radius second surface*/ -40.72, /*thickness*/ 2.8, /*edge thickness*/ 1.8, /*material*/ glasses.getNBK7_S1(), /*price*/ 29.76,
		/*design wavelength*/ 587.6, /*free aperture CA*/ 0.9 * 12.7, /*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*centration*/ 3.0,
		/*max diameter tolerance*/ 0.0,	/*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1, /*coating*/ "BBAR",
		/*min wavelength*/ 350.0, /*max wavelength*/ 700.0);

	mT_LB1844A.buildLensTwoSurfaces_thorlabs(/*lens catalog*/ "Thorlabs", /*item*/ "LB1844-A", /*diameter*/ 12.7, /* focallength*/ 50.0, /*back focal length*/ 49.1,
		/*radius first surface*/ 51.06, /*radius second surface*/ -51.06, /*thickness*/ 2.59, /*edge thickness*/ 1.8, /*material*/ glasses.getNBK7_S1(), /*price*/ 29.52,
		/*design wavelength*/ 587.6, /*free aperture CA*/ 0.9 * 12.7, /*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*centration*/ 3.0,
		/*max diameter tolerance*/ 0.0,	/*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1, /*coating*/ "BBAR",
		/*min wavelength*/ 350.0, /*max wavelength*/ 700.0);

	mT_LB1187A.buildLensTwoSurfaces_thorlabs(/*lens catalog*/ "Thorlabs", /*item*/ "LB1187-A", /*diameter*/ 12.7, /* focallength*/ 100.0, /*back focal length*/ 99.3,
		/*radius first surface*/ 102.64, /*radius second surface*/ -102.64, /*thickness*/ 2.19, /*edge thickness*/ 1.8, /*material*/ glasses.getNBK7_S1(), /*price*/ 29.52,
		/*design wavelength*/ 587.6, /*free aperture CA*/ 0.9 * 12.7, /*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*centration*/ 3.0,
		/*max diameter tolerance*/ 0.0,	/*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1, /*coating*/ "BBAR",
		/*min wavelength*/ 350.0, /*max wavelength*/ 700.0);

	mT_LB1761A.buildLensTwoSurfaces_thorlabs(/*lens catalog*/ "Thorlabs", /*item*/ "LB1761-A", /*diameter*/ 25.4, /* focallength*/ 25.4, /*back focal length*/ 22.2,
		/*radius first surface*/ 24.53, /*radius second surface*/ -24.53, /*thickness*/ 8.98, /*edge thickness*/ 1.9, /*material*/ glasses.getNBK7_S1(), /*price*/ 35.66,
		/*design wavelength*/ 587.6, /*free aperture CA*/ 0.9 * 25.4, /*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*centration*/ 3.0,
		/*max diameter tolerance*/ 0.0,	/*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1, /*coating*/ "BBAR",
		/*min wavelength*/ 350.0, /*max wavelength*/ 700.0);

	mT_LB1757A.buildLensTwoSurfaces_thorlabs(/*lens catalog*/ "Thorlabs", /*item*/ "LB1757-A", /*diameter*/ 25.4, /* focallength*/ 30.0, /*back focal length*/ 27.3,
		/*radius first surface*/ 29.52, /*radius second surface*/ -29.52, /*thickness*/ 7.74, /*edge thickness*/ 2.0, /*material*/ glasses.getNBK7_S1(), /*price*/ 34.92,
		/*design wavelength*/ 587.6, /*free aperture CA*/ 0.9 * 25.4, /*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*centration*/ 3.0,
		/*max diameter tolerance*/ 0.0,	/*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1, /*coating*/ "BBAR",
		/*min wavelength*/ 350.0, /*max wavelength*/ 700.0);

	mT_LB1811A.buildLensTwoSurfaces_thorlabs(/*lens catalog*/ "Thorlabs", /*item*/ "LB1811-A", /*diameter*/ 25.4, /* focallength*/ 35.0, /*back focal length*/ 32.7,
		/*radius first surface*/ 34.86, /*radius second surface*/ -34.86, /*thickness*/ 6.79, /*edge thickness*/ 2.0, /*material*/ glasses.getNBK7_S1(), /*price*/ 34.19,
		/*design wavelength*/ 587.6, /*free aperture CA*/ 0.9 * 25.4, /*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*centration*/ 3.0,
		/*max diameter tolerance*/ 0.0,	/*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1, /*coating*/ "BBAR",
		/*min wavelength*/ 350.0, /*max wavelength*/ 700.0);

	mT_LB1027A.buildLensTwoSurfaces_thorlabs(/*lens catalog*/ "Thorlabs", /*item*/ "LB1027-A", /*diameter*/ 25.4, /* focallength*/ 40.0, /*back focal length*/ 37.9,
		/*radius first surface*/ 40.13, /*radius second surface*/ -40.13, /*thickness*/ 6.12, /*edge thickness*/ 2.0, /*material*/ glasses.getNBK7_S1(), /*price*/ 33.94,
		/*design wavelength*/ 587.6, /*free aperture CA*/ 0.9 * 25.4, /*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*centration*/ 3.0,
		/*max diameter tolerance*/ 0.0,	/*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1, /*coating*/ "BBAR",
		/*min wavelength*/ 350.0, /*max wavelength*/ 700.0);

	mT_LB1471A.buildLensTwoSurfaces_thorlabs(/*lens catalog*/ "Thorlabs", /*item*/ "LB1471-A", /*diameter*/ 25.4, /* focallength*/ 50.0, /*back focal length*/ 48.2,
		/*radius first surface*/ 50.6, /*radius second surface*/ -50.6, /*thickness*/ 5.24, /*edge thickness*/ 2.0, /*material*/ glasses.getNBK7_S1(), /*price*/ 33.44,
		/*design wavelength*/ 587.6, /*free aperture CA*/ 0.9 * 25.4, /*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*centration*/ 3.0,
		/*max diameter tolerance*/ 0.0,	/*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1, /*coating*/ "BBAR",
		/*min wavelength*/ 350.0, /*max wavelength*/ 700.0);

	mT_LB1596A.buildLensTwoSurfaces_thorlabs(/*lens catalog*/ "Thorlabs", /*item*/ "LB1596-A", /*diameter*/ 25.4, /* focallength*/ 60.0, /*back focal length*/ 58.4,
		/*radius first surface*/ 61.0, /*radius second surface*/ -61.0, /*thickness*/ 4.67, /*edge thickness*/ 2.0, /*material*/ glasses.getNBK7_S1(), /*price*/ 32.96,
		/*design wavelength*/ 587.6, /*free aperture CA*/ 0.9 * 25.4, /*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*centration*/ 3.0,
		/*max diameter tolerance*/ 0.0,	/*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1, /*coating*/ "BBAR",
		/*min wavelength*/ 350.0, /*max wavelength*/ 700.0);

	mT_LB1901A.buildLensTwoSurfaces_thorlabs(/*lens catalog*/ "Thorlabs", /*item*/ "LB1901-A", /*diameter*/ 25.4, /* focallength*/ 75.0, /*back focal length*/ 73.6,
		/*radius first surface*/ 76.55, /*radius second surface*/ -76.55, /*thickness*/ 4.12, /*edge thickness*/ 2.0, /*material*/ glasses.getNBK7_S1(), /*price*/ 32.96,
		/*design wavelength*/ 587.6, /*free aperture CA*/ 0.9 * 25.4, /*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*centration*/ 3.0,
		/*max diameter tolerance*/ 0.0,	/*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1, /*coating*/ "BBAR",
		/*min wavelength*/ 350.0, /*max wavelength*/ 700.0);

	mT_LB1676A.buildLensTwoSurfaces_thorlabs(/*lens catalog*/ "Thorlabs", /*item*/ "LB1676-A", /*diameter*/ 25.4, /* focallength*/ 100.0, /*back focal length*/ 98.8,
		/*radius first surface*/ 102.4, /*radius second surface*/ -102.4, /*thickness*/ 3.58, /*edge thickness*/ 2.0, /*material*/ glasses.getNBK7_S1(), /*price*/ 32.21,
		/*design wavelength*/ 587.6, /*free aperture CA*/ 0.9 * 25.4, /*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*centration*/ 3.0,
		/*max diameter tolerance*/ 0.0,	/*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1, /*coating*/ "BBAR",
		/*min wavelength*/ 350.0, /*max wavelength*/ 700.0);

	mT_LB1904A.buildLensTwoSurfaces_thorlabs(/*lens catalog*/ "Thorlabs", /*item*/ "LB1904-A", /*diameter*/ 25.4, /* focallength*/ 125.0, /*back focal length*/ 123.9,
		/*radius first surface*/ 128.21, /*radius second surface*/ -128.21, /*thickness*/ 3.26, /*edge thickness*/ 2.0, /*material*/ glasses.getNBK7_S1(), /*price*/ 31.96,
		/*design wavelength*/ 587.6, /*free aperture CA*/ 0.9 * 25.4, /*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*centration*/ 3.0,
		/*max diameter tolerance*/ 0.0,	/*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1, /*coating*/ "BBAR",
		/*min wavelength*/ 350.0, /*max wavelength*/ 700.0);

	mT_LB1437A.buildLensTwoSurfaces_thorlabs(/*lens catalog*/ "Thorlabs", /*item*/ "LB1437-A", /*diameter*/ 25.4, /* focallength*/ 150.0, /*back focal length*/ 149.0,
		/*radius first surface*/ 154.0, /*radius second surface*/ -154.0, /*thickness*/ 3.05, /*edge thickness*/ 2.0, /*material*/ glasses.getNBK7_S1(), /*price*/ 31.48,
		/*design wavelength*/ 587.6, /*free aperture CA*/ 0.9 * 25.4, /*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*centration*/ 3.0,
		/*max diameter tolerance*/ 0.0,	/*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1, /*coating*/ "BBAR",
		/*min wavelength*/ 350.0, /*max wavelength*/ 700.0);

	mT_LB1294A.buildLensTwoSurfaces_thorlabs(/*lens catalog*/ "Thorlabs", /*item*/ "LB1294-A", /*diameter*/ 25.4, /* focallength*/ 175.0, /*back focal length*/ 174.0,
		/*radius first surface*/ 179.78, /*radius second surface*/ -179.78, /*thickness*/ 2.9, /*edge thickness*/ 2.0, /*material*/ glasses.getNBK7_S1(), /*price*/ 31.23,
		/*design wavelength*/ 587.6, /*free aperture CA*/ 0.9 * 25.4, /*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*centration*/ 3.0,
		/*max diameter tolerance*/ 0.0,	/*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1, /*coating*/ "BBAR",
		/*min wavelength*/ 350.0, /*max wavelength*/ 700.0);

	mT_LB1945A.buildLensTwoSurfaces_thorlabs(/*lens catalog*/ "Thorlabs", /*item*/ "LB1945-A", /*diameter*/ 25.4, /* focallength*/ 200.0, /*back focal length*/ 199.1,
		/*radius first surface*/ 205.55, /*radius second surface*/ -205.55, /*thickness*/ 2.79, /*edge thickness*/ 2.0, /*material*/ glasses.getNBK7_S1(), /*price*/ 31.23,
		/*design wavelength*/ 587.6, /*free aperture CA*/ 0.9 * 25.4, /*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*centration*/ 3.0,
		/*max diameter tolerance*/ 0.0,	/*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1, /*coating*/ "BBAR",
		/*min wavelength*/ 350.0, /*max wavelength*/ 700.0);

	mT_LB1056A.buildLensTwoSurfaces_thorlabs(/*lens catalog*/ "Thorlabs", /*item*/ "LB1056-A", /*diameter*/ 25.4, /* focallength*/ 250.0, /*back focal length*/ 249.1,
		/*radius first surface*/ 257.09, /*radius second surface*/ -257.09, /*thickness*/ 2.63, /*edge thickness*/ 2.0, /*material*/ glasses.getNBK7_S1(), /*price*/ 30.98,
		/*design wavelength*/ 587.6, /*free aperture CA*/ 0.9 * 25.4, /*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*centration*/ 3.0,
		/*max diameter tolerance*/ 0.0,	/*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1, /*coating*/ "BBAR",
		/*min wavelength*/ 350.0, /*max wavelength*/ 700.0);

	mT_LB1779A.buildLensTwoSurfaces_thorlabs(/*lens catalog*/ "Thorlabs", /*item*/ "LB1779-A", /*diameter*/ 25.4, /* focallength*/ 300.0, /*back focal length*/ 299.2,
		/*radius first surface*/ 308.62, /*radius second surface*/ -308.62, /*thickness*/ 2.52, /*edge thickness*/ 2.0, /*material*/ glasses.getNBK7_S1(), /*price*/ 30.98,
		/*design wavelength*/ 587.6, /*free aperture CA*/ 0.9 * 25.4, /*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*centration*/ 3.0,
		/*max diameter tolerance*/ 0.0,	/*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1, /*coating*/ "BBAR",
		/*min wavelength*/ 350.0, /*max wavelength*/ 700.0);

	mT_LB1391A.buildLensTwoSurfaces_thorlabs(/*lens catalog*/ "Thorlabs", /*item*/ "LB1391-A", /*diameter*/ 25.4, /* focallength*/ 400.0, /*back focal length*/ 399.2,
		/*radius first surface*/ 411.65, /*radius second surface*/ -411.65, /*thickness*/ 2.39, /*edge thickness*/ 2.0, /*material*/ glasses.getNBK7_S1(), /*price*/ 30.98,
		/*design wavelength*/ 587.6, /*free aperture CA*/ 0.9 * 25.4, /*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*centration*/ 3.0,
		/*max diameter tolerance*/ 0.0,	/*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1, /*coating*/ "BBAR",
		/*min wavelength*/ 350.0, /*max wavelength*/ 700.0);

	mT_LB1869A.buildLensTwoSurfaces_thorlabs(/*lens catalog*/ "Thorlabs", /*item*/ "LB1869-A", /*diameter*/ 25.4, /* focallength*/ 500.0, /*back focal length*/ 499.2,
		/*radius first surface*/ 514.68, /*radius second surface*/ -514.68, /*thickness*/ 2.31, /*edge thickness*/ 2.0, /*material*/ glasses.getNBK7_S1(), /*price*/ 30.98,
		/*design wavelength*/ 587.6, /*free aperture CA*/ 0.9 * 25.4, /*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*centration*/ 3.0,
		/*max diameter tolerance*/ 0.0,	/*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1, /*coating*/ "BBAR",
		/*min wavelength*/ 350.0, /*max wavelength*/ 700.0);

	mT_LB1475A.buildLensTwoSurfaces_thorlabs(/*lens catalog*/ "Thorlabs", /*item*/ "LB1475-A", /*diameter*/ 25.4, /* focallength*/ 750.0, /*back focal length*/ 749.3,
		/*radius first surface*/ 772.24, /*radius second surface*/ -772.24, /*thickness*/ 2.21, /*edge thickness*/ 2.0, /*material*/ glasses.getNBK7_S1(), /*price*/ 30.98,
		/*design wavelength*/ 587.6, /*free aperture CA*/ 0.9 * 25.4, /*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*centration*/ 3.0,
		/*max diameter tolerance*/ 0.0,	/*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1, /*coating*/ "BBAR",
		/*min wavelength*/ 350.0, /*max wavelength*/ 700.0);

	mT_LB1409A.buildLensTwoSurfaces_thorlabs(/*lens catalog*/ "Thorlabs", /*item*/ "LB1409-A", /*diameter*/ 25.4, /* focallength*/ 1000.0, /*back focal length*/ 999.3,
		/*radius first surface*/ 1029.79, /*radius second surface*/ -1029.79, /*thickness*/ 2.16, /*edge thickness*/ 2.0, /*material*/ glasses.getNBK7_S1(), /*price*/ 30.75,
		/*design wavelength*/ 587.6, /*free aperture CA*/ 0.9 * 25.4, /*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*centration*/ 3.0,
		/*max diameter tolerance*/ 0.0,	/*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1, /*coating*/ "BBAR",
		/*min wavelength*/ 350.0, /*max wavelength*/ 700.0);

	mT_LB1723A.buildLensTwoSurfaces_thorlabs(/*lens catalog*/ "Thorlabs", /*item*/ "LB1723-A", /*diameter*/ 50.8, /* focallength*/ 60.0, /*back focal length*/ 55.0,
		/*radius first surface*/ 59.24, /*radius second surface*/ -59.24, /*thickness*/ 14.44, /*edge thickness*/ 3.0, /*material*/ glasses.getNBK7_S1(), /*price*/ 42.06,
		/*design wavelength*/ 587.6, /*free aperture CA*/ 0.9 * 50.8, /*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*centration*/ 3.0,
		/*max diameter tolerance*/ 0.0,	/*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1, /*coating*/ "BBAR",
		/*min wavelength*/ 350.0, /*max wavelength*/ 700.0);

	mT_LB1309A.buildLensTwoSurfaces_thorlabs(/*lens catalog*/ "Thorlabs", /*item*/ "LB1309-A", /*diameter*/ 50.8, /* focallength*/ 75.0, /*back focal length*/ 71.0,
		/*radius first surface*/ 75.19, /*radius second surface*/ -75.19, /*thickness*/ 11.84, /*edge thickness*/ 3.0, /*material*/ glasses.getNBK7_S1(), /*price*/ 42.06,
		/*design wavelength*/ 587.6, /*free aperture CA*/ 0.9 * 50.8, /*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*centration*/ 3.0,
		/*max diameter tolerance*/ 0.0,	/*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1, /*coating*/ "BBAR",
		/*min wavelength*/ 350.0, /*max wavelength*/ 700.0);

	mT_LB1630A.buildLensTwoSurfaces_thorlabs(/*lens catalog*/ "Thorlabs", /*item*/ "LB1630-A", /*diameter*/ 50.8, /* focallength*/ 100.0, /*back focal length*/ 96.8,
		/*radius first surface*/ 101.38, /*radius second surface*/ -101.38, /*thickness*/ 9.47, /*edge thickness*/ 3.0, /*material*/ glasses.getNBK7_S1(), /*price*/ 41.56,
		/*design wavelength*/ 587.6, /*free aperture CA*/ 0.9 * 50.8, /*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*centration*/ 3.0,
		/*max diameter tolerance*/ 0.0,	/*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1, /*coating*/ "BBAR",
		/*min wavelength*/ 350.0, /*max wavelength*/ 700.0);

	mT_LB1106A.buildLensTwoSurfaces_thorlabs(/*lens catalog*/ "Thorlabs", /*item*/ "LB1106-A", /*diameter*/ 50.8, /* focallength*/ 125.0, /*back focal length*/ 122.3,
		/*radius first surface*/ 127.37, /*radius second surface*/ -127.37, /*thickness*/ 8.12, /*edge thickness*/ 3.0, /*material*/ glasses.getNBK7_S1(), /*price*/ 41.56,
		/*design wavelength*/ 587.6, /*free aperture CA*/ 0.9 * 50.8, /*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*centration*/ 3.0,
		/*max diameter tolerance*/ 0.0,	/*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1, /*coating*/ "BBAR",
		/*min wavelength*/ 350.0, /*max wavelength*/ 700.0);

	mT_LB1374A.buildLensTwoSurfaces_thorlabs(/*lens catalog*/ "Thorlabs", /*item*/ "LB1374-A", /*diameter*/ 50.8, /* focallength*/ 150.0, /*back focal length*/ 147.6,
		/*radius first surface*/ 153.28, /*radius second surface*/ -153.28, /*thickness*/ 7.24, /*edge thickness*/ 3.0, /*material*/ glasses.getNBK7_S1(), /*price*/ 41.08,
		/*design wavelength*/ 587.6, /*free aperture CA*/ 0.9 * 50.8, /*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*centration*/ 3.0,
		/*max diameter tolerance*/ 0.0,	/*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1, /*coating*/ "BBAR",
		/*min wavelength*/ 350.0, /*max wavelength*/ 700.0);

	mT_LB1607A.buildLensTwoSurfaces_thorlabs(/*lens catalog*/ "Thorlabs", /*item*/ "LB1607-A", /*diameter*/ 50.8, /* focallength*/ 175.0, /*back focal length*/ 172.8,
		/*radius first surface*/ 179.14, /*radius second surface*/ -179.14, /*thickness*/ 6.62, /*edge thickness*/ 3.0, /*material*/ glasses.getNBK7_S1(), /*price*/ 41.08,
		/*design wavelength*/ 587.6, /*free aperture CA*/ 0.9 * 50.8, /*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*centration*/ 3.0,
		/*max diameter tolerance*/ 0.0,	/*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1, /*coating*/ "BBAR",
		/*min wavelength*/ 350.0, /*max wavelength*/ 700.0);

	mT_LB1199A.buildLensTwoSurfaces_thorlabs(/*lens catalog*/ "Thorlabs", /*item*/ "LB1199-A", /*diameter*/ 50.8, /* focallength*/ 200.0, /*back focal length*/ 198.0,
		/*radius first surface*/ 204.98, /*radius second surface*/ -204.98, /*thickness*/ 6.16, /*edge thickness*/ 3.0, /*material*/ glasses.getNBK7_S1(), /*price*/ 41.08,
		/*design wavelength*/ 587.6, /*free aperture CA*/ 0.9 * 50.8, /*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*centration*/ 3.0,
		/*max diameter tolerance*/ 0.0,	/*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1, /*coating*/ "BBAR",
		/*min wavelength*/ 350.0, /*max wavelength*/ 700.0);

	mT_LB1889A.buildLensTwoSurfaces_thorlabs(/*lens catalog*/ "Thorlabs", /*item*/ "LB1889-A", /*diameter*/ 50.8, /* focallength*/ 250.0, /*back focal length*/ 248.2,
		/*radius first surface*/ 256.59, /*radius second surface*/ -256.59, /*thickness*/ 5.52, /*edge thickness*/ 3.0, /*material*/ glasses.getNBK7_S1(), /*price*/ 41.08,
		/*design wavelength*/ 587.6, /*free aperture CA*/ 0.9 * 50.8, /*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*centration*/ 3.0,
		/*max diameter tolerance*/ 0.0,	/*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1, /*coating*/ "BBAR",
		/*min wavelength*/ 350.0, /*max wavelength*/ 700.0);

	mT_LB1917A.buildLensTwoSurfaces_thorlabs(/*lens catalog*/ "Thorlabs", /*item*/ "LB1917-A", /*diameter*/ 50.8, /* focallength*/ 300.0, /*back focal length*/ 298.3,
		/*radius first surface*/ 308.17, /*radius second surface*/ -308.17, /*thickness*/ 5.1, /*edge thickness*/ 3.0, /*material*/ glasses.getNBK7_S1(), /*price*/ 41.08,
		/*design wavelength*/ 587.6, /*free aperture CA*/ 0.9 * 50.8, /*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*centration*/ 3.0,
		/*max diameter tolerance*/ 0.0,	/*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1, /*coating*/ "BBAR",
		/*min wavelength*/ 350.0, /*max wavelength*/ 700.0);

	mT_LB1862A.buildLensTwoSurfaces_thorlabs(/*lens catalog*/ "Thorlabs", /*item*/ "LB1862-A", /*diameter*/ 50.8, /* focallength*/ 400.0, /*back focal length*/ 398.5,
		/*radius first surface*/ 411.28, /*radius second surface*/ -411.28, /*thickness*/ 4.57, /*edge thickness*/ 3.0, /*material*/ glasses.getNBK7_S1(), /*price*/ 41.08,
		/*design wavelength*/ 587.6, /*free aperture CA*/ 0.9 * 50.8, /*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*centration*/ 3.0,
		/*max diameter tolerance*/ 0.0,	/*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1, /*coating*/ "BBAR",
		/*min wavelength*/ 350.0, /*max wavelength*/ 700.0);

	mT_LB1909A.buildLensTwoSurfaces_thorlabs(/*lens catalog*/ "Thorlabs", /*item*/ "LB1909-A", /*diameter*/ 50.8, /* focallength*/ 500.0, /*back focal length*/ 498.6,
		/*radius first surface*/ 514.35, /*radius second surface*/ -514.35, /*thickness*/ 4.26, /*edge thickness*/ 3.0, /*material*/ glasses.getNBK7_S1(), /*price*/ 41.08,
		/*design wavelength*/ 587.6, /*free aperture CA*/ 0.9 * 50.8, /*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*centration*/ 3.0,
		/*max diameter tolerance*/ 0.0,	/*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1, /*coating*/ "BBAR",
		/*min wavelength*/ 350.0, /*max wavelength*/ 700.0);

	mT_LB1247A.buildLensTwoSurfaces_thorlabs(/*lens catalog*/ "Thorlabs", /*item*/ "LB1247-A", /*diameter*/ 50.8, /* focallength*/ 750.0, /*back focal length*/ 748.7,
		/*radius first surface*/ 771.96, /*radius second surface*/ -771.96, /*thickness*/ 3.84, /*edge thickness*/ 3.0, /*material*/ glasses.getNBK7_S1(), /*price*/ 41.08,
		/*design wavelength*/ 587.6, /*free aperture CA*/ 0.9 * 50.8, /*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*centration*/ 3.0,
		/*max diameter tolerance*/ 0.0,	/*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1, /*coating*/ "BBAR",
		/*min wavelength*/ 350.0, /*max wavelength*/ 700.0);

	mT_LB1859A.buildLensTwoSurfaces_thorlabs(/*lens catalog*/ "Thorlabs", /*item*/ "LB1859-A", /*diameter*/ 50.8, /* focallength*/ 1000.0, /*back focal length*/ 998.8,
		/*radius first surface*/ 1029.54, /*radius second surface*/ -1029.54, /*thickness*/ 3.63, /*edge thickness*/ 3.0, /*material*/ glasses.getNBK7_S1(), /*price*/ 41.08,
		/*design wavelength*/ 587.6, /*free aperture CA*/ 0.9 * 50.8, /*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*centration*/ 3.0,
		/*max diameter tolerance*/ 0.0,	/*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1, /*coating*/ "BBAR",
		/*min wavelength*/ 350.0, /*max wavelength*/ 700.0);


}

std::vector<LensesTwoSurfaces> ThorlabsLensCatalog::getAll_Thorlabs_N_BK7_Bi_Convex_Lenses_AR_Coating_350_700_nm()
{
	// https://www.thorlabs.de/newgrouppage9.cfm?objectgroup_id=4848

	std::vector<LensesTwoSurfaces> return_N_BK7_Bi_Convex_Lenses_AR_Coating_350_700_nm;

	return_N_BK7_Bi_Convex_Lenses_AR_Coating_350_700_nm.push_back(mT_LB1157A);
	return_N_BK7_Bi_Convex_Lenses_AR_Coating_350_700_nm.push_back(mT_LB1406A);
	return_N_BK7_Bi_Convex_Lenses_AR_Coating_350_700_nm.push_back(mT_LB1494A);
	return_N_BK7_Bi_Convex_Lenses_AR_Coating_350_700_nm.push_back(mT_LB1212A);
	return_N_BK7_Bi_Convex_Lenses_AR_Coating_350_700_nm.push_back(mT_LB1092A);
	return_N_BK7_Bi_Convex_Lenses_AR_Coating_350_700_nm.push_back(mT_LB1450A);
	return_N_BK7_Bi_Convex_Lenses_AR_Coating_350_700_nm.push_back(mT_LB1014A);
	return_N_BK7_Bi_Convex_Lenses_AR_Coating_350_700_nm.push_back(mT_LB1258A);
	return_N_BK7_Bi_Convex_Lenses_AR_Coating_350_700_nm.push_back(mT_LB1378A);
	return_N_BK7_Bi_Convex_Lenses_AR_Coating_350_700_nm.push_back(mT_LB1844A);
	return_N_BK7_Bi_Convex_Lenses_AR_Coating_350_700_nm.push_back(mT_LB1187A);
	return_N_BK7_Bi_Convex_Lenses_AR_Coating_350_700_nm.push_back(mT_LB1761A);
	return_N_BK7_Bi_Convex_Lenses_AR_Coating_350_700_nm.push_back(mT_LB1757A);
	return_N_BK7_Bi_Convex_Lenses_AR_Coating_350_700_nm.push_back(mT_LB1811A);
	return_N_BK7_Bi_Convex_Lenses_AR_Coating_350_700_nm.push_back(mT_LB1027A);
	return_N_BK7_Bi_Convex_Lenses_AR_Coating_350_700_nm.push_back(mT_LB1471A);
	return_N_BK7_Bi_Convex_Lenses_AR_Coating_350_700_nm.push_back(mT_LB1596A);
	return_N_BK7_Bi_Convex_Lenses_AR_Coating_350_700_nm.push_back(mT_LB1901A);
	return_N_BK7_Bi_Convex_Lenses_AR_Coating_350_700_nm.push_back(mT_LB1676A);
	return_N_BK7_Bi_Convex_Lenses_AR_Coating_350_700_nm.push_back(mT_LB1904A);
	return_N_BK7_Bi_Convex_Lenses_AR_Coating_350_700_nm.push_back(mT_LB1437A);
	return_N_BK7_Bi_Convex_Lenses_AR_Coating_350_700_nm.push_back(mT_LB1294A);
	return_N_BK7_Bi_Convex_Lenses_AR_Coating_350_700_nm.push_back(mT_LB1945A);
	return_N_BK7_Bi_Convex_Lenses_AR_Coating_350_700_nm.push_back(mT_LB1056A);
	return_N_BK7_Bi_Convex_Lenses_AR_Coating_350_700_nm.push_back(mT_LB1779A);
	return_N_BK7_Bi_Convex_Lenses_AR_Coating_350_700_nm.push_back(mT_LB1391A);
	return_N_BK7_Bi_Convex_Lenses_AR_Coating_350_700_nm.push_back(mT_LB1869A);
	return_N_BK7_Bi_Convex_Lenses_AR_Coating_350_700_nm.push_back(mT_LB1475A);
	return_N_BK7_Bi_Convex_Lenses_AR_Coating_350_700_nm.push_back(mT_LB1409A);
	return_N_BK7_Bi_Convex_Lenses_AR_Coating_350_700_nm.push_back(mT_LB1723A);
	return_N_BK7_Bi_Convex_Lenses_AR_Coating_350_700_nm.push_back(mT_LB1309A);
	return_N_BK7_Bi_Convex_Lenses_AR_Coating_350_700_nm.push_back(mT_LB1630A);
	return_N_BK7_Bi_Convex_Lenses_AR_Coating_350_700_nm.push_back(mT_LB1106A);
	return_N_BK7_Bi_Convex_Lenses_AR_Coating_350_700_nm.push_back(mT_LB1374A);
	return_N_BK7_Bi_Convex_Lenses_AR_Coating_350_700_nm.push_back(mT_LB1607A);
	return_N_BK7_Bi_Convex_Lenses_AR_Coating_350_700_nm.push_back(mT_LB1199A);
	return_N_BK7_Bi_Convex_Lenses_AR_Coating_350_700_nm.push_back(mT_LB1889A);
	return_N_BK7_Bi_Convex_Lenses_AR_Coating_350_700_nm.push_back(mT_LB1917A);
	return_N_BK7_Bi_Convex_Lenses_AR_Coating_350_700_nm.push_back(mT_LB1862A);
	return_N_BK7_Bi_Convex_Lenses_AR_Coating_350_700_nm.push_back(mT_LB1909A);
	return_N_BK7_Bi_Convex_Lenses_AR_Coating_350_700_nm.push_back(mT_LB1247A);
	return_N_BK7_Bi_Convex_Lenses_AR_Coating_350_700_nm.push_back(mT_LB1859A);

	return return_N_BK7_Bi_Convex_Lenses_AR_Coating_350_700_nm;
}
// ***


// *** N-BK7 Plano-Concave Lenses, AR Coating 350 - 700 nm
void ThorlabsLensCatalog::loadLensCatalogThorlabs_N_BK7_Plano_Concave_Lenses_AR_Coating_350_700_nm()
{
	glass glasses;
	glasses.loadGlassCatalog_Schott();

	mT_LC1975A.buildLensTwoSurfaces_Thorlabs_oneSurfacePlan(/*lens catalog*/ "thorlabs", /*catalog number*/ "LC1975-A", /*diameter*/  6.0, /* focallength*/ -24.0, /*back focal length*/ -25.3,
		/*radius*/ -12.35, /*thickness*/ 2.0, /*edge thickness*/ 2.4, /*material*/ glasses.getNBK7_S1(), /*price*/ 31.96, /*design wavelength*/ 587.6, /*free aperture CA*/ 0.9 * 6.0,
		/*max surface quality*/ 40.0, /*min surface quality*/ 20.0,	/*centration*/ 3.0,	/*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1,
		/*coating*/ "BBAR",	/*min wavelength*/ 350.0, /*max wavelength*/ 700.0);

	mT_LC1906A.buildLensTwoSurfaces_Thorlabs_oneSurfacePlan(/*lens catalog*/ "thorlabs", /*catalog number*/ "LC1906-A", /*diameter*/  9.0, /* focallength*/ -27.0,
		/*back focal length*/ -28.3, /*radius*/ -13.89, /*thickness*/ 2.0, /*edge thickness*/ 2.7, /*material*/ glasses.getNBK7_S1(), /*price*/ 30.00,
		/*design wavelength*/ 587.6, /*free aperture CA*/ 0.9 * 9.0, /*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*centration*/ 3.0,
		/*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1,/*coating*/ "BBAR",	/*min wavelength*/ 350.0, /*max wavelength*/ 700.0);

	mT_LC1054A.buildLensTwoSurfaces_Thorlabs_oneSurfacePlan(/*lens catalog*/ "thorlabs", /*catalog number*/ "LC1054-A", /*diameter*/  12.7, /* focallength*/ -25.0,
		/*back focal length*/ -27.0, /*radius*/ -12.86, /*thickness*/ 3.0, /*edge thickness*/ 4.7, /*material*/ glasses.getNBK7_S1(), /*price*/ 26.81,
		/*design wavelength*/ 587.6, /*free aperture CA*/ 0.9 * 12.7, /*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*centration*/ 3.0,
		/*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1,/*coating*/ "BBAR",	/*min wavelength*/ 350.0, /*max wavelength*/ 700.0);

	mT_LC1060A.buildLensTwoSurfaces_Thorlabs_oneSurfacePlan(/*lens catalog*/ "thorlabs", /*catalog number*/ "LC1060-A", /*diameter*/  12.7, /* focallength*/ -30.0,
		/*back focal length*/ -32.0, /*radius*/ -15.43, /*thickness*/ 3.0, /*edge thickness*/ 4.4, /*material*/ glasses.getNBK7_S1(), /*price*/ 26.56,
		/*design wavelength*/ 587.6, /*free aperture CA*/ 0.9 * 12.7, /*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*centration*/ 3.0,
		/*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1,/*coating*/ "BBAR",	/*min wavelength*/ 350.0, /*max wavelength*/ 700.0);

	mT_LC1439A.buildLensTwoSurfaces_Thorlabs_oneSurfacePlan(/*lens catalog*/ "thorlabs", /*catalog number*/ "LC1439-A", /*diameter*/  12.7, /* focallength*/ -50.0,
		/*back focal length*/ -52.3, /*radius*/ -25.73, /*thickness*/ 3.5, /*edge thickness*/ 4.3, /*material*/ glasses.getNBK7_S1(), /*price*/ 27.30,
		/*design wavelength*/ 587.6, /*free aperture CA*/ 0.9 * 12.7, /*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*centration*/ 3.0,
		/*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1,/*coating*/ "BBAR",	/*min wavelength*/ 350.0, /*max wavelength*/ 700.0);

	mT_LC1259A.buildLensTwoSurfaces_Thorlabs_oneSurfacePlan(/*lens catalog*/ "thorlabs", /*catalog number*/ "LC1259-A", /*diameter*/  25.0, /* focallength*/ -50.0,
		/*back focal length*/ -52.3, /*radius*/ -25.7, /*thickness*/ 3.5, /*edge thickness*/ 6.7, /*material*/ glasses.getNBK7_S1(), /*price*/ 28.78,
		/*design wavelength*/ 587.6, /*free aperture CA*/ 0.9 * 25.0, /*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*centration*/ 3.0,
		/*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1,/*coating*/ "BBAR",	/*min wavelength*/ 350.0, /*max wavelength*/ 700.0);

	mT_LC1258A.buildLensTwoSurfaces_Thorlabs_oneSurfacePlan(/*lens catalog*/ "thorlabs", /*catalog number*/ "LC1258-A", /*diameter*/  25.0, /* focallength*/ -75.0,
		/*back focal length*/ -77.3, /*radius*/ -38.6, /*thickness*/ 3.5, /*edge thickness*/ 5.6, /*material*/ glasses.getNBK7_S1(), /*price*/ 28.78,
		/*design wavelength*/ 587.6, /*free aperture CA*/ 0.9 * 25.0, /*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*centration*/ 3.0,
		/*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1,/*coating*/ "BBAR",	/*min wavelength*/ 350.0, /*max wavelength*/ 700.0);

	mT_LC1254A.buildLensTwoSurfaces_Thorlabs_oneSurfacePlan(/*lens catalog*/ "thorlabs", /*catalog number*/ "LC1254-A", /*diameter*/  25.0, /* focallength*/ -100.0,
		/*back focal length*/ -102.6, /*radius*/ -51.5, /*thickness*/ 4.0, /*edge thickness*/ 5.5, /*material*/ glasses.getNBK7_S1(), /*price*/ 37.14,
		/*design wavelength*/ 587.6, /*free aperture CA*/ 0.9 * 25.0, /*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*centration*/ 3.0,
		/*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1,/*coating*/ "BBAR",	/*min wavelength*/ 350.0, /*max wavelength*/ 700.0);

	mT_LC1715A.buildLensTwoSurfaces_Thorlabs_oneSurfacePlan(/*lens catalog*/ "thorlabs", /*catalog number*/ "LC1715-A", /*diameter*/  25.4, /* focallength*/ -50.0,
		/*back focal length*/ -52.3, /*radius*/ -25.73, /*thickness*/ 3.5, /*edge thickness*/ 6.9, /*material*/ glasses.getNBK7_S1(), /*price*/ 29.27,
		/*design wavelength*/ 587.6, /*free aperture CA*/ 0.9 * 25.4, /*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*centration*/ 3.0,
		/*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1,/*coating*/ "BBAR",	/*min wavelength*/ 350.0, /*max wavelength*/ 700.0);

	mT_LC1582A.buildLensTwoSurfaces_Thorlabs_oneSurfacePlan(/*lens catalog*/ "thorlabs", /*catalog number*/ "LC1582-A", /*diameter*/  25.4, /* focallength*/ -75.0,
		/*back focal length*/ -77.3, /*radius*/ -38.59, /*thickness*/ 3.5, /*edge thickness*/ 5.6, /*material*/ glasses.getNBK7_S1(), /*price*/ 29.27,
		/*design wavelength*/ 587.6, /*free aperture CA*/ 0.9 * 25.4, /*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*centration*/ 3.0,
		/*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1,/*coating*/ "BBAR",	/*min wavelength*/ 350.0, /*max wavelength*/ 700.0);

	mT_LC1120A.buildLensTwoSurfaces_Thorlabs_oneSurfacePlan(/*lens catalog*/ "thorlabs", /*catalog number*/ "LC1120-A", /*diameter*/  25.4, /* focallength*/ -100.0,
		/*back focal length*/ -102.6, /*radius*/ -51.46, /*thickness*/ 4.0, /*edge thickness*/ 5.6, /*material*/ glasses.getNBK7_S1(), /*price*/ 29.02,
		/*design wavelength*/ 587.6, /*free aperture CA*/ 0.9 * 25.4, /*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*centration*/ 3.0,
		/*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1,/*coating*/ "BBAR",	/*min wavelength*/ 350.0, /*max wavelength*/ 700.0);

	mT_LC1315A.buildLensTwoSurfaces_Thorlabs_oneSurfacePlan(/*lens catalog*/ "thorlabs", /*catalog number*/ "LC1315-A", /*diameter*/  50.8, /* focallength*/ -75.0,
		/*back focal length*/ -77.3, /*radius*/ -38.59, /*thickness*/ 3.5, /*edge thickness*/ 13.0, /*material*/ glasses.getNBK7_S1(), /*price*/ 45.00,
		/*design wavelength*/ 587.6, /*free aperture CA*/ 0.9 * 50.8, /*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*centration*/ 3.0,
		/*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1,/*coating*/ "BBAR",	/*min wavelength*/ 350.0, /*max wavelength*/ 700.0);

	mT_LC1093A.buildLensTwoSurfaces_Thorlabs_oneSurfacePlan(/*lens catalog*/ "thorlabs", /*catalog number*/ "LC1093-A", /*diameter*/  50.8, /* focallength*/ -100.0,
		/*back focal length*/ -102.6, /*radius*/ -51.46, /*thickness*/ 4.0, /*edge thickness*/ 10.7, /*material*/ glasses.getNBK7_S1(), /*price*/ 39.60,
		/*design wavelength*/ 587.6, /*free aperture CA*/ 0.9 * 50.8, /*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*centration*/ 3.0,
		/*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1,/*coating*/ "BBAR",	/*min wavelength*/ 350.0, /*max wavelength*/ 700.0);

	mT_LC1611A.buildLensTwoSurfaces_Thorlabs_oneSurfacePlan(/*lens catalog*/ "thorlabs", /*catalog number*/ "LC1611-A", /*diameter*/  50.8, /* focallength*/ -150.0,
		/*back focal length*/ -152.6, /*radius*/ -77.19, /*thickness*/ 4.0, /*edge thickness*/ 8.3, /*material*/ glasses.getNBK7_S1(), /*price*/ 39.60,
		/*design wavelength*/ 587.6, /*free aperture CA*/ 0.9 * 50.8, /*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*centration*/ 3.0,
		/*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1,/*coating*/ "BBAR",	/*min wavelength*/ 350.0, /*max wavelength*/ 700.0);


}
std::vector<LensesTwoSurfaces> ThorlabsLensCatalog::getAll_Thorlabs_N_BK7_Plano_Concave_Lenses_AR_Coating_350_700_nm()
{
	//	https://www.thorlabs.de/newgrouppage9.cfm?objectgroup_id=6509

	std::vector<LensesTwoSurfaces> return_N_BK7_Plano_Concave_Lenses_AR_Coating_350_700_nm;

	return_N_BK7_Plano_Concave_Lenses_AR_Coating_350_700_nm.push_back(mT_LC1975A);
	return_N_BK7_Plano_Concave_Lenses_AR_Coating_350_700_nm.push_back(mT_LC1906A);
	return_N_BK7_Plano_Concave_Lenses_AR_Coating_350_700_nm.push_back(mT_LC1054A);
	return_N_BK7_Plano_Concave_Lenses_AR_Coating_350_700_nm.push_back(mT_LC1060A);
	return_N_BK7_Plano_Concave_Lenses_AR_Coating_350_700_nm.push_back(mT_LC1439A);
	return_N_BK7_Plano_Concave_Lenses_AR_Coating_350_700_nm.push_back(mT_LC1259A);
	return_N_BK7_Plano_Concave_Lenses_AR_Coating_350_700_nm.push_back(mT_LC1258A);
	return_N_BK7_Plano_Concave_Lenses_AR_Coating_350_700_nm.push_back(mT_LC1254A);
	return_N_BK7_Plano_Concave_Lenses_AR_Coating_350_700_nm.push_back(mT_LC1715A);
	return_N_BK7_Plano_Concave_Lenses_AR_Coating_350_700_nm.push_back(mT_LC1582A);
	return_N_BK7_Plano_Concave_Lenses_AR_Coating_350_700_nm.push_back(mT_LC1120A);
	return_N_BK7_Plano_Concave_Lenses_AR_Coating_350_700_nm.push_back(mT_LC1315A);
	return_N_BK7_Plano_Concave_Lenses_AR_Coating_350_700_nm.push_back(mT_LC1093A);
	return_N_BK7_Plano_Concave_Lenses_AR_Coating_350_700_nm.push_back(mT_LC1611A);

	return return_N_BK7_Plano_Concave_Lenses_AR_Coating_350_700_nm;
}


// *** N-BK7 and N-SF11 Bi-Concave Lenses, AR Coating 350 - 700 nm
void ThorlabsLensCatalog::loadLensCatalogThorlabs_N_BK7_and_N_SF11_Bi_Concave_Lenses_AR_Coating_350_700_nm()
{
	glass glasses;
	glasses.loadGlassCatalog_Schott();

	/// https://www.thorlabs.de/newgrouppage9.cfm?objectgroup_id=9733
	mT_LD2746A.buildLensTwoSurfaces_thorlabs(/*lens catalog*/ "Thorlabs", /*item*/ "LD2746-A", /*diameter*/ 6.0, /* focallength*/ -6.0, /*back focal length*/ -6.4,
		/*radius first surface*/ -9.66, /*radius second surface*/ 9.66, /*thickness*/ 1.5, /*edge thickness*/ 2.5, /*material*/ glasses.getNSF11_S1(), /*price*/ 34.68, /*design wavelength*/ 587.6,
		/*free aperture CA*/ 6.0 * 0.9, /*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*centration*/ 3.0, /*max diameter tolerance*/ 0.0,	/*min diameter tolerance*/ -0.1,
		/*tolerance center thickness*/ 0.1, /*coating*/ "BBAR", /*min wavelength*/ 350.0, /*max wavelength*/ 700.0);

	mT_LD2568A.buildLensTwoSurfaces_thorlabs(/*lens catalog*/ "Thorlabs", /*item*/ "LD2568-A", /*diameter*/ 9.0, /* focallength*/ -9.0, /*back focal length*/ -9.5,
		/*radius first surface*/ -14.43, /*radius second surface*/ 14.43, /*thickness*/ 2.0, /*edge thickness*/ 3.4, /*material*/ glasses.getNSF11_S1(),
		/*price*/ 34.68, /*design wavelength*/ 587.6, /*free aperture CA*/ 9.0 * 0.9, /*max surface quality*/ 40.0, /*min surface quality*/ 20.0,
		/*centration*/ 3.0, /*max diameter tolerance*/ 0.0,	/*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1,
		/*coating*/ "BBAR", /*min wavelength*/ 350.0, /*max wavelength*/ 700.0);

	mT_LD1357A.buildLensTwoSurfaces_thorlabs(/*lens catalog*/ "Thorlabs", /*item*/ "LD1357-A", /*diameter*/ 12.7, /* focallength*/ -15.0, /*back focal length*/ -15.7,
		/*radius first surface*/ -52.09, /*radius second surface*/ 52.09, /*thickness*/ 3.5, /*edge thickness*/ 4.7, /*material*/ glasses.getNBK7_S1(),
		/*price*/ 31.96, /*design wavelength*/ 587.6, /*free aperture CA*/ 12.7 * 0.9, /*max surface quality*/ 40.0, /*min surface quality*/ 20.0,
		/*centration*/ 3.0, /*max diameter tolerance*/ 0.0,	/*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1,
		/*coating*/ "BBAR", /*min wavelength*/ 350.0, /*max wavelength*/ 700.0);

	mT_LD2060A.buildLensTwoSurfaces_thorlabs(/*lens catalog*/ "Thorlabs", /*item*/ "LD2060-A", /*diameter*/ 12.7, /* focallength*/ -50.0, /*back focal length*/ -51.0,
		/*radius first surface*/ -23.99, /*radius second surface*/ 23.99, /*thickness*/ 3.0, /*edge thickness*/ 4.3, /*material*/ glasses.getNSF11_S1(),
		/*price*/ 37.38, /*design wavelength*/ 587.6, /*free aperture CA*/ 12.7 * 0.9, /*max surface quality*/ 40.0, /*min surface quality*/ 20.0,
		/*centration*/ 3.0, /*max diameter tolerance*/ 0.0,	/*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1,
		/*coating*/ "BBAR", /*min wavelength*/ 350.0, /*max wavelength*/ 700.0);

	mT_LD2297A.buildLensTwoSurfaces_thorlabs(/*lens catalog*/ "Thorlabs", /*item*/ "LD2297-A", /*diameter*/ 25.4, /* focallength*/ -25.0, /*back focal length*/ -25.6,
		/*radius first surface*/ -39.57, /*radius second surface*/ 39.57, /*thickness*/ 3.0, /*edge thickness*/ 7.2, /*material*/ glasses.getNSF11_S1(),
		/*price*/ 41.56, /*design wavelength*/ 587.6, /*free aperture CA*/ 25.4 * 0.9, /*max surface quality*/ 40.0, /*min surface quality*/ 20.0,
		/*centration*/ 3.0, /*max diameter tolerance*/ 0.0,	/*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1,
		/*coating*/ "BBAR", /*min wavelength*/ 350.0, /*max wavelength*/ 700.0);

	mT_LD1464A.buildLensTwoSurfaces_thorlabs(/*lens catalog*/ "Thorlabs", /*item*/ "LD1464-A", /*diameter*/ 25.4, /* focallength*/ -50.0, /*back focal length*/ -50.8,
		/*radius first surface*/ -52.01, /*radius second surface*/ 52.01, /*thickness*/ 3.0, /*edge thickness*/ 6.1, /*material*/ glasses.getNBK7_S1(),
		/*price*/ 33.94, /*design wavelength*/ 587.6, /*free aperture CA*/ 25.4 * 0.9, /*max surface quality*/ 40.0, /*min surface quality*/ 20.0,
		/*centration*/ 3.0, /*max diameter tolerance*/ 0.0,	/*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1,
		/*coating*/ "BBAR", /*min wavelength*/ 350.0, /*max wavelength*/ 700.0);

	mT_LD1170A.buildLensTwoSurfaces_thorlabs(/*lens catalog*/ "Thorlabs", /*item*/ "LD1170-A", /*diameter*/ 25.4, /* focallength*/ -75.0, /*back focal length*/ -75.9,
		/*radius first surface*/ -77.85, /*radius second surface*/ 77.85, /*thickness*/ 3.5, /*edge thickness*/ 5.6, /*material*/ glasses.getNBK7_S1(),
		/*price*/ 31.96, /*design wavelength*/ 587.6, /*free aperture CA*/ 25.4 * 0.9, /*max surface quality*/ 40.0, /*min surface quality*/ 20.0,
		/*centration*/ 3.0, /*max diameter tolerance*/ 0.0,	/*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1,
		/*coating*/ "BBAR", /*min wavelength*/ 350.0, /*max wavelength*/ 700.0);

	mT_LD1613A.buildLensTwoSurfaces_thorlabs(/*lens catalog*/ "Thorlabs", /*item*/ "LD1613-A", /*diameter*/ 25.4, /* focallength*/ -100.0, /*back focal length*/ -101.0,
		/*radius first surface*/ -103.69, /*radius second surface*/ 103.69, /*thickness*/ 4.0, /*edge thickness*/ 5.6, /*material*/ glasses.getNBK7_S1(),
		/*price*/ 31.48, /*design wavelength*/ 587.6, /*free aperture CA*/ 25.4 * 0.9, /*max surface quality*/ 40.0, /*min surface quality*/ 20.0,
		/*centration*/ 3.0, /*max diameter tolerance*/ 0.0,	/*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1,
		/*coating*/ "BBAR", /*min wavelength*/ 350.0, /*max wavelength*/ 700.0);
}

std::vector<LensesTwoSurfaces> ThorlabsLensCatalog::getAll_Thorlabs_N_BK7_and_N_SF11_BiSConcave_Lenses_AR_Coating_350_700_nm()
{
	/// https://www.thorlabs.de/newgrouppage9.cfm?objectgroup_id=9733
	std::vector<LensesTwoSurfaces> return_N_BK7_and_N_SF11_BiSConcave_Lenses_AR_Coating_350_700_nm;

	return_N_BK7_and_N_SF11_BiSConcave_Lenses_AR_Coating_350_700_nm.push_back(mT_LD2746A);
	return_N_BK7_and_N_SF11_BiSConcave_Lenses_AR_Coating_350_700_nm.push_back(mT_LD2568A);
	return_N_BK7_and_N_SF11_BiSConcave_Lenses_AR_Coating_350_700_nm.push_back(mT_LD1357A);
	return_N_BK7_and_N_SF11_BiSConcave_Lenses_AR_Coating_350_700_nm.push_back(mT_LD2060A);
	return_N_BK7_and_N_SF11_BiSConcave_Lenses_AR_Coating_350_700_nm.push_back(mT_LD2297A);
	return_N_BK7_and_N_SF11_BiSConcave_Lenses_AR_Coating_350_700_nm.push_back(mT_LD1464A);
	return_N_BK7_and_N_SF11_BiSConcave_Lenses_AR_Coating_350_700_nm.push_back(mT_LD1170A);
	return_N_BK7_and_N_SF11_BiSConcave_Lenses_AR_Coating_350_700_nm.push_back(mT_LD1613A);

	return return_N_BK7_and_N_SF11_BiSConcave_Lenses_AR_Coating_350_700_nm;
}


// *** Ø1" N-BK7 Best Form Spherical Lenses, AR Coating: 350-700 nm
void ThorlabsLensCatalog::loadLensCatalogThorlabs_1Zoll_N_BK7_Best_Form_Spherical_Lenses_AR_Coating_350_700_nm()
{
	glass glasses;
	glasses.loadGlassCatalog_Schott();

	// https://www.thorlabs.de/newgrouppage9.cfm?objectgroup_id=4874
	mT_LBF254040A.buildLensTwoSurfaces_thorlabs(/*lens catalog*/ "Thorlabs", /*item*/ "LBF254-040-A", /*diameter*/ 25.4, /* focallength*/ 40.0, /*back focal length*/ -36.3,
		/*radius first surface*/ 24.02, /*radius second surface*/ -134.6, /*thickness*/ 6.5, /*edge thickness*/ 2.3, /*material*/ glasses.getNBK7_S1(), /*price*/ 51.89, /*design wavelength*/ 587.6,
		/*free aperture CA*/ 25.4 * 0.9, /*max surface quality*/ 20.0, /*min surface quality*/ 10.0, /*centration*/ 3.0, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.1,
		/*tolerance center thickness*/ 0.1, /*coating*/ "BBAR", /*min wavelength*/ 350.0, /*max wavelength*/ 700.0);

	mT_LBF254050A.buildLensTwoSurfaces_thorlabs(/*lens catalog*/ "Thorlabs", /*item*/ "LBF254-050-A", /*diameter*/ 25.4, /* focallength*/ 0.0, /*back focal length*/ -46.4,
		/*radius first surface*/ 30.06, /*radius second surface*/ -172.0, /*thickness*/ 6.5, /*edge thickness*/ 3.2, /*material*/ glasses.getNBK7_S1(), /*price*/ 51.89,
		/*design wavelength*/ 587.6, /*free aperture CA*/ 25.4 * 0.9, /*max surface quality*/ 20.0, /*min surface quality*/ 10.0, /*centration*/ 3.0,
		/*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1, /*coating*/ "BBAR",
		/*min wavelength*/ 350.0, /*max wavelength*/ 700.0);

	mT_LBF254075A.buildLensTwoSurfaces_thorlabs(/*lens catalog*/ "Thorlabs", /*item*/ "LBF254-075-A", /*diameter*/ 25.4, /* focallength*/ 75.0, /*back focal length*/ -72.1,
		/*radius first surface*/ 44.5, /*radius second surface*/ -289.0, /*thickness*/ 5.0, /*edge thickness*/ 2.9, /*material*/ glasses.getNBK7_S1(), /*price*/ 51.89,
		/*design wavelength*/ 587.6, /*free aperture CA*/ 25.4 * 0.9, /*max surface quality*/ 20.0, /*min surface quality*/ 10.0, /*centration*/ 3.0,
		/*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1, /*coating*/ "BBAR",
		/*min wavelength*/ 350.0, /*max wavelength*/ 700.0);

	mT_LBF254100A.buildLensTwoSurfaces_thorlabs(/*lens catalog*/ "Thorlabs", /*item*/ "LBF254-100-A", /*diameter*/ 25.4, /* focallength*/ 100.0, /*back focal length*/ -97.3,
		/*radius first surface*/ 60.02, /*radius second surface*/ -353.3, /*thickness*/ 4.0, /*edge thickness*/ 2.4, /*material*/ glasses.getNBK7_S1(), /*price*/ 51.89,
		/*design wavelength*/ 587.6, /*free aperture CA*/ 25.4 * 0.9, /*max surface quality*/ 20.0, /*min surface quality*/ 10.0, /*centration*/ 3.0,
		/*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1, /*coating*/ "BBAR",
		/*min wavelength*/ 350.0, /*max wavelength*/ 700.0);

	mT_LBF254150A.buildLensTwoSurfaces_thorlabs(/*lens catalog*/ "Thorlabs", /*item*/ "LBF254-150-A", /*diameter*/ 25.4, /* focallength*/ 150.0, /*back focal length*/ -147.5,
		/*radius first surface*/ 89.35, /*radius second surface*/ -570.49, /*thickness*/ 4.0, /*edge thickness*/ 3.0, /*material*/ glasses.getNBK7_S1(), /*price*/ 51.89,
		/*design wavelength*/ 587.6, /*free aperture CA*/ 25.4 * 0.9, /*max surface quality*/ 20.0, /*min surface quality*/ 10.0, /*centration*/ 3.0,
		/*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1, /*coating*/ "BBAR",
		/*min wavelength*/ 350.0, /*max wavelength*/ 700.0);

	mT_LBF254200A.buildLensTwoSurfaces_thorlabs(/*lens catalog*/ "Thorlabs", /*item*/ "LBF254-200-A", /*diameter*/ 25.4, /* focallength*/ 200.0, /*back focal length*/ -197.8,
		/*radius first surface*/ 121.5, /*radius second surface*/ -684.5, /*thickness*/ 4.0, /*edge thickness*/ 3.2, /*material*/ glasses.getNBK7_S1(), /*price*/ 51.89,
		/*design wavelength*/ 587.6, /*free aperture CA*/ 25.4 * 0.9, /*max surface quality*/ 20.0, /*min surface quality*/ 10.0, /*centration*/ 3.0,
		/*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1, /*coating*/ "BBAR",
		/*min wavelength*/ 350.0, /*max wavelength*/ 700.0);

}
std::vector<LensesTwoSurfaces> ThorlabsLensCatalog::getAll_Thorlabs_1Zoll_N_BK7_Best_Form_Spherical_Lenses_AR_Coating_350_700_nm()
{
	// https://www.thorlabs.de/newgrouppage9.cfm?objectgroup_id=4874

	std::vector<LensesTwoSurfaces> return_1Zoll_N_BK7_Best_Form_Spherical_Lenses_AR_Coating_350_700_nm;

	return_1Zoll_N_BK7_Best_Form_Spherical_Lenses_AR_Coating_350_700_nm.push_back(mT_LBF254040A);
	return_1Zoll_N_BK7_Best_Form_Spherical_Lenses_AR_Coating_350_700_nm.push_back(mT_LBF254050A);
	return_1Zoll_N_BK7_Best_Form_Spherical_Lenses_AR_Coating_350_700_nm.push_back(mT_LBF254075A);
	return_1Zoll_N_BK7_Best_Form_Spherical_Lenses_AR_Coating_350_700_nm.push_back(mT_LBF254100A);
	return_1Zoll_N_BK7_Best_Form_Spherical_Lenses_AR_Coating_350_700_nm.push_back(mT_LBF254150A);
	return_1Zoll_N_BK7_Best_Form_Spherical_Lenses_AR_Coating_350_700_nm.push_back(mT_LBF254200A);

	return return_1Zoll_N_BK7_Best_Form_Spherical_Lenses_AR_Coating_350_700_nm;
}

// *** N-BK7 Positive Meniscus Lenses
void ThorlabsLensCatalog::loadLensCatalogThorlabs_N_BK7_Positive_Meniscus_Lenses_Uncoated()
{

	glass glasses;
	glasses.loadGlassCatalog_Schott();

	// https://www.thorlabs.de/newgrouppage9.cfm?objectgroup_id=130
	mT_LE1234.buildLensTwoSurfaces_thorlabs_Uncoated(/*lens catalog*/ "Thorlabs", /*item*/ "LE1234", /*diameter*/ 25.4, /* focallength*/ 100.0, /*back focal length*/ 95.6,
		/*radius first surface*/ 32.14, /*radius second surface*/ 82.23, /*thickness*/ 3.59, /*edge thickness*/ 2.0, /*material*/ glasses.getNBK7_S1(), /*price*/ 19.97,
		/*design wavelength*/ 587.6, /*free aperture CA*/ 0.9 * 25.4, /*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*centration*/ 3.0,
		/*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1);

	mT_LE1234A.buildLensTwoSurfaces_thorlabs_coated(/*lens catalog*/ "Thorlabs", /*item*/ "LE1234-A", /*diameter*/ 25.4, /* focallength*/ 100.0, /*back focal length*/ 95.6,
		/*radius first surface*/ 32.14, /*radius second surface*/ 82.23, /*thickness*/ 3.59, /*edge thickness*/ 2.0, /*material*/ glasses.getNBK7_S1(), /*price*/ 29.76,
		/*design wavelength*/ 587.6, /*free aperture CA*/ 0.9 * 25.4, /*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*centration*/ 3.0,
		/*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1,
		/*coating*/ "BBAR",	/*min wavelength coating*/ 350.0, /*max wavelength coating*/ 700.0);

	mT_LE1234B.buildLensTwoSurfaces_thorlabs_coated(/*lens catalog*/ "Thorlabs", /*item*/ "LE1234-B", /*diameter*/ 25.4, /* focallength*/ 100.0, /*back focal length*/ 95.6,
		/*radius first surface*/ 32.14, /*radius second surface*/ 82.23, /*thickness*/ 3.59, /*edge thickness*/ 2.0, /*material*/ glasses.getNBK7_S1(), /*price*/ 29.76,
		/*design wavelength*/ 587.6, /*free aperture CA*/ 0.9 * 25.4, /*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*centration*/ 3.0,
		/*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1,
		/*coating*/ "BBAR",	/*min wavelength coating*/ 650.0, /*max wavelength coating*/ 1050.0);

	mT_LE1234C.buildLensTwoSurfaces_thorlabs_coated(/*lens catalog*/ "Thorlabs", /*item*/ "LE1234-C", /*diameter*/ 25.4, /* focallength*/ 100.0, /*back focal length*/ 95.6,
		/*radius first surface*/ 32.14, /*radius second surface*/ 82.23, /*thickness*/ 3.59, /*edge thickness*/ 2.0, /*material*/ glasses.getNBK7_S1(), /*price*/ 32.96,
		/*design wavelength*/ 587.6, /*free aperture CA*/ 0.9 * 25.4, /*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*centration*/ 3.0,
		/*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1,
		/*coating*/ "BBAR",	/*min wavelength coating*/ 1050.0, /*max wavelength coating*/ 1700.0);

	mT_LE1156.buildLensTwoSurfaces_thorlabs_Uncoated(/*lens catalog*/ "Thorlabs", /*item*/ "LE1156", /*diameter*/ 25.4, /* focallength*/ 125.0, /*back focal length*/ 121.2,
		/*radius first surface*/ 40.6, /*radius second surface*/ 106.9, /*thickness*/ 3.3, /*edge thickness*/ 2.0, /*material*/ glasses.getNBK7_S1(), /*price*/ 19.87,
		/*design wavelength*/ 587.6, /*free aperture CA*/ 0.9 * 25.4, /*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*centration*/ 3.0,
		/*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1);

	mT_LE1156A.buildLensTwoSurfaces_thorlabs_coated(/*lens catalog*/ "Thorlabs", /*item*/ "LE1156-A", /*diameter*/ 25.4, /* focallength*/ 125.0, /*back focal length*/ 121.2,
		/*radius first surface*/ 40.6, /*radius second surface*/ 106.9, /*thickness*/ 3.3, /*edge thickness*/ 2.0, /*material*/ glasses.getNBK7_S1(), /*price*/ 29.52,
		/*design wavelength*/ 587.6, /*free aperture CA*/ 0.9 * 25.4, /*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*centration*/ 3.0,
		/*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1, /*coating*/ "BBAR",	/*min wavelength coating*/ 350.0, /*max wavelength coating*/ 700.0);

	mT_LE1156B.buildLensTwoSurfaces_thorlabs_coated(/*lens catalog*/ "Thorlabs", /*item*/ "LE1156-B", /*diameter*/ 25.4, /* focallength*/ 125.0, /*back focal length*/ 121.2,
		/*radius first surface*/ 40.6, /*radius second surface*/ 106.9, /*thickness*/ 3.3, /*edge thickness*/ 2.0, /*material*/ glasses.getNBK7_S1(), /*price*/ 29.52,
		/*design wavelength*/ 587.6, /*free aperture CA*/ 0.9 * 25.4, /*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*centration*/ 3.0,
		/*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1,
		/*coating*/ "BBAR",	/*min wavelength coating*/ 650.0, /*max wavelength coating*/ 1050.0);

	mT_LE1156C.buildLensTwoSurfaces_thorlabs_coated(/*lens catalog*/ "Thorlabs", /*item*/ "LE1156-C", /*diameter*/ 25.4, /* focallength*/ 125.0, /*back focal length*/ 121.2,
		/*radius first surface*/ 40.6, /*radius second surface*/ 106.9, /*thickness*/ 3.3, /*edge thickness*/ 2.0, /*material*/ glasses.getNBK7_S1(), /*price*/ 32.71,
		/*design wavelength*/ 587.6, /*free aperture CA*/ 0.9 * 25.4, /*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*centration*/ 3.0,
		/*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1,
		/*coating*/ "BBAR",	/*min wavelength coating*/ 1050.0, /*max wavelength coating*/ 1700.0);

	mT_LE1104.buildLensTwoSurfaces_thorlabs_Uncoated(/*lens catalog*/ "Thorlabs", /*item*/ "LE1104", /*diameter*/ 25.4, /* focallength*/ 150.0, /*back focal length*/ 146.3,
		/*radius first surface*/ 49.06, /*radius second surface*/ 131.56, /*thickness*/ 3.05, /*edge thickness*/ 2.0, /*material*/ glasses.getNBK7_S1(), /*price*/ 19.87,
		/*design wavelength*/ 587.6, /*free aperture CA*/ 0.9 * 25.4, /*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*centration*/ 3.0,
		/*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1);

	mT_LE1104A.buildLensTwoSurfaces_thorlabs_coated(/*lens catalog*/ "Thorlabs", /*item*/ "LE1104-A", /*diameter*/ 25.4, /* focallength*/ 150.0, /*back focal length*/ 146.3,
		/*radius first surface*/ 49.06, /*radius second surface*/ 131.56, /*thickness*/ 3.05, /*edge thickness*/ 2.0, /*material*/ glasses.getNBK7_S1(), /*price*/ 29.52,
		/*design wavelength*/ 587.6, /*free aperture CA*/ 0.9 * 25.4, /*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*centration*/ 3.0,
		/*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1,
		/*coating*/ "BBAR",	/*min wavelength coating*/ 350.0, /*max wavelength coating*/ 700.0);

	mT_LE1104B.buildLensTwoSurfaces_thorlabs_coated(/*lens catalog*/ "Thorlabs", /*item*/ "LE1104-B", /*diameter*/ 25.4, /* focallength*/ 150.0, /*back focal length*/ 146.3,
		/*radius first surface*/ 49.06, /*radius second surface*/ 131.56, /*thickness*/ 3.05, /*edge thickness*/ 2.0, /*material*/ glasses.getNBK7_S1(), /*price*/ 29.52,
		/*design wavelength*/ 587.6, /*free aperture CA*/ 0.9 * 25.4, /*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*centration*/ 3.0,
		/*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1,
		/*coating*/ "BBAR",	/*min wavelength coating*/ 650.0, /*max wavelength coating*/ 1050.0);

	mT_LE1104C.buildLensTwoSurfaces_thorlabs_coated(/*lens catalog*/ "Thorlabs", /*item*/ "LE1104-C", /*diameter*/ 25.4, /* focallength*/ 150.0, /*back focal length*/ 146.3,
		/*radius first surface*/ 49.06, /*radius second surface*/ 131.56, /*thickness*/ 3.05, /*edge thickness*/ 2.0, /*material*/ glasses.getNBK7_S1(), /*price*/ 32.71,
		/*design wavelength*/ 587.6, /*free aperture CA*/ 0.9 * 25.4, /*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*centration*/ 3.0,
		/*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1,
		/*coating*/ "BBAR",	/*min wavelength coating*/ 1050.0, /*max wavelength coating*/ 1700.0);

	mT_LE1202.buildLensTwoSurfaces_thorlabs_Uncoated(/*lens catalog*/ "Thorlabs", /*item*/ "LE1202", /*diameter*/ 25.4, /* focallength*/ 200.0, /*back focal length*/ 196.5,
		/*radius first surface*/ 66.15, /*radius second surface*/ 182.19, /*thickness*/ 2.79, /*edge thickness*/ 2.0, /*material*/ glasses.getNBK7_S1(), /*price*/ 19.67,
		/*design wavelength*/ 587.6, /*free aperture CA*/ 0.9 * 25.4, /*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*centration*/ 3.0,
		/*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1);

	mT_LE1202A.buildLensTwoSurfaces_thorlabs_coated(/*lens catalog*/ "Thorlabs", /*item*/ "LE1202-A", /*diameter*/ 25.4, /* focallength*/ 200.0, /*back focal length*/ 196.5,
		/*radius first surface*/ 66.15, /*radius second surface*/ 182.19, /*thickness*/ 2.79, /*edge thickness*/ 2.0, /*material*/ glasses.getNBK7_S1(), /*price*/ 29.52,
		/*design wavelength*/ 587.6, /*free aperture CA*/ 0.9 * 25.4, /*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*centration*/ 3.0,
		/*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1,
		/*coating*/ "BBAR",	/*min wavelength coating*/ 350.0, /*max wavelength coating*/ 700.0);

	mT_LE1202B.buildLensTwoSurfaces_thorlabs_coated(/*lens catalog*/ "Thorlabs", /*item*/ "LE1202-B", /*diameter*/ 25.4, /* focallength*/ 200.0, /*back focal length*/ 196.5,
		/*radius first surface*/ 66.15, /*radius second surface*/ 182.19, /*thickness*/ 2.79, /*edge thickness*/ 2.0, /*material*/ glasses.getNBK7_S1(), /*price*/ 29.52,
		/*design wavelength*/ 587.6, /*free aperture CA*/ 0.9 * 25.4, /*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*centration*/ 3.0,
		/*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1,
		/*coating*/ "BBAR",	/*min wavelength coating*/ 650.0, /*max wavelength coating*/ 1050.0);

	mT_LE1202C.buildLensTwoSurfaces_thorlabs_coated(/*lens catalog*/ "Thorlabs", /*item*/ "LE1202-C", /*diameter*/ 25.4, /* focallength*/ 200.0, /*back focal length*/ 196.5,
		/*radius first surface*/ 66.15, /*radius second surface*/ 182.19, /*thickness*/ 2.79, /*edge thickness*/ 2.0, /*material*/ glasses.getNBK7_S1(), /*price*/ 32.46,
		/*design wavelength*/ 587.6, /*free aperture CA*/ 0.9 * 25.4, /*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*centration*/ 3.0,
		/*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1,
		/*coating*/ "BBAR",	/*min wavelength coating*/ 1050.0, /*max wavelength coating*/ 1700.0);

	mT_LE1929.buildLensTwoSurfaces_thorlabs_Uncoated(/*lens catalog*/ "Thorlabs", /*item*/ "LE1929", /*diameter*/ 25.4, /* focallength*/ 300.0, /*back focal length*/ 296.5,
		/*radius first surface*/ 100.89, /*radius second surface*/ 288.2, /*thickness*/ 2.52, /*edge thickness*/ 2.0, /*material*/ glasses.getNBK7_S1(), /*price*/ 23.32,
		/*design wavelength*/ 587.6, /*free aperture CA*/ 0.9 * 25.4, /*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*centration*/ 3.0,
		/*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1);

	mT_LE1929A.buildLensTwoSurfaces_thorlabs_coated(/*lens catalog*/ "Thorlabs", /*item*/ "LE1929-A", /*diameter*/ 25.4, /* focallength*/ 300.0, /*back focal length*/ 296.5,
		/*radius first surface*/ 100.89, /*radius second surface*/ 288.2, /*thickness*/ 2.52, /*edge thickness*/ 2.0, /*material*/ glasses.getNBK7_S1(), /*price*/ 32.96,
		/*design wavelength*/ 587.6, /*free aperture CA*/ 0.9 * 25.4, /*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*centration*/ 3.0,
		/*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1,
		/*coating*/ "BBAR",	/*min wavelength coating*/ 350.0, /*max wavelength coating*/ 700.0);

	mT_LE1929B.buildLensTwoSurfaces_thorlabs_coated(/*lens catalog*/ "Thorlabs", /*item*/ "LE1929-B", /*diameter*/ 25.4, /* focallength*/ 300.0, /*back focal length*/ 296.5,
		/*radius first surface*/ 100.89, /*radius second surface*/ 288.2, /*thickness*/ 2.52, /*edge thickness*/ 2.0, /*material*/ glasses.getNBK7_S1(), /*price*/ 32.96,
		/*design wavelength*/ 587.6, /*free aperture CA*/ 0.9 * 25.4, /*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*centration*/ 3.0,
		/*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1,
		/*coating*/ "BBAR",	/*min wavelength coating*/ 650.0, /*max wavelength coating*/ 1050.0);

	mT_LE1929C.buildLensTwoSurfaces_thorlabs_coated(/*lens catalog*/ "Thorlabs", /*item*/ "LE1929-C", /*diameter*/ 25.4, /* focallength*/ 300.0, /*back focal length*/ 296.5,
		/*radius first surface*/ 100.89, /*radius second surface*/ 288.2, /*thickness*/ 2.52, /*edge thickness*/ 2.0, /*material*/ glasses.getNBK7_S1(), /*price*/ 36.15,
		/*design wavelength*/ 587.6, /*free aperture CA*/ 0.9 * 25.4, /*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*centration*/ 3.0,
		/*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1,
		/*coating*/ "BBAR",	/*min wavelength coating*/ 1050.0, /*max wavelength coating*/ 1700.0);

	mT_LE1076.buildLensTwoSurfaces_thorlabs_Uncoated(/*lens catalog*/ "Thorlabs", /*item*/ "LE1076", /*diameter*/ 50.8, /* focallength*/ 100.0, /*back focal length*/ 88.8,
		/*radius first surface*/ 30.34, /*radius second surface*/ 65.8, /*thickness*/ 9.7, /*edge thickness*/ 1.1, /*material*/ glasses.getNBK7_S1(), /*price*/ 38.12,
		/*design wavelength*/ 587.6, /*free aperture CA*/ 0.9 * 50.8, /*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*centration*/ 3.0,
		/*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1);

	mT_LE1076A.buildLensTwoSurfaces_thorlabs_coated(/*lens catalog*/ "Thorlabs", /*item*/ "LE1076-A", /*diameter*/ 50.8, /* focallength*/ 100.0, /*back focal length*/ 88.8,
		/*radius first surface*/ 30.34, /*radius second surface*/ 65.8, /*thickness*/ 9.7, /*edge thickness*/ 1.1, /*material*/ glasses.getNBK7_S1(), /*price*/ 47.70,
		/*design wavelength*/ 587.6, /*free aperture CA*/ 0.9 * 50.8, /*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*centration*/ 3.0,
		/*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1,
		/*coating*/ "BBAR",	/*min wavelength coating*/ 350.0, /*max wavelength coating*/ 700.0);

	mT_LE1076B.buildLensTwoSurfaces_thorlabs_coated(/*lens catalog*/ "Thorlabs", /*item*/ "LE1076-B", /*diameter*/ 50.8, /* focallength*/ 100.0, /*back focal length*/ 88.8,
		/*radius first surface*/ 30.34, /*radius second surface*/ 65.8, /*thickness*/ 9.7, /*edge thickness*/ 1.1, /*material*/ glasses.getNBK7_S1(), /*price*/ 47.70,
		/*design wavelength*/ 587.6, /*free aperture CA*/ 0.9 * 50.8, /*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*centration*/ 3.0,
		/*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1,
		/*coating*/ "BBAR",	/*min wavelength coating*/ 650.0, /*max wavelength coating*/ 1050.0);

	mT_LE1076C.buildLensTwoSurfaces_thorlabs_coated(/*lens catalog*/ "Thorlabs", /*item*/ "LE1076-C", /*diameter*/ 50.8, /* focallength*/ 100.0, /*back focal length*/ 88.8,
		/*radius first surface*/ 30.34, /*radius second surface*/ 65.8, /*thickness*/ 9.7, /*edge thickness*/ 1.1, /*material*/ glasses.getNBK7_S1(), /*price*/ 50.90,
		/*design wavelength*/ 587.6, /*free aperture CA*/ 0.9 * 50.8, /*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*centration*/ 3.0,
		/*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1,
		/*coating*/ "BBAR",	/*min wavelength coating*/ 1050.0, /*max wavelength coating*/ 1700.0);

	mT_LE1418.buildLensTwoSurfaces_thorlabs_Uncoated(/*lens catalog*/ "Thorlabs", /*item*/ "LE1418", /*diameter*/ 50.8, /* focallength*/ 150.0, /*back focal length*/ 141.7,
		/*radius first surface*/ 47.87, /*radius second surface*/ 119.32, /*thickness*/ 7.29, /*edge thickness*/ 2.7, /*material*/ glasses.getNBK7_S1(), /*price*/ 39.11,
		/*design wavelength*/ 587.6, /*free aperture CA*/ 0.9 * 50.8, /*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*centration*/ 3.0,
		/*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1);

	mT_LE1418A.buildLensTwoSurfaces_thorlabs_coated(/*lens catalog*/ "Thorlabs", /*item*/ "LE1418-A", /*diameter*/ 50.8, /* focallength*/ 150.0, /*back focal length*/ 141.7,
		/*radius first surface*/ 47.87, /*radius second surface*/ 119.32, /*thickness*/ 7.29, /*edge thickness*/ 2.7, /*material*/ glasses.getNBK7_S1(), /*price*/ 48.69,
		/*design wavelength*/ 587.6, /*free aperture CA*/ 0.9 * 50.8, /*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*centration*/ 3.0,
		/*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1,
		/*coating*/ "BBAR",	/*min wavelength coating*/ 350.0, /*max wavelength coating*/ 700.0);

	mT_LE1418B.buildLensTwoSurfaces_thorlabs_coated(/*lens catalog*/ "Thorlabs", /*item*/ "LE1418-B", /*diameter*/ 50.8, /* focallength*/ 150.0, /*back focal length*/ 141.7,
		/*radius first surface*/ 47.87, /*radius second surface*/ 119.32, /*thickness*/ 7.29, /*edge thickness*/ 2.7, /*material*/ glasses.getNBK7_S1(), /*price*/ 48.69,
		/*design wavelength*/ 587.6, /*free aperture CA*/ 0.9 * 50.8, /*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*centration*/ 3.0,
		/*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1,
		/*coating*/ "BBAR",	/*min wavelength coating*/ 650.0, /*max wavelength coating*/ 1050.0);

	mT_LE1418C.buildLensTwoSurfaces_thorlabs_coated(/*lens catalog*/ "Thorlabs", /*item*/ "LE1418-C", /*diameter*/ 50.8, /* focallength*/ 150.0, /*back focal length*/ 141.7,
		/*radius first surface*/ 47.87, /*radius second surface*/ 119.32, /*thickness*/ 7.29, /*edge thickness*/ 2.7, /*material*/ glasses.getNBK7_S1(), /*price*/ 51.89,
		/*design wavelength*/ 587.6, /*free aperture CA*/ 0.9 * 50.8, /*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*centration*/ 3.0,
		/*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1,
		/*coating*/ "BBAR",	/*min wavelength coating*/ 1050.0, /*max wavelength coating*/ 1700.0);

	mT_LE1015.buildLensTwoSurfaces_thorlabs_Uncoated(/*lens catalog*/ "Thorlabs", /*item*/ "LE1015", /*diameter*/ 50.8, /* focallength*/ 200.0, /*back focal length*/ 192.9,
		/*radius first surface*/ 65.16, /*radius second surface*/ 171.6, /*thickness*/ 6.18, /*edge thickness*/ 2.9, /*material*/ glasses.getNBK7_S1(), /*price*/ 44.27,
		/*design wavelength*/ 587.6, /*free aperture CA*/ 0.9 * 50.8, /*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*centration*/ 3.0,
		/*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1);

	mT_LE1015A.buildLensTwoSurfaces_thorlabs_coated(/*lens catalog*/ "Thorlabs", /*item*/ "LE1015-A", /*diameter*/ 50.8, /* focallength*/ 200.0, /*back focal length*/ 192.9,
		/*radius first surface*/ 65.16, /*radius second surface*/ 171.6, /*thickness*/ 6.18, /*edge thickness*/ 2.9, /*material*/ glasses.getNBK7_S1(), /*price*/ 54.09,
		/*design wavelength*/ 587.6, /*free aperture CA*/ 0.9 * 50.8, /*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*centration*/ 3.0,
		/*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1,
		/*coating*/ "BBAR",	/*min wavelength coating*/ 350.0, /*max wavelength coating*/ 700.0);

	mT_LE1015B.buildLensTwoSurfaces_thorlabs_coated(/*lens catalog*/ "Thorlabs", /*item*/ "LE1015-B", /*diameter*/ 50.8, /* focallength*/ 200.0, /*back focal length*/ 192.9,
		/*radius first surface*/ 65.16, /*radius second surface*/ 171.6, /*thickness*/ 6.18, /*edge thickness*/ 2.9, /*material*/ glasses.getNBK7_S1(), /*price*/ 54.09,
		/*design wavelength*/ 587.6, /*free aperture CA*/ 0.9 * 50.8, /*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*centration*/ 3.0,
		/*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1,
		/*coating*/ "BBAR",	/*min wavelength coating*/ 650.0, /*max wavelength coating*/ 1050.0);

	mT_LE1015C.buildLensTwoSurfaces_thorlabs_coated(/*lens catalog*/ "Thorlabs", /*item*/ "LE1015-C", /*diameter*/ 50.8, /* focallength*/ 200.0, /*back focal length*/ 192.9,
		/*radius first surface*/ 65.16, /*radius second surface*/ 171.6, /*thickness*/ 6.18, /*edge thickness*/ 2.9, /*material*/ glasses.getNBK7_S1(), /*price*/ 57.30,
		/*design wavelength*/ 587.6, /*free aperture CA*/ 0.9 * 50.8, /*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*centration*/ 3.0,
		/*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1,
		/*coating*/ "BBAR",	/*min wavelength coating*/ 1050.0, /*max wavelength coating*/ 1700.0);

	mT_LE1613.buildLensTwoSurfaces_thorlabs_Uncoated(/*lens catalog*/ "Thorlabs", /*item*/ "LE1613", /*diameter*/ 50.8, /* focallength*/ 250.0, /*back focal length*/ 243.5,
		/*radius first surface*/ 82.54, /*radius second surface*/ 224.67, /*thickness*/ 5.53, /*edge thickness*/ 2.9, /*material*/ glasses.getNBK7_S1(), /*price*/ 41.56,
		/*design wavelength*/ 587.6, /*free aperture CA*/ 0.9 * 50.8, /*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*centration*/ 3.0,
		/*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1);

	mT_LE1613A.buildLensTwoSurfaces_thorlabs_coated(/*lens catalog*/ "Thorlabs", /*item*/ "LE1613-A", /*diameter*/ 50.8, /* focallength*/ 250.0, /*back focal length*/ 243.5,
		/*radius first surface*/ 82.54, /*radius second surface*/ 224.67, /*thickness*/ 5.53, /*edge thickness*/ 2.9, /*material*/ glasses.getNBK7_S1(), /*price*/ 51.15,
		/*design wavelength*/ 587.6, /*free aperture CA*/ 0.9 * 50.8, /*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*centration*/ 3.0,
		/*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1,
		/*coating*/ "BBAR",	/*min wavelength coating*/ 350.0, /*max wavelength coating*/ 700.0);

	mT_LE1613B.buildLensTwoSurfaces_thorlabs_coated(/*lens catalog*/ "Thorlabs", /*item*/ "LE1613-B", /*diameter*/ 50.8, /* focallength*/ 250.0, /*back focal length*/ 243.5,
		/*radius first surface*/ 82.54, /*radius second surface*/ 224.67, /*thickness*/ 5.53, /*edge thickness*/ 2.9, /*material*/ glasses.getNBK7_S1(), /*price*/ 51.15,
		/*design wavelength*/ 587.6, /*free aperture CA*/ 0.9 * 50.8, /*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*centration*/ 3.0,
		/*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1,
		/*coating*/ "BBAR",	/*min wavelength coating*/ 650.0, /*max wavelength coating*/ 1050.0);

	mT_LE1613C.buildLensTwoSurfaces_thorlabs_coated(/*lens catalog*/ "Thorlabs", /*item*/ "LE1613-C", /*diameter*/ 50.8, /* focallength*/ 250.0, /*back focal length*/ 243.5,
		/*radius first surface*/ 82.54, /*radius second surface*/ 224.67, /*thickness*/ 5.53, /*edge thickness*/ 2.9, /*material*/ glasses.getNBK7_S1(), /*price*/ 54.35,
		/*design wavelength*/ 587.6, /*free aperture CA*/ 0.9 * 50.8, /*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*centration*/ 3.0,
		/*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1,
		/*coating*/ "BBAR",	/*min wavelength coating*/ 1050.0, /*max wavelength coating*/ 1700.0);

	mT_LE1985.buildLensTwoSurfaces_thorlabs_Uncoated(/*lens catalog*/ "Thorlabs", /*item*/ "LE1985", /*diameter*/ 50.8, /* focallength*/ 300.0, /*back focal length*/ 293.8,
		/*radius first surface*/ 100.08, /*radius second surface*/ 279.12, /*thickness*/ 5.1, /*edge thickness*/ 3.0, /*material*/ glasses.getNBK7_S1(), /*price*/ 35.17,
		/*design wavelength*/ 587.6, /*free aperture CA*/ 0.9 * 50.8, /*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*centration*/ 3.0,
		/*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1);

	mT_LE1985A.buildLensTwoSurfaces_thorlabs_coated(/*lens catalog*/ "Thorlabs", /*item*/ "LE1985-A", /*diameter*/ 50.8, /* focallength*/ 300.0, /*back focal length*/ 293.8,
		/*radius first surface*/ 100.08, /*radius second surface*/ 279.12, /*thickness*/ 5.1, /*edge thickness*/ 3.0, /*material*/ glasses.getNBK7_S1(), /*price*/ 45.00,
		/*design wavelength*/ 587.6, /*free aperture CA*/ 0.9 * 50.8, /*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*centration*/ 3.0,
		/*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1,
		/*coating*/ "BBAR",	/*min wavelength coating*/ 350.0, /*max wavelength coating*/ 700.0);

	mT_LE1985B.buildLensTwoSurfaces_thorlabs_coated(/*lens catalog*/ "Thorlabs", /*item*/ "LE1985-B", /*diameter*/ 50.8, /* focallength*/ 300.0, /*back focal length*/ 293.8,
		/*radius first surface*/ 100.08, /*radius second surface*/ 279.12, /*thickness*/ 5.1, /*edge thickness*/ 3.0, /*material*/ glasses.getNBK7_S1(), /*price*/ 45.00,
		/*design wavelength*/ 587.6, /*free aperture CA*/ 0.9 * 50.8, /*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*centration*/ 3.0,
		/*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1,
		/*coating*/ "BBAR",	/*min wavelength coating*/ 650.0, /*max wavelength coating*/ 1050.0);

	mT_LE1985C.buildLensTwoSurfaces_thorlabs_coated(/*lens catalog*/ "Thorlabs", /*item*/ "LE1985-C", /*diameter*/ 50.8, /* focallength*/ 300.0, /*back focal length*/ 293.8,
		/*radius first surface*/ 100.08, /*radius second surface*/ 279.12, /*thickness*/ 5.1, /*edge thickness*/ 3.0, /*material*/ glasses.getNBK7_S1(), /*price*/ 47.96,
		/*design wavelength*/ 587.6, /*free aperture CA*/ 0.9 * 50.8, /*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*centration*/ 3.0,
		/*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1,
		/*coating*/ "BBAR",	/*min wavelength coating*/ 1050.0, /*max wavelength coating*/ 1700.0);
}

std::vector<LensesTwoSurfaces> ThorlabsLensCatalog::getAll_Thorlabs_N_BK7_Positive_Meniscus_Lenses_Uncoated()
{
	// https://www.thorlabs.de/newgrouppage9.cfm?objectgroup_id=130
	std::vector<LensesTwoSurfaces> return_1_N_BK7_Positive_Meniscus_Lensesm;

	return_1_N_BK7_Positive_Meniscus_Lensesm.push_back(mT_LE1234);
	return_1_N_BK7_Positive_Meniscus_Lensesm.push_back(mT_LE1234A);
	return_1_N_BK7_Positive_Meniscus_Lensesm.push_back(mT_LE1234B);
	return_1_N_BK7_Positive_Meniscus_Lensesm.push_back(mT_LE1234C);
	return_1_N_BK7_Positive_Meniscus_Lensesm.push_back(mT_LE1156);
	return_1_N_BK7_Positive_Meniscus_Lensesm.push_back(mT_LE1156A);
	return_1_N_BK7_Positive_Meniscus_Lensesm.push_back(mT_LE1156B);
	return_1_N_BK7_Positive_Meniscus_Lensesm.push_back(mT_LE1156C);
	return_1_N_BK7_Positive_Meniscus_Lensesm.push_back(mT_LE1104);
	return_1_N_BK7_Positive_Meniscus_Lensesm.push_back(mT_LE1104A);
	return_1_N_BK7_Positive_Meniscus_Lensesm.push_back(mT_LE1104B);
	return_1_N_BK7_Positive_Meniscus_Lensesm.push_back(mT_LE1104C);
	return_1_N_BK7_Positive_Meniscus_Lensesm.push_back(mT_LE1202);
	return_1_N_BK7_Positive_Meniscus_Lensesm.push_back(mT_LE1202A);
	return_1_N_BK7_Positive_Meniscus_Lensesm.push_back(mT_LE1202B);
	return_1_N_BK7_Positive_Meniscus_Lensesm.push_back(mT_LE1202C);
	return_1_N_BK7_Positive_Meniscus_Lensesm.push_back(mT_LE1929);
	return_1_N_BK7_Positive_Meniscus_Lensesm.push_back(mT_LE1929A);
	return_1_N_BK7_Positive_Meniscus_Lensesm.push_back(mT_LE1929B);
	return_1_N_BK7_Positive_Meniscus_Lensesm.push_back(mT_LE1929C);
	return_1_N_BK7_Positive_Meniscus_Lensesm.push_back(mT_LE1076);
	return_1_N_BK7_Positive_Meniscus_Lensesm.push_back(mT_LE1076A);
	return_1_N_BK7_Positive_Meniscus_Lensesm.push_back(mT_LE1076B);
	return_1_N_BK7_Positive_Meniscus_Lensesm.push_back(mT_LE1076C);
	return_1_N_BK7_Positive_Meniscus_Lensesm.push_back(mT_LE1418);
	return_1_N_BK7_Positive_Meniscus_Lensesm.push_back(mT_LE1418A);
	return_1_N_BK7_Positive_Meniscus_Lensesm.push_back(mT_LE1418B);
	return_1_N_BK7_Positive_Meniscus_Lensesm.push_back(mT_LE1418C);
	return_1_N_BK7_Positive_Meniscus_Lensesm.push_back(mT_LE1015);
	return_1_N_BK7_Positive_Meniscus_Lensesm.push_back(mT_LE1015A);
	return_1_N_BK7_Positive_Meniscus_Lensesm.push_back(mT_LE1015B);
	return_1_N_BK7_Positive_Meniscus_Lensesm.push_back(mT_LE1015C);
	return_1_N_BK7_Positive_Meniscus_Lensesm.push_back(mT_LE1613);
	return_1_N_BK7_Positive_Meniscus_Lensesm.push_back(mT_LE1613A);
	return_1_N_BK7_Positive_Meniscus_Lensesm.push_back(mT_LE1613B);
	return_1_N_BK7_Positive_Meniscus_Lensesm.push_back(mT_LE1613C);
	return_1_N_BK7_Positive_Meniscus_Lensesm.push_back(mT_LE1985);
	return_1_N_BK7_Positive_Meniscus_Lensesm.push_back(mT_LE1985A);
	return_1_N_BK7_Positive_Meniscus_Lensesm.push_back(mT_LE1985B);
	return_1_N_BK7_Positive_Meniscus_Lensesm.push_back(mT_LE1985C);

	return return_1_N_BK7_Positive_Meniscus_Lensesm;
}

// *** Ø1" N-BK7 Negative Meniscus Lenses
void ThorlabsLensCatalog::loadLensCatalogThorlabs_1Zoll_N_BK7_Negative_Meniscus_Lenses_Uncoated()
{
	glass glasses;
	glasses.loadGlassCatalog_Schott();

	// https://www.thorlabs.de/newgrouppage9.cfm?objectgroup_id=902
	mT_LF1822.buildLensTwoSurfaces_thorlabs_Uncoated(/*lens catalog*/ "Thorlabs", /*item*/ "LF1822", /*diameter*/ 25.4, /* focallength*/ -100.0, /*back focal length*/ -98.7,
		/*radius first surface*/ 100.0, /*radius second surface*/ 33.65, /*thickness*/ 3.0, /*edge thickness*/ 4.7, /*material*/ glasses.getNBK7_S1(), /*price*/ 23.12, /*design wavelength*/ 587.6,
		/*free aperture CA*/ 0.9 * 25.4, /*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*centration*/ 3.0, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.1,
		/*tolerance center thickness*/ 0.1);

	mT_LF1547.buildLensTwoSurfaces_thorlabs_Uncoated(/*lens catalog*/ "Thorlabs", /*item*/ "LF1547", /*diameter*/ 25.4, /* focallength*/ -150.0, /*back focal length*/ -148.0,
		/*radius first surface*/ 100.0, /*radius second surface*/ 43.14, /*thickness*/ 3.0, /*edge thickness*/ 4.1, /*material*/ glasses.getNBK7_S1(), /*price*/ 19.28,
		/*design wavelength*/ 587.6, /*free aperture CA*/ 0.9 * 25.4, /*max surface quality*/ 40.0, /*min surface quality*/ 20.0,
		/*centration*/ 3.0, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1);

	mT_LF1097.buildLensTwoSurfaces_thorlabs_Uncoated(/*lens catalog*/ "Thorlabs", /*item*/ "LF1097", /*diameter*/ 25.4, /* focallength*/ -200.0, /*back focal length*/ -197.3,
		/*radius first surface*/ 100.0, /*radius second surface*/ 50.22, /*thickness*/ 3.0, /*edge thickness*/ 3.8, /*material*/ glasses.getNBK7_S1(), /*price*/ 19.58,
		/*design wavelength*/ 587.6, /*free aperture CA*/ 0.9 * 25.4, /*max surface quality*/ 40.0, /*min surface quality*/ 20.0,
		/*centration*/ 3.0, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1);

	mT_LF1015.buildLensTwoSurfaces_thorlabs_Uncoated(/*lens catalog*/ "Thorlabs", /*item*/ "LF1015", /*diameter*/ 25.4, /* focallength*/ -300.0, /*back focal length*/ -297.8,
		/*radius first surface*/ 250.0, /*radius second surface*/ 95.11, /*thickness*/ 3.0, /*edge thickness*/ 3.5, /*material*/ glasses.getNBK7_S1(), /*price*/ 19.28,
		/*design wavelength*/ 587.6, /*free aperture CA*/ 0.9 * 25.4, /*max surface quality*/ 40.0, /*min surface quality*/ 20.0,
		/*centration*/ 3.0, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1);

	mT_LF1544.buildLensTwoSurfaces_thorlabs_Uncoated(/*lens catalog*/ "Thorlabs", /*item*/ "LF1544", /*diameter*/ 25.4, /* focallength*/ -400.0, /*back focal length*/ -397.0,
		/*radius first surface*/ 250.0, /*radius second surface*/ 112.48, /*thickness*/ 3.0, /*edge thickness*/ 3.4, /*material*/ glasses.getNBK7_S1(), /*price*/ 19.87,
		/*design wavelength*/ 587.6, /*free aperture CA*/ 0.9 * 25.4, /*max surface quality*/ 40.0, /*min surface quality*/ 20.0,
		/*centration*/ 3.0, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1);

	mT_LF1988.buildLensTwoSurfaces_thorlabs_Uncoated(/*lens catalog*/ "Thorlabs", /*item*/ "LF1988", /*diameter*/ 25.4, /* focallength*/ -500.0, /*back focal length*/ -496.3,
		/*radius first surface*/ 250.0, /*radius second surface*/ 126.34, /*thickness*/ 3.0, /*edge thickness*/ 3.3, /*material*/ glasses.getNBK7_S1(), /*price*/ 20.26,
		/*design wavelength*/ 587.6, /*free aperture CA*/ 0.9 * 25.4, /*max surface quality*/ 40.0, /*min surface quality*/ 20.0,
		/*centration*/ 3.0, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1);

	mT_LF1141.buildLensTwoSurfaces_thorlabs_Uncoated(/*lens catalog*/ "Thorlabs", /*item*/ "LF1141", /*diameter*/ 25.4, /* focallength*/ -1000.0, /*back focal length*/ -994.6,
		/*radius first surface*/ 500.0, /*radius second surface*/ 253.19, /*thickness*/ 3.0, /*edge thickness*/ 3.2, /*material*/ glasses.getNBK7_S1(), /*price*/ 19.37,
		/*design wavelength*/ 587.6, /*free aperture CA*/ 0.9 * 25.4, /*max surface quality*/ 40.0, /*min surface quality*/ 20.0,
		/*centration*/ 3.0, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1);

	mT_LF1822A.buildLensTwoSurfaces_thorlabs_coated(/*lens catalog*/ "Thorlabs", /*item*/ "LF1822-A", /*diameter*/ 25.4, /* focallength*/ -100.0, /*back focal length*/ -98.7,
		/*radius first surface*/ 100.0, /*radius second surface*/ 33.65, /*thickness*/ 3.0, /*edge thickness*/ 4.7, /*material*/ glasses.getNBK7_S1(), /*price*/ 32.71,
		/*design wavelength*/ 587.6, /*free aperture CA*/ 0.9 * 25.4, /*max surface quality*/ 40.0, /*min surface quality*/ 20.0,
		/*centration*/ 3.0, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1,
		/*coating*/ "BBAR",	/*min wavelength*/ 350.0, /*max wavelength*/ 700.0);

	mT_LF1547A.buildLensTwoSurfaces_thorlabs_coated(/*lens catalog*/ "Thorlabs", /*item*/ "LF1547-A", /*diameter*/ 25.4, /* focallength*/ -150.0, /*back focal length*/ -148.0,
		/*radius first surface*/ 100.0, /*radius second surface*/ 43.14, /*thickness*/ 3.0, /*edge thickness*/ 4.1, /*material*/ glasses.getNBK7_S1(), /*price*/ 28.78,
		/*design wavelength*/ 587.6, /*free aperture CA*/ 0.9 * 25.4, /*max surface quality*/ 40.0, /*min surface quality*/ 20.0,
		/*centration*/ 3.0, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1,
		/*coating*/ "BBAR",	/*min wavelength*/ 350.0, /*max wavelength*/ 700.0);

	mT_LF1097A.buildLensTwoSurfaces_thorlabs_coated(/*lens catalog*/ "Thorlabs", /*item*/ "LF1097-A", /*diameter*/ 25.4, /* focallength*/ -200.0, /*back focal length*/ -197.3,
		/*radius first surface*/ 100.0, /*radius second surface*/ 50.22, /*thickness*/ 3.0, /*edge thickness*/ 3.8, /*material*/ glasses.getNBK7_S1(), /*price*/ 29.02,
		/*design wavelength*/ 587.6, /*free aperture CA*/ 0.9 * 25.4, /*max surface quality*/ 40.0, /*min surface quality*/ 20.0,
		/*centration*/ 3.0, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1,
		/*coating*/ "BBAR",	/*min wavelength*/ 350.0, /*max wavelength*/ 700.0);

	mT_LF1015A.buildLensTwoSurfaces_thorlabs_coated(/*lens catalog*/ "Thorlabs", /*item*/ "LF1015-A", /*diameter*/ 25.4, /* focallength*/ -300.0, /*back focal length*/ -297.8,
		/*radius first surface*/ 250.0, /*radius second surface*/ 95.11, /*thickness*/ 3.0, /*edge thickness*/ 3.5, /*material*/ glasses.getNBK7_S1(), /*price*/ 28.78,
		/*design wavelength*/ 587.6, /*free aperture CA*/ 0.9 * 25.4, /*max surface quality*/ 40.0, /*min surface quality*/ 20.0,
		/*centration*/ 3.0, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1,
		/*coating*/ "BBAR",	/*min wavelength*/ 350.0, /*max wavelength*/ 700.0);

	mT_LF1544A.buildLensTwoSurfaces_thorlabs_coated(/*lens catalog*/ "Thorlabs", /*item*/ "LF1544-A", /*diameter*/ 25.4, /* focallength*/ -400.0, /*back focal length*/ -397.0,
		/*radius first surface*/ 250.0, /*radius second surface*/ 112.48, /*thickness*/ 3.0, /*edge thickness*/ 3.4, /*material*/ glasses.getNBK7_S1(), /*price*/ 29.27,
		/*design wavelength*/ 587.6, /*free aperture CA*/ 0.9 * 25.4, /*max surface quality*/ 40.0, /*min surface quality*/ 20.0,
		/*centration*/ 3.0, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1,
		/*coating*/ "BBAR",	/*min wavelength*/ 350.0, /*max wavelength*/ 700.0);

	mT_LF1988A.buildLensTwoSurfaces_thorlabs_coated(/*lens catalog*/ "Thorlabs", /*item*/ "LF1988-A", /*diameter*/ 25.4, /* focallength*/ -500.0, /*back focal length*/ -496.3,
		/*radius first surface*/ 250.0, /*radius second surface*/ 126.34, /*thickness*/ 3.0, /*edge thickness*/ 3.3, /*material*/ glasses.getNBK7_S1(), /*price*/ 29.76,
		/*design wavelength*/ 587.6, /*free aperture CA*/ 0.9 * 25.4, /*max surface quality*/ 40.0, /*min surface quality*/ 20.0,
		/*centration*/ 3.0, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1,
		/*coating*/ "BBAR",	/*min wavelength*/ 350.0, /*max wavelength*/ 700.0);

	mT_LF1141A.buildLensTwoSurfaces_thorlabs_coated(/*lens catalog*/ "Thorlabs", /*item*/ "LF1141-A", /*diameter*/ 25.4, /* focallength*/ -1000.0, /*back focal length*/ -994.6,
		/*radius first surface*/ 500.0, /*radius second surface*/ 253.19, /*thickness*/ 3.0, /*edge thickness*/ 3.2, /*material*/ glasses.getNBK7_S1(), /*price*/ 28.78,
		/*design wavelength*/ 587.6, /*free aperture CA*/ 0.9 * 25.4, /*max surface quality*/ 40.0, /*min surface quality*/ 20.0,
		/*centration*/ 3.0, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1,
		/*coating*/ "BBAR",	/*min wavelength*/ 350.0, /*max wavelength*/ 700.0);

	mT_LF1822B.buildLensTwoSurfaces_thorlabs_coated(/*lens catalog*/ "Thorlabs", /*item*/ "LF1822-B", /*diameter*/ 25.4, /* focallength*/ -100.0, /*back focal length*/ -98.7,
		/*radius first surface*/ 100.0, /*radius second surface*/ 33.65, /*thickness*/ 3.0, /*edge thickness*/ 4.7, /*material*/ glasses.getNBK7_S1(), /*price*/ 32.71,
		/*design wavelength*/ 587.6,  /*free aperture CA*/ 0.9 * 25.4, /*max surface quality*/ 40.0, /*min surface quality*/ 20.0,
		/*centration*/ 3.0, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1,
		/*coating*/ "BBAR",	/*min wavelength*/ 650.0, /*max wavelength*/ 1050.0);

	mT_LF1547B.buildLensTwoSurfaces_thorlabs_coated(/*lens catalog*/ "Thorlabs", /*item*/ "LF1547-B", /*diameter*/ 25.4, /* focallength*/ -150.0, /*back focal length*/ -148.0,
		/*radius first surface*/ 100.0, /*radius second surface*/ 43.14, /*thickness*/ 3.0, /*edge thickness*/ 4.1, /*material*/ glasses.getNBK7_S1(), /*price*/ 28.78,
		/*design wavelength*/ 587.6, /*free aperture CA*/ 0.9 * 25.4, /*max surface quality*/ 40.0, /*min surface quality*/ 20.0,
		/*centration*/ 3.0, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1,
		/*coating*/ "BBAR",	/*min wavelength*/ 650.0, /*max wavelength*/ 1050.0);

	mT_LF1097B.buildLensTwoSurfaces_thorlabs_coated(/*lens catalog*/ "Thorlabs", /*item*/ "LF1097-B", /*diameter*/ 25.4, /* focallength*/ -200.0, /*back focal length*/ -197.3,
		/*radius first surface*/ 100.0, /*radius second surface*/ 50.22, /*thickness*/ 3.0, /*edge thickness*/ 3.8, /*material*/ glasses.getNBK7_S1(), /*price*/ 29.02,
		/*design wavelength*/ 587.6, /*free aperture CA*/ 0.9 * 25.4, /*max surface quality*/ 40.0, /*min surface quality*/ 20.0,
		/*centration*/ 3.0, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1,
		/*coating*/ "BBAR",	/*min wavelength*/ 650.0, /*max wavelength*/ 1050.0);

	mT_LF1015B.buildLensTwoSurfaces_thorlabs_coated(/*lens catalog*/ "Thorlabs", /*item*/ "LF1015-B", /*diameter*/ 25.4, /* focallength*/ -300.0, /*back focal length*/ -297.8,
		/*radius first surface*/ 250.0, /*radius second surface*/ 95.11, /*thickness*/ 3.0, /*edge thickness*/ 3.5, /*material*/ glasses.getNBK7_S1(), /*price*/ 28.78,
		/*design wavelength*/ 587.6, /*free aperture CA*/ 0.9 * 25.4, /*max surface quality*/ 40.0, /*min surface quality*/ 20.0,
		/*centration*/ 3.0, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1,
		/*coating*/ "BBAR",	/*min wavelength*/ 650.0, /*max wavelength*/ 1050.0);

	mT_LF1544B.buildLensTwoSurfaces_thorlabs_coated(/*lens catalog*/ "Thorlabs", /*item*/ "LF1544-B", /*diameter*/ 25.4, /* focallength*/ -400.0, /*back focal length*/ -397.0,
		/*radius first surface*/ 250.0, /*radius second surface*/ 112.48, /*thickness*/ 3.0, /*edge thickness*/ 3.4, /*material*/ glasses.getNBK7_S1(), /*price*/ 29.27,
		/*design wavelength*/ 587.6, /*free aperture CA*/ 0.9 * 25.4, /*max surface quality*/ 40.0, /*min surface quality*/ 20.0,
		/*centration*/ 3.0, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1,
		/*coating*/ "BBAR",	/*min wavelength*/ 650.0, /*max wavelength*/ 1050.0);

	mT_LF1988B.buildLensTwoSurfaces_thorlabs_coated(/*lens catalog*/ "Thorlabs", /*item*/ "LF1988-B", /*diameter*/ 25.4, /* focallength*/ -500.0, /*back focal length*/ -496.3,
		/*radius first surface*/ 250.0, /*radius second surface*/ 126.34, /*thickness*/ 3.0, /*edge thickness*/ 3.3, /*material*/ glasses.getNBK7_S1(), /*price*/ 29.76,
		/*design wavelength*/ 587.6, /*free aperture CA*/ 0.9 * 25.4, /*max surface quality*/ 40.0, /*min surface quality*/ 20.0,
		/*centration*/ 3.0, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1,
		/*coating*/ "BBAR",	/*min wavelength*/ 650.0, /*max wavelength*/ 1050.0);

	mT_LF1141B.buildLensTwoSurfaces_thorlabs_coated(/*lens catalog*/ "Thorlabs", /*item*/ "LF1141-B", /*diameter*/ 25.4, /* focallength*/ -1000.0, /*back focal length*/ -994.6,
		/*radius first surface*/ 500.0, /*radius second surface*/ 253.19, /*thickness*/ 3.0, /*edge thickness*/ 3.2, /*material*/ glasses.getNBK7_S1(), /*price*/ 28.78,
		/*design wavelength*/ 587.6, /*free aperture CA*/ 0.9 * 25.4, /*max surface quality*/ 40.0, /*min surface quality*/ 20.0,
		/*centration*/ 3.0, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1,
		/*coating*/ "BBAR",	/*min wavelength*/ 650.0, /*max wavelength*/ 1050.0);

	mT_LF1822C.buildLensTwoSurfaces_thorlabs_coated(/*lens catalog*/ "Thorlabs", /*item*/ "LF1822-C", /*diameter*/ 25.4, /* focallength*/ -100.0, /*back focal length*/ -98.7,
		/*radius first surface*/ 100.0, /*radius second surface*/ 33.65, /*thickness*/ 3.0, /*edge thickness*/ 4.7, /*material*/ glasses.getNBK7_S1(), /*price*/ 35.66,
		/*design wavelength*/ 587.6, /*free aperture CA*/ 0.9 * 25.4, /*max surface quality*/ 40.0, /*min surface quality*/ 20.0,
		/*centration*/ 3.0, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1,
		/*coating*/ "BBAR",	/*min wavelength*/ 1050.0, /*max wavelength*/ 1700.0);

	mT_LF1547C.buildLensTwoSurfaces_thorlabs_coated(/*lens catalog*/ "Thorlabs", /*item*/ "LF1547-C", /*diameter*/ 25.4, /* focallength*/ -150.0, /*back focal length*/ -148.0,
		/*radius first surface*/ 100.0, /*radius second surface*/ 43.14, /*thickness*/ 3.0, /*edge thickness*/ 4.1, /*material*/ glasses.getNBK7_S1(), /*price*/ 31.96,
		/*design wavelength*/ 587.6, /*free aperture CA*/ 0.9 * 25.4, /*max surface quality*/ 40.0, /*min surface quality*/ 20.0,
		/*centration*/ 3.0, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1,
		/*coating*/ "BBAR",	/*min wavelength*/ 1050.0, /*max wavelength*/ 1700.0);

	mT_LF1097C.buildLensTwoSurfaces_thorlabs_coated(/*lens catalog*/ "Thorlabs", /*item*/ "LF1097-C", /*diameter*/ 25.4, /* focallength*/ -200.0, /*back focal length*/ -197.3,
		/*radius first surface*/ 100.0, /*radius second surface*/ 50.22, /*thickness*/ 3.0, /*edge thickness*/ 3.8, /*material*/ glasses.getNBK7_S1(), /*price*/ 32.21,
		/*design wavelength*/ 587.6, /*free aperture CA*/ 0.9 * 25.4, /*max surface quality*/ 40.0, /*min surface quality*/ 20.0,
		/*centration*/ 3.0, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1,
		/*coating*/ "BBAR",	/*min wavelength*/ 1050.0, /*max wavelength*/ 1700.0);

	mT_LF1015C.buildLensTwoSurfaces_thorlabs_coated(/*lens catalog*/ "Thorlabs", /*item*/ "LF1015-C", /*diameter*/ 25.4, /* focallength*/ -300.0, /*back focal length*/ -297.8,
		/*radius first surface*/ 250.0, /*radius second surface*/ 95.11, /*thickness*/ 3.0, /*edge thickness*/ 3.5, /*material*/ glasses.getNBK7_S1(), /*price*/ 31.96,
		/*design wavelength*/ 587.6, /*free aperture CA*/ 0.9 * 25.4, /*max surface quality*/ 40.0, /*min surface quality*/ 20.0,
		/*centration*/ 3.0, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1,
		/*coating*/ "BBAR",	/*min wavelength*/ 1050.0, /*max wavelength*/ 1700.0);

	mT_LF1544C.buildLensTwoSurfaces_thorlabs_coated(/*lens catalog*/ "Thorlabs", /*item*/ "LF1544-C", /*diameter*/ 25.4, /* focallength*/ -400.0, /*back focal length*/ -397.0,
		/*radius first surface*/ 250.0, /*radius second surface*/ 112.48, /*thickness*/ 3.0, /*edge thickness*/ 3.4, /*material*/ glasses.getNBK7_S1(), /*price*/ 32.46,
		/*design wavelength*/ 587.6, /*free aperture CA*/ 0.9 * 25.4, /*max surface quality*/ 40.0, /*min surface quality*/ 20.0,
		/*centration*/ 3.0, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1,
		/*coating*/ "BBAR",	/*min wavelength*/ 1050.0, /*max wavelength*/ 1700.0);

	mT_LF1988C.buildLensTwoSurfaces_thorlabs_coated(/*lens catalog*/ "Thorlabs", /*item*/ "LF1988-C", /*diameter*/ 25.4, /* focallength*/ -500.0, /*back focal length*/ -496.3,
		/*radius first surface*/ 250.0, /*radius second surface*/ 126.34, /*thickness*/ 3.0, /*edge thickness*/ 3.3, /*material*/ glasses.getNBK7_S1(), /*price*/ 32.71,
		/*design wavelength*/ 587.6, /*free aperture CA*/ 0.9 * 25.4, /*max surface quality*/ 40.0, /*min surface quality*/ 20.0,
		/*centration*/ 3.0, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1,
		/*coating*/ "BBAR",	/*min wavelength*/ 1050.0, /*max wavelength*/ 1700.0);

	mT_LF1141C.buildLensTwoSurfaces_thorlabs_coated(/*lens catalog*/ "Thorlabs", /*item*/ "LF1141-C", /*diameter*/ 25.4, /* focallength*/ -1000.0, /*back focal length*/ -994.6,
		/*radius first surface*/ 500.0, /*radius second surface*/ 253.19, /*thickness*/ 3.0, /*edge thickness*/ 3.2, /*material*/ glasses.getNBK7_S1(), /*price*/ 31.96,
		/*design wavelength*/ 587.6, /*free aperture CA*/ 0.9 * 25.4, /*max surface quality*/ 40.0, /*min surface quality*/ 20.0,
		/*centration*/ 3.0, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.1, /*tolerance center thickness*/ 0.1,
		/*coating*/ "BBAR",	/*min wavelength*/ 1050.0, /*max wavelength*/ 1700.0);

}
std::vector<LensesTwoSurfaces> ThorlabsLensCatalog::getAll_1Zoll_N_BK7_Negative_Meniscus_Lenses_Uncoated()
{
	// https://www.thorlabs.de/newgrouppage9.cfm?objectgroup_id=902
	std::vector<LensesTwoSurfaces> return_1Zoll_N_BK7_Negative_Meniscus_Lenses;

	return_1Zoll_N_BK7_Negative_Meniscus_Lenses.push_back(mT_LF1822);
	return_1Zoll_N_BK7_Negative_Meniscus_Lenses.push_back(mT_LF1547);
	return_1Zoll_N_BK7_Negative_Meniscus_Lenses.push_back(mT_LF1097);
	return_1Zoll_N_BK7_Negative_Meniscus_Lenses.push_back(mT_LF1015);
	return_1Zoll_N_BK7_Negative_Meniscus_Lenses.push_back(mT_LF1544);
	return_1Zoll_N_BK7_Negative_Meniscus_Lenses.push_back(mT_LF1988);
	return_1Zoll_N_BK7_Negative_Meniscus_Lenses.push_back(mT_LF1141);

	return_1Zoll_N_BK7_Negative_Meniscus_Lenses.push_back(mT_LF1822A);
	return_1Zoll_N_BK7_Negative_Meniscus_Lenses.push_back(mT_LF1547A);
	return_1Zoll_N_BK7_Negative_Meniscus_Lenses.push_back(mT_LF1097A);
	return_1Zoll_N_BK7_Negative_Meniscus_Lenses.push_back(mT_LF1015A);
	return_1Zoll_N_BK7_Negative_Meniscus_Lenses.push_back(mT_LF1544A);
	return_1Zoll_N_BK7_Negative_Meniscus_Lenses.push_back(mT_LF1988A);
	return_1Zoll_N_BK7_Negative_Meniscus_Lenses.push_back(mT_LF1141A);

	return_1Zoll_N_BK7_Negative_Meniscus_Lenses.push_back(mT_LF1822B);
	return_1Zoll_N_BK7_Negative_Meniscus_Lenses.push_back(mT_LF1547B);
	return_1Zoll_N_BK7_Negative_Meniscus_Lenses.push_back(mT_LF1097B);
	return_1Zoll_N_BK7_Negative_Meniscus_Lenses.push_back(mT_LF1015B);
	return_1Zoll_N_BK7_Negative_Meniscus_Lenses.push_back(mT_LF1544B);
	return_1Zoll_N_BK7_Negative_Meniscus_Lenses.push_back(mT_LF1988B);
	return_1Zoll_N_BK7_Negative_Meniscus_Lenses.push_back(mT_LF1141B);

	return_1Zoll_N_BK7_Negative_Meniscus_Lenses.push_back(mT_LF1822C);
	return_1Zoll_N_BK7_Negative_Meniscus_Lenses.push_back(mT_LF1547C);
	return_1Zoll_N_BK7_Negative_Meniscus_Lenses.push_back(mT_LF1097C);
	return_1Zoll_N_BK7_Negative_Meniscus_Lenses.push_back(mT_LF1015C);
	return_1Zoll_N_BK7_Negative_Meniscus_Lenses.push_back(mT_LF1544C);
	return_1Zoll_N_BK7_Negative_Meniscus_Lenses.push_back(mT_LF1988C);
	return_1Zoll_N_BK7_Negative_Meniscus_Lenses.push_back(mT_LF1141C);

	return return_1Zoll_N_BK7_Negative_Meniscus_Lenses;
}

// *** Steinheil Triplet Achromatic Lenses, Visible
void ThorlabsLensCatalog::loadLensCatalogThorlabs_Steinheil_Triplet_Achromatic_Lenses_Visible()
{
	// https://www.thorlabs.de/newgrouppage9.cfm?objectgroup_id=5370
	glass glasses;
	glasses.loadGlassCatalog_Schott();

	mT_TRS064010A.buildLensFourSurfaces(/*lens catalog*/ "Thorlabs", /*catalog number*/ "TRS064-010-A", /*diameter*/ 6.35, /*focallength*/ 10.0,
		/*tolerance focal length */ 2.0, /*back focal length*/ 8.6, /*working distance*/ 18.8,	/*radius first surface*/ 9.333,	/*radius second surface*/ 3.834,
		/*radius third surface*/ -3.834, /*radius tourth surface*/ -9.333, /*first thickness*/ 0.5, /*second thickness*/ 3.7, /*third thickness*/ 0.5,
		/*material first*/ glasses.getNSF8_S1(), /*material second*/glasses.getNBAF52_S1(), /*material third*/ glasses.getNSF8_S1(), /*edge thickness*/ 3.7,
		/*first design wavelength*/ 486.1, /*second design wavelength*/ 587.6, /*third design wavelength*/ 656.3, /*free aperture CA*/ 0.9 * 6.35,
		/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*centration*/ 3.0, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.1,
		/*tolerance center thickness*/ 0.15, /*coating*/ "BBAR", /*min wavelength*/ 400.0, /*max wavelength*/ 700.0, /*price*/ 61.24);

	mT_TRS127020A.buildLensFourSurfaces(/*lens catalog*/ "Thorlabs", /*catalog number*/ "TRS127-020-A", /*diameter*/ 12.7, /*focallength*/ 20.0,
		/*tolerance focal length */ 2.0, /*back focal length*/ 17.0, /*working distance*/ 37.3,	/*radius first surface*/ 18.334,	/*radius second surface*/ 7.38,
		/*radius third surface*/ -7.38, /*radius tourth surface*/ -18.334, /*first thickness*/ 1.0, /*second thickness*/ 8.0, /*third thickness*/ 1.0,
		/*material first*/ glasses.getNSF8_S1(), /*material second*/glasses.getNBAF52_S1(), /*material third*/ glasses.getNSF8_S1(), /*edge thickness*/ 7.8,
		/*first design wavelength*/ 486.1, /*second design wavelength*/ 587.6, /*third design wavelength*/ 656.3, /*free aperture CA*/ 0.9 * 12.7,
		/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*centration*/ 3.0, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.1,
		/*tolerance center thickness*/ 0.15, /*coating*/ "BBAR", /*min wavelength*/ 400.0, /*max wavelength*/ 700.0, /*price*/ 61.24);

	mT_TRS254040A.buildLensFourSurfaces(/*lens catalog*/ "Thorlabs", /*catalog number*/ "TRS254-040-A", /*diameter*/ 25.4, /*focallength*/ 40.0,
		/*tolerance focal length */ 1.0, /*back focal length*/ 28.8, /*working distance*/ 69.3,	/*radius first surface*/ 28.77,	/*radius second surface*/ 13.333,
		/*radius third surface*/ -13.333, /*radius tourth surface*/ -28.77, /*first thickness*/ 5.2, /*second thickness*/ 19.8, /*third thickness*/ 5.2,
		/*material first*/ glasses.getNF2_S1(), /*material second*/glasses.getNK5_S1(), /*material third*/ glasses.getNF2_S1(), /*edge thickness*/ 24.4,
		/*first design wavelength*/ 486.1, /*second design wavelength*/ 587.6, /*third design wavelength*/ 656.3, /*free aperture CA*/ 0.9 * 6.35,
		/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*centration*/ 3.0, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.1,
		/*tolerance center thickness*/ 0.15, /*coating*/ "BBAR", /*min wavelength*/ 400.0, /*max wavelength*/ 700.0, /*price*/ 76.48);



	mT_TRS127020AML.buildLensFourSurfaces(/*lens catalog*/ "Thorlabs", /*catalog number*/ "TRS127-020-A-ML", /*diameter*/ 12.7, /*focallength*/ 20.0,
		/*tolerance focal length */ 2.0, /*back focal length*/ 17.0, /*working distance1*/ 35.5, /*working distance2*/ 34.1, /*radius first surface*/ 18.334,
		/*radius second surface*/ 7.38,	/*radius third surface*/ -7.38, /*radius tourth surface*/ -18.334, /*first thickness*/ 1.0, /*second thickness*/ 8.0,
		/*third thickness*/ 1.0, /*material first*/ glasses.getNSF8_S1(), /*material second*/glasses.getNBAF52_S1(), /*material third*/ glasses.getNSF8_S1(),
		/*edge thickness*/ 7.8,	/*first design wavelength*/ 486.1, /*second design wavelength*/ 587.6, /*third design wavelength*/ 656.3, /*free aperture CA*/ 0.9 * 12.7,
		/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*centration*/ 3.0, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.1,
		/*tolerance center thickness*/ 0.15, /*coating*/ "BBAR", /*min wavelength*/ 400.0, /*max wavelength*/ 700.0, /*price*/ 81.89);

	mT_TRS254040AML.buildLensFourSurfaces(/*lens catalog*/ "Thorlabs", /*catalog number*/ "TRS254-040-A-ML", /*diameter*/ 25.4, /*focallength*/ 40.0,
		/*tolerance focal length */ 1.0, /*back focal length*/ 28.8, /*working distance1*/ 68.2, /*working distance2*/ 65.9, /*radius first surface*/ 28.77,
		/*radius second surface*/ 13.333, /*radius third surface*/ -13.333, /*radius tourth surface*/ -28.77, /*first thickness*/ 5.2, /*second thickness*/ 19.8,
		/*third thickness*/ 5.2, /*material first*/ glasses.getNF2_S1(), /*material second*/glasses.getNK5_S1(), /*material third*/ glasses.getNF2_S1(),
		/*edge thickness*/ 24.4, /*first design wavelength*/ 486.1, /*second design wavelength*/ 587.6, /*third design wavelength*/ 656.3, /*free aperture CA*/ 0.9 * 6.35,
		/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*centration*/ 3.0, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.1,
		/*tolerance center thickness*/ 0.15, /*coating*/ "BBAR", /*min wavelength*/ 400.0, /*max wavelength*/ 700.0, /*price*/ 97.14);



}

std::vector<LensFourSurfaces> ThorlabsLensCatalog::getAll_Steinheil_Triplet_Achromatic_Lenses_Visible()
{
	// https://www.thorlabs.de/newgrouppage9.cfm?objectgroup_id=5370
	std::vector<LensFourSurfaces> return_Steinheil_Triplet_Achromatic_Lenses_Visible;

	return_Steinheil_Triplet_Achromatic_Lenses_Visible.push_back(mT_TRS064010A);
	return_Steinheil_Triplet_Achromatic_Lenses_Visible.push_back(mT_TRS127020A);
	return_Steinheil_Triplet_Achromatic_Lenses_Visible.push_back(mT_TRS254040A);

	return_Steinheil_Triplet_Achromatic_Lenses_Visible.push_back(mT_TRS127020AML);
	return_Steinheil_Triplet_Achromatic_Lenses_Visible.push_back(mT_TRS254040AML);

	return return_Steinheil_Triplet_Achromatic_Lenses_Visible;

}

// *** Hastings Triplet Achromatic Lenses, Visible
void ThorlabsLensCatalog::loadLensCatalogThorlabs_Hastings_Triplet_Achromatic_Lenses_Visible()
{
	// https://www.thorlabs.de/newgrouppage9.cfm?objectgroup_id=5368
	glass glasses;
	glasses.loadGlassCatalog_Schott();

	mT_TRH064010A.buildLensFourSurfaces(/*lens catalog*/ "Thorlabs", /*catalog number*/ "TRH064-010-A", /*diameter*/ 6.35, /*focallength*/ 12.2,
		/*tolerance focal length */ 1.0, /*back focal length*/ 7.8, /*working distance*/ 7.8, /*radius first surface*/ 7.38,	/*radius second surface*/ 3.47,
		/*radius third surface*/ -3.47, /*radius tourth surface*/ -7.38, /*first thickness*/ 0.5, /*second thickness*/ 5.0, /*third thickness*/ 0.5,
		/*material first*/ glasses.getNF2_S1(), /*material second*/glasses.getNK5_S1(), /*material third*/ glasses.getNF2_S1(), /*edge thickness*/ 4.7,
		/*first design wavelength*/ 486.1, /*second design wavelength*/ 587.6, /*third design wavelength*/ 656.3, /*free aperture CA*/ 0.9 * 6.35,
		/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*centration*/ 3.0, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.1,
		/*tolerance center thickness*/ 0.15, /*coating*/ "BBAR", /*min wavelength*/ 400.0, /*max wavelength*/ 700.0, /*price*/ 61.24);

	mT_TRH127020A.buildLensFourSurfaces(/*lens catalog*/ "Thorlabs", /*catalog number*/ "TRH127-020-A", /*diameter*/ 12.7, /*focallength*/ 20.0,
		/*tolerance focal length */ 1.0, /*back focal length*/ 15.9, /*working distance*/ 15.9, /*radius first surface*/ 14.86,	/*radius second surface*/ 8.281,
		/*radius third surface*/ -8.281, /*radius tourth surface*/ -14.86, /*first thickness*/ 2.0, /*second thickness*/ 8.0, /*third thickness*/ 2.0,
		/*material first*/ glasses.getNF2_S1(), /*material second*/glasses.getNK5_S1(), /*material third*/ glasses.getNF2_S1(), /*edge thickness*/ 9.3,
		/*first design wavelength*/ 486.1, /*second design wavelength*/ 587.6, /*third design wavelength*/ 656.3, /*free aperture CA*/ 0.9 * 12.7,
		/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*centration*/ 3.0, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.1,
		/*tolerance center thickness*/ 0.15, /*coating*/ "BBAR", /*min wavelength*/ 400.0, /*max wavelength*/ 700.0, /*price*/ 61.24);

	mT_TRH254040A.buildLensFourSurfaces(/*lens catalog*/ "Thorlabs", /*catalog number*/ "TRH254-040-A", /*diameter*/ 25.4, /*focallength*/ 40.0,
		/*tolerance focal length */ 1.0, /*back focal length*/ 32.3, /*working distance*/ 32.3, /*radius first surface*/ 30.2,	/*radius second surface*/ 14.223,
		/*radius third surface*/ -14.223, /*radius tourth surface*/ -30.2, /*first thickness*/ 2.5, /*second thickness*/ 17.0, /*third thickness*/ 2.5,
		/*material first*/ glasses.getNF2_S1(), /*material second*/glasses.getNK5_S1(), /*material third*/ glasses.getNF2_S1(), /*edge thickness*/ 4.7,
		/*first design wavelength*/ 486.1, /*second design wavelength*/ 587.6, /*third design wavelength*/ 656.3, /*free aperture CA*/ 0.9 * 25.4,
		/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*centration*/ 3.0, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.1,
		/*tolerance center thickness*/ 0.15, /*coating*/ "BBAR", /*min wavelength*/ 400.0, /*max wavelength*/ 700.0, /*price*/ 71.57);



	mT_TRH127020AML.buildLensFourSurfaces(/*lens catalog*/ "Thorlabs", /*catalog number*/ "TRH127-020-A", /*diameter*/ 12.7, /*focallength*/ 20.0,
		/*tolerance focal length */ 1.0, /*back focal length*/ 15.9, /*working distance*/ 14.4, /*radius first surface*/ 14.86,	/*radius second surface*/ 8.281,
		/*radius third surface*/ -8.281, /*radius tourth surface*/ -14.86, /*first thickness*/ 2.0, /*second thickness*/ 8.0, /*third thickness*/ 2.0,
		/*material first*/ glasses.getNF2_S1(), /*material second*/glasses.getNK5_S1(), /*material third*/ glasses.getNF2_S1(), /*edge thickness*/ 9.3,
		/*first design wavelength*/ 486.1, /*second design wavelength*/ 587.6, /*third design wavelength*/ 656.3, /*free aperture CA*/ 0.9 * 12.7,
		/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*centration*/ 3.0, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.1,
		/*tolerance center thickness*/ 0.15, /*coating*/ "BBAR", /*min wavelength*/ 400.0, /*max wavelength*/ 700.0, /*price*/ 81.89);

	mT_TRH254040A.buildLensFourSurfaces(/*lens catalog*/ "Thorlabs", /*catalog number*/ "TRH254-040-A", /*diameter*/ 25.4, /*focallength*/ 40.0,
		/*tolerance focal length */ 1.0, /*back focal length*/ 32.3, /*working distance*/ 31.1, /*radius first surface*/ 30.2,	/*radius second surface*/ 14.223,
		/*radius third surface*/ -14.223, /*radius tourth surface*/ -30.2, /*first thickness*/ 2.5, /*second thickness*/ 17.0, /*third thickness*/ 2.5,
		/*material first*/ glasses.getNF2_S1(), /*material second*/glasses.getNK5_S1(), /*material third*/ glasses.getNF2_S1(), /*edge thickness*/ 4.7,
		/*first design wavelength*/ 486.1, /*second design wavelength*/ 587.6, /*third design wavelength*/ 656.3, /*free aperture CA*/ 0.9 * 25.4,
		/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*centration*/ 3.0, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.1,
		/*tolerance center thickness*/ 0.15, /*coating*/ "BBAR", /*min wavelength*/ 400.0, /*max wavelength*/ 700.0, /*price*/ 92.23);





}

std::vector<LensFourSurfaces> ThorlabsLensCatalog::getAll_Hastings_Triplet_Achromatic_Lenses_Visible()
{
	// https://www.thorlabs.de/newgrouppage9.cfm?objectgroup_id=5368
	std::vector<LensFourSurfaces> return_Hastings_Triplet_Achromatic_Lenses_Visible;

	return_Hastings_Triplet_Achromatic_Lenses_Visible.push_back(mT_TRH064010A);
	return_Hastings_Triplet_Achromatic_Lenses_Visible.push_back(mT_TRH127020A);
	return_Hastings_Triplet_Achromatic_Lenses_Visible.push_back(mT_TRH254040A);

	return_Hastings_Triplet_Achromatic_Lenses_Visible.push_back(mT_TRH127020AML);
	return_Hastings_Triplet_Achromatic_Lenses_Visible.push_back(mT_TRH254040AML);

	return return_Hastings_Triplet_Achromatic_Lenses_Visible;
}

// Unmounted Achromatic Doublets, AR Coated: 400 - 1100 nm
// https://www.thorlabs.com/newgrouppage9.cfm?objectgroup_id=12767
LensThreeSurfaces ThorlabsLensCatalog::getT_AC127019AB()
{
	return mT_AC127019AB;
}
LensThreeSurfaces ThorlabsLensCatalog::getT_AC127025AB()
{
	return mT_AC127025AB;
}
LensThreeSurfaces ThorlabsLensCatalog::getT_AC127030AB()
{
	return mT_AC127030AB;

}
LensThreeSurfaces ThorlabsLensCatalog::getT_AC127050AB()
{
	return mT_AC127050AB;
}
LensThreeSurfaces ThorlabsLensCatalog::getT_AC127075AB()
{
	return mT_AC127075AB;
}
//LensThreeSurfaces ThorlabsLensCatalog::getT_AC254030AB()
//{
//	return mT_AC254030AB
//}
LensThreeSurfaces ThorlabsLensCatalog::getT_AC254050AB()
{
	return mT_AC254050AB;
}
LensThreeSurfaces ThorlabsLensCatalog::getT_AC254075AB()
{
	return mT_AC254075AB;
}
LensThreeSurfaces ThorlabsLensCatalog::getT_AC254100AB()
{
	return mT_AC254100AB;
}
LensThreeSurfaces ThorlabsLensCatalog::getT_AC254150AB()
{
	return mT_AC254150AB;
}
LensThreeSurfaces ThorlabsLensCatalog::getT_AC254200AB()
{
	return mT_AC254200AB;
}
LensThreeSurfaces ThorlabsLensCatalog::getT_AC508080AB()
{
	return mT_AC508080AB;
}
LensThreeSurfaces ThorlabsLensCatalog::getT_AC508180AB()
{
	return mT_AC508180AB;
}
LensThreeSurfaces ThorlabsLensCatalog::getT_AC508300AB()
{
	return mT_AC508300AB;
}
LensThreeSurfaces ThorlabsLensCatalog::getT_AC508400AB()
{
	return mT_AC508400AB;
}
LensThreeSurfaces ThorlabsLensCatalog::getT_AC508500AB()
{
	return mT_AC508500AB;
}
LensThreeSurfaces ThorlabsLensCatalog::getT_AC508600AB()
{
	return mT_AC508600AB;
}

//  N BK7 Plano Convex Lenses AR Coating 400 1100 nm
// https://www.thorlabs.de/newgrouppage9.cfm?objectgroup_id=13685
LensesTwoSurfaces ThorlabsLensCatalog::getT_LA1540AB()
{
	return mT_LA1540AB;
}
LensesTwoSurfaces ThorlabsLensCatalog::getT_LA1074AB()
{
	return mT_LA1074AB;
}
LensesTwoSurfaces ThorlabsLensCatalog::getT_LA1560AB()
{
	return mT_LA1560AB;
}
LensesTwoSurfaces ThorlabsLensCatalog::getT_LA1289AB()
{
	return mT_LA1289AB;
}
LensesTwoSurfaces ThorlabsLensCatalog::getT_LA1304AB()
{
	return mT_LA1304AB;
}
LensesTwoSurfaces ThorlabsLensCatalog::getT_LA1213AB()
{
	return mT_LA1213AB;
}
LensesTwoSurfaces ThorlabsLensCatalog::getT_LA1207AB()
{
	return mT_LA1207AB;
}
LensesTwoSurfaces ThorlabsLensCatalog::getT_LA1951AB()
{
	return mT_LA1951AB;
}
LensesTwoSurfaces ThorlabsLensCatalog::getT_LA1805AB()
{
	return mT_LA1805AB;
}
LensesTwoSurfaces ThorlabsLensCatalog::getT_LA1027AB()
{
	return mT_LA1027AB;
}
LensesTwoSurfaces ThorlabsLensCatalog::getT_LA1422AB()
{
	return mT_LA1422AB;
}
LensesTwoSurfaces ThorlabsLensCatalog::getT_LA1131AB()
{
	return mT_LA1131AB;
}
LensesTwoSurfaces ThorlabsLensCatalog::getT_LA1134AB()
{
	return mT_LA1134AB;
}
LensesTwoSurfaces ThorlabsLensCatalog::getT_LA1608AB()
{
	return mT_LA1608AB;
}
LensesTwoSurfaces ThorlabsLensCatalog::getT_LA1986AB()
{
	return mT_LA1986AB;
}
LensesTwoSurfaces ThorlabsLensCatalog::getT_LA1433AB()
{
	return mT_LA1433AB;
}
LensesTwoSurfaces ThorlabsLensCatalog::getT_LA1229AB()
{
	return mT_LA1229AB;
}
LensesTwoSurfaces ThorlabsLensCatalog::getT_LA1708AB()
{
	return mT_LA1708AB;
}
LensesTwoSurfaces ThorlabsLensCatalog::getT_LA1461AB()
{
	return mT_LA1461AB;
}
LensesTwoSurfaces ThorlabsLensCatalog::getT_LA1484AB()
{
	return mT_LA1484AB;
}
LensesTwoSurfaces ThorlabsLensCatalog::getT_LA1172AB()
{
	return mT_LA1172AB;
}
LensesTwoSurfaces ThorlabsLensCatalog::getT_LA1908AB()
{
	return mT_LA1908AB;
}
LensesTwoSurfaces ThorlabsLensCatalog::getT_LA1978AB()
{
	return mT_LA1978AB;
}
LensesTwoSurfaces ThorlabsLensCatalog::getT_LA1464AB()
{
	return mT_LA1464AB;
}
LensesTwoSurfaces ThorlabsLensCatalog::getT_LA1254AB()
{
	return mT_LA1254AB;
}
LensesTwoSurfaces ThorlabsLensCatalog::getT_LA1258AB()
{
	return mT_LA1258AB;
}
LensesTwoSurfaces ThorlabsLensCatalog::getT_LA1259AB()
{
	return mT_LA1259AB;
}
LensesTwoSurfaces ThorlabsLensCatalog::getT_LA1401AB()
{
	return mT_LA1401AB;
}
LensesTwoSurfaces ThorlabsLensCatalog::getT_LA1145AB()
{
	return mT_LA1145AB;
}
LensesTwoSurfaces ThorlabsLensCatalog::getT_LA1050AB()
{
	return mT_LA1050AB;
}
LensesTwoSurfaces ThorlabsLensCatalog::getT_LA1384AB()
{
	return mT_LA1384AB;
}
LensesTwoSurfaces ThorlabsLensCatalog::getT_LA1417AB()
{
	return mT_LA1417AB;
}
LensesTwoSurfaces ThorlabsLensCatalog::getT_LA1399AB()
{
	return mT_LA1399AB;
}
LensesTwoSurfaces ThorlabsLensCatalog::getT_LA1979AB()
{
	return mT_LA1979AB;
}
LensesTwoSurfaces ThorlabsLensCatalog::getT_LA1301AB()
{
	return mT_LA1301AB;
}
LensesTwoSurfaces ThorlabsLensCatalog::getT_LA1256AB()
{
	return mT_LA1256AB;
}
LensesTwoSurfaces ThorlabsLensCatalog::getT_LA1725AB()
{
	return mT_LA1725AB;
}
LensesTwoSurfaces ThorlabsLensCatalog::getT_LA1380AB()
{
	return mT_LA1380AB;
}
LensesTwoSurfaces ThorlabsLensCatalog::getT_LA1727AB()
{
	return mT_LA1727AB;
}
LensesTwoSurfaces ThorlabsLensCatalog::getT_LA1779AB()
{
	return mT_LA1779AB;
}


// N BK7 Bi-Convex Lenses AR Coating: 350 - 700 nm
// https://www.thorlabs.de/newgrouppage9.cfm?objectgroup_id=
LensesTwoSurfaces ThorlabsLensCatalog::getT_LB1157A()
{
	return mT_LB1157A;
}
LensesTwoSurfaces ThorlabsLensCatalog::getT_LB1406A()
{
	return mT_LB1406A;
}
LensesTwoSurfaces ThorlabsLensCatalog::getT_LB1494A()
{
	return mT_LB1494A;
}
LensesTwoSurfaces ThorlabsLensCatalog::getT_LB1212A()
{
	return mT_LB1212A;
}
LensesTwoSurfaces ThorlabsLensCatalog::getT_LB1092A()
{
	return mT_LB1092A;
}
LensesTwoSurfaces ThorlabsLensCatalog::getT_LB1450A()
{
	return mT_LB1450A;
}
LensesTwoSurfaces ThorlabsLensCatalog::getT_LB1014A()
{
	return mT_LB1014A;
}
LensesTwoSurfaces ThorlabsLensCatalog::getT_LB1258A()
{
	return mT_LB1258A;
}
LensesTwoSurfaces ThorlabsLensCatalog::getT_LB1378A()
{
	return mT_LB1378A;
}
LensesTwoSurfaces ThorlabsLensCatalog::getT_LB1844A()
{
	return mT_LB1844A;
}
LensesTwoSurfaces ThorlabsLensCatalog::getT_LB1187A()
{
	return mT_LB1187A;
}
LensesTwoSurfaces ThorlabsLensCatalog::getT_LB1761A()
{
	return mT_LB1761A;
}
LensesTwoSurfaces ThorlabsLensCatalog::getT_LB1757A()
{
	return mT_LB1757A;
}
LensesTwoSurfaces ThorlabsLensCatalog::getT_LB1811A()
{
	return mT_LB1811A;
}
LensesTwoSurfaces ThorlabsLensCatalog::getT_LB1027A()
{
	return mT_LB1027A;
}
LensesTwoSurfaces ThorlabsLensCatalog::getT_LB1471A()
{
	return mT_LB1471A;
}
LensesTwoSurfaces ThorlabsLensCatalog::getT_LB1596A()
{
	return mT_LB1596A;
}
LensesTwoSurfaces ThorlabsLensCatalog::getT_LB1901A()
{
	return mT_LB1901A;
}
LensesTwoSurfaces ThorlabsLensCatalog::getT_LB1676A()
{
	return mT_LB1676A;
}
LensesTwoSurfaces ThorlabsLensCatalog::getT_LB1904A()
{
	return mT_LB1904A;
}
LensesTwoSurfaces ThorlabsLensCatalog::getT_LB1437A()
{
	return mT_LB1437A;
}
LensesTwoSurfaces ThorlabsLensCatalog::getT_LB1294A()
{
	return mT_LB1294A;
}
LensesTwoSurfaces ThorlabsLensCatalog::getT_LB1945A()
{
	return mT_LB1945A;
}
LensesTwoSurfaces ThorlabsLensCatalog::getT_LB1056A()
{
	return mT_LB1056A;
}
LensesTwoSurfaces ThorlabsLensCatalog::getT_LB1779A()
{
	return mT_LB1779A;
}
LensesTwoSurfaces ThorlabsLensCatalog::getT_LB1391A()
{
	return mT_LB1391A;
}
LensesTwoSurfaces ThorlabsLensCatalog::getT_LB1869A()
{
	return mT_LB1869A;
}
LensesTwoSurfaces ThorlabsLensCatalog::getT_LB1475A()
{
	return mT_LB1475A;
}
LensesTwoSurfaces ThorlabsLensCatalog::getT_LB1409A()
{
	return mT_LB1409A;
}
LensesTwoSurfaces ThorlabsLensCatalog::getT_LB1723A()
{
	return mT_LB1723A;
}
LensesTwoSurfaces ThorlabsLensCatalog::getT_LB1309A()
{
	return mT_LB1309A;
}
LensesTwoSurfaces ThorlabsLensCatalog::getT_LB1630A()
{
	return mT_LB1630A;
}
LensesTwoSurfaces ThorlabsLensCatalog::getT_LB1106A()
{
	return mT_LB1106A;
}
LensesTwoSurfaces ThorlabsLensCatalog::getT_LB1374A()
{
	return mT_LB1374A;
}
LensesTwoSurfaces ThorlabsLensCatalog::getT_LB1607A()
{
	return mT_LB1607A;
}
LensesTwoSurfaces ThorlabsLensCatalog::getT_LB1199A()
{
	return mT_LB1199A;
}
LensesTwoSurfaces ThorlabsLensCatalog::getT_LB1889A()
{
	return mT_LB1889A;
}
LensesTwoSurfaces ThorlabsLensCatalog::getT_LB1917A()
{
	return mT_LB1917A;
}
LensesTwoSurfaces ThorlabsLensCatalog::getT_LB1862A()
{
	return mT_LB1862A;
}
LensesTwoSurfaces ThorlabsLensCatalog::getT_LB1909A()
{
	return mT_LB1909A;
}
LensesTwoSurfaces ThorlabsLensCatalog::getT_LB1247A()
{
	return mT_LB1247A;
}
LensesTwoSurfaces ThorlabsLensCatalog::getT_LB1859A()
{
	return mT_LB1859A;
}

// N-BK7 Plano-Concave Lenses, AR Coating 350 - 700 nm
//	https://www.thorlabs.de/newgrouppage9.cfm?objectgroup_id=6509
LensesTwoSurfaces ThorlabsLensCatalog::getT_LC1975A()
{
	return mT_LC1975A;
}
LensesTwoSurfaces ThorlabsLensCatalog::getT_LC1906A()
{
	return mT_LC1906A;
}
LensesTwoSurfaces ThorlabsLensCatalog::getT_LC1054A()
{
	return mT_LC1054A;
}
LensesTwoSurfaces ThorlabsLensCatalog::getT_LC1060A()
{
	return mT_LC1060A;
}
LensesTwoSurfaces ThorlabsLensCatalog::getT_LC1439A()
{
	return mT_LC1439A;
}
LensesTwoSurfaces ThorlabsLensCatalog::getT_LC1259A()
{
	return mT_LC1259A;
}
LensesTwoSurfaces ThorlabsLensCatalog::getT_LC1258A()
{
	return mT_LC1258A;
}
LensesTwoSurfaces ThorlabsLensCatalog::getT_LC1254A()
{
	return mT_LC1254A;
}
LensesTwoSurfaces ThorlabsLensCatalog::getT_LC1715A()
{
	return mT_LC1715A;
}
LensesTwoSurfaces ThorlabsLensCatalog::getT_LC1582A()
{
	return mT_LC1582A;
}
LensesTwoSurfaces ThorlabsLensCatalog::getT_LC1120A()
{
	return mT_LC1120A;
}
LensesTwoSurfaces ThorlabsLensCatalog::getT_LC1315A()
{
	return mT_LC1315A;
}
LensesTwoSurfaces ThorlabsLensCatalog::getT_LC1093A()
{
	return mT_LC1093A;
}
LensesTwoSurfaces ThorlabsLensCatalog::getT_LC1611A()
{
	return mT_LC1611A;
}



// N-BK7 and N-SF11 Bi-Concave Lenses, AR Coating 350 - 700 nm
// https://www.thorlabs.de/newgrouppage9.cfm?objectgroup_id=9733
LensesTwoSurfaces ThorlabsLensCatalog::getT_LD2746A()
{
	return mT_LD2746A;
}
LensesTwoSurfaces ThorlabsLensCatalog::getT_LD2568A()
{
	return mT_LD2568A;
}
LensesTwoSurfaces ThorlabsLensCatalog::getT_LD1357A()
{
	return mT_LD1357A;
}
LensesTwoSurfaces ThorlabsLensCatalog::getT_LD2060A()
{
	return mT_LD2060A;
}
LensesTwoSurfaces ThorlabsLensCatalog::getT_LD2297A()
{
	return mT_LD2297A;
}
LensesTwoSurfaces ThorlabsLensCatalog::getT_LD1464A()
{
	return mT_LD1464A;
}
LensesTwoSurfaces ThorlabsLensCatalog::getT_LD1170A()
{
	return mT_LD1170A;
}
LensesTwoSurfaces ThorlabsLensCatalog::getT_LD1613A()
{
	return mT_LD1613A;
}

// Ø1" N-BK7 Best Form Spherical Lenses, AR Coating: 350-700 nm
// https://www.thorlabs.de/newgrouppage9.cfm?objectgroup_id=4874
LensesTwoSurfaces ThorlabsLensCatalog::getT_LBF254040A()
{
	return mT_LBF254040A;
}
LensesTwoSurfaces ThorlabsLensCatalog::getT_LBF254050A()
{
	return mT_LBF254050A;
}
LensesTwoSurfaces ThorlabsLensCatalog::getT_LBF254075A()
{
	return mT_LBF254075A;
}
LensesTwoSurfaces ThorlabsLensCatalog::getT_LBF254100A()
{
	return mT_LBF254100A;
}
LensesTwoSurfaces ThorlabsLensCatalog::getT_LBF254150A()
{
	return mT_LBF254150A;
}
LensesTwoSurfaces ThorlabsLensCatalog::getT_LBF254200A()
{
	return mT_LBF254200A;
}

// *** N-BK7 Positive Meniscus Lenses
// https://www.thorlabs.de/newgrouppage9.cfm?objectgroup_id=130
LensesTwoSurfaces ThorlabsLensCatalog::getT_LE1234()
{
	return mT_LE1234;
}
LensesTwoSurfaces ThorlabsLensCatalog::getT_LE1234A()
{
	return mT_LE1234A;
}
LensesTwoSurfaces ThorlabsLensCatalog::getT_LE1234B()
{
	return mT_LE1234B;
}
LensesTwoSurfaces ThorlabsLensCatalog::getT_LE1234C()
{
	return mT_LE1234C;
}
LensesTwoSurfaces ThorlabsLensCatalog::getT_LE1156()
{
	return mT_LE1156;
}
LensesTwoSurfaces ThorlabsLensCatalog::getT_LE1156A()
{
	return mT_LE1156A;
}
LensesTwoSurfaces ThorlabsLensCatalog::getT_LE1156B()
{
	return mT_LE1156B;
}
LensesTwoSurfaces ThorlabsLensCatalog::getT_LE1156C()
{
	return mT_LE1156C;
}
LensesTwoSurfaces ThorlabsLensCatalog::getT_LE1104()
{
	return mT_LE1104;
}
LensesTwoSurfaces ThorlabsLensCatalog::getT_LE1104A()
{
	return mT_LE1104A;
}
LensesTwoSurfaces ThorlabsLensCatalog::getT_LE1104B()
{
	return mT_LE1104B;
}
LensesTwoSurfaces ThorlabsLensCatalog::getT_LE1104C()
{
	return mT_LE1104C;
}
LensesTwoSurfaces ThorlabsLensCatalog::getT_LE1202()
{
	return mT_LE1202;
}
LensesTwoSurfaces ThorlabsLensCatalog::getT_LE1202A()
{
	return mT_LE1202A;
}
LensesTwoSurfaces ThorlabsLensCatalog::getT_LE1202B()
{
	return mT_LE1202B;
}
LensesTwoSurfaces ThorlabsLensCatalog::getT_LE1202C()
{
	return mT_LE1202C;
}
LensesTwoSurfaces ThorlabsLensCatalog::getT_LE1929()
{
	return mT_LE1929;
}
LensesTwoSurfaces ThorlabsLensCatalog::getT_LE1929A()
{
	return mT_LE1929A;
}
LensesTwoSurfaces ThorlabsLensCatalog::getT_LE1929B()
{
	return mT_LE1929B;
}
LensesTwoSurfaces ThorlabsLensCatalog::getT_LE1929C()
{
	return mT_LE1929C;
}
LensesTwoSurfaces ThorlabsLensCatalog::getT_LE1076()
{
	return mT_LE1076;
}
LensesTwoSurfaces ThorlabsLensCatalog::getT_LE1076A()
{
	return mT_LE1076A;
}
LensesTwoSurfaces ThorlabsLensCatalog::getT_LE1076B()
{
	return mT_LE1076B;
}
LensesTwoSurfaces ThorlabsLensCatalog::getT_LE1076C()
{
	return mT_LE1076C;
}
LensesTwoSurfaces ThorlabsLensCatalog::getT_LE1418()
{
	return mT_LE1418;
}
LensesTwoSurfaces ThorlabsLensCatalog::getT_LE1418A()
{
	return mT_LE1418A;
}
LensesTwoSurfaces ThorlabsLensCatalog::getT_LE1418B()
{
	return mT_LE1418B;
}
LensesTwoSurfaces ThorlabsLensCatalog::getT_LE1418C()
{
	return mT_LE1418C;
}
LensesTwoSurfaces ThorlabsLensCatalog::getT_LE1015()
{
	return mT_LE1015;
}
LensesTwoSurfaces ThorlabsLensCatalog::getT_LE1015A()
{
	return mT_LE1015A;
}
LensesTwoSurfaces ThorlabsLensCatalog::getT_LE1015B()
{
	return mT_LE1015B;
}
LensesTwoSurfaces ThorlabsLensCatalog::getT_LE1015C()
{
	return mT_LE1015C;
}
LensesTwoSurfaces ThorlabsLensCatalog::getT_LE1613()
{
	return mT_LE1613;
}
LensesTwoSurfaces ThorlabsLensCatalog::getT_LE1613A()
{
	return mT_LE1613A;
}
LensesTwoSurfaces ThorlabsLensCatalog::getT_LE1613B()
{
	return mT_LE1613B;
}
LensesTwoSurfaces ThorlabsLensCatalog::getT_LE1613C()
{
	return mT_LE1613C;
}
LensesTwoSurfaces ThorlabsLensCatalog::getT_LE1985()
{
	return mT_LE1985;
}
LensesTwoSurfaces ThorlabsLensCatalog::getT_LE1985A()
{
	return mT_LE1985A;
}
LensesTwoSurfaces ThorlabsLensCatalog::getT_LE1985B()
{
	return mT_LE1985B;
}
LensesTwoSurfaces ThorlabsLensCatalog::getT_LE1985C()
{
	return mT_LE1985C;
}


// *** Ø1" N-BK7 Negative Meniscus Lenses
// https://www.thorlabs.de/newgrouppage9.cfm?objectgroup_id=902
LensesTwoSurfaces ThorlabsLensCatalog::getT_LF1822()
{
	return mT_LF1822;
}
LensesTwoSurfaces ThorlabsLensCatalog::getT_LF1547()
{
	return mT_LF1547;
}
LensesTwoSurfaces ThorlabsLensCatalog::getT_LF1097()
{
	return mT_LF1097;
}
LensesTwoSurfaces ThorlabsLensCatalog::getT_LF1015()
{
	return mT_LF1015;
}
LensesTwoSurfaces ThorlabsLensCatalog::getT_LF1544()
{
	return mT_LF1544;
}
LensesTwoSurfaces ThorlabsLensCatalog::getT_LF1988()
{
	return mT_LF1988;
}
LensesTwoSurfaces ThorlabsLensCatalog::getT_LF1141()
{
	return mT_LF1141;
}

LensesTwoSurfaces ThorlabsLensCatalog::getT_LF1822A()
{
	return mT_LF1822A;
}
LensesTwoSurfaces ThorlabsLensCatalog::getT_LF1547A()
{
	return mT_LF1547A;
}
LensesTwoSurfaces ThorlabsLensCatalog::getT_LF1097A()
{
	return mT_LF1097A;
}
LensesTwoSurfaces ThorlabsLensCatalog::getT_LF1015A()
{
	return mT_LF1015A;
}
LensesTwoSurfaces ThorlabsLensCatalog::getT_LF1544A()
{
	return mT_LF1544A;
}
LensesTwoSurfaces ThorlabsLensCatalog::getT_LF1988A()
{
	return mT_LF1988A;
}
LensesTwoSurfaces ThorlabsLensCatalog::getT_LF1141A()
{
	return mT_LF1141A;
}

LensesTwoSurfaces ThorlabsLensCatalog::getT_LF1822B()
{
	return mT_LF1822B;
}
LensesTwoSurfaces ThorlabsLensCatalog::getT_LF1547B()
{
	return mT_LF1547B;
}
LensesTwoSurfaces ThorlabsLensCatalog::getT_LF1097B()
{
	return mT_LF1097B;
}
LensesTwoSurfaces ThorlabsLensCatalog::getT_LF1015B()
{
	return mT_LF1015B;
}
LensesTwoSurfaces ThorlabsLensCatalog::getT_LF1544B()
{
	return mT_LF1544B;
}
LensesTwoSurfaces ThorlabsLensCatalog::getT_LF1988B()
{
	return mT_LF1988B;
}
LensesTwoSurfaces ThorlabsLensCatalog::getT_LF1141B()
{
	return mT_LF1141B;
}

LensesTwoSurfaces ThorlabsLensCatalog::getT_LF1822C()
{
	return mT_LF1822C;
}
LensesTwoSurfaces ThorlabsLensCatalog::getT_LF1547C()
{
	return mT_LF1547C;
}
LensesTwoSurfaces ThorlabsLensCatalog::getT_LF1097C()
{
	return mT_LF1097C;
}
LensesTwoSurfaces ThorlabsLensCatalog::getT_LF1015C()
{
	return mT_LF1015C;
}
LensesTwoSurfaces ThorlabsLensCatalog::getT_LF1544C()
{
	return mT_LF1544C;
}
LensesTwoSurfaces ThorlabsLensCatalog::getT_LF1988C()
{
	return mT_LF1988C;
}
LensesTwoSurfaces ThorlabsLensCatalog::getT_LF1141C()
{
	return mT_LF1141C;
}

// Steinheil Triplet Achromatic Lenses, Visible
// https://www.thorlabs.de/newgrouppage9.cfm?objectgroup_id=5370
LensFourSurfaces ThorlabsLensCatalog::getT_TRS064010A()
{
	return mT_TRS064010A;
}
LensFourSurfaces ThorlabsLensCatalog::getT_TRS127020A()
{
	return mT_TRS127020A;
}
LensFourSurfaces ThorlabsLensCatalog::getT_TRS254040A()
{
	return mT_TRS254040A;
}

LensFourSurfaces ThorlabsLensCatalog::getT_TRS127020AML()
{
	return mT_TRS127020AML;
}
LensFourSurfaces ThorlabsLensCatalog::getT_TRS254040AML()
{
	return mT_TRS254040AML;
}



// Hastings Triplet Achromatic Lenses, Visible
// https://www.thorlabs.de/newgrouppage9.cfm?objectgroup_id=5368
LensFourSurfaces ThorlabsLensCatalog::getT_TRH064010A()
{
	return mT_TRH064010A;
}
LensFourSurfaces ThorlabsLensCatalog::getT_TRH127020A()
{
	return mT_TRH127020A;
}
LensFourSurfaces ThorlabsLensCatalog::getT_TRH254020A()
{
	return mT_TRH254040A;
}

LensFourSurfaces ThorlabsLensCatalog::getT_TRH127020AML()
{
	return mT_TRH127020AML;
}
LensFourSurfaces ThorlabsLensCatalog::getT_TRH254020AML()
{
	return mT_TRH254040AML;
}