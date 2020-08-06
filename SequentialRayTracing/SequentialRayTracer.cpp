#include "SequentialRayTracer.h"
#include "..\LowLevelTracing\Ray_LLT.h"
#include<omp.h>
#include <iostream>
//#include "..\FillAptertureStop/FillApertureStop.h"
#include "..\LowLevelTracing/Surfaces/ApertureStop_LLT.h"
#include "..\RayAiming\RayAiming.h"
#include "..\FillAptertureStop\FillApertureStop.h"

IntersectInfosAndPosSurfaceAndTotalSteps::IntersectInfosAndPosSurfaceAndTotalSteps() { setNoIntersectionPoint(); };
IntersectInfosAndPosSurfaceAndTotalSteps::~IntersectInfosAndPosSurfaceAndTotalSteps() {};

// get intersection infos
IntersectInformationStruct IntersectInfosAndPosSurfaceAndTotalSteps::getIntersecInfos() const
{
	return mIntersectInfos;
}
// set intersection infos
void IntersectInfosAndPosSurfaceAndTotalSteps::setIntersectionInfos(IntersectInformationStruct const setIntersectinfos)
{
	mIntersectInfos = setIntersectinfos;
}

// set position
void IntersectInfosAndPosSurfaceAndTotalSteps::setPosition(unsigned int const pos)
{
	mPosition = pos;
}
// get position
unsigned int IntersectInfosAndPosSurfaceAndTotalSteps::getPosition() const
{
	return mPosition;
}

// set total  steps
void IntersectInfosAndPosSurfaceAndTotalSteps::setTotalSteps(real const totSte)
{
	mTotalSteps = totSte;
}
// get total steps 
real IntersectInfosAndPosSurfaceAndTotalSteps::getTotalSteps() const
{
	return mTotalSteps;
}
// no intersection point
void IntersectInfosAndPosSurfaceAndTotalSteps::setNoIntersectionPoint()
{
	mIntersectInfos.setNoIntersectionPoint();
	mPosition = 9999999999999;
	mTotalSteps = 0.0;
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
	resizeAllRelevantVectorsAndSetConst_Element();

};

SequentialRayTracing::SequentialRayTracing() {};

SequentialRayTracing::SequentialRayTracing(OpticalSystem_LLT opticalSystem) :
	mOpticalSystem_LLT(opticalSystem)
{
	resizeAllRelevantVectorsAndSetConst_LLT();
};

SequentialRayTracing::SequentialRayTracing(OpticalSystem_LLT opticalSystem, unsigned int traToSur) :
	mOpticalSystem_LLT(opticalSystem),
	mTraceToSurface_i(traToSur)
{
	mNoInterPointAndPos.setNoIntersectionPoint();
};

SequentialRayTracing::SequentialRayTracing(OpticalSystemElement opticalSysElement, LightRayStruct LightRay) :
	mOptSysEle(opticalSysElement),
	mLightRay(LightRay)

{
	resizeAllRelevantVectorsAndSetConst_Element();
	int sizeOptSysEle = opticalSysElement.getPosAndElement().size();


	// set the refractive index to the wavelenght
	for (unsigned int j = 0; j < sizeOptSysEle; j++)
	{

		mOptSysEle.getPosAndElement().at(j).getElementInOptSys_ptr()->calRefIndex_A_and_B_andSet(LightRay.getLight_LLT().getWavelength());
	}

	mOpticalSystem_LLT = mOptSysEle.getLLTconversion_doConversion();
	sequentialRayTracing(mLightRay);

}

SequentialRayTracing::SequentialRayTracing(OpticalSystemElement /*optical system element*/ opticalSysElement, VectorStructR3 /*start point lightRay*/ startPointLightRay, unsigned int /*rings*/ rings, unsigned int /*arms*/ arms, real /*refractive index*/ refIndex, Light_LLT mLight) :
	mOptSysEle(opticalSysElement),
	mOpticalSystem_LLT(opticalSysElement.getLLTconversion_doConversion())

