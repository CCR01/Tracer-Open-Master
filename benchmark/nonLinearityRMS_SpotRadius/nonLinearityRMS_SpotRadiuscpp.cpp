#include "nonLinearityRMS_SpotRadius.h"


// include surfaces
#include "..\..\SurfaceElements\SphericalElement.h"
#include "..\..\SurfaceElements\PlanElement.h"
#include "..\..\SurfaceElements\ApertureStopElement.h"

// include interactions
#include "..\..\LowLevelTracing\Interaction\RefractedRay_LLT.h"
#include "..\..\LowLevelTracing\Interaction\DoNothingInteraction_LLT.h"
#include "..\..\LowLevelTracing\Interaction\Absorb_LLT.h"

// include the glas cataloge
#include "..\..\Glasses\Glasses.h"

// include to export data
#include "..\..\Inport_Export_Data\Inport_Export_Data.h"


nonLinearityRMS_SpotRadius::nonLinearityRMS_SpotRadius(){}

nonLinearityRMS_SpotRadius::~nonLinearityRMS_SpotRadius(){}

bool nonLinearityRMS_SpotRadius::showNonLinearityRMS_SpotRadius(double minRadius, double maxRadius, double steps, std::string nameToSave)
{
	// location to save data in csv
	std::string location = "../benchmark/nonLinearityRMS_SpotRadius/";

	typedef std::shared_ptr< Element_CR > surfacePtr;
	typedef std::shared_ptr< InteractionRay_LLT > interactionPtr;
	std::vector<bool> workNonLin;

	// interactions 
	RefractedRay_LLT refrac;
	Absorb_LLT absorb;
	DoNothingInteraction_LLT doNothing;

	glass glasses;
	glasses.loadGlassCatalog_Schott();

	Light_LLT Light0_nonLin;
	Light0_nonLin.setWavelength(587.5618);
	Light0_nonLin.setIntensity(1.0);

	Light_LLT Light1_nonLin;
	Light1_nonLin.setWavelength(486.1327);
	Light1_nonLin.setIntensity(1.0);

	Light_LLT Light2_nonLin;
	Light2_nonLin.setWavelength(656.2725);
	Light2_nonLin.setIntensity(1.0);


	std::vector<Light_LLT> lichtVecnonLin{ Light0_nonLin, Light1_nonLin, Light2_nonLin };

	// surfaces nonLin
	ApertureStopElement AperSto0_nonLin(/* semi height*/3.0, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAirZemax());
	SphericalElement Sphere1_nonLin(/*radius*/ 20.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,35.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAirZemax(), /*refractive index B*/glasses.getBK7_S1());
	SphericalElement Sphere2_nonLin(/*radius*/ 50.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,45.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getBK7_S1(), /*refractive index B*/glasses.getSF5_S1());
	SphericalElement Sphere3_nonLin(/*radius*/ 25.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,55.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAirZemax(), /*refractive index B*/glasses.getSF5_S1());
	PlanElement Plan4_nonLin(/*semi height*/ 99.0, /*point*/{ 0.0,0.0,85.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAirZemax(), /*refractive index B*/ glasses.getAirZemax());

	surfacePtr AperSto0_nonLin_ptr = AperSto0_nonLin.clone();
	surfacePtr Sphere1_nonLin_ptr = Sphere1_nonLin.clone();
	surfacePtr Sphere2_nonLin_ptr = Sphere2_nonLin.clone();
	surfacePtr Sphere3_nonLin_ptr = Sphere3_nonLin.clone();
	surfacePtr Plan4_nonLin_ptr = Plan4_nonLin.clone();

	std::vector<surfacePtr> opticalSystemnonLin_ptr{ AperSto0_nonLin_ptr, Sphere1_nonLin_ptr, Sphere2_nonLin_ptr, Sphere3_nonLin_ptr, Plan4_nonLin_ptr };
	std::vector<interactionPtr> interactionsnonLin_ptr{ doNothing.clone(),refrac.clone(), refrac.clone(), refrac.clone(), refrac.clone(), absorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement_nonLin(opticalSystemnonLin_ptr, interactionsnonLin_ptr);

	// trace the ray thow the optical system
	SequentialRayTracing seqTrace_nonLin_optA(/*optical system element*/ optSystemElement_nonLin, /*start point lightRay*/{ 0.0,0.0,0.0 }, /*rings*/ 6, /*arms*/ 8, /*refractive index*/ 1.0, lichtVecnonLin);
	SequentialRayTracing seqTrace_nonLin_field2(/*optical system element*/ optSystemElement_nonLin, /*start point lightRay*/{ 0.0,2.0,0.0 }, /*rings*/ 6, /*arms*/ 8, /*refractive index*/ 1.0, lichtVecnonLin);
	SequentialRayTracing seqTrace_nonLin_field4(/*optical system element*/ optSystemElement_nonLin, /*start point lightRay*/{ 0.0,4.0,0.0 }, /*rings*/ 6, /*arms*/ 8, /*refractive index*/ 1.0, lichtVecnonLin);

	// calculate rms value
	Spot spot_nonLin_optA(seqTrace_nonLin_optA.getAllInterPointsAtSurf_i(4), seqTrace_nonLin_optA.getAllInterPointsAtSurf_i(4).at(0));
	real rms_nonLin_optA = spot_nonLin_optA.getRMS_µm();
	bool checkRMSoptA_nonLin = Math::compareTwoNumbers(rms_nonLin_optA, 354.553, 2);
	workNonLin.push_back(checkRMSoptA_nonLin);
	Spot spot_nonLin_field2(seqTrace_nonLin_field2.getAllInterPointsAtSurf_i(4), seqTrace_nonLin_field2.getAllInterPointsAtSurf_i(4).at(0));
	real rms_nonLin_field2 = spot_nonLin_field2.getRMS_µm();
	bool checkRMSfield2_nonLin = Math::compareTwoNumbers(rms_nonLin_field2, 339.605, 2);
	workNonLin.push_back(checkRMSfield2_nonLin);
	Spot spot_nonLin_field4(seqTrace_nonLin_field4.getAllInterPointsAtSurf_i(4), seqTrace_nonLin_field4.getAllInterPointsAtSurf_i(4).at(0));
	real rms_nonLin_field4 = spot_nonLin_field4.getRMS_µm();
	bool checkRMSfield4_nonLin = Math::compareTwoNumbers(rms_nonLin_field4, 302.609, 2);
	workNonLin.push_back(checkRMSfield4_nonLin);

	bool output = Math::checkTrueOfVectorElements(workNonLin);
	

	std::vector<real> lineWithPossibleRadius = Math::linDistriAlongTwoValues_double_steps(minRadius, maxRadius, steps);
	real tempRadius;
	std::vector<real> vectorToExport(4);

	for (unsigned int i = 0; i < lineWithPossibleRadius.size(); i++)
	{
		

		tempRadius = lineWithPossibleRadius.at(i);
		std::cout << "radius: " << tempRadius << std::endl;
		Sphere1_nonLin_ptr->setRadiusElementValue(tempRadius);

		// trace the ray thow the optical system
		SequentialRayTracing seqTrace_nonLin_optA(/*optical system element*/ optSystemElement_nonLin, /*start point lightRay*/{ 0.0,0.0,0.0 }, /*rings*/ 6, /*arms*/ 8, /*refractive index*/ 1.0, lichtVecnonLin);
		SequentialRayTracing seqTrace_nonLin_field2(/*optical system element*/ optSystemElement_nonLin, /*start point lightRay*/{ 0.0,2.0,0.0 }, /*rings*/ 6, /*arms*/ 8, /*refractive index*/ 1.0, lichtVecnonLin);
		SequentialRayTracing seqTrace_nonLin_field4(/*optical system element*/ optSystemElement_nonLin, /*start point lightRay*/{ 0.0,4.0,0.0 }, /*rings*/ 6, /*arms*/ 8, /*refractive index*/ 1.0, lichtVecnonLin);
		
		// calculate rms value
		Spot spot_nonLin_optA(seqTrace_nonLin_optA.getAllInterPointsAtSurf_i(4), seqTrace_nonLin_optA.getAllInterPointsAtSurf_i(4).at(0));
		real rms_nonLin_optA = spot_nonLin_optA.getRMS_µm();

		
		Spot spot_nonLin_field2(seqTrace_nonLin_field2.getAllInterPointsAtSurf_i(4), seqTrace_nonLin_field2.getAllInterPointsAtSurf_i(4).at(0));
		real rms_nonLin_field2 = spot_nonLin_field2.getRMS_µm();


		Spot spot_nonLin_field4(seqTrace_nonLin_field4.getAllInterPointsAtSurf_i(4), seqTrace_nonLin_field4.getAllInterPointsAtSurf_i(4).at(0));
		real rms_nonLin_field4 = spot_nonLin_field4.getRMS_µm();

		// fill the vector to export and save 
		vectorToExport.at(0) = tempRadius;
		vectorToExport.at(1) = rms_nonLin_optA;
		vectorToExport.at(2) = rms_nonLin_field2;
		vectorToExport.at(3) = rms_nonLin_field4;
		inportExportData::exportDataToExcel_vector(location, nameToSave, "Radius, RMS optA, field2 and field 4", vectorToExport);

		tempRadius = tempRadius + steps;

	}

	return output;
}