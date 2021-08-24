#include "oftenUseNamespace.h"
#include <iomanip>
#include <limits>
#include "..\..\Inport_Export_Data\Inport_Export_Data.h"

#include "..\SequentialRayTracing\SequentialRayTracer.h"
#include "..\RayAiming\RayAiming.h"
#include "..\FillAptertureStop\FillApertureStop.h"
//#define unsignedInt_INF (unsigned)!((int)0)

bool oftenUse::checkRayTracing(VectorStructR3 startPoint, VectorStructR3 direction, VectorStructR3 targetPoint, OpticalSystem_LLT optSys_LLT, unsigned int surfaceNum, real tolerance)
{
	SequentialRayTracing seqTrace(optSys_LLT);
	// ray
	Ray_LLT ray(startPoint, direction, 1.0);
	// light
	Light_LLT mLight;
	mLight.setWavelength(550.0);
	mLight.setIntensity(1.0);
	mLight.setJonesVector({ 1.0,1.0,1.0,1.0 });
	mLight.setTypeLight(typeLight::typeLightRay);
	// light ray
	LightRayStruct lightRay(mLight, ray, 1.0);
	// ray tracing
	seqTrace.sequentialRayTracing(lightRay);

	int sizeOpticalSystem = optSys_LLT.getPosAndInteractingSurface().size() - 1;
	if (surfaceNum > sizeOpticalSystem)
	{
		surfaceNum = sizeOpticalSystem;
	}

	VectorStructR3 intersecPoint = seqTrace.getAllInterPointsAtSurface_i_filtered(surfaceNum)[0];

	bool checker = Math::compareTwoVectorStructR3_tolerance(intersecPoint, targetPoint, tolerance);

	return checker;
}


bool oftenUse::checkIfUnsIntIsInVector(/*search for unsingt int*/ unsigned int target, /*vector with unsigned int*/ std::vector<unsigned int> vectorUnsInt)
{


	std::vector<unsigned int>::iterator it = std::find(vectorUnsInt.begin(), vectorUnsInt.end(), target);
	if (it != vectorUnsInt.end())
	{
		return true;
	}

	return false;
}

void oftenUse::resizeAllRowsMatrix(std::vector<std::vector<real>>& matrix, unsigned int rows)
{
	unsigned int numColumnsMatrix = matrix.size();
	for (unsigned int i = 0; i < numColumnsMatrix; ++i)
	{
		matrix[i].resize(rows);
	}
}

void oftenUse::resizeAllRowsMatrix(std::vector<std::vector<float>>& matrix, unsigned int rows)
{
	unsigned int numColumnsMatrix = matrix.size();
	for (unsigned int i = 0; i < numColumnsMatrix; ++i)
	{
		matrix[i].resize(rows);
	}
}

void oftenUse::print(std::vector< std::vector<double> > A)
{
	unsigned int numColumns = A.size();
	unsigned int numRows = A[0].size();

	for (int i = 0; i < numColumns; i++)
	{
		for (int j = 0; j < numRows; j++)
		{
			std::cout << A[i][j] << "\t" "\t";
		}
		std::cout << "\n";
	}
	std::cout << std::endl;
}

void oftenUse::print(std::vector<real> V)
{
	unsigned int sizeVec = V.size();
	for (unsigned int i = 0; i < sizeVec; ++i)
	{
		std::cout << V[i] << std::endl;
	}

	std::cout << std::endl;
}

void oftenUse::print(OpticalSystemElement opticalSysElement, real wavelength)
{

	unsigned int size = opticalSysElement.getPosAndElement().size();
	opticalSysElement.setRefractiveIndexAccordingToWavelength(wavelength);
	std::shared_ptr<SurfaceIntersectionRay_LLT> tempSurface_ptr;
	std::shared_ptr<SurfaceIntersectionRay_LLT> tempSurface_ptr_next;

	std::string tempTypeMode_Radius;
	std::string tempTypeMode_Thickness;

	real tempRadius{};
	real tempPoint_Z{};
	real tempPoint_Z_next{};
	real tempDirection_Z{};
	real semiHeight{};
	real tempPointZ = 0;
	std::string nameGlasRightSide{};
	real thickness = 0;
	real tempRefIndexRightSide{};

	for (unsigned int i = 0; i < size; i++)
	{
		tempSurface_ptr = opticalSysElement.getPosAndIntersection_LLT()[i].getSurfaceInterRay_ptr();

		// get radius
		tempRadius = tempSurface_ptr->getRadius();
		tempTypeMode_Radius = oftenUse::convertTypeModeToString(opticalSysElement.getPosAndElement()[i].getElementInOptSys_ptr()->getRadiusTypeModifier());
		tempDirection_Z = tempSurface_ptr->getDirection().getZ();
		// glass by name
		if (tempDirection_Z > 0)
		{
			nameGlasRightSide = opticalSysElement.getPosAndElement()[i].getElementInOptSys_ptr()->getGlassB().getNameGlas();
			tempRefIndexRightSide = tempSurface_ptr->getRefractiveIndex_B();
		}

		else if (tempDirection_Z < 0)
		{
			tempRadius = -1 * tempRadius;
			nameGlasRightSide = opticalSysElement.getPosAndElement()[i].getElementInOptSys_ptr()->getGlassA().getNameGlas();
			tempRefIndexRightSide = tempSurface_ptr->getRefractiveIndex_A();
		}

		//if (tempRadius > 999.0)
		//{
		//	tempRadius = 999.0;
		//}
		//
		//else if (tempRadius < -999.0)
		//{
		//	tempRadius = -999.0;
		//}

		// get tempPoint
		tempTypeMode_Thickness = oftenUse::convertTypeModeToString(opticalSysElement.getPosAndElement()[i].getElementInOptSys_ptr()->getPointTypeModifier_Z());
		if (i < size - 1)
		{
			tempSurface_ptr_next = opticalSysElement.getPosAndIntersection_LLT()[i + 1].getSurfaceInterRay_ptr();
			tempPoint_Z = tempSurface_ptr->getPoint().getZ();
			tempPoint_Z_next = tempSurface_ptr_next->getPoint().getZ();
		}

		else
		{
			tempPoint_Z = 99.0;
			tempPoint_Z_next = 99.0;
		}

		thickness = tempPoint_Z_next - tempPoint_Z;



		// get semiHeight
		semiHeight = tempSurface_ptr->getSemiHeight();

		std::cout << "" << std::endl;
		std::cout << std::fixed;
		std::cout << std::setprecision(3);
		std::cout << "surface: " << i << '\t' << "radius: " << tempRadius << " " << tempTypeMode_Radius << '\t' << "thickness: " << thickness << " " << tempTypeMode_Thickness << '\t' << "glass: " << nameGlasRightSide << '\t' << "refIndex: " << tempRefIndexRightSide << '\t' << "semi height: " << '\t' << semiHeight << std::endl;

	}

	std::cout << "" << std::endl;

}

void oftenUse::print(OpticalSystem_LLT optSys)
{
	unsigned int size = optSys.getPosAndInteractingSurface().size();
	std::shared_ptr<SurfaceIntersectionRay_LLT> tempSurface_ptr;
	std::shared_ptr<SurfaceIntersectionRay_LLT> tempSurface_ptr_next;

	std::string tempTypeMode_Radius;
	std::string tempTypeMode_Thickness;

	real tempRadius{};
	real tempPoint_Z{};
	real tempPoint_Z_next{};
	real tempDirection_Z{};
	real semiHeight{};
	real tempPointZ = 0;
	std::string nameGlasRightSide{};
	real thickness = 0;
	real tempRefIndexRightSide{};

	for (unsigned int i = 0; i < size; i++)
	{
		tempSurface_ptr = optSys.getPosAndInteractingSurface()[i].getSurfaceInterRay_ptr();

		// get radius
		tempRadius = tempSurface_ptr->getRadius();
		tempDirection_Z = tempSurface_ptr->getDirection().getZ();
		// glass by name
		if (tempDirection_Z > 0)
		{
			tempRefIndexRightSide = tempSurface_ptr->getRefractiveIndex_B();
		}

		else if (tempDirection_Z < 0)
		{
			tempRadius = -1 * tempRadius;
			tempRefIndexRightSide = tempSurface_ptr->getRefractiveIndex_A();
		}

		if (std::abs(tempRadius) > 999.0)
		{
			tempRadius = 999.0;
		}

		// get tempPoint
		if (i < size - 1)
		{
			tempSurface_ptr_next = optSys.getPosAndInteractingSurface()[i + 1].getSurfaceInterRay_ptr();
			tempPoint_Z = tempSurface_ptr->getPoint().getZ();
			tempPoint_Z_next = tempSurface_ptr_next->getPoint().getZ();
		}

		else
		{
			tempPoint_Z = 99.0;
			tempPoint_Z_next = 99.0;
		}

		thickness = tempPoint_Z_next - tempPoint_Z;



		// get semiHeight
		semiHeight = tempSurface_ptr->getSemiHeight();

		std::cout << "" << std::endl;
		std::cout << std::fixed;
		std::cout << std::setprecision(3);
		std::cout << "surface: " << i << '\t' << "radius: " << tempRadius << " " << tempTypeMode_Radius << '\t' << "thickness: " << thickness << " " << tempTypeMode_Thickness << '\t' << "glass: " << nameGlasRightSide << '\t' << "refIndex: " << tempRefIndexRightSide << '\t' << "semi height: " << '\t' << semiHeight << std::endl;

	}

	std::cout << "" << std::endl;
}

// get very height number
real oftenUse::getInfReal()
{
	real inf = 99999999999999999999999999999.0;
	return inf;
};
float oftenUse::getInfFloat()
{
	float inf = 99999999999999999999999999999.0;
	return inf;
};
int oftenUse::getInfInt()
{
	int inf = 999999999;
	return inf;
};
//unsigned int oftenUse::getInfUnsignedInt() { return unsignedInt_INF; };

// check if two values have the same prefix
bool oftenUse::checkSamePrefixTwoVal(real v1, real v2)
{
	if (v1 > 0.0 & v2 < 0.0 || v1 < 0 & v2>0)
	{
		return false;
	}

	return true;
}

// build default Light
Light_LLT oftenUse::buildDefaultLight(real wavelength)
{
	real defaultIntensity = 1.0;
	JonesVector_LLT defaultPolarisation(1.0, 1.0, 1.0, 1.0);
	typeLight defaultLightType = typeLight::typeLightRay;

	Light_LLT defaultLight(/*wavelength*/ wavelength, /*intensity*/ defaultIntensity,/*polarisation*/defaultPolarisation,/*light type*/ defaultLightType);

	return defaultLight;
}

Light_LLT oftenUse::getDefaultLight()
{
	return buildDefaultLight(550.0);
}

