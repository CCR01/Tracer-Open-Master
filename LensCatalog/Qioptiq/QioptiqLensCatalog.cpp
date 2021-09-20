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

	mQ_G312003000.buildLensTwoSurfaces_Qioptiq_oneSurfacePlan(/*lens catalog*/ "Qioptiq", /*catalog number*/ "G312003000", /*diameter*/ 3.0,
		/*focallength*/ 2.5, /*tolerance focal length*/ 2.0,	/*material*/ glasses.getNLASF9_S1(), /*optical centering accurancy*/6.0,
		/*surface quality*/ "3x0.063", /*thickness*/ 1.0, /*tolerance center thickness*/ 0.02, /*edge thickness*/ 0.38, /*min diameter tolerance*/ -0.02,
		/*back focal length*/ 1.96, /*radius*/ 2.126, /*price*/ 43.0, /*coating*/ "ARB2-VIS", /*min wavelength*/ 450.0, /*max wavelength*/ 700.0);

	mQ_G312004000.buildLensTwoSurfaces_Qioptiq_oneSurfacePlan(/*lens catalog*/ "Qioptiq", /*catalog number*/ "G312004000", /*diameter*/ 3.0,
		/*focallength*/ 3.0, /*tolerance focal length*/ 2.0,	/*material*/ glasses.getNBK7_S1(), /*optical centering accurancy*/6.0,
		/*surface quality*/ "3x0.063", /*thickness*/ 1.5, /*tolerance center thickness*/ 0.02, /*edge thickness*/ 0.34, /*min diameter tolerance*/ -0.02,
		/*back focal length*/ 2.01, /*radius*/ 1.55, /*price*/ 52.0, /*coating*/ "ARB2-VIS", /*min wavelength*/ 450.0, /*max wavelength*/ 700.0);

	mQ_G312006000.buildLensTwoSurfaces_Qioptiq_oneSurfacePlan(/*lens catalog*/ "Qioptiq", /*catalog number*/ "G312006000", /*diameter*/ 4.0,
		/*focallength*/ 4.0, /*tolerance focal length*/ 2.0,	/*material*/ glasses.getNBK7_S1(), /*optical centering accurancy*/ 6.0,
		/*surface quality*/ "3x0.063", /*thickness*/ 2.0, /*tolerance center thickness*/ 0.02, /*edge thickness*/ 0.45, /*min diameter tolerance*/ -0.03,
		/*back focal length*/ 2.68, /*radius*/ 2.067, /*price*/ 44.00, /*coating*/ "ARB2-VIS", /*min wavelength*/ 450.0, /*max wavelength*/ 700.0);

	mQ_G312007000.buildLensTwoSurfaces_Qioptiq_oneSurfacePlan(/*lens catalog*/ "Qioptiq", /*catalog number*/ "G312007000", /*diameter*/ 5.0,
		/*focallength*/ 5.0, /*tolerance focal length*/ 2.0,	/*material*/ glasses.getNBK7_S1(), /*optical centering accurancy*/ 6.0,
		/*surface quality*/ "3x0.1", /*thickness*/ 2.5, /*tolerance center thickness*/ 0.02, /*edge thickness*/0.57, /*min diameter tolerance*/ -0.03,
		/*back focal length*/ 3.35, /*radius*/ 2.584, /*price*/ 56.00, /*coating*/ "ARB2-VIS", /*min wavelength*/ 450.0, /*max wavelength*/ 700.0);

	mQ_G312008000.buildLensTwoSurfaces_Qioptiq_oneSurfacePlan(/*lens catalog*/ "Qioptiq", /*catalog number*/ "G312008000", /*diameter*/ 6.0,
		/*focallength*/ 6.0, /*tolerance focal length*/ 2.0,	/*material*/ glasses.getNBK7_S1(), /*optical centering accurancy*/ 6.0,
		/*surface quality*/ "3x0.1", /*thickness*/ 3.0, /*tolerance center thickness*/ 0.02, /*edge thickness*/0.68, /*min diameter tolerance*/ -0.03,
		/*back focal length*/ 4.02, /*radius*/ 3.101, /*price*/ 46.00, /*coating*/ "ARB2-VIS", /*min wavelength*/ 450.0, /*max wavelength*/ 700.0);

	mQ_G312201000.buildLensTwoSurfaces_Qioptiq_oneSurfacePlan(/*lens catalog*/ "Qioptiq", /*catalog number*/ "G312201000", /*diameter*/ 6.0,
		/*focallength*/ 10.0, /*tolerance focal length*/ 2.0,	/*material*/ glasses.getNBAK2_S1(), /*optical centering accurancy*/ 6.0,
		/*surface quality*/ "3x0.1", /*thickness*/ 2.0, /*tolerance center thickness*/ 0.1, /*edge thickness*/1.1, /*min diameter tolerance*/ -0.03,
		/*back focal length*/ 8.82, /*radius*/ 5.464, /*price*/ 43.00, /*coating*/ "ARB2-VIS", /*min wavelength*/ 450.0, /*max wavelength*/ 700.0);

	mQ_G312009000.buildLensTwoSurfaces_Qioptiq_oneSurfacePlan(/*lens catalog*/ "Qioptiq", /*catalog number*/ "G312009000", /*diameter*/ 7.0,
		/*focallength*/ 7.0, /*tolerance focal length*/ 2.0,	/*material*/ glasses.getNBK7_S1(), /*optical centering accurancy*/ 6.0,
		/*surface quality*/ "3x0.1", /*thickness*/ 3.5, /*tolerance center thickness*/ 0.02, /*edge thickness*/0.8, /*min diameter tolerance*/ -0.04,
		/*back focal length*/ 4.69, /*radius*/ 3.618, /*price*/ 41.00, /*coating*/ "ARB2-VIS", /*min wavelength*/ 450.0, /*max wavelength*/ 700.0);

	mQ_G312010000.buildLensTwoSurfaces_Qioptiq_oneSurfacePlan(/*lens catalog*/ "Qioptiq", /*catalog number*/ "G312010000", /*diameter*/ 8.0,
		/*focallength*/ 8.0, /*tolerance focal length*/ 2.0,	/*material*/ glasses.getNBK7_S1(), /*optical centering accurancy*/ 6.0,
		/*surface quality*/ "3x0.1", /*thickness*/ 4.0, /*tolerance center thickness*/ 0.02, /*edge thickness*/0.91, /*min diameter tolerance*/ -0.04,
		/*back focal length*/ 5.36, /*radius*/ 4.134, /*price*/ 50.00, /*coating*/ "ARB2-VIS", /*min wavelength*/ 450.0, /*max wavelength*/ 700.0);

	mQ_G312011000.buildLensTwoSurfaces_Qioptiq_oneSurfacePlan(/*lens catalog*/ "Qioptiq", /*catalog number*/ "G312011000", /*diameter*/ 10.0,
		/*focallength*/ 10.0, /*tolerance focal length*/ 2.0,	/*material*/ glasses.getNBK7_S1(), /*optical centering accurancy*/ 6.0,
		/*surface quality*/ "3x0.1", /*thickness*/ 5.0, /*tolerance center thickness*/ 0.02, /*edge thickness*/1.14, /*min diameter tolerance*/ -0.04,
		/*back focal length*/ 6.7, /*radius*/ 5.168, /*price*/ 46.00, /*coating*/ "ARB2-VIS", /*min wavelength*/ 450.0, /*max wavelength*/ 700.0);

	mQ_G312236000.buildLensTwoSurfaces_Qioptiq_oneSurfacePlan(/*lens catalog*/ "Qioptiq", /*catalog number*/ "G312236000", /*diameter*/ 10.0,
		/*focallength*/ 15.0, /*tolerance focal length*/ 2.0,	/*material*/ glasses.getNBAK4_S1(), /*optical centering accurancy*/ 6.0,
		/*surface quality*/ "3x0.16", /*thickness*/ 3.0, /*tolerance center thickness*/ 0.1, /*edge thickness*/1.4, /*min diameter tolerance*/ -0.04,
		/*back focal length*/ 12.99, /*radius*/ 8.475, /*price*/ 43.00, /*coating*/ "ARB2-VIS", /*min wavelength*/ 450.0, /*max wavelength*/ 700.0);

	mQ_G312329000.buildLensTwoSurfaces_Qioptiq_oneSurfacePlan(/*lens catalog*/ "Qioptiq", /*catalog number*/ "G312329000", /*diameter*/ 12.5,
		/*focallength*/ 20.0, /*tolerance focal length*/ 2.0,	/*material*/ glasses.getNBK7_S1(), /*optical centering accurancy*/ 3.0,
		/*surface quality*/ "3x0.16", /*thickness*/ 3.5, /*tolerance center thickness*/ 0.1, /*edge thickness*/1.4, /*min diameter tolerance*/ -0.05,
		/*back focal length*/ 17.9, /*radius*/ 10.441, /*price*/ 38.00, /*coating*/ "ARB2-VIS", /*min wavelength*/ 450.0, /*max wavelength*/ 700.0);

	mQ_G312330000.buildLensTwoSurfaces_Qioptiq_oneSurfacePlan(/*lens catalog*/ "Qioptiq", /*catalog number*/ "G312330000", /*diameter*/ 12.5,
		/*focallength*/ 25.0, /*tolerance focal length*/ 2.0,	/*material*/ glasses.getNBK7_S1(), /*optical centering accurancy*/ 10.0,
		/*surface quality*/ "3x0.16", /*thickness*/ 3.0, /*tolerance center thickness*/ 0.1, /*edge thickness*/1.4, /*min diameter tolerance*/ -0.11,
		/*back focal length*/ 23.27, /*radius*/ 13.05, /*price*/ 38.00, /*coating*/ "ARB2-VIS", /*min wavelength*/ 450.0, /*max wavelength*/ 700.0);

	mQ_G312351000.buildLensTwoSurfaces_Qioptiq_oneSurfacePlan(/*lens catalog*/ "Qioptiq", /*catalog number*/ "G312351000", /*diameter*/ 12.7,
		/*focallength*/ 30.0, /*tolerance focal length*/ 2.0,	/*material*/ glasses.getNBK7_S1(), /*optical centering accurancy*/ 10.0,
		/*surface quality*/ "3x0.16", /*thickness*/ 0.0, /*tolerance center thickness*/ 0.1, /*edge thickness*/1.6, /*min diameter tolerance*/ -0.12,
		/*back focal length*/ 28.03, /*radius*/ 15.51, /*price*/ 38.00, /*coating*/ "ARB2-VIS", /*min wavelength*/ 450.0, /*max wavelength*/ 700.0);

	mQ_G312352000.buildLensTwoSurfaces_Qioptiq_oneSurfacePlan(/*lens catalog*/ "Qioptiq", /*catalog number*/ "G312352000", /*diameter*/ 12.7,
		/*focallength*/ 50.0, /*tolerance focal length*/ 2.0,	/*material*/ glasses.getNBK7_S1(), /*optical centering accurancy*/ 10.0,
		/*surface quality*/ "3x0.16", /*thickness*/ 3.0, /*tolerance center thickness*/ 0.1, /*edge thickness*/2.2, /*min diameter tolerance*/ -0.12,
		/*back focal length*/ 48.41, /*radius*/ 26.039, /*price*/ 38.00, /*coating*/ "ARB2-VIS", /*min wavelength*/ 450.0, /*max wavelength*/ 700.0);

	mQ_G312353000.buildLensTwoSurfaces_Qioptiq_oneSurfacePlan(/*lens catalog*/ "Qioptiq", /*catalog number*/ "G312353000", /*diameter*/ 12.7,
		/*focallength*/ 80.0, /*tolerance focal length*/ 2.0,	/*material*/ glasses.getNBK7_S1(), /*optical centering accurancy*/ 10.0,
		/*surface quality*/ "3x0.16", /*thickness*/ 3.0, /*tolerance center thickness*/ 0.1, /*edge thickness*/2.5, /*min diameter tolerance*/ -0.12,
		/*back focal length*/ 77.88, /*radius*/ 41.269, /*price*/ 38.00, /*coating*/ "ARB2-VIS", /*min wavelength*/ 450.0, /*max wavelength*/ 700.0);

	mQ_G312354000.buildLensTwoSurfaces_Qioptiq_oneSurfacePlan(/*lens catalog*/ "Qioptiq", /*catalog number*/ "G312354000", /*diameter*/ 12.7,
		/*focallength*/ 100.0, /*tolerance focal length*/ 2.0,	/*material*/ glasses.getNBK7_S1(), /*optical centering accurancy*/ 10.0,
		/*surface quality*/ "3x0.16", /*thickness*/ 3.0, /*tolerance center thickness*/ 0.1, /*edge thickness*/2.6, /*min diameter tolerance*/ -0.12,
		/*back focal length*/ 97.12, /*radius*/ 51.212, /*price*/ 38.00, /*coating*/ "ARB2-VIS", /*min wavelength*/ 450.0, /*max wavelength*/ 700.0);

	mQ_G312355000.buildLensTwoSurfaces_Qioptiq_oneSurfacePlan(/*lens catalog*/ "Qioptiq", /*catalog number*/ "G312355000", /*diameter*/ 12.7,
		/*focallength*/ 150.0, /*tolerance focal length*/ 2.0,	/*material*/ glasses.getNBK7_S1(), /*optical centering accurancy*/ 10.0,
		/*surface quality*/ "3x0.16", /*thickness*/ 3.0, /*tolerance center thickness*/ 0.1, /*edge thickness*/2.7, /*min diameter tolerance*/ -0.12,
		/*back focal length*/ 147.36, /*radius*/ 77.179, /*price*/ 38.00, /*coating*/ "ARB2-VIS", /*min wavelength*/ 450.0, /*max wavelength*/ 700.0);

	mQ_G312356000.buildLensTwoSurfaces_Qioptiq_oneSurfacePlan(/*lens catalog*/ "Qioptiq", /*catalog number*/ "G312356000", /*diameter*/ 12.7,
		/*focallength*/ 200.0, /*tolerance focal length*/ 2.0,	/*material*/ glasses.getNBK7_S1(), /*optical centering accurancy*/ 10.0,
		/*surface quality*/ "3x0.16", /*thickness*/ 3.0, /*tolerance center thickness*/ 0.1, /*edge thickness*/2.8, /*min diameter tolerance*/ -0.12,
		/*back focal length*/ 197.17, /*radius*/ 102.92, /*price*/ 38.00, /*coating*/ "ARB2-VIS", /*min wavelength*/ 450.0, /*max wavelength*/ 700.0);

	mQ_G312357000.buildLensTwoSurfaces_Qioptiq_oneSurfacePlan(/*lens catalog*/ "Qioptiq", /*catalog number*/ "G312357000", /*diameter*/ 12.7,
		/*focallength*/ 300.0, /*tolerance focal length*/ 2.0,	/*material*/ glasses.getNBK7_S1(), /*optical centering accurancy*/ 10.0,
		/*surface quality*/ "3x0.016", /*thickness*/ 3.0, /*tolerance center thickness*/ 0.1, /*edge thickness*/2.9, /*min diameter tolerance*/ -0.12,
		/*back focal length*/ 295.99, /*radius*/ 153.99, /*price*/ 38.00, /*coating*/ "ARB2-VIS", /*min wavelength*/ 450.0, /*max wavelength*/ 700.0);

	mQ_G312358000.buildLensTwoSurfaces_Qioptiq_oneSurfacePlan(/*lens catalog*/ "Qioptiq", /*catalog number*/ "G312358000", /*diameter*/ 12.7,
		/*focallength*/ 500.0, /*tolerance focal length*/ 2.0,	/*material*/ glasses.getNBK7_S1(), /*optical centering accurancy*/ 10.0,
		/*surface quality*/ "3x0.16", /*thickness*/ 3.0, /*tolerance center thickness*/ 0.1, /*edge thickness*/2.9, /*min diameter tolerance*/ -0.12,
		/*back focal length*/ 501.87, /*radius*/ 260.39, /*price*/ 38.00, /*coating*/ "ARB2-VIS", /*min wavelength*/ 450.0, /*max wavelength*/ 700.0);

	mQ_G312331000.buildLensTwoSurfaces_Qioptiq_oneSurfacePlan(/*lens catalog*/ "Qioptiq", /*catalog number*/ "G312331000", /*diameter*/ 18.0,
		/*focallength*/ 30.0, /*tolerance focal length*/ 2.0,	/*material*/ glasses.getNBK7_S1(), /*optical centering accurancy*/ 10.0,
		/*surface quality*/ "3x0.16", /*thickness*/ 4.5, /*tolerance center thickness*/ 0.1, /*edge thickness*/1.7, /*min diameter tolerance*/ -0.11,
		/*back focal length*/ 27.48, /*radius*/ 15.735, /*price*/ 43.00, /*coating*/ "ARB2-VIS", /*min wavelength*/ 450.0, /*max wavelength*/ 700.0);

	mQ_G312314000.buildLensTwoSurfaces_Qioptiq_oneSurfacePlan(/*lens catalog*/ "Qioptiq", /*catalog number*/ "G312314000", /*diameter*/ 22.4,
		/*focallength*/ 40.0, /*tolerance focal length*/ 2.0,	/*material*/ glasses.getNBK7_S1(), /*optical centering accurancy*/ 10.0,
		/*surface quality*/ "3x0.25", /*thickness*/ 5.0, /*tolerance center thickness*/ 0.2, /*edge thickness*/1.7, /*min diameter tolerance*/ -0.13,
		/*back focal length*/ 37.02, /*radius*/ 20.833, /*price*/ 0.0, /*coating*/ "ARB2-VIS", /*min wavelength*/ 450.0, /*max wavelength*/ 700.0);

	mQ_G312315000.buildLensTwoSurfaces_Qioptiq_oneSurfacePlan(/*lens catalog*/ "Qioptiq", /*catalog number*/ "G312315000", /*diameter*/ 22.4,
		/*focallength*/ 50.0, /*tolerance focal length*/ 2.0,	/*material*/ glasses.getNBK7_S1(), /*optical centering accurancy*/ 10.0,
		/*surface quality*/ "3x0.25", /*thickness*/ 4.5, /*tolerance center thickness*/ 0.2, /*edge thickness*/2.0, /*min diameter tolerance*/ -0.13,
		/*back focal length*/ 48.15, /*radius*/ 26.416, /*price*/ 43.00, /*coating*/ "ARB2-VIS", /*min wavelength*/ 450.0, /*max wavelength*/ 700.0);

	mQ_G312316000.buildLensTwoSurfaces_Qioptiq_oneSurfacePlan(/*lens catalog*/ "Qioptiq", /*catalog number*/ "G312316000", /*diameter*/ 22.4,
		/*focallength*/ 60.0, /*tolerance focal length*/ 2.0,	/*material*/ glasses.getNBK7_S1(), /*optical centering accurancy*/ 10.0,
		/*surface quality*/ "3x0.25", /*thickness*/ 4.0, /*tolerance center thickness*/ 0.2, /*edge thickness*/2.0, /*min diameter tolerance*/ -0.13,
		/*back focal length*/ 59.0, /*radius*/ 31.851, /*price*/ 43.00, /*coating*/ "ARB2-VIS", /*min wavelength*/ 450.0, /*max wavelength*/ 700.0);

	mQ_G312317000.buildLensTwoSurfaces_Qioptiq_oneSurfacePlan(/*lens catalog*/ "Qioptiq", /*catalog number*/ "G312317000", /*diameter*/ 22.4,
		/*focallength*/ 80.0, /*tolerance focal length*/ 2.0,	/*material*/ glasses.getNBK7_S1(), /*optical centering accurancy*/ 10.0,
		/*surface quality*/ "3x0.25", /*thickness*/ 3.5, /*tolerance center thickness*/ 0.2, /*edge thickness*/1.9, /*min diameter tolerance*/ -0.13,
		/*back focal length*/ 78.71, /*radius*/ 41.867, /*price*/ 43.00, /*coating*/ "ARB2-VIS", /*min wavelength*/ 450.0, /*max wavelength*/ 700.0);

	mQ_G312318000.buildLensTwoSurfaces_Qioptiq_oneSurfacePlan(/*lens catalog*/ "Qioptiq", /*catalog number*/ "G312318000", /*diameter*/ 22.4,
		/*focallength*/ 100.0, /*tolerance focal length*/ 2.0,	/*material*/ glasses.getNBK7_S1(), /*optical centering accurancy*/ 10.0,
		/*surface quality*/ "3x0.25", /*thickness*/ 3.2, /*tolerance center thickness*/ 0.2, /*edge thickness*/2.0, /*min diameter tolerance*/ -0.13,
		/*back focal length*/ 99.15, /*radius*/ 52.33, /*price*/ 43.00, /*coating*/ "ARB2-VIS", /*min wavelength*/ 450.0, /*max wavelength*/ 700.0);

	mQ_G312319000.buildLensTwoSurfaces_Qioptiq_oneSurfacePlan(/*lens catalog*/ "Qioptiq", /*catalog number*/ "G312319000", /*diameter*/ 22.4,
		/*focallength*/ 150.0, /*tolerance focal length*/ 2.0,	/*material*/ glasses.getNBK7_S1(), /*optical centering accurancy*/ 10.0,
		/*surface quality*/ "3x0.25", /*thickness*/ 3.0, /*tolerance center thickness*/ 0.2, /*edge thickness*/2.2, /*min diameter tolerance*/ -0.13,
		/*back focal length*/ 149.54, /*radius*/ 78.298, /*price*/ 0.0, /*coating*/ "ARB2-VIS", /*min wavelength*/ 450.0, /*max wavelength*/ 700.0);

	mQ_G312320000.buildLensTwoSurfaces_Qioptiq_oneSurfacePlan(/*lens catalog*/ "Qioptiq", /*catalog number*/ "G312320000", /*diameter*/ 22.4,
		/*focallength*/ 200.0, /*tolerance focal length*/ 2.0,	/*material*/ glasses.getNBK7_S1(), /*optical centering accurancy*/ 10.0,
		/*surface quality*/ "3x0.25", /*thickness*/ 2.7, /*tolerance center thickness*/ 0.2, /*edge thickness*/2.1, /*min diameter tolerance*/ -0.13,
		/*back focal length*/ 200.27, /*radius*/ 104.41, /*price*/ 43.00, /*coating*/ "ARB2-VIS", /*min wavelength*/ 450.0, /*max wavelength*/ 700.0);

	mQ_G312321000.buildLensTwoSurfaces_Qioptiq_oneSurfacePlan(/*lens catalog*/ "Qioptiq", /*catalog number*/ "G312321000", /*diameter*/ 25.4,
		/*focallength*/ 50.0, /*tolerance focal length*/ 2.0,	/*material*/ glasses.getNBK7_S1(), /*optical centering accurancy*/ 10.0,
		/*surface quality*/ "3x0.25", /*thickness*/ 5.0, /*tolerance center thickness*/ 0.2, /*edge thickness*/1.8, /*min diameter tolerance*/ -0.15,
		/*back focal length*/ 47.09, /*radius*/ 26.039, /*price*/ 43.00, /*coating*/ "ARB2-VIS", /*min wavelength*/ 450.0, /*max wavelength*/ 700.0);

	mQ_G312322000.buildLensTwoSurfaces_Qioptiq_oneSurfacePlan(/*lens catalog*/ "Qioptiq", /*catalog number*/ "G312322000", /*diameter*/ 25.4,
		/*focallength*/ 80.0, /*tolerance focal length*/ 2.0,	/*material*/ glasses.getNBK7_S1(), /*optical centering accurancy*/ 10.0,
		/*surface quality*/ "3x0.25", /*thickness*/ 4.0, /*tolerance center thickness*/ 0.2, /*edge thickness*/2.0, /*min diameter tolerance*/ -0.15,
		/*back focal length*/ 77.88, /*radius*/ 41.269, /*price*/ 43.00, /*coating*/ "ARB2-VIS", /*min wavelength*/ 450.0, /*max wavelength*/ 700.0);

	mQ_G312323000.buildLensTwoSurfaces_Qioptiq_oneSurfacePlan(/*lens catalog*/ "Qioptiq", /*catalog number*/ "G312323000", /*diameter*/ 25.4,
		/*focallength*/ 100.0, /*tolerance focal length*/ 2.0,	/*material*/ glasses.getNBK7_S1(), /*optical centering accurancy*/ 10.0,
		/*surface quality*/ "3x0.25", /*thickness*/ 4.0, /*tolerance center thickness*/ 0.2, /*edge thickness*/2.4, /*min diameter tolerance*/ -0.15,
		/*back focal length*/ 96.46, /*radius*/ 51.212, /*price*/ 43.00, /*coating*/ "ARB2-VIS", /*min wavelength*/ 450.0, /*max wavelength*/ 700.0);

	mQ_G312324000.buildLensTwoSurfaces_Qioptiq_oneSurfacePlan(/*lens catalog*/ "Qioptiq", /*catalog number*/ "G312324000", /*diameter*/ 25.4,
		/*focallength*/ 150.0, /*tolerance focal length*/ 2.0,	/*material*/ glasses.getNBK7_S1(), /*optical centering accurancy*/ 10.0,
		/*surface quality*/ "3x0.25", /*thickness*/ 4.0, /*tolerance center thickness*/ 0.2, /*edge thickness*/3.0, /*min diameter tolerance*/ -0.15,
		/*back focal length*/ 148.87, /*radius*/ 78.298, /*price*/ 43.00, /*coating*/ "ARB2-VIS", /*min wavelength*/ 450.0, /*max wavelength*/ 700.0);

	mQ_G312325000.buildLensTwoSurfaces_Qioptiq_oneSurfacePlan(/*lens catalog*/ "Qioptiq", /*catalog number*/ "G312325000", /*diameter*/ 25.4,
		/*focallength*/ 200.0, /*tolerance focal length*/ 2.0,	/*material*/ glasses.getNBK7_S1(), /*optical centering accurancy*/ 10.0,
		/*surface quality*/ "3x0.25", /*thickness*/ 4.0, /*tolerance center thickness*/ 0.2, /*edge thickness*/3.2, /*min diameter tolerance*/ -0.15,
		/*back focal length*/ 196.51, /*radius*/ 102.92, /*price*/ 43.00, /*coating*/ "ARB2-VIS", /*min wavelength*/ 450.0, /*max wavelength*/ 700.0);

	mQ_G312326000.buildLensTwoSurfaces_Qioptiq_oneSurfacePlan(/*lens catalog*/ "Qioptiq", /*catalog number*/ "G312326000", /*diameter*/ 25.4,
		/*focallength*/ 300.0, /*tolerance focal length*/ 2.0,	/*material*/ glasses.getNBK7_S1(), /*optical centering accurancy*/ 10.0,
		/*surface quality*/ "3x0.25", /*thickness*/ 4.0, /*tolerance center thickness*/ 0.2, /*edge thickness*/3.5, /*min diameter tolerance*/ -0.15,
		/*back focal length*/ 295.33, /*radius*/ 153.99, /*price*/ 43.00, /*coating*/ "ARB2-VIS", /*min wavelength*/ 450.0, /*max wavelength*/ 700.0);

	mQ_G312327000.buildLensTwoSurfaces_Qioptiq_oneSurfacePlan(/*lens catalog*/ "Qioptiq", /*catalog number*/ "G312327000", /*diameter*/ 25.4,
		/*focallength*/ 500.0, /*tolerance focal length*/ 2.0,	/*material*/ glasses.getNBK7_S1(), /*optical centering accurancy*/ 10.0,
		/*surface quality*/ "3x0.25", /*thickness*/ 4.0, /*tolerance center thickness*/ 0.2, /*edge thickness*/3.7, /*min diameter tolerance*/ -0.15,
		/*back focal length*/ 501.22, /*radius*/ 260.39, /*price*/ 43.00, /*coating*/ "ARB2-VIS", /*min wavelength*/ 450.0, /*max wavelength*/ 700.0);

	mQ_G312328000.buildLensTwoSurfaces_Qioptiq_oneSurfacePlan(/*lens catalog*/ "Qioptiq", /*catalog number*/ "G312328000", /*diameter*/ 25.4,
		/*focallength*/ 1000.0, /*tolerance focal length*/ 2.0,	/*material*/ glasses.getNBK7_S1(), /*optical centering accurancy*/ 10.0,
		/*surface quality*/ "3x0.25", /*thickness*/ 4.0, /*tolerance center thickness*/ 0.2, /*edge thickness*/3.8, /*min diameter tolerance*/ -0.15,
		/*back focal length*/ 981.21, /*radius*/ 508.45, /*price*/ 43.00, /*coating*/ "ARB2-VIS", /*min wavelength*/ 450.0, /*max wavelength*/ 700.0);

	mQ_G312401000.buildLensTwoSurfaces_Qioptiq_oneSurfacePlan(/*lens catalog*/ "Qioptiq", /*catalog number*/ "G312401000", /*diameter*/ 31.5,
		/*focallength*/ 40.0, /*tolerance focal length*/ 2.0,	/*material*/ glasses.getNBAK4_S1(), /*optical centering accurancy*/ 3.0,
		/*surface quality*/ "3x0.25", /*thickness*/ 8.3, /*tolerance center thickness*/ 0.2, /*edge thickness*/2.0, /*min diameter tolerance*/ -0.15,
		/*back focal length*/ 34.92, /*radius*/ 22.874, /*price*/ 55.00, /*coating*/ "ARB2-VIS", /*min wavelength*/ 450.0, /*max wavelength*/ 700.0);

	mQ_G312402000.buildLensTwoSurfaces_Qioptiq_oneSurfacePlan(/*lens catalog*/ "Qioptiq", /*catalog number*/ "G312402000", /*diameter*/ 31.5,
		/*focallength*/ 50.0, /*tolerance focal length*/ 2.0,	/*material*/ glasses.getNBAK4_S1(), /*optical centering accurancy*/ 3.0,
		/*surface quality*/ "3x0.25", /*thickness*/ 6.7, /*tolerance center thickness*/ 0.2, /*edge thickness*/2.0, /*min diameter tolerance*/ -0.07,
		/*back focal length*/ 45.99, /*radius*/ 28.593, /*price*/ 55.00, /*coating*/ "ARB2-VIS", /*min wavelength*/ 450.0, /*max wavelength*/ 700.0);

	mQ_G312332000.buildLensTwoSurfaces_Qioptiq_oneSurfacePlan(/*lens catalog*/ "Qioptiq", /*catalog number*/ "G312332000", /*diameter*/ 31.5,
		/*focallength*/ 60.0, /*tolerance focal length*/ 2.0,	/*material*/ glasses.getNBK7_S1(), /*optical centering accurancy*/ 3.0,
		/*surface quality*/ "3x0.25", /*thickness*/ 6.3, /*tolerance center thickness*/ 0.2, /*edge thickness*/2.1, /*min diameter tolerance*/ -0.07,
		/*back focal length*/ 57.48, /*radius*/ 31.851, /*price*/ 55.00, /*coating*/ "ARB2-VIS", /*min wavelength*/ 450.0, /*max wavelength*/ 700.0);

	mQ_G312403000.buildLensTwoSurfaces_Qioptiq_oneSurfacePlan(/*lens catalog*/ "Qioptiq", /*catalog number*/ "G312403000", /*diameter*/ 31.5,
		/*focallength*/ 80.0, /*tolerance focal length*/ 2.0,	/*material*/ glasses.getNBK7_S1(), /*optical centering accurancy*/ 3.0,
		/*surface quality*/ "3x0.25", /*thickness*/ 5.0, /*tolerance center thickness*/ 0.2, /*edge thickness*/1.9, /*min diameter tolerance*/ -0.07,
		/*back focal length*/ 77.14, /*radius*/ 41.568, /*price*/ 55.00, /*coating*/ "ARB2-VIS", /*min wavelength*/ 450.0, /*max wavelength*/ 700.0);

	mQ_G312333000.buildLensTwoSurfaces_Qioptiq_oneSurfacePlan(/*lens catalog*/ "Qioptiq", /*catalog number*/ "G312333000", /*diameter*/ 31.5,
		/*focallength*/ 100.0, /*tolerance focal length*/ 2.0,	/*material*/ glasses.getNBK7_S1(), /*optical centering accurancy*/ 3.0,
		/*surface quality*/ "3x0.25", /*thickness*/ 4.5, /*tolerance center thickness*/ 0.2, /*edge thickness*/2.1, /*min diameter tolerance*/ -0.07,
		/*back focal length*/ 98.3, /*radius*/ 52.33, /*price*/ 55.00, /*coating*/ "ARB2-VIS", /*min wavelength*/ 450.0, /*max wavelength*/ 700.0);

	mQ_G312404000.buildLensTwoSurfaces_Qioptiq_oneSurfacePlan(/*lens catalog*/ "Qioptiq", /*catalog number*/ "G312404000", /*diameter*/ 31.5,
		/*focallength*/ 150.0, /*tolerance focal length*/ 2.0,	/*material*/ glasses.getNBK7_S1(), /*optical centering accurancy*/ 3.0,
		/*surface quality*/ "3x0.25", /*thickness*/ 4.0, /*tolerance center thickness*/ 0.2, /*edge thickness*/2.4, /*min diameter tolerance*/ -0.07,
		/*back focal length*/ 148.33, /*radius*/ 78.021, /*price*/ 55.00, /*coating*/ "ARB2-VIS", /*min wavelength*/ 450.0, /*max wavelength*/ 700.0);

	mQ_G312405000.buildLensTwoSurfaces_Qioptiq_oneSurfacePlan(/*lens catalog*/ "Qioptiq", /*catalog number*/ "G312405000", /*diameter*/ 31.5,
		/*focallength*/ 200.0, /*tolerance focal length*/ 2.0,	/*material*/ glasses.getNBK7_S1(), /*optical centering accurancy*/ 3.0,
		/*surface quality*/ "3x0.25", /*thickness*/ 3.2, /*tolerance center thickness*/ 0.2, /*edge thickness*/2.0, /*min diameter tolerance*/ -0.07,
		/*back focal length*/ 199.21, /*radius*/ 104.04, /*price*/ 55.00, /*coating*/ "ARB2-VIS", /*min wavelength*/ 450.0, /*max wavelength*/ 700.0);

	mQ_G312406000.buildLensTwoSurfaces_Qioptiq_oneSurfacePlan(/*lens catalog*/ "Qioptiq", /*catalog number*/ "G312406000", /*diameter*/ 31.5,
		/*focallength*/ 300.0, /*tolerance focal length*/ 2.0,	/*material*/ glasses.getNBK7_S1(), /*optical centering accurancy*/ 3.0,
		/*surface quality*/ "3x0.25", /*thickness*/ 3.0, /*tolerance center thickness*/ 0.2, /*edge thickness*/2.2, /*min diameter tolerance*/ -0.07,
		/*back focal length*/ 299.23, /*radius*/ 155.663, /*price*/ 55.00, /*coating*/ "ARB2-VIS", /*min wavelength*/ 450.0, /*max wavelength*/ 700.0);

	mQ_G312407000.buildLensTwoSurfaces_Qioptiq_oneSurfacePlan(/*lens catalog*/ "Qioptiq", /*catalog number*/ "G312407000", /*diameter*/ 31.5,
		/*focallength*/ 500.0, /*tolerance focal length*/ 2.0,	/*material*/ glasses.getNBK7_S1(), /*optical centering accurancy*/ 10.0,
		/*surface quality*/ "3x0.063", /*thickness*/ 2.5, /*tolerance center thickness*/ 0.2, /*edge thickness*/2.0, /*min diameter tolerance*/ -0.07,
		/*back focal length*/ 500.43, /*radius*/ 259.476, /*price*/ 55.00, /*coating*/ "ARB2-VIS", /*min wavelength*/ 450.0, /*max wavelength*/ 700.0);

	mQ_G312312000.buildLensTwoSurfaces_Qioptiq_oneSurfacePlan(/*lens catalog*/ "Qioptiq", /*catalog number*/ "G312312000", /*diameter*/ 40.0,
		/*focallength*/ 50.0, /*tolerance focal length*/ 2.0,	/*material*/ glasses.getNBK7_S1(), /*optical centering accurancy*/ 10.0,
		/*surface quality*/ "3x0.25", /*thickness*/ 11.8, /*tolerance center thickness*/ 0.2, /*edge thickness*/2.6, /*min diameter tolerance*/ -0.16,
		/*back focal length*/ 43.34, /*radius*/ 26.416, /*price*/ 67.00, /*coating*/ "ARB2-VIS", /*min wavelength*/ 450.0, /*max wavelength*/ 700.0);

	mQ_G312340000.buildLensTwoSurfaces_Qioptiq_oneSurfacePlan(/*lens catalog*/ "Qioptiq", /*catalog number*/ "G312340000", /*diameter*/ 40.0,
		/*focallength*/ 60.0, /*tolerance focal length*/ 2.0,	/*material*/ glasses.getNBK7_S1(), /*optical centering accurancy*/ 10.0,
		/*surface quality*/ "3x0.25", /*thickness*/ 9.5, /*tolerance center thickness*/ 0.2, /*edge thickness*/2.4, /*min diameter tolerance*/ -0.16,
		/*back focal length*/ 55.37, /*radius*/ 31.851, /*price*/ 67.00, /*coating*/ "ARB2-VIS", /*min wavelength*/ 450.0, /*max wavelength*/ 700.0);

	mQ_G312350000.buildLensTwoSurfaces_Qioptiq_oneSurfacePlan(/*lens catalog*/ "Qioptiq", /*catalog number*/ "G312350000", /*diameter*/ 40.0,
		/*focallength*/ 80.0, /*tolerance focal length*/ 2.0,	/*material*/ glasses.getNBK7_S1(), /*optical centering accurancy*/ 10.0,
		/*surface quality*/ "3x0.25", /*thickness*/ 7.5, /*tolerance center thickness*/ 0.2, /*edge thickness*/2.3, /*min diameter tolerance*/ -0.16,
		/*back focal length*/ 74.91, /*radius*/ 41.269, /*price*/ 67.00, /*coating*/ "ARB2-VIS", /*min wavelength*/ 450.0, /*max wavelength*/ 700.0);

	mQ_G312341000.buildLensTwoSurfaces_Qioptiq_oneSurfacePlan(/*lens catalog*/ "Qioptiq", /*catalog number*/ "G312341000", /*diameter*/ 40.0,
		/*focallength*/ 150.0, /*tolerance focal length*/ 2.0,	/*material*/ glasses.getNBK7_S1(), /*optical centering accurancy*/ 10.0,
		/*surface quality*/ "3x0.25", /*thickness*/ 5.0, /*tolerance center thickness*/ 0.2, /*edge thickness*/2.4, /*min diameter tolerance*/ -0.16,
		/*back focal length*/ 148.22, /*radius*/ 78.298, /*price*/ 67.00, /*coating*/ "ARB2-VIS", /*min wavelength*/ 450.0, /*max wavelength*/ 700.0);

	mQ_G312334000.buildLensTwoSurfaces_Qioptiq_oneSurfacePlan(/*lens catalog*/ "Qioptiq", /*catalog number*/ "G312334000", /*diameter*/ 50.0,
		/*focallength*/ 100.0, /*tolerance focal length*/ 2.0,	/*material*/ glasses.getNBK7_S1(), /*optical centering accurancy*/ 10.0,
		/*surface quality*/ "3x0.25", /*thickness*/ 9.0, /*tolerance center thickness*/ 0.2, /*edge thickness*/2.6, /*min diameter tolerance*/ -0.16,
		/*back focal length*/ 95.33, /*radius*/ 52.33, /*price*/ 78.00, /*coating*/ "ARB2-VIS", /*min wavelength*/ 450.0, /*max wavelength*/ 700.0);

	mQ_G312335000.buildLensTwoSurfaces_Qioptiq_oneSurfacePlan(/*lens catalog*/ "Qioptiq", /*catalog number*/ "G312335000", /*diameter*/ 50.0,
		/*focallength*/ 150.0, /*tolerance focal length*/ 2.0,	/*material*/ glasses.getNBK7_S1(), /*optical centering accurancy*/ 10.0,
		/*surface quality*/ "3x0.25", /*thickness*/ 6.5, /*tolerance center thickness*/ 0.2, /*edge thickness*/2.4, /*min diameter tolerance*/ -0.16,
		/*back focal length*/ 147.23, /*radius*/ 78.298, /*price*/ 78.00, /*coating*/ "ARB2-VIS", /*min wavelength*/ 450.0, /*max wavelength*/ 700.0);

	// no zemax file available
	// price -> on request
	mQ_G312361000.buildLensTwoSurfaces_Qioptiq_oneSurfacePlan(/*lens catalog*/ "Qioptiq", /*catalog number*/ "G312361000", /*diameter*/ 63.0,
		/*focallength*/ 140.0, /*tolerance focal length*/ 2.0,	/*material*/ glasses.getNBK7_S1(), /*optical centering accurancy*/ 10.0,
		/*surface quality*/ "3x0.25", /*thickness*/ 10.0, /*tolerance center thickness*/ 0.2, /*edge thickness*/2.8, /*min diameter tolerance*/ -0.19,
		/*back focal length*/ 134.4, /*radius*/ 72.862, /*price*/ 9999999.0, /*coating*/ "ARB2-VIS", /*min wavelength*/ 450.0, /*max wavelength*/ 700.0);

	// no zemax file available
	// price -> on request
	mQ_G312363000.buildLensTwoSurfaces_Qioptiq_oneSurfacePlan(/*lens catalog*/ "Qioptiq", /*catalog number*/ "G312363000", /*diameter*/ 63.0,
		/*focallength*/ 300.0, /*tolerance focal length*/ 2.0,	/*material*/ glasses.getNBK7_S1(), /*optical centering accurancy*/ 10.0,
		/*surface quality*/ "3x0.25", /*thickness*/ 5.5, /*tolerance center thickness*/ 0.2, /*edge thickness*/2.3, /*min diameter tolerance*/ -0.19,
		/*back focal length*/ 298.7, /*radius*/ 156.22, /*price*/ 9999999.0, /*coating*/ "ARB2-VIS", /*min wavelength*/ 450.0, /*max wavelength*/ 700.0);

	// no zemax file available
	mQ_G312001000.buildLensTwoSurfaces_Qioptiq_oneSurfacePlan(/*lens catalog*/ "Qioptiq", /*catalog number*/ "G312001000", /*diameter*/ 2.0,
		/*focallength*/ 1.5, /*tolerance focal length*/ 2.0,	/*material*/ glasses.getNLASF9_S1(), /*optical centering accurancy*/ 9.0,
		/*surface quality*/ "3x0.063", /*thickness*/ 0.8, /*tolerance center thickness*/ 0.02, /*edge thickness*/0.32, /*min diameter tolerance*/ -0.02,
		/*back focal length*/ 1.07, /*radius*/ 1.275, /*price*/ 14.00, /*coating*/ "ARB2-VIS", /*min wavelength*/ 450.0, /*max wavelength*/ 700.0);

	// no zemax file available
	mQ_G312362000.buildLensTwoSurfaces_Qioptiq_oneSurfacePlan(/*lens catalog*/ "Qioptiq", /*catalog number*/ "G312362000", /*diameter*/ 63.0,
		/*focallength*/ 200.0, /*tolerance focal length*/ 2.0,	/*material*/ glasses.getNBK7_S1(), /*optical centering accurancy*/ 10.0,
		/*surface quality*/ "3x0.25", /*thickness*/ 8.0, /*tolerance center thickness*/ 0.2, /*edge thickness*/ 3.1, /*min diameter tolerance*/ -0.19,
		/*back focal length*/ 196.78, /*radius*/ 104.41, /*price*/ 59.00, /*coating*/ "ARB2-VIS", /*min wavelength*/ 450.0, /*max wavelength*/ 700.0);










}
std::vector<LensesTwoSurfaces> QioptiqLensCatalog::getAll_Qioptiq_PlanoConvex_lenses_unmounted_ARB2_VIS()
{
	// https://www.qioptiq-shop.com/en/Precision-Optics/Singlets/Plano-Convex-Lenses/Plano-convex-lenses-unmounted.html

	std::vector<LensesTwoSurfaces> return_Qioptiq_PlanoConvex_lenses_unmounted_ARB2_VIS;
	return_Qioptiq_PlanoConvex_lenses_unmounted_ARB2_VIS.push_back(mQ_G312003000);
	return_Qioptiq_PlanoConvex_lenses_unmounted_ARB2_VIS.push_back(mQ_G312004000);
	return_Qioptiq_PlanoConvex_lenses_unmounted_ARB2_VIS.push_back(mQ_G312006000);
	return_Qioptiq_PlanoConvex_lenses_unmounted_ARB2_VIS.push_back(mQ_G312007000);
	return_Qioptiq_PlanoConvex_lenses_unmounted_ARB2_VIS.push_back(mQ_G312008000);
	return_Qioptiq_PlanoConvex_lenses_unmounted_ARB2_VIS.push_back(mQ_G312201000);
	return_Qioptiq_PlanoConvex_lenses_unmounted_ARB2_VIS.push_back(mQ_G312009000);
	return_Qioptiq_PlanoConvex_lenses_unmounted_ARB2_VIS.push_back(mQ_G312010000);
	return_Qioptiq_PlanoConvex_lenses_unmounted_ARB2_VIS.push_back(mQ_G312011000);
	return_Qioptiq_PlanoConvex_lenses_unmounted_ARB2_VIS.push_back(mQ_G312236000);
	return_Qioptiq_PlanoConvex_lenses_unmounted_ARB2_VIS.push_back(mQ_G312329000);
	return_Qioptiq_PlanoConvex_lenses_unmounted_ARB2_VIS.push_back(mQ_G312330000);
	return_Qioptiq_PlanoConvex_lenses_unmounted_ARB2_VIS.push_back(mQ_G312351000);
	return_Qioptiq_PlanoConvex_lenses_unmounted_ARB2_VIS.push_back(mQ_G312352000);
	return_Qioptiq_PlanoConvex_lenses_unmounted_ARB2_VIS.push_back(mQ_G312353000);
	return_Qioptiq_PlanoConvex_lenses_unmounted_ARB2_VIS.push_back(mQ_G312354000);
	return_Qioptiq_PlanoConvex_lenses_unmounted_ARB2_VIS.push_back(mQ_G312355000);
	return_Qioptiq_PlanoConvex_lenses_unmounted_ARB2_VIS.push_back(mQ_G312356000);
	return_Qioptiq_PlanoConvex_lenses_unmounted_ARB2_VIS.push_back(mQ_G312357000);
	return_Qioptiq_PlanoConvex_lenses_unmounted_ARB2_VIS.push_back(mQ_G312358000);
	return_Qioptiq_PlanoConvex_lenses_unmounted_ARB2_VIS.push_back(mQ_G312331000);
	return_Qioptiq_PlanoConvex_lenses_unmounted_ARB2_VIS.push_back(mQ_G312314000);
	return_Qioptiq_PlanoConvex_lenses_unmounted_ARB2_VIS.push_back(mQ_G312315000);
	return_Qioptiq_PlanoConvex_lenses_unmounted_ARB2_VIS.push_back(mQ_G312316000);
	return_Qioptiq_PlanoConvex_lenses_unmounted_ARB2_VIS.push_back(mQ_G312317000);
	return_Qioptiq_PlanoConvex_lenses_unmounted_ARB2_VIS.push_back(mQ_G312318000);
	return_Qioptiq_PlanoConvex_lenses_unmounted_ARB2_VIS.push_back(mQ_G312319000);
	return_Qioptiq_PlanoConvex_lenses_unmounted_ARB2_VIS.push_back(mQ_G312320000);
	return_Qioptiq_PlanoConvex_lenses_unmounted_ARB2_VIS.push_back(mQ_G312321000);
	return_Qioptiq_PlanoConvex_lenses_unmounted_ARB2_VIS.push_back(mQ_G312322000);
	return_Qioptiq_PlanoConvex_lenses_unmounted_ARB2_VIS.push_back(mQ_G312323000);
	return_Qioptiq_PlanoConvex_lenses_unmounted_ARB2_VIS.push_back(mQ_G312324000);
	return_Qioptiq_PlanoConvex_lenses_unmounted_ARB2_VIS.push_back(mQ_G312325000);
	return_Qioptiq_PlanoConvex_lenses_unmounted_ARB2_VIS.push_back(mQ_G312326000);
	return_Qioptiq_PlanoConvex_lenses_unmounted_ARB2_VIS.push_back(mQ_G312327000);
	return_Qioptiq_PlanoConvex_lenses_unmounted_ARB2_VIS.push_back(mQ_G312328000);
	return_Qioptiq_PlanoConvex_lenses_unmounted_ARB2_VIS.push_back(mQ_G312401000);
	return_Qioptiq_PlanoConvex_lenses_unmounted_ARB2_VIS.push_back(mQ_G312402000);
	return_Qioptiq_PlanoConvex_lenses_unmounted_ARB2_VIS.push_back(mQ_G312332000);
	return_Qioptiq_PlanoConvex_lenses_unmounted_ARB2_VIS.push_back(mQ_G312403000);
	return_Qioptiq_PlanoConvex_lenses_unmounted_ARB2_VIS.push_back(mQ_G312333000);
	return_Qioptiq_PlanoConvex_lenses_unmounted_ARB2_VIS.push_back(mQ_G312404000);
	return_Qioptiq_PlanoConvex_lenses_unmounted_ARB2_VIS.push_back(mQ_G312405000);
	return_Qioptiq_PlanoConvex_lenses_unmounted_ARB2_VIS.push_back(mQ_G312406000);
	return_Qioptiq_PlanoConvex_lenses_unmounted_ARB2_VIS.push_back(mQ_G312407000);
	return_Qioptiq_PlanoConvex_lenses_unmounted_ARB2_VIS.push_back(mQ_G312312000);
	return_Qioptiq_PlanoConvex_lenses_unmounted_ARB2_VIS.push_back(mQ_G312340000);
	return_Qioptiq_PlanoConvex_lenses_unmounted_ARB2_VIS.push_back(mQ_G312350000);
	return_Qioptiq_PlanoConvex_lenses_unmounted_ARB2_VIS.push_back(mQ_G312341000);
	return_Qioptiq_PlanoConvex_lenses_unmounted_ARB2_VIS.push_back(mQ_G312334000);
	return_Qioptiq_PlanoConvex_lenses_unmounted_ARB2_VIS.push_back(mQ_G312335000);
	return_Qioptiq_PlanoConvex_lenses_unmounted_ARB2_VIS.push_back(mQ_G312361000);
	return_Qioptiq_PlanoConvex_lenses_unmounted_ARB2_VIS.push_back(mQ_G312363000);
	return_Qioptiq_PlanoConvex_lenses_unmounted_ARB2_VIS.push_back(mQ_G312001000);
	return_Qioptiq_PlanoConvex_lenses_unmounted_ARB2_VIS.push_back(mQ_G312362000);

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

	mQ_G311329000.buildLensTwoSurfaces_Qioptiq_lenses(/*lens catalog*/ "Qioptiq", /*catalog number*/ "G311329000", /*diameter*/ 8.0,
		/*focallength*/ 7.0, /*tolerance focal length*/ 2.0, /*material*/ glasses.getNBAK4_S1(), /*optical centering accurancy*/10.0,
		/*surface quality*/ "3x0.1", /*thickness*/ 3.4, /*tolerance center thickness*/ 0.1, /*edge thickness*/ 1.1, /*min diameter tolerance*/ -0.09,
		/*back focal length*/ 6.0, /*radius first surface*/ 7.499, /*radius second surface*/ -7.499, /*price*/ 49.0, /*coating*/ "ARB2-VIS",
		/*min wavelength*/ 450.0, /*max wavelength*/ 700.0);

	mQ_G311300000.buildLensTwoSurfaces_Qioptiq_lenses(/*lens catalog*/ "Qioptiq", /*catalog number*/ "G311300000", /*diameter*/ 10.0,
		/*focallength*/ 10.0, /*tolerance focal length*/ 2.0, /*material*/ glasses.getNBAK4_S1(), /*optical centering accurancy*/10.0,
		/*surface quality*/ "3x0.16", /*thickness*/ 3.5, /*tolerance center thickness*/ 0.1, /*edge thickness*/ 1.0, /*min diameter tolerance*/ -0.09,
		/*back focal length*/ 8.78, /*radius first surface*/ 10.669, /*radius second surface*/ -10.669, /*price*/ 43.0, /*coating*/ "ARB2-VIS",
		/*min wavelength*/ 450.0, /*max wavelength*/ 700.0);

	mQ_G311377000.buildLensTwoSurfaces_Qioptiq_lenses(/*lens catalog*/ "Qioptiq", /*catalog number*/ "G311377000", /*diameter*/ 12.5,
		/*focallength*/ 12.5, /*tolerance focal length*/ 2.0, /*material*/ glasses.getNBK7_S1(), /*optical centering accurancy*/10.0,
		/*surface quality*/ "3x0.16", /*thickness*/ 4.5, /*tolerance center thickness*/ 0.1, /*edge thickness*/ 1.0, /*min diameter tolerance*/ -0.11,
		/*back focal length*/ 10.79, /*radius first surface*/ 11.971, /*radius second surface*/ -11.971, /*price*/ 43.0, /*coating*/ "ARB2-VIS",
		/*min wavelength*/ 450.0, /*max wavelength*/ 700.0);

	mQ_G311381000.buildLensTwoSurfaces_Qioptiq_lenses(/*lens catalog*/ "Qioptiq", /*catalog number*/ "G311381000", /*diameter*/ 12.7,
		/*focallength*/ 15.0, /*tolerance focal length*/ 2.0, /*material*/ glasses.getNBK7_S1(), /*optical centering accurancy*/10.0,
		/*surface quality*/ "3x0.16", /*thickness*/ 4.0, /*tolerance center thickness*/ 0.1, /*edge thickness*/ 1.1, /*min diameter tolerance*/ -0.12,
		/*back focal length*/ 13.58, /*radius first surface*/ 14.749, /*radius second surface*/ -14.749, /*price*/ 38.0, /*coating*/ "ARB2-VIS",
		/*min wavelength*/ 450.0, /*max wavelength*/ 700.0);

	mQ_G311382000.buildLensTwoSurfaces_Qioptiq_lenses(/*lens catalog*/ "Qioptiq", /*catalog number*/ "G311382000", /*diameter*/ 12.7,
		/*focallength*/ 20.0, /*tolerance focal length*/ 2.0, /*material*/ glasses.getNBK7_S1(), /*optical centering accurancy*/10.0,
		/*surface quality*/ "3x0.16", /*thickness*/ 3.0, /*tolerance center thickness*/ 0.1, /*edge thickness*/ 0.9, /*min diameter tolerance*/ -0.12,
		/*back focal length*/ 18.94, /*radius first surface*/ 20.097, /*radius second surface*/ -20.097, /*price*/ 38.0, /*coating*/ "ARB2-VIS",
		/*min wavelength*/ 450.0, /*max wavelength*/ 700.0);

	mQ_G311383000.buildLensTwoSurfaces_Qioptiq_lenses(/*lens catalog*/ "Qioptiq", /*catalog number*/ "G311383000", /*diameter*/ 12.7,
		/*focallength*/ 30.0, /*tolerance focal length*/ 2.0, /*material*/ glasses.getNBK7_S1(), /*optical centering accurancy*/10.0,
		/*surface quality*/ "3x0.16", /*thickness*/ 3.0, /*tolerance center thickness*/ 0.1, /*edge thickness*/ 1.6, /*min diameter tolerance*/ -0.12,
		/*back focal length*/ 28.8, /*radius first surface*/ 30.287, /*radius second surface*/ -30.287, /*price*/ 38.0, /*coating*/ "ARB2-VIS",
		/*min wavelength*/ 450.0, /*max wavelength*/ 700.0);

	mQ_G311384000.buildLensTwoSurfaces_Qioptiq_lenses(/*lens catalog*/ "Qioptiq", /*catalog number*/ "G311384000", /*diameter*/ 12.7,
		/*focallength*/ 50.0, /*tolerance focal length*/ 2.0, /*material*/ glasses.getNBK7_S1(), /*optical centering accurancy*/10.0,
		/*surface quality*/ "3x0.16", /*thickness*/ 3.0, /*tolerance center thickness*/ 0.1, /*edge thickness*/ 2.2, /*min diameter tolerance*/ -0.12,
		/*back focal length*/ 48.92, /*radius first surface*/ 51.08, /*radius second surface*/ -51.08, /*price*/ 38.0, /*coating*/ "ARB2-VIS",
		/*min wavelength*/ 450.0, /*max wavelength*/ 700.0);

	// no zemax file available
	mQ_G311385000.buildLensTwoSurfaces_Qioptiq_lenses(/*lens catalog*/ "Qioptiq", /*catalog number*/ "G311385000", /*diameter*/ 12.7,
		/*focallength*/ 80.0, /*tolerance focal length*/ 2.0, /*material*/ glasses.getNBK7_S1(), /*optical centering accurancy*/10.0,
		/*surface quality*/ "3x0.16", /*thickness*/ 3.0, /*tolerance center thickness*/ 0.1, /*edge thickness*/ 2.5, /*min diameter tolerance*/ -0.12,
		/*back focal length*/ 78.03, /*radius first surface*/ 81.166, /*radius second surface*/ -81.166, /*price*/ 14.0, /*coating*/ "ARB2-VIS",
		/*min wavelength*/ 450.0, /*max wavelength*/ 700.0);

	// no zemax file available
	// price -> on request
	mQ_G311386000.buildLensTwoSurfaces_Qioptiq_lenses(/*lens catalog*/ "Qioptiq", /*catalog number*/ "G311386000", /*diameter*/ 12.7,
		/*focallength*/ 100.0, /*tolerance focal length*/ 2.0, /*material*/ glasses.getNBK7_S1(), /*optical centering accurancy*/ 10.0,
		/*surface quality*/ "3x0.16", /*thickness*/ 3.0, /*tolerance center thickness*/ 0.1, /*edge thickness*/ 2.6, /*min diameter tolerance*/ -0.12,
		/*back focal length*/ 99.08, /*radius first surface*/ 102.92, /*radius second surface*/ -102.92, /*price*/ 999999.0, /*coating*/ "ARB2-VIS",
		/*min wavelength*/ 450.0, /*max wavelength*/ 700.0);

	mQ_G311387000.buildLensTwoSurfaces_Qioptiq_lenses(/*lens catalog*/ "Qioptiq", /*catalog number*/ "G311387000", /*diameter*/ 12.7,
		/*focallength*/ 150.0, /*tolerance focal length*/ 2.0, /*material*/ glasses.getNBK7_S1(), /*optical centering accurancy*/10.0,
		/*surface quality*/ "3x0.16", /*thickness*/ 3.0, /*tolerance center thickness*/ 0.1, /*edge thickness*/ 2.7, /*min diameter tolerance*/ -0.12,
		/*back focal length*/ 148.5, /*radius first surface*/ 153.99, /*radius second surface*/ -153.99, /*price*/ 51.0, /*coating*/ "ARB2-VIS",
		/*min wavelength*/ 450.0, /*max wavelength*/ 700.0);

	mQ_G311378000.buildLensTwoSurfaces_Qioptiq_lenses(/*lens catalog*/ "Qioptiq", /*catalog number*/ "G311378000", /*diameter*/ 18.0,
		/*focallength*/ 16.0, /*tolerance focal length*/ 2.0, /*material*/ glasses.getNBK7_S1(), /*optical centering accurancy*/10.0,
		/*surface quality*/ "3x0.16", /*thickness*/ 7.0, /*tolerance center thickness*/ 0.2, /*edge thickness*/ 1.1, /*min diameter tolerance*/ -0.11,
		/*back focal length*/ 13.43, /*radius first surface*/ 15.179, /*radius second surface*/ -15.179, /*price*/ 43.0, /*coating*/ "ARB2-VIS",
		/*min wavelength*/ 450.0, /*max wavelength*/ 700.0);

	mQ_G311338000.buildLensTwoSurfaces_Qioptiq_lenses(/*lens catalog*/ "Qioptiq", /*catalog number*/ "G311338000", /*diameter*/ 22.4,
		/*focallength*/ 20.0, /*tolerance focal length*/ 2.0, /*material*/ glasses.getNBK7_S1(), /*optical centering accurancy*/10.0,
		/*surface quality*/ "3x0.25", /*thickness*/ 8.8, /*tolerance center thickness*/ 0.2, /*edge thickness*/ 1.6, /*min diameter tolerance*/ -0.13,
		/*back focal length*/ 17.05, /*radius first surface*/ 19.248, /*radius second surface*/ -19.248, /*price*/ 50.0, /*coating*/ "ARB2-VIS",
		/*min wavelength*/ 450.0, /*max wavelength*/ 700.0);

	mQ_G311308000.buildLensTwoSurfaces_Qioptiq_lenses(/*lens catalog*/ "Qioptiq", /*catalog number*/ "G311308000", /*diameter*/ 22.4,
		/*focallength*/ 25.0, /*tolerance focal length*/ 2.0, /*material*/ glasses.getNBK7_S1(), /*optical centering accurancy*/10.0,
		/*surface quality*/ "3x0.25", /*thickness*/ 7.0, /*tolerance center thickness*/ 0.2, /*edge thickness*/ 1.6, /*min diameter tolerance*/ -0.13,
		/*back focal length*/ 22.4, /*radius first surface*/ 24.406, /*radius second surface*/ -24.406, /*price*/ 50.0, /*coating*/ "ARB2-VIS",
		/*min wavelength*/ 450.0, /*max wavelength*/ 700.0);

	mQ_G311310000.buildLensTwoSurfaces_Qioptiq_lenses(/*lens catalog*/ "Qioptiq", /*catalog number*/ "G311310000", /*diameter*/ 22.4,
		/*focallength*/ 30.0, /*tolerance focal length*/ 2.0, /*material*/ glasses.getNBK7_S1(), /*optical centering accurancy*/10.0,
		/*surface quality*/ "3x0.25", /*thickness*/ 6.3, /*tolerance center thickness*/ 0.2, /*edge thickness*/ 2.0, /*min diameter tolerance*/ -0.13,
		/*back focal length*/ 28.01, /*radius first surface*/ 30.069, /*radius second surface*/ -30.069, /*price*/ 50.0, /*coating*/ "ARB2-VIS",
		/*min wavelength*/ 450.0, /*max wavelength*/ 700.0);

	mQ_G311314000.buildLensTwoSurfaces_Qioptiq_lenses(/*lens catalog*/ "Qioptiq", /*catalog number*/ "G311314000", /*diameter*/ 22.4,
		/*focallength*/ 40.0, /*tolerance focal length*/ 2.0, /*material*/ glasses.getNBK7_S1(), /*optical centering accurancy*/10.0,
		/*surface quality*/ "3x0.25", /*thickness*/ 5.0, /*tolerance center thickness*/ 0.2, /*edge thickness*/ 2.0, /*min diameter tolerance*/ -0.13,
		/*back focal length*/ 39.66, /*radius first surface*/ 41.867, /*radius second surface*/ -41.867, /*price*/ 50.0, /*coating*/ "ARB2-VIS",
		/*min wavelength*/ 450.0, /*max wavelength*/ 700.0);

	mQ_G311315000.buildLensTwoSurfaces_Qioptiq_lenses(/*lens catalog*/ "Qioptiq", /*catalog number*/ "G311315000", /*diameter*/ 22.4,
		/*focallength*/ 50.0, /*tolerance focal length*/ 2.0, /*material*/ glasses.getNBK7_S1(), /*optical centering accurancy*/10.0,
		/*surface quality*/ "3x0.25", /*thickness*/ 4.5, /*tolerance center thickness*/ 0.2, /*edge thickness*/ 2.1, /*min diameter tolerance*/ -0.13,
		/*back focal length*/ 49.88, /*radius first surface*/ 52.33, /*radius second surface*/ -52.33, /*price*/ 50.0, /*coating*/ "ARB2-VIS",
		/*min wavelength*/ 450.0, /*max wavelength*/ 700.0);

	mQ_G311316000.buildLensTwoSurfaces_Qioptiq_lenses(/*lens catalog*/ "Qioptiq", /*catalog number*/ "G311316000", /*diameter*/ 22.4,
		/*focallength*/ 60.0, /*tolerance focal length*/ 2.0, /*material*/ glasses.getNBK7_S1(), /*optical centering accurancy*/10.0,
		/*surface quality*/ "3x0.25", /*thickness*/ 4.0, /*tolerance center thickness*/ 0.2, /*edge thickness*/ 2.0, /*min diameter tolerance*/ -0.13,
		/*back focal length*/ 59.94, /*radius first surface*/ 62.643, /*radius second surface*/ -62.643, /*price*/ 50.0, /*coating*/ "ARB2-VIS",
		/*min wavelength*/ 450.0, /*max wavelength*/ 700.0);

	mQ_G311317000.buildLensTwoSurfaces_Qioptiq_lenses(/*lens catalog*/ "Qioptiq", /*catalog number*/ "G311317000", /*diameter*/ 22.4,
		/*focallength*/ 80.0, /*tolerance focal length*/ 2.0, /*material*/ glasses.getNBK7_S1(), /*optical centering accurancy*/10.0,
		/*surface quality*/ "3x0.25", /*thickness*/ 3.5, /*tolerance center thickness*/ 0.2, /*edge thickness*/ 2.0, /*min diameter tolerance*/ -0.13,
		/*back focal length*/ 80.24, /*radius first surface*/ 83.536, /*radius second surface*/ -83.536, /*price*/ 50.0, /*coating*/ "ARB2-VIS",
		/*min wavelength*/ 450.0, /*max wavelength*/ 700.0);

	mQ_G311318000.buildLensTwoSurfaces_Qioptiq_lenses(/*lens catalog*/ "Qioptiq", /*catalog number*/ "G311318000", /*diameter*/ 22.4,
		/*focallength*/ 100.0, /*tolerance focal length*/ 2.0, /*material*/ glasses.getNBK7_S1(), /*optical centering accurancy*/10.0,
		/*surface quality*/ "3x0.25", /*thickness*/ 3.5, /*tolerance center thickness*/ 0.2, /*edge thickness*/ 2.3, /*min diameter tolerance*/ -0.13,
		/*back focal length*/ 100.44, /*radius first surface*/ 104.41, /*radius second surface*/ -104.41, /*price*/ 50.0, /*coating*/ "ARB2-VIS",
		/*min wavelength*/ 450.0, /*max wavelength*/ 700.0);

	mQ_G311319000.buildLensTwoSurfaces_Qioptiq_lenses(/*lens catalog*/ "Qioptiq", /*catalog number*/ "G311319000", /*diameter*/ 22.4,
		/*focallength*/ 150.0, /*tolerance focal length*/ 2.0, /*material*/ glasses.getNBK7_S1(), /*optical centering accurancy*/10.0,
		/*surface quality*/ "3x0.25", /*thickness*/ 3.0, /*tolerance center thickness*/ 0.2, /*edge thickness*/ 2.2, /*min diameter tolerance*/ -0.13,
		/*back focal length*/ 150.65, /*radius first surface*/ 156.22, /*radius second surface*/ -156.22, /*price*/ 50.0, /*coating*/ "ARB2-VIS",
		/*min wavelength*/ 450.0, /*max wavelength*/ 700.0);

	mQ_G311320000.buildLensTwoSurfaces_Qioptiq_lenses(/*lens catalog*/ "Qioptiq", /*catalog number*/ "G311320000", /*diameter*/ 22.4,
		/*focallength*/ 200.0, /*tolerance focal length*/ 2.0, /*material*/ glasses.getNBK7_S1(), /*optical centering accurancy*/10.0,
		/*surface quality*/ "3x0.25", /*thickness*/ 3.0, /*tolerance center thickness*/ 0.2, /*edge thickness*/ 2.4, /*min diameter tolerance*/ -0.13,
		/*back focal length*/ 202.51, /*radius first surface*/ 209.83, /*radius second surface*/ -209.83, /*price*/ 42.0, /*coating*/ "ARB2-VIS",
		/*min wavelength*/ 450.0, /*max wavelength*/ 700.0);

	mQ_G311321000.buildLensTwoSurfaces_Qioptiq_lenses(/*lens catalog*/ "Qioptiq", /*catalog number*/ "G311321000", /*diameter*/ 25.4,
		/*focallength*/ 30.0, /*tolerance focal length*/ 2.0, /*material*/ glasses.getNBK7_S1(), /*optical centering accurancy*/ 0.0,
		/*surface quality*/ "3x0.25", /*thickness*/ 7.0, /*tolerance center thickness*/ 0.2, /*edge thickness*/ 1.4, /*min diameter tolerance*/ -0.06,
		/*back focal length*/ 27.89, /*radius first surface*/ 30.069, /*radius second surface*/ -30.069, /*price*/ 42.0, /*coating*/ "ARB2-VIS",
		/*min wavelength*/ 450.0, /*max wavelength*/ 700.0);

	mQ_G311322000.buildLensTwoSurfaces_Qioptiq_lenses(/*lens catalog*/ "Qioptiq", /*catalog number*/ "G311322000", /*diameter*/ 25.4,
		/*focallength*/ 50.0, /*tolerance focal length*/ 2.0, /*material*/ glasses.getNBK7_S1(), /*optical centering accurancy*/ 0.0,
		/*surface quality*/ "3x0.25", /*thickness*/ 7.0, /*tolerance center thickness*/ 0.2, /*edge thickness*/ 3.8, /*min diameter tolerance*/ -0.06,
		/*back focal length*/ 48.24, /*radius first surface*/ 51.08, /*radius second surface*/ -51.08, /*price*/ 42.0, /*coating*/ "ARB2-VIS",
		/*min wavelength*/ 450.0, /*max wavelength*/ 700.0);

	mQ_G311323000.buildLensTwoSurfaces_Qioptiq_lenses(/*lens catalog*/ "Qioptiq", /*catalog number*/ "G311323000", /*diameter*/ 25.4,
		/*focallength*/ 80.0, /*tolerance focal length*/ 2.0, /*material*/ glasses.getNBK7_S1(), /*optical centering accurancy*/ 0.0,
		/*surface quality*/ "3x0.25", /*thickness*/ 7.0, /*tolerance center thickness*/ 0.2, /*edge thickness*/ 5.0, /*min diameter tolerance*/ -0.06,
		/*back focal length*/ 77.36, /*radius first surface*/ 81.166, /*radius second surface*/ -81.166, /*price*/ 42.0, /*coating*/ "ARB2-VIS",
		/*min wavelength*/ 450.0, /*max wavelength*/ 700.0);

	mQ_G311324000.buildLensTwoSurfaces_Qioptiq_lenses(/*lens catalog*/ "Qioptiq", /*catalog number*/ "G311324000", /*diameter*/ 25.4,
		/*focallength*/ 100.0, /*tolerance focal length*/ 2.0, /*material*/ glasses.getNBK7_S1(), /*optical centering accurancy*/ 0.0,
		/*surface quality*/ "3x0.25", /*thickness*/ 7.0, /*tolerance center thickness*/ 0.2, /*edge thickness*/ 5.4, /*min diameter tolerance*/ -0.06,
		/*back focal length*/ 98.41, /*radius first surface*/ 102.92, /*radius second surface*/ -102.92, /*price*/ 42.0, /*coating*/ "ARB2-VIS",
		/*min wavelength*/ 450.0, /*max wavelength*/ 700.0);

	mQ_G311325000.buildLensTwoSurfaces_Qioptiq_lenses(/*lens catalog*/ "Qioptiq", /*catalog number*/ "G311325000", /*diameter*/ 25.4,
		/*focallength*/ 150.0, /*tolerance focal length*/ 2.0, /*material*/ glasses.getNBK7_S1(), /*optical centering accurancy*/ 0.0,
		/*surface quality*/ "3x0.25", /*thickness*/ 7.0, /*tolerance center thickness*/ 0.2, /*edge thickness*/ 6.0, /*min diameter tolerance*/ -0.06,
		/*back focal length*/ 147.8, /*radius first surface*/ 153.99, /*radius second surface*/ -153.99, /*price*/ 45.0, /*coating*/ "ARB2-VIS",
		/*min wavelength*/ 450.0, /*max wavelength*/ 700.0);

	mQ_G311331000.buildLensTwoSurfaces_Qioptiq_lenses(/*lens catalog*/ "Qioptiq", /*catalog number*/ "G311331000", /*diameter*/ 31.5,
		/*focallength*/ 30.0, /*tolerance focal length*/ 2.0, /*material*/ glasses.getNBK7_S1(), /*optical centering accurancy*/ 0.0,
		/*surface quality*/ "3x0.25", /*thickness*/ 9.5, /*tolerance center thickness*/ 0.2, /*edge thickness*/ 2.0, /*min diameter tolerance*/ -0.07,
		/*back focal length*/ 27.03, /*radius first surface*/ 34.721, /*radius second surface*/ -34.721, /*price*/ 55.0, /*coating*/ "ARB2-VIS",
		/*min wavelength*/ 450.0, /*max wavelength*/ 700.0);

	mQ_G311339000.buildLensTwoSurfaces_Qioptiq_lenses(/*lens catalog*/ "Qioptiq", /*catalog number*/ "G311339000", /*diameter*/ 31.5,
		/*focallength*/ 40.0, /*tolerance focal length*/ 2.0, /*material*/ glasses.getNBK7_S1(), /*optical centering accurancy*/ 0.0,
		/*surface quality*/ "3x0.25", /*thickness*/ 8.3, /*tolerance center thickness*/ 0.2, /*edge thickness*/ 2.1, /*min diameter tolerance*/ -0.07,
		/*back focal length*/ 39.09, /*radius first surface*/ 41.867, /*radius second surface*/ -41.867, /*price*/ 55.0, /*coating*/ "ARB2-VIS",
		/*min wavelength*/ 450.0, /*max wavelength*/ 700.0);

	mQ_G311351000.buildLensTwoSurfaces_Qioptiq_lenses(/*lens catalog*/ "Qioptiq", /*catalog number*/ "G311351000", /*diameter*/ 31.5,
		/*focallength*/ 50.0, /*tolerance focal length*/ 2.0, /*material*/ glasses.getNBK7_S1(), /*optical centering accurancy*/ 0.0,
		/*surface quality*/ "3x0.25", /*thickness*/ 7.0, /*tolerance center thickness*/ 0.2, /*edge thickness*/ 2.1, /*min diameter tolerance*/ -0.07,
		/*back focal length*/ 49.45, /*radius first surface*/ 52.33, /*radius second surface*/ -52.33, /*price*/ 55.0, /*coating*/ "ARB2-VIS",
		/*min wavelength*/ 450.0, /*max wavelength*/ 700.0);

	mQ_G311357000.buildLensTwoSurfaces_Qioptiq_lenses(/*lens catalog*/ "Qioptiq", /*catalog number*/ "G311357000", /*diameter*/ 31.5,
		/*focallength*/ 70.0, /*tolerance focal length*/ 2.0, /*material*/ glasses.getNBK7_S1(), /*optical centering accurancy*/ 0.0,
		/*surface quality*/ "3x0.25", /*thickness*/ 5.5, /*tolerance center thickness*/ 0.2, /*edge thickness*/ 2.1, /*min diameter tolerance*/ -0.07,
		/*back focal length*/ 69.57, /*radius first surface*/ 72.862, /*radius second surface*/ -72.862, /*price*/ 55.0, /*coating*/ "ARB2-VIS",
		/*min wavelength*/ 450.0, /*max wavelength*/ 700.0);

	// price -> on request
	mQ_G311333000.buildLensTwoSurfaces_Qioptiq_lenses(/*lens catalog*/ "Qioptiq", /*catalog number*/ "G311333000", /*diameter*/ 31.5,
		/*focallength*/ 100.0, /*tolerance focal length*/ 2.0, /*material*/ glasses.getNBK7_S1(), /*optical centering accurancy*/ 0.0,
		/*surface quality*/ "3x0.25", /*thickness*/ 4.8, /*tolerance center thickness*/ 0.2, /*edge thickness*/ 2.4, /*min diameter tolerance*/ -0.07,
		/*back focal length*/ 98.41, /*radius first surface*/ 102.92, /*radius second surface*/ -102.92, /*price*/ 99999.0, /*coating*/ "ARB2-VIS",
		/*min wavelength*/ 450.0, /*max wavelength*/ 700.0);

	mQ_G311335000.buildLensTwoSurfaces_Qioptiq_lenses(/*lens catalog*/ "Qioptiq", /*catalog number*/ "G311335000", /*diameter*/ 31.5,
		/*focallength*/ 130.0, /*tolerance focal length*/ 2.0, /*material*/ glasses.getNBK7_S1(), /*optical centering accurancy*/ 0.0,
		/*surface quality*/ "3x0.25", /*thickness*/ 4.0, /*tolerance center thickness*/ 0.2, /*edge thickness*/ 2.2, /*min diameter tolerance*/ -0.07,
		/*back focal length*/ 129.3, /*radius first surface*/ 134.325, /*radius second surface*/ -134.325, /*price*/ 55.0, /*coating*/ "ARB2-VIS",
		/*min wavelength*/ 450.0, /*max wavelength*/ 700.0);

	// no zemax file available
	// price -> on request
	mQ_G311347000.buildLensTwoSurfaces_Qioptiq_lenses(/*lens catalog*/ "Qioptiq", /*catalog number*/ "G311347000", /*diameter*/ 40.0,
		/*focallength*/ 250.0, /*tolerance focal length*/ 2.0, /*material*/ glasses.getNBK7_S1(), /*optical centering accurancy*/ 0.0,
		/*surface quality*/ "5x0.25", /*thickness*/ 3.5, /*tolerance center thickness*/ 0.2, /*edge thickness*/ 2.0, /*min diameter tolerance*/ -0.07,
		/*back focal length*/ 251.35, /*radius first surface*/ 260.39, /*radius second surface*/ -260.39, /*price*/ 9999.0, /*coating*/ "ARB2-VIS",
		/*min wavelength*/ 450.0, /*max wavelength*/ 700.0);

	// no zemax file available
	// price -> on request
	mQ_G311348000.buildLensTwoSurfaces_Qioptiq_lenses(/*lens catalog*/ "Qioptiq", /*catalog number*/ "G311348000", /*diameter*/ 40.0,
		/*focallength*/ 300.0, /*tolerance focal length*/ 2.0, /*material*/ glasses.getNBK7_S1(), /*optical centering accurancy*/ 0.0,
		/*surface quality*/ "5x0.16", /*thickness*/ 3.3, /*tolerance center thickness*/ 0.2, /*edge thickness*/ 2.0, /*min diameter tolerance*/ -0.07,
		/*back focal length*/ 305.4, /*radius first surface*/ 316.23, /*radius second surface*/ -316.23, /*price*/ 9999.0, /*coating*/ "ARB2-VIS",
		/*min wavelength*/ 450.0, /*max wavelength*/ 700.0);

	// no zemax file available
	mQ_G311341000.buildLensTwoSurfaces_Qioptiq_lenses(/*lens catalog*/ "Qioptiq", /*catalog number*/ "G311341000", /*diameter*/ 40.0,
		/*focallength*/ 65.0, /*tolerance focal length*/ 2.0, /*material*/ glasses.getNBK7_S1(), /*optical centering accurancy*/ 0.0,
		/*surface quality*/ "5x0.25", /*thickness*/ 8.0, /*tolerance center thickness*/ 0.2, /*edge thickness*/ 1.9, /*min diameter tolerance*/ -0.07,
		/*back focal length*/ 63.78, /*radius first surface*/ 67.317, /*radius second surface*/ -67.317, /*price*/ 72.0, /*coating*/ "ARB2-VIS",
		/*min wavelength*/ 450.0, /*max wavelength*/ 700.0);

	// no zemax file available
	// price -> on request
	mQ_G311345000.buildLensTwoSurfaces_Qioptiq_lenses(/*lens catalog*/ "Qioptiq", /*catalog number*/ "G311345000", /*diameter*/ 40.0,
		/*focallength*/ 150.0, /*tolerance focal length*/ 2.0, /*material*/ glasses.getNBK7_S1(), /*optical centering accurancy*/ 0.0,
		/*surface quality*/ "5x0.25", /*thickness*/ 4.5, /*tolerance center thickness*/ 0.2, /*edge thickness*/ 1.9, /*min diameter tolerance*/ -0.07,
		/*back focal length*/ 150.4, /*radius first surface*/ 156.22, /*radius second surface*/ -156.22, /*price*/ 99999.0, /*coating*/ "ARB2-VIS",
		/*min wavelength*/ 450.0, /*max wavelength*/ 700.0);

	// no zemax file available
	mQ_G311346000.buildLensTwoSurfaces_Qioptiq_lenses(/*lens catalog*/ "Qioptiq", /*catalog number*/ "G311346000", /*diameter*/ 40.0,
		/*focallength*/ 200.0, /*tolerance focal length*/ 2.0, /*material*/ glasses.getNBK7_S1(), /*optical centering accurancy*/ 0.0,
		/*surface quality*/ "5x0.25", /*thickness*/ 4.0, /*tolerance center thickness*/ 0.2, /*edge thickness*/ 2.1, /*min diameter tolerance*/ -0.07,
		/*back focal length*/ 202.35, /*radius first surface*/ 209.83, /*radius second surface*/ -209.83, /*price*/ 72.0, /*coating*/ "ARB2-VIS",
		/*min wavelength*/ 450.0, /*max wavelength*/ 700.0);


}

