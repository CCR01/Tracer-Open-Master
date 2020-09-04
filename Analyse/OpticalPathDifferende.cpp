
//#include "types.hpp"

#include "OpticalPathDifference.h"
#include "..\LowLevelTracing\Surfaces\SphericalSurface_LLT.h"
#include "..\LowLevelTracing\Interaction\Absorb_LLT.h"
#include "..\SequentialRayTracing\SequentialRayTracer.h"

#include <cmath>
#include <limits>
#include "..\PSFfunction\PSFfunction.h"
#include <fstream>
#include <string.h>
#include <stdlib.h>





// calculate position of exit pupil in optical system according to z direction
unsigned int OPD::calcPosExPupil_Z()
{
	unsigned int i = 0.0;
	unsigned int size = mOptSys.getPosAndInteractingSurface().size();
	//

	for (i; i < size; ++i)
	{
		real Z = mOptSys.getPosAndInteractingSurface()[i].getSurfaceInterRay_ptr()->getPoint().getZ();
		if (Z >= mExitPupil->getPoint().getZ())
		{
			return mOptSys.getPosAndInteractingSurface()[i].getPosition();
		}
	}

	return i;
}






// calc reference distance for OPD
real OPD::calcRefDisForRefSphere()
{

	SequentialRayTracing seqTrace1(mOptSys);
	seqTrace1.sequentialRayTracing(mChiefLightRay);
	mChiefRayAtImage = seqTrace1.getAllInterPointsAtSurf_i_notFiltered(mPosImageSurface).at(0);
	SequentialRayTracing seqTrace2(mOptSysWithExitPupil);
	seqTrace2.sequentialRayTracing(mChiefLightRay);
	mChiefRayAtExitPupil = seqTrace2.getAllInterPointsAtSurf_i_notFiltered(mPosExPupilInOptSys).at(0);
	real refDistanceForRefSphere = Math::distanceTwoVectors(mChiefRayAtImage, mChiefRayAtExitPupil);

	return refDistanceForRefSphere;
}

// get reference point
VectorStructR3 OPD::getRefPoints()
{
	return mRefPoint;
}
// calc reference distance to calculat OPD
real OPD::calcRefDisForOPD()
{

	SequentialRayTracing seqTrace(mOptSys);
	seqTrace.sequentialRayTracing(mChiefLightRay);
	unsigned int numImaSurface = mOptSys.getNumberOfSurfaces();
	numImageSurfaceWithoutExitPupil = numImaSurface;
	mTotalStepsToImageSurfaceRef = seqTrace.getInterInf_PosSurface_TotalSteps_ofSur_i(numImaSurface).at(0).getTotalSteps();

	// ref point
	mRefPoint = seqTrace.getInterInf_PosSurface_TotalSteps_ofSur_i(numImaSurface).at(0).getIntersecInfos().getIntersectionPoint();

	real dis2 = mRadiusRefSphere;
	real returnDis;

	if (numImaSurface > mPosExPupilInOptSys)
	{
		returnDis = mTotalStepsToImageSurfaceRef - dis2;
	}

	else
	{
		returnDis = mTotalStepsToImageSurfaceRef + dis2;
	}

	return returnDis;
}

// calc OPD in X direction
std::vector<cv::Point2d> OPD::calcOPD_X()
{
	Absorb_LLT Absorb;
	std::vector<cv::Point2d> returnOPD_X;

	// check if the exit pupil is behind the image surface
	if (mPosImageSurface <= mPosExPupilInOptSys)
	{
		// fill in reference sphere
		OpticalSystem_LLT OptSysWithRefSphere;
		OptSysWithRefSphere = mOptSys;
		OptSysWithRefSphere.fillInSurfaceAndInteracAtPos_i(mPosExPupilInOptSys, mRefSphere.clone(), mDoNothingInteraction_ptr);

		SequentialRayTracing seqTraceRefSphere(OptSysWithRefSphere);
		seqTraceRefSphere.seqRayTracingWithVectorOfLightRays(mLightRayX);

		SequentialRayTracing seqTraceExitPup(mOptSysWithExitPupil);
		seqTraceExitPup.seqRayTracingWithVectorOfLightRays(mLightRayX);

		for (unsigned int i = 0; i < seqTraceRefSphere.getAllInterPointsAtSurf_i_notFiltered(mPosExPupilInOptSys).size(); i++)
		{
			// according to ZEMAX we give the OPD in the wavelenth unitof the chief ray
			real tempOPD = ((mRefDistance - seqTraceRefSphere.getInterInf_PosSurface_TotalSteps_ofSur_i(mPosExPupilInOptSys).at(i).getTotalSteps()) / mChiefLightRay.getLight_LLT().getWavelength()) * 1000000;

			cv::Point2d tempPoint(mChiefRayAtExitPupil.getX() - seqTraceExitPup.getAllInterPointsAtSurf_i_notFiltered(mPosExPupilInOptSys).at(i).getX(), tempOPD);
			returnOPD_X.push_back(tempPoint);
		}

		return returnOPD_X;
	}

	SequentialRayTracing seqTrace(mOptSys);
	SequentialRayTracing seqTraceWithExitPupil(mOptSysWithExitPupil);
	// trace all ray
	seqTrace.seqRayTracingWithVectorOfLightRays(mLightRayX);
	seqTraceWithExitPupil.seqRayTracingWithVectorOfLightRays(mLightRayX);
	// save all total steps to image (last) surface
	std::vector<real> totalStepsToImageSurface = seqTrace.getTotalOptPathLenthToSurface_i(mPosImageSurface);
	std::vector<VectorStructR3> posInExitPupilForEveryRay = seqTraceWithExitPupil.getAllInterPointsAtSurf_i_notFiltered(mPosExPupilInOptSys);
	// *** passt
	OpticalSystem_LLT OptSysOPDX;
	OptSysOPDX.fillVectorSurfaceAndInteractingData(0, mRefSphere.clone(), Absorb.clone());
	// *** passt
	std::vector<LightRayStruct> LightRaysToTraceBack;
	Ray_LLT ray;
	Light_LLT light;
	LightRayStruct lightRay(light, ray, 1);
	std::vector<VectorStructR3> posInExitPupil;




	// build light rays to trace back and save position in exit pupil
	for (unsigned int i = 0; i < seqTrace.getInterInf_PosSurface_TotalSteps_ofSur_i(mPosImageSurface).size(); i++)
	{
		VectorStructR3 tempOrigin = seqTrace.getAllInterPointsAtSurf_i_notFiltered(mPosImageSurface).at(i);
		VectorStructR3 tempDirection = -1 * seqTrace.getAllInterInfosOfSurf_i(mPosImageSurface).at(i).getDirectionRayUnit(); // direction to trace back
		real tempWavelenth = seqTrace.getAllInterInfosOfSurf_i(mPosImageSurface).at(i).getLight().getWavelength();
		surfaceSide tempSurSide = seqTrace.getAllInterInfosOfSurf_i(mPosImageSurface).at(i).getSurfaceSide();
		real tempCurRefIndex;

		// check from witch side the ray interact with the exit pupil
		if (tempSurSide == A)
		{
			tempCurRefIndex = seqTrace.getAllInterInfosOfSurf_i(mPosImageSurface).at(i).getRefractiveIndex_A();
		}

		else if (tempSurSide == B)
		{
			tempCurRefIndex = seqTrace.getAllInterInfosOfSurf_i(mPosImageSurface).at(i).getRefractiveIndex_B();
		}

		else // there must be a mistake!!!
		{
			std::cout << "there is a mistake in calculating the OPD!" << std::endl;
		}

		Ray_LLT tempRay(tempOrigin, tempDirection, tempCurRefIndex);
		lightRay.setRay_LLT(tempRay);
		light.setWavelength(tempWavelenth);
		lightRay.setLight_LLT(light);
		LightRaysToTraceBack.push_back(lightRay);
	}

	SequentialRayTracing seqTraceBack(OptSysOPDX);
	seqTraceBack.seqRayTracingWithVectorOfLightRays(LightRaysToTraceBack);
	std::vector<real> totalSteps;

	for (unsigned int i = 0; i < seqTraceBack.getAllInterInfosOfSurf_i(0).size(); i++)
	{
		real tempDisObToIm = totalStepsToImageSurface.at(i);
		real tempDisImToRefSphere = seqTraceBack.getAllInterInfosOfSurf_i(0).at(i).getStepsToWalk();
		totalSteps.push_back(tempDisObToIm - tempDisImToRefSphere);
	}

	cv::Point2d OPDinOnePoint;

	// the x value is the position in the exit pupil and the y value is the OPD 
	// save OPD and position in exit pupil
	for (unsigned int i = 0; i < totalSteps.size(); i++)
	{
		OPDinOnePoint.x = posInExitPupilForEveryRay.at(i).getX();
		// according to ZEMAX we give the OPD in the wavelenth unitof the chief ray
		OPDinOnePoint.y = ((mRefDistance - totalSteps.at(i)) / mChiefLightRay.getLight_LLT().getWavelength()) * 1000;
		returnOPD_X.push_back(OPDinOnePoint);
	}


	return returnOPD_X;
}