// build default Light vector
std::vector<Light_LLT> oftenUse::buildDefaultLight_Vec(std::vector<real> wavelength_vec)
{
	unsigned int numberWavelengths = wavelength_vec.size();
	std::vector<Light_LLT> returnLight_LLT_vec;
	returnLight_LLT_vec.resize(numberWavelengths);
	Light_LLT tempLight;

	for (unsigned int i = 0; i < numberWavelengths; ++i)
	{
		tempLight = oftenUse::buildDefaultLight(wavelength_vec[i]);
		returnLight_LLT_vec[i] = tempLight;
	}

	return returnLight_LLT_vec;
}

bool oftenUse::checkOptSysELement_Equal_Better_Zemax(OpticalSystemElement opticalSystemHLT, std::vector<VectorStructR3> fieldPoints, std::vector<real> wavelength_vec, std::vector<real> rmsValZemax, real tolerance, compareTOM_Zemax compare)
{
	bool check_Equal_Better_Zemax{};

	unsigned int defaultRings = 6;
	unsigned int defaultArms = 8;
	real defaultRefractivIndex = 1.0;

	unsigned int posLastSurface = opticalSystemHLT.getPosAndElement().size() - 1;

	unsigned int numFieldPoints = fieldPoints.size();
	unsigned int numRMS_ValZemax = rmsValZemax.size();
	unsigned int numWavelengths = wavelength_vec.size();

	std::vector<Light_LLT> lightVec = oftenUse::buildDefaultLight_Vec(wavelength_vec);

	// check if number field points is equal to rms values from zemax
	if (numFieldPoints != numRMS_ValZemax)
	{
		std::cout << "number of evaluated field does not match to the number of evaluated rms values" << std::endl;
		return false;
	}

	SequentialRayTracing tempSeqTrace;
	VectorStructR3 tempFieldPoint{};
	real tempWavelength;


	RayAiming tempRayAiming;
	FillApertureStop FillApertureStop(opticalSystemHLT.getOptSys_LLT_buildSystem(), defaultRings, defaultArms);
	std::vector<LightRayStruct> tempLightRay_vec{};

	std::vector<VectorStructR3> tempInterPoints{};
	std::vector<VectorStructR3> saveAllInterPoints{};

	real tempRMS;
	std::vector<real> allRMS;
	allRMS.resize(numFieldPoints);

	for (unsigned int i = 0; i < numFieldPoints; ++i)
	{
		tempFieldPoint = fieldPoints[i];

		for (unsigned int j = 0; j < numWavelengths; ++j)
		{
			tempWavelength = wavelength_vec[j];
			opticalSystemHLT.setRefractiveIndexAccordingToWavelength(tempWavelength);
			opticalSystemHLT.convertSurfacesToLLT();

			tempRayAiming.setOpticalSystem_LLT(opticalSystemHLT.getOptSys_LLT_buildSystem());
			tempRayAiming.loadImportantInfosForRayAiming();
			tempRayAiming.turn_On_RobustRayAiming();
			tempRayAiming.setMaxIterationsRayAiming(200);
			tempRayAiming.setMaxInterationRobustRayAiming(200);

			// check distance obj first surface
			real posZ_0 = opticalSystemHLT.getOpticalSystemElement().getPosAndIntersection_LLT()[0].getSurfaceInterRay_ptr()->getPoint().getZ();
			tempRayAiming.setFactorObj_distanceObjPointToFirstSurface(tempFieldPoint.getZ(), posZ_0);


			tempLightRay_vec = tempRayAiming.rayAimingMany_obj(FillApertureStop.getPointsInAS(), tempFieldPoint, lightVec[0], defaultRefractivIndex);

			tempSeqTrace.setOpticalSystem(opticalSystemHLT);
			tempSeqTrace.setTraceToSurface(posLastSurface);
			tempSeqTrace.seqRayTracingWithVectorOfLightRays(tempLightRay_vec);

			tempInterPoints = tempSeqTrace.getAllInterPointsAtSurf_i_notFiltered(posLastSurface);

			saveAllInterPoints.insert(saveAllInterPoints.end(), tempInterPoints.begin(), tempInterPoints.end());

			tempSeqTrace.clearAllTracedRays();

		}


		// calc rms spot
		Spot tempSpot(saveAllInterPoints, saveAllInterPoints[0]);
		allRMS[i] = tempSpot.getRMS_�m();

		saveAllInterPoints.clear();

	}


	if (compare == compareTOM_Zemax::comEqual)
	{
		real tempRMS_TOM;
		real tempRMS_Z;
		bool tempChecker;
		std::vector<bool> checker;
		checker.resize(numFieldPoints);

		for (unsigned int i = 0; i < numFieldPoints; i++)
		{
			tempRMS_TOM = allRMS[i];
			tempRMS_Z = rmsValZemax[i];

			std::cout << "temp rms tom: " << tempRMS_TOM << std::endl;
			std::cout << "temp rms Zemax: " << tempRMS_Z << std::endl;

			tempChecker = Math::compareTwoNumbers_tolerance(tempRMS_TOM, tempRMS_Z, tolerance);
			checker[i] = tempChecker;

		}

		check_Equal_Better_Zemax = Math::checkTrueOfVectorElements(checker);
	}

	else if (compare == compareTOM_Zemax::comBetter)
	{
		real sumRMS_TOM = Math::sumAllVectorValues(allRMS);
		real sumRMS_Z = Math::sumAllVectorValues(rmsValZemax);

		std::cout << "sum rms tom: " << sumRMS_TOM << std::endl;
		std::cout << "sum rms Zemax: " << sumRMS_Z << std::endl;

		check_Equal_Better_Zemax = (sumRMS_TOM - sumRMS_Z) < tolerance;
	}


	return check_Equal_Better_Zemax;
}


bool oftenUse::checkOptSysELement_Equal_Better_Zemax(OpticalSystemElement optimizedSystemHLT, VectorStructR3 fieldPoint, real wavelength, real rmsValZemax, real tolerance, compareTOM_Zemax compare)
{
	std::vector<VectorStructR3> field_vec = { fieldPoint };
	std::vector<real> wace_vec = { wavelength };
	std::vector<real> ref_rms = { rmsValZemax };

	bool checkTheSystem = checkOptSysELement_Equal_Better_Zemax(optimizedSystemHLT, field_vec, wace_vec, ref_rms, tolerance, compare);

	return checkTheSystem;
}

bool oftenUse::checkOptSysELement_Equal_Better_Zemax(OpticalSystemElement optimizedSystemHLT, VectorStructR3 fieldPoint, std::vector<real> wavelength_vec, real rmsValZemax, real tolerance, compareTOM_Zemax compare)
{
	std::vector<VectorStructR3> field_vec = { fieldPoint };
	std::vector<real> ref_rms = { rmsValZemax };

	bool checkTheSystem = checkOptSysELement_Equal_Better_Zemax(optimizedSystemHLT, field_vec, wavelength_vec, ref_rms, tolerance, compare);

	return checkTheSystem;
}

bool oftenUse::checkOptSysELement_Equal_Better_Zemax(OpticalSystemElement optimizedSystemHLT, std::vector<VectorStructR3> fieldPoint_vec, real wavelength, std::vector<real> rmsValZemax_vec, real tolerance, compareTOM_Zemax compare)
{
	std::vector<real> wavelength_vec = { wavelength };
	bool checkTheSystem = checkOptSysELement_Equal_Better_Zemax(optimizedSystemHLT, fieldPoint_vec, wavelength_vec, rmsValZemax_vec, tolerance, compare);

	return checkTheSystem;
}

// check optical system HLT better / eauel than zemax
bool oftenUse::checkOptSysELement_Equal_Better_Zemax(OpticalSystemElement optimizedSystemHLT, std::vector<real> anglesX_vec, std::vector<real> anglesY_vec, std::vector<real> wavelength_vec, std::vector<real> rmsValZemax, real tolerance, compareTOM_Zemax compare)
{
	bool check_Equal_Better_Zemax{};

	unsigned int defaultRings = 6;
	unsigned int defaultArms = 8;
	real defaultRefractivIndex = 1.0;

	unsigned int posLastSurface = optimizedSystemHLT.getPosAndElement().size() - 1;

	unsigned int numAnglesX = anglesX_vec.size();
	unsigned int numAnglesY = anglesY_vec.size();
	unsigned int numRMS_ValZemax = rmsValZemax.size();
	unsigned int numWavelengths = wavelength_vec.size();

	std::vector<Light_LLT> lightVec = oftenUse::buildDefaultLight_Vec(wavelength_vec);

	// check if number field points is equal to rms values from zemax
	if (numAnglesX != numRMS_ValZemax || numAnglesX != numAnglesY)
	{
		std::cout << "ERROR - inf -> checkOptSysELement_Equal_Better_Zemax" << std::endl;
		check_Equal_Better_Zemax = false;
	}

	SequentialRayTracing tempSeqTrace;
	real tempAngle_X{};
	real tempAngle_Y{};
	real tempWavelength;


	RayAiming tempRayAiming;
	FillApertureStop FillApertureStop(optimizedSystemHLT.getOptSys_LLT_buildSystem(), defaultRings, defaultArms);
	std::vector<LightRayStruct> tempLightRay_vec{};

	std::vector<VectorStructR3> tempInterPoints{};
	std::vector<VectorStructR3> saveAllInterPoints{};

	real tempRMS;
	std::vector<real> allRMS;
	allRMS.resize(numAnglesX);

	for (unsigned int i = 0; i < numAnglesX; ++i)
	{
		tempAngle_X = anglesX_vec[i];
		tempAngle_Y = anglesY_vec[i];

		for (unsigned int j = 0; j < numWavelengths; ++j)
		{
			tempWavelength = wavelength_vec[j];
			optimizedSystemHLT.setRefractiveIndexAccordingToWavelength(tempWavelength);
			//optimizedSystemHLT.convertSurfacesToLLT();

			tempRayAiming.setOpticalSystem_LLT(optimizedSystemHLT.getOptSys_LLT_buildSystem());
			tempRayAiming.loadImportantInfosForRayAiming();
			tempRayAiming.turn_On_RobustRayAiming();

			tempLightRay_vec = tempRayAiming.rayAimingMany_inf(FillApertureStop.getPointsInAS(), tempAngle_X, tempAngle_Y, lightVec[0], defaultRefractivIndex);

			tempSeqTrace.setOpticalSystem(optimizedSystemHLT);
			tempSeqTrace.setTraceToSurface(posLastSurface);
			tempSeqTrace.seqRayTracingWithVectorOfLightRays(tempLightRay_vec);

			tempInterPoints = tempSeqTrace.getAllInterPointsAtSurface_i_filtered(posLastSurface);

			saveAllInterPoints.insert(saveAllInterPoints.end(), tempInterPoints.begin(), tempInterPoints.end());

			tempSeqTrace.clearAllTracedRays();

		}


		// calc rms spot
		Spot tempSpot(saveAllInterPoints, saveAllInterPoints[0]);
		allRMS[i] = tempSpot.getRMS_�m();

		saveAllInterPoints.clear();

	}


	if (compare == compareTOM_Zemax::comEqual)
	{
		real tempRMS_TOM;
		real tempRMS_Z;
		bool tempChecker;

		std::vector<bool> checker;
		checker.resize(numAnglesX);

		for (unsigned int i = 0; i < numAnglesX; i++)
		{
			tempRMS_TOM = allRMS[i];
			tempRMS_Z = rmsValZemax[i];

			tempChecker = Math::compareTwoNumbers_tolerance(tempRMS_TOM, tempRMS_Z, tolerance);
			checker[i] = tempChecker;

			std::cout << "temp rms tom: " << tempRMS_TOM << std::endl;
			std::cout << "temp rms Zemax: " << tempRMS_Z << std::endl;


		}

		check_Equal_Better_Zemax = Math::checkTrueOfVectorElements(checker);
	}

	else if (compare == compareTOM_Zemax::comBetter)
	{
		real sumRMS_TOM = Math::sumAllVectorValues(allRMS);
		real sumRMS_Z = Math::sumAllVectorValues(rmsValZemax);

		std::cout << "sum rms tom: " << sumRMS_TOM << std::endl;
		std::cout << "sum rms Zemax: " << sumRMS_Z << std::endl;

		check_Equal_Better_Zemax = (sumRMS_TOM - sumRMS_Z) < tolerance;
	}





	return check_Equal_Better_Zemax;

}

