#pragma once //https://www.edmundoptics.de/f/vis-nir-coated-double-concave-dcv-lenses/13540/
#include "..\..\Glasses\Glasses.h"
#include "..\..\LensElements\LensesThreeSurfaces.h"
#include "..\..\LensElements\LensesFourSurfaces.h"

class EdmundOpticsLensCatalog
{
public:
	EdmundOpticsLensCatalog();
	~EdmundOpticsLensCatalog();

	// load the lens catalog from Edmund Optics
	void loadLensCatalogEO_double_convex_lenses(); //https://www.edmundoptics.de/f/vis-nir-coated-double-convex-dcx-lenses/13504/
	std::vector<LensesTwoSurfaces> getAll_DoubleConvexLenses();

	void loadLensCatalogEO_achroamticLensesMgF(); //https://www.edmundoptics.de/f/mgfsub2sub-coated-achromatic-lenses/12006/
	std::vector<LensThreeSurfaces> getAll_achroamticLensesMgF();

	void loadLensCatalogEO_plan_convex_lenses_VIS_NIR(); //https://www.edmundoptics.de/f/vis-nir-coated-plano-convex-pcx-lenses/12278/
	std::vector<LensesTwoSurfaces> getAll_PlanConvexLenses();

	void loadLensCatalogEO_double_concav_lenses_VIS_NIR();  //https://www.edmundoptics.de/f/vis-nir-coated-double-concave-dcv-lenses/13540/
	std::vector<LensesTwoSurfaces> getAll_DoubleConcavLenses();

	void loadLensCatalogEO_plan_concav_lenses_VIS_NIR(); //https://www.edmundoptics.de/f/vis-nir-coated-plano-concave-pcv-lenses/13512/
	std::vector<LensesTwoSurfaces> getAll_PlanConcavLenses();

	// Doppelkonkave Linsen (DCV) mit NIR-I-Beschichtung
	void loadLensCatalogEO_double_concav_lenses_NIR_I(); //https://www.edmundoptics.de/f/nir-i-coated-double-concave-dcv-lenses/13500/
	// *** ACHTUNG: mach das dann lieber am Schluss
	 // Comment CR: Das sind im eigentlich die Linsen von "double_concav_lenses_VIS_NIR" (https://www.edmundoptics.de/f/vis-nir-coated-double-concave-dcv-lenses/13540/) nur
	// mit einer anderen Beschichtung. Denke von den Parametern kannst du einige von dort kopieren. Das Coating musst du immer anpassen (siehe Beipiel). Auch die minimale 
	// und maxiamle Wellenlänge verändert sich hier. 
	std::vector<LensesTwoSurfaces> getAll_LensCatalogEO_double_concav_lenses_NIR_I();

	// Achromate mit VIS-NIR-Beschichtung 
	// *** ACHTUNG: mach das dann lieber am Schluss
	// *** da müsstest du vieles von loadLensCatalogEO_achroamticLensesMgF kopieren können, die Beschichtung ist dann halt immer ne andere (vielleicht hilft dir das) ***//
	void loadLensCatalogEO_achroamticLenses_VIS_NIR_Coating(); //https://www.edmundoptics.de/f/vis-nir-coated-achromatic-lenses/13536/
	std::vector<LensThreeSurfaces> getAll_LensCatalogEO_achroamticLenses_VIS_NIR_Coating();

	// Broadband AR Coated Negative Achromatic Lenses
	void loadLensCatalogEO_Broadband_AR_Coated_Negative_Achromatic_Lenses(); // https://www.edmundoptics.de/f/broadband-ar-coated-negative-achromatic-lenses/13623/
	std::vector<LensThreeSurfaces> getAll_LensCatalogEO_Broadband_AR_Coated_Negative_Achromatic_Lenses();

	// Large Precision Achromatic Lenses -> No Airspace
	void loadLensCatalogEO_Large_Precision_Achromatic_Lenses_NoAirspace(); // https://www.edmundoptics.de/f/large-precision-achromatic-lenses/11679/
	std::vector<LensThreeSurfaces> getAll_LensCatalogEO_Large_Precision_Achromatic_Lenses_NoAirspace();


	// Large Precision Achromatic Lenses -> Airspace 0.1mm
	void loadLensCatalogEO_Large_Precision_Achromatic_Lenses_Airspace01mm(); // https://www.edmundoptics.de/f/large-precision-achromatic-lenses/11679/
	std::vector<LensFourSurfaces> getAll_LensCatalogEO_Large_Precision_Achromatic_Lenses_Airspace01mm();

	// Hastings Triplet Achromatic Lenses 
	void loadLensCatalogEO_Hastings_Triplet_Achromatic_Lenses(); // https://www.edmundoptics.de/f/hastings-triplet-achromatic-lenses/11968/
	std::vector<LensFourSurfaces> getAll_LensCatalogEO_Hastings_Triplet_Achromatic_Lenses();

	// Steinheil Triplet Achromatic Lenses 
	void loadLensCatalogEO_Steinheil_Triplet_Achromatic_Lenses(); // https://www.edmundoptics.de/f/steinheil-triplet-achromatic-lenses/12275/
	std::vector<LensFourSurfaces> getAll_LensCatalogEO_Steinheil_Triplet_Achromatic_Lenses();

	// Micro Plano-Convex (PCX) Lenses 
	void loadLensCatalogEO_Micro_Plano_Convex_PCX_Lenses(); // https://www.edmundoptics.de/f/micro-plano-convex-pcx-lenses/39529/
	std::vector<LensesTwoSurfaces> getAll_Micro_Plano_Convex_PCX_Lenses();

	// Large PCX Condenser Lenses
	void loadLensCatalogEO_Large_PCX_Condenser_Lenses(); // https://www.edmundoptics.de/f/large-pcx-condenser-lenses/13572/
	std::vector<LensesTwoSurfaces> getAll_Large_PCX_Condenser_Lenses();

	// Large PCX Condenser Lenses
	// https://www.edmundoptics.de/f/large-pcx-condenser-lenses/13572/
	LensesTwoSurfaces getEO67187();


	// Micro Plano-Convex (PCX) Lenses 
	// https://www.edmundoptics.de/f/micro-plano-convex-pcx-lenses/39529/
	LensesTwoSurfaces getEO45951();

	// Steinheil Triplet Achromatic Lenses 
	// https://www.edmundoptics.de/f/steinheil-triplet-achromatic-lenses/12275/
	LensFourSurfaces getEO47673();

	// Hastings Triplet Achromatic Lenses 
	// https://www.edmundoptics.de/f/hastings-triplet-achromatic-lenses/11968/
	LensFourSurfaces getEO13521();

	// Large Precision Achromatic Lenses -> No Airspace
	// https://www.edmundoptics.de/f/large-precision-achromatic-lenses/11679/
	LensThreeSurfaces getEO31402();


	// Large Precision Achromatic Lenses -> Airspace 0.1mm
	// https://www.edmundoptics.de/f/large-precision-achromatic-lenses/11679/
	LensFourSurfaces getEO30976();


	// Broadband AR Coated Negative Achromatic Lenses
	// https://www.edmundoptics.de/f/broadband-ar-coated-negative-achromatic-lenses/13623/
	LensThreeSurfaces getEO62478();


