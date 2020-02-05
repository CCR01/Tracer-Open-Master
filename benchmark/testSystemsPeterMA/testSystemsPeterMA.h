#pragma once

#include "..\..\OpticalSystemElement\OpticalSystemElement.h"

// evaluate paraxial ray tracing
#include "..\..\OptimizeSystem\EvaluateManyOptSystems_ParaxialDistances.h"
#include "..\..\OptimizeSystem\EvaluateManyOptSystems_RayTracing.h"

class testSystemsPeterMA
{
public:
	testSystemsPeterMA();
	~testSystemsPeterMA();

	enum testWhatEnum{testAll, testParaxial, testSeidel, testRayTrac};

	bool calcTestSystemPeterMA_superFct();
	bool calcTestSystemPeterMA_E0(testWhatEnum testWhat);
	bool calcTestSystemPeterMA_E1(testWhatEnum testWhat);
	bool calcTestSystemPeterMA_E2(testWhatEnum testWhat);
	bool calcTestSystemPeterMA_E3(testWhatEnum testWhat);
	bool calcTestSystemPeterMA_E4(testWhatEnum testWhat);
	bool calcTestSystemPeterMA_E5(testWhatEnum testWhat);
	bool calcTestSystemPeterMA_E6(testWhatEnum testWhat);
	bool calcTestSystemPeterMA_E7(testWhatEnum testWhat);
	bool calcTestSystemPeterMA_E8(testWhatEnum testWhat);
	bool calcTestSystemPeterMA_E9(testWhatEnum testWhat);


	
	void saveSystemData_bestOptSys_paraxial(unsigned int optSysNum, real timeGetBestOptSys, OpticalSystemElement& optSystemElement, OpticalSystem_LLT& bestOptSys_LLT, unsigned int numberEvaSys, real primWave, const std::vector<VectorStructR3>& fields, const std::vector<Light_LLT>& light_vec, const std::vector<real>& rmsZemax, const std::vector<real>& Var_vec_Zemax, const std::vector<stepsWithoutMinWithoutMax>& addInfos, const std::vector< parameterTypeModeStruct>& parameterTypeMode, std::string location, std::string nameExcel);
	void saveSystemData_bestOptSys_seidel(unsigned int optSysNum, real duration_N_bestOptSys_min, real duration_N_bestOptSys_convertEle_min, real duration_N_bestOptSys_seidel_min, OpticalSystemElement optSystemElement, OpticalSystem_LLT bestoptSys_LLT_seidel, EvaluateManyOptSystems_ParaxialDistances EvManOptSys_ParaDis_bestSys, real primWave, std::vector<VectorStructR3> fields, std::vector<Light_LLT> light_vec, std::vector<real> rmsZemax, std::vector<real> Var_vec_Zemax, std::vector<stepsWithoutMinWithoutMax> addInfos, std::vector< parameterTypeModeStruct> parameterTypeMode, std::string location, std::string nameExcel);
	void saveSystemData_bestOptSys_RayTracing(unsigned int optSysNum, real timeGetBestOptSys, OpticalSystemElement optSystemElement, OpticalSystem_LLT bestOptSys_LLT, EvaluateManyOptSys_RayTracing EvManOptSys_rayTracing, real primWave, std::vector<VectorStructR3> fields, std::vector<Light_LLT> light_vec, std::vector<real> rmsZemax, std::vector<real> Var_vec_Zemax, std::vector<stepsWithoutMinWithoutMax> addInfos, std::vector< parameterTypeModeStruct> parameterTypeMode, std::string location, std::string nameExcel);

private:

};


