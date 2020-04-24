#include "SequentialRayTracer.h"
#include "..\LowLevelTracing\Ray_LLT.h"
#include<omp.h>
#include <iostream>
#include "..\FillAptertureStop/FillApertureStop.h"
#include "..\LowLevelTracing/Surfaces/ApertureStop_LLT.h"

// get intersection infos
IntersectInformationStruct IntersectInfosAndPosSurfaceAndTotalSteps::getIntersecInfos() const
{
	return intersectInfos;
}
// set intersection infos
void IntersectInfosAndPosSurfaceAndTotalSteps::setIntersectionInfos(IntersectInformationStruct const setIntersectinfos)
{
	intersectInfos = setIntersectinfos;
}

// set position
void IntersectInfosAndPosSurfaceAndTotalSteps::setPosition(unsigned int const pos)
{
	position = pos;
}
// get position
unsigned int IntersectInfosAndPosSurfaceAndTotalSteps::getPosition() const
{
	return position;
}

// set total  steps
void IntersectInfosAndPosSurfaceAndTotalSteps::setTotalSteps(real const totSte)
{
	totalSteps = totSte;
}
// get total steps 
real IntersectInfosAndPosSurfaceAndTotalSteps::getTotalSteps() const
{
	return totalSteps;
}

saveResultsSeqRayTrace_parallel::saveResultsSeqRayTrace_parallel() {};
saveResultsSeqRayTrace_parallel::~saveResultsSeqRayTrace_parallel() {};

std::vector<VectorStructR3> saveResultsSeqRayTrace_parallel::getStartPointsOfLightRay()
{
	return mStartPointOfLightRays;
}
void saveResultsSeqRayTrace_parallel::setStartPointsOfLightRay(std::vector<VectorStructR3> startPointsLightRay)
{
	mStartPointOfLightRays = startPointsLightRay;
}
std::vector <IntersectInfosAndPosSurfaceAndTotalSteps> saveResultsSeqRayTrace_parallel::getIntersectInfosAndPosSurfaceAndTotalSteps()
{
	return mSaveIntInfos_Pos_totStep_NotFiltered;
}
void saveResultsSeqRayTrace_parallel::setIntersectInfosAndPosSurfaceAndTotalSteps(std::vector <IntersectInfosAndPosSurfaceAndTotalSteps> intInfos_Pos_totStep_NotFiltered)
{
	mSaveIntInfos_Pos_totStep_NotFiltered = intInfos_Pos_totStep_NotFiltered;
}
std::vector <std::vector<LightRayStruct>> saveResultsSeqRayTrace_parallel::getLightRayStructNotFiltered()
{
	return mSaveLightRayStructsNotFiltered;
}
void saveResultsSeqRayTrace_parallel::setLightRayStructNotFiltered(std::vector <std::vector<LightRayStruct>> lightRayStructNotFiltered)
{
	mSaveLightRayStructsNotFiltered = lightRayStructNotFiltered;
}

std::vector<IntersectInfosAndPosSurfaceAndTotalSteps> saveResultsSeqRayTrace_parallel::getInterInfosAndPosSurAndTotStep()
{
	return mSaveInterInfos_PosSur_TotSteps;
}
void saveResultsSeqRayTrace_parallel::setInterInfosAndPosSurAndTotStep(std::vector <IntersectInfosAndPosSurfaceAndTotalSteps> interInfosAndPosSurAndTotStep)
{
	mSaveInterInfos_PosSur_TotSteps = interInfosAndPosSurAndTotStep;
}


SequentialRayTracing::~SequentialRayTracing() 
{};

// sequential ray tracing with the optical system element
SequentialRayTracing::SequentialRayTracing(OpticalSystemElement opticalSysElement) :
	mOpticalSystem_LLT(opticalSysElement.getLLTconversion_doConversion())
{
	mTraceToSurface_i = 9999999999;

};

SequentialRayTracing::SequentialRayTracing(OpticalSystem_LLT opticalSystem) :
	mOpticalSystem_LLT(opticalSystem)
{
	mTraceToSurface_i = 9999999999;
};

SequentialRayTracing::SequentialRayTracing(OpticalSystem_LLT opticalSystem, unsigned int traToSur) :
	mOpticalSystem_LLT(opticalSystem),
	mTraceToSurface_i(traToSur)
{};

SequentialRayTracing::SequentialRayTracing(OpticalSystemElement opticalSysElement, LightRayStruct LightRay) :
	mOptSysEle(opticalSysElement),
	mLightRay(LightRay)