	// get VIS-NIR beschichtete PCV Linsen
	// https://www.edmundoptics.de/f/vis-nir-coated-plano-concave-pcv-lenses/13512/
	LensesTwoSurfaces getEO84380();
	LensesTwoSurfaces getEO84381();
	LensesTwoSurfaces getEO45910();
	LensesTwoSurfaces getEO48345();
	LensesTwoSurfaces getEO45911();
	LensesTwoSurfaces getEO48696();
	LensesTwoSurfaces getEO45912();
	LensesTwoSurfaces getEO45913();
	LensesTwoSurfaces getEO48346();
	LensesTwoSurfaces getEO45914();
	LensesTwoSurfaces getEO45915();
	LensesTwoSurfaces getEO45916();
	LensesTwoSurfaces getEO48697();
	LensesTwoSurfaces getEO48347();
	LensesTwoSurfaces getEO45917();
	LensesTwoSurfaces getEO45918();
	LensesTwoSurfaces getEO45919();
	LensesTwoSurfaces getEO45920();
	LensesTwoSurfaces getEO45921();
	LensesTwoSurfaces getEO45922();
	LensesTwoSurfaces getEO48698();
	LensesTwoSurfaces getEO45923();
	LensesTwoSurfaces getEO45924();
	LensesTwoSurfaces getEO45925();
	LensesTwoSurfaces getEO45926();




	// get Doppelkonkave (DCV) Linsen VIS-NIR AR beschichtet
	// https://www.edmundoptics.de/f/vis-nir-coated-double-concave-dcv-lenses/13540/
	LensesTwoSurfaces getEO45927();
	LensesTwoSurfaces getEO48941();
	LensesTwoSurfaces getEO48699();
	LensesTwoSurfaces getEO48348();
	LensesTwoSurfaces getEO48942();
	LensesTwoSurfaces getEO48700();
	LensesTwoSurfaces getEO45928();
	LensesTwoSurfaces getEO48943();
	LensesTwoSurfaces getEO48701();
	LensesTwoSurfaces getEO45929();
	LensesTwoSurfaces getEO45930();
	LensesTwoSurfaces getEO45931();
	LensesTwoSurfaces getEO45932();


