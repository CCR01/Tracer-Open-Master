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

//interactions
#include "..\..\LowLevelTracing\Interaction\RefractedRay_LLT.h"
#include "..\..\LowLevelTracing\Interaction\DoNothingInteraction_LLT.h"
#include "..\..\LowLevelTracing\Interaction\Absorb_LLT.h"

//spot
#include "..\..\Analyse\Spot.h"

// include the glas cataloge
#include "..\..\Glasses\Glasses.h"

#include "..\..\lensReplace\LensReplace.h"

testLensReplace::testLensReplace(){}

testLensReplace::~testLensReplace(){}



bool testLensReplace::testLensReplace_superFct()
{
	std::vector<bool> workLensReplace_superFct;
	// E0
	bool checkE0 = testLensReplace_E0();
	workLensReplace_superFct.push_back(checkE0);
	 
	// E1
	bool checkE1 = testLensReplace_E1();
	workLensReplace_superFct.push_back(checkE1);

	bool checkE2 = testLensReplace_E2();
	workLensReplace_superFct.push_back(checkE2);

	bool returnChecker_superFct = Math::checkTrueOfVectorElements(workLensReplace_superFct);
	return returnChecker_superFct;
}


bool testLensReplace::testLensReplace_E0()
{
	RefractedRay_LLT refrac;
	Absorb_LLT absorb;
	
	Light_LLT LightE0;
	LightE0.setWavelength(550.0);

	std::vector<bool> workLensReplace_E0;

	SphericalSurface_LLT S0_E0(/*radius*/30.0, /*semiHeight*/5.0, /*Apex of the sphere*/{ 0.0, 0.0, 25.0 },	/*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.67);
	SphericalSurface_LLT S1_E0(/*radius*/25.0, /*semiHeight*/5.0, /*Apex of the sphere*/{ 0.0, 0.0, 30.0}, /*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.73, /*refIndexSideB*/1.67);
	SphericalSurface_LLT S2_E0(/*radius*/20.0, /*semiHeight*/5.0, /*Apex of the sphere*/{ 0.0, 0.0, 32.0}, /*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.73);
	PlanGeometry_LLT P3_E0(/*semiHeight*/3.0, /*point*/{ 0.0,0.0,47 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiveSideA*/ 1.0, /*refractiveSideB*/ 1.0);
	   
	// build opitcal system
	OpticalSystem_LLT OptSysE0;
	OptSysE0.fillVectorSurfaceAndInteractingData(0, S0_E0.clone(), refrac.clone());
	OptSysE0.fillVectorSurfaceAndInteractingData(1, S1_E0.clone(), refrac.clone());
	OptSysE0.fillVectorSurfaceAndInteractingData(2, S2_E0.clone(), refrac.clone());
	OptSysE0.fillVectorSurfaceAndInteractingData(3, P3_E0.clone(), absorb.clone());

	// *** test optical system *** //
	SequentialRayTracing seqTraceE0(OptSysE0);
	FillApertureStop fillAperE0(/*start point rays*/{ 0.0,0.0,0.0 }, /*semi height of aperture stop*/ 2.0,/*point of aperture stop*/{ 0.0,0.0,20.0 },/*direction of aperture stop*/{ 0.0,0.0,1.0 }, /*rings*/ 6,/*arms*/ 8,/*refractive index*/ 1.0,/*light*/ LightE0);
	seqTraceE0.seqRayTracingWithVectorOfLightRays(fillAperE0.getVectorWithLightRays());
	Spot spotE0(seqTraceE0.getAllInterPointsAtSurf_i(3),/*reference point*/ seqTraceE0.getAllInterPointsAtSurf_i(3)[0]);
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
	Achromat_E0.fillVectorSurfaceAndInteractingData(0, S0_E0.clone(), refrac.clone());
	Achromat_E0.fillVectorSurfaceAndInteractingData(1, S1_E0.clone(), refrac.clone());
	Achromat_E0.fillVectorSurfaceAndInteractingData(2, S2_E0.clone(), refrac.clone());

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
	DoNothingInteraction_LLT doNot;
	RefractedRay_LLT refrac;
	Absorb_LLT absorb;

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

	std::vector<std::shared_ptr<InteractionRay_LLT>> interaction_ptr_E1{ doNot.clone(),refrac.clone(),refrac.clone() ,refrac.clone() ,refrac.clone() ,refrac.clone() ,refrac.clone()
	,refrac.clone() ,refrac.clone() ,refrac.clone() ,refrac.clone() ,refrac.clone() ,refrac.clone(), absorb.clone() };

	OpticalSystem_LLT optSye_LLT_E1(surface_ptr_E1, interaction_ptr_E1);

	// *** test optical system *** //
	// single ray trace
	Ray_LLT ray_E1(/*origin*/{ 0.0,0.0,0.0 },/*direction*/{ 0.0,1.0,20.0 },/*refractive index*/ 1.0);
	LightRayStruct lightRayE0(LightE1, ray_E1, 1);
	SequentialRayTracing seqTraceE1_single(optSye_LLT_E1);
	seqTraceE1_single.sequentialRayTracing(lightRayE0);
	VectorStructR3 interPointZemax{ 0.0,-0.025229984226,105.91112797 };
	VectorStructR3 interPointTOM = seqTraceE1_single.getAllInterPointsAtSurf_i(13)[0];
	bool checkSingRayTrace_E1 = Math::compareTwoVectorStructR3_decimals(interPointZemax, interPointTOM, 3);
	workLensReplace_E1.push_back(checkSingRayTrace_E1);

	// test rms
	SequentialRayTracing seqTraceE1(optSye_LLT_E1);
	FillApertureStop fillAperE0(/*start point rays*/{ 0.0,0.0,0.0 }, /*semi height of aperture stop*/ 1.0,/*point of aperture stop*/{ 0.0,0.0,20.0 },/*direction of aperture stop*/{ 0.0,0.0,1.0 }, /*rings*/ 6,/*arms*/ 8,/*refractive index*/ 1.0,/*light*/ LightE1);
	seqTraceE1.seqRayTracingWithVectorOfLightRays(fillAperE0.getVectorWithLightRays());
	Spot spotE1(seqTraceE1.getAllInterPointsAtSurf_i(13),/*reference point*/ seqTraceE1.getAllInterPointsAtSurf_i(13)[0]);
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

	typedef std::shared_ptr< Element_CR > surfacePtr;
	typedef std::shared_ptr< InteractionRay_LLT > interactionPtr;

	DoNothingInteraction_LLT doNot;
	RefractedRay_LLT refrac;
	Absorb_LLT absorb;

	Light_LLT LightE2;
	LightE2.setWavelength(550.0);

	glass glasses;
	glasses.loadGlassCatalog_Schott();

	std::vector<bool> workLensReplace_E2;

	ApertureStopElement A0_E2(/* semi height*/2.0, /*point*/{ 0.0,0.0,20.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAirZemax());
	SphericalElement S1_E2(/*radius*/ 25.0, /*semi height*/ 8.0, /*point*/{ 0.0,0.0,25.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAirZemax(), /*refractive index B*/glasses.getSF5_S1());
	SphericalElement S2_E2(/*radius*/ 30.0, /*semi height*/ 8.0, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getBK7_S1(), /*refractive index B*/glasses.getSF5_S1());
	SphericalElement S3_E2(/*radius*/ 20.0, /*semi height*/ 8.0, /*point*/{ 0.0,0.0,32.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAirZemax(), /*refractive index B*/glasses.getBK7_S1());
	PlanElement P4_E2(/*semi height*/ 99.0, /*point*/{ 0.0,0.0,82.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAirZemax(), /*refractive index B*/ glasses.getAirZemax());

	surfacePtr A0_E2_ptr = A0_E2.clone();
	surfacePtr S1_E2_ptr = S1_E2.clone();
	surfacePtr S2_E2_ptr = S2_E2.clone();
	surfacePtr S3_E2_ptr = S3_E2.clone();
	surfacePtr P4_E2_ptr = P4_E2.clone();

	std::vector<surfacePtr> opticalSystemE0_ptr{ A0_E2_ptr, S1_E2_ptr, S2_E2_ptr, S3_E2_ptr, P4_E2_ptr };
	std::vector<interactionPtr> interactionsE0_ptr{ doNot.clone(),refrac.clone(), refrac.clone(), refrac.clone(), absorb.clone() };


	//	build optical system
	OpticalSystemElement optSystemElement_E2(opticalSystemE0_ptr, interactionsE0_ptr);
	optSystemElement_E2.setRefractiveIndexAccordingToWavelength(550.0);

	// *** test optical system *** //
	SequentialRayTracing seqTraceE2(optSystemElement_E2);
	FillApertureStop fillAperE2(/*start point rays*/{ 0.0,0.0,0.0 }, /*semi height of aperture stop*/ 2.0,/*point of aperture stop*/{ 0.0,0.0,20.0 },/*direction of aperture stop*/{ 0.0,0.0,1.0 }, /*rings*/ 6,/*arms*/ 8,/*refractive index*/ 1.0,/*light*/ LightE2);
	seqTraceE2.seqRayTracingWithVectorOfLightRays(fillAperE2.getVectorWithLightRays());
	Spot spotE2(seqTraceE2.getAllInterPointsAtSurf_i(4),/*reference point*/ seqTraceE2.getAllInterPointsAtSurf_i(4)[0]);
	real rmsZemax_E2 = 45.274;
	real rmsTOM_E2 = spotE2.getRMS_µm();
	bool checkerSystem_E2 = Math::compareTwoNumbers_decimals(rmsTOM_E2, rmsZemax_E2, 0);
	workLensReplace_E2.push_back(checkerSystem_E2);
	// *** *** //

	// *** check rotate opt sys ele *** //
	std::vector<surfacePtr> opticalSystemE0_ptr_toRotate{S1_E2_ptr, S2_E2_ptr, S3_E2_ptr};
	std::vector<interactionPtr> interactionsE0_ptr_toRotate{refrac.clone(), refrac.clone(), refrac.clone()};
	OpticalSystemElement optSystemElement_E2_toRotate(opticalSystemE0_ptr_toRotate, interactionsE0_ptr_toRotate);

	OpticalSystemElement optSystemElement_E2_rotate = optSystemElement_E2.reverseOptSysEle(optSystemElement_E2_toRotate);
	OpticalSystem_LLT optSysE2_rotat_LLT = optSystemElement_E2_rotate.getLLTconversion_doConversion();
	optSysE2_rotat_LLT.printAllPositions();
	optSysE2_rotat_LLT.printAllRadii();

	optSystemElement_E2_rotate.fillInElementAndInteractionAtPos_i(0, A0_E2.clone(), doNot.clone());
	optSystemElement_E2_rotate.fillInElementAndInteractionAtPos_i(99, P4_E2.clone(), absorb.clone());
	SequentialRayTracing seqTraceE2_rotate(optSystemElement_E2_rotate);
	FillApertureStop fillAperE2_rotate(/*start point rays*/{ 0.0,0.0,0.0 }, /*semi height of aperture stop*/ 2.0,/*point of aperture stop*/{ 0.0,0.0,20.0 },/*direction of aperture stop*/{ 0.0,0.0,1.0 }, /*rings*/ 6,/*arms*/ 8,/*refractive index*/ 1.0,/*light*/ LightE2);
	seqTraceE2_rotate.seqRayTracingWithVectorOfLightRays(fillAperE2_rotate.getVectorWithLightRays());
	Spot spotE2_rotate(seqTraceE2_rotate.getAllInterPointsAtSurf_i(4),/*reference point*/ seqTraceE2_rotate.getAllInterPointsAtSurf_i(4)[0]);
	real rmsZemax_E2_rotate = 48.048;
	real rmsTOM_E2_rotate = spotE2_rotate.getRMS_µm();
	bool checkerSystem_E2_rotate = Math::compareTwoNumbers_decimals(rmsTOM_E2_rotate, rmsZemax_E2_rotate, 0);
	workLensReplace_E2.push_back(checkerSystem_E2_rotate);
	// *** *** //

	bool returnChecker_E2 = Math::checkTrueOfVectorElements(workLensReplace_E2);
	return returnChecker_E2;
}
