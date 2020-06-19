#include "CardinalPoints.h"
#include <typeinfo>
#include <iostream>



//// get the position of all surfaces after the stop
//std::vector<real> CardinalPoints::getPosSurAfterStop() const
//{
//	return mPosSurfaceAfterStop;
//}
//// get the focal length of all surfaces after the stop
//std::vector<real> CardinalPoints::getFocalLengthAfterStop() const
//{
//	return mFocalLengthAfterStop;
//}

// get the radius of all surfaces after the stop
std::vector<real> CardinalPoints::getRadiusAfterStop() const
{
	return mRadiusAfterStop;
}
// get all refractive indexes
std::vector<real> CardinalPoints::getRefractivIndexesAfterStop() const
{
	return mRefractivIndexesAfterStop;
}
// get aperture size
real CardinalPoints::getDiameterAperture() const
{
	return mDiameterOfApertureStop;
}

// get the EFL
real CardinalPoints::getEFL()
{
	return mEFL;
}
// get position principal plain
real CardinalPoints::getPrincipaPlan()
{
	return mPP;
}
// get ecit pupil position
real CardinalPoints::getExitPupilPosition_lastSurface()
{
	return mEXPP_accordingToLastSurface;
}

// get ecit pupil position
real CardinalPoints::getExitPupilPosition_globalCoori()
{
	return mEXPP_inGlobalCoordinatSystem;
}

// get EcitPupilDiameter
real CardinalPoints::getExitPupilDiameter()
{
	return mEXPD;
}
//get magnification of the system
real CardinalPoints::getMagnification()
{
	return mMag;
}

// get anti principelplane
real CardinalPoints::getAntiPP()
{
	return mAntiPP;
}

void CardinalPoints::loadAndResizeParameters()
{
	mSizeOfOpt = mOpticalSystem_LLT.getPosAndInteractingSurface().size();
	mPosAndInteraSurfaceVector = mOpticalSystem_LLT.getPosAndInteractingSurface();
	mPositionApertureStop = mOpticalSystem_LLT.getInforAS().getPosAS();
	mSizeOfOptSysMinOne = mSizeOfOpt - 1;
	mSizeOfOptSysMinTwo = mSizeOfOpt - 2;
	mSizeAfterStop = mSizeOfOptSysMinTwo - mPositionApertureStop;

	//// resize
	mSepSurfaceAfterStop.resize(mSizeAfterStop);
	mRadiusAfterStop.resize(mSizeAfterStop);
	mRefractivIndexesAfterStop.resize(mSizeAfterStop);
	mSystemMatrixAfterStop.resize(4);
	mALLSepSurfaceStop.resize(mSizeAfterStop);
	mAllRadius.resize(mSizeOfOptSysMinTwo);
	AllmRefractivIndexes.resize(mSizeOfOptSysMinTwo);
	AllmSepSurface.resize(mSizeOfOptSysMinTwo);
	mAllSystemMatrix.resize(4);
}

void CardinalPoints::calcSystemMatrix()
{
	// ALL
	/**/calcAllRadius();
	/**/calcAllSepSur();
	/**/calcAllRefractivIndexes();
	/**/calcSepSurAndImPlane();
	/**/calcSepObjandSurface();

	// after stop
	/**/calcSepSurAndStop();
	/**/calcSepSurAfterStop();
	/**/calcRadiusAfterStop();
	/**/calcRefractivIndexesAfterStop();

	/**/calcDiameterAperture();

	calcSystemMatrixAfterStop();
	calcAllSystemMatrix();
}





// calculate the separation of all surfaces after the stop
void CardinalPoints::calcSepSurAfterStop()
{
	unsigned int posInVec = 0;
	for (unsigned int j = mPositionApertureStop + 1; j < mSizeOfOptSysMinOne; j++)
	{
		mSepSurfaceAfterStop[posInVec] = mPosAndInteraSurfaceVector[j].getSurfaceInterRay_ptr()->getPoint().getZ() - mPosAndInteraSurfaceVector[j-1].getSurfaceInterRay_ptr()->getPoint().getZ();
		++posInVec;
	}

}