// calc OPD in Y direction
std::vector<cv::Point2d> OPD::calcOPD_Y()
{
	Absorb_LLT Absorb;
	std::vector<cv::Point2d> returnOPD_Y;

	// check if the exit pupil is behind the image surface
	if (mPosImageSurface <= mPosExPupilInOptSys)
	{
		// fill in reference sphere
		OpticalSystem_LLT OptSysWithRefSphere;
		OptSysWithRefSphere = mOptSys;
		OptSysWithRefSphere.fillInSurfaceAndInteracAtPos_i(mPosExPupilInOptSys, mRefSphere.clone(), mDoNothingInteraction_ptr);

		SequentialRayTracing seqTraceRefSphere(OptSysWithRefSphere); // optical system include referece sphere
		seqTraceRefSphere.seqRayTracingWithVectorOfLightRays(mLightRayY);

		SequentialRayTracing seqTraceExitPup(mOptSysWithExitPupil); // optical system include exit pupil (plan surface)
		seqTraceExitPup.seqRayTracingWithVectorOfLightRays(mLightRayY);

		for (unsigned int i = 0; i < seqTraceRefSphere.getAllInterPointsAtSurf_i_notFiltered(mPosExPupilInOptSys).size(); i++)
		{
			// according to ZEMAX we give the OPD in the wavelenth unit of the chief ray
			real tempOPD = ((mRefDistance - seqTraceRefSphere.getInterInf_PosSurface_TotalSteps_ofSur_i(mPosExPupilInOptSys).at(i).getTotalSteps()) / mChiefLightRay.getLight_LLT().getWavelength()) * 1000000;

			cv::Point2d tempPoint(mChiefRayAtExitPupil.getY() - seqTraceRefSphere.getAllInterPointsAtSurf_i_notFiltered(mPosExPupilInOptSys).at(i).getY(), tempOPD);
			returnOPD_Y.push_back(tempPoint);
		}

		return returnOPD_Y;
	}

	// exit pupil is not behind the image surface
	SequentialRayTracing seqTrace(mOptSys);
	SequentialRayTracing seqTraceWithExitPupil(mOptSysWithExitPupil);
	// trace all ray
	seqTrace.seqRayTracingWithVectorOfLightRays(mLightRayY);
	seqTraceWithExitPupil.seqRayTracingWithVectorOfLightRays(mLightRayY);
	// save all total steps to image (last) surface
	std::vector<real> totalStepsToImageSurface = seqTrace.getTotalOptPathLenthToSurface_i(mPosImageSurface);
	std::vector<VectorStructR3> posInExitPupilForEveryRay = seqTraceWithExitPupil.getAllInterPointsAtSurf_i_notFiltered(mPosExPupilInOptSys);
	// *** passt
	OpticalSystem_LLT OptSysOPDY;
	OptSysOPDY.fillVectorSurfaceAndInteractingData(0, &mRefSphere, Absorb.clone());
	// *** passt
	std::vector<LightRayStruct> LightRaysToTraceBack;
	Ray_LLT ray;
	Light_LLT light;
	LightRayStruct lightRay(light, ray, 1);
	std::vector<VectorStructR3> posInExitPupil;

	// bild light rays to trace back and save position in exit pupil
	for (unsigned int i = 0; i < seqTrace.getInterInf_PosSurface_TotalSteps_ofSur_i(mPosImageSurface).size(); i++)
	{
		VectorStructR3 tempOrigin = seqTrace.getAllInterPointsAtSurf_i_notFiltered(mPosImageSurface).at(i);
		VectorStructR3 tempDirection = -1 * seqTrace.getAllInterInfosOfSurf_i(mPosImageSurface).at(i).getDirectionRayUnit(); // direction to trace back
		real tempWavelenth = seqTrace.getAllInterInfosOfSurf_i(mPosImageSurface).at(i).getLight().getWavelength();
		surfaceSide tempSurSide = seqTrace.getAllInterInfosOfSurf_i(mPosImageSurface).at(i).getSurfaceSide();
		real tempCurRefIndex;

		// check from witch side the ray interact with the exit pupil
		if (tempSurSide == A)
		{
			tempCurRefIndex = seqTrace.getAllInterInfosOfSurf_i(mPosImageSurface).at(i).getRefractiveIndex_A();
		}

		else if (tempSurSide == B)
		{
			tempCurRefIndex = seqTrace.getAllInterInfosOfSurf_i(mPosImageSurface).at(i).getRefractiveIndex_B();
		}

		else // there must be a mistake!!!
		{
			std::cout << "there is a mistake in calculating the OPD!" << std::endl;
		}

		Ray_LLT tempRay(tempOrigin, tempDirection, tempCurRefIndex);
		lightRay.setRay_LLT(tempRay);
		light.setWavelength(tempWavelenth);
		lightRay.setLight_LLT(light);
		LightRaysToTraceBack.push_back(lightRay);
	}


	SequentialRayTracing seqTraceBack(OptSysOPDY);
	seqTraceBack.seqRayTracingWithVectorOfLightRays(LightRaysToTraceBack);
	std::vector<real> totalSteps;

	// save the total steps (distance obj to image - distance image to referece sphere)
	for (unsigned int i = 0; i < seqTraceBack.getAllInterInfosOfSurf_i(0).size(); i++)
	{
		real tempDisObToIm = totalStepsToImageSurface.at(i);
		real tempDisImToRefSphere = seqTraceBack.getAllInterInfosOfSurf_i(0).at(i).getStepsToWalk();
		totalSteps.push_back(tempDisObToIm - tempDisImToRefSphere);
	}

	cv::Point2d OPDinOnePoint;

	// the x value is the position in the exit pupil and the y value is the OPD 
	// save OPD and position in exit pupil
	for (unsigned int i = 0; i < totalSteps.size(); i++)
	{

		OPDinOnePoint.x = posInExitPupilForEveryRay.at(i).getY();
		// according to ZEMAX we give the OPD in the wavelenth unitof the chief ray
		OPDinOnePoint.y = ((mRefDistance - totalSteps.at(i)) / mChiefLightRay.getLight_LLT().getWavelength()) * 1000;
		returnOPD_Y.push_back(OPDinOnePoint);
	}


	return returnOPD_Y;
}




// get position of exit pupil in optical system
unsigned int OPD::getPosExPupilInOptSys()
{
	return mPosExPupilInOptSys;
}

// get points OPD in Y direction
std::vector<cv::Point2d> OPD::getPointsOPD_Y()
{
	return mOPD_Y;
}

// get points in X direction
std::vector<cv::Point2d> OPD::getPointsOPD_X()
{
	return mOPD_X;
}



