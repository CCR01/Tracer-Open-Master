#include "BenchOpticalSystemElement.h"
#include "..\..\..\SurfaceElements\SphericalElement.h"
#include "..\..\..\FillAptertureStop\FillApertureStop.h"
#include "..\..\..\Analyse\Spot.h"
#include "..\..\..\SurfaceElements\PlanElement.h"
#include "..\..\..\SurfaceElements\ApertureStopElement.h"
#include "..\..\..\LowLevelTracing\Interaction\Absorb_LLT.h"
#include "..\..\..\LowLevelTracing\Interaction\DoNothingInteraction_LLT.h"
#include "..\..\..\LowLevelTracing\Light_LLT.h"
#include "..\..\..\OptimizeSystem\OptimizeOpticalSystem.h"
#include "..\..\..\Glasses\GlassDispersionFormulas\MaterialSellmeier1.h"
#include "..\..\..\Glasses\Glasses.h"
#include "..\..\..\LowLevelTracing\Math_LLT.h"

bool BenchOpticalSystemElement::checkMethodesOpticalSystemElement()
{
	std::vector<bool> workOptSysEle;

	RefractedRay_LLT refrac;
	DoNothingInteraction_LLT doNothing;
	Absorb_LLT absorb;
	typedef std::shared_ptr< Element_CR > surfacePtr;
	typedef std::shared_ptr< InteractionRay_LLT > interactionPtr;
	glass glasses;
	glasses.loadGlassCatalog_Schott();

	Light_LLT LightE0_0;
	LightE0_0.setWavelength(486.1327);
	LightE0_0.setIntensity(2.0);
	Light_LLT LightE0_1;
	LightE0_1.setWavelength(587.5618);
	LightE0_1.setIntensity(1.0);
	Light_LLT LightE0_2;
	LightE0_2.setWavelength(656.2725);
	LightE0_2.setIntensity(1.0);

	std::vector<Light_LLT> light_vec{ LightE0_0 , LightE0_1, LightE0_2 };


	ApertureStopElement AperStop0_E0(/* semi height*/1.0, /*point*/{ 0.0,0.0,10.0 }, /*direction*/{ 0.0,0.0,1.0 }, glasses.getAir());
	surfacePtr apertureStop0_E0_ptr = AperStop0_E0.clone();

	SphericalElement Sphere1_E0(/*radius*/ 10.0, /*semi height*/ 3.0, /*point*/{ 0.0,0.0,15.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNBK7_S1());
	surfacePtr sphere1_E0_ptr = Sphere1_E0.clone();
		
	SphericalElement Sphere2_E0(/*radius*/ 10.0, /*semi height*/ 3.0, /*point*/{ 0.0,0.0,20.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getNBK7_S1(), /*refractive index B*/glasses.getSF5_S1());
	surfacePtr sphere2_E0_ptr = Sphere2_E0.clone();

	SphericalElement Sphere3_E0(/*radius*/ 10.0, /*semi height*/ 3.0, /*point*/{ 0.0,0.0,25.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getSF5_S1());
	surfacePtr sphere3_E0_ptr = Sphere3_E0.clone();

	PlanElement Plan4_E0(/*semi height*/ 3.0, /*point*/{ 0.0,0.0,40.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAir(), /*refractive index B*/ glasses.getAir());
	surfacePtr plna4_E0_ptr = Plan4_E0.clone();

	std::vector<surfacePtr> opticalSystemE0_ptr{ apertureStop0_E0_ptr, sphere1_E0_ptr, sphere2_E0_ptr, sphere3_E0_ptr, plna4_E0_ptr};
	std::vector<interactionPtr> interactionsE0_ptr{ doNothing.clone(),refrac.clone(), refrac.clone(), refrac.clone(), absorb.clone() };


	//	build optical system
	OpticalSystemElement opticalsystem00(opticalSystemE0_ptr, interactionsE0_ptr);
	// trace the ray thow the optical system
	SequentialRayTracing seqTrace_E0_optA(/*optical system element*/ opticalsystem00, /*start point lightRay*/{ 0.0,0.0,0.0 }, /*rings*/ 6, /*arms*/ 8, /*refractive index*/ 1.0, light_vec);
	SequentialRayTracing seqTrace_E0_field1(/*optical system element*/ opticalsystem00, /*start point lightRay*/{ 0.0,1.0,0.0 }, /*rings*/ 6, /*arms*/ 8, /*refractive index*/ 1.0, light_vec);


	Spot SpotE0_optA(seqTrace_E0_optA.getAllInterPointsAndIntensityAtSurface_i(4), seqTrace_E0_optA.getAllInterPointsAtSurf_i_notFiltered(4).at(0));
	real rmsOptAchseE0 = SpotE0_optA.getRMS_µm();
	bool checkRMS_OptA_E0 = Math::compareTwoNumbers_decimals(rmsOptAchseE0, 123.579, 2);
	workOptSysEle.push_back(checkRMS_OptA_E0);

	Spot SpotE0_field1(seqTrace_E0_field1.getAllInterPointsAndIntensityAtSurface_i(4), seqTrace_E0_field1.getAllInterPointsAtSurf_i_notFiltered(4).at(0));
	real rmsField1E0 = SpotE0_field1.getRMS_µm();
	bool checkRMS_feidl1_E0 = Math::compareTwoNumbers_decimals(rmsField1E0, 178.189, 2);
	workOptSysEle.push_back(checkRMS_feidl1_E0);



	bool checkOptSysEle = Math::checkTrueOfVectorElements(workOptSysEle);
	return checkOptSysEle;
}

