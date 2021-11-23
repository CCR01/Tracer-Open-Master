#include "OptimizeSystemSuperFct_GeneticAndDLS.h"
#include "..\oftenUseNamespace\oftenUseNamespace.h"
#include <omp.h>

#include "..\OptimizeSystem\multiThreads\DLS_mulitThreads12.h"

OptimizeSystemSuperFct_GeneticAndDLS::OptimizeSystemSuperFct_GeneticAndDLS(){}

OptimizeSystemSuperFct_GeneticAndDLS::~OptimizeSystemSuperFct_GeneticAndDLS(){}

OptimizeSystemSuperFct_GeneticAndDLS::OptimizeSystemSuperFct_GeneticAndDLS(OpticalSystemElement /*optSysEle*/ optSysEle, std::vector<VectorStructR3> /*fields*/ fields, std::vector<real> /*wavelengths*/ wavelengths, unsigned int /*rings*/ rings, unsigned int /*arms*/ arms, unsigned int /*populatuion*/ population, defaultParaGenetic defaultGenetic, defaultParaDLS defaultDLS):
	mOptSysEle(optSysEle),
	mFields_vec(fields),
	mWavelength_vec(wavelengths),
	mRings(rings),
	mArms(arms),
	mPopulation(population),
	mDefaultParameterGenetic(defaultGenetic),
	mDefaultPrameterDLS(defaultDLS)
{
	mObjPoint_inf_obj = objectPoint_inf_obj::obj;
	mTargetCarPoints.setIsOneTargetCardinalPoint(false);
	mFactorBetter_1 = 0.4;
	mFactorWorst_1 = 1.9;
	mFactorBetter_2 = 0.2;
	mFactorWorst_2 = 2.1;
	loadBestFactorBetterFactorWorstCombinations();
}

OptimizeSystemSuperFct_GeneticAndDLS::OptimizeSystemSuperFct_GeneticAndDLS(OpticalSystemElement /*optSysEle*/ optSysEle, std::vector<VectorStructR3> /*fields*/ fields, std::vector<real> /*wavelengths*/ wavelengths, unsigned int /*rings*/ rings, unsigned int /*arms*/ arms, unsigned int /*populatuion*/ population, targetCardinalPointsStruct targetCarPoints, defaultParaGenetic defaultGenetic, defaultParaDLS defaultDLS) :
	mOptSysEle(optSysEle),
	mFields_vec(fields),
	mWavelength_vec(wavelengths),
	mRings(rings),
	mArms(arms),
	mPopulation(population),
	mDefaultParameterGenetic(defaultGenetic),
	mDefaultPrameterDLS(defaultDLS),
	mTargetCarPoints(targetCarPoints)
{
	mObjPoint_inf_obj = objectPoint_inf_obj::obj;
	mFactorBetter_1 = 0.4;
	mFactorWorst_1 = 2.1;
	mFactorBetter_2 = 0.2;
	mFactorWorst_2 = 1.9;
	loadBestFactorBetterFactorWorstCombinations();
}

OptimizeSystemSuperFct_GeneticAndDLS::OptimizeSystemSuperFct_GeneticAndDLS(OpticalSystemElement /*optSysEle*/ optSysEle, std::vector<real> /*angleX*/ angleX, std::vector<real> /*angleY*/ angle, std::vector<real> /*wavelengths*/ wavelengths, unsigned int /*rings*/ rings, unsigned int /*arms*/ arms, unsigned int /*populatuion*/ population, targetCardinalPointsStruct targetCarPoints, defaultParaGenetic defaultGenetic, defaultParaDLS defaultDLS) :
	mOptSysEle(optSysEle),
	mAngleX(angleX),
	mAngleY(angle),
	mWavelength_vec(wavelengths),
	mRings(rings),
	mArms(arms),
	mPopulation(population),
	mDefaultParameterGenetic(defaultGenetic),
	mDefaultPrameterDLS(defaultDLS),
	mTargetCarPoints(targetCarPoints)
{
	mObjPoint_inf_obj = objectPoint_inf_obj::inf;
	mFactorBetter_1 = 0.4;
	mFactorWorst_1 = 2.1;
	mFactorBetter_2 = 0.2;
	mFactorWorst_2 = 1.9;
	loadBestFactorBetterFactorWorstCombinations();
}

// genetic and DLS
OpticalSystemElement OptimizeSystemSuperFct_GeneticAndDLS::optimizeSuperFct_GeneticAndDLS()
{
	unsigned int objFieldSize = mFields_vec.size();
	unsigned int infAngle_X_Size = mAngleX.size();
	unsigned int infAngle_Y_Size = mAngleY.size();

	if (objFieldSize > 0)
	{
		return optimizeSuperFct_GeneticAndDLS_obj();
	}

	else
	{
		if (infAngle_X_Size == infAngle_Y_Size)
		{
			return optimizeSuperFct_GeneticAndDLS_inf();
		}

		else
		{
			std::cout << "ATTENTION: size angle X is not size angle Y" << std::endl;
			OpticalSystemElement optSys{};
			return optSys;
		}
	}

}

OpticalSystemElement OptimizeSystemSuperFct_GeneticAndDLS::optimizeSuperFct_GeneticAndDLS_obj()
{
	OpticalSystemElement optSysEleGenetic = mOptSysEle.getDeepCopyOptSysEle();

	// GENETIC
	Genetic geneticClass(/*optSysEle*/ optSysEleGenetic, /*fields*/ mFields_vec,/*wavelengths*/ mWavelength_vec, /*rings*/ mRings, /*arms*/ mArms, /*populatuion*/ mPopulation, /*target cardinal points*/ mTargetCarPoints, /*default parameter*/ mDefaultParameterGenetic);
	geneticClass.setChooseValueMode(cleverSamplingMode);
	geneticClass.doTheGeneticProcess();
	OpticalSystemElement optSysEleOptimizedGenetic = geneticClass.getOptimizedOpticalSystemElement().getDeepCopyOptSysEle();
	
	// DLS
	DLS DLS_Class(/*optSysEle*/ optSysEleOptimizedGenetic, /*fields*/ mFields_vec, /*wavelengths*/ mWavelength_vec, /*rings*/ mRings, /*arms*/ mArms, /*target cardinal points*/ mTargetCarPoints, /*default DLS*/ mDefaultPrameterDLS);
	DLS_Class.turnOffImaProc();
	DLS_Class.optimizeSystem_DLS_multiplicativ_Damping();
	OpticalSystemElement optSysEleOptimizedDLS = DLS_Class.getOptimizedSystem_HLT();
	mBestMeritVal = DLS_Class.getBestMeritValue();

	return optSysEleOptimizedDLS;


}
OpticalSystemElement OptimizeSystemSuperFct_GeneticAndDLS::optimizeSuperFct_GeneticAndDLS_inf()
{
	
	OpticalSystemElement optSysEleGenetic = mOptSysEle.getDeepCopyOptSysEle();

	// GENETIC
	Genetic geneticClass(/*optSysEle*/ optSysEleGenetic, /*angleX*/ mAngleX, /*angleY*/ mAngleY, /*wavelengths*/ mWavelength_vec, /*rings*/ mRings, /*arms*/ mArms, /*populatuion*/ mPopulation, /*target cardinal points*/ mTargetCarPoints, /*default parameter*/ mDefaultParameterGenetic);
	geneticClass.setChooseValueMode(cleverSamplingMode);
	geneticClass.doTheGeneticProcess();
	OpticalSystemElement optSysEleOptimizedGenetic = geneticClass.getOptimizedOpticalSystemElement().getDeepCopyOptSysEle();


	//DLS
	DLS DLS_Class(/*optSysEle*/ optSysEleOptimizedGenetic, /*angleX*/ mAngleX, /*angleY*/ mAngleY, /*wavelengths*/ mWavelength_vec, /*rings*/ mRings, /*arms*/ mArms, /*target cardinal points*/ mTargetCarPoints, /*default DLS*/ mDefaultPrameterDLS);
	DLS_Class.turnOffImaProc();
	DLS_Class.optimizeSystem_DLS_multiplicativ_Damping();
	OpticalSystemElement optSysEleOptimizedDLS = DLS_Class.getOptimizedSystem_HLT();

	return optSysEleOptimizedDLS;

}

OpticalSystemElement OptimizeSystemSuperFct_GeneticAndDLS::optimizeSuperFct_GeneticAndDLS_12Cores()
{
	unsigned int objFieldSize = mFields_vec.size();
	unsigned int infAngle_X_Size = mAngleX.size();
	unsigned int infAngle_Y_Size = mAngleY.size();

	if (objFieldSize > 0)
	{
		return optimizeSuperFct_GeneticAndDLS_12Cores_obj();
	}

	else
	{
		if (infAngle_X_Size == infAngle_Y_Size)
		{
			return optimizeSuperFct_GeneticAndDLS_12Cores_inf();
		}

		else
		{
			std::cout << "ATTENTION: size angle X is not size angle Y" << std::endl;
			OpticalSystemElement optSys{};
			return optSys;
		}
	}
}

