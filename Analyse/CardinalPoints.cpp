#include "CardinalPoints.h"
#include <typeinfo>
#include <iostream>

#include "..\RayAiming\RayAiming.h"
#include "..\OptimizeSystem\calculateParaxialDistances.h"
#include "..\oftenUseNamespace\oftenUseNamespace.h"

CardinalPoints::CardinalPoints() { loadAndResizeParameters(); };
CardinalPoints::CardinalPoints(OpticalSystem_LLT OptSys, objectPoint_inf_obj objPoint_inf_obj) :
	mOpticalSystem_LLT(OptSys),
	mObjectPoint_inf_obj(objPoint_inf_obj)
{
	loadAndResizeParameters();
	calcSystemMatrix();

	mEFL = calcEFL();
	mPP_obj = calcPP_obj();
	mPP_ima = calcPP_ima();
	mEXPP_lastSurface = calcEXPP_lastSurface();
	mEXPP_inGlobalCoordi = calcEXPP_globalCoordi();
	mEXPD = calcEXPD();
	mMag = calcMagnification();
	mNA_objSpac = calcNA_objSpac();
	mENPP_firstSurface = calcENPP_firstSurface();
	mENPP_inGlobalCoodi = calcENPP_globalCoordi();
	mENPD = calcENPD();
	mF_number_imaSpace = calcFnumberImaSpace();
	mNA_imaSpace = calcNA_imaSpace();
	mWFNO = calcWFNO();
};

CardinalPoints::CardinalPoints(OpticalSystemElement optSysEle, real primWavelenght, objectPoint_inf_obj objPoint_inf_obj) :
	mOpticalSystem_Ele(optSysEle),
	mPrimWavelength(primWavelenght),
	mObjectPoint_inf_obj(objPoint_inf_obj)
{

	mOpticalSystem_Ele.setRefractiveIndexAccordingToWavelength(primWavelenght);
	mOpticalSystem_LLT = mOpticalSystem_Ele.getLLTconversion_doConversion();

	loadAndResizeParameters();
	calcSystemMatrix();

	mEFL = calcEFL();
	mPP_obj = calcPP_obj();
	mPP_ima = calcPP_ima();
	mEXPP_lastSurface = calcEXPP_lastSurface();
	mEXPP_inGlobalCoordi = calcEXPP_globalCoordi();
	mEXPD = calcEXPD();
	mMag = calcMagnification();
	mNA_objSpac = calcNA_objSpac();
	mENPP_firstSurface = calcENPP_firstSurface();
	mENPP_inGlobalCoodi = calcENPP_globalCoordi();
	mENPD = calcENPD();
	mF_number_imaSpace = calcFnumberImaSpace();
	mNA_imaSpace = calcNA_imaSpace();
	mWFNO = calcWFNO();
}

CardinalPoints::~CardinalPoints() {};


// get the EFL
real CardinalPoints::getEFL()
{
	return mEFL;
}
// get position principal plain
real CardinalPoints::getPP_obj()
{
	return mPP_obj;
}
// get ecit pupil position
real CardinalPoints::getEXPP_lastSurface()
{
	return mEXPP_lastSurface;
}

// get ecit pupil position
real CardinalPoints::getEXPP_globalCoori()
{
	return mEXPP_inGlobalCoordi;
}

// get EcitPupilDiameter
real CardinalPoints::getEXPD()
{
	return mEXPD;
}
//get magnification of the system
real CardinalPoints::getMagnification()
{
	return mMag;
}

// get anti principelplane
real CardinalPoints::getPP_ima()
{
	return mPP_ima;
}

// entrace pupil position first surface
real CardinalPoints::getENPP_firstSurface()
{
	return mENPP_firstSurface;
}
// entrance pupil position global coordi
real CardinalPoints::getENPP_globalCoodi()
{
	return mENPP_inGlobalCoodi;
}
// entrance pupil diameter
real CardinalPoints::getENPD()
{
	return mENPD;
}
// get f number
real CardinalPoints::getF_num_imaSpace()
{
	return mF_number_imaSpace;
}
// NA image space
real CardinalPoints::getNA_imaSpace()
{
	return mNA_imaSpace;
}
// working f number
real CardinalPoints::getWorkingFnumber()
{
	return mWFNO;
}