std::vector<LensesTwoSurfaces> QioptiqLensCatalog::getAll_Symmetric_convex_lenses_unmounted_ARB2_VIS()
{
	// https://www.qioptiq-shop.com/en/Precision-Optics/Singlets/Symmetric-Convex-Lenses/Symmetric-convex-lenses-unmounted.html

	std::vector<LensesTwoSurfaces> return_Qioptiq_Symmetric_convex_lenses_unmounted_ARB2_VIS;
	return_Qioptiq_Symmetric_convex_lenses_unmounted_ARB2_VIS.push_back(mQ_G311328000);
	return_Qioptiq_Symmetric_convex_lenses_unmounted_ARB2_VIS.push_back(mQ_G311329000);
	return_Qioptiq_Symmetric_convex_lenses_unmounted_ARB2_VIS.push_back(mQ_G311300000);
	return_Qioptiq_Symmetric_convex_lenses_unmounted_ARB2_VIS.push_back(mQ_G311377000);
	return_Qioptiq_Symmetric_convex_lenses_unmounted_ARB2_VIS.push_back(mQ_G311381000);
	return_Qioptiq_Symmetric_convex_lenses_unmounted_ARB2_VIS.push_back(mQ_G311382000);
	return_Qioptiq_Symmetric_convex_lenses_unmounted_ARB2_VIS.push_back(mQ_G311383000);
	return_Qioptiq_Symmetric_convex_lenses_unmounted_ARB2_VIS.push_back(mQ_G311384000);
	return_Qioptiq_Symmetric_convex_lenses_unmounted_ARB2_VIS.push_back(mQ_G311385000);
	return_Qioptiq_Symmetric_convex_lenses_unmounted_ARB2_VIS.push_back(mQ_G311386000);
	return_Qioptiq_Symmetric_convex_lenses_unmounted_ARB2_VIS.push_back(mQ_G311387000);
	return_Qioptiq_Symmetric_convex_lenses_unmounted_ARB2_VIS.push_back(mQ_G311378000);
	return_Qioptiq_Symmetric_convex_lenses_unmounted_ARB2_VIS.push_back(mQ_G311338000);
	return_Qioptiq_Symmetric_convex_lenses_unmounted_ARB2_VIS.push_back(mQ_G311308000);
	return_Qioptiq_Symmetric_convex_lenses_unmounted_ARB2_VIS.push_back(mQ_G311310000);
	return_Qioptiq_Symmetric_convex_lenses_unmounted_ARB2_VIS.push_back(mQ_G311314000);
	return_Qioptiq_Symmetric_convex_lenses_unmounted_ARB2_VIS.push_back(mQ_G311315000);
	return_Qioptiq_Symmetric_convex_lenses_unmounted_ARB2_VIS.push_back(mQ_G311316000);
	return_Qioptiq_Symmetric_convex_lenses_unmounted_ARB2_VIS.push_back(mQ_G311317000);
	return_Qioptiq_Symmetric_convex_lenses_unmounted_ARB2_VIS.push_back(mQ_G311318000);
	return_Qioptiq_Symmetric_convex_lenses_unmounted_ARB2_VIS.push_back(mQ_G311319000);
	return_Qioptiq_Symmetric_convex_lenses_unmounted_ARB2_VIS.push_back(mQ_G311320000);
	return_Qioptiq_Symmetric_convex_lenses_unmounted_ARB2_VIS.push_back(mQ_G311321000);
	return_Qioptiq_Symmetric_convex_lenses_unmounted_ARB2_VIS.push_back(mQ_G311322000);
	return_Qioptiq_Symmetric_convex_lenses_unmounted_ARB2_VIS.push_back(mQ_G311323000);
	return_Qioptiq_Symmetric_convex_lenses_unmounted_ARB2_VIS.push_back(mQ_G311324000);
	return_Qioptiq_Symmetric_convex_lenses_unmounted_ARB2_VIS.push_back(mQ_G311325000);
	return_Qioptiq_Symmetric_convex_lenses_unmounted_ARB2_VIS.push_back(mQ_G311331000);
	return_Qioptiq_Symmetric_convex_lenses_unmounted_ARB2_VIS.push_back(mQ_G311339000);
	return_Qioptiq_Symmetric_convex_lenses_unmounted_ARB2_VIS.push_back(mQ_G311351000);
	return_Qioptiq_Symmetric_convex_lenses_unmounted_ARB2_VIS.push_back(mQ_G311357000);
	return_Qioptiq_Symmetric_convex_lenses_unmounted_ARB2_VIS.push_back(mQ_G311333000);
	return_Qioptiq_Symmetric_convex_lenses_unmounted_ARB2_VIS.push_back(mQ_G311335000);
	return_Qioptiq_Symmetric_convex_lenses_unmounted_ARB2_VIS.push_back(mQ_G311347000);
	return_Qioptiq_Symmetric_convex_lenses_unmounted_ARB2_VIS.push_back(mQ_G311348000);
	return_Qioptiq_Symmetric_convex_lenses_unmounted_ARB2_VIS.push_back(mQ_G311341000);
	return_Qioptiq_Symmetric_convex_lenses_unmounted_ARB2_VIS.push_back(mQ_G311345000);
	return_Qioptiq_Symmetric_convex_lenses_unmounted_ARB2_VIS.push_back(mQ_G311346000);

	return return_Qioptiq_Symmetric_convex_lenses_unmounted_ARB2_VIS;
}
// ***