	// get VIS-NIR beschichtete PCX Linsen
	// https://www.edmundoptics.de/f/vis-nir-coated-plano-convex-pcx-lenses/12278/
	LensesTwoSurfaces getEO65289();
	LensesTwoSurfaces getEO65290();
	LensesTwoSurfaces getEO65291();
	LensesTwoSurfaces getEO65292();
	LensesTwoSurfaces getEO65293();
	LensesTwoSurfaces getEO65294();
	LensesTwoSurfaces getEO65295();
	LensesTwoSurfaces getEO65296();
	LensesTwoSurfaces getEO65297();
	LensesTwoSurfaces getEO65298();
	LensesTwoSurfaces getEO65299();
	LensesTwoSurfaces getEO65300();
	LensesTwoSurfaces getEO65301();
	LensesTwoSurfaces getEO65302();
	LensesTwoSurfaces getEO65303();
	LensesTwoSurfaces getEO65304();
	LensesTwoSurfaces getEO49174();
	LensesTwoSurfaces getEO49175();
	LensesTwoSurfaces getEO49176();
	LensesTwoSurfaces getEO49177();
	LensesTwoSurfaces getEO49178();
	LensesTwoSurfaces getEO49179();
	LensesTwoSurfaces getEO49180();
	LensesTwoSurfaces getEO47850();
	LensesTwoSurfaces getEO47851();
	LensesTwoSurfaces getEO47852();
	LensesTwoSurfaces getEO47853();
	LensesTwoSurfaces getEO47854();
	LensesTwoSurfaces getEO47855();
	LensesTwoSurfaces getEO47856();
	LensesTwoSurfaces getEO47857();
	LensesTwoSurfaces getEO48661();
	LensesTwoSurfaces getEO47858();
	LensesTwoSurfaces getEO47859();
	LensesTwoSurfaces getEO47860();
	LensesTwoSurfaces getEO49913();
	LensesTwoSurfaces getEO87917();
	LensesTwoSurfaces getEO87918();
	LensesTwoSurfaces getEO45465();
	LensesTwoSurfaces getEO49914();
	LensesTwoSurfaces getEO45466();
	LensesTwoSurfaces getEO38483();
	LensesTwoSurfaces getEO45467();
	LensesTwoSurfaces getEO45468();
	LensesTwoSurfaces getEO45469();
	LensesTwoSurfaces getEO38484();
	LensesTwoSurfaces getEO45470();
	LensesTwoSurfaces getEO45471();
	LensesTwoSurfaces getEO38485();
	LensesTwoSurfaces getEO45472();
	LensesTwoSurfaces getEO45473();
	LensesTwoSurfaces getEO47381();
	LensesTwoSurfaces getEO67178();
	LensesTwoSurfaces getEO45696();
	LensesTwoSurfaces getEO45474();
	LensesTwoSurfaces getEO49915();
	LensesTwoSurfaces getEO45475();
	LensesTwoSurfaces getEO49916();
	LensesTwoSurfaces getEO45476();
	LensesTwoSurfaces getEO38487();
	LensesTwoSurfaces getEO45477();
	LensesTwoSurfaces getEO38488();
	LensesTwoSurfaces getEO45478();
	LensesTwoSurfaces getEO45479();
	LensesTwoSurfaces getEO45703();
	LensesTwoSurfaces getEO67179();
	LensesTwoSurfaces getEO67180();
	LensesTwoSurfaces getEO67181();
	LensesTwoSurfaces getEO38486();
	LensesTwoSurfaces getEO63519();
	LensesTwoSurfaces getEO63520();
	LensesTwoSurfaces getEO63521();
	LensesTwoSurfaces getEO63522();
	LensesTwoSurfaces getEO63523();
	LensesTwoSurfaces getEO63524();
	LensesTwoSurfaces getEO63525();
	LensesTwoSurfaces getEO63526();
	LensesTwoSurfaces getEO63527();
	LensesTwoSurfaces getEO45480();
	LensesTwoSurfaces getEO45481();
	LensesTwoSurfaces getEO45482();
	LensesTwoSurfaces getEO49917();
	LensesTwoSurfaces getEO45483();
	LensesTwoSurfaces getEO45484();
	LensesTwoSurfaces getEO33355();
	LensesTwoSurfaces getEO45485();
	LensesTwoSurfaces getEO45486();
	LensesTwoSurfaces getEO45487();
	LensesTwoSurfaces getEO45488();
	LensesTwoSurfaces getEO45705();
	LensesTwoSurfaces getEO45489();
	LensesTwoSurfaces getEO45490();
	LensesTwoSurfaces getEO38501();
	LensesTwoSurfaces getEO38506();
	LensesTwoSurfaces getEO62591();
	LensesTwoSurfaces getEO62592();
	LensesTwoSurfaces getEO62593();
	LensesTwoSurfaces getEO38515();
	LensesTwoSurfaces getEO62594();
	LensesTwoSurfaces getEO38516();
	LensesTwoSurfaces getEO62595();
	LensesTwoSurfaces getEO62596();
	LensesTwoSurfaces getEO38517();
	LensesTwoSurfaces getEO62597();
	LensesTwoSurfaces getEO62598();
	LensesTwoSurfaces getEO45491();
	LensesTwoSurfaces getEO49918();
	LensesTwoSurfaces getEO63528();
	LensesTwoSurfaces getEO45492();
	LensesTwoSurfaces getEO45493();
	LensesTwoSurfaces getEO45494();
	LensesTwoSurfaces getEO49919();
	LensesTwoSurfaces getEO47382();
	LensesTwoSurfaces getEO47383();
	LensesTwoSurfaces getEO45706();
	LensesTwoSurfaces getEO48426();
	LensesTwoSurfaces getEO45496();
	LensesTwoSurfaces getEO45497();
	LensesTwoSurfaces getEO45498();
	LensesTwoSurfaces getEO45499();
	LensesTwoSurfaces getEO49921();
	LensesTwoSurfaces getEO45707();
	LensesTwoSurfaces getEO49922();
	LensesTwoSurfaces getEO45500();
	LensesTwoSurfaces getEO45501();
	LensesTwoSurfaces getEO45502();
	LensesTwoSurfaces getEO45503();
	LensesTwoSurfaces getEO47385();
	LensesTwoSurfaces getEO45708();
	LensesTwoSurfaces getEO47386();
	LensesTwoSurfaces getEO45504();
	LensesTwoSurfaces getEO45505();
	LensesTwoSurfaces getEO45506();
	LensesTwoSurfaces getEO45507();
	LensesTwoSurfaces getEO45508();
	LensesTwoSurfaces getEO45509();
	LensesTwoSurfaces getEO45510();
	LensesTwoSurfaces getEO45511();
	LensesTwoSurfaces getEO45512();
	LensesTwoSurfaces getEO45513();
	LensesTwoSurfaces getEO45514();
	LensesTwoSurfaces getEO45515();
	LensesTwoSurfaces getEO33361();
	LensesTwoSurfaces getEO67182();
	LensesTwoSurfaces getEO67183();
	LensesTwoSurfaces getEO33367();
	LensesTwoSurfaces getEO47387();
	LensesTwoSurfaces getEO47388();
	LensesTwoSurfaces getEO62599();
	LensesTwoSurfaces getEO62600();
	LensesTwoSurfaces getEO62601();
	LensesTwoSurfaces getEO62602();
	LensesTwoSurfaces getEO62603();
	LensesTwoSurfaces getEO62604();
	LensesTwoSurfaces getEO62605();
	LensesTwoSurfaces getEO48662();
	LensesTwoSurfaces getEO67184();
	LensesTwoSurfaces getEO45709();
	LensesTwoSurfaces getEO47389();
	LensesTwoSurfaces getEO45710();
	LensesTwoSurfaces getEO45711();
	LensesTwoSurfaces getEO47390();
	LensesTwoSurfaces getEO48663();
	LensesTwoSurfaces getEO45712();
	LensesTwoSurfaces getEO33385();
	LensesTwoSurfaces getEO33373();
	LensesTwoSurfaces getEO33379();
	LensesTwoSurfaces getEO47391();
	LensesTwoSurfaces getEO47392();
	LensesTwoSurfaces getEO45715();
	LensesTwoSurfaces getEO45716();
	LensesTwoSurfaces getEO45717();
	LensesTwoSurfaces getEO47393();
	LensesTwoSurfaces getEO45718();
	LensesTwoSurfaces getEO47394();
	LensesTwoSurfaces getEO47395();
	LensesTwoSurfaces getEO47396();
	LensesTwoSurfaces getEO47397();
	LensesTwoSurfaces getEO86911();
	LensesTwoSurfaces getEO86912();
	LensesTwoSurfaces getEO86913();
	LensesTwoSurfaces getEO86914();
	LensesTwoSurfaces getEO86915();
	LensesTwoSurfaces getEO38489();
	LensesTwoSurfaces getEO38492();
	LensesTwoSurfaces getEO38494();
	LensesTwoSurfaces getEO38496();
	LensesTwoSurfaces getEO38499();
	LensesTwoSurfaces getEO38500();
	LensesTwoSurfaces getEO38503();
	LensesTwoSurfaces getEO38504();
	LensesTwoSurfaces getEO38505();
	LensesTwoSurfaces getEO38507();
	LensesTwoSurfaces getEO38508();
	LensesTwoSurfaces getEO38509();
	LensesTwoSurfaces getEO38510();
	LensesTwoSurfaces getEO38512();
	LensesTwoSurfaces getEO38518();
	LensesTwoSurfaces getEO38519();
	LensesTwoSurfaces getEO38520();
	LensesTwoSurfaces getEO38521();
	LensesTwoSurfaces getEO38522();
	LensesTwoSurfaces getEO38523();
	LensesTwoSurfaces getEO38524();
	LensesTwoSurfaces getEO38525();
	LensesTwoSurfaces getEO38542();
	LensesTwoSurfaces getEO38543();
	LensesTwoSurfaces getEO38544();
	LensesTwoSurfaces getEO38545();
	LensesTwoSurfaces getEO38547();
	LensesTwoSurfaces getEO38548();
	LensesTwoSurfaces getEO38552();
	LensesTwoSurfaces getEO38561();
	LensesTwoSurfaces getEO38567();