// get OPD X in std::vector
std::vector<real> OPD::getOPD_X_inVec()
{
	std::vector<real> outputOPD_X;
	for (unsigned int i = 0; i < mOPD_X.size(); i++)
	{
		outputOPD_X.push_back(mOPD_X.at(i).y);
	}

	return outputOPD_X;
}

// get OPD Y in std::vector
std::vector<real> OPD::getOPD_Y_inVec()
{
	std::vector<real> outputOPD_Y;
	for (unsigned int i = 0; i < mOPD_Y.size(); i++)
	{
		outputOPD_Y.push_back(mOPD_Y.at(i).y);
	}

	return outputOPD_Y;
}

// calc global optical path difference 
cv::Mat OPD::calcGlobalOPD()
{

	unsigned int numerOfRay = mLightRayFillAperturStop.size();
	//
	unsigned int sizeOfMatrixToCalcOPD = 33;
	//
	cv::Mat returnGlobalOPD = cv::Mat::zeros(sizeOfMatrixToCalcOPD, sizeOfMatrixToCalcOPD, CV_64F);


	// check if the exit pupil is behind the image surface
	// if not, we have to fill the reference sphere!
	if (mPosImageSurface <= mPosExPupilInOptSys)
	{
		// fill in reference sphere
		OpticalSystem_LLT OptSysWithRefSphere;
		OptSysWithRefSphere = mOptSys;
		OptSysWithRefSphere.fillInSurfaceAndInteracAtPos_i(mPosExPupilInOptSys, mRefSphere.clone(), mDoNothingInteraction_ptr);

		SequentialRayTracing seqTraceRefSphere(OptSysWithRefSphere); // optical system include referece sphere
		seqTraceRefSphere.seqRayTracingWithVectorOfLightRays(mLightRayFillAperturStop);

		SequentialRayTracing seqTraceExitPup(mOptSysWithExitPupil); // optical system include exit pupil (plan surface)
		seqTraceExitPup.seqRayTracingWithVectorOfLightRays(mLightRayFillAperturStop);

		std::vector<real> vectorXvalues;
		std::vector<real> vectorYvalues;



		for (unsigned int i = 0; i < seqTraceRefSphere.getAllInterPointsAtSurf_i_notFiltered(mPosExPupilInOptSys).size(); i++)
		{
			// get all X values of the intersection points at the exitpupil (ref sphere)
			real tempXvalue = mChiefRayAtExitPupil.getX() - seqTraceRefSphere.getAllInterPointsAtSurf_i_notFiltered(mPosExPupilInOptSys).at(i).getX();

			vectorXvalues.push_back(tempXvalue);

			// get all Y values of the intersection points at the exitpupil (ref sphere)
			real tempYvalue = mChiefRayAtExitPupil.getY() - seqTraceRefSphere.getAllInterPointsAtSurf_i_notFiltered(mPosExPupilInOptSys).at(i).getY();
			vectorYvalues.push_back(tempYvalue);
		}

		real maxValueInX_Direction = Math::maxValueOfVactor(vectorXvalues);
		real minValueInX_Direction = Math::minValueOfVector(vectorXvalues);
		real maxValueInY_Direction = Math::maxValueOfVactor(vectorYvalues);
		real minValueInY_Direction = Math::minValueOfVector(vectorYvalues);

		switch (mScaling)
		{
		case 0:
		{
			real maxABSValueInX_Direction = maxValueInX_Direction;
			if (maxValueInX_Direction < std::abs(minValueInX_Direction))
			{
				maxABSValueInX_Direction = std::abs(minValueInX_Direction);
			}

			real maxABSValueInY_Direction = maxValueInY_Direction;
			if (maxValueInY_Direction < std::abs(minValueInY_Direction))
			{
				maxABSValueInY_Direction = std::abs(minValueInY_Direction);
			}

			for (unsigned int i = 0; i < seqTraceRefSphere.getAllInterPointsAtSurf_i_notFiltered(mPosExPupilInOptSys).size(); i++)
			{
				// according to ZEMAX we give the OPD in the wavelenth unit of the chief ray
				real tempOPD = ((mRefDistance - seqTraceRefSphere.getInterInf_PosSurface_TotalSteps_ofSur_i(mPosExPupilInOptSys).at(i).getTotalSteps()) / mChiefLightRay.getLight_LLT().getWavelength()) * 1000000;

				//***
				// just for debugging
				mVecWithAllCalcGlobalOPD.push_back(tempOPD);
				//***


				real scalePositionTempOPD_X = vectorXvalues.at(i) / maxABSValueInX_Direction;
				real scalePositionTempOPD_Y = vectorYvalues.at(i) / maxABSValueInY_Direction;

				// fill the matrix with the OPD valus
				int matrixScalePosTempOPD_X = sizeOfMatrixToCalcOPD / 2 + scalePositionTempOPD_X * sizeOfMatrixToCalcOPD / 2;
				//std::cout << matrixScalePosTempOPD_X << std::endl ;
				//std::cout << "pos OPD X " << matrixScalePosTempOPD_X << std::endl;

				int matrixScalePosTempOPD_Y = sizeOfMatrixToCalcOPD / 2 - scalePositionTempOPD_Y * sizeOfMatrixToCalcOPD / 2;
				//std::cout << matrixScalePosTempOPD_Y << std::endl;
				//std::cout << "pos OPD Y " << matrixScalePosTempOPD_Y << std::endl;
				//std::cout << std::endl;
				// hier gehts weiter!!!

				returnGlobalOPD.at<real>(matrixScalePosTempOPD_Y, matrixScalePosTempOPD_X) = tempOPD;

			}


		}
		break;


		case 1:
		{
			// the case for mScaling = 1 is not testet!!! TODO: test it!!!
			std::cout << "mScaling = 1 is not testet!!! We have to do this in the future!!!" << std::endl;
			for (unsigned int i = 0; i < seqTraceRefSphere.getAllInterPointsAtSurf_i_notFiltered(mPosExPupilInOptSys).size(); i++)
			{
				// according to ZEMAX we give the OPD in the wavelenth unit of the chief ray
				real tempOPD = ((mRefDistance - seqTraceRefSphere.getInterInf_PosSurface_TotalSteps_ofSur_i(mPosExPupilInOptSys).at(i).getTotalSteps()) / mChiefLightRay.getLight_LLT().getWavelength()) * 1000000;

				//***
				// just for debugging
				mVecWithAllCalcGlobalOPD.push_back(tempOPD);
				//***
				real scalePositionTempOPD_X;
				real scalePositionTempOPD_Y;
				if (vectorXvalues.at(i) > 0)
				{
					scalePositionTempOPD_X = vectorXvalues.at(i) / maxValueInX_Direction;
				}
				else
				{
					scalePositionTempOPD_X = vectorXvalues.at(i) / std::abs(minValueInX_Direction);
				}
				if (vectorYvalues.at(i) > 0)
				{
					scalePositionTempOPD_Y = vectorYvalues.at(i) / maxValueInY_Direction;
				}
				else
				{
					scalePositionTempOPD_Y = vectorYvalues.at(i) / std::abs(minValueInY_Direction);
				}

				//real scalePositionTempOPD_X = vectorXvalues.at(i) / maxABSValueInX_Direction;
				//real scalePositionTempOPD_Y = vectorYvalues.at(i) / maxABSValueInY_Direction;

				// fill the matrix with the OPD valus
				int matrixScalePosTempOPD_X = sizeOfMatrixToCalcOPD / 2 + scalePositionTempOPD_X * sizeOfMatrixToCalcOPD / 2;
				//std::cout << matrixScalePosTempOPD_X << std::endl ;
				//std::cout << "pos OPD X " << matrixScalePosTempOPD_X << std::endl;

				int matrixScalePosTempOPD_Y = sizeOfMatrixToCalcOPD / 2 - scalePositionTempOPD_Y * sizeOfMatrixToCalcOPD / 2;
				//std::cout << matrixScalePosTempOPD_Y << std::endl;
				//std::cout << "pos OPD Y " << matrixScalePosTempOPD_Y << std::endl;
				//std::cout << std::endl;
				// hier gehts weiter!!!

				returnGlobalOPD.at<real>(matrixScalePosTempOPD_Y, matrixScalePosTempOPD_X) = tempOPD;

			}

		}
		break;

		default: std::cout << "scalling can be 0 or 1;" << std::endl;
			break;
		}



		//mGlobalOPD = returnGlobalOPD;

		// we need that for debugging
		//exportCV_MatToExcel(mGlobalOPD, "D:\OPDglobalE1_Field.csv");

		return returnGlobalOPD;
	}
	//***
	// exit pupil is not behind the image surface
	//***
	else {
		SequentialRayTracing seqTrace(mOptSys);
		SequentialRayTracing seqTraceWithExitPupil(mOptSysWithExitPupil);
		// trace all ray
		seqTrace.seqRayTracingWithVectorOfLightRays(mLightRayFillAperturStop);
		seqTraceWithExitPupil.seqRayTracingWithVectorOfLightRays(mLightRayFillAperturStop);
		// save all total steps to image (last) surface
		std::vector<real> totalStepsToImageSurface = seqTrace.getTotalOptPathLenthToSurface_i(mPosImageSurface);
		std::vector<VectorStructR3> posInExitPupilForEveryRay = seqTraceWithExitPupil.getAllInterPointsAtSurf_i_notFiltered(mPosExPupilInOptSys);
		OpticalSystem_LLT OptSysOPDglobal;
		Absorb_LLT Absorb;
		OptSysOPDglobal.fillVectorSurfaceAndInteractingData(0, &mRefSphere, Absorb.clone());
		std::vector<LightRayStruct> LightRaysToTraceBack;
		//Ray_LLT ray;
		//Light_LLT light;
		LightRayStruct lightRay;
		Light_LLT light;
		std::vector<VectorStructR3> posInExitPupil;

		// bild light rays to trace back and save position in exit pupil
		for (unsigned int i = 0; i < seqTrace.getInterInf_PosSurface_TotalSteps_ofSur_i(mPosImageSurface).size(); i++)
		{
			VectorStructR3 tempOrigin = seqTrace.getAllInterPointsAtSurf_i_notFiltered(mPosImageSurface).at(i);
			VectorStructR3 tempDirection = -1 * seqTrace.getAllInterInfosOfSurf_i(mPosImageSurface).at(i).getDirectionRayUnit(); // direction to trace back
			real tempWavelenth = seqTrace.getAllInterInfosOfSurf_i(mPosImageSurface).at(i).getLight().getWavelength();
			surfaceSide tempSurSide = seqTrace.getAllInterInfosOfSurf_i(mPosImageSurface).at(i).getSurfaceSide();
			real tempCurRefIndex;

			// check from witch side the ray interact with the exit pupil
			if (tempSurSide == A)
			{
				tempCurRefIndex = seqTrace.getAllInterInfosOfSurf_i(mPosImageSurface).at(i).getRefractiveIndex_A();
			}

			else if (tempSurSide == B)
			{
				tempCurRefIndex = seqTrace.getAllInterInfosOfSurf_i(mPosImageSurface).at(i).getRefractiveIndex_B();
			}

			else // there must be a mistake!!!
			{
				std::cout << "there is a mistake in calculating the OPD!" << std::endl;
			}

			Ray_LLT tempRay(tempOrigin, tempDirection, tempCurRefIndex);
			light.setWavelength(tempWavelenth);
			lightRay.setRay_LLT(tempRay);
			lightRay.setLight_LLT(light);
			LightRaysToTraceBack.push_back(lightRay); // save all light rays to trace back in a vector
		}


		SequentialRayTracing seqTraceBack(OptSysOPDglobal);
		seqTraceBack.seqRayTracingWithVectorOfLightRays(LightRaysToTraceBack);
		std::vector<real> totalStepsToRefSphere;

		// save the total steps (distance obj to image - distance image to referece sphere)
		for (unsigned int i = 0; i < seqTraceBack.getAllInterInfosOfSurf_i(0).size(); i++)
		{
			real tempDisObToIm = totalStepsToImageSurface.at(i);
			real tempDisImToRefSphere = seqTraceBack.getAllInterInfosOfSurf_i(0).at(i).getStepsToWalk();
			totalStepsToRefSphere.push_back(tempDisObToIm - tempDisImToRefSphere);
		}

		std::vector<real> vectorXvalues;
		std::vector<real> vectorYvalues;



		for (unsigned int i = 0; i < seqTraceBack.getAllInterPointsAtSurf_i_notFiltered(0).size(); i++)
		{
			// get all X values of the intersection points at the exitpupil
			real tempXvalue = mChiefRayAtExitPupil.getX() - seqTraceBack.getAllInterPointsAtSurf_i_notFiltered(0).at(i).getX();
			vectorXvalues.push_back(tempXvalue);

			// get all Y values of the intersection points at the exitpupil
			real tempYvalue = mChiefRayAtExitPupil.getY() - seqTraceBack.getAllInterPointsAtSurf_i_notFiltered(0).at(i).getY();
			vectorYvalues.push_back(tempYvalue);
		}



		real maxValueInX_Direction = Math::maxValueOfVactor(vectorXvalues);
		real minValueInX_Direction = Math::minValueOfVector(vectorXvalues);
		real maxValueInY_Direction = Math::maxValueOfVactor(vectorYvalues);
		real minValueInY_Direction = Math::minValueOfVector(vectorYvalues);

		switch (mScaling)
		{
		case 0:
		{
			// save OPD and position in exit pupil
			real maxABSValueInX_Direction = maxValueInX_Direction;
			if (maxValueInX_Direction < std::abs(minValueInX_Direction))
			{
				maxABSValueInX_Direction = std::abs(minValueInX_Direction);
			}

			real maxABSValueInY_Direction = maxValueInY_Direction;
			if (maxValueInY_Direction < std::abs(minValueInY_Direction))
			{
				maxABSValueInY_Direction = std::abs(minValueInY_Direction);
			}

			// save the OPD in a cv matrix
			for (unsigned int i = 0; i < seqTraceBack.getAllInterPointsAtSurf_i_notFiltered(0).size(); i++)
			{
				// according to ZEMAX we give the OPD in the wavelenth unit of the chief ray
				real tempOPD = ((mRefDistance - totalStepsToRefSphere.at(i)) / mChiefLightRay.getLight_LLT().getWavelength()) * 1000000;

				//***
				// just for debugging
				mVecWithAllCalcGlobalOPD.push_back(tempOPD);
				//***


				// scale the position in X and Y direction
				// max value in X and Y is 1

				real scalePosTempOPD_X = vectorXvalues.at(i) / maxABSValueInX_Direction;
				real scalePosTempOPD_Y = vectorYvalues.at(i) / maxABSValueInY_Direction;

				// fill the matrix with the OPD valus
				int matrixScalePosTempOPD_X = sizeOfMatrixToCalcOPD / 2 - scalePosTempOPD_X * sizeOfMatrixToCalcOPD / 2;
				//std::cout << "pos OPD X " << matrixScalePosTempOPD_X << std::endl;

				int matrixScalePosTempOPD_Y = sizeOfMatrixToCalcOPD / 2 + scalePosTempOPD_Y * sizeOfMatrixToCalcOPD / 2;
				//std::cout << "pos OPD Y " << matrixScalePosTempOPD_Y << std::endl;
				//std::cout << std::endl;
				// hier gehts weiter!!!

				returnGlobalOPD.at<real>(matrixScalePosTempOPD_Y, matrixScalePosTempOPD_X) = tempOPD;
			}
		}
		break;

		case 1:
		{
			// the case for mScaling = 1 is not testet!!! TODO: test it!!!
			std::cout << "mScaling = 1 is not testet!!! We have to do this in the future!!!" << std::endl;
			for (unsigned int i = 0; i < seqTraceBack.getAllInterPointsAtSurf_i_notFiltered(0).size(); i++)
			{
				// according to ZEMAX we give the OPD in the wavelenth unit of the chief ray
				real tempOPD = ((mRefDistance - totalStepsToRefSphere.at(i)) / mChiefLightRay.getLight_LLT().getWavelength()) * 1000000;

				//***
				// just for debugging
				mVecWithAllCalcGlobalOPD.push_back(tempOPD);
				//***
				real scalePositionTempOPD_X;
				real scalePositionTempOPD_Y;
				if (vectorXvalues.at(i) > 0)
				{
					scalePositionTempOPD_X = vectorXvalues.at(i) / maxValueInX_Direction;
				}
				else
				{
					scalePositionTempOPD_X = vectorXvalues.at(i) / std::abs(minValueInX_Direction);
				}
				if (vectorYvalues.at(i) > 0)
				{
					scalePositionTempOPD_Y = vectorYvalues.at(i) / maxValueInY_Direction;
				}
				else
				{
					scalePositionTempOPD_Y = vectorYvalues.at(i) / std::abs(minValueInY_Direction);
				}

				//real scalePositionTempOPD_X = vectorXvalues.at(i) / maxABSValueInX_Direction;
				//real scalePositionTempOPD_Y = vectorYvalues.at(i) / maxABSValueInY_Direction;

				// fill the matrix with the OPD valus
				int matrixScalePosTempOPD_X = sizeOfMatrixToCalcOPD / 2 - scalePositionTempOPD_X * sizeOfMatrixToCalcOPD / 2;
				//std::cout << matrixScalePosTempOPD_X << std::endl ;
				//std::cout << "pos OPD X " << matrixScalePosTempOPD_X << std::endl;

				int matrixScalePosTempOPD_Y = sizeOfMatrixToCalcOPD / 2 + scalePositionTempOPD_Y * sizeOfMatrixToCalcOPD / 2;
				//std::cout << matrixScalePosTempOPD_Y << std::endl;
				//std::cout << "pos OPD Y " << matrixScalePosTempOPD_Y << std::endl;
				//std::cout << std::endl;
				// hier gehts weiter!!!

				returnGlobalOPD.at<real>(matrixScalePosTempOPD_Y, matrixScalePosTempOPD_X) = tempOPD;

			}

		}
		break;

		}
	}


	//mGlobalOPD = returnGlobalOPD;

	// we need that for debugging
	//exportCV_MatToExcel(mGlobalOPD, "D:\OPDglobal_leftFromImage.csv");

	return returnGlobalOPD;

}