// *** Plano - concave lenses, unmounted (N - BK7), ARB2 VIS
void QioptiqLensCatalog::loadLensCatalogQioptiq_Plano_concave_lenses_unmounted_N_BK7_ARB2_VIS()
{
	glass glasses;
	glasses.loadGlassCatalog_Schott();

	// https://www.qioptiq-shop.com/en/Precision-Optics/Singlets/Plano-Concave-Lenses/Plano-concave-lenses-unmounted-N-BK7.html

	mQ_G314001000.buildLensTwoSurfaces_Qioptiq_oneSurfacePlan(/*lens catalog*/ "Qioptiq", /*catalog number*/ "G314001000", /*diameter*/ 6.0,
		/*focallength*/ -6.0, /*tolerance focal length*/ 2.0,	/*material*/ glasses.getNBK7_S1(), /*optical centering accurancy*/10.0,
		/*surface quality*/ "3x0.1", /*thickness*/ 0.5, /*tolerance center thickness*/ 0.02, /*edge thickness*/ 2.82, /*min diameter tolerance*/ -0.02,
		/*back focal length*/ -6.33, /*radius*/ -3.101, /*price*/ 56.00, /*coating*/ "ARB2-VIS", /*min wavelength*/ 450.0, /*max wavelength*/ 700.0);

	mQ_G314304000.buildLensTwoSurfaces_Qioptiq_oneSurfacePlan(/*lens catalog*/ "Qioptiq", /*catalog number*/ "G314304000", /*diameter*/ 6.0,
		/*focallength*/ -10.0, /*tolerance focal length*/ 2.0,	/*material*/ glasses.getNBK7_S1(), /*optical centering accurancy*/10.0,
		/*surface quality*/ "3x0.1", /*thickness*/ 1.0, /*tolerance center thickness*/ 0.01, /*edge thickness*/ 2.0, /*min diameter tolerance*/ -0.09,
		/*back focal length*/ -10.36, /*radius*/ -5.012, /*price*/ 53.00, /*coating*/ "ARB2-VIS", /*min wavelength*/ 450.0, /*max wavelength*/ 700.0);

	mQ_G314002000.buildLensTwoSurfaces_Qioptiq_oneSurfacePlan(/*lens catalog*/ "Qioptiq", /*catalog number*/ "G314002000", /*diameter*/ 8.0,
		/*focallength*/ -8.0, /*tolerance focal length*/ 2.0,	/*material*/ glasses.getNBK7_S1(), /*optical centering accurancy*/10.0,
		/*surface quality*/ "3x0.1", /*thickness*/ 1.0, /*tolerance center thickness*/ 0.02, /*edge thickness*/ 4.09, /*min diameter tolerance*/ -0.02,
		/*back focal length*/ -8.66, /*radius*/ -4.134, /*price*/ 68.00, /*coating*/ "ARB2-VIS", /*min wavelength*/ 450.0, /*max wavelength*/ 700.0);

	mQ_G314003000.buildLensTwoSurfaces_Qioptiq_oneSurfacePlan(/*lens catalog*/ "Qioptiq", /*catalog number*/ "G314003000", /*diameter*/ 10.0,
		/*focallength*/ -10.0, /*tolerance focal length*/ 2.0,	/*material*/ glasses.getNBK7_S1(), /*optical centering accurancy*/10.0,
		/*surface quality*/ "3x0.1", /*thickness*/ 1.0, /*tolerance center thickness*/ 0.02, /*edge thickness*/ 4.86, /*min diameter tolerance*/ -0.02,
		/*back focal length*/ -10.66, /*radius*/ -5.168, /*price*/ 51.00, /*coating*/ "ARB2-VIS", /*min wavelength*/ 450.0, /*max wavelength*/ 700.0);

	mQ_G314005000.buildLensTwoSurfaces_Qioptiq_oneSurfacePlan(/*lens catalog*/ "Qioptiq", /*catalog number*/ "G314005000", /*diameter*/10.0,
		/*focallength*/ -16.0, /*tolerance focal length*/ 2.0,	/*material*/ glasses.getNBK7_S1(), /*optical centering accurancy*/10.0,
		/*surface quality*/ "3x0.16", /*thickness*/ 1.5, /*tolerance center thickness*/ 0.2, /*edge thickness*/ 3.1, /*min diameter tolerance*/ -0.09,
		/*back focal length*/ -17.39, /*radius*/ -8.475, /*price*/ 51.00, /*coating*/ "ARB2-VIS", /*min wavelength*/ 450.0, /*max wavelength*/ 700.0);

	mQ_G314331000.buildLensTwoSurfaces_Qioptiq_oneSurfacePlan(/*lens catalog*/ "Qioptiq", /*catalog number*/ "G314331000", /*diameter*/ 12.7,
		/*focallength*/ -30.0, /*tolerance focal length*/ 2.0,	/*material*/ glasses.getNBK7_S1(), /*optical centering accurancy*/10.0,
		/*surface quality*/ "3x0.16", /*thickness*/ 1.5, /*tolerance center thickness*/ 0.01, /*edge thickness*/ 2.9, /*min diameter tolerance*/ -0.12,
		/*back focal length*/ -31.0, /*radius*/ -15.51, /*price*/ 40.00, /*coating*/ "ARB2-VIS", /*min wavelength*/ 450.0, /*max wavelength*/ 700.0);

	mQ_G314332000.buildLensTwoSurfaces_Qioptiq_oneSurfacePlan(/*lens catalog*/ "Qioptiq", /*catalog number*/ "G314332000", /*diameter*/ 12.7,
		/*focallength*/ -50.0, /*tolerance focal length*/ 2.0,	/*material*/ glasses.getNBK7_S1(), /*optical centering accurancy*/10.0,
		/*surface quality*/ "3x0.16", /*thickness*/ 1.5, /*tolerance center thickness*/ 0.01, /*edge thickness*/ 2.3, /*min diameter tolerance*/ -0.12,
		/*back focal length*/ -51.38, /*radius*/ -26.039, /*price*/ 40.00, /*coating*/ "ARB2-VIS", /*min wavelength*/ 450.0, /*max wavelength*/ 700.0);

	mQ_G314333000.buildLensTwoSurfaces_Qioptiq_oneSurfacePlan(/*lens catalog*/ "Qioptiq", /*catalog number*/ "G314333000", /*diameter*/ 12.7,
		/*focallength*/ -100.0, /*tolerance focal length*/ 2.0,	/*material*/ glasses.getNBK7_S1(), /*optical centering accurancy*/10.0,
		/*surface quality*/ "3x0.16", /*thickness*/ 1.5, /*tolerance center thickness*/ 0.01, /*edge thickness*/ 1.9, /*min diameter tolerance*/ -0.12,
		/*back focal length*/ -100.99, /*radius*/ -51.212, /*price*/ 40.00, /*coating*/ "ARB2-VIS", /*min wavelength*/ 450.0, /*max wavelength*/ 700.0);

	mQ_G314334000.buildLensTwoSurfaces_Qioptiq_oneSurfacePlan(/*lens catalog*/ "Qioptiq", /*catalog number*/ "G314334000", /*diameter*/ 12.7,
		/*focallength*/ -200.0, /*tolerance focal length*/ 2.0,	/*material*/ glasses.getNBK7_S1(), /*optical centering accurancy*/10.0,
		/*surface quality*/ "3x0.16", /*thickness*/ 1.5, /*tolerance center thickness*/ 0.01, /*edge thickness*/ 1.7, /*min diameter tolerance*/ -0.12,
		/*back focal length*/ -200.15, /*radius*/ -102.92, /*price*/ 40.00, /*coating*/ "ARB2-VIS", /*min wavelength*/ 450.0, /*max wavelength*/ 700.0);

	mQ_G314335000.buildLensTwoSurfaces_Qioptiq_oneSurfacePlan(/*lens catalog*/ "Qioptiq", /*catalog number*/ "G314335000", /*diameter*/ 12.7,
		/*focallength*/ -500.0, /*tolerance focal length*/ 2.0,	/*material*/ glasses.getNBK7_S1(), /*optical centering accurancy*/10.0,
		/*surface quality*/ "3x0.16", /*thickness*/ 1.5, /*tolerance center thickness*/ 0.01, /*edge thickness*/ 1.6, /*min diameter tolerance*/ -0.12,
		/*back focal length*/ -504.88, /*radius*/ -260.39, /*price*/ 40.00, /*coating*/ "ARB2-VIS", /*min wavelength*/ 450.0, /*max wavelength*/ 700.0);

	mQ_G314301000.buildLensTwoSurfaces_Qioptiq_oneSurfacePlan(/*lens catalog*/ "Qioptiq", /*catalog number*/ "G314301000", /*diameter*/ 22.4,
		/*focallength*/ -40.0, /*tolerance focal length*/ 2.0,	/*material*/ glasses.getNBK7_S1(), /*optical centering accurancy*/10.0,
		/*surface quality*/ "3x0.25", /*thickness*/ 1.5, /*tolerance center thickness*/ 0.2, /*edge thickness*/ 4.8, /*min diameter tolerance*/ -0.13,
		/*back focal length*/ -41.3, /*radius*/ -20.833, /*price*/ 53.00, /*coating*/ "ARB2-VIS", /*min wavelength*/ 450.0, /*max wavelength*/ 700.0);

	mQ_G314315000.buildLensTwoSurfaces_Qioptiq_oneSurfacePlan(/*lens catalog*/ "Qioptiq", /*catalog number*/ "G314315000", /*diameter*/ 22.4,
		/*focallength*/ -50.0, /*tolerance focal length*/ 2.0,	/*material*/ glasses.getNBK7_S1(), /*optical centering accurancy*/10.0,
		/*surface quality*/ "3x0.25", /*thickness*/ 1.5, /*tolerance center thickness*/ 0.2, /*edge thickness*/ 4.0, /*min diameter tolerance*/ -0.13,
		/*back focal length*/ -51.38, /*radius*/ -26.039, /*price*/ 53.00, /*coating*/ "ARB2-VIS", /*min wavelength*/ 450.0, /*max wavelength*/ 700.0);

	mQ_G314316000.buildLensTwoSurfaces_Qioptiq_oneSurfacePlan(/*lens catalog*/ "Qioptiq", /*catalog number*/ "G314316000", /*diameter*/ 22.4,
		/*focallength*/ -100.0, /*tolerance focal length*/ 2.0,	/*material*/ glasses.getNBK7_S1(), /*optical centering accurancy*/10.0,
		/*surface quality*/ "3x0.25", /*thickness*/ 1.5, /*tolerance center thickness*/ 0.2, /*edge thickness*/ 2.7, /*min diameter tolerance*/ -0.13,
		/*back focal length*/ -102.25, /*radius*/ -52.33, /*price*/ 53.00, /*coating*/ "ARB2-VIS", /*min wavelength*/ 450.0, /*max wavelength*/ 700.0);

	mQ_G314317000.buildLensTwoSurfaces_Qioptiq_oneSurfacePlan(/*lens catalog*/ "Qioptiq", /*catalog number*/ "G314317000", /*diameter*/ 22.4,
		/*focallength*/ -150.0, /*tolerance focal length*/ 2.0,	/*material*/ glasses.getNBK7_S1(), /*optical centering accurancy*/10.0,
		/*surface quality*/ "3x0.25", /*thickness*/ 1.5, /*tolerance center thickness*/ 0.2, /*edge thickness*/ 2.3, /*min diameter tolerance*/ -0.13,
		/*back focal length*/ -152.5, /*radius*/ -78.298, /*price*/ 53.00, /*coating*/ "ARB2-VIS", /*min wavelength*/ 450.0, /*max wavelength*/ 700.0);

	mQ_G314321000.buildLensTwoSurfaces_Qioptiq_oneSurfacePlan(/*lens catalog*/ "Qioptiq", /*catalog number*/ "G314321000", /*diameter*/ 25.4,
		/*focallength*/ -50.0, /*tolerance focal length*/ 2.0,	/*material*/ glasses.getNBK7_S1(), /*optical centering accurancy*/10.0,
		/*surface quality*/ "3x0.25", /*thickness*/ 1.5, /*tolerance center thickness*/ 0.2, /*edge thickness*/ 4.8, /*min diameter tolerance*/ -0.15,
		/*back focal length*/ -51.38, /*radius*/ -26.039, /*price*/ 58.00, /*coating*/ "ARB2-VIS", /*min wavelength*/ 450.0, /*max wavelength*/ 700.0);

	mQ_G314322000.buildLensTwoSurfaces_Qioptiq_oneSurfacePlan(/*lens catalog*/ "Qioptiq", /*catalog number*/ "G314322000", /*diameter*/ 25.4,
		/*focallength*/ -100.0, /*tolerance focal length*/ 2.0,	/*material*/ glasses.getNBK7_S1(), /*optical centering accurancy*/10.0,
		/*surface quality*/ "3x0.25", /*thickness*/ 1.5, /*tolerance center thickness*/ 0.2, /*edge thickness*/ 3.1, /*min diameter tolerance*/ -0.15,
		/*back focal length*/ -100.09, /*radius*/ -51.212, /*price*/ 58.00, /*coating*/ "ARB2-VIS", /*min wavelength*/ 450.0, /*max wavelength*/ 700.0);

	mQ_G314323000.buildLensTwoSurfaces_Qioptiq_oneSurfacePlan(/*lens catalog*/ "Qioptiq", /*catalog number*/ "G314323000", /*diameter*/ 25.4,
		/*focallength*/ -200.0, /*tolerance focal length*/ 2.0,	/*material*/ glasses.getNBK7_S1(), /*optical centering accurancy*/10.0,
		/*surface quality*/ "3x0.25", /*thickness*/ 1.5, /*tolerance center thickness*/ 0.2, /*edge thickness*/ 2.2, /*min diameter tolerance*/ -0.15,
		/*back focal length*/ -203.03, /*radius*/ -104.41, /*price*/ 58.00, /*coating*/ "ARB2-VIS", /*min wavelength*/ 450.0, /*max wavelength*/ 700.0);

	mQ_G314324000.buildLensTwoSurfaces_Qioptiq_oneSurfacePlan(/*lens catalog*/ "Qioptiq", /*catalog number*/ "G314324000", /*diameter*/ 25.4,
		/*focallength*/ -500.0, /*tolerance focal length*/ 2.0,	/*material*/ glasses.getNBK7_S1(), /*optical centering accurancy*/10.0,
		/*surface quality*/ "3x0.25", /*thickness*/ 1.5, /*tolerance center thickness*/ 0.2, /*edge thickness*/ 1.8, /*min diameter tolerance*/ -0.15,
		/*back focal length*/ -504.86, /*radius*/ -260.39, /*price*/ 58.00, /*coating*/ "ARB2-VIS", /*min wavelength*/ 450.0, /*max wavelength*/ 700.0);


	mQ_G314325000.buildLensTwoSurfaces_Qioptiq_oneSurfacePlan(/*lens catalog*/ "Qioptiq", /*catalog number*/ "G314325000", /*diameter*/ 25.4,
		/*focallength*/ -1000.0, /*tolerance focal length*/ 2.0,	/*material*/ glasses.getNBK7_S1(), /*optical centering accurancy*/10.0,
		/*surface quality*/ "3x0.25", /*thickness*/ 1.5, /*tolerance center thickness*/ 0.2, /*edge thickness*/ 1.7, /*min diameter tolerance*/ -0.15,
		/*back focal length*/ -1013.6, /*radius*/ -523.3, /*price*/ 58.00, /*coating*/ "ARB2-VIS", /*min wavelength*/ 450.0, /*max wavelength*/ 700.0);
}

