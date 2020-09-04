#include "testLenseReplace.h"

#include "..\..\LowLevelTracing\OpticalSystem_LLT.h"
#include "..\..\OpticalSystemElement\OpticalSystemElement.h"

#include "..\..\FillAptertureStop\FillApertureStop.h"

//surface LLT
#include "..\..\LowLevelTracing\Surfaces\PlanGeometry_LLT.h"
#include "..\..\LowLevelTracing\Surfaces\SphericalSurface_LLT.h"
#include "..\..\LowLevelTracing\Surfaces\ApertureStop_LLT.h"

//surface HLT
#include "..\..\SurfaceElements\PlanElement.h"
#include "..\..\SurfaceElements\SphericalElement.h"
#include "..\..\SurfaceElements\ApertureStopElement.h"


//spot
#include "..\..\Analyse\Spot.h"
#include "..\..\Analyse\CardinalPoints.h"

// often use
#include "..\..\oftenUseNamespace\oftenUseNamespace.h"

#include "..\..\lensReplace\LensReplace.h"

testLensReplace::testLensReplace() { loadDefaulParameter_testLensReplace(); }

testLensReplace::~testLensReplace(){}

typedef std::shared_ptr< Element_CR > surfacePtr;
typedef std::shared_ptr< InteractionRay_LLT > interaction_ptr;

void testLensReplace::loadDefaulParameter_testLensReplace()
{
	mDefaulLight550 = oftenUse::buildDefaultLight(550.0);
	mGlasses.loadGlassCatalog_Schott();

	// field
	mStartOptA = { 0.0,0.0,0.0 };
	mStartOptA_vec.push_back(mStartOptA);

	// wavelength
	mWave550 = 550.0;
	mWave500_vec.push_back(mWave550);

	// tolerance
	mGlobalTolerance = 1.0;
}

bool testLensReplace::testLensReplace_superFct()
{
	std::vector<bool> workLensReplace_superFct;

	//// E0
	//bool checkE0 = testLensReplace_E0();
	//workLensReplace_superFct.push_back(checkE0);
	// 
	//// E1
	//bool checkE1 = testLensReplace_E1();
	//workLensReplace_superFct.push_back(checkE1);
	//
	//// E2
	//bool checkE2 = testLensReplace_E2();
	//workLensReplace_superFct.push_back(checkE2);

	// E3
	bool checkE3 = testLensReplace_E3();
	workLensReplace_superFct.push_back(checkE3);

	bool returnChecker_superFct = Math::checkTrueOfVectorElements(workLensReplace_superFct);
	return returnChecker_superFct;
}