{
	mTraceToSurface_i = 9999999999;
	int sizeOptSysEle = opticalSysElement.getPosAndElement().size();


	// set the refractive index to the wavelenght
	for (unsigned int j = 0; j < sizeOptSysEle; j++)
	{

		mOptSysEle.getPosAndElement().at(j).getElementInOptSys_ptr()->calRefIndex_A_and_B_andSet(LightRay.getLight_LLT().getWavelength());
	}

	mOpticalSystem_LLT = mOptSysEle.getLLTconversion_doConversion();
	sequentialRayTracing(mLightRay);

}

SequentialRayTracing::SequentialRayTracing(OpticalSystemElement /*optical system element*/ opticalSysElement, VectorStructR3 /*start point lightRay*/ startPointLightRay, unsigned int /*rings*/ rings, unsigned int /*arms*/ arms, real /*refractive index*/ refIndex, Light_LLT light) :
	mOptSysEle(opticalSysElement),
	mOpticalSystem_LLT(opticalSysElement.getLLTconversion_doConversion())
{
	mLightRay.setLight_LLT(light);
	mTraceToSurface_i = 9999999999;
	mPositionApertureStop = findPosApertureStop(mOpticalSystem_LLT);
	setRefractivIndexOptSys(light.getWavelength());
	FillApertureStop fillAperStop(/*start point rays*/ startPointLightRay,/*semi height of aperture stop*/ mOpticalSystem_LLT.getPosAndInteractingSurface().at(mPositionApertureStop).getSurfaceInterRay_ptr()->getSemiHeight(),
		/*point of aperture stop*/mOpticalSystem_LLT.getPosAndInteractingSurface().at(mPositionApertureStop).getSurfaceInterRay_ptr()->getPoint(),/*direction of aperture stop*/mOpticalSystem_LLT.getPosAndInteractingSurface().at(mPositionApertureStop).getSurfaceInterRay_ptr()->getDirection(),
		/*rings*/ rings,/*arms*/ arms,/*refractive index*/ refIndex,/*wavelength*/ light);
	seqRayTracingWithVectorOfLightRays(fillAperStop.getVectorWithLightRays());
}

SequentialRayTracing::SequentialRayTracing(OpticalSystemElement /*optical system element*/ opticalSysElement, VectorStructR3 /*start point lightRay*/ startPointLightRay, unsigned int /*rings*/ rings, unsigned int /*arms*/ arms, real /*refractive index*/ refIndex, std::vector<Light_LLT> light_vec) :
	mOptSysEle(opticalSysElement),
	mLight_LLT_vec(light_vec)
{
	mTraceToSurface_i = 9999999999;
	int sizeOptSysEle = opticalSysElement.getPosAndElement().size();
	mPositionApertureStop = findPosApertureStop(opticalSysElement.getLLTconversion_doConversion());

	for (unsigned int i = 0; i < light_vec.size(); i++)
	{

		// set the refractive index to the wavelenght
		for (unsigned int j = 0; j < sizeOptSysEle; j++)
		{

			setRefractivIndexOptSys(light_vec.at(i).getWavelength());
		}

		mOpticalSystem_LLT = mOptSysEle.getLLTconversion_doConversion();

		FillApertureStop fillAperStop(/*start point rays*/ startPointLightRay,/*semi height of aperture stop*/ mOpticalSystem_LLT.getPosAndInteractingSurface().at(mPositionApertureStop).getSurfaceInterRay_ptr()->getSemiHeight(),
			/*point of aperture stop*/mOpticalSystem_LLT.getPosAndInteractingSurface().at(mPositionApertureStop).getSurfaceInterRay_ptr()->getPoint(),/*direction of aperture stop*/mOpticalSystem_LLT.getPosAndInteractingSurface().at(mPositionApertureStop).getSurfaceInterRay_ptr()->getDirection(),
			/*rings*/ rings,/*arms*/ arms,/*refractive index*/ refIndex,/*wavelength*/ light_vec.at(i));

		seqRayTracingWithVectorOfLightRays(fillAperStop.getVectorWithLightRays());

	}

}


void SequentialRayTracing::setRefractivIndexOptSys(real wavelength)
{
	unsigned int sizeOptSys = mOptSysEle.getPosAndElement().size();
	// set the refractive index to the wavelenght
	for (unsigned int j = 0; j < sizeOptSys; j++)
	{
		mOptSysEle.getPosAndElement().at(j).getElementInOptSys_ptr()->calRefIndex_A_and_B_andSet(wavelength);
	}

	mOpticalSystem_LLT = mOptSysEle.getLLTconversion_doConversion();
}