// get global OPD
cv::Mat OPD::getGlobalOPD()
{
	return mGlobalOPD;
}

// export a cv::mat to excel
void OPD::exportCV_MatToExcel(cv::Mat matToExport, std::string locationAndfilename)
{

	std::ofstream outData;
	outData.open(locationAndfilename, std::ios::app);
	outData << matToExport << std::endl;
}

// get vector with all calculated global OPD --> just for debugging
std::vector<real> OPD::getVecWithAllCalcGlobalOPD()
{
	return mVecWithAllCalcGlobalOPD;
}

double OPD::bilinear_interpolator(double fxfy, double fxcy, double cxfy, double cxcy, int fx, int cx, int fy, int cy, double actualX, double actualY)
{

	if (((fx - cx) == 0) || ((fy - cy) == 0)) {
		return (fxfy + fxcy + cxfy + cxcy) / 4;
	}

	double A0 = (double)(fxfy*cx*cy - fxcy * cx*fy - cxfy * fx*cy + cxcy * fx*fy) / (double)((fx - cx)*(fy - cy));
	double A1 = (double)((-1)*fxfy*cy + fxcy * fy + cxfy * cy + (-1)*cxcy*fy) / (double)((fx - cx)*(fy - cy));
	double A2 = (double)(-1 * fxfy*cx + fxcy * cx + cxfy * fx + -1 * cxcy*fx) / (double)((fx - cx)*(fy - cy));
	double A3 = (double)(fxfy - fxcy - cxfy + cxcy) / (double)((fx - cx)*(fy - cy));

	double sol = A0 + A1 * actualX + A2 * actualY + A3 * actualX*actualY;
	return sol;

}


