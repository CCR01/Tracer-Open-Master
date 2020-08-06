
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


CardinalPoints OPD::calculateCardinalPoints()
{
	mCardinalPoints = CardinalPoints(mOptSys, objectPoint_inf_obj::obj);

	return mCardinalPoints;
}


// get PSF
cv::Mat OPD::getPSF()
{
	return mHuygenPSF;
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



cv::Mat OPD::calcPSF()
{

	calculateCardinalPoints();
	std::complex<double> twopi = 2 * 3.1415926535897932384626433832;

	//static const int  N = floor(upscaledMatrixSize * (sqrt((32 / upscaledMatrixSize)))); /* check sampling*/
	double aperture_diameter = mOptSys.getInforAS().getSemiHeightAS() * 2.0;  //meters; 1 inch
	double efl = mCardinalPoints.getEFL();   //effective focal length in meters



	double a = mGlobalOPD.cols;
	double b = sqrt(32 / a);
	double  SampledMatrixSizeforPSF = floor(mGlobalOPD.cols * b); /* effective grid size for PSF calculation*/
	int N = SampledMatrixSizeforPSF;

	if (N % 2 == 1)
	{
		N = N + 1;
	}
	typedef std::complex<double> Complex;

	const Complex J(0, 1);


	cv::Mat PupilFunction = cv::Mat::zeros(2 * N, 2 * N, CV_64F);


	// sampling
	double sampling = 0.5e-6;
	cv::Mat X_pupil = cv::Mat::zeros(N, N, CV_64F);
	for (int i = 0; i < mSampledOPDMatrixforPSF.cols; i++)
	{
		for (int j = 0; j < mSampledOPDMatrixforPSF.cols; j++)
		{
			X_pupil.at<double>(i, j) = (i - floor((mSampledOPDMatrixforPSF.cols / 2)))*0.0005;
		}
	}


	cv::Mat Y_pupil = cv::Mat::zeros(N, N, CV_64F);
	for (int i = 0; i < mSampledOPDMatrixforPSF.cols; i++)
	{
		for (int j = 0; j < mSampledOPDMatrixforPSF.cols; j++)
		{
			Y_pupil.at<double>(i, j) = (j - floor((mSampledOPDMatrixforPSF.cols / 2)))*0.0005;
		}
	}


	cv::Mat R_pupil = cv::Mat::zeros(N, N, CV_64F);
	for (int i = 0; i < mSampledOPDMatrixforPSF.cols; i++)
	{
		for (int j = 0; j < mSampledOPDMatrixforPSF.cols; j++)
		{
			R_pupil.at<double>(i, j) = sqrt(X_pupil.at<double>(i, j)*X_pupil.at<double>(i, j) + Y_pupil.at<double>(i, j)*Y_pupil.at<double>(i, j));
		}
	}

	cv::Mat R_norm = cv::Mat::zeros(N, N, CV_64F);
	for (int i = 0; i < mSampledOPDMatrixforPSF.cols; i++)
	{
		for (int j = 0; j < mSampledOPDMatrixforPSF.cols; j++)
		{
			R_norm.at<double>(i, j) = (R_pupil.at<double>(i, j)) * 1000 / aperture_diameter;
		}
	}



	////////////////////////////////////////////////////





	for (int i = 0; i < mSampledOPDMatrixforPSF.cols; i++)
	{
		for (int j = 0; j < mSampledOPDMatrixforPSF.cols; j++)
		{
			if (R_norm.at<double>(i, j) > 4)
			{
				PupilFunction.at<Complex>(i, j) = (0, 0);

			}
			else
			{
				PupilFunction.at<Complex>(i, j) = (cos(twopi * mSampledOPDMatrixforPSF.at<double>(i, j)) + J * sin(twopi * mSampledOPDMatrixforPSF.at<double>(i, j)));

			}
		}
	}

	cv::Mat Amplitude = cv::Mat::zeros(floor(PupilFunction.cols / 2), floor(PupilFunction.cols / 2), CV_64F);

	for (int i = 0; i < floor(PupilFunction.cols / 2); i++)
	{
		for (int j = 0; j < floor(PupilFunction.cols / 2); j++)
		{
			Amplitude.at<double>(i, j) = abs(PupilFunction.at<Complex>(i, j));
		}

	}



	////////////////////////////////////////check below
	N = Amplitude.cols;
	cv::Mat mPSF_complex = cv::Mat::zeros(N, N, CV_64F);
	cv::Mat mPSF = cv::Mat::zeros(2 * N, 2 * N, CV_64F);
	mPSF_complex = calcFFT(PupilFunction);

	for (int i = N; i < 3 * N; i++)
	{
		for (int j = N; j < 3 * N; j++)
		{
			//std::cout << abs(mPSF_complex.at<float>(2 * N, 2 * N)) << std::endl;
			//std::cout << mPSF_complex.at<float>(i , j) << std::endl;
			mPSF.at<double>(i - N, j - N) = abs(mPSF_complex.at<float>(i, j))*abs(mPSF_complex.at<float>(i, j)) / (abs(mPSF_complex.at<float>(2 * N, 2 * N)*abs(mPSF_complex.at<float>(2 * N, 2 * N))));
		}

	}
	/*
	N = mPSF.cols;
	cv::Mat mPSF_1 = cv::Mat::zeros( N-28, N, CV_64F);

	for (int i = 14; i <  N-14; i++)
	{
		for (int j = 0; j <  N; j++)
		{
			mPSF_1.at<double>(i - 14, j) = mPSF.at<double>(i, j);
		}
	}*/





	//check for total energy equal to one for psf .
	std::ofstream outData;
	outData.open("D:\PSFrishav.csv", std::ios::app);
	outData << mPSF << std::endl;



	//see results with higher pixels
	N = 2 * mPSF.cols;
	//std::cout << mPSF.at<float>(0, 0);//for checking fft function
	double ratio = (double)(mPSF.cols - 1) / (double)(N - 1);
	cv::Mat mPSF_high = cv::Mat::zeros(N, N, CV_64F);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int fx = floor((double)(i)*ratio);
			int fy = floor((double)(j)*ratio);
			int cx = ceil((double)(i)*ratio);
			int cy = ceil((double)(j)*ratio);
			double actualX = double(i)*ratio;
			double actualY = double(j)*ratio;


			mPSF_high.at<double>(i, j) = bilinear_interpolator(mPSF.at<double>(fx, fy), mPSF.at<double>(fx, cy),
				mPSF.at<double>(cx, fy), mPSF.at<double>(cx, cy),
				fx, cx, fy, cy,
				actualX, actualY);
		}
	}



	//OPD


	cv::Mat display;
	/*
		if (mSampledOPDMatrixforPSF.empty())
		{
			std::cout << "image not loaded";
		}
		else
		{
			mSampledOPDMatrixforPSF.convertTo(display, CV_8UC1, 255.0 / 1.0, 0);
			applyColorMap(display, display, cv::COLORMAP_JET);
			cv::imshow("imagesc", display);
			cv::waitKey(0);
		}
	*/

	//PSF

	//if (mPSF_high.empty())
	//
	//{
	//	std::cout << "image not loaded";
	//}
	//else
	//{
	//	mPSF_high.convertTo(display, CV_8UC1, 255.0 / 1.0, 0);
	//	applyColorMap(display, display, cv::COLORMAP_JET);
	//	cv::imshow("imagesc", display);
	//	cv::waitKey(0);
	//}



	return mPSF_high;
}


//calculate the cut off frequency
double OPD::calcCutoffFreq()
{
	calculateCardinalPoints();

	double lambda = 0.550e-6;   //
	double efl = mCardinalPoints.getEFL();                        //effective focal length
	double	D = mCardinalPoints.getENPD();       //extrance pupil dia or stop dia
	double mag = mCardinalPoints.getMagnification();             //image magnification                  
	double	EXPD = mCardinalPoints.getEXPD();                   //exit pupil dia
	double	P = EXPD / D;                         //pupil magnification
	double	F = efl / D;                             //f number
	double	Fw = (1 + mag / P)*F;                   //working f nummber
	if (Fw < 0)
	{
		Fw = -Fw;
	}
	double	mCutoffFreq = 0.001 / (Fw * lambda);  //cut of frequency in lines / mm
	std::cout << "Cut of Frequency of the system = " << mCutoffFreq << std::endl;

	return mCutoffFreq;
}

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
cv::Mat OPD::calcMTF()
{
	/*int N = upscaledMatrixSize;
	//take 2 times fft to get mtf,cant do fft of psf since psf sampling is low


	//sampling

	double aperture_diameter = mCardinalPoints.getDiameterAperture();
	double sampling = 0.00090;
	cv::Mat X_pupil = cv::Mat::zeros(N, N, CV_64F);
	for (int i = 0; i < upscaledMatrixSize; i++)
	{
		for (int j = 0; j < upscaledMatrixSize; j++)
		{
			X_pupil.at<double>(i, j) = (i - floor((upscaledMatrixSize / 2)))*0.001;
		}
	}

	cv::Mat Y_pupil = cv::Mat::zeros(N, N, CV_64F);
	for (int i = 0; i < upscaledMatrixSize; i++)
	{
		for (int j = 0; j < upscaledMatrixSize; j++)
		{
			Y_pupil.at<double>(i, j) = (j - floor((upscaledMatrixSize / 2)))*0.001;
		}
	}


	cv::Mat R_pupil = cv::Mat::zeros(N, N, CV_64F);
	for (int i = 0; i < upscaledMatrixSize; i++)
	{
		for (int j = 0; j < upscaledMatrixSize; j++)
		{
			R_pupil.at<double>(i, j) = sqrt(X_pupil.at<double>(i, j)*X_pupil.at<double>(i, j) + Y_pupil.at<double>(i, j)*Y_pupil.at<double>(i, j));
		}
	}

	cv::Mat R_norm = cv::Mat::zeros(N, N, CV_64F);
	for (int i = 0; i < upscaledMatrixSize; i++)
	{
		for (int j = 0; j < upscaledMatrixSize; j++)
		{
			R_norm.at<double>(i, j) = (R_pupil.at<double>(i, j) *100) / aperture_diameter;
		}
	}


	//////////////////////////////////////////////////////////
	typedef std::complex<double> Complex;
	std::complex<double> twopi = 2 * 3.1415926535897932384626433832;
	const Complex J(0, 1);
	cv::Mat PupilFunction = cv::Mat::zeros(2*N, 2*N, CV_64F);


	for (int i = 0; i < upscaledMatrixSize; i++)
	{
		for (int j = 0; j < upscaledMatrixSize; j++)
		{
			if (R_norm.at<double>(i, j) > 1)
			{
				PupilFunction.at<Complex>(i, j) = (0, 0);

			}
			else
			{
				PupilFunction.at<Complex>(i, j) = cos(twopi * mUpscaledGlobalOPD.at<double>(i, j)) + J * sin(twopi * mUpscaledGlobalOPD.at<double>(i, j));

			}
		}
	}

	*/


	mMTF = calcFFT(mPSF);

	cv::Mat display;

	//if (mMTF.empty())
	//{
	//	std::cout << "image not loaded";
	//}
	//else
	//{
	//    mMTF.convertTo(display, CV_8UC1, 255.0 / 1.0, 0);
	//	applyColorMap(display, display, cv::COLORMAP_JET);
	//	cv::imshow("imagesc", display);
	//	cv::waitKey(0);
	//
	//
	//}

	//plot MTF //fix data type
	double s = mMTF.cols / 2;
	std::vector<float> MTFplot(s);
	double MTFmax = 0;

	for (int i = s; i < mMTF.cols; i++)
	{

		if (abs(mMTF.at<float>(i, s)) > MTFmax)
		{
			MTFmax = abs(mMTF.at<float>(i + 1, s));
		}

	}

	for (int i = s; i < mMTF.cols; i++)
	{
		MTFplot.at(i - s) = abs(mMTF.at<float>(i, s)) / MTFmax;
		std::cout << MTFplot.at(i - s) << std::endl;
	}



	//std::cout << MTFplot << std::endl;
/*std::ofstream outData;
	outData.open("D:\MTFplot.csv", std::ios::app);
	outData << MTFplot << std::endl;*/

	return mMTF;
}
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


//Calculate huygen's integral
cv::Mat OPD::calcHuygenIntegral(cv::Mat PupilFunction, double waveVector, double prop_distance, double sampling_in)
{
	double twopi = 2 * 3.1415926535897932384626433832;
	typedef std::complex<double> Complex;
	const Complex J(0, 1);
	double sampling_out = 0.0005;
	double sidelength_out = 0.05;
	double N = floor(PupilFunction.cols / 2);




	// sampling in
	cv::Mat X_in = cv::Mat::zeros(N, N, CV_64F);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			X_in.at<double>(i, j) = (i - floor((N / 2)))*sampling_in;
		}
	}


	cv::Mat Y_in = cv::Mat::zeros(N, N, CV_64F);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			Y_in.at<double>(i, j) = (j - floor((N / 2)))*sampling_in;
		}
	}

	//sampling out
	N = floor(sidelength_out / sampling_out);

	cv::Mat X_out = cv::Mat::zeros(N, N, CV_64F);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			X_out.at<double>(i, j) = (i - floor((N / 2)))*sampling_out;
		}
	}


	cv::Mat Y_out = cv::Mat::zeros(N, N, CV_64F);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			Y_out.at<double>(i, j) = (j - floor((N / 2)))*sampling_out;
		}
	}

	////////////////////////////////////////////////

	cv::Mat mHuygenIntegral = cv::Mat::zeros(2 * N, 2 * N, CV_64F);
	cv::Mat X = cv::Mat::zeros(N, N, CV_64F);
	cv::Mat Y = cv::Mat::zeros(N, N, CV_64F);
	cv::Mat distance_to_target = cv::Mat::zeros(N, N, CV_64F);
	cv::Mat inverse_distance_to_target = cv::Mat::zeros(N, N, CV_64F);
	cv::Mat E = cv::Mat::zeros(2 * N, 2 * N, CV_64F);
	Complex E_sum = (0, 0);
	cv::Mat Amplitude = cv::Mat::zeros(floor(PupilFunction.cols / 2), floor(PupilFunction.cols / 2), CV_64F);

	for (int i = 0; i < floor(PupilFunction.cols / 2); i++)
	{
		for (int j = 0; j < floor(PupilFunction.cols / 2); j++)
		{
			Amplitude.at<double>(i, j) = abs(PupilFunction.at<Complex>(i, j));
		}

	}
	////////////////////////////////////////////////////

		//see results at higher resolution
	N = 5 * Amplitude.cols;
	cv::Mat Amplitude_high = cv::Mat::zeros(N, N, CV_64F);
	double ratio = (double)(Amplitude.cols - 1) / (double)(N - 1);
	cv::Mat mHuygenPSF_high = cv::Mat::zeros(N, N, CV_64F);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int fx = floor((double)(i)*ratio);
			int fy = floor((double)(j)*ratio);
			int cx = ceil((double)(i)*ratio);
			int cy = ceil((double)(j)*ratio);
			double actualX = double(i)*ratio;
			double actualY = double(j)*ratio;


			Amplitude_high.at<double>(i, j) = bilinear_interpolator(Amplitude.at<double>(fx, fy), Amplitude.at<double>(fx, cy),
				Amplitude.at<double>(cx, fy), Amplitude.at<double>(cx, cy),
				fx, cx, fy, cy,
				actualX, actualY);
		}
	}

	cv::Mat display;
	if (Amplitude_high.empty())

	{
		std::cout << "image not loaded";
	}
	else
	{
		//Amplitude_high.convertTo(display, CV_8UC1, 255.0 / 1.0, 0);
		//applyColorMap(display, display, cv::COLORMAP_JET);
		//cv::imshow("Pupil function", display);
		//cv::waitKey(0);
	}

	/////////////////////////////////
	N = floor(sidelength_out / sampling_out);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			Complex E_sum = (0, 0);


			for (int k = 0; k < floor(PupilFunction.cols / 2); k++)
			{
				for (int l = 0; l < floor(PupilFunction.cols / 2); l++)
				{
					X.at<double>(k, l) = X_in.at<double>(k, l) - X_out.at<double>(i, j);
					Y.at<double>(k, l) = Y_in.at<double>(k, l) - Y_out.at<double>(i, j);
					distance_to_target.at<double>(k, l) = sqrt(X.at<double>(k, l)*X.at<double>(k, l) + Y.at<double>(k, l)*Y.at<double>(k, l) + prop_distance * prop_distance);
					inverse_distance_to_target.at<double>(k, l) = 1 / sqrt(X.at<double>(k, l)*X.at<double>(k, l) + Y.at<double>(k, l)*Y.at<double>(k, l) + prop_distance * prop_distance);
					E.at<Complex>(k, l) = (Amplitude.at<double>(k, l))*(inverse_distance_to_target.at<double>(k, l))*(cos(-1 * waveVector*distance_to_target.at<double>(k, l) + (twopi * mGlobalOPD.at<double>(k, l))) + J * sin(-1 * waveVector*distance_to_target.at<double>(k, l) + (twopi * mGlobalOPD.at<double>(k, l))));
					E_sum = (E_sum + E.at<Complex>(k, l));

				}
			}
			mHuygenIntegral.at<Complex>(i, j) = E_sum;
		}

		std::cout << "Percentage completion of integration = " << i + 1 << std::endl;


	}

	return mHuygenIntegral;
}








// export the global OPD as an .csv file
void OPD::exportGloblaOPD(std::string const& directionAndFilename)
{
	std::ofstream outData;


	outData.open("directionAndFilename", std::ios::app);
	outData << mGlobalOPD << std::endl;
}

////////////////////////////PSF////////////////////


// Function Declarations
static void b_r2br_r2dit_trig(const creal_T x[512], const double costab[257],
	const double sintab[257], creal_T y[512]);
static void bluestein(const creal_T x[36864], int xoffInit, const double costab
	[257], const double sintab[257], const double costabinv
	[257], const double sintabinv[257], const creal_T wwc[383],
	creal_T y[192]);
static void r2br_r2dit_trig(const creal_T x[383], const double costab[257],
	const double sintab[257], creal_T y[512]);
static void r2br_r2dit_trig_impl(const creal_T x[192], int xoffInit, const
	double costab[257], const double sintab[257], creal_T y[512]);

// Function Definitions

//
// Arguments    : const creal_T x[512]
//                const double costab[257]
//                const double sintab[257]
//                creal_T y[512]
// Return Type  : void
//
static void b_r2br_r2dit_trig(const creal_T x[512], const double costab[257],
	const double sintab[257], creal_T y[512])
{
	int ix;
	int ju;
	int iy;
	int i;
	boolean_T tst;
	double temp_re;
	double temp_im;
	int iheight;
	int istart;
	int j;
	double twid_re;
	double twid_im;
	int ihi;
	ix = 0;
	ju = 0;
	iy = 0;
	for (i = 0; i < 511; i++) {
		y[iy] = x[ix];
		iy = 512;
		tst = true;
		while (tst) {
			iy >>= 1;
			ju ^= iy;
			tst = ((ju & iy) == 0);
		}

		iy = ju;
		ix++;
	}

	y[iy] = x[ix];
	for (i = 0; i <= 511; i += 2) {
		temp_re = y[i + 1].re;
		temp_im = y[i + 1].im;
		y[i + 1].re = y[i].re - y[i + 1].re;
		y[i + 1].im = y[i].im - y[i + 1].im;
		y[i].re += temp_re;
		y[i].im += temp_im;
	}

	iy = 2;
	ix = 4;
	ju = 128;
	iheight = 509;
	while (ju > 0) {
		for (i = 0; i < iheight; i += ix) {
			temp_re = y[i + iy].re;
			temp_im = y[i + iy].im;
			y[i + iy].re = y[i].re - temp_re;
			y[i + iy].im = y[i].im - temp_im;
			y[i].re += temp_re;
			y[i].im += temp_im;
		}

		istart = 1;
		for (j = ju; j < 256; j += ju) {
			twid_re = costab[j];
			twid_im = sintab[j];
			i = istart;
			ihi = istart + iheight;
			while (i < ihi) {
				temp_re = twid_re * y[i + iy].re - twid_im * y[i + iy].im;
				temp_im = twid_re * y[i + iy].im + twid_im * y[i + iy].re;
				y[i + iy].re = y[i].re - temp_re;
				y[i + iy].im = y[i].im - temp_im;
				y[i].re += temp_re;
				y[i].im += temp_im;
				i += ix;
			}

			istart++;
		}

		ju /= 2;
		iy = ix;
		ix += ix;
		iheight -= iy;
	}

	for (iy = 0; iy < 512; iy++) {
		y[iy].re *= 0.001953125;
		y[iy].im *= 0.001953125;
	}
}

//
// Arguments    : const creal_T x[36864]
//                int xoffInit
//                const double costab[257]
//                const double sintab[257]
//                const double costabinv[257]
//                const double sintabinv[257]
//                const creal_T wwc[383]
//                creal_T y[192]
// Return Type  : void
//
static void bluestein(const creal_T x[36864], int xoffInit, const double costab
	[257], const double sintab[257], const double costabinv
	[257], const double sintabinv[257], const creal_T wwc[383],
	creal_T y[192])
{
	int xidx;
	int k;
	creal_T fv[512];
	creal_T dcv1[512];
	creal_T b_fv[512];
	xidx = xoffInit;
	for (k = 0; k < 192; k++) {
		y[k].re = wwc[k + 191].re * x[xidx].re + wwc[k + 191].im * x[xidx].im;
		y[k].im = wwc[k + 191].re * x[xidx].im - wwc[k + 191].im * x[xidx].re;
		xidx++;
	}

	r2br_r2dit_trig_impl(y, 0, costab, sintab, fv);
	r2br_r2dit_trig(wwc, costab, sintab, dcv1);
	for (xidx = 0; xidx < 512; xidx++) {
		b_fv[xidx].re = fv[xidx].re * dcv1[xidx].re - fv[xidx].im * dcv1[xidx].im;
		b_fv[xidx].im = fv[xidx].re * dcv1[xidx].im + fv[xidx].im * dcv1[xidx].re;
	}

	b_r2br_r2dit_trig(b_fv, costabinv, sintabinv, fv);
	xidx = 0;
	for (k = 0; k < 192; k++) {
		y[xidx].re = wwc[k + 191].re * fv[k + 191].re + wwc[k + 191].im * fv[k + 191]
			.im;
		y[xidx].im = wwc[k + 191].re * fv[k + 191].im - wwc[k + 191].im * fv[k + 191]
			.re;
		xidx++;
	}
}

//
// Arguments    : const creal_T x[383]
//                const double costab[257]
//                const double sintab[257]
//                creal_T y[512]
// Return Type  : void
//
static void r2br_r2dit_trig(const creal_T x[383], const double costab[257],
	const double sintab[257], creal_T y[512])
{
	int i;
	int ix;
	int ju;
	int iy;
	boolean_T tst;
	double temp_re;
	double temp_im;
	int iheight;
	int istart;
	int j;
	double twid_re;
	double twid_im;
	int ihi;
	for (i = 0; i < 512; i++) {
		y[i].re = 0.0;
		y[i].im = 0.0;
	}

	ix = 0;
	ju = 0;
	iy = 0;
	for (i = 0; i < 382; i++) {
		y[iy] = x[ix];
		iy = 512;
		tst = true;
		while (tst) {
			iy >>= 1;
			ju ^= iy;
			tst = ((ju & iy) == 0);
		}

		iy = ju;
		ix++;
	}

	y[iy] = x[ix];
	for (i = 0; i <= 511; i += 2) {
		temp_re = y[i + 1].re;
		temp_im = y[i + 1].im;
		y[i + 1].re = y[i].re - y[i + 1].re;
		y[i + 1].im = y[i].im - y[i + 1].im;
		y[i].re += temp_re;
		y[i].im += temp_im;
	}

	iy = 2;
	ix = 4;
	ju = 128;
	iheight = 509;
	while (ju > 0) {
		for (i = 0; i < iheight; i += ix) {
			temp_re = y[i + iy].re;
			temp_im = y[i + iy].im;
			y[i + iy].re = y[i].re - temp_re;
			y[i + iy].im = y[i].im - temp_im;
			y[i].re += temp_re;
			y[i].im += temp_im;
		}

		istart = 1;
		for (j = ju; j < 256; j += ju) {
			twid_re = costab[j];
			twid_im = sintab[j];
			i = istart;
			ihi = istart + iheight;
			while (i < ihi) {
				temp_re = twid_re * y[i + iy].re - twid_im * y[i + iy].im;
				temp_im = twid_re * y[i + iy].im + twid_im * y[i + iy].re;
				y[i + iy].re = y[i].re - temp_re;
				y[i + iy].im = y[i].im - temp_im;
				y[i].re += temp_re;
				y[i].im += temp_im;
				i += ix;
			}

			istart++;
		}

		ju /= 2;
		iy = ix;
		ix += ix;
		iheight -= iy;
	}
}

//
// Arguments    : const creal_T x[192]
//                int xoffInit
//                const double costab[257]
//                const double sintab[257]
//                creal_T y[512]
// Return Type  : void
//
static void r2br_r2dit_trig_impl(const creal_T x[192], int xoffInit, const
	double costab[257], const double sintab[257], creal_T y[512])
{
	int i;
	int ix;
	int ju;
	int iy;
	boolean_T tst;
	double temp_re;
	double temp_im;
	int iheight;
	int istart;
	int j;
	double twid_re;
	double twid_im;
	int ihi;
	for (i = 0; i < 512; i++) {
		y[i].re = 0.0;
		y[i].im = 0.0;
	}

	ix = xoffInit;
	ju = 0;
	iy = 0;
	for (i = 0; i < 191; i++) {
		y[iy] = x[ix];
		iy = 512;
		tst = true;
		while (tst) {
			iy >>= 1;
			ju ^= iy;
			tst = ((ju & iy) == 0);
		}

		iy = ju;
		ix++;
	}

	y[iy] = x[ix];
	for (i = 0; i <= 511; i += 2) {
		temp_re = y[i + 1].re;
		temp_im = y[i + 1].im;
		y[i + 1].re = y[i].re - y[i + 1].re;
		y[i + 1].im = y[i].im - y[i + 1].im;
		y[i].re += temp_re;
		y[i].im += temp_im;
	}

	iy = 2;
	ix = 4;
	ju = 128;
	iheight = 509;
	while (ju > 0) {
		for (i = 0; i < iheight; i += ix) {
			temp_re = y[i + iy].re;
			temp_im = y[i + iy].im;
			y[i + iy].re = y[i].re - temp_re;
			y[i + iy].im = y[i].im - temp_im;
			y[i].re += temp_re;
			y[i].im += temp_im;
		}

		istart = 1;
		for (j = ju; j < 256; j += ju) {
			twid_re = costab[j];
			twid_im = sintab[j];
			i = istart;
			ihi = istart + iheight;
			while (i < ihi) {
				temp_re = twid_re * y[i + iy].re - twid_im * y[i + iy].im;
				temp_im = twid_re * y[i + iy].im + twid_im * y[i + iy].re;
				y[i + iy].re = y[i].re - temp_re;
				y[i + iy].im = y[i].im - temp_im;
				y[i].re += temp_re;
				y[i].im += temp_im;
				i += ix;
			}

			istart++;
		}

		ju /= 2;
		iy = ix;
		ix += ix;
		iheight -= iy;
	}
}

