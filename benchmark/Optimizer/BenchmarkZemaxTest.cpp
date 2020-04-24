#include "BenchmarkZemaxTest.h"



#include "..\..\OpticalSystemElement\OpticalSystemElement.h"
#include "..\..\SurfaceElements\SphericalElement.h"
#include "..\..\SurfaceElements\AsphericalElement.h" 
#include "..\..\LowLevelTracing\Interaction\RefractedRay_LLT.h"
#include "..\..\SequentialRayTracing\SequentialRayTracer.h"
#include "..\..\FillAptertureStop\FillApertureStop.h"
#include "..\..\Analyse\Spot.h"
#include "..\..\SurfaceElements\PlanElement.h"
#include "..\..\LowLevelTracing\Interaction\Absorb_LLT.h"
#include "..\..\LowLevelTracing\Light_LLT.h"
#include "..\..\OptimizeSystem\OptimizeOpticalSystem.h"

////LLT Surfaces
#include "..\..\LowLevelTracing\Surfaces\ApertureStop_LLT.h"
#include "..\..\LowLevelTracing\Surfaces\SphericalSurface_LLT.h"
#include "..\..\LowLevelTracing\Surfaces\PlanGeometry_LLT.h"

//// interaction
#include "..\..\LowLevelTracing\Interaction\RefractedRay_LLT.h"
#include "..\..\LowLevelTracing\Interaction\DoNothingInteraction_LLT.h"
#include "..\..\LowLevelTracing\Interaction\Absorb_LLT.h"
#include "..\..\SurfaceElements\ApertureStopElement.h"
#include "..\..\Glasses\Glasses.h"

#include "..\..\Plot\PlotSpotDiagram.h"

