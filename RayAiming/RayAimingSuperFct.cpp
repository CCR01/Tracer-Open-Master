#include "RayAimingSuperFct.h"
#include "RayAiming.h"
#include <omp.h>

#include "..\..\FillAptertureStop\FillApertureStop.h"

RayAiming_12Cores::RayAiming_12Cores() {}

RayAiming_12Cores::~RayAiming_12Cores() {}

RayAiming_12Cores::RayAiming_12Cores(const /*optical system*/ OpticalSystem_LLT& optSys_LLT, /*rings*/ unsigned int rings,/*arms*/ unsigned int arms, const /*start point ray*/ VectorStructR3 startPointRay, Light_LLT /*light*/ light, real /*start ref index*/ curRefracIndex) :
	mOptcalSystem_LLT(optSys_LLT),
	mRings(rings),
	mArms(arms),
	mStartPointRay(startPointRay),
	mLight(light),
	mCurRefIndex(curRefracIndex)
	{
	mSetDefaulParameter = false;
	loadPointsInAS();
	splitPointsInAsFor12Cores();
	calcAimedLightRay_vec_12cores_obj();
	}

void RayAiming_12Cores::loadPointsInAS()
{
	// find position aperture stop in opt sys
	infosAS infosASinOptSysLLT = mOptcalSystem_LLT.getInforAS();
	FillApertureStop fillAS(infosASinOptSysLLT, mRings, mArms);
	
	mPointsInAS = fillAS.getPointsInAS();
}

void RayAiming_12Cores::splitPointsInAsFor12Cores()
{
	mNumberPointsInAS = mPointsInAS.size();
	unsigned int numberCores = 12;
	unsigned int calcModulo = mNumberPointsInAS % numberCores;

	unsigned minNumberCore = std::floor(mNumberPointsInAS / numberCores);
	unsigned int counter = 0;


	unsigned int minNumberCorePlusOne = minNumberCore + 1;
	mPoints_1.reserve(minNumberCorePlusOne);
	mPoints_2.reserve(minNumberCorePlusOne);
	mPoints_3.reserve(minNumberCorePlusOne);
	mPoints_4.reserve(minNumberCorePlusOne);
	mPoints_5.reserve(minNumberCorePlusOne);
	mPoints_6.reserve(minNumberCorePlusOne);
	mPoints_7.reserve(minNumberCorePlusOne);
	mPoints_8.reserve(minNumberCorePlusOne);
	mPoints_9.reserve(minNumberCorePlusOne);
	mPoints_10.reserve(minNumberCorePlusOne);
	mPoints_11.reserve(minNumberCorePlusOne);
	mPoints_12.reserve(minNumberCorePlusOne);

	bool checker = true;

	while (checker)
	{
		if (counter < mNumberPointsInAS)
		{
			mPoints_1.push_back(mPointsInAS[counter]);
			++counter;
		}

		if (counter < mNumberPointsInAS)
		{
			mPoints_2.push_back(mPointsInAS[counter]);
			++counter;
		}

		if (counter < mNumberPointsInAS)
		{
			mPoints_3.push_back(mPointsInAS[counter]);
			++counter;
		}

		if (counter < mNumberPointsInAS)
		{
			mPoints_4.push_back(mPointsInAS[counter]);
			++counter;
		}


		if (counter < mNumberPointsInAS)
		{
			mPoints_5.push_back(mPointsInAS[counter]);
			++counter;
		}

		if (counter < mNumberPointsInAS)
		{
			mPoints_6.push_back(mPointsInAS[counter]);
			++counter;
		}

		if (counter < mNumberPointsInAS)
		{
			mPoints_7.push_back(mPointsInAS[counter]);
			++counter;
		}

		if (counter < mNumberPointsInAS)
		{
			mPoints_8.push_back(mPointsInAS[counter]);
			++counter;
		}

		if (counter < mNumberPointsInAS)
		{
			mPoints_9.push_back(mPointsInAS[counter]);
			++counter;
		}

		if (counter < mNumberPointsInAS)
		{
			mPoints_10.push_back(mPointsInAS[counter]);
			++counter;
		}

		if (counter < mNumberPointsInAS)
		{
			mPoints_11.push_back(mPointsInAS[counter]);
			++counter;
		}

		if (counter < mNumberPointsInAS)
		{
			mPoints_12.push_back(mPointsInAS[counter]);
			++counter;
		}

		if (counter >= mNumberPointsInAS)
		{
			checker = false;
		}

	}


}

std::vector<LightRayStruct> RayAiming_12Cores::getAimedLightRays()
{
	return mAimedLightRays;
}