// parallel the optimisation including genetic and DLS on 6 cores
OpticalSystemElement OptimizeSystemSuperFct_GeneticAndDLS::optimizeSuperFct_GeneticAndDLS_12Cores_obj()
{
	int nProcessors = omp_get_max_threads();
	// check if there are 6 threads
	if (nProcessors < 12)
	{
		std::cout << "there are no 12 threads to do the optimization" << std::endl;
	}


	// build the optical systems for DLS
	OpticalSystemElement optSysEleThread1_1_forDLS;
	OpticalSystemElement optSysEleThread1_2_forDLS;

	OpticalSystemElement optSysEleThread2_1_forDLS;
	OpticalSystemElement optSysEleThread2_2_forDLS;

	OpticalSystemElement optSysEleThread3_1_forDLS;
	OpticalSystemElement optSysEleThread3_2_forDLS;

	OpticalSystemElement optSysEleThread4_1_forDLS;
	OpticalSystemElement optSysEleThread4_2_forDLS;

	OpticalSystemElement optSysEleThread5_1_forDLS;
	OpticalSystemElement optSysEleThread5_2_forDLS;

	OpticalSystemElement optSysEleThread6_1_forDLS;
	OpticalSystemElement optSysEleThread6_2_forDLS;

	OpticalSystemElement optSysEleThread7_1_forDLS;
	OpticalSystemElement optSysEleThread7_2_forDLS;

	OpticalSystemElement optSysEleThread8_1_forDLS;
	OpticalSystemElement optSysEleThread8_2_forDLS;

	OpticalSystemElement optSysEleThread9_1_forDLS;
	OpticalSystemElement optSysEleThread9_2_forDLS;

	OpticalSystemElement optSysEleThread10_1_forDLS;
	OpticalSystemElement optSysEleThread10_2_forDLS;

	OpticalSystemElement optSysEleThread11_1_forDLS;
	OpticalSystemElement optSysEleThread11_2_forDLS;

	OpticalSystemElement optSysEleThread12_1_forDLS;
	OpticalSystemElement optSysEleThread12_2_forDLS;

omp_set_num_threads(12);
#pragma omp parallel sections
		{
		#pragma omp section // 1
			{
				// thread 1 -> random mode
				OpticalSystemElement optSysEleThread1 = mOptSysEle.getDeepCopyOptSysEle();
				Genetic geneticThread_1 (/*optSysEle*/ optSysEleThread1, /*fields*/ mFields_vec,/*wavelengths*/ mWavelength_vec, /*rings*/ mRings, /*arms*/ mArms, /*populatuion*/ mPopulation, /*target cardinal points*/ mTargetCarPoints, /*default parameter*/ mDefaultParameterGenetic);
				geneticThread_1.setChooseValueMode(randomMode);
				std::cout << "start genetic core 1" << std::endl;
				geneticThread_1.doTheGeneticProcess(); 

				OpticalSystemElement saveOptSys_1 = geneticThread_1.getOptimizedOpticalSystemElement();
				optSysEleThread1_1_forDLS = saveOptSys_1.getDeepCopyOptSysEle();

				OpticalSystemElement saveOptSys_2 = geneticThread_1.getOptimizedOpticalSystemElement();
				optSysEleThread1_2_forDLS = saveOptSys_2.getDeepCopyOptSysEle();
			}
		#pragma omp section // 2
			{
				// thread 2 -> clever sampling

				OpticalSystemElement optSysEleThread2 = mOptSysEle.getDeepCopyOptSysEle();
				Genetic geneticThread_2(/*optSysEle*/ optSysEleThread2, /*fields*/ mFields_vec,/*wavelengths*/ mWavelength_vec, /*rings*/ mRings, /*arms*/ mArms, /*populatuion*/ mPopulation, /*target cardinal points*/ mTargetCarPoints, /*default parameter*/ mDefaultParameterGenetic);
				geneticThread_2.setChooseValueMode(cleverSamplingMode);
				std::cout << "start genetic core 2" << std::endl;
				geneticThread_2.doTheGeneticProcess(); 

				optSysEleThread2_1_forDLS = geneticThread_2.getOptimizedOpticalSystemElement().getDeepCopyOptSysEle();
				optSysEleThread2_2_forDLS = geneticThread_2.getOptimizedOpticalSystemElement().getDeepCopyOptSysEle();
			}
		#pragma omp section // 3
			{
				// thread 3 -> mean 0, std 50
				OpticalSystemElement optSysEleThread3 = mOptSysEle.getDeepCopyOptSysEle();
				Genetic geneticThread_3(/*optSysEle*/ optSysEleThread3, /*fields*/ mFields_vec,/*wavelengths*/ mWavelength_vec, /*rings*/ mRings, /*arms*/ mArms, /*populatuion*/ mPopulation, /*target cardinal points*/ mTargetCarPoints, /*default parameter*/ mDefaultParameterGenetic);
				geneticThread_3.setChooseValueMode(normalDistributionMode);
				geneticThread_3.setMeanToCalcND(0.0);
				geneticThread_3.setStddevToCalcND(50.0);
				std::cout << "start genetic core 3" << std::endl;
				geneticThread_3.doTheGeneticProcess(); 

				optSysEleThread3_1_forDLS = geneticThread_3.getOptimizedOpticalSystemElement().getDeepCopyOptSysEle();
				optSysEleThread3_2_forDLS = geneticThread_3.getOptimizedOpticalSystemElement().getDeepCopyOptSysEle();
			}
		#pragma omp section // 4
			{
				// thread 4 -> mean 0, std 100
				OpticalSystemElement optSysEleThread4 = mOptSysEle.getDeepCopyOptSysEle();
				Genetic geneticThread_4(/*optSysEle*/ optSysEleThread4, /*fields*/ mFields_vec,/*wavelengths*/ mWavelength_vec, /*rings*/ mRings, /*arms*/ mArms, /*populatuion*/ mPopulation, /*target cardinal points*/ mTargetCarPoints, /*default parameter*/ mDefaultParameterGenetic);
				geneticThread_4.setChooseValueMode(normalDistributionMode);
				geneticThread_4.setMeanToCalcND(0.0);
				geneticThread_4.setStddevToCalcND(100.0);
				std::cout << "start genetic core 4" << std::endl;
				geneticThread_4.doTheGeneticProcess(); 

				optSysEleThread4_1_forDLS = geneticThread_4.getOptimizedOpticalSystemElement().getDeepCopyOptSysEle();
				optSysEleThread4_2_forDLS = geneticThread_4.getOptimizedOpticalSystemElement().getDeepCopyOptSysEle();
			}
		#pragma omp section // 5
			{
				// thread 5 -> mean 0, std 150
				OpticalSystemElement optSysEleThread5 = mOptSysEle.getDeepCopyOptSysEle();
				Genetic geneticThread_5(/*optSysEle*/ optSysEleThread5, /*fields*/ mFields_vec,/*wavelengths*/ mWavelength_vec, /*rings*/ mRings, /*arms*/ mArms, /*populatuion*/ mPopulation, /*target cardinal points*/ mTargetCarPoints, /*default parameter*/ mDefaultParameterGenetic);
				geneticThread_5.setChooseValueMode(normalDistributionMode);
				geneticThread_5.setMeanToCalcND(0.0);
				geneticThread_5.setStddevToCalcND(150.0);
				std::cout << "start genetic core 5" << std::endl;
				geneticThread_5.doTheGeneticProcess(); 

				optSysEleThread5_1_forDLS = geneticThread_5.getOptimizedOpticalSystemElement().getDeepCopyOptSysEle();
				optSysEleThread5_2_forDLS = geneticThread_5.getOptimizedOpticalSystemElement().getDeepCopyOptSysEle();

			}
		#pragma omp section // 6
			{
				// thread 6 -> mean 0, std 200
				OpticalSystemElement optSysEleThread6 = mOptSysEle.getDeepCopyOptSysEle();
				Genetic geneticThread_6(/*optSysEle*/ optSysEleThread6, /*fields*/ mFields_vec,/*wavelengths*/ mWavelength_vec, /*rings*/ mRings, /*arms*/ mArms, /*populatuion*/ mPopulation, /*target cardinal points*/ mTargetCarPoints, /*default parameter*/ mDefaultParameterGenetic);
				geneticThread_6.setChooseValueMode(normalDistributionMode);
				geneticThread_6.setMeanToCalcND(0.0);
				geneticThread_6.setStddevToCalcND(200.0);
				std::cout << "start genetic core 6" << std::endl;
				geneticThread_6.doTheGeneticProcess(); 

				optSysEleThread6_1_forDLS = geneticThread_6.getOptimizedOpticalSystemElement().getDeepCopyOptSysEle();
				optSysEleThread6_2_forDLS = geneticThread_6.getOptimizedOpticalSystemElement().getDeepCopyOptSysEle();

			}
		#pragma omp section // 7
			{
				// thread 7 -> mean 0, std 250
				OpticalSystemElement optSysEleThread7 = mOptSysEle.getDeepCopyOptSysEle();
				Genetic geneticThread_7(/*optSysEle*/ optSysEleThread7, /*fields*/ mFields_vec,/*wavelengths*/ mWavelength_vec, /*rings*/ mRings, /*arms*/ mArms, /*populatuion*/ mPopulation, /*target cardinal points*/ mTargetCarPoints, /*default parameter*/ mDefaultParameterGenetic);
				geneticThread_7.setChooseValueMode(normalDistributionMode);
				geneticThread_7.setMeanToCalcND(0.0);
				geneticThread_7.setStddevToCalcND(250.0);
				std::cout << "start genetic core 7" << std::endl;
				geneticThread_7.doTheGeneticProcess();

				optSysEleThread7_1_forDLS = geneticThread_7.getOptimizedOpticalSystemElement().getDeepCopyOptSysEle();
				optSysEleThread7_2_forDLS = geneticThread_7.getOptimizedOpticalSystemElement().getDeepCopyOptSysEle();
			}
		#pragma omp section // 8
			{
				// thread 8 -> mean 0, std 300
				OpticalSystemElement optSysEleThread8 = mOptSysEle.getDeepCopyOptSysEle();
				Genetic geneticThread_8(/*optSysEle*/ optSysEleThread8, /*fields*/ mFields_vec,/*wavelengths*/ mWavelength_vec, /*rings*/ mRings, /*arms*/ mArms, /*populatuion*/ mPopulation, /*target cardinal points*/ mTargetCarPoints, /*default parameter*/ mDefaultParameterGenetic);
				geneticThread_8.setChooseValueMode(normalDistributionMode);
				geneticThread_8.setMeanToCalcND(0.0);
				geneticThread_8.setStddevToCalcND(300.0);
				std::cout << "start genetic core 8" << std::endl;
				geneticThread_8.doTheGeneticProcess();

				optSysEleThread8_1_forDLS = geneticThread_8.getOptimizedOpticalSystemElement().getDeepCopyOptSysEle();
				optSysEleThread8_2_forDLS = geneticThread_8.getOptimizedOpticalSystemElement().getDeepCopyOptSysEle();

			}
		#pragma omp section // 9
			{
				// thread 9 -> mean 0, std 350
				OpticalSystemElement optSysEleThread9 = mOptSysEle.getDeepCopyOptSysEle();
				Genetic geneticThread_9(/*optSysEle*/ optSysEleThread9, /*fields*/ mFields_vec,/*wavelengths*/ mWavelength_vec, /*rings*/ mRings, /*arms*/ mArms, /*populatuion*/ mPopulation, /*target cardinal points*/ mTargetCarPoints, /*default parameter*/ mDefaultParameterGenetic);
				geneticThread_9.setChooseValueMode(normalDistributionMode);
				geneticThread_9.setMeanToCalcND(0.0);
				geneticThread_9.setStddevToCalcND(350.0);
				std::cout << "start genetic core 9" << std::endl;
				geneticThread_9.doTheGeneticProcess();

				optSysEleThread9_1_forDLS = geneticThread_9.getOptimizedOpticalSystemElement().getDeepCopyOptSysEle();
				optSysEleThread9_2_forDLS = geneticThread_9.getOptimizedOpticalSystemElement().getDeepCopyOptSysEle();

			}
		#pragma omp section // 10
			{
				// thread 10 -> mean 0, std 400
				OpticalSystemElement optSysEleThread10 = mOptSysEle.getDeepCopyOptSysEle();
				Genetic geneticThread_10(/*optSysEle*/ optSysEleThread10, /*fields*/ mFields_vec,/*wavelengths*/ mWavelength_vec, /*rings*/ mRings, /*arms*/ mArms, /*populatuion*/ mPopulation, /*target cardinal points*/ mTargetCarPoints, /*default parameter*/ mDefaultParameterGenetic);
				geneticThread_10.setChooseValueMode(normalDistributionMode);
				geneticThread_10.setMeanToCalcND(0.0);
				geneticThread_10.setStddevToCalcND(400.0);
				std::cout << "start genetic core 10" << std::endl;
				geneticThread_10.doTheGeneticProcess();

				optSysEleThread10_1_forDLS = geneticThread_10.getOptimizedOpticalSystemElement().getDeepCopyOptSysEle();
				optSysEleThread10_2_forDLS = geneticThread_10.getOptimizedOpticalSystemElement().getDeepCopyOptSysEle();
				
			}
		#pragma omp section // 11
			{
				// thread 11 -> mean 0, std 450
				OpticalSystemElement optSysEleThread11 = mOptSysEle.getDeepCopyOptSysEle();
				Genetic geneticThread_11(/*optSysEle*/ optSysEleThread11, /*fields*/ mFields_vec,/*wavelengths*/ mWavelength_vec, /*rings*/ mRings, /*arms*/ mArms, /*populatuion*/ mPopulation, /*target cardinal points*/ mTargetCarPoints, /*default parameter*/ mDefaultParameterGenetic);
				geneticThread_11.setChooseValueMode(normalDistributionMode);
				geneticThread_11.setMeanToCalcND(0.0);
				geneticThread_11.setStddevToCalcND(450.0);
				std::cout << "start genetic core 11" << std::endl;
				geneticThread_11.doTheGeneticProcess();

				optSysEleThread11_1_forDLS = geneticThread_11.getOptimizedOpticalSystemElement().getDeepCopyOptSysEle();
				optSysEleThread11_2_forDLS = geneticThread_11.getOptimizedOpticalSystemElement().getDeepCopyOptSysEle();
			}
		
		#pragma omp section // 12
			{
				// thread 12 -> mean 0, std 500
				OpticalSystemElement optSysEleThread12 = mOptSysEle.getDeepCopyOptSysEle();
				Genetic geneticThread_12(/*optSysEle*/ optSysEleThread12, /*fields*/ mFields_vec,/*wavelengths*/ mWavelength_vec, /*rings*/ mRings, /*arms*/ mArms, /*populatuion*/ mPopulation, /*target cardinal points*/ mTargetCarPoints, /*default parameter*/ mDefaultParameterGenetic);
				geneticThread_12.setChooseValueMode(normalDistributionMode);
				geneticThread_12.setMeanToCalcND(0.0);
				geneticThread_12.setStddevToCalcND(500.0);
				std::cout << "start genetic core 12" << std::endl;
				geneticThread_12.doTheGeneticProcess();

				optSysEleThread12_1_forDLS = geneticThread_12.getOptimizedOpticalSystemElement().getDeepCopyOptSysEle();
				optSysEleThread12_2_forDLS = geneticThread_12.getOptimizedOpticalSystemElement().getDeepCopyOptSysEle();
			}
		}
		


	// save the core
	unsigned int numberDLS_optimizations = 12;
	
	mAllMeritVal_vec.resize(numberDLS_optimizations);

	std::vector<OpticalSystemElement> optmizedSystem_vec;
	optmizedSystem_vec.resize(numberDLS_optimizations);

#pragma omp parallel sections
{
	#pragma omp section // 1
		{

			// optimize the systems using DLS
			// thread 1
			DLS DLS1_1(/*optSysEle*/ optSysEleThread1_1_forDLS, /*fields*/ mFields_vec, /*wavelengths*/ mWavelength_vec, /*rings*/ mRings, /*arms*/ mArms, /*target cardinal points*/ mTargetCarPoints, /*default DLS*/ mDefaultPrameterDLS);
			DLS1_1.turnOffImaProc();
			DLS1_1.setFactorGettingBetter(mFactorBetter_1);
			DLS1_1.setFactorGettingWorst(mFactorWorst_1);

			DLS DLS1_2(/*optSysEle*/ optSysEleThread1_2_forDLS, /*fields*/ mFields_vec, /*wavelengths*/ mWavelength_vec, /*rings*/ mRings, /*arms*/ mArms, /*target cardinal points*/ mTargetCarPoints, /*default DLS*/ mDefaultPrameterDLS);
			DLS1_2.turnOffImaProc();
			DLS1_2.setFactorGettingBetter(mFactorBetter_2);
			DLS1_2.setFactorGettingWorst(mFactorWorst_2);

			std::cout << "DLS 1_1" << std::endl;
			DLS1_1.optimizeSystem_DLS_multiplicativ_Damping();
			mAllMeritVal_vec[0] = DLS1_1.getBestMeritValue();
			std::cout << "DLS 1_2" << std::endl;
			DLS1_2.optimizeSystem_DLS_multiplicativ_Damping();
			mAllMeritVal_vec[1] = DLS1_2.getBestMeritValue();

			optmizedSystem_vec[0] = DLS1_1.getOptimizedSystem_HLT();
			optmizedSystem_vec[1] = DLS1_2.getOptimizedSystem_HLT();

			// just for debugging
			// std::cout << "DLS 1_1" << std::endl;
			// oftenUse::print(DLS1_1.getOptimizedSystem_HLT(), mWavelength_vec[0]);


		}
	#pragma omp section // 2
		{

			//// just for debugging
			//std::cout << "optical system thread 2" << std::endl;
			//oftenUse::print(optSysEleThread2_1_forDLS, mWavelength_vec[0]);
			
			// thread 2
			DLS DLS2_1(/*optSysEle*/ optSysEleThread2_1_forDLS, /*fields*/ mFields_vec, /*wavelengths*/ mWavelength_vec, /*rings*/ mRings, /*arms*/ mArms, /*target cardinal points*/ mTargetCarPoints, /*default DLS*/ mDefaultPrameterDLS);
			DLS2_1.turnOffImaProc();
			DLS2_1.setFactorGettingBetter(mFactorBetter_1);
			DLS2_1.setFactorGettingWorst(mFactorWorst_1);

			DLS DLS2_2(/*optSysEle*/ optSysEleThread2_2_forDLS, /*fields*/ mFields_vec, /*wavelengths*/ mWavelength_vec, /*rings*/ mRings, /*arms*/ mArms, /*target cardinal points*/ mTargetCarPoints, /*default DLS*/ mDefaultPrameterDLS);
			DLS2_2.turnOffImaProc();
			DLS2_2.setFactorGettingBetter(mFactorBetter_2);
			DLS2_2.setFactorGettingWorst(mFactorWorst_2);

			std::cout << "DLS 2_1" << std::endl;
			DLS2_1.optimizeSystem_DLS_multiplicativ_Damping();
			mAllMeritVal_vec[2] = DLS2_1.getBestMeritValue();
			std::cout << "DLS 2_2" << std::endl;
			DLS2_2.optimizeSystem_DLS_multiplicativ_Damping();
			mAllMeritVal_vec[3] = DLS2_2.getBestMeritValue();

			optmizedSystem_vec[2] = DLS2_1.getOptimizedSystem_HLT();
			optmizedSystem_vec[3] = DLS2_2.getOptimizedSystem_HLT();

		}
	#pragma omp section // 3
		{

			// thread 3
			DLS DLS3_1(/*optSysEle*/ optSysEleThread3_1_forDLS, /*fields*/ mFields_vec, /*wavelengths*/ mWavelength_vec, /*rings*/ mRings, /*arms*/ mArms, /*target cardinal points*/ mTargetCarPoints, /*default DLS*/ mDefaultPrameterDLS);
			DLS3_1.turnOffImaProc();
			DLS3_1.setFactorGettingBetter(mFactorBetter_1);
			DLS3_1.setFactorGettingWorst(mFactorWorst_1);

			DLS DLS3_2(/*optSysEle*/ optSysEleThread3_2_forDLS, /*fields*/ mFields_vec, /*wavelengths*/ mWavelength_vec, /*rings*/ mRings, /*arms*/ mArms, /*target cardinal points*/ mTargetCarPoints, /*default DLS*/ mDefaultPrameterDLS);
			DLS3_2.turnOffImaProc();
			DLS3_2.setFactorGettingBetter(mFactorBetter_2);
			DLS3_2.setFactorGettingWorst(mFactorWorst_2);

			std::cout << "DLS 3_1" << std::endl;
			DLS3_1.optimizeSystem_DLS_multiplicativ_Damping();
			mAllMeritVal_vec[4] = DLS3_1.getBestMeritValue();
			std::cout << "DLS 3_2" << std::endl;
			DLS3_2.optimizeSystem_DLS_multiplicativ_Damping();
			mAllMeritVal_vec[5] = DLS3_2.getBestMeritValue();

			optmizedSystem_vec[4] = DLS3_1.getOptimizedSystem_HLT();;
			optmizedSystem_vec[5] = DLS3_2.getOptimizedSystem_HLT();;

		}
	#pragma omp section // 4
		{

			// thread 4
			DLS DLS4_1(/*optSysEle*/ optSysEleThread4_1_forDLS, /*fields*/ mFields_vec, /*wavelengths*/ mWavelength_vec, /*rings*/ mRings, /*arms*/ mArms, /*target cardinal points*/ mTargetCarPoints, /*default DLS*/ mDefaultPrameterDLS);
			DLS4_1.turnOffImaProc();
			DLS4_1.setFactorGettingBetter(mFactorBetter_1);
			DLS4_1.setFactorGettingWorst(mFactorWorst_1);

			DLS DLS4_2(/*optSysEle*/ optSysEleThread4_2_forDLS, /*fields*/ mFields_vec, /*wavelengths*/ mWavelength_vec, /*rings*/ mRings, /*arms*/ mArms, /*target cardinal points*/ mTargetCarPoints, /*default DLS*/ mDefaultPrameterDLS);
			DLS4_2.turnOffImaProc();
			DLS4_2.setFactorGettingBetter(mFactorBetter_2);
			DLS4_2.setFactorGettingWorst(mFactorWorst_2);

			std::cout << "DLS 4_1" << std::endl;
			DLS4_1.optimizeSystem_DLS_multiplicativ_Damping();
			mAllMeritVal_vec[6] = DLS4_1.getBestMeritValue();
			std::cout << "DLS 4_2" << std::endl;
			DLS4_2.optimizeSystem_DLS_multiplicativ_Damping();
			mAllMeritVal_vec[7] = DLS4_2.getBestMeritValue();

			optmizedSystem_vec[6] = DLS4_1.getOptimizedSystem_HLT();;
			optmizedSystem_vec[7] = DLS4_2.getOptimizedSystem_HLT();;
		}
	#pragma omp section // 5
		{

			// thread 5
			DLS DLS5_1(/*optSysEle*/ optSysEleThread5_1_forDLS, /*fields*/ mFields_vec, /*wavelengths*/ mWavelength_vec, /*rings*/ mRings, /*arms*/ mArms, /*target cardinal points*/ mTargetCarPoints, /*default DLS*/ mDefaultPrameterDLS);
			DLS5_1.turnOffImaProc();
			DLS5_1.setFactorGettingBetter(mFactorBetter_1);
			DLS5_1.setFactorGettingWorst(mFactorWorst_1);

			DLS DLS5_2(/*optSysEle*/ optSysEleThread5_2_forDLS, /*fields*/ mFields_vec, /*wavelengths*/ mWavelength_vec, /*rings*/ mRings, /*arms*/ mArms, /*target cardinal points*/ mTargetCarPoints, /*default DLS*/ mDefaultPrameterDLS);
			DLS5_2.turnOffImaProc();
			DLS5_2.setFactorGettingBetter(mFactorBetter_2);
			DLS5_2.setFactorGettingWorst(mFactorWorst_2);

			std::cout << "DLS 5_1" << std::endl;
			DLS5_1.optimizeSystem_DLS_multiplicativ_Damping();
			mAllMeritVal_vec[8] = DLS5_1.getBestMeritValue();
			std::cout << "DLS 5_2" << std::endl;
			DLS5_2.optimizeSystem_DLS_multiplicativ_Damping();
			mAllMeritVal_vec[9] = DLS5_2.getBestMeritValue();

			optmizedSystem_vec[8] = DLS5_1.getOptimizedSystem_HLT();
			optmizedSystem_vec[9] = DLS5_2.getOptimizedSystem_HLT();
		}
	#pragma omp section // 6
		{

			// thread 6
			DLS DLS6_1(/*optSysEle*/ optSysEleThread6_1_forDLS, /*fields*/ mFields_vec, /*wavelengths*/ mWavelength_vec, /*rings*/ mRings, /*arms*/ mArms, /*target cardinal points*/ mTargetCarPoints, /*default DLS*/ mDefaultPrameterDLS);
			DLS6_1.turnOffImaProc();
			DLS6_1.setFactorGettingBetter(mFactorBetter_1);
			DLS6_1.setFactorGettingWorst(mFactorWorst_1);

			DLS DLS6_2(/*optSysEle*/ optSysEleThread6_2_forDLS, /*fields*/ mFields_vec, /*wavelengths*/ mWavelength_vec, /*rings*/ mRings, /*arms*/ mArms, /*target cardinal points*/ mTargetCarPoints, /*default DLS*/ mDefaultPrameterDLS);
			DLS6_2.turnOffImaProc();
			DLS6_2.setFactorGettingBetter(mFactorBetter_2);
			DLS6_2.setFactorGettingWorst(mFactorWorst_2);

			std::cout << "DLS 6_1" << std::endl;
			DLS6_1.optimizeSystem_DLS_multiplicativ_Damping();
			mAllMeritVal_vec[10] = DLS6_1.getBestMeritValue();
			std::cout << "DLS 6_2" << std::endl;
			DLS6_2.optimizeSystem_DLS_multiplicativ_Damping();
			mAllMeritVal_vec[11] = DLS6_2.getBestMeritValue();

			optmizedSystem_vec[10] = DLS6_1.getOptimizedSystem_HLT();;
			optmizedSystem_vec[11] = DLS6_2.getOptimizedSystem_HLT();;
		}
	#pragma omp section // 7
		{
			// thread 7
			DLS DLS7_1(/*optSysEle*/ optSysEleThread7_1_forDLS, /*fields*/ mFields_vec, /*wavelengths*/ mWavelength_vec, /*rings*/ mRings, /*arms*/ mArms, /*target cardinal points*/ mTargetCarPoints, /*default DLS*/ mDefaultPrameterDLS);
			DLS7_1.turnOffImaProc();
			DLS7_1.setFactorGettingBetter(mFactorBetter_1);
			DLS7_1.setFactorGettingWorst(mFactorWorst_1);

			DLS DLS7_2(/*optSysEle*/ optSysEleThread7_2_forDLS, /*fields*/ mFields_vec, /*wavelengths*/ mWavelength_vec, /*rings*/ mRings, /*arms*/ mArms, /*target cardinal points*/ mTargetCarPoints, /*default DLS*/ mDefaultPrameterDLS);
			DLS7_2.turnOffImaProc();
			DLS7_2.setFactorGettingBetter(mFactorBetter_2);
			DLS7_2.setFactorGettingWorst(mFactorWorst_2);

			std::cout << "DLS 7_1" << std::endl;
			DLS7_1.optimizeSystem_DLS_multiplicativ_Damping();
			mAllMeritVal_vec[12] = DLS7_1.getBestMeritValue();
			std::cout << "DLS 7_2" << std::endl;
			DLS7_2.optimizeSystem_DLS_multiplicativ_Damping();
			mAllMeritVal_vec[13] = DLS7_2.getBestMeritValue();

			optmizedSystem_vec[12] = DLS7_1.getOptimizedSystem_HLT();
			optmizedSystem_vec[13] = DLS7_2.getOptimizedSystem_HLT();

		}
	#pragma omp section // 8
		{
			// thread 8
			DLS DLS8_1(/*optSysEle*/ optSysEleThread8_1_forDLS, /*fields*/ mFields_vec, /*wavelengths*/ mWavelength_vec, /*rings*/ mRings, /*arms*/ mArms, /*target cardinal points*/ mTargetCarPoints, /*default DLS*/ mDefaultPrameterDLS);
			DLS8_1.turnOffImaProc();
			DLS8_1.setFactorGettingBetter(mFactorBetter_1);
			DLS8_1.setFactorGettingWorst(mFactorWorst_1);

			DLS DLS8_2(/*optSysEle*/ optSysEleThread8_2_forDLS, /*fields*/ mFields_vec, /*wavelengths*/ mWavelength_vec, /*rings*/ mRings, /*arms*/ mArms, /*target cardinal points*/ mTargetCarPoints, /*default DLS*/ mDefaultPrameterDLS);
			DLS8_2.turnOffImaProc();
			DLS8_2.setFactorGettingBetter(mFactorBetter_2);
			DLS8_2.setFactorGettingWorst(mFactorWorst_2);

			std::cout << "DLS 8_1" << std::endl;
			DLS8_1.optimizeSystem_DLS_multiplicativ_Damping();
			mAllMeritVal_vec[14] = DLS8_1.getBestMeritValue();
			std::cout << "DLS 8_2" << std::endl;
			DLS8_2.optimizeSystem_DLS_multiplicativ_Damping();
			mAllMeritVal_vec[15] = DLS8_2.getBestMeritValue();

			optmizedSystem_vec[14] = DLS8_1.getOptimizedSystem_HLT();;
			optmizedSystem_vec[15] = DLS8_2.getOptimizedSystem_HLT();;

		}
	#pragma omp section // 9
		{

			// thread 9
			DLS DLS9_1(/*optSysEle*/ optSysEleThread9_1_forDLS, /*fields*/ mFields_vec, /*wavelengths*/ mWavelength_vec, /*rings*/ mRings, /*arms*/ mArms, /*target cardinal points*/ mTargetCarPoints, /*default DLS*/ mDefaultPrameterDLS);
			DLS9_1.turnOffImaProc();
			DLS9_1.setFactorGettingBetter(mFactorBetter_1);
			DLS9_1.setFactorGettingWorst(mFactorWorst_1);

			DLS DLS9_2(/*optSysEle*/ optSysEleThread9_2_forDLS, /*fields*/ mFields_vec, /*wavelengths*/ mWavelength_vec, /*rings*/ mRings, /*arms*/ mArms, /*target cardinal points*/ mTargetCarPoints, /*default DLS*/ mDefaultPrameterDLS);
			DLS9_2.turnOffImaProc();
			DLS9_2.setFactorGettingBetter(mFactorBetter_2);
			DLS9_2.setFactorGettingWorst(mFactorWorst_2);

			std::cout << "DLS 9_1" << std::endl;
			DLS9_1.optimizeSystem_DLS_multiplicativ_Damping();
			mAllMeritVal_vec[16] = DLS9_1.getBestMeritValue();
			std::cout << "DLS 9_2" << std::endl;
			DLS9_2.optimizeSystem_DLS_multiplicativ_Damping();
			mAllMeritVal_vec[17] = DLS9_2.getBestMeritValue();

			optmizedSystem_vec[16] = DLS9_1.getOptimizedSystem_HLT();;
			optmizedSystem_vec[17] = DLS9_2.getOptimizedSystem_HLT();;

		}
	#pragma omp section // 10
		{

			// thread 10
			DLS DLS10_1(/*optSysEle*/ optSysEleThread10_1_forDLS, /*fields*/ mFields_vec, /*wavelengths*/ mWavelength_vec, /*rings*/ mRings, /*arms*/ mArms, /*target cardinal points*/ mTargetCarPoints, /*default DLS*/ mDefaultPrameterDLS);
			DLS10_1.turnOffImaProc();
			DLS10_1.setFactorGettingBetter(mFactorBetter_1);
			DLS10_1.setFactorGettingWorst(mFactorWorst_1);

			DLS DLS10_2(/*optSysEle*/ optSysEleThread10_2_forDLS, /*fields*/ mFields_vec, /*wavelengths*/ mWavelength_vec, /*rings*/ mRings, /*arms*/ mArms, /*target cardinal points*/ mTargetCarPoints, /*default DLS*/ mDefaultPrameterDLS);
			DLS10_2.turnOffImaProc();
			DLS10_2.setFactorGettingBetter(mFactorBetter_2);
			DLS10_2.setFactorGettingWorst(mFactorWorst_2);

			std::cout << "DLS 10_1" << std::endl;
			DLS10_1.optimizeSystem_DLS_multiplicativ_Damping();
			mAllMeritVal_vec[18] = DLS10_1.getBestMeritValue();
			std::cout << "DLS 10_2" << std::endl;
			DLS10_2.optimizeSystem_DLS_multiplicativ_Damping();
			mAllMeritVal_vec[19] = DLS10_2.getBestMeritValue();

			optmizedSystem_vec[18] = DLS10_1.getOptimizedSystem_HLT();
			optmizedSystem_vec[19] = DLS10_2.getOptimizedSystem_HLT();

		}
	#pragma omp section // 11
		{
			// thread 11
			DLS DLS11_1(/*optSysEle*/ optSysEleThread11_1_forDLS, /*fields*/ mFields_vec, /*wavelengths*/ mWavelength_vec, /*rings*/ mRings, /*arms*/ mArms, /*target cardinal points*/ mTargetCarPoints, /*default DLS*/ mDefaultPrameterDLS);
			DLS11_1.turnOffImaProc();
			DLS11_1.setFactorGettingBetter(mFactorBetter_1);
			DLS11_1.setFactorGettingWorst(mFactorWorst_1);

			DLS DLS11_2(/*optSysEle*/ optSysEleThread11_2_forDLS, /*fields*/ mFields_vec, /*wavelengths*/ mWavelength_vec, /*rings*/ mRings, /*arms*/ mArms, /*target cardinal points*/ mTargetCarPoints, /*default DLS*/ mDefaultPrameterDLS);
			DLS11_2.turnOffImaProc();
			DLS11_2.setFactorGettingBetter(mFactorBetter_2);
			DLS11_2.setFactorGettingWorst(mFactorWorst_2);

			std::cout << "DLS 11_1" << std::endl;
			DLS11_1.optimizeSystem_DLS_multiplicativ_Damping();
			mAllMeritVal_vec[20] = DLS11_1.getBestMeritValue();
			std::cout << "DLS 11_2" << std::endl;
			DLS11_2.optimizeSystem_DLS_multiplicativ_Damping();
			mAllMeritVal_vec[21] = DLS11_2.getBestMeritValue();

			optmizedSystem_vec[20] = DLS11_1.getOptimizedSystem_HLT();
			optmizedSystem_vec[21] = DLS11_2.getOptimizedSystem_HLT();

		}
	
		
	#pragma omp section // 12
		{

			// thread 12
			DLS DLS12_1(/*optSysEle*/ optSysEleThread12_1_forDLS, /*fields*/ mFields_vec, /*wavelengths*/ mWavelength_vec, /*rings*/ mRings, /*arms*/ mArms, /*target cardinal points*/ mTargetCarPoints, /*default DLS*/ mDefaultPrameterDLS);
			DLS12_1.turnOffImaProc();
			DLS12_1.setFactorGettingBetter(mFactorBetter_1);
			DLS12_1.setFactorGettingWorst(mFactorWorst_1);
			
			DLS DLS12_2(/*optSysEle*/ optSysEleThread12_2_forDLS, /*fields*/ mFields_vec, /*wavelengths*/ mWavelength_vec, /*rings*/ mRings, /*arms*/ mArms, /*target cardinal points*/ mTargetCarPoints, /*default DLS*/ mDefaultPrameterDLS);
			DLS12_2.turnOffImaProc();
			DLS12_2.setFactorGettingBetter(mFactorBetter_2);
			DLS12_2.setFactorGettingWorst(mFactorWorst_2);

			std::cout << "DLS 12_1" << std::endl;
			DLS12_1.optimizeSystem_DLS_multiplicativ_Damping();
			mAllMeritVal_vec[22] = DLS12_1.getBestMeritValue();
			std::cout << "DLS 12_2" << std::endl;
			DLS12_2.optimizeSystem_DLS_multiplicativ_Damping();
			mAllMeritVal_vec[23] = DLS12_2.getBestMeritValue();

			
			optmizedSystem_vec[22] = DLS12_1.getOptimizedSystem_HLT();
			optmizedSystem_vec[23] = DLS12_2.getOptimizedSystem_HLT();
		}
}


			mBestMeritVal = mAllMeritVal_vec[0];
		mOptimizedOpticalSystemElement_firstIteration = optmizedSystem_vec[0];

		for (unsigned int i = 1; i < numberDLS_optimizations; ++i)
		{
			if (mBestMeritVal > mAllMeritVal_vec[i])
			{
				mBestMeritVal = mAllMeritVal_vec[i];
				mOptimizedOpticalSystemElement_firstIteration = optmizedSystem_vec[i].getDeepCopyOptSysEle();
			}
		}

	mOptimizedOpticalSystemElement_firstIteration.convertHLTSurfacesToLLTSurfaces();
	

	DLS_multiThreads_12 DLS_mulit_12(mOptimizedOpticalSystemElement_firstIteration, mFields_vec, mWavelength_vec, mRings, mArms, mTargetCarPoints, mDefaultPrameterDLS);
	// do the optimization
	mOptimizedOpticalSystemElement_secondIteration = DLS_mulit_12.DLS_optimisation_multiThreads_12_obj();
	mBestMeritVal = DLS_mulit_12.getBestMeritValue();
	
	return mOptimizedOpticalSystemElement_secondIteration;
}

