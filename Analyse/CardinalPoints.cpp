#include "CardinalPoints.h"
#include <typeinfo>
#include "..\LowLevelTracing\Surfaces\ApertureStop_LLT.h"
#include <iostream>



// get the position of all surfaces after the stop
std::vector<real> CardinalPoints::getPosSurAfterStop() const&
{
	return mPosSurfaceAfterStop;
}
// get the focal length of all surfaces after the stop
std::vector<real> CardinalPoints::getFocalLengthAfterStop() const&
{
	return mFocalLengthAfterStop;
}

// get the radius of all surfaces after the stop
std::vector<real> CardinalPoints::getRadiusAfterStop() const&
{
	return mRadiusAfterStop;
}
// get all refractive indexes
std::vector<real> CardinalPoints::getRefractivIndexesAfterStop() const&
{
	return mRefractivIndexesAfterStop;
}
// get aperture size
real CardinalPoints::getDiameterAperture() const&
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

void CardinalPoints::checkForApertureStopInOptSys()
{
	bool isThereAnApertureStop = false;
	unsigned int sizeOfOptSys = mOpticalSystem_LLT.getNumberOfSurfaces();
	std::vector<PosAndIntsectionSurfaceStruct> posAndInteraSurfaceVector = mOpticalSystem_LLT.getPosAndInteractingSurface();
	ApertureStop_LLT apertureStop_ptr;

	for (unsigned int i = 0; i < sizeOfOptSys; i++)
	{
		if (typeid(*posAndInteraSurfaceVector.at(i).getSurfaceInterRay_ptr()) == typeid(apertureStop_ptr))
		{
			isThereAnApertureStop = true;
		}

	}

	if (isThereAnApertureStop == false) std::cout << "There is no aperture in your optical system!!!" << std::endl;

}


// calculate the position of all surfaces after the stop
std::vector<real> CardinalPoints::calcPosSurAfterStop()
{
	unsigned int sizeOfOptSys = mOpticalSystem_LLT.getNumberOfSurfaces();
	std::vector<PosAndIntsectionSurfaceStruct> posAndInteraSurfaceVector = mOpticalSystem_LLT.getPosAndInteractingSurface();
	ApertureStop_LLT apertureStop_ptr;
	std::vector<real> PosSurfaceAfterAperStop;

	for (unsigned int i = 0; i < sizeOfOptSys; i++)
	{
		if (typeid(*posAndInteraSurfaceVector.at(i).getSurfaceInterRay_ptr()) == typeid(apertureStop_ptr))
		{
			for (unsigned int j = i + 1; j < sizeOfOptSys; j++)
			{
				real tempZ_Pos = mOpticalSystem_LLT.getPosAndInteractingSurface().at(j).getSurfaceInterRay_ptr()->getPoint().getZ();
				PosSurfaceAfterAperStop.push_back(tempZ_Pos);
			}
		}

	}

	return PosSurfaceAfterAperStop;

}




// calculate the separation of all surfaces after the stop
std::vector<real> CardinalPoints::calcSepSurAfterStop()
{
	unsigned int sizeOfOptSys = mOpticalSystem_LLT.getNumberOfSurfaces();
	std::vector<PosAndIntsectionSurfaceStruct> posAndInteraSurfaceVector = mOpticalSystem_LLT.getPosAndInteractingSurface();
	ApertureStop_LLT apertureStop_ptr;
	std::vector<real> mSepSurfaceAfterStop;

	for (unsigned int i = 0; i < sizeOfOptSys; i++)
	{
		if (typeid(*posAndInteraSurfaceVector.at(i).getSurfaceInterRay_ptr()) == typeid(apertureStop_ptr))
		{

			for (unsigned int j = i + 1; j < sizeOfOptSys; j++)
			{
				real tempZ_Pos = mOpticalSystem_LLT.getPosAndInteractingSurface().at(j).getSurfaceInterRay_ptr()->getPoint().getZ() - mOpticalSystem_LLT.getPosAndInteractingSurface().at(j - 1).getSurfaceInterRay_ptr()->getPoint().getZ();
				mSepSurfaceAfterStop.push_back(tempZ_Pos);

			}
		}

	}

	return mSepSurfaceAfterStop;

}

