#include "FillApertureStop.h"
#include <iostream>
#define _USE_MATH_DEFINES
#include <cmath>
#include <math.h>   
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

#include "..\RayAiming\RayAiming.h"

// calculate points on one arm of the entrance pupil
std::vector<VectorStructR3> FillApertureStop::calcPointsOnOneArm(VectorStructR3 const& direction)
{
	std::vector<VectorStructR3> returnPointsOnOneArm;
	//std::vector<VectorStructR3> returnPointsOnOneArm_private;
	double scaleValue = mSemiHeightAS / mNumberOfRingsAS;

//#pragma omp for nowait
	for (int i = 1; i <= mNumberOfRingsAS; i++)
	{
		VectorStructR3 PointOnArm = mPointAS + i * scaleValue * direction;
		returnPointsOnOneArm.push_back(PointOnArm);
	}
//#pragma omp critical
//	returnPointsOnOneArm.insert(returnPointsOnOneArm.end(), returnPointsOnOneArm_private.begin(), returnPointsOnOneArm.end());

	return returnPointsOnOneArm;

}

FillApertureStop::~FillApertureStop()
{
	std::vector<VectorStructR3>().swap(mVectorWithManyPointsInAS);
	std::vector<LightRayStruct>().swap(mVectorWithLightRays);

}

// get number of rings in aperture stop
unsigned int FillApertureStop::getNumberOfRingsInApertureStop() const&
{
	return mNumberOfRingsAS;
}

// print all points in the entrace pupil
void FillApertureStop::printAllPointsInAS() const&
{
	unsigned int sizeOfVector = mVectorWithManyPointsInAS.size();
	for (int i = 0; i < sizeOfVector; i++)
	{
		std::cout << "___________\n";
		std::cout << "point Nr " << i << std::endl;
		std::cout << "\n";
		mVectorWithManyPointsInAS.at(i).print();
		std::cout << "___________\n";
		std::cout << "\n";
	}
}


// build many LightRays from an object point
std::vector<LightRayStruct> FillApertureStop::fillASWithLightRayFromObjectPoint(std::vector<VectorStructR3> const& points)
{
	std::vector<LightRayStruct> returnVectorOfLightRays;
	//std::vector<LightRayStruct> returnVectorOfLightRays_private;

//#pragma omp for nowait
	for (int i = 0; i < points.size(); i++)
	{
		LightRayStruct LightRay;
		Light_LLT light;
		LightRay.setIsAlive(1);
		LightRay.ray.setOriginRay(mStartPointRay);
		LightRay.ray.setDirectionRayUnit(points.at(i) - mStartPointRay);
		LightRay.ray.setCurrentRefractiveIndex(mRefractiveIndex);
		//ghtRay.ray.setWavelenghtRay(mWavelength);
		light.setWavelength(mLight.getWavelength());
		light.setIntensity(mLight.getIntensity());
		LightRay.setLight_LLT(light);
		// TODO: set the light things too

		returnVectorOfLightRays.push_back(LightRay);

	}

//#pragma omp critical
//	returnVectorOfLightRays.insert(returnVectorOfLightRays.end(), returnVectorOfLightRays_private.begin(), returnVectorOfLightRays_private.end());

	return returnVectorOfLightRays;
}

// build many LightRay from infinity
std::vector<LightRayStruct> FillApertureStop::fillASWithLightRayFromInfinity(std::vector<VectorStructR3> const points)
{
	std::vector<LightRayStruct> returnVectorOfLightRays;
	//std::vector<LightRayStruct> returnVectorOfLightRays_private;

//#pragma omp for nowait
	for (int i = 0; i < points.size(); i++)
	{
		LightRayStruct LightRay;
		Light_LLT light;
		LightRay.setIsAlive(1);
		// calculate temp point
		VectorStructR3 tempPoint = { points.at(i).getX() - tan(mAngleX * PI / 180.0) * 1000, points.at(i).getY() - tan(mAngleY*PI / 180.0) * 1000, points.at(i).getZ() - 1000 };
		LightRay.ray.setOriginRay(tempPoint);
		LightRay.ray.setDirectionRayUnit(points.at(i) - tempPoint);
		LightRay.ray.setCurrentRefractiveIndex(mRefractiveIndex);;
		light.setWavelength(550.0);
		LightRay.setLight_LLT(light);
		// TODO: set the light things too!!!

		returnVectorOfLightRays.push_back(LightRay);

	}


	return returnVectorOfLightRays;
}