OpticalSystemElement OptimizeSystemSuperFct_GeneticAndDLS::optimizeSuperFct_GeneticAndDLS_12Cores_inf()
{
	int nProcessors = omp_get_max_threads();
	// check if there are 6 threads
	if (nProcessors < 12)
	{
		std::cout << "there are no 12 threads to do the optimization" << std::endl;
	}

	// build the optical systems for DLS
	OpticalSystemElement optSysEleThread1_1_forDLS;
	OpticalSystemElement optSysEleThread1_2_forDLS;

	OpticalSystemElement optSysEleThread2_1_forDLS;
	OpticalSystemElement optSysEleThread2_2_forDLS;

	OpticalSystemElement optSysEleThread3_1_forDLS;
	OpticalSystemElement optSysEleThread3_2_forDLS;

	OpticalSystemElement optSysEleThread4_1_forDLS;
	OpticalSystemElement optSysEleThread4_2_forDLS;

	OpticalSystemElement optSysEleThread5_1_forDLS;
	OpticalSystemElement optSysEleThread5_2_forDLS;

	OpticalSystemElement optSysEleThread6_1_forDLS;
	OpticalSystemElement optSysEleThread6_2_forDLS;

	OpticalSystemElement optSysEleThread7_1_forDLS;
	OpticalSystemElement optSysEleThread7_2_forDLS;

	OpticalSystemElement optSysEleThread8_1_forDLS;
	OpticalSystemElement optSysEleThread8_2_forDLS;

	OpticalSystemElement optSysEleThread9_1_forDLS;
	OpticalSystemElement optSysEleThread9_2_forDLS;

	OpticalSystemElement optSysEleThread10_1_forDLS;
	OpticalSystemElement optSysEleThread10_2_forDLS;

	OpticalSystemElement optSysEleThread11_1_forDLS;
	OpticalSystemElement optSysEleThread11_2_forDLS;

	OpticalSystemElement optSysEleThread12_1_forDLS;
	OpticalSystemElement optSysEleThread12_2_forDLS;

#pragma omp parallel sections
	{
	#pragma omp section // 1
		{
			// thread 1 -> random mode
			OpticalSystemElement optSysEleThread1 = mOptSysEle.getDeepCopyOptSysEle();
			Genetic geneticThread_1(/*optSysEle*/ optSysEleThread1, /*angleX*/ mAngleX, /*angleY*/ mAngleY, /*wavelengths*/ mWavelength_vec, /*rings*/ mRings, /*arms*/ mArms, /*populatuion*/ mPopulation, /*target cardinal points*/ mTargetCarPoints, /*default parameter*/ mDefaultParameterGenetic);
			geneticThread_1.setChooseValueMode(randomMode);
			std::cout << "start genetic core 1" << std::endl;
			geneticThread_1.doTheGeneticProcess();

			OpticalSystemElement saveOptSys_1 = geneticThread_1.getOptimizedOpticalSystemElement();
			optSysEleThread1_1_forDLS = saveOptSys_1.getDeepCopyOptSysEle();

			OpticalSystemElement saveOptSys_2 = geneticThread_1.getOptimizedOpticalSystemElement();
			optSysEleThread1_2_forDLS = saveOptSys_2.getDeepCopyOptSysEle();
		}
	#pragma omp section // 2
		{
			// thread 2 -> clever sampling

			OpticalSystemElement optSysEleThread2 = mOptSysEle.getDeepCopyOptSysEle();
			Genetic geneticThread_2(/*optSysEle*/ optSysEleThread2, /*angleX*/ mAngleX, /*angleY*/ mAngleY, /*wavelengths*/ mWavelength_vec, /*rings*/ mRings, /*arms*/ mArms, /*populatuion*/ mPopulation, /*target cardinal points*/ mTargetCarPoints, /*default parameter*/ mDefaultParameterGenetic);
			geneticThread_2.setChooseValueMode(cleverSamplingMode);
			std::cout << "start genetic core 2" << std::endl;
			geneticThread_2.doTheGeneticProcess();

			optSysEleThread2_1_forDLS = geneticThread_2.getOptimizedOpticalSystemElement().getDeepCopyOptSysEle();
			optSysEleThread2_2_forDLS = geneticThread_2.getOptimizedOpticalSystemElement().getDeepCopyOptSysEle();
		}
	#pragma omp section // 3
		{
			// thread 3 -> mean 0, std 50
			OpticalSystemElement optSysEleThread3 = mOptSysEle.getDeepCopyOptSysEle();
			Genetic geneticThread_3(/*optSysEle*/ optSysEleThread3,  /*angleX*/ mAngleX, /*angleY*/ mAngleY, /*wavelengths*/ mWavelength_vec, /*rings*/ mRings, /*arms*/ mArms, /*populatuion*/ mPopulation, /*target cardinal points*/ mTargetCarPoints, /*default parameter*/ mDefaultParameterGenetic);
			geneticThread_3.setChooseValueMode(normalDistributionMode);
			geneticThread_3.setMeanToCalcND(0.0);
			geneticThread_3.setStddevToCalcND(50.0);
			std::cout << "start genetic core 3" << std::endl;
			geneticThread_3.doTheGeneticProcess();

			optSysEleThread3_1_forDLS = geneticThread_3.getOptimizedOpticalSystemElement().getDeepCopyOptSysEle();
			optSysEleThread3_2_forDLS = geneticThread_3.getOptimizedOpticalSystemElement().getDeepCopyOptSysEle();
		}
	#pragma omp section // 4
		{
			// thread 4 -> mean 0, std 100
			OpticalSystemElement optSysEleThread4 = mOptSysEle.getDeepCopyOptSysEle();
			Genetic geneticThread_4(/*optSysEle*/ optSysEleThread4, /*angleX*/ mAngleX, /*angleY*/ mAngleY, /*wavelengths*/ mWavelength_vec, /*rings*/ mRings, /*arms*/ mArms, /*populatuion*/ mPopulation, /*target cardinal points*/ mTargetCarPoints, /*default parameter*/ mDefaultParameterGenetic);
			geneticThread_4.setChooseValueMode(normalDistributionMode);
			geneticThread_4.setMeanToCalcND(0.0);
			geneticThread_4.setStddevToCalcND(100.0);
			std::cout << "start genetic core 4" << std::endl;
			geneticThread_4.doTheGeneticProcess();

			optSysEleThread4_1_forDLS = geneticThread_4.getOptimizedOpticalSystemElement().getDeepCopyOptSysEle();
			optSysEleThread4_2_forDLS = geneticThread_4.getOptimizedOpticalSystemElement().getDeepCopyOptSysEle();
		}
	#pragma omp section // 5
		{
			// thread 5 -> mean 0, std 150
			OpticalSystemElement optSysEleThread5 = mOptSysEle.getDeepCopyOptSysEle();
			Genetic geneticThread_5(/*optSysEle*/ optSysEleThread5, /*angleX*/ mAngleX, /*angleY*/ mAngleY, /*wavelengths*/ mWavelength_vec, /*rings*/ mRings, /*arms*/ mArms, /*populatuion*/ mPopulation, /*target cardinal points*/ mTargetCarPoints, /*default parameter*/ mDefaultParameterGenetic);
			geneticThread_5.setChooseValueMode(normalDistributionMode);
			geneticThread_5.setMeanToCalcND(0.0);
			geneticThread_5.setStddevToCalcND(150.0);
			std::cout << "start genetic core 5" << std::endl;
			geneticThread_5.doTheGeneticProcess();

			optSysEleThread5_1_forDLS = geneticThread_5.getOptimizedOpticalSystemElement().getDeepCopyOptSysEle();
			optSysEleThread5_2_forDLS = geneticThread_5.getOptimizedOpticalSystemElement().getDeepCopyOptSysEle();

		}
	#pragma omp section // 6
		{
			// thread 6 -> mean 0, std 200
			OpticalSystemElement optSysEleThread6 = mOptSysEle.getDeepCopyOptSysEle();
			Genetic geneticThread_6(/*optSysEle*/ optSysEleThread6, /*angleX*/ mAngleX, /*angleY*/ mAngleY, /*wavelengths*/ mWavelength_vec, /*rings*/ mRings, /*arms*/ mArms, /*populatuion*/ mPopulation, /*target cardinal points*/ mTargetCarPoints, /*default parameter*/ mDefaultParameterGenetic);
			geneticThread_6.setChooseValueMode(normalDistributionMode);
			geneticThread_6.setMeanToCalcND(0.0);
			geneticThread_6.setStddevToCalcND(200.0);
			std::cout << "start genetic core 6" << std::endl;
			geneticThread_6.doTheGeneticProcess();

			optSysEleThread6_1_forDLS = geneticThread_6.getOptimizedOpticalSystemElement().getDeepCopyOptSysEle();
			optSysEleThread6_2_forDLS = geneticThread_6.getOptimizedOpticalSystemElement().getDeepCopyOptSysEle();

		}
	#pragma omp section // 7
		{
			// thread 7 -> mean 0, std 250
			OpticalSystemElement optSysEleThread7 = mOptSysEle.getDeepCopyOptSysEle();
			Genetic geneticThread_7(/*optSysEle*/ optSysEleThread7, /*angleX*/ mAngleX, /*angleY*/ mAngleY, /*wavelengths*/ mWavelength_vec, /*rings*/ mRings, /*arms*/ mArms, /*populatuion*/ mPopulation, /*target cardinal points*/ mTargetCarPoints, /*default parameter*/ mDefaultParameterGenetic);
			geneticThread_7.setChooseValueMode(normalDistributionMode);
			geneticThread_7.setMeanToCalcND(0.0);
			geneticThread_7.setStddevToCalcND(250.0);
			std::cout << "start genetic core 7" << std::endl;
			geneticThread_7.doTheGeneticProcess();

			optSysEleThread7_1_forDLS = geneticThread_7.getOptimizedOpticalSystemElement().getDeepCopyOptSysEle();
			optSysEleThread7_2_forDLS = geneticThread_7.getOptimizedOpticalSystemElement().getDeepCopyOptSysEle();
		}
	#pragma omp section // 8
		{
			// thread 8 -> mean 0, std 300
			OpticalSystemElement optSysEleThread8 = mOptSysEle.getDeepCopyOptSysEle();
			Genetic geneticThread_8(/*optSysEle*/ optSysEleThread8, /*angleX*/ mAngleX, /*angleY*/ mAngleY, /*wavelengths*/ mWavelength_vec, /*rings*/ mRings, /*arms*/ mArms, /*populatuion*/ mPopulation, /*target cardinal points*/ mTargetCarPoints, /*default parameter*/ mDefaultParameterGenetic);
			geneticThread_8.setChooseValueMode(normalDistributionMode);
			geneticThread_8.setMeanToCalcND(0.0);
			geneticThread_8.setStddevToCalcND(300.0);
			std::cout << "start genetic core 8" << std::endl;
			geneticThread_8.doTheGeneticProcess();

			optSysEleThread8_1_forDLS = geneticThread_8.getOptimizedOpticalSystemElement().getDeepCopyOptSysEle();
			optSysEleThread8_2_forDLS = geneticThread_8.getOptimizedOpticalSystemElement().getDeepCopyOptSysEle();

		}
	#pragma omp section // 9
		{
			// thread 9 -> mean 0, std 350
			OpticalSystemElement optSysEleThread9 = mOptSysEle.getDeepCopyOptSysEle();
			Genetic geneticThread_9(/*optSysEle*/ optSysEleThread9, /*angleX*/ mAngleX, /*angleY*/ mAngleY, /*wavelengths*/ mWavelength_vec, /*rings*/ mRings, /*arms*/ mArms, /*populatuion*/ mPopulation, /*target cardinal points*/ mTargetCarPoints, /*default parameter*/ mDefaultParameterGenetic);
			geneticThread_9.setChooseValueMode(normalDistributionMode);
			geneticThread_9.setMeanToCalcND(0.0);
			geneticThread_9.setStddevToCalcND(350.0);
			std::cout << "start genetic core 9" << std::endl;
			geneticThread_9.doTheGeneticProcess();

			optSysEleThread9_1_forDLS = geneticThread_9.getOptimizedOpticalSystemElement().getDeepCopyOptSysEle();
			optSysEleThread9_2_forDLS = geneticThread_9.getOptimizedOpticalSystemElement().getDeepCopyOptSysEle();

		}
	#pragma omp section // 10
		{
			// thread 10 -> mean 0, std 400
			OpticalSystemElement optSysEleThread10 = mOptSysEle.getDeepCopyOptSysEle();
			Genetic geneticThread_10(/*optSysEle*/ optSysEleThread10, /*angleX*/ mAngleX, /*angleY*/ mAngleY, /*wavelengths*/ mWavelength_vec, /*rings*/ mRings, /*arms*/ mArms, /*populatuion*/ mPopulation, /*target cardinal points*/ mTargetCarPoints, /*default parameter*/ mDefaultParameterGenetic);
			geneticThread_10.setChooseValueMode(normalDistributionMode);
			geneticThread_10.setMeanToCalcND(0.0);
			geneticThread_10.setStddevToCalcND(400.0);
			std::cout << "start genetic core 10" << std::endl;
			geneticThread_10.doTheGeneticProcess();

			optSysEleThread10_1_forDLS = geneticThread_10.getOptimizedOpticalSystemElement().getDeepCopyOptSysEle();
			optSysEleThread10_2_forDLS = geneticThread_10.getOptimizedOpticalSystemElement().getDeepCopyOptSysEle();

		}
	#pragma omp section // 11
		{
			// thread 11 -> mean 0, std 450
			OpticalSystemElement optSysEleThread11 = mOptSysEle.getDeepCopyOptSysEle();
			Genetic geneticThread_11(/*optSysEle*/ optSysEleThread11, /*angleX*/ mAngleX, /*angleY*/ mAngleY, /*wavelengths*/ mWavelength_vec, /*rings*/ mRings, /*arms*/ mArms, /*populatuion*/ mPopulation, /*target cardinal points*/ mTargetCarPoints, /*default parameter*/ mDefaultParameterGenetic);
			geneticThread_11.setChooseValueMode(normalDistributionMode);
			geneticThread_11.setMeanToCalcND(0.0);
			geneticThread_11.setStddevToCalcND(450.0);
			std::cout << "start genetic core 11" << std::endl;
			geneticThread_11.doTheGeneticProcess();

			optSysEleThread11_1_forDLS = geneticThread_11.getOptimizedOpticalSystemElement().getDeepCopyOptSysEle();
			optSysEleThread11_2_forDLS = geneticThread_11.getOptimizedOpticalSystemElement().getDeepCopyOptSysEle();
		}
	
	#pragma omp section // 12
		{
			// thread 12 -> mean 0, std 500
			OpticalSystemElement optSysEleThread12 = mOptSysEle.getDeepCopyOptSysEle();
			Genetic geneticThread_12(/*optSysEle*/ optSysEleThread12,/*angleX*/ mAngleX, /*angleY*/ mAngleY, /*wavelengths*/ mWavelength_vec, /*rings*/ mRings, /*arms*/ mArms, /*populatuion*/ mPopulation, /*target cardinal points*/ mTargetCarPoints, /*default parameter*/ mDefaultParameterGenetic);
			geneticThread_12.setChooseValueMode(normalDistributionMode);
			geneticThread_12.setMeanToCalcND(0.0);
			geneticThread_12.setStddevToCalcND(500.0);
			std::cout << "start genetic core 12" << std::endl;
			geneticThread_12.doTheGeneticProcess();

			optSysEleThread12_1_forDLS = geneticThread_12.getOptimizedOpticalSystemElement().getDeepCopyOptSysEle();
			optSysEleThread12_2_forDLS = geneticThread_12.getOptimizedOpticalSystemElement().getDeepCopyOptSysEle();
		}
	}

	// save the core
	unsigned int numberDLS_optimizations = 24;

	mAllMeritVal_vec.resize(numberDLS_optimizations);

	std::vector<OpticalSystemElement> optmizedSystem_vec;
	optmizedSystem_vec.resize(numberDLS_optimizations);

#pragma omp parallel sections
	{
	#pragma omp section // 1
		{

			// optimize the systems using DLS
			// thread 1
			DLS DLS1_1(/*optSysEle*/ optSysEleThread1_1_forDLS, /*angleX*/ mAngleX, /*angleY*/ mAngleY, /*wavelengths*/ mWavelength_vec, /*rings*/ mRings, /*arms*/ mArms, /*target cardinal points*/ mTargetCarPoints, /*default DLS*/ mDefaultPrameterDLS);
			DLS1_1.turnOffImaProc();
			DLS1_1.setFactorGettingBetter(mFactorBetter_1);
			DLS1_1.setFactorGettingWorst(mFactorWorst_1);

			DLS DLS1_2(/*optSysEle*/ optSysEleThread1_2_forDLS,/*angleX*/ mAngleX, /*angleY*/ mAngleY, /*wavelengths*/ mWavelength_vec, /*rings*/ mRings, /*arms*/ mArms, /*target cardinal points*/ mTargetCarPoints, /*default DLS*/ mDefaultPrameterDLS);
			DLS1_2.turnOffImaProc();
			DLS1_2.setFactorGettingBetter(mFactorBetter_2);
			DLS1_2.setFactorGettingWorst(mFactorWorst_2);

			std::cout << "DLS 1_1" << std::endl;
			DLS1_1.optimizeSystem_DLS_multiplicativ_Damping();
			mAllMeritVal_vec[0] = DLS1_1.getBestMeritValue();
			std::cout << "DLS 1_2" << std::endl;
			DLS1_2.optimizeSystem_DLS_multiplicativ_Damping();
			mAllMeritVal_vec[1] = DLS1_2.getBestMeritValue();

			optmizedSystem_vec[0] = DLS1_1.getOptimizedSystem_HLT();
			optmizedSystem_vec[1] = DLS1_2.getOptimizedSystem_HLT();

			// just for debugging
			// std::cout << "DLS 1_1" << std::endl;
			// oftenUse::print(DLS1_1.getOptimizedSystem_HLT(), mWavelength_vec[0]);


		}
	#pragma omp section // 2
		{

			//// just for debugging
			//std::cout << "optical system thread 2" << std::endl;
			//oftenUse::print(optSysEleThread2_1_forDLS, mWavelength_vec[0]);

			// thread 2
			DLS DLS2_1(/*optSysEle*/ optSysEleThread2_1_forDLS, /*angleX*/ mAngleX, /*angleY*/ mAngleY, /*wavelengths*/ mWavelength_vec, /*rings*/ mRings, /*arms*/ mArms, /*target cardinal points*/ mTargetCarPoints, /*default DLS*/ mDefaultPrameterDLS);
			DLS2_1.turnOffImaProc();
			DLS2_1.setFactorGettingBetter(mFactorBetter_1);
			DLS2_1.setFactorGettingWorst(mFactorWorst_1);

			DLS DLS2_2(/*optSysEle*/ optSysEleThread2_2_forDLS, /*angleX*/ mAngleX, /*angleY*/ mAngleY, /*wavelengths*/ mWavelength_vec, /*rings*/ mRings, /*arms*/ mArms, /*target cardinal points*/ mTargetCarPoints, /*default DLS*/ mDefaultPrameterDLS);
			DLS2_2.turnOffImaProc();
			DLS2_2.setFactorGettingBetter(mFactorBetter_2);
			DLS2_2.setFactorGettingWorst(mFactorWorst_2);

			std::cout << "DLS 2_1" << std::endl;
			DLS2_1.optimizeSystem_DLS_multiplicativ_Damping();
			mAllMeritVal_vec[2] = DLS2_1.getBestMeritValue();
			std::cout << "DLS 2_2" << std::endl;
			DLS2_2.optimizeSystem_DLS_multiplicativ_Damping();
			mAllMeritVal_vec[3] = DLS2_2.getBestMeritValue();

			optmizedSystem_vec[2] = DLS2_1.getOptimizedSystem_HLT();
			optmizedSystem_vec[3] = DLS2_2.getOptimizedSystem_HLT();

		}
	#pragma omp section // 3
		{

			// thread 3
			DLS DLS3_1(/*optSysEle*/ optSysEleThread3_1_forDLS, /*angleX*/ mAngleX, /*angleY*/ mAngleY, /*wavelengths*/ mWavelength_vec, /*rings*/ mRings, /*arms*/ mArms, /*target cardinal points*/ mTargetCarPoints, /*default DLS*/ mDefaultPrameterDLS);
			DLS3_1.turnOffImaProc();
			DLS3_1.setFactorGettingBetter(mFactorBetter_1);
			DLS3_1.setFactorGettingWorst(mFactorWorst_1);

			DLS DLS3_2(/*optSysEle*/ optSysEleThread3_2_forDLS, /*angleX*/ mAngleX, /*angleY*/ mAngleY, /*wavelengths*/ mWavelength_vec, /*rings*/ mRings, /*arms*/ mArms, /*target cardinal points*/ mTargetCarPoints, /*default DLS*/ mDefaultPrameterDLS);
			DLS3_2.turnOffImaProc();
			DLS3_2.setFactorGettingBetter(mFactorBetter_2);
			DLS3_2.setFactorGettingWorst(mFactorWorst_2);

			std::cout << "DLS 3_1" << std::endl;
			DLS3_1.optimizeSystem_DLS_multiplicativ_Damping();
			mAllMeritVal_vec[4] = DLS3_1.getBestMeritValue();
			std::cout << "DLS 3_2" << std::endl;
			DLS3_2.optimizeSystem_DLS_multiplicativ_Damping();
			mAllMeritVal_vec[5] = DLS3_2.getBestMeritValue();

			optmizedSystem_vec[4] = DLS3_1.getOptimizedSystem_HLT();;
			optmizedSystem_vec[5] = DLS3_2.getOptimizedSystem_HLT();;

		}
	#pragma omp section // 4
		{

			// thread 4
			DLS DLS4_1(/*optSysEle*/ optSysEleThread4_1_forDLS, /*angleX*/ mAngleX, /*angleY*/ mAngleY, /*wavelengths*/ mWavelength_vec, /*rings*/ mRings, /*arms*/ mArms, /*target cardinal points*/ mTargetCarPoints, /*default DLS*/ mDefaultPrameterDLS);
			DLS4_1.turnOffImaProc();
			DLS4_1.setFactorGettingBetter(mFactorBetter_1);
			DLS4_1.setFactorGettingWorst(mFactorWorst_1);

			DLS DLS4_2(/*optSysEle*/ optSysEleThread4_2_forDLS, /*angleX*/ mAngleX, /*angleY*/ mAngleY, /*wavelengths*/ mWavelength_vec, /*rings*/ mRings, /*arms*/ mArms, /*target cardinal points*/ mTargetCarPoints, /*default DLS*/ mDefaultPrameterDLS);
			DLS4_2.turnOffImaProc();
			DLS4_2.setFactorGettingBetter(mFactorBetter_2);
			DLS4_2.setFactorGettingWorst(mFactorWorst_2);

			std::cout << "DLS 4_1" << std::endl;
			DLS4_1.optimizeSystem_DLS_multiplicativ_Damping();
			mAllMeritVal_vec[6] = DLS4_1.getBestMeritValue();
			std::cout << "DLS 4_2" << std::endl;
			DLS4_2.optimizeSystem_DLS_multiplicativ_Damping();
			mAllMeritVal_vec[7] = DLS4_2.getBestMeritValue();

			optmizedSystem_vec[6] = DLS4_1.getOptimizedSystem_HLT();;
			optmizedSystem_vec[7] = DLS4_2.getOptimizedSystem_HLT();;
		}
	#pragma omp section // 5
		{

			// thread 5
			DLS DLS5_1(/*optSysEle*/ optSysEleThread5_1_forDLS, /*angleX*/ mAngleX, /*angleY*/ mAngleY, /*wavelengths*/ mWavelength_vec, /*rings*/ mRings, /*arms*/ mArms, /*target cardinal points*/ mTargetCarPoints, /*default DLS*/ mDefaultPrameterDLS);
			DLS5_1.turnOffImaProc();
			DLS5_1.setFactorGettingBetter(mFactorBetter_1);
			DLS5_1.setFactorGettingWorst(mFactorWorst_1);

			DLS DLS5_2(/*optSysEle*/ optSysEleThread5_2_forDLS, /*angleX*/ mAngleX, /*angleY*/ mAngleY, /*wavelengths*/ mWavelength_vec, /*rings*/ mRings, /*arms*/ mArms, /*target cardinal points*/ mTargetCarPoints, /*default DLS*/ mDefaultPrameterDLS);
			DLS5_2.turnOffImaProc();
			DLS5_2.setFactorGettingBetter(mFactorBetter_2);
			DLS5_2.setFactorGettingWorst(mFactorWorst_2);

			std::cout << "DLS 5_1" << std::endl;
			DLS5_1.optimizeSystem_DLS_multiplicativ_Damping();
			mAllMeritVal_vec[8] = DLS5_1.getBestMeritValue();
			std::cout << "DLS 5_2" << std::endl;
			DLS5_2.optimizeSystem_DLS_multiplicativ_Damping();
			mAllMeritVal_vec[9] = DLS5_2.getBestMeritValue();

			optmizedSystem_vec[8] = DLS5_1.getOptimizedSystem_HLT();
			optmizedSystem_vec[9] = DLS5_2.getOptimizedSystem_HLT();
		}
	#pragma omp section // 6
		{

			// thread 6
			DLS DLS6_1(/*optSysEle*/ optSysEleThread6_1_forDLS, /*angleX*/ mAngleX, /*angleY*/ mAngleY, /*wavelengths*/ mWavelength_vec, /*rings*/ mRings, /*arms*/ mArms, /*target cardinal points*/ mTargetCarPoints, /*default DLS*/ mDefaultPrameterDLS);
			DLS6_1.turnOffImaProc();
			DLS6_1.setFactorGettingBetter(mFactorBetter_1);
			DLS6_1.setFactorGettingWorst(mFactorWorst_1);

			DLS DLS6_2(/*optSysEle*/ optSysEleThread6_2_forDLS, /*angleX*/ mAngleX, /*angleY*/ mAngleY, /*wavelengths*/ mWavelength_vec, /*rings*/ mRings, /*arms*/ mArms, /*target cardinal points*/ mTargetCarPoints, /*default DLS*/ mDefaultPrameterDLS);
			DLS6_2.turnOffImaProc();
			DLS6_2.setFactorGettingBetter(mFactorBetter_2);
			DLS6_2.setFactorGettingWorst(mFactorWorst_2);

			std::cout << "DLS 6_1" << std::endl;
			DLS6_1.optimizeSystem_DLS_multiplicativ_Damping();
			mAllMeritVal_vec[10] = DLS6_1.getBestMeritValue();
			std::cout << "DLS 6_2" << std::endl;
			DLS6_2.optimizeSystem_DLS_multiplicativ_Damping();
			mAllMeritVal_vec[11] = DLS6_2.getBestMeritValue();

			optmizedSystem_vec[10] = DLS6_1.getOptimizedSystem_HLT();;
			optmizedSystem_vec[11] = DLS6_2.getOptimizedSystem_HLT();;
		}
	#pragma omp section // 7
		{
			// thread 7
			DLS DLS7_1(/*optSysEle*/ optSysEleThread7_1_forDLS, /*angleX*/ mAngleX, /*angleY*/ mAngleY, /*wavelengths*/ mWavelength_vec, /*rings*/ mRings, /*arms*/ mArms, /*target cardinal points*/ mTargetCarPoints, /*default DLS*/ mDefaultPrameterDLS);
			DLS7_1.turnOffImaProc();
			DLS7_1.setFactorGettingBetter(mFactorBetter_1);
			DLS7_1.setFactorGettingWorst(mFactorWorst_1);

			DLS DLS7_2(/*optSysEle*/ optSysEleThread7_2_forDLS, /*angleX*/ mAngleX, /*angleY*/ mAngleY, /*wavelengths*/ mWavelength_vec, /*rings*/ mRings, /*arms*/ mArms, /*target cardinal points*/ mTargetCarPoints, /*default DLS*/ mDefaultPrameterDLS);
			DLS7_2.turnOffImaProc();
			DLS7_2.setFactorGettingBetter(mFactorBetter_2);
			DLS7_2.setFactorGettingWorst(mFactorWorst_2);

			std::cout << "DLS 7_1" << std::endl;
			DLS7_1.optimizeSystem_DLS_multiplicativ_Damping();
			mAllMeritVal_vec[12] = DLS7_1.getBestMeritValue();
			std::cout << "DLS 7_2" << std::endl;
			DLS7_2.optimizeSystem_DLS_multiplicativ_Damping();
			mAllMeritVal_vec[13] = DLS7_2.getBestMeritValue();

			optmizedSystem_vec[12] = DLS7_1.getOptimizedSystem_HLT();
			optmizedSystem_vec[13] = DLS7_2.getOptimizedSystem_HLT();

		}
	#pragma omp section // 8
		{
			// thread 8
			DLS DLS8_1(/*optSysEle*/ optSysEleThread8_1_forDLS, /*angleX*/ mAngleX, /*angleY*/ mAngleY, /*wavelengths*/ mWavelength_vec, /*rings*/ mRings, /*arms*/ mArms, /*target cardinal points*/ mTargetCarPoints, /*default DLS*/ mDefaultPrameterDLS);
			DLS8_1.turnOffImaProc();
			DLS8_1.setFactorGettingBetter(mFactorBetter_1);
			DLS8_1.setFactorGettingWorst(mFactorWorst_1);

			DLS DLS8_2(/*optSysEle*/ optSysEleThread8_2_forDLS, /*angleX*/ mAngleX, /*angleY*/ mAngleY, /*wavelengths*/ mWavelength_vec, /*rings*/ mRings, /*arms*/ mArms, /*target cardinal points*/ mTargetCarPoints, /*default DLS*/ mDefaultPrameterDLS);
			DLS8_2.turnOffImaProc();
			DLS8_2.setFactorGettingBetter(mFactorBetter_2);
			DLS8_2.setFactorGettingWorst(mFactorWorst_2);

			std::cout << "DLS 8_1" << std::endl;
			DLS8_1.optimizeSystem_DLS_multiplicativ_Damping();
			mAllMeritVal_vec[14] = DLS8_1.getBestMeritValue();
			std::cout << "DLS 8_2" << std::endl;
			DLS8_2.optimizeSystem_DLS_multiplicativ_Damping();
			mAllMeritVal_vec[15] = DLS8_2.getBestMeritValue();

			optmizedSystem_vec[14] = DLS8_1.getOptimizedSystem_HLT();;
			optmizedSystem_vec[15] = DLS8_2.getOptimizedSystem_HLT();;

		}
	#pragma omp section // 9
		{

			// thread 9
			DLS DLS9_1(/*optSysEle*/ optSysEleThread9_1_forDLS, /*angleX*/ mAngleX, /*angleY*/ mAngleY, /*wavelengths*/ mWavelength_vec, /*rings*/ mRings, /*arms*/ mArms, /*target cardinal points*/ mTargetCarPoints, /*default DLS*/ mDefaultPrameterDLS);
			DLS9_1.turnOffImaProc();
			DLS9_1.setFactorGettingBetter(mFactorBetter_1);
			DLS9_1.setFactorGettingWorst(mFactorWorst_1);

			DLS DLS9_2(/*optSysEle*/ optSysEleThread9_2_forDLS, /*angleX*/ mAngleX, /*angleY*/ mAngleY, /*wavelengths*/ mWavelength_vec, /*rings*/ mRings, /*arms*/ mArms, /*target cardinal points*/ mTargetCarPoints, /*default DLS*/ mDefaultPrameterDLS);
			DLS9_2.turnOffImaProc();
			DLS9_2.setFactorGettingBetter(mFactorBetter_2);
			DLS9_2.setFactorGettingWorst(mFactorWorst_2);

			std::cout << "DLS 9_1" << std::endl;
			DLS9_1.optimizeSystem_DLS_multiplicativ_Damping();
			mAllMeritVal_vec[16] = DLS9_1.getBestMeritValue();
			std::cout << "DLS 9_2" << std::endl;
			DLS9_2.optimizeSystem_DLS_multiplicativ_Damping();
			mAllMeritVal_vec[17] = DLS9_2.getBestMeritValue();

			optmizedSystem_vec[16] = DLS9_1.getOptimizedSystem_HLT();;
			optmizedSystem_vec[17] = DLS9_2.getOptimizedSystem_HLT();;

		}
	#pragma omp section // 10
		{

			// thread 10
			DLS DLS10_1(/*optSysEle*/ optSysEleThread10_1_forDLS, /*angleX*/ mAngleX, /*angleY*/ mAngleY, /*wavelengths*/ mWavelength_vec, /*rings*/ mRings, /*arms*/ mArms, /*target cardinal points*/ mTargetCarPoints, /*default DLS*/ mDefaultPrameterDLS);
			DLS10_1.turnOffImaProc();
			DLS10_1.setFactorGettingBetter(mFactorBetter_1);
			DLS10_1.setFactorGettingWorst(mFactorWorst_1);

			DLS DLS10_2(/*optSysEle*/ optSysEleThread10_2_forDLS, /*angleX*/ mAngleX, /*angleY*/ mAngleY, /*wavelengths*/ mWavelength_vec, /*rings*/ mRings, /*arms*/ mArms, /*target cardinal points*/ mTargetCarPoints, /*default DLS*/ mDefaultPrameterDLS);
			DLS10_2.turnOffImaProc();
			DLS10_2.setFactorGettingBetter(mFactorBetter_2);
			DLS10_2.setFactorGettingWorst(mFactorWorst_2);

			std::cout << "DLS 10_1" << std::endl;
			DLS10_1.optimizeSystem_DLS_multiplicativ_Damping();
			mAllMeritVal_vec[18] = DLS10_1.getBestMeritValue();
			std::cout << "DLS 10_2" << std::endl;
			DLS10_2.optimizeSystem_DLS_multiplicativ_Damping();
			mAllMeritVal_vec[19] = DLS10_2.getBestMeritValue();

			optmizedSystem_vec[18] = DLS10_1.getOptimizedSystem_HLT();;
			optmizedSystem_vec[19] = DLS10_2.getOptimizedSystem_HLT();;

		}
	#pragma omp section // 11
		{
			// thread 11
			DLS DLS11_1(/*optSysEle*/ optSysEleThread11_1_forDLS, /*angleX*/ mAngleX, /*angleY*/ mAngleY, /*wavelengths*/ mWavelength_vec, /*rings*/ mRings, /*arms*/ mArms, /*target cardinal points*/ mTargetCarPoints, /*default DLS*/ mDefaultPrameterDLS);
			DLS11_1.turnOffImaProc();
			DLS11_1.setFactorGettingBetter(mFactorBetter_1);
			DLS11_1.setFactorGettingWorst(mFactorWorst_1);

			DLS DLS11_2(/*optSysEle*/ optSysEleThread11_2_forDLS, /*angleX*/ mAngleX, /*angleY*/ mAngleY, /*wavelengths*/ mWavelength_vec, /*rings*/ mRings, /*arms*/ mArms, /*target cardinal points*/ mTargetCarPoints, /*default DLS*/ mDefaultPrameterDLS);
			DLS11_2.turnOffImaProc();
			DLS11_2.setFactorGettingBetter(mFactorBetter_2);
			DLS11_2.setFactorGettingWorst(mFactorWorst_2);

			std::cout << "DLS 11_1" << std::endl;
			DLS11_1.optimizeSystem_DLS_multiplicativ_Damping();
			mAllMeritVal_vec[20] = DLS11_1.getBestMeritValue();
			std::cout << "DLS 11_2" << std::endl;
			DLS11_2.optimizeSystem_DLS_multiplicativ_Damping();
			mAllMeritVal_vec[21] = DLS11_2.getBestMeritValue();

			optmizedSystem_vec[20] = DLS11_1.getOptimizedSystem_HLT();;
			optmizedSystem_vec[21] = DLS11_2.getOptimizedSystem_HLT();;

		}


	#pragma omp section // 12
		{

			// thread 12
			DLS DLS12_1(/*optSysEle*/ optSysEleThread12_1_forDLS, /*angleX*/ mAngleX, /*angleY*/ mAngleY, /*wavelengths*/ mWavelength_vec, /*rings*/ mRings, /*arms*/ mArms, /*target cardinal points*/ mTargetCarPoints, /*default DLS*/ mDefaultPrameterDLS);
			DLS12_1.turnOffImaProc();
			DLS12_1.setFactorGettingBetter(mFactorBetter_1);
			DLS12_1.setFactorGettingWorst(mFactorWorst_1);

			DLS DLS12_2(/*optSysEle*/ optSysEleThread12_2_forDLS, /*angleX*/ mAngleX, /*angleY*/ mAngleY, /*wavelengths*/ mWavelength_vec, /*rings*/ mRings, /*arms*/ mArms, /*target cardinal points*/ mTargetCarPoints, /*default DLS*/ mDefaultPrameterDLS);
			DLS12_2.turnOffImaProc();
			DLS12_2.setFactorGettingBetter(mFactorBetter_2);
			DLS12_2.setFactorGettingWorst(mFactorWorst_2);

			std::cout << "DLS 12_1" << std::endl;
			DLS12_1.optimizeSystem_DLS_multiplicativ_Damping();
			mAllMeritVal_vec[22] = DLS12_1.getBestMeritValue();
			std::cout << "DLS 12_2" << std::endl;
			DLS12_2.optimizeSystem_DLS_multiplicativ_Damping();
			mAllMeritVal_vec[23] = DLS12_2.getBestMeritValue();


			optmizedSystem_vec[22] = DLS12_1.getOptimizedSystem_HLT();;
			optmizedSystem_vec[23] = DLS12_2.getOptimizedSystem_HLT();;
		}
	}


	mBestMeritVal = mAllMeritVal_vec[0];
	mOptimizedOpticalSystemElement_firstIteration = optmizedSystem_vec[0];

	for (unsigned int i = 1; i < numberDLS_optimizations; ++i)
	{
		if (mBestMeritVal > mAllMeritVal_vec[i])
		{
			mBestMeritVal = mAllMeritVal_vec[i];
			mOptimizedOpticalSystemElement_firstIteration = optmizedSystem_vec[i];
		}
	}


	mOptimizedOpticalSystemElement_firstIteration.convertHLTSurfacesToLLTSurfaces();


	DLS_multiThreads_12 DLS_mulit_12(mOptimizedOpticalSystemElement_firstIteration, /*angleX*/ mAngleX, /*angleY*/ mAngleY, mWavelength_vec, mRings, mArms, mTargetCarPoints, mDefaultPrameterDLS);


	mOptimizedOpticalSystemElement_secondIteration = DLS_mulit_12.DLS_optimisation_multiThreads_12_inf();


	return mOptimizedOpticalSystemElement_secondIteration;

}