// calculate the separation of 1st surface and the stop
real CardinalPoints::calcSepSurAndStop()
{
	unsigned int sizeOfOptSys = mOpticalSystem_LLT.getNumberOfSurfaces();
	std::vector<PosAndIntsectionSurfaceStruct> posAndInteraSurfaceVector = mOpticalSystem_LLT.getPosAndInteractingSurface();
	ApertureStop_LLT apertureStop_ptr;

	real mSepSurfaceAndStop;
	unsigned int checker;

	for (unsigned int i = 0; i < sizeOfOptSys; i++)
	{
		if (typeid(*posAndInteraSurfaceVector.at(i).getSurfaceInterRay_ptr()) == typeid(apertureStop_ptr))
		{

			real temp_pos = mOpticalSystem_LLT.getPosAndInteractingSurface().at(i + 1).getSurfaceInterRay_ptr()->getPoint().getZ() - mOpticalSystem_LLT.getPosAndInteractingSurface().at(i).getSurfaceInterRay_ptr()->getPoint().getZ();
			mSepSurfaceAndStop = temp_pos;
		}


	}

	/*/ TODO: find a better solution
	std::cout << "there is no aperture stop in your optical system" << std::endl;
	unsigned int errorInput;
	std::cin >> errorInput;
	*/

	return mSepSurfaceAndStop;

}


//calculate distance between object plane and first surface(first lens)
real CardinalPoints::calcSepObjandSurface()
{
	unsigned int sizeOfOptSys = mOpticalSystem_LLT.getNumberOfSurfaces();
	std::vector<PosAndIntsectionSurfaceStruct> posAndInteraSurfaceVector = mOpticalSystem_LLT.getPosAndInteractingSurface();
	ApertureStop_LLT apertureStop_ptr;

	real mSepObjandSurface;
	unsigned int checker;

	for (unsigned int i = 0; i < sizeOfOptSys; i++)
	{
		if (typeid(*posAndInteraSurfaceVector.at(i).getSurfaceInterRay_ptr()) == typeid(apertureStop_ptr))
		{

			real temp_pos = mOpticalSystem_LLT.getPosAndInteractingSurface().at(1).getSurfaceInterRay_ptr()->getPoint().getZ();
			mSepObjandSurface = temp_pos;
		}


	}


	return mSepObjandSurface;
}

// calculate the separation oflast surface and image plane
real CardinalPoints::calcSepSurAndImPlane()
{
	unsigned int sizeOfOptSys = mOpticalSystem_LLT.getNumberOfSurfaces();
	std::vector<PosAndIntsectionSurfaceStruct> posAndInteraSurfaceVector = mOpticalSystem_LLT.getPosAndInteractingSurface();
	ApertureStop_LLT apertureStop_ptr;
	real mSepSurAndImPlane;

	for (unsigned int i = 0; i < sizeOfOptSys; i++)
	{
		if (typeid(*posAndInteraSurfaceVector.at(i).getSurfaceInterRay_ptr()) == typeid(apertureStop_ptr))
		{

			real tempZ_Pos = mOpticalSystem_LLT.getPosAndInteractingSurface().at(sizeOfOptSys).getSurfaceInterRay_ptr()->getPoint().getZ() - mOpticalSystem_LLT.getPosAndInteractingSurface().at(sizeOfOptSys - 1).getSurfaceInterRay_ptr()->getPoint().getZ();
			mSepSurAndImPlane = tempZ_Pos;

		}

	}

	return mSepSurAndImPlane;

}

// calculate the focal length of all surfaces after the stop
std::vector<real> CardinalPoints::calcFocalLengthAfterStop()
{
	unsigned int sizeOfOptSys = mOpticalSystem_LLT.getNumberOfSurfaces();
	std::vector<PosAndIntsectionSurfaceStruct> posAndInteraSurfaceVector = mOpticalSystem_LLT.getPosAndInteractingSurface();
	ApertureStop_LLT apertureStop_ptr;
	std::vector<real> focalLengthes;

	for (unsigned int i = 0; i < sizeOfOptSys; i++)
	{
		if (typeid(*posAndInteraSurfaceVector.at(i).getSurfaceInterRay_ptr()) == typeid(apertureStop_ptr))
		{
			for (unsigned int j = i + 1; j < sizeOfOptSys; j++)
			{
				real tempFocalLength = mOpticalSystem_LLT.getPosAndInteractingSurface().at(j).getSurfaceInterRay_ptr()->getFocalLength_B();
				focalLengthes.push_back(tempFocalLength);
			}
		}

	}

	return focalLengthes;

}