//
// Arguments    : const creal_T x[36864]
//                const double costab[257]
//                const double sintab[257]
//                const double sintabinv[257]
//                creal_T y[36864]
// Return Type  : void
//
void dobluesteinfft(const creal_T x[36864], const double costab[257], const
	double sintab[257], const double sintabinv[257], creal_T y
	[36864])
{
	int k;
	creal_T rwork[192];
	int xoff;
	static const creal_T dcv0[383] = { { 0.9998661379095618,// re
		0.01636173162648678              // im
	  }, { 0.99785892323860348,          // re
		0.065403129230143062             // im
	  }, { 0.989176509964781,            // re
		0.14673047445536175              // im
	  }, { 0.96592582628906831,          // re
		0.25881904510252074              // im
	  }, { 0.91749449644749126,          // re
		0.39774847452701106              // im
	  }, { 0.83146961230254524,          // re
		0.55557023301960218              // im
	  }, { 0.69544263500961168,          // re
		0.718581617779698                // im
	  }, { 0.50000000000000011,          // re
		0.8660254037844386               // im
	  }, { 0.24298017990326398,          // re
		0.970031253194544                // im
	  }, { -0.065403129230143145,        // re
		0.99785892323860348              // im
	  }, { -0.39774847452701106,         // re
		0.91749449644749126              // im
	  }, { -0.70710678118654746,         // re
		0.70710678118654757              // im
	  }, { -0.93001722368401207,         // re
		0.36751593659470361              // im
	  }, { -0.99785892323860348,         // re
		-0.065403129230142867            // im
	  }, { -0.85772861000027212,         // re
		-0.51410274419322155             // im
	  }, { -0.50000000000000044,         // re
		-0.86602540378443849             // im
	  }, { 0.016361731626486246,         // re
		-0.9998661379095618              // im
	  }, { 0.55557023301960184,          // re
		-0.83146961230254546             // im
	  }, { 0.93001722368401174,          // re
		-0.3675159365947045              // im
	  }, { 0.96592582628906831,          // re
		0.25881904510252074              // im
	  }, { 0.59569930449243347,          // re
		0.80320753148064483              // im
	  }, { -0.065403129230143145,        // re
		0.99785892323860348              // im
	  }, { -0.718581617779698,           // re
		0.69544263500961168              // im
	  }, { -1.0,                         // re
		1.2246467991473532E-16           // im
	  }, { -0.69544263500961168,         // re
		-0.718581617779698               // im
	  }, { 0.065403129230142368,         // re
		-0.99785892323860359             // im
	  }, { 0.803207531480645,            // re
		-0.59569930449243325             // im
	  }, { 0.96592582628906831,          // re
		0.25881904510252074              // im
	  }, { 0.36751593659470372,          // re
		0.93001722368401207              // im
	  }, { -0.55557023301960229,         // re
		0.83146961230254512              // im
	  }, { -0.9998661379095618,          // re
		-0.016361731626486752            // im
	  }, { -0.50000000000000044,         // re
		-0.86602540378443849             // im
	  }, { 0.51410274419322155,          // re
		-0.85772861000027223             // im
	  }, { 0.99785892323860348,          // re
		0.065403129230143062             // im
	  }, { 0.36751593659470372,          // re
		0.93001722368401207              // im
	  }, { -0.70710678118654746,         // re
		0.70710678118654757              // im
	  }, { -0.91749449644749148,         // re
		-0.39774847452701062             // im
	  }, { 0.065403129230142368,         // re
		-0.99785892323860359             // im
	  }, { 0.970031253194544,            // re
		-0.24298017990326418             // im
	  }, { 0.50000000000000011,          // re
		0.8660254037844386               // im
	  }, { -0.718581617779698,           // re
		0.69544263500961168              // im
	  }, { -0.83146961230254546,         // re
		-0.555570233019602               // im
	  }, { 0.39774847452701095,          // re
		-0.91749449644749137             // im
	  }, { 0.96592582628906831,          // re
		0.25881904510252074              // im
	  }, { -0.14673047445536186,         // re
		0.9891765099647809               // im
	  }, { -0.99785892323860348,         // re
		-0.065403129230142867            // im
	  }, { 0.016361731626486246,         // re
		-0.9998661379095618              // im
	  }, { 1.0,                          // re
		-0.0                             // im
	  }, { -0.016361731626486589,        // re
		0.9998661379095618               // im
	  }, { -0.99785892323860348,         // re
		-0.065403129230142867            // im
	  }, { 0.14673047445536194,          // re
		-0.9891765099647809              // im
	  }, { 0.96592582628906831,          // re
		0.25881904510252074              // im
	  }, { -0.39774847452701106,         // re
		0.91749449644749126              // im
	  }, { -0.83146961230254546,         // re
		-0.555570233019602               // im
	  }, { 0.71858161777969765,          // re
		-0.69544263500961212             // im
	  }, { 0.50000000000000011,          // re
		0.8660254037844386               // im
	  }, { -0.97003125319454409,         // re
		0.24298017990326362              // im
	  }, { 0.065403129230142368,         // re
		-0.99785892323860359             // im
	  }, { 0.91749449644749126,          // re
		0.39774847452701106              // im
	  }, { -0.70710678118654746,         // re
		0.70710678118654757              // im
	  }, { -0.36751593659470361,         // re
		-0.93001722368401207             // im
	  }, { 0.99785892323860348,          // re
		0.065403129230143062             // im
	  }, { -0.51410274419322155,         // re
		0.85772861000027212              // im
	  }, { -0.50000000000000044,         // re
		-0.86602540378443849             // im
	  }, { 0.9998661379095618,           // re
		0.01636173162648678              // im
	  }, { -0.55557023301960229,         // re
		0.83146961230254512              // im
	  }, { -0.36751593659470361,         // re
		-0.93001722368401207             // im
	  }, { 0.96592582628906831,          // re
		0.25881904510252074              // im
	  }, { -0.80320753148064483,         // re
		0.59569930449243347              // im
	  }, { 0.065403129230142368,         // re
		-0.99785892323860359             // im
	  }, { 0.69544263500961168,          // re
		0.718581617779698                // im
	  }, { -1.0,                         // re
		1.2246467991473532E-16           // im
	  }, { 0.71858161777969765,          // re
		-0.69544263500961212             // im
	  }, { -0.065403129230143145,        // re
		0.99785892323860348              // im
	  }, { -0.59569930449243391,         // re
		-0.8032075314806445              // im
	  }, { 0.96592582628906831,          // re
		0.25881904510252074              // im
	  }, { -0.93001722368401207,         // re
		0.36751593659470361              // im
	  }, { 0.55557023301960184,          // re
		-0.83146961230254546             // im
	  }, { -0.016361731626486589,        // re
		0.9998661379095618               // im
	  }, { -0.50000000000000044,         // re
		-0.86602540378443849             // im
	  }, { 0.857728610000272,            // re
		0.51410274419322177              // im
	  }, { -0.99785892323860348,         // re
		-0.065403129230142867            // im
	  }, { 0.93001722368401174,          // re
		-0.3675159365947045              // im
	  }, { -0.70710678118654746,         // re
		0.70710678118654757              // im
	  }, { 0.39774847452701095,          // re
		-0.91749449644749137             // im
	  }, { -0.065403129230143145,        // re
		0.99785892323860348              // im
	  }, { -0.24298017990326412,         // re
		-0.970031253194544               // im
	  }, { 0.50000000000000011,          // re
		0.8660254037844386               // im
	  }, { -0.69544263500961168,         // re
		-0.718581617779698               // im
	  }, { 0.83146961230254524,          // re
		0.55557023301960218              // im
	  }, { -0.91749449644749148,         // re
		-0.39774847452701062             // im
	  }, { 0.96592582628906831,          // re
		0.25881904510252074              // im
	  }, { -0.989176509964781,           // re
		-0.14673047445536158             // im
	  }, { 0.99785892323860348,          // re
		0.065403129230143062             // im
	  }, { -0.9998661379095618,          // re
		-0.016361731626486752            // im
	  }, { 1.0,                          // re
		-0.0                             // im
	  }, { -0.9998661379095618,          // re
		-0.016361731626486752            // im
	  }, { 0.99785892323860348,          // re
		0.065403129230143062             // im
	  }, { -0.989176509964781,           // re
		-0.14673047445536158             // im
	  }, { 0.96592582628906831,          // re
		0.25881904510252074              // im
	  }, { -0.91749449644749148,         // re
		-0.39774847452701062             // im
	  }, { 0.83146961230254524,          // re
		0.55557023301960218              // im
	  }, { -0.69544263500961168,         // re
		-0.718581617779698               // im
	  }, { 0.50000000000000011,          // re
		0.8660254037844386               // im
	  }, { -0.24298017990326412,         // re
		-0.970031253194544               // im
	  }, { -0.065403129230143145,        // re
		0.99785892323860348              // im
	  }, { 0.39774847452701095,          // re
		-0.91749449644749137             // im
	  }, { -0.70710678118654746,         // re
		0.70710678118654757              // im
	  }, { 0.93001722368401174,          // re
		-0.3675159365947045              // im
	  }, { -0.99785892323860348,         // re
		-0.065403129230142867            // im
	  }, { 0.857728610000272,            // re
		0.51410274419322177              // im
	  }, { -0.50000000000000044,         // re
		-0.86602540378443849             // im
	  }, { -0.016361731626486589,        // re
		0.9998661379095618               // im
	  }, { 0.55557023301960184,          // re
		-0.83146961230254546             // im
	  }, { -0.93001722368401207,         // re
		0.36751593659470361              // im
	  }, { 0.96592582628906831,          // re
		0.25881904510252074              // im
	  }, { -0.59569930449243391,         // re
		-0.8032075314806445              // im
	  }, { -0.065403129230143145,        // re
		0.99785892323860348              // im
	  }, { 0.71858161777969765,          // re
		-0.69544263500961212             // im
	  }, { -1.0,                         // re
		1.2246467991473532E-16           // im
	  }, { 0.69544263500961168,          // re
		0.718581617779698                // im
	  }, { 0.065403129230142368,         // re
		-0.99785892323860359             // im
	  }, { -0.80320753148064483,         // re
		0.59569930449243347              // im
	  }, { 0.96592582628906831,          // re
		0.25881904510252074              // im
	  }, { -0.36751593659470361,         // re
		-0.93001722368401207             // im
	  }, { -0.55557023301960229,         // re
		0.83146961230254512              // im
	  }, { 0.9998661379095618,           // re
		0.01636173162648678              // im
	  }, { -0.50000000000000044,         // re
		-0.86602540378443849             // im
	  }, { -0.51410274419322155,         // re
		0.85772861000027212              // im
	  }, { 0.99785892323860348,          // re
		0.065403129230143062             // im
	  }, { -0.36751593659470361,         // re
		-0.93001722368401207             // im
	  }, { -0.70710678118654746,         // re
		0.70710678118654757              // im
	  }, { 0.91749449644749126,          // re
		0.39774847452701106              // im
	  }, { 0.065403129230142368,         // re
		-0.99785892323860359             // im
	  }, { -0.97003125319454409,         // re
		0.24298017990326362              // im
	  }, { 0.50000000000000011,          // re
		0.8660254037844386               // im
	  }, { 0.71858161777969765,          // re
		-0.69544263500961212             // im
	  }, { -0.83146961230254546,         // re
		-0.555570233019602               // im
	  }, { -0.39774847452701106,         // re
		0.91749449644749126              // im
	  }, { 0.96592582628906831,          // re
		0.25881904510252074              // im
	  }, { 0.14673047445536194,          // re
		-0.9891765099647809              // im
	  }, { -0.99785892323860348,         // re
		-0.065403129230142867            // im
	  }, { -0.016361731626486589,        // re
		0.9998661379095618               // im
	  }, { 1.0,                          // re
		-0.0                             // im
	  }, { 0.016361731626486246,         // re
		-0.9998661379095618              // im
	  }, { -0.99785892323860348,         // re
		-0.065403129230142867            // im
	  }, { -0.14673047445536186,         // re
		0.9891765099647809               // im
	  }, { 0.96592582628906831,          // re
		0.25881904510252074              // im
	  }, { 0.39774847452701095,          // re
		-0.91749449644749137             // im
	  }, { -0.83146961230254546,         // re
		-0.555570233019602               // im
	  }, { -0.718581617779698,           // re
		0.69544263500961168              // im
	  }, { 0.50000000000000011,          // re
		0.8660254037844386               // im
	  }, { 0.970031253194544,            // re
		-0.24298017990326418             // im
	  }, { 0.065403129230142368,         // re
		-0.99785892323860359             // im
	  }, { -0.91749449644749148,         // re
		-0.39774847452701062             // im
	  }, { -0.70710678118654746,         // re
		0.70710678118654757              // im
	  }, { 0.36751593659470372,          // re
		0.93001722368401207              // im
	  }, { 0.99785892323860348,          // re
		0.065403129230143062             // im
	  }, { 0.51410274419322155,          // re
		-0.85772861000027223             // im
	  }, { -0.50000000000000044,         // re
		-0.86602540378443849             // im
	  }, { -0.9998661379095618,          // re
		-0.016361731626486752            // im
	  }, { -0.55557023301960229,         // re
		0.83146961230254512              // im
	  }, { 0.36751593659470372,          // re
		0.93001722368401207              // im
	  }, { 0.96592582628906831,          // re
		0.25881904510252074              // im
	  }, { 0.803207531480645,            // re
		-0.59569930449243325             // im
	  }, { 0.065403129230142368,         // re
		-0.99785892323860359             // im
	  }, { -0.69544263500961168,         // re
		-0.718581617779698               // im
	  }, { -1.0,                         // re
		1.2246467991473532E-16           // im
	  }, { -0.718581617779698,           // re
		0.69544263500961168              // im
	  }, { -0.065403129230143145,        // re
		0.99785892323860348              // im
	  }, { 0.59569930449243347,          // re
		0.80320753148064483              // im
	  }, { 0.96592582628906831,          // re
		0.25881904510252074              // im
	  }, { 0.93001722368401174,          // re
		-0.3675159365947045              // im
	  }, { 0.55557023301960184,          // re
		-0.83146961230254546             // im
	  }, { 0.016361731626486246,         // re
		-0.9998661379095618              // im
	  }, { -0.50000000000000044,         // re
		-0.86602540378443849             // im
	  }, { -0.85772861000027212,         // re
		-0.51410274419322155             // im
	  }, { -0.99785892323860348,         // re
		-0.065403129230142867            // im
	  }, { -0.93001722368401207,         // re
		0.36751593659470361              // im
	  }, { -0.70710678118654746,         // re
		0.70710678118654757              // im
	  }, { -0.39774847452701106,         // re
		0.91749449644749126              // im
	  }, { -0.065403129230143145,        // re
		0.99785892323860348              // im
	  }, { 0.24298017990326398,          // re
		0.970031253194544                // im
	  }, { 0.50000000000000011,          // re
		0.8660254037844386               // im
	  }, { 0.69544263500961168,          // re
		0.718581617779698                // im
	  }, { 0.83146961230254524,          // re
		0.55557023301960218              // im
	  }, { 0.91749449644749126,          // re
		0.39774847452701106              // im
	  }, { 0.96592582628906831,          // re
		0.25881904510252074              // im
	  }, { 0.989176509964781,            // re
		0.14673047445536175              // im
	  }, { 0.99785892323860348,          // re
		0.065403129230143062             // im
	  }, { 0.9998661379095618,           // re
		0.01636173162648678              // im
	  }, { 1.0,                          // re
		0.0                              // im
	  }, { 0.9998661379095618,           // re
		0.01636173162648678              // im
	  }, { 0.99785892323860348,          // re
		0.065403129230143062             // im
	  }, { 0.989176509964781,            // re
		0.14673047445536175              // im
	  }, { 0.96592582628906831,          // re
		0.25881904510252074              // im
	  }, { 0.91749449644749126,          // re
		0.39774847452701106              // im
	  }, { 0.83146961230254524,          // re
		0.55557023301960218              // im
	  }, { 0.69544263500961168,          // re
		0.718581617779698                // im
	  }, { 0.50000000000000011,          // re
		0.8660254037844386               // im
	  }, { 0.24298017990326398,          // re
		0.970031253194544                // im
	  }, { -0.065403129230143145,        // re
		0.99785892323860348              // im
	  }, { -0.39774847452701106,         // re
		0.91749449644749126              // im
	  }, { -0.70710678118654746,         // re
		0.70710678118654757              // im
	  }, { -0.93001722368401207,         // re
		0.36751593659470361              // im
	  }, { -0.99785892323860348,         // re
		-0.065403129230142867            // im
	  }, { -0.85772861000027212,         // re
		-0.51410274419322155             // im
	  }, { -0.50000000000000044,         // re
		-0.86602540378443849             // im
	  }, { 0.016361731626486246,         // re
		-0.9998661379095618              // im
	  }, { 0.55557023301960184,          // re
		-0.83146961230254546             // im
	  }, { 0.93001722368401174,          // re
		-0.3675159365947045              // im
	  }, { 0.96592582628906831,          // re
		0.25881904510252074              // im
	  }, { 0.59569930449243347,          // re
		0.80320753148064483              // im
	  }, { -0.065403129230143145,        // re
		0.99785892323860348              // im
	  }, { -0.718581617779698,           // re
		0.69544263500961168              // im
	  }, { -1.0,                         // re
		1.2246467991473532E-16           // im
	  }, { -0.69544263500961168,         // re
		-0.718581617779698               // im
	  }, { 0.065403129230142368,         // re
		-0.99785892323860359             // im
	  }, { 0.803207531480645,            // re
		-0.59569930449243325             // im
	  }, { 0.96592582628906831,          // re
		0.25881904510252074              // im
	  }, { 0.36751593659470372,          // re
		0.93001722368401207              // im
	  }, { -0.55557023301960229,         // re
		0.83146961230254512              // im
	  }, { -0.9998661379095618,          // re
		-0.016361731626486752            // im
	  }, { -0.50000000000000044,         // re
		-0.86602540378443849             // im
	  }, { 0.51410274419322155,          // re
		-0.85772861000027223             // im
	  }, { 0.99785892323860348,          // re
		0.065403129230143062             // im
	  }, { 0.36751593659470372,          // re
		0.93001722368401207              // im
	  }, { -0.70710678118654746,         // re
		0.70710678118654757              // im
	  }, { -0.91749449644749148,         // re
		-0.39774847452701062             // im
	  }, { 0.065403129230142368,         // re
		-0.99785892323860359             // im
	  }, { 0.970031253194544,            // re
		-0.24298017990326418             // im
	  }, { 0.50000000000000011,          // re
		0.8660254037844386               // im
	  }, { -0.718581617779698,           // re
		0.69544263500961168              // im
	  }, { -0.83146961230254546,         // re
		-0.555570233019602               // im
	  }, { 0.39774847452701095,          // re
		-0.91749449644749137             // im
	  }, { 0.96592582628906831,          // re
		0.25881904510252074              // im
	  }, { -0.14673047445536186,         // re
		0.9891765099647809               // im
	  }, { -0.99785892323860348,         // re
		-0.065403129230142867            // im
	  }, { 0.016361731626486246,         // re
		-0.9998661379095618              // im
	  }, { 1.0,                          // re
		-0.0                             // im
	  }, { -0.016361731626486589,        // re
		0.9998661379095618               // im
	  }, { -0.99785892323860348,         // re
		-0.065403129230142867            // im
	  }, { 0.14673047445536194,          // re
		-0.9891765099647809              // im
	  }, { 0.96592582628906831,          // re
		0.25881904510252074              // im
	  }, { -0.39774847452701106,         // re
		0.91749449644749126              // im
	  }, { -0.83146961230254546,         // re
		-0.555570233019602               // im
	  }, { 0.71858161777969765,          // re
		-0.69544263500961212             // im
	  }, { 0.50000000000000011,          // re
		0.8660254037844386               // im
	  }, { -0.97003125319454409,         // re
		0.24298017990326362              // im
	  }, { 0.065403129230142368,         // re
		-0.99785892323860359             // im
	  }, { 0.91749449644749126,          // re
		0.39774847452701106              // im
	  }, { -0.70710678118654746,         // re
		0.70710678118654757              // im
	  }, { -0.36751593659470361,         // re
		-0.93001722368401207             // im
	  }, { 0.99785892323860348,          // re
		0.065403129230143062             // im
	  }, { -0.51410274419322155,         // re
		0.85772861000027212              // im
	  }, { -0.50000000000000044,         // re
		-0.86602540378443849             // im
	  }, { 0.9998661379095618,           // re
		0.01636173162648678              // im
	  }, { -0.55557023301960229,         // re
		0.83146961230254512              // im
	  }, { -0.36751593659470361,         // re
		-0.93001722368401207             // im
	  }, { 0.96592582628906831,          // re
		0.25881904510252074              // im
	  }, { -0.80320753148064483,         // re
		0.59569930449243347              // im
	  }, { 0.065403129230142368,         // re
		-0.99785892323860359             // im
	  }, { 0.69544263500961168,          // re
		0.718581617779698                // im
	  }, { -1.0,                         // re
		1.2246467991473532E-16           // im
	  }, { 0.71858161777969765,          // re
		-0.69544263500961212             // im
	  }, { -0.065403129230143145,        // re
		0.99785892323860348              // im
	  }, { -0.59569930449243391,         // re
		-0.8032075314806445              // im
	  }, { 0.96592582628906831,          // re
		0.25881904510252074              // im
	  }, { -0.93001722368401207,         // re
		0.36751593659470361              // im
	  }, { 0.55557023301960184,          // re
		-0.83146961230254546             // im
	  }, { -0.016361731626486589,        // re
		0.9998661379095618               // im
	  }, { -0.50000000000000044,         // re
		-0.86602540378443849             // im
	  }, { 0.857728610000272,            // re
		0.51410274419322177              // im
	  }, { -0.99785892323860348,         // re
		-0.065403129230142867            // im
	  }, { 0.93001722368401174,          // re
		-0.3675159365947045              // im
	  }, { -0.70710678118654746,         // re
		0.70710678118654757              // im
	  }, { 0.39774847452701095,          // re
		-0.91749449644749137             // im
	  }, { -0.065403129230143145,        // re
		0.99785892323860348              // im
	  }, { -0.24298017990326412,         // re
		-0.970031253194544               // im
	  }, { 0.50000000000000011,          // re
		0.8660254037844386               // im
	  }, { -0.69544263500961168,         // re
		-0.718581617779698               // im
	  }, { 0.83146961230254524,          // re
		0.55557023301960218              // im
	  }, { -0.91749449644749148,         // re
		-0.39774847452701062             // im
	  }, { 0.96592582628906831,          // re
		0.25881904510252074              // im
	  }, { -0.989176509964781,           // re
		-0.14673047445536158             // im
	  }, { 0.99785892323860348,          // re
		0.065403129230143062             // im
	  }, { -0.9998661379095618,          // re
		-0.016361731626486752            // im
	  }, { 1.0,                          // re
		-0.0                             // im
	  }, { -0.9998661379095618,          // re
		-0.016361731626486752            // im
	  }, { 0.99785892323860348,          // re
		0.065403129230143062             // im
	  }, { -0.989176509964781,           // re
		-0.14673047445536158             // im
	  }, { 0.96592582628906831,          // re
		0.25881904510252074              // im
	  }, { -0.91749449644749148,         // re
		-0.39774847452701062             // im
	  }, { 0.83146961230254524,          // re
		0.55557023301960218              // im
	  }, { -0.69544263500961168,         // re
		-0.718581617779698               // im
	  }, { 0.50000000000000011,          // re
		0.8660254037844386               // im
	  }, { -0.24298017990326412,         // re
		-0.970031253194544               // im
	  }, { -0.065403129230143145,        // re
		0.99785892323860348              // im
	  }, { 0.39774847452701095,          // re
		-0.91749449644749137             // im
	  }, { -0.70710678118654746,         // re
		0.70710678118654757              // im
	  }, { 0.93001722368401174,          // re
		-0.3675159365947045              // im
	  }, { -0.99785892323860348,         // re
		-0.065403129230142867            // im
	  }, { 0.857728610000272,            // re
		0.51410274419322177              // im
	  }, { -0.50000000000000044,         // re
		-0.86602540378443849             // im
	  }, { -0.016361731626486589,        // re
		0.9998661379095618               // im
	  }, { 0.55557023301960184,          // re
		-0.83146961230254546             // im
	  }, { -0.93001722368401207,         // re
		0.36751593659470361              // im
	  }, { 0.96592582628906831,          // re
		0.25881904510252074              // im
	  }, { -0.59569930449243391,         // re
		-0.8032075314806445              // im
	  }, { -0.065403129230143145,        // re
		0.99785892323860348              // im
	  }, { 0.71858161777969765,          // re
		-0.69544263500961212             // im
	  }, { -1.0,                         // re
		1.2246467991473532E-16           // im
	  }, { 0.69544263500961168,          // re
		0.718581617779698                // im
	  }, { 0.065403129230142368,         // re
		-0.99785892323860359             // im
	  }, { -0.80320753148064483,         // re
		0.59569930449243347              // im
	  }, { 0.96592582628906831,          // re
		0.25881904510252074              // im
	  }, { -0.36751593659470361,         // re
		-0.93001722368401207             // im
	  }, { -0.55557023301960229,         // re
		0.83146961230254512              // im
	  }, { 0.9998661379095618,           // re
		0.01636173162648678              // im
	  }, { -0.50000000000000044,         // re
		-0.86602540378443849             // im
	  }, { -0.51410274419322155,         // re
		0.85772861000027212              // im
	  }, { 0.99785892323860348,          // re
		0.065403129230143062             // im
	  }, { -0.36751593659470361,         // re
		-0.93001722368401207             // im
	  }, { -0.70710678118654746,         // re
		0.70710678118654757              // im
	  }, { 0.91749449644749126,          // re
		0.39774847452701106              // im
	  }, { 0.065403129230142368,         // re
		-0.99785892323860359             // im
	  }, { -0.97003125319454409,         // re
		0.24298017990326362              // im
	  }, { 0.50000000000000011,          // re
		0.8660254037844386               // im
	  }, { 0.71858161777969765,          // re
		-0.69544263500961212             // im
	  }, { -0.83146961230254546,         // re
		-0.555570233019602               // im
	  }, { -0.39774847452701106,         // re
		0.91749449644749126              // im
	  }, { 0.96592582628906831,          // re
		0.25881904510252074              // im
	  }, { 0.14673047445536194,          // re
		-0.9891765099647809              // im
	  }, { -0.99785892323860348,         // re
		-0.065403129230142867            // im
	  }, { -0.016361731626486589,        // re
		0.9998661379095618               // im
	  }, { 1.0,                          // re
		-0.0                             // im
	  }, { 0.016361731626486246,         // re
		-0.9998661379095618              // im
	  }, { -0.99785892323860348,         // re
		-0.065403129230142867            // im
	  }, { -0.14673047445536186,         // re
		0.9891765099647809               // im
	  }, { 0.96592582628906831,          // re
		0.25881904510252074              // im
	  }, { 0.39774847452701095,          // re
		-0.91749449644749137             // im
	  }, { -0.83146961230254546,         // re
		-0.555570233019602               // im
	  }, { -0.718581617779698,           // re
		0.69544263500961168              // im
	  }, { 0.50000000000000011,          // re
		0.8660254037844386               // im
	  }, { 0.970031253194544,            // re
		-0.24298017990326418             // im
	  }, { 0.065403129230142368,         // re
		-0.99785892323860359             // im
	  }, { -0.91749449644749148,         // re
		-0.39774847452701062             // im
	  }, { -0.70710678118654746,         // re
		0.70710678118654757              // im
	  }, { 0.36751593659470372,          // re
		0.93001722368401207              // im
	  }, { 0.99785892323860348,          // re
		0.065403129230143062             // im
	  }, { 0.51410274419322155,          // re
		-0.85772861000027223             // im
	  }, { -0.50000000000000044,         // re
		-0.86602540378443849             // im
	  }, { -0.9998661379095618,          // re
		-0.016361731626486752            // im
	  }, { -0.55557023301960229,         // re
		0.83146961230254512              // im
	  }, { 0.36751593659470372,          // re
		0.93001722368401207              // im
	  }, { 0.96592582628906831,          // re
		0.25881904510252074              // im
	  }, { 0.803207531480645,            // re
		-0.59569930449243325             // im
	  }, { 0.065403129230142368,         // re
		-0.99785892323860359             // im
	  }, { -0.69544263500961168,         // re
		-0.718581617779698               // im
	  }, { -1.0,                         // re
		1.2246467991473532E-16           // im
	  }, { -0.718581617779698,           // re
		0.69544263500961168              // im
	  }, { -0.065403129230143145,        // re
		0.99785892323860348              // im
	  }, { 0.59569930449243347,          // re
		0.80320753148064483              // im
	  }, { 0.96592582628906831,          // re
		0.25881904510252074              // im
	  }, { 0.93001722368401174,          // re
		-0.3675159365947045              // im
	  }, { 0.55557023301960184,          // re
		-0.83146961230254546             // im
	  }, { 0.016361731626486246,         // re
		-0.9998661379095618              // im
	  }, { -0.50000000000000044,         // re
		-0.86602540378443849             // im
	  }, { -0.85772861000027212,         // re
		-0.51410274419322155             // im
	  }, { -0.99785892323860348,         // re
		-0.065403129230142867            // im
	  }, { -0.93001722368401207,         // re
		0.36751593659470361              // im
	  }, { -0.70710678118654746,         // re
		0.70710678118654757              // im
	  }, { -0.39774847452701106,         // re
		0.91749449644749126              // im
	  }, { -0.065403129230143145,        // re
		0.99785892323860348              // im
	  }, { 0.24298017990326398,          // re
		0.970031253194544                // im
	  }, { 0.50000000000000011,          // re
		0.8660254037844386               // im
	  }, { 0.69544263500961168,          // re
		0.718581617779698                // im
	  }, { 0.83146961230254524,          // re
		0.55557023301960218              // im
	  }, { 0.91749449644749126,          // re
		0.39774847452701106              // im
	  }, { 0.96592582628906831,          // re
		0.25881904510252074              // im
	  }, { 0.989176509964781,            // re
		0.14673047445536175              // im
	  }, { 0.99785892323860348,          // re
		0.065403129230143062             // im
	  }, { 0.9998661379095618,           // re
		0.01636173162648678              // im
	  } };

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(rwork,xoff)

	for (k = 1; k < 193; k++) {
		xoff = (k - 1) * 192;
		bluestein(x, xoff, costab, sintab, costab, sintabinv, dcv0, rwork);
		memcpy(&y[k * 192 + -192], &rwork[0], 192U * sizeof(creal_T));
	}
}

//
// File trailer for fft1.cpp
//
// [EOF]
//


// Function Declarations
static void eml_fftshift(creal_T x[36864], int dim);
static double rt_hypotd_snf(double u0, double u1);

// Function Definitions

//
// Arguments    : creal_T x[36864]
//                int dim
// Return Type  : void
//
static void eml_fftshift(creal_T x[36864], int dim)
{
	int vstride;
	int k;
	int npages;
	int b_k;
	int vspread;
	int midoffset;
	int i2;
	int i;
	int i1;
	int j;
	int ia;
	int ib;
	double xtmp_re;
	double xtmp_im;
	if (!(dim > 2)) {
		vstride = 1;
		for (k = 1; k < dim; k++) {
			if (k <= 2) {
				b_k = 192;
			}
			else {
				b_k = 1;
			}

			vstride *= b_k;
		}

		npages = 1;
		for (k = dim + 1; k < 3; k++) {
			npages *= 192;
		}

		vspread = 191 * vstride;
		midoffset = 96 * vstride - 1;
		i2 = 0;
		for (i = 1; i <= npages; i++) {
			i1 = i2;
			i2 += vspread;
			for (j = 1; j <= vstride; j++) {
				i1++;
				i2++;
				ia = i1 - 1;
				ib = i1 + midoffset;
				for (k = 0; k < 96; k++) {
					xtmp_re = x[ia].re;
					xtmp_im = x[ia].im;
					x[ia] = x[ib];
					x[ib].re = xtmp_re;
					x[ib].im = xtmp_im;
					ia += vstride;
					ib += vstride;
				}
			}
		}
	}
}

//
// Arguments    : double u0
//                double u1
// Return Type  : double
//
static double rt_hypotd_snf(double u0, double u1)
{
	double y;
	double a;
	double b;
	a = std::abs(u0);
	b = std::abs(u1);
	if (a < b) {
		a /= b;
		y = b * std::sqrt(a * a + 1.0);
	}
	else if (a > b) {
		b /= a;
		y = a * std::sqrt(b * b + 1.0);
	}
	else if (rtIsNaN_psf(b)) {
		y = b;
	}
	else {
		y = a * 1.4142135623730951;
	}

	return y;
}