//upsampling OPD
cv::Mat OPD::calcUpscaledGlobalOPD()
{
	//for MTF calculation
	int N = upscaledMatrixSize;
	double ratio = (double)(mGlobalOPD.cols - 1) / (double)(upscaledMatrixSize - 1);
	//std::cout << mGlobalOPD << std::endl;






	cv::Mat mUpscaledGlobalOPD = cv::Mat::zeros(N, N, CV_64F);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int fx = floor((double)(i)*ratio);
			int fy = floor((double)(j)*ratio);
			int cx = ceil((double)(i)*ratio);
			int cy = ceil((double)(j)*ratio);
			double actualX = double(i)*ratio;
			double actualY = double(j)*ratio;

			mUpscaledGlobalOPD.at<double>(i, j) = bilinear_interpolator(mGlobalOPD.at<double>(fx, fy), mGlobalOPD.at<double>(fx, cy),
				mGlobalOPD.at<double>(cx, fy), mGlobalOPD.at<double>(cx, cy),
				fx, cx, fy, cy,
				actualX, actualY);
		}

	}


	return mUpscaledGlobalOPD;
}

//downsampling matrix size for PSF calculations 
cv::Mat OPD::calcSampledOPDMatrixforPSF()
{
	double a = mGlobalOPD.cols;
	double b = sqrt(32 / a);
	double  SampledMatrixSizeforPSF = floor(mGlobalOPD.cols * b); /* effective grid size for PSF calculation*/
	int N = SampledMatrixSizeforPSF;
	double ratio = (double)(mGlobalOPD.cols - 1) / (double)(SampledMatrixSizeforPSF - 1);



	cv::Mat mSampledOPDMatrixforPSF = cv::Mat::zeros(N, N, CV_64F);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int fx = floor((double)(i)*ratio);
			int fy = floor((double)(j)*ratio);
			int cx = ceil((double)(i)*ratio);
			int cy = ceil((double)(j)*ratio);
			double actualX = double(i)*ratio;
			double actualY = double(j)*ratio;

			mSampledOPDMatrixforPSF.at<double>(i, j) = bilinear_interpolator(mGlobalOPD.at<double>(fx, fy), mGlobalOPD.at<double>(fx, cy),
				mGlobalOPD.at<double>(cx, fy), mGlobalOPD.at<double>(cx, cy),
				fx, cx, fy, cy,
				actualX, actualY);
			/*std::cout << mUpscaledGlobalOPD.at<double>(i, j)<<" ";*/
		}
		/*std::cout << std::endl;*/
	}
	return mSampledOPDMatrixforPSF;

}