// calculate the separation of 1st surface and the stop
void CardinalPoints::calcSepSurAndStop()
{
	mSepSurfaceAndStop = mOpticalSystem_LLT.getPosAndInteractingSurface().at(mPositionApertureStop + 1).getSurfaceInterRay_ptr()->getPoint().getZ() - mOpticalSystem_LLT.getPosAndInteractingSurface().at(mPositionApertureStop).getSurfaceInterRay_ptr()->getPoint().getZ();

}


//calculate distance between object plane and first surface(first lens)
void CardinalPoints::calcSepObjandSurface()
{
	mSepObjandSurface = mOpticalSystem_LLT.getPosAndInteractingSurface().at(1).getSurfaceInterRay_ptr()->getPoint().getZ();
}

// calculate the separation oflast surface and image plane
void CardinalPoints::calcSepSurAndImPlane()
{
	mSepSurAndImPlane = mOpticalSystem_LLT.getPosAndInteractingSurface().at(mSizeOfOptSysMinOne).getSurfaceInterRay_ptr()->getPoint().getZ() - mOpticalSystem_LLT.getPosAndInteractingSurface().at(mSizeOfOptSysMinOne - 1).getSurfaceInterRay_ptr()->getPoint().getZ();
}


// calculate the radius of all surfaces after the stop
void CardinalPoints::calcRadiusAfterStop()
{
	unsigned int posInVec = 0;

	for (unsigned int j = mPositionApertureStop; j < mSizeOfOptSysMinOne -1; j++)
	{
		mRadiusAfterStop[posInVec] = mAllRadius[j];
		++posInVec;
	}
}




// calculate the refractive index after all surfaces after the stop
void CardinalPoints::calcRefractivIndexesAfterStop()
{
	unsigned int posInVec = 0;
	for (unsigned int j = mPositionApertureStop; j < mSizeOfOptSysMinOne - 1; j++)
	{	
		mRefractivIndexesAfterStop[posInVec] = AllmRefractivIndexes[j];
		++posInVec;
	}
}

// calculate aperture size
void CardinalPoints::calcDiameterAperture()
{
	mDiameterOfApertureStop = 2.0 * mPosAndInteraSurfaceVector[mPositionApertureStop].getSurfaceInterRay_ptr()->getSemiHeight();
}