// find position of aperture stop
unsigned int SequentialRayTracing::findPosApertureStop(OpticalSystem_LLT optSys_LLT)
{
	unsigned int posApertureStop = -1;
	ApertureStop_LLT aperStop_ptr;

	for (unsigned int i = 0; i < optSys_LLT.getNumberOfSurfaces(); i++)
	{

		if (typeid(aperStop_ptr) == typeid(*optSys_LLT.getPosAndInteractingSurface().at(i).getSurfaceInterRay_ptr()))
		{
			posApertureStop = optSys_LLT.getPosAndInteractingSurface().at(i).getPosition();
		}

	}

	if (posApertureStop == -1)
	{
		std::cout << "there is no aperture stop in your optical system!!!" << std::endl;
	}

	return posApertureStop;

}

// do sequential ray tracing
void SequentialRayTracing::sequentialRayTracing(LightRayStruct LightRaySt)
{
	
	Ray_LLT ray = LightRaySt.getRay_LLT();
	Light_LLT light = LightRaySt.getLight_LLT();


	// save the start points of the rays in an std::vector
	mStartPointOfLightRays.push_back(ray.getOriginRay());

	IntersectInfosAndPosSurfaceAndTotalSteps tempInterInfos_Pos_totStep;
	unsigned sizeOfVector = mOpticalSystem_LLT.getPosAndInteractingSurface().size();

	// to stop tracing at surface mTraceToSurface_i
	if (sizeOfVector <= mTraceToSurface_i)
	{
		mTraceToSurface_i = sizeOfVector - 1;
	}

	// _____________________________ 
	// to filter the intersection points
	IntersectInformationStruct NoInterPoint;
	NoInterPoint.setSurface(N);
	IntersectInfosAndPosSurfaceAndTotalSteps NoInterPointAndPos;
	NoInterPointAndPos.setIntersectionInfos(NoInterPoint);
	NoInterPointAndPos.setPosition(99);
	// _____________________________ 
	real saveTotalSteps = 0.0;

	// I do not think that it is best when we use #pragma omp here.
	// bacause with this function we trace just on LightRay from surface to surface
	// we parallelized the code in the function "seqRayTracingWithVectorOfLightRays" here we
	// trace an vector of LightRays
	for (int i = 0; i <= mTraceToSurface_i; i++)
	{
		int isRayLightAlive = LightRaySt.getIsAlive();
		real curWavelength = LightRaySt.getLight_LLT().getWavelength();
		//std::cout << "_________________________\n";
		//Ray_LLT rayToD = LightRaySt.getRay_LLT();
		//VectorStructR3 printDir = rayToD.getDirectionRayUnit();
		//printDir.print();
		//std::cout << "_________________________\n";



		//#pragma omp parallel if(isRayLightAlive,curWavelength)
		if (isRayLightAlive == 1 && curWavelength != 0.0) // TODO Ques: Hier muss ich mir vielleicht noch ein "sichererer" Abbruchkriterium überlegen
		{
			//real tempStepsToWalk = tempInterInfos_Pos_totStep.getIntersecInfos().getStepsToWalk();
			tempInterInfos_Pos_totStep.setIntersectionInfos(mOpticalSystem_LLT.getPosAndInteractingSurface().at(i).getSurfaceInterRay_ptr()->calculateIntersection(LightRaySt));
			tempInterInfos_Pos_totStep.setPosition(mOpticalSystem_LLT.getPosAndInteractingSurface().at(i).getPosition());
			saveTotalSteps = saveTotalSteps + tempInterInfos_Pos_totStep.getIntersecInfos().getStepsToWalk();
			tempInterInfos_Pos_totStep.setTotalSteps(saveTotalSteps);
			//std::cout << "_________________________\n";
			//tempIntersectInfos.printIntersectInformation();
			//std::cout << "_________________________\n";
			mSaveIntInfos_Pos_totStep_NotFiltered.push_back(tempInterInfos_Pos_totStep);

			IntersectInformationStruct tempInterInfos = tempInterInfos_Pos_totStep.getIntersecInfos();
			std::vector<LightRayStruct> tempLightRay = mOpticalSystem_LLT.getPosAndInteraction()[i].getInteractionAtSur_ptr()->calcInteraction(tempInterInfos);
			// here we need an vector of LightRays bacause then we can return later more than one ray -> so it is possible to
			// calculate scattered rays


			mSaveLightRayStructsNotFiltered.push_back(tempLightRay);
			// TODO: Wenn in dem Vector mehrere LightRays sind, dann müssen diese auch in einer Schleige abgearbeitet werden.
			ray = tempLightRay.at(0).getRay_LLT();
			light = tempLightRay.at(0).getLight_LLT();
			LightRaySt.setLight_LLT(light);
			LightRaySt.setRay_LLT(ray);


		}

		else
		{

			mSaveIntInfos_Pos_totStep_NotFiltered.push_back(NoInterPointAndPos);
			ray.setDirectionRayUnit({ 0.0,0.0,0.0 });
			LightRaySt.light.setWavelength(0.0);
		}

	}

	mSaveInterInfos_PosSur_TotSteps = filterAllRealIntersecPoints(mSaveIntInfos_Pos_totStep_NotFiltered);
}