bool oftenUse::checkOptSysELement_Equal_Better_Zemax(OpticalSystemElement optimizedSystemHLT, real anglesX, real anglesY, std::vector<real> wavelength_vec, std::vector<real> rmsValZemax, real tolerance, compareTOM_Zemax compare)
{
	std::vector<real> angleX_vec = { anglesX };
	std::vector<real> angleY_vec = { anglesY };

	bool checker = checkOptSysELement_Equal_Better_Zemax(optimizedSystemHLT, angleX_vec, angleY_vec, wavelength_vec, rmsValZemax, tolerance, compare);

	return checker;
}

bool oftenUse::checkOptSysELement_Equal_Better_Zemax(OpticalSystemElement optimizedSystemHLT, real anglesX, real anglesY, real wavelength, real rmsValZemax, real tolerance, compareTOM_Zemax compare)
{
	std::vector<real> angleX_vec = { anglesX };
	std::vector<real> angleY_vec = { anglesY };
	std::vector<real> wave_vec = { wavelength };
	std::vector<real> rms_vec = { rmsValZemax };

	bool checker = checkOptSysELement_Equal_Better_Zemax(optimizedSystemHLT, angleX_vec, angleY_vec, wave_vec, rms_vec, tolerance, compare);

	return checker;

}

// check the thickness between surfaces
bool oftenUse::checkThickness(OpticalSystem_LLT optSys_LLT, std::vector<real> thickness_vec, real tolerance)
{
	std::vector<real> thicknessOptSys_vec;
	unsigned int sizeOptSys = optSys_LLT.getPosAndInteractingSurface().size();
	thicknessOptSys_vec.resize(sizeOptSys - 1);

	real tempThickness_Z;
	real tempPosSurface_Z{};
	real tempPosNextSurface{};

	for (unsigned int i = 0; i < sizeOptSys - 1; ++i)
	{
		tempPosSurface_Z = optSys_LLT.getPosAndInteractingSurface()[i].getSurfaceInterRay_ptr()->getPoint().getZ();
		tempPosNextSurface = optSys_LLT.getPosAndInteractingSurface()[i + 1].getSurfaceInterRay_ptr()->getPoint().getZ();
		tempThickness_Z = tempPosNextSurface - tempPosSurface_Z;
		thicknessOptSys_vec[i] = tempThickness_Z;
	}

	return Math::compateTwoSTDVector_tolerance(thicknessOptSys_vec, thickness_vec, tolerance);

}

// check optical system LLT better / equal than zemax
bool oftenUse::checkOptSysLLT_Equal_Better_Zemax(OpticalSystem_LLT optSys_LLT, std::vector<VectorStructR3> fieldPoints, std::vector<real> rmsValZemax, real tolerance, compareTOM_Zemax compare)
{

	bool check_Equal_Better_Zemax{};

	unsigned int defaultRings = 6;
	unsigned int defaultArms = 8;
	real startRefractivIndex = getStartRefIndex(optSys_LLT);

	unsigned int posLastSurface = optSys_LLT.getPosAndInteractingSurface().size() - 1;

	unsigned int numFieldPoints = fieldPoints.size();
	unsigned int numRMS_ValZemax = rmsValZemax.size();

	// check if number field points is equal to rms values from zemax
	if (numFieldPoints != numRMS_ValZemax)
	{
		std::cout << "number of evaluated field does not match to the number of evaluated rms values" << std::endl;
		return false;
	}

	SequentialRayTracing tempSeqTrace(optSys_LLT);
	VectorStructR3 tempFieldPoint{};

	RayAiming tempRayAiming(optSys_LLT);
	FillApertureStop FillApertureStop(optSys_LLT, defaultRings, defaultArms);
	std::vector<LightRayStruct> tempLightRay_vec{};

	std::vector<VectorStructR3> tempInterPoints{};
	Light_LLT defaultLight = oftenUse::getDefaultLight();

	real tempRMS;
	std::vector<real> allRMS;
	allRMS.resize(numFieldPoints);

	Spot tempSpot;

	for (unsigned int i = 0; i < numFieldPoints; ++i)
	{
		tempFieldPoint = fieldPoints[i];

		tempLightRay_vec = tempRayAiming.rayAimingMany_obj(FillApertureStop.getPointsInAS(), tempFieldPoint, defaultLight, startRefractivIndex);

		tempSeqTrace.seqRayTracingWithVectorOfLightRays(tempLightRay_vec);

		tempInterPoints = tempSeqTrace.getAllInterPointsAtSurf_i_notFiltered(posLastSurface);

		// calc rms spot
		allRMS[i] = tempSpot.calcRMS(tempInterPoints, tempInterPoints[0]) * 1000;

		tempSeqTrace.clearAllTracedRays();

	}

	if (compare == compareTOM_Zemax::comEqual)
	{
		real tempRMS_TOM;
		real tempRMS_Z;
		bool tempChecker;
		std::vector<bool> checker;
		checker.resize(numFieldPoints);

		for (unsigned int i = 0; i < numFieldPoints; i++)
		{
			tempRMS_TOM = allRMS[i];
			tempRMS_Z = rmsValZemax[i];

			std::cout << "rms TOM: " << tempRMS_TOM << std::endl;
			std::cout << "rms referencce: " << tempRMS_Z << std::endl;

			tempChecker = Math::compareTwoNumbers_tolerance(tempRMS_TOM, tempRMS_Z, tolerance);
			checker[i] = tempChecker;

		}

		check_Equal_Better_Zemax = Math::checkTrueOfVectorElements(checker);
	}

	else if (compare == compareTOM_Zemax::comBetter)
	{
		real sumRMS_TOM = Math::sumAllVectorValues(allRMS);
		real sumRMS_Z = Math::sumAllVectorValues(rmsValZemax);

		check_Equal_Better_Zemax = (sumRMS_TOM - sumRMS_Z) < tolerance;
	}


	return check_Equal_Better_Zemax;

}

bool oftenUse::checkOptSysLLT_Equal_Better_Zemax(OpticalSystem_LLT optSys_LLT, VectorStructR3 fieldPoints, real rmsValZemax, real tolerance, compareTOM_Zemax compare)
{
	std::vector<VectorStructR3> field_vec = { fieldPoints };
	std::vector<real> ref_rms_vec = { rmsValZemax };

	bool checkEqualBetter = checkOptSysLLT_Equal_Better_Zemax(optSys_LLT, field_vec, ref_rms_vec, tolerance, compare);

	return checkEqualBetter;
}

bool oftenUse::checkOptSysLLT_Equal_Better_Zemax(OpticalSystem_LLT optSys_LLT, std::vector<real> fieldAngle_X, std::vector<real> fieldAngle_Y, std::vector<real> rmsValZemax, real tolerance, compareTOM_Zemax compare)
{
	bool check_Equal_Better_Zemax{};

	unsigned int defaultRings = 6;
	unsigned int defaultArms = 8;
	real startRefractivIndex = getStartRefIndex(optSys_LLT);

	unsigned int posLastSurface = optSys_LLT.getPosAndInteractingSurface().size() - 1;

	unsigned int numFieldAngle_X = fieldAngle_X.size();
	unsigned int numFieldAngle_Y = fieldAngle_Y.size();

	if (numFieldAngle_X != numFieldAngle_Y)
	{
		std::cout << "numFieldAngle_X is not numFieldAngle_Y" << std::endl;
		return false;
	}


	unsigned int numRMS_ValZemax = rmsValZemax.size();
	// check if number field points is equal to rms values from zemax
	if (numFieldAngle_X != numRMS_ValZemax)
	{
		std::cout << "number of evaluated field does not match to the number of evaluated rms values" << std::endl;
		return false;
	}

	SequentialRayTracing tempSeqTrace(optSys_LLT);
	real tempFieldAngle_X{};
	real tempFieldAngle_Y{};

	RayAiming tempRayAiming(optSys_LLT);
	FillApertureStop FillApertureStop(optSys_LLT, defaultRings, defaultArms);
	std::vector<LightRayStruct> tempLightRay_vec{};

	std::vector<VectorStructR3> tempInterPoints{};
	Light_LLT defaultLight = oftenUse::getDefaultLight();

	real tempRMS;
	std::vector<real> allRMS;
	allRMS.resize(numFieldAngle_X);

	Spot tempSpot;

	for (unsigned int i = 0; i < numFieldAngle_X; ++i)
	{
		tempFieldAngle_X = fieldAngle_X[i];
		tempFieldAngle_Y = fieldAngle_Y[i];

		tempLightRay_vec = tempRayAiming.rayAimingMany_inf(FillApertureStop.getPointsInAS(), tempFieldAngle_X, tempFieldAngle_Y, defaultLight, startRefractivIndex);

		tempSeqTrace.seqRayTracingWithVectorOfLightRays(tempLightRay_vec);

		tempInterPoints = tempSeqTrace.getAllInterPointsAtSurf_i_notFiltered(posLastSurface);

		// calc rms spot
		allRMS[i] = tempSpot.calcRMS(tempInterPoints, tempInterPoints[0]) * 1000;

		tempSeqTrace.clearAllTracedRays();

	}

	if (compare == compareTOM_Zemax::comEqual)
	{
		real tempRMS_TOM;
		real tempRMS_Z;
		bool tempChecker;
		std::vector<bool> checker;
		checker.resize(numFieldAngle_X);

		for (unsigned int i = 0; i < numFieldAngle_X; i++)
		{
			tempRMS_TOM = allRMS[i];
			tempRMS_Z = rmsValZemax[i];

			std::cout << "rms TOM: " << tempRMS_TOM << std::endl;
			std::cout << "rms referencce: " << tempRMS_Z << std::endl;

			tempChecker = Math::compareTwoNumbers_tolerance(tempRMS_TOM, tempRMS_Z, tolerance);
			checker[i] = tempChecker;

		}

		check_Equal_Better_Zemax = Math::checkTrueOfVectorElements(checker);
	}

	else if (compare == compareTOM_Zemax::comBetter)
	{
		real sumRMS_TOM = Math::sumAllVectorValues(allRMS);
		real sumRMS_Z = Math::sumAllVectorValues(rmsValZemax);

		check_Equal_Better_Zemax = (sumRMS_TOM - sumRMS_Z) < tolerance;
	}


	return check_Equal_Better_Zemax;
}