// get optimized optical system
OpticalSystemElement OptimizeSystemSuperFct_GeneticAndDLS::getOptimizedOpticalSystem()
{
	return mOptimizedOpticalSystemElement_secondIteration;
}

// get object point inf or obj
objectPoint_inf_obj OptimizeSystemSuperFct_GeneticAndDLS::getObjPoint_inf_obj()
{
	return mObjPoint_inf_obj;
}

void OptimizeSystemSuperFct_GeneticAndDLS::loadBestFactorBetterFactorWorstCombinations()
{
	factorBetter_vec.push_back(0.2);
	factorWorst_vec.push_back(1.9);

	factorBetter_vec.push_back(0.4);
	factorWorst_vec.push_back(2.1);

	factorBetter_vec.push_back(0.4);
	factorWorst_vec.push_back(1.9);

	factorBetter_vec.push_back(0.8);
	factorWorst_vec.push_back(2.0);

	factorBetter_vec.push_back(0.8);
	factorWorst_vec.push_back(2.3);

	factorBetter_vec.push_back(0.2);
	factorWorst_vec.push_back(2.0);

	factorBetter_vec.push_back(0.6);
	factorWorst_vec.push_back(2.0);

	factorBetter_vec.push_back(0.4);
	factorWorst_vec.push_back(2.3);

	factorBetter_vec.push_back(0.5);
	factorWorst_vec.push_back(1.9);

	factorBetter_vec.push_back(0.5);
	factorWorst_vec.push_back(2.1);

	factorBetter_vec.push_back(0.3);
	factorWorst_vec.push_back(2.1);

	factorBetter_vec.push_back(0.4);
	factorWorst_vec.push_back(1.8);

}

real OptimizeSystemSuperFct_GeneticAndDLS::getBestMeritValue()
{
	return mBestMeritVal;
}