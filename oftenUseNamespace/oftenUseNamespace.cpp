#include "oftenUseNamespace.h"

//#include "..\SequentialRayTracing\SequentialRayTracer.h"
#include "..\RayAiming\RayAiming.h"
//#define unsignedInt_INF (unsigned)!((int)0)

bool oftenUse::checkRayTracing(VectorStructR3 startPoint, VectorStructR3 direction, VectorStructR3 targetPoint, OpticalSystem_LLT optSys_LLT, unsigned int surfaceNum, real tolerande)
{
	SequentialRayTracing seqTrace(optSys_LLT);
	// ray
	Ray_LLT ray(startPoint, direction, 1.0);
	// light
	Light_LLT light;
	light.setWavelength(550.0);
	light.setIsAlive(1);
	light.setIntensity(1.0);
	// light ray
	LightRayStruct lightRay(light, ray, 1.0);
	// ray tracing
	seqTrace.sequentialRayTracing(lightRay);
	
	VectorStructR3 intersecPoint = seqTrace.getAllInterPointsAtSurf_i(surfaceNum)[0];

	bool checker = Math::compareTwoVectorStructR3_tolerance(intersecPoint, targetPoint, tolerande);

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

// get very height number
real oftenUse::getInfReal() { return std::numeric_limits<real>::infinity(); };
float oftenUse::getInfFloat() { return std::numeric_limits<float>::infinity(); };
int oftenUse::getInfInt() { return std::numeric_limits<int>::infinity(); };
//unsigned int oftenUse::getInfUnsignedInt() { return unsignedInt_INF; };

// check if two values have the same prefix
bool oftenUse::checkSamePrefixTwoVal(real v1, real v2)
{
	if (v1 > 0 & v2 < 0 || v1 < 0 & v2>0)
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
	typeLight defaultLightType = typeLightRay;
	int defaultIsAlive = 1;

	Light_LLT defaultLight(/*wavelength*/ wavelength, /*intensity*/ defaultIntensity,/*polarisation*/defaultPolarisation,/*light type*/ defaultLightType,/*is alive*/ defaultIsAlive);

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

	for(unsigned int i = 0; i<numberWavelengths; ++i)
	{
		tempLight = oftenUse::buildDefaultLight(wavelength_vec[i]);
		returnLight_LLT_vec[i] = tempLight;
	}

	return returnLight_LLT_vec;
}

bool oftenUse::checkOptSysELement_Equal_Better_Zemax(OpticalSystemElement optimizedSystemHLT, std::vector<VectorStructR3> fieldPoints, std::vector<real> wavelength_vec, std::vector<real> rmsValZemax, real tolerance, compareTOM_Zemax compare)
{
	bool check_Equal_Better_Zemax{};
	
	unsigned int defaultRings = 6;
	unsigned int defaultArms = 8;
	real defaultRefractivIndex = 1.0;
	
	unsigned int posLastSurface = optimizedSystemHLT.getPosAndElement().size() - 1;

	unsigned int numFieldPoints = fieldPoints.size();
	unsigned int numRMS_ValZemax = rmsValZemax.size();
	unsigned int numWavelengths = wavelength_vec.size();

	std::vector<Light_LLT> lightVec = oftenUse::buildDefaultLight_Vec(wavelength_vec);

	// check if number field points is equal to rms values from zemax
	if (numFieldPoints != numRMS_ValZemax)
	{
		std::cout << "number of evaluated field does not match to the number of evaluated rms values" << std::endl;
		check_Equal_Better_Zemax = false;
	}

	SequentialRayTracing tempSeqTrace;
	VectorStructR3 tempFieldPoint{};
	real tempWavelength;


	RayAiming tempRayAiming;
	FillApertureStop FillApertureStop(optimizedSystemHLT.getOptSys_LLT_buildSystem(), defaultRings, defaultArms);
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
			tempSeqTrace.setTraceToSurface(6);
			tempSeqTrace.seqRayTracingWithVectorOfLightRays(tempLightRay_vec);

			tempInterPoints = tempSeqTrace.getAllInterPointsAtSurf_i(posLastSurface);

			saveAllInterPoints.insert(saveAllInterPoints.end(), tempInterPoints.begin(), tempInterPoints.end());
		
			tempSeqTrace.clearAllTracedRays();
		
		}
		

		// calc rms spot
		Spot tempSpot(saveAllInterPoints, saveAllInterPoints[0]);
		allRMS[i] = tempSpot.getRMS_µm();

		saveAllInterPoints.clear();

	}

	
	if (compare == comEqual)
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

			tempChecker = Math::compareTwoNumbers_tolerance(tempRMS_TOM, tempRMS_Z, tolerance);
			checker[i] = tempChecker;

		}

		check_Equal_Better_Zemax = Math::checkTrueOfVectorElements(checker);
	}

	else if (compare == comBetter)
	{
		real sumRMS_TOM = Math::sumAllVectorValues(allRMS);
		real sumRMS_Z = Math::sumAllVectorValues(rmsValZemax);

		check_Equal_Better_Zemax = (sumRMS_TOM - sumRMS_Z) < tolerance;
	}



	

	return check_Equal_Better_Zemax;
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
	real defaultRefractivIndex = 1.0;

	unsigned int posLastSurface = optSys_LLT.getPosAndInteractingSurface().size() - 1;

	unsigned int numFieldPoints = fieldPoints.size();
	unsigned int numRMS_ValZemax = rmsValZemax.size();

	// check if number field points is equal to rms values from zemax
	if (numFieldPoints != numRMS_ValZemax)
	{
		std::cout << "number of evaluated field does not match to the number of evaluated rms values" << std::endl;
		check_Equal_Better_Zemax = false;
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
		
		tempLightRay_vec = tempRayAiming.rayAimingMany_obj(FillApertureStop.getPointsInAS(), tempFieldPoint, defaultLight, defaultRefractivIndex);

		tempSeqTrace.seqRayTracingWithVectorOfLightRays(tempLightRay_vec);

		tempInterPoints = tempSeqTrace.getAllInterPointsAtSurf_i(posLastSurface);

		// calc rms spot
		allRMS[i] = tempSpot.calcRMS(tempInterPoints, tempInterPoints[0]) * 1000;

		tempSeqTrace.clearAllTracedRays();

	}

	if (compare == comEqual)
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

			tempChecker = Math::compareTwoNumbers_tolerance(tempRMS_TOM, tempRMS_Z, tolerance);
			checker[i] = tempChecker;

		}

		check_Equal_Better_Zemax = Math::checkTrueOfVectorElements(checker);
	}

	else if (compare == comBetter)
	{
		real sumRMS_TOM = Math::sumAllVectorValues(allRMS);
		real sumRMS_Z = Math::sumAllVectorValues(rmsValZemax);

		check_Equal_Better_Zemax = (sumRMS_TOM - sumRMS_Z) < tolerance;
	}





	return check_Equal_Better_Zemax;



}