//
// Arguments    : const double W[4096]
//                double PSF_final[36864]
// Return Type  : void
//
void psf_function(const double W[4096], double PSF_final[36864])
{
	int trueCount;
	int k;
	emxArray_int32_T *r0;
	double R_pupil;
	static const double dv0[4096] = { -0.069850000000000009, -0.069850000000000009,
	  -0.069850000000000009, -0.069850000000000009, -0.069850000000000009,
	  -0.069850000000000009, -0.069850000000000009, -0.069850000000000009,
	  -0.069850000000000009, -0.069850000000000009, -0.069850000000000009,
	  -0.069850000000000009, -0.069850000000000009, -0.069850000000000009,
	  -0.069850000000000009, -0.069850000000000009, -0.069850000000000009,
	  -0.069850000000000009, -0.069850000000000009, -0.069850000000000009,
	  -0.069850000000000009, -0.069850000000000009, -0.069850000000000009,
	  -0.069850000000000009, -0.069850000000000009, -0.069850000000000009,
	  -0.069850000000000009, -0.069850000000000009, -0.069850000000000009,
	  -0.069850000000000009, -0.069850000000000009, -0.069850000000000009,
	  -0.069850000000000009, -0.069850000000000009, -0.069850000000000009,
	  -0.069850000000000009, -0.069850000000000009, -0.069850000000000009,
	  -0.069850000000000009, -0.069850000000000009, -0.069850000000000009,
	  -0.069850000000000009, -0.069850000000000009, -0.069850000000000009,
	  -0.069850000000000009, -0.069850000000000009, -0.069850000000000009,
	  -0.069850000000000009, -0.069850000000000009, -0.069850000000000009,
	  -0.069850000000000009, -0.069850000000000009, -0.069850000000000009,
	  -0.069850000000000009, -0.069850000000000009, -0.069850000000000009,
	  -0.069850000000000009, -0.069850000000000009, -0.069850000000000009,
	  -0.069850000000000009, -0.069850000000000009, -0.069850000000000009,
	  -0.069850000000000009, -0.069850000000000009, -0.0676671875, -0.0676671875,
	  -0.0676671875, -0.0676671875, -0.0676671875, -0.0676671875, -0.0676671875,
	  -0.0676671875, -0.0676671875, -0.0676671875, -0.0676671875, -0.0676671875,
	  -0.0676671875, -0.0676671875, -0.0676671875, -0.0676671875, -0.0676671875,
	  -0.0676671875, -0.0676671875, -0.0676671875, -0.0676671875, -0.0676671875,
	  -0.0676671875, -0.0676671875, -0.0676671875, -0.0676671875, -0.0676671875,
	  -0.0676671875, -0.0676671875, -0.0676671875, -0.0676671875, -0.0676671875,
	  -0.0676671875, -0.0676671875, -0.0676671875, -0.0676671875, -0.0676671875,
	  -0.0676671875, -0.0676671875, -0.0676671875, -0.0676671875, -0.0676671875,
	  -0.0676671875, -0.0676671875, -0.0676671875, -0.0676671875, -0.0676671875,
	  -0.0676671875, -0.0676671875, -0.0676671875, -0.0676671875, -0.0676671875,
	  -0.0676671875, -0.0676671875, -0.0676671875, -0.0676671875, -0.0676671875,
	  -0.0676671875, -0.0676671875, -0.0676671875, -0.0676671875, -0.0676671875,
	  -0.0676671875, -0.0676671875, -0.065484375, -0.065484375, -0.065484375,
	  -0.065484375, -0.065484375, -0.065484375, -0.065484375, -0.065484375,
	  -0.065484375, -0.065484375, -0.065484375, -0.065484375, -0.065484375,
	  -0.065484375, -0.065484375, -0.065484375, -0.065484375, -0.065484375,
	  -0.065484375, -0.065484375, -0.065484375, -0.065484375, -0.065484375,
	  -0.065484375, -0.065484375, -0.065484375, -0.065484375, -0.065484375,
	  -0.065484375, -0.065484375, -0.065484375, -0.065484375, -0.065484375,
	  -0.065484375, -0.065484375, -0.065484375, -0.065484375, -0.065484375,
	  -0.065484375, -0.065484375, -0.065484375, -0.065484375, -0.065484375,
	  -0.065484375, -0.065484375, -0.065484375, -0.065484375, -0.065484375,
	  -0.065484375, -0.065484375, -0.065484375, -0.065484375, -0.065484375,
	  -0.065484375, -0.065484375, -0.065484375, -0.065484375, -0.065484375,
	  -0.065484375, -0.065484375, -0.065484375, -0.065484375, -0.065484375,
	  -0.065484375, -0.0633015625, -0.0633015625, -0.0633015625, -0.0633015625,
	  -0.0633015625, -0.0633015625, -0.0633015625, -0.0633015625, -0.0633015625,
	  -0.0633015625, -0.0633015625, -0.0633015625, -0.0633015625, -0.0633015625,
	  -0.0633015625, -0.0633015625, -0.0633015625, -0.0633015625, -0.0633015625,
	  -0.0633015625, -0.0633015625, -0.0633015625, -0.0633015625, -0.0633015625,
	  -0.0633015625, -0.0633015625, -0.0633015625, -0.0633015625, -0.0633015625,
	  -0.0633015625, -0.0633015625, -0.0633015625, -0.0633015625, -0.0633015625,
	  -0.0633015625, -0.0633015625, -0.0633015625, -0.0633015625, -0.0633015625,
	  -0.0633015625, -0.0633015625, -0.0633015625, -0.0633015625, -0.0633015625,
	  -0.0633015625, -0.0633015625, -0.0633015625, -0.0633015625, -0.0633015625,
	  -0.0633015625, -0.0633015625, -0.0633015625, -0.0633015625, -0.0633015625,
	  -0.0633015625, -0.0633015625, -0.0633015625, -0.0633015625, -0.0633015625,
	  -0.0633015625, -0.0633015625, -0.0633015625, -0.0633015625, -0.0633015625,
	  -0.06111875, -0.06111875, -0.06111875, -0.06111875, -0.06111875, -0.06111875,
	  -0.06111875, -0.06111875, -0.06111875, -0.06111875, -0.06111875, -0.06111875,
	  -0.06111875, -0.06111875, -0.06111875, -0.06111875, -0.06111875, -0.06111875,
	  -0.06111875, -0.06111875, -0.06111875, -0.06111875, -0.06111875, -0.06111875,
	  -0.06111875, -0.06111875, -0.06111875, -0.06111875, -0.06111875, -0.06111875,
	  -0.06111875, -0.06111875, -0.06111875, -0.06111875, -0.06111875, -0.06111875,
	  -0.06111875, -0.06111875, -0.06111875, -0.06111875, -0.06111875, -0.06111875,
	  -0.06111875, -0.06111875, -0.06111875, -0.06111875, -0.06111875, -0.06111875,
	  -0.06111875, -0.06111875, -0.06111875, -0.06111875, -0.06111875, -0.06111875,
	  -0.06111875, -0.06111875, -0.06111875, -0.06111875, -0.06111875, -0.06111875,
	  -0.06111875, -0.06111875, -0.06111875, -0.06111875, -0.058935937500000007,
	  -0.058935937500000007, -0.058935937500000007, -0.058935937500000007,
	  -0.058935937500000007, -0.058935937500000007, -0.058935937500000007,
	  -0.058935937500000007, -0.058935937500000007, -0.058935937500000007,
	  -0.058935937500000007, -0.058935937500000007, -0.058935937500000007,
	  -0.058935937500000007, -0.058935937500000007, -0.058935937500000007,
	  -0.058935937500000007, -0.058935937500000007, -0.058935937500000007,
	  -0.058935937500000007, -0.058935937500000007, -0.058935937500000007,
	  -0.058935937500000007, -0.058935937500000007, -0.058935937500000007,
	  -0.058935937500000007, -0.058935937500000007, -0.058935937500000007,
	  -0.058935937500000007, -0.058935937500000007, -0.058935937500000007,
	  -0.058935937500000007, -0.058935937500000007, -0.058935937500000007,
	  -0.058935937500000007, -0.058935937500000007, -0.058935937500000007,
	  -0.058935937500000007, -0.058935937500000007, -0.058935937500000007,
	  -0.058935937500000007, -0.058935937500000007, -0.058935937500000007,
	  -0.058935937500000007, -0.058935937500000007, -0.058935937500000007,
	  -0.058935937500000007, -0.058935937500000007, -0.058935937500000007,
	  -0.058935937500000007, -0.058935937500000007, -0.058935937500000007,
	  -0.058935937500000007, -0.058935937500000007, -0.058935937500000007,
	  -0.058935937500000007, -0.058935937500000007, -0.058935937500000007,
	  -0.058935937500000007, -0.058935937500000007, -0.058935937500000007,
	  -0.058935937500000007, -0.058935937500000007, -0.058935937500000007,
	  -0.056753125, -0.056753125, -0.056753125, -0.056753125, -0.056753125,
	  -0.056753125, -0.056753125, -0.056753125, -0.056753125, -0.056753125,
	  -0.056753125, -0.056753125, -0.056753125, -0.056753125, -0.056753125,
	  -0.056753125, -0.056753125, -0.056753125, -0.056753125, -0.056753125,
	  -0.056753125, -0.056753125, -0.056753125, -0.056753125, -0.056753125,
	  -0.056753125, -0.056753125, -0.056753125, -0.056753125, -0.056753125,
	  -0.056753125, -0.056753125, -0.056753125, -0.056753125, -0.056753125,
	  -0.056753125, -0.056753125, -0.056753125, -0.056753125, -0.056753125,
	  -0.056753125, -0.056753125, -0.056753125, -0.056753125, -0.056753125,
	  -0.056753125, -0.056753125, -0.056753125, -0.056753125, -0.056753125,
	  -0.056753125, -0.056753125, -0.056753125, -0.056753125, -0.056753125,
	  -0.056753125, -0.056753125, -0.056753125, -0.056753125, -0.056753125,
	  -0.056753125, -0.056753125, -0.056753125, -0.056753125, -0.0545703125,
	  -0.0545703125, -0.0545703125, -0.0545703125, -0.0545703125, -0.0545703125,
	  -0.0545703125, -0.0545703125, -0.0545703125, -0.0545703125, -0.0545703125,
	  -0.0545703125, -0.0545703125, -0.0545703125, -0.0545703125, -0.0545703125,
	  -0.0545703125, -0.0545703125, -0.0545703125, -0.0545703125, -0.0545703125,
	  -0.0545703125, -0.0545703125, -0.0545703125, -0.0545703125, -0.0545703125,
	  -0.0545703125, -0.0545703125, -0.0545703125, -0.0545703125, -0.0545703125,
	  -0.0545703125, -0.0545703125, -0.0545703125, -0.0545703125, -0.0545703125,
	  -0.0545703125, -0.0545703125, -0.0545703125, -0.0545703125, -0.0545703125,
	  -0.0545703125, -0.0545703125, -0.0545703125, -0.0545703125, -0.0545703125,
	  -0.0545703125, -0.0545703125, -0.0545703125, -0.0545703125, -0.0545703125,
	  -0.0545703125, -0.0545703125, -0.0545703125, -0.0545703125, -0.0545703125,
	  -0.0545703125, -0.0545703125, -0.0545703125, -0.0545703125, -0.0545703125,
	  -0.0545703125, -0.0545703125, -0.0545703125, -0.052387500000000004,
	  -0.052387500000000004, -0.052387500000000004, -0.052387500000000004,
	  -0.052387500000000004, -0.052387500000000004, -0.052387500000000004,
	  -0.052387500000000004, -0.052387500000000004, -0.052387500000000004,
	  -0.052387500000000004, -0.052387500000000004, -0.052387500000000004,
	  -0.052387500000000004, -0.052387500000000004, -0.052387500000000004,
	  -0.052387500000000004, -0.052387500000000004, -0.052387500000000004,
	  -0.052387500000000004, -0.052387500000000004, -0.052387500000000004,
	  -0.052387500000000004, -0.052387500000000004, -0.052387500000000004,
	  -0.052387500000000004, -0.052387500000000004, -0.052387500000000004,
	  -0.052387500000000004, -0.052387500000000004, -0.052387500000000004,
	  -0.052387500000000004, -0.052387500000000004, -0.052387500000000004,
	  -0.052387500000000004, -0.052387500000000004, -0.052387500000000004,
	  -0.052387500000000004, -0.052387500000000004, -0.052387500000000004,
	  -0.052387500000000004, -0.052387500000000004, -0.052387500000000004,
	  -0.052387500000000004, -0.052387500000000004, -0.052387500000000004,
	  -0.052387500000000004, -0.052387500000000004, -0.052387500000000004,
	  -0.052387500000000004, -0.052387500000000004, -0.052387500000000004,
	  -0.052387500000000004, -0.052387500000000004, -0.052387500000000004,
	  -0.052387500000000004, -0.052387500000000004, -0.052387500000000004,
	  -0.052387500000000004, -0.052387500000000004, -0.052387500000000004,
	  -0.052387500000000004, -0.052387500000000004, -0.052387500000000004,
	  -0.050204687500000005, -0.050204687500000005, -0.050204687500000005,
	  -0.050204687500000005, -0.050204687500000005, -0.050204687500000005,
	  -0.050204687500000005, -0.050204687500000005, -0.050204687500000005,
	  -0.050204687500000005, -0.050204687500000005, -0.050204687500000005,
	  -0.050204687500000005, -0.050204687500000005, -0.050204687500000005,
	  -0.050204687500000005, -0.050204687500000005, -0.050204687500000005,
	  -0.050204687500000005, -0.050204687500000005, -0.050204687500000005,
	  -0.050204687500000005, -0.050204687500000005, -0.050204687500000005,
	  -0.050204687500000005, -0.050204687500000005, -0.050204687500000005,
	  -0.050204687500000005, -0.050204687500000005, -0.050204687500000005,
	  -0.050204687500000005, -0.050204687500000005, -0.050204687500000005,
	  -0.050204687500000005, -0.050204687500000005, -0.050204687500000005,
	  -0.050204687500000005, -0.050204687500000005, -0.050204687500000005,
	  -0.050204687500000005, -0.050204687500000005, -0.050204687500000005,
	  -0.050204687500000005, -0.050204687500000005, -0.050204687500000005,
	  -0.050204687500000005, -0.050204687500000005, -0.050204687500000005,
	  -0.050204687500000005, -0.050204687500000005, -0.050204687500000005,
	  -0.050204687500000005, -0.050204687500000005, -0.050204687500000005,
	  -0.050204687500000005, -0.050204687500000005, -0.050204687500000005,
	  -0.050204687500000005, -0.050204687500000005, -0.050204687500000005,
	  -0.050204687500000005, -0.050204687500000005, -0.050204687500000005,
	  -0.050204687500000005, -0.048021875000000006, -0.048021875000000006,
	  -0.048021875000000006, -0.048021875000000006, -0.048021875000000006,
	  -0.048021875000000006, -0.048021875000000006, -0.048021875000000006,
	  -0.048021875000000006, -0.048021875000000006, -0.048021875000000006,
	  -0.048021875000000006, -0.048021875000000006, -0.048021875000000006,
	  -0.048021875000000006, -0.048021875000000006, -0.048021875000000006,
	  -0.048021875000000006, -0.048021875000000006, -0.048021875000000006,
	  -0.048021875000000006, -0.048021875000000006, -0.048021875000000006,
	  -0.048021875000000006, -0.048021875000000006, -0.048021875000000006,
	  -0.048021875000000006, -0.048021875000000006, -0.048021875000000006,
	  -0.048021875000000006, -0.048021875000000006, -0.048021875000000006,
	  -0.048021875000000006, -0.048021875000000006, -0.048021875000000006,
	  -0.048021875000000006, -0.048021875000000006, -0.048021875000000006,
	  -0.048021875000000006, -0.048021875000000006, -0.048021875000000006,
	  -0.048021875000000006, -0.048021875000000006, -0.048021875000000006,
	  -0.048021875000000006, -0.048021875000000006, -0.048021875000000006,
	  -0.048021875000000006, -0.048021875000000006, -0.048021875000000006,
	  -0.048021875000000006, -0.048021875000000006, -0.048021875000000006,
	  -0.048021875000000006, -0.048021875000000006, -0.048021875000000006,
	  -0.048021875000000006, -0.048021875000000006, -0.048021875000000006,
	  -0.048021875000000006, -0.048021875000000006, -0.048021875000000006,
	  -0.048021875000000006, -0.048021875000000006, -0.045839062500000007,
	  -0.045839062500000007, -0.045839062500000007, -0.045839062500000007,
	  -0.045839062500000007, -0.045839062500000007, -0.045839062500000007,
	  -0.045839062500000007, -0.045839062500000007, -0.045839062500000007,
	  -0.045839062500000007, -0.045839062500000007, -0.045839062500000007,
	  -0.045839062500000007, -0.045839062500000007, -0.045839062500000007,
	  -0.045839062500000007, -0.045839062500000007, -0.045839062500000007,
	  -0.045839062500000007, -0.045839062500000007, -0.045839062500000007,
	  -0.045839062500000007, -0.045839062500000007, -0.045839062500000007,
	  -0.045839062500000007, -0.045839062500000007, -0.045839062500000007,
	  -0.045839062500000007, -0.045839062500000007, -0.045839062500000007,
	  -0.045839062500000007, -0.045839062500000007, -0.045839062500000007,
	  -0.045839062500000007, -0.045839062500000007, -0.045839062500000007,
	  -0.045839062500000007, -0.045839062500000007, -0.045839062500000007,
	  -0.045839062500000007, -0.045839062500000007, -0.045839062500000007,
	  -0.045839062500000007, -0.045839062500000007, -0.045839062500000007,
	  -0.045839062500000007, -0.045839062500000007, -0.045839062500000007,
	  -0.045839062500000007, -0.045839062500000007, -0.045839062500000007,
	  -0.045839062500000007, -0.045839062500000007, -0.045839062500000007,
	  -0.045839062500000007, -0.045839062500000007, -0.045839062500000007,
	  -0.045839062500000007, -0.045839062500000007, -0.045839062500000007,
	  -0.045839062500000007, -0.045839062500000007, -0.045839062500000007,
	  -0.04365625, -0.04365625, -0.04365625, -0.04365625, -0.04365625, -0.04365625,
	  -0.04365625, -0.04365625, -0.04365625, -0.04365625, -0.04365625, -0.04365625,
	  -0.04365625, -0.04365625, -0.04365625, -0.04365625, -0.04365625, -0.04365625,
	  -0.04365625, -0.04365625, -0.04365625, -0.04365625, -0.04365625, -0.04365625,
	  -0.04365625, -0.04365625, -0.04365625, -0.04365625, -0.04365625, -0.04365625,
	  -0.04365625, -0.04365625, -0.04365625, -0.04365625, -0.04365625, -0.04365625,
	  -0.04365625, -0.04365625, -0.04365625, -0.04365625, -0.04365625, -0.04365625,
	  -0.04365625, -0.04365625, -0.04365625, -0.04365625, -0.04365625, -0.04365625,
	  -0.04365625, -0.04365625, -0.04365625, -0.04365625, -0.04365625, -0.04365625,
	  -0.04365625, -0.04365625, -0.04365625, -0.04365625, -0.04365625, -0.04365625,
	  -0.04365625, -0.04365625, -0.04365625, -0.04365625, -0.0414734375,
	  -0.0414734375, -0.0414734375, -0.0414734375, -0.0414734375, -0.0414734375,
	  -0.0414734375, -0.0414734375, -0.0414734375, -0.0414734375, -0.0414734375,
	  -0.0414734375, -0.0414734375, -0.0414734375, -0.0414734375, -0.0414734375,
	  -0.0414734375, -0.0414734375, -0.0414734375, -0.0414734375, -0.0414734375,
	  -0.0414734375, -0.0414734375, -0.0414734375, -0.0414734375, -0.0414734375,
	  -0.0414734375, -0.0414734375, -0.0414734375, -0.0414734375, -0.0414734375,
	  -0.0414734375, -0.0414734375, -0.0414734375, -0.0414734375, -0.0414734375,
	  -0.0414734375, -0.0414734375, -0.0414734375, -0.0414734375, -0.0414734375,
	  -0.0414734375, -0.0414734375, -0.0414734375, -0.0414734375, -0.0414734375,
	  -0.0414734375, -0.0414734375, -0.0414734375, -0.0414734375, -0.0414734375,
	  -0.0414734375, -0.0414734375, -0.0414734375, -0.0414734375, -0.0414734375,
	  -0.0414734375, -0.0414734375, -0.0414734375, -0.0414734375, -0.0414734375,
	  -0.0414734375, -0.0414734375, -0.0414734375, -0.039290625, -0.039290625,
	  -0.039290625, -0.039290625, -0.039290625, -0.039290625, -0.039290625,
	  -0.039290625, -0.039290625, -0.039290625, -0.039290625, -0.039290625,
	  -0.039290625, -0.039290625, -0.039290625, -0.039290625, -0.039290625,
	  -0.039290625, -0.039290625, -0.039290625, -0.039290625, -0.039290625,
	  -0.039290625, -0.039290625, -0.039290625, -0.039290625, -0.039290625,
	  -0.039290625, -0.039290625, -0.039290625, -0.039290625, -0.039290625,
	  -0.039290625, -0.039290625, -0.039290625, -0.039290625, -0.039290625,
	  -0.039290625, -0.039290625, -0.039290625, -0.039290625, -0.039290625,
	  -0.039290625, -0.039290625, -0.039290625, -0.039290625, -0.039290625,
	  -0.039290625, -0.039290625, -0.039290625, -0.039290625, -0.039290625,
	  -0.039290625, -0.039290625, -0.039290625, -0.039290625, -0.039290625,
	  -0.039290625, -0.039290625, -0.039290625, -0.039290625, -0.039290625,
	  -0.039290625, -0.039290625, -0.0371078125, -0.0371078125, -0.0371078125,
	  -0.0371078125, -0.0371078125, -0.0371078125, -0.0371078125, -0.0371078125,
	  -0.0371078125, -0.0371078125, -0.0371078125, -0.0371078125, -0.0371078125,
	  -0.0371078125, -0.0371078125, -0.0371078125, -0.0371078125, -0.0371078125,
	  -0.0371078125, -0.0371078125, -0.0371078125, -0.0371078125, -0.0371078125,
	  -0.0371078125, -0.0371078125, -0.0371078125, -0.0371078125, -0.0371078125,
	  -0.0371078125, -0.0371078125, -0.0371078125, -0.0371078125, -0.0371078125,
	  -0.0371078125, -0.0371078125, -0.0371078125, -0.0371078125, -0.0371078125,
	  -0.0371078125, -0.0371078125, -0.0371078125, -0.0371078125, -0.0371078125,
	  -0.0371078125, -0.0371078125, -0.0371078125, -0.0371078125, -0.0371078125,
	  -0.0371078125, -0.0371078125, -0.0371078125, -0.0371078125, -0.0371078125,
	  -0.0371078125, -0.0371078125, -0.0371078125, -0.0371078125, -0.0371078125,
	  -0.0371078125, -0.0371078125, -0.0371078125, -0.0371078125, -0.0371078125,
	  -0.0371078125, -0.034925000000000005, -0.034925000000000005,
	  -0.034925000000000005, -0.034925000000000005, -0.034925000000000005,
	  -0.034925000000000005, -0.034925000000000005, -0.034925000000000005,
	  -0.034925000000000005, -0.034925000000000005, -0.034925000000000005,
	  -0.034925000000000005, -0.034925000000000005, -0.034925000000000005,
	  -0.034925000000000005, -0.034925000000000005, -0.034925000000000005,
	  -0.034925000000000005, -0.034925000000000005, -0.034925000000000005,
	  -0.034925000000000005, -0.034925000000000005, -0.034925000000000005,
	  -0.034925000000000005, -0.034925000000000005, -0.034925000000000005,
	  -0.034925000000000005, -0.034925000000000005, -0.034925000000000005,
	  -0.034925000000000005, -0.034925000000000005, -0.034925000000000005,
	  -0.034925000000000005, -0.034925000000000005, -0.034925000000000005,
	  -0.034925000000000005, -0.034925000000000005, -0.034925000000000005,
	  -0.034925000000000005, -0.034925000000000005, -0.034925000000000005,
	  -0.034925000000000005, -0.034925000000000005, -0.034925000000000005,
	  -0.034925000000000005, -0.034925000000000005, -0.034925000000000005,
	  -0.034925000000000005, -0.034925000000000005, -0.034925000000000005,
	  -0.034925000000000005, -0.034925000000000005, -0.034925000000000005,
	  -0.034925000000000005, -0.034925000000000005, -0.034925000000000005,
	  -0.034925000000000005, -0.034925000000000005, -0.034925000000000005,
	  -0.034925000000000005, -0.034925000000000005, -0.034925000000000005,
	  -0.034925000000000005, -0.034925000000000005, -0.0327421875, -0.0327421875,
	  -0.0327421875, -0.0327421875, -0.0327421875, -0.0327421875, -0.0327421875,
	  -0.0327421875, -0.0327421875, -0.0327421875, -0.0327421875, -0.0327421875,
	  -0.0327421875, -0.0327421875, -0.0327421875, -0.0327421875, -0.0327421875,
	  -0.0327421875, -0.0327421875, -0.0327421875, -0.0327421875, -0.0327421875,
	  -0.0327421875, -0.0327421875, -0.0327421875, -0.0327421875, -0.0327421875,
	  -0.0327421875, -0.0327421875, -0.0327421875, -0.0327421875, -0.0327421875,
	  -0.0327421875, -0.0327421875, -0.0327421875, -0.0327421875, -0.0327421875,
	  -0.0327421875, -0.0327421875, -0.0327421875, -0.0327421875, -0.0327421875,
	  -0.0327421875, -0.0327421875, -0.0327421875, -0.0327421875, -0.0327421875,
	  -0.0327421875, -0.0327421875, -0.0327421875, -0.0327421875, -0.0327421875,
	  -0.0327421875, -0.0327421875, -0.0327421875, -0.0327421875, -0.0327421875,
	  -0.0327421875, -0.0327421875, -0.0327421875, -0.0327421875, -0.0327421875,
	  -0.0327421875, -0.0327421875, -0.030559375, -0.030559375, -0.030559375,
	  -0.030559375, -0.030559375, -0.030559375, -0.030559375, -0.030559375,
	  -0.030559375, -0.030559375, -0.030559375, -0.030559375, -0.030559375,
	  -0.030559375, -0.030559375, -0.030559375, -0.030559375, -0.030559375,
	  -0.030559375, -0.030559375, -0.030559375, -0.030559375, -0.030559375,
	  -0.030559375, -0.030559375, -0.030559375, -0.030559375, -0.030559375,
	  -0.030559375, -0.030559375, -0.030559375, -0.030559375, -0.030559375,
	  -0.030559375, -0.030559375, -0.030559375, -0.030559375, -0.030559375,
	  -0.030559375, -0.030559375, -0.030559375, -0.030559375, -0.030559375,
	  -0.030559375, -0.030559375, -0.030559375, -0.030559375, -0.030559375,
	  -0.030559375, -0.030559375, -0.030559375, -0.030559375, -0.030559375,
	  -0.030559375, -0.030559375, -0.030559375, -0.030559375, -0.030559375,
	  -0.030559375, -0.030559375, -0.030559375, -0.030559375, -0.030559375,
	  -0.030559375, -0.0283765625, -0.0283765625, -0.0283765625, -0.0283765625,
	  -0.0283765625, -0.0283765625, -0.0283765625, -0.0283765625, -0.0283765625,
	  -0.0283765625, -0.0283765625, -0.0283765625, -0.0283765625, -0.0283765625,
	  -0.0283765625, -0.0283765625, -0.0283765625, -0.0283765625, -0.0283765625,
	  -0.0283765625, -0.0283765625, -0.0283765625, -0.0283765625, -0.0283765625,
	  -0.0283765625, -0.0283765625, -0.0283765625, -0.0283765625, -0.0283765625,
	  -0.0283765625, -0.0283765625, -0.0283765625, -0.0283765625, -0.0283765625,
	  -0.0283765625, -0.0283765625, -0.0283765625, -0.0283765625, -0.0283765625,
	  -0.0283765625, -0.0283765625, -0.0283765625, -0.0283765625, -0.0283765625,
	  -0.0283765625, -0.0283765625, -0.0283765625, -0.0283765625, -0.0283765625,
	  -0.0283765625, -0.0283765625, -0.0283765625, -0.0283765625, -0.0283765625,
	  -0.0283765625, -0.0283765625, -0.0283765625, -0.0283765625, -0.0283765625,
	  -0.0283765625, -0.0283765625, -0.0283765625, -0.0283765625, -0.0283765625,
	  -0.026193750000000002, -0.026193750000000002, -0.026193750000000002,
	  -0.026193750000000002, -0.026193750000000002, -0.026193750000000002,
	  -0.026193750000000002, -0.026193750000000002, -0.026193750000000002,
	  -0.026193750000000002, -0.026193750000000002, -0.026193750000000002,
	  -0.026193750000000002, -0.026193750000000002, -0.026193750000000002,
	  -0.026193750000000002, -0.026193750000000002, -0.026193750000000002,
	  -0.026193750000000002, -0.026193750000000002, -0.026193750000000002,
	  -0.026193750000000002, -0.026193750000000002, -0.026193750000000002,
	  -0.026193750000000002, -0.026193750000000002, -0.026193750000000002,
	  -0.026193750000000002, -0.026193750000000002, -0.026193750000000002,
	  -0.026193750000000002, -0.026193750000000002, -0.026193750000000002,
	  -0.026193750000000002, -0.026193750000000002, -0.026193750000000002,
	  -0.026193750000000002, -0.026193750000000002, -0.026193750000000002,
	  -0.026193750000000002, -0.026193750000000002, -0.026193750000000002,
	  -0.026193750000000002, -0.026193750000000002, -0.026193750000000002,
	  -0.026193750000000002, -0.026193750000000002, -0.026193750000000002,
	  -0.026193750000000002, -0.026193750000000002, -0.026193750000000002,
	  -0.026193750000000002, -0.026193750000000002, -0.026193750000000002,
	  -0.026193750000000002, -0.026193750000000002, -0.026193750000000002,
	  -0.026193750000000002, -0.026193750000000002, -0.026193750000000002,
	  -0.026193750000000002, -0.026193750000000002, -0.026193750000000002,
	  -0.026193750000000002, -0.024010937500000003, -0.024010937500000003,
	  -0.024010937500000003, -0.024010937500000003, -0.024010937500000003,
	  -0.024010937500000003, -0.024010937500000003, -0.024010937500000003,
	  -0.024010937500000003, -0.024010937500000003, -0.024010937500000003,
	  -0.024010937500000003, -0.024010937500000003, -0.024010937500000003,
	  -0.024010937500000003, -0.024010937500000003, -0.024010937500000003,
	  -0.024010937500000003, -0.024010937500000003, -0.024010937500000003,
	  -0.024010937500000003, -0.024010937500000003, -0.024010937500000003,
	  -0.024010937500000003, -0.024010937500000003, -0.024010937500000003,
	  -0.024010937500000003, -0.024010937500000003, -0.024010937500000003,
	  -0.024010937500000003, -0.024010937500000003, -0.024010937500000003,
	  -0.024010937500000003, -0.024010937500000003, -0.024010937500000003,
	  -0.024010937500000003, -0.024010937500000003, -0.024010937500000003,
	  -0.024010937500000003, -0.024010937500000003, -0.024010937500000003,
	  -0.024010937500000003, -0.024010937500000003, -0.024010937500000003,
	  -0.024010937500000003, -0.024010937500000003, -0.024010937500000003,
	  -0.024010937500000003, -0.024010937500000003, -0.024010937500000003,
	  -0.024010937500000003, -0.024010937500000003, -0.024010937500000003,
	  -0.024010937500000003, -0.024010937500000003, -0.024010937500000003,
	  -0.024010937500000003, -0.024010937500000003, -0.024010937500000003,
	  -0.024010937500000003, -0.024010937500000003, -0.024010937500000003,
	  -0.024010937500000003, -0.024010937500000003, -0.021828125, -0.021828125,
	  -0.021828125, -0.021828125, -0.021828125, -0.021828125, -0.021828125,
	  -0.021828125, -0.021828125, -0.021828125, -0.021828125, -0.021828125,
	  -0.021828125, -0.021828125, -0.021828125, -0.021828125, -0.021828125,
	  -0.021828125, -0.021828125, -0.021828125, -0.021828125, -0.021828125,
	  -0.021828125, -0.021828125, -0.021828125, -0.021828125, -0.021828125,
	  -0.021828125, -0.021828125, -0.021828125, -0.021828125, -0.021828125,
	  -0.021828125, -0.021828125, -0.021828125, -0.021828125, -0.021828125,
	  -0.021828125, -0.021828125, -0.021828125, -0.021828125, -0.021828125,
	  -0.021828125, -0.021828125, -0.021828125, -0.021828125, -0.021828125,
	  -0.021828125, -0.021828125, -0.021828125, -0.021828125, -0.021828125,
	  -0.021828125, -0.021828125, -0.021828125, -0.021828125, -0.021828125,
	  -0.021828125, -0.021828125, -0.021828125, -0.021828125, -0.021828125,
	  -0.021828125, -0.021828125, -0.0196453125, -0.0196453125, -0.0196453125,
	  -0.0196453125, -0.0196453125, -0.0196453125, -0.0196453125, -0.0196453125,
	  -0.0196453125, -0.0196453125, -0.0196453125, -0.0196453125, -0.0196453125,
	  -0.0196453125, -0.0196453125, -0.0196453125, -0.0196453125, -0.0196453125,
	  -0.0196453125, -0.0196453125, -0.0196453125, -0.0196453125, -0.0196453125,
	  -0.0196453125, -0.0196453125, -0.0196453125, -0.0196453125, -0.0196453125,
	  -0.0196453125, -0.0196453125, -0.0196453125, -0.0196453125, -0.0196453125,
	  -0.0196453125, -0.0196453125, -0.0196453125, -0.0196453125, -0.0196453125,
	  -0.0196453125, -0.0196453125, -0.0196453125, -0.0196453125, -0.0196453125,
	  -0.0196453125, -0.0196453125, -0.0196453125, -0.0196453125, -0.0196453125,
	  -0.0196453125, -0.0196453125, -0.0196453125, -0.0196453125, -0.0196453125,
	  -0.0196453125, -0.0196453125, -0.0196453125, -0.0196453125, -0.0196453125,
	  -0.0196453125, -0.0196453125, -0.0196453125, -0.0196453125, -0.0196453125,
	  -0.0196453125, -0.017462500000000002, -0.017462500000000002,
	  -0.017462500000000002, -0.017462500000000002, -0.017462500000000002,
	  -0.017462500000000002, -0.017462500000000002, -0.017462500000000002,
	  -0.017462500000000002, -0.017462500000000002, -0.017462500000000002,
	  -0.017462500000000002, -0.017462500000000002, -0.017462500000000002,
	  -0.017462500000000002, -0.017462500000000002, -0.017462500000000002,
	  -0.017462500000000002, -0.017462500000000002, -0.017462500000000002,
	  -0.017462500000000002, -0.017462500000000002, -0.017462500000000002,
	  -0.017462500000000002, -0.017462500000000002, -0.017462500000000002,
	  -0.017462500000000002, -0.017462500000000002, -0.017462500000000002,
	  -0.017462500000000002, -0.017462500000000002, -0.017462500000000002,
	  -0.017462500000000002, -0.017462500000000002, -0.017462500000000002,
	  -0.017462500000000002, -0.017462500000000002, -0.017462500000000002,
	  -0.017462500000000002, -0.017462500000000002, -0.017462500000000002,
	  -0.017462500000000002, -0.017462500000000002, -0.017462500000000002,
	  -0.017462500000000002, -0.017462500000000002, -0.017462500000000002,
	  -0.017462500000000002, -0.017462500000000002, -0.017462500000000002,
	  -0.017462500000000002, -0.017462500000000002, -0.017462500000000002,
	  -0.017462500000000002, -0.017462500000000002, -0.017462500000000002,
	  -0.017462500000000002, -0.017462500000000002, -0.017462500000000002,
	  -0.017462500000000002, -0.017462500000000002, -0.017462500000000002,
	  -0.017462500000000002, -0.017462500000000002, -0.0152796875, -0.0152796875,
	  -0.0152796875, -0.0152796875, -0.0152796875, -0.0152796875, -0.0152796875,
	  -0.0152796875, -0.0152796875, -0.0152796875, -0.0152796875, -0.0152796875,
	  -0.0152796875, -0.0152796875, -0.0152796875, -0.0152796875, -0.0152796875,
	  -0.0152796875, -0.0152796875, -0.0152796875, -0.0152796875, -0.0152796875,
	  -0.0152796875, -0.0152796875, -0.0152796875, -0.0152796875, -0.0152796875,
	  -0.0152796875, -0.0152796875, -0.0152796875, -0.0152796875, -0.0152796875,
	  -0.0152796875, -0.0152796875, -0.0152796875, -0.0152796875, -0.0152796875,
	  -0.0152796875, -0.0152796875, -0.0152796875, -0.0152796875, -0.0152796875,
	  -0.0152796875, -0.0152796875, -0.0152796875, -0.0152796875, -0.0152796875,
	  -0.0152796875, -0.0152796875, -0.0152796875, -0.0152796875, -0.0152796875,
	  -0.0152796875, -0.0152796875, -0.0152796875, -0.0152796875, -0.0152796875,
	  -0.0152796875, -0.0152796875, -0.0152796875, -0.0152796875, -0.0152796875,
	  -0.0152796875, -0.0152796875, -0.013096875000000001, -0.013096875000000001,
	  -0.013096875000000001, -0.013096875000000001, -0.013096875000000001,
	  -0.013096875000000001, -0.013096875000000001, -0.013096875000000001,
	  -0.013096875000000001, -0.013096875000000001, -0.013096875000000001,
	  -0.013096875000000001, -0.013096875000000001, -0.013096875000000001,
	  -0.013096875000000001, -0.013096875000000001, -0.013096875000000001,
	  -0.013096875000000001, -0.013096875000000001, -0.013096875000000001,
	  -0.013096875000000001, -0.013096875000000001, -0.013096875000000001,
	  -0.013096875000000001, -0.013096875000000001, -0.013096875000000001,
	  -0.013096875000000001, -0.013096875000000001, -0.013096875000000001,
	  -0.013096875000000001, -0.013096875000000001, -0.013096875000000001,
	  -0.013096875000000001, -0.013096875000000001, -0.013096875000000001,
	  -0.013096875000000001, -0.013096875000000001, -0.013096875000000001,
	  -0.013096875000000001, -0.013096875000000001, -0.013096875000000001,
	  -0.013096875000000001, -0.013096875000000001, -0.013096875000000001,
	  -0.013096875000000001, -0.013096875000000001, -0.013096875000000001,
	  -0.013096875000000001, -0.013096875000000001, -0.013096875000000001,
	  -0.013096875000000001, -0.013096875000000001, -0.013096875000000001,
	  -0.013096875000000001, -0.013096875000000001, -0.013096875000000001,
	  -0.013096875000000001, -0.013096875000000001, -0.013096875000000001,
	  -0.013096875000000001, -0.013096875000000001, -0.013096875000000001,
	  -0.013096875000000001, -0.013096875000000001, -0.0109140625, -0.0109140625,
	  -0.0109140625, -0.0109140625, -0.0109140625, -0.0109140625, -0.0109140625,
	  -0.0109140625, -0.0109140625, -0.0109140625, -0.0109140625, -0.0109140625,
	  -0.0109140625, -0.0109140625, -0.0109140625, -0.0109140625, -0.0109140625,
	  -0.0109140625, -0.0109140625, -0.0109140625, -0.0109140625, -0.0109140625,
	  -0.0109140625, -0.0109140625, -0.0109140625, -0.0109140625, -0.0109140625,
	  -0.0109140625, -0.0109140625, -0.0109140625, -0.0109140625, -0.0109140625,
	  -0.0109140625, -0.0109140625, -0.0109140625, -0.0109140625, -0.0109140625,
	  -0.0109140625, -0.0109140625, -0.0109140625, -0.0109140625, -0.0109140625,
	  -0.0109140625, -0.0109140625, -0.0109140625, -0.0109140625, -0.0109140625,
	  -0.0109140625, -0.0109140625, -0.0109140625, -0.0109140625, -0.0109140625,
	  -0.0109140625, -0.0109140625, -0.0109140625, -0.0109140625, -0.0109140625,
	  -0.0109140625, -0.0109140625, -0.0109140625, -0.0109140625, -0.0109140625,
	  -0.0109140625, -0.0109140625, -0.0087312500000000012, -0.0087312500000000012,
	  -0.0087312500000000012, -0.0087312500000000012, -0.0087312500000000012,
	  -0.0087312500000000012, -0.0087312500000000012, -0.0087312500000000012,
	  -0.0087312500000000012, -0.0087312500000000012, -0.0087312500000000012,
	  -0.0087312500000000012, -0.0087312500000000012, -0.0087312500000000012,
	  -0.0087312500000000012, -0.0087312500000000012, -0.0087312500000000012,
	  -0.0087312500000000012, -0.0087312500000000012, -0.0087312500000000012,
	  -0.0087312500000000012, -0.0087312500000000012, -0.0087312500000000012,
	  -0.0087312500000000012, -0.0087312500000000012, -0.0087312500000000012,
	  -0.0087312500000000012, -0.0087312500000000012, -0.0087312500000000012,
	  -0.0087312500000000012, -0.0087312500000000012, -0.0087312500000000012,
	  -0.0087312500000000012, -0.0087312500000000012, -0.0087312500000000012,
	  -0.0087312500000000012, -0.0087312500000000012, -0.0087312500000000012,
	  -0.0087312500000000012, -0.0087312500000000012, -0.0087312500000000012,
	  -0.0087312500000000012, -0.0087312500000000012, -0.0087312500000000012,
	  -0.0087312500000000012, -0.0087312500000000012, -0.0087312500000000012,
	  -0.0087312500000000012, -0.0087312500000000012, -0.0087312500000000012,
	  -0.0087312500000000012, -0.0087312500000000012, -0.0087312500000000012,
	  -0.0087312500000000012, -0.0087312500000000012, -0.0087312500000000012,
	  -0.0087312500000000012, -0.0087312500000000012, -0.0087312500000000012,
	  -0.0087312500000000012, -0.0087312500000000012, -0.0087312500000000012,
	  -0.0087312500000000012, -0.0087312500000000012, -0.0065484375000000004,
	  -0.0065484375000000004, -0.0065484375000000004, -0.0065484375000000004,
	  -0.0065484375000000004, -0.0065484375000000004, -0.0065484375000000004,
	  -0.0065484375000000004, -0.0065484375000000004, -0.0065484375000000004,
	  -0.0065484375000000004, -0.0065484375000000004, -0.0065484375000000004,
	  -0.0065484375000000004, -0.0065484375000000004, -0.0065484375000000004,
	  -0.0065484375000000004, -0.0065484375000000004, -0.0065484375000000004,
	  -0.0065484375000000004, -0.0065484375000000004, -0.0065484375000000004,
	  -0.0065484375000000004, -0.0065484375000000004, -0.0065484375000000004,
	  -0.0065484375000000004, -0.0065484375000000004, -0.0065484375000000004,
	  -0.0065484375000000004, -0.0065484375000000004, -0.0065484375000000004,
	  -0.0065484375000000004, -0.0065484375000000004, -0.0065484375000000004,
	  -0.0065484375000000004, -0.0065484375000000004, -0.0065484375000000004,
	  -0.0065484375000000004, -0.0065484375000000004, -0.0065484375000000004,
	  -0.0065484375000000004, -0.0065484375000000004, -0.0065484375000000004,
	  -0.0065484375000000004, -0.0065484375000000004, -0.0065484375000000004,
	  -0.0065484375000000004, -0.0065484375000000004, -0.0065484375000000004,
	  -0.0065484375000000004, -0.0065484375000000004, -0.0065484375000000004,
	  -0.0065484375000000004, -0.0065484375000000004, -0.0065484375000000004,
	  -0.0065484375000000004, -0.0065484375000000004, -0.0065484375000000004,
	  -0.0065484375000000004, -0.0065484375000000004, -0.0065484375000000004,
	  -0.0065484375000000004, -0.0065484375000000004, -0.0065484375000000004,
	  -0.0043656250000000006, -0.0043656250000000006, -0.0043656250000000006,
	  -0.0043656250000000006, -0.0043656250000000006, -0.0043656250000000006,
	  -0.0043656250000000006, -0.0043656250000000006, -0.0043656250000000006,
	  -0.0043656250000000006, -0.0043656250000000006, -0.0043656250000000006,
	  -0.0043656250000000006, -0.0043656250000000006, -0.0043656250000000006,
	  -0.0043656250000000006, -0.0043656250000000006, -0.0043656250000000006,
	  -0.0043656250000000006, -0.0043656250000000006, -0.0043656250000000006,
	  -0.0043656250000000006, -0.0043656250000000006, -0.0043656250000000006,
	  -0.0043656250000000006, -0.0043656250000000006, -0.0043656250000000006,
	  -0.0043656250000000006, -0.0043656250000000006, -0.0043656250000000006,
	  -0.0043656250000000006, -0.0043656250000000006, -0.0043656250000000006,
	  -0.0043656250000000006, -0.0043656250000000006, -0.0043656250000000006,
	  -0.0043656250000000006, -0.0043656250000000006, -0.0043656250000000006,
	  -0.0043656250000000006, -0.0043656250000000006, -0.0043656250000000006,
	  -0.0043656250000000006, -0.0043656250000000006, -0.0043656250000000006,
	  -0.0043656250000000006, -0.0043656250000000006, -0.0043656250000000006,
	  -0.0043656250000000006, -0.0043656250000000006, -0.0043656250000000006,
	  -0.0043656250000000006, -0.0043656250000000006, -0.0043656250000000006,
	  -0.0043656250000000006, -0.0043656250000000006, -0.0043656250000000006,
	  -0.0043656250000000006, -0.0043656250000000006, -0.0043656250000000006,
	  -0.0043656250000000006, -0.0043656250000000006, -0.0043656250000000006,
	  -0.0043656250000000006, -0.0021828125000000003, -0.0021828125000000003,
	  -0.0021828125000000003, -0.0021828125000000003, -0.0021828125000000003,
	  -0.0021828125000000003, -0.0021828125000000003, -0.0021828125000000003,
	  -0.0021828125000000003, -0.0021828125000000003, -0.0021828125000000003,
	  -0.0021828125000000003, -0.0021828125000000003, -0.0021828125000000003,
	  -0.0021828125000000003, -0.0021828125000000003, -0.0021828125000000003,
	  -0.0021828125000000003, -0.0021828125000000003, -0.0021828125000000003,
	  -0.0021828125000000003, -0.0021828125000000003, -0.0021828125000000003,
	  -0.0021828125000000003, -0.0021828125000000003, -0.0021828125000000003,
	  -0.0021828125000000003, -0.0021828125000000003, -0.0021828125000000003,
	  -0.0021828125000000003, -0.0021828125000000003, -0.0021828125000000003,
	  -0.0021828125000000003, -0.0021828125000000003, -0.0021828125000000003,
	  -0.0021828125000000003, -0.0021828125000000003, -0.0021828125000000003,
	  -0.0021828125000000003, -0.0021828125000000003, -0.0021828125000000003,
	  -0.0021828125000000003, -0.0021828125000000003, -0.0021828125000000003,
	  -0.0021828125000000003, -0.0021828125000000003, -0.0021828125000000003,
	  -0.0021828125000000003, -0.0021828125000000003, -0.0021828125000000003,
	  -0.0021828125000000003, -0.0021828125000000003, -0.0021828125000000003,
	  -0.0021828125000000003, -0.0021828125000000003, -0.0021828125000000003,
	  -0.0021828125000000003, -0.0021828125000000003, -0.0021828125000000003,
	  -0.0021828125000000003, -0.0021828125000000003, -0.0021828125000000003,
	  -0.0021828125000000003, -0.0021828125000000003, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
	  0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
	  0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
	  0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
	  0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
	  0.0021828125000000003, 0.0021828125000000003, 0.0021828125000000003,
	  0.0021828125000000003, 0.0021828125000000003, 0.0021828125000000003,
	  0.0021828125000000003, 0.0021828125000000003, 0.0021828125000000003,
	  0.0021828125000000003, 0.0021828125000000003, 0.0021828125000000003,
	  0.0021828125000000003, 0.0021828125000000003, 0.0021828125000000003,
	  0.0021828125000000003, 0.0021828125000000003, 0.0021828125000000003,
	  0.0021828125000000003, 0.0021828125000000003, 0.0021828125000000003,
	  0.0021828125000000003, 0.0021828125000000003, 0.0021828125000000003,
	  0.0021828125000000003, 0.0021828125000000003, 0.0021828125000000003,
	  0.0021828125000000003, 0.0021828125000000003, 0.0021828125000000003,
	  0.0021828125000000003, 0.0021828125000000003, 0.0021828125000000003,
	  0.0021828125000000003, 0.0021828125000000003, 0.0021828125000000003,
	  0.0021828125000000003, 0.0021828125000000003, 0.0021828125000000003,
	  0.0021828125000000003, 0.0021828125000000003, 0.0021828125000000003,
	  0.0021828125000000003, 0.0021828125000000003, 0.0021828125000000003,
	  0.0021828125000000003, 0.0021828125000000003, 0.0021828125000000003,
	  0.0021828125000000003, 0.0021828125000000003, 0.0021828125000000003,
	  0.0021828125000000003, 0.0021828125000000003, 0.0021828125000000003,
	  0.0021828125000000003, 0.0021828125000000003, 0.0021828125000000003,
	  0.0021828125000000003, 0.0021828125000000003, 0.0021828125000000003,
	  0.0021828125000000003, 0.0021828125000000003, 0.0021828125000000003,
	  0.0021828125000000003, 0.0043656250000000006, 0.0043656250000000006,
	  0.0043656250000000006, 0.0043656250000000006, 0.0043656250000000006,
	  0.0043656250000000006, 0.0043656250000000006, 0.0043656250000000006,
	  0.0043656250000000006, 0.0043656250000000006, 0.0043656250000000006,
	  0.0043656250000000006, 0.0043656250000000006, 0.0043656250000000006,
	  0.0043656250000000006, 0.0043656250000000006, 0.0043656250000000006,
	  0.0043656250000000006, 0.0043656250000000006, 0.0043656250000000006,
	  0.0043656250000000006, 0.0043656250000000006, 0.0043656250000000006,
	  0.0043656250000000006, 0.0043656250000000006, 0.0043656250000000006,
	  0.0043656250000000006, 0.0043656250000000006, 0.0043656250000000006,
	  0.0043656250000000006, 0.0043656250000000006, 0.0043656250000000006,
	  0.0043656250000000006, 0.0043656250000000006, 0.0043656250000000006,
	  0.0043656250000000006, 0.0043656250000000006, 0.0043656250000000006,
	  0.0043656250000000006, 0.0043656250000000006, 0.0043656250000000006,
	  0.0043656250000000006, 0.0043656250000000006, 0.0043656250000000006,
	  0.0043656250000000006, 0.0043656250000000006, 0.0043656250000000006,
	  0.0043656250000000006, 0.0043656250000000006, 0.0043656250000000006,
	  0.0043656250000000006, 0.0043656250000000006, 0.0043656250000000006,
	  0.0043656250000000006, 0.0043656250000000006, 0.0043656250000000006,
	  0.0043656250000000006, 0.0043656250000000006, 0.0043656250000000006,
	  0.0043656250000000006, 0.0043656250000000006, 0.0043656250000000006,
	  0.0043656250000000006, 0.0043656250000000006, 0.0065484375000000004,
	  0.0065484375000000004, 0.0065484375000000004, 0.0065484375000000004,
	  0.0065484375000000004, 0.0065484375000000004, 0.0065484375000000004,
	  0.0065484375000000004, 0.0065484375000000004, 0.0065484375000000004,
	  0.0065484375000000004, 0.0065484375000000004, 0.0065484375000000004,
	  0.0065484375000000004, 0.0065484375000000004, 0.0065484375000000004,
	  0.0065484375000000004, 0.0065484375000000004, 0.0065484375000000004,
	  0.0065484375000000004, 0.0065484375000000004, 0.0065484375000000004,
	  0.0065484375000000004, 0.0065484375000000004, 0.0065484375000000004,
	  0.0065484375000000004, 0.0065484375000000004, 0.0065484375000000004,
	  0.0065484375000000004, 0.0065484375000000004, 0.0065484375000000004,
	  0.0065484375000000004, 0.0065484375000000004, 0.0065484375000000004,
	  0.0065484375000000004, 0.0065484375000000004, 0.0065484375000000004,
	  0.0065484375000000004, 0.0065484375000000004, 0.0065484375000000004,
	  0.0065484375000000004, 0.0065484375000000004, 0.0065484375000000004,
	  0.0065484375000000004, 0.0065484375000000004, 0.0065484375000000004,
	  0.0065484375000000004, 0.0065484375000000004, 0.0065484375000000004,
	  0.0065484375000000004, 0.0065484375000000004, 0.0065484375000000004,
	  0.0065484375000000004, 0.0065484375000000004, 0.0065484375000000004,
	  0.0065484375000000004, 0.0065484375000000004, 0.0065484375000000004,
	  0.0065484375000000004, 0.0065484375000000004, 0.0065484375000000004,
	  0.0065484375000000004, 0.0065484375000000004, 0.0065484375000000004,
	  0.0087312500000000012, 0.0087312500000000012, 0.0087312500000000012,
	  0.0087312500000000012, 0.0087312500000000012, 0.0087312500000000012,
	  0.0087312500000000012, 0.0087312500000000012, 0.0087312500000000012,
	  0.0087312500000000012, 0.0087312500000000012, 0.0087312500000000012,
	  0.0087312500000000012, 0.0087312500000000012, 0.0087312500000000012,
	  0.0087312500000000012, 0.0087312500000000012, 0.0087312500000000012,
	  0.0087312500000000012, 0.0087312500000000012, 0.0087312500000000012,
	  0.0087312500000000012, 0.0087312500000000012, 0.0087312500000000012,
	  0.0087312500000000012, 0.0087312500000000012, 0.0087312500000000012,
	  0.0087312500000000012, 0.0087312500000000012, 0.0087312500000000012,
	  0.0087312500000000012, 0.0087312500000000012, 0.0087312500000000012,
	  0.0087312500000000012, 0.0087312500000000012, 0.0087312500000000012,
	  0.0087312500000000012, 0.0087312500000000012, 0.0087312500000000012,
	  0.0087312500000000012, 0.0087312500000000012, 0.0087312500000000012,
	  0.0087312500000000012, 0.0087312500000000012, 0.0087312500000000012,
	  0.0087312500000000012, 0.0087312500000000012, 0.0087312500000000012,
	  0.0087312500000000012, 0.0087312500000000012, 0.0087312500000000012,
	  0.0087312500000000012, 0.0087312500000000012, 0.0087312500000000012,
	  0.0087312500000000012, 0.0087312500000000012, 0.0087312500000000012,
	  0.0087312500000000012, 0.0087312500000000012, 0.0087312500000000012,
	  0.0087312500000000012, 0.0087312500000000012, 0.0087312500000000012,
	  0.0087312500000000012, 0.0109140625, 0.0109140625, 0.0109140625,
	  0.0109140625, 0.0109140625, 0.0109140625, 0.0109140625, 0.0109140625,
	  0.0109140625, 0.0109140625, 0.0109140625, 0.0109140625, 0.0109140625,
	  0.0109140625, 0.0109140625, 0.0109140625, 0.0109140625, 0.0109140625,
	  0.0109140625, 0.0109140625, 0.0109140625, 0.0109140625, 0.0109140625,
	  0.0109140625, 0.0109140625, 0.0109140625, 0.0109140625, 0.0109140625,
	  0.0109140625, 0.0109140625, 0.0109140625, 0.0109140625, 0.0109140625,
	  0.0109140625, 0.0109140625, 0.0109140625, 0.0109140625, 0.0109140625,
	  0.0109140625, 0.0109140625, 0.0109140625, 0.0109140625, 0.0109140625,
	  0.0109140625, 0.0109140625, 0.0109140625, 0.0109140625, 0.0109140625,
	  0.0109140625, 0.0109140625, 0.0109140625, 0.0109140625, 0.0109140625,
	  0.0109140625, 0.0109140625, 0.0109140625, 0.0109140625, 0.0109140625,
	  0.0109140625, 0.0109140625, 0.0109140625, 0.0109140625, 0.0109140625,
	  0.0109140625, 0.013096875000000001, 0.013096875000000001,
	  0.013096875000000001, 0.013096875000000001, 0.013096875000000001,
	  0.013096875000000001, 0.013096875000000001, 0.013096875000000001,
	  0.013096875000000001, 0.013096875000000001, 0.013096875000000001,
	  0.013096875000000001, 0.013096875000000001, 0.013096875000000001,
	  0.013096875000000001, 0.013096875000000001, 0.013096875000000001,
	  0.013096875000000001, 0.013096875000000001, 0.013096875000000001,
	  0.013096875000000001, 0.013096875000000001, 0.013096875000000001,
	  0.013096875000000001, 0.013096875000000001, 0.013096875000000001,
	  0.013096875000000001, 0.013096875000000001, 0.013096875000000001,
	  0.013096875000000001, 0.013096875000000001, 0.013096875000000001,
	  0.013096875000000001, 0.013096875000000001, 0.013096875000000001,
	  0.013096875000000001, 0.013096875000000001, 0.013096875000000001,
	  0.013096875000000001, 0.013096875000000001, 0.013096875000000001,
	  0.013096875000000001, 0.013096875000000001, 0.013096875000000001,
	  0.013096875000000001, 0.013096875000000001, 0.013096875000000001,
	  0.013096875000000001, 0.013096875000000001, 0.013096875000000001,
	  0.013096875000000001, 0.013096875000000001, 0.013096875000000001,
	  0.013096875000000001, 0.013096875000000001, 0.013096875000000001,
	  0.013096875000000001, 0.013096875000000001, 0.013096875000000001,
	  0.013096875000000001, 0.013096875000000001, 0.013096875000000001,
	  0.013096875000000001, 0.013096875000000001, 0.0152796875, 0.0152796875,
	  0.0152796875, 0.0152796875, 0.0152796875, 0.0152796875, 0.0152796875,
	  0.0152796875, 0.0152796875, 0.0152796875, 0.0152796875, 0.0152796875,
	  0.0152796875, 0.0152796875, 0.0152796875, 0.0152796875, 0.0152796875,
	  0.0152796875, 0.0152796875, 0.0152796875, 0.0152796875, 0.0152796875,
	  0.0152796875, 0.0152796875, 0.0152796875, 0.0152796875, 0.0152796875,
	  0.0152796875, 0.0152796875, 0.0152796875, 0.0152796875, 0.0152796875,
	  0.0152796875, 0.0152796875, 0.0152796875, 0.0152796875, 0.0152796875,
	  0.0152796875, 0.0152796875, 0.0152796875, 0.0152796875, 0.0152796875,
	  0.0152796875, 0.0152796875, 0.0152796875, 0.0152796875, 0.0152796875,
	  0.0152796875, 0.0152796875, 0.0152796875, 0.0152796875, 0.0152796875,
	  0.0152796875, 0.0152796875, 0.0152796875, 0.0152796875, 0.0152796875,
	  0.0152796875, 0.0152796875, 0.0152796875, 0.0152796875, 0.0152796875,
	  0.0152796875, 0.0152796875, 0.017462500000000002, 0.017462500000000002,
	  0.017462500000000002, 0.017462500000000002, 0.017462500000000002,
	  0.017462500000000002, 0.017462500000000002, 0.017462500000000002,
	  0.017462500000000002, 0.017462500000000002, 0.017462500000000002,
	  0.017462500000000002, 0.017462500000000002, 0.017462500000000002,
	  0.017462500000000002, 0.017462500000000002, 0.017462500000000002,
	  0.017462500000000002, 0.017462500000000002, 0.017462500000000002,
	  0.017462500000000002, 0.017462500000000002, 0.017462500000000002,
	  0.017462500000000002, 0.017462500000000002, 0.017462500000000002,
	  0.017462500000000002, 0.017462500000000002, 0.017462500000000002,
	  0.017462500000000002, 0.017462500000000002, 0.017462500000000002,
	  0.017462500000000002, 0.017462500000000002, 0.017462500000000002,
	  0.017462500000000002, 0.017462500000000002, 0.017462500000000002,
	  0.017462500000000002, 0.017462500000000002, 0.017462500000000002,
	  0.017462500000000002, 0.017462500000000002, 0.017462500000000002,
	  0.017462500000000002, 0.017462500000000002, 0.017462500000000002,
	  0.017462500000000002, 0.017462500000000002, 0.017462500000000002,
	  0.017462500000000002, 0.017462500000000002, 0.017462500000000002,
	  0.017462500000000002, 0.017462500000000002, 0.017462500000000002,
	  0.017462500000000002, 0.017462500000000002, 0.017462500000000002,
	  0.017462500000000002, 0.017462500000000002, 0.017462500000000002,
	  0.017462500000000002, 0.017462500000000002, 0.0196453125, 0.0196453125,
	  0.0196453125, 0.0196453125, 0.0196453125, 0.0196453125, 0.0196453125,
	  0.0196453125, 0.0196453125, 0.0196453125, 0.0196453125, 0.0196453125,
	  0.0196453125, 0.0196453125, 0.0196453125, 0.0196453125, 0.0196453125,
	  0.0196453125, 0.0196453125, 0.0196453125, 0.0196453125, 0.0196453125,
	  0.0196453125, 0.0196453125, 0.0196453125, 0.0196453125, 0.0196453125,
	  0.0196453125, 0.0196453125, 0.0196453125, 0.0196453125, 0.0196453125,
	  0.0196453125, 0.0196453125, 0.0196453125, 0.0196453125, 0.0196453125,
	  0.0196453125, 0.0196453125, 0.0196453125, 0.0196453125, 0.0196453125,
	  0.0196453125, 0.0196453125, 0.0196453125, 0.0196453125, 0.0196453125,
	  0.0196453125, 0.0196453125, 0.0196453125, 0.0196453125, 0.0196453125,
	  0.0196453125, 0.0196453125, 0.0196453125, 0.0196453125, 0.0196453125,
	  0.0196453125, 0.0196453125, 0.0196453125, 0.0196453125, 0.0196453125,
	  0.0196453125, 0.0196453125, 0.021828125, 0.021828125, 0.021828125,
	  0.021828125, 0.021828125, 0.021828125, 0.021828125, 0.021828125, 0.021828125,
	  0.021828125, 0.021828125, 0.021828125, 0.021828125, 0.021828125, 0.021828125,
	  0.021828125, 0.021828125, 0.021828125, 0.021828125, 0.021828125, 0.021828125,
	  0.021828125, 0.021828125, 0.021828125, 0.021828125, 0.021828125, 0.021828125,
	  0.021828125, 0.021828125, 0.021828125, 0.021828125, 0.021828125, 0.021828125,
	  0.021828125, 0.021828125, 0.021828125, 0.021828125, 0.021828125, 0.021828125,
	  0.021828125, 0.021828125, 0.021828125, 0.021828125, 0.021828125, 0.021828125,
	  0.021828125, 0.021828125, 0.021828125, 0.021828125, 0.021828125, 0.021828125,
	  0.021828125, 0.021828125, 0.021828125, 0.021828125, 0.021828125, 0.021828125,
	  0.021828125, 0.021828125, 0.021828125, 0.021828125, 0.021828125, 0.021828125,
	  0.021828125, 0.024010937500000003, 0.024010937500000003,
	  0.024010937500000003, 0.024010937500000003, 0.024010937500000003,
	  0.024010937500000003, 0.024010937500000003, 0.024010937500000003,
	  0.024010937500000003, 0.024010937500000003, 0.024010937500000003,
	  0.024010937500000003, 0.024010937500000003, 0.024010937500000003,
	  0.024010937500000003, 0.024010937500000003, 0.024010937500000003,
	  0.024010937500000003, 0.024010937500000003, 0.024010937500000003,
	  0.024010937500000003, 0.024010937500000003, 0.024010937500000003,
	  0.024010937500000003, 0.024010937500000003, 0.024010937500000003,
	  0.024010937500000003, 0.024010937500000003, 0.024010937500000003,
	  0.024010937500000003, 0.024010937500000003, 0.024010937500000003,
	  0.024010937500000003, 0.024010937500000003, 0.024010937500000003,
	  0.024010937500000003, 0.024010937500000003, 0.024010937500000003,
	  0.024010937500000003, 0.024010937500000003, 0.024010937500000003,
	  0.024010937500000003, 0.024010937500000003, 0.024010937500000003,
	  0.024010937500000003, 0.024010937500000003, 0.024010937500000003,
	  0.024010937500000003, 0.024010937500000003, 0.024010937500000003,
	  0.024010937500000003, 0.024010937500000003, 0.024010937500000003,
	  0.024010937500000003, 0.024010937500000003, 0.024010937500000003,
	  0.024010937500000003, 0.024010937500000003, 0.024010937500000003,
	  0.024010937500000003, 0.024010937500000003, 0.024010937500000003,
	  0.024010937500000003, 0.024010937500000003, 0.026193750000000002,
	  0.026193750000000002, 0.026193750000000002, 0.026193750000000002,
	  0.026193750000000002, 0.026193750000000002, 0.026193750000000002,
	  0.026193750000000002, 0.026193750000000002, 0.026193750000000002,
	  0.026193750000000002, 0.026193750000000002, 0.026193750000000002,
	  0.026193750000000002, 0.026193750000000002, 0.026193750000000002,
	  0.026193750000000002, 0.026193750000000002, 0.026193750000000002,
	  0.026193750000000002, 0.026193750000000002, 0.026193750000000002,
	  0.026193750000000002, 0.026193750000000002, 0.026193750000000002,
	  0.026193750000000002, 0.026193750000000002, 0.026193750000000002,
	  0.026193750000000002, 0.026193750000000002, 0.026193750000000002,
	  0.026193750000000002, 0.026193750000000002, 0.026193750000000002,
	  0.026193750000000002, 0.026193750000000002, 0.026193750000000002,
	  0.026193750000000002, 0.026193750000000002, 0.026193750000000002,
	  0.026193750000000002, 0.026193750000000002, 0.026193750000000002,
	  0.026193750000000002, 0.026193750000000002, 0.026193750000000002,
	  0.026193750000000002, 0.026193750000000002, 0.026193750000000002,
	  0.026193750000000002, 0.026193750000000002, 0.026193750000000002,
	  0.026193750000000002, 0.026193750000000002, 0.026193750000000002,
	  0.026193750000000002, 0.026193750000000002, 0.026193750000000002,
	  0.026193750000000002, 0.026193750000000002, 0.026193750000000002,
	  0.026193750000000002, 0.026193750000000002, 0.026193750000000002,
	  0.0283765625, 0.0283765625, 0.0283765625, 0.0283765625, 0.0283765625,
	  0.0283765625, 0.0283765625, 0.0283765625, 0.0283765625, 0.0283765625,
	  0.0283765625, 0.0283765625, 0.0283765625, 0.0283765625, 0.0283765625,
	  0.0283765625, 0.0283765625, 0.0283765625, 0.0283765625, 0.0283765625,
	  0.0283765625, 0.0283765625, 0.0283765625, 0.0283765625, 0.0283765625,
	  0.0283765625, 0.0283765625, 0.0283765625, 0.0283765625, 0.0283765625,
	  0.0283765625, 0.0283765625, 0.0283765625, 0.0283765625, 0.0283765625,
	  0.0283765625, 0.0283765625, 0.0283765625, 0.0283765625, 0.0283765625,
	  0.0283765625, 0.0283765625, 0.0283765625, 0.0283765625, 0.0283765625,
	  0.0283765625, 0.0283765625, 0.0283765625, 0.0283765625, 0.0283765625,
	  0.0283765625, 0.0283765625, 0.0283765625, 0.0283765625, 0.0283765625,
	  0.0283765625, 0.0283765625, 0.0283765625, 0.0283765625, 0.0283765625,
	  0.0283765625, 0.0283765625, 0.0283765625, 0.0283765625, 0.030559375,
	  0.030559375, 0.030559375, 0.030559375, 0.030559375, 0.030559375, 0.030559375,
	  0.030559375, 0.030559375, 0.030559375, 0.030559375, 0.030559375, 0.030559375,
	  0.030559375, 0.030559375, 0.030559375, 0.030559375, 0.030559375, 0.030559375,
	  0.030559375, 0.030559375, 0.030559375, 0.030559375, 0.030559375, 0.030559375,
	  0.030559375, 0.030559375, 0.030559375, 0.030559375, 0.030559375, 0.030559375,
	  0.030559375, 0.030559375, 0.030559375, 0.030559375, 0.030559375, 0.030559375,
	  0.030559375, 0.030559375, 0.030559375, 0.030559375, 0.030559375, 0.030559375,
	  0.030559375, 0.030559375, 0.030559375, 0.030559375, 0.030559375, 0.030559375,
	  0.030559375, 0.030559375, 0.030559375, 0.030559375, 0.030559375, 0.030559375,
	  0.030559375, 0.030559375, 0.030559375, 0.030559375, 0.030559375, 0.030559375,
	  0.030559375, 0.030559375, 0.030559375, 0.0327421875, 0.0327421875,
	  0.0327421875, 0.0327421875, 0.0327421875, 0.0327421875, 0.0327421875,
	  0.0327421875, 0.0327421875, 0.0327421875, 0.0327421875, 0.0327421875,
	  0.0327421875, 0.0327421875, 0.0327421875, 0.0327421875, 0.0327421875,
	  0.0327421875, 0.0327421875, 0.0327421875, 0.0327421875, 0.0327421875,
	  0.0327421875, 0.0327421875, 0.0327421875, 0.0327421875, 0.0327421875,
	  0.0327421875, 0.0327421875, 0.0327421875, 0.0327421875, 0.0327421875,
	  0.0327421875, 0.0327421875, 0.0327421875, 0.0327421875, 0.0327421875,
	  0.0327421875, 0.0327421875, 0.0327421875, 0.0327421875, 0.0327421875,
	  0.0327421875, 0.0327421875, 0.0327421875, 0.0327421875, 0.0327421875,
	  0.0327421875, 0.0327421875, 0.0327421875, 0.0327421875, 0.0327421875,
	  0.0327421875, 0.0327421875, 0.0327421875, 0.0327421875, 0.0327421875,
	  0.0327421875, 0.0327421875, 0.0327421875, 0.0327421875, 0.0327421875,
	  0.0327421875, 0.0327421875, 0.034925000000000005, 0.034925000000000005,
	  0.034925000000000005, 0.034925000000000005, 0.034925000000000005,
	  0.034925000000000005, 0.034925000000000005, 0.034925000000000005,
	  0.034925000000000005, 0.034925000000000005, 0.034925000000000005,
	  0.034925000000000005, 0.034925000000000005, 0.034925000000000005,
	  0.034925000000000005, 0.034925000000000005, 0.034925000000000005,
	  0.034925000000000005, 0.034925000000000005, 0.034925000000000005,
	  0.034925000000000005, 0.034925000000000005, 0.034925000000000005,
	  0.034925000000000005, 0.034925000000000005, 0.034925000000000005,
	  0.034925000000000005, 0.034925000000000005, 0.034925000000000005,
	  0.034925000000000005, 0.034925000000000005, 0.034925000000000005,
	  0.034925000000000005, 0.034925000000000005, 0.034925000000000005,
	  0.034925000000000005, 0.034925000000000005, 0.034925000000000005,
	  0.034925000000000005, 0.034925000000000005, 0.034925000000000005,
	  0.034925000000000005, 0.034925000000000005, 0.034925000000000005,
	  0.034925000000000005, 0.034925000000000005, 0.034925000000000005,
	  0.034925000000000005, 0.034925000000000005, 0.034925000000000005,
	  0.034925000000000005, 0.034925000000000005, 0.034925000000000005,
	  0.034925000000000005, 0.034925000000000005, 0.034925000000000005,
	  0.034925000000000005, 0.034925000000000005, 0.034925000000000005,
	  0.034925000000000005, 0.034925000000000005, 0.034925000000000005,
	  0.034925000000000005, 0.034925000000000005, 0.0371078125, 0.0371078125,
	  0.0371078125, 0.0371078125, 0.0371078125, 0.0371078125, 0.0371078125,
	  0.0371078125, 0.0371078125, 0.0371078125, 0.0371078125, 0.0371078125,
	  0.0371078125, 0.0371078125, 0.0371078125, 0.0371078125, 0.0371078125,
	  0.0371078125, 0.0371078125, 0.0371078125, 0.0371078125, 0.0371078125,
	  0.0371078125, 0.0371078125, 0.0371078125, 0.0371078125, 0.0371078125,
	  0.0371078125, 0.0371078125, 0.0371078125, 0.0371078125, 0.0371078125,
	  0.0371078125, 0.0371078125, 0.0371078125, 0.0371078125, 0.0371078125,
	  0.0371078125, 0.0371078125, 0.0371078125, 0.0371078125, 0.0371078125,
	  0.0371078125, 0.0371078125, 0.0371078125, 0.0371078125, 0.0371078125,
	  0.0371078125, 0.0371078125, 0.0371078125, 0.0371078125, 0.0371078125,
	  0.0371078125, 0.0371078125, 0.0371078125, 0.0371078125, 0.0371078125,
	  0.0371078125, 0.0371078125, 0.0371078125, 0.0371078125, 0.0371078125,
	  0.0371078125, 0.0371078125, 0.039290625, 0.039290625, 0.039290625,
	  0.039290625, 0.039290625, 0.039290625, 0.039290625, 0.039290625, 0.039290625,
	  0.039290625, 0.039290625, 0.039290625, 0.039290625, 0.039290625, 0.039290625,
	  0.039290625, 0.039290625, 0.039290625, 0.039290625, 0.039290625, 0.039290625,
	  0.039290625, 0.039290625, 0.039290625, 0.039290625, 0.039290625, 0.039290625,
	  0.039290625, 0.039290625, 0.039290625, 0.039290625, 0.039290625, 0.039290625,
	  0.039290625, 0.039290625, 0.039290625, 0.039290625, 0.039290625, 0.039290625,
	  0.039290625, 0.039290625, 0.039290625, 0.039290625, 0.039290625, 0.039290625,
	  0.039290625, 0.039290625, 0.039290625, 0.039290625, 0.039290625, 0.039290625,
	  0.039290625, 0.039290625, 0.039290625, 0.039290625, 0.039290625, 0.039290625,
	  0.039290625, 0.039290625, 0.039290625, 0.039290625, 0.039290625, 0.039290625,
	  0.039290625, 0.0414734375, 0.0414734375, 0.0414734375, 0.0414734375,
	  0.0414734375, 0.0414734375, 0.0414734375, 0.0414734375, 0.0414734375,
	  0.0414734375, 0.0414734375, 0.0414734375, 0.0414734375, 0.0414734375,
	  0.0414734375, 0.0414734375, 0.0414734375, 0.0414734375, 0.0414734375,
	  0.0414734375, 0.0414734375, 0.0414734375, 0.0414734375, 0.0414734375,
	  0.0414734375, 0.0414734375, 0.0414734375, 0.0414734375, 0.0414734375,
	  0.0414734375, 0.0414734375, 0.0414734375, 0.0414734375, 0.0414734375,
	  0.0414734375, 0.0414734375, 0.0414734375, 0.0414734375, 0.0414734375,
	  0.0414734375, 0.0414734375, 0.0414734375, 0.0414734375, 0.0414734375,
	  0.0414734375, 0.0414734375, 0.0414734375, 0.0414734375, 0.0414734375,
	  0.0414734375, 0.0414734375, 0.0414734375, 0.0414734375, 0.0414734375,
	  0.0414734375, 0.0414734375, 0.0414734375, 0.0414734375, 0.0414734375,
	  0.0414734375, 0.0414734375, 0.0414734375, 0.0414734375, 0.0414734375,
	  0.04365625, 0.04365625, 0.04365625, 0.04365625, 0.04365625, 0.04365625,
	  0.04365625, 0.04365625, 0.04365625, 0.04365625, 0.04365625, 0.04365625,
	  0.04365625, 0.04365625, 0.04365625, 0.04365625, 0.04365625, 0.04365625,
	  0.04365625, 0.04365625, 0.04365625, 0.04365625, 0.04365625, 0.04365625,
	  0.04365625, 0.04365625, 0.04365625, 0.04365625, 0.04365625, 0.04365625,
	  0.04365625, 0.04365625, 0.04365625, 0.04365625, 0.04365625, 0.04365625,
	  0.04365625, 0.04365625, 0.04365625, 0.04365625, 0.04365625, 0.04365625,
	  0.04365625, 0.04365625, 0.04365625, 0.04365625, 0.04365625, 0.04365625,
	  0.04365625, 0.04365625, 0.04365625, 0.04365625, 0.04365625, 0.04365625,
	  0.04365625, 0.04365625, 0.04365625, 0.04365625, 0.04365625, 0.04365625,
	  0.04365625, 0.04365625, 0.04365625, 0.04365625, 0.045839062500000007,
	  0.045839062500000007, 0.045839062500000007, 0.045839062500000007,
	  0.045839062500000007, 0.045839062500000007, 0.045839062500000007,
	  0.045839062500000007, 0.045839062500000007, 0.045839062500000007,
	  0.045839062500000007, 0.045839062500000007, 0.045839062500000007,
	  0.045839062500000007, 0.045839062500000007, 0.045839062500000007,
	  0.045839062500000007, 0.045839062500000007, 0.045839062500000007,
	  0.045839062500000007, 0.045839062500000007, 0.045839062500000007,
	  0.045839062500000007, 0.045839062500000007, 0.045839062500000007,
	  0.045839062500000007, 0.045839062500000007, 0.045839062500000007,
	  0.045839062500000007, 0.045839062500000007, 0.045839062500000007,
	  0.045839062500000007, 0.045839062500000007, 0.045839062500000007,
	  0.045839062500000007, 0.045839062500000007, 0.045839062500000007,
	  0.045839062500000007, 0.045839062500000007, 0.045839062500000007,
	  0.045839062500000007, 0.045839062500000007, 0.045839062500000007,
	  0.045839062500000007, 0.045839062500000007, 0.045839062500000007,
	  0.045839062500000007, 0.045839062500000007, 0.045839062500000007,
	  0.045839062500000007, 0.045839062500000007, 0.045839062500000007,
	  0.045839062500000007, 0.045839062500000007, 0.045839062500000007,
	  0.045839062500000007, 0.045839062500000007, 0.045839062500000007,
	  0.045839062500000007, 0.045839062500000007, 0.045839062500000007,
	  0.045839062500000007, 0.045839062500000007, 0.045839062500000007,
	  0.048021875000000006, 0.048021875000000006, 0.048021875000000006,
	  0.048021875000000006, 0.048021875000000006, 0.048021875000000006,
	  0.048021875000000006, 0.048021875000000006, 0.048021875000000006,
	  0.048021875000000006, 0.048021875000000006, 0.048021875000000006,
	  0.048021875000000006, 0.048021875000000006, 0.048021875000000006,
	  0.048021875000000006, 0.048021875000000006, 0.048021875000000006,
	  0.048021875000000006, 0.048021875000000006, 0.048021875000000006,
	  0.048021875000000006, 0.048021875000000006, 0.048021875000000006,
	  0.048021875000000006, 0.048021875000000006, 0.048021875000000006,
	  0.048021875000000006, 0.048021875000000006, 0.048021875000000006,
	  0.048021875000000006, 0.048021875000000006, 0.048021875000000006,
	  0.048021875000000006, 0.048021875000000006, 0.048021875000000006,
	  0.048021875000000006, 0.048021875000000006, 0.048021875000000006,
	  0.048021875000000006, 0.048021875000000006, 0.048021875000000006,
	  0.048021875000000006, 0.048021875000000006, 0.048021875000000006,
	  0.048021875000000006, 0.048021875000000006, 0.048021875000000006,
	  0.048021875000000006, 0.048021875000000006, 0.048021875000000006,
	  0.048021875000000006, 0.048021875000000006, 0.048021875000000006,
	  0.048021875000000006, 0.048021875000000006, 0.048021875000000006,
	  0.048021875000000006, 0.048021875000000006, 0.048021875000000006,
	  0.048021875000000006, 0.048021875000000006, 0.048021875000000006,
	  0.048021875000000006, 0.050204687500000005, 0.050204687500000005,
	  0.050204687500000005, 0.050204687500000005, 0.050204687500000005,
	  0.050204687500000005, 0.050204687500000005, 0.050204687500000005,
	  0.050204687500000005, 0.050204687500000005, 0.050204687500000005,
	  0.050204687500000005, 0.050204687500000005, 0.050204687500000005,
	  0.050204687500000005, 0.050204687500000005, 0.050204687500000005,
	  0.050204687500000005, 0.050204687500000005, 0.050204687500000005,
	  0.050204687500000005, 0.050204687500000005, 0.050204687500000005,
	  0.050204687500000005, 0.050204687500000005, 0.050204687500000005,
	  0.050204687500000005, 0.050204687500000005, 0.050204687500000005,
	  0.050204687500000005, 0.050204687500000005, 0.050204687500000005,
	  0.050204687500000005, 0.050204687500000005, 0.050204687500000005,
	  0.050204687500000005, 0.050204687500000005, 0.050204687500000005,
	  0.050204687500000005, 0.050204687500000005, 0.050204687500000005,
	  0.050204687500000005, 0.050204687500000005, 0.050204687500000005,
	  0.050204687500000005, 0.050204687500000005, 0.050204687500000005,
	  0.050204687500000005, 0.050204687500000005, 0.050204687500000005,
	  0.050204687500000005, 0.050204687500000005, 0.050204687500000005,
	  0.050204687500000005, 0.050204687500000005, 0.050204687500000005,
	  0.050204687500000005, 0.050204687500000005, 0.050204687500000005,
	  0.050204687500000005, 0.050204687500000005, 0.050204687500000005,
	  0.050204687500000005, 0.050204687500000005, 0.052387500000000004,
	  0.052387500000000004, 0.052387500000000004, 0.052387500000000004,
	  0.052387500000000004, 0.052387500000000004, 0.052387500000000004,
	  0.052387500000000004, 0.052387500000000004, 0.052387500000000004,
	  0.052387500000000004, 0.052387500000000004, 0.052387500000000004,
	  0.052387500000000004, 0.052387500000000004, 0.052387500000000004,
	  0.052387500000000004, 0.052387500000000004, 0.052387500000000004,
	  0.052387500000000004, 0.052387500000000004, 0.052387500000000004,
	  0.052387500000000004, 0.052387500000000004, 0.052387500000000004,
	  0.052387500000000004, 0.052387500000000004, 0.052387500000000004,
	  0.052387500000000004, 0.052387500000000004, 0.052387500000000004,
	  0.052387500000000004, 0.052387500000000004, 0.052387500000000004,
	  0.052387500000000004, 0.052387500000000004, 0.052387500000000004,
	  0.052387500000000004, 0.052387500000000004, 0.052387500000000004,
	  0.052387500000000004, 0.052387500000000004, 0.052387500000000004,
	  0.052387500000000004, 0.052387500000000004, 0.052387500000000004,
	  0.052387500000000004, 0.052387500000000004, 0.052387500000000004,
	  0.052387500000000004, 0.052387500000000004, 0.052387500000000004,
	  0.052387500000000004, 0.052387500000000004, 0.052387500000000004,
	  0.052387500000000004, 0.052387500000000004, 0.052387500000000004,
	  0.052387500000000004, 0.052387500000000004, 0.052387500000000004,
	  0.052387500000000004, 0.052387500000000004, 0.052387500000000004,
	  0.0545703125, 0.0545703125, 0.0545703125, 0.0545703125, 0.0545703125,
	  0.0545703125, 0.0545703125, 0.0545703125, 0.0545703125, 0.0545703125,
	  0.0545703125, 0.0545703125, 0.0545703125, 0.0545703125, 0.0545703125,
	  0.0545703125, 0.0545703125, 0.0545703125, 0.0545703125, 0.0545703125,
	  0.0545703125, 0.0545703125, 0.0545703125, 0.0545703125, 0.0545703125,
	  0.0545703125, 0.0545703125, 0.0545703125, 0.0545703125, 0.0545703125,
	  0.0545703125, 0.0545703125, 0.0545703125, 0.0545703125, 0.0545703125,
	  0.0545703125, 0.0545703125, 0.0545703125, 0.0545703125, 0.0545703125,
	  0.0545703125, 0.0545703125, 0.0545703125, 0.0545703125, 0.0545703125,
	  0.0545703125, 0.0545703125, 0.0545703125, 0.0545703125, 0.0545703125,
	  0.0545703125, 0.0545703125, 0.0545703125, 0.0545703125, 0.0545703125,
	  0.0545703125, 0.0545703125, 0.0545703125, 0.0545703125, 0.0545703125,
	  0.0545703125, 0.0545703125, 0.0545703125, 0.0545703125, 0.056753125,
	  0.056753125, 0.056753125, 0.056753125, 0.056753125, 0.056753125, 0.056753125,
	  0.056753125, 0.056753125, 0.056753125, 0.056753125, 0.056753125, 0.056753125,
	  0.056753125, 0.056753125, 0.056753125, 0.056753125, 0.056753125, 0.056753125,
	  0.056753125, 0.056753125, 0.056753125, 0.056753125, 0.056753125, 0.056753125,
	  0.056753125, 0.056753125, 0.056753125, 0.056753125, 0.056753125, 0.056753125,
	  0.056753125, 0.056753125, 0.056753125, 0.056753125, 0.056753125, 0.056753125,
	  0.056753125, 0.056753125, 0.056753125, 0.056753125, 0.056753125, 0.056753125,
	  0.056753125, 0.056753125, 0.056753125, 0.056753125, 0.056753125, 0.056753125,
	  0.056753125, 0.056753125, 0.056753125, 0.056753125, 0.056753125, 0.056753125,
	  0.056753125, 0.056753125, 0.056753125, 0.056753125, 0.056753125, 0.056753125,
	  0.056753125, 0.056753125, 0.056753125, 0.058935937500000007,
	  0.058935937500000007, 0.058935937500000007, 0.058935937500000007,
	  0.058935937500000007, 0.058935937500000007, 0.058935937500000007,
	  0.058935937500000007, 0.058935937500000007, 0.058935937500000007,
	  0.058935937500000007, 0.058935937500000007, 0.058935937500000007,
	  0.058935937500000007, 0.058935937500000007, 0.058935937500000007,
	  0.058935937500000007, 0.058935937500000007, 0.058935937500000007,
	  0.058935937500000007, 0.058935937500000007, 0.058935937500000007,
	  0.058935937500000007, 0.058935937500000007, 0.058935937500000007,
	  0.058935937500000007, 0.058935937500000007, 0.058935937500000007,
	  0.058935937500000007, 0.058935937500000007, 0.058935937500000007,
	  0.058935937500000007, 0.058935937500000007, 0.058935937500000007,
	  0.058935937500000007, 0.058935937500000007, 0.058935937500000007,
	  0.058935937500000007, 0.058935937500000007, 0.058935937500000007,
	  0.058935937500000007, 0.058935937500000007, 0.058935937500000007,
	  0.058935937500000007, 0.058935937500000007, 0.058935937500000007,
	  0.058935937500000007, 0.058935937500000007, 0.058935937500000007,
	  0.058935937500000007, 0.058935937500000007, 0.058935937500000007,
	  0.058935937500000007, 0.058935937500000007, 0.058935937500000007,
	  0.058935937500000007, 0.058935937500000007, 0.058935937500000007,
	  0.058935937500000007, 0.058935937500000007, 0.058935937500000007,
	  0.058935937500000007, 0.058935937500000007, 0.058935937500000007, 0.06111875,
	  0.06111875, 0.06111875, 0.06111875, 0.06111875, 0.06111875, 0.06111875,
	  0.06111875, 0.06111875, 0.06111875, 0.06111875, 0.06111875, 0.06111875,
	  0.06111875, 0.06111875, 0.06111875, 0.06111875, 0.06111875, 0.06111875,
	  0.06111875, 0.06111875, 0.06111875, 0.06111875, 0.06111875, 0.06111875,
	  0.06111875, 0.06111875, 0.06111875, 0.06111875, 0.06111875, 0.06111875,
	  0.06111875, 0.06111875, 0.06111875, 0.06111875, 0.06111875, 0.06111875,
	  0.06111875, 0.06111875, 0.06111875, 0.06111875, 0.06111875, 0.06111875,
	  0.06111875, 0.06111875, 0.06111875, 0.06111875, 0.06111875, 0.06111875,
	  0.06111875, 0.06111875, 0.06111875, 0.06111875, 0.06111875, 0.06111875,
	  0.06111875, 0.06111875, 0.06111875, 0.06111875, 0.06111875, 0.06111875,
	  0.06111875, 0.06111875, 0.06111875, 0.0633015625, 0.0633015625, 0.0633015625,
	  0.0633015625, 0.0633015625, 0.0633015625, 0.0633015625, 0.0633015625,
	  0.0633015625, 0.0633015625, 0.0633015625, 0.0633015625, 0.0633015625,
	  0.0633015625, 0.0633015625, 0.0633015625, 0.0633015625, 0.0633015625,
	  0.0633015625, 0.0633015625, 0.0633015625, 0.0633015625, 0.0633015625,
	  0.0633015625, 0.0633015625, 0.0633015625, 0.0633015625, 0.0633015625,
	  0.0633015625, 0.0633015625, 0.0633015625, 0.0633015625, 0.0633015625,
	  0.0633015625, 0.0633015625, 0.0633015625, 0.0633015625, 0.0633015625,
	  0.0633015625, 0.0633015625, 0.0633015625, 0.0633015625, 0.0633015625,
	  0.0633015625, 0.0633015625, 0.0633015625, 0.0633015625, 0.0633015625,
	  0.0633015625, 0.0633015625, 0.0633015625, 0.0633015625, 0.0633015625,
	  0.0633015625, 0.0633015625, 0.0633015625, 0.0633015625, 0.0633015625,
	  0.0633015625, 0.0633015625, 0.0633015625, 0.0633015625, 0.0633015625,
	  0.0633015625, 0.065484375, 0.065484375, 0.065484375, 0.065484375,
	  0.065484375, 0.065484375, 0.065484375, 0.065484375, 0.065484375, 0.065484375,
	  0.065484375, 0.065484375, 0.065484375, 0.065484375, 0.065484375, 0.065484375,
	  0.065484375, 0.065484375, 0.065484375, 0.065484375, 0.065484375, 0.065484375,
	  0.065484375, 0.065484375, 0.065484375, 0.065484375, 0.065484375, 0.065484375,
	  0.065484375, 0.065484375, 0.065484375, 0.065484375, 0.065484375, 0.065484375,
	  0.065484375, 0.065484375, 0.065484375, 0.065484375, 0.065484375, 0.065484375,
	  0.065484375, 0.065484375, 0.065484375, 0.065484375, 0.065484375, 0.065484375,
	  0.065484375, 0.065484375, 0.065484375, 0.065484375, 0.065484375, 0.065484375,
	  0.065484375, 0.065484375, 0.065484375, 0.065484375, 0.065484375, 0.065484375,
	  0.065484375, 0.065484375, 0.065484375, 0.065484375, 0.065484375, 0.065484375,
	  0.0676671875, 0.0676671875, 0.0676671875, 0.0676671875, 0.0676671875,
	  0.0676671875, 0.0676671875, 0.0676671875, 0.0676671875, 0.0676671875,
	  0.0676671875, 0.0676671875, 0.0676671875, 0.0676671875, 0.0676671875,
	  0.0676671875, 0.0676671875, 0.0676671875, 0.0676671875, 0.0676671875,
	  0.0676671875, 0.0676671875, 0.0676671875, 0.0676671875, 0.0676671875,
	  0.0676671875, 0.0676671875, 0.0676671875, 0.0676671875, 0.0676671875,
	  0.0676671875, 0.0676671875, 0.0676671875, 0.0676671875, 0.0676671875,
	  0.0676671875, 0.0676671875, 0.0676671875, 0.0676671875, 0.0676671875,
	  0.0676671875, 0.0676671875, 0.0676671875, 0.0676671875, 0.0676671875,
	  0.0676671875, 0.0676671875, 0.0676671875, 0.0676671875, 0.0676671875,
	  0.0676671875, 0.0676671875, 0.0676671875, 0.0676671875, 0.0676671875,
	  0.0676671875, 0.0676671875, 0.0676671875, 0.0676671875, 0.0676671875,
	  0.0676671875, 0.0676671875, 0.0676671875, 0.0676671875 };

	static const double dv1[4096] = { -0.069850000000000009, -0.0676671875,
	  -0.065484375, -0.0633015625, -0.06111875, -0.058935937500000007,
	  -0.056753125, -0.0545703125, -0.052387500000000004, -0.050204687500000005,
	  -0.048021875000000006, -0.045839062500000007, -0.04365625, -0.0414734375,
	  -0.039290625, -0.0371078125, -0.034925000000000005, -0.0327421875,
	  -0.030559375, -0.0283765625, -0.026193750000000002, -0.024010937500000003,
	  -0.021828125, -0.0196453125, -0.017462500000000002, -0.0152796875,
	  -0.013096875000000001, -0.0109140625, -0.0087312500000000012,
	  -0.0065484375000000004, -0.0043656250000000006, -0.0021828125000000003, 0.0,
	  0.0021828125000000003, 0.0043656250000000006, 0.0065484375000000004,
	  0.0087312500000000012, 0.0109140625, 0.013096875000000001, 0.0152796875,
	  0.017462500000000002, 0.0196453125, 0.021828125, 0.024010937500000003,
	  0.026193750000000002, 0.0283765625, 0.030559375, 0.0327421875,
	  0.034925000000000005, 0.0371078125, 0.039290625, 0.0414734375, 0.04365625,
	  0.045839062500000007, 0.048021875000000006, 0.050204687500000005,
	  0.052387500000000004, 0.0545703125, 0.056753125, 0.058935937500000007,
	  0.06111875, 0.0633015625, 0.065484375, 0.0676671875, -0.069850000000000009,
	  -0.0676671875, -0.065484375, -0.0633015625, -0.06111875,
	  -0.058935937500000007, -0.056753125, -0.0545703125, -0.052387500000000004,
	  -0.050204687500000005, -0.048021875000000006, -0.045839062500000007,
	  -0.04365625, -0.0414734375, -0.039290625, -0.0371078125,
	  -0.034925000000000005, -0.0327421875, -0.030559375, -0.0283765625,
	  -0.026193750000000002, -0.024010937500000003, -0.021828125, -0.0196453125,
	  -0.017462500000000002, -0.0152796875, -0.013096875000000001, -0.0109140625,
	  -0.0087312500000000012, -0.0065484375000000004, -0.0043656250000000006,
	  -0.0021828125000000003, 0.0, 0.0021828125000000003, 0.0043656250000000006,
	  0.0065484375000000004, 0.0087312500000000012, 0.0109140625,
	  0.013096875000000001, 0.0152796875, 0.017462500000000002, 0.0196453125,
	  0.021828125, 0.024010937500000003, 0.026193750000000002, 0.0283765625,
	  0.030559375, 0.0327421875, 0.034925000000000005, 0.0371078125, 0.039290625,
	  0.0414734375, 0.04365625, 0.045839062500000007, 0.048021875000000006,
	  0.050204687500000005, 0.052387500000000004, 0.0545703125, 0.056753125,
	  0.058935937500000007, 0.06111875, 0.0633015625, 0.065484375, 0.0676671875,
	  -0.069850000000000009, -0.0676671875, -0.065484375, -0.0633015625,
	  -0.06111875, -0.058935937500000007, -0.056753125, -0.0545703125,
	  -0.052387500000000004, -0.050204687500000005, -0.048021875000000006,
	  -0.045839062500000007, -0.04365625, -0.0414734375, -0.039290625,
	  -0.0371078125, -0.034925000000000005, -0.0327421875, -0.030559375,
	  -0.0283765625, -0.026193750000000002, -0.024010937500000003, -0.021828125,
	  -0.0196453125, -0.017462500000000002, -0.0152796875, -0.013096875000000001,
	  -0.0109140625, -0.0087312500000000012, -0.0065484375000000004,
	  -0.0043656250000000006, -0.0021828125000000003, 0.0, 0.0021828125000000003,
	  0.0043656250000000006, 0.0065484375000000004, 0.0087312500000000012,
	  0.0109140625, 0.013096875000000001, 0.0152796875, 0.017462500000000002,
	  0.0196453125, 0.021828125, 0.024010937500000003, 0.026193750000000002,
	  0.0283765625, 0.030559375, 0.0327421875, 0.034925000000000005, 0.0371078125,
	  0.039290625, 0.0414734375, 0.04365625, 0.045839062500000007,
	  0.048021875000000006, 0.050204687500000005, 0.052387500000000004,
	  0.0545703125, 0.056753125, 0.058935937500000007, 0.06111875, 0.0633015625,
	  0.065484375, 0.0676671875, -0.069850000000000009, -0.0676671875,
	  -0.065484375, -0.0633015625, -0.06111875, -0.058935937500000007,
	  -0.056753125, -0.0545703125, -0.052387500000000004, -0.050204687500000005,
	  -0.048021875000000006, -0.045839062500000007, -0.04365625, -0.0414734375,
	  -0.039290625, -0.0371078125, -0.034925000000000005, -0.0327421875,
	  -0.030559375, -0.0283765625, -0.026193750000000002, -0.024010937500000003,
	  -0.021828125, -0.0196453125, -0.017462500000000002, -0.0152796875,
	  -0.013096875000000001, -0.0109140625, -0.0087312500000000012,
	  -0.0065484375000000004, -0.0043656250000000006, -0.0021828125000000003, 0.0,
	  0.0021828125000000003, 0.0043656250000000006, 0.0065484375000000004,
	  0.0087312500000000012, 0.0109140625, 0.013096875000000001, 0.0152796875,
	  0.017462500000000002, 0.0196453125, 0.021828125, 0.024010937500000003,
	  0.026193750000000002, 0.0283765625, 0.030559375, 0.0327421875,
	  0.034925000000000005, 0.0371078125, 0.039290625, 0.0414734375, 0.04365625,
	  0.045839062500000007, 0.048021875000000006, 0.050204687500000005,
	  0.052387500000000004, 0.0545703125, 0.056753125, 0.058935937500000007,
	  0.06111875, 0.0633015625, 0.065484375, 0.0676671875, -0.069850000000000009,
	  -0.0676671875, -0.065484375, -0.0633015625, -0.06111875,
	  -0.058935937500000007, -0.056753125, -0.0545703125, -0.052387500000000004,
	  -0.050204687500000005, -0.048021875000000006, -0.045839062500000007,
	  -0.04365625, -0.0414734375, -0.039290625, -0.0371078125,
	  -0.034925000000000005, -0.0327421875, -0.030559375, -0.0283765625,
	  -0.026193750000000002, -0.024010937500000003, -0.021828125, -0.0196453125,
	  -0.017462500000000002, -0.0152796875, -0.013096875000000001, -0.0109140625,
	  -0.0087312500000000012, -0.0065484375000000004, -0.0043656250000000006,
	  -0.0021828125000000003, 0.0, 0.0021828125000000003, 0.0043656250000000006,
	  0.0065484375000000004, 0.0087312500000000012, 0.0109140625,
	  0.013096875000000001, 0.0152796875, 0.017462500000000002, 0.0196453125,
	  0.021828125, 0.024010937500000003, 0.026193750000000002, 0.0283765625,
	  0.030559375, 0.0327421875, 0.034925000000000005, 0.0371078125, 0.039290625,
	  0.0414734375, 0.04365625, 0.045839062500000007, 0.048021875000000006,
	  0.050204687500000005, 0.052387500000000004, 0.0545703125, 0.056753125,
	  0.058935937500000007, 0.06111875, 0.0633015625, 0.065484375, 0.0676671875,
	  -0.069850000000000009, -0.0676671875, -0.065484375, -0.0633015625,
	  -0.06111875, -0.058935937500000007, -0.056753125, -0.0545703125,
	  -0.052387500000000004, -0.050204687500000005, -0.048021875000000006,
	  -0.045839062500000007, -0.04365625, -0.0414734375, -0.039290625,
	  -0.0371078125, -0.034925000000000005, -0.0327421875, -0.030559375,
	  -0.0283765625, -0.026193750000000002, -0.024010937500000003, -0.021828125,
	  -0.0196453125, -0.017462500000000002, -0.0152796875, -0.013096875000000001,
	  -0.0109140625, -0.0087312500000000012, -0.0065484375000000004,
	  -0.0043656250000000006, -0.0021828125000000003, 0.0, 0.0021828125000000003,
	  0.0043656250000000006, 0.0065484375000000004, 0.0087312500000000012,
	  0.0109140625, 0.013096875000000001, 0.0152796875, 0.017462500000000002,
	  0.0196453125, 0.021828125, 0.024010937500000003, 0.026193750000000002,
	  0.0283765625, 0.030559375, 0.0327421875, 0.034925000000000005, 0.0371078125,
	  0.039290625, 0.0414734375, 0.04365625, 0.045839062500000007,
	  0.048021875000000006, 0.050204687500000005, 0.052387500000000004,
	  0.0545703125, 0.056753125, 0.058935937500000007, 0.06111875, 0.0633015625,
	  0.065484375, 0.0676671875, -0.069850000000000009, -0.0676671875,
	  -0.065484375, -0.0633015625, -0.06111875, -0.058935937500000007,
	  -0.056753125, -0.0545703125, -0.052387500000000004, -0.050204687500000005,
	  -0.048021875000000006, -0.045839062500000007, -0.04365625, -0.0414734375,
	  -0.039290625, -0.0371078125, -0.034925000000000005, -0.0327421875,
	  -0.030559375, -0.0283765625, -0.026193750000000002, -0.024010937500000003,
	  -0.021828125, -0.0196453125, -0.017462500000000002, -0.0152796875,
	  -0.013096875000000001, -0.0109140625, -0.0087312500000000012,
	  -0.0065484375000000004, -0.0043656250000000006, -0.0021828125000000003, 0.0,
	  0.0021828125000000003, 0.0043656250000000006, 0.0065484375000000004,
	  0.0087312500000000012, 0.0109140625, 0.013096875000000001, 0.0152796875,
	  0.017462500000000002, 0.0196453125, 0.021828125, 0.024010937500000003,
	  0.026193750000000002, 0.0283765625, 0.030559375, 0.0327421875,
	  0.034925000000000005, 0.0371078125, 0.039290625, 0.0414734375, 0.04365625,
	  0.045839062500000007, 0.048021875000000006, 0.050204687500000005,
	  0.052387500000000004, 0.0545703125, 0.056753125, 0.058935937500000007,
	  0.06111875, 0.0633015625, 0.065484375, 0.0676671875, -0.069850000000000009,
	  -0.0676671875, -0.065484375, -0.0633015625, -0.06111875,
	  -0.058935937500000007, -0.056753125, -0.0545703125, -0.052387500000000004,
	  -0.050204687500000005, -0.048021875000000006, -0.045839062500000007,
	  -0.04365625, -0.0414734375, -0.039290625, -0.0371078125,
	  -0.034925000000000005, -0.0327421875, -0.030559375, -0.0283765625,
	  -0.026193750000000002, -0.024010937500000003, -0.021828125, -0.0196453125,
	  -0.017462500000000002, -0.0152796875, -0.013096875000000001, -0.0109140625,
	  -0.0087312500000000012, -0.0065484375000000004, -0.0043656250000000006,
	  -0.0021828125000000003, 0.0, 0.0021828125000000003, 0.0043656250000000006,
	  0.0065484375000000004, 0.0087312500000000012, 0.0109140625,
	  0.013096875000000001, 0.0152796875, 0.017462500000000002, 0.0196453125,
	  0.021828125, 0.024010937500000003, 0.026193750000000002, 0.0283765625,
	  0.030559375, 0.0327421875, 0.034925000000000005, 0.0371078125, 0.039290625,
	  0.0414734375, 0.04365625, 0.045839062500000007, 0.048021875000000006,
	  0.050204687500000005, 0.052387500000000004, 0.0545703125, 0.056753125,
	  0.058935937500000007, 0.06111875, 0.0633015625, 0.065484375, 0.0676671875,
	  -0.069850000000000009, -0.0676671875, -0.065484375, -0.0633015625,
	  -0.06111875, -0.058935937500000007, -0.056753125, -0.0545703125,
	  -0.052387500000000004, -0.050204687500000005, -0.048021875000000006,
	  -0.045839062500000007, -0.04365625, -0.0414734375, -0.039290625,
	  -0.0371078125, -0.034925000000000005, -0.0327421875, -0.030559375,
	  -0.0283765625, -0.026193750000000002, -0.024010937500000003, -0.021828125,
	  -0.0196453125, -0.017462500000000002, -0.0152796875, -0.013096875000000001,
	  -0.0109140625, -0.0087312500000000012, -0.0065484375000000004,
	  -0.0043656250000000006, -0.0021828125000000003, 0.0, 0.0021828125000000003,
	  0.0043656250000000006, 0.0065484375000000004, 0.0087312500000000012,
	  0.0109140625, 0.013096875000000001, 0.0152796875, 0.017462500000000002,
	  0.0196453125, 0.021828125, 0.024010937500000003, 0.026193750000000002,
	  0.0283765625, 0.030559375, 0.0327421875, 0.034925000000000005, 0.0371078125,
	  0.039290625, 0.0414734375, 0.04365625, 0.045839062500000007,
	  0.048021875000000006, 0.050204687500000005, 0.052387500000000004,
	  0.0545703125, 0.056753125, 0.058935937500000007, 0.06111875, 0.0633015625,
	  0.065484375, 0.0676671875, -0.069850000000000009, -0.0676671875,
	  -0.065484375, -0.0633015625, -0.06111875, -0.058935937500000007,
	  -0.056753125, -0.0545703125, -0.052387500000000004, -0.050204687500000005,
	  -0.048021875000000006, -0.045839062500000007, -0.04365625, -0.0414734375,
	  -0.039290625, -0.0371078125, -0.034925000000000005, -0.0327421875,
	  -0.030559375, -0.0283765625, -0.026193750000000002, -0.024010937500000003,
	  -0.021828125, -0.0196453125, -0.017462500000000002, -0.0152796875,
	  -0.013096875000000001, -0.0109140625, -0.0087312500000000012,
	  -0.0065484375000000004, -0.0043656250000000006, -0.0021828125000000003, 0.0,
	  0.0021828125000000003, 0.0043656250000000006, 0.0065484375000000004,
	  0.0087312500000000012, 0.0109140625, 0.013096875000000001, 0.0152796875,
	  0.017462500000000002, 0.0196453125, 0.021828125, 0.024010937500000003,
	  0.026193750000000002, 0.0283765625, 0.030559375, 0.0327421875,
	  0.034925000000000005, 0.0371078125, 0.039290625, 0.0414734375, 0.04365625,
	  0.045839062500000007, 0.048021875000000006, 0.050204687500000005,
	  0.052387500000000004, 0.0545703125, 0.056753125, 0.058935937500000007,
	  0.06111875, 0.0633015625, 0.065484375, 0.0676671875, -0.069850000000000009,
	  -0.0676671875, -0.065484375, -0.0633015625, -0.06111875,
	  -0.058935937500000007, -0.056753125, -0.0545703125, -0.052387500000000004,
	  -0.050204687500000005, -0.048021875000000006, -0.045839062500000007,
	  -0.04365625, -0.0414734375, -0.039290625, -0.0371078125,
	  -0.034925000000000005, -0.0327421875, -0.030559375, -0.0283765625,
	  -0.026193750000000002, -0.024010937500000003, -0.021828125, -0.0196453125,
	  -0.017462500000000002, -0.0152796875, -0.013096875000000001, -0.0109140625,
	  -0.0087312500000000012, -0.0065484375000000004, -0.0043656250000000006,
	  -0.0021828125000000003, 0.0, 0.0021828125000000003, 0.0043656250000000006,
	  0.0065484375000000004, 0.0087312500000000012, 0.0109140625,
	  0.013096875000000001, 0.0152796875, 0.017462500000000002, 0.0196453125,
	  0.021828125, 0.024010937500000003, 0.026193750000000002, 0.0283765625,
	  0.030559375, 0.0327421875, 0.034925000000000005, 0.0371078125, 0.039290625,
	  0.0414734375, 0.04365625, 0.045839062500000007, 0.048021875000000006,
	  0.050204687500000005, 0.052387500000000004, 0.0545703125, 0.056753125,
	  0.058935937500000007, 0.06111875, 0.0633015625, 0.065484375, 0.0676671875,
	  -0.069850000000000009, -0.0676671875, -0.065484375, -0.0633015625,
	  -0.06111875, -0.058935937500000007, -0.056753125, -0.0545703125,
	  -0.052387500000000004, -0.050204687500000005, -0.048021875000000006,
	  -0.045839062500000007, -0.04365625, -0.0414734375, -0.039290625,
	  -0.0371078125, -0.034925000000000005, -0.0327421875, -0.030559375,
	  -0.0283765625, -0.026193750000000002, -0.024010937500000003, -0.021828125,
	  -0.0196453125, -0.017462500000000002, -0.0152796875, -0.013096875000000001,
	  -0.0109140625, -0.0087312500000000012, -0.0065484375000000004,
	  -0.0043656250000000006, -0.0021828125000000003, 0.0, 0.0021828125000000003,
	  0.0043656250000000006, 0.0065484375000000004, 0.0087312500000000012,
	  0.0109140625, 0.013096875000000001, 0.0152796875, 0.017462500000000002,
	  0.0196453125, 0.021828125, 0.024010937500000003, 0.026193750000000002,
	  0.0283765625, 0.030559375, 0.0327421875, 0.034925000000000005, 0.0371078125,
	  0.039290625, 0.0414734375, 0.04365625, 0.045839062500000007,
	  0.048021875000000006, 0.050204687500000005, 0.052387500000000004,
	  0.0545703125, 0.056753125, 0.058935937500000007, 0.06111875, 0.0633015625,
	  0.065484375, 0.0676671875, -0.069850000000000009, -0.0676671875,
	  -0.065484375, -0.0633015625, -0.06111875, -0.058935937500000007,
	  -0.056753125, -0.0545703125, -0.052387500000000004, -0.050204687500000005,
	  -0.048021875000000006, -0.045839062500000007, -0.04365625, -0.0414734375,
	  -0.039290625, -0.0371078125, -0.034925000000000005, -0.0327421875,
	  -0.030559375, -0.0283765625, -0.026193750000000002, -0.024010937500000003,
	  -0.021828125, -0.0196453125, -0.017462500000000002, -0.0152796875,
	  -0.013096875000000001, -0.0109140625, -0.0087312500000000012,
	  -0.0065484375000000004, -0.0043656250000000006, -0.0021828125000000003, 0.0,
	  0.0021828125000000003, 0.0043656250000000006, 0.0065484375000000004,
	  0.0087312500000000012, 0.0109140625, 0.013096875000000001, 0.0152796875,
	  0.017462500000000002, 0.0196453125, 0.021828125, 0.024010937500000003,
	  0.026193750000000002, 0.0283765625, 0.030559375, 0.0327421875,
	  0.034925000000000005, 0.0371078125, 0.039290625, 0.0414734375, 0.04365625,
	  0.045839062500000007, 0.048021875000000006, 0.050204687500000005,
	  0.052387500000000004, 0.0545703125, 0.056753125, 0.058935937500000007,
	  0.06111875, 0.0633015625, 0.065484375, 0.0676671875, -0.069850000000000009,
	  -0.0676671875, -0.065484375, -0.0633015625, -0.06111875,
	  -0.058935937500000007, -0.056753125, -0.0545703125, -0.052387500000000004,
	  -0.050204687500000005, -0.048021875000000006, -0.045839062500000007,
	  -0.04365625, -0.0414734375, -0.039290625, -0.0371078125,
	  -0.034925000000000005, -0.0327421875, -0.030559375, -0.0283765625,
	  -0.026193750000000002, -0.024010937500000003, -0.021828125, -0.0196453125,
	  -0.017462500000000002, -0.0152796875, -0.013096875000000001, -0.0109140625,
	  -0.0087312500000000012, -0.0065484375000000004, -0.0043656250000000006,
	  -0.0021828125000000003, 0.0, 0.0021828125000000003, 0.0043656250000000006,
	  0.0065484375000000004, 0.0087312500000000012, 0.0109140625,
	  0.013096875000000001, 0.0152796875, 0.017462500000000002, 0.0196453125,
	  0.021828125, 0.024010937500000003, 0.026193750000000002, 0.0283765625,
	  0.030559375, 0.0327421875, 0.034925000000000005, 0.0371078125, 0.039290625,
	  0.0414734375, 0.04365625, 0.045839062500000007, 0.048021875000000006,
	  0.050204687500000005, 0.052387500000000004, 0.0545703125, 0.056753125,
	  0.058935937500000007, 0.06111875, 0.0633015625, 0.065484375, 0.0676671875,
	  -0.069850000000000009, -0.0676671875, -0.065484375, -0.0633015625,
	  -0.06111875, -0.058935937500000007, -0.056753125, -0.0545703125,
	  -0.052387500000000004, -0.050204687500000005, -0.048021875000000006,
	  -0.045839062500000007, -0.04365625, -0.0414734375, -0.039290625,
	  -0.0371078125, -0.034925000000000005, -0.0327421875, -0.030559375,
	  -0.0283765625, -0.026193750000000002, -0.024010937500000003, -0.021828125,
	  -0.0196453125, -0.017462500000000002, -0.0152796875, -0.013096875000000001,
	  -0.0109140625, -0.0087312500000000012, -0.0065484375000000004,
	  -0.0043656250000000006, -0.0021828125000000003, 0.0, 0.0021828125000000003,
	  0.0043656250000000006, 0.0065484375000000004, 0.0087312500000000012,
	  0.0109140625, 0.013096875000000001, 0.0152796875, 0.017462500000000002,
	  0.0196453125, 0.021828125, 0.024010937500000003, 0.026193750000000002,
	  0.0283765625, 0.030559375, 0.0327421875, 0.034925000000000005, 0.0371078125,
	  0.039290625, 0.0414734375, 0.04365625, 0.045839062500000007,
	  0.048021875000000006, 0.050204687500000005, 0.052387500000000004,
	  0.0545703125, 0.056753125, 0.058935937500000007, 0.06111875, 0.0633015625,
	  0.065484375, 0.0676671875, -0.069850000000000009, -0.0676671875,
	  -0.065484375, -0.0633015625, -0.06111875, -0.058935937500000007,
	  -0.056753125, -0.0545703125, -0.052387500000000004, -0.050204687500000005,
	  -0.048021875000000006, -0.045839062500000007, -0.04365625, -0.0414734375,
	  -0.039290625, -0.0371078125, -0.034925000000000005, -0.0327421875,
	  -0.030559375, -0.0283765625, -0.026193750000000002, -0.024010937500000003,
	  -0.021828125, -0.0196453125, -0.017462500000000002, -0.0152796875,
	  -0.013096875000000001, -0.0109140625, -0.0087312500000000012,
	  -0.0065484375000000004, -0.0043656250000000006, -0.0021828125000000003, 0.0,
	  0.0021828125000000003, 0.0043656250000000006, 0.0065484375000000004,
	  0.0087312500000000012, 0.0109140625, 0.013096875000000001, 0.0152796875,
	  0.017462500000000002, 0.0196453125, 0.021828125, 0.024010937500000003,
	  0.026193750000000002, 0.0283765625, 0.030559375, 0.0327421875,
	  0.034925000000000005, 0.0371078125, 0.039290625, 0.0414734375, 0.04365625,
	  0.045839062500000007, 0.048021875000000006, 0.050204687500000005,
	  0.052387500000000004, 0.0545703125, 0.056753125, 0.058935937500000007,
	  0.06111875, 0.0633015625, 0.065484375, 0.0676671875, -0.069850000000000009,
	  -0.0676671875, -0.065484375, -0.0633015625, -0.06111875,
	  -0.058935937500000007, -0.056753125, -0.0545703125, -0.052387500000000004,
	  -0.050204687500000005, -0.048021875000000006, -0.045839062500000007,
	  -0.04365625, -0.0414734375, -0.039290625, -0.0371078125,
	  -0.034925000000000005, -0.0327421875, -0.030559375, -0.0283765625,
	  -0.026193750000000002, -0.024010937500000003, -0.021828125, -0.0196453125,
	  -0.017462500000000002, -0.0152796875, -0.013096875000000001, -0.0109140625,
	  -0.0087312500000000012, -0.0065484375000000004, -0.0043656250000000006,
	  -0.0021828125000000003, 0.0, 0.0021828125000000003, 0.0043656250000000006,
	  0.0065484375000000004, 0.0087312500000000012, 0.0109140625,
	  0.013096875000000001, 0.0152796875, 0.017462500000000002, 0.0196453125,
	  0.021828125, 0.024010937500000003, 0.026193750000000002, 0.0283765625,
	  0.030559375, 0.0327421875, 0.034925000000000005, 0.0371078125, 0.039290625,
	  0.0414734375, 0.04365625, 0.045839062500000007, 0.048021875000000006,
	  0.050204687500000005, 0.052387500000000004, 0.0545703125, 0.056753125,
	  0.058935937500000007, 0.06111875, 0.0633015625, 0.065484375, 0.0676671875,
	  -0.069850000000000009, -0.0676671875, -0.065484375, -0.0633015625,
	  -0.06111875, -0.058935937500000007, -0.056753125, -0.0545703125,
	  -0.052387500000000004, -0.050204687500000005, -0.048021875000000006,
	  -0.045839062500000007, -0.04365625, -0.0414734375, -0.039290625,
	  -0.0371078125, -0.034925000000000005, -0.0327421875, -0.030559375,
	  -0.0283765625, -0.026193750000000002, -0.024010937500000003, -0.021828125,
	  -0.0196453125, -0.017462500000000002, -0.0152796875, -0.013096875000000001,
	  -0.0109140625, -0.0087312500000000012, -0.0065484375000000004,
	  -0.0043656250000000006, -0.0021828125000000003, 0.0, 0.0021828125000000003,
	  0.0043656250000000006, 0.0065484375000000004, 0.0087312500000000012,
	  0.0109140625, 0.013096875000000001, 0.0152796875, 0.017462500000000002,
	  0.0196453125, 0.021828125, 0.024010937500000003, 0.026193750000000002,
	  0.0283765625, 0.030559375, 0.0327421875, 0.034925000000000005, 0.0371078125,
	  0.039290625, 0.0414734375, 0.04365625, 0.045839062500000007,
	  0.048021875000000006, 0.050204687500000005, 0.052387500000000004,
	  0.0545703125, 0.056753125, 0.058935937500000007, 0.06111875, 0.0633015625,
	  0.065484375, 0.0676671875, -0.069850000000000009, -0.0676671875,
	  -0.065484375, -0.0633015625, -0.06111875, -0.058935937500000007,
	  -0.056753125, -0.0545703125, -0.052387500000000004, -0.050204687500000005,
	  -0.048021875000000006, -0.045839062500000007, -0.04365625, -0.0414734375,
	  -0.039290625, -0.0371078125, -0.034925000000000005, -0.0327421875,
	  -0.030559375, -0.0283765625, -0.026193750000000002, -0.024010937500000003,
	  -0.021828125, -0.0196453125, -0.017462500000000002, -0.0152796875,
	  -0.013096875000000001, -0.0109140625, -0.0087312500000000012,
	  -0.0065484375000000004, -0.0043656250000000006, -0.0021828125000000003, 0.0,
	  0.0021828125000000003, 0.0043656250000000006, 0.0065484375000000004,
	  0.0087312500000000012, 0.0109140625, 0.013096875000000001, 0.0152796875,
	  0.017462500000000002, 0.0196453125, 0.021828125, 0.024010937500000003,
	  0.026193750000000002, 0.0283765625, 0.030559375, 0.0327421875,
	  0.034925000000000005, 0.0371078125, 0.039290625, 0.0414734375, 0.04365625,
	  0.045839062500000007, 0.048021875000000006, 0.050204687500000005,
	  0.052387500000000004, 0.0545703125, 0.056753125, 0.058935937500000007,
	  0.06111875, 0.0633015625, 0.065484375, 0.0676671875, -0.069850000000000009,
	  -0.0676671875, -0.065484375, -0.0633015625, -0.06111875,
	  -0.058935937500000007, -0.056753125, -0.0545703125, -0.052387500000000004,
	  -0.050204687500000005, -0.048021875000000006, -0.045839062500000007,
	  -0.04365625, -0.0414734375, -0.039290625, -0.0371078125,
	  -0.034925000000000005, -0.0327421875, -0.030559375, -0.0283765625,
	  -0.026193750000000002, -0.024010937500000003, -0.021828125, -0.0196453125,
	  -0.017462500000000002, -0.0152796875, -0.013096875000000001, -0.0109140625,
	  -0.0087312500000000012, -0.0065484375000000004, -0.0043656250000000006,
	  -0.0021828125000000003, 0.0, 0.0021828125000000003, 0.0043656250000000006,
	  0.0065484375000000004, 0.0087312500000000012, 0.0109140625,
	  0.013096875000000001, 0.0152796875, 0.017462500000000002, 0.0196453125,
	  0.021828125, 0.024010937500000003, 0.026193750000000002, 0.0283765625,
	  0.030559375, 0.0327421875, 0.034925000000000005, 0.0371078125, 0.039290625,
	  0.0414734375, 0.04365625, 0.045839062500000007, 0.048021875000000006,
	  0.050204687500000005, 0.052387500000000004, 0.0545703125, 0.056753125,
	  0.058935937500000007, 0.06111875, 0.0633015625, 0.065484375, 0.0676671875,
	  -0.069850000000000009, -0.0676671875, -0.065484375, -0.0633015625,
	  -0.06111875, -0.058935937500000007, -0.056753125, -0.0545703125,
	  -0.052387500000000004, -0.050204687500000005, -0.048021875000000006,
	  -0.045839062500000007, -0.04365625, -0.0414734375, -0.039290625,
	  -0.0371078125, -0.034925000000000005, -0.0327421875, -0.030559375,
	  -0.0283765625, -0.026193750000000002, -0.024010937500000003, -0.021828125,
	  -0.0196453125, -0.017462500000000002, -0.0152796875, -0.013096875000000001,
	  -0.0109140625, -0.0087312500000000012, -0.0065484375000000004,
	  -0.0043656250000000006, -0.0021828125000000003, 0.0, 0.0021828125000000003,
	  0.0043656250000000006, 0.0065484375000000004, 0.0087312500000000012,
	  0.0109140625, 0.013096875000000001, 0.0152796875, 0.017462500000000002,
	  0.0196453125, 0.021828125, 0.024010937500000003, 0.026193750000000002,
	  0.0283765625, 0.030559375, 0.0327421875, 0.034925000000000005, 0.0371078125,
	  0.039290625, 0.0414734375, 0.04365625, 0.045839062500000007,
	  0.048021875000000006, 0.050204687500000005, 0.052387500000000004,
	  0.0545703125, 0.056753125, 0.058935937500000007, 0.06111875, 0.0633015625,
	  0.065484375, 0.0676671875, -0.069850000000000009, -0.0676671875,
	  -0.065484375, -0.0633015625, -0.06111875, -0.058935937500000007,
	  -0.056753125, -0.0545703125, -0.052387500000000004, -0.050204687500000005,
	  -0.048021875000000006, -0.045839062500000007, -0.04365625, -0.0414734375,
	  -0.039290625, -0.0371078125, -0.034925000000000005, -0.0327421875,
	  -0.030559375, -0.0283765625, -0.026193750000000002, -0.024010937500000003,
	  -0.021828125, -0.0196453125, -0.017462500000000002, -0.0152796875,
	  -0.013096875000000001, -0.0109140625, -0.0087312500000000012,
	  -0.0065484375000000004, -0.0043656250000000006, -0.0021828125000000003, 0.0,
	  0.0021828125000000003, 0.0043656250000000006, 0.0065484375000000004,
	  0.0087312500000000012, 0.0109140625, 0.013096875000000001, 0.0152796875,
	  0.017462500000000002, 0.0196453125, 0.021828125, 0.024010937500000003,
	  0.026193750000000002, 0.0283765625, 0.030559375, 0.0327421875,
	  0.034925000000000005, 0.0371078125, 0.039290625, 0.0414734375, 0.04365625,
	  0.045839062500000007, 0.048021875000000006, 0.050204687500000005,
	  0.052387500000000004, 0.0545703125, 0.056753125, 0.058935937500000007,
	  0.06111875, 0.0633015625, 0.065484375, 0.0676671875, -0.069850000000000009,
	  -0.0676671875, -0.065484375, -0.0633015625, -0.06111875,
	  -0.058935937500000007, -0.056753125, -0.0545703125, -0.052387500000000004,
	  -0.050204687500000005, -0.048021875000000006, -0.045839062500000007,
	  -0.04365625, -0.0414734375, -0.039290625, -0.0371078125,
	  -0.034925000000000005, -0.0327421875, -0.030559375, -0.0283765625,
	  -0.026193750000000002, -0.024010937500000003, -0.021828125, -0.0196453125,
	  -0.017462500000000002, -0.0152796875, -0.013096875000000001, -0.0109140625,
	  -0.0087312500000000012, -0.0065484375000000004, -0.0043656250000000006,
	  -0.0021828125000000003, 0.0, 0.0021828125000000003, 0.0043656250000000006,
	  0.0065484375000000004, 0.0087312500000000012, 0.0109140625,
	  0.013096875000000001, 0.0152796875, 0.017462500000000002, 0.0196453125,
	  0.021828125, 0.024010937500000003, 0.026193750000000002, 0.0283765625,
	  0.030559375, 0.0327421875, 0.034925000000000005, 0.0371078125, 0.039290625,
	  0.0414734375, 0.04365625, 0.045839062500000007, 0.048021875000000006,
	  0.050204687500000005, 0.052387500000000004, 0.0545703125, 0.056753125,
	  0.058935937500000007, 0.06111875, 0.0633015625, 0.065484375, 0.0676671875,
	  -0.069850000000000009, -0.0676671875, -0.065484375, -0.0633015625,
	  -0.06111875, -0.058935937500000007, -0.056753125, -0.0545703125,
	  -0.052387500000000004, -0.050204687500000005, -0.048021875000000006,
	  -0.045839062500000007, -0.04365625, -0.0414734375, -0.039290625,
	  -0.0371078125, -0.034925000000000005, -0.0327421875, -0.030559375,
	  -0.0283765625, -0.026193750000000002, -0.024010937500000003, -0.021828125,
	  -0.0196453125, -0.017462500000000002, -0.0152796875, -0.013096875000000001,
	  -0.0109140625, -0.0087312500000000012, -0.0065484375000000004,
	  -0.0043656250000000006, -0.0021828125000000003, 0.0, 0.0021828125000000003,
	  0.0043656250000000006, 0.0065484375000000004, 0.0087312500000000012,
	  0.0109140625, 0.013096875000000001, 0.0152796875, 0.017462500000000002,
	  0.0196453125, 0.021828125, 0.024010937500000003, 0.026193750000000002,
	  0.0283765625, 0.030559375, 0.0327421875, 0.034925000000000005, 0.0371078125,
	  0.039290625, 0.0414734375, 0.04365625, 0.045839062500000007,
	  0.048021875000000006, 0.050204687500000005, 0.052387500000000004,
	  0.0545703125, 0.056753125, 0.058935937500000007, 0.06111875, 0.0633015625,
	  0.065484375, 0.0676671875, -0.069850000000000009, -0.0676671875,
	  -0.065484375, -0.0633015625, -0.06111875, -0.058935937500000007,
	  -0.056753125, -0.0545703125, -0.052387500000000004, -0.050204687500000005,
	  -0.048021875000000006, -0.045839062500000007, -0.04365625, -0.0414734375,
	  -0.039290625, -0.0371078125, -0.034925000000000005, -0.0327421875,
	  -0.030559375, -0.0283765625, -0.026193750000000002, -0.024010937500000003,
	  -0.021828125, -0.0196453125, -0.017462500000000002, -0.0152796875,
	  -0.013096875000000001, -0.0109140625, -0.0087312500000000012,
	  -0.0065484375000000004, -0.0043656250000000006, -0.0021828125000000003, 0.0,
	  0.0021828125000000003, 0.0043656250000000006, 0.0065484375000000004,
	  0.0087312500000000012, 0.0109140625, 0.013096875000000001, 0.0152796875,
	  0.017462500000000002, 0.0196453125, 0.021828125, 0.024010937500000003,
	  0.026193750000000002, 0.0283765625, 0.030559375, 0.0327421875,
	  0.034925000000000005, 0.0371078125, 0.039290625, 0.0414734375, 0.04365625,
	  0.045839062500000007, 0.048021875000000006, 0.050204687500000005,
	  0.052387500000000004, 0.0545703125, 0.056753125, 0.058935937500000007,
	  0.06111875, 0.0633015625, 0.065484375, 0.0676671875, -0.069850000000000009,
	  -0.0676671875, -0.065484375, -0.0633015625, -0.06111875,
	  -0.058935937500000007, -0.056753125, -0.0545703125, -0.052387500000000004,
	  -0.050204687500000005, -0.048021875000000006, -0.045839062500000007,
	  -0.04365625, -0.0414734375, -0.039290625, -0.0371078125,
	  -0.034925000000000005, -0.0327421875, -0.030559375, -0.0283765625,
	  -0.026193750000000002, -0.024010937500000003, -0.021828125, -0.0196453125,
	  -0.017462500000000002, -0.0152796875, -0.013096875000000001, -0.0109140625,
	  -0.0087312500000000012, -0.0065484375000000004, -0.0043656250000000006,
	  -0.0021828125000000003, 0.0, 0.0021828125000000003, 0.0043656250000000006,
	  0.0065484375000000004, 0.0087312500000000012, 0.0109140625,
	  0.013096875000000001, 0.0152796875, 0.017462500000000002, 0.0196453125,
	  0.021828125, 0.024010937500000003, 0.026193750000000002, 0.0283765625,
	  0.030559375, 0.0327421875, 0.034925000000000005, 0.0371078125, 0.039290625,
	  0.0414734375, 0.04365625, 0.045839062500000007, 0.048021875000000006,
	  0.050204687500000005, 0.052387500000000004, 0.0545703125, 0.056753125,
	  0.058935937500000007, 0.06111875, 0.0633015625, 0.065484375, 0.0676671875,
	  -0.069850000000000009, -0.0676671875, -0.065484375, -0.0633015625,
	  -0.06111875, -0.058935937500000007, -0.056753125, -0.0545703125,
	  -0.052387500000000004, -0.050204687500000005, -0.048021875000000006,
	  -0.045839062500000007, -0.04365625, -0.0414734375, -0.039290625,
	  -0.0371078125, -0.034925000000000005, -0.0327421875, -0.030559375,
	  -0.0283765625, -0.026193750000000002, -0.024010937500000003, -0.021828125,
	  -0.0196453125, -0.017462500000000002, -0.0152796875, -0.013096875000000001,
	  -0.0109140625, -0.0087312500000000012, -0.0065484375000000004,
	  -0.0043656250000000006, -0.0021828125000000003, 0.0, 0.0021828125000000003,
	  0.0043656250000000006, 0.0065484375000000004, 0.0087312500000000012,
	  0.0109140625, 0.013096875000000001, 0.0152796875, 0.017462500000000002,
	  0.0196453125, 0.021828125, 0.024010937500000003, 0.026193750000000002,
	  0.0283765625, 0.030559375, 0.0327421875, 0.034925000000000005, 0.0371078125,
	  0.039290625, 0.0414734375, 0.04365625, 0.045839062500000007,
	  0.048021875000000006, 0.050204687500000005, 0.052387500000000004,
	  0.0545703125, 0.056753125, 0.058935937500000007, 0.06111875, 0.0633015625,
	  0.065484375, 0.0676671875, -0.069850000000000009, -0.0676671875,
	  -0.065484375, -0.0633015625, -0.06111875, -0.058935937500000007,
	  -0.056753125, -0.0545703125, -0.052387500000000004, -0.050204687500000005,
	  -0.048021875000000006, -0.045839062500000007, -0.04365625, -0.0414734375,
	  -0.039290625, -0.0371078125, -0.034925000000000005, -0.0327421875,
	  -0.030559375, -0.0283765625, -0.026193750000000002, -0.024010937500000003,
	  -0.021828125, -0.0196453125, -0.017462500000000002, -0.0152796875,
	  -0.013096875000000001, -0.0109140625, -0.0087312500000000012,
	  -0.0065484375000000004, -0.0043656250000000006, -0.0021828125000000003, 0.0,
	  0.0021828125000000003, 0.0043656250000000006, 0.0065484375000000004,
	  0.0087312500000000012, 0.0109140625, 0.013096875000000001, 0.0152796875,
	  0.017462500000000002, 0.0196453125, 0.021828125, 0.024010937500000003,
	  0.026193750000000002, 0.0283765625, 0.030559375, 0.0327421875,
	  0.034925000000000005, 0.0371078125, 0.039290625, 0.0414734375, 0.04365625,
	  0.045839062500000007, 0.048021875000000006, 0.050204687500000005,
	  0.052387500000000004, 0.0545703125, 0.056753125, 0.058935937500000007,
	  0.06111875, 0.0633015625, 0.065484375, 0.0676671875, -0.069850000000000009,
	  -0.0676671875, -0.065484375, -0.0633015625, -0.06111875,
	  -0.058935937500000007, -0.056753125, -0.0545703125, -0.052387500000000004,
	  -0.050204687500000005, -0.048021875000000006, -0.045839062500000007,
	  -0.04365625, -0.0414734375, -0.039290625, -0.0371078125,
	  -0.034925000000000005, -0.0327421875, -0.030559375, -0.0283765625,
	  -0.026193750000000002, -0.024010937500000003, -0.021828125, -0.0196453125,
	  -0.017462500000000002, -0.0152796875, -0.013096875000000001, -0.0109140625,
	  -0.0087312500000000012, -0.0065484375000000004, -0.0043656250000000006,
	  -0.0021828125000000003, 0.0, 0.0021828125000000003, 0.0043656250000000006,
	  0.0065484375000000004, 0.0087312500000000012, 0.0109140625,
	  0.013096875000000001, 0.0152796875, 0.017462500000000002, 0.0196453125,
	  0.021828125, 0.024010937500000003, 0.026193750000000002, 0.0283765625,
	  0.030559375, 0.0327421875, 0.034925000000000005, 0.0371078125, 0.039290625,
	  0.0414734375, 0.04365625, 0.045839062500000007, 0.048021875000000006,
	  0.050204687500000005, 0.052387500000000004, 0.0545703125, 0.056753125,
	  0.058935937500000007, 0.06111875, 0.0633015625, 0.065484375, 0.0676671875,
	  -0.069850000000000009, -0.0676671875, -0.065484375, -0.0633015625,
	  -0.06111875, -0.058935937500000007, -0.056753125, -0.0545703125,
	  -0.052387500000000004, -0.050204687500000005, -0.048021875000000006,
	  -0.045839062500000007, -0.04365625, -0.0414734375, -0.039290625,
	  -0.0371078125, -0.034925000000000005, -0.0327421875, -0.030559375,
	  -0.0283765625, -0.026193750000000002, -0.024010937500000003, -0.021828125,
	  -0.0196453125, -0.017462500000000002, -0.0152796875, -0.013096875000000001,
	  -0.0109140625, -0.0087312500000000012, -0.0065484375000000004,
	  -0.0043656250000000006, -0.0021828125000000003, 0.0, 0.0021828125000000003,
	  0.0043656250000000006, 0.0065484375000000004, 0.0087312500000000012,
	  0.0109140625, 0.013096875000000001, 0.0152796875, 0.017462500000000002,
	  0.0196453125, 0.021828125, 0.024010937500000003, 0.026193750000000002,
	  0.0283765625, 0.030559375, 0.0327421875, 0.034925000000000005, 0.0371078125,
	  0.039290625, 0.0414734375, 0.04365625, 0.045839062500000007,
	  0.048021875000000006, 0.050204687500000005, 0.052387500000000004,
	  0.0545703125, 0.056753125, 0.058935937500000007, 0.06111875, 0.0633015625,
	  0.065484375, 0.0676671875, -0.069850000000000009, -0.0676671875,
	  -0.065484375, -0.0633015625, -0.06111875, -0.058935937500000007,
	  -0.056753125, -0.0545703125, -0.052387500000000004, -0.050204687500000005,
	  -0.048021875000000006, -0.045839062500000007, -0.04365625, -0.0414734375,
	  -0.039290625, -0.0371078125, -0.034925000000000005, -0.0327421875,
	  -0.030559375, -0.0283765625, -0.026193750000000002, -0.024010937500000003,
	  -0.021828125, -0.0196453125, -0.017462500000000002, -0.0152796875,
	  -0.013096875000000001, -0.0109140625, -0.0087312500000000012,
	  -0.0065484375000000004, -0.0043656250000000006, -0.0021828125000000003, 0.0,
	  0.0021828125000000003, 0.0043656250000000006, 0.0065484375000000004,
	  0.0087312500000000012, 0.0109140625, 0.013096875000000001, 0.0152796875,
	  0.017462500000000002, 0.0196453125, 0.021828125, 0.024010937500000003,
	  0.026193750000000002, 0.0283765625, 0.030559375, 0.0327421875,
	  0.034925000000000005, 0.0371078125, 0.039290625, 0.0414734375, 0.04365625,
	  0.045839062500000007, 0.048021875000000006, 0.050204687500000005,
	  0.052387500000000004, 0.0545703125, 0.056753125, 0.058935937500000007,
	  0.06111875, 0.0633015625, 0.065484375, 0.0676671875, -0.069850000000000009,
	  -0.0676671875, -0.065484375, -0.0633015625, -0.06111875,
	  -0.058935937500000007, -0.056753125, -0.0545703125, -0.052387500000000004,
	  -0.050204687500000005, -0.048021875000000006, -0.045839062500000007,
	  -0.04365625, -0.0414734375, -0.039290625, -0.0371078125,
	  -0.034925000000000005, -0.0327421875, -0.030559375, -0.0283765625,
	  -0.026193750000000002, -0.024010937500000003, -0.021828125, -0.0196453125,
	  -0.017462500000000002, -0.0152796875, -0.013096875000000001, -0.0109140625,
	  -0.0087312500000000012, -0.0065484375000000004, -0.0043656250000000006,
	  -0.0021828125000000003, 0.0, 0.0021828125000000003, 0.0043656250000000006,
	  0.0065484375000000004, 0.0087312500000000012, 0.0109140625,
	  0.013096875000000001, 0.0152796875, 0.017462500000000002, 0.0196453125,
	  0.021828125, 0.024010937500000003, 0.026193750000000002, 0.0283765625,
	  0.030559375, 0.0327421875, 0.034925000000000005, 0.0371078125, 0.039290625,
	  0.0414734375, 0.04365625, 0.045839062500000007, 0.048021875000000006,
	  0.050204687500000005, 0.052387500000000004, 0.0545703125, 0.056753125,
	  0.058935937500000007, 0.06111875, 0.0633015625, 0.065484375, 0.0676671875,
	  -0.069850000000000009, -0.0676671875, -0.065484375, -0.0633015625,
	  -0.06111875, -0.058935937500000007, -0.056753125, -0.0545703125,
	  -0.052387500000000004, -0.050204687500000005, -0.048021875000000006,
	  -0.045839062500000007, -0.04365625, -0.0414734375, -0.039290625,
	  -0.0371078125, -0.034925000000000005, -0.0327421875, -0.030559375,
	  -0.0283765625, -0.026193750000000002, -0.024010937500000003, -0.021828125,
	  -0.0196453125, -0.017462500000000002, -0.0152796875, -0.013096875000000001,
	  -0.0109140625, -0.0087312500000000012, -0.0065484375000000004,
	  -0.0043656250000000006, -0.0021828125000000003, 0.0, 0.0021828125000000003,
	  0.0043656250000000006, 0.0065484375000000004, 0.0087312500000000012,
	  0.0109140625, 0.013096875000000001, 0.0152796875, 0.017462500000000002,
	  0.0196453125, 0.021828125, 0.024010937500000003, 0.026193750000000002,
	  0.0283765625, 0.030559375, 0.0327421875, 0.034925000000000005, 0.0371078125,
	  0.039290625, 0.0414734375, 0.04365625, 0.045839062500000007,
	  0.048021875000000006, 0.050204687500000005, 0.052387500000000004,
	  0.0545703125, 0.056753125, 0.058935937500000007, 0.06111875, 0.0633015625,
	  0.065484375, 0.0676671875, -0.069850000000000009, -0.0676671875,
	  -0.065484375, -0.0633015625, -0.06111875, -0.058935937500000007,
	  -0.056753125, -0.0545703125, -0.052387500000000004, -0.050204687500000005,
	  -0.048021875000000006, -0.045839062500000007, -0.04365625, -0.0414734375,
	  -0.039290625, -0.0371078125, -0.034925000000000005, -0.0327421875,
	  -0.030559375, -0.0283765625, -0.026193750000000002, -0.024010937500000003,
	  -0.021828125, -0.0196453125, -0.017462500000000002, -0.0152796875,
	  -0.013096875000000001, -0.0109140625, -0.0087312500000000012,
	  -0.0065484375000000004, -0.0043656250000000006, -0.0021828125000000003, 0.0,
	  0.0021828125000000003, 0.0043656250000000006, 0.0065484375000000004,
	  0.0087312500000000012, 0.0109140625, 0.013096875000000001, 0.0152796875,
	  0.017462500000000002, 0.0196453125, 0.021828125, 0.024010937500000003,
	  0.026193750000000002, 0.0283765625, 0.030559375, 0.0327421875,
	  0.034925000000000005, 0.0371078125, 0.039290625, 0.0414734375, 0.04365625,
	  0.045839062500000007, 0.048021875000000006, 0.050204687500000005,
	  0.052387500000000004, 0.0545703125, 0.056753125, 0.058935937500000007,
	  0.06111875, 0.0633015625, 0.065484375, 0.0676671875, -0.069850000000000009,
	  -0.0676671875, -0.065484375, -0.0633015625, -0.06111875,
	  -0.058935937500000007, -0.056753125, -0.0545703125, -0.052387500000000004,
	  -0.050204687500000005, -0.048021875000000006, -0.045839062500000007,
	  -0.04365625, -0.0414734375, -0.039290625, -0.0371078125,
	  -0.034925000000000005, -0.0327421875, -0.030559375, -0.0283765625,
	  -0.026193750000000002, -0.024010937500000003, -0.021828125, -0.0196453125,
	  -0.017462500000000002, -0.0152796875, -0.013096875000000001, -0.0109140625,
	  -0.0087312500000000012, -0.0065484375000000004, -0.0043656250000000006,
	  -0.0021828125000000003, 0.0, 0.0021828125000000003, 0.0043656250000000006,
	  0.0065484375000000004, 0.0087312500000000012, 0.0109140625,
	  0.013096875000000001, 0.0152796875, 0.017462500000000002, 0.0196453125,
	  0.021828125, 0.024010937500000003, 0.026193750000000002, 0.0283765625,
	  0.030559375, 0.0327421875, 0.034925000000000005, 0.0371078125, 0.039290625,
	  0.0414734375, 0.04365625, 0.045839062500000007, 0.048021875000000006,
	  0.050204687500000005, 0.052387500000000004, 0.0545703125, 0.056753125,
	  0.058935937500000007, 0.06111875, 0.0633015625, 0.065484375, 0.0676671875,
	  -0.069850000000000009, -0.0676671875, -0.065484375, -0.0633015625,
	  -0.06111875, -0.058935937500000007, -0.056753125, -0.0545703125,
	  -0.052387500000000004, -0.050204687500000005, -0.048021875000000006,
	  -0.045839062500000007, -0.04365625, -0.0414734375, -0.039290625,
	  -0.0371078125, -0.034925000000000005, -0.0327421875, -0.030559375,
	  -0.0283765625, -0.026193750000000002, -0.024010937500000003, -0.021828125,
	  -0.0196453125, -0.017462500000000002, -0.0152796875, -0.013096875000000001,
	  -0.0109140625, -0.0087312500000000012, -0.0065484375000000004,
	  -0.0043656250000000006, -0.0021828125000000003, 0.0, 0.0021828125000000003,
	  0.0043656250000000006, 0.0065484375000000004, 0.0087312500000000012,
	  0.0109140625, 0.013096875000000001, 0.0152796875, 0.017462500000000002,
	  0.0196453125, 0.021828125, 0.024010937500000003, 0.026193750000000002,
	  0.0283765625, 0.030559375, 0.0327421875, 0.034925000000000005, 0.0371078125,
	  0.039290625, 0.0414734375, 0.04365625, 0.045839062500000007,
	  0.048021875000000006, 0.050204687500000005, 0.052387500000000004,
	  0.0545703125, 0.056753125, 0.058935937500000007, 0.06111875, 0.0633015625,
	  0.065484375, 0.0676671875, -0.069850000000000009, -0.0676671875,
	  -0.065484375, -0.0633015625, -0.06111875, -0.058935937500000007,
	  -0.056753125, -0.0545703125, -0.052387500000000004, -0.050204687500000005,
	  -0.048021875000000006, -0.045839062500000007, -0.04365625, -0.0414734375,
	  -0.039290625, -0.0371078125, -0.034925000000000005, -0.0327421875,
	  -0.030559375, -0.0283765625, -0.026193750000000002, -0.024010937500000003,
	  -0.021828125, -0.0196453125, -0.017462500000000002, -0.0152796875,
	  -0.013096875000000001, -0.0109140625, -0.0087312500000000012,
	  -0.0065484375000000004, -0.0043656250000000006, -0.0021828125000000003, 0.0,
	  0.0021828125000000003, 0.0043656250000000006, 0.0065484375000000004,
	  0.0087312500000000012, 0.0109140625, 0.013096875000000001, 0.0152796875,
	  0.017462500000000002, 0.0196453125, 0.021828125, 0.024010937500000003,
	  0.026193750000000002, 0.0283765625, 0.030559375, 0.0327421875,
	  0.034925000000000005, 0.0371078125, 0.039290625, 0.0414734375, 0.04365625,
	  0.045839062500000007, 0.048021875000000006, 0.050204687500000005,
	  0.052387500000000004, 0.0545703125, 0.056753125, 0.058935937500000007,
	  0.06111875, 0.0633015625, 0.065484375, 0.0676671875, -0.069850000000000009,
	  -0.0676671875, -0.065484375, -0.0633015625, -0.06111875,
	  -0.058935937500000007, -0.056753125, -0.0545703125, -0.052387500000000004,
	  -0.050204687500000005, -0.048021875000000006, -0.045839062500000007,
	  -0.04365625, -0.0414734375, -0.039290625, -0.0371078125,
	  -0.034925000000000005, -0.0327421875, -0.030559375, -0.0283765625,
	  -0.026193750000000002, -0.024010937500000003, -0.021828125, -0.0196453125,
	  -0.017462500000000002, -0.0152796875, -0.013096875000000001, -0.0109140625,
	  -0.0087312500000000012, -0.0065484375000000004, -0.0043656250000000006,
	  -0.0021828125000000003, 0.0, 0.0021828125000000003, 0.0043656250000000006,
	  0.0065484375000000004, 0.0087312500000000012, 0.0109140625,
	  0.013096875000000001, 0.0152796875, 0.017462500000000002, 0.0196453125,
	  0.021828125, 0.024010937500000003, 0.026193750000000002, 0.0283765625,
	  0.030559375, 0.0327421875, 0.034925000000000005, 0.0371078125, 0.039290625,
	  0.0414734375, 0.04365625, 0.045839062500000007, 0.048021875000000006,
	  0.050204687500000005, 0.052387500000000004, 0.0545703125, 0.056753125,
	  0.058935937500000007, 0.06111875, 0.0633015625, 0.065484375, 0.0676671875,
	  -0.069850000000000009, -0.0676671875, -0.065484375, -0.0633015625,
	  -0.06111875, -0.058935937500000007, -0.056753125, -0.0545703125,
	  -0.052387500000000004, -0.050204687500000005, -0.048021875000000006,
	  -0.045839062500000007, -0.04365625, -0.0414734375, -0.039290625,
	  -0.0371078125, -0.034925000000000005, -0.0327421875, -0.030559375,
	  -0.0283765625, -0.026193750000000002, -0.024010937500000003, -0.021828125,
	  -0.0196453125, -0.017462500000000002, -0.0152796875, -0.013096875000000001,
	  -0.0109140625, -0.0087312500000000012, -0.0065484375000000004,
	  -0.0043656250000000006, -0.0021828125000000003, 0.0, 0.0021828125000000003,
	  0.0043656250000000006, 0.0065484375000000004, 0.0087312500000000012,
	  0.0109140625, 0.013096875000000001, 0.0152796875, 0.017462500000000002,
	  0.0196453125, 0.021828125, 0.024010937500000003, 0.026193750000000002,
	  0.0283765625, 0.030559375, 0.0327421875, 0.034925000000000005, 0.0371078125,
	  0.039290625, 0.0414734375, 0.04365625, 0.045839062500000007,
	  0.048021875000000006, 0.050204687500000005, 0.052387500000000004,
	  0.0545703125, 0.056753125, 0.058935937500000007, 0.06111875, 0.0633015625,
	  0.065484375, 0.0676671875, -0.069850000000000009, -0.0676671875,
	  -0.065484375, -0.0633015625, -0.06111875, -0.058935937500000007,
	  -0.056753125, -0.0545703125, -0.052387500000000004, -0.050204687500000005,
	  -0.048021875000000006, -0.045839062500000007, -0.04365625, -0.0414734375,
	  -0.039290625, -0.0371078125, -0.034925000000000005, -0.0327421875,
	  -0.030559375, -0.0283765625, -0.026193750000000002, -0.024010937500000003,
	  -0.021828125, -0.0196453125, -0.017462500000000002, -0.0152796875,
	  -0.013096875000000001, -0.0109140625, -0.0087312500000000012,
	  -0.0065484375000000004, -0.0043656250000000006, -0.0021828125000000003, 0.0,
	  0.0021828125000000003, 0.0043656250000000006, 0.0065484375000000004,
	  0.0087312500000000012, 0.0109140625, 0.013096875000000001, 0.0152796875,
	  0.017462500000000002, 0.0196453125, 0.021828125, 0.024010937500000003,
	  0.026193750000000002, 0.0283765625, 0.030559375, 0.0327421875,
	  0.034925000000000005, 0.0371078125, 0.039290625, 0.0414734375, 0.04365625,
	  0.045839062500000007, 0.048021875000000006, 0.050204687500000005,
	  0.052387500000000004, 0.0545703125, 0.056753125, 0.058935937500000007,
	  0.06111875, 0.0633015625, 0.065484375, 0.0676671875, -0.069850000000000009,
	  -0.0676671875, -0.065484375, -0.0633015625, -0.06111875,
	  -0.058935937500000007, -0.056753125, -0.0545703125, -0.052387500000000004,
	  -0.050204687500000005, -0.048021875000000006, -0.045839062500000007,
	  -0.04365625, -0.0414734375, -0.039290625, -0.0371078125,
	  -0.034925000000000005, -0.0327421875, -0.030559375, -0.0283765625,
	  -0.026193750000000002, -0.024010937500000003, -0.021828125, -0.0196453125,
	  -0.017462500000000002, -0.0152796875, -0.013096875000000001, -0.0109140625,
	  -0.0087312500000000012, -0.0065484375000000004, -0.0043656250000000006,
	  -0.0021828125000000003, 0.0, 0.0021828125000000003, 0.0043656250000000006,
	  0.0065484375000000004, 0.0087312500000000012, 0.0109140625,
	  0.013096875000000001, 0.0152796875, 0.017462500000000002, 0.0196453125,
	  0.021828125, 0.024010937500000003, 0.026193750000000002, 0.0283765625,
	  0.030559375, 0.0327421875, 0.034925000000000005, 0.0371078125, 0.039290625,
	  0.0414734375, 0.04365625, 0.045839062500000007, 0.048021875000000006,
	  0.050204687500000005, 0.052387500000000004, 0.0545703125, 0.056753125,
	  0.058935937500000007, 0.06111875, 0.0633015625, 0.065484375, 0.0676671875,
	  -0.069850000000000009, -0.0676671875, -0.065484375, -0.0633015625,
	  -0.06111875, -0.058935937500000007, -0.056753125, -0.0545703125,
	  -0.052387500000000004, -0.050204687500000005, -0.048021875000000006,
	  -0.045839062500000007, -0.04365625, -0.0414734375, -0.039290625,
	  -0.0371078125, -0.034925000000000005, -0.0327421875, -0.030559375,
	  -0.0283765625, -0.026193750000000002, -0.024010937500000003, -0.021828125,
	  -0.0196453125, -0.017462500000000002, -0.0152796875, -0.013096875000000001,
	  -0.0109140625, -0.0087312500000000012, -0.0065484375000000004,
	  -0.0043656250000000006, -0.0021828125000000003, 0.0, 0.0021828125000000003,
	  0.0043656250000000006, 0.0065484375000000004, 0.0087312500000000012,
	  0.0109140625, 0.013096875000000001, 0.0152796875, 0.017462500000000002,
	  0.0196453125, 0.021828125, 0.024010937500000003, 0.026193750000000002,
	  0.0283765625, 0.030559375, 0.0327421875, 0.034925000000000005, 0.0371078125,
	  0.039290625, 0.0414734375, 0.04365625, 0.045839062500000007,
	  0.048021875000000006, 0.050204687500000005, 0.052387500000000004,
	  0.0545703125, 0.056753125, 0.058935937500000007, 0.06111875, 0.0633015625,
	  0.065484375, 0.0676671875, -0.069850000000000009, -0.0676671875,
	  -0.065484375, -0.0633015625, -0.06111875, -0.058935937500000007,
	  -0.056753125, -0.0545703125, -0.052387500000000004, -0.050204687500000005,
	  -0.048021875000000006, -0.045839062500000007, -0.04365625, -0.0414734375,
	  -0.039290625, -0.0371078125, -0.034925000000000005, -0.0327421875,
	  -0.030559375, -0.0283765625, -0.026193750000000002, -0.024010937500000003,
	  -0.021828125, -0.0196453125, -0.017462500000000002, -0.0152796875,
	  -0.013096875000000001, -0.0109140625, -0.0087312500000000012,
	  -0.0065484375000000004, -0.0043656250000000006, -0.0021828125000000003, 0.0,
	  0.0021828125000000003, 0.0043656250000000006, 0.0065484375000000004,
	  0.0087312500000000012, 0.0109140625, 0.013096875000000001, 0.0152796875,
	  0.017462500000000002, 0.0196453125, 0.021828125, 0.024010937500000003,
	  0.026193750000000002, 0.0283765625, 0.030559375, 0.0327421875,
	  0.034925000000000005, 0.0371078125, 0.039290625, 0.0414734375, 0.04365625,
	  0.045839062500000007, 0.048021875000000006, 0.050204687500000005,
	  0.052387500000000004, 0.0545703125, 0.056753125, 0.058935937500000007,
	  0.06111875, 0.0633015625, 0.065484375, 0.0676671875, -0.069850000000000009,
	  -0.0676671875, -0.065484375, -0.0633015625, -0.06111875,
	  -0.058935937500000007, -0.056753125, -0.0545703125, -0.052387500000000004,
	  -0.050204687500000005, -0.048021875000000006, -0.045839062500000007,
	  -0.04365625, -0.0414734375, -0.039290625, -0.0371078125,
	  -0.034925000000000005, -0.0327421875, -0.030559375, -0.0283765625,
	  -0.026193750000000002, -0.024010937500000003, -0.021828125, -0.0196453125,
	  -0.017462500000000002, -0.0152796875, -0.013096875000000001, -0.0109140625,
	  -0.0087312500000000012, -0.0065484375000000004, -0.0043656250000000006,
	  -0.0021828125000000003, 0.0, 0.0021828125000000003, 0.0043656250000000006,
	  0.0065484375000000004, 0.0087312500000000012, 0.0109140625,
	  0.013096875000000001, 0.0152796875, 0.017462500000000002, 0.0196453125,
	  0.021828125, 0.024010937500000003, 0.026193750000000002, 0.0283765625,
	  0.030559375, 0.0327421875, 0.034925000000000005, 0.0371078125, 0.039290625,
	  0.0414734375, 0.04365625, 0.045839062500000007, 0.048021875000000006,
	  0.050204687500000005, 0.052387500000000004, 0.0545703125, 0.056753125,
	  0.058935937500000007, 0.06111875, 0.0633015625, 0.065484375, 0.0676671875,
	  -0.069850000000000009, -0.0676671875, -0.065484375, -0.0633015625,
	  -0.06111875, -0.058935937500000007, -0.056753125, -0.0545703125,
	  -0.052387500000000004, -0.050204687500000005, -0.048021875000000006,
	  -0.045839062500000007, -0.04365625, -0.0414734375, -0.039290625,
	  -0.0371078125, -0.034925000000000005, -0.0327421875, -0.030559375,
	  -0.0283765625, -0.026193750000000002, -0.024010937500000003, -0.021828125,
	  -0.0196453125, -0.017462500000000002, -0.0152796875, -0.013096875000000001,
	  -0.0109140625, -0.0087312500000000012, -0.0065484375000000004,
	  -0.0043656250000000006, -0.0021828125000000003, 0.0, 0.0021828125000000003,
	  0.0043656250000000006, 0.0065484375000000004, 0.0087312500000000012,
	  0.0109140625, 0.013096875000000001, 0.0152796875, 0.017462500000000002,
	  0.0196453125, 0.021828125, 0.024010937500000003, 0.026193750000000002,
	  0.0283765625, 0.030559375, 0.0327421875, 0.034925000000000005, 0.0371078125,
	  0.039290625, 0.0414734375, 0.04365625, 0.045839062500000007,
	  0.048021875000000006, 0.050204687500000005, 0.052387500000000004,
	  0.0545703125, 0.056753125, 0.058935937500000007, 0.06111875, 0.0633015625,
	  0.065484375, 0.0676671875, -0.069850000000000009, -0.0676671875,
	  -0.065484375, -0.0633015625, -0.06111875, -0.058935937500000007,
	  -0.056753125, -0.0545703125, -0.052387500000000004, -0.050204687500000005,
	  -0.048021875000000006, -0.045839062500000007, -0.04365625, -0.0414734375,
	  -0.039290625, -0.0371078125, -0.034925000000000005, -0.0327421875,
	  -0.030559375, -0.0283765625, -0.026193750000000002, -0.024010937500000003,
	  -0.021828125, -0.0196453125, -0.017462500000000002, -0.0152796875,
	  -0.013096875000000001, -0.0109140625, -0.0087312500000000012,
	  -0.0065484375000000004, -0.0043656250000000006, -0.0021828125000000003, 0.0,
	  0.0021828125000000003, 0.0043656250000000006, 0.0065484375000000004,
	  0.0087312500000000012, 0.0109140625, 0.013096875000000001, 0.0152796875,
	  0.017462500000000002, 0.0196453125, 0.021828125, 0.024010937500000003,
	  0.026193750000000002, 0.0283765625, 0.030559375, 0.0327421875,
	  0.034925000000000005, 0.0371078125, 0.039290625, 0.0414734375, 0.04365625,
	  0.045839062500000007, 0.048021875000000006, 0.050204687500000005,
	  0.052387500000000004, 0.0545703125, 0.056753125, 0.058935937500000007,
	  0.06111875, 0.0633015625, 0.065484375, 0.0676671875, -0.069850000000000009,
	  -0.0676671875, -0.065484375, -0.0633015625, -0.06111875,
	  -0.058935937500000007, -0.056753125, -0.0545703125, -0.052387500000000004,
	  -0.050204687500000005, -0.048021875000000006, -0.045839062500000007,
	  -0.04365625, -0.0414734375, -0.039290625, -0.0371078125,
	  -0.034925000000000005, -0.0327421875, -0.030559375, -0.0283765625,
	  -0.026193750000000002, -0.024010937500000003, -0.021828125, -0.0196453125,
	  -0.017462500000000002, -0.0152796875, -0.013096875000000001, -0.0109140625,
	  -0.0087312500000000012, -0.0065484375000000004, -0.0043656250000000006,
	  -0.0021828125000000003, 0.0, 0.0021828125000000003, 0.0043656250000000006,
	  0.0065484375000000004, 0.0087312500000000012, 0.0109140625,
	  0.013096875000000001, 0.0152796875, 0.017462500000000002, 0.0196453125,
	  0.021828125, 0.024010937500000003, 0.026193750000000002, 0.0283765625,
	  0.030559375, 0.0327421875, 0.034925000000000005, 0.0371078125, 0.039290625,
	  0.0414734375, 0.04365625, 0.045839062500000007, 0.048021875000000006,
	  0.050204687500000005, 0.052387500000000004, 0.0545703125, 0.056753125,
	  0.058935937500000007, 0.06111875, 0.0633015625, 0.065484375, 0.0676671875,
	  -0.069850000000000009, -0.0676671875, -0.065484375, -0.0633015625,
	  -0.06111875, -0.058935937500000007, -0.056753125, -0.0545703125,
	  -0.052387500000000004, -0.050204687500000005, -0.048021875000000006,
	  -0.045839062500000007, -0.04365625, -0.0414734375, -0.039290625,
	  -0.0371078125, -0.034925000000000005, -0.0327421875, -0.030559375,
	  -0.0283765625, -0.026193750000000002, -0.024010937500000003, -0.021828125,
	  -0.0196453125, -0.017462500000000002, -0.0152796875, -0.013096875000000001,
	  -0.0109140625, -0.0087312500000000012, -0.0065484375000000004,
	  -0.0043656250000000006, -0.0021828125000000003, 0.0, 0.0021828125000000003,
	  0.0043656250000000006, 0.0065484375000000004, 0.0087312500000000012,
	  0.0109140625, 0.013096875000000001, 0.0152796875, 0.017462500000000002,
	  0.0196453125, 0.021828125, 0.024010937500000003, 0.026193750000000002,
	  0.0283765625, 0.030559375, 0.0327421875, 0.034925000000000005, 0.0371078125,
	  0.039290625, 0.0414734375, 0.04365625, 0.045839062500000007,
	  0.048021875000000006, 0.050204687500000005, 0.052387500000000004,
	  0.0545703125, 0.056753125, 0.058935937500000007, 0.06111875, 0.0633015625,
	  0.065484375, 0.0676671875, -0.069850000000000009, -0.0676671875,
	  -0.065484375, -0.0633015625, -0.06111875, -0.058935937500000007,
	  -0.056753125, -0.0545703125, -0.052387500000000004, -0.050204687500000005,
	  -0.048021875000000006, -0.045839062500000007, -0.04365625, -0.0414734375,
	  -0.039290625, -0.0371078125, -0.034925000000000005, -0.0327421875,
	  -0.030559375, -0.0283765625, -0.026193750000000002, -0.024010937500000003,
	  -0.021828125, -0.0196453125, -0.017462500000000002, -0.0152796875,
	  -0.013096875000000001, -0.0109140625, -0.0087312500000000012,
	  -0.0065484375000000004, -0.0043656250000000006, -0.0021828125000000003, 0.0,
	  0.0021828125000000003, 0.0043656250000000006, 0.0065484375000000004,
	  0.0087312500000000012, 0.0109140625, 0.013096875000000001, 0.0152796875,
	  0.017462500000000002, 0.0196453125, 0.021828125, 0.024010937500000003,
	  0.026193750000000002, 0.0283765625, 0.030559375, 0.0327421875,
	  0.034925000000000005, 0.0371078125, 0.039290625, 0.0414734375, 0.04365625,
	  0.045839062500000007, 0.048021875000000006, 0.050204687500000005,
	  0.052387500000000004, 0.0545703125, 0.056753125, 0.058935937500000007,
	  0.06111875, 0.0633015625, 0.065484375, 0.0676671875, -0.069850000000000009,
	  -0.0676671875, -0.065484375, -0.0633015625, -0.06111875,
	  -0.058935937500000007, -0.056753125, -0.0545703125, -0.052387500000000004,
	  -0.050204687500000005, -0.048021875000000006, -0.045839062500000007,
	  -0.04365625, -0.0414734375, -0.039290625, -0.0371078125,
	  -0.034925000000000005, -0.0327421875, -0.030559375, -0.0283765625,
	  -0.026193750000000002, -0.024010937500000003, -0.021828125, -0.0196453125,
	  -0.017462500000000002, -0.0152796875, -0.013096875000000001, -0.0109140625,
	  -0.0087312500000000012, -0.0065484375000000004, -0.0043656250000000006,
	  -0.0021828125000000003, 0.0, 0.0021828125000000003, 0.0043656250000000006,
	  0.0065484375000000004, 0.0087312500000000012, 0.0109140625,
	  0.013096875000000001, 0.0152796875, 0.017462500000000002, 0.0196453125,
	  0.021828125, 0.024010937500000003, 0.026193750000000002, 0.0283765625,
	  0.030559375, 0.0327421875, 0.034925000000000005, 0.0371078125, 0.039290625,
	  0.0414734375, 0.04365625, 0.045839062500000007, 0.048021875000000006,
	  0.050204687500000005, 0.052387500000000004, 0.0545703125, 0.056753125,
	  0.058935937500000007, 0.06111875, 0.0633015625, 0.065484375, 0.0676671875,
	  -0.069850000000000009, -0.0676671875, -0.065484375, -0.0633015625,
	  -0.06111875, -0.058935937500000007, -0.056753125, -0.0545703125,
	  -0.052387500000000004, -0.050204687500000005, -0.048021875000000006,
	  -0.045839062500000007, -0.04365625, -0.0414734375, -0.039290625,
	  -0.0371078125, -0.034925000000000005, -0.0327421875, -0.030559375,
	  -0.0283765625, -0.026193750000000002, -0.024010937500000003, -0.021828125,
	  -0.0196453125, -0.017462500000000002, -0.0152796875, -0.013096875000000001,
	  -0.0109140625, -0.0087312500000000012, -0.0065484375000000004,
	  -0.0043656250000000006, -0.0021828125000000003, 0.0, 0.0021828125000000003,
	  0.0043656250000000006, 0.0065484375000000004, 0.0087312500000000012,
	  0.0109140625, 0.013096875000000001, 0.0152796875, 0.017462500000000002,
	  0.0196453125, 0.021828125, 0.024010937500000003, 0.026193750000000002,
	  0.0283765625, 0.030559375, 0.0327421875, 0.034925000000000005, 0.0371078125,
	  0.039290625, 0.0414734375, 0.04365625, 0.045839062500000007,
	  0.048021875000000006, 0.050204687500000005, 0.052387500000000004,
	  0.0545703125, 0.056753125, 0.058935937500000007, 0.06111875, 0.0633015625,
	  0.065484375, 0.0676671875, -0.069850000000000009, -0.0676671875,
	  -0.065484375, -0.0633015625, -0.06111875, -0.058935937500000007,
	  -0.056753125, -0.0545703125, -0.052387500000000004, -0.050204687500000005,
	  -0.048021875000000006, -0.045839062500000007, -0.04365625, -0.0414734375,
	  -0.039290625, -0.0371078125, -0.034925000000000005, -0.0327421875,
	  -0.030559375, -0.0283765625, -0.026193750000000002, -0.024010937500000003,
	  -0.021828125, -0.0196453125, -0.017462500000000002, -0.0152796875,
	  -0.013096875000000001, -0.0109140625, -0.0087312500000000012,
	  -0.0065484375000000004, -0.0043656250000000006, -0.0021828125000000003, 0.0,
	  0.0021828125000000003, 0.0043656250000000006, 0.0065484375000000004,
	  0.0087312500000000012, 0.0109140625, 0.013096875000000001, 0.0152796875,
	  0.017462500000000002, 0.0196453125, 0.021828125, 0.024010937500000003,
	  0.026193750000000002, 0.0283765625, 0.030559375, 0.0327421875,
	  0.034925000000000005, 0.0371078125, 0.039290625, 0.0414734375, 0.04365625,
	  0.045839062500000007, 0.048021875000000006, 0.050204687500000005,
	  0.052387500000000004, 0.0545703125, 0.056753125, 0.058935937500000007,
	  0.06111875, 0.0633015625, 0.065484375, 0.0676671875, -0.069850000000000009,
	  -0.0676671875, -0.065484375, -0.0633015625, -0.06111875,
	  -0.058935937500000007, -0.056753125, -0.0545703125, -0.052387500000000004,
	  -0.050204687500000005, -0.048021875000000006, -0.045839062500000007,
	  -0.04365625, -0.0414734375, -0.039290625, -0.0371078125,
	  -0.034925000000000005, -0.0327421875, -0.030559375, -0.0283765625,
	  -0.026193750000000002, -0.024010937500000003, -0.021828125, -0.0196453125,
	  -0.017462500000000002, -0.0152796875, -0.013096875000000001, -0.0109140625,
	  -0.0087312500000000012, -0.0065484375000000004, -0.0043656250000000006,
	  -0.0021828125000000003, 0.0, 0.0021828125000000003, 0.0043656250000000006,
	  0.0065484375000000004, 0.0087312500000000012, 0.0109140625,
	  0.013096875000000001, 0.0152796875, 0.017462500000000002, 0.0196453125,
	  0.021828125, 0.024010937500000003, 0.026193750000000002, 0.0283765625,
	  0.030559375, 0.0327421875, 0.034925000000000005, 0.0371078125, 0.039290625,
	  0.0414734375, 0.04365625, 0.045839062500000007, 0.048021875000000006,
	  0.050204687500000005, 0.052387500000000004, 0.0545703125, 0.056753125,
	  0.058935937500000007, 0.06111875, 0.0633015625, 0.065484375, 0.0676671875,
	  -0.069850000000000009, -0.0676671875, -0.065484375, -0.0633015625,
	  -0.06111875, -0.058935937500000007, -0.056753125, -0.0545703125,
	  -0.052387500000000004, -0.050204687500000005, -0.048021875000000006,
	  -0.045839062500000007, -0.04365625, -0.0414734375, -0.039290625,
	  -0.0371078125, -0.034925000000000005, -0.0327421875, -0.030559375,
	  -0.0283765625, -0.026193750000000002, -0.024010937500000003, -0.021828125,
	  -0.0196453125, -0.017462500000000002, -0.0152796875, -0.013096875000000001,
	  -0.0109140625, -0.0087312500000000012, -0.0065484375000000004,
	  -0.0043656250000000006, -0.0021828125000000003, 0.0, 0.0021828125000000003,
	  0.0043656250000000006, 0.0065484375000000004, 0.0087312500000000012,
	  0.0109140625, 0.013096875000000001, 0.0152796875, 0.017462500000000002,
	  0.0196453125, 0.021828125, 0.024010937500000003, 0.026193750000000002,
	  0.0283765625, 0.030559375, 0.0327421875, 0.034925000000000005, 0.0371078125,
	  0.039290625, 0.0414734375, 0.04365625, 0.045839062500000007,
	  0.048021875000000006, 0.050204687500000005, 0.052387500000000004,
	  0.0545703125, 0.056753125, 0.058935937500000007, 0.06111875, 0.0633015625,
	  0.065484375, 0.0676671875, -0.069850000000000009, -0.0676671875,
	  -0.065484375, -0.0633015625, -0.06111875, -0.058935937500000007,
	  -0.056753125, -0.0545703125, -0.052387500000000004, -0.050204687500000005,
	  -0.048021875000000006, -0.045839062500000007, -0.04365625, -0.0414734375,
	  -0.039290625, -0.0371078125, -0.034925000000000005, -0.0327421875,
	  -0.030559375, -0.0283765625, -0.026193750000000002, -0.024010937500000003,
	  -0.021828125, -0.0196453125, -0.017462500000000002, -0.0152796875,
	  -0.013096875000000001, -0.0109140625, -0.0087312500000000012,
	  -0.0065484375000000004, -0.0043656250000000006, -0.0021828125000000003, 0.0,
	  0.0021828125000000003, 0.0043656250000000006, 0.0065484375000000004,
	  0.0087312500000000012, 0.0109140625, 0.013096875000000001, 0.0152796875,
	  0.017462500000000002, 0.0196453125, 0.021828125, 0.024010937500000003,
	  0.026193750000000002, 0.0283765625, 0.030559375, 0.0327421875,
	  0.034925000000000005, 0.0371078125, 0.039290625, 0.0414734375, 0.04365625,
	  0.045839062500000007, 0.048021875000000006, 0.050204687500000005,
	  0.052387500000000004, 0.0545703125, 0.056753125, 0.058935937500000007,
	  0.06111875, 0.0633015625, 0.065484375, 0.0676671875, -0.069850000000000009,
	  -0.0676671875, -0.065484375, -0.0633015625, -0.06111875,
	  -0.058935937500000007, -0.056753125, -0.0545703125, -0.052387500000000004,
	  -0.050204687500000005, -0.048021875000000006, -0.045839062500000007,
	  -0.04365625, -0.0414734375, -0.039290625, -0.0371078125,
	  -0.034925000000000005, -0.0327421875, -0.030559375, -0.0283765625,
	  -0.026193750000000002, -0.024010937500000003, -0.021828125, -0.0196453125,
	  -0.017462500000000002, -0.0152796875, -0.013096875000000001, -0.0109140625,
	  -0.0087312500000000012, -0.0065484375000000004, -0.0043656250000000006,
	  -0.0021828125000000003, 0.0, 0.0021828125000000003, 0.0043656250000000006,
	  0.0065484375000000004, 0.0087312500000000012, 0.0109140625,
	  0.013096875000000001, 0.0152796875, 0.017462500000000002, 0.0196453125,
	  0.021828125, 0.024010937500000003, 0.026193750000000002, 0.0283765625,
	  0.030559375, 0.0327421875, 0.034925000000000005, 0.0371078125, 0.039290625,
	  0.0414734375, 0.04365625, 0.045839062500000007, 0.048021875000000006,
	  0.050204687500000005, 0.052387500000000004, 0.0545703125, 0.056753125,
	  0.058935937500000007, 0.06111875, 0.0633015625, 0.065484375, 0.0676671875,
	  -0.069850000000000009, -0.0676671875, -0.065484375, -0.0633015625,
	  -0.06111875, -0.058935937500000007, -0.056753125, -0.0545703125,
	  -0.052387500000000004, -0.050204687500000005, -0.048021875000000006,
	  -0.045839062500000007, -0.04365625, -0.0414734375, -0.039290625,
	  -0.0371078125, -0.034925000000000005, -0.0327421875, -0.030559375,
	  -0.0283765625, -0.026193750000000002, -0.024010937500000003, -0.021828125,
	  -0.0196453125, -0.017462500000000002, -0.0152796875, -0.013096875000000001,
	  -0.0109140625, -0.0087312500000000012, -0.0065484375000000004,
	  -0.0043656250000000006, -0.0021828125000000003, 0.0, 0.0021828125000000003,
	  0.0043656250000000006, 0.0065484375000000004, 0.0087312500000000012,
	  0.0109140625, 0.013096875000000001, 0.0152796875, 0.017462500000000002,
	  0.0196453125, 0.021828125, 0.024010937500000003, 0.026193750000000002,
	  0.0283765625, 0.030559375, 0.0327421875, 0.034925000000000005, 0.0371078125,
	  0.039290625, 0.0414734375, 0.04365625, 0.045839062500000007,
	  0.048021875000000006, 0.050204687500000005, 0.052387500000000004,
	  0.0545703125, 0.056753125, 0.058935937500000007, 0.06111875, 0.0633015625,
	  0.065484375, 0.0676671875, -0.069850000000000009, -0.0676671875,
	  -0.065484375, -0.0633015625, -0.06111875, -0.058935937500000007,
	  -0.056753125, -0.0545703125, -0.052387500000000004, -0.050204687500000005,
	  -0.048021875000000006, -0.045839062500000007, -0.04365625, -0.0414734375,
	  -0.039290625, -0.0371078125, -0.034925000000000005, -0.0327421875,
	  -0.030559375, -0.0283765625, -0.026193750000000002, -0.024010937500000003,
	  -0.021828125, -0.0196453125, -0.017462500000000002, -0.0152796875,
	  -0.013096875000000001, -0.0109140625, -0.0087312500000000012,
	  -0.0065484375000000004, -0.0043656250000000006, -0.0021828125000000003, 0.0,
	  0.0021828125000000003, 0.0043656250000000006, 0.0065484375000000004,
	  0.0087312500000000012, 0.0109140625, 0.013096875000000001, 0.0152796875,
	  0.017462500000000002, 0.0196453125, 0.021828125, 0.024010937500000003,
	  0.026193750000000002, 0.0283765625, 0.030559375, 0.0327421875,
	  0.034925000000000005, 0.0371078125, 0.039290625, 0.0414734375, 0.04365625,
	  0.045839062500000007, 0.048021875000000006, 0.050204687500000005,
	  0.052387500000000004, 0.0545703125, 0.056753125, 0.058935937500000007,
	  0.06111875, 0.0633015625, 0.065484375, 0.0676671875, -0.069850000000000009,
	  -0.0676671875, -0.065484375, -0.0633015625, -0.06111875,
	  -0.058935937500000007, -0.056753125, -0.0545703125, -0.052387500000000004,
	  -0.050204687500000005, -0.048021875000000006, -0.045839062500000007,
	  -0.04365625, -0.0414734375, -0.039290625, -0.0371078125,
	  -0.034925000000000005, -0.0327421875, -0.030559375, -0.0283765625,
	  -0.026193750000000002, -0.024010937500000003, -0.021828125, -0.0196453125,
	  -0.017462500000000002, -0.0152796875, -0.013096875000000001, -0.0109140625,
	  -0.0087312500000000012, -0.0065484375000000004, -0.0043656250000000006,
	  -0.0021828125000000003, 0.0, 0.0021828125000000003, 0.0043656250000000006,
	  0.0065484375000000004, 0.0087312500000000012, 0.0109140625,
	  0.013096875000000001, 0.0152796875, 0.017462500000000002, 0.0196453125,
	  0.021828125, 0.024010937500000003, 0.026193750000000002, 0.0283765625,
	  0.030559375, 0.0327421875, 0.034925000000000005, 0.0371078125, 0.039290625,
	  0.0414734375, 0.04365625, 0.045839062500000007, 0.048021875000000006,
	  0.050204687500000005, 0.052387500000000004, 0.0545703125, 0.056753125,
	  0.058935937500000007, 0.06111875, 0.0633015625, 0.065484375, 0.0676671875,
	  -0.069850000000000009, -0.0676671875, -0.065484375, -0.0633015625,
	  -0.06111875, -0.058935937500000007, -0.056753125, -0.0545703125,
	  -0.052387500000000004, -0.050204687500000005, -0.048021875000000006,
	  -0.045839062500000007, -0.04365625, -0.0414734375, -0.039290625,
	  -0.0371078125, -0.034925000000000005, -0.0327421875, -0.030559375,
	  -0.0283765625, -0.026193750000000002, -0.024010937500000003, -0.021828125,
	  -0.0196453125, -0.017462500000000002, -0.0152796875, -0.013096875000000001,
	  -0.0109140625, -0.0087312500000000012, -0.0065484375000000004,
	  -0.0043656250000000006, -0.0021828125000000003, 0.0, 0.0021828125000000003,
	  0.0043656250000000006, 0.0065484375000000004, 0.0087312500000000012,
	  0.0109140625, 0.013096875000000001, 0.0152796875, 0.017462500000000002,
	  0.0196453125, 0.021828125, 0.024010937500000003, 0.026193750000000002,
	  0.0283765625, 0.030559375, 0.0327421875, 0.034925000000000005, 0.0371078125,
	  0.039290625, 0.0414734375, 0.04365625, 0.045839062500000007,
	  0.048021875000000006, 0.050204687500000005, 0.052387500000000004,
	  0.0545703125, 0.056753125, 0.058935937500000007, 0.06111875, 0.0633015625,
	  0.065484375, 0.0676671875, -0.069850000000000009, -0.0676671875,
	  -0.065484375, -0.0633015625, -0.06111875, -0.058935937500000007,
	  -0.056753125, -0.0545703125, -0.052387500000000004, -0.050204687500000005,
	  -0.048021875000000006, -0.045839062500000007, -0.04365625, -0.0414734375,
	  -0.039290625, -0.0371078125, -0.034925000000000005, -0.0327421875,
	  -0.030559375, -0.0283765625, -0.026193750000000002, -0.024010937500000003,
	  -0.021828125, -0.0196453125, -0.017462500000000002, -0.0152796875,
	  -0.013096875000000001, -0.0109140625, -0.0087312500000000012,
	  -0.0065484375000000004, -0.0043656250000000006, -0.0021828125000000003, 0.0,
	  0.0021828125000000003, 0.0043656250000000006, 0.0065484375000000004,
	  0.0087312500000000012, 0.0109140625, 0.013096875000000001, 0.0152796875,
	  0.017462500000000002, 0.0196453125, 0.021828125, 0.024010937500000003,
	  0.026193750000000002, 0.0283765625, 0.030559375, 0.0327421875,
	  0.034925000000000005, 0.0371078125, 0.039290625, 0.0414734375, 0.04365625,
	  0.045839062500000007, 0.048021875000000006, 0.050204687500000005,
	  0.052387500000000004, 0.0545703125, 0.056753125, 0.058935937500000007,
	  0.06111875, 0.0633015625, 0.065484375, 0.0676671875, -0.069850000000000009,
	  -0.0676671875, -0.065484375, -0.0633015625, -0.06111875,
	  -0.058935937500000007, -0.056753125, -0.0545703125, -0.052387500000000004,
	  -0.050204687500000005, -0.048021875000000006, -0.045839062500000007,
	  -0.04365625, -0.0414734375, -0.039290625, -0.0371078125,
	  -0.034925000000000005, -0.0327421875, -0.030559375, -0.0283765625,
	  -0.026193750000000002, -0.024010937500000003, -0.021828125, -0.0196453125,
	  -0.017462500000000002, -0.0152796875, -0.013096875000000001, -0.0109140625,
	  -0.0087312500000000012, -0.0065484375000000004, -0.0043656250000000006,
	  -0.0021828125000000003, 0.0, 0.0021828125000000003, 0.0043656250000000006,
	  0.0065484375000000004, 0.0087312500000000012, 0.0109140625,
	  0.013096875000000001, 0.0152796875, 0.017462500000000002, 0.0196453125,
	  0.021828125, 0.024010937500000003, 0.026193750000000002, 0.0283765625,
	  0.030559375, 0.0327421875, 0.034925000000000005, 0.0371078125, 0.039290625,
	  0.0414734375, 0.04365625, 0.045839062500000007, 0.048021875000000006,
	  0.050204687500000005, 0.052387500000000004, 0.0545703125, 0.056753125,
	  0.058935937500000007, 0.06111875, 0.0633015625, 0.065484375, 0.0676671875,
	  -0.069850000000000009, -0.0676671875, -0.065484375, -0.0633015625,
	  -0.06111875, -0.058935937500000007, -0.056753125, -0.0545703125,
	  -0.052387500000000004, -0.050204687500000005, -0.048021875000000006,
	  -0.045839062500000007, -0.04365625, -0.0414734375, -0.039290625,
	  -0.0371078125, -0.034925000000000005, -0.0327421875, -0.030559375,
	  -0.0283765625, -0.026193750000000002, -0.024010937500000003, -0.021828125,
	  -0.0196453125, -0.017462500000000002, -0.0152796875, -0.013096875000000001,
	  -0.0109140625, -0.0087312500000000012, -0.0065484375000000004,
	  -0.0043656250000000006, -0.0021828125000000003, 0.0, 0.0021828125000000003,
	  0.0043656250000000006, 0.0065484375000000004, 0.0087312500000000012,
	  0.0109140625, 0.013096875000000001, 0.0152796875, 0.017462500000000002,
	  0.0196453125, 0.021828125, 0.024010937500000003, 0.026193750000000002,
	  0.0283765625, 0.030559375, 0.0327421875, 0.034925000000000005, 0.0371078125,
	  0.039290625, 0.0414734375, 0.04365625, 0.045839062500000007,
	  0.048021875000000006, 0.050204687500000005, 0.052387500000000004,
	  0.0545703125, 0.056753125, 0.058935937500000007, 0.06111875, 0.0633015625,
	  0.065484375, 0.0676671875, -0.069850000000000009, -0.0676671875,
	  -0.065484375, -0.0633015625, -0.06111875, -0.058935937500000007,
	  -0.056753125, -0.0545703125, -0.052387500000000004, -0.050204687500000005,
	  -0.048021875000000006, -0.045839062500000007, -0.04365625, -0.0414734375,
	  -0.039290625, -0.0371078125, -0.034925000000000005, -0.0327421875,
	  -0.030559375, -0.0283765625, -0.026193750000000002, -0.024010937500000003,
	  -0.021828125, -0.0196453125, -0.017462500000000002, -0.0152796875,
	  -0.013096875000000001, -0.0109140625, -0.0087312500000000012,
	  -0.0065484375000000004, -0.0043656250000000006, -0.0021828125000000003, 0.0,
	  0.0021828125000000003, 0.0043656250000000006, 0.0065484375000000004,
	  0.0087312500000000012, 0.0109140625, 0.013096875000000001, 0.0152796875,
	  0.017462500000000002, 0.0196453125, 0.021828125, 0.024010937500000003,
	  0.026193750000000002, 0.0283765625, 0.030559375, 0.0327421875,
	  0.034925000000000005, 0.0371078125, 0.039290625, 0.0414734375, 0.04365625,
	  0.045839062500000007, 0.048021875000000006, 0.050204687500000005,
	  0.052387500000000004, 0.0545703125, 0.056753125, 0.058935937500000007,
	  0.06111875, 0.0633015625, 0.065484375, 0.0676671875 };

	int i0;
	creal_T E[4096];
	double xtmp_re;
	double r;
	double b_R_pupil[4096];
	static creal_T b_E[36864];
	static creal_T c_E[36864];
	static const double dv2[257] = { 1.0, 0.9999247018391445, 0.99969881869620425,
	  0.99932238458834954, 0.99879545620517241, 0.99811811290014918,
	  0.99729045667869021, 0.996312612182778, 0.99518472667219693,
	  0.99390697000235606, 0.99247953459871, 0.99090263542778, 0.989176509964781,
	  0.98730141815785843, 0.98527764238894122, 0.98310548743121629,
	  0.98078528040323043, 0.97831737071962765, 0.97570213003852857,
	  0.97293995220556018, 0.970031253194544, 0.96697647104485207,
	  0.96377606579543984, 0.96043051941556579, 0.95694033573220882,
	  0.95330604035419386, 0.94952818059303667, 0.94560732538052128,
	  0.94154406518302081, 0.937339011912575, 0.932992798834739,
	  0.92850608047321559, 0.92387953251128674, 0.91911385169005777,
	  0.91420975570353069, 0.90916798309052238, 0.90398929312344334,
	  0.89867446569395382, 0.89322430119551532, 0.88763962040285393,
	  0.881921264348355, 0.8760700941954066, 0.87008699110871146,
	  0.8639728561215867, 0.85772861000027212, 0.8513551931052652,
	  0.84485356524970712, 0.83822470555483808, 0.83146961230254524,
	  0.82458930278502529, 0.81758481315158371, 0.81045719825259477,
	  0.80320753148064494, 0.79583690460888357, 0.78834642762660634,
	  0.78073722857209449, 0.773010453362737, 0.765167265622459,
	  0.75720884650648457, 0.74913639452345937, 0.74095112535495922,
	  0.73265427167241282, 0.724247082951467, 0.71573082528381859,
	  0.70710678118654757, 0.69837624940897292, 0.68954054473706683,
	  0.680600997795453, 0.67155895484701833, 0.66241577759017178,
	  0.65317284295377676, 0.64383154288979139, 0.63439328416364549,
	  0.62485948814238634, 0.61523159058062682, 0.60551104140432555,
	  0.59569930449243336, 0.58579785745643886, 0.57580819141784534,
	  0.56573181078361312, 0.55557023301960218, 0.54532498842204646,
	  0.53499761988709715, 0.524589682678469, 0.51410274419322166,
	  0.50353838372571758, 0.49289819222978404, 0.48218377207912272,
	  0.47139673682599764, 0.46053871095824, 0.44961132965460654,
	  0.43861623853852766, 0.42755509343028208, 0.41642956009763715,
	  0.40524131400498986, 0.3939920400610481, 0.38268343236508978,
	  0.37131719395183749, 0.35989503653498811, 0.34841868024943456,
	  0.33688985339222005, 0.32531029216226293, 0.31368174039889152,
	  0.30200594931922808, 0.29028467725446233, 0.27851968938505306,
	  0.26671275747489837, 0.25486565960451457, 0.24298017990326387,
	  0.23105810828067111, 0.2191012401568698, 0.20711137619221856,
	  0.19509032201612825, 0.18303988795514095, 0.17096188876030122,
	  0.15885814333386145, 0.14673047445536175, 0.13458070850712617,
	  0.1224106751992162, 0.11022220729388306, 0.0980171403295606,
	  0.0857973123444399, 0.073564563599667426, 0.061320736302208578,
	  0.049067674327418015, 0.036807222941358832, 0.024541228522912288,
	  0.012271538285719925, 0.0, -0.012271538285719925, -0.024541228522912288,
	  -0.036807222941358832, -0.049067674327418015, -0.061320736302208578,
	  -0.073564563599667426, -0.0857973123444399, -0.0980171403295606,
	  -0.11022220729388306, -0.1224106751992162, -0.13458070850712617,
	  -0.14673047445536175, -0.15885814333386145, -0.17096188876030122,
	  -0.18303988795514095, -0.19509032201612825, -0.20711137619221856,
	  -0.2191012401568698, -0.23105810828067111, -0.24298017990326387,
	  -0.25486565960451457, -0.26671275747489837, -0.27851968938505306,
	  -0.29028467725446233, -0.30200594931922808, -0.31368174039889152,
	  -0.32531029216226293, -0.33688985339222005, -0.34841868024943456,
	  -0.35989503653498811, -0.37131719395183749, -0.38268343236508978,
	  -0.3939920400610481, -0.40524131400498986, -0.41642956009763715,
	  -0.42755509343028208, -0.43861623853852766, -0.44961132965460654,
	  -0.46053871095824, -0.47139673682599764, -0.48218377207912272,
	  -0.49289819222978404, -0.50353838372571758, -0.51410274419322166,
	  -0.524589682678469, -0.53499761988709715, -0.54532498842204646,
	  -0.55557023301960218, -0.56573181078361312, -0.57580819141784534,
	  -0.58579785745643886, -0.59569930449243336, -0.60551104140432555,
	  -0.61523159058062682, -0.62485948814238634, -0.63439328416364549,
	  -0.64383154288979139, -0.65317284295377676, -0.66241577759017178,
	  -0.67155895484701833, -0.680600997795453, -0.68954054473706683,
	  -0.69837624940897292, -0.70710678118654757, -0.71573082528381859,
	  -0.724247082951467, -0.73265427167241282, -0.74095112535495922,
	  -0.74913639452345937, -0.75720884650648457, -0.765167265622459,
	  -0.773010453362737, -0.78073722857209449, -0.78834642762660634,
	  -0.79583690460888357, -0.80320753148064494, -0.81045719825259477,
	  -0.81758481315158371, -0.82458930278502529, -0.83146961230254524,
	  -0.83822470555483808, -0.84485356524970712, -0.8513551931052652,
	  -0.85772861000027212, -0.8639728561215867, -0.87008699110871146,
	  -0.8760700941954066, -0.881921264348355, -0.88763962040285393,
	  -0.89322430119551532, -0.89867446569395382, -0.90398929312344334,
	  -0.90916798309052238, -0.91420975570353069, -0.91911385169005777,
	  -0.92387953251128674, -0.92850608047321559, -0.932992798834739,
	  -0.937339011912575, -0.94154406518302081, -0.94560732538052128,
	  -0.94952818059303667, -0.95330604035419386, -0.95694033573220882,
	  -0.96043051941556579, -0.96377606579543984, -0.96697647104485207,
	  -0.970031253194544, -0.97293995220556018, -0.97570213003852857,
	  -0.97831737071962765, -0.98078528040323043, -0.98310548743121629,
	  -0.98527764238894122, -0.98730141815785843, -0.989176509964781,
	  -0.99090263542778, -0.99247953459871, -0.99390697000235606,
	  -0.99518472667219693, -0.996312612182778, -0.99729045667869021,
	  -0.99811811290014918, -0.99879545620517241, -0.99932238458834954,
	  -0.99969881869620425, -0.9999247018391445, -1.0 };

	static const double dv3[257] = { 0.0, -0.012271538285719925,
	  -0.024541228522912288, -0.036807222941358832, -0.049067674327418015,
	  -0.061320736302208578, -0.073564563599667426, -0.0857973123444399,
	  -0.0980171403295606, -0.11022220729388306, -0.1224106751992162,
	  -0.13458070850712617, -0.14673047445536175, -0.15885814333386145,
	  -0.17096188876030122, -0.18303988795514095, -0.19509032201612825,
	  -0.20711137619221856, -0.2191012401568698, -0.23105810828067111,
	  -0.24298017990326387, -0.25486565960451457, -0.26671275747489837,
	  -0.27851968938505306, -0.29028467725446233, -0.30200594931922808,
	  -0.31368174039889152, -0.32531029216226293, -0.33688985339222005,
	  -0.34841868024943456, -0.35989503653498811, -0.37131719395183749,
	  -0.38268343236508978, -0.3939920400610481, -0.40524131400498986,
	  -0.41642956009763715, -0.42755509343028208, -0.43861623853852766,
	  -0.44961132965460654, -0.46053871095824, -0.47139673682599764,
	  -0.48218377207912272, -0.49289819222978404, -0.50353838372571758,
	  -0.51410274419322166, -0.524589682678469, -0.53499761988709715,
	  -0.54532498842204646, -0.55557023301960218, -0.56573181078361312,
	  -0.57580819141784534, -0.58579785745643886, -0.59569930449243336,
	  -0.60551104140432555, -0.61523159058062682, -0.62485948814238634,
	  -0.63439328416364549, -0.64383154288979139, -0.65317284295377676,
	  -0.66241577759017178, -0.67155895484701833, -0.680600997795453,
	  -0.68954054473706683, -0.69837624940897292, -0.70710678118654757,
	  -0.71573082528381859, -0.724247082951467, -0.73265427167241282,
	  -0.74095112535495922, -0.74913639452345937, -0.75720884650648457,
	  -0.765167265622459, -0.773010453362737, -0.78073722857209449,
	  -0.78834642762660634, -0.79583690460888357, -0.80320753148064494,
	  -0.81045719825259477, -0.81758481315158371, -0.82458930278502529,
	  -0.83146961230254524, -0.83822470555483808, -0.84485356524970712,
	  -0.8513551931052652, -0.85772861000027212, -0.8639728561215867,
	  -0.87008699110871146, -0.8760700941954066, -0.881921264348355,
	  -0.88763962040285393, -0.89322430119551532, -0.89867446569395382,
	  -0.90398929312344334, -0.90916798309052238, -0.91420975570353069,
	  -0.91911385169005777, -0.92387953251128674, -0.92850608047321559,
	  -0.932992798834739, -0.937339011912575, -0.94154406518302081,
	  -0.94560732538052128, -0.94952818059303667, -0.95330604035419386,
	  -0.95694033573220882, -0.96043051941556579, -0.96377606579543984,
	  -0.96697647104485207, -0.970031253194544, -0.97293995220556018,
	  -0.97570213003852857, -0.97831737071962765, -0.98078528040323043,
	  -0.98310548743121629, -0.98527764238894122, -0.98730141815785843,
	  -0.989176509964781, -0.99090263542778, -0.99247953459871,
	  -0.99390697000235606, -0.99518472667219693, -0.996312612182778,
	  -0.99729045667869021, -0.99811811290014918, -0.99879545620517241,
	  -0.99932238458834954, -0.99969881869620425, -0.9999247018391445, -1.0,
	  -0.9999247018391445, -0.99969881869620425, -0.99932238458834954,
	  -0.99879545620517241, -0.99811811290014918, -0.99729045667869021,
	  -0.996312612182778, -0.99518472667219693, -0.99390697000235606,
	  -0.99247953459871, -0.99090263542778, -0.989176509964781,
	  -0.98730141815785843, -0.98527764238894122, -0.98310548743121629,
	  -0.98078528040323043, -0.97831737071962765, -0.97570213003852857,
	  -0.97293995220556018, -0.970031253194544, -0.96697647104485207,
	  -0.96377606579543984, -0.96043051941556579, -0.95694033573220882,
	  -0.95330604035419386, -0.94952818059303667, -0.94560732538052128,
	  -0.94154406518302081, -0.937339011912575, -0.932992798834739,
	  -0.92850608047321559, -0.92387953251128674, -0.91911385169005777,
	  -0.91420975570353069, -0.90916798309052238, -0.90398929312344334,
	  -0.89867446569395382, -0.89322430119551532, -0.88763962040285393,
	  -0.881921264348355, -0.8760700941954066, -0.87008699110871146,
	  -0.8639728561215867, -0.85772861000027212, -0.8513551931052652,
	  -0.84485356524970712, -0.83822470555483808, -0.83146961230254524,
	  -0.82458930278502529, -0.81758481315158371, -0.81045719825259477,
	  -0.80320753148064494, -0.79583690460888357, -0.78834642762660634,
	  -0.78073722857209449, -0.773010453362737, -0.765167265622459,
	  -0.75720884650648457, -0.74913639452345937, -0.74095112535495922,
	  -0.73265427167241282, -0.724247082951467, -0.71573082528381859,
	  -0.70710678118654757, -0.69837624940897292, -0.68954054473706683,
	  -0.680600997795453, -0.67155895484701833, -0.66241577759017178,
	  -0.65317284295377676, -0.64383154288979139, -0.63439328416364549,
	  -0.62485948814238634, -0.61523159058062682, -0.60551104140432555,
	  -0.59569930449243336, -0.58579785745643886, -0.57580819141784534,
	  -0.56573181078361312, -0.55557023301960218, -0.54532498842204646,
	  -0.53499761988709715, -0.524589682678469, -0.51410274419322166,
	  -0.50353838372571758, -0.49289819222978404, -0.48218377207912272,
	  -0.47139673682599764, -0.46053871095824, -0.44961132965460654,
	  -0.43861623853852766, -0.42755509343028208, -0.41642956009763715,
	  -0.40524131400498986, -0.3939920400610481, -0.38268343236508978,
	  -0.37131719395183749, -0.35989503653498811, -0.34841868024943456,
	  -0.33688985339222005, -0.32531029216226293, -0.31368174039889152,
	  -0.30200594931922808, -0.29028467725446233, -0.27851968938505306,
	  -0.26671275747489837, -0.25486565960451457, -0.24298017990326387,
	  -0.23105810828067111, -0.2191012401568698, -0.20711137619221856,
	  -0.19509032201612825, -0.18303988795514095, -0.17096188876030122,
	  -0.15885814333386145, -0.14673047445536175, -0.13458070850712617,
	  -0.1224106751992162, -0.11022220729388306, -0.0980171403295606,
	  -0.0857973123444399, -0.073564563599667426, -0.061320736302208578,
	  -0.049067674327418015, -0.036807222941358832, -0.024541228522912288,
	  -0.012271538285719925, -0.0 };

	static const double dv4[257] = { 0.0, 0.012271538285719925,
	  0.024541228522912288, 0.036807222941358832, 0.049067674327418015,
	  0.061320736302208578, 0.073564563599667426, 0.0857973123444399,
	  0.0980171403295606, 0.11022220729388306, 0.1224106751992162,
	  0.13458070850712617, 0.14673047445536175, 0.15885814333386145,
	  0.17096188876030122, 0.18303988795514095, 0.19509032201612825,
	  0.20711137619221856, 0.2191012401568698, 0.23105810828067111,
	  0.24298017990326387, 0.25486565960451457, 0.26671275747489837,
	  0.27851968938505306, 0.29028467725446233, 0.30200594931922808,
	  0.31368174039889152, 0.32531029216226293, 0.33688985339222005,
	  0.34841868024943456, 0.35989503653498811, 0.37131719395183749,
	  0.38268343236508978, 0.3939920400610481, 0.40524131400498986,
	  0.41642956009763715, 0.42755509343028208, 0.43861623853852766,
	  0.44961132965460654, 0.46053871095824, 0.47139673682599764,
	  0.48218377207912272, 0.49289819222978404, 0.50353838372571758,
	  0.51410274419322166, 0.524589682678469, 0.53499761988709715,
	  0.54532498842204646, 0.55557023301960218, 0.56573181078361312,
	  0.57580819141784534, 0.58579785745643886, 0.59569930449243336,
	  0.60551104140432555, 0.61523159058062682, 0.62485948814238634,
	  0.63439328416364549, 0.64383154288979139, 0.65317284295377676,
	  0.66241577759017178, 0.67155895484701833, 0.680600997795453,
	  0.68954054473706683, 0.69837624940897292, 0.70710678118654757,
	  0.71573082528381859, 0.724247082951467, 0.73265427167241282,
	  0.74095112535495922, 0.74913639452345937, 0.75720884650648457,
	  0.765167265622459, 0.773010453362737, 0.78073722857209449,
	  0.78834642762660634, 0.79583690460888357, 0.80320753148064494,
	  0.81045719825259477, 0.81758481315158371, 0.82458930278502529,
	  0.83146961230254524, 0.83822470555483808, 0.84485356524970712,
	  0.8513551931052652, 0.85772861000027212, 0.8639728561215867,
	  0.87008699110871146, 0.8760700941954066, 0.881921264348355,
	  0.88763962040285393, 0.89322430119551532, 0.89867446569395382,
	  0.90398929312344334, 0.90916798309052238, 0.91420975570353069,
	  0.91911385169005777, 0.92387953251128674, 0.92850608047321559,
	  0.932992798834739, 0.937339011912575, 0.94154406518302081,
	  0.94560732538052128, 0.94952818059303667, 0.95330604035419386,
	  0.95694033573220882, 0.96043051941556579, 0.96377606579543984,
	  0.96697647104485207, 0.970031253194544, 0.97293995220556018,
	  0.97570213003852857, 0.97831737071962765, 0.98078528040323043,
	  0.98310548743121629, 0.98527764238894122, 0.98730141815785843,
	  0.989176509964781, 0.99090263542778, 0.99247953459871, 0.99390697000235606,
	  0.99518472667219693, 0.996312612182778, 0.99729045667869021,
	  0.99811811290014918, 0.99879545620517241, 0.99932238458834954,
	  0.99969881869620425, 0.9999247018391445, 1.0, 0.9999247018391445,
	  0.99969881869620425, 0.99932238458834954, 0.99879545620517241,
	  0.99811811290014918, 0.99729045667869021, 0.996312612182778,
	  0.99518472667219693, 0.99390697000235606, 0.99247953459871, 0.99090263542778,
	  0.989176509964781, 0.98730141815785843, 0.98527764238894122,
	  0.98310548743121629, 0.98078528040323043, 0.97831737071962765,
	  0.97570213003852857, 0.97293995220556018, 0.970031253194544,
	  0.96697647104485207, 0.96377606579543984, 0.96043051941556579,
	  0.95694033573220882, 0.95330604035419386, 0.94952818059303667,
	  0.94560732538052128, 0.94154406518302081, 0.937339011912575,
	  0.932992798834739, 0.92850608047321559, 0.92387953251128674,
	  0.91911385169005777, 0.91420975570353069, 0.90916798309052238,
	  0.90398929312344334, 0.89867446569395382, 0.89322430119551532,
	  0.88763962040285393, 0.881921264348355, 0.8760700941954066,
	  0.87008699110871146, 0.8639728561215867, 0.85772861000027212,
	  0.8513551931052652, 0.84485356524970712, 0.83822470555483808,
	  0.83146961230254524, 0.82458930278502529, 0.81758481315158371,
	  0.81045719825259477, 0.80320753148064494, 0.79583690460888357,
	  0.78834642762660634, 0.78073722857209449, 0.773010453362737,
	  0.765167265622459, 0.75720884650648457, 0.74913639452345937,
	  0.74095112535495922, 0.73265427167241282, 0.724247082951467,
	  0.71573082528381859, 0.70710678118654757, 0.69837624940897292,
	  0.68954054473706683, 0.680600997795453, 0.67155895484701833,
	  0.66241577759017178, 0.65317284295377676, 0.64383154288979139,
	  0.63439328416364549, 0.62485948814238634, 0.61523159058062682,
	  0.60551104140432555, 0.59569930449243336, 0.58579785745643886,
	  0.57580819141784534, 0.56573181078361312, 0.55557023301960218,
	  0.54532498842204646, 0.53499761988709715, 0.524589682678469,
	  0.51410274419322166, 0.50353838372571758, 0.49289819222978404,
	  0.48218377207912272, 0.47139673682599764, 0.46053871095824,
	  0.44961132965460654, 0.43861623853852766, 0.42755509343028208,
	  0.41642956009763715, 0.40524131400498986, 0.3939920400610481,
	  0.38268343236508978, 0.37131719395183749, 0.35989503653498811,
	  0.34841868024943456, 0.33688985339222005, 0.32531029216226293,
	  0.31368174039889152, 0.30200594931922808, 0.29028467725446233,
	  0.27851968938505306, 0.26671275747489837, 0.25486565960451457,
	  0.24298017990326387, 0.23105810828067111, 0.2191012401568698,
	  0.20711137619221856, 0.19509032201612825, 0.18303988795514095,
	  0.17096188876030122, 0.15885814333386145, 0.14673047445536175,
	  0.13458070850712617, 0.1224106751992162, 0.11022220729388306,
	  0.0980171403295606, 0.0857973123444399, 0.073564563599667426,
	  0.061320736302208578, 0.049067674327418015, 0.036807222941358832,
	  0.024541228522912288, 0.012271538285719925, 0.0 };

	// focal plane sampling in meters
	// wavelength in meters
	// meters; 1 inch
	// meters
	// Calculate pupil plane sampling
	// Pupil normalized to aperture diameter
	// Complex amplitude
	trueCount = 0;
	for (k = 0; k < 4096; k++) {
		R_pupil = std::sqrt(dv0[k] * dv0[k] + dv1[k] * dv1[k]) / 0.0127;
		E[k].re = W[k] * 0.0;
		E[k].im = W[k] * 6.2831853071795862;
		if (E[k].im == 0.0) {
			xtmp_re = std::exp(E[k].re);
			r = 0.0;
		}
		else if (rtIsInf_psf(E[k].im) && rtIsInf_psf(E[k].re) && (E[k].re < 0.0)) {
			xtmp_re = 0.0;
			r = 0.0;
		}
		else {
			r = std::exp(E[k].re / 2.0);
			xtmp_re = r * (r * std::cos(E[k].im));
			r *= r * std::sin(E[k].im);
		}

		E[k].re = xtmp_re;
		E[k].im = r;
		if (R_pupil > 4.0) {
			trueCount++;
		}

		b_R_pupil[k] = R_pupil;
	}

	emxInit_int32_T_psf(&r0, 1);
	i0 = r0->size[0];
	r0->size[0] = trueCount;
	emxEnsureCapacity_int32_T_psf(r0, i0);
	k = 0;
	for (trueCount = 0; trueCount < 4096; trueCount++) {
		if (b_R_pupil[trueCount] > 4.0) {
			r0->data[k] = trueCount + 1;
			k++;
		}
	}

	k = r0->size[0];
	for (i0 = 0; i0 < k; i0++) {
		E[r0->data[i0] - 1].re = 0.0;
		E[r0->data[i0] - 1].im = 0.0;
	}

	emxFree_int32_T_psf(&r0);

	// Impose aperture size
	for (k = 0; k < 64; k++) {
		for (trueCount = 0; trueCount < 192; trueCount++) {
			b_E[trueCount + 192 * k].re = 0.0;
			b_E[trueCount + 192 * k].im = 0.0;
			b_E[trueCount + 192 * (k + 128)].re = 0.0;
			b_E[trueCount + 192 * (k + 128)].im = 0.0;
		}

		for (trueCount = 0; trueCount < 64; trueCount++) {
			b_E[trueCount + 192 * (k + 64)].re = 0.0;
			b_E[trueCount + 192 * (k + 64)].im = 0.0;
			b_E[(trueCount + 192 * (k + 64)) + 128].re = 0.0;
			b_E[(trueCount + 192 * (k + 64)) + 128].im = 0.0;
			b_E[(trueCount + 192 * (k + 64)) + 64] = E[trueCount + (k << 6)];
		}
	}

	for (k = 0; k < 2; k++) {
		eml_fftshift(b_E, k + 1);
	}

	for (i0 = 0; i0 < 192; i0++) {
		for (k = 0; k < 192; k++) {
			c_E[k + 192 * i0] = b_E[i0 + 192 * k];
		}
	}

	dobluesteinfft(c_E, dv2, dv3, dv4, b_E);
	for (i0 = 0; i0 < 192; i0++) {
		for (k = 0; k < 192; k++) {
			c_E[k + 192 * i0] = b_E[i0 + 192 * k];
		}
	}

	dobluesteinfft(c_E, dv2, dv3, dv4, b_E);
	for (k = 0; k < 2; k++) {
		eml_fftshift(b_E, k + 1);
	}

	for (k = 0; k < 36864; k++) {
		r = rt_hypotd_snf(b_E[k].re, b_E[k].im);
		PSF_final[k] = r * r;
	}

	r = PSF_final[0];
	for (k = 0; k < 36863; k++) {
		r += PSF_final[k + 1];
	}

	for (i0 = 0; i0 < 36864; i0++) {
		PSF_final[i0] /= r;
	}

	// Normalize to unity energy
	// x_psf = (-fix(N/2):fix((N-1)/2)) * psf_sampling;
}

