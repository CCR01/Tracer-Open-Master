#include "BenchmarkSphericalLens.h"
#include "..\..\LowLevelTracing\Surfaces\SphericalSurface_LLT.h"
#include "..\..\LowLevelTracing\Ray_LLT.h"
#include "..\..\LowLevelTracing\Light_LLT.h"
#include <iostream>
#include <vector>


bool  BenchmarkSphericalLens::checkMethodesSphericalLens_LLT()
{
	std::vector<bool> checkMethodesSphericalLens;
	JonesVector_LLT jones{ 1.0,1.0,1.0,1.0 };
	//dummy light
	Light_LLT light{550.0, 1.0,jones,typeLightRay,1 };

	// Linse um 0° gedreht, Apex Sphere (0.0, 0.0, 20.0) 
	// Startwert (0.0, 0.0, 0.0)
	Ray_LLT Ray1(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 1.0, 15.0 }, 1.0);
	Ray_LLT Ray2(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.5, 15.0 }, 1.0);
	Ray_LLT Ray3(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.0, 15.0 }, 1.0);
	Ray_LLT Ray4(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -0.5, 15.0}, 1.0);
	Ray_LLT Ray5(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0}, 1.0);
	
	LightRayStruct lightRay1{ light,Ray1,1 };
	LightRayStruct lightRay2{ light,Ray2,1 };
	LightRayStruct lightRay3{ light,Ray3,1 };
	LightRayStruct lightRay4{ light,Ray4,1 };
	LightRayStruct lightRay5{ light,Ray5,1 };

	SphericalSurface_LLT S0(/*radius*/9.0, /*semiHeight*/2.817458, /*Apex of the sphere*/{ 0.0, 0.0, 20.0 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.0);

	IntersectInformationStruct InterInfo1 = S0.calculateIntersection(lightRay1);
	VectorStructR3 InterP1 = InterInfo1.getIntersectionPoint();
	IntersectInformationStruct InterInfo2 = S0.calculateIntersection(lightRay2);
	VectorStructR3 InterP2 = InterInfo2.getIntersectionPoint();
	IntersectInformationStruct InterInfo3 = S0.calculateIntersection(lightRay3);
	VectorStructR3 InterP3 = InterInfo3.getIntersectionPoint();
	IntersectInformationStruct InterInfo4 = S0.calculateIntersection(lightRay4);
	VectorStructR3 InterP4 = InterInfo4.getIntersectionPoint();
	IntersectInformationStruct InterInfo5 = S0.calculateIntersection(lightRay5);
	VectorStructR3 InterP5 = InterInfo5.getIntersectionPoint();

	//________________________________________________________________________________________________________
	//Linse um 0° gedreht, Startwert (0.0, 4.0, 0.0)
	Ray_LLT Ray6(/*origin*/{ 0.0, 4.0, 0.0 }, /*direction*/{ 0.0, -3.0, 15.0 }, 1.0);
	Ray_LLT Ray7(/*origin*/{ 0.0, 4.0, 0.0 }, /*direction*/{ 0.0, -3.5, 15.0 }, 1.0);
	Ray_LLT Ray8(/*origin*/{ 0.0, 4.0, 0.0 }, /*direction*/{ 0.0, -4.0, 15.0 }, 1.0);
	Ray_LLT Ray9(/*origin*/{ 0.0, 4.0, 0.0 }, /*direction*/{ 0.0, -4.5, 15.0 }, 1.0);
	Ray_LLT Ray10(/*origin*/{ 0.0, 4.0, 0.0 }, /*direction*/{ 0.0, -5.0, 15.0}, 1.0);

	LightRayStruct lightRay6{ light,Ray6,1 };
	LightRayStruct lightRay7{ light,Ray7,1 };
	LightRayStruct lightRay8{ light,Ray8,1 };
	LightRayStruct lightRay9{ light,Ray9,1 };
	LightRayStruct lightRay10{ light,Ray10,1 };

	IntersectInformationStruct InterInfo6 = S0.calculateIntersection(lightRay6);
	VectorStructR3 InterP6 = InterInfo6.getIntersectionPoint();
	IntersectInformationStruct InterInfo7 = S0.calculateIntersection(lightRay7);
	VectorStructR3 InterP7 = InterInfo7.getIntersectionPoint();
	IntersectInformationStruct InterInfo8 = S0.calculateIntersection(lightRay8);
	VectorStructR3 InterP8 = InterInfo8.getIntersectionPoint();
	IntersectInformationStruct InterInfo9 = S0.calculateIntersection(lightRay9);
	VectorStructR3 InterP9 = InterInfo9.getIntersectionPoint();
	IntersectInformationStruct InterInfo10 = S0.calculateIntersection(lightRay10);
	VectorStructR3 InterP10 = InterInfo10.getIntersectionPoint();

	std::vector<VectorStructR3> checkVector10 = { InterP1, InterP2, InterP3, InterP4, InterP5, InterP6, InterP7, InterP8, InterP9, InterP10 };


	std::vector<VectorStructR3> ReferenzVector10 = { { 0.0, 1.3400211868, 20.100317802 },{ 0.0, 0.66749289100, 20.024786730 },{ 0.0, 0.0, 20.0 } ,{ 0.0, -0.66749289100, 20.024786730 },{ 0.0, -1.3400211868, 20.100317802 },
	{ 0.0, -6.6662231291e-12, 20.0 },{ 0.0, -0.67253812043, 20.025163373 },{ 0.0, -1.3609310176, 20.103491316 },{ 0.0, -2.0725674561, 20.241891520 },{ 0.0, -2.8174575579, 20.452372674 } };

	

	bool isRight10 = Math::compareAllVectorElements(checkVector10, ReferenzVector10, 8);
	checkMethodesSphericalLens.push_back(isRight10);

//	//____________________________________________________________________________________________________________________
//	//____________________________________________________________________________________________________________________
//	// Linse um +45° gedreht, Startwert (0.0, 0.0, 0.0)
//	Ray_LLT Ray11(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray12(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray13(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray14(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -0.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray15(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//
//	SphericalSurface_LLT S1(/*radius*/9.0, /*semiHeight*/2.817458, /*Apex of the sphere*/{ 0.0, 0.0, 20.0 },
//		/*Direction*/ VectorStructR3{ 0.0, -1.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.0);
//
//	IntersectInformationStruct InterInfo11 = S1.calculateIntersection(Ray11);
//	VectorStructR3 InterP11 = InterInfo11.getIntersectionPoint();
//	IntersectInformationStruct InterInfo12 = S1.calculateIntersection(Ray12);
//	VectorStructR3 InterP12 = InterInfo12.getIntersectionPoint();
//	IntersectInformationStruct InterInfo13 = S1.calculateIntersection(Ray13);
//	VectorStructR3 InterP13 = InterInfo13.getIntersectionPoint();
//	IntersectInformationStruct InterInfo14 = S1.calculateIntersection(Ray14);
//	VectorStructR3 InterP14 = InterInfo14.getIntersectionPoint();
//	IntersectInformationStruct InterInfo15 = S1.calculateIntersection(Ray15);
//	VectorStructR3 InterP15 = InterInfo15.getIntersectionPoint();
//
//	//_____________________________________________________________________________________________________________
//	//Linse um +45° gedreht, Startwert (0.0, 4.0, 0.0)
//	Ray_LLT Ray16(/*origin*/{ 0.0, 4.0, 0.0 }, /*direction*/{ 0.0, -3.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray17(/*origin*/{ 0.0, 4.0, 0.0 }, /*direction*/{ 0.0, -3.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray18(/*origin*/{ 0.0, 4.0, 0.0 }, /*direction*/{ 0.0, -4.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray19(/*origin*/{ 0.0, 4.0, 0.0 }, /*direction*/{ 0.0, -4.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray20(/*origin*/{ 0.0, 4.0, 0.0 }, /*direction*/{ 0.0, -5.0, 15.0 }, /*wavelength*/500.0, 1.0);
//
//
//	IntersectInformationStruct InterInfo16 = S1.calculateIntersection(Ray16);
//	VectorStructR3 InterP16 = InterInfo16.getIntersectionPoint();
//	IntersectInformationStruct InterInfo17 = S1.calculateIntersection(Ray17);
//	VectorStructR3 InterP17 = InterInfo17.getIntersectionPoint();
//	IntersectInformationStruct InterInfo18 = S1.calculateIntersection(Ray18);
//	VectorStructR3 InterP18 = InterInfo18.getIntersectionPoint();
//	IntersectInformationStruct InterInfo19 = S1.calculateIntersection(Ray19);
//	VectorStructR3 InterP19 = InterInfo19.getIntersectionPoint();
//	IntersectInformationStruct InterInfo20 = S1.calculateIntersection(Ray20);
//	VectorStructR3 InterP20 = InterInfo20.getIntersectionPoint();
//
//	std::vector<VectorStructR3> checkVector23 = { InterP11, InterP12, InterP13, InterP14, InterP15, InterP16, InterP17, InterP18, InterP19, InterP20 };
//	std::vector<VectorStructR3> ReferenzVector23 = { { 0.0, 1.4611975761, 21.917963642 },{ 0.0, 0.69259381472, 20.777814442 },{ 0.0, 0.0, 20.0 } ,{ 0.0, -0.64709617100, 19.412885130 },{ 0.0, -1.2632612082, 18.948918123 },
//	{ 0.0, -5.5556151558E-012, 20.0 },{ 0.0, -0.54880972986, 19.494898842 },{ 0.0, -1.0863414733, 19.073780525 },{ 0.0, -1.6155579662, 18.718526554 },{ 0.0,-2.1390799085, 18.417239725 } };
//
//	bool isRight23 = Math::compareAllVectorElements(checkVector23, ReferenzVector23, 9);
//	checkMethodesSphericalLens.push_back(isRight23);
//
//
//	//____________________________________________________________________________________________________________________
//	//____________________________________________________________________________________________________________________
//	// Linse um +90° gedreht, Startwert (0.0, 0.0, 0.0)
//	Ray_LLT Ray21(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray22(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray23(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray24(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -0.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray25(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//
//	SphericalSurface_LLT S2(/*radius*/9.0, /*semiHeight*/2.817458, /*Apex of the sphere*/{ 0.0, 0.0, 20.0 },
//		/*Direction*/ VectorStructR3{ 0.0, -1.0, 0.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.0);
//
//	IntersectInformationStruct InterInfo21 = S2.calculateIntersection(Ray21);
//	VectorStructR3 InterP21 = InterInfo21.getIntersectionPoint();
//	IntersectInformationStruct InterInfo22 = S2.calculateIntersection(Ray22);
//	VectorStructR3 InterP22 = InterInfo22.getIntersectionPoint();
//	IntersectInformationStruct InterInfo23 = S2.calculateIntersection(Ray23);
//	VectorStructR3 InterP23 = InterInfo23.getIntersectionPoint();
//	IntersectInformationStruct InterInfo24 = S2.calculateIntersection(Ray24);
//	VectorStructR3 InterP24 = InterInfo24.getIntersectionPoint();
//	IntersectInformationStruct InterInfo25 = S2.calculateIntersection(Ray25);
//	VectorStructR3 InterP25 = InterInfo25.getIntersectionPoint();
//
//	//__________________________________________________________________________________________________________ 
//	//Linse um +90° gedreht, Startwert (0.0, 4.0, 0.0)
//	Ray_LLT Ray26(/*origin*/{ 0.0, 4.0, 0.0 }, /*direction*/{ 0.0, -3.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray27(/*origin*/{ 0.0, 4.0, 0.0 }, /*direction*/{ 0.0, -3.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray28(/*origin*/{ 0.0, 4.0, 0.0 }, /*direction*/{ 0.0, -4.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray29(/*origin*/{ 0.0, 4.0, 0.0 }, /*direction*/{ 0.0, -4.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray30(/*origin*/{ 0.0, 4.0, 0.0 }, /*direction*/{ 0.0, -5.0, 15.0 }, /*wavelength*/500.0, 1.0);
//
//
//	IntersectInformationStruct InterInfo26 = S2.calculateIntersection(Ray26);
//	VectorStructR3 InterP26 = InterInfo26.getIntersectionPoint();
//	IntersectInformationStruct InterInfo27 = S2.calculateIntersection(Ray27);
//	VectorStructR3 InterP27 = InterInfo27.getIntersectionPoint();
//	IntersectInformationStruct InterInfo28 = S2.calculateIntersection(Ray28);
//	VectorStructR3 InterP28 = InterInfo28.getIntersectionPoint();
//	IntersectInformationStruct InterInfo29 = S2.calculateIntersection(Ray29);
//	VectorStructR3 InterP29 = InterInfo29.getIntersectionPoint();
//	IntersectInformationStruct InterInfo30 = S2.calculateIntersection(Ray30);
//	VectorStructR3 InterP30 = InterInfo30.getIntersectionPoint();
//
//	std::vector<VectorStructR3> checkVector45 = { InterP21, InterP22, InterP23, InterP24, InterP25, InterP26, InterP27, InterP28, InterP29, InterP30 };
//	std::vector<VectorStructR3> ReferenzVector45 = { { 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0,-1.5777218104e-030, 20.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },
//	{ 0.0, -6.1715247777E-023, 20.0 },{ 0.0, -0.21275516734, 18.054665003 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 } };
//
//	bool isRight45 = Math::compareAllVectorElements(checkVector45, ReferenzVector45, 9);
//	checkMethodesSphericalLens.push_back(isRight45);
//
//	//____________________________________________________________________________________________________________________
//	//____________________________________________________________________________________________________________________
//	// Linse um -45° gedreht, Startwert (0.0, 0.0, 0.0)
//	Ray_LLT Ray31(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray32(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray33(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray34(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -0.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray35(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//
//	SphericalSurface_LLT S3(/*radius*/9.0, /*semiHeight*/2.817458, /*Apex of the sphere*/{ 0.0, 0.0, 20.0 },
//		/*Direction*/ VectorStructR3{ 0.0, 1.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.0);
//
//	IntersectInformationStruct InterInfo31 = S3.calculateIntersection(Ray31);
//	VectorStructR3 InterP31 = InterInfo31.getIntersectionPoint();
//	IntersectInformationStruct InterInfo32 = S3.calculateIntersection(Ray32);
//	VectorStructR3 InterP32 = InterInfo32.getIntersectionPoint();
//	IntersectInformationStruct InterInfo33 = S3.calculateIntersection(Ray33);
//	VectorStructR3 InterP33 = InterInfo33.getIntersectionPoint();
//	IntersectInformationStruct InterInfo34 = S3.calculateIntersection(Ray34);
//	VectorStructR3 InterP34 = InterInfo34.getIntersectionPoint();
//	IntersectInformationStruct InterInfo35 = S3.calculateIntersection(Ray35);
//	VectorStructR3 InterP35 = InterInfo35.getIntersectionPoint();
//
//	//__________________________________________________________________________________________________________ 
//	//Linse um -45° gedreht, Startwert (0.0, 4.0, 0.0)
//	Ray_LLT Ray36(/*origin*/{ 0.0, 4.0, 0.0 }, /*direction*/{ 0.0, -3.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray37(/*origin*/{ 0.0, 4.0, 0.0 }, /*direction*/{ 0.0, -3.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray38(/*origin*/{ 0.0, 4.0, 0.0 }, /*direction*/{ 0.0, -4.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray39(/*origin*/{ 0.0, 4.0, 0.0 }, /*direction*/{ 0.0, -4.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray40(/*origin*/{ 0.0, 4.0, 0.0 }, /*direction*/{ 0.0, -5.0, 15.0 }, /*wavelength*/500.0, 1.0);
//
//
//	IntersectInformationStruct InterInfo36 = S3.calculateIntersection(Ray36);
//	VectorStructR3 InterP36 = InterInfo36.getIntersectionPoint();
//	IntersectInformationStruct InterInfo37 = S3.calculateIntersection(Ray37);
//	VectorStructR3 InterP37 = InterInfo37.getIntersectionPoint();
//	IntersectInformationStruct InterInfo38 = S3.calculateIntersection(Ray38);
//	VectorStructR3 InterP38 = InterInfo38.getIntersectionPoint();
//	IntersectInformationStruct InterInfo39 = S3.calculateIntersection(Ray39);
//	VectorStructR3 InterP39 = InterInfo39.getIntersectionPoint();
//	IntersectInformationStruct InterInfo40 = S3.calculateIntersection(Ray40);
//	VectorStructR3 InterP40 = InterInfo40.getIntersectionPoint();
//
//	std::vector<VectorStructR3> checkVector67 = { InterP31, InterP32, InterP33, InterP34, InterP35, InterP36, InterP37,InterP38, InterP39, InterP40 };
//	std::vector<VectorStructR3> ReferenzVector67 = { { 0.0, 1.2632612082, 18.948918123 },{ 0.0, 0.64709617100, 19.412885130 },{ 0.0, 0.0, 20.0 },{ 0.0, -0.69259381472, 20.777814442 },{ 0.0, -1.4611975761, 21.917963642 },
//	{ 0.0, -8.3327946967E-012, 20.0 },{ 0.0, -0.91726551290, 21.073995055 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 } };
//
//	bool isRight67 = Math::compareAllVectorElements(checkVector67, ReferenzVector67, 9);
//	checkMethodesSphericalLens.push_back(isRight67);
//
//	//____________________________________________________________________________________________________________________
//	//____________________________________________________________________________________________________________________
//	// Linse um -90° gedreht, Startwert (0.0, 0.0, 0.0)
//	Ray_LLT Ray41(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray42(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray43(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray44(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -0.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray45(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//
//	SphericalSurface_LLT S4(/*radius*/9.0, /*semiHeight*/2.817458, /*Apex of the sphere*/{ 0.0, 0.0, 20.0 },
//		/*Direction*/ VectorStructR3{ 0.0, 1.0, 0.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.0);
//
//	IntersectInformationStruct InterInfo41 = S4.calculateIntersection(Ray41);
//	VectorStructR3 InterP41 = InterInfo41.getIntersectionPoint();
//	IntersectInformationStruct InterInfo42 = S4.calculateIntersection(Ray42);
//	VectorStructR3 InterP42 = InterInfo42.getIntersectionPoint();
//	IntersectInformationStruct InterInfo43 = S4.calculateIntersection(Ray43);
//	VectorStructR3 InterP43 = InterInfo43.getIntersectionPoint();
//	IntersectInformationStruct InterInfo44 = S4.calculateIntersection(Ray44);
//	VectorStructR3 InterP44 = InterInfo44.getIntersectionPoint();
//	IntersectInformationStruct InterInfo45 = S4.calculateIntersection(Ray45);
//	VectorStructR3 InterP45 = InterInfo45.getIntersectionPoint();
//
//	//Linse um -90° gedreht, Startwert (0.0, 4.0, 0.0)
//	Ray_LLT Ray46(/*origin*/{ 0.0, 4.0, 0.0 }, /*direction*/{ 0.0, -3.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray47(/*origin*/{ 0.0, 4.0, 0.0 }, /*direction*/{ 0.0, -3.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray48(/*origin*/{ 0.0, 4.0, 0.0 }, /*direction*/{ 0.0, -4.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray49(/*origin*/{ 0.0, 4.0, 0.0 }, /*direction*/{ 0.0, -4.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray50(/*origin*/{ 0.0, 4.0, 0.0 }, /*direction*/{ 0.0, -5.0, 15.0 }, /*wavelength*/500.0, 1.0);
//
//
//	IntersectInformationStruct InterInfo46 = S4.calculateIntersection(Ray46);	// InterP46: 2 Schnittpunkte mit Sphäre
//	VectorStructR3 InterP46 = InterInfo46.getIntersectionPoint();
//	IntersectInformationStruct InterInfo47 = S4.calculateIntersection(Ray47);
//	VectorStructR3 InterP47 = InterInfo47.getIntersectionPoint();
//	IntersectInformationStruct InterInfo48 = S4.calculateIntersection(Ray48);
//	VectorStructR3 InterP48 = InterInfo48.getIntersectionPoint();
//	IntersectInformationStruct InterInfo49 = S4.calculateIntersection(Ray49);
//	VectorStructR3 InterP49 = InterInfo49.getIntersectionPoint();
//	IntersectInformationStruct InterInfo50 = S4.calculateIntersection(Ray50);
//	VectorStructR3 InterP50 = InterInfo50.getIntersectionPoint();
//
//	std::vector<VectorStructR3> checkVector89 = { InterP41, InterP42, InterP43, InterP44, InterP45, InterP46, InterP47, InterP48, InterP49, InterP50 };
//	std::vector<VectorStructR3> ReferenzVector89 = { { 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 1.5777218104E-030, 20.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },
//	{ 0.0, 0.0, 20.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 } };
//
//	bool isRight89 = Math::compareAllVectorElements(checkVector89, ReferenzVector89, 9);
//	checkMethodesSphericalLens.push_back(isRight89);
//
//	//________________________________________________________________________________________________________________________________________________________________
//	//________________________________________________________________________________________________________________________________________________________________
//	// Linse 0° gedreht, Apex Sphere (0.0, 1.0, 20.0)
//	// Startwert (0.0, 0.0, 0.0)
//	Ray_LLT Ray51(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray52(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray53(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray54(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -0.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray55(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//
//	SphericalSurface_LLT S5(/*radius*/9.0, /*semiHeight*/2.817458, /*Apex of the sphere*/{ 0.0, 1.0, 20.0 },
//		/*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.0);
//
//	IntersectInformationStruct InterInfo51 = S5.calculateIntersection(Ray51);
//	VectorStructR3 InterP51 = InterInfo51.getIntersectionPoint();
//	IntersectInformationStruct InterInfo52 = S5.calculateIntersection(Ray52);
//	VectorStructR3 InterP52 = InterInfo52.getIntersectionPoint();
//	IntersectInformationStruct InterInfo53 = S5.calculateIntersection(Ray53);
//	VectorStructR3 InterP53 = InterInfo53.getIntersectionPoint();
//	IntersectInformationStruct InterInfo54 = S5.calculateIntersection(Ray54);
//	VectorStructR3 InterP54 = InterInfo54.getIntersectionPoint();
//	IntersectInformationStruct InterInfo55 = S5.calculateIntersection(Ray55);
//	VectorStructR3 InterP55 = InterInfo55.getIntersectionPoint();
//
//	//________________________________________________________________________________________________________
//	//Linse um 0° gedreht, Startwert (0.0, 2.0, 0.0)
//	Ray_LLT Ray56(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray57(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray58(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray59(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray60(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -3.0, 15.0 }, /*wavelength*/500.0, 1.0);
//
//
//	//InterP57 stimmt nicht exakt mit ZEMAX-Schnittpunkt überein -> Übereinstimmung auf Kommazahlen auf 8 heruntergesetzt
//	IntersectInformationStruct InterInfo56 = S5.calculateIntersection(Ray56);
//	VectorStructR3 InterP56 = InterInfo56.getIntersectionPoint();
//	IntersectInformationStruct InterInfo57 = S5.calculateIntersection(Ray57);
//	VectorStructR3 InterP57 = InterInfo57.getIntersectionPoint();
//	IntersectInformationStruct InterInfo58 = S5.calculateIntersection(Ray58);
//	VectorStructR3 InterP58 = InterInfo58.getIntersectionPoint();
//	IntersectInformationStruct InterInfo59 = S5.calculateIntersection(Ray59);
//	VectorStructR3 InterP59 = InterInfo59.getIntersectionPoint();
//	IntersectInformationStruct InterInfo60 = S5.calculateIntersection(Ray60);
//	VectorStructR3 InterP60 = InterInfo60.getIntersectionPoint();
//
//	std::vector<VectorStructR3> checkVector100 = { InterP51, InterP52, InterP53, InterP54, InterP55, InterP56, InterP57, InterP58, InterP59, InterP60 };
//
//
//	std::vector<VectorStructR3> ReferenzVector100 = { { 0.0, 1.3337460175, 20.006190262 },{ 0.0, 0.66687224470, 20.006167341 },{ 0.0, 0.0, 20.055728090 },{ 0.0, -0.67188842782, 20.156652835 },{ 0.0, -1.3542243327, 20.313364990 },
//	{ 0.0, 0.66625398250, 20.006190262 },{ 0.0, -0.0056360012139, 20.056360012 },{ 0.0, -0.68796087482, 20.159706561 },{ 0.0, -1.3870548813, 20.322329288 },{ 0.0, 0.0, 0.0 } };
//
//
//	bool isRight100 = Math::compareAllVectorElements(checkVector100, ReferenzVector100, 7);
//	checkMethodesSphericalLens.push_back(isRight100);
//
//	//________________________________________________________________________________________________________________________________________________________________
//	//________________________________________________________________________________________________________________________________________________________________
//	// Linse 45° gedreht, Apex Sphere (0.0, 1.0, 20.0)
//	// Startwert (0.0, 0.0, 0.0)
//	Ray_LLT Ray61(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray62(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray63(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray64(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -0.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray65(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//
//	SphericalSurface_LLT S6(/*radius*/9.0, /*semiHeight*/2.817458, /*Apex of the sphere*/{ 0.0, 1.0, 20.0 },
//		/*Direction*/ VectorStructR3{ 0.0, -1.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.0);
//
//	IntersectInformationStruct InterInfo61 = S6.calculateIntersection(Ray61);
//	VectorStructR3 InterP61 = InterInfo61.getIntersectionPoint();
//	IntersectInformationStruct InterInfo62 = S6.calculateIntersection(Ray62);
//	VectorStructR3 InterP62 = InterInfo62.getIntersectionPoint();
//	IntersectInformationStruct InterInfo63 = S6.calculateIntersection(Ray63);
//	VectorStructR3 InterP63 = InterInfo63.getIntersectionPoint();
//	IntersectInformationStruct InterInfo64 = S6.calculateIntersection(Ray64);
//	VectorStructR3 InterP64 = InterInfo64.getIntersectionPoint();
//	IntersectInformationStruct InterInfo65 = S6.calculateIntersection(Ray65);
//	VectorStructR3 InterP65 = InterInfo65.getIntersectionPoint();
//
//	//________________________________________________________________________________________________________
//	//Linse um 45° gedreht, Startwert (0.0, 2.0, 0.0)
//	Ray_LLT Ray66(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray67(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray68(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray69(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray70(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -3.0, 15.0 }, /*wavelength*/500.0, 1.0);
//
//
//	IntersectInformationStruct InterInfo66 = S6.calculateIntersection(Ray66);
//	VectorStructR3 InterP66 = InterInfo66.getIntersectionPoint();
//	IntersectInformationStruct InterInfo67 = S6.calculateIntersection(Ray67);
//	VectorStructR3 InterP67 = InterInfo67.getIntersectionPoint();
//	IntersectInformationStruct InterInfo68 = S6.calculateIntersection(Ray68);
//	VectorStructR3 InterP68 = InterInfo68.getIntersectionPoint();
//	IntersectInformationStruct InterInfo69 = S6.calculateIntersection(Ray69);
//	VectorStructR3 InterP69 = InterInfo69.getIntersectionPoint();
//	IntersectInformationStruct InterInfo70 = S6.calculateIntersection(Ray70);
//	VectorStructR3 InterP70 = InterInfo70.getIntersectionPoint();
//
//	std::vector<VectorStructR3> checkVector101 = { InterP61, InterP62, InterP63, InterP64, InterP65, InterP66, InterP67, InterP68, InterP69, InterP70 };
//
//
//	std::vector<VectorStructR3> ReferenzVector101 = { { 0.0, 1.3586757758, 20.380136638 },{ 0.0, 0.65578228300, 19.673468490 },{ 0.0, 0.0, 19.137072208 },{ 0.0, -0.62378085438, 18.713425631 },{ 0.0, -1.2248165105, 18.372247657 },
//	{ 0.0, 0.68657953404, 19.701306989 },{ 0.0, 0.080265578790, 19.197344212 },{ 0.0, -0.50509941741, 18.788245631 },{ 0.0, -1.0752507908, 18.451504745 },{ 0.0, 0.0, 0.0 } };
//
//
//	bool isRight101 = Math::compareAllVectorElements(checkVector101, ReferenzVector101, 9);
//	checkMethodesSphericalLens.push_back(isRight101);
//
//	//________________________________________________________________________________________________________________________________________________________________
//	//________________________________________________________________________________________________________________________________________________________________
//	// Linse -45° gedreht, Apex Sphere (0.0, 1.0, 20.0)
//	// Startwert (0.0, 0.0, 0.0)
//	Ray_LLT Ray71(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray72(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray73(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray74(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -0.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray75(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//
//	SphericalSurface_LLT S7(/*radius*/9.0, /*semiHeight*/2.817458, /*Apex of the sphere*/{ 0.0, 1.0, 20.0 },
//		/*Direction*/ VectorStructR3{ 0.0, 1.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.0);
//
//	IntersectInformationStruct InterInfo71 = S7.calculateIntersection(Ray71);
//	VectorStructR3 InterP71 = InterInfo71.getIntersectionPoint();
//	IntersectInformationStruct InterInfo72 = S7.calculateIntersection(Ray72);
//	VectorStructR3 InterP72 = InterInfo72.getIntersectionPoint();
//	IntersectInformationStruct InterInfo73 = S7.calculateIntersection(Ray73);
//	VectorStructR3 InterP73 = InterInfo73.getIntersectionPoint();
//	IntersectInformationStruct InterInfo74 = S7.calculateIntersection(Ray74);
//	VectorStructR3 InterP74 = InterInfo74.getIntersectionPoint();
//	IntersectInformationStruct InterInfo75 = S7.calculateIntersection(Ray75);
//	VectorStructR3 InterP75 = InterInfo75.getIntersectionPoint();
//
//	//________________________________________________________________________________________________________
//	//Linse um -45° gedreht, Startwert (0.0, 2.0, 0.0)
//	Ray_LLT Ray76(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray77(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray78(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray79(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray80(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -3.0, 15.0 }, /*wavelength*/500.0, 1.0);
//
//
//	IntersectInformationStruct InterInfo76 = S7.calculateIntersection(Ray76);
//	VectorStructR3 InterP76 = InterInfo76.getIntersectionPoint();
//	IntersectInformationStruct InterInfo77 = S7.calculateIntersection(Ray77);
//	VectorStructR3 InterP77 = InterInfo77.getIntersectionPoint();
//	IntersectInformationStruct InterInfo78 = S7.calculateIntersection(Ray78);
//	VectorStructR3 InterP78 = InterInfo78.getIntersectionPoint();
//	IntersectInformationStruct InterInfo79 = S7.calculateIntersection(Ray79);
//	VectorStructR3 InterP79 = InterInfo79.getIntersectionPoint();
//	IntersectInformationStruct InterInfo80 = S7.calculateIntersection(Ray80);
//	VectorStructR3 InterP80 = InterInfo80.getIntersectionPoint();
//
//	std::vector<VectorStructR3> checkVector102 = { InterP71, InterP72, InterP73, InterP74, InterP75, InterP76, InterP77, InterP78, InterP79, InterP80 };
//
//
//	std::vector<VectorStructR3> ReferenzVector102 = { { 0.0, 1.3134204659,19.701306989 },{ 0.0, 0.67797380542, 20.339214163 },{ 0.0, 0.0, 21.189786900 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },
//	{ 0.0, 0.64132422416, 20.380136638 },{ 0.0, -0.13941113151, 21.394111315 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 } };
//
//
//	bool isRight102 = Math::compareAllVectorElements(checkVector102, ReferenzVector102, 9);
//	checkMethodesSphericalLens.push_back(isRight102);
//
//
//	//________________________________________________________________________________________________________________________________________________________________
//	//________________________________________________________________________________________________________________________________________________________________
//	// Linse 90° gedreht, Apex Sphere (0.0, 1.0, 20.0)
//	// Startwert (0.0, 0.0, 0.0)
//	Ray_LLT Ray81(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray82(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray83(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray84(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -0.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray85(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//
//	SphericalSurface_LLT S8(/*radius*/9.0, /*semiHeight*/2.817458, /*Apex of the sphere*/{ 0.0, 1.0, 20.0 },
//		/*Direction*/ VectorStructR3{ 0.0, -1.0, 0.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.0);
//
//	IntersectInformationStruct InterInfo81 = S8.calculateIntersection(Ray81);
//	VectorStructR3 InterP81 = InterInfo81.getIntersectionPoint();
//	IntersectInformationStruct InterInfo82 = S8.calculateIntersection(Ray82);
//	VectorStructR3 InterP82 = InterInfo82.getIntersectionPoint();
//	IntersectInformationStruct InterInfo83 = S8.calculateIntersection(Ray83);
//	VectorStructR3 InterP83 = InterInfo83.getIntersectionPoint();
//	IntersectInformationStruct InterInfo84 = S8.calculateIntersection(Ray84);
//	VectorStructR3 InterP84 = InterInfo84.getIntersectionPoint();
//	IntersectInformationStruct InterInfo85 = S8.calculateIntersection(Ray85);
//	VectorStructR3 InterP85 = InterInfo85.getIntersectionPoint();
//
//	//________________________________________________________________________________________________________
//	//Linse um 90° gedreht, Startwert (0.0, 2.0, 0.0)
//	Ray_LLT Ray86(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray87(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray88(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray89(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray90(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -3.0, 15.0 }, /*wavelength*/500.0, 1.0);
//
//
//	IntersectInformationStruct InterInfo86 = S8.calculateIntersection(Ray86);
//	VectorStructR3 InterP86 = InterInfo86.getIntersectionPoint();
//	IntersectInformationStruct InterInfo87 = S8.calculateIntersection(Ray87);
//	VectorStructR3 InterP87 = InterInfo87.getIntersectionPoint();
//	IntersectInformationStruct InterInfo88 = S8.calculateIntersection(Ray88);
//	VectorStructR3 InterP88 = InterInfo88.getIntersectionPoint();
//	IntersectInformationStruct InterInfo89 = S8.calculateIntersection(Ray89);
//	VectorStructR3 InterP89 = InterInfo89.getIntersectionPoint();
//	IntersectInformationStruct InterInfo90 = S8.calculateIntersection(Ray90);
//	VectorStructR3 InterP90 = InterInfo90.getIntersectionPoint();
//
//	std::vector<VectorStructR3> checkVector103 = { InterP81, InterP82, InterP83, InterP84, InterP85, InterP86, InterP87, InterP88, InterP89, InterP90 };
//
//
//	std::vector<VectorStructR3> ReferenzVector103 = { { 0.0, 0.0, 0.0 },{ 0.0, 0.57563229773, 17.268968932 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },
//	{ 0.0, 0.79423303769, 18.086504435 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 } };
//
//
//	bool isRight103 = Math::compareAllVectorElements(checkVector103, ReferenzVector103, 9);
//	checkMethodesSphericalLens.push_back(isRight103);
//
//	//________________________________________________________________________________________________________________________________________________________________
//	//________________________________________________________________________________________________________________________________________________________________
//	// Linse -90° gedreht, Apex Sphere (0.0, 1.0, 20.0)
//	// Startwert (0.0, 0.0, 0.0)
//	Ray_LLT Ray91(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray92(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray93(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray94(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -0.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray95(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//
//	SphericalSurface_LLT S9(/*radius*/9.0, /*semiHeight*/2.817458, /*Apex of the sphere*/{ 0.0, 1.0, 20.0 },
//		/*Direction*/ VectorStructR3{ 0.0, 1.0, 0.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.0);
//
//	IntersectInformationStruct InterInfo91 = S9.calculateIntersection(Ray91);
//	VectorStructR3 InterP91 = InterInfo91.getIntersectionPoint();
//	IntersectInformationStruct InterInfo92 = S9.calculateIntersection(Ray92);
//	VectorStructR3 InterP92 = InterInfo92.getIntersectionPoint();
//	IntersectInformationStruct InterInfo93 = S9.calculateIntersection(Ray93);
//	VectorStructR3 InterP93 = InterInfo93.getIntersectionPoint();
//	IntersectInformationStruct InterInfo94 = S9.calculateIntersection(Ray94);
//	VectorStructR3 InterP94 = InterInfo94.getIntersectionPoint();
//	IntersectInformationStruct InterInfo95 = S9.calculateIntersection(Ray95);
//	VectorStructR3 InterP95 = InterInfo95.getIntersectionPoint();
//
//	//________________________________________________________________________________________________________
//	//Linse um -90° gedreht, Startwert (0.0, 2.0, 0.0)
//	Ray_LLT Ray96(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray97(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray98(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray99(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray100(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -3.0, 15.0 }, /*wavelength*/500.0, 1.0);
//
//
//	IntersectInformationStruct InterInfo96 = S9.calculateIntersection(Ray96);
//	VectorStructR3 InterP96 = InterInfo96.getIntersectionPoint();
//	IntersectInformationStruct InterInfo97 = S9.calculateIntersection(Ray97);
//	VectorStructR3 InterP97 = InterInfo97.getIntersectionPoint();
//	IntersectInformationStruct InterInfo98 = S9.calculateIntersection(Ray98);
//	VectorStructR3 InterP98 = InterInfo98.getIntersectionPoint();
//	IntersectInformationStruct InterInfo99 = S9.calculateIntersection(Ray99);
//	VectorStructR3 InterP99 = InterInfo99.getIntersectionPoint();
//	IntersectInformationStruct InterInfo100 = S9.calculateIntersection(Ray100);
//	VectorStructR3 InterP100 = InterInfo100.getIntersectionPoint();
//
//	std::vector<VectorStructR3> checkVector104 = { InterP91, InterP92, InterP93, InterP94, InterP95, InterP96, InterP97, InterP98, InterP99, InterP100 };
//
//
//	std::vector<VectorStructR3> ReferenzVector104 = { { 0.0, 1.2057669623, 18.086504435 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },
//	{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 } };
//
//
//	bool isRight104 = Math::compareAllVectorElements(checkVector104, ReferenzVector104, 9);
//	checkMethodesSphericalLens.push_back(isRight104);
//
//	//________________________________________________________________________________________________________________________________________________________________
//	//________________________________________________________________________________________________________________________________________________________________
//	// Linse 0° gedreht, Apex Sphere (0.0, -1.0, 20.0)
//	// Startwert (0.0, 0.0, 0.0)
//	Ray_LLT Ray101(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray102(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray103(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray104(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -0.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray105(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//
//	SphericalSurface_LLT S10(/*radius*/9.0, /*semiHeight*/2.817458, /*Apex of the sphere*/{ 0.0, -1.0, 20.0 },
//		/*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.0);
//
//	IntersectInformationStruct InterInfo101 = S10.calculateIntersection(Ray101);
//	VectorStructR3 InterP101 = InterInfo101.getIntersectionPoint();
//	IntersectInformationStruct InterInfo102 = S10.calculateIntersection(Ray102);
//	VectorStructR3 InterP102 = InterInfo102.getIntersectionPoint();
//	IntersectInformationStruct InterInfo103 = S10.calculateIntersection(Ray103);
//	VectorStructR3 InterP103 = InterInfo103.getIntersectionPoint();
//	IntersectInformationStruct InterInfo104 = S10.calculateIntersection(Ray104);
//	VectorStructR3 InterP104 = InterInfo104.getIntersectionPoint();
//	IntersectInformationStruct InterInfo105 = S10.calculateIntersection(Ray105);
//	VectorStructR3 InterP105 = InterInfo105.getIntersectionPoint();
//
//	//________________________________________________________________________________________________________
//	//Linse um 0° gedreht, Startwert (0.0, 2.0, 0.0)
//	Ray_LLT Ray106(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray107(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray108(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray109(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray110(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -3.0, 15.0 }, /*wavelength*/500.0, 1.0);
//
//
//	IntersectInformationStruct InterInfo106 = S10.calculateIntersection(Ray106);
//	VectorStructR3 InterP106 = InterInfo106.getIntersectionPoint();
//	IntersectInformationStruct InterInfo107 = S10.calculateIntersection(Ray107);
//	VectorStructR3 InterP107 = InterInfo107.getIntersectionPoint();
//	IntersectInformationStruct InterInfo108 = S10.calculateIntersection(Ray108);
//	VectorStructR3 InterP108 = InterInfo108.getIntersectionPoint();
//	IntersectInformationStruct InterInfo109 = S10.calculateIntersection(Ray109);
//	VectorStructR3 InterP109 = InterInfo109.getIntersectionPoint();
//	IntersectInformationStruct InterInfo110 = S10.calculateIntersection(Ray110);
//	VectorStructR3 InterP110 = InterInfo110.getIntersectionPoint();
//
//	std::vector<VectorStructR3> checkVector105 = { InterP101, InterP102, InterP103, InterP104, InterP105, InterP106, InterP107, InterP108, InterP109, InterP110 };
//
//
//	std::vector<VectorStructR3> ReferenzVector105 = { { 0.0, 1.3542243327, 20.313364990 },{ 0.0, 0.67188842782, 20.156652835 },{ 0.0, 0.0, 20.055728090 },{ 0.0, -0.66687224470, 20.006167341 },{ 0.0, -1.3337460175, 20.006190262 },
//	{ 0.0, 0.65641720542, 20.153741919 },{ 0.0, -0.0055113620156, 20.055113620 },{ 0.0, -0.66748595074, 20.006144631 },{ 0.0, -1.3343688997, 20.006213398 },{ 0.0, -2.0114020474, 20.057010237 } };
//
//
//	bool isRight105 = Math::compareAllVectorElements(checkVector105, ReferenzVector105, 9);
//	checkMethodesSphericalLens.push_back(isRight105);
//
//
//	//________________________________________________________________________________________________________________________________________________________________
//	//________________________________________________________________________________________________________________________________________________________________
//	// Linse 45° gedreht, Apex Sphere (0.0, -1.0, 20.0)
//	// Startwert (0.0, 0.0, 0.0)
//	Ray_LLT Ray111(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray112(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray113(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray114(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -0.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray115(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//
//	SphericalSurface_LLT S11(/*radius*/9.0, /*semiHeight*/2.817458, /*Apex of the sphere*/{ 0.0, -1.0, 20.0 },
//		/*Direction*/ VectorStructR3{ 0.0, -1.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.0);
//
//	IntersectInformationStruct InterInfo111 = S11.calculateIntersection(Ray111);
//	VectorStructR3 InterP111 = InterInfo111.getIntersectionPoint();
//	IntersectInformationStruct InterInfo112 = S11.calculateIntersection(Ray112);
//	VectorStructR3 InterP112 = InterInfo112.getIntersectionPoint();
//	IntersectInformationStruct InterInfo113 = S11.calculateIntersection(Ray113);
//	VectorStructR3 InterP113 = InterInfo113.getIntersectionPoint();
//	IntersectInformationStruct InterInfo114 = S11.calculateIntersection(Ray114);
//	VectorStructR3 InterP114 = InterInfo114.getIntersectionPoint();
//	IntersectInformationStruct InterInfo115 = S11.calculateIntersection(Ray115);
//	VectorStructR3 InterP115 = InterInfo115.getIntersectionPoint();
//
//	//________________________________________________________________________________________________________
//	//Linse um 45° gedreht, Startwert (0.0, 2.0, 0.0)
//	Ray_LLT Ray116(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray117(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray118(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray119(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray120(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -3.0, 15.0 }, /*wavelength*/500.0, 1.0);
//
//
//	IntersectInformationStruct InterInfo116 = S11.calculateIntersection(Ray116);
//	VectorStructR3 InterP116 = InterInfo116.getIntersectionPoint();
//	IntersectInformationStruct InterInfo117 = S11.calculateIntersection(Ray117);
//	VectorStructR3 InterP117 = InterInfo117.getIntersectionPoint();
//	IntersectInformationStruct InterInfo118 = S11.calculateIntersection(Ray118);
//	VectorStructR3 InterP118 = InterInfo118.getIntersectionPoint();
//	IntersectInformationStruct InterInfo119 = S11.calculateIntersection(Ray119);
//	VectorStructR3 InterP119 = InterInfo119.getIntersectionPoint();
//	IntersectInformationStruct InterInfo120 = S11.calculateIntersection(Ray120);
//	VectorStructR3 InterP120 = InterInfo120.getIntersectionPoint();
//
//	std::vector<VectorStructR3> checkVector106 = { InterP111, InterP112, InterP113, InterP114, InterP115, InterP116, InterP117, InterP118, InterP119, InterP120 };
//
//
//	std::vector<VectorStructR3> ReferenzVector106 = { { 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 21.189786900 },{ 0.0, -0.67797380542, 20.339214163 },{ 0.0, -1.3134204659, 19.701306989 },
//	{ 0.0, 0.53051691180, 22.042246323 },{ 0.0, -0.10442656171, 21.044265617 },{ 0.0, -0.70754162548, 20.306562191 },{ 0.0, -1.2874910938, 19.724946563 },{ 0.0, -1.8501485790, 19.250742895 } };
//
//
//	bool isRight106 = Math::compareAllVectorElements(checkVector106, ReferenzVector106, 9);
//	checkMethodesSphericalLens.push_back(isRight106);
//
//	//________________________________________________________________________________________________________________________________________________________________
//	//________________________________________________________________________________________________________________________________________________________________
//	// Linse -45° gedreht, Apex Sphere (0.0, -1.0, 20.0)
//	// Startwert (0.0, 0.0, 0.0)
//	Ray_LLT Ray121(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray122(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray123(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray124(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -0.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray125(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//
//	SphericalSurface_LLT S12(/*radius*/9.0, /*semiHeight*/2.817458, /*Apex of the sphere*/{ 0.0, -1.0, 20.0 },
//		/*Direction*/ VectorStructR3{ 0.0, 1.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.0);
//
//	IntersectInformationStruct InterInfo121 = S12.calculateIntersection(Ray121);
//	VectorStructR3 InterP121 = InterInfo121.getIntersectionPoint();
//	IntersectInformationStruct InterInfo122 = S12.calculateIntersection(Ray122);
//	VectorStructR3 InterP122 = InterInfo122.getIntersectionPoint();
//	IntersectInformationStruct InterInfo123 = S12.calculateIntersection(Ray123);
//	VectorStructR3 InterP123 = InterInfo123.getIntersectionPoint();
//	IntersectInformationStruct InterInfo124 = S12.calculateIntersection(Ray124);
//	VectorStructR3 InterP124 = InterInfo124.getIntersectionPoint();
//	IntersectInformationStruct InterInfo125 = S12.calculateIntersection(Ray125);
//	VectorStructR3 InterP125 = InterInfo125.getIntersectionPoint();
//
//	//________________________________________________________________________________________________________
//	//Linse um -45° gedreht, Startwert (0.0, 2.0, 0.0)
//	Ray_LLT Ray126(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray127(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray128(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray129(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray130(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -3.0, 15.0 }, /*wavelength*/500.0, 1.0);
//
//
//	//InterP127 y-Wert stimmt nich mit Zemax-Schnittpunkt überein -> Übereinstimmung auf Kommazahlen auf 8 heruntergesetzt
//	IntersectInformationStruct InterInfo126 = S12.calculateIntersection(Ray126);
//	VectorStructR3 InterP126 = InterInfo126.getIntersectionPoint();
//	IntersectInformationStruct InterInfo127 = S12.calculateIntersection(Ray127);
//	VectorStructR3 InterP127 = InterInfo127.getIntersectionPoint();
//	IntersectInformationStruct InterInfo128 = S12.calculateIntersection(Ray128);
//	VectorStructR3 InterP128 = InterInfo128.getIntersectionPoint();
//	IntersectInformationStruct InterInfo129 = S12.calculateIntersection(Ray129);
//	VectorStructR3 InterP129 = InterInfo129.getIntersectionPoint();
//	IntersectInformationStruct InterInfo130 = S12.calculateIntersection(Ray130);
//	VectorStructR3 InterP130 = InterInfo130.getIntersectionPoint();
//
//	std::vector<VectorStructR3> checkVector107 = { InterP121, InterP122, InterP123, InterP124, InterP125, InterP126, InterP127, InterP128, InterP129, InterP130 };
//
//
//	std::vector<VectorStructR3> ReferenzVector107 = { { 0.0, 1.2248165105, 18.372247657 },{ 0.0, 0.62378085438, 18.713425631 },{ 0.0, 0.0, 19.137072208 },{ 0.0, -0.65578228300, 19.673468490 },{ 0.0, -1.3586757758, 20.380136638 },
//	{ 0.0, 0.75786968950, 18.631954657 },{ 0.0, 0.093111580756, 19.068884192 },{ 0.0, -0.61870588404, 19.640294130 },{ 0.0, -1.4055329923, 20.433197954 },{ 0.0, -2.3433246826, 21.716623413 } };
//
//
//	bool isRight107 = Math::compareAllVectorElements(checkVector107, ReferenzVector107, 8);
//	checkMethodesSphericalLens.push_back(isRight107);;
//
//
//	//________________________________________________________________________________________________________________________________________________________________
//	//________________________________________________________________________________________________________________________________________________________________
//	// Linse 90° gedreht, Apex Sphere (0.0, -1.0, 20.0)
//	// Startwert (0.0, 0.0, 0.0)
//	Ray_LLT Ray131(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray132(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray133(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray134(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -0.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray135(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//
//	SphericalSurface_LLT S13(/*radius*/9.0, /*semiHeight*/2.817458, /*Apex of the sphere*/{ 0.0, -1.0, 20.0 },
//		/*Direction*/ VectorStructR3{ 0.0, -1.0, 0.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.0);
//
//	IntersectInformationStruct InterInfo131 = S13.calculateIntersection(Ray131);
//	VectorStructR3 InterP131 = InterInfo131.getIntersectionPoint();
//	IntersectInformationStruct InterInfo132 = S13.calculateIntersection(Ray132);
//	VectorStructR3 InterP132 = InterInfo132.getIntersectionPoint();
//	IntersectInformationStruct InterInfo133 = S13.calculateIntersection(Ray133);
//	VectorStructR3 InterP133 = InterInfo133.getIntersectionPoint();
//	IntersectInformationStruct InterInfo134 = S13.calculateIntersection(Ray134);
//	VectorStructR3 InterP134 = InterInfo134.getIntersectionPoint();
//	IntersectInformationStruct InterInfo135 = S13.calculateIntersection(Ray135);
//	VectorStructR3 InterP135 = InterInfo135.getIntersectionPoint();
//
//	//________________________________________________________________________________________________________
//	//Linse um 90° gedreht, Startwert (0.0, 2.0, 0.0)
//	Ray_LLT Ray136(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray137(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray138(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray139(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray140(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -3.0, 15.0 }, /*wavelength*/500.0, 1.0);
//
//
//	IntersectInformationStruct InterInfo136 = S13.calculateIntersection(Ray136);
//	VectorStructR3 InterP136 = InterInfo136.getIntersectionPoint();
//	IntersectInformationStruct InterInfo137 = S13.calculateIntersection(Ray137);
//	VectorStructR3 InterP137 = InterInfo137.getIntersectionPoint();
//	IntersectInformationStruct InterInfo138 = S13.calculateIntersection(Ray138);
//	VectorStructR3 InterP138 = InterInfo138.getIntersectionPoint();
//	IntersectInformationStruct InterInfo139 = S13.calculateIntersection(Ray139);
//	VectorStructR3 InterP139 = InterInfo139.getIntersectionPoint();
//	IntersectInformationStruct InterInfo140 = S13.calculateIntersection(Ray140);
//	VectorStructR3 InterP140 = InterInfo140.getIntersectionPoint();
//
//	std::vector<VectorStructR3> checkVector108 = { InterP131, InterP132, InterP133, InterP134, InterP135, InterP136, InterP137, InterP138, InterP139, InterP140 };
//
//
//	std::vector<VectorStructR3> ReferenzVector108 = { { 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, -1.2057669623, 18.086504435 },
//	{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, -1.1049393846, 18.629636308 },{ 0.0, -1.4425213939, 17.212606970 } };
//
//
//	bool isRight108 = Math::compareAllVectorElements(checkVector108, ReferenzVector108, 9);
//	checkMethodesSphericalLens.push_back(isRight108);
//
//	//________________________________________________________________________________________________________________________________________________________________
//	//________________________________________________________________________________________________________________________________________________________________
//	// Linse -90° gedreht, Apex Sphere (0.0, -1.0, 20.0)
//	// Startwert (0.0, 0.0, 0.0)
//	Ray_LLT Ray141(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray142(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray143(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray144(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -0.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray145(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//
//	SphericalSurface_LLT S14(/*radius*/9.0, /*semiHeight*/2.817458, /*Apex of the sphere*/{ 0.0, -1.0, 20.0 },
//		/*Direction*/ VectorStructR3{ 0.0, 1.0, 0.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.0);
//
//	IntersectInformationStruct InterInfo141 = S14.calculateIntersection(Ray141);
//	VectorStructR3 InterP141 = InterInfo141.getIntersectionPoint();
//	IntersectInformationStruct InterInfo142 = S14.calculateIntersection(Ray142);
//	VectorStructR3 InterP142 = InterInfo142.getIntersectionPoint();
//	IntersectInformationStruct InterInfo143 = S14.calculateIntersection(Ray143);
//	VectorStructR3 InterP143 = InterInfo143.getIntersectionPoint();
//	IntersectInformationStruct InterInfo144 = S14.calculateIntersection(Ray144);
//	VectorStructR3 InterP144 = InterInfo144.getIntersectionPoint();
//	IntersectInformationStruct InterInfo145 = S14.calculateIntersection(Ray145);
//	VectorStructR3 InterP145 = InterInfo145.getIntersectionPoint();
//
//	//________________________________________________________________________________________________________
//	//Linse um -90° gedreht, Startwert (0.0, 2.0, 0.0)
//	Ray_LLT Ray146(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray147(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray148(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray149(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray150(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -3.0, 15.0 }, /*wavelength*/500.0, 1.0);
//
//
//	//InterP148 trifft Linse von oben, Zemax gibt keinen Schnittpunkt an -> In Referenzvketor Schnittpunkt des Programms eingesetzt
//	IntersectInformationStruct InterInfo146 = S14.calculateIntersection(Ray146);
//	VectorStructR3 InterP146 = InterInfo146.getIntersectionPoint();
//	IntersectInformationStruct InterInfo147 = S14.calculateIntersection(Ray147);
//	VectorStructR3 InterP147 = InterInfo147.getIntersectionPoint();
//	IntersectInformationStruct InterInfo148 = S14.calculateIntersection(Ray148);
//	VectorStructR3 InterP148 = InterInfo148.getIntersectionPoint();
//	IntersectInformationStruct InterInfo149 = S14.calculateIntersection(Ray149);
//	VectorStructR3 InterP149 = InterInfo149.getIntersectionPoint();
//	IntersectInformationStruct InterInfo150 = S14.calculateIntersection(Ray150);
//	VectorStructR3 InterP150 = InterInfo150.getIntersectionPoint();
//
//	std::vector<VectorStructR3> checkVector109 = { InterP141, InterP142, InterP143,  InterP144, InterP145, InterP146, InterP147, InterP148, InterP149, InterP150 };
//
//
//	std::vector<VectorStructR3> ReferenzVector109 = { { 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, -0.57563229773, 17.268968932 },{ 0.0, 0.0, 0.0 },
//	{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, -0.86993782540169828, 21.524533690512737 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 } };
//
//
//	bool isRight109 = Math::compareAllVectorElements(checkVector109, ReferenzVector109, 9);
//	checkMethodesSphericalLens.push_back(isRight109);
//
//
//	//________________________________________________________________________________________________________________________________________________________________
//	//________________________________________________________________________________________________________________________________________________________________
//	//________________________________________________________________________________________________________________________________________________________________
//	// Linse 0° gedreht, Apex Sphere (1.0, 0.0, 20.0)
//	// Startwert (0.0, 0.0, 0.0)
//	Ray_LLT Ray151(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray152(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray153(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray154(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -0.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray155(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//
//	SphericalSurface_LLT S15(/*radius*/9.0, /*semiHeight*/2.817458, /*Apex of the sphere*/{ 1.0, 0.0, 20.0 },
//		/*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.0);
//
//	IntersectInformationStruct InterInfo151 = S15.calculateIntersection(Ray151);
//	VectorStructR3 InterP151 = InterInfo151.getIntersectionPoint();
//	IntersectInformationStruct InterInfo152 = S15.calculateIntersection(Ray152);
//	VectorStructR3 InterP152 = InterInfo152.getIntersectionPoint();
//	IntersectInformationStruct InterInfo153 = S15.calculateIntersection(Ray153);
//	VectorStructR3 InterP153 = InterInfo153.getIntersectionPoint();
//	IntersectInformationStruct InterInfo154 = S15.calculateIntersection(Ray154);
//	VectorStructR3 InterP154 = InterInfo154.getIntersectionPoint();
//	IntersectInformationStruct InterInfo155 = S15.calculateIntersection(Ray155);
//	VectorStructR3 InterP155 = InterInfo155.getIntersectionPoint();
//
//	//________________________________________________________________________________________________________
//	//Linse um 0° gedreht, Startwert (0.0, 2.0, 0.0)
//	Ray_LLT Ray156(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray157(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray158(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray159(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray160(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -3.0, 15.0 }, /*wavelength*/500.0, 1.0);
//
//
//	//InterP157 stimmt nicht exakt mit ZEMAX-Schnittpunkt überein -> Übereinstimmung auf Kommazahlen auf 8 heruntergesetzt
//	IntersectInformationStruct InterInfo156 = S15.calculateIntersection(Ray156);
//	VectorStructR3 InterP156 = InterInfo156.getIntersectionPoint();
//	IntersectInformationStruct InterInfo157 = S15.calculateIntersection(Ray157);
//	VectorStructR3 InterP157 = InterInfo157.getIntersectionPoint();
//	IntersectInformationStruct InterInfo158 = S15.calculateIntersection(Ray158);
//	VectorStructR3 InterP158 = InterInfo158.getIntersectionPoint();
//	IntersectInformationStruct InterInfo159 = S15.calculateIntersection(Ray159);
//	VectorStructR3 InterP159 = InterInfo159.getIntersectionPoint();
//	IntersectInformationStruct InterInfo160 = S15.calculateIntersection(Ray160);
//	VectorStructR3 InterP160 = InterInfo160.getIntersectionPoint();
//
//	std::vector<VectorStructR3> checkVector110 = { InterP151, InterP152, InterP153, InterP154, InterP155, InterP156, InterP157, InterP158, InterP159, InterP160 };
//
//
//	std::vector<VectorStructR3> ReferenzVector110 = { { 0.0, 1.3438169363, 20.157254044 },{ 0.0, 0.66936032118, 20.080809635 },{ 0.0, 0.0, 20.055728090 },{ 0.0, -0.66936032118, 20.080809635 },{ 0.0, -1.3438169363, 20.157254044 },
//	{ 0.0, 0.66131934484, 20.080209827 },{ 0.0, -0.0055729826237, 20.055729826 },{ 0.0, -0.67752346849, 20.081426014 },{ 0.0, -1.3599535611, 20.159721367 },{ 0.0, -2.0591990429, 20.295995215 } };
//
//
//	bool isRight110 = Math::compareAllVectorElements(checkVector110, ReferenzVector110, 7);
//	checkMethodesSphericalLens.push_back(isRight110);
//
//
//	//________________________________________________________________________________________________________________________________________________________________
//	//________________________________________________________________________________________________________________________________________________________________
//	// Linse 45° gedreht, Apex Sphere (1.0, 0.0, 20.0)
//	// Startwert (0.0, 0.0, 0.0)
//	Ray_LLT Ray161(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray162(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray163(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray164(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -0.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray165(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//
//	SphericalSurface_LLT S16(/*radius*/9.0, /*semiHeight*/2.817458, /*Apex of the sphere*/{ 1.0, 0.0, 20.0 },
//		/*Direction*/ VectorStructR3{ 0.0, -1.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.0);
//
//	IntersectInformationStruct InterInfo161 = S16.calculateIntersection(Ray161);
//	VectorStructR3 InterP161 = InterInfo161.getIntersectionPoint();
//	IntersectInformationStruct InterInfo162 = S16.calculateIntersection(Ray162);
//	VectorStructR3 InterP162 = InterInfo162.getIntersectionPoint();
//	IntersectInformationStruct InterInfo163 = S16.calculateIntersection(Ray163);
//	VectorStructR3 InterP163 = InterInfo163.getIntersectionPoint();
//	IntersectInformationStruct InterInfo164 = S16.calculateIntersection(Ray164);
//	VectorStructR3 InterP164 = InterInfo164.getIntersectionPoint();
//	IntersectInformationStruct InterInfo165 = S16.calculateIntersection(Ray165);
//	VectorStructR3 InterP165 = InterInfo165.getIntersectionPoint();
//
//	//________________________________________________________________________________________________________
//	//Linse um 45° gedreht, Startwert (0.0, 2.0, 0.0)
//	Ray_LLT Ray166(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray167(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray168(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray169(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray170(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -3.0, 15.0 }, /*wavelength*/500.0, 1.0);
//
//
//	IntersectInformationStruct InterInfo166 = S16.calculateIntersection(Ray166);
//	VectorStructR3 InterP166 = InterInfo166.getIntersectionPoint();
//	IntersectInformationStruct InterInfo167 = S16.calculateIntersection(Ray167);
//	VectorStructR3 InterP167 = InterInfo167.getIntersectionPoint();
//	IntersectInformationStruct InterInfo168 = S16.calculateIntersection(Ray168);
//	VectorStructR3 InterP168 = InterInfo168.getIntersectionPoint();
//	IntersectInformationStruct InterInfo169 = S16.calculateIntersection(Ray169);
//	VectorStructR3 InterP169 = InterInfo169.getIntersectionPoint();
//	IntersectInformationStruct InterInfo170 = S16.calculateIntersection(Ray170);
//	VectorStructR3 InterP170 = InterInfo170.getIntersectionPoint();
//
//	std::vector<VectorStructR3> checkVector112 = { InterP161, InterP162, InterP163, InterP164, InterP165, InterP166, InterP167, InterP168, InterP169, InterP170 };
//
//
//	std::vector<VectorStructR3> ReferenzVector112 = { { 0.0, 1.4698348265, 22.047522398 },{ 0.0, 0.69573625181, 20.872087554 },{ 0.0, 0.0, 20.079058486 },{ 0.0, -0.64944146832, 19.483244050 },{ 0.0, -1.2675775589, 19.013663383 },
//	{ 0.0, 0.61531710528, 20.770243421 },{ 0.0, -0.0071796788928, 20.071796789 },{ 0.0, -0.60294972288, 19.522122922 },{ 0.0, -1.1792795683, 19.075677410 },{ 0.0, -1.7413664712, 18.706832356 } };
//
//
//	bool isRight112 = Math::compareAllVectorElements(checkVector112, ReferenzVector112, 9);
//	checkMethodesSphericalLens.push_back(isRight112);
//
//	//________________________________________________________________________________________________________________________________________________________________
//	//________________________________________________________________________________________________________________________________________________________________
//	// Linse -45° gedreht, Apex Sphere (1.0, 0.0, 20.0)
//	// Startwert (0.0, 0.0, 0.0)
//	Ray_LLT Ray171(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray172(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray173(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray174(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -0.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray175(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//
//	SphericalSurface_LLT S17(/*radius*/9.0, /*semiHeight*/2.817458, /*Apex of the sphere*/{ 1.0, 0.0, 20.0 },
//		/*Direction*/ VectorStructR3{ 0.0, 1.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.0);
//
//	IntersectInformationStruct InterInfo171 = S17.calculateIntersection(Ray171);
//	VectorStructR3 InterP171 = InterInfo171.getIntersectionPoint();
//	IntersectInformationStruct InterInfo172 = S17.calculateIntersection(Ray172);
//	VectorStructR3 InterP172 = InterInfo172.getIntersectionPoint();
//	IntersectInformationStruct InterInfo173 = S17.calculateIntersection(Ray173);
//	VectorStructR3 InterP173 = InterInfo173.getIntersectionPoint();
//	IntersectInformationStruct InterInfo174 = S17.calculateIntersection(Ray174);
//	VectorStructR3 InterP174 = InterInfo174.getIntersectionPoint();
//	IntersectInformationStruct InterInfo175 = S17.calculateIntersection(Ray175);
//	VectorStructR3 InterP175 = InterInfo175.getIntersectionPoint();
//
//	//________________________________________________________________________________________________________
//	//Linse um -45° gedreht, Startwert (0.0, 2.0, 0.0)
//	Ray_LLT Ray176(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray177(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray178(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray179(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray180(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -3.0, 15.0 }, /*wavelength*/500.0, 1.0);
//
//
//	//InterP177 stimmt nicht exakt mit ZEMAX-Schnittpunkt überein -> Übereinstimmung auf Kommazahlen auf 8 heruntergesetzt
//	IntersectInformationStruct InterInfo176 = S17.calculateIntersection(Ray176);
//	VectorStructR3 InterP176 = InterInfo176.getIntersectionPoint();
//	IntersectInformationStruct InterInfo177 = S17.calculateIntersection(Ray177);
//	VectorStructR3 InterP177 = InterInfo177.getIntersectionPoint();
//	IntersectInformationStruct InterInfo178 = S17.calculateIntersection(Ray178);
//	VectorStructR3 InterP178 = InterInfo178.getIntersectionPoint();
//	IntersectInformationStruct InterInfo179 = S17.calculateIntersection(Ray179);
//	VectorStructR3 InterP179 = InterInfo179.getIntersectionPoint();
//	IntersectInformationStruct InterInfo180 = S17.calculateIntersection(Ray180);
//	VectorStructR3 InterP180 = InterInfo180.getIntersectionPoint();
//
//	std::vector<VectorStructR3> checkVector113 = { InterP171, InterP172, InterP173, InterP174, InterP175, InterP176, InterP177, InterP178, InterP179, InterP180 };
//
//
//	std::vector<VectorStructR3> ReferenzVector113 = { { 0.0, 1.2675775589, 19.013663383 },{ 0.0, 0.64944146832, 19.483244050 },{ 0.0, 0.0, 20.079058486 },{ 0.0, -0.69573625181, 20.872087554 },{ 0.0, -1.4698348265, 22.047522398 },
//	{ 0.0, 0.70412017130, 19.438197430 },{ 0.0, -0.0087979606378, 20.087979606 },{ 0.0, -0.80142946372, 21.010720978 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 } };
//
//
//	bool isRight113 = Math::compareAllVectorElements(checkVector113, ReferenzVector113, 8);
//	checkMethodesSphericalLens.push_back(isRight113);
//
//
//	//________________________________________________________________________________________________________________________________________________________________
//	//________________________________________________________________________________________________________________________________________________________________
//	// Linse 90° gedreht, Apex Sphere (1.0, 0.0, 20.0)
//	// Startwert (0.0, 0.0, 0.0)
//	Ray_LLT Ray181(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray182(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray183(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray184(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -0.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray185(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//
//	SphericalSurface_LLT S18(/*radius*/9.0, /*semiHeight*/2.817458, /*Apex of the sphere*/{ 1.0, 0.0, 20.0 },
//		/*Direction*/ VectorStructR3{ 0.0, -1.0, 0.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.0);
//
//	IntersectInformationStruct InterInfo181 = S18.calculateIntersection(Ray181);
//	VectorStructR3 InterP181 = InterInfo181.getIntersectionPoint();
//	IntersectInformationStruct InterInfo182 = S18.calculateIntersection(Ray182);
//	VectorStructR3 InterP182 = InterInfo182.getIntersectionPoint();
//	IntersectInformationStruct InterInfo183 = S18.calculateIntersection(Ray183);
//	VectorStructR3 InterP183 = InterInfo183.getIntersectionPoint();
//	IntersectInformationStruct InterInfo184 = S18.calculateIntersection(Ray184);
//	VectorStructR3 InterP184 = InterInfo184.getIntersectionPoint();
//	IntersectInformationStruct InterInfo185 = S18.calculateIntersection(Ray185);
//	VectorStructR3 InterP185 = InterInfo185.getIntersectionPoint();
//
//	//________________________________________________________________________________________________________
//	//Linse um 90° gedreht, Startwert (0.0, 2.0, 0.0)
//	Ray_LLT Ray186(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray187(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray188(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray189(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray190(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -3.0, 15.0 }, /*wavelength*/500.0, 1.0);
//
//
//	IntersectInformationStruct InterInfo186 = S18.calculateIntersection(Ray186);
//	VectorStructR3 InterP186 = InterInfo186.getIntersectionPoint();
//	IntersectInformationStruct InterInfo187 = S18.calculateIntersection(Ray187);
//	VectorStructR3 InterP187 = InterInfo187.getIntersectionPoint();
//	IntersectInformationStruct InterInfo188 = S18.calculateIntersection(Ray188);
//	VectorStructR3 InterP188 = InterInfo188.getIntersectionPoint();
//	IntersectInformationStruct InterInfo189 = S18.calculateIntersection(Ray189);
//	VectorStructR3 InterP189 = InterInfo189.getIntersectionPoint();
//	IntersectInformationStruct InterInfo190 = S18.calculateIntersection(Ray190);
//	VectorStructR3 InterP190 = InterInfo190.getIntersectionPoint();
//
//	std::vector<VectorStructR3> checkVector114 = { InterP181, InterP182, InterP183, InterP184, InterP185, InterP186, InterP187, InterP188, InterP189, InterP190 };
//
//
//	std::vector<VectorStructR3> ReferenzVector114 = { { 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },
//	{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, -0.35883502699, 17.691262702 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 } };
//
//
//	bool isRight114 = Math::compareAllVectorElements(checkVector114, ReferenzVector114, 9);
//	checkMethodesSphericalLens.push_back(isRight114);
//
//	//________________________________________________________________________________________________________________________________________________________________
//	//________________________________________________________________________________________________________________________________________________________________
//	// Linse -90° gedreht, Apex Sphere (1.0, 0.0, 20.0)
//	// Startwert (0.0, 0.0, 0.0)
//	Ray_LLT Ray191(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray192(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray193(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray194(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -0.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray195(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//
//	SphericalSurface_LLT S19(/*radius*/9.0, /*semiHeight*/2.817458, /*Apex of the sphere*/{ 1.0, 0.0, 20.0 },
//		/*Direction*/ VectorStructR3{ 0.0, 1.0, 0.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.0);
//
//	IntersectInformationStruct InterInfo191 = S19.calculateIntersection(Ray191);
//	VectorStructR3 InterP191 = InterInfo191.getIntersectionPoint();
//	IntersectInformationStruct InterInfo192 = S19.calculateIntersection(Ray192);
//	VectorStructR3 InterP192 = InterInfo192.getIntersectionPoint();
//	IntersectInformationStruct InterInfo193 = S19.calculateIntersection(Ray193);
//	VectorStructR3 InterP193 = InterInfo193.getIntersectionPoint();
//	IntersectInformationStruct InterInfo194 = S19.calculateIntersection(Ray194);
//	VectorStructR3 InterP194 = InterInfo194.getIntersectionPoint();
//	IntersectInformationStruct InterInfo195 = S19.calculateIntersection(Ray195);
//	VectorStructR3 InterP195 = InterInfo195.getIntersectionPoint();
//
//	//________________________________________________________________________________________________________
//	//Linse um -90° gedreht, Startwert (0.0, 2.0, 0.0)
//	Ray_LLT Ray196(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray197(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray198(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray199(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray200(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -3.0, 15.0 }, /*wavelength*/500.0, 1.0);
//
//	//SphericalSurface_LLT S39(/*radius*/9.0, /*semiHeight*/2.817458, /*Apex of the sphere*/{ 1.0, 0.0, 20.0 },
//	//	/*Direction*/ VectorStructR3{ 0.0, 1.0, 0.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
//
//	IntersectInformationStruct InterInfo196 = S19.calculateIntersection(Ray196);
//	VectorStructR3 InterP196 = InterInfo196.getIntersectionPoint();
//	IntersectInformationStruct InterInfo197 = S19.calculateIntersection(Ray197);
//	VectorStructR3 InterP197 = InterInfo197.getIntersectionPoint();
//	IntersectInformationStruct InterInfo198 = S19.calculateIntersection(Ray198);
//	VectorStructR3 InterP198 = InterInfo198.getIntersectionPoint();
//	IntersectInformationStruct InterInfo199 = S19.calculateIntersection(Ray199);
//	VectorStructR3 InterP199 = InterInfo199.getIntersectionPoint();
//	IntersectInformationStruct InterInfo200 = S19.calculateIntersection(Ray200);
//	VectorStructR3 InterP200 = InterInfo200.getIntersectionPoint();
//
//	std::vector<VectorStructR3> checkVector115 = { InterP191, InterP192, InterP193, InterP194, InterP195, InterP196, InterP197, InterP198, InterP199, InterP200 };
//
//
//	std::vector<VectorStructR3> ReferenzVector115 = { { 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },
//	{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 } };
//
//
//	bool isRight115 = Math::compareAllVectorElements(checkVector115, ReferenzVector115, 9);
//	checkMethodesSphericalLens.push_back(isRight115);
//
//	//________________________________________________________________________________________________________________________________________________________________
//	//________________________________________________________________________________________________________________________________________________________________
//	//________________________________________________________________________________________________________________________________________________________________
//	// Linse 0° gedreht, Apex Sphere (1.0, 1.0, 20.0)
//	// Startwert (0.0, 0.0, 0.0)
//	Ray_LLT Ray201(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray202(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray203(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray204(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -0.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray205(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//
//	SphericalSurface_LLT S20(/*radius*/9.0, /*semiHeight*/2.817458, /*Apex of the sphere*/{ 1.0, 1.0, 20.0 },
//		/*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.0);
//
//	IntersectInformationStruct InterInfo201 = S20.calculateIntersection(Ray201);
//	VectorStructR3 InterP201 = InterInfo201.getIntersectionPoint();
//	IntersectInformationStruct InterInfo202 = S20.calculateIntersection(Ray202);
//	VectorStructR3 InterP202 = InterInfo202.getIntersectionPoint();
//	IntersectInformationStruct InterInfo203 = S20.calculateIntersection(Ray203);
//	VectorStructR3 InterP203 = InterInfo203.getIntersectionPoint();
//	IntersectInformationStruct InterInfo204 = S20.calculateIntersection(Ray204);
//	VectorStructR3 InterP204 = InterInfo204.getIntersectionPoint();
//	IntersectInformationStruct InterInfo205 = S20.calculateIntersection(Ray205);
//	VectorStructR3 InterP205 = InterInfo205.getIntersectionPoint();
//
//	//________________________________________________________________________________________________________
//	//Linse um 0° gedreht, Startwert (0.0, 2.0, 0.0)
//	Ray_LLT Ray206(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray207(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray208(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray209(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray210(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -3.0, 15.0 }, /*wavelength*/500.0, 1.0);
//
//
//	//InterP207: y-Wert  stimmt nicht mit ZEMAX überein -> Übereinstimmung der Kommazahlen auf 8 heruntergesetzt
//	IntersectInformationStruct InterInfo206 = S20.calculateIntersection(Ray206);
//	VectorStructR3 InterP206 = InterInfo206.getIntersectionPoint();
//	IntersectInformationStruct InterInfo207 = S20.calculateIntersection(Ray207);
//	VectorStructR3 InterP207 = InterInfo207.getIntersectionPoint();
//	IntersectInformationStruct InterInfo208 = S20.calculateIntersection(Ray208);
//	VectorStructR3 InterP208 = InterInfo208.getIntersectionPoint();
//	IntersectInformationStruct InterInfo209 = S20.calculateIntersection(Ray209);
//	VectorStructR3 InterP209 = InterInfo209.getIntersectionPoint();
//	IntersectInformationStruct InterInfo210 = S20.calculateIntersection(Ray210);
//	VectorStructR3 InterP210 = InterInfo210.getIntersectionPoint();
//
//	std::vector<VectorStructR3> checkVector116 = { InterP201, InterP202, InterP203, InterP204, InterP205, InterP206, InterP207, InterP208, InterP209, InterP210 };
//
//
//	std::vector<VectorStructR3> ReferenzVector116 = { { 0.0, 1.3374731264, 20.062096896 },{ 0.0, 0.66872882935, 20.061864881 },{ 0.0, 0.0, 20.111805583 },{ 0.0, -0.67379122302, 20.213736691 },{ 0.0, -1.3581458345, 20.372187518 },
//	{ 0.0, 0.66252687357, 20.062096896 },{ 0.0, -0.011308517642, 20.113085176 },{ 0.0, -0.69572581837,  20.217943638 },{ 0.0, -1.3971575097,  20.382945058 },{ 0.0, 0.0, 0.0 } };
//
//
//	bool isRight116 = Math::compareAllVectorElements(checkVector116, ReferenzVector116, 8);
//	checkMethodesSphericalLens.push_back(isRight116);
//
//
//	//________________________________________________________________________________________________________________________________________________________________
//	//________________________________________________________________________________________________________________________________________________________________
//	// Linse 45° gedreht, Apex Sphere (1.0, 1.0, 20.0)
//	// Startwert (0.0, 0.0, 0.0)
//	Ray_LLT Ray211(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray212(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray213(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray214(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -0.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray215(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//
//	SphericalSurface_LLT S21(/*radius*/9.0, /*semiHeight*/2.817458, /*Apex of the sphere*/{ 1.0, 1.0, 20.0 },
//		/*Direction*/ VectorStructR3{ 0.0, -1.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.0);
//
//	//InterP215: Programm gibt Schnittpunkt an, Strahl trifft Linse in Zemax, in Realtität nicht
//	IntersectInformationStruct InterInfo211 = S21.calculateIntersection(Ray211);
//	VectorStructR3 InterP211 = InterInfo211.getIntersectionPoint();
//	IntersectInformationStruct InterInfo212 = S21.calculateIntersection(Ray212);
//	VectorStructR3 InterP212 = InterInfo212.getIntersectionPoint();
//	IntersectInformationStruct InterInfo213 = S21.calculateIntersection(Ray213);
//	VectorStructR3 InterP213 = InterInfo213.getIntersectionPoint();
//	IntersectInformationStruct InterInfo214 = S21.calculateIntersection(Ray214);
//	VectorStructR3 InterP214 = InterInfo214.getIntersectionPoint();
//	IntersectInformationStruct InterInfo215 = S21.calculateIntersection(Ray215);
//	VectorStructR3 InterP215 = InterInfo215.getIntersectionPoint();
//
//	//________________________________________________________________________________________________________
//	//Linse um 45° gedreht, Startwert (0.0, 2.0, 0.0)
//	Ray_LLT Ray216(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray217(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray218(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray219(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray220(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -3.0, 15.0 }, /*wavelength*/500.0, 1.0);
//
//
//	//InterP217: y-Wert stimmt nicht exakt mit Zemax-Schnittpunkt überein -> Übereinstimmung Kommazahlen auf 8 heruntergesetzt
//	IntersectInformationStruct InterInfo216 = S21.calculateIntersection(Ray216);
//	VectorStructR3 InterP216 = InterInfo216.getIntersectionPoint();
//	IntersectInformationStruct InterInfo217 = S21.calculateIntersection(Ray217);
//	VectorStructR3 InterP217 = InterInfo217.getIntersectionPoint();
//	IntersectInformationStruct InterInfo218 = S21.calculateIntersection(Ray218);
//	VectorStructR3 InterP218 = InterInfo218.getIntersectionPoint();
//	IntersectInformationStruct InterInfo219 = S21.calculateIntersection(Ray219);
//	VectorStructR3 InterP219 = InterInfo219.getIntersectionPoint();
//	IntersectInformationStruct InterInfo220 = S21.calculateIntersection(Ray220);
//	VectorStructR3 InterP220 = InterInfo220.getIntersectionPoint();
//
//	std::vector<VectorStructR3> checkVector117 = { InterP211, InterP212, InterP213, InterP214, InterP215, InterP216, InterP217, InterP218, InterP219, InterP220 };
//
//
//	std::vector<VectorStructR3> ReferenzVector117 = { { 0.0, 1.3647475229, 20.471212843 },{ 0.0, 0.65836584658, 19.750975398 },{ 0.0, 0.0, 19.206592655 },{ 0.0, -0.62592410304, 18.777723091 },{ 0.0, 0.0, 0.0 },
//	{ 0.0, 0.68183815608, 19.772427659 },{ 0.0, 0.073753596848, 19.262464031 },{ 0.0, -0.51323693619, 18.849277021 },{ 0.0, -1.0849436945, 18.509662167 },{ 0.0, 0.0, 0.0 } };
//
//
//	bool isRight117 = Math::compareAllVectorElements(checkVector117, ReferenzVector117, 8);
//	checkMethodesSphericalLens.push_back(isRight117);
//
//	//________________________________________________________________________________________________________________________________________________________________
//	//________________________________________________________________________________________________________________________________________________________________
//	// Linse -45° gedreht, Apex Sphere (1.0, 1.0, 20.0)
//	// Startwert (0.0, 0.0, 0.0)
//	Ray_LLT Ray221(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray222(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray223(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray224(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -0.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray225(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//
//	SphericalSurface_LLT S22(/*radius*/9.0, /*semiHeight*/2.817458, /*Apex of the sphere*/{ 1.0, 1.0, 20.0 },
//		/*Direction*/ VectorStructR3{ 0.0, 1.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.0);
//
//	IntersectInformationStruct InterInfo221 = S22.calculateIntersection(Ray221);
//	VectorStructR3 InterP221 = InterInfo221.getIntersectionPoint();
//	IntersectInformationStruct InterInfo222 = S22.calculateIntersection(Ray222);
//	VectorStructR3 InterP222 = InterInfo222.getIntersectionPoint();
//	IntersectInformationStruct InterInfo223 = S22.calculateIntersection(Ray223);
//	VectorStructR3 InterP223 = InterInfo223.getIntersectionPoint();
//	IntersectInformationStruct InterInfo224 = S22.calculateIntersection(Ray224);
//	VectorStructR3 InterP224 = InterInfo224.getIntersectionPoint();
//	IntersectInformationStruct InterInfo225 = S22.calculateIntersection(Ray225);
//	VectorStructR3 InterP225 = InterInfo225.getIntersectionPoint();
//
//	//________________________________________________________________________________________________________
//	//Linse um -45° gedreht, Startwert (0.0, 2.0, 0.0)
//	Ray_LLT Ray226(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray227(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray228(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray229(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray230(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -3.0, 15.0 }, /*wavelength*/500.0, 1.0);
//
//
//	IntersectInformationStruct InterInfo226 = S22.calculateIntersection(Ray226);
//	VectorStructR3 InterP226 = InterInfo226.getIntersectionPoint();
//	IntersectInformationStruct InterInfo227 = S22.calculateIntersection(Ray227);
//	VectorStructR3 InterP227 = InterInfo227.getIntersectionPoint();
//	IntersectInformationStruct InterInfo228 = S22.calculateIntersection(Ray228);
//	VectorStructR3 InterP228 = InterInfo228.getIntersectionPoint();
//	IntersectInformationStruct InterInfo229 = S22.calculateIntersection(Ray229);
//	VectorStructR3 InterP229 = InterInfo229.getIntersectionPoint();
//	IntersectInformationStruct InterInfo230 = S22.calculateIntersection(Ray230);
//	VectorStructR3 InterP230 = InterInfo230.getIntersectionPoint();
//
//	std::vector<VectorStructR3> checkVector118 = { InterP221, InterP222, InterP223, InterP224, InterP225, InterP226, InterP227, InterP228, InterP229, InterP230 };
//
//
//	std::vector<VectorStructR3> ReferenzVector118 = { { 0.0, 1.3181618439, 19.772427659 },{ 0.0, 0.68065881904, 20.419764571 },{ 0.0, 0.0, 21.287340310 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },
//	{ 0.0, 0.63525247711, 20.471212843 },{ 0.0, -0.15143383662, 21.514338366 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 } };
//
//
//	bool isRight118 = Math::compareAllVectorElements(checkVector118, ReferenzVector118, 9);
//	checkMethodesSphericalLens.push_back(isRight118);
//
//
//	//________________________________________________________________________________________________________________________________________________________________
//	//________________________________________________________________________________________________________________________________________________________________
//	// Linse 90° gedreht, Apex Sphere (1.0, 1.0, 20.0)
//	// Startwert (0.0, 0.0, 0.0)
//	Ray_LLT Ray231(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray232(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray233(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray234(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -0.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray235(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//
//	SphericalSurface_LLT S23(/*radius*/9.0, /*semiHeight*/2.817458, /*Apex of the sphere*/{ 1.0, 1.0, 20.0 },
//		/*Direction*/ VectorStructR3{ 0.0, -1.0, 0.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.0);
//
//	IntersectInformationStruct InterInfo231 = S23.calculateIntersection(Ray231);
//	VectorStructR3 InterP231 = InterInfo231.getIntersectionPoint();
//	IntersectInformationStruct InterInfo232 = S23.calculateIntersection(Ray232);
//	VectorStructR3 InterP232 = InterInfo232.getIntersectionPoint();
//	IntersectInformationStruct InterInfo233 = S23.calculateIntersection(Ray233);
//	VectorStructR3 InterP233 = InterInfo233.getIntersectionPoint();
//	IntersectInformationStruct InterInfo234 = S23.calculateIntersection(Ray234);
//	VectorStructR3 InterP234 = InterInfo234.getIntersectionPoint();
//	IntersectInformationStruct InterInfo235 = S23.calculateIntersection(Ray235);
//	VectorStructR3 InterP235 = InterInfo235.getIntersectionPoint();
//
//	//________________________________________________________________________________________________________
//	//Linse um 90° gedreht, Startwert (0.0, 2.0, 0.0)
//	Ray_LLT Ray236(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray237(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray238(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray239(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray240(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -3.0, 15.0 }, /*wavelength*/500.0, 1.0);
//
//
//	IntersectInformationStruct InterInfo236 = S23.calculateIntersection(Ray236);
//	VectorStructR3 InterP236 = InterInfo236.getIntersectionPoint();
//	IntersectInformationStruct InterInfo237 = S23.calculateIntersection(Ray237);
//	VectorStructR3 InterP237 = InterInfo237.getIntersectionPoint();
//	IntersectInformationStruct InterInfo238 = S23.calculateIntersection(Ray238);
//	VectorStructR3 InterP238 = InterInfo238.getIntersectionPoint();
//	IntersectInformationStruct InterInfo239 = S23.calculateIntersection(Ray239);
//	VectorStructR3 InterP239 = InterInfo239.getIntersectionPoint();
//	IntersectInformationStruct InterInfo240 = S23.calculateIntersection(Ray240);
//	VectorStructR3 InterP240 = InterInfo240.getIntersectionPoint();
//
//	std::vector<VectorStructR3> checkVector119 = { InterP231, InterP232, InterP233, InterP234, InterP235, InterP236, InterP237, InterP238, InterP239, InterP240 };
//
//
//	std::vector<VectorStructR3> ReferenzVector119 = { { 0.0, 0.0, 0.0 },{ 0.0, 0.58276048599, 17.482814580 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },
//	{ 0.0, 0.78031472599, 18.295279110 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 } };
//
//
//	bool isRight119 = Math::compareAllVectorElements(checkVector119, ReferenzVector119, 9);
//	checkMethodesSphericalLens.push_back(isRight119);
//
//	//________________________________________________________________________________________________________________________________________________________________
//	//________________________________________________________________________________________________________________________________________________________________
//	// Linse -90° gedreht, Apex Sphere (1.0, 1.0, 20.0)
//	// Startwert (0.0, 0.0, 0.0)
//	Ray_LLT Ray241(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray242(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray243(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray244(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -0.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray245(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//
//	SphericalSurface_LLT S24(/*radius*/9.0, /*semiHeight*/2.817458, /*Apex of the sphere*/{ 1.0, 1.0, 20.0 },
//		/*Direction*/ VectorStructR3{ 0.0, 1.0, 0.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.0);
//
//	IntersectInformationStruct InterInfo241 = S24.calculateIntersection(Ray241);
//	VectorStructR3 InterP241 = InterInfo241.getIntersectionPoint();
//	IntersectInformationStruct InterInfo242 = S24.calculateIntersection(Ray242);
//	VectorStructR3 InterP242 = InterInfo242.getIntersectionPoint();
//	IntersectInformationStruct InterInfo243 = S24.calculateIntersection(Ray243);
//	VectorStructR3 InterP243 = InterInfo243.getIntersectionPoint();
//	IntersectInformationStruct InterInfo244 = S24.calculateIntersection(Ray244);
//	VectorStructR3 InterP244 = InterInfo244.getIntersectionPoint();
//	IntersectInformationStruct InterInfo245 = S24.calculateIntersection(Ray245);
//	VectorStructR3 InterP245 = InterInfo245.getIntersectionPoint();
//
//	//________________________________________________________________________________________________________
//	//Linse um -90° gedreht, Startwert (0.0, 2.0, 0.0)
//	Ray_LLT Ray246(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray247(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray248(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray249(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray250(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -3.0, 15.0 }, /*wavelength*/500.0, 1.0);
//
//
//	IntersectInformationStruct InterInfo246 = S24.calculateIntersection(Ray246);
//	VectorStructR3 InterP246 = InterInfo246.getIntersectionPoint();
//	IntersectInformationStruct InterInfo247 = S24.calculateIntersection(Ray247);
//	VectorStructR3 InterP247 = InterInfo247.getIntersectionPoint();
//	IntersectInformationStruct InterInfo248 = S24.calculateIntersection(Ray248);
//	VectorStructR3 InterP248 = InterInfo248.getIntersectionPoint();
//	IntersectInformationStruct InterInfo249 = S24.calculateIntersection(Ray249);
//	VectorStructR3 InterP249 = InterInfo249.getIntersectionPoint();
//	IntersectInformationStruct InterInfo250 = S24.calculateIntersection(Ray250);
//	VectorStructR3 InterP250 = InterInfo250.getIntersectionPoint();
//
//	std::vector<VectorStructR3> checkVector120 = { InterP241, InterP242, InterP243, InterP244, InterP245, InterP246, InterP247, InterP248, InterP249, InterP250 };
//
//
//	std::vector<VectorStructR3> ReferenzVector120 = { { 0.0, 1.2196852740, 18.295279110 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },
//	{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 } };
//
//
//	bool isRight120 = Math::compareAllVectorElements(checkVector120, ReferenzVector120, 9);
//	checkMethodesSphericalLens.push_back(isRight120);
//
//
//
//	//________________________________________________________________________________________________________________________________________________________________
//	//________________________________________________________________________________________________________________________________________________________________
//	//________________________________________________________________________________________________________________________________________________________________
//	// Linse 0° gedreht, Apex Sphere (1.0, -1.0, 20.0)
//	// Startwert (0.0, 0.0, 0.0)
//	Ray_LLT Ray251(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray252(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray253(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray254(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -0.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray255(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//
//	SphericalSurface_LLT S25(/*radius*/9.0, /*semiHeight*/2.817458, /*Apex of the sphere*/{ 1.0, -1.0, 20.0 },
//		/*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.0);
//
//	IntersectInformationStruct InterInfo251 = S25.calculateIntersection(Ray251);
//	VectorStructR3 InterP251 = InterInfo251.getIntersectionPoint();
//	IntersectInformationStruct InterInfo252 = S25.calculateIntersection(Ray252);
//	VectorStructR3 InterP252 = InterInfo252.getIntersectionPoint();
//	IntersectInformationStruct InterInfo253 = S25.calculateIntersection(Ray253);
//	VectorStructR3 InterP253 = InterInfo253.getIntersectionPoint();
//	IntersectInformationStruct InterInfo254 = S25.calculateIntersection(Ray254);
//	VectorStructR3 InterP254 = InterInfo254.getIntersectionPoint();
//	IntersectInformationStruct InterInfo255 = S25.calculateIntersection(Ray255);
//	VectorStructR3 InterP255 = InterInfo255.getIntersectionPoint();
//
//	//________________________________________________________________________________________________________
//	//Linse um 0° gedreht, Startwert (0.0, 2.0, 0.0)
//	Ray_LLT Ray256(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray257(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray258(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray259(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray260(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -3.0, 15.0 }, /*wavelength*/500.0, 1.0);
//
//
//	IntersectInformationStruct InterInfo256 = S25.calculateIntersection(Ray256);
//	VectorStructR3 InterP256 = InterInfo256.getIntersectionPoint();
//	IntersectInformationStruct InterInfo257 = S25.calculateIntersection(Ray257);
//	VectorStructR3 InterP257 = InterInfo257.getIntersectionPoint();
//	IntersectInformationStruct InterInfo258 = S25.calculateIntersection(Ray258);
//	VectorStructR3 InterP258 = InterInfo258.getIntersectionPoint();
//	IntersectInformationStruct InterInfo259 = S25.calculateIntersection(Ray259);
//	VectorStructR3 InterP259 = InterInfo259.getIntersectionPoint();
//	IntersectInformationStruct InterInfo260 = S25.calculateIntersection(Ray260);
//	VectorStructR3 InterP260 = InterInfo260.getIntersectionPoint();
//
//	std::vector<VectorStructR3> checkVector121 = { InterP251, InterP252, InterP253, InterP254, InterP255, InterP256, InterP257, InterP258, InterP259, InterP260 };
//
//
//	std::vector<VectorStructR3> ReferenzVector121 = { { 0.0, 1.3581458345, 20.372187518 },{ 0.0, 0.67379122302, 20.213736691 },{ 0.0, 0.0, 20.111805583 },{ 0.0, -0.66872882935, 20.061864881 },{ 0.0, -1.3374731264, 20.062096896 },
//	{ 0.0, 0.65268386790, 20.209741981 },{ 0.0, -0.011056855272, 20.110568553 },{ 0.0, -0.67488517773, 20.061638833 },{ 0.0, -1.3437225076, 20.062335046 },{ 0.0, -2.0228819681, 20.114409841 } };
//
//
//	bool isRight121 = Math::compareAllVectorElements(checkVector121, ReferenzVector121, 9);
//	checkMethodesSphericalLens.push_back(isRight121);
//
//
//	//________________________________________________________________________________________________________________________________________________________________
//	//________________________________________________________________________________________________________________________________________________________________
//	// Linse 45° gedreht, Apex Sphere (1.0, -1.0, 20.0)
//	// Startwert (0.0, 0.0, 0.0)
//	Ray_LLT Ray261(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray262(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray263(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray264(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -0.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray265(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//
//	SphericalSurface_LLT S26(/*radius*/9.0, /*semiHeight*/2.817458, /*Apex of the sphere*/{ 1.0, -1.0, 20.0 },
//		/*Direction*/ VectorStructR3{ 0.0, -1.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.0);
//
//	IntersectInformationStruct InterInfo261 = S26.calculateIntersection(Ray261);
//	VectorStructR3 InterP261 = InterInfo261.getIntersectionPoint();
//	IntersectInformationStruct InterInfo262 = S26.calculateIntersection(Ray262);
//	VectorStructR3 InterP262 = InterInfo262.getIntersectionPoint();
//	IntersectInformationStruct InterInfo263 = S26.calculateIntersection(Ray263);
//	VectorStructR3 InterP263 = InterInfo263.getIntersectionPoint();
//	IntersectInformationStruct InterInfo264 = S26.calculateIntersection(Ray264);
//	VectorStructR3 InterP264 = InterInfo264.getIntersectionPoint();
//	IntersectInformationStruct InterInfo265 = S26.calculateIntersection(Ray265);
//	VectorStructR3 InterP265 = InterInfo265.getIntersectionPoint();
//
//	//________________________________________________________________________________________________________
//	//Linse um 45° gedreht, Startwert (0.0, 2.0, 0.0)
//	Ray_LLT Ray266(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray267(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray268(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray269(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray270(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -3.0, 15.0 }, /*wavelength*/500.0, 1.0);
//
//
//	IntersectInformationStruct InterInfo266 = S26.calculateIntersection(Ray266);
//	VectorStructR3 InterP266 = InterInfo266.getIntersectionPoint();
//	IntersectInformationStruct InterInfo267 = S26.calculateIntersection(Ray267);
//	VectorStructR3 InterP267 = InterInfo267.getIntersectionPoint();
//	IntersectInformationStruct InterInfo268 = S26.calculateIntersection(Ray268);
//	VectorStructR3 InterP268 = InterInfo268.getIntersectionPoint();
//	IntersectInformationStruct InterInfo269 = S26.calculateIntersection(Ray269);
//	VectorStructR3 InterP269 = InterInfo269.getIntersectionPoint();
//	IntersectInformationStruct InterInfo270 = S26.calculateIntersection(Ray260);
//	VectorStructR3 InterP270 = InterInfo270.getIntersectionPoint();
//
//	std::vector<VectorStructR3> checkVector122 = { InterP261, InterP262, InterP263, InterP264, InterP265, InterP266, InterP267, InterP268, InterP269, InterP270 };
//
//
//	std::vector<VectorStructR3> ReferenzVector122 = { { 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 21.287340310 },{ 0.0, -0.68065881904 , 20.419764571 },{ 0.0, -1.3181618439, 19.772427659 },
//	{ 0.0, 0.52356616967, 22.146507455 },{ 0.0, -0.11275491095, 21.127549109 },{ 0.0, -0.71719214830, 20.378941112 },{ 0.0, -1.2984300534, 19.790580320 },{ 0.0, -1.8623672261, 19.311836130 } };
//
//
//	bool isRight122 = Math::compareAllVectorElements(checkVector122, ReferenzVector122, 9);
//	checkMethodesSphericalLens.push_back(isRight122);
//
//	//________________________________________________________________________________________________________________________________________________________________
//	//________________________________________________________________________________________________________________________________________________________________
//	// Linse -45° gedreht, Apex Sphere (1.0, -1.0, 20.0)
//	// Startwert (0.0, 0.0, 0.0)
//	Ray_LLT Ray271(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray272(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray273(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray274(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -0.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray275(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//
//	SphericalSurface_LLT S27(/*radius*/9.0, /*semiHeight*/2.817458, /*Apex of the sphere*/{ 1.0, -1.0, 20.0 },
//		/*Direction*/ VectorStructR3{ 0.0, 1.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.0);
//
//	//InterP271: Programm gibt keinen Schnittpunkt mit Linse an, Strahl trifft Linse in Zemax, in Realtität nicht
//	IntersectInformationStruct InterInfo271 = S27.calculateIntersection(Ray271);
//	VectorStructR3 InterP271 = InterInfo271.getIntersectionPoint();
//	IntersectInformationStruct InterInfo272 = S27.calculateIntersection(Ray272);
//	VectorStructR3 InterP272 = InterInfo272.getIntersectionPoint();
//	IntersectInformationStruct InterInfo273 = S27.calculateIntersection(Ray273);
//	VectorStructR3 InterP273 = InterInfo273.getIntersectionPoint();
//	IntersectInformationStruct InterInfo274 = S27.calculateIntersection(Ray274);
//	VectorStructR3 InterP274 = InterInfo274.getIntersectionPoint();
//	IntersectInformationStruct InterInfo275 = S27.calculateIntersection(Ray275);
//	VectorStructR3 InterP275 = InterInfo275.getIntersectionPoint();
//
//	//________________________________________________________________________________________________________
//	//Linse um -45° gedreht, Startwert (0.0, 2.0, 0.0)
//	Ray_LLT Ray276(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray277(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray278(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray279(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray280(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -3.0, 15.0 }, /*wavelength*/500.0, 1.0);
//
//
//	IntersectInformationStruct InterInfo276 = S27.calculateIntersection(Ray276);
//	VectorStructR3 InterP276 = InterInfo276.getIntersectionPoint();
//	IntersectInformationStruct InterInfo277 = S27.calculateIntersection(Ray277);
//	VectorStructR3 InterP277 = InterInfo277.getIntersectionPoint();
//	IntersectInformationStruct InterInfo278 = S27.calculateIntersection(Ray278);
//	VectorStructR3 InterP278 = InterInfo278.getIntersectionPoint();
//	IntersectInformationStruct InterInfo279 = S27.calculateIntersection(Ray279);
//	VectorStructR3 InterP279 = InterInfo279.getIntersectionPoint();
//	IntersectInformationStruct InterInfo280 = S27.calculateIntersection(Ray280);
//	VectorStructR3 InterP280 = InterInfo280.getIntersectionPoint();
//
//	std::vector<VectorStructR3> checkVector123 = { InterP271, InterP272, InterP273, InterP274, InterP275, InterP276, InterP277, InterP278, InterP279, InterP280 };
//
//
//	std::vector<VectorStructR3> ReferenzVector123 = { { 0.0, 0.0, 0.0 },{ 0.0, 0.62592410304, 18.777723091 },{ 0.0,  0.0, 19.206592655 },{ 0.0, -0.65836584658, 19.750975398 },{ 0.0, -1.3647475229, 20.471212843 },
//	{ 0.0, 0.75335967435, 18.699604885 },{ 0.0, 0.085682685652, 19.143173143 },{ 0.0, -0.63003850027, 19.725288752 },{ 0.0, -1.4230827549, 20.538496530 },{ 0.0, -2.3764396609, 21.882198304 } };
//
//
//	bool isRight123 = Math::compareAllVectorElements(checkVector123, ReferenzVector123, 9);
//	checkMethodesSphericalLens.push_back(isRight123);
//
//
//	//________________________________________________________________________________________________________________________________________________________________
//	//________________________________________________________________________________________________________________________________________________________________
//	// Linse 90° gedreht, Apex Sphere (1.0, -1.0, 20.0)
//	// Startwert (0.0, 0.0, 0.0)
//	Ray_LLT Ray281(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray282(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray283(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray284(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -0.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray285(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//
//	SphericalSurface_LLT S28(/*radius*/9.0, /*semiHeight*/2.817458, /*Apex of the sphere*/{ 1.0, -1.0, 20.0 },
//		/*Direction*/ VectorStructR3{ 0.0, -1.0, 0.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.0);
//
//	IntersectInformationStruct InterInfo281 = S28.calculateIntersection(Ray281);
//	VectorStructR3 InterP281 = InterInfo281.getIntersectionPoint();
//	IntersectInformationStruct InterInfo282 = S28.calculateIntersection(Ray282);
//	VectorStructR3 InterP282 = InterInfo282.getIntersectionPoint();
//	IntersectInformationStruct InterInfo283 = S28.calculateIntersection(Ray283);
//	VectorStructR3 InterP283 = InterInfo283.getIntersectionPoint();
//	IntersectInformationStruct InterInfo284 = S28.calculateIntersection(Ray284);
//	VectorStructR3 InterP284 = InterInfo284.getIntersectionPoint();
//	IntersectInformationStruct InterInfo285 = S28.calculateIntersection(Ray285);
//	VectorStructR3 InterP285 = InterInfo285.getIntersectionPoint();
//
//	//________________________________________________________________________________________________________
//	//Linse um 90° gedreht, Startwert (0.0, 2.0, 0.0)
//	Ray_LLT Ray286(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray287(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray288(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray289(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray290(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -3.0, 15.0 }, /*wavelength*/500.0, 1.0);
//
//
//	//InterP290: Programm gibt keinen Schnittpunkt mit Linse an, Strahl trifft Linse in Zemax, in Realtität nicht
//	IntersectInformationStruct InterInfo286 = S28.calculateIntersection(Ray286);
//	VectorStructR3 InterP286 = InterInfo286.getIntersectionPoint();
//	IntersectInformationStruct InterInfo287 = S28.calculateIntersection(Ray287);
//	VectorStructR3 InterP287 = InterInfo287.getIntersectionPoint();
//	IntersectInformationStruct InterInfo288 = S28.calculateIntersection(Ray288);
//	VectorStructR3 InterP288 = InterInfo288.getIntersectionPoint();
//	IntersectInformationStruct InterInfo289 = S28.calculateIntersection(Ray289);
//	VectorStructR3 InterP289 = InterInfo289.getIntersectionPoint();
//	IntersectInformationStruct InterInfo290 = S28.calculateIntersection(Ray290);
//	VectorStructR3 InterP290 = InterInfo290.getIntersectionPoint();
//
//	std::vector<VectorStructR3> checkVector124 = { InterP281, InterP282, InterP283, InterP284, InterP285, InterP286, InterP287, InterP288, InterP289, InterP290 };
//
//
//	std::vector<VectorStructR3> ReferenzVector124 = { { 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, -1.2196852740, 18.295279110 },
//	{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, -1.1351351351, 18.810810811 },{ 0.0, 0.0, 0.0 } };
//
//
//	bool isRight124 = Math::compareAllVectorElements(checkVector124, ReferenzVector124, 9);
//	checkMethodesSphericalLens.push_back(isRight124);
//
//	//________________________________________________________________________________________________________________________________________________________________
//	//________________________________________________________________________________________________________________________________________________________________
//	// Linse -90° gedreht, Apex Sphere (1.0, -1.0, 20.0)
//	// Startwert (0.0, 0.0, 0.0)
//	Ray_LLT Ray291(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray292(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray293(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray294(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -0.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray295(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//
//	SphericalSurface_LLT S29(/*radius*/9.0, /*semiHeight*/2.817458, /*Apex of the sphere*/{ 1.0, -1.0, 20.0 },
//		/*Direction*/ VectorStructR3{ 0.0, 1.0, 0.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.0);
//
//	// InterP294 stimmt nicht mit ZEMAX-Schnittpunkt überein!
//	IntersectInformationStruct InterInfo291 = S29.calculateIntersection(Ray291);
//	VectorStructR3 InterP291 = InterInfo291.getIntersectionPoint();
//	IntersectInformationStruct InterInfo292 = S29.calculateIntersection(Ray292);
//	VectorStructR3 InterP292 = InterInfo292.getIntersectionPoint();
//	IntersectInformationStruct InterInfo293 = S29.calculateIntersection(Ray293);
//	VectorStructR3 InterP293 = InterInfo293.getIntersectionPoint();
//	IntersectInformationStruct InterInfo294 = S29.calculateIntersection(Ray294);
//	VectorStructR3 InterP294 = InterInfo294.getIntersectionPoint();
//	IntersectInformationStruct InterInfo295 = S29.calculateIntersection(Ray295);
//	VectorStructR3 InterP295 = InterInfo295.getIntersectionPoint();
//
//	//________________________________________________________________________________________________________
//	//Linse um -90° gedreht, Startwert (0.0, 2.0, 0.0)
//	Ray_LLT Ray296(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray297(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray298(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray299(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray300(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -3.0, 15.0 }, /*wavelength*/500.0, 1.0);
//
//
//	//InterP298 trifft Linse von oben, ZEMAX gibt keinen Schnittpunkt an -> Programm-Schnittpunkt als Referenz eingetragen
//	IntersectInformationStruct InterInfo296 = S29.calculateIntersection(Ray296);
//	VectorStructR3 InterP296 = InterInfo296.getIntersectionPoint();
//	IntersectInformationStruct InterInfo297 = S29.calculateIntersection(Ray297);
//	VectorStructR3 InterP297 = InterInfo297.getIntersectionPoint();
//	IntersectInformationStruct InterInfo298 = S29.calculateIntersection(Ray298);
//	VectorStructR3 InterP298 = InterInfo298.getIntersectionPoint();
//	// we compared our results with the zemax in sequential mode. To trace this ray we had to swith to NONsequential mode.
//	IntersectInformationStruct InterInfo299 = S29.calculateIntersection(Ray299);
//	VectorStructR3 InterP299 = InterInfo299.getIntersectionPoint();
//	IntersectInformationStruct InterInfo300 = S29.calculateIntersection(Ray300);
//	VectorStructR3 InterP300 = InterInfo300.getIntersectionPoint();
//
//	std::vector<VectorStructR3> checkVector125 = { InterP291, InterP292, InterP293, InterP294, InterP295, InterP296, InterP297, InterP298, InterP299, InterP300 };
//
//
//	std::vector<VectorStructR3> ReferenzVector125 = { { 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0,  -0.58276048599, 17.482814580 },{ 0.0, 0.0, 0.0 },
//	{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, -0.84439202936972979, 21.332940220272974 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 } };
//
//
//	bool isRight125 = Math::compareAllVectorElements(checkVector125, ReferenzVector125, 9);
//	checkMethodesSphericalLens.push_back(isRight125);
//
//
//	//____________________________________________________________________________________________________________________________________________________
//	//____________________________________________________________________________________________________________________________________________________
//	//____________________________________________________________________________________________________________________________________________________
//	// Linse 0° gedreht, Apex Sphere (-1.0, 0.0, 20.0)
//	// Startwert (0.0, 0.0, 0.0)
//	Ray_LLT Ray301(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray302(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray303(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray304(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -0.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray305(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//
//	SphericalSurface_LLT S30(/*radius*/9.0, /*semiHeight*/2.817458, /*Apex of the sphere*/{ -1.0, 0.0, 20.0 },
//		/*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.0);
//
//	IntersectInformationStruct InterInfo301 = S30.calculateIntersection(Ray301);
//	VectorStructR3 InterP301 = InterInfo301.getIntersectionPoint();
//	IntersectInformationStruct InterInfo302 = S30.calculateIntersection(Ray302);
//	VectorStructR3 InterP302 = InterInfo302.getIntersectionPoint();
//	IntersectInformationStruct InterInfo303 = S30.calculateIntersection(Ray303);
//	VectorStructR3 InterP303 = InterInfo303.getIntersectionPoint();
//	IntersectInformationStruct InterInfo304 = S30.calculateIntersection(Ray304);
//	VectorStructR3 InterP304 = InterInfo304.getIntersectionPoint();
//	IntersectInformationStruct InterInfo305 = S30.calculateIntersection(Ray305);
//	VectorStructR3 InterP305 = InterInfo305.getIntersectionPoint();
//
//	//________________________________________________________________________________________________________
//	//Linse um 0° gedreht, Startwert (0.0, 2.0, 0.0)
//	Ray_LLT Ray306(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray307(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray308(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray309(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray310(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -3.0, 15.0 }, /*wavelength*/500.0, 1.0);
//
//
//	IntersectInformationStruct InterInfo306 = S30.calculateIntersection(Ray306);
//	VectorStructR3 InterP306 = InterInfo306.getIntersectionPoint();
//	IntersectInformationStruct InterInfo307 = S30.calculateIntersection(Ray307);
//	VectorStructR3 InterP307 = InterInfo307.getIntersectionPoint();
//	IntersectInformationStruct InterInfo308 = S30.calculateIntersection(Ray308);
//	VectorStructR3 InterP308 = InterInfo308.getIntersectionPoint();
//	IntersectInformationStruct InterInfo309 = S30.calculateIntersection(Ray309);
//	VectorStructR3 InterP309 = InterInfo309.getIntersectionPoint();
//	IntersectInformationStruct InterInfo310 = S30.calculateIntersection(Ray310);
//	VectorStructR3 InterP310 = InterInfo310.getIntersectionPoint();
//
//
//	std::vector<VectorStructR3> checkVector126 = { InterP301, InterP302, InterP303, InterP304, InterP305, InterP306, InterP307, InterP308, InterP309, InterP310 };
//
//
//	std::vector<VectorStructR3> ReferenzVector126 = { { 0.0, 1.3438169363, 20.157254044 },{ 0.0, 0.66936032118, 20.080809635 },{ 0.0, 0.0, 20.055728090 },{ 0.0, -0.66936032118, 20.080809635 },{ 0.0, -1.3438169363, 20.157254044 },
//	{ 0.0, 0.66131934484, 20.080209827 },{ 0.0, -0.0055729826237, 20.055729826 },{ 0.0, -0.67752346849, 20.081426014 },{ 0.0, -1.3599535611, 20.159721367 },{ 0.0, -2.0591990429, 20.295995215 } };
//
//
//	bool isRight126 = Math::compareAllVectorElements(checkVector126, ReferenzVector126, 9);
//	checkMethodesSphericalLens.push_back(isRight126);
//
//
//	//________________________________________________________________________________________________________________________________________________________________
//	//________________________________________________________________________________________________________________________________________________________________
//	// Linse 45° gedreht, Apex Sphere (-1.0, 0.0, 20.0)
//	// Startwert (0.0, 0.0, 0.0)
//	Ray_LLT Ray311(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray312(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray313(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray314(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -0.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray315(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//
//	SphericalSurface_LLT S31(/*radius*/9.0, /*semiHeight*/2.817458, /*Apex of the sphere*/{ -1.0, 0.0, 20.0 },
//		/*Direction*/ VectorStructR3{ 0.0, -1.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.0);
//
//	IntersectInformationStruct InterInfo311 = S31.calculateIntersection(Ray311);
//	VectorStructR3 InterP311 = InterInfo311.getIntersectionPoint();
//	IntersectInformationStruct InterInfo312 = S31.calculateIntersection(Ray312);
//	VectorStructR3 InterP312 = InterInfo312.getIntersectionPoint();
//	IntersectInformationStruct InterInfo313 = S31.calculateIntersection(Ray313);
//	VectorStructR3 InterP313 = InterInfo313.getIntersectionPoint();
//	IntersectInformationStruct InterInfo314 = S31.calculateIntersection(Ray314);
//	VectorStructR3 InterP314 = InterInfo314.getIntersectionPoint();
//	IntersectInformationStruct InterInfo315 = S31.calculateIntersection(Ray315);
//	VectorStructR3 InterP315 = InterInfo315.getIntersectionPoint();
//
//	//________________________________________________________________________________________________________
//	//Linse um 45° gedreht, Startwert (0.0, 2.0, 0.0)
//	Ray_LLT Ray316(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray317(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray318(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray319(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray320(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -3.0, 15.0 }, /*wavelength*/500.0, 1.0);
//
//
//	IntersectInformationStruct InterInfo316 = S31.calculateIntersection(Ray316);
//	VectorStructR3 InterP316 = InterInfo316.getIntersectionPoint();
//	IntersectInformationStruct InterInfo317 = S31.calculateIntersection(Ray317);
//	VectorStructR3 InterP317 = InterInfo317.getIntersectionPoint();
//	IntersectInformationStruct InterInfo318 = S31.calculateIntersection(Ray318);
//	VectorStructR3 InterP318 = InterInfo318.getIntersectionPoint();
//	IntersectInformationStruct InterInfo319 = S31.calculateIntersection(Ray319);
//	VectorStructR3 InterP319 = InterInfo319.getIntersectionPoint();
//	IntersectInformationStruct InterInfo320 = S31.calculateIntersection(Ray320);
//	VectorStructR3 InterP320 = InterInfo320.getIntersectionPoint();
//
//	std::vector<VectorStructR3> checkVector127 = { InterP311, InterP312, InterP313, InterP314, InterP315, InterP316, InterP317, InterP318, InterP319, InterP320 };
//
//
//	std::vector<VectorStructR3> ReferenzVector127 = { { 0.0, 1.4698348265, 22.047522398 },{ 0.0, 0.69573625181, 20.872087554 },{ 0.0, 0.0, 20.079058486 },{ 0.0, -0.64944146832 , 19.483244050 },{ 0.0, -1.2675775589, 19.013663383 },
//	{ 0.0, 0.61531710528, 20.770243421 },{ 0.0, -0.0071796788928, 20.071796789 },{ 0.0, -0.60294972288, 19.522122922 },{ 0.0, -1.1792795683, 19.075677410 },{ 0.0, -1.7413664712, 18.706832356 } };
//
//
//	bool isRight127 = Math::compareAllVectorElements(checkVector127, ReferenzVector127, 9);
//	checkMethodesSphericalLens.push_back(isRight127);
//
//	//________________________________________________________________________________________________________________________________________________________________
//	//________________________________________________________________________________________________________________________________________________________________
//	// Linse -45° gedreht, Apex Sphere (-1.0, 0.0, 20.0)
//	// Startwert (0.0, 0.0, 0.0)
//	Ray_LLT Ray321(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray322(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray323(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray324(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -0.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray325(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//
//	SphericalSurface_LLT S32(/*radius*/9.0, /*semiHeight*/2.817458, /*Apex of the sphere*/{ -1.0, 0.0, 20.0 },
//		/*Direction*/ VectorStructR3{ 0.0, 1.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.0);
//
//	//InterP322 stimmt nicht exakt mit Zemax-Schnittpunkten überein -> Übereinstimmung Kommazahlen auf 8 heruntergesetzt
//	IntersectInformationStruct InterInfo321 = S32.calculateIntersection(Ray321);
//	VectorStructR3 InterP321 = InterInfo321.getIntersectionPoint();
//	IntersectInformationStruct InterInfo322 = S32.calculateIntersection(Ray322);
//	VectorStructR3 InterP322 = InterInfo322.getIntersectionPoint();
//	IntersectInformationStruct InterInfo323 = S32.calculateIntersection(Ray323);
//	VectorStructR3 InterP323 = InterInfo323.getIntersectionPoint();
//	IntersectInformationStruct InterInfo324 = S32.calculateIntersection(Ray324);
//	VectorStructR3 InterP324 = InterInfo324.getIntersectionPoint();
//	IntersectInformationStruct InterInfo325 = S32.calculateIntersection(Ray325);
//	VectorStructR3 InterP325 = InterInfo325.getIntersectionPoint();
//
//	//________________________________________________________________________________________________________
//	//Linse um -45° gedreht, Startwert (0.0, 2.0, 0.0)
//	Ray_LLT Ray326(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray327(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray328(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray329(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray330(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -3.0, 15.0 }, /*wavelength*/500.0, 1.0);
//
//
//	//InterP327 stimmt nicht exakt mit Zemax-Schnittpunkt überein -> Übereinstimmung Kommazahlen auf 8 heruntergesetzt
//	IntersectInformationStruct InterInfo326 = S32.calculateIntersection(Ray326);
//	VectorStructR3 InterP326 = InterInfo326.getIntersectionPoint();
//	IntersectInformationStruct InterInfo327 = S32.calculateIntersection(Ray327);
//	VectorStructR3 InterP327 = InterInfo327.getIntersectionPoint();
//	IntersectInformationStruct InterInfo328 = S32.calculateIntersection(Ray328);
//	VectorStructR3 InterP328 = InterInfo328.getIntersectionPoint();
//	IntersectInformationStruct InterInfo329 = S32.calculateIntersection(Ray329);
//	VectorStructR3 InterP329 = InterInfo329.getIntersectionPoint();
//	IntersectInformationStruct InterInfo330 = S32.calculateIntersection(Ray330);
//	VectorStructR3 InterP330 = InterInfo330.getIntersectionPoint();
//
//	std::vector<VectorStructR3> checkVector128 = { InterP321, InterP322, InterP323, InterP324, InterP325, InterP326, InterP327, InterP328, InterP329, InterP330 };
//
//
//	std::vector<VectorStructR3> ReferenzVector128 = { { 0.0, 1.2675775589, 19.013663383 },{ 0.0, 0.64944146832, 19.483244050 },{ 0.0, 0.0, 20.079058486 },{ 0.0, -0.69573625181, 20.872087554 },{ 0.0, -1.4698348265, 22.047522398 },
//	{ 0.0, 0.70412017130, 19.438197430 },{ 0.0, -0.0087979606378, 20.087979606 },{ 0.0, -0.80142946372, 21.010720978 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 } };
//
//
//	bool isRight128 = Math::compareAllVectorElements(checkVector128, ReferenzVector128, 8);
//	checkMethodesSphericalLens.push_back(isRight128);
//
//
//	//________________________________________________________________________________________________________________________________________________________________
//	//________________________________________________________________________________________________________________________________________________________________
//	// Linse 90° gedreht, Apex Sphere (-1.0, 0.0, 20.0)
//	// Startwert (0.0, 0.0, 0.0)
//	Ray_LLT Ray331(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray332(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray333(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray334(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -0.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray335(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//
//	SphericalSurface_LLT S33(/*radius*/9.0, /*semiHeight*/2.817458, /*Apex of the sphere*/{ -1.0, 0.0, 20.0 },
//		/*Direction*/ VectorStructR3{ 0.0, -1.0, 0.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.0);
//
//	IntersectInformationStruct InterInfo331 = S33.calculateIntersection(Ray331);
//	VectorStructR3 InterP331 = InterInfo331.getIntersectionPoint();
//	IntersectInformationStruct InterInfo332 = S33.calculateIntersection(Ray332);
//	VectorStructR3 InterP332 = InterInfo332.getIntersectionPoint();
//	IntersectInformationStruct InterInfo333 = S33.calculateIntersection(Ray333);
//	VectorStructR3 InterP333 = InterInfo333.getIntersectionPoint();
//	IntersectInformationStruct InterInfo334 = S33.calculateIntersection(Ray334);
//	VectorStructR3 InterP334 = InterInfo334.getIntersectionPoint();
//	IntersectInformationStruct InterInfo335 = S33.calculateIntersection(Ray335);
//	VectorStructR3 InterP335 = InterInfo335.getIntersectionPoint();
//
//	//________________________________________________________________________________________________________
//	//Linse um 90° gedreht, Startwert (0.0, 2.0, 0.0)
//	Ray_LLT Ray336(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray337(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray338(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray339(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray340(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -3.0, 15.0 }, /*wavelength*/500.0, 1.0);
//
//
//	IntersectInformationStruct InterInfo336 = S33.calculateIntersection(Ray336);
//	VectorStructR3 InterP336 = InterInfo336.getIntersectionPoint();
//	IntersectInformationStruct InterInfo337 = S33.calculateIntersection(Ray337);
//	VectorStructR3 InterP337 = InterInfo337.getIntersectionPoint();
//	IntersectInformationStruct InterInfo338 = S33.calculateIntersection(Ray338);
//	VectorStructR3 InterP338 = InterInfo338.getIntersectionPoint();
//	IntersectInformationStruct InterInfo339 = S33.calculateIntersection(Ray339);
//	VectorStructR3 InterP339 = InterInfo339.getIntersectionPoint();
//	IntersectInformationStruct InterInfo340 = S33.calculateIntersection(Ray340);
//	VectorStructR3 InterP340 = InterInfo340.getIntersectionPoint();
//
//	std::vector<VectorStructR3> checkVector129 = { InterP331, InterP332, InterP333, InterP334, InterP335, InterP336, InterP337, InterP338, InterP339, InterP340 };
//
//
//	std::vector<VectorStructR3> ReferenzVector129 = { { 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },
//	{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, -0.35883502699, 17.691262702 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 } };
//
//
//	bool isRight129 = Math::compareAllVectorElements(checkVector129, ReferenzVector129, 9);
//	checkMethodesSphericalLens.push_back(isRight129);
//
//	//________________________________________________________________________________________________________________________________________________________________
//	//________________________________________________________________________________________________________________________________________________________________
//	// Linse -90° gedreht, Apex Sphere (-1.0, 0.0, 20.0)
//	// Startwert (0.0, 0.0, 0.0)
//	Ray_LLT Ray341(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray342(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray343(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray344(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -0.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray345(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//
//	SphericalSurface_LLT S34(/*radius*/9.0, /*semiHeight*/2.817458, /*Apex of the sphere*/{ -1.0, 0.0, 20.0 },
//		/*Direction*/ VectorStructR3{ 0.0, 1.0, 0.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.0);
//
//	IntersectInformationStruct InterInfo341 = S34.calculateIntersection(Ray341);
//	VectorStructR3 InterP341 = InterInfo341.getIntersectionPoint();
//	IntersectInformationStruct InterInfo342 = S34.calculateIntersection(Ray342);
//	VectorStructR3 InterP342 = InterInfo342.getIntersectionPoint();
//	IntersectInformationStruct InterInfo343 = S34.calculateIntersection(Ray343);
//	VectorStructR3 InterP343 = InterInfo343.getIntersectionPoint();
//	IntersectInformationStruct InterInfo344 = S34.calculateIntersection(Ray344);
//	VectorStructR3 InterP344 = InterInfo344.getIntersectionPoint();
//	IntersectInformationStruct InterInfo345 = S34.calculateIntersection(Ray345);
//	VectorStructR3 InterP345 = InterInfo345.getIntersectionPoint();
//
//	//________________________________________________________________________________________________________
//	//Linse um -90° gedreht, Startwert (0.0, 2.0, 0.0)
//	Ray_LLT Ray346(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray347(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray348(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray349(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray350(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -3.0, 15.0 }, /*wavelength*/500.0, 1.0);
//
//
//	IntersectInformationStruct InterInfo346 = S34.calculateIntersection(Ray346);
//	VectorStructR3 InterP346 = InterInfo346.getIntersectionPoint();
//	IntersectInformationStruct InterInfo347 = S34.calculateIntersection(Ray347);
//	VectorStructR3 InterP347 = InterInfo347.getIntersectionPoint();
//	IntersectInformationStruct InterInfo348 = S34.calculateIntersection(Ray348);
//	VectorStructR3 InterP348 = InterInfo348.getIntersectionPoint();
//	IntersectInformationStruct InterInfo349 = S34.calculateIntersection(Ray349);
//	VectorStructR3 InterP349 = InterInfo349.getIntersectionPoint();
//	IntersectInformationStruct InterInfo350 = S34.calculateIntersection(Ray350);
//	VectorStructR3 InterP350 = InterInfo350.getIntersectionPoint();
//
//	std::vector<VectorStructR3> checkVector130 = { InterP341, InterP342, InterP343, InterP344, InterP345, InterP346, InterP347, InterP348, InterP349, InterP350 };
//
//
//	std::vector<VectorStructR3> ReferenzVector130 = { { 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },
//	{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 } };
//
//
//	bool isRight130 = Math::compareAllVectorElements(checkVector130, ReferenzVector130, 9);
//	checkMethodesSphericalLens.push_back(isRight130);
//
//	//____________________________________________________________________________________________________________________________________________________
//	//____________________________________________________________________________________________________________________________________________________
//	//____________________________________________________________________________________________________________________________________________________
//	// Linse 0° gedreht, Apex Sphere (-1.0, 1.0, 20.0)
//	// Startwert (0.0, 0.0, 0.0)
//	Ray_LLT Ray351(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray352(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray353(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray354(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -0.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray355(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//
//	SphericalSurface_LLT S35(/*radius*/9.0, /*semiHeight*/2.817458, /*Apex of the sphere*/{ -1.0, 1.0, 20.0 },
//		/*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.0);
//
//	IntersectInformationStruct InterInfo351 = S35.calculateIntersection(Ray351);
//	VectorStructR3 InterP351 = InterInfo351.getIntersectionPoint();
//	IntersectInformationStruct InterInfo352 = S35.calculateIntersection(Ray352);
//	VectorStructR3 InterP352 = InterInfo352.getIntersectionPoint();
//	IntersectInformationStruct InterInfo353 = S35.calculateIntersection(Ray353);
//	VectorStructR3 InterP353 = InterInfo353.getIntersectionPoint();
//	IntersectInformationStruct InterInfo354 = S35.calculateIntersection(Ray354);
//	VectorStructR3 InterP354 = InterInfo354.getIntersectionPoint();
//	IntersectInformationStruct InterInfo355 = S35.calculateIntersection(Ray355);
//	VectorStructR3 InterP355 = InterInfo355.getIntersectionPoint();
//
//	//________________________________________________________________________________________________________
//	//Linse um 0° gedreht, Startwert (0.0, 2.0, 0.0)
//	Ray_LLT Ray356(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray357(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray358(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray359(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray360(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -3.0, 15.0 }, /*wavelength*/500.0, 1.0);
//
//
//	//InterP357: y-Wert stimmt nicht exakt mit Zemax überein -> Übereinstimmung Kommazahlen auf 8 heruntergesetzt
//	IntersectInformationStruct InterInfo356 = S35.calculateIntersection(Ray356);
//	VectorStructR3 InterP356 = InterInfo356.getIntersectionPoint();
//	IntersectInformationStruct InterInfo357 = S35.calculateIntersection(Ray357);
//	VectorStructR3 InterP357 = InterInfo357.getIntersectionPoint();
//	IntersectInformationStruct InterInfo358 = S35.calculateIntersection(Ray358);
//	VectorStructR3 InterP358 = InterInfo358.getIntersectionPoint();
//	IntersectInformationStruct InterInfo359 = S35.calculateIntersection(Ray359);
//	VectorStructR3 InterP359 = InterInfo359.getIntersectionPoint();
//	IntersectInformationStruct InterInfo360 = S35.calculateIntersection(Ray360);
//	VectorStructR3 InterP360 = InterInfo360.getIntersectionPoint();
//
//
//	std::vector<VectorStructR3> checkVector131 = { InterP351, InterP352, InterP353, InterP354, InterP355, InterP356, InterP357, InterP358, InterP359, InterP360 };
//
//
//	std::vector<VectorStructR3> ReferenzVector131 = { { 0.0, 1.3374731264, 20.062096896 },{ 0.0, 0.66872882935, 20.061864881 },{ 0.0, 0.0, 20.111805583 },{ 0.0, -0.67379122302, 20.213736691 },{ 0.0, -1.3581458345, 20.372187518 },
//	{ 0.0, 0.66252687357, 20.062096896 },{ 0.0, -0.011308517642, 20.113085176 },{ 0.0, -0.69572581837, 20.217943638 },{ 0.0, -1.3971575097, 20.382945058 },{ 0.0, 0.0, 0.0 } };
//
//
//	bool isRight131 = Math::compareAllVectorElements(checkVector131, ReferenzVector131, 8);
//	checkMethodesSphericalLens.push_back(isRight131);
//
//
//	//________________________________________________________________________________________________________________________________________________________________
//	//________________________________________________________________________________________________________________________________________________________________
//	// Linse 45° gedreht, Apex Sphere (-1.0, 1.0, 20.0)
//	// Startwert (0.0, 0.0, 0.0)
//	Ray_LLT Ray361(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray362(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray363(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray364(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -0.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray365(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//
//	SphericalSurface_LLT S36(/*radius*/9.0, /*semiHeight*/2.817458, /*Apex of the sphere*/{ -1.0, 1.0, 20.0 },
//		/*Direction*/ VectorStructR3{ 0.0, -1.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.0);
//
//	//InterP365: Programm gibt keinen Schnittpunkt an, Strahl trifft Linse in Zemax, in Realität nicht
//	IntersectInformationStruct InterInfo361 = S36.calculateIntersection(Ray361);
//	VectorStructR3 InterP361 = InterInfo361.getIntersectionPoint();
//	IntersectInformationStruct InterInfo362 = S36.calculateIntersection(Ray362);
//	VectorStructR3 InterP362 = InterInfo362.getIntersectionPoint();
//	IntersectInformationStruct InterInfo363 = S36.calculateIntersection(Ray363);
//	VectorStructR3 InterP363 = InterInfo363.getIntersectionPoint();
//	IntersectInformationStruct InterInfo364 = S36.calculateIntersection(Ray364);
//	VectorStructR3 InterP364 = InterInfo364.getIntersectionPoint();
//	IntersectInformationStruct InterInfo365 = S36.calculateIntersection(Ray365);
//	VectorStructR3 InterP365 = InterInfo365.getIntersectionPoint();
//
//	//________________________________________________________________________________________________________
//	//Linse um 45° gedreht, Startwert (0.0, 2.0, 0.0)
//	Ray_LLT Ray366(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray367(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray368(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray369(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray370(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -3.0, 15.0 }, /*wavelength*/500.0, 1.0);
//
//
//	//InterP367: y-Wert stimmt nicht exakt mit Zemax überein -> Übereinstimmung Kommazahlen auf 8 heruntergesetzt
//	IntersectInformationStruct InterInfo366 = S36.calculateIntersection(Ray366);
//	VectorStructR3 InterP366 = InterInfo366.getIntersectionPoint();
//	IntersectInformationStruct InterInfo367 = S36.calculateIntersection(Ray367);
//	VectorStructR3 InterP367 = InterInfo367.getIntersectionPoint();
//	IntersectInformationStruct InterInfo368 = S36.calculateIntersection(Ray368);
//	VectorStructR3 InterP368 = InterInfo368.getIntersectionPoint();
//	IntersectInformationStruct InterInfo369 = S36.calculateIntersection(Ray369);
//	VectorStructR3 InterP369 = InterInfo369.getIntersectionPoint();
//	IntersectInformationStruct InterInfo370 = S36.calculateIntersection(Ray370);
//	VectorStructR3 InterP370 = InterInfo370.getIntersectionPoint();
//
//	std::vector<VectorStructR3> checkVector132 = { InterP361, InterP362, InterP363, InterP364, InterP365, InterP366, InterP367, InterP368, InterP369, InterP370 };
//
//
//	std::vector<VectorStructR3> ReferenzVector132 = { { 0.0, 1.3647475229, 20.471212843 },{ 0.0, 0.65836584658, 19.750975398 },{ 0.0, 0.0, 19.206592655 },{ 0.0, -0.62592410304, 18.777723091 },{ 0.0, 0.0, 0.0 },
//	{ 0.0, 0.68183815608, 19.772427659 },{ 0.0, 0.073753596848, 19.262464031 },{ 0.0, -0.51323693619, 18.849277021 },{ 0.0, -1.0849436945, 18.509662167 },{ 0.0, 0.0, 0.0 } };
//
//
//	bool isRight132 = Math::compareAllVectorElements(checkVector132, ReferenzVector132, 8);
//	checkMethodesSphericalLens.push_back(isRight132);
//
//	//________________________________________________________________________________________________________________________________________________________________
//	//________________________________________________________________________________________________________________________________________________________________
//	// Linse -45° gedreht, Apex Sphere (-1.0, 1.0, 20.0)
//	// Startwert (0.0, 0.0, 0.0)
//	Ray_LLT Ray371(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray372(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray373(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray374(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -0.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray375(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//
//	SphericalSurface_LLT S37(/*radius*/9.0, /*semiHeight*/2.817458, /*Apex of the sphere*/{ -1.0, 1.0, 20.0 },
//		/*Direction*/ VectorStructR3{ 0.0, 1.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.0);
//
//	IntersectInformationStruct InterInfo371 = S37.calculateIntersection(Ray371);
//	VectorStructR3 InterP371 = InterInfo371.getIntersectionPoint();
//	IntersectInformationStruct InterInfo372 = S37.calculateIntersection(Ray372);
//	VectorStructR3 InterP372 = InterInfo372.getIntersectionPoint();
//	IntersectInformationStruct InterInfo373 = S37.calculateIntersection(Ray373);
//	VectorStructR3 InterP373 = InterInfo373.getIntersectionPoint();
//	IntersectInformationStruct InterInfo374 = S37.calculateIntersection(Ray374);
//	VectorStructR3 InterP374 = InterInfo374.getIntersectionPoint();
//	IntersectInformationStruct InterInfo375 = S37.calculateIntersection(Ray375);
//	VectorStructR3 InterP375 = InterInfo375.getIntersectionPoint();
//
//	//________________________________________________________________________________________________________
//	//Linse um -45° gedreht, Startwert (0.0, 2.0, 0.0)
//	Ray_LLT Ray376(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray377(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray378(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray379(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray380(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -3.0, 15.0 }, /*wavelength*/500.0, 1.0);
//
//
//
//	IntersectInformationStruct InterInfo376 = S37.calculateIntersection(Ray356);
//	VectorStructR3 InterP376 = InterInfo376.getIntersectionPoint();
//	IntersectInformationStruct InterInfo377 = S37.calculateIntersection(Ray357);
//	VectorStructR3 InterP377 = InterInfo377.getIntersectionPoint();
//	IntersectInformationStruct InterInfo378 = S37.calculateIntersection(Ray358);
//	VectorStructR3 InterP378 = InterInfo378.getIntersectionPoint();
//	IntersectInformationStruct InterInfo379 = S37.calculateIntersection(Ray359);
//	VectorStructR3 InterP379 = InterInfo379.getIntersectionPoint();
//	IntersectInformationStruct InterInfo380 = S37.calculateIntersection(Ray350);
//	VectorStructR3 InterP380 = InterInfo380.getIntersectionPoint();
//
//
//	std::vector<VectorStructR3> checkVector133 = { InterP371, InterP372, InterP373, InterP374, InterP375, InterP376, InterP377, InterP378, InterP379, InterP380 };
//
//
//	std::vector<VectorStructR3> ReferenzVector133 = { { 0.0, 1.3181618439, 19.772427659 },{ 0.0, 0.68065881904, 20.419764571 },{ 0.0, 0.0, 21.287340310 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },
//	{ 0.0, 0.63525247711, 20.471212843 },{ 0.0, -0.15143383662, 21.514338366 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 } };
//
//
//	bool isRight133 = Math::compareAllVectorElements(checkVector133, ReferenzVector133, 9);
//	checkMethodesSphericalLens.push_back(isRight133);
//
//
//	//________________________________________________________________________________________________________________________________________________________________
//	//________________________________________________________________________________________________________________________________________________________________
//	// Linse 90° gedreht, Apex Sphere (-1.0, 1.0, 20.0)
//	// Startwert (0.0, 0.0, 0.0)
//	Ray_LLT Ray381(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray382(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray383(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray384(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -0.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray385(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//
//	SphericalSurface_LLT S38(/*radius*/9.0, /*semiHeight*/2.817458, /*Apex of the sphere*/{ -1.0, 1.0, 20.0 },
//		/*Direction*/ VectorStructR3{ 0.0, -1.0, 0.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.0);
//
//	IntersectInformationStruct InterInfo381 = S38.calculateIntersection(Ray381);
//	VectorStructR3 InterP381 = InterInfo381.getIntersectionPoint();
//	IntersectInformationStruct InterInfo382 = S38.calculateIntersection(Ray382);
//	VectorStructR3 InterP382 = InterInfo382.getIntersectionPoint();
//	IntersectInformationStruct InterInfo383 = S38.calculateIntersection(Ray383);
//	VectorStructR3 InterP383 = InterInfo383.getIntersectionPoint();
//	IntersectInformationStruct InterInfo384 = S38.calculateIntersection(Ray384);
//	VectorStructR3 InterP384 = InterInfo384.getIntersectionPoint();
//	IntersectInformationStruct InterInfo385 = S38.calculateIntersection(Ray385);
//	VectorStructR3 InterP385 = InterInfo385.getIntersectionPoint();
//
//	//________________________________________________________________________________________________________
//	//Linse um 90° gedreht, Startwert (0.0, 2.0, 0.0)
//	Ray_LLT Ray386(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray387(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray388(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray389(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray390(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -3.0, 15.0 }, /*wavelength*/500.0, 1.0);
//
//
//	IntersectInformationStruct InterInfo386 = S38.calculateIntersection(Ray386);
//	VectorStructR3 InterP386 = InterInfo386.getIntersectionPoint();
//	IntersectInformationStruct InterInfo387 = S38.calculateIntersection(Ray387);
//	VectorStructR3 InterP387 = InterInfo387.getIntersectionPoint();
//	IntersectInformationStruct InterInfo388 = S38.calculateIntersection(Ray388);
//	VectorStructR3 InterP388 = InterInfo388.getIntersectionPoint();
//	IntersectInformationStruct InterInfo389 = S38.calculateIntersection(Ray389);
//	VectorStructR3 InterP389 = InterInfo389.getIntersectionPoint();
//	IntersectInformationStruct InterInfo390 = S38.calculateIntersection(Ray390);
//	VectorStructR3 InterP390 = InterInfo390.getIntersectionPoint();
//
//	std::vector<VectorStructR3> checkVector134 = { InterP381, InterP382, InterP383, InterP384, InterP385, InterP386, InterP387, InterP388, InterP389, InterP390 };
//
//
//	std::vector<VectorStructR3> ReferenzVector134 = { { 0.0, 0.0, 0.0 },{ 0.0, 0.58276048599, 17.482814580 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },
//	{ 0.0, 0.78031472599, 18.295279110 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 } };
//
//
//	bool isRight134 = Math::compareAllVectorElements(checkVector134, ReferenzVector134, 9);
//	checkMethodesSphericalLens.push_back(isRight134);
//
//	//________________________________________________________________________________________________________________________________________________________________
//	//________________________________________________________________________________________________________________________________________________________________
//	// Linse -90° gedreht, Apex Sphere (-1.0, 1.0, 20.0)
//	// Startwert (0.0, 0.0, 0.0)
//	Ray_LLT Ray391(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray392(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray393(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray394(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -0.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray395(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//
//	SphericalSurface_LLT S39(/*radius*/9.0, /*semiHeight*/2.817458, /*Apex of the sphere*/{ -1.0, 1.0, 20.0 },
//		/*Direction*/ VectorStructR3{ 0.0, 1.0, 0.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.0);
//
//	IntersectInformationStruct InterInfo391 = S39.calculateIntersection(Ray391);
//	VectorStructR3 InterP391 = InterInfo391.getIntersectionPoint();
//	IntersectInformationStruct InterInfo392 = S39.calculateIntersection(Ray392);
//	VectorStructR3 InterP392 = InterInfo392.getIntersectionPoint();
//	IntersectInformationStruct InterInfo393 = S39.calculateIntersection(Ray393);
//	VectorStructR3 InterP393 = InterInfo393.getIntersectionPoint();
//	IntersectInformationStruct InterInfo394 = S39.calculateIntersection(Ray394);
//	VectorStructR3 InterP394 = InterInfo394.getIntersectionPoint();
//	IntersectInformationStruct InterInfo395 = S39.calculateIntersection(Ray395);
//	VectorStructR3 InterP395 = InterInfo395.getIntersectionPoint();
//
//	//________________________________________________________________________________________________________
//	//Linse um -90° gedreht, Startwert (0.0, 2.0, 0.0)
//	Ray_LLT Ray396(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray397(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray398(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray399(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray400(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -3.0, 15.0 }, /*wavelength*/500.0, 1.0);
//
//
//	IntersectInformationStruct InterInfo396 = S39.calculateIntersection(Ray396);
//	VectorStructR3 InterP396 = InterInfo396.getIntersectionPoint();
//	IntersectInformationStruct InterInfo397 = S39.calculateIntersection(Ray397);
//	VectorStructR3 InterP397 = InterInfo397.getIntersectionPoint();
//	IntersectInformationStruct InterInfo398 = S39.calculateIntersection(Ray398);
//	VectorStructR3 InterP398 = InterInfo398.getIntersectionPoint();
//	IntersectInformationStruct InterInfo399 = S39.calculateIntersection(Ray399);
//	VectorStructR3 InterP399 = InterInfo399.getIntersectionPoint();
//	IntersectInformationStruct InterInfo400 = S39.calculateIntersection(Ray400);
//	VectorStructR3 InterP400 = InterInfo400.getIntersectionPoint();
//
//	std::vector<VectorStructR3> checkVector135 = { InterP391, InterP392, InterP393, InterP394, InterP395, InterP396, InterP397, InterP398, InterP399, InterP400 };
//
//
//	std::vector<VectorStructR3> ReferenzVector135 = { { 0.0, 1.2196852740, 18.295279110 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },
//	{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 } };
//
//
//	bool isRight135 = Math::compareAllVectorElements(checkVector135, ReferenzVector135, 9);
//	checkMethodesSphericalLens.push_back(isRight135);
//
//
//
//	//____________________________________________________________________________________________________________________________________________________
//	//____________________________________________________________________________________________________________________________________________________
//	//____________________________________________________________________________________________________________________________________________________
//	// Linse 0° gedreht, Apex Sphere (-1.0, -1.0, 20.0)
//	// Startwert (0.0, 0.0, 0.0)
//	Ray_LLT Ray401(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray402(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray403(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray404(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -0.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray405(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//
//	SphericalSurface_LLT S40(/*radius*/9.0, /*semiHeight*/2.817458, /*Apex of the sphere*/{ -1.0, -1.0, 20.0 },
//		/*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.0);
//
//	IntersectInformationStruct InterInfo401 = S40.calculateIntersection(Ray401);
//	VectorStructR3 InterP401 = InterInfo401.getIntersectionPoint();
//	IntersectInformationStruct InterInfo402 = S40.calculateIntersection(Ray402);
//	VectorStructR3 InterP402 = InterInfo402.getIntersectionPoint();
//	IntersectInformationStruct InterInfo403 = S40.calculateIntersection(Ray403);
//	VectorStructR3 InterP403 = InterInfo403.getIntersectionPoint();
//	IntersectInformationStruct InterInfo404 = S40.calculateIntersection(Ray404);
//	VectorStructR3 InterP404 = InterInfo404.getIntersectionPoint();
//	IntersectInformationStruct InterInfo405 = S40.calculateIntersection(Ray405);
//	VectorStructR3 InterP405 = InterInfo405.getIntersectionPoint();
//
//	//________________________________________________________________________________________________________
//	//Linse um 0° gedreht, Startwert (0.0, 2.0, 0.0)
//	Ray_LLT Ray406(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray407(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray408(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray409(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray410(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -3.0, 15.0 }, /*wavelength*/500.0, 1.0);
//
//
//	//InterP407: y-Wert stimmt nicht exakt mit Zemax überein -> Übereinstimmung Kommazahlen auf 8 heruntergesetzt
//	IntersectInformationStruct InterInfo406 = S40.calculateIntersection(Ray406);
//	VectorStructR3 InterP406 = InterInfo406.getIntersectionPoint();
//	IntersectInformationStruct InterInfo407 = S40.calculateIntersection(Ray407);
//	VectorStructR3 InterP407 = InterInfo407.getIntersectionPoint();
//	IntersectInformationStruct InterInfo408 = S40.calculateIntersection(Ray408);
//	VectorStructR3 InterP408 = InterInfo408.getIntersectionPoint();
//	IntersectInformationStruct InterInfo409 = S40.calculateIntersection(Ray409);
//	VectorStructR3 InterP409 = InterInfo409.getIntersectionPoint();
//	IntersectInformationStruct InterInfo410 = S40.calculateIntersection(Ray410);
//	VectorStructR3 InterP410 = InterInfo410.getIntersectionPoint();
//
//	std::vector<VectorStructR3> checkVector136 = { InterP401, InterP402, InterP403, InterP404, InterP405, InterP406, InterP407, InterP408, InterP409, InterP410 };
//
//
//	std::vector<VectorStructR3> ReferenzVector136 = { { 0.0, 1.3581458345, 20.372187518 },{ 0.0, 0.67379122302, 20.213736691 },{ 0.0, 0.0, 20.111805583 },{ 0.0, -0.66872882935, 20.061864881 },{ 0.0, -1.3374731264, 20.062096896 },
//	{ 0.0, 0.65268386790, 20.209741981 },{ 0.0, -0.011056855272, 20.110568553 },{ 0.0, -0.67488517773, 20.061638833 },{ 0.0, -1.3437225076, 20.062335046 },{ 0.0, -2.0228819681, 20.114409841 } };
//
//
//	bool isRight136 = Math::compareAllVectorElements(checkVector136, ReferenzVector136, 8);
//	checkMethodesSphericalLens.push_back(isRight136);
//
//
//	//________________________________________________________________________________________________________________________________________________________________
//	//________________________________________________________________________________________________________________________________________________________________
//	// Linse 45° gedreht, Apex Sphere (-1.0, -1.0, 20.0)
//	// Startwert (0.0, 0.0, 0.0)
//	Ray_LLT Ray411(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray412(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray413(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray414(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -0.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray415(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//
//	SphericalSurface_LLT S41(/*radius*/9.0, /*semiHeight*/2.817458, /*Apex of the sphere*/{ -1.0, -1.0, 20.0 },
//		/*Direction*/ VectorStructR3{ 0.0, -1.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.0);
//
//	IntersectInformationStruct InterInfo411 = S41.calculateIntersection(Ray411);
//	VectorStructR3 InterP411 = InterInfo411.getIntersectionPoint();
//	IntersectInformationStruct InterInfo412 = S41.calculateIntersection(Ray412);
//	VectorStructR3 InterP412 = InterInfo412.getIntersectionPoint();
//	IntersectInformationStruct InterInfo413 = S41.calculateIntersection(Ray413);
//	VectorStructR3 InterP413 = InterInfo413.getIntersectionPoint();
//	IntersectInformationStruct InterInfo414 = S41.calculateIntersection(Ray414);
//	VectorStructR3 InterP414 = InterInfo414.getIntersectionPoint();
//	IntersectInformationStruct InterInfo415 = S41.calculateIntersection(Ray415);
//	VectorStructR3 InterP415 = InterInfo415.getIntersectionPoint();
//
//	//________________________________________________________________________________________________________
//	//Linse um 45° gedreht, Startwert (0.0, 2.0, 0.0)
//	Ray_LLT Ray416(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray417(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray418(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray419(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray420(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -3.0, 15.0 }, /*wavelength*/500.0, 1.0);
//
//
//	IntersectInformationStruct InterInfo416 = S41.calculateIntersection(Ray416);
//	VectorStructR3 InterP416 = InterInfo416.getIntersectionPoint();
//	IntersectInformationStruct InterInfo417 = S41.calculateIntersection(Ray417);
//	VectorStructR3 InterP417 = InterInfo417.getIntersectionPoint();
//	IntersectInformationStruct InterInfo418 = S41.calculateIntersection(Ray418);
//	VectorStructR3 InterP418 = InterInfo418.getIntersectionPoint();
//	IntersectInformationStruct InterInfo419 = S41.calculateIntersection(Ray419);
//	VectorStructR3 InterP419 = InterInfo419.getIntersectionPoint();
//	IntersectInformationStruct InterInfo420 = S41.calculateIntersection(Ray420);
//	VectorStructR3 InterP420 = InterInfo420.getIntersectionPoint();
//
//	std::vector<VectorStructR3> checkVector137 = { InterP411, InterP412, InterP413, InterP414, InterP415, InterP416, InterP417, InterP418, InterP419, InterP420 };
//
//
//	std::vector<VectorStructR3> ReferenzVector137 = { { 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 21.287340310 },{ 0.0, -0.68065881904, 20.419764571 },{ 0.0, -1.3181618439, 19.772427659 },
//	{ 0.0, 0.52356616967, 22.146507455 },{ 0.0, -0.11275491095, 21.127549109 },{ 0.0, -0.71719214830, 20.378941112 },{ 0.0, -1.2984300534, 19.790580320 },{ 0.0, -1.8623672261, 19.311836130 } };
//
//
//	bool isRight137 = Math::compareAllVectorElements(checkVector137, ReferenzVector137, 9);
//	checkMethodesSphericalLens.push_back(isRight137);
//
//	//________________________________________________________________________________________________________________________________________________________________
//	//________________________________________________________________________________________________________________________________________________________________
//	// Linse -45° gedreht, Apex Sphere (-1.0, -1.0, 20.0)
//	// Startwert (0.0, 0.0, 0.0)
//	Ray_LLT Ray421(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray422(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray423(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray424(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -0.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray425(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//
//	SphericalSurface_LLT S42(/*radius*/9.0, /*semiHeight*/2.817458, /*Apex of the sphere*/{ -1.0, -1.0, 20.0 },
//		/*Direction*/ VectorStructR3{ 0.0, 1.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
//
//	//InterP421: Programm gibt keinen Schnittpunkt an, Strahl trifft Linse in Zemax, in Realität nicht
//	IntersectInformationStruct InterInfo421 = S42.calculateIntersection(Ray421);
//	VectorStructR3 InterP421 = InterInfo421.getIntersectionPoint();
//	IntersectInformationStruct InterInfo422 = S42.calculateIntersection(Ray422);
//	VectorStructR3 InterP422 = InterInfo422.getIntersectionPoint();
//	IntersectInformationStruct InterInfo423 = S42.calculateIntersection(Ray423);
//	VectorStructR3 InterP423 = InterInfo423.getIntersectionPoint();
//	IntersectInformationStruct InterInfo424 = S42.calculateIntersection(Ray424);
//	VectorStructR3 InterP424 = InterInfo424.getIntersectionPoint();
//	IntersectInformationStruct InterInfo425 = S42.calculateIntersection(Ray425);
//	VectorStructR3 InterP425 = InterInfo425.getIntersectionPoint();
//
//
//	//________________________________________________________________________________________________________
//	//Linse um -45° gedreht, Startwert (0.0, 2.0, 0.0)
//	Ray_LLT Ray426(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray427(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray428(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray429(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray430(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -3.0, 15.0 }, /*wavelength*/500.0, 1.0);
//
//
//	//InterP427: y-Wert stimmt nicht exakt mit Zemax überein -> Übereinstimmung Kommazahlenauf 8 heruntergesetzt
//	IntersectInformationStruct InterInfo426 = S42.calculateIntersection(Ray426);
//	VectorStructR3 InterP426 = InterInfo426.getIntersectionPoint();
//	IntersectInformationStruct InterInfo427 = S42.calculateIntersection(Ray427);
//	VectorStructR3 InterP427 = InterInfo427.getIntersectionPoint();
//	IntersectInformationStruct InterInfo428 = S42.calculateIntersection(Ray428);
//	VectorStructR3 InterP428 = InterInfo428.getIntersectionPoint();
//	IntersectInformationStruct InterInfo429 = S42.calculateIntersection(Ray429);
//	VectorStructR3 InterP429 = InterInfo429.getIntersectionPoint();
//	IntersectInformationStruct InterInfo430 = S42.calculateIntersection(Ray430);
//	VectorStructR3 InterP430 = InterInfo430.getIntersectionPoint();
//
//	std::vector<VectorStructR3> checkVector138 = { InterP421, InterP422, InterP423, InterP424, InterP425, InterP426, InterP427, InterP428, InterP429, InterP430 };
//
//
//	std::vector<VectorStructR3> ReferenzVector138 = { { 0.0, 0.0, 0.0 },{ 0.0, 0.62592410304, 18.777723091 },{ 0.0, 0.0, 19.206592655 },{ 0.0, -0.65836584658, 19.750975398 },{ 0.0, -1.3647475229, 20.471212843 },
//	{ 0.0, 0.75335967435, 18.699604885 },{ 0.0, 0.085682685652, 19.143173143 },{ 0.0, -0.63003850027, 19.725288752 },{ 0.0, -1.4230827549, 20.538496530 },{ 0.0, -2.3764396609, 21.882198304 } };
//
//
//	bool isRight138 = Math::compareAllVectorElements(checkVector138, ReferenzVector138, 7);
//	checkMethodesSphericalLens.push_back(isRight138);
//
//
//	//________________________________________________________________________________________________________________________________________________________________
//	//________________________________________________________________________________________________________________________________________________________________
//	// Linse 90° gedreht, Apex Sphere (-1.0, -1.0, 20.0)
//	// Startwert (0.0, 0.0, 0.0)
//	Ray_LLT Ray431(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray432(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray433(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray434(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -0.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray435(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//
//	SphericalSurface_LLT S43(/*radius*/9.0, /*semiHeight*/2.817458, /*Apex of the sphere*/{ -1.0, -1.0, 20.0 },
//		/*Direction*/ VectorStructR3{ 0.0, -1.0, 0.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.0);
//
//	IntersectInformationStruct InterInfo431 = S43.calculateIntersection(Ray431);
//	VectorStructR3 InterP431 = InterInfo431.getIntersectionPoint();
//	IntersectInformationStruct InterInfo432 = S43.calculateIntersection(Ray432);
//	VectorStructR3 InterP432 = InterInfo432.getIntersectionPoint();
//	IntersectInformationStruct InterInfo433 = S43.calculateIntersection(Ray433);
//	VectorStructR3 InterP433 = InterInfo433.getIntersectionPoint();
//	IntersectInformationStruct InterInfo434 = S43.calculateIntersection(Ray434);
//	VectorStructR3 InterP434 = InterInfo434.getIntersectionPoint();
//	IntersectInformationStruct InterInfo435 = S43.calculateIntersection(Ray435);
//	VectorStructR3 InterP435 = InterInfo435.getIntersectionPoint();
//
//	//________________________________________________________________________________________________________
//	//Linse um 90° gedreht, Startwert (0.0, 2.0, 0.0)
//	Ray_LLT Ray436(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray437(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray438(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray439(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray440(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -3.0, 15.0 }, /*wavelength*/500.0, 1.0);
//
//
//	//InterP440: Programm gibt keinen Schnittpunkt an, Strahl trifft Linse in Zemax, in Realität nicht
//	IntersectInformationStruct InterInfo436 = S43.calculateIntersection(Ray436);
//	VectorStructR3 InterP436 = InterInfo436.getIntersectionPoint();
//	IntersectInformationStruct InterInfo437 = S43.calculateIntersection(Ray437);
//	VectorStructR3 InterP437 = InterInfo437.getIntersectionPoint();
//	IntersectInformationStruct InterInfo438 = S43.calculateIntersection(Ray438);
//	VectorStructR3 InterP438 = InterInfo438.getIntersectionPoint();
//	IntersectInformationStruct InterInfo439 = S43.calculateIntersection(Ray439);
//	VectorStructR3 InterP439 = InterInfo439.getIntersectionPoint();
//	IntersectInformationStruct InterInfo440 = S43.calculateIntersection(Ray440);
//	VectorStructR3 InterP440 = InterInfo440.getIntersectionPoint();
//
//
//	std::vector<VectorStructR3> checkVector139 = { InterP431, InterP432, InterP433, InterP434, InterP435, InterP436, InterP437, InterP438, InterP439, InterP400 };
//
//
//	std::vector<VectorStructR3> ReferenzVector139 = { { 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, -1.2196852740, 18.295279110 },
//	{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, -1.1351351351, 18.810810811 },{ 0.0, 0.0, 0.0 } };
//
//
//	bool isRight139 = Math::compareAllVectorElements(checkVector139, ReferenzVector139, 9);
//	checkMethodesSphericalLens.push_back(isRight139);
//
//	//________________________________________________________________________________________________________________________________________________________________
//	//________________________________________________________________________________________________________________________________________________________________
//	// Linse -90° gedreht, Apex Sphere (-1.0, -1.0, 20.0)
//	// Startwert (0.0, 0.0, 0.0)
//	Ray_LLT Ray441(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray442(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray443(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray444(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -0.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray445(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//
//	SphericalSurface_LLT S44(/*radius*/9.0, /*semiHeight*/2.817458, /*Apex of the sphere*/{ -1.0, -1.0, 20.0 },
//		/*Direction*/ VectorStructR3{ 0.0, 1.0, 0.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.0);
//
//	IntersectInformationStruct InterInfo441 = S44.calculateIntersection(Ray441);
//	VectorStructR3 InterP441 = InterInfo441.getIntersectionPoint();
//	IntersectInformationStruct InterInfo442 = S44.calculateIntersection(Ray442);
//	VectorStructR3 InterP442 = InterInfo442.getIntersectionPoint();
//	IntersectInformationStruct InterInfo443 = S44.calculateIntersection(Ray443);
//	VectorStructR3 InterP443 = InterInfo443.getIntersectionPoint();
//	IntersectInformationStruct InterInfo444 = S44.calculateIntersection(Ray444);
//	VectorStructR3 InterP444 = InterInfo444.getIntersectionPoint();
//	IntersectInformationStruct InterInfo445 = S44.calculateIntersection(Ray445);
//	VectorStructR3 InterP445 = InterInfo445.getIntersectionPoint();
//
//	//________________________________________________________________________________________________________
//	//Linse um -90° gedreht, Startwert (0.0, 2.0, 0.0)
//	Ray_LLT Ray446(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray447(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray448(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray449(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray450(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -3.0, 15.0 }, /*wavelength*/500.0, 1.0);
//
//
//	//InterP448 trifft Linse von oben, Zemax gibt keinen Schnittpunkt an -> Programm-Schnittpunkt als Referenz eingesetzt
//	IntersectInformationStruct InterInfo446 = S44.calculateIntersection(Ray446);
//	VectorStructR3 InterP446 = InterInfo446.getIntersectionPoint();
//	IntersectInformationStruct InterInfo447 = S44.calculateIntersection(Ray447);
//	VectorStructR3 InterP447 = InterInfo447.getIntersectionPoint();
//	IntersectInformationStruct InterInfo448 = S44.calculateIntersection(Ray448);
//	VectorStructR3 InterP448 = InterInfo448.getIntersectionPoint();
//	IntersectInformationStruct InterInfo449 = S44.calculateIntersection(Ray449);
//	VectorStructR3 InterP449 = InterInfo449.getIntersectionPoint();
//	IntersectInformationStruct InterInfo450 = S44.calculateIntersection(Ray450);
//	VectorStructR3 InterP450 = InterInfo450.getIntersectionPoint();
//
//	std::vector<VectorStructR3> checkVector140 = { InterP441, InterP442, InterP443, InterP444, InterP445, InterP446, InterP447, InterP448, InterP449, InterP450 };
//
//
//	std::vector<VectorStructR3> ReferenzVector140 = { { 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, -0.58276048599, 17.482814580 },{ 0.0, 0.0, 0.0 },
//	{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, -0.84439202936972979, 21.332940220272974 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 } };
//
//
//	bool isRight140 = Math::compareAllVectorElements(checkVector140, ReferenzVector140, 8);
//	checkMethodesSphericalLens.push_back(isRight140);
//
//	
//	//________________________________________________________________________________________________________________________________________________________________
//	//________________________________________________________________________________________________________________________________________________________________
//	// Linse 0° gedreht, Apex Sphere (0.0, 0.0, 20.0), Radius -9mm
//	// Startwert (0.0, 0.0, 0.0)
//	Ray_LLT Ray451(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray452(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray453(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray454(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -0.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray455(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//
//	SphericalSurface_LLT S45(/*radius*/9.0, /*semiHeight*/2.817458, /*Apex of the sphere*/{ 0.0, 0.0, 20.0 },
//		/*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.0);
//
//	IntersectInformationStruct InterInfo451 = S45.calculateIntersection(Ray451);
//	VectorStructR3 InterP451 = InterInfo451.getIntersectionPoint();
//	IntersectInformationStruct InterInfo452 = S45.calculateIntersection(Ray452);
//	VectorStructR3 InterP452 = InterInfo452.getIntersectionPoint();
//	IntersectInformationStruct InterInfo453 = S45.calculateIntersection(Ray453);
//	VectorStructR3 InterP453 = InterInfo453.getIntersectionPoint();
//	IntersectInformationStruct InterInfo454 = S45.calculateIntersection(Ray454);
//	VectorStructR3 InterP454 = InterInfo454.getIntersectionPoint();
//	IntersectInformationStruct InterInfo455 = S45.calculateIntersection(Ray455);
//	VectorStructR3 InterP455 = InterInfo455.getIntersectionPoint();
//
//	//________________________________________________________________________________________________________
//	//Linse um 0° gedreht, Startwert (0.0, 2.0, 0.0)
//	Ray_LLT Ray456(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray457(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray458(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray459(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray460(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -3.0, 15.0 }, /*wavelength*/500.0, 1.0);
//
//
//	IntersectInformationStruct InterInfo456 = S45.calculateIntersection(Ray456);
//	VectorStructR3 InterP456 = InterInfo456.getIntersectionPoint();
//	IntersectInformationStruct InterInfo457 = S45.calculateIntersection(Ray457);
//	VectorStructR3 InterP457 = InterInfo457.getIntersectionPoint();
//	IntersectInformationStruct InterInfo458 = S45.calculateIntersection(Ray458);
//	VectorStructR3 InterP458 = InterInfo458.getIntersectionPoint();
//	IntersectInformationStruct InterInfo459 = S45.calculateIntersection(Ray459);
//	VectorStructR3 InterP459 = InterInfo459.getIntersectionPoint();
//	IntersectInformationStruct InterInfo460 = S45.calculateIntersection(Ray460);
//	VectorStructR3 InterP460 = InterInfo460.getIntersectionPoint();
//
//	std::vector<VectorStructR3> checkVector141 = { InterP451, InterP452, InterP453, InterP454, InterP455, InterP456, InterP457, InterP458, InterP459, InterP460 };
//
//
//	std::vector<VectorStructR3> ReferenzVector141 = { { 0.0, 1.3267777455, 19.901666182 },{ 0.0,  0.66584452359, 19.975335708 },{ 0.0, 0.0, 20.0 },{ 0.0, -0.6658445235901, 19.975335708 },{ 0.0, -1.3267777455, 19.901666182 },
//	{ 0.0, 0.66832323479, 19.975151478 },{ 0.0, -3.3331115645E-012, 20.0 },{ 0.0, -0.66340220794, 19.975516560 },{ 0.0, -1.3171818577, 19.903091146 },{ 0.0, -1.9569338072, 19.784669036 } };
//
//
//	bool isRight141 = Math::compareAllVectorElements(checkVector141, ReferenzVector141, 7);
//	checkMethodesSphericalLens.push_back(isRight141);
//
//
//	//________________________________________________________________________________________________________________________________________________________________
//	//________________________________________________________________________________________________________________________________________________________________
//	// Linse 45° gedreht, Apex Sphere (0.0, 0.0, 20.0), Radius -9mm
//	// Startwert (0.0, 0.0, 0.0)
//	Ray_LLT Ray461(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray462(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray463(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray464(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -0.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray465(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//
//	SphericalSurface_LLT S46(/*radius*/9.0, /*semiHeight*/2.817458, /*Apex of the sphere*/{ 0.0, 0.0, 20.0 },
//		/*Direction*/ VectorStructR3{ 0.0, 1.0, -1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.0);
//
//	IntersectInformationStruct InterInfo461 = S46.calculateIntersection(Ray461);
//	VectorStructR3 InterP461 = InterInfo461.getIntersectionPoint();
//	IntersectInformationStruct InterInfo462 = S46.calculateIntersection(Ray462);
//	VectorStructR3 InterP462 = InterInfo462.getIntersectionPoint();
//	IntersectInformationStruct InterInfo463 = S46.calculateIntersection(Ray463);
//	VectorStructR3 InterP463 = InterInfo463.getIntersectionPoint();
//	IntersectInformationStruct InterInfo464 = S46.calculateIntersection(Ray464);
//	VectorStructR3 InterP464 = InterInfo464.getIntersectionPoint();
//	IntersectInformationStruct InterInfo465 = S46.calculateIntersection(Ray465);
//	VectorStructR3 InterP465 = InterInfo465.getIntersectionPoint();
//
//	//________________________________________________________________________________________________________
//	//Linse um 45° gedreht, Startwert (0.0, 2.0, 0.0)
//	Ray_LLT Ray466(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray467(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray468(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray469(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray470(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -3.0, 15.0 }, /*wavelength*/500.0, 1.0);
//
//
//	IntersectInformationStruct InterInfo466 = S46.calculateIntersection(Ray466);
//	VectorStructR3 InterP466 = InterInfo466.getIntersectionPoint();
//	IntersectInformationStruct InterInfo467 = S46.calculateIntersection(Ray467);
//	VectorStructR3 InterP467 = InterInfo467.getIntersectionPoint();
//	IntersectInformationStruct InterInfo468 = S46.calculateIntersection(Ray468);
//	VectorStructR3 InterP468 = InterInfo468.getIntersectionPoint();
//	IntersectInformationStruct InterInfo469 = S46.calculateIntersection(Ray469);
//	VectorStructR3 InterP469 = InterInfo469.getIntersectionPoint();
//	IntersectInformationStruct InterInfo470 = S46.calculateIntersection(Ray470);
//	VectorStructR3 InterP470 = InterInfo470.getIntersectionPoint();
//
//	std::vector<VectorStructR3> checkVector142 = { InterP461, InterP462, InterP463, InterP464, InterP465, InterP466, InterP467, InterP468, InterP469, InterP470 };
//
//
//	std::vector<VectorStructR3> ReferenzVector142 = { { 0.0, 1.4099937809, 21.149906714 },{ 0.0, 0.68733379032, 20.620013710 },{ 0.0, 0.0, 20.0 },{ 0.0, -0.64281653713, 19.284496114 },{ 0.0, -1.2309856444, 18.464784666 },
//	{ 0.0, 0.62854556894, 20.571816466 },{ 0.0, -3.0301014223E-012, 20.0 },{ 0.0, -0.58132487531, 19.359936565 },{ 0.0, -1.1086662705, 18.651997623 },{ 0.0, -1.5750704853, 17.875352427 } };
//
//
//	bool isRight142 = Math::compareAllVectorElements(checkVector142, ReferenzVector142, 7);
//	checkMethodesSphericalLens.push_back(isRight142);
//
//	//________________________________________________________________________________________________________________________________________________________________
//	//________________________________________________________________________________________________________________________________________________________________
//	// Linse -45° gedreht, Apex Sphere (0.0, 0.0, 20.0), Radius -9mm
//	// Startwert (0.0, 0.0, 0.0)
//	Ray_LLT Ray471(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray472(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray473(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray474(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -0.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray475(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//
//	SphericalSurface_LLT S47(/*radius*/9.0, /*semiHeight*/2.817458, /*Apex of the sphere*/{ 0.0, 0.0, 20.0 },
//		/*Direction*/ VectorStructR3{ 0.0, -1.0,-1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.0);
//
//	IntersectInformationStruct InterInfo471 = S47.calculateIntersection(Ray471);
//	VectorStructR3 InterP471 = InterInfo471.getIntersectionPoint();
//	IntersectInformationStruct InterInfo472 = S47.calculateIntersection(Ray472);
//	VectorStructR3 InterP472 = InterInfo472.getIntersectionPoint();
//	IntersectInformationStruct InterInfo473 = S47.calculateIntersection(Ray473);
//	VectorStructR3 InterP473 = InterInfo473.getIntersectionPoint();
//	IntersectInformationStruct InterInfo474 = S47.calculateIntersection(Ray474);
//	VectorStructR3 InterP474 = InterInfo474.getIntersectionPoint();
//	IntersectInformationStruct InterInfo475 = S47.calculateIntersection(Ray475);
//	VectorStructR3 InterP475 = InterInfo475.getIntersectionPoint();
//
//	//________________________________________________________________________________________________________
//	//Linse um -45° gedreht, Startwert (0.0, 2.0, 0.0)
//	Ray_LLT Ray476(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray477(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray478(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray479(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray480(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -3.0, 15.0 }, /*wavelength*/500.0, 1.0);
//
//	//SphericalSurface_LLT S95(/*radius*/-9.0, /*semiHeight*/2.817458, /*Apex of the sphere*/{ 0.0, 0.0, 20.0 },
//	//	/*Direction*/ VectorStructR3{ 0.0, 1.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
//
//
//	IntersectInformationStruct InterInfo476 = S47.calculateIntersection(Ray476);
//	VectorStructR3 InterP476 = InterInfo476.getIntersectionPoint();
//	IntersectInformationStruct InterInfo477 = S47.calculateIntersection(Ray477);
//	VectorStructR3 InterP477 = InterInfo477.getIntersectionPoint();
//	IntersectInformationStruct InterInfo478 = S47.calculateIntersection(Ray478);
//	VectorStructR3 InterP478 = InterInfo478.getIntersectionPoint();
//	IntersectInformationStruct InterInfo479 = S47.calculateIntersection(Ray479);
//	VectorStructR3 InterP479 = InterInfo479.getIntersectionPoint();
//	IntersectInformationStruct InterInfo480 = S47.calculateIntersection(Ray480);
//	VectorStructR3 InterP480 = InterInfo480.getIntersectionPoint();
//
//	std::vector<VectorStructR3> checkVector143 = { InterP471, InterP472, InterP473, InterP474, InterP475, InterP476, InterP477, InterP478, InterP479, InterP480 };
//
//
//	std::vector<VectorStructR3> ReferenzVector143 = { { 0.0, 1.2309856444, 18.464784666 },{ 0.0, 0.64281653713, 19.284496114 },{ 0.0, 0.0, 20.0 },{ 0.0, -0.68733379032, 20.620013710 },{ 0.0, -1.4099937809, 21.149906714 },
//	{ 0.0, 0.72091886227, 19.186217066 },{ 0.0, -3.7034572939E-012, 20.0 },{ 0.0, -0.75678616150, 20.675896211 },{ 0.0, -1.5388864007, 21.233318404 },{ 0.0, 0.0, 0.0 } };
//
//
//	bool isRight143 = Math::compareAllVectorElements(checkVector143, ReferenzVector143, 9);
//	checkMethodesSphericalLens.push_back(isRight143);
//
//
//	//________________________________________________________________________________________________________________________________________________________________
//	//________________________________________________________________________________________________________________________________________________________________
//	// Linse 90° gedreht, Apex Sphere (0.0, 0.0, 20.0), Radius -9mm
//	// Startwert (0.0, 0.0, 0.0)
//	Ray_LLT Ray481(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray482(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray483(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray484(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -0.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray485(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//
//	SphericalSurface_LLT S48(/*radius*/9.0, /*semiHeight*/2.817458, /*Apex of the sphere*/{ 0.0, 0.0, 20.0 },
//		/*Direction*/ VectorStructR3{ 0.0, 1.0, 0.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.0);
//
//	IntersectInformationStruct InterInfo481 = S48.calculateIntersection(Ray481);
//	VectorStructR3 InterP481 = InterInfo481.getIntersectionPoint();
//	IntersectInformationStruct InterInfo482 = S48.calculateIntersection(Ray482);
//	VectorStructR3 InterP482 = InterInfo482.getIntersectionPoint();
//	IntersectInformationStruct InterInfo483 = S48.calculateIntersection(Ray483);
//	VectorStructR3 InterP483 = InterInfo483.getIntersectionPoint();
//	IntersectInformationStruct InterInfo484 = S48.calculateIntersection(Ray484);
//	VectorStructR3 InterP484 = InterInfo484.getIntersectionPoint();
//	IntersectInformationStruct InterInfo485 = S48.calculateIntersection(Ray485);
//	VectorStructR3 InterP485 = InterInfo485.getIntersectionPoint();
//
//	//________________________________________________________________________________________________________
//	//Linse um 90° gedreht, Startwert (0.0, 2.0, 0.0)
//	Ray_LLT Ray486(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray487(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray488(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray489(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray490(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -3.0, 15.0 }, /*wavelength*/500.0, 1.0);
//
//
//	//InterP487 stimmt nicht mit Zemax überein -> Programm berechnet ersten Schnittpunkt mit Linse, als Referenz eingesetzt
//	IntersectInformationStruct InterInfo486 = S48.calculateIntersection(Ray486);
//	VectorStructR3 InterP486 = InterInfo486.getIntersectionPoint();
//	IntersectInformationStruct InterInfo487 = S48.calculateIntersection(Ray487);
//	VectorStructR3 InterP487 = InterInfo487.getIntersectionPoint();
//	IntersectInformationStruct InterInfo488 = S48.calculateIntersection(Ray488);
//	VectorStructR3 InterP488 = InterInfo488.getIntersectionPoint();
//	IntersectInformationStruct InterInfo489 = S48.calculateIntersection(Ray489);
//	VectorStructR3 InterP489 = InterInfo489.getIntersectionPoint();
//	IntersectInformationStruct InterInfo490 = S48.calculateIntersection(Ray490);
//	VectorStructR3 InterP490 = InterInfo490.getIntersectionPoint();
//
//
//	std::vector<VectorStructR3> checkVector144 = { InterP481, InterP482, InterP483, InterP484, InterP485, InterP486, InterP487, InterP488, InterP489, InterP490 };
//
//
//	std::vector<VectorStructR3> ReferenzVector144 = { { 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 2.6384288908E-030, 20.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },
//	{ 0.0, 0.0, 0.0 },{ 0.0, 0.17821782178218148, 18.217821782178188 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 } };
//
//
//	bool isRight144 = Math::compareAllVectorElements(checkVector144, ReferenzVector144, 9);
//	checkMethodesSphericalLens.push_back(isRight144);
//
//	//________________________________________________________________________________________________________________________________________________________________
//	//________________________________________________________________________________________________________________________________________________________________
//	// Linse -90° gedreht, Apex Sphere (0.0, 0.0, 20.0), Radius -9mm
//	// Startwert (0.0, 0.0, 0.0)
//	Ray_LLT Ray491(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray492(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray493(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray494(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -0.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray495(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//
//	SphericalSurface_LLT S49(/*radius*/9.0, /*semiHeight*/2.817458, /*Apex of the sphere*/{ 0.0, 0.0, 20.0 },
//		/*Direction*/ VectorStructR3{ 0.0, -1.0, 0.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
//
//	IntersectInformationStruct InterInfo491 = S49.calculateIntersection(Ray491);
//	VectorStructR3 InterP491 = InterInfo491.getIntersectionPoint();
//	IntersectInformationStruct InterInfo492 = S49.calculateIntersection(Ray492);
//	VectorStructR3 InterP492 = InterInfo492.getIntersectionPoint();
//	IntersectInformationStruct InterInfo493 = S49.calculateIntersection(Ray493);
//	VectorStructR3 InterP493 = InterInfo493.getIntersectionPoint();
//	IntersectInformationStruct InterInfo494 = S49.calculateIntersection(Ray494);
//	VectorStructR3 InterP494 = InterInfo494.getIntersectionPoint();
//	IntersectInformationStruct InterInfo495 = S49.calculateIntersection(Ray495);
//	VectorStructR3 InterP495 = InterInfo495.getIntersectionPoint();
//
//	//________________________________________________________________________________________________________
//	//Linse um -90° gedreht, Startwert (0.0, 2.0, 0.0)
//	Ray_LLT Ray496(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray497(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray498(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray499(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray500(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -3.0, 15.0 }, /*wavelength*/500.0, 1.0);
//
//
//	//InterP498 stimmt nicht mit Zemax überein -> Programm berechnet ersten Schnittpunkt mit Linse, als Referenz eingesetzt
//	IntersectInformationStruct InterInfo496 = S49.calculateIntersection(Ray496);
//	VectorStructR3 InterP496 = InterInfo496.getIntersectionPoint();
//	IntersectInformationStruct InterInfo497 = S49.calculateIntersection(Ray497);
//	VectorStructR3 InterP497 = InterInfo497.getIntersectionPoint();
//	IntersectInformationStruct InterInfo498 = S49.calculateIntersection(Ray498);
//	VectorStructR3 InterP498 = InterInfo498.getIntersectionPoint();
//	IntersectInformationStruct InterInfo499 = S49.calculateIntersection(Ray499);
//	VectorStructR3 InterP499 = InterInfo499.getIntersectionPoint();
//	IntersectInformationStruct InterInfo500 = S49.calculateIntersection(Ray500);
//	VectorStructR3 InterP500 = InterInfo500.getIntersectionPoint();
//
//	std::vector<VectorStructR3> checkVector145 = { InterP491, InterP492, InterP493, InterP494, InterP495, InterP496, InterP497, InterP498, InterP499, InterP500 };
//
//
//	std::vector<VectorStructR3> ReferenzVector145 = { { 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, -2.6384288908E-030, 20.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },
//	{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 20.0 },{ 0.0, -0.33996486167351003, 17.549736462551326 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 } };
//
//
//	bool isRight145 = Math::compareAllVectorElements(checkVector145, ReferenzVector145, 9);
//	checkMethodesSphericalLens.push_back(isRight145);
//
//
//	//________________________________________________________________________________________________________________________________________________________________
//	//_______________________________________________________________________________________________________________________________________________________________
//	// Linse 0° gedreht, Apex Sphere (0.0, 1.0, 20.0), Radius -9mm
//	// Startwert (0.0, 0.0, 0.0)
//	Ray_LLT Ray501(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray502(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray503(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray504(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -0.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray505(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//
//	SphericalSurface_LLT S50(/*radius*/9.0, /*semiHeight*/2.817458, /*Apex of the sphere*/{ 0.0, 1.0, 20.0 },
//		/*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.0);
//
//	IntersectInformationStruct InterInfo501 = S50.calculateIntersection(Ray501);
//	VectorStructR3 InterP501 = InterInfo501.getIntersectionPoint();
//	IntersectInformationStruct InterInfo502 = S50.calculateIntersection(Ray502);
//	VectorStructR3 InterP502 = InterInfo502.getIntersectionPoint();
//	IntersectInformationStruct InterInfo503 = S50.calculateIntersection(Ray503);
//	VectorStructR3 InterP503 = InterInfo503.getIntersectionPoint();
//	IntersectInformationStruct InterInfo504 = S50.calculateIntersection(Ray504);
//	VectorStructR3 InterP504 = InterInfo504.getIntersectionPoint();
//	IntersectInformationStruct InterInfo505 = S50.calculateIntersection(Ray505);
//	VectorStructR3 InterP505 = InterInfo505.getIntersectionPoint();
//
//	//________________________________________________________________________________________________________
//	//Linse um 0° gedreht, Startwert (0.0, 2.0, 0.0)
//	Ray_LLT Ray506(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray507(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray508(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray509(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray510(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -3.0, 15.0 }, /*wavelength*/500.0, 1.0);
//
//
//	IntersectInformationStruct InterInfo506 = S50.calculateIntersection(Ray506);
//	VectorStructR3 InterP506 = InterInfo506.getIntersectionPoint();
//	IntersectInformationStruct InterInfo507 = S50.calculateIntersection(Ray507);
//	VectorStructR3 InterP507 = InterInfo507.getIntersectionPoint();
//	IntersectInformationStruct InterInfo508 = S50.calculateIntersection(Ray508);
//	VectorStructR3 InterP508 = InterInfo508.getIntersectionPoint();
//	IntersectInformationStruct InterInfo509 = S50.calculateIntersection(Ray509);
//	VectorStructR3 InterP509 = InterInfo509.getIntersectionPoint();
//	IntersectInformationStruct InterInfo510 = S50.calculateIntersection(Ray510);
//	VectorStructR3 InterP510 = InterInfo510.getIntersectionPoint();
//
//	std::vector<VectorStructR3> checkVector146 = { InterP501, InterP502, InterP503, InterP504, InterP505, InterP506, InterP507, InterP508, InterP509, InterP510 };
//
//
//	std::vector<VectorStructR3> ReferenzVector146 = { { 0.0, 1.3329226835, 19.993840252 },{ 0.0, 0.66646058005, 19.993817402 },{ 0.0, 0.0, 19.944271910 },{ 0.0, -0.66151009817, 19.845302945 },{ 0.0, -1.3131770364, 19.697655546 },
//	{ 0.0, 0.66707731650, 19.993840252 },{ 0.0, 0.0055113620090, 19.944886380 },{ 0.0, -0.64641663832, 19.848124787 },{ 0.0, -1.2842176400, 19.705305840 },{ 0.0, 0.0, 0.0 } };
//
//
//	bool isRight146 = Math::compareAllVectorElements(checkVector146, ReferenzVector146, 7);
//	checkMethodesSphericalLens.push_back(isRight146);
//
//
//	//________________________________________________________________________________________________________________________________________________________________
//	//________________________________________________________________________________________________________________________________________________________________
//	// Linse 45° gedreht, Apex Sphere (0.0, 1.0, 20.0), Radius -9mm
//	// Startwert (0.0, 0.0, 0.0)
//	Ray_LLT Ray511(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray512(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray513(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray514(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -0.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray515(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//
//	SphericalSurface_LLT S51(/*radius*/9.0, /*semiHeight*/2.817458, /*Apex of the sphere*/{ 0.0, 1.0, 20.0 },
//		/*Direction*/ VectorStructR3{ 0.0, 1.0, -1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.0);
//
//	IntersectInformationStruct InterInfo511 = S51.calculateIntersection(Ray511);
//	VectorStructR3 InterP511 = InterInfo511.getIntersectionPoint();
//	IntersectInformationStruct InterInfo512 = S51.calculateIntersection(Ray512);
//	VectorStructR3 InterP512 = InterInfo512.getIntersectionPoint();
//	IntersectInformationStruct InterInfo513 = S51.calculateIntersection(Ray513);
//	VectorStructR3 InterP513 = InterInfo513.getIntersectionPoint();
//	IntersectInformationStruct InterInfo514 = S51.calculateIntersection(Ray514);
//	VectorStructR3 InterP514 = InterInfo514.getIntersectionPoint();
//	IntersectInformationStruct InterInfo515 = S51.calculateIntersection(Ray515);
//	VectorStructR3 InterP515 = InterInfo515.getIntersectionPoint();
//
//	//________________________________________________________________________________________________________
//	//Linse um 45° gedreht, Startwert (0.0, 2.0, 0.0)
//	Ray_LLT Ray516(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray517(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray518(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray519(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray520(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -3.0, 15.0 }, /*wavelength*/500.0, 1.0);
//
//
//	IntersectInformationStruct InterInfo516 = S51.calculateIntersection(Ray516);
//	VectorStructR3 InterP516 = InterInfo516.getIntersectionPoint();
//	IntersectInformationStruct InterInfo517 = S51.calculateIntersection(Ray517);
//	VectorStructR3 InterP517 = InterInfo517.getIntersectionPoint();
//	IntersectInformationStruct InterInfo518 = S51.calculateIntersection(Ray518);
//	VectorStructR3 InterP518 = InterInfo518.getIntersectionPoint();
//	IntersectInformationStruct InterInfo519 = S51.calculateIntersection(Ray519);
//	VectorStructR3 InterP519 = InterInfo519.getIntersectionPoint();
//	IntersectInformationStruct InterInfo520 = S51.calculateIntersection(Ray520);
//	VectorStructR3 InterP520 = InterInfo520.getIntersectionPoint();
//
//	std::vector<VectorStructR3> checkVector147 = { InterP511, InterP512, InterP513, InterP514, InterP515, InterP516, InterP517, InterP518, InterP519, InterP520 };
//
//
//	std::vector<VectorStructR3> ReferenzVector147 = { { 0.0, 1.3557953563, 20.336930345 },{ 0.0, 0.65448729963, 19.634618989 },{ 0.0, 0.0, 18.810213100 },{ 0.0, -0.59461801827, 17.838540548 },{ 0.0, 0.0, 0.0 },
//	{ 0.0, 0.68850330041, 19.672450494 },{ 0.0, 0.10442656170, 18.955734383 },{ 0.0, -0.42040943779, 18.153070783 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 } };
//
//
//	bool isRight147 = Math::compareAllVectorElements(checkVector147, ReferenzVector147, 9);
//	checkMethodesSphericalLens.push_back(isRight147);
//
//	//________________________________________________________________________________________________________________________________________________________________
//	//________________________________________________________________________________________________________________________________________________________________
//	// Linse -45° gedreht, Apex Sphere (0.0, 1.0, 20.0), Radius -9mm
//	// Startwert (0.0, 0.0, 0.0)
//	Ray_LLT Ray521(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray522(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray523(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray524(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -0.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray525(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//
//	SphericalSurface_LLT S52(/*radius*/9.0, /*semiHeight*/2.817458, /*Apex of the sphere*/{ 0.0, 1.0, 20.0 },
//		/*Direction*/ VectorStructR3{ 0.0, -1.0, -1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.0);
//
//	IntersectInformationStruct InterInfo521 = S52.calculateIntersection(Ray521);
//	VectorStructR3 InterP521 = InterInfo521.getIntersectionPoint();
//	IntersectInformationStruct InterInfo522 = S52.calculateIntersection(Ray522);
//	VectorStructR3 InterP522 = InterInfo522.getIntersectionPoint();
//	IntersectInformationStruct InterInfo523 = S52.calculateIntersection(Ray523);
//	VectorStructR3 InterP523 = InterInfo523.getIntersectionPoint();
//	IntersectInformationStruct InterInfo524 = S52.calculateIntersection(Ray524);
//	VectorStructR3 InterP524 = InterInfo524.getIntersectionPoint();
//	IntersectInformationStruct InterInfo525 = S52.calculateIntersection(Ray525);
//	VectorStructR3 InterP525 = InterInfo525.getIntersectionPoint();
//
//	//________________________________________________________________________________________________________
//	//Linse um -45° gedreht, Startwert (0.0, 2.0, 0.0)
//	Ray_LLT Ray526(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray527(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray528(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray529(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray530(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -3.0, 15.0 }, /*wavelength*/500.0, 1.0);
//
//
//	IntersectInformationStruct InterInfo526 = S52.calculateIntersection(Ray526);
//	VectorStructR3 InterP526 = InterInfo526.getIntersectionPoint();
//	IntersectInformationStruct InterInfo527 = S52.calculateIntersection(Ray527);
//	VectorStructR3 InterP527 = InterInfo527.getIntersectionPoint();
//	IntersectInformationStruct InterInfo528 = S52.calculateIntersection(Ray528);
//	VectorStructR3 InterP528 = InterInfo528.getIntersectionPoint();
//	IntersectInformationStruct InterInfo529 = S52.calculateIntersection(Ray529);
//	VectorStructR3 InterP529 = InterInfo529.getIntersectionPoint();
//	IntersectInformationStruct InterInfo530 = S52.calculateIntersection(Ray530);
//	VectorStructR3 InterP530 = InterInfo530.getIntersectionPoint();
//
//	std::vector<VectorStructR3> checkVector148 = { InterP521, InterP522, InterP523, InterP524, InterP525, InterP526, InterP527, InterP528, InterP529, InterP530 };
//
//
//	std::vector<VectorStructR3> ReferenzVector148 = { { 0.0, 1.3114966996, 19.672450494 },{ 0.0, 0.67691522223, 20.307456667 },{ 0.0, 0.0, 20.862927792 },{ 0.0, -0.71133783716,  21.340135115 },{ 0.0, 0.0, 0.0 },
//	{ 0.0, 0.64420464365, 20.336930345 },{ 0.0, -0.093111580763, 20.931115808 },{ 0.0, -0.85681860771, 21.426139558 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 } };
//
//
//	bool isRight148 = Math::compareAllVectorElements(checkVector148, ReferenzVector148, 9);
//	checkMethodesSphericalLens.push_back(isRight148);
//
//	//________________________________________________________________________________________________________________________________________________________________
//	//________________________________________________________________________________________________________________________________________________________________
//	// Linse 90° gedreht, Apex Sphere (0.0, 1.0, 20.0), Radius -9mm
//	// Startwert (0.0, 0.0, 0.0)
//	Ray_LLT Ray531(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray532(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray533(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray534(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -0.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray535(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//
//	SphericalSurface_LLT S53(/*radius*/9.0, /*semiHeight*/2.817458, /*Apex of the sphere*/{ 0.0, 1.0, 20.0 },
//		/*Direction*/ VectorStructR3{ 0.0, 1.0, 0.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.0);
//
//	//InterP531 stimmt nicht mit Zemax überein, Programm berechnet ersten Schnittpunkt mit Linse, als Referenz eingesetzt
//	IntersectInformationStruct InterInfo531 = S53.calculateIntersection(Ray531);
//	VectorStructR3 InterP531 = InterInfo531.getIntersectionPoint();
//	IntersectInformationStruct InterInfo532 = S53.calculateIntersection(Ray532);
//	VectorStructR3 InterP532 = InterInfo532.getIntersectionPoint();
//	IntersectInformationStruct InterInfo533 = S53.calculateIntersection(Ray533);
//	VectorStructR3 InterP533 = InterInfo533.getIntersectionPoint();
//	IntersectInformationStruct InterInfo534 = S53.calculateIntersection(Ray534);
//	VectorStructR3 InterP534 = InterInfo534.getIntersectionPoint();
//	IntersectInformationStruct InterInfo535 = S53.calculateIntersection(Ray535);
//	VectorStructR3 InterP535 = InterInfo535.getIntersectionPoint();
//
//	//________________________________________________________________________________________________________
//	//Linse um 90° gedreht, Startwert (0.0, 2.0, 0.0)
//	Ray_LLT Ray536(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray537(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray538(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray539(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray540(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -3.0, 15.0 }, /*wavelength*/500.0, 1.0);
//
//
//	IntersectInformationStruct InterInfo536 = S53.calculateIntersection(Ray536);
//	VectorStructR3 InterP536 = InterInfo536.getIntersectionPoint();
//	IntersectInformationStruct InterInfo537 = S53.calculateIntersection(Ray537);
//	VectorStructR3 InterP537 = InterInfo537.getIntersectionPoint();
//	IntersectInformationStruct InterInfo538 = S53.calculateIntersection(Ray538);
//	VectorStructR3 InterP538 = InterInfo538.getIntersectionPoint();
//	IntersectInformationStruct InterInfo539 = S53.calculateIntersection(Ray539);
//	VectorStructR3 InterP539 = InterInfo539.getIntersectionPoint();
//	IntersectInformationStruct InterInfo540 = S53.calculateIntersection(Ray540);
//	VectorStructR3 InterP540 = InterInfo540.getIntersectionPoint();
//
//
//	std::vector<VectorStructR3> checkVector149 = { InterP531, InterP532, InterP533, InterP534, InterP535, InterP536, InterP537, InterP538, InterP539, InterP540 };
//
//
//	std::vector<VectorStructR3> ReferenzVector149 = { { 0.0, 1.2057669623074985, 18.086504434612475 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },
//	{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 } };
//
//
//	bool isRight149 = Math::compareAllVectorElements(checkVector149, ReferenzVector149, 9);
//	checkMethodesSphericalLens.push_back(isRight149);
//
//	//________________________________________________________________________________________________________________________________________________________________
//	//________________________________________________________________________________________________________________________________________________________________
//	// Linse -90° gedreht, Apex Sphere (0.0, 1.0, 20.0), Radius -9mm
//	// Startwert (0.0, 0.0, 0.0)
//	Ray_LLT Ray541(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray542(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray543(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray544(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -0.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray545(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//
//	SphericalSurface_LLT S54(/*radius*/9.0, /*semiHeight*/2.817458, /*Apex of the sphere*/{ 0.0, 1.0, 20.0 },
//		/*Direction*/ VectorStructR3{ 0.0, -1.0, 0.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.0);
//
//	//InterP542: stimmt nicht überein, Programm berechnet ersten Schnittpunkt mit Linse, als Referenz eingesetzt
//	IntersectInformationStruct InterInfo541 = S54.calculateIntersection(Ray541);
//	VectorStructR3 InterP541 = InterInfo541.getIntersectionPoint();
//	IntersectInformationStruct InterInfo542 = S54.calculateIntersection(Ray542);
//	VectorStructR3 InterP542 = InterInfo542.getIntersectionPoint();
//	IntersectInformationStruct InterInfo543 = S54.calculateIntersection(Ray543);
//	VectorStructR3 InterP543 = InterInfo543.getIntersectionPoint();
//	IntersectInformationStruct InterInfo544 = S54.calculateIntersection(Ray544);
//	VectorStructR3 InterP544 = InterInfo544.getIntersectionPoint();
//	IntersectInformationStruct InterInfo545 = S54.calculateIntersection(Ray545);
//	VectorStructR3 InterP545 = InterInfo545.getIntersectionPoint();
//
//	//________________________________________________________________________________________________________
//	//Linse um -90° gedreht, Startwert (0.0, 2.0, 0.0)
//	Ray_LLT Ray546(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray547(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray548(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray549(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray550(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -3.0, 15.0 }, /*wavelength*/500.0, 1.0);
//
//
//	//InteP546: Schnittpunkt stimmt nicht mit Zemax überein, Programm berechnet ersten Schnittpunkt mit Linse
//	IntersectInformationStruct InterInfo546 = S54.calculateIntersection(Ray546);
//	VectorStructR3 InterP546 = InterInfo546.getIntersectionPoint();
//	IntersectInformationStruct InterInfo547 = S54.calculateIntersection(Ray547);
//	VectorStructR3 InterP547 = InterInfo547.getIntersectionPoint();
//	IntersectInformationStruct InterInfo548 = S54.calculateIntersection(Ray548);
//	VectorStructR3 InterP548 = InterInfo548.getIntersectionPoint();
//	IntersectInformationStruct InterInfo549 = S54.calculateIntersection(Ray549);
//	VectorStructR3 InterP549 = InterInfo549.getIntersectionPoint();
//	IntersectInformationStruct InterInfo550 = S54.calculateIntersection(Ray550);
//	VectorStructR3 InterP550 = InterInfo550.getIntersectionPoint();
//
//	std::vector<VectorStructR3> checkVector150 = { InterP541, InterP542, InterP543, InterP544, InterP545, InterP546, InterP547, InterP548, InterP549, InterP550 };
//
//
//	std::vector<VectorStructR3> ReferenzVector150 = { { 0.0, 0.0, 0.0 },{ 0.0, 0.57563229773543478, 17.268968932063043 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },
//	{ 0.0, 0.79423303769250020, 18.086504434612497 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 } };
//
//
//	bool isRight150 = Math::compareAllVectorElements(checkVector150, ReferenzVector150, 9);
//	checkMethodesSphericalLens.push_back(isRight150);
//
//
//	//________________________________________________________________________________________________________________________________________________________________
//	//_______________________________________________________________________________________________________________________________________________________________
//	// Linse 0° gedreht, Apex Sphere (0.0, -1.0, 20.0), Radius -9mm
//	// Startwert (0.0, 0.0, 0.0)
//	Ray_LLT Ray551(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray552(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray553(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray554(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -0.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray555(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//
//	SphericalSurface_LLT S55(/*radius*/9.0, /*semiHeight*/2.817458, /*Apex of the sphere*/{ 0.0, -1.0, 20.0 },
//		/*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.0);
//
//	IntersectInformationStruct InterInfo551 = S55.calculateIntersection(Ray551);
//	VectorStructR3 InterP551 = InterInfo551.getIntersectionPoint();
//	IntersectInformationStruct InterInfo552 = S55.calculateIntersection(Ray552);
//	VectorStructR3 InterP552 = InterInfo552.getIntersectionPoint();
//	IntersectInformationStruct InterInfo553 = S55.calculateIntersection(Ray553);
//	VectorStructR3 InterP553 = InterInfo553.getIntersectionPoint();
//	IntersectInformationStruct InterInfo554 = S55.calculateIntersection(Ray554);
//	VectorStructR3 InterP554 = InterInfo554.getIntersectionPoint();
//	IntersectInformationStruct InterInfo555 = S55.calculateIntersection(Ray555);
//	VectorStructR3 InterP555 = InterInfo555.getIntersectionPoint();
//
//	//________________________________________________________________________________________________________
//	//Linse um 0° gedreht, Startwert (0.0, 2.0, 0.0)
//	Ray_LLT Ray556(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray557(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray558(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray559(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray560(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -3.0, 15.0 }, /*wavelength*/500.0, 1.0);
//
//
//	IntersectInformationStruct InterInfo556 = S55.calculateIntersection(Ray556);
//	VectorStructR3 InterP556 = InterInfo556.getIntersectionPoint();
//	IntersectInformationStruct InterInfo557 = S55.calculateIntersection(Ray557);
//	VectorStructR3 InterP557 = InterInfo557.getIntersectionPoint();
//	IntersectInformationStruct InterInfo558 = S55.calculateIntersection(Ray558);
//	VectorStructR3 InterP558 = InterInfo558.getIntersectionPoint();
//	IntersectInformationStruct InterInfo559 = S55.calculateIntersection(Ray559);
//	VectorStructR3 InterP559 = InterInfo559.getIntersectionPoint();
//	IntersectInformationStruct InterInfo560 = S55.calculateIntersection(Ray560);
//	VectorStructR3 InterP560 = InterInfo560.getIntersectionPoint();
//
//	std::vector<VectorStructR3> checkVector151 = { InterP551, InterP552, InterP553, InterP554, InterP555, InterP556, InterP557, InterP558, InterP559, InterP560 };
//
//
//	std::vector<VectorStructR3> ReferenzVector151 = { { 0.0, 1.3131770364, 19.697655546 },{ 0.0, 0.66151009817, 19.845302945 },{ 0.0, 0.0, 19.944271910 },{ 0.0, -0.66646058005, 19.993817402 },{ 0.0, -1.3329226835, 19.993840252 },
//	{ 0.0, 0.67717695337, 19.842345699 },{ 0.0, 0.0056360012072, 19.943639988 },{ 0.0, -0.66583924503, 19.993794338 },{ 0.0, -1.3323104822, 19.993862893 },{ 0.0, -1.9890968386, 19.945484193 } };
//
//	bool isRight151 = Math::compareAllVectorElements(checkVector151, ReferenzVector151, 9);
//	checkMethodesSphericalLens.push_back(isRight151);
//
//
//	//________________________________________________________________________________________________________________________________________________________________
//	//________________________________________________________________________________________________________________________________________________________________
//	// Linse 45° gedreht, Apex Sphere (0.0, -1.0, 20.0), Radius -9mm
//	// Startwert (0.0, 0.0, 0.0)
//	Ray_LLT Ray561(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray562(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray563(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray564(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -0.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray565(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//
//	SphericalSurface_LLT S56(/*radius*/9.0, /*semiHeight*/2.817458, /*Apex of the sphere*/{ 0.0, -1.0, 20.0 },
//		/*Direction*/ VectorStructR3{ 0.0, 1.0, -1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.0);
//
//	IntersectInformationStruct InterInfo561 = S56.calculateIntersection(Ray561);
//	VectorStructR3 InterP561 = InterInfo561.getIntersectionPoint();
//	IntersectInformationStruct InterInfo562 = S56.calculateIntersection(Ray562);
//	VectorStructR3 InterP562 = InterInfo562.getIntersectionPoint();
//	IntersectInformationStruct InterInfo563 = S56.calculateIntersection(Ray563);
//	VectorStructR3 InterP563 = InterInfo563.getIntersectionPoint();
//	IntersectInformationStruct InterInfo564 = S56.calculateIntersection(Ray564);
//	VectorStructR3 InterP564 = InterInfo564.getIntersectionPoint();
//	IntersectInformationStruct InterInfo565 = S56.calculateIntersection(Ray565);
//	VectorStructR3 InterP565 = InterInfo565.getIntersectionPoint();
//
//	//________________________________________________________________________________________________________
//	//Linse um 45° gedreht, Startwert (0.0, 2.0, 0.0)
//	Ray_LLT Ray566(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray567(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray568(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray569(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray570(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -3.0, 15.0 }, /*wavelength*/500.0, 1.0);
//
//
//	IntersectInformationStruct InterInfo566 = S56.calculateIntersection(Ray566);
//	VectorStructR3 InterP566 = InterInfo566.getIntersectionPoint();
//	IntersectInformationStruct InterInfo567 = S56.calculateIntersection(Ray567);
//	VectorStructR3 InterP567 = InterInfo567.getIntersectionPoint();
//	IntersectInformationStruct InterInfo568 = S56.calculateIntersection(Ray568);
//	VectorStructR3 InterP568 = InterInfo568.getIntersectionPoint();
//	IntersectInformationStruct InterInfo569 = S56.calculateIntersection(Ray569);
//	VectorStructR3 InterP569 = InterInfo569.getIntersectionPoint();
//	IntersectInformationStruct InterInfo570 = S56.calculateIntersection(Ray570);
//	VectorStructR3 InterP570 = InterInfo570.getIntersectionPoint();
//
//	std::vector<VectorStructR3> checkVector152 = { InterP561, InterP562, InterP563, InterP564, InterP565, InterP566, InterP567, InterP568, InterP569, InterP570 };
//
//
//	std::vector<VectorStructR3> ReferenzVector152 = { { 0.0, 0.0, 0.0 },{ 0.0, 0.71133783716, 21.340135115 },{ 0.0, 0.0, 20.862927792 },{ 0.0, -0.67691522223, 20.307456667 },{ 0.0, -1.3114966996, 19.672450494 },
//	{ 0.0, 0.58260605943, 21.260909108 },{ 0.0, -0.080265578796, 20.802655788 },{ 0.0, -0.70433654596, 20.282524095 },{ 0.0, -1.2838195578, 19.702917347 },{ 0.0, -1.8132565541, 19.066282771 } };
//
//
//	bool isRight152 = Math::compareAllVectorElements(checkVector152, ReferenzVector152, 9);
//	checkMethodesSphericalLens.push_back(isRight152);
//
//	//________________________________________________________________________________________________________________________________________________________________
//	//________________________________________________________________________________________________________________________________________________________________
//	// Linse -45° gedreht, Apex Sphere (0.0, -1.0, 20.0), Radius -9mm
//	// Startwert (0.0, 0.0, 0.0)
//	Ray_LLT Ray571(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray572(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray573(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray574(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -0.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray575(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//
//	SphericalSurface_LLT S57(/*radius*/9.0, /*semiHeight*/2.817458, /*Apex of the sphere*/{ 0.0, -1.0, 20.0 },
//		/*Direction*/ VectorStructR3{ 0.0, -1.0, -1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.0);
//
//	IntersectInformationStruct InterInfo571 = S57.calculateIntersection(Ray571);
//	VectorStructR3 InterP571 = InterInfo571.getIntersectionPoint();
//	IntersectInformationStruct InterInfo572 = S57.calculateIntersection(Ray572);
//	VectorStructR3 InterP572 = InterInfo572.getIntersectionPoint();
//	IntersectInformationStruct InterInfo573 = S57.calculateIntersection(Ray573);
//	VectorStructR3 InterP573 = InterInfo573.getIntersectionPoint();
//	IntersectInformationStruct InterInfo574 = S57.calculateIntersection(Ray574);
//	VectorStructR3 InterP574 = InterInfo574.getIntersectionPoint();
//	IntersectInformationStruct InterInfo575 = S57.calculateIntersection(Ray575);
//	VectorStructR3 InterP575 = InterInfo575.getIntersectionPoint();
//
//	//________________________________________________________________________________________________________
//	//Linse um -45° gedreht, Startwert (0.0, 2.0, 0.0)
//	Ray_LLT Ray576(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray577(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray578(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray579(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray580(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -3.0, 15.0 }, /*wavelength*/500.0, 1.0);
//
//
//	IntersectInformationStruct InterInfo576 = S57.calculateIntersection(Ray576);
//	VectorStructR3 InterP576 = InterInfo576.getIntersectionPoint();
//	IntersectInformationStruct InterInfo577 = S57.calculateIntersection(Ray577);
//	VectorStructR3 InterP577 = InterInfo577.getIntersectionPoint();
//	IntersectInformationStruct InterInfo578 = S57.calculateIntersection(Ray578);
//	VectorStructR3 InterP578 = InterInfo578.getIntersectionPoint();
//	IntersectInformationStruct InterInfo579 = S57.calculateIntersection(Ray579);
//	VectorStructR3 InterP579 = InterInfo579.getIntersectionPoint();
//	IntersectInformationStruct InterInfo580 = S57.calculateIntersection(Ray580);
//	VectorStructR3 InterP580 = InterInfo580.getIntersectionPoint();
//
//	std::vector<VectorStructR3> checkVector153 = { InterP571, InterP572, InterP573, InterP574, InterP575, InterP576, InterP577, InterP578, InterP579, InterP580 };
//
//
//	std::vector<VectorStructR3> ReferenzVector153 = { { 0.0, 0.0, 0.0 },{ 0.0, 0.59461801827, 17.838540548 },{ 0.0, 0.0, 18.810213100 },{ 0.0, -0.65448729963, 19.634618989 },{ 0.0, -1.3557953563, 20.336930345 },
//	{ 0.0, 0.0, 0.0 },{ 0.0, 0.13941113150, 18.605888685 },{ 0.0, -0.61149021382, 19.586176604 },{ 0.0, -1.3953668972, 20.372201384 },{ 0.0, -2.2016665517, 21.008332758 } };
//
//
//	bool isRight153 = Math::compareAllVectorElements(checkVector153, ReferenzVector153, 9);
//	checkMethodesSphericalLens.push_back(isRight153);
//
//
//	//________________________________________________________________________________________________________________________________________________________________
//	//________________________________________________________________________________________________________________________________________________________________
//	// Linse 90° gedreht, Apex Sphere (0.0, 1.0, 20.0), Radius -9mm
//	// Startwert (0.0, 0.0, 0.0)
//	Ray_LLT Ray581(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray582(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray583(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray584(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -0.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray585(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//
//	SphericalSurface_LLT S58(/*radius*/9.0, /*semiHeight*/2.817458, /*Apex of the sphere*/{ 0.0, -1.0, 20.0 },
//		/*Direction*/ VectorStructR3{ 0.0, 1.0, 0.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.0);
//
//	//InterP584 stimmt nicht mit Zemax überein, Programm berechnet ersten Schnittpunkt, als Referenz eingesetzt
//	IntersectInformationStruct InterInfo581 = S58.calculateIntersection(Ray581);
//	VectorStructR3 InterP581 = InterInfo581.getIntersectionPoint();
//	IntersectInformationStruct InterInfo582 = S58.calculateIntersection(Ray582);
//	VectorStructR3 InterP582 = InterInfo582.getIntersectionPoint();
//	IntersectInformationStruct InterInfo583 = S58.calculateIntersection(Ray583);
//	VectorStructR3 InterP583 = InterInfo583.getIntersectionPoint();
//	IntersectInformationStruct InterInfo584 = S58.calculateIntersection(Ray584);
//	VectorStructR3 InterP584 = InterInfo584.getIntersectionPoint();
//	IntersectInformationStruct InterInfo585 = S58.calculateIntersection(Ray585);
//	VectorStructR3 InterP585 = InterInfo585.getIntersectionPoint();
//
//	//________________________________________________________________________________________________________
//	//Linse um 90° gedreht, Startwert (0.0, 2.0, 0.0)
//	Ray_LLT Ray586(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray587(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray588(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray589(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray590(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -3.0, 15.0 }, /*wavelength*/500.0, 1.0);
//
//
//	IntersectInformationStruct InterInfo586 = S58.calculateIntersection(Ray586);
//	VectorStructR3 InterP586 = InterInfo586.getIntersectionPoint();
//	IntersectInformationStruct InterInfo587 = S58.calculateIntersection(Ray587);
//	VectorStructR3 InterP587 = InterInfo587.getIntersectionPoint();
//	IntersectInformationStruct InterInfo588 = S58.calculateIntersection(Ray588);
//	VectorStructR3 InterP588 = InterInfo588.getIntersectionPoint();
//	IntersectInformationStruct InterInfo589 = S58.calculateIntersection(Ray589);
//	VectorStructR3 InterP589 = InterInfo589.getIntersectionPoint();
//	IntersectInformationStruct InterInfo590 = S58.calculateIntersection(Ray590);
//	VectorStructR3 InterP590 = InterInfo590.getIntersectionPoint();
//
//
//	std::vector<VectorStructR3> checkVector154 = { InterP581, InterP582, InterP583, InterP584, InterP585, InterP586, InterP587, InterP588, InterP589, InterP590 };
//
//
//	std::vector<VectorStructR3> ReferenzVector154 = { { 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, -0.57563229773543478, 17.268968932063043 },{ 0.0, 0.0, 0.0 },
//	{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, -0.86993782540, 21.524533691 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 } };
//
//
//	bool isRight154 = Math::compareAllVectorElements(checkVector154, ReferenzVector154, 9);
//	checkMethodesSphericalLens.push_back(isRight154);
//
//	//________________________________________________________________________________________________________________________________________________________________
//	//________________________________________________________________________________________________________________________________________________________________
//	// Linse -90° gedreht, Apex Sphere (0.0, 1.0, 20.0), Radius -9mm
//	// Startwert (0.0, 0.0, 0.0)
//	Ray_LLT Ray591(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray592(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray593(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray594(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -0.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray595(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//
//	SphericalSurface_LLT S59(/*radius*/9.0, /*semiHeight*/2.817458, /*Apex of the sphere*/{ 0.0, -1.0, 20.0 },
//		/*Direction*/ VectorStructR3{ 0.0, -1.0, 0.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.0);
//
//	//InterP595 stimmt nicht mit Zemax überein, Programm berechnet ersten Schnittpunkt mit LInse, als Referenz eingsetzt
//	IntersectInformationStruct InterInfo591 = S59.calculateIntersection(Ray591);
//	VectorStructR3 InterP591 = InterInfo591.getIntersectionPoint();
//	IntersectInformationStruct InterInfo592 = S59.calculateIntersection(Ray592);
//	VectorStructR3 InterP592 = InterInfo592.getIntersectionPoint();
//	IntersectInformationStruct InterInfo593 = S59.calculateIntersection(Ray593);
//	VectorStructR3 InterP593 = InterInfo593.getIntersectionPoint();
//	IntersectInformationStruct InterInfo594 = S59.calculateIntersection(Ray594);
//	VectorStructR3 InterP594 = InterInfo594.getIntersectionPoint();
//	IntersectInformationStruct InterInfo595 = S59.calculateIntersection(Ray595);
//	VectorStructR3 InterP595 = InterInfo595.getIntersectionPoint();
//
//	//________________________________________________________________________________________________________
//	//Linse um -90° gedreht, Startwert (0.0, 2.0, 0.0)
//	Ray_LLT Ray596(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray597(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray598(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.0, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray599(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.5, 15.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray600(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -3.0, 15.0 }, /*wavelength*/500.0, 1.0);
//
//
//	//InterP599 und InterP600 stimmt nicht mit Zemax überein, Programm berechnet ersten Schnittpunkt mit Linse, als Referenz eingesetzt
//	IntersectInformationStruct InterInfo596 = S59.calculateIntersection(Ray596);
//	VectorStructR3 InterP596 = InterInfo596.getIntersectionPoint();
//	IntersectInformationStruct InterInfo597 = S59.calculateIntersection(Ray597);
//	VectorStructR3 InterP597 = InterInfo597.getIntersectionPoint();
//	IntersectInformationStruct InterInfo598 = S59.calculateIntersection(Ray598);
//	VectorStructR3 InterP598 = InterInfo598.getIntersectionPoint();
//	IntersectInformationStruct InterInfo599 = S59.calculateIntersection(Ray599);
//	VectorStructR3 InterP599 = InterInfo599.getIntersectionPoint();
//	IntersectInformationStruct InterInfo600 = S59.calculateIntersection(Ray600);
//	VectorStructR3 InterP600 = InterInfo600.getIntersectionPoint();
//
//	std::vector<VectorStructR3> checkVector155 = { InterP591, InterP592, InterP593, InterP594, InterP595, InterP596, InterP597, InterP598, InterP599, InterP600 };
//
//
//	std::vector<VectorStructR3> ReferenzVector155 = { { 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, -1.2057669623074985, 18.086504434612475 },
//	{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, -1.1049393846317908,  18.629636307790744 },{ 0.0, -1.4425213939075419, 17.212606969537710 } };
//
//
//	bool isRight155 = Math::compareAllVectorElements(checkVector155, ReferenzVector155, 9);
//	checkMethodesSphericalLens.push_back(isRight155);
//
//	// *****************************************************************************************************************
	bool output = Math::checkTrueOfVectorElements(checkMethodesSphericalLens);
	// *****************************************************************************************************************

	return output;
}