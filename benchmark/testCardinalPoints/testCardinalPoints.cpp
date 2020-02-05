
#include "testCardinalPoints.h"

// include surfaces
#include "..\..\LowLevelTracing\Surfaces\SphericalSurface_LLT.h"
#include "..\..\LowLevelTracing\Surfaces\PlanGeometry_LLT.h"
#include "..\..\LowLevelTracing\Surfaces\ApertureStop_LLT.h"

// include interactions
#include "..\..\LowLevelTracing\Interaction\Absorb_LLT.h"
#include "..\..\LowLevelTracing\Interaction\DoNothingInteraction_LLT.h"
#include "..\..\LowLevelTracing\Interaction\RefractedRay_LLT.h"

// include optical system
#include "..\..\LowLevelTracing\OpticalSystem_LLT.h"

// include sequential ray tracing 
#include "..\..\SequentialRayTracing\SequentialRayTracer.h"

// include cardinal points
#include "..\..\Analyse\CardinalPoints.h"

testCardinalPoints::testCardinalPoints() {}

testCardinalPoints::~testCardinalPoints() {}


bool testCardinalPoints::superFuncTestCalcCardinalPoints()
{
	std::vector<bool> checkCalcCardinal;

	bool testE0 = testCalcCardinalPointsE0();
	checkCalcCardinal.push_back(testE0);
	bool testE1 = testCalcCardinalPointsE1();
	checkCalcCardinal.push_back(testE1);
	bool testE2 = testCalcCardinalPointsE2();
	checkCalcCardinal.push_back(testE2);
	bool testE3 = testCalcCardinalPointsE3();
	checkCalcCardinal.push_back(testE3);

	bool returnCheck = Math::checkTrueOfVectorElements(checkCalcCardinal);

	return returnCheck;
}

