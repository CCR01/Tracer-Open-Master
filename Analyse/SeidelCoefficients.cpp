#include "Seidel Coefficients.h"
#include <math.h>
#include "..\SurfaceElements\ApertureStopElement.h"
#include "..\LowLevelTracing\SurfaceIntersectionRay_LLT.h"
#include "..\LowLevelTracing\Surfaces\ApertureStop_LLT.h"

SeidelCoefficients::SeidelCoefficients() {}

SeidelCoefficients::~SeidelCoefficients() {}

SeidelCoefficients::SeidelCoefficients(OpticalSystemElement opticalSys_Ele, LightRayStruct chefLightRay, LightRayStruct marginalLightRay, std::vector<real> wavelenght_vec, unsigned int posAperStop, real focalLength, real lagrangeInvariant, bool aperInlens) :
	mOpticalSys_Ele(opticalSys_Ele),
	mChiefLightRay(chefLightRay),
	mMarginalLightRay(marginalLightRay),
	mWavelength_vec(wavelenght_vec),
	mPosApertureStop(posAperStop),
	mFocalLenght(focalLength),
	mLagrangeInvariant(lagrangeInvariant),
	mAperInLens(aperInlens)

{
	//calcCardinalPoints();

	buildOptSysWithoutApertureStop();

	setOpticalSys_Ele();

	setRefractiveIndexesAccordingToPrimWavelength();
	calcOneByR();
	calculateD();
	calculate_RelevantValuesForSeidel();
	///calcLagrangeInvariant();
	calculate_h_bar();

	//calculate_A_bar();
	calculateRefIndexAtSurface();
	calcE();
	calcA_bar();
	calcMeanRefIndex();
	findMinAndMaxRefIndex();
	calcDeltaNandU_wavelength();
	calculateOnebyN();
	calculateDeltaUandN();
	calculateS1();
	calculateS2();
	calculateS3();
	calculateS4();
	calculateS5();
	calculateS6_C1();
	calculateS7_C2();

	calcSumS1();
	calcSumS2();
	calcSumS3();
	calcSumS4();
	calcSumS5();
	calcSumS6_C1();
	calcSumS7_C2();
}

void SeidelCoefficients::calcSeidelCoef_superFuction(OpticalSystemElement opticalSys_Ele, LightRayStruct chefLightRay, LightRayStruct marginalLightRay, std::vector<real> wavelenght_vec, unsigned int posAperStop, real focalLength, real lagrangeInvariant, bool aperInlens)
{

	mOpticalSys_Ele = opticalSys_Ele.getDeepCopyOptSysEle();
	mChiefLightRay = chefLightRay;
	mMarginalLightRay = marginalLightRay;
	mWavelength_vec = wavelenght_vec;
	mPosApertureStop = posAperStop;
	mFocalLenght = focalLength;
	mLagrangeInvariant = lagrangeInvariant;
	mAperInLens = aperInlens;

	//calcCardinalPoints();

	buildOptSysWithoutApertureStop();

	setOpticalSys_Ele();

	setRefractiveIndexesAccordingToPrimWavelength();
	calcOneByR();
	calculateD();
	calculate_RelevantValuesForSeidel();
	///calcLagrangeInvariant();
	calculate_h_bar();

	//calculate_A_bar();
	calculateRefIndexAtSurface();
	calcE();
	calcA_bar();
	calcMeanRefIndex();
	findMinAndMaxRefIndex();
	calcDeltaNandU_wavelength();
	calculateOnebyN();
	calculateDeltaUandN();
	calculateS1();
	calculateS2();
	calculateS3();
	calculateS4();
	calculateS5();
	calculateS6_C1();
	calculateS7_C2();

	calcSumS1();
	calcSumS2();
	calcSumS3();
	calcSumS4();
	calcSumS5();
	calcSumS6_C1();
	calcSumS7_C2();

}

void SeidelCoefficients::setOpticalSys_Ele()
{

	if (mAperInLens)
	{
		mOpticalSys_Ele_USE = mOpticalSys_Ele_WithoutApertureStop;
	}

	else
	{
		mOpticalSys_Ele_USE = mOpticalSys_Ele;
	}

}




void SeidelCoefficients::setPosApertureStop(unsigned int posApertureStop)
{
	mPosApertureStop = posApertureStop;
}