void CardinalPoints::loadAndResizeParameters()
{
	mSizeOfOpt = mOpticalSystem_LLT.getPosAndInteractingSurface().size();
	mPosAndInteraSurfaceVector = mOpticalSystem_LLT.getPosAndInteractingSurface();
	mPositionApertureStop = mOpticalSystem_LLT.getInforAS().getPosAS();
	mSizeOfOptSysMinOne = mSizeOfOpt - 1;
	mSizeOfOptSysMinTwo = mSizeOfOpt - 2;
	mSizeAfterStop = mSizeOfOpt - mPositionApertureStop;

	//// resize
	mAllRadius.resize(mSizeOfOptSysMinOne);
	mAllRefractivIndexes.resize(mSizeOfOptSysMinOne);
	mAllRefractivIndexes_dash.resize(mSizeOfOptSysMinOne);
	mAllThickness_vec.resize(mSizeOfOptSysMinTwo);
	mAllSystemMatrix.resize(4);

	// NA 
	mStartPointRayToCalcNA_obj = { 0.0,0.0,0.0 };
}

void CardinalPoints::calcSystemMatrix()
{

	// ALL
	/**/calcAllRadius();
	/**/calcAllSepSur();
	/**/calcAllRefractivIndexes();
	/**/calcSepSurAndImPlane();
	//calcSepObjandSurface();


	/**/calcDiameterAperture();

	calcAllSystemMatrix();
}







// calculate the separation oflast surface and image plane
void CardinalPoints::calcSepSurAndImPlane()
{
	mSepSurAndImPlane = mOpticalSystem_LLT.getPosAndInteractingSurface().at(mSizeOfOptSysMinOne).getSurfaceInterRay_ptr()->getPoint().getZ() - mOpticalSystem_LLT.getPosAndInteractingSurface().at(mSizeOfOptSysMinOne - 1).getSurfaceInterRay_ptr()->getPoint().getZ();
}



// calculate aperture size
void CardinalPoints::calcDiameterAperture()
{
	mDiameterOfApertureStop = 2.0 * mPosAndInteraSurfaceVector[mPositionApertureStop].getSurfaceInterRay_ptr()->getSemiHeight();
}


// calculate the EFL ot the optical system
real CardinalPoints::calcEFL()
{

	return -1.0 / (mSystemMatrix_vec[2]);

}

// calculat the global principal plan of the optical system
real CardinalPoints::calcPP_obj()
{
	real PP_obj = (mSystemMatrix_vec[3] - 1) / (mSystemMatrix_vec[2]);

	if (mPositionApertureStop == 0)
	{
		real thicknessAperStopSecondSurface = mPosAndInteraSurfaceVector[1].getSurfaceInterRay_ptr()->getPoint().getZ() - mPosAndInteraSurfaceVector[0].getSurfaceInterRay_ptr()->getPoint().getZ();
		PP_obj = PP_obj + thicknessAperStopSecondSurface;
	}

	return PP_obj;
}

// calculat the global anti principal plan of the optical syste
real CardinalPoints::calcPP_ima()
{
	return -(mSystemMatrix_vec[0] - 1) / mSystemMatrix_vec[2];
}