// calculate the radius of all surfaces after the stop
std::vector<real> CardinalPoints::calcRadiusAfterStop()
{
	unsigned int sizeOfOptSys = mOpticalSystem_LLT.getNumberOfSurfaces();
	std::vector<PosAndIntsectionSurfaceStruct> posAndInteraSurfaceVector = mOpticalSystem_LLT.getPosAndInteractingSurface();
	ApertureStop_LLT apertureStop_ptr;
	std::vector<real> Radius;

	for (unsigned int i = 0; i < sizeOfOptSys; i++)
	{
		if (typeid(*posAndInteraSurfaceVector.at(i).getSurfaceInterRay_ptr()) == typeid(apertureStop_ptr))
		{

			for (unsigned int j = i + 1; j < sizeOfOptSys; j++)
			{
				real tempRadius = mOpticalSystem_LLT.getPosAndInteractingSurface().at(j).getSurfaceInterRay_ptr()->getRadius();
				real tempDirectionZ = mOpticalSystem_LLT.getPosAndInteractingSurface().at(j).getSurfaceInterRay_ptr()->getDirection().getZ();
				int sign = 1;
				if (tempDirectionZ < 0)
				{
					sign = -1;
				}

				Radius.push_back(sign * tempRadius);
			}
		}

	}

	return Radius;

}




// calculate the refractive index after all surfaces after the stop
std::vector<real> CardinalPoints::calcRefractivIndexesAfterStop()
{
	unsigned int sizeOfOptSys = mOpticalSystem_LLT.getNumberOfSurfaces();
	std::vector<PosAndIntsectionSurfaceStruct> posAndInteraSurfaceVector = mOpticalSystem_LLT.getPosAndInteractingSurface();
	ApertureStop_LLT apertureStop_ptr;
	std::vector<real> refracticeIndex;

	for (unsigned int i = 0; i < sizeOfOptSys; i++)
	{
		if (typeid(*posAndInteraSurfaceVector.at(i).getSurfaceInterRay_ptr()) == typeid(apertureStop_ptr))
		{

			for (unsigned int j = i + 1; j < sizeOfOptSys; j++)
			{
				real tempDirectionZ = mOpticalSystem_LLT.getPosAndInteractingSurface().at(j).getSurfaceInterRay_ptr()->getDirection().getZ();


				if (tempDirectionZ > 0)
				{
					real tempRefIndex = mOpticalSystem_LLT.getPosAndInteractingSurface().at(j).getSurfaceInterRay_ptr()->getRefractiveIndex_B();
					refracticeIndex.push_back(tempRefIndex);
				}
				else if (tempDirectionZ < 0)
				{
					real tempRefIndex = mOpticalSystem_LLT.getPosAndInteractingSurface().at(j).getSurfaceInterRay_ptr()->getRefractiveIndex_A();
					refracticeIndex.push_back(tempRefIndex);
				}
				else
				{
					std::cout << "there is an mistake in the direction!!! the Z value is 0!!!" << std::endl;

				}
			}

		}

	}

	return refracticeIndex;

}

// calculate aperture size
real CardinalPoints::calcDiameterAperture()
{
	unsigned int sizeOfOptSys = mOpticalSystem_LLT.getNumberOfSurfaces();
	std::vector<PosAndIntsectionSurfaceStruct> posAndInteraSurfaceVector = mOpticalSystem_LLT.getPosAndInteractingSurface();
	ApertureStop_LLT apertureStop_ptr;
	real dimameterOfAperture = -99999.0;

	for (unsigned int i = 0; i < sizeOfOptSys; i++)
	{
		if (typeid(*posAndInteraSurfaceVector.at(i).getSurfaceInterRay_ptr()) == typeid(apertureStop_ptr))
		{
			return dimameterOfAperture = 2 * mOpticalSystem_LLT.getPosAndInteractingSurface().at(i).getSurfaceInterRay_ptr()->getSemiHeight();
		}

	}

	if (dimameterOfAperture == -99999.0)
	{
		std::cout << "You have to define an aperture stop!!!" << std::endl;
	}

	return dimameterOfAperture;

}