	// get double convex lenses from Edmund Optics
	// Link: https://www.edmundoptics.de/f/VIS-NIR-Coated-Double-Convex-DCX-Lenses/13504/
	LensesTwoSurfaces getEO49447();
	LensesTwoSurfaces getEO49448();
	LensesTwoSurfaces getEO49449();
	LensesTwoSurfaces getEO49450();
	LensesTwoSurfaces getEO47893();
	LensesTwoSurfaces getEO47894();
	LensesTwoSurfaces getEO63658();
	LensesTwoSurfaces getEO63659();
	LensesTwoSurfaces getEO63660();
	LensesTwoSurfaces getEO63661();
	LensesTwoSurfaces getEO63662();
	LensesTwoSurfaces getEO45859();
	LensesTwoSurfaces getEO45860();
	LensesTwoSurfaces getEO45861();
	LensesTwoSurfaces getEO45862();
	LensesTwoSurfaces getEO45863();
	LensesTwoSurfaces getEO45864();
	LensesTwoSurfaces getEO45865();
	LensesTwoSurfaces getEO45866();
	LensesTwoSurfaces getEO45867();
	LensesTwoSurfaces getEO45868();
	LensesTwoSurfaces getEO45869();
	LensesTwoSurfaces getEO45870();
	LensesTwoSurfaces getEO45871();
	LensesTwoSurfaces getEO63663();
	LensesTwoSurfaces getEO63664();
	LensesTwoSurfaces getEO63665();
	LensesTwoSurfaces getEO63666();
	LensesTwoSurfaces getEO63667();
	LensesTwoSurfaces getEO63668();
	LensesTwoSurfaces getEO63669();
	LensesTwoSurfaces getEO63670();
	LensesTwoSurfaces getEO45872();
	LensesTwoSurfaces getEO45873();
	LensesTwoSurfaces getEO33391();
	LensesTwoSurfaces getEO45875();
	LensesTwoSurfaces getEO45876();
	LensesTwoSurfaces getEO45877();
	LensesTwoSurfaces getEO45878();
	LensesTwoSurfaces getEO45879();
	LensesTwoSurfaces getEO63671();
	LensesTwoSurfaces getEO45880();
	LensesTwoSurfaces getEO63672();
	LensesTwoSurfaces getEO45881();
	LensesTwoSurfaces getEO63673();
	LensesTwoSurfaces getEO45882();
	LensesTwoSurfaces getEO63674();
	LensesTwoSurfaces getEO63675();
	LensesTwoSurfaces getEO45883();
	LensesTwoSurfaces getEO45884();
	LensesTwoSurfaces getEO63678();
	LensesTwoSurfaces getEO63679();
	LensesTwoSurfaces getEO45885();
	LensesTwoSurfaces getEO45886();
	LensesTwoSurfaces getEO63680();
	LensesTwoSurfaces getEO63681();
	LensesTwoSurfaces getEO63682();
	LensesTwoSurfaces getEO45887();
	LensesTwoSurfaces getEO63683();
	LensesTwoSurfaces getEO45888();
	LensesTwoSurfaces getEO45889();
	LensesTwoSurfaces getEO45890();
	LensesTwoSurfaces getEO45891();
	LensesTwoSurfaces getEO45892();
	LensesTwoSurfaces getEO45893();
	LensesTwoSurfaces getEO45894();
	LensesTwoSurfaces getEO45895();
	LensesTwoSurfaces getEO33397();
	LensesTwoSurfaces getEO63684();
	LensesTwoSurfaces getEO45898();
	LensesTwoSurfaces getEO63685();
	LensesTwoSurfaces getEO45899();
	LensesTwoSurfaces getEO63686();
	LensesTwoSurfaces getEO63687();
	LensesTwoSurfaces getEO63688();
	LensesTwoSurfaces getEO45900();
	LensesTwoSurfaces getEO33422();
	LensesTwoSurfaces getEO33409();
	LensesTwoSurfaces getEO63689();
	LensesTwoSurfaces getEO33416();
	LensesTwoSurfaces getEO45905();
	LensesTwoSurfaces getEO45906();
	LensesTwoSurfaces getEO45907();
	LensesTwoSurfaces getEO45908();
	LensesTwoSurfaces getEO45909();

	// get achromatic lenses from edmund optics
	// https://www.edmundoptics.de/f/MgFsub2sub-Coated-Achromatic-Lenses/12006/
	LensThreeSurfaces getEO65564();
	LensThreeSurfaces getEO65565();
	LensThreeSurfaces getEO65566();
	LensThreeSurfaces getEO65567();
	LensThreeSurfaces getEO65568();
	LensThreeSurfaces getEO65569();
	LensThreeSurfaces getEO83338();
	LensThreeSurfaces getEO83339();
	LensThreeSurfaces getEO45262();
	LensThreeSurfaces getEO47721();
	LensThreeSurfaces getEO45089();
	LensThreeSurfaces getEO45090();
	LensThreeSurfaces getEO63690();
	LensThreeSurfaces getEO63691();
	LensThreeSurfaces getEO63692();
	LensThreeSurfaces getEO45205();
	LensThreeSurfaces getEO45206();
	LensThreeSurfaces getEO49923();
	LensThreeSurfaces getEO45207();
	LensThreeSurfaces getEO45408();
	LensThreeSurfaces getEO45407();
	LensThreeSurfaces getEO49924();
	LensThreeSurfaces getEO45208();
	LensThreeSurfaces getEO32299();
	LensThreeSurfaces getEO32301();
	LensThreeSurfaces getEO49925();
	LensThreeSurfaces getEO32303();
	LensThreeSurfaces getEO32305();
	LensThreeSurfaces getEO45135();
	LensThreeSurfaces getEO32307();
	LensThreeSurfaces getEO45173();
	LensThreeSurfaces getEO45263();
	LensThreeSurfaces getEO45345();
	LensThreeSurfaces getEO65549();
	LensThreeSurfaces getEO45346();
	LensThreeSurfaces getEO49926();
	LensThreeSurfaces getEO45091();
	LensThreeSurfaces getEO49927();
	LensThreeSurfaces getEO45092();
	LensThreeSurfaces getEO45264();
	LensThreeSurfaces getEO45818();
	LensThreeSurfaces getEO45347();
	LensThreeSurfaces getEO45819();
	LensThreeSurfaces getEO45820();
	LensThreeSurfaces getEO63693();
	LensThreeSurfaces getEO63694();
	LensThreeSurfaces getEO63695();
	LensThreeSurfaces getEO63696();
	LensThreeSurfaces getEO63697();
	LensThreeSurfaces getEO63698();
	LensThreeSurfaces getEO63699();
	LensThreeSurfaces getEO65550();
	LensThreeSurfaces getEO45209();
	LensThreeSurfaces getEO63700();
	LensThreeSurfaces getEO49928();
	LensThreeSurfaces getEO32309();
	LensThreeSurfaces getEO32311();
	LensThreeSurfaces getEO32313();
	LensThreeSurfaces getEO45210();
	LensThreeSurfaces getEO32315();
	LensThreeSurfaces getEO45136();
	LensThreeSurfaces getEO32317();
	LensThreeSurfaces getEO45137();
	LensThreeSurfaces getEO32882();
	LensThreeSurfaces getEO45409();
	LensThreeSurfaces getEO45410();
	LensThreeSurfaces getEO45265();
	LensThreeSurfaces getEO49758();
	LensThreeSurfaces getEO49759();
	LensThreeSurfaces getEO49760();
	LensThreeSurfaces getEO49761();
	LensThreeSurfaces getEO49762();
	LensThreeSurfaces getEO49763();
	LensThreeSurfaces getEO49764();
	LensThreeSurfaces getEO83415();
	LensThreeSurfaces getEO65551();
	LensThreeSurfaces getEO49929();
	LensThreeSurfaces getEO45174();
	LensThreeSurfaces getEO32720();
	LensThreeSurfaces getEO45103();
	LensThreeSurfaces getEO45138();
	LensThreeSurfaces getEO49930();
	LensThreeSurfaces getEO45139();
	LensThreeSurfaces getEO45266();
	LensThreeSurfaces getEO49931();
	LensThreeSurfaces getEO45412();
	LensThreeSurfaces getEO45348();
	LensThreeSurfaces getEO45413();
	LensThreeSurfaces getEO45104();
	LensThreeSurfaces getEO32913();
	LensThreeSurfaces getEO45349();
	LensThreeSurfaces getEO45350();
	LensThreeSurfaces getEO32915();
	LensThreeSurfaces getEO65552();
	LensThreeSurfaces getEO49932();
	LensThreeSurfaces getEO45175();
	LensThreeSurfaces getEO45351();
	LensThreeSurfaces getEO32722();
	LensThreeSurfaces getEO49933();
	LensThreeSurfaces getEO45267();
	LensThreeSurfaces getEO49934();
	LensThreeSurfaces getEO65553();
	LensThreeSurfaces getEO45211();
	LensThreeSurfaces getEO32319();
	LensThreeSurfaces getEO32321();
	LensThreeSurfaces getEO45212();
	LensThreeSurfaces getEO32323();
	LensThreeSurfaces getEO32724();
	LensThreeSurfaces getEO32325();
	LensThreeSurfaces getEO45213();
	LensThreeSurfaces getEO32327();
	LensThreeSurfaces getEO32492();
	LensThreeSurfaces getEO32494();
	LensThreeSurfaces getEO67328();
	LensThreeSurfaces getEO32884();
	LensThreeSurfaces getEO32917();
	LensThreeSurfaces getEO45214();
	LensThreeSurfaces getEO32919();
	LensThreeSurfaces getEO45414();
	LensThreeSurfaces getEO45215();
	LensThreeSurfaces getEO45216();
	LensThreeSurfaces getEO45268();
	LensThreeSurfaces getEO67329();
	LensThreeSurfaces getEO49765();
	LensThreeSurfaces getEO49766();
	LensThreeSurfaces getEO49767();
	LensThreeSurfaces getEO49768();
	LensThreeSurfaces getEO49769();
	LensThreeSurfaces getEO49770();
	LensThreeSurfaces getEO33917();
	LensThreeSurfaces getEO32500();
	LensThreeSurfaces getEO45217();
	LensThreeSurfaces getEO32502();
	LensThreeSurfaces getEO45415();
	LensThreeSurfaces getEO45269();
	LensThreeSurfaces getEO32496();
	LensThreeSurfaces getEO45140();
	LensThreeSurfaces getEO32498();
	LensThreeSurfaces getEO89681();
	LensThreeSurfaces getEO45218();
	LensThreeSurfaces getEO45105();
	LensThreeSurfaces getEO63701();
	LensThreeSurfaces getEO32921();
	LensThreeSurfaces getEO32923();
	LensThreeSurfaces getEO32925();
	LensThreeSurfaces getEO32935();
	LensThreeSurfaces getEO45178();
	LensThreeSurfaces getEO32927();
	LensThreeSurfaces getEO45352();
	LensThreeSurfaces getEO45270();
	LensThreeSurfaces getEO67330();
	LensThreeSurfaces getEO49291();
	LensThreeSurfaces getEO45353();
	LensThreeSurfaces getEO32886();
	LensThreeSurfaces getEO45179();
	LensThreeSurfaces getEO45180();
	LensThreeSurfaces getEO45181();
	LensThreeSurfaces getEO45354();
	LensThreeSurfaces getEO45271();
	LensThreeSurfaces getEO33918();
	LensThreeSurfaces getEO33919();
	LensThreeSurfaces getEO45417();
	LensThreeSurfaces getEO45418();
	LensThreeSurfaces getEO45419();