// get points in entrance pupil
std::vector<VectorStructR3> FillApertureStop::getPointsInAS()
{
	return mVectorWithManyPointsInAS;
}

// get a vector with many LightRays
std::vector<LightRayStruct> FillApertureStop::getVectorWithLightRays() const&
{
	return mVectorWithLightRays;
}


// build LightRays (hexapolar)
std::vector<VectorStructR3>  FillApertureStop::fillAS_withPoints(unsigned int const& rayDensity, VectorStructR3 const& PointApertureStop, VectorStructR3 const& directionApertureStop, real const& SemiHeightEntrancePupil)
{

	if (rayDensity < 3)
	{
		std::vector<VectorStructR3 > Error;
		std::cout << "for qood evaluation the rayDensity must be at least 3\n";
		return Error; //TODO Ques Sergej: Was soll hier herausgegeben werden???
	}

	else // the rayDensity is heigher than 3

	{
		VectorStructR3 DirectionEntrancePupilUNIT = Math::unitVector(directionApertureStop);

		VectorStructR3 BaseVecor1 = { 1.0,0.0,0.0 };
		if (Math::checkLinearlyDependent(DirectionEntrancePupilUNIT, BaseVecor1))
		{
			BaseVecor1 = { 0.0,1.0,0.0 };
		}
		else
		{
			BaseVecor1 = { 1.0,0.0,0.0 };
		}

		/*
		rayDensity = 3 --> Arms1=6, Arms2=12, Arms3=18 --> 3 Rings
		rayDenisty = 4 --> Arms1=6, Arms2=12, Arms3=18, Arms4=24 --> 4 Rings
		rayDenisty = 5 --> Arms1=6, Arms2=12, Arms3=18, Arms4=24, Arms5=30 --> 5 Rings

		see Zemax manual on page 137
		Ray Density:
		"The ray density specifies the number of hexapolar rings to be traced if a hexapolar or
		dithered  pattern is selected, or the number of rays across the width and height if a
		rectangular pattern is selected. The more rays traced, the greater the accuracy of the
		RMS spot radius, although the computation time increases. Thereare 6 rays in the first
		hexapolar ring, 12 in the second, 18 in the third, and so on."
		*/

		// TODO Question: What is the max. ray density -> adapt the rayDensityArray!
		unsigned int rayDensityArray[60] = { 6,12,18,24,30,36,42,48,54,60,66,72,78,84,90,96,102,108,114,120,126,132,138,144,150,156,162,168,174,180,186,192,198,204,210,216,222,228,234,240,246,252,258,264,270,276,282,288,294,300,306,312,318,324,330,336,342,348,354,360 };

		// number of rings
		unsigned int numberOfRings = rayDensity;


		


		// scale facor
		real scaleValue = SemiHeightEntrancePupil / numberOfRings;
		real scaleValueGlobal = scaleValue;
		// Vector in entrance pupil
		VectorStructR3 VectorForEntrancePupil = Math::unitVector(Math::DoCrossProduct(BaseVecor1, DirectionEntrancePupilUNIT));

		// postion in rayDensityArray => number of arms
		unsigned int posInRayDenArray = 0;

		// the first point is allways the position of the aperture stop 
		mVectorWithManyPointsInAS.push_back(PointApertureStop);


		for (int j = 0; j < numberOfRings; j++)
		{
			// rotarion angle starts with 2Pi / 6 because there are 6 arms
			real rotationAngleRadian = 2 * PI / rayDensityArray[posInRayDenArray];
			Matrix3x3AndExist rotationMatrixAndExist = Math::calcRotationMatrixAroundVector(DirectionEntrancePupilUNIT, rotationAngleRadian);


			for (int i = 0; i < rayDensityArray[posInRayDenArray]; i++)
			{
				VectorStructR3 Point = PointApertureStop + scaleValue * VectorForEntrancePupil;
				mVectorWithManyPointsInAS.push_back(Point);
				VectorForEntrancePupil = Math::multiplyMatrix3x3VectorR3(rotationMatrixAndExist.Matrix, VectorForEntrancePupil);
			}




			posInRayDenArray = posInRayDenArray + 1;
			scaleValue = scaleValue + scaleValueGlobal;
		}


	}


	return mVectorWithManyPointsInAS;

}

