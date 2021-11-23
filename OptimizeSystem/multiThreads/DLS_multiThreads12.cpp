#include "DLS_mulitThreads12.h"
#include <omp.h>

DLS_multiThreads_12::DLS_multiThreads_12(){}
DLS_multiThreads_12::DLS_multiThreads_12(OpticalSystemElement /*optSysEle*/ optSysEle, std::vector<VectorStructR3> /*fields*/ fields, std::vector<real> /*wavelengths*/ wavelengths, unsigned int /*rings*/ rings, unsigned int /*arms*/ arms):
	mOpticalSystemElement_start(optSysEle),
	mFields_vec(fields),
	mWavelength_vec(wavelengths),
	mRings(rings),
	mArms(arms)
{
	loadDefaulParameters();
	loadFactorBetterAndWorst();
}
DLS_multiThreads_12::DLS_multiThreads_12(OpticalSystemElement /*optSysEle*/ optSysEle, std::vector<VectorStructR3> /*fields*/ fields, std::vector<real> /*wavelengths*/ wavelengths, unsigned int /*rings*/ rings, unsigned int /*arms*/ arms, defaultParaDLS defaultParameterDLS) :
	mOpticalSystemElement_start(optSysEle),
	mFields_vec(fields),
	mWavelength_vec(wavelengths),
	mRings(rings),
	mArms(arms),
	mDefaultParameterDLS(defaultParameterDLS)
{
	loadFactorBetterAndWorst();
}
DLS_multiThreads_12::DLS_multiThreads_12(OpticalSystemElement /*optSysEle*/ optSysEle, std::vector<VectorStructR3> /*fields*/ fields, std::vector<real> /*wavelengths*/ wavelengths, unsigned int /*rings*/ rings, unsigned int /*arms*/ arms, /*target cardinal points*/ targetCardinalPointsStruct targetCarPoints, defaultParaDLS defaultParameterDLS):
	mOpticalSystemElement_start(optSysEle),
	mFields_vec(fields),
	mWavelength_vec(wavelengths),
	mRings(rings),
	mArms(arms),
	mTargetCarPoints(targetCarPoints),
	mDefaultParameterDLS(defaultParameterDLS)
{
	loadFactorBetterAndWorst();
}
DLS_multiThreads_12::DLS_multiThreads_12(OpticalSystemElement /*optSysEle*/ optSysEle, std::vector<real> /*angleX*/ angleX, std::vector<real> /*angleY*/ angleY, std::vector<real> /*wavelengths*/ wavelengths, unsigned int /*rings*/ rings, unsigned int /*arms*/ arms, /*target cardinal points*/ targetCardinalPointsStruct targetCarPoints, defaultParaDLS defaultParameterDLS):
	mOpticalSystemElement_start(optSysEle),
	mAnglesX(angleX),
	mAnglesY(angleY),
	mWavelength_vec(wavelengths),
	mRings(rings),
	mArms(arms),
	mTargetCarPoints(targetCarPoints),
	mDefaultParameterDLS(defaultParameterDLS)
{
	loadFactorBetterAndWorst();
}

DLS_multiThreads_12::~DLS_multiThreads_12(){}

void DLS_multiThreads_12::loadDefaulParameters()
{
	mDefaultParameterDLS.setDampingFactor(5.0);
	mDefaultParameterDLS.setFactorRadiusDeviation(0.000001);
	mDefaultParameterDLS.setFactorPositionDeviation(0.000001);
	mDefaultParameterDLS.setStartRefractivIndex(1.0);
	mDefaultParameterDLS.setMaxWorstCounter(250);
	mDefaultParameterDLS.setImproveMeritStopDiff(0.00000001);
	mDefaultParameterDLS.setMaxInterations(500);
	mDefaultParameterDLS.setFlipOrientationRadius(1000.0);
	mDefaultParameterDLS.setMaxBorderViolations(30);
	mDefaultParameterDLS.setMaxDeltaParameter(25.0);
	mDefaultParameterDLS.setMinDeltaParameter(0.00000001);
	mDefaultParameterDLS.setFactorGettingBetter(0.4);
	mDefaultParameterDLS.setFactorGettingWorst(1.9);
	mDefaultParameterDLS.setToleranceWithoutMin(-0.5);
	mDefaultParameterDLS.setToleranceWithoutMax(0.5);
	mDefaultParameterDLS.set_Min_DamNumBefSwitchFactors(0.00001);
	mDefaultParameterDLS.set_Max_DamNumBefSwitchFactors(9999.0);
	mDefaultParameterDLS.turn_ON_calcRMSusingRayTracing();
}