//
// File trailer for psf_function.cpp
//
// [EOF]
//


// Variable Definitions
omp_nest_lock_t emlrtNestLockGlobal_psf;

//
// File trailer for psf_function_data.cpp
//
// [EOF]
//

// Function Definitions

//
// Arguments    : emxArray_int32_T *emxArray
//                int oldNumel
// Return Type  : void
//
void emxEnsureCapacity_int32_T_psf(emxArray_int32_T *emxArray, int oldNumel)
{
	int newNumel;
	int i;
	void *newData;
	if (oldNumel < 0) {
		oldNumel = 0;
	}

	newNumel = 1;
	for (i = 0; i < emxArray->numDimensions; i++) {
		newNumel *= emxArray->size[i];
	}

	if (newNumel > emxArray->allocatedSize) {
		i = emxArray->allocatedSize;
		if (i < 16) {
			i = 16;
		}

		while (i < newNumel) {
			if (i > 1073741823) {
				i = MAX_int32_T;
			}
			else {
				i <<= 1;
			}
		}

		newData = calloc((unsigned int)i, sizeof(int));
		if (emxArray->data != NULL) {
			memcpy(newData, (void *)emxArray->data, sizeof(int) * oldNumel);
			if (emxArray->canFreeData) {
				free((void *)emxArray->data);
			}
		}

		emxArray->data = (int *)newData;
		emxArray->allocatedSize = i;
		emxArray->canFreeData = true;
	}
}

