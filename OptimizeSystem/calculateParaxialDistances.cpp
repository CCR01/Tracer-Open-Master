#include "calculateParaxialDistances.h"

CalculateParaxialDistances::CalculateParaxialDistances() {}

CalculateParaxialDistances::~CalculateParaxialDistances() {}


CalculateParaxialDistances::CalculateParaxialDistances(OpticalSystemElement optSysEle, StartRayPos startRay, real primaryWavelength) :
	mOptSysEle(optSysEle),
	optSys_LLT(optSysEle.getLLTconversion_doConversion()),
	mStartRay(startRay),
	mPrimaryWavelength(primaryWavelength)

{
	calcDistancesAllSurfaces();
	setRefractiveIndexesAccordingToPrimWavelength();
	calcNandNdash();
	calcFocallength_each_surface();
	calcS_object_image();
}

CalculateParaxialDistances::CalculateParaxialDistances(OpticalSystem_LLT optSys_LLT, StartRayPos startRay, real primaryWavelength) :
	optSys_LLT(optSys_LLT),
	mStartRay(startRay),
	mPrimaryWavelength(primaryWavelength)
{
	calcDistancesAllSurfaces();
	calcNandNdash();
	calcFocallength_each_surface();
	calcS_object_image();
}


void CalculateParaxialDistances::calcDistancesAllSurfaces()
{
	unsigned int sizeOptSys = optSys_LLT.getPosAndInteractingSurface().size();
	real tempPosZ = optSys_LLT.getPosAndInteractingSurface().at(0).getSurfaceInterRay_ptr()->getPoint().getZ();
	mDistancesAllSurfaces.push_back(tempPosZ);

	real tempPosZ_next;
	real distance;

	for (unsigned int i = 1; i < sizeOptSys; i++)
	{
		tempPosZ_next = optSys_LLT.getPosAndInteractingSurface().at(i).getSurfaceInterRay_ptr()->getPoint().getZ();
		distance = tempPosZ_next - tempPosZ;

		mDistancesAllSurfaces.push_back(distance);
		tempPosZ = tempPosZ_next;
	}

}

void CalculateParaxialDistances::setRefractiveIndexesAccordingToPrimWavelength()
{
	unsigned int sizeOptSys = mOptSysEle.getPosAndElement().size();

	for (unsigned int i = 0; i < sizeOptSys; i++)
	{
		mOptSysEle.getPosAndElement().at(i).getElementInOptSys_ptr()->calRefIndex_A_and_B_andSet(mPrimaryWavelength);
	}
}

void CalculateParaxialDistances::calcNandNdash()
{
	unsigned int lengthOptSys = optSys_LLT.getPosAndInteractingSurface().size();
	real tempN;
	real tempN_dash;
	real tempDirection;

	for (unsigned int i = 0; i < lengthOptSys - 1; i++)
	{
		tempDirection = optSys_LLT.getPosAndInteractingSurface().at(i).getSurfaceInterRay_ptr()->getDirection().getZ();

		if (tempDirection < 0)
		{
			tempN = optSys_LLT.getPosAndInteractingSurface().at(i).getSurfaceInterRay_ptr()->getRefractiveIndex_B();
			tempN_dash = optSys_LLT.getPosAndInteractingSurface().at(i).getSurfaceInterRay_ptr()->getRefractiveIndex_A();

			mN_vec.push_back(tempN);
			mN_dash_vec.push_back(tempN_dash);
		}

		if (tempDirection > 0)
		{
			tempN = optSys_LLT.getPosAndInteractingSurface().at(i).getSurfaceInterRay_ptr()->getRefractiveIndex_A();
			tempN_dash = optSys_LLT.getPosAndInteractingSurface().at(i).getSurfaceInterRay_ptr()->getRefractiveIndex_B();

			mN_vec.push_back(tempN);
			mN_dash_vec.push_back(tempN_dash);
		}

	}

};

void CalculateParaxialDistances::calcFocallength_each_surface()
{

	unsigned int lengthOptSys = optSys_LLT.getPosAndInteractingSurface().size();
	real focallength_each_surface;
	real tempDirection;

	for (unsigned int i = 0; i < lengthOptSys - 1; i++)
	{
		int prefix = 1;
		tempDirection = optSys_LLT.getPosAndInteractingSurface().at(i).getSurfaceInterRay_ptr()->getDirection().getZ();
		if (tempDirection < 0)
		{
			prefix = -1;


			focallength_each_surface = (mN_dash_vec.at(i)*optSys_LLT.getPosAndInteractingSurface().at(i).getSurfaceInterRay_ptr()->getRadius()*prefix) / (mN_dash_vec.at(i) - mN_vec.at(i));
			mFocalLength_each_surface_vec.push_back(focallength_each_surface);
		}
		else if (tempDirection > 0)
		{

			focallength_each_surface = (mN_dash_vec.at(i)*optSys_LLT.getPosAndInteractingSurface().at(i).getSurfaceInterRay_ptr()->getRadius()*prefix) / (mN_dash_vec.at(i) - mN_vec.at(i));
			mFocalLength_each_surface_vec.push_back(focallength_each_surface);
		}
	}
}