void DLS_multiThreads_12::loadFactorBetterAndWorst()
{
	mFactorBetter_vec.push_back(0.2);
	mFactorWorst_vec.push_back(1.9);

	mFactorBetter_vec.push_back(0.4);
	mFactorWorst_vec.push_back(2.1);

	mFactorBetter_vec.push_back(0.4);
	mFactorWorst_vec.push_back(1.9);

	mFactorBetter_vec.push_back(0.8);
	mFactorWorst_vec.push_back(2.0);

	mFactorBetter_vec.push_back(0.8);
	mFactorWorst_vec.push_back(2.3);

	mFactorBetter_vec.push_back(0.2);
	mFactorWorst_vec.push_back(2.0);

	mFactorBetter_vec.push_back(0.6);
	mFactorWorst_vec.push_back(2.0);

	mFactorBetter_vec.push_back(0.4);
	mFactorWorst_vec.push_back(2.3);

	mFactorBetter_vec.push_back(0.5);
	mFactorWorst_vec.push_back(1.9);

	mFactorBetter_vec.push_back(0.5);
	mFactorWorst_vec.push_back(2.1);

	mFactorBetter_vec.push_back(0.3);
	mFactorWorst_vec.push_back(2.1);

	mFactorBetter_vec.push_back(0.4);
	mFactorWorst_vec.push_back(1.8);
}

real DLS_multiThreads_12::getBestMeritValue()
{
	return mBestMeritVal;
}