//calculate the exit Pupul position
real CardinalPoints::calcEXPP_lastSurface()
{
	if (mPositionApertureStop == mSizeOfOptSysMinTwo)
	{
		return mPosAndInteraSurfaceVector[mPositionApertureStop].getSurfaceInterRay_ptr()->getPoint().getZ() - mPosAndInteraSurfaceVector[mSizeOfOptSysMinOne].getSurfaceInterRay_ptr()->getPoint().getZ();
	}

	//std::vector<PosAndIntsectionSurfaceStruct> posAndInteraSurfaceBeforeApertureStop_vec(mPositionApertureStop);
	std::shared_ptr<SurfaceIntersectionRay_LLT> tempSurfacePointer{};
	real tempDirection_Z{};

	std::vector<real> distances_vec_afterAS(mSizeAfterStop - 1);
	std::vector<real> radii_vec_afterAS(mSizeAfterStop - 1);
	std::vector<real> refIndex_vec_afterAS(mSizeAfterStop - 1);
	std::vector<real> refIndex_dash_vec_afterAS(mSizeAfterStop - 1);
	std::vector<real> f_dash_vec_afterAS(mSizeAfterStop - 1);

	mS_afterAS.resize(mSizeAfterStop - 1);
	mS_dash_afterAS.resize(mSizeAfterStop - 1);

	unsigned int posInVec = 0;
	
	for (unsigned int i = mPositionApertureStop + 1; i < mSizeOfOpt; ++i)
	{
		tempSurfacePointer = mPosAndInteraSurfaceVector[i].getSurfaceInterRay_ptr();
		distances_vec_afterAS[posInVec] = tempSurfacePointer->getPoint().getZ() - mPosAndInteraSurfaceVector[i - 1].getSurfaceInterRay_ptr()->getPoint().getZ();
		radii_vec_afterAS[posInVec] = tempSurfacePointer->getRadius();
		tempDirection_Z = tempSurfacePointer->getDirection().getZ();

		if (tempDirection_Z > 0)
		{
			radii_vec_afterAS[posInVec] = tempSurfacePointer->getRadius();;
			refIndex_vec_afterAS[posInVec] = tempSurfacePointer->getRefractiveIndex_A();
			refIndex_dash_vec_afterAS[posInVec] = tempSurfacePointer->getRefractiveIndex_B();
			f_dash_vec_afterAS[posInVec] = refIndex_dash_vec_afterAS[posInVec] * radii_vec_afterAS[posInVec] / (refIndex_dash_vec_afterAS[posInVec] - refIndex_vec_afterAS[posInVec]);
		}

		else
		{
			radii_vec_afterAS[posInVec] = -1.0 * tempSurfacePointer->getRadius();
			refIndex_vec_afterAS[posInVec] = tempSurfacePointer->getRefractiveIndex_B();
			refIndex_dash_vec_afterAS[posInVec] = tempSurfacePointer->getRefractiveIndex_A();
			f_dash_vec_afterAS[posInVec] = refIndex_dash_vec_afterAS[posInVec] * radii_vec_afterAS[posInVec] / (refIndex_dash_vec_afterAS[posInVec] - refIndex_vec_afterAS[posInVec]);
		}
		++posInVec;
	}

	// calc s and s_dash
	mS_dash_afterAS[0] = 0.0;
	real tempS_dash{};
	for (unsigned int i = 0; i < posInVec; ++i)
	{
		mS_afterAS[i] = -1.0 * (distances_vec_afterAS[i] - tempS_dash);
		mS_dash_afterAS[i] = refIndex_dash_vec_afterAS[i] / (refIndex_dash_vec_afterAS[i] / f_dash_vec_afterAS[i] + refIndex_vec_afterAS[i] / mS_afterAS[i]);
		tempS_dash = mS_dash_afterAS[i];
	}


	real EXPP = mS_dash_afterAS.back();

	return EXPP;
}


// calculate the diameter of the exit pupil of the optical system
real CardinalPoints::calcEXPD()
{
	if (mPositionApertureStop == mSizeOfOptSysMinTwo)
	{
		return mDiameterOfApertureStop;
	}

	real magAperStop_right = 1.0;

	unsigned int size = mS_dash_afterAS.size();
	for (unsigned int i = 0; i < size; ++i)
	{
		magAperStop_right = magAperStop_right * mS_dash_afterAS[i] / mS_afterAS[i];
	}

	return std::abs(mDiameterOfApertureStop * magAperStop_right);
}