void SeidelCoefficients::calcE()
{
	real tempE;
	real tempEplusOne = 0;
	unsigned int sizeOptSys = mOpticalSys_Ele_USE.getPosAndElement().size();

	real posAperMode = mPosApertureStop;

	if (mAperInLens == false)
	{
		posAperMode++;
	}


	for (unsigned int i = posAperMode; i < sizeOptSys - 1; i++)
	{
		tempE = -mD.at(i) / (mRefIndex_vec.at(i).at(0) * mh_vec.at(i - 1) * mh_vec.at(i)) + tempEplusOne;
		mE_afterStop_vec.push_back(tempE);
		tempEplusOne = tempE;
	}

	tempEplusOne = 0;
	for (unsigned int i = posAperMode; i > 1; i--)
	{
		tempE = mD.at(i - 1) / (mRefIndex_vec.at(i - 1).at(0) * mh_vec.at(i - 1) * mh_vec.at(i - 2)) + tempEplusOne;
		mE_beforeStop_vec.push_back(tempE);
		tempEplusOne = tempE;
	}

	unsigned int size = mE_beforeStop_vec.size() + mE_afterStop_vec.size();
	mE.resize(size + 1);

	for (unsigned int i = 1; i < mE_beforeStop_vec.size() + 1; i++)
	{
		mE.at(i - 1) = mE_beforeStop_vec.at(mE_beforeStop_vec.size() - i);
	}

	for (unsigned int i = 0; i < mE_afterStop_vec.size(); i++)
	{
		mE.at(i + mE_beforeStop_vec.size() + 1) = mE_afterStop_vec.at(i);
	}




}


void SeidelCoefficients::calcA_bar()
{
	unsigned int size = mE.size();
	real tempA_bar;

	for (unsigned int i = 0; i < size; i++)
	{
		tempA_bar = mLagrangeInvariant / mh_vec.at(i) * (mA_vec.at(i) * mh_vec.at(i)*mE.at(i) - 1);
		mA_bar_vec.push_back(tempA_bar);
	}

}

void SeidelCoefficients::setRefractiveIndexesAccordingToPrimWavelength()
{
	unsigned int sizeOptSys = mOpticalSys_Ele_USE.getPosAndElement().size();

	for (unsigned int i = 0; i < sizeOptSys; i++)
	{
		mOpticalSys_Ele_USE.getPosAndElement().at(i).getElementInOptSys_ptr()->calRefIndex_A_and_B_andSet(mWavelength_vec.at(0));
	}
}

void SeidelCoefficients::calcCardinalPoints()
{
	mCardinalPoints = CardinalPoints(mOpticalSys_Ele_USE.getLLTconversion_doConversion(), objectPoint_inf_obj::obj);
	mFocalLenght = mCardinalPoints.getEFL();
}

void SeidelCoefficients::buildOptSysWithoutApertureStop()
{
	unsigned int lengthOptSys = mOpticalSys_Ele.getPosAndElement().size();

	std::shared_ptr<SurfaceIntersectionRay_LLT> tempInteSurface_LLT;
	std::shared_ptr<InteractionRay_LLT> tempInteraction_ptr;

	ApertureStop_LLT apertureStop;
	int counter = 0;

	for (unsigned int i = 0; i < lengthOptSys; i++)
	{
		//if (typeid(*posAndInteraSurfaceVector.at(i).getSurfaceInterRay_ptr()) == typeid(apertureStop))
		tempInteSurface_LLT = mOpticalSys_Ele.getPosAndIntersection_LLT().at(i).getSurfaceInterRay_ptr();

		if (typeid(*tempInteSurface_LLT) == typeid(apertureStop))
		{

		}
		else
		{

			tempInteraction_ptr = mOpticalSys_Ele.getPosAndInteraction_LLT()[i].getInteractionAtSur_ptr();
			mOpticalSys_Ele_WithoutApertureStop.fillPosAndElementAndInteraction(counter, mOpticalSys_Ele.getPosAndElement().at(i).getElementInOptSys_ptr(), tempInteraction_ptr);
			counter++;
		}

	}

	mOpticalSys_Ele_WithoutApertureStop.convertHLTtoLLT();
}