//
// Arguments    : emxArray_int32_T **pEmxArray
// Return Type  : void
//
void emxFree_int32_T_psf(emxArray_int32_T **pEmxArray)
{
	if (*pEmxArray != (emxArray_int32_T *)NULL) {
		if (((*pEmxArray)->data != (int *)NULL) && (*pEmxArray)->canFreeData) {
			free((void *)(*pEmxArray)->data);
		}

		free((void *)(*pEmxArray)->size);
		free((void *)*pEmxArray);
		*pEmxArray = (emxArray_int32_T *)NULL;
	}
}

//
// Arguments    : emxArray_int32_T **pEmxArray
//                int numDimensions
// Return Type  : void
//

void emxInit_int32_T_psf(emxArray_int32_T **pEmxArray, int numDimensions)
{
	emxArray_int32_T *emxArray;
	int i;
	*pEmxArray = (emxArray_int32_T *)malloc(sizeof(emxArray_int32_T));
	emxArray = *pEmxArray;
	emxArray->data = (int *)NULL;
	emxArray->numDimensions = numDimensions;
	emxArray->size = (int *)malloc(sizeof(int) * numDimensions);
	emxArray->allocatedSize = 0;
	emxArray->canFreeData = true;
	for (i = 0; i < numDimensions; i++) {
		emxArray->size[i] = 0;
	}
}