// do sequential ray tracing with an vector of many LightRay
void SequentialRayTracing::seqRayTracingWithVectorOfLightRays(std::vector<LightRayStruct> const LightRayStVec)
{
	
	
	for (int i = 0; i < LightRayStVec.size(); i++)
	{
		int isAlive = LightRayStVec.at(i).getIsAlive();
		if (isAlive == 1);
		{
			sequentialRayTracing(LightRayStVec.at(i));
		}
	}
		
}

//void SequentialRayTracing::seqRayTracingWithVectorOfLightRays_parallel(std::vector<LightRayStruct> const LightRayStVec)
//{
//		std::vector<std::vector<LightRayStruct>> lightRayVec_vec = divVecWithLightRay(LightRayStVec);
//		
//		std::vector<LightRayStruct> LightRayStVec_core1 = lightRayVec_vec.at(0);
//		std::vector<LightRayStruct> LightRayStVec_core2 = lightRayVec_vec.at(1);
//		std::vector<LightRayStruct> LightRayStVec_core3 = lightRayVec_vec.at(2);
//		std::vector<LightRayStruct> LightRayStVec_core4 = lightRayVec_vec.at(3);
//		std::vector<LightRayStruct> LightRayStVec_core5 = lightRayVec_vec.at(4);
//		std::vector<LightRayStruct> LightRayStVec_core6 = lightRayVec_vec.at(5);
//		std::vector<LightRayStruct> LightRayStVec_core7 = lightRayVec_vec.at(6);
//		std::vector<LightRayStruct> LightRayStVec_core8 = lightRayVec_vec.at(7);
//		
//		saveResultsSeqRayTrace_parallel saveResults_core1;
//
//
//		#pragma omp parallel
//		#pragma omp sections
//		{
//		#pragma omp section
//			
//
//
//		#pragma omp section
//			{for (int i = 0; i < LightRayStVec_core2.size(); i++)
//			{
//				int isAlive = LightRayStVec_core2.at(i).getIsAlive();
//				if (isAlive == 1);
//				{
//					sequentialRayTracing(LightRayStVec_core2.at(i));
//				}
//			}
//			}
//		#pragma omp section
//			{for (int i = 0; i < LightRayStVec_core3.size(); i++)
//			{
//				int isAlive = LightRayStVec_core3.at(i).getIsAlive();
//				if (isAlive == 1);
//				{
//					sequentialRayTracing(LightRayStVec_core3.at(i));
//				}
//			}
//			}
//		#pragma omp section
//			{for (int i = 0; i < LightRayStVec_core4.size(); i++)
//			{
//				int isAlive = LightRayStVec_core4.at(i).getIsAlive();
//				if (isAlive == 1);
//				{
//					sequentialRayTracing(LightRayStVec_core4.at(i));
//				}
//			}
//			}
//		#pragma omp section
//			{for (int i = 0; i < LightRayStVec_core5.size(); i++)
//			{
//				int isAlive = LightRayStVec_core5.at(i).getIsAlive();
//				if (isAlive == 1);
//				{
//					sequentialRayTracing(LightRayStVec_core5.at(i));
//				}
//			}
//			}
//		#pragma omp section
//			{for (int i = 0; i < LightRayStVec_core6.size(); i++)
//			{
//				int isAlive = LightRayStVec_core6.at(i).getIsAlive();
//				if (isAlive == 1);
//				{
//					sequentialRayTracing(LightRayStVec_core6.at(i));
//				}
//			}
//			}
//		#pragma omp section
//			{for (int i = 0; i < LightRayStVec_core7.size(); i++)
//			{
//				int isAlive = LightRayStVec_core7.at(i).getIsAlive();
//				if (isAlive == 1);
//				{
//					sequentialRayTracing(LightRayStVec_core7.at(i));
//				}
//			}
//			}
//		#pragma omp section
//			{for (int i = 0; i < LightRayStVec_core8.size(); i++)
//			{
//				int isAlive = LightRayStVec_core8.at(i).getIsAlive();
//				if (isAlive == 1);
//				{
//					sequentialRayTracing(LightRayStVec_core8.at(i));
//				}
//			}
//			}
//		
//		
//		
//		}
//		
//		
//		
//
//}