///void SeidelCoefficients::calcLagrangeInvariant()
//{
//	SequentialRayTracing mSeqTraceChief(/*optical system element*/ mOpticalSys_Ele_USE, mChiefLightRay);
//	//unsigned int size = mOpticalSys_Ele_USE.getPosAndElement().size();
//
//
//	VectorStructR3 DirectionChief = mSeqTraceChief.getAllInterInfosOfSurf_i(0).at(0).getDirectionRayUnit();
//
//
//	real angle = atan(DirectionChief.getY() / DirectionChief.getZ());
//
//	//mLagrangeInvariant = mN_dash_vec.back() * mU_dash_vec.back() * mFocalLenght * tan(angle);
//	//mLagrangeInvariant = mN_dash_vec.back() * mU_dash_vec.back() * mh_bar_vec.back();
//
//}

void SeidelCoefficients::calcOneByR()
{
	unsigned int lengthOptSys = mOpticalSys_Ele_USE.getPosAndElement().size();
	real tempOneByR;

	for (unsigned int i = 0; i < lengthOptSys; i++)
	{
		tempOneByR = 1 / mOpticalSys_Ele_USE.getPosAndIntersection_LLT()[i].getSurfaceInterRay_ptr()->getRadius();
		mOneByRadius_C_vec.push_back(tempOneByR);
	}
}


void SeidelCoefficients::calculateD()
{

	real positionDistance = mOpticalSys_Ele_USE.getPosAndElement().at(0).getElementInOptSys_ptr()->getPointElementValue_Z();
	real vectorSum = 0;
	mD.push_back(positionDistance);

	for (unsigned int i = 1; i < mOpticalSys_Ele_USE.getPosAndElement().size(); i++)
	{
		vectorSum = vectorSum + positionDistance;

		positionDistance = mOpticalSys_Ele_USE.getPosAndElement().at(i).getElementInOptSys_ptr()->getPointElementValue_Z() - vectorSum;
		mD.push_back(positionDistance);
	}




}

std::vector<real> SeidelCoefficients::getall_S1()
{
	return mS1_vec;
}

// calculate the spherical seidel coefficients
void SeidelCoefficients::calculate_RelevantValuesForSeidel()
{
	SequentialRayTracing seqTracMarginalRay(/*optical system element*/ mOpticalSys_Ele_USE, mMarginalLightRay);
	unsigned int lengthOptSys = mOpticalSys_Ele_USE.getPosAndElement().size();
	real tempHeight;
	real tempRefractiveIndex_N;
	real tempRefractiveIndex_N_dash;
	real tempIncidenceAngle;
	real tempOutAngle_dash;
	real tempDeltaAngleRefraction;
	real SeidelCoef1;
	real tempOneByRadius_C;

	IntersectInformationStruct interInfosFirstSurface;
	real tempDirectionSurface;
	VectorStructR3 tempIncidenceVecFirstSurface;
	VectorStructR3 tempOutVec_dash;

	real tempA;



	interInfosFirstSurface = seqTracMarginalRay.getAllInterInfosOfSurf_i(0).at(0);
	tempIncidenceVecFirstSurface = interInfosFirstSurface.getDirectionRayUnit();
	tempIncidenceAngle = tempIncidenceVecFirstSurface.getY() / tempIncidenceVecFirstSurface.getZ();
	//tempIncidenceAngle = 0.82;
	tempHeight = interInfosFirstSurface.getIntersectionPoint().getY();
	for (unsigned int i = 0; i < lengthOptSys - 1; i++)
	{
		tempDirectionSurface = mOpticalSys_Ele_USE.getPosAndIntersection_LLT()[i].getSurfaceInterRay_ptr()->getDirection().getZ();

		tempRefractiveIndex_N = mOpticalSys_Ele_USE.getPosAndIntersection_LLT()[i].getSurfaceInterRay_ptr()->getRefractiveIndex_A();
		tempRefractiveIndex_N_dash = mOpticalSys_Ele_USE.getPosAndIntersection_LLT()[i].getSurfaceInterRay_ptr()->getRefractiveIndex_B();

		if (0 < tempDirectionSurface)
		{
			tempOneByRadius_C = mOneByRadius_C_vec.at(i);
		}
		else if (0 > tempDirectionSurface)
		{
			tempOneByRadius_C = -mOneByRadius_C_vec.at(i);
		}
		else if (0 == tempDirectionSurface)
		{
			std::cout << "there is a mistake by the calculation of the seidel coeffizients" << std::endl;
		}
		tempOutAngle_dash = (tempRefractiveIndex_N * tempIncidenceAngle - tempHeight * tempOneByRadius_C * (tempRefractiveIndex_N_dash - tempRefractiveIndex_N)) / tempRefractiveIndex_N_dash;

		tempA = tempRefractiveIndex_N * (tempHeight * tempOneByRadius_C + tempIncidenceAngle);
		mA_vec.push_back(tempA);
		mh_vec.push_back(tempHeight);
		mU_vec.push_back(tempIncidenceAngle);
		mN_vec.push_back(tempRefractiveIndex_N);
		mU_dash_vec.push_back(tempOutAngle_dash);
		mN_dash_vec.push_back(tempRefractiveIndex_N_dash);


		tempDeltaAngleRefraction = ((tempIncidenceAngle / tempRefractiveIndex_N) - (tempOutAngle_dash / tempRefractiveIndex_N_dash));
		tempIncidenceAngle = tempOutAngle_dash;
		tempHeight = tempHeight + tempOutAngle_dash * mD.at(i + 1);
		mOneByRadius_C_direction_vec.push_back(tempOneByRadius_C);
	}

}