{
	resizeAllRelevantVectorsAndSetConst_Element();
	mLightRay.setLight_LLT(mLight);
	mPositionApertureStop = findPosApertureStop(mOpticalSystem_LLT);
	setRefractivIndexOptSys(mLight.getWavelength());
	FillApertureStop fillAperStop(/*start point rays*/ startPointLightRay,/*semi height of aperture stop*/ mOpticalSystem_LLT.getPosAndInteractingSurface().at(mPositionApertureStop).getSurfaceInterRay_ptr()->getSemiHeight(),
		/*point of aperture stop*/mOpticalSystem_LLT.getPosAndInteractingSurface().at(mPositionApertureStop).getSurfaceInterRay_ptr()->getPoint(),/*direction of aperture stop*/mOpticalSystem_LLT.getPosAndInteractingSurface().at(mPositionApertureStop).getSurfaceInterRay_ptr()->getDirection(),
		/*rings*/ rings,/*arms*/ arms,/*refractive index*/ refIndex,/*wavelength*/ mLight);
	seqRayTracingWithVectorOfLightRays(fillAperStop.getVectorWithLightRays());
}

SequentialRayTracing::SequentialRayTracing(const OpticalSystemElement& /*optical system element*/ opticalSysElement, const VectorStructR3& /*start point lightRay*/ startPointLightRay, unsigned int /*rings*/ rings, unsigned int /*arms*/ arms, real /*refractive index*/ refIndex, const std::vector<Light_LLT>& light_vec) :
	mOptSysEle(opticalSysElement),
	mStartPointLightRay(startPointLightRay),
	mRings(rings),
	mArms(arms),
	mRefIndexStartPont(refIndex),
	mLight_LLT_vec(light_vec)
	