std::vector<std::vector<LightRayStruct>> SequentialRayTracing::divVecWithLightRay(std::vector<LightRayStruct> lightRayStVec)
{

	std::vector<std::vector<LightRayStruct>> returnVecDivLightRay;
	unsigned int numberCores = 8;

	unsigned int size = lightRayStVec.size();
	unsigned int elementsPerVec = size / numberCores;

	unsigned int counter = 0;

	// core1
	std::vector<LightRayStruct>::const_iterator first_core1 = lightRayStVec.begin() + counter;
	std::vector<LightRayStruct>::const_iterator last_core1 = lightRayStVec.begin() + elementsPerVec + counter;
	std::vector<LightRayStruct> LightRayStVec_core1(first_core1,last_core1);
	returnVecDivLightRay.push_back(LightRayStVec_core1);
	counter++;

	// core2
	std::vector<LightRayStruct>::const_iterator first_core2 = lightRayStVec.begin() + elementsPerVec + counter;
	std::vector<LightRayStruct>::const_iterator last_core2 = lightRayStVec.begin() + 2 *  elementsPerVec + counter;
	std::vector<LightRayStruct> LightRayStVec_core2(first_core2, last_core2);
	returnVecDivLightRay.push_back(LightRayStVec_core2);
	counter++;

	// core3
	std::vector<LightRayStruct>::const_iterator first_core3 = lightRayStVec.begin() + 2 * elementsPerVec + counter;
	std::vector<LightRayStruct>::const_iterator last_core3 = lightRayStVec.begin() + 3 * elementsPerVec + counter;
	std::vector<LightRayStruct> LightRayStVec_core3(first_core3, last_core3);
	returnVecDivLightRay.push_back(LightRayStVec_core3);
	counter++;

	// core4
	std::vector<LightRayStruct>::const_iterator first_core4 = lightRayStVec.begin() + 3 * elementsPerVec + counter;
	std::vector<LightRayStruct>::const_iterator last_core4 = lightRayStVec.begin() + 4 * elementsPerVec + counter;
	std::vector<LightRayStruct> LightRayStVec_core4(first_core4, last_core4);
	returnVecDivLightRay.push_back(LightRayStVec_core4);
	counter++;

	// core5
	std::vector<LightRayStruct>::const_iterator first_core5 = lightRayStVec.begin() + 4 * elementsPerVec + counter;
	std::vector<LightRayStruct>::const_iterator last_core5 = lightRayStVec.begin() + 5 * elementsPerVec + counter;
	std::vector<LightRayStruct> LightRayStVec_core5(first_core5, last_core5);
	returnVecDivLightRay.push_back(LightRayStVec_core5);
	counter++;

	// core6
	std::vector<LightRayStruct>::const_iterator first_core6 = lightRayStVec.begin() + 5 * elementsPerVec + counter;
	std::vector<LightRayStruct>::const_iterator last_core6 = lightRayStVec.begin() + 6 * elementsPerVec + counter;
	std::vector<LightRayStruct> LightRayStVec_core6(first_core6, last_core6);
	returnVecDivLightRay.push_back(LightRayStVec_core6);
	counter++;

	// core7
	std::vector<LightRayStruct>::const_iterator first_core7 = lightRayStVec.begin() + 6 * elementsPerVec + counter;
	std::vector<LightRayStruct>::const_iterator last_core7 = lightRayStVec.begin() + 7 * elementsPerVec + counter;
	std::vector<LightRayStruct> LightRayStVec_core7(first_core7, last_core7);
	returnVecDivLightRay.push_back(LightRayStVec_core7);
	counter++;

	// core8
	std::vector<LightRayStruct>::const_iterator first_core8 = lightRayStVec.begin() + 7 * elementsPerVec + counter;
	std::vector<LightRayStruct>::const_iterator last_core8 = lightRayStVec.end();
	std::vector<LightRayStruct> LightRayStVec_core8(first_core8, last_core8);
	returnVecDivLightRay.push_back(LightRayStVec_core8);
	counter++;

	return returnVecDivLightRay;

}




// get all intersection points from SRT
std::vector<VectorStructR3> SequentialRayTracing::getAllIntersectionPointsSRT()
{
	std::vector<VectorStructR3> returnVecInterPoints;
	for (int i = 0; i < mSaveInterInfos_PosSur_TotSteps.size(); i++)
	{
		VectorStructR3 tempInterpoint = mSaveInterInfos_PosSur_TotSteps.at(i).getIntersecInfos().getIntersectionPoint();
		returnVecInterPoints.push_back(tempInterpoint);
	}

	return returnVecInterPoints;
}