std::vector<LensesTwoSurfaces> QioptiqLensCatalog::getAll_Plano_concave_lenses_unmounted_N_BK7_ARB2_VIS()
{
	// https://www.qioptiq-shop.com/en/Precision-Optics/Singlets/Plano-Concave-Lenses/Plano-concave-lenses-unmounted-N-BK7.html

	std::vector<LensesTwoSurfaces> return_Qioptiq_Plano_concave_lenses_unmounted_N_BK7_ARB2_VIS;
	return_Qioptiq_Plano_concave_lenses_unmounted_N_BK7_ARB2_VIS.push_back(mQ_G314001000);
	return_Qioptiq_Plano_concave_lenses_unmounted_N_BK7_ARB2_VIS.push_back(mQ_G314304000);
	return_Qioptiq_Plano_concave_lenses_unmounted_N_BK7_ARB2_VIS.push_back(mQ_G314002000);
	return_Qioptiq_Plano_concave_lenses_unmounted_N_BK7_ARB2_VIS.push_back(mQ_G314003000);
	return_Qioptiq_Plano_concave_lenses_unmounted_N_BK7_ARB2_VIS.push_back(mQ_G314005000);
	return_Qioptiq_Plano_concave_lenses_unmounted_N_BK7_ARB2_VIS.push_back(mQ_G314331000);
	return_Qioptiq_Plano_concave_lenses_unmounted_N_BK7_ARB2_VIS.push_back(mQ_G314332000);
	return_Qioptiq_Plano_concave_lenses_unmounted_N_BK7_ARB2_VIS.push_back(mQ_G314333000);
	return_Qioptiq_Plano_concave_lenses_unmounted_N_BK7_ARB2_VIS.push_back(mQ_G314334000);
	return_Qioptiq_Plano_concave_lenses_unmounted_N_BK7_ARB2_VIS.push_back(mQ_G314335000);
	return_Qioptiq_Plano_concave_lenses_unmounted_N_BK7_ARB2_VIS.push_back(mQ_G314301000);
	return_Qioptiq_Plano_concave_lenses_unmounted_N_BK7_ARB2_VIS.push_back(mQ_G314315000);
	return_Qioptiq_Plano_concave_lenses_unmounted_N_BK7_ARB2_VIS.push_back(mQ_G314316000);
	return_Qioptiq_Plano_concave_lenses_unmounted_N_BK7_ARB2_VIS.push_back(mQ_G314317000);
	return_Qioptiq_Plano_concave_lenses_unmounted_N_BK7_ARB2_VIS.push_back(mQ_G314321000);
	return_Qioptiq_Plano_concave_lenses_unmounted_N_BK7_ARB2_VIS.push_back(mQ_G314322000);
	return_Qioptiq_Plano_concave_lenses_unmounted_N_BK7_ARB2_VIS.push_back(mQ_G314323000);
	return_Qioptiq_Plano_concave_lenses_unmounted_N_BK7_ARB2_VIS.push_back(mQ_G314324000);
	return_Qioptiq_Plano_concave_lenses_unmounted_N_BK7_ARB2_VIS.push_back(mQ_G314325000);

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
		/*focallength*/ -10.0, /*tolerance focal length*/ 2.0, /*material*/ glasses.getNBK7_S1(), /*optical centering accurancy*/10.0,
		/*surface quality*/ "3x0.16", /*thickness*/ 1.0, /*tolerance center thickness*/ 0.15, /*edge thickness*/ 3.5, /*min diameter tolerance*/ -0.09,
		/*back focal length*/ -10.48, /*radius first surface*/ -10.669, /*radius second surface*/ 10.669, /*price*/ 46.00, /*coating*/ "ARB2-VIS",
		/*min wavelength*/ 450.0, /*max wavelength*/ 700.0);

	mQ_G313373000.buildLensTwoSurfaces_Qioptiq_lenses(/*lens catalog*/ "Qioptiq", /*catalog number*/ "G313373000", /*diameter*/ 12.7,
		/*focallength*/ -20.0, /*tolerance focal length*/ 2.0, /*material*/ glasses.getNBK7_S1(), /*optical centering accurancy*/10.0,
		/*surface quality*/ "3x0.16", /*thickness*/ 1.5, /*tolerance center thickness*/ 0.1, /*edge thickness*/ 3.5, /*min diameter tolerance*/ -0.12,
		/*back focal length*/ -20.55, /*radius first surface*/ -20.983, /*radius second surface*/ 20.983, /*price*/ 43.00, /*coating*/ "ARB2-VIS",
		/*min wavelength*/ 450.0, /*max wavelength*/ 700.0);

	mQ_G313374000.buildLensTwoSurfaces_Qioptiq_lenses(/*lens catalog*/ "Qioptiq", /*catalog number*/ "G313374000", /*diameter*/ 12.7,
		/*focallength*/ -50.0, /*tolerance focal length*/ 2.0, /*material*/ glasses.getNBK7_S1(), /*optical centering accurancy*/10.0,
		/*surface quality*/ "3x0.16", /*thickness*/ 1.5, /*tolerance center thickness*/ 0.1, /*edge thickness*/ 2.3, /*min diameter tolerance*/ -0.12,
		/*back focal length*/ -50.88, /*radius first surface*/ -52.33, /*radius second surface*/ 52.33, /*price*/ 43.00, /*coating*/ "ARB2-VIS",
		/*min wavelength*/ 450.0, /*max wavelength*/ 700.0);

	mQ_G313375000.buildLensTwoSurfaces_Qioptiq_lenses(/*lens catalog*/ "Qioptiq", /*catalog number*/ "G313375000", /*diameter*/ 12.7,
		/*focallength*/ -100.0, /*tolerance focal length*/ 2.0, /*material*/ glasses.getNBK7_S1(), /*optical centering accurancy*/10.0,
		/*surface quality*/ "3x0.16", /*thickness*/ 1.5, /*tolerance center thickness*/ 0.1, /*edge thickness*/ 1.9, /*min diameter tolerance*/ -0.12,
		/*back focal length*/ -101.3, /*radius first surface*/ -104.41, /*radius second surface*/ 104.41, /*price*/ 43.00, /*coating*/ "ARB2-VIS",
		/*min wavelength*/ 450.0, /*max wavelength*/ 700.0);

	// no zemax file available
	// price -> on request
	mQ_G313376000.buildLensTwoSurfaces_Qioptiq_lenses(/*lens catalog*/ "Qioptiq", /*catalog number*/ "G313376000", /*diameter*/ 12.7,
		/*focallength*/ -200.0, /*tolerance focal length*/ 2.0, /*material*/ glasses.getNBK7_S1(), /*optical centering accurancy*/10.0,
		/*surface quality*/ "3x0.25", /*thickness*/ 1.5, /*tolerance center thickness*/ 0.1, /*edge thickness*/ 1.7, /*min diameter tolerance*/ -0.12,
		/*back focal length*/ -203.3, /*radius first surface*/ -209.83, /*radius second surface*/ 209.83, /*price*/ 99999.00, /*coating*/ "ARB2-VIS",
		/*min wavelength*/ 450.0, /*max wavelength*/ 700.0);

	mQ_G313205000.buildLensTwoSurfaces_Qioptiq_lenses(/*lens catalog*/ "Qioptiq", /*catalog number*/ "G313205000", /*diameter*/ 22.4,
		/*focallength*/ -20.0, /*tolerance focal length*/ 2.0, /*material*/ glasses.getNBK7_S1(), /*optical centering accurancy*/10.0,
		/*surface quality*/ "3x0.25", /*thickness*/ 1.5, /*tolerance center thickness*/ 0.2, /*edge thickness*/ 7.5, /*min diameter tolerance*/ -0.13,
		/*back focal length*/ -20.4, /*radius first surface*/ -20.833, /*radius second surface*/ 20.833, /*price*/ 51.00, /*coating*/ "ARB2-VIS",
		/*min wavelength*/ 450.0, /*max wavelength*/ 700.0);

	mQ_G313206000.buildLensTwoSurfaces_Qioptiq_lenses(/*lens catalog*/ "Qioptiq", /*catalog number*/ "G313206000", /*diameter*/ 22.4,
		/*focallength*/ -30.0, /*tolerance focal length*/ 2.0, /*material*/ glasses.getNBK7_S1(), /*optical centering accurancy*/10.0,
		/*surface quality*/ "3x0.25", /*thickness*/ 1.5, /*tolerance center thickness*/ 0.2, /*edge thickness*/ 5.6, /*min diameter tolerance*/ -0.13,
		/*back focal length*/ -30.62, /*radius first surface*/ -31.396, /*radius second surface*/ 31.396, /*price*/ 51.00, /*coating*/ "ARB2-VIS",
		/*min wavelength*/ 450.0, /*max wavelength*/ 700.0);

	mQ_G313214000.buildLensTwoSurfaces_Qioptiq_lenses(/*lens catalog*/ "Qioptiq", /*catalog number*/ "G313214000", /*diameter*/ 22.4,
		/*focallength*/ -40.0, /*tolerance focal length*/ 2.0, /*material*/ glasses.getNBK7_S1(), /*optical centering accurancy*/10.0,
		/*surface quality*/ "3x0.25", /*thickness*/ 1.5, /*tolerance center thickness*/ 0.2, /*edge thickness*/ 4.5, /*min diameter tolerance*/ -0.13,
		/*back focal length*/ -40.75, /*radius first surface*/ -41.867, /*radius second surface*/ 41.867, /*price*/ 51.00, /*coating*/ "ARB2-VIS",
		/*min wavelength*/ 450.0, /*max wavelength*/ 700.0);

	mQ_G313215000.buildLensTwoSurfaces_Qioptiq_lenses(/*lens catalog*/ "Qioptiq", /*catalog number*/ "G313215000", /*diameter*/ 22.4,
		/*focallength*/ -50.0, /*tolerance focal length*/ 2.0, /*material*/ glasses.getNBK7_S1(), /*optical centering accurancy*/10.0,
		/*surface quality*/ "3x0.25", /*thickness*/ 1.5, /*tolerance center thickness*/ 0.2, /*edge thickness*/ 3.9, /*min diameter tolerance*/ -0.13,
		/*back focal length*/ -50.87, /*radius first surface*/ -52.33, /*radius second surface*/ 52.33, /*price*/ 51.00, /*coating*/ "ARB2-VIS",
		/*min wavelength*/ 450.0, /*max wavelength*/ 700.0);

	mQ_G313216000.buildLensTwoSurfaces_Qioptiq_lenses(/*lens catalog*/ "Qioptiq", /*catalog number*/ "G313216000", /*diameter*/ 22.4,
		/*focallength*/ -100.0, /*tolerance focal length*/ 2.0, /*material*/ glasses.getNBK7_S1(), /*optical centering accurancy*/10.0,
		/*surface quality*/ "3x0.25", /*thickness*/ 1.5, /*tolerance center thickness*/ 0.2, /*edge thickness*/ 2.7, /*min diameter tolerance*/ -0.13,
		/*back focal length*/ -101.26, /*radius first surface*/ -104.41, /*radius second surface*/ 104.41, /*price*/ 51.00, /*coating*/ "ARB2-VIS",
		/*min wavelength*/ 450.0, /*max wavelength*/ 700.0);

	mQ_G313217000.buildLensTwoSurfaces_Qioptiq_lenses(/*lens catalog*/ "Qioptiq", /*catalog number*/ "G313217000", /*diameter*/ 22.4,
		/*focallength*/ -150.0, /*tolerance focal length*/ 2.0, /*material*/ glasses.getNBK7_S1(), /*optical centering accurancy*/10.0,
		/*surface quality*/ "3x0.25", /*thickness*/ 1.5, /*tolerance center thickness*/ 0.2, /*edge thickness*/ 2.3, /*min diameter tolerance*/ -0.13,
		/*back focal length*/ -151.39, /*radius first surface*/ -156.22, /*radius second surface*/ 156.22, /*price*/ 51.00, /*coating*/ "ARB2-VIS",
		/*min wavelength*/ 450.0, /*max wavelength*/ 700.0);

	// no zemax file available
	mQ_G313337000.buildLensTwoSurfaces_Qioptiq_lenses(/*lens catalog*/ "Qioptiq", /*catalog number*/ "G313337000", /*diameter*/ 25.4,
		/*focallength*/ -50.0, /*tolerance focal length*/ 2.0, /*material*/ glasses.getNBK7_S1(), /*optical centering accurancy*/10.0,
		/*surface quality*/ "3x0.25", /*thickness*/ 1.5, /*tolerance center thickness*/ 0.2, /*edge thickness*/ 4.6, /*min diameter tolerance*/ -0.15,
		/*back focal length*/ -50.88, /*radius first surface*/ -52.33, /*radius second surface*/ 52.33, /*price*/ 61.00, /*coating*/ "ARB2-VIS",
		/*min wavelength*/ 450.0, /*max wavelength*/ 700.0);

	// no zemax file available
	mQ_G313339000.buildLensTwoSurfaces_Qioptiq_lenses(/*lens catalog*/ "Qioptiq", /*catalog number*/ "G313339000", /*diameter*/ 25.4,
		/*focallength*/ -200.0, /*tolerance focal length*/ 2.0, /*material*/ glasses.getNBK7_S1(), /*optical centering accurancy*/10.0,
		/*surface quality*/ "5x0.25", /*thickness*/ 1.5, /*tolerance center thickness*/ 0.2, /*edge thickness*/ 2.3, /*min diameter tolerance*/ -0.15,
		/*back focal length*/ -203.3, /*radius first surface*/ -209.83, /*radius second surface*/ 209.83, /*price*/ 16.00, /*coating*/ "ARB2-VIS",
		/*min wavelength*/ 450.0, /*max wavelength*/ 700.0);

	// no zemax file available
	// price -> on request
	mQ_G313249000.buildLensTwoSurfaces_Qioptiq_lenses(/*lens catalog*/ "Qioptiq", /*catalog number*/ "G313249000", /*diameter*/ 40.0,
		/*focallength*/ -500.0, /*tolerance focal length*/ 2.0, /*material*/ glasses.getNBK7_S1(), /*optical centering accurancy*/10.0,
		/*surface quality*/ "3x0.16", /*thickness*/ 2.0, /*tolerance center thickness*/ 0.2, /*edge thickness*/ 2.8, /*min diameter tolerance*/ -0.16,
		/*back focal length*/ -506.62, /*radius first surface*/ -523.3, /*radius second surface*/ 523.3, /*price*/ 99999.00, /*coating*/ "ARB2-VIS",
		/*min wavelength*/ 450.0, /*max wavelength*/ 700.0);
}
std::vector<LensesTwoSurfaces> QioptiqLensCatalog::getAll_Symmetric_concave_lenses_unmounted_N_BK7_ARB2_VIS()
{

	// https://www.qioptiq-shop.com/en/Precision-Optics/Singlets/Symmetric-Concave-Lenses/Symmetric-concave-lenses-unmounted-N-BK7.html

	std::vector<LensesTwoSurfaces> return_Qioptiq_Symmetric_concave_lenses_unmounted_N_BK7_ARB2_VIS;
	return_Qioptiq_Symmetric_concave_lenses_unmounted_N_BK7_ARB2_VIS.push_back(mQ_G313210000);
	return_Qioptiq_Symmetric_concave_lenses_unmounted_N_BK7_ARB2_VIS.push_back(mQ_G313373000);
	return_Qioptiq_Symmetric_concave_lenses_unmounted_N_BK7_ARB2_VIS.push_back(mQ_G313374000);
	return_Qioptiq_Symmetric_concave_lenses_unmounted_N_BK7_ARB2_VIS.push_back(mQ_G313375000);
	return_Qioptiq_Symmetric_concave_lenses_unmounted_N_BK7_ARB2_VIS.push_back(mQ_G313376000);
	return_Qioptiq_Symmetric_concave_lenses_unmounted_N_BK7_ARB2_VIS.push_back(mQ_G313205000);
	return_Qioptiq_Symmetric_concave_lenses_unmounted_N_BK7_ARB2_VIS.push_back(mQ_G313206000);
	return_Qioptiq_Symmetric_concave_lenses_unmounted_N_BK7_ARB2_VIS.push_back(mQ_G313214000);
	return_Qioptiq_Symmetric_concave_lenses_unmounted_N_BK7_ARB2_VIS.push_back(mQ_G313215000);
	return_Qioptiq_Symmetric_concave_lenses_unmounted_N_BK7_ARB2_VIS.push_back(mQ_G313216000);
	return_Qioptiq_Symmetric_concave_lenses_unmounted_N_BK7_ARB2_VIS.push_back(mQ_G313217000);
	return_Qioptiq_Symmetric_concave_lenses_unmounted_N_BK7_ARB2_VIS.push_back(mQ_G313337000);
	return_Qioptiq_Symmetric_concave_lenses_unmounted_N_BK7_ARB2_VIS.push_back(mQ_G313339000);
	return_Qioptiq_Symmetric_concave_lenses_unmounted_N_BK7_ARB2_VIS.push_back(mQ_G313249000);

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
		/*price*/ 90.00);

	mQ_G322219000.buildLensThreeSurfaces_Qioptiq_lenses(/*lenscatalog*/ "Qioptiq", /*catalog number*/"G322219000", /*diameter*/ 3.0,
		/*focallength*/ 5.0, /*optical centering accurancy*/ 3.0, /*surface quality*/ "3x0.1", /*edge thickness*/ 2.6, /*back focal length*/ 3.6,
		/*min wavelength*/450.0, /*max wavelength*/ 700.0, /*coating*/ "ARB2-VIS", /*caoting specification*/ "2xR<0.5%",
		/*radius first surface*/ 3.55, /*radius second surface*/ -2.269, /*radius thrid surface*/ -6.712, /*thickness first*/ 1.935,
		/*thickness second*/ 1.125, /*tolerance center thickness*/ 0.1,/*material first*/glasses.getNSSK8_S1(), /*material second*/ glasses.getNSF56_S1(),
		/*price*/ 90.00);

	mQ_G322250000.buildLensThreeSurfaces_Qioptiq_lenses(/*lenscatalog*/ "Qioptiq", /*catalog number*/"G322250000", /*diameter*/ 3.0,
		/*focallength*/ 6.0, /*optical centering accurancy*/ 4.0, /*surface quality*/ "3x0.1", /*edge thickness*/ 2.2, /*back focal length*/ 4.68,
		/*min wavelength*/450.0, /*max wavelength*/ 700.0, /*coating*/ "ARB2-VIS", /*caoting specification*/ "2xR<0.5%",
		/*radius first surface*/ 4.068, /*radius second surface*/ -2.758, /*radius thrid surface*/ -9.205, /*thickness first*/ 1.7,
		/*thickness second*/ 0.95, /*tolerance center thickness*/ 0.1,/*material first*/glasses.getNSSK8_S1(), /*material second*/ glasses.getNSF56_S1(),
		/*price*/ 110.00);

	mQ_G322220000.buildLensThreeSurfaces_Qioptiq_lenses(/*lenscatalog*/ "Qioptiq", /*catalog number*/"G322220000", /*diameter*/ 6.0,
		/*focallength*/ 8.0, /*optical centering accurancy*/ 3.0, /*surface quality*/ "3x0.1", /*edge thickness*/ 3.7, /*back focal length*/ 5.48,
		/*min wavelength*/450.0, /*max wavelength*/ 700.0, /*coating*/ "ARB2-VIS", /*caoting specification*/ "2xR<0.5%",
		/*radius first surface*/ 5.271, /*radius second surface*/ -3.652, /*radius thrid surface*/ -12.544, /*thickness first*/ 3.2,
		/*thickness second*/ 1.8, /*tolerance center thickness*/ 0.1,/*material first*/glasses.getNSSK8_S1(), /*material second*/ glasses.getNSF56_S1(),
		/*price*/ 118.00);

	mQ_G322206000.buildLensThreeSurfaces_Qioptiq_lenses(/*lenscatalog*/ "Qioptiq", /*catalog number*/"G322206000", /*diameter*/ 6.0,
		/*focallength*/ 10.0, /*optical centering accurancy*/ 4.0, /*surface quality*/ "3x0.1", /*edge thickness*/ 2.1, /*back focal length*/ 8.88,
		/*min wavelength*/450.0, /*max wavelength*/ 700.0, /*coating*/ "ARB2-VIS", /*caoting specification*/ "2xR<0.5%",
		/*radius first surface*/ 7.232, /*radius second surface*/ -5.178, /*radius thrid surface*/ -18.84, /*thickness first*/ 2.2,
		/*thickness second*/ 0.8, /*tolerance center thickness*/ 0.2,/*material first*/glasses.getNSSK8_S1(), /*material second*/ glasses.getNSF4_S1(),
		/*price*/ 83.00);

	mQ_G322222000.buildLensThreeSurfaces_Qioptiq_lenses(/*lenscatalog*/ "Qioptiq", /*catalog number*/"G322222000", /*diameter*/ 6.0,
		/*focallength*/ 13.0, /*optical centering accurancy*/ 3.0, /*surface quality*/ "3x0.1", /*edge thickness*/ 4.1, /*back focal length*/ 10.53,
		/*min wavelength*/450.0, /*max wavelength*/ 700.0, /*coating*/ "ARB2-VIS", /*caoting specification*/ "2xR<0.5%",
		/*radius first surface*/ 8.536, /*radius second surface*/ -6.471, /*radius thrid surface*/ -23.886, /*thickness first*/ 3.2,
		/*thickness second*/ 1.65, /*tolerance center thickness*/ 0.1,/*material first*/glasses.getNSSK8_S1(), /*material second*/ glasses.getNSF56_S1(),
		/*price*/ 90.00);

	mQ_G322223000.buildLensThreeSurfaces_Qioptiq_lenses(/*lenscatalog*/ "Qioptiq", /*catalog number*/"G322223000", /*diameter*/ 6.0,
		/*focallength*/ 18.0, /*optical centering accurancy*/ 3.0, /*surface quality*/ "3x0.1", /*edge thickness*/ 3.2, /*back focal length*/ 16.07,
		/*min wavelength*/450.0, /*max wavelength*/ 700.0, /*coating*/ "ARB2-VIS", /*caoting specification*/ "2xR<0.5%",
		/*radius first surface*/ 11.757, /*radius second surface*/ -9.577, /*radius thrid surface*/ -34.477, /*thickness first*/ 2.7,
		/*thickness second*/ 1.0, /*tolerance center thickness*/ 0.1,/*material first*/glasses.getNSSK8_S1(), /*material second*/ glasses.getNSF56_S1(),
		/*price*/ 95.00);

	mQ_G322207000.buildLensThreeSurfaces_Qioptiq_lenses(/*lenscatalog*/ "Qioptiq", /*catalog number*/"G322207000", /*diameter*/ 8.0,
		/*focallength*/ 16.0, /*optical centering accurancy*/ 4.0, /*surface quality*/ "3x0.16", /*edge thickness*/ 2.4, /*back focal length*/ 14.53,
		/*min wavelength*/450.0, /*max wavelength*/ 700.0, /*coating*/ "ARB2-VIS", /*caoting specification*/ "2xR<0.5%",
		/*radius first surface*/ 10.864, /*radius second surface*/ -8.245, /*radius thrid surface*/ -34.441, /*thickness first*/ 2.5,
		/*thickness second*/ 0.95, /*tolerance center thickness*/ 0.2,/*material first*/glasses.getNSSK8_S1(), /*material second*/ glasses.getNSF4_S1(),
		/*price*/ 83.00);

	mQ_G322356322.buildLensThreeSurfaces_Qioptiq_lenses(/*lenscatalog*/ "Qioptiq", /*catalog number*/"G322356322", /*diameter*/ 8.0,
		/*focallength*/ 25.0, /*optical centering accurancy*/ 3.0, /*surface quality*/ "3x0.1", /*edge thickness*/ 3.4, /*back focal length*/ 22.88,
		/*min wavelength*/450.0, /*max wavelength*/ 700.0, /*coating*/ "ARB2-VIS", /*caoting specification*/ "2xR<0.5%",
		/*radius first surface*/ 15.0695, /*radius second surface*/ -10.941, /*radius thrid surface*/ -32.4335, /*thickness first*/ 3.0,
		/*thickness second*/ 1.2, /*tolerance center thickness*/ 0.2,/*material first*/glasses.getNBK7_S1(), /*material second*/ glasses.getNSF5_S1(),
		/*price*/ 83.00);

	mQ_G322357322.buildLensThreeSurfaces_Qioptiq_lenses(/*lenscatalog*/ "Qioptiq", /*catalog number*/"G322357322", /*diameter*/ 8.0,
		/*focallength*/ 30.0, /*optical centering accurancy*/ 3.0, /*surface quality*/ "3x0.1", /*edge thickness*/ 3.5, /*back focal length*/ 27.86,
		/*min wavelength*/450.0, /*max wavelength*/ 700.0, /*coating*/ "ARB2-VIS", /*caoting specification*/ "2xR<0.5%",
		/*radius first surface*/ 18.0412, /*radius second surface*/ -13.2389, /*radius thrid surface*/ -39.5253, /*thickness first*/ 3.0,
		/*thickness second*/ 1.2, /*tolerance center thickness*/ 0.2,/*material first*/glasses.getNBK7_S1(), /*material second*/ glasses.getNSF5_S1(),
		/*price*/ 83.00);

	mQ_G322358322.buildLensThreeSurfaces_Qioptiq_lenses(/*lenscatalog*/ "Qioptiq", /*catalog number*/"G322358322", /*diameter*/ 8.0,
		/*focallength*/ 35.0, /*optical centering accurancy*/ 3.0, /*surface quality*/ "3x0.1", /*edge thickness*/ 3.6, /*back focal length*/ 32.88,
		/*min wavelength*/450.0, /*max wavelength*/ 700.0, /*coating*/ "ARB2-VIS", /*caoting specification*/ "2xR<0.5%",
		/*radius first surface*/ 21.0586, /*radius second surface*/ -15.3478, /*radius thrid surface*/ -46.1474, /*thickness first*/ 3.0,
		/*thickness second*/ 1.2, /*tolerance center thickness*/ 0.2,/*material first*/glasses.getNBK7_S1(), /*material second*/ glasses.getNSF5_S1(),
		/*price*/ 97.00);

	mQ_G322359322.buildLensThreeSurfaces_Qioptiq_lenses(/*lenscatalog*/ "Qioptiq", /*catalog number*/"G322359322", /*diameter*/ 8.0,
		/*focallength*/ 40.0, /*optical centering accurancy*/ 3.0, /*surface quality*/ "3x0.1", /*edge thickness*/ 3.7, /*back focal length*/ 37.88,
		/*min wavelength*/450.0, /*max wavelength*/ 700.0, /*coating*/ "ARB2-VIS", /*caoting specification*/ "2xR<0.5%",
		/*radius first surface*/ 24.0604, /*radius second surface*/ -17.5303, /*radius thrid surface*/ -52.905, /*thickness first*/ 1.645,
		/*thickness second*/ 0.75, /*tolerance center thickness*/ 0.2,/*material first*/glasses.getNBK7_S1(), /*material second*/ glasses.getNSF5_S1(),
		/*price*/ 83.00);

	mQ_G322360322.buildLensThreeSurfaces_Qioptiq_lenses(/*lenscatalog*/ "Qioptiq", /*catalog number*/"G322360322", /*diameter*/ 8.0,
		/*focallength*/ 45.0, /*optical centering accurancy*/ 3.0, /*surface quality*/ "3x0.1", /*edge thickness*/ 3.9, /*back focal length*/ 42.86,
		/*min wavelength*/450.0, /*max wavelength*/ 700.0, /*coating*/ "ARB2-VIS", /*caoting specification*/ "2xR<0.5%",
		/*radius first surface*/ 27.194, /*radius second surface*/ -19.8086, /*radius thrid surface*/ -59.3521, /*thickness first*/ 3.0,
		/*thickness second*/ 1.3, /*tolerance center thickness*/ 0.2,/*material first*/glasses.getNBK7_S1(), /*material second*/ glasses.getNSF5_S1(),
		/*price*/ 97.00);

	//// no zemax file
	//// no radius, no thickness, no glasses
	//mQ_G322361322.buildLensThreeSurfaces_Qioptiq_lenses(/*lenscatalog*/ "Qioptiq", /*catalog number*/"G322361322", /*diameter*/ 8.0,
	//	/*focallength*/ 50.0, /*optical centering accurancy*/ 3.0, /*surface quality*/ "3x0.1", /*edge thickness*/ 3.9, /*back focal length*/ 47.85,
	//	/*min wavelength*/450.0, /*max wavelength*/ 700.0, /*coating*/ "ARB2-VIS", /*caoting specification*/ "2xR<0.5%",
	//	/*radius first surface*/ 999999.0, /*radius second surface*/ -999999.0, /*radius thrid surface*/ -999999.0, /*thickness first*/ 0.0,
	//	/*thickness second*/0.0, /*tolerance center thickness*/ 0.2,/*material first*/glasses.getNBK7_S1(), /*material second*/ glasses.getNSF5_S1(),
	//	/*price*/ 103.00);

	mQ_G322362322.buildLensThreeSurfaces_Qioptiq_lenses(/*lenscatalog*/ "Qioptiq", /*catalog number*/"G322362322", /*diameter*/ 8.0,
		/*focallength*/ 60.0, /*optical centering accurancy*/ 3.0, /*surface quality*/ "3x0.1", /*edge thickness*/ 4.1, /*back focal length*/ 57.8,
		/*min wavelength*/450.0, /*max wavelength*/ 700.0, /*coating*/ "ARB2-VIS", /*caoting specification*/ "2xR<0.5%",
		/*radius first surface*/ 36.26, /*radius second surface*/ -26.8005, /*radius thrid surface*/ -80.2972, /*thickness first*/ 3.0,
		/*thickness second*/ 1.4, /*tolerance center thickness*/ 0.2,/*material first*/glasses.getNBK7_S1(), /*material second*/ glasses.getNSF5_S1(),
		/*price*/ 97.00);

	mQ_G322363322.buildLensThreeSurfaces_Qioptiq_lenses(/*lenscatalog*/ "Qioptiq", /*catalog number*/"G322363322", /*diameter*/ 8.0,
		/*focallength*/ 80.0, /*optical centering accurancy*/ 3.0, /*surface quality*/ "3x0.1", /*edge thickness*/ 4.2, /*back focal length*/ 77.84,
		/*min wavelength*/450.0, /*max wavelength*/ 700.0, /*coating*/ "ARB2-VIS", /*caoting specification*/ "2xR<0.5%",
		/*radius first surface*/ 48.356, /*radius second surface*/ -35.4811, /*radius thrid surface*/ -107.075, /*thickness first*/ 3.0,
		/*thickness second*/ 1.4, /*tolerance center thickness*/ 0.2,/*material first*/glasses.getNBK7_S1(), /*material second*/ glasses.getNSF5_S1(),
		/*price*/ 97.00);

	mQ_G322364322.buildLensThreeSurfaces_Qioptiq_lenses(/*lenscatalog*/ "Qioptiq", /*catalog number*/"G322364322", /*diameter*/ 8.0,
		/*focallength*/ 100.0, /*optical centering accurancy*/ 3.0, /*surface quality*/ "3x0.1", /*edge thickness*/ 4.3, /*back focal length*/ 97.73,
		/*min wavelength*/450.0, /*max wavelength*/ 700.0, /*coating*/ "ARB2-VIS", /*caoting specification*/ "2xR<0.5%",
		/*radius first surface*/ 60.4372, /*radius second surface*/ -44.5139, /*radius thrid surface*/ -134.3201, /*thickness first*/ 3.0,
		/*thickness second*/ 1.5, /*tolerance center thickness*/ 0.2,/*material first*/glasses.getNBK7_S1(), /*material second*/ glasses.getNSF5_S1(),
		/*price*/ 97.00);

	//// no zemax file
	//// no radius, no thickness, no glasses
	//mQ_G322365322.buildLensThreeSurfaces_Qioptiq_lenses(/*lenscatalog*/ "Qioptiq", /*catalog number*/"G322365322", /*diameter*/ 8.0,
	//	/*focallength*/ 120.0, /*optical centering accurancy*/ 3.0, /*surface quality*/ "3x0.1", /*edge thickness*/ 4.3, /*back focal length*/ 117.75,
	//	/*min wavelength*/450.0, /*max wavelength*/ 700.0, /*coating*/ "ARB2-VIS", /*caoting specification*/ "2xR<0.5%",
	//	/*radius first surface*/ 99999.0, /*radius second surface*/ -9999999.0, /*radius thrid surface*/ -999999.0, /*thickness first*/ 0.0,
	//	/*thickness second*/ 0.0, /*tolerance center thickness*/ 0.2,/*material first*/glasses.getNBK7_S1(), /*material second*/ glasses.getNSF5_S1(),
	//	/*price*/ 97.00);

	mQ_G322366322.buildLensThreeSurfaces_Qioptiq_lenses(/*lenscatalog*/ "Qioptiq", /*catalog number*/"G322366322", /*diameter*/ 8.0,
		/*focallength*/ 150.0, /*optical centering accurancy*/ 3.0, /*surface quality*/ "3x0.1", /*edge thickness*/ 4.4, /*back focal length*/ 147.75,
		/*min wavelength*/450.0, /*max wavelength*/ 700.0, /*coating*/ "ARB2-VIS", /*caoting specification*/ "2xR<0.5%",
		/*radius first surface*/ 90.7431, /*radius second surface*/ -67.318, /*radius thrid surface*/ -203.162, /*thickness first*/ 3.0,
		/*thickness second*/ 1.5, /*tolerance center thickness*/ 0.2,/*material first*/glasses.getNBK7_S1(), /*material second*/ glasses.getNSF5_S1(),
		/*price*/ 103.00);

	mQ_G322367322.buildLensThreeSurfaces_Qioptiq_lenses(/*lenscatalog*/ "Qioptiq", /*catalog number*/"G322367322", /*diameter*/ 8.0,
		/*focallength*/ 200.0, /*optical centering accurancy*/ 3.0, /*surface quality*/ "3x0.1", /*edge thickness*/ 4.6, /*back focal length*/ 197.49,
		/*min wavelength*/450.0, /*max wavelength*/ 700.0, /*coating*/ "ARB2-VIS", /*caoting specification*/ "2xR<0.5%",
		/*radius first surface*/ 120.576, /*radius second surface*/ -90.421, /*radius thrid surface*/ -273.842, /*thickness first*/ 3.0,
		/*thickness second*/ 1.7, /*tolerance center thickness*/ 0.2,/*material first*/glasses.getNBK7_S1(), /*material second*/ glasses.getNSF5_S1(),
		/*price*/ 117.00);

	mQ_G322368322.buildLensThreeSurfaces_Qioptiq_lenses(/*lenscatalog*/ "Qioptiq", /*catalog number*/"G322368322", /*diameter*/ 8.0,
		/*focallength*/ 300.0, /*optical centering accurancy*/ 3.0, /*surface quality*/ "3x0.1", /*edge thickness*/ 4.6, /*back focal length*/ 297.61,
		/*min wavelength*/450.0, /*max wavelength*/ 700.0, /*coating*/ "ARB2-VIS", /*caoting specification*/ "2xR<0.5%",
		/*radius first surface*/ 181.082, /*radius second surface*/ -136.271, /*radius thrid surface*/ -412.699, /*thickness first*/ 3.0,
		/*thickness second*/ 1.7, /*tolerance center thickness*/ 0.2,/*material first*/glasses.getNBK7_S1(), /*material second*/ glasses.getNSF5_S1(),
		/*price*/ 127.00);

	mQ_G322201000.buildLensThreeSurfaces_Qioptiq_lenses(/*lenscatalog*/ "Qioptiq", /*catalog number*/"G322201000", /*diameter*/ 10.0,
		/*focallength*/ 20.0, /*optical centering accurancy*/ 4.0, /*surface quality*/ "5x0.16", /*edge thickness*/ 2.8, /*back focal length*/ 18.44,
		/*min wavelength*/450.0, /*max wavelength*/ 700.0, /*coating*/ "ARB2-VIS", /*caoting specification*/ "2xR<0.5%",
		/*radius first surface*/ 13.47, /*radius second surface*/ -10.981, /*radius thrid surface*/ -39.525, /*thickness first*/ 3.1,
		/*thickness second*/ 1.0, /*tolerance center thickness*/ 0.2,/*material first*/glasses.getNSSK8_S1(), /*material second*/ glasses.getNSF6_S1(),
		/*price*/ 85.00);

	mQ_G322284000.buildLensThreeSurfaces_Qioptiq_lenses(/*lenscatalog*/ "Qioptiq", /*catalog number*/"G322284000", /*diameter*/ 12.5,
		/*focallength*/ 25.0, /*optical centering accurancy*/ 4.0, /*surface quality*/ "5x0.16", /*edge thickness*/ 4.0, /*back focal length*/ 22.38,
		/*min wavelength*/450.0, /*max wavelength*/ 700.0, /*coating*/ "ARB2-VIS", /*caoting specification*/ "2xR<0.5%",
		/*radius first surface*/ 16.43, /*radius second surface*/ -12.864, /*radius thrid surface*/ -58.294, /*thickness first*/ 4.0,
		/*thickness second*/ 1.5, /*tolerance center thickness*/ 0.2,/*material first*/glasses.getNSK2_S1(), /*material second*/ glasses.getNSF10_S1(),
		/*price*/ 86.00);

	mQ_G322285000.buildLensThreeSurfaces_Qioptiq_lenses(/*lenscatalog*/ "Qioptiq", /*catalog number*/"G322285000", /*diameter*/ 12.5,
		/*focallength*/ 30.0, /*optical centering accurancy*/ 4.0, /*surface quality*/ "5x0.16", /*edge thickness*/ 3.7, /*back focal length*/ 27.59,
		/*min wavelength*/450.0, /*max wavelength*/ 700.0, /*coating*/ "ARB2-VIS", /*caoting specification*/ "2xR<0.5%",
		/*radius first surface*/ 19.668, /*radius second surface*/ -15.51, /*radius thrid surface*/ -70.287, /*thickness first*/ 3.5,
		/*thickness second*/ 1.5, /*tolerance center thickness*/ 0.2,/*material first*/glasses.getNSK2_S1(), /*material second*/ glasses.getNSF10_S1(),
		/*price*/ 86.00);

	mQ_G322286000.buildLensThreeSurfaces_Qioptiq_lenses(/*lenscatalog*/ "Qioptiq", /*catalog number*/"G322286000", /*diameter*/ 12.5,
		/*focallength*/ 35.0, /*optical centering accurancy*/ 4.0, /*surface quality*/ "5x0.16", /*edge thickness*/ 3.9, /*back focal length*/ 32.39,
		/*min wavelength*/450.0, /*max wavelength*/ 700.0, /*coating*/ "ARB2-VIS", /*caoting specification*/ "2xR<0.5%",
		/*radius first surface*/ 22.712, /*radius second surface*/ -17.529, /*radius thrid surface*/ -81.166, /*thickness first*/ 3.5,
		/*thickness second*/ 1.5, /*tolerance center thickness*/ 0.2,/*material first*/glasses.getNSK2_S1(), /*material second*/ glasses.getNSF10_S1(),
		/*price*/ 86.00);

	mQ_G322337000.buildLensThreeSurfaces_Qioptiq_lenses(/*lenscatalog*/ "Qioptiq", /*catalog number*/"G322337000", /*diameter*/ 12.5,
		/*focallength*/ 40.0, /*optical centering accurancy*/ 3.0, /*surface quality*/ "3x0.16", /*edge thickness*/ 5.1, /*back focal length*/ 37.24,
		/*min wavelength*/450.0, /*max wavelength*/ 700.0, /*coating*/ "ARB2-VIS", /*caoting specification*/ "2xR<0.5%",
		/*radius first surface*/ 25.119, /*radius second surface*/ -17.783, /*radius thrid surface*/ -49.403, /*thickness first*/ 4.0,
		/*thickness second*/ 2.3, /*tolerance center thickness*/ 0.1,/*material first*/glasses.getNBK7_S1(), /*material second*/ glasses.getNSF5_S1(),
		/*price*/ 86.00);

	mQ_G322338000.buildLensThreeSurfaces_Qioptiq_lenses(/*lenscatalog*/ "Qioptiq", /*catalog number*/"G322338000", /*diameter*/ 12.5,
		/*focallength*/ 45.0, /*optical centering accurancy*/ 3.0, /*surface quality*/ "3x0.16", /*edge thickness*/ 4.4, /*back focal length*/ 42.51,
		/*min wavelength*/450.0, /*max wavelength*/ 700.0, /*coating*/ "ARB2-VIS", /*caoting specification*/ "2xR<0.5%",
		/*radius first surface*/ 27.982, /*radius second surface*/ -19.953, /*radius thrid surface*/ -56.64, /*thickness first*/ 3.5,
		/*thickness second*/ 2.0, /*tolerance center thickness*/ 0.1,/*material first*/glasses.getNBK7_S1(), /*material second*/ glasses.getNSF5_S1(),
		/*price*/ 86.00);

	mQ_G322339000.buildLensThreeSurfaces_Qioptiq_lenses(/*lenscatalog*/ "Qioptiq", /*catalog number*/"G322339000", /*diameter*/ 12.5,
		/*focallength*/ 50.0, /*optical centering accurancy*/ 3.0, /*surface quality*/ "3x0.16", /*edge thickness*/ 4.1, /*back focal length*/ 47.65,
		/*min wavelength*/450.0, /*max wavelength*/ 700.0, /*coating*/ "ARB2-VIS", /*caoting specification*/ "2xR<0.5%",
		/*radius first surface*/ 31.059, /*radius second surface*/ -21.909, /*radius thrid surface*/ -62.869, /*thickness first*/ 3.5,
		/*thickness second*/ 1.5, /*tolerance center thickness*/ 0.1,/*material first*/glasses.getNBK7_S1(), /*material second*/ glasses.getNSF5_S1(),
		/*price*/ 86.00);

	mQ_G322341000.buildLensThreeSurfaces_Qioptiq_lenses(/*lenscatalog*/ "Qioptiq", /*catalog number*/"G322341000", /*diameter*/ 12.5,
		/*focallength*/ 60.0, /*optical centering accurancy*/ 3.0, /*surface quality*/ "3x0.16", /*edge thickness*/ 4.5, /*back focal length*/ 57.69,
		/*min wavelength*/450.0, /*max wavelength*/ 700.0, /*coating*/ "ARB2-VIS", /*caoting specification*/ "2xR<0.5%",
		/*radius first surface*/ 37.449, /*radius second surface*/ -26.322, /*radius thrid surface*/ -74.989, /*thickness first*/ 3.0,
		/*thickness second*/ 2.3, /*tolerance center thickness*/ 0.1,/*material first*/glasses.getNBK7_S1(), /*material second*/ glasses.getNSF5_S1(),
		/*price*/ 86.00);

	mQ_G322343000.buildLensThreeSurfaces_Qioptiq_lenses(/*lenscatalog*/ "Qioptiq", /*catalog number*/"G322343000", /*diameter*/ 12.5,
		/*focallength*/ 80.0, /*optical centering accurancy*/ 3.0, /*surface quality*/ "3x0.16", /*edge thickness*/ 5.1, /*back focal length*/ 77.57,
		/*min wavelength*/450.0, /*max wavelength*/ 700.0, /*coating*/ "ARB2-VIS", /*caoting specification*/ "2xR<0.5%",
		/*radius first surface*/ 49.581, /*radius second surface*/ -35.1, /*radius thrid surface*/ -101.45, /*thickness first*/ 3.0,
		/*thickness second*/ 2.5, /*tolerance center thickness*/ 0.1,/*material first*/glasses.getNBK7_S1(), /*material second*/ glasses.getNSF5_S1(),
		/*price*/ 86.00);

	mQ_G322345000.buildLensThreeSurfaces_Qioptiq_lenses(/*lenscatalog*/ "Qioptiq", /*catalog number*/"G322345000", /*diameter*/ 12.5,
		/*focallength*/ 100.0, /*optical centering accurancy*/ 3.0, /*surface quality*/ "3x0.16", /*edge thickness*/ 4.8, /*back focal length*/ 97.81,
		/*min wavelength*/450.0, /*max wavelength*/ 700.0, /*coating*/ "ARB2-VIS", /*caoting specification*/ "2xR<0.5%",
		/*radius first surface*/ 61.971, /*radius second surface*/ -44.03, /*radius thrid surface*/ -127.72, /*thickness first*/ 2.5,
		/*thickness second*/ 2.8, /*tolerance center thickness*/ 0.1,/*material first*/glasses.getNBK7_S1(), /*material second*/ glasses.getNSF5_S1(),
		/*price*/ 86.00);

	mQ_G322320322.buildLensThreeSurfaces_Qioptiq_lenses(/*lenscatalog*/ "Qioptiq", /*catalog number*/"G322320322", /*diameter*/ 12.5,
		/*focallength*/ 120.0, /*optical centering accurancy*/ 3.0, /*surface quality*/ "3x0.16", /*edge thickness*/ 5.4, /*back focal length*/ 117.93,
		/*min wavelength*/450.0, /*max wavelength*/ 700.0, /*coating*/ "ARB2-VIS", /*caoting specification*/ "2xR<0.5%",
		/*radius first surface*/ 73.9202, /*radius second surface*/ -53.2853, /*radius thrid surface*/ -155.663, /*thickness first*/ 3.0,
		/*thickness second*/ 2.8, /*tolerance center thickness*/ 0.1,/*material first*/glasses.getNBK7_S1(), /*material second*/ glasses.getNSF5_S1(),
		/*price*/ 130.00);

	mQ_G322325322.buildLensThreeSurfaces_Qioptiq_lenses(/*lenscatalog*/ "Qioptiq", /*catalog number*/"G322325322", /*diameter*/ 12.5,
		/*focallength*/ 150.0, /*optical centering accurancy*/ 3.0, /*surface quality*/ "3x0.16", /*edge thickness*/ 5.5, /*back focal length*/ 147.42,
		/*min wavelength*/450.0, /*max wavelength*/ 700.0, /*coating*/ "ARB2-VIS", /*caoting specification*/ "2xR<0.5%",
		/*radius first surface*/ 92.0605, /*radius second surface*/ -66.8373, /*radius thrid surface*/ -196.6801, /*thickness first*/ 2.8,
		/*thickness second*/ 3.0, /*tolerance center thickness*/ 0.1,/*material first*/glasses.getNBK7_S1(), /*material second*/ glasses.getNSF5_S1(),
		/*price*/ 140.00);

	mQ_G322327322.buildLensThreeSurfaces_Qioptiq_lenses(/*lenscatalog*/ "Qioptiq", /*catalog number*/"G322327322", /*diameter*/ 12.5,
		/*focallength*/ 200.0, /*optical centering accurancy*/ 3.0, /*surface quality*/ "3x0.16", /*edge thickness*/ 5.3, /*back focal length*/ 197.55,
		/*min wavelength*/450.0, /*max wavelength*/ 700.0, /*coating*/ "ARB2-VIS", /*caoting specification*/ "2xR<0.5%",
		/*radius first surface*/ 122.327, /*radius second surface*/ -89.4473, /*radius thrid surface*/ -265.124, /*thickness first*/ 2.5,
		/*thickness second*/ 3.0, /*tolerance center thickness*/ 0.1,/*material first*/glasses.getNBK7_S1(), /*material second*/ glasses.getNSF5_S1(),
		/*price*/ 160.00);

	//// glasses are not found
	//mQ_G322209000.buildLensThreeSurfaces_Qioptiq_lenses(/*lenscatalog*/ "Qioptiq", /*catalog number*/"G322209000", /*diameter*/ 18.0,
	//	/*focallength*/ 40.0, /*optical centering accurancy*/ 3.0, /*surface quality*/ "5x0.16", /*edge thickness*/ 4.5, /*back focal length*/ 36.04,
	//	/*min wavelength*/450.0, /*max wavelength*/ 700.0, /*coating*/ "ARB2-VIS", /*caoting specification*/ "2xR<0.5%",
	//	/*radius first surface*/ 21.909, /*radius second surface*/ -17.529, /*radius thrid surface*/ -71.821, /*thickness first*/ 5.8,
	//	/*thickness second*/ 1.2, /*tolerance center thickness*/ 0.2,/*material first*/glasses.getSBSL7_S1(), /*material second*/ glasses.getSTIM22_S1(),
	//	/*price*/ 95.00);

	mQ_G322265000.buildLensThreeSurfaces_Qioptiq_lenses(/*lenscatalog*/ "Qioptiq", /*catalog number*/"G322265000", /*diameter*/ 18.0,
		/*focallength*/ 50.0, /*optical centering accurancy*/ 3.0, /*surface quality*/ "5x0.16", /*edge thickness*/ 4.6, /*back focal length*/ 45.95,
		/*min wavelength*/450.0, /*max wavelength*/ 700.0, /*coating*/ "ARB2-VIS", /*caoting specification*/ "2xR<0.5%",
		/*radius first surface*/ 25.483, /*radius second surface*/ -21.909, /*radius thrid surface*/ -139.24, /*thickness first*/ 5.0,
		/*thickness second*/ 1.5, /*tolerance center thickness*/ 0.2,/*material first*/glasses.getNBK7_S1(), /*material second*/ glasses.getNF2_S1(),
		/*price*/ 95.00);

	mQ_G322266000.buildLensThreeSurfaces_Qioptiq_lenses(/*lenscatalog*/ "Qioptiq", /*catalog number*/"G322266000", /*diameter*/ 18.0,
		/*focallength*/ 60.0, /*optical centering accurancy*/ 3.0, /*surface quality*/ "5x0.16", /*edge thickness*/ 4.4, /*back focal length*/ 56.33,
		/*min wavelength*/450.0, /*max wavelength*/ 700.0, /*coating*/ "ARB2-VIS", /*caoting specification*/ "2xR<0.5%",
		/*radius first surface*/ 30.287, /*radius second surface*/ -25.483, /*radius thrid surface*/ -170.31, /*thickness first*/ 4.5,
		/*thickness second*/ 1.5, /*tolerance center thickness*/ 0.2,/*material first*/glasses.getNBK7_S1(), /*material second*/ glasses.getNF2_S1(),
		/*price*/ 95.00);

	mQ_G322210000.buildLensThreeSurfaces_Qioptiq_lenses(/*lenscatalog*/ "Qioptiq", /*catalog number*/"G322210000", /*diameter*/ 18.0,
		/*focallength*/ 80.0, /*optical centering accurancy*/ 3.0, /*surface quality*/ "5x0.16", /*edge thickness*/ 4.6, /*back focal length*/ 76.62,
		/*min wavelength*/450.0, /*max wavelength*/ 700.0, /*coating*/ "ARB2-VIS", /*caoting specification*/ "2xR<0.5%",
		/*radius first surface*/ 41.269, /*radius second surface*/ -34.724, /*radius thrid surface*/ -209.83, /*thickness first*/ 4.0,
		/*thickness second*/ 1.8, /*tolerance center thickness*/ 0.2,/*material first*/glasses.getNBK7_S1(), /*material second*/ glasses.getNF2_S1(),
		/*price*/ 95.00);

	mQ_G322236000.buildLensThreeSurfaces_Qioptiq_lenses(/*lenscatalog*/ "Qioptiq", /*catalog number*/"G322236000", /*diameter*/ 18.0,
		/*focallength*/ 100.0, /*optical centering accurancy*/ 3.0, /*surface quality*/ "5x0.16", /*edge thickness*/ 4.8, /*back focal length*/ 96.43,
		/*min wavelength*/450.0, /*max wavelength*/ 700.0, /*coating*/ "ARB2-VIS", /*caoting specification*/ "2xR<0.5%",
		/*radius first surface*/ 49.403, /*radius second surface*/ -42.474, /*radius thrid surface*/ -316.23, /*thickness first*/ 4.0,
		/*thickness second*/ 1.8, /*tolerance center thickness*/ 0.2,/*material first*/glasses.getNBK7_S1(), /*material second*/ glasses.getNF2_S1(),
		/*price*/ 95.00);

	mQ_G322331322.buildLensThreeSurfaces_Qioptiq_lenses(/*lenscatalog*/ "Qioptiq", /*catalog number*/"G322331322", /*diameter*/ 18.0,
		/*focallength*/ 150.0, /*optical centering accurancy*/ 3.0, /*surface quality*/ "3x0.1", /*edge thickness*/ 5.9, /*back focal length*/ 146.94,
		/*min wavelength*/450.0, /*max wavelength*/ 700.0, /*coating*/ "ARB2-VIS", /*caoting specification*/ "2xR<0.5%",
		/*radius first surface*/ 91.3919, /*radius second surface*/ -67.559, /*radius thrid surface*/ -200.235, /*thickness first*/ 3.5,
		/*thickness second*/ 3.0, /*tolerance center thickness*/ 0.2,/*material first*/glasses.getNBK7_S1(), /*material second*/ glasses.getNSF5_S1(),
		/*price*/ 95.00);

	mQ_G322332322.buildLensThreeSurfaces_Qioptiq_lenses(/*lenscatalog*/ "Qioptiq", /*catalog number*/"G322332322", /*diameter*/ 18.0,
		/*focallength*/ 200.0, /*optical centering accurancy*/ 3.0, /*surface quality*/ "3x0.1", /*edge thickness*/ 6.1, /*back focal length*/ 197.07,
		/*min wavelength*/450.0, /*max wavelength*/ 700.0, /*coating*/ "ARB2-VIS", /*caoting specification*/ "2xR<0.5%",
		/*radius first surface*/ 125.439, /*radius second surface*/ -87.853, /*radius thrid surface*/ -251.18, /*thickness first*/ 3.5,
		/*thickness second*/ 3.0, /*tolerance center thickness*/ 0.2,/*material first*/glasses.getNBK7_S1(), /*material second*/ glasses.getNSF5_S1(),
		/*price*/ 172.00);

	mQ_G322321000.buildLensThreeSurfaces_Qioptiq_lenses(/*lenscatalog*/ "Qioptiq", /*catalog number*/"G322321000", /*diameter*/ 22.4,
		/*focallength*/ 50.0, /*optical centering accurancy*/ 3.0, /*surface quality*/ "3x0.16", /*edge thickness*/ 5.2, /*back focal length*/ 45.76,
		/*min wavelength*/450.0, /*max wavelength*/ 700.0, /*coating*/ "ARB2-VIS", /*caoting specification*/ "2xR<0.5%",
		/*radius first surface*/ 33.018, /*radius second surface*/ -28.184, /*radius thrid surface*/ -177.83, /*thickness first*/ 5.8,
		/*thickness second*/ 1.7, /*tolerance center thickness*/ 0.2,/*material first*/glasses.getNBAF10_S1(), /*material second*/ glasses.getNSF6_S1(),
		/*price*/ 102.00);

	mQ_G322322000.buildLensThreeSurfaces_Qioptiq_lenses(/*lenscatalog*/ "Qioptiq", /*catalog number*/"G322322000", /*diameter*/ 22.4,
		/*focallength*/ 60.0, /*optical centering accurancy*/ 3.0, /*surface quality*/ "3x0.161", /*edge thickness*/ 5.1, /*back focal length*/ 56.74,
		/*min wavelength*/450.0, /*max wavelength*/ 700.0, /*coating*/ "ARB2-VIS", /*caoting specification*/ "2xR<0.5%",
		/*radius first surface*/ 42.474, /*radius second surface*/ -32.546, /*radius thrid surface*/ -160.79, /*thickness first*/ 5.4,
		/*thickness second*/ 1.6, /*tolerance center thickness*/ 0.2,/*material first*/glasses.getNBAF10_S1(), /*material second*/ glasses.getNSF6_S1(),
		/*price*/ 102.00);

	mQ_G322323000.buildLensThreeSurfaces_Qioptiq_lenses(/*lenscatalog*/ "Qioptiq", /*catalog number*/"G322323000", /*diameter*/ 22.4,
		/*focallength*/ 80.0, /*optical centering accurancy*/ 3.0, /*surface quality*/ "3x0.16", /*edge thickness*/ 5.1, /*back focal length*/ 77.05,
		/*min wavelength*/450.0, /*max wavelength*/ 700.0, /*coating*/ "ARB2-VIS", /*caoting specification*/ "2xR<0.5%",
		/*radius first surface*/ 50.481, /*radius second surface*/ -35.481, /*radius thrid surface*/ -100.0, /*thickness first*/ 5.0,
		/*thickness second*/ 2.0, /*tolerance center thickness*/ 0.2,/*material first*/glasses.getNBK7_S1(), /*material second*/ glasses.getNSF5_S1(),
		/*price*/ 102.00);

	mQ_G322324000.buildLensThreeSurfaces_Qioptiq_lenses(/*lenscatalog*/ "Qioptiq", /*catalog number*/"G322324000", /*diameter*/ 22.4,
		/*focallength*/ 100.0, /*optical centering accurancy*/ 3.0, /*surface quality*/ "3x0.16", /*edge thickness*/ 7.5, /*back focal length*/ 95.89,
		/*min wavelength*/450.0, /*max wavelength*/ 700.0, /*coating*/ "ARB2-VIS", /*caoting specification*/ "2xR<0.5%",
		/*radius first surface*/ 61.748, /*radius second surface*/ -44.348, /*radius thrid surface*/ -128.64, /*thickness first*/ 6.25,
		/*thickness second*/ 2.75, /*tolerance center thickness*/ 0.2,/*material first*/glasses.getNBK7_S1(), /*material second*/ glasses.getNSF5_S1(),
		/*price*/ 102.00);

	mQ_G322326000.buildLensThreeSurfaces_Qioptiq_lenses(/*lenscatalog*/ "Qioptiq", /*catalog number*/"G322326000", /*diameter*/ 22.4,
		/*focallength*/ 140.0, /*optical centering accurancy*/ 3.0, /*surface quality*/ "3x0.16", /*edge thickness*/ 6.9, /*back focal length*/ 136.2,
		/*min wavelength*/450.0, /*max wavelength*/ 700.0, /*coating*/ "ARB2-VIS", /*caoting specification*/ "2xR<0.5%",
		/*radius first surface*/ 87.222, /*radius second surface*/ -61.748, /*radius thrid surface*/ -177.83, /*thickness first*/ 6.0,
		/*thickness second*/ 2.0, /*tolerance center thickness*/ 0.2,/*material first*/glasses.getNBK7_S1(), /*material second*/ glasses.getNSF5_S1(),
		/*price*/ 102.00);

	mQ_G322333322.buildLensThreeSurfaces_Qioptiq_lenses(/*lenscatalog*/ "Qioptiq", /*catalog number*/"G322333322", /*diameter*/ 22.4,
		/*focallength*/ 160.0, /*optical centering accurancy*/ 3.0, /*surface quality*/ "3x0.16", /*edge thickness*/ 6.5, /*back focal length*/ 156.6,
		/*min wavelength*/450.0, /*max wavelength*/ 700.0, /*coating*/ "ARB2-VIS", /*caoting specification*/ "2xR<0.5%",
		/*radius first surface*/ 97.1652, /*radius second surface*/ -71.5664, /*radius thrid surface*/ -213.638, /*thickness first*/ 4.0,
		/*thickness second*/ 3.0, /*tolerance center thickness*/ 0.1,/*material first*/glasses.getNBK7_S1(), /*material second*/ glasses.getNSF5_S1(),
		/*price*/ 149.00);

	mQ_G322328000.buildLensThreeSurfaces_Qioptiq_lenses(/*lenscatalog*/ "Qioptiq", /*catalog number*/"G322328000", /*diameter*/ 22.4,
		/*focallength*/ 200.0, /*optical centering accurancy*/ 3.0, /*surface quality*/ "3x0.16", /*edge thickness*/ 5.2, /*back focal length*/ 197.38,
		/*min wavelength*/450.0, /*max wavelength*/ 700.0, /*coating*/ "ARB2-VIS", /*caoting specification*/ "2xR<0.5%",
		/*radius first surface*/ 120.57, /*radius second surface*/ -91.728, /*radius thrid surface*/ -277.81, /*thickness first*/ 4.0,
		/*thickness second*/ 2.0, /*tolerance center thickness*/ 0.1,/*material first*/glasses.getNBK7_S1(), /*material second*/ glasses.getNSF5_S1(),
		/*price*/ 102.00);

	mQ_G322334322.buildLensThreeSurfaces_Qioptiq_lenses(/*lenscatalog*/ "Qioptiq", /*catalog number*/"G322334322", /*diameter*/ 22.4,
		/*focallength*/ 400.0, /*optical centering accurancy*/ 3.0, /*surface quality*/ "3x0.16", /*edge thickness*/ 6.6, /*back focal length*/ 396.5,
		/*min wavelength*/450.0, /*max wavelength*/ 700.0, /*coating*/ "ARB2-VIS", /*caoting specification*/ "2xR<0.5%",
		/*radius first surface*/ 248.508, /*radius second surface*/ -177.824, /*radius thrid surface*/ -515.797, /*thickness first*/ 4.0,
		/*thickness second*/ 3.0, /*tolerance center thickness*/ 0.1,/*material first*/glasses.getNBK7_S1(), /*material second*/ glasses.getNSF5_S1(),
		/*price*/ 114.00);

	mQ_G322329000.buildLensThreeSurfaces_Qioptiq_lenses(/*lenscatalog*/ "Qioptiq", /*catalog number*/"G322329000", /*diameter*/ 22.4,
		/*focallength*/ 500.0, /*optical centering accurancy*/ 3.0, /*surface quality*/ "3x0.16", /*edge thickness*/ 5.7, /*back focal length*/ 495.99,
		/*min wavelength*/450.0, /*max wavelength*/ 700.0, /*coating*/ "ARB2-VIS", /*caoting specification*/ "2xR<0.5%",
		/*radius first surface*/ 260.39, /*radius second surface*/ -260.39, /*radius thrid surface*/ -1090.2, /*thickness first*/ 4.0,
		/*thickness second*/ 2.0, /*tolerance center thickness*/ 0.1,/*material first*/glasses.getNBK7_S1(), /*material second*/ glasses.getNSF5_S1(),
		/*price*/ 102.00);

	mQ_G322306322.buildLensThreeSurfaces_Qioptiq_lenses(/*lenscatalog*/ "Qioptiq", /*catalog number*/"G322306322", /*diameter*/ 25.4,
		/*focallength*/ 60.0, /*optical centering accurancy*/ 3.0, /*surface quality*/ "3x0.16", /*edge thickness*/ 6.2, /*back focal length*/ 55.47,
		/*min wavelength*/450.0, /*max wavelength*/ 700.0, /*coating*/ "ARB2-VIS", /*caoting specification*/ "2xR<0.5%",
		/*radius first surface*/ 40.388, /*radius second surface*/ -32.2, /*radius thrid surface*/ -117.15, /*thickness first*/ 6.9,
		/*thickness second*/ 2.0, /*tolerance center thickness*/ 0.2,/*material first*/glasses.getNSSK8_S1(), /*material second*/ glasses.getNSF56_S1(),
		/*price*/ 89.00);

	mQ_G322307322.buildLensThreeSurfaces_Qioptiq_lenses(/*lenscatalog*/ "Qioptiq", /*catalog number*/"G322307322", /*diameter*/ 25.4,
		/*focallength*/ 80.0, /*optical centering accurancy*/ 3.0, /*surface quality*/ "3x0.16", /*edge thickness*/ 4.6, /*back focal length*/ 77.05,
		/*min wavelength*/450.0, /*max wavelength*/ 700.0, /*coating*/ "ARB2-VIS", /*caoting specification*/ "2xR<0.5%",
		/*radius first surface*/ 50.481, /*radius second surface*/ -35.481, /*radius thrid surface*/ -100.0, /*thickness first*/ 5.0,
		/*thickness second*/ 2.0, /*tolerance center thickness*/ 0.2,/*material first*/glasses.getNBK7_S1(), /*material second*/ glasses.getNSF5_S1(),
		/*price*/ 89.00);

	mQ_G322308322.buildLensThreeSurfaces_Qioptiq_lenses(/*lenscatalog*/ "Qioptiq", /*catalog number*/"G322308322", /*diameter*/ 25.4,
		/*focallength*/ 100.0, /*optical centering accurancy*/ 3.0, /*surface quality*/ "3x0.16", /*edge thickness*/ 7.1, /*back focal length*/ 95.89,
		/*min wavelength*/450.0, /*max wavelength*/ 700.0, /*coating*/ "ARB2-VIS", /*caoting specification*/ "2xR<0.5%",
		/*radius first surface*/ 61.748, /*radius second surface*/ -44.348, /*radius thrid surface*/ -128.64, /*thickness first*/ 6.25,
		/*thickness second*/ 2.75, /*tolerance center thickness*/ 0.2,/*material first*/glasses.getNBK7_S1(), /*material second*/ glasses.getNSF5_S1(),
		/*price*/ 89.00);

	mQ_G322309322.buildLensThreeSurfaces_Qioptiq_lenses(/*lenscatalog*/ "Qioptiq", /*catalog number*/"G322309322", /*diameter*/ 25.4,
		/*focallength*/ 120.0, /*optical centering accurancy*/ 3.0, /*surface quality*/ "3x0.16", /*edge thickness*/ 5.4, /*back focal length*/ 116.77,
		/*min wavelength*/450.0, /*max wavelength*/ 700.0, /*coating*/ "ARB2-VIS", /*caoting specification*/ "2xR<0.5%",
		/*radius first surface*/ 74.45, /*radius second surface*/ -53.472, /*radius thrid surface*/ -154.557, /*thickness first*/ 5.0,
		/*thickness second*/ 2.0, /*tolerance center thickness*/ 0.2,/*material first*/glasses.getNBK7_S1(), /*material second*/ glasses.getNSF5_S1(),
		/*price*/ 89.00);

	mQ_G322351000.buildLensThreeSurfaces_Qioptiq_lenses(/*lenscatalog*/ "Qioptiq", /*catalog number*/"G322351000", /*diameter*/ 25.4,
		/*focallength*/ 140.0, /*optical centering accurancy*/ 3.0, /*surface quality*/ "3x0.16", /*edge thickness*/ 6.6, /*back focal length*/ 136.2,
		/*min wavelength*/450.0, /*max wavelength*/ 700.0, /*coating*/ "ARB2-VIS", /*caoting specification*/ "2xR<0.5%",
		/*radius first surface*/ 87.222, /*radius second surface*/ -61.748, /*radius thrid surface*/ -177.83, /*thickness first*/ 6.0,
		/*thickness second*/ 2.0, /*tolerance center thickness*/ 0.2,/*material first*/glasses.getNBK7_S1(), /*material second*/ glasses.getNSF5_S1(),
		/*price*/ 89.00);

	mQ_G322352000.buildLensThreeSurfaces_Qioptiq_lenses(/*lenscatalog*/ "Qioptiq", /*catalog number*/"G322352000", /*diameter*/ 25.4,
		/*focallength*/ 160.0, /*optical centering accurancy*/ 3.0, /*surface quality*/ "3x0.16", /*edge thickness*/ 7.4, /*back focal length*/ 155.95,
		/*min wavelength*/450.0, /*max wavelength*/ 700.0, /*coating*/ "ARB2-VIS", /*caoting specification*/ "2xR<0.5%",
		/*radius first surface*/ 99.646, /*radius second surface*/ -70.543, /*radius thrid surface*/ -203.162, /*thickness first*/ 6.0,
		/*thickness second*/ 2.6, /*tolerance center thickness*/ 0.2,/*material first*/glasses.getNBK7_S1(), /*material second*/ glasses.getNSF5_S1(),
		/*price*/ 89.00);

	mQ_G322353000.buildLensThreeSurfaces_Qioptiq_lenses(/*lenscatalog*/ "Qioptiq", /*catalog number*/"G322353000", /*diameter*/ 25.4,
		/*focallength*/ 200.0, /*optical centering accurancy*/ 3.0, /*surface quality*/ "3x0.16", /*edge thickness*/ 5.0, /*back focal length*/ 197.38,
		/*min wavelength*/450.0, /*max wavelength*/ 700.0, /*coating*/ "ARB2-VIS", /*caoting specification*/ "2xR<0.5%",
		/*radius first surface*/ 120.57, /*radius second surface*/ -91.728, /*radius thrid surface*/ -277.1, /*thickness first*/ 4.0,
		/*thickness second*/ 2.0, /*tolerance center thickness*/ 0.2, /*material first*/glasses.getNBK7_S1(), /*material second*/ glasses.getNSF5_S1(),
		/*price*/ 89.00);

	mQ_G322336322.buildLensThreeSurfaces_Qioptiq_lenses(/*lenscatalog*/ "Qioptiq", /*catalog number*/"G322336322", /*diameter*/ 25.4,
		/*focallength*/ 300.0, /*optical centering accurancy*/ 3.0, /*surface quality*/ "3x0.16", /*edge thickness*/ 6.4, /*back focal length*/ 296.5,
		/*min wavelength*/450.0, /*max wavelength*/ 700.0, /*coating*/ "ARB2-VIS", /*caoting specification*/ "2xR<0.5%",
		/*radius first surface*/ 182.371, /*radius second surface*/ -135.774, /*radius thrid surface*/ -405.282, /*thickness first*/ 4.0,
		/*thickness second*/ 3.0, /*tolerance center thickness*/ 0.1,/*material first*/glasses.getNBK7_S1(), /*material second*/ glasses.getNSF5_S1(),
		/*price*/ 89.00);

	mQ_G322340322.buildLensThreeSurfaces_Qioptiq_lenses(/*lenscatalog*/ "Qioptiq", /*catalog number*/"G322340322", /*diameter*/ 25.4,
		/*focallength*/ 400.0, /*optical centering accurancy*/ 3.0, /*surface quality*/ "3x0.16", /*edge thickness*/ 6.5, /*back focal length*/ 396.44,
		/*min wavelength*/450.0, /*max wavelength*/ 700.0, /*coating*/ "ARB2-VIS", /*caoting specification*/ "2xR<0.5%",
		/*radius first surface*/ 243.185, /*radius second surface*/ -181.702, /*radius thrid surface*/ -542.574, /*thickness first*/ 4.0,
		/*thickness second*/ 3.0, /*tolerance center thickness*/ 0.1,/*material first*/glasses.getNBK7_S1(), /*material second*/ glasses.getNSF5_S1(),
		/*price*/ 89.00);

	mQ_G322355000.buildLensThreeSurfaces_Qioptiq_lenses(/*lenscatalog*/ "Qioptiq", /*catalog number*/"G322355000", /*diameter*/ 25.4,
		/*focallength*/ 500.0, /*optical centering accurancy*/ 3.0, /*surface quality*/ "3x0.16", /*edge thickness*/ 5.5, /*back focal length*/ 495.99,
		/*min wavelength*/450.0, /*max wavelength*/ 700.0, /*coating*/ "ARB2-VIS", /*caoting specification*/ "2xR<0.5%",
		/*radius first surface*/ 260.39, /*radius second surface*/ -260.39, /*radius thrid surface*/ -1090.2, /*thickness first*/ 4.0,
		/*thickness second*/ 2.0, /*tolerance center thickness*/ 0.2,/*material first*/glasses.getNBK7_S1(), /*material second*/ glasses.getNSF5_S1(),
		/*price*/ 89.00);

	mQ_G322287322.buildLensThreeSurfaces_Qioptiq_lenses(/*lenscatalog*/ "Qioptiq", /*catalog number*/"G322287322", /*diameter*/ 31.5,
		/*focallength*/ 80.0, /*optical centering accurancy*/ 3.0, /*surface quality*/ "5x0.25", /*edge thickness*/ 6.7, /*back focal length*/ 74.84,
		/*min wavelength*/450.0, /*max wavelength*/ 700.0, /*coating*/ "ARB2-VIS", /*caoting specification*/ "2xR<0.5%",
		/*radius first surface*/ 48.87, /*radius second surface*/ -36.917, /*radius thrid surface*/ -106.683, /*thickness first*/ 8.0,
		/*thickness second*/ 2.5, /*tolerance center thickness*/ 0.2,/*material first*/glasses.getNBK7_S1(), /*material second*/ glasses.getNSF5_S1(),
		/*price*/ 112.00);

	mQ_G322288322.buildLensThreeSurfaces_Qioptiq_lenses(/*lenscatalog*/ "Qioptiq", /*catalog number*/"G322288322", /*diameter*/ 31.5,
		/*focallength*/ 100.0, /*optical centering accurancy*/ 3.0, /*surface quality*/ "5x0.25", /*edge thickness*/ 6.5, /*back focal length*/ 95.34,
		/*min wavelength*/450.0, /*max wavelength*/ 700.0, /*coating*/ "ARB2-VIS", /*caoting specification*/ "2xR<0.5%",
		/*radius first surface*/ 61.748, /*radius second surface*/ -45.153, /*radius thrid surface*/ -130.04, /*thickness first*/ 7.5,
		/*thickness second*/ 2.0, /*tolerance center thickness*/ 0.2,/*material first*/glasses.getNBK7_S1(), /*material second*/ glasses.getNSF5_S1(),
		/*price*/ 112.00);

	mQ_G322269322.buildLensThreeSurfaces_Qioptiq_lenses(/*lenscatalog*/ "Qioptiq", /*catalog number*/"G322269322", /*diameter*/ 31.5,
		/*focallength*/ 120.0, /*optical centering accurancy*/ 3.0, /*surface quality*/ "5x0.25", /*edge thickness*/ 7.0, /*back focal length*/ 115.6,
		/*min wavelength*/450.0, /*max wavelength*/ 700.0, /*coating*/ "ARB2-VIS", /*caoting specification*/ "2xR<0.5%",
		/*radius first surface*/ 74.721, /*radius second surface*/ -54.049, /*radius thrid surface*/ -153.45, /*thickness first*/ 6.0,
		/*thickness second*/ 3.5, /*tolerance center thickness*/ 0.2,/*material first*/glasses.getNBK7_S1(), /*material second*/ glasses.getNSF5_S1(),
		/*price*/ 112.00);

	mQ_G322239322.buildLensThreeSurfaces_Qioptiq_lenses(/*lenscatalog*/ "Qioptiq", /*catalog number*/"G322239322", /*diameter*/ 31.5,
		/*focallength*/ 140.0, /*optical centering accurancy*/ 3.0, /*surface quality*/ "5x0.25", /*edge thickness*/ 5.9, /*back focal length*/ 136.2,
		/*min wavelength*/450.0, /*max wavelength*/ 700.0, /*coating*/ "ARB2-VIS", /*caoting specification*/ "2xR<0.5%",
		/*radius first surface*/ 87.222, /*radius second surface*/ -6.748, /*radius thrid surface*/ -177.83, /*thickness first*/ 6.0,
		/*thickness second*/ 2.0, /*tolerance center thickness*/ 0.2,/*material first*/glasses.getNBK7_S1(), /*material second*/ glasses.getNSF5_S1(),
		/*price*/ 112.00);

	mQ_G322227322.buildLensThreeSurfaces_Qioptiq_lenses(/*lenscatalog*/ "Qioptiq", /*catalog number*/"G322227322", /*diameter*/ 31.5,
		/*focallength*/ 150.0, /*optical centering accurancy*/ 3.0, /*surface quality*/ "5x0.25", /*edge thickness*/ 6.6, /*back focal length*/ 145.85,
		/*min wavelength*/450.0, /*max wavelength*/ 700.0, /*coating*/ "ARB2-VIS", /*caoting specification*/ "2xR<0.5%",
		/*radius first surface*/ 93.402, /*radius second surface*/ -66.117, /*radius thrid surface*/ -190.4, /*thickness first*/ 6.4,
		/*thickness second*/ 2.2, /*tolerance center thickness*/ 0.2,/*material first*/glasses.getNBK7_S1(), /*material second*/ glasses.getNSF5_S1(),
		/*price*/ 112.00);

	mQ_G322270322.buildLensThreeSurfaces_Qioptiq_lenses(/*lenscatalog*/ "Qioptiq", /*catalog number*/"G322270322", /*diameter*/ 31.5,
		/*focallength*/ 160.0, /*optical centering accurancy*/ 3.0, /*surface quality*/ "5x0.25", /*edge thickness*/ 6.7, /*back focal length*/ 155.95,
		/*min wavelength*/450.0, /*max wavelength*/ 700.0, /*coating*/ "ARB2-VIS", /*caoting specification*/ "2xR<0.5%",
		/*radius first surface*/ 99.646, /*radius second surface*/ -70.543, /*radius thrid surface*/ -203.162, /*thickness first*/ 6.0,
		/*thickness second*/ 2.6, /*tolerance center thickness*/ 0.2,/*material first*/glasses.getNBK7_S1(), /*material second*/ glasses.getNSF5_S1(),
		/*price*/ 112.00);

	mQ_G322342322.buildLensThreeSurfaces_Qioptiq_lenses(/*lenscatalog*/ "Qioptiq", /*catalog number*/"G322342322", /*diameter*/ 31.5,
		/*focallength*/ 180.0, /*optical centering accurancy*/ 3.0, /*surface quality*/ "3x0.16", /*edge thickness*/ 7.1, /*back focal length*/ 175.84,
		/*min wavelength*/450.0, /*max wavelength*/ 700.0, /*coating*/ "ARB2-VIS", /*caoting specification*/ "2xR<0.5%",
		/*radius first surface*/ 107.853, /*radius second surface*/ -76.6263, /*radius thrid surface*/ -221.4701, /*thickness first*/ 6.0,
		/*thickness second*/ 3.0, /*tolerance center thickness*/ 0.2,/*material first*/glasses.getNBK10_S1(), /*material second*/ glasses.getNSF2_S1(),
		/*price*/ 112.00);

	mQ_G322271322.buildLensThreeSurfaces_Qioptiq_lenses(/*lenscatalog*/ "Qioptiq", /*catalog number*/"G322271322", /*diameter*/ 31.5,
		/*focallength*/ 200.0, /*optical centering accurancy*/ 3.0, /*surface quality*/ "5x0.25", /*edge thickness*/ 5.5, /*back focal length*/ 197.21,
		/*min wavelength*/450.0, /*max wavelength*/ 700.0, /*coating*/ "ARB2-VIS", /*caoting specification*/ "2xR<0.5%",
		/*radius first surface*/ 120.57, /*radius second surface*/ -91.728, /*radius thrid surface*/ -277.81, /*thickness first*/ 4.0,
		/*thickness second*/ 3.0, /*tolerance center thickness*/ 0.2,/*material first*/glasses.getNBK7_S1(), /*material second*/ glasses.getNSF5_S1(),
		/*price*/ 112.00);

	mQ_G322272322.buildLensThreeSurfaces_Qioptiq_lenses(/*lenscatalog*/ "Qioptiq", /*catalog number*/"G322272322", /*diameter*/ 31.5,
		/*focallength*/ 250.0, /*optical centering accurancy*/ 3.0, /*surface quality*/ "5x0.25", /*edge thickness*/ 5.8, /*back focal length*/ 247.42,
		/*min wavelength*/450.0, /*max wavelength*/ 700.0, /*coating*/ "ARB2-VIS", /*caoting specification*/ "2xR<0.5%",
		/*radius first surface*/ 156.217, /*radius second surface*/ -110.21, /*radius thrid surface*/ -318.535, /*thickness first*/ 4.0,
		/*thickness second*/ 3.0, /*tolerance center thickness*/ 0.2,/*material first*/glasses.getNBK7_S1(), /*material second*/ glasses.getNSF5_S1(),
		/*price*/ 112.00);

	mQ_G322273322.buildLensThreeSurfaces_Qioptiq_lenses(/*lenscatalog*/ "Qioptiq", /*catalog number*/"G322273322", /*diameter*/ 31.5,
		/*focallength*/ 300.0, /*optical centering accurancy*/ 3.0, /*surface quality*/ "5x0.25", /*edge thickness*/ 6.0, /*back focal length*/ 297.19,
		/*min wavelength*/450.0, /*max wavelength*/ 700.0, /*coating*/ "ARB2-VIS", /*caoting specification*/ "2xR<0.5%",
		/*radius first surface*/ 187.015, /*radius second surface*/ -131.938, /*radius thrid surface*/ -382.71, /*thickness first*/ 4.0,
		/*thickness second*/ 3.0, /*tolerance center thickness*/ 0.2,/*material first*/glasses.getNBK7_S1(), /*material second*/ glasses.getNSF5_S1(),
		/*price*/ 112.00);

	mQ_G322275322.buildLensThreeSurfaces_Qioptiq_lenses(/*lenscatalog*/ "Qioptiq", /*catalog number*/"G322275322", /*diameter*/ 31.5,
		/*focallength*/ 400.0, /*optical centering accurancy*/ 3.0, /*surface quality*/ "5x0.25", /*edge thickness*/ 6.3, /*back focal length*/ 397.05,
		/*min wavelength*/450.0, /*max wavelength*/ 700.0, /*coating*/ "ARB2-VIS", /*caoting specification*/ "2xR<0.5%",
		/*radius first surface*/ 249.393, /*radius second surface*/ -175.917, /*radius thrid surface*/ -510.26, /*thickness first*/ 4.0,
		/*thickness second*/ 3.0, /*tolerance center thickness*/ 0.2,/*material first*/glasses.getNBK7_S1(), /*material second*/ glasses.getNSF5_S1(),
		/*price*/ 150.00);

	//// no zemax
	//// no radius, no thickness, no glasses
	//mQ_G322277322.buildLensThreeSurfaces_Qioptiq_lenses(/*lenscatalog*/ "Qioptiq", /*catalog number*/"G322277322", /*diameter*/ 31.5,
	//	/*focallength*/ 600.0, /*optical centering accurancy*/ 3.0, /*surface quality*/ "3x0.16", /*edge thickness*/ 6.5, /*back focal length*/ 597.3,
	//	/*min wavelength*/450.0, /*max wavelength*/ 700.0, /*coating*/ "ARB2-VIS", /*caoting specification*/ "2xR<0.5%",
	//	/*radius first surface*/ 9999.0, /*radius second surface*/ -99999.0, /*radius thrid surface*/ -999999.0, /*thickness first*/ 0.0,
	//	/*thickness second*/ 0.0, /*tolerance center thickness*/ 0.2,/*material first*/glasses.getNBK7_S1(), /*material second*/ glasses.getNSF5_S1(),
	//	/*price*/ 150.00);

}