bool oftenUse::DLSmulticheck(DLS startDLS, std::vector<real> factorBetter_vec, std::vector<real> factorWorst_vec, std::vector<real> rmsZ_vec, unsigned int systemNum)
{
	OpticalSystemElement initalOptSysEle = startDLS.getInitialOpticalSystemHLT();
	std::string location = "../tests/DLSmulticheck/";
	std::string exportFile = "_DLSmulticheck";
	std::string sysNumString = std::to_string(systemNum);
	exportFile = sysNumString + exportFile;

	std::vector<real> vectorToExport;
	std::string exportString = "system number, factor Better, factor Worst, time to optimize, V1, V2, V3, RMS1, RMS2, RMS3, sum RMS TOM, sum RMS Zemax, better Zemax";

	// check size better_vec and worst_vec
	unsigned int sizeVecBetter = factorBetter_vec.size();
	unsigned int sizeVecWorst = factorWorst_vec.size();
	if (sizeVecBetter != sizeVecWorst)
	{
		std::cout << "vector sizes does not macht!" << std::endl;
	}

	real tempFactorBetter;
	real tempFactorWorst;
	std::vector<real> tempRMS_vec;
	std::vector<real> variables_vec;
	real sumRMS_TOM;
	real sumRMS_Zemax;

	std::vector<bool> checkBetterZemax;
	checkBetterZemax.resize(sizeVecBetter);

	OpticalSystemElement optimizedSystemHLT;
	unsigned int sizeRMS_Z = rmsZ_vec.size();
	unsigned int sizeTMS_TOM;
	unsigned int sizeVariables;

	OpticalSystemElement optSysEle_save = startDLS.getInitialOpticalSystemHLT().getDeepCopyOptSysEle();
	std::vector<VectorStructR3> fields_save = startDLS.getField_vec();
	std::vector<real> wavelengths_save = startDLS.getWavelength_vev();
	unsigned int rings_save = startDLS.getRings();
	unsigned int arms_save = startDLS.getArms();



	for (unsigned int i = 0; i < sizeVecBetter; ++i)
	{
		DLS workDLS(optSysEle_save, fields_save, wavelengths_save, rings_save, arms_save);

		tempFactorBetter = factorBetter_vec[i];
		tempFactorWorst = factorWorst_vec[i];
		workDLS.setFactorGettingBetter(tempFactorBetter);
		workDLS.setFactorGettingWorst(tempFactorWorst);

		// optimize the system using multiplicativ damping
		auto startTimeOptimization_total = std::chrono::high_resolution_clock::now();
		workDLS.optimizeSystem_DLS_multiplicativ_Damping();
		auto endTimeOptimization_total = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> TotalDurationOptimization_secondes = endTimeOptimization_total - startTimeOptimization_total;
		auto totalDurationOptimization_min = TotalDurationOptimization_secondes.count() / 60.0;

		optimizedSystemHLT = workDLS.getOptimizedSystem_HLT();
		tempRMS_vec = getRMSoptSysHLT(optimizedSystemHLT, workDLS.getField_vec(), workDLS.getWavelength_vev(), workDLS.getRings(), workDLS.getArms());
		sizeTMS_TOM = tempRMS_vec.size();

		// check size rms Zemax vs TOM
		if (sizeRMS_Z != sizeTMS_TOM)
		{
			std::cout << "check the size of rms values!!!" << std::endl;
		}

		variables_vec = oftenUse::getVariablesOfOptSysHLT(optimizedSystemHLT);
		sizeVariables = variables_vec.size();
		sumRMS_TOM = Math::sumAllVectorValues(tempRMS_vec);
		sumRMS_Zemax = Math::sumAllVectorValues(rmsZ_vec);

		checkBetterZemax[i] = sumRMS_TOM <= sumRMS_Zemax;

		vectorToExport.push_back(systemNum);
		vectorToExport.push_back(tempFactorBetter);
		vectorToExport.push_back(tempFactorWorst);
		vectorToExport.push_back(totalDurationOptimization_min);
		for (unsigned int j = 0; j < sizeVariables; j++)
		{
			vectorToExport.push_back(variables_vec[j]);
		}

		for (unsigned int k = 0; k < sizeTMS_TOM; ++k)
		{
			vectorToExport.push_back(tempRMS_vec[k]);
		}
		vectorToExport.push_back(sumRMS_TOM);
		vectorToExport.push_back(sumRMS_Zemax);
		vectorToExport.push_back(checkBetterZemax[i]);
		inportExportData::exportDataToExcel_vector(location, exportFile, exportString, vectorToExport);

		vectorToExport.clear();
	}


	bool checker = std::find(checkBetterZemax.begin(), checkBetterZemax.end(), true) != checkBetterZemax.end();
	return checker;
}

// get rms valus of optical system HLT
std::vector<real> oftenUse::getRMSoptSysHLT(OpticalSystemElement optimizedSystemHLT, std::vector<VectorStructR3> fieldPoints, std::vector<real> wavelength_vec, unsigned int rings, unsigned int arms)
{
	real defaultRefractivIndex = 1.0;

	unsigned int posLastSurface = optimizedSystemHLT.getPosAndElement().size() - 1;

	unsigned int numFieldPoints = fieldPoints.size();
	unsigned int numWavelengths = wavelength_vec.size();

	std::vector<Light_LLT> lightVec = oftenUse::buildDefaultLight_Vec(wavelength_vec);


	SequentialRayTracing tempSeqTrace;
	VectorStructR3 tempFieldPoint{};
	real tempWavelength;


	RayAiming tempRayAiming;
	FillApertureStop FillApertureStop(optimizedSystemHLT.getOptSys_LLT_buildSystem(), rings, arms);
	std::vector<LightRayStruct> tempLightRay_vec{};

	std::vector<VectorStructR3> tempInterPoints{};
	std::vector<VectorStructR3> saveAllInterPoints{};

	real tempRMS;
	std::vector<real> allRMS;
	allRMS.resize(numFieldPoints);

	for (unsigned int i = 0; i < numFieldPoints; ++i)
	{
		tempFieldPoint = fieldPoints[i];

		for (unsigned int j = 0; j < numWavelengths; ++j)
		{
			tempWavelength = wavelength_vec[j];
			optimizedSystemHLT.setRefractiveIndexAccordingToWavelength(tempWavelength);
			//optimizedSystemHLT.convertSurfacesToLLT();

			tempRayAiming.setOpticalSystem_LLT(optimizedSystemHLT.getOptSys_LLT_buildSystem());
			tempRayAiming.loadImportantInfosForRayAiming();

			tempLightRay_vec = tempRayAiming.rayAimingMany_obj(FillApertureStop.getPointsInAS(), tempFieldPoint, lightVec[0], defaultRefractivIndex);

			tempSeqTrace.setOpticalSystem(optimizedSystemHLT);
			tempSeqTrace.setTraceToSurface(posLastSurface);
			tempSeqTrace.seqRayTracingWithVectorOfLightRays(tempLightRay_vec);

			tempInterPoints = tempSeqTrace.getAllInterPointsAtSurface_i_filtered(posLastSurface);

			saveAllInterPoints.insert(saveAllInterPoints.end(), tempInterPoints.begin(), tempInterPoints.end());

			tempSeqTrace.clearAllTracedRays();

		}


		// calc rms spot
		Spot tempSpot(saveAllInterPoints, saveAllInterPoints[0]);
		allRMS[i] = tempSpot.getRMS_�m();

		saveAllInterPoints.clear();
	}

	return allRMS;
}

std::vector<real> oftenUse::getRMSoptSysHLT(OpticalSystemElement optimizedSystemHLT, std::vector<real> fieldAngle_X, std::vector<real> fieldAngle_Y, std::vector<real> wavelength_vec, unsigned int rings, unsigned int arms)
{
	real defaultRefractivIndex = 1.0;
	std::vector<real> allRMS{};
	unsigned int posLastSurface = optimizedSystemHLT.getPosAndElement().size() - 1;

	unsigned int numAngles_X = fieldAngle_X.size();

	// check size fields X and Y
	if (fieldAngle_X.size() != fieldAngle_Y.size())
	{
		return allRMS;
		std::cout << "number angle X is not number angles Y --> ERROR" << std::endl;
	}

	unsigned int numWavelengths = wavelength_vec.size();

	std::vector<Light_LLT> lightVec = oftenUse::buildDefaultLight_Vec(wavelength_vec);


	SequentialRayTracing tempSeqTrace;
	real tempAngle_X{};
	real tempAngle_Y{};
	real tempWavelength;


	RayAiming tempRayAiming;
	FillApertureStop FillApertureStop(optimizedSystemHLT.getOptSys_LLT_buildSystem(), rings, arms);
	std::vector<LightRayStruct> tempLightRay_vec{};

	std::vector<VectorStructR3> tempInterPoints{};
	std::vector<VectorStructR3> saveAllInterPoints{};

	real tempRMS;

	allRMS.resize(numAngles_X);

	for (unsigned int i = 0; i < numAngles_X; ++i)
	{
		tempAngle_X = fieldAngle_X[i];
		tempAngle_Y = fieldAngle_Y[i];


		for (unsigned int j = 0; j < numWavelengths; ++j)
		{
			tempWavelength = wavelength_vec[j];
			optimizedSystemHLT.setRefractiveIndexAccordingToWavelength(tempWavelength);
			//optimizedSystemHLT.convertSurfacesToLLT();

			tempRayAiming.setOpticalSystem_LLT(optimizedSystemHLT.getOptSys_LLT_buildSystem());
			tempRayAiming.loadImportantInfosForRayAiming();

			tempLightRay_vec = tempRayAiming.rayAimingMany_inf(FillApertureStop.getPointsInAS(), tempAngle_X, tempAngle_Y, lightVec[0], defaultRefractivIndex);

			tempSeqTrace.setOpticalSystem(optimizedSystemHLT);
			tempSeqTrace.setTraceToSurface(posLastSurface);
			tempSeqTrace.seqRayTracingWithVectorOfLightRays(tempLightRay_vec);

			tempInterPoints = tempSeqTrace.getAllInterPointsAtSurface_i_filtered(posLastSurface);

			saveAllInterPoints.insert(saveAllInterPoints.end(), tempInterPoints.begin(), tempInterPoints.end());

			tempSeqTrace.clearAllTracedRays();

		}


		// calc rms spot
		Spot tempSpot(saveAllInterPoints, saveAllInterPoints[0]);
		allRMS[i] = tempSpot.getRMS_�m();

		saveAllInterPoints.clear();
	}

	return allRMS;
}