//
// File trailer for psf_function_emxutil.cpp
//
// [EOF]
//

// Function Definitions

//
// Arguments    : void
// Return Type  : void
//
void psf_function_initialize()
{
	rt_InitInfAndNaN_psf(8U);
	omp_init_nest_lock(&emlrtNestLockGlobal_psf);
}

//
// File trailer for psf_function_initialize.cpp
//
// [EOF]
//
// Function Definitions

//
// Arguments    : void
// Return Type  : void
//
void psf_function_terminate()
{
	omp_destroy_nest_lock(&emlrtNestLockGlobal_psf);
}

//
// File trailer for psf_function_terminate.cpp
//
// [EOF]
//

/*real_T rtInf_psf;
real_T rtMinusInf_psf;
real_T rtNaN_psf;
real32_T rtInfF_psf;
real32_T rtMinusInfF_psf;
real32_T rtNaNF_psf;*/

/* Function: rt_InitInfAndNaN ==================================================
 * Abstract:
 * Initialize the rtInf, rtMinusInf, and rtNaN needed by the
 * generated code. NaN is initialized as non-signaling. Assumes IEEE.
 */
void rt_InitInfAndNaN_psf(size_t realSize)
{
	(void)realSize;
	rtNaN_psf = std::numeric_limits<real_T>::quiet_NaN();
	rtNaNF_psf = std::numeric_limits<real32_T>::quiet_NaN();
	rtInf_psf = std::numeric_limits<real_T>::infinity();
	rtInfF_psf = std::numeric_limits<real32_T>::infinity();
	rtMinusInf_psf = -std::numeric_limits<real_T>::infinity();
	rtMinusInfF_psf = -std::numeric_limits<real32_T>::infinity();
}