//void  SeidelCoefficients::calculate_h_bar()
//{
//	SequentialRayTracing seqTracChiefRay(/*optical system element*/ mOpticalSys_Ele_USE, mChiefLightRay);
//	unsigned int lengthOptSys = mOpticalSys_Ele_USE.getPosAndElement().size();
//	real tempHeight;
//	real tempDirectionSurface_Z;
//	real tempRefractiveIndex_N;
//	real tempRefractiveIndex_N_dash;
//	real tempOneByRadius_C;
//	real tempOutAngle_dash;
//
//	real deltaY = seqTracChiefRay.getAllInterInfosOfSurf_i(0).at(0).getIntersectionPoint().getY() - seqTracChiefRay.getStartPoints().at(0).getY();
//	real deltaZ = seqTracChiefRay.getAllInterInfosOfSurf_i(0).at(0).getIntersectionPoint().getZ() - seqTracChiefRay.getStartPoints().at(0).getZ();
//
//	real tempIncidenceAngle = atan(deltaY / deltaZ);
//
//	tempHeight = seqTracChiefRay.getAllInterInfosOfSurf_i(0).at(0).getIntersectionPoint().getY();
//	mh_bar_vec.push_back(tempHeight);
//	mU_bar_vec.push_back(tempIncidenceAngle);
//	for (unsigned int i = 0; i < lengthOptSys - 1; i++)
//	{
//
//		tempDirectionSurface_Z = mOpticalSys_Ele_USE.getOpticalSystem_LLT().getPosAndInteractingSurface().at(i).getSurfaceInterRay_ptr()->getDirection().getZ();
//
//		if (0 < tempDirectionSurface_Z)
//		{
//			tempRefractiveIndex_N = mOpticalSys_Ele_USE.getOpticalSystem_LLT().getPosAndInteractingSurface().at(i).getSurfaceInterRay_ptr()->getRefractiveIndex_A();
//			tempRefractiveIndex_N_dash = mOpticalSys_Ele_USE.getOpticalSystem_LLT().getPosAndInteractingSurface().at(i).getSurfaceInterRay_ptr()->getRefractiveIndex_B();
//			tempOneByRadius_C = mOneByRadius_C_vec.at(i);
//		}
//		else if (0 > tempDirectionSurface_Z)
//		{
//			tempRefractiveIndex_N = mOpticalSys_Ele_USE.getOpticalSystem_LLT().getPosAndInteractingSurface().at(i).getSurfaceInterRay_ptr()->getRefractiveIndex_B();
//			tempRefractiveIndex_N_dash = mOpticalSys_Ele_USE.getOpticalSystem_LLT().getPosAndInteractingSurface().at(i).getSurfaceInterRay_ptr()->getRefractiveIndex_A();
//			tempOneByRadius_C = -mOneByRadius_C_vec.at(i);
//		}
//		else if (0 == tempDirectionSurface_Z)
//		{
//			std::cout << "there is a mistake by the calculation of the seidel coeffizients" << std::endl;
//		}
//
//		tempOutAngle_dash = (tempRefractiveIndex_N * tempIncidenceAngle - tempHeight * tempOneByRadius_C * (tempRefractiveIndex_N_dash - tempRefractiveIndex_N)) / tempRefractiveIndex_N_dash;
//
//
//		tempIncidenceAngle = tempOutAngle_dash;
//		tempHeight = tempHeight + tempOutAngle_dash * mD.at(i + 1);
//		mh_bar_vec.push_back(tempHeight);
//		mU_bar_vec.push_back(tempIncidenceAngle);
//	}
//
//}

