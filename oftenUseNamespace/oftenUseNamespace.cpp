#include "oftenUseNamespace.h"
#include <limits>
#include "..\..\Inport_Export_Data\Inport_Export_Data.h"

#include "..\SequentialRayTracing\SequentialRayTracer.h"
#include "..\RayAiming\RayAiming.h"
#include "..\FillAptertureStop\FillApertureStop.h"
//#define unsignedInt_INF (unsigned)!((int)0)

bool oftenUse::checkRayTracing(VectorStructR3 startPoint, VectorStructR3 direction, VectorStructR3 targetPoint, OpticalSystem_LLT optSys_LLT, unsigned int surfaceNum, real tolerande)
{
	SequentialRayTracing seqTrace(optSys_LLT);
	// ray
	Ray_LLT ray(startPoint, direction, 1.0);
	// light
	Light_LLT mLight;
	mLight.setWavelength(550.0);
	mLight.setIntensity(1.0);
	mLight.setJonesVector({ 1.0,1.0,1.0,1.0 });
	mLight.setTypeLight(typeLightRay);
	// light ray
	LightRayStruct lightRay(mLight, ray, 1.0);
	// ray tracing
	seqTrace.sequentialRayTracing(lightRay);
	
	VectorStructR3 intersecPoint = seqTrace.getAllInterPointsAtSurf_i_notFiltered(surfaceNum)[0];

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

void oftenUse::print(OpticalSystemElement opticalSysElement, real wavelength)
{
	opticalSysElement.setRefractiveIndexAccordingToWavelength(wavelength);
	OpticalSystem_LLT optSysLLTtoPrint = opticalSysElement.getLLTconversion_doConversion();
	optSysLLTtoPrint.printAllOptSysParameter_LLT(optSysLLTtoPrint);

}

// get very height number
real oftenUse::getInfReal() 
{ 
	return 99999999999999999999999999999.0;;
};
float oftenUse::getInfFloat() { return 99999999999999999999999999999.0; };
int oftenUse::getInfInt() { return 9999999999999999999; };
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
			tempSeqTrace.setTraceToSurface(posLastSurface);
			tempSeqTrace.seqRayTracingWithVectorOfLightRays(tempLightRay_vec);

			tempInterPoints = tempSeqTrace.getAllInterPointsAtSurf_i_notFiltered(posLastSurface);

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

		tempInterPoints = tempSeqTrace.getAllInterPointsAtSurf_i_notFiltered(posLastSurface);

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

			tempInterPoints = tempSeqTrace.getAllInterPointsAtSurf_i_notFiltered(posLastSurface);

			saveAllInterPoints.insert(saveAllInterPoints.end(), tempInterPoints.begin(), tempInterPoints.end());

			tempSeqTrace.clearAllTracedRays();

		}


		// calc rms spot
		Spot tempSpot(saveAllInterPoints, saveAllInterPoints[0]);
		allRMS[i] = tempSpot.getRMS_µm();

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
bool checkIntersectInfos(const IntersectInformationStruct& intersectInfos, const IntersectInformationStruct& controleIntersectInfos, real tolerance)
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



	bool checker = Math::checkTrueOfVectorElements(checkIntersectInfos);
	return checker;

	//JonesVector_LLT mPolarisation{};
	//typeLight mLightType{};
	//bool mIsAlive = true;
	//Light_LLT mLight{};
}