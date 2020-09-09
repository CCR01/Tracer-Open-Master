#include "IOC2020_Dresden.h"

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


IOC2020_Dresden::IOC2020_Dresden(){}

IOC2020_Dresden::~IOC2020_Dresden(){}


bool IOC2020_Dresden::systemFor_IOC2020_Dresten()
{
	// interactions
	DoNothingInteraction_LLT doNot;
	RefractedRay_LLT refrac;
	Absorb_LLT absorb;

	// light
	Light_LLT LightIOC_587;
	LightIOC_587.setWavelength(587.5618);

	Light_LLT LightIOC_486;
	LightIOC_486.setWavelength(486.1327);

	Light_LLT LightIOC_656;
	LightIOC_656.setWavelength(656.2725);

	std::vector<Light_LLT> light_IOC_vec{ LightIOC_587, LightIOC_486, LightIOC_656 };

	// glasses
	glass glasses;
	glasses.loadGlassCatalog_Schott();

	std::vector<bool> workTheSystem_IOC2020;

	//ApertureStopElement A0_IOC(/* semi height*/1.0, /*point*/{ 0.0,0.0,10.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAir());
	//SphericalElement S1_IOC(/*radius*/ 30.0, /*semi height*/ 6.0, /*point*/{ 0.0,0.0,15.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getSF5_S1());
	//SphericalElement S2_IOC(/*radius*/ 35.0, /*semi height*/ 6.0, /*point*/{ 0.0,0.0,20.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getBK7_S1(), /*refractive index B*/glasses.getSF5_S1());
	//SphericalElement S3_IOC(/*radius*/ 35.0, /*semi height*/ 6.0, /*point*/{ 0.0,0.0,23.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getBK7_S1());
	//SphericalElement S4_IOC(/*radius*/ 10.0, /*semi height*/ 6.0, /*point*/{ 0.0,0.0,33.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNBAF10_S1());
	//SphericalElement S5_IOC(/*radius*/ 20.0, /*semi height*/ 6.0, /*point*/{ 0.0,0.0,38.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getSF10_S1(), /*refractive index B*/glasses.getNBAF10_S1());
	//SphericalElement S6_IOC(/*radius*/ 25.0, /*semi height*/ 6.0, /*point*/{ 0.0,0.0,40.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getSF10_S1());
	//PlanElement P7_IOC(/*semi height*/ 5.0, /*point*/{ 0.0,0.0,50.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAir(), /*refractive index B*/ glasses.getAir());
	//
	//
	//std::vector<std::shared_ptr<Element_CR>> surface_ptr_IOC{ A0_IOC.clone(),S1_IOC.clone(),S2_IOC.clone(),S3_IOC.clone(),S4_IOC.clone(), S5_IOC.clone(),S6_IOC.clone(), P7_IOC.clone()};
	//
	//std::vector<std::shared_ptr<InteractionRay_LLT>> interaction_ptr_IOC{ doNot.clone(),refrac.clone(),refrac.clone() ,refrac.clone() ,refrac.clone() ,refrac.clone() ,refrac.clone(), absorb.clone() };
	//
	//OpticalSystemElement optSysEle_IOC(surface_ptr_IOC, interaction_ptr_IOC);
	//optSysEle_IOC.setRefractiveIndexAccordingToWavelength(LightIOC_587.getWavelength());
	//
	//// *** test optical system *** //
	//// single ray trace
	//Ray_LLT ray_IOC(/*origin*/{ 0.0,0.0,0.0 },/*direction*/{ 0.0,1.0,10.0 },/*refractive index*/ 1.0);
	//LightRayStruct lightRayE0(LightIOC_587, ray_IOC, 1);
	//SequentialRayTracing seqTraceIOC_single(optSysEle_IOC);
	//seqTraceIOC_single.sequentialRayTracing(lightRayE0);
	//VectorStructR3 interPointZemax{ 0.0,0.066840087303,50.0 };
	//VectorStructR3 interPointTOM = seqTraceIOC_single.getAllInterPointsAtSurf_i(7)[0];
	//bool checkSingRayTrace_IOC = Math::compareTwoVectorStructR3(interPointZemax, interPointTOM, 3);
	//workTheSystem_IOC2020.push_back(checkSingRayTrace_IOC);
	//
	//// test rms
	//SequentialRayTracing seqTraceIOC(/*optical system element*/ optSysEle_IOC, /*start point lightRay*/{ 0.0,0.0,0.0 }, /*rings*/ 6, /*arms*/ 8, /*refractive index*/ 1.0, light_IOC_vec);
	//Spot spotIOC(seqTraceIOC.getAllInterPointsAtSurf_i(7),/*reference point*/ seqTraceIOC.getAllInterPointsAtSurf_i(7)[0]);
	//real rmsZemax_IOC = 61.229;
	//real rmsTOM_IOC = spotIOC.getRMS_µm();
	//bool checkerSystem_IOC = Math::compareTwoNumbers(rmsTOM_IOC, rmsZemax_IOC, 0);
	//workTheSystem_IOC2020.push_back(checkerSystem_IOC);
	//// *** *** //
	//
	//optSysEle_IOC.setRefractiveIndexAccordingToWavelength(LightIOC_587.getWavelength());
	////OpticalSystem_LLT optSys_IOC_LLT = optSysEle_IOC.getLLTconversion_doConversion();
	//
	//
	//LensReplace lensReplace_IOC220(optSysEle_IOC);
	//
	//// *** *** //
	//// check focal lenght
	//real focalLengthFirstLensTOM = lensReplace_IOC220.getParameterLenses()[0].getFocalLengthMinMax().getValue();
	//real focalLengthFirstLensZemax = 25.2661;
	//bool checkfocalLengthFirstLens = Math::compareTwoNumbers(focalLengthFirstLensTOM, focalLengthFirstLensZemax, 3);
	//workTheSystem_IOC2020.push_back(checkfocalLengthFirstLens);
	//real focalLengthSecondLensTOM = lensReplace_IOC220.getParameterLenses()[1].getFocalLengthMinMax().getValue();
	//real focalLengthSecondLensZemax = 11.6574;
	//bool checkfocalLengthSecondLens = Math::compareTwoNumbers(focalLengthSecondLensTOM, focalLengthSecondLensZemax, 3);
	//// *** *** //
	//
	//int numberLens = 0;
	std::vector<lensTypes> loadLensCatalogEO_vec{ lensTypes::posAchromat };
	//OpticalSystemElement bestFitLens0 = lensReplace_IOC220.checkLensCatalogsForBestFitLens(/*number lens*/ numberLens,/*parameter lens*/ lensReplace_IOC220.getParameterLenses()[numberLens], /*load lens catalog*/ loadLensCatalogEO_vec);
	//
	//OpticalSystemElement bestFitLens0_rot = bestFitLens0.reverseOptSysEle(bestFitLens0);
	//
	//lensReplace_IOC220.replaceLens(0, bestFitLens0_rot);
	//
	//OpticalSystemElement optSysEle_replace0 = lensReplace_IOC220.getOpticalSysEle();
	//optSysEle_replace0.getPosAndElement()[4].getElementInOptSys_ptr()->setPointElementValue_Z(31.25);
	//optSysEle_replace0.getPosAndElement()[5].getElementInOptSys_ptr()->setPointElementValue_Z(36.25);
	//optSysEle_replace0.getPosAndElement()[6].getElementInOptSys_ptr()->setPointElementValue_Z(38.25);
	//optSysEle_replace0.getPosAndElement()[7].getElementInOptSys_ptr()->setPointElementValue_Z(48.25);
	//
	//OpticalSystem_LLT optSys_LLT_replace0 = optSysEle_replace0.getLLTconversion_doConversion();
	//optSysEle_replace0.setRefractiveIndexAccordingToWavelength(LightIOC_587.getWavelength());
	//optSys_LLT_replace0.printAllOptSysParameter_LLT(optSys_LLT_replace0);

	//// ***  test replca lens 0 *** ///
	//SequentialRayTracing seqTraceReplace0(/*optical system element*/ optSysEle_replace0, /*start point lightRay*/{ 0.0,0.0,0.0 }, /*rings*/ 6, /*arms*/ 8, /*refractive index*/ 1.0, light_IOC_vec);
	//Spot spotIOC_replace0(seqTraceReplace0.getAllInterPointsAtSurf_i(7),/*reference point*/ seqTraceReplace0.getAllInterPointsAtSurf_i(7)[0]);
	//real rmsZemax_IOC_replace0 = 19.334;
	//real rmsTOM_IOC_replace0 = spotIOC_replace0.getRMS_µm();
	//bool checkerSystem_IOC_replace0 = Math::compareTwoNumbers(rmsTOM_IOC_replace0, rmsZemax_IOC_replace0, 2);
	//workTheSystem_IOC2020.push_back(checkerSystem_IOC_replace0);

	// glas wird noch nicht mit genommen -> fix that!!!


	// check replace
	ApertureStopElement A0_IOC_replace0(/* semi height*/1.0, /*point*/{ 0.0,0.0,10.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAir());
	SphericalElement S1_IOC_replace0(/*radius*/ 107.03, /*semi height*/ 6.25, /*point*/{ 0.0,0.0,15.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNSF10_S1());
	SphericalElement S2_IOC_replace0(/*radius*/ 10.99, /*semi height*/ 6.25, /*point*/{ 0.0,0.0,16.25 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getNSF10_S1(), /*refractive index B*/glasses.getNBAF10_S1());
	SphericalElement S3_IOC_replace0(/*radius*/ 17.27, /*semi height*/ 6.25, /*point*/{ 0.0,0.0,21.25 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNBAF10_S1());
	SphericalElement S4_IOC_replace0(/*radius*/ 12.91990912, /*semi height*/ 6.0, /*point*/{ 0.0,0.0,31.25 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNBAF10_S1());
	SphericalElement S5_IOC_replace0(/*radius*/ 20.0, /*semi height*/ 6.0, /*point*/{ 0.0,0.0,36.25 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getSF10_S1(), /*refractive index B*/glasses.getNBAF10_S1());
	SphericalElement S6_IOC_replace0(/*radius*/ 25.0, /*semi height*/ 6.0, /*point*/{ 0.0,0.0,38.25 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getSF10_S1());
	PlanElement P7_IOC_replace0(/*semi height*/ 5.0, /*point*/{ 0.0,0.0,51.60988 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAir(), /*refractive index B*/ glasses.getAir());

	std::vector<std::shared_ptr<Element_CR>> surface_ptr_IOC_replace0{ A0_IOC_replace0.clone(),S1_IOC_replace0.clone(),S2_IOC_replace0.clone(),S3_IOC_replace0.clone(),S4_IOC_replace0.clone(), S5_IOC_replace0.clone(),S6_IOC_replace0.clone(), P7_IOC_replace0.clone() };
	std::vector<std::shared_ptr<InteractionRay_LLT>> interaction_ptr_IOC_replace0{ doNot.clone(),refrac.clone(),refrac.clone() ,refrac.clone() ,refrac.clone() ,refrac.clone() ,refrac.clone(), absorb.clone() };

	OpticalSystemElement optSysEle_IOC_replace0(surface_ptr_IOC_replace0, interaction_ptr_IOC_replace0);
	optSysEle_IOC_replace0.setRefractiveIndexAccordingToWavelength(LightIOC_587.getWavelength());

	//// ***  test replca lens 1 *** ///
	// single ray trace
	Ray_LLT ray_IOC_replace0(/*origin*/{ 0.0,0.0,0.0 },/*direction*/{ 0.0,1.0,10.0 },/*refractive index*/ 1.0);
	LightRayStruct lightRayE0_replace0(LightIOC_587, ray_IOC_replace0, 1);
	SequentialRayTracing seqTraceIOC_single_replace0(optSysEle_IOC_replace0);
	seqTraceIOC_single_replace0.sequentialRayTracing(lightRayE0_replace0);
	VectorStructR3 interPointZemax_replace0{ 0.0,-0.0091558,51.60988 };
	VectorStructR3 interPointTOM_replace0 = seqTraceIOC_single_replace0.getAllInterPointsAtSurf_i_notFiltered(7)[0];
	bool checkSingRayTrace_IOC_replace0 = Math::compareTwoVectorStructR3_decimals(interPointZemax_replace0, interPointTOM_replace0, 3);
	workTheSystem_IOC2020.push_back(checkSingRayTrace_IOC_replace0);

	SequentialRayTracing seqTraceReplace_replace0(/*optical system element*/ optSysEle_IOC_replace0, /*start point lightRay*/{ 0.0,0.0,0.0 }, /*rings*/ 6, /*arms*/ 8, /*refractive index*/ 1.0, light_IOC_vec);
	Spot spotIOC_replace0(seqTraceReplace_replace0.getAllInterPointsAtSurf_i_notFiltered(7),/*reference point*/ seqTraceReplace_replace0.getAllInterPointsAtSurf_i_notFiltered(7)[0]);
	real rmsZemax_IOC_replace0 = 18.510;
	real rmsTOM_IOC_replace0 = spotIOC_replace0.getRMS_µm();
	bool checkerSystem_IOC_replace0 = Math::compareTwoNumbers_decimals(rmsTOM_IOC_replace0, rmsZemax_IOC_replace0, 2);
	workTheSystem_IOC2020.push_back(checkerSystem_IOC_replace0);
	// *** *** //


	//int numberLens1 = 1;
	//LensReplace lensReplace_IOC220_replace0(optSysEle_IOC_replace0);
	//////std::vector<lensTypes> loadLensCatalogEO_vec{ posAchromat };
	//OptSysEle_Merit_LensType bestFitLens1 = lensReplace_IOC220_replace0.checkLensCatalogsForBestFitLens(/*number lens*/ numberLens1,/*parameter lens*/ lensReplace_IOC220_replace0.getParameterLenses()[numberLens1], /*load lens catalog*/ loadLensCatalogEO_vec);


	bool check_IOC2020 = Math::checkTrueOfVectorElements(workTheSystem_IOC2020);
	return check_IOC2020;
}