void CardinalPoints::calcSystemMatrixAfterStop()
{

	using namespace std;


	/*******************************************input values***********************************/
	unsigned int PosAperturStop = 0;
	unsigned int s = mSizeOfOptSysMinOne - mPositionApertureStop - 1;
		
	/*****************************************************************************/
	std::vector<double> R_i(s);
	std::vector<double> R(2 * s - 2);
	std::vector<double> n_i(s);
	std::vector<double> n(2 * s - 1);
	std::vector<double> d_i(s);
	std::vector<double> dis(2 * s - 2);

	/****************************************/
	for (int i = 0; i < s; i++)
	{

		R_i[i] = mRadiusAfterStop[s - i - 1];

	}

	for (int i = 0; i < 2 * s - 2; i++)
	{
		if (i == 0)
		{
			R[i] = R_i[i];
		}
		else if (i > 0 && i % 2 == 0)
		{
			R[i] = 0;
		}
		else
		{
			R[i] = R_i[(i + 1) / 2];
		}

	}

	/****************************************/


	for (int i = 0; i < s - 1; i++)
	{

		d_i[i] = mSepSurfaceAfterStop[s - i - 1];

	}

	for (int i = 0; i < 2 * s - 2; i++)
	{

		if (i % 2 == 0)
		{
			dis[i] = d_i[(i + 1) / 2];

		}
		else
		{
			dis[i] = 0;
		}

	}
	/****************************************/


	for (int i = 0; i < s; i++)
	{

		n_i[i] = mRefractivIndexesAfterStop[s - i - 1];

	}


	for (int i = 0; i < 2 * s - 1; i++)
	{
		if (i == 0)
		{
			n[i] = n_i[i];
		}
		else if (i == 2 * s - 2)
		{
			n[i] = n_i[0];
		}
		else if (i > 0 && i % 2 == 0)
		{
			n[i] = n_i[(i + 2) / 2];
		}
		else
		{
			n[i] = n_i[(i + 1) / 2];
		}

	}
	/*****************************************initiate 3D matrix******************************************************/

	vector < vector < vector<double> > > t;
	t.resize(2);
	t[0].resize(2);
	t[1].resize(2);
	t[0][0].resize(2 * s - 2);
	t[0][1].resize(2 * s - 2);
	t[1][0].resize(2 * s - 2);
	t[1][1].resize(2 * s - 2);

	vector < vector < vector<double> > > r;
	r.resize(2);
	r[0].resize(2);
	r[1].resize(2);
	r[0][0].resize(2 * s - 1);
	r[0][1].resize(2 * s - 1);
	r[1][0].resize(2 * s - 1);
	r[1][1].resize(2 * s - 1);



	/*******************************spherical surface************************************************/

	

	for (int k = 0; k < 2 * s - 2; k++)
	{

		if (k == 0)
		{
			r[0][0][k] = 1;
			r[0][1][k] = -(n[k] - n[k + 1]) / R[k];
			r[1][0][k] = 0;
			r[1][1][k] = 1;



			t[0][0][k] = 1;
			t[0][1][k] = 0;
			t[1][0][k] = dis[k] / n[k + 1];
			t[1][1][k] = 1;


		}


		else if (k > 0 && k % 2 == 0)
		{
			r[0][0][k] = 0;
			r[0][1][k] = 0;
			r[1][0][k] = 0;
			r[1][1][k] = 0;

			t[0][0][k] = 1;
			t[0][1][k] = 0;
			t[1][0][k] = dis[k] / n[k + 1];
			t[1][1][k] = 1;


		}
		else
		{

			r[0][0][k] = 1;
			r[0][1][k] = -(n[k] - n[k + 1]) / R[k];
			r[1][0][k] = 0;
			r[1][1][k] = 1;


			t[0][0][k] = 0;
			t[0][1][k] = 0;
			t[1][0][k] = 0;
			t[1][1][k] = 0;
		}

	}

	/**********************************************************************************************/

	double mult[2][2];
	for (int z = 0; z < 2 * s - 2; z++)
	{
		mult[0][0] = 0;
		mult[0][1] = 0;
		mult[1][0] = 0;
		mult[1][1] = 0;

		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				for (int k = 0; k < 2; k++)
				{

					if (z % 2 == 0)
					{
						mult[i][j] += t[i][k][z] * r[k][j][z];


					}
					else
					{
						mult[i][j] += r[i][k][z] * t[k][j][z];

					}
				}
			}
		}
		if (z % 2 == 0)
		{
			for (int p = 0; p < 2; p++)
			{
				for (int q = 0; q < 2; q++)
				{
					t[p][q][z + 1] = mult[p][q];
				}
			}
		}

		else
		{
			for (int p = 0; p < 2; p++)
			{
				for (int q = 0; q < 2; q++)
				{
					r[p][q][z + 1] = mult[p][q];
				}
			}
		}


	}
	/****************************************************************************************/


	vector < vector < double > > matrix2D;
	matrix2D.resize(2);
	matrix2D[0].resize(2);
	matrix2D[1].resize(2);

	for (int i = 0; i < 2; i++)
	{
		//vector <double> zii;
		//matrix2D[i] = zii;
		for (int j = 0; j < 2; j++)
		{
			matrix2D[i][j] = mult[1 - j][1 - i];
		}
	}

	mSystemMatrixAfterStop[0] = matrix2D[0][0];
	mSystemMatrixAfterStop[1] = matrix2D[0][1];
	mSystemMatrixAfterStop[2] = matrix2D[1][0];
	mSystemMatrixAfterStop[3] = matrix2D[1][1];


}


// calculate the EFL ot the optical system
real CardinalPoints::calcEFL()
{

	using namespace std;


	std::vector<double> matrixABCD = mAllSystemMatrix;
	double a, b, c, d;

	b = matrixABCD[0];
	a = -matrixABCD[1];
	d = -matrixABCD[2];
	c = matrixABCD[3];




	double efl = 1 / a;
	//cout << endl << "EFL = " << efl << endl;




	return efl;

}