//fuction to calculate FFT
cv::Mat OPD::calcFFT(cv::Mat Matrix)
{

	//write function to get fft, add padding here it self. Nyquist rule = 2 times the array. that means if matrix is 32x32, the after padding it should be 64x64.

	int N = Matrix.cols;
	if (N % 2 == 1)
	{
		N = N + 1;
	}
	cv::Mat I = cv::Mat::zeros(2 * N, 2 * N, CV_64F);
	cv::Mat E = cv::Mat::zeros(2 * N, 2 * N, CV_64F);

	if (N < 200)
	{
		for (int i = 0; i < 2 * N; i++)
		{
			for (int j = 0; j < 2 * N; j++)
			{
				if (i >= N / 2 && j >= N / 2 && i < 1.5 * N && j < 1.5 * N)
				{
					I.at<double>(i, j) = Matrix.at<double>(i - N / 2, j - N / 2);
				}
				else
				{
					I.at<double>(i, j) = 0;
				}
			}

		}
	}
	else
	{
		I = Matrix;
	}

	/*
	cv::Mat display;
	if (I.empty())

	{
		std::cout << "image not loaded";
	}
	else
	{
		I.convertTo(display, CV_8UC1, 255.0 / 1.0, 0);
		applyColorMap(display, display, cv::COLORMAP_JET);
		cv::imshow("imagesc", display);
		cv::waitKey(0);
	}
	*/


	cv::Mat padded;                            //expand input image to optimal size
	int m = cv::getOptimalDFTSize(1 * I.rows);
	int n = cv::getOptimalDFTSize(1 * I.cols); // on the border add zero values
	cv::copyMakeBorder(I, padded, 0, m - I.rows, 0, n - I.cols, cv::BORDER_CONSTANT, cv::Scalar::all(0));
	cv::Mat planes[] = { cv::Mat_<float>(padded), cv::Mat::zeros(padded.size(), CV_32F) };
	cv::Mat complexI;
	merge(planes, 2, complexI);         // Add to the expanded another plane with zeros
	dft(complexI, complexI);            // this way the result may fit in the source matrix
	// compute the magnitude and switch to logarithmic scale
	// => log(1 + sqrt(Re(DFT(I))^2 + Im(DFT(I))^2))
	split(complexI, planes);                   // planes[0] = Re(DFT(I), planes[1] = Im(DFT(I))
	magnitude(planes[0], planes[1], planes[0]);// planes[0] = magnitude
	cv::Mat magI = planes[0];
	//magI += cv::Scalar::all(1);                    // switch to logarithmic scale
	//log(magI, magI);
	// crop the spectrum, if it has an odd number of rows or columns
	//magI = magI(cv::Rect(0, 0, magI.cols & -3, magI.rows & -3));
	// rearrange the quadrants of Fourier image  so that the origin is at the image center
	int cx = magI.cols / 2;
	int cy = magI.rows / 2;
	cv::Mat q0(magI, cv::Rect(0, 0, cx, cy));   // Top-Left - Create a ROI per quadrant
	cv::Mat q1(magI, cv::Rect(cx, 0, cx, cy));  // Top-Right
	cv::Mat q2(magI, cv::Rect(0, cy, cx, cy));  // Bottom-Left
	cv::Mat q3(magI, cv::Rect(cx, cy, cx, cy)); // Bottom-Right
	cv::Mat tmp;                           // swap quadrants (Top-Left with Bottom-Right)
	q0.copyTo(tmp);
	q3.copyTo(q0);
	tmp.copyTo(q3);
	q1.copyTo(tmp);                    // swap quadrant (Top-Right with Bottom-Left)
	q2.copyTo(q1);
	tmp.copyTo(q2);

	normalize(magI, magI, 0, 1, cv::NORM_MINMAX);




	//std::cout << magI;
	////
	return magI;
}

// get PSF
cv::Mat OPD::getPSF()
{
	return mHuygenPSF;
}