bool BenchmarkZemaxTest::checkMethodesZemaxTest()
{
	glass glasses;
	glasses.loadGlassCatalog_Schott();
	
	MaterialSellmeier1 glass1;
	glass1.setRealGlass(false);
	glass1.setRefractiveIndex(1.0);
	
	MaterialSellmeier1 glass15;
	glass15.setRealGlass(false);
	glass15.setRefractiveIndex(1.5);
	
	MaterialSellmeier1 glass16;
	glass16.setRealGlass(false);
	glass16.setRefractiveIndex(1.6);
	
	Light_LLT Light0_E13;
	Light0_E13.setWavelength(587.5618);
	Light0_E13.setIntensity(1.0);

	Light_LLT Light1_E13;
	Light1_E13.setWavelength(486.1327);
	Light1_E13.setIntensity(1.0);

	Light_LLT Light2_E13;
	Light2_E13.setWavelength(656.2725);
	Light2_E13.setIntensity(1.0);


	std::vector<Light_LLT> lightVecE13{ Light0_E13, Light1_E13, Light2_E13 };
	
	typedef std::shared_ptr< Element_CR > surfacePtr;
	typedef std::shared_ptr<InteractionRay_LLT> interactionPtr;
	
	// work the optimizer
	std::vector<bool> workTheOptimizer;
	real toleranceDistance = 0.00001;
	


	// interactions 
	RefractedRay_LLT refrac;
	Absorb_LLT absorb;
	DoNothingInteraction_LLT doNothing;

	//SYSTEM E0////////////////////////////////////////////////////////////////////////////////////
	// set the wavelength
	Light_LLT Light_E0;
	Light_E0.setWavelength(550.0);
	Light_E0.setIntensity(1.0);
	std::vector<Light_LLT> lichtVecE0{ Light_E0 };
	
	// surfaces E0
	ApertureStopElement AperStop0_E0(/* semi height*/1.0, /*point*/{ 0.0,0.0,10.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glass1);
	SphericalElement Sphere1_E0(/*radius*/ 5.0, /*semi height*/ 3.0, /*point*/{ 0.0,0.0,15.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glass1, /*refractive index B*/glass15);
	SphericalElement Sphere2_E0(/*radius*/ 5.0, /*semi height*/ 3.0, /*point*/{ 0.0,0.0,20.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glass1, /*refractive index B*/glass15);
	PlanElement Plan3_E0(/*semi height*/ 3.0, /*point*/{ 0.0,0.0,30.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glass1, /*refractive index B*/ glass1);
	
	// set the radius variable
	Sphere1_E0.setParameterRadius(3.0, 7.0, 0.0, typeModifierVariable);
	Sphere2_E0.setParameterRadius(3.0, 7.0, 0, typeModifierVariable);
	
	surfacePtr AperStop0_E0_ptr = AperStop0_E0.clone();
	surfacePtr Sphere1_E0_ptr = Sphere1_E0.clone();
	surfacePtr Sphere2_E0_ptr = Sphere2_E0.clone();
	surfacePtr Plan3_E0_ptr = Plan3_E0.clone();
	
	std::vector<surfacePtr> opticalSystemE0_ptr{ AperStop0_E0_ptr, Sphere1_E0_ptr, Sphere2_E0_ptr, Plan3_E0_ptr };
	std::vector<interactionPtr> interactionsE0_ptr{ refrac.clone(),refrac.clone(), refrac.clone(), absorb.clone() };
	
	// build optical system
	OpticalSystemElement optSystemElement_E0(opticalSystemE0_ptr, interactionsE0_ptr);
	
	// trace the ray thow the optical system
	SequentialRayTracing seqTrace_E0_optA(/*optical system element*/ optSystemElement_E0, /*start point lightRay*/{ 0.0,0.0,0.0 }, /*rings*/ 6, /*arms*/ 8, /*refractive index*/ 1.0, lichtVecE0);
	
	// calculate rms value
	Spot spot_E0_optA(seqTrace_E0_optA.getAllInterPointsAtSurf_i_notFiltered(3), seqTrace_E0_optA.getAllInterPointsAtSurf_i_notFiltered(3).at(0));
	real rms_E0_optA = spot_E0_optA.getRMS_µm();
	std::cout << "Organic RMS optA E0: " << rms_E0_optA << "\n";
	workTheOptimizer.push_back( std::abs(rms_E0_optA - 558.824) < 0.1);
	
	// next we start the optimasation
	std::cout << "start of the optimizer example E0 \n";
	// population of the optimasation process
	unsigned int population_E0 = 500;
	
	// stadt the optim
	localStart localOp_E0 = radiusStart;
	/*mutation factor*/
	real mutarionFactor_E0 = 0.01;
	
	OptimizeOpticalSystem optimizedOptSys_E0(optSystemElement_E0, population_E0, mutarionFactor_E0, localOp_E0);
	
	// field on the optical axis
	// when we add no field, then the default field is at {0.0,0.0,0.0}
	// when we add no wavelenght, then the default wavelenght ist 550nm
	
	// set rings and arms for the optimasation
	optimizedOptSys_E0.setRings_optimizer(6);
	optimizedOptSys_E0.setArms_optimizer(8);
	optimizedOptSys_E0.add_IMAGEQuality_Weight(1.0);
	// *********************************
	// start optimasation of example E12
	optimizedOptSys_E0.optimizeSUPERFUNCTION();
	// *********************************
	// get the optimized optical system
	OpticalSystemElement optimizedOptSys_Ele_E0 = optimizedOptSys_E0.getOptSysOptimized_Ele();
	
	// trace the ray thow the optical system
	SequentialRayTracing seqTrace_E0_optA_AO(/*optical system element*/ optimizedOptSys_Ele_E0, /*start point lightRay*/{ 0.0,0.0,0.0 }, /*rings*/ 6, /*arms*/ 8, /*refractive index*/ 1.0, Light_E0);
	Spot SpotOptA_AO_E0(seqTrace_E0_optA_AO.getAllInterPointsAtSurf_i_notFiltered(3), seqTrace_E0_optA_AO.getAllInterPointsAtSurf_i_notFiltered(3).at(0));
	real sporRMS_OA_E0 = SpotOptA_AO_E0.getRMS_µm();
	real spotZemaxOA_EO = 32.418;
	std::cout << "RMS AO optA E0: " << sporRMS_OA_E0 << "\n";
	std::cout << "radius R1 E0: " << optimizedOptSys_E0.getOptSysOptimized_LLT().getPosAndInteractingSurface().at(1).getSurfaceInterRay_ptr()->getRadius() << std::endl;
	std::cout << "radius R2 E0: " << optimizedOptSys_E0.getOptSysOptimized_LLT().getPosAndInteractingSurface().at(2).getSurfaceInterRay_ptr()->getRadius() << std::endl;
	
	bool checkE0 = sporRMS_OA_E0 - spotZemaxOA_EO < 0.0;
	workTheOptimizer.push_back(checkE0);
	
	
	////END SYSTEM E0////////////////////////////////////////////////////////////////////////////////////
	
	//SYSTEM E1////////////////////////////////////////////////////////////////////////////////////
	// set the wavelength
	Light_LLT Light_E1;
	Light_E1.setWavelength(550.0);
	Light_E1.setIntensity(1.0);
	std::vector<Light_LLT> lichtVecE1{ Light_E1 };
	
	// surfaces E1
	ApertureStopElement AperStop0_E1(/* semi height*/1.0, /*point*/{ 0.0,0.0,10.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glass1);
	SphericalElement Sphere1_E1(/*radius*/ 15.0, /*semi height*/ 3.0, /*point*/{ 0.0,0.0,15.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glass1, /*refractive index B*/glass15);
	SphericalElement Sphere2_E1(/*radius*/ 7.0, /*semi height*/ 3.0, /*point*/{ 0.0,0.0,20.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glass1, /*refractive index B*/glass15);
	SphericalElement Sphere3_E1(/*radius*/ 100.0, /*semi height*/ 3.0, /*point*/{ 0.0,0.0,25.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glass15, /*refractive index B*/glass1);
	SphericalElement Sphere4_E1(/*radius*/ 100.0, /*semi height*/ 3.0, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glass15, /*refractive index B*/glass1);
	PlanElement Plan5_E1(/*semi height*/ 3.0, /*point*/{ 0.0,0.0,40.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glass1, /*refractive index B*/ glass1);
	
	// set the radius variable
	Sphere1_E1.setParameterRadius(5.0, 20.0, 0.0, typeModifierVariable);
	Sphere2_E1.setParameterRadius(5.0, 15.0, 0, typeModifierVariable);
	
	surfacePtr AperStop0_E1_ptr = AperStop0_E1.clone();
	surfacePtr Sphere1_E1_ptr = Sphere1_E1.clone();
	surfacePtr Sphere2_E1_ptr = Sphere2_E1.clone();
	surfacePtr Sphere3_E1_ptr = Sphere3_E1.clone();
	surfacePtr Sphere4_E1_ptr = Sphere4_E1.clone();
	surfacePtr Plan5_E1_ptr = Plan5_E1.clone();
	
	std::vector<surfacePtr> opticalSystemE1_ptr{ AperStop0_E1_ptr, Sphere1_E1_ptr, Sphere2_E1_ptr, Sphere3_E1_ptr, Sphere4_E1_ptr, Plan5_E1_ptr };
	std::vector<interactionPtr> interactionsE1_ptr{ doNothing.clone() ,refrac.clone(), refrac.clone(),refrac.clone(),refrac.clone(), absorb.clone() };
	
	// build optical system
	OpticalSystemElement optSystemElement_E1(opticalSystemE1_ptr, interactionsE1_ptr);
	
	// trace the ray thow the optical system
	SequentialRayTracing seqTrace_E1_optA(/*optical system element*/ optSystemElement_E1, /*start point lightRay*/{ 0.0,0.0,0.0 }, /*rings*/ 6, /*arms*/ 8, /*refractive index*/ 1.0, lichtVecE1);
	
	// calculate rms value
	Spot spot_E1_optA(seqTrace_E1_optA.getAllInterPointsAtSurf_i_notFiltered(5), seqTrace_E1_optA.getAllInterPointsAtSurf_i_notFiltered(5).at(0));
	real rms_E1_optA = spot_E1_optA.getRMS_µm();
	std::cout << "Organic RMS optA E0: " << rms_E1_optA << "\n";
	workTheOptimizer.push_back(std::abs(rms_E1_optA - 345.544) < 0.1);
	
	// next we start the optimasation
	std::cout << "start of the optimizer example E1 \n";
	// population of the optimasation process
	unsigned int population_E1 = 1000;
	
	// stadt the optim
	localStart localOp_E1 = radiusStart;
	/*mutation factor*/
	real mutarionFactor_E1 = 0.01;
	
	OptimizeOpticalSystem optimizedOptSys_E1(optSystemElement_E1, population_E1, mutarionFactor_E1, localOp_E1);
	
	// set rings and arms for the optimasation
	optimizedOptSys_E1.setRings_optimizer(6);
	optimizedOptSys_E1.setArms_optimizer(8);
	// *********************************
	// start optimasation of example E12
	optimizedOptSys_E1.optimizeSUPERFUNCTION();
	// *********************************
	// get the optimized optical system
	OpticalSystemElement optimizedOptSys_Ele_E1 = optimizedOptSys_E1.getOptSysOptimized_Ele();
	
	// trace the ray thow the optical system
	SequentialRayTracing seqTrace_E1_optA_AO(/*optical system element*/ optimizedOptSys_Ele_E1, /*start point lightRay*/{ 0.0,0.0,0.0 }, /*rings*/ 6, /*arms*/ 8, /*refractive index*/ 1.0, Light_E1);
	Spot SpotOptA_AO_E1(seqTrace_E1_optA_AO.getAllInterPointsAtSurf_i_notFiltered(5), seqTrace_E1_optA_AO.getAllInterPointsAtSurf_i_notFiltered(5).at(0));
	real sporRMS_OA_E1 = SpotOptA_AO_E1.getRMS_µm();
	real spotZemaxOA_E1 = 30.450;
	std::cout << "RMS AO optA E1: " << sporRMS_OA_E1 << "\n";
	std::cout << "radius R1 E1: " << optimizedOptSys_E1.getOptSysOptimized_LLT().getPosAndInteractingSurface().at(1).getSurfaceInterRay_ptr()->getRadius() << std::endl;
	std::cout << "radius R2 E1: " << optimizedOptSys_E1.getOptSysOptimized_LLT().getPosAndInteractingSurface().at(2).getSurfaceInterRay_ptr()->getRadius() << std::endl;
	
	bool checkE1 = sporRMS_OA_E1 - spotZemaxOA_E1 < 0.0;
	workTheOptimizer.push_back(checkE1);
	
	//END SYSTEM E1////////////////////////////////////////////////////////////////////////////////////
	
	//SYSTEM E2////////////////////////////////////////////////////////////////////////////////////
	// set the wavelength
	Light_LLT Light_E2_XX;
	Light_E2_XX.setWavelength(550.0);
	Light_E2_XX.setIntensity(1.0);
	std::vector<Light_LLT> lichtVecE2{ Light_E2_XX };
	
	// surfaces E2
	ApertureStopElement AperStop0_E2(/* semi height*/1.0, /*point*/{ 0.0,0.0,10.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glass1);
	SphericalElement Sphere1_E2(/*radius*/ 10.0, /*semi height*/ 3.0, /*point*/{ 0.0,0.0,15.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glass1, /*refractive index B*/glass15);
	SphericalElement Sphere2_E2(/*radius*/ 6.0, /*semi height*/ 3.0, /*point*/{ 0.0,0.0,20.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glass1, /*refractive index B*/glass15);
	SphericalElement Sphere3_E2(/*radius*/ 50.0, /*semi height*/ 3.0, /*point*/{ 0.0,0.0,25.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glass15, /*refractive index B*/glass1);
	SphericalElement Sphere4_E2(/*radius*/ 50.0, /*semi height*/ 3.0, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glass1, /*refractive index B*/glass15);
	PlanElement Plan5_E2(/*semi height*/ 3.0, /*point*/{ 0.0,0.0,40.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glass1, /*refractive index B*/ glass1);
	
	// set the radius variable
	Sphere1_E2.setParameterRadius(5.0, 25.0, 0.0, typeModifierVariable);
	Sphere2_E2.setParameterRadius(5.0, 15.0, 0, typeModifierVariable);
	Sphere4_E2.setParameterRadius(5.0, 100.0, 0, typeModifierVariable);
	
	surfacePtr AperStop0_E2_ptr = AperStop0_E2.clone();
	surfacePtr Sphere1_E2_ptr = Sphere1_E2.clone();
	surfacePtr Sphere2_E2_ptr = Sphere2_E2.clone();
	surfacePtr Sphere3_E2_ptr = Sphere3_E2.clone();
	surfacePtr Sphere4_E2_ptr = Sphere4_E2.clone();
	surfacePtr Plan5_E2_ptr = Plan5_E2.clone();
	
	std::vector<surfacePtr> opticalSystemE2_ptr{ AperStop0_E2_ptr, Sphere1_E2_ptr, Sphere2_E2_ptr, Sphere3_E2_ptr, Sphere4_E2_ptr, Plan5_E2_ptr };
	std::vector<interactionPtr> interactionsE2_ptr{ doNothing.clone(),refrac.clone(), refrac.clone(),refrac.clone(),refrac.clone(), absorb.clone() };
	
	// build optical system
	OpticalSystemElement optSystemElement_E2(opticalSystemE2_ptr, interactionsE2_ptr);
	
	// trace the ray thow the optical system
	SequentialRayTracing seqTrace_E2_optA(/*optical system element*/ optSystemElement_E2, /*start point lightRay*/{ 0.0,0.0,0.0 }, /*rings*/ 6, /*arms*/ 8, /*refractive index*/ 1.0, lichtVecE2);
	
	
	// calculate rms value
	Spot spot_E2_optA(seqTrace_E2_optA.getAllInterPointsAtSurf_i_notFiltered(5), seqTrace_E2_optA.getAllInterPointsAtSurf_i_notFiltered(5).at(0));
	real rms_E2_optA = spot_E2_optA.getRMS_µm();
	std::cout << "Organic RMS optA E2: " << rms_E2_optA << "\n";
	workTheOptimizer.push_back(std::abs(rms_E2_optA - 356.607) < 0.1);
	
	// next we start the optimasation
	std::cout << "start of the optimizer example E2 \n";
	// population of the optimasation process
	unsigned int population_E2 = 2000;
	
	// stadt the optim
	localStart localOp_E2 = radiusStart;
	/*mutation factor*/
	real mutarionFactor_E2 = 0.01;
	
	OptimizeOpticalSystem optimizedOptSys_E2(optSystemElement_E2, population_E2, mutarionFactor_E2, localOp_E2);
	
	// set rings and arms for the optimasation
	optimizedOptSys_E2.setRings_optimizer(6);
	optimizedOptSys_E2.setArms_optimizer(8);
	// *********************************
	// start optimasation of example E22
	optimizedOptSys_E2.optimizeSUPERFUNCTION();
	// *********************************
	// get the optimized optical system
	OpticalSystemElement optimizedOptSys_Ele_E2 = optimizedOptSys_E2.getOptSysOptimized_Ele();
	
	// trace the ray thow the optical system
	SequentialRayTracing seqTrace_E2_optA_AO(/*optical system element*/ optimizedOptSys_Ele_E2, /*start point lightRay*/{ 0.0,0.0,0.0 }, /*rings*/ 6, /*arms*/ 8, /*refractive index*/ 1.0, lichtVecE2);
	Spot SpotOptA_AO_E2(seqTrace_E2_optA_AO.getAllInterPointsAtSurf_i_notFiltered(5), seqTrace_E2_optA_AO.getAllInterPointsAtSurf_i_notFiltered(5).at(0));
	real sporRMS_OA_E2 = SpotOptA_AO_E2.getRMS_µm();
	real spotZemaxOA_E2 = 18.919;
	std::cout << "RMS AO optA E2: " << sporRMS_OA_E2 << "\n";
	std::cout << "radius R1 E2: " << optimizedOptSys_E2.getOptSysOptimized_LLT().getPosAndInteractingSurface().at(1).getSurfaceInterRay_ptr()->getRadius() << std::endl;
	std::cout << "radius R2 E2: " << optimizedOptSys_E2.getOptSysOptimized_LLT().getPosAndInteractingSurface().at(2).getSurfaceInterRay_ptr()->getRadius() << std::endl;
	std::cout << "radius R4 E2: " << optimizedOptSys_E2.getOptSysOptimized_LLT().getPosAndInteractingSurface().at(4).getSurfaceInterRay_ptr()->getRadius() << std::endl;
	
	std::cout << "RMS E2 optA: " << sporRMS_OA_E2 << std::endl;
	
	bool checkE2 = sporRMS_OA_E2 - spotZemaxOA_E2 < 0.0;
	workTheOptimizer.push_back(checkE2);
	
	//END SYSTEM E2////////////////////////////////////////////////////////////////////////////////////
	
	//SYSTEM E3////////////////////////////////////////////////////////////////////////////////////
	// set the wavelength
	Light_LLT Light_E3_XX;
	Light_E3_XX.setWavelength(550.0);
	Light_E3_XX.setIntensity(1.0);
	std::vector<Light_LLT> lichtVecE3{ Light_E3_XX };
	
	// surfaces E3
	ApertureStopElement AperStop0_E3(/* semi height*/1.0, /*point*/{ 0.0,0.0,10.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glass1);
	SphericalElement Sphere1_E3(/*radius*/ 6.0, /*semi height*/ 3.0, /*point*/{ 0.0,0.0,15.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glass1, /*refractive index B*/glass15);
	SphericalElement Sphere2_E3(/*radius*/ 6.0, /*semi height*/ 3.0, /*point*/{ 0.0,0.0,20.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glass1, /*refractive index B*/glass15);
	PlanElement Plan3_E3(/*semi height*/ 3.0, /*point*/{ 0.0,0.0,30.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glass1, /*refractive index B*/ glass1);
	
	// set the radius variable
	Sphere1_E3.setParameterRadius(5.0, 15.0, 0.0, typeModifierVariable);
	
	surfacePtr AperStop0_E3_ptr = AperStop0_E3.clone();
	surfacePtr Sphere1_E3_ptr = Sphere1_E3.clone();
	surfacePtr Sphere2_E3_ptr = Sphere2_E3.clone();
	surfacePtr Plan3_E3_ptr = Plan3_E3.clone();
	
	
	std::vector<surfacePtr> opticalSystemE3_ptr{ AperStop0_E3_ptr, Sphere1_E3_ptr, Sphere2_E3_ptr, Plan3_E3_ptr };
	std::vector<interactionPtr> interactionsE3_ptr{ doNothing.clone(),refrac.clone(), refrac.clone(), absorb.clone() };
	
	//// build optical system
	OpticalSystemElement optSystemElement_E3(opticalSystemE3_ptr, interactionsE3_ptr);
	
	// trace the ray thow the optical system
	SequentialRayTracing seqTrace_E3_optA(/*optical system element*/ optSystemElement_E3, /*start point lightRay*/{ 0.0,0.0,0.0 }, /*rings*/ 6, /*arms*/ 8, /*refractive index*/ 1.0, lichtVecE3);
	
	
	// calculate rms value
	Spot spot_E3_optA(seqTrace_E3_optA.getAllInterPointsAtSurf_i_notFiltered(3), seqTrace_E3_optA.getAllInterPointsAtSurf_i_notFiltered(3).at(0));
	real rms_E3_optA = spot_E3_optA.getRMS_µm();
	std::cout << "Organic RMS optA E0: " << rms_E3_optA << "\n";
	workTheOptimizer.push_back(std::abs(rms_E3_optA - 123.953) < 0.1);
	
	// next we start the optimasation
	std::cout << "start of the optimizer example E3 \n";
	// population of the optimasation process
	unsigned int population_E3 = 1000;
	
	// stadt the optim
	localStart localOp_E3 = radiusStart;
	/*mutation factor*/
	real mutarionFactor_E3 = 0.01;
	
	OptimizeOpticalSystem optimizedOptSys_E3(optSystemElement_E3, population_E3, mutarionFactor_E3, localOp_E3);
	
	// set rings and arms for the optimasation
	optimizedOptSys_E3.setRings_optimizer(6);
	optimizedOptSys_E3.setArms_optimizer(8);
	// here we say that the EFL of the system should be 8 mm
	// we really want an EFL of 8 mm, so we set the weight to 10000
	optimizedOptSys_E3.add_TargetEFL(8.0,10000.0);
	//optimizedOptSys_E3.set_Field({ 0.0,0.0,0.0}, 0.01);
	// *********************************
	// start optimasation of example E32
	optimizedOptSys_E3.optimizeSUPERFUNCTION();
	// *********************************
	// get the optimized optical system
	OpticalSystemElement optimizedOptSys_Ele_E3 = optimizedOptSys_E3.getOptSysOptimized_Ele();
	
	// trace the ray thow the optical system
	SequentialRayTracing seqTrace_E3_optA_AO(/*optical system element*/ optimizedOptSys_Ele_E3, /*start point lightRay*/{ 0.0,0.0,0.0 }, /*rings*/ 6, /*arms*/ 8, /*refractive index*/ 1.0, lichtVecE3);
	Spot SpotOptA_AO_E3(seqTrace_E3_optA_AO.getAllInterPointsAtSurf_i_notFiltered(3), seqTrace_E3_optA_AO.getAllInterPointsAtSurf_i_notFiltered(3).at(0));
	real sporRMS_OA_E3 = SpotOptA_AO_E3.getRMS_µm();
	real spotZemaxOA_E3 = 180.078;
	std::cout << "RMS AO optA E3: " << sporRMS_OA_E3 << "\n";
	std::cout << "radius R1 E3: " << optimizedOptSys_E3.getOptSysOptimized_LLT().getPosAndInteractingSurface().at(1).getSurfaceInterRay_ptr()->getRadius() << std::endl;
	std::cout << "EFFL system E3: " << optimizedOptSys_E3.getEFL_AO() << std::endl;
	
	
	bool checkE3_RMS = std::abs(sporRMS_OA_E3 - spotZemaxOA_E3) < 50.0;
	bool checkE3_EFF = std::abs(optimizedOptSys_E3.getEFL_AO() - 8) < 0.1;
	workTheOptimizer.push_back(checkE3_RMS);
	workTheOptimizer.push_back(checkE3_EFF);
	
	//END SYSTEM E3////////////////////////////////////////////////////////////////////////////////////
	
	//SYSTEM E4////////////////////////////////////////////////////////////////////////////////////
	// set the wavelength
	Light_LLT Light_E4_XX;
	Light_E4_XX.setWavelength(550.0);
	Light_E4_XX.setIntensity(1.0);
	std::vector<Light_LLT> lichtVecE4{ Light_E4_XX };
	
	// surfaces E4
	ApertureStopElement AperStop0_E4(/* semi height*/1.0, /*point*/{ 0.0,0.0,10.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glass1);
	SphericalElement Sphere1_E4(/*radius*/ 20.0, /*semi height*/ 3.0, /*point*/{ 0.0,0.0,15.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glass1, /*refractive index B*/glass15);
	SphericalElement Sphere2_E4(/*radius*/ 15.0, /*semi height*/ 3.0, /*point*/{ 0.0,0.0,20.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glass1, /*refractive index B*/glass15);
	SphericalElement Sphere3_E4(/*radius*/ 15.0, /*semi height*/ 3.0, /*point*/{ 0.0,0.0,25.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glass1, /*refractive index B*/glass15);
	SphericalElement Sphere4_E4(/*radius*/ 10.0, /*semi height*/ 3.0, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glass1, /*refractive index B*/glass15);
	PlanElement Plan5_E4(/*semi height*/ 3.0, /*point*/{ 0.0,0.0,40.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glass1, /*refractive index B*/ glass1);
	
	// set the radius variable
	Sphere1_E4.setParameterRadius(5.0, 15.0, 0.0, typeModifierVariable);
	Sphere4_E4.setParameterRadius(10.0, 15.0, 0.0, typeModifierVariable);
	
	surfacePtr AperStop0_E4_ptr = AperStop0_E4.clone();
	surfacePtr Sphere1_E4_ptr = Sphere1_E4.clone();
	surfacePtr Sphere2_E4_ptr = Sphere2_E4.clone();
	surfacePtr Sphere3_E4_ptr = Sphere3_E4.clone();
	surfacePtr Sphere4_E4_ptr = Sphere4_E4.clone();
	surfacePtr Plan5_E4_ptr = Plan5_E4.clone();
	
	std::vector<surfacePtr> opticalSystemE4_ptr{ AperStop0_E4_ptr, Sphere1_E4_ptr, Sphere2_E4_ptr, Sphere3_E4_ptr, Sphere4_E4_ptr, Plan5_E4_ptr };
	std::vector<interactionPtr> interactionsE4_ptr{ doNothing.clone(),refrac.clone(), refrac.clone(), refrac.clone(), refrac.clone(), absorb.clone() };
	
	// build optical system
	OpticalSystemElement optSystemElement_E4(opticalSystemE4_ptr, interactionsE4_ptr);
	
	// trace the ray thow the optical system
	SequentialRayTracing seqTrace_E4_optA(/*optical system element*/ optSystemElement_E4, /*start point lightRay*/{ 0.0,0.0,0.0 }, /*rings*/ 6, /*arms*/ 8, /*refractive index*/ 1.0, lichtVecE4);
	
	// calculate rms value
	Spot spot_E4_optA(seqTrace_E4_optA.getAllInterPointsAtSurf_i_notFiltered(5), seqTrace_E4_optA.getAllInterPointsAtSurf_i_notFiltered(5).at(0));
	real rms_E4_optA = spot_E4_optA.getRMS_µm();
	std::cout << "Organic RMS optA E4: " << rms_E4_optA << "\n";
	workTheOptimizer.push_back(std::abs(rms_E4_optA - 159.302) < 0.1);
	
	// next we start the optimasation
	std::cout << "start of the optimizer example E4 \n";
	// population of the optimasation process
	unsigned int population_E4 = 1000;
	
	// stadt the optim
	localStart localOp_E4 = radiusStart;
	/*mutation factor*/
	real mutarionFactor_E4 = 0.1;
	
	OptimizeOpticalSystem optimizedOptSys_E4(optSystemElement_E4, population_E4, mutarionFactor_E4, localOp_E4);
	
	// set rings and arms for the optimasation
	optimizedOptSys_E4.setRings_optimizer(6);
	optimizedOptSys_E4.setArms_optimizer(8);
	// here we say that the EXPP of the system should be at 40 mm
	optimizedOptSys_E4.add_TargetEXPP(40.0, 10000);
	optimizedOptSys_E4.setCheckAllLocalCombinations_optimizer(true);
	// *********************************
	// start optimasation of example E42
	optimizedOptSys_E4.optimizeSUPERFUNCTION();
	// *********************************
	// get the optimized optical system
	OpticalSystemElement optimizedOptSys_Ele_E4 = optimizedOptSys_E4.getOptSysOptimized_Ele();
	
	// trace the ray thow the optical system
	SequentialRayTracing seqTrace_E4_optA_AO(/*optical system element*/ optimizedOptSys_Ele_E4, /*start point lightRay*/{ 0.0,0.0,0.0 }, /*rings*/ 6, /*arms*/ 8, /*refractive index*/ 1.0, lichtVecE4);
	Spot SpotOptA_AO_E4(seqTrace_E4_optA_AO.getAllInterPointsAtSurf_i_notFiltered(5), seqTrace_E4_optA_AO.getAllInterPointsAtSurf_i_notFiltered(5).at(0));
	real sporRMS_OA_E4 = SpotOptA_AO_E4.getRMS_µm();
	real spotZemaxOA_E4 = 12.246;
	std::cout << "RMS AO optA E4: " << sporRMS_OA_E4 << "\n";
	std::cout << "radius R0 E4: " << optimizedOptSys_E4.getOptSysOptimized_LLT().getPosAndInteractingSurface().at(1).getSurfaceInterRay_ptr()->getRadius() << std::endl;
	std::cout << "radius R4 E4: " << optimizedOptSys_E4.getOptSysOptimized_LLT().getPosAndInteractingSurface().at(4).getSurfaceInterRay_ptr()->getRadius() << std::endl;
		std::cout << "EXPP z E4: " << optimizedOptSys_E4.getEXPP_z_AO() << std::endl;
	
	
	
	bool checkE4_RMS = std::abs(sporRMS_OA_E4 - spotZemaxOA_E4) < 50.0;
	std::cout << "RMS E4 optA: " << sporRMS_OA_E4 << std::endl;
	bool checkE4_EXPP = std::abs(optimizedOptSys_E4.getEXPP_z_AO() - 40) < 0.1;
	workTheOptimizer.push_back(checkE4_RMS);
	workTheOptimizer.push_back(checkE4_EXPP);
	
	// END SYSTEM E4////////////////////////////////////////////////////////////////////////////////////
	
	//SYSTEM E5////////////////////////////////////////////////////////////////////////////////////
	// set the wavelength
	Light_LLT Light_E5_XX;
	Light_E5_XX.setWavelength(550.0);
	Light_E5_XX.setIntensity(1.0);
	std::vector<Light_LLT> lichtVecE5{ Light_E5_XX };
	
	// surfaces E5
	ApertureStopElement AperStop0_E5(/* semi height*/1.0, /*point*/{ 0.0,0.0,10.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glass1);
	SphericalElement Sphere1_E5(/*radius*/ 20.0, /*semi height*/ 3.0, /*point*/{ 0.0,0.0,15.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glass1, /*refractive index B*/glass15);
	SphericalElement Sphere2_E5(/*radius*/ 15.0, /*semi height*/ 3.0, /*point*/{ 0.0,0.0,20.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glass1, /*refractive index B*/glass15);
	SphericalElement Sphere3_E5(/*radius*/ 15.0, /*semi height*/ 3.0, /*point*/{ 0.0,0.0,25.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glass1, /*refractive index B*/glass15);
	SphericalElement Sphere4_E5(/*radius*/ 10.0, /*semi height*/ 3.0, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glass1, /*refractive index B*/glass15);
	PlanElement Plan5_E5(/*semi height*/ 3.0, /*point*/{ 0.0,0.0,40.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glass1, /*refractive index B*/ glass1);
	
	// set the radius variable
	Sphere1_E5.setParameterRadius(5.0, 15.0, 0.0, typeModifierVariable);
	Sphere4_E5.setParameterRadius(5.0, 15.0, 0.0, typeModifierVariable);
	
	surfacePtr AperStop0_E5_ptr = AperStop0_E5.clone();
	surfacePtr Sphere1_E5_ptr = Sphere1_E5.clone();
	surfacePtr Sphere2_E5_ptr = Sphere2_E5.clone();
	surfacePtr Sphere3_E5_ptr = Sphere3_E5.clone();
	surfacePtr Sphere4_E5_ptr = Sphere4_E5.clone();
	surfacePtr Plan5_E5_ptr = Plan5_E5.clone();
	
	std::vector<surfacePtr> opticalSystemE5_ptr{ AperStop0_E5_ptr, Sphere1_E5_ptr, Sphere2_E5_ptr, Sphere3_E5_ptr, Sphere4_E5_ptr, Plan5_E5_ptr };
	std::vector<interactionPtr> interactionsE5_ptr{ doNothing.clone(),refrac.clone(), refrac.clone(), refrac.clone(), refrac.clone(), absorb.clone() };
	
	//// build optical system
	OpticalSystemElement optSystemElement_E5(opticalSystemE5_ptr, interactionsE5_ptr);
	
	// trace the ray thow the optical system
	SequentialRayTracing seqTrace_E5_optA(/*optical system element*/ optSystemElement_E5, /*start point lightRay*/{ 0.0,0.0,0.0 }, /*rings*/ 6, /*arms*/ 8, /*refractive index*/ 1.0, lichtVecE5);
	
	// calculate rms value
	Spot spot_E5_optA(seqTrace_E5_optA.getAllInterPointsAtSurf_i_notFiltered(5), seqTrace_E5_optA.getAllInterPointsAtSurf_i_notFiltered(5).at(0));
	real rms_E5_optA = spot_E5_optA.getRMS_µm();
	std::cout << "Organic RMS optA E5: " << rms_E5_optA << "\n";
	workTheOptimizer.push_back(std::abs(rms_E5_optA - 159.302) < 0.1);
	
	// next we start the optimasation
	std::cout << "start of the optimizer example E5 \n";
	// population of the optimasation process
	unsigned int population_E5 = 500;
	
	// stadt the optim
	localStart localOp_E5 = radiusStart;
	/*mutation factor*/
	real mutarionFactor_E5 = 0.01;
	
	OptimizeOpticalSystem optimizedOptSys_E5(optSystemElement_E5, population_E5, mutarionFactor_E5, localOp_E5);
	
	// set rings and arms for the optimasation
	optimizedOptSys_E5.setRings_optimizer(6);
	optimizedOptSys_E5.setArms_optimizer(8);
	// here we say that the EXPP of the system should be at 40 mm
	// we really want an EXPP of 40 mm, so we set the weight to 10
	optimizedOptSys_E5.add_TargetEXPD(7.0, 1000.0);
	// *********************************
	// start optimasation of example E52
	optimizedOptSys_E5.optimizeSUPERFUNCTION();
	// *********************************
	// get the optimized optical system
	OpticalSystemElement optimizedOptSys_Ele_E5 = optimizedOptSys_E5.getOptSysOptimized_Ele();
	
	// trace the ray thow the optical system
	SequentialRayTracing seqTrace_E5_optA_AO(/*optical system element*/ optimizedOptSys_Ele_E5, /*start point lightRay*/{ 0.0,0.0,0.0 }, /*rings*/ 6, /*arms*/ 8, /*refractive index*/ 1.0, lichtVecE5);
	Spot SpotOptA_AO_E5(seqTrace_E5_optA_AO.getAllInterPointsAtSurf_i_notFiltered(5), seqTrace_E5_optA_AO.getAllInterPointsAtSurf_i_notFiltered(5).at(0));
	real sporRMS_OA_E5 = SpotOptA_AO_E5.getRMS_µm();
	real spotZemaxOA_E5 = 12.567;
	std::cout << "RMS AO optA E5: " << sporRMS_OA_E5 << "\n";
	std::cout << "radius R1 E5: " << optimizedOptSys_E5.getOptSysOptimized_LLT().getPosAndInteractingSurface().at(1).getSurfaceInterRay_ptr()->getRadius() << std::endl;
	std::cout << "radius R4 E5: " << optimizedOptSys_E5.getOptSysOptimized_LLT().getPosAndInteractingSurface().at(4).getSurfaceInterRay_ptr()->getRadius() << std::endl;
	std::cout << "EXPD E5: " << optimizedOptSys_E5.getEXPD_AO() << std::endl;
	
	std::cout << "RMS E5: " << sporRMS_OA_E5 << std::endl;
	
	bool checkE5_RMS = sporRMS_OA_E5 - spotZemaxOA_E5 < 10.0;
	bool checkE5_EXPD = std::abs(optimizedOptSys_E5.getEXPD_AO() - 7.0) < 0.1;
	workTheOptimizer.push_back(checkE5_RMS);
	workTheOptimizer.push_back(checkE5_EXPD);
	
	// END SYSTEM E5////////////////////////////////////////////////////////////////////////////////////
	
	//SYSTEM E6 //////////////////////////////////////////////////////////////////////////////////
	// set the wavelength
	Light_LLT Light_E6_XX;
	Light_E6_XX.setWavelength(550.0);
	Light_E6_XX.setIntensity(1.0);
	std::vector<Light_LLT> lichtVecE6{ Light_E6_XX };
	
	// surfaces E6
	ApertureStopElement AperStop0_E6(/* semi height*/1.0, /*point*/{ 0.0,0.0,10.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glass1);
	SphericalElement Sphere1_E6(/*radius*/ 15.0, /*semi height*/ 3.0, /*point*/{ 0.0,0.0,15.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glass1, /*refractive index B*/glass15);
	SphericalElement Sphere2_E6(/*radius*/ 10.0, /*semi height*/ 3.0, /*point*/{ 0.0,0.0,20.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glass1, /*refractive index B*/glass15);
	SphericalElement Sphere3_E6(/*radius*/ 10.0, /*semi height*/ 3.0, /*point*/{ 0.0,0.0,21.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glass1, /*refractive index B*/glass15);
	SphericalElement Sphere4_E6(/*radius*/ 5.0, /*semi height*/ 3.0, /*point*/{ 0.0,0.0,26.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glass1, /*refractive index B*/glass15);
	PlanElement Plan5_E6(/*semi height*/ 3.0, /*point*/{ 0.0,0.0,31.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glass1, /*refractive index B*/ glass1);
	
	//	// set the radius variable
	Sphere1_E6.setParameterRadius(5.0, 15.0, 0.0, typeModifierVariable);
	Sphere2_E6.setParameterRadius(5.0, 15.0, 0.0, typeModifierVariable);
	Sphere3_E6.setParameterRadius(40.0, 60.0, 0.0, typeModifierVariable);
	
	surfacePtr AperStop0_E6_ptr = AperStop0_E6.clone();
	surfacePtr Sphere1_E6_ptr = Sphere1_E6.clone();
	surfacePtr Sphere2_E6_ptr = Sphere2_E6.clone();
	surfacePtr Sphere3_E6_ptr = Sphere3_E6.clone();
	surfacePtr Sphere4_E6_ptr = Sphere4_E6.clone();
	surfacePtr Plan5_E6_ptr = Plan5_E6.clone();
	
	std::vector<surfacePtr> opticalSystemE6_ptr{ AperStop0_E6_ptr, Sphere1_E6_ptr, Sphere2_E6_ptr, Sphere3_E6_ptr, Sphere4_E6_ptr, Plan5_E6_ptr };
	std::vector<interactionPtr> interactionsE6_ptr{ doNothing.clone(),refrac.clone(), refrac.clone(), refrac.clone(), refrac.clone(), absorb.clone() };
	
	//	//// build optical system
	OpticalSystemElement optSystemElement_E6(opticalSystemE6_ptr, interactionsE6_ptr);
	
	// trace the ray thow the optical system
	SequentialRayTracing seqTrace_E6_optA(/*optical system element*/ optSystemElement_E6, /*start point lightRay*/{ 0.0,0.0,0.0 }, /*rings*/ 6, /*arms*/ 8, /*refractive index*/ 1.0, lichtVecE6);
	
	// calculate rms value
	Spot spot_E6_optA(seqTrace_E6_optA.getAllInterPointsAtSurf_i_notFiltered(5), seqTrace_E6_optA.getAllInterPointsAtSurf_i_notFiltered(5).at(0));
	real rms_E6_optA = spot_E6_optA.getRMS_µm();
	std::cout << "Organic RMS optA E6: " << rms_E6_optA << "\n";
	workTheOptimizer.push_back(std::abs(rms_E6_optA - 58.026) < 1.0);
	
	//	// next we start the optimasation
	std::cout << "start of the optimizer example E6 \n";
	// population of the optimasation process
	unsigned int population_E6 = 1000;
	
	// stadt the optim
	localStart localOp_E6 = radiusStart;
	/*mutation factor*/
	real mutarionFactor_E6 = 0.05;
	
	OptimizeOpticalSystem optimizedOptSys_E6(optSystemElement_E6, population_E6, mutarionFactor_E6, localOp_E6);
	
	// set rings and arms for the optimasation
	optimizedOptSys_E6.setRings_optimizer(6);
	optimizedOptSys_E6.setArms_optimizer(8);
	// here we say that the EXPP of the system should be at 40 mm
	// we really want an EXPP of 40 mm, so we set the weight to 10
	optimizedOptSys_E6.add_FieldAndWeight({ 0.0,0.5,0.0 }, 1.0);
	optimizedOptSys_E6.add_FieldAndWeight({ 0.0,1.0,0.0 }, 1.0);
	// *********************************
	// start optimasation of example E62
	optimizedOptSys_E6.optimizeSUPERFUNCTION();
	// *********************************
	// get the optimized optical system
	OpticalSystemElement optimizedOptSys_Ele_E6 = optimizedOptSys_E6.getOptSysOptimized_Ele();
	//	// trace the ray thow the optical system
	SequentialRayTracing seqTrace_E6_optA_AO(/*optical system element*/ optimizedOptSys_Ele_E6, /*start point lightRay*/{ 0.0,0.0,0.0 }, /*rings*/ 6, /*arms*/ 8, /*refractive index*/ 1.0, lichtVecE6);
	Spot SpotOptA_AO_E6_optA(seqTrace_E6_optA_AO.getAllInterPointsAtSurf_i_notFiltered(5), seqTrace_E6_optA_AO.getAllInterPointsAtSurf_i_notFiltered(5).at(0));
	real sporRMS_OA_E6_optA = SpotOptA_AO_E6_optA.getRMS_µm();
	real spotZemaxOA_E6_optA = 29.713;
	
	SequentialRayTracing seqTrace_E6_optA_field05(/*optical system element*/ optimizedOptSys_Ele_E6, /*start point lightRay*/{ 0.0,0.5,0.0 }, /*rings*/ 6, /*arms*/ 8, /*refractive index*/ 1.0, lichtVecE6);
	Spot SpotOptA_AO_E6_optA_field05(seqTrace_E6_optA_field05.getAllInterPointsAtSurf_i_notFiltered(5), seqTrace_E6_optA_field05.getAllInterPointsAtSurf_i_notFiltered(5).at(0));
	real sporRMS_OA_E6_optA_field05 = SpotOptA_AO_E6_optA_field05.getRMS_µm();
	real spotZemaxOA_E6_field05 = 57.980;
	
	SequentialRayTracing seqTrace_E6_optA_field1(/*optical system element*/ optimizedOptSys_Ele_E6, /*start point lightRay*/{ 0.0,1.0,0.0 }, /*rings*/ 6, /*arms*/ 8, /*refractive index*/ 1.0, lichtVecE6);
	Spot SpotOptA_AO_E6_optA_field1(seqTrace_E6_optA_field1.getAllInterPointsAtSurf_i_notFiltered(5), seqTrace_E6_optA_field1.getAllInterPointsAtSurf_i_notFiltered(5).at(0));
	real sporRMS_OA_E6_optA_field1 = SpotOptA_AO_E6_optA_field1.getRMS_µm();
	real spotZemaxOA_E6_field1 = 123.110;
	
	
	std::cout << "RMS AO optA E6 optA: " << sporRMS_OA_E6_optA << "\n";
	std::cout << "RMS AO optA E6 field05: " << sporRMS_OA_E6_optA_field05 << "\n";
	std::cout << "RMS AO optA E6 field1: " << sporRMS_OA_E6_optA_field1 << "\n";
	
	std::cout << "radius R1 E6: " << optimizedOptSys_E6.getOptSysOptimized_LLT().getPosAndInteractingSurface().at(1).getSurfaceInterRay_ptr()->getRadius() << std::endl;
	std::cout << "radius R2 E6: " << optimizedOptSys_E6.getOptSysOptimized_LLT().getPosAndInteractingSurface().at(2).getSurfaceInterRay_ptr()->getRadius() << std::endl;
	std::cout << "radius R6 E6: " << optimizedOptSys_E6.getOptSysOptimized_LLT().getPosAndInteractingSurface().at(3).getSurfaceInterRay_ptr()->getRadius() << std::endl;
	
	
	real GLOWsum = sporRMS_OA_E6_optA + sporRMS_OA_E6_optA_field05 + sporRMS_OA_E6_optA_field1;
	real ZemaxSum = spotZemaxOA_E6_optA + spotZemaxOA_E6_field05 + spotZemaxOA_E6_field1;
	
	std::cout << "GLOWsum RMS E6: " << GLOWsum << std::endl;
	bool checkRMSsum = GLOWsum - ZemaxSum < 0;
	workTheOptimizer.push_back(checkRMSsum);
	
	
	//////SYSTEM E6 END//////////////////////////////////////////////////////////////////////////////////
	
	//SYSTEM E7////////////////////////////////////////////////////////////////////////////////////
	// set the wavelength
	Light_LLT Light_E7_XX;
	Light_E7_XX.setWavelength(550.0);
	Light_E7_XX.setIntensity(1.0);
	std::vector<Light_LLT> lichtVecE7{ Light_E7_XX };
	
	// surfaces E7
	ApertureStopElement AperStop0_E7(/* semi height*/1.0, /*point*/{ 0.0,0.0,10.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glass1);
	SphericalElement Sphere1_E7(/*radius*/ 15.0, /*semi height*/ 3.0, /*point*/{ 0.0,0.0,15.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glass1, /*refractive index B*/glass15);
	SphericalElement Sphere2_E7(/*radius*/ 10.0, /*semi height*/ 3.0, /*point*/{ 0.0,0.0,20.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glass1, /*refractive index B*/glass15);
	SphericalElement Sphere3_E7(/*radius*/ 10.0, /*semi height*/ 3.0, /*point*/{ 0.0,0.0,21.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glass1, /*refractive index B*/glass15);
	SphericalElement Sphere4_E7(/*radius*/ 5.0, /*semi height*/ 3.0, /*point*/{ 0.0,0.0,26.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glass1, /*refractive index B*/glass15);
	PlanElement Plan5_E7(/*semi height*/ 3.0, /*point*/{ 0.0,0.0,31.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glass1, /*refractive index B*/ glass1);
	
	//	// set the radius variable
	Sphere2_E7.setParameterRadius(5.0, 100.0, 0.0, typeModifierVariable);
	Sphere3_E7.setParameterRadius(5.0, 100.0, 0.0, typeModifierVariable);
	
	surfacePtr AperStop0_E7_ptr = AperStop0_E7.clone();
	surfacePtr Sphere1_E7_ptr = Sphere1_E7.clone();
	surfacePtr Sphere2_E7_ptr = Sphere2_E7.clone();
	surfacePtr Sphere3_E7_ptr = Sphere3_E7.clone();
	surfacePtr Sphere4_E7_ptr = Sphere4_E7.clone();
	surfacePtr Plan5_E7_ptr = Plan5_E7.clone();
	
	std::vector<surfacePtr> opticalSystemE7_ptr{ AperStop0_E7_ptr, Sphere1_E7_ptr, Sphere2_E7_ptr, Sphere3_E7_ptr, Sphere4_E7_ptr, Plan5_E7_ptr };
	std::vector<interactionPtr> interactionsE7_ptr{ doNothing.clone(),refrac.clone(), refrac.clone(), refrac.clone(), refrac.clone(), absorb.clone() };
	
	//	//// build optical system
	OpticalSystemElement optSystemElement_E7(opticalSystemE7_ptr, interactionsE7_ptr);
	
	// trace the ray thow the optical system
	SequentialRayTracing seqTrace_E7_optA(/*optical system element*/ optSystemElement_E7, /*start point lightRay*/{ 0.0,0.0,0.0 }, /*rings*/ 6, /*arms*/ 8, /*refractive index*/ 1.0, lichtVecE7);
	
	// calculate rms value
	Spot spot_E7_optA(seqTrace_E7_optA.getAllInterPointsAtSurf_i_notFiltered(5), seqTrace_E7_optA.getAllInterPointsAtSurf_i_notFiltered(5).at(0));
	real rms_E7_optA = spot_E7_optA.getRMS_µm();
	std::cout << "Organic RMS optA E7: " << rms_E7_optA << "\n";
	workTheOptimizer.push_back(std::abs(rms_E7_optA - 58.026) < 1.0);
	
	//	// next we start the optimasation
	std::cout << "start of the optimizer example E7 \n";
	// population of the optimasation process
	unsigned int population_E7 = 500;
	
	// stadt the optim
	localStart localOp_E7 = radiusStart;
	/*mutation factor*/
	real mutarionFactor_E7 = 0.05;
	
	OptimizeOpticalSystem optimizedOptSys_E7(optSystemElement_E7, population_E7, mutarionFactor_E7, localOp_E7);
	
	// set rings and arms for the optimasation
	optimizedOptSys_E7.setRings_optimizer(6);
	optimizedOptSys_E7.setArms_optimizer(8);
	// here we say that the EXPP of the system should be at 40 mm
	// we really want an EXPP of 40 mm, so we set the weight to 10
	optimizedOptSys_E7.add_FieldAndWeight({ 0.0,-0.5,0.0 }, 1.0);
	// *********************************
	// start optimasation of example E72
	optimizedOptSys_E7.optimizeSUPERFUNCTION();
	// *********************************
	// get the optimized optical system
	OpticalSystemElement optimizedOptSys_Ele_E7 = optimizedOptSys_E7.getOptSysOptimized_Ele();
	
	//	// trace the ray thow the optical system
	SequentialRayTracing seqTrace_E7_optA_AO(/*optical system element*/ optimizedOptSys_Ele_E7, /*start point lightRay*/{ 0.0,0.0,0.0 }, /*rings*/ 6, /*arms*/ 8, /*refractive index*/ 1.0, lichtVecE7);
	Spot SpotOptA_AO_E7_optA(seqTrace_E7_optA_AO.getAllInterPointsAtSurf_i_notFiltered(5), seqTrace_E7_optA_AO.getAllInterPointsAtSurf_i_notFiltered(5).at(0));
	real sporRMS_OA_E7_optA = SpotOptA_AO_E7_optA.getRMS_µm();
	real spotZemaxOA_E7_optA = 31.608;
	
	SequentialRayTracing seqTrace_E7_optA_fieldNeg05(/*optical system element*/ optimizedOptSys_Ele_E7, /*start point lightRay*/{ 0.0,-0.5,0.0 }, /*rings*/ 6, /*arms*/ 8, /*refractive index*/ 1.0, lichtVecE7);
	Spot SpotOptA_AO_E7_optA_fieldNeg05(seqTrace_E7_optA_fieldNeg05.getAllInterPointsAtSurf_i_notFiltered(5), seqTrace_E7_optA_fieldNeg05.getAllInterPointsAtSurf_i_notFiltered(5).at(0));
	real sporRMS_OA_E7_optA_fieldNeg05 = SpotOptA_AO_E7_optA_fieldNeg05.getRMS_µm();
	real spotZemaxOA_E7_fieldNeg05 = 71.180;
	
	
	std::cout << "RMS AO optA E7 optA: " << sporRMS_OA_E7_optA << "\n";
	std::cout << "RMS AO optA E7 field05: " << sporRMS_OA_E7_optA_fieldNeg05 << "\n";
	
	std::cout << "radius R2 E7: " << optimizedOptSys_E7.getOptSysOptimized_LLT().getPosAndInteractingSurface().at(2).getSurfaceInterRay_ptr()->getRadius() << std::endl;
	std::cout << "radius R3 E7: " << optimizedOptSys_E7.getOptSysOptimized_LLT().getPosAndInteractingSurface().at(3).getSurfaceInterRay_ptr()->getRadius() << std::endl;
	
	
	bool checkE7_RMS_optA = std::abs(sporRMS_OA_E7_optA - spotZemaxOA_E7_optA) < 10;
	bool checkE7_RMS_field05 = std::abs(sporRMS_OA_E7_optA_fieldNeg05 - spotZemaxOA_E7_fieldNeg05) < 10;
	
	workTheOptimizer.push_back(checkE7_RMS_optA);
	workTheOptimizer.push_back(checkE7_RMS_field05);
	
	
	//////SYSTEM E7 END//////////////////////////////////////////////////////////////////////////////////
	
	//SYSTEM E8////////////////////////////////////////////////////////////////////////////////////
	// set the wavelength
	Light_LLT Light_E8_XX;
	Light_E8_XX.setWavelength(550.0);
	Light_E8_XX.setIntensity(1.0);
	std::vector<Light_LLT> lichtVecE8{ Light_E8_XX };
	
	// surfaces E8
	ApertureStopElement AperStop0_E8(/* semi height*/1.0, /*point*/{ 0.0,0.0,10.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glass1);
	SphericalElement Sphere1_E8(/*radius*/ 10.0, /*semi height*/ 3.0, /*point*/{ 0.0,0.0,15.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glass1, /*refractive index B*/glass15);
	SphericalElement Sphere2_E8(/*radius*/ 10.0, /*semi height*/ 3.0, /*point*/{ 0.0,0.0,20.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glass1, /*refractive index B*/glass15);
	SphericalElement Sphere3_E8(/*radius*/ 5.0, /*semi height*/ 3.0, /*point*/{ 0.0,0.0,25.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glass1, /*refractive index B*/glass15);
	SphericalElement Sphere4_E8(/*radius*/ 5.0, /*semi height*/ 3.0, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glass1, /*refractive index B*/glass15);
	PlanElement Plan5_E8(/*semi height*/ 10.0, /*point*/{ 0.0,0.0,35.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glass1, /*refractive index B*/ glass1);
	
	//	// set the radius variable
	Sphere1_E8.setParameterRadius(5.0, 10.0, 0.0, typeModifierVariable);
	// set the position of the spherical surface (4) variable
	Plan5_E8.setParameterPointZ(30.0, 35.0, 0.0, typeModifierVariable);
	
	surfacePtr AperStop0_E8_ptr = AperStop0_E8.clone();
	surfacePtr Sphere1_E8_ptr = Sphere1_E8.clone();
	surfacePtr Sphere2_E8_ptr = Sphere2_E8.clone();
	surfacePtr Sphere3_E8_ptr = Sphere3_E8.clone();
	surfacePtr Sphere4_E8_ptr = Sphere4_E8.clone();
	surfacePtr Plan5_E8_ptr = Plan5_E8.clone();
	
	std::vector<surfacePtr> opticalSystemE8_ptr{AperStop0_E8_ptr, Sphere1_E8_ptr, Sphere2_E8_ptr, Sphere3_E8_ptr, Sphere4_E8_ptr, Plan5_E8_ptr };
	std::vector<interactionPtr> interactionsE8_ptr{ doNothing.clone(),refrac.clone(), refrac.clone(), refrac.clone(), refrac.clone(), absorb.clone() };
	
	//	//// build optical system
	OpticalSystemElement optSystemElement_E8(opticalSystemE8_ptr, interactionsE8_ptr);
	
	// trace the ray thow the optical system
	SequentialRayTracing seqTrace_E8_optA(/*optical system element*/ optSystemElement_E8, /*start point lightRay*/{ 0.0,0.0,0.0 }, /*rings*/ 6, /*arms*/ 8, /*refractive index*/ 1.0, lichtVecE8);
	
	// calculate rms value
	Spot spot_E8_optA(seqTrace_E8_optA.getAllInterPointsAtSurf_i_notFiltered(5), seqTrace_E8_optA.getAllInterPointsAtSurf_i_notFiltered(5).at(0));
	real rms_E8_optA = spot_E8_optA.getRMS_µm();
	std::cout << "Organic RMS optA E8: " << rms_E8_optA << "\n";
	workTheOptimizer.push_back(std::abs(rms_E8_optA - 497.099) < 1.0);
	
	//	// next we start the optimasation
	std::cout << "start of the optimizer example E8 \n";
	// population of the optimasation process
	unsigned int population_E8 = 1000;
	
	// stadt the optim
	localStart localOp_E8 = radiusStart;
	/*mutation factor*/
	real mutarionFactor_E8 = 0.05;
	
	OptimizeOpticalSystem optimizedOptSys_E8(optSystemElement_E8, population_E8, mutarionFactor_E8, localOp_E8);
	
	// set rings and arms for the optimasation
	optimizedOptSys_E8.setRings_optimizer(6);
	optimizedOptSys_E8.setArms_optimizer(8);
	optimizedOptSys_E8.add_FieldAndWeight({ 0.0,-0.5,0.0 }, 1.0);
	// *********************************
	// start optimasation of example E82
	optimizedOptSys_E8.optimizeSUPERFUNCTION();
	// *********************************
	// get the optimized optical system
	OpticalSystemElement optimizedOptSys_Ele_E8 = optimizedOptSys_E8.getOptSysOptimized_Ele();
	
	//	// trace the ray thow the optical system
	SequentialRayTracing seqTrace_E8_optA_AO(/*optical system element*/ optimizedOptSys_Ele_E8, /*start point lightRay*/{ 0.0,0.0,0.0 }, /*rings*/ 6, /*arms*/ 8, /*refractive index*/ 1.0, lichtVecE8);
	Spot SpotOptA_AO_E8_optA(seqTrace_E8_optA_AO.getAllInterPointsAtSurf_i_notFiltered(5), seqTrace_E8_optA_AO.getAllInterPointsAtSurf_i_notFiltered(5).at(0));
	real sporRMS_OA_E8_optA = SpotOptA_AO_E8_optA.getRMS_µm();
	real spotZemaxOA_E8_optA = 12.274;
	
	SequentialRayTracing seqTrace_E8_field_neg05_AO(/*optical system element*/ optimizedOptSys_Ele_E8, /*start point lightRay*/{ 0.0,-0.5,0.0 }, /*rings*/ 6, /*arms*/ 8, /*refractive index*/ 1.0, lichtVecE8);
	Spot Spotfield_neg05_AO_E8_field_neg05(seqTrace_E8_field_neg05_AO.getAllInterPointsAtSurf_i_notFiltered(5), seqTrace_E8_field_neg05_AO.getAllInterPointsAtSurf_i_notFiltered(5).at(0));
	real sporRMS_OA_E8_field_neg05 = Spotfield_neg05_AO_E8_field_neg05.getRMS_µm();
	real spotZemaxOA_E8_field_neg05 = 28.571;
	
	real zemaxSum_E8 = spotZemaxOA_E8_optA + spotZemaxOA_E8_field_neg05;
	real GLOW_Sum_E8 = sporRMS_OA_E8_optA + sporRMS_OA_E8_field_neg05;
	
	std::cout << "RMS AO E8 optA: " << sporRMS_OA_E8_optA << "\n";
	std::cout << "RMS AO E8 field -05: " << sporRMS_OA_E8_field_neg05 << "\n";
	std::cout << "radius R1 E8: " << optimizedOptSys_E8.getOptSysOptimized_LLT().getPosAndInteractingSurface().at(1).getSurfaceInterRay_ptr()->getRadius() << std::endl;
	
	std::cout << "Point image surface (plane5_E8): " << optimizedOptSys_Ele_E8.getPosAndIntersection_LLT().at(5).getSurfaceInterRay_ptr()->getPoint().getZ();
	
	bool checkPositionApertureStopE8 = optimizedOptSys_Ele_E8.getPosAndElement().at(0).getElementInOptSys_ptr()->getPointElementValue_Z() == 10.0;
	bool checkPositionSphere1E8 = optimizedOptSys_Ele_E8.getPosAndElement().at(1).getElementInOptSys_ptr()->getPointElementValue_Z() == 15.0;
	bool checkPositionSphere2E8 = optimizedOptSys_Ele_E8.getPosAndElement().at(2).getElementInOptSys_ptr()->getPointElementValue_Z() == 20.0;
	bool checkPositionSphere3E8 = optimizedOptSys_Ele_E8.getPosAndElement().at(3).getElementInOptSys_ptr()->getPointElementValue_Z() == 25.0;
	bool checkPositionSphere4E8 = optimizedOptSys_Ele_E8.getPosAndElement().at(4).getElementInOptSys_ptr()->getPointElementValue_Z() == 30.0;
	
	bool checkE8_RMS_better = GLOW_Sum_E8 - zemaxSum_E8 < 1.0;
	
	workTheOptimizer.push_back(checkPositionApertureStopE8);
	workTheOptimizer.push_back(checkPositionSphere1E8);
	workTheOptimizer.push_back(checkPositionSphere2E8);
	workTheOptimizer.push_back(checkPositionSphere3E8);
	workTheOptimizer.push_back(checkPositionSphere4E8);
	
	
	workTheOptimizer.push_back(checkE8_RMS_better);
	
	//SYSTEM E8 END//////////////////////////////////////////////////////////////////////////////////
	
	//SYSTEM E9////////////////////////////////////////////////////////////////////////////////////
	// set the wavelength
	Light_LLT Light_E9_XX;
	Light_E9_XX.setWavelength(550.0);
	Light_E9_XX.setIntensity(1.0);
	std::vector<Light_LLT> lichtVecE9{ Light_E9_XX };
	
	// surfaces E9
	ApertureStopElement AperStop0_E9(/* semi height*/1.0, /*point*/{ 0.0,0.0,10.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glass1);
	SphericalElement Sphere1_E9(/*radius*/ 10.0, /*semi height*/ 3.0, /*point*/{ 0.0,0.0,15.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glass1, /*refractive index B*/glass15);
	SphericalElement Sphere2_E9(/*radius*/ 10.0, /*semi height*/ 3.0, /*point*/{ 0.0,0.0,20.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glass1, /*refractive index B*/glass15);
	SphericalElement Sphere3_E9(/*radius*/ 5.0, /*semi height*/ 3.0, /*point*/{ 0.0,0.0,25.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glass1, /*refractive index B*/glass15);
	SphericalElement Sphere4_E9(/*radius*/ 5.0, /*semi height*/ 3.0, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glass1, /*refractive index B*/glass15);
	PlanElement Plan5_E9(/*semi height*/ 10.0, /*point*/{ 0.0,0.0,35.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glass1, /*refractive index B*/ glass1);
	
	//	// set the radius variable
	Sphere3_E9.setParameterPointZ(30.0, 40.0, 0.0, typeModifierVariable);
	// set the position of the spherical surface (4) variable
	Plan5_E9.setParameterPointZ(35.0, 45.0, 0.0, typeModifierVariable);
	
	surfacePtr AperStop0_E9_ptr = AperStop0_E9.clone();
	surfacePtr Sphere1_E9_ptr = Sphere1_E9.clone();
	surfacePtr Sphere2_E9_ptr = Sphere2_E9.clone();
	surfacePtr Sphere3_E9_ptr = Sphere3_E9.clone();
	surfacePtr Sphere4_E9_ptr = Sphere4_E9.clone();
	surfacePtr Plan5_E9_ptr = Plan5_E9.clone();
	
	std::vector<surfacePtr> opticalSystemE9_ptr{AperStop0_E9_ptr, Sphere1_E9_ptr, Sphere2_E9_ptr, Sphere3_E9_ptr, Sphere4_E9_ptr, Plan5_E9_ptr };
	std::vector<interactionPtr> interactionsE9_ptr{ doNothing.clone(),refrac.clone(), refrac.clone(), refrac.clone(), refrac.clone(), absorb.clone() };
	
	//	//// build optical system
	OpticalSystemElement optSystemElement_E9(opticalSystemE9_ptr, interactionsE9_ptr);
	
	// trace the ray thow the optical system
	SequentialRayTracing seqTrace_E9_optA(/*optical system element*/ optSystemElement_E9, /*start point lightRay*/{ 0.0,0.0,0.0 }, /*rings*/ 6, /*arms*/ 8, /*refractive index*/ 1.0, lichtVecE9);
	
		// calculate rms value
	Spot spot_E9_optA(seqTrace_E9_optA.getAllInterPointsAtSurf_i_notFiltered(5), seqTrace_E9_optA.getAllInterPointsAtSurf_i_notFiltered(5).at(0));
	real rms_E9_optA = spot_E9_optA.getRMS_µm();
	std::cout << "Organic RMS optA E9: " << rms_E9_optA << "\n";
	workTheOptimizer.push_back(std::abs(rms_E9_optA - 497.099) < 1.0);
	
	//	// next we start the optimasation
	std::cout << "start of the optimizer example E9 \n";
	// population of the optimasation process
	unsigned int population_E9 = 1000;
	
	// stadt the optim
	localStart localOp_E9 = positionStart;
	/*mutation factor*/
	real mutarionFactor_E9 = 0.1;
	
	OptimizeOpticalSystem optimizedOptSys_E9(optSystemElement_E9, population_E9, mutarionFactor_E9, localOp_E9);
	
	// set rings and arms for the optimasation
	optimizedOptSys_E9.setRings_optimizer(6);
	optimizedOptSys_E9.setArms_optimizer(8);
	// *********************************
	// start optimasation of example E92
	optimizedOptSys_E9.optimizeSUPERFUNCTION();
	// *********************************
	// get the optimized optical system
	OpticalSystemElement optimizedOptSys_Ele_E9 = optimizedOptSys_E9.getOptSysOptimized_Ele();
	
	//	// trace the ray thow the optical system
	SequentialRayTracing seqTrace_E9_optA_AO(/*optical system element*/ optimizedOptSys_Ele_E9, /*start point lightRay*/{ 0.0,0.0,0.0 }, /*rings*/ 6, /*arms*/ 8, /*refractive index*/ 1.0, lichtVecE9);
	Spot SpotOptA_AO_E9_optA(seqTrace_E9_optA_AO.getAllInterPointsAtSurf_i_notFiltered(5), seqTrace_E9_optA_AO.getAllInterPointsAtSurf_i_notFiltered(5).at(0));
	real sporRMS_OA_E9_optA = SpotOptA_AO_E9_optA.getRMS_µm();
	real spotZemaxOA_E9_optA = 9.779;
	
	real PointZ_S0_E9 = optimizedOptSys_Ele_E9.getPosAndElement().at(0).getElementInOptSys_ptr()->getPointElementValue_Z();
	real PointZ_S1_E9 = optimizedOptSys_Ele_E9.getPosAndElement().at(1).getElementInOptSys_ptr()->getPointElementValue_Z();
	real PointZ_S2_E9 = optimizedOptSys_Ele_E9.getPosAndElement().at(2).getElementInOptSys_ptr()->getPointElementValue_Z();
	real PointZ_S3_E9 = optimizedOptSys_Ele_E9.getPosAndElement().at(3).getElementInOptSys_ptr()->getPointElementValue_Z();
	real PointZ_S4_E9 = optimizedOptSys_Ele_E9.getPosAndElement().at(4).getElementInOptSys_ptr()->getPointElementValue_Z();
	real PointZ_S5_E9 = optimizedOptSys_Ele_E9.getPosAndElement().at(5).getElementInOptSys_ptr()->getPointElementValue_Z();
	
	real distaneS0_S1_E9 = PointZ_S1_E9 - PointZ_S0_E9;
	real distaneS1_S2_E9 = PointZ_S2_E9 - PointZ_S1_E9;
	real distaneS2_S3_E9 = PointZ_S3_E9 - PointZ_S2_E9;
	real distaneS3_S4_E9 = PointZ_S4_E9 - PointZ_S3_E9;
	real distaneS4_S5_E9 = PointZ_S5_E9 - PointZ_S4_E9;
	
	std::cout << "RMS AO E9 optA: " << sporRMS_OA_E9_optA << "\n";
	std::cout << "Point S3 : " << optimizedOptSys_Ele_E9.getPosAndElement().at(3).getElementInOptSys_ptr()->getPointElementValue_Z() << "\n";
	std::cout << "Point S4 : " << optimizedOptSys_Ele_E9.getPosAndElement().at(4).getElementInOptSys_ptr()->getPointElementValue_Z() << "\n";
	std::cout << "Point image surface (plane5_E9): " << optimizedOptSys_Ele_E9.getPosAndElement().at(5).getElementInOptSys_ptr()->getPointElementValue_Z() << "\n";
	
	bool checkPositionApertureStopE9 = optimizedOptSys_Ele_E9.getPosAndElement().at(0).getElementInOptSys_ptr()->getPointElementValue_Z() == 10.0;
	bool checkPositionSphere1E9 = optimizedOptSys_Ele_E9.getPosAndElement().at(1).getElementInOptSys_ptr()->getPointElementValue_Z() == 15.0;
	bool checkPositionSphere2E9 = optimizedOptSys_Ele_E9.getPosAndElement().at(2).getElementInOptSys_ptr()->getPointElementValue_Z() == 20.0;
	bool checkPositionSphere3E9 = optimizedOptSys_Ele_E9.getPosAndElement().at(3).getElementInOptSys_ptr()->getPointElementValue_Z() != 25.0;
	bool checkPositionSphere4E9 = optimizedOptSys_Ele_E9.getPosAndElement().at(4).getElementInOptSys_ptr()->getPointElementValue_Z() != 30.0;
	bool checkPositionSphere5E9 = optimizedOptSys_Ele_E9.getPosAndElement().at(5).getElementInOptSys_ptr()->getPointElementValue_Z() != 35.0;
	
	bool checkDistanceS3S4 = std::abs(distaneS3_S4_E9 - 5.0) < toleranceDistance;
	
	workTheOptimizer.push_back(checkPositionApertureStopE9);
	workTheOptimizer.push_back(checkPositionSphere1E9);
	workTheOptimizer.push_back(checkPositionSphere2E9);
	workTheOptimizer.push_back(checkPositionSphere3E9);
	workTheOptimizer.push_back(checkPositionSphere4E9);
	workTheOptimizer.push_back(checkPositionSphere5E9);
	workTheOptimizer.push_back(checkDistanceS3S4);
	
	bool checkE9_RMS_better = sporRMS_OA_E9_optA - spotZemaxOA_E9_optA < 0.0;
	workTheOptimizer.push_back(checkE9_RMS_better);
	
	
	//SYSTEM E9 END//////////////////////////////////////////////////////////////////////////////////


	//SYSTEM E10////////////////////////////////////////////////////////////////////////////////////
	// set the wavelength
	Light_LLT Light_E10;
	Light_E10.setWavelength(550.0);
	Light_E10.setIntensity(1.0);
	std::vector<Light_LLT> lichtVecE10{ Light_E10 };

	// surfaces E10
	ApertureStopElement AperStop0_E10(/* semi height*/1.0, /*point*/{ 0.0,0.0,10.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glass1);
	SphericalElement Sphere1_E10(/*radius*/ 10.0, /*semi height*/ 3.0, /*point*/{ 0.0,0.0,15.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glass1, /*refractive index B*/glass15);
	SphericalElement Sphere2_E10(/*radius*/ 10.0, /*semi height*/ 3.0, /*point*/{ 0.0,0.0,20.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glass1, /*refractive index B*/glass15);
	SphericalElement Sphere3_E10(/*radius*/ 10.0, /*semi height*/ 3.0, /*point*/{ 0.0,0.0,25.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glass15, /*refractive index B*/glass1);
	SphericalElement Sphere4_E10(/*radius*/ 10.0, /*semi height*/ 3.0, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glass15, /*refractive index B*/glass1);
	SphericalElement Sphere5_E10(/*radius*/ 10.0, /*semi height*/ 3.0, /*point*/{ 0.0,0.0,35.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glass1, /*refractive index B*/glass15);
	SphericalElement Sphere6_E10(/*radius*/ 10.0, /*semi height*/ 3.0, /*point*/{ 0.0,0.0,40.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glass1, /*refractive index B*/glass15);
	PlanElement Plan7_E10(/*semi height*/ 3.0, /*point*/{ 0.0,0.0,50.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glass1, /*refractive index B*/ glass1);

	Sphere3_E10.setParameterPointZ(25.0, 40.0, 0.0, typeModifierVariable);
	Sphere4_E10.setParameterPointZ(25.0, 40.0, 0.0, typeModifierVariable);
	Plan7_E10.setParameterPointZ(50.0, 60.0, 0.0, typeModifierVariable);

	surfacePtr AperStop0_E10_ptr = AperStop0_E10.clone();
	surfacePtr Sphere1_E10_ptr = Sphere1_E10.clone();
	surfacePtr Sphere2_E10_ptr = Sphere2_E10.clone();
	surfacePtr Sphere3_E10_ptr = Sphere3_E10.clone();
	surfacePtr Sphere4_E10_ptr = Sphere4_E10.clone();
	surfacePtr Sphere5_E10_ptr = Sphere5_E10.clone();
	surfacePtr Sphere6_E10_ptr = Sphere6_E10.clone();
	surfacePtr Plan7_E10_ptr = Plan7_E10.clone();

	std::vector<surfacePtr> opticalSystemE10_ptr{ AperStop0_E10_ptr, Sphere1_E10_ptr, Sphere2_E10_ptr, Sphere3_E10_ptr, Sphere4_E10_ptr, Sphere5_E10_ptr, Sphere6_E10_ptr, Plan7_E10_ptr }; 
	std::vector<interactionPtr> interactionsE10_ptr{ doNothing.clone(),refrac.clone(), refrac.clone(), refrac.clone(), refrac.clone(), refrac.clone(), refrac.clone(), absorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement_E10(opticalSystemE10_ptr, interactionsE10_ptr);

	// trace the ray thow the optical system
	SequentialRayTracing seqTrace_E10_optA(/*optical system element*/ optSystemElement_E10, /*start point lightRay*/{ 0.0,0.0,0.0 }, /*rings*/ 6, /*arms*/ 8, /*refractive index*/ 1.0, lichtVecE10);

	// calculate rms value
	Spot spot_E10_optA(seqTrace_E10_optA.getAllInterPointsAndIntensityAtSurface_i(7), seqTrace_E10_optA.getAllInterPointsAtSurf_i_notFiltered(7).at(0));

	real rms_E10_optA = spot_E10_optA.getRMS_µm();
	std::cout << "Organic RMS optA E10: " << rms_E10_optA << "\n";
	workTheOptimizer.push_back(std::abs(rms_E10_optA - 525.687) < 1.0);

	//	// next we start the optimasation
	std::cout << "start of the optimizer example E10 \n";
	// population of the optimasation process
	unsigned int population_E10 = 1000;

	// stadt the optim
	localStart localOp_E10 = positionStart;
	/*mutation factor*/
	real mutarionFactor_E10 = 0.01;

	OptimizeOpticalSystem optimizedOptSys_E10(optSystemElement_E10, population_E10, mutarionFactor_E10, localOp_E10);

	// set rings and arms for the optimasation
	optimizedOptSys_E10.add_FieldAndWeight({ 0.0,0.5,0.0 }, 1.0);
	// *********************************
	// start optimasation of example E102
	optimizedOptSys_E10.optimizeSUPERFUNCTION();
	// *********************************
	// get the optimized optical system
	OpticalSystemElement optimizedOptSys_Ele_E10 = optimizedOptSys_E10.getOptSysOptimized_Ele();

	//	// trace the ray thow the optical system
	SequentialRayTracing seqTrace_E10_optA_AO(/*optical system element*/ optimizedOptSys_Ele_E10, /*start point lightRay*/{ 0.0,0.0,0.0 }, /*rings*/ 6, /*arms*/ 8, /*refractive index*/ 1.0, Light_E10);
	Spot SpotOptA_AO_E10_optA(seqTrace_E10_optA_AO.getAllInterPointsAtSurf_i_notFiltered(7), seqTrace_E10_optA_AO.getAllInterPointsAtSurf_i_notFiltered(7).at(0));
	real sporRMS_OA_E10_optA = SpotOptA_AO_E10_optA.getRMS_µm();
	real spotZemaxOA_E10_optA = 22.925;

	//	// trace the ray thow the optical system
	SequentialRayTracing seqTrace_E10_field05_AO(/*optical system element*/ optimizedOptSys_Ele_E10, /*start point lightRay*/{ 0.0,0.5,0.0 }, /*rings*/ 6, /*arms*/ 8, /*refractive index*/ 1.0, Light_E10);
	Spot SpotOptA_AO_E10_field05(seqTrace_E10_field05_AO.getAllInterPointsAtSurf_i_notFiltered(7), seqTrace_E10_field05_AO.getAllInterPointsAtSurf_i_notFiltered(7).at(0));
	real sporRMS_OA_E10_field05 = SpotOptA_AO_E10_field05.getRMS_µm();
	real spotZemaxOA_E10_field05 = 53.937;

	real spotZemaxSum_E10 = spotZemaxOA_E10_optA + spotZemaxOA_E10_field05;
	real spotGLOWSum_E10 = sporRMS_OA_E10_optA + sporRMS_OA_E10_field05;

	// check if GLOW is better than Zemax
	bool checkE10_RMS_better = spotGLOWSum_E10 - spotZemaxSum_E10 < 0.0;
	workTheOptimizer.push_back(checkE10_RMS_better);

	real PointZ_S0_E10 = optimizedOptSys_Ele_E10.getPosAndElement().at(0).getElementInOptSys_ptr()->getPointElementValue_Z();
	real PointZ_S1_E10 = optimizedOptSys_Ele_E10.getPosAndElement().at(1).getElementInOptSys_ptr()->getPointElementValue_Z();
	real PointZ_S2_E10 = optimizedOptSys_Ele_E10.getPosAndElement().at(2).getElementInOptSys_ptr()->getPointElementValue_Z();
	real PointZ_S3_E10 = optimizedOptSys_Ele_E10.getPosAndElement().at(3).getElementInOptSys_ptr()->getPointElementValue_Z();
	real PointZ_S4_E10 = optimizedOptSys_Ele_E10.getPosAndElement().at(4).getElementInOptSys_ptr()->getPointElementValue_Z();
	real PointZ_S5_E10 = optimizedOptSys_Ele_E10.getPosAndElement().at(5).getElementInOptSys_ptr()->getPointElementValue_Z();
	real PointZ_S6_E10 = optimizedOptSys_Ele_E10.getPosAndElement().at(6).getElementInOptSys_ptr()->getPointElementValue_Z();
	real PointZ_S7_E10 = optimizedOptSys_Ele_E10.getPosAndElement().at(7).getElementInOptSys_ptr()->getPointElementValue_Z();

	real distaneS0_S1_E10 = PointZ_S1_E10 - PointZ_S0_E10;
	real distaneS1_S2_E10 = PointZ_S2_E10 - PointZ_S1_E10;
	real distaneS2_S3_E10 = PointZ_S3_E10 - PointZ_S2_E10;
	real distaneS3_S4_E10 = PointZ_S4_E10 - PointZ_S3_E10;
	real distaneS4_S5_E10 = PointZ_S5_E10 - PointZ_S4_E10;
	real distaneS5_S6_E10 = PointZ_S6_E10 - PointZ_S5_E10;
 	real distaneS6_S7_E10 = PointZ_S7_E10 - PointZ_S6_E10;

	std::cout << "RMS AO E10 optA: " << sporRMS_OA_E10_optA << "\n";
	std::cout << "RMS AO E10 field05: " << sporRMS_OA_E10_field05 << "\n";
	std::cout << "sum RMS" << sporRMS_OA_E10_optA + sporRMS_OA_E10_field05 << std::endl;
	std::cout << "Point S3 : " << optimizedOptSys_Ele_E10.getPosAndElement().at(3).getElementInOptSys_ptr()->getPointElementValue_Z() << "\n";
	std::cout << "Point S4 : " << optimizedOptSys_Ele_E10.getPosAndElement().at(4).getElementInOptSys_ptr()->getPointElementValue_Z() << "\n";
	std::cout << "Point image surface (plane7_E10): " << optimizedOptSys_Ele_E10.getPosAndElement().at(7).getElementInOptSys_ptr()->getPointElementValue_Z() << "\n";

	bool checkPosApertureStop = optimizedOptSys_Ele_E10.getPosAndElement().at(0).getElementInOptSys_ptr()->getPointElementValue_Z() == 10.0;
	bool checkDistaneS0_S1 = distaneS0_S1_E10 == 5.0;
	bool checkDistaneS1_S2 = distaneS1_S2_E10 == 5.0;
	bool checkDistaneS2_S3 = distaneS2_S3_E10 != 5.0;
	std::cout << "dis23: " << distaneS2_S3_E10 << std::endl;
	bool checkDistaneS3_S4 = distaneS3_S4_E10 != 5.0;
	std::cout << "dis34 :" << distaneS3_S4_E10 << std::endl;
	bool checkDistaneS4_S5 = distaneS4_S5_E10 == 5.0;
	bool checkDistaneS5_S6 = distaneS5_S6_E10 == 5.0;
	bool checkDistaneS6_S7 = distaneS6_S7_E10 != 10.0;
	std::cout << "dis67: " << distaneS6_S7_E10 << std::endl;

	workTheOptimizer.push_back(checkPosApertureStop);
	workTheOptimizer.push_back(checkDistaneS0_S1);
	workTheOptimizer.push_back(checkDistaneS1_S2);
	workTheOptimizer.push_back(checkDistaneS2_S3);
	workTheOptimizer.push_back(checkDistaneS3_S4);
	workTheOptimizer.push_back(checkDistaneS4_S5);
	workTheOptimizer.push_back(checkDistaneS6_S7);
	

	//SYSTEM E10 END//////////////////////////////////////////////////////////////////////////////////

	//SYSTEM E11 ///////////////////////////////////////////////////////////////////////////////////
	// set the wavelength
	Light_LLT Light_E11;
	Light_E11.setWavelength(550.0);
	Light_E11.setIntensity(1.0);
	std::vector<Light_LLT> lichtVecE11{ Light_E11 };

	// surfaces E11
	ApertureStopElement AperStop0_E11(/* semi height*/1.0, /*point*/{ 0.0,0.0,10.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glass1);
	SphericalElement Sphere1_E11(/*radius*/ 10.0, /*semi height*/ 3.0, /*point*/{ 0.0,0.0,15.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glass1, /*refractive index B*/glass15);
	SphericalElement Sphere2_E11(/*radius*/ 10.0, /*semi height*/ 3.0, /*point*/{ 0.0,0.0,20.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glass15, /*refractive index B*/glass16);
	SphericalElement Sphere3_E11(/*radius*/ 10.0, /*semi height*/ 3.0, /*point*/{ 0.0,0.0,25.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glass15, /*refractive index B*/glass16);
	SphericalElement Sphere4_E11(/*radius*/ 10.0, /*semi height*/ 3.0, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glass15, /*refractive index B*/glass16);
	SphericalElement Sphere5_E11(/*radius*/ 10.0, /*semi height*/ 3.0, /*point*/{ 0.0,0.0,35.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glass15, /*refractive index B*/glass16);
	SphericalElement Sphere6_E11(/*radius*/ 10.0, /*semi height*/ 3.0, /*point*/{ 0.0,0.0,40.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glass1, /*refractive index B*/glass15);
	PlanElement Plan7_E11(/*semi height*/ 3.0, /*point*/{ 0.0,0.0,47.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glass1, /*refractive index B*/ glass1);

	Sphere1_E11.setParameterRadius(5.0, 15.0, 0.0, typeModifierVariable);
	Sphere2_E11.setParameterRadius(5.0, 15.0, 0.0, typeModifierVariable);
	Sphere3_E11.setParameterRadius(5.0, 15.0, 0.0, typeModifierVariable);
	Sphere4_E11.setParameterRadius(5.0, 15.0, 0.0, typeModifierVariable);
	Sphere5_E11.setParameterRadius(5.0, 15.0, 0.0, typeModifierVariable);
	Sphere6_E11.setParameterRadius(5.0, 15.0, 0.0, typeModifierVariable);

	surfacePtr AperStop0_E11_ptr = AperStop0_E11.clone();
	surfacePtr Sphere1_E11_ptr = Sphere1_E11.clone();
	surfacePtr Sphere2_E11_ptr = Sphere2_E11.clone();
	surfacePtr Sphere3_E11_ptr = Sphere3_E11.clone();
	surfacePtr Sphere4_E11_ptr = Sphere4_E11.clone();
	surfacePtr Sphere5_E11_ptr = Sphere5_E11.clone();
	surfacePtr Sphere6_E11_ptr = Sphere6_E11.clone();
	surfacePtr Plan7_E11_ptr = Plan7_E11.clone();

	std::vector<surfacePtr> opticalSystemE11_ptr{ AperStop0_E11_ptr, Sphere1_E11_ptr, Sphere2_E11_ptr, Sphere3_E11_ptr, Sphere4_E11_ptr, Sphere5_E11_ptr, Sphere6_E11_ptr, Plan7_E11_ptr };
	std::vector<interactionPtr> interactionsE11_ptr{ doNothing.clone(),refrac.clone(), refrac.clone(), refrac.clone(), refrac.clone(), refrac.clone(), refrac.clone(), absorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement_E11(opticalSystemE11_ptr, interactionsE11_ptr);

	// trace the ray thow the optical system
	SequentialRayTracing seqTrace_E11_optA(/*optical system element*/ optSystemElement_E11, /*start point lightRay*/{ 0.0,0.0,0.0 }, /*rings*/ 6, /*arms*/ 8, /*refractive index*/ 1.0, lichtVecE11);

	// calculate rms value
	Spot spot_E11_optA(seqTrace_E11_optA.getAllInterPointsAndIntensityAtSurface_i(7), seqTrace_E11_optA.getAllInterPointsAtSurf_i_notFiltered(7).at(0));
	real rms_E11_optA = spot_E11_optA.getRMS_µm();
	std::cout << "Organic RMS optA E11: " << rms_E11_optA << "\n";
	workTheOptimizer.push_back(std::abs(rms_E11_optA - 445.130) < 1.0);

	//	// next we start the optimasation
	std::cout << "start of the optimizer example E11 \n";
	// population of the optimasation process
	unsigned int population_E11 = 3000;

	// stadt the optim
	localStart localOp_E11 = radiusStart;
	/*mutation factor*/
	real mutarionFactor_E11 = 0.01;

	OptimizeOpticalSystem optimizedOptSys_E11(optSystemElement_E11, population_E11, mutarionFactor_E11, localOp_E11);

	// set rings and arms for the optimasation
	optimizedOptSys_E11.add_FieldAndWeight({ 0.0,1.0,0.0 }, 1.0);
	//optimizedOptSys_E11.add
	// *********************************
	// start optimasation of example E112
	optimizedOptSys_E11.optimizeSUPERFUNCTION();
	// *********************************
	// get the optimized optical system
	OpticalSystemElement optimizedOptSys_Ele_E11 = optimizedOptSys_E11.getOptSysOptimized_Ele();

	// trace the ray thow the optical system
	SequentialRayTracing seqTrace_E11_optA_AO(/*optical system element*/ optimizedOptSys_Ele_E11, /*start point lightRay*/{ 0.0,0.0,0.0 }, /*rings*/ 6, /*arms*/ 8, /*refractive index*/ 1.0, Light_E11);
	Spot SpotOptA_AO_E11_optA(seqTrace_E11_optA_AO.getAllInterPointsAtSurf_i_notFiltered(7), seqTrace_E11_optA_AO.getAllInterPointsAtSurf_i_notFiltered(7).at(0));
	real sporRMS_OA_E11_optA = SpotOptA_AO_E11_optA.getRMS_µm();
	real spotZemaxOA_E11_optA = 26.884;

	// trace the ray thow the optical system
	SequentialRayTracing seqTrace_E11_field05_AO(/*optical system element*/ optimizedOptSys_Ele_E11, /*start point lightRay*/{ 0.0,1.0,0.0 }, /*rings*/ 6, /*arms*/ 8, /*refractive index*/ 1.0, Light_E11);
	Spot SpotOptA_AO_E11_field1(seqTrace_E11_field05_AO.getAllInterPointsAtSurf_i_notFiltered(7), seqTrace_E11_field05_AO.getAllInterPointsAtSurf_i_notFiltered(7).at(0));
	real sporRMS_OA_E11_field1 = SpotOptA_AO_E11_field1.getRMS_µm();
	real spotZemaxOA_E11_field1 = 89.610;

	real spotZemaxSum_E11 = spotZemaxOA_E11_optA + spotZemaxOA_E11_field1;
	real spotGLOWSum_E11 = sporRMS_OA_E11_optA + sporRMS_OA_E11_field1;

	std::cout << "RMS optA GLOW E11: " << sporRMS_OA_E11_optA << std::endl;
	std::cout << "RMS field1 GLOW E11: " << sporRMS_OA_E11_field1 << std::endl;
	std::cout << "sum GLOW Example E11: " << spotGLOWSum_E11 << std::endl;

	std::cout << "E11 R1: " << optimizedOptSys_Ele_E11.getPosAndIntersection_LLT().at(1).getSurfaceInterRay_ptr()->getRadius() << std::endl;
	std::cout << "E11 R2: " << optimizedOptSys_Ele_E11.getPosAndIntersection_LLT().at(2).getSurfaceInterRay_ptr()->getRadius() << std::endl;
	std::cout << "E11 R3: " << optimizedOptSys_Ele_E11.getPosAndIntersection_LLT().at(3).getSurfaceInterRay_ptr()->getRadius() << std::endl;
	std::cout << "E11 R4: " << optimizedOptSys_Ele_E11.getPosAndIntersection_LLT().at(4).getSurfaceInterRay_ptr()->getRadius() << std::endl;
	std::cout << "E11 R5: " << optimizedOptSys_Ele_E11.getPosAndIntersection_LLT().at(5).getSurfaceInterRay_ptr()->getRadius() << std::endl;
	std::cout << "E11 R6: " << optimizedOptSys_Ele_E11.getPosAndIntersection_LLT().at(6).getSurfaceInterRay_ptr()->getRadius() << std::endl;

	// check if GLOW is better than Zemax
	bool checkE11_RMS_better = spotGLOWSum_E11 - spotZemaxSum_E11 < 0.0;
	workTheOptimizer.push_back(checkE11_RMS_better);

	//SYSTEM E11 END//////////////////////////////////////////////////////////////////////////////////

	//SYSTEM E12////////////////////////////////////////////////////////////////////////////////////
	// set the wavelength
	Light_LLT Light_E12;
	Light_E12.setWavelength(550.0);
	Light_E12.setIntensity(1.0);
	std::vector<Light_LLT> lichtVecE12{ Light_E12 };
	
	// surfaces E12
	ApertureStopElement Apertur0_E12(1.0, { 0.0,0.0,20.0 }, { 0.0,0.0,1.0 }, glass1);
	SphericalElement Sphere1_E12(40.0, 5.0, { 0.0,0.0,25.0 }, { 0.0,0.0,1.0 }, glass1, glass15);
	SphericalElement Sphere2_E12(40.0, 5.0, { 0.0,0.0,35.0 }, { 0.0,0.0,-1.0 }, glass1, glass15);
	SphericalElement Sphere3_E12(50.0, 5.0, { 0.0,0.0,45.0 }, { 0.0,0.0,1.0 }, glass1, glass16);
	SphericalElement Sphere4_E12(40.0, 5.0, { 0.0,0.0,55.0 }, { 0.0,0.0,-1.0 }, glass1, glass16);
	SphericalElement Sphere5_E12(30.0, 5.0, { 0.0,0.0,65.0 }, { 0.0,0.0,1.0 }, glass1, glass15);
	SphericalElement Sphere6_E12(50.0, 5.0, { 0.0,0.0,75.0 }, { 0.0,0.0,-1.0 }, glass1, glass15);
	PlanElement Plane7_E12(5.0, { 0.0,0.0,85.0 }, { 0.0,0.0,1.0 }, glass1, glass1);
	
	// set the radius variable
	Sphere1_E12.setParameterRadius(20.0, 30.0, 0.0, typeModifierVariable);
	Sphere3_E12.setParameterRadius(40, 60.0, 0, typeModifierVariable);
	Sphere5_E12.setParameterRadius(15.0, 35.0, 0, typeModifierVariable);
	
	surfacePtr AperStop0_E12_ptr = Apertur0_E12.clone();
	surfacePtr Sphere1_E12_ptr = Sphere1_E12.clone();
	surfacePtr Sphere2_E12_ptr = Sphere2_E12.clone();
	surfacePtr Sphere3_E12_ptr = Sphere3_E12.clone();
	surfacePtr Sphere4_E12_ptr = Sphere4_E12.clone();
	surfacePtr Sphere5_E12_ptr = Sphere5_E12.clone();
	surfacePtr Sphere6_E12_ptr = Sphere6_E12.clone();
	surfacePtr Plan7_E12_ptr = Plane7_E12.clone();

	std::vector<surfacePtr> opticalSystemE12_ptr{ AperStop0_E12_ptr, Sphere1_E12_ptr, Sphere2_E12_ptr, Sphere3_E12_ptr, Sphere4_E12_ptr, Sphere5_E12_ptr, Sphere6_E12_ptr, Plan7_E12_ptr };
	std::vector<interactionPtr> interactionsE12_ptr{ refrac.clone(),refrac.clone(), refrac.clone(), refrac.clone(), refrac.clone(), refrac.clone(), refrac.clone(),absorb.clone() };
	
	// build optical system
	OpticalSystemElement optSystemElement_E12(opticalSystemE12_ptr, interactionsE12_ptr);
	
	
		
	// trace the ray thow the optical system
	SequentialRayTracing seqTrace_E12_optA(/*optical system element*/ optSystemElement_E12, /*start point lightRay*/{ 0.0,0.0,0.0 }, /*rings*/ 6, /*arms*/ 8, /*refractive index*/ 1.0, lichtVecE12);
	SequentialRayTracing seqTrace_E12_field1(/*optical system element*/ optSystemElement_E12, /*start point lightRay*/{ 0.0,1.0,0.0 }, /*rings*/ 6, /*arms*/ 8, /*refractive index*/ 1.0, lichtVecE12);
	SequentialRayTracing seqTrace_E12_field2(/*optical system element*/ optSystemElement_E12, /*start point lightRay*/{ 0.0,2.0,0.0 }, /*rings*/ 6, /*arms*/ 8, /*refractive index*/ 1.0, lichtVecE12);


	
	// calculate rms value
	Spot spot_E12_optA(seqTrace_E12_optA.getAllInterPointsAtSurf_i_notFiltered(7), seqTrace_E12_optA.getAllInterPointsAtSurf_i_notFiltered(7).at(0));
	real rms_E12_optA = spot_E12_optA.getRMS_µm();
	bool checkRMSoptA_E12 = Math::compareTwoNumbers_decimals(rms_E12_optA, 299.028, 3);
	workTheOptimizer.push_back(checkRMSoptA_E12);
	std::cout << "Organic RMS optA : " << rms_E12_optA << "\n";
	Spot spot_E12_field1(seqTrace_E12_field1.getAllInterPointsAtSurf_i_notFiltered(7), seqTrace_E12_field1.getAllInterPointsAtSurf_i_notFiltered(7).at(0));
	real rms_E12_field1 = spot_E12_field1.getRMS_µm();
	bool checkRMSfield1_E12 = Math::compareTwoNumbers_decimals(rms_E12_field1, 294.895, 3);
	workTheOptimizer.push_back(checkRMSfield1_E12);
	std::cout << "Organic RMS field1 : " << rms_E12_field1 << "\n";
	Spot spot_E12_field2(seqTrace_E12_field2.getAllInterPointsAtSurf_i_notFiltered(7), seqTrace_E12_field2.getAllInterPointsAtSurf_i_notFiltered(7).at(0));
	real rms_E12_field2 = spot_E12_field2.getRMS_µm();
	bool checkRMSfield2_E12 = Math::compareTwoNumbers_decimals(rms_E12_field2, 282.642, 3);
	workTheOptimizer.push_back(checkRMSfield2_E12);
	std::cout << "Organic RMS field2 : " << rms_E12_field2 << "\n";
	

	// next we start the optimasation
	std::cout << "start of the optimizer\n";
	// population of the optimasation process
	unsigned int population_E12 = 1000;
	
	// stadt the optim
	localStart localOp_E12 = radiusStart;
	// the hole system has a length of 85.0 mm
	real opticalLen_E12 = 85.0;
	/*mutation factor*/
	real mutarionFactor_E12 = 0.01;
	
	OptimizeOpticalSystem optimizedOptSys_E12(optSystemElement_E12, population_E12, mutarionFactor_E12, localOp_E12);

	// field on the optical axis
	//optimized_E12.set_Field({ 0.0,0.0,0.0 }, 1.0);
	// field at y = 1
	int rings = 6;
	optimizedOptSys_E12.add_FieldAndWeight({ 0.0,1.0,0.0 }, 1.0);
	optimizedOptSys_E12.add_FieldAndWeight({ 0.0,2.0,0.0 }, 1.0);
	optimizedOptSys_E12.setCheckAllLocalCombinations_optimizer(true);
	optimizedOptSys_E12.setRings_optimizer(rings);

	// *********************************
	// start optimasation of example E12
	optimizedOptSys_E12.optimizeSUPERFUNCTION();
	// *********************************
	
	OpticalSystemElement optimizedOptSys_Ele_E12 = optimizedOptSys_E12.getOptSysOptimized_Ele();
	SequentialRayTracing seqTrace_optA_AO(/*optical system element*/ optimizedOptSys_Ele_E12, /*start point lightRay*/{ 0.0,0.0,0.0 }, /*rings*/ rings, /*arms*/ 8, /*refractive index*/ 1.0, lichtVecE12);
	SequentialRayTracing seqTrace_field1_AO(/*optical system element*/ optimizedOptSys_Ele_E12, /*start point lightRay*/{ 0.0,1.0,0.0 }, /*rings*/ rings, /*arms*/ 8, /*refractive index*/ 1.0, lichtVecE12);
	SequentialRayTracing seqTrace_field2_AO(/*optical system element*/ optimizedOptSys_Ele_E12, /*start point lightRay*/{ 0.0,2.0,0.0 }, /*rings*/ rings, /*arms*/ 8, /*refractive index*/ 1.0, lichtVecE12);
		
	
	
	Spot Spot_optA_AO_E12(seqTrace_optA_AO.getAllInterPointsAtSurf_i_notFiltered(7), seqTrace_optA_AO.getAllInterPointsAtSurf_i_notFiltered(7).at(0));
	Spot Spot_field1_AO_E12(seqTrace_field1_AO.getAllInterPointsAtSurf_i_notFiltered(7), seqTrace_field1_AO.getAllInterPointsAtSurf_i_notFiltered(7).at(0));
	Spot Spot_field2_AO_E12(seqTrace_field2_AO.getAllInterPointsAtSurf_i_notFiltered(7), seqTrace_field2_AO.getAllInterPointsAtSurf_i_notFiltered(7).at(0));
	
	real spot_optA_E12_AO = Spot_optA_AO_E12.getRMS_µm();
	real spot_field1_E12_AO = Spot_field1_AO_E12.getRMS_µm();
	real spot_field2_E12_AO = Spot_field2_AO_E12.getRMS_µm();
	
	std::cout << "R1: " << optimizedOptSys_Ele_E12.getPosAndIntersection_LLT().at(1).getSurfaceInterRay_ptr()->getRadius() << std::endl;
	std::cout << "R3: " << optimizedOptSys_Ele_E12.getPosAndIntersection_LLT().at(3).getSurfaceInterRay_ptr()->getRadius() << std::endl;
	std::cout << "R5: " << optimizedOptSys_Ele_E12.getPosAndIntersection_LLT().at(5).getSurfaceInterRay_ptr()->getRadius() << std::endl;
	std::cout << "rms opt Achse: " << spot_optA_E12_AO << std::endl;
	std::cout << "field 1: " << spot_field1_E12_AO << std::endl;
	std::cout << "field 2 " << spot_field2_E12_AO << std::endl;
		
	real sumZemaxOpt_E12 = 6.513 + 6.133 + 16.031;
	real sumGLOW_E12 = Spot_optA_AO_E12.getRMS_µm() + Spot_field1_AO_E12.getRMS_µm() + Spot_field2_AO_E12.getRMS_µm();
	std::cout << "GLOW RMS sum E12: " << sumGLOW_E12 << std::endl;

	bool checkE12 = sumGLOW_E12 - sumZemaxOpt_E12 < 0.0;
	workTheOptimizer.push_back(checkE12);

	////END SYSTEM E12////////////////////////////////////////////////////////////////////////////////////
	

	//SYSTEM E13////////////////////////////////////////////////////////////////////////////////////
	
	ApertureStopElement AperSto0_E13(/* semi height*/3.0, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAirZemax());
	SphericalElement Sphere1_E13(/*radius*/ 40.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,35.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAirZemax(), /*refractive index B*/glasses.getBK7_S1());
	SphericalElement Sphere2_E13(/*radius*/ 50.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,45.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getBK7_S1(), /*refractive index B*/glasses.getSF5_S1());
	SphericalElement Sphere3_E13(/*radius*/ 60.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,55.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAirZemax(), /*refractive index B*/glasses.getSF5_S1());
	PlanElement Plan4_E13(/*semi height*/ 99.0, /*point*/{ 0.0,0.0,85.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAirZemax(), /*refractive index B*/ glasses.getAirZemax());

	// set parameter variable
	Sphere1_E13.setParameterRadius(10.0, 40.0, 0.0, typeModifierVariable); // radius of surface Sphere1_E13 is variable
	Sphere2_E13.setParameterRadius(30.0, 60.0, 0.0, typeModifierVariable); // radius of surface Sphere1_E13 is variable
	Sphere3_E13.setParameterRadius(10.0, 40.0, 0.0, typeModifierVariable); // radius of surface Sphere6_E13 is variable

	surfacePtr AperSto0_E13_ptr = AperSto0_E13.clone();
	surfacePtr Sphere1_E13_ptr = Sphere1_E13.clone();
	surfacePtr Sphere2_E13_ptr = Sphere2_E13.clone();
	surfacePtr Sphere3_E13_ptr = Sphere3_E13.clone();
	surfacePtr Plan4_E13_ptr = Plan4_E13.clone();

	std::vector<surfacePtr> opticalSystemE13_ptr{ AperSto0_E13_ptr, Sphere1_E13_ptr, Sphere2_E13_ptr, Sphere3_E13_ptr, Plan4_E13_ptr };
	std::vector<interactionPtr> interactionsE13_ptr{ doNothing.clone(),refrac.clone(), refrac.clone(), refrac.clone(), refrac.clone(), absorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement_E13(opticalSystemE13_ptr, interactionsE13_ptr);

	// trace the ray thow the optical system
	SequentialRayTracing seqTrace_E13_optA(/*optical system element*/ optSystemElement_E13, /*start point lightRay*/{ 0.0,0.0,0.0 }, /*rings*/ 6, /*arms*/ 8, /*refractive index*/ 1.0, lightVecE13);
	SequentialRayTracing seqTrace_E13_field2(/*optical system element*/ optSystemElement_E13, /*start point lightRay*/{ 0.0,2.0,0.0 }, /*rings*/ 6, /*arms*/ 8, /*refractive index*/ 1.0, lightVecE13);
	SequentialRayTracing seqTrace_E13_field4(/*optical system element*/ optSystemElement_E13, /*start point lightRay*/{ 0.0,4.0,0.0 }, /*rings*/ 6, /*arms*/ 8, /*refractive index*/ 1.0, lightVecE13);

	// calculate rms value
	Spot spot_E13_optA(seqTrace_E13_optA.getAllInterPointsAtSurf_i_notFiltered(4), seqTrace_E13_optA.getAllInterPointsAtSurf_i_notFiltered(4).at(0));
	real rms_E13_optA = spot_E13_optA.getRMS_µm();
	bool checkRMSoptA_E13 = Math::compareTwoNumbers_decimals(rms_E13_optA, 3015.10, 2);
	workTheOptimizer.push_back(checkRMSoptA_E13);
	Spot spot_E13_field2(seqTrace_E13_field2.getAllInterPointsAtSurf_i_notFiltered(4), seqTrace_E13_field2.getAllInterPointsAtSurf_i_notFiltered(4).at(0));
	real rms_E13_field2 = spot_E13_field2.getRMS_µm();
	bool checkRMSfield2_E13 = Math::compareTwoNumbers_decimals(rms_E13_field2, 2999.52, 2);
	workTheOptimizer.push_back(checkRMSfield2_E13);
	Spot spot_E13_field4(seqTrace_E13_field4.getAllInterPointsAtSurf_i_notFiltered(4), seqTrace_E13_field4.getAllInterPointsAtSurf_i_notFiltered(4).at(0));
	real rms_E13_field4 = spot_E13_field4.getRMS_µm();
	bool checkRMSfield4_E13 = Math::compareTwoNumbers_decimals(rms_E13_field4, 2953.19, 2);
	workTheOptimizer.push_back(checkRMSfield4_E13);

	localStart localOp_P0 = radiusStart;
	real mutarionFactor_P0 = 0.01;
	real population = 1000;

	optSystemElement_E13.setRefractiveIndexAccordingToWavelength(Light0_E13.getWavelength());
	OptimizeOpticalSystem optimizedOptSys_E13(optSystemElement_E13, population, mutarionFactor_P0, localOp_P0);
	optimizedOptSys_E13.setCheckAllLocalCombinations_optimizer(true);
	optimizedOptSys_E13.add_FieldAndWeight({ 0.0,2.0,0.0 }, 1.0);
	optimizedOptSys_E13.add_FieldAndWeight({ 0.0,4.0,0.0 }, 1.0);
	optimizedOptSys_E13.set_Light(Light0_E13);
	optimizedOptSys_E13.add_Light(Light1_E13);
	optimizedOptSys_E13.add_Light(Light2_E13);

	// start optimtestOptimizerasation of example P0
	optimizedOptSys_E13.optimizeSUPERFUNCTION();
	
	// get the optimized optical system
	OpticalSystemElement optimizedOptSys_Ele_E13 = optimizedOptSys_E13.getOptSysOptimized_Ele();


	// trace the ray thow the optimized optical system
	SequentialRayTracing seqTrace_optA_AO_E13(/*optical system element*/ optimizedOptSys_Ele_E13, /*start point lightRay*/{ 0.0,0.0,0.0 }, /*rings*/ 6, /*arms*/ 8, /*refractive index*/ 1.0, lightVecE13);
	Spot Spot_optA_AO_E13(seqTrace_optA_AO_E13.getAllInterPointsAtSurf_i_notFiltered(4), seqTrace_optA_AO_E13.getAllInterPointsAtSurf_i_notFiltered(4).at(0));
	real sporRMS_optA_AO_E13 = Spot_optA_AO_E13.getRMS_µm();
	std::cout << "GLOW optA E13 rms " << sporRMS_optA_AO_E13 << std::endl;
	real spotZemaxOA_optA_E13 = 77.953;
	std::cout << "ZEMAX optA E13 rms: " << spotZemaxOA_optA_E13 << std::endl;
	
	SequentialRayTracing seqTrace_field2_AO_E13(/*optical system element*/ optimizedOptSys_Ele_E13, /*start point lightRay*/{ 0.0,2.0,0.0 }, /*rings*/ 6, /*arms*/ 8, /*refractive index*/ 1.0, lightVecE13);
	Spot Spot_field2_AO_E13(seqTrace_field2_AO_E13.getAllInterPointsAtSurf_i_notFiltered(4), seqTrace_field2_AO_E13.getAllInterPointsAtSurf_i_notFiltered(4).at(0));
	real sporRMS_field2_AO_E13 = Spot_field2_AO_E13.getRMS_µm();
	std::cout << "GLOW field2 E13 rms " << sporRMS_field2_AO_E13 << std::endl;
	real spotZemaxOA_field2_E13 = 108.084;
	std::cout << "ZEMAX field2 E13 rms: " << spotZemaxOA_field2_E13 << std::endl;

	SequentialRayTracing seqTrace_field4_AO_E13(/*optical system element*/ optimizedOptSys_Ele_E13, /*start point lightRay*/{ 0.0,4.0,0.0 }, /*rings*/ 6, /*arms*/ 8, /*refractive index*/ 1.0, lightVecE13);
	Spot Spot_field4_AO_E13(seqTrace_field4_AO_E13.getAllInterPointsAtSurf_i_notFiltered(4), seqTrace_field4_AO_E13.getAllInterPointsAtSurf_i_notFiltered(4).at(0));
	real sporRMS_field4_AO_E13 = Spot_field4_AO_E13.getRMS_µm();
	std::cout << "GLOW field4 E13 rms " << sporRMS_field4_AO_E13 << std::endl;
	real spotZemaxOA_field4_E13 = 190.617;
	std::cout << "ZEMAX field4 E13 rms " << spotZemaxOA_field4_E13 << std::endl;

	real zemaxSum = spotZemaxOA_optA_E13 + spotZemaxOA_field2_E13 + spotZemaxOA_field4_E13;
	std::cout << "zemax sum E13 rms " << zemaxSum << std::endl;
	real GLOWsumE13 = sporRMS_optA_AO_E13 + sporRMS_field2_AO_E13 + sporRMS_field4_AO_E13;
	std::cout << "GLOW sum E13 rms " << GLOWsumE13 << std::endl;

	bool checkGLOWsumBetterZemaxSumE13 = GLOWsumE13 - zemaxSum < 0.0;
	workTheOptimizer.push_back(checkGLOWsumBetterZemaxSumE13);

	// get the radiuses
	real radiusS1 = optimizedOptSys_Ele_E13.getOpticalSystemElement().getPosAndElement().at(1).getElementInOptSys_ptr()->getRadiusElementValue();
	std::cout << "radius S1: " << radiusS1 << std::endl;
	real radiusS2 = optimizedOptSys_Ele_E13.getOpticalSystemElement().getPosAndElement().at(2).getElementInOptSys_ptr()->getRadiusElementValue();
	std::cout << "radius S2: " << radiusS2 << std::endl;
	real radiusS3 = optimizedOptSys_Ele_E13.getOpticalSystemElement().getPosAndElement().at(3).getElementInOptSys_ptr()->getRadiusElementValue();
	std::cout << "radius S3: " << radiusS3 << std::endl;


	bool checkTheOptimizer = Math::checkTrueOfVectorElements(workTheOptimizer);


	return checkTheOptimizer;
}