std::vector<LensThreeSurfaces> QioptiqLensCatalog::getAll_Achromats_VIS_Positive_dia_3_mm_to_31_5_mm_unmounted_N_BK7_ARB2_VIS()
{
	// https://www.qioptiq-shop.com/en/Precision-Optics/LINOS-Achromats-Lens-Systems/Achromats-positive/Achromats-VIS-Positive-dia-3-mm-to-31-5-mm-unmounted.html

	std::vector<LensThreeSurfaces> return_Qioptiq_Achromats_VIS_Positive_dia_3_mm_to_31_5_mm_unmounted_N_BK7_ARB2_VIS;
	return_Qioptiq_Achromats_VIS_Positive_dia_3_mm_to_31_5_mm_unmounted_N_BK7_ARB2_VIS.push_back(mQ_G322218000);
	return_Qioptiq_Achromats_VIS_Positive_dia_3_mm_to_31_5_mm_unmounted_N_BK7_ARB2_VIS.push_back(mQ_G322219000);
	return_Qioptiq_Achromats_VIS_Positive_dia_3_mm_to_31_5_mm_unmounted_N_BK7_ARB2_VIS.push_back(mQ_G322250000);
	return_Qioptiq_Achromats_VIS_Positive_dia_3_mm_to_31_5_mm_unmounted_N_BK7_ARB2_VIS.push_back(mQ_G322220000);
	return_Qioptiq_Achromats_VIS_Positive_dia_3_mm_to_31_5_mm_unmounted_N_BK7_ARB2_VIS.push_back(mQ_G322206000);
	return_Qioptiq_Achromats_VIS_Positive_dia_3_mm_to_31_5_mm_unmounted_N_BK7_ARB2_VIS.push_back(mQ_G322222000);
	return_Qioptiq_Achromats_VIS_Positive_dia_3_mm_to_31_5_mm_unmounted_N_BK7_ARB2_VIS.push_back(mQ_G322223000);
	return_Qioptiq_Achromats_VIS_Positive_dia_3_mm_to_31_5_mm_unmounted_N_BK7_ARB2_VIS.push_back(mQ_G322207000);
	return_Qioptiq_Achromats_VIS_Positive_dia_3_mm_to_31_5_mm_unmounted_N_BK7_ARB2_VIS.push_back(mQ_G322356322);
	return_Qioptiq_Achromats_VIS_Positive_dia_3_mm_to_31_5_mm_unmounted_N_BK7_ARB2_VIS.push_back(mQ_G322357322);
	return_Qioptiq_Achromats_VIS_Positive_dia_3_mm_to_31_5_mm_unmounted_N_BK7_ARB2_VIS.push_back(mQ_G322358322);
	return_Qioptiq_Achromats_VIS_Positive_dia_3_mm_to_31_5_mm_unmounted_N_BK7_ARB2_VIS.push_back(mQ_G322359322);
	return_Qioptiq_Achromats_VIS_Positive_dia_3_mm_to_31_5_mm_unmounted_N_BK7_ARB2_VIS.push_back(mQ_G322360322);
	//return_Qioptiq_Achromats_VIS_Positive_dia_3_mm_to_31_5_mm_unmounted_N_BK7_ARB2_VIS.push_back(mQ_G322361322); /* no zemax file */
	return_Qioptiq_Achromats_VIS_Positive_dia_3_mm_to_31_5_mm_unmounted_N_BK7_ARB2_VIS.push_back(mQ_G322362322);
	return_Qioptiq_Achromats_VIS_Positive_dia_3_mm_to_31_5_mm_unmounted_N_BK7_ARB2_VIS.push_back(mQ_G322363322);
	return_Qioptiq_Achromats_VIS_Positive_dia_3_mm_to_31_5_mm_unmounted_N_BK7_ARB2_VIS.push_back(mQ_G322364322);
	// return_Qioptiq_Achromats_VIS_Positive_dia_3_mm_to_31_5_mm_unmounted_N_BK7_ARB2_VIS.push_back(mQ_G322365322); /* no zemax file */
	return_Qioptiq_Achromats_VIS_Positive_dia_3_mm_to_31_5_mm_unmounted_N_BK7_ARB2_VIS.push_back(mQ_G322366322);
	return_Qioptiq_Achromats_VIS_Positive_dia_3_mm_to_31_5_mm_unmounted_N_BK7_ARB2_VIS.push_back(mQ_G322367322);
	return_Qioptiq_Achromats_VIS_Positive_dia_3_mm_to_31_5_mm_unmounted_N_BK7_ARB2_VIS.push_back(mQ_G322368322);
	return_Qioptiq_Achromats_VIS_Positive_dia_3_mm_to_31_5_mm_unmounted_N_BK7_ARB2_VIS.push_back(mQ_G322201000);
	return_Qioptiq_Achromats_VIS_Positive_dia_3_mm_to_31_5_mm_unmounted_N_BK7_ARB2_VIS.push_back(mQ_G322284000);
	return_Qioptiq_Achromats_VIS_Positive_dia_3_mm_to_31_5_mm_unmounted_N_BK7_ARB2_VIS.push_back(mQ_G322285000);
	return_Qioptiq_Achromats_VIS_Positive_dia_3_mm_to_31_5_mm_unmounted_N_BK7_ARB2_VIS.push_back(mQ_G322286000);
	return_Qioptiq_Achromats_VIS_Positive_dia_3_mm_to_31_5_mm_unmounted_N_BK7_ARB2_VIS.push_back(mQ_G322337000);
	return_Qioptiq_Achromats_VIS_Positive_dia_3_mm_to_31_5_mm_unmounted_N_BK7_ARB2_VIS.push_back(mQ_G322338000);
	return_Qioptiq_Achromats_VIS_Positive_dia_3_mm_to_31_5_mm_unmounted_N_BK7_ARB2_VIS.push_back(mQ_G322339000);
	return_Qioptiq_Achromats_VIS_Positive_dia_3_mm_to_31_5_mm_unmounted_N_BK7_ARB2_VIS.push_back(mQ_G322341000);
	return_Qioptiq_Achromats_VIS_Positive_dia_3_mm_to_31_5_mm_unmounted_N_BK7_ARB2_VIS.push_back(mQ_G322343000);
	return_Qioptiq_Achromats_VIS_Positive_dia_3_mm_to_31_5_mm_unmounted_N_BK7_ARB2_VIS.push_back(mQ_G322345000);
	return_Qioptiq_Achromats_VIS_Positive_dia_3_mm_to_31_5_mm_unmounted_N_BK7_ARB2_VIS.push_back(mQ_G322320322);
	return_Qioptiq_Achromats_VIS_Positive_dia_3_mm_to_31_5_mm_unmounted_N_BK7_ARB2_VIS.push_back(mQ_G322325322);
	return_Qioptiq_Achromats_VIS_Positive_dia_3_mm_to_31_5_mm_unmounted_N_BK7_ARB2_VIS.push_back(mQ_G322327322);
	//return_Qioptiq_Achromats_VIS_Positive_dia_3_mm_to_31_5_mm_unmounted_N_BK7_ARB2_VIS.push_back(mQ_G322209000);
	return_Qioptiq_Achromats_VIS_Positive_dia_3_mm_to_31_5_mm_unmounted_N_BK7_ARB2_VIS.push_back(mQ_G322265000);
	return_Qioptiq_Achromats_VIS_Positive_dia_3_mm_to_31_5_mm_unmounted_N_BK7_ARB2_VIS.push_back(mQ_G322266000);
	return_Qioptiq_Achromats_VIS_Positive_dia_3_mm_to_31_5_mm_unmounted_N_BK7_ARB2_VIS.push_back(mQ_G322210000);
	return_Qioptiq_Achromats_VIS_Positive_dia_3_mm_to_31_5_mm_unmounted_N_BK7_ARB2_VIS.push_back(mQ_G322236000);
	return_Qioptiq_Achromats_VIS_Positive_dia_3_mm_to_31_5_mm_unmounted_N_BK7_ARB2_VIS.push_back(mQ_G322331322);
	return_Qioptiq_Achromats_VIS_Positive_dia_3_mm_to_31_5_mm_unmounted_N_BK7_ARB2_VIS.push_back(mQ_G322332322);
	return_Qioptiq_Achromats_VIS_Positive_dia_3_mm_to_31_5_mm_unmounted_N_BK7_ARB2_VIS.push_back(mQ_G322321000);
	return_Qioptiq_Achromats_VIS_Positive_dia_3_mm_to_31_5_mm_unmounted_N_BK7_ARB2_VIS.push_back(mQ_G322322000);
	return_Qioptiq_Achromats_VIS_Positive_dia_3_mm_to_31_5_mm_unmounted_N_BK7_ARB2_VIS.push_back(mQ_G322323000);
	return_Qioptiq_Achromats_VIS_Positive_dia_3_mm_to_31_5_mm_unmounted_N_BK7_ARB2_VIS.push_back(mQ_G322324000);
	return_Qioptiq_Achromats_VIS_Positive_dia_3_mm_to_31_5_mm_unmounted_N_BK7_ARB2_VIS.push_back(mQ_G322326000);
	return_Qioptiq_Achromats_VIS_Positive_dia_3_mm_to_31_5_mm_unmounted_N_BK7_ARB2_VIS.push_back(mQ_G322333322);
	return_Qioptiq_Achromats_VIS_Positive_dia_3_mm_to_31_5_mm_unmounted_N_BK7_ARB2_VIS.push_back(mQ_G322328000);
	return_Qioptiq_Achromats_VIS_Positive_dia_3_mm_to_31_5_mm_unmounted_N_BK7_ARB2_VIS.push_back(mQ_G322334322);
	return_Qioptiq_Achromats_VIS_Positive_dia_3_mm_to_31_5_mm_unmounted_N_BK7_ARB2_VIS.push_back(mQ_G322329000);
	return_Qioptiq_Achromats_VIS_Positive_dia_3_mm_to_31_5_mm_unmounted_N_BK7_ARB2_VIS.push_back(mQ_G322306322);
	return_Qioptiq_Achromats_VIS_Positive_dia_3_mm_to_31_5_mm_unmounted_N_BK7_ARB2_VIS.push_back(mQ_G322307322);
	return_Qioptiq_Achromats_VIS_Positive_dia_3_mm_to_31_5_mm_unmounted_N_BK7_ARB2_VIS.push_back(mQ_G322308322);
	return_Qioptiq_Achromats_VIS_Positive_dia_3_mm_to_31_5_mm_unmounted_N_BK7_ARB2_VIS.push_back(mQ_G322309322);
	return_Qioptiq_Achromats_VIS_Positive_dia_3_mm_to_31_5_mm_unmounted_N_BK7_ARB2_VIS.push_back(mQ_G322351000);
	return_Qioptiq_Achromats_VIS_Positive_dia_3_mm_to_31_5_mm_unmounted_N_BK7_ARB2_VIS.push_back(mQ_G322352000);
	return_Qioptiq_Achromats_VIS_Positive_dia_3_mm_to_31_5_mm_unmounted_N_BK7_ARB2_VIS.push_back(mQ_G322353000);
	return_Qioptiq_Achromats_VIS_Positive_dia_3_mm_to_31_5_mm_unmounted_N_BK7_ARB2_VIS.push_back(mQ_G322336322);
	return_Qioptiq_Achromats_VIS_Positive_dia_3_mm_to_31_5_mm_unmounted_N_BK7_ARB2_VIS.push_back(mQ_G322340322);
	return_Qioptiq_Achromats_VIS_Positive_dia_3_mm_to_31_5_mm_unmounted_N_BK7_ARB2_VIS.push_back(mQ_G322355000);
	return_Qioptiq_Achromats_VIS_Positive_dia_3_mm_to_31_5_mm_unmounted_N_BK7_ARB2_VIS.push_back(mQ_G322287322);
	return_Qioptiq_Achromats_VIS_Positive_dia_3_mm_to_31_5_mm_unmounted_N_BK7_ARB2_VIS.push_back(mQ_G322288322);
	return_Qioptiq_Achromats_VIS_Positive_dia_3_mm_to_31_5_mm_unmounted_N_BK7_ARB2_VIS.push_back(mQ_G322269322);
	return_Qioptiq_Achromats_VIS_Positive_dia_3_mm_to_31_5_mm_unmounted_N_BK7_ARB2_VIS.push_back(mQ_G322239322);
	return_Qioptiq_Achromats_VIS_Positive_dia_3_mm_to_31_5_mm_unmounted_N_BK7_ARB2_VIS.push_back(mQ_G322227322);
	return_Qioptiq_Achromats_VIS_Positive_dia_3_mm_to_31_5_mm_unmounted_N_BK7_ARB2_VIS.push_back(mQ_G322270322);
	return_Qioptiq_Achromats_VIS_Positive_dia_3_mm_to_31_5_mm_unmounted_N_BK7_ARB2_VIS.push_back(mQ_G322342322);
	return_Qioptiq_Achromats_VIS_Positive_dia_3_mm_to_31_5_mm_unmounted_N_BK7_ARB2_VIS.push_back(mQ_G322271322);
	return_Qioptiq_Achromats_VIS_Positive_dia_3_mm_to_31_5_mm_unmounted_N_BK7_ARB2_VIS.push_back(mQ_G322272322);
	return_Qioptiq_Achromats_VIS_Positive_dia_3_mm_to_31_5_mm_unmounted_N_BK7_ARB2_VIS.push_back(mQ_G322273322);
	return_Qioptiq_Achromats_VIS_Positive_dia_3_mm_to_31_5_mm_unmounted_N_BK7_ARB2_VIS.push_back(mQ_G322275322);
	//return_Qioptiq_Achromats_VIS_Positive_dia_3_mm_to_31_5_mm_unmounted_N_BK7_ARB2_VIS.push_back(mQ_G322277322);

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
		/*price*/ 131.00);

	mQ_G322388000.buildLensThreeSurfaces_Qioptiq_lenses(/*lenscatalog*/ "Qioptiq", /*catalog number*/"G322388000", /*diameter*/ 40.0,
		/*focallength*/ 120.0, /*optical centering accurancy*/ 6.0, /*surface quality*/ "5x0.4", /*edge thickness*/ 9.7, /*back focal length*/ 113.6,
		/*min wavelength*/450.0, /*max wavelength*/ 700.0, /*coating*/ "ARB2-VIS", /*caoting specification*/ "2xR<0.5%",
		/*radius first surface*/ 85.053, /*radius second surface*/ -41.269, /*radius thrid surface*/ -217.52, /*thickness first*/ 10.0,
		/*thickness second*/ 3.0, /*tolerance center thickness*/ 0.2,/*material first*/glasses.getNBAK1_S1(), /*material second*/ glasses.getNF2_S1(),
		/*price*/ 131.00);

	mQ_G322384000.buildLensThreeSurfaces_Qioptiq_lenses(/*lenscatalog*/ "Qioptiq", /*catalog number*/"G322384000", /*diameter*/ 40.0,
		/*focallength*/ 160.0, /*optical centering accurancy*/ 3.0, /*surface quality*/ "5x0.4", /*edge thickness*/ 9.0, /*back focal length*/ 154.64,
		/*min wavelength*/450.0, /*max wavelength*/ 700.0, /*coating*/ "ARB2-VIS", /*caoting specification*/ "2xR<0.5%",
		/*radius first surface*/ 102.92, /*radius second surface*/ -76.626, /*radius thrid surface*/ -266.07, /*thickness first*/ 7.1,
		/*thickness second*/ 4.6, /*tolerance center thickness*/ 0.2,/*material first*/glasses.getNBAK1_S1(), /*material second*/ glasses.getNSF1_S1(),
		/*price*/ 131.00);

	mQ_G322246000.buildLensThreeSurfaces_Qioptiq_lenses(/*lenscatalog*/ "Qioptiq", /*catalog number*/"G322246000", /*diameter*/ 40.0,
		/*focallength*/ 180.0, /*optical centering accurancy*/ 3.0, /*surface quality*/ "5x0.4", /*edge thickness*/ 8.2, /*back focal length*/ 174.92,
		/*min wavelength*/450.0, /*max wavelength*/ 700.0, /*coating*/ "ARB2-VIS", /*caoting specification*/ "2xR<0.5%",
		/*radius first surface*/ 90.417, /*radius second surface*/ -78.298, /*radius thrid surface*/ -558.31, /*thickness first*/ 7.3,
		/*thickness second*/ 3.5, /*tolerance center thickness*/ 0.2,/*material first*/glasses.getNBK7_S1(), /*material second*/ glasses.getNF2_S1(),
		/*price*/ 196.00);

	mQ_G322293000.buildLensThreeSurfaces_Qioptiq_lenses(/*lenscatalog*/ "Qioptiq", /*catalog number*/"G322293000", /*diameter*/ 40.0,
		/*focallength*/ 200.0, /*optical centering accurancy*/ 3.0, /*surface quality*/ "5x0.4", /*edge thickness*/ 7.7, /*back focal length*/ 195.34,
		/*min wavelength*/450.0, /*max wavelength*/ 700.0, /*coating*/ "ARB2-VIS", /*caoting specification*/ "2xR<0.5%",
		/*radius first surface*/ 104.41, /*radius second surface*/ -86.596, /*radius thrid surface*/ -508.45, /*thickness first*/ 6.5,
		/*thickness second*/ 3.5, /*tolerance center thickness*/ 0.2,/*material first*/glasses.getNBK7_S1(), /*material second*/ glasses.getNF2_S1(),
		/*price*/ 131.00);

	mQ_G322294000.buildLensThreeSurfaces_Qioptiq_lenses(/*lenscatalog*/ "Qioptiq", /*catalog number*/"G322294000", /*diameter*/ 40.0,
		/*focallength*/ 250.0, /*optical centering accurancy*/ 3.0, /*surface quality*/ "5x0.4", /*edge thickness*/ 7.6, /*back focal length*/ 245.52,
		/*min wavelength*/450.0, /*max wavelength*/ 700.0, /*coating*/ "ARB2-VIS", /*caoting specification*/ "2xR<0.5%",
		/*radius first surface*/ 153.99, /*radius second surface*/ -109.81, /*radius thrid surface*/ -323.13, /*thickness first*/ 6.2,
		/*thickness second*/ 3.3, /*tolerance center thickness*/ 0.2,/*material first*/glasses.getNBK7_S1(), /*material second*/ glasses.getNSF5_S1(),
		/*price*/ 131.00);

	mQ_G322295000.buildLensThreeSurfaces_Qioptiq_lenses(/*lenscatalog*/ "Qioptiq", /*catalog number*/"G322295000", /*diameter*/ 40.0,
		/*focallength*/ 300.0, /*optical centering accurancy*/ 3.0, /*surface quality*/ "5x0.4", /*edge thickness*/ 9.4, /*back focal length*/ 294.78,
		/*min wavelength*/450.0, /*max wavelength*/ 700.0, /*coating*/ "ARB2-VIS", /*caoting specification*/ "2xR<0.5%",
		/*radius first surface*/ 184.34, /*radius second surface*/ -116.31, /*radius thrid surface*/ -434.01, /*thickness first*/ 7.0,
		/*thickness second*/ 4.0, /*tolerance center thickness*/ 0.2,/*material first*/glasses.getNBK7_S1(), /*material second*/ glasses.getNF2_S1(),
		/*price*/ 172.00);

	////no zemax
	////no radius, no thickness, no glasses
	//mQ_G322373322.buildLensThreeSurfaces_Qioptiq_lenses(/*lenscatalog*/ "Qioptiq", /*catalog number*/"G322373322", /*diameter*/ 40.0,
	//	/*focallength*/ 350.0, /*optical centering accurancy*/ 3.0, /*surface quality*/ "5x0.25", /*edge thickness*/ 8.6, /*back focal length*/ 345.1,
	//	/*min wavelength*/450.0, /*max wavelength*/ 700.0, /*coating*/ "ARB2-VIS", /*caoting specification*/ "2xR<0.5%",
	//	/*radius first surface*/ 9999.0, /*radius second surface*/ -9999.0, /*radius thrid surface*/ -9999.0, /*thickness first*/ 0.0,
	//	/*thickness second*/ 0.0, /*tolerance center thickness*/ 0.2,/*material first*/glasses.getNBAK1_S1(), /*material second*/ glasses.getNF2_S1(),
	//	/*price*/ 172.00);

	mQ_G322301000.buildLensThreeSurfaces_Qioptiq_lenses(/*lenscatalog*/ "Qioptiq", /*catalog number*/"G322301000", /*diameter*/ 50.0,
		/*focallength*/ 80.0, /*optical centering accurancy*/ 3.0, /*surface quality*/ "5x0.4", /*edge thickness*/ 11.9, /*back focal length*/ 69.05,
		/*min wavelength*/450.0, /*max wavelength*/ 700.0, /*coating*/ "ARB2-VIS", /*caoting specification*/ "2xR<0.5%",
		/*radius first surface*/ 52.33, /*radius second surface*/ -41.867, /*radius thrid surface*/ -184.34, /*thickness first*/ 16.8,
		/*thickness second*/ 3.2, /*tolerance center thickness*/ 0.2,/*material first*/glasses.getNSK2_S1(), /*material second*/ glasses.getNSF10_S1(),
		/*price*/ 179.00);

	mQ_G322302000.buildLensThreeSurfaces_Qioptiq_lenses(/*lenscatalog*/ "Qioptiq", /*catalog number*/"G322302000", /*diameter*/ 50.0,
		/*focallength*/ 100.0, /*optical centering accurancy*/ 3.0, /*surface quality*/ "5x0.4", /*edge thickness*/ 11.2, /*back focal length*/ 92.03,
		/*min wavelength*/450.0, /*max wavelength*/ 700.0, /*coating*/ "ARB2-VIS", /*caoting specification*/ "2xR<0.5%",
		/*radius first surface*/ 66.355, /*radius second surface*/ -51.212, /*radius thrid surface*/ -230.41, /*thickness first*/ 14.0,
		/*thickness second*/ 3.5, /*tolerance center thickness*/ 0.2,/*material first*/glasses.getNSK2_S1(), /*material second*/ glasses.getNSF10_S1(),
		/*price*/ 171.00);

	mQ_G322303000.buildLensThreeSurfaces_Qioptiq_lenses(/*lenscatalog*/ "Qioptiq", /*catalog number*/"G322303000", /*diameter*/ 50.0,
		/*focallength*/ 120.0, /*optical centering accurancy*/ 3.0, /*surface quality*/ "5x0.4", /*edge thickness*/ 10.3, /*back focal length*/ 112.88,
		/*min wavelength*/450.0, /*max wavelength*/ 700.0, /*coating*/ "ARB2-VIS", /*caoting specification*/ "2xR<0.5%",
		/*radius first surface*/ 78.298, /*radius second surface*/ -60.43, /*radius thrid surface*/ -285.92, /*thickness first*/ 12.0,
		/*thickness second*/ 3.5, /*tolerance center thickness*/ 0.2,/*material first*/glasses.getNSK2_S1(), /*material second*/ glasses.getNSF10_S1(),
		/*price*/ 231.00);

	//// no zemax
	//// no radius, no thickness, no glasses
	//mQ_G322369322.buildLensThreeSurfaces_Qioptiq_lenses(/*lenscatalog*/ "Qioptiq", /*catalog number*/"G322369322", /*diameter*/ 50.0,
	//	/*focallength*/ 160.0, /*optical centering accurancy*/ 3.0, /*surface quality*/ "5x0.25", /*edge thickness*/ 10.8, /*back focal length*/ 151.63,
	//	/*min wavelength*/450.0, /*max wavelength*/ 700.0, /*coating*/ "ARB2-VIS", /*caoting specification*/ "2xR<0.5%",
	//	/*radius first surface*/ 99999.0, /*radius second surface*/ -9999.0, /*radius thrid surface*/ -99999.0, /*thickness first*/ 0.0,
	//	/*thickness second*/ 0.0, /*tolerance center thickness*/ 0.2,/*material first*/glasses.getNBAK1_S1(), /*material second*/ glasses.getNF2_S1(),
	//	/*price*/ 179.00);

	mQ_G322304000.buildLensThreeSurfaces_Qioptiq_lenses(/*lenscatalog*/ "Qioptiq", /*catalog number*/"G322304000", /*diameter*/ 50.0,
		/*focallength*/ 200.0, /*optical centering accurancy*/ 2.0, /*surface quality*/ "5x0.4", /*edge thickness*/ 8.9, /*back focal length*/ 193.7,
		/*min wavelength*/450.0, /*max wavelength*/ 700.0, /*coating*/ "ARB2-VIS", /*caoting specification*/ "2xR<0.5%",
		/*radius first surface*/ 104.41, /*radius second surface*/ -86.596, /*radius thrid surface*/ -508.45, /*thickness first*/ 9.0,
		/*thickness second*/ 3.5, /*tolerance center thickness*/ 0.2,/*material first*/glasses.getNBK7_S1(), /*material second*/ glasses.getNF2_S1(),
		/*price*/ 179.00);

	mQ_G322305000.buildLensThreeSurfaces_Qioptiq_lenses(/*lenscatalog*/ "Qioptiq", /*catalog number*/"G322305000", /*diameter*/ 50.0,
		/*focallength*/ 300.0, /*optical centering accurancy*/ 2.0, /*surface quality*/ "5x0.4", /*edge thickness*/ 9.6, /*back focal length*/ 294.31,
		/*min wavelength*/450.0, /*max wavelength*/ 700.0, /*coating*/ "ARB2-VIS", /*caoting specification*/ "2xR<0.5%",
		/*radius first surface*/ 184.34, /*radius second surface*/ -116.31, /*radius thrid surface*/ -434.01, /*thickness first*/ 8.0,
		/*thickness second*/ 4.0, /*tolerance center thickness*/ 0.2,/*material first*/glasses.getNBK7_S1(), /*material second*/ glasses.getNF2_S1(),
		/*price*/ 179.00);

	mQ_G322310000.buildLensThreeSurfaces_Qioptiq_lenses(/*lenscatalog*/ "Qioptiq", /*catalog number*/"G322310000", /*diameter*/ 50.8,
		/*focallength*/ 160.0, /*optical centering accurancy*/ 3.0, /*surface quality*/ "5x0.4", /*edge thickness*/ 8.6, /*back focal length*/ 152.76,
		/*min wavelength*/450.0, /*max wavelength*/ 700.0, /*coating*/ "ARB2-VIS", /*caoting specification*/ "2xR<0.5%",
		/*radius first surface*/ 96.466, /*radius second surface*/ -71.821, /*radius thrid surface*/ -214.41, /*thickness first*/ 10.0,
		/*thickness second*/ 3.5, /*tolerance center thickness*/ 0.2,/*material first*/glasses.getNBK7_S1(), /*material second*/ glasses.getNSF5_S1(),
		/*price*/ 203.00);

	mQ_G322311000.buildLensThreeSurfaces_Qioptiq_lenses(/*lenscatalog*/ "Qioptiq", /*catalog number*/"G322311000", /*diameter*/ 50.8,
		/*focallength*/ 250.0, /*optical centering accurancy*/ 2.0, /*surface quality*/ "5x0.4", /*edge thickness*/ 8.4, /*back focal length*/ 244.65,
		/*min wavelength*/450.0, /*max wavelength*/ 700.0, /*coating*/ "ARB2-VIS", /*caoting specification*/ "2xR<0.5%",
		/*radius first surface*/ 153.99, /*radius second surface*/ -109.81, /*radius thrid surface*/ -323.13, /*thickness first*/ 8.0,
		/*thickness second*/ 3.5, /*tolerance center thickness*/ 0.2,/*material first*/glasses.getNBK7_S1(), /*material second*/ glasses.getNSF5_S1(),
		/*price*/ 230.00);

	mQ_G322312000.buildLensThreeSurfaces_Qioptiq_lenses(/*lenscatalog*/ "Qioptiq", /*catalog number*/"G322312000", /*diameter*/ 50.8,
		/*focallength*/ 400.0, /*optical centering accurancy*/ 2.0, /*surface quality*/ "5x0.4", /*edge thickness*/ 8.6, /*back focal length*/ 395.59,
		/*min wavelength*/450.0, /*max wavelength*/ 700.0, /*coating*/ "ARB2-VIS", /*caoting specification*/ "2xR<0.5%",
		/*radius first surface*/ 242.31, /*radius second surface*/ -177.83, /*radius thrid surface*/ -538.58, /*thickness first*/ 6.0,
		/*thickness second*/ 4.5, /*tolerance center thickness*/ 0.2,/*material first*/glasses.getNBK7_S1(), /*material second*/ glasses.getNSF5_S1(),
		/*price*/ 223.00);

	mQ_G322383000.buildLensThreeSurfaces_Qioptiq_lenses(/*lenscatalog*/ "Qioptiq", /*catalog number*/"G322383000", /*diameter*/ 63.0,
		/*focallength*/ 150.0, /*optical centering accurancy*/ 3.0, /*surface quality*/ "5x0.4", /*edge thickness*/ 13.9, /*back focal length*/ 138.3,
		/*min wavelength*/450.0, /*max wavelength*/ 700.0, /*coating*/ "ARB2-VIS", /*caoting specification*/ "2xR<0.5%",
		/*radius first surface*/ 88.486, /*radius second surface*/ -72.862, /*radius thrid surface*/ -379.92, /*thickness first*/ 16.0,
		/*thickness second*/ 5.0, /*tolerance center thickness*/ 0.2,/*material first*/glasses.getNBAK1_S1(), /*material second*/ glasses.getNSF8_S1(),
		/*price*/ 320.00);

	mQ_G322230000.buildLensThreeSurfaces_Qioptiq_lenses(/*lenscatalog*/ "Qioptiq", /*catalog number*/"G322230000", /*diameter*/ 63.0,
		/*focallength*/ 500.0, /*optical centering accurancy*/ 2.0, /*surface quality*/ "5x0.4", /*edge thickness*/ 10.7, /*back focal length*/ 494.65,
		/*min wavelength*/450.0, /*max wavelength*/ 700.0, /*coating*/ "ARB2-VIS", /*caoting specification*/ "2xR<0.5%",
		/*radius first surface*/ 302.87, /*radius second surface*/ -222.27, /*radius thrid surface*/ -673.17, /*thickness first*/ 7.0,
		/*thickness second*/ 6.0, /*tolerance center thickness*/ 0.2,/*material first*/glasses.getNBK7_S1(), /*material second*/ glasses.getNSF5_S1(),
		/*price*/ 320.00);

	mQ_G322232000.buildLensThreeSurfaces_Qioptiq_lenses(/*lenscatalog*/ "Qioptiq", /*catalog number*/"G322232000", /*diameter*/ 63.0,
		/*focallength*/ 800.0, /*optical centering accurancy*/ 2.0, /*surface quality*/ "5x0.4", /*edge thickness*/ 11.5, /*back focal length*/ 796.93,
		/*min wavelength*/450.0, /*max wavelength*/ 700.0, /*coating*/ "ARB2-VIS", /*caoting specification*/ "2xR<0.5%",
		/*radius first surface*/ 486.97, /*radius second surface*/ -354.81, /*radius thrid surface*/ -1074.6, /*thickness first*/ 7.5,
		/*thickness second*/ 5.5, /*tolerance center thickness*/ 0.2,/*material first*/glasses.getNBK7_S1(), /*material second*/ glasses.getNSF5_S1(),
		/*price*/ 320.00);

	mQ_G322267000.buildLensThreeSurfaces_Qioptiq_lenses(/*lenscatalog*/ "Qioptiq", /*catalog number*/"G322267000", /*diameter*/ 80.0,
		/*focallength*/ 160.0, /*optical centering accurancy*/ 4.0, /*surface quality*/ "5x0.4", /*edge thickness*/ 18.8, /*back focal length*/ 144.45,
		/*min wavelength*/450.0, /*max wavelength*/ 700.0, /*coating*/ "ARB2-VIS", /*caoting specification*/ "2xR<0.5%",
		/*radius first surface*/ 104.41, /*radius second surface*/ -81.166, /*radius thrid surface*/ -365.17, /*thickness first*/ 22.0,
		/*thickness second*/ 7.0, /*tolerance center thickness*/ 0.2,/*material first*/glasses.getNSK2_S1(), /*material second*/ glasses.getNSF10_S1(),
		/*price*/ 428.00);

	mQ_G322278000.buildLensThreeSurfaces_Qioptiq_lenses(/*lenscatalog*/ "Qioptiq", /*catalog number*/"G322278000", /*diameter*/ 80.0,
		/*focallength*/ 310.0, /*optical centering accurancy*/ 3.0, /*surface quality*/ "5x0.4", /*edge thickness*/ 12.3, /*back focal length*/ 301.5,
		/*min wavelength*/450.0, /*max wavelength*/ 700.0, /*coating*/ "ARB2-VIS", /*caoting specification*/ "2xR<0.5%",
		/*radius first surface*/ 188.36, /*radius second surface*/ -139.24, /*radius thrid surface*/ -415.67, /*thickness first*/ 12.25,
		/*thickness second*/ 6.0, /*tolerance center thickness*/ 0.2,/*material first*/glasses.getNBK7_S1(), /*material second*/ glasses.getNSF5_S1(),
		/*price*/ 428.00);

	mQ_G322279000.buildLensThreeSurfaces_Qioptiq_lenses(/*lenscatalog*/ "Qioptiq", /*catalog number*/"G322279000", /*diameter*/ 80.0,
		/*focallength*/ 500.0, /*optical centering accurancy*/ 2.0, /*surface quality*/ "5x0.4", /*edge thickness*/ 12.2, /*back focal length*/ 493.2,
		/*min wavelength*/450.0, /*max wavelength*/ 700.0, /*coating*/ "ARB2-VIS", /*caoting specification*/ "2xR<0.5%",
		/*radius first surface*/ 302.87, /*radius second surface*/ -222.27, /*radius thrid surface*/ -673.17, /*thickness first*/ 10.0,
		/*thickness second*/ 6.0, /*tolerance center thickness*/ 0.2,/*material first*/glasses.getNBK7_S1(), /*material second*/ glasses.getNSF5_S1(),
		/*price*/ 428.00);

	mQ_G322316000.buildLensThreeSurfaces_Qioptiq_lenses(/*lenscatalog*/ "Qioptiq", /*catalog number*/"G322316000", /*diameter*/ 100.0,
		/*focallength*/ 500.0, /*optical centering accurancy*/ 1.0, /*surface quality*/ "5x0.63", /*edge thickness*/ 16.0, /*back focal length*/ 488.87,
		/*min wavelength*/450.0, /*max wavelength*/ 700.0, /*coating*/ "ARB2-VIS", /*caoting specification*/ "2xR<0.5%",
		/*radius first surface*/ 302.87, /*radius second surface*/ -222.27, /*radius thrid surface*/ -668.34, /*thickness first*/ 15.0,
		/*thickness second*/ 7.0, /*tolerance center thickness*/ 0.2,/*material first*/glasses.getNBK7_S1(), /*material second*/ glasses.getNSF5_S1(),
		/*price*/ 1848.00);

	//// glasses no found
	//mQ_G322313000.buildLensThreeSurfaces_Qioptiq_lenses(/*lenscatalog*/ "Qioptiq", /*catalog number*/"G322313000", /*diameter*/ 100.0,
	//	/*focallength*/ 1000.0, /*optical centering accurancy*/ 1.0, /*surface quality*/ "5x0.63", /*edge thickness*/ 18.5, /*back focal length*/ 988.52,
	//	/*min wavelength*/450.0, /*max wavelength*/ 700.0, /*coating*/ "ARB2-VIS", /*caoting specification*/ "2xR<0.5%",
	//	/*radius first surface*/ 528.52, /*radius second surface*/ -456.43, /*radius thrid surface*/ -2083.3, /*thickness first*/ 12.25,
	//	/*thickness second*/ 9.0, /*tolerance center thickness*/ 0.2,/*material first*/glasses.getSBSL7_S1(), /*material second*/ glasses.getSTIM22_S1(),
	//	/*price*/ 1848.00);

	//// no zemax
	//// no radius, no thickness, no glasses
	//mQ_G322386000.buildLensThreeSurfaces_Qioptiq_lenses(/*lenscatalog*/ "Qioptiq", /*catalog number*/"G322386000", /*diameter*/ 150.0,
	//	/*focallength*/ 2250.0, /*optical centering accurancy*/ 1.0, /*surface quality*/ "5x0.4", /*edge thickness*/ 28.9, /*back focal length*/ 2235.93,
	//	/*min wavelength*/450.0, /*max wavelength*/ 700.0, /*coating*/ "ARB2-VIS", /*caoting specification*/ "2xR<0.5%",
	//	/*radius first surface*/ 9999.0, /*radius second surface*/ -9999.0, /*radius thrid surface*/ -99999.0, /*thickness first*/ 0.0,
	//	/*thickness second*/ 0.0, /*tolerance center thickness*/ 0.4,/*material first*/glasses.getNBAK1_S1(), /*material second*/ glasses.getNF2_S1(),
	//	/*price*/ 2710.00);
}
std::vector<LensThreeSurfaces> QioptiqLensCatalog::getAll_Achromats_VIS_Positive_from_40_mm_diameter_unmounted_N_BK7_ARB2_VIS()
{
	// https://www.qioptiq-shop.com/en/Precision-Optics/LINOS-Achromats-Lens-Systems/Achromats-positive/Achromats-VIS-Positive-from-40-mm-diameter-unmounted.html

	std::vector<LensThreeSurfaces> return_Qioptiq_Achromats_VIS_Positive_from_40_mm_diameter_unmounted_N_BK7_ARB2_VIS;
	return_Qioptiq_Achromats_VIS_Positive_from_40_mm_diameter_unmounted_N_BK7_ARB2_VIS.push_back(mQ_G322389000);
	return_Qioptiq_Achromats_VIS_Positive_from_40_mm_diameter_unmounted_N_BK7_ARB2_VIS.push_back(mQ_G322388000);
	return_Qioptiq_Achromats_VIS_Positive_from_40_mm_diameter_unmounted_N_BK7_ARB2_VIS.push_back(mQ_G322384000);
	return_Qioptiq_Achromats_VIS_Positive_from_40_mm_diameter_unmounted_N_BK7_ARB2_VIS.push_back(mQ_G322246000);
	return_Qioptiq_Achromats_VIS_Positive_from_40_mm_diameter_unmounted_N_BK7_ARB2_VIS.push_back(mQ_G322293000);
	return_Qioptiq_Achromats_VIS_Positive_from_40_mm_diameter_unmounted_N_BK7_ARB2_VIS.push_back(mQ_G322294000);
	return_Qioptiq_Achromats_VIS_Positive_from_40_mm_diameter_unmounted_N_BK7_ARB2_VIS.push_back(mQ_G322295000);
	//return_Qioptiq_Achromats_VIS_Positive_from_40_mm_diameter_unmounted_N_BK7_ARB2_VIS.push_back(mQ_G322373322);
	return_Qioptiq_Achromats_VIS_Positive_from_40_mm_diameter_unmounted_N_BK7_ARB2_VIS.push_back(mQ_G322301000);
	return_Qioptiq_Achromats_VIS_Positive_from_40_mm_diameter_unmounted_N_BK7_ARB2_VIS.push_back(mQ_G322302000);
	return_Qioptiq_Achromats_VIS_Positive_from_40_mm_diameter_unmounted_N_BK7_ARB2_VIS.push_back(mQ_G322303000);
	//return_Qioptiq_Achromats_VIS_Positive_from_40_mm_diameter_unmounted_N_BK7_ARB2_VIS.push_back(mQ_G322369322);
	return_Qioptiq_Achromats_VIS_Positive_from_40_mm_diameter_unmounted_N_BK7_ARB2_VIS.push_back(mQ_G322304000);
	return_Qioptiq_Achromats_VIS_Positive_from_40_mm_diameter_unmounted_N_BK7_ARB2_VIS.push_back(mQ_G322305000);
	return_Qioptiq_Achromats_VIS_Positive_from_40_mm_diameter_unmounted_N_BK7_ARB2_VIS.push_back(mQ_G322310000);
	return_Qioptiq_Achromats_VIS_Positive_from_40_mm_diameter_unmounted_N_BK7_ARB2_VIS.push_back(mQ_G322311000);
	return_Qioptiq_Achromats_VIS_Positive_from_40_mm_diameter_unmounted_N_BK7_ARB2_VIS.push_back(mQ_G322312000);
	return_Qioptiq_Achromats_VIS_Positive_from_40_mm_diameter_unmounted_N_BK7_ARB2_VIS.push_back(mQ_G322383000);
	return_Qioptiq_Achromats_VIS_Positive_from_40_mm_diameter_unmounted_N_BK7_ARB2_VIS.push_back(mQ_G322230000);
	return_Qioptiq_Achromats_VIS_Positive_from_40_mm_diameter_unmounted_N_BK7_ARB2_VIS.push_back(mQ_G322232000);
	return_Qioptiq_Achromats_VIS_Positive_from_40_mm_diameter_unmounted_N_BK7_ARB2_VIS.push_back(mQ_G322267000);
	return_Qioptiq_Achromats_VIS_Positive_from_40_mm_diameter_unmounted_N_BK7_ARB2_VIS.push_back(mQ_G322278000);
	return_Qioptiq_Achromats_VIS_Positive_from_40_mm_diameter_unmounted_N_BK7_ARB2_VIS.push_back(mQ_G322279000);
	return_Qioptiq_Achromats_VIS_Positive_from_40_mm_diameter_unmounted_N_BK7_ARB2_VIS.push_back(mQ_G322316000);
	//return_Qioptiq_Achromats_VIS_Positive_from_40_mm_diameter_unmounted_N_BK7_ARB2_VIS.push_back(mQ_G322313000);
	//return_Qioptiq_Achromats_VIS_Positive_from_40_mm_diameter_unmounted_N_BK7_ARB2_VIS.push_back(mQ_G322386000);



	return return_Qioptiq_Achromats_VIS_Positive_from_40_mm_diameter_unmounted_N_BK7_ARB2_VIS;
}
// ***