	// Doppelkonkave Linsen (DCV) mit NIR-I-Beschichtung
	//https://www.edmundoptics.de/f/nir-i-coated-double-concave-dcv-lenses/13500/
	LensesTwoSurfaces getEO49540();

	// Achromate mit VIS-NIR-Beschichtung 
	//https://www.edmundoptics.de/f/vis-nir-coated-achromatic-lenses/13536/
	LensThreeSurfaces getEO84127();

private:

	glass mGlasses{};
	
	// Large Precision Achromatic Lenses -> No Airespace
	// https://www.edmundoptics.de/f/large-precision-achromatic-lenses/11679/
	LensThreeSurfaces EO31402{};

	// Large Precision Achromatic Lenses -> Airspace 0.1mm
	// https://www.edmundoptics.de/f/large-precision-achromatic-lenses/11679/
	LensFourSurfaces EO30976{};

	// Broadband AR Coated Negative Achromatic Lenses
	// https://www.edmundoptics.de/f/broadband-ar-coated-negative-achromatic-lenses/13623/
	LensThreeSurfaces EO62478{};

	// get VIS-NIR beschichtete PCV Linsen
	// https://www.edmundoptics.de/f/vis-nir-coated-plano-concave-pcv-lenses/13512/
	LensesTwoSurfaces EO84380{};
	LensesTwoSurfaces EO84381{};
	LensesTwoSurfaces EO45910{};
	LensesTwoSurfaces EO48345{};
	LensesTwoSurfaces EO45911{};
	LensesTwoSurfaces EO48696{};
	LensesTwoSurfaces EO45912{};
	LensesTwoSurfaces EO45913{};
	LensesTwoSurfaces EO48346{};
	LensesTwoSurfaces EO45914{};
	LensesTwoSurfaces EO45915{};
	LensesTwoSurfaces EO45916{};
	LensesTwoSurfaces EO48697{};
	LensesTwoSurfaces EO48347{};
	LensesTwoSurfaces EO45917{};
	LensesTwoSurfaces EO45918{};
	LensesTwoSurfaces EO45919{};
	LensesTwoSurfaces EO45920{};
	LensesTwoSurfaces EO45921{};
	LensesTwoSurfaces EO45922{};
	LensesTwoSurfaces EO48698{};
	LensesTwoSurfaces EO45923{};
	LensesTwoSurfaces EO45924{};
	LensesTwoSurfaces EO45925{};
	LensesTwoSurfaces EO45926{};



	// Doppelkonkave (DCV) Linsen VIS-NIR AR beschichtet 
	// https://www.edmundoptics.de/f/vis-nir-coated-double-concave-dcv-lenses/13540/
	LensesTwoSurfaces EO45927{};
	LensesTwoSurfaces EO48941{};
	LensesTwoSurfaces EO48699{};
	LensesTwoSurfaces EO48348{};
	LensesTwoSurfaces EO48942{};
	LensesTwoSurfaces EO48700{};
	LensesTwoSurfaces EO45928{};
	LensesTwoSurfaces EO48943{};
	LensesTwoSurfaces EO48701{};
	LensesTwoSurfaces EO45929{};
	LensesTwoSurfaces EO45930{};
	LensesTwoSurfaces EO45931{};
	LensesTwoSurfaces EO45932{};