bool testLensReplace::testLensReplace_E0()
{


	std::vector<bool> workLensReplace_E0;

	SphericalSurface_LLT S0_E0(/*radius*/30.0, /*semiHeight*/5.0, /*Apex of the sphere*/{ 0.0, 0.0, 25.0 },	/*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.67);
	SphericalSurface_LLT S1_E0(/*radius*/25.0, /*semiHeight*/5.0, /*Apex of the sphere*/{ 0.0, 0.0, 30.0}, /*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.73, /*refIndexSideB*/1.67);
	SphericalSurface_LLT S2_E0(/*radius*/20.0, /*semiHeight*/5.0, /*Apex of the sphere*/{ 0.0, 0.0, 32.0}, /*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.73);
	PlanGeometry_LLT P3_E0(/*semiHeight*/3.0, /*point*/{ 0.0,0.0,47 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiveSideA*/ 1.0, /*refractiveSideB*/ 1.0);
	   
	// build opitcal system
	OpticalSystem_LLT OptSysE0;
	OptSysE0.fillVectorSurfaceAndInteractingData(0, S0_E0.clone(), mRefrac.clone());
	OptSysE0.fillVectorSurfaceAndInteractingData(1, S1_E0.clone(), mRefrac.clone());
	OptSysE0.fillVectorSurfaceAndInteractingData(2, S2_E0.clone(), mRefrac.clone());
	OptSysE0.fillVectorSurfaceAndInteractingData(3, P3_E0.clone(), mAbsorb.clone());

	// *** test optical system *** //
	SequentialRayTracing seqTraceE0(OptSysE0);
	FillApertureStop fillAperE0(/*start point rays*/{ 0.0,0.0,0.0 }, /*semi height of aperture stop*/ 2.0,/*point of aperture stop*/{ 0.0,0.0,20.0 },/*direction of aperture stop*/{ 0.0,0.0,1.0 }, /*rings*/ 6,/*arms*/ 8,/*refractive index*/ 1.0,/*light*/ mDefaulLight550);
	seqTraceE0.seqRayTracingWithVectorOfLightRays(fillAperE0.getVectorWithLightRays());
	Spot spotE0(seqTraceE0.getAllInterPointsAtSurf_i_notFiltered(3),/*reference point*/ seqTraceE0.getAllInterPointsAtSurf_i_notFiltered(3)[0]);
	real rmsZemax_E0 = 1476.21;
	real rmsTOM_E0 = spotE0.getRMS_µm();
	bool checkerSystem_E0 = Math::compareTwoNumbers_decimals(rmsTOM_E0, rmsZemax_E0, 0);
	workLensReplace_E0.push_back(checkerSystem_E0);
	// *** *** //

	// check focal lenght
	LensReplace lensReplace;
	real focalLengthTOM = lensReplace.calcFocalLenghtOptSys(OptSysE0);
	real focalLengthZemax = 18.7599;
	bool checkCalcFocalLength = Math::compareTwoNumbers_decimals(focalLengthTOM, focalLengthZemax, 3);
	workLensReplace_E0.push_back(checkCalcFocalLength);

	// only the optical system (achromatic lens)
	OpticalSystem_LLT Achromat_E0;
	Achromat_E0.fillVectorSurfaceAndInteractingData(0, S0_E0.clone(), mRefrac.clone());
	Achromat_E0.fillVectorSurfaceAndInteractingData(1, S1_E0.clone(), mRefrac.clone());
	Achromat_E0.fillVectorSurfaceAndInteractingData(2, S2_E0.clone(), mRefrac.clone());

	// check thickness

	real thicknessTOM = lensReplace.calculateThickness_Z(Achromat_E0);
	real thicknessZemax = 7.0;
	bool checkCalcThickness_E0 = Math::compareTwoNumbers_decimals(thicknessTOM, thicknessZemax, 3);
	workLensReplace_E0.push_back(checkCalcThickness_E0);


	// check calc heihest semi height
	real semiHeightTOM = lensReplace.calcMaxSemiHeigh(Achromat_E0);
	real semiHeightZemax = 5.0;
	bool checkCalcHeighestSemiHeitght_E0 = Math::compareTwoNumbers_decimals(semiHeightTOM, semiHeightZemax, 3);
	workLensReplace_E0.push_back(checkCalcHeighestSemiHeitght_E0);


	bool returnChecker_E0 = Math::checkTrueOfVectorElements(workLensReplace_E0);
	return returnChecker_E0;
}


bool testLensReplace::testLensReplace_E1()
{


	Light_LLT LightE1;
	LightE1.setWavelength(550.0);

	std::vector<bool> workLensReplace_E1;

	ApertureStop_LLT aperStop_S0_E0(/*semiHeight*/ 1.0, /*point*/{ 0.0,0.0,20.0 }, /*direction*/{ 0.0,0.0,1.0 }, 1.0);
	SphericalSurface_LLT S1_E0(/*radius*/30.0, /*semiHeight*/5.0, /*Apex of the sphere*/{ 0.0, 0.0, 25.0 },	/*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.1);
	SphericalSurface_LLT S2_E0(/*radius*/25.0, /*semiHeight*/5.0, /*Apex of the sphere*/{ 0.0, 0.0, 30.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.2, /*refIndexSideB*/1.1);
	SphericalSurface_LLT S3_E0(/*radius*/20.0, /*semiHeight*/5.0, /*Apex of the sphere*/{ 0.0, 0.0, 32.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.2);
	SphericalSurface_LLT S4_E0(/*radius*/300.0, /*semiHeight*/6.0, /*Apex of the sphere*/{ 0.0, 0.0, 37.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.3, /*refIndexSideB*/1.0);
	SphericalSurface_LLT S5_E0(/*radius*/80.0, /*semiHeight*/6.0, /*Apex of the sphere*/{ 0.0, 0.0, 40.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.4, /*refIndexSideB*/1.3);
	SphericalSurface_LLT S6_E0(/*radius*/60.0, /*semiHeight*/6.0, /*Apex of the sphere*/{ 0.0, 0.0, 43.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.4, /*refIndexSideB*/1.0);
	SphericalSurface_LLT S7_E0(/*radius*/50.0, /*semiHeight*/7.0, /*Apex of the sphere*/{ 0.0, 0.0, 48.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
	SphericalSurface_LLT S8_E0(/*radius*/70.0, /*semiHeight*/7.0, /*Apex of the sphere*/{ 0.0, 0.0, 52.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.5, /*refIndexSideB*/1.6);
	SphericalSurface_LLT S9_E0(/*radius*/300.0, /*semiHeight*/7.0, /*Apex of the sphere*/{ 0.0, 0.0, 55.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.6, /*refIndexSideB*/1.0);
	SphericalSurface_LLT S10_E0(/*radius*/500.0, /*semiHeight*/8.0, /*Apex of the sphere*/{ 0.0, 0.0, 60.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.7, /*refIndexSideB*/1.0);
	SphericalSurface_LLT S11_E0(/*radius*/30.0, /*semiHeight*/8.0, /*Apex of the sphere*/{ 0.0, 0.0, 66.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.7, /*refIndexSideB*/1.8);
	SphericalSurface_LLT S12_E0(/*radius*/20.0, /*semiHeight*/8.0, /*Apex of the sphere*/{ 0.0, 0.0, 73.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.8);
	PlanGeometry_LLT P13_E0(/*semiHeight*/3.0, /*point*/{ 0.0,0.0,105.911128 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiveSideA*/ 1.0, /*refractiveSideB*/ 1.0);


	std::vector<std::shared_ptr<SurfaceIntersectionRay_LLT>> surface_ptr_E1{ aperStop_S0_E0.clone(),S1_E0.clone(),S2_E0.clone(),S3_E0.clone(),S4_E0.clone(),
		S5_E0.clone(),S6_E0.clone(), S7_E0.clone(),S8_E0.clone(),S9_E0.clone(),S10_E0.clone(),S11_E0.clone(),S12_E0.clone(), P13_E0.clone() };

	std::vector<std::shared_ptr<InteractionRay_LLT>> interaction_ptr_E1{ mDoNot.clone(),mRefrac.clone(),mRefrac.clone() ,mRefrac.clone() ,mRefrac.clone() ,mRefrac.clone() ,mRefrac.clone()
	,mRefrac.clone() ,mRefrac.clone() ,mRefrac.clone() ,mRefrac.clone() ,mRefrac.clone() ,mRefrac.clone(), mAbsorb.clone() };

	OpticalSystem_LLT optSye_LLT_E1(surface_ptr_E1, interaction_ptr_E1);

	// *** test optical system *** //
	// single ray trace
	Ray_LLT ray_E1(/*origin*/{ 0.0,0.0,0.0 },/*direction*/{ 0.0,1.0,20.0 },/*refractive index*/ 1.0);
	LightRayStruct lightRayE0(LightE1, ray_E1, 1);
	SequentialRayTracing seqTraceE1_single(optSye_LLT_E1);
	seqTraceE1_single.sequentialRayTracing(lightRayE0);
	VectorStructR3 interPointZemax{ 0.0,-0.025229984226,105.91112797 };
	VectorStructR3 interPointTOM = seqTraceE1_single.getAllInterPointsAtSurf_i_notFiltered(13)[0];
	bool checkSingRayTrace_E1 = Math::compareTwoVectorStructR3_decimals(interPointZemax, interPointTOM, 3);
	workLensReplace_E1.push_back(checkSingRayTrace_E1);

	// test rms
	SequentialRayTracing seqTraceE1(optSye_LLT_E1);
	FillApertureStop fillAperE0(/*start point rays*/{ 0.0,0.0,0.0 }, /*semi height of aperture stop*/ 1.0,/*point of aperture stop*/{ 0.0,0.0,20.0 },/*direction of aperture stop*/{ 0.0,0.0,1.0 }, /*rings*/ 6,/*arms*/ 8,/*refractive index*/ 1.0,/*light*/ LightE1);
	seqTraceE1.seqRayTracingWithVectorOfLightRays(fillAperE0.getVectorWithLightRays());
	Spot spotE1(seqTraceE1.getAllInterPointsAtSurf_i_notFiltered(13),/*reference point*/ seqTraceE1.getAllInterPointsAtSurf_i_notFiltered(13)[0]);
	real rmsZemax_E1 = 16.160;
	real rmsTOM_E1 = spotE1.getRMS_µm();
	bool checkerSystem_E1 = Math::compareTwoNumbers_decimals(rmsTOM_E1, rmsZemax_E1, 0);
	workLensReplace_E1.push_back(checkerSystem_E1);
	// *** *** //


	LensReplace lensReplace_E1;

	// check focal lenght
	real focalLengthTOM = lensReplace_E1.calcFocalLenghtOptSys(optSye_LLT_E1);
	real focalLengthZemax = 24.8177;
	bool checkCalcFocalLength_E1 = Math::compareTwoNumbers_decimals(focalLengthTOM, focalLengthZemax, 3);
	workLensReplace_E1.push_back(checkCalcFocalLength_E1);

	// check find lenses in opt sys
	std::vector<OpticalSystem_LLT> lensesInOptSys_E1 = lensReplace_E1.findLensesInOptSys_LLT(optSye_LLT_E1);
	real numSur0 = lensesInOptSys_E1[0].getPosAndInteractingSurface().size();
	bool checkNumSur0 = Math::compareTwoNumbers_decimals(numSur0,3,0);
	workLensReplace_E1.push_back(checkNumSur0);
	real numSur1 = lensesInOptSys_E1[1].getPosAndInteractingSurface().size();
	bool checkNumSur1 = Math::compareTwoNumbers_decimals(numSur1, 3, 0);
	workLensReplace_E1.push_back(checkNumSur1);
	real numSur2 = lensesInOptSys_E1[2].getPosAndInteractingSurface().size();
	bool checkNumSur2 = Math::compareTwoNumbers_decimals(numSur2, 3, 0);
	workLensReplace_E1.push_back(checkNumSur2);
	real numSur3 = lensesInOptSys_E1[3].getPosAndInteractingSurface().size();
	bool checkNumSur3 = Math::compareTwoNumbers_decimals(numSur3, 3, 0);
	workLensReplace_E1.push_back(checkNumSur3);

	// calculate parameter lenses
	LensReplace lensReplace_E1_calcPara;
	lensReplace_E1_calcPara.setOptSys_LLT(optSye_LLT_E1);
	lensReplace_E1_calcPara.replaceSuperFuction();
	std::vector<parameterLens> parameterLensesVec_E0 = lensReplace_E1_calcPara.getParameterLenses();
	bool sizeParameterLenses = parameterLensesVec_E0.size() == 4;
	workLensReplace_E1.push_back(sizeParameterLenses);



	bool returnChecker_E1 = Math::checkTrueOfVectorElements(workLensReplace_E1);
	return returnChecker_E1;
}


bool testLensReplace::testLensReplace_E2()
{

	std::vector<bool> workLensReplace_E2;

	ApertureStopElement A0_E2(/* semi height*/2.0, /*point*/{ 0.0,0.0,20.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ mGlasses.getAir());
	SphericalElement S1_E2(/*radius*/ 20.0, /*semi height*/ 8.0, /*point*/{ 0.0,0.0,25.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S2_E2(/*radius*/ 30.0, /*semi height*/ 8.0, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getNBK7_S1(), /*refractive index B*/mGlasses.getSF5_S1());
	SphericalElement S3_E2(/*radius*/ 25.0, /*semi height*/ 8.0, /*point*/{ 0.0,0.0,35.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getSF5_S1());
	PlanElement P4_E2(/*semi height*/ 99.0, /*point*/{ 0.0,0.0,85.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getAir());

	surfacePtr A0_E2_ptr = A0_E2.clone();
	surfacePtr S1_E2_ptr = S1_E2.clone();
	surfacePtr S2_E2_ptr = S2_E2.clone();
	surfacePtr S3_E2_ptr = S3_E2.clone();
	surfacePtr P4_E2_ptr = P4_E2.clone();

	std::vector<surfacePtr> opticalSystemE0_ptr{ A0_E2_ptr, S1_E2_ptr, S2_E2_ptr, S3_E2_ptr, P4_E2_ptr };
	std::vector<interaction_ptr> interactionsE0_ptr{ mDoNot.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };


	//	build optical system
	OpticalSystemElement optSystemElement_E2(opticalSystemE0_ptr, interactionsE0_ptr);
	optSystemElement_E2.setRefractiveIndexAccordingToWavelength(550.0);

	// *** test optical system *** //
	SequentialRayTracing seqTraceE2(optSystemElement_E2);
	FillApertureStop fillAperE2(/*start point rays*/{ 0.0,0.0,0.0 }, /*semi height of aperture stop*/ 2.0,/*point of aperture stop*/{ 0.0,0.0,20.0 },/*direction of aperture stop*/{ 0.0,0.0,1.0 }, /*rings*/ 6,/*arms*/ 8,/*refractive index*/ 1.0,/*light*/ mDefaulLight550);
	seqTraceE2.seqRayTracingWithVectorOfLightRays(fillAperE2.getVectorWithLightRays());
	Spot spotE2(seqTraceE2.getAllInterPointsAtSurf_i_notFiltered(4),/*reference point*/ seqTraceE2.getAllInterPointsAtSurf_i_notFiltered(4)[0]);
	real rmsZemax_E2 = 29.817;
	real rmsTOM_E2 = spotE2.getRMS_µm();
	bool checkerSystem_E2 = Math::compareTwoNumbers_decimals(rmsTOM_E2, rmsZemax_E2, 0);
	workLensReplace_E2.push_back(checkerSystem_E2);
	// *** *** //

	// *** check rotate opt sys ele *** //
	std::vector<surfacePtr> opticalSystemE0_ptr_toRotate{S1_E2_ptr, S2_E2_ptr, S3_E2_ptr};
	std::vector<interaction_ptr> interactionsE0_ptr_toRotate{mRefrac.clone(), mRefrac.clone(), mRefrac.clone()};
	OpticalSystemElement optSystemElement_E2_toRotate(opticalSystemE0_ptr_toRotate, interactionsE0_ptr_toRotate);

	OpticalSystemElement optSystemElement_E2_rotate = optSystemElement_E2.reverseOptSysEle(optSystemElement_E2_toRotate);
	OpticalSystem_LLT optSysE2_rotat_LLT = optSystemElement_E2_rotate.getLLTconversion_doConversion();
	optSysE2_rotat_LLT.printAllPositions();
	optSysE2_rotat_LLT.printAllRadii();

	optSystemElement_E2_rotate.fillInElementAndInteractionAtPos_i(0, A0_E2.clone(), mDoNot.clone());
	optSystemElement_E2_rotate.fillInElementAndInteractionAtPos_i(99, P4_E2.clone(), mAbsorb.clone());
	SequentialRayTracing seqTraceE2_rotate(optSystemElement_E2_rotate);
	FillApertureStop fillAperE2_rotate(/*start point rays*/{ 0.0,0.0,0.0 }, /*semi height of aperture stop*/ 2.0,/*point of aperture stop*/{ 0.0,0.0,20.0 },/*direction of aperture stop*/{ 0.0,0.0,1.0 }, /*rings*/ 6,/*arms*/ 8,/*refractive index*/ 1.0,/*light*/ mDefaulLight550);
	seqTraceE2_rotate.seqRayTracingWithVectorOfLightRays(fillAperE2_rotate.getVectorWithLightRays());
	Spot spotE2_rotate(seqTraceE2_rotate.getAllInterPointsAtSurf_i_notFiltered(4),/*reference point*/ seqTraceE2_rotate.getAllInterPointsAtSurf_i_notFiltered(4)[0]);
	real rmsZemax_E2_rotate = 38.684;
	real rmsTOM_E2_rotate = spotE2_rotate.getRMS_µm();
	bool checkerSystem_E2_rotate = Math::compareTwoNumbers_decimals(rmsTOM_E2_rotate, rmsZemax_E2_rotate, 0);
	workLensReplace_E2.push_back(checkerSystem_E2_rotate);
	// *** *** //

	bool returnChecker_E2 = Math::checkTrueOfVectorElements(workLensReplace_E2);
	return returnChecker_E2;
}

bool testLensReplace::testLensReplace_E3()
{

	std::vector<bool> workLensReplace_E3;

	ApertureStopElement A0_E3(/* semi height*/1.0, /*point*/{ 0.0,0.0,10.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ mGlasses.getAir());
	SphericalElement S1_E3(/*radius*/ 30.0, /*semi height*/ 6.0, /*point*/{ 0.0,0.0,15.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getSF5_S1());
	SphericalElement S2_E3(/*radius*/ 35.0, /*semi height*/ 6.0, /*point*/{ 0.0,0.0,20.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNBK7_S1(), /*refractive index B*/mGlasses.getSF5_S1());
	SphericalElement S3_E3(/*radius*/ 35.0, /*semi height*/ 6.0, /*point*/{ 0.0,0.0,23.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S4_E3(/*radius*/ 10.0, /*semi height*/ 6.0, /*point*/{ 0.0,0.0,33.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBAF10_S1());
	SphericalElement S5_E3(/*radius*/ 20.0, /*semi height*/ 6.0, /*point*/{ 0.0,0.0,38.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ mGlasses.getSF10_S1(), /*refractive index B*/mGlasses.getNBAF10_S1());
	SphericalElement S6_E3(/*radius*/ 25.0, /*semi height*/ 6.0, /*point*/{ 0.0,0.0,40.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getSF10_S1());
	PlanElement P7_E3(/*semi height*/ 99.0, /*point*/{ 0.0,0.0,50.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getAir());

	surfacePtr A0_E3_ptr = A0_E3.clone();
	surfacePtr S1_E3_ptr = S1_E3.clone();
	surfacePtr S2_E3_ptr = S2_E3.clone();
	surfacePtr S3_E3_ptr = S3_E3.clone();
	surfacePtr S4_E3_ptr = S4_E3.clone();
	surfacePtr S5_E3_ptr = S5_E3.clone();
	surfacePtr S6_E3_ptr = S6_E3.clone();
	surfacePtr P7_E3_ptr = P7_E3.clone();

	std::vector<surfacePtr> opticalSystem_E3_ptr{ A0_E3_ptr, S1_E3_ptr, S2_E3_ptr, S3_E3_ptr, S4_E3_ptr,S5_E3_ptr,S6_E3_ptr, P7_E3_ptr };
	std::vector<interaction_ptr> interactions_E3_ptr{ mDoNot.clone(),mRefrac.clone(),mRefrac.clone(),mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };


	//	build optical system
	OpticalSystemElement optSystemElement_E3(opticalSystem_E3_ptr, interactions_E3_ptr);
	optSystemElement_E3.setRefractiveIndexAccordingToWavelength(550.0);

	// check the start system
	std::vector<real> rms_Zemax{ 54.144 };
	bool test_E3 = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement_E3, mStartOptA_vec, mWave500_vec, rms_Zemax, mGlobalTolerance, compareTOM_Zemax::comEqual);
	workLensReplace_E3.push_back(test_E3);

	LensReplace lensReplace_E3(optSystemElement_E3);
	

	// Achromat 1
	real focalLensAchromat_1 = lensReplace_E3.getParameterLenses()[0].getFocalLengthMinMax().getValue();
	real focalLensAchromat_1_ref = 25.106;
	bool checkFocalLengthAchromat_1 = Math::compareTwoNumbers_tolerance(focalLensAchromat_1, focalLensAchromat_1_ref, mGlobalTolerance);
	workLensReplace_E3.push_back(checkFocalLengthAchromat_1);

	real semiHeightAchromat_1 = lensReplace_E3.getParameterLenses()[0].getSemiHeightMinMax().getValue();
	real semiHeightAchromat_1_ref = 6.0;
	bool checkSemiHeightAchromat_1 = Math::compareTwoNumbers_tolerance(semiHeightAchromat_1, semiHeightAchromat_1_ref, mGlobalTolerance);
	workLensReplace_E3.push_back(checkSemiHeightAchromat_1);

	real thicknessAchromat_1 = lensReplace_E3.getParameterLenses()[0].getThicknessMinMax().getValue();
	real thicknessAchromat_1_ref = 8.0;
	bool checkThicknessAchromat_1 = Math::compareTwoNumbers_tolerance(thicknessAchromat_1, thicknessAchromat_1_ref, mGlobalTolerance);
	workLensReplace_E3.push_back(checkThicknessAchromat_1);
	// ---

	// Achromat 2
	real focalLensAchromat_2 = lensReplace_E3.getParameterLenses()[1].getFocalLengthMinMax().getValue();
	real focalLensAchromat_2_ref = 11.610107;
	bool checkFocalLengthAchromat_2 = Math::compareTwoNumbers_tolerance(focalLensAchromat_2, focalLensAchromat_2_ref, mGlobalTolerance);
	workLensReplace_E3.push_back(checkFocalLengthAchromat_2);

	real semiHeightAchromat_2 = lensReplace_E3.getParameterLenses()[1].getSemiHeightMinMax().getValue();
	real semiHeightAchromat_2_ref = 6.0;
	bool checkSemiHeightAchromat_2 = Math::compareTwoNumbers_tolerance(semiHeightAchromat_2, semiHeightAchromat_2_ref, mGlobalTolerance);
	workLensReplace_E3.push_back(checkSemiHeightAchromat_2);

	real thicknessAchromat_2 = lensReplace_E3.getParameterLenses()[1].getThicknessMinMax().getValue();
	real thicknessAchromat_2_ref = 7.0;
	bool checkThicknessAchromat_2 = Math::compareTwoNumbers_tolerance(thicknessAchromat_2, thicknessAchromat_2_ref, mGlobalTolerance);
	workLensReplace_E3.push_back(checkThicknessAchromat_2);
	// ---

	std::vector<lensTypes> loadLensCatalogEO_vec;
	loadLensCatalogEO_vec.push_back(lensTypes::DConvexL);
	loadLensCatalogEO_vec.push_back(lensTypes::posAchromat);
	loadLensCatalogEO_vec.push_back(lensTypes::PConvexL);
	loadLensCatalogEO_vec.push_back(lensTypes::DConcavL);
	loadLensCatalogEO_vec.push_back(lensTypes::PConcavL);

	lensReplace_E3.loadLensCata(loadLensCatalogEO_vec);

	// first lens
	OptSysEle_Merit_LensType bestLensForAchromat_1 = lensReplace_E3.checkLensCatalogsForBestFitLens(/*lens number*/0, /*parameter lens*/ lensReplace_E3.getParameterLenses()[0]);
	LensReplace replacedAchromat_1(bestLensForAchromat_1.getOptSysEle());
	
	real replaced_focalLensAchromat_1 = replacedAchromat_1.getParameterLenses()[0].getFocalLengthMinMax().getValue();
	bool checkReplaceFocallength_1 = std::abs(replaced_focalLensAchromat_1 - focalLensAchromat_1) < 1.0;
	workLensReplace_E3.push_back(checkReplaceFocallength_1);

	real replaced_semiHeightAchromat_1 = replacedAchromat_1.getParameterLenses()[0].getSemiHeightMinMax().getValue();
	bool checkReplacesSemiHeight_1 = std::abs(replaced_semiHeightAchromat_1 - semiHeightAchromat_1) < 1.0;
	workLensReplace_E3.push_back(checkReplacesSemiHeight_1);

	real replace_thicknessAchromat_1 = replacedAchromat_1.getParameterLenses()[0].getThicknessMinMax().getValue();
	bool checkReplaceThickness_1 = std::abs(replace_thicknessAchromat_1 - thicknessAchromat_1) < 3.0;
	workLensReplace_E3.push_back(checkReplaceThickness_1);
	// ***

	// second lens
	OptSysEle_Merit_LensType bestLensForAchromat_2 = lensReplace_E3.checkLensCatalogsForBestFitLens(/*lens number*/1, /*parameter lens*/ lensReplace_E3.getParameterLenses()[1]);
	LensReplace replacedAchromat_2(bestLensForAchromat_2.getOptSysEle());
	
	real replaced_focalLensAchromat_2 = replacedAchromat_2.getParameterLenses()[0].getFocalLengthMinMax().getValue();
	bool checkReplaceFocallength_2 = std::abs(replaced_focalLensAchromat_2 - focalLensAchromat_2) < 1.0;
	workLensReplace_E3.push_back(checkReplaceFocallength_2);

	real replaced_semiHeightAchromat_2 = replacedAchromat_2.getParameterLenses()[0].getSemiHeightMinMax().getValue();
	bool checkReplacesSemiHeight_2 = std::abs(replaced_semiHeightAchromat_2 - semiHeightAchromat_2) < 2.0;
	workLensReplace_E3.push_back(checkReplacesSemiHeight_2);

	real replace_thicknessAchromat_2 = replacedAchromat_2.getParameterLenses()[0].getThicknessMinMax().getValue();
	bool checkReplaceThickness_2 = std::abs(replace_thicknessAchromat_2 - thicknessAchromat_2) < 3.0;
	workLensReplace_E3.push_back(checkReplaceThickness_2);
	// ***

	// replace lens 0
	lensReplace_E3.replaceLens(0, bestLensForAchromat_1.getOptSysEle());
	OpticalSystemElement optSysEle_replacedLens_0 = lensReplace_E3.getOpticalSysEle();

	oftenUse::print(optSysEle_replacedLens_0, mWave550);

	std::vector<real> rms_replace0_ref = { 135.087 };
	bool checkReplace0 = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSysEle_replacedLens_0, mStartOptA_vec, mWave500_vec, rms_replace0_ref, mGlobalTolerance, compareTOM_Zemax::comEqual);


	bool returnChecker_E3 = Math::checkTrueOfVectorElements(workLensReplace_E3);
	return returnChecker_E3;
}