bool testCardinalPoints::testCalcCardinalPointsE0()
{
	std::vector<bool> checkE0_vecBool;

	RefractedRay_LLT refrac;
	Absorb_LLT absorb;
	DoNothingInteraction_LLT doNothing;
	Light_LLT Light;
	Light.setWavelength(550.0);


	SphericalSurface_LLT SphericalSurface1E0(/*radius*/5.5, /*semiHeight*/3.0, /*Apex of the sphere*/{ 0.0,0.0,5.0 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
	SphericalSurface_LLT SphericalSurface2E0(/*radius*/8, /*semiHeight*/3.0, /*Apex of the sphere*/{ 0.0,0.0,10.0 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
	ApertureStop_LLT ApertureStop0E0(1.0, { 0.0,0.0,15.0 }, { 0.0,0.0,1.0 }, 1.0);
	SphericalSurface_LLT SphericalSurface3E0(/*radius*/100.0, /*semiHeight*/3.0, /*Apex of the sphere*/{ 0.0,0.0,25.0 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.5, /*refIndexSideB*/1.0);
	SphericalSurface_LLT SphericalSurface4E0(/*radius*/100.0, /*semiHeight*/3.0, /*Apex of the sphere*/{ 0.0,0.0,30.0 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.5, /*refIndexSideB*/1.0);
	SphericalSurface_LLT SphericalSurface5E0(/*radius*/40.0, /*semiHeight*/3.0, /*Apex of the sphere*/{ 0.0,0.0,35.0 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.5, /*refIndexSideB*/1.0);
	SphericalSurface_LLT SphericalSurface6E0(/*radius*/40.0, /*semiHeight*/3.0, /*Apex of the sphere*/{ 0.0,0.0,40.0 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.5, /*refIndexSideB*/1.0);
	PlanGeometry_LLT Plan5E0(/*semi Height*/ 3.0, /*apex*/{ 0.0,0.0,50.0 }, /*direction*/{ 0.0,0.0,1.0 }, 1.5, 1.0);


	//*************
	// build the optical system
	OpticalSystem_LLT optSysE0;

	optSysE0.fillVectorSurfaceAndInteractingData(0, SphericalSurface1E0.clone(), refrac.clone());
	optSysE0.fillVectorSurfaceAndInteractingData(1, SphericalSurface2E0.clone(), refrac.clone());
	optSysE0.fillVectorSurfaceAndInteractingData(2, ApertureStop0E0.clone(), doNothing.clone());
	optSysE0.fillVectorSurfaceAndInteractingData(3, SphericalSurface3E0.clone(), refrac.clone());
	optSysE0.fillVectorSurfaceAndInteractingData(4, SphericalSurface4E0.clone(), refrac.clone());
	optSysE0.fillVectorSurfaceAndInteractingData(5, SphericalSurface5E0.clone(), refrac.clone());
	optSysE0.fillVectorSurfaceAndInteractingData(6, SphericalSurface6E0.clone(), refrac.clone());
	optSysE0.fillVectorSurfaceAndInteractingData(7, Plan5E0.clone(), absorb.clone());


	CardinalPoints calcCardinalPointsE0(optSysE0);

	real mEFL_ref = 4.52272;
	real mPP_ref = -2.633821;
	real mAntiPP_ref = -28.752718;
	real mEXPP_accordingToLastSurface_ref = -24.29743;
	real mEXPD_ref = 1.211248;
	real mMag_ref = 5.2609;

	real mEFL_calc = calcCardinalPointsE0.getEFL();
	real mPP_calc = calcCardinalPointsE0.getPrincipaPlan();
	real mAntiPP_calc = calcCardinalPointsE0.getAntiPP();
	real mEXPP_accordingToLastSurface_calc = calcCardinalPointsE0.getExitPupilPosition_lastSurface();
	real mEXPD_calc = calcCardinalPointsE0.getExitPupilDiameter();
	real mMag_calc = calcCardinalPointsE0.getMagnification();

	bool checkEFL = Math::compareTwoNumbers(mEFL_ref, mEFL_calc, 4);
	checkE0_vecBool.push_back(checkEFL);
	bool checkPP = Math::compareTwoNumbers(mPP_ref, mPP_calc, 4);
	checkE0_vecBool.push_back(checkPP);
	bool checkAntiPP = Math::compareTwoNumbers(mAntiPP_ref, mAntiPP_calc, 4);
	checkE0_vecBool.push_back(checkAntiPP);
	bool checkEXPP = Math::compareTwoNumbers(mEXPP_accordingToLastSurface_ref, mEXPP_accordingToLastSurface_calc, 4);
	checkE0_vecBool.push_back(checkEXPP);
	bool checkEXPD = Math::compareTwoNumbers(mEXPD_ref, mEXPD_calc, 4);
	checkE0_vecBool.push_back(checkEXPD);
	bool checkMag = Math::compareTwoNumbers(mMag_ref, mMag_calc, 4);
	checkE0_vecBool.push_back(checkMag);




	bool checkE0 = Math::checkTrueOfVectorElements(checkE0_vecBool);
	return checkE0;

}
bool testCardinalPoints::testCalcCardinalPointsE1()
{

	std::vector<bool> checkE1_vecBool;

	RefractedRay_LLT refrac;
	Absorb_LLT absorb;
	DoNothingInteraction_LLT doNothing;
	Light_LLT Light;
	Light.setWavelength(550.0);

	ApertureStop_LLT ApertureStop0E1(1.0, { 0.0,0.0,5.0 }, { 0.0,0.0,1.0 }, 1.0);
	SphericalSurface_LLT SphericalSurface1E1(/*radius*/5.5, /*semiHeight*/3.0, /*Apex of the sphere*/{ 0.0,0.0,10.0 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
	SphericalSurface_LLT SphericalSurface2E1(/*radius*/8, /*semiHeight*/3.0, /*Apex of the sphere*/{ 0.0,0.0,15.0 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
	SphericalSurface_LLT SphericalSurface3E1(/*radius*/100.0, /*semiHeight*/3.0, /*Apex of the sphere*/{ 0.0,0.0,20.0 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.5, /*refIndexSideB*/1.0);
	SphericalSurface_LLT SphericalSurface4E1(/*radius*/100.0, /*semiHeight*/3.0, /*Apex of the sphere*/{ 0.0,0.0,25.0 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.5, /*refIndexSideB*/1.0);
	PlanGeometry_LLT Plan5E1(/*semi Height*/ 3.0, /*apex*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0,1.0 }, 1.5, 1.0);


	//*************
	// build the optical system
	OpticalSystem_LLT optSysE1;
	optSysE1.fillVectorSurfaceAndInteractingData(0, ApertureStop0E1.clone(), doNothing.clone());
	optSysE1.fillVectorSurfaceAndInteractingData(1, SphericalSurface1E1.clone(), refrac.clone());
	optSysE1.fillVectorSurfaceAndInteractingData(2, SphericalSurface2E1.clone(), refrac.clone());
	optSysE1.fillVectorSurfaceAndInteractingData(3, SphericalSurface3E1.clone(), refrac.clone());
	optSysE1.fillVectorSurfaceAndInteractingData(4, SphericalSurface4E1.clone(), refrac.clone());
	optSysE1.fillVectorSurfaceAndInteractingData(5, Plan5E1.clone(), absorb.clone());


	CardinalPoints calcCardinalPointsE1(optSysE1);



	real mEFL_ref = 7.328015;
	real mPP_ref = 5.891194;
	real mAntiPP_ref = -15.429237;
	real mEXPP_accordingToLastSurface_ref = -45.47525;
	real mEXPD_ref = 10.20031;
	real mMag_ref = 1.28557;

	real mEFL_calc = calcCardinalPointsE1.getEFL();
	real mPP_calc = calcCardinalPointsE1.getPrincipaPlan();
	real mAntiPP_calc = calcCardinalPointsE1.getAntiPP();
	real mEXPP_accordingToLastSurface_calc = calcCardinalPointsE1.getExitPupilPosition_lastSurface();
	real mEXPD_calc = calcCardinalPointsE1.getExitPupilDiameter();
	real mMag_calc = calcCardinalPointsE1.getMagnification();

	bool checkEFL = Math::compareTwoNumbers(mEFL_ref, mEFL_calc, 4);
	checkE1_vecBool.push_back(checkEFL);
	bool checkPP = Math::compareTwoNumbers(mPP_ref, mPP_calc, 4);
	checkE1_vecBool.push_back(checkPP);
	bool checkAntiPP = Math::compareTwoNumbers(mAntiPP_ref, mAntiPP_calc, 4);
	checkE1_vecBool.push_back(checkAntiPP);
	bool checkEXPP = Math::compareTwoNumbers(mEXPP_accordingToLastSurface_ref, mEXPP_accordingToLastSurface_calc, 4);
	checkE1_vecBool.push_back(checkEXPP);
	bool checkEXPD = Math::compareTwoNumbers(mEXPD_ref, mEXPD_calc, 4);
	checkE1_vecBool.push_back(checkEXPD);
	bool checkMag = Math::compareTwoNumbers(mMag_ref, mMag_calc, 4);
	checkE1_vecBool.push_back(checkMag);


	bool checkE1 = Math::checkTrueOfVectorElements(checkE1_vecBool);
	return checkE1;


}


bool testCardinalPoints::testCalcCardinalPointsE2()
{

	std::vector<bool> checkE2_vecBool;

	RefractedRay_LLT refrac;
	Absorb_LLT absorb;
	DoNothingInteraction_LLT doNothing;
	Light_LLT Light;
	Light.setWavelength(550.0);


	SphericalSurface_LLT SphericalSurface1E2(/*radius*/20.0, /*semiHeight*/4.0, /*Apex of the sphere*/{ 0.0,0.0,10.0 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
	SphericalSurface_LLT SphericalSurface2E2(/*radius*/14.0, /*semiHeight*/4.0, /*Apex of the sphere*/{ 0.0,0.0,15.0 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
	SphericalSurface_LLT SphericalSurface3E2(/*radius*/15.0, /*semiHeight*/4.0, /*Apex of the sphere*/{ 0.0,0.0,25.0 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.5, /*refIndexSideB*/1.0);
	SphericalSurface_LLT SphericalSurface4E2(/*radius*/15.0, /*semiHeight*/4.0, /*Apex of the sphere*/{ 0.0,0.0,30.0 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.5, /*refIndexSideB*/1.0);
	ApertureStop_LLT ApertureStop0E2(1.0, { 0.0,0.0,40.0 }, { 0.0,0.0,1.0 }, 1.0);
	SphericalSurface_LLT SphericalSurface5E2(/*radius*/25.0, /*semiHeight*/3.0, /*Apex of the sphere*/{ 0.0,0.0,50.0 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.5, /*refIndexSideB*/1.0);
	SphericalSurface_LLT SphericalSurface6E2(/*radius*/60.0, /*semiHeight*/4.0, /*Apex of the sphere*/{ 0.0,0.0,55.0 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.5, /*refIndexSideB*/1.0);
	SphericalSurface_LLT SphericalSurface7E2(/*radius*/40.0, /*semiHeight*/4.0, /*Apex of the sphere*/{ 0.0,0.0,65.0 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.5, /*refIndexSideB*/1.0);
	SphericalSurface_LLT SphericalSurface8E2(/*radius*/40.0, /*semiHeight*/4.0, /*Apex of the sphere*/{ 0.0,0.0,70.0 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.5, /*refIndexSideB*/1.0);
	PlanGeometry_LLT Plan9E2(/*semi Height*/ 4.0, /*apex*/{ 0.0,0.0,80.0 }, /*direction*/{ 0.0,0.0,1.0 }, 1.5, 1.0);


	//*************
	// build the optical system
	OpticalSystem_LLT optSysE2;

	optSysE2.fillVectorSurfaceAndInteractingData(0, SphericalSurface1E2.clone(), refrac.clone());
	optSysE2.fillVectorSurfaceAndInteractingData(1, SphericalSurface2E2.clone(), refrac.clone());
	optSysE2.fillVectorSurfaceAndInteractingData(3, SphericalSurface3E2.clone(), refrac.clone());
	optSysE2.fillVectorSurfaceAndInteractingData(4, SphericalSurface4E2.clone(), refrac.clone());
	optSysE2.fillVectorSurfaceAndInteractingData(2, ApertureStop0E2.clone(), doNothing.clone());
	optSysE2.fillVectorSurfaceAndInteractingData(5, SphericalSurface5E2.clone(), refrac.clone());
	optSysE2.fillVectorSurfaceAndInteractingData(6, SphericalSurface6E2.clone(), refrac.clone());
	optSysE2.fillVectorSurfaceAndInteractingData(5, SphericalSurface7E2.clone(), refrac.clone());
	optSysE2.fillVectorSurfaceAndInteractingData(6, SphericalSurface8E2.clone(), refrac.clone());
	optSysE2.fillVectorSurfaceAndInteractingData(7, Plan9E2.clone(), absorb.clone());


	CardinalPoints calcCardinalPointsE2(optSysE2);

	real mEFL_ref = 10.279011;
	real mPP_ref = -51.746677;
	real mAntiPP_ref = -37.195998;
	real mEXPP_accordingToLastSurface_ref = -25.83053;
	real mEXPD_ref = 0.9685867;
	real mMag_ref = -1.28436;

	real mEFL_calc = calcCardinalPointsE2.getEFL();
	real mPP_calc = calcCardinalPointsE2.getPrincipaPlan();
	real mAntiPP_calc = calcCardinalPointsE2.getAntiPP();
	real mEXPP_accordingToLastSurface_calc = calcCardinalPointsE2.getExitPupilPosition_lastSurface();
	real mEXPD_calc = calcCardinalPointsE2.getExitPupilDiameter();
	real mMag_calc = calcCardinalPointsE2.getMagnification();

	bool checkEFL = Math::compareTwoNumbers(mEFL_ref, mEFL_calc, 4);
	checkE2_vecBool.push_back(checkEFL);
	bool checkPP = Math::compareTwoNumbers(mPP_ref, mPP_calc, 4);
	checkE2_vecBool.push_back(checkPP);
	bool checkAntiPP = Math::compareTwoNumbers(mAntiPP_ref, mAntiPP_calc, 4);
	checkE2_vecBool.push_back(checkAntiPP);
	bool checkEXPP = Math::compareTwoNumbers(mEXPP_accordingToLastSurface_ref, mEXPP_accordingToLastSurface_calc, 4);
	checkE2_vecBool.push_back(checkEXPP);
	bool checkEXPD = Math::compareTwoNumbers(mEXPD_ref, mEXPD_calc, 4);
	checkE2_vecBool.push_back(checkEXPD);
	bool checkMag = Math::compareTwoNumbers(mMag_ref, mMag_calc, 4);
	checkE2_vecBool.push_back(checkMag);

	bool checkE2 = Math::checkTrueOfVectorElements(checkE2_vecBool);
	return checkE2;


}

bool testCardinalPoints::testCalcCardinalPointsE3()
{

	std::vector<bool> checkE3_vecBool;

	RefractedRay_LLT refrac;
	Absorb_LLT absorb;
	DoNothingInteraction_LLT doNothing;
	Light_LLT Light;
	Light.setWavelength(550.0);


	SphericalSurface_LLT SphericalSurface1E3(/*radius*/30.0, /*semiHeight*/5.0, /*Apex of the sphere*/{ 0.0,0.0,10.0 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
	SphericalSurface_LLT SphericalSurface2E3(/*radius*/12.0, /*semiHeight*/5.0, /*Apex of the sphere*/{ 0.0,0.0,15.0 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.5, /*refIndexSideB*/1.0);
	SphericalSurface_LLT SphericalSurface3E3(/*radius*/18.0, /*semiHeight*/5.0, /*Apex of the sphere*/{ 0.0,0.0,25.0 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
	SphericalSurface_LLT SphericalSurface4E3(/*radius*/60.0, /*semiHeight*/5.0, /*Apex of the sphere*/{ 0.0,0.0,30.0 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.5, /*refIndexSideB*/1.0);
	SphericalSurface_LLT SphericalSurface5E3(/*radius*/15.0, /*semiHeight*/5.0, /*Apex of the sphere*/{ 0.0,0.0,45.0 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.5, /*refIndexSideB*/1.0);
	SphericalSurface_LLT SphericalSurface6E3(/*radius*/15.0, /*semiHeight*/5.0, /*Apex of the sphere*/{ 0.0,0.0,50.0 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.5, /*refIndexSideB*/1.0);
	ApertureStop_LLT ApertureStop0E3(0.5, { 0.0,0.0,60.0 }, { 0.0,0.0,1.0 }, 1.0);
	SphericalSurface_LLT SphericalSurface7E3(/*radius*/10.0, /*semiHeight*/5.0, /*Apex of the sphere*/{ 0.0,0.0,80.0 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
	SphericalSurface_LLT SphericalSurface8E3(/*radius*/25.0, /*semiHeight*/5.0, /*Apex of the sphere*/{ 0.0,0.0,85.0 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
	PlanGeometry_LLT Plan9E3(/*semi Height*/ 5.0, /*apex*/{ 0.0,0.0,105.0 }, /*direction*/{ 0.0,0.0,1.0 }, 1.5, 1.0);


	//*************
	// build the optical system
	OpticalSystem_LLT optSysE3;

	optSysE3.fillVectorSurfaceAndInteractingData(0, SphericalSurface1E3.clone(), refrac.clone());
	optSysE3.fillVectorSurfaceAndInteractingData(1, SphericalSurface2E3.clone(), refrac.clone());
	optSysE3.fillVectorSurfaceAndInteractingData(2, SphericalSurface3E3.clone(), refrac.clone());
	optSysE3.fillVectorSurfaceAndInteractingData(3, SphericalSurface4E3.clone(), refrac.clone());
	optSysE3.fillVectorSurfaceAndInteractingData(4, SphericalSurface5E3.clone(), refrac.clone());
	optSysE3.fillVectorSurfaceAndInteractingData(5, SphericalSurface6E3.clone(), refrac.clone());
	optSysE3.fillVectorSurfaceAndInteractingData(6, ApertureStop0E3.clone(), doNothing.clone());
	optSysE3.fillVectorSurfaceAndInteractingData(7, SphericalSurface7E3.clone(), refrac.clone());
	optSysE3.fillVectorSurfaceAndInteractingData(8, SphericalSurface8E3.clone(), refrac.clone());
	optSysE3.fillVectorSurfaceAndInteractingData(9, Plan9E3.clone(), absorb.clone());


	CardinalPoints calcCardinalPointsE3(optSysE3);

	real mEFL_ref = 5.936132;
	real mPP_ref = 40.007814;
	real mAntiPP_ref = -6.372792;
	real mEXPP_accordingToLastSurface_ref = 30.00001;
	real mEXPD_ref = 2.500001;
	real mMag_ref = 0.479437;

	real mEFL_calc = calcCardinalPointsE3.getEFL();
	real mPP_calc = calcCardinalPointsE3.getPrincipaPlan();
	real mAntiPP_calc = calcCardinalPointsE3.getAntiPP();
	real mEXPP_accordingToLastSurface_calc = calcCardinalPointsE3.getExitPupilPosition_lastSurface();
	real mEXPD_calc = calcCardinalPointsE3.getExitPupilDiameter();
	real mMag_calc = calcCardinalPointsE3.getMagnification();

	bool checkEFL = Math::compareTwoNumbers(mEFL_ref, mEFL_calc, 4);
	checkE3_vecBool.push_back(checkEFL);
	bool checkPP = Math::compareTwoNumbers(mPP_ref, mPP_calc, 4);
	checkE3_vecBool.push_back(checkPP);
	bool checkAntiPP = Math::compareTwoNumbers(mAntiPP_ref, mAntiPP_calc, 4);
	checkE3_vecBool.push_back(checkAntiPP);
	bool checkEXPP = Math::compareTwoNumbers(mEXPP_accordingToLastSurface_ref, mEXPP_accordingToLastSurface_calc, 4);
	checkE3_vecBool.push_back(checkEXPP);
	bool checkEXPD = Math::compareTwoNumbers(mEXPD_ref, mEXPD_calc, 4);
	checkE3_vecBool.push_back(checkEXPD);
	bool checkMag = Math::compareTwoNumbers(mMag_ref, mMag_calc, 4);
	checkE3_vecBool.push_back(checkMag);


	bool checkE3 = Math::checkTrueOfVectorElements(checkE3_vecBool);
	return checkE3;


}