	// VIS-NIR beschichtete PCX Linsen 
	LensesTwoSurfaces EO65289{};
	LensesTwoSurfaces EO65290{};
	LensesTwoSurfaces EO65291{};
	LensesTwoSurfaces EO65292{};
	LensesTwoSurfaces EO65293{};
	LensesTwoSurfaces EO65294{};
	LensesTwoSurfaces EO65295{};
	LensesTwoSurfaces EO65296{};
	LensesTwoSurfaces EO65297{};
	LensesTwoSurfaces EO65298{};
	LensesTwoSurfaces EO65299{};
	LensesTwoSurfaces EO65300{};
	LensesTwoSurfaces EO65301{};
	LensesTwoSurfaces EO65302{};
	LensesTwoSurfaces EO65303{};
	LensesTwoSurfaces EO65304{};
	LensesTwoSurfaces EO49174{};
	LensesTwoSurfaces EO49175{};
	LensesTwoSurfaces EO49176{};
	LensesTwoSurfaces EO49177{};
	LensesTwoSurfaces EO49178{};
	LensesTwoSurfaces EO49179{};
	LensesTwoSurfaces EO49180{};
	LensesTwoSurfaces EO47850{};
	LensesTwoSurfaces EO47851{};
	LensesTwoSurfaces EO47852{};
	LensesTwoSurfaces EO47853{};
	LensesTwoSurfaces EO47854{};
	LensesTwoSurfaces EO47855{};
	LensesTwoSurfaces EO47856{};
	LensesTwoSurfaces EO47857{};
	LensesTwoSurfaces EO48661{};
	LensesTwoSurfaces EO47858{};
	LensesTwoSurfaces EO47859{};
	LensesTwoSurfaces EO47860{};
	LensesTwoSurfaces EO49913{};
	LensesTwoSurfaces EO87917{};
	LensesTwoSurfaces EO87918{};
	LensesTwoSurfaces EO45465{};
	LensesTwoSurfaces EO49914{};
	LensesTwoSurfaces EO45466{};
	LensesTwoSurfaces EO38483{};
	LensesTwoSurfaces EO45467{};
	LensesTwoSurfaces EO45468{};
	LensesTwoSurfaces EO45469{};
	LensesTwoSurfaces EO38484{};
	LensesTwoSurfaces EO45470{};
	LensesTwoSurfaces EO45471{};
	LensesTwoSurfaces EO38485{};
	LensesTwoSurfaces EO45472{};
	LensesTwoSurfaces EO45473{};
	LensesTwoSurfaces EO47381{};
	LensesTwoSurfaces EO67178{};
	LensesTwoSurfaces EO45696{};
	LensesTwoSurfaces EO45474{};
	LensesTwoSurfaces EO49915{};
	LensesTwoSurfaces EO45475{};
	LensesTwoSurfaces EO49916{};
	LensesTwoSurfaces EO45476{};
	LensesTwoSurfaces EO38487{};
	LensesTwoSurfaces EO45477{};
	LensesTwoSurfaces EO38488{};
	LensesTwoSurfaces EO45478{};
	LensesTwoSurfaces EO45479{};
	LensesTwoSurfaces EO45703{};
	LensesTwoSurfaces EO67179{};
	LensesTwoSurfaces EO67180{};
	LensesTwoSurfaces EO67181{};
	LensesTwoSurfaces EO38486{};
	LensesTwoSurfaces EO63519{};
	LensesTwoSurfaces EO63520{};
	LensesTwoSurfaces EO63521{};
	LensesTwoSurfaces EO63522{};
	LensesTwoSurfaces EO63523{};
	LensesTwoSurfaces EO63524{};
	LensesTwoSurfaces EO63525{};
	LensesTwoSurfaces EO63526{};
	LensesTwoSurfaces EO63527{};
	LensesTwoSurfaces EO45480{};
	LensesTwoSurfaces EO45481{};
	LensesTwoSurfaces EO45482{};
	LensesTwoSurfaces EO49917{};
	LensesTwoSurfaces EO45483{};
	LensesTwoSurfaces EO45484{};
	LensesTwoSurfaces EO33355{};
	LensesTwoSurfaces EO45485{};
	LensesTwoSurfaces EO45486{};
	LensesTwoSurfaces EO45487{};
	LensesTwoSurfaces EO45488{};
	LensesTwoSurfaces EO45705{};
	LensesTwoSurfaces EO45489{};
	LensesTwoSurfaces EO45490{};
	LensesTwoSurfaces EO38501{};
	LensesTwoSurfaces EO38506{};
	LensesTwoSurfaces EO62591{};
	LensesTwoSurfaces EO62592{};
	LensesTwoSurfaces EO62593{};
	LensesTwoSurfaces EO38515{};
	LensesTwoSurfaces EO62594{};
	LensesTwoSurfaces EO38516{};
	LensesTwoSurfaces EO62595{};
	LensesTwoSurfaces EO62596{};
	LensesTwoSurfaces EO38517{};
	LensesTwoSurfaces EO62597{};
	LensesTwoSurfaces EO62598{};
	LensesTwoSurfaces EO45491{};
	LensesTwoSurfaces EO49918{};
	LensesTwoSurfaces EO63528{};
	LensesTwoSurfaces EO45492{};
	LensesTwoSurfaces EO45493{};
	LensesTwoSurfaces EO45494{};
	LensesTwoSurfaces EO49919{};
	LensesTwoSurfaces EO47382{};
	LensesTwoSurfaces EO47383{};
	LensesTwoSurfaces EO45706{};
	LensesTwoSurfaces EO48426{};
	LensesTwoSurfaces EO45496{};
	LensesTwoSurfaces EO45497{};
	LensesTwoSurfaces EO45498{};
	LensesTwoSurfaces EO45499{};
	LensesTwoSurfaces EO49921{};
	LensesTwoSurfaces EO45707{};
	LensesTwoSurfaces EO49922{};
	LensesTwoSurfaces EO45500{};
	LensesTwoSurfaces EO45501{};
	LensesTwoSurfaces EO45502{};
	LensesTwoSurfaces EO45503{};
	LensesTwoSurfaces EO47385{};
	LensesTwoSurfaces EO45708{};
	LensesTwoSurfaces EO47386{};
	LensesTwoSurfaces EO45504{};
	LensesTwoSurfaces EO45505{};
	LensesTwoSurfaces EO45506{};
	LensesTwoSurfaces EO45507{};
	LensesTwoSurfaces EO45508{};
	LensesTwoSurfaces EO45509{};
	LensesTwoSurfaces EO45510{};
	LensesTwoSurfaces EO45511{};
	LensesTwoSurfaces EO45512{};
	LensesTwoSurfaces EO45513{};
	LensesTwoSurfaces EO45514{};
	LensesTwoSurfaces EO45515{};
	LensesTwoSurfaces EO33361{};
	LensesTwoSurfaces EO67182{};
	LensesTwoSurfaces EO67183{};
	LensesTwoSurfaces EO33367{};
	LensesTwoSurfaces EO47387{};
	LensesTwoSurfaces EO47388{};
	LensesTwoSurfaces EO62599{};
	LensesTwoSurfaces EO62600{};
	LensesTwoSurfaces EO62601{};
	LensesTwoSurfaces EO62602{};
	LensesTwoSurfaces EO62603{};
	LensesTwoSurfaces EO62604{};
	LensesTwoSurfaces EO62605{};
	LensesTwoSurfaces EO48662{};
	LensesTwoSurfaces EO67184{};
	LensesTwoSurfaces EO45709{};
	LensesTwoSurfaces EO47389{};
	LensesTwoSurfaces EO45710{};
	LensesTwoSurfaces EO45711{};
	LensesTwoSurfaces EO47390{};
	LensesTwoSurfaces EO48663{};
	LensesTwoSurfaces EO45712{};
	LensesTwoSurfaces EO33385{};
	LensesTwoSurfaces EO33373{};
	LensesTwoSurfaces EO33379{};
	LensesTwoSurfaces EO47391{};
	LensesTwoSurfaces EO47392{};
	LensesTwoSurfaces EO45715{};
	LensesTwoSurfaces EO45716{};
	LensesTwoSurfaces EO45717{};
	LensesTwoSurfaces EO47393{};
	LensesTwoSurfaces EO45718{};
	LensesTwoSurfaces EO47394{};
	LensesTwoSurfaces EO47395{};
	LensesTwoSurfaces EO47396{};
	LensesTwoSurfaces EO47397{};
	LensesTwoSurfaces EO86911{};
	LensesTwoSurfaces EO86912{};
	LensesTwoSurfaces EO86913{};
	LensesTwoSurfaces EO86914{};
	LensesTwoSurfaces EO86915{};
	LensesTwoSurfaces EO38489{};
	LensesTwoSurfaces EO38492{};
	LensesTwoSurfaces EO38494{};
	LensesTwoSurfaces EO38496{};
	LensesTwoSurfaces EO38499{};
	LensesTwoSurfaces EO38500{};
	LensesTwoSurfaces EO38503{};
	LensesTwoSurfaces EO38504{};
	LensesTwoSurfaces EO38505{};
	LensesTwoSurfaces EO38507{};
	LensesTwoSurfaces EO38508{};
	LensesTwoSurfaces EO38509{};
	LensesTwoSurfaces EO38510{};
	LensesTwoSurfaces EO38512{};
	LensesTwoSurfaces EO38518{};
	LensesTwoSurfaces EO38519{};
	LensesTwoSurfaces EO38520{};
	LensesTwoSurfaces EO38521{};
	LensesTwoSurfaces EO38522{};
	LensesTwoSurfaces EO38523{};
	LensesTwoSurfaces EO38524{};
	LensesTwoSurfaces EO38525{};
	LensesTwoSurfaces EO38542{};
	LensesTwoSurfaces EO38543{};
	LensesTwoSurfaces EO38544{};
	LensesTwoSurfaces EO38545{};
	LensesTwoSurfaces EO38547{};
	LensesTwoSurfaces EO38548{};
	LensesTwoSurfaces EO38552{};
	LensesTwoSurfaces EO38561{};
	LensesTwoSurfaces EO38567{};