// *** Achromats, Negative, Unmounted, ARB2 VIS
void QioptiqLensCatalog::loadLensCatalogQioptiq_Achromats_Negative_Unmounted_ARB2_VIS()
{
	// https://www.qioptiq-shop.com/en/Precision-Optics/LINOS-Achromats-Lens-Systems/Achromats-negative/Achromats-Negative-Unmounted.html
	//// there was no Zemax file online
	//// no radius
	//// no thickness
	//// no material glasses
	//mQ_G325221000.buildLensThreeSurfaces_Qioptiq_lenses(/*lenscatalog*/ "Qioptiq", /*catalog number*/"G325221000", /*diameter*/ 18.0,
	//	/*focallength*/ -50.0, /*optical centering accurancy*/ 4.0, /*surface quality*/ "3x0.1", /*edge thickness*/ 4.7, /*back focal length*/ -52.37,
	//	/*min wavelength*/450.0, /*max wavelength*/ 700.0, /*coating*/ "ARB2-VIS", /*caoting specification*/ "2xR<0.5%",
	//	/*radius first surface*/ 0.0, /*radius second surface*/ -0.0, /*radius thrid surface*/ -0.0, /*thickness first*/ 0.0,
	//	/*thickness second*/ 0.0, /*tolerance center thickness*/ 0.2,/*material first*/glasses., /*material second*/ glasses.,
	//	/*price*/ 102.00);
}

