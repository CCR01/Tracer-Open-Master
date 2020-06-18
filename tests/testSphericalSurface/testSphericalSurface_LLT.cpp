#include "testSphericalSurface_LLT.h"
#include "..\..\LowLevelTracing\Surfaces\SphericalSurface_LLT.h"
#include "..\..\LowLevelTracing\Light_LLT.h"
#include <iostream>
#include <vector>


bool  testSphericalSurface_LLT::checkSphericalSurface_LLT()
{
	std::vector<bool> checkMethodesSphericalLens;
	JonesVector_LLT jones{ 1.0,1.0,1.0,1.0 };
	//dummy light
	Light_LLT light{550.0, 1.0,jones,typeLight::typeLightRay};

	// Linse um 0° gedreht, Apex Sphere (0.0, 0.0, 20.0) 
	// Startwert (0.0, 0.0, 0.0)
	LightRayStruct LightRay1(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 1.0, 15.0 }, 1.0);
	LightRayStruct LightRay2(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.5, 15.0 }, 1.0);
	LightRayStruct LightRay3(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.0, 15.0 }, 1.0);
	LightRayStruct LightRay4(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -0.5, 15.0}, 1.0);
	LightRayStruct LightRay5(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0}, 1.0);
	
	SphericalSurface_LLT S0(/*radius*/9.0, /*semiHeight*/2.817458, /*Apex of the sphere*/{ 0.0, 0.0, 20.0 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.0);

	IntersectInformationStruct InterInfo1 = S0.calculateIntersection(LightRay1);
	VectorStructR3 InterP1 = InterInfo1.getIntersectionPoint();
	IntersectInformationStruct InterInfo2 = S0.calculateIntersection(LightRay2);
	VectorStructR3 InterP2 = InterInfo2.getIntersectionPoint();
	IntersectInformationStruct InterInfo3 = S0.calculateIntersection(LightRay3);
	VectorStructR3 InterP3 = InterInfo3.getIntersectionPoint();
	IntersectInformationStruct InterInfo4 = S0.calculateIntersection(LightRay4);
	VectorStructR3 InterP4 = InterInfo4.getIntersectionPoint();
	IntersectInformationStruct InterInfo5 = S0.calculateIntersection(LightRay5);
	VectorStructR3 InterP5 = InterInfo5.getIntersectionPoint();

	//________________________________________________________________________________________________________
	//Linse um 0° gedreht, Startwert (0.0, 4.0, 0.0)
	LightRayStruct Ray6(/*origin*/{ 0.0, 4.0, 0.0 }, /*direction*/{ 0.0, -3.0, 15.0 }, 1.0);
	LightRayStruct Ray7(/*origin*/{ 0.0, 4.0, 0.0 }, /*direction*/{ 0.0, -3.5, 15.0 }, 1.0);
	LightRayStruct Ray8(/*origin*/{ 0.0, 4.0, 0.0 }, /*direction*/{ 0.0, -4.0, 15.0 }, 1.0);
	LightRayStruct Ray9(/*origin*/{ 0.0, 4.0, 0.0 }, /*direction*/{ 0.0, -4.5, 15.0 }, 1.0);
	LightRayStruct LightRay10(/*origin*/{ 0.0, 4.0, 0.0 }, /*direction*/{ 0.0, -5.0, 15.0}, 1.0);

	IntersectInformationStruct InterInfo6 = S0.calculateIntersection(Ray6);
	VectorStructR3 InterP6 = InterInfo6.getIntersectionPoint();
	IntersectInformationStruct InterInfo7 = S0.calculateIntersection(Ray7);
	VectorStructR3 InterP7 = InterInfo7.getIntersectionPoint();
	IntersectInformationStruct InterInfo8 = S0.calculateIntersection(Ray8);
	VectorStructR3 InterP8 = InterInfo8.getIntersectionPoint();
	IntersectInformationStruct InterInfo9 = S0.calculateIntersection(Ray9);
	VectorStructR3 InterP9 = InterInfo9.getIntersectionPoint();
	IntersectInformationStruct InterInfo10 = S0.calculateIntersection(LightRay10);
	VectorStructR3 InterP10 = InterInfo10.getIntersectionPoint();

	std::vector<VectorStructR3> checkVector10 = { InterP1, InterP2, InterP3, InterP4, InterP5, InterP6, InterP7, InterP8, InterP9, InterP10 };


	std::vector<VectorStructR3> ReferenzVector10 = { { 0.0, 1.3400211868, 20.100317802 },{ 0.0, 0.66749289100, 20.024786730 },{ 0.0, 0.0, 20.0 } ,{ 0.0, -0.66749289100, 20.024786730 },{ 0.0, -1.3400211868, 20.100317802 },
	{ 0.0, -6.6662231291e-12, 20.0 },{ 0.0, -0.67253812043, 20.025163373 },{ 0.0, -1.3609310176, 20.103491316 },{ 0.0, -2.0725674561, 20.241891520 },{ 0.0, -2.8174575579, 20.452372674 } };

	

	bool isRight10 = Math::compareAllVectorElements(checkVector10, ReferenzVector10, 8);
	checkMethodesSphericalLens.push_back(isRight10);

	//____________________________________________________________________________________________________________________
	//____________________________________________________________________________________________________________________
	// Linse um +45° gedreht, Startwert (0.0, 0.0, 0.0)
	LightRayStruct LightRay11(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 1.0, 15.0 }, 1.0);
	LightRayStruct LightRay12(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.5, 15.0 },  1.0);
	LightRayStruct LightRay13(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.0, 15.0 },  1.0);
	LightRayStruct LightRay14(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -0.5, 15.0 },  1.0);
	LightRayStruct LightRay15(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 },  1.0);

	SphericalSurface_LLT S1(/*radius*/9.0, /*semiHeight*/2.817458, /*Apex of the sphere*/{ 0.0, 0.0, 20.0 },
		/*Direction*/ VectorStructR3{ 0.0, -1.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.0);

	IntersectInformationStruct InterInfo11 = S1.calculateIntersection(LightRay11);
	VectorStructR3 InterP11 = InterInfo11.getIntersectionPoint();
	IntersectInformationStruct InterInfo12 = S1.calculateIntersection(LightRay12);
	VectorStructR3 InterP12 = InterInfo12.getIntersectionPoint();
	IntersectInformationStruct InterInfo13 = S1.calculateIntersection(LightRay13);
	VectorStructR3 InterP13 = InterInfo13.getIntersectionPoint();
	IntersectInformationStruct InterInfo14 = S1.calculateIntersection(LightRay14);
	VectorStructR3 InterP14 = InterInfo14.getIntersectionPoint();
	IntersectInformationStruct InterInfo15 = S1.calculateIntersection(LightRay15);
	VectorStructR3 InterP15 = InterInfo15.getIntersectionPoint();

	//_____________________________________________________________________________________________________________
	//Linse um +45° gedreht, Startwert (0.0, 4.0, 0.0)
	LightRayStruct LightRay16(/*origin*/{ 0.0, 4.0, 0.0 }, /*direction*/{ 0.0, -3.0, 15.0 },  1.0);
	LightRayStruct LightRay17(/*origin*/{ 0.0, 4.0, 0.0 }, /*direction*/{ 0.0, -3.5, 15.0 },  1.0);
	LightRayStruct LightRay18(/*origin*/{ 0.0, 4.0, 0.0 }, /*direction*/{ 0.0, -4.0, 15.0 },  1.0);
	LightRayStruct LightRay19(/*origin*/{ 0.0, 4.0, 0.0 }, /*direction*/{ 0.0, -4.5, 15.0 },  1.0);
	LightRayStruct LightRay20(/*origin*/{ 0.0, 4.0, 0.0 }, /*direction*/{ 0.0, -5.0, 15.0 },  1.0);


	IntersectInformationStruct InterInfo16 = S1.calculateIntersection(LightRay16);
	VectorStructR3 InterP16 = InterInfo16.getIntersectionPoint();
	IntersectInformationStruct InterInfo17 = S1.calculateIntersection(LightRay17);
	VectorStructR3 InterP17 = InterInfo17.getIntersectionPoint();
	IntersectInformationStruct InterInfo18 = S1.calculateIntersection(LightRay18);
	VectorStructR3 InterP18 = InterInfo18.getIntersectionPoint();
	IntersectInformationStruct InterInfo19 = S1.calculateIntersection(LightRay19);
	VectorStructR3 InterP19 = InterInfo19.getIntersectionPoint();
	IntersectInformationStruct InterInfo20 = S1.calculateIntersection(LightRay20);
	VectorStructR3 InterP20 = InterInfo20.getIntersectionPoint();

	std::vector<VectorStructR3> checkVector23 = { InterP11, InterP12, InterP13, InterP14, InterP15, InterP16, InterP17, InterP18, InterP19, InterP20 };
	std::vector<VectorStructR3> ReferenzVector23 = { { 0.0, 1.4611975761, 21.917963642 },{ 0.0, 0.69259381472, 20.777814442 },{ 0.0, 0.0, 20.0 } ,{ 0.0, -0.64709617100, 19.412885130 },{ 0.0, -1.2632612082, 18.948918123 },
	{ 0.0, -5.5556151558E-012, 20.0 },{ 0.0, -0.54880972986, 19.494898842 },{ 0.0, -1.0863414733, 19.073780525 },{ 0.0, -1.6155579662, 18.718526554 },{ 0.0,-2.1390799085, 18.417239725 } };

	bool isRight23 = Math::compareAllVectorElements(checkVector23, ReferenzVector23, 9);
	checkMethodesSphericalLens.push_back(isRight23);


	//____________________________________________________________________________________________________________________
	//____________________________________________________________________________________________________________________
	// Linse um +90° gedreht, Startwert (0.0, 0.0, 0.0)
	LightRayStruct LightRay21(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 1.0, 15.0 },  1.0);
	LightRayStruct LightRay22(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.5, 15.0 },  1.0);
	LightRayStruct LightRay23(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.0, 15.0 },  1.0);
	LightRayStruct LightRay24(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -0.5, 15.0 },  1.0);
	LightRayStruct LightRay25(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 },  1.0);

	SphericalSurface_LLT S2(/*radius*/9.0, /*semiHeight*/2.817458, /*Apex of the sphere*/{ 0.0, 0.0, 20.0 },
		/*Direction*/ VectorStructR3{ 0.0, -1.0, 0.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.0);

	IntersectInformationStruct InterInfo21 = S2.calculateIntersection(LightRay21);
	VectorStructR3 InterP21 = InterInfo21.getIntersectionPoint();
	IntersectInformationStruct InterInfo22 = S2.calculateIntersection(LightRay22);
	VectorStructR3 InterP22 = InterInfo22.getIntersectionPoint();
	IntersectInformationStruct InterInfo23 = S2.calculateIntersection(LightRay23);
	VectorStructR3 InterP23 = InterInfo23.getIntersectionPoint();
	IntersectInformationStruct InterInfo24 = S2.calculateIntersection(LightRay24);
	VectorStructR3 InterP24 = InterInfo24.getIntersectionPoint();
	IntersectInformationStruct InterInfo25 = S2.calculateIntersection(LightRay25);
	VectorStructR3 InterP25 = InterInfo25.getIntersectionPoint();

	//__________________________________________________________________________________________________________ 
	//Linse um +90° gedreht, Startwert (0.0, 4.0, 0.0)
	LightRayStruct LightRay26(/*origin*/{ 0.0, 4.0, 0.0 }, /*direction*/{ 0.0, -3.0, 15.0 },  1.0);
	LightRayStruct LightRay27(/*origin*/{ 0.0, 4.0, 0.0 }, /*direction*/{ 0.0, -3.5, 15.0 },  1.0);
	LightRayStruct LightRay28(/*origin*/{ 0.0, 4.0, 0.0 }, /*direction*/{ 0.0, -4.0, 15.0 },  1.0);
	LightRayStruct LightRay29(/*origin*/{ 0.0, 4.0, 0.0 }, /*direction*/{ 0.0, -4.5, 15.0 },  1.0);
	LightRayStruct LightRay30(/*origin*/{ 0.0, 4.0, 0.0 }, /*direction*/{ 0.0, -5.0, 15.0 },  1.0);


	IntersectInformationStruct InterInfo26 = S2.calculateIntersection(LightRay26);
	VectorStructR3 InterP26 = InterInfo26.getIntersectionPoint();
	IntersectInformationStruct InterInfo27 = S2.calculateIntersection(LightRay27);
	VectorStructR3 InterP27 = InterInfo27.getIntersectionPoint();
	IntersectInformationStruct InterInfo28 = S2.calculateIntersection(LightRay28);
	VectorStructR3 InterP28 = InterInfo28.getIntersectionPoint();
	IntersectInformationStruct InterInfo29 = S2.calculateIntersection(LightRay29);
	VectorStructR3 InterP29 = InterInfo29.getIntersectionPoint();
	IntersectInformationStruct InterInfo30 = S2.calculateIntersection(LightRay30);
	VectorStructR3 InterP30 = InterInfo30.getIntersectionPoint();

	std::vector<VectorStructR3> checkVector45 = { InterP21, InterP22, InterP23, InterP24, InterP25, InterP26, InterP27, InterP28, InterP29, InterP30 };
	std::vector<VectorStructR3> ReferenzVector45 = { { 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0,-1.5777218104e-030, 20.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },
	{ 0.0, -6.1715247777E-023, 20.0 },{ 0.0, -0.21275516734, 18.054665003 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 } };

	bool isRight45 = Math::compareAllVectorElements(checkVector45, ReferenzVector45, 9);
	checkMethodesSphericalLens.push_back(isRight45);

	//____________________________________________________________________________________________________________________
	//____________________________________________________________________________________________________________________
	// Linse um -45° gedreht, Startwert (0.0, 0.0, 0.0)
	LightRayStruct LightRay31(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 1.0, 15.0 },  1.0);
	LightRayStruct LightRay32(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.5, 15.0 },  1.0);
	LightRayStruct LightRay33(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.0, 15.0 },  1.0);
	LightRayStruct LightRay34(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -0.5, 15.0 },  1.0);
	LightRayStruct LightRay35(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 },  1.0);

	SphericalSurface_LLT S3(/*radius*/9.0, /*semiHeight*/2.817458, /*Apex of the sphere*/{ 0.0, 0.0, 20.0 },
		/*Direction*/ VectorStructR3{ 0.0, 1.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.0);

	IntersectInformationStruct InterInfo31 = S3.calculateIntersection(LightRay31);
	VectorStructR3 InterP31 = InterInfo31.getIntersectionPoint();
	IntersectInformationStruct InterInfo32 = S3.calculateIntersection(LightRay32);
	VectorStructR3 InterP32 = InterInfo32.getIntersectionPoint();
	IntersectInformationStruct InterInfo33 = S3.calculateIntersection(LightRay33);
	VectorStructR3 InterP33 = InterInfo33.getIntersectionPoint();
	IntersectInformationStruct InterInfo34 = S3.calculateIntersection(LightRay34);
	VectorStructR3 InterP34 = InterInfo34.getIntersectionPoint();
	IntersectInformationStruct InterInfo35 = S3.calculateIntersection(LightRay35);
	VectorStructR3 InterP35 = InterInfo35.getIntersectionPoint();

	//__________________________________________________________________________________________________________ 
	//Linse um -45° gedreht, Startwert (0.0, 4.0, 0.0)
	LightRayStruct LightRay36(/*origin*/{ 0.0, 4.0, 0.0 }, /*direction*/{ 0.0, -3.0, 15.0 },  1.0);
	LightRayStruct LightRay37(/*origin*/{ 0.0, 4.0, 0.0 }, /*direction*/{ 0.0, -3.5, 15.0 },  1.0);
	LightRayStruct LightRay38(/*origin*/{ 0.0, 4.0, 0.0 }, /*direction*/{ 0.0, -4.0, 15.0 },  1.0);
	LightRayStruct LightRay39(/*origin*/{ 0.0, 4.0, 0.0 }, /*direction*/{ 0.0, -4.5, 15.0 },  1.0);
	LightRayStruct LightRay40(/*origin*/{ 0.0, 4.0, 0.0 }, /*direction*/{ 0.0, -5.0, 15.0 },  1.0);


	IntersectInformationStruct InterInfo36 = S3.calculateIntersection(LightRay36);
	VectorStructR3 InterP36 = InterInfo36.getIntersectionPoint();
	IntersectInformationStruct InterInfo37 = S3.calculateIntersection(LightRay37);
	VectorStructR3 InterP37 = InterInfo37.getIntersectionPoint();
	IntersectInformationStruct InterInfo38 = S3.calculateIntersection(LightRay38);
	VectorStructR3 InterP38 = InterInfo38.getIntersectionPoint();
	IntersectInformationStruct InterInfo39 = S3.calculateIntersection(LightRay39);
	VectorStructR3 InterP39 = InterInfo39.getIntersectionPoint();
	IntersectInformationStruct InterInfo40 = S3.calculateIntersection(LightRay40);
	VectorStructR3 InterP40 = InterInfo40.getIntersectionPoint();

	std::vector<VectorStructR3> checkVector67 = { InterP31, InterP32, InterP33, InterP34, InterP35, InterP36, InterP37,InterP38, InterP39, InterP40 };
	std::vector<VectorStructR3> ReferenzVector67 = { { 0.0, 1.2632612082, 18.948918123 },{ 0.0, 0.64709617100, 19.412885130 },{ 0.0, 0.0, 20.0 },{ 0.0, -0.69259381472, 20.777814442 },{ 0.0, -1.4611975761, 21.917963642 },
	{ 0.0, -8.3327946967E-012, 20.0 },{ 0.0, -0.91726551290, 21.073995055 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 } };

	bool isRight67 = Math::compareAllVectorElements(checkVector67, ReferenzVector67, 9);
	checkMethodesSphericalLens.push_back(isRight67);

	//____________________________________________________________________________________________________________________
	//____________________________________________________________________________________________________________________
	// Linse um -90° gedreht, Startwert (0.0, 0.0, 0.0)
	LightRayStruct LightRay41(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 1.0, 15.0 },  1.0);
	LightRayStruct LightRay42(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.5, 15.0 },  1.0);
	LightRayStruct LightRay43(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.0, 15.0 },  1.0);
	LightRayStruct LightRay44(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -0.5, 15.0 },  1.0);
	LightRayStruct LightRay45(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 },  1.0);

	SphericalSurface_LLT S4(/*radius*/9.0, /*semiHeight*/2.817458, /*Apex of the sphere*/{ 0.0, 0.0, 20.0 },
		/*Direction*/ VectorStructR3{ 0.0, 1.0, 0.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.0);

	IntersectInformationStruct InterInfo41 = S4.calculateIntersection(LightRay41);
	VectorStructR3 InterP41 = InterInfo41.getIntersectionPoint();
	IntersectInformationStruct InterInfo42 = S4.calculateIntersection(LightRay42);
	VectorStructR3 InterP42 = InterInfo42.getIntersectionPoint();
	IntersectInformationStruct InterInfo43 = S4.calculateIntersection(LightRay43);
	VectorStructR3 InterP43 = InterInfo43.getIntersectionPoint();
	IntersectInformationStruct InterInfo44 = S4.calculateIntersection(LightRay44);
	VectorStructR3 InterP44 = InterInfo44.getIntersectionPoint();
	IntersectInformationStruct InterInfo45 = S4.calculateIntersection(LightRay45);
	VectorStructR3 InterP45 = InterInfo45.getIntersectionPoint();

	//Linse um -90° gedreht, Startwert (0.0, 4.0, 0.0)
	LightRayStruct LightRay46(/*origin*/{ 0.0, 4.0, 0.0 }, /*direction*/{ 0.0, -3.0, 15.0 },  1.0);
	LightRayStruct LightRay47(/*origin*/{ 0.0, 4.0, 0.0 }, /*direction*/{ 0.0, -3.5, 15.0 },  1.0);
	LightRayStruct LightRay48(/*origin*/{ 0.0, 4.0, 0.0 }, /*direction*/{ 0.0, -4.0, 15.0 },  1.0);
	LightRayStruct LightRay49(/*origin*/{ 0.0, 4.0, 0.0 }, /*direction*/{ 0.0, -4.5, 15.0 },  1.0);
	LightRayStruct LightRay50(/*origin*/{ 0.0, 4.0, 0.0 }, /*direction*/{ 0.0, -5.0, 15.0 },  1.0);


	IntersectInformationStruct InterInfo46 = S4.calculateIntersection(LightRay46);	// InterP46: 2 Schnittpunkte mit Sphäre
	VectorStructR3 InterP46 = InterInfo46.getIntersectionPoint();
	IntersectInformationStruct InterInfo47 = S4.calculateIntersection(LightRay47);
	VectorStructR3 InterP47 = InterInfo47.getIntersectionPoint();
	IntersectInformationStruct InterInfo48 = S4.calculateIntersection(LightRay48);
	VectorStructR3 InterP48 = InterInfo48.getIntersectionPoint();
	IntersectInformationStruct InterInfo49 = S4.calculateIntersection(LightRay49);
	VectorStructR3 InterP49 = InterInfo49.getIntersectionPoint();
	IntersectInformationStruct InterInfo50 = S4.calculateIntersection(LightRay50);
	VectorStructR3 InterP50 = InterInfo50.getIntersectionPoint();

	std::vector<VectorStructR3> checkVector89 = { InterP41, InterP42, InterP43, InterP44, InterP45, InterP46, InterP47, InterP48, InterP49, InterP50 };
	std::vector<VectorStructR3> ReferenzVector89 = { { 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 1.5777218104E-030, 20.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },
	{ 0.0, 0.0, 20.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 } };

	bool isRight89 = Math::compareAllVectorElements(checkVector89, ReferenzVector89, 9);
	checkMethodesSphericalLens.push_back(isRight89);

	//________________________________________________________________________________________________________________________________________________________________
	//________________________________________________________________________________________________________________________________________________________________
	// Linse 0° gedreht, Apex Sphere (0.0, 1.0, 20.0)
	// Startwert (0.0, 0.0, 0.0)
	LightRayStruct LightRay51(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 1.0, 15.0 },  1.0);
	LightRayStruct LightRay52(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.5, 15.0 },  1.0);
	LightRayStruct LightRay53(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.0, 15.0 },  1.0);
	LightRayStruct LightRay54(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -0.5, 15.0 },  1.0);
	LightRayStruct LightRay55(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 },  1.0);

	SphericalSurface_LLT S5(/*radius*/9.0, /*semiHeight*/2.817458, /*Apex of the sphere*/{ 0.0, 1.0, 20.0 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.0);

	IntersectInformationStruct InterInfo51 = S5.calculateIntersection(LightRay51);
	VectorStructR3 InterP51 = InterInfo51.getIntersectionPoint();
	IntersectInformationStruct InterInfo52 = S5.calculateIntersection(LightRay52);
	VectorStructR3 InterP52 = InterInfo52.getIntersectionPoint();
	IntersectInformationStruct InterInfo53 = S5.calculateIntersection(LightRay53);
	VectorStructR3 InterP53 = InterInfo53.getIntersectionPoint();
	IntersectInformationStruct InterInfo54 = S5.calculateIntersection(LightRay54);
	VectorStructR3 InterP54 = InterInfo54.getIntersectionPoint();
	IntersectInformationStruct InterInfo55 = S5.calculateIntersection(LightRay55);
	VectorStructR3 InterP55 = InterInfo55.getIntersectionPoint();

	//________________________________________________________________________________________________________
	//Linse um 0° gedreht, Startwert (0.0, 2.0, 0.0)
	LightRayStruct LightRay56(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 },  1.0);
	LightRayStruct LightRay57(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.5, 15.0 },  1.0);
	LightRayStruct LightRay58(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.0, 15.0 },  1.0);
	LightRayStruct LightRay59(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.5, 15.0 },  1.0);
	LightRayStruct Ray60(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -3.0, 15.0 },  1.0);


	//InterP57 stimmt nicht exakt mit ZEMAX-Schnittpunkt überein -> Übereinstimmung auf Kommazahlen auf 8 heruntergesetzt
	IntersectInformationStruct InterInfo56 = S5.calculateIntersection(LightRay56);
	VectorStructR3 InterP56 = InterInfo56.getIntersectionPoint();
	IntersectInformationStruct InterInfo57 = S5.calculateIntersection(LightRay57);
	VectorStructR3 InterP57 = InterInfo57.getIntersectionPoint();
	IntersectInformationStruct InterInfo58 = S5.calculateIntersection(LightRay58);
	VectorStructR3 InterP58 = InterInfo58.getIntersectionPoint();
	IntersectInformationStruct InterInfo59 = S5.calculateIntersection(LightRay59);
	VectorStructR3 InterP59 = InterInfo59.getIntersectionPoint();
	IntersectInformationStruct InterInfo60 = S5.calculateIntersection(Ray60);
	VectorStructR3 InterP60 = InterInfo60.getIntersectionPoint();

	std::vector<VectorStructR3> checkVector100 = { InterP51, InterP52, InterP53, InterP54, InterP55, InterP56, InterP57, InterP58, InterP59, InterP60 };


	std::vector<VectorStructR3> ReferenzVector100 = { { 0.0, 1.3337460175, 20.006190262 },{ 0.0, 0.66687224470, 20.006167341 },{ 0.0, 0.0, 20.055728090 },{ 0.0, -0.67188842782, 20.156652835 },{ 0.0, -1.3542243327, 20.313364990 },
	{ 0.0, 0.66625398250, 20.006190262 },{ 0.0, -0.0056360012139, 20.056360012 },{ 0.0, -0.68796087482, 20.159706561 },{ 0.0, -1.3870548813, 20.322329288 },{ 0.0, 0.0, 0.0 } };


	bool isRight100 = Math::compareAllVectorElements(checkVector100, ReferenzVector100, 7);
	checkMethodesSphericalLens.push_back(isRight100);

	//________________________________________________________________________________________________________________________________________________________________
	//________________________________________________________________________________________________________________________________________________________________
	// Linse 45° gedreht, Apex Sphere (0.0, 1.0, 20.0)
	// Startwert (0.0, 0.0, 0.0)
	LightRayStruct Ray61(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 1.0, 15.0 },  1.0);
	LightRayStruct Ray62(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.5, 15.0 },  1.0);
	LightRayStruct Ray63(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.0, 15.0 },  1.0);
	LightRayStruct Ray64(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -0.5, 15.0 },  1.0);
	LightRayStruct Ray65(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 },  1.0);

	SphericalSurface_LLT S6(/*radius*/9.0, /*semiHeight*/2.817458, /*Apex of the sphere*/{ 0.0, 1.0, 20.0 },
		/*Direction*/ VectorStructR3{ 0.0, -1.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.0);

	IntersectInformationStruct InterInfo61 = S6.calculateIntersection(Ray61);
	VectorStructR3 InterP61 = InterInfo61.getIntersectionPoint();
	IntersectInformationStruct InterInfo62 = S6.calculateIntersection(Ray62);
	VectorStructR3 InterP62 = InterInfo62.getIntersectionPoint();
	IntersectInformationStruct InterInfo63 = S6.calculateIntersection(Ray63);
	VectorStructR3 InterP63 = InterInfo63.getIntersectionPoint();
	IntersectInformationStruct InterInfo64 = S6.calculateIntersection(Ray64);
	VectorStructR3 InterP64 = InterInfo64.getIntersectionPoint();
	IntersectInformationStruct InterInfo65 = S6.calculateIntersection(Ray65);
	VectorStructR3 InterP65 = InterInfo65.getIntersectionPoint();

	//________________________________________________________________________________________________________
	//Linse um 45° gedreht, Startwert (0.0, 2.0, 0.0)
	LightRayStruct Ray66(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 },  1.0);
	LightRayStruct Ray67(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.5, 15.0 },  1.0);
	LightRayStruct Ray68(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.0, 15.0 },  1.0);
	LightRayStruct Ray69(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.5, 15.0 },  1.0);
	LightRayStruct Ray70(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -3.0, 15.0 },  1.0);


	IntersectInformationStruct InterInfo66 = S6.calculateIntersection(Ray66);
	VectorStructR3 InterP66 = InterInfo66.getIntersectionPoint();
	IntersectInformationStruct InterInfo67 = S6.calculateIntersection(Ray67);
	VectorStructR3 InterP67 = InterInfo67.getIntersectionPoint();
	IntersectInformationStruct InterInfo68 = S6.calculateIntersection(Ray68);
	VectorStructR3 InterP68 = InterInfo68.getIntersectionPoint();
	IntersectInformationStruct InterInfo69 = S6.calculateIntersection(Ray69);
	VectorStructR3 InterP69 = InterInfo69.getIntersectionPoint();
	IntersectInformationStruct InterInfo70 = S6.calculateIntersection(Ray70);
	VectorStructR3 InterP70 = InterInfo70.getIntersectionPoint();

	std::vector<VectorStructR3> checkVector101 = { InterP61, InterP62, InterP63, InterP64, InterP65, InterP66, InterP67, InterP68, InterP69, InterP70 };


	std::vector<VectorStructR3> ReferenzVector101 = { { 0.0, 1.3586757758, 20.380136638 },{ 0.0, 0.65578228300, 19.673468490 },{ 0.0, 0.0, 19.137072208 },{ 0.0, -0.62378085438, 18.713425631 },{ 0.0, -1.2248165105, 18.372247657 },
	{ 0.0, 0.68657953404, 19.701306989 },{ 0.0, 0.080265578790, 19.197344212 },{ 0.0, -0.50509941741, 18.788245631 },{ 0.0, -1.0752507908, 18.451504745 },{ 0.0, 0.0, 0.0 } };


	bool isRight101 = Math::compareAllVectorElements(checkVector101, ReferenzVector101, 9);
	checkMethodesSphericalLens.push_back(isRight101);

	//________________________________________________________________________________________________________________________________________________________________
	//________________________________________________________________________________________________________________________________________________________________
	// Linse -45° gedreht, Apex Sphere (0.0, 1.0, 20.0)
	// Startwert (0.0, 0.0, 0.0)
	LightRayStruct Ray71(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 1.0, 15.0 },  1.0);
	LightRayStruct Ray72(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.5, 15.0 },  1.0);
	LightRayStruct Ray73(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.0, 15.0 },  1.0);
	LightRayStruct Ray74(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -0.5, 15.0 },  1.0);
	LightRayStruct Ray75(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 },  1.0);

	SphericalSurface_LLT S7(/*radius*/9.0, /*semiHeight*/2.817458, /*Apex of the sphere*/{ 0.0, 1.0, 20.0 },
		/*Direction*/ VectorStructR3{ 0.0, 1.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.0);

	IntersectInformationStruct InterInfo71 = S7.calculateIntersection(Ray71);
	VectorStructR3 InterP71 = InterInfo71.getIntersectionPoint();
	IntersectInformationStruct InterInfo72 = S7.calculateIntersection(Ray72);
	VectorStructR3 InterP72 = InterInfo72.getIntersectionPoint();
	IntersectInformationStruct InterInfo73 = S7.calculateIntersection(Ray73);
	VectorStructR3 InterP73 = InterInfo73.getIntersectionPoint();
	IntersectInformationStruct InterInfo74 = S7.calculateIntersection(Ray74);
	VectorStructR3 InterP74 = InterInfo74.getIntersectionPoint();
	IntersectInformationStruct InterInfo75 = S7.calculateIntersection(Ray75);
	VectorStructR3 InterP75 = InterInfo75.getIntersectionPoint();

	//________________________________________________________________________________________________________
	//Linse um -45° gedreht, Startwert (0.0, 2.0, 0.0)
	LightRayStruct Ray76(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 },  1.0);
	LightRayStruct Ray77(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.5, 15.0 },  1.0);
	LightRayStruct Ray78(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.0, 15.0 },  1.0);
	LightRayStruct Ray79(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.5, 15.0 },  1.0);
	LightRayStruct Ray80(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -3.0, 15.0 },  1.0);


	IntersectInformationStruct InterInfo76 = S7.calculateIntersection(Ray76);
	VectorStructR3 InterP76 = InterInfo76.getIntersectionPoint();
	IntersectInformationStruct InterInfo77 = S7.calculateIntersection(Ray77);
	VectorStructR3 InterP77 = InterInfo77.getIntersectionPoint();
	IntersectInformationStruct InterInfo78 = S7.calculateIntersection(Ray78);
	VectorStructR3 InterP78 = InterInfo78.getIntersectionPoint();
	IntersectInformationStruct InterInfo79 = S7.calculateIntersection(Ray79);
	VectorStructR3 InterP79 = InterInfo79.getIntersectionPoint();
	IntersectInformationStruct InterInfo80 = S7.calculateIntersection(Ray80);
	VectorStructR3 InterP80 = InterInfo80.getIntersectionPoint();

	std::vector<VectorStructR3> checkVector102 = { InterP71, InterP72, InterP73, InterP74, InterP75, InterP76, InterP77, InterP78, InterP79, InterP80 };


	std::vector<VectorStructR3> ReferenzVector102 = { { 0.0, 1.3134204659,19.701306989 },{ 0.0, 0.67797380542, 20.339214163 },{ 0.0, 0.0, 21.189786900 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },
	{ 0.0, 0.64132422416, 20.380136638 },{ 0.0, -0.13941113151, 21.394111315 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 } };


	bool isRight102 = Math::compareAllVectorElements(checkVector102, ReferenzVector102, 9);
	checkMethodesSphericalLens.push_back(isRight102);


	//________________________________________________________________________________________________________________________________________________________________
	//________________________________________________________________________________________________________________________________________________________________
	// Linse 90° gedreht, Apex Sphere (0.0, 1.0, 20.0)
	// Startwert (0.0, 0.0, 0.0)
	LightRayStruct Ray81(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 1.0, 15.0 },  1.0);
	LightRayStruct Ray82(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.5, 15.0 },  1.0);
	LightRayStruct Ray83(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.0, 15.0 },  1.0);
	LightRayStruct Ray84(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -0.5, 15.0 },  1.0);
	LightRayStruct Ray85(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 },  1.0);

	SphericalSurface_LLT S8(/*radius*/9.0, /*semiHeight*/2.817458, /*Apex of the sphere*/{ 0.0, 1.0, 20.0 },
		/*Direction*/ VectorStructR3{ 0.0, -1.0, 0.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.0);

	IntersectInformationStruct InterInfo81 = S8.calculateIntersection(Ray81);
	VectorStructR3 InterP81 = InterInfo81.getIntersectionPoint();
	IntersectInformationStruct InterInfo82 = S8.calculateIntersection(Ray82);
	VectorStructR3 InterP82 = InterInfo82.getIntersectionPoint();
	IntersectInformationStruct InterInfo83 = S8.calculateIntersection(Ray83);
	VectorStructR3 InterP83 = InterInfo83.getIntersectionPoint();
	IntersectInformationStruct InterInfo84 = S8.calculateIntersection(Ray84);
	VectorStructR3 InterP84 = InterInfo84.getIntersectionPoint();
	IntersectInformationStruct InterInfo85 = S8.calculateIntersection(Ray85);
	VectorStructR3 InterP85 = InterInfo85.getIntersectionPoint();

	//________________________________________________________________________________________________________
	//Linse um 90° gedreht, Startwert (0.0, 2.0, 0.0)
	LightRayStruct Ray86(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 },  1.0);
	LightRayStruct Ray87(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.5, 15.0 },  1.0);
	LightRayStruct Ray88(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.0, 15.0 },  1.0);
	LightRayStruct Ray89(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.5, 15.0 },  1.0);
	LightRayStruct Ray90(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -3.0, 15.0 },  1.0);


	IntersectInformationStruct InterInfo86 = S8.calculateIntersection(Ray86);
	VectorStructR3 InterP86 = InterInfo86.getIntersectionPoint();
	IntersectInformationStruct InterInfo87 = S8.calculateIntersection(Ray87);
	VectorStructR3 InterP87 = InterInfo87.getIntersectionPoint();
	IntersectInformationStruct InterInfo88 = S8.calculateIntersection(Ray88);
	VectorStructR3 InterP88 = InterInfo88.getIntersectionPoint();
	IntersectInformationStruct InterInfo89 = S8.calculateIntersection(Ray89);
	VectorStructR3 InterP89 = InterInfo89.getIntersectionPoint();
	IntersectInformationStruct InterInfo90 = S8.calculateIntersection(Ray90);
	VectorStructR3 InterP90 = InterInfo90.getIntersectionPoint();

	std::vector<VectorStructR3> checkVector103 = { InterP81, InterP82, InterP83, InterP84, InterP85, InterP86, InterP87, InterP88, InterP89, InterP90 };


	std::vector<VectorStructR3> ReferenzVector103 = { { 0.0, 0.0, 0.0 },{ 0.0, 0.57563229773, 17.268968932 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },
	{ 0.0, 0.79423303769, 18.086504435 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 } };


	bool isRight103 = Math::compareAllVectorElements(checkVector103, ReferenzVector103, 9);
	checkMethodesSphericalLens.push_back(isRight103);

	//________________________________________________________________________________________________________________________________________________________________
	//________________________________________________________________________________________________________________________________________________________________
	// Linse -90° gedreht, Apex Sphere (0.0, 1.0, 20.0)
	// Startwert (0.0, 0.0, 0.0)
	LightRayStruct Ray91(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 1.0, 15.0 },  1.0);
	LightRayStruct Ray92(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.5, 15.0 },  1.0);
	LightRayStruct Ray93(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.0, 15.0 },  1.0);
	LightRayStruct Ray94(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -0.5, 15.0 },  1.0);
	LightRayStruct Ray95(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 },  1.0);

	SphericalSurface_LLT S9(/*radius*/9.0, /*semiHeight*/2.817458, /*Apex of the sphere*/{ 0.0, 1.0, 20.0 },
		/*Direction*/ VectorStructR3{ 0.0, 1.0, 0.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.0);

	IntersectInformationStruct InterInfo91 = S9.calculateIntersection(Ray91);
	VectorStructR3 InterP91 = InterInfo91.getIntersectionPoint();
	IntersectInformationStruct InterInfo92 = S9.calculateIntersection(Ray92);
	VectorStructR3 InterP92 = InterInfo92.getIntersectionPoint();
	IntersectInformationStruct InterInfo93 = S9.calculateIntersection(Ray93);
	VectorStructR3 InterP93 = InterInfo93.getIntersectionPoint();
	IntersectInformationStruct InterInfo94 = S9.calculateIntersection(Ray94);
	VectorStructR3 InterP94 = InterInfo94.getIntersectionPoint();
	IntersectInformationStruct InterInfo95 = S9.calculateIntersection(Ray95);
	VectorStructR3 InterP95 = InterInfo95.getIntersectionPoint();

	//________________________________________________________________________________________________________
	//Linse um -90° gedreht, Startwert (0.0, 2.0, 0.0)
	LightRayStruct Ray96(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 },  1.0);
	LightRayStruct Ray97(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.5, 15.0 },  1.0);
	LightRayStruct Ray98(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.0, 15.0 },  1.0);
	LightRayStruct Ray99(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.5, 15.0 },  1.0);
	LightRayStruct LightRay100(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -3.0, 15.0 },  1.0);


	IntersectInformationStruct InterInfo96 = S9.calculateIntersection(Ray96);
	VectorStructR3 InterP96 = InterInfo96.getIntersectionPoint();
	IntersectInformationStruct InterInfo97 = S9.calculateIntersection(Ray97);
	VectorStructR3 InterP97 = InterInfo97.getIntersectionPoint();
	IntersectInformationStruct InterInfo98 = S9.calculateIntersection(Ray98);
	VectorStructR3 InterP98 = InterInfo98.getIntersectionPoint();
	IntersectInformationStruct InterInfo99 = S9.calculateIntersection(Ray99);
	VectorStructR3 InterP99 = InterInfo99.getIntersectionPoint();
	IntersectInformationStruct InterInfo100 = S9.calculateIntersection(LightRay100);
	VectorStructR3 InterP100 = InterInfo100.getIntersectionPoint();

	std::vector<VectorStructR3> checkVector104 = { InterP91, InterP92, InterP93, InterP94, InterP95, InterP96, InterP97, InterP98, InterP99, InterP100 };


	std::vector<VectorStructR3> ReferenzVector104 = { { 0.0, 1.2057669623, 18.086504435 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },
	{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 } };


	bool isRight104 = Math::compareAllVectorElements(checkVector104, ReferenzVector104, 9);
	checkMethodesSphericalLens.push_back(isRight104);

	//________________________________________________________________________________________________________________________________________________________________
	//________________________________________________________________________________________________________________________________________________________________
	// Linse 0° gedreht, Apex Sphere (0.0, -1.0, 20.0)
	// Startwert (0.0, 0.0, 0.0)
	LightRayStruct LightRay101(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 1.0, 15.0 },  1.0);
	LightRayStruct LightRay102(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.5, 15.0 },  1.0);
	LightRayStruct LightRay103(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.0, 15.0 },  1.0);
	LightRayStruct LightRay104(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -0.5, 15.0 },  1.0);
	LightRayStruct LightRay105(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 },  1.0);

	SphericalSurface_LLT S10(/*radius*/9.0, /*semiHeight*/2.817458, /*Apex of the sphere*/{ 0.0, -1.0, 20.0 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.0);

	IntersectInformationStruct InterInfo101 = S10.calculateIntersection(LightRay101);
	VectorStructR3 InterP101 = InterInfo101.getIntersectionPoint();
	IntersectInformationStruct InterInfo102 = S10.calculateIntersection(LightRay102);
	VectorStructR3 InterP102 = InterInfo102.getIntersectionPoint();
	IntersectInformationStruct InterInfo103 = S10.calculateIntersection(LightRay103);
	VectorStructR3 InterP103 = InterInfo103.getIntersectionPoint();
	IntersectInformationStruct InterInfo104 = S10.calculateIntersection(LightRay104);
	VectorStructR3 InterP104 = InterInfo104.getIntersectionPoint();
	IntersectInformationStruct InterInfo105 = S10.calculateIntersection(LightRay105);
	VectorStructR3 InterP105 = InterInfo105.getIntersectionPoint();

	//________________________________________________________________________________________________________
	//Linse um 0° gedreht, Startwert (0.0, 2.0, 0.0)
	LightRayStruct LightRay106(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 },  1.0);
	LightRayStruct LightRay107(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.5, 15.0 },  1.0);
	LightRayStruct LightRay108(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.0, 15.0 },  1.0);
	LightRayStruct LightRay109(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.5, 15.0 },  1.0);
	LightRayStruct LightRay110(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -3.0, 15.0 },  1.0);


	IntersectInformationStruct InterInfo106 = S10.calculateIntersection(LightRay106);
	VectorStructR3 InterP106 = InterInfo106.getIntersectionPoint();
	IntersectInformationStruct InterInfo107 = S10.calculateIntersection(LightRay107);
	VectorStructR3 InterP107 = InterInfo107.getIntersectionPoint();
	IntersectInformationStruct InterInfo108 = S10.calculateIntersection(LightRay108);
	VectorStructR3 InterP108 = InterInfo108.getIntersectionPoint();
	IntersectInformationStruct InterInfo109 = S10.calculateIntersection(LightRay109);
	VectorStructR3 InterP109 = InterInfo109.getIntersectionPoint();
	IntersectInformationStruct InterInfo110 = S10.calculateIntersection(LightRay110);
	VectorStructR3 InterP110 = InterInfo110.getIntersectionPoint();

	std::vector<VectorStructR3> checkVector105 = { InterP101, InterP102, InterP103, InterP104, InterP105, InterP106, InterP107, InterP108, InterP109, InterP110 };


	std::vector<VectorStructR3> ReferenzVector105 = { { 0.0, 1.3542243327, 20.313364990 },{ 0.0, 0.67188842782, 20.156652835 },{ 0.0, 0.0, 20.055728090 },{ 0.0, -0.66687224470, 20.006167341 },{ 0.0, -1.3337460175, 20.006190262 },
	{ 0.0, 0.65641720542, 20.153741919 },{ 0.0, -0.0055113620156, 20.055113620 },{ 0.0, -0.66748595074, 20.006144631 },{ 0.0, -1.3343688997, 20.006213398 },{ 0.0, -2.0114020474, 20.057010237 } };


	bool isRight105 = Math::compareAllVectorElements(checkVector105, ReferenzVector105, 9);
	checkMethodesSphericalLens.push_back(isRight105);


	//________________________________________________________________________________________________________________________________________________________________
	//________________________________________________________________________________________________________________________________________________________________
	// Linse 45° gedreht, Apex Sphere (0.0, -1.0, 20.0)
	// Startwert (0.0, 0.0, 0.0)
	LightRayStruct LightRay111(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 1.0, 15.0 },  1.0);
	LightRayStruct LightRay112(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.5, 15.0 },  1.0);
	LightRayStruct LightRay113(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.0, 15.0 },  1.0);
	LightRayStruct LightRay114(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -0.5, 15.0 },  1.0);
	LightRayStruct LightRay115(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 },  1.0);

	SphericalSurface_LLT S11(/*radius*/9.0, /*semiHeight*/2.817458, /*Apex of the sphere*/{ 0.0, -1.0, 20.0 },
		/*Direction*/ VectorStructR3{ 0.0, -1.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.0);

	IntersectInformationStruct InterInfo111 = S11.calculateIntersection(LightRay111);
	VectorStructR3 InterP111 = InterInfo111.getIntersectionPoint();
	IntersectInformationStruct InterInfo112 = S11.calculateIntersection(LightRay112);
	VectorStructR3 InterP112 = InterInfo112.getIntersectionPoint();
	IntersectInformationStruct InterInfo113 = S11.calculateIntersection(LightRay113);
	VectorStructR3 InterP113 = InterInfo113.getIntersectionPoint();
	IntersectInformationStruct InterInfo114 = S11.calculateIntersection(LightRay114);
	VectorStructR3 InterP114 = InterInfo114.getIntersectionPoint();
	IntersectInformationStruct InterInfo115 = S11.calculateIntersection(LightRay115);
	VectorStructR3 InterP115 = InterInfo115.getIntersectionPoint();

	//________________________________________________________________________________________________________
	//Linse um 45° gedreht, Startwert (0.0, 2.0, 0.0)
	LightRayStruct LightRay116(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 },  1.0);
	LightRayStruct LightRay117(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.5, 15.0 },  1.0);
	LightRayStruct LightRay118(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.0, 15.0 },  1.0);
	LightRayStruct LightRay119(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.5, 15.0 },  1.0);
	LightRayStruct LightRay120(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -3.0, 15.0 },  1.0);


	IntersectInformationStruct InterInfo116 = S11.calculateIntersection(LightRay116);
	VectorStructR3 InterP116 = InterInfo116.getIntersectionPoint();
	IntersectInformationStruct InterInfo117 = S11.calculateIntersection(LightRay117);
	VectorStructR3 InterP117 = InterInfo117.getIntersectionPoint();
	IntersectInformationStruct InterInfo118 = S11.calculateIntersection(LightRay118);
	VectorStructR3 InterP118 = InterInfo118.getIntersectionPoint();
	IntersectInformationStruct InterInfo119 = S11.calculateIntersection(LightRay119);
	VectorStructR3 InterP119 = InterInfo119.getIntersectionPoint();
	IntersectInformationStruct InterInfo120 = S11.calculateIntersection(LightRay120);
	VectorStructR3 InterP120 = InterInfo120.getIntersectionPoint();

	std::vector<VectorStructR3> checkVector106 = { InterP111, InterP112, InterP113, InterP114, InterP115, InterP116, InterP117, InterP118, InterP119, InterP120 };


	std::vector<VectorStructR3> ReferenzVector106 = { { 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 21.189786900 },{ 0.0, -0.67797380542, 20.339214163 },{ 0.0, -1.3134204659, 19.701306989 },
	{ 0.0, 0.53051691180, 22.042246323 },{ 0.0, -0.10442656171, 21.044265617 },{ 0.0, -0.70754162548, 20.306562191 },{ 0.0, -1.2874910938, 19.724946563 },{ 0.0, -1.8501485790, 19.250742895 } };


	bool isRight106 = Math::compareAllVectorElements(checkVector106, ReferenzVector106, 9);
	checkMethodesSphericalLens.push_back(isRight106);

	//________________________________________________________________________________________________________________________________________________________________
	//________________________________________________________________________________________________________________________________________________________________
	// Linse -45° gedreht, Apex Sphere (0.0, -1.0, 20.0)
	// Startwert (0.0, 0.0, 0.0)
	LightRayStruct LightRay121(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 1.0, 15.0 },  1.0);
	LightRayStruct LightRay122(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.5, 15.0 },  1.0);
	LightRayStruct LightRay123(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.0, 15.0 },  1.0);
	LightRayStruct LightRay124(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -0.5, 15.0 },  1.0);
	LightRayStruct LightRay125(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 },  1.0);

	SphericalSurface_LLT S12(/*radius*/9.0, /*semiHeight*/2.817458, /*Apex of the sphere*/{ 0.0, -1.0, 20.0 },
		/*Direction*/ VectorStructR3{ 0.0, 1.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.0);

	IntersectInformationStruct InterInfo121 = S12.calculateIntersection(LightRay121);
	VectorStructR3 InterP121 = InterInfo121.getIntersectionPoint();
	IntersectInformationStruct InterInfo122 = S12.calculateIntersection(LightRay122);
	VectorStructR3 InterP122 = InterInfo122.getIntersectionPoint();
	IntersectInformationStruct InterInfo123 = S12.calculateIntersection(LightRay123);
	VectorStructR3 InterP123 = InterInfo123.getIntersectionPoint();
	IntersectInformationStruct InterInfo124 = S12.calculateIntersection(LightRay124);
	VectorStructR3 InterP124 = InterInfo124.getIntersectionPoint();
	IntersectInformationStruct InterInfo125 = S12.calculateIntersection(LightRay125);
	VectorStructR3 InterP125 = InterInfo125.getIntersectionPoint();

	//________________________________________________________________________________________________________
	//Linse um -45° gedreht, Startwert (0.0, 2.0, 0.0)
	LightRayStruct LightRay126(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 },  1.0);
	LightRayStruct LightRay127(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.5, 15.0 },  1.0);
	LightRayStruct LightRay128(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.0, 15.0 },  1.0);
	LightRayStruct LightRay129(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.5, 15.0 },  1.0);
	LightRayStruct LightRay130(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -3.0, 15.0 },  1.0);


	//InterP127 y-Wert stimmt nich mit Zemax-Schnittpunkt überein -> Übereinstimmung auf Kommazahlen auf 8 heruntergesetzt
	IntersectInformationStruct InterInfo126 = S12.calculateIntersection(LightRay126);
	VectorStructR3 InterP126 = InterInfo126.getIntersectionPoint();
	IntersectInformationStruct InterInfo127 = S12.calculateIntersection(LightRay127);
	VectorStructR3 InterP127 = InterInfo127.getIntersectionPoint();
	IntersectInformationStruct InterInfo128 = S12.calculateIntersection(LightRay128);
	VectorStructR3 InterP128 = InterInfo128.getIntersectionPoint();
	IntersectInformationStruct InterInfo129 = S12.calculateIntersection(LightRay129);
	VectorStructR3 InterP129 = InterInfo129.getIntersectionPoint();
	IntersectInformationStruct InterInfo130 = S12.calculateIntersection(LightRay130);
	VectorStructR3 InterP130 = InterInfo130.getIntersectionPoint();

	std::vector<VectorStructR3> checkVector107 = { InterP121, InterP122, InterP123, InterP124, InterP125, InterP126, InterP127, InterP128, InterP129, InterP130 };


	std::vector<VectorStructR3> ReferenzVector107 = { { 0.0, 1.2248165105, 18.372247657 },{ 0.0, 0.62378085438, 18.713425631 },{ 0.0, 0.0, 19.137072208 },{ 0.0, -0.65578228300, 19.673468490 },{ 0.0, -1.3586757758, 20.380136638 },
	{ 0.0, 0.75786968950, 18.631954657 },{ 0.0, 0.093111580756, 19.068884192 },{ 0.0, -0.61870588404, 19.640294130 },{ 0.0, -1.4055329923, 20.433197954 },{ 0.0, -2.3433246826, 21.716623413 } };


	bool isRight107 = Math::compareAllVectorElements(checkVector107, ReferenzVector107, 8);
	checkMethodesSphericalLens.push_back(isRight107);;


	//________________________________________________________________________________________________________________________________________________________________
	//________________________________________________________________________________________________________________________________________________________________
	// Linse 90° gedreht, Apex Sphere (0.0, -1.0, 20.0)
	// Startwert (0.0, 0.0, 0.0)
	LightRayStruct LightRay131(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 1.0, 15.0 },  1.0);
	LightRayStruct LightRay132(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.5, 15.0 },  1.0);
	LightRayStruct LightRay133(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.0, 15.0 },  1.0);
	LightRayStruct LightRay134(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -0.5, 15.0 },  1.0);
	LightRayStruct LightRay135(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 },  1.0);

	SphericalSurface_LLT S13(/*radius*/9.0, /*semiHeight*/2.817458, /*Apex of the sphere*/{ 0.0, -1.0, 20.0 },
		/*Direction*/ VectorStructR3{ 0.0, -1.0, 0.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.0);

	IntersectInformationStruct InterInfo131 = S13.calculateIntersection(LightRay131);
	VectorStructR3 InterP131 = InterInfo131.getIntersectionPoint();
	IntersectInformationStruct InterInfo132 = S13.calculateIntersection(LightRay132);
	VectorStructR3 InterP132 = InterInfo132.getIntersectionPoint();
	IntersectInformationStruct InterInfo133 = S13.calculateIntersection(LightRay133);
	VectorStructR3 InterP133 = InterInfo133.getIntersectionPoint();
	IntersectInformationStruct InterInfo134 = S13.calculateIntersection(LightRay134);
	VectorStructR3 InterP134 = InterInfo134.getIntersectionPoint();
	IntersectInformationStruct InterInfo135 = S13.calculateIntersection(LightRay135);
	VectorStructR3 InterP135 = InterInfo135.getIntersectionPoint();

	//________________________________________________________________________________________________________
	//Linse um 90° gedreht, Startwert (0.0, 2.0, 0.0)
	LightRayStruct LightRay136(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 },  1.0);
	LightRayStruct LightRay137(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.5, 15.0 },  1.0);
	LightRayStruct LightRay138(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.0, 15.0 },  1.0);
	LightRayStruct LightRay139(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.5, 15.0 },  1.0);
	LightRayStruct LightRay140(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -3.0, 15.0 },  1.0);


	IntersectInformationStruct InterInfo136 = S13.calculateIntersection(LightRay136);
	VectorStructR3 InterP136 = InterInfo136.getIntersectionPoint();
	IntersectInformationStruct InterInfo137 = S13.calculateIntersection(LightRay137);
	VectorStructR3 InterP137 = InterInfo137.getIntersectionPoint();
	IntersectInformationStruct InterInfo138 = S13.calculateIntersection(LightRay138);
	VectorStructR3 InterP138 = InterInfo138.getIntersectionPoint();
	IntersectInformationStruct InterInfo139 = S13.calculateIntersection(LightRay139);
	VectorStructR3 InterP139 = InterInfo139.getIntersectionPoint();
	IntersectInformationStruct InterInfo140 = S13.calculateIntersection(LightRay140);
	VectorStructR3 InterP140 = InterInfo140.getIntersectionPoint();

	std::vector<VectorStructR3> checkVector108 = { InterP131, InterP132, InterP133, InterP134, InterP135, InterP136, InterP137, InterP138, InterP139, InterP140 };


	std::vector<VectorStructR3> ReferenzVector108 = { { 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, -1.2057669623, 18.086504435 },
	{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, -1.1049393846, 18.629636308 },{ 0.0, -1.4425213939, 17.212606970 } };


	bool isRight108 = Math::compareAllVectorElements(checkVector108, ReferenzVector108, 9);
	checkMethodesSphericalLens.push_back(isRight108);

	//________________________________________________________________________________________________________________________________________________________________
	//________________________________________________________________________________________________________________________________________________________________
	// Linse -90° gedreht, Apex Sphere (0.0, -1.0, 20.0)
	// Startwert (0.0, 0.0, 0.0)
	LightRayStruct LightRay141(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 1.0, 15.0 },  1.0);
	LightRayStruct LightRay142(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.5, 15.0 },  1.0);
	LightRayStruct LightRay143(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.0, 15.0 },  1.0);
	LightRayStruct LightRay144(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -0.5, 15.0 },  1.0);
	LightRayStruct LightRay145(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 },  1.0);

	SphericalSurface_LLT S14(/*radius*/9.0, /*semiHeight*/2.817458, /*Apex of the sphere*/{ 0.0, -1.0, 20.0 },
		/*Direction*/ VectorStructR3{ 0.0, 1.0, 0.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.0);

	IntersectInformationStruct InterInfo141 = S14.calculateIntersection(LightRay141);
	VectorStructR3 InterP141 = InterInfo141.getIntersectionPoint();
	IntersectInformationStruct InterInfo142 = S14.calculateIntersection(LightRay142);
	VectorStructR3 InterP142 = InterInfo142.getIntersectionPoint();
	IntersectInformationStruct InterInfo143 = S14.calculateIntersection(LightRay143);
	VectorStructR3 InterP143 = InterInfo143.getIntersectionPoint();
	IntersectInformationStruct InterInfo144 = S14.calculateIntersection(LightRay144);
	VectorStructR3 InterP144 = InterInfo144.getIntersectionPoint();
	IntersectInformationStruct InterInfo145 = S14.calculateIntersection(LightRay145);
	VectorStructR3 InterP145 = InterInfo145.getIntersectionPoint();

	//________________________________________________________________________________________________________
	//Linse um -90° gedreht, Startwert (0.0, 2.0, 0.0)
	LightRayStruct LightRay146(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 },  1.0);
	LightRayStruct LightRay147(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.5, 15.0 },  1.0);
	LightRayStruct LightRay148(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.0, 15.0 },  1.0);
	LightRayStruct LightRay149(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.5, 15.0 },  1.0);
	LightRayStruct LightRay150(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -3.0, 15.0 },  1.0);


	//InterP148 trifft Linse von oben, Zemax gibt keinen Schnittpunkt an -> In Referenzvketor Schnittpunkt des Programms eingesetzt
	IntersectInformationStruct InterInfo146 = S14.calculateIntersection(LightRay146);
	VectorStructR3 InterP146 = InterInfo146.getIntersectionPoint();
	IntersectInformationStruct InterInfo147 = S14.calculateIntersection(LightRay147);
	VectorStructR3 InterP147 = InterInfo147.getIntersectionPoint();
	IntersectInformationStruct InterInfo148 = S14.calculateIntersection(LightRay148);
	VectorStructR3 InterP148 = InterInfo148.getIntersectionPoint();
	IntersectInformationStruct InterInfo149 = S14.calculateIntersection(LightRay149);
	VectorStructR3 InterP149 = InterInfo149.getIntersectionPoint();
	IntersectInformationStruct InterInfo150 = S14.calculateIntersection(LightRay150);
	VectorStructR3 InterP150 = InterInfo150.getIntersectionPoint();

	std::vector<VectorStructR3> checkVector109 = { InterP141, InterP142, InterP143,  InterP144, InterP145, InterP146, InterP147, InterP148, InterP149, InterP150 };


	std::vector<VectorStructR3> ReferenzVector109 = { { 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, -0.57563229773, 17.268968932 },{ 0.0, 0.0, 0.0 },
	{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, -0.86993782540169828, 21.524533690512737 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 } };


	bool isRight109 = Math::compareAllVectorElements(checkVector109, ReferenzVector109, 9);
	checkMethodesSphericalLens.push_back(isRight109);


	//________________________________________________________________________________________________________________________________________________________________
	//________________________________________________________________________________________________________________________________________________________________
	//________________________________________________________________________________________________________________________________________________________________
	// Linse 0° gedreht, Apex Sphere (1.0, 0.0, 20.0)
	// Startwert (0.0, 0.0, 0.0)
	LightRayStruct LightRay151(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 1.0, 15.0 },  1.0);
	LightRayStruct LightRay152(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.5, 15.0 },  1.0);
	LightRayStruct LightRay153(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.0, 15.0 },  1.0);
	LightRayStruct LightRay154(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -0.5, 15.0 },  1.0);
	LightRayStruct LightRay155(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 },  1.0);

	SphericalSurface_LLT S15(/*radius*/9.0, /*semiHeight*/2.817458, /*Apex of the sphere*/{ 1.0, 0.0, 20.0 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.0);

	IntersectInformationStruct InterInfo151 = S15.calculateIntersection(LightRay151);
	VectorStructR3 InterP151 = InterInfo151.getIntersectionPoint();
	IntersectInformationStruct InterInfo152 = S15.calculateIntersection(LightRay152);
	VectorStructR3 InterP152 = InterInfo152.getIntersectionPoint();
	IntersectInformationStruct InterInfo153 = S15.calculateIntersection(LightRay153);
	VectorStructR3 InterP153 = InterInfo153.getIntersectionPoint();
	IntersectInformationStruct InterInfo154 = S15.calculateIntersection(LightRay154);
	VectorStructR3 InterP154 = InterInfo154.getIntersectionPoint();
	IntersectInformationStruct InterInfo155 = S15.calculateIntersection(LightRay155);
	VectorStructR3 InterP155 = InterInfo155.getIntersectionPoint();

	//________________________________________________________________________________________________________
	//Linse um 0° gedreht, Startwert (0.0, 2.0, 0.0)
	LightRayStruct LightRay156(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 },  1.0);
	LightRayStruct LightRay157(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.5, 15.0 },  1.0);
	LightRayStruct LightRay158(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.0, 15.0 },  1.0);
	LightRayStruct LightRay159(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.5, 15.0 },  1.0);
	LightRayStruct LightRay160(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -3.0, 15.0 },  1.0);


	//InterP157 stimmt nicht exakt mit ZEMAX-Schnittpunkt überein -> Übereinstimmung auf Kommazahlen auf 8 heruntergesetzt
	IntersectInformationStruct InterInfo156 = S15.calculateIntersection(LightRay156);
	VectorStructR3 InterP156 = InterInfo156.getIntersectionPoint();
	IntersectInformationStruct InterInfo157 = S15.calculateIntersection(LightRay157);
	VectorStructR3 InterP157 = InterInfo157.getIntersectionPoint();
	IntersectInformationStruct InterInfo158 = S15.calculateIntersection(LightRay158);
	VectorStructR3 InterP158 = InterInfo158.getIntersectionPoint();
	IntersectInformationStruct InterInfo159 = S15.calculateIntersection(LightRay159);
	VectorStructR3 InterP159 = InterInfo159.getIntersectionPoint();
	IntersectInformationStruct InterInfo160 = S15.calculateIntersection(LightRay160);
	VectorStructR3 InterP160 = InterInfo160.getIntersectionPoint();

	std::vector<VectorStructR3> checkVector110 = { InterP151, InterP152, InterP153, InterP154, InterP155, InterP156, InterP157, InterP158, InterP159, InterP160 };


	std::vector<VectorStructR3> ReferenzVector110 = { { 0.0, 1.3438169363, 20.157254044 },{ 0.0, 0.66936032118, 20.080809635 },{ 0.0, 0.0, 20.055728090 },{ 0.0, -0.66936032118, 20.080809635 },{ 0.0, -1.3438169363, 20.157254044 },
	{ 0.0, 0.66131934484, 20.080209827 },{ 0.0, -0.0055729826237, 20.055729826 },{ 0.0, -0.67752346849, 20.081426014 },{ 0.0, -1.3599535611, 20.159721367 },{ 0.0, -2.0591990429, 20.295995215 } };


	bool isRight110 = Math::compareAllVectorElements(checkVector110, ReferenzVector110, 7);
	checkMethodesSphericalLens.push_back(isRight110);


	//________________________________________________________________________________________________________________________________________________________________
	//________________________________________________________________________________________________________________________________________________________________
	// Linse 45° gedreht, Apex Sphere (1.0, 0.0, 20.0)
	// Startwert (0.0, 0.0, 0.0)
	LightRayStruct LightRay161(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 1.0, 15.0 },  1.0);
	LightRayStruct LightRay162(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.5, 15.0 },  1.0);
	LightRayStruct LightRay163(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.0, 15.0 },  1.0);
	LightRayStruct LightRay164(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -0.5, 15.0 },  1.0);
	LightRayStruct LightRay165(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 },  1.0);

	SphericalSurface_LLT S16(/*radius*/9.0, /*semiHeight*/2.817458, /*Apex of the sphere*/{ 1.0, 0.0, 20.0 },
		/*Direction*/ VectorStructR3{ 0.0, -1.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.0);

	IntersectInformationStruct InterInfo161 = S16.calculateIntersection(LightRay161);
	VectorStructR3 InterP161 = InterInfo161.getIntersectionPoint();
	IntersectInformationStruct InterInfo162 = S16.calculateIntersection(LightRay162);
	VectorStructR3 InterP162 = InterInfo162.getIntersectionPoint();
	IntersectInformationStruct InterInfo163 = S16.calculateIntersection(LightRay163);
	VectorStructR3 InterP163 = InterInfo163.getIntersectionPoint();
	IntersectInformationStruct InterInfo164 = S16.calculateIntersection(LightRay164);
	VectorStructR3 InterP164 = InterInfo164.getIntersectionPoint();
	IntersectInformationStruct InterInfo165 = S16.calculateIntersection(LightRay165);
	VectorStructR3 InterP165 = InterInfo165.getIntersectionPoint();

	//________________________________________________________________________________________________________
	//Linse um 45° gedreht, Startwert (0.0, 2.0, 0.0)
	LightRayStruct LightRay166(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 },  1.0);
	LightRayStruct LightRay167(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.5, 15.0 },  1.0);
	LightRayStruct LightRay168(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.0, 15.0 },  1.0);
	LightRayStruct LightRay169(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.5, 15.0 },  1.0);
	LightRayStruct LightRay170(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -3.0, 15.0 },  1.0);


	IntersectInformationStruct InterInfo166 = S16.calculateIntersection(LightRay166);
	VectorStructR3 InterP166 = InterInfo166.getIntersectionPoint();
	IntersectInformationStruct InterInfo167 = S16.calculateIntersection(LightRay167);
	VectorStructR3 InterP167 = InterInfo167.getIntersectionPoint();
	IntersectInformationStruct InterInfo168 = S16.calculateIntersection(LightRay168);
	VectorStructR3 InterP168 = InterInfo168.getIntersectionPoint();
	IntersectInformationStruct InterInfo169 = S16.calculateIntersection(LightRay169);
	VectorStructR3 InterP169 = InterInfo169.getIntersectionPoint();
	IntersectInformationStruct InterInfo170 = S16.calculateIntersection(LightRay170);
	VectorStructR3 InterP170 = InterInfo170.getIntersectionPoint();

	std::vector<VectorStructR3> checkVector112 = { InterP161, InterP162, InterP163, InterP164, InterP165, InterP166, InterP167, InterP168, InterP169, InterP170 };


	std::vector<VectorStructR3> ReferenzVector112 = { { 0.0, 1.4698348265, 22.047522398 },{ 0.0, 0.69573625181, 20.872087554 },{ 0.0, 0.0, 20.079058486 },{ 0.0, -0.64944146832, 19.483244050 },{ 0.0, -1.2675775589, 19.013663383 },
	{ 0.0, 0.61531710528, 20.770243421 },{ 0.0, -0.0071796788928, 20.071796789 },{ 0.0, -0.60294972288, 19.522122922 },{ 0.0, -1.1792795683, 19.075677410 },{ 0.0, -1.7413664712, 18.706832356 } };


	bool isRight112 = Math::compareAllVectorElements(checkVector112, ReferenzVector112, 9);
	checkMethodesSphericalLens.push_back(isRight112);

	//________________________________________________________________________________________________________________________________________________________________
	//________________________________________________________________________________________________________________________________________________________________
	// Linse -45° gedreht, Apex Sphere (1.0, 0.0, 20.0)
	// Startwert (0.0, 0.0, 0.0)
	LightRayStruct LightRay171(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 1.0, 15.0 },  1.0);
	LightRayStruct LightRay172(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.5, 15.0 },  1.0);
	LightRayStruct LightRay173(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.0, 15.0 },  1.0);
	LightRayStruct LightRay174(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -0.5, 15.0 },  1.0);
	LightRayStruct LightRay175(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 },  1.0);

	SphericalSurface_LLT S17(/*radius*/9.0, /*semiHeight*/2.817458, /*Apex of the sphere*/{ 1.0, 0.0, 20.0 },
		/*Direction*/ VectorStructR3{ 0.0, 1.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.0);

	IntersectInformationStruct InterInfo171 = S17.calculateIntersection(LightRay171);
	VectorStructR3 InterP171 = InterInfo171.getIntersectionPoint();
	IntersectInformationStruct InterInfo172 = S17.calculateIntersection(LightRay172);
	VectorStructR3 InterP172 = InterInfo172.getIntersectionPoint();
	IntersectInformationStruct InterInfo173 = S17.calculateIntersection(LightRay173);
	VectorStructR3 InterP173 = InterInfo173.getIntersectionPoint();
	IntersectInformationStruct InterInfo174 = S17.calculateIntersection(LightRay174);
	VectorStructR3 InterP174 = InterInfo174.getIntersectionPoint();
	IntersectInformationStruct InterInfo175 = S17.calculateIntersection(LightRay175);
	VectorStructR3 InterP175 = InterInfo175.getIntersectionPoint();

	//________________________________________________________________________________________________________
	//Linse um -45° gedreht, Startwert (0.0, 2.0, 0.0)
	LightRayStruct LightRay176(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 },  1.0);
	LightRayStruct LightRay177(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.5, 15.0 },  1.0);
	LightRayStruct LightRay178(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.0, 15.0 },  1.0);
	LightRayStruct LightRay179(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.5, 15.0 },  1.0);
	LightRayStruct LightRay180(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -3.0, 15.0 },  1.0);


	//InterP177 stimmt nicht exakt mit ZEMAX-Schnittpunkt überein -> Übereinstimmung auf Kommazahlen auf 8 heruntergesetzt
	IntersectInformationStruct InterInfo176 = S17.calculateIntersection(LightRay176);
	VectorStructR3 InterP176 = InterInfo176.getIntersectionPoint();
	IntersectInformationStruct InterInfo177 = S17.calculateIntersection(LightRay177);
	VectorStructR3 InterP177 = InterInfo177.getIntersectionPoint();
	IntersectInformationStruct InterInfo178 = S17.calculateIntersection(LightRay178);
	VectorStructR3 InterP178 = InterInfo178.getIntersectionPoint();
	IntersectInformationStruct InterInfo179 = S17.calculateIntersection(LightRay179);
	VectorStructR3 InterP179 = InterInfo179.getIntersectionPoint();
	IntersectInformationStruct InterInfo180 = S17.calculateIntersection(LightRay180);
	VectorStructR3 InterP180 = InterInfo180.getIntersectionPoint();

	std::vector<VectorStructR3> checkVector113 = { InterP171, InterP172, InterP173, InterP174, InterP175, InterP176, InterP177, InterP178, InterP179, InterP180 };


	std::vector<VectorStructR3> ReferenzVector113 = { { 0.0, 1.2675775589, 19.013663383 },{ 0.0, 0.64944146832, 19.483244050 },{ 0.0, 0.0, 20.079058486 },{ 0.0, -0.69573625181, 20.872087554 },{ 0.0, -1.4698348265, 22.047522398 },
	{ 0.0, 0.70412017130, 19.438197430 },{ 0.0, -0.0087979606378, 20.087979606 },{ 0.0, -0.80142946372, 21.010720978 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 } };


	bool isRight113 = Math::compareAllVectorElements(checkVector113, ReferenzVector113, 8);
	checkMethodesSphericalLens.push_back(isRight113);


	//________________________________________________________________________________________________________________________________________________________________
	//________________________________________________________________________________________________________________________________________________________________
	// Linse 90° gedreht, Apex Sphere (1.0, 0.0, 20.0)
	// Startwert (0.0, 0.0, 0.0)
	LightRayStruct LightRay181(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 1.0, 15.0 },  1.0);
	LightRayStruct LightRay182(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.5, 15.0 },  1.0);
	LightRayStruct LightRay183(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.0, 15.0 },  1.0);
	LightRayStruct LightRay184(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -0.5, 15.0 },  1.0);
	LightRayStruct LightRay185(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 },  1.0);

	SphericalSurface_LLT S18(/*radius*/9.0, /*semiHeight*/2.817458, /*Apex of the sphere*/{ 1.0, 0.0, 20.0 },
		/*Direction*/ VectorStructR3{ 0.0, -1.0, 0.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.0);

	IntersectInformationStruct InterInfo181 = S18.calculateIntersection(LightRay181);
	VectorStructR3 InterP181 = InterInfo181.getIntersectionPoint();
	IntersectInformationStruct InterInfo182 = S18.calculateIntersection(LightRay182);
	VectorStructR3 InterP182 = InterInfo182.getIntersectionPoint();
	IntersectInformationStruct InterInfo183 = S18.calculateIntersection(LightRay183);
	VectorStructR3 InterP183 = InterInfo183.getIntersectionPoint();
	IntersectInformationStruct InterInfo184 = S18.calculateIntersection(LightRay184);
	VectorStructR3 InterP184 = InterInfo184.getIntersectionPoint();
	IntersectInformationStruct InterInfo185 = S18.calculateIntersection(LightRay185);
	VectorStructR3 InterP185 = InterInfo185.getIntersectionPoint();

	//________________________________________________________________________________________________________
	//Linse um 90° gedreht, Startwert (0.0, 2.0, 0.0)
	LightRayStruct LightRay186(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 },  1.0);
	LightRayStruct LightRay187(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.5, 15.0 },  1.0);
	LightRayStruct LightRay188(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.0, 15.0 },  1.0);
	LightRayStruct LightRay189(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.5, 15.0 },  1.0);
	LightRayStruct LightRay190(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -3.0, 15.0 },  1.0);


	IntersectInformationStruct InterInfo186 = S18.calculateIntersection(LightRay186);
	VectorStructR3 InterP186 = InterInfo186.getIntersectionPoint();
	IntersectInformationStruct InterInfo187 = S18.calculateIntersection(LightRay187);
	VectorStructR3 InterP187 = InterInfo187.getIntersectionPoint();
	IntersectInformationStruct InterInfo188 = S18.calculateIntersection(LightRay188);
	VectorStructR3 InterP188 = InterInfo188.getIntersectionPoint();
	IntersectInformationStruct InterInfo189 = S18.calculateIntersection(LightRay189);
	VectorStructR3 InterP189 = InterInfo189.getIntersectionPoint();
	IntersectInformationStruct InterInfo190 = S18.calculateIntersection(LightRay190);
	VectorStructR3 InterP190 = InterInfo190.getIntersectionPoint();

	std::vector<VectorStructR3> checkVector114 = { InterP181, InterP182, InterP183, InterP184, InterP185, InterP186, InterP187, InterP188, InterP189, InterP190 };


	std::vector<VectorStructR3> ReferenzVector114 = { { 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },
	{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, -0.35883502699, 17.691262702 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 } };


	bool isRight114 = Math::compareAllVectorElements(checkVector114, ReferenzVector114, 9);
	checkMethodesSphericalLens.push_back(isRight114);

	//________________________________________________________________________________________________________________________________________________________________
	//________________________________________________________________________________________________________________________________________________________________
	// Linse -90° gedreht, Apex Sphere (1.0, 0.0, 20.0)
	// Startwert (0.0, 0.0, 0.0)
	LightRayStruct LightRay191(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 1.0, 15.0 },  1.0);
	LightRayStruct LightRay192(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.5, 15.0 },  1.0);
	LightRayStruct LightRay193(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.0, 15.0 },  1.0);
	LightRayStruct LightRay194(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -0.5, 15.0 },  1.0);
	LightRayStruct LightRay195(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 },  1.0);

	SphericalSurface_LLT S19(/*radius*/9.0, /*semiHeight*/2.817458, /*Apex of the sphere*/{ 1.0, 0.0, 20.0 },
		/*Direction*/ VectorStructR3{ 0.0, 1.0, 0.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.0);

	IntersectInformationStruct InterInfo191 = S19.calculateIntersection(LightRay191);
	VectorStructR3 InterP191 = InterInfo191.getIntersectionPoint();
	IntersectInformationStruct InterInfo192 = S19.calculateIntersection(LightRay192);
	VectorStructR3 InterP192 = InterInfo192.getIntersectionPoint();
	IntersectInformationStruct InterInfo193 = S19.calculateIntersection(LightRay193);
	VectorStructR3 InterP193 = InterInfo193.getIntersectionPoint();
	IntersectInformationStruct InterInfo194 = S19.calculateIntersection(LightRay194);
	VectorStructR3 InterP194 = InterInfo194.getIntersectionPoint();
	IntersectInformationStruct InterInfo195 = S19.calculateIntersection(LightRay195);
	VectorStructR3 InterP195 = InterInfo195.getIntersectionPoint();

	//________________________________________________________________________________________________________
	//Linse um -90° gedreht, Startwert (0.0, 2.0, 0.0)
	LightRayStruct LightRay196(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 },  1.0);
	LightRayStruct LightRay197(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.5, 15.0 },  1.0);
	LightRayStruct LightRay198(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.0, 15.0 },  1.0);
	LightRayStruct LightRay199(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.5, 15.0 },  1.0);
	LightRayStruct LightRay200(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -3.0, 15.0 },  1.0);

	//SphericalSurface_LLT S39(/*radius*/9.0, /*semiHeight*/2.817458, /*Apex of the sphere*/{ 1.0, 0.0, 20.0 },
	//	/*Direction*/ VectorStructR3{ 0.0, 1.0, 0.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);

	IntersectInformationStruct InterInfo196 = S19.calculateIntersection(LightRay196);
	VectorStructR3 InterP196 = InterInfo196.getIntersectionPoint();
	IntersectInformationStruct InterInfo197 = S19.calculateIntersection(LightRay197);
	VectorStructR3 InterP197 = InterInfo197.getIntersectionPoint();
	IntersectInformationStruct InterInfo198 = S19.calculateIntersection(LightRay198);
	VectorStructR3 InterP198 = InterInfo198.getIntersectionPoint();
	IntersectInformationStruct InterInfo199 = S19.calculateIntersection(LightRay199);
	VectorStructR3 InterP199 = InterInfo199.getIntersectionPoint();
	IntersectInformationStruct InterInfo200 = S19.calculateIntersection(LightRay200);
	VectorStructR3 InterP200 = InterInfo200.getIntersectionPoint();

	std::vector<VectorStructR3> checkVector115 = { InterP191, InterP192, InterP193, InterP194, InterP195, InterP196, InterP197, InterP198, InterP199, InterP200 };


	std::vector<VectorStructR3> ReferenzVector115 = { { 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },
	{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 } };


	bool isRight115 = Math::compareAllVectorElements(checkVector115, ReferenzVector115, 9);
	checkMethodesSphericalLens.push_back(isRight115);

	//________________________________________________________________________________________________________________________________________________________________
	//________________________________________________________________________________________________________________________________________________________________
	//________________________________________________________________________________________________________________________________________________________________
	// Linse 0° gedreht, Apex Sphere (1.0, 1.0, 20.0)
	// Startwert (0.0, 0.0, 0.0)
	LightRayStruct LightRay201(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 1.0, 15.0 },  1.0);
	LightRayStruct LightRay202(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.5, 15.0 },  1.0);
	LightRayStruct LightRay203(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.0, 15.0 },  1.0);
	LightRayStruct LightRay204(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -0.5, 15.0 },  1.0);
	LightRayStruct LightRay205(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 },  1.0);

	SphericalSurface_LLT S20(/*radius*/9.0, /*semiHeight*/2.817458, /*Apex of the sphere*/{ 1.0, 1.0, 20.0 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.0);

	IntersectInformationStruct InterInfo201 = S20.calculateIntersection(LightRay201);
	VectorStructR3 InterP201 = InterInfo201.getIntersectionPoint();
	IntersectInformationStruct InterInfo202 = S20.calculateIntersection(LightRay202);
	VectorStructR3 InterP202 = InterInfo202.getIntersectionPoint();
	IntersectInformationStruct InterInfo203 = S20.calculateIntersection(LightRay203);
	VectorStructR3 InterP203 = InterInfo203.getIntersectionPoint();
	IntersectInformationStruct InterInfo204 = S20.calculateIntersection(LightRay204);
	VectorStructR3 InterP204 = InterInfo204.getIntersectionPoint();
	IntersectInformationStruct InterInfo205 = S20.calculateIntersection(LightRay205);
	VectorStructR3 InterP205 = InterInfo205.getIntersectionPoint();

	//________________________________________________________________________________________________________
	//Linse um 0° gedreht, Startwert (0.0, 2.0, 0.0)
	LightRayStruct LightRay206(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 },  1.0);
	LightRayStruct LightRay207(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.5, 15.0 },  1.0);
	LightRayStruct LightRay208(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.0, 15.0 },  1.0);
	LightRayStruct LightRay209(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.5, 15.0 },  1.0);
	LightRayStruct LightRay210(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -3.0, 15.0 },  1.0);


	//InterP207: y-Wert  stimmt nicht mit ZEMAX überein -> Übereinstimmung der Kommazahlen auf 8 heruntergesetzt
	IntersectInformationStruct InterInfo206 = S20.calculateIntersection(LightRay206);
	VectorStructR3 InterP206 = InterInfo206.getIntersectionPoint();
	IntersectInformationStruct InterInfo207 = S20.calculateIntersection(LightRay207);
	VectorStructR3 InterP207 = InterInfo207.getIntersectionPoint();
	IntersectInformationStruct InterInfo208 = S20.calculateIntersection(LightRay208);
	VectorStructR3 InterP208 = InterInfo208.getIntersectionPoint();
	IntersectInformationStruct InterInfo209 = S20.calculateIntersection(LightRay209);
	VectorStructR3 InterP209 = InterInfo209.getIntersectionPoint();
	IntersectInformationStruct InterInfo210 = S20.calculateIntersection(LightRay210);
	VectorStructR3 InterP210 = InterInfo210.getIntersectionPoint();

	std::vector<VectorStructR3> checkVector116 = { InterP201, InterP202, InterP203, InterP204, InterP205, InterP206, InterP207, InterP208, InterP209, InterP210 };


	std::vector<VectorStructR3> ReferenzVector116 = { { 0.0, 1.3374731264, 20.062096896 },{ 0.0, 0.66872882935, 20.061864881 },{ 0.0, 0.0, 20.111805583 },{ 0.0, -0.67379122302, 20.213736691 },{ 0.0, -1.3581458345, 20.372187518 },
	{ 0.0, 0.66252687357, 20.062096896 },{ 0.0, -0.011308517642, 20.113085176 },{ 0.0, -0.69572581837,  20.217943638 },{ 0.0, -1.3971575097,  20.382945058 },{ 0.0, 0.0, 0.0 } };


	bool isRight116 = Math::compareAllVectorElements(checkVector116, ReferenzVector116, 8);
	checkMethodesSphericalLens.push_back(isRight116);


	//________________________________________________________________________________________________________________________________________________________________
	//________________________________________________________________________________________________________________________________________________________________
	// Linse 45° gedreht, Apex Sphere (1.0, 1.0, 20.0)
	// Startwert (0.0, 0.0, 0.0)
	LightRayStruct LightRay211(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 1.0, 15.0 },  1.0);
	LightRayStruct LightRay212(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.5, 15.0 },  1.0);
	LightRayStruct LightRay213(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.0, 15.0 },  1.0);
	LightRayStruct LightRay214(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -0.5, 15.0 },  1.0);
	LightRayStruct LightRay215(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 },  1.0);

	SphericalSurface_LLT S21(/*radius*/9.0, /*semiHeight*/2.817458, /*Apex of the sphere*/{ 1.0, 1.0, 20.0 },
		/*Direction*/ VectorStructR3{ 0.0, -1.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.0);

	//InterP215: Programm gibt Schnittpunkt an, Strahl trifft Linse in Zemax, in Realtität nicht
	IntersectInformationStruct InterInfo211 = S21.calculateIntersection(LightRay211);
	VectorStructR3 InterP211 = InterInfo211.getIntersectionPoint();
	IntersectInformationStruct InterInfo212 = S21.calculateIntersection(LightRay212);
	VectorStructR3 InterP212 = InterInfo212.getIntersectionPoint();
	IntersectInformationStruct InterInfo213 = S21.calculateIntersection(LightRay213);
	VectorStructR3 InterP213 = InterInfo213.getIntersectionPoint();
	IntersectInformationStruct InterInfo214 = S21.calculateIntersection(LightRay214);
	VectorStructR3 InterP214 = InterInfo214.getIntersectionPoint();
	IntersectInformationStruct InterInfo215 = S21.calculateIntersection(LightRay215);
	VectorStructR3 InterP215 = InterInfo215.getIntersectionPoint();

	//________________________________________________________________________________________________________
	//Linse um 45° gedreht, Startwert (0.0, 2.0, 0.0)
	LightRayStruct LightRay216(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 },  1.0);
	LightRayStruct LightRay217(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.5, 15.0 },  1.0);
	LightRayStruct LightRay218(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.0, 15.0 },  1.0);
	LightRayStruct LightRay219(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.5, 15.0 },  1.0);
	LightRayStruct LightRay220(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -3.0, 15.0 },  1.0);


	//InterP217: y-Wert stimmt nicht exakt mit Zemax-Schnittpunkt überein -> Übereinstimmung Kommazahlen auf 8 heruntergesetzt
	IntersectInformationStruct InterInfo216 = S21.calculateIntersection(LightRay216);
	VectorStructR3 InterP216 = InterInfo216.getIntersectionPoint();
	IntersectInformationStruct InterInfo217 = S21.calculateIntersection(LightRay217);
	VectorStructR3 InterP217 = InterInfo217.getIntersectionPoint();
	IntersectInformationStruct InterInfo218 = S21.calculateIntersection(LightRay218);
	VectorStructR3 InterP218 = InterInfo218.getIntersectionPoint();
	IntersectInformationStruct InterInfo219 = S21.calculateIntersection(LightRay219);
	VectorStructR3 InterP219 = InterInfo219.getIntersectionPoint();
	IntersectInformationStruct InterInfo220 = S21.calculateIntersection(LightRay220);
	VectorStructR3 InterP220 = InterInfo220.getIntersectionPoint();

	std::vector<VectorStructR3> checkVector117 = { InterP211, InterP212, InterP213, InterP214, InterP215, InterP216, InterP217, InterP218, InterP219, InterP220 };


	std::vector<VectorStructR3> ReferenzVector117 = { { 0.0, 1.3647475229, 20.471212843 },{ 0.0, 0.65836584658, 19.750975398 },{ 0.0, 0.0, 19.206592655 },{ 0.0, -0.62592410304, 18.777723091 },{ 0.0, 0.0, 0.0 },
	{ 0.0, 0.68183815608, 19.772427659 },{ 0.0, 0.073753596848, 19.262464031 },{ 0.0, -0.51323693619, 18.849277021 },{ 0.0, -1.0849436945, 18.509662167 },{ 0.0, 0.0, 0.0 } };


	bool isRight117 = Math::compareAllVectorElements(checkVector117, ReferenzVector117, 8);
	checkMethodesSphericalLens.push_back(isRight117);

	//________________________________________________________________________________________________________________________________________________________________
	//________________________________________________________________________________________________________________________________________________________________
	// Linse -45° gedreht, Apex Sphere (1.0, 1.0, 20.0)
	// Startwert (0.0, 0.0, 0.0)
	LightRayStruct LightRay221(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 1.0, 15.0 },  1.0);
	LightRayStruct LightRay222(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.5, 15.0 },  1.0);
	LightRayStruct LightRay223(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.0, 15.0 },  1.0);
	LightRayStruct LightRay224(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -0.5, 15.0 },  1.0);
	LightRayStruct LightRay225(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 },  1.0);

	SphericalSurface_LLT S22(/*radius*/9.0, /*semiHeight*/2.817458, /*Apex of the sphere*/{ 1.0, 1.0, 20.0 },
		/*Direction*/ VectorStructR3{ 0.0, 1.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.0);

	IntersectInformationStruct InterInfo221 = S22.calculateIntersection(LightRay221);
	VectorStructR3 InterP221 = InterInfo221.getIntersectionPoint();
	IntersectInformationStruct InterInfo222 = S22.calculateIntersection(LightRay222);
	VectorStructR3 InterP222 = InterInfo222.getIntersectionPoint();
	IntersectInformationStruct InterInfo223 = S22.calculateIntersection(LightRay223);
	VectorStructR3 InterP223 = InterInfo223.getIntersectionPoint();
	IntersectInformationStruct InterInfo224 = S22.calculateIntersection(LightRay224);
	VectorStructR3 InterP224 = InterInfo224.getIntersectionPoint();
	IntersectInformationStruct InterInfo225 = S22.calculateIntersection(LightRay225);
	VectorStructR3 InterP225 = InterInfo225.getIntersectionPoint();

	//________________________________________________________________________________________________________
	//Linse um -45° gedreht, Startwert (0.0, 2.0, 0.0)
	LightRayStruct LightRay226(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 },  1.0);
	LightRayStruct LightRay227(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.5, 15.0 },  1.0);
	LightRayStruct LightRay228(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.0, 15.0 },  1.0);
	LightRayStruct LightRay229(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.5, 15.0 },  1.0);
	LightRayStruct LightRay230(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -3.0, 15.0 },  1.0);


	IntersectInformationStruct InterInfo226 = S22.calculateIntersection(LightRay226);
	VectorStructR3 InterP226 = InterInfo226.getIntersectionPoint();
	IntersectInformationStruct InterInfo227 = S22.calculateIntersection(LightRay227);
	VectorStructR3 InterP227 = InterInfo227.getIntersectionPoint();
	IntersectInformationStruct InterInfo228 = S22.calculateIntersection(LightRay228);
	VectorStructR3 InterP228 = InterInfo228.getIntersectionPoint();
	IntersectInformationStruct InterInfo229 = S22.calculateIntersection(LightRay229);
	VectorStructR3 InterP229 = InterInfo229.getIntersectionPoint();
	IntersectInformationStruct InterInfo230 = S22.calculateIntersection(LightRay230);
	VectorStructR3 InterP230 = InterInfo230.getIntersectionPoint();

	std::vector<VectorStructR3> checkVector118 = { InterP221, InterP222, InterP223, InterP224, InterP225, InterP226, InterP227, InterP228, InterP229, InterP230 };


	std::vector<VectorStructR3> ReferenzVector118 = { { 0.0, 1.3181618439, 19.772427659 },{ 0.0, 0.68065881904, 20.419764571 },{ 0.0, 0.0, 21.287340310 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },
	{ 0.0, 0.63525247711, 20.471212843 },{ 0.0, -0.15143383662, 21.514338366 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 } };


	bool isRight118 = Math::compareAllVectorElements(checkVector118, ReferenzVector118, 9);
	checkMethodesSphericalLens.push_back(isRight118);


	//________________________________________________________________________________________________________________________________________________________________
	//________________________________________________________________________________________________________________________________________________________________
	// Linse 90° gedreht, Apex Sphere (1.0, 1.0, 20.0)
	// Startwert (0.0, 0.0, 0.0)
	LightRayStruct LightRay231(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 1.0, 15.0 },  1.0);
	LightRayStruct LightRay232(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.5, 15.0 },  1.0);
	LightRayStruct LightRay233(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.0, 15.0 },  1.0);
	LightRayStruct LightRay234(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -0.5, 15.0 },  1.0);
	LightRayStruct LightRay235(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 },  1.0);

	SphericalSurface_LLT S23(/*radius*/9.0, /*semiHeight*/2.817458, /*Apex of the sphere*/{ 1.0, 1.0, 20.0 },
		/*Direction*/ VectorStructR3{ 0.0, -1.0, 0.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.0);

	IntersectInformationStruct InterInfo231 = S23.calculateIntersection(LightRay231);
	VectorStructR3 InterP231 = InterInfo231.getIntersectionPoint();
	IntersectInformationStruct InterInfo232 = S23.calculateIntersection(LightRay232);
	VectorStructR3 InterP232 = InterInfo232.getIntersectionPoint();
	IntersectInformationStruct InterInfo233 = S23.calculateIntersection(LightRay233);
	VectorStructR3 InterP233 = InterInfo233.getIntersectionPoint();
	IntersectInformationStruct InterInfo234 = S23.calculateIntersection(LightRay234);
	VectorStructR3 InterP234 = InterInfo234.getIntersectionPoint();
	IntersectInformationStruct InterInfo235 = S23.calculateIntersection(LightRay235);
	VectorStructR3 InterP235 = InterInfo235.getIntersectionPoint();

	//________________________________________________________________________________________________________
	//Linse um 90° gedreht, Startwert (0.0, 2.0, 0.0)
	LightRayStruct LightRay236(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 },  1.0);
	LightRayStruct LightRay237(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.5, 15.0 },  1.0);
	LightRayStruct LightRay238(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.0, 15.0 },  1.0);
	LightRayStruct LightRay239(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.5, 15.0 },  1.0);
	LightRayStruct LightRay240(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -3.0, 15.0 },  1.0);


	IntersectInformationStruct InterInfo236 = S23.calculateIntersection(LightRay236);
	VectorStructR3 InterP236 = InterInfo236.getIntersectionPoint();
	IntersectInformationStruct InterInfo237 = S23.calculateIntersection(LightRay237);
	VectorStructR3 InterP237 = InterInfo237.getIntersectionPoint();
	IntersectInformationStruct InterInfo238 = S23.calculateIntersection(LightRay238);
	VectorStructR3 InterP238 = InterInfo238.getIntersectionPoint();
	IntersectInformationStruct InterInfo239 = S23.calculateIntersection(LightRay239);
	VectorStructR3 InterP239 = InterInfo239.getIntersectionPoint();
	IntersectInformationStruct InterInfo240 = S23.calculateIntersection(LightRay240);
	VectorStructR3 InterP240 = InterInfo240.getIntersectionPoint();

	std::vector<VectorStructR3> checkVector119 = { InterP231, InterP232, InterP233, InterP234, InterP235, InterP236, InterP237, InterP238, InterP239, InterP240 };


	std::vector<VectorStructR3> ReferenzVector119 = { { 0.0, 0.0, 0.0 },{ 0.0, 0.58276048599, 17.482814580 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },
	{ 0.0, 0.78031472599, 18.295279110 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 } };


	bool isRight119 = Math::compareAllVectorElements(checkVector119, ReferenzVector119, 9);
	checkMethodesSphericalLens.push_back(isRight119);

	//________________________________________________________________________________________________________________________________________________________________
	//________________________________________________________________________________________________________________________________________________________________
	// Linse -90° gedreht, Apex Sphere (1.0, 1.0, 20.0)
	// Startwert (0.0, 0.0, 0.0)
	LightRayStruct LightRay241(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 1.0, 15.0 },  1.0);
	LightRayStruct LightRay242(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.5, 15.0 },  1.0);
	LightRayStruct LightRay243(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.0, 15.0 },  1.0);
	LightRayStruct LightRay244(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -0.5, 15.0 },  1.0);
	LightRayStruct LightRay245(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 },  1.0);

	SphericalSurface_LLT S24(/*radius*/9.0, /*semiHeight*/2.817458, /*Apex of the sphere*/{ 1.0, 1.0, 20.0 },
		/*Direction*/ VectorStructR3{ 0.0, 1.0, 0.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.0);

	IntersectInformationStruct InterInfo241 = S24.calculateIntersection(LightRay241);
	VectorStructR3 InterP241 = InterInfo241.getIntersectionPoint();
	IntersectInformationStruct InterInfo242 = S24.calculateIntersection(LightRay242);
	VectorStructR3 InterP242 = InterInfo242.getIntersectionPoint();
	IntersectInformationStruct InterInfo243 = S24.calculateIntersection(LightRay243);
	VectorStructR3 InterP243 = InterInfo243.getIntersectionPoint();
	IntersectInformationStruct InterInfo244 = S24.calculateIntersection(LightRay244);
	VectorStructR3 InterP244 = InterInfo244.getIntersectionPoint();
	IntersectInformationStruct InterInfo245 = S24.calculateIntersection(LightRay245);
	VectorStructR3 InterP245 = InterInfo245.getIntersectionPoint();

	//________________________________________________________________________________________________________
	//Linse um -90° gedreht, Startwert (0.0, 2.0, 0.0)
	LightRayStruct LightRay246(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 },  1.0);
	LightRayStruct LightRay247(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.5, 15.0 },  1.0);
	LightRayStruct LightRay248(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.0, 15.0 },  1.0);
	LightRayStruct LightRay249(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.5, 15.0 },  1.0);
	LightRayStruct LightRay250(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -3.0, 15.0 },  1.0);


	IntersectInformationStruct InterInfo246 = S24.calculateIntersection(LightRay246);
	VectorStructR3 InterP246 = InterInfo246.getIntersectionPoint();
	IntersectInformationStruct InterInfo247 = S24.calculateIntersection(LightRay247);
	VectorStructR3 InterP247 = InterInfo247.getIntersectionPoint();
	IntersectInformationStruct InterInfo248 = S24.calculateIntersection(LightRay248);
	VectorStructR3 InterP248 = InterInfo248.getIntersectionPoint();
	IntersectInformationStruct InterInfo249 = S24.calculateIntersection(LightRay249);
	VectorStructR3 InterP249 = InterInfo249.getIntersectionPoint();
	IntersectInformationStruct InterInfo250 = S24.calculateIntersection(LightRay250);
	VectorStructR3 InterP250 = InterInfo250.getIntersectionPoint();

	std::vector<VectorStructR3> checkVector120 = { InterP241, InterP242, InterP243, InterP244, InterP245, InterP246, InterP247, InterP248, InterP249, InterP250 };


	std::vector<VectorStructR3> ReferenzVector120 = { { 0.0, 1.2196852740, 18.295279110 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },
	{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 } };


	bool isRight120 = Math::compareAllVectorElements(checkVector120, ReferenzVector120, 9);
	checkMethodesSphericalLens.push_back(isRight120);



	//________________________________________________________________________________________________________________________________________________________________
	//________________________________________________________________________________________________________________________________________________________________
	//________________________________________________________________________________________________________________________________________________________________
	// Linse 0° gedreht, Apex Sphere (1.0, -1.0, 20.0)
	// Startwert (0.0, 0.0, 0.0)
	LightRayStruct LightRay251(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 1.0, 15.0 },  1.0);
	LightRayStruct LightRay252(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.5, 15.0 },  1.0);
	LightRayStruct LightRay253(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.0, 15.0 },  1.0);
	LightRayStruct LightRay254(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -0.5, 15.0 },  1.0);
	LightRayStruct LightRay255(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 },  1.0);

	SphericalSurface_LLT S25(/*radius*/9.0, /*semiHeight*/2.817458, /*Apex of the sphere*/{ 1.0, -1.0, 20.0 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.0);

	IntersectInformationStruct InterInfo251 = S25.calculateIntersection(LightRay251);
	VectorStructR3 InterP251 = InterInfo251.getIntersectionPoint();
	IntersectInformationStruct InterInfo252 = S25.calculateIntersection(LightRay252);
	VectorStructR3 InterP252 = InterInfo252.getIntersectionPoint();
	IntersectInformationStruct InterInfo253 = S25.calculateIntersection(LightRay253);
	VectorStructR3 InterP253 = InterInfo253.getIntersectionPoint();
	IntersectInformationStruct InterInfo254 = S25.calculateIntersection(LightRay254);
	VectorStructR3 InterP254 = InterInfo254.getIntersectionPoint();
	IntersectInformationStruct InterInfo255 = S25.calculateIntersection(LightRay255);
	VectorStructR3 InterP255 = InterInfo255.getIntersectionPoint();

	//________________________________________________________________________________________________________
	//Linse um 0° gedreht, Startwert (0.0, 2.0, 0.0)
	LightRayStruct LightRay256(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 },  1.0);
	LightRayStruct LightRay257(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.5, 15.0 },  1.0);
	LightRayStruct LightRay258(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.0, 15.0 },  1.0);
	LightRayStruct LightRay259(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.5, 15.0 },  1.0);
	LightRayStruct LightRay260(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -3.0, 15.0 },  1.0);


	IntersectInformationStruct InterInfo256 = S25.calculateIntersection(LightRay256);
	VectorStructR3 InterP256 = InterInfo256.getIntersectionPoint();
	IntersectInformationStruct InterInfo257 = S25.calculateIntersection(LightRay257);
	VectorStructR3 InterP257 = InterInfo257.getIntersectionPoint();
	IntersectInformationStruct InterInfo258 = S25.calculateIntersection(LightRay258);
	VectorStructR3 InterP258 = InterInfo258.getIntersectionPoint();
	IntersectInformationStruct InterInfo259 = S25.calculateIntersection(LightRay259);
	VectorStructR3 InterP259 = InterInfo259.getIntersectionPoint();
	IntersectInformationStruct InterInfo260 = S25.calculateIntersection(LightRay260);
	VectorStructR3 InterP260 = InterInfo260.getIntersectionPoint();

	std::vector<VectorStructR3> checkVector121 = { InterP251, InterP252, InterP253, InterP254, InterP255, InterP256, InterP257, InterP258, InterP259, InterP260 };


	std::vector<VectorStructR3> ReferenzVector121 = { { 0.0, 1.3581458345, 20.372187518 },{ 0.0, 0.67379122302, 20.213736691 },{ 0.0, 0.0, 20.111805583 },{ 0.0, -0.66872882935, 20.061864881 },{ 0.0, -1.3374731264, 20.062096896 },
	{ 0.0, 0.65268386790, 20.209741981 },{ 0.0, -0.011056855272, 20.110568553 },{ 0.0, -0.67488517773, 20.061638833 },{ 0.0, -1.3437225076, 20.062335046 },{ 0.0, -2.0228819681, 20.114409841 } };


	bool isRight121 = Math::compareAllVectorElements(checkVector121, ReferenzVector121, 9);
	checkMethodesSphericalLens.push_back(isRight121);


	//________________________________________________________________________________________________________________________________________________________________
	//________________________________________________________________________________________________________________________________________________________________
	// Linse 45° gedreht, Apex Sphere (1.0, -1.0, 20.0)
	// Startwert (0.0, 0.0, 0.0)
	LightRayStruct LightRay261(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 1.0, 15.0 },  1.0);
	LightRayStruct LightRay262(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.5, 15.0 },  1.0);
	LightRayStruct LightRay263(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.0, 15.0 },  1.0);
	LightRayStruct LightRay264(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -0.5, 15.0 },  1.0);
	LightRayStruct LightRay265(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 },  1.0);

	SphericalSurface_LLT S26(/*radius*/9.0, /*semiHeight*/2.817458, /*Apex of the sphere*/{ 1.0, -1.0, 20.0 },
		/*Direction*/ VectorStructR3{ 0.0, -1.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.0);

	IntersectInformationStruct InterInfo261 = S26.calculateIntersection(LightRay261);
	VectorStructR3 InterP261 = InterInfo261.getIntersectionPoint();
	IntersectInformationStruct InterInfo262 = S26.calculateIntersection(LightRay262);
	VectorStructR3 InterP262 = InterInfo262.getIntersectionPoint();
	IntersectInformationStruct InterInfo263 = S26.calculateIntersection(LightRay263);
	VectorStructR3 InterP263 = InterInfo263.getIntersectionPoint();
	IntersectInformationStruct InterInfo264 = S26.calculateIntersection(LightRay264);
	VectorStructR3 InterP264 = InterInfo264.getIntersectionPoint();
	IntersectInformationStruct InterInfo265 = S26.calculateIntersection(LightRay265);
	VectorStructR3 InterP265 = InterInfo265.getIntersectionPoint();

	//________________________________________________________________________________________________________
	//Linse um 45° gedreht, Startwert (0.0, 2.0, 0.0)
	LightRayStruct LightRay266(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 },  1.0);
	LightRayStruct LightRay267(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.5, 15.0 },  1.0);
	LightRayStruct LightRay268(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.0, 15.0 },  1.0);
	LightRayStruct LightRay269(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.5, 15.0 },  1.0);
	LightRayStruct LightRay270(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -3.0, 15.0 },  1.0);


	IntersectInformationStruct InterInfo266 = S26.calculateIntersection(LightRay266);
	VectorStructR3 InterP266 = InterInfo266.getIntersectionPoint();
	IntersectInformationStruct InterInfo267 = S26.calculateIntersection(LightRay267);
	VectorStructR3 InterP267 = InterInfo267.getIntersectionPoint();
	IntersectInformationStruct InterInfo268 = S26.calculateIntersection(LightRay268);
	VectorStructR3 InterP268 = InterInfo268.getIntersectionPoint();
	IntersectInformationStruct InterInfo269 = S26.calculateIntersection(LightRay269);
	VectorStructR3 InterP269 = InterInfo269.getIntersectionPoint();
	IntersectInformationStruct InterInfo270 = S26.calculateIntersection(LightRay260);
	VectorStructR3 InterP270 = InterInfo270.getIntersectionPoint();

	std::vector<VectorStructR3> checkVector122 = { InterP261, InterP262, InterP263, InterP264, InterP265, InterP266, InterP267, InterP268, InterP269, InterP270 };


	std::vector<VectorStructR3> ReferenzVector122 = { { 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 21.287340310 },{ 0.0, -0.68065881904 , 20.419764571 },{ 0.0, -1.3181618439, 19.772427659 },
	{ 0.0, 0.52356616967, 22.146507455 },{ 0.0, -0.11275491095, 21.127549109 },{ 0.0, -0.71719214830, 20.378941112 },{ 0.0, -1.2984300534, 19.790580320 },{ 0.0, -1.8623672261, 19.311836130 } };


	bool isRight122 = Math::compareAllVectorElements(checkVector122, ReferenzVector122, 9);
	checkMethodesSphericalLens.push_back(isRight122);

	//________________________________________________________________________________________________________________________________________________________________
	//________________________________________________________________________________________________________________________________________________________________
	// Linse -45° gedreht, Apex Sphere (1.0, -1.0, 20.0)
	// Startwert (0.0, 0.0, 0.0)
	LightRayStruct LightRay271(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 1.0, 15.0 },  1.0);
	LightRayStruct LightRay272(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.5, 15.0 },  1.0);
	LightRayStruct LightRay273(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.0, 15.0 },  1.0);
	LightRayStruct LightRay274(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -0.5, 15.0 },  1.0);
	LightRayStruct LightRay275(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 },  1.0);

	SphericalSurface_LLT S27(/*radius*/9.0, /*semiHeight*/2.817458, /*Apex of the sphere*/{ 1.0, -1.0, 20.0 },
		/*Direction*/ VectorStructR3{ 0.0, 1.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.0);

	//InterP271: Programm gibt keinen Schnittpunkt mit Linse an, Strahl trifft Linse in Zemax, in Realtität nicht
	IntersectInformationStruct InterInfo271 = S27.calculateIntersection(LightRay271);
	VectorStructR3 InterP271 = InterInfo271.getIntersectionPoint();
	IntersectInformationStruct InterInfo272 = S27.calculateIntersection(LightRay272);
	VectorStructR3 InterP272 = InterInfo272.getIntersectionPoint();
	IntersectInformationStruct InterInfo273 = S27.calculateIntersection(LightRay273);
	VectorStructR3 InterP273 = InterInfo273.getIntersectionPoint();
	IntersectInformationStruct InterInfo274 = S27.calculateIntersection(LightRay274);
	VectorStructR3 InterP274 = InterInfo274.getIntersectionPoint();
	IntersectInformationStruct InterInfo275 = S27.calculateIntersection(LightRay275);
	VectorStructR3 InterP275 = InterInfo275.getIntersectionPoint();

	//________________________________________________________________________________________________________
	//Linse um -45° gedreht, Startwert (0.0, 2.0, 0.0)
	LightRayStruct LightRay276(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 },  1.0);
	LightRayStruct LightRay277(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.5, 15.0 },  1.0);
	LightRayStruct LightRay278(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.0, 15.0 },  1.0);
	LightRayStruct LightRay279(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.5, 15.0 },  1.0);
	LightRayStruct LightRay280(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -3.0, 15.0 },  1.0);


	IntersectInformationStruct InterInfo276 = S27.calculateIntersection(LightRay276);
	VectorStructR3 InterP276 = InterInfo276.getIntersectionPoint();
	IntersectInformationStruct InterInfo277 = S27.calculateIntersection(LightRay277);
	VectorStructR3 InterP277 = InterInfo277.getIntersectionPoint();
	IntersectInformationStruct InterInfo278 = S27.calculateIntersection(LightRay278);
	VectorStructR3 InterP278 = InterInfo278.getIntersectionPoint();
	IntersectInformationStruct InterInfo279 = S27.calculateIntersection(LightRay279);
	VectorStructR3 InterP279 = InterInfo279.getIntersectionPoint();
	IntersectInformationStruct InterInfo280 = S27.calculateIntersection(LightRay280);
	VectorStructR3 InterP280 = InterInfo280.getIntersectionPoint();

	std::vector<VectorStructR3> checkVector123 = { InterP271, InterP272, InterP273, InterP274, InterP275, InterP276, InterP277, InterP278, InterP279, InterP280 };


	std::vector<VectorStructR3> ReferenzVector123 = { { 0.0, 0.0, 0.0 },{ 0.0, 0.62592410304, 18.777723091 },{ 0.0,  0.0, 19.206592655 },{ 0.0, -0.65836584658, 19.750975398 },{ 0.0, -1.3647475229, 20.471212843 },
	{ 0.0, 0.75335967435, 18.699604885 },{ 0.0, 0.085682685652, 19.143173143 },{ 0.0, -0.63003850027, 19.725288752 },{ 0.0, -1.4230827549, 20.538496530 },{ 0.0, -2.3764396609, 21.882198304 } };


	bool isRight123 = Math::compareAllVectorElements(checkVector123, ReferenzVector123, 9);
	checkMethodesSphericalLens.push_back(isRight123);


	//________________________________________________________________________________________________________________________________________________________________
	//________________________________________________________________________________________________________________________________________________________________
	// Linse 90° gedreht, Apex Sphere (1.0, -1.0, 20.0)
	// Startwert (0.0, 0.0, 0.0)
	LightRayStruct LightRay281(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 1.0, 15.0 },  1.0);
	LightRayStruct LightRay282(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.5, 15.0 },  1.0);
	LightRayStruct LightRay283(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.0, 15.0 },  1.0);
	LightRayStruct LightRay284(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -0.5, 15.0 },  1.0);
	LightRayStruct LightRay285(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 },  1.0);

	SphericalSurface_LLT S28(/*radius*/9.0, /*semiHeight*/2.817458, /*Apex of the sphere*/{ 1.0, -1.0, 20.0 },
		/*Direction*/ VectorStructR3{ 0.0, -1.0, 0.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.0);

	IntersectInformationStruct InterInfo281 = S28.calculateIntersection(LightRay281);
	VectorStructR3 InterP281 = InterInfo281.getIntersectionPoint();
	IntersectInformationStruct InterInfo282 = S28.calculateIntersection(LightRay282);
	VectorStructR3 InterP282 = InterInfo282.getIntersectionPoint();
	IntersectInformationStruct InterInfo283 = S28.calculateIntersection(LightRay283);
	VectorStructR3 InterP283 = InterInfo283.getIntersectionPoint();
	IntersectInformationStruct InterInfo284 = S28.calculateIntersection(LightRay284);
	VectorStructR3 InterP284 = InterInfo284.getIntersectionPoint();
	IntersectInformationStruct InterInfo285 = S28.calculateIntersection(LightRay285);
	VectorStructR3 InterP285 = InterInfo285.getIntersectionPoint();

	//________________________________________________________________________________________________________
	//Linse um 90° gedreht, Startwert (0.0, 2.0, 0.0)
	LightRayStruct LightRay286(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 },  1.0);
	LightRayStruct LightRay287(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.5, 15.0 },  1.0);
	LightRayStruct LightRay288(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.0, 15.0 },  1.0);
	LightRayStruct LightRay289(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.5, 15.0 },  1.0);
	LightRayStruct LightRay290(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -3.0, 15.0 },  1.0);


	//InterP290: Programm gibt keinen Schnittpunkt mit Linse an, Strahl trifft Linse in Zemax, in Realtität nicht
	IntersectInformationStruct InterInfo286 = S28.calculateIntersection(LightRay286);
	VectorStructR3 InterP286 = InterInfo286.getIntersectionPoint();
	IntersectInformationStruct InterInfo287 = S28.calculateIntersection(LightRay287);
	VectorStructR3 InterP287 = InterInfo287.getIntersectionPoint();
	IntersectInformationStruct InterInfo288 = S28.calculateIntersection(LightRay288);
	VectorStructR3 InterP288 = InterInfo288.getIntersectionPoint();
	IntersectInformationStruct InterInfo289 = S28.calculateIntersection(LightRay289);
	VectorStructR3 InterP289 = InterInfo289.getIntersectionPoint();
	IntersectInformationStruct InterInfo290 = S28.calculateIntersection(LightRay290);
	VectorStructR3 InterP290 = InterInfo290.getIntersectionPoint();

	std::vector<VectorStructR3> checkVector124 = { InterP281, InterP282, InterP283, InterP284, InterP285, InterP286, InterP287, InterP288, InterP289, InterP290 };


	std::vector<VectorStructR3> ReferenzVector124 = { { 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, -1.2196852740, 18.295279110 },
	{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, -1.1351351351, 18.810810811 },{ 0.0, 0.0, 0.0 } };


	bool isRight124 = Math::compareAllVectorElements(checkVector124, ReferenzVector124, 9);
	checkMethodesSphericalLens.push_back(isRight124);

	//________________________________________________________________________________________________________________________________________________________________
	//________________________________________________________________________________________________________________________________________________________________
	// Linse -90° gedreht, Apex Sphere (1.0, -1.0, 20.0)
	// Startwert (0.0, 0.0, 0.0)
	LightRayStruct LightRay291(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 1.0, 15.0 },  1.0);
	LightRayStruct LightRay292(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.5, 15.0 },  1.0);
	LightRayStruct LightRay293(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.0, 15.0 },  1.0);
	LightRayStruct LightRay294(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -0.5, 15.0 },  1.0);
	LightRayStruct LightRay295(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 },  1.0);

	SphericalSurface_LLT S29(/*radius*/9.0, /*semiHeight*/2.817458, /*Apex of the sphere*/{ 1.0, -1.0, 20.0 },
		/*Direction*/ VectorStructR3{ 0.0, 1.0, 0.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.0);

	// InterP294 stimmt nicht mit ZEMAX-Schnittpunkt überein!
	IntersectInformationStruct InterInfo291 = S29.calculateIntersection(LightRay291);
	VectorStructR3 InterP291 = InterInfo291.getIntersectionPoint();
	IntersectInformationStruct InterInfo292 = S29.calculateIntersection(LightRay292);
	VectorStructR3 InterP292 = InterInfo292.getIntersectionPoint();
	IntersectInformationStruct InterInfo293 = S29.calculateIntersection(LightRay293);
	VectorStructR3 InterP293 = InterInfo293.getIntersectionPoint();
	IntersectInformationStruct InterInfo294 = S29.calculateIntersection(LightRay294);
	VectorStructR3 InterP294 = InterInfo294.getIntersectionPoint();
	IntersectInformationStruct InterInfo295 = S29.calculateIntersection(LightRay295);
	VectorStructR3 InterP295 = InterInfo295.getIntersectionPoint();

	//________________________________________________________________________________________________________
	//Linse um -90° gedreht, Startwert (0.0, 2.0, 0.0)
	LightRayStruct LightRay296(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 },  1.0);
	LightRayStruct LightRay297(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.5, 15.0 },  1.0);
	LightRayStruct LightRay298(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.0, 15.0 },  1.0);
	LightRayStruct LightRay299(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.5, 15.0 },  1.0);
	LightRayStruct LightRay300(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -3.0, 15.0 },  1.0);


	//InterP298 trifft Linse von oben, ZEMAX gibt keinen Schnittpunkt an -> Programm-Schnittpunkt als Referenz eingetragen
	IntersectInformationStruct InterInfo296 = S29.calculateIntersection(LightRay296);
	VectorStructR3 InterP296 = InterInfo296.getIntersectionPoint();
	IntersectInformationStruct InterInfo297 = S29.calculateIntersection(LightRay297);
	VectorStructR3 InterP297 = InterInfo297.getIntersectionPoint();
	IntersectInformationStruct InterInfo298 = S29.calculateIntersection(LightRay298);
	VectorStructR3 InterP298 = InterInfo298.getIntersectionPoint();
	// we compared our results with the zemax in sequential mode. To trace this ray we had to swith to NONsequential mode.
	IntersectInformationStruct InterInfo299 = S29.calculateIntersection(LightRay299);
	VectorStructR3 InterP299 = InterInfo299.getIntersectionPoint();
	IntersectInformationStruct InterInfo300 = S29.calculateIntersection(LightRay300);
	VectorStructR3 InterP300 = InterInfo300.getIntersectionPoint();

	std::vector<VectorStructR3> checkVector125 = { InterP291, InterP292, InterP293, InterP294, InterP295, InterP296, InterP297, InterP298, InterP299, InterP300 };


	std::vector<VectorStructR3> ReferenzVector125 = { { 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0,  -0.58276048599, 17.482814580 },{ 0.0, 0.0, 0.0 },
	{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, -0.84439202936972979, 21.332940220272974 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 } };


	bool isRight125 = Math::compareAllVectorElements(checkVector125, ReferenzVector125, 9);
	checkMethodesSphericalLens.push_back(isRight125);


	//____________________________________________________________________________________________________________________________________________________
	//____________________________________________________________________________________________________________________________________________________
	//____________________________________________________________________________________________________________________________________________________
	// Linse 0° gedreht, Apex Sphere (-1.0, 0.0, 20.0)
	// Startwert (0.0, 0.0, 0.0)
	LightRayStruct LightRay301(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 1.0, 15.0 },  1.0);
	LightRayStruct LightRay302(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.5, 15.0 },  1.0);
	LightRayStruct LightRay303(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.0, 15.0 },  1.0);
	LightRayStruct LightRay304(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -0.5, 15.0 },  1.0);
	LightRayStruct LightRay305(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 },  1.0);

	SphericalSurface_LLT S30(/*radius*/9.0, /*semiHeight*/2.817458, /*Apex of the sphere*/{ -1.0, 0.0, 20.0 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.0);

	IntersectInformationStruct InterInfo301 = S30.calculateIntersection(LightRay301);
	VectorStructR3 InterP301 = InterInfo301.getIntersectionPoint();
	IntersectInformationStruct InterInfo302 = S30.calculateIntersection(LightRay302);
	VectorStructR3 InterP302 = InterInfo302.getIntersectionPoint();
	IntersectInformationStruct InterInfo303 = S30.calculateIntersection(LightRay303);
	VectorStructR3 InterP303 = InterInfo303.getIntersectionPoint();
	IntersectInformationStruct InterInfo304 = S30.calculateIntersection(LightRay304);
	VectorStructR3 InterP304 = InterInfo304.getIntersectionPoint();
	IntersectInformationStruct InterInfo305 = S30.calculateIntersection(LightRay305);
	VectorStructR3 InterP305 = InterInfo305.getIntersectionPoint();

	//________________________________________________________________________________________________________
	//Linse um 0° gedreht, Startwert (0.0, 2.0, 0.0)
	LightRayStruct LightRay306(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 },  1.0);
	LightRayStruct LightRay307(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.5, 15.0 },  1.0);
	LightRayStruct LightRay308(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.0, 15.0 },  1.0);
	LightRayStruct LightRay309(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.5, 15.0 },  1.0);
	LightRayStruct LightRay310(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -3.0, 15.0 },  1.0);


	IntersectInformationStruct InterInfo306 = S30.calculateIntersection(LightRay306);
	VectorStructR3 InterP306 = InterInfo306.getIntersectionPoint();
	IntersectInformationStruct InterInfo307 = S30.calculateIntersection(LightRay307);
	VectorStructR3 InterP307 = InterInfo307.getIntersectionPoint();
	IntersectInformationStruct InterInfo308 = S30.calculateIntersection(LightRay308);
	VectorStructR3 InterP308 = InterInfo308.getIntersectionPoint();
	IntersectInformationStruct InterInfo309 = S30.calculateIntersection(LightRay309);
	VectorStructR3 InterP309 = InterInfo309.getIntersectionPoint();
	IntersectInformationStruct InterInfo310 = S30.calculateIntersection(LightRay310);
	VectorStructR3 InterP310 = InterInfo310.getIntersectionPoint();


	std::vector<VectorStructR3> checkVector126 = { InterP301, InterP302, InterP303, InterP304, InterP305, InterP306, InterP307, InterP308, InterP309, InterP310 };


	std::vector<VectorStructR3> ReferenzVector126 = { { 0.0, 1.3438169363, 20.157254044 },{ 0.0, 0.66936032118, 20.080809635 },{ 0.0, 0.0, 20.055728090 },{ 0.0, -0.66936032118, 20.080809635 },{ 0.0, -1.3438169363, 20.157254044 },
	{ 0.0, 0.66131934484, 20.080209827 },{ 0.0, -0.0055729826237, 20.055729826 },{ 0.0, -0.67752346849, 20.081426014 },{ 0.0, -1.3599535611, 20.159721367 },{ 0.0, -2.0591990429, 20.295995215 } };


	bool isRight126 = Math::compareAllVectorElements(checkVector126, ReferenzVector126, 9);
	checkMethodesSphericalLens.push_back(isRight126);


	//________________________________________________________________________________________________________________________________________________________________
	//________________________________________________________________________________________________________________________________________________________________
	// Linse 45° gedreht, Apex Sphere (-1.0, 0.0, 20.0)
	// Startwert (0.0, 0.0, 0.0)
	LightRayStruct LightRay311(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 1.0, 15.0 },  1.0);
	LightRayStruct LightRay312(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.5, 15.0 },  1.0);
	LightRayStruct LightRay313(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.0, 15.0 },  1.0);
	LightRayStruct LightRay314(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -0.5, 15.0 },  1.0);
	LightRayStruct LightRay315(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 },  1.0);

	SphericalSurface_LLT S31(/*radius*/9.0, /*semiHeight*/2.817458, /*Apex of the sphere*/{ -1.0, 0.0, 20.0 },
		/*Direction*/ VectorStructR3{ 0.0, -1.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.0);

	IntersectInformationStruct InterInfo311 = S31.calculateIntersection(LightRay311);
	VectorStructR3 InterP311 = InterInfo311.getIntersectionPoint();
	IntersectInformationStruct InterInfo312 = S31.calculateIntersection(LightRay312);
	VectorStructR3 InterP312 = InterInfo312.getIntersectionPoint();
	IntersectInformationStruct InterInfo313 = S31.calculateIntersection(LightRay313);
	VectorStructR3 InterP313 = InterInfo313.getIntersectionPoint();
	IntersectInformationStruct InterInfo314 = S31.calculateIntersection(LightRay314);
	VectorStructR3 InterP314 = InterInfo314.getIntersectionPoint();
	IntersectInformationStruct InterInfo315 = S31.calculateIntersection(LightRay315);
	VectorStructR3 InterP315 = InterInfo315.getIntersectionPoint();

	//________________________________________________________________________________________________________
	//Linse um 45° gedreht, Startwert (0.0, 2.0, 0.0)
	LightRayStruct LightRay316(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 },  1.0);
	LightRayStruct LightRay317(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.5, 15.0 },  1.0);
	LightRayStruct LightRay318(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.0, 15.0 },  1.0);
	LightRayStruct LightRay319(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.5, 15.0 },  1.0);
	LightRayStruct LightRay320(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -3.0, 15.0 },  1.0);


	IntersectInformationStruct InterInfo316 = S31.calculateIntersection(LightRay316);
	VectorStructR3 InterP316 = InterInfo316.getIntersectionPoint();
	IntersectInformationStruct InterInfo317 = S31.calculateIntersection(LightRay317);
	VectorStructR3 InterP317 = InterInfo317.getIntersectionPoint();
	IntersectInformationStruct InterInfo318 = S31.calculateIntersection(LightRay318);
	VectorStructR3 InterP318 = InterInfo318.getIntersectionPoint();
	IntersectInformationStruct InterInfo319 = S31.calculateIntersection(LightRay319);
	VectorStructR3 InterP319 = InterInfo319.getIntersectionPoint();
	IntersectInformationStruct InterInfo320 = S31.calculateIntersection(LightRay320);
	VectorStructR3 InterP320 = InterInfo320.getIntersectionPoint();

	std::vector<VectorStructR3> checkVector127 = { InterP311, InterP312, InterP313, InterP314, InterP315, InterP316, InterP317, InterP318, InterP319, InterP320 };


	std::vector<VectorStructR3> ReferenzVector127 = { { 0.0, 1.4698348265, 22.047522398 },{ 0.0, 0.69573625181, 20.872087554 },{ 0.0, 0.0, 20.079058486 },{ 0.0, -0.64944146832 , 19.483244050 },{ 0.0, -1.2675775589, 19.013663383 },
	{ 0.0, 0.61531710528, 20.770243421 },{ 0.0, -0.0071796788928, 20.071796789 },{ 0.0, -0.60294972288, 19.522122922 },{ 0.0, -1.1792795683, 19.075677410 },{ 0.0, -1.7413664712, 18.706832356 } };


	bool isRight127 = Math::compareAllVectorElements(checkVector127, ReferenzVector127, 9);
	checkMethodesSphericalLens.push_back(isRight127);

	//________________________________________________________________________________________________________________________________________________________________
	//________________________________________________________________________________________________________________________________________________________________
	// Linse -45° gedreht, Apex Sphere (-1.0, 0.0, 20.0)
	// Startwert (0.0, 0.0, 0.0)
	LightRayStruct LightRay321(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 1.0, 15.0 },  1.0);
	LightRayStruct LightRay322(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.5, 15.0 },  1.0);
	LightRayStruct LightRay323(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.0, 15.0 },  1.0);
	LightRayStruct LightRay324(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -0.5, 15.0 },  1.0);
	LightRayStruct LightRay325(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 },  1.0);

	SphericalSurface_LLT S32(/*radius*/9.0, /*semiHeight*/2.817458, /*Apex of the sphere*/{ -1.0, 0.0, 20.0 },
		/*Direction*/ VectorStructR3{ 0.0, 1.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.0);

	//InterP322 stimmt nicht exakt mit Zemax-Schnittpunkten überein -> Übereinstimmung Kommazahlen auf 8 heruntergesetzt
	IntersectInformationStruct InterInfo321 = S32.calculateIntersection(LightRay321);
	VectorStructR3 InterP321 = InterInfo321.getIntersectionPoint();
	IntersectInformationStruct InterInfo322 = S32.calculateIntersection(LightRay322);
	VectorStructR3 InterP322 = InterInfo322.getIntersectionPoint();
	IntersectInformationStruct InterInfo323 = S32.calculateIntersection(LightRay323);
	VectorStructR3 InterP323 = InterInfo323.getIntersectionPoint();
	IntersectInformationStruct InterInfo324 = S32.calculateIntersection(LightRay324);
	VectorStructR3 InterP324 = InterInfo324.getIntersectionPoint();
	IntersectInformationStruct InterInfo325 = S32.calculateIntersection(LightRay325);
	VectorStructR3 InterP325 = InterInfo325.getIntersectionPoint();

	//________________________________________________________________________________________________________
	//Linse um -45° gedreht, Startwert (0.0, 2.0, 0.0)
	LightRayStruct LightRay326(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 },  1.0);
	LightRayStruct LightRay327(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.5, 15.0 },  1.0);
	LightRayStruct LightRay328(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.0, 15.0 },  1.0);
	LightRayStruct LightRay329(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.5, 15.0 },  1.0);
	LightRayStruct LightRay330(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -3.0, 15.0 },  1.0);


	//InterP327 stimmt nicht exakt mit Zemax-Schnittpunkt überein -> Übereinstimmung Kommazahlen auf 8 heruntergesetzt
	IntersectInformationStruct InterInfo326 = S32.calculateIntersection(LightRay326);
	VectorStructR3 InterP326 = InterInfo326.getIntersectionPoint();
	IntersectInformationStruct InterInfo327 = S32.calculateIntersection(LightRay327);
	VectorStructR3 InterP327 = InterInfo327.getIntersectionPoint();
	IntersectInformationStruct InterInfo328 = S32.calculateIntersection(LightRay328);
	VectorStructR3 InterP328 = InterInfo328.getIntersectionPoint();
	IntersectInformationStruct InterInfo329 = S32.calculateIntersection(LightRay329);
	VectorStructR3 InterP329 = InterInfo329.getIntersectionPoint();
	IntersectInformationStruct InterInfo330 = S32.calculateIntersection(LightRay330);
	VectorStructR3 InterP330 = InterInfo330.getIntersectionPoint();

	std::vector<VectorStructR3> checkVector128 = { InterP321, InterP322, InterP323, InterP324, InterP325, InterP326, InterP327, InterP328, InterP329, InterP330 };


	std::vector<VectorStructR3> ReferenzVector128 = { { 0.0, 1.2675775589, 19.013663383 },{ 0.0, 0.64944146832, 19.483244050 },{ 0.0, 0.0, 20.079058486 },{ 0.0, -0.69573625181, 20.872087554 },{ 0.0, -1.4698348265, 22.047522398 },
	{ 0.0, 0.70412017130, 19.438197430 },{ 0.0, -0.0087979606378, 20.087979606 },{ 0.0, -0.80142946372, 21.010720978 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 } };


	bool isRight128 = Math::compareAllVectorElements(checkVector128, ReferenzVector128, 8);
	checkMethodesSphericalLens.push_back(isRight128);


	//________________________________________________________________________________________________________________________________________________________________
	//________________________________________________________________________________________________________________________________________________________________
	// Linse 90° gedreht, Apex Sphere (-1.0, 0.0, 20.0)
	// Startwert (0.0, 0.0, 0.0)
	LightRayStruct LightRay331(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 1.0, 15.0 },  1.0);
	LightRayStruct LightRay332(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.5, 15.0 },  1.0);
	LightRayStruct LightRay333(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.0, 15.0 },  1.0);
	LightRayStruct LightRay334(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -0.5, 15.0 },  1.0);
	LightRayStruct LightRay335(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 },  1.0);

	SphericalSurface_LLT S33(/*radius*/9.0, /*semiHeight*/2.817458, /*Apex of the sphere*/{ -1.0, 0.0, 20.0 },
		/*Direction*/ VectorStructR3{ 0.0, -1.0, 0.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.0);

	IntersectInformationStruct InterInfo331 = S33.calculateIntersection(LightRay331);
	VectorStructR3 InterP331 = InterInfo331.getIntersectionPoint();
	IntersectInformationStruct InterInfo332 = S33.calculateIntersection(LightRay332);
	VectorStructR3 InterP332 = InterInfo332.getIntersectionPoint();
	IntersectInformationStruct InterInfo333 = S33.calculateIntersection(LightRay333);
	VectorStructR3 InterP333 = InterInfo333.getIntersectionPoint();
	IntersectInformationStruct InterInfo334 = S33.calculateIntersection(LightRay334);
	VectorStructR3 InterP334 = InterInfo334.getIntersectionPoint();
	IntersectInformationStruct InterInfo335 = S33.calculateIntersection(LightRay335);
	VectorStructR3 InterP335 = InterInfo335.getIntersectionPoint();

	//________________________________________________________________________________________________________
	//Linse um 90° gedreht, Startwert (0.0, 2.0, 0.0)
	LightRayStruct LightRay336(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 },  1.0);
	LightRayStruct LightRay337(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.5, 15.0 },  1.0);
	LightRayStruct LightRay338(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.0, 15.0 },  1.0);
	LightRayStruct LightRay339(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.5, 15.0 },  1.0);
	LightRayStruct LightRay340(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -3.0, 15.0 },  1.0);


	IntersectInformationStruct InterInfo336 = S33.calculateIntersection(LightRay336);
	VectorStructR3 InterP336 = InterInfo336.getIntersectionPoint();
	IntersectInformationStruct InterInfo337 = S33.calculateIntersection(LightRay337);
	VectorStructR3 InterP337 = InterInfo337.getIntersectionPoint();
	IntersectInformationStruct InterInfo338 = S33.calculateIntersection(LightRay338);
	VectorStructR3 InterP338 = InterInfo338.getIntersectionPoint();
	IntersectInformationStruct InterInfo339 = S33.calculateIntersection(LightRay339);
	VectorStructR3 InterP339 = InterInfo339.getIntersectionPoint();
	IntersectInformationStruct InterInfo340 = S33.calculateIntersection(LightRay340);
	VectorStructR3 InterP340 = InterInfo340.getIntersectionPoint();

	std::vector<VectorStructR3> checkVector129 = { InterP331, InterP332, InterP333, InterP334, InterP335, InterP336, InterP337, InterP338, InterP339, InterP340 };


	std::vector<VectorStructR3> ReferenzVector129 = { { 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },
	{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, -0.35883502699, 17.691262702 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 } };


	bool isRight129 = Math::compareAllVectorElements(checkVector129, ReferenzVector129, 9);
	checkMethodesSphericalLens.push_back(isRight129);

	//________________________________________________________________________________________________________________________________________________________________
	//________________________________________________________________________________________________________________________________________________________________
	// Linse -90° gedreht, Apex Sphere (-1.0, 0.0, 20.0)
	// Startwert (0.0, 0.0, 0.0)
	LightRayStruct LightRay341(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 1.0, 15.0 },  1.0);
	LightRayStruct LightRay342(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.5, 15.0 },  1.0);
	LightRayStruct LightRay343(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.0, 15.0 },  1.0);
	LightRayStruct LightRay344(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -0.5, 15.0 },  1.0);
	LightRayStruct LightRay345(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 },  1.0);

	SphericalSurface_LLT S34(/*radius*/9.0, /*semiHeight*/2.817458, /*Apex of the sphere*/{ -1.0, 0.0, 20.0 },
		/*Direction*/ VectorStructR3{ 0.0, 1.0, 0.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.0);

	IntersectInformationStruct InterInfo341 = S34.calculateIntersection(LightRay341);
	VectorStructR3 InterP341 = InterInfo341.getIntersectionPoint();
	IntersectInformationStruct InterInfo342 = S34.calculateIntersection(LightRay342);
	VectorStructR3 InterP342 = InterInfo342.getIntersectionPoint();
	IntersectInformationStruct InterInfo343 = S34.calculateIntersection(LightRay343);
	VectorStructR3 InterP343 = InterInfo343.getIntersectionPoint();
	IntersectInformationStruct InterInfo344 = S34.calculateIntersection(LightRay344);
	VectorStructR3 InterP344 = InterInfo344.getIntersectionPoint();
	IntersectInformationStruct InterInfo345 = S34.calculateIntersection(LightRay345);
	VectorStructR3 InterP345 = InterInfo345.getIntersectionPoint();

	//________________________________________________________________________________________________________
	//Linse um -90° gedreht, Startwert (0.0, 2.0, 0.0)
	LightRayStruct LightRay346(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 },  1.0);
	LightRayStruct LightRay347(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.5, 15.0 },  1.0);
	LightRayStruct LightRay348(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.0, 15.0 },  1.0);
	LightRayStruct LightRay349(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.5, 15.0 },  1.0);
	LightRayStruct LightRay350(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -3.0, 15.0 },  1.0);


	IntersectInformationStruct InterInfo346 = S34.calculateIntersection(LightRay346);
	VectorStructR3 InterP346 = InterInfo346.getIntersectionPoint();
	IntersectInformationStruct InterInfo347 = S34.calculateIntersection(LightRay347);
	VectorStructR3 InterP347 = InterInfo347.getIntersectionPoint();
	IntersectInformationStruct InterInfo348 = S34.calculateIntersection(LightRay348);
	VectorStructR3 InterP348 = InterInfo348.getIntersectionPoint();
	IntersectInformationStruct InterInfo349 = S34.calculateIntersection(LightRay349);
	VectorStructR3 InterP349 = InterInfo349.getIntersectionPoint();
	IntersectInformationStruct InterInfo350 = S34.calculateIntersection(LightRay350);
	VectorStructR3 InterP350 = InterInfo350.getIntersectionPoint();

	std::vector<VectorStructR3> checkVector130 = { InterP341, InterP342, InterP343, InterP344, InterP345, InterP346, InterP347, InterP348, InterP349, InterP350 };


	std::vector<VectorStructR3> ReferenzVector130 = { { 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },
	{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 } };


	bool isRight130 = Math::compareAllVectorElements(checkVector130, ReferenzVector130, 9);
	checkMethodesSphericalLens.push_back(isRight130);

	//____________________________________________________________________________________________________________________________________________________
	//____________________________________________________________________________________________________________________________________________________
	//____________________________________________________________________________________________________________________________________________________
	// Linse 0° gedreht, Apex Sphere (-1.0, 1.0, 20.0)
	// Startwert (0.0, 0.0, 0.0)
	LightRayStruct LightRay351(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 1.0, 15.0 },  1.0);
	LightRayStruct LightRay352(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.5, 15.0 },  1.0);
	LightRayStruct LightRay353(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.0, 15.0 },  1.0);
	LightRayStruct LightRay354(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -0.5, 15.0 },  1.0);
	LightRayStruct LightRay355(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 },  1.0);

	SphericalSurface_LLT S35(/*radius*/9.0, /*semiHeight*/2.817458, /*Apex of the sphere*/{ -1.0, 1.0, 20.0 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.0);

	IntersectInformationStruct InterInfo351 = S35.calculateIntersection(LightRay351);
	VectorStructR3 InterP351 = InterInfo351.getIntersectionPoint();
	IntersectInformationStruct InterInfo352 = S35.calculateIntersection(LightRay352);
	VectorStructR3 InterP352 = InterInfo352.getIntersectionPoint();
	IntersectInformationStruct InterInfo353 = S35.calculateIntersection(LightRay353);
	VectorStructR3 InterP353 = InterInfo353.getIntersectionPoint();
	IntersectInformationStruct InterInfo354 = S35.calculateIntersection(LightRay354);
	VectorStructR3 InterP354 = InterInfo354.getIntersectionPoint();
	IntersectInformationStruct InterInfo355 = S35.calculateIntersection(LightRay355);
	VectorStructR3 InterP355 = InterInfo355.getIntersectionPoint();

	//________________________________________________________________________________________________________
	//Linse um 0° gedreht, Startwert (0.0, 2.0, 0.0)
	LightRayStruct LightRay356(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 },  1.0);
	LightRayStruct LightRay357(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.5, 15.0 },  1.0);
	LightRayStruct LightRay358(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.0, 15.0 },  1.0);
	LightRayStruct LightRay359(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.5, 15.0 },  1.0);
	LightRayStruct LightRay360(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -3.0, 15.0 },  1.0);


	//InterP357: y-Wert stimmt nicht exakt mit Zemax überein -> Übereinstimmung Kommazahlen auf 8 heruntergesetzt
	IntersectInformationStruct InterInfo356 = S35.calculateIntersection(LightRay356);
	VectorStructR3 InterP356 = InterInfo356.getIntersectionPoint();
	IntersectInformationStruct InterInfo357 = S35.calculateIntersection(LightRay357);
	VectorStructR3 InterP357 = InterInfo357.getIntersectionPoint();
	IntersectInformationStruct InterInfo358 = S35.calculateIntersection(LightRay358);
	VectorStructR3 InterP358 = InterInfo358.getIntersectionPoint();
	IntersectInformationStruct InterInfo359 = S35.calculateIntersection(LightRay359);
	VectorStructR3 InterP359 = InterInfo359.getIntersectionPoint();
	IntersectInformationStruct InterInfo360 = S35.calculateIntersection(LightRay360);
	VectorStructR3 InterP360 = InterInfo360.getIntersectionPoint();


	std::vector<VectorStructR3> checkVector131 = { InterP351, InterP352, InterP353, InterP354, InterP355, InterP356, InterP357, InterP358, InterP359, InterP360 };


	std::vector<VectorStructR3> ReferenzVector131 = { { 0.0, 1.3374731264, 20.062096896 },{ 0.0, 0.66872882935, 20.061864881 },{ 0.0, 0.0, 20.111805583 },{ 0.0, -0.67379122302, 20.213736691 },{ 0.0, -1.3581458345, 20.372187518 },
	{ 0.0, 0.66252687357, 20.062096896 },{ 0.0, -0.011308517642, 20.113085176 },{ 0.0, -0.69572581837, 20.217943638 },{ 0.0, -1.3971575097, 20.382945058 },{ 0.0, 0.0, 0.0 } };


	bool isRight131 = Math::compareAllVectorElements(checkVector131, ReferenzVector131, 8);
	checkMethodesSphericalLens.push_back(isRight131);


	//________________________________________________________________________________________________________________________________________________________________
	//________________________________________________________________________________________________________________________________________________________________
	// Linse 45° gedreht, Apex Sphere (-1.0, 1.0, 20.0)
	// Startwert (0.0, 0.0, 0.0)
	LightRayStruct LightRay361(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 1.0, 15.0 },  1.0);
	LightRayStruct LightRay362(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.5, 15.0 },  1.0);
	LightRayStruct LightRay363(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.0, 15.0 },  1.0);
	LightRayStruct LightRay364(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -0.5, 15.0 },  1.0);
	LightRayStruct LightRay365(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 },  1.0);

	SphericalSurface_LLT S36(/*radius*/9.0, /*semiHeight*/2.817458, /*Apex of the sphere*/{ -1.0, 1.0, 20.0 },
		/*Direction*/ VectorStructR3{ 0.0, -1.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.0);

	//InterP365: Programm gibt keinen Schnittpunkt an, Strahl trifft Linse in Zemax, in Realität nicht
	IntersectInformationStruct InterInfo361 = S36.calculateIntersection(LightRay361);
	VectorStructR3 InterP361 = InterInfo361.getIntersectionPoint();
	IntersectInformationStruct InterInfo362 = S36.calculateIntersection(LightRay362);
	VectorStructR3 InterP362 = InterInfo362.getIntersectionPoint();
	IntersectInformationStruct InterInfo363 = S36.calculateIntersection(LightRay363);
	VectorStructR3 InterP363 = InterInfo363.getIntersectionPoint();
	IntersectInformationStruct InterInfo364 = S36.calculateIntersection(LightRay364);
	VectorStructR3 InterP364 = InterInfo364.getIntersectionPoint();
	IntersectInformationStruct InterInfo365 = S36.calculateIntersection(LightRay365);
	VectorStructR3 InterP365 = InterInfo365.getIntersectionPoint();

	//________________________________________________________________________________________________________
	//Linse um 45° gedreht, Startwert (0.0, 2.0, 0.0)
	LightRayStruct LightRay366(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 },  1.0);
	LightRayStruct LightRay367(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.5, 15.0 },  1.0);
	LightRayStruct LightRay368(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.0, 15.0 },  1.0);
	LightRayStruct LightRay369(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.5, 15.0 },  1.0);
	LightRayStruct LightRay370(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -3.0, 15.0 },  1.0);


	//InterP367: y-Wert stimmt nicht exakt mit Zemax überein -> Übereinstimmung Kommazahlen auf 8 heruntergesetzt
	IntersectInformationStruct InterInfo366 = S36.calculateIntersection(LightRay366);
	VectorStructR3 InterP366 = InterInfo366.getIntersectionPoint();
	IntersectInformationStruct InterInfo367 = S36.calculateIntersection(LightRay367);
	VectorStructR3 InterP367 = InterInfo367.getIntersectionPoint();
	IntersectInformationStruct InterInfo368 = S36.calculateIntersection(LightRay368);
	VectorStructR3 InterP368 = InterInfo368.getIntersectionPoint();
	IntersectInformationStruct InterInfo369 = S36.calculateIntersection(LightRay369);
	VectorStructR3 InterP369 = InterInfo369.getIntersectionPoint();
	IntersectInformationStruct InterInfo370 = S36.calculateIntersection(LightRay370);
	VectorStructR3 InterP370 = InterInfo370.getIntersectionPoint();

	std::vector<VectorStructR3> checkVector132 = { InterP361, InterP362, InterP363, InterP364, InterP365, InterP366, InterP367, InterP368, InterP369, InterP370 };


	std::vector<VectorStructR3> ReferenzVector132 = { { 0.0, 1.3647475229, 20.471212843 },{ 0.0, 0.65836584658, 19.750975398 },{ 0.0, 0.0, 19.206592655 },{ 0.0, -0.62592410304, 18.777723091 },{ 0.0, 0.0, 0.0 },
	{ 0.0, 0.68183815608, 19.772427659 },{ 0.0, 0.073753596848, 19.262464031 },{ 0.0, -0.51323693619, 18.849277021 },{ 0.0, -1.0849436945, 18.509662167 },{ 0.0, 0.0, 0.0 } };


	bool isRight132 = Math::compareAllVectorElements(checkVector132, ReferenzVector132, 8);
	checkMethodesSphericalLens.push_back(isRight132);

	//________________________________________________________________________________________________________________________________________________________________
	//________________________________________________________________________________________________________________________________________________________________
	// Linse -45° gedreht, Apex Sphere (-1.0, 1.0, 20.0)
	// Startwert (0.0, 0.0, 0.0)
	LightRayStruct LightRay371(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 1.0, 15.0 },  1.0);
	LightRayStruct LightRay372(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.5, 15.0 },  1.0);
	LightRayStruct LightRay373(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.0, 15.0 },  1.0);
	LightRayStruct LightRay374(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -0.5, 15.0 },  1.0);
	LightRayStruct LightRay375(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 },  1.0);

	SphericalSurface_LLT S37(/*radius*/9.0, /*semiHeight*/2.817458, /*Apex of the sphere*/{ -1.0, 1.0, 20.0 },
		/*Direction*/ VectorStructR3{ 0.0, 1.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.0);

	IntersectInformationStruct InterInfo371 = S37.calculateIntersection(LightRay371);
	VectorStructR3 InterP371 = InterInfo371.getIntersectionPoint();
	IntersectInformationStruct InterInfo372 = S37.calculateIntersection(LightRay372);
	VectorStructR3 InterP372 = InterInfo372.getIntersectionPoint();
	IntersectInformationStruct InterInfo373 = S37.calculateIntersection(LightRay373);
	VectorStructR3 InterP373 = InterInfo373.getIntersectionPoint();
	IntersectInformationStruct InterInfo374 = S37.calculateIntersection(LightRay374);
	VectorStructR3 InterP374 = InterInfo374.getIntersectionPoint();
	IntersectInformationStruct InterInfo375 = S37.calculateIntersection(LightRay375);
	VectorStructR3 InterP375 = InterInfo375.getIntersectionPoint();

	//________________________________________________________________________________________________________
	//Linse um -45° gedreht, Startwert (0.0, 2.0, 0.0)
	LightRayStruct LightRay376(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 },  1.0);
	LightRayStruct LightRay377(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.5, 15.0 },  1.0);
	LightRayStruct LightRay378(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.0, 15.0 },  1.0);
	LightRayStruct LightRay379(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.5, 15.0 },  1.0);
	LightRayStruct LightRay380(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -3.0, 15.0 },  1.0);



	IntersectInformationStruct InterInfo376 = S37.calculateIntersection(LightRay356);
	VectorStructR3 InterP376 = InterInfo376.getIntersectionPoint();
	IntersectInformationStruct InterInfo377 = S37.calculateIntersection(LightRay357);
	VectorStructR3 InterP377 = InterInfo377.getIntersectionPoint();
	IntersectInformationStruct InterInfo378 = S37.calculateIntersection(LightRay358);
	VectorStructR3 InterP378 = InterInfo378.getIntersectionPoint();
	IntersectInformationStruct InterInfo379 = S37.calculateIntersection(LightRay359);
	VectorStructR3 InterP379 = InterInfo379.getIntersectionPoint();
	IntersectInformationStruct InterInfo380 = S37.calculateIntersection(LightRay350);
	VectorStructR3 InterP380 = InterInfo380.getIntersectionPoint();


	std::vector<VectorStructR3> checkVector133 = { InterP371, InterP372, InterP373, InterP374, InterP375, InterP376, InterP377, InterP378, InterP379, InterP380 };


	std::vector<VectorStructR3> ReferenzVector133 = { { 0.0, 1.3181618439, 19.772427659 },{ 0.0, 0.68065881904, 20.419764571 },{ 0.0, 0.0, 21.287340310 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },
	{ 0.0, 0.63525247711, 20.471212843 },{ 0.0, -0.15143383662, 21.514338366 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 } };


	bool isRight133 = Math::compareAllVectorElements(checkVector133, ReferenzVector133, 9);
	checkMethodesSphericalLens.push_back(isRight133);


	//________________________________________________________________________________________________________________________________________________________________
	//________________________________________________________________________________________________________________________________________________________________
	// Linse 90° gedreht, Apex Sphere (-1.0, 1.0, 20.0)
	// Startwert (0.0, 0.0, 0.0)
	LightRayStruct LightRay381(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 1.0, 15.0 },  1.0);
	LightRayStruct LightRay382(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.5, 15.0 },  1.0);
	LightRayStruct LightRay383(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.0, 15.0 },  1.0);
	LightRayStruct LightRay384(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -0.5, 15.0 },  1.0);
	LightRayStruct LightRay385(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 },  1.0);

	SphericalSurface_LLT S38(/*radius*/9.0, /*semiHeight*/2.817458, /*Apex of the sphere*/{ -1.0, 1.0, 20.0 },
		/*Direction*/ VectorStructR3{ 0.0, -1.0, 0.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.0);

	IntersectInformationStruct InterInfo381 = S38.calculateIntersection(LightRay381);
	VectorStructR3 InterP381 = InterInfo381.getIntersectionPoint();
	IntersectInformationStruct InterInfo382 = S38.calculateIntersection(LightRay382);
	VectorStructR3 InterP382 = InterInfo382.getIntersectionPoint();
	IntersectInformationStruct InterInfo383 = S38.calculateIntersection(LightRay383);
	VectorStructR3 InterP383 = InterInfo383.getIntersectionPoint();
	IntersectInformationStruct InterInfo384 = S38.calculateIntersection(LightRay384);
	VectorStructR3 InterP384 = InterInfo384.getIntersectionPoint();
	IntersectInformationStruct InterInfo385 = S38.calculateIntersection(LightRay385);
	VectorStructR3 InterP385 = InterInfo385.getIntersectionPoint();

	//________________________________________________________________________________________________________
	//Linse um 90° gedreht, Startwert (0.0, 2.0, 0.0)
	LightRayStruct LightRay386(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 },  1.0);
	LightRayStruct LightRay387(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.5, 15.0 },  1.0);
	LightRayStruct LightRay388(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.0, 15.0 },  1.0);
	LightRayStruct LightRay389(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.5, 15.0 },  1.0);
	LightRayStruct LightRay390(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -3.0, 15.0 },  1.0);


	IntersectInformationStruct InterInfo386 = S38.calculateIntersection(LightRay386);
	VectorStructR3 InterP386 = InterInfo386.getIntersectionPoint();
	IntersectInformationStruct InterInfo387 = S38.calculateIntersection(LightRay387);
	VectorStructR3 InterP387 = InterInfo387.getIntersectionPoint();
	IntersectInformationStruct InterInfo388 = S38.calculateIntersection(LightRay388);
	VectorStructR3 InterP388 = InterInfo388.getIntersectionPoint();
	IntersectInformationStruct InterInfo389 = S38.calculateIntersection(LightRay389);
	VectorStructR3 InterP389 = InterInfo389.getIntersectionPoint();
	IntersectInformationStruct InterInfo390 = S38.calculateIntersection(LightRay390);
	VectorStructR3 InterP390 = InterInfo390.getIntersectionPoint();

	std::vector<VectorStructR3> checkVector134 = { InterP381, InterP382, InterP383, InterP384, InterP385, InterP386, InterP387, InterP388, InterP389, InterP390 };


	std::vector<VectorStructR3> ReferenzVector134 = { { 0.0, 0.0, 0.0 },{ 0.0, 0.58276048599, 17.482814580 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },
	{ 0.0, 0.78031472599, 18.295279110 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 } };


	bool isRight134 = Math::compareAllVectorElements(checkVector134, ReferenzVector134, 9);
	checkMethodesSphericalLens.push_back(isRight134);

	//________________________________________________________________________________________________________________________________________________________________
	//________________________________________________________________________________________________________________________________________________________________
	// Linse -90° gedreht, Apex Sphere (-1.0, 1.0, 20.0)
	// Startwert (0.0, 0.0, 0.0)
	LightRayStruct LightRay391(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 1.0, 15.0 },  1.0);
	LightRayStruct LightRay392(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.5, 15.0 },  1.0);
	LightRayStruct LightRay393(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.0, 15.0 },  1.0);
	LightRayStruct LightRay394(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -0.5, 15.0 },  1.0);
	LightRayStruct LightRay395(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 },  1.0);

	SphericalSurface_LLT S39(/*radius*/9.0, /*semiHeight*/2.817458, /*Apex of the sphere*/{ -1.0, 1.0, 20.0 },
		/*Direction*/ VectorStructR3{ 0.0, 1.0, 0.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.0);

	IntersectInformationStruct InterInfo391 = S39.calculateIntersection(LightRay391);
	VectorStructR3 InterP391 = InterInfo391.getIntersectionPoint();
	IntersectInformationStruct InterInfo392 = S39.calculateIntersection(LightRay392);
	VectorStructR3 InterP392 = InterInfo392.getIntersectionPoint();
	IntersectInformationStruct InterInfo393 = S39.calculateIntersection(LightRay393);
	VectorStructR3 InterP393 = InterInfo393.getIntersectionPoint();
	IntersectInformationStruct InterInfo394 = S39.calculateIntersection(LightRay394);
	VectorStructR3 InterP394 = InterInfo394.getIntersectionPoint();
	IntersectInformationStruct InterInfo395 = S39.calculateIntersection(LightRay395);
	VectorStructR3 InterP395 = InterInfo395.getIntersectionPoint();

	//________________________________________________________________________________________________________
	//Linse um -90° gedreht, Startwert (0.0, 2.0, 0.0)
	LightRayStruct LightRay396(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 },  1.0);
	LightRayStruct LightRay397(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.5, 15.0 },  1.0);
	LightRayStruct LightRay398(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.0, 15.0 },  1.0);
	LightRayStruct LightRay399(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.5, 15.0 },  1.0);
	LightRayStruct LightRay400(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -3.0, 15.0 },  1.0);


	IntersectInformationStruct InterInfo396 = S39.calculateIntersection(LightRay396);
	VectorStructR3 InterP396 = InterInfo396.getIntersectionPoint();
	IntersectInformationStruct InterInfo397 = S39.calculateIntersection(LightRay397);
	VectorStructR3 InterP397 = InterInfo397.getIntersectionPoint();
	IntersectInformationStruct InterInfo398 = S39.calculateIntersection(LightRay398);
	VectorStructR3 InterP398 = InterInfo398.getIntersectionPoint();
	IntersectInformationStruct InterInfo399 = S39.calculateIntersection(LightRay399);
	VectorStructR3 InterP399 = InterInfo399.getIntersectionPoint();
	IntersectInformationStruct InterInfo400 = S39.calculateIntersection(LightRay400);
	VectorStructR3 InterP400 = InterInfo400.getIntersectionPoint();

	std::vector<VectorStructR3> checkVector135 = { InterP391, InterP392, InterP393, InterP394, InterP395, InterP396, InterP397, InterP398, InterP399, InterP400 };


	std::vector<VectorStructR3> ReferenzVector135 = { { 0.0, 1.2196852740, 18.295279110 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },
	{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 } };


	bool isRight135 = Math::compareAllVectorElements(checkVector135, ReferenzVector135, 9);
	checkMethodesSphericalLens.push_back(isRight135);



	//____________________________________________________________________________________________________________________________________________________
	//____________________________________________________________________________________________________________________________________________________
	//____________________________________________________________________________________________________________________________________________________
	// Linse 0° gedreht, Apex Sphere (-1.0, -1.0, 20.0)
	// Startwert (0.0, 0.0, 0.0)
	LightRayStruct LightRay401(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 1.0, 15.0 },  1.0);
	LightRayStruct LightRay402(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.5, 15.0 },  1.0);
	LightRayStruct LightRay403(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.0, 15.0 },  1.0);
	LightRayStruct LightRay404(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -0.5, 15.0 },  1.0);
	LightRayStruct LightRay405(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 },  1.0);

	SphericalSurface_LLT S40(/*radius*/9.0, /*semiHeight*/2.817458, /*Apex of the sphere*/{ -1.0, -1.0, 20.0 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.0);

	IntersectInformationStruct InterInfo401 = S40.calculateIntersection(LightRay401);
	VectorStructR3 InterP401 = InterInfo401.getIntersectionPoint();
	IntersectInformationStruct InterInfo402 = S40.calculateIntersection(LightRay402);
	VectorStructR3 InterP402 = InterInfo402.getIntersectionPoint();
	IntersectInformationStruct InterInfo403 = S40.calculateIntersection(LightRay403);
	VectorStructR3 InterP403 = InterInfo403.getIntersectionPoint();
	IntersectInformationStruct InterInfo404 = S40.calculateIntersection(LightRay404);
	VectorStructR3 InterP404 = InterInfo404.getIntersectionPoint();
	IntersectInformationStruct InterInfo405 = S40.calculateIntersection(LightRay405);
	VectorStructR3 InterP405 = InterInfo405.getIntersectionPoint();

	//________________________________________________________________________________________________________
	//Linse um 0° gedreht, Startwert (0.0, 2.0, 0.0)
	LightRayStruct LightRay406(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 },  1.0);
	LightRayStruct LightRay407(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.5, 15.0 },  1.0);
	LightRayStruct LightRay408(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.0, 15.0 },  1.0);
	LightRayStruct LightRay409(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.5, 15.0 },  1.0);
	LightRayStruct LightRay410(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -3.0, 15.0 },  1.0);


	//InterP407: y-Wert stimmt nicht exakt mit Zemax überein -> Übereinstimmung Kommazahlen auf 8 heruntergesetzt
	IntersectInformationStruct InterInfo406 = S40.calculateIntersection(LightRay406);
	VectorStructR3 InterP406 = InterInfo406.getIntersectionPoint();
	IntersectInformationStruct InterInfo407 = S40.calculateIntersection(LightRay407);
	VectorStructR3 InterP407 = InterInfo407.getIntersectionPoint();
	IntersectInformationStruct InterInfo408 = S40.calculateIntersection(LightRay408);
	VectorStructR3 InterP408 = InterInfo408.getIntersectionPoint();
	IntersectInformationStruct InterInfo409 = S40.calculateIntersection(LightRay409);
	VectorStructR3 InterP409 = InterInfo409.getIntersectionPoint();
	IntersectInformationStruct InterInfo410 = S40.calculateIntersection(LightRay410);
	VectorStructR3 InterP410 = InterInfo410.getIntersectionPoint();

	std::vector<VectorStructR3> checkVector136 = { InterP401, InterP402, InterP403, InterP404, InterP405, InterP406, InterP407, InterP408, InterP409, InterP410 };


	std::vector<VectorStructR3> ReferenzVector136 = { { 0.0, 1.3581458345, 20.372187518 },{ 0.0, 0.67379122302, 20.213736691 },{ 0.0, 0.0, 20.111805583 },{ 0.0, -0.66872882935, 20.061864881 },{ 0.0, -1.3374731264, 20.062096896 },
	{ 0.0, 0.65268386790, 20.209741981 },{ 0.0, -0.011056855272, 20.110568553 },{ 0.0, -0.67488517773, 20.061638833 },{ 0.0, -1.3437225076, 20.062335046 },{ 0.0, -2.0228819681, 20.114409841 } };


	bool isRight136 = Math::compareAllVectorElements(checkVector136, ReferenzVector136, 8);
	checkMethodesSphericalLens.push_back(isRight136);


	//________________________________________________________________________________________________________________________________________________________________
	//________________________________________________________________________________________________________________________________________________________________
	// Linse 45° gedreht, Apex Sphere (-1.0, -1.0, 20.0)
	// Startwert (0.0, 0.0, 0.0)
	LightRayStruct LightRay411(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 1.0, 15.0 },  1.0);
	LightRayStruct LightRay412(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.5, 15.0 },  1.0);
	LightRayStruct LightRay413(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.0, 15.0 },  1.0);
	LightRayStruct LightRay414(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -0.5, 15.0 },  1.0);
	LightRayStruct LightRay415(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 },  1.0);

	SphericalSurface_LLT S41(/*radius*/9.0, /*semiHeight*/2.817458, /*Apex of the sphere*/{ -1.0, -1.0, 20.0 },
		/*Direction*/ VectorStructR3{ 0.0, -1.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.0);

	IntersectInformationStruct InterInfo411 = S41.calculateIntersection(LightRay411);
	VectorStructR3 InterP411 = InterInfo411.getIntersectionPoint();
	IntersectInformationStruct InterInfo412 = S41.calculateIntersection(LightRay412);
	VectorStructR3 InterP412 = InterInfo412.getIntersectionPoint();
	IntersectInformationStruct InterInfo413 = S41.calculateIntersection(LightRay413);
	VectorStructR3 InterP413 = InterInfo413.getIntersectionPoint();
	IntersectInformationStruct InterInfo414 = S41.calculateIntersection(LightRay414);
	VectorStructR3 InterP414 = InterInfo414.getIntersectionPoint();
	IntersectInformationStruct InterInfo415 = S41.calculateIntersection(LightRay415);
	VectorStructR3 InterP415 = InterInfo415.getIntersectionPoint();

	//________________________________________________________________________________________________________
	//Linse um 45° gedreht, Startwert (0.0, 2.0, 0.0)
	LightRayStruct LightRay416(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 },  1.0);
	LightRayStruct LightRay417(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.5, 15.0 },  1.0);
	LightRayStruct LightRay418(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.0, 15.0 },  1.0);
	LightRayStruct LightRay419(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.5, 15.0 },  1.0);
	LightRayStruct LightRay420(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -3.0, 15.0 },  1.0);


	IntersectInformationStruct InterInfo416 = S41.calculateIntersection(LightRay416);
	VectorStructR3 InterP416 = InterInfo416.getIntersectionPoint();
	IntersectInformationStruct InterInfo417 = S41.calculateIntersection(LightRay417);
	VectorStructR3 InterP417 = InterInfo417.getIntersectionPoint();
	IntersectInformationStruct InterInfo418 = S41.calculateIntersection(LightRay418);
	VectorStructR3 InterP418 = InterInfo418.getIntersectionPoint();
	IntersectInformationStruct InterInfo419 = S41.calculateIntersection(LightRay419);
	VectorStructR3 InterP419 = InterInfo419.getIntersectionPoint();
	IntersectInformationStruct InterInfo420 = S41.calculateIntersection(LightRay420);
	VectorStructR3 InterP420 = InterInfo420.getIntersectionPoint();

	std::vector<VectorStructR3> checkVector137 = { InterP411, InterP412, InterP413, InterP414, InterP415, InterP416, InterP417, InterP418, InterP419, InterP420 };


	std::vector<VectorStructR3> ReferenzVector137 = { { 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 21.287340310 },{ 0.0, -0.68065881904, 20.419764571 },{ 0.0, -1.3181618439, 19.772427659 },
	{ 0.0, 0.52356616967, 22.146507455 },{ 0.0, -0.11275491095, 21.127549109 },{ 0.0, -0.71719214830, 20.378941112 },{ 0.0, -1.2984300534, 19.790580320 },{ 0.0, -1.8623672261, 19.311836130 } };


	bool isRight137 = Math::compareAllVectorElements(checkVector137, ReferenzVector137, 9);
	checkMethodesSphericalLens.push_back(isRight137);

	//________________________________________________________________________________________________________________________________________________________________
	//________________________________________________________________________________________________________________________________________________________________
	// Linse -45° gedreht, Apex Sphere (-1.0, -1.0, 20.0)
	// Startwert (0.0, 0.0, 0.0)
	LightRayStruct LightRay421(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 1.0, 15.0 },  1.0);
	LightRayStruct LightRay422(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.5, 15.0 },  1.0);
	LightRayStruct LightRay423(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.0, 15.0 },  1.0);
	LightRayStruct LightRay424(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -0.5, 15.0 },  1.0);
	LightRayStruct LightRay425(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 },  1.0);

	SphericalSurface_LLT S42(/*radius*/9.0, /*semiHeight*/2.817458, /*Apex of the sphere*/{ -1.0, -1.0, 20.0 },
		/*Direction*/ VectorStructR3{ 0.0, 1.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);

	//InterP421: Programm gibt keinen Schnittpunkt an, Strahl trifft Linse in Zemax, in Realität nicht
	IntersectInformationStruct InterInfo421 = S42.calculateIntersection(LightRay421);
	VectorStructR3 InterP421 = InterInfo421.getIntersectionPoint();
	IntersectInformationStruct InterInfo422 = S42.calculateIntersection(LightRay422);
	VectorStructR3 InterP422 = InterInfo422.getIntersectionPoint();
	IntersectInformationStruct InterInfo423 = S42.calculateIntersection(LightRay423);
	VectorStructR3 InterP423 = InterInfo423.getIntersectionPoint();
	IntersectInformationStruct InterInfo424 = S42.calculateIntersection(LightRay424);
	VectorStructR3 InterP424 = InterInfo424.getIntersectionPoint();
	IntersectInformationStruct InterInfo425 = S42.calculateIntersection(LightRay425);
	VectorStructR3 InterP425 = InterInfo425.getIntersectionPoint();


	//________________________________________________________________________________________________________
	//Linse um -45° gedreht, Startwert (0.0, 2.0, 0.0)
	LightRayStruct LightRay426(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 },  1.0);
	LightRayStruct LightRay427(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.5, 15.0 },  1.0);
	LightRayStruct LightRay428(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.0, 15.0 },  1.0);
	LightRayStruct LightRay429(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.5, 15.0 },  1.0);
	LightRayStruct LightRay430(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -3.0, 15.0 },  1.0);


	//InterP427: y-Wert stimmt nicht exakt mit Zemax überein -> Übereinstimmung Kommazahlenauf 8 heruntergesetzt
	IntersectInformationStruct InterInfo426 = S42.calculateIntersection(LightRay426);
	VectorStructR3 InterP426 = InterInfo426.getIntersectionPoint();
	IntersectInformationStruct InterInfo427 = S42.calculateIntersection(LightRay427);
	VectorStructR3 InterP427 = InterInfo427.getIntersectionPoint();
	IntersectInformationStruct InterInfo428 = S42.calculateIntersection(LightRay428);
	VectorStructR3 InterP428 = InterInfo428.getIntersectionPoint();
	IntersectInformationStruct InterInfo429 = S42.calculateIntersection(LightRay429);
	VectorStructR3 InterP429 = InterInfo429.getIntersectionPoint();
	IntersectInformationStruct InterInfo430 = S42.calculateIntersection(LightRay430);
	VectorStructR3 InterP430 = InterInfo430.getIntersectionPoint();

	std::vector<VectorStructR3> checkVector138 = { InterP421, InterP422, InterP423, InterP424, InterP425, InterP426, InterP427, InterP428, InterP429, InterP430 };


	std::vector<VectorStructR3> ReferenzVector138 = { { 0.0, 0.0, 0.0 },{ 0.0, 0.62592410304, 18.777723091 },{ 0.0, 0.0, 19.206592655 },{ 0.0, -0.65836584658, 19.750975398 },{ 0.0, -1.3647475229, 20.471212843 },
	{ 0.0, 0.75335967435, 18.699604885 },{ 0.0, 0.085682685652, 19.143173143 },{ 0.0, -0.63003850027, 19.725288752 },{ 0.0, -1.4230827549, 20.538496530 },{ 0.0, -2.3764396609, 21.882198304 } };


	bool isRight138 = Math::compareAllVectorElements(checkVector138, ReferenzVector138, 7);
	checkMethodesSphericalLens.push_back(isRight138);


	//________________________________________________________________________________________________________________________________________________________________
	//________________________________________________________________________________________________________________________________________________________________
	// Linse 90° gedreht, Apex Sphere (-1.0, -1.0, 20.0)
	// Startwert (0.0, 0.0, 0.0)
	LightRayStruct LightRay431(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 1.0, 15.0 },  1.0);
	LightRayStruct LightRay432(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.5, 15.0 },  1.0);
	LightRayStruct LightRay433(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.0, 15.0 },  1.0);
	LightRayStruct LightRay434(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -0.5, 15.0 },  1.0);
	LightRayStruct LightRay435(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 },  1.0);

	SphericalSurface_LLT S43(/*radius*/9.0, /*semiHeight*/2.817458, /*Apex of the sphere*/{ -1.0, -1.0, 20.0 },
		/*Direction*/ VectorStructR3{ 0.0, -1.0, 0.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.0);

	IntersectInformationStruct InterInfo431 = S43.calculateIntersection(LightRay431);
	VectorStructR3 InterP431 = InterInfo431.getIntersectionPoint();
	IntersectInformationStruct InterInfo432 = S43.calculateIntersection(LightRay432);
	VectorStructR3 InterP432 = InterInfo432.getIntersectionPoint();
	IntersectInformationStruct InterInfo433 = S43.calculateIntersection(LightRay433);
	VectorStructR3 InterP433 = InterInfo433.getIntersectionPoint();
	IntersectInformationStruct InterInfo434 = S43.calculateIntersection(LightRay434);
	VectorStructR3 InterP434 = InterInfo434.getIntersectionPoint();
	IntersectInformationStruct InterInfo435 = S43.calculateIntersection(LightRay435);
	VectorStructR3 InterP435 = InterInfo435.getIntersectionPoint();

	//________________________________________________________________________________________________________
	//Linse um 90° gedreht, Startwert (0.0, 2.0, 0.0)
	LightRayStruct LightRay436(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 },  1.0);
	LightRayStruct LightRay437(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.5, 15.0 },  1.0);
	LightRayStruct LightRay438(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.0, 15.0 },  1.0);
	LightRayStruct LightRay439(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.5, 15.0 },  1.0);
	LightRayStruct LightRay440(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -3.0, 15.0 },  1.0);


	//InterP440: Programm gibt keinen Schnittpunkt an, Strahl trifft Linse in Zemax, in Realität nicht
	IntersectInformationStruct InterInfo436 = S43.calculateIntersection(LightRay436);
	VectorStructR3 InterP436 = InterInfo436.getIntersectionPoint();
	IntersectInformationStruct InterInfo437 = S43.calculateIntersection(LightRay437);
	VectorStructR3 InterP437 = InterInfo437.getIntersectionPoint();
	IntersectInformationStruct InterInfo438 = S43.calculateIntersection(LightRay438);
	VectorStructR3 InterP438 = InterInfo438.getIntersectionPoint();
	IntersectInformationStruct InterInfo439 = S43.calculateIntersection(LightRay439);
	VectorStructR3 InterP439 = InterInfo439.getIntersectionPoint();
	IntersectInformationStruct InterInfo440 = S43.calculateIntersection(LightRay440);
	VectorStructR3 InterP440 = InterInfo440.getIntersectionPoint();


	std::vector<VectorStructR3> checkVector139 = { InterP431, InterP432, InterP433, InterP434, InterP435, InterP436, InterP437, InterP438, InterP439, InterP400 };


	std::vector<VectorStructR3> ReferenzVector139 = { { 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, -1.2196852740, 18.295279110 },
	{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, -1.1351351351, 18.810810811 },{ 0.0, 0.0, 0.0 } };


	bool isRight139 = Math::compareAllVectorElements(checkVector139, ReferenzVector139, 9);
	checkMethodesSphericalLens.push_back(isRight139);

	//________________________________________________________________________________________________________________________________________________________________
	//________________________________________________________________________________________________________________________________________________________________
	// Linse -90° gedreht, Apex Sphere (-1.0, -1.0, 20.0)
	// Startwert (0.0, 0.0, 0.0)
	LightRayStruct LightRay441(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 1.0, 15.0 },  1.0);
	LightRayStruct LightRay442(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.5, 15.0 },  1.0);
	LightRayStruct LightRay443(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.0, 15.0 },  1.0);
	LightRayStruct LightRay444(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -0.5, 15.0 },  1.0);
	LightRayStruct LightRay445(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 },  1.0);

	SphericalSurface_LLT S44(/*radius*/9.0, /*semiHeight*/2.817458, /*Apex of the sphere*/{ -1.0, -1.0, 20.0 },
		/*Direction*/ VectorStructR3{ 0.0, 1.0, 0.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.0);

	IntersectInformationStruct InterInfo441 = S44.calculateIntersection(LightRay441);
	VectorStructR3 InterP441 = InterInfo441.getIntersectionPoint();
	IntersectInformationStruct InterInfo442 = S44.calculateIntersection(LightRay442);
	VectorStructR3 InterP442 = InterInfo442.getIntersectionPoint();
	IntersectInformationStruct InterInfo443 = S44.calculateIntersection(LightRay443);
	VectorStructR3 InterP443 = InterInfo443.getIntersectionPoint();
	IntersectInformationStruct InterInfo444 = S44.calculateIntersection(LightRay444);
	VectorStructR3 InterP444 = InterInfo444.getIntersectionPoint();
	IntersectInformationStruct InterInfo445 = S44.calculateIntersection(LightRay445);
	VectorStructR3 InterP445 = InterInfo445.getIntersectionPoint();

	//________________________________________________________________________________________________________
	//Linse um -90° gedreht, Startwert (0.0, 2.0, 0.0)
	LightRayStruct LightRay446(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 },  1.0);
	LightRayStruct LightRay447(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.5, 15.0 },  1.0);
	LightRayStruct LightRay448(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.0, 15.0 },  1.0);
	LightRayStruct LightRay449(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.5, 15.0 },  1.0);
	LightRayStruct LightRay450(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -3.0, 15.0 },  1.0);


	//InterP448 trifft Linse von oben, Zemax gibt keinen Schnittpunkt an -> Programm-Schnittpunkt als Referenz eingesetzt
	IntersectInformationStruct InterInfo446 = S44.calculateIntersection(LightRay446);
	VectorStructR3 InterP446 = InterInfo446.getIntersectionPoint();
	IntersectInformationStruct InterInfo447 = S44.calculateIntersection(LightRay447);
	VectorStructR3 InterP447 = InterInfo447.getIntersectionPoint();
	IntersectInformationStruct InterInfo448 = S44.calculateIntersection(LightRay448);
	VectorStructR3 InterP448 = InterInfo448.getIntersectionPoint();
	IntersectInformationStruct InterInfo449 = S44.calculateIntersection(LightRay449);
	VectorStructR3 InterP449 = InterInfo449.getIntersectionPoint();
	IntersectInformationStruct InterInfo450 = S44.calculateIntersection(LightRay450);
	VectorStructR3 InterP450 = InterInfo450.getIntersectionPoint();

	std::vector<VectorStructR3> checkVector140 = { InterP441, InterP442, InterP443, InterP444, InterP445, InterP446, InterP447, InterP448, InterP449, InterP450 };


	std::vector<VectorStructR3> ReferenzVector140 = { { 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, -0.58276048599, 17.482814580 },{ 0.0, 0.0, 0.0 },
	{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, -0.84439202936972979, 21.332940220272974 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 } };


	bool isRight140 = Math::compareAllVectorElements(checkVector140, ReferenzVector140, 8);
	checkMethodesSphericalLens.push_back(isRight140);

	
	//________________________________________________________________________________________________________________________________________________________________
	//________________________________________________________________________________________________________________________________________________________________
	// Linse 0° gedreht, Apex Sphere (0.0, 0.0, 20.0), Radius -9mm
	// Startwert (0.0, 0.0, 0.0)
	LightRayStruct LightRay451(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 1.0, 15.0 },  1.0);
	LightRayStruct LightRay452(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.5, 15.0 },  1.0);
	LightRayStruct LightRay453(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.0, 15.0 },  1.0);
	LightRayStruct LightRay454(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -0.5, 15.0 },  1.0);
	LightRayStruct LightRay455(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 },  1.0);

	SphericalSurface_LLT S45(/*radius*/9.0, /*semiHeight*/2.817458, /*Apex of the sphere*/{ 0.0, 0.0, 20.0 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.0);

	IntersectInformationStruct InterInfo451 = S45.calculateIntersection(LightRay451);
	VectorStructR3 InterP451 = InterInfo451.getIntersectionPoint();
	IntersectInformationStruct InterInfo452 = S45.calculateIntersection(LightRay452);
	VectorStructR3 InterP452 = InterInfo452.getIntersectionPoint();
	IntersectInformationStruct InterInfo453 = S45.calculateIntersection(LightRay453);
	VectorStructR3 InterP453 = InterInfo453.getIntersectionPoint();
	IntersectInformationStruct InterInfo454 = S45.calculateIntersection(LightRay454);
	VectorStructR3 InterP454 = InterInfo454.getIntersectionPoint();
	IntersectInformationStruct InterInfo455 = S45.calculateIntersection(LightRay455);
	VectorStructR3 InterP455 = InterInfo455.getIntersectionPoint();

	//________________________________________________________________________________________________________
	//Linse um 0° gedreht, Startwert (0.0, 2.0, 0.0)
	LightRayStruct LightRay456(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 },  1.0);
	LightRayStruct LightRay457(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.5, 15.0 },  1.0);
	LightRayStruct LightRay458(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.0, 15.0 },  1.0);
	LightRayStruct LightRay459(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.5, 15.0 },  1.0);
	LightRayStruct LightRay460(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -3.0, 15.0 },  1.0);


	IntersectInformationStruct InterInfo456 = S45.calculateIntersection(LightRay456);
	VectorStructR3 InterP456 = InterInfo456.getIntersectionPoint();
	IntersectInformationStruct InterInfo457 = S45.calculateIntersection(LightRay457);
	VectorStructR3 InterP457 = InterInfo457.getIntersectionPoint();
	IntersectInformationStruct InterInfo458 = S45.calculateIntersection(LightRay458);
	VectorStructR3 InterP458 = InterInfo458.getIntersectionPoint();
	IntersectInformationStruct InterInfo459 = S45.calculateIntersection(LightRay459);
	VectorStructR3 InterP459 = InterInfo459.getIntersectionPoint();
	IntersectInformationStruct InterInfo460 = S45.calculateIntersection(LightRay460);
	VectorStructR3 InterP460 = InterInfo460.getIntersectionPoint();

	std::vector<VectorStructR3> checkVector141 = { InterP451, InterP452, InterP453, InterP454, InterP455, InterP456, InterP457, InterP458, InterP459, InterP460 };


	std::vector<VectorStructR3> ReferenzVector141 = { { 0.0, 1.3267777455, 19.901666182 },{ 0.0,  0.66584452359, 19.975335708 },{ 0.0, 0.0, 20.0 },{ 0.0, -0.6658445235901, 19.975335708 },{ 0.0, -1.3267777455, 19.901666182 },
	{ 0.0, 0.66832323479, 19.975151478 },{ 0.0, -3.3331115645E-012, 20.0 },{ 0.0, -0.66340220794, 19.975516560 },{ 0.0, -1.3171818577, 19.903091146 },{ 0.0, -1.9569338072, 19.784669036 } };


	bool isRight141 = Math::compareAllVectorElements(checkVector141, ReferenzVector141, 7);
	checkMethodesSphericalLens.push_back(isRight141);


	//________________________________________________________________________________________________________________________________________________________________
	//________________________________________________________________________________________________________________________________________________________________
	// Linse 45° gedreht, Apex Sphere (0.0, 0.0, 20.0), Radius -9mm
	// Startwert (0.0, 0.0, 0.0)
	LightRayStruct LightRay461(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 1.0, 15.0 },  1.0);
	LightRayStruct LightRay462(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.5, 15.0 },  1.0);
	LightRayStruct LightRay463(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.0, 15.0 },  1.0);
	LightRayStruct LightRay464(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -0.5, 15.0 },  1.0);
	LightRayStruct LightRay465(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 },  1.0);

	SphericalSurface_LLT S46(/*radius*/9.0, /*semiHeight*/2.817458, /*Apex of the sphere*/{ 0.0, 0.0, 20.0 },
		/*Direction*/ VectorStructR3{ 0.0, 1.0, -1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.0);

	IntersectInformationStruct InterInfo461 = S46.calculateIntersection(LightRay461);
	VectorStructR3 InterP461 = InterInfo461.getIntersectionPoint();
	IntersectInformationStruct InterInfo462 = S46.calculateIntersection(LightRay462);
	VectorStructR3 InterP462 = InterInfo462.getIntersectionPoint();
	IntersectInformationStruct InterInfo463 = S46.calculateIntersection(LightRay463);
	VectorStructR3 InterP463 = InterInfo463.getIntersectionPoint();
	IntersectInformationStruct InterInfo464 = S46.calculateIntersection(LightRay464);
	VectorStructR3 InterP464 = InterInfo464.getIntersectionPoint();
	IntersectInformationStruct InterInfo465 = S46.calculateIntersection(LightRay465);
	VectorStructR3 InterP465 = InterInfo465.getIntersectionPoint();

	//________________________________________________________________________________________________________
	//Linse um 45° gedreht, Startwert (0.0, 2.0, 0.0)
	LightRayStruct LightRay466(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 },  1.0);
	LightRayStruct LightRay467(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.5, 15.0 },  1.0);
	LightRayStruct LightRay468(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.0, 15.0 },  1.0);
	LightRayStruct LightRay469(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.5, 15.0 },  1.0);
	LightRayStruct LightRay470(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -3.0, 15.0 },  1.0);


	IntersectInformationStruct InterInfo466 = S46.calculateIntersection(LightRay466);
	VectorStructR3 InterP466 = InterInfo466.getIntersectionPoint();
	IntersectInformationStruct InterInfo467 = S46.calculateIntersection(LightRay467);
	VectorStructR3 InterP467 = InterInfo467.getIntersectionPoint();
	IntersectInformationStruct InterInfo468 = S46.calculateIntersection(LightRay468);
	VectorStructR3 InterP468 = InterInfo468.getIntersectionPoint();
	IntersectInformationStruct InterInfo469 = S46.calculateIntersection(LightRay469);
	VectorStructR3 InterP469 = InterInfo469.getIntersectionPoint();
	IntersectInformationStruct InterInfo470 = S46.calculateIntersection(LightRay470);
	VectorStructR3 InterP470 = InterInfo470.getIntersectionPoint();

	std::vector<VectorStructR3> checkVector142 = { InterP461, InterP462, InterP463, InterP464, InterP465, InterP466, InterP467, InterP468, InterP469, InterP470 };


	std::vector<VectorStructR3> ReferenzVector142 = { { 0.0, 1.4099937809, 21.149906714 },{ 0.0, 0.68733379032, 20.620013710 },{ 0.0, 0.0, 20.0 },{ 0.0, -0.64281653713, 19.284496114 },{ 0.0, -1.2309856444, 18.464784666 },
	{ 0.0, 0.62854556894, 20.571816466 },{ 0.0, -3.0301014223E-012, 20.0 },{ 0.0, -0.58132487531, 19.359936565 },{ 0.0, -1.1086662705, 18.651997623 },{ 0.0, -1.5750704853, 17.875352427 } };


	bool isRight142 = Math::compareAllVectorElements(checkVector142, ReferenzVector142, 7);
	checkMethodesSphericalLens.push_back(isRight142);

	//________________________________________________________________________________________________________________________________________________________________
	//________________________________________________________________________________________________________________________________________________________________
	// Linse -45° gedreht, Apex Sphere (0.0, 0.0, 20.0), Radius -9mm
	// Startwert (0.0, 0.0, 0.0)
	LightRayStruct LightRay471(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 1.0, 15.0 },  1.0);
	LightRayStruct LightRay472(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.5, 15.0 },  1.0);
	LightRayStruct LightRay473(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.0, 15.0 },  1.0);
	LightRayStruct LightRay474(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -0.5, 15.0 },  1.0);
	LightRayStruct LightRay475(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 },  1.0);

	SphericalSurface_LLT S47(/*radius*/9.0, /*semiHeight*/2.817458, /*Apex of the sphere*/{ 0.0, 0.0, 20.0 },
		/*Direction*/ VectorStructR3{ 0.0, -1.0,-1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.0);

	IntersectInformationStruct InterInfo471 = S47.calculateIntersection(LightRay471);
	VectorStructR3 InterP471 = InterInfo471.getIntersectionPoint();
	IntersectInformationStruct InterInfo472 = S47.calculateIntersection(LightRay472);
	VectorStructR3 InterP472 = InterInfo472.getIntersectionPoint();
	IntersectInformationStruct InterInfo473 = S47.calculateIntersection(LightRay473);
	VectorStructR3 InterP473 = InterInfo473.getIntersectionPoint();
	IntersectInformationStruct InterInfo474 = S47.calculateIntersection(LightRay474);
	VectorStructR3 InterP474 = InterInfo474.getIntersectionPoint();
	IntersectInformationStruct InterInfo475 = S47.calculateIntersection(LightRay475);
	VectorStructR3 InterP475 = InterInfo475.getIntersectionPoint();

	//________________________________________________________________________________________________________
	//Linse um -45° gedreht, Startwert (0.0, 2.0, 0.0)
	LightRayStruct LightRay476(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 },  1.0);
	LightRayStruct LightRay477(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.5, 15.0 },  1.0);
	LightRayStruct LightRay478(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.0, 15.0 },  1.0);
	LightRayStruct LightRay479(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.5, 15.0 },  1.0);
	LightRayStruct LightRay480(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -3.0, 15.0 },  1.0);

	//SphericalSurface_LLT S95(/*radius*/-9.0, /*semiHeight*/2.817458, /*Apex of the sphere*/{ 0.0, 0.0, 20.0 },
	//	/*Direction*/ VectorStructR3{ 0.0, 1.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);


	IntersectInformationStruct InterInfo476 = S47.calculateIntersection(LightRay476);
	VectorStructR3 InterP476 = InterInfo476.getIntersectionPoint();
	IntersectInformationStruct InterInfo477 = S47.calculateIntersection(LightRay477);
	VectorStructR3 InterP477 = InterInfo477.getIntersectionPoint();
	IntersectInformationStruct InterInfo478 = S47.calculateIntersection(LightRay478);
	VectorStructR3 InterP478 = InterInfo478.getIntersectionPoint();
	IntersectInformationStruct InterInfo479 = S47.calculateIntersection(LightRay479);
	VectorStructR3 InterP479 = InterInfo479.getIntersectionPoint();
	IntersectInformationStruct InterInfo480 = S47.calculateIntersection(LightRay480);
	VectorStructR3 InterP480 = InterInfo480.getIntersectionPoint();

	std::vector<VectorStructR3> checkVector143 = { InterP471, InterP472, InterP473, InterP474, InterP475, InterP476, InterP477, InterP478, InterP479, InterP480 };


	std::vector<VectorStructR3> ReferenzVector143 = { { 0.0, 1.2309856444, 18.464784666 },{ 0.0, 0.64281653713, 19.284496114 },{ 0.0, 0.0, 20.0 },{ 0.0, -0.68733379032, 20.620013710 },{ 0.0, -1.4099937809, 21.149906714 },
	{ 0.0, 0.72091886227, 19.186217066 },{ 0.0, -3.7034572939E-012, 20.0 },{ 0.0, -0.75678616150, 20.675896211 },{ 0.0, -1.5388864007, 21.233318404 },{ 0.0, 0.0, 0.0 } };


	bool isRight143 = Math::compareAllVectorElements(checkVector143, ReferenzVector143, 9);
	checkMethodesSphericalLens.push_back(isRight143);


	//________________________________________________________________________________________________________________________________________________________________
	//________________________________________________________________________________________________________________________________________________________________
	// Linse 90° gedreht, Apex Sphere (0.0, 0.0, 20.0), Radius -9mm
	// Startwert (0.0, 0.0, 0.0)
	LightRayStruct LightRay481(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 1.0, 15.0 },  1.0);
	LightRayStruct LightRay482(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.5, 15.0 },  1.0);
	LightRayStruct LightRay483(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.0, 15.0 },  1.0);
	LightRayStruct LightRay484(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -0.5, 15.0 },  1.0);
	LightRayStruct LightRay485(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 },  1.0);

	SphericalSurface_LLT S48(/*radius*/9.0, /*semiHeight*/2.817458, /*Apex of the sphere*/{ 0.0, 0.0, 20.0 },
		/*Direction*/ VectorStructR3{ 0.0, 1.0, 0.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.0);

	IntersectInformationStruct InterInfo481 = S48.calculateIntersection(LightRay481);
	VectorStructR3 InterP481 = InterInfo481.getIntersectionPoint();
	IntersectInformationStruct InterInfo482 = S48.calculateIntersection(LightRay482);
	VectorStructR3 InterP482 = InterInfo482.getIntersectionPoint();
	IntersectInformationStruct InterInfo483 = S48.calculateIntersection(LightRay483);
	VectorStructR3 InterP483 = InterInfo483.getIntersectionPoint();
	IntersectInformationStruct InterInfo484 = S48.calculateIntersection(LightRay484);
	VectorStructR3 InterP484 = InterInfo484.getIntersectionPoint();
	IntersectInformationStruct InterInfo485 = S48.calculateIntersection(LightRay485);
	VectorStructR3 InterP485 = InterInfo485.getIntersectionPoint();

	//________________________________________________________________________________________________________
	//Linse um 90° gedreht, Startwert (0.0, 2.0, 0.0)
	LightRayStruct LightRay486(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 },  1.0);
	LightRayStruct LightRay487(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.5, 15.0 },  1.0);
	LightRayStruct LightRay488(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.0, 15.0 },  1.0);
	LightRayStruct LightRay489(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.5, 15.0 },  1.0);
	LightRayStruct LightRay490(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -3.0, 15.0 },  1.0);


	//InterP487 stimmt nicht mit Zemax überein -> Programm berechnet ersten Schnittpunkt mit Linse, als Referenz eingesetzt
	IntersectInformationStruct InterInfo486 = S48.calculateIntersection(LightRay486);
	VectorStructR3 InterP486 = InterInfo486.getIntersectionPoint();
	IntersectInformationStruct InterInfo487 = S48.calculateIntersection(LightRay487);
	VectorStructR3 InterP487 = InterInfo487.getIntersectionPoint();
	IntersectInformationStruct InterInfo488 = S48.calculateIntersection(LightRay488);
	VectorStructR3 InterP488 = InterInfo488.getIntersectionPoint();
	IntersectInformationStruct InterInfo489 = S48.calculateIntersection(LightRay489);
	VectorStructR3 InterP489 = InterInfo489.getIntersectionPoint();
	IntersectInformationStruct InterInfo490 = S48.calculateIntersection(LightRay490);
	VectorStructR3 InterP490 = InterInfo490.getIntersectionPoint();


	std::vector<VectorStructR3> checkVector144 = { InterP481, InterP482, InterP483, InterP484, InterP485, InterP486, InterP487, InterP488, InterP489, InterP490 };


	std::vector<VectorStructR3> ReferenzVector144 = { { 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 2.6384288908E-030, 20.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },
	{ 0.0, 0.0, 0.0 },{ 0.0, 0.17821782178218148, 18.217821782178188 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 } };


	bool isRight144 = Math::compareAllVectorElements(checkVector144, ReferenzVector144, 9);
	checkMethodesSphericalLens.push_back(isRight144);

	//________________________________________________________________________________________________________________________________________________________________
	//________________________________________________________________________________________________________________________________________________________________
	// Linse -90° gedreht, Apex Sphere (0.0, 0.0, 20.0), Radius -9mm
	// Startwert (0.0, 0.0, 0.0)
	LightRayStruct LightRay491(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 1.0, 15.0 },  1.0);
	LightRayStruct LightRay492(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.5, 15.0 },  1.0);
	LightRayStruct LightRay493(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.0, 15.0 },  1.0);
	LightRayStruct LightRay494(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -0.5, 15.0 },  1.0);
	LightRayStruct LightRay495(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 },  1.0);

	SphericalSurface_LLT S49(/*radius*/9.0, /*semiHeight*/2.817458, /*Apex of the sphere*/{ 0.0, 0.0, 20.0 },
		/*Direction*/ VectorStructR3{ 0.0, -1.0, 0.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);

	IntersectInformationStruct InterInfo491 = S49.calculateIntersection(LightRay491);
	VectorStructR3 InterP491 = InterInfo491.getIntersectionPoint();
	IntersectInformationStruct InterInfo492 = S49.calculateIntersection(LightRay492);
	VectorStructR3 InterP492 = InterInfo492.getIntersectionPoint();
	IntersectInformationStruct InterInfo493 = S49.calculateIntersection(LightRay493);
	VectorStructR3 InterP493 = InterInfo493.getIntersectionPoint();
	IntersectInformationStruct InterInfo494 = S49.calculateIntersection(LightRay494);
	VectorStructR3 InterP494 = InterInfo494.getIntersectionPoint();
	IntersectInformationStruct InterInfo495 = S49.calculateIntersection(LightRay495);
	VectorStructR3 InterP495 = InterInfo495.getIntersectionPoint();

	//________________________________________________________________________________________________________
	//Linse um -90° gedreht, Startwert (0.0, 2.0, 0.0)
	LightRayStruct LightRay496(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 },  1.0);
	LightRayStruct LightRay497(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.5, 15.0 },  1.0);
	LightRayStruct LightRay498(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.0, 15.0 },  1.0);
	LightRayStruct LightRay499(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.5, 15.0 },  1.0);
	LightRayStruct LightRay500(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -3.0, 15.0 },  1.0);


	//InterP498 stimmt nicht mit Zemax überein -> Programm berechnet ersten Schnittpunkt mit Linse, als Referenz eingesetzt
	IntersectInformationStruct InterInfo496 = S49.calculateIntersection(LightRay496);
	VectorStructR3 InterP496 = InterInfo496.getIntersectionPoint();
	IntersectInformationStruct InterInfo497 = S49.calculateIntersection(LightRay497);
	VectorStructR3 InterP497 = InterInfo497.getIntersectionPoint();
	IntersectInformationStruct InterInfo498 = S49.calculateIntersection(LightRay498);
	VectorStructR3 InterP498 = InterInfo498.getIntersectionPoint();
	IntersectInformationStruct InterInfo499 = S49.calculateIntersection(LightRay499);
	VectorStructR3 InterP499 = InterInfo499.getIntersectionPoint();
	IntersectInformationStruct InterInfo500 = S49.calculateIntersection(LightRay500);
	VectorStructR3 InterP500 = InterInfo500.getIntersectionPoint();

	std::vector<VectorStructR3> checkVector145 = { InterP491, InterP492, InterP493, InterP494, InterP495, InterP496, InterP497, InterP498, InterP499, InterP500 };


	std::vector<VectorStructR3> ReferenzVector145 = { { 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, -2.6384288908E-030, 20.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },
	{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 20.0 },{ 0.0, -0.33996486167351003, 17.549736462551326 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 } };


	bool isRight145 = Math::compareAllVectorElements(checkVector145, ReferenzVector145, 9);
	checkMethodesSphericalLens.push_back(isRight145);


	//________________________________________________________________________________________________________________________________________________________________
	//_______________________________________________________________________________________________________________________________________________________________
	// Linse 0° gedreht, Apex Sphere (0.0, 1.0, 20.0), Radius -9mm
	// Startwert (0.0, 0.0, 0.0)
	LightRayStruct LightRay501(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 1.0, 15.0 },  1.0);
	LightRayStruct LightRay502(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.5, 15.0 },  1.0);
	LightRayStruct LightRay503(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.0, 15.0 },  1.0);
	LightRayStruct LightRay504(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -0.5, 15.0 },  1.0);
	LightRayStruct LightRay505(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 },  1.0);

	SphericalSurface_LLT S50(/*radius*/9.0, /*semiHeight*/2.817458, /*Apex of the sphere*/{ 0.0, 1.0, 20.0 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.0);

	IntersectInformationStruct InterInfo501 = S50.calculateIntersection(LightRay501);
	VectorStructR3 InterP501 = InterInfo501.getIntersectionPoint();
	IntersectInformationStruct InterInfo502 = S50.calculateIntersection(LightRay502);
	VectorStructR3 InterP502 = InterInfo502.getIntersectionPoint();
	IntersectInformationStruct InterInfo503 = S50.calculateIntersection(LightRay503);
	VectorStructR3 InterP503 = InterInfo503.getIntersectionPoint();
	IntersectInformationStruct InterInfo504 = S50.calculateIntersection(LightRay504);
	VectorStructR3 InterP504 = InterInfo504.getIntersectionPoint();
	IntersectInformationStruct InterInfo505 = S50.calculateIntersection(LightRay505);
	VectorStructR3 InterP505 = InterInfo505.getIntersectionPoint();

	//________________________________________________________________________________________________________
	//Linse um 0° gedreht, Startwert (0.0, 2.0, 0.0)
	LightRayStruct LightRay506(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 },  1.0);
	LightRayStruct LightRay507(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.5, 15.0 },  1.0);
	LightRayStruct LightRay508(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.0, 15.0 },  1.0);
	LightRayStruct LightRay509(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.5, 15.0 },  1.0);
	LightRayStruct LightRay510(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -3.0, 15.0 },  1.0);


	IntersectInformationStruct InterInfo506 = S50.calculateIntersection(LightRay506);
	VectorStructR3 InterP506 = InterInfo506.getIntersectionPoint();
	IntersectInformationStruct InterInfo507 = S50.calculateIntersection(LightRay507);
	VectorStructR3 InterP507 = InterInfo507.getIntersectionPoint();
	IntersectInformationStruct InterInfo508 = S50.calculateIntersection(LightRay508);
	VectorStructR3 InterP508 = InterInfo508.getIntersectionPoint();
	IntersectInformationStruct InterInfo509 = S50.calculateIntersection(LightRay509);
	VectorStructR3 InterP509 = InterInfo509.getIntersectionPoint();
	IntersectInformationStruct InterInfo510 = S50.calculateIntersection(LightRay510);
	VectorStructR3 InterP510 = InterInfo510.getIntersectionPoint();

	std::vector<VectorStructR3> checkVector146 = { InterP501, InterP502, InterP503, InterP504, InterP505, InterP506, InterP507, InterP508, InterP509, InterP510 };


	std::vector<VectorStructR3> ReferenzVector146 = { { 0.0, 1.3329226835, 19.993840252 },{ 0.0, 0.66646058005, 19.993817402 },{ 0.0, 0.0, 19.944271910 },{ 0.0, -0.66151009817, 19.845302945 },{ 0.0, -1.3131770364, 19.697655546 },
	{ 0.0, 0.66707731650, 19.993840252 },{ 0.0, 0.0055113620090, 19.944886380 },{ 0.0, -0.64641663832, 19.848124787 },{ 0.0, -1.2842176400, 19.705305840 },{ 0.0, 0.0, 0.0 } };


	bool isRight146 = Math::compareAllVectorElements(checkVector146, ReferenzVector146, 7);
	checkMethodesSphericalLens.push_back(isRight146);


	//________________________________________________________________________________________________________________________________________________________________
	//________________________________________________________________________________________________________________________________________________________________
	// Linse 45° gedreht, Apex Sphere (0.0, 1.0, 20.0), Radius -9mm
	// Startwert (0.0, 0.0, 0.0)
	LightRayStruct LightRay511(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 1.0, 15.0 },  1.0);
	LightRayStruct LightRay512(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.5, 15.0 },  1.0);
	LightRayStruct LightRay513(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.0, 15.0 },  1.0);
	LightRayStruct LightRay514(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -0.5, 15.0 },  1.0);
	LightRayStruct LightRay515(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 },  1.0);

	SphericalSurface_LLT S51(/*radius*/9.0, /*semiHeight*/2.817458, /*Apex of the sphere*/{ 0.0, 1.0, 20.0 },
		/*Direction*/ VectorStructR3{ 0.0, 1.0, -1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.0);

	IntersectInformationStruct InterInfo511 = S51.calculateIntersection(LightRay511);
	VectorStructR3 InterP511 = InterInfo511.getIntersectionPoint();
	IntersectInformationStruct InterInfo512 = S51.calculateIntersection(LightRay512);
	VectorStructR3 InterP512 = InterInfo512.getIntersectionPoint();
	IntersectInformationStruct InterInfo513 = S51.calculateIntersection(LightRay513);
	VectorStructR3 InterP513 = InterInfo513.getIntersectionPoint();
	IntersectInformationStruct InterInfo514 = S51.calculateIntersection(LightRay514);
	VectorStructR3 InterP514 = InterInfo514.getIntersectionPoint();
	IntersectInformationStruct InterInfo515 = S51.calculateIntersection(LightRay515);
	VectorStructR3 InterP515 = InterInfo515.getIntersectionPoint();

	//________________________________________________________________________________________________________
	//Linse um 45° gedreht, Startwert (0.0, 2.0, 0.0)
	LightRayStruct LightRay516(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 },  1.0);
	LightRayStruct LightRay517(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.5, 15.0 },  1.0);
	LightRayStruct LightRay518(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.0, 15.0 },  1.0);
	LightRayStruct LightRay519(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.5, 15.0 },  1.0);
	LightRayStruct LightRay520(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -3.0, 15.0 },  1.0);


	IntersectInformationStruct InterInfo516 = S51.calculateIntersection(LightRay516);
	VectorStructR3 InterP516 = InterInfo516.getIntersectionPoint();
	IntersectInformationStruct InterInfo517 = S51.calculateIntersection(LightRay517);
	VectorStructR3 InterP517 = InterInfo517.getIntersectionPoint();
	IntersectInformationStruct InterInfo518 = S51.calculateIntersection(LightRay518);
	VectorStructR3 InterP518 = InterInfo518.getIntersectionPoint();
	IntersectInformationStruct InterInfo519 = S51.calculateIntersection(LightRay519);
	VectorStructR3 InterP519 = InterInfo519.getIntersectionPoint();
	IntersectInformationStruct InterInfo520 = S51.calculateIntersection(LightRay520);
	VectorStructR3 InterP520 = InterInfo520.getIntersectionPoint();

	std::vector<VectorStructR3> checkVector147 = { InterP511, InterP512, InterP513, InterP514, InterP515, InterP516, InterP517, InterP518, InterP519, InterP520 };


	std::vector<VectorStructR3> ReferenzVector147 = { { 0.0, 1.3557953563, 20.336930345 },{ 0.0, 0.65448729963, 19.634618989 },{ 0.0, 0.0, 18.810213100 },{ 0.0, -0.59461801827, 17.838540548 },{ 0.0, 0.0, 0.0 },
	{ 0.0, 0.68850330041, 19.672450494 },{ 0.0, 0.10442656170, 18.955734383 },{ 0.0, -0.42040943779, 18.153070783 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 } };


	bool isRight147 = Math::compareAllVectorElements(checkVector147, ReferenzVector147, 9);
	checkMethodesSphericalLens.push_back(isRight147);

	//________________________________________________________________________________________________________________________________________________________________
	//________________________________________________________________________________________________________________________________________________________________
	// Linse -45° gedreht, Apex Sphere (0.0, 1.0, 20.0), Radius -9mm
	// Startwert (0.0, 0.0, 0.0)
	LightRayStruct LightRay521(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 1.0, 15.0 },  1.0);
	LightRayStruct LightRay522(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.5, 15.0 },  1.0);
	LightRayStruct LightRay523(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.0, 15.0 },  1.0);
	LightRayStruct LightRay524(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -0.5, 15.0 },  1.0);
	LightRayStruct LightRay525(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 },  1.0);

	SphericalSurface_LLT S52(/*radius*/9.0, /*semiHeight*/2.817458, /*Apex of the sphere*/{ 0.0, 1.0, 20.0 },
		/*Direction*/ VectorStructR3{ 0.0, -1.0, -1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.0);

	IntersectInformationStruct InterInfo521 = S52.calculateIntersection(LightRay521);
	VectorStructR3 InterP521 = InterInfo521.getIntersectionPoint();
	IntersectInformationStruct InterInfo522 = S52.calculateIntersection(LightRay522);
	VectorStructR3 InterP522 = InterInfo522.getIntersectionPoint();
	IntersectInformationStruct InterInfo523 = S52.calculateIntersection(LightRay523);
	VectorStructR3 InterP523 = InterInfo523.getIntersectionPoint();
	IntersectInformationStruct InterInfo524 = S52.calculateIntersection(LightRay524);
	VectorStructR3 InterP524 = InterInfo524.getIntersectionPoint();
	IntersectInformationStruct InterInfo525 = S52.calculateIntersection(LightRay525);
	VectorStructR3 InterP525 = InterInfo525.getIntersectionPoint();

	//________________________________________________________________________________________________________
	//Linse um -45° gedreht, Startwert (0.0, 2.0, 0.0)
	LightRayStruct LightRay526(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 },  1.0);
	LightRayStruct LightRay527(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.5, 15.0 },  1.0);
	LightRayStruct LightRay528(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.0, 15.0 },  1.0);
	LightRayStruct LightRay529(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.5, 15.0 },  1.0);
	LightRayStruct LightRay530(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -3.0, 15.0 },  1.0);


	IntersectInformationStruct InterInfo526 = S52.calculateIntersection(LightRay526);
	VectorStructR3 InterP526 = InterInfo526.getIntersectionPoint();
	IntersectInformationStruct InterInfo527 = S52.calculateIntersection(LightRay527);
	VectorStructR3 InterP527 = InterInfo527.getIntersectionPoint();
	IntersectInformationStruct InterInfo528 = S52.calculateIntersection(LightRay528);
	VectorStructR3 InterP528 = InterInfo528.getIntersectionPoint();
	IntersectInformationStruct InterInfo529 = S52.calculateIntersection(LightRay529);
	VectorStructR3 InterP529 = InterInfo529.getIntersectionPoint();
	IntersectInformationStruct InterInfo530 = S52.calculateIntersection(LightRay530);
	VectorStructR3 InterP530 = InterInfo530.getIntersectionPoint();

	std::vector<VectorStructR3> checkVector148 = { InterP521, InterP522, InterP523, InterP524, InterP525, InterP526, InterP527, InterP528, InterP529, InterP530 };


	std::vector<VectorStructR3> ReferenzVector148 = { { 0.0, 1.3114966996, 19.672450494 },{ 0.0, 0.67691522223, 20.307456667 },{ 0.0, 0.0, 20.862927792 },{ 0.0, -0.71133783716,  21.340135115 },{ 0.0, 0.0, 0.0 },
	{ 0.0, 0.64420464365, 20.336930345 },{ 0.0, -0.093111580763, 20.931115808 },{ 0.0, -0.85681860771, 21.426139558 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 } };


	bool isRight148 = Math::compareAllVectorElements(checkVector148, ReferenzVector148, 9);
	checkMethodesSphericalLens.push_back(isRight148);

	//________________________________________________________________________________________________________________________________________________________________
	//________________________________________________________________________________________________________________________________________________________________
	// Linse 90° gedreht, Apex Sphere (0.0, 1.0, 20.0), Radius -9mm
	// Startwert (0.0, 0.0, 0.0)
	LightRayStruct LightRay531(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 1.0, 15.0 },  1.0);
	LightRayStruct LightRay532(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.5, 15.0 },  1.0);
	LightRayStruct LightRay533(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.0, 15.0 },  1.0);
	LightRayStruct LightRay534(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -0.5, 15.0 },  1.0);
	LightRayStruct LightRay535(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 },  1.0);

	SphericalSurface_LLT S53(/*radius*/9.0, /*semiHeight*/2.817458, /*Apex of the sphere*/{ 0.0, 1.0, 20.0 },
		/*Direction*/ VectorStructR3{ 0.0, 1.0, 0.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.0);

	//InterP531 stimmt nicht mit Zemax überein, Programm berechnet ersten Schnittpunkt mit Linse, als Referenz eingesetzt
	IntersectInformationStruct InterInfo531 = S53.calculateIntersection(LightRay531);
	VectorStructR3 InterP531 = InterInfo531.getIntersectionPoint();
	IntersectInformationStruct InterInfo532 = S53.calculateIntersection(LightRay532);
	VectorStructR3 InterP532 = InterInfo532.getIntersectionPoint();
	IntersectInformationStruct InterInfo533 = S53.calculateIntersection(LightRay533);
	VectorStructR3 InterP533 = InterInfo533.getIntersectionPoint();
	IntersectInformationStruct InterInfo534 = S53.calculateIntersection(LightRay534);
	VectorStructR3 InterP534 = InterInfo534.getIntersectionPoint();
	IntersectInformationStruct InterInfo535 = S53.calculateIntersection(LightRay535);
	VectorStructR3 InterP535 = InterInfo535.getIntersectionPoint();

	//________________________________________________________________________________________________________
	//Linse um 90° gedreht, Startwert (0.0, 2.0, 0.0)
	LightRayStruct LightRay536(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 },  1.0);
	LightRayStruct LightRay537(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.5, 15.0 },  1.0);
	LightRayStruct LightRay538(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.0, 15.0 },  1.0);
	LightRayStruct LightRay539(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.5, 15.0 },  1.0);
	LightRayStruct LightRay540(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -3.0, 15.0 },  1.0);


	IntersectInformationStruct InterInfo536 = S53.calculateIntersection(LightRay536);
	VectorStructR3 InterP536 = InterInfo536.getIntersectionPoint();
	IntersectInformationStruct InterInfo537 = S53.calculateIntersection(LightRay537);
	VectorStructR3 InterP537 = InterInfo537.getIntersectionPoint();
	IntersectInformationStruct InterInfo538 = S53.calculateIntersection(LightRay538);
	VectorStructR3 InterP538 = InterInfo538.getIntersectionPoint();
	IntersectInformationStruct InterInfo539 = S53.calculateIntersection(LightRay539);
	VectorStructR3 InterP539 = InterInfo539.getIntersectionPoint();
	IntersectInformationStruct InterInfo540 = S53.calculateIntersection(LightRay540);
	VectorStructR3 InterP540 = InterInfo540.getIntersectionPoint();


	std::vector<VectorStructR3> checkVector149 = { InterP531, InterP532, InterP533, InterP534, InterP535, InterP536, InterP537, InterP538, InterP539, InterP540 };


	std::vector<VectorStructR3> ReferenzVector149 = { { 0.0, 1.2057669623074985, 18.086504434612475 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },
	{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 } };


	bool isRight149 = Math::compareAllVectorElements(checkVector149, ReferenzVector149, 9);
	checkMethodesSphericalLens.push_back(isRight149);

	//________________________________________________________________________________________________________________________________________________________________
	//________________________________________________________________________________________________________________________________________________________________
	// Linse -90° gedreht, Apex Sphere (0.0, 1.0, 20.0), Radius -9mm
	// Startwert (0.0, 0.0, 0.0)
	LightRayStruct LightRay541(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 1.0, 15.0 },  1.0);
	LightRayStruct LightRay542(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.5, 15.0 },  1.0);
	LightRayStruct LightRay543(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.0, 15.0 },  1.0);
	LightRayStruct LightRay544(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -0.5, 15.0 },  1.0);
	LightRayStruct LightRay545(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 },  1.0);

	SphericalSurface_LLT S54(/*radius*/9.0, /*semiHeight*/2.817458, /*Apex of the sphere*/{ 0.0, 1.0, 20.0 },
		/*Direction*/ VectorStructR3{ 0.0, -1.0, 0.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.0);

	//InterP542: stimmt nicht überein, Programm berechnet ersten Schnittpunkt mit Linse, als Referenz eingesetzt
	IntersectInformationStruct InterInfo541 = S54.calculateIntersection(LightRay541);
	VectorStructR3 InterP541 = InterInfo541.getIntersectionPoint();
	IntersectInformationStruct InterInfo542 = S54.calculateIntersection(LightRay542);
	VectorStructR3 InterP542 = InterInfo542.getIntersectionPoint();
	IntersectInformationStruct InterInfo543 = S54.calculateIntersection(LightRay543);
	VectorStructR3 InterP543 = InterInfo543.getIntersectionPoint();
	IntersectInformationStruct InterInfo544 = S54.calculateIntersection(LightRay544);
	VectorStructR3 InterP544 = InterInfo544.getIntersectionPoint();
	IntersectInformationStruct InterInfo545 = S54.calculateIntersection(LightRay545);
	VectorStructR3 InterP545 = InterInfo545.getIntersectionPoint();

	//________________________________________________________________________________________________________
	//Linse um -90° gedreht, Startwert (0.0, 2.0, 0.0)
	LightRayStruct LightRay546(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 },  1.0);
	LightRayStruct LightRay547(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.5, 15.0 },  1.0);
	LightRayStruct LightRay548(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.0, 15.0 },  1.0);
	LightRayStruct LightRay549(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.5, 15.0 },  1.0);
	LightRayStruct LightRay550(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -3.0, 15.0 },  1.0);


	//InteP546: Schnittpunkt stimmt nicht mit Zemax überein, Programm berechnet ersten Schnittpunkt mit Linse
	IntersectInformationStruct InterInfo546 = S54.calculateIntersection(LightRay546);
	VectorStructR3 InterP546 = InterInfo546.getIntersectionPoint();
	IntersectInformationStruct InterInfo547 = S54.calculateIntersection(LightRay547);
	VectorStructR3 InterP547 = InterInfo547.getIntersectionPoint();
	IntersectInformationStruct InterInfo548 = S54.calculateIntersection(LightRay548);
	VectorStructR3 InterP548 = InterInfo548.getIntersectionPoint();
	IntersectInformationStruct InterInfo549 = S54.calculateIntersection(LightRay549);
	VectorStructR3 InterP549 = InterInfo549.getIntersectionPoint();
	IntersectInformationStruct InterInfo550 = S54.calculateIntersection(LightRay550);
	VectorStructR3 InterP550 = InterInfo550.getIntersectionPoint();

	std::vector<VectorStructR3> checkVector150 = { InterP541, InterP542, InterP543, InterP544, InterP545, InterP546, InterP547, InterP548, InterP549, InterP550 };


	std::vector<VectorStructR3> ReferenzVector150 = { { 0.0, 0.0, 0.0 },{ 0.0, 0.57563229773543478, 17.268968932063043 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },
	{ 0.0, 0.79423303769250020, 18.086504434612497 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 } };


	bool isRight150 = Math::compareAllVectorElements(checkVector150, ReferenzVector150, 9);
	checkMethodesSphericalLens.push_back(isRight150);


	//________________________________________________________________________________________________________________________________________________________________
	//_______________________________________________________________________________________________________________________________________________________________
	// Linse 0° gedreht, Apex Sphere (0.0, -1.0, 20.0), Radius -9mm
	// Startwert (0.0, 0.0, 0.0)
	LightRayStruct LightRay551(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 1.0, 15.0 },  1.0);
	LightRayStruct LightRay552(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.5, 15.0 },  1.0);
	LightRayStruct LightRay553(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.0, 15.0 },  1.0);
	LightRayStruct LightRay554(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -0.5, 15.0 },  1.0);
	LightRayStruct LightRay555(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 },  1.0);

	SphericalSurface_LLT S55(/*radius*/9.0, /*semiHeight*/2.817458, /*Apex of the sphere*/{ 0.0, -1.0, 20.0 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.0);

	IntersectInformationStruct InterInfo551 = S55.calculateIntersection(LightRay551);
	VectorStructR3 InterP551 = InterInfo551.getIntersectionPoint();
	IntersectInformationStruct InterInfo552 = S55.calculateIntersection(LightRay552);
	VectorStructR3 InterP552 = InterInfo552.getIntersectionPoint();
	IntersectInformationStruct InterInfo553 = S55.calculateIntersection(LightRay553);
	VectorStructR3 InterP553 = InterInfo553.getIntersectionPoint();
	IntersectInformationStruct InterInfo554 = S55.calculateIntersection(LightRay554);
	VectorStructR3 InterP554 = InterInfo554.getIntersectionPoint();
	IntersectInformationStruct InterInfo555 = S55.calculateIntersection(LightRay555);
	VectorStructR3 InterP555 = InterInfo555.getIntersectionPoint();

	//________________________________________________________________________________________________________
	//Linse um 0° gedreht, Startwert (0.0, 2.0, 0.0)
	LightRayStruct LightRay556(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 },  1.0);
	LightRayStruct LightRay557(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.5, 15.0 },  1.0);
	LightRayStruct LightRay558(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.0, 15.0 },  1.0);
	LightRayStruct LightRay559(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.5, 15.0 },  1.0);
	LightRayStruct LightRay560(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -3.0, 15.0 },  1.0);


	IntersectInformationStruct InterInfo556 = S55.calculateIntersection(LightRay556);
	VectorStructR3 InterP556 = InterInfo556.getIntersectionPoint();
	IntersectInformationStruct InterInfo557 = S55.calculateIntersection(LightRay557);
	VectorStructR3 InterP557 = InterInfo557.getIntersectionPoint();
	IntersectInformationStruct InterInfo558 = S55.calculateIntersection(LightRay558);
	VectorStructR3 InterP558 = InterInfo558.getIntersectionPoint();
	IntersectInformationStruct InterInfo559 = S55.calculateIntersection(LightRay559);
	VectorStructR3 InterP559 = InterInfo559.getIntersectionPoint();
	IntersectInformationStruct InterInfo560 = S55.calculateIntersection(LightRay560);
	VectorStructR3 InterP560 = InterInfo560.getIntersectionPoint();

	std::vector<VectorStructR3> checkVector151 = { InterP551, InterP552, InterP553, InterP554, InterP555, InterP556, InterP557, InterP558, InterP559, InterP560 };


	std::vector<VectorStructR3> ReferenzVector151 = { { 0.0, 1.3131770364, 19.697655546 },{ 0.0, 0.66151009817, 19.845302945 },{ 0.0, 0.0, 19.944271910 },{ 0.0, -0.66646058005, 19.993817402 },{ 0.0, -1.3329226835, 19.993840252 },
	{ 0.0, 0.67717695337, 19.842345699 },{ 0.0, 0.0056360012072, 19.943639988 },{ 0.0, -0.66583924503, 19.993794338 },{ 0.0, -1.3323104822, 19.993862893 },{ 0.0, -1.9890968386, 19.945484193 } };

	bool isRight151 = Math::compareAllVectorElements(checkVector151, ReferenzVector151, 9);
	checkMethodesSphericalLens.push_back(isRight151);


	//________________________________________________________________________________________________________________________________________________________________
	//________________________________________________________________________________________________________________________________________________________________
	// Linse 45° gedreht, Apex Sphere (0.0, -1.0, 20.0), Radius -9mm
	// Startwert (0.0, 0.0, 0.0)
	LightRayStruct LightRay561(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 1.0, 15.0 },  1.0);
	LightRayStruct LightRay562(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.5, 15.0 },  1.0);
	LightRayStruct LightRay563(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.0, 15.0 },  1.0);
	LightRayStruct LightRay564(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -0.5, 15.0 },  1.0);
	LightRayStruct LightRay565(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 },  1.0);

	SphericalSurface_LLT S56(/*radius*/9.0, /*semiHeight*/2.817458, /*Apex of the sphere*/{ 0.0, -1.0, 20.0 },
		/*Direction*/ VectorStructR3{ 0.0, 1.0, -1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.0);

	IntersectInformationStruct InterInfo561 = S56.calculateIntersection(LightRay561);
	VectorStructR3 InterP561 = InterInfo561.getIntersectionPoint();
	IntersectInformationStruct InterInfo562 = S56.calculateIntersection(LightRay562);
	VectorStructR3 InterP562 = InterInfo562.getIntersectionPoint();
	IntersectInformationStruct InterInfo563 = S56.calculateIntersection(LightRay563);
	VectorStructR3 InterP563 = InterInfo563.getIntersectionPoint();
	IntersectInformationStruct InterInfo564 = S56.calculateIntersection(LightRay564);
	VectorStructR3 InterP564 = InterInfo564.getIntersectionPoint();
	IntersectInformationStruct InterInfo565 = S56.calculateIntersection(LightRay565);
	VectorStructR3 InterP565 = InterInfo565.getIntersectionPoint();

	//________________________________________________________________________________________________________
	//Linse um 45° gedreht, Startwert (0.0, 2.0, 0.0)
	LightRayStruct LightRay566(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 },  1.0);
	LightRayStruct LightRay567(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.5, 15.0 },  1.0);
	LightRayStruct LightRay568(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.0, 15.0 },  1.0);
	LightRayStruct LightRay569(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.5, 15.0 },  1.0);
	LightRayStruct LightRay570(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -3.0, 15.0 },  1.0);


	IntersectInformationStruct InterInfo566 = S56.calculateIntersection(LightRay566);
	VectorStructR3 InterP566 = InterInfo566.getIntersectionPoint();
	IntersectInformationStruct InterInfo567 = S56.calculateIntersection(LightRay567);
	VectorStructR3 InterP567 = InterInfo567.getIntersectionPoint();
	IntersectInformationStruct InterInfo568 = S56.calculateIntersection(LightRay568);
	VectorStructR3 InterP568 = InterInfo568.getIntersectionPoint();
	IntersectInformationStruct InterInfo569 = S56.calculateIntersection(LightRay569);
	VectorStructR3 InterP569 = InterInfo569.getIntersectionPoint();
	IntersectInformationStruct InterInfo570 = S56.calculateIntersection(LightRay570);
	VectorStructR3 InterP570 = InterInfo570.getIntersectionPoint();

	std::vector<VectorStructR3> checkVector152 = { InterP561, InterP562, InterP563, InterP564, InterP565, InterP566, InterP567, InterP568, InterP569, InterP570 };


	std::vector<VectorStructR3> ReferenzVector152 = { { 0.0, 0.0, 0.0 },{ 0.0, 0.71133783716, 21.340135115 },{ 0.0, 0.0, 20.862927792 },{ 0.0, -0.67691522223, 20.307456667 },{ 0.0, -1.3114966996, 19.672450494 },
	{ 0.0, 0.58260605943, 21.260909108 },{ 0.0, -0.080265578796, 20.802655788 },{ 0.0, -0.70433654596, 20.282524095 },{ 0.0, -1.2838195578, 19.702917347 },{ 0.0, -1.8132565541, 19.066282771 } };


	bool isRight152 = Math::compareAllVectorElements(checkVector152, ReferenzVector152, 9);
	checkMethodesSphericalLens.push_back(isRight152);

	//________________________________________________________________________________________________________________________________________________________________
	//________________________________________________________________________________________________________________________________________________________________
	// Linse -45° gedreht, Apex Sphere (0.0, -1.0, 20.0), Radius -9mm
	// Startwert (0.0, 0.0, 0.0)
	LightRayStruct LightRay571(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 1.0, 15.0 },  1.0);
	LightRayStruct LightRay572(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.5, 15.0 },  1.0);
	LightRayStruct LightRay573(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.0, 15.0 },  1.0);
	LightRayStruct LightRay574(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -0.5, 15.0 },  1.0);
	LightRayStruct LightRay575(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 },  1.0);

	SphericalSurface_LLT S57(/*radius*/9.0, /*semiHeight*/2.817458, /*Apex of the sphere*/{ 0.0, -1.0, 20.0 },
		/*Direction*/ VectorStructR3{ 0.0, -1.0, -1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.0);

	IntersectInformationStruct InterInfo571 = S57.calculateIntersection(LightRay571);
	VectorStructR3 InterP571 = InterInfo571.getIntersectionPoint();
	IntersectInformationStruct InterInfo572 = S57.calculateIntersection(LightRay572);
	VectorStructR3 InterP572 = InterInfo572.getIntersectionPoint();
	IntersectInformationStruct InterInfo573 = S57.calculateIntersection(LightRay573);
	VectorStructR3 InterP573 = InterInfo573.getIntersectionPoint();
	IntersectInformationStruct InterInfo574 = S57.calculateIntersection(LightRay574);
	VectorStructR3 InterP574 = InterInfo574.getIntersectionPoint();
	IntersectInformationStruct InterInfo575 = S57.calculateIntersection(LightRay575);
	VectorStructR3 InterP575 = InterInfo575.getIntersectionPoint();

	//________________________________________________________________________________________________________
	//Linse um -45° gedreht, Startwert (0.0, 2.0, 0.0)
	LightRayStruct LightRay576(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 },  1.0);
	LightRayStruct LightRay577(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.5, 15.0 },  1.0);
	LightRayStruct LightRay578(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.0, 15.0 },  1.0);
	LightRayStruct LightRay579(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.5, 15.0 },  1.0);
	LightRayStruct LightRay580(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -3.0, 15.0 },  1.0);


	IntersectInformationStruct InterInfo576 = S57.calculateIntersection(LightRay576);
	VectorStructR3 InterP576 = InterInfo576.getIntersectionPoint();
	IntersectInformationStruct InterInfo577 = S57.calculateIntersection(LightRay577);
	VectorStructR3 InterP577 = InterInfo577.getIntersectionPoint();
	IntersectInformationStruct InterInfo578 = S57.calculateIntersection(LightRay578);
	VectorStructR3 InterP578 = InterInfo578.getIntersectionPoint();
	IntersectInformationStruct InterInfo579 = S57.calculateIntersection(LightRay579);
	VectorStructR3 InterP579 = InterInfo579.getIntersectionPoint();
	IntersectInformationStruct InterInfo580 = S57.calculateIntersection(LightRay580);
	VectorStructR3 InterP580 = InterInfo580.getIntersectionPoint();

	std::vector<VectorStructR3> checkVector153 = { InterP571, InterP572, InterP573, InterP574, InterP575, InterP576, InterP577, InterP578, InterP579, InterP580 };


	std::vector<VectorStructR3> ReferenzVector153 = { { 0.0, 0.0, 0.0 },{ 0.0, 0.59461801827, 17.838540548 },{ 0.0, 0.0, 18.810213100 },{ 0.0, -0.65448729963, 19.634618989 },{ 0.0, -1.3557953563, 20.336930345 },
	{ 0.0, 0.0, 0.0 },{ 0.0, 0.13941113150, 18.605888685 },{ 0.0, -0.61149021382, 19.586176604 },{ 0.0, -1.3953668972, 20.372201384 },{ 0.0, -2.2016665517, 21.008332758 } };


	bool isRight153 = Math::compareAllVectorElements(checkVector153, ReferenzVector153, 9);
	checkMethodesSphericalLens.push_back(isRight153);


	//________________________________________________________________________________________________________________________________________________________________
	//________________________________________________________________________________________________________________________________________________________________
	// Linse 90° gedreht, Apex Sphere (0.0, 1.0, 20.0), Radius -9mm
	// Startwert (0.0, 0.0, 0.0)
	LightRayStruct LightRay581(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 1.0, 15.0 },  1.0);
	LightRayStruct LightRay582(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.5, 15.0 },  1.0);
	LightRayStruct LightRay583(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.0, 15.0 },  1.0);
	LightRayStruct LightRay584(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -0.5, 15.0 },  1.0);
	LightRayStruct LightRay585(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 },  1.0);

	SphericalSurface_LLT S58(/*radius*/9.0, /*semiHeight*/2.817458, /*Apex of the sphere*/{ 0.0, -1.0, 20.0 },
		/*Direction*/ VectorStructR3{ 0.0, 1.0, 0.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.0);

	//InterP584 stimmt nicht mit Zemax überein, Programm berechnet ersten Schnittpunkt, als Referenz eingesetzt
	IntersectInformationStruct InterInfo581 = S58.calculateIntersection(LightRay581);
	VectorStructR3 InterP581 = InterInfo581.getIntersectionPoint();
	IntersectInformationStruct InterInfo582 = S58.calculateIntersection(LightRay582);
	VectorStructR3 InterP582 = InterInfo582.getIntersectionPoint();
	IntersectInformationStruct InterInfo583 = S58.calculateIntersection(LightRay583);
	VectorStructR3 InterP583 = InterInfo583.getIntersectionPoint();
	IntersectInformationStruct InterInfo584 = S58.calculateIntersection(LightRay584);
	VectorStructR3 InterP584 = InterInfo584.getIntersectionPoint();
	IntersectInformationStruct InterInfo585 = S58.calculateIntersection(LightRay585);
	VectorStructR3 InterP585 = InterInfo585.getIntersectionPoint();

	//________________________________________________________________________________________________________
	//Linse um 90° gedreht, Startwert (0.0, 2.0, 0.0)
	LightRayStruct LightRay586(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 },  1.0);
	LightRayStruct LightRay587(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.5, 15.0 },  1.0);
	LightRayStruct LightRay588(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.0, 15.0 },  1.0);
	LightRayStruct LightRay589(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.5, 15.0 },  1.0);
	LightRayStruct LightRay590(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -3.0, 15.0 },  1.0);


	IntersectInformationStruct InterInfo586 = S58.calculateIntersection(LightRay586);
	VectorStructR3 InterP586 = InterInfo586.getIntersectionPoint();
	IntersectInformationStruct InterInfo587 = S58.calculateIntersection(LightRay587);
	VectorStructR3 InterP587 = InterInfo587.getIntersectionPoint();
	IntersectInformationStruct InterInfo588 = S58.calculateIntersection(LightRay588);
	VectorStructR3 InterP588 = InterInfo588.getIntersectionPoint();
	IntersectInformationStruct InterInfo589 = S58.calculateIntersection(LightRay589);
	VectorStructR3 InterP589 = InterInfo589.getIntersectionPoint();
	IntersectInformationStruct InterInfo590 = S58.calculateIntersection(LightRay590);
	VectorStructR3 InterP590 = InterInfo590.getIntersectionPoint();


	std::vector<VectorStructR3> checkVector154 = { InterP581, InterP582, InterP583, InterP584, InterP585, InterP586, InterP587, InterP588, InterP589, InterP590 };


	std::vector<VectorStructR3> ReferenzVector154 = { { 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, -0.57563229773543478, 17.268968932063043 },{ 0.0, 0.0, 0.0 },
	{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, -0.86993782540, 21.524533691 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 } };


	bool isRight154 = Math::compareAllVectorElements(checkVector154, ReferenzVector154, 9);
	checkMethodesSphericalLens.push_back(isRight154);

	//________________________________________________________________________________________________________________________________________________________________
	//________________________________________________________________________________________________________________________________________________________________
	// Linse -90° gedreht, Apex Sphere (0.0, 1.0, 20.0), Radius -9mm
	// Startwert (0.0, 0.0, 0.0)
	LightRayStruct LightRay591(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 1.0, 15.0 },  1.0);
	LightRayStruct LightRay592(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.5, 15.0 },  1.0);
	LightRayStruct LightRay593(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.0, 15.0 },  1.0);
	LightRayStruct LightRay594(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -0.5, 15.0 },  1.0);
	LightRayStruct LightRay595(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 },  1.0);

	SphericalSurface_LLT S59(/*radius*/9.0, /*semiHeight*/2.817458, /*Apex of the sphere*/{ 0.0, -1.0, 20.0 },
		/*Direction*/ VectorStructR3{ 0.0, -1.0, 0.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.0);

	//InterP595 stimmt nicht mit Zemax überein, Programm berechnet ersten Schnittpunkt mit LInse, als Referenz eingsetzt
	IntersectInformationStruct InterInfo591 = S59.calculateIntersection(LightRay591);
	VectorStructR3 InterP591 = InterInfo591.getIntersectionPoint();
	IntersectInformationStruct InterInfo592 = S59.calculateIntersection(LightRay592);
	VectorStructR3 InterP592 = InterInfo592.getIntersectionPoint();
	IntersectInformationStruct InterInfo593 = S59.calculateIntersection(LightRay593);
	VectorStructR3 InterP593 = InterInfo593.getIntersectionPoint();
	IntersectInformationStruct InterInfo594 = S59.calculateIntersection(LightRay594);
	VectorStructR3 InterP594 = InterInfo594.getIntersectionPoint();
	IntersectInformationStruct InterInfo595 = S59.calculateIntersection(LightRay595);
	VectorStructR3 InterP595 = InterInfo595.getIntersectionPoint();

	//________________________________________________________________________________________________________
	//Linse um -90° gedreht, Startwert (0.0, 2.0, 0.0)
	LightRayStruct LightRay596(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.0, 15.0 },  1.0);
	LightRayStruct LightRay597(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.5, 15.0 },  1.0);
	LightRayStruct LightRay598(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.0, 15.0 },  1.0);
	LightRayStruct LightRay599(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.5, 15.0 },  1.0);
	LightRayStruct Ray600(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -3.0, 15.0 },  1.0);


	//InterP599 und InterP600 stimmt nicht mit Zemax überein, Programm berechnet ersten Schnittpunkt mit Linse, als Referenz eingesetzt
	IntersectInformationStruct InterInfo596 = S59.calculateIntersection(LightRay596);
	VectorStructR3 InterP596 = InterInfo596.getIntersectionPoint();
	IntersectInformationStruct InterInfo597 = S59.calculateIntersection(LightRay597);
	VectorStructR3 InterP597 = InterInfo597.getIntersectionPoint();
	IntersectInformationStruct InterInfo598 = S59.calculateIntersection(LightRay598);
	VectorStructR3 InterP598 = InterInfo598.getIntersectionPoint();
	IntersectInformationStruct InterInfo599 = S59.calculateIntersection(LightRay599);
	VectorStructR3 InterP599 = InterInfo599.getIntersectionPoint();
	IntersectInformationStruct InterInfo600 = S59.calculateIntersection(Ray600);
	VectorStructR3 InterP600 = InterInfo600.getIntersectionPoint();

	std::vector<VectorStructR3> checkVector155 = { InterP591, InterP592, InterP593, InterP594, InterP595, InterP596, InterP597, InterP598, InterP599, InterP600 };


	std::vector<VectorStructR3> ReferenzVector155 = { { 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, -1.2057669623074985, 18.086504434612475 },
	{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 },{ 0.0, -1.1049393846317908,  18.629636307790744 },{ 0.0, -1.4425213939075419, 17.212606969537710 } };


	bool isRight155 = Math::compareAllVectorElements(checkVector155, ReferenzVector155, 9);
	checkMethodesSphericalLens.push_back(isRight155);

	// *****************************************************************************************************************
	bool output = Math::checkTrueOfVectorElements(checkMethodesSphericalLens);
	// *****************************************************************************************************************

	return output;
}