// build LightRays (square)
std::vector<VectorStructR3> FillApertureStop::fillAS_withPointsRing(int nrOfRings, double semiHeightAperture, VectorStructR3 apexApertureStop)
{
	std::vector<VectorStructR3> targetPointVec;
	VectorStructR3 targetPoint;
	unsigned int rayDensityArray[60] = { 6,12,18,24,30,36,42,48,54,60,66,72,78,84,90,96,102,108,114,120,126,132,138,144,150,156,162,168,174,180,186,192,198,204,210,216,222,228,234,240,246,252,258,264,270,276,282,288,294,300,306,312,318,324,330,336,342,348,354,360 };

	// ein Target-Punkt in der Mitte
	targetPointVec.push_back(apexApertureStop);

	// bei einem Ring pos 0,5, bei 2 Ringen 1/3 und 2/3, bei 3 Ringen 0,25, 0,5 und 0,75 usw. Hier geht es um den innersten Radius
	double radiusRing0 = semiHeightAperture / (nrOfRings + 1);

	for (int i = 0; i < nrOfRings; i++)
	{
		int nrOfRays = rayDensityArray[i];
		double radiusRing = radiusRing0 * (i + 1);

		for (int j = 0; j < rayDensityArray[i]; j++)
		{
			double degreeVal = 360 * j / nrOfRays;
			double radVal = degreeVal * M_PI / 180;
			double targetXval = sin(radVal) * radiusRing;
			double targetYval = cos(radVal) * radiusRing;
			targetPoint = { targetXval,targetYval,apexApertureStop.getZ() };
			targetPointVec.push_back(targetPoint);
		}
	}
	return targetPointVec;
}

// Gibt einen Vektor mit quadratisch angeordneten Targetpunkten in der Aperturblende zurück
std::vector<VectorStructR3> FillApertureStop::fillAS_withPointsSquare(unsigned int rayDensity, VectorStructR3 pointEntrancePupil, VectorStructR3 directionEntrancePupil, real semiHeightEntrancePupil)
{
	std::vector<VectorStructR3> targetPointVec;
	std::vector<VectorStructR3> targetPointVec2;
	VectorStructR3 targetPoint;

	double radiusRing0 = (semiHeightEntrancePupil / rayDensity);
	double yVal;

	for (unsigned int i = 0; i < rayDensity; i++)
	{
		targetPoint = { radiusRing0 * (i + 1) + pointEntrancePupil.getX(),pointEntrancePupil.getY(),pointEntrancePupil.getZ() };
		targetPointVec.push_back(targetPoint);
		targetPoint = { radiusRing0 * (i + 1) * (-1.0) + pointEntrancePupil.getX(),pointEntrancePupil.getY(),pointEntrancePupil.getZ() };
		targetPointVec.push_back(targetPoint);
		targetPoint = { pointEntrancePupil.getX(),radiusRing0 * (i + 1) + pointEntrancePupil.getY(),pointEntrancePupil.getZ() };
		targetPointVec.push_back(targetPoint);
		targetPoint = { pointEntrancePupil.getX(),radiusRing0 * (i + 1) * (-1.0) + pointEntrancePupil.getY(),pointEntrancePupil.getZ() };
		targetPointVec.push_back(targetPoint);

		for (unsigned int j = 0; j < rayDensity; j++)
		{
			targetPoint = { radiusRing0 * (j + 1) + pointEntrancePupil.getX(),radiusRing0 * (i + 1) + pointEntrancePupil.getY(),pointEntrancePupil.getZ() };
			targetPointVec.push_back(targetPoint);
			targetPoint = { radiusRing0 * (j + 1) * (-1.0) + pointEntrancePupil.getX(),radiusRing0 * (i + 1) + pointEntrancePupil.getY(),pointEntrancePupil.getZ() };
			targetPointVec.push_back(targetPoint);
			targetPoint = { radiusRing0 * (j + 1) + pointEntrancePupil.getX(),radiusRing0 * (i + 1)* (-1.0) + pointEntrancePupil.getY(),pointEntrancePupil.getZ() };
			targetPointVec.push_back(targetPoint);
			targetPoint = { radiusRing0 * (j + 1) * (-1.0) + pointEntrancePupil.getX(),radiusRing0 * (i + 1)* (-1.0) + pointEntrancePupil.getY(),pointEntrancePupil.getZ() };
			targetPointVec.push_back(targetPoint);
		}
	}

	double checkVec;
	// Target-Punkt in der Mitte
	targetPointVec2.push_back(pointEntrancePupil);

	// Entfernt alle Targets die nicht innerhalb der Blende liegen
	for (unsigned int i = 0; i < targetPointVec.size(); i++)
	{
		checkVec = std::sqrt(targetPointVec.at(i).getX()*targetPointVec.at(i).getX() + targetPointVec.at(i).getY()*targetPointVec.at(i).getY());
		if (checkVec <= semiHeightEntrancePupil)
		{
			targetPointVec2.push_back(targetPointVec.at(i));
		}
	}
	return targetPointVec2;
}