// get all intersection points at surfaces i and intensity of lightRay;
std::vector<pointAndIntensity> SequentialRayTracing::getAllInterPointsAndIntensityAtSurface_i(unsigned int const surfaceNo)
{
	std::vector<IntersectInformationStruct> interInfos;
	interInfos = getAllInterInfosOfSurf_i(surfaceNo);

	std::vector<pointAndIntensity> returnPointsAndIntesity;
	for (int i = 0; i < interInfos.size(); i++)
	{
		pointAndIntensity tempInterPointsAndIntesity;
		tempInterPointsAndIntesity.setPoint(interInfos.at(i).getIntersectionPoint());
		tempInterPointsAndIntesity.setIntesity(interInfos.at(i).getLight().getIntensity());
		returnPointsAndIntesity.push_back(tempInterPointsAndIntesity);

	}

	return returnPointsAndIntesity;

}

// print all intersection points
void SequentialRayTracing::printAllIntersectionPoints()
{
	std::vector<VectorStructR3> allInterPoints = getAllIntersectionPointsSRT();
	//#pragma omp parallel for
	for (int i = 0; i < allInterPoints.size(); i++)
	{
		VectorStructR3 printInterPoint = allInterPoints.at(i);
		std::cout << "____________________________\n";
		std::cout << "intersectionpoint number: " << i << std::endl;
		std::cout << "____________________________\n";
		printInterPoint.print();
	}
}


// print all IntersectInfos from sequential raytracing
void SequentialRayTracing::printAllIntersectInfosSRT()
{
	//#pragma omp parallel for
	for (int i = 0; i < mSaveInterInfos_PosSur_TotSteps.size(); i++)
	{
		std::cout << "____________________________\n";
		std::cout << "intersection Point infos number " << i << std::endl;
		std::cout << "____________________________\n";
		IntersectInformationStruct toPrintIntersectInfos = mSaveInterInfos_PosSur_TotSteps.at(i).getIntersecInfos();
		toPrintIntersectInfos.printIntersectInformation();
		std::cout << "____________________________\n";
	}
}

// filter for all real intersection points
std::vector <IntersectInfosAndPosSurfaceAndTotalSteps>  SequentialRayTracing::filterAllRealIntersecPoints(std::vector <IntersectInfosAndPosSurfaceAndTotalSteps> SaveIntInfos_Pos_totStep_NotFiltered)
{

	int sizeOfVector = SaveIntInfos_Pos_totStep_NotFiltered.size();
	//std::vector<IntersectInfosAndPosSurfaceAndTotalSteps> returnFilteredInterPointsAndPos;
	char isRealIntersectionPoint;
	bool isNAN;
	std::vector<IntersectInfosAndPosSurfaceAndTotalSteps> returnFilteredInterPointsAndPos;
	returnFilteredInterPointsAndPos.reserve(sizeOfVector);

	for (int i = 0; i < sizeOfVector; i++)
	{
		isRealIntersectionPoint = SaveIntInfos_Pos_totStep_NotFiltered[i].getIntersecInfos().getSurfaceSide();
		isNAN = std::isnan(SaveIntInfos_Pos_totStep_NotFiltered[i].getIntersecInfos().getIntersectionPoint().getX());


		if (isRealIntersectionPoint != 'N' && isNAN == false)
		{
			returnFilteredInterPointsAndPos.push_back(SaveIntInfos_Pos_totStep_NotFiltered.at(i));
		}

	}
	

	return returnFilteredInterPointsAndPos;
}

// get all intersection points of surface i
std::vector<IntersectInformationStruct> SequentialRayTracing::getAllInterInfosOfSurf_i(unsigned int const surfaceNo)
{
	std::vector<IntersectInformationStruct> retunInterInfosSurf_i;
	//#pragma omp parallel for
	for (int i = 0; i < mSaveInterInfos_PosSur_TotSteps.size(); i++)
	{
		if (mSaveInterInfos_PosSur_TotSteps.at(i).getPosition() == surfaceNo)
		{

			retunInterInfosSurf_i.push_back(mSaveInterInfos_PosSur_TotSteps.at(i).getIntersecInfos());
		}
	}

	return retunInterInfosSurf_i;
}

// get all intersection points of surface i not filtered
// we need that for ray aiming
std::vector<IntersectInformationStruct> SequentialRayTracing::getAllInterInfosOfSurf_i_notFiltered(unsigned int const surfaceNo)
{
	std::vector<IntersectInformationStruct> retunInterInfosSurf_i_notFiltered;
	unsigned int sizeVector = mSaveIntInfos_Pos_totStep_NotFiltered.size();
	retunInterInfosSurf_i_notFiltered.resize(sizeVector);

	for (int i = 0; i < sizeVector; i++)
	{
		if (mSaveIntInfos_Pos_totStep_NotFiltered.at(i).getPosition() == surfaceNo)
		{

			retunInterInfosSurf_i_notFiltered[i] = mSaveIntInfos_Pos_totStep_NotFiltered[i].getIntersecInfos();
		}
	}

	return retunInterInfosSurf_i_notFiltered;
}