real CardinalPoints::calcMagnification()
{
	real mag = 1.0;

	if (objectPoint_inf_obj::obj == mObjectPoint_inf_obj)
	{
		CalculateParaxialDistances calcParaDis(mOpticalSystem_LLT, notInfinity, 550.0);

		std::vector<real> s_vec = calcParaDis.getAll_S();
		std::vector<real> s_dash_vec = calcParaDis.getAll_S_dash();
		unsigned int size = s_dash_vec.size();
	
		for (unsigned int i = 0; i < size; ++i)
		{
			mag = mag * s_dash_vec[i] / s_vec[i];
		}
	}

	else
	{
		return 0.0;
	}
	
	return mag;
}

// calc pos exit pupil gloabl coordinates
real CardinalPoints::calcEXPP_globalCoordi()
{
	real posZ_lastSurface = mPosAndInteraSurfaceVector[mSizeOfOptSysMinOne].getSurfaceInterRay_ptr()->getPoint().getZ();

	return posZ_lastSurface + mEXPP_lastSurface;
}

// calc numerical aperture
real CardinalPoints::calcNA_objSpac()
{
	real NA_obj{};

	if (mObjectPoint_inf_obj == objectPoint_inf_obj::obj)
	{
		RayAiming rayAiming(mOpticalSystem_LLT);
		rayAiming.turn_On_RobustRayAiming();

		VectorStructR3 pointApertureStop = mPosAndInteraSurfaceVector[mPositionApertureStop].getSurfaceInterRay_ptr()->getPoint();
		real semiHeightAperStop = mPosAndInteraSurfaceVector[mPositionApertureStop].getSurfaceInterRay_ptr()->getSemiHeight();
		VectorStructR3 vec = { 0.0,semiHeightAperStop, 0.0 };
		VectorStructR3 targetPointRay = pointApertureStop + vec;
		Light_LLT defaulLight = oftenUse::getDefaultLight();
		LightRayStruct lightRay = rayAiming.rayAiming_obj(mStartPointRayToCalcNA_obj, targetPointRay, defaulLight, 1.0);

		VectorStructR3 directionRayUnit = lightRay.getRay_LLT().getDirectionRayUnit();

		real z = directionRayUnit.getZ();
		real y = directionRayUnit.getY();

		real angel = std::atan(y / z);
		NA_obj = mAllRefractivIndexes[0] * std::abs(std::sin(angel));
	}

	else // mObjectPoint_inf_obj == inf
	{
		NA_obj = 0;
	}

	return NA_obj;
}

// calc NA image space
real CardinalPoints::calcNA_imaSpace()
{
	real NA_ima{};

	RayAiming rayAiming(mOpticalSystem_LLT);
	rayAiming.turn_On_RobustRayAiming();

	VectorStructR3 pointApertureStop = mPosAndInteraSurfaceVector[mPositionApertureStop].getSurfaceInterRay_ptr()->getPoint();
	real semiHeightAperStop = mPosAndInteraSurfaceVector[mPositionApertureStop].getSurfaceInterRay_ptr()->getSemiHeight();
	VectorStructR3 vec = { 0.0,semiHeightAperStop, 0.0 };
	VectorStructR3 targetPointRay = pointApertureStop + vec;
	Light_LLT defaulLight = oftenUse::getDefaultLight();

	LightRayStruct marginalLightRay;
	if (mObjectPoint_inf_obj == objectPoint_inf_obj::obj)
	{
		marginalLightRay = rayAiming.rayAiming_obj(mStartPointRayToCalcNA_obj, targetPointRay, defaulLight, 1.0);
	}

	else
	{
		marginalLightRay = rayAiming.rayAiming_inf({ 0.0,0.0,1.0 }, targetPointRay, defaulLight, 1.0);

	}

	SequentialRayTracing seqTrace(mOpticalSystem_LLT);
	seqTrace.sequentialRayTracing(marginalLightRay);

	// check if the ray at the last surface is still alive
	unsigned int sizeRealInterPoints = seqTrace.getAllIntersectionPointsSRT().size();
	VectorStructR3 directionRayUnitAtLastSurface{};

	if (sizeRealInterPoints == mSizeOfOpt)
	{
		directionRayUnitAtLastSurface = seqTrace.getAllInterInfosOfSurf_i(mSizeOfOptSysMinOne)[0].getDirectionRayUnit();
	}

	else
	{
		return 51818018.0; // ERROR
	}


	real z = directionRayUnitAtLastSurface.getZ();
	real y = directionRayUnitAtLastSurface.getY();

	real angel = std::atan(y / z);
	NA_ima = mAllRefractivIndexes.back() * std::abs(std::sin(y / z));


	return NA_ima;
}