// Gibt einen Vektor mit zufälligen Targetpunkten in der Aperturblende zurück
std::vector<VectorStructR3> FillApertureStop::fillAS_withPointsDithered(unsigned int nrOfRings, VectorStructR3 apexApertureStop, VectorStructR3 directionEntrancePupil, real semiHeightAperture)
{
	std::vector<VectorStructR3> targetPointVec;
	VectorStructR3 targetPoint;
	int nrOfTargets = 1;

	for (unsigned int i = 0; i < nrOfRings; i++)
	{
		nrOfTargets = nrOfTargets + 6 * (i + 1);
	}

	for (unsigned int i = 0; i < nrOfTargets; i++)
	{
		// Random SemiHeight
		double a = (double)rand() / RAND_MAX;
		double randRadius = a * semiHeightAperture;
		// Random Degree
		int dRand = rand() % 360;
		double radVal = dRand * M_PI / 180;
		double targetXval = sin(radVal) * randRadius;
		double targetYval = cos(radVal) * randRadius;
		targetPoint = { targetXval,targetYval,apexApertureStop.getZ() };
		targetPointVec.push_back(targetPoint);
	}
	return targetPointVec;
}




// Einlesen einer .csv Tabelle mit 2 Spalten
std::vector<VectorStructR2> FillApertureStop::getcsv2columns(std::string fname)
{
	using namespace std;

	//cout << "Test csv: " << endl;
	//string hallo;
	// ACHTUNG: / statt \
	// Bsp: Datei heißt C:\Users\Dominik\Desktop\Bachelorarbeit Ray Aiming\Lichtquelle_Tbl_Werte.csv
	// muss aber so heißen: C:/Users/Dominik/Desktop/Bachelorarbeit Ray Aiming/Lichtquelle_Tbl_Werte.csv
	// Tabellenwerte (Intensität) in Prozent, also von 0-100 ohne nachkommastellen

	fstream file(fname, ios::in);
	vector<VectorStructR2> vec;
	int safeVal;
	VectorStructR2 val = { 0.0,0.0 };

	if (!file)
	{
		cerr << "Can't open file" << endl;
		file.close();
		vec.push_back(val);
	}
	else
	{
		while (!file.eof()) 	// Einlesen bis Dateiende
		{
			string row;
			getline(file, row);	// Einlesen einer Zeile

			if (!row.empty()) // Falls Zeile nicht leer
			{
				istringstream ss(row);		// StringStream zum zerlegen der Zeile
				string temp;
				getline(ss, temp, ';');		// Ersten Wert bis zum Trennzeichen einlesen

				for (int i = 0; i < 2; i++)
				{
					stringstream convert;	// StringStream für die Konvertierung
					convert << temp;		// Konvertierung
					int itemp;			// des String
					convert >> itemp;		// nach double
					if (i == 0)
					{
						safeVal = itemp;
					}
					else
					{
						val = { (double)safeVal, (double)itemp };
					}

					temp.clear();			// String leeren
					getline(ss, temp, ';');	// Nächsten Wert einlesen
				}
				vec.push_back(val);		// einfügen in den vector
			}
		}
		file.close();

		//for (int i = 0; i < vec.size(); i++)
		//{
		//	cout << vec[i].getX() << " | " << vec[i].getY() << endl;
		//}
	}
	vector<VectorStructR2> vec2;

	for (unsigned int i = 0; i < vec.size(); i++)
	{
		vec2.push_back({ vec.at(i).getX(), vec.at(i).getY() / 100 });
	}
	return vec2;
}