/* Function: rtIsInf ==================================================
 * Abstract:
 * Test if value is infinite
 */
boolean_T rtIsInf_psf(real_T value)
{
	return ((value == rtInf_psf || value == rtMinusInf_psf) ? 1U : 0U);
}

/* Function: rtIsInfF =================================================
 * Abstract:
 * Test if single-precision value is infinite
 */
boolean_T rtIsInfF_psf(real32_T value)
{
	return(((value) == rtInfF_psf || (value) == rtMinusInfF_psf) ? 1U : 0U);
}

/* Function: rtIsNaN ==================================================
 * Abstract:
 * Test if value is not a number
 */
boolean_T rtIsNaN_psf(real_T value)
{
	return (value != value) ? 1U : 0U;
}

/* Function: rtIsNaNF =================================================
 * Abstract:
 * Test if single-precision value is not a number
 */
boolean_T rtIsNaNF_psf(real32_T value)
{
	return (value != value) ? 1U : 0U;
}

/*
 * File trailer for rt_nonfinite.cpp
 *
 * [EOF]
 */

 /* Function: rtGetInf ==================================================
  * Abstract:
  * Initialize rtInf needed by the generated code.
  */
real_T rtGetInf_psf(void)
{
	return rtInf_psf;
}

/* Function: rtGetInfF ==================================================
 * Abstract:
 * Initialize rtInfF needed by the generated code.
 */