void CalculateParaxialDistances::calcS_object_image()
{
	unsigned int lengthOptSys = optSys_LLT.getPosAndInteractingSurface().size();

	real s;
	real s_dash;
	real s_next_surface;

	if (mStartRay == infinity)
	{
		s = 9999999999999999.0; // that should be infinity
	}

	else if (mStartRay == notInfinity)
	{
		s = optSys_LLT.getPosAndInteractingSurface().at(0).getSurfaceInterRay_ptr()->getPoint().getZ()*-1;
	}




	mS_vec.push_back(s);

	s_dash = (mN_dash_vec.at(0) / ((mN_dash_vec.at(0) / mFocalLength_each_surface_vec.at(0)) + (mN_vec.at(0) / s)));
	mS_dash_vec.push_back(s_dash);


	for (unsigned int i = 1; i < lengthOptSys - 1; i++)
	{
		s = s_dash - mDistancesAllSurfaces.at(i);
		mS_vec.push_back(s);
		s_dash = (mN_dash_vec.at(i) / ((mN_dash_vec.at(i) / mFocalLength_each_surface_vec.at(i)) + (mN_vec.at(i) / mS_vec.at(i))));
		mS_dash_vec.push_back(s_dash);
	}
}


real CalculateParaxialDistances::getS_atSurface_i(unsigned int i)
{
	return mS_vec.at(i);
}


real CalculateParaxialDistances::getS_dash_atSurface_i(unsigned int i)
{
	return mS_dash_vec.at(i);
}

real CalculateParaxialDistances::getFocallength_atSurface_i(unsigned int i)
{
	return mFocalLength_each_surface_vec.at(i);
}

//void CalculateParaxialDistances::calcRadius_with_prefix_forCombination()
//{
//	unsigned int lengthOptSys = mOptSysEle.getPosAndElement().size();
//	real radius_with_prefix;
//
//	for (unsigned int i = 0; i < lengthOptSys - 1; i++)
//	{
//		int prefix = 1;
//		real tempDirection = optSys_LLT.getPosAndInteractingSurface().at(i).getSurfaceInterRay_ptr()->getDirection().getZ();
//		if (tempDirection < 0)
//		{
//			prefix = -1;
//			radius_with_prefix = (optSys_LLT.getPosAndInteractingSurface().at(i).getSurfaceInterRay_ptr()->getRadius()*prefix);
//			mRadius_with_prefix_vec.push_back(radius_with_prefix);
//		}
//		else if (tempDirection > 0)
//		{
//			radius_with_prefix = (optSys_LLT.getPosAndInteractingSurface().at(i).getSurfaceInterRay_ptr()->getRadius()*prefix);
//			mRadius_with_prefix_vec.push_back(radius_with_prefix);
//		}
//	}
//}



//void SeidelCoefficients::calcFocallength()
//{
//
//	unsigned int lengthOptSys = mOpticalSys_Ele_USE.getPosAndElement().size();
//	unsigned int number_lenses = mRefraction_indices_lenses_vec.size();
//	real thickness;
//	real onebyradius1_onebyradius2;
//	real radius1_radius2;
//	real focallength;
//
//	for (unsigned int i = 1; i < lengthOptSys - 1;)
//	{
//		thickness = mD.at(i);
//		mLens_thickness_vec.push_back(thickness);
//		i = i + 2;
//	}
//
//	for (unsigned int i = 0; i < lengthOptSys - 2;)
//	{
//		onebyradius1_onebyradius2 = (1 / mRadius_with_prefix_vec.at(i)) - (1 / mRadius_with_prefix_vec.at(i + 1));
//		mOnebyradius1_onebyradius2_vec.push_back(onebyradius1_onebyradius2);
//		i = i + 2;
//	}
//
//	for (unsigned int i = 0; i < lengthOptSys - 2;)
//	{
//		radius1_radius2 = (mRadius_with_prefix_vec.at(i) * mRadius_with_prefix_vec.at(i + 1));
//		mRadius1_radius2_vec.push_back(radius1_radius2);
//		i = i + 2;
//	}
//
//
//
//	for (unsigned int i = 0; i < number_lenses; i++)
//	{
//		focallength = 1 / (((mRefraction_indices_lenses_vec.at(i) - 1) / 1) * mOnebyradius1_onebyradius2_vec.at(i) + (((mRefraction_indices_lenses_vec.at(i) - 1) / mRefraction_indices_lenses_vec.at(i))*(mD.at(i) / mRadius1_radius2_vec.at(i))));
//		mFocalLength.push_back(focallength);
//	}
//}