real CardinalPoints::calcWFNO()
{
	return 1 / (2 * mNA_imaSpace);
}

void CardinalPoints::calcAllRadius()
{
	real tempRadius;
	real tempDirectionZ;
	int sign;
	unsigned int posInVec = 0;

	for (unsigned int i = 0; i < mSizeOfOpt; i++)
	{
		if (typeid(*mPosAndInteraSurfaceVector.at(i).getSurfaceInterRay_ptr()) != typeid(mApertureStop))
		{
			tempRadius = mOpticalSystem_LLT.getPosAndInteractingSurface().at(i).getSurfaceInterRay_ptr()->getRadius();
			tempDirectionZ = mOpticalSystem_LLT.getPosAndInteractingSurface().at(i).getSurfaceInterRay_ptr()->getDirection().getZ();

			sign = 1;
			if (tempDirectionZ < 0)
			{
				sign = -1;
			}
			mAllRadius[posInVec] = sign * tempRadius;
			++posInVec;
		}


	}

}


void CardinalPoints::calcAllRefractivIndexes()
{
	real tempRefIndex;
	real tempRefIndex_dash;
	real tempDirectionZ;
	std::shared_ptr<SurfaceIntersectionRay_LLT> tempSurface_prt{};
	unsigned int posInVec = 0;

	for (unsigned int i = 0; i < mSizeOfOpt; i++)
	{
		if (typeid(*mPosAndInteraSurfaceVector.at(i).getSurfaceInterRay_ptr()) != typeid(mApertureStop))
		{

			tempDirectionZ = mPosAndInteraSurfaceVector[i].getSurfaceInterRay_ptr()->getDirection().getZ();


			if (tempDirectionZ > 0)
			{
				mAllRefractivIndexes[posInVec] = mPosAndInteraSurfaceVector[i].getSurfaceInterRay_ptr()->getRefractiveIndex_A();
				mAllRefractivIndexes_dash[posInVec] = mPosAndInteraSurfaceVector[i].getSurfaceInterRay_ptr()->getRefractiveIndex_B();
				

			}
			else if (tempDirectionZ < 0)
			{
				mAllRefractivIndexes[posInVec] = mPosAndInteraSurfaceVector[i].getSurfaceInterRay_ptr()->getRefractiveIndex_B();
				mAllRefractivIndexes_dash[posInVec] = mPosAndInteraSurfaceVector[i].getSurfaceInterRay_ptr()->getRefractiveIndex_A();

			}
			else
			{
				std::cout << "there is an mistake in the direction!!! the Z value is 0!!!" << std::endl;

			}

			++posInVec;

		}

	}


}

void CardinalPoints::calcAllSepSur()
{
	real tempZ_Pos;
	unsigned int posInVec = 0;

	for (unsigned int i = 0; i < mSizeOfOptSysMinOne; i++)
	{
		if (typeid(*mPosAndInteraSurfaceVector.at(i).getSurfaceInterRay_ptr()) != typeid(mApertureStop))
		{
			if (typeid(*mPosAndInteraSurfaceVector.at(i + 1).getSurfaceInterRay_ptr()) != typeid(mApertureStop))
			{
				tempZ_Pos = mOpticalSystem_LLT.getPosAndInteractingSurface().at(i + 1).getSurfaceInterRay_ptr()->getPoint().getZ() - mOpticalSystem_LLT.getPosAndInteractingSurface().at(i).getSurfaceInterRay_ptr()->getPoint().getZ();
				mAllThickness_vec[posInVec] = tempZ_Pos;

			}
			else
			{
				tempZ_Pos = mOpticalSystem_LLT.getPosAndInteractingSurface().at(i + 2).getSurfaceInterRay_ptr()->getPoint().getZ() - mOpticalSystem_LLT.getPosAndInteractingSurface().at(i).getSurfaceInterRay_ptr()->getPoint().getZ();
				mAllThickness_vec[posInVec] = tempZ_Pos;

			}
			++posInVec;
		}

	}

}