void  SeidelCoefficients::calculate_h_bar()
{
	real temp_h_bar;
	unsigned int lenghtOptSys = mOpticalSys_Ele_USE.getPosAndElement().size();
	SequentialRayTracing seqTracChiefRay(/*optical system element*/ mOpticalSys_Ele_USE, mChiefLightRay);

	char tempSurfaceSide;

	for (unsigned int i = 0; i < lenghtOptSys - 1; i++)
	{
		tempSurfaceSide = seqTracChiefRay.getAllInterInfosOfSurf_i_notFiltered(i)[0].getSurfaceSide();
		if (tempSurfaceSide == N) // there is no intersection point
		{
			temp_h_bar = 99999999.0; // TODO: Check if that is a good option
		}
		else // there is an intersection point
		{
			temp_h_bar = seqTracChiefRay.getAllInterPointsAtSurf_i_notFiltered(i).at(0).getY();
			mh_bar_vec.push_back(temp_h_bar);
		}
	}

}



//void SeidelCoefficients::calculate_A_bar()
//{
//	real temp_A_bar;
//	unsigned int lenghtOptSys = mOpticalSys_Ele_USE.getPosAndElement().size();
//
//	for (unsigned int i = 0; i < lenghtOptSys - 1; i++)
//	{
//		temp_A_bar = (mh_bar_vec.at(i) * mA_vec.at(i) - mLagrangeInvariant) / mh_vec.at(i);
//		mA_bar_vec.push_back(temp_A_bar);
//	}
//
//}

void SeidelCoefficients::setWavelength(std::vector<real> wavelenght_vec)
{
	mWavelength_vec = wavelenght_vec;
}

void SeidelCoefficients::calculateRefIndexAtSurface()
{
	unsigned int lengthOptSys = mOpticalSys_Ele_USE.getPosAndElement().size();
	real tempRefIndex_A;
	real tempRefIndex_B;

	std::vector<real> tempRefIndex_A_vec;
	std::vector<real> tempRefIndex_B_vec;

	real tempDirectionSurface_Z;


	for (unsigned int i = 0; i < lengthOptSys; i++)
	{

		for (unsigned int j = 0; j < mWavelength_vec.size(); j++)
		{
			mOpticalSys_Ele_USE.getPosAndElement().at(i).getElementInOptSys_ptr()->calRefIndex_A_and_B_andSet(mWavelength_vec.at(j));
			tempRefIndex_A = mOpticalSys_Ele_USE.getPosAndElement().at(i).getElementInOptSys_ptr()->getRefIndexValue_A();
			tempRefIndex_B = mOpticalSys_Ele_USE.getPosAndElement().at(i).getElementInOptSys_ptr()->getRefIndexValue_B();

			tempDirectionSurface_Z = mOpticalSys_Ele_USE.getPosAndElement().at(i).getElementInOptSys_ptr()->getDirectionElementValue_Z();

			if (0 < tempDirectionSurface_Z)
			{
				tempRefIndex_A_vec.push_back(tempRefIndex_A);
				tempRefIndex_B_vec.push_back(tempRefIndex_B);

			}
			else if (0 > tempDirectionSurface_Z)
			{
				tempRefIndex_B_vec.push_back(tempRefIndex_A);
				tempRefIndex_A_vec.push_back(tempRefIndex_B);
			}

		}

		mRefIndex_vec.push_back(tempRefIndex_A_vec);
		mRefIndex_dash_vec.push_back(tempRefIndex_B_vec);

		tempRefIndex_A_vec.clear();
		tempRefIndex_B_vec.clear();

	}

}

void SeidelCoefficients::calcMeanRefIndex()
{

	for (unsigned int i = 0; i < mRefIndex_vec.size(); i++)
	{
		real tempIndex = 0;
		real tempSumIndex = 0;
		real tempIndexMean = 0;

		for (unsigned int j = 0; j < mRefIndex_vec.at(0).size(); j++)
		{
			tempIndex = mRefIndex_vec.at(i).at(j);
			tempSumIndex = tempSumIndex + tempIndex;

		}

		tempIndexMean = tempSumIndex / mWavelength_vec.size();
		mRefIndexMean_vec.push_back(tempIndexMean);
	}


}