// print all intersection points at surface i
void SequentialRayTracing::printAllInterInfosAtSurface_i(unsigned int const surfaceNo)
{
	std::vector<IntersectInformationStruct> interInfosAtSurfac_i = getAllInterInfosOfSurf_i(surfaceNo);

	//#pragma omp parallel for
	for (int i = 0; i < interInfosAtSurfac_i.size(); i++)
	{
		std::cout << "______________________________\n";
		std::cout << "intersection point: " << i << std::endl;
		interInfosAtSurfac_i.at(i).printIntersectInformation();
		std::cout << "______________________________\n";
	}
}

// get all intersection points at surface i
std::vector<VectorStructR3> SequentialRayTracing::getAllInterPointsAtSurf_i_notFiltered(unsigned int const surfaceNo)
{
	std::vector<IntersectInformationStruct> interInfosAtSurfac_i = getAllInterInfosOfSurf_i(surfaceNo);
	std::vector<VectorStructR3> intersecPoints;
	//#pragma omp parallel for
	for (int i = 0; i < interInfosAtSurfac_i.size(); i++)
	{
		intersecPoints.push_back(interInfosAtSurfac_i.at(i).getIntersectionPoint());
	}

	return intersecPoints;

}

// get all intersection points of surface i filtered
std::vector<VectorStructR3> SequentialRayTracing::getAllInterPointsAtSurface_i_filtered(unsigned int const surfaceNo)
{
	std::vector<VectorStructR3> intersecPoints;
	unsigned int lenght = mSaveInterInfos_PosSur_TotSteps.size();
	unsigned int maxSizeVector = mSaveIntInfos_Pos_totStep_NotFiltered.size() / mOpticalSystem_LLT.getPosAndInteractingSurface().size();
	intersecPoints.reserve(maxSizeVector);

	for (unsigned int i = 0; i < lenght; ++i)
	{
		if (mSaveInterInfos_PosSur_TotSteps[i].getPosition() == surfaceNo)
		{
			if (mSaveInterInfos_PosSur_TotSteps[i].getIntersecInfos().getSurfaceSide() != N)
			{ 
					intersecPoints.push_back(mSaveInterInfos_PosSur_TotSteps[i].getIntersecInfos().getIntersectionPoint());
			}
		}
	}

	return intersecPoints;

}

// get intersection point i at Surface i not filtered
VectorStructR3 SequentialRayTracing::getInterPoint_i_atSurface_i_notFiltered(unsigned int const interPointNo, unsigned int const surfaceNo)
{
	VectorStructR3 interPoint_i = getAllInterPointsAtSurf_i_notFiltered(surfaceNo).at(interPointNo);
	return interPoint_i;
}


// get semi height of surface i
double  SequentialRayTracing::getSemiHeightOfSurface_i(unsigned int i)
{
	double SemiHeightOfSurface_i = mOpticalSystem_LLT.getPosAndInteractingSurface().at(i).getSurfaceInterRay_ptr()->getSemiHeight();

	return SemiHeightOfSurface_i;

}


// get point of surface i
VectorStructR3 SequentialRayTracing::getPointSurface_i(unsigned int i)
{
	VectorStructR3 pointSurface_i = mOpticalSystem_LLT.getPosAndInteractingSurface().at(i).getSurfaceInterRay_ptr()->getPoint();
	return pointSurface_i;
}


// get direction of surface_i
VectorStructR3 SequentialRayTracing::getDirectionSurface_i(unsigned int i)
{
	VectorStructR3 directionSurface_i = mOpticalSystem_LLT.getPosAndInteractingSurface().at(i).getSurfaceInterRay_ptr()->getDirection();
	return directionSurface_i;

}


// clear all traced rays 
void SequentialRayTracing::clearAllTracedRays()
{
	mSaveIntInfos_Pos_totStep_NotFiltered.clear();
	mSaveInterInfos_PosSur_TotSteps.clear();
	mSaveLightRayStructsNotFiltered.clear();
	mStartPointOfLightRays.clear();
}

// get IntersectInfos, PosSurface and TotalSteps
std::vector <IntersectInfosAndPosSurfaceAndTotalSteps> SequentialRayTracing::getInterInf_PosSurface_TotalSteps_ofSur_i(unsigned int const surfaceNo)
{
	std::vector<IntersectInfosAndPosSurfaceAndTotalSteps> returnInterInfos_PosSur_TotSteps;

	//#pragma omp parallel for
	for (int i = 0; i < mSaveInterInfos_PosSur_TotSteps.size(); i++)
	{
		if (mSaveInterInfos_PosSur_TotSteps.at(i).getPosition() == surfaceNo)
		{
			returnInterInfos_PosSur_TotSteps.push_back(mSaveInterInfos_PosSur_TotSteps.at(i));
		}
	}

	return returnInterInfos_PosSur_TotSteps;

}