{
	resizeAllRelevantVectorsAndSetConst_Element();
	infosAS infosAS_OptSys = mOptSysEle.getLLTconversion_doConversion().getInforAS();
	FillApertureStop fillAperStop(infosAS_OptSys, mRings, mArms);
	RayAiming rayAiming;

	//(/*start point rays*/ startPointLightRay,/*semi height of aperture stop*/ mOpticalSystem_LLT.getPosAndInteractingSurface().at(mPositionApertureStop).getSurfaceInterRay_ptr()->getSemiHeight(),
	//	/*point of aperture stop*/mOpticalSystem_LLT.getPosAndInteractingSurface().at(mPositionApertureStop).getSurfaceInterRay_ptr()->getPoint(),/*direction of aperture stop*/mOpticalSystem_LLT.getPosAndInteractingSurface().at(mPositionApertureStop).getSurfaceInterRay_ptr()->getDirection(),
	//	/*rings*/ rings,/*arms*/ arms,/*refractive index*/ refIndex,/*wavelength*/ light_vec.at(i));

	//const std::vector<VectorStructR3>& pointsInAS, const VectorStructR3 startPointRay, Light_LLT mLight, real curRefracIndex
	for (unsigned int i = 0; i < light_vec.size(); i++)
	{

		// set the refractive index to the wavelenght
		for (unsigned int j = 0; j < mTraceToSurface_i; j++)
		{

			setRefractivIndexOptSys(light_vec.at(i).getWavelength());
		}
	
		mOpticalSystem_LLT = mOptSysEle.getLLTconversion_doConversion();
			
		seqRayTracingWithVectorOfLightRays(rayAiming.rayAimingMany_obj_complete(mOpticalSystem_LLT, fillAperStop.getPointsInAS(), mStartPointLightRay, light_vec.at(i), mRefIndexStartPont));

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
	mSaveTotalSteps = 0.0,
	mRay = LightRaySt.getRay_LLT();
	mLight = LightRaySt.getLight_LLT();
	
	// save the start points of the rays in an std::vector
	mStartsPointOfLightRays_vec.push_back(mRay.getOriginRay());
	
	for (int i = 0; i <= mTraceToSurface_i; i++)
	{

		//if (LightRaySt.getIsAlive() == true)
		//{
			mTempInterInfos_Pos_totStep.setIntersectionInfos(mOpticalSystem_LLT.getPosAndInteractingSurface().at(i).getSurfaceInterRay_ptr()->calculateIntersection(LightRaySt));
			mTempInterInfos_Pos_totStep.setPosition(mOpticalSystem_LLT.getPosAndInteractingSurface().at(i).getPosition());
			mSaveTotalSteps = mSaveTotalSteps + mTempInterInfos_Pos_totStep.getIntersecInfos().getStepsToWalk();
			mTempInterInfos_Pos_totStep.setTotalSteps(mSaveTotalSteps);

			mSaveIntInfos_Pos_totStep_NotFiltered.push_back(mTempInterInfos_Pos_totStep);

			mTempLightRay_vec = mOpticalSystem_LLT.getPosAndInteraction()[i].getInteractionAtSur_ptr()->calcInteraction(mTempInterInfos_Pos_totStep.getIntersecInfos());

			// TODO: Until now, there is no interaction fuction that delivers more than one light ray!
			// If we implement a function that dilivers more than one ray, we have to take that in account in the loop!!!
			mLight = mTempLightRay_vec[0].getLight_LLT();
			mRay = mTempLightRay_vec[0].getRay_LLT();
			mIsAlive = mTempLightRay_vec[0].getIsAlive();

			LightRaySt.setLight_LLT(mLight);
			LightRaySt.setRay_LLT(mRay);
			LightRaySt.setIsAlive(mIsAlive);
		

		//else
		//{
		//	mSaveIntInfos_Pos_totStep_NotFiltered.push_back(mNoInterPointAndPos);
		//	LightRaySt.setIsAlive(false);
		//}

	}

	mSaveInterInfos_PosSur_TotSteps = filterAllRealIntersecPoints(mSaveIntInfos_Pos_totStep_NotFiltered);
}

// do sequential ray tracing with an vector of many LightRay
void SequentialRayTracing::seqRayTracingWithVectorOfLightRays(const std::vector<LightRayStruct>& LightRayStVec)
{
	LightRayStruct tempLightRaySt{};
	unsigned int sizeOptSys = mOpticalSystem_LLT.getPosAndInteractingSurface().size();
	unsigned int sizeLightRayVec = LightRayStVec.size();
	unsigned int maxNumberOfIntersectionPoints = sizeOptSys * sizeLightRayVec;
	unsigned int counter = 0;

	mSaveIntInfos_Pos_totStep_NotFiltered.resize(maxNumberOfIntersectionPoints);
	mSaveInterInfos_PosSur_TotSteps.reserve(maxNumberOfIntersectionPoints);
	mStartsPointOfLightRays_vec.resize(sizeLightRayVec);

	for (unsigned int i = 0; i < sizeLightRayVec; i++)
	{
		tempLightRaySt = LightRayStVec[i];

		mSaveTotalSteps = 0.0,
		mRay = tempLightRaySt.getRay_LLT();
		mLight = tempLightRaySt.getLight_LLT();

		// save the start points of the rays in a std::vector
		mStartsPointOfLightRays_vec[i] = mRay.getOriginRay();

		for (unsigned int j = 0; j <= mTraceToSurface_i; j++)
		{
			// just for debugging
			// std::cout << counter << std::endl;

			if (tempLightRaySt.getIsAlive() == true)
			{
				mTempInterInfos_Pos_totStep.setIntersectionInfos(mOpticalSystem_LLT.getPosAndInteractingSurface().at(j).getSurfaceInterRay_ptr()->calculateIntersection(tempLightRaySt));
				mTempInterInfos_Pos_totStep.setPosition(mOpticalSystem_LLT.getPosAndInteractingSurface().at(j).getPosition());
				mSaveTotalSteps = mSaveTotalSteps + mTempInterInfos_Pos_totStep.getIntersecInfos().getStepsToWalk();
				mTempInterInfos_Pos_totStep.setTotalSteps(mSaveTotalSteps);

				mSaveIntInfos_Pos_totStep_NotFiltered[counter] = mTempInterInfos_Pos_totStep;

				

				if (mTempInterInfos_Pos_totStep.getIntersecInfos().getSurfaceSide() != N)
				{
					mSaveInterInfos_PosSur_TotSteps.push_back(mTempInterInfos_Pos_totStep);
					mTempLightRay_vec = mOpticalSystem_LLT.getPosAndInteraction()[j].getInteractionAtSur_ptr()->calcInteraction(mTempInterInfos_Pos_totStep.getIntersecInfos());
				}

				// TODO: Until now, there is no interaction fuction that delivers more than one light ray!
				// If we implement a function that dilivers more than one ray, we have to take that in account in the loop!!!

				tempLightRaySt.setLight_LLT(mTempLightRay_vec[0].getLight_LLT());
				tempLightRaySt.setRay_LLT(mTempLightRay_vec[0].getRay_LLT());


			}

			else
			{
				mSaveIntInfos_Pos_totStep_NotFiltered[counter] = mNoInterPointAndPos;
				tempLightRaySt.setLightRayAbsorb();
			}

			++counter;
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
	std::vector<LightRayStruct>::const_iterator last_core2 = lightRayStVec.begin() + 2.0 *  elementsPerVec + counter;
	std::vector<LightRayStruct> LightRayStVec_core2(first_core2, last_core2);
	returnVecDivLightRay.push_back(LightRayStVec_core2);
	counter++;

	// core3
	std::vector<LightRayStruct>::const_iterator first_core3 = lightRayStVec.begin() + 2.0 * elementsPerVec + counter;
	std::vector<LightRayStruct>::const_iterator last_core3 = lightRayStVec.begin() + 3.0 * elementsPerVec + counter;
	std::vector<LightRayStruct> LightRayStVec_core3(first_core3, last_core3);
	returnVecDivLightRay.push_back(LightRayStVec_core3);
	counter++;

	// core4
	std::vector<LightRayStruct>::const_iterator first_core4 = lightRayStVec.begin() + 3.0 * elementsPerVec + counter;
	std::vector<LightRayStruct>::const_iterator last_core4 = lightRayStVec.begin() + 4.0 * elementsPerVec + counter;
	std::vector<LightRayStruct> LightRayStVec_core4(first_core4, last_core4);
	returnVecDivLightRay.push_back(LightRayStVec_core4);
	counter++;

	// core5
	std::vector<LightRayStruct>::const_iterator first_core5 = lightRayStVec.begin() + 4.0 * elementsPerVec + counter;
	std::vector<LightRayStruct>::const_iterator last_core5 = lightRayStVec.begin() + 5.0 * elementsPerVec + counter;
	std::vector<LightRayStruct> LightRayStVec_core5(first_core5, last_core5);
	returnVecDivLightRay.push_back(LightRayStVec_core5);
	counter++;

	// core6
	std::vector<LightRayStruct>::const_iterator first_core6 = lightRayStVec.begin() + 5.0 * elementsPerVec + counter;
	std::vector<LightRayStruct>::const_iterator last_core6 = lightRayStVec.begin() + 6.0 * elementsPerVec + counter;
	std::vector<LightRayStruct> LightRayStVec_core6(first_core6, last_core6);
	returnVecDivLightRay.push_back(LightRayStVec_core6);
	counter++;

	// core7
	std::vector<LightRayStruct>::const_iterator first_core7 = lightRayStVec.begin() + 6.0 * elementsPerVec + counter;
	std::vector<LightRayStruct>::const_iterator last_core7 = lightRayStVec.begin() + 7.0 * elementsPerVec + counter;
	std::vector<LightRayStruct> LightRayStVec_core7(first_core7, last_core7);
	returnVecDivLightRay.push_back(LightRayStVec_core7);
	counter++;

	// core8
	std::vector<LightRayStruct>::const_iterator first_core8 = lightRayStVec.begin() + 7.0 * elementsPerVec + counter;
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
	pointAndIntensity tempInterPointsAndIntesity;
	for (int i = 0; i < interInfos.size(); i++)
	{		
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
	surfaceSide isRealIntersectionPoint;
	bool isNAN;
	typeLight typeLight;
	std::vector<IntersectInfosAndPosSurfaceAndTotalSteps> returnFilteredInterPointsAndPos;
	returnFilteredInterPointsAndPos.reserve(sizeOfVector);

	for (int i = 0; i < sizeOfVector; i++)
	{
		isRealIntersectionPoint = SaveIntInfos_Pos_totStep_NotFiltered[i].getIntersecInfos().getSurfaceSide();
		isNAN = std::isnan(SaveIntInfos_Pos_totStep_NotFiltered[i].getIntersecInfos().getIntersectionPoint().getX());
		typeLight = SaveIntInfos_Pos_totStep_NotFiltered[i].getIntersecInfos().getLight().getTypeLight();

		if (isRealIntersectionPoint != N && isNAN == false && typeLight != typeLight::typeDeath)
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
	retunInterInfosSurf_i_notFiltered.reserve(sizeVector);

	for (int i = 0; i < sizeVector; i++)
	{
		if (mSaveIntInfos_Pos_totStep_NotFiltered.at(i).getPosition() == surfaceNo)
		{

			retunInterInfosSurf_i_notFiltered.push_back(mSaveIntInfos_Pos_totStep_NotFiltered[i].getIntersecInfos());
		}
	}

	if (retunInterInfosSurf_i_notFiltered.size() == 0)
	{
		// surface have no intersection point
		std::cout << "the surface " << surfaceNo << "has no intersection point" << std::endl;
		IntersectInformationStruct noIntersectionPoint;
		noIntersectionPoint.setNoIntersectionPoint();
		retunInterInfosSurf_i_notFiltered.push_back(noIntersectionPoint);
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
	std::vector<IntersectInformationStruct> interInfosAtSurfac_i = getAllInterInfosOfSurf_i_notFiltered(surfaceNo);
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
			if (mSaveInterInfos_PosSur_TotSteps[i].getIntersecInfos().getSurfaceSide() != N && (std::isnan(mSaveInterInfos_PosSur_TotSteps[i].getIntersecInfos().getIntersectionPoint().getX()) == false ) && (std::isnan(mSaveInterInfos_PosSur_TotSteps[i].getIntersecInfos().getIntersectionPoint().getY()) == false) && (std::isnan(mSaveInterInfos_PosSur_TotSteps[i].getIntersecInfos().getIntersectionPoint().getZ()) == false))
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
	mStartsPointOfLightRays_vec.clear();
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
	return mStartsPointOfLightRays_vec;
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

SequentialRayTracingandColorStruct::SequentialRayTracingandColorStruct() {};
SequentialRayTracingandColorStruct::~SequentialRayTracingandColorStruct() {};
SequentialRayTracingandColorStruct::SequentialRayTracingandColorStruct(SequentialRayTracing* SeqRayTrac, QColor color) 
{
	mSeqRayTrac = SeqRayTrac;
	mColor = color;
};

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

void SequentialRayTracing::resizeAllRelevantVectorsAndSetConst_LLT()
{
	mTraceToSurface_i = mOpticalSystem_LLT.getPosAndInteractingSurface().size() - 1;
		;
	mNoInterPointAndPos.setNoIntersectionPoint();
}

void SequentialRayTracing::resizeAllRelevantVectorsAndSetConst_Element()
{
	mTraceToSurface_i = mOptSysEle.getPosAndElement().size() - 1;
	mNoInterPointAndPos.setNoIntersectionPoint();
}