void SeidelCoefficients::findMinAndMaxRefIndex()
{
	int tempMinPos;
	int tempMaxPos;
	real tempMin;
	real tempMax;
	std::vector<real> tempRefIndex_vec;

	for (unsigned int i = 0; i < mRefIndex_vec.size(); i++)
	{
		tempRefIndex_vec = mRefIndex_vec.at(i);
		std::vector<real>::iterator resultMin = std::min_element(std::begin(tempRefIndex_vec), std::end(tempRefIndex_vec));
		tempMinPos = std::distance(std::begin(tempRefIndex_vec), resultMin);
		tempMin = tempRefIndex_vec.at(tempMinPos);

		std::vector<real>::iterator resultMax = std::max_element(std::begin(tempRefIndex_vec), std::end(tempRefIndex_vec));
		tempMaxPos = std::distance(std::begin(tempRefIndex_vec), resultMax);
		tempMax = tempRefIndex_vec.at(tempMaxPos);

		mMinRefIndex_vec.push_back(tempMin);
		mMaxRefIndex_vec.push_back(tempMax);
	}


}

void SeidelCoefficients::calcDeltaNandU_wavelength()
{
	real tempDeltaNandU_wavelength;

	for (unsigned int i = 0; i < mN_vec.size(); i++)
	{
		tempDeltaNandU_wavelength = ((mMaxRefIndex_vec.at(i + 1) - mMinRefIndex_vec.at(i + 1)) / mRefIndexMean_vec.at(i + 1)) - ((mMaxRefIndex_vec.at(i) - mMinRefIndex_vec.at(i)) / mRefIndexMean_vec.at(i));
		mDeltaNandU_wavelength_vec.push_back(tempDeltaNandU_wavelength);
	}

}

void SeidelCoefficients::calculateOnebyN()
{
	real tempOnebyN;

	for (unsigned int i = 0; i < mN_vec.size(); i++)
	{
		tempOnebyN = ((1 / mN_dash_vec.at(i)) - (1 / mN_vec.at(i)));
		mOnebyN_vec.push_back(tempOnebyN);
	}

}

void SeidelCoefficients::calculateDeltaUandN()
{
	real tempDeltaUandN;

	for (unsigned int i = 0; i < mN_vec.size(); i++)
	{
		tempDeltaUandN = (mU_vec.at(i) / mN_vec.at(i)) - (mU_dash_vec.at(i) / mN_dash_vec.at(i));
		mDeltaUandN_vec.push_back(tempDeltaUandN);
	}
}


void SeidelCoefficients::calculateS1()
{
	unsigned int lengthOptSys = mOpticalSys_Ele_USE.getPosAndElement().size();
	real tempCoef_S1;

	for (unsigned int i = 0; i < lengthOptSys - 1; i++)
	{
		tempCoef_S1 = pow(mA_vec.at(i), 2)*mh_vec.at(i)*mDeltaUandN_vec.at(i);
		mS1_vec.push_back(tempCoef_S1);
	}


}

void SeidelCoefficients::calculateS2()
{
	unsigned int lengthOptSys = mOpticalSys_Ele_USE.getPosAndElement().size();
	real tempCoef_S2;


	for (unsigned int i = 0; i < lengthOptSys - 1; i++)
	{
		tempCoef_S2 = mA_vec.at(i)*mA_bar_vec.at(i)*mh_vec.at(i) *mDeltaUandN_vec.at(i);
		mS2_vec.push_back(tempCoef_S2);
	}

}


void SeidelCoefficients::calculateS3()
{
	unsigned int lengthOptSys = mOpticalSys_Ele_USE.getPosAndElement().size();
	real tempCoef_S3;

	for (unsigned int i = 0; i < lengthOptSys - 1; i++)
	{
		tempCoef_S3 = pow(mA_bar_vec.at(i), 2)*mh_vec.at(i) *mDeltaUandN_vec.at(i);
		mS3_vec.push_back(tempCoef_S3);
	}
}


void SeidelCoefficients::calculateS4()
{
	unsigned int lengthOptSys = mOpticalSys_Ele_USE.getPosAndElement().size();
	real tempCoef_S4;

	for (unsigned int i = 0; i < lengthOptSys - 1; i++)
	{
		tempCoef_S4 = -pow(mLagrangeInvariant, 2)*mOneByRadius_C_direction_vec.at(i)*(mOnebyN_vec.at(i));
		mS4_vec.push_back(tempCoef_S4);
	}

}


