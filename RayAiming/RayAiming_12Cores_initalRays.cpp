#include "RayAiming_12Cores_initalRays.h"

// fill aperture stop
#include "..\..\FillAptertureStop\FillApertureStop.h"

// omp
#include <omp.h>


RayAiming_12Cores_initalRays::RayAiming_12Cores_initalRays() {};

RayAiming_12Cores_initalRays::~RayAiming_12Cores_initalRays() {};

void RayAiming_12Cores_initalRays::loadInput(/*optical system*/ OpticalSystemElement optSysEle, /*rings*/ unsigned int rings,/*arms*/ unsigned int arms, const /*start point ray*/ VectorStructR3 startPointRay, Light_LLT /*light*/ light, /*wavelength vector*/ std::vector<real> wavelength_vec)
{
	mOptiSysEle = optSysEle;
	mRings = rings;
	mArms = arms;
	mStartPointRay = startPointRay;
	mLight = light;
	mWavelength_vec = wavelength_vec;
}

void RayAiming_12Cores_initalRays::loadDefaultParameter_initalRays(defaultRayAimingStruct defaulParaRayAim_initalRays)
{
	mDefaulParaRayAiming_initalRays = defaulParaRayAim_initalRays;
	mSetDefaulParameter = true;
}

void RayAiming_12Cores_initalRays::loadPointsInAS()
{
	// find position aperture stop in opt sys
	infosAS infosASinOptSysLLT = mOptiSysEle.getInfoAS();
	FillApertureStop fillAS(infosASinOptSysLLT, mRings, mArms);

	mPointsInAS = fillAS.getPointsInAS();
}

std::vector<std::vector<LightRayStruct>> RayAiming_12Cores_initalRays::getAimedLightRays()
{
	return mAllAimedLightRays;
}

void RayAiming_12Cores_initalRays::splitPointsInAsFor12Cores()
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