// calculat the global principal plan of the optical system
real CardinalPoints::calcPrincPlanOptSys()
{
	using namespace std;
	/*******************************************input values***********************************/
	std::vector<double> matrixABCD = mAllSystemMatrix;
	double efl = mEFL;
	double image_plane = mSepSurAndImPlane;
	double aperture_size = mDiameterOfApertureStop;
	double sto = mSepSurfaceAndStop;

	/*****************************************************************************/

	double a, b, c, d;

	b = matrixABCD[0];
	a = -matrixABCD[1];
	d = -matrixABCD[2];
	c = matrixABCD[3];

	double h1 = (1 - b) / a;

	if (typeid(*mPosAndInteraSurfaceVector.at(0).getSurfaceInterRay_ptr()) == typeid(mApertureStop))
	{
		h1 = (1 - b) / a
			+ mOpticalSystem_LLT.getPosAndInteractingSurface().at(1).getSurfaceInterRay_ptr()->getPoint().getZ()
			- mOpticalSystem_LLT.getPosAndInteractingSurface().at(0).getSurfaceInterRay_ptr()->getPoint().getZ();
	}

	//cout << "principal plane = " << h1 << endl;





	return h1;
}

// calculat the global anti principal plan of the optical syste
real CardinalPoints::calcAntiPrincPlanOptSys()
{
	using namespace std;
	/*******************************************input values***********************************/
	std::vector<double> matrixABCD = mAllSystemMatrix;
	double efl = mEFL;
	double image_plane = mSepSurAndImPlane;
	double aperture_size = mDiameterOfApertureStop;
	double sto = mSepSurfaceAndStop;

	/*****************************************************************************/

	double a, b, c, d;

	b = matrixABCD[0];
	a = -matrixABCD[1];
	d = -matrixABCD[2];
	c = matrixABCD[3];


	double h2 = (c - 1) / a - image_plane;

	//cout << "anti-principal plane = " << h2 << endl;




	return h2;
}

//calculate the exit Pupul position
real CardinalPoints::calcExitPupilPost()
{
	using namespace std;
	/*******************************************input values***********************************/
	std::vector<double> matrixABCD = mSystemMatrixAfterStop;

	double image_plane = mSepSurAndImPlane;
	double aperture_size = mDiameterOfApertureStop;
	double sto = mSepSurfaceAndStop;
	/*****************************************************************************/
	double a, b, c, d;

	b = matrixABCD[0];
	a = -matrixABCD[1];
	d = -matrixABCD[2];
	c = matrixABCD[3];

	double efl = 1 / a;
	double h1 = (1 - b) / a + sto;
	double h2 = (c - 1) / a - image_plane;


	double pupil_pos;
	double pupil_pos1;
	double X = image_plane - h2;
	pupil_pos = (h1*efl) / (h1 - efl);
	pupil_pos1 = pupil_pos + h2;
	//cout <<"exit pupil position = " << pupil_pos1 << endl;


	return pupil_pos1;
}


// calculate the diameter of the exit pupil of the optical system
real CardinalPoints::calcDiameterExitPupil()
{
	using namespace std;
	/*******************************************input values***********************************/
	std::vector<double> matrixABCD = mSystemMatrixAfterStop;

	double image_plane = mSepSurAndImPlane;
	double aperture_size = mDiameterOfApertureStop;
	double sto = mSepSurfaceAndStop;
	/*****************************************************************************/


	double a, b, c, d;

	b = matrixABCD[0];
	a = -matrixABCD[1];
	d = -matrixABCD[2];
	c = matrixABCD[3];


	double efl = 1 / a;
	double h1 = (1 - b) / a;
	double h2 = (c - 1) / a;
	double pupil_pos;
	double pupil_pos1;
	double size_pupil;
	double X = image_plane - h2;
	pupil_pos = ((sto + h1)*efl) / (sto + h1 - efl);
	pupil_pos1 = pupil_pos;
	size_pupil = -aperture_size * (pupil_pos) / (sto + h1);

	if (size_pupil < 0)
	{
		size_pupil = -size_pupil;
	}

	//cout << "size_pupil = " << size_pupil << endl;
	return size_pupil;
}