// Ändert die Intensität eines Strahls anhand des nach einer .csv-Tabelle/Vector gegebenen Gradzahl
LightRayStruct FillApertureStop::changeIntensityByDegree(LightRayStruct lightRay, std::vector<VectorStructR2> vec1)
{
	LightRayStruct returnLightRay;
	LightRayStruct lightRayStruct0;
	returnLightRay.setRay_LLT(lightRay.getRay_LLT());
	Light_LLT light = lightRay.getLight_LLT();
	VectorStructR3 rayVector = lightRay.getRay_LLT().getDirectionRayUnit();
	double minDegree = 0.0;
	double maxDegree = 0.0;
	double minIntensity = 0.0;
	double maxIntensity = vec1.at(0).getY();

	double rayDegree = 180.0 * acos(rayVector.getZ() / (sqrt(rayVector.getX()*rayVector.getX() + rayVector.getY()*rayVector.getY() + rayVector.getZ()*rayVector.getZ()) * 1.0)) / PI;
	double intensityVal = vec1.at(0).getY();

	for (unsigned int i = 0; (i < vec1.size()) && (vec1.at(i).getX() < rayDegree); i++)
	{
		minDegree = vec1.at(i).getX();
		maxDegree = vec1.at(i + 1).getX();
		minIntensity = vec1.at(i).getY();
		maxIntensity = vec1.at(i + 1).getY();
	}

	double newIntensity;

	// Falls Gradzahlen oder Intensitäten exakt übereinstimmen, ist eine Berechnung nicht notwendig
	if ((rayDegree == maxDegree) || (minIntensity == maxIntensity))
	{
		newIntensity = maxIntensity;
	}
	else
	{
		// Falls Gradzahl ein Zwischenwert ist
		double diffDegree = std::abs(maxDegree - minDegree);
		double diffIntensity = maxIntensity - minIntensity;
		newIntensity = minIntensity + (diffIntensity / diffDegree)*std::abs(rayDegree - minDegree);
	}
	std::cout << "rayDegree: " << rayDegree << '\n';
	std::cout << "newIntensity: " << newIntensity << '\n';
	std::cout << '\n';

	light.setIntensity(newIntensity);
	returnLightRay.setLight_LLT(light);
	return returnLightRay;
}



// fill aperture stop with ray including ray aiming
std::vector<LightRayStruct> FillApertureStop::fillAperStopRayAimingInfinity(std::vector<VectorStructR3> targetPointVec, VectorStructR3 direction, Light_LLT light, real curRefractiveIndex, OpticalSystem_LLT opticalSys)
{
	LightRayStruct tempLightRayStr;
	RayAiming TempRayAiming(opticalSys);
	std::vector<LightRayStruct> returnLightRaySt;

	for (unsigned int i = 0; i < targetPointVec.size(); i++)
	{
		tempLightRayStr = TempRayAiming.infinityRayAiming(direction, targetPointVec.at(i), light, 1.0);
		returnLightRaySt.push_back(tempLightRayStr);
	}

	return returnLightRaySt;

}

// fill aperture stop with ray including ray aiming
std::vector<LightRayStruct> FillApertureStop::fillAperStopRayAimingFromPoint(std::vector<VectorStructR3> targetPointVec, VectorStructR3 startPointRay, Light_LLT light, real curRefractiveIndex, OpticalSystem_LLT opticalSys)
{
	LightRayStruct tempLightRayStr;
	RayAiming TempRayAiming(opticalSys);
	std::vector<LightRayStruct> returnLightRaySt;

	for (unsigned int i = 0; i < targetPointVec.size(); i++)
	{
		tempLightRayStr = TempRayAiming.calcRayThrowPointInApertureStop(startPointRay, targetPointVec.at(i), light, 1.0);
		returnLightRaySt.push_back(tempLightRayStr);
	}

	return returnLightRaySt;

}