OpticalSystemElement DLS_multiThreads_12::DLS_optimisation_multiThreads_12_obj()
{
	unsigned int numberThreads = 12;
	mAllMeritVal_vec.resize(numberThreads);
	mBestOptSysEle_vec.resize(numberThreads);
	//mOpticalSystemElement_start.getOptSys_LLT_buildSystem();

omp_set_num_threads(numberThreads);
#pragma omp parallel sections
	{
	#pragma omp section // 1
		{
			
			OpticalSystemElement optSysEle_1 = mOpticalSystemElement_start.getDeepCopyOptSysEle();
			DLS DLS_1(/*optSysEle*/ optSysEle_1, /*fields*/ mFields_vec, /*wavelengths*/ mWavelength_vec, /*rings*/ mRings, /*arms*/ mArms, /*target cardinal points*/ mTargetCarPoints, /*default DLS*/ mDefaultParameterDLS);
			DLS_1.turnOffImaProc();
			DLS_1.setFactorGettingBetter(mFactorBetter_vec[0]);
			DLS_1.setFactorGettingWorst(mFactorWorst_vec[0]);
			std::cout << "start DLS core 1" << std::endl;
			DLS_1.optimizeSystem_DLS_multiplicativ_Damping();
			std::cout << "thread 1 completed" << std::endl;
			mAllMeritVal_vec[0] = DLS_1.getBestMeritValue();
			OpticalSystemElement bestOptSysEle_thread_1 = DLS_1.getOptimizedSystem_HLT();
			mBestOptSysEle_vec[0] = bestOptSysEle_thread_1;
		}
	#pragma omp section // 2
		{
			
			OpticalSystemElement optSysEle_2 = mOpticalSystemElement_start.getDeepCopyOptSysEle();
			DLS DLS_2(/*optSysEle*/ optSysEle_2, /*fields*/ mFields_vec, /*wavelengths*/ mWavelength_vec, /*rings*/ mRings, /*arms*/ mArms, /*target cardinal points*/ mTargetCarPoints, /*default DLS*/ mDefaultParameterDLS);
			DLS_2.turnOffImaProc();
			DLS_2.setFactorGettingBetter(mFactorBetter_vec[1]);
			DLS_2.setFactorGettingWorst(mFactorWorst_vec[1]);
			std::cout << "start DLS core 2" << std::endl;
			DLS_2.optimizeSystem_DLS_multiplicativ_Damping();
			std::cout << "thread 2 completed" << std::endl;
			mAllMeritVal_vec[1] = DLS_2.getBestMeritValue();
			OpticalSystemElement bestOptSysEle_thread_2 = DLS_2.getOptimizedSystem_HLT();
			mBestOptSysEle_vec[1] = bestOptSysEle_thread_2;
		}
	#pragma omp section // 3
		{
			
			OpticalSystemElement optSysEle_3 = mOpticalSystemElement_start.getDeepCopyOptSysEle();
			DLS DLS_3(/*optSysEle*/ optSysEle_3, /*fields*/ mFields_vec, /*wavelengths*/ mWavelength_vec, /*rings*/ mRings, /*arms*/ mArms, /*target cardinal points*/ mTargetCarPoints, /*default DLS*/ mDefaultParameterDLS);
			DLS_3.turnOffImaProc();
			DLS_3.setFactorGettingBetter(mFactorBetter_vec[2]);
			DLS_3.setFactorGettingWorst(mFactorWorst_vec[2]);
			std::cout << "start DLS core 3" << std::endl;
			DLS_3.optimizeSystem_DLS_multiplicativ_Damping();
			std::cout << "thread 3 completed" << std::endl;
			mAllMeritVal_vec[2] = DLS_3.getBestMeritValue();
			OpticalSystemElement bestOptSysEle_thread_3 = DLS_3.getOptimizedSystem_HLT();
			mBestOptSysEle_vec[2] = bestOptSysEle_thread_3;
		}
	#pragma omp section // 4
		{
			
			OpticalSystemElement optSysEle_4 = mOpticalSystemElement_start.getDeepCopyOptSysEle();
			DLS DLS_4(/*optSysEle*/ optSysEle_4, /*fields*/ mFields_vec, /*wavelengths*/ mWavelength_vec, /*rings*/ mRings, /*arms*/ mArms, /*target cardinal points*/ mTargetCarPoints, /*default DLS*/ mDefaultParameterDLS);
			DLS_4.turnOffImaProc();
			DLS_4.setFactorGettingBetter(mFactorBetter_vec[3]);
			DLS_4.setFactorGettingWorst(mFactorWorst_vec[3]);
			std::cout << "start DLS core 4" << std::endl;
			DLS_4.optimizeSystem_DLS_multiplicativ_Damping();
			std::cout << "thread 4 completed" << std::endl;
			mAllMeritVal_vec[3] = DLS_4.getBestMeritValue();
			OpticalSystemElement bestOptSysEle_thread_4 = DLS_4.getOptimizedSystem_HLT();
			mBestOptSysEle_vec[3] = bestOptSysEle_thread_4;
		}
	#pragma omp section // 5
		{
			
			OpticalSystemElement optSysEle_5 = mOpticalSystemElement_start.getDeepCopyOptSysEle();
			DLS DLS_5(/*optSysEle*/ optSysEle_5, /*fields*/ mFields_vec, /*wavelengths*/ mWavelength_vec, /*rings*/ mRings, /*arms*/ mArms, /*target cardinal points*/ mTargetCarPoints, /*default DLS*/ mDefaultParameterDLS);
			DLS_5.turnOffImaProc();
			DLS_5.setFactorGettingBetter(mFactorBetter_vec[4]);
			DLS_5.setFactorGettingWorst(mFactorWorst_vec[4]);
			std::cout << "start DLS core 5" << std::endl;
			DLS_5.optimizeSystem_DLS_multiplicativ_Damping();
			std::cout << "thread 5 completed" << std::endl;
			mAllMeritVal_vec[4] = DLS_5.getBestMeritValue();
			OpticalSystemElement bestOptSysEle_thread_5 = DLS_5.getOptimizedSystem_HLT();
			mBestOptSysEle_vec[4] = bestOptSysEle_thread_5;
		}
	#pragma omp section // 6
		{
			
			OpticalSystemElement optSysEle_6 = mOpticalSystemElement_start.getDeepCopyOptSysEle();
			DLS DLS_6(/*optSysEle*/ optSysEle_6, /*fields*/ mFields_vec, /*wavelengths*/ mWavelength_vec, /*rings*/ mRings, /*arms*/ mArms, /*target cardinal points*/ mTargetCarPoints, /*default DLS*/ mDefaultParameterDLS);
			DLS_6.turnOffImaProc();
			DLS_6.setFactorGettingBetter(mFactorBetter_vec[5]);
			DLS_6.setFactorGettingWorst(mFactorWorst_vec[5]);
			std::cout << "start DLS core 6" << std::endl;
			DLS_6.optimizeSystem_DLS_multiplicativ_Damping();
			std::cout << "thread 6 completed" << std::endl;
			mAllMeritVal_vec[5] = DLS_6.getBestMeritValue();
			OpticalSystemElement bestOptSysEle_thread_6 = DLS_6.getOptimizedSystem_HLT();
			mBestOptSysEle_vec[5] = bestOptSysEle_thread_6;
		}
	#pragma omp section // 7
		{
			
			OpticalSystemElement optSysEle_7 = mOpticalSystemElement_start.getDeepCopyOptSysEle();
			DLS DLS_7(/*optSysEle*/ optSysEle_7, /*fields*/ mFields_vec, /*wavelengths*/ mWavelength_vec, /*rings*/ mRings, /*arms*/ mArms, /*target cardinal points*/ mTargetCarPoints, /*default DLS*/ mDefaultParameterDLS);
			DLS_7.turnOffImaProc();
			DLS_7.setFactorGettingBetter(mFactorBetter_vec[6]);
			DLS_7.setFactorGettingWorst(mFactorWorst_vec[6]);
			std::cout << "start DLS core 7" << std::endl;
			DLS_7.optimizeSystem_DLS_multiplicativ_Damping();
			std::cout << "thread 7 completed" << std::endl;
			mAllMeritVal_vec[6] = DLS_7.getBestMeritValue();
			OpticalSystemElement bestOptSysEle_thread_7 = DLS_7.getOptimizedSystem_HLT();
			mBestOptSysEle_vec[6] = bestOptSysEle_thread_7;
		}
	#pragma omp section // 8
		{
			
			OpticalSystemElement optSysEle_8 = mOpticalSystemElement_start.getDeepCopyOptSysEle();
			DLS DLS_8(/*optSysEle*/ optSysEle_8, /*fields*/ mFields_vec, /*wavelengths*/ mWavelength_vec, /*rings*/ mRings, /*arms*/ mArms, /*target cardinal points*/ mTargetCarPoints, /*default DLS*/ mDefaultParameterDLS);
			DLS_8.turnOffImaProc();
			DLS_8.setFactorGettingBetter(mFactorBetter_vec[7]);
			DLS_8.setFactorGettingWorst(mFactorWorst_vec[7]);
			std::cout << "start DLS core 8" << std::endl;
			DLS_8.optimizeSystem_DLS_multiplicativ_Damping();
			std::cout << "thread 8 completed" << std::endl;
			mAllMeritVal_vec[7] = DLS_8.getBestMeritValue();
			OpticalSystemElement bestOptSysEle_thread_8 = DLS_8.getOptimizedSystem_HLT();
			mBestOptSysEle_vec[7] = bestOptSysEle_thread_8;
		}
	#pragma omp section // 9
		{
			
			OpticalSystemElement optSysEle_9 = mOpticalSystemElement_start.getDeepCopyOptSysEle();
			DLS DLS_9(/*optSysEle*/ optSysEle_9, /*fields*/ mFields_vec, /*wavelengths*/ mWavelength_vec, /*rings*/ mRings, /*arms*/ mArms, /*target cardinal points*/ mTargetCarPoints, /*default DLS*/ mDefaultParameterDLS);
			DLS_9.turnOffImaProc();
			DLS_9.setFactorGettingBetter(mFactorBetter_vec[8]);
			DLS_9.setFactorGettingWorst(mFactorWorst_vec[8]);
			std::cout << "start DLS core 9" << std::endl;
			DLS_9.optimizeSystem_DLS_multiplicativ_Damping();
			std::cout << "thread 9 completed" << std::endl;
			mAllMeritVal_vec[8] = DLS_9.getBestMeritValue();
			OpticalSystemElement bestOptSysEle_thread_9 = DLS_9.getOptimizedSystem_HLT();
			mBestOptSysEle_vec[8] = bestOptSysEle_thread_9;
		}
	#pragma omp section // 10
		{
			
			OpticalSystemElement optSysEle_10 = mOpticalSystemElement_start.getDeepCopyOptSysEle();
			DLS DLS_10(/*optSysEle*/ optSysEle_10, /*fields*/ mFields_vec, /*wavelengths*/ mWavelength_vec, /*rings*/ mRings, /*arms*/ mArms, /*target cardinal points*/ mTargetCarPoints, /*default DLS*/ mDefaultParameterDLS);
			DLS_10.turnOffImaProc();
			DLS_10.setFactorGettingBetter(mFactorBetter_vec[9]);
			DLS_10.setFactorGettingWorst(mFactorWorst_vec[9]);
			std::cout << "start DLS core 10" << std::endl;
			DLS_10.optimizeSystem_DLS_multiplicativ_Damping();
			std::cout << "thread 10 completed" << std::endl;
			mAllMeritVal_vec[9] = DLS_10.getBestMeritValue();
			OpticalSystemElement bestOptSysEle_thread_10 = DLS_10.getOptimizedSystem_HLT();
			mBestOptSysEle_vec[9] = bestOptSysEle_thread_10;
		}
	#pragma omp section // 11
		{
			
			OpticalSystemElement optSysEle_11 = mOpticalSystemElement_start.getDeepCopyOptSysEle();
			DLS DLS_11(/*optSysEle*/ optSysEle_11, /*fields*/ mFields_vec, /*wavelengths*/ mWavelength_vec, /*rings*/ mRings, /*arms*/ mArms, /*target cardinal points*/ mTargetCarPoints, /*default DLS*/ mDefaultParameterDLS);
			DLS_11.turnOffImaProc();
			DLS_11.setFactorGettingBetter(mFactorBetter_vec[10]);
			DLS_11.setFactorGettingWorst(mFactorWorst_vec[10]);
			std::cout << "start DLS core 11" << std::endl;
			DLS_11.optimizeSystem_DLS_multiplicativ_Damping();
			std::cout << "thread 11 completed" << std::endl;
			mAllMeritVal_vec[10] = DLS_11.getBestMeritValue();
			OpticalSystemElement bestOptSysEle_thread_11 = DLS_11.getOptimizedSystem_HLT();
			mBestOptSysEle_vec[10] = bestOptSysEle_thread_11;
		}
	#pragma omp section // 12
		{
			
			OpticalSystemElement optSysEle_12 = mOpticalSystemElement_start.getDeepCopyOptSysEle();
			DLS DLS_12(/*optSysEle*/ optSysEle_12, /*fields*/ mFields_vec, /*wavelengths*/ mWavelength_vec, /*rings*/ mRings, /*arms*/ mArms, /*target cardinal points*/ mTargetCarPoints, /*default DLS*/ mDefaultParameterDLS);
			DLS_12.turnOffImaProc();
			DLS_12.setFactorGettingBetter(mFactorBetter_vec[11]);
			DLS_12.setFactorGettingWorst(mFactorWorst_vec[11]);
			std::cout << "start DLS core 12" << std::endl;
			DLS_12.optimizeSystem_DLS_multiplicativ_Damping();
			std::cout << "thread 12 completed" << std::endl;
			mAllMeritVal_vec[11] = DLS_12.getBestMeritValue();
			OpticalSystemElement bestOptSysEle_thread_12 = DLS_12.getOptimizedSystem_HLT();
			mBestOptSysEle_vec[11] = bestOptSysEle_thread_12;
		}
	}

	mBestMeritVal = mAllMeritVal_vec[0];
	bestOpticalSystem = mBestOptSysEle_vec[0];

	for (unsigned int i = 1; i < numberThreads; ++i)
	{
		if (mBestMeritVal > mAllMeritVal_vec[i])
		{
			mBestMeritVal = mAllMeritVal_vec[i];
			bestOpticalSystem = mBestOptSysEle_vec[i].getDeepCopyOptSysEle();
		}
	}

	return bestOpticalSystem;
}