void SeidelCoefficients::calculateS5()
{
	unsigned int lengthOptSys = mOpticalSys_Ele_USE.getPosAndElement().size();
	real tempCoef_S5;

	for (unsigned int i = 0; i < lengthOptSys - 1; i++)
	{
		tempCoef_S5 = (mA_bar_vec.at(i) / mA_vec.at(i))*(mS3_vec.at(i) + mS4_vec.at(i));
		mS5_vec.push_back(tempCoef_S5);
	}
}


void SeidelCoefficients::calculateS6_C1()
{
	unsigned int lengthOptSys = mOpticalSys_Ele_USE.getPosAndElement().size();
	real tempCoef_S6_C1;

	for (unsigned int i = 0; i < lengthOptSys - 1; i++)
	{
		tempCoef_S6_C1 = mA_vec.at(i)*mh_vec.at(i)*mDeltaNandU_wavelength_vec.at(i);
		mS6_C1_vec.push_back(tempCoef_S6_C1);
	}
}


void SeidelCoefficients::calculateS7_C2()
{
	unsigned int lengthOptSys = mOpticalSys_Ele_USE.getPosAndElement().size();
	real tempCoef_S7_C2;

	for (unsigned int i = 0; i < lengthOptSys - 1; i++)
	{
		tempCoef_S7_C2 = mA_bar_vec.at(i)*mh_vec.at(i)*mDeltaNandU_wavelength_vec.at(i);
		mS7_C2_vec.push_back(tempCoef_S7_C2);
	}
}

void SeidelCoefficients::calcSumS1()
{
	mSum_S1 = std::accumulate(mS1_vec.begin(), mS1_vec.end(), (real)0);
}

void SeidelCoefficients::calcSumS2()
{
	mSum_S2 = std::accumulate(mS2_vec.begin(), mS2_vec.end(), (real)0);
}

void SeidelCoefficients::calcSumS3()
{
	mSum_S3 = std::accumulate(mS3_vec.begin(), mS3_vec.end(), (real)0);
}

void SeidelCoefficients::calcSumS4()
{
	mSum_S4 = std::accumulate(mS4_vec.begin(), mS4_vec.end(), (real)0);
}

void SeidelCoefficients::calcSumS5()
{
	mSum_S5 = std::accumulate(mS5_vec.begin(), mS5_vec.end(), (real)0);
}

void SeidelCoefficients::calcSumS6_C1()
{
	mSum_S6_C1 = std::accumulate(mS6_C1_vec.begin(), mS6_C1_vec.end(), (real)0);
}

void SeidelCoefficients::calcSumS7_C2()
{
	mSum_S7_C2 = std::accumulate(mS7_C2_vec.begin(), mS7_C2_vec.end(), (real)0);
}

real SeidelCoefficients::getS1_at_surface_i(unsigned int i)
{
	return mS1_vec.at(i);
}
real SeidelCoefficients::getS1sum()
{
	return mSum_S1;
}
real SeidelCoefficients::getS2_at_surface_i(unsigned int i)
{
	return mS2_vec.at(i);
}
real SeidelCoefficients::getS2sum()
{
	return mSum_S2;
}
real SeidelCoefficients::getS3_at_surface_i(unsigned int i)
{
	return mS3_vec.at(i);
}
real SeidelCoefficients::getS3sum()
{
	return mSum_S3;
}
real SeidelCoefficients::getS4_at_surface_i(unsigned int i)
{
	return mS4_vec.at(i);
}
real SeidelCoefficients::getS4sum()
{
	return mSum_S4;
}
real SeidelCoefficients::getS5_at_surface_i(unsigned int i)
{
	return mS5_vec.at(i);
}
real SeidelCoefficients::getS5sum()
{
	return mSum_S5;
}
real SeidelCoefficients::getS6_C1_at_surface_i(unsigned int i)
{
	return mS6_C1_vec.at(i);
}
real SeidelCoefficients::getS6C1sum()
{
	return mSum_S6_C1;
}
real SeidelCoefficients::getS7_C2_at_surface_i(unsigned int i)
{
	return mS7_C2_vec.at(i);
}
real SeidelCoefficients::getS7C2sum()
{
	return mSum_S7_C2;
}