std::vector<real> CardinalPoints::calcSystemMatrix()
{

	using namespace std;


	/*******************************************input values***********************************/
	unsigned int sizeOfOptSys = mOpticalSystem_LLT.getNumberOfSurfaces();
	ApertureStop_LLT apertureStop_ptr;
	int PosAperturStop = 0;
	std::vector<PosAndIntsectionSurfaceStruct> posAndInteraSurfaceVector = mOpticalSystem_LLT.getPosAndInteractingSurface();
	int s = sizeOfOptSys - 1;
	for (unsigned int i = 1; i < s; i++)
	{
		if (typeid(*posAndInteraSurfaceVector.at(i).getSurfaceInterRay_ptr()) == typeid(apertureStop_ptr))
		{
			s = sizeOfOptSys - i - 1;
		}
	}

	std::vector<double> R_ip = mRadiusAfterStop;
	std::vector<double> n_ip = mRefractivIndexesAfterStop;
	std::vector<double> d_ip = mSepSurfaceAfterStop;
	double image_plane = mSepSurAndImPlane;
	double aperture_size = mDiameterOfApertureStop;
	double sto = mSepSurfaceAndStop;
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

		R_i[i] = R_ip[s - i - 1];

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

		d_i[i] = d_ip[s - i - 1];

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

		n_i[i] = n_ip[s - i - 1];

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
	for (int i = 0; i < 2; i++)
	{

		vector < vector < double > > w;
		t.push_back(w);
		for (int j = 0; j < 2; j++)
		{
			vector <double> v;
			t[i].push_back(v);
			for (int k = 0; k < 2 * s - 2; k++)
			{
				t[i][j].push_back(0);
			}
		}
	}


	vector < vector < vector<double> > > r;
	for (int i = 0; i < 2; i++)
	{

		vector < vector < double > > xi;
		r.push_back(xi);
		for (int j = 0; j < 2; j++)
		{
			vector <double> zi;
			r[i].push_back(zi);
			for (int k = 0; k < 2 * s - 1; k++)
			{
				r[i][j].push_back(0);
			}
		}
	}



	/*******************************spherical surface************************************************/

	double mult[2][2];

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


	std::vector<double> matrixABCD;
	matrixABCD.push_back(matrix2D[0][0]);
	matrixABCD.push_back(matrix2D[0][1]);
	matrixABCD.push_back(matrix2D[1][0]);
	matrixABCD.push_back(matrix2D[1][1]);


	/*	cout << " System Matrix of surfaces after the apertur stop: " << endl << endl;
		for (int i = 0; i < 4; i++)
		{
			cout << " " << matrixABCD[i];
			if (i == 1)
			{
				cout << " " << endl;

			}
			else
				cout << "  ";
		}

		cout << " " << endl;*/

	return matrixABCD;

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


	ApertureStop_LLT apertureStop_ptr;

	std::vector<PosAndIntsectionSurfaceStruct> posAndInteraSurfaceVector = mOpticalSystem_LLT.getPosAndInteractingSurface();


	if (typeid(*posAndInteraSurfaceVector.at(0).getSurfaceInterRay_ptr()) == typeid(apertureStop_ptr))
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
	std::vector<double> matrixABCD = mSystemMatrix;

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
	std::vector<double> matrixABCD = mSystemMatrix;

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


std::vector<real> CardinalPoints::calcAllRadius()
{

	unsigned int sizeOfOptSys = mOpticalSystem_LLT.getNumberOfSurfaces();
	std::vector<PosAndIntsectionSurfaceStruct> posAndInteraSurfaceVector = mOpticalSystem_LLT.getPosAndInteractingSurface();
	ApertureStop_LLT apertureStop_ptr;
	std::vector<real> Radius;

	for (unsigned int i = 0; i < sizeOfOptSys; i++)
	{
		if (typeid(*posAndInteraSurfaceVector.at(i).getSurfaceInterRay_ptr()) != typeid(apertureStop_ptr))
		{
			real tempRadius = mOpticalSystem_LLT.getPosAndInteractingSurface().at(i).getSurfaceInterRay_ptr()->getRadius();
			real tempDirectionZ = mOpticalSystem_LLT.getPosAndInteractingSurface().at(i).getSurfaceInterRay_ptr()->getDirection().getZ();
			int sign = 1;
			if (tempDirectionZ < 0)
			{
				sign = -1;
			}

			Radius.push_back(sign * tempRadius);

		}

	}

	return Radius;

}


std::vector<real> CardinalPoints::calcAllRefractivIndexes()
{
	unsigned int sizeOfOptSys = mOpticalSystem_LLT.getNumberOfSurfaces();
	std::vector<PosAndIntsectionSurfaceStruct> posAndInteraSurfaceVector = mOpticalSystem_LLT.getPosAndInteractingSurface();
	ApertureStop_LLT apertureStop_ptr;
	std::vector<real> refractiveIndex;

	for (unsigned int i = 0; i < sizeOfOptSys; i++)
	{
		if (typeid(*posAndInteraSurfaceVector.at(i).getSurfaceInterRay_ptr()) != typeid(apertureStop_ptr))
		{


			real tempDirectionZ = mOpticalSystem_LLT.getPosAndInteractingSurface().at(i).getSurfaceInterRay_ptr()->getDirection().getZ();


			if (tempDirectionZ > 0)
			{
				real tempRefIndex = mOpticalSystem_LLT.getPosAndInteractingSurface().at(i).getSurfaceInterRay_ptr()->getRefractiveIndex_B();
				refractiveIndex.push_back(tempRefIndex);

			}
			else if (tempDirectionZ < 0)
			{
				real tempRefIndex = mOpticalSystem_LLT.getPosAndInteractingSurface().at(i).getSurfaceInterRay_ptr()->getRefractiveIndex_A();
				refractiveIndex.push_back(tempRefIndex);

			}
			else
			{
				std::cout << "there is an mistake in the direction!!! the Z value is 0!!!" << std::endl;

			}


		}

	}

	return refractiveIndex;

}

std::vector<real> CardinalPoints::calcAllSepSur()
{
	unsigned int sizeOfOptSys = mOpticalSystem_LLT.getNumberOfSurfaces();
	std::vector<PosAndIntsectionSurfaceStruct> posAndInteraSurfaceVector = mOpticalSystem_LLT.getPosAndInteractingSurface();
	ApertureStop_LLT apertureStop_ptr;
	std::vector<real> mSepSurfaceAfterStop;

	for (unsigned int i = 0; i < sizeOfOptSys; i++)
	{
		if (typeid(*posAndInteraSurfaceVector.at(i).getSurfaceInterRay_ptr()) != typeid(apertureStop_ptr))
		{
			if (typeid(*posAndInteraSurfaceVector.at(i + 1).getSurfaceInterRay_ptr()) != typeid(apertureStop_ptr))
			{
				real tempZ_Pos = mOpticalSystem_LLT.getPosAndInteractingSurface().at(i + 1).getSurfaceInterRay_ptr()->getPoint().getZ() - mOpticalSystem_LLT.getPosAndInteractingSurface().at(i).getSurfaceInterRay_ptr()->getPoint().getZ();
				mSepSurfaceAfterStop.push_back(tempZ_Pos);

			}
			else
			{
				real tempZ_Pos = mOpticalSystem_LLT.getPosAndInteractingSurface().at(i + 2).getSurfaceInterRay_ptr()->getPoint().getZ() - mOpticalSystem_LLT.getPosAndInteractingSurface().at(i).getSurfaceInterRay_ptr()->getPoint().getZ();
				mSepSurfaceAfterStop.push_back(tempZ_Pos);

			}
		}

	}

	return mSepSurfaceAfterStop;

}



std::vector<real> CardinalPoints::calcAllSystemMatrix()
{

	using namespace std;

	/*******************************************input values***********************************/
	unsigned int sizeOfOptSys = mOpticalSystem_LLT.getNumberOfSurfaces();
	int s = sizeOfOptSys - 1;
	std::vector<double> R_ip = mAllRadius;
	std::vector<double> n_ip = AllmRefractivIndexes;
	std::vector<double> d_ip = AllmSepSurface;

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

		R_i[i] = R_ip[s - i - 1];

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

		d_i[i] = d_ip[s - i - 2];


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

		n_i[i] = n_ip[s - i - 1];


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
	for (int i = 0; i < 2; i++)
	{

		vector < vector < double > > w;
		t.push_back(w);
		for (int j = 0; j < 2; j++)
		{
			vector <double> v;
			t[i].push_back(v);
			for (int k = 0; k < 2 * s - 2; k++)
			{
				t[i][j].push_back(0);
			}
		}
	}


	vector < vector < vector<double> > > r;
	for (int i = 0; i < 2; i++)
	{

		vector < vector < double > > xi;
		r.push_back(xi);
		for (int j = 0; j < 2; j++)
		{
			vector <double> zi;
			r[i].push_back(zi);
			for (int k = 0; k < 2 * s - 1; k++)
			{
				r[i][j].push_back(0);
			}
		}
	}



	/*******************************spherical surface************************************************/

	double mult[2][2];

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


	std::vector<double> matrixABCD;
	matrixABCD.push_back(matrix2D[0][0]);
	matrixABCD.push_back(matrix2D[0][1]);
	matrixABCD.push_back(matrix2D[1][0]);
	matrixABCD.push_back(matrix2D[1][1]);


	/*	cout <<endl << "System Matrix of all the surfaces: " << endl << endl;
		for (int i = 0; i < 4; i++)
		{
			cout << " " << matrixABCD[i];
			if (i == 1)
			{
				cout << " " << endl;

			}
			else
				cout << "  ";
		}

		cout << " " << endl;*/

	return matrixABCD;

}