real32_T rtGetInfF_psf(void)
{
	return rtInfF_psf;
}

/* Function: rtGetMinusInf ==================================================
 * Abstract:
 * Initialize rtMinusInf needed by the generated code.
 */
real_T rtGetMinusInf_psf(void)
{
	return rtMinusInf_psf;
}

/* Function: rtGetMinusInfF ==================================================
 * Abstract:
 * Initialize rtMinusInfF needed by the generated code.
 */
real32_T rtGetMinusInfF_psf(void)
{
	return rtMinusInfF_psf;
}

/*
 * File trailer for rtGetInf.cpp
 *
 * [EOF]
 */

 /* Function: rtGetNaN ==================================================
  * Abstract:
  * Initialize rtNaN needed by the generated code.
  * NaN is initialized as non-signaling. Assumes IEEE.
  */
real_T rtGetNaN_psf(void)
{
	return rtNaN_psf;
}

/* Function: rtGetNaNF ==================================================
 * Abstract:
 * Initialize rtNaNF needed by the generated code.
 * NaN is initialized as non-signaling. Assumes IEEE.
 */
real32_T rtGetNaNF_psf(void)
{
	return rtNaNF_psf;
}

/*
 * File trailer for rtGetNaN.cpp
 *
 * [EOF]
 */
 // Function Declarations
static void argInit_64x64_real_T(double result[4096]);
static double argInit_real_T();
void main_psf_function(cv::Mat mGlobalOPD, static double Sim_PSF);

// Function Definitions

//
// Arguments    : double result[4096]
// Return Type  : void
//
static void argInit_64x64_real_T(double result[4096])
{
	int idx0;
	int idx1;

	// Loop over the array to initialize each element.
	for (idx0 = 0; idx0 < 64; idx0++) {
		for (idx1 = 0; idx1 < 64; idx1++) {
			// Set the value of the array element.
			// Change this value to the value that the application requires.
			result[idx0 + (idx1 << 6)] = argInit_real_T();
		}
	}
}

//
// Arguments    : void
// Return Type  : double
//
static double argInit_real_T()
{
	return 0.0;
}

//
// Arguments    : void
// Return Type  : void
//
void main_psf_function(cv::Mat mGlobalOPD, static double Sim_PSF[36864])
{

	double W[4096];
	static double PSF_final[36864];



	for (int i = 0; i < 4096; i++)
	{
		int j = i % 64;
		int k = i / 64;
		W[i] = mGlobalOPD.at<double>(j, k);
	}


	psf_function(W, PSF_final);

	for (int i = 0; i < 36864; i++)
	{
		Sim_PSF[i] = PSF_final[i];
	}
	//return PSF_final;
}

//
// Arguments    : int argc
//                const char * const argv[]
// Return Type  : int
//
/*
int main(int, const char * const[])
{
	// Initialize the application.
	// You do not need to do this more than one time.
	//psf_function_initialize();

	// Invoke the entry-point functions.
	// You can call entry-point functions multiple times.
	//main_psf_function();

	// Terminate the application.
	// You do not need to do this more than one time.
	//psf_function_terminate();
	return 0;
}
*/

//
// File trailer for main.cpp
//
// [EOF]
//



//Calculate Huygens PSF
cv::Mat OPD::calcHuygenPSF()
{
	psf_function_initialize();

	// Invoke the entry-point functions.
	// You can call entry-point functions multiple times.

		//get OPD of 64 x 64
	double N = 64;

	double ratio = (double)(mGlobalOPD.cols - 1) / (double)(N - 1);
	cv::Mat mGlobalOPD_high = cv::Mat::zeros(N, N, CV_64F);

	for (int i = 0; i < N; i++) 
	{
		for (int j = 0; j < N; j++) {
			int fx = std::floor((double)(i)*ratio);
			int fy = std::floor((double)(j)*ratio);
			int cx = ceil((double)(i)*ratio);
			int cy = ceil((double)(j)*ratio);
			double actualX = double(i)*ratio;
			double actualY = double(j)*ratio;


			mGlobalOPD_high.at<double>(i, j) = bilinear_interpolator(mGlobalOPD.at<double>(fx, fy), mGlobalOPD.at<double>(fx, cy),
				mGlobalOPD.at<double>(cx, fy), mGlobalOPD.at<double>(cx, cy),
				fx, cx, fy, cy,
				actualX, actualY);
		}
	}

	static double Sim_PSF[36864];

	main_psf_function(mGlobalOPD_high, Sim_PSF);


	cv::Mat mat_PSF = cv::Mat::zeros(192, 192, CV_64F);
	for (int i = 0; i < 192; i++)
	{
		for (int j = 0; j < 192; j++)
		{
			int k = i * 192 + j;
			mat_PSF.at<double>(i, j) = Sim_PSF[k];
		}
	}

	std::ofstream outData;
	outData.open("D:\Thisisitman.csv", std::ios::app);
	outData << mat_PSF << std::endl;



	//get PSF of 128x128
	N = 128;
	ratio = (double)(mat_PSF.cols - 1) / (double)(N - 1);
	cv::Mat mHuygenPSF = cv::Mat::zeros(N, N, CV_64F);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int fx = floor((double)(i)*ratio);
			int fy = floor((double)(j)*ratio);
			int cx = ceil((double)(i)*ratio);
			int cy = ceil((double)(j)*ratio);
			double actualX = double(i)*ratio;
			double actualY = double(j)*ratio;


			mHuygenPSF.at<double>(i, j) = bilinear_interpolator(mat_PSF.at<double>(fx, fy), mat_PSF.at<double>(fx, cy),
				mat_PSF.at<double>(cx, fy), mat_PSF.at<double>(cx, cy), fx, cx, fy, cy, actualX, actualY);
		}
	}


	cv::Mat display;
	if (mHuygenPSF.empty())
	{
		std::cout << "image not loaded";
	}
	else
	{
		mHuygenPSF.convertTo(display, CV_8UC1, 255.0 / 0.001, 0);
		applyColorMap(display, display, cv::COLORMAP_JET);
		cv::imshow("PSF", display);
		cv::waitKey(0);
	}
	//psf_function_terminate();
	return mHuygenPSF;
}