std::vector<std::vector<LightRayStruct>> RayAiming_12Cores_initalRays::calcRayAimingInitalRays_vec_12cores_obj()
{
	int nProcessors = omp_get_max_threads();
	// check if there are 6 threads
	if (nProcessors < 12)
	{
		std::cout << "there are no 12 threads to do the optimization" << std::endl;
	}

	unsigned int numberOfPointsInAS = mPointsInAS.size();

	std::vector<std::vector<LightRayStruct>> lightRayCore_1;
	std::vector<std::vector<LightRayStruct>> lightRayCore_2;
	std::vector<std::vector<LightRayStruct>> lightRayCore_3;
	std::vector<std::vector<LightRayStruct>> lightRayCore_4;
	std::vector<std::vector<LightRayStruct>> lightRayCore_5;
	std::vector<std::vector<LightRayStruct>> lightRayCore_6;
	std::vector<std::vector<LightRayStruct>> lightRayCore_7;
	std::vector<std::vector<LightRayStruct>> lightRayCore_8;
	std::vector<std::vector<LightRayStruct>> lightRayCore_9;
	std::vector<std::vector<LightRayStruct>> lightRayCore_10;
	std::vector<std::vector<LightRayStruct>> lightRayCore_11;
	std::vector<std::vector<LightRayStruct>> lightRayCore_12;



#pragma omp parallel sections
	{
	#pragma omp section // _1
	{
		// std::cout << "start ray aiming in core _1" << std::endl;
		RayAiming rayAiming_1;
		if (mSetDefaulParameter)
		{
			rayAiming_1.setDefaultParameters(mDefaulParaRayAiming_initalRays);
			rayAiming_1.setDefaultParametersInitalRays_obj_initalRays();
		}

		OpticalSystemElement optSysEle_1 = mOptiSysEle.getDeepCopyOptSysEle();
		lightRayCore_1 = rayAiming_1.rayAiming_obj_initalRays_complete(optSysEle_1, mPoints_1, mWavelength_vec, mStartPointRay, mLight);
		mTime_sec_1 = rayAiming_1.getTime_sec();

	}

	#pragma omp section // _2
	{
		// std::cout << "start ray aiming in core _2" << std::endl;
		RayAiming rayAiming_2;
		if (mSetDefaulParameter)
		{
			rayAiming_2.setDefaultParameters(mDefaulParaRayAiming_initalRays);
			rayAiming_2.setDefaultParametersInitalRays_obj_initalRays();
		}

		OpticalSystemElement optSysEle_2 = mOptiSysEle.getDeepCopyOptSysEle();
		lightRayCore_2 = rayAiming_2.rayAiming_obj_initalRays_complete(optSysEle_2, mPoints_2, mWavelength_vec, mStartPointRay, mLight);
		mTime_sec_2 = rayAiming_2.getTime_sec();

	}

	#pragma omp section // _3
	{
		// std::cout << "start ray aiming in core _3" << std::endl;
		RayAiming rayAiming_3;
		if (mSetDefaulParameter)
		{
			rayAiming_3.setDefaultParameters(mDefaulParaRayAiming_initalRays);
			rayAiming_3.setDefaultParametersInitalRays_obj_initalRays();
		}
		OpticalSystemElement optSysEle_3 = mOptiSysEle.getDeepCopyOptSysEle();
		lightRayCore_3 = rayAiming_3.rayAiming_obj_initalRays_complete(optSysEle_3, mPoints_3, mWavelength_vec, mStartPointRay, mLight);
		mTime_sec_3 = rayAiming_3.getTime_sec();

	}
	//
	#pragma omp section // _4
	{
		// std::cout << "start ray aiming in core _4" << std::endl;
		RayAiming rayAiming_4;
		if (mSetDefaulParameter)
		{
			rayAiming_4.setDefaultParameters(mDefaulParaRayAiming_initalRays);
			rayAiming_4.setDefaultParametersInitalRays_obj_initalRays();
		}
		OpticalSystemElement optSysEle_4 = mOptiSysEle.getDeepCopyOptSysEle();
		lightRayCore_4 = rayAiming_4.rayAiming_obj_initalRays_complete(optSysEle_4, mPoints_4, mWavelength_vec, mStartPointRay, mLight);
		mTime_sec_4 = rayAiming_4.getTime_sec();

	}
	//
	#pragma omp section // _5
	{
		// std::cout << "start ray aiming in core _5" << std::endl;
		RayAiming rayAiming_5;
		if (mSetDefaulParameter)
		{
			rayAiming_5.setDefaultParameters(mDefaulParaRayAiming_initalRays);
			rayAiming_5.setDefaultParametersInitalRays_obj_initalRays();
		}
		OpticalSystemElement optSysEle_5 = mOptiSysEle.getDeepCopyOptSysEle();
		lightRayCore_5 = rayAiming_5.rayAiming_obj_initalRays_complete(optSysEle_5, mPoints_5, mWavelength_vec, mStartPointRay, mLight);
		mTime_sec_5 = rayAiming_5.getTime_sec();

	}
	//
	#pragma omp section // _6
	{
		// std::cout << "start ray aiming in core _6" << std::endl;
		RayAiming rayAiming_6;
		if (mSetDefaulParameter)
		{
			rayAiming_6.setDefaultParameters(mDefaulParaRayAiming_initalRays);
			rayAiming_6.setDefaultParametersInitalRays_obj_initalRays();
		}
		OpticalSystemElement optSysEle_6 = mOptiSysEle.getDeepCopyOptSysEle();
		lightRayCore_6 = rayAiming_6.rayAiming_obj_initalRays_complete(optSysEle_6, mPoints_6, mWavelength_vec, mStartPointRay, mLight);
		mTime_sec_6 = rayAiming_6.getTime_sec();

	}

	#pragma omp section // _7
	{
		// std::cout << "start ray aiming in core _7" << std::endl;
		RayAiming rayAiming_7;
		if (mSetDefaulParameter)
		{
			rayAiming_7.setDefaultParameters(mDefaulParaRayAiming_initalRays);
			rayAiming_7.setDefaultParametersInitalRays_obj_initalRays();
		}
		OpticalSystemElement optSysEle_7 = mOptiSysEle.getDeepCopyOptSysEle();
		lightRayCore_7 = rayAiming_7.rayAiming_obj_initalRays_complete(optSysEle_7, mPoints_7, mWavelength_vec, mStartPointRay, mLight);
		mTime_sec_7 = rayAiming_7.getTime_sec();

	}

	#pragma omp section // _8
	{
		// std::cout << "start ray aiming in core _8" << std::endl;
		RayAiming rayAiming_8;
		if (mSetDefaulParameter)
		{
			rayAiming_8.setDefaultParameters(mDefaulParaRayAiming_initalRays);
			rayAiming_8.setDefaultParametersInitalRays_obj_initalRays();
		}
		OpticalSystemElement optSysEle_8 = mOptiSysEle.getDeepCopyOptSysEle();
		lightRayCore_8 = rayAiming_8.rayAiming_obj_initalRays_complete(optSysEle_8, mPoints_8, mWavelength_vec, mStartPointRay, mLight);
		mTime_sec_8 = rayAiming_8.getTime_sec();

	}

	#pragma omp section // _9
	{
		// std::cout << "start ray aiming in core _9" << std::endl;
		RayAiming rayAiming_9;
		if (mSetDefaulParameter)
		{
			rayAiming_9.setDefaultParameters(mDefaulParaRayAiming_initalRays);
			rayAiming_9.setDefaultParametersInitalRays_obj_initalRays();
		}
		OpticalSystemElement optSysEle_9 = mOptiSysEle.getDeepCopyOptSysEle();
		lightRayCore_9 = rayAiming_9.rayAiming_obj_initalRays_complete(optSysEle_9, mPoints_9, mWavelength_vec, mStartPointRay, mLight);
		mTime_sec_9 = rayAiming_9.getTime_sec();

	}

	#pragma omp section // _10
	{
		// std::cout << "start ray aiming in core _10" << std::endl;
		RayAiming rayAiming_10;
		if (mSetDefaulParameter)
		{
			rayAiming_10.setDefaultParameters(mDefaulParaRayAiming_initalRays);
			rayAiming_10.setDefaultParametersInitalRays_obj_initalRays();
		}
		OpticalSystemElement optSysEle_10 = mOptiSysEle.getDeepCopyOptSysEle();
		lightRayCore_10 = rayAiming_10.rayAiming_obj_initalRays_complete(optSysEle_10, mPoints_10, mWavelength_vec, mStartPointRay, mLight);
		mTime_sec_10 = rayAiming_10.getTime_sec();

	}

	#pragma omp section // _11
	{
		// std::cout << "start ray aiming in core _11" << std::endl;
		RayAiming rayAiming_11;
		if (mSetDefaulParameter)
		{
			rayAiming_11.setDefaultParameters(mDefaulParaRayAiming_initalRays);
			rayAiming_11.setDefaultParametersInitalRays_obj_initalRays();
		}
		OpticalSystemElement optSysEle_11 = mOptiSysEle.getDeepCopyOptSysEle();
		lightRayCore_11 = rayAiming_11.rayAiming_obj_initalRays_complete(optSysEle_11, mPoints_11, mWavelength_vec, mStartPointRay, mLight);
		mTime_sec_11 = rayAiming_11.getTime_sec();

	}

	#pragma omp section // _12
	{
		// std::cout << "start ray aiming in core _12" << std::endl;
		RayAiming rayAiming_12;
		if (mSetDefaulParameter)
		{
			rayAiming_12.setDefaultParameters(mDefaulParaRayAiming_initalRays);
			rayAiming_12.setDefaultParametersInitalRays_obj_initalRays();
		}
		OpticalSystemElement optSysEle_12 = mOptiSysEle.getDeepCopyOptSysEle();
		lightRayCore_12 = rayAiming_12.rayAiming_obj_initalRays_complete(optSysEle_12, mPoints_12, mWavelength_vec, mStartPointRay, mLight);
		mTime_sec_12 = rayAiming_12.getTime_sec();

	}

}

	std::vector<LightRayStruct> aimedLightRaysCore{};
	aimedLightRaysCore.reserve(mNumberPointsInAS);
	
	//std::vector<LightRayStruct> tempLightRay_core1;
	//std::vector<LightRayStruct> tempLightRay_core2;
	//std::vector<LightRayStruct> tempLightRay_core3;
	//std::vector<LightRayStruct> tempLightRay_core4;
	//std::vector<LightRayStruct> tempLightRay_core5;
	//std::vector<LightRayStruct> tempLightRay_core6;
	//std::vector<LightRayStruct> tempLightRay_core7;
	//std::vector<LightRayStruct> tempLightRay_core8;
	//std::vector<LightRayStruct> tempLightRay_core9;
	//std::vector<LightRayStruct> tempLightRay_core10;
	//std::vector<LightRayStruct> tempLightRay_core11;
	//std::vector<LightRayStruct> tempLightRay_core12;
	
	mAllAimedLightRays.resize(mWavelength_vec.size());
	for (unsigned int i = 0; i < mWavelength_vec.size(); ++i)
	{
		aimedLightRaysCore.clear();
		aimedLightRaysCore.reserve(mNumberPointsInAS);

		aimedLightRaysCore.insert(std::end(aimedLightRaysCore), std::begin(lightRayCore_1[i]), std::end(lightRayCore_1[i]));
		aimedLightRaysCore.insert(std::end(aimedLightRaysCore), std::begin(lightRayCore_2[i]), std::end(lightRayCore_2[i]));
		aimedLightRaysCore.insert(std::end(aimedLightRaysCore), std::begin(lightRayCore_3[i]), std::end(lightRayCore_3[i]));
		aimedLightRaysCore.insert(std::end(aimedLightRaysCore), std::begin(lightRayCore_4[i]), std::end(lightRayCore_4[i]));
		aimedLightRaysCore.insert(std::end(aimedLightRaysCore), std::begin(lightRayCore_5[i]), std::end(lightRayCore_5[i]));
		aimedLightRaysCore.insert(std::end(aimedLightRaysCore), std::begin(lightRayCore_6[i]), std::end(lightRayCore_6[i]));
		aimedLightRaysCore.insert(std::end(aimedLightRaysCore), std::begin(lightRayCore_7[i]), std::end(lightRayCore_7[i]));
		aimedLightRaysCore.insert(std::end(aimedLightRaysCore), std::begin(lightRayCore_8[i]), std::end(lightRayCore_8[i]));
		aimedLightRaysCore.insert(std::end(aimedLightRaysCore), std::begin(lightRayCore_9[i]), std::end(lightRayCore_9[i]));
		aimedLightRaysCore.insert(std::end(aimedLightRaysCore), std::begin(lightRayCore_10[i]), std::end(lightRayCore_10[i]));
		aimedLightRaysCore.insert(std::end(aimedLightRaysCore), std::begin(lightRayCore_11[i]), std::end(lightRayCore_11[i]));
		aimedLightRaysCore.insert(std::end(aimedLightRaysCore), std::begin(lightRayCore_12[i]), std::end(lightRayCore_12[i]));
	
		mAllAimedLightRays[i] = aimedLightRaysCore;
	}

	mTimeTotal_sec.resize(mWavelength_vec.size() + 1);
	if (mDefaulParaRayAiming_initalRays.getRecodTimeInitalRay())
	{
		for (unsigned int i = 0; i < mWavelength_vec.size(); ++i)
		{
			mTimeTotal_sec[i] = mTime_sec_1[i] + mTime_sec_2[i] + mTime_sec_3[i] + mTime_sec_4[i] + mTime_sec_5[i] + mTime_sec_6[i] + mTime_sec_7[i] + mTime_sec_8[i] + mTime_sec_9[i] + mTime_sec_10[i] + mTime_sec_11[i] + mTime_sec_12[i];
			mTimeTotal_sec[i] = mTimeTotal_sec[i] / 12.0;
		}

		

		// save total time
		real totalTime = 0.0;
		for (unsigned int i = 0; i < mWavelength_vec.size(); ++i)
		{
			totalTime = totalTime + mTimeTotal_sec[i];
		}

		mTimeTotal_sec[mWavelength_vec.size()] = totalTime;
	}
	

	return mAllAimedLightRays;
}

std::vector<real> RayAiming_12Cores_initalRays::getTotalTime_sec()
{
	return mTimeTotal_sec;
}

// get tolerance X and Y
real RayAiming_12Cores_initalRays::getToleranceXandY()
{
	return mDefaulParaRayAiming_initalRays.getTolerance_XandY();
}