	// double convex lenses
	LensesTwoSurfaces EO49447{};
	LensesTwoSurfaces EO49448{};
	LensesTwoSurfaces EO49449{};
	LensesTwoSurfaces EO49450{};
	LensesTwoSurfaces EO47893{};
	LensesTwoSurfaces EO47894{};
	LensesTwoSurfaces EO63658{};
	LensesTwoSurfaces EO63659{};
	LensesTwoSurfaces EO63660{};
	LensesTwoSurfaces EO63661{};
	LensesTwoSurfaces EO63662{};
	LensesTwoSurfaces EO45859{};
	LensesTwoSurfaces EO45860{};
	LensesTwoSurfaces EO45861{};
	LensesTwoSurfaces EO45862{};
	LensesTwoSurfaces EO45863{};
	LensesTwoSurfaces EO45864{};
	LensesTwoSurfaces EO45865{};
	LensesTwoSurfaces EO45866{};
	LensesTwoSurfaces EO45867{};
	LensesTwoSurfaces EO45868{};
	LensesTwoSurfaces EO45869{};
	LensesTwoSurfaces EO45870{};
	LensesTwoSurfaces EO45871{};
	LensesTwoSurfaces EO63663{};
	LensesTwoSurfaces EO63664{};
	LensesTwoSurfaces EO63665{};
	LensesTwoSurfaces EO63666{};
	LensesTwoSurfaces EO63667{};
	LensesTwoSurfaces EO63668{};
	LensesTwoSurfaces EO63669{};
	LensesTwoSurfaces EO63670{};
	LensesTwoSurfaces EO45872{};
	LensesTwoSurfaces EO45873{};
	LensesTwoSurfaces EO33391{};
	LensesTwoSurfaces EO45875{};
	LensesTwoSurfaces EO45876{};
	LensesTwoSurfaces EO45877{};
	LensesTwoSurfaces EO45878{};
	LensesTwoSurfaces EO45879{};
	LensesTwoSurfaces EO63671{};
	LensesTwoSurfaces EO45880{};
	LensesTwoSurfaces EO63672{};
	LensesTwoSurfaces EO45881{};
	LensesTwoSurfaces EO63673{};
	LensesTwoSurfaces EO45882{};
	LensesTwoSurfaces EO63674{};
	LensesTwoSurfaces EO63675{};
	LensesTwoSurfaces EO45883{};
	LensesTwoSurfaces EO45884{};
	LensesTwoSurfaces EO63678{};
	LensesTwoSurfaces EO63679{};
	LensesTwoSurfaces EO45885{};
	LensesTwoSurfaces EO45886{};
	LensesTwoSurfaces EO63680{};
	LensesTwoSurfaces EO63681{};
	LensesTwoSurfaces EO63682{};
	LensesTwoSurfaces EO45887{};
	LensesTwoSurfaces EO63683{};
	LensesTwoSurfaces EO45888{};
	LensesTwoSurfaces EO45889{};
	LensesTwoSurfaces EO45890{};
	LensesTwoSurfaces EO45891{};
	LensesTwoSurfaces EO45892{};
	LensesTwoSurfaces EO45893{};
	LensesTwoSurfaces EO45894{};
	LensesTwoSurfaces EO45895{};
	LensesTwoSurfaces EO33397{};
	LensesTwoSurfaces EO63684{};
	LensesTwoSurfaces EO45898{};
	LensesTwoSurfaces EO63685{};
	LensesTwoSurfaces EO45899{};
	LensesTwoSurfaces EO63686{};
	LensesTwoSurfaces EO63687{};
	LensesTwoSurfaces EO63688{};
	LensesTwoSurfaces EO45900{};
	LensesTwoSurfaces EO33422{};
	LensesTwoSurfaces EO33409{};
	LensesTwoSurfaces EO63689{};
	LensesTwoSurfaces EO33416{};
	LensesTwoSurfaces EO45905{};
	LensesTwoSurfaces EO45906{};
	LensesTwoSurfaces EO45907{};
	LensesTwoSurfaces EO45908{};
	LensesTwoSurfaces EO45909{};