real CardinalPoints::calcMagnification()
{
	using namespace std;
	double mag;
	double image_plane = mSepSurAndImPlane;
	double object_plane = mSepObjandSurface;
	double paraxial_implane = image_plane + (-1 * mAntiPP);
	double paraxial_objplane = object_plane + (mPP);
	mag = paraxial_implane / paraxial_objplane;
	//cout << "Magnification = " << mag << endl;
	return mag;
}

// calc pos exit pupil gloabl coordinates
real CardinalPoints::calcPosEXXPglobalCoordi()
{
	real EXXPglobalCoordi;

	unsigned int numSurfaces = mOpticalSystem_LLT.getNumberOfSurfaces();
	real zPosLastSurface = mOpticalSystem_LLT.getPosAndInteractingSurface().at(numSurfaces).getSurfaceInterRay_ptr()->getPoint().getZ();

	EXXPglobalCoordi = zPosLastSurface + mEXPP_accordingToLastSurface;
	return EXXPglobalCoordi;

}


void CardinalPoints::calcAllRadius()
{
	real tempRadius;
	real tempDirectionZ;
	int sign;
	unsigned int posInVec = 0;

	for (unsigned int i = 0; i < mSizeOfOptSysMinOne; i++)
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
	real tempDirectionZ;
	unsigned int posInVec = 0;

	for (unsigned int i = 0; i < mSizeOfOptSysMinOne; i++)
	{
		if (typeid(*mPosAndInteraSurfaceVector.at(i).getSurfaceInterRay_ptr()) != typeid(mApertureStop))
		{


			tempDirectionZ = mPosAndInteraSurfaceVector[i].getSurfaceInterRay_ptr()->getDirection().getZ();


			if (tempDirectionZ > 0)
			{
				tempRefIndex = mPosAndInteraSurfaceVector[i].getSurfaceInterRay_ptr()->getRefractiveIndex_B();
				AllmRefractivIndexes[posInVec] = tempRefIndex;

			}
			else if (tempDirectionZ < 0)
			{
				tempRefIndex = mPosAndInteraSurfaceVector[i].getSurfaceInterRay_ptr()->getRefractiveIndex_A();
				AllmRefractivIndexes[posInVec] = tempRefIndex;

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
				AllmSepSurface[posInVec] = tempZ_Pos;

			}
			else
			{
				tempZ_Pos = mOpticalSystem_LLT.getPosAndInteractingSurface().at(i + 2).getSurfaceInterRay_ptr()->getPoint().getZ() - mOpticalSystem_LLT.getPosAndInteractingSurface().at(i).getSurfaceInterRay_ptr()->getPoint().getZ();
				AllmSepSurface[posInVec] = tempZ_Pos;

			}
			++posInVec;
		}

	}

}



