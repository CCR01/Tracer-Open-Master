#include "BenchmarkPlanSurface.h"
#include "..\..\LowLevelTracing\Surfaces\PlanGeometry_LLT.h"
#include "..\..\LowLevelTracing\Ray_LLT.h"

bool BenchmarkePlanSurface::checkMethodesPlanSurface()
{
	std::vector<bool> checkPlanSurface;


	//____________________________________________________________________________________________________________________
	//____________________________________________________________________________________________________________________

	// Plan surface, rotation 0°, start point {0.0,0.0,10.0}

	Ray_LLT Ray1(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 1.0, 5.0 }, 1.0);
	Ray_LLT Ray2(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.0, 5.0 }, 1.0);
	Ray_LLT Ray3(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -1.0, 5.0 }, 1.0);

	Ray_LLT Ray4(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.0, 5.0 }, 1.0);
	Ray_LLT Ray5(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.0, 5.0 }, 1.0);
	Ray_LLT Ray6(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -3.0, 5.0 }, 1.0);

	PlanGeometry_LLT Plan1(/*semiHeight*/3.0, /*point*/{ 0.0,0.0,10.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiveSideA*/ 1.0, /*refractiveSideB*/ 1.0);

//	IntersectInformationStruct InterInfo1 = Plan1.calculateIntersection(Ray1);
//	VectorStructR3 InterP1 = InterInfo1.getIntersectionPoint();
//	IntersectInformationStruct InterInfo2 = Plan1.calculateIntersection(Ray2);
//	VectorStructR3 InterP2 = InterInfo2.getIntersectionPoint();
//	IntersectInformationStruct InterInfo3 = Plan1.calculateIntersection(Ray3);
//	VectorStructR3 InterP3 = InterInfo3.getIntersectionPoint();
//
//	IntersectInformationStruct InterInfo4 = Plan1.calculateIntersection(Ray4);
//	VectorStructR3 InterP4 = InterInfo4.getIntersectionPoint();
//	IntersectInformationStruct InterInfo5 = Plan1.calculateIntersection(Ray5);
//	VectorStructR3 InterP5 = InterInfo5.getIntersectionPoint();
//	IntersectInformationStruct InterInfo6 = Plan1.calculateIntersection(Ray6);
//	VectorStructR3 InterP6 = InterInfo6.getIntersectionPoint();
//
//
//	std::vector<VectorStructR3> ReferenzVector1 = { { 0.0, 2.0, 10.0 },{ 0.0, 0.0, 10.0 },{ 0.0, -2.0, 10.0 },{ 0.0, 0.0, 10.0 },{ 0.0, -2.0, 10.0 },{ 0.0, 0.0, 0.0 } };
//	std::vector<VectorStructR3> checkVector1 = { InterP1, InterP2, InterP3, InterP4, InterP5, InterP6 };
//
//	// *****************************************************************************************************************
//	bool isRight1 = Math::compareAllVectorElements(checkVector1, ReferenzVector1, 9);
//	checkPlanSurface.push_back(isRight1);
//	// *****************************************************************************************************************
//
//	//____________________________________________________________________________________________________________________
//	//____________________________________________________________________________________________________________________
//
//
//	//Plan surface, rotation -45°, start point{ 0.0,0.0,10.0 }
//	Ray_LLT Ray7(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 1.0, 5.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray8(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.0, 5.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray9(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -1.0, 5.0 }, /*wavelength*/500.0, 1.0);
//
//	Ray_LLT Ray10(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.0, 5.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray11(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.0, 5.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray12(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -3.0, 5.0 }, /*wavelength*/500.0, 1.0);
//
//	PlanGeometry_LLT Plan2(/*semiHeight*/3.0, /*point*/{ 0.0,0.0,10.0 }, /*direction*/{ 0.0,1.0,1.0 }, /*refractiveSideA*/ 1.0, /*refractiveSideB*/ 1.0);
//
//	IntersectInformationStruct InterInfo7 = Plan2.calculateIntersection(Ray7);
//	VectorStructR3 InterP7 = InterInfo7.getIntersectionPoint();
//	IntersectInformationStruct InterInfo8 = Plan2.calculateIntersection(Ray8);
//	VectorStructR3 InterP8 = InterInfo8.getIntersectionPoint();
//	IntersectInformationStruct InterInfo9 = Plan2.calculateIntersection(Ray9);
//	VectorStructR3 InterP9 = InterInfo9.getIntersectionPoint();
//
//	IntersectInformationStruct InterInfo10 = Plan2.calculateIntersection(Ray10);
//	VectorStructR3 InterP10 = InterInfo10.getIntersectionPoint();
//	IntersectInformationStruct InterInfo11 = Plan2.calculateIntersection(Ray11);
//	VectorStructR3 InterP11 = InterInfo11.getIntersectionPoint();
//	IntersectInformationStruct InterInfo12 = Plan2.calculateIntersection(Ray12);
//	VectorStructR3 InterP12 = InterInfo12.getIntersectionPoint();
//
//	std::vector<VectorStructR3> ReferenzVector2 = { { 0.0, 1.6666666667, 8.3333333333 },{ 0.0, 0.0, 10.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 10.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 } };
//	std::vector<VectorStructR3> checkVector2 = { InterP7, InterP8, InterP9, InterP10, InterP11, InterP12 };
//
//	// *****************************************************************************************************************
//	bool isRight2 = Math::compareAllVectorElements(checkVector2, ReferenzVector2, 9);
//	checkPlanSurface.push_back(isRight2);
//	// *****************************************************************************************************************
//
//	//____________________________________________________________________________________________________________________
//	//____________________________________________________________________________________________________________________
//
//	// Plan surface, rotation 45°, start point {0.0,0.0,10.0}
//	Ray_LLT Ray13(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 1.0, 5.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray14(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.0, 5.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray15(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -1.0, 5.0 }, /*wavelength*/500.0, 1.0);
//
//	Ray_LLT Ray16(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.0, 5.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray17(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.0, 5.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray18(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -3.0, 5.0 }, /*wavelength*/500.0, 1.0);
//
//	PlanGeometry_LLT Plan3(/*semiHeight*/3.0, /*point*/{ 0.5,1.0,10.0 }, /*direction*/{ 0.0,-1.0,1.0 }, /*refractiveSideA*/ 1.0, /*refractiveSideB*/ 1.0);
//
//	IntersectInformationStruct InterInfo13 = Plan3.calculateIntersection(Ray13);
//	VectorStructR3 InterP13 = InterInfo13.getIntersectionPoint();
//	IntersectInformationStruct InterInfo14 = Plan3.calculateIntersection(Ray14);
//	VectorStructR3 InterP14 = InterInfo14.getIntersectionPoint();
//	IntersectInformationStruct InterInfo15 = Plan3.calculateIntersection(Ray15);
//	VectorStructR3 InterP15 = InterInfo15.getIntersectionPoint();
//
//	IntersectInformationStruct InterInfo16 = Plan3.calculateIntersection(Ray16);
//	VectorStructR3 InterP16 = InterInfo16.getIntersectionPoint();
//	IntersectInformationStruct InterInfo17 = Plan3.calculateIntersection(Ray17);
//	VectorStructR3 InterP17 = InterInfo17.getIntersectionPoint();
//	IntersectInformationStruct InterInfo18 = Plan3.calculateIntersection(Ray18);
//	VectorStructR3 InterP18 = InterInfo18.getIntersectionPoint();
//
//	std::vector<VectorStructR3> ReferenzVector3 = { { 0.0, 2.25, 11.25 },{ 0.0, 0.0, 9.0 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.1666666666, 9.1666666667 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 } };
//	std::vector<VectorStructR3> checkVector3 = { InterP13, InterP14, InterP15, InterP16, InterP17, InterP18 };
//
//	// *****************************************************************************************************************
//	bool isRight3 = Math::compareAllVectorElements(checkVector3, ReferenzVector3, 9);
//	checkPlanSurface.push_back(isRight3);
//	// *****************************************************************************************************************
//
//	//____________________________________________________________________________________________________________________
//	//____________________________________________________________________________________________________________________
//
//	// Plan surface, rotation -45°, start point {0.0,0.0,10.0}
//	Ray_LLT Ray19(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 1.0, 5.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray20(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.0, 5.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray21(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -1.0, 5.0 }, /*wavelength*/500.0, 1.0);
//
//	Ray_LLT Ray22(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.0, 5.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray23(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.0, 5.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray24(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -3.0, 5.0 }, /*wavelength*/500.0, 1.0);
//
//	PlanGeometry_LLT Plan4(/*semiHeight*/3.0, /*point*/{ -0.5,1.0,10.0 }, /*direction*/{ 0.0,-1.0,-1.0 }, /*refractiveSideA*/ 1.0, /*refractiveSideB*/ 1.0);
//
//	IntersectInformationStruct InterInfo19 = Plan4.calculateIntersection(Ray19);
//	VectorStructR3 InterP19 = InterInfo19.getIntersectionPoint();
//	IntersectInformationStruct InterInfo20 = Plan4.calculateIntersection(Ray20);
//	VectorStructR3 InterP20 = InterInfo20.getIntersectionPoint();
//	IntersectInformationStruct InterInfo21 = Plan4.calculateIntersection(Ray21);
//	VectorStructR3 InterP21 = InterInfo21.getIntersectionPoint();
//
//	IntersectInformationStruct InterInfo22 = Plan4.calculateIntersection(Ray22);
//	VectorStructR3 InterP22 = InterInfo22.getIntersectionPoint();
//	IntersectInformationStruct InterInfo23 = Plan4.calculateIntersection(Ray23);
//	VectorStructR3 InterP23 = InterInfo23.getIntersectionPoint();
//	IntersectInformationStruct InterInfo24 = Plan4.calculateIntersection(Ray24);
//	VectorStructR3 InterP24 = InterInfo24.getIntersectionPoint();
//
//	std::vector<VectorStructR3> ReferenzVector4 = { { 0.0, 1.8333333333, 9.1666666667 },{ 0.0, 0.0, 11.0 },{ 0.0, 0.0, 0.0 },{ 0.0, -0.250, 11.250 },{ 0.0, 0.0, 0.0 },{ 0.0, 0.0, 0.0 } };
//	std::vector<VectorStructR3> checkVector4 = { InterP19, InterP20, InterP21, InterP22, InterP23, InterP24 };
//
//	// *****************************************************************************************************************
//	bool isRight4 = Math::compareAllVectorElements(checkVector4, ReferenzVector4, 9);
//	checkPlanSurface.push_back(isRight4);
//	// *****************************************************************************************************************
//
//	//____________________________________________________________________________________________________________________
//	//____________________________________________________________________________________________________________________
//
//	// Plan surface, rotation 45°, start point {0.0,0.0,10.0}
//	Ray_LLT Ray25(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 1.0, 5.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray26(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.0, 5.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray27(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -1.0, 5.0 }, /*wavelength*/500.0, 1.0);
//
//	Ray_LLT Ray28(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -1.0, 5.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray29(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -2.0, 5.0 }, /*wavelength*/500.0, 1.0);
//	Ray_LLT Ray30(/*origin*/{ 0.0, 2.0, 0.0 }, /*direction*/{ 0.0, -3.0, 5.0 }, /*wavelength*/500.0, 1.0);
//
//	PlanGeometry_LLT Plan5(/*semiHeight*/3.0, /*point*/{ -0.5,-1.0,10.0 }, /*direction*/{ 0.0, 1.0,-1.0 }, /*refractiveSideA*/ 1.0, /*refractiveSideB*/ 1.0);
//
//	IntersectInformationStruct InterInfo25 = Plan5.calculateIntersection(Ray25);
//	VectorStructR3 InterP25 = InterInfo25.getIntersectionPoint();
//	IntersectInformationStruct InterInfo26 = Plan5.calculateIntersection(Ray26);
//	VectorStructR3 InterP26 = InterInfo26.getIntersectionPoint();
//	IntersectInformationStruct InterInfo27 = Plan5.calculateIntersection(Ray27);
//	VectorStructR3 InterP27 = InterInfo27.getIntersectionPoint();
//
//	IntersectInformationStruct InterInfo28 = Plan5.calculateIntersection(Ray28);
//	VectorStructR3 InterP28 = InterInfo28.getIntersectionPoint();
//	IntersectInformationStruct InterInfo29 = Plan5.calculateIntersection(Ray29);
//	VectorStructR3 InterP29 = InterInfo29.getIntersectionPoint();
//	IntersectInformationStruct InterInfo30 = Plan5.calculateIntersection(Ray30);
//	VectorStructR3 InterP30 = InterInfo30.getIntersectionPoint();
//
//	std::vector<VectorStructR3> ReferenzVector5 = { { 0.0, 0.0, 0.0 },{ 0.0,0.0, 11.0 },{ 0.0, -1.8333333333, 9.1666666667 },{ 0.0, -0.16666666668, 10.833333333 },{ 0.0, -1.7142857143, 9.2857142857 },{ 0.0, -2.8750, 8.1250 } };
//	std::vector<VectorStructR3> checkVector5 = { InterP25, InterP26, InterP27, InterP28, InterP29, InterP30 };
//
//	// *****************************************************************************************************************
//	bool isRight5 = Math::compareAllVectorElements(checkVector5, ReferenzVector5, 9);
//	checkPlanSurface.push_back(isRight5);
//	// *****************************************************************************************************************

	// ____________________________________________________________________________________________________________________
	//____________________________________________________________________________________________________________________
	bool output = Math::checkTrueOfVectorElements(checkPlanSurface);
	return output;
}