	// achromatic lenses
	LensThreeSurfaces EO65564{};
	LensThreeSurfaces EO65565{};
	LensThreeSurfaces EO65566{};
	LensThreeSurfaces EO65567{};
	LensThreeSurfaces EO65568{};
	LensThreeSurfaces EO65569{};
	LensThreeSurfaces EO83338{};
	LensThreeSurfaces EO83339{};
	LensThreeSurfaces EO45262{};
	LensThreeSurfaces EO47721{};
	LensThreeSurfaces EO45089{};
	LensThreeSurfaces EO45090{};
	LensThreeSurfaces EO63690{};
	LensThreeSurfaces EO63691{};
	LensThreeSurfaces EO63692{};
	LensThreeSurfaces EO45205{};
	LensThreeSurfaces EO45206{};
	LensThreeSurfaces EO49923{};
	LensThreeSurfaces EO45207{};
	LensThreeSurfaces EO45408{};
	LensThreeSurfaces EO45407{};
	LensThreeSurfaces EO49924{};
	LensThreeSurfaces EO45208{};
	LensThreeSurfaces EO32299{};
	LensThreeSurfaces EO32301{};
	LensThreeSurfaces EO49925{};
	LensThreeSurfaces EO32303{};
	LensThreeSurfaces EO32305{};
	LensThreeSurfaces EO45135{};
	LensThreeSurfaces EO32307{};
	LensThreeSurfaces EO45173{};
	LensThreeSurfaces EO45263{};
	LensThreeSurfaces EO45345{};
	LensThreeSurfaces EO65549{};
	LensThreeSurfaces EO45346{};
	LensThreeSurfaces EO49926{};
	LensThreeSurfaces EO45091{};
	LensThreeSurfaces EO49927{};
	LensThreeSurfaces EO45092{};
	LensThreeSurfaces EO45264{};
	LensThreeSurfaces EO45818{};
	LensThreeSurfaces EO45347{};
	LensThreeSurfaces EO45819{};
	LensThreeSurfaces EO45820{};
	LensThreeSurfaces EO63693{};
	LensThreeSurfaces EO63694{};
	LensThreeSurfaces EO63695{};
	LensThreeSurfaces EO63696{};
	LensThreeSurfaces EO63697{};
	LensThreeSurfaces EO63698{};
	LensThreeSurfaces EO63699{};
	LensThreeSurfaces EO65550{};
	LensThreeSurfaces EO45209{};
	LensThreeSurfaces EO63700{};
	LensThreeSurfaces EO49928{};
	LensThreeSurfaces EO32309{};
	LensThreeSurfaces EO32311{};
	LensThreeSurfaces EO32313{};
	LensThreeSurfaces EO45210{};
	LensThreeSurfaces EO32315{};
	LensThreeSurfaces EO45136{};
	LensThreeSurfaces EO32317{};
	LensThreeSurfaces EO45137{};
	LensThreeSurfaces EO32882{};
	LensThreeSurfaces EO45409{};
	LensThreeSurfaces EO45410{};
	LensThreeSurfaces EO45265{};
	LensThreeSurfaces EO49758{};
	LensThreeSurfaces EO49759{};
	LensThreeSurfaces EO49760{};
	LensThreeSurfaces EO49761{};
	LensThreeSurfaces EO49762{};
	LensThreeSurfaces EO49763{};
	LensThreeSurfaces EO49764{};
	LensThreeSurfaces EO83415{};
	LensThreeSurfaces EO65551{};
	LensThreeSurfaces EO49929{};
	LensThreeSurfaces EO45174{};
	LensThreeSurfaces EO32720{};
	LensThreeSurfaces EO45103{};
	LensThreeSurfaces EO45138{};
	LensThreeSurfaces EO49930{};
	LensThreeSurfaces EO45139{};
	LensThreeSurfaces EO45266{};
	LensThreeSurfaces EO49931{};
	LensThreeSurfaces EO45412{};
	LensThreeSurfaces EO45348{};
	LensThreeSurfaces EO45413{};
	LensThreeSurfaces EO45104{};
	LensThreeSurfaces EO32913{};
	LensThreeSurfaces EO45349{};
	LensThreeSurfaces EO45350{};
	LensThreeSurfaces EO32915{};
	LensThreeSurfaces EO65552{};
	LensThreeSurfaces EO49932{};
	LensThreeSurfaces EO45175{};
	LensThreeSurfaces EO45351{};
	LensThreeSurfaces EO32722{};
	LensThreeSurfaces EO49933{};
	LensThreeSurfaces EO45267{};
	LensThreeSurfaces EO49934{};
	LensThreeSurfaces EO65553{};
	LensThreeSurfaces EO45211{};
	LensThreeSurfaces EO32319{};
	LensThreeSurfaces EO32321{};
	LensThreeSurfaces EO45212{};
	LensThreeSurfaces EO32323{};
	LensThreeSurfaces EO32724{};
	LensThreeSurfaces EO32325{};
	LensThreeSurfaces EO45213{};
	LensThreeSurfaces EO32327{};
	LensThreeSurfaces EO32492{};
	LensThreeSurfaces EO32494{};
	LensThreeSurfaces EO67328{};
	LensThreeSurfaces EO32884{};
	LensThreeSurfaces EO32917{};
	LensThreeSurfaces EO45214{};
	LensThreeSurfaces EO32919{};
	LensThreeSurfaces EO45414{};
	LensThreeSurfaces EO45215{};
	LensThreeSurfaces EO45216{};
	LensThreeSurfaces EO45268{};
	LensThreeSurfaces EO67329{};
	LensThreeSurfaces EO49765{};
	LensThreeSurfaces EO49766{};
	LensThreeSurfaces EO49767{};
	LensThreeSurfaces EO49768{};
	LensThreeSurfaces EO49769{};
	LensThreeSurfaces EO49770{};
	LensThreeSurfaces EO33917{};
	LensThreeSurfaces EO32500{};
	LensThreeSurfaces EO45217{};
	LensThreeSurfaces EO32502{};
	LensThreeSurfaces EO45415{};
	LensThreeSurfaces EO45269{};
	LensThreeSurfaces EO32496{};
	LensThreeSurfaces EO45140{};
	LensThreeSurfaces EO32498{};
	LensThreeSurfaces EO89681{};
	LensThreeSurfaces EO45218{};
	LensThreeSurfaces EO45105{};
	LensThreeSurfaces EO63701{};
	LensThreeSurfaces EO32921{};
	LensThreeSurfaces EO32923{};
	LensThreeSurfaces EO32925{};
	LensThreeSurfaces EO32935{};
	LensThreeSurfaces EO45178{};
	LensThreeSurfaces EO32927{};
	LensThreeSurfaces EO45352{};
	LensThreeSurfaces EO45270{};
	LensThreeSurfaces EO67330{};
	LensThreeSurfaces EO49291{};
	LensThreeSurfaces EO45353{};
	LensThreeSurfaces EO32886{};
	LensThreeSurfaces EO45179{};
	LensThreeSurfaces EO45180{};
	LensThreeSurfaces EO45181{};
	LensThreeSurfaces EO45354{};
	LensThreeSurfaces EO45271{};
	LensThreeSurfaces EO33918{};
	LensThreeSurfaces EO33919{};
	LensThreeSurfaces EO45417{};
	LensThreeSurfaces EO45418{};
	LensThreeSurfaces EO45419{};


	// Doppelkonkave Linsen (DCV) mit NIR-I-Beschichtung
	//https://www.edmundoptics.de/f/nir-i-coated-double-concave-dcv-lenses/13500/
	LensesTwoSurfaces EO49540{};
	
	// Achromate mit VIS-NIR-Beschichtung 
	//https://www.edmundoptics.de/f/vis-nir-coated-achromatic-lenses/13536/
	LensThreeSurfaces EO84127{};

	// Hastings Triplet Achromatic Lenses 
	// https://www.edmundoptics.de/f/hastings-triplet-achromatic-lenses/11968/
	LensFourSurfaces EO13521{};

	// Steinheil Triplet Achromatic Lenses 
	// https://www.edmundoptics.de/f/steinheil-triplet-achromatic-lenses/12275/
	LensFourSurfaces EO47673{};

	// Micro Plano-Convex (PCX) Lenses 
	// https://www.edmundoptics.de/f/micro-plano-convex-pcx-lenses/39529/
	LensesTwoSurfaces EO45951{};

	// Large PCX Condenser Lenses
	// https://www.edmundoptics.de/f/large-pcx-condenser-lenses/13572/
	LensesTwoSurfaces EO67187{};

};