std::vector<real> oftenUse::getVariablesOfOptSysHLT(OpticalSystemElement optSysEle)
{
	std::shared_ptr<Element_CR> tempElement_ptr;
	unsigned sizeOptSys = optSysEle.getSizeOptSys();
	std::vector<real> variables_vec{};

	for (unsigned int i = 0; i < sizeOptSys; ++i)
	{
		tempElement_ptr = optSysEle.getPosAndElement()[i].getElementInOptSys_ptr();

		// check if radius is variable
		if (tempElement_ptr->getRadiusTypeModifier() == typeModifierVariable)
		{
			if (tempElement_ptr->getDirectionElementValue_Z() > 0)
			{
				variables_vec.push_back(tempElement_ptr->getRadiusElementValue());
			}
			else
			{
				variables_vec.push_back(-1.0 * tempElement_ptr->getRadiusElementValue());
			}
		}

		// check if thickness is variable
		if (tempElement_ptr->getPointTypeModifier_Z() == typeModifierVariable)
		{
			real posZ_0_temp = tempElement_ptr->getPointElementValue_Z();
			real posZ_1_temp = optSysEle.getPosAndElement()[i + 1].getElementInOptSys_ptr()->getPointElementValue_Z();

			variables_vec.push_back(posZ_1_temp - posZ_0_temp);
		}
	}

	return variables_vec;

}

// check if one value in the vector is true
bool oftenUse::checkIf_ONE_valueIsTrue(const std::vector<bool>& vector)
{
	return std::find(vector.begin(), vector.end(), true) != vector.end();
}


bool oftenUse::checkDeltaVariables(OpticalSystemElement optSysEle, std::vector<real> bestValue, real delta)
{
	unsigned int sizeOptSys = optSysEle.getPosAndElement().size();
	real tempValue;
	std::shared_ptr<Element_CR> tempElement_ptr;
	typeModifier tempTypeMode;
	std::vector<bool> checkerVec;

	unsigned int variabelCounter = 0.0;

	for (unsigned int i = 0; i < sizeOptSys; ++i)
	{
		tempElement_ptr = optSysEle.getPosAndElement()[i].getElementInOptSys_ptr();


		// check Radius
		tempTypeMode = tempElement_ptr->getRadiusTypeModifier();
		if (tempTypeMode == typeModifierVariable)
		{
			// check Orientation Radius
			checkerVec.push_back(checkSamePrefixTwoVal(bestValue[variabelCounter], tempElement_ptr->getDirectionElementValue_Z()));


			// check radius in delta
			checkerVec.push_back(std::abs(tempElement_ptr->getRadiusElementValue() - bestValue[variabelCounter]) < delta);

			++variabelCounter;
		}


		// check thickness
		tempTypeMode = tempElement_ptr->getPointTypeModifier_Z();
		if (tempTypeMode == typeModifierVariable)
		{
			real thickness = optSysEle.getPosAndElement()[i + 1].getElementInOptSys_ptr()->getPointElementValue_Z() - tempElement_ptr->getPointElementValue_Z();
			checkerVec.push_back(std::abs(bestValue[variabelCounter] - thickness) < delta);

			++variabelCounter;
		}
	}

	return Math::checkTrueOfVectorElements(checkerVec);
}

// check number for histogram
std::vector<real> oftenUse::makeHistogram(std::vector<real> number_vec, real min, real max, unsigned int sampling)
{
	unsigned int sizeVec = number_vec.size();
	real tempNum;
	bool checker = true;

	std::vector<real> returnVec;
	returnVec.resize(sampling);


	real steps = (max - min) / sampling;
	real initialSteps = steps;
	steps = min + steps;
	unsigned int counter = 0;

	for (unsigned int i = 0; i < sizeVec; ++i)
	{
		tempNum = number_vec[i];

		while (checker)
		{
			if (tempNum <= steps)
			{
				returnVec[counter] = ++returnVec[counter];
				checker = false;
			}
			++counter;
			steps = steps + initialSteps;
		}

		checker = true;
		counter = 0;
		steps = min + initialSteps;
	}

	return returnVec;
}

// check intersectinformations 
bool oftenUse::checkIntersectInfos(const IntersectInformationStruct& intersectInfos, const IntersectInformationStruct& controleIntersectInfos, real tolerance)
{
	std::vector<bool> checkIntersectInfos;

	checkIntersectInfos.push_back(Math::compareTwoVectorStructR3_tolerance(intersectInfos.getIntersectionPoint(), controleIntersectInfos.getIntersectionPoint(), tolerance));
	checkIntersectInfos.push_back(Math::compareTwoVectorStructR3_tolerance(intersectInfos.getNormalUnitVector(), controleIntersectInfos.getNormalUnitVector(), tolerance));
	checkIntersectInfos.push_back(intersectInfos.getSurfaceSide() == controleIntersectInfos.getSurfaceSide());
	checkIntersectInfos.push_back(Math::compareTwoNumbers_tolerance(intersectInfos.getStepsToWalk(), controleIntersectInfos.getStepsToWalk(), tolerance));
	checkIntersectInfos.push_back(Math::compareTwoNumbers_tolerance(intersectInfos.getRefractiveIndex_A(), controleIntersectInfos.getRefractiveIndex_A(), tolerance));
	checkIntersectInfos.push_back(Math::compareTwoNumbers_tolerance(intersectInfos.getRefractiveIndex_B(), controleIntersectInfos.getRefractiveIndex_B(), tolerance));
	checkIntersectInfos.push_back(Math::compareTwoVectorStructR3_tolerance(intersectInfos.getDirectionRayUnit(), controleIntersectInfos.getDirectionRayUnit(), tolerance));
	checkIntersectInfos.push_back(Math::compareTwoNumbers_tolerance(intersectInfos.getLight().getWavelength(), controleIntersectInfos.getLight().getWavelength(), tolerance));
	checkIntersectInfos.push_back(Math::compareTwoNumbers_tolerance(intersectInfos.getLight().getIntensity(), controleIntersectInfos.getLight().getIntensity(), tolerance));
	checkIntersectInfos.push_back(Math::compareTwoNumbers_tolerance(intersectInfos.getLight().getJonesVector().getIa(), controleIntersectInfos.getLight().getJonesVector().getIa(), tolerance));
	checkIntersectInfos.push_back(Math::compareTwoNumbers_tolerance(intersectInfos.getLight().getJonesVector().getIb(), controleIntersectInfos.getLight().getJonesVector().getIb(), tolerance));
	checkIntersectInfos.push_back(Math::compareTwoNumbers_tolerance(intersectInfos.getLight().getJonesVector().getRa(), controleIntersectInfos.getLight().getJonesVector().getRa(), tolerance));
	checkIntersectInfos.push_back(Math::compareTwoNumbers_tolerance(intersectInfos.getLight().getJonesVector().getRb(), controleIntersectInfos.getLight().getJonesVector().getRb(), tolerance));
	checkIntersectInfos.push_back(intersectInfos.getLight().getTypeLight() == controleIntersectInfos.getLight().getTypeLight());

	bool checker = Math::checkTrueOfVectorElements(checkIntersectInfos);
	return checker;

}

// check if all values in a vevtor are less than a specific value
bool oftenUse::checkValInVacLessThan(std::vector<real> vec, real minVal)
{
	unsigned int sizeVec = vec.size();

	for (unsigned int i = 0; i < sizeVec; ++i)
	{
		if (vec[i] < minVal)
		{
			return false;
		}
	}

	return true;
}

// check if average of values in vecor are less than specific value
bool oftenUse::checkAverageOfVecValLessThan(std::vector<real> vec, real minVal)
{
	unsigned int n = vec.size();
	real average{};
	if (n != 0)
	{
		average = std::accumulate(vec.begin(), vec.end(), 0.0) / n;
	}

	return average < minVal;

}
// convert type mode variable to string
std::string oftenUse::convertTypeModeToString(typeModifier typeMode)
{
	switch (typeMode)
	{
	case typeModifierFixed:
		return "F";
		break;
	case typeModifierVariable:
		return "V";
		break;
	case typeModifierPickup:
		return "P";
		break;
	default:
		break;
	}
}

real oftenUse::sum(std::vector<real> vec)
{
	return std::accumulate(vec.begin(), vec.end(), 0.0);
}

bool oftenUse::checkDLS_resultRMS(DLS dls, real tolerance)
{
	OpticalSystemElement optimizedOptSysHLT = dls.getOptimizedSystem_HLT();

	std::vector<real> weight_fields = dls.getWeigthFields();
	std::vector<unsigned int> weight_wavelength = dls.getWeightWavelength();

	objectPoint_inf_obj inf_obj = dls.getInfOrObj();
	real bestMeritValueDLS = dls.getBestMeritValue();
	real sumMeritRMSoptimizedSystem = 0.0;
	real sumMeritTargetCarPoints = 0.0;
	real sumTotalMerit_RMS_TargetCarPoints = 0.0;
	unsigned int rings = dls.getRings();
	unsigned int arms = dls.getArms();
	std::vector<real> wave_vec = dls.getWavelength_vev();
	std::vector<real> wave_vec_resize = resizeWeightWave_vec(wave_vec, weight_wavelength);

	if (dls.getCalcRMSusingRayTracing())
	{
		if (inf_obj == objectPoint_inf_obj::obj)
		{
			std::vector<VectorStructR3> field_vec = dls.getField_vec();

			std::vector<real> allRMS_vec = getRMSoptSysHLT(optimizedOptSysHLT, field_vec, wave_vec_resize, rings, arms);
			allRMS_vec = weightingRMS_fields(allRMS_vec, weight_fields);

			sumMeritRMSoptimizedSystem = sum(allRMS_vec);
		}

		else if (inf_obj == objectPoint_inf_obj::inf)
		{
			std::vector<real> fieldAngle_X = dls.getFieldAngles_X();
			std::vector<real> fieldAngle_Y = dls.getFieldAngle_Y();

			std::vector<real> allRMS_vec = getRMSoptSysHLT(optimizedOptSysHLT, fieldAngle_X, fieldAngle_Y, wave_vec_resize, rings, arms);

			allRMS_vec = weightingRMS_fields(allRMS_vec, weight_fields);

			sumMeritRMSoptimizedSystem = sum(allRMS_vec);
		}
	}

	if (dls.getTargetCardinalPoints().getIsOneTargetCardinalPoint())
	{
		optimizedOptSysHLT.setRefractiveIndexAccordingToWavelength(dls.getWavelength_vev()[0]);

		targetCardinalPointsStruct targetCarPointsDLS;
		targetCarPointsDLS = dls.getTargetCardinalPoints();
		std::vector<real> abberationFct;
		abberationFct.resize(dls.getTargetCardinalPoints().getNumerOfTargets());
		targetCarPointsDLS.calcualteMeritVal_targetCardinalPoints_forDLS(optimizedOptSysHLT.getOptSys_LLT_buildSystem(), inf_obj, abberationFct);
		sumMeritTargetCarPoints = sum(abberationFct);
	}

	sumTotalMerit_RMS_TargetCarPoints = sumMeritRMSoptimizedSystem + sumMeritTargetCarPoints;
	bool returnCheck = std::abs(bestMeritValueDLS - sumTotalMerit_RMS_TargetCarPoints) < tolerance;

	return returnCheck;
}