std::vector<real> CardinalPoints::calcVecTimesVec(std::vector<real> const vec1, std::vector<real> const vec2)
{
	std::vector<real> retunVec(4);

	retunVec[0] = vec1[0] * vec2[0] + vec1[1] * vec2[2];
	retunVec[1] = vec1[0] * vec2[1] + vec1[1] * vec2[3];
	retunVec[2] = vec1[2] * vec2[0] + vec1[3] * vec2[2];
	retunVec[3] = vec1[2] * vec2[1] + vec1[3] * vec2[3];

	return retunVec;
}

void CardinalPoints::calcAllSystemMatrix()
{

	mSystemMatrix_vec.resize(4);
	mSystemMatrix_vec[0] = 1.0;
	mSystemMatrix_vec[2] = 1.0;

	std::vector<real> propagate(4);
	propagate[0] = 1.0;
	propagate[1] = 999.0;
	propagate[2] = 0.0;
	propagate[3] = 1.0;

	std::vector<real> refract(4);
	refract[0] = 1.0;
	refract[1] = 0.0;
	refract[2] = 999.0;
	refract[3] = 999.0;

	bool swichPropagatRefract = true;

	unsigned int counter = 0;

	mSystemMatrix_vec[0] = 1.0;
	mSystemMatrix_vec[1] = 0.0;
	mSystemMatrix_vec[2] = (mAllRefractivIndexes[counter] - mAllRefractivIndexes_dash[counter]) / (mAllRadius[counter] * mAllRefractivIndexes_dash[counter]);
	mSystemMatrix_vec[3] = mAllRefractivIndexes[counter] / mAllRefractivIndexes_dash[counter];

	for (unsigned int i = 0; i < 2*mSizeOfOptSysMinTwo; i++)
	{
		if (swichPropagatRefract) // propagate
		{
			propagate[1] = mAllThickness_vec[counter];
			mSystemMatrix_vec = calcVecTimesVec(propagate ,mSystemMatrix_vec);

			swichPropagatRefract = false;
			++counter;
		}

		else // refaction
		{
			refract[2] = (mAllRefractivIndexes[counter] - mAllRefractivIndexes_dash[counter]) / (mAllRadius[counter] * mAllRefractivIndexes_dash[counter]);
			refract[3] = mAllRefractivIndexes[counter] / mAllRefractivIndexes_dash[counter];
			mSystemMatrix_vec = calcVecTimesVec(refract, mSystemMatrix_vec);

			swichPropagatRefract = true;
		}
	}

}