// get all total optical path lenth to surface i
std::vector<real> SequentialRayTracing::getTotalOptPathLenthToSurface_i(unsigned int surfaceNo)
{
	std::vector<real> totalOptPath;

	//#pragma omp parallel for
	for (int i = 0; i < mSaveInterInfos_PosSur_TotSteps.size(); i++)
	{
		if (mSaveInterInfos_PosSur_TotSteps.at(i).getPosition() == surfaceNo)
		{
			totalOptPath.push_back(mSaveInterInfos_PosSur_TotSteps.at(i).getTotalSteps());
		}
	}

	return totalOptPath;
}


// build many lightRay along x achse(y = 0)
std::vector<LightRayStruct> SequentialRayTracing::lightRayAlongX(VectorStructR3 startPoint, unsigned int numberLightRay, real zPos, real minX, real maxX, real wavelength, real curRefInd)
{
	Light_LLT Light;

	std::vector<LightRayStruct> outputLightRay;
	std::vector<real> linDisX = Math::linDistriAlongTwoValues_double(minX, maxX, numberLightRay);

	//#pragma omp parallel for
	for (int i = 0; i < numberLightRay; i++)
	{
		VectorStructR3 tempPoint = { linDisX.at(i) , 0 ,zPos };
		VectorStructR3 tempDir = tempPoint - startPoint;
		Ray_LLT tempRay(startPoint, tempDir, curRefInd);
		Light.setWavelength(wavelength);
		LightRayStruct LightRay(Light, tempRay, 1);
		outputLightRay.push_back(LightRay);
	}

	return outputLightRay;
}

// build many lightRay along y achse (x = 0) 
std::vector<LightRayStruct>  SequentialRayTracing::lightRayAlongY(VectorStructR3 startPoint, unsigned int numberLightRay, real zPos, real minY, real maxY, real wavelength, real curRefInd)
{
	Light_LLT Light;

	std::vector<LightRayStruct> outputLightRay;
	std::vector<real> linDisY = Math::linDistriAlongTwoValues_double(minY, maxY, numberLightRay);

	//#pragma omp parallel for
	for (int i = 0; i < numberLightRay; i++)
	{
		VectorStructR3 tempPoint = { 0 ,linDisY.at(i) ,zPos };
		VectorStructR3 tempDir = tempPoint - startPoint;
		Ray_LLT tempRay(startPoint, tempDir, curRefInd);
		Light.setWavelength(wavelength);
		LightRayStruct LightRay(Light, tempRay, 1);
		outputLightRay.push_back(LightRay);
	}

	return outputLightRay;
}

// get all start points
std::vector<VectorStructR3> SequentialRayTracing::getStartPoints()
{
	return mStartPointOfLightRays;
}

// set the optical system
void SequentialRayTracing::setOpticalSystem(OpticalSystem_LLT optSysLLT)
{
	mOpticalSystem_LLT = optSysLLT;
}

void SequentialRayTracing::setOpticalSystem(OpticalSystemElement optSysHLT)
{
	mOpticalSystem_LLT = optSysHLT.getLLTconversion_doConversion();
}

// set trace to surface
void SequentialRayTracing::setTraceToSurface(unsigned int traceToSurface)
{
	mTraceToSurface_i = traceToSurface;
}

void SequentialRayTracingandColorStruct::setColor(QColor const color)
{
	mColor = color;
}

QColor SequentialRayTracingandColorStruct::getColor() const
{
	return mColor;
}

void SequentialRayTracingandColorStruct::setSequentialRayTracing(SequentialRayTracing* SeqRayTrac)
{
	mSeqRayTrac = SeqRayTrac;
}

SequentialRayTracing* SequentialRayTracingandColorStruct::getSequentialRayTracing() const
{
	return mSeqRayTrac;
}

void RayTracingSystem::fillVectorRayTracing(SequentialRayTracing* SeqRayTrac, QColor color)
{
	SequentialRayTracingandColorStruct SeqRayTracAndColorStruct;
	SeqRayTracAndColorStruct.setColor(color);
	SeqRayTracAndColorStruct.setSequentialRayTracing(SeqRayTrac);
	mSeqRayTracAndColorStruct.push_back(SeqRayTracAndColorStruct);

}

std::vector<SequentialRayTracingandColorStruct> RayTracingSystem::getVectorRayTracing()
{
	return mSeqRayTracAndColorStruct;
}