bool oftenUse::optimizedTargetBetterThanStartCardinalPoint(/*start value*/ real startValue, /*optimized value*/ real optVal, /*target val*/ real targetVal)
{
	real startValVsTargetVal = std::abs(startValue - targetVal);
	real optValVsTargetVal = std::abs(optVal - targetVal);

	return optValVsTargetVal <= startValVsTargetVal;
}

std::vector<real> oftenUse::weightingRMS_fields(std::vector<real> rms_vec, std::vector<real> weightRMS_vec)
{
	std::vector<real> returnWeighedRMS_fields;

	unsigned int sizeRMS_fields = rms_vec.size();
	unsigned int sizeWeight = weightRMS_vec.size();

	if (sizeRMS_fields != sizeWeight)
	{
		std::cout << "ATTENTION: sizeRMS_fields is not sizeWeight" << std::endl;
	}

	returnWeighedRMS_fields.resize(sizeRMS_fields);

	for (unsigned int i = 0; i < sizeRMS_fields; ++i)
	{
		returnWeighedRMS_fields[i] = rms_vec[i] * weightRMS_vec[i];
	}

	return returnWeighedRMS_fields;
}

std::vector<real> oftenUse::resizeWeightWave_vec(std::vector<real> wave_vec, std::vector<unsigned int> weightWave_vec)
{
	std::vector<real> returnWeightWave_vec{};
	unsigned int tempWeight{};
	real tempWavelength{};

	unsigned int size_wave_vec = wave_vec.size();
	unsigned int size_weightWave_vec = weightWave_vec.size();

	if (size_wave_vec != size_weightWave_vec)
	{
		std::cout << "ATTENTION: size_wave_vec is not size_weightWave_vec" << std::endl;
	}

	for (unsigned int i = 0; i < size_wave_vec; ++i)
	{
		tempWeight = weightWave_vec[i];
		tempWavelength = wave_vec[i];

		if (tempWeight == 1)
		{
			returnWeightWave_vec.push_back(tempWavelength);
		}

		else if (tempWeight == 2)
		{
			returnWeightWave_vec.push_back(tempWavelength);
			returnWeightWave_vec.push_back(tempWavelength);
		}

		else if (tempWeight == 3)
		{
			returnWeightWave_vec.push_back(tempWavelength);
			returnWeightWave_vec.push_back(tempWavelength);
			returnWeightWave_vec.push_back(tempWavelength);
		}

		else if (tempWeight == 4)
		{
			returnWeightWave_vec.push_back(tempWavelength);
			returnWeightWave_vec.push_back(tempWavelength);
			returnWeightWave_vec.push_back(tempWavelength);
			returnWeightWave_vec.push_back(tempWavelength);
		}

		else if (tempWeight == 5)
		{
			returnWeightWave_vec.push_back(tempWavelength);
			returnWeightWave_vec.push_back(tempWavelength);
			returnWeightWave_vec.push_back(tempWavelength);
			returnWeightWave_vec.push_back(tempWavelength);
			returnWeightWave_vec.push_back(tempWavelength);
		}

		else if (tempWeight == 6)
		{
			returnWeightWave_vec.push_back(tempWavelength);
			returnWeightWave_vec.push_back(tempWavelength);
			returnWeightWave_vec.push_back(tempWavelength);
			returnWeightWave_vec.push_back(tempWavelength);
			returnWeightWave_vec.push_back(tempWavelength);
			returnWeightWave_vec.push_back(tempWavelength);
		}

		else if (tempWeight == 7)
		{
			returnWeightWave_vec.push_back(tempWavelength);
			returnWeightWave_vec.push_back(tempWavelength);
			returnWeightWave_vec.push_back(tempWavelength);
			returnWeightWave_vec.push_back(tempWavelength);
			returnWeightWave_vec.push_back(tempWavelength);
			returnWeightWave_vec.push_back(tempWavelength);
			returnWeightWave_vec.push_back(tempWavelength);
		}

		else if (tempWeight == 8)
		{
			returnWeightWave_vec.push_back(tempWavelength);
			returnWeightWave_vec.push_back(tempWavelength);
			returnWeightWave_vec.push_back(tempWavelength);
			returnWeightWave_vec.push_back(tempWavelength);
			returnWeightWave_vec.push_back(tempWavelength);
			returnWeightWave_vec.push_back(tempWavelength);
			returnWeightWave_vec.push_back(tempWavelength);
			returnWeightWave_vec.push_back(tempWavelength);
		}

		else if (tempWeight == 9)
		{
			returnWeightWave_vec.push_back(tempWavelength);
			returnWeightWave_vec.push_back(tempWavelength);
			returnWeightWave_vec.push_back(tempWavelength);
			returnWeightWave_vec.push_back(tempWavelength);
			returnWeightWave_vec.push_back(tempWavelength);
			returnWeightWave_vec.push_back(tempWavelength);
			returnWeightWave_vec.push_back(tempWavelength);
			returnWeightWave_vec.push_back(tempWavelength);
			returnWeightWave_vec.push_back(tempWavelength);
		}

		else if (tempWeight == 10)
		{
			returnWeightWave_vec.push_back(tempWavelength);
			returnWeightWave_vec.push_back(tempWavelength);
			returnWeightWave_vec.push_back(tempWavelength);
			returnWeightWave_vec.push_back(tempWavelength);
			returnWeightWave_vec.push_back(tempWavelength);
			returnWeightWave_vec.push_back(tempWavelength);
			returnWeightWave_vec.push_back(tempWavelength);
			returnWeightWave_vec.push_back(tempWavelength);
			returnWeightWave_vec.push_back(tempWavelength);
			returnWeightWave_vec.push_back(tempWavelength);
		}

		else
		{
			std::cout << "ATTENTION: the returnWeightWave_vec could not be initilized" << std::endl;
		}
	}

	return returnWeightWave_vec;
}

// get default values for DLS optimization
defaultParaDLS oftenUse::getDefaultPara_DLS(bool rayTracing)
{

	defaultParaDLS defaultParamDLS;
	defaultParamDLS.setDampingFactor(5.0);
	defaultParamDLS.setFactorRadiusDeviation(0.000001);
	defaultParamDLS.setFactorPositionDeviation(0.000001);
	defaultParamDLS.setStartRefractivIndex(1.0);
	defaultParamDLS.setMaxWorstCounter(300);
	defaultParamDLS.setImproveMeritStopDiff(0.00000001);
	defaultParamDLS.setMaxInterations(500);
	defaultParamDLS.setFlipOrientationRadius(1000.0);
	defaultParamDLS.setMaxBorderViolations(5);
	defaultParamDLS.setMaxDeltaParameter(25.0);
	defaultParamDLS.setMinDeltaParameter(0.00000001);
	defaultParamDLS.setFactorGettingBetter(0.4);
	defaultParamDLS.setFactorGettingWorst(1.9);
	defaultParamDLS.setToleranceWithoutMin(0.0);
	defaultParamDLS.setToleranceWithoutMax(0.0);
	defaultParamDLS.set_Min_DamNumBefSwitchFactors(0.00001);
	defaultParamDLS.set_Max_DamNumBefSwitchFactors(9999.0);

	if (rayTracing)
	{
		defaultParamDLS.turn_ON_calcRMSusingRayTracing();
	}


	else
	{
		defaultParamDLS.turn_OFF_caclRMSusingRayTracing();
	}

	return defaultParamDLS;

}

// get default values for genetic optimisation
defaultParaGenetic oftenUse::getDafulatPara_Genetic(bool rayTracing)
{
	defaultParaGenetic defaultParaGenetic_rayTracing;
	defaultParaGenetic_rayTracing.setStartRefIndex(1.0);
	defaultParaGenetic_rayTracing.setToleranceWithoutMIN(-0.5);
	defaultParaGenetic_rayTracing.setToleranceWithoutMAX(0.5);
	defaultParaGenetic_rayTracing.setMaxInterationGenetic(3);
	defaultParaGenetic_rayTracing.setDeltaMeritValueStop(0.1);
	defaultParaGenetic_rayTracing.setToleranceForEvaluation(0.001);
	defaultParaGenetic_rayTracing.setChooseValueMode(normalDistributionDefaultMode);

	if (rayTracing)
	{
		defaultParaGenetic_rayTracing.set_ON_CheckRMS_rayTracing();
	}

	else
	{
		defaultParaGenetic_rayTracing.set_OFF_CheckRMS_rayTracing();
	}

	return defaultParaGenetic_rayTracing;

}


std::string oftenUse::replacePointByComma(std::string inputString)
{

	unsigned int size = inputString.size();
	char tempChar{};
	std::string exportString;
	exportString.resize(size);

	for (unsigned int i = 0; i < size; ++i)
	{
		tempChar = inputString[i];

		if (tempChar == '.')
		{
			tempChar = ',';
		}

		exportString[i] = tempChar;
	}

	return exportString;
}

// check for nan in VectorStructR3
bool oftenUse::checkFor_No_Nan(VectorStructR3 vec)
{
	return std::isnan(vec.getX()) == false && std::isnan(vec.getY()) == false && std::isnan(vec.getZ()) == false;
}

// error protocol
void oftenUse::errorProtocol_stopSystem(/*error*/ std::string error, /*location*/ std::string location, /*error number*/ unsigned int errorNumber, /*stop program*/ bool stopProgram)
{
	std::string locationErrorProtocol = "../ErrorProtocol/";
	std::string nameTXT = "errorProtocol";

	std::string errorAndLocation = error + " <---> location of error: " + location;

	inportExportData::saveStringInTXT_includingTime(locationErrorProtocol, nameTXT, error);

	if (errorNumber == 0)
	{
		std::cout << errorAndLocation << std::endl;

		int i;
		std::cout << "insert a rendom number" << std::endl;
		std::cin >> i;
	}

	if (stopProgram) exit(EXIT_SUCCESS);
}

bool oftenUse::checkForEvenNumber(int number)
{
	if (number % 2 == 0) return true;

	return false;
}

bool oftenUse::checkForOddNumber(int number)
{
	if (number % 2 == 0) return false;

	return true;
}

// get start refractiv index
real oftenUse::getStartRefIndex(OpticalSystem_LLT optSys_LLT)
{
	real curRefracIndex;
	real directionZFirstSurface = optSys_LLT.getPosAndInteractingSurface()[0].getSurfaceInterRay_ptr()->getDirection().getZ();
	if (directionZFirstSurface > 0)
	{
		curRefracIndex = optSys_LLT.getPosAndInteractingSurface()[0].getSurfaceInterRay_ptr()->getRefractiveIndex_A();
	}
	else if (directionZFirstSurface < 0)
	{
		curRefracIndex = optSys_LLT.getPosAndInteractingSurface()[0].getSurfaceInterRay_ptr()->getRefractiveIndex_B();
	}
	else
	{
		oftenUse::errorProtocol_stopSystem("direction first surface is zero", "oftenUseNamespace.cpp", 0, true);
	}

	return curRefracIndex;
}

