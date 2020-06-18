#include "testPlanSurface.h"
#include "..\..\LowLevelTracing\Surfaces\PlanGeometry_LLT.h"
#include "..\..\LowLevelTracing\ImportantStructures.h"

bool testPlanSurface::checkMethodesPlanSurface()
{
	std::vector<bool> checkPlanSurface;


	//____________________________________________________________________________________________________________________
	//____________________________________________________________________________________________________________________

	// Plan surface, rotation 0°, start point {0.0,0.0,10.0}

	LightRayStruct lightRay1(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 1.0, 5.0 }, 1.0);
	LightRayStruct lightRay2(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.0, 5.0 }, 1.0);
	LightRayStruct lightRay3(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -1.0, 5.0 }, 1.0);

	LightRayStruct lightRay4(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.0, 5.0 }, 1.0);
	LightRayStruct lightRay5(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.0, 5.0 }, 1.0);
	LightRayStruct lightRay6(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -3.0, 5.0 }, 1.0);

	PlanGeometry_LLT Plan1(/*semiHeight*/3.0, /*point*/{ 0.0,0.0,10.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiveSideA*/ 1.0, /*refractiveSideB*/ 1.0);

	IntersectInformationStruct InterInfo1 = Plan1.calculateIntersection(lightRay1);
	VectorStructR3 InterP1 = InterInfo1.getIntersectionPoint();
	IntersectInformationStruct InterInfo2 = Plan1.calculateIntersection(lightRay2);
	VectorStructR3 InterP2 = InterInfo2.getIntersectionPoint();
	IntersectInformationStruct InterInfo3 = Plan1.calculateIntersection(lightRay3);
	VectorStructR3 InterP3 = InterInfo3.getIntersectionPoint();

	IntersectInformationStruct InterInfo4 = Plan1.calculateIntersection(lightRay4);
	VectorStructR3 InterP4 = InterInfo4.getIntersectionPoint();
	IntersectInformationStruct InterInfo5 = Plan1.calculateIntersection(lightRay5);
	VectorStructR3 InterP5 = InterInfo5.getIntersectionPoint();
	IntersectInformationStruct InterInfo6 = Plan1.calculateIntersection(lightRay6);
	VectorStructR3 InterP6 = InterInfo6.getIntersectionPoint();


	std::vector<VectorStructR3> ReferenzVector1 = { { 0.0, 2.0, 10.0 },{ 0.0, 0.0, 10.0 },{ 0.0, -2.0, 10.0 },{ 0.0, 0.0, 10.0 },{ 0.0, -2.0, 10.0 },{ 0.0, 0.0, 0.0 } };
	std::vector<VectorStructR3> checkVector1 = { InterP1, InterP2, InterP3, InterP4, InterP5, InterP6 };

	// *****************************************************************************************************************
	bool isRight1 = Math::compareAllVectorElements(checkVector1, ReferenzVector1, 9);
	checkPlanSurface.push_back(isRight1);
	// *****************************************************************************************************************

	//____________________________________________________________________________________________________________________
	//____________________________________________________________________________________________________________________


	//Plan surface, rotation -45°, start point{ 0.0,0.0,10.0 }
	LightRayStruct lightRay7(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 1.0, 5.0 },  1.0);
	LightRayStruct lightRay8(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.0, 5.0 },  1.0);
	LightRayStruct lightRay9(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -1.0, 5.0 },  1.0);

	LightRayStruct lightRay10(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.0, 5.0 },  1.0);
	LightRayStruct lightRay11(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.0, 5.0 },  1.0);
	LightRayStruct lightRay12(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -3.0, 5.0 },  1.0);

	PlanGeometry_LLT Plan2(/*semiHeight*/3.0, /*point*/{ 0.0,0.0,10.0 }, /*direction*/{ 0.0,1.0,1.0 }, /*refractiveSideA*/ 1.0, /*refractiveSideB*/ 1.0);

	IntersectInformationStruct InterInfo7 = Plan2.calculateIntersection(lightRay7);
	VectorStructR3 InterP7 = InterInfo7.getIntersectionPoint();
	IntersectInformationStruct InterInfo8 = Plan2.calculateIntersection(lightRay8);
	VectorStructR3 InterP8 = InterInfo8.getIntersectionPoint();
	IntersectInformationStruct InterInfo9 = Plan2.calculateIntersection(lightRay9);
	VectorStructR3 InterP9 = InterInfo9.getIntersectionPoint();

	IntersectInformationStruct InterInfo10 = Plan2.calculateIntersection(lightRay10);
	VectorStructR3 InterP10 = InterInfo10.getIntersectionPoint();
	IntersectInformationStruct InterInfo11 = Plan2.calculateIntersection(lightRay11);
	VectorStructR3 InterP11 = InterInfo11.getIntersectionPoint();
	IntersectInformationStruct InterInfo12 = Plan2.calculateIntersection(lightRay12);
	VectorStructR3 InterP12 = InterInfo12.getIntersectionPoint();

	std::vector<VectorStructR3> ReferenzVector2 = { { 0.0, 1.6666666667, 8.3333333333 },{ 0.0, 0.0, 10.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 10.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 } };
	std::vector<VectorStructR3> checkVector2 = { InterP7, InterP8, InterP9, InterP10, InterP11, InterP12 };

	// *****************************************************************************************************************
	bool isRight2 = Math::compareAllVectorElements(checkVector2, ReferenzVector2, 9);
	checkPlanSurface.push_back(isRight2);
	// *****************************************************************************************************************

	//____________________________________________________________________________________________________________________
	//____________________________________________________________________________________________________________________

	// Plan surface, rotation 45°, start point {0.0,0.0,10.0}
	LightRayStruct lightRay13(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 1.0, 5.0 },  1.0);
	LightRayStruct lightRay14(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.0, 5.0 },  1.0);
	LightRayStruct lightRay15(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -1.0, 5.0 },  1.0);

	LightRayStruct lightRay16(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.0, 5.0 },  1.0);
	LightRayStruct lightRay17(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.0, 5.0 },  1.0);
	LightRayStruct lightRay18(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -3.0, 5.0 },  1.0);

	PlanGeometry_LLT Plan3(/*semiHeight*/3.0, /*point*/{ 0.5,1.0,10.0 }, /*direction*/{ 0.0,-1.0,1.0 }, /*refractiveSideA*/ 1.0, /*refractiveSideB*/ 1.0);

	IntersectInformationStruct InterInfo13 = Plan3.calculateIntersection(lightRay13);
	VectorStructR3 InterP13 = InterInfo13.getIntersectionPoint();
	IntersectInformationStruct InterInfo14 = Plan3.calculateIntersection(lightRay14);
	VectorStructR3 InterP14 = InterInfo14.getIntersectionPoint();
	IntersectInformationStruct InterInfo15 = Plan3.calculateIntersection(lightRay15);
	VectorStructR3 InterP15 = InterInfo15.getIntersectionPoint();

	IntersectInformationStruct InterInfo16 = Plan3.calculateIntersection(lightRay16);
	VectorStructR3 InterP16 = InterInfo16.getIntersectionPoint();
	IntersectInformationStruct InterInfo17 = Plan3.calculateIntersection(lightRay17);
	VectorStructR3 InterP17 = InterInfo17.getIntersectionPoint();
	IntersectInformationStruct InterInfo18 = Plan3.calculateIntersection(lightRay18);
	VectorStructR3 InterP18 = InterInfo18.getIntersectionPoint();

	std::vector<VectorStructR3> ReferenzVector3 = { { 0.0, 2.25, 11.25 },{ 0.0, 0.0, 9.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.1666666666, 9.1666666667 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 } };
	std::vector<VectorStructR3> checkVector3 = { InterP13, InterP14, InterP15, InterP16, InterP17, InterP18 };

	// *****************************************************************************************************************
	bool isRight3 = Math::compareAllVectorElements(checkVector3, ReferenzVector3, 9);
	checkPlanSurface.push_back(isRight3);
	// *****************************************************************************************************************

	//____________________________________________________________________________________________________________________
	//____________________________________________________________________________________________________________________

	// Plan surface, rotation -45°, start point {0.0,0.0,10.0}
	LightRayStruct lightRay19(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 1.0, 5.0 },  1.0);
	LightRayStruct lightRay20(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.0, 5.0 },  1.0);
	LightRayStruct lightRay21(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -1.0, 5.0 },  1.0);

	LightRayStruct lightRay22(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.0, 5.0 },  1.0);
	LightRayStruct lightRay23(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.0, 5.0 },  1.0);
	LightRayStruct lightRay24(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -3.0, 5.0 },  1.0);

	PlanGeometry_LLT Plan4(/*semiHeight*/3.0, /*point*/{ -0.5,1.0,10.0 }, /*direction*/{ 0.0,-1.0,-1.0 }, /*refractiveSideA*/ 1.0, /*refractiveSideB*/ 1.0);

	IntersectInformationStruct InterInfo19 = Plan4.calculateIntersection(lightRay19);
	VectorStructR3 InterP19 = InterInfo19.getIntersectionPoint();
	IntersectInformationStruct InterInfo20 = Plan4.calculateIntersection(lightRay20);
	VectorStructR3 InterP20 = InterInfo20.getIntersectionPoint();
	IntersectInformationStruct InterInfo21 = Plan4.calculateIntersection(lightRay21);
	VectorStructR3 InterP21 = InterInfo21.getIntersectionPoint();

	IntersectInformationStruct InterInfo22 = Plan4.calculateIntersection(lightRay22);
	VectorStructR3 InterP22 = InterInfo22.getIntersectionPoint();
	IntersectInformationStruct InterInfo23 = Plan4.calculateIntersection(lightRay23);
	VectorStructR3 InterP23 = InterInfo23.getIntersectionPoint();
	IntersectInformationStruct InterInfo24 = Plan4.calculateIntersection(lightRay24);
	VectorStructR3 InterP24 = InterInfo24.getIntersectionPoint();

	std::vector<VectorStructR3> ReferenzVector4 = { { 0.0, 1.8333333333, 9.1666666667 },{ 0.0, 0.0, 11.0 },{ 0.0, 0.0, 0.0 },{ 0.0, -0.250, 11.250 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 } };
	std::vector<VectorStructR3> checkVector4 = { InterP19, InterP20, InterP21, InterP22, InterP23, InterP24 };

	// *****************************************************************************************************************
	bool isRight4 = Math::compareAllVectorElements(checkVector4, ReferenzVector4, 9);
	checkPlanSurface.push_back(isRight4);
	// *****************************************************************************************************************

	//____________________________________________________________________________________________________________________
	//____________________________________________________________________________________________________________________

	// Plan surface, rotation 45°, start point {0.0,0.0,10.0}
	LightRayStruct lightRay25(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 1.0, 5.0 },  1.0);
	LightRayStruct lightRay26(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.0, 5.0 },  1.0);
	LightRayStruct lightRay27(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -1.0, 5.0 },  1.0);

	LightRayStruct lightRay28(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.0, 5.0 },  1.0);
	LightRayStruct lightRay29(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.0, 5.0 },  1.0);
	LightRayStruct lightRay30(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -3.0, 5.0 },  1.0);

	PlanGeometry_LLT Plan5(/*semiHeight*/3.0, /*point*/{ -0.5,-1.0,10.0 }, /*direction*/{ 0.0, 1.0,-1.0 }, /*refractiveSideA*/ 1.0, /*refractiveSideB*/ 1.0);

	IntersectInformationStruct InterInfo25 = Plan5.calculateIntersection(lightRay25);
	VectorStructR3 InterP25 = InterInfo25.getIntersectionPoint();
	IntersectInformationStruct InterInfo26 = Plan5.calculateIntersection(lightRay26);
	VectorStructR3 InterP26 = InterInfo26.getIntersectionPoint();
	IntersectInformationStruct InterInfo27 = Plan5.calculateIntersection(lightRay27);
	VectorStructR3 InterP27 = InterInfo27.getIntersectionPoint();

	IntersectInformationStruct InterInfo28 = Plan5.calculateIntersection(lightRay28);
	VectorStructR3 InterP28 = InterInfo28.getIntersectionPoint();
	IntersectInformationStruct InterInfo29 = Plan5.calculateIntersection(lightRay29);
	VectorStructR3 InterP29 = InterInfo29.getIntersectionPoint();
	IntersectInformationStruct InterInfo30 = Plan5.calculateIntersection(lightRay30);
	VectorStructR3 InterP30 = InterInfo30.getIntersectionPoint();

	std::vector<VectorStructR3> ReferenzVector5 = { { 0.0, 0.0, 0.0 },{ 0.0,0.0, 11.0 },{ 0.0, -1.8333333333, 9.1666666667 },{ 0.0, -0.16666666668, 10.833333333 },{ 0.0, -1.7142857143, 9.2857142857 },{ 0.0, -2.8750, 8.1250 } };
	std::vector<VectorStructR3> checkVector5 = { InterP25, InterP26, InterP27, InterP28, InterP29, InterP30 };

	// *****************************************************************************************************************
	bool isRight5 = Math::compareAllVectorElements(checkVector5, ReferenzVector5, 9);
	checkPlanSurface.push_back(isRight5);
	// *****************************************************************************************************************

	// ____________________________________________________________________________________________________________________
	//____________________________________________________________________________________________________________________
	bool output = Math::checkTrueOfVectorElements(checkPlanSurface);
	return output;
}