OpticalSystemElement DLS_multiThreads_12::DLS_optimisation_multiThreads_12_inf()
{
	unsigned int numberThreads = 12;
	mAllMeritVal_vec.resize(numberThreads);
	mBestOptSysEle_vec.resize(numberThreads);
	//mOpticalSystemElement_start.getOptSys_LLT_buildSystem();

#pragma omp parallel sections
	{
	#pragma omp section // 1
		{

			OpticalSystemElement optSysEle_1 = mOpticalSystemElement_start.getDeepCopyOptSysEle();
			DLS DLS_1(/*optSysEle*/ optSysEle_1, /*angleX*/ mAnglesX, /*angleY*/ mAnglesY, /*wavelengths*/ mWavelength_vec, /*rings*/ mRings, /*arms*/ mArms, /*target cardinal points*/ mTargetCarPoints, /*default DLS*/ mDefaultParameterDLS);
			DLS_1.setFactorGettingBetter(mFactorBetter_vec[0]);
			DLS_1.setFactorGettingWorst(mFactorWorst_vec[0]);
			DLS_1.turnOffImaProc();
			std::cout << "start DLS core 1" << std::endl;
			DLS_1.optimizeSystem_DLS_multiplicativ_Damping();
			std::cout << "thread 1 completed" << std::endl;
			mAllMeritVal_vec[0] = DLS_1.getBestMeritValue();
			OpticalSystemElement bestOptSysEle_thread_1 = DLS_1.getOptimizedSystem_HLT();
			mBestOptSysEle_vec[0] = bestOptSysEle_thread_1;
		}
	#pragma omp section // 2
		{

			OpticalSystemElement optSysEle_2 = mOpticalSystemElement_start.getDeepCopyOptSysEle();
			DLS DLS_2(/*optSysEle*/ optSysEle_2, /*angleX*/ mAnglesX, /*angleY*/ mAnglesY, /*wavelengths*/ mWavelength_vec, /*rings*/ mRings, /*arms*/ mArms, /*target cardinal points*/ mTargetCarPoints, /*default DLS*/ mDefaultParameterDLS);
			DLS_2.setFactorGettingBetter(mFactorBetter_vec[1]);
			DLS_2.setFactorGettingWorst(mFactorWorst_vec[1]);
			DLS_2.turnOffImaProc();
			std::cout << "start DLS core 2" << std::endl;
			DLS_2.optimizeSystem_DLS_multiplicativ_Damping();
			std::cout << "thread 2 completed" << std::endl;
			mAllMeritVal_vec[1] = DLS_2.getBestMeritValue();
			OpticalSystemElement bestOptSysEle_thread_2 = DLS_2.getOptimizedSystem_HLT();
			mBestOptSysEle_vec[1] = bestOptSysEle_thread_2;
		}
	#pragma omp section // 3
		{

			OpticalSystemElement optSysEle_3 = mOpticalSystemElement_start.getDeepCopyOptSysEle();
			DLS DLS_3(/*optSysEle*/ optSysEle_3, /*angleX*/ mAnglesX, /*angleY*/ mAnglesY, /*wavelengths*/ mWavelength_vec, /*rings*/ mRings, /*arms*/ mArms, /*target cardinal points*/ mTargetCarPoints, /*default DLS*/ mDefaultParameterDLS);
			DLS_3.setFactorGettingBetter(mFactorBetter_vec[2]);
			DLS_3.setFactorGettingWorst(mFactorWorst_vec[2]);
			DLS_3.turnOffImaProc();
			std::cout << "start DLS core 3" << std::endl;
			DLS_3.optimizeSystem_DLS_multiplicativ_Damping();
			std::cout << "thread 3 completed" << std::endl;
			mAllMeritVal_vec[2] = DLS_3.getBestMeritValue();
			OpticalSystemElement bestOptSysEle_thread_3 = DLS_3.getOptimizedSystem_HLT();
			mBestOptSysEle_vec[2] = bestOptSysEle_thread_3;
		}
	#pragma omp section // 4
		{

			OpticalSystemElement optSysEle_4 = mOpticalSystemElement_start.getDeepCopyOptSysEle();
			DLS DLS_4(/*optSysEle*/ optSysEle_4, /*angleX*/ mAnglesX, /*angleY*/ mAnglesY, /*wavelengths*/ mWavelength_vec, /*rings*/ mRings, /*arms*/ mArms, /*target cardinal points*/ mTargetCarPoints, /*default DLS*/ mDefaultParameterDLS);
			DLS_4.setFactorGettingBetter(mFactorBetter_vec[3]);
			DLS_4.setFactorGettingWorst(mFactorWorst_vec[3]);
			DLS_4.turnOffImaProc();
			std::cout << "start DLS core 4" << std::endl;
			DLS_4.optimizeSystem_DLS_multiplicativ_Damping();
			std::cout << "thread 4 completed" << std::endl;
			mAllMeritVal_vec[3] = DLS_4.getBestMeritValue();
			OpticalSystemElement bestOptSysEle_thread_4 = DLS_4.getOptimizedSystem_HLT();
			mBestOptSysEle_vec[3] = bestOptSysEle_thread_4;
		}
	#pragma omp section // 5
		{

			OpticalSystemElement optSysEle_5 = mOpticalSystemElement_start.getDeepCopyOptSysEle();
			DLS DLS_5(/*optSysEle*/ optSysEle_5, /*angleX*/ mAnglesX, /*angleY*/ mAnglesY, /*wavelengths*/ mWavelength_vec, /*rings*/ mRings, /*arms*/ mArms, /*target cardinal points*/ mTargetCarPoints, /*default DLS*/ mDefaultParameterDLS);
			DLS_5.setFactorGettingBetter(mFactorBetter_vec[4]);
			DLS_5.setFactorGettingWorst(mFactorWorst_vec[4]);
			DLS_5.turnOffImaProc();
			std::cout << "start DLS core 5" << std::endl;
			DLS_5.optimizeSystem_DLS_multiplicativ_Damping();
			std::cout << "thread 5 completed" << std::endl;
			mAllMeritVal_vec[4] = DLS_5.getBestMeritValue();
			OpticalSystemElement bestOptSysEle_thread_5 = DLS_5.getOptimizedSystem_HLT();
			mBestOptSysEle_vec[4] = bestOptSysEle_thread_5;
		}
	#pragma omp section // 6
		{

			OpticalSystemElement optSysEle_6 = mOpticalSystemElement_start.getDeepCopyOptSysEle();
			DLS DLS_6(/*optSysEle*/ optSysEle_6, /*angleX*/ mAnglesX, /*angleY*/ mAnglesY, /*wavelengths*/ mWavelength_vec, /*rings*/ mRings, /*arms*/ mArms, /*target cardinal points*/ mTargetCarPoints, /*default DLS*/ mDefaultParameterDLS);
			DLS_6.setFactorGettingBetter(mFactorBetter_vec[5]);
			DLS_6.setFactorGettingWorst(mFactorWorst_vec[5]);
			DLS_6.turnOffImaProc();
			std::cout << "start DLS core 6" << std::endl;
			DLS_6.optimizeSystem_DLS_multiplicativ_Damping();
			std::cout << "thread 6 completed" << std::endl;
			mAllMeritVal_vec[5] = DLS_6.getBestMeritValue();
			OpticalSystemElement bestOptSysEle_thread_6 = DLS_6.getOptimizedSystem_HLT();
			mBestOptSysEle_vec[5] = bestOptSysEle_thread_6;
		}
	#pragma omp section // 7
		{

			OpticalSystemElement optSysEle_7 = mOpticalSystemElement_start.getDeepCopyOptSysEle();
			DLS DLS_7(/*optSysEle*/ optSysEle_7, /*angleX*/ mAnglesX, /*angleY*/ mAnglesY, /*wavelengths*/ mWavelength_vec, /*rings*/ mRings, /*arms*/ mArms, /*target cardinal points*/ mTargetCarPoints, /*default DLS*/ mDefaultParameterDLS);
			DLS_7.setFactorGettingBetter(mFactorBetter_vec[6]);
			DLS_7.setFactorGettingWorst(mFactorWorst_vec[6]);
			DLS_7.turnOffImaProc();
			std::cout << "start DLS core 7" << std::endl;
			DLS_7.optimizeSystem_DLS_multiplicativ_Damping();
			std::cout << "thread 7 completed" << std::endl;
			mAllMeritVal_vec[6] = DLS_7.getBestMeritValue();
			OpticalSystemElement bestOptSysEle_thread_7 = DLS_7.getOptimizedSystem_HLT();
			mBestOptSysEle_vec[6] = bestOptSysEle_thread_7;
		}
	#pragma omp section // 8
		{

			OpticalSystemElement optSysEle_8 = mOpticalSystemElement_start.getDeepCopyOptSysEle();
			DLS DLS_8(/*optSysEle*/ optSysEle_8, /*angleX*/ mAnglesX, /*angleY*/ mAnglesY, /*wavelengths*/ mWavelength_vec, /*rings*/ mRings, /*arms*/ mArms, /*target cardinal points*/ mTargetCarPoints, /*default DLS*/ mDefaultParameterDLS);
			DLS_8.setFactorGettingBetter(mFactorBetter_vec[7]);
			DLS_8.setFactorGettingWorst(mFactorWorst_vec[7]);
			DLS_8.turnOffImaProc();
			std::cout << "start DLS core 8" << std::endl;
			DLS_8.optimizeSystem_DLS_multiplicativ_Damping();
			std::cout << "thread 8 completed" << std::endl;
			mAllMeritVal_vec[7] = DLS_8.getBestMeritValue();
			OpticalSystemElement bestOptSysEle_thread_8 = DLS_8.getOptimizedSystem_HLT();
			mBestOptSysEle_vec[7] = bestOptSysEle_thread_8;
		}
	#pragma omp section // 9
		{

			OpticalSystemElement optSysEle_9 = mOpticalSystemElement_start.getDeepCopyOptSysEle();
			DLS DLS_9(/*optSysEle*/ optSysEle_9, /*angleX*/ mAnglesX, /*angleY*/ mAnglesY, /*wavelengths*/ mWavelength_vec, /*rings*/ mRings, /*arms*/ mArms, /*target cardinal points*/ mTargetCarPoints, /*default DLS*/ mDefaultParameterDLS);
			DLS_9.setFactorGettingBetter(mFactorBetter_vec[8]);
			DLS_9.setFactorGettingWorst(mFactorWorst_vec[8]);
			DLS_9.turnOffImaProc();
			std::cout << "start DLS core 9" << std::endl;
			DLS_9.optimizeSystem_DLS_multiplicativ_Damping();
			std::cout << "thread 9 completed" << std::endl;
			mAllMeritVal_vec[8] = DLS_9.getBestMeritValue();
			OpticalSystemElement bestOptSysEle_thread_9 = DLS_9.getOptimizedSystem_HLT();
			mBestOptSysEle_vec[8] = bestOptSysEle_thread_9;
		}
	#pragma omp section // 10
		{

			OpticalSystemElement optSysEle_10 = mOpticalSystemElement_start.getDeepCopyOptSysEle();
			DLS DLS_10(/*optSysEle*/ optSysEle_10, /*angleX*/ mAnglesX, /*angleY*/ mAnglesY, /*wavelengths*/ mWavelength_vec, /*rings*/ mRings, /*arms*/ mArms, /*target cardinal points*/ mTargetCarPoints, /*default DLS*/ mDefaultParameterDLS);
			DLS_10.setFactorGettingBetter(mFactorBetter_vec[9]);
			DLS_10.setFactorGettingWorst(mFactorWorst_vec[9]);
			DLS_10.turnOffImaProc();
			std::cout << "start DLS core 10" << std::endl;
			DLS_10.optimizeSystem_DLS_multiplicativ_Damping();
			std::cout << "thread 10 completed" << std::endl;
			mAllMeritVal_vec[9] = DLS_10.getBestMeritValue();
			OpticalSystemElement bestOptSysEle_thread_10 = DLS_10.getOptimizedSystem_HLT();
			mBestOptSysEle_vec[9] = bestOptSysEle_thread_10;
		}
	#pragma omp section // 11
		{

			OpticalSystemElement optSysEle_11 = mOpticalSystemElement_start.getDeepCopyOptSysEle();
			DLS DLS_11(/*optSysEle*/ optSysEle_11, /*angleX*/ mAnglesX, /*angleY*/ mAnglesY, /*wavelengths*/ mWavelength_vec, /*rings*/ mRings, /*arms*/ mArms, /*target cardinal points*/ mTargetCarPoints, /*default DLS*/ mDefaultParameterDLS);
			DLS_11.setFactorGettingBetter(mFactorBetter_vec[10]);
			DLS_11.setFactorGettingWorst(mFactorWorst_vec[10]);
			DLS_11.turnOffImaProc();
			std::cout << "start DLS core 11" << std::endl;
			DLS_11.optimizeSystem_DLS_multiplicativ_Damping();
			std::cout << "thread 11 completed" << std::endl;
			mAllMeritVal_vec[10] = DLS_11.getBestMeritValue();
			OpticalSystemElement bestOptSysEle_thread_11 = DLS_11.getOptimizedSystem_HLT();
			mBestOptSysEle_vec[10] = bestOptSysEle_thread_11;
		}
	#pragma omp section // 12
		{

			OpticalSystemElement optSysEle_12 = mOpticalSystemElement_start.getDeepCopyOptSysEle();
			DLS DLS_12(/*optSysEle*/ optSysEle_12, /*angleX*/ mAnglesX, /*angleY*/ mAnglesY, /*wavelengths*/ mWavelength_vec, /*rings*/ mRings, /*arms*/ mArms, /*target cardinal points*/ mTargetCarPoints, /*default DLS*/ mDefaultParameterDLS);
			DLS_12.setFactorGettingBetter(mFactorBetter_vec[11]);
			DLS_12.setFactorGettingWorst(mFactorWorst_vec[11]);
			DLS_12.turnOffImaProc();
			std::cout << "start DLS core 12" << std::endl;
			DLS_12.optimizeSystem_DLS_multiplicativ_Damping();
			std::cout << "thread 12 completed" << std::endl;
			mAllMeritVal_vec[11] = DLS_12.getBestMeritValue();
			OpticalSystemElement bestOptSysEle_thread_12 = DLS_12.getOptimizedSystem_HLT();
			mBestOptSysEle_vec[11] = bestOptSysEle_thread_12;
		}
	}

	mBestMeritVal = mAllMeritVal_vec[0];
	bestOpticalSystem = mBestOptSysEle_vec[0];

	for (unsigned int i = 1; i < numberThreads; ++i)
	{
		if (mBestMeritVal > mAllMeritVal_vec[i])
		{
			mBestMeritVal = mAllMeritVal_vec[i];
			bestOpticalSystem = mBestOptSysEle_vec[i];
		}
	}

	return bestOpticalSystem;
}