void RayAiming_12Cores::loadInput(/*optical system*/ OpticalSystem_LLT optSys_LLT, /*rings*/ unsigned int rings,/*arms*/ unsigned int arms, const /*start point ray*/ VectorStructR3 startPointRay, Light_LLT /*light*/ light, real /*start ref index*/ curRefracIndex)
{
	mOptcalSystem_LLT = optSys_LLT.clone();
	mRings = rings;
	mArms = arms;
	mStartPointRay = startPointRay;
	mLight = light;
	mCurRefIndex = curRefracIndex;
}

void RayAiming_12Cores::loadDefaultParameter(defaultRayAimingStruct defaulParaRayAim)
{
	mDefaulParaRayAiming = defaulParaRayAim;
	mSetDefaulParameter = true;
}

std::vector<LightRayStruct> RayAiming_12Cores::calcAimedLightRay_vec_12cores_obj()
{
	int nProcessors = omp_get_max_threads();
	// check if there are 6 threads
	if (nProcessors < 12)
	{
		std::cout << "there are no 12 threads to do the optimization" << std::endl;
	}

	unsigned int numberOfPointsInAS = mPointsInAS.size();

	std::vector<LightRayStruct> lightRayCore_1;
	std::vector<LightRayStruct> lightRayCore_2;
	std::vector<LightRayStruct> lightRayCore_3;
	std::vector<LightRayStruct> lightRayCore_4;
	std::vector<LightRayStruct> lightRayCore_5;
	std::vector<LightRayStruct> lightRayCore_6;
	std::vector<LightRayStruct> lightRayCore_7;
	std::vector<LightRayStruct> lightRayCore_8;
	std::vector<LightRayStruct> lightRayCore_9;
	std::vector<LightRayStruct> lightRayCore_10;
	std::vector<LightRayStruct> lightRayCore_11;
	std::vector<LightRayStruct> lightRayCore_12;



	#pragma omp parallel sections
	{
		#pragma omp section // 1
		{
			// std::cout << "start ray aiming in core 1" << std::endl;
			RayAiming rayAiming_1(mOptcalSystem_LLT.clone());
			if(mSetDefaulParameter)
			{
				rayAiming_1.setDefaultParameters(mDefaulParaRayAiming);
			}
			lightRayCore_1 = rayAiming_1.rayAimingMany_obj(mPoints_1, mStartPointRay, mLight, mCurRefIndex);
		}

		#pragma omp section // 2
		{
			// std::cout << "start ray aiming in core 2" << std::endl;
			RayAiming rayAiming_2(mOptcalSystem_LLT.clone());
			if (mSetDefaulParameter)
			{
				rayAiming_2.setDefaultParameters(mDefaulParaRayAiming);
			}
			lightRayCore_2 = rayAiming_2.rayAimingMany_obj(mPoints_2, mStartPointRay, mLight, mCurRefIndex);
		}

		#pragma omp section // 3
		{
			// std::cout << "start ray aiming in core 3" << std::endl;
			RayAiming rayAiming_3(mOptcalSystem_LLT.clone());
			if (mSetDefaulParameter)
			{
				rayAiming_3.setDefaultParameters(mDefaulParaRayAiming);
			}
			lightRayCore_3 = rayAiming_3.rayAimingMany_obj(mPoints_3, mStartPointRay, mLight, mCurRefIndex);
		}

		#pragma omp section // 4
		{
			// std::cout << "start ray aiming in core 4" << std::endl;
			RayAiming rayAiming_4(mOptcalSystem_LLT.clone());
			if (mSetDefaulParameter)
			{
				rayAiming_4.setDefaultParameters(mDefaulParaRayAiming);
			}
			lightRayCore_4 = rayAiming_4.rayAimingMany_obj(mPoints_4, mStartPointRay, mLight, mCurRefIndex);
		}

		#pragma omp section // 5
		{
			// std::cout << "start ray aiming in core 5" << std::endl;
			RayAiming rayAiming_5(mOptcalSystem_LLT.clone());
			if (mSetDefaulParameter)
			{
				rayAiming_5.setDefaultParameters(mDefaulParaRayAiming);
			}
			lightRayCore_5 = rayAiming_5.rayAimingMany_obj(mPoints_5, mStartPointRay, mLight, mCurRefIndex);
		}

		#pragma omp section // 6
		{
			// std::cout << "start ray aiming in core 6" << std::endl;
			RayAiming rayAiming_6(mOptcalSystem_LLT.clone());
			if (mSetDefaulParameter)
			{
				rayAiming_6.setDefaultParameters(mDefaulParaRayAiming);
			}
			lightRayCore_6 = rayAiming_6.rayAimingMany_obj(mPoints_6, mStartPointRay, mLight, mCurRefIndex);
		}

		#pragma omp section // 7
		{
			// std::cout << "start ray aiming in core 7" << std::endl;
			RayAiming rayAiming_7(mOptcalSystem_LLT.clone());
			if (mSetDefaulParameter)
			{
				rayAiming_7.setDefaultParameters(mDefaulParaRayAiming);
			}
			lightRayCore_7 = rayAiming_7.rayAimingMany_obj(mPoints_7, mStartPointRay, mLight, mCurRefIndex);
		}

		#pragma omp section // 8
		{
			// std::cout << "start ray aiming in core 8" << std::endl;
			RayAiming rayAiming_8(mOptcalSystem_LLT.clone());
			if (mSetDefaulParameter)
			{
				rayAiming_8.setDefaultParameters(mDefaulParaRayAiming);
			}
			lightRayCore_8 = rayAiming_8.rayAimingMany_obj(mPoints_8, mStartPointRay, mLight, mCurRefIndex);
		}

		#pragma omp section // 9
		{
			// std::cout << "start ray aiming in core 9" << std::endl;
			RayAiming rayAiming_9(mOptcalSystem_LLT.clone());
			if (mSetDefaulParameter)
			{
				rayAiming_9.setDefaultParameters(mDefaulParaRayAiming);
			}
			lightRayCore_9 = rayAiming_9.rayAimingMany_obj(mPoints_9, mStartPointRay, mLight, mCurRefIndex);
		}

		#pragma omp section // 10
		{
			// std::cout << "start ray aiming in core 10" << std::endl;
			RayAiming rayAiming_10(mOptcalSystem_LLT.clone());
			if (mSetDefaulParameter)
			{
				rayAiming_10.setDefaultParameters(mDefaulParaRayAiming);
			}
			lightRayCore_10 = rayAiming_10.rayAimingMany_obj(mPoints_10, mStartPointRay, mLight, mCurRefIndex);
		}

		#pragma omp section // 11
		{
			// std::cout << "start ray aiming in core 11" << std::endl;
			RayAiming rayAiming_11(mOptcalSystem_LLT.clone());
			if (mSetDefaulParameter)
			{
				rayAiming_11.setDefaultParameters(mDefaulParaRayAiming);
			}
			lightRayCore_11 = rayAiming_11.rayAimingMany_obj(mPoints_11, mStartPointRay, mLight, mCurRefIndex);
		}

		#pragma omp section // 12
		{
			// std::cout << "start ray aiming in core 12" << std::endl;
			RayAiming rayAiming_12(mOptcalSystem_LLT.clone());
			if (mSetDefaulParameter)
			{
				rayAiming_12.setDefaultParameters(mDefaulParaRayAiming);
			}
			lightRayCore_12 = rayAiming_12.rayAimingMany_obj(mPoints_12, mStartPointRay, mLight, mCurRefIndex);
		}
	}



	std::vector<LightRayStruct> returnAllAimedLightRays{};
	returnAllAimedLightRays.reserve(mNumberPointsInAS);

	returnAllAimedLightRays.insert(std::end(returnAllAimedLightRays), std::begin(lightRayCore_1), std::end(lightRayCore_1));
	returnAllAimedLightRays.insert(std::end(returnAllAimedLightRays), std::begin(lightRayCore_2), std::end(lightRayCore_2));
	returnAllAimedLightRays.insert(std::end(returnAllAimedLightRays), std::begin(lightRayCore_3), std::end(lightRayCore_3));
	returnAllAimedLightRays.insert(std::end(returnAllAimedLightRays), std::begin(lightRayCore_4), std::end(lightRayCore_4));
	returnAllAimedLightRays.insert(std::end(returnAllAimedLightRays), std::begin(lightRayCore_5), std::end(lightRayCore_5));
	returnAllAimedLightRays.insert(std::end(returnAllAimedLightRays), std::begin(lightRayCore_6), std::end(lightRayCore_6));
	returnAllAimedLightRays.insert(std::end(returnAllAimedLightRays), std::begin(lightRayCore_7), std::end(lightRayCore_7));
	returnAllAimedLightRays.insert(std::end(returnAllAimedLightRays), std::begin(lightRayCore_8), std::end(lightRayCore_8));
	returnAllAimedLightRays.insert(std::end(returnAllAimedLightRays), std::begin(lightRayCore_9), std::end(lightRayCore_9));
	returnAllAimedLightRays.insert(std::end(returnAllAimedLightRays), std::begin(lightRayCore_10), std::end(lightRayCore_10));
	returnAllAimedLightRays.insert(std::end(returnAllAimedLightRays), std::begin(lightRayCore_11), std::end(lightRayCore_11));
	returnAllAimedLightRays.insert(std::end(returnAllAimedLightRays), std::begin(lightRayCore_12), std::end(lightRayCore_12));

	mAimedLightRays = returnAllAimedLightRays;

	return returnAllAimedLightRays;
}