real CardinalPoints::calcENPP_firstSurface()
{

	if (mPositionApertureStop == 0) // entrance pupil is aperture stop
	{
		return 0;
	}

	//std::vector<PosAndIntsectionSurfaceStruct> posAndInteraSurfaceBeforeApertureStop_vec(mPositionApertureStop);
	std::shared_ptr<SurfaceIntersectionRay_LLT> tempSurfacePointer{};
	real tempDirection_Z{};

	std::vector<real> distances_vec_BAS_rot(mPositionApertureStop);
	std::vector<real> radii_vec_BAS_rot(mPositionApertureStop);
	std::vector<real> refIndex_vec_BAS_rot(mPositionApertureStop);
	std::vector<real> refIndex_vec_dash_BAS_rot(mPositionApertureStop);
	std::vector<real> f_dash_vec_BAS_rot(mPositionApertureStop);

	mS_beforeAS_rot.resize(mPositionApertureStop);
	mS_dash_beforeAS_rot.resize(mPositionApertureStop);

	for (unsigned int i = 0; i < mPositionApertureStop; ++i)
	{
		//posAndInteraSurfaceBeforeApertureStop_vec[i] = mPosAndInteraSurfaceVector[i].clone();
		tempSurfacePointer = mPosAndInteraSurfaceVector[mPositionApertureStop - 1 - i].getSurfaceInterRay_ptr();
		distances_vec_BAS_rot[i] = mPosAndInteraSurfaceVector[mPositionApertureStop - i].getSurfaceInterRay_ptr()->getPoint().getZ() - tempSurfacePointer->getPoint().getZ();
		radii_vec_BAS_rot[i] = tempSurfacePointer->getRadius();
		tempDirection_Z = tempSurfacePointer->getDirection().getZ();

		if (tempDirection_Z > 0)
		{
			radii_vec_BAS_rot[i] = -1.0 * tempSurfacePointer->getRadius();;
			refIndex_vec_BAS_rot[i] = tempSurfacePointer->getRefractiveIndex_B();
			refIndex_vec_dash_BAS_rot[i] = tempSurfacePointer->getRefractiveIndex_A();
			f_dash_vec_BAS_rot[i] = refIndex_vec_dash_BAS_rot[i] * radii_vec_BAS_rot[i] / (refIndex_vec_dash_BAS_rot[i] - refIndex_vec_BAS_rot[i]);
		}

		else
		{
			radii_vec_BAS_rot[i] = tempSurfacePointer->getRadius();
			refIndex_vec_BAS_rot[i] = tempSurfacePointer->getRefractiveIndex_A();
			refIndex_vec_dash_BAS_rot[i] = tempSurfacePointer->getRefractiveIndex_B();
			f_dash_vec_BAS_rot[i] = refIndex_vec_dash_BAS_rot[i] * radii_vec_BAS_rot[i] / (refIndex_vec_dash_BAS_rot[i] - refIndex_vec_BAS_rot[i]);
		}

	}

	// calc s and s_dash
	mS_dash_beforeAS_rot[0] = 0.0;
	real tempS_dash{};
	for (unsigned int i = 0; i < mPositionApertureStop; ++i)
	{
		mS_beforeAS_rot[i] = -1.0 * (distances_vec_BAS_rot[i] - tempS_dash);
		mS_dash_beforeAS_rot[i] = refIndex_vec_dash_BAS_rot[i] / (refIndex_vec_dash_BAS_rot[i] / f_dash_vec_BAS_rot[i] + refIndex_vec_BAS_rot[i] / mS_beforeAS_rot[i]);
		tempS_dash = mS_dash_beforeAS_rot[i];
	}


	


	return -1.0 * mS_dash_beforeAS_rot.back();

}

real CardinalPoints::calcENPP_globalCoordi()
{
	return mPosAndInteraSurfaceVector[0].getSurfaceInterRay_ptr()->getPoint().getZ() + mENPP_firstSurface;
}

// calc entrance pupil diameter 
real CardinalPoints::calcENPD()
{
	if (mPositionApertureStop == 0) // entrance pupil is aperture stop
	{
		return mDiameterOfApertureStop;
	}

	real magAperStop_left = 1.0;
	for (unsigned int i = 0; i < mPositionApertureStop; ++i)
	{
		magAperStop_left = magAperStop_left * mS_dash_beforeAS_rot[i] / mS_beforeAS_rot[i];			
	}

	return std::abs(mDiameterOfApertureStop * magAperStop_left);

}
// calc f number
real CardinalPoints::calcFnumberImaSpace()
{
	return std::abs(mEFL / mENPD);
}

real CardinalPoints::getNA_objSpace()
{
	return mNA_objSpac;
}

void CardinalPoints::setObjectPoint(objectPoint_inf_obj point_inf_obj)
{
	mObjectPoint_inf_obj = point_inf_obj;
}