void CardinalPoints::calcAllSystemMatrix()
{

	using namespace std;

	/*******************************************input values***********************************/
	unsigned int sizeOfOptSys = mOpticalSystem_LLT.getNumberOfSurfaces();
	int s = sizeOfOptSys - 1;
	//std::vector<double> R_ip = mAllRadius;
	//std::vector<double> n_ip = AllmRefractivIndexes;
	//std::vector<double> d_ip = AllmSepSurface;

	/*****************************************************************************/
	std::vector<double> R_i(s);
	std::vector<double> R(2 * s - 2);
	std::vector<double> n_i(s);
	std::vector<double> n(2 * s - 1);
	std::vector<double> d_i(s);
	std::vector<double> dis(2 * s - 2);


	/****************************************/
	for (int i = 0; i < s; i++)
	{

		R_i[i] = mAllRadius[s - i - 1];

	}

	for (int i = 0; i < 2 * s - 2; i++)
	{
		if (i == 0)
		{
			R[i] = R_i[i];
		}
		else if (i > 0 && i % 2 == 0)
		{
			R[i] = 0;
		}
		else
		{
			R[i] = R_i[(i + 1) / 2];

		}
	}

	/****************************************/


	for (int i = 0; i < s - 1; i++)
	{

		d_i[i] = AllmSepSurface[s - i - 2];


	}

	for (int i = 0; i < 2 * s - 2; i++)
	{

		if (i % 2 == 0)
		{
			dis[i] = d_i[(i + 1) / 2];
		}
		else
		{
			dis[i] = 0;
		}
	}
	/****************************************/

	for (int i = 0; i < s; i++)
	{

		n_i[i] = AllmRefractivIndexes[s - i - 1];


	}


	for (int i = 0; i < 2 * s - 1; i++)
	{
		if (i == 0)
		{
			n[i] = n_i[i];
		}
		else if (i == 2 * s - 2)
		{
			n[i] = n_i[0];
		}
		else if (i > 0 && i % 2 == 0)
		{
			n[i] = n_i[(i + 2) / 2];
		}
		else
		{
			n[i] = n_i[(i + 1) / 2];
		}
	}
	/*****************************************initiate 3D matrix******************************************************/

	vector < vector < vector<double> > > t;
	t.resize(2);
	t[0].resize(2);
	t[1].resize(2);
	t[0][0].resize(2 * s - 2);
	t[0][1].resize(2 * s - 2);
	t[1][0].resize(2 * s - 2);
	t[1][1].resize(2 * s - 2);

	vector < vector < vector<double> > > r;
	r.resize(2);
	r[0].resize(2);
	r[1].resize(2);
	r[0][0].resize(2 * s - 1);
	r[0][1].resize(2 * s - 1);
	r[1][0].resize(2 * s - 1);
	r[1][1].resize(2 * s - 1);



	/*******************************spherical surface************************************************/

	for (int k = 0; k < 2 * s - 2; k++)
	{

		if (k == 0)
		{
			r[0][0][k] = 1;
			r[0][1][k] = -(n[k] - n[k + 1]) / R[k];
			r[1][0][k] = 0;
			r[1][1][k] = 1;


			t[0][0][k] = 1;
			t[0][1][k] = 0;
			t[1][0][k] = dis[k] / n[k + 1];
			t[1][1][k] = 1;

		}


		else if (k > 0 && k % 2 == 0)
		{
			r[0][0][k] = 0;
			r[0][1][k] = 0;
			r[1][0][k] = 0;
			r[1][1][k] = 0;

			t[0][0][k] = 1;
			t[0][1][k] = 0;
			t[1][0][k] = dis[k] / n[k + 1];
			t[1][1][k] = 1;

		}
		else
		{

			r[0][0][k] = 1;
			r[0][1][k] = -(n[k] - n[k + 1]) / R[k];
			r[1][0][k] = 0;
			r[1][1][k] = 1;


			t[0][0][k] = 0;
			t[0][1][k] = 0;
			t[1][0][k] = 0;
			t[1][1][k] = 0;
		}

	}

	/**********************************************************************************************/
	//cout << endl << endl;

	double mult[2][2];
	for (int z = 0; z < 2 * s - 2; z++)
	{
		mult[0][0] = 0;
		mult[0][1] = 0;
		mult[1][0] = 0;
		mult[1][1] = 0;

		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				for (int k = 0; k < 2; k++)
				{

					if (z % 2 == 0)
					{
						mult[i][j] += t[i][k][z] * r[k][j][z];
					}
					else
					{
						mult[i][j] += r[i][k][z] * t[k][j][z];

					}
				}
			}
		}
		if (z % 2 == 0)
		{
			for (int p = 0; p < 2; p++)
			{
				for (int q = 0; q < 2; q++)
				{
					t[p][q][z + 1] = mult[p][q];
				}
			}
		}

		else
		{
			for (int p = 0; p < 2; p++)
			{
				for (int q = 0; q < 2; q++)
				{
					r[p][q][z + 1] = mult[p][q];
				}
			}
		}


	}
	/****************************************************************************************/


	vector < vector < double > > matrix2D;
	for (int i = 0; i < 2; i++)
	{
		vector <double> zii;
		matrix2D.push_back(zii);
		for (int j = 0; j < 2; j++)
		{
			matrix2D[i].push_back(mult[1 - j][1 - i]);
		}
	}


	
	mAllSystemMatrix[0] = matrix2D[0][0];
	mAllSystemMatrix[1] = matrix2D[0][1];
	mAllSystemMatrix[2] = matrix2D[1][0];
	mAllSystemMatrix[3] = matrix2D[1][1];



}