std::vector<LensThreeSurfaces> QioptiqLensCatalog::getAll_Achromats_Negative_Unmounted_ARB2_VIS()
{
	// https://www.qioptiq-shop.com/en/Precision-Optics/LINOS-Achromats-Lens-Systems/Achromats-negative/Achromats-Negative-Unmounted.html

	std::vector<LensThreeSurfaces> return_Qioptiq_Achromats_Negative_Unmounted_ARB2_VIS{};
	// there was no Zemax file online
	return_Qioptiq_Achromats_Negative_Unmounted_ARB2_VIS.push_back(mQ_G325221000);

	return return_Qioptiq_Achromats_Negative_Unmounted_ARB2_VIS;
}
// ***

//  *** Plano-Convex lenses, unmounted, ARB2-VIS
// https://www.qioptiq-shop.com/en/Precision-Optics/Singlets/Plano-Convex-Lenses/Plano-convex-lenses-unmounted.html
LensesTwoSurfaces QioptiqLensCatalog::getQ_G312003000()
{
	return mQ_G312003000;
}
LensesTwoSurfaces QioptiqLensCatalog::getQ_G312004000()
{
	return mQ_G312004000;
}
LensesTwoSurfaces QioptiqLensCatalog::getQ_G312006000()
{
	return mQ_G312006000;
}
LensesTwoSurfaces QioptiqLensCatalog::getQ_G312007000()
{
	return mQ_G312007000;
}
LensesTwoSurfaces QioptiqLensCatalog::getQ_G312008000()
{
	return mQ_G312008000;
}
LensesTwoSurfaces QioptiqLensCatalog::getQ_G312201000()
{
	return mQ_G312201000;
}
LensesTwoSurfaces QioptiqLensCatalog::getQ_G312009000()
{
	return mQ_G312009000;
}
LensesTwoSurfaces QioptiqLensCatalog::getQ_G312010000()
{
	return mQ_G312010000;
}
LensesTwoSurfaces QioptiqLensCatalog::getQ_G312011000()
{
	return mQ_G312011000;
}
LensesTwoSurfaces QioptiqLensCatalog::getQ_G312236000()
{
	return mQ_G312236000;
}
LensesTwoSurfaces QioptiqLensCatalog::getQ_G312329000()
{
	return mQ_G312329000;
}
LensesTwoSurfaces QioptiqLensCatalog::getQ_G312330000()
{
	return mQ_G312330000;
}
LensesTwoSurfaces QioptiqLensCatalog::getQ_G312351000()
{
	return mQ_G312351000;
}
LensesTwoSurfaces QioptiqLensCatalog::getQ_G312352000()
{
	return mQ_G312352000;
}
LensesTwoSurfaces QioptiqLensCatalog::getQ_G312353000()
{
	return mQ_G312353000;
}
LensesTwoSurfaces QioptiqLensCatalog::getQ_G312354000()
{
	return mQ_G312354000;
}
LensesTwoSurfaces QioptiqLensCatalog::getQ_G312355000()
{
	return mQ_G312355000;
}
LensesTwoSurfaces QioptiqLensCatalog::getQ_G312356000()
{
	return mQ_G312356000;
}
LensesTwoSurfaces QioptiqLensCatalog::getQ_G312357000()
{
	return mQ_G312357000;
}
LensesTwoSurfaces QioptiqLensCatalog::getQ_G312358000()
{
	return mQ_G312358000;
}
LensesTwoSurfaces QioptiqLensCatalog::getQ_G312331000()
{
	return mQ_G312331000;
}
LensesTwoSurfaces QioptiqLensCatalog::getQ_G312314000()
{
	return mQ_G312314000;
}
LensesTwoSurfaces QioptiqLensCatalog::getQ_G312315000()
{
	return mQ_G312315000;
}
LensesTwoSurfaces QioptiqLensCatalog::getQ_G312316000()
{
	return mQ_G312316000;
}
LensesTwoSurfaces QioptiqLensCatalog::getQ_G312317000()
{
	return mQ_G312317000;
}
LensesTwoSurfaces QioptiqLensCatalog::getQ_G312318000()
{
	return mQ_G312318000;
}
LensesTwoSurfaces QioptiqLensCatalog::getQ_G312319000()
{
	return mQ_G312319000;
}
LensesTwoSurfaces QioptiqLensCatalog::getQ_G312320000()
{
	return mQ_G312320000;
}
LensesTwoSurfaces QioptiqLensCatalog::getQ_G312321000()
{
	return mQ_G312321000;
}
LensesTwoSurfaces QioptiqLensCatalog::getQ_G312322000()
{
	return mQ_G312322000;
}
LensesTwoSurfaces QioptiqLensCatalog::getQ_G312323000()
{
	return mQ_G312323000;
}
LensesTwoSurfaces QioptiqLensCatalog::getQ_G312324000()
{
	return mQ_G312324000;
}
LensesTwoSurfaces QioptiqLensCatalog::getQ_G312325000()
{
	return mQ_G312325000;
}
LensesTwoSurfaces QioptiqLensCatalog::getQ_G312326000()
{
	return mQ_G312326000;
}
LensesTwoSurfaces QioptiqLensCatalog::getQ_G312327000()
{
	return mQ_G312327000;
}
LensesTwoSurfaces QioptiqLensCatalog::getQ_G312328000()
{
	return mQ_G312328000;
}
LensesTwoSurfaces QioptiqLensCatalog::getQ_G312401000()
{
	return mQ_G312401000;
}
LensesTwoSurfaces QioptiqLensCatalog::getQ_G312402000()
{
	return mQ_G312402000;
}
LensesTwoSurfaces QioptiqLensCatalog::getQ_G312332000()
{
	return mQ_G312332000;
}
LensesTwoSurfaces QioptiqLensCatalog::getQ_G312403000()
{
	return mQ_G312403000;
}
LensesTwoSurfaces QioptiqLensCatalog::getQ_G312333000()
{
	return mQ_G312333000;
}
LensesTwoSurfaces QioptiqLensCatalog::getQ_G312404000()
{
	return mQ_G312404000;
}
LensesTwoSurfaces QioptiqLensCatalog::getQ_G312405000()
{
	return mQ_G312405000;
}
LensesTwoSurfaces QioptiqLensCatalog::getQ_G312406000()
{
	return mQ_G312406000;
}
LensesTwoSurfaces QioptiqLensCatalog::getQ_G312407000()
{
	return mQ_G312407000;
}
LensesTwoSurfaces QioptiqLensCatalog::getQ_G312312000()
{
	return mQ_G312312000;
}
LensesTwoSurfaces QioptiqLensCatalog::getQ_G312340000()
{
	return mQ_G312340000;
}
LensesTwoSurfaces QioptiqLensCatalog::getQ_G312350000()
{
	return mQ_G312350000;
}
LensesTwoSurfaces QioptiqLensCatalog::getQ_G312341000()
{
	return mQ_G312341000;
}
LensesTwoSurfaces QioptiqLensCatalog::getQ_G312334000()
{
	return mQ_G312334000;
}
LensesTwoSurfaces QioptiqLensCatalog::getQ_G312335000()
{
	return mQ_G312335000;
}
LensesTwoSurfaces QioptiqLensCatalog::getQ_G312361000()
{
	return mQ_G312361000;
}
LensesTwoSurfaces QioptiqLensCatalog::getQ_G312363000()
{
	return mQ_G312363000;
}
LensesTwoSurfaces QioptiqLensCatalog::getQ_G312001000()
{
	return mQ_G312001000;
}
LensesTwoSurfaces QioptiqLensCatalog::getQ_G312362000()
{
	return mQ_G312362000;
}