//cv::Mat OPD::calcPSF()
//{
//
//	calculateCardinalPoints();
//	std::complex<double> twopi = 2 * 3.1415926535897932384626433832;
//
//	//static const int  N = floor(upscaledMatrixSize * (sqrt((32 / upscaledMatrixSize)))); /* check sampling*/
//	double aperture_diameter = mOptSys.getInforAS().getSemiHeightAS() * 2.0;  //meters; 1 inch
//	double efl = mCardinalPoints.getEFL();   //effective focal length in meters
//
//
//
//	double a = mGlobalOPD.cols;
//	double b = sqrt(32 / a);
//	double  SampledMatrixSizeforPSF = floor(mGlobalOPD.cols * b); /* effective grid size for PSF calculation*/
//	int N = SampledMatrixSizeforPSF;
//
//	if (N % 2 == 1)
//	{
//		N = N + 1;
//	}
//	typedef std::complex<double> Complex;
//
//	const Complex J(0, 1);
//
//
//	cv::Mat PupilFunction = cv::Mat::zeros(2 * N, 2 * N, CV_64F);
//
//
//	// sampling
//	double sampling = 0.5e-6;
//	cv::Mat X_pupil = cv::Mat::zeros(N, N, CV_64F);
//	for (int i = 0; i < mSampledOPDMatrixforPSF.cols; i++)
//	{
//		for (int j = 0; j < mSampledOPDMatrixforPSF.cols; j++)
//		{
//			X_pupil.at<double>(i, j) = (i - floor((mSampledOPDMatrixforPSF.cols / 2)))*0.0005;
//		}
//	}
//
//
//	cv::Mat Y_pupil = cv::Mat::zeros(N, N, CV_64F);
//	for (int i = 0; i < mSampledOPDMatrixforPSF.cols; i++)
//	{
//		for (int j = 0; j < mSampledOPDMatrixforPSF.cols; j++)
//		{
//			Y_pupil.at<double>(i, j) = (j - floor((mSampledOPDMatrixforPSF.cols / 2)))*0.0005;
//		}
//	}
//
//
//	cv::Mat R_pupil = cv::Mat::zeros(N, N, CV_64F);
//	for (int i = 0; i < mSampledOPDMatrixforPSF.cols; i++)
//	{
//		for (int j = 0; j < mSampledOPDMatrixforPSF.cols; j++)
//		{
//			R_pupil.at<double>(i, j) = sqrt(X_pupil.at<double>(i, j)*X_pupil.at<double>(i, j) + Y_pupil.at<double>(i, j)*Y_pupil.at<double>(i, j));
//		}
//	}
//
//	cv::Mat R_norm = cv::Mat::zeros(N, N, CV_64F);
//	for (int i = 0; i < mSampledOPDMatrixforPSF.cols; i++)
//	{
//		for (int j = 0; j < mSampledOPDMatrixforPSF.cols; j++)
//		{
//			R_norm.at<double>(i, j) = (R_pupil.at<double>(i, j)) * 1000 / aperture_diameter;
//		}
//	}
//
//
//
//	////////////////////////////////////////////////////
//
//
//
//
//
//	for (int i = 0; i < mSampledOPDMatrixforPSF.cols; i++)
//	{
//		for (int j = 0; j < mSampledOPDMatrixforPSF.cols; j++)
//		{
//			if (R_norm.at<double>(i, j) > 4)
//			{
//				PupilFunction.at<Complex>(i, j) = (0, 0);
//
//			}
//			else
//			{
//				PupilFunction.at<Complex>(i, j) = (cos(twopi * mSampledOPDMatrixforPSF.at<double>(i, j)) + J * sin(twopi * mSampledOPDMatrixforPSF.at<double>(i, j)));
//
//			}
//		}
//	}
//
//	cv::Mat Amplitude = cv::Mat::zeros(floor(PupilFunction.cols / 2), floor(PupilFunction.cols / 2), CV_64F);
//
//	for (int i = 0; i < floor(PupilFunction.cols / 2); i++)
//	{
//		for (int j = 0; j < floor(PupilFunction.cols / 2); j++)
//		{
//			Amplitude.at<double>(i, j) = abs(PupilFunction.at<Complex>(i, j));
//		}
//
//	}
//
//
//
//	////////////////////////////////////////check below
//	N = Amplitude.cols;
//	cv::Mat mPSF_complex = cv::Mat::zeros(N, N, CV_64F);
//	cv::Mat mPSF = cv::Mat::zeros(2 * N, 2 * N, CV_64F);
//	mPSF_complex = calcFFT(PupilFunction);
//
//	for (int i = N; i < 3 * N; i++)
//	{
//		for (int j = N; j < 3 * N; j++)
//		{
//			//std::cout << abs(mPSF_complex.at<float>(2 * N, 2 * N)) << std::endl;
//			//std::cout << mPSF_complex.at<float>(i , j) << std::endl;
//			mPSF.at<double>(i - N, j - N) = abs(mPSF_complex.at<float>(i, j))*abs(mPSF_complex.at<float>(i, j)) / (abs(mPSF_complex.at<float>(2 * N, 2 * N)*abs(mPSF_complex.at<float>(2 * N, 2 * N))));
//		}
//
//	}
//	/*
//	N = mPSF.cols;
//	cv::Mat mPSF_1 = cv::Mat::zeros( N-28, N, CV_64F);
//
//	for (int i = 14; i <  N-14; i++)
//	{
//		for (int j = 0; j <  N; j++)
//		{
//			mPSF_1.at<double>(i - 14, j) = mPSF.at<double>(i, j);
//		}
//	}*/
//
//
//
//
//
//	//check for total energy equal to one for psf .
//	std::ofstream outData;
//	outData.open("D:\PSFrishav.csv", std::ios::app);
//	outData << mPSF << std::endl;
//
//
//
//	//see results with higher pixels
//	N = 2 * mPSF.cols;
//	//std::cout << mPSF.at<float>(0, 0);//for checking fft function
//	double ratio = (double)(mPSF.cols - 1) / (double)(N - 1);
//	cv::Mat mPSF_high = cv::Mat::zeros(N, N, CV_64F);
//
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < N; j++) {
//			int fx = floor((double)(i)*ratio);
//			int fy = floor((double)(j)*ratio);
//			int cx = ceil((double)(i)*ratio);
//			int cy = ceil((double)(j)*ratio);
//			double actualX = double(i)*ratio;
//			double actualY = double(j)*ratio;
//
//
//			mPSF_high.at<double>(i, j) = bilinear_interpolator(mPSF.at<double>(fx, fy), mPSF.at<double>(fx, cy),
//				mPSF.at<double>(cx, fy), mPSF.at<double>(cx, cy),
//				fx, cx, fy, cy,
//				actualX, actualY);
//		}
//	}
//
//
//
//	//OPD
//
//
//	cv::Mat display;
//	/*
//		if (mSampledOPDMatrixforPSF.empty())
//		{
//			std::cout << "image not loaded";
//		}
//		else
//		{
//			mSampledOPDMatrixforPSF.convertTo(display, CV_8UC1, 255.0 / 1.0, 0);
//			applyColorMap(display, display, cv::COLORMAP_JET);
//			cv::imshow("imagesc", display);
//			cv::waitKey(0);
//		}
//	*/
//
//	//PSF
//
//	//if (mPSF_high.empty())
//	//
//	//{
//	//	std::cout << "image not loaded";
//	//}
//	//else
//	//{
//	//	mPSF_high.convertTo(display, CV_8UC1, 255.0 / 1.0, 0);
//	//	applyColorMap(display, display, cv::COLORMAP_JET);
//	//	cv::imshow("imagesc", display);
//	//	cv::waitKey(0);
//	//}
//
//
//
//	return mPSF_high;
//}


////calculate the cut off frequency
//double OPD::calcCutoffFreq()
//{
//	calculateCardinalPoints();
//
//	double lambda = 0.550e-6;   //
//	double efl = mCardinalPoints.getEFL();                        //effective focal length
//	double	D = mCardinalPoints.getENPD();       //extrance pupil dia or stop dia
//	double mag = mCardinalPoints.getMagnification();             //image magnification                  
//	double	EXPD = mCardinalPoints.getEXPD();                   //exit pupil dia
//	double	P = EXPD / D;                         //pupil magnification
//	double	F = efl / D;                             //f number
//	double	Fw = (1 + mag / P)*F;                   //working f nummber
//	if (Fw < 0)
//	{
//		Fw = -Fw;
//	}
//	double	mCutoffFreq = 0.001 / (Fw * lambda);  //cut of frequency in lines / mm
//	std::cout << "Cut of Frequency of the system = " << mCutoffFreq << std::endl;
//
//	return mCutoffFreq;
//}

/*
int OPD::PlotGraph(cv::Mat & data)
{

	//converting the Mat to CV_64F
	data.convertTo(data, CV_64F);
	cv::Mat plot_result;

	cv::Ptr<cv::plot::Plot2d> plot = cv::plot::Plot2d::create(data);
	plot->setPlotBackgroundColor(cv::Scalar(50, 50, 50));
	plot->setPlotLineColor(cv::Scalar(50, 50, 255));
	plot->render(plot_result);

	imshow("Graph", plot_result);
	cv::waitKey();

	return 0;
}*/

//calculate MTF
//cv::Mat OPD::calcMTF()
//{
//	/*int N = upscaledMatrixSize;
//	//take 2 times fft to get mtf,cant do fft of psf since psf sampling is low
//
//
//	//sampling
//
//	double aperture_diameter = mCardinalPoints.getDiameterAperture();
//	double sampling = 0.00090;
//	cv::Mat X_pupil = cv::Mat::zeros(N, N, CV_64F);
//	for (int i = 0; i < upscaledMatrixSize; i++)
//	{
//		for (int j = 0; j < upscaledMatrixSize; j++)
//		{
//			X_pupil.at<double>(i, j) = (i - floor((upscaledMatrixSize / 2)))*0.001;
//		}
//	}
//
//	cv::Mat Y_pupil = cv::Mat::zeros(N, N, CV_64F);
//	for (int i = 0; i < upscaledMatrixSize; i++)
//	{
//		for (int j = 0; j < upscaledMatrixSize; j++)
//		{
//			Y_pupil.at<double>(i, j) = (j - floor((upscaledMatrixSize / 2)))*0.001;
//		}
//	}
//
//
//	cv::Mat R_pupil = cv::Mat::zeros(N, N, CV_64F);
//	for (int i = 0; i < upscaledMatrixSize; i++)
//	{
//		for (int j = 0; j < upscaledMatrixSize; j++)
//		{
//			R_pupil.at<double>(i, j) = sqrt(X_pupil.at<double>(i, j)*X_pupil.at<double>(i, j) + Y_pupil.at<double>(i, j)*Y_pupil.at<double>(i, j));
//		}
//	}
//
//	cv::Mat R_norm = cv::Mat::zeros(N, N, CV_64F);
//	for (int i = 0; i < upscaledMatrixSize; i++)
//	{
//		for (int j = 0; j < upscaledMatrixSize; j++)
//		{
//			R_norm.at<double>(i, j) = (R_pupil.at<double>(i, j) *100) / aperture_diameter;
//		}
//	}
//
//
//	//////////////////////////////////////////////////////////
//	typedef std::complex<double> Complex;
//	std::complex<double> twopi = 2 * 3.1415926535897932384626433832;
//	const Complex J(0, 1);
//	cv::Mat PupilFunction = cv::Mat::zeros(2*N, 2*N, CV_64F);
//
//
//	for (int i = 0; i < upscaledMatrixSize; i++)
//	{
//		for (int j = 0; j < upscaledMatrixSize; j++)
//		{
//			if (R_norm.at<double>(i, j) > 1)
//			{
//				PupilFunction.at<Complex>(i, j) = (0, 0);
//
//			}
//			else
//			{
//				PupilFunction.at<Complex>(i, j) = cos(twopi * mUpscaledGlobalOPD.at<double>(i, j)) + J * sin(twopi * mUpscaledGlobalOPD.at<double>(i, j));
//
//			}
//		}
//	}
//
//	*/
//
//
//	mMTF = calcFFT(mPSF);
//
//	cv::Mat display;
//
//	//if (mMTF.empty())
//	//{
//	//	std::cout << "image not loaded";
//	//}
//	//else
//	//{
//	//    mMTF.convertTo(display, CV_8UC1, 255.0 / 1.0, 0);
//	//	applyColorMap(display, display, cv::COLORMAP_JET);
//	//	cv::imshow("imagesc", display);
//	//	cv::waitKey(0);
//	//
//	//
//	//}
//
//	//plot MTF //fix data type
//	double s = mMTF.cols / 2;
//	std::vector<float> MTFplot(s);
//	double MTFmax = 0;
//
//	for (int i = s; i < mMTF.cols; i++)
//	{
//
//		if (abs(mMTF.at<float>(i, s)) > MTFmax)
//		{
//			MTFmax = abs(mMTF.at<float>(i + 1, s));
//		}
//
//	}
//
//	for (int i = s; i < mMTF.cols; i++)
//	{
//		MTFplot.at(i - s) = abs(mMTF.at<float>(i, s)) / MTFmax;
//		std::cout << MTFplot.at(i - s) << std::endl;
//	}
//
//
//
//	//std::cout << MTFplot << std::endl;
///*std::ofstream outData;
//	outData.open("D:\MTFplot.csv", std::ios::app);
//	outData << MTFplot << std::endl;*/
//
//	return mMTF;
//}
//////////////////////////////




///////////////////////
/*
//mtf plot
cv::plot::Plot2d;
cv::Mat xData, yData, display;
cv::Ptr<plot::Plot2d> plot;
xData.create(1, 100, CV_64F);//1 Row, 100 columns, Double
yData.create(1, 100, CV_64F);

for (int i = 0; i < 100; ++i)
{
	xData.at<double>(i) = i / 10.0;
	yData.at<double>(i) = i;
}
plot = plot::createPlot2d(xData, yData);
plot->setPlotSize(100, 1000);
plot->setMaxX(10);
plot->setMinX(0);
plot->setMaxY(100);
plot->setMinY(-1);
plot->render(display);
imshow("Plot", display);
cv::waitKey();
*/
//double s = PupilFunction.cols / 2;
//std::vector<double> MTFplot(s);


/*double MTFmax = 0;

for (int i = s; i < PupilFunction.cols; i++)
{

	if (abs(mMTF.at<double>(i , s)) > MTFmax)
	{
		MTFmax = abs(mMTF.at<double>(i+1, s));
	}

}

for (int i = s; i < PupilFunction.cols; i++)
{
	MTFplot.at(i - s) = abs(mMTF.at<double>(i, s))/ MTFmax;
}*/


//plot function


////Calculate huygen's integral
//cv::Mat OPD::calcHuygenIntegral(cv::Mat PupilFunction, double waveVector, double prop_distance, double sampling_in)
//{
//	double twopi = 2 * 3.1415926535897932384626433832;
//	typedef std::complex<double> Complex;
//	const Complex J(0, 1);
//	double sampling_out = 0.0005;
//	double sidelength_out = 0.05;
//	double N = floor(PupilFunction.cols / 2);
//
//
//
//
//	// sampling in
//	cv::Mat X_in = cv::Mat::zeros(N, N, CV_64F);
//	for (int i = 0; i < N; i++)
//	{
//		for (int j = 0; j < N; j++)
//		{
//			X_in.at<double>(i, j) = (i - floor((N / 2)))*sampling_in;
//		}
//	}
//
//
//	cv::Mat Y_in = cv::Mat::zeros(N, N, CV_64F);
//	for (int i = 0; i < N; i++)
//	{
//		for (int j = 0; j < N; j++)
//		{
//			Y_in.at<double>(i, j) = (j - floor((N / 2)))*sampling_in;
//		}
//	}
//
//	//sampling out
//	N = floor(sidelength_out / sampling_out);
//
//	cv::Mat X_out = cv::Mat::zeros(N, N, CV_64F);
//	for (int i = 0; i < N; i++)
//	{
//		for (int j = 0; j < N; j++)
//		{
//			X_out.at<double>(i, j) = (i - floor((N / 2)))*sampling_out;
//		}
//	}
//
//
//	cv::Mat Y_out = cv::Mat::zeros(N, N, CV_64F);
//	for (int i = 0; i < N; i++)
//	{
//		for (int j = 0; j < N; j++)
//		{
//			Y_out.at<double>(i, j) = (j - floor((N / 2)))*sampling_out;
//		}
//	}
//
//	////////////////////////////////////////////////
//
//	cv::Mat mHuygenIntegral = cv::Mat::zeros(2 * N, 2 * N, CV_64F);
//	cv::Mat X = cv::Mat::zeros(N, N, CV_64F);
//	cv::Mat Y = cv::Mat::zeros(N, N, CV_64F);
//	cv::Mat distance_to_target = cv::Mat::zeros(N, N, CV_64F);
//	cv::Mat inverse_distance_to_target = cv::Mat::zeros(N, N, CV_64F);
//	cv::Mat E = cv::Mat::zeros(2 * N, 2 * N, CV_64F);
//	Complex E_sum = (0, 0);
//	cv::Mat Amplitude = cv::Mat::zeros(floor(PupilFunction.cols / 2), floor(PupilFunction.cols / 2), CV_64F);
//
//	for (int i = 0; i < floor(PupilFunction.cols / 2); i++)
//	{
//		for (int j = 0; j < floor(PupilFunction.cols / 2); j++)
//		{
//			Amplitude.at<double>(i, j) = abs(PupilFunction.at<Complex>(i, j));
//		}
//
//	}
//	////////////////////////////////////////////////////
//
//		//see results at higher resolution
//	N = 5 * Amplitude.cols;
//	cv::Mat Amplitude_high = cv::Mat::zeros(N, N, CV_64F);
//	double ratio = (double)(Amplitude.cols - 1) / (double)(N - 1);
//	cv::Mat mHuygenPSF_high = cv::Mat::zeros(N, N, CV_64F);
//
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < N; j++) {
//			int fx = floor((double)(i)*ratio);
//			int fy = floor((double)(j)*ratio);
//			int cx = ceil((double)(i)*ratio);
//			int cy = ceil((double)(j)*ratio);
//			double actualX = double(i)*ratio;
//			double actualY = double(j)*ratio;
//
//
//			Amplitude_high.at<double>(i, j) = bilinear_interpolator(Amplitude.at<double>(fx, fy), Amplitude.at<double>(fx, cy),
//				Amplitude.at<double>(cx, fy), Amplitude.at<double>(cx, cy),
//				fx, cx, fy, cy,
//				actualX, actualY);
//		}
//	}
//
//	cv::Mat display;
//	if (Amplitude_high.empty())
//
//	{
//		std::cout << "image not loaded";
//	}
//	else
//	{
//		//Amplitude_high.convertTo(display, CV_8UC1, 255.0 / 1.0, 0);
//		//applyColorMap(display, display, cv::COLORMAP_JET);
//		//cv::imshow("Pupil function", display);
//		//cv::waitKey(0);
//	}
//
//	/////////////////////////////////
//	N = floor(sidelength_out / sampling_out);
//
//	for (int i = 0; i < N; i++)
//	{
//		for (int j = 0; j < N; j++)
//		{
//			Complex E_sum = (0, 0);
//
//
//			for (int k = 0; k < floor(PupilFunction.cols / 2); k++)
//			{
//				for (int l = 0; l < floor(PupilFunction.cols / 2); l++)
//				{
//					X.at<double>(k, l) = X_in.at<double>(k, l) - X_out.at<double>(i, j);
//					Y.at<double>(k, l) = Y_in.at<double>(k, l) - Y_out.at<double>(i, j);
//					distance_to_target.at<double>(k, l) = sqrt(X.at<double>(k, l)*X.at<double>(k, l) + Y.at<double>(k, l)*Y.at<double>(k, l) + prop_distance * prop_distance);
//					inverse_distance_to_target.at<double>(k, l) = 1 / sqrt(X.at<double>(k, l)*X.at<double>(k, l) + Y.at<double>(k, l)*Y.at<double>(k, l) + prop_distance * prop_distance);
//					E.at<Complex>(k, l) = (Amplitude.at<double>(k, l))*(inverse_distance_to_target.at<double>(k, l))*(cos(-1 * waveVector*distance_to_target.at<double>(k, l) + (twopi * mGlobalOPD.at<double>(k, l))) + J * sin(-1 * waveVector*distance_to_target.at<double>(k, l) + (twopi * mGlobalOPD.at<double>(k, l))));
//					E_sum = (E_sum + E.at<Complex>(k, l));
//
//				}
//			}
//			mHuygenIntegral.at<Complex>(i, j) = E_sum;
//		}
//
//		std::cout << "Percentage completion of integration = " << i + 1 << std::endl;
//
//
//	}
//
//	return mHuygenIntegral;
//}

