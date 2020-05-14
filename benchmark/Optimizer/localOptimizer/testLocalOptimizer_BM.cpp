#include "testLocalOptimizer_BM.h"

#include "..\..\..\OptimizeSystem\OptimizeOpticalSystem.h"
#include "..\..\..\OpticalSystemElement\OpticalSystemElement.h"

// include surfaces
#include "..\..\..\SurfaceElements\SphericalElement.h"
#include "..\..\..\SurfaceElements\PlanElement.h"
#include "..\..\..\SurfaceElements\ApertureStopElement.h"

// include interactions
#include "..\..\..\LowLevelTracing\Interaction\RefractedRay_LLT.h"
#include "..\..\..\LowLevelTracing\Interaction\DoNothingInteraction_LLT.h"
#include "..\..\..\LowLevelTracing\Interaction\Absorb_LLT.h"

// include the glas cataloge
#include "..\..\..\Glasses\Glasses.h"

// include to export data
#include "..\..\..\Inport_Export_Data\Inport_Export_Data.h"

testLocalOpti_BM::testLocalOpti_BM() {}
testLocalOpti_BM::~testLocalOpti_BM() {}




bool testLocalOpti_BM::checkLocalOpti_BM()
{
	std::cout << "start test BM methode" << std::endl;

	std::vector<bool> workLocalOpti_BM;
	
	typedef std::shared_ptr< Element_CR > surfacePtr;
	typedef std::shared_ptr< InteractionRay_LLT > interactionPtr;

	// interactions 
	RefractedRay_LLT refrac;
	Absorb_LLT absorb;
	DoNothingInteraction_LLT doNothing;

	glass glasses;
	glasses.loadGlassCatalog_Schott();

	Light_LLT Light0_E0;
	Light0_E0.setWavelength(587.5618);
	Light0_E0.setIntensity(1.0);

	Light_LLT Light1_E0;
	Light1_E0.setWavelength(486.1327);
	Light1_E0.setIntensity(1.0);

	Light_LLT Light2_E0;
	Light2_E0.setWavelength(656.2725);
	Light2_E0.setIntensity(1.0);


	std::vector<Light_LLT> lichtVecE0{ Light0_E0, Light1_E0, Light2_E0 };

	// surfaces E0
	ApertureStopElement AperSto0_E0(/* semi height*/3.0, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAir());
	SphericalElement Sphere1_E0(/*radius*/ 20.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,35.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNBK7_S1());
	SphericalElement Sphere2_E0(/*radius*/ 50.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,45.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getNBK7_S1(), /*refractive index B*/glasses.getSF5_S1());
	SphericalElement Sphere3_E0(/*radius*/ 25.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,55.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getSF5_S1());
	PlanElement Plan4_E0(/*semi height*/ 99.0, /*point*/{ 0.0,0.0,85.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAir(), /*refractive index B*/ glasses.getAir());

	Sphere1_E0.setParameterRadius(10.0, 40.0, 0.0, typeModifierVariable);
	Sphere2_E0.setParameterRadius(10.0, 60.0, 0.0, typeModifierVariable);
	Sphere3_E0.setParameterRadius(10.0, 60.0, 0.0, typeModifierVariable);

	surfacePtr AperSto0_E0_ptr = AperSto0_E0.clone();
	surfacePtr Sphere1_E0_ptr = Sphere1_E0.clone();
	surfacePtr Sphere2_E0_ptr = Sphere2_E0.clone();
	surfacePtr Sphere3_E0_ptr = Sphere3_E0.clone();
	surfacePtr Plan4_E0_ptr = Plan4_E0.clone();

	std::vector<surfacePtr> opticalSystem_E0_ptr{ AperSto0_E0_ptr, Sphere1_E0_ptr, Sphere2_E0_ptr, Sphere3_E0_ptr, Plan4_E0_ptr };
	std::vector<interactionPtr> interactions_E0_ptr{ doNothing.clone(),refrac.clone(), refrac.clone(), refrac.clone(), refrac.clone(), absorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement_E0(opticalSystem_E0_ptr, interactions_E0_ptr);

	// trace the ray thow the optical system
	SequentialRayTracing seqTrace_E0_optA(/*optical system element*/ optSystemElement_E0, /*start point lightRay*/{ 0.0,0.0,0.0 }, /*rings*/ 6, /*arms*/ 8, /*refractive index*/ 1.0, lichtVecE0);
	SequentialRayTracing seqTrace_E0_field2(/*optical system element*/ optSystemElement_E0, /*start point lightRay*/{ 0.0,2.0,0.0 }, /*rings*/ 6, /*arms*/ 8, /*refractive index*/ 1.0, lichtVecE0);
	SequentialRayTracing seqTrace_E0_field4(/*optical system element*/ optSystemElement_E0, /*start point lightRay*/{ 0.0,4.0,0.0 }, /*rings*/ 6, /*arms*/ 8, /*refractive index*/ 1.0, lichtVecE0);

	// calculate rms value
	Spot spot_E0_optA(seqTrace_E0_optA.getAllInterPointsAtSurf_i_notFiltered(4), seqTrace_E0_optA.getAllInterPointsAtSurf_i_notFiltered(4).at(0));
	real rms_E0_optA = spot_E0_optA.getRMS_µm();
	bool checkRMSoptA_E0 = Math::compareTwoNumbers_decimals(rms_E0_optA, 354.553, 2);
	workLocalOpti_BM.push_back(checkRMSoptA_E0);
	Spot spot_E0_field2(seqTrace_E0_field2.getAllInterPointsAtSurf_i_notFiltered(4), seqTrace_E0_field2.getAllInterPointsAtSurf_i_notFiltered(4).at(0));
	real rms_E0_field2 = spot_E0_field2.getRMS_µm();
	bool checkRMSfield2_E0 = Math::compareTwoNumbers_decimals(rms_E0_field2, 339.605, 3);
	workLocalOpti_BM.push_back(checkRMSfield2_E0);
	Spot spot_E0_field4(seqTrace_E0_field4.getAllInterPointsAtSurf_i_notFiltered(4), seqTrace_E0_field4.getAllInterPointsAtSurf_i_notFiltered(4).at(0));
	real rms_E0_field4 = spot_E0_field4.getRMS_µm();
	bool checkRMSfield4_E0 = Math::compareTwoNumbers_decimals(rms_E0_field4, 302.609, 2);
	workLocalOpti_BM.push_back(checkRMSfield4_E0);


	localStart localOp_P0 = radiusStart;

	OptimizeOpticalSystem optimizedOptSys_P0(optSystemElement_E0, radiusStart);
	optimizedOptSys_P0.setCheckAllLocalCombinations_optimizer(true);
	optimizedOptSys_P0.add_FieldAndWeight({ 0.0,2.0,0.0 }, 1.0);
	optimizedOptSys_P0.add_FieldAndWeight({ 0.0,4.0,0.0 }, 1.0);
	optimizedOptSys_P0.set_Light(Light0_E0);
	optimizedOptSys_P0.add_Light(Light1_E0);
	optimizedOptSys_P0.add_Light(Light2_E0);

	optimizedOptSys_P0.localOptimizatio_BM();
	real durationTimeLocal_BM = optimizedOptSys_P0.getDurationTimeLocalOptiInMin();
	std::cout << "duration time local BM: " << durationTimeLocal_BM << std::endl;

	OpticalSystemElement optimizedOpticalSys = optimizedOptSys_P0.getOptSysOptimized_Ele();
	real optiRadius1 = optimizedOpticalSys.getPosAndElement().at(1).getElementInOptSys_ptr()->getRadiusElementValue();
	std::cout << "radius 1: " << optiRadius1 << std::endl;
	real optiRadius2 = optimizedOpticalSys.getPosAndElement().at(2).getElementInOptSys_ptr()->getRadiusElementValue();
	std::cout << "radius 2: " << optiRadius2 << std::endl;
	real optiRadius3 = optimizedOpticalSys.getPosAndElement().at(3).getElementInOptSys_ptr()->getRadiusElementValue();
	std::cout << "radius 3: " << optiRadius3 << std::endl;

	// trace the ray thow the optical system
	SequentialRayTracing seqTrace_E0_optA_opti(/*optical system element*/ optimizedOpticalSys, /*start point lightRay*/{ 0.0,0.0,0.0 }, /*rings*/ 6, /*arms*/ 8, /*refractive index*/ 1.0, lichtVecE0);
	SequentialRayTracing seqTrace_E0_field2_opti(/*optical system element*/ optimizedOpticalSys, /*start point lightRay*/{ 0.0,2.0,0.0 }, /*rings*/ 6, /*arms*/ 8, /*refractive index*/ 1.0, lichtVecE0);
	SequentialRayTracing seqTrace_E0_field4_opti(/*optical system element*/ optimizedOpticalSys, /*start point lightRay*/{ 0.0,4.0,0.0 }, /*rings*/ 6, /*arms*/ 8, /*refractive index*/ 1.0, lichtVecE0);
	
	// calculate rms value from the optimized optical system
	// optA
	Spot spot_E0_optA_opti(seqTrace_E0_optA_opti.getAllInterPointsAtSurf_i_notFiltered(4), seqTrace_E0_optA_opti.getAllInterPointsAtSurf_i_notFiltered(4).at(0));
	real rms_E0_optA_opti = spot_E0_optA_opti.getRMS_µm();
	// field2
	Spot spot_E0_field2_opti(seqTrace_E0_field2_opti.getAllInterPointsAtSurf_i_notFiltered(4), seqTrace_E0_field2_opti.getAllInterPointsAtSurf_i_notFiltered(4).at(0));
	real rms_E0_field2_opti = spot_E0_field2_opti.getRMS_µm();
	// field4
	Spot spot_E0_field4_opti(seqTrace_E0_field4_opti.getAllInterPointsAtSurf_i_notFiltered(4), seqTrace_E0_field4_opti.getAllInterPointsAtSurf_i_notFiltered(4).at(0));
	real rms_E0_field4_opti = spot_E0_field4_opti.getRMS_µm();
	
	real zemaxRMSsumOpti = 77.957 + 108.083 + 190.609;
	std::cout << "zemax sum rms: " << zemaxRMSsumOpti << std::endl;
	real glowRMSsumOpti = rms_E0_optA_opti + rms_E0_field2_opti + rms_E0_field4_opti;
	std::cout << "glow sum rms: " << glowRMSsumOpti << std::endl;
	   	
	

	bool returnCheckLocalOpti_BM = Math::checkTrueOfVectorElements(workLocalOpti_BM);

	return returnCheckLocalOpti_BM;
}