LightRayStruct oftenUse::findMarginalRay_inf(OpticalSystemElement optSysEle, real primWavelength, Light_LLT light)
{
	infosAS infosAperStop = optSysEle.getInfoAS();
	VectorStructR3 targetPointMarginal = infosAperStop.getPointAS();
	targetPointMarginal.setY(infosAperStop.getSemiHeightAS());

	optSysEle.setRefractiveIndexAccordingToWavelength(primWavelength);

	RayAiming rayAim;
	LightRayStruct marginalLightRay = rayAim.rayAimingMany_inf_complete(optSysEle.getLLTconversion_doConversion(), targetPointMarginal, 0.0, 0.0, light);

	return marginalLightRay;
}


LightRayStruct oftenUse::findChiefRay_inf(OpticalSystemElement optSysEle, real primWavelength, real maxAngelY, Light_LLT light)
{
	infosAS infosAperStop = optSysEle.getInfoAS();
	optSysEle.setRefractiveIndexAccordingToWavelength(primWavelength);

	RayAiming rayAim;
	rayAim.loadDefaultParameter();
	rayAim.setLoadImportantDefaulParameterRayAiming(false);
	rayAim.setTolerance_XandY(0.0000000001);
	LightRayStruct chiefLightRay = rayAim.rayAimingMany_inf_complete(optSysEle.getLLTconversion_doConversion(), infosAperStop.getPointAS(), 0.0, maxAngelY, light);

	return chiefLightRay;
}

LightRayStruct oftenUse::findMarginalRay_obj(OpticalSystemElement optSysEle, real primWavelength, Light_LLT light)
{
	infosAS infoAperStop = optSysEle.getInfoAS();
	VectorStructR3 targetPointMarginal = infoAperStop.getPointAS();
	targetPointMarginal.setY(infoAperStop.getSemiHeightAS());
	std::vector<VectorStructR3> targetPointMarginal_vec = { targetPointMarginal };

	optSysEle.setRefractiveIndexAccordingToWavelength(primWavelength);

	RayAiming rayAim;
	rayAim.loadDefaultParameter();
	rayAim.setLoadImportantDefaulParameterRayAiming(false);
	rayAim.setTolerance_XandY(0.0000000001);

	VectorStructR3 startPoint = { 0.0,0.0,0.0 };
	std::vector<LightRayStruct> marginalLightRay_obj_vec = rayAim.rayAimingMany_obj_complete(optSysEle.getLLTconversion_doConversion(), targetPointMarginal_vec, startPoint, light);

	return marginalLightRay_obj_vec[0];
}

LightRayStruct oftenUse::findChiefRay_obj(OpticalSystemElement optSysEle, real primWavelength, VectorStructR3 maxStartPoint, Light_LLT light)
{
	infosAS infoAperStop = optSysEle.getInfoAS();
	VectorStructR3 targetPointChief = infoAperStop.getPointAS();
	std::vector<VectorStructR3> targetPointChief_vec = { targetPointChief };

	optSysEle.setRefractiveIndexAccordingToWavelength(primWavelength);

	RayAiming rayAim;
	rayAim.loadDefaultParameter();
	rayAim.setLoadImportantDefaulParameterRayAiming(false);
	rayAim.setTolerance_XandY(0.0000000001);

	std::vector<LightRayStruct> chiefLightRay_obj_vec = rayAim.rayAimingMany_obj_complete(optSysEle.getLLTconversion_doConversion(), targetPointChief_vec, maxStartPoint, light);

	return chiefLightRay_obj_vec[0];
}


// find lenses in optical system
std::vector<OpticalSystem_LLT> oftenUse::findLensesInOptSys_LLT(OpticalSystem_LLT optSys_LLT)
{
	std::vector<OpticalSystem_LLT> optSys_lenses_LLT_vec;
	real tolerance = 0.0001;

	OpticalSystem_LLT tempOptSys_lens_LLT;

	unsigned sizeOptSys = optSys_LLT.getPosAndInteractingSurface().size();

	// surfaces before
	std::shared_ptr<SurfaceIntersectionRay_LLT> Surface_ptr_before = optSys_LLT.getPosAndInteractingSurface()[0].getSurfaceInterRay_ptr();
	real direction_Z_before = Surface_ptr_before->getDirection().getZ();
	real refIndex_A_before = Surface_ptr_before->getRefractiveIndex_A();
	real refIndex_B_before = Surface_ptr_before->getRefractiveIndex_B();

	unsigned int tempPos;

	if (std::abs(refIndex_A_before - 1.0) > tolerance || std::abs(refIndex_B_before - 1.0) > tolerance)
	{
		tempPos = optSys_LLT.getPosAndInteractingSurface()[0].getPosition();
		tempOptSys_lens_LLT.fillVectorSurfaceAndInteractingData(tempPos, Surface_ptr_before, optSys_LLT.getPosAndInteraction()[0].getInteractionAtSur_ptr());
	}

	// surfaces after
	std::shared_ptr<SurfaceIntersectionRay_LLT> Surface_ptr_temp;
	real direction_Z_temp;
	real refIndex_A_temp;
	real refIndex_B_temp;

	bool isThereALens = true;
	unsigned int sizeTempLens;
	std::shared_ptr<InteractionRay_LLT> Interaction_ptr_temp;
	real refIndexSurMat = oftenUse::getStartRefIndex(optSys_LLT);

	for (unsigned int i = 1; i < sizeOptSys; ++i)
	{
		tempPos = optSys_LLT.getPosAndInteractingSurface()[i].getPosition();
		Surface_ptr_temp = optSys_LLT.getPosAndInteractingSurface()[i].getSurfaceInterRay_ptr();
		direction_Z_temp = Surface_ptr_temp->getDirection().getZ();
		refIndex_A_temp = Surface_ptr_temp->getRefractiveIndex_A();
		refIndex_B_temp = Surface_ptr_temp->getRefractiveIndex_B();

		Interaction_ptr_temp = optSys_LLT.getPosAndInteraction()[i].getInteractionAtSur_ptr();

		// lens type 0
		if (direction_Z_before > 0 && direction_Z_temp < 0)
		{
			if ((refIndex_B_before - refIndexSurMat) < tolerance && (refIndex_B_temp - refIndexSurMat) < tolerance && tempOptSys_lens_LLT.getPosAndInteractingSurface().size() > 0) // there is no lens
			{
				optSys_lenses_LLT_vec.push_back(tempOptSys_lens_LLT);
				tempOptSys_lens_LLT.clean_optSys_LLT();
			}

			if (std::abs(refIndex_B_before - refIndex_B_temp) < tolerance) // there is a lens
			{
				sizeTempLens = tempOptSys_lens_LLT.getPosAndInteractingSurface().size();
				tempOptSys_lens_LLT.fillVectorSurfaceAndInteractingData(tempPos, Surface_ptr_temp, Interaction_ptr_temp);
			}
		}

		// lens type 1
		else if (direction_Z_before < 0 && direction_Z_temp < 0)
		{
			if ((refIndex_A_before - refIndexSurMat) < tolerance && (refIndex_B_temp - refIndexSurMat) < tolerance && tempOptSys_lens_LLT.getPosAndInteractingSurface().size() > 0) // there is no lens
			{
				optSys_lenses_LLT_vec.push_back(tempOptSys_lens_LLT);
				tempOptSys_lens_LLT.clean_optSys_LLT();
			}

			if (std::abs(refIndex_A_before - refIndex_B_temp) < tolerance) // there is a lens
			{
				sizeTempLens = tempOptSys_lens_LLT.getPosAndInteractingSurface().size();
				tempOptSys_lens_LLT.fillVectorSurfaceAndInteractingData(tempPos, Surface_ptr_temp, Interaction_ptr_temp);
			}

		}

		// lens type 2
		else if (direction_Z_before > 0 && direction_Z_temp > 0)
		{
			if ((refIndex_B_before - refIndexSurMat) < tolerance && (refIndex_A_temp - refIndexSurMat) < tolerance && tempOptSys_lens_LLT.getPosAndInteractingSurface().size() > 0) // there is no lens
			{
				optSys_lenses_LLT_vec.push_back(tempOptSys_lens_LLT);
				tempOptSys_lens_LLT.clean_optSys_LLT();
			}

			if (std::abs(refIndex_B_before - refIndex_A_temp) < tolerance) // there is a lens
			{
				sizeTempLens = tempOptSys_lens_LLT.getPosAndInteractingSurface().size();
				tempOptSys_lens_LLT.fillVectorSurfaceAndInteractingData(tempPos, Surface_ptr_temp, Interaction_ptr_temp);
			}

		}

		// lens type 3
		else if (direction_Z_before < 0 && direction_Z_temp > 0)
		{
			if ((refIndex_A_before - refIndexSurMat) < tolerance && (refIndex_A_temp - refIndexSurMat) < tolerance && tempOptSys_lens_LLT.getPosAndInteractingSurface().size() > 0) // there is no lens
			{
				optSys_lenses_LLT_vec.push_back(tempOptSys_lens_LLT);
				tempOptSys_lens_LLT.clean_optSys_LLT();
			}

			if (std::abs(refIndex_A_before - refIndex_A_temp) < tolerance) // there is a lens
			{
				sizeTempLens = tempOptSys_lens_LLT.getPosAndInteractingSurface().size();
				tempOptSys_lens_LLT.fillVectorSurfaceAndInteractingData(tempPos, Surface_ptr_temp, Interaction_ptr_temp);
			}

		}

		// surfaces before
		Surface_ptr_before = Surface_ptr_temp;
		direction_Z_before = direction_Z_temp;
		refIndex_A_before = refIndex_A_temp;
		refIndex_B_before = refIndex_B_temp;

	}

	if (optSys_lenses_LLT_vec.size() == 0)
	{
		optSys_lenses_LLT_vec.push_back(tempOptSys_lens_LLT);
	}

	return optSys_lenses_LLT_vec;
}

std::vector<OpticalSystem_LLT> oftenUse::findLensesInOptSysEle(OpticalSystemElement optSysEle)
{
	optSysEle.setRefractiveIndexAccordingToWavelength(550.0);
	OpticalSystem_LLT optSysLLT = optSysEle.getLLTconversion_doConversion();

	return findLensesInOptSys_LLT(optSysLLT);
}

