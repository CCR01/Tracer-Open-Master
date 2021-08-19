#include "EdmundOpticsLensCatalog.h"


EdmundOpticsLensCatalog::EdmundOpticsLensCatalog() { mGlasses.loadGlassCatalog_Schott(); };

EdmundOpticsLensCatalog::~EdmundOpticsLensCatalog() {};


void EdmundOpticsLensCatalog::loadLensCatalogEO_plan_concav_lenses_VIS_NIR() //https://www.edmundoptics.de/p/3mm-diameter-x6-fl-vis-nir-coated-plano-concave-lens/27489/
{
	EO84380.buildLensTwoSurfaces_PCV(/*lens catalog*/ "EO", /*catalog number*/ 84380, /*diameter*/3.0, /*max tolerance diameter*/0.0, /*min tolerance diameter*/-0.025, /*back focal length*/-6.56,
		/*max surface quality*/40.0, /*min surface quality*/20.0, /*irregularity*/4.0, /*tolerance center thickness*/0.1, /*design wavelength*/587.6,
		/*free aperture CA*/2.7, /*radius*/-4.71, /*numerical Aperture*/0.25, /*min wavelength range*/400, /*max wavelength range*/1000, /*focal length*/-6.00219,
		/*Coating*/"VIS-NIR (400-1000nm)", /*material*/mGlasses.getSF11_S1(), /*power (P-V)*/1.5, /*center thickness*/ 1.0,/*tolerance focal lenght*/1.0,
		/*Centering (arc minutes)*/3.0, /*edge thickness*/1.17, /*price*/ 61.0, /*wavelength to trace through optical system*/550.0);

	EO84381.buildLensTwoSurfaces_PCV(/*lens catalog*/ "EO", /*catalog number*/ 84381, /*diameter*/3.0, /*max tolerance diameter*/0.0, /*min tolerance diameter*/-0.025, /*back focal length*/-9.56,
		/*max surface quality*/40.0, /*min surface quality*/20.0, /*irregularity*/4.0, /*tolerance center thickness*/0.1, /*design wavelength*/587.6,
		/*free aperture CA*/2.7, /*radius*/-7.06, /*numerical Aperture*/0.17, /*min wavelength range*/400, /*max wavelength range*/1000, /*focal length*/-8.99691,
		/*Coating*/"VIS-NIR (400-1000nm)", /*material*/mGlasses.getSF11_S1(), /*power (P-V)*/1.5, /*center thickness*/ 1.0,/*tolerance focal lenght*/1.0,
		/*Centering (arc minutes)*/3.0, /*edge thickness*/1.11, /*price*/ 61.0, /*wavelength to trace through optical system*/550.0);

	EO45910.buildLensTwoSurfaces_PCV(/*lens catalog*/ "EO", /*catalog number*/ 45910, /*diameter*/6.0, /*max tolerance diameter*/0.0, /*min tolerance diameter*/-0.025, /*back focal length*/-6.84,
		/*max surface quality*/40.0, /*min surface quality*/20.0, /*irregularity*/4.0, /*tolerance center thickness*/0.1, /*design wavelength*/587.6,
		/*free aperture CA*/5.4, /*radius*/-4.71, /*numerical Aperture*/0.5, /*min wavelength range*/400, /*max wavelength range*/1000, /*focal length*/-6.00219,
		/*Coating*/"VIS-NIR (400-1000nm)", /*material*/mGlasses.getSF11_S1(), /*power (P-V)*/1.5, /*center thickness*/ 1.5,/*tolerance focal lenght*/1.0,
		/*Centering (arc minutes)*/3.0, /*edge thickness*/2.22, /*price*/ 35.5, /*wavelength to trace through optical system*/550.0);

	EO48345.buildLensTwoSurfaces_PCV(/*lens catalog*/ "EO", /*catalog number*/ 48345, /*diameter*/6.0, /*max tolerance diameter*/0.0, /*min tolerance diameter*/-0.025, /*back focal length*/-9.84,
		/*max surface quality*/40.0, /*min surface quality*/20.0, /*irregularity*/4.0, /*tolerance center thickness*/0.1, /*design wavelength*/587.6,
		/*free aperture CA*/5.4, /*radius*/-7.06, /*numerical Aperture*/0.33, /*min wavelength range*/400, /*max wavelength range*/1000, /*focal length*/-8.99691,
		/*Coating*/"VIS-NIR (400-1000nm)", /*material*/mGlasses.getSF11_S1(), /*power (P-V)*/1.5, /*center thickness*/ 1.5,/*tolerance focal lenght*/1.0,
		/*Centering (arc minutes)*/3.0, /*edge thickness*/2.04, /*price*/ 35.5, /*wavelength to trace through optical system*/550.0);

	EO45911.buildLensTwoSurfaces_PCV(/*lens catalog*/ "EO", /*catalog number*/ 45911, /*diameter*/6.0, /*max tolerance diameter*/0.0, /*min tolerance diameter*/-0.025, /*back focal length*/-12.99,
		/*max surface quality*/40.0, /*min surface quality*/20.0, /*irregularity*/4.0, /*tolerance center thickness*/0.1, /*design wavelength*/587.6,
		/*free aperture CA*/5.4, /*radius*/-6.2, /*numerical Aperture*/0.25, /*min wavelength range*/400, /*max wavelength range*/1000, /*focal length*/-11.9969,
		/*Coating*/"VIS-NIR (400-1000nm)", /*material*/mGlasses.getNBK7_S1(), /*power (P-V)*/1.5, /*center thickness*/1.5, /*tolerance focal lenght*/1.0,
		/*Centering (arc minutes)*/1.0, /*edge thickness*/2.12, /*price*/ 35.5, /*wavelength to trace through optical system*/550.0);

	EO48696.buildLensTwoSurfaces_PCV(/*lens catalog*/ "EO", /*catalog number*/ 48696, /*diameter*/6.0, /*max tolerance diameter*/0.0, /*min tolerance diameter*/-0.025, /*back focal length*/-16.32,
		/*max surface quality*/40.0, /*min surface quality*/20.0, /*irregularity*/4.0, /*tolerance center thickness*/0.1, /*design wavelength*/587.6,
		/*free aperture CA*/5.4, /*radius*/-7.752, /*numerical Aperture*/0.2, /*min wavelength range*/400, /*max wavelength range*/1000, /*focal length*/-15.0,
		/*Coating*/"VIS-NIR (400-1000nm)", /*material*/mGlasses.getNBK7_S1(), /*power (P-V)*/1.5, /*center thickness*/2.0, /*tolerance focal lenght*/1.0,
		/*Centering (arc minutes)*/1.0, /*edge thickness*/2.49, /*price*/ 35.5, /*wavelength to trace through optical system*/550.0);

	EO45912.buildLensTwoSurfaces_PCV(/*lens catalog*/ "EO", /*catalog number*/ 45912, /*diameter*/6.0, /*max tolerance diameter*/0.0, /*min tolerance diameter*/-0.025, /*back focal length*/-19.32,
		/*max surface quality*/40.0, /*min surface quality*/20.0, /*irregularity*/4.0, /*tolerance center thickness*/0.1, /*design wavelength*/587.6,
		/*free aperture CA*/5.4, /*radius*/-9.3, /*numerical Aperture*/0.17, /*min wavelength range*/400, /*max wavelength range*/1000, /*focal length*/-17.9954,
		/*Coating*/"VIS-NIR (400-1000nm)", /*material*/mGlasses.getNBK7_S1(), /*power (P-V)*/1.5, /*center thickness*/2.0, /*tolerance focal lenght*/1.0,
		/*Centering (arc minutes)*/1.0, /*edge thickness*/2.4, /*price*/ 35.5, /*wavelength to trace through optical system*/550.0);

	EO45913.buildLensTwoSurfaces_PCV(/*lens catalog*/ "EO", /*catalog number*/ 45913, /*diameter*/9.0, /*max tolerance diameter*/0.0, /*min tolerance diameter*/-0.025, /*back focal length*/-10.21,
		/*max surface quality*/40.0, /*min surface quality*/20.0, /*irregularity*/4.0, /*tolerance center thickness*/0.1, /*design wavelength*/587.6,
		/*free aperture CA*/8.1, /*radius*/-7.07, /*numerical Aperture*/0.5, /*min wavelength range*/400, /*max wavelength range*/1000, /*focal length*/-9.00965,
		/*Coating*/"VIS-NIR (400-1000nm)", /*material*/mGlasses.getNSF11_S1(), /*power (P-V)*/1.5, /*center thickness*/2.25, /*tolerance focal lenght*/1.0,
		/*Centering (arc minutes)*/3.0, /*edge thickness*/3.63, /*price*/ 36.5, /*wavelength to trace through optical system*/550.0);

	EO48346.buildLensTwoSurfaces_PCV(/*lens catalog*/ "EO", /*catalog number*/ 48346, /*diameter*/9.0, /*max tolerance diameter*/0.0, /*min tolerance diameter*/-0.025, /*back focal length*/-13.26,
		/*max surface quality*/40.0, /*min surface quality*/20.0, /*irregularity*/4.0, /*tolerance center thickness*/0.1, /*design wavelength*/587.6,
		/*free aperture CA*/8.1, /*radius*/-9.42, /*numerical Aperture*/0.38, /*min wavelength range*/400, /*max wavelength range*/1000, /*focal length*/-12.0044,
		/*Coating*/"VIS-NIR (400-1000nm)", /*material*/mGlasses.getNSF11_S1(), /*power (P-V)*/1.5, /*center thickness*/2.25, /*tolerance focal lenght*/1.0,
		/*Centering (arc minutes)*/1.0, /*edge thickness*/3.24, /*price*/ 36.5, /*wavelength to trace through optical system*/550.0);

	EO45914.buildLensTwoSurfaces_PCV(/*lens catalog*/ "EO", /*catalog number*/ 45914, /*diameter*/9.0, /*max tolerance diameter*/0.0, /*min tolerance diameter*/-0.025, /*back focal length*/-19.26,
		/*max surface quality*/40.0, /*min surface quality*/20.0, /*irregularity*/4.0, /*tolerance center thickness*/0.1, /*design wavelength*/587.6,
		/*free aperture CA*/8.1, /*radius*/-14.12, /*numerical Aperture*/0.25, /*min wavelength range*/400, /*max wavelength range*/1000, /*focal length*/-17.9938,
		/*Coating*/"VIS-NIR (400-1000nm)", /*material*/mGlasses.getNSF11_S1(), /*power (P-V)*/1.5, /*center thickness*/2.25, /*tolerance focal lenght*/1.0,
		/*Centering (arc minutes)*/1.0, /*edge thickness*/2.89, /*price*/ 36.5, /*wavelength to trace through optical system*/550.0);

	EO45915.buildLensTwoSurfaces_PCV(/*lens catalog*/ "EO", /*catalog number*/ 45915, /*diameter*/9.0, /*max tolerance diameter*/0.0, /*min tolerance diameter*/-0.025, /*back focal length*/-28.68,
		/*max surface quality*/40.0, /*min surface quality*/20.0, /*irregularity*/4.0, /*tolerance center thickness*/0.1, /*design wavelength*/587.6,
		/*free aperture CA*/8.1, /*radius*/-21.19, /*numerical Aperture*/0.17, /*min wavelength range*/400, /*max wavelength range*/1000, /*focal length*/-27.0035,
		/*Coating*/"VIS-NIR (400-1000nm)", /*material*/mGlasses.getNSF11_S1(), /*power (P-V)*/1.5, /*center thickness*/3.0, /*tolerance focal lenght*/1.0,
		/*Centering (arc minutes)*/1.0, /*edge thickness*/3.42, /*price*/ 36.5, /*wavelength to trace through optical system*/550.0);

	EO45916.buildLensTwoSurfaces_PCV(/*lens catalog*/ "EO", /*catalog number*/ 45916, /*diameter*/12.0, /*max tolerance diameter*/0.0, /*min tolerance diameter*/-0.025, /*back focal length*/-13.23,
		/*max surface quality*/40.0, /*min surface quality*/20.0, /*irregularity*/4.0, /*tolerance center thickness*/0.1, /*design wavelength*/587.6,
		/*free aperture CA*/11.0, /*radius*/-9.42, /*numerical Aperture*/0.5, /*min wavelength range*/400, /*max wavelength range*/1000, /*focal length*/-12.0044,
		/*Coating*/"VIS-NIR (400-1000nm)", /*material*/mGlasses.getNSF11_S1(), /*power (P-V)*/1.5, /*center thickness*/2.2, /*tolerance focal lenght*/1.0,
		/*Centering (arc minutes)*/1.0, /*edge thickness*/4.12, /*price*/ 37.5, /*wavelength to trace through optical system*/550.0);

	EO48697.buildLensTwoSurfaces_PCV(/*lens catalog*/ "EO", /*catalog number*/ 48697, /*diameter*/12.0, /*max tolerance diameter*/0.0, /*min tolerance diameter*/-0.025, /*back focal length*/-16.68,
		/*max surface quality*/40.0, /*min surface quality*/20.0, /*irregularity*/4.0, /*tolerance center thickness*/0.1, /*design wavelength*/587.6,
		/*free aperture CA*/11.0, /*radius*/-11.771, /*numerical Aperture*/0.4, /*min wavelength range*/400, /*max wavelength range*/1000, /*focal length*/-15.0004,
		/*Coating*/"VIS-NIR (400-1000nm)", /*material*/mGlasses.getNSF11_S1(), /*power (P-V)*/1.5, /*center thickness*/3.0, /*tolerance focal lenght*/1.0,
		/*Centering (arc minutes)*/1.0, /*edge thickness*/4.47, /*price*/ 37.5, /*wavelength to trace through optical system*/550.0);

	EO48347.buildLensTwoSurfaces_PCV(/*lens catalog*/ "EO", /*catalog number*/ 48347, /*diameter*/12.0, /*max tolerance diameter*/0.0, /*min tolerance diameter*/-0.025, /*back focal length*/-19.95,
		/*max surface quality*/40.0, /*min surface quality*/20.0, /*irregularity*/4.0, /*tolerance center thickness*/0.1, /*design wavelength*/587.6,
		/*free aperture CA*/11.0, /*radius*/-14.12, /*numerical Aperture*/0.33, /*min wavelength range*/400, /*max wavelength range*/1000, /*focal length*/-17.9938,
		/*Coating*/"VIS-NIR (400-1000nm)", /*material*/mGlasses.getNSF11_S1(), /*power (P-V)*/1.5, /*center thickness*/3.5, /*tolerance focal lenght*/1.0,
		/*Centering (arc minutes)*/1.0, /*edge thickness*/4.7, /*price*/ 37.5, /*wavelength to trace through optical system*/550.0);

	EO45917.buildLensTwoSurfaces_PCV(/*lens catalog*/ "EO", /*catalog number*/ 45917, /*diameter*/12.0, /*max tolerance diameter*/0.0, /*min tolerance diameter*/-0.025, /*back focal length*/-26.32,
		/*max surface quality*/40.0, /*min surface quality*/20.0, /*irregularity*/4.0, /*tolerance center thickness*/0.1, /*design wavelength*/587.6,
		/*free aperture CA*/11.0, /*radius*/-12.4, /*numerical Aperture*/0.25, /*min wavelength range*/400, /*max wavelength range*/1000, /*focal length*/-23.9939,
		/*Coating*/"VIS-NIR (400-1000nm)", /*material*/mGlasses.getNBK7_S1(), /*power (P-V)*/1.5, /*center thickness*/3.5, /*tolerance focal lenght*/1.0,
		/*Centering (arc minutes)*/1.0, /*edge thickness*/4.79, /*price*/ 37.5, /*wavelength to trace through optical system*/550.0);

	EO45918.buildLensTwoSurfaces_PCV(/*lens catalog*/ "EO", /*catalog number*/ 45918, /*diameter*/12.0, /*max tolerance diameter*/0.0, /*min tolerance diameter*/-0.025, /*back focal length*/-50.31,
		/*max surface quality*/40.0, /*min surface quality*/20.0, /*irregularity*/4.0, /*tolerance center thickness*/0.1, /*design wavelength*/587.6,
		/*free aperture CA*/11.0, /*radius*/-24.81, /*numerical Aperture*/0.13, /*min wavelength range*/400, /*max wavelength range*/1000, /*focal length*/-48.0071,
		/*Coating*/"VIS-NIR (400-1000nm)", /*material*/mGlasses.getNBK7_S1(), /*power (P-V)*/1.5, /*center thickness*/3.5, /*tolerance focal lenght*/1.0,
		/*Centering (arc minutes)*/1.0, /*edge thickness*/4.12, /*price*/ 37.5, /*wavelength to trace through optical system*/550.0);

	EO45919.buildLensTwoSurfaces_PCV(/*lens catalog*/ "EO", /*catalog number*/ 45919, /*diameter*/20.0, /*max tolerance diameter*/0.0, /*min tolerance diameter*/-0.025, /*back focal length*/-31.96,
		/*max surface quality*/40.0, /*min surface quality*/20.0, /*irregularity*/4.0, /*tolerance center thickness*/0.1, /*design wavelength*/587.6,
		/*free aperture CA*/19.0, /*radius*/-23.54, /*numerical Aperture*/0.33, /*min wavelength range*/400, /*max wavelength range*/1000, /*focal length*/-29.9982,
		/*Coating*/"VIS-NIR (400-1000nm)", /*material*/mGlasses.getNSF11_S1(), /*power (P-V)*/1.5, /*center thickness*/3.5, /*tolerance focal lenght*/1.0,
		/*Centering (arc minutes)*/1.0, /*edge thickness*/5.39, /*price*/ 37.5, /*wavelength to trace through optical system*/550.0);

	EO45920.buildLensTwoSurfaces_PCV(/*lens catalog*/ "EO", /*catalog number*/ 45920, /*diameter*/20.0, /*max tolerance diameter*/0.0, /*min tolerance diameter*/-0.025, /*back focal length*/-42.31,
		/*max surface quality*/40.0, /*min surface quality*/20.0, /*irregularity*/4.0, /*tolerance center thickness*/0.1, /*design wavelength*/587.6,
		/*free aperture CA*/19.0, /*radius*/-20.67, /*numerical Aperture*/0.25, /*min wavelength range*/400, /*max wavelength range*/1000, /*focal length*/-39.9963,
		/*Coating*/"VIS-NIR (400-1000nm)", /*material*/mGlasses.getNBK7_S1(), /*power (P-V)*/1.5, /*center thickness*/3.5, /*tolerance focal lenght*/1.0,
		/*Centering (arc minutes)*/1.0, /*edge thickness*/5.39, /*price*/ 37.5, /*wavelength to trace through optical system*/550.0);

	EO45921.buildLensTwoSurfaces_PCV(/*lens catalog*/ "EO", /*catalog number*/ 45921, /*diameter*/20.0, /*max tolerance diameter*/0.0, /*min tolerance diameter*/-0.025, /*back focal length*/-52.31,
		/*max surface quality*/40.0, /*min surface quality*/20.0, /*irregularity*/4.0, /*tolerance center thickness*/0.1, /*design wavelength*/587.6,
		/*free aperture CA*/19.0, /*radius*/-25.84, /*numerical Aperture*/0.2, /*min wavelength range*/400, /*max wavelength range*/1000, /*focal length*/-50.0002,
		/*Coating*/"VIS-NIR (400-1000nm)", /*material*/mGlasses.getNBK7_S1(), /*power (P-V)*/1.5, /*center thickness*/3.5, /*tolerance focal lenght*/1.0,
		/*Centering (arc minutes)*/1.0, /*edge thickness*/3.5, /*price*/ 37.5, /*wavelength to trace through optical system*/550.0);

	EO45922.buildLensTwoSurfaces_PCV(/*lens catalog*/ "EO", /*catalog number*/ 45922, /*diameter*/25.0, /*max tolerance diameter*/0.0, /*min tolerance diameter*/-0.025, /*back focal length*/-26.96,
		/*max surface quality*/40.0, /*min surface quality*/20.0, /*irregularity*/4.0, /*tolerance center thickness*/0.1, /*design wavelength*/587.6,
		/*free aperture CA*/24.0, /*radius*/-19.62, /*numerical Aperture*/0.5, /*min wavelength range*/400, /*max wavelength range*/1000, /*focal length*/-25.0027,
		/*Coating*/"VIS-NIR (400-1000nm)", /*material*/mGlasses.getNSF11_S1(), /*power (P-V)*/1.5, /*center thickness*/3.5, /*tolerance focal lenght*/1.0,
		/*Centering (arc minutes)*/1.0, /*edge thickness*/7.41, /*price*/ 42.0, /*wavelength to trace through optical system*/550.0);

	EO48698.buildLensTwoSurfaces_PCV(/*lens catalog*/ "EO", /*catalog number*/ 48698, /*diameter*/25.0, /*max tolerance diameter*/0.0, /*min tolerance diameter*/-0.025, /*back focal length*/-36.96,
		/*max surface quality*/40.0, /*min surface quality*/20.0, /*irregularity*/4.0, /*tolerance center thickness*/0.1, /*design wavelength*/587.6,
		/*free aperture CA*/24.0, /*radius*/-27.465, /*numerical Aperture*/0.36, /*min wavelength range*/400, /*max wavelength range*/1000, /*focal length*/-35.0,
		/*Coating*/"VIS-NIR (400-1000nm)", /*material*/mGlasses.getNSF11_S1(), /*power (P-V)*/1.5, /*center thickness*/3.5, /*tolerance focal lenght*/1.0,
		/*Centering (arc minutes)*/1.0, /*edge thickness*/6.36, /*price*/ 42.0, /*wavelength to trace through optical system*/550.0);

	EO45923.buildLensTwoSurfaces_PCV(/*lens catalog*/ "EO", /*catalog number*/ 45923, /*diameter*/25.0, /*max tolerance diameter*/0.0, /*min tolerance diameter*/-0.025, /*back focal length*/-52.31,
		/*max surface quality*/40.0, /*min surface quality*/20.0, /*irregularity*/4.0, /*tolerance center thickness*/0.1, /*design wavelength*/587.6,
		/*free aperture CA*/24.0, /*radius*/-25.84, /*numerical Aperture*/0.25, /*min wavelength range*/400, /*max wavelength range*/1000, /*focal length*/-50.0002,
		/*Coating*/"VIS-NIR (400-1000nm)", /*material*/mGlasses.getNBK7_S1(), /*power (P-V)*/1.5, /*center thickness*/3.5, /*tolerance focal lenght*/1.0,
		/*Centering (arc minutes)*/1.0, /*edge thickness*/6.33, /*price*/ 42.0, /*wavelength to trace through optical system*/550.0);

	EO45924.buildLensTwoSurfaces_PCV(/*lens catalog*/ "EO", /*catalog number*/ 45924, /*diameter*/25.0, /*max tolerance diameter*/0.0, /*min tolerance diameter*/-0.025, /*back focal length*/-102.31,
		/*max surface quality*/40.0, /*min surface quality*/20.0, /*irregularity*/4.0, /*tolerance center thickness*/0.1, /*design wavelength*/587.6,
		/*free aperture CA*/24.0, /*radius*/-51.68, /*numerical Aperture*/0.13, /*min wavelength range*/400, /*max wavelength range*/1000, /*focal length*/-100.0,
		/*Coating*/"VIS-NIR (400-1000nm)", /*material*/mGlasses.getNBK7_S1(), /*power (P-V)*/1.5, /*center thickness*/3.5, /*tolerance focal lenght*/1.0,
		/*Centering (arc minutes)*/1.0, /*edge thickness*/4.85, /*price*/ 42.0, /*wavelength to trace through optical system*/550.0);

	EO45925.buildLensTwoSurfaces_PCV(/*lens catalog*/ "EO", /*catalog number*/ 45925, /*diameter*/50.0, /*max tolerance diameter*/0.0, /*min tolerance diameter*/-0.025, /*back focal length*/-103.3,
		/*max surface quality*/40.0, /*min surface quality*/20.0, /*irregularity*/4.0, /*tolerance center thickness*/0.1, /*design wavelength*/587.6,
		/*free aperture CA*/49.0, /*radius*/-51.68, /*numerical Aperture*/0.25, /*min wavelength range*/400, /*max wavelength range*/1000, /*focal length*/-100.0,
		/*Coating*/"VIS-NIR (400-1000nm)", /*material*/mGlasses.getNBK7_S1(), /*power (P-V)*/1.5, /*center thickness*/5.0, /*tolerance focal lenght*/1.0,
		/*Centering (arc minutes)*/1.0, /*edge thickness*/11.23, /*price*/ 64.5, /*wavelength to trace through optical system*/550.0);

	EO45926.buildLensTwoSurfaces_PCV(/*lens catalog*/ "EO", /*catalog number*/ 45926, /*diameter*/50.0, /*max tolerance diameter*/0.0, /*min tolerance diameter*/-0.025, /*back focal length*/-128.3,
		/*max surface quality*/40.0, /*min surface quality*/20.0, /*irregularity*/4.0, /*tolerance center thickness*/0.1, /*design wavelength*/587.6,
		/*free aperture CA*/49.0, /*radius*/-64.6, /*numerical Aperture*/0.2, /*min wavelength range*/400, /*max wavelength range*/1000, /*focal length*/-125.0,
		/*Coating*/"VIS-NIR (400-1000nm)", /*material*/mGlasses.getNBK7_S1(), /*power (P-V)*/1.5, /*center thickness*/5.0, /*tolerance focal lenght*/1.0,
		/*Centering (arc minutes)*/1.0, /*edge thickness*/9.87, /*price*/ 64.5, /*wavelength to trace through optical system*/550.0);

}






void EdmundOpticsLensCatalog::loadLensCatalogEO_double_concav_lenses_VIS_NIR()  //https://www.edmundoptics.de/f/vis-nir-coated-double-concave-dcv-lenses/13540/
{
	// Doppelkonkave (DCV) Linsen VIS-NIR AR beschichtet (without INK lenses like #45-927 INK)

	EO45927.buildLensTwoSurfaces_DCV(/*lens catalog*/ "EO", /*catalog number*/ 45927, /*diameter*/6.0, /*max tolerance diameter*/0.0, /*min tolerance diameter*/-0.025,/*max surface quality*/40.0,
		/*back focal length*/-6.41,/*min surface quality*/20.0, /*irregularity*/4.0, /*center thickness*/  1.5, /*Centering (arc minutes)*/3.0, /*edge thickness*/2.29,
		/*design wavelength*/587.6, /*numerical Aperture*/0.5, /*min wavelength range*/400, /*max wavelength range*/1000, /*focal length*/-6.00285,
		/*Coating*/"VIS-NIR (400-1000nm)", /*material*/mGlasses.getSF11_S1(), /*power (P-V)*/1.5, /*free aperture CA*/5.4,/*tolerance center thickness*/0.1,
		/*tolerance focal lenght*/1.0, /*radius*/-9.74, /*price*/  35.50,/*wavelength to trace through optical system*/550.0);

	EO48941.buildLensTwoSurfaces_DCV(/*lens catalog*/ "EO", /*catalog number*/ 48941, /*diameter*/6.0, /*max tolerance diameter*/0.0, /*min tolerance diameter*/-0.025,/*max surface quality*/40.0,
		/*back focal length*/-9.32,/*min surface quality*/20.0, /*irregularity*/4.0, /*center thickness*/  1.0, /*Centering (arc minutes)*/3.0, /*edge thickness*/1.79,
		/*design wavelength*/587.6, /*numerical Aperture*/0.5, /*min wavelength range*/400, /*max wavelength range*/1000, /*focal length*/-9.00027,
		/*Coating*/"VIS-NIR (400-1000nm)", /*material*/mGlasses.getNBK7_S1(), /*power (P-V)*/1.5, /*free aperture CA*/5.4,/*tolerance center thickness*/0.1,
		/*tolerance focal lenght*/1.0, /*radius*/-9.47, /*price*/  35.50,/*wavelength to trace through optical system*/550.0);

	EO48699.buildLensTwoSurfaces_DCV(/*lens catalog*/ "EO", /*catalog number*/ 48699, /*diameter*/6.0, /*max tolerance diameter*/0.0, /*min tolerance diameter*/-0.025,/*max surface quality*/40.0,
		/*back focal length*/-12.33,/*min surface quality*/20.0, /*irregularity*/4.0, /*center thickness*/  1.0, /*Centering (arc minutes)*/1.0, /*edge thickness*/1.59,
		/*design wavelength*/587.6, /*numerical Aperture*/0.5, /*min wavelength range*/400, /*max wavelength range*/1000, /*focal length*/-11.9998,
		/*Coating*/"VIS-NIR (400-1000nm)", /*material*/mGlasses.getNBK7_S1(), /*power (P-V)*/1.5, /*free aperture CA*/5.4,/*tolerance center thickness*/0.1,
		/*tolerance focal lenght*/1.0, /*radius*/-12.571, /*price*/  35.50,/*wavelength to trace through optical system*/550.0);

	EO48348.buildLensTwoSurfaces_DCV(/*lens catalog*/ "EO", /*catalog number*/ 48348, /*diameter*/9.0, /*max tolerance diameter*/0.0, /*min tolerance diameter*/-0.025,/*max surface quality*/40.0,
		/*back focal length*/-9.61,/*min surface quality*/20.0, /*irregularity*/4.0, /*center thickness*/  2.25, /*Centering (arc minutes)*/3.0, /*edge thickness*/3.48,
		/*design wavelength*/587.6, /*numerical Aperture*/0.5, /*min wavelength range*/400, /*max wavelength range*/1000, /*focal length*/-8.9979,
		/*Coating*/"VIS-NIR (400-1000nm)", /*material*/mGlasses.getNSF11_S1(), /*power (P-V)*/1.5, /*free aperture CA*/8.1,/*tolerance center thickness*/0.1,
		/*tolerance focal lenght*/1.0, /*radius*/-14.6, /*price*/  36.50,/*wavelength to trace through optical system*/550.0);

	EO48942.buildLensTwoSurfaces_DCV(/*lens catalog*/ "EO", /*catalog number*/ 48942, /*diameter*/9.0, /*max tolerance diameter*/0.0, /*min tolerance diameter*/-0.025,/*max surface quality*/40.0,
		/*back focal length*/-12.41,/*min surface quality*/20.0, /*irregularity*/4.0, /*center thickness*/  1.5, /*Centering (arc minutes)*/1.0, /*edge thickness*/2.43,
		/*design wavelength*/587.6, /*numerical Aperture*/0.38, /*min wavelength range*/400, /*max wavelength range*/1000, /*focal length*/-11.9998,
		/*Coating*/"VIS-NIR (400-1000nm)", /*material*/mGlasses.getNSF11_S1(), /*power (P-V)*/1.5, /*free aperture CA*/8.1,/*tolerance center thickness*/0.1,
		/*tolerance focal lenght*/1.0, /*radius*/-19.157, /*price*/  36.50,/*wavelength to trace through optical system*/550.0);

	EO48700.buildLensTwoSurfaces_DCV(/*lens catalog*/ "EO", /*catalog number*/ 48700, /*diameter*/9.0, /*max tolerance diameter*/0.0, /*min tolerance diameter*/-0.025,/*max surface quality*/40.0,
		/*back focal length*/-18.49,/*min surface quality*/20.0, /*irregularity*/4.0, /*center thickness*/  1.5, /*Centering (arc minutes)*/1.0, /*edge thickness*/2.45,
		/*design wavelength*/587.6, /*numerical Aperture*/0.25, /*min wavelength range*/400, /*max wavelength range*/1000, /*focal length*/-18.0001,
		/*Coating*/"VIS-NIR (400-1000nm)", /*material*/mGlasses.getNBK7_S1(), /*power (P-V)*/1.5, /*free aperture CA*/8.1,/*tolerance center thickness*/0.1,
		/*tolerance focal lenght*/1.0, /*radius*/-18.857, /*price*/  36.50,/*wavelength to trace through optical system*/550.0);

	EO45928.buildLensTwoSurfaces_DCV(/*lens catalog*/ "EO", /*catalog number*/ 45928, /*diameter*/12.0, /*max tolerance diameter*/0.0, /*min tolerance diameter*/-0.025,/*max surface quality*/40.0,
		/*back focal length*/-12.81,/*min surface quality*/20.0, /*irregularity*/4.0, /*center thickness*/  3.0, /*Centering (arc minutes)*/1.0, /*edge thickness*/4.71,
		/*design wavelength*/587.6, /*numerical Aperture*/0.5, /*min wavelength range*/400, /*max wavelength range*/1000, /*focal length*/-11.9993,
		/*Coating*/"VIS-NIR (400-1000nm)", /*material*/mGlasses.getNSF11_S1(), /*power (P-V)*/1.5, /*free aperture CA*/11.0,/*tolerance center thickness*/0.1,
		/*tolerance focal lenght*/1.0, /*radius*/-19.47, /*price*/  37.50,/*wavelength to trace through optical system*/550.0);

	EO48943.buildLensTwoSurfaces_DCV(/*lens catalog*/ "EO", /*catalog number*/ 48943, /*diameter*/12.0, /*max tolerance diameter*/0.0, /*min tolerance diameter*/-0.025,/*max surface quality*/40.0,
		/*back focal length*/-18.65,/*min surface quality*/20.0, /*irregularity*/4.0, /*center thickness*/  2.0, /*Centering (arc minutes)*/1.0, /*edge thickness*/3.76,
		/*design wavelength*/587.6, /*numerical Aperture*/0.33, /*min wavelength range*/400, /*max wavelength range*/1000, /*focal length*/-17.9996,
		/*Coating*/"VIS-NIR (400-1000nm)", /*material*/mGlasses.getNBK7_S1(), /*power (P-V)*/1.5, /*free aperture CA*/10.8,/*tolerance center thickness*/0.1,
		/*tolerance focal lenght*/1.0, /*radius*/-18.939, /*price*/  37.50,/*wavelength to trace through optical system*/550.0);

	EO48701.buildLensTwoSurfaces_DCV(/*lens catalog*/ "EO", /*catalog number*/ 48701, /*diameter*/12.0, /*max tolerance diameter*/0.0, /*min tolerance diameter*/-0.025,/*max surface quality*/40.0,
		/*back focal length*/-24.65,/*min surface quality*/20.0, /*irregularity*/4.0, /*center thickness*/  2.0, /*Centering (arc minutes)*/1.0, /*edge thickness*/3.31,
		/*design wavelength*/587.6, /*numerical Aperture*/0.25, /*min wavelength range*/400, /*max wavelength range*/1000, /*focal length*/-23.9995,
		/*Coating*/"VIS-NIR (400-1000nm)", /*material*/mGlasses.getNBK7_S1(), /*power (P-V)*/1.5, /*free aperture CA*/11.0, /*tolerance center thickness*/0.1,
		/*tolerance focal lenght*/1.0, /*radius*/-25.142, /*price*/  37.50,/*wavelength to trace through optical system*/550.0);

	EO45929.buildLensTwoSurfaces_DCV(/*lens catalog*/ "EO", /*catalog number*/ 45929, /*diameter*/20.0, /*max tolerance diameter*/0.0, /*min tolerance diameter*/-0.025,/*max surface quality*/40.0,
		/*back focal length*/-20.55,/*min surface quality*/20.0, /*irregularity*/4.0, /*center thickness*/  2.0, /*Centering (arc minutes)*/1.0, /*edge thickness*/5.03,
		/*design wavelength*/587.6, /*numerical Aperture*/0.5, /*min wavelength range*/400, /*max wavelength range*/1000, /*focal length*/-19.9986,
		/*Coating*/"VIS-NIR (400-1000nm)", /*material*/mGlasses.getNSF11_S1(), /*power (P-V)*/1.5, /*free aperture CA*/19.0, /*tolerance center thickness*/0.1,
		/*tolerance focal lenght*/1.0, /*radius*/-31.82, /*price*/  37.50,/*wavelength to trace through optical system*/550.0);

	EO45930.buildLensTwoSurfaces_DCV(/*lens catalog*/ "EO", /*catalog number*/ 45931, /*diameter*/25.0, /*max tolerance diameter*/0.0, /*min tolerance diameter*/-0.025,/*max surface quality*/40.0,
		/*back focal length*/-25.69,/*min surface quality*/20.0, /*irregularity*/4.0, /*center thickness*/  2.5, /*Centering (arc minutes)*/1.0, /*edge thickness*/6.05,
		/*design wavelength*/587.6, /*numerical Aperture*/0.5, /*min wavelength range*/400, /*max wavelength range*/1000, /*focal length*/-25.0014,
		/*Coating*/"VIS-NIR (400-1000nm)", /*material*/mGlasses.getNSF11_S1(), /*power (P-V)*/1.5, /*free aperture CA*/24.0, /*tolerance center thickness*/0.1,
		/*tolerance focal lenght*/1.0, /*radius*/-39.78, /*price*/  42.0,/*wavelength to trace through optical system*/550.0);

	EO45931.buildLensTwoSurfaces_DCV(/*lens catalog*/ "EO", /*catalog number*/ 45931, /*diameter*/25.0, /*max tolerance diameter*/0.0, /*min tolerance diameter*/-0.025,/*max surface quality*/40.0,
		/*back focal length*/-50.82,/*min surface quality*/20.0, /*irregularity*/4.0, /*center thickness*/  2.5, /*Centering (arc minutes)*/1.0, /*edge thickness*/5.4,
		/*design wavelength*/587.6, /*numerical Aperture*/0.25, /*min wavelength range*/400, /*max wavelength range*/1000, /*focal length*/-49.9978,
		/*Coating*/"VIS-NIR (400-1000nm)", /*material*/mGlasses.getNBK7_S1(), /*power (P-V)*/1.5, /*free aperture CA*/24.0, /*tolerance center thickness*/0.1,
		/*tolerance focal lenght*/1.0, /*radius*/-52.1, /*price*/  42.0,/*wavelength to trace through optical system*/550.0);

	EO45932.buildLensTwoSurfaces_DCV(/*lens catalog*/ "EO", /*catalog number*/ 45932, /*diameter*/25.0, /*max tolerance diameter*/0.0, /*min tolerance diameter*/-0.025,/*max surface quality*/40.0,
		/*back focal length*/-101.64,/*min surface quality*/20.0, /*irregularity*/4.0, /*center thickness*/  5.0, /*Centering (arc minutes)*/1.0, /*edge thickness*/6.43,
		/*design wavelength*/587.6, /*numerical Aperture*/0.13, /*min wavelength range*/400, /*max wavelength range*/1000, /*focal length*/-99.9956,
		/*Coating*/"VIS-NIR (400-1000nm)", /*material*/mGlasses.getNBK7_S1(), /*power (P-V)*/1.5, /*free aperture CA*/24.0, /*tolerance center thickness*/0.1,
		/*tolerance focal lenght*/1.0, /*radius*/-104.2, /*price*/  42.0,/*wavelength to trace through optical system*/550.0);

}


void EdmundOpticsLensCatalog::loadLensCatalogEO_plan_convex_lenses_VIS_NIR() //https://www.edmundoptics.de/f/vis-nir-coated-plano-convex-pcx-lenses/12278/
{


	// VIS-NIR beschichtete PCX Linsen (without INK lenses like #47-859-INK)

	EO65289.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 65289, /*diameter*/ 1.0, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 0.17,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  30.0, /*max centering*/  45.0,
		/*tolerance center thickness*/  0.05, /*radius first surface*/  0.51, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0, /*focal lenght*/ 0.599828,	/*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNLASF9_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/  0.80,/*edge thickness*/  0.39, /*free aperture CA*/  0.5,/*numerical Aperture*/  0.83,
		/*price*/  85.0, /*wavelength to trace through optical system*/  550.0);

	EO65290.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 65290, /*diameter*/ 1.0, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 0.57,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  30.0, /*max centering*/  45.0,
		/*tolerance center thickness*/  0.05, /*radius first surface*/  0.85, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0, /*focal length*/ 0.999713,	/*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNLASF9_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/  0.80,/*edge thickness*/  0.64, /*free aperture CA*/  0.5,/*numerical Aperture*/  0.50,
		/*price*/  85.0, /*wavelength to trace through optical system*/  550.0);

	EO65291.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 65291, /*diameter*/ 1.0, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 1.07,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  30.0, /*max centering*/  45.0,
		/*tolerance center thickness*/  0.05, /*radius first surface*/  1.275, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0, /*focal length*/ 1.49957,	/*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNLASF9_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/  0.80,/*edge thickness*/  0.7, /*free aperture CA*/  0.5,/*numerical Aperture*/  0.33,
		/*price*/  85.0, /*wavelength to trace through optical system*/  550.0);

	EO65292.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 65292, /*diameter*/ 1.0, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 1.57,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  30.0, /*max centering*/  45.0,
		/*tolerance center thickness*/  0.05, /*radius first surface*/  1.7, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0, /*focal length*/ 1.99943, /*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNLASF9_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/  0.80,/*edge thickness*/  0.72, /*free aperture CA*/  0.5,/*numerical Aperture*/  0.25,
		/*price*/  85.0, /*wavelength to trace through optical system*/  550.0);

	EO65293.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 65293, /*diameter*/ 1.5, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 0.57,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  30.0, /*max centering*/  45.0,
		/*tolerance center thickness*/  0.05, /*radius first surface*/  0.85, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0, /*focal length*/ 0.999713,	/*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNLASF9_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/  0.80,/*edge thickness*/  0.35, /*free aperture CA*/  1.0,/*numerical Aperture*/  0.75,
		/*price*/  85.0, /*wavelength to trace through optical system*/  550.0);

	EO65294.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 65294, /*diameter*/ 1.5, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 1.07,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  30.0, /*max centering*/  45.0,
		/*tolerance center thickness*/  0.05, /*radius first surface*/  1.28, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0, /*focal length*/ 1.50545,	/*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNLASF9_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/  0.80,/*edge thickness*/  0.56, /*free aperture CA*/  1.0,/*numerical Aperture*/  0.5,
		/*price*/  85.0, /*wavelength to trace through optical system*/  550.0);

	EO65295.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 65295, /*diameter*/ 1.5, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 1.57,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  30.0, /*max centering*/  45.0,
		/*tolerance center thickness*/  0.05, /*radius first surface*/  1.7, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0, /*focal lenth*/ 1.99943,	/*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNLASF9_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/  0.80,/*edge thickness*/  0.63, /*free aperture CA*/  1.0,/*numerical Aperture*/  0.38,
		/*price*/  85.0, /*wavelength to trace through optical system*/  550.0);

	EO65296.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 65296, /*diameter*/ 2.0, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 1.07,		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  30.0, /*max centering*/  45.0,
		/*tolerance center thickness*/  0.05, /*radius first surface*/  1.28, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0, /*focal length*/ 1.50545,	/*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNLASF9_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/  0.80,/*edge thickness*/  0.32, /*free aperture CA*/  1.5,/*numerical Aperture*/  0.67,
		/*price*/  85.0, /*wavelength to trace through optical system*/  550.0);

	EO65297.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 65297, /*diameter*/ 2.0, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 1.57,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  30.0, /*max centering*/  45.0,
		/*tolerance center thickness*/  0.05, /*radius first surface*/  1.7, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0, /*focal length*/ 1.99943,	/*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNLASF9_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/  0.80,/*edge thickness*/  0.48, /*free aperture CA*/  1.5,/*numerical Aperture*/  0.5,
		/*price*/  85.0, /*wavelength to trace through optical system*/  550.0);

	EO65298.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 65298, /*diameter*/ 2.0, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 2.57,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  30.0, /*max centering*/  45.0,
		/*tolerance center thickness*/  0.05, /*radius first surface*/  2.55, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0, /*focal length*/ 2.99914,	/*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNLASF9_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/  0.80,/*edge thickness*/  0.60, /*free aperture CA*/  1.5,/*numerical Aperture*/  0.33,
		/*price*/  85.0, /*wavelength to trace through optical system*/  550.0);

	EO65299.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 65299, /*diameter*/ 2.0, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 3.57,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  30.0, /*max centering*/  45.0,
		/*tolerance center thickness*/  0.05, /*radius first surface*/  3.4, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0, /*focal length*/ 3.99885,	/*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNLASF9_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/  0.80,/*edge thickness*/  0.65, /*free aperture CA*/  1.5,/*numerical Aperture*/  0.25,
		/*price*/  85.0, /*wavelength to trace through optical system*/  550.0);

	EO65300.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 65300, /*diameter*/ 2.5, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 1.57,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  30.0, /*max centering*/  45.0,
		/*tolerance center thickness*/  0.05, /*radius first surface*/  1.7, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0, /*focal length*/ 1.99943,	/*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNLASF9_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/  0.80,/*edge thickness*/  0.63, /*free aperture CA*/  2.0,/*numerical Aperture*/  0.63,
		/*price*/  85.0, /*wavelength to trace through optical system*/  550.0);

	EO65301.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 65301, /*diameter*/ 2.5, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 2.05,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  30.0, /*max centering*/  45.0,
		/*tolerance center thickness*/  0.05, /*radius first surface*/  2.12, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0,	/*focal length*/ 2.4934, /*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNLASF9_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/  0.80,/*edge thickness*/  0.39, /*free aperture CA*/  2.0,/*numerical Aperture*/  0.5,
		/*price*/  85.0, /*wavelength to trace through optical system*/  550.0);

	EO65302.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 65302, /*diameter*/ 2.5, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 2.57,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  30.0, /*max centering*/  45.0,
		/*tolerance center thickness*/  0.05, /*radius first surface*/  2.55, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0, /*focal length*/ 2.99914,	/*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNLASF9_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/  0.80,/*edge thickness*/  0.47, /*free aperture CA*/  2.0,/*numerical Aperture*/  0.42,
		/*price*/  85.0, /*wavelength to trace through optical system*/  550.0);

	EO65303.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 65303, /*diameter*/ 2.5, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 3.57,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  30.0, /*max centering*/  45.0,
		/*tolerance center thickness*/  0.05, /*radius first surface*/  3.401, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0, /*focal length*/ 4.00003,	/*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNLASF9_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/  0.80,/*edge thickness*/  0.56, /*free aperture CA*/  2.0,/*numerical Aperture*/  0.31,
		/*price*/  85.0, /*wavelength to trace through optical system*/  550.0);

	EO65304.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 65304, /*diameter*/ 2.5, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 4.57,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  30.0, /*max centering*/  45.0,
		/*tolerance center thickness*/  0.05, /*radius first surface*/  4.251, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0, /*focal length*/ 4.99974,	/*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNLASF9_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/  0.80,/*edge thickness*/  0.61, /*free aperture CA*/  2.0,/*numerical Aperture*/  0.25,
		/*price*/  85.0, /*wavelength to trace through optical system*/  550.0);

	EO49174.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 49174, /*diameter*/ 3.0, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 1.88,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  30.0, /*max centering*/  45.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/  2.35, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0, /*focal length*/ 2.99472,	/*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNSF11_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/  2.0,/*edge thickness*/  1.46, /*free aperture CA*/  2.5,/*numerical Aperture*/  0.5,
		/*price*/  65.0, /*wavelength to trace through optical system*/  550.0);

	EO49175.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 49175, /*diameter*/ 3.0, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 3.5,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  30.0, /*max centering*/  45.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 3.62, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0,	/*foclal length*/ 4.50139, /*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNLASF44_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/  1.8,/*edge thickness*/  1.47, /*free aperture CA*/  2.5,/*numerical Aperture*/  0.33,
		/*price*/  65.0, /*wavelength to trace through optical system*/  550.0);

	EO49176.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 49176, /*diameter*/ 3.0, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 4.81,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  3.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 3.1, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0, /*focal length*/ 5.99847,	/*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNBK7_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/  1.8,/*edge thickness*/  1.41, /*free aperture CA*/  2.5,/*numerical Aperture*/  0.25,
		/*price*/  61.0, /*wavelength to trace through optical system*/  550.0);

	EO49177.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 49177, /*diameter*/ 3.0, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 6.51,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  3.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 3.876, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0, /*focal length*/ 7.50002,	/*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNBK7_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/  1.5,/*edge thickness*/  1.2, /*free aperture CA*/  2.5,/*numerical Aperture*/  0.2,
		/*price*/  61.0, /*wavelength to trace through optical system*/  550.0);

	EO49178.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 49178, /*diameter*/ 3.0, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 8.01,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  3.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 4.65, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0,	/*focal length*/ 8.99771, /*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNBK7_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/  1.5,/*edge thickness*/  1.25, /*free aperture CA*/  2.5,/*numerical Aperture*/  0.17,
		/*price*/  61.0, /*wavelength to trace through optical system*/  550.0);

	EO49179.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 49179, /*diameter*/ 3.0, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 11.29,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 6.2, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0, /*focal length*/ 11.9969,	/*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNBK7_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/  1.08,/*edge thickness*/  0.9, /*free aperture CA*/  2.5,/*numerical Aperture*/  0.13,
		/*price*/  61.0, /*wavelength to trace through optical system*/  550.0);

	EO49180.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 49180, /*diameter*/ 3.0, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 14.17,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 7.78, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0, /*focal length*/ 15.0542,	/*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNBK7_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/  1.26,/*edge thickness*/  1.12, /*free aperture CA*/  2.5,/*numerical Aperture*/  0.1,
		/*price*/  61.0, /*wavelength to trace through optical system*/  550.0);

	EO47850.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 47850, /*diameter*/ 4.0, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 3.06,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  30.0, /*max centering*/  45.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 3.21, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0, /*focal length*/ 3.99156,	/*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNLASF44_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/  1.7,/*edge thickness*/  1.0, /*free aperture CA*/  3.6,/*numerical Aperture*/  0.5,
		/*price*/  62.5, /*wavelength to trace through optical system*/  550.0);

	EO47851.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 47851, /*diameter*/ 4.0, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 4.51,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  3.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 3.11, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0, /*focal length*/ 6.01782,	/*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNBK7_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/  2.26,/*edge thickness*/  1.53, /*free aperture CA*/  3.6,/*numerical Aperture*/  0.33,
		/*price*/  62.5, /*wavelength to trace through optical system*/  550.0);

	EO47852.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 47852, /*diameter*/ 4.0, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 7.17,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  3.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 5.36, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0, /*focal length*/ 7.99968,	/*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNBAF10_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/  1.39,/*edge thickness*/  1.0, /*free aperture CA*/  3.6,/*numerical Aperture*/  0.25,
		/*price*/  59.0, /*wavelength to trace through optical system*/  550.0);

	EO47853.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 47853, /*diameter*/ 4.0, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 8.92,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  3.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 5.19, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0, /*focal length*/ 10.0426,	/*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNBK7_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/  1.64,/*edge thickness*/  1.24, /*free aperture CA*/  3.6,/*numerical Aperture*/  0.2,
		/*price*/  59.0, /*wavelength to trace through optical system*/  550.0);

	EO47854.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 47854, /*diameter*/ 4.0, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 11.0,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 6.22, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0, /*focal length*/ 12.0356,	/*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNBK7_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/  1.52,/*edge thickness*/  1.19, /*free aperture CA*/  3.6,/*numerical Aperture*/  0.17,
		/*price*/  62.5, /*wavelength to trace through optical system*/  550.0);

	EO47855.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 47855, /*diameter*/ 4.5, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 3.05,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  30.0, /*max centering*/  45.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 3.61, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0, /*focal length*/ 4.48895,	/*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNLASF44_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/  2.59,/*edge thickness*/  1.8, /*free aperture CA*/  4.05,/*numerical Aperture*/  0.5,
		/*price*/  59.0, /*wavelength to trace through optical system*/  550.0);

	EO47856.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 47856, /*diameter*/ 4.5, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 7.41,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  3.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 4.65, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0, /*focal length*/ 8.99771,	/*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNBK7_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/  2.38,/*edge thickness*/  1.8, /*free aperture CA*/  4.05,/*numerical Aperture*/  0.25,
		/*price*/  62.5, /*wavelength to trace through optical system*/  550.0);

	EO47857.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 47857, /*diameter*/ 5.0, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 3.96,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  30.0, /*max centering*/  45.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 4.02, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0, /*focal length*/ 4.99878,	/*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNLASF44_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/  1.87,/*edge thickness*/  1.0, /*free aperture CA*/  4.5,/*numerical Aperture*/  0.5,
		/*price*/  59.0, /*wavelength to trace through optical system*/  550.0);

	EO48661.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 48661, /*diameter*/ 5.0, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 6.43,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  3.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 5.885, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0, /*focal length*/ 7.49955,	/*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNSF11_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/  1.9,/*edge thickness*/  1.34, /*free aperture CA*/  4.5,/*numerical Aperture*/  0.33,
		/*price*/  44.5, /*wavelength to trace through optical system*/  550.0);

	EO47858.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 47858, /*diameter*/ 5.0, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 8.91,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  3.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 5.17, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0, /*focal length*/ 10.0039,	/*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNBK7_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/  1.64,/*edge thickness*/  1.0, /*free aperture CA*/  4.5,/*numerical Aperture*/  0.25,
		/*price*/  44.5, /*wavelength to trace through optical system*/  550.0);

	EO47859.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 47859, /*diameter*/ 5.0, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 10.83,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 6.22, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0, /*focal length*/ 12.0356,	/*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNBK7_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/  1.77,/*edge thickness*/  1.25, /*free aperture CA*/  4.5,/*numerical Aperture*/  0.21,
		/*price*/  44.5, /*wavelength to trace through optical system*/  550.0);


	EO47860.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 47860, /*diameter*/ 5.0, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 13.94,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 7.75, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0, /*focal length*/ 14.9962, /*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNBK7_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/  1.6,/*edge thickness*/  1.19, /*free aperture CA*/  4.5,/*numerical Aperture*/  0.17,
		/*price*/  44.5, /*wavelength to trace through optical system*/  550.0);

	EO49913.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 49913, /*diameter*/ 5.0, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 19.02,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 10.34, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0, /*focal length*/ 20.0078, /*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNBK7_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/  1.5,/*edge thickness*/  1.19, /*free aperture CA*/  4.5,/*numerical Aperture*/  0.13,
		/*price*/  44.5, /*wavelength to trace through optical system*/  550.0);

	EO87917.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 87917, /*diameter*/ 5.0, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 23.95,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 12.92, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0, /*focal length*/ 25.0001,	/*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNBK7_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/  1.6,/*edge thickness*/  1.36, /*free aperture CA*/  4.5,/*numerical Aperture*/  0.1,
		/*price*/  44.5, /*wavelength to trace through optical system*/  550.0);

	EO87918.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 87918, /*diameter*/ 5.0, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 28.95,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 15.504, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0, /*focal length*/ 30.0001,	/*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNBK7_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/  1.6,/*edge thickness*/  1.4, /*free aperture CA*/  4.5,/*numerical Aperture*/  0.08,
		/*price*/  44.5, /*wavelength to trace through optical system*/  550.0);

	EO45465.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 45465, /*diameter*/ 6.0, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 4.6,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  3.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 4.71, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0, /*focal length*/ 6.00219,	/*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNSF11_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/  2.5,/*edge thickness*/  1.42, /*free aperture CA*/  5.4,/*numerical Aperture*/  0.5,
		/*price*/  44.5, /*wavelength to trace through optical system*/  550.0);

	EO49914.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 49914, /*diameter*/ 6.0, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 6.1,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  3.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 5.885, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0, /*focal length*/ 7.49955,	/*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNSF11_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/  2.5,/*edge thickness*/  1.68, /*free aperture CA*/  5.4,/*numerical Aperture*/  0.4,
		/*price*/  36.5, /*wavelength to trace through optical system*/  550.0);

	EO45466.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 45466, /*diameter*/ 6.0, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 7.95,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  3.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 6.05, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0, /*focal length*/ 8.99357,	/*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNSF5_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/  1.75,/*edge thickness*/  0.95, /*free aperture CA*/  5.4,/*numerical Aperture*/  0.33,
		/*price*/  36.5, /*wavelength to trace through optical system*/  550.0);

	EO38483.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 38483, /*diameter*/ 6.0, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 8.82,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  3.0,
		/*tolerance center thickness*/  0.05, /*radius first surface*/ 5.17, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0, /*focal length*/ 10.0039, /*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNBK7_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/  1.8,/*edge thickness*/  0.84, /*free aperture CA*/  5.4,/*numerical Aperture*/  0.3,
		/*price*/  36.5, /*wavelength to trace through optical system*/  550.0);

	EO45467.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 45467, /*diameter*/ 6.0, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 10.94,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 6.2, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0,	/*focal length*/ 11.9969, /*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNBK7_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/  1.6,/*edge thickness*/  0.83, /*free aperture CA*/  5.4,/*numerical Aperture*/  0.25,
		/*price*/  36.5, /*wavelength to trace through optical system*/  550.0);

	EO45468.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 45468, /*diameter*/ 6.0, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 13.68,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 7.75, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0,	/*focal length*/ 14.9962, /*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNBK7_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/  2.0,/*edge thickness*/  1.4, /*free aperture CA*/  5.4,/*numerical Aperture*/  0.2,
		/*price*/  35.5, /*wavelength to trace through optical system*/  550.0);

	EO45469.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 45469, /*diameter*/ 6.0, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 17.07,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 9.3, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0,	/*focal length*/ 17.9954, /*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNBK7_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/  1.42,/*edge thickness*/  0.92, /*free aperture CA*/  5.4,/*numerical Aperture*/  0.17,
		/*price*/  35.5, /*wavelength to trace through optical system*/  550.0);

	EO38484.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 38484, /*diameter*/ 6.0, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 19.04,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.05, /*radius first surface*/ 10.335, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0, /*focal length*/ 19.9981,	/*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNBK7_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/  1.45,/*edge thickness*/  1.01, /*free aperture CA*/  5.4,/*numerical Aperture*/  0.15,
		/*price*/  35.5, /*wavelength to trace through optical system*/  550.0);

	EO45470.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 45470, /*diameter*/ 6.0, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 20.06,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 10.85, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0, /*focal length*/ 20.9946,	/*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNBK7_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/  1.42,/*edge thickness*/  1.0, /*free aperture CA*/  5.4,/*numerical Aperture*/  0.14,
		/*price*/  35.5, /*wavelength to trace through optical system*/  550.0);

	EO45471.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 45471, /*diameter*/ 6.0, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 23.01,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 12.4, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0, /*focal length*/ 23.9939,	/*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNBK7_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/  1.5,/*edge thickness*/  1.13, /*free aperture CA*/  5.4,/*numerical Aperture*/  0.13,
		/*price*/  35.5, /*wavelength to trace through optical system*/  550.0);

	EO38485.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 38485, /*diameter*/ 6.0, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 24.04,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.05, /*radius first surface*/ 12.92, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0,	/*focal length*/ 25.0001, /*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNBK7_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/  1.45,/*edge thickness*/  1.1, /*free aperture CA*/  5.4,/*numerical Aperture*/  0.12,
		/*price*/  35.5, /*wavelength to trace through optical system*/  550.0);

	EO45472.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 45472, /*diameter*/ 6.0, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 29.14,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 15.5, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0, /*focal length*/ 29.9924,	/*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNBK7_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/  1.3,/*edge thickness*/  1.01, /*free aperture CA*/  5.4,/*numerical Aperture*/  0.1,
		/*price*/  35.5, /*wavelength to trace through optical system*/  550.0);

	EO45473.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 45473, /*diameter*/ 6.0, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 34.95,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 18.61, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0,	/*focal length*/ 36.0102, /*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNBK7_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/  1.6,/*edge thickness*/  1.36, /*free aperture CA*/  5.4,/*numerical Aperture*/  0.08,
		/*price*/  35.5, /*wavelength to trace through optical system*/  550.0);

	EO47381.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 47381, /*diameter*/ 6.0, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 46.95,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 24.81, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0, /*focal length*/ 48.0071,	/*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNBK7_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/  1.6,/*edge thickness*/  1.42, /*free aperture CA*/  5.4,/*numerical Aperture*/  0.06,
		/*price*/  35.5, /*wavelength to trace through optical system*/  550.0);

	EO67178.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 67178, /*diameter*/ 6.0, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 58.95,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 31.01, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0, /*focal length*/ 60.0041,	/*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNBK7_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/  1.6,/*edge thickness*/  1.45, /*free aperture CA*/  5.4,/*numerical Aperture*/  0.05,
		/*price*/  35.5, /*wavelength to trace through optical system*/  550.0);

	EO45696.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 45696, /*diameter*/ 6.0, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 70.97,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 37.22, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0, /*focal length*/ 72.0203,	/*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNBK7_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/  1.6,/*edge thickness*/  1.48, /*free aperture CA*/  5.4,/*numerical Aperture*/  0.04,
		/*price*/  35.5, /*wavelength to trace through optical system*/  550.0);

	EO45474.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 45474, /*diameter*/ 9.0, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 7.32,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  3.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 7.06, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0, /*focal length*/ 98.99691,	/*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNSF11_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/  3.0,/*edge thickness*/  1.38, /*free aperture CA*/  8.1,/*numerical Aperture*/  0.5,
		/*price*/  35.5, /*wavelength to trace through optical system*/  550.0);

	EO49915.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 49915, /*diameter*/ 9.0, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 10.6,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 9.42, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0,	/*focal length*/ 12.0044, /*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNSF11_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/  2.5,/*edge thickness*/  1.36, /*free aperture CA*/  8.1,/*numerical Aperture*/  0.38,
		/*price*/  37.5, /*wavelength to trace through optical system*/  550.0);

	EO45475.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 45475, /*diameter*/ 9.0, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 11.94,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 9.09, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0, /*focal length*/ 13.5126,	/*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNSF5_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/  2.6,/*edge thickness*/  1.4, /*free aperture CA*/  8.1,/*numerical Aperture*/  0.33,
		/*price*/  37.5, /*wavelength to trace through optical system*/  550.0);

	EO49916.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 49916, /*diameter*/ 9.0, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 13.02,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 7.75, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0, /*focal length*/ 14.9962,	/*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNBK7_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/  3.0,/*edge thickness*/  1.56, /*free aperture CA*/  8.1,/*numerical Aperture*/  0.3,
		/*price*/  37.5, /*wavelength to trace through optical system*/  550.0);

	EO45476.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 45476, /*diameter*/ 9.0, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 16.41,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 9.32, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0, /*focal length*/ 18.0341,	/*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNBK7_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/  2.41,/*edge thickness*/  1.26, /*free aperture CA*/  8.1,/*numerical Aperture*/  0.25,
		/*price*/  37.5, /*wavelength to trace through optical system*/  550.0);

	EO38487.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 38487, /*diameter*/ 9.0, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 18.55,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.05, /*radius first surface*/ 10.335, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0, /*focal length*/ 19.9981,	/*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNBK7_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/  2.2,/*edge thickness*/  1.17, /*free aperture CA*/  8.1,/*numerical Aperture*/  0.23,
		/*price*/  36.5, /*wavelength to trace through optical system*/  550.0);

	EO45477.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 45477, /*diameter*/ 9.0, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 20.73,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 11.37, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0, /*focal length*/ 22.0008,	/*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNBK7_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/  1.93,/*edge thickness*/  1.0, /*free aperture CA*/  8.1,/*numerical Aperture*/  0.2,
		/*price*/  36.5, /*wavelength to trace through optical system*/  550.0);

	EO38488.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 38488, /*diameter*/ 9.0, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 23.68,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.05, /*radius first surface*/ 12.92, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0,	/*focal length*/ 25.0001, /*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNBK7_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/  2.0,/*edge thickness*/  1.19, /*free aperture CA*/  8.1,/*numerical Aperture*/  0.18,
		/*price*/  36.5, /*wavelength to trace through optical system*/  550.0);

	EO45478.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 45478, /*diameter*/ 9.0, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 25.35,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 13.95, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0,	/*focal length*/ 26.9931, /*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNBK7_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/  2.5,/*edge thickness*/  2.5, /*free aperture CA*/  8.1,/*numerical Aperture*/  0.17,
		/*price*/  36.5, /*wavelength to trace through optical system*/  550.0);

	EO45479.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 45479, /*diameter*/ 9.0, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 34.48,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 18.61, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0, /*focal length*/ 36.0102,	/*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNBK7_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/  2.5,/*edge thickness*/  2.3, /*free aperture CA*/  8.1,/*numerical Aperture*/  0.13,
		/*price*/  36.5, /*wavelength to trace through optical system*/  550.0);

	EO45703.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 45703, /*diameter*/ 9.0, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 43.98,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 23.26, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0,	/*focal length*/ 45.0079, /*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNBK7_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/  1.54,/*edge thickness*/  1.1, /*free aperture CA*/  8.1,/*numerical Aperture*/  0.1,
		/*price*/  36.5, /*wavelength to trace through optical system*/  550.0);

	EO67179.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 67179, /*diameter*/ 9.0, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 52.69,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 27.91, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0, /*focal length*/ 54.0056,	/*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNBK7_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/ 2.0,/*edge thickness*/  1.63, /*free aperture CA*/  8.1,/*numerical Aperture*/  0.08,
		/*price*/  36.5, /*wavelength to trace through optical system*/  550.0);

	EO67180.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 67180, /*diameter*/ 9.0, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 70.68,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 37.21, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0, /*focal length*/ 72.001,	/*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNBK7_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/ 2.0,/*edge thickness*/  1.73, /*free aperture CA*/  8.1,/*numerical Aperture*/  0.06,
		/*price*/  36.5, /*wavelength to trace through optical system*/  550.0);

	EO67181.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 67181, /*diameter*/ 9.0, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 88.68,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 46.51, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0, /*focal length*/ 89.9964,	/*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNBK7_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/ 2.0,/*edge thickness*/  1.78, /*free aperture CA*/  8.1,/*numerical Aperture*/  0.05,
		/*price*/  36.5, /*wavelength to trace through optical system*/  550.0);

	EO38486.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 38486, /*diameter*/ 9.0, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 8.49,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  3.0,
		/*tolerance center thickness*/  0.05, /*radius first surface*/ 7.85, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0,	/*focal length*/ 10.0036, /*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNSF11_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/ 2.7,/*edge thickness*/  1.28, /*free aperture CA*/  8.1,/*numerical Aperture*/  0.45,
		/*price*/  37.5, /*wavelength to trace through optical system*/  550.0);

	EO63519.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 63519, /*diameter*/ 10.0, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 8.18,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 7.85, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0, /*focal length*/ 10.0036,	/*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNSF11_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/ 3.25,/*edge thickness*/  1.45, /*free aperture CA*/  9.0,/*numerical Aperture*/  0.5,
		/*price*/  36.5, /*wavelength to trace through optical system*/  550.0);

	EO63520.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 63520, /*diameter*/ 10.0, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 13.32,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 11.77, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0, /*focal length*/ 14.9991,	/*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNSF11_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/ 3.0,/*edge thickness*/  1.89, /*free aperture CA*/  9.0,/*numerical Aperture*/  0.33,
		/*price*/  37.5, /*wavelength to trace through optical system*/  550.0);

	EO63521.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 63521, /*diameter*/ 10.0, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 18.03,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 10.34, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0,	/*focal length*/ 20.0078, /*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNBK7_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/ 3.0,/*edge thickness*/  1.71, /*free aperture CA*/  9.0,/*numerical Aperture*/  0.25,
		/*price*/  36.5, /*wavelength to trace through optical system*/  550.0);

	EO63522.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 63522, /*diameter*/ 10.0, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 23.02,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 12.92, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0, /*focal length*/ 25.0001,	/*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNBK7_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/ 3.0,/*edge thickness*/  1.99, /*free aperture CA*/  9.0,/*numerical Aperture*/  0.2,
		/*price*/  36.5, /*wavelength to trace through optical system*/  550.0);

	EO63523.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 63523, /*diameter*/ 10.0, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 28.01,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 15.5, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0, /*focal length*/ 29.9924,	/*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNBK7_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/ 3.0,/*edge thickness*/  2.17, /*free aperture CA*/  9.0,/*numerical Aperture*/  0.17,
		/*price*/  36.5, /*wavelength to trace through optical system*/  550.0);

	EO63524.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 63524, /*diameter*/ 10.0, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 38.02,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 20.67, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0, /*focal length*/ 39.9963,	/*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNBK7_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/ 3.0,/*edge thickness*/  2.39, /*free aperture CA*/  9.0,/*numerical Aperture*/  0.13,
		/*price*/  36.5, /*wavelength to trace through optical system*/  550.0);

	EO63525.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 63525, /*diameter*/ 10.0, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 48.02,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 25.84, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0, /*focal length*/ 50.0002,	/*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNBK7_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/ 3.0,/*edge thickness*/  2.51, /*free aperture CA*/  9.0,/*numerical Aperture*/  0.1,
		/*price*/  36.5, /*wavelength to trace through optical system*/  550.0);

	EO63526.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 63526, /*diameter*/ 10.0, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 73.02,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 38.76, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0, /*focal length*/ 75.0002,	/*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNBK7_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/ 3.0,/*edge thickness*/  2.68, /*free aperture CA*/  9.0,/*numerical Aperture*/  0.07,
		/*price*/  36.5, /*wavelength to trace through optical system*/  550.0);

	EO63527.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 63527, /*diameter*/ 10.0, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 98.02,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 51.68, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0, /*focal length*/ 100.0,	/*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNBK7_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/ 3.0,/*edge thickness*/  2.76, /*free aperture CA*/  9.0,/*numerical Aperture*/  0.05,
		/*price*/  36.5, /*wavelength to trace through optical system*/  550.0);

	EO45480.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 45480, /*diameter*/ 12.0, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 9.76,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 9.42, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0,	/*focal length*/ 12.0044, /*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNSF11_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/ 4.0,/*edge thickness*/  1.84, /*free aperture CA*/  11.0,/*numerical Aperture*/  0.5,
		/*price*/  36.5, /*wavelength to trace through optical system*/  550.0);

	EO45481.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 45481, /*diameter*/ 12.0, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 12.03,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 7.75, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0, /*focal length*/ 14.9962,	/*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNBK7_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/ 4.5,/*edge thickness*/  1.66, /*free aperture CA*/  11.0,/*numerical Aperture*/  0.4,
		/*price*/  42.0, /*wavelength to trace through optical system*/  550.0);

	EO45482.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 45482, /*diameter*/ 12.0, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 16.22,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 12.11, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0,	/*focal length*/ 18.002, /*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNSF5_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/ 3.0,/*edge thickness*/  1.41, /*free aperture CA*/  11.0,/*numerical Aperture*/  0.33,
		/*price*/  42.0, /*wavelength to trace through optical system*/  550.0);

	EO49917.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 49917, /*diameter*/ 12.0, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 17.69,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 10.335, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0, /*focal length*/ 19.9981,	/*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNBK7_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/ 3.5,/*edge thickness*/  1.58, /*free aperture CA*/  19.0,/*numerical Aperture*/  0.3,
		/*price*/  42.0, /*wavelength to trace through optical system*/  550.0);

	EO45483.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 45483, /*diameter*/ 12.0, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 22.15,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 12.42, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0,	/*focal length*/ 24.0326, /*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNBK7_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/ 2.8,/*edge thickness*/  1.25, /*free aperture CA*/  11.0,/*numerical Aperture*/  0.25,
		/*price*/  42.0, /*wavelength to trace through optical system*/  550.0);

	EO45484.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 45484, /*diameter*/ 12.0, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 28.02,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 15.5, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0,	/*focal length*/ 29.9924, /*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNBK7_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/ 3.0,/*edge thickness*/  1.79, /*free aperture CA*/  11.0,/*numerical Aperture*/  0.2,
		/*price*/  41.0, /*wavelength to trace through optical system*/  550.0);

	EO33355.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 33355, /*diameter*/ 12.0, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 34.02,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 18.605, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0,	/*focal length*/ 36.0005, /*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNBK7_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/ 3.0,/*edge thickness*/  2.01, /*free aperture CA*/  11.0,/*numerical Aperture*/  0.17,
		/*price*/  41.0, /*wavelength to trace through optical system*/  550.0);

	EO45485.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 45485, /*diameter*/ 12.0, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 40.22,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 21.71, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0, /*focal length*/ 42.0086,	/*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNBK7_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/ 2.7,/*edge thickness*/  1.85, /*free aperture CA*/  11.0,/*numerical Aperture*/  0.14,
		/*price*/  51.0, /*wavelength to trace through optical system*/  550.0);

	EO45486.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 45486, /*diameter*/ 12.0, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 46.36,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 24.82, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0,	/*focal length*/ 48.0265, /*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNBK7_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/ 2.5,/*edge thickness*/  1.76, /*free aperture CA*/  11.0,/*numerical Aperture*/  0.13,
		/*price*/  41.0, /*wavelength to trace through optical system*/  550.0);

	EO45487.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 45487, /*diameter*/ 12.0, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 52.02,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 27.91, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0,	/*focal length*/ 54.0056, /*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNBK7_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/ 3.0,/*edge thickness*/  2.35, /*free aperture CA*/  11.0,/*numerical Aperture*/  0.11,
		/*price*/  41.0, /*wavelength to trace through optical system*/  550.0);

	EO45488.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 45488, /*diameter*/ 12.0, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 58.37,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 31.02, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0,	/*focal length*/ 60.0234, /*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNBK7_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/ 2.5,/*edge thickness*/  1.91, /*free aperture CA*/  11.0,/*numerical Aperture*/  0.1,
		/*price*/  41.0, /*wavelength to trace through optical system*/  550.0);

	EO45705.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 45705, /*diameter*/ 12.0, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 70.42,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 37.21, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0, /*focal length*/ 72.001,	/*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNBK7_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/ 2.4,/*edge thickness*/  1.91, /*free aperture CA*/  11.0,/*numerical Aperture*/  0.08,
		/*price*/  41.0, /*wavelength to trace through optical system*/  550.0);

	EO45489.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 45489, /*diameter*/ 12.0, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 82.39,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 43.43, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0,	/*focal length*/ 84.0366, /*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNBK7_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/ 2.5,/*edge thickness*/  2.08, /*free aperture CA*/  11.0,/*numerical Aperture*/  0.07,
		/*price*/  41.0, /*wavelength to trace through optical system*/  550.0);

	EO45490.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 45490, /*diameter*/ 12.0, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 98.35,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 51.68, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0, /*focal length*/ 100.0,	/*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNBK7_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/ 2.5,/*edge thickness*/  2.15, /*free aperture CA*/  11.0,/*numerical Aperture*/  0.06,
		/*price*/  41.0, /*wavelength to trace through optical system*/  550.0);

	EO38501.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 38501, /*diameter*/ 12.5, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 15.0,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 9.045, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0,	/*focal length*/ 17.502, /*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNBK7_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/ 3.8,/*edge thickness*/ 1.29, /*free aperture CA*/  11.5,/*numerical Aperture*/  0.36,
		/*price*/  42.0, /*wavelength to trace through optical system*/  550.0);

	EO38506.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 38506, /*diameter*/ 12.5, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 33.42,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 18.09, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0,	/*focal length*/ 35.004, /*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNBK7_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/ 2.4,/*edge thickness*/ 1.29, /*free aperture CA*/  11.5,/*numerical Aperture*/  0.18,
		/*price*/  41.0, /*wavelength to trace through optical system*/  550.0);

	EO62591.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 62591, /*diameter*/ 12.7, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 10.46,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 9.97, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0, /*focal length*/ 12.7053,	/*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNSF11_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/ 4.0,/*edge thickness*/ 1.72, /*free aperture CA*/  11.7,/*numerical Aperture*/  0.5,
		/*price*/  41.0, /*wavelength to trace through optical system*/  550.0);

	EO62592.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 62592, /*diameter*/ 12.7, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 11.53,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 7.75, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0, /*focal length*/ 14.9962,	/*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNBK7_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/ 5.25,/*edge thickness*/ 1.94, /*free aperture CA*/  11.7,/*numerical Aperture*/  0.42,
		/*price*/  42.0, /*wavelength to trace through optical system*/  550.0);

	EO62593.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 62593, /*diameter*/ 12.7, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 16.46,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 9.87, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0,	/*focal length*/ 19.0984, /*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNBK7_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/ 4.0,/*edge thickness*/ 1.69, /*free aperture CA*/  11.7,/*numerical Aperture*/  0.33,
		/*price*/  42.0, /*wavelength to trace through optical system*/  550.0);

	EO38515.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 38515, /*diameter*/ 12.7, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 17.49,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 10.335, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0,	/*focal length*/ 19.9981, /*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNBK7_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/ 3.8,/*edge thickness*/ 1.62, /*free aperture CA*/  11.7,/*numerical Aperture*/  0.32,
		/*price*/  42.0, /*wavelength to trace through optical system*/  550.0);

	EO62594.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 62594, /*diameter*/ 12.7, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 23.43,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 13.13, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0,	/*focal length*/ 25.4064, /*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNBK7_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/ 3.0,/*edge thickness*/ 1.36, /*free aperture CA*/  11.7,/*numerical Aperture*/  0.25,
		/*price*/  42.0, /*wavelength to trace through optical system*/  550.0);

	EO38516.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 38516, /*diameter*/ 12.7, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 28.22,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 15.505, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0, /*focal length*/ 30.002,	/*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNBK7_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/ 2.7,/*edge thickness*/ 1.34, /*free aperture CA*/  11.7,/*numerical Aperture*/  0.21,
		/*price*/  41.0, /*wavelength to trace through optical system*/  550.0);

	EO62595.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 62595, /*diameter*/ 12.7, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 29.81,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 16.43, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0, /*focal length*/ 31.7919,	/*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNBK7_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/ 3.0,/*edge thickness*/ 1.72, /*free aperture CA*/  11.7,/*numerical Aperture*/  0.2,
		/*price*/  41.0, /*wavelength to trace through optical system*/  550.0);

	EO62596.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 62596, /*diameter*/ 12.7, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 36.12,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 19.69, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0, /*focal length*/ 38.1,	/*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNBK7_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/ 3.0,/*edge thickness*/ 1.95, /*free aperture CA*/  11.7,/*numerical Aperture*/  0.17,
		/*price*/  41.0, /*wavelength to trace through optical system*/  550.0);

	EO38517.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 38517, /*diameter*/ 12.7, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 38.48,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 20.67, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0,	/*focal length*/ 39.9963, /*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNBK7_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/ 2.3,/*edge thickness*/ 1.3, /*free aperture CA*/  11.7,/*numerical Aperture*/  0.16,
		/*price*/  41.0, /*wavelength to trace through optical system*/  550.0);

	EO62597.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 62597, /*diameter*/ 12.7, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 42.69,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 23.0, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0,	/*focal length*/ 44.5048, /*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNBK7_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/ 2.75,/*edge thickness*/ 1.86, /*free aperture CA*/  11.7,/*numerical Aperture*/  0.14,
		/*price*/  41.0, /*wavelength to trace through optical system*/  550.0);

	EO62598.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 62598, /*diameter*/ 12.7, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 49.15,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 26.25, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0, /*focal length*/ 50.7935,	/*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNBK7_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/ 2.5,/*edge thickness*/ 1.72, /*free aperture CA*/  11.7,/*numerical Aperture*/  0.13,
		/*price*/  41.0, /*wavelength to trace through optical system*/  550.0);

	EO45491.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 45491, /*diameter*/ 15, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 11.71,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 10.09, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0,	/*focal length*/ 14.9992, /*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNSF5_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/ 5.5,/*edge thickness*/ 2.16, /*free aperture CA*/  14.0,/*numerical Aperture*/  0.5,
		/*price*/  41.0, /*wavelength to trace through optical system*/  550.0);

	EO49918.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 49918, /*diameter*/ 15, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 15.61,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 12.11, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0, /*focal length*/ 18.002,	/*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNSF5_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/ 4.0,/*edge thickness*/ 1.4, /*free aperture CA*/  14.0,/*numerical Aperture*/  0.42,
		/*price*/  42.0, /*wavelength to trace through optical system*/  550.0);

	EO63528.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 63528, /*diameter*/ 15, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 17.74,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 13.46, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0,	/*focal length*/ 20.0088, /*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNSF5_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/ 3.8,/*edge thickness*/ 1.52, /*free aperture CA*/  14.0,/*numerical Aperture*/  0.38,
		/*price*/  42.0, /*wavelength to trace through optical system*/  550.0);

	EO45492.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 45492, /*diameter*/ 15, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 20.5,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 15.12, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0, /*focal length*/ 22.4765,	/*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNSF5_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/ 3.35,/*edge thickness*/ 1.36, /*free aperture CA*/  14.0,/*numerical Aperture*/  0.33,
		/*price*/  42.0, /*wavelength to trace through optical system*/  550.0);

	EO45493.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 45493, /*diameter*/ 15, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 27.9,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 15.52, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0,	/*focal length*/ 30.0311, /*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNBK7_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/ 3.18,/*edge thickness*/ 1.25, /*free aperture CA*/  14.0,/*numerical Aperture*/  0.25,
		/*price*/  41.0, /*wavelength to trace through optical system*/  550.0);

	EO45494.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 45494, /*diameter*/ 15, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 38.02,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 20.67, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0, /*focal length*/ 39.9963,	/*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNBK7_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/ 3.0,/*edge thickness*/ 1.59, /*free aperture CA*/  14.0,/*numerical Aperture*/  0.19,
		/*price*/  41.0, /*wavelength to trace through optical system*/  550.0);

	EO49919.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 49919, /*diameter*/ 15, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 43.35,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 23.255, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0,	/*focal length*/ 49.9982, /*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNBK7_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/ 2.5,/*edge thickness*/ 1.26, /*free aperture CA*/  14.0,/*numerical Aperture*/  0.17,
		/*price*/  41.0, /*wavelength to trace through optical system*/  550.0);

	EO47382.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 47382, /*diameter*/ 15, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 58.65,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 31.11, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0, /*focal length*/ 60.1976,	/*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNBK7_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/ 2.05,/*edge thickness*/ 1.13, /*free aperture CA*/  14.0,/*numerical Aperture*/  0.13,
		/*price*/  41.0, /*wavelength to trace through optical system*/  550.0);

	EO47383.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 47383, /*diameter*/ 15, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 73.79,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 38.76, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0,	/*focal length*/ 75.0002, /*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNBK7_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/ 1.83,/*edge thickness*/ 1.1, /*free aperture CA*/  14.0,/*numerical Aperture*/  0.1,
		/*price*/  41.0, /*wavelength to trace through optical system*/  550.0);

	EO45706.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 45706, /*diameter*/ 15, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 98.02,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 51.68, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0, /*focal length*/ 100.0,	/*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNBK7_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/ 3.0,/*edge thickness*/ 2.45, /*free aperture CA*/  14.0,/*numerical Aperture*/  0.07,
		/*price*/  41.0, /*wavelength to trace through optical system*/  550.0);

	EO48426.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 48426, /*diameter*/ 18, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 15.2,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 14.13, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0,	/*focal length*/ 18.0066, /*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNSF11_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/ 5.0,/*edge thickness*/ 1.76, /*free aperture CA*/  17.0,/*numerical Aperture*/  0.5,
		/*price*/  41.0, /*wavelength to trace through optical system*/  550.0);

	EO45496.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 45496, /*diameter*/ 18, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 33.65,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 18.62, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0,	/*focal length*/ 36.0295, /*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNBK7_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/ 3.57,/*edge thickness*/ 1.25, /*free aperture CA*/  17.0,/*numerical Aperture*/  0.25,
		/*price*/  41.0, /*wavelength to trace through optical system*/  550.0);

	EO45497.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 45497, /*diameter*/ 18, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 52.02,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 27.91, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0,	/*focal length*/ 54.0056, /*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNBK7_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/ 3.0,/*edge thickness*/ 1.51, /*free aperture CA*/  17.0,/*numerical Aperture*/  0.17,
		/*price*/  41.0, /*wavelength to trace through optical system*/  550.0);

	EO45498.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 45498, /*diameter*/ 18, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 70.05,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 37.22, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0,	/*focal length*/ 72.0203, /*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNBK7_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/ 3.0,/*edge thickness*/ 1.9, /*free aperture CA*/  17.0,/*numerical Aperture*/  0.13,
		/*price*/  41.0, /*wavelength to trace through optical system*/  550.0);

	EO45499.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 45499, /*diameter*/ 20, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 17.42,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 15.7, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0, /*focal length*/ 20.0073,	/*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNSF11_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/ 4.6,/*edge thickness*/ 1.0, /*free aperture CA*/  19.0,/*numerical Aperture*/  0.5,
		/*price*/  42.0, /*wavelength to trace through optical system*/  550.0);

	EO49921.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 49921, /*diameter*/ 20, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 22.76,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 19.62, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0, /*focal length*/ 25.0027,	/*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNSF11_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/ 4.0,/*edge thickness*/ 1.26, /*free aperture CA*/  19.0,/*numerical Aperture*/  0.4,
		/*price*/  42.0, /*wavelength to trace through optical system*/  550.0);

	EO45707.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 45707, /*diameter*/ 20, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 27.3,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 20.1, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0, /*focal length*/ 29.9988,	/*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNBAF10_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/ 4.5,/*edge thickness*/ 1.84, /*free aperture CA*/  19.0,/*numerical Aperture*/  0.33,
		/*price*/  42.0, /*wavelength to trace through optical system*/  550.0);

	EO49922.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 49922, /*diameter*/ 20, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 32.04,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 18.09, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0,	/*focal length*/ 35.004, /*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNBK7_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/ 4.5,/*edge thickness*/ 1.48, /*free aperture CA*/  19.0,/*numerical Aperture*/  0.29,
		/*price*/  42.0, /*wavelength to trace through optical system*/  550.0);

	EO45500.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 45500, /*diameter*/ 20, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 36.77,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 20.67, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0, /*focal length*/ 39.9963,	/*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNBK7_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/ 4.9,/*edge thickness*/ 2.32, /*free aperture CA*/  19.0,/*numerical Aperture*/  0.25,
		/*price*/  41.0, /*wavelength to trace through optical system*/  550.0);

	EO45501.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 45501, /*diameter*/ 20, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 47.87,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 25.84, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0, /*focal length*/ 50.0002,	/*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNBK7_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/ 3.23,/*edge thickness*/ 1.22, /*free aperture CA*/  19.0,/*numerical Aperture*/  0.2,
		/*price*/  41.0, /*wavelength to trace through optical system*/  550.0);

	EO45502.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 45502, /*diameter*/ 20, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 57.03,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 31.01, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0,	/*focal length*/ 60.0041, /*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNBK7_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/ 4.5,/*edge thickness*/ 2.84, /*free aperture CA*/  19.0,/*numerical Aperture*/  0.17,
		/*price*/  41.0, /*wavelength to trace through optical system*/  550.0);

	EO45503.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 45503, /*diameter*/ 20, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 68.03,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 36.18, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0,	/*focal length*/ 70.008, /*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNBK7_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/ 3.0,/*edge thickness*/ 1.59, /*free aperture CA*/  19.0,/*numerical Aperture*/  0.14,
		/*price*/  41.0, /*wavelength to trace through optical system*/  550.0);

	EO47385.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 47385, /*diameter*/ 20, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 78.45,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 41.48, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0, /*focal length*/ 80.2634,	/*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNBK7_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/ 2.35,/*edge thickness*/ 1.13, /*free aperture CA*/  19.0,/*numerical Aperture*/  0.13,
		/*price*/  41.0, /*wavelength to trace through optical system*/  550.0);

	EO45708.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 45708, /*diameter*/ 20, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 97.13,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 51.68, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0, /*focal length*/ 100.0,	/*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNBK7_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/ 4.3,/*edge thickness*/ 3.32, /*free aperture CA*/  19.0,/*numerical Aperture*/  0.1,
		/*price*/  41.0, /*wavelength to trace through optical system*/  550.0);

	EO47386.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 47386, /*diameter*/ 20, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 148.02,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 77.52, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0, /*focal length*/ 150.0,	/*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNBK7_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/ 3.0,/*edge thickness*/ 2.35, /*free aperture CA*/  19.0,/*numerical Aperture*/  0.1,
		/*price*/  41.0, /*wavelength to trace through optical system*/  550.0);

	EO45504.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 45504, /*diameter*/ 25, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 20.22,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 16.82, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0,	/*focal length*/ 25.0036, /*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNSF5_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/ 8.0,/*edge thickness*/ 2.43, /*free aperture CA*/  24.0,/*numerical Aperture*/  0.5,
		/*price*/  45.5, /*wavelength to trace through optical system*/  550.0);

	EO45505.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 45505, /*diameter*/ 25, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 24.69,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 15.5, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0, /*focal length*/ 29.9924,	/*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNBK7_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/ 8.06,/*edge thickness*/ 1.73, /*free aperture CA*/  24.0,/*numerical Aperture*/  0.42,
		/*price*/  45.5, /*wavelength to trace through optical system*/  550.0);

	EO45506.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 45506, /*diameter*/ 25, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 30.42,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 18.11, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0, /*focal length*/ 35.0427,	/*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNBK7_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/ 7.01,/*edge thickness*/ 2.0, /*free aperture CA*/  24.0,/*numerical Aperture*/  0.36,
		/*price*/  45.5, /*wavelength to trace through optical system*/  550.0);

	EO45507.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 45507, /*diameter*/ 25, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 36.31,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 20.67, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0, /*focal length*/ 39.9963,	/*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNBK7_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/ 5.6,/*edge thickness*/ 1.39, /*free aperture CA*/  24.0,/*numerical Aperture*/  0.31,
		/*price*/  45.5, /*wavelength to trace through optical system*/  550.0);

	EO45508.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 45508, /*diameter*/ 25, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 46.75,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 25.84, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0,	/*focal langth*/ 50.0002, /*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNBK7_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/ 4.9,/*edge thickness*/ 1.68, /*free aperture CA*/  24.0,/*numerical Aperture*/  0.25,
		/*price*/  44.5, /*wavelength to trace through optical system*/  550.0);

	EO45509.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 45509, /*diameter*/ 25, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 56.9,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 31.01, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0,	/*focal length*/ 60.0041, /*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNBK7_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/ 4.7,/*edge thickness*/ 2.07, /*free aperture CA*/  24.0,/*numerical Aperture*/  0.21,
		/*price*/  44.5, /*wavelength to trace through optical system*/  550.0);

	EO45510.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 45510, /*diameter*/ 25, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 72.0,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 38.76, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0,	/*focal length*/ 75.0002, /*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNBK7_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/ 4.5,/*edge thickness*/ 2.43, /*free aperture CA*/  24.0,/*numerical Aperture*/  0.17,
		/*price*/  44.5, /*wavelength to trace through optical system*/  550.0);

	EO45511.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 45511, /*diameter*/ 25, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 82.17,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 43.93, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0,	/*focal length*/ 85.0041, /*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNBK7_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/ 4.3,/*edge thickness*/ 2.48, /*free aperture CA*/  24.0,/*numerical Aperture*/  0.15,
		/*price*/  44.5, /*wavelength to trace through optical system*/  550.0);

	EO45512.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 45512, /*diameter*/ 25, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 97.13,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 51.68, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0,	/*focal length*/ 100.0, /*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNBK7_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/ 4.3,/*edge thickness*/ 2.77, /*free aperture CA*/  24.0,/*numerical Aperture*/  0.13,
		/*price*/  44.5, /*wavelength to trace through optical system*/  550.0);

	EO45513.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 45513, /*diameter*/ 25, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025,  /*back focal length*/ 122.7,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 64.62, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0, /*focal length*/ 125.039,	/*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNBK7_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/ 3.5,/*edge thickness*/ 2.28, /*free aperture CA*/  24.0,/*numerical Aperture*/  0.1,
		/*price*/  44.5, /*wavelength to trace through optical system*/  550.0);

	EO45514.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 45514, /*diameter*/ 25, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 147.81,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 77.55, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0,	/*focal length*/ 150.059, /*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNBK7_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/ 3.5,/*edge thickness*/ 2.49, /*free aperture CA*/  24.0,/*numerical Aperture*/  0.08,
		/*price*/  44.5, /*wavelength to trace through optical system*/  550.0);

	EO45515.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 45515, /*diameter*/ 25, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 172.85,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 90.47, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0,	/*focal length*/ 175.059, /*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNBK7_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/ 3.5,/*edge thickness*/ 2.63, /*free aperture CA*/  24.0,/*numerical Aperture*/  0.07,
		/*price*/  44.5, /*wavelength to trace through optical system*/  550.0);

	EO33361.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 33361, /*diameter*/ 25, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 197.89,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 103.36, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0, /*focal length*/ 200.001, /*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNBK7_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/ 3.2,/*edge thickness*/ 2.44, /*free aperture CA*/  24.0,/*numerical Aperture*/  0.06,
		/*price*/  44.5, /*wavelength to trace through optical system*/  550.0);

	EO67182.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 67182, /*diameter*/ 25, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 148.02,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 129.2, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0,	/*focal length*/ 250.001, /*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNBK7_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/ 3.0,/*edge thickness*/ 2.39, /*free aperture CA*/  24.0,/*numerical Aperture*/  0.05,
		/*price*/  44.5, /*wavelength to trace through optical system*/  550.0);

	EO67183.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 67183, /*diameter*/ 25, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 298.02,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 155.04, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0, /*focal length*/ 300.001,	/*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNBK7_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/ 3.0,/*edge thickness*/ 2.5, /*free aperture CA*/  24.0,/*numerical Aperture*/  0.04,
		/*price*/  44.5, /*wavelength to trace through optical system*/  550.0);

	EO33367.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 33367, /*diameter*/ 25, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 397.89,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 206.72, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0,	/*focal length*/ 400.001, /*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNBK7_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/ 3.2,/*edge thickness*/ 2.82, /*free aperture CA*/  24.0,/*numerical Aperture*/  0.03,
		/*price*/  44.5, /*wavelength to trace through optical system*/  550.0);

	EO47387.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 47387, /*diameter*/ 25, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 497.89,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 258.4, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0, /*focal length*/ 500.002,	/*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNBK7_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/ 3.2,/*edge thickness*/ 2.9, /*free aperture CA*/  24.0,/*numerical Aperture*/  0.03,
		/*price*/  44.5, /*wavelength to trace through optical system*/  550.0);

	EO47388.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 47388, /*diameter*/ 25, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 747.89,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 387.6, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0,	/*focal length*/ 750.002, /*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNBK7_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/ 3.2,/*edge thickness*/ 3.0, /*free aperture CA*/  24.0,/*numerical Aperture*/  0.02,
		/*price*/  44.5, /*wavelength to trace through optical system*/  550.0);

	EO62599.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 62599, /*diameter*/ 25.4, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 21.48,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 19.93, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0, /*focal length*/ 25.3978,	/*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNBK7_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/ 7.0,/*edge thickness*/ 2.43, /*free aperture CA*/  24.4,/*numerical Aperture*/  0.5,
		/*price*/  45.5, /*wavelength to trace through optical system*/  550.0);

	EO62600.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 62600, /*diameter*/ 25.4, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 33.48,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 19.69, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0, /*focal length*/ 38.1,	/*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNBK7_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/ 7.0,/*edge thickness*/ 2.36, /*free aperture CA*/  24.4,/*numerical Aperture*/  0.33,
		/*price*/  45.5, /*wavelength to trace through optical system*/  550.0);

	EO62601.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 62601, /*diameter*/ 25.4, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 47.5,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 26.25, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0, /*focal length*/ 50.7935,	/*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNBK7_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/ 5.0,/*edge thickness*/ 1.72, /*free aperture CA*/  24.4,/*numerical Aperture*/  0.25,
		/*price*/  44.5, /*wavelength to trace through optical system*/  550.0);

	EO62602.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 62602, /*diameter*/ 25.4, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 60.37,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 32.82, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0, /*focal length*/ 63.5064,	/*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNBK7_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/ 4.75,/*edge thickness*/ 2.19, /*free aperture CA*/  24.4,/*numerical Aperture*/  0.2,
		/*price*/  44.5, /*wavelength to trace through optical system*/  550.0);

	EO62603.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 62603, /*diameter*/ 25.4, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 73.56,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 39.38, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0, /*focal length*/ 76.1999,	/*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNBK7_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/ 4.0,/*edge thickness*/ 1.9, /*free aperture CA*/  24.4,/*numerical Aperture*/  0.17,
		/*price*/  44.5, /*wavelength to trace through optical system*/  550.0);

	EO62604.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 62604, /*diameter*/ 25.4, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 86.26,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 45.94, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0,	/*focal length*/ 88.8935, /*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNBK7_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/ 4.0,/*edge thickness*/ 2.21, /*free aperture CA*/  24.4,/*numerical Aperture*/  0.14,
		/*price*/  44.5, /*wavelength to trace through optical system*/  550.0);

	EO62605.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 62605, /*diameter*/ 25.4, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 98.97,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 52.51, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0,	/*focal length*/ 101.606, /*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNBK7_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/ 4.0,/*edge thickness*/ 2.44, /*free aperture CA*/  24.4,/*numerical Aperture*/  0.13,
		/*price*/  44.5, /*wavelength to trace through optical system*/  550.0);

	EO48662.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 48662, /*diameter*/ 30.0, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 26.13,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 23.541, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0, /*focal length*/ 29.9995,	/*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNSF11_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/ 6.9,/*edge thickness*/ 15.0, /*free aperture CA*/  29.0,/*numerical Aperture*/  0.5,
		/*price*/  51.5, /*wavelength to trace through optical system*/  550.0);

	EO67184.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 67184, /*diameter*/ 30.0, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 37.2,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 31.39, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0,	/*focal length*/ 40.0018, /*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNSF11_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/ 5.0,/*edge thickness*/ 1.18, /*free aperture CA*/  29.0,/*numerical Aperture*/  0.38,
		/*price*/  51.5, /*wavelength to trace through optical system*/  550.0);

	EO45709.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 45709, /*diameter*/ 30.0, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 46.17,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 33.63, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0, /*focal length*/ 49.9923,	/*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNSF5_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/ 6.35,/*edge thickness*/ 2.82, /*free aperture CA*/  29.0,/*numerical Aperture*/  0.3,
		/*price*/  51.5, /*wavelength to trace through optical system*/  550.0);

	EO47389.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 47389, /*diameter*/ 30.0, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 56.03,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 31.01, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0, /*focal length*/ 60.0041,	/*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNBK7_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/ 6.0,/*edge thickness*/ 2.13, /*free aperture CA*/  29.0,/*numerical Aperture*/  0.25,
		/*price*/  50.0, /*wavelength to trace through optical system*/  550.0);

	EO45710.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 45710, /*diameter*/ 30.0, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 70.95,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 38.76, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0,	/*focal length*/ 75.0002, /*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNBK7_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/ 6.1,/*edge thickness*/ 3.08, /*free aperture CA*/  29.0,/*numerical Aperture*/  0.2,
		/*price*/  50.0, /*wavelength to trace through optical system*/  550.0);

	EO45711.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 45711, /*diameter*/ 30.0, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 96.01,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 51.68, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0,	/*focal length*/ 100.0, /*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNBK7_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/ 6.0,/*edge thickness*/ 3.78, /*free aperture CA*/  29.0,/*numerical Aperture*/  0.15,
		/*price*/  50.0, /*wavelength to trace through optical system*/  550.0);

	EO47390.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 47390, /*diameter*/ 30.0, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 116.04,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 62.02, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0,	/*focal length*/ 120.008, /*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNBK7_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/ 6.0,/*edge thickness*/ 4.16, /*free aperture CA*/  29.0,/*numerical Aperture*/  0.13,
		/*price*/  50.0, /*wavelength to trace through optical system*/  550.0);

	EO48663.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 48663, /*diameter*/ 40.0, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 35.13,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 31.389, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0,	/*focal length*/ 40.0006, /*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNSF11_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/ 8.7,/*edge thickness*/ 1.5, /*free aperture CA*/  39.0,/*numerical Aperture*/  0.5,
		/*price*/  62.5, /*wavelength to trace through optical system*/  550.0);

	EO45712.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 45712, /*diameter*/ 40.0, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 53.9,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 31.03, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0,	/*focal length*/ 60.0428, /*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNBK7_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/ 9.31,/*edge thickness*/ 2.0, /*free aperture CA*/  39.0,/*numerical Aperture*/  0.33,
		/*price*/  62.5, /*wavelength to trace through optical system*/  550.0);

	EO33385.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 33385, /*diameter*/ 40.0, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 74.73,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 41.344, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0,	/*focal length*/ 80.0002, /*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNBK7_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/ 8.0,/*edge thickness*/ 2.84, /*free aperture CA*/  39.0,/*numerical Aperture*/  0.25,
		/*price*/  61.5, /*wavelength to trace through optical system*/  550.0);

	EO33373.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 33373, /*diameter*/ 40.0, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 95.39,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 51.68, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0,	/*focal length*/ 100.0, /*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNBK7_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/ 7.0,/*edge thickness*/ 2.97, /*free aperture CA*/  39.0,/*numerical Aperture*/  0.2,
		/*price*/  61.5, /*wavelength to trace through optical system*/  550.0);

	EO33379.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 33379, /*diameter*/ 40.0, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 196.7,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 103.36, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0, /*focal length*/ 200.001,	/*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNBK7_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/ 5.0,/*edge thickness*/ 3.05, /*free aperture CA*/  39.0,/*numerical Aperture*/  0.1,
		/*price*/  61.5, /*wavelength to trace through optical system*/  550.0);

	EO47391.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 47391, /*diameter*/ 40.0, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 296.7,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 155.04, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0, /*focal length*/ 300.001,	/*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNBK7_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/ 5.0,/*edge thickness*/ 3.7, /*free aperture CA*/  39.0,/*numerical Aperture*/  0.07,
		/*price*/  61.5, /*wavelength to trace through optical system*/  550.0);

	EO47392.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 47392, /*diameter*/ 40.0, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 396.7,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 206.72, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0, /*focal length*/ 400.001,	/*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNBK7_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/ 5.0,/*edge thickness*/ 4.03, /*free aperture CA*/  39.0,/*numerical Aperture*/  0.05,
		/*price*/  61.5, /*wavelength to trace through optical system*/  550.0);

	EO45715.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 45715, /*diameter*/ 50.0, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 43.28,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 39.24, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0, /*focal length*/ 50.0055,	/*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNSF11_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/ 12.0,/*edge thickness*/ 3.0, /*free aperture CA*/  49.0,/*numerical Aperture*/  0.5,
		/*price*/  67.5, /*wavelength to trace through optical system*/  550.0);

	EO45716.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 45716, /*diameter*/ 50.0, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 67.75,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 38.76, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0, /*focal length*/ 75.0002,	/*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNBK7_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/ 11.0,/*edge thickness*/ 1.86, /*free aperture CA*/  49.0,/*numerical Aperture*/  0.33,
		/*price*/  67.5, /*wavelength to trace through optical system*/  550.0);

	EO45717.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 45717, /*diameter*/ 50.0, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 93.41,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 51.68, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0,	/*focal length*/ 100.00, /*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNBK7_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/ 10.0,/*edge thickness*/ 3.55, /*free aperture CA*/  49.0,/*numerical Aperture*/  0.25,
		/*price*/  64.5, /*wavelength to trace through optical system*/  550.0);

	EO47393.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 47393, /*diameter*/ 50.0, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 118.39,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 64.6, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0,	/*focal length*/ 125.0, /*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNBK7_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/ 10.0,/*edge thickness*/ 4.97, /*free aperture CA*/  49.0,/*numerical Aperture*/  0.2,
		/*price*/  64.5, /*wavelength to trace through optical system*/  550.0);

	EO45718.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 45718, /*diameter*/ 50.0, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 144.07,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 77.52, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0,	/*focal length*/ 150.0, /*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNBK7_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/ 9.0,/*edge thickness*/ 4.86, /*free aperture CA*/  49.0,/*numerical Aperture*/  0.17,
		/*price*/  64.5, /*wavelength to trace through optical system*/  550.0);

	EO47394.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 47394, /*diameter*/ 50.0, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 169.05,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 90.44, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0,	/*focal length*/ 175.001, /*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNBK7_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/ 9.0,/*edge thickness*/ 5.48, /*free aperture CA*/  49.0,/*numerical Aperture*/  0.14,
		/*price*/  64.5, /*wavelength to trace through optical system*/  550.0);

	EO47395.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 47395, /*diameter*/ 50.0, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 196.66,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 103.36, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0,	/*focal length*/ 200.001, /*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNBK7_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/ 5.07,/*edge thickness*/ 2.0, /*free aperture CA*/  49.0,/*numerical Aperture*/  0.13,
		/*price*/  64.5, /*wavelength to trace through optical system*/  550.0);

	EO47396.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 47396, /*diameter*/ 50.0, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 246.74,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 129.21, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0, /*focal length*/ 250.02,	/*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNBK7_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/ 4.94,/*edge thickness*/ 2.5, /*free aperture CA*/  49.0,/*numerical Aperture*/  0.1,
		/*price*/  64.5, /*wavelength to trace through optical system*/  550.0);

	EO47397.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 47397, /*diameter*/ 50.0, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 496.7,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 258.4, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0, /*focal length*/ 500.002,	/*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNBK7_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/ 5.0,/*edge thickness*/ 3.79, /*free aperture CA*/  49.0,/*numerical Aperture*/  0.05,
		/*price*/  64.5, /*wavelength to trace through optical system*/  550.0);

	EO86911.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 86911, /*diameter*/ 75.0, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 53.49,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 38.76, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0, /*focal length*/ 75.0002,	/*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNBK7_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/ 32.62,/*edge thickness*/ 3.66, /*free aperture CA*/  73.5,/*numerical Aperture*/  0.5,
		/*price*/  125.0, /*wavelength to trace through optical system*/  550.0);

	EO86912.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 86912, /*diameter*/ 75.0, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 142.45,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 77.52, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0, /*focal length*/ 150.0,	/*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNBK7_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/ 11.45,/*edge thickness*/ 1.78, /*free aperture CA*/  73.5,/*numerical Aperture*/  0.25,
		/*price*/  125.0, /*wavelength to trace through optical system*/  550.0);

	EO86913.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 86913, /*diameter*/ 75.0, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 194.24,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 103.36, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0,	/*focal length*/ 200.0001, /*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNBK7_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/ 8.74,/*edge thickness*/ 1.7, /*free aperture CA*/  73.5,/*numerical Aperture*/  0.19,
		/*price*/  125.0, /*wavelength to trace through optical system*/  550.0);

	EO86914.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 86914, /*diameter*/ 75.0, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 244.73,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 129.2, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0, /*focal length*/ 250.001,	/*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNBK7_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/ 8.0,/*edge thickness*/ 2.44, /*free aperture CA*/  73.5,/*numerical Aperture*/  0.15,
		/*price*/  125.0, /*wavelength to trace through optical system*/  550.0);

	EO86915.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 86915, /*diameter*/ 75.0, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 494.73,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 258.4, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0, /*focal length*/ 500.002,	/*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNBK7_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/ 8.0,/*edge thickness*/ 5.26, /*free aperture CA*/  73.5,/*numerical Aperture*/  0.07,
		/*price*/  125.0, /*wavelength to trace through optical system*/  550.0);

	EO38489.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 38489, /*diameter*/ 10.0, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 10.99,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.05, /*radius first surface*/ 9.81, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0, /*focal length*/ 12.5014,	/*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNSF11_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/ 2.7,/*edge thickness*/ 1.33, /*free aperture CA*/  9.0,/*numerical Aperture*/  0.4,
		/*price*/  37.5, /*wavelength to trace through optical system*/  550.0);

	EO38492.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 38492, /*diameter*/ 10.0, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 15.66,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.05, /*radius first surface*/ 9.045, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0, /*focal length*/ 17.502,	/*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNBK7_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/ 2.8,/*edge thickness*/ 1.29, /*free aperture CA*/  9.0,/*numerical Aperture*/  0.29,
		/*price*/  37.5, /*wavelength to trace through optical system*/  550.0);

	EO38494.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 38494, /*diameter*/ 12.0, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 32.22,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.05, /*radius first surface*/ 12.92, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0,	/*focal length*/ 25.0001, /*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNBK7_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/ 2.7,/*edge thickness*/ 1.22, /*free aperture CA*/  11.0,/*numerical Aperture*/  0.24,
		/*price*/  41.0, /*wavelength to trace through optical system*/  550.0);

	EO38496.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 38496, /*diameter*/ 12.0, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 48.75,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.05, /*radius first surface*/ 25.84, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0,	/*focal length*/ 50.0002, /*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNBK7_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/ 1.9,/*edge thickness*/ 1.19, /*free aperture CA*/  11.0,/*numerical Aperture*/  0.12,
		/*price*/  41.0, /*wavelength to trace through optical system*/  550.0);

	EO38499.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 38499, /*diameter*/ 12.5, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 10.4,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 9.81, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0,	/*focal length*/ 12.5014, /*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNSF11_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/ 3.75,/*edge thickness*/ 1.5, /*free aperture CA*/  11.5,/*numerical Aperture*/  0.5,
		/*price*/  41.0, /*wavelength to trace through optical system*/  550.0);

	EO38500.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 38500, /*diameter*/ 12.5, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 13.26,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 11.77, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0,	/*focal length*/ 14.9991, /*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNSF11_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/ 3.1,/*edge thickness*/ 1.3, /*free aperture CA*/  11.5,/*numerical Aperture*/  0.42,
		/*price*/  42.0, /*wavelength to trace through optical system*/  550.0);

	EO38503.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 38503, /*diameter*/ 12.5, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 17.69,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 10.335, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0, /*focal length*/ 19.9981,	/*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNBK7_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/ 3.5,/*edge thickness*/ 1.4, /*free aperture CA*/  11.5,/*numerical Aperture*/  0.36,
		/*price*/  42.0, /*wavelength to trace through optical system*/  550.0);

	EO38504.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 38504, /*diameter*/ 12.5, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 22.96,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 12.92, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0,	/*focal length*/ 25.0001, /*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNBK7_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/ 3.1,/*edge thickness*/ 1.49, /*free aperture CA*/  11.5,/*numerical Aperture*/  0.25,
		/*price*/  42.0, /*wavelength to trace through optical system*/  550.0);

	EO38505.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 38505, /*diameter*/ 12.5, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 28.22,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 15.505, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0,	/*focal length*/ 30.002, /*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNBK7_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/ 2.7,/*edge thickness*/ 1.39, /*free aperture CA*/  11.5,/*numerical Aperture*/  0.21,
		/*price*/  41.0, /*wavelength to trace through optical system*/  550.0);

	EO38507.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 38507, /*diameter*/ 12.5, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 38.55,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 20.67, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0,	/*focal length*/ 39.9963, /*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNBK7_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/ 2.2,/*edge thickness*/ 1.23, /*free aperture CA*/  11.5,/*numerical Aperture*/  0.16,
		/*price*/  41.0, /*wavelength to trace through optical system*/  550.0);

	EO38508.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 38508, /*diameter*/ 12.5, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 43.68,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 23.255, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0,	/*focal length*/ 44.9982, /*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNBK7_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/ 2.0,/*edge thickness*/ 1.14, /*free aperture CA*/  11.5,/*numerical Aperture*/  0.14,
		/*price*/  41.0, /*wavelength to trace through optical system*/  550.0);

	EO38509.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 38509, /*diameter*/ 12.5, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 48.68,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 25.84, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0,	/*focal length*/ 50.0002, /*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNBK7_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/ 2.0,/*edge thickness*/ 1.23, /*free aperture CA*/  11.5,/*numerical Aperture*/  0.13,
		/*price*/  41.0, /*wavelength to trace through optical system*/  550.0);

	EO38510.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 38510, /*diameter*/ 12.5, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 73.88,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 38.76, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0,	/*focal length*/ 75.0002, /*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNBK7_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/ 1.7,/*edge thickness*/ 1.19, /*free aperture CA*/  11.5,/*numerical Aperture*/  0.08,
		/*price*/  41.0, /*wavelength to trace through optical system*/  550.0);

	EO38512.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 38512, /*diameter*/ 12.5, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 98.95,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 51.68, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0,	/*focal length*/ 100.0, /*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNBK7_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/ 1.6,/*edge thickness*/ 1.22, /*free aperture CA*/  11.5,/*numerical Aperture*/  0.06,
		/*price*/  41.0, /*wavelength to trace through optical system*/  550.0);

	EO38518.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 38518, /*diameter*/ 12.7, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 98.88,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 51.68, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0,	/*focal length*/ 100.0, /*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNBK7_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/ 1.7,/*edge thickness*/ 1.31, /*free aperture CA*/  11.5,/*numerical Aperture*/  0.06,
		/*price*/  41.0, /*wavelength to trace through optical system*/  550.0);

	EO38519.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 38519, /*diameter*/ 15.0, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 22.5,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 12.92, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0, /*focal length*/ 25.0001,	/*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNBK7_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/ 3.8,/*edge thickness*/ 1.4, /*free aperture CA*/  14.0,/*numerical Aperture*/  0.3,
		/*price*/  42.0, /*wavelength to trace through optical system*/  550.0);

	EO38520.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 38520, /*diameter*/ 15.0, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 48.35,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 25.84, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0,	/*focal length*/ 50.0002, /*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNBK7_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/ 2.5,/*edge thickness*/ 1.39, /*free aperture CA*/  14.0,/*numerical Aperture*/  0.15,
		/*price*/  41.0, /*wavelength to trace through optical system*/  550.0);

	EO38521.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 38521, /*diameter*/ 18.0, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 17.59,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 15.695, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0, /*focal length*/ 20.0009,	/*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNSF11_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/ 4.3,/*edge thickness*/ 1.46, /*free aperture CA*/  17.0,/*numerical Aperture*/  0.45,
		/*price*/  42.0, /*wavelength to trace through optical system*/  550.0);

	EO38522.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 38522, /*diameter*/ 18.0, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 21.51,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 12.92, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0, /*focal length*/ 25.0001, /*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNBK7_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/ 5.3,/*edge thickness*/ 1.65, /*free aperture CA*/  17.0,/*numerical Aperture*/  0.36,
		/*price*/  42.0, /*wavelength to trace through optical system*/  550.0);

	EO38523.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 38523, /*diameter*/ 18.0, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 27.1,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 15.505, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0, /*focal length*/ 30.002,	/*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNBK7_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/ 4.4,/*edge thickness*/ 1.52, /*free aperture CA*/  17.0,/*numerical Aperture*/  0.3,
		/*price*/  42.0, /*wavelength to trace through optical system*/  550.0);

	EO38524.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 38524, /*diameter*/ 18.0, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 48.09,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 25.84, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0,	/*focal length*/ 50.0002, /*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNBK7_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/ 2.9,/*edge thickness*/ 1.28, /*free aperture CA*/  17.0,/*numerical Aperture*/  0.18,
		/*price*/  41.0, /*wavelength to trace through optical system*/  550.0);

	EO38525.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 38525, /*diameter*/ 25.4, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 30.46,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 18.09, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0,	/*focal length*/ 35.004, /*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNBK7_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/ 6.9,/*edge thickness*/ 1.69, /*free aperture CA*/  24.4,/*numerical Aperture*/  0.36,
		/*price*/  45.5, /*wavelength to trace through optical system*/  550.0);

	EO38542.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 38542, /*diameter*/ 25.4, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 36.11,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 20.67, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0, /*focal length*/ 39.9963,	/*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNBK7_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/ 5.9,/*edge thickness*/ 1.54, /*free aperture CA*/  24.4,/*numerical Aperture*/  0.32,
		/*price*/  45.5, /*wavelength to trace through optical system*/  550.0);

	EO38543.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 38543, /*diameter*/ 25.4, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 72.69,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 38.76, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0,	/*focal length*/ 75.0002, /*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNBK7_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/ 3.5,/*edge thickness*/ 1.36, /*free aperture CA*/  24.4,/*numerical Aperture*/  0.17,
		/*price*/  44.5, /*wavelength to trace through optical system*/  550.0);

	EO38544.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 38544, /*diameter*/ 25.4, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 92.02,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 51.68, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0,	/*focal length*/ 100.0, /*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNBK7_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/ 3.0,/*edge thickness*/ 1.42, /*free aperture CA*/  24.4,/*numerical Aperture*/  0.13,
		/*price*/  44.5, /*wavelength to trace through optical system*/  550.0);

	EO38545.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 38545, /*diameter*/ 25.4, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 123.02,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 64.6, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0, /*focal length*/ 125.0,	/*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNBK7_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/ 3.0,/*edge thickness*/ 1.74, /*free aperture CA*/  24.4,/*numerical Aperture*/  0.1,
		/*price*/  44.5, /*wavelength to trace through optical system*/  550.0);

	EO38547.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 38547, /*diameter*/ 25.4, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 148.02,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 77.52, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0, /*focal length*/ 150.0,	/*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNBK7_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/ 3.0,/*edge thickness*/ 1.95, /*free aperture CA*/  24.4,/*numerical Aperture*/  0.08,
		/*price*/  44.5, /*wavelength to trace through optical system*/  550.0);

	EO38548.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 38548, /*diameter*/ 35.0, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 30.52,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 27.465, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0, /*focal length*/ 35.0,	/*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNSF11_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/ 8.0,/*edge thickness*/ 1.7, /*free aperture CA*/  34.0,/*numerical Aperture*/  0.5,
		/*price*/  52.5, /*wavelength to trace through optical system*/  550.0);

	EO38552.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 38552, /*diameter*/ 35.0, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 44.4,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 25.84, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0, /*focal length*/ 50.0002,	/*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNBK7_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/ 8.5,/*edge thickness*/ 1.67, /*free aperture CA*/  34.0,/*numerical Aperture*/  0.35,
		/*price*/  51.0, /*wavelength to trace through optical system*/  550.0);

	EO38561.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 38561, /*diameter*/ 35.0, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 66.04,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 36.175, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0, /*focal length*/ 69.9983,	/*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNBK7_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/ 6.0,/*edge thickness*/ 1.49, /*free aperture CA*/  34.0,/*numerical Aperture*/  0.25,
		/*price*/  51.0, /*wavelength to trace through optical system*/  550.0);

	EO38567.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 38567, /*diameter*/ 35.0, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025, /*back focal length*/ 97.03,
		/*max surface quality*/  40.0, /*min surface quality*/  20.0,	/*curvature (P-V)*/  4.0,	/*min centering*/  0.0, /*max centering*/  1.0,
		/*tolerance center thickness*/  0.1, /*radius first surface*/ 51.68, /*design wavelength*/  587.6,	/*min wavelength range*/  400.0,
		/*max wavelength range*/  1000.0, /*focal length*/ 100.0,	/*Coating*/ "VIS-NIR (400-1000nm)",	/*material*/ mGlasses.getNBK7_S1(), /*power (P-V)*/  1.5,
		/*tolerance focal lenght*/  1.0, /*center thickness*/ 4.5,/*edge thickness*/ 1.45, /*free aperture CA*/  34.0,/*numerical Aperture*/  0.18,
		/*price*/  51.0, /*wavelength to trace through optical system*/  550.0);


}

void EdmundOpticsLensCatalog::loadLensCatalogEO_double_convex_lenses() // https://www.edmundoptics.de/f/vis-nir-coated-double-convex-dcx-lenses/13504/
{
	// DCX lenses with VIS-AIR coating

	EO49447.buildLensTwoSurfaces_DCX(/*lens catalog*/ "EO", /*catalog number*/ 49447, /*durchmesser*/3.0, /*max tolerance diameter*/0.0, /*min tolerance diameter*/-0.025, /*foacl lenght*/ 3.0,
		/*max surface quality*/40.0, /*min surface quality*/20.0, /*curvature (P-V)*/4.0, /*tolerance center thickness*/0.1,
		/*radius first surface*/3.5, /*radius second surface*/-3.5, /*tolerance focal lenght*/1.0, /*min wavelength range*/400,
		/*max wavelength range*/1000, /*back focal length*/ 2.21, /*Coating*/"VIS-NIR (400-1000nm)", /*material*/mGlasses.getNSF5_S1(), /*power (P-V)*/1.5,
		/*min centering*/30.0, /*max centering*/45.0, /*center thickness*/2.3, /*edge thickness*/1.64, /*free aperture CA*/2.7,
		/*design wavelength*/ 587.6, /*numerical Aperture*/0.5, /*price*/ 61.0, /*wavelength to trace through optical system*/ 550.0);

	EO49448.buildLensTwoSurfaces_DCX(/*lens catalog*/ "EO", /*catalog number*/ 49448, /*durchmesser*/3.0, /*max tolerance diameter*/0.0, /*min tolerance diameter*/-0.025, /*focal length*/ 4.5,
		/*max surface quality*/40.0, /*min surface quality*/20.0, /*curvature (P-V)*/4.0, /*tolerance center thickness*/0.1,
		/*radius first surface*/4.29, /*radius second surface*/-4.29, /*tolerance focal lenght*/1.0, /*min wavelength range*/400,
		/*max wavelength range*/1000, /*back focal length*/ 3.78, /*Coating*/"VIS-NIR (400-1000nm)", /*material*/mGlasses.getNBK7_S1(), /*power (P-V)*/1.5,
		/*min centering*/30.0, /*max centering*/45, /*center thickness*/2.0, /*edge thickness*/1.47, /*free aperture CA*/2.7,
		/*design wavelength*/ 587.6, /*numerical Aperture*/0.33, /*price*/ 61.0, /*wavelength to trace through optical system*/550.0);

	EO49449.buildLensTwoSurfaces_DCX(/*lens catalog*/ "EO", /*catalog number*/ 49449, /*durchmesser*/3.0, /*max tolerance diameter*/0.0, /*min tolerance diameter*/-0.025, /*focal length*/ 6.0,
		/*max surface quality*/40.0, /*min surface quality*/20.0, /*curvature (P-V)*/4.0, /*tolerance center thickness*/0.1,
		/*radius first surface*/5.88, /*radius second surface*/-5.88, /*tolerance focal lenght*/1.0, /*min wavelength range*/400,
		/*max wavelength range*/1000, /*focal length*/ 5.37, /*Coating*/"VIS-NIR (400-1000nm)", /*material*/mGlasses.getNBK7_S1(), /*power (P-V)*/1.5,
		/*min centering*/0.0, /*max centering*/3.0, /*center thickness*/1.80, /*edge thickness*/1.41, /*free aperture CA*/2.7,				//centering <3
		/*design wavelength*/ 587.6, /*numerical Aperture*/0.25, /*price*/ 61.0, /*wavelength to trace through optical system*/550.0);

	EO49450.buildLensTwoSurfaces_DCX(/*lens catalog*/ "EO", /*catalog number*/ 49450, /*durchmesser*/3.0, /*max tolerance diameter*/0.0, /*min tolerance diameter*/-0.025, /*focal length*/ 9.0,
		/*max surface quality*/40.0, /*min surface quality*/20.0, /*curvature (P-V)*/4.0, /*tolerance center thickness*/0.1,
		/*radius first surface*/9.02, /*radius second surface*/-9.02, /*tolerance focal lenght*/1.0, /*min wavelength range*/400,
		/*max wavelength range*/1000, /*back focal length*/ 8.46, /*Coating*/"VIS-NIR (400-1000nm)", /*material*/mGlasses.getNBK7_S1(), /*power (P-V)*/1.5,
		/*min centering*/0.0, /*max centering*/3.0, /*center thickness*/1.60, /*edge thickness*/1.35, /*free aperture CA*/2.7,				//centering <3
		/*design wavelength*/ 587.6, /*numerical Aperture*/0.17, /*price*/ 61.0, /*wavelength to trace through optical system*/550.0);

	EO47893.buildLensTwoSurfaces_DCX(/*lens catalog*/ "EO", /*catalog number*/ 47893, /*durchmesser*/4.5, /*max tolerance diameter*/0.0, /*min tolerance diameter*/-0.025, /*focal length*/ 4.5,
		/*max surface quality*/40.0, /*min surface quality*/20.0, /*curvature (P-V)*/4.0, /*tolerance center thickness*/0.1,
		/*radius first surface*/6.58, /*radius second surface*/-6.58, /*tolerance focal lenght*/1.0, /*min wavelength range*/400,
		/*max wavelength range*/1000, /*back focal length*/ 3.7, /*Coating*/"VIS-NIR (400-1000nm)", /*material*/mGlasses.getNLASF44_S1(), /*power (P-V)*/1.5,
		/*min centering*/30.0, /*max centering*/45.0, /*center thickness*/2.60, /*edge thickness*/1.80, /*free aperture CA*/4.05,
		/*design wavelength*/ 587.6, /*numerical Aperture*/0.50, /*price*/ 59.0, /*wavelength to trace through optical system*/550.0);

	EO47894.buildLensTwoSurfaces_DCX(/*lens catalog*/ "EO", /*catalog number*/ 47894, /*durchmesser*/4.5, /*max tolerance diameter*/0.0, /*min tolerance diameter*/-0.025, /*focal length*/ 9.0,
		/*max surface quality*/40.0, /*min surface quality*/20.0, /*curvature (P-V)*/4.0, /*tolerance center thickness*/0.1,
		/*radius first surface*/8.88, /*radius second surface*/-8.88, /*tolerance focal lenght*/1.0, /*min wavelength range*/400,
		/*max wavelength range*/1000, /*back focal length*/ 8.16, /*Coating*/"VIS-NIR (400-1000nm)", /*material*/mGlasses.getNBK7_S1(), /*power (P-V)*/1.5,
		/*min centering*/0.0, /*max centering*/3.0, /*center thickness*/2.38, /*edge thickness*/1.80, /*free aperture CA*/4.05,				//centering <3
		/*design wavelength*/ 587.6, /*numerical Aperture*/0.25, /*price*/ 59.0, /*wavelength to trace through optical system*/550.0);

	EO63658.buildLensTwoSurfaces_DCX(/*lens catalog*/ "EO", /*catalog number*/ 63658, /*durchmesser*/5.0, /*max tolerance diameter*/0.0, /*min tolerance diameter*/-0.025, /*focal length*/ 5.0,
		/*max surface quality*/40.0, /*min surface quality*/20.0, /*curvature (P-V)*/4.0, /*tolerance center thickness*/0.1,
		/*radius first surface*/6.18, /*radius second surface*/-6.18, /*tolerance focal lenght*/1.0, /*min wavelength range*/400,
		/*max wavelength range*/1000, /*back focal length*/ 4.19, /*Coating*/"VIS-NIR (400-1000nm)", /*material*/mGlasses.getNSF5_S1(), /*power (P-V)*/1.5,
		/*min centering*/30.0, /*max centering*/45.0, /*center thickness*/2.50, /*edge thickness*/1.44, /*free aperture CA*/4.50,
		/*design wavelength*/ 587.6, /*numerical Aperture*/0.50, /*price*/ 44.50, /*wavelength to trace through optical system*/550.0);

	EO63659.buildLensTwoSurfaces_DCX(/*lens catalog*/ "EO", /*catalog number*/ 63659, /*durchmesser*/5.0, /*max tolerance diameter*/0.0, /*min tolerance diameter*/-0.025, /*focal length*/ 10.0,
		/*max surface quality*/40.0, /*min surface quality*/20.0, /*curvature (P-V)*/4.0, /*tolerance center thickness*/0.1,
		/*radius first surface*/9.98, /*radius second surface*/-9.98, /*tolerance focal lenght*/1.0, /*min wavelength range*/400,
		/*max wavelength range*/1000, /*back focal length*/ 9.31, /*Coating*/"VIS-NIR (400-1000nm)", /*material*/mGlasses.getNBK7_S1(), /*power (P-V)*/1.5,
		/*min centering*/0.0, /*max centering*/3.0, /*center thickness*/2.00, /*edge thickness*/1.36, /*free aperture CA*/4.50,				//centering <3
		/*design wavelength*/ 587.6, /*numerical Aperture*/0.25, /*price*/ 44.50, /*wavelength to trace through optical system*/550.0);

	EO63660.buildLensTwoSurfaces_DCX(/*lens catalog*/ "EO", /*catalog number*/ 63660, /*durchmesser*/5.0, /*max tolerance diameter*/0.0, /*min tolerance diameter*/-0.025, /*focal length*/ 15.0,
		/*max surface quality*/40.0, /*min surface quality*/20.0, /*curvature (P-V)*/4.0, /*tolerance center thickness*/0.1,
		/*radius first surface*/15.16, /*radius second surface*/-15.16, /*tolerance focal lenght*/1.0, /*min wavelength range*/400,
		/*max wavelength range*/1000, /*back focal length*/ 14.33, /*Coating*/"VIS-NIR (400-1000nm)", /*material*/mGlasses.getNBK7_S1(), /*power (P-V)*/1.5,
		/*min centering*/0.0, /*max centering*/1.0, /*center thickness*/2.0, /*edge thickness*/1.58, /*free aperture CA*/4.50,				//centering <1
		/*design wavelength*/ 587.6, /*numerical Aperture*/0.17, /*price*/ 44.50, /*wavelength to trace through optical system*/550.0);

	EO63661.buildLensTwoSurfaces_DCX(/*lens catalog*/ "EO", /*catalog number*/ 63661, /*durchmesser*/5.0, /*max tolerance diameter*/0.0, /*min tolerance diameter*/-0.025, /*focal length*/ 20.0,
		/*max surface quality*/40.0, /*min surface quality*/20.0, /*curvature (P-V)*/4.0, /*tolerance center thickness*/0.1,
		/*radius first surface*/20.41, /*radius second surface*/-20.41, /*tolerance focal lenght*/1.0, /*min wavelength range*/400,
		/*max wavelength range*/1000, /*back focal length*/ 19.5, /*Coating*/"VIS-NIR (400-1000nm)", /*material*/mGlasses.getNBK7_S1(), /*power (P-V)*/1.5,
		/*min centering*/0.0, /*max centering*/1.0, /*center thickness*/1.50, /*edge thickness*/1.19, /*free aperture CA*/4.50,				//centering <1
		/*design wavelength*/ 587.6, /*numerical Aperture*/0.13, /*price*/ 44.50, /*wavelength to trace through optical system*/550.0);

	EO63662.buildLensTwoSurfaces_DCX(/*lens catalog*/ "EO", /*catalog number*/ 63662, /*durchmesser*/5.0, /*max tolerance diameter*/0.0, /*min tolerance diameter*/-0.025, /*focal length*/ 25.0,
		/*max surface quality*/40.0, /*min surface quality*/20.0, /*curvature (P-V)*/4.0, /*tolerance center thickness*/0.1,
		/*radius first surface*/25.58, /*radius second surface*/-25.58, /*tolerance focal lenght*/1.0, /*min wavelength range*/400,
		/*max wavelength range*/1000, /*back focal length*/ 24.5, /*Coating*/"VIS-NIR (400-1000nm)", /*material*/mGlasses.getNBK7_S1(), /*power (P-V)*/1.5,
		/*min centering*/0.0, /*max centering*/1.0, /*center thickness*/1.50, /*edge thickness*/1.26, /*free aperture CA*/4.50,				//centering <1
		/*design wavelength*/ 587.6, /*numerical Aperture*/0.10, /*price*/ 44.50, /*wavelength to trace through optical system*/550.0);

	EO45859.buildLensTwoSurfaces_DCX(/*lens catalog*/ "EO", /*catalog number*/ 45859, /*durchmesser*/6.0, /*max tolerance diameter*/0.0, /*min tolerance diameter*/-0.025, /*focal length*/ 6.0,
		/*max surface quality*/40.0, /*min surface quality*/20.0, /*curvature (P-V)*/4.0, /*tolerance center thickness*/0.1,
		/*radius first surface*/7.59, /*radius second surface*/-7.59, /*tolerance focal lenght*/1.0, /*min wavelength range*/400,
		/*max wavelength range*/1000, /*back focal length*/ 5.19, /*Coating*/"VIS-NIR (400-1000nm)", /*material*/mGlasses.getNSF5_S1(), /*power (P-V)*/1.5,
		/*min centering*/0.0, /*max centering*/3.0, /*center thickness*/2.54, /*edge thickness*/1.29, /*free aperture CA*/5.40,				//centering <3
		/*design wavelength*/ 587.6, /*numerical Aperture*/0.50, /*price*/ 35.50, /*wavelength to trace through optical system*/550.0);

	EO45860.buildLensTwoSurfaces_DCX(/*lens catalog*/ "EO", /*catalog number*/ 45860, /*durchmesser*/6.0, /*max tolerance diameter*/0.0, /*min tolerance diameter*/-0.025, /*focal length*/ 9.0,
		/*max surface quality*/40.0, /*min surface quality*/20.0, /*curvature (P-V)*/4.0, /*tolerance center thickness*/0.1,
		/*radius first surface*/8.91, /*radius second surface*/-8.91, /*tolerance focal lenght*/1.0, /*min wavelength range*/400,
		/*max wavelength range*/1000, /*back focal length*/ 8.22, /*Coating*/"VIS-NIR (400-1000nm)", /*material*/mGlasses.getNBK7_S1(), /*power (P-V)*/1.5,
		/*min centering*/0.0, /*max centering*/3.0, /*center thickness*/2.25, /*edge thickness*/1.22, /*free aperture CA*/5.40,				//centering <3
		/*design wavelength*/ 587.6, /*numerical Aperture*/0.33, /*price*/ 35.50, /*wavelength to trace through optical system*/550.0);

	EO45861.buildLensTwoSurfaces_DCX(/*lens catalog*/ "EO", /*catalog number*/ 45861, /*durchmesser*/6.0, /*max tolerance diameter*/0.0, /*min tolerance diameter*/-0.025, /*focal length*/ 12.0,
		/*max surface quality*/40.0, /*min surface quality*/20.0, /*curvature (P-V)*/4.0, /*tolerance center thickness*/0.1,
		/*radius first surface*/11.98, /*radius second surface*/-11.98, /*tolerance focal lenght*/1.0, /*min wavelength range*/400,
		/*max wavelength range*/1000, /*back focal length*/ 11.18, /*Coating*/"VIS-NIR (400-1000nm)", /*material*/mGlasses.getNBK7_S1(), /*power (P-V)*/1.5,
		/*min centering*/0.0, /*max centering*/1.0, /*center thickness*/2.40, /*edge thickness*/1.64, /*free aperture CA*/5.40,				//centering <1
		/*design wavelength*/ 587.6, /*numerical Aperture*/0.25, /*price*/ 35.50, /*wavelength to trace through optical system*/550.0);

	EO45862.buildLensTwoSurfaces_DCX(/*lens catalog*/ "EO", /*catalog number*/ 45862, /*durchmesser*/6.0, /*max tolerance diameter*/0.0, /*min tolerance diameter*/-0.025, /*focal length*/ 18.0,
		/*max surface quality*/40.0, /*min surface quality*/20.0, /*curvature (P-V)*/4.0, /*tolerance center thickness*/0.1,
		/*radius first surface*/18.22, /*radius second surface*/-18.22, /*tolerance focal lenght*/1.0, /*min wavelength range*/400,
		/*max wavelength range*/1000, /*back focal length*/ 17.26, /*Coating*/"VIS-NIR (400-1000nm)", /*material*/mGlasses.getNBK7_S1(), /*power (P-V)*/1.5,
		/*min centering*/0.0, /*max centering*/1.0, /*center thickness*/2.20, /*edge thickness*/1.70, /*free aperture CA*/5.40,				//centering <1
		/*design wavelength*/ 587.6, /*numerical Aperture*/0.17, /*price*/ 35.50, /*wavelength to trace through optical system*/550.0);

	EO45863.buildLensTwoSurfaces_DCX(/*lens catalog*/ "EO", /*catalog number*/ 45863, /*durchmesser*/6.0, /*max tolerance diameter*/0.0, /*min tolerance diameter*/-0.025, /*focal length*/ 24.0,
		/*max surface quality*/40.0, /*min surface quality*/20.0, /*curvature (P-V)*/4.0, /*tolerance center thickness*/0.1,
		/*radius first surface*/24.36, /*radius second surface*/-24.36, /*tolerance focal lenght*/1.0, /*min wavelength range*/400,
		/*max wavelength range*/1000, /*back focal length*/ 23.13, /*Coating*/"VIS-NIR (400-1000nm)", /*material*/mGlasses.getNBK7_S1(), /*power (P-V)*/1.5,
		/*min centering*/0.0, /*max centering*/1.0, /*center thickness*/2.60, /*edge thickness*/2.23, /*free aperture CA*/5.40,				//centering <1
		/*design wavelength*/ 587.6, /*numerical Aperture*/0.13, /*price*/ 35.50, /*wavelength to trace through optical system*/550.0);

	EO45864.buildLensTwoSurfaces_DCX(/*lens catalog*/ "EO", /*catalog number*/ 45864, /*durchmesser*/6.0, /*max tolerance diameter*/0.0, /*min tolerance diameter*/-0.025, /*focal length*/ 30.0,
		/*max surface quality*/40.0, /*min surface quality*/20.0, /*curvature (P-V)*/4.0, /*tolerance center thickness*/0.1,
		/*radius first surface*/30.61, /*radius second surface*/-30.61, /*tolerance focal lenght*/1.0, /*min wavelength range*/400,
		/*max wavelength range*/1000, /*back focal length*/ 29.23, /*Coating*/"VIS-NIR (400-1000nm)", /*material*/mGlasses.getNBK7_S1(), /*power (P-V)*/1.5,
		/*min centering*/0.0, /*max centering*/1.0, /*center thickness*/2.30, /*edge thickness*/2.00, /*free aperture CA*/5.40,				//centering <1
		/*design wavelength*/ 587.6, /*numerical Aperture*/0.10, /*price*/ 35.50, /*wavelength to trace through optical system*/550.0);

	EO45865.buildLensTwoSurfaces_DCX(/*lens catalog*/ "EO", /*catalog number*/ 45865, /*durchmesser*/6.0, /*max tolerance diameter*/0.0, /*min tolerance diameter*/-0.025, /*focal length*/ 36.0,
		/*max surface quality*/40.0, /*min surface quality*/20.0, /*curvature (P-V)*/4.0, /*tolerance center thickness*/0.1,
		/*radius first surface*/36.87, /*radius second surface*/-36.87, /*tolerance focal lenght*/1.0, /*min wavelength range*/400,
		/*max wavelength range*/1000, /*back focal length*/ 35.33, /*Coating*/"VIS-NIR (400-1000nm)", /*material*/mGlasses.getNBK7_S1(), /*power (P-V)*/1.5,
		/*min centering*/0.0, /*max centering*/1.0, /*center thickness*/2.00, /*edge thickness*/1.76, /*free aperture CA*/5.40,				//centering <1
		/*design wavelength*/ 587.6, /*numerical Aperture*/0.08, /*price*/ 35.50, /*wavelength to trace through optical system*/550.0);

	EO45866.buildLensTwoSurfaces_DCX(/*lens catalog*/ "EO", /*catalog number*/ 45866, /*durchmesser*/9.0, /*max tolerance diameter*/0.0, /*min tolerance diameter*/-0.025, /*focal length*/ 9,
		/*max surface quality*/40.0, /*min surface quality*/20.0, /*curvature (P-V)*/4.0, /*tolerance center thickness*/0.1,
		/*radius first surface*/11.38, /*radius second surface*/-11.38, /*tolerance focal lenght*/1.0, /*min wavelength range*/400,
		/*max wavelength range*/1000, /*back focal length*/ 7.9, /*Coating*/"VIS-NIR (400-1000nm)", /*material*/mGlasses.getNSF5_S1(), /*power (P-V)*/1.5,
		/*min centering*/0.0, /*max centering*/3.0, /*center thickness*/3.45, /*edge thickness*/1.60, /*free aperture CA*/8.10,				//centering <3
		/*design wavelength*/ 587.6, /*numerical Aperture*/0.50, /*price*/ 36.50, /*wavelength to trace through optical system*/550.0);

	EO45867.buildLensTwoSurfaces_DCX(/*lens catalog*/ "EO", /*catalog number*/ 45867, /*durchmesser*/9.0, /*max tolerance diameter*/0.0, /*min tolerance diameter*/-0.025,/*focal length*/ 13.5,
		/*max surface quality*/40.0, /*min surface quality*/20.0, /*curvature (P-V)*/4.0, /*tolerance center thickness*/0.1,
		/*radius first surface*/13.46, /*radius second surface*/-13.46, /*tolerance focal lenght*/1.0, /*min wavelength range*/400,
		/*max wavelength range*/1000, /*back focal length*/ 12.56, /*Coating*/"VIS-NIR (400-1000nm)", /*material*/mGlasses.getNBK7_S1(), /*power (P-V)*/1.5,
		/*min centering*/0.0, /*max centering*/1.0, /*center thickness*/2.75, /*edge thickness*/1.20, /*free aperture CA*/8.10,				//centering <1
		/*design wavelength*/ 587.6, /*numerical Aperture*/0.33, /*price*/ 36.50, /*wavelength to trace through optical system*/550.0);

	EO45868.buildLensTwoSurfaces_DCX(/*lens catalog*/ "EO", /*catalog number*/ 45868, /*durchmesser*/9.0, /*max tolerance diameter*/0.0, /*min tolerance diameter*/-0.025,/*focal length*/ 18.0,
		/*max surface quality*/40.0, /*min surface quality*/20.0, /*curvature (P-V)*/4.0, /*tolerance center thickness*/0.1,
		/*radius first surface*/18.15, /*radius second surface*/-18.15, /*tolerance focal lenght*/1.0, /*min wavelength range*/400,
		/*max wavelength range*/1000, /*back focal length*/ 17.12, /*Coating*/"VIS-NIR (400-1000nm)", /*material*/mGlasses.getNBK7_S1(), /*power (P-V)*/1.5,
		/*min centering*/0.0, /*max centering*/1.0, /*center thickness*/2.60, /*edge thickness*/1.47, /*free aperture CA*/8.10,				//centering <1
		/*design wavelength*/ 587.6, /*numerical Aperture*/0.26, /*price*/ 36.50, /*wavelength to trace through optical system*/550.0);

	EO45869.buildLensTwoSurfaces_DCX(/*lens catalog*/ "EO", /*catalog number*/ 45869, /*durchmesser*/9.0, /*max tolerance diameter*/0.0, /*min tolerance diameter*/-0.025, /*focal length*/ 27.0,
		/*max surface quality*/40.0, /*min surface quality*/20.0, /*curvature (P-V)*/4.0, /*tolerance center thickness*/0.1,
		/*radius first surface*/27.43, /*radius second surface*/-27.43, /*tolerance focal lenght*/1.0, /*min wavelength range*/400,
		/*max wavelength range*/1000, /*back focal length*/ 26.08, /*Coating*/"VIS-NIR (400-1000nm)", /*material*/mGlasses.getNBK7_S1(), /*power (P-V)*/1.5,
		/*min centering*/0.0, /*max centering*/1.0, /*center thickness*/2.74, /*edge thickness*/2.00, /*free aperture CA*/8.10,				//centering <1
		/*design wavelength*/ 587.6, /*numerical Aperture*/0.17, /*price*/ 36.50, /*wavelength to trace through optical system*/550.0);

	EO45870.buildLensTwoSurfaces_DCX(/*lens catalog*/ "EO", /*catalog number*/ 45870, /*durchmesser*/9.0, /*max tolerance diameter*/0.0, /*min tolerance diameter*/-0.025, /*focal length*/ 36.0,
		/*max surface quality*/40.0, /*min surface quality*/20.0, /*curvature (P-V)*/4.0, /*tolerance center thickness*/0.1,
		/*radius first surface*/36.77, /*radius second surface*/-36.77, /*tolerance focal lenght*/1.0, /*min wavelength range*/400,
		/*max wavelength range*/1000, /*back focal length*/ 35.15, /*Coating*/"VIS-NIR (400-1000nm)", /*material*/mGlasses.getNBK7_S1(), /*power (P-V)*/1.5,
		/*min centering*/0.0, /*max centering*/1.0, /*center thickness*/2.55, /*edge thickness*/2.00, /*free aperture CA*/8.10,				//centering <1
		/*design wavelength*/ 587.6, /*numerical Aperture*/0.13, /*price*/ 36.50, /*wavelength to trace through optical system*/550.0);

	EO45871.buildLensTwoSurfaces_DCX(/*lens catalog*/ "EO", /*catalog number*/ 45871, /*durchmesser*/9.0, /*max tolerance diameter*/0.0, /*min tolerance diameter*/-0.025, /*focal length*/ 45.0,
		/*max surface quality*/40.0, /*min surface quality*/20.0, /*curvature (P-V)*/4.0, /*tolerance center thickness*/0.1,
		/*radius first surface*/46.08, /*radius second surface*/-46.08, /*tolerance focal lenght*/1.0, /*min wavelength range*/400,
		/*max wavelength range*/1000, /*back focal length*/ 44.17, /*Coating*/"VIS-NIR (400-1000nm)", /*material*/mGlasses.getNBK7_S1(), /*power (P-V)*/1.5,
		/*min centering*/0.0, /*max centering*/1.0, /*center thickness*/2.50, /*edge thickness*/2.06, /*free aperture CA*/8.10,				//centering <1
		/*design wavelength*/ 587.6, /*numerical Aperture*/0.10, /*price*/ 36.50, /*wavelength to trace through optical system*/550.0);

	EO63663.buildLensTwoSurfaces_DCX(/*lens catalog*/ "EO", /*catalog number*/ 63663, /*durchmesser*/10.0, /*max tolerance diameter*/0.0, /*min tolerance diameter*/-0.025, /*focal length*/ 10.0,
		/*max surface quality*/40.0, /*min surface quality*/20.0, /*curvature (P-V)*/4.0, /*tolerance center thickness*/0.1,
		/*radius first surface*/12.71, /*radius second surface*/-12.71, /*tolerance focal lenght*/1.0, /*min wavelength range*/400,
		/*max wavelength range*/1000, /*back focal length*/ 8.89, /*Coating*/"VIS-NIR (400-1000nm)", /*material*/mGlasses.getNSF5_S1(), /*power (P-V)*/1.5,
		/*min centering*/0.0, /*max centering*/1.0, /*center thickness*/3.50, /*edge thickness*/1.45, /*free aperture CA*/9.0,				//centering <1
		/*design wavelength*/ 587.6, /*numerical Aperture*/0.50, /*price*/ 36.50, /*wavelength to trace through optical system*/550.0);

	EO63664.buildLensTwoSurfaces_DCX(/*lens catalog*/ "EO", /*catalog number*/ 63664, /*durchmesser*/10.0, /*max tolerance diameter*/0.0, /*min tolerance diameter*/-0.025, /*focal length*/ 15.0,
		/*max surface quality*/40.0, /*min surface quality*/20.0, /*curvature (P-V)*/4.0, /*tolerance center thickness*/0.1,
		/*radius first surface*/14.88, /*radius second surface*/-14.88, /*tolerance focal lenght*/1.0, /*min wavelength range*/400,
		/*max wavelength range*/1000, /*back focal length*/ 13.8, /*Coating*/"VIS-NIR (400-1000nm)", /*material*/mGlasses.getNBK7_S1(), /*power (P-V)*/1.5,
		/*min centering*/0.0, /*max centering*/1.0, /*center thickness*/3.50, /*edge thickness*/1.77, /*free aperture CA*/9.0,				//centering <1
		/*design wavelength*/ 587.6, /*numerical Aperture*/0.33, /*price*/ 36.50, /*wavelength to trace through optical system*/550.0);

	EO63665.buildLensTwoSurfaces_DCX(/*lens catalog*/ "EO", /*catalog number*/ 63665, /*durchmesser*/10.0, /*max tolerance diameter*/0.0, /*min tolerance diameter*/-0.025, /*focal length*/ 20.0,
		/*max surface quality*/40.0, /*min surface quality*/20.0, /*curvature (P-V)*/4.0, /*tolerance center thickness*/0.1,
		/*radius first surface*/20.24, /*radius second surface*/-20.24, /*tolerance focal lenght*/1.0, /*min wavelength range*/400,
		/*max wavelength range*/1000, /*back focal length*/ 19.16, /*Coating*/"VIS-NIR (400-1000nm)", /*material*/mGlasses.getNBK7_S1(), /*power (P-V)*/1.5,
		/*min centering*/0.0, /*max centering*/1.0, /*center thickness*/2.50, /*edge thickness*/1.25, /*free aperture CA*/9.0,				//centering <1
		/*design wavelength*/ 587.6, /*numerical Aperture*/0.25, /*price*/ 36.50, /*wavelength to trace through optical system*/550.0);

	EO63666.buildLensTwoSurfaces_DCX(/*lens catalog*/ "EO", /*catalog number*/ 63666, /*durchmesser*/10.0, /*max tolerance diameter*/0.0, /*min tolerance diameter*/-0.025, /*focal length*/ 25.0,
		/*max surface quality*/40.0, /*min surface quality*/20.0, /*curvature (P-V)*/4.0, /*tolerance center thickness*/0.1,
		/*radius first surface*/25.41, /*radius second surface*/-25.41, /*tolerance focal lenght*/1.0, /*min wavelength range*/400,
		/*max wavelength range*/1000, /*back focal length*/ 24.16, /*Coating*/"VIS-NIR (400-1000nm)", /*material*/mGlasses.getNBK7_S1(), /*power (P-V)*/1.5,
		/*min centering*/0.0, /*max centering*/1.0, /*center thickness*/2.5, /*edge thickness*/1.51, /*free aperture CA*/9.00,				//centering <1
		/*design wavelength*/ 587.6, /*numerical Aperture*/0.20, /*price*/ 36.50, /*wavelength to trace through optical system*/550.0);

	EO63667.buildLensTwoSurfaces_DCX(/*lens catalog*/ "EO", /*catalog number*/ 63667, /*durchmesser*/10.0, /*max tolerance diameter*/0.0, /*min tolerance diameter*/-0.025, /*focal length*/ 30.0,
		/*max surface quality*/40.0, /*min surface quality*/20.0, /*curvature (P-V)*/4.0, /*tolerance center thickness*/0.1,
		/*radius first surface*/30.58, /*radius second surface*/-30.58, /*tolerance focal lenght*/1.0, /*min wavelength range*/400,
		/*max wavelength range*/1000, /*back focal length*/ 29.17, /*Coating*/"VIS-NIR (400-1000nm)", /*material*/mGlasses.getNBK7_S1(), /*power (P-V)*/1.5,
		/*min centering*/0.0, /*max centering*/1.0, /*center thickness*/2.50, /*edge thickness*/1.68, /*free aperture CA*/9.0,				//centering <1
		/*design wavelength*/ 587.6, /*numerical Aperture*/0.17, /*price*/ 36.50, /*wavelength to trace through optical system*/550.0);

	EO63668.buildLensTwoSurfaces_DCX(/*lens catalog*/ "EO", /*catalog number*/ 63668, /*durchmesser*/10.0, /*max tolerance diameter*/0.0, /*min tolerance diameter*/-0.025, /*focal length*/ 40.0,
		/*max surface quality*/40.0, /*min surface quality*/20.0, /*curvature (P-V)*/4.0, /*tolerance center thickness*/0.1,
		/*radius first surface*/40.91, /*radius second surface*/-40.91, /*tolerance focal lenght*/1.0, /*min wavelength range*/400,
		/*max wavelength range*/1000, /*back focal length*/ 39.16, /*Coating*/"VIS-NIR (400-1000nm)", /*material*/mGlasses.getNBK7_S1(), /*power (P-V)*/1.5,
		/*min centering*/0.0, /*max centering*/1.0, /*center thickness*/2.50, /*edge thickness*/1.89, /*free aperture CA*/9.0,				//centering <1
		/*design wavelength*/ 587.6, /*numerical Aperture*/0.13, /*price*/ 36.50, /*wavelength to trace through optical system*/550.0);

	EO63669.buildLensTwoSurfaces_DCX(/*lens catalog*/ "EO", /*catalog number*/ 63669, /*durchmesser*/10.0, /*max tolerance diameter*/0.0, /*min tolerance diameter*/-0.025, /*focal length*/ 50.0,
		/*max surface quality*/40.0, /*min surface quality*/20.0, /*curvature (P-V)*/4.0, /*tolerance center thickness*/0.1,
		/*radius first surface*/51.25, /*radius second surface*/-51.25, /*tolerance focal lenght*/1.0, /*min wavelength range*/400,
		/*max wavelength range*/1000, /*back focal length*/ 49.17, /*Coating*/"VIS-NIR (400-1000nm)", /*material*/mGlasses.getNBK7_S1(), /*power (P-V)*/1.5,
		/*min centering*/0.0, /*max centering*/1.0, /*center thickness*/2.5, /*edge thickness*/2.01, /*free aperture CA*/9.0,				//centering <1
		/*design wavelength*/ 587.6, /*numerical Aperture*/0.1, /*price*/ 36.50, /*wavelength to trace through optical system*/550.0);

	EO63670.buildLensTwoSurfaces_DCX(/*lens catalog*/ "EO", /*catalog number*/ 63670, /*durchmesser*/10.0, /*max tolerance diameter*/0.0, /*min tolerance diameter*/-0.025, /*focal length*/ 100.0,
		/*max surface quality*/40.0, /*min surface quality*/20.0, /*curvature (P-V)*/4.0, /*tolerance center thickness*/0.1,
		/*radius first surface*/102.93, /*radius second surface*/-102.93, /*tolerance focal lenght*/1.0, /*min wavelength range*/400,
		/*max wavelength range*/1000, /*back focal length*/ 99.17, /*Coating*/"VIS-NIR (400-1000nm)", /*material*/mGlasses.getNBK7_S1(), /*power (P-V)*/1.5,
		/*min centering*/0.0, /*max centering*/1.0, /*center thickness*/2.50, /*edge thickness*/2.26, /*free aperture CA*/9.0,				//centering <1
		/*design wavelength*/ 587.6, /*numerical Aperture*/0.05, /*price*/ 36.50, /*wavelength to trace through optical system*/550.0);

	EO45872.buildLensTwoSurfaces_DCX(/*lens catalog*/ "EO", /*catalog number*/ 45872, /*durchmesser*/12.0, /*max tolerance diameter*/0.0, /*min tolerance diameter*/-0.025, /*focal length*/ 12.0,
		/*max surface quality*/40.0, /*min surface quality*/20.0, /*curvature (P-V)*/4.0, /*tolerance center thickness*/0.1,
		/*radius first surface*/15.34, /*radius second surface*/-15.34, /*tolerance focal lenght*/1.0, /*min wavelength range*/400,
		/*max wavelength range*/1000, /*back focal length*/ 10.79, /*Coating*/"VIS-NIR (400-1000nm)", /*material*/mGlasses.getNSF5_S1(), /*power (P-V)*/1.5,
		/*min centering*/0.0, /*max centering*/1.0, /*center thickness*/3.85, /*edge thickness*/1.41, /*free aperture CA*/11.0,				//centering <1
		/*design wavelength*/ 587.6, /*numerical Aperture*/0.5, /*price*/ 38.00, /*wavelength to trace through optical system*/550.0);

	EO45873.buildLensTwoSurfaces_DCX(/*lens catalog*/ "EO", /*catalog number*/ 45873, /*durchmesser*/12.0, /*max tolerance diameter*/0.0, /*min tolerance diameter*/-0.025, /*focal length*/ 18.0,
		/*max surface quality*/40.0, /*min surface quality*/20.0, /*curvature (P-V)*/4.0, /*tolerance center thickness*/0.1,
		/*radius first surface*/18.01, /*radius second surface*/-18.01, /*tolerance focal lenght*/1.0, /*min wavelength range*/400,
		/*max wavelength range*/1000, /*back focal length*/ 16.81, /*Coating*/"VIS-NIR (400-1000nm)", /*material*/mGlasses.getNBK7_S1(), /*power (P-V)*/1.5,
		/*min centering*/0.0, /*max centering*/1.0, /*center thickness*/3.48, /*edge thickness*/1.42, /*free aperture CA*/11.0,				//centering <1
		/*design wavelength*/ 587.6, /*numerical Aperture*/0.33, /*price*/ 38.00, /*wavelength to trace through optical system*/550.0);

	EO33391.buildLensTwoSurfaces_DCX(/*lens catalog*/ "EO", /*catalog number*/ 33391, /*durchmesser*/12.00, /*max tolerance diameter*/0.0, /*min tolerance diameter*/-0.025, /*focal length*/ 24.0,
		/*max surface quality*/40.0, /*min surface quality*/20.0, /*curvature (P-V)*/4.0, /*tolerance center thickness*/0.1,
		/*radius first surface*/24.108, /*radius second surface*/-24.108, /*tolerance focal lenght*/1.0, /*min wavelength range*/400,
		/*max wavelength range*/1000, /*back focal length*/ 22.65, /*Coating*/"VIS-NIR (400-1000nm)", /*material*/mGlasses.getNBK7_S1(), /*power (P-V)*/1.5,
		/*min centering*/0.0, /*max centering*/1.0, /*center thickness*/4.0, /*edge thickness*/2.48, /*free aperture CA*/11.0,				//centering <1
		/*design wavelength*/ 587.6, /*numerical Aperture*/0.25, /*price*/ 38.0, /*wavelength to trace through optical system*/550.0);

	EO45875.buildLensTwoSurfaces_DCX(/*lens catalog*/ "EO", /*catalog number*/ 45875, /*durchmesser*/12.0, /*max tolerance diameter*/0.0, /*min tolerance diameter*/-0.025, /*focal length*/ 30.0,
		/*max surface quality*/40.0, /*min surface quality*/20.0, /*curvature (P-V)*/4.0, /*tolerance center thickness*/0.1,
		/*radius first surface*/30.36, /*radius second surface*/-30.36, /*tolerance focal lenght*/1.0, /*min wavelength range*/400,
		/*max wavelength range*/1000, /*back focal length*/ 28.75, /*Coating*/"VIS-NIR (400-1000nm)", /*material*/mGlasses.getNBK7_S1(), /*power (P-V)*/1.5,
		/*min centering*/0.0, /*max centering*/1.0, /*center thickness*/3.7, /*edge thickness*/2.5, /*free aperture CA*/11.0,				//centering <1
		/*design wavelength*/ 587.6, /*numerical Aperture*/0.2, /*price*/ 38.00, /*wavelength to trace through optical system*/550.0);

	EO45876.buildLensTwoSurfaces_DCX(/*lens catalog*/ "EO", /*catalog number*/ 45876, /*durchmesser*/12.0, /*max tolerance diameter*/0.0, /*min tolerance diameter*/-0.025, /*focal length*/ 36.0,
		/*max surface quality*/40.0, /*min surface quality*/20.0, /*curvature (P-V)*/4.0, /*tolerance center thickness*/0.1,
		/*radius first surface*/36.65, /*radius second surface*/-36.65, /*tolerance focal lenght*/1.0, /*min wavelength range*/400,
		/*max wavelength range*/1000, /*back focal length*/ 34.9, /*Coating*/"VIS-NIR (400-1000nm)", /*material*/mGlasses.getNBK7_S1(), /*power (P-V)*/1.5,
		/*min centering*/0.0, /*max centering*/1.0, /*center thickness*/3.3, /*edge thickness*/2.31, /*free aperture CA*/11.0,				//centering <1
		/*design wavelength*/ 587.6, /*numerical Aperture*/0.17, /*price*/ 38.00, /*wavelength to trace through optical system*/550.0);

	EO45877.buildLensTwoSurfaces_DCX(/*lens catalog*/ "EO", /*catalog number*/ 45877, /*durchmesser*/12.0, /*max tolerance diameter*/0.0, /*min tolerance diameter*/-0.025, /*focal length*/ 48.0,
		/*max surface quality*/40.0, /*min surface quality*/20.0, /*curvature (P-V)*/4.0, /*tolerance center thickness*/0.1,
		/*radius first surface*/49.14, /*radius second surface*/-49.14, /*tolerance focal lenght*/1.0, /*min wavelength range*/400,
		/*max wavelength range*/1000, /*back focal length*/ 47.09, /*Coating*/"VIS-NIR (400-1000nm)", /*material*/mGlasses.getNBK7_S1(), /*power (P-V)*/1.5,
		/*min centering*/0.0, /*max centering*/1.0, /*center thickness*/2.74, /*edge thickness*/2.0, /*free aperture CA*/11.0,				//centering <1
		/*design wavelength*/ 587.6, /*numerical Aperture*/0.13, /*price*/ 38.00, /*wavelength to trace through optical system*/550.0);

	EO45878.buildLensTwoSurfaces_DCX(/*lens catalog*/ "EO", /*catalog number*/ 45878, /*durchmesser*/12.0, /*max tolerance diameter*/0.0, /*min tolerance diameter*/-0.025, /*focal length*/ 72.0,
		/*max surface quality*/40.0, /*min surface quality*/20.0, /*curvature (P-V)*/4.0, /*tolerance center thickness*/0.1,
		/*radius first surface*/73.97, /*radius second surface*/-73.97, /*tolerance focal lenght*/1.0, /*min wavelength range*/400,
		/*max wavelength range*/1000, /*back focal length*/ 71.07, /*Coating*/"VIS-NIR (400-1000nm)", /*material*/mGlasses.getNBK7_S1(), /*power (P-V)*/1.5,
		/*min centering*/0.0, /*max centering*/1.0, /*center thickness*/2.8, /*edge thickness*/2.31, /*free aperture CA*/11.0,				//centering <1
		/*design wavelength*/ 587.6, /*numerical Aperture*/0.08, /*price*/ 38.00, /*wavelength to trace through optical system*/550.0);

	EO45879.buildLensTwoSurfaces_DCX(/*lens catalog*/ "EO", /*catalog number*/ 45879, /*durchmesser*/15.0, /*max tolerance diameter*/0.0, /*min tolerance diameter*/-0.025, /*focal length*/ 15.0,
		/*max surface quality*/40.0, /*min surface quality*/20.0, /*curvature (P-V)*/4.0, /*tolerance center thickness*/0.1,
		/*radius first surface*/22.51, /*radius second surface*/-22.51, /*tolerance focal lenght*/1.0, /*min wavelength range*/400,
		/*max wavelength range*/1000, /*back focal length*/ 13.68, /*Coating*/"VIS-NIR (400-1000nm)", /*material*/mGlasses.getNSF11_S1(), /*power (P-V)*/1.5,
		/*min centering*/0.0, /*max centering*/1.0, /*center thickness*/4.5, /*edge thickness*/1.93, /*free aperture CA*/14.0,				//centering <1
		/*design wavelength*/ 587.6, /*numerical Aperture*/0.5, /*price*/ 40.50, /*wavelength to trace through optical system*/550.0);

	EO63671.buildLensTwoSurfaces_DCX(/*lens catalog*/ "EO", /*catalog number*/ 63671, /*durchmesser*/15.0, /*max tolerance diameter*/0.0, /*min tolerance diameter*/-0.025, /*focal length*/ 20.0,
		/*max surface quality*/40.0, /*min surface quality*/20.0, /*curvature (P-V)*/4.0, /*tolerance center thickness*/0.1,
		/*radius first surface*/30.60, /*radius second surface*/-30.60, /*tolerance focal lenght*/1.0, /*min wavelength range*/400,
		/*max wavelength range*/1000, /*back focal length*/ 18.99, /*Coating*/"VIS-NIR (400-1000nm)", /*material*/mGlasses.getNSF11_S1(), /*power (P-V)*/1.5,
		/*min centering*/0.0, /*max centering*/1.0, /*center thickness*/3.5, /*edge thickness*/1.63, /*free aperture CA*/14.0,				//centering <1
		/*design wavelength*/ 587.6, /*numerical Aperture*/0.38, /*price*/ 40.50, /*wavelength to trace through optical system*/550.0);

	EO45880.buildLensTwoSurfaces_DCX(/*lens catalog*/ "EO", /*catalog number*/ 45880, /*durchmesser*/15.0, /*max tolerance diameter*/0.0, /*min tolerance diameter*/-0.025, /*focal length*/ 22.5,
		/*max surface quality*/40.0, /*min surface quality*/20.0, /*curvature (P-V)*/4.0, /*tolerance center thickness*/0.1,
		/*radius first surface*/34.36, /*radius second surface*/-34.36, /*tolerance focal lenght*/1.0, /*min wavelength range*/400,
		/*max wavelength range*/1000, /*back focal length*/ 21.29, /*Coating*/"VIS-NIR (400-1000nm)", /*material*/mGlasses.getNSF11_S1(), /*power (P-V)*/1.5,
		/*min centering*/0.0, /*max centering*/1.0, /*center thickness*/4.2, /*edge thickness*/2.54, /*free aperture CA*/14.0,				//centering <1
		/*design wavelength*/ 587.6, /*numerical Aperture*/0.33, /*price*/ 40.50, /*wavelength to trace through optical system*/550.0);

	EO63672.buildLensTwoSurfaces_DCX(/*lens catalog*/ "EO", /*catalog number*/ 63672, /*durchmesser*/15.0, /*max tolerance diameter*/0.0, /*min tolerance diameter*/-0.025, /*focal length*/ 25.0,
		/*max surface quality*/40.0, /*min surface quality*/20.0, /*curvature (P-V)*/4.0, /*tolerance center thickness*/0.1,
		/*radius first surface*/25.23, /*radius second surface*/-25.23, /*tolerance focal lenght*/1.0, /*min wavelength range*/400,
		/*max wavelength range*/1000, /*back focal length*/ 23.82, /*Coating*/"VIS-NIR (400-1000nm)", /*material*/mGlasses.getNBK7_S1(), /*power (P-V)*/1.5,
		/*min centering*/0.0, /*max centering*/1.0, /*center thickness*/3.5, /*edge thickness*/1.22, /*free aperture CA*/14.0,				//centering <1
		/*design wavelength*/ 587.6, /*numerical Aperture*/0.3, /*price*/ 40.50, /*wavelength to trace through optical system*/550.0);

	EO45881.buildLensTwoSurfaces_DCX(/*lens catalog*/ "EO", /*catalog number*/ 45881, /*durchmesser*/15.0, /*max tolerance diameter*/0.0, /*min tolerance diameter*/-0.025, /*focal length*/ 30.0,
		/*max surface quality*/40.0, /*min surface quality*/20.0, /*curvature (P-V)*/4.0, /*tolerance center thickness*/0.1,
		/*radius first surface*/30.50, /*radius second surface*/-30.50, /*tolerance focal lenght*/1.0, /*min wavelength range*/400,
		/*max wavelength range*/1000, /*back focal legnth*/ 28.82, /*Coating*/"VIS-NIR (400-1000nm)", /*material*/mGlasses.getNBK7_S1(), /*power (P-V)*/1.5,
		/*min centering*/0.0, /*max centering*/1.0, /*center thickness*/4.0, /*edge thickness*/2.13, /*free aperture CA*/14.0,				//centering <1
		/*design wavelength*/ 587.6, /*numerical Aperture*/0.25, /*price*/ 40.50, /*wavelength to trace through optical system*/550.0);

	EO63673.buildLensTwoSurfaces_DCX(/*lens catalog*/ "EO", /*catalog number*/ 63673, /*durchmesser*/15.0, /*max tolerance diameter*/0.0, /*min tolerance diameter*/-0.025, /*focal length*/ 45.0,
		/*max surface quality*/40.0, /*min surface quality*/20.0, /*curvature (P-V)*/4.0, /*tolerance center thickness*/0.1,
		/*radius first surface*/45.99, /*radius second surface*/-45.99, /*tolerance focal lenght*/1.0, /*min wavelength range*/400,
		/*max wavelength range*/1000, /*back focal length*/ 44.0, /*Coating*/"VIS-NIR (400-1000nm)", /*material*/mGlasses.getNBK7_S1(), /*power (P-V)*/1.5,
		/*min centering*/0.0, /*max centering*/1.0, /*center thickness*/3.0, /*edge thickness*/1.77, /*free aperture CA*/14.00,				//centering <1
		/*design wavelength*/ 587.6, /*numerical Aperture*/0.17, /*price*/ 40.50, /*wavelength to trace through optical system*/550.0);

	EO45882.buildLensTwoSurfaces_DCX(/*lens catalog*/ "EO", /*catalog number*/ 45882, /*durchmesser*/15.0, /*max tolerance diameter*/0.0, /*min tolerance diameter*/-0.025, /*focal length*/ 50.0,
		/*max surface quality*/40.0, /*min surface quality*/20.0, /*curvature (P-V)*/4.0, /*tolerance center thickness*/0.1,
		/*radius first surface*/51.16, /*radius second surface*/-51.16, /*tolerance focal lenght*/1.0, /*min wavelength range*/400,
		/*max wavelength range*/1000, /*back focal length*/ 49.0, /*Coating*/"VIS-NIR (400-1000nm)", /*material*/mGlasses.getNBK7_S1(), /*power (P-V)*/1.5,
		/*min centering*/0.0, /*max centering*/1.0, /*center thickness*/3.0, /*edge thickness*/1.9, /*free aperture CA*/14.0,				//centering <1
		/*design wavelength*/ 587.6, /*numerical Aperture*/0.15, /*price*/ 40.50, /*wavelength to trace through optical system*/550.0);

	EO63674.buildLensTwoSurfaces_DCX(/*lens catalog*/ "EO", /*catalog number*/ 63674, /*durchmesser*/15.0, /*max tolerance diameter*/0.0, /*min tolerance diameter*/-0.025, /*focal length*/ 60.0,
		/*max surface quality*/40.0, /*min surface quality*/20.0, /*curvature (P-V)*/4.0, /*tolerance center thickness*/0.1,
		/*radius first surface*/61.50, /*radius second surface*/-61.50, /*tolerance focal lenght*/1.0, /*min wavelength range*/400,
		/*max wavelength range*/1000, /*back focal length*/ 59.0, /*Coating*/"VIS-NIR (400-1000nm)", /*material*/mGlasses.getNBK7_S1(), /*power (P-V)*/1.5,
		/*min centering*/0.0, /*max centering*/1.0, /*center thickness*/3.0, /*edge thickness*/2.08, /*free aperture CA*/14.0,				//centering <1
		/*design wavelength*/ 587.6, /*numerical Aperture*/0.13, /*price*/ 40.50, /*wavelength to trace through optical system*/550.0);

	EO63675.buildLensTwoSurfaces_DCX(/*lens catalog*/ "EO", /*catalog number*/ 63675, /*durchmesser*/18.0, /*max tolerance diameter*/0.0, /*min tolerance diameter*/-0.025, /*focal length*/ 180.0,
		/*max surface quality*/40.0, /*min surface quality*/20.0, /*curvature (P-V)*/4.0, /*tolerance center thickness*/0.1,
		/*radius first surface*/27.22, /*radius second surface*/-27.22, /*tolerance focal lenght*/1.0, /*min wavelength range*/400,
		/*max wavelength range*/1000, /*back focal length*/ 16.69, /*Coating*/"VIS-NIR (400-1000nm)", /*material*/mGlasses.getNSF11_S1(), /*power (P-V)*/1.5,
		/*min centering*/0.0, /*max centering*/1.0, /*center thickness*/4.5, /*edge thickness*/1.44, /*free aperture CA*/17.0,				//centering <1
		/*design wavelength*/ 587.6, /*numerical Aperture*/0.5, /*price*/ 40.50, /*wavelength to trace through optical system*/550.0);

	EO45883.buildLensTwoSurfaces_DCX(/*lens catalog*/ "EO", /*catalog number*/ 45883, /*durchmesser*/18.0, /*max tolerance diameter*/0.0, /*min tolerance diameter*/-0.025, /*focal length*/ 27.0,
		/*max surface quality*/40.0, /*min surface quality*/20.0, /*curvature (P-V)*/4.0, /*tolerance center thickness*/0.1,
		/*radius first surface*/27.08, /*radius second surface*/-27.08, /*tolerance focal lenght*/1.0, /*min wavelength range*/400,
		/*max wavelength range*/1000, /*back focal length*/ 25.25, /*Coating*/"VIS-NIR (400-1000nm)", /*material*/mGlasses.getNBK7_S1(), /*power (P-V)*/1.5,
		/*min centering*/0.0, /*max centering*/1.0, /*center thickness*/5.5, /*edge thickness*/2.42, /*free aperture CA*/17.0,				//centering <1
		/*design wavelength*/ 587.6, /*numerical Aperture*/0.33, /*price*/ 40.50, /*wavelength to trace through optical system*/550.0);

	EO45884.buildLensTwoSurfaces_DCX(/*lens catalog*/ "EO", /*catalog number*/ 45884, /*durchmesser*/18.0, /*max tolerance diameter*/0.0, /*min tolerance diameter*/-0.025, /*focal length*/ 36.0,
		/*max surface quality*/40.0, /*min surface quality*/20.0, /*curvature (P-V)*/4.0, /*tolerance center thickness*/0.1,
		/*radius first surface*/36.60, /*radius second surface*/-36.60, /*tolerance focal lenght*/1.0, /*min wavelength range*/400,
		/*max wavelength range*/1000, /*back focal length*/ 34.59, /*Coating*/"VIS-NIR (400-1000nm)", /*material*/mGlasses.getNBK7_S1(), /*power (P-V)*/1.5,
		/*min centering*/0.0, /*max centering*/1.0, /*center thickness*/4.8, /*edge thickness*/2.55, /*free aperture CA*/17.0,				//centering <1
		/*design wavelength*/ 587.6, /*numerical Aperture*/0.25, /*price*/40.50, /*wavelength to trace through optical system*/550.0);

	EO63678.buildLensTwoSurfaces_DCX(/*lens catalog*/ "EO", /*catalog number*/ 63678, /*durchmesser*/20.0, /*max tolerance diameter*/0.0, /*min tolerance diameter*/-0.025, /*focal length*/ 20.0,
		/*max surface quality*/40.0, /*min surface quality*/20.0, /*curvature (P-V)*/4.0, /*tolerance center thickness*/0.1,
		/*radius first surface*/30.25, /*radius second surface*/-30.25, /*tolerance focal lenght*/1.0, /*min wavelength range*/400,
		/*max wavelength range*/1000, /*back focal length*/ 18.55, /*Coating*/"VIS-NIR (400-1000nm)", /*material*/mGlasses.getNSF11_S1(), /*power (P-V)*/1.5,
		/*min centering*/0.0, /*max centering*/1.0, /*center thickness*/5.0, /*edge thickness*/1.6, /*free aperture CA*/19.0,				//centering <1
		/*design wavelength*/ 587.6, /*numerical Aperture*/0.50, /*price*/ 40.50, /*wavelength to trace through optical system*/550.0);

	EO63679.buildLensTwoSurfaces_DCX(/*lens catalog*/ "EO", /*catalog number*/ 63679, /*durchmesser*/20.0, /*max tolerance diameter*/0.0, /*min tolerance diameter*/-0.025, /*focal length*/ 25.0,
		/*max surface quality*/40.0, /*min surface quality*/20.0, /*curvature (P-V)*/4.0, /*tolerance center thickness*/0.1,
		/*radius first surface*/38.34, /*radius second surface*/-38.34, /*tolerance focal lenght*/1.0, /*min wavelength range*/400,
		/*max wavelength range*/1000, /*back focal length*/ 23.86, /*Coating*/"VIS-NIR (400-1000nm)", /*material*/mGlasses.getNSF11_S1(), /*power (P-V)*/1.5,
		/*min centering*/0.0, /*max centering*/1.0, /*center thickness*/4.0, /*edge thickness*/1.35, /*free aperture CA*/19.0,				//centering <1
		/*design wavelength*/ 587.6, /*numerical Aperture*/0.4, /*price*/ 40.50, /*wavelength to trace through optical system*/550.0);

	EO45885.buildLensTwoSurfaces_DCX(/*lens catalog*/ "EO", /*catalog number*/ 45885, /*durchmesser*/20.0, /*max tolerance diameter*/0.0, /*min tolerance diameter*/-0.025, /*focal length*/ 30.0,
		/*max surface quality*/40.0, /*min surface quality*/20.0, /*curvature (P-V)*/4.0, /*tolerance center thickness*/0.1,
		/*radius first surface*/30.08, /*radius second surface*/-30.08, /*tolerance focal lenght*/1.0, /*min wavelength range*/400,
		/*max wavelength range*/1000, /*back focal length*/ 28.2, /*Coating*/"VIS-NIR (400-1000nm)", /*material*/mGlasses.getNBK7_S1(), /*power (P-V)*/1.5,
		/*min centering*/0.0, /*max centering*/1.0, /*center thickness*/5.3, /*edge thickness*/1.88, /*free aperture CA*/19.0,				//centering <1
		/*design wavelength*/ 587.6, /*numerical Aperture*/0.33, /*price*/ 40.50, /*wavelength to trace through optical system*/550.0);

	EO45886.buildLensTwoSurfaces_DCX(/*lens catalog*/ "EO", /*catalog number*/ 45886, /*durchmesser*/20.0, /*max tolerance diameter*/0.0, /*min tolerance diameter*/-0.025, /*focal length*/ 40.0,
		/*max surface quality*/40.0, /*min surface quality*/20.0, /*curvature (P-V)*/4.0, /*tolerance center thickness*/0.1,
		/*radius first surface*/40.67, /*radius second surface*/-40.67, /*tolerance focal lenght*/1.0, /*min wavelength range*/400,
		/*max wavelength range*/1000, /*back focal length*/ 38.44, /*Coating*/"VIS-NIR (400-1000nm)", /*material*/mGlasses.getNBK7_S1(), /*power (P-V)*/1.5,
		/*min centering*/0.0, /*max centering*/1.0, /*center thickness*/5.3, /*edge thickness*/2.8, /*free aperture CA*/19.0,				//centering <1
		/*design wavelength*/ 587.6, /*numerical Aperture*/0.25, /*price*/ 40.50, /*wavelength to trace through optical system*/550.0);


	EO63680.buildLensTwoSurfaces_DCX(/*lens catalog*/ "EO", /*catalog number*/ 63680, /*durchmesser*/20.0, /*max tolerance diameter*/0.0, /*min tolerance diameter*/-0.025, /*focal length*/ 50.0,
		/*max surface quality*/40.0, /*min surface quality*/20.0, /*curvature (P-V)*/4.0, /*tolerance center thickness*/0.1,
		/*radius first surface*/51.08, /*radius second surface*/-51.08, /*tolerance focal lenght*/1.0, /*min wavelength range*/400,
		/*max wavelength range*/1000, /*back focal length*/ 48.84, /*Coating*/"VIS-NIR (400-1000nm)", /*material*/mGlasses.getNBK7_S1(), /*power (P-V)*/1.5,
		/*min centering*/0.0, /*max centering*/1.0, /*center thickness*/3.5, /*edge thickness*/1.52, /*free aperture CA*/19.0,				//centering <1
		/*design wavelength*/ 587.6, /*numerical Aperture*/0.2, /*price*/ 40.50, /*wavelength to trace through optical system*/550.0);


	EO63681.buildLensTwoSurfaces_DCX(/*lens catalog*/ "EO", /*catalog number*/ 63681, /*durchmesser*/20.0, /*max tolerance diameter*/0.0, /*min tolerance diameter*/-0.025, /*focal length*/ 60.0,
		/*max surface quality*/40.0, /*min surface quality*/20.0, /*curvature (P-V)*/4.0, /*tolerance center thickness*/0.1,
		/*radius first surface*/61.33, /*radius second surface*/-61.33, /*tolerance focal lenght*/1.0, /*min wavelength range*/400,
		/*max wavelength range*/1000, /*back focal length*/ 58.67, /*Coating*/"VIS-NIR (400-1000nm)", /*material*/mGlasses.getNBK7_S1(), /*power (P-V)*/1.5,
		/*min centering*/0.0, /*max centering*/1.0, /*center thickness*/4.0, /*edge thickness*/2.36, /*free aperture CA*/19.0,				//centering <1
		/*design wavelength*/ 587.6, /*numerical Aperture*/0.17, /*price*/ 40.50, /*wavelength to trace through optical system*/550.0);

	EO63682.buildLensTwoSurfaces_DCX(/*lens catalog*/ "EO", /*catalog number*/ 63682, /*durchmesser*/20.0, /*max tolerance diameter*/0.0, /*min tolerance diameter*/-0.025, /*focal length*/ 80.0,
		/*max surface quality*/40.0, /*min surface quality*/20.0, /*curvature (P-V)*/4.0, /*tolerance center thickness*/0.1,
		/*radius first surface*/82.0, /*radius second surface*/-82.0, /*tolerance focal lenght*/1.0, /*min wavelength range*/400,
		/*max wavelength range*/1000, /*back focal length*/ 78.67, /*Coating*/"VIS-NIR (400-1000nm)", /*material*/mGlasses.getNBK7_S1(), /*power (P-V)*/1.5,
		/*min centering*/0.0, /*max centering*/1.0, /*center thickness*/4.0, /*edge thickness*/2.78, /*free aperture CA*/19.0,				//centering <1
		/*design wavelength*/ 587.6, /*numerical Aperture*/0.13, /*price*/ 40.50, /*wavelength to trace through optical system*/550.0);

	EO45887.buildLensTwoSurfaces_DCX(/*lens catalog*/ "EO", /*catalog number*/ 45887, /*durchmesser*/25.0, /*max tolerance diameter*/0.0, /*min tolerance diameter*/-0.025, /*focal length*/ 25.0,
		/*max surface quality*/40.0, /*min surface quality*/20.0, /*curvature (P-V)*/4.0, /*tolerance center thickness*/0.1,
		/*radius first surface*/31.94, /*radius second surface*/-31.94, /*tolerance focal lenght*/1.0, /*min wavelength range*/400,
		/*max wavelength range*/1000, /*back focal length*/ 22.47, /*Coating*/"VIS-NIR (400-1000nm)", /*material*/mGlasses.getNSF5_S1(), /*power (P-V)*/1.5,
		/*min centering*/0.0, /*max centering*/1.0, /*center thickness*/8.0, /*edge thickness*/2.9, /*free aperture CA*/24.0,				//centering <1
		/*design wavelength*/ 587.6, /*numerical Aperture*/0.5, /*price*/ 44.50, /*wavelength to trace through optical system*/550.0);

	EO63683.buildLensTwoSurfaces_DCX(/*lens catalog*/ "EO", /*catalog number*/ 63683, /*durchmesser*/25.0, /*max tolerance diameter*/0.0, /*min tolerance diameter*/-0.025, /*focal length*/ 30.0,
		/*max surface quality*/40.0, /*min surface quality*/20.0, /*curvature (P-V)*/4.0, /*tolerance center thickness*/0.1,
		/*radius first surface*/39.22, /*radius second surface*/-39.22, /*tolerance focal lenght*/1.0, /*min wavelength range*/400,
		/*max wavelength range*/1000, /*back focal length*/ 28.31, /*Coating*/"VIS-NIR (400-1000nm)", /*material*/mGlasses.getNSF5_S1(), /*power (P-V)*/1.5,
		/*min centering*/0.0, /*max centering*/1.0, /*center thickness*/5.5, /*edge thickness*/1.41, /*free aperture CA*/24.0,				//centering <1
		/*design wavelength*/ 587.6, /*numerical Aperture*/0.42, /*price*/ 44.50, /*wavelength to trace through optical system*/550.0);

	EO45888.buildLensTwoSurfaces_DCX(/*lens catalog*/ "EO", /*catalog number*/ 45888, /*durchmesser*/25.0, /*max tolerance diameter*/0.0, /*min tolerance diameter*/-0.025, /*focal length*/ 35.0,
		/*max surface quality*/40.0, /*min surface quality*/20.0, /*curvature (P-V)*/4.0, /*tolerance center thickness*/0.1,
		/*radius first surface*/35.09, /*radius second surface*/-35.09, /*tolerance focal lenght*/1.0, /*min wavelength range*/400,
		/*max wavelength range*/1000, /*back focal length*/ 32.81, /*Coating*/"VIS-NIR (400-1000nm)", /*material*/mGlasses.getNBK7_S1(), /*power (P-V)*/1.5,
		/*min centering*/0.0, /*max centering*/1.0, /*center thickness*/6.6, /*edge thickness*/2.0, /*free aperture CA*/24.0,				//centering <1
		/*design wavelength*/ 587.6, /*numerical Aperture*/0.36, /*price*/ 44.50, /*wavelength to trace through optical system*/550.0);

	EO45889.buildLensTwoSurfaces_DCX(/*lens catalog*/ "EO", /*catalog number*/ 45889, /*durchmesser*/25.0, /*max tolerance diameter*/0.0, /*min tolerance diameter*/-0.025, /*focal length*/ 40.0,
		/*max surface quality*/40.0, /*min surface quality*/20.0, /*curvature (P-V)*/4.0, /*tolerance center thickness*/0.1,
		/*radius first surface*/40.42, /*radius second surface*/-40.42, /*tolerance focal lenght*/1.0, /*min wavelength range*/400,
		/*max wavelength range*/1000, /*back focal length*/ 38.21, /*Coating*/"VIS-NIR (400-1000nm)", /*material*/mGlasses.getNBK7_S1(), /*power (P-V)*/1.5,
		/*min centering*/0.0, /*max centering*/1.0, /*center thickness*/5.3, /*edge thickness*/1.34, /*free aperture CA*/ 24.0,				//centering <1
		/*design wavelength*/ 587.6, /*numerical Aperture*/0.31, /*price*/ 44.50, /*wavelength to trace through optical system*/550.0);

	EO45890.buildLensTwoSurfaces_DCX(/*lens catalog*/ "EO", /*catalog number*/ 45890, /*durchmesser*/25.0, /*max tolerance diameter*/0.0, /*min tolerance diameter*/-0.025, /*focal length*/ 50.0,
		/*max surface quality*/40.0, /*min surface quality*/20.0, /*curvature (P-V)*/4.0, /*tolerance center thickness*/0.1,
		/*radius first surface*/50.80, /*radius second surface*/-50.80, /*tolerance focal lenght*/1.0, /*min wavelength range*/400,
		/*max wavelength range*/1000, /*back focal length*/ 48.29, /*Coating*/"VIS-NIR (400-1000nm)", /*material*/mGlasses.getNBK7_S1(), /*power (P-V)*/1.5,
		/*min centering*/0.0, /*max centering*/1.0, /*center thickness*/5.0, /*edge thickness*/1.88, /*free aperture CA*/24.0,				//centering <1
		/*design wavelength*/ 587.6, /*numerical Aperture*/0.25, /*price*/ 44.50, /*wavelength to trace through optical system*/550.0);

	EO45891.buildLensTwoSurfaces_DCX(/*lens catalog*/ "EO", /*catalog number*/ 45891, /*durchmesser*/25.0, /*max tolerance diameter*/0.0, /*min tolerance diameter*/-0.025, /*focal length*/ 75.0,
		/*max surface quality*/40.0, /*min surface quality*/20.0, /*curvature (P-V)*/4.0, /*tolerance center thickness*/0.1,
		/*radius first surface*/76.66, /*radius second surface*/-76.66, /*tolerance focal lenght*/1.0, /*min wavelength range*/400,
		/*max wavelength range*/1000, /*back focal length*/ 73.84, /*Coating*/"VIS-NIR (400-1000nm)", /*material*/mGlasses.getNBK7_S1(), /*power (P-V)*/1.5,
		/*min centering*/0.0, /*max centering*/1.0, /*center thickness*/3.5, /*edge thickness*/1.45, /*free aperture CA*/24.0,				//centering <1
		/*design wavelength*/ 587.6, /*numerical Aperture*/0.17, /*price*/ 44.50, /*wavelength to trace through optical system*/550.0);

	EO45892.buildLensTwoSurfaces_DCX(/*lens catalog*/ "EO", /*catalog number*/ 45892, /*durchmesser*/25.0, /*max tolerance diameter*/0.0, /*min tolerance diameter*/-0.025, /*focal length*/ 100.0,
		/*max surface quality*/40.0, /*min surface quality*/20.0, /*curvature (P-V)*/4.0, /*tolerance center thickness*/0.1,
		/*radius first surface*/103.0, /*radius second surface*/-103.0, /*tolerance focal lenght*/1.0, /*min wavelength range*/400,
		/*max wavelength range*/1000, /*back focal length*/ 98.95, /*Coating*/"VIS-NIR (400-1000nm)", /*material*/mGlasses.getNBK7_S1(), /*power (P-V)*/1.5,
		/*min centering*/0.0, /*max centering*/1.0, /*center thickness*/4.0, /*edge thickness*/2.48, /*free aperture CA*/24.0,				//centering <1
		/*design wavelength*/ 587.6, /*numerical Aperture*/0.13, /*price*/ 44.50, /*wavelength to trace through optical system*/550.0);

	EO45893.buildLensTwoSurfaces_DCX(/*lens catalog*/ "EO", /*catalog number*/ 45893, /*durchmesser*/25.0, /*max tolerance diameter*/0.0, /*min tolerance diameter*/-0.025, /*focal length*/ 125.0,
		/*max surface quality*/40.0, /*min surface quality*/20.0, /*curvature (P-V)*/4.0, /*tolerance center thickness*/0.1,
		/*radius first surface*/128.65, /*radius second surface*/-128.65, /*tolerance focal lenght*/1.0, /*min wavelength range*/400,
		/*max wavelength range*/1000, /*back focal length*/ 123.84, /*Coating*/"VIS-NIR (400-1000nm)", /*material*/mGlasses.getNBK7_S1(), /*power (P-V)*/1.5,
		/*min centering*/0.0, /*max centering*/1.0, /*center thickness*/3.5, /*edge thickness*/2.28, /*free aperture CA*/24.0,				//centering <1
		/*design wavelength*/ 587.6, /*numerical Aperture*/0.1, /*price*/ 44.50, /*wavelength to trace through optical system*/550.0);

	EO45894.buildLensTwoSurfaces_DCX(/*lens catalog*/ "EO", /*catalog number*/ 45894, /*durchmesser*/25.0, /*max tolerance diameter*/0.0, /*min tolerance diameter*/-0.025, /*focal length*/ 150,
		/*max surface quality*/40.0, /*min surface quality*/20.0, /*curvature (P-V)*/4.0, /*tolerance center thickness*/0.1,
		/*radius first surface*/154.52, /*radius second surface*/-154.52, /*tolerance focal lenght*/1.0, /*min wavelength range*/400,
		/*max wavelength range*/1000, /*back focal length*/ 148.88, /*Coating*/"VIS-NIR (400-1000nm)", /*material*/mGlasses.getNBK7_S1(), /*power (P-V)*/1.5,
		/*min centering*/0.0, /*max centering*/1.0, /*center thickness*/3.4, /*edge thickness*/2.39, /*free aperture CA*/24.0,				//centering <1
		/*design wavelength*/ 587.6, /*numerical Aperture*/0.08, /*price*/ 44.50, /*wavelength to trace through optical system*/550.0);

	EO45895.buildLensTwoSurfaces_DCX(/*lens catalog*/ "EO", /*catalog number*/ 45895, /*durchmesser*/25.0, /*max tolerance diameter*/0.0, /*min tolerance diameter*/-0.025, /*focal length*/ 175.0,
		/*max surface quality*/40.0, /*min surface quality*/20.0, /*curvature (P-V)*/4.0, /*tolerance center thickness*/0.1,
		/*radius first surface*/180.4, /*radius second surface*/-180.4, /*tolerance focal lenght*/1.0, /*min wavelength range*/400,
		/*max wavelength range*/1000, /*back focal length*/ 173.94, /*Coating*/"VIS-NIR (400-1000nm)", /*material*/mGlasses.getNBK7_S1(), /*power (P-V)*/1.5,
		/*min centering*/0.0, /*max centering*/1.0, /*center thickness*/3.2, /*edge thickness*/2.33, /*free aperture CA*/24.0,				//centering <1
		/*design wavelength*/ 587.6, /*numerical Aperture*/0.07, /*price*/ 44.50, /*wavelength to trace through optical system*/550.0);

	EO33397.buildLensTwoSurfaces_DCX(/*lens catalog*/ "EO", /*catalog number*/ 33397, /*durchmesser*/25.0, /*max tolerance diameter*/0.0, /*min tolerance diameter*/-0.025, /*focal length*/ 200.0,
		/*max surface quality*/40.0, /*min surface quality*/20.0, /*curvature (P-V)*/4.0, /*tolerance center thickness*/0.1,
		/*radius first surface*/205.865, /*radius second surface*/-205.865, /*tolerance focal lenght*/1.0, /*min wavelength range*/400,
		/*max wavelength range*/1000, /*back focal length*/ 198.35, /*Coating*/"VIS-NIR (400-1000nm)", /*material*/mGlasses.getNBK7_S1(), /*power (P-V)*/1.5,
		/*min centering*/0.0, /*max centering*/1.0, /*center thickness*/5.0, /*edge thickness*/4.24, /*free aperture CA*/24.0,				//centering <1
		/*design wavelength*/ 587.6, /*numerical Aperture*/0.06, /*price*/ 44.50, /*wavelength to trace through optical system*/550.0);

	EO63684.buildLensTwoSurfaces_DCX(/*lens catalog*/ "EO", /*catalog number*/ 63684, /*durchmesser*/30.0, /*max tolerance diameter*/0.0, /*min tolerance diameter*/-0.025, /*focal length*/ 30.0,
		/*max surface quality*/40.0, /*min surface quality*/20.0, /*curvature (P-V)*/4.0, /*tolerance center thickness*/0.1,
		/*radius first surface*/45.61, /*radius second surface*/-45.61, /*tolerance focal lenght*/1.0, /*min wavelength range*/400,
		/*max wavelength range*/1000, /*back focal length*/ 28.12, /*Coating*/"VIS-NIR (400-1000nm)", /*material*/mGlasses.getNSF11_S1(), /*power (P-V)*/1.5,
		/*min centering*/0.0, /*max centering*/1.0, /*center thickness*/6.5, /*edge thickness*/1.43, /*free aperture CA*/29.0,				//centering <1
		/*design wavelength*/ 587.6, /*numerical Aperture*/0.50, /*price*/ 50.00, /*wavelength to trace through optical system*/550.0);

	EO45898.buildLensTwoSurfaces_DCX(/*lens catalog*/ "EO", /*catalog number*/ 45898, /*durchmesser*/30.0, /*max tolerance diameter*/0.0, /*min tolerance diameter*/-0.025, /*focal length*/ 50.0,
		/*max surface quality*/40.0, /*min surface quality*/20.0, /*curvature (P-V)*/4.0, /*tolerance center thickness*/0.1,
		/*radius first surface*/50.56, /*radius second surface*/-50.56, /*tolerance focal lenght*/1.0, /*min wavelength range*/400,
		/*max wavelength range*/1000, /*back focal length*/ 47.82, /*Coating*/"VIS-NIR (400-1000nm)", /*material*/mGlasses.getNBK7_S1(), /*power (P-V)*/1.5,
		/*min centering*/0.0, /*max centering*/1.0, /*center thickness*/6.55, /*edge thickness*/2.00, /*free aperture CA*/29.0,				//centering <1
		/*design wavelength*/ 587.6, /*numerical Aperture*/0.3, /*price*/ 50.00, /*wavelength to trace through optical system*/550.0);

	EO63685.buildLensTwoSurfaces_DCX(/*lens catalog*/ "EO", /*catalog number*/ 63685, /*durchmesser*/30.0, /*max tolerance diameter*/0.0, /*min tolerance diameter*/-0.025, /*focal length*/ 60.0,
		/*max surface quality*/40.0, /*min surface quality*/20.0, /*curvature (P-V)*/4.0, /*tolerance center thickness*/0.1,
		/*radius first surface*/61.15, /*radius second surface*/-61.15, /*tolerance focal lenght*/1.0, /*min wavelength range*/400,
		/*max wavelength range*/1000, /*back focal length*/ 58.33, /*Coating*/"VIS-NIR (400-1000nm)", /*material*/mGlasses.getNBK7_S1(), /*power (P-V)*/1.5,
		/*min centering*/0.0, /*max centering*/1.0, /*center thickness*/5.0, /*edge thickness*/1.26, /*free aperture CA*/29.0,				//centering <1
		/*design wavelength*/ 587.6, /*numerical Aperture*/0.25, /*price*/ 50.00, /*wavelength to trace through optical system*/550.0);

	EO45899.buildLensTwoSurfaces_DCX(/*lens catalog*/ "EO", /*catalog number*/ 45899, /*durchmesser*/30.0, /*max tolerance diameter*/0.0, /*min tolerance diameter*/-0.025, /*focal length*/ 75.0,
		/*max surface quality*/40.0, /*min surface quality*/20.0, /*curvature (P-V)*/4.0, /*tolerance center thickness*/0.1,
		/*radius first surface*/76.67, /*radius second surface*/-76.67, /*tolerance focal lenght*/1.0, /*min wavelength range*/400,
		/*max wavelength range*/1000, /*back focal length*/ 73.35, /*Coating*/"VIS-NIR (400-1000nm)", /*material*/mGlasses.getNBK7_S1(), /*power (P-V)*/1.5,
		/*min centering*/0.0, /*max centering*/1.0, /*center thickness*/4.96, /*edge thickness*/2.00, /*free aperture CA*/29.0,				//centering <1
		/*design wavelength*/ 587.6, /*numerical Aperture*/0.20, /*price*/ 50.00, /*wavelength to trace through optical system*/550.0);

	EO63686.buildLensTwoSurfaces_DCX(/*lens catalog*/ "EO", /*catalog number*/ 63686, /*durchmesser*/30.0, /*max tolerance diameter*/0.0, /*min tolerance diameter*/-0.025,/*focal length*/ 100.0,
		/*max surface quality*/40.0, /*min surface quality*/20.0, /*curvature (P-V)*/4.0, /*tolerance center thickness*/0.1,
		/*radius first surface*/102.50, /*radius second surface*/-102.50, /*tolerance focal lenght*/1.0, /*min wavelength range*/400,
		/*max wavelength range*/1000, /*back focal length*/ 98.34, /*Coating*/"VIS-NIR (400-1000nm)", /*material*/mGlasses.getNBK7_S1(), /*power (P-V)*/1.5,
		/*min centering*/0.0, /*max centering*/1.0, /*center thickness*/5.0, /*edge thickness*/2.79, /*free aperture CA*/29.0,				//centering <1
		/*design wavelength*/ 587.6, /*numerical Aperture*/0.15, /*price*/ 50.00, /*wavelength to trace through optical system*/550.0);

	EO63687.buildLensTwoSurfaces_DCX(/*lens catalog*/ "EO", /*catalog number*/ 63687, /*durchmesser*/30.0, /*max tolerance diameter*/0.0, /*min tolerance diameter*/-0.025, /*focal length*/ 120.0,
		/*max surface quality*/40.0, /*min surface quality*/20.0, /*curvature (P-V)*/4.0, /*tolerance center thickness*/0.1,
		/*radius first surface*/123.17, /*radius second surface*/-123.17, /*tolerance focal lenght*/1.0, /*min wavelength range*/400,
		/*max wavelength range*/1000, /*back focal length*/ 118.34, /*Coating*/"VIS-NIR (400-1000nm)", /*material*/mGlasses.getNBK7_S1(), /*power (P-V)*/1.5,
		/*min centering*/0.0, /*max centering*/1.0, /*center thickness*/5.0, /*edge thickness*/3.17, /*free aperture CA*/29.0,				//centering <1
		/*design wavelength*/ 587.6, /*numerical Aperture*/0.13, /*price*/ 50.00, /*wavelength to trace through optical system*/550.0);

	EO63688.buildLensTwoSurfaces_DCX(/*lens catalog*/ "EO", /*catalog number*/ 63688, /*durchmesser*/40.0, /*max tolerance diameter*/0.0, /*min tolerance diameter*/-0.025, /*focal length*/ 40.0,
		/*max surface quality*/40.0, /*min surface quality*/20.0, /*curvature (P-V)*/4.0, /*tolerance center thickness*/0.1,
		/*radius first surface*/60.85, /*radius second surface*/-60.85, /*tolerance focal lenght*/1.0, /*min wavelength range*/400,
		/*max wavelength range*/1000, /*back focal length*/ 37.54, /*Coating*/"VIS-NIR (400-1000nm)", /*material*/mGlasses.getNSF11_S1(), /*power (P-V)*/1.5,
		/*min centering*/0.0, /*max centering*/1.0, /*center thickness*/8.5, /*edge thickness*/1.74, /*free aperture CA*/39.0,				//centering <1
		/*design wavelength*/ 587.6, /*numerical Aperture*/0.5, /*price*/ 61.50, /*wavelength to trace through optical system*/550.0);

	EO45900.buildLensTwoSurfaces_DCX(/*lens catalog*/ "EO", /*catalog number*/ 45900, /*durchmesser*/40.0, /*max tolerance diameter*/0.0, /*min tolerance diameter*/-0.025, /*focal length*/ 60.0,
		/*max surface quality*/40.0, /*min surface quality*/20.0, /*curvature (P-V)*/4.0, /*tolerance center thickness*/0.1,
		/*radius first surface*/60.56, /*radius second surface*/-60.56, /*tolerance focal lenght*/1.0, /*min wavelength range*/400,
		/*max wavelength range*/1000, /*back focal length*/ 57.1, /*Coating*/"VIS-NIR (400-1000nm)", /*material*/mGlasses.getNBK7_S1(), /*power (P-V)*/1.5,
		/*min centering*/0.0, /*max centering*/1.0, /*center thickness*/8.8, /*edge thickness*/2.0, /*free aperture CA*/39.0,				//centering <1
		/*design wavelength*/ 587.6, /*numerical Aperture*/0.33, /*price*/ 61.50, /*wavelength to trace through optical system*/550.0);

	EO33422.buildLensTwoSurfaces_DCX(/*lens catalog*/ "EO", /*catalog number*/ 33422, /*durchmesser*/40.0, /*max tolerance diameter*/0.0, /*min tolerance diameter*/-0.025, /*focal length*/ 80.0,
		/*max surface quality*/40.0, /*min surface quality*/20.0, /*curvature (P-V)*/4.0, /*tolerance center thickness*/0.1,
		/*radius first surface*/81.3, /*radius second surface*/-81.3, /*tolerance focal lenght*/1.0, /*min wavelength range*/400,
		/*max wavelength range*/1000, /*back focal length*/ 77.32, /*Coating*/"VIS-NIR (400-1000nm)", /*material*/mGlasses.getNBK7_S1(), /*power (P-V)*/1.5,
		/*min centering*/0.0, /*max centering*/1.0, /*center thickness*/8.0, /*edge thickness*/3.0, /*free aperture CA*/39.0,				//centering <1
		/*design wavelength*/ 587.6, /*numerical Aperture*/0.25, /*price*/ 61.50, /*wavelength to trace through optical system*/550.0);

	EO33409.buildLensTwoSurfaces_DCX(/*lens catalog*/ "EO", /*catalog number*/ 33409, /*durchmesser*/40.0, /*max tolerance diameter*/0.0, /*min tolerance diameter*/-0.025, /*focal length*/ 100.0,
		/*max surface quality*/40.0, /*min surface quality*/20.0, /*curvature (P-V)*/4.0, /*tolerance center thickness*/0.1,
		/*radius first surface*/101.98, /*radius second surface*/-101.98, /*tolerance focal lenght*/1.0, /*min wavelength range*/400,
		/*max wavelength range*/1000, /*back focal length*/ 97.33, /*Coating*/"VIS-NIR (400-1000nm)", /*material*/mGlasses.getNBK7_S1(), /*power (P-V)*/1.5,
		/*min centering*/0.0, /*max centering*/1.0, /*center thickness*/8.0, /*edge thickness*/4.04, /*free aperture CA*/39.0,				//centering <1
		/*design wavelength*/ 587.6, /*numerical Aperture*/0.20, /*price*/ 61.50, /*wavelength to trace through optical system*/550.0);

	EO63689.buildLensTwoSurfaces_DCX(/*lens catalog*/ "EO", /*catalog number*/ 63689, /*durchmesser*/40.0, /*max tolerance diameter*/0.0, /*min tolerance diameter*/-0.025, /*focal length*/ 120.0,
		/*max surface quality*/40.0, /*min surface quality*/20.0, /*curvature (P-V)*/4.0, /*tolerance center thickness*/0.1,
		/*radius first surface*/122.83, /*radius second surface*/-122.83, /*tolerance focal lenght*/1.0, /*min wavelength range*/400,
		/*max wavelength range*/1000, /*back focal length*/ 117.67, /*Coating*/"VIS-NIR (400-1000nm)", /*material*/mGlasses.getNBK7_S1(), /*power (P-V)*/1.5,
		/*min centering*/0.0, /*max centering*/1.0, /*center thickness*/7.0, /*edge thickness*/3.72, /*free aperture CA*/39.0,				//centering <1
		/*design wavelength*/ 587.6, /*numerical Aperture*/0.17, /*price*/ 61.50, /*wavelength to trace through optical system*/550.0);

	EO33416.buildLensTwoSurfaces_DCX(/*lens catalog*/ "EO", /*catalog number*/ 33416, /*durchmesser*/40.0, /*max tolerance diameter*/0.0, /*min tolerance diameter*/-0.025, /*focal length*/ 200.0,
		/*max surface quality*/40.0, /*min surface quality*/20.0, /*curvature (P-V)*/4.0, /*tolerance center thickness*/0.1,
		/*radius first surface*/205.35, /*radius second surface*/-205.35, /*tolerance focal lenght*/1.0, /*min wavelength range*/400,
		/*max wavelength range*/1000, /*back focal length*/ 197.35, /*Coating*/"VIS-NIR (400-1000nm)", /*material*/mGlasses.getNBK7_S1(), /*power (P-V)*/1.5,
		/*min centering*/0.0, /*max centering*/1.0, /*center thickness*/8.0, /*edge thickness*/6.05, /*free aperture CA*/39.0,				//centering <1
		/*design wavelength*/ 587.6, /*numerical Aperture*/0.10, /*price*/ 61.50, /*wavelength to trace through optical system*/550.0);

	EO45905.buildLensTwoSurfaces_DCX(/*lens catalog*/ "EO", /*catalog number*/ 45905, /*durchmesser*/50.0, /*max tolerance diameter*/0.0, /*min tolerance diameter*/-0.025,/*focal length*/ 50,
		/*max surface quality*/40.0, /*min surface quality*/20.0, /*curvature (P-V)*/4.0, /*tolerance center thickness*/0.1,
		/*radius first surface*/74.78, /*radius second surface*/-74.78, /*tolerance focal lenght*/1.0, /*min wavelength range*/400,
		/*max wavelength range*/1000, /*back focal length*/ 45.3, /*Coating*/"VIS-NIR (400-1000nm)", /*material*/mGlasses.getNSF11_S1(), /*power (P-V)*/1.5,
		/*min centering*/0.0, /*max centering*/1.0, /*center thickness*/16.0, /*edge thickness*/7.39, /*free aperture CA*/49.0,				//centering <1
		/*design wavelength*/ 587.6, /*numerical Aperture*/0.5, /*price*/ 61.50, /*wavelength to trace through optical system*/550.0);

	EO45906.buildLensTwoSurfaces_DCX(/*lens catalog*/ "EO", /*catalog number*/ 45906, /*durchmesser*/50.0, /*max tolerance diameter*/0.0, /*min tolerance diameter*/-0.025, /*focal length*/ 100.0,
		/*max surface quality*/40.0, /*min surface quality*/20.0, /*curvature (P-V)*/4.0, /*tolerance center thickness*/0.1,
		/*radius first surface*/101.63, /*radius second surface*/-101.63, /*tolerance focal lenght*/1.0, /*min wavelength range*/400,
		/*max wavelength range*/1000, /*back focal length*/ 96.65, /*Coating*/"VIS-NIR (400-1000nm)", /*material*/mGlasses.getNBK7_S1(), /*power (P-V)*/1.5,
		/*min centering*/0.0, /*max centering*/1.0, /*center thickness*/10.0, /*edge thickness*/3.76, /*free aperture CA*/49.0,				//centering <1
		/*design wavelength*/ 587.6, /*numerical Aperture*/0.25, /*price*/ 64.50, /*wavelength to trace through optical system*/550.0);

	EO45907.buildLensTwoSurfaces_DCX(/*lens catalog*/ "EO", /*catalog number*/ 45907, /*durchmesser*/50.0, /*max tolerance diameter*/0.0, /*min tolerance diameter*/-0.025, /*focal length*/ 150.0,
		/*max surface quality*/40.0, /*min surface quality*/20.0, /*curvature (P-V)*/4.0, /*tolerance center thickness*/0.1,
		/*radius first surface*/153.49, /*radius second surface*/-153.49, /*tolerance focal lenght*/1.0, /*min wavelength range*/400,
		/*max wavelength range*/1000, /*back focal length*/ 147.0, /*Coating*/"VIS-NIR (400-1000nm)", /*material*/mGlasses.getNBK7_S1(), /*power (P-V)*/1.5,
		/*min centering*/0.0, /*max centering*/1.0, /*center thickness*/9.0, /*edge thickness*/4.9, /*free aperture CA*/49.0,				//centering <1
		/*design wavelength*/ 587.6, /*numerical Aperture*/0.17, /*price*/ 64.50, /*wavelength to trace through optical system*/550.0);

	EO45908.buildLensTwoSurfaces_DCX(/*lens catalog*/ "EO", /*catalog number*/ 45908, /*durchmesser*/50.0, /*max tolerance diameter*/0.0, /*min tolerance diameter*/-0.025, /*focal length*/200.0,
		/*max surface quality*/40.0, /*min surface quality*/20.0, /*curvature (P-V)*/4.0, /*tolerance center thickness*/0.1,
		/*radius first surface*/205.86, /*radius second surface*/-205.86, /*tolerance focal lenght*/1.0, /*min wavelength range*/400,
		/*max wavelength range*/1000, /*back focal length*/ 198.33, /*Coating*/"VIS-NIR (400-1000nm)", /*material*/mGlasses.getNBK7_S1(), /*power (P-V)*/1.5,
		/*min centering*/0.0, /*max centering*/1.0, /*center thickness*/5.05, /*edge thickness*/2.0, /*free aperture CA*/49.0,				//centering <1
		/*design wavelength*/ 587.6, /*numerical Aperture*/0.13, /*price*/ 64.50, /*wavelength to trace through optical system*/550.0);

	EO45909.buildLensTwoSurfaces_DCX(/*lens catalog*/ "EO", /*catalog number*/ 45909, /*durchmesser*/50.0, /*max tolerance diameter*/0.0, /*min tolerance diameter*/-0.025, /*focal length*/ 250.0,
		/*max surface quality*/40.0, /*min surface quality*/20.0, /*curvature (P-V)*/4.0, /*tolerance center thickness*/0.1,
		/*radius first surface*/257.57, /*radius second surface*/-257.57, /*tolerance focal lenght*/1.0, /*min wavelength range*/400,
		/*max wavelength range*/1000, /*back focal length*/ 248.37, /*Coating*/"VIS-NIR (400-1000nm)", /*material*/mGlasses.getNBK7_S1(), /*power (P-V)*/1.5,
		/*min centering*/0.0, /*max centering*/1.0, /*center thickness*/4.93, /*edge thickness*/2.50, /*free aperture CA*/49.0,				//centering <1
		/*design wavelength*/ 587.6, /*numerical Aperture*/0.10, /*price*/ 64.50, /*wavelength to trace through optical system*/550.0);


}

void EdmundOpticsLensCatalog::loadLensCatalogEO_achroamticLensesMgF() //https://www.edmundoptics.de/f/mgfsub2sub-coated-achromatic-lenses/12006/
{
	//EO65564.buildLensThreeSurfaces(/*lens catalog*/ "EO", /*catalog number*/ 65564,  /*diameter*/1.00, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.025,/* focallength*/1.50,
//	/* tolerance focal length*/ 2.0, /*back focal length*/0.92, /*design wavelength*/ 587.6, /*free aperture CA*/0.5,/*min centering*/ 30.0,
//	/*max centering*/45.0,  /*first thickness*/0.50,	/*second thickness*/0.50, /*tolerance center thickness*/ 0.1, /*radius first surface*/0.80,
//	/*radius second surface*/ -0.80, /*radius third surface*/ -4.50, /*edge thickness*0.80/, /*material first*/ glasses.getSPHM52_S1(),					//Glas 1 nicht im Glaskatalog
//	/*material second*/ glasses.getNLASF9_S1(),/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*stop*/1.5, /*numerical aperture*/0.33,
//	/*coating*/ "MgF2",	/*coating specification*/ 1.75,	/*power wavelength*/ 632.8, /*power PV*/ 1.5,/*curvature wavelength*/ 632.8,
//	/*curvature PV*/ 4, /*bevel*/ "Protective bevel as needed",	/*type*/ "achromatic lens",	/*min wavelength*/ 400.0, /*max wavelength*/ 700.0,
//	/*price*/200.00, /*wavelength to trace*/ 550.0);
//
//EO65565.buildLensThreeSurfaces(/*lens catalog*/ "EO", /*catalog number*/ 65565, /*diameter*/1.00, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.025,/* focallength*/2.00,
//	/* tolerance focal length*/ 2.0, /*back focal length*/1.45, /*design wavelength*/ 587.6, /*free aperture CA*/0.5,/*min centering*/ 30.0,
//	/*max centering*/45.0,  /*first thickness*/0.50,	/*second thickness*/0.50, /*tolerance center thickness*/ 0.1, /*radius first surface*/1.11,
//	/*radius second surface*/ -1.11, /*radius third surface*/ -5.27, /*edge thickness*/0.86, /*material first*/ glasses.getSPHM52_S1(),					//Glas 1 nicht im Glaskatalog
//	/*material second*/ glasses.getNLASF9_S1(),/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*stop*/2.00, /*numerical aperture*/0.25,
//	/*coating*/ "MgF2",	/*coating specification*/ 1.75,	/*power wavelength*/ 632.8, /*power PV*/ 1.5,/*curvature wavelength*/ 632.8,
//	/*curvature PV*/ 4, /*bevel*/ "Protective bevel as needed",	/*type*/ "achromatic lens",	/*min wavelength*/ 400.0, /*max wavelength*/ 700.0,
//	/*price*/200.00, /*wavelength to trace*/ 550.0);
//
//EO65566.buildLensThreeSurfaces(/*lens catalog*/ "EO", /*catalog number*/ 65566, /*diameter*/1.00, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.025,/* focallength*/3.00,
//	/* tolerance focal length*/ 2.0, /*back focal length*/2.48, /*design wavelength*/ 587.6, /*free aperture CA*/0.50,/*min centering*/ 30.0,
//	/*max centering*/45.0,  /*first thickness*/0.50,	/*second thickness*/0.50, /*tolerance center thickness*/ 0.1, /*radius first surface*/1.75,
//	/*radius second surface*/ -1.75, /*radius third surface*/ -7.13, /*edge thickness*/0.91, /*material first*/ glasses.getSPHM52_S1(),					//Glas 1 nicht im Glaskatalog
//	/*material second*/ glasses.getNLASF9_S1(),/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*stop*/3.00, /*numerical aperture*/0.17,
//	/*coating*/ "MgF2",	/*coating specification*/ 1.75,	/*power wavelength*/ 632.8, /*power PV*/ 1.5,/*curvature wavelength*/ 632.8,
//	/*curvature PV*/ 4, /*bevel*/ "Protective bevel as needed",	/*type*/ "achromatic lens",	/*min wavelength*/ 400.0, /*max wavelength*/ 700.0,
//	/*price*/200.00, /*wavelength to trace*/ 550.0);
//
//EO65567.buildLensThreeSurfaces(/*lens catalog*/ "EO", /*catalog number*/ 65567, /*diameter*/2.00, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.025,/* focallength*/3.00,
//	/* tolerance focal length*/ 2.0, /*back focal length*/1.89, /*design wavelength*/ 587.6, /*free aperture CA*/1.6,/*min centering*/ 30.0,
//	/*max centering*/45.0,  /*first thickness*/1.00,	/*second thickness*/1.00, /*tolerance center thickness*/ 0.1, /*radius first surface*/1.68,
//	/*radius second surface*/ -1.68, /*radius third surface*/ -7.39, /*edge thickness*/1.60, /*material first*/ glasses.getSPHM52_S1(),					//Glas 1 nicht im Glaskatalog
//	/*material second*/ glasses.getNLASF9_S1(),/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*stop*/1.5, /*numerical aperture*/0.33,
//	/*coating*/ "MgF2",	/*coating specification*/ 1.75,	/*power wavelength*/ 632.8, /*power PV*/ 1.5,/*curvature wavelength*/ 632.8,
//	/*curvature PV*/ 4, /*bevel*/ "Protective bevel as needed",	/*type*/ "achromatic lens",	/*min wavelength*/ 400.0, /*max wavelength*/ 700.0,
//	/*price*/200.00, /*wavelength to trace*/ 550.0);
//
//EO65568.buildLensThreeSurfaces(/*lens catalog*/ "EO", /*catalog number*/ 65568, /*diameter*/2.00, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.025,/* focallength*/4.00,
//	/* tolerance focal length*/ 2.0, /*back focal length*/2.92, /*design wavelength*/ 587.6, /*free aperture CA*/1.6,/*min centering*/ 30.0,
//	/*max centering*/45.0,  /*first thickness*/1.00,	/*second thickness*/1.00, /*tolerance center thickness*/ 0.1, /*radius first surface*/2.26,
//	/*radius second surface*/ -2.26, /*radius third surface*/ -10.00, /*edge thickness*/1.72, /*material first*/ glasses.getSPHM52_S1(),				//Glas 1 nicht im Glaskatalog
//	/*material second*/ glasses.getNLASF9_S1(),/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*stop*/2.00, /*numerical aperture*/0.25,
//	/*coating*/ "MgF2",	/*coating specification*/ 1.75,	/*power wavelength*/ 632.8, /*power PV*/ 1.5,/*curvature wavelength*/ 632.8,
//	/*curvature PV*/ 4, /*bevel*/ "Protective bevel as needed",	/*type*/ "achromatic lens",	/*min wavelength*/ 400.0, /*max wavelength*/ 700.0,
//	/*price*/200.00, /*wavelength to trace*/ 550.0);
//
//EO65569.buildLensThreeSurfaces(/*lens catalog*/ "EO", /*catalog number*/ 65569, /*diameter*/2.00, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.025,/* focallength*/6.00,
//	/* tolerance focal length*/ 2.0, /*back focal length*/4.96, /*design wavelength*/ 587.6, /*free aperture CA*/1.6,/*min centering*/ 0.0,
//	/*max centering*/3.0,  /*first thickness*/1.00,	/*second thickness*/1.00, /*tolerance center thickness*/ 0.1, /*radius first surface*/3.50,
//	/*radius second surface*/ -3.50, /*radius third surface*/ -14.26, /*edge thickness*/1.82, /*material first*/ glasses.getSPHM52_S1(),				//Glas 1 nicht im Glaskatalog
//	/*material second*/ glasses.getNLASF9_S1(),/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*stop*/3.00, /*numerical aperture*/0.17,
//	/*coating*/ "MgF2",	/*coating specification*/ 1.75,	/*power wavelength*/ 632.8, /*power PV*/ 1.5,/*curvature wavelength*/ 632.8,
//	/*curvature PV*/ 4, /*bevel*/ "Protective bevel as needed",	/*type*/ "achromatic lens",	/*min wavelength*/ 400.0, /*max wavelength*/ 700.0,
//	/*price*/200.00, /*wavelength to trace*/ 550.0);
//
//EO83338.buildLensThreeSurfaces(/*lens catalog*/ "EO", /*catalog number*/ 83338, /*diameter*/2.00, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.025,/* focallength*/9.00,
//	/* tolerance focal length*/ 2.0, /*back focal length*/8.00, /*design wavelength*/ 587.6, /*free aperture CA*/1.6,/*min centering*/ 0.0,
//	/*max centering*/3.0,  /*first thickness*/1.00,	/*second thickness*/1.00, /*tolerance center thickness*/ 0.1, /*radius first surface*/5.38,
//	/*radius second surface*/ -5.38, /*radius third surface*/ -20.79, /*edge thickness*/1.88, /*material first*/ glasses.getSPHM52_S1(),				//Glas 1 nicht im Glaskatalog
//	/*material second*/ glasses.getNLASF9_S1(),/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*stop*/4.5, /*numerical aperture*/0.11,
//	/*coating*/ "MgF2",	/*coating specification*/ 1.75,	/*power wavelength*/ 632.8, /*power PV*/ 1.5,/*curvature wavelength*/ 632.8,
//	/*curvature PV*/ 4, /*bevel*/ "Protective bevel as needed",	/*type*/ "achromatic lens",	/*min wavelength*/ 400.0, /*max wavelength*/ 700.0,
//	/*price*/200.00, /*wavelength to trace*/ 550.0);
//
//EO83339.buildLensThreeSurfaces(/*lens catalog*/ "EO", /*catalog number*/ 83339, /*diameter*/2.00, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.025,/* focallength*/12.00,
//	/* tolerance focal length*/ 2.0, /*back focal length*/11.00, /*design wavelength*/ 587.6, /*free aperture CA*/1.6,/*min centering*/ 0.0,
//	/*max centering*/1.0,  /*first thickness*/1.00,	/*second thickness*/1.00, /*tolerance center thickness*/ 0.1, /*radius first surface*/7.20,
//	/*radius second surface*/ -7.20, /*radius third surface*/ -27.80, /*edge thickness*/1.91, /*material first*/ glasses.getSPHM52_S1(),				//Glas 1 nicht im Glaskatalog
//	/*material second*/ glasses.getNLASF9_S1(),/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*stop*/6.00, /*numerical aperture*/0.08,
//	/*coating*/ "MgF2",	/*coating specification*/ 1.75,	/*power wavelength*/ 632.8, /*power PV*/ 1.5,/*curvature wavelength*/ 632.8,
//	/*curvature PV*/ 4, /*bevel*/ "Protective bevel as needed",	/*type*/ "achromatic lens",	/*min wavelength*/ 400.0, /*max wavelength*/ 700.0,
//	/*price*/200.00, /*wavelength to trace*/ 550.0);

	EO45262.buildLensThreeSurfaces(/*lens catalog*/ "EO", /*catalog number*/ 45262, /*diameter*/ 3.0, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.025,/* focallength*/ 12.0,
		/* tolerance focal length*/ 2.0, /*back focal length*/ 10.77, /*design wavelength*/ 587.6, /*free aperture CA*/ 2.7,	/*min centering*/ 0.0,
		/*max centering*/ 1,  /*first thickness*/ 1.68,	/*second thickness*/ 1.0, /*tolerance center thickness*/ 0.2, /*radius first surface*/ 7.39,
		/*radius second surface*/ -5.15, /*radisu third surface*/ -14.62, /*edge thickness*/ 2.45, /*material first*/ mGlasses.getNBK7_S1(),
		/*material second*/ mGlasses.getNSF5_S1(),/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*stop*/ 4.0, /*numerical aperture*/ 0.13,
		/*coating*/ "MgF2",	/*coating specification*/ 1.75,	/*power wavelength*/ 632.8, /*power PV*/ 1.5,/*curvature wavelength*/ 632.8,
		/*curvature PV*/ 4, /*bevel*/ "Protective bevel as needed",	/*type*/ "achromatic lens",	/*min wavelength*/ 400.0, /*max wavelength*/ 700.0,
		/*price*/ 90.0, /*wavelength to trace*/ 550.0);

	EO47721.buildLensThreeSurfaces(/*lens catalog*/ "EO", /*catalog number*/ 47721, /*diameter*/ 3.0, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.025,/* focallength*/ 4.5,
		/* tolerance focal length*/ 2.0, /*back focal length*/ 2.99, /*design wavelength*/ 587.6, /*free aperture CA*/ 2.7,	/*min centering*/ 30.0,
		/*max centering*/ 45.0,  /*first thickness*/ 2.0,	/*second thickness*/ 1.0, /*tolerance center thickness*/ 0.2, /*radius first surface*/ 3.16,
		/*radius second surface*/ -2.23, /*radius third surface*/ -7.88, /*edge thickness*/ 2.48, /*material first*/ mGlasses.getNLAK22_S1(),
		/*material second*/ mGlasses.getNSF6_S1(),/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*stop*/ 1.5, /*numerical aperture*/ 0.33,
		/*coating*/ "MgF2",	/*coating specification*/ 1.75,	/*power wavelength*/ 632.8, /*power PV*/ 1.5,/*curvature wavelength*/ 632.8,
		/*curvature PV*/ 4, /*bevel*/ "Protective bevel as needed",	/*type*/ "achromatic lens",	/*min wavelength*/ 400.0, /*max wavelength*/ 700.0,
		/*price*/ 90.0, /*wavelength to trace*/ 550.0);

	EO45089.buildLensThreeSurfaces(/*lens catalog*/ "EO", /*catalog number*/ 45089, /*diameter*/ 3.0, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.025,/* focallength*/ 6.0,
		/* tolerance focal length*/ 2.0, /*back focal length*/ 4.33, /*design wavelength*/ 587.6, /*free aperture CA*/ 2.7,	/*min centering*/ 0.0,
		/*max centering*/ 3.0,  /*first thickness*/ 1.97,	/*second thickness*/ 1.03, /*tolerance center thickness*/ 0.2, /*radius first surface*/ 4.13,
		/*radius second surface*/ -2.36, /*radius third surface*/ -21.70, /*edge thickness*/ 2.67, /*material first*/ mGlasses.getNBAF10_S1(),
		/*material second*/ mGlasses.getNSF10_S1(),/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*stop*/ 2.0, /*numerical aperture*/ 0.25,
		/*coating*/ "MgF2",	/*coating specification*/ 1.75,	/*power wavelength*/ 632.8, /*power PV*/ 1.5,/*curvature wavelength*/ 632.8,
		/*curvature PV*/ 4, /*bevel*/ "Protective bevel as needed",	/*type*/ "achromatic lens",	/*min wavelength*/ 400.0, /*max wavelength*/ 700.0,
		/*price*/ 90.0, /*wavelength to trace*/ 550.0);

	EO45090.buildLensThreeSurfaces(/*lens catalog*/ "EO", /*catalog number*/ 45090, /*diameter*/ 3.0, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.025,/* focallength*/ 9.0,
		/* tolerance focal length*/ 2.0, /*back focal length*/ 7.79, /*design wavelength*/ 587.6, /*free aperture CA*/ 2.7,	/*min centering*/ 0.0,
		/*max centering*/ 30.0,  /*first thickness*/ 1.47,	/*second thickness*/ 1.03, /*tolerance center thickness*/ 0.2, /*radius first surface*/ 5.26,
		/*radius second surface*/ -3.98, /*radius third surface*/ -12.05, /*edge thickness*/ 2.19, /*material first*/ mGlasses.getNBK7_S1(),
		/*material second*/ mGlasses.getNSF5_S1(),/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*stop*/ 3.0, /*numerical aperture*/ 0.17,
		/*coating*/ "MgF2",	/*coating specification*/ 1.75,	/*power wavelength*/ 632.8, /*power PV*/ 1.5,/*curvature wavelength*/ 632.8,
		/*curvature PV*/ 4, /*bevel*/ "Protective bevel as needed",	/*type*/ "achromatic lens",	/*min wavelength*/ 400.0, /*max wavelength*/ 700.0,
		/*price*/ 90.00, /*wavelength to trace*/ 550.0);

	EO63690.buildLensThreeSurfaces(/*lens catalog*/ "EO", /*catalog number*/ 63690, /*diameter*/ 4.0, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.025,/* focallength*/ 6.0,
		/* tolerance focal length*/ 2.0, /*back focal length*/ 3.92, /*design wavelength*/ 587.6, /*free aperture CA*/ 3.6,	/*min centering*/ 0.0,
		/*max centering*/ 3.0,  /*first thickness*/ 2.8,	/*second thickness*/ 1.0, /*tolerance center thickness*/ 0.2, /*radius first surface*/4.24,
		/*radius second surface*/ -2.60, /*radius third surface*/ -18.90, /*edge thickness*/ 3.19, /*material first*/ mGlasses.getNBAF10_S1(),
		/*material second*/ mGlasses.getNSF10_S1(),/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*stop*/ 1.5, /*numerical aperture*/ 0.33,
		/*coating*/ "MgF2",	/*coating specification*/ 1.75,	/*power wavelength*/ 632.8, /*power PV*/ 1.5,/*curvature wavelength*/ 632.8,
		/*curvature PV*/ 4, /*bevel*/ "Protective bevel as needed",	/*type*/ "achromatic lens",	/*min wavelength*/ 400.0, /*max wavelength*/ 700.0,
		/*price*/ 79.00, /*wavelength to trace*/ 550.0);

	EO63691.buildLensThreeSurfaces(/*lens catalog*/ "EO", /*catalog number*/ 63691, /*diameter*/ 4.0, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.025,/* focallength*/ 10.0,
		/* tolerance focal length*/ 2.0, /*back focal length*/ 8.4, /*design wavelength*/ 587.6, /*free aperture CA*/ 3.6,	/*min centering*/ 0.0,
		/*max centering*/ 3.0,  /*first thickness*/ 2.0,	/*second thickness*/ 1.0, /*tolerance center thickness*/ 0.2, /*radius first surface*/ 7.12,
		/*radius second surface*/ -4.22, /*radius third surface*/ -33.66, /*edge thickness*/ 2.65, /*material first*/ mGlasses.getNBAF10_S1(),
		/*material second*/ mGlasses.getNSF10_S1(),/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*stop*/ 2.5, /*numerical aperture*/ 0.20,
		/*coating*/ "MgF2",	/*coating specification*/ 1.75,	/*power wavelength*/ 632.8, /*power PV*/ 1.5,/*curvature wavelength*/ 632.8,
		/*curvature PV*/ 4, /*bevel*/ "Protective bevel as needed",	/*type*/ "achromatic lens",	/*min wavelength*/ 400.0, /*max wavelength*/ 700.0,
		/*price*/ 79.00, /*wavelength to trace*/ 550.0);

	EO63692.buildLensThreeSurfaces(/*lens catalog*/ "EO", /*catalog number*/ 63692, /*diameter*/ 4.0, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.025,/* focallength*/12.0,
		/* tolerance focal length*/ 2.0, /*back focal length*/10.70, /*design wavelength*/ 587.6, /*free aperture CA*/3.6,	/*min centering*/ 0.0,
		/*max centering*/1.0,  /*first thickness*/1.80,	/*second thickness*/1.0, /*tolerance center thickness*/ 0.2, /*radius first surface*/ 7.35,
		/*radius second surface*/ -5.09, /*radius third surface*/ -14.60, /*edge thickness*/2.39, /*material first*/ mGlasses.getNBK7_S1(),
		/*material second*/ mGlasses.getNSF5_S1(),/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*stop*/3.0, /*numerical aperture*/0.17,
		/*coating*/ "MgF2",	/*coating specification*/ 1.75,	/*power wavelength*/ 632.8, /*power PV*/ 1.5,/*curvature wavelength*/ 632.8,
		/*curvature PV*/ 4, /*bevel*/ "Protective bevel as needed",	/*type*/ "achromatic lens",	/*min wavelength*/ 400.0, /*max wavelength*/ 700.0,
		/*price*/79.00, /*wavelength to trace*/ 550.0);

	EO45205.buildLensThreeSurfaces(/*lens catalog*/ "EO", /*catalog number*/ 45205, /*diameter*/ 4.0, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.025,/* focallength*/8.0,
		/* tolerance focal length*/ 2.0, /*back focal length*/6.69, /*design wavelength*/ 587.6, /*free aperture CA*/3.6,	/*min centering*/ 0.0,
		/*max centering*/3.0,  /*first thickness*/1.5,	/*second thickness*/1.03, /*tolerance center thickness*/ 0.2, /*radius first surface*/ 5.76,
		/*radius second surface*/ -3.49, /*radius third surface*/ -26.05, /*edge thickness*/2.09, /*material first*/ mGlasses.getNBAF10_S1(),
		/*material second*/ mGlasses.getNSF10_S1(),/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*stop*/2.0, /*numerical aperture*/0.25,
		/*coating*/ "MgF2",	/*coating specification*/ 1.75,	/*power wavelength*/ 632.8, /*power PV*/ 1.5,/*curvature wavelength*/ 632.8,
		/*curvature PV*/ 4, /*bevel*/ "Protective bevel as needed",	/*type*/ "achromatic lens",	/*min wavelength*/ 400.0, /*max wavelength*/ 700.0,
		/*price*/79.00, /*wavelength to trace*/ 550.0);

	EO45206.buildLensThreeSurfaces(/*lens catalog*/ "EO", /*catalog number*/ 45206, /*diameter*/ 5.0, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.025,/* focallength*/10.0,
		/* tolerance focal length*/ 2.0, /*back focal length*/8.56, /*design wavelength*/ 587.6, /*free aperture CA*/4.5,	/*min centering*/ 0.0,
		/*max centering*/3.0,  /*first thickness*/1.73,	/*second thickness*/1.03, /*tolerance center thickness*/ 0.2, /*radius first surface*/ 7.17,
		/*radius second surface*/ -4.39, /*radius third surface*/ -33.96, /*edge thickness*/2.22, /*material first*/ mGlasses.getNBAF10_S1(),
		/*material second*/ mGlasses.getNSF10_S1(),/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*stop*/2.0, /*numerical aperture*/0.25,
		/*coating*/ "MgF2",	/*coating specification*/ 1.75,	/*power wavelength*/ 632.8, /*power PV*/ 1.5,/*curvature wavelength*/ 632.8,
		/*curvature PV*/ 4, /*bevel*/ "Protective bevel as needed",	/*type*/ "achromatic lens",	/*min wavelength*/ 400.0, /*max wavelength*/ 700.0,
		/*price*/59.00, /*wavelength to trace*/ 550.0);

	EO49923.buildLensThreeSurfaces(/*lens catalog*/ "EO", /*catalog number*/ 49923, /*diameter*/ 5.0, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.025,/* focallength*/12.50,
		/* tolerance focal length*/ 2.0, /*back focal length*/10.89, /*design wavelength*/ 587.6, /*free aperture CA*/4.5,	/*min centering*/ 0.0,
		/*max centering*/1.0,  /*first thickness*/2.3,	/*second thickness*/1.0, /*tolerance center thickness*/ 0.2, /*radius first surface*/ 8.57,
		/*radius second surface*/ -6.22, /*radius third surface*/ -21.36, /*edge thickness*/2.78, /*material first*/ mGlasses.getNSSK8_S1(),
		/*material second*/ mGlasses.getNSF56_S1(),/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*stop*/2.5, /*numerical aperture*/0.20,
		/*coating*/ "MgF2",	/*coating specification*/ 1.75,	/*power wavelength*/ 632.8, /*power PV*/ 1.5,/*curvature wavelength*/ 632.8,
		/*curvature PV*/ 4, /*bevel*/ "Protective bevel as needed",	/*type*/ "achromatic lens",	/*min wavelength*/ 400.0, /*max wavelength*/ 700.0,
		/*price*/59.00, /*wavelength to trace*/ 550.0);

	EO45207.buildLensThreeSurfaces(/*lens catalog*/ "EO", /*catalog number*/ 45207, /*diameter*/ 5.0, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.025,/* focallength*/15.0,
		/* tolerance focal length*/ 2.0, /*back focal length*/13.64, /*design wavelength*/ 587.6, /*free aperture CA*/4.5,	/*min centering*/ 0.0,
		/*max centering*/1.0,  /*first thickness*/1.55,	/*second thickness*/1.03, /*tolerance center thickness*/ 0.2, /*radius first surface*/ 10.67,
		/*radius second surface*/ -6.46, /*radius third surface*/ -53.57, /*edge thickness*/2.22, /*material first*/ mGlasses.getNBAF10_S1(),
		/*material second*/ mGlasses.getNSF10_S1(),/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*stop*/3.0, /*numerical aperture*/0.17,
		/*coating*/ "MgF2",	/*coating specification*/ 1.75,	/*power wavelength*/ 632.8, /*power PV*/ 1.5,/*curvature wavelength*/ 632.8,
		/*curvature PV*/ 4, /*bevel*/ "Protective bevel as needed",	/*type*/ "achromatic lens",	/*min wavelength*/ 400.0, /*max wavelength*/ 700.0,
		/*price*/59.00, /*wavelength to trace*/ 550.0);

	EO45408.buildLensThreeSurfaces(/*lens catalog*/ "EO", /*catalog number*/ 45408, /*diameter*/ 5.0, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.025,/* focallength*/20.0,
		/* tolerance focal length*/ 2.0, /*back focal length*/18.60, /*design wavelength*/ 587.6, /*free aperture CA*/4.5,	/*min centering*/ 0.0,
		/*max centering*/1.0,  /*first thickness*/1.61,	/*second thickness*/1.03, /*tolerance center thickness*/ 0.2, /*radius first surface*/ 14.11,
		/*radius second surface*/ -8.63, /*radius third surface*/ -75.59, /*edge thickness*/2.38, /*material first*/ mGlasses.getNBAF10_S1(),
		/*material second*/ mGlasses.getNSF10_S1(),/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*stop*/4.0, /*numerical aperture*/0.13,
		/*coating*/ "MgF2",	/*coating specification*/ 1.75,	/*power wavelength*/ 632.8, /*power PV*/ 1.5,/*curvature wavelength*/ 632.8,
		/*curvature PV*/ 4, /*bevel*/ "Protective bevel as needed",	/*type*/ "achromatic lens",	/*min wavelength*/ 400.0, /*max wavelength*/ 700.0,
		/*price*/59.00, /*wavelength to trace*/ 550.0);

	EO45407.buildLensThreeSurfaces(/*lens catalog*/ "EO", /*catalog number*/ 45407, /*diameter*/ 5.0, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.025,/* focallength*/7.5,
		/* tolerance focal length*/ 2.0, /*back focal length*/5.01, /*design wavelength*/ 587.6, /*free aperture CA*/4.5,	/*min centering*/ 0.0,
		/*max centering*/3.0,  /*first thickness*/3.72,	/*second thickness*/1.03, /*tolerance center thickness*/ 0.2, /*radius first surface*/ 5.56,
		/*radius second surface*/ -3.09, /*radius third surface*/ -18.25, /*edge thickness*/3.98, /*material first*/ mGlasses.getNBAF10_S1(),
		/*material second*/ mGlasses.getNSF10_S1(),/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*stop*/1.5, /*numerical aperture*/0.33,
		/*coating*/ "MgF2",	/*coating specification*/ 1.75,	/*power wavelength*/ 632.8, /*power PV*/ 1.5,/*curvature wavelength*/ 632.8,
		/*curvature PV*/ 4, /*bevel*/ "Protective bevel as needed",	/*type*/ "achromatic lens",	/*min wavelength*/ 400.0, /*max wavelength*/ 700.0,
		/*price*/59.00, /*wavelength to trace*/ 550.0);

	EO49924.buildLensThreeSurfaces(/*lens catalog*/ "EO", /*catalog number*/ 49924, /*diameter*/ 6.25, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.025,/* focallength*/7.5,
		/* tolerance focal length*/ 2.0, /*back focal length*/4.45, /*design wavelength*/ 587.6, /*free aperture CA*/5.625,	/*min centering*/ 0.0,
		/*max centering*/3.0,  /*first thickness*/5.0,	/*second thickness*/1.0, /*tolerance center thickness*/ 0.2, /*radius first surface*/ 5.60,
		/*radius second surface*/ -3.71, /*radius third surface*/ -11.34, /*edge thickness*/4.61, /*material first*/ mGlasses.getNBAF10_S1(),
		/*material second*/ mGlasses.getNSF57_S1(),/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*stop*/1.2, /*numerical aperture*/0.42,
		/*coating*/ "MgF2",	/*coating specification*/ 1.75,	/*power wavelength*/ 632.8, /*power PV*/ 1.5,/*curvature wavelength*/ 632.8,
		/*curvature PV*/ 4, /*bevel*/ "Protective bevel as needed",	/*type*/ "achromatic lens",	/*min wavelength*/ 400.0, /*max wavelength*/ 700.0,
		/*price*/53.0, /*wavelength to trace*/ 550.0);

	EO45208.buildLensThreeSurfaces(/*lens catalog*/ "EO", /*catalog number*/ 45208, /*diameter*/6.25, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.025,/* focallength*/10.0,
		/* tolerance focal length*/ 2.0, /*back focal length*/7.83, /*design wavelength*/ 587.6, /*free aperture CA*/5.625,	/*min centering*/ 0.0,
		/*max centering*/3.0,  /*first thickness*/3.06,	/*second thickness*/1.03, /*tolerance center thickness*/ 0.2, /*radius first surface*/ 6.98,
		/*radius second surface*/ -4.35, /*radius third surface*/ -41.01, /*edge thickness*/3.23, /*material first*/ mGlasses.getNBAF10_S1(),
		/*material second*/ mGlasses.getNSF10_S1(),/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*stop*/1.6, /*numerical aperture*/0.31,
		/*coating*/ "MgF2",	/*coating specification*/ 1.75,	/*power wavelength*/ 632.8, /*power PV*/ 1.5,/*curvature wavelength*/ 632.8,
		/*curvature PV*/ 4, /*bevel*/ "Protective bevel as needed",	/*type*/ "achromatic lens",	/*min wavelength*/ 400.0, /*max wavelength*/ 700.0,
		/*price*/53.00, /*wavelength to trace*/ 550.0);

	EO32299.buildLensThreeSurfaces(/*lens catalog*/ "EO", /*catalog number*/ 32299, /*diameter*/ 6.25, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.025,/* focallength*/10.36,
		/* tolerance focal length*/ 2.0, /*back focal length*/10.36, /*design wavelength*/ 587.6, /*free aperture CA*/5.625,/*min centering*/ 0.0,
		/*max centering*/1.0,  /*first thickness*/3.00,	/*second thickness*/0.80, /*tolerance center thickness*/ 0.2, /*radius first surface*/ 8.63,
		/*radius second surface*/ -5.29, /*radius third surface*/ -51.17, /*edge thickness*/3.12, /*material first*/ mGlasses.getNBAF10_S1(),
		/*material second*/ mGlasses.getNSF10_S1(),/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*stop*/2.00, /*numerical aperture*/0.25,
		/*coating*/ "MgF2",	/*coating specification*/ 1.75,	/*power wavelength*/ 632.8, /*power PV*/ 1.5,/*curvature wavelength*/ 632.8,
		/*curvature PV*/ 4, /*bevel*/ "Protective bevel as needed",	/*type*/ "achromatic lens",	/*min wavelength*/ 400.0, /*max wavelength*/ 700.0,
		/*price*/53.00, /*wavelength to trace*/ 550.0);

	EO32301.buildLensThreeSurfaces(/*lens catalog*/ "EO", /*catalog number*/ 32301, /*diameter*/ 6.25, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.025,/* focallength*/15.00,
		/* tolerance focal length*/ 2.0, /*back focal length*/12.73, /*design wavelength*/ 587.6, /*free aperture CA*/5.6235, /*min centering*/ 0.0,
		/*max centering*/1.0,  /*first thickness*/2.70,	/*second thickness*/0.60, /*tolerance center thickness*/ 0.2, /*radius first surface*/ 7.95,
		/*radius second surface*/ -7.25, /*radius third surface*/ -277.83, /*edge thickness*/2.64, /*material first*/ mGlasses.getNSSK8_S1(),
		/*material second*/ mGlasses.getNSF10_S1(),/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*stop*/2.4, /*numerical aperture*/ 0.21,
		/*coating*/ "MgF2",	/*coating specification*/ 1.75,	/*power wavelength*/ 632.8, /*power PV*/ 1.5,/*curvature wavelength*/ 632.8,
		/*curvature PV*/ 4, /*bevel*/ "Protective bevel as needed",	/*type*/ "achromatic lens",	/*min wavelength*/ 400.0, /*max wavelength*/ 700.0,
		/*price*/53.00, /*wavelength to trace*/ 550.0);

	EO49925.buildLensThreeSurfaces(/*lens catalog*/ "EO", /*catalog number*/ 49925, /*diameter*/ 6.25, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.025,/* focallength*/17.50,
		/* tolerance focal length*/ 2.0, /*back focal length*/15.46, /*design wavelength*/ 587.6, /*free aperture CA*/5.625,/*min centering*/ 0.0,
		/*max centering*/1.0,  /*first thickness*/2.75,	/*second thickness*/1.00, /*tolerance center thickness*/ 0.2, /*radius first surface*/ 11.125,
		/*radius second surface*/ -9.22, /*radius third surface*/ -38.49, /*edge thickness*/3.18, /*material first*/ mGlasses.getNSSK8_S1(),
		/*material second*/ mGlasses.getNSF56_S1(),/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*stop*/2.8, /*numerical aperture*/0.18,
		/*coating*/ "MgF2",	/*coating specification*/ 1.75,	/*power wavelength*/ 632.8, /*power PV*/ 1.5,/*curvature wavelength*/ 632.8,
		/*curvature PV*/ 4, /*bevel*/ "Protective bevel as needed",	/*type*/ "achromatic lens",	/*min wavelength*/ 400.0, /*max wavelength*/ 700.0,
		/*price*/53.00, /*wavelength to trace*/ 550.0);

	EO32303.buildLensThreeSurfaces(/*lens catalog*/ "EO", /*catalog number*/ 32303, /*diameter*/6.25, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.025,/* focallength*/20.00,
		/* tolerance focal length*/ 2.0, /*back focal length*/18.23, /*design wavelength*/ 587.6, /*free aperture CA*/5.625,/*min centering*/ 0.0,
		/*max centering*/1.0,  /*first thickness*/2.70,	/*second thickness*/0.90, /*tolerance center thickness*/ 0.2, /*radius first surface*/ 12.30,
		/*radius second surface*/ -8.71, /*radius third surface*/ -24.98, /*edge thickness*/3.00, /*material first*/ mGlasses.getNBK7_S1(),
		/*material second*/ mGlasses.getNSF5_S1(),/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*stop*/3.2, /*numerical aperture*/0.16,
		/*coating*/ "MgF2",	/*coating specification*/ 1.75,	/*power wavelength*/ 632.8, /*power PV*/ 1.5,/*curvature wavelength*/ 632.8,
		/*curvature PV*/ 4, /*bevel*/ "Protective bevel as needed",	/*type*/ "achromatic lens",	/*min wavelength*/ 400.0, /*max wavelength*/ 700.0,
		/*price*/53.0, /*wavelength to trace*/ 550.0);

	EO32305.buildLensThreeSurfaces(/*lens catalog*/ "EO", /*catalog number*/ 32305, /*diameter*/6.25, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.025,/* focallength*/25.00,
		/* tolerance focal length*/ 2.0, /*back focal length*/23.45, /*design wavelength*/ 587.6, /*free aperture CA*/5.635,/*min centering*/ 0.0,
		/*max centering*/1.0,  /*first thickness*/2.30,	/*second thickness*/0.90, /*tolerance center thickness*/ 0.2, /*radius first surface*/15.37,
		/*radius second surface*/ -11.16, /*radius third surface*/ -32.17, /*edge thickness*/2.73, /*material first*/ mGlasses.getNBK7_S1(),
		/*material second*/ mGlasses.getNSF5_S1(),/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*stop*/4.00, /*numerical aperture*/0.13,
		/*coating*/ "MgF2",	/*coating specification*/ 1.75,	/*power wavelength*/ 632.8, /*power PV*/ 1.5,/*curvature wavelength*/ 632.8,
		/*curvature PV*/ 4, /*bevel*/ "Protective bevel as needed",	/*type*/ "achromatic lens",	/*min wavelength*/ 400.0, /*max wavelength*/ 700.0,
		/*price*/53.00, /*wavelength to trace*/ 550.0);

	EO45135.buildLensThreeSurfaces(/*lens catalog*/ "EO", /*catalog number*/ 45135, /*diameter*/6.25, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.025,/* focallength*/30.00,
		/* tolerance focal length*/ 2.0, /*back focal length*/28.43, /*design wavelength*/ 587.6, /*free aperture CA*/5.625,/*min centering*/ 0.0,
		/*max centering*/1.0,  /*first thickness*/2.30,	/*second thickness*/0.90, /*tolerance center thickness*/ 0.2, /*radius first surface*/18.11,
		/*radius second surface*/ -13.51, /*radius third surface*/ -39.29, /*edge thickness*/2.80, /*material first*/ mGlasses.getNBK7_S1(),
		/*material second*/ mGlasses.getNSF5_S1(),/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*stop*/4.8, /*numerical aperture*/0.10,
		/*coating*/ "MgF2",	/*coating specification*/ 1.75,	/*power wavelength*/ 632.8, /*power PV*/ 1.5,/*curvature wavelength*/ 632.8,
		/*curvature PV*/ 4, /*bevel*/ "Protective bevel as needed",	/*type*/ "achromatic lens",	/*min wavelength*/ 400.0, /*max wavelength*/ 700.0,
		/*price*/53.00, /*wavelength to trace*/ 550.0);

	EO32307.buildLensThreeSurfaces(/*lens catalog*/ "EO", /*catalog number*/ 32307, /*diameter*/6.25, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.025,/* focallength*/35.00,
		/* tolerance focal length*/ 2.0, /*back focal length*/33.59, /*design wavelength*/ 587.6, /*free aperture CA*/5.625, /*min centering*/ 0.0,
		/*max centering*/1.0,  /*first thickness*/2.30,	/*second thickness*/0.90, /*tolerance center thickness*/ 0.2, /*radius first surface*/23.14,
		/*radius second surface*/ -14.51, /*radius third surface*/ -38.86, /*edge thickness*/2.86, /*material first*/ mGlasses.getNBK7_S1(),
		/*material second*/ mGlasses.getNSF5_S1(),/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*stop*/5.6, /*numerical aperture*/0.09,
		/*coating*/ "MgF2",	/*coating specification*/ 1.75,	/*power wavelength*/ 632.8, /*power PV*/ 1.5,/*curvature wavelength*/ 632.8,
		/*curvature PV*/ 4, /*bevel*/ "Protective bevel as needed",	/*type*/ "achromatic lens",	/*min wavelength*/ 400.0, /*max wavelength*/ 700.0,
		/*price*/53.00, /*wavelength to trace*/ 550.0);

	EO45173.buildLensThreeSurfaces(/*lens catalog*/ "EO", /*catalog number*/ 45173, /*diameter*/6.25, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.025,/* focallength*/ 40.00,
		/* tolerance focal length*/ 2.0, /*back focal length*/38.46, /*design wavelength*/ 587.6, /*free aperture CA*/5.625,/*min centering*/ 0.0,
		/*max centering*/1.0,  /*first thickness*/2.30,	/*second thickness*/1.00, /*tolerance center thickness*/ 0.2, /*radius first surface*/25.05,
		/*radius second surface*/ -17.27, /*radius third surface*/ -49.33, /*edge thickness*/3.01, /*material first*/ mGlasses.getNBK7_S1(),
		/*material second*/ mGlasses.getNSF5_S1(),/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*stop*/6.4, /*numerical aperture*/0.08,
		/*coating*/ "MgF2",	/*coating specification*/ 1.75,	/*power wavelength*/ 632.8, /*power PV*/ 1.5,/*curvature wavelength*/ 632.8,
		/*curvature PV*/ 4, /*bevel*/ "Protective bevel as needed",	/*type*/ "achromatic lens",	/*min wavelength*/ 400.0, /*max wavelength*/ 700.0,
		/*price*/53.00, /*wavelength to trace*/ 550.0);

	EO45263.buildLensThreeSurfaces(/*lens catalog*/ "EO", /*catalog number*/ 45263, /*diameter*/6.25, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.025,/* focallength*/50.00,
		/* tolerance focal length*/ 2.0, /*back focal length*/48.61, /*design wavelength*/ 587.6, /*free aperture CA*/5.625,/*min centering*/ 0.0,
		/*max centering*/1.0,  /*first thickness*/2.00,	/*second thickness*/1.00, /*tolerance center thickness*/ 0.2, /*radius first surface*/30.77,
		/*radius second surface*/ -22.05, /*radius third surface*/ -64.60, /*edge thickness*/2.77, /*material first*/ mGlasses.getNBK7_S1(),
		/*material second*/ mGlasses.getNSF5_S1(),/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*stop*/8.0, /*numerical aperture*/0.06,
		/*coating*/ "MgF2",	/*coating specification*/ 1.75,	/*power wavelength*/ 632.8, /*power PV*/ 1.5,/*curvature wavelength*/ 632.8,
		/*curvature PV*/ 4, /*bevel*/ "Protective bevel as needed",	/*type*/ "achromatic lens",	/*min wavelength*/ 400.0, /*max wavelength*/ 700.0,
		/*price*/53.00, /*wavelength to trace*/ 550.0);

	EO45345.buildLensThreeSurfaces(/*lens catalog*/ "EO", /*catalog number*/ 45345, /*diameter*/6.25, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.025,/* focallength*/60.00,
		/* tolerance focal length*/ 2.0, /*back focal length*/58.46, /*design wavelength*/ 587.6, /*free aperture CA*/5.625,/*min centering*/ 0.0,
		/*max centering*/1.0,  /*first thickness*/2.30,	/*second thickness*/1.0, /*tolerance center thickness*/ 0.2, /*radius first surface*/37.16,
		/*radius second surface*/ -26.28, /*radius third surface*/ -76.48, /*edge thickness*/3.11, /*material first*/ mGlasses.getNBK7_S1(),
		/*material second*/ mGlasses.getNSF5_S1(),/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*stop*/9.6, /*numerical aperture*/0.05,
		/*coating*/ "MgF2",	/*coating specification*/ 1.75,	/*power wavelength*/ 632.8, /*power PV*/ 1.5,/*curvature wavelength*/ 632.8,
		/*curvature PV*/ 4, /*bevel*/ "Protective bevel as needed",	/*type*/ "achromatic lens",	/*min wavelength*/ 400.0, /*max wavelength*/ 700.0,
		/*price*/53.00, /*wavelength to trace*/ 550.0);

	EO65549.buildLensThreeSurfaces(/*lens catalog*/ "EO", /*catalog number*/ 65549, /*diameter*/9.00, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.025,/* focallength*/9.00,
		/* tolerance focal length*/ 2.0, /*back focal length*/4.92, /*design wavelength*/ 587.6, /*free aperture CA*/8.1,/*min centering*/ 0.0,
		/*max centering*/3.0,  /*first thickness*/6.35,	/*second thickness*/1.80, /*tolerance center thickness*/ 0.2, /*radius first surface*/6.87,
		/*radius second surface*/ -5.00, /*radius third surface*/ -14.16, /*edge thickness*/5.73, /*material first*/ mGlasses.getNBASF64_S1(),
		/*material second*/ mGlasses.getNSF66_S1(),/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*stop*/1.00, /*numerical aperture*/0.50,
		/*coating*/ "MgF2",	/*coating specification*/ 1.75,	/*power wavelength*/ 632.8, /*power PV*/ 1.5,/*curvature wavelength*/ 632.8,
		/*curvature PV*/ 4, /*bevel*/ "Protective bevel as needed",	/*type*/ "achromatic lens",	/*min wavelength*/ 400.0, /*max wavelength*/ 700.0,
		/*price*/75.00, /*wavelength to trace*/ 550.0);

	EO45346.buildLensThreeSurfaces(/*lens catalog*/ "EO", /*catalog number*/ 45346, /*diameter*/9.00, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.025,/* focallength*/12.00,
		/* tolerance focal length*/ 2.0, /*back focal length*/8.33, /*design wavelength*/ 587.6, /*free aperture CA*/8.1,/*min centering*/ 0.0,
		/*max centering*/1.0,  /*first thickness*/5.00,	/*second thickness*/2.00, /*tolerance center thickness*/ 0.2, /*radius first surface*/8.37,
		/*radius second surface*/ -7.01, /*radius third surface*/ -26.18, /*edge thickness*/5.30, /*material first*/ mGlasses.getNBAF10_S1(),
		/*material second*/ mGlasses.getNSF57_S1(),/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*stop*/1.33, /*numerical aperture*/0.38,
		/*coating*/ "MgF2",	/*coating specification*/ 1.75,	/*power wavelength*/ 632.8, /*power PV*/ 1.5,/*curvature wavelength*/ 632.8,
		/*curvature PV*/ 4, /*bevel*/ "Protective bevel as needed",	/*type*/ "achromatic lens",	/*min wavelength*/ 400.0, /*max wavelength*/ 700.0,
		/*price*/55.00, /*wavelength to trace*/ 550.0);

	EO49926.buildLensThreeSurfaces(/*lens catalog*/ "EO", /*catalog number*/ 49926, /*diameter*/9.00, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.025,/* focallength*/15.00,
		/* tolerance focal length*/ 2.0, /*back focal length*/12.08, /*design wavelength*/ 587.6, /*free aperture CA*/8.1,/*min centering*/ 0.0,
		/*max centering*/1.0,  /*first thickness*/4.00,	/*second thickness*/1.50, /*tolerance center thickness*/ 0.2, /*radius first surface*/10.49,
		/*radius second surface*/ -8.08, /*radius third surface*/ -38.23, /*edge thickness*/4.22, /*material first*/ mGlasses.getNBAF10_S1(),
		/*material second*/ mGlasses.getNSF6_S1(),/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*stop*/1.67, /*numerical aperture*/0.30,
		/*coating*/ "MgF2",	/*coating specification*/ 1.75,	/*power wavelength*/ 632.8, /*power PV*/ 1.5,/*curvature wavelength*/ 632.8,
		/*curvature PV*/ 4, /*bevel*/ "Protective bevel as needed",	/*type*/ "achromatic lens",	/*min wavelength*/ 400.0, /*max wavelength*/ 700.0,
		/*price*/55.00, /*wavelength to trace*/ 550.0);

	EO45091.buildLensThreeSurfaces(/*lens catalog*/ "EO", /*catalog number*/ 45091, /*diameter*/9.0, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.025,/* focallength*/18.00,
		/* tolerance focal length*/ 2.0, /*back focal length*/14.91, /*design wavelength*/ 587.6, /*free aperture CA*/8.1,/*min centering*/ 0.0,
		/*max centering*/1.0,  /*first thickness*/4.32,	/*second thickness*/1.15, /*tolerance center thickness*/ 0.2, /*radius first surface*/12.37,
		/*radius second surface*/ -7.38, /*radius third surface*/ -73.86, /*edge thickness*/4.49, /*material first*/ mGlasses.getNBAF10_S1(),
		/*material second*/ mGlasses.getNSF10_S1(),/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*stop*/2.00, /*numerical aperture*/0.25,
		/*coating*/ "MgF2",	/*coating specification*/ 1.75,	/*power wavelength*/ 632.8, /*power PV*/ 1.5,/*curvature wavelength*/ 632.8,
		/*curvature PV*/ 4, /*bevel*/ "Protective bevel as needed",	/*type*/ "achromatic lens",	/*min wavelength*/ 400.0, /*max wavelength*/ 700.0,
		/*price*/55.00, /*wavelength to trace*/ 550.0);

	EO49927.buildLensThreeSurfaces(/*lens catalog*/ "EO", /*catalog number*/ 49927, /*diameter*/9.00, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.025,/* focallength*/22.50,
		/* tolerance focal length*/ 2.0, /*back focal length*/20.21, /*design wavelength*/ 587.6, /*free aperture CA*/8.1,/*min centering*/ 0.0,
		/*max centering*/1.0,  /*first thickness*/3.0,	/*second thickness*/1.50, /*tolerance center thickness*/ 0.2, /*radius first surface*/14.79,
		/*radius second surface*/ -12.09, /*radius third surface*/ -45.72, /*edge thickness*/3.58, /*material first*/ mGlasses.getNSSK8_S1(),
		/*material second*/ mGlasses.getNSF56_S1(),/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*stop*/2.5, /*numerical aperture*/0.20,
		/*coating*/ "MgF2",	/*coating specification*/ 1.75,	/*power wavelength*/ 632.8, /*power PV*/ 1.5,/*curvature wavelength*/ 632.8,
		/*curvature PV*/ 4, /*bevel*/ "Protective bevel as needed",	/*type*/ "achromatic lens",	/*min wavelength*/ 400.0, /*max wavelength*/ 700.0,
		/*price*/55.00, /*wavelength to trace*/ 550.0);

	EO45092.buildLensThreeSurfaces(/*lens catalog*/ "EO", /*catalog number*/ 45092, /*diameter*/9.00, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.025,/* focallength*/27.00,
		/* tolerance focal length*/ 2.0, /*back focal length*/24.22, /*design wavelength*/ 587.6, /*free aperture CA*/8.1,/*min centering*/ 0.0,
		/*max centering*/1.0,  /*first thickness*/3.89,	/*second thickness*/1.30, /*tolerance center thickness*/ 0.2, /*radius first surface*/15.36,
		/*radius second surface*/ -12.01, /*radius third surface*/ -39.56, /*edge thickness*/4.26, /*material first*/ mGlasses.getNBK7_S1(),
		/*material second*/ mGlasses.getNSF5_S1(),/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*stop*/3.00, /*numerical aperture*/0.17,
		/*coating*/ "MgF2",	/*coating specification*/ 1.75,	/*power wavelength*/ 632.8, /*power PV*/ 1.5,/*curvature wavelength*/ 632.8,
		/*curvature PV*/ 4, /*bevel*/ "Protective bevel as needed",	/*type*/ "achromatic lens",	/*min wavelength*/ 400.0, /*max wavelength*/ 700.0,
		/*price*/55.00, /*wavelength to trace*/ 550.0);

	EO45264.buildLensThreeSurfaces(/*lens catalog*/ "EO", /*catalog number*/ 45264, /*diameter*/9.00, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.025,/* focallength*/36.00,
		/* tolerance focal length*/ 2.0, /*back focal length*/34.17, /*design wavelength*/ 587.6, /*free aperture CA*/8.1,/*min centering*/ 0.0,
		/*max centering*/1.0,  /*first thickness*/2.50,	/*second thickness*/1.50, /*tolerance center thickness*/ 0.2, /*radius first surface*/22.16,
		/*radius second surface*/ -15.98, /*radius third surface*/ -46.14, /*edge thickness*/3.32, /*material first*/ mGlasses.getNBK7_S1(),
		/*material second*/ mGlasses.getNSF5_S1(),/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*stop*/4.00, /*numerical aperture*/0.13,
		/*coating*/ "MgF2",	/*coating specification*/ 1.75,	/*power wavelength*/ 632.8, /*power PV*/ 1.5,/*curvature wavelength*/ 632.8,
		/*curvature PV*/ 4, /*bevel*/ "Protective bevel as needed",	/*type*/ "achromatic lens",	/*min wavelength*/ 400.0, /*max wavelength*/ 700.0,
		/*price*/55.00, /*wavelength to trace*/ 550.0);

	EO45818.buildLensThreeSurfaces(/*lens catalog*/ "EO", /*catalog number*/ 45818, /*diameter*/9.00, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.025,/* focallength*/40.00,
		/* tolerance focal length*/ 2.0, /*back focal length*/37.54, /*design wavelength*/ 587.6, /*free aperture CA*/8.1,/*min centering*/ 0.0,
		/*max centering*/1.0,  /*first thickness*/3.73,	/*second thickness*/1.33, /*tolerance center thickness*/ 0.2, /*radius first surface*/24.77,
		/*radius second surface*/ -18.01, /*radius third surface*/ -51.17, /*edge thickness*/4.59, /*material first*/ mGlasses.getNBK7_S1(),
		/*material second*/ mGlasses.getNSF5_S1(),/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*stop*/4.44, /*numerical aperture*/0.11,
		/*coating*/ "MgF2",	/*coating specification*/ 1.75,	/*power wavelength*/ 632.8, /*power PV*/ 1.5,/*curvature wavelength*/ 632.8,
		/*curvature PV*/ 4, /*bevel*/ "Protective bevel as needed",	/*type*/ "achromatic lens",	/*min wavelength*/ 400.0, /*max wavelength*/ 700.0,
		/*price*/55.00, /*wavelength to trace*/ 550.0);

	EO45347.buildLensThreeSurfaces(/*lens catalog*/ "EO", /*catalog number*/ 45347, /*diameter*/9.00, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.025,/* focallength*/45.00,
		/* tolerance focal length*/ 2.0, /*back focal length*/42.97, /*design wavelength*/ 587.6, /*free aperture CA*/8.1,/*min centering*/ 0.0,
		/*max centering*/1.0,  /*first thickness*/3.00,	/*second thickness*/1.30, /*tolerance center thickness*/ 0.2, /*radius first surface*/27.83,
		/*radius second surface*/ -19.75, /*radius third surface*/ -57.06, /*edge thickness*/3.76, /*material first*/ mGlasses.getNBK7_S1(),
		/*material second*/ mGlasses.getNSF5_S1(),/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*stop*/5.00, /*numerical aperture*/0.10,
		/*coating*/ "MgF2",	/*coating specification*/ 1.75,	/*power wavelength*/ 632.8, /*power PV*/ 1.5,/*curvature wavelength*/ 632.8,
		/*curvature PV*/ 4, /*bevel*/ "Protective bevel as needed",	/*type*/ "achromatic lens",	/*min wavelength*/ 400.0, /*max wavelength*/ 700.0,
		/*price*/55.00, /*wavelength to trace*/ 550.0);

	EO45819.buildLensThreeSurfaces(/*lens catalog*/ "EO", /*catalog number*/ 45819, /*diameter*/9.0, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.025,/* focallength*/60.00,
		/* tolerance focal length*/ 2.0, /*back focal length*/57.59, /*design wavelength*/ 587.6, /*free aperture CA*/8.1,/*min centering*/ 0.0,
		/*max centering*/1.0,  /*first thickness*/3.50,	/*second thickness*/1.50, /*tolerance center thickness*/ 0.2, /*radius first surface*/36.51,
		/*radius second surface*/ -26.33, /*radius third surface*/ -78.35, /*edge thickness*/3.32, /*material first*/ mGlasses.getNBK7_S1(),
		/*material second*/ mGlasses.getNSF5_S1(),/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*stop*/6.67, /*numerical aperture*/0.07,
		/*coating*/ "MgF2",	/*coating specification*/ 1.75,	/*power wavelength*/ 632.8, /*power PV*/ 1.5,/*curvature wavelength*/ 632.8,
		/*curvature PV*/ 4, /*bevel*/ "Protective bevel as needed",	/*type*/ "achromatic lens",	/*min wavelength*/ 400.0, /*max wavelength*/ 700.0,
		/*price*/55.00, /*wavelength to trace*/ 550.0);

	EO45820.buildLensThreeSurfaces(/*lens catalog*/ "EO", /*catalog number*/ 45820, /*diameter*/9.00, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.025,/* focallength*/75.00,
		/* tolerance focal length*/ 2.0, /*back focal length*/72.35, /*design wavelength*/ 587.6, /*free aperture CA*/8.1,/*min centering*/ 0.0,
		/*max centering*/1.0,  /*first thickness*/3.00,	/*second thickness*/1.60, /*tolerance center thickness*/ 0.2, /*radius first surface*/46.44,
		/*radius second surface*/ -33.77, /*radius third surface*/ -95.94, /*edge thickness*/4.28, /*material first*/ mGlasses.getNBK7_S1(),
		/*material second*/ mGlasses.getNSF5_S1(),/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*stop*/8.33, /*numerical aperture*/0.06,
		/*coating*/ "MgF2",	/*coating specification*/ 1.75,	/*power wavelength*/ 632.8, /*power PV*/ 1.5,/*curvature wavelength*/ 632.8,
		/*curvature PV*/ 4, /*bevel*/ "Protective bevel as needed",	/*type*/ "achromatic lens",	/*min wavelength*/ 400.0, /*max wavelength*/ 700.0,
		/*price*/55.00, /*wavelength to trace*/ 550.0);

	EO63693.buildLensThreeSurfaces(/*lens catalog*/ "EO", /*catalog number*/ 63693, /*diameter*/10.00, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.025,/* focallength*/15.00,
		/* tolerance focal length*/ 2.0, /*back focal length*/10.66, /*design wavelength*/ 587.6, /*free aperture CA*/9.00,/*min centering*/ 0.0,
		/*max centering*/1.0,  /*first thickness*/5.50,	/*second thickness*/2.00, /*tolerance center thickness*/ 0.2, /*radius first surface*/10.04,
		/*radius second surface*/ -7.00, /*radius third surface*/ -80.71, /*edge thickness*/6.01, /*material first*/ mGlasses.getNBAF10_S1(),
		/*material second*/ mGlasses.getNSF10_S1(),/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*stop*/1.5, /*numerical aperture*/0.33,
		/*coating*/ "MgF2",	/*coating specification*/ 1.75,	/*power wavelength*/ 632.8, /*power PV*/ 1.5,/*curvature wavelength*/ 632.8,
		/*curvature PV*/ 4, /*bevel*/ "Protective bevel as needed",	/*type*/ "achromatic lens",	/*min wavelength*/ 400.0, /*max wavelength*/ 700.0,
		/*price*/56.50, /*wavelength to trace*/ 550.0);

	EO63694.buildLensThreeSurfaces(/*lens catalog*/ "EO", /*catalog number*/ 63694, /*diameter*/10.00, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.025,/* focallength*/20.00,
		/* tolerance focal length*/ 2.0, /*back focal length*/17.25, /*design wavelength*/ 587.6, /*free aperture CA*/9.00,/*min centering*/ 0.0,
		/*max centering*/1.0,  /*first thickness*/4.00,	/*second thickness*/1.00, /*tolerance center thickness*/ 0.2, /*radius first surface*/14.15,
		/*radius second surface*/ -8.38, /*radius third surface*/ -71.22, /*edge thickness*/3.91, /*material first*/ mGlasses.getNBAF10_S1(),
		/*material second*/ mGlasses.getNSF10_S1(),/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*stop*/2.00, /*numerical aperture*/0.25,
		/*coating*/ "MgF2",	/*coating specification*/ 1.75,	/*power wavelength*/ 632.8, /*power PV*/ 1.5,/*curvature wavelength*/ 632.8,
		/*curvature PV*/ 4, /*bevel*/ "Protective bevel as needed",	/*type*/ "achromatic lens",	/*min wavelength*/ 400.0, /*max wavelength*/ 700.0,
		/*price*/56.50, /*wavelength to trace*/ 550.0);

	EO63695.buildLensThreeSurfaces(/*lens catalog*/ "EO", /*catalog number*/ 63695, /*diameter*/10.0, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.025,/* focallength*/25.00,
		/* tolerance focal length*/ 2.0, /*back focal length*/22.60, /*design wavelength*/ 587.6, /*free aperture CA*/9.00,/*min centering*/ 0.0,
		/*max centering*/1.0,  /*first thickness*/3.50,	/*second thickness*/1.50, /*tolerance center thickness*/ 0.2, /*radius first surface*/15.37,
		/*radius second surface*/ -11.10, /*radius third surface*/ -31.47, /*edge thickness*/3.76, /*material first*/ mGlasses.getNBK7_S1(),
		/*material second*/ mGlasses.getNSF5_S1(),/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*stop*/2.5, /*numerical aperture*/0.20,
		/*coating*/ "MgF2",	/*coating specification*/ 1.75,	/*power wavelength*/ 632.8, /*power PV*/ 1.5,/*curvature wavelength*/ 632.8,
		/*curvature PV*/ 4, /*bevel*/ "Protective bevel as needed",	/*type*/ "achromatic lens",	/*min wavelength*/ 400.0, /*max wavelength*/ 700.0,
		/*price*/56.50, /*wavelength to trace*/ 550.0);

	EO63696.buildLensThreeSurfaces(/*lens catalog*/ "EO", /*catalog number*/ 63696, /*diameter*/10.0, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.025,/* focallength*/30.0,
		/* tolerance focal length*/ 2.0, /*back focal length*/27.47, /*design wavelength*/ 587.6, /*free aperture CA*/9.00,/*min centering*/ 0.0,
		/*max centering*/1.0,  /*first thickness*/3.50,	/*second thickness*/2.00, /*tolerance center thickness*/ 0.2, /*radius first surface*/18.58,
		/*radius second surface*/ -13.17, /*radius third surface*/ -37.11, /*edge thickness*/4.48, /*material first*/ mGlasses.getNBK7_S1(),
		/*material second*/ mGlasses.getNSF5_S1(),/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*stop*/3.00, /*numerical aperture*/0.17,
		/*coating*/ "MgF2",	/*coating specification*/ 1.75,	/*power wavelength*/ 632.8, /*power PV*/ 1.5,/*curvature wavelength*/ 632.8,
		/*curvature PV*/ 4, /*bevel*/ "Protective bevel as needed",	/*type*/ "achromatic lens",	/*min wavelength*/ 400.0, /*max wavelength*/ 700.0,
		/*price*/56.50, /*wavelength to trace*/ 550.0);

	EO63697.buildLensThreeSurfaces(/*lens catalog*/ "EO", /*catalog number*/ 63697, /*diameter*/10.0, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.025,/* focallength*/40.00,
		/* tolerance focal length*/ 2.0, /*back focal length*/37.79, /*design wavelength*/ 587.6, /*free aperture CA*/9.00,/*min centering*/ 0.0,
		/*max centering*/1.0,  /*first thickness*/3.00,	/*second thickness*/1.50, /*tolerance center thickness*/ 0.2, /*radius first surface*/23.66,
		/*radius second surface*/ -18.11, /*radius third surface*/ -55.78, /*edge thickness*/3.74, /*material first*/ mGlasses.getNBK7_S1(),
		/*material second*/ mGlasses.getNSF5_S1(),/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*stop*/4.00, /*numerical aperture*/0.13,
		/*coating*/ "MgF2",	/*coating specification*/ 1.75,	/*power wavelength*/ 632.8, /*power PV*/ 1.5,/*curvature wavelength*/ 632.8,
		/*curvature PV*/ 4, /*bevel*/ "Protective bevel as needed",	/*type*/ "achromatic lens",	/*min wavelength*/ 400.0, /*max wavelength*/ 700.0,
		/*price*/56.50, /*wavelength to trace*/ 550.0);

	EO63698.buildLensThreeSurfaces(/*lens catalog*/ "EO", /*catalog number*/ 63698, /*diameter*/10.00, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.025,/* focallength*/50.00,
		/* tolerance focal length*/ 2.0, /*back focal length*/47.45, /*design wavelength*/ 587.6, /*free aperture CA*/9.00,/*min centering*/ 0.0,
		/*max centering*/1.0,  /*first thickness*/3.00,	/*second thickness*/1.50, /*tolerance center thickness*/ 0.2, /*radius first surface*/26.22,
		/*radius second surface*/ -23.95, /*radius third surface*/ -97.55, /*edge thickness*/3.89, /*material first*/ mGlasses.getNBK7_S1(),
		/*material second*/ mGlasses.getNSF5_S1(),/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*stop*/5.00, /*numerical aperture*/0.10,
		/*coating*/ "MgF2",	/*coating specification*/ 1.75,	/*power wavelength*/ 632.8, /*power PV*/ 1.5,/*curvature wavelength*/ 632.8,
		/*curvature PV*/ 4, /*bevel*/ "Protective bevel as needed",	/*type*/ "achromatic lens",	/*min wavelength*/ 400.0, /*max wavelength*/ 700.0,
		/*price*/56.50, /*wavelength to trace*/ 550.0);

	EO63699.buildLensThreeSurfaces(/*lens catalog*/ "EO", /*catalog number*/ 63699, /*diameter*/10.00, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.025,/* focallength*/100.00,
		/* tolerance focal length*/ 2.0, /*back focal length*/98.16, /*design wavelength*/ 587.6, /*free aperture CA*/9.00,/*min centering*/ 0.0,
		/*max centering*/1.0,  /*first thickness*/2.50,	/*second thickness*/1.50, /*tolerance center thickness*/ 0.2, /*radius first surface*/60.99,
		/*radius second surface*/ -43.74, /*radius third surface*/ -130.98, /*edge thickness*/3.70, /*material first*/ mGlasses.getNBK7_S1(),
		/*material second*/ mGlasses.getNSF5_S1(),/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*stop*/10.00, /*numerical aperture*/0.05,
		/*coating*/ "MgF2",	/*coating specification*/ 1.75,	/*power wavelength*/ 632.8, /*power PV*/ 1.5,/*curvature wavelength*/ 632.8,
		/*curvature PV*/ 4, /*bevel*/ "Protective bevel as needed",	/*type*/ "achromatic lens",	/*min wavelength*/ 400.0, /*max wavelength*/ 700.0,
		/*price*/56.50, /*wavelength to trace*/ 550.0);

	EO65550.buildLensThreeSurfaces(/*lens catalog*/ "EO", /*catalog number*/ 65550, /*diameter*/12.50, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.025,/* focallength*/12.50,
		/* tolerance focal length*/ 2.0, /*back focal length*/7.23, /*design wavelength*/ 587.6, /*free aperture CA*/11.50,/*min centering*/ 0.0,
		/*max centering*/1.0,  /*first thickness*/8.12,	/*second thickness*/2.50, /*tolerance center thickness*/ 0.2, /*radius first surface*/9.53,
		/*radius second surface*/ -6.92, /*radius third surface*/ -20.07, /*edge thickness*/7.29, /*material first*/ mGlasses.getNBASF64_S1(),
		/*material second*/ mGlasses.getNSF66_S1(),/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*stop*/1.00, /*numerical aperture*/0.50,
		/*coating*/ "MgF2",	/*coating specification*/ 1.75,	/*power wavelength*/ 632.8, /*power PV*/ 1.5,/*curvature wavelength*/ 632.8,
		/*curvature PV*/ 4, /*bevel*/ "Protective bevel as needed",	/*type*/ "achromatic lens",	/*min wavelength*/ 400.0, /*max wavelength*/ 700.0,
		/*price*/90.00, /*wavelength to trace*/ 550.0);

	EO45209.buildLensThreeSurfaces(/*lens catalog*/ "EO", /*catalog number*/ 45209, /*diameter*/12.50, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.025,/* focallength*/14.00,
		/* tolerance focal length*/ 2.0, /*back focal length*/9.92, /*design wavelength*/ 587.6, /*free aperture CA*/11.50,/*min centering*/ 0.0,
		/*max centering*/1.0,  /*first thickness*/6.23,	/*second thickness*/1.50, /*tolerance center thickness*/ 0.2, /*radius first surface*/10.60,
		/*radius second surface*/ -7.72, /*radius third surface*/ -56.54, /*edge thickness*/5.34, /*material first*/ mGlasses.getNBAF10_S1(),
		/*material second*/ mGlasses.getNSF5_S1(),/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*stop*/1.12, /*numerical aperture*/0.45,
		/*coating*/ "MgF2",	/*coating specification*/ 1.75,	/*power wavelength*/ 632.8, /*power PV*/ 1.5,/*curvature wavelength*/ 632.8,
		/*curvature PV*/ 4, /*bevel*/ "Protective bevel as needed",	/*type*/ "achromatic lens",	/*min wavelength*/ 400.0, /*max wavelength*/ 700.0,
		/*price*/63.50, /*wavelength to trace*/ 550.0);

	EO63700.buildLensThreeSurfaces(/*lens catalog*/ "EO", /*catalog number*/ 63700, /*diameter*/12.50, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.025,/* focallength*/15.00,
		/* tolerance focal length*/ 2.0, /*back focal length*/10.82, /*design wavelength*/ 587.6, /*free aperture CA*/11.50,/*min centering*/ 0.0,
		/*max centering*/1.0,  /*first thickness*/6.00,	/*second thickness*/1.00, /*tolerance center thickness*/ 0.2, /*radius first surface*/9.55,
		/*radius second surface*/ -8.60, /*radius third surface*/ -48.50, /*edge thickness*/4.27, /*material first*/ mGlasses.getNLAK22_S1(),
		/*material second*/ mGlasses.getNSF6_S1(),/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*stop*/1.2, /*numerical aperture*/0.42,
		/*coating*/ "MgF2",	/*coating specification*/ 1.75,	/*power wavelength*/ 632.8, /*power PV*/ 1.5,/*curvature wavelength*/ 632.8,
		/*curvature PV*/ 4, /*bevel*/ "Protective bevel as needed",	/*type*/ "achromatic lens",	/*min wavelength*/ 400.0, /*max wavelength*/ 700.0,
		/*price*/63.50, /*wavelength to trace*/ 550.0);

	EO49928.buildLensThreeSurfaces(/*lens catalog*/ "EO", /*catalog number*/ 49928, /*diameter*/12.50, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.025,/* focallength*/17.50,
		/* tolerance focal length*/ 2.0, /*back focal length*/13.59, /*design wavelength*/ 587.6, /*free aperture CA*/11.50,/*min centering*/ 0.0,
		/*max centering*/1.0,  /*first thickness*/5.80,	/*second thickness*/1.50, /*tolerance center thickness*/ 0.2, /*radius first surface*/12.20,
		/*radius second surface*/ -9.82, /*radius third surface*/ -39.19, /*edge thickness*/5.08, /*material first*/ mGlasses.getNBAF10_S1(),
		/*material second*/ mGlasses.getNSF57_S1(),/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*stop*/1.4, /*numerical aperture*/0.36,
		/*coating*/ "MgF2",	/*coating specification*/ 1.75,	/*power wavelength*/ 632.8, /*power PV*/ 1.5,/*curvature wavelength*/ 632.8,
		/*curvature PV*/ 4, /*bevel*/ "Protective bevel as needed",	/*type*/ "achromatic lens",	/*min wavelength*/ 400.0, /*max wavelength*/ 700.0,
		/*price*/63.50, /*wavelength to trace*/ 550.0);

	//EO32309.buildLensThreeSurfaces(/*lens catalog*/ "EO", /*catalog number*/ 32309, /*diameter*/12.50, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.025,/* focallength*/20.00,		//Glas 1 nicht im Glaskatalog
	//	/* tolerance focal length*/ 2.0, /*back focal length*/16.45, /*design wavelength*/ 587.6, /*free aperture CA*/11.50,/*min centering*/ 0.0,
	//	/*max centering*/1.0,  /*first thickness*/5.25,	/*second thickness*/1.10, /*tolerance center thickness*/ 0.2, /*radius first surface*/13.98,
	//	/*radius second surface*/ -9.35, /*radius third surface*/ -76.14, /*edge thickness*/4.62, /*material first*/ glasses.getSBaH11_S1(),
	//	/*material second*/ glasses.getNSF10_S1(),/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*stop*/1.6, /*numerical aperture*/0.31,
	//	/*coating*/ "MgF2",	/*coating specification*/ 1.75,	/*power wavelength*/ 632.8, /*power PV*/ 1.5,/*curvature wavelength*/ 632.8,
	//	/*curvature PV*/ 4, /*bevel*/ "Protective bevel as needed",	/*type*/ "achromatic lens",	/*min wavelength*/ 400.0, /*max wavelength*/ 700.0,
	//	/*price*/63.50, /*wavelength to trace*/ 550.0);

	EO32311.buildLensThreeSurfaces(/*lens catalog*/ "EO", /*catalog number*/ 32311, /*diameter*/12.50, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.025,/* focallength*/25.00,
		/* tolerance focal length*/ 2.0, /*back focal length*/21.47, /*design wavelength*/ 587.6, /*free aperture CA*/11.50,/*min centering*/ 0.0,
		/*max centering*/1.0,  /*first thickness*/5.00,	/*second thickness*/1.25, /*tolerance center thickness*/ 0.2, /*radius first surface*/17.27,
		/*radius second surface*/ -10.99, /*radius third surface*/ -107.03, /*edge thickness*/4.90, /*material first*/ mGlasses.getNBAF10_S1(),
		/*material second*/ mGlasses.getNSF10_S1(),/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*stop*/2.00, /*numerical aperture*/0.25,
		/*coating*/ "MgF2",	/*coating specification*/ 1.75,	/*power wavelength*/ 632.8, /*power PV*/ 1.5,/*curvature wavelength*/ 632.8,
		/*curvature PV*/ 4, /*bevel*/ "Protective bevel as needed",	/*type*/ "achromatic lens",	/*min wavelength*/ 400.0, /*max wavelength*/ 700.0,
		/*price*/63.50, /*wavelength to trace*/ 550.0);

	EO32313.buildLensThreeSurfaces(/*lens catalog*/ "EO", /*catalog number*/ 32313, /*diameter*/12.50, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.025,/* focallength*/30.00,
		/* tolerance focal length*/ 2.0, /*back focal length*/26.12, /*design wavelength*/ 587.6, /*free aperture CA*/11.50,/*min centering*/ 0.0,
		/*max centering*/1.0,  /*first thickness*/4.50,	/*second thickness*/1.20, /*tolerance center thickness*/ 0.2, /*radius first surface*/15.97,
		/*radius second surface*/ -15.00, /*radius third surface*/ -528.23, /*edge thickness*/4.39, /*material first*/ mGlasses.getNSSK8_S1(),
		/*material second*/ mGlasses.getNSF10_S1(),/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*stop*/2.4, /*numerical aperture*/0.21,
		/*coating*/ "MgF2",	/*coating specification*/ 1.75,	/*power wavelength*/ 632.8, /*power PV*/ 1.5,/*curvature wavelength*/ 632.8,
		/*curvature PV*/ 4, /*bevel*/ "Protective bevel as needed",	/*type*/ "achromatic lens",	/*min wavelength*/ 400.0, /*max wavelength*/ 700.0,
		/*price*/63.50, /*wavelength to trace*/ 550.0);

	EO45210.buildLensThreeSurfaces(/*lens catalog*/ "EO", /*catalog number*/ 45210, /*diameter*/12.50, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.025,/* focallength*/35.00,
		/* tolerance focal length*/ 2.0, /*back focal length*/32.50, /*design wavelength*/ 587.6, /*free aperture CA*/11.50,/*min centering*/ 0.0,
		/*max centering*/1.0,  /*first thickness*/3.68,	/*second thickness*/1.50, /*tolerance center thickness*/ 0.2, /*radius first surface*/22.94,
		/*radius second surface*/ -15.54, /*radius third surface*/ -58.84, /*edge thickness*/3.98, /*material first*/ mGlasses.getNSK11_S1(),
		/*material second*/ mGlasses.getNSF5_S1(),/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*stop*/2.8, /*numerical aperture*/0.18,
		/*coating*/ "MgF2",	/*coating specification*/ 1.75,	/*power wavelength*/ 632.8, /*power PV*/ 1.5,/*curvature wavelength*/ 632.8,
		/*curvature PV*/ 4, /*bevel*/ "Protective bevel as needed",	/*type*/ "achromatic lens",	/*min wavelength*/ 400.0, /*max wavelength*/ 700.0,
		/*price*/63.50, /*wavelength to trace*/ 550.0);

	EO32315.buildLensThreeSurfaces(/*lens catalog*/ "EO", /*catalog number*/ 32315, /*diameter*/12.50, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.025,/* focallength*/40.00,
		/* tolerance focal length*/ 2.0, /*back focal length*/37.54, /*design wavelength*/ 587.6, /*free aperture CA*/11.50,/*min centering*/ 0.0,
		/*max centering*/1.0,  /*first thickness*/3.73,	/*second thickness*/1.33, /*tolerance center thickness*/ 0.2, /*radius first surface*/24.77,
		/*radius second surface*/ -18.01, /*radius third surface*/ -51.17, /*edge thickness*/3.88, /*material first*/ mGlasses.getNBK7_S1(),
		/*material second*/ mGlasses.getNSF5_S1(),/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*stop*/3.2, /*numerical aperture*/0.16,
		/*coating*/ "MgF2",	/*coating specification*/ 1.75,	/*power wavelength*/ 632.8, /*power PV*/ 1.5,/*curvature wavelength*/ 632.8,
		/*curvature PV*/ 4, /*bevel*/ "Protective bevel as needed",	/*type*/ "achromatic lens",	/*min wavelength*/ 400.0, /*max wavelength*/ 700.0,
		/*price*/63.50, /*wavelength to trace*/ 550.0);

	EO45136.buildLensThreeSurfaces(/*lens catalog*/ "EO", /*catalog number*/ 45136, /*diameter*/12.50, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.025,/* focallength*/45.00,
		/* tolerance focal length*/ 2.0, /*back focal length*/42.52, /*design wavelength*/ 587.6, /*free aperture CA*/11.50,/*min centering*/ 0.0,
		/*max centering*/1.0,  /*first thickness*/3.50,	/*second thickness*/1.50, /*tolerance center thickness*/ 0.2, /*radius first surface*/26.82,
		/*radius second surface*/ -20.12, /*radius third surface*/ -61.38, /*edge thickness*/3.94, /*material first*/ mGlasses.getNBK7_S1(),
		/*material second*/ mGlasses.getNSF5_S1(),/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*stop*/3.6, /*numerical aperture*/0.14,
		/*coating*/ "MgF2",	/*coating specification*/ 1.75,	/*power wavelength*/ 632.8, /*power PV*/ 1.5,/*curvature wavelength*/ 632.8,
		/*curvature PV*/ 4, /*bevel*/ "Protective bevel as needed",	/*type*/ "achromatic lens",	/*min wavelength*/ 400.0, /*max wavelength*/ 700.0,
		/*price*/63.50, /*wavelength to trace*/ 550.0);

	EO32317.buildLensThreeSurfaces(/*lens catalog*/ "EO", /*catalog number*/ 32317, /*diameter*/12.50, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.025,/* focallength*/50.00,
		/* tolerance focal length*/ 2.0, /*back focal length*/47.61, /*design wavelength*/ 587.6, /*free aperture CA*/11.50,/*min centering*/ 0.0,
		/*max centering*/1.0,  /*first thickness*/3.50,	/*second thickness*/1.50, /*tolerance center thickness*/ 0.2, /*radius first surface*/30.73,
		/*radius second surface*/ -22.32, /*radius third surface*/ -64.75, /*edge thickness*/4.06, /*material first*/ mGlasses.getNBK7_S1(),
		/*material second*/ mGlasses.getNSF5_S1(),/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*stop*/4.00, /*numerical aperture*/0.13,
		/*coating*/ "MgF2",	/*coating specification*/ 1.75,	/*power wavelength*/ 632.8, /*power PV*/ 1.5,/*curvature wavelength*/ 632.8,
		/*curvature PV*/ 4, /*bevel*/ "Protective bevel as needed",	/*type*/ "achromatic lens",	/*min wavelength*/ 400.0, /*max wavelength*/ 700.0,
		/*price*/63.50, /*wavelength to trace*/ 550.0);

	EO45137.buildLensThreeSurfaces(/*lens catalog*/ "EO", /*catalog number*/ 45137, /*diameter*/12.50, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.025,/* focallength*/60.00,
		/* tolerance focal length*/ 2.0, /*back focal length*/57.59, /*design wavelength*/ 587.6, /*free aperture CA*/11.50,/*min centering*/ 0.0,
		/*max centering*/1.0,  /*first thickness*/3.50,	/*second thickness*/1.50, /*tolerance center thickness*/ 0.2, /*radius first surface*/36.51,
		/*radius second surface*/ -26.33, /*radius third surface*/ -78.35, /*edge thickness*/4.21, /*material first*/ mGlasses.getNBK7_S1(),
		/*material second*/ mGlasses.getNSF5_S1(),/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*stop*/4.8, /*numerical aperture*/0.1,
		/*coating*/ "MgF2",	/*coating specification*/ 1.75,	/*power wavelength*/ 632.8, /*power PV*/ 1.5,/*curvature wavelength*/ 632.8,
		/*curvature PV*/ 4, /*bevel*/ "Protective bevel as needed",	/*type*/ "achromatic lens",	/*min wavelength*/ 400.0, /*max wavelength*/ 700.0,
		/*price*/63.50, /*wavelength to trace*/ 550.0);

	EO32882.buildLensThreeSurfaces(/*lens catalog*/ "EO", /*catalog number*/ 32882, /*diameter*/12.50, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.025,/* focallength*/75.00,
		/* tolerance focal length*/ 2.0, /*back focal length*/72.35, /*design wavelength*/ 587.6, /*free aperture CA*/11.50,/*min centering*/ 0.0,
		/*max centering*/1.0,  /*first thickness*/3.00,	/*second thickness*/1.60, /*tolerance center thickness*/ 0.2, /*radius first surface*/46.44,
		/*radius second surface*/ -33.77, /*radius third surface*/ -95.94, /*edge thickness*/3.97, /*material first*/ mGlasses.getNBK7_S1(),
		/*material second*/ mGlasses.getNSF5_S1(),/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*stop*/6.00, /*numerical aperture*/0.08,
		/*coating*/ "MgF2",	/*coating specification*/ 1.75,	/*power wavelength*/ 632.8, /*power PV*/ 1.5,/*curvature wavelength*/ 632.8,
		/*curvature PV*/ 4, /*bevel*/ "Protective bevel as needed",	/*type*/ "achromatic lens",	/*min wavelength*/ 400.0, /*max wavelength*/ 700.0,
		/*price*/63.50, /*wavelength to trace*/ 550.0);

	EO45409.buildLensThreeSurfaces(/*lens catalog*/ "EO", /*catalog number*/ 45409, /*diameter*/12.50, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.025,/* focallength*/80.00,
		/* tolerance focal length*/ 2.0, /*back focal length*/78.40, /*design wavelength*/ 587.6, /*free aperture CA*/11.50,/*min centering*/ 0.0,
		/*max centering*/1.0,  /*first thickness*/2.10,	/*second thickness*/1.60, /*tolerance center thickness*/ 0.2, /*radius first surface*/49.62,
		/*radius second surface*/ -35.73, /*radius third surface*/ -103.22, /*edge thickness*/3.12, /*material first*/ mGlasses.getNBK7_S1(),
		/*material second*/ mGlasses.getNSF5_S1(),/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*stop*/6.4, /*numerical aperture*/0.08,
		/*coating*/ "MgF2",	/*coating specification*/ 1.75,	/*power wavelength*/ 632.8, /*power PV*/ 1.5,/*curvature wavelength*/ 632.8,
		/*curvature PV*/ 4, /*bevel*/ "Protective bevel as needed",	/*type*/ "achromatic lens",	/*min wavelength*/ 400.0, /*max wavelength*/ 700.0,
		/*price*/63.50, /*wavelength to trace*/ 550.0);

	EO45410.buildLensThreeSurfaces(/*lens catalog*/ "EO", /*catalog number*/ 45410, /*diameter*/12.50, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.025,/* focallength*/90.00,
		/* tolerance focal length*/ 2.0, /*back focal length*/88.47, /*design wavelength*/ 587.6, /*free aperture CA*/11.50,/*min centering*/ 0.0,
		/*max centering*/1.0,  /*first thickness*/1.98,	/*second thickness*/1.60, /*tolerance center thickness*/ 0.2, /*radius first surface*/55.80,
		/*radius second surface*/ -40.17, /*radius third surface*/ -116.32, /*edge thickness*/3.06, /*material first*/ mGlasses.getNBK7_S1(),
		/*material second*/ mGlasses.getNSF5_S1(),/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*stop*/7.2, /*numerical aperture*/0.07,
		/*coating*/ "MgF2",	/*coating specification*/ 1.75,	/*power wavelength*/ 632.8, /*power PV*/ 1.5,/*curvature wavelength*/ 632.8,
		/*curvature PV*/ 4, /*bevel*/ "Protective bevel as needed",	/*type*/ "achromatic lens",	/*min wavelength*/ 400.0, /*max wavelength*/ 700.0,
		/*price*/63.50, /*wavelength to trace*/ 550.0);

	EO45265.buildLensThreeSurfaces(/*lens catalog*/ "EO", /*catalog number*/ 45265, /*diameter*/12.50, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.025,/* focallength*/100.00,
		/* tolerance focal length*/ 2.0, /*back focal length*/97.92, /*design wavelength*/ 587.6, /*free aperture CA*/11.50,/*min centering*/ 0.0,
		/*max centering*/1.0,  /*first thickness*/3.00,	/*second thickness*/1.50, /*tolerance center thickness*/ 0.2, /*radius first surface*/61.54,
		/*radius second surface*/ -44.39, /*radius third surface*/ -130.26, /*edge thickness*/4.03, /*material first*/ mGlasses.getNBK7_S1(),
		/*material second*/ mGlasses.getNSF5_S1(),/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*stop*/8.00, /*numerical aperture*/0.06,
		/*coating*/ "MgF2",	/*coating specification*/ 1.75,	/*power wavelength*/ 632.8, /*power PV*/ 1.5,/*curvature wavelength*/ 632.8,
		/*curvature PV*/ 4, /*bevel*/ "Protective bevel as needed",	/*type*/ "achromatic lens",	/*min wavelength*/ 400.0, /*max wavelength*/ 700.0,
		/*price*/63.50, /*wavelength to trace*/ 550.0);

	EO49758.buildLensThreeSurfaces(/*lens catalog*/ "EO", /*catalog number*/ 49758, /*diameter*/12.70, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.025,/* focallength*/15.00,
		/* tolerance focal length*/ 2.0, /*back focal length*/10.56, /*design wavelength*/ 587.6, /*free aperture CA*/11.70,/*min centering*/ 0.0,
		/*max centering*/1.0,  /*first thickness*/6.50,	/*second thickness*/2.00, /*tolerance center thickness*/ 0.2, /*radius first surface*/10.59,
		/*radius second surface*/ -8.26, /*radius third surface*/ -30.70, /*edge thickness*/5.72, /*material first*/ mGlasses.getNBAF10_S1(),
		/*material second*/ mGlasses.getNSF57_S1(),/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*stop*/1.18, /*numerical aperture*/0.42,
		/*coating*/ "MgF2",	/*coating specification*/ 1.75,	/*power wavelength*/ 632.8, /*power PV*/ 1.5,/*curvature wavelength*/ 632.8,
		/*curvature PV*/ 4, /*bevel*/ "Protective bevel as needed",	/*type*/ "achromatic lens",	/*min wavelength*/ 400.0, /*max wavelength*/ 700.0,
		/*price*/63.50, /*wavelength to trace*/ 550.0);

	EO49759.buildLensThreeSurfaces(/*lens catalog*/ "EO", /*catalog number*/ 49759, /*diameter*/12.70, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.025,/* focallength*/19.10,
		/* tolerance focal length*/ 2.0, /*back focal length*/15.38, /*design wavelength*/ 587.6, /*free aperture CA*/11.70,/*min centering*/ 0.0,
		/*max centering*/1.0,  /*first thickness*/5.25,	/*second thickness*/1.50, /*tolerance center thickness*/ 0.2, /*radius first surface*/13.185,
		/*radius second surface*/ -10.215, /*radius third surface*/ -50.875, /*edge thickness*/4.72, /*material first*/ mGlasses.getNBAF10_S1(),
		/*material second*/ mGlasses.getNSF6_S1(),/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*stop*/1.5, /*numerical aperture*/0.33,
		/*coating*/ "MgF2",	/*coating specification*/ 1.75,	/*power wavelength*/ 632.8, /*power PV*/ 1.5,/*curvature wavelength*/ 632.8,
		/*curvature PV*/ 4, /*bevel*/ "Protective bevel as needed",	/*type*/ "achromatic lens",	/*min wavelength*/ 400.0, /*max wavelength*/ 700.0,
		/*price*/63.50, /*wavelength to trace*/ 550.0);

	EO49760.buildLensThreeSurfaces(/*lens catalog*/ "EO", /*catalog number*/ 49760, /*diameter*/12.70, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.025,/* focallength*/25.40,
		/* tolerance focal length*/ 2.0, /*back focal length*/22.45, /*design wavelength*/ 587.6, /*free aperture CA*/11.70,/*min centering*/ 0.0,
		/*max centering*/1.0,  /*first thickness*/4.00,	/*second thickness*/1.75, /*tolerance center thickness*/ 0.2, /*radius first surface*/16.77,
		/*radius second surface*/ -13.63, /*radius third surface*/ -50.73, /*edge thickness*/4.10, /*material first*/ mGlasses.getNSSK8_S1(),
		/*material second*/ mGlasses.getNSF56_S1(),/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*stop*/2.00, /*numerical aperture*/0.25,
		/*coating*/ "MgF2",	/*coating specification*/ 1.75,	/*power wavelength*/ 632.8, /*power PV*/ 1.5,/*curvature wavelength*/ 632.8,
		/*curvature PV*/ 4, /*bevel*/ "Protective bevel as needed",	/*type*/ "achromatic lens",	/*min wavelength*/ 400.0, /*max wavelength*/ 700.0,
		/*price*/63.50, /*wavelength to trace*/ 550.0);

	EO49761.buildLensThreeSurfaces(/*lens catalog*/ "EO", /*catalog number*/ 49761, /*diameter*/12.70, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.025,/* focallength*/31.75,
		/* tolerance focal length*/ 2.0, /*back focal length*/28.83, /*design wavelength*/ 587.6, /*free aperture CA*/11.70,/*min centering*/ 0.0,
		/*max centering*/1.0,  /*first thickness*/4.00,	/*second thickness*/1.75, /*tolerance center thickness*/ 0.2, /*radius first surface*/21.13,
		/*radius second surface*/ -16.69, /*radius third surface*/ -61.73, /*edge thickness*/4.45, /*material first*/ mGlasses.getNSSK8_S1(),
		/*material second*/ mGlasses.getNSF56_S1(),/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*stop*/2.5, /*numerical aperture*/0.20,
		/*coating*/ "MgF2",	/*coating specification*/ 1.75,	/*power wavelength*/ 632.8, /*power PV*/ 1.5,/*curvature wavelength*/ 632.8,
		/*curvature PV*/ 4, /*bevel*/ "Protective bevel as needed",	/*type*/ "achromatic lens",	/*min wavelength*/ 400.0, /*max wavelength*/ 700.0,
		/*price*/63.50, /*wavelength to trace*/ 550.0);

	EO49762.buildLensThreeSurfaces(/*lens catalog*/ "EO", /*catalog number*/ 49762, /*diameter*/12.70, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.025,/* focallength*/38.10,
		/* tolerance focal length*/ 2.0, /*back focal length*/35.57, /*design wavelength*/ 587.6, /*free aperture CA*/11.70,/*min centering*/ 0.0,
		/*max centering*/1.0,  /*first thickness*/3.50,	/*second thickness*/1.50, /*tolerance center thickness*/ 0.2, /*radius first surface*/25.425,
		/*radius second surface*/ -20.03, /*radius third surface*/ -74.39, /*edge thickness*/3.92, /*material first*/ mGlasses.getNSSK8_S1(),
		/*material second*/ mGlasses.getNSF56_S1(),/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*stop*/3.00, /*numerical aperture*/0.17,
		/*coating*/ "MgF2",	/*coating specification*/ 1.75,	/*power wavelength*/ 632.8, /*power PV*/ 1.5,/*curvature wavelength*/ 632.8,
		/*curvature PV*/ 4, /*bevel*/ "Protective bevel as needed",	/*type*/ "achromatic lens",	/*min wavelength*/ 400.0, /*max wavelength*/ 700.0,
		/*price*/63.50, /*wavelength to trace*/ 550.0);

	EO49763.buildLensThreeSurfaces(/*lens catalog*/ "EO", /*catalog number*/ 49763, /*diameter*/12.70, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.025,/* focallength*/44.45,
		/* tolerance focal length*/ 2.0, /*back focal length*/41.98, /*design wavelength*/ 587.6, /*free aperture CA*/11.70,/*min centering*/ 0.0,
		/*max centering*/1.0,  /*first thickness*/3.00,	/*second thickness*/2.00, /*tolerance center thickness*/ 0.2, /*radius first surface*/28.49,
		/*radius second surface*/ -20.03, /*radius third surface*/ -81.41, /*edge thickness*/4.04, /*material first*/ mGlasses.getNBAK1_S1(),
		/*material second*/ mGlasses.getNSF8_S1(),/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*stop*/3.5, /*numerical aperture*/0.14,
		/*coating*/ "MgF2",	/*coating specification*/ 1.75,	/*power wavelength*/ 632.8, /*power PV*/ 1.5,/*curvature wavelength*/ 632.8,
		/*curvature PV*/ 4, /*bevel*/ "Protective bevel as needed",	/*type*/ "achromatic lens",	/*min wavelength*/ 400.0, /*max wavelength*/ 700.0,
		/*price*/63.50, /*wavelength to trace*/ 550.0);

	EO49764.buildLensThreeSurfaces(/*lens catalog*/ "EO", /*catalog number*/ 49764, /*diameter*/12.70, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.025,/* focallength*/50.80,
		/* tolerance focal length*/ 2.0, /*back focal length*/48.86, /*design wavelength*/ 587.6, /*free aperture CA*/11.70,/*min centering*/ 0.0,
		/*max centering*/1.0,  /*first thickness*/2.50,	/*second thickness*/1.50, /*tolerance center thickness*/ 0.2, /*radius first surface*/33.165,
		/*radius second surface*/ -23.975, /*radius third surface*/ -89.025, /*edge thickness*/3.16, /*material first*/ mGlasses.getNBAK1_S1(),
		/*material second*/ mGlasses.getNSF15_S1(),/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*stop*/4.00, /*numerical aperture*/0.13,
		/*coating*/ "MgF2",	/*coating specification*/ 1.75,	/*power wavelength*/ 632.8, /*power PV*/ 1.5,/*curvature wavelength*/ 632.8,
		/*curvature PV*/ 4, /*bevel*/ "Protective bevel as needed",	/*type*/ "achromatic lens",	/*min wavelength*/ 400.0, /*max wavelength*/ 700.0,
		/*price*/63.50, /*wavelength to trace*/ 550.0);

	EO83415.buildLensThreeSurfaces(/*lens catalog*/ "EO", /*catalog number*/ 83415, /*diameter*/12.70, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.025,/* focallength*/125.00,
		/* tolerance focal length*/ 2.0, /*back focal length*/121.95, /*design wavelength*/ 587.6, /*free aperture CA*/11.70,/*min centering*/ 0.0,
		/*max centering*/1.0,  /*first thickness*/4.50,	/*second thickness*/2.00, /*tolerance center thickness*/ 0.2, /*radius first surface*/76.92,
		/*radius second surface*/ 55.48, /*radius third surface*/ 162.59, /*edge thickness*/6.11, /*material first*/ mGlasses.getNBK7_S1(),
		/*material second*/ mGlasses.getNSF5_S1(),/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*stop*/9.84, /*numerical aperture*/0.05,
		/*coating*/ "MgF2",	/*coating specification*/ 1.75,	/*power wavelength*/ 632.8, /*power PV*/ 1.5,/*curvature wavelength*/ 632.8,
		/*curvature PV*/ 4, /*bevel*/ "Protective bevel as needed",	/*type*/ "achromatic lens",	/*min wavelength*/ 400.0, /*max wavelength*/ 700.0,
		/*price*/63.50, /*wavelength to trace*/ 550.0);

	EO65551.buildLensThreeSurfaces(/*lens catalog*/ "EO", /*catalog number*/ 65551, /*diameter*/15.00, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.025,/* focallength*/15.00,
		/* tolerance focal length*/ 2.0, /*back focal length*/8.57, /*design wavelength*/ 587.6, /*free aperture CA*/14.00,/*min centering*/ 0.0,
		/*max centering*/1.0,  /*first thickness*/9.86,	/*second thickness*/3.00, /*tolerance center thickness*/ 0.2, /*radius first surface*/11.393,
		/*radius second surface*/ -8.523, /*radius third surface*/ -24.69, /*edge thickness*/8.88, /*material first*/ mGlasses.getNBASF64_S1(),
		/*material second*/ mGlasses.getNSF66_S1(),/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*stop*/1.00, /*numerical aperture*/0.50,
		/*coating*/ "MgF2",	/*coating specification*/ 1.75,	/*power wavelength*/ 632.8, /*power PV*/ 1.5,/*curvature wavelength*/ 632.8,
		/*curvature PV*/ 4, /*bevel*/ "Protective bevel as needed",	/*type*/ "achromatic lens",	/*min wavelength*/ 400.0, /*max wavelength*/ 700.0,
		/*price*/99.50, /*wavelength to trace*/ 550.0);

	EO49929.buildLensThreeSurfaces(/*lens catalog*/ "EO", /*catalog number*/ 49929, /*diameter*/15.00, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.025,/* focallength*/20.00,
		/* tolerance focal length*/ 2.0, /*back focal length*/15.34, /*design wavelength*/ 587.6, /*free aperture CA*/14.00,/*min centering*/ 0.0,
		/*max centering*/1.0,  /*first thickness*/6.80,	/*second thickness*/2.00, /*tolerance center thickness*/ 0.2, /*radius first surface*/14.01,
		/*radius second surface*/ -11.36, /*radius third surface*/ -44.21, /*edge thickness*/5.98, /*material first*/ mGlasses.getNBAF10_S1(),
		/*material second*/ mGlasses.getNSF57_S1(),/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*stop*/1.33, /*numerical aperture*/0.38,
		/*coating*/ "MgF2",	/*coating specification*/ 1.75,	/*power wavelength*/ 632.8, /*power PV*/ 1.5,/*curvature wavelength*/ 632.8,
		/*curvature PV*/ 4, /*bevel*/ "Protective bevel as needed",	/*type*/ "achromatic lens",	/*min wavelength*/ 400.0, /*max wavelength*/ 700.0,
		/*price*/75.00, /*wavelength to trace*/ 550.0);

	//EO45174.buildLensThreeSurfaces(/*lens catalog*/ "EO", /*catalog number*/ 45174, /*diameter*/15.00, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.025,/* focallength*/25.00,		//Glas 1 nicht im Glaskatalog
	//	/* tolerance focal length*/ 2.0, /*back focal length*/20.98, /*design wavelength*/ 587.6, /*free aperture CA*/14.00,/*min centering*/ 0.0,
	//	/*max centering*/1.0,  /*first thickness*/6.27,	/*second thickness*/1.76, /*tolerance center thickness*/ 0.2, /*radius first surface*/17.97,
	//	/*radius second surface*/ -11.20, /*radius third surface*/ -85.31, /*edge thickness*/6.06, /*material first*/ glasses.getSBaH11_S1(),
	//	/*material second*/ glasses.getNSF10_S1(),/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*stop*/1.67, /*numerical aperture*/0.30,
	//	/*coating*/ "MgF2",	/*coating specification*/ 1.75,	/*power wavelength*/ 632.8, /*power PV*/ 1.5,/*curvature wavelength*/ 632.8,
	//	/*curvature PV*/ 4, /*bevel*/ "Protective bevel as needed",	/*type*/ "achromatic lens",	/*min wavelength*/ 400.0, /*max wavelength*/ 700.0,
	//	/*price*/75.00, /*wavelength to trace*/ 550.0);

	EO32720.buildLensThreeSurfaces(/*lens catalog*/ "EO", /*catalog number*/ 32720, /*diameter*/15.00, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.025,/* focallength*/30.00,
		/* tolerance focal length*/ 2.0, /*back focal length*/25.78, /*design wavelength*/ 587.6, /*free aperture CA*/14.00,/*min centering*/ 0.0,
		/*max centering*/1.0,  /*first thickness*/6.00,	/*second thickness*/1.50, /*tolerance center thickness*/ 0.2, /*radius first surface*/20.72,
		/*radius second surface*/ -13.17, /*radius third surface*/ -128.44, /*edge thickness*/5.88, /*material first*/ mGlasses.getNBAF10_S1(),
		/*material second*/ mGlasses.getNSF10_S1(),/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*stop*/2.00, /*numerical aperture*/0.25,
		/*coating*/ "MgF2",	/*coating specification*/ 1.75,	/*power wavelength*/ 632.8, /*power PV*/ 1.5,/*curvature wavelength*/ 632.8,
		/*curvature PV*/ 4, /*bevel*/ "Protective bevel as needed",	/*type*/ "achromatic lens",	/*min wavelength*/ 400.0, /*max wavelength*/ 700.0,
		/*price*/75.00, /*wavelength to trace*/ 550.0);

	EO45103.buildLensThreeSurfaces(/*lens catalog*/ "EO", /*catalog number*/ 45103, /*diameter*/15.00, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.025,/* focallength*/40.00,
		/* tolerance focal length*/ 2.0, /*back focal length*/35.63, /*design wavelength*/ 587.6, /*free aperture CA*/14.00,/*min centering*/ 0.0,
		/*max centering*/1.0,  /*first thickness*/5.98,	/*second thickness*/1.60, /*tolerance center thickness*/ 0.2, /*radius first surface*/26.97,
		/*radius second surface*/ -17.64, /*radius third surface*/ -205.03, /*edge thickness*/6.38, /*material first*/ mGlasses.getNBAF10_S1(),
		/*material second*/ mGlasses.getNSF10_S1(),/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*stop*/2.67, /*numerical aperture*/0.19,
		/*coating*/ "MgF2",	/*coating specification*/ 1.75,	/*power wavelength*/ 632.8, /*power PV*/ 1.5,/*curvature wavelength*/ 632.8,
		/*curvature PV*/ 4, /*bevel*/ "Protective bevel as needed",	/*type*/ "achromatic lens",	/*min wavelength*/ 400.0, /*max wavelength*/ 700.0,
		/*price*/75.00, /*wavelength to trace*/ 550.0);

	EO45138.buildLensThreeSurfaces(/*lens catalog*/ "EO", /*catalog number*/ 45138, /*diameter*/15.00, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.025,/* focallength*/50.00,
		/* tolerance focal length*/ 2.0, /*back focal length*/46.17, /*design wavelength*/ 587.6, /*free aperture CA*/14.00,/*min centering*/ 0.0,
		/*max centering*/1.0,  /*first thickness*/5.00,	/*second thickness*/1.50, /*tolerance center thickness*/ 0.2, /*radius first surface*/26.81,
		/*radius second surface*/ -23.82, /*radius third surface*/ -90.79, /*edge thickness*/5.12, /*material first*/ mGlasses.getNBK7_S1(),
		/*material second*/ mGlasses.getNSF5_S1(),/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*stop*/3.33, /*numerical aperture*/0.15,
		/*coating*/ "MgF2",	/*coating specification*/ 1.75,	/*power wavelength*/ 632.8, /*power PV*/ 1.5,/*curvature wavelength*/ 632.8,
		/*curvature PV*/ 4, /*bevel*/ "Protective bevel as needed",	/*type*/ "achromatic lens",	/*min wavelength*/ 400.0, /*max wavelength*/ 700.0,
		/*price*/75.00, /*wavelength to trace*/ 550.0);

	EO49930.buildLensThreeSurfaces(/*lens catalog*/ "EO", /*catalog number*/ 49930, /*diameter*/15.00, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.025,/* focallength*/60.00,
		/* tolerance focal length*/ 2.0, /*back focal length*/57.48, /*design wavelength*/ 587.6, /*free aperture CA*/14.00,/*min centering*/ 0.0,
		/*max centering*/1.0,  /*first thickness*/3.50,	/*second thickness*/2.00, /*tolerance center thickness*/ 0.2, /*radius first surface*/37.23,
		/*radius second surface*/ -26.69, /*radius third surface*/ -76.36, /*edge thickness*/4.37, /*material first*/ mGlasses.getNBK7_S1(),
		/*material second*/ mGlasses.getNSF5_S1(),/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*stop*/4.00, /*numerical aperture*/0.13,
		/*coating*/ "MgF2",	/*coating specification*/ 1.75,	/*power wavelength*/ 632.8, /*power PV*/ 1.5,/*curvature wavelength*/ 632.8,
		/*curvature PV*/ 4, /*bevel*/ "Protective bevel as needed",	/*type*/ "achromatic lens",	/*min wavelength*/ 400.0, /*max wavelength*/ 700.0,
		/*price*/75.00, /*wavelength to trace*/ 550.0);

	EO45139.buildLensThreeSurfaces(/*lens catalog*/ "EO", /*catalog number*/ 45139, /*diameter*/15.00, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.025,/* focallength*/75.00,
		/* tolerance focal length*/ 2.0, /*back focal length*/70.78, /*design wavelength*/ 587.6, /*free aperture CA*/14.00,/*min centering*/ 0.0,
		/*max centering*/1.0,  /*first thickness*/5.00,	/*second thickness*/2.50, /*tolerance center thickness*/ 0.2, /*radius first surface*/39.61,
		/*radius second surface*/ -36.46, /*radius third surface*/ -145.02, /*edge thickness*/6.59, /*material first*/ mGlasses.getNBK7_S1(),
		/*material second*/ mGlasses.getNSF5_S1(),/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*stop*/5.00, /*numerical aperture*/0.10,
		/*coating*/ "MgF2",	/*coating specification*/ 1.75,	/*power wavelength*/ 632.8, /*power PV*/ 1.5,/*curvature wavelength*/ 632.8,
		/*curvature PV*/ 4, /*bevel*/ "Protective bevel as needed",	/*type*/ "achromatic lens",	/*min wavelength*/ 400.0, /*max wavelength*/ 700.0,
		/*price*/75.00, /*wavelength to trace*/ 550.0);

	EO45266.buildLensThreeSurfaces(/*lens catalog*/ "EO", /*catalog number*/ 45266, /*diameter*/18.00, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.025,/* focallength*/125.00,
		/* tolerance focal length*/ 2.0, /*back focal length*/121.95, /*design wavelength*/ 587.6, /*free aperture CA*/17.00,/*min centering*/ 0.0,
		/*max centering*/1.0,  /*first thickness*/4.50,	/*second thickness*/2.00, /*tolerance center thickness*/ 0.2, /*radius first surface*/76.92,
		/*radius second surface*/ -55.48, /*radius third surface*/ -162.59, /*edge thickness*/5.72, /*material first*/ mGlasses.getNBK7_S1(),
		/*material second*/ mGlasses.getNSF5_S1(),/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*stop*/6.94, /*numerical aperture*/0.07,
		/*coating*/ "MgF2",	/*coating specification*/ 1.75,	/*power wavelength*/ 632.8, /*power PV*/ 1.5,/*curvature wavelength*/ 632.8,
		/*curvature PV*/ 4, /*bevel*/ "Protective bevel as needed",	/*type*/ "achromatic lens",	/*min wavelength*/ 400.0, /*max wavelength*/ 700.0,
		/*price*/76.50, /*wavelength to trace*/ 550.0);

	EO49931.buildLensThreeSurfaces(/*lens catalog*/ "EO", /*catalog number*/ 49931, /*diameter*/18.00, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.025,/* focallength*/22.50,
		/* tolerance focal length*/ 2.0, /*back focal length*/16.39, /*design wavelength*/ 587.6, /*free aperture CA*/17.00,/*min centering*/ 0.0,
		/*max centering*/1.0,  /*first thickness*/8.70,	/*second thickness*/3.00, /*tolerance center thickness*/ 0.2, /*radius first surface*/15.83,
		/*radius second surface*/ -12.65, /*radius third surface*/ -47.42, /*edge thickness*/8.03, /*material first*/ mGlasses.getNBAF10_S1(),
		/*material second*/ mGlasses.getNSF57_S1(),/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*stop*/1.25, /*numerical aperture*/0.40,
		/*coating*/ "MgF2",	/*coating specification*/ 1.75,	/*power wavelength*/ 632.8, /*power PV*/ 1.5,/*curvature wavelength*/ 632.8,
		/*curvature PV*/ 4, /*bevel*/ "Protective bevel as needed",	/*type*/ "achromatic lens",	/*min wavelength*/ 400.0, /*max wavelength*/ 700.0,
		/*price*/76.50, /*wavelength to trace*/ 550.0);

	EO45412.buildLensThreeSurfaces(/*lens catalog*/ "EO", /*catalog number*/ 45412, /*diameter*/18.00, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.025,/* focallength*/27.00,
		/* tolerance focal length*/ 2.0, /*back focal length*/21.74, /*design wavelength*/ 587.6, /*free aperture CA*/17.00,/*min centering*/ 0.0,
		/*max centering*/1.0,  /*first thickness*/7.67,	/*second thickness*/1.60, /*tolerance center thickness*/ 0.2, /*radius first surface*/18.70,
		/*radius second surface*/ -13.11, /*radius third surface*/ -119.12, /*edge thickness*/6.62, /*material first*/ mGlasses.getNBAF10_S1(),
		/*material second*/ mGlasses.getNSF10_S1(),/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*stop*/1.5, /*numerical aperture*/0.33,
		/*coating*/ "MgF2",	/*coating specification*/ 1.75,	/*power wavelength*/ 632.8, /*power PV*/ 1.5,/*curvature wavelength*/ 632.8,
		/*curvature PV*/ 4, /*bevel*/ "Protective bevel as needed",	/*type*/ "achromatic lens",	/*min wavelength*/ 400.0, /*max wavelength*/ 700.0,
		/*price*/76.50, /*wavelength to trace*/ 550.0);

	EO45348.buildLensThreeSurfaces(/*lens catalog*/ "EO", /*catalog number*/ 45348, /*diameter*/18.00, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.025,/* focallength*/30.00,
		/* tolerance focal length*/ 2.0, /*back focal length*/24.97, /*design wavelength*/ 587.6, /*free aperture CA*/17.00,/*min centering*/ 0.0,
		/*max centering*/1.0,  /*first thickness*/6.91,	/*second thickness*/2.00, /*tolerance center thickness*/ 0.2, /*radius first surface*/20.73,
		/*radius second surface*/ -14.31, /*radius third surface*/ -133.58, /*edge thickness*/6.55, /*material first*/ mGlasses.getNBAF10_S1(),
		/*material second*/ mGlasses.getNSF10_S1(),/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*stop*/1.67, /*numerical aperture*/0.30,
		/*coating*/ "MgF2",	/*coating specification*/ 1.75,	/*power wavelength*/ 632.8, /*power PV*/ 1.5,/*curvature wavelength*/ 632.8,
		/*curvature PV*/ 4, /*bevel*/ "Protective bevel as needed",	/*type*/ "achromatic lens",	/*min wavelength*/ 400.0, /*max wavelength*/ 700.0,
		/*price*/76.50, /*wavelength to trace*/ 550.0);

	EO45413.buildLensThreeSurfaces(/*lens catalog*/ "EO", /*catalog number*/ 45413, /*diameter*/18.00, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.025,/* focallength*/35.00,
		/* tolerance focal length*/ 2.0, /*back focal length*/30.72, /*design wavelength*/ 587.6, /*free aperture CA*/17.00,/*min centering*/ 0.0,
		/*max centering*/1.0,  /*first thickness*/6.01,	/*second thickness*/1.60, /*tolerance center thickness*/ 0.2, /*radius first surface*/24.26,
		/*radius second surface*/ -16.23, /*radius third surface*/ -152.99, /*edge thickness*/5.61, /*material first*/ mGlasses.getNBAF10_S1(),
		/*material second*/ mGlasses.getNSF10_S1(),/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*stop*/1.94, /*numerical aperture*/0.26,
		/*coating*/ "MgF2",	/*coating specification*/ 1.75,	/*power wavelength*/ 632.8, /*power PV*/ 1.5,/*curvature wavelength*/ 632.8,
		/*curvature PV*/ 4, /*bevel*/ "Protective bevel as needed",	/*type*/ "achromatic lens",	/*min wavelength*/ 400.0, /*max wavelength*/ 700.0,
		/*price*/76.50, /*wavelength to trace*/ 550.0);

	EO45104.buildLensThreeSurfaces(/*lens catalog*/ "EO", /*catalog number*/ 45104, /*diameter*/18.00, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.025,/* focallength*/40.00,
		/* tolerance focal length*/ 2.0, /*back focal length*/35.63, /*design wavelength*/ 587.6, /*free aperture CA*/17.00,/*min centering*/ 0.0,
		/*max centering*/1.0,  /*first thickness*/5.98,	/*second thickness*/1.60, /*tolerance center thickness*/ 0.2, /*radius first surface*/26.97,
		/*radius second surface*/ -17.64, /*radius third surface*/ -205.03, /*edge thickness*/5.84, /*material first*/ mGlasses.getNBAF10_S1(),
		/*material second*/ mGlasses.getNSF10_S1(),/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*stop*/2.22, /*numerical aperture*/0.23,
		/*coating*/ "MgF2",	/*coating specification*/ 1.75,	/*power wavelength*/ 632.8, /*power PV*/ 1.5,/*curvature wavelength*/ 632.8,
		/*curvature PV*/ 4, /*bevel*/ "Protective bevel as needed",	/*type*/ "achromatic lens",	/*min wavelength*/ 400.0, /*max wavelength*/ 700.0,
		/*price*/76.50, /*wavelength to trace*/ 550.0);

	EO32913.buildLensThreeSurfaces(/*lens catalog*/ "EO", /*catalog number*/ 32913, /*diameter*/18.00, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.025,/* focallength*/50.00,
		/* tolerance focal length*/ 2.0, /*back focal length*/45.24, /*design wavelength*/ 587.6, /*free aperture CA*/17.00,/*min centering*/ 0.0,
		/*max centering*/1.0,  /*first thickness*/5.00,	/*second thickness*/2.30, /*tolerance center thickness*/ 0.2, /*radius first surface*/27.12,
		/*radius second surface*/ -25.66, /*radius third surface*/ -538.70, /*edge thickness*/5.69, /*material first*/ mGlasses.getNSSK8_S1(),
		/*material second*/ mGlasses.getNSF10_S1(),/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*stop*/2.78, /*numerical aperture*/0.18,
		/*coating*/ "MgF2",	/*coating specification*/ 1.75,	/*power wavelength*/ 632.8, /*power PV*/ 1.5,/*curvature wavelength*/ 632.8,
		/*curvature PV*/ 4, /*bevel*/ "Protective bevel as needed",	/*type*/ "achromatic lens",	/*min wavelength*/ 400.0, /*max wavelength*/ 700.0,
		/*price*/76.50, /*wavelength to trace*/ 550.0);

	EO45349.buildLensThreeSurfaces(/*lens catalog*/ "EO", /*catalog number*/ 45349, /*diameter*/18.00, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.025,/* focallength*/60.00,
		/* tolerance focal length*/ 2.0, /*back focal length*/56.79, /*design wavelength*/ 587.6, /*free aperture CA*/17.00,/*min centering*/ 0.0,
		/*max centering*/1.0,  /*first thickness*/3.85,	/*second thickness*/2.00, /*tolerance center thickness*/ 0.2, /*radius first surface*/42.51,
		/*radius second surface*/ -26.24, /*radius third surface*/ -226.77, /*edge thickness*/4.71, /*material first*/ mGlasses.getNBAF10_S1(),
		/*material second*/ mGlasses.getNSF10_S1(),/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*stop*/3.33, /*numerical aperture*/0.15,
		/*coating*/ "MgF2",	/*coating specification*/ 1.75,	/*power wavelength*/ 632.8, /*power PV*/ 1.5,/*curvature wavelength*/ 632.8,
		/*curvature PV*/ 4, /*bevel*/ "Protective bevel as needed",	/*type*/ "achromatic lens",	/*min wavelength*/ 400.0, /*max wavelength*/ 700.0,
		/*price*/76.50, /*wavelength to trace*/ 550.0);

	EO45350.buildLensThreeSurfaces(/*lens catalog*/ "EO", /*catalog number*/ 45350, /*diameter*/18.00, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.025,/* focallength*/75.00,
		/* tolerance focal length*/ 2.0, /*back focal length*/72.15, /*design wavelength*/ 587.6, /*free aperture CA*/17.00,/*min centering*/ 0.0,
		/*max centering*/1.0,  /*first thickness*/3.27,	/*second thickness*/2.00, /*tolerance center thickness*/ 0.2, /*radius first surface*/53.03,
		/*radius second surface*/ -32.72, /*radius third surface*/ -288.05, /*edge thickness*/4.36, /*material first*/ mGlasses.getNBAF10_S1(),
		/*material second*/ mGlasses.getNSF10_S1(),/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*stop*/4.17, /*numerical aperture*/0.12,
		/*coating*/ "MgF2",	/*coating specification*/ 1.75,	/*power wavelength*/ 632.8, /*power PV*/ 1.5,/*curvature wavelength*/ 632.8,
		/*curvature PV*/ 4, /*bevel*/ "Protective bevel as needed",	/*type*/ "achromatic lens",	/*min wavelength*/ 400.0, /*max wavelength*/ 700.0,
		/*price*/76.50, /*wavelength to trace*/ 550.0);

	EO32915.buildLensThreeSurfaces(/*lens catalog*/ "EO", /*catalog number*/ 32915, /*diameter*/18.00, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.025,/* focallength*/80.00,
		/* tolerance focal length*/ 2.0, /*back focal length*/76.52, /*design wavelength*/ 587.6, /*free aperture CA*/17.00,/*min centering*/ 0.0,
		/*max centering*/1.0,  /*first thickness*/5.00,	/*second thickness*/2.50, /*tolerance center thickness*/ 0.2, /*radius first surface*/49.67,
		/*radius second surface*/ -34.73, /*radius third surface*/ -100.11, /*edge thickness*/6.27, /*material first*/ mGlasses.getNBK7_S1(),
		/*material second*/ mGlasses.getNSF5_S1(),/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*stop*/4.44, /*numerical aperture*/0.11,
		/*coating*/ "MgF2",	/*coating specification*/ 1.75,	/*power wavelength*/ 632.8, /*power PV*/ 1.5,/*curvature wavelength*/ 632.8,
		/*curvature PV*/ 4, /*bevel*/ "Protective bevel as needed",	/*type*/ "achromatic lens",	/*min wavelength*/ 400.0, /*max wavelength*/ 700.0,
		/*price*/76.50, /*wavelength to trace*/ 550.0);

	EO65552.buildLensThreeSurfaces(/*lens catalog*/ "EO", /*catalog number*/ 65552, /*diameter*/20.00, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.025,/* focallength*/20.00,
		/* tolerance focal length*/ 2.0, /*back focal length*/11.73, /*design wavelength*/ 587.6, /*free aperture CA*/19.00,/*min centering*/ 0.0,
		/*max centering*/1.0,  /*first thickness*/12.57,	/*second thickness*/4.00, /*tolerance center thickness*/ 0.2, /*radius first surface*/15.134,
		/*radius second surface*/ -11.18, /*radius third surface*/ -33.15, /*edge thickness*/11.25, /*material first*/ mGlasses.getNBASF64_S1(),
		/*material second*/ mGlasses.getNSF66_S1(),/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*stop*/1.00, /*numerical aperture*/0.50,
		/*coating*/ "MgF2",	/*coating specification*/ 1.75,	/*power wavelength*/ 632.8, /*power PV*/ 1.5,/*curvature wavelength*/ 632.8,
		/*curvature PV*/ 4, /*bevel*/ "Protective bevel as needed",	/*type*/ "achromatic lens",	/*min wavelength*/ 400.0, /*max wavelength*/ 700.0,
		/*price*/110.00, /*wavelength to trace*/ 550.0);

	EO49932.buildLensThreeSurfaces(/*lens catalog*/ "EO", /*catalog number*/ 49932, /*diameter*/20.00, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.025,/* focallength*/25.00,
		/* tolerance focal length*/ 2.0, /*back focal length*/18.71, /*design wavelength*/ 587.6, /*free aperture CA*/19.00,/*min centering*/ 0.0,
		/*max centering*/1.0,  /*first thickness*/9.50,	/*second thickness*/2.50, /*tolerance center thickness*/ 0.2, /*radius first surface*/18.03,
		/*radius second surface*/ -13.27, /*radius third surface*/ -55.46, /*edge thickness*/8.06, /*material first*/ mGlasses.getNBAF10_S1(),
		/*material second*/ mGlasses.getNSF6_S1(),/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*stop*/1.25, /*numerical aperture*/0.40,
		/*coating*/ "MgF2",	/*coating specification*/ 1.75,	/*power wavelength*/ 632.8, /*power PV*/ 1.5,/*curvature wavelength*/ 632.8,
		/*curvature PV*/ 4, /*bevel*/ "Protective bevel as needed",	/*type*/ "achromatic lens",	/*min wavelength*/ 400.0, /*max wavelength*/ 700.0,
		/*price*/79.00, /*wavelength to trace*/ 550.0);

	//EO45175.buildLensThreeSurfaces(/*lens catalog*/ "EO", /*catalog number*/ 45175, /*diameter*/20.00, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.025,/* focallength*/30.00,
	//	/* tolerance focal length*/ 2.0, /*back focal length*/24.70, /*design wavelength*/ 587.6, /*free aperture CA*/19.00,/*min centering*/ 0.0,
	//	/*max centering*/1.0,  /*first thickness*/8.40,	/*second thickness*/1.76, /*tolerance center thickness*/ 0.2, /*radius first surface*/21.41,
	//	/*radius second surface*/ -13.75, /*radius third surface*/ -105.58, /*edge thickness*/7.21, /*material first*/ glasses.getSBaH11_S1(),				//Glas 1 nicht im Glaskatalog
	//	/*material second*/ glasses.getNSF10_S1(),/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*stop*/1.5, /*numerical aperture*/0.33,
	//	/*coating*/ "MgF2",	/*coating specification*/ 1.75,	/*power wavelength*/ 632.8, /*power PV*/ 1.5,/*curvature wavelength*/ 632.8,
	//	/*curvature PV*/ 4, /*bevel*/ "Protective bevel as needed",	/*type*/ "achromatic lens",	/*min wavelength*/ 400.0, /*max wavelength*/ 700.0,
	//	/*price*/79.00, /*wavelength to trace*/ 550.0);

	//EO45351.buildLensThreeSurfaces(/*lens catalog*/ "EO", /*catalog number*/ 45351, /*diameter*/20.00, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.025,/* focallength*/35.00,			//Glas 1 nicht im Glaskatalog
	//	/* tolerance focal length*/ 2.0, /*back focal length*/29.90, /*design wavelength*/ 587.6, /*free aperture CA*/19.00,/*min centering*/ 0.0,
	//	/*max centering*/1.0,  /*first thickness*/7.33,	/*second thickness*/1.76, /*tolerance center thickness*/ 0.2, /*radius first surface*/24.24,
	//	/*radius second surface*/ -15.96, /*radius third surface*/ -139.78, /*edge thickness*/6.57, /*material first*/ glasses.getSBaH11_S1(),
	//	/*material second*/ glasses.getNSF10_S1(),/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*stop*/1.75, /*numerical aperture*/0.29,
	//	/*coating*/ "MgF2",	/*coating specification*/ 1.75,	/*power wavelength*/ 632.8, /*power PV*/ 1.5,/*curvature wavelength*/ 632.8,
	//	/*curvature PV*/ 4, /*bevel*/ "Protective bevel as needed",	/*type*/ "achromatic lens",	/*min wavelength*/ 400.0, /*max wavelength*/ 700.0,
	//	/*price*/79.00, /*wavelength to trace*/ 550.0);

	EO32722.buildLensThreeSurfaces(/*lens catalog*/ "EO", /*catalog number*/ 32722, /*diameter*/20.00, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.025,/* focallength*/40.00,
		/* tolerance focal length*/ 2.0, /*back focal length*/34.30, /*design wavelength*/ 587.6, /*free aperture CA*/19.00,/*min centering*/ 0.0,
		/*max centering*/1.0,  /*first thickness*/8.00,	/*second thickness*/2.00, /*tolerance center thickness*/ 0.2, /*radius first surface*/27.63,
		/*radius second surface*/ -17.58, /*radius third surface*/ -171.25, /*edge thickness*/7.83, /*material first*/ mGlasses.getNBAF10_S1(),
		/*material second*/ mGlasses.getNSF10_S1(),/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*stop*/2.00, /*numerical aperture*/0.25,
		/*coating*/ "MgF2",	/*coating specification*/ 1.75,	/*power wavelength*/ 632.8, /*power PV*/ 1.5,/*curvature wavelength*/ 632.8,
		/*curvature PV*/ 4, /*bevel*/ "Protective bevel as needed",	/*type*/ "achromatic lens",	/*min wavelength*/ 400.0, /*max wavelength*/ 700.0,
		/*price*/79.00, /*wavelength to trace*/ 550.0);

	EO49933.buildLensThreeSurfaces(/*lens catalog*/ "EO", /*catalog number*/ 49933, /*diameter*/20.00, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.025,/* focallength*/50.00,
		/* tolerance focal length*/ 2.0, /*back focal length*/46.93, /*design wavelength*/ 587.6, /*free aperture CA*/19.00,/*min centering*/ 0.0,
		/*max centering*/1.0,  /*first thickness*/4.80,	/*second thickness*/2.00, /*tolerance center thickness*/ 0.2, /*radius first surface*/36.92,
		/*radius second surface*/ -25.65, /*radius third surface*/ -77.89, /*edge thickness*/4.78, /*material first*/ mGlasses.getNSSK8_S1(),
		/*material second*/ mGlasses.getNSF56_S1(),/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*stop*/2.5, /*numerical aperture*/0.20,
		/*coating*/ "MgF2",	/*coating specification*/ 1.75,	/*power wavelength*/ 632.8, /*power PV*/ 1.5,/*curvature wavelength*/ 632.8,
		/*curvature PV*/ 4, /*bevel*/ "Protective bevel as needed",	/*type*/ "achromatic lens",	/*min wavelength*/ 400.0, /*max wavelength*/ 700.0,
		/*price*/79.00, /*wavelength to trace*/ 550.0);

	EO45267.buildLensThreeSurfaces(/*lens catalog*/ "EO", /*catalog number*/ 45267, /*diameter*/20.00, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.025,/* focallength*/60.00,
		/* tolerance focal length*/ 2.0, /*back focal length*/56.61, /*design wavelength*/ 587.6, /*free aperture CA*/19.00,/*min centering*/ 0.0,
		/*max centering*/1.0,  /*first thickness*/5.00,	/*second thickness*/2.00, /*tolerance center thickness*/ 0.2, /*radius first surface*/35.92,
		/*radius second surface*/ -28.12, /*radius third surface*/ -83.79, /*edge thickness*/4.98, /*material first*/ mGlasses.getNBK7_S1(),
		/*material second*/ mGlasses.getNSF5_S1(),/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*stop*/3.00, /*numerical aperture*/0.17,
		/*coating*/ "MgF2",	/*coating specification*/ 1.75,	/*power wavelength*/ 632.8, /*power PV*/ 1.5,/*curvature wavelength*/ 632.8,
		/*curvature PV*/ 4, /*bevel*/ "Protective bevel as needed",	/*type*/ "achromatic lens",	/*min wavelength*/ 400.0, /*max wavelength*/ 700.0,
		/*price*/79.00, /*wavelength to trace*/ 550.0);

	EO49934.buildLensThreeSurfaces(/*lens catalog*/ "EO", /*catalog number*/ 49934, /*diameter*/20.00, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.025,/* focallength*/80.00,
		/* tolerance focal length*/ 2.0, /*back focal length*/77.26, /*design wavelength*/ 587.6, /*free aperture CA*/19.00,/*min centering*/ 0.0,
		/*max centering*/1.0,  /*first thickness*/4.00,	/*second thickness*/2.00, /*tolerance center thickness*/ 0.2, /*radius first surface*/50.49,
		/*radius second surface*/ -37.06, /*radius third surface*/ -102.19, /*edge thickness*/4.51, /*material first*/ mGlasses.getNBK7_S1(),
		/*material second*/ mGlasses.getNSF5_S1(),/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*stop*/4.00, /*numerical aperture*/0.13,
		/*coating*/ "MgF2",	/*coating specification*/ 1.75,	/*power wavelength*/ 632.8, /*power PV*/ 1.5,/*curvature wavelength*/ 632.8,
		/*curvature PV*/ 4, /*bevel*/ "Protective bevel as needed",	/*type*/ "achromatic lens",	/*min wavelength*/ 400.0, /*max wavelength*/ 700.0,
		/*price*/79.00, /*wavelength to trace*/ 550.0);

	EO65553.buildLensThreeSurfaces(/*lens catalog*/ "EO", /*catalog number*/ 65553, /*diameter*/25.00, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.025,/* focallength*/25.00,
		/* tolerance focal length*/ 2.0, /*back focal length*/14.85, /*design wavelength*/ 587.6, /*free aperture CA*/24.00,/*min centering*/ 0.0,
		/*max centering*/1.0,  /*first thickness*/15.33,	/*second thickness*/5.00, /*tolerance center thickness*/ 0.2, /*radius first surface*/18.85,
		/*radius second surface*/ -13.84, /*radius third surface*/ -41.70, /*edge thickness*/13.67, /*material first*/ mGlasses.getNBASF64_S1(),
		/*material second*/ mGlasses.getNSF66_S1(),/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*stop*/1.00, /*numerical aperture*/0.50,
		/*coating*/ "MgF2",	/*coating specification*/ 1.75,	/*power wavelength*/ 632.8, /*power PV*/ 1.5,/*curvature wavelength*/ 632.8,
		/*curvature PV*/ 4, /*bevel*/ "Protective bevel as needed",	/*type*/ "achromatic lens",	/*min wavelength*/ 400.0, /*max wavelength*/ 700.0,
		/*price*/130.00, /*wavelength to trace*/ 550.0);

	EO45211.buildLensThreeSurfaces(/*lens catalog*/ "EO", /*catalog number*/ 45211, /*diameter*/25.00, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.025,/* focallength*/30.0,
		/* tolerance focal length*/ 2.0, /*back focal length*/22.23, /*design wavelength*/ 587.6, /*free aperture CA*/24.00,/*min centering*/ 0.0,
		/*max centering*/1.0,  /*first thickness*/11.04,	/*second thickness*/3.0, /*tolerance center thickness*/ 0.2, /*radius first surface*/21.17,
		/*radius second surface*/ -16.08, /*radius third surface*/ -118.66, /*edge thickness*/9.30, /*material first*/ mGlasses.getNBAF10_S1(),
		/*material second*/ mGlasses.getNSF10_S1(),/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*stop*/1.2, /*numerical aperture*/0.42,
		/*coating*/ "MgF2",	/*coating specification*/ 1.75,	/*power wavelength*/ 632.8, /*power PV*/ 1.5,/*curvature wavelength*/ 632.8,
		/*curvature PV*/ 4, /*bevel*/ "Protective bevel as needed",	/*type*/ "achromatic lens",	/*min wavelength*/ 400.0, /*max wavelength*/ 700.0,
		/*price*/90.00, /*wavelength to trace*/ 550.0);

	//EO32319.buildLensThreeSurfaces(/*lens catalog*/ "EO", /*catalog number*/ 32319, /*diameter*/25.00, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.025,/* focallength*/35.00,
	//	/* tolerance focal length*/ 2.0, /*back focal length*/27.55, /*design wavelength*/ 587.6, /*free aperture CA*/24.00,/*min centering*/ 0.0,
	//	/*max centering*/1.0,  /*first thickness*/11.00,	/*second thickness*/2.50, /*tolerance center thickness*/ 0.2, /*radius first surface*/24.47,
	//	/*radius second surface*/ -16.49, /*radius third surface*/ -131.65, /*edge thickness*/9.47, /*material first*/ glasses.getSBaH11_S1(),				//Glas 1 nicht im Glaskatalog
	//	/*material second*/ glasses.getNSF10_S1(),/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*stop*/1.4, /*numerical aperture*/0.36,
	//	/*coating*/ "MgF2",	/*coating specification*/ 1.75,	/*power wavelength*/ 632.8, /*power PV*/ 1.5,/*curvature wavelength*/ 632.8,
	//	/*curvature PV*/ 4, /*bevel*/ "Protective bevel as needed",	/*type*/ "achromatic lens",	/*min wavelength*/ 400.0, /*max wavelength*/ 700.0,
	//	/*price*/90.00, /*wavelength to trace*/ 550.0);

	//EO32321.buildLensThreeSurfaces(/*lens catalog*/ "EO", /*catalog number*/ 32321, /*diameter*/25.00, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.025,/* focallength*/40.00,
	//	/* tolerance focal length*/ 2.0, /*back focal length*/33.26, /*design wavelength*/ 587.6, /*free aperture CA*/24.00,/*min centering*/ 0.0,
	//	/*max centering*/1.0,  /*first thickness*/9.50,	/*second thickness*/2.50, /*tolerance center thickness*/ 0.2, /*radius first surface*/27.97,
	//	/*radius second surface*/ -18.85, /*radius third surface*/ -152.94, /*edge thickness*/8.54, /*material first*/ glasses.getSaBH11_S1(),				//Glas 1 nicht im Glaskatalog
	//	/*material second*/ glasses.getNSF10_S1(),/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*stop*/1.6, /*numerical aperture*/0.31,
	//	/*coating*/ "MgF2",	/*coating specification*/ 1.75,	/*power wavelength*/ 632.8, /*power PV*/ 1.5,/*curvature wavelength*/ 632.8,
	//	/*curvature PV*/ 4, /*bevel*/ "Protective bevel as needed",	/*type*/ "achromatic lens",	/*min wavelength*/ 400.0, /*max wavelength*/ 700.0,
	//	/*price*/90.00, /*wavelength to trace*/ 550.0);

	EO45212.buildLensThreeSurfaces(/*lens catalog*/ "EO", /*catalog number*/ 45212, /*diameter*/25.00, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.025,/* focallength*/45.00,
		/* tolerance focal length*/ 2.0, /*back focal length*/39.28, /*design wavelength*/ 587.6, /*free aperture CA*/24.00,/*min centering*/ 0.0,
		/*max centering*/1.0,  /*first thickness*/7.89,	/*second thickness*/3.00, /*tolerance center thickness*/ 0.2, /*radius first surface*/28.75,
		/*radius second surface*/ -21.38, /*radius third surface*/ -82.92, /*edge thickness*/7.08, /*material first*/ mGlasses.getNSK11_S1(),
		/*material second*/ mGlasses.getNSF5_S1(),/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*stop*/1.8, /*numerical aperture*/0.28,
		/*coating*/ "MgF2",	/*coating specification*/ 1.75,	/*power wavelength*/ 632.8, /*power PV*/ 1.5,/*curvature wavelength*/ 632.8,
		/*curvature PV*/ 4, /*bevel*/ "Protective bevel as needed",	/*type*/ "achromatic lens",	/*min wavelength*/ 400.0, /*max wavelength*/ 700.0,
		/*price*/90.00, /*wavelength to trace*/ 550.0);

	EO32323.buildLensThreeSurfaces(/*lens catalog*/ "EO", /*catalog number*/ 32323, /*diameter*/25.00, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.025,/* focallength*/50.00,
		/* tolerance focal length*/ 2.0, /*back focal length*/43.53, /*design wavelength*/ 587.6, /*free aperture CA*/24.00,/*min centering*/ 0.0,
		/*max centering*/1.0,  /*first thickness*/9.00,	/*second thickness*/2.50, /*tolerance center thickness*/ 0.2, /*radius first surface*/34.53,
		/*radius second surface*/ -21.98, /*radius third surface*/ -214.63, /*edge thickness*/8.79, /*material first*/ mGlasses.getNBAF10_S1(),
		/*material second*/ mGlasses.getNSF10_S1(),/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*stop*/2.00, /*numerical aperture*/0.25,
		/*coating*/ "MgF2",	/*coating specification*/ 1.75,	/*power wavelength*/ 632.8, /*power PV*/ 1.5,/*curvature wavelength*/ 632.8,
		/*curvature PV*/ 4, /*bevel*/ "Protective bevel as needed",	/*type*/ "achromatic lens",	/*min wavelength*/ 400.0, /*max wavelength*/ 700.0,
		/*price*/90.00, /*wavelength to trace*/ 550.0);

	EO32724.buildLensThreeSurfaces(/*lens catalog*/ "EO", /*catalog number*/ 32724, /*diameter*/25.00, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.025,/* focallength*/60.00,
		/* tolerance focal length*/ 2.0, /*back focal length*/52.23, /*design wavelength*/ 587.6, /*free aperture CA*/24.00,/*min centering*/ 0.0,
		/*max centering*/1.0,  /*first thickness*/9.00,	/*second thickness*/2.40, /*tolerance center thickness*/ 0.2, /*radius first surface*/31.94,
		/*radius second surface*/ -29.95, /*radius third surface*/ -1029.79, /*edge thickness*/8.78, /*material first*/ mGlasses.getNSSK8_S1(),
		/*material second*/ mGlasses.getNSF10_S1(),/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*stop*/2.4, /*numerical aperture*/0.21,
		/*coating*/ "MgF2",	/*coating specification*/ 1.75,	/*power wavelength*/ 632.8, /*power PV*/ 1.5,/*curvature wavelength*/ 632.8,
		/*curvature PV*/ 4, /*bevel*/ "Protective bevel as needed",	/*type*/ "achromatic lens",	/*min wavelength*/ 400.0, /*max wavelength*/ 700.0,
		/*price*/90.00, /*wavelength to trace*/ 550.0);

	EO32325.buildLensThreeSurfaces(/*lens catalog*/ "EO", /*catalog number*/ 32325, /*diameter*/25.00, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.025,/* focallength*/75.00,
		/* tolerance focal length*/ 2.0, /*back focal length*/70.39, /*design wavelength*/ 587.6, /*free aperture CA*/24.00,/*min centering*/ 0.0,
		/*max centering*/1.0,  /*first thickness*/7.00,	/*second thickness*/2.50, /*tolerance center thickness*/ 0.2, /*radius first surface*/46.44,
		/*radius second surface*/ -33.77, /*radius third surface*/ -95.94, /*edge thickness*/6.97, /*material first*/ mGlasses.getNBK7_S1(),
		/*material second*/ mGlasses.getNSF5_S1(),/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*stop*/3.0, /*numerical aperture*/0.17,
		/*coating*/ "MgF2",	/*coating specification*/ 1.75,	/*power wavelength*/ 632.8, /*power PV*/ 1.5,/*curvature wavelength*/ 632.8,
		/*curvature PV*/ 4, /*bevel*/ "Protective bevel as needed",	/*type*/ "achromatic lens",	/*min wavelength*/ 400.0, /*max wavelength*/ 700.0,
		/*price*/90.00, /*wavelength to trace*/ 550.0);

	EO45213.buildLensThreeSurfaces(/*lens catalog*/ "EO", /*catalog number*/ 45213, /*diameter*/25.0, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.025,/* focallength*/85.00,
		/* tolerance focal length*/ 2.0, /*back focal length*/81.21, /*design wavelength*/ 587.6, /*free aperture CA*/24.00,/*min centering*/ 0.0,
		/*max centering*/1.0,  /*first thickness*/5.01,	/*second thickness*/3.00, /*tolerance center thickness*/ 0.2, /*radius first surface*/55.68,
		/*radius second surface*/ -38.37, /*radius third surface*/ -146.45, /*edge thickness*/6.05, /*material first*/ mGlasses.getNSK11_S1(),
		/*material second*/ mGlasses.getNSF5_S1(),/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*stop*/3.4, /*numerical aperture*/0.15,
		/*coating*/ "MgF2",	/*coating specification*/ 1.75,	/*power wavelength*/ 632.8, /*power PV*/ 1.5,/*curvature wavelength*/ 632.8,
		/*curvature PV*/ 4, /*bevel*/ "Protective bevel as needed",	/*type*/ "achromatic lens",	/*min wavelength*/ 400.0, /*max wavelength*/ 700.0,
		/*price*/90.00, /*wavelength to trace*/ 550.0);

	EO32327.buildLensThreeSurfaces(/*lens catalog*/ "EO", /*catalog number*/ 32327, /*diameter*/25.0, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.025,/* focallength*/100.00,
		/* tolerance focal length*/ 2.0, /*back focal length*/95.92, /*design wavelength*/ 587.6, /*free aperture CA*/24.00,/*min centering*/ 0.0,
		/*max centering*/1.0,  /*first thickness*/6.00,	/*second thickness*/2.50, /*tolerance center thickness*/ 0.2, /*radius first surface*/61.47,
		/*radius second surface*/ -44.64, /*radius third surface*/ -129.94, /*edge thickness*/6.61, /*material first*/ mGlasses.getNBK7_S1(),
		/*material second*/ mGlasses.getNSF5_S1(),/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*stop*/4.00, /*numerical aperture*/0.13,
		/*coating*/ "MgF2",	/*coating specification*/ 1.75,	/*power wavelength*/ 632.8, /*power PV*/ 1.5,/*curvature wavelength*/ 632.8,
		/*curvature PV*/ 4, /*bevel*/ "Protective bevel as needed",	/*type*/ "achromatic lens",	/*min wavelength*/ 400.0, /*max wavelength*/ 700.0,
		/*price*/90.00, /*wavelength to trace*/ 550.0);

	EO32492.buildLensThreeSurfaces(/*lens catalog*/ "EO", /*catalog number*/ 32492, /*diameter*/25.00, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.025,/* focallength*/125.00,
		/* tolerance focal length*/ 2.0, /*back focal length*/120.89, /*design wavelength*/ 587.6, /*free aperture CA*/24.00,/*min centering*/ 0.0,
		/*max centering*/1.0,  /*first thickness*/6.00,	/*second thickness*/2.40, /*tolerance center thickness*/ 0.2, /*radius first surface*/76.28,
		/*radius second surface*/ -54.44, /*radius third surface*/ -162.43, /*edge thickness*/6.89, /*material first*/ mGlasses.getNBK7_S1(),
		/*material second*/ mGlasses.getNSF5_S1(),/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*stop*/5.00, /*numerical aperture*/0.10,
		/*coating*/ "MgF2",	/*coating specification*/ 1.75,	/*power wavelength*/ 632.8, /*power PV*/ 1.5,/*curvature wavelength*/ 632.8,
		/*curvature PV*/ 4, /*bevel*/ "Protective bevel as needed",	/*type*/ "achromatic lens",	/*min wavelength*/ 400.0, /*max wavelength*/ 700.0,
		/*price*/90.00, /*wavelength to trace*/ 550.0);

	EO32494.buildLensThreeSurfaces(/*lens catalog*/ "EO", /*catalog number*/ 32494, /*diameter*/25.00, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.025,/* focallength*/150.00,
		/* tolerance focal length*/ 2.0, /*back focal length*/146.10, /*design wavelength*/ 587.6, /*free aperture CA*/24.00,/*min centering*/ 0.0,
		/*max centering*/1.0,  /*first thickness*/5.70,	/*second thickness*/2.20, /*tolerance center thickness*/ 0.2, /*radius first surface*/91.37,
		/*radius second surface*/ -66.21, /*radius third surface*/ -197.71, /*edge thickness*/6.65, /*material first*/ mGlasses.getNBK7_S1(),
		/*material second*/ mGlasses.getNSF5_S1(),/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*stop*/6.00, /*numerical aperture*/0.08,
		/*coating*/ "MgF2",	/*coating specification*/ 1.75,	/*power wavelength*/ 632.8, /*power PV*/ 1.5,/*curvature wavelength*/ 632.8,
		/*curvature PV*/ 4, /*bevel*/ "Protective bevel as needed",	/*type*/ "achromatic lens",	/*min wavelength*/ 400.0, /*max wavelength*/ 700.0,
		/*price*/90.00, /*wavelength to trace*/ 550.0);

	EO67328.buildLensThreeSurfaces(/*lens catalog*/ "EO", /*catalog number*/ 67328, /*diameter*/25.00, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.025,/* focallength*/160.00,
		/* tolerance focal length*/ 2.0, /*back focal length*/157.87, /*design wavelength*/ 587.6, /*free aperture CA*/24.00,/*min centering*/ 0.0,
		/*max centering*/1.0,  /*first thickness*/3.00,	/*second thickness*/2.50, /*tolerance center thickness*/ 0.2, /*radius first surface*/107.20,
		/*radius second surface*/ -67.90, /*radius third surface*/ -179.23, /*edge thickness*/4.33, /*material first*/ mGlasses.getNBK7_S1(),
		/*material second*/ mGlasses.getNSF5_S1(),/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*stop*/6.4, /*numerical aperture*/0.08,
		/*coating*/ "MgF2",	/*coating specification*/ 1.75,	/*power wavelength*/ 632.8, /*power PV*/ 1.5,/*curvature wavelength*/ 632.8,
		/*curvature PV*/ 4, /*bevel*/ "Protective bevel as needed",	/*type*/ "achromatic lens",	/*min wavelength*/ 400.0, /*max wavelength*/ 700.0,
		/*price*/90.00, /*wavelength to trace*/ 550.0);

	EO32884.buildLensThreeSurfaces(/*lens catalog*/ "EO", /*catalog number*/ 32884, /*diameter*/25.00, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.025,/* focallength*/175.00,
		/* tolerance focal length*/ 2.0, /*back focal length*/179.84, /*design wavelength*/ 587.6, /*free aperture CA*/24.00,/*min centering*/ 0.0,
		/*max centering*/1.0,  /*first thickness*/6.00,	/*second thickness*/3.00, /*tolerance center thickness*/ 0.2, /*radius first surface*/109.16,
		/*radius second surface*/ -79.38, /*radius third surface*/ -226.03, /*edge thickness*/7.94, /*material first*/ mGlasses.getNBK7_S1(),
		/*material second*/ mGlasses.getNSF5_S1(),/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*stop*/7.00, /*numerical aperture*/0.07,
		/*coating*/ "MgF2",	/*coating specification*/ 1.75,	/*power wavelength*/ 632.8, /*power PV*/ 1.5,/*curvature wavelength*/ 632.8,
		/*curvature PV*/ 4, /*bevel*/ "Protective bevel as needed",	/*type*/ "achromatic lens",	/*min wavelength*/ 400.0, /*max wavelength*/ 700.0,
		/*price*/90.00, /*wavelength to trace*/ 550.0);

	EO32917.buildLensThreeSurfaces(/*lens catalog*/ "EO", /*catalog number*/ 32917, /*diameter*/25.00, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.025,/* focallength*/200.00,
		/* tolerance focal length*/ 2.0, /*back focal length*/194.14, /*design wavelength*/ 587.6, /*free aperture CA*/24.00,/*min centering*/ 0.0,
		/*max centering*/1.0,  /*first thickness*/8.50,	/*second thickness*/4.00, /*tolerance center thickness*/ 0.2, /*radius first surface*/124.12,
		/*radius second surface*/ -87.26, /*radius third surface*/ -253.10, /*edge thickness*/11.56, /*material first*/ mGlasses.getNBK7_S1(),
		/*material second*/ mGlasses.getNSF5_S1(),/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*stop*/8.00, /*numerical aperture*/0.06,
		/*coating*/ "MgF2",	/*coating specification*/ 1.75,	/*power wavelength*/ 632.8, /*power PV*/ 1.5,/*curvature wavelength*/ 632.8,
		/*curvature PV*/ 4, /*bevel*/ "Protective bevel as needed",	/*type*/ "achromatic lens",	/*min wavelength*/ 400.0, /*max wavelength*/ 700.0,
		/*price*/90.00, /*wavelength to trace*/ 550.0);

	EO45214.buildLensThreeSurfaces(/*lens catalog*/ "EO", /*catalog number*/ 45214, /*diameter*/25.00, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.025,/* focallength*/225.00,
		/* tolerance focal length*/ 2.0, /*back focal length*/222.69, /*design wavelength*/ 587.6, /*free aperture CA*/24.00,/*min centering*/ 0.0,
		/*max centering*/1.0,  /*first thickness*/3.00,	/*second thickness*/2.50, /*tolerance center thickness*/ 0.2, /*radius first surface*/139.53,
		/*radius second surface*/ -100.21, /*radius third surface*/ -291.32, /*edge thickness*/4.67, /*material first*/ mGlasses.getNBK7_S1(),
		/*material second*/ mGlasses.getNSF5_S1(),/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*stop*/9.00, /*numerical aperture*/0.06,
		/*coating*/ "MgF2",	/*coating specification*/ 1.75,	/*power wavelength*/ 632.8, /*power PV*/ 1.5,/*curvature wavelength*/ 632.8,
		/*curvature PV*/ 4, /*bevel*/ "Protective bevel as needed",	/*type*/ "achromatic lens",	/*min wavelength*/ 400.0, /*max wavelength*/ 700.0,
		/*price*/90.00, /*wavelength to trace*/ 550.0);

	EO32919.buildLensThreeSurfaces(/*lens catalog*/ "EO", /*catalog number*/ 32919, /*diameter*/25.00, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.025,/* focallength*/250.00,
		/* tolerance focal length*/ 2.0, /*back focal length*/246.63, /*design wavelength*/ 587.6, /*free aperture CA*/24.00,/*min centering*/ 0.0,
		/*max centering*/1.0,  /*first thickness*/5.00,	/*second thickness*/2.50, /*tolerance center thickness*/ 0.2, /*radius first surface*/160.73,
		/*radius second surface*/ -105.64, /*radius third surface*/ -295.75, /*edge thickness*/6.75, /*material first*/ mGlasses.getNBK7_S1(),
		/*material second*/ mGlasses.getNSF5_S1(),/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*stop*/10.00, /*numerical aperture*/0.05,
		/*coating*/ "MgF2",	/*coating specification*/ 1.75,	/*power wavelength*/ 632.8, /*power PV*/ 1.5,/*curvature wavelength*/ 632.8,
		/*curvature PV*/ 4, /*bevel*/ "Protective bevel as needed",	/*type*/ "achromatic lens",	/*min wavelength*/ 400.0, /*max wavelength*/ 700.0,
		/*price*/90.00, /*wavelength to trace*/ 550.0);

	EO45414.buildLensThreeSurfaces(/*lens catalog*/ "EO", /*catalog number*/ 45414, /*diameter*/25.00, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.025,/* focallength*/275.00,
		/* tolerance focal length*/ 2.0, /*back focal length*/271.60, /*design wavelength*/ 587.6, /*free aperture CA*/24.00,/*min centering*/ 0.0,
		/*max centering*/1.0,  /*first thickness*/5.00,	/*second thickness*/2.50, /*tolerance center thickness*/ 0.2, /*radius first surface*/171.03,
		/*radius second surface*/ -121.54, /*radius third surface*/ -352.46, /*edge thickness*/6.82, /*material first*/ mGlasses.getNBK7_S1(),
		/*material second*/ mGlasses.getNSF5_S1(),/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*stop*/11.0, /*numerical aperture*/0.05,
		/*coating*/ "MgF2",	/*coating specification*/ 1.75,	/*power wavelength*/ 632.8, /*power PV*/ 1.5,/*curvature wavelength*/ 632.8,
		/*curvature PV*/ 4, /*bevel*/ "Protective bevel as needed",	/*type*/ "achromatic lens",	/*min wavelength*/ 400.0, /*max wavelength*/ 700.0,
		/*price*/90.00, /*wavelength to trace*/ 550.0);

	EO45215.buildLensThreeSurfaces(/*lens catalog*/ "EO", /*catalog number*/ 45215, /*diameter*/25.00, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.025,/* focallength*/300.00,
		/* tolerance focal length*/ 2.0, /*back focal length*/297.73, /*design wavelength*/ 587.6, /*free aperture CA*/24.00,/*min centering*/ 0.0,
		/*max centering*/1.0,  /*first thickness*/3.00,	/*second thickness*/2.50, /*tolerance center thickness*/ 0.2, /*radius first surface*/184.84,
		/*radius second surface*/ -134.06, /*radius third surface*/ -393.98, /*edge thickness*/4.88, /*material first*/ mGlasses.getNBK7_S1(),
		/*material second*/ mGlasses.getNSF5_S1(),/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*stop*/12.00, /*numerical aperture*/0.04,
		/*coating*/ "MgF2",	/*coating specification*/ 1.75,	/*power wavelength*/ 632.8, /*power PV*/ 1.5,/*curvature wavelength*/ 632.8,
		/*curvature PV*/ 4, /*bevel*/ "Protective bevel as needed",	/*type*/ "achromatic lens",	/*min wavelength*/ 400.0, /*max wavelength*/ 700.0,
		/*price*/90.00, /*wavelength to trace*/ 550.0);

	EO45216.buildLensThreeSurfaces(/*lens catalog*/ "EO", /*catalog number*/ 45216, /*diameter*/25.00, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.025,/* focallength*/400.00,
		/* tolerance focal length*/ 2.0, /*back focal length*/397.84, /*design wavelength*/ 587.6, /*free aperture CA*/24.00,/*min centering*/ 0.0,
		/*max centering*/1.0,  /*first thickness*/3.00,	/*second thickness*/2.50, /*tolerance center thickness*/ 0.2, /*radius first surface*/244.65,
		/*radius second surface*/ -179.62, /*radius third surface*/ -534.10, /*edge thickness*/5.03, /*material first*/ mGlasses.getNBK7_S1(),
		/*material second*/ mGlasses.getNSF5_S1(),/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*stop*/16.00, /*numerical aperture*/0.03,
		/*coating*/ "MgF2",	/*coating specification*/ 1.75,	/*power wavelength*/ 632.8, /*power PV*/ 1.5,/*curvature wavelength*/ 632.8,
		/*curvature PV*/ 4, /*bevel*/ "Protective bevel as needed",	/*type*/ "achromatic lens",	/*min wavelength*/ 400.0, /*max wavelength*/ 700.0,
		/*price*/90.00, /*wavelength to trace*/ 550.0);

	EO45268.buildLensThreeSurfaces(/*lens catalog*/ "EO", /*catalog number*/ 45268, /*diameter*/25.00, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.025,/* focallength*/500.00,
		/* tolerance focal length*/ 2.0, /*back focal length*/497.57, /*design wavelength*/ 587.6, /*free aperture CA*/24.00,/*min centering*/ 0.0,
		/*max centering*/1.0,  /*first thickness*/3.00,	/*second thickness*/2.50, /*tolerance center thickness*/ 0.2, /*radius first surface*/290.71,
		/*radius second surface*/ -232.07, /*radius third surface*/ -750.52, /*edge thickness*/5.13, /*material first*/ mGlasses.getNBK7_S1(),
		/*material second*/ mGlasses.getNSF5_S1(),/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*stop*/20.00, /*numerical aperture*/0.03,
		/*coating*/ "MgF2",	/*coating specification*/ 1.75,	/*power wavelength*/ 632.8, /*power PV*/ 1.5,/*curvature wavelength*/ 632.8,
		/*curvature PV*/ 4, /*bevel*/ "Protective bevel as needed",	/*type*/ "achromatic lens",	/*min wavelength*/ 400.0, /*max wavelength*/ 700.0,
		/*price*/90.00, /*wavelength to trace*/ 550.0);

	EO67329.buildLensThreeSurfaces(/*lens catalog*/ "EO", /*catalog number*/ 67329, /*diameter*/25.00, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.025,/* focallength*/750.00,				//R3: infinity
		/* tolerance focal length*/ 2.0, /*back focal length*/746.47, /*design wavelength*/ 587.6, /*free aperture CA*/24.00,/*min centering*/ 0.0,
		/*max centering*/1.0,  /*first thickness*/2.50,	/*second thickness*/2.50, /*tolerance center thickness*/ 0.2, /*radius first surface*/315.20,
		/*radius second surface*/ -507.71, /*radius third surface*/ 99999999999999.0 /*infinity*/, /*edge thickness*/4.75, /*material first*/ mGlasses.getNBK7_S1(),
		/*material second*/ mGlasses.getNSF5_S1(),/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*stop*/30.00, /*numerical aperture*/0.02,
		/*coating*/ "MgF2",	/*coating specification*/ 1.75,	/*power wavelength*/ 632.8, /*power PV*/ 1.5,/*curvature wavelength*/ 632.8,
		/*curvature PV*/ 4, /*bevel*/ "Protective bevel as needed",	/*type*/ "achromatic lens",	/*min wavelength*/ 400.0, /*max wavelength*/ 700.0,
		/*price*/90.00, /*wavelength to trace*/ 550.0);

	EO49765.buildLensThreeSurfaces(/*lens catalog*/ "EO", /*catalog number*/ 49765, /*diameter*/25.40, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.025,/* focallength*/38.10,
		/* tolerance focal length*/ 2.0, /*back focal length*/30.77, /*design wavelength*/ 587.6, /*free aperture CA*/24.40,/*min centering*/ 0.0,
		/*max centering*/1.0,  /*first thickness*/10.50,	/*second thickness*/3.00, /*tolerance center thickness*/ 0.2, /*radius first surface*/26.37,
		/*radius second surface*/ -20.43, /*radius third surface*/ -101.75, /*edge thickness*/9.44, /*material first*/ mGlasses.getNBAF10_S1(),
		/*material second*/ mGlasses.getNSF6_S1(),/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*stop*/1.5, /*numerical aperture*/0.33,
		/*coating*/ "MgF2",	/*coating specification*/ 1.75,	/*power wavelength*/ 632.8, /*power PV*/ 1.5,/*curvature wavelength*/ 632.8,
		/*curvature PV*/ 4, /*bevel*/ "Protective bevel as needed",	/*type*/ "achromatic lens",	/*min wavelength*/ 400.0, /*max wavelength*/ 700.0,
		/*price*/90.00, /*wavelength to trace*/ 550.0);

	EO49766.buildLensThreeSurfaces(/*lens catalog*/ "EO", /*catalog number*/ 49766, /*diameter*/25.40, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.025,/* focallength*/50.80,
		/* tolerance focal length*/ 2.0, /*back focal length*/44.90, /*design wavelength*/ 587.6, /*free aperture CA*/24.40,/*min centering*/ 0.0,
		/*max centering*/1.0,  /*first thickness*/8.00,	/*second thickness*/3.50, /*tolerance center thickness*/ 0.2, /*radius first surface*/33.54,
		/*radius second surface*/ -27.27, /*radius third surface*/ -101.50, /*edge thickness*/8.20, /*material first*/ mGlasses.getNSSK8_S1(),
		/*material second*/ mGlasses.getNSF56_S1(),/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*stop*/2.00, /*numerical aperture*/0.25,
		/*coating*/ "MgF2",	/*coating specification*/ 1.75,	/*power wavelength*/ 632.8, /*power PV*/ 1.5,/*curvature wavelength*/ 632.8,
		/*curvature PV*/ 4, /*bevel*/ "Protective bevel as needed",	/*type*/ "achromatic lens",	/*min wavelength*/ 400.0, /*max wavelength*/ 700.0,
		/*price*/90.00, /*wavelength to trace*/ 550.0);

	EO49767.buildLensThreeSurfaces(/*lens catalog*/ "EO", /*catalog number*/ 49767, /*diameter*/25.40, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.025,/* focallength*/63.50,
		/* tolerance focal length*/ 2.0, /*back focal length*/57.67, /*design wavelength*/ 587.6, /*free aperture CA*/24.40,/*min centering*/ 0.0,
		/*max centering*/1.0,  /*first thickness*/8.00,	/*second thickness*/3.50, /*tolerance center thickness*/ 0.2, /*radius first surface*/42.26,
		/*radius second surface*/ -33.37, /*radius third surface*/ -123.45, /*edge thickness*/8.89, /*material first*/ mGlasses.getNSSK8_S1(),
		/*material second*/ mGlasses.getNSF56_S1(),/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*stop*/2.5, /*numerical aperture*/0.20,
		/*coating*/ "MgF2",	/*coating specification*/ 1.75,	/*power wavelength*/ 632.8, /*power PV*/ 1.5,/*curvature wavelength*/ 632.8,
		/*curvature PV*/ 4, /*bevel*/ "Protective bevel as needed",	/*type*/ "achromatic lens",	/*min wavelength*/ 400.0, /*max wavelength*/ 700.0,
		/*price*/90.00, /*wavelength to trace*/ 550.0);

	EO49768.buildLensThreeSurfaces(/*lens catalog*/ "EO", /*catalog number*/ 49768, /*diameter*/25.40, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.025,/* focallength*/76.20,
		/* tolerance focal length*/ 2.0, /*back focal length*/71.14, /*design wavelength*/ 587.6, /*free aperture CA*/24.40,/*min centering*/ 0.0,
		/*max centering*/1.0,  /*first thickness*/7.00,	/*second thickness*/3.00, /*tolerance center thickness*/ 0.2, /*radius first surface*/50.85,
		/*radius second surface*/ -40.06, /*radius third surface*/ -148.78, /*edge thickness*/7.85, /*material first*/ mGlasses.getNSSK8_S1(),
		/*material second*/ mGlasses.getNSF56_S1(),/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*stop*/3.00, /*numerical aperture*/0.17,
		/*coating*/ "MgF2",	/*coating specification*/ 1.75,	/*power wavelength*/ 632.8, /*power PV*/ 1.5,/*curvature wavelength*/ 632.8,
		/*curvature PV*/ 4, /*bevel*/ "Protective bevel as needed",	/*type*/ "achromatic lens",	/*min wavelength*/ 400.0, /*max wavelength*/ 700.0,
		/*price*/90.00, /*wavelength to trace*/ 550.0);

	EO49769.buildLensThreeSurfaces(/*lens catalog*/ "EO", /*catalog number*/ 49769, /*diameter*/25.40, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.025,/* focallength*/88.90,
		/* tolerance focal length*/ 2.0, /*back focal length*/83.96, /*design wavelength*/ 587.6, /*free aperture CA*/24.40,/*min centering*/ 0.0,
		/*max centering*/1.0,  /*first thickness*/6.00,	/*second thickness*/4.00, /*tolerance center thickness*/ 0.2, /*radius first surface*/56.98,
		/*radius second surface*/ -40.06, /*radius third surface*/ -162.82, /*edge thickness*/8.07, /*material first*/ mGlasses.getNBAK1_S1(),
		/*material second*/ mGlasses.getNSF8_S1(),/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*stop*/2.5, /*numerical aperture*/0.14,
		/*coating*/ "MgF2",	/*coating specification*/ 1.75,	/*power wavelength*/ 632.8, /*power PV*/ 1.5,/*curvature wavelength*/ 632.8,
		/*curvature PV*/ 4, /*bevel*/ "Protective bevel as needed",	/*type*/ "achromatic lens",	/*min wavelength*/ 400.0, /*max wavelength*/ 700.0,
		/*price*/90.00, /*wavelength to trace*/ 550.0);

	EO49770.buildLensThreeSurfaces(/*lens catalog*/ "EO", /*catalog number*/ 49770, /*diameter*/101.60, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.025,/* focallength*/101.60,
		/* tolerance focal length*/ 2.0, /*back focal length*/97.72, /*design wavelength*/ 587.6, /*free aperture CA*/24.40,/*min centering*/ 0.0,
		/*max centering*/1.0,  /*first thickness*/5.00,	/*second thickness*/3.00, /*tolerance center thickness*/ 0.2, /*radius first surface*/66.33,
		/*radius second surface*/ -47.95, /*radius third surface*/ -178.05, /*edge thickness*/6.32, /*material first*/ mGlasses.getNBAK1_S1(),
		/*material second*/ mGlasses.getNSF15_S1(),/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*stop*/4.00, /*numerical aperture*/0.13,
		/*coating*/ "MgF2",	/*coating specification*/ 1.75,	/*power wavelength*/ 632.8, /*power PV*/ 1.5,/*curvature wavelength*/ 632.8,
		/*curvature PV*/ 4, /*bevel*/ "Protective bevel as needed",	/*type*/ "achromatic lens",	/*min wavelength*/ 400.0, /*max wavelength*/ 700.0,
		/*price*/90.00, /*wavelength to trace*/ 550.0);

	EO33917.buildLensThreeSurfaces(/*lens catalog*/ "EO", /*catalog number*/ 33917, /*diameter*/30.00, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.025,/* focallength*/40.00,
		/* tolerance focal length*/ 2.0, /*back focal length*/31.14, /*design wavelength*/ 587.6, /*free aperture CA*/39.00,/*min centering*/ 0.0,
		/*max centering*/1.0,  /*first thickness*/10.90,	/*second thickness*/4.60, /*tolerance center thickness*/ 0.2, /*radius first surface*/25.62,
		/*radius second surface*/ -25.62, /*radius third surface*/ -144.37, /*edge thickness*/9.87, /*material first*/ mGlasses.getNBAF10_S1(),					//NBaF10?
		/*material second*/ mGlasses.getNSF57_S1(),/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*stop*/1.33, /*numerical aperture*/0.38,
		/*coating*/ "MgF2",	/*coating specification*/ 1.75,	/*power wavelength*/ 632.8, /*power PV*/ 1.5,/*curvature wavelength*/ 632.8,
		/*curvature PV*/ 4, /*bevel*/ "Protective bevel as needed",	/*type*/ "achromatic lens",	/*min wavelength*/ 400.0, /*max wavelength*/ 700.0,
		/*price*/102.50, /*wavelength to trace*/ 550.0);

	EO32500.buildLensThreeSurfaces(/*lens catalog*/ "EO", /*catalog number*/ 32500, /*diameter*/30.00, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.025,/* focallength*/100.00,
		/* tolerance focal length*/ 2.0, /*back focal length*/94.54, /*design wavelength*/ 587.6, /*free aperture CA*/29.00,/*min centering*/ 0.0,
		/*max centering*/1.0,  /*first thickness*/8.25,	/*second thickness*/2.80, /*tolerance center thickness*/ 0.2, /*radius first surface*/61.36,
		/*radius second surface*/ -44.30, /*radius third surface*/ -128.90, /*edge thickness*/8.31, /*material first*/ mGlasses.getNBK7_S1(),
		/*material second*/ mGlasses.getNSF5_S1(),/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*stop*/3.33, /*numerical aperture*/0.15,
		/*coating*/ "MgF2",	/*coating specification*/ 1.75,	/*power wavelength*/ 632.8, /*power PV*/ 1.5,/*curvature wavelength*/ 632.8,
		/*curvature PV*/ 4, /*bevel*/ "Protective bevel as needed",	/*type*/ "achromatic lens",	/*min wavelength*/ 400.0, /*max wavelength*/ 700.0,
		/*price*/102.50, /*wavelength to trace*/ 550.0);

	EO45217.buildLensThreeSurfaces(/*lens catalog*/ "EO", /*catalog number*/ 45217, /*diameter*/30.00, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.025,/* focallength*/125.00,
		/* tolerance focal length*/ 2.0, /*back focal length*/121.37, /*design wavelength*/ 587.6, /*free aperture CA*/29.00,/*min centering*/ 0.0,
		/*max centering*/1.0,  /*first thickness*/4.92,	/*second thickness*/2.50, /*tolerance center thickness*/ 0.2, /*radius first surface*/81.53,
		/*radius second surface*/ -56.59, /*radius third surface*/ -220.08, /*edge thickness*/5.52, /*material first*/ mGlasses.getNSK11_S1(),
		/*material second*/ mGlasses.getNSF5_S1(),/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*stop*/4.17, /*numerical aperture*/0.12,
		/*coating*/ "MgF2",	/*coating specification*/ 1.75,	/*power wavelength*/ 632.8, /*power PV*/ 1.5,/*curvature wavelength*/ 632.8,
		/*curvature PV*/ 4, /*bevel*/ "Protective bevel as needed",	/*type*/ "achromatic lens",	/*min wavelength*/ 400.0, /*max wavelength*/ 700.0,
		/*price*/102.50, /*wavelength to trace*/ 550.0);

	EO32502.buildLensThreeSurfaces(/*lens catalog*/ "EO", /*catalog number*/ 32502, /*diameter*/30.00, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.025,/* focallength*/150.00,
		/* tolerance focal length*/ 2.0, /*back focal length*/144.63, /*design wavelength*/ 587.6, /*free aperture CA*/29.00,/*min centering*/ 0.0,
		/*max centering*/1.0,  /*first thickness*/8.10,	/*second thickness*/2.60, /*tolerance center thickness*/ 0.2, /*radius first surface*/91.31,
		/*radius second surface*/ -65.57, /*radius third surface*/ -195.87, /*edge thickness*/8.88, /*material first*/ mGlasses.getNBK7_S1(),
		/*material second*/ mGlasses.getNSF5_S1(),/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*stop*/5.00, /*numerical aperture*/0.10,
		/*coating*/ "MgF2",	/*coating specification*/ 1.75,	/*power wavelength*/ 632.8, /*power PV*/ 1.5,/*curvature wavelength*/ 632.8,
		/*curvature PV*/ 4, /*bevel*/ "Protective bevel as needed",	/*type*/ "achromatic lens",	/*min wavelength*/ 400.0, /*max wavelength*/ 700.0,
		/*price*/102.50, /*wavelength to trace*/ 550.0);

	EO45415.buildLensThreeSurfaces(/*lens catalog*/ "EO", /*catalog number*/ 45415, /*diameter*/30.00, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.025,/* focallength*/200.00,
		/* tolerance focal length*/ 2.0, /*back focal length*/196.57, /*design wavelength*/ 587.6, /*free aperture CA*/29.00,/*min centering*/ 0.0,
		/*max centering*/1.0,  /*first thickness*/5.00,	/*second thickness*/2.50, /*tolerance center thickness*/ 0.2, /*radius first surface*/123.77,
		/*radius second surface*/ -89.22, /*radius third surface*/ -259.43, /*edge thickness*/6.15, /*material first*/ mGlasses.getNBK7_S1(),
		/*material second*/ mGlasses.getNSF5_S1(),/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*stop*/6.67, /*numerical aperture*/0.07,
		/*coating*/ "MgF2",	/*coating specification*/ 1.75,	/*power wavelength*/ 632.8, /*power PV*/ 1.5,/*curvature wavelength*/ 632.8,
		/*curvature PV*/ 4, /*bevel*/ "Protective bevel as needed",	/*type*/ "achromatic lens",	/*min wavelength*/ 400.0, /*max wavelength*/ 700.0,
		/*price*/102.50, /*wavelength to trace*/ 550.0);

	EO45269.buildLensThreeSurfaces(/*lens catalog*/ "EO", /*catalog number*/ 45269, /*diameter*/30.00, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.025,/* focallength*/300.00,
		/* tolerance focal length*/ 2.0, /*back focal length*/296.85, /*design wavelength*/ 587.6, /*free aperture CA*/29.00,/*min centering*/ 0.0,
		/*max centering*/1.0,  /*first thickness*/4.50,	/*second thickness*/2.50, /*tolerance center thickness*/ 0.2, /*radius first surface*/184.40,
		/*radius second surface*/ -133.95, /*radius third surface*/ -394.96, /*edge thickness*/6.12, /*material first*/ mGlasses.getNBK7_S1(),
		/*material second*/ mGlasses.getNSF5_S1(),/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*stop*/10.00, /*numerical aperture*/0.05,
		/*coating*/ "MgF2",	/*coating specification*/ 1.75,	/*power wavelength*/ 632.8, /*power PV*/ 1.5,/*curvature wavelength*/ 632.8,
		/*curvature PV*/ 4, /*bevel*/ "Protective bevel as needed",	/*type*/ "achromatic lens",	/*min wavelength*/ 400.0, /*max wavelength*/ 700.0,
		/*price*/102.50, /*wavelength to trace*/ 550.0);

	EO32496.buildLensThreeSurfaces(/*lens catalog*/ "EO", /*catalog number*/ 32496, /*diameter*/30.00, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.025,/* focallength*/50.00,
		/* tolerance focal length*/ 2.0, /*back focal length*/42.57, /*design wavelength*/ 587.6, /*free aperture CA*/29.00,/*min centering*/ 0.0,
		/*max centering*/1.0,  /*first thickness*/11.00,	/*second thickness*/2.20, /*tolerance center thickness*/ 0.2, /*radius first surface*/34.81,
		/*radius second surface*/ -22.12, /*radius third surface*/ -203.48, /*edge thickness*/9.25, /*material first*/ mGlasses.getNBAF10_S1(),
		/*material second*/ mGlasses.getNSF10_S1(),/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*stop*/1.67, /*numerical aperture*/0.30,
		/*coating*/ "MgF2",	/*coating specification*/ 1.75,	/*power wavelength*/ 632.8, /*power PV*/ 1.5,/*curvature wavelength*/ 632.8,
		/*curvature PV*/ 4, /*bevel*/ "Protective bevel as needed",	/*type*/ "achromatic lens",	/*min wavelength*/ 400.0, /*max wavelength*/ 700.0,
		/*price*/102.50, /*wavelength to trace*/ 550.0);

	EO45140.buildLensThreeSurfaces(/*lens catalog*/ "EO", /*catalog number*/ 45140, /*diameter*/30.00, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.025,/* focallength*/60.00,
		/* tolerance focal length*/ 2.0, /*back focal length*/52.50, /*design wavelength*/ 587.6, /*free aperture CA*/29.00,/*min centering*/ 0.0,
		/*max centering*/1.0,  /*first thickness*/8.47,	/*second thickness*/2.99, /*tolerance center thickness*/ 0.2, /*radius first surface*/32.60,
		/*radius second surface*/ -31.81, /*radius third surface*/ -799.64, /*edge thickness*/7.66, /*material first*/ mGlasses.getNSSK8_S1(),
		/*material second*/ mGlasses.getNSF10_S1(),/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*stop*/2.00, /*numerical aperture*/0.25,
		/*coating*/ "MgF2",	/*coating specification*/ 1.75,	/*power wavelength*/ 632.8, /*power PV*/ 1.5,/*curvature wavelength*/ 632.8,
		/*curvature PV*/ 4, /*bevel*/ "Protective bevel as needed",	/*type*/ "achromatic lens",	/*min wavelength*/ 400.0, /*max wavelength*/ 700.0,
		/*price*/102.50, /*wavelength to trace*/ 550.0);

	EO32498.buildLensThreeSurfaces(/*lens catalog*/ "EO", /*catalog number*/ 32498, /*diameter*/20.00, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.025,/* focallength*/75.00,
		/* tolerance focal length*/ 2.0, /*back focal length*/67.44, /*design wavelength*/ 587.6, /*free aperture CA*/29.00,/*min centering*/ 0.0,
		/*max centering*/1.0,  /*first thickness*/8.40,	/*second thickness*/3.00, /*tolerance center thickness*/ 0.2, /*radius first surface*/40.51,
		/*radius second surface*/ -38.68, /*radius third surface*/ -922.04, /*edge thickness*/8.40, /*material first*/ mGlasses.getNSSK8_S1(),
		/*material second*/ mGlasses.getNSF10_S1(),/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*stop*/2.5, /*numerical aperture*/0.20,
		/*coating*/ "MgF2",	/*coating specification*/ 1.75,	/*power wavelength*/ 632.8, /*power PV*/ 1.5,/*curvature wavelength*/ 632.8,
		/*curvature PV*/ 4, /*bevel*/ "Protective bevel as needed",	/*type*/ "achromatic lens",	/*min wavelength*/ 400.0, /*max wavelength*/ 700.0,
		/*price*/102.50, /*wavelength to trace*/ 550.0);

	EO89681.buildLensThreeSurfaces(/*lens catalog*/ "EO", /*catalog number*/ 89681, /*diameter*/40.00, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.025,/* focallength*/50.00,
		/* tolerance focal length*/ 2.0, /*back focal length*/34.46, /*design wavelength*/ 587.6, /*free aperture CA*/39.00,/*min centering*/ 0.0,
		/*max centering*/1.0,  /*first thickness*/19.00, /*second thickness*/7.00, /*tolerance center thickness*/ 0.1, /*radius first surface*/28.558,
		/*radius second surface*/ -29.965, /*radius third surface*/ 153.666, /*edge thickness*/16.52, /*material first*/ mGlasses.getNSK11_S1(),							//R3: positiv
		/*material second*/ mGlasses.getNSF5_S1(),/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*stop*/1.25, /*numerical aperture*/0.40,
		/*coating*/ "MgF2",	/*coating specification*/ 1.75,	/*power wavelength*/ 632.8, /*power PV*/ 1.5,/*curvature wavelength*/ 632.8,
		/*curvature PV*/ 4, /*bevel*/ "Protective bevel as needed",	/*type*/ "achromatic lens",	/*min wavelength*/ 400.0, /*max wavelength*/ 700.0,
		/*price*/128.50, /*wavelength to trace*/ 550.0);

	EO45218.buildLensThreeSurfaces(/*lens catalog*/ "EO", /*catalog number*/ 45218, /*diameter*/40.00, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.025,/* focallength*/60.00,
		/* tolerance focal length*/ 2.0, /*back focal length*/50.29, /*design wavelength*/ 587.6, /*free aperture CA*/39.00,/*min centering*/ 0.0,
		/*max centering*/1.0,  /*first thickness*/14.46,	/*second thickness*/3.00, /*tolerance center thickness*/ 0.2, /*radius first surface*/37.33,
		/*radius second surface*/ -31.54, /*radius third surface*/ -124.51, /*edge thickness*/10.03, /*material first*/ mGlasses.getNSK11_S1(),
		/*material second*/ mGlasses.getNSF5_S1(),/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*stop*/1.5, /*numerical aperture*/0.33,
		/*coating*/ "MgF2",	/*coating specification*/ 1.75,	/*power wavelength*/ 632.8, /*power PV*/ 1.5,/*curvature wavelength*/ 632.8,
		/*curvature PV*/ 4, /*bevel*/ "Protective bevel as needed",	/*type*/ "achromatic lens",	/*min wavelength*/ 400.0, /*max wavelength*/ 700.0,
		/*price*/128.50, /*wavelength to trace*/ 550.0);

	EO45105.buildLensThreeSurfaces(/*lens catalog*/ "EO", /*catalog number*/ 45105, /*diameter*/40.00, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.025,/* focallength*/80.00,
		/* tolerance focal length*/ 2.0, /*back focal length*/70.75, /*design wavelength*/ 587.6, /*free aperture CA*/39.00,/*min centering*/ 0.0,
		/*max centering*/1.0,  /*first thickness*/12.07,	/*second thickness*/4.00, /*tolerance center thickness*/ 0.2, /*radius first surface*/53.76,
		/*radius second surface*/ -36.73, /*radius third surface*/ -435.85, /*edge thickness*/11.75, /*material first*/ mGlasses.getNBAF10_S1(),
		/*material second*/ mGlasses.getNSF10_S1(),/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*stop*/2.00, /*numerical aperture*/0.25,
		/*coating*/ "MgF2",	/*coating specification*/ 1.75,	/*power wavelength*/ 632.8, /*power PV*/ 1.5,/*curvature wavelength*/ 632.8,
		/*curvature PV*/ 4, /*bevel*/ "Protective bevel as needed",	/*type*/ "achromatic lens",	/*min wavelength*/ 400.0, /*max wavelength*/ 700.0,
		/*price*/128.50, /*wavelength to trace*/ 550.0);

	EO63701.buildLensThreeSurfaces(/*lens catalog*/ "EO", /*catalog number*/ 63701, /*diameter*/40.00, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.025,/* focallength*/100.00,
		/* tolerance focal length*/ 2.0, /*back focal length*/91.24, /*design wavelength*/ 587.6, /*free aperture CA*/39.00,/*min centering*/ 0.0,
		/*max centering*/1.0,  /*first thickness*/10.00,	/*second thickness*/3.00, /*tolerance center thickness*/ 0.2, /*radius first surface*/46.73,
		/*radius second surface*/ -50.61, /*radius third surface*/ -341.70, /*edge thickness*/7.92, /*material first*/ mGlasses.getNBK7_S1(),
		/*material second*/ mGlasses.getNSF5_S1(),/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*stop*/2.5, /*numerical aperture*/0.20,
		/*coating*/ "MgF2",	/*coating specification*/ 1.75,	/*power wavelength*/ 632.8, /*power PV*/ 1.5,/*curvature wavelength*/ 632.8,
		/*curvature PV*/ 4, /*bevel*/ "Protective bevel as needed",	/*type*/ "achromatic lens",	/*min wavelength*/ 400.0, /*max wavelength*/ 700.0,
		/*price*/128.50, /*wavelength to trace*/ 550.0);

	EO32921.buildLensThreeSurfaces(/*lens catalog*/ "EO", /*catalog number*/ 32921, /*diameter*/40.00, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.025,/* focallength*/120.00,
		/* tolerance focal length*/ 2.0, /*back focal length*/111.00, /*design wavelength*/ 587.6, /*free aperture CA*/39.00,/*min centering*/ 0.0,
		/*max centering*/1.0,  /*first thickness*/9.60,	/*second thickness*/4.20, /*tolerance center thickness*/ 0.2, /*radius first surface*/65.22,
		/*radius second surface*/ -62.03, /*radius third surface*/ -1240.67, /*edge thickness*/10.51, /*material first*/ mGlasses.getNSSK8_S1(),
		/*material second*/ mGlasses.getNSF10_S1(),/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*stop*/3.00, /*numerical aperture*/0.17,
		/*coating*/ "MgF2",	/*coating specification*/ 1.75,	/*power wavelength*/ 632.8, /*power PV*/ 1.5,/*curvature wavelength*/ 632.8,
		/*curvature PV*/ 4, /*bevel*/ "Protective bevel as needed",	/*type*/ "achromatic lens",	/*min wavelength*/ 400.0, /*max wavelength*/ 700.0,
		/*price*/128.50, /*wavelength to trace*/ 550.0);

	EO32923.buildLensThreeSurfaces(/*lens catalog*/ "EO", /*catalog number*/ 32923, /*diameter*/40.00, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.025,/* focallength*/160.00,
		/* tolerance focal length*/ 2.0, /*back focal length*/154.10, /*design wavelength*/ 587.6, /*free aperture CA*/39.00,/*min centering*/ 0.0,
		/*max centering*/1.0,  /*first thickness*/8.50,	/*second thickness*/4.00, /*tolerance center thickness*/ 0.2, /*radius first surface*/98.66,
		/*radius second surface*/ -70.73, /*radius third surface*/ -205.72, /*edge thickness*/9.48, /*material first*/ mGlasses.getNBK7_S1(),
		/*material second*/ mGlasses.getNSF5_S1(),/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*stop*/4.00, /*numerical aperture*/0.13,
		/*coating*/ "MgF2",	/*coating specification*/ 1.75,	/*power wavelength*/ 632.8, /*power PV*/ 1.5,/*curvature wavelength*/ 632.8,
		/*curvature PV*/ 4, /*bevel*/ "Protective bevel as needed",	/*type*/ "achromatic lens",	/*min wavelength*/ 400.0, /*max wavelength*/ 700.0,
		/*price*/128.50, /*wavelength to trace*/ 550.0);

	EO32925.buildLensThreeSurfaces(/*lens catalog*/ "EO", /*catalog number*/ 32925, /*diameter*/40.00, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.025,/* focallength*/200.00,
		/* tolerance focal length*/ 2.0, /*back focal length*/194.21, /*design wavelength*/ 587.6, /*free aperture CA*/39.00,/*min centering*/ 0.0,
		/*max centering*/1.0,  /*first thickness*/8.50,	/*second thickness*/4.00, /*tolerance center thickness*/ 0.2, /*radius first surface*/124.12,
		/*radius second surface*/ -87.26, /*radius third surface*/ -253.10, /*edge thickness*/10.09, /*material first*/ mGlasses.getNBK7_S1(),
		/*material second*/ mGlasses.getNSF5_S1(),/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*stop*/5.00, /*numerical aperture*/0.10,
		/*coating*/ "MgF2",	/*coating specification*/ 1.75,	/*power wavelength*/ 632.8, /*power PV*/ 1.5,/*curvature wavelength*/ 632.8,
		/*curvature PV*/ 4, /*bevel*/ "Protective bevel as needed",	/*type*/ "achromatic lens",	/*min wavelength*/ 400.0, /*max wavelength*/ 700.0,
		/*price*/128.50, /*wavelength to trace*/ 550.0);

	EO32935.buildLensThreeSurfaces(/*lens catalog*/ "EO", /*catalog number*/ 32935, /*diameter*/40.00, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.025,/* focallength*/250.00,
		/* tolerance focal length*/ 2.0, /*back focal length*/244.32, /*design wavelength*/ 587.6, /*free aperture CA*/39.00,/*min centering*/ 0.0,
		/*max centering*/1.0,  /*first thickness*/8.00,	/*second thickness*/4.50, /*tolerance center thickness*/ 0.2, /*radius first surface*/156.00,
		/*radius second surface*/ -108.70, /*radius third surface*/ -313.64, /*edge thickness*/10.57, /*material first*/ mGlasses.getNBK7_S1(),
		/*material second*/ mGlasses.getNSF5_S1(),/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*stop*/6.25, /*numerical aperture*/0.08,
		/*coating*/ "MgF2",	/*coating specification*/ 1.75,	/*power wavelength*/ 632.8, /*power PV*/ 1.5,/*curvature wavelength*/ 632.8,
		/*curvature PV*/ 4, /*bevel*/ "Protective bevel as needed",	/*type*/ "achromatic lens",	/*min wavelength*/ 400.0, /*max wavelength*/ 700.0,
		/*price*/128.50, /*wavelength to trace*/ 550.0);

	EO45178.buildLensThreeSurfaces(/*lens catalog*/ "EO", /*catalog number*/ 45178, /*diameter*/40.00, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.025,/* focallength*/300.00,
		/* tolerance focal length*/ 2.0, /*back focal length*/293.63, /*design wavelength*/ 587.6, /*free aperture CA*/39.00,/*min centering*/ 0.0,
		/*max centering*/1.0,  /*first thickness*/9.00,	/*second thickness*/4.10, /*tolerance center thickness*/ 0.2, /*radius first surface*/194.96,
		/*radius second surface*/ -148.27, /*radius third surface*/ -483.71, /*edge thickness*/11.66, /*material first*/ mGlasses.getNBAK4_S1(),
		/*material second*/ mGlasses.getNSF10_S1(),/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*stop*/7.5, /*numerical aperture*/0.07,
		/*coating*/ "MgF2",	/*coating specification*/ 1.75,	/*power wavelength*/ 632.8, /*power PV*/ 1.5,/*curvature wavelength*/ 632.8,
		/*curvature PV*/ 4, /*bevel*/ "Protective bevel as needed",	/*type*/ "achromatic lens",	/*min wavelength*/ 400.0, /*max wavelength*/ 700.0,
		/*price*/128.50, /*wavelength to trace*/ 550.0);

	EO32927.buildLensThreeSurfaces(/*lens catalog*/ "EO", /*catalog number*/ 32927, /*diameter*/40.00, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.025,/* focallength*/400.00,
		/* tolerance focal length*/ 2.0, /*back focal length*/394.33, /*design wavelength*/ 587.6, /*free aperture CA*/39.00,/*min centering*/ 0.0,
		/*max centering*/1.0,  /*first thickness*/8.50,	/*second thickness*/4.00, /*tolerance center thickness*/ 0.2, /*radius first surface*/257.16,
		/*radius second surface*/ -169.03, /*radius third surface*/ -473.08, /*edge thickness*/11.30, /*material first*/ mGlasses.getNBK7_S1(),
		/*material second*/ mGlasses.getNSF5_S1(),/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*stop*/10.00, /*numerical aperture*/0.05,
		/*coating*/ "MgF2",	/*coating specification*/ 1.75,	/*power wavelength*/ 632.8, /*power PV*/ 1.5,/*curvature wavelength*/ 632.8,
		/*curvature PV*/ 4, /*bevel*/ "Protective bevel as needed",	/*type*/ "achromatic lens",	/*min wavelength*/ 400.0, /*max wavelength*/ 700.0,
		/*price*/128.50, /*wavelength to trace*/ 550.0);

	EO45352.buildLensThreeSurfaces(/*lens catalog*/ "EO", /*catalog number*/ 45352, /*diameter*/40.00, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.025,/* focallength*/450.00,
		/* tolerance focal length*/ 2.0, /*back focal length*/445.69, /*design wavelength*/ 587.6, /*free aperture CA*/39.00,/*min centering*/ 0.0,
		/*max centering*/1.0,  /*first thickness*/6.00,	/*second thickness*/4.00, /*tolerance center thickness*/ 0.2, /*radius first surface*/279.60,
		/*radius second surface*/ -199.51, /*radius third surface*/ -579.39, /*edge thickness*/8.94, /*material first*/ mGlasses.getNBK7_S1(),
		/*material second*/ mGlasses.getNSF5_S1(),/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*stop*/11.25, /*numerical aperture*/0.04,
		/*coating*/ "MgF2",	/*coating specification*/ 1.75,	/*power wavelength*/ 632.8, /*power PV*/ 1.5,/*curvature wavelength*/ 632.8,
		/*curvature PV*/ 4, /*bevel*/ "Protective bevel as needed",	/*type*/ "achromatic lens",	/*min wavelength*/ 400.0, /*max wavelength*/ 700.0,
		/*price*/128.50, /*wavelength to trace*/ 550.0);

	EO45270.buildLensThreeSurfaces(/*lens catalog*/ "EO", /*catalog number*/ 45270, /*diameter*/40.00, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.025,/* focallength*/500.00,
		/* tolerance focal length*/ 2.0, /*back focal length*/495.60, /*design wavelength*/ 587.6, /*free aperture CA*/39.00,/*min centering*/ 0.0,
		/*max centering*/1.00,  /*first thickness*/6.00,	/*second thickness*/4.00, /*tolerance center thickness*/ 0.2, /*radius first surface*/305.31,
		/*radius second surface*/ -224.08, /*radius third surface*/ -667.68, /*edge thickness*/9.04, /*material first*/ mGlasses.getNBK7_S1(),
		/*material second*/ mGlasses.getNSF5_S1(),/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*stop*/12.5, /*numerical aperture*/0.04,
		/*coating*/ "MgF2",	/*coating specification*/ 1.75,	/*power wavelength*/ 632.8, /*power PV*/ 1.5,/*curvature wavelength*/ 632.8,
		/*curvature PV*/ 4, /*bevel*/ "Protective bevel as needed",	/*type*/ "achromatic lens",	/*min wavelength*/ 400.0, /*max wavelength*/ 700.0,
		/*price*/128.50, /*wavelength to trace*/ 550.0);

	EO67330.buildLensThreeSurfaces(/*lens catalog*/ "EO", /*catalog number*/ 67330, /*diameter*/40.00, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.025,/* focallength*/750.00,
		/* tolerance focal length*/ 2.0, /*back focal length*/744.37, /*design wavelength*/ 587.6, /*free aperture CA*/39.00,/*min centering*/ 0.0,
		/*max centering*/1.0,  /*first thickness*/4.00,	/*second thickness*/4.00, /*tolerance center thickness*/ 0.2, /*radius first surface*/315.18,
		/*radius second surface*/ -506.69, /*radius third surface*/ 99999999999999.0 /*infinity*/, /*edge thickness*/7.36, /*material first*/ mGlasses.getNBK7_S1(),
		/*material second*/ mGlasses.getNSF5_S1(),/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*stop*/18.75, /*numerical aperture*/0.03,			//R3: infinity
		/*coating*/ "MgF2",	/*coating specification*/ 1.75,	/*power wavelength*/ 632.8, /*power PV*/ 1.5,/*curvature wavelength*/ 632.8,
		/*curvature PV*/ 4, /*bevel*/ "Protective bevel as needed",	/*type*/ "achromatic lens",	/*min wavelength*/ 400.0, /*max wavelength*/ 700.0,
		/*price*/ 128.50, /*wavelength to trace*/ 550.0);

	EO49291.buildLensThreeSurfaces(/*lens catalog*/ "EO", /*catalog number*/ 49291, /*diameter*/50.00, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.025,/* focallength*/75.00,
		/* tolerance focal length*/ 2.0, /*back focal length*/61.17, /*design wavelength*/ 587.6, /*free aperture CA*/49.00,/*min centering*/ 0.0,
		/*max centering*/1.0,  /*first thickness*/20.00,	/*second thickness*/4.50, /*tolerance center thickness*/ 0.2, /*radius first surface*/51.88,
		/*radius second surface*/ -32.79, /*radius third surface*/ -309.45, /*edge thickness*/17.07, /*material first*/ mGlasses.getNBAF10_S1(),
		/*material second*/ mGlasses.getNSF10_S1(),/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*stop*/1.5, /*numerical aperture*/0.33,
		/*coating*/ "MgF2",	/*coating specification*/ 1.75,	/*power wavelength*/ 632.8, /*power PV*/ 1.5,/*curvature wavelength*/ 632.8,
		/*curvature PV*/ 4, /*bevel*/ "Protective bevel as needed",	/*type*/ "achromatic lens",	/*min wavelength*/ 400.0, /*max wavelength*/ 700.0,
		/*price*/139.00, /*wavelength to trace*/ 550.0);

	EO45353.buildLensThreeSurfaces(/*lens catalog*/ "EO", /*catalog number*/ 45353, /*diameter*/50.00, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.025,/* focallength*/100.00,
		/* tolerance focal length*/ 2.0, /*back focal length*/89.94, /*design wavelength*/ 587.6, /*free aperture CA*/49.00,/*min centering*/ 0.0,
		/*max centering*/1.0,  /*first thickness*/13.92,	/*second thickness*/4.00, /*tolerance center thickness*/ 0.2, /*radius first surface*/69.28,
		/*radius second surface*/ -46.95, /*radius third surface*/ -446.01, /*edge thickness*/12.55, /*material first*/ mGlasses.getNBAF10_S1(),
		/*material second*/ mGlasses.getNSF10_S1(),/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*stop*/2.00, /*numerical aperture*/0.25,
		/*coating*/ "MgF2",	/*coating specification*/ 1.75,	/*power wavelength*/ 632.8, /*power PV*/ 1.5,/*curvature wavelength*/ 632.8,
		/*curvature PV*/ 4, /*bevel*/ "Protective bevel as needed",	/*type*/ "achromatic lens",	/*min wavelength*/ 400.0, /*max wavelength*/ 700.0,
		/*price*/139.00, /*wavelength to trace*/ 550.0);

	EO32886.buildLensThreeSurfaces(/*lens catalog*/ "EO", /*catalog number*/ 32886, /*diameter*/50.00, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.025,/* focallength*/150.00,
		/* tolerance focal length*/ 2.0, /*back focal length*/143.17, /*design wavelength*/ 587.6, /*free aperture CA*/49.00,/*min centering*/ 0.0,
		/*max centering*/1.0,  /*first thickness*/9.50,	/*second thickness*/4.00, /*tolerance center thickness*/ 0.2, /*radius first surface*/96.85,
		/*radius second surface*/ -73.74, /*radius third surface*/ -241.63, /*edge thickness*/8.92, /*material first*/ mGlasses.getNBAK4_S1(),
		/*material second*/ mGlasses.getNSF10_S1(),/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*stop*/3.00, /*numerical aperture*/0.17,
		/*coating*/ "MgF2",	/*coating specification*/ 1.75,	/*power wavelength*/ 632.8, /*power PV*/ 1.5,/*curvature wavelength*/ 632.8,
		/*curvature PV*/ 4, /*bevel*/ "Protective bevel as needed",	/*type*/ "achromatic lens",	/*min wavelength*/ 400.0, /*max wavelength*/ 700.0,
		/*price*/139.00, /*wavelength to trace*/ 550.0);

	EO45179.buildLensThreeSurfaces(/*lens catalog*/ "EO", /*catalog number*/ 45179, /*diameter*/50.00, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.025,/* focallength*/200.00,
		/* tolerance focal length*/ 2.0, /*back focal length*/194.45, /*design wavelength*/ 587.6, /*free aperture CA*/49.00,/*min centering*/ 0.0,
		/*max centering*/1.0,  /*first thickness*/9.00,	/*second thickness*/3.50, /*tolerance center thickness*/ 0.2, /*radius first surface*/130.48,
		/*radius second surface*/ -99.36, /*radius third surface*/ -320.20, /*edge thickness*/9.11, /*material first*/ mGlasses.getNBAK4_S1(),
		/*material second*/ mGlasses.getNSF10_S1(),/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*stop*/4.00, /*numerical aperture*/0.13,
		/*coating*/ "MgF2",	/*coating specification*/ 1.75,	/*power wavelength*/ 632.8, /*power PV*/ 1.5,/*curvature wavelength*/ 632.8,
		/*curvature PV*/ 4, /*bevel*/ "Protective bevel as needed",	/*type*/ "achromatic lens",	/*min wavelength*/ 400.0, /*max wavelength*/ 700.0,
		/*price*/139.00, /*wavelength to trace*/ 550.0);

	EO45180.buildLensThreeSurfaces(/*lens catalog*/ "EO", /*catalog number*/ 45180, /*diameter*/50.00, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.025,/* focallength*/250.00,
		/* tolerance focal length*/ 2.0, /*back focal length*/243.41, /*design wavelength*/ 587.6, /*free aperture CA*/49.00,/*min centering*/ 0.0,
		/*max centering*/1.0,  /*first thickness*/9.75,	/*second thickness*/3.50, /*tolerance center thickness*/ 0.2, /*radius first surface*/162.59,
		/*radius second surface*/ -123.82, /*radius third surface*/ -402.58, /*edge thickness*/10.54, /*material first*/ mGlasses.getNBAK4_S1(),
		/*material second*/ mGlasses.getNSF10_S1(),/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*stop*/5.00, /*numerical aperture*/0.10,
		/*coating*/ "MgF2",	/*coating specification*/ 1.75,	/*power wavelength*/ 632.8, /*power PV*/ 1.5,/*curvature wavelength*/ 632.8,
		/*curvature PV*/ 4, /*bevel*/ "Protective bevel as needed",	/*type*/ "achromatic lens",	/*min wavelength*/ 400.0, /*max wavelength*/ 700.0,
		/*price*/139.00, /*wavelength to trace*/ 550.0);

	EO45181.buildLensThreeSurfaces(/*lens catalog*/ "EO", /*catalog number*/ 45181, /*diameter*/50.00, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.025,/* focallength*/300.00,
		/* tolerance focal length*/ 2.0, /*back focal length*/292.91, /*design wavelength*/ 587.6, /*free aperture CA*/49.00,/*min centering*/ 0.0,
		/*max centering*/1.0,  /*first thickness*/9.00,	/*second thickness*/3.50, /*tolerance center thickness*/ 0.2, /*radius first surface*/173.11,
		/*radius second surface*/ -164.03, /*radius third surface*/ -709.83, /*edge thickness*/10.24, /*material first*/ mGlasses.getNBAK4_S1(),
		/*material second*/ mGlasses.getNSF10_S1(),/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*stop*/6.00, /*numerical aperture*/0.08,
		/*coating*/ "MgF2",	/*coating specification*/ 1.75,	/*power wavelength*/ 632.8, /*power PV*/ 1.5,/*curvature wavelength*/ 632.8,
		/*curvature PV*/ 4, /*bevel*/ "Protective bevel as needed",	/*type*/ "achromatic lens",	/*min wavelength*/ 400.0, /*max wavelength*/ 700.0,
		/*price*/139.00, /*wavelength to trace*/ 550.0);

	EO45354.buildLensThreeSurfaces(/*lens catalog*/ "EO", /*catalog number*/ 45354, /*diameter*/50.00, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.025,/* focallength*/350.00,
		/* tolerance focal length*/ 2.0, /*back focal length*/344.32, /*design wavelength*/ 587.6, /*free aperture CA*/49.00,/*min centering*/ 0.0,
		/*max centering*/1.0,  /*first thickness*/8.00,	/*second thickness*/4.00, /*tolerance center thickness*/ 0.2, /*radius first surface*/227.16,
		/*radius second surface*/ -174.83, /*radius third surface*/ -571.49, /*edge thickness*/10.07, /*material first*/ mGlasses.getNBAK4_S1(),
		/*material second*/ mGlasses.getNSF10_S1(),/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*stop*/7.00, /*numerical aperture*/0.07,
		/*coating*/ "MgF2",	/*coating specification*/ 1.75,	/*power wavelength*/ 632.8, /*power PV*/ 1.5,/*curvature wavelength*/ 632.8,
		/*curvature PV*/ 4, /*bevel*/ "Protective bevel as needed",	/*type*/ "achromatic lens",	/*min wavelength*/ 400.0, /*max wavelength*/ 700.0,
		/*price*/139.00, /*wavelength to trace*/ 550.0);

	EO45271.buildLensThreeSurfaces(/*lens catalog*/ "EO", /*catalog number*/ 45271, /*diameter*/50.00, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.025,/* focallength*/500.00,
		/* tolerance focal length*/ 2.0, /*back focal length*/494.50, /*design wavelength*/ 587.6, /*free aperture CA*/49.00,/*min centering*/ 0.0,
		/*max centering*/1.0,  /*first thickness*/8.00,	/*second thickness*/4.00, /*tolerance center thickness*/ 0.2, /*radius first surface*/305.74,
		/*radius second surface*/ -223.20, /*radius third surface*/ -663.82, /*edge thickness*/10.51, /*material first*/ mGlasses.getNBK7_S1(),
		/*material second*/ mGlasses.getNSF5_S1(),/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*stop*/10.00, /*numerical aperture*/0.05,
		/*coating*/ "MgF2",	/*coating specification*/ 1.75,	/*power wavelength*/ 632.8, /*power PV*/ 1.5,/*curvature wavelength*/ 632.8,
		/*curvature PV*/ 4, /*bevel*/ "Protective bevel as needed",	/*type*/ "achromatic lens",	/*min wavelength*/ 400.0, /*max wavelength*/ 700.0,
		/*price*/139.00, /*wavelength to trace*/ 550.0);

	EO33918.buildLensThreeSurfaces(/*lens catalog*/ "EO", /*catalog number*/ 33918, /*diameter*/75.00, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.025,/* focallength*/100.00,
		/* tolerance focal length*/ 2.0, /*back focal length*/78.32, /*design wavelength*/ 587.6, /*free aperture CA*/73.50,/*min centering*/ 0.0,
		/*max centering*/1.0,  /*first thickness*/26.00,	/*second thickness*/12.70, /*tolerance center thickness*/ 0.2, /*radius first surface*/64.67,
		/*radius second surface*/ -64.67, /*radius third surface*/ -343.586, /*edge thickness*/24.66, /*material first*/ mGlasses.getNBAF10_S1(),				//NBaF10
		/*material second*/ mGlasses.getNSF57_S1(),/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*stop*/1.33, /*numerical aperture*/0.38,
		/*coating*/ "MgF2",	/*coating specification*/ 1.75,	/*power wavelength*/ 632.8, /*power PV*/ 1.5,/*curvature wavelength*/ 632.8,
		/*curvature PV*/ 4, /*bevel*/ "Protective bevel as needed",	/*type*/ "achromatic lens",	/*min wavelength*/ 400.0, /*max wavelength*/ 700.0,
		/*price*/245.00, /*wavelength to trace*/ 550.0);

	EO33919.buildLensThreeSurfaces(/*lens catalog*/ "EO", /*catalog number*/ 33919, /*diameter*/75.00, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.025,/* focallength*/150.00,
		/* tolerance focal length*/ 2.0, /*back focal length*/126.46, /*design wavelength*/ 587.6, /*free aperture CA*/73.50,/*min centering*/ 0.0,
		/*max centering*/1.0,  /*first thickness*/23.20,	/*second thickness*/23.10, /*tolerance center thickness*/ 0.2, /*radius first surface*/92.05,
		/*radius second surface*/ -72.85, /*radius third surface*/ -305.865, /*edge thickness*/36.01, /*material first*/ mGlasses.getNBAK1_S1(),				//NBaK1
		/*material second*/ mGlasses.getNSF8_S1(),/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*stop*/2.00, /*numerical aperture*/0.25,
		/*coating*/ "MgF2",	/*coating specification*/ 1.75,	/*power wavelength*/ 632.8, /*power PV*/ 1.5,/*curvature wavelength*/ 632.8,
		/*curvature PV*/ 4, /*bevel*/ "Protective bevel as needed",	/*type*/ "achromatic lens",	/*min wavelength*/ 400.0, /*max wavelength*/ 700.0,
		/*price*/245.00, /*wavelength to trace*/ 550.0);

	EO45417.buildLensThreeSurfaces(/*lens catalog*/ "EO", /*catalog number*/ 45417, /*diameter*/75.00, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.025,/* focallength*/200.00,
		/* tolerance focal length*/ 2.0, /*back focal length*/187.69, /*design wavelength*/ 587.6, /*free aperture CA*/73.50,/*min centering*/ 0.0,
		/*max centering*/1.0,  /*first thickness*/17.94,	/*second thickness*/6.00, /*tolerance center thickness*/ 0.2, /*radius first surface*/118.81,
		/*radius second surface*/ -96.37, /*radius third surface*/ -288.97, /*edge thickness*/15.42, /*material first*/ mGlasses.getNBK7_S1(),
		/*material second*/ mGlasses.getNSF5_S1(),/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*stop*/2.67, /*numerical aperture*/0.19,
		/*coating*/ "MgF2",	/*coating specification*/ 1.75,	/*power wavelength*/ 632.8, /*power PV*/ 1.5,/*curvature wavelength*/ 632.8,
		/*curvature PV*/ 4, /*bevel*/ "Protective bevel as needed",	/*type*/ "achromatic lens",	/*min wavelength*/ 400.0, /*max wavelength*/ 700.0,
		/*price*/245.00, /*wavelength to trace*/ 550.0);

	EO45418.buildLensThreeSurfaces(/*lens catalog*/ "EO", /*catalog number*/ 45418, /*diameter*/75.00, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.025,/* focallength*/300.00,
		/* tolerance focal length*/ 2.0, /*back focal length*/290.62, /*design wavelength*/ 587.6, /*free aperture CA*/73.50,/*min centering*/ 0.0,
		/*max centering*/1.0,  /*first thickness*/13.59,	/*second thickness*/6.00, /*tolerance center thickness*/ 0.2, /*radius first surface*/184.05,
		/*radius second surface*/ -137.34, /*radius third surface*/ -399.33, /*edge thickness*/13.97, /*material first*/ mGlasses.getNBK7_S1(),
		/*material second*/ mGlasses.getNSF5_S1(),/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*stop*/4.00, /*numerical aperture*/0.13,
		/*coating*/ "MgF2",	/*coating specification*/ 1.75,	/*power wavelength*/ 632.8, /*power PV*/ 1.5,/*curvature wavelength*/ 632.8,
		/*curvature PV*/ 4, /*bevel*/ "Protective bevel as needed",	/*type*/ "achromatic lens",	/*min wavelength*/ 400.0, /*max wavelength*/ 700.0,
		/*price*/245.00, /*wavelength to trace*/ 550.0);

	EO45419.buildLensThreeSurfaces(/*lens catalog*/ "EO", /*catalog number*/ 45419, /*diameter*/75.00, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.025,/* focallength*/400.00,
		/* tolerance focal length*/ 2.0, /*back focal length*/392.10, /*design wavelength*/ 587.6, /*free aperture CA*/73.50,/*min centering*/ 0.0,
		/*max centering*/1.0,  /*first thickness*/11.05,	/*second thickness*/6.00, /*tolerance center thickness*/ 0.2, /*radius first surface*/246.50,
		/*radius second surface*/ -180.92, /*radius third surface*/ -526.70, /*edge thickness*/12.84, /*material first*/ mGlasses.getNBK7_S1(),
		/*material second*/ mGlasses.getNSF5_S1(),/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*stop*/5.33, /*numerical aperture*/0.09,
		/*coating*/ "MgF2",	/*coating specification*/ 1.75,	/*power wavelength*/ 632.8, /*power PV*/ 1.5,/*curvature wavelength*/ 632.8,
		/*curvature PV*/ 4, /*bevel*/ "Protective bevel as needed",	/*type*/ "achromatic lens",	/*min wavelength*/ 400.0, /*max wavelength*/ 700.0,
		/*price*/245.00, /*wavelength to trace*/ 550.0);
}
// get VIS-NIR beschichtete PCV Linsen
// https://www.edmundoptics.de/f/vis-nir-coated-plano-concave-pcv-lenses/13512/
LensesTwoSurfaces EdmundOpticsLensCatalog::getEO84380()
{
	return EO84380;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO84381()
{
	return EO84381;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO45910()
{
	return EO45910;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO48345()
{
	return EO48345;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO45911()
{
	return EO45911;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO48696()
{
	return EO48696;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO45912()
{
	return EO45912;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO45913()
{
	return EO45913;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO48346()
{
	return EO48346;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO45914()
{
	return EO45914;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO45915()
{
	return EO45915;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO45916()
{
	return EO45916;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO48697()
{
	return EO48697;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO48347()
{
	return EO48347;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO45917()
{
	return EO45917;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO45918()
{
	return EO45918;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO45919()
{
	return EO45919;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO45920()
{
	return EO45920;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO45921()
{
	return EO45921;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO45922()
{
	return EO45922;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO48698()
{
	return EO48698;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO45923()
{
	return EO45923;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO45924()
{
	return EO45924;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO45925()
{
	return EO45925;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO45926()
{
	return EO45926;
}







// get Doppelkonkave (DCV) Linsen VIS-NIR AR beschichtet
// https://www.edmundoptics.de/f/vis-nir-coated-double-concave-dcv-lenses/13540/
LensesTwoSurfaces EdmundOpticsLensCatalog::getEO45927()
{
	return EO45927;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO48941()
{
	return EO48941;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO48699()
{
	return EO48699;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO48348()
{
	return EO48348;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO48942()
{
	return EO48942;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO48700()
{
	return EO48700;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO45928()
{
	return EO45928;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO48943()
{
	return EO48943;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO48701()
{
	return EO48701;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO45929()
{
	return EO45929;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO45930()
{
	return EO45930;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO45931()
{
	return EO45931;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO45932()
{
	return EO45932;
}






// get VIS-NIR beschichtete PCX Linsen
// https://www.edmundoptics.de/f/vis-nir-coated-plano-convex-pcx-lenses/12278/
LensesTwoSurfaces EdmundOpticsLensCatalog::getEO65289()
{
	return EO65289;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO65290()
{
	return EO65290;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO65291()
{
	return EO65291;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO65292()
{
	return EO65292;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO65293()
{
	return EO65293;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO65294()
{
	return EO65294;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO65295()
{
	return EO65295;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO65296()
{
	return EO65296;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO65297()
{
	return EO65297;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO65298()
{
	return EO65298;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO65299()
{
	return EO65299;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO65300()
{
	return EO65300;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO65301()
{
	return EO65301;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO65302()
{
	return EO65302;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO65303()
{
	return EO65303;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO65304()
{
	return EO65304;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO49174()
{
	return EO49174;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO49175()
{
	return EO49175;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO49176()
{
	return EO49176;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO49177()
{
	return EO49177;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO49178()
{
	return EO49178;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO49179()
{
	return EO49179;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO49180()
{
	return EO49180;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO47850()
{
	return EO47850;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO47851()
{
	return EO47851;
}


LensesTwoSurfaces EdmundOpticsLensCatalog::getEO47852()
{
	return EO47852;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO47853()
{
	return EO47853;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO47854()
{
	return EO47854;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO47855()
{
	return EO47855;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO47856()
{
	return EO47856;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO47857()
{
	return EO47857;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO48661()
{
	return EO48661;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO47858()
{
	return EO47858;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO47859()
{
	return EO47859;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO47860()
{
	return EO47860;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO49913()
{
	return EO49913;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO87917()
{
	return EO87917;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO87918()
{
	return EO87918;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO45465()
{
	return EO45465;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO49914()
{
	return EO49914;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO45466()
{
	return EO45466;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO38483()
{
	return EO38483;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO45467()
{
	return EO45467;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO45468()
{
	return EO45468;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO45469()
{
	return EO45469;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO38484()
{
	return EO38484;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO45470()
{
	return EO45470;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO45471()
{
	return EO45471;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO38485()
{
	return EO38485;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO45472()
{
	return EO45472;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO45473()
{
	return EO45473;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO47381()
{
	return EO47381;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO67178()
{
	return EO67178;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO45696()
{
	return EO45696;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO45474()
{
	return EO45474;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO49915()
{
	return EO49915;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO45475()
{
	return EO45475;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO49916()
{
	return EO49916;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO45476()
{
	return EO45476;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO38487()
{
	return EO38487;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO45477()
{
	return EO45477;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO38488()
{
	return EO38488;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO45478()
{
	return EO45478;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO45479()
{
	return EO45479;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO45703()
{
	return EO45703;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO67179()
{
	return EO67179;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO67180()
{
	return EO67180;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO67181()
{
	return EO67181;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO38486()
{
	return EO38486;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO63519()
{
	return EO63519;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO63520()
{
	return EO63520;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO63521()
{
	return EO63521;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO63522()
{
	return EO63522;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO63523()
{
	return EO63523;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO63524()
{
	return EO63524;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO63525()
{
	return EO63525;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO63526()
{
	return EO63526;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO63527()
{
	return EO63527;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO45480()
{
	return EO45480;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO45481()
{
	return EO45481;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO45482()
{
	return EO45482;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO49917()
{
	return EO49917;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO45483()
{
	return EO45483;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO45484()
{
	return EO45484;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO33355()
{
	return EO33355;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO45485()
{
	return EO45485;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO45486()
{
	return EO45486;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO45487()
{
	return EO45487;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO45488()
{
	return EO45488;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO45705()
{
	return EO45705;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO45489()
{
	return EO45489;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO45490()
{
	return EO45490;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO38501()
{
	return EO38501;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO38506()
{
	return EO38506;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO62591()
{
	return EO62591;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO62592()
{
	return EO62592;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO62593()
{
	return EO62593;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO38515()
{
	return EO38515;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO62594()
{
	return EO62594;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO38516()
{
	return EO38516;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO62595()
{
	return EO62595;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO62596()
{
	return EO62596;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO38517()
{
	return EO38517;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO62597()
{
	return EO62597;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO62598()
{
	return EO62598;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO45491()
{
	return EO45491;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO49918()
{
	return EO49918;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO63528()
{
	return EO63528;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO45492()
{
	return EO45492;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO45493()
{
	return EO45493;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO45494()
{
	return EO45494;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO49919()
{
	return EO49919;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO47382()
{
	return EO47382;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO47383()
{
	return EO47383;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO45706()
{
	return EO45706;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO48426()
{
	return EO48426;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO45496()
{
	return EO45496;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO45497()
{
	return EO45497;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO45498()
{
	return EO45498;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO45499()
{
	return EO45499;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO49921()
{
	return EO49921;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO45707()
{
	return EO45707;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO49922()
{
	return EO49922;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO45500()
{
	return EO45500;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO45501()
{
	return EO45501;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO45502()
{
	return EO45502;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO45503()
{
	return EO45503;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO47385()
{
	return EO47385;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO45708()
{
	return EO45708;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO47386()
{
	return EO47386;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO45504()
{
	return EO45504;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO45505()
{
	return EO45505;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO45506()
{
	return EO45506;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO45507()
{
	return EO45507;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO45508()
{
	return EO45508;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO45509()
{
	return EO45509;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO45510()
{
	return EO45510;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO45511()
{
	return EO45511;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO45512()
{
	return EO45512;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO45513()
{
	return EO45513;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO45514()
{
	return EO45514;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO45515()
{
	return EO45515;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO33361()
{
	return EO33361;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO67182()
{
	return EO67182;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO67183()
{
	return EO67183;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO33367()
{
	return EO33367;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO47387()
{
	return EO47387;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO47388()
{
	return EO47388;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO62599()
{
	return EO62599;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO62600()
{
	return EO62600;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO62601()
{
	return EO62601;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO62602()
{
	return EO62602;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO62603()
{
	return EO62603;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO62604()
{
	return EO62604;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO62605()
{
	return EO62605;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO48662()
{
	return EO48662;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO67184()
{
	return EO67184;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO45709()
{
	return EO45709;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO47389()
{
	return EO47389;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO45710()
{
	return EO45710;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO45711()
{
	return EO45711;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO47390()
{
	return EO47390;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO48663()
{
	return EO48663;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO45712()
{
	return EO45712;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO33385()
{
	return EO33385;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO33373()
{
	return EO33373;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO33379()
{
	return EO33379;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO47391()
{
	return EO47391;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO47392()
{
	return EO47392;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO45715()
{
	return EO45715;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO45716()
{
	return EO45716;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO45717()
{
	return EO45717;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO47393()
{
	return EO47393;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO45718()
{
	return EO45718;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO47394()
{
	return EO47394;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO47395()
{
	return EO47395;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO47396()
{
	return EO47396;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO47397()
{
	return EO47397;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO86911()
{
	return EO86911;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO86912()
{
	return EO86912;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO86913()
{
	return EO86913;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO86914()
{
	return EO86914;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO86915()
{
	return EO86915;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO38489()
{
	return EO38489;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO38492()
{
	return EO38492;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO38494()
{
	return EO38494;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO38496()
{
	return EO38496;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO38499()
{
	return EO38499;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO38500()
{
	return EO38500;
}


LensesTwoSurfaces EdmundOpticsLensCatalog::getEO38503()
{
	return EO38503;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO38504()
{
	return EO38504;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO38505()
{
	return EO38505;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO38507()
{
	return EO38507;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO38508()
{
	return EO38508;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO38509()
{
	return EO38509;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO38510()
{
	return EO38510;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO38512()
{
	return EO38512;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO38518()
{
	return EO38518;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO38519()
{
	return EO38519;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO38520()
{
	return EO38520;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO38521()
{
	return EO38521;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO38522()
{
	return EO38522;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO38523()
{
	return EO38523;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO38524()
{
	return EO38524;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO38525()
{
	return EO38525;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO38542()
{
	return EO38542;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO38543()
{
	return EO38543;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO38544()
{
	return EO38544;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO38545()
{
	return EO38545;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO38547()
{
	return EO38547;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO38548()
{
	return EO38548;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO38552()
{
	return EO38552;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO38561()
{
	return EO38561;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO38567()
{
	return EO38567;
}







LensesTwoSurfaces EdmundOpticsLensCatalog::getEO49447()
{
	return EO49447;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO49448()
{
	return EO49448;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO49449()
{
	return EO49449;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO49450()
{
	return EO49450;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO47893()
{
	return EO47893;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO47894()
{
	return EO47894;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO63658()
{
	return EO63658;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO63659()
{
	return EO63659;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO63660()
{
	return EO63660;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO63661()
{
	return EO63661;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO63662()
{
	return EO63662;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO45859()
{
	return EO45859;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO45860()
{
	return EO45860;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO45861()
{
	return EO45861;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO45862()
{
	return EO45862;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO45863()
{
	return EO45863;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO45864()
{
	return EO45864;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO45865()
{
	return EO45865;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO45866()
{
	return EO45866;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO45867()
{
	return EO45867;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO45868()
{
	return EO45868;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO45869()
{
	return EO45869;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO45870()
{
	return EO45870;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO45871()
{
	return EO45871;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO63663()
{
	return EO63663;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO63664()
{
	return EO63664;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO63665()
{
	return EO63665;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO63666()
{
	return EO63666;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO63667()
{
	return EO63667;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO63668()
{
	return EO63668;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO63669()
{
	return EO63669;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO63670()
{
	return EO63670;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO45872()
{
	return EO45872;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO45873()
{
	return EO45873;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO33391()
{
	return EO33391;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO45875()
{
	return EO45875;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO45876()
{
	return EO45876;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO45877()
{
	return EO45877;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO45878()
{
	return EO45878;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO45879()
{
	return EO45879;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO63671()
{
	return EO63671;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO45880()
{
	return EO45880;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO63672()
{
	return EO63672;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO45881()
{
	return EO45881;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO63673()
{
	return EO63673;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO45882()
{
	return EO45882;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO63674()
{
	return EO63674;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO63675()
{
	return EO63675;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO45883()
{
	return EO45883;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO45884()
{
	return EO45884;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO63678()
{
	return EO63678;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO63679()
{
	return EO63679;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO45885()
{
	return EO45885;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO45886()
{
	return EO45886;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO63680()
{
	return EO63680;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO63681()
{
	return EO63681;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO63682()
{
	return EO63682;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO45887()
{
	return EO45887;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO63683()
{
	return EO63683;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO45888()
{
	return EO45888;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO45889()
{
	return EO45889;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO45890()
{
	return EO45890;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO45891()
{
	return EO45891;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO45892()
{
	return EO45892;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO45893()
{
	return EO45893;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO45894()
{
	return EO45894;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO45895()
{
	return EO45895;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO33397()
{
	return EO33397;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO63684()
{
	return EO63684;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO45898()
{
	return EO45898;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO63685()
{
	return EO63685;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO45899()
{
	return EO45899;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO63686()
{
	return EO63686;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO63687()
{
	return EO63687;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO63688()
{
	return EO63688;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO45900()
{
	return EO45900;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO33422()
{
	return EO33422;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO33409()
{
	return EO33409;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO63689()
{
	return EO63689;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO33416()
{
	return EO33416;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO45905()
{
	return EO45905;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO45906()
{
	return EO45906;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO45907()
{
	return EO45907;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO45908()
{
	return EO45908;
}

LensesTwoSurfaces EdmundOpticsLensCatalog::getEO45909()
{
	return EO45909;
}

// achromatic lenses

//LensThreeSurfaces EdmundOpticsLensCatalog::getEO65564()
//{
//	return EO65564;
//}
//
//LensThreeSurfaces EdmundOpticsLensCatalog::getEO65565()
//{
//	return EO65565;
//}
//
//LensThreeSurfaces EdmundOpticsLensCatalog::getEO65566()
//{
//	return EO65566;
//}
//
//LensThreeSurfaces EdmundOpticsLensCatalog::getEO65567()
//{
//	return EO65567;
//}
//
//LensThreeSurfaces EdmundOpticsLensCatalog::getEO65568()
//{
//	return EO65568;
//}
//
//LensThreeSurfaces EdmundOpticsLensCatalog::getEO65569()
//{
//	return EO65569;
//}
//
//LensThreeSurfaces EdmundOpticsLensCatalog::getEO83338()
//{
//	return EO83338;
//}
//
//LensThreeSurfaces EdmundOpticsLensCatalog::getEO83339()
//{
//	return EO83339;
//}


LensThreeSurfaces EdmundOpticsLensCatalog::getEO45262()
{
	return EO45262;
}

LensThreeSurfaces EdmundOpticsLensCatalog::getEO47721()
{
	return EO47721;
}

LensThreeSurfaces EdmundOpticsLensCatalog::getEO45089()
{
	return EO45089;
}

LensThreeSurfaces EdmundOpticsLensCatalog::getEO45090()
{
	return EO45090;
}

LensThreeSurfaces EdmundOpticsLensCatalog::getEO63690()
{
	return EO63690;
}

LensThreeSurfaces EdmundOpticsLensCatalog::getEO63691()
{
	return EO63691;
}

LensThreeSurfaces EdmundOpticsLensCatalog::getEO63692()
{
	return EO63692;
}

LensThreeSurfaces EdmundOpticsLensCatalog::getEO45205()
{
	return EO45205;
}

LensThreeSurfaces EdmundOpticsLensCatalog::getEO45206()
{
	return EO45206;
}

LensThreeSurfaces EdmundOpticsLensCatalog::getEO49923()
{
	return EO49923;
}

LensThreeSurfaces EdmundOpticsLensCatalog::getEO45207()
{
	return EO45207;
}

LensThreeSurfaces EdmundOpticsLensCatalog::getEO45408()
{
	return EO45408;
}

LensThreeSurfaces EdmundOpticsLensCatalog::getEO45407()
{
	return EO45407;
}

LensThreeSurfaces EdmundOpticsLensCatalog::getEO49924()
{
	return EO49924;
}

LensThreeSurfaces EdmundOpticsLensCatalog::getEO45208()
{
	return EO45208;
}

LensThreeSurfaces EdmundOpticsLensCatalog::getEO32299()
{
	return EO32299;
}

LensThreeSurfaces EdmundOpticsLensCatalog::getEO32301()
{
	return EO32301;
}

LensThreeSurfaces EdmundOpticsLensCatalog::getEO49925()
{
	return EO49925;
}

LensThreeSurfaces EdmundOpticsLensCatalog::getEO32303()
{
	return EO32303;
}

LensThreeSurfaces EdmundOpticsLensCatalog::getEO32305()
{
	return EO32305;
}

LensThreeSurfaces EdmundOpticsLensCatalog::getEO45135()
{
	return EO45135;
}

LensThreeSurfaces EdmundOpticsLensCatalog::getEO32307()
{
	return EO32307;
}

LensThreeSurfaces EdmundOpticsLensCatalog::getEO45173()
{
	return EO45173;
}

LensThreeSurfaces EdmundOpticsLensCatalog::getEO45263()
{
	return EO45263;
}

LensThreeSurfaces EdmundOpticsLensCatalog::getEO45345()
{
	return EO45345;
}

LensThreeSurfaces EdmundOpticsLensCatalog::getEO65549()
{
	return EO65549;
}

LensThreeSurfaces EdmundOpticsLensCatalog::getEO45346()
{
	return EO45346;
}

LensThreeSurfaces EdmundOpticsLensCatalog::getEO49926()
{
	return EO49926;
}

LensThreeSurfaces EdmundOpticsLensCatalog::getEO45091()
{
	return EO45091;
}

LensThreeSurfaces EdmundOpticsLensCatalog::getEO49927()
{
	return EO49927;
}

LensThreeSurfaces EdmundOpticsLensCatalog::getEO45092()
{
	return EO45092;
}

LensThreeSurfaces EdmundOpticsLensCatalog::getEO45264()
{
	return EO45264;
}

LensThreeSurfaces EdmundOpticsLensCatalog::getEO45818()
{
	return EO45818;
}

LensThreeSurfaces EdmundOpticsLensCatalog::getEO45347()
{
	return EO45347;
}

LensThreeSurfaces EdmundOpticsLensCatalog::getEO45819()
{
	return EO45819;
}

LensThreeSurfaces EdmundOpticsLensCatalog::getEO45820()
{
	return EO45820;
}

LensThreeSurfaces EdmundOpticsLensCatalog::getEO63693()
{
	return EO63693;
}

LensThreeSurfaces EdmundOpticsLensCatalog::getEO63694()
{
	return EO63694;
}

LensThreeSurfaces EdmundOpticsLensCatalog::getEO63695()
{
	return EO63695;
}

LensThreeSurfaces EdmundOpticsLensCatalog::getEO63696()
{
	return EO63696;
}

LensThreeSurfaces EdmundOpticsLensCatalog::getEO63697()
{
	return EO63697;
}

LensThreeSurfaces EdmundOpticsLensCatalog::getEO63698()
{
	return EO63698;
}

LensThreeSurfaces EdmundOpticsLensCatalog::getEO63699()
{
	return EO63699;
}

LensThreeSurfaces EdmundOpticsLensCatalog::getEO65550()
{
	return EO65550;
}

LensThreeSurfaces EdmundOpticsLensCatalog::getEO45209()
{
	return EO45209;
}

LensThreeSurfaces EdmundOpticsLensCatalog::getEO63700()
{
	return EO63700;
}

LensThreeSurfaces EdmundOpticsLensCatalog::getEO49928()
{
	return EO49928;
}

LensThreeSurfaces EdmundOpticsLensCatalog::getEO32309()
{
	return EO32309;
}

LensThreeSurfaces EdmundOpticsLensCatalog::getEO32311()
{
	return EO32311;
}

LensThreeSurfaces EdmundOpticsLensCatalog::getEO32313()
{
	return EO32313;
}

LensThreeSurfaces EdmundOpticsLensCatalog::getEO45210()
{
	return EO45210;
}

LensThreeSurfaces EdmundOpticsLensCatalog::getEO32315()
{
	return EO32315;
}

LensThreeSurfaces EdmundOpticsLensCatalog::getEO45136()
{
	return EO45136;
}

LensThreeSurfaces EdmundOpticsLensCatalog::getEO32317()
{
	return EO32317;
}

LensThreeSurfaces EdmundOpticsLensCatalog::getEO45137()
{
	return EO45137;
}

LensThreeSurfaces EdmundOpticsLensCatalog::getEO32882()
{
	return EO32882;
}

LensThreeSurfaces EdmundOpticsLensCatalog::getEO45409()
{
	return EO45409;
}

LensThreeSurfaces EdmundOpticsLensCatalog::getEO45410()
{
	return EO45410;
}

LensThreeSurfaces EdmundOpticsLensCatalog::getEO45265()
{
	return EO45265;
}

LensThreeSurfaces EdmundOpticsLensCatalog::getEO49758()
{
	return EO49758;
}

LensThreeSurfaces EdmundOpticsLensCatalog::getEO49759()
{
	return EO49759;
}

LensThreeSurfaces EdmundOpticsLensCatalog::getEO49760()
{
	return EO49760;
}

LensThreeSurfaces EdmundOpticsLensCatalog::getEO49761()
{
	return EO49761;
}

LensThreeSurfaces EdmundOpticsLensCatalog::getEO49762()
{
	return EO49762;
}

LensThreeSurfaces EdmundOpticsLensCatalog::getEO49763()
{
	return EO49763;
}

LensThreeSurfaces EdmundOpticsLensCatalog::getEO49764()
{
	return EO49764;
}

LensThreeSurfaces EdmundOpticsLensCatalog::getEO83415()
{
	return EO83415;
}

LensThreeSurfaces EdmundOpticsLensCatalog::getEO65551()
{
	return EO65551;
}

LensThreeSurfaces EdmundOpticsLensCatalog::getEO49929()
{
	return EO49929;
}

LensThreeSurfaces EdmundOpticsLensCatalog::getEO45174()
{
	return EO45174;
}

LensThreeSurfaces EdmundOpticsLensCatalog::getEO32720()
{
	return EO32720;
}

LensThreeSurfaces EdmundOpticsLensCatalog::getEO45103()
{
	return EO45103;
}

LensThreeSurfaces EdmundOpticsLensCatalog::getEO45138()
{
	return EO45138;
}

LensThreeSurfaces EdmundOpticsLensCatalog::getEO49930()
{
	return EO49930;
}

LensThreeSurfaces EdmundOpticsLensCatalog::getEO45139()
{
	return EO45139;
}

LensThreeSurfaces EdmundOpticsLensCatalog::getEO45266()
{
	return EO45266;
}

LensThreeSurfaces EdmundOpticsLensCatalog::getEO49931()
{
	return EO49931;
}

LensThreeSurfaces EdmundOpticsLensCatalog::getEO45412()
{
	return EO45412;
}

LensThreeSurfaces EdmundOpticsLensCatalog::getEO45348()
{
	return EO45348;
}

LensThreeSurfaces EdmundOpticsLensCatalog::getEO45413()
{
	return EO45413;
}

LensThreeSurfaces EdmundOpticsLensCatalog::getEO45104()
{
	return EO45104;
}

LensThreeSurfaces EdmundOpticsLensCatalog::getEO32913()
{
	return EO32913;
}

LensThreeSurfaces EdmundOpticsLensCatalog::getEO45349()
{
	return EO45349;
}

LensThreeSurfaces EdmundOpticsLensCatalog::getEO45350()
{
	return EO45350;
}

LensThreeSurfaces EdmundOpticsLensCatalog::getEO32915()
{
	return EO32915;
}

LensThreeSurfaces EdmundOpticsLensCatalog::getEO65552()
{
	return EO65552;
}

LensThreeSurfaces EdmundOpticsLensCatalog::getEO49932()
{
	return EO49932;
}

LensThreeSurfaces EdmundOpticsLensCatalog::getEO45175()
{
	return EO45175;
}

LensThreeSurfaces EdmundOpticsLensCatalog::getEO45351()
{
	return EO45351;
}

LensThreeSurfaces EdmundOpticsLensCatalog::getEO32722()
{
	return EO32722;
}

LensThreeSurfaces EdmundOpticsLensCatalog::getEO49933()
{
	return EO49933;
}

LensThreeSurfaces EdmundOpticsLensCatalog::getEO45267()
{
	return EO45267;
}

LensThreeSurfaces EdmundOpticsLensCatalog::getEO49934()
{
	return EO49934;
}

LensThreeSurfaces EdmundOpticsLensCatalog::getEO65553()
{
	return EO65553;
}
LensThreeSurfaces EdmundOpticsLensCatalog::getEO45211()
{
	return EO45211;
}

LensThreeSurfaces EdmundOpticsLensCatalog::getEO32319()
{
	return EO32319;
}

LensThreeSurfaces EdmundOpticsLensCatalog::getEO32321()
{
	return EO32321;
}

LensThreeSurfaces EdmundOpticsLensCatalog::getEO45212()
{
	return EO45212;
}

LensThreeSurfaces EdmundOpticsLensCatalog::getEO32323()
{
	return EO32323;
}

LensThreeSurfaces EdmundOpticsLensCatalog::getEO32724()
{
	return EO32724;
}

LensThreeSurfaces EdmundOpticsLensCatalog::getEO32325()
{
	return EO32325;
}

LensThreeSurfaces EdmundOpticsLensCatalog::getEO45213()
{
	return EO45213;
}

LensThreeSurfaces EdmundOpticsLensCatalog::getEO32327()
{
	return EO32327;
}

LensThreeSurfaces EdmundOpticsLensCatalog::getEO32492()
{
	return EO32492;
}
LensThreeSurfaces EdmundOpticsLensCatalog::getEO32494()
{
	return EO32494;
}

LensThreeSurfaces EdmundOpticsLensCatalog::getEO67328()
{
	return EO67328;
}

LensThreeSurfaces EdmundOpticsLensCatalog::getEO32884()
{
	return EO32884;
}

LensThreeSurfaces EdmundOpticsLensCatalog::getEO32917()
{
	return EO32917;
}

LensThreeSurfaces EdmundOpticsLensCatalog::getEO45214()
{
	return EO45214;
}

LensThreeSurfaces EdmundOpticsLensCatalog::getEO32919()
{
	return EO32919;
}

LensThreeSurfaces EdmundOpticsLensCatalog::getEO45414()
{
	return EO45414;
}

LensThreeSurfaces EdmundOpticsLensCatalog::getEO45215()
{
	return EO45215;
}

LensThreeSurfaces EdmundOpticsLensCatalog::getEO45216()
{
	return EO45216;
}

LensThreeSurfaces EdmundOpticsLensCatalog::getEO45268()
{
	return EO45268;
}

LensThreeSurfaces EdmundOpticsLensCatalog::getEO67329()
{
	return EO67329;
}

LensThreeSurfaces EdmundOpticsLensCatalog::getEO49765()
{
	return EO49765;
}

LensThreeSurfaces EdmundOpticsLensCatalog::getEO49766()
{
	return EO49766;
}

LensThreeSurfaces EdmundOpticsLensCatalog::getEO49767()
{
	return EO49767;
}

LensThreeSurfaces EdmundOpticsLensCatalog::getEO49768()
{
	return EO49768;
}

LensThreeSurfaces EdmundOpticsLensCatalog::getEO49769()
{
	return EO49769;
}

LensThreeSurfaces EdmundOpticsLensCatalog::getEO49770()
{
	return EO49770;
}

LensThreeSurfaces EdmundOpticsLensCatalog::getEO33917()
{
	return EO33917;
}
LensThreeSurfaces EdmundOpticsLensCatalog::getEO32500()
{
	return EO32500;
}

LensThreeSurfaces EdmundOpticsLensCatalog::getEO45217()
{
	return EO45217;
}

LensThreeSurfaces EdmundOpticsLensCatalog::getEO32502()
{
	return EO32502;
}

LensThreeSurfaces EdmundOpticsLensCatalog::getEO45415()
{
	return EO45415;
}

LensThreeSurfaces EdmundOpticsLensCatalog::getEO45269()
{
	return EO45269;
}

LensThreeSurfaces EdmundOpticsLensCatalog::getEO32496()
{
	return EO32496;
}

LensThreeSurfaces EdmundOpticsLensCatalog::getEO45140()
{
	return EO45140;
}

LensThreeSurfaces EdmundOpticsLensCatalog::getEO32498()
{
	return EO32498;
}

LensThreeSurfaces EdmundOpticsLensCatalog::getEO89681()
{
	return EO89681;
}

LensThreeSurfaces EdmundOpticsLensCatalog::getEO45218()
{
	return EO45218;
}

LensThreeSurfaces EdmundOpticsLensCatalog::getEO45105()
{
	return EO45105;
}

LensThreeSurfaces EdmundOpticsLensCatalog::getEO63701()
{
	return EO63701;
}

LensThreeSurfaces EdmundOpticsLensCatalog::getEO32921()
{
	return EO32921;
}

LensThreeSurfaces EdmundOpticsLensCatalog::getEO32923()
{
	return EO32923;
}

LensThreeSurfaces EdmundOpticsLensCatalog::getEO32925()
{
	return EO32925;
}

LensThreeSurfaces EdmundOpticsLensCatalog::getEO32935()
{
	return EO32935;
}

LensThreeSurfaces EdmundOpticsLensCatalog::getEO45178()
{
	return EO45178;
}

LensThreeSurfaces EdmundOpticsLensCatalog::getEO32927()
{
	return EO32927;
}


LensThreeSurfaces EdmundOpticsLensCatalog::getEO45352()
{
	return EO45352;
}

LensThreeSurfaces EdmundOpticsLensCatalog::getEO45270()
{
	return EO45270;
}

LensThreeSurfaces EdmundOpticsLensCatalog::getEO67330()
{
	return EO67330;
}

LensThreeSurfaces EdmundOpticsLensCatalog::getEO49291()
{
	return EO49291;
}

LensThreeSurfaces EdmundOpticsLensCatalog::getEO45353()
{
	return EO45353;
}

LensThreeSurfaces EdmundOpticsLensCatalog::getEO32886()
{
	return EO32886;
}

LensThreeSurfaces EdmundOpticsLensCatalog::getEO45179()
{
	return EO45179;
}

LensThreeSurfaces EdmundOpticsLensCatalog::getEO45180()
{
	return EO45180;
}

LensThreeSurfaces EdmundOpticsLensCatalog::getEO45181()
{
	return EO45181;
}

LensThreeSurfaces EdmundOpticsLensCatalog::getEO45354()
{
	return EO45354;
}

LensThreeSurfaces EdmundOpticsLensCatalog::getEO45271()
{
	return EO45271;
}

LensThreeSurfaces EdmundOpticsLensCatalog::getEO33918()
{
	return EO33918;
}

LensThreeSurfaces EdmundOpticsLensCatalog::getEO33919()
{
	return EO33919;
}

LensThreeSurfaces EdmundOpticsLensCatalog::getEO45417()
{
	return EO45417;
}

LensThreeSurfaces EdmundOpticsLensCatalog::getEO45418()
{
	return EO45418;
}

LensThreeSurfaces EdmundOpticsLensCatalog::getEO45419()
{
	return EO45419;
}

// Doppelkonkave Linsen (DCV) mit NIR-I-Beschichtung
//https://www.edmundoptics.de/f/nir-i-coated-double-concave-dcv-lenses/13500/
LensesTwoSurfaces EdmundOpticsLensCatalog::getEO49540()
{
	return EO49540;
}

// Achromate mit VIS-NIR-Beschichtung 
//https://www.edmundoptics.de/f/vis-nir-coated-achromatic-lenses/13536/
LensThreeSurfaces EdmundOpticsLensCatalog::getEO84127()
{
	return EO84127;
}


std::vector<LensesTwoSurfaces> EdmundOpticsLensCatalog::getAll_DoubleConvexLenses()
{
	std::vector<LensesTwoSurfaces> returnDoubleConvexLenses;

	// https://www.edmundoptics.de/f/vis-nir-coated-double-convex-dcx-lenses/13504/
	returnDoubleConvexLenses.push_back(getEO49447());
	returnDoubleConvexLenses.push_back(getEO49448());
	returnDoubleConvexLenses.push_back(getEO49449());
	returnDoubleConvexLenses.push_back(getEO49450());
	returnDoubleConvexLenses.push_back(getEO47893());
	returnDoubleConvexLenses.push_back(getEO47894());
	returnDoubleConvexLenses.push_back(getEO63658());
	returnDoubleConvexLenses.push_back(getEO63659());
	returnDoubleConvexLenses.push_back(getEO63660());
	returnDoubleConvexLenses.push_back(getEO63661());
	returnDoubleConvexLenses.push_back(getEO63662());
	returnDoubleConvexLenses.push_back(getEO45859());
	returnDoubleConvexLenses.push_back(getEO45860());
	returnDoubleConvexLenses.push_back(getEO45861());
	returnDoubleConvexLenses.push_back(getEO45862());
	returnDoubleConvexLenses.push_back(getEO45863());
	returnDoubleConvexLenses.push_back(getEO45864());
	returnDoubleConvexLenses.push_back(getEO45865());
	returnDoubleConvexLenses.push_back(getEO45866());
	returnDoubleConvexLenses.push_back(getEO45867());
	returnDoubleConvexLenses.push_back(getEO45868());
	returnDoubleConvexLenses.push_back(getEO45869());
	returnDoubleConvexLenses.push_back(getEO45870());
	returnDoubleConvexLenses.push_back(getEO45871());
	returnDoubleConvexLenses.push_back(getEO63663());
	returnDoubleConvexLenses.push_back(getEO63664());
	returnDoubleConvexLenses.push_back(getEO63665());
	returnDoubleConvexLenses.push_back(getEO63666());
	returnDoubleConvexLenses.push_back(getEO63667());
	returnDoubleConvexLenses.push_back(getEO63668());
	returnDoubleConvexLenses.push_back(getEO63669());
	returnDoubleConvexLenses.push_back(getEO63670());
	returnDoubleConvexLenses.push_back(getEO45872());
	returnDoubleConvexLenses.push_back(getEO45873());
	returnDoubleConvexLenses.push_back(getEO33391());
	returnDoubleConvexLenses.push_back(getEO45875());
	returnDoubleConvexLenses.push_back(getEO45876());
	returnDoubleConvexLenses.push_back(getEO45877());
	returnDoubleConvexLenses.push_back(getEO45878());
	returnDoubleConvexLenses.push_back(getEO45879());
	returnDoubleConvexLenses.push_back(getEO63671());
	returnDoubleConvexLenses.push_back(getEO45880());
	returnDoubleConvexLenses.push_back(getEO63672());
	returnDoubleConvexLenses.push_back(getEO45881());
	returnDoubleConvexLenses.push_back(getEO63673());
	returnDoubleConvexLenses.push_back(getEO45882());
	returnDoubleConvexLenses.push_back(getEO63674());
	returnDoubleConvexLenses.push_back(getEO63675());
	returnDoubleConvexLenses.push_back(getEO45883());
	returnDoubleConvexLenses.push_back(getEO45884());
	returnDoubleConvexLenses.push_back(getEO63678());
	returnDoubleConvexLenses.push_back(getEO63679());
	returnDoubleConvexLenses.push_back(getEO45885());
	returnDoubleConvexLenses.push_back(getEO45886());
	returnDoubleConvexLenses.push_back(getEO63680());
	returnDoubleConvexLenses.push_back(getEO63681());
	returnDoubleConvexLenses.push_back(getEO63682());
	returnDoubleConvexLenses.push_back(getEO45887());
	returnDoubleConvexLenses.push_back(getEO63683());
	returnDoubleConvexLenses.push_back(getEO45888());
	returnDoubleConvexLenses.push_back(getEO45889());
	returnDoubleConvexLenses.push_back(getEO45890());
	returnDoubleConvexLenses.push_back(getEO45891());
	returnDoubleConvexLenses.push_back(getEO45892());
	returnDoubleConvexLenses.push_back(getEO45893());
	returnDoubleConvexLenses.push_back(getEO45894());
	returnDoubleConvexLenses.push_back(getEO45895());
	returnDoubleConvexLenses.push_back(getEO33397());
	returnDoubleConvexLenses.push_back(getEO63684());
	returnDoubleConvexLenses.push_back(getEO45898());
	returnDoubleConvexLenses.push_back(getEO63685());
	returnDoubleConvexLenses.push_back(getEO45899());
	returnDoubleConvexLenses.push_back(getEO63686());
	returnDoubleConvexLenses.push_back(getEO63687());
	returnDoubleConvexLenses.push_back(getEO63688());
	returnDoubleConvexLenses.push_back(getEO45900());
	returnDoubleConvexLenses.push_back(getEO33422());
	returnDoubleConvexLenses.push_back(getEO33409());
	returnDoubleConvexLenses.push_back(getEO63689());
	returnDoubleConvexLenses.push_back(getEO33416());
	returnDoubleConvexLenses.push_back(getEO45905());
	returnDoubleConvexLenses.push_back(getEO45906());
	returnDoubleConvexLenses.push_back(getEO45907());
	returnDoubleConvexLenses.push_back(getEO45908());
	returnDoubleConvexLenses.push_back(getEO45909());

	return returnDoubleConvexLenses;

}

std::vector<LensThreeSurfaces> EdmundOpticsLensCatalog::getAll_achroamticLensesMgF()
{
	std::vector<LensThreeSurfaces> returnAchromaticLenses;

	// https://www.edmundoptics.de/f/MgFsub2sub-Coated-Achromatic-Lenses/12006/
	//returnAchromaticLenses.push_back(getEO65564());
	//returnAchromaticLenses.push_back(getEO65565());
	//returnAchromaticLenses.push_back(getEO65566());
	//returnAchromaticLenses.push_back(getEO65567());
	//returnAchromaticLenses.push_back(getEO65568());
	//returnAchromaticLenses.push_back(getEO65569());
	//returnAchromaticLenses.push_back(getEO83338());
	//returnAchromaticLenses.push_back(getEO83339());
	returnAchromaticLenses.push_back(getEO45262());
	returnAchromaticLenses.push_back(getEO47721());
	returnAchromaticLenses.push_back(getEO45089());
	returnAchromaticLenses.push_back(getEO45090());
	returnAchromaticLenses.push_back(getEO63690());
	returnAchromaticLenses.push_back(getEO63691());
	returnAchromaticLenses.push_back(getEO63692());
	returnAchromaticLenses.push_back(getEO45205());
	returnAchromaticLenses.push_back(getEO45206());
	returnAchromaticLenses.push_back(getEO49923());
	returnAchromaticLenses.push_back(getEO45207());
	returnAchromaticLenses.push_back(getEO45408());
	returnAchromaticLenses.push_back(getEO45407());
	returnAchromaticLenses.push_back(getEO49924());
	returnAchromaticLenses.push_back(getEO45208());
	returnAchromaticLenses.push_back(getEO32299());
	returnAchromaticLenses.push_back(getEO32301());
	returnAchromaticLenses.push_back(getEO49925());
	returnAchromaticLenses.push_back(getEO32303());
	returnAchromaticLenses.push_back(getEO32305());
	returnAchromaticLenses.push_back(getEO45135());
	returnAchromaticLenses.push_back(getEO32307());
	returnAchromaticLenses.push_back(getEO45173());
	returnAchromaticLenses.push_back(getEO45263());
	returnAchromaticLenses.push_back(getEO45345());
	returnAchromaticLenses.push_back(getEO65549());
	returnAchromaticLenses.push_back(getEO45346());
	returnAchromaticLenses.push_back(getEO49926());
	returnAchromaticLenses.push_back(getEO45091());
	returnAchromaticLenses.push_back(getEO49927());
	returnAchromaticLenses.push_back(getEO45092());
	returnAchromaticLenses.push_back(getEO45264());
	returnAchromaticLenses.push_back(getEO45818());
	returnAchromaticLenses.push_back(getEO45347());
	returnAchromaticLenses.push_back(getEO45819());
	returnAchromaticLenses.push_back(getEO45820());
	returnAchromaticLenses.push_back(getEO63693());
	returnAchromaticLenses.push_back(getEO63694());
	returnAchromaticLenses.push_back(getEO63695());
	returnAchromaticLenses.push_back(getEO63696());
	returnAchromaticLenses.push_back(getEO63697());
	returnAchromaticLenses.push_back(getEO63698());
	returnAchromaticLenses.push_back(getEO63699());
	returnAchromaticLenses.push_back(getEO65550());
	returnAchromaticLenses.push_back(getEO45209());
	returnAchromaticLenses.push_back(getEO63700());
	returnAchromaticLenses.push_back(getEO49928());
	returnAchromaticLenses.push_back(getEO32309());
	returnAchromaticLenses.push_back(getEO32311());
	returnAchromaticLenses.push_back(getEO32313());
	returnAchromaticLenses.push_back(getEO45210());
	returnAchromaticLenses.push_back(getEO32315());
	returnAchromaticLenses.push_back(getEO45136());
	returnAchromaticLenses.push_back(getEO32317());
	returnAchromaticLenses.push_back(getEO45137());
	returnAchromaticLenses.push_back(getEO32882());
	returnAchromaticLenses.push_back(getEO45409());
	returnAchromaticLenses.push_back(getEO45410());
	returnAchromaticLenses.push_back(getEO45265());
	returnAchromaticLenses.push_back(getEO49758());
	returnAchromaticLenses.push_back(getEO49759());
	returnAchromaticLenses.push_back(getEO49760());
	returnAchromaticLenses.push_back(getEO49761());
	returnAchromaticLenses.push_back(getEO49762());
	returnAchromaticLenses.push_back(getEO49763());
	returnAchromaticLenses.push_back(getEO49764());
	returnAchromaticLenses.push_back(getEO83415());
	returnAchromaticLenses.push_back(getEO65551());
	returnAchromaticLenses.push_back(getEO49929());
	returnAchromaticLenses.push_back(getEO45174());
	returnAchromaticLenses.push_back(getEO32720());
	returnAchromaticLenses.push_back(getEO45103());
	returnAchromaticLenses.push_back(getEO45138());
	returnAchromaticLenses.push_back(getEO49930());
	returnAchromaticLenses.push_back(getEO45139());
	returnAchromaticLenses.push_back(getEO45266());
	returnAchromaticLenses.push_back(getEO49931());
	returnAchromaticLenses.push_back(getEO45412());
	returnAchromaticLenses.push_back(getEO45348());
	returnAchromaticLenses.push_back(getEO45413());
	returnAchromaticLenses.push_back(getEO45104());
	returnAchromaticLenses.push_back(getEO32913());
	returnAchromaticLenses.push_back(getEO45349());
	returnAchromaticLenses.push_back(getEO45350());
	returnAchromaticLenses.push_back(getEO32915());
	returnAchromaticLenses.push_back(getEO65552());
	returnAchromaticLenses.push_back(getEO49932());
	returnAchromaticLenses.push_back(getEO45175());
	returnAchromaticLenses.push_back(getEO45351());
	returnAchromaticLenses.push_back(getEO32722());
	returnAchromaticLenses.push_back(getEO49933());
	returnAchromaticLenses.push_back(getEO45267());
	returnAchromaticLenses.push_back(getEO49934());
	returnAchromaticLenses.push_back(getEO65553());
	returnAchromaticLenses.push_back(getEO45211());
	returnAchromaticLenses.push_back(getEO32319());
	returnAchromaticLenses.push_back(getEO32321());
	returnAchromaticLenses.push_back(getEO45212());
	returnAchromaticLenses.push_back(getEO32323());
	returnAchromaticLenses.push_back(getEO32724());
	returnAchromaticLenses.push_back(getEO32325());
	returnAchromaticLenses.push_back(getEO45213());
	returnAchromaticLenses.push_back(getEO32327());
	returnAchromaticLenses.push_back(getEO32492());
	returnAchromaticLenses.push_back(getEO32494());
	returnAchromaticLenses.push_back(getEO67328());
	returnAchromaticLenses.push_back(getEO32884());
	returnAchromaticLenses.push_back(getEO32917());
	returnAchromaticLenses.push_back(getEO45214());
	returnAchromaticLenses.push_back(getEO32919());
	returnAchromaticLenses.push_back(getEO45414());
	returnAchromaticLenses.push_back(getEO45215());
	returnAchromaticLenses.push_back(getEO45216());
	returnAchromaticLenses.push_back(getEO45268());
	returnAchromaticLenses.push_back(getEO67329());
	returnAchromaticLenses.push_back(getEO49765());
	returnAchromaticLenses.push_back(getEO49766());
	returnAchromaticLenses.push_back(getEO49767());
	returnAchromaticLenses.push_back(getEO49768());
	returnAchromaticLenses.push_back(getEO49769());
	returnAchromaticLenses.push_back(getEO49770());
	returnAchromaticLenses.push_back(getEO33917());
	returnAchromaticLenses.push_back(getEO32500());
	returnAchromaticLenses.push_back(getEO45217());
	returnAchromaticLenses.push_back(getEO32502());
	returnAchromaticLenses.push_back(getEO45415());
	returnAchromaticLenses.push_back(getEO45269());
	returnAchromaticLenses.push_back(getEO32496());
	returnAchromaticLenses.push_back(getEO45140());
	returnAchromaticLenses.push_back(getEO32498());
	returnAchromaticLenses.push_back(getEO89681());
	returnAchromaticLenses.push_back(getEO45218());
	returnAchromaticLenses.push_back(getEO45105());
	returnAchromaticLenses.push_back(getEO63701());
	returnAchromaticLenses.push_back(getEO32921());
	returnAchromaticLenses.push_back(getEO32923());
	returnAchromaticLenses.push_back(getEO32925());
	returnAchromaticLenses.push_back(getEO32935());
	returnAchromaticLenses.push_back(getEO45178());
	returnAchromaticLenses.push_back(getEO32927());
	returnAchromaticLenses.push_back(getEO45352());
	returnAchromaticLenses.push_back(getEO45270());
	returnAchromaticLenses.push_back(getEO67330());
	returnAchromaticLenses.push_back(getEO49291());
	returnAchromaticLenses.push_back(getEO45353());
	returnAchromaticLenses.push_back(getEO32886());
	returnAchromaticLenses.push_back(getEO45179());
	returnAchromaticLenses.push_back(getEO45180());
	returnAchromaticLenses.push_back(getEO45181());
	returnAchromaticLenses.push_back(getEO45354());
	returnAchromaticLenses.push_back(getEO45271());
	returnAchromaticLenses.push_back(getEO33918());
	returnAchromaticLenses.push_back(getEO33919());
	returnAchromaticLenses.push_back(getEO45417());
	returnAchromaticLenses.push_back(getEO45418());
	returnAchromaticLenses.push_back(getEO45419());

	return returnAchromaticLenses;
}


std::vector<LensesTwoSurfaces> EdmundOpticsLensCatalog::getAll_PlanConvexLenses()
{
	std::vector<LensesTwoSurfaces> returnPlanConvexLenses;

https://www.edmundoptics.de/f/vis-nir-coated-plano-convex-pcx-lenses/12278/
	returnPlanConvexLenses.push_back(getEO65289());
	returnPlanConvexLenses.push_back(getEO65290());
	returnPlanConvexLenses.push_back(getEO65291());
	returnPlanConvexLenses.push_back(getEO65292());
	returnPlanConvexLenses.push_back(getEO65293());
	returnPlanConvexLenses.push_back(getEO65294());
	returnPlanConvexLenses.push_back(getEO65295());
	returnPlanConvexLenses.push_back(getEO65296());
	returnPlanConvexLenses.push_back(getEO65297());
	returnPlanConvexLenses.push_back(getEO65298());
	returnPlanConvexLenses.push_back(getEO65299());
	returnPlanConvexLenses.push_back(getEO65300());
	returnPlanConvexLenses.push_back(getEO65301());
	returnPlanConvexLenses.push_back(getEO65302());
	returnPlanConvexLenses.push_back(getEO65303());
	returnPlanConvexLenses.push_back(getEO65304());
	returnPlanConvexLenses.push_back(getEO49174());
	returnPlanConvexLenses.push_back(getEO49175());
	returnPlanConvexLenses.push_back(getEO49176());
	returnPlanConvexLenses.push_back(getEO49177());
	returnPlanConvexLenses.push_back(getEO49178());
	returnPlanConvexLenses.push_back(getEO49179());
	returnPlanConvexLenses.push_back(getEO49180());
	returnPlanConvexLenses.push_back(getEO47850());
	returnPlanConvexLenses.push_back(getEO47851());
	returnPlanConvexLenses.push_back(getEO47852());
	returnPlanConvexLenses.push_back(getEO47853());
	returnPlanConvexLenses.push_back(getEO47854());
	returnPlanConvexLenses.push_back(getEO47855());
	returnPlanConvexLenses.push_back(getEO47856());
	returnPlanConvexLenses.push_back(getEO47857());
	returnPlanConvexLenses.push_back(getEO48661());
	returnPlanConvexLenses.push_back(getEO47858());
	returnPlanConvexLenses.push_back(getEO47859());
	returnPlanConvexLenses.push_back(getEO47860());
	returnPlanConvexLenses.push_back(getEO49913());
	returnPlanConvexLenses.push_back(getEO87917());
	returnPlanConvexLenses.push_back(getEO87918());
	returnPlanConvexLenses.push_back(getEO45465());
	returnPlanConvexLenses.push_back(getEO49914());
	returnPlanConvexLenses.push_back(getEO45466());
	returnPlanConvexLenses.push_back(getEO38483());
	returnPlanConvexLenses.push_back(getEO45467());
	returnPlanConvexLenses.push_back(getEO45468());
	returnPlanConvexLenses.push_back(getEO45469());
	returnPlanConvexLenses.push_back(getEO38484());
	returnPlanConvexLenses.push_back(getEO45470());
	returnPlanConvexLenses.push_back(getEO45471());
	returnPlanConvexLenses.push_back(getEO38485());
	returnPlanConvexLenses.push_back(getEO45472());
	returnPlanConvexLenses.push_back(getEO45473());
	returnPlanConvexLenses.push_back(getEO47381());
	returnPlanConvexLenses.push_back(getEO67178());
	returnPlanConvexLenses.push_back(getEO45696());
	returnPlanConvexLenses.push_back(getEO45474());
	returnPlanConvexLenses.push_back(getEO49915());
	returnPlanConvexLenses.push_back(getEO45475());
	returnPlanConvexLenses.push_back(getEO49916());
	returnPlanConvexLenses.push_back(getEO45476());
	returnPlanConvexLenses.push_back(getEO38487());
	returnPlanConvexLenses.push_back(getEO45477());
	returnPlanConvexLenses.push_back(getEO38488());
	returnPlanConvexLenses.push_back(getEO45478());
	returnPlanConvexLenses.push_back(getEO45479());
	returnPlanConvexLenses.push_back(getEO45703());
	returnPlanConvexLenses.push_back(getEO67179());
	returnPlanConvexLenses.push_back(getEO67180());
	returnPlanConvexLenses.push_back(getEO67181());
	returnPlanConvexLenses.push_back(getEO38486());
	returnPlanConvexLenses.push_back(getEO63519());
	returnPlanConvexLenses.push_back(getEO63520());
	returnPlanConvexLenses.push_back(getEO63521());
	returnPlanConvexLenses.push_back(getEO63522());
	returnPlanConvexLenses.push_back(getEO63523());
	returnPlanConvexLenses.push_back(getEO63524());
	returnPlanConvexLenses.push_back(getEO63525());
	returnPlanConvexLenses.push_back(getEO63526());
	returnPlanConvexLenses.push_back(getEO63527());
	returnPlanConvexLenses.push_back(getEO45480());
	returnPlanConvexLenses.push_back(getEO45481());
	returnPlanConvexLenses.push_back(getEO45482());
	returnPlanConvexLenses.push_back(getEO49917());
	returnPlanConvexLenses.push_back(getEO45483());
	returnPlanConvexLenses.push_back(getEO45484());
	returnPlanConvexLenses.push_back(getEO33355());
	returnPlanConvexLenses.push_back(getEO45485());
	returnPlanConvexLenses.push_back(getEO45486());
	returnPlanConvexLenses.push_back(getEO45487());
	returnPlanConvexLenses.push_back(getEO45488());
	returnPlanConvexLenses.push_back(getEO45705());
	returnPlanConvexLenses.push_back(getEO45489());
	returnPlanConvexLenses.push_back(getEO45490());
	returnPlanConvexLenses.push_back(getEO38501());
	returnPlanConvexLenses.push_back(getEO38506());
	returnPlanConvexLenses.push_back(getEO62591());
	returnPlanConvexLenses.push_back(getEO62592());
	returnPlanConvexLenses.push_back(getEO62593());
	returnPlanConvexLenses.push_back(getEO38515());
	returnPlanConvexLenses.push_back(getEO62594());
	returnPlanConvexLenses.push_back(getEO38516());
	returnPlanConvexLenses.push_back(getEO62595());
	returnPlanConvexLenses.push_back(getEO62596());
	returnPlanConvexLenses.push_back(getEO38517());
	returnPlanConvexLenses.push_back(getEO62597());
	returnPlanConvexLenses.push_back(getEO62598());
	returnPlanConvexLenses.push_back(getEO45491());
	returnPlanConvexLenses.push_back(getEO49918());
	returnPlanConvexLenses.push_back(getEO63528());
	returnPlanConvexLenses.push_back(getEO45492());
	returnPlanConvexLenses.push_back(getEO45493());
	returnPlanConvexLenses.push_back(getEO45494());
	returnPlanConvexLenses.push_back(getEO49919());
	returnPlanConvexLenses.push_back(getEO47382());
	returnPlanConvexLenses.push_back(getEO47383());
	returnPlanConvexLenses.push_back(getEO45706());
	returnPlanConvexLenses.push_back(getEO48426());
	returnPlanConvexLenses.push_back(getEO45496());
	returnPlanConvexLenses.push_back(getEO45497());
	returnPlanConvexLenses.push_back(getEO45498());
	returnPlanConvexLenses.push_back(getEO45499());
	returnPlanConvexLenses.push_back(getEO49921());
	returnPlanConvexLenses.push_back(getEO45707());
	returnPlanConvexLenses.push_back(getEO49922());
	returnPlanConvexLenses.push_back(getEO45500());
	returnPlanConvexLenses.push_back(getEO45501());
	returnPlanConvexLenses.push_back(getEO45502());
	returnPlanConvexLenses.push_back(getEO45503());
	returnPlanConvexLenses.push_back(getEO47385());
	returnPlanConvexLenses.push_back(getEO45708());
	returnPlanConvexLenses.push_back(getEO47386());
	returnPlanConvexLenses.push_back(getEO45504());
	returnPlanConvexLenses.push_back(getEO45505());
	returnPlanConvexLenses.push_back(getEO45506());
	returnPlanConvexLenses.push_back(getEO45507());
	returnPlanConvexLenses.push_back(getEO45508());
	returnPlanConvexLenses.push_back(getEO45509());
	returnPlanConvexLenses.push_back(getEO45510());
	returnPlanConvexLenses.push_back(getEO45511());
	returnPlanConvexLenses.push_back(getEO45512());
	returnPlanConvexLenses.push_back(getEO45513());
	returnPlanConvexLenses.push_back(getEO45514());
	returnPlanConvexLenses.push_back(getEO45515());
	returnPlanConvexLenses.push_back(getEO33361());
	returnPlanConvexLenses.push_back(getEO67182());
	returnPlanConvexLenses.push_back(getEO67183());
	returnPlanConvexLenses.push_back(getEO33367());
	returnPlanConvexLenses.push_back(getEO47387());
	returnPlanConvexLenses.push_back(getEO47388());
	returnPlanConvexLenses.push_back(getEO62599());
	returnPlanConvexLenses.push_back(getEO62600());
	returnPlanConvexLenses.push_back(getEO62601());
	returnPlanConvexLenses.push_back(getEO62602());
	returnPlanConvexLenses.push_back(getEO62603());
	returnPlanConvexLenses.push_back(getEO62604());
	returnPlanConvexLenses.push_back(getEO62605());
	returnPlanConvexLenses.push_back(getEO48662());
	returnPlanConvexLenses.push_back(getEO67184());
	returnPlanConvexLenses.push_back(getEO45709());
	returnPlanConvexLenses.push_back(getEO47389());
	returnPlanConvexLenses.push_back(getEO45710());
	returnPlanConvexLenses.push_back(getEO45711());
	returnPlanConvexLenses.push_back(getEO47390());
	returnPlanConvexLenses.push_back(getEO48663());
	returnPlanConvexLenses.push_back(getEO45712());
	returnPlanConvexLenses.push_back(getEO33385());
	returnPlanConvexLenses.push_back(getEO33373());
	returnPlanConvexLenses.push_back(getEO33379());
	returnPlanConvexLenses.push_back(getEO47391());
	returnPlanConvexLenses.push_back(getEO47392());
	returnPlanConvexLenses.push_back(getEO45715());
	returnPlanConvexLenses.push_back(getEO45716());
	returnPlanConvexLenses.push_back(getEO45717());
	returnPlanConvexLenses.push_back(getEO47393());
	returnPlanConvexLenses.push_back(getEO45718());
	returnPlanConvexLenses.push_back(getEO47394());
	returnPlanConvexLenses.push_back(getEO47395());
	returnPlanConvexLenses.push_back(getEO47396());
	returnPlanConvexLenses.push_back(getEO47397());
	returnPlanConvexLenses.push_back(getEO86911());
	returnPlanConvexLenses.push_back(getEO86912());
	returnPlanConvexLenses.push_back(getEO86913());
	returnPlanConvexLenses.push_back(getEO86914());
	returnPlanConvexLenses.push_back(getEO86915());
	returnPlanConvexLenses.push_back(getEO38489());
	returnPlanConvexLenses.push_back(getEO38492());
	returnPlanConvexLenses.push_back(getEO38494());
	returnPlanConvexLenses.push_back(getEO38496());
	returnPlanConvexLenses.push_back(getEO38499());
	returnPlanConvexLenses.push_back(getEO38500());
	returnPlanConvexLenses.push_back(getEO38503());
	returnPlanConvexLenses.push_back(getEO38504());
	returnPlanConvexLenses.push_back(getEO38505());
	returnPlanConvexLenses.push_back(getEO38507());
	returnPlanConvexLenses.push_back(getEO38508());
	returnPlanConvexLenses.push_back(getEO38509());
	returnPlanConvexLenses.push_back(getEO38510());
	returnPlanConvexLenses.push_back(getEO38512());
	returnPlanConvexLenses.push_back(getEO38518());
	returnPlanConvexLenses.push_back(getEO38519());
	returnPlanConvexLenses.push_back(getEO38520());
	returnPlanConvexLenses.push_back(getEO38521());
	returnPlanConvexLenses.push_back(getEO38522());
	returnPlanConvexLenses.push_back(getEO38523());
	returnPlanConvexLenses.push_back(getEO38524());
	returnPlanConvexLenses.push_back(getEO38525());
	returnPlanConvexLenses.push_back(getEO38542());
	returnPlanConvexLenses.push_back(getEO38543());
	returnPlanConvexLenses.push_back(getEO38544());
	returnPlanConvexLenses.push_back(getEO38545());
	returnPlanConvexLenses.push_back(getEO38547());
	returnPlanConvexLenses.push_back(getEO38548());
	returnPlanConvexLenses.push_back(getEO38552());
	returnPlanConvexLenses.push_back(getEO38561());
	returnPlanConvexLenses.push_back(getEO38567());

	return returnPlanConvexLenses;
}

std::vector<LensesTwoSurfaces> EdmundOpticsLensCatalog::getAll_DoubleConcavLenses()
{
	std::vector<LensesTwoSurfaces> returnDoubleConcavLenses;

	//https://www.edmundoptics.de/f/vis-nir-coated-double-concave-dcv-lenses/13540/
	returnDoubleConcavLenses.push_back(getEO45927());
	returnDoubleConcavLenses.push_back(getEO48941());
	returnDoubleConcavLenses.push_back(getEO48699());
	returnDoubleConcavLenses.push_back(getEO48348());
	returnDoubleConcavLenses.push_back(getEO48942());
	returnDoubleConcavLenses.push_back(getEO48700());
	returnDoubleConcavLenses.push_back(getEO45928());
	returnDoubleConcavLenses.push_back(getEO48943());
	returnDoubleConcavLenses.push_back(getEO48701());
	returnDoubleConcavLenses.push_back(getEO45929());
	returnDoubleConcavLenses.push_back(getEO45930());
	returnDoubleConcavLenses.push_back(getEO45931());
	returnDoubleConcavLenses.push_back(getEO45932());

	return returnDoubleConcavLenses;
}

std::vector<LensesTwoSurfaces> EdmundOpticsLensCatalog::getAll_PlanConcavLenses()
{

	std::vector<LensesTwoSurfaces> returnPlanConcavLenses;

	// https://www.edmundoptics.de/f/vis-nir-coated-plano-concave-pcv-lenses/13512/
	returnPlanConcavLenses.push_back(getEO84380());
	returnPlanConcavLenses.push_back(getEO84381());
	returnPlanConcavLenses.push_back(getEO45910());
	returnPlanConcavLenses.push_back(getEO48345());
	returnPlanConcavLenses.push_back(getEO45911());
	returnPlanConcavLenses.push_back(getEO48696());
	returnPlanConcavLenses.push_back(getEO45912());
	returnPlanConcavLenses.push_back(getEO45913());
	returnPlanConcavLenses.push_back(getEO48346());
	returnPlanConcavLenses.push_back(getEO45914());
	returnPlanConcavLenses.push_back(getEO45915());
	returnPlanConcavLenses.push_back(getEO45916());
	returnPlanConcavLenses.push_back(getEO48697());
	returnPlanConcavLenses.push_back(getEO48347());
	returnPlanConcavLenses.push_back(getEO45917());
	returnPlanConcavLenses.push_back(getEO45918());
	returnPlanConcavLenses.push_back(getEO45919());
	returnPlanConcavLenses.push_back(getEO45920());
	returnPlanConcavLenses.push_back(getEO45921());
	returnPlanConcavLenses.push_back(getEO45922());
	returnPlanConcavLenses.push_back(getEO48698());
	returnPlanConcavLenses.push_back(getEO45923());
	returnPlanConcavLenses.push_back(getEO45924());
	returnPlanConcavLenses.push_back(getEO45925());
	returnPlanConcavLenses.push_back(getEO45926());

	return returnPlanConcavLenses;
}

void EdmundOpticsLensCatalog::loadLensCatalogEO_double_concav_lenses_NIR_I()
{
	//https://www.edmundoptics.de/f/nir-i-coated-double-concave-dcv-lenses/13500/

	EO49540.buildLensTwoSurfaces_DCV(/*lens catalog*/ "EO", /*catalog number*/ 49540, /*diameter*/6.0, /*max tolerance diameter*/0.0, /*min tolerance diameter*/-0.025,/*max surface quality*/40.0,
		/*back focal length*/-6.41,/*min surface quality*/20.0, /*irregularity*/4.0, /*center thickness*/  1.5, /*Centering (arc minutes)*/3.0, /*edge thickness*/2.29,
		/*design wavelength*/587.6, /*numerical Aperture*/0.5, /*min wavelength range*/600.0, /*max wavelength range*/1050, /*focal length*/-6.0,
		/*Coating*/"Ravg<_0.5;600-1050nm", /*material*/mGlasses.getSF11_S1(), /*power (P-V)*/1.5, /*free aperture CA*/5.4,/*tolerance center thickness*/0.05,
		/*tolerance focal lenght*/1.0, /*radius*/-9.74, /*price*/  35.50,/*wavelength to trace through optical system*/587.6);
}

std::vector<LensesTwoSurfaces> EdmundOpticsLensCatalog::getAll_LensCatalogEO_double_concav_lenses_NIR_I()
{
	//https://www.edmundoptics.de/f/nir-i-coated-double-concave-dcv-lenses/13500/

	std::vector<LensesTwoSurfaces> return_double_concav_lenses_NIR_I;
	return_double_concav_lenses_NIR_I.push_back(getEO49540());

	return return_double_concav_lenses_NIR_I;
}

// Achromate mit VIS-NIR-Beschichtung 
void EdmundOpticsLensCatalog::loadLensCatalogEO_achroamticLenses_VIS_NIR_Coating()
{
	//https://www.edmundoptics.de/f/vis-nir-coated-achromatic-lenses/13536/


	EO84127.buildLensThreeSurfaces(/*lens catalog*/ "EO", /*catalog number*/ 84127, /*diameter*/ 1.5, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.025,/* focallength*/ 3.0,
		/* tolerance focal length*/ 2.0, /*back focal length*/ 1.89, /*design wavelength*/ 587.6, /*free aperture CA*/ 1.6,	/*min centering*/ 30.0,
		/*max centering*/ 45,  /*first thickness*/ 1.0,	/*second thickness*/ 1.0, /*tolerance center thickness*/ 0.1, /*radius first surface*/ 1.68,
		/*radius second surface*/ -1.68, /*radisu third surface*/ -7.39, /*edge thickness*/ 1.6, /*material first*/ mGlasses.getNPSK53A_S1(),
		/*material second*/ mGlasses.getNLASF9_S1(),/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*stop*/ 1.5, /*numerical aperture*/ 0.33,
		/*coating*/ "VIS-NIR(400-1000nm)",	/*coating specification 1*/ "0.25@880nm", /*coating specification 2*/ "1.25@400-870nm", 
		/*coating specification 3*/ "1.25@890-1000nm", /*power wavelength*/ 632.8, /*power PV*/ 1.5,/*curvature wavelength*/ 632.8, 
		/*curvature PV*/ 4, /*bevel*/ "Protective bevel as needed",	/*type*/ "achromatic lens",	/*min wavelength*/ 400.0, /*max wavelength*/ 1000.0,
		/*price*/ 225.0, /*wavelength to trace*/ 550.0);
}

std::vector<LensThreeSurfaces> EdmundOpticsLensCatalog::getAll_LensCatalogEO_achroamticLenses_VIS_NIR_Coating()
{
	//https://www.edmundoptics.de/f/vis-nir-coated-achromatic-lenses/13536/

	std::vector<LensThreeSurfaces> returnAchromaticLenses;


	returnAchromaticLenses.push_back(getEO84127());

	return returnAchromaticLenses;

}

// Broadband AR Coated Negative Achromatic Lenses
void EdmundOpticsLensCatalog::loadLensCatalogEO_Broadband_AR_Coated_Negative_Achromatic_Lenses()
{
	// https://www.edmundoptics.de/f/broadband-ar-coated-negative-achromatic-lenses/13623/

	EO62478.buildLensThreeSurfaces(/*lens catalog*/ "EO", /*catalog number*/ 62478, /*diameter*/ 6.25, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.025,
		/*focallength*/ -12.0, /* tolerance focal length*/ 2.0, /*back focal length*/ 11.92, /*design wavelength*/ 587.6, /*free aperture CA*/ 5.625, /*max centering*/ 3.0,  
		/*first thickness*/ 1.0,	/*second thickness*/ 2.5, /*tolerance center thickness*/ 0.2, /*radius first surface*/ -6.545, /*radius second surface*/ 5.1, 
		/*radisu third surface*/ 89.1, /*edge thickness*/ 4.19, /*material first*/ mGlasses.getNBAF10_S1(),	/*material second*/ mGlasses.getNSF10_S1(),
		/*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*F-Number*/ 1.6, /*numerical aperture*/ 0.31, /*coating*/ "VIS 0°(425 - 675nm)",	
		/*coating specification*/ 0.4,	/*min wavelength coating*/ 425.0, /*max wavelength coating*/ 675.0, /*power PV*/ 1.5, /*curvature PV*/ 4, 
		/*bevel*/ "Protective bevel as needed",	/*type*/ "negative achromatic lens",	/*min wavelength*/ 425, /*max wavelength*/ 675.0,
		/*price*/ 62.50, /*wavelength to trace*/ 550.0);
}

std::vector<LensThreeSurfaces> EdmundOpticsLensCatalog::getAll_LensCatalogEO_Broadband_AR_Coated_Negative_Achromatic_Lenses()
{
	std::vector<LensThreeSurfaces> returnAchromaticLenses;


	returnAchromaticLenses.push_back(getEO62478());

	return returnAchromaticLenses;

}

// Broadband AR Coated Negative Achromatic Lenses
// https://www.edmundoptics.de/f/broadband-ar-coated-negative-achromatic-lenses/13623/
LensThreeSurfaces EdmundOpticsLensCatalog::getEO62478()
{
	return EO62478;
}

// Large Precision Achromatic Lenses 
void EdmundOpticsLensCatalog::loadLensCatalogEO_Large_Precision_Achromatic_Lenses_NoAirspace()
{
	// https://www.edmundoptics.de/f/large-precision-achromatic-lenses/11679/
	// *** NO AIRSPACE *** ///

	EO31402.buildLensThreeSurfaces(/*lens catalog*/ "EO", /*catalog number*/ 31402, /*diameter*/ 63.50, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.1,
		/*focallength*/ 354.87, /* tolerance focal length*/ 1.0, /*back focal length*/ 344.52, /*Focal Length Specification Wavelength*/ 587.6, /*free aperture CA*/ 62.70, 
		/*max centering*/ 5.0, /*first thickness*/ 11.94,	/*second thickness*/ 8.86, /*tolerance center thickness*/ 0.2, /*radius first surface*/ 203.94, 
		/*radius second surface*/ -156.41, /*radius third surface*/ -569.6, /*edge thickness*/ 17.43, /*material first*/ mGlasses.getNBK7_S1(),	
		/*material second*/ mGlasses.getNSF2_S1(), /*max surface quality*/ 60.0, /*min surface quality*/ 40.0, /*F-Number*/ 5.6, /*numerical aperture*/ 0.09, 
		/*coating*/ "MgF2(400 - 700nm)",/*coating specification*/ 1.75,	/*min wavelength coating*/ 400.0, /*max wavelength coating*/ 700.0,
		/*bevel*/ "Protective bevel as needed",	/*type*/ "negative achromatic lens",	/*min wavelength*/ 425, /*max wavelength*/ 675.0,
		/*price*/ 300.00, /*wavelength to trace*/ 550.0);


}
std::vector<LensThreeSurfaces> EdmundOpticsLensCatalog::getAll_LensCatalogEO_Large_Precision_Achromatic_Lenses_NoAirspace()
{
	// https://www.edmundoptics.de/f/large-precision-achromatic-lenses/11679/

	std::vector<LensThreeSurfaces> returnAchromaticLenses;

	returnAchromaticLenses.push_back(getEO31402());




	return returnAchromaticLenses;

}
// Large Precision Achromatic Lenses 
// https://www.edmundoptics.de/f/large-precision-achromatic-lenses/11679/
LensThreeSurfaces EdmundOpticsLensCatalog::getEO31402()
{
	return EO31402;
}

// Large Precision Achromatic Lenses -> Airspace 0.1mm
void EdmundOpticsLensCatalog::loadLensCatalogEO_Large_Precision_Achromatic_Lenses_Airspace01mm()
{

	// https://www.edmundoptics.de/f/large-precision-achromatic-lenses/11679/

	EO30976.buildLensFourSurfaces(/*lens catalog*/ "EO", /*catalog number*/ 30976, /*diameter*/ 76.56, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.08,
		/*focallength*/ 849.96, /* tolerance focal length*/ 1.0, /*back focal length*/ 838.69, /*Focal Length Specification Wavelength*/ 587.6, /*free aperture CA*/ 73.25,
		/*max centering*/ 5.0, /*first thickness*/ 13.08, /*second thickness*/ 0.1,	/*third thickness*/ 10.16, /*tolerance center thickness*/ 0.86, /*radius first surface*/ 497.21,
		/*radius second surface*/ -345.82, /*radius third surface*/ -344.2, /*radius fourth surface*/ -1227.86, /*edge thickness*/ 21.27, /*material first*/ mGlasses.getNBK7_S1(), 
		/*material second*/ mGlasses.getAir(), /*material third*/ mGlasses.getNSF2_S1(), /*max surface quality*/ 60.0, /*min surface quality*/ 40.0, /*F-Number*/ 11.1, 
		/*numerical aperture*/ 0.05, /*coating*/ "MgF2(400 - 700nm)",/*coating specification*/ 1.75,	/*min wavelength coating*/ 400.0, /*max wavelength coating*/ 700.0,
		/*bevel*/ "Protective bevel as needed",	/*type*/ "achromatic lens",	/*min wavelength*/ 400, /*max wavelength*/ 700.0, /*price*/ 300.00);

}
std::vector<LensFourSurfaces> EdmundOpticsLensCatalog::getAll_LensCatalogEO_Large_Precision_Achromatic_Lenses_Airspace01mm()
{
	// https://www.edmundoptics.de/f/large-precision-achromatic-lenses/11679/

	std::vector<LensFourSurfaces> returnAchromaticLenses;

	returnAchromaticLenses.push_back(getEO30976());




	return returnAchromaticLenses;
}


// Hastings Triplet Achromatic Lenses 
void EdmundOpticsLensCatalog::loadLensCatalogEO_Hastings_Triplet_Achromatic_Lenses()
{
	// https://www.edmundoptics.de/f/hastings-triplet-achromatic-lenses/11968/


	EO13521.buildLensFourSurfaces(/*lens catalog*/ "EO", /*catalog number*/ 13521, /*diameter*/ 8.0, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.025,
		/*focallength*/ 12.5, /* tolerance focal length*/ 2.0, /*back focal length*/ 9.82, /*Focal Length Specification Wavelength*/ 587.6, 
		/*max centering*/ 3.0, /*first thickness*/ 1.0, /*second thickness*/ 5.23,	/*third thickness*/ 1.0, /*tolerance center thickness*/ 0.3, /*radius first surface*/ 9.395,
		/*radius second surface*/ 4.805, /*radius third surface*/ -4.805, /*radius fourth surface*/ -9.395, /*edge thickness*/ 5.44, /*material first*/ mGlasses.getNF2_S1(),
		/*material second*/ mGlasses.getNBK7_S1(), /*material third*/ mGlasses.getNF2_S1(), /*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*F-Number*/ 1.56,
		/*numerical aperture*/ 0.32, /*coating*/ "MgF2(400-700nm)",/*coating specification*/ 1.75,	/*min wavelength coating*/ 400.0, /*max wavelength coating*/ 700.0,
		/*Power(P-V)@632.8nm:*/ 1.5, /*Irregularity(P-V)@632.8nm*/ 4.0, /*bevel*/ "Protective bevel as needed",	/*type*/ "achromatic Triplet Lens ",	/*min wavelength*/ 400, /*max wavelength*/ 700.0, /*price*/ 101.0);

}

std::vector<LensFourSurfaces> EdmundOpticsLensCatalog::getAll_LensCatalogEO_Hastings_Triplet_Achromatic_Lenses()
{
	// https://www.edmundoptics.de/f/hastings-triplet-achromatic-lenses/11968/

	std::vector<LensFourSurfaces> returnAchromaticLenses;

	returnAchromaticLenses.push_back(getEO13521());




	return returnAchromaticLenses;
}

// Hastings Triplet Achromatic Lenses 
// https://www.edmundoptics.de/f/hastings-triplet-achromatic-lenses/11968/
LensFourSurfaces EdmundOpticsLensCatalog::getEO13521()
{
	return EO13521;
}

// Large Precision Achromatic Lenses -> Airspace 0.1mm
// https://www.edmundoptics.de/f/large-precision-achromatic-lenses/11679/
LensFourSurfaces EdmundOpticsLensCatalog::getEO30976()
{
	return EO30976;
}

// Steinheil Triplet Achromatic Lenses 
void EdmundOpticsLensCatalog::loadLensCatalogEO_Steinheil_Triplet_Achromatic_Lenses()
{
	// https://www.edmundoptics.de/f/steinheil-triplet-achromatic-lenses/12275/

	EO47673.buildLensFourSurfaces(/*lens catalog*/ "EO", /*catalog number*/ 47673, /*diameter*/ 6.25, /*max diameter tolerance*/ 0.0, /*min diameter tolerance*/ -0.025,
		/*focallength*/ 12.5, /* tolerance focal length*/ 1.0, /*back focal length*/ 8.94, /*Focal Length Specification Wavelength*/ 587.6,
		/*max centering*/ 3.0, /*first thickness*/ 2.0, /*second thickness*/ 5.0,	/*third thickness*/ 2.0, /*tolerance center thickness*/ 0.3, /*radius first surface*/ 7.81,
		/*radius second surface*/ 4.09, /*radius third surface*/ -4.09, /*radius fourth surface*/ -7.81, /*edge thickness*/ 7.70, /*material first*/ mGlasses.getNBASF64_S1(),
		/*material second*/ mGlasses.getNBK7_S1(), /*material third*/ mGlasses.getNBASF64_S1(), /*max surface quality*/ 40.0, /*min surface quality*/ 20.0, /*F-Number*/ 2.0,
		/*numerical aperture*/ 0.25, /*coating*/ "MgF2(400-700nm)",/*coating specification*/ 1.75,	/*min wavelength coating*/ 400.0, /*max wavelength coating*/ 700.0,
		/*Power(P-V)@632.8nm:*/ 1.5, /*Irregularity(P-V)@632.8nm*/ 4.0, /*bevel*/ "Protective bevel as needed",	/*type*/ "achromatic Triplet Lens ",	/*min wavelength*/ 400, 
		/*max wavelength*/ 700.0, /*price*/ 101.50);


}
std::vector<LensFourSurfaces> EdmundOpticsLensCatalog::getAll_LensCatalogEO_Steinheil_Triplet_Achromatic_Lenses()
{
	// https://www.edmundoptics.de/f/steinheil-triplet-achromatic-lenses/12275/

	std::vector<LensFourSurfaces> returnAchromaticLenses;

	returnAchromaticLenses.push_back(getEO47673());




	return returnAchromaticLenses;
}



// Steinheil Triplet Achromatic Lenses 
// https://www.edmundoptics.de/f/steinheil-triplet-achromatic-lenses/12275/
LensFourSurfaces EdmundOpticsLensCatalog::getEO47673()
{
	return EO47673;
}

// Micro Plano-Convex (PCX) Lenses 
void EdmundOpticsLensCatalog::loadLensCatalogEO_Micro_Plano_Convex_PCX_Lenses()
{
	// https://www.edmundoptics.de/f/micro-plano-convex-pcx-lenses/39529/

	EO45951.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 45951, /*diameter*/ 1.0, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/  -0.025,
		/*Effective Focal Length EFL(mm)*/ 0.60, /*back focal length*/ 0.17, /*Coating*/ "NIR I (600-1050nm)", /*Coating Specification*/ "Ravg<=0.5% @600-1050nm ", 
		/*min coating wavelength*/ 600.0, /*max coating wavelength*/ 1050.0, /*material*/ mGlasses.getNLASF9_S1(), /*max surface quality*/  40.0, 
		/*min surface quality*/  20.0, /*Power(P-V)@632.8nm:*/  1.5, /*Irregularity(P-V)@632.8nm*/ 4.0, /*tolerance focal lenght*/  1.0, /*min centering*/  30.0, 
		/*max centering*/  45.0, /*center thickness*/  0.80, /*tolerance center thickness*/  0.05,/*edge thickness*/  0.39, /*radius first surface*/  0.51,
		/*free aperture CA*/  0.5, /*F-Number*/ 0.6,  /*numerical Aperture*/  0.83, /*type*/ "Plano-Convex Lens", /*Bevel*/ "Protective bevel as needed",
		/*Typical Energy Density Limit*/ "7J/cm2 @ 1064nm, 10ns", /*min wavelength range*/ 600.0,	/*max wavelength range*/  1050.0, 	/*price*/  87.0);

}

std::vector<LensesTwoSurfaces> EdmundOpticsLensCatalog::getAll_Micro_Plano_Convex_PCX_Lenses()
{
	std::vector<LensesTwoSurfaces> returnMicroPlanoConvecLenses;

	returnMicroPlanoConvecLenses.push_back(getEO45951());




	return returnMicroPlanoConvecLenses;
}

// Large PCX Condenser Lenses
void EdmundOpticsLensCatalog::loadLensCatalogEO_Large_PCX_Condenser_Lenses()
{
	// https://www.edmundoptics.de/f/large-pcx-condenser-lenses/13572/

	EO67187.buildLensTwoSurfaces_PCX(/*lens catalog*/ "EO", /*catalog number*/ 67187, /*diameter*/ 100.0, /*max tolerance diameter*/  0.0,	/*min tolerance diameter*/-0.5,
		/*Effective Focal Length EFL(mm)*/ 150.0, /*back focal length*/ 136.16, /*Coating*/ "Uncoated ", /*material*/ mGlasses.getNBK7_S1(), /*max surface quality*/  120.0,
		/*min surface quality*/  80.0, /*center thickness*/  21.0, /*edge thickness*/  2.72, /*radius first surface*/  77.57075215478673,
		/*free aperture CA*/  95.0, /*F-Number*/ 1.5,  /*numerical Aperture*/  0.33, /*type*/ "Condenser Lens", /*Bevel*/ "Protective bevel as needed",
		/*min wavelength range*/ 350.0,	/*max wavelength range*/  2200.0, /*price*/ 90.0);

}
std::vector<LensesTwoSurfaces> EdmundOpticsLensCatalog::getAll_Large_PCX_Condenser_Lenses()
{
	std::vector<LensesTwoSurfaces> returnLargePCX_CondenserLenses;

	returnLargePCX_CondenserLenses.push_back(getEO67187());




	return returnLargePCX_CondenserLenses;
}


// Large PCX Condenser Lenses
// https://www.edmundoptics.de/f/large-pcx-condenser-lenses/13572/
LensesTwoSurfaces EdmundOpticsLensCatalog::getEO67187()
{
	return EO67187;
}


// Micro Plano-Convex (PCX) Lenses 
// https://www.edmundoptics.de/f/micro-plano-convex-pcx-lenses/39529/
LensesTwoSurfaces EdmundOpticsLensCatalog::getEO45951()
{
	return EO45951;
}