// *** Symmetric - convex lenses, unmounted, ARB2 VIS
// https://www.qioptiq-shop.com/en/Precision-Optics/Singlets/Symmetric-Convex-Lenses/Symmetric-convex-lenses-unmounted.html
LensesTwoSurfaces QioptiqLensCatalog::getQ_G311328000()
{
	return mQ_G311328000;
}
LensesTwoSurfaces QioptiqLensCatalog::getQ_G311329000()
{
	return mQ_G311329000;
}
LensesTwoSurfaces QioptiqLensCatalog::getQ_G311300000()
{
	return mQ_G311300000;
}
LensesTwoSurfaces QioptiqLensCatalog::getQ_G311377000()
{
	return mQ_G311377000;
}
LensesTwoSurfaces QioptiqLensCatalog::getQ_G311381000()
{
	return mQ_G311381000;
}
LensesTwoSurfaces QioptiqLensCatalog::getQ_G311382000()
{
	return mQ_G311382000;
}
LensesTwoSurfaces QioptiqLensCatalog::getQ_G311383000()
{
	return mQ_G311383000;
}
LensesTwoSurfaces QioptiqLensCatalog::getQ_G311384000()
{
	return mQ_G311384000;
}
LensesTwoSurfaces QioptiqLensCatalog::getQ_G311385000()
{
	return mQ_G311385000;
}
LensesTwoSurfaces QioptiqLensCatalog::getQ_G311386000()
{
	return mQ_G311386000;
}
LensesTwoSurfaces QioptiqLensCatalog::getQ_G311387000()
{
	return mQ_G311387000;
}
LensesTwoSurfaces QioptiqLensCatalog::getQ_G311378000()
{
	return mQ_G311378000;
}
LensesTwoSurfaces QioptiqLensCatalog::getQ_G311338000()
{
	return mQ_G311338000;
}
LensesTwoSurfaces QioptiqLensCatalog::getQ_G311308000()
{
	return mQ_G311308000;
}
LensesTwoSurfaces QioptiqLensCatalog::getQ_G311310000()
{
	return mQ_G311310000;
}
LensesTwoSurfaces QioptiqLensCatalog::getQ_G311314000()
{
	return mQ_G311314000;
}
LensesTwoSurfaces QioptiqLensCatalog::getQ_G311315000()
{
	return mQ_G311315000;
}
LensesTwoSurfaces QioptiqLensCatalog::getQ_G311316000()
{
	return mQ_G311316000;
}
LensesTwoSurfaces QioptiqLensCatalog::getQ_G311317000()
{
	return mQ_G311317000;
}
LensesTwoSurfaces QioptiqLensCatalog::getQ_G311318000()
{
	return mQ_G311318000;
}
LensesTwoSurfaces QioptiqLensCatalog::getQ_G311319000()
{
	return mQ_G311319000;
}
LensesTwoSurfaces QioptiqLensCatalog::getQ_G311320000()
{
	return mQ_G311320000;
}
LensesTwoSurfaces QioptiqLensCatalog::getQ_G311321000()
{
	return mQ_G311321000;
}
LensesTwoSurfaces QioptiqLensCatalog::getQ_G311322000()
{
	return mQ_G311322000;
}
LensesTwoSurfaces QioptiqLensCatalog::getQ_G311323000()
{
	return mQ_G311323000;
}
LensesTwoSurfaces QioptiqLensCatalog::getQ_G311324000()
{
	return mQ_G311324000;
}
LensesTwoSurfaces QioptiqLensCatalog::getQ_G311325000()
{
	return mQ_G311325000;
}
LensesTwoSurfaces QioptiqLensCatalog::getQ_G311331000()
{
	return mQ_G311331000;
}
LensesTwoSurfaces QioptiqLensCatalog::getQ_G311339000()
{
	return mQ_G311339000;
}
LensesTwoSurfaces QioptiqLensCatalog::getQ_G311351000()
{
	return mQ_G311351000;
}
LensesTwoSurfaces QioptiqLensCatalog::getQ_G311357000()
{
	return mQ_G311357000;
}
LensesTwoSurfaces QioptiqLensCatalog::getQ_G311333000()
{
	return mQ_G311333000;
}
LensesTwoSurfaces QioptiqLensCatalog::getQ_G311335000()
{
	return mQ_G311335000;
}
LensesTwoSurfaces QioptiqLensCatalog::getQ_G311347000()
{
	return mQ_G311347000;
}
LensesTwoSurfaces QioptiqLensCatalog::getQ_G311348000()
{
	return mQ_G311348000;
}
LensesTwoSurfaces QioptiqLensCatalog::getQ_G311341000()
{
	return mQ_G311341000;
}
LensesTwoSurfaces QioptiqLensCatalog::getQ_G311345000()
{
	return mQ_G311345000;
}
LensesTwoSurfaces QioptiqLensCatalog::getQ_G311346000()
{
	return mQ_G311346000;
}


// *** Plano - concave lenses, unmounted (N - BK7), ARB2 VIS
// https://www.qioptiq-shop.com/en/Precision-Optics/Singlets/Plano-Concave-Lenses/Plano-concave-lenses-unmounted-N-BK7.html
LensesTwoSurfaces QioptiqLensCatalog::getQ_G314001000()
{
	return mQ_G314001000;
}
LensesTwoSurfaces QioptiqLensCatalog::getQ_G314304000()
{
	return mQ_G314304000;
}
LensesTwoSurfaces QioptiqLensCatalog::getQ_G314002000()
{
	return mQ_G314002000;
}
LensesTwoSurfaces QioptiqLensCatalog::getQ_G314003000()
{
	return mQ_G314003000;
}
LensesTwoSurfaces QioptiqLensCatalog::getQ_G314005000()
{
	return mQ_G314005000;
}
LensesTwoSurfaces QioptiqLensCatalog::getQ_G314331000()
{
	return mQ_G314331000;
}
LensesTwoSurfaces QioptiqLensCatalog::getQ_G314332000()
{
	return mQ_G314332000;
}
LensesTwoSurfaces QioptiqLensCatalog::getQ_G314333000()
{
	return mQ_G314333000;
}
LensesTwoSurfaces QioptiqLensCatalog::getQ_G314334000()
{
	return mQ_G314334000;
}
LensesTwoSurfaces QioptiqLensCatalog::getQ_G314335000()
{
	return mQ_G314335000;
}
LensesTwoSurfaces QioptiqLensCatalog::getQ_G314301000()
{
	return mQ_G314301000;
}
LensesTwoSurfaces QioptiqLensCatalog::getQ_G314315000()
{
	return mQ_G314315000;
}
LensesTwoSurfaces QioptiqLensCatalog::getQ_G314316000()
{
	return mQ_G314316000;
}
LensesTwoSurfaces QioptiqLensCatalog::getQ_G314317000()
{
	return mQ_G314317000;
}
LensesTwoSurfaces QioptiqLensCatalog::getQ_G314321000()
{
	return mQ_G314321000;
}
LensesTwoSurfaces QioptiqLensCatalog::getQ_G314322000()
{
	return mQ_G314322000;
}
LensesTwoSurfaces QioptiqLensCatalog::getQ_G314323000()
{
	return mQ_G314323000;
}
LensesTwoSurfaces QioptiqLensCatalog::getQ_G314324000()
{
	return mQ_G314324000;
}
LensesTwoSurfaces QioptiqLensCatalog::getQ_G314325000()
{
	return mQ_G314325000;
}


// *** Symmetric - concave lenses, unmounted (N - BK7), ARB2 VIS
// https://www.qioptiq-shop.com/en/Precision-Optics/Singlets/Symmetric-Concave-Lenses/Symmetric-concave-lenses-unmounted-N-BK7.html
LensesTwoSurfaces QioptiqLensCatalog::getQ_G313210000()
{
	return mQ_G313210000;
}
LensesTwoSurfaces QioptiqLensCatalog::getQ_G313373000()
{
	return mQ_G313373000;
}
LensesTwoSurfaces QioptiqLensCatalog::getQ_G313374000()
{
	return mQ_G313374000;
}
LensesTwoSurfaces QioptiqLensCatalog::getQ_G313375000()
{
	return mQ_G313375000;
}
LensesTwoSurfaces QioptiqLensCatalog::getQ_G313376000()
{
	return mQ_G313376000;
}
LensesTwoSurfaces QioptiqLensCatalog::getQ_G313205000()
{
	return mQ_G313205000;
}
LensesTwoSurfaces QioptiqLensCatalog::getQ_G313206000()
{
	return mQ_G313206000;
}
LensesTwoSurfaces QioptiqLensCatalog::getQ_G313214000()
{
	return mQ_G313214000;
}
LensesTwoSurfaces QioptiqLensCatalog::getQ_G313215000()
{
	return mQ_G313215000;
}
LensesTwoSurfaces QioptiqLensCatalog::getQ_G313216000()
{
	return mQ_G313216000;
}
LensesTwoSurfaces QioptiqLensCatalog::getQ_G313217000()
{
	return mQ_G313217000;
}
LensesTwoSurfaces QioptiqLensCatalog::getQ_G313337000()
{
	return mQ_G313337000;
}
LensesTwoSurfaces QioptiqLensCatalog::getQ_G313339000()
{
	return mQ_G313339000;
}
LensesTwoSurfaces QioptiqLensCatalog::getQ_G313249000()
{
	return mQ_G313249000;
}

// *** Achromats VIS, Positive, dia. 3 mm to 31.5 mm, unmounted, ARB2 VIS
// https://www.qioptiq-shop.com/en/Precision-Optics/LINOS-Achromats-Lens-Systems/Achromats-positive/Achromats-VIS-Positive-dia-3-mm-to-31-5-mm-unmounted.html
LensThreeSurfaces QioptiqLensCatalog::getQ_G322218000()
{
	return mQ_G322218000;
}
LensThreeSurfaces QioptiqLensCatalog::getQ_G322219000()
{
	return mQ_G322219000;
}
LensThreeSurfaces QioptiqLensCatalog::getQ_G322250000()
{
	return mQ_G322250000;
}
LensThreeSurfaces QioptiqLensCatalog::getQ_G322220000()
{
	return mQ_G322220000;
}
LensThreeSurfaces QioptiqLensCatalog::getQ_G322206000()
{
	return mQ_G322206000;
}
LensThreeSurfaces QioptiqLensCatalog::getQ_G322222000()
{
	return mQ_G322222000;
}
LensThreeSurfaces QioptiqLensCatalog::getQ_G322223000()
{
	return mQ_G322223000;
}
LensThreeSurfaces QioptiqLensCatalog::getQ_G322207000()
{
	return mQ_G322207000;
}
LensThreeSurfaces QioptiqLensCatalog::getQ_G322356322()
{
	return mQ_G322356322;
}
LensThreeSurfaces QioptiqLensCatalog::getQ_G322357322()
{
	return mQ_G322357322;
}
LensThreeSurfaces QioptiqLensCatalog::getQ_G322358322()
{
	return mQ_G322358322;
}
LensThreeSurfaces QioptiqLensCatalog::getQ_G322359322()
{
	return mQ_G322359322;
}
LensThreeSurfaces QioptiqLensCatalog::getQ_G322360322()
{
	return mQ_G322360322;
}
//LensThreeSurfaces QioptiqLensCatalog::getQ_G322361322()
//{
//	return mQ_G322361322;
//}
LensThreeSurfaces QioptiqLensCatalog::getQ_G322362322()
{
	return mQ_G322362322;
}
LensThreeSurfaces QioptiqLensCatalog::getQ_G322363322()
{
	return mQ_G322363322;
}
LensThreeSurfaces QioptiqLensCatalog::getQ_G322364322()
{
	return mQ_G322364322;
}
//LensThreeSurfaces QioptiqLensCatalog::getQ_G322365322()
//{
//	return mQ_G322365322;
//}
LensThreeSurfaces QioptiqLensCatalog::getQ_G322366322()
{
	return mQ_G322366322;
}
LensThreeSurfaces QioptiqLensCatalog::getQ_G322367322()
{
	return mQ_G322367322;
}
LensThreeSurfaces QioptiqLensCatalog::getQ_G322368322()
{
	return mQ_G322368322;
}
LensThreeSurfaces QioptiqLensCatalog::getQ_G322201000()
{
	return mQ_G322201000;
}
LensThreeSurfaces QioptiqLensCatalog::getQ_G322284000()
{
	return mQ_G322284000;
}
LensThreeSurfaces QioptiqLensCatalog::getQ_G322285000()
{
	return mQ_G322285000;
}
LensThreeSurfaces QioptiqLensCatalog::getQ_G322286000()
{
	return mQ_G322286000;
}
LensThreeSurfaces QioptiqLensCatalog::getQ_G322337000()
{
	return mQ_G322337000;
}
LensThreeSurfaces QioptiqLensCatalog::getQ_G322338000()
{
	return mQ_G322338000;
}
LensThreeSurfaces QioptiqLensCatalog::getQ_G322339000()
{
	return mQ_G322339000;
}
LensThreeSurfaces QioptiqLensCatalog::getQ_G322341000()
{
	return mQ_G322341000;
}
LensThreeSurfaces QioptiqLensCatalog::getQ_G322343000()
{
	return mQ_G322343000;
}
LensThreeSurfaces QioptiqLensCatalog::getQ_G322345000()
{
	return mQ_G322345000;
}
LensThreeSurfaces QioptiqLensCatalog::getQ_G322320322()
{
	return mQ_G322320322;
}
LensThreeSurfaces QioptiqLensCatalog::getQ_G322325322()
{
	return mQ_G322325322;
}
LensThreeSurfaces QioptiqLensCatalog::getQ_G322327322()
{
	return mQ_G322327322;
}
//LensThreeSurfaces QioptiqLensCatalog::getQ_G322209000()
//{
//	return mQ_G322209000;
//}
LensThreeSurfaces QioptiqLensCatalog::getQ_G322265000()
{
	return mQ_G322265000;
}
LensThreeSurfaces QioptiqLensCatalog::getQ_G322266000()
{
	return mQ_G322266000;
}
LensThreeSurfaces QioptiqLensCatalog::getQ_G322210000()
{
	return mQ_G322210000;
}
LensThreeSurfaces QioptiqLensCatalog::getQ_G322236000()
{
	return mQ_G322236000;
}
LensThreeSurfaces QioptiqLensCatalog::getQ_G322331322()
{
	return mQ_G322331322;
}
LensThreeSurfaces QioptiqLensCatalog::getQ_G322332322()
{
	return mQ_G322332322;
}
LensThreeSurfaces QioptiqLensCatalog::getQ_G322322000()
{
	return mQ_G322322000;
}
LensThreeSurfaces QioptiqLensCatalog::getQ_G322323000()
{
	return mQ_G322323000;
}
LensThreeSurfaces QioptiqLensCatalog::getQ_G322324000()
{
	return mQ_G322324000;
}
LensThreeSurfaces QioptiqLensCatalog::getQ_G322326000()
{
	return mQ_G322326000;
}
LensThreeSurfaces QioptiqLensCatalog::getQ_G322333322()
{
	return mQ_G322333322;
}
LensThreeSurfaces QioptiqLensCatalog::getQ_G322328000()
{
	return mQ_G322328000;
}
LensThreeSurfaces QioptiqLensCatalog::getQ_G322334322()
{
	return mQ_G322334322;
}
LensThreeSurfaces QioptiqLensCatalog::getQ_G322329000()
{
	return mQ_G322329000;
}
LensThreeSurfaces QioptiqLensCatalog::getQ_G322306322()
{
	return mQ_G322306322;
}
LensThreeSurfaces QioptiqLensCatalog::getQ_G322307322()
{
	return mQ_G322307322;
}
LensThreeSurfaces QioptiqLensCatalog::getQ_G322308322()
{
	return mQ_G322308322;
}
LensThreeSurfaces QioptiqLensCatalog::getQ_G322309322()
{
	return mQ_G322309322;
}
LensThreeSurfaces QioptiqLensCatalog::getQ_G322351000()
{
	return mQ_G322351000;
}
LensThreeSurfaces QioptiqLensCatalog::getQ_G322352000()
{
	return mQ_G322352000;
}
LensThreeSurfaces QioptiqLensCatalog::getQ_G322353000()
{
	return mQ_G322353000;
}
LensThreeSurfaces QioptiqLensCatalog::getQ_G322336322()
{
	return mQ_G322336322;
}
LensThreeSurfaces QioptiqLensCatalog::getQ_G322340322()
{
	return mQ_G322340322;
}
LensThreeSurfaces QioptiqLensCatalog::getQ_G322355000()
{
	return mQ_G322355000;
}
LensThreeSurfaces QioptiqLensCatalog::getQ_G322287322()
{
	return mQ_G322287322;
}
LensThreeSurfaces QioptiqLensCatalog::getQ_G322288322()
{
	return mQ_G322288322;
}
LensThreeSurfaces QioptiqLensCatalog::getQ_G322269322()
{
	return mQ_G322269322;
}
LensThreeSurfaces QioptiqLensCatalog::getQ_G322239322()
{
	return mQ_G322239322;
}
LensThreeSurfaces QioptiqLensCatalog::getQ_G322227322()
{
	return mQ_G322227322;
}
LensThreeSurfaces QioptiqLensCatalog::getQ_G322270322()
{
	return mQ_G322270322;
}
LensThreeSurfaces QioptiqLensCatalog::getQ_G322342322()
{
	return mQ_G322342322;
}
LensThreeSurfaces QioptiqLensCatalog::getQ_G322271322()
{
	return mQ_G322271322;
}
LensThreeSurfaces QioptiqLensCatalog::getQ_G322272322()
{
	return mQ_G322272322;
}
LensThreeSurfaces QioptiqLensCatalog::getQ_G322273322()
{
	return mQ_G322273322;
}
LensThreeSurfaces QioptiqLensCatalog::getQ_G322275322()
{
	return mQ_G322275322;
}
//LensThreeSurfaces QioptiqLensCatalog::getQ_G322277322()
//{
//	return mQ_G322277322;
//}


// *** Achromats VIS, Positive from 40 mm diameter, unmounted, ARB2 VIS
// https://www.qioptiq-shop.com/en/Precision-Optics/LINOS-Achromats-Lens-Systems/Achromats-positive/Achromats-VIS-Positive-from-40-mm-diameter-unmounted.html
LensThreeSurfaces QioptiqLensCatalog::getQ_G322389000()
{
	return mQ_G322389000;
}
LensThreeSurfaces QioptiqLensCatalog::getQ_G322388000()
{
	return mQ_G322388000;
}
LensThreeSurfaces QioptiqLensCatalog::getQ_G322384000()
{
	return mQ_G322384000;
}
LensThreeSurfaces QioptiqLensCatalog::getQ_G322246000()
{
	return mQ_G322246000;
}
LensThreeSurfaces QioptiqLensCatalog::getQ_G322293000()
{
	return mQ_G322293000;
}
LensThreeSurfaces QioptiqLensCatalog::getQ_G322294000()
{
	return mQ_G322294000;
}
LensThreeSurfaces QioptiqLensCatalog::getQ_G322295000()
{
	return mQ_G322295000;
}
//LensThreeSurfaces QioptiqLensCatalog::getQ_G322373322()
//{
//	return mQ_G322373322;
//}
LensThreeSurfaces QioptiqLensCatalog::getQ_G322301000()
{
	return mQ_G322301000;
}
LensThreeSurfaces QioptiqLensCatalog::getQ_G322302000()
{
	return mQ_G322302000;
}
LensThreeSurfaces QioptiqLensCatalog::getQ_G322303000()
{
	return mQ_G322303000;
}
//LensThreeSurfaces QioptiqLensCatalog::getQ_G322369322()
//{
//	return mQ_G322369322;
//}
LensThreeSurfaces QioptiqLensCatalog::getQ_G322304000()
{
	return mQ_G322304000;
}
LensThreeSurfaces QioptiqLensCatalog::getQ_G322305000()
{
	return mQ_G322305000;
}
LensThreeSurfaces QioptiqLensCatalog::getQ_G322310000()
{
	return mQ_G322310000;
}
LensThreeSurfaces QioptiqLensCatalog::getQ_G322311000()
{
	return mQ_G322311000;
}
LensThreeSurfaces QioptiqLensCatalog::getQ_G322312000()
{
	return mQ_G322312000;
}
LensThreeSurfaces QioptiqLensCatalog::getQ_G322383000()
{
	return mQ_G322383000;
}
LensThreeSurfaces QioptiqLensCatalog::getQ_G322230000()
{
	return mQ_G322230000;
}
LensThreeSurfaces QioptiqLensCatalog::getQ_G322232000()
{
	return mQ_G322232000;
}
LensThreeSurfaces QioptiqLensCatalog::getQ_G322267000()
{
	return mQ_G322267000;
}
LensThreeSurfaces QioptiqLensCatalog::getQ_G322278000()
{
	return mQ_G322278000;
}
LensThreeSurfaces QioptiqLensCatalog::getQ_G322279000()
{
	return mQ_G322279000;
}
LensThreeSurfaces QioptiqLensCatalog::getQ_G322316000()
{
	return mQ_G322316000;
}
//LensThreeSurfaces QioptiqLensCatalog::getQ_G322313000()
//{
//	return mQ_G322313000;
//}
//LensThreeSurfaces QioptiqLensCatalog::getQ_G322386000()
//{
//	return mQ_G322386000;
//}

// *** Achromats VIS, Negativ from 40 mm diameter, unmounted, ARB2 VIS
// https://www.qioptiq-shop.com/en/Precision-Optics/LINOS-Achromats-Lens-Systems/Achromats-negative/Achromats-Negative-Unmounted.html
LensThreeSurfaces QioptiqLensCatalog::getQ_G325221000()
{
	return mQ_G325221000;
}