// compare two optical systems LLT
bool oftenUse::compareTwoOpticalSystemsSurfaces(OpticalSystemElement optSysEle1, OpticalSystemElement optSysEle2, real tolerance)
{
	real waveLength = 550.0;

	optSysEle1.setRefractiveIndexAccordingToWavelength(waveLength);
	optSysEle2.setRefractiveIndexAccordingToWavelength(waveLength);

	OpticalSystem_LLT optSys1 = optSysEle1.getLLTconversion_doConversion();
	OpticalSystem_LLT optSys2 = optSysEle2.getLLTconversion_doConversion();

	std::vector<bool> opticalSystemsSame_vec;

	real tempRadius1;
	real tempOriginX1;
	real tempOriginY1;
	real tempOriginZ1;
	real tempDirectionX1;
	real tempDirectionY1;
	real tempDirectionZ1;
	real tempRefIndexA1;
	real tempRefIndexB1;

	real tempRadius2;
	real tempOriginX2;
	real tempOriginY2;
	real tempOriginZ2;
	real tempDirectionX2;
	real tempDirectionY2;
	real tempDirectionZ2;
	real tempRefIndexA2;
	real tempRefIndexB2;

	bool checkRadius;
	bool checkOriginX;
	bool checkOriginY;
	bool checkOriginZ;
	bool checkDirectionX;
	bool checkDirectionY;
	bool checkDirectionZ;
	bool checkRefIndexA;
	bool checkRefIndexB;

	unsigned int sizeOptSys1 = optSys1.getPosAndInteractingSurface().size();
	unsigned int sizeOptSys2 = optSys2.getPosAndInteractingSurface().size();

	bool checkSizeOptSys = Math::compareTwoNumbers_tolerance(sizeOptSys1, sizeOptSys2, tolerance);
	opticalSystemsSame_vec.push_back(checkSizeOptSys);

	if (checkSizeOptSys)
	{
		for (unsigned int i = 0; i < sizeOptSys1; ++i)
		{
			// data optSys1
			tempRadius1 = optSys1.getPosAndInteractingSurface()[i].getSurfaceInterRay_ptr()->getRadius();
			tempOriginX1 = optSys1.getPosAndInteractingSurface()[i].getSurfaceInterRay_ptr()->getPoint().getX();
			tempOriginY1 = optSys1.getPosAndInteractingSurface()[i].getSurfaceInterRay_ptr()->getPoint().getY();
			tempOriginZ1 = optSys1.getPosAndInteractingSurface()[i].getSurfaceInterRay_ptr()->getPoint().getZ();
			tempDirectionX1 = optSys1.getPosAndInteractingSurface()[i].getSurfaceInterRay_ptr()->getDirection().getX();
			tempDirectionY1 = optSys1.getPosAndInteractingSurface()[i].getSurfaceInterRay_ptr()->getDirection().getY();
			tempDirectionZ1 = optSys1.getPosAndInteractingSurface()[i].getSurfaceInterRay_ptr()->getDirection().getZ();
			tempRefIndexA1 = optSys1.getPosAndInteractingSurface()[i].getSurfaceInterRay_ptr()->getRefractiveIndex_A();
			tempRefIndexB1 = optSys1.getPosAndInteractingSurface()[i].getSurfaceInterRay_ptr()->getRefractiveIndex_B();

			tempRadius2 = optSys2.getPosAndInteractingSurface()[i].getSurfaceInterRay_ptr()->getRadius();
			tempOriginX2 = optSys2.getPosAndInteractingSurface()[i].getSurfaceInterRay_ptr()->getPoint().getX();
			tempOriginY2 = optSys2.getPosAndInteractingSurface()[i].getSurfaceInterRay_ptr()->getPoint().getY();
			tempOriginZ2 = optSys2.getPosAndInteractingSurface()[i].getSurfaceInterRay_ptr()->getPoint().getZ();
			tempDirectionX2 = optSys2.getPosAndInteractingSurface()[i].getSurfaceInterRay_ptr()->getDirection().getX();
			tempDirectionY2 = optSys2.getPosAndInteractingSurface()[i].getSurfaceInterRay_ptr()->getDirection().getY();
			tempDirectionZ2 = optSys2.getPosAndInteractingSurface()[i].getSurfaceInterRay_ptr()->getDirection().getZ();
			tempRefIndexA2 = optSys2.getPosAndInteractingSurface()[i].getSurfaceInterRay_ptr()->getRefractiveIndex_A();
			tempRefIndexB2 = optSys2.getPosAndInteractingSurface()[i].getSurfaceInterRay_ptr()->getRefractiveIndex_B();

			checkRadius = Math::compareTwoNumbers_tolerance(tempRadius1, tempRadius2, tolerance);
			checkOriginX = Math::compareTwoNumbers_tolerance(tempOriginX1, tempOriginX2, tolerance);
			checkOriginY = Math::compareTwoNumbers_tolerance(tempOriginY1, tempOriginY2, tolerance);
			checkOriginZ = Math::compareTwoNumbers_tolerance(tempOriginZ1, tempOriginZ2, tolerance);
			checkDirectionX = Math::compareTwoNumbers_tolerance(tempDirectionX1, tempDirectionX2, tolerance);
			checkDirectionY = Math::compareTwoNumbers_tolerance(tempDirectionY1, tempDirectionY2, tolerance);
			checkDirectionZ = Math::compareTwoNumbers_tolerance(tempDirectionZ1, tempDirectionZ2, tolerance);
			checkRefIndexA = Math::compareTwoNumbers_tolerance(tempRefIndexA1, tempRefIndexA2, tolerance);
			checkRefIndexB = Math::compareTwoNumbers_tolerance(tempRefIndexB1, tempRefIndexB2, tolerance);

			opticalSystemsSame_vec.push_back(checkRadius);
			opticalSystemsSame_vec.push_back(checkOriginX);
			opticalSystemsSame_vec.push_back(checkOriginY);
			opticalSystemsSame_vec.push_back(checkOriginZ);
			opticalSystemsSame_vec.push_back(checkDirectionX);
			opticalSystemsSame_vec.push_back(checkDirectionY);
			opticalSystemsSame_vec.push_back(checkDirectionZ);
			opticalSystemsSame_vec.push_back(checkRefIndexA);
			opticalSystemsSame_vec.push_back(checkRefIndexB);
	
		}

	}

	bool returnChecker = Math::checkTrueOfVectorElements(opticalSystemsSame_vec);
	return returnChecker;
}


// get max start point 
VectorStructR3 oftenUse::getMaxStartPoint(VectorStructR3 referencePoint, std::vector<VectorStructR3> startPointVec)
{
	real tempDistance{};
	real maxDistance = -1.0 * getInfReal();
	int posMax = 0;
	unsigned int sizeVec = startPointVec.size();
	for (unsigned int i = 0; i < sizeVec; i++)
	{
		tempDistance = Math::distanceTwoVectors(referencePoint, startPointVec[i]);
		if (tempDistance > maxDistance)
		{
			maxDistance = tempDistance;
			posMax = i;
		}
	}

	return startPointVec[posMax];
	
}

// calculate faculty
int oftenUse::calcFacultyInt(unsigned int value)
{
	int factorial = 1.0;

	if (value < 0)
	{
		std::cout << "Error! Factorial of a negative number doesn't exist.";
	}
	else
	{
		for (int i = 1; i <= value; ++i)
		{
			factorial *= i;
		}
	}

	return factorial;
}

// calculate all possible sequences int
std::vector<std::vector<unsigned int>> oftenUse::calcAllPossibleSequencesInt(std::vector<unsigned int> vec)
{
	std::sort(vec.begin(), vec.end());
	std::vector<std::vector<unsigned int>> allPossibleSequencesInt;
	int factorial = calcFacultyInt(vec.size());
	allPossibleSequencesInt.resize(factorial);

	for(unsigned int i = 0; i< allPossibleSequencesInt.size(); ++i)
	{
		allPossibleSequencesInt[i] = vec;
		std::next_permutation(vec.begin(), vec.end());
	}

	return allPossibleSequencesInt;
}

// check refractiv index 
bool oftenUse::checkRefractivIndex(OpticalSystem_LLT optSyeLLT)
{
	real tolerance = 0.01;
	unsigned int sizeOptSysMinOne = optSyeLLT.getPosAndInteractingSurface().size() - 1;
	std::shared_ptr<SurfaceIntersectionRay_LLT> tempSurface_ptr;
	std::shared_ptr<SurfaceIntersectionRay_LLT> tempSurface_ptr_next;

	real tempDirectionZ{};
	real tempDirectionZ_Next{};
	real tempRefIndex{};
	real tempRefIndexNext{};
	real tempRefIndex_A{};
	real tempRefIndex_B{};
	real tempRefIndexNext_A{};
	real tempRefIndexNext_B{};

	std::vector<bool> workTheSystem{};
	workTheSystem.resize(sizeOptSysMinOne);
	bool tempChecker{};
	for (unsigned int i = 0; i < sizeOptSysMinOne; ++i)
	{
		tempSurface_ptr = optSyeLLT.getPosAndInteractingSurface()[i].getSurfaceInterRay_ptr();
		tempSurface_ptr_next = optSyeLLT.getPosAndInteractingSurface()[i+1].getSurfaceInterRay_ptr();
		
		tempDirectionZ = tempSurface_ptr->getDirection().getZ();
		tempDirectionZ_Next = tempSurface_ptr_next->getDirection().getZ();
		
		tempRefIndex_A = tempSurface_ptr->getRefractiveIndex_A();
		tempRefIndex_B = tempSurface_ptr->getRefractiveIndex_B();
		tempRefIndexNext_A = tempSurface_ptr_next->getRefractiveIndex_A();
		tempRefIndexNext_B = tempSurface_ptr_next->getRefractiveIndex_B();

		if (tempDirectionZ > 0.0 && tempDirectionZ_Next > 0.0)
		{
			tempChecker = std::abs(tempRefIndex_B - tempRefIndexNext_A) < tolerance;
			workTheSystem[i] = tempChecker;
		}

		else if (tempDirectionZ < 0.0 && tempDirectionZ_Next < 0.0)
		{
			tempChecker = std::abs(tempRefIndex_A - tempRefIndexNext_B) < tolerance;
			workTheSystem[i] = tempChecker;
		}

		else if (tempDirectionZ > 0.0 && tempDirectionZ_Next < 0.0)
		{
			tempChecker = std::abs(tempRefIndex_B - tempRefIndexNext_B) < tolerance;
			workTheSystem[i] = tempChecker;
		}

		else if (tempDirectionZ < 0.0 && tempDirectionZ_Next > 0.0)
		{
			tempChecker = std::abs(tempRefIndex_A - tempRefIndexNext_A) < tolerance;
			workTheSystem[i] = tempChecker;
		}

		else
		{
			errorProtocol_stopSystem("The optical system is not possible", "oftenUseNamespace.cpp", 0, true);
		}
	}

	bool returnChecker = Math::checkTrueOfVectorElements(workTheSystem);
	return returnChecker;
}

bool oftenUse::checkRefractivIndex(OpticalSystemElement optSyeEle)
{
	optSyeEle.setRefractiveIndexAccordingToWavelength(550.0);
	OpticalSystem_LLT optSysLLT = optSyeEle.getLLTconversion_doConversion();

	return checkRefractivIndex(optSysLLT);
}