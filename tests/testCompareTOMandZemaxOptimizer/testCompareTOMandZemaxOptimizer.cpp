#include "testCompareTOMandZemaxOptimizer.h"

// often use
#include "..\..\oftenUseNamespace\oftenUseNamespace.h"

// inport export
#include "..\..\Inport_Export_Data\Inport_Export_Data.h"

// element surfaces
#include "..\..\SurfaceElements\ApertureStopElement.h"
#include "..\..\SurfaceElements\SphericalElement.h"
#include "..\..\SurfaceElements\PlanElement.h"

// DLS 12
#include "..\..\OptimizeSystem\multiThreads\DLS_mulitThreads12.h"

// Genetic and DLS 12
#include "..\..\OptimizeSystem\OptimizeSystemSuperFct_GeneticAndDLS.h"

testCompareTOMandZemaxOptimizer::testCompareTOMandZemaxOptimizer()
{
	loadImportantValues();
	turn_OFF_debugMode();
}
testCompareTOMandZemaxOptimizer::~testCompareTOMandZemaxOptimizer() {}

typedef std::shared_ptr< Element_CR > surfacePtr;
typedef std::shared_ptr< InteractionRay_LLT > interaction_ptr;

saveResultsOptimizationMethodes::saveResultsOptimizationMethodes() {};
saveResultsOptimizationMethodes::~saveResultsOptimizationMethodes() {};

// Zemax
void saveResultsOptimizationMethodes::setRMSvec_Zemax(std::vector<real> RMS_Zemax)
{
	mRMSvec_Zemax = RMS_Zemax;
}
std::vector<real> saveResultsOptimizationMethodes::getRMSvec_Zemax()
{
	return mRMSvec_Zemax;
}
real saveResultsOptimizationMethodes::getRMSsum_Zemax()
{
	return mRMS_Zemax_sum;
}
// DLS
void saveResultsOptimizationMethodes::setRMSvec_DLS(std::vector<real> RMS_DLS)
{
	mRMSvec_DLS = RMS_DLS;
}
std::vector<real> saveResultsOptimizationMethodes::getRMSvec_DLS()
{
	return mRMSvec_DLS;
}
real saveResultsOptimizationMethodes::getRMSsum_DLS()
{
	return mRMS_DLS_sum;;
}
void saveResultsOptimizationMethodes::setOptimizedSystem_DLS(OpticalSystemElement optimizedSystemDLS)
{
	mOptimizedOptSys_DLS = optimizedSystemDLS;
}
OpticalSystemElement saveResultsOptimizationMethodes::getOptimizedSystem_DLS()
{
	return mOptimizedOptSys_DLS;
}
// DLS 12
void saveResultsOptimizationMethodes::setRMSvec_DLS_12(std::vector<real> RMS_DLS_12)
{
	mRMSvec_DLS_12 = RMS_DLS_12;
}
std::vector<real> saveResultsOptimizationMethodes::getRMSvec_DLS_12()
{
	return mRMSvec_DLS_12;
}
real saveResultsOptimizationMethodes::getRMSsum_DLS_12()
{
	return mRMS_DLS_12_sum;;
}
void saveResultsOptimizationMethodes::setOptimizedSystem_DLS_12(OpticalSystemElement optimizedSystemDLS_12)
{
	mOptimizedOptSys_DLS_12 = optimizedSystemDLS_12;
}
OpticalSystemElement saveResultsOptimizationMethodes::getOptimizedSystem_DLS_12()
{
	return mOptimizedOptSys_DLS_12;
}
// Genetic and DLS
void saveResultsOptimizationMethodes::setRMSvec_GeneticAndDLS(std::vector<real> RMS_GeneticAndDLS)
{
	mRMSvec_GeneticAndDLS = RMS_GeneticAndDLS;
}
std::vector<real> saveResultsOptimizationMethodes::getRMSvec_GeneticAndDLS()
{
	return mRMSvec_GeneticAndDLS;
}
real saveResultsOptimizationMethodes::getRMSsum_GeneticAndDLS()
{
	return mRMS_GeneticAndDLS_sum;
}
void saveResultsOptimizationMethodes::setOptimizedSystem_GeneticAndDLS(OpticalSystemElement optimizedSystemGeneticAndDLS)
{
	mOptimizedOptSys_GeneticAndDLS = optimizedSystemGeneticAndDLS;
}
OpticalSystemElement saveResultsOptimizationMethodes::getOptimizedSystem_GeneticAndDLS()
{
	return mOptimizedOptSys_GeneticAndDLS;
}
// Genetic and DLS 12
void saveResultsOptimizationMethodes::setRMSvec_GeneticAndDLS_12(std::vector<real> RMS_GeneticAndDLS_12)
{
	mRMSvec_GeneticAndDLS_12 = RMS_GeneticAndDLS_12;
}
std::vector<real> saveResultsOptimizationMethodes::getRMSvec_GeneticAndDLS_12()
{
	return mRMSvec_GeneticAndDLS_12;
}
real saveResultsOptimizationMethodes::getRMSsum_GeneticAndDLS_12()
{
	return mRMS_GeneticAndDLS_12_sum;
}
void saveResultsOptimizationMethodes::setOptimizedSystem_GeneticAndDLS_12(OpticalSystemElement optimizedSystemGeneticAndDLS_12)
{
	mOptimizedOptSys_GeneticAndDLS_12 = optimizedSystemGeneticAndDLS_12;
}
OpticalSystemElement saveResultsOptimizationMethodes::getOptimizedSystem_GeneticAndDLS_12()
{
	return mOptimizedOptSys_GeneticAndDLS_12;
}
void saveResultsOptimizationMethodes::calcAllSums()
{
	mRMS_Zemax_sum = Math::sumAllVectorValues(mRMSvec_Zemax);
	mRMS_DLS_sum = Math::sumAllVectorValues(mRMSvec_DLS);
	mRMS_DLS_12_sum = Math::sumAllVectorValues(mRMSvec_DLS_12);
	mRMS_GeneticAndDLS_sum = Math::sumAllVectorValues(mRMSvec_GeneticAndDLS);
	mRMS_GeneticAndDLS_12_sum = Math::sumAllVectorValues(mRMSvec_GeneticAndDLS_12);
}


void testCompareTOMandZemaxOptimizer::loadImportantValues()
{
	// load glass catalog
	mGlasses.loadGlassCatalog_Schott();

	// light FdC
	mWave587d = 587.5618;
	mWave486F = 486.1327;
	mWave656C = 656.2725;
	mWavelength_FdV_vec.push_back(mWave587d);
	mWavelength_FdV_vec.push_back(mWave486F);
	mWavelength_FdV_vec.push_back(mWave656C);

	mLight587 = oftenUse::getDefaultLight();
	mLight587.setWavelength(mWave587d);
	mLight486 = oftenUse::getDefaultLight();
	mLight486.setWavelength(mWave486F);
	mLight656 = oftenUse::getDefaultLight();
	mLight656.setWavelength(mWave656C);

	mLight_FdC_Vec.push_back(mLight587);
	mLight_FdC_Vec.push_back(mLight486);
	mLight_FdC_Vec.push_back(mLight656);


	// field obj
	mField0 = { 0.0,0.0,0.0 };
	mField283 = { 0.0,2.83, 0.0 };
	mField4 = { 0.0,4.0,0.0 };
	mField_vec.push_back(mField0);
	mField_vec.push_back(mField283);
	mField_vec.push_back(mField4);

	mTolerance = 0.1;
	mRings = 20;
	mArms = 20;

	mDefaulParaDLS = oftenUse::getDefaultPara_DLS(true);
	mDefaultParameterGenetic = oftenUse::getDafulatPara_Genetic(true);
	mPopulation = 1000.0;


}

// try all optimization methodes
saveResultsOptimizationMethodes testCompareTOMandZemaxOptimizer::tryAllOptimizationMethodes(OpticalSystemElement optSysEle, std::vector<real> rmsZ)
{

	if (mDebugMode)
	{
		mDefaulParaDLS.setMaxInterations(1);
		mDefaultParameterGenetic.setMaxInterationGenetic(1);
		mPopulation = 5;
	}

	OpticalSystemElement optSysEle_DLS = optSysEle.getDeepCopyOptSysEle();
	OpticalSystemElement optSysEle_DLS_12 = optSysEle.getDeepCopyOptSysEle();
	OpticalSystemElement optSysEle_GeneticAndDLS = optSysEle.getDeepCopyOptSysEle();
	OpticalSystemElement optSysEle_GeneticAndDLS_12 = optSysEle.getDeepCopyOptSysEle();

	saveResultsOptimizationMethodes saveResults;

	// RMS Zemax
	saveResults.setRMSvec_Zemax(rmsZ);

	// DLS opt
	DLS DLS_opti;
	DLS_opti.turnOFF_imageProcessing();
	DLS_opti.DLS_superFctDLS(optSysEle_DLS, mField_vec, mWavelength_FdV_vec, mRings, mArms, mDefaulParaDLS);
	OpticalSystemElement optimizedSystem_DLS = DLS_opti.getOptimizedSystem_HLT();
	std::vector<real> rmsVecDLS = oftenUse::getRMSoptSysHLT(optimizedSystem_DLS, mField_vec, mWavelength_FdV_vec, mRings, mArms);
	saveResults.setRMSvec_DLS(rmsVecDLS);
	saveResults.setOptimizedSystem_DLS(optimizedSystem_DLS);

	// DLS opt 12
	DLS_multiThreads_12 DLS_opt_12(optSysEle_DLS_12, mField_vec, mWavelength_FdV_vec, mRings, mArms, mDefaulParaDLS);
	OpticalSystemElement optimizedSystem_DLS_12 = DLS_opt_12.DLS_optimisation_multiThreads_12_obj();
	std::vector<real> rmsVecDLS_12 = oftenUse::getRMSoptSysHLT(optimizedSystem_DLS_12, mField_vec, mWavelength_FdV_vec, mRings, mArms);
	saveResults.setRMSvec_DLS_12(rmsVecDLS_12);
	saveResults.setOptimizedSystem_DLS_12(optimizedSystem_DLS_12);

	// Genetic and DLS
	OptimizeSystemSuperFct_GeneticAndDLS GeneticAndDLS(/*optSysEle*/ optSysEle_GeneticAndDLS,/*fields*/ mField_vec, /*wavelength*/ mWavelength_FdV_vec, /*rings*/ mRings, /*arms*/ mArms, /*populatuion*/ mPopulation, /*default Genetic*/ mDefaultParameterGenetic, /*default DLS*/ mDefaulParaDLS);
	OpticalSystemElement optimizedSystem_GeneticAndDLS = GeneticAndDLS.optimizeSuperFct_GeneticAndDLS();
	std::vector<real> rmsVecGeneticDLS = oftenUse::getRMSoptSysHLT(optimizedSystem_GeneticAndDLS, mField_vec, mWavelength_FdV_vec, mRings, mArms);
	saveResults.setRMSvec_GeneticAndDLS(rmsVecGeneticDLS);
	saveResults.setOptimizedSystem_GeneticAndDLS(optimizedSystem_GeneticAndDLS);

	// Genetic and DLS 12
	OptimizeSystemSuperFct_GeneticAndDLS GeneticAndDLS_12(/*optSysEle*/ optSysEle_GeneticAndDLS_12,/*fields*/ mField_vec, /*wavelength*/ mWavelength_FdV_vec, /*rings*/ mRings, /*arms*/ mArms, /*populatuion*/ mPopulation, /*default Genetic*/ mDefaultParameterGenetic, /*default DLS*/ mDefaulParaDLS);
	OpticalSystemElement optimizedSystem_GeneticAndDLS_12 = GeneticAndDLS_12.optimizeSuperFct_GeneticAndDLS_12Cores();
	std::vector<real> rmsVecGeneticDLS_12 = oftenUse::getRMSoptSysHLT(optimizedSystem_GeneticAndDLS_12, mField_vec, mWavelength_FdV_vec, mRings, mArms);
	saveResults.setRMSvec_GeneticAndDLS_12(rmsVecGeneticDLS_12);
	saveResults.setOptimizedSystem_GeneticAndDLS_12(optimizedSystem_GeneticAndDLS_12);

	// calc all sums
	saveResults.calcAllSums();

	return saveResults;

}

// export all results
void testCompareTOMandZemaxOptimizer::exportResults(std::string location, std::string name, std::string example, unsigned int posInVec)
{

	std::string NameDataToExport = "field0_RMS_Z, field1_RMS_Z, field2_RMS_Z, rmsZ_RMS_sum, field0_RMS_DLS, field1_RMS_DLS, field2_RMS_DLS, rmsDLS_RMS_sum, field0_RMS_DLS_12, field1_RMS_DLS_12, field2_RMS_DLS_12, rmsDLS_12_RMS_sum, field0_RMS_DLSandGenetic, field1_RMS_DLSandGenetic, field2_RMSandGenetic_DLS, rmsDLSandGenetic_sum, field0_RMS_DLSandGenetic_12, field1_RMS_DLSandGenetic_12, field2_RMSandGenetic_DLS_12, rmsDLSandGenetic_12_sum";
	std::vector<real> dataToExport;
	unsigned int sizeDataToExport = 20;
	dataToExport.resize(sizeDataToExport);

	// Zemax data
	dataToExport[0] = mSaveAllResults[posInVec].getRMSvec_Zemax()[0];
	dataToExport[1] = mSaveAllResults[posInVec].getRMSvec_Zemax()[1];
	dataToExport[2] = mSaveAllResults[posInVec].getRMSvec_Zemax()[2];
	dataToExport[3] = mSaveAllResults[posInVec].getRMSsum_Zemax();
	// DLS							  
	dataToExport[4] = mSaveAllResults[posInVec].getRMSvec_DLS()[0];
	dataToExport[5] = mSaveAllResults[posInVec].getRMSvec_DLS()[1];
	dataToExport[6] = mSaveAllResults[posInVec].getRMSvec_DLS()[2];
	dataToExport[7] = mSaveAllResults[posInVec].getRMSsum_DLS();
	// DLS 12						  
	dataToExport[8] = mSaveAllResults[posInVec].getRMSvec_DLS_12()[0];
	dataToExport[9] = mSaveAllResults[posInVec].getRMSvec_DLS_12()[1];
	dataToExport[10] = mSaveAllResults[posInVec].getRMSvec_DLS_12()[2];
	dataToExport[11] = mSaveAllResults[posInVec].getRMSsum_DLS_12();
	// Genetic and DLS
	dataToExport[12] = mSaveAllResults[posInVec].getRMSvec_GeneticAndDLS()[0];
	dataToExport[13] = mSaveAllResults[posInVec].getRMSvec_GeneticAndDLS()[1];
	dataToExport[14] = mSaveAllResults[posInVec].getRMSvec_GeneticAndDLS()[2];
	dataToExport[15] = mSaveAllResults[posInVec].getRMSsum_GeneticAndDLS();
	// Genetic and DLS 12
	dataToExport[16] = mSaveAllResults[posInVec].getRMSvec_GeneticAndDLS_12()[0];
	dataToExport[17] = mSaveAllResults[posInVec].getRMSvec_GeneticAndDLS_12()[1];
	dataToExport[18] = mSaveAllResults[posInVec].getRMSvec_GeneticAndDLS_12()[2];
	dataToExport[19] = mSaveAllResults[posInVec].getRMSsum_GeneticAndDLS_12();

	std::vector<real> vec = { 0.0 };
	inportExportData::exportDataToExcel_vector(location, name, example, vec);
	inportExportData::exportDataToExcel_vector(location, name, NameDataToExport, dataToExport);

}

void testCompareTOMandZemaxOptimizer::exportAllOpticalSystems(std::string location, saveResultsOptimizationMethodes saveResOptimizationMethodes)
{
	real wavelength = 550.0;

	// optimization DLS
	OpticalSystemElement optiDLS = saveResOptimizationMethodes.getOptimizedSystem_DLS();
	inportExportData::saveOpticalSystemAsTXT(optiDLS, wavelength, location, "optiDLS");

	// optimization DLS 12
	OpticalSystemElement optiDLS_12 = saveResOptimizationMethodes.getOptimizedSystem_DLS_12();
	inportExportData::saveOpticalSystemAsTXT(optiDLS_12, wavelength, location, "optiDLS_12");

	// optimization Geentic and DLS
	OpticalSystemElement optiGeneticAndDLS = saveResOptimizationMethodes.getOptimizedSystem_GeneticAndDLS();
	inportExportData::saveOpticalSystemAsTXT(optiGeneticAndDLS, wavelength, location, "optiGeneticAndDLS");

	// optimization Genetic and DLS 12
	OpticalSystemElement optiGeneticAndDLS_12 = saveResOptimizationMethodes.getOptimizedSystem_GeneticAndDLS_12();
	inportExportData::saveOpticalSystemAsTXT(optiGeneticAndDLS_12, wavelength, location, "optiGeneticAndDLS_12");

}

// debug mode
void testCompareTOMandZemaxOptimizer::turn_ON_debugMode()
{
	mDebugMode = true;
}
void testCompareTOMandZemaxOptimizer::turn_OFF_debugMode()
{
	mDebugMode = false;
}

// super function
bool testCompareTOMandZemaxOptimizer::testCompareTOMandZemaxOptimizer_superFct()
{
	std::vector<bool> workTheSystem;

	// debug mode
	// ***
	// turn_ON_debugMode();
	// ***

	std::string location = "../tests/testCompareTOMandZemaxOptimizer";
	std::string nameWorkCompareTOMandZemax = "testCompareTOMandZemaxOptimizer";
	std::string nameSaveData = "compareOptimisationMethodes";

	unsigned int tempPosInVec = 0;

	// clear data
	inportExportData::clearDataInTXT(location, nameWorkCompareTOMandZemax);
	inportExportData::removeDateCSV(location, nameSaveData);


	//// E0 
	//bool checkE0 = testCompareTOMandZemaxOptimizer_E0();
	//workTheSystem.push_back(checkE0);
	//if (checkE0) { inportExportData::saveStringInTXT_includingTime(location, nameWorkCompareTOMandZemax, "E0 worked"); };
	//exportResults(location, nameSaveData, "E0", tempPosInVec);
	//++tempPosInVec;

	//// E1
	//bool checkE1 = testCompareTOMandZemaxOptimizer_E1();
	//workTheSystem.push_back(checkE1);
	//if (checkE1) { inportExportData::saveStringInTXT_includingTime(location, nameWorkCompareTOMandZemax, "E1 worked"); };
	//exportResults(location, nameSaveData, "E1", tempPosInVec);
	//++tempPosInVec;
	//
	//// E2
	//bool checkE2 = testCompareTOMandZemaxOptimizer_E2();
	//workTheSystem.push_back(checkE2);
	//if (checkE2) { inportExportData::saveStringInTXT_includingTime(location, nameWorkCompareTOMandZemax, "E2 worked"); };
	//exportResults(location, nameSaveData, "E2", tempPosInVec);
	//++tempPosInVec;
	//
	//// E3
	//bool checkE3 = testCompareTOMandZemaxOptimizer_E3();
	//workTheSystem.push_back(checkE3);
	//if (checkE3) { inportExportData::saveStringInTXT_includingTime(location, nameWorkCompareTOMandZemax, "E3 worked"); };
	//exportResults(location, nameSaveData, "E3", tempPosInVec);
	//++tempPosInVec;
	//
	//// E4
	//bool checkE4 = testCompareTOMandZemaxOptimizer_E4();
	//workTheSystem.push_back(checkE4);
	//if (checkE4) { inportExportData::saveStringInTXT_includingTime(location, nameWorkCompareTOMandZemax, "E4 worked"); };
	//exportResults(location, nameSaveData, "E4", tempPosInVec);
	//++tempPosInVec;
	//
	//// E5
	//bool checkE5 = testCompareTOMandZemaxOptimizer_E5();
	//workTheSystem.push_back(checkE5);
	//if (checkE5) { inportExportData::saveStringInTXT_includingTime(location, nameWorkCompareTOMandZemax, "E5 worked"); };
	//exportResults(location, nameSaveData, "E5", tempPosInVec);
	//++tempPosInVec;
	//
	// E6
	bool checkE6 = testCompareTOMandZemaxOptimizer_E6();
	workTheSystem.push_back(checkE6);
	if (checkE6) { inportExportData::saveStringInTXT_includingTime(location, nameWorkCompareTOMandZemax, "E6 worked"); };
	exportResults(location, nameSaveData, "E6", tempPosInVec);
	++tempPosInVec;
	//
	//// E7
	//bool checkE7 = testCompareTOMandZemaxOptimizer_E7();
	//workTheSystem.push_back(checkE7);
	//if (checkE7) { inportExportData::saveStringInTXT_includingTime(location, nameWorkCompareTOMandZemax, "E7 worked"); };
	//exportResults(location, nameSaveData, "E7", tempPosInVec);
	//++tempPosInVec;
	//
	//// E8
	//bool checkE8 = testCompareTOMandZemaxOptimizer_E8();
	//workTheSystem.push_back(checkE8);
	//if (checkE8) { inportExportData::saveStringInTXT_includingTime(location, nameWorkCompareTOMandZemax, "E8 worked"); };
	//exportResults(location, nameSaveData, "E8", tempPosInVec);
	//++tempPosInVec;
	//
	//// E9
	//bool checkE9 = testCompareTOMandZemaxOptimizer_E9();
	//workTheSystem.push_back(checkE9);
	//if (checkE9) { inportExportData::saveStringInTXT_includingTime(location, nameWorkCompareTOMandZemax, "E9 worked"); };
	//exportResults(location, nameSaveData, "E9", tempPosInVec);
	//++tempPosInVec;
	//
	//// E10
	//bool checkE10 = testCompareTOMandZemaxOptimizer_E10();
	//workTheSystem.push_back(checkE10);
	//if (checkE10) { inportExportData::saveStringInTXT_includingTime(location, nameWorkCompareTOMandZemax, "E10 worked"); };
	//exportResults(location, nameSaveData, "E10", tempPosInVec);
	//++tempPosInVec;
	//
	//// E11
	//bool checkE11 = testCompareTOMandZemaxOptimizer_E11();
	//workTheSystem.push_back(checkE11);
	//if (checkE11) { inportExportData::saveStringInTXT_includingTime(location, nameWorkCompareTOMandZemax, "E11 worked"); };
	//exportResults(location, nameSaveData, "E11", tempPosInVec);
	//++tempPosInVec;
	//
	//// E12
	//bool checkE12 = testCompareTOMandZemaxOptimizer_E12();
	//workTheSystem.push_back(checkE12);
	//if (checkE12) { inportExportData::saveStringInTXT_includingTime(location, nameWorkCompareTOMandZemax, "E12 worked"); };
	//exportResults(location, nameSaveData, "E12", tempPosInVec);
	//++tempPosInVec;
	//
	//// E13
	//bool checkE13 = testCompareTOMandZemaxOptimizer_E13();
	//workTheSystem.push_back(checkE13);
	//if (checkE13) { inportExportData::saveStringInTXT_includingTime(location, nameWorkCompareTOMandZemax, "E13 worked"); };
	//exportResults(location, nameSaveData, "E13", tempPosInVec);
	//++tempPosInVec;

	//// E14
	//bool checkE14 = testCompareTOMandZemaxOptimizer_E14();
	//workTheSystem.push_back(checkE14);
	//if (checkE14) { inportExportData::saveStringInTXT_includingTime(location, nameWorkCompareTOMandZemax, "E14 worked"); };
	//exportResults(location, nameSaveData, "E14", tempPosInVec);
	//++tempPosInVec;

	bool returnChecker = Math::checkTrueOfVectorElements(workTheSystem);
	return returnChecker;
}




// E0
bool testCompareTOMandZemaxOptimizer::testCompareTOMandZemaxOptimizer_E0()
{
	std::vector<bool> workTheSystem;

	ApertureStopElement S0(/* semi height*/1.0, /*point*/{ 0.0,0.0,15.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ mGlasses.getAir());
	SphericalElement S1(/*radius*/ 30.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,20.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF66_S1());
	SphericalElement S2(/*radius*/ 60.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,25.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getNSF66_S1(), /*refractive index B*/mGlasses.getNLAF2_S1());
	SphericalElement S3(/*radius*/ 15.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNLAF2_S1());
	SphericalElement S4(/*radius*/ 40.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,35.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBAF10_S1());
	SphericalElement S5(/*radius*/ 15.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,40.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNSF57_S1(), /*refractive index B*/mGlasses.getNBAF10_S1());
	SphericalElement S6(/*radius*/ 40.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,45.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF57_S1());
	SphericalElement S7(/*radius*/ 30.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,50.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S8(/*radius*/ 100.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,55.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getNBK7_S1(), /*refractive index B*/mGlasses.getNSF5_S1());
	SphericalElement S9(/*radius*/ 20.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,60.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getNSF5_S1(), /*refractive index B*/mGlasses.getAir());
	PlanElement S10(/*semi height*/ 7.0, /*point*/{ 0.0,0.0,65.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getNBK7_S1());
	SphericalElement S11(/*radius*/ 50.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,70.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S12(/*radius*/ 50.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,75.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getSF5_S1());
	PlanElement S13(/*semi height*/ 7.0, /*point*/{ 0.0,0.0,80.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getSF5_S1(), /*refractive index B*/ mGlasses.getAir());
	PlanElement S14(/*semi height*/ 99.0, /*point*/{ 0.0,0.0,85.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getAir());

	// **********************************
	// set parameter variable
	S1.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S5.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S6.setParameterPointZ(/*min value*/ 1.0, /*max value*/ 20.0, 0.0, typeModifierVariable);
	// **********************************

	surfacePtr S0_ptr = S0.clone();
	surfacePtr S1_ptr = S1.clone();
	surfacePtr S2_ptr = S2.clone();
	surfacePtr S3_ptr = S3.clone();
	surfacePtr S4_ptr = S4.clone();
	surfacePtr S5_ptr = S5.clone();
	surfacePtr S6_ptr = S6.clone();
	surfacePtr S7_ptr = S7.clone();
	surfacePtr S8_ptr = S8.clone();
	surfacePtr S9_ptr = S9.clone();
	surfacePtr S10_ptr = S10.clone();
	surfacePtr S11_ptr = S11.clone();
	surfacePtr S12_ptr = S12.clone();
	surfacePtr S13_ptr = S13.clone();
	surfacePtr S14_ptr = S14.clone();

	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr, S2_ptr, S3_ptr, S4_ptr,S5_ptr,S6_ptr, S7_ptr, S8_ptr, S9_ptr, S10_ptr, S11_ptr, S12_ptr, S13_ptr, S14_ptr };
	std::vector<interaction_ptr> interactions_ptr{ mDoNot.clone(),mRefrac.clone(),mRefrac.clone(),mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(),mRefrac.clone(),mRefrac.clone(),mRefrac.clone(), mAbsorb.clone() };


	//	build optical system
	OpticalSystemElement optSystemElement(opticalSystem_ptr, interactions_ptr);
	oftenUse::print(optSystemElement, 550.0);
	// save the start system
	std::string location = "../tests/testCompareTOMandZemaxOptimizer/E0";
	inportExportData::saveOpticalSystemAsTXT(optSystemElement, 550.0, location, "start_E0");


	// check the start system
	std::vector<real> rms_Zemax{ 1144.70, 1208.36, 1269.70 };
	bool test = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, mField_vec, mWavelength_FdV_vec, rms_Zemax, mTolerance, compareTOM_Zemax::comEqual);
	workTheSystem.push_back(test);


	//** results optimize Zemax
	real field0_RMS_Z = 14.788;
	real field1_RMS_Z = 12.835;
	real field2_RMS_Z = 24.726;
	std::vector<real> rmsZ = { field0_RMS_Z, field1_RMS_Z,field2_RMS_Z };

	// try all optimization methodes
	saveResultsOptimizationMethodes saveResultsE0 = tryAllOptimizationMethodes(optSystemElement, rmsZ);
	mSaveAllResults.push_back(saveResultsE0);

	// save optimized optical system
	exportAllOpticalSystems(location, saveResultsE0);

	bool returnChecker = Math::checkTrueOfVectorElements(workTheSystem);
	return returnChecker;
}

// E1
bool testCompareTOMandZemaxOptimizer::testCompareTOMandZemaxOptimizer_E1()
{
	std::vector<bool> workTheSystem;
	real semiHeight = 5.0;

	ApertureStopElement S0(/* semi height*/0.3, /*point*/{ 0.0,0.0,15.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ mGlasses.getAir());
	SphericalElement S1(/*radius*/ 30.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,20.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF66_S1());
	SphericalElement S2(/*radius*/ 50.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,25.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF66_S1());
	SphericalElement S3(/*radius*/ 15.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBAF10_S1());
	SphericalElement S4(/*radius*/ 40.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,35.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNSF57_S1(), /*refractive index B*/mGlasses.getNBAF10_S1());
	SphericalElement S5(/*radius*/ 40.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,40.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF57_S1());
	SphericalElement S6(/*radius*/ 20.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,45.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S7(/*radius*/ 100.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,50.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getNBK7_S1(), /*refractive index B*/mGlasses.getNSF5_S1());
	SphericalElement S8(/*radius*/ 60.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,55.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF5_S1());
	PlanElement S9(/*semi height*/ semiHeight, /*point*/{ 0.0,0.0,60.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getNBK7_S1());
	SphericalElement S10(/*radius*/ 50.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,65.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S11(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,70.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNSF5_S1(), /*refractive index B*/mGlasses.getAir());
	PlanElement S12(/*semi height*/ semiHeight, /*point*/{ 0.0,0.0,75.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getNSF5_S1(), /*refractive index B*/ mGlasses.getAir());
	SphericalElement S13(/*radius*/ 30.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,80.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBAF10_S1());
	SphericalElement S14(/*radius*/ 50.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,85.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNBK7_S1(), /*refractive index B*/mGlasses.getNBAF10_S1());
	SphericalElement S15(/*radius*/ 20.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,90.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S16(/*radius*/ 30.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,95.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getF2G12_S1());
	SphericalElement S17(/*radius*/ 30.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,100.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getF2G12_S1());
	PlanElement S18(/*semi height*/ 99.0, /*point*/{ 0.0,0.0,120.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getAir());

	// **********************************
	// set parameter variable
	S4.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S6.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S8.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S11.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S15.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	// **********************************

	surfacePtr S0_ptr = S0.clone();
	surfacePtr S1_ptr = S1.clone();
	surfacePtr S2_ptr = S2.clone();
	surfacePtr S3_ptr = S3.clone();
	surfacePtr S4_ptr = S4.clone();
	surfacePtr S5_ptr = S5.clone();
	surfacePtr S6_ptr = S6.clone();
	surfacePtr S7_ptr = S7.clone();
	surfacePtr S8_ptr = S8.clone();
	surfacePtr S9_ptr = S9.clone();
	surfacePtr S10_ptr = S10.clone();
	surfacePtr S11_ptr = S11.clone();
	surfacePtr S12_ptr = S12.clone();
	surfacePtr S13_ptr = S13.clone();
	surfacePtr S14_ptr = S14.clone();
	surfacePtr S15_ptr = S15.clone();
	surfacePtr S16_ptr = S16.clone();
	surfacePtr S17_ptr = S17.clone();
	surfacePtr S18_ptr = S18.clone();

	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr, S2_ptr, S3_ptr, S4_ptr,S5_ptr,S6_ptr, S7_ptr, S8_ptr, S9_ptr, S10_ptr, S11_ptr, S12_ptr, S13_ptr, S14_ptr,S15_ptr,S16_ptr,S17_ptr,S18_ptr };
	std::vector<interaction_ptr> interactions_ptr{ mDoNot.clone(),mRefrac.clone(),mRefrac.clone(),mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(),mRefrac.clone(),mRefrac.clone(),mRefrac.clone(),mRefrac.clone(),mRefrac.clone(),mRefrac.clone(),mRefrac.clone(), mAbsorb.clone() };


	//	build optical system
	OpticalSystemElement optSystemElement(opticalSystem_ptr, interactions_ptr);
	oftenUse::print(optSystemElement, 550.0);
	// save the start system
	std::string location = "../tests/testCompareTOMandZemaxOptimizer/E1";
	inportExportData::saveOpticalSystemAsTXT(optSystemElement, 550.0, location, "start_E1");

	// check ref indexes
	bool checkRefIndexes = oftenUse::checkRefractivIndex(optSystemElement);
	workTheSystem.push_back(checkRefIndexes);
	// check the start system
	std::vector<real> rms_Zemax{ 14.006, 48.261, 75.655 };
	bool test = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, mField_vec, mWavelength_FdV_vec, rms_Zemax, mTolerance, compareTOM_Zemax::comEqual);
	workTheSystem.push_back(test);


	//** results optimize Zemax
	real field0_RMS_Z = 16.453;
	real field1_RMS_Z = 14.317;
	real field2_RMS_Z = 16.980;
	std::vector<real> rmsZ = { field0_RMS_Z, field1_RMS_Z,field2_RMS_Z };

	// try all optimization methodes
	saveResultsOptimizationMethodes saveResultsE1 = tryAllOptimizationMethodes(optSystemElement, rmsZ);
	mSaveAllResults.push_back(saveResultsE1);

	// save optimized optical system
	exportAllOpticalSystems(location, saveResultsE1);


	bool returnChecker = Math::checkTrueOfVectorElements(workTheSystem);
	return returnChecker;
}

// E2
bool testCompareTOMandZemaxOptimizer::testCompareTOMandZemaxOptimizer_E2()
{
	std::vector<bool> workTheSystem;

	ApertureStopElement S0(/* semi height*/1.0, /*point*/{ 0.0,0.0,15.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ mGlasses.getAir());
	SphericalElement S1(/*radius*/ 30.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,20.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF66_S1());
	SphericalElement S2(/*radius*/ 60.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,25.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getNSF66_S1(), /*refractive index B*/mGlasses.getNLAF2_S1());
	SphericalElement S3(/*radius*/ 50.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNLAF2_S1());
	SphericalElement S4(/*radius*/ 40.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,35.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBAF10_S1());
	SphericalElement S5(/*radius*/ 40.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,40.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNSF57_S1(), /*refractive index B*/mGlasses.getNBAF10_S1());
	SphericalElement S6(/*radius*/ 40.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,45.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF57_S1());
	SphericalElement S7(/*radius*/ 100.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,50.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S8(/*radius*/ 50.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,55.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getNBK7_S1(), /*refractive index B*/mGlasses.getNSF5_S1());
	SphericalElement S9(/*radius*/ 50.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,60.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF5_S1());
	PlanElement S10(/*semi height*/ 7.0, /*point*/{ 0.0,0.0,65.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getNBK7_S1());
	SphericalElement S11(/*radius*/ 500.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,70.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S12(/*radius*/ 500.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,75.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF5_S1());
	PlanElement S13(/*semi height*/ 7.0, /*point*/{ 0.0,0.0,80.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getNSF5_S1(), /*refractive index B*/ mGlasses.getAir());
	PlanElement S14(/*semi height*/ 99.0, /*point*/{ 0.0,0.0,85.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getAir());

	// **********************************
	// set parameter variable
	S1.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S5.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S9.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	// **********************************

	surfacePtr S0_ptr = S0.clone();
	surfacePtr S1_ptr = S1.clone();
	surfacePtr S2_ptr = S2.clone();
	surfacePtr S3_ptr = S3.clone();
	surfacePtr S4_ptr = S4.clone();
	surfacePtr S5_ptr = S5.clone();
	surfacePtr S6_ptr = S6.clone();
	surfacePtr S7_ptr = S7.clone();
	surfacePtr S8_ptr = S8.clone();
	surfacePtr S9_ptr = S9.clone();
	surfacePtr S10_ptr = S10.clone();
	surfacePtr S11_ptr = S11.clone();
	surfacePtr S12_ptr = S12.clone();
	surfacePtr S13_ptr = S13.clone();
	surfacePtr S14_ptr = S14.clone();

	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr, S2_ptr, S3_ptr, S4_ptr,S5_ptr,S6_ptr, S7_ptr, S8_ptr, S9_ptr, S10_ptr, S11_ptr, S12_ptr, S13_ptr, S14_ptr };
	std::vector<interaction_ptr> interactions_ptr{ mDoNot.clone(),mRefrac.clone(),mRefrac.clone(),mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(),mRefrac.clone(),mRefrac.clone(),mRefrac.clone(), mAbsorb.clone() };


	//	build optical system
	OpticalSystemElement optSystemElement(opticalSystem_ptr, interactions_ptr);
	oftenUse::print(optSystemElement, 550.0);
	// save the start system
	std::string location = "../tests/testCompareTOMandZemaxOptimizer/E2";
	inportExportData::saveOpticalSystemAsTXT(optSystemElement, 550.0, location, "start_E2");

	// check ref indexes
	bool checkRefIndexes = oftenUse::checkRefractivIndex(optSystemElement);
	workTheSystem.push_back(checkRefIndexes);
	// check the start system
	std::vector<real> rms_Zemax{ 356.769, 436.244, 510.103 };
	bool test = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, mField_vec, mWavelength_FdV_vec, rms_Zemax, mTolerance, compareTOM_Zemax::comEqual);
	workTheSystem.push_back(test);

	//** results optimize Zemax
	real field0_RMS_Z = 19.966;
	real field1_RMS_Z = 9.216;
	real field2_RMS_Z = 20.683;
	std::vector<real> rmsZ = { field0_RMS_Z, field1_RMS_Z,field2_RMS_Z };

	// try all optimization methodes
	saveResultsOptimizationMethodes saveResultsE2 = tryAllOptimizationMethodes(optSystemElement, rmsZ);
	mSaveAllResults.push_back(saveResultsE2);

	// save optimized optical system
	exportAllOpticalSystems(location, saveResultsE2);


	bool returnChecker = Math::checkTrueOfVectorElements(workTheSystem);
	return returnChecker;
}

// E3
bool testCompareTOMandZemaxOptimizer::testCompareTOMandZemaxOptimizer_E3()
{
	std::vector<bool> workTheSystem;
	real semiHeight = 10.0;
	ApertureStopElement S0(/* semi height*/2.0, /*point*/{ 0.0,0.0,25.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ mGlasses.getAir());

	SphericalElement S1(/*radius*/ 15.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ mGlasses.getNSF66_S1(), /*refractive index B*/mGlasses.getAir());
	SphericalElement S2(/*radius*/ 20.0, /*semi height*/semiHeight, /*point*/{ 0.0,0.0,35.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNLAF2_S1(), /*refractive index B*/mGlasses.getNSF66_S1());
	SphericalElement S3(/*radius*/ 15.0, /*semi height*/semiHeight, /*point*/{ 0.0,0.0,40.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNLAF2_S1());

	SphericalElement S4(/*radius*/ 100.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,45.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBAF10_S1());
	SphericalElement S5(/*radius*/ 20.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,50.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNSF57_S1(), /*refractive index B*/mGlasses.getNBAF10_S1());
	SphericalElement S6(/*radius*/ 50.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,55.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF57_S1());

	SphericalElement S7(/*radius*/ 30.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,60.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S8(/*radius*/ 20.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,65.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNSF5_S1(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S9(/*radius*/ 100.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,70.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getNSF5_S1(), /*refractive index B*/mGlasses.getAir());

	SphericalElement S10(/*radius*/ 16.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,75.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S11(/*radius*/ 30.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,80.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());

	SphericalElement S12(/*radius*/ 30.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,85.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNSF5_S1(), /*refractive index B*/mGlasses.getAir());
	PlanElement S13(/*semi height*/ 99.0, /*point*/{ 0.0,0.0,90.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getNSF5_S1(), /*refractive index B*/ mGlasses.getAir());

	PlanElement S14(/*semi height*/ 99.0, /*point*/{ 0.0,0.0,95.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getAir());

	// **********************************
	// set parameter variable
	S7.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S10.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S12.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	// **********************************

	surfacePtr S0_ptr = S0.clone();
	surfacePtr S1_ptr = S1.clone();
	surfacePtr S2_ptr = S2.clone();
	surfacePtr S3_ptr = S3.clone();
	surfacePtr S4_ptr = S4.clone();
	surfacePtr S5_ptr = S5.clone();
	surfacePtr S6_ptr = S6.clone();
	surfacePtr S7_ptr = S7.clone();
	surfacePtr S8_ptr = S8.clone();
	surfacePtr S9_ptr = S9.clone();
	surfacePtr S10_ptr = S10.clone();
	surfacePtr S11_ptr = S11.clone();
	surfacePtr S12_ptr = S12.clone();
	surfacePtr S13_ptr = S13.clone();
	surfacePtr S14_ptr = S14.clone();

	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr, S2_ptr, S3_ptr, S4_ptr,S5_ptr,S6_ptr, S7_ptr, S8_ptr, S9_ptr, S10_ptr, S11_ptr, S12_ptr, S13_ptr, S14_ptr };
	std::vector<interaction_ptr> interactions_ptr{ mDoNot.clone(),mRefrac.clone(),mRefrac.clone(),mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(),mRefrac.clone(),mRefrac.clone(),mRefrac.clone(), mAbsorb.clone() };


	//	build optical system
	OpticalSystemElement optSystemElement(opticalSystem_ptr, interactions_ptr);
	oftenUse::print(optSystemElement, 550.0);
	// save the start system
	std::string location = "../tests/testCompareTOMandZemaxOptimizer/E3";
	inportExportData::saveOpticalSystemAsTXT(optSystemElement, 550.0, location, "start_E3");

	// check ref indexes
	bool checkRefIndexes = oftenUse::checkRefractivIndex(optSystemElement);
	workTheSystem.push_back(checkRefIndexes);
	// check the start system
	std::vector<real> rms_Zemax{ 212.522, 183.967, 155.525 };
	bool test = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, mField_vec, mWavelength_FdV_vec, rms_Zemax, mTolerance, compareTOM_Zemax::comEqual);
	workTheSystem.push_back(test);

	//** results optimize Zemax
	real field0_RMS_Z = 4.746;
	real field1_RMS_Z = 8.494;
	real field2_RMS_Z = 10.443;
	std::vector<real> rmsZ = { field0_RMS_Z, field1_RMS_Z,field2_RMS_Z };

	// try all optimization methodes
	saveResultsOptimizationMethodes saveResultsE3 = tryAllOptimizationMethodes(optSystemElement, rmsZ);
	mSaveAllResults.push_back(saveResultsE3);

	// save optimized optical system
	exportAllOpticalSystems(location, saveResultsE3);


	bool returnChecker = Math::checkTrueOfVectorElements(workTheSystem);
	return returnChecker;
}

// E4
bool testCompareTOMandZemaxOptimizer::testCompareTOMandZemaxOptimizer_E4()
{
	std::vector<bool> workTheSystem;
	real semiHeight = 10.0;
	ApertureStopElement S0(/* semi height*/2.0, /*point*/{ 0.0,0.0,25.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ mGlasses.getAir());

	SphericalElement S1(/*radius*/ 40.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ mGlasses.getNSF66_S1(), /*refractive index B*/mGlasses.getAir());
	SphericalElement S2(/*radius*/ 150.0, /*semi height*/semiHeight, /*point*/{ 0.0,0.0,35.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNLAF2_S1(), /*refractive index B*/mGlasses.getNSF66_S1());
	SphericalElement S3(/*radius*/ 15.0, /*semi height*/semiHeight, /*point*/{ 0.0,0.0,40.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNLAF2_S1());

	SphericalElement S4(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,45.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBAF10_S1());
	SphericalElement S5(/*radius*/ 20.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,50.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNSF57_S1(), /*refractive index B*/mGlasses.getNBAF10_S1());
	SphericalElement S6(/*radius*/ 50.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,55.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF57_S1());

	SphericalElement S7(/*radius*/ 30.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,60.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNBK7_S1(), /*refractive index B*/mGlasses.getAir());
	SphericalElement S8(/*radius*/ 20.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,65.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNSF5_S1(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S9(/*radius*/ 100.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,70.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getNSF5_S1(), /*refractive index B*/mGlasses.getAir());

	SphericalElement S10(/*radius*/ 20.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,75.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S11(/*radius*/ 30.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,80.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());

	SphericalElement S12(/*radius*/ 30.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,85.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNSF5_S1(), /*refractive index B*/mGlasses.getAir());
	PlanElement S13(/*semi height*/ 99.0, /*point*/{ 0.0,0.0,90.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getNSF5_S1(), /*refractive index B*/ mGlasses.getAir());

	PlanElement S14(/*semi height*/ 99.0, /*point*/{ 0.0,0.0,105.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getAir());

	// **********************************
	// set parameter variable
	S3.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S6.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S12.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S13.setParameterPointZ(/*min value*/ 1.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	// **********************************

	surfacePtr S0_ptr = S0.clone();
	surfacePtr S1_ptr = S1.clone();
	surfacePtr S2_ptr = S2.clone();
	surfacePtr S3_ptr = S3.clone();
	surfacePtr S4_ptr = S4.clone();
	surfacePtr S5_ptr = S5.clone();
	surfacePtr S6_ptr = S6.clone();
	surfacePtr S7_ptr = S7.clone();
	surfacePtr S8_ptr = S8.clone();
	surfacePtr S9_ptr = S9.clone();
	surfacePtr S10_ptr = S10.clone();
	surfacePtr S11_ptr = S11.clone();
	surfacePtr S12_ptr = S12.clone();
	surfacePtr S13_ptr = S13.clone();
	surfacePtr S14_ptr = S14.clone();

	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr, S2_ptr, S3_ptr, S4_ptr,S5_ptr,S6_ptr, S7_ptr, S8_ptr, S9_ptr, S10_ptr, S11_ptr, S12_ptr, S13_ptr, S14_ptr };
	std::vector<interaction_ptr> interactions_ptr{ mDoNot.clone(),mRefrac.clone(),mRefrac.clone(),mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(),mRefrac.clone(),mRefrac.clone(),mRefrac.clone(), mAbsorb.clone() };


	//	build optical system
	OpticalSystemElement optSystemElement(opticalSystem_ptr, interactions_ptr);
	oftenUse::print(optSystemElement, 550.0);
	// save the start system
	std::string location = "../tests/testCompareTOMandZemaxOptimizer/E4";
	inportExportData::saveOpticalSystemAsTXT(optSystemElement, 550.0, location, "start_E4");

	// check ref indexes
	bool checkRefIndexes = oftenUse::checkRefractivIndex(optSystemElement);
	workTheSystem.push_back(checkRefIndexes);
	// check the start system
	std::vector<real> rms_Zemax{ 519.694, 470.473, 418.810 };
	bool test = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, mField_vec, mWavelength_FdV_vec, rms_Zemax, mTolerance, compareTOM_Zemax::comEqual);
	workTheSystem.push_back(test);

	//** results optimize Zemax
	real field0_RMS_Z = 17.662;
	real field1_RMS_Z = 18.713;
	real field2_RMS_Z = 21.407;
	std::vector<real> rmsZ = { field0_RMS_Z, field1_RMS_Z,field2_RMS_Z };

	// try all optimization methodes
	saveResultsOptimizationMethodes saveResultsE4 = tryAllOptimizationMethodes(optSystemElement, rmsZ);
	mSaveAllResults.push_back(saveResultsE4);

	// save optimized optical system
	exportAllOpticalSystems(location, saveResultsE4);


	bool returnChecker = Math::checkTrueOfVectorElements(workTheSystem);
	return returnChecker;
}

// E5
bool testCompareTOMandZemaxOptimizer::testCompareTOMandZemaxOptimizer_E5()
{
	std::vector<bool> workTheSystem;
	real semiHeight = 10.0;
	ApertureStopElement S0(/* semi height*/1.5, /*point*/{ 0.0,0.0,25.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ mGlasses.getAir());

	SphericalElement S1(/*radius*/ 30.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ mGlasses.getNSF66_S1(), /*refractive index B*/mGlasses.getAir());
	SphericalElement S2(/*radius*/ 60.0, /*semi height*/semiHeight, /*point*/{ 0.0,0.0,35.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNLAF2_S1(), /*refractive index B*/mGlasses.getNSF66_S1());
	SphericalElement S3(/*radius*/ 50.0, /*semi height*/semiHeight, /*point*/{ 0.0,0.0,40.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNLAF2_S1());

	SphericalElement S4(/*radius*/ 60.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,45.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBAF10_S1());
	SphericalElement S5(/*radius*/ 40.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,50.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNSF57_S1(), /*refractive index B*/mGlasses.getNBAF10_S1());
	SphericalElement S6(/*radius*/ 50.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,55.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF57_S1());

	SphericalElement S7(/*radius*/ 30.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,60.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S8(/*radius*/ 20.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,65.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNSF5_S1(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S9(/*radius*/ 100.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,70.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getNSF5_S1(), /*refractive index B*/mGlasses.getAir());

	SphericalElement S10(/*radius*/ 20.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,75.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S11(/*radius*/ 20.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,80.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNPSK53_S1(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S12(/*radius*/ 30.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,85.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNPSK53_S1());

	SphericalElement S13(/*radius*/ 50.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,90.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S14(/*radius*/ 100.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,95.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());


	PlanElement S15(/*semi height*/ 99.0, /*point*/{ 0.0,0.0,100.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getAir());

	// **********************************
	// set parameter variable
	S3.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S4.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S7.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S10.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	// **********************************

	surfacePtr S0_ptr = S0.clone();
	surfacePtr S1_ptr = S1.clone();
	surfacePtr S2_ptr = S2.clone();
	surfacePtr S3_ptr = S3.clone();
	surfacePtr S4_ptr = S4.clone();
	surfacePtr S5_ptr = S5.clone();
	surfacePtr S6_ptr = S6.clone();
	surfacePtr S7_ptr = S7.clone();
	surfacePtr S8_ptr = S8.clone();
	surfacePtr S9_ptr = S9.clone();
	surfacePtr S10_ptr = S10.clone();
	surfacePtr S11_ptr = S11.clone();
	surfacePtr S12_ptr = S12.clone();
	surfacePtr S13_ptr = S13.clone();
	surfacePtr S14_ptr = S14.clone();
	surfacePtr S15_ptr = S15.clone();


	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr, S2_ptr, S3_ptr, S4_ptr,S5_ptr,S6_ptr, S7_ptr, S8_ptr, S9_ptr, S10_ptr, S11_ptr, S12_ptr, S13_ptr, S14_ptr, S15_ptr };
	std::vector<interaction_ptr> interactions_ptr{ mDoNot.clone(),mRefrac.clone(),mRefrac.clone(),mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(),mRefrac.clone(),mRefrac.clone(),mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };


	//	build optical system
	OpticalSystemElement optSystemElement(opticalSystem_ptr, interactions_ptr);
	oftenUse::print(optSystemElement, 550.0);
	// save the start system
	std::string location = "../tests/testCompareTOMandZemaxOptimizer/E5";
	inportExportData::saveOpticalSystemAsTXT(optSystemElement, 550.0, location, "start_E5");

	// check ref indexes
	bool checkRefIndexes = oftenUse::checkRefractivIndex(optSystemElement);
	workTheSystem.push_back(checkRefIndexes);
	// check the start system
	std::vector<real> rms_Zemax{ 447.876, 391.857, 337.982 };
	bool test = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, mField_vec, mWavelength_FdV_vec, rms_Zemax, mTolerance, compareTOM_Zemax::comEqual);
	workTheSystem.push_back(test);

	//** results optimize Zemax
	real field0_RMS_Z = 10.033;
	real field1_RMS_Z = 10.702;
	real field2_RMS_Z = 14.893;
	std::vector<real> rmsZ = { field0_RMS_Z, field1_RMS_Z,field2_RMS_Z };

	// try all optimization methodes
	saveResultsOptimizationMethodes saveResultsE5 = tryAllOptimizationMethodes(optSystemElement, rmsZ);
	mSaveAllResults.push_back(saveResultsE5);

	// save optimized optical system
	exportAllOpticalSystems(location, saveResultsE5);


	bool returnChecker = Math::checkTrueOfVectorElements(workTheSystem);
	return returnChecker;
}

// E6
bool testCompareTOMandZemaxOptimizer::testCompareTOMandZemaxOptimizer_E6()
{
	std::vector<bool> workTheSystem;

	real semiHeight = 10.0;
	ApertureStopElement S0(/* semi height*/1.0, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ mGlasses.getAir());

	SphericalElement S1(/*radius*/ 90.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,40.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF66_S1());
	SphericalElement S2(/*radius*/ 30.0, /*semi height*/semiHeight, /*point*/{ 0.0,0.0,50.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getNSF66_S1(), /*refractive index B*/mGlasses.getNLAF2_S1());
	SphericalElement S3(/*radius*/ 80.0, /*semi height*/semiHeight, /*point*/{ 0.0,0.0,60.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getNLAF2_S1(), /*refractive index B*/mGlasses.getAir());

	SphericalElement S4(/*radius*/ 50.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,70.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBAF10_S1());
	SphericalElement S5(/*radius*/ 40.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,80.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNSF57_S1(), /*refractive index B*/mGlasses.getNBAF10_S1());
	SphericalElement S6(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,90.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF57_S1());

	SphericalElement S7(/*radius*/ 50.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,100.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S8(/*radius*/ 40.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,110.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNSF5_S1(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S9(/*radius*/ 50.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,120.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF5_S1());

	SphericalElement S10(/*radius*/ 20.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,130.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNBK7_S1(), /*refractive index B*/mGlasses.getAir());
	SphericalElement S11(/*radius*/ 30.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,140.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNPSK53_S1(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S12(/*radius*/ 30.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,150.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNPSK53_S1());

	SphericalElement S13(/*radius*/ 20.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,160.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S14(/*radius*/ 100.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,170.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNLAK22_S1(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S15(/*radius*/ 50.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,180.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getNLAK22_S1(), /*refractive index B*/mGlasses.getAir());

	PlanElement S16(/*semi height*/ 99.0, /*point*/{ 0.0,0.0,190.00 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getAir());

	// **********************************
	// set parameter variable
	S2.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S7.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S12.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S15.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	// **********************************

	surfacePtr S0_ptr = S0.clone();
	surfacePtr S1_ptr = S1.clone();
	surfacePtr S2_ptr = S2.clone();
	surfacePtr S3_ptr = S3.clone();
	surfacePtr S4_ptr = S4.clone();
	surfacePtr S5_ptr = S5.clone();
	surfacePtr S6_ptr = S6.clone();
	surfacePtr S7_ptr = S7.clone();
	surfacePtr S8_ptr = S8.clone();
	surfacePtr S9_ptr = S9.clone();
	surfacePtr S10_ptr = S10.clone();
	surfacePtr S11_ptr = S11.clone();
	surfacePtr S12_ptr = S12.clone();
	surfacePtr S13_ptr = S13.clone();
	surfacePtr S14_ptr = S14.clone();
	surfacePtr S15_ptr = S15.clone();
	surfacePtr S16_ptr = S16.clone();

	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr, S2_ptr, S3_ptr, S4_ptr,S5_ptr,S6_ptr, S7_ptr, S8_ptr, S9_ptr, S10_ptr, S11_ptr, S12_ptr, S13_ptr, S14_ptr, S15_ptr, S16_ptr };
	std::vector<interaction_ptr> interactions_ptr{ mDoNot.clone(),mRefrac.clone(),mRefrac.clone(),mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(),mRefrac.clone(),mRefrac.clone(),mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };


	//	build optical system
	OpticalSystemElement optSystemElement(opticalSystem_ptr, interactions_ptr);
	oftenUse::print(optSystemElement, 550.0);
	// save the start system
	std::string location = "../tests/testCompareTOMandZemaxOptimizer/E6";
	inportExportData::saveOpticalSystemAsTXT(optSystemElement, 550.0, location, "start_E6");

	// check ref indexes
	bool checkRefIndexes = oftenUse::checkRefractivIndex(optSystemElement);
	workTheSystem.push_back(checkRefIndexes);
	// check the start system
	std::vector<real> rms_Zemax{ 27.277, 29.929, 34.267 };
	bool test = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, mField_vec, mWavelength_FdV_vec, rms_Zemax, mTolerance, compareTOM_Zemax::comEqual);
	workTheSystem.push_back(test);

	//** results optimize Zemax
	real field0_RMS_Z = 19.647;
	real field1_RMS_Z = 34.989;
	real field2_RMS_Z = 49.129;
	std::vector<real> rmsZ = { field0_RMS_Z, field1_RMS_Z,field2_RMS_Z };

	// try all optimization methodes
	saveResultsOptimizationMethodes saveResultsE6 = tryAllOptimizationMethodes(optSystemElement, rmsZ);
	mSaveAllResults.push_back(saveResultsE6);

	// save optimized optical system
	exportAllOpticalSystems(location, saveResultsE6);

	bool returnChecker = Math::checkTrueOfVectorElements(workTheSystem);
	return returnChecker;
}

// E7
bool testCompareTOMandZemaxOptimizer::testCompareTOMandZemaxOptimizer_E7()
{
	std::vector<bool> workTheSystem;

	real semiHeight = 15.0;
	ApertureStopElement S0(/* semi height*/1.5, /*point*/{ 0.0,0.0,50.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ mGlasses.getAir());

	SphericalElement S1(/*radius*/ 900.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,55.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ mGlasses.getNSF66_S1(), /*refractive index B*/mGlasses.getAir());
	SphericalElement S2(/*radius*/ 80.0, /*semi height*/semiHeight, /*point*/{ 0.0,0.0,60.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNLAF2_S1(), /*refractive index B*/mGlasses.getNSF66_S1());
	SphericalElement S3(/*radius*/ 100.0, /*semi height*/semiHeight, /*point*/{ 0.0,0.0,65.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getNLAF2_S1(), /*refractive index B*/mGlasses.getAir());

	SphericalElement S4(/*radius*/ 40.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,70.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBAF10_S1());
	SphericalElement S5(/*radius*/ 40.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,75.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNSF57_S1(), /*refractive index B*/mGlasses.getNBAF10_S1());
	SphericalElement S6(/*radius*/ 50.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,80.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF57_S1());

	SphericalElement S7(/*radius*/ 70.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,85.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S8(/*radius*/ 40.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,90.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNSF5_S1(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S9(/*radius*/ 100.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,95.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF5_S1());

	SphericalElement S10(/*radius*/ 50.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,100.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S11(/*radius*/ 30.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,105.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNPSK53_S1(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S12(/*radius*/ 30.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,110.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNPSK53_S1());

	SphericalElement S13(/*radius*/ 30.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,115.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S14(/*radius*/ 100.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,120.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNLAK22_S1(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S15(/*radius*/ 100.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,125.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNLAK22_S1());

	PlanElement S16(/*semi height*/ 99.0, /*point*/{ 0.0,0.0,130.00 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getAir());

	// **********************************
	// set parameter variable
	S2.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S7.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S7.setParameterPointZ(/*min value*/ 1.0, /*max value*/ 60.0, 0.0, typeModifierVariable);
	S15.setParameterPointZ(/*min value*/ 1.0, /*max value*/ 20.0, 0.0, typeModifierVariable);
	// **********************************

	surfacePtr S0_ptr = S0.clone();
	surfacePtr S1_ptr = S1.clone();
	surfacePtr S2_ptr = S2.clone();
	surfacePtr S3_ptr = S3.clone();
	surfacePtr S4_ptr = S4.clone();
	surfacePtr S5_ptr = S5.clone();
	surfacePtr S6_ptr = S6.clone();
	surfacePtr S7_ptr = S7.clone();
	surfacePtr S8_ptr = S8.clone();
	surfacePtr S9_ptr = S9.clone();
	surfacePtr S10_ptr = S10.clone();
	surfacePtr S11_ptr = S11.clone();
	surfacePtr S12_ptr = S12.clone();
	surfacePtr S13_ptr = S13.clone();
	surfacePtr S14_ptr = S14.clone();
	surfacePtr S15_ptr = S15.clone();
	surfacePtr S16_ptr = S16.clone();

	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr, S2_ptr, S3_ptr, S4_ptr,S5_ptr,S6_ptr, S7_ptr, S8_ptr, S9_ptr, S10_ptr, S11_ptr, S12_ptr, S13_ptr, S14_ptr, S15_ptr, S16_ptr };
	std::vector<interaction_ptr> interactions_ptr{ mDoNot.clone(),mRefrac.clone(),mRefrac.clone(),mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(),mRefrac.clone(),mRefrac.clone(),mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };


	//	build optical system
	OpticalSystemElement optSystemElement(opticalSystem_ptr, interactions_ptr);
	oftenUse::print(optSystemElement, 550.0);
	// save the start system
	std::string location = "../tests/testCompareTOMandZemaxOptimizer/E7";
	inportExportData::saveOpticalSystemAsTXT(optSystemElement, 550.0, location, "start_E7");

	// check ref indexes
	bool checkRefIndexes = oftenUse::checkRefractivIndex(optSystemElement);
	workTheSystem.push_back(checkRefIndexes);
	// check the start system
	std::vector<real> rms_Zemax{ 123.730, 133.111, 142.486 };
	bool test = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, mField_vec, mWavelength_FdV_vec, rms_Zemax, mTolerance, compareTOM_Zemax::comEqual);
	workTheSystem.push_back(test);

	//** results optimize Zemax
	real field0_RMS_Z = 8.952;
	real field1_RMS_Z = 13.372;
	real field2_RMS_Z = 21.629;
	std::vector<real> rmsZ = { field0_RMS_Z, field1_RMS_Z,field2_RMS_Z };

	// try all optimization methodes
	saveResultsOptimizationMethodes saveResultsE7 = tryAllOptimizationMethodes(optSystemElement, rmsZ);
	mSaveAllResults.push_back(saveResultsE7);

	// save optimized optical system
	exportAllOpticalSystems(location, saveResultsE7);

	bool returnChecker = Math::checkTrueOfVectorElements(workTheSystem);
	return returnChecker;
}

// E8
bool testCompareTOMandZemaxOptimizer::testCompareTOMandZemaxOptimizer_E8()
{
	std::vector<bool> workTheSystem;

	real semiHeight = 7.0;
	ApertureStopElement S0(/* semi height*/2.0, /*point*/{ 0.0,0.0,50.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ mGlasses.getAir());

	SphericalElement S1(/*radius*/ 30.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,55.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF66_S1());
	SphericalElement S2(/*radius*/ 15.0, /*semi height*/semiHeight, /*point*/{ 0.0,0.0,60.0 }, /*direction*/{ 0.0,0.0,  1.0 }, /*refractive index A*/ mGlasses.getNSF66_S1(), /*refractive index B*/mGlasses.getAir());

	SphericalElement S3(/*radius*/ 20.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,65.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S4(/*radius*/ 15.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,70.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());

	SphericalElement S5(/*radius*/ 20.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,75.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S6(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,80.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());

	SphericalElement S7(/*radius*/ 20.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,85.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNBK7_S1(), /*refractive index B*/mGlasses.getAir());
	SphericalElement S8(/*radius*/ 30.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,90.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getNBK7_S1(), /*refractive index B*/mGlasses.getAir());

	SphericalElement S9(/*radius*/ 20.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,95.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF10_S1());
	SphericalElement S10(/*radius*/ 15.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,100.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getNSF10_S1(), /*refractive index B*/mGlasses.getAir());

	SphericalElement S11(/*radius*/ 25.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,105.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF5_S1());
	SphericalElement S12(/*radius*/ 15.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,110.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF5_S1());

	SphericalElement S13(/*radius*/ 15.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,115.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNLAF2_S1());
	SphericalElement S14(/*radius*/ 15.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,120.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNLAF2_S1());

	SphericalElement S15(/*radius*/ 15.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,125.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF57_S1());
	SphericalElement S16(/*radius*/ 60.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,130.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF57_S1());

	PlanElement S17(/*semi height*/ 99.0, /*point*/{ 0.0,0.0,135.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getAir());

	// **********************************
	// set parameter variable
	S5.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S7.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S9.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S11.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S13.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);

	// **********************************

	surfacePtr S0_ptr = S0.clone();
	surfacePtr S1_ptr = S1.clone();
	surfacePtr S2_ptr = S2.clone();
	surfacePtr S3_ptr = S3.clone();
	surfacePtr S4_ptr = S4.clone();
	surfacePtr S5_ptr = S5.clone();
	surfacePtr S6_ptr = S6.clone();
	surfacePtr S7_ptr = S7.clone();
	surfacePtr S8_ptr = S8.clone();
	surfacePtr S9_ptr = S9.clone();
	surfacePtr S10_ptr = S10.clone();
	surfacePtr S11_ptr = S11.clone();
	surfacePtr S12_ptr = S12.clone();
	surfacePtr S13_ptr = S13.clone();
	surfacePtr S14_ptr = S14.clone();
	surfacePtr S15_ptr = S15.clone();
	surfacePtr S16_ptr = S16.clone();
	surfacePtr S17_ptr = S17.clone();

	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr, S2_ptr, S3_ptr, S4_ptr,S5_ptr,S6_ptr, S7_ptr, S8_ptr, S9_ptr, S10_ptr, S11_ptr, S12_ptr, S13_ptr, S14_ptr, S15_ptr, S16_ptr, S17_ptr };
	std::vector<interaction_ptr> interactions_ptr{ mDoNot.clone(),mRefrac.clone(),mRefrac.clone(),mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(),mRefrac.clone(),mRefrac.clone(),mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };


	//	build optical system
	OpticalSystemElement optSystemElement(opticalSystem_ptr, interactions_ptr);
	oftenUse::print(optSystemElement, 550.0);
	// save the start system
	std::string location = "../tests/testCompareTOMandZemaxOptimizer/E8";
	inportExportData::saveOpticalSystemAsTXT(optSystemElement, 550.0, location, "start_E8");

	// check ref indexes
	bool checkRefIndexes = oftenUse::checkRefractivIndex(optSystemElement);
	workTheSystem.push_back(checkRefIndexes);
	// check the start system
	std::vector<real> rms_Zemax{ 204.055, 179.563, 154.598 };
	bool test = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, mField_vec, mWavelength_FdV_vec, rms_Zemax, mTolerance, compareTOM_Zemax::comEqual);
	workTheSystem.push_back(test);

	//** results optimize Zemax
	real field0_RMS_Z = 23.213;
	real field1_RMS_Z = 24.604;
	real field2_RMS_Z = 27.678;
	std::vector<real> rmsZ = { field0_RMS_Z, field1_RMS_Z,field2_RMS_Z };

	// try all optimization methodes
	saveResultsOptimizationMethodes saveResultsE8 = tryAllOptimizationMethodes(optSystemElement, rmsZ);
	mSaveAllResults.push_back(saveResultsE8);

	// save optimized optical system
	exportAllOpticalSystems(location, saveResultsE8);

	bool returnChecker = Math::checkTrueOfVectorElements(workTheSystem);
	return returnChecker;
}

// E9
bool testCompareTOMandZemaxOptimizer::testCompareTOMandZemaxOptimizer_E9()
{
	std::vector<bool> workTheSystem;

	real semiHeight = 7.0;
	ApertureStopElement S0(/* semi height*/1.0, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ mGlasses.getAir());

	SphericalElement S1(/*radius*/ 30.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,35.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNSF66_S1(), /*refractive index B*/mGlasses.getAir());
	SphericalElement S2(/*radius*/ 15.0, /*semi height*/semiHeight, /*point*/{ 0.0,0.0,40.0 }, /*direction*/{ 0.0,0.0,  -1.0 }, /*refractive index A*/ mGlasses.getNSF5_S1(), /*refractive index B*/mGlasses.getNSF66_S1());
	SphericalElement S3(/*radius*/ 30.0, /*semi height*/semiHeight, /*point*/{ 0.0,0.0,45.0 }, /*direction*/{ 0.0,0.0,  -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF5_S1());

	SphericalElement S4(/*radius*/ 20.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,50.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S5(/*radius*/ 15.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,55.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNSF10_S1(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S6(/*radius*/ 90.0, /*semi height*/semiHeight, /*point*/{ 0.0,0.0,60.0 }, /*direction*/{ 0.0,0.0,  1.0 }, /*refractive index A*/ mGlasses.getNSF10_S1(), /*refractive index B*/mGlasses.getAir());

	SphericalElement S7(/*radius*/ 20.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,65.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S8(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,70.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNBK10_S1(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S9(/*radius*/ 40.0, /*semi height*/semiHeight, /*point*/{ 0.0,0.0,75.0 }, /*direction*/{ 0.0,0.0,  -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK10_S1());

	SphericalElement S10(/*radius*/ 20.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,80.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNBK7_S1(), /*refractive index B*/mGlasses.getAir());
	SphericalElement S11(/*radius*/ 30.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,85.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getNBK7_S1(), /*refractive index B*/mGlasses.getNSF5_S1());
	SphericalElement S12(/*radius*/ 40.0, /*semi height*/semiHeight, /*point*/{ 0.0,0.0,90.0 }, /*direction*/{ 0.0,0.0,  -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF5_S1());

	SphericalElement S13(/*radius*/ 20.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,95.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF10_S1());
	SphericalElement S14(/*radius*/ 15.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,100.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getNSF10_S1(), /*refractive index B*/mGlasses.getAir());

	SphericalElement S15(/*radius*/ 25.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,105.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF5_S1());
	SphericalElement S16(/*radius*/ 15.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,110.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF5_S1());

	SphericalElement S17(/*radius*/ 15.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,115.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNLAF2_S1());
	SphericalElement S18(/*radius*/ 15.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,120.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNLAF2_S1());

	SphericalElement S19(/*radius*/ 15.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,125.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF57_S1());
	SphericalElement S20(/*radius*/ 60.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,130.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF57_S1());

	PlanElement S21(/*semi height*/ 99.0, /*point*/{ 0.0,0.0,135.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getAir());

	// **********************************
	// set parameter variable
	S3.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S6.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S9.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S12.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S18.setParameterPointZ(/*min value*/ 1.0, /*max value*/ 40.0, 0.0, typeModifierVariable);

	// **********************************

	surfacePtr S0_ptr = S0.clone();
	surfacePtr S1_ptr = S1.clone();
	surfacePtr S2_ptr = S2.clone();
	surfacePtr S3_ptr = S3.clone();
	surfacePtr S4_ptr = S4.clone();
	surfacePtr S5_ptr = S5.clone();
	surfacePtr S6_ptr = S6.clone();
	surfacePtr S7_ptr = S7.clone();
	surfacePtr S8_ptr = S8.clone();
	surfacePtr S9_ptr = S9.clone();
	surfacePtr S10_ptr = S10.clone();
	surfacePtr S11_ptr = S11.clone();
	surfacePtr S12_ptr = S12.clone();
	surfacePtr S13_ptr = S13.clone();
	surfacePtr S14_ptr = S14.clone();
	surfacePtr S15_ptr = S15.clone();
	surfacePtr S16_ptr = S16.clone();
	surfacePtr S17_ptr = S17.clone();
	surfacePtr S18_ptr = S18.clone();
	surfacePtr S19_ptr = S19.clone();
	surfacePtr S20_ptr = S20.clone();
	surfacePtr S21_ptr = S21.clone();

	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr, S2_ptr, S3_ptr, S4_ptr,S5_ptr,S6_ptr, S7_ptr, S8_ptr, S9_ptr, S10_ptr, S11_ptr, S12_ptr, S13_ptr, S14_ptr, S15_ptr, S16_ptr, S17_ptr, S18_ptr, S19_ptr, S20_ptr, S21_ptr };
	std::vector<interaction_ptr> interactions_ptr{ mDoNot.clone(),mRefrac.clone(),mRefrac.clone(),mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(),mRefrac.clone(),mRefrac.clone(),mRefrac.clone(), mRefrac.clone(),mRefrac.clone(),mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };


	//	build optical system
	OpticalSystemElement optSystemElement(opticalSystem_ptr, interactions_ptr);
	oftenUse::print(optSystemElement, 550.0);
	// save the start system
	std::string location = "../tests/testCompareTOMandZemaxOptimizer/E9";
	inportExportData::saveOpticalSystemAsTXT(optSystemElement, 550.0, location, "start_E9");

	// check ref indexes
	bool checkRefIndexes = oftenUse::checkRefractivIndex(optSystemElement);
	workTheSystem.push_back(checkRefIndexes);
	// check the start system
	std::vector<real> rms_Zemax{ 349.084, 328.717, 304.650 };
	bool test = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, mField_vec, mWavelength_FdV_vec, rms_Zemax, mTolerance, compareTOM_Zemax::comEqual);
	workTheSystem.push_back(test);

	//** results optimize Zemax
	real field0_RMS_Z = 22.608;
	real field1_RMS_Z = 16.075;
	real field2_RMS_Z = 27.268;
	std::vector<real> rmsZ = { field0_RMS_Z, field1_RMS_Z,field2_RMS_Z };

	// try all optimization methodes
	saveResultsOptimizationMethodes saveResultsE9 = tryAllOptimizationMethodes(optSystemElement, rmsZ);
	mSaveAllResults.push_back(saveResultsE9);

	// save optimized optical system
	exportAllOpticalSystems(location, saveResultsE9);

	bool returnChecker = Math::checkTrueOfVectorElements(workTheSystem);
	return returnChecker;
}

// E10
bool testCompareTOMandZemaxOptimizer::testCompareTOMandZemaxOptimizer_E10()
{
	std::vector<bool> workTheSystem;

	real semiHeight = 7.0;
	ApertureStopElement S0(/* semi height*/1.0, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ mGlasses.getAir());

	SphericalElement S1(/*radius*/ 30.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,35.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNSF66_S1(), /*refractive index B*/mGlasses.getAir());
	SphericalElement S2(/*radius*/ 15.0, /*semi height*/semiHeight, /*point*/{ 0.0,0.0,40.0 }, /*direction*/{ 0.0,0.0,  -1.0 }, /*refractive index A*/ mGlasses.getNSF5_S1(), /*refractive index B*/mGlasses.getNSF66_S1());
	SphericalElement S3(/*radius*/ 30.0, /*semi height*/semiHeight, /*point*/{ 0.0,0.0,45.0 }, /*direction*/{ 0.0,0.0,  -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF5_S1());

	SphericalElement S4(/*radius*/ 20.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,50.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S5(/*radius*/ 15.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,55.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNSF10_S1(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S6(/*radius*/ 100.0, /*semi height*/semiHeight, /*point*/{ 0.0,0.0,60.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF10_S1());

	SphericalElement S7(/*radius*/ 20.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,65.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S8(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,70.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNBK10_S1(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S9(/*radius*/ 80.0, /*semi height*/semiHeight, /*point*/{ 0.0,0.0,75.0 }, /*direction*/{ 0.0,0.0,  -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK10_S1());

	SphericalElement S10(/*radius*/ 20.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,80.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNBK7_S1(), /*refractive index B*/mGlasses.getAir());
	SphericalElement S11(/*radius*/ 30.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,85.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getNBK7_S1(), /*refractive index B*/mGlasses.getNSF5_S1());
	SphericalElement S12(/*radius*/ 40.0, /*semi height*/semiHeight, /*point*/{ 0.0,0.0,90.0 }, /*direction*/{ 0.0,0.0,  -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF5_S1());

	SphericalElement S13(/*radius*/ 20.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,95.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF10_S1());
	SphericalElement S14(/*radius*/ 15.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,100.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getNSF10_S1(), /*refractive index B*/mGlasses.getNBK10_S1());
	SphericalElement S15(/*radius*/ 20.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,105.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getNBK10_S1(), /*refractive index B*/mGlasses.getAir());

	SphericalElement S16(/*radius*/ 25.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,110.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF5_S1());
	SphericalElement S17(/*radius*/ 15.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,115.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNBK10_S1(), /*refractive index B*/mGlasses.getNSF5_S1());
	SphericalElement S18(/*radius*/ 700.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,120.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK10_S1());

	SphericalElement S19(/*radius*/ 15.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,125.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNLAF2_S1());
	SphericalElement S20(/*radius*/ 15.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,130.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNSF15_S1(), /*refractive index B*/mGlasses.getNLAF2_S1());
	SphericalElement S21(/*radius*/ 50.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,135.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF15_S1());

	SphericalElement S22(/*radius*/ 15.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,140.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF57_S1());
	SphericalElement S23(/*radius*/ 60.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,145.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNBK7_S1(), /*refractive index B*/mGlasses.getNSF57_S1());
	SphericalElement S24(/*radius*/ 200.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,150.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());

	PlanElement S25(/*semi height*/ 99.0, /*point*/{ 0.0,0.0,155.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getAir());

	// **********************************
	// set parameter variable
	S6.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S9.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S15.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S21.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	// **********************************

	surfacePtr S0_ptr = S0.clone();
	surfacePtr S1_ptr = S1.clone();
	surfacePtr S2_ptr = S2.clone();
	surfacePtr S3_ptr = S3.clone();
	surfacePtr S4_ptr = S4.clone();
	surfacePtr S5_ptr = S5.clone();
	surfacePtr S6_ptr = S6.clone();
	surfacePtr S7_ptr = S7.clone();
	surfacePtr S8_ptr = S8.clone();
	surfacePtr S9_ptr = S9.clone();
	surfacePtr S10_ptr = S10.clone();
	surfacePtr S11_ptr = S11.clone();
	surfacePtr S12_ptr = S12.clone();
	surfacePtr S13_ptr = S13.clone();
	surfacePtr S14_ptr = S14.clone();
	surfacePtr S15_ptr = S15.clone();
	surfacePtr S16_ptr = S16.clone();
	surfacePtr S17_ptr = S17.clone();
	surfacePtr S18_ptr = S18.clone();
	surfacePtr S19_ptr = S19.clone();
	surfacePtr S20_ptr = S20.clone();
	surfacePtr S21_ptr = S21.clone();
	surfacePtr S22_ptr = S22.clone();
	surfacePtr S23_ptr = S23.clone();
	surfacePtr S24_ptr = S24.clone();
	surfacePtr S25_ptr = S25.clone();

	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr, S2_ptr, S3_ptr, S4_ptr,S5_ptr,S6_ptr, S7_ptr, S8_ptr, S9_ptr, S10_ptr, S11_ptr, S12_ptr, S13_ptr, S14_ptr, S15_ptr, S16_ptr, S17_ptr, S18_ptr, S19_ptr, S20_ptr, S21_ptr, S22_ptr, S23_ptr, S24_ptr, S25_ptr, };
	std::vector<interaction_ptr> interactions_ptr{ mDoNot.clone(),mRefrac.clone(),mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(),mRefrac.clone(),mRefrac.clone(),mRefrac.clone(), mRefrac.clone(),mRefrac.clone(),mRefrac.clone(),mRefrac.clone(),mRefrac.clone(),mRefrac.clone(),mRefrac.clone(),mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };


	//	build optical system
	OpticalSystemElement optSystemElement(opticalSystem_ptr, interactions_ptr);
	oftenUse::print(optSystemElement, 550.0);
	// save the start system
	std::string location = "../tests/testCompareTOMandZemaxOptimizer/E10";
	inportExportData::saveOpticalSystemAsTXT(optSystemElement, 550.0, location, "start_E10");

	// check ref indexes
	bool checkRefIndexes = oftenUse::checkRefractivIndex(optSystemElement);
	workTheSystem.push_back(checkRefIndexes);
	// check the start system
	std::vector<real> rms_Zemax{ 29.028, 23.453, 25.854 };
	bool test = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, mField_vec, mWavelength_FdV_vec, rms_Zemax, mTolerance, compareTOM_Zemax::comEqual);
	workTheSystem.push_back(test);

	//** results optimize Zemax
	real field0_RMS_Z = 22.206;
	real field1_RMS_Z = 19.974;
	real field2_RMS_Z = 23.429;
	std::vector<real> rmsZ = { field0_RMS_Z, field1_RMS_Z,field2_RMS_Z };

	// try all optimization methodes
	saveResultsOptimizationMethodes saveResultsE10 = tryAllOptimizationMethodes(optSystemElement, rmsZ);
	mSaveAllResults.push_back(saveResultsE10);

	// save optimized optical system
	exportAllOpticalSystems(location, saveResultsE10);

	bool returnChecker = Math::checkTrueOfVectorElements(workTheSystem);
	return returnChecker;
}

// E11
bool testCompareTOMandZemaxOptimizer::testCompareTOMandZemaxOptimizer_E11()
{
	std::vector<bool> workTheSystem;

	real semiHeight = 7.0;
	ApertureStopElement S0(/* semi height*/1.5, /*point*/{ 0.0,0.0,50.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ mGlasses.getAir());

	SphericalElement S1(/*radius*/ 30.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,55.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNSF66_S1(), /*refractive index B*/mGlasses.getAir());
	SphericalElement S2(/*radius*/ 80.0, /*semi height*/semiHeight, /*point*/{ 0.0,0.0,60.0 }, /*direction*/{ 0.0,0.0,  -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF66_S1());

	SphericalElement S3(/*radius*/ 20.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,65.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S4(/*radius*/ 50.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,70.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());

	SphericalElement S5(/*radius*/ 20.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,75.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S6(/*radius*/ 30.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,80.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNBK10_S1(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S7(/*radius*/ 80.0, /*semi height*/semiHeight, /*point*/{ 0.0,0.0,85.0 }, /*direction*/{ 0.0,0.0,  -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK10_S1());

	SphericalElement S8(/*radius*/ 20.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,90.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNBK7_S1(), /*refractive index B*/mGlasses.getAir());
	SphericalElement S9(/*radius*/ 30.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,95.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getNBK7_S1(), /*refractive index B*/mGlasses.getNSF5_S1());
	SphericalElement S10(/*radius*/ 40.0, /*semi height*/semiHeight, /*point*/{ 0.0,0.0,100.0 }, /*direction*/{ 0.0,0.0,  1.0 }, /*refractive index A*/ mGlasses.getNSF5_S1(), /*refractive index B*/mGlasses.getAir());

	SphericalElement S11(/*radius*/ 20.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,105.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF10_S1());
	SphericalElement S12(/*radius*/ 20.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,110.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNBK10_S1(), /*refractive index B*/mGlasses.getNSF10_S1());
	SphericalElement S13(/*radius*/ 100.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,115.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK10_S1());

	SphericalElement S14(/*radius*/ 25.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,120.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF5_S1());
	SphericalElement S15(/*radius*/ 20.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,125.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getNSF5_S1(), /*refractive index B*/mGlasses.getNBK10_S1());
	SphericalElement S16(/*radius*/ 20.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,130.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK10_S1());

	SphericalElement S17(/*radius*/ 15.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,135.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNLAF2_S1());
	SphericalElement S18(/*radius*/ 50.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,140.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNLAF2_S1());

	SphericalElement S19(/*radius*/ 15.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,145.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF57_S1());
	SphericalElement S20(/*radius*/ 200.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,150.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF57_S1());

	PlanElement S21(/*semi height*/ 99.0, /*point*/{ 0.0,0.0,155.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getAir());

	// **********************************
	// set parameter variable
	S2.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S7.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S10.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S13.setParameterPointZ(/*min value*/ 1.0, /*max value*/ 80.0, 0.0, typeModifierVariable);
	S16.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	// **********************************

	surfacePtr S0_ptr = S0.clone();
	surfacePtr S1_ptr = S1.clone();
	surfacePtr S2_ptr = S2.clone();
	surfacePtr S3_ptr = S3.clone();
	surfacePtr S4_ptr = S4.clone();
	surfacePtr S5_ptr = S5.clone();
	surfacePtr S6_ptr = S6.clone();
	surfacePtr S7_ptr = S7.clone();
	surfacePtr S8_ptr = S8.clone();
	surfacePtr S9_ptr = S9.clone();
	surfacePtr S10_ptr = S10.clone();
	surfacePtr S11_ptr = S11.clone();
	surfacePtr S12_ptr = S12.clone();
	surfacePtr S13_ptr = S13.clone();
	surfacePtr S14_ptr = S14.clone();
	surfacePtr S15_ptr = S15.clone();
	surfacePtr S16_ptr = S16.clone();
	surfacePtr S17_ptr = S17.clone();
	surfacePtr S18_ptr = S18.clone();
	surfacePtr S19_ptr = S19.clone();
	surfacePtr S20_ptr = S20.clone();
	surfacePtr S21_ptr = S21.clone();


	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr, S2_ptr, S3_ptr, S4_ptr,S5_ptr,S6_ptr, S7_ptr, S8_ptr, S9_ptr, S10_ptr, S11_ptr, S12_ptr, S13_ptr, S14_ptr, S15_ptr, S16_ptr, S17_ptr, S18_ptr, S19_ptr, S20_ptr, S21_ptr, };
	std::vector<interaction_ptr> interactions_ptr{ mDoNot.clone(),mRefrac.clone(),mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(),mRefrac.clone(),mRefrac.clone(),mRefrac.clone(),mRefrac.clone(),mRefrac.clone(),mRefrac.clone(),mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };


	//	build optical system
	OpticalSystemElement optSystemElement(opticalSystem_ptr, interactions_ptr);
	oftenUse::print(optSystemElement, 550.0);
	// save the start system
	std::string location = "../tests/testCompareTOMandZemaxOptimizer/E11";
	inportExportData::saveOpticalSystemAsTXT(optSystemElement, 550.0, location, "start_E11");

	// check ref indexes
	bool checkRefIndexes = oftenUse::checkRefractivIndex(optSystemElement);
	workTheSystem.push_back(checkRefIndexes);
	// check the start system
	std::vector<real> rms_Zemax{ 344.627, 334.488, 324.241 };
	bool test = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, mField_vec, mWavelength_FdV_vec, rms_Zemax, mTolerance, compareTOM_Zemax::comEqual);
	workTheSystem.push_back(test);

	//** results optimize Zemax
	real field0_RMS_Z = 19.043;
	real field1_RMS_Z = 17.475;
	real field2_RMS_Z = 21.223;
	std::vector<real> rmsZ = { field0_RMS_Z, field1_RMS_Z,field2_RMS_Z };

	// try all optimization methodes
	saveResultsOptimizationMethodes saveResultsE11 = tryAllOptimizationMethodes(optSystemElement, rmsZ);
	mSaveAllResults.push_back(saveResultsE11);

	// save optimized optical system
	exportAllOpticalSystems(location, saveResultsE11);

	bool returnChecker = Math::checkTrueOfVectorElements(workTheSystem);
	return returnChecker;
}

// E12
bool testCompareTOMandZemaxOptimizer::testCompareTOMandZemaxOptimizer_E12()
{
	std::vector<bool> workTheSystem;
	real semiHeight = 7.0;

	ApertureStopElement S0(/* semi height*/2.0, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ mGlasses.getAir());

	SphericalElement S1(/*radius*/ 30.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,35.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNSF66_S1(), /*refractive index B*/mGlasses.getAir());
	SphericalElement S2(/*radius*/ 60.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,40.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getNSF66_S1(), /*refractive index B*/mGlasses.getNLAF2_S1());
	SphericalElement S3(/*radius*/ 15.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,45.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNLAF2_S1());

	SphericalElement S4(/*radius*/ 40.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,50.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBAF10_S1());
	SphericalElement S5(/*radius*/ 20.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,55.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNSF57_S1(), /*refractive index B*/mGlasses.getNBAF10_S1());
	SphericalElement S6(/*radius*/ 40.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,60.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF57_S1());

	SphericalElement S7(/*radius*/ 30.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,65.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S8(/*radius*/ 100.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,70.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getNBK7_S1(), /*refractive index B*/mGlasses.getNSF5_S1());
	SphericalElement S9(/*radius*/ 20.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,75.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getNSF5_S1(), /*refractive index B*/mGlasses.getAir());

	SphericalElement S10(/*radius*/ 20.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,80.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S11(/*radius*/ 100.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,85.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());

	SphericalElement S12(/*radius*/ 50.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,90.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getSF5_S1());
	SphericalElement S13(/*radius*/ 50.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,95.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getSF5_S1());

	PlanElement S14(/*semi height*/ 99.0, /*point*/{ 0.0,0.0,100.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getAir());

	// **********************************
	// set parameter variable
	S1.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S8.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S11.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	// **********************************

	surfacePtr S0_ptr = S0.clone();
	surfacePtr S1_ptr = S1.clone();
	surfacePtr S2_ptr = S2.clone();
	surfacePtr S3_ptr = S3.clone();
	surfacePtr S4_ptr = S4.clone();
	surfacePtr S5_ptr = S5.clone();
	surfacePtr S6_ptr = S6.clone();
	surfacePtr S7_ptr = S7.clone();
	surfacePtr S8_ptr = S8.clone();
	surfacePtr S9_ptr = S9.clone();
	surfacePtr S10_ptr = S10.clone();
	surfacePtr S11_ptr = S11.clone();
	surfacePtr S12_ptr = S12.clone();
	surfacePtr S13_ptr = S13.clone();
	surfacePtr S14_ptr = S14.clone();

	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr, S2_ptr, S3_ptr, S4_ptr,S5_ptr,S6_ptr, S7_ptr, S8_ptr, S9_ptr, S10_ptr, S11_ptr, S12_ptr, S13_ptr, S14_ptr };
	std::vector<interaction_ptr> interactions_ptr{ mDoNot.clone(),mRefrac.clone(),mRefrac.clone(),mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(),mRefrac.clone(),mRefrac.clone(),mRefrac.clone(), mAbsorb.clone() };


	//	build optical system
	OpticalSystemElement optSystemElement(opticalSystem_ptr, interactions_ptr);
	oftenUse::print(optSystemElement, 550.0);
	// save the start system
	std::string location = "../tests/testCompareTOMandZemaxOptimizer/E12";
	inportExportData::saveOpticalSystemAsTXT(optSystemElement, 550.0, location, "start_E12");

	// check ref indexes
	bool checkRefIndexes = oftenUse::checkRefractivIndex(optSystemElement);
	workTheSystem.push_back(checkRefIndexes);
	// check the start system
	std::vector<real> rms_Zemax{ 650.913, 656.989, 662.980 };
	bool test = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, mField_vec, mWavelength_FdV_vec, rms_Zemax, mTolerance, compareTOM_Zemax::comEqual);
	workTheSystem.push_back(test);


	//** results optimize Zemax
	real field0_RMS_Z = 13.289;
	real field1_RMS_Z = 14.254;
	real field2_RMS_Z = 18.983;
	std::vector<real> rmsZ = { field0_RMS_Z, field1_RMS_Z,field2_RMS_Z };

	// try all optimization methodes
	saveResultsOptimizationMethodes saveResultsE12 = tryAllOptimizationMethodes(optSystemElement, rmsZ);
	mSaveAllResults.push_back(saveResultsE12);

	// save optimized optical system
	exportAllOpticalSystems(location, saveResultsE12);

	bool returnChecker = Math::checkTrueOfVectorElements(workTheSystem);
	return returnChecker;
}

// E13
bool testCompareTOMandZemaxOptimizer::testCompareTOMandZemaxOptimizer_E13()
{
	std::vector<bool> workTheSystem;
	real semiHeight = 8.0;

	ApertureStopElement S0(/* semi height*/2.0, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ mGlasses.getAir());

	SphericalElement S1(/*radius*/ 30.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,35.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNSF66_S1(), /*refractive index B*/mGlasses.getAir());
	SphericalElement S2(/*radius*/ 60.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,40.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getNSF66_S1(), /*refractive index B*/mGlasses.getNLAF2_S1());
	SphericalElement S3(/*radius*/ 15.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,45.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNLAF2_S1());

	SphericalElement S4(/*radius*/ 40.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,50.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBAF10_S1());
	SphericalElement S5(/*radius*/ 20.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,55.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNSF57_S1(), /*refractive index B*/mGlasses.getNBAF10_S1());
	SphericalElement S6(/*radius*/ 40.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,60.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF57_S1());

	SphericalElement S7(/*radius*/ 30.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,65.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S8(/*radius*/ 100.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,70.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getNBK7_S1(), /*refractive index B*/mGlasses.getNSF5_S1());
	SphericalElement S9(/*radius*/ 20.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,75.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getNSF5_S1(), /*refractive index B*/mGlasses.getAir());

	SphericalElement S10(/*radius*/ 20.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,80.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S11(/*radius*/ 100.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,85.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getSF5_S1(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S12(/*radius*/ 100.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,90.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getSF5_S1());

	SphericalElement S13(/*radius*/ 50.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,95.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getSF5_S1());
	SphericalElement S14(/*radius*/ 50.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,100.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNBK7_S1(), /*refractive index B*/mGlasses.getSF5_S1());
	SphericalElement S15(/*radius*/ 50.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,105.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getNBK7_S1(), /*refractive index B*/mGlasses.getAir());

	PlanElement S16(/*semi height*/ 99.0, /*point*/{ 0.0,0.0,115.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getAir());

	// **********************************
	// set parameter variable
	S1.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S2.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S9.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S12.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S15.setParameterPointZ(/*min value*/ 5.0, /*max value*/ 50.0, 0.0, typeModifierVariable);
	// **********************************

	surfacePtr S0_ptr = S0.clone();
	surfacePtr S1_ptr = S1.clone();
	surfacePtr S2_ptr = S2.clone();
	surfacePtr S3_ptr = S3.clone();
	surfacePtr S4_ptr = S4.clone();
	surfacePtr S5_ptr = S5.clone();
	surfacePtr S6_ptr = S6.clone();
	surfacePtr S7_ptr = S7.clone();
	surfacePtr S8_ptr = S8.clone();
	surfacePtr S9_ptr = S9.clone();
	surfacePtr S10_ptr = S10.clone();
	surfacePtr S11_ptr = S11.clone();
	surfacePtr S12_ptr = S12.clone();
	surfacePtr S13_ptr = S13.clone();
	surfacePtr S14_ptr = S14.clone();
	surfacePtr S15_ptr = S15.clone();
	surfacePtr S16_ptr = S16.clone();

	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr, S2_ptr, S3_ptr, S4_ptr,S5_ptr,S6_ptr, S7_ptr, S8_ptr, S9_ptr, S10_ptr, S11_ptr, S12_ptr, S13_ptr, S14_ptr,S15_ptr,S16_ptr };
	std::vector<interaction_ptr> interactions_ptr{ mDoNot.clone(),mRefrac.clone(),mRefrac.clone(),mRefrac.clone(),mRefrac.clone(), mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(),mRefrac.clone(),mRefrac.clone(),mRefrac.clone(), mAbsorb.clone() };


	//	build optical system
	OpticalSystemElement optSystemElement(opticalSystem_ptr, interactions_ptr);
	oftenUse::print(optSystemElement, 550.0);
	// save the start system
	std::string location = "../tests/testCompareTOMandZemaxOptimizer/E13";
	inportExportData::saveOpticalSystemAsTXT(optSystemElement, 550.0, location, "start_E13");

	// check ref indexes
	bool checkRefIndexes = oftenUse::checkRefractivIndex(optSystemElement);
	workTheSystem.push_back(checkRefIndexes);
	// check the start system
	std::vector<real> rms_Zemax{ 1631.07, 1633.85, 1636.55 };
	bool test = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, mField_vec, mWavelength_FdV_vec, rms_Zemax, mTolerance, compareTOM_Zemax::comEqual);
	workTheSystem.push_back(test);


	//** results optimize Zemax
	real field0_RMS_Z = 7.961;
	real field1_RMS_Z = 11.688;
	real field2_RMS_Z = 13.980;
	std::vector<real> rmsZ = { field0_RMS_Z, field1_RMS_Z,field2_RMS_Z };

	// try all optimization methodes
	saveResultsOptimizationMethodes saveResultsE13 = tryAllOptimizationMethodes(optSystemElement, rmsZ);
	mSaveAllResults.push_back(saveResultsE13);

	// save optimized optical system
	exportAllOpticalSystems(location, saveResultsE13);

	bool returnChecker = Math::checkTrueOfVectorElements(workTheSystem);
	return returnChecker;
}

// E14
bool testCompareTOMandZemaxOptimizer::testCompareTOMandZemaxOptimizer_E14()
{
	std::vector<bool> workTheSystem;
	real semiHeight = 8.0;
	ApertureStopElement S0(/* semi height*/2.0, /*point*/{ 0.0,0.0,25.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ mGlasses.getAir());

	SphericalElement S1(/*radius*/ 30.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ mGlasses.getNSF66_S1(), /*refractive index B*/mGlasses.getAir());
	SphericalElement S2(/*radius*/ 40.0, /*semi height*/semiHeight, /*point*/{ 0.0,0.0,35.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNLAF2_S1(), /*refractive index B*/mGlasses.getNSF66_S1());
	SphericalElement S3(/*radius*/ 20.0, /*semi height*/semiHeight, /*point*/{ 0.0,0.0,40.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNLAF2_S1());

	SphericalElement S4(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,45.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBAF10_S1());
	SphericalElement S5(/*radius*/ 40.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,50.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNSF57_S1(), /*refractive index B*/mGlasses.getNBAF10_S1());
	SphericalElement S6(/*radius*/ 50.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,55.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF57_S1());

	SphericalElement S7(/*radius*/ 40.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,60.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S8(/*radius*/ 30.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,65.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNSF5_S1(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S9(/*radius*/ 50.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,70.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getNSF5_S1(), /*refractive index B*/mGlasses.getAir());

	SphericalElement S10(/*radius*/ 20.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,75.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S11(/*radius*/ 15.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,80.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNSF5_S1(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S12(/*radius*/ 40.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,85.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF5_S1());

	SphericalElement S13(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,90.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK10_S1());
	SphericalElement S14(/*radius*/ 90.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,95.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK10_S1());

	PlanElement S15(/*semi height*/ 99.0, /*point*/{ 0.0,0.0,105.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getAir());

	// **********************************
	// set parameter variable
	S1.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S7.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S11.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S14.setParameterPointZ(/*min value*/ 5.0, /*max value*/ 40.0, 0.0, typeModifierVariable);
	// **********************************

	surfacePtr S0_ptr = S0.clone();
	surfacePtr S1_ptr = S1.clone();
	surfacePtr S2_ptr = S2.clone();
	surfacePtr S3_ptr = S3.clone();
	surfacePtr S4_ptr = S4.clone();
	surfacePtr S5_ptr = S5.clone();
	surfacePtr S6_ptr = S6.clone();
	surfacePtr S7_ptr = S7.clone();
	surfacePtr S8_ptr = S8.clone();
	surfacePtr S9_ptr = S9.clone();
	surfacePtr S10_ptr = S10.clone();
	surfacePtr S11_ptr = S11.clone();
	surfacePtr S12_ptr = S12.clone();
	surfacePtr S13_ptr = S13.clone();
	surfacePtr S14_ptr = S14.clone();
	surfacePtr S15_ptr = S15.clone();

	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr, S2_ptr, S3_ptr, S4_ptr,S5_ptr,S6_ptr, S7_ptr, S8_ptr, S9_ptr, S10_ptr, S11_ptr, S12_ptr, S13_ptr, S14_ptr, S15_ptr };
	std::vector<interaction_ptr> interactions_ptr{ mDoNot.clone(),mRefrac.clone(),mRefrac.clone(),mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(),mRefrac.clone(),mRefrac.clone(),mRefrac.clone(), mAbsorb.clone() };


	//	build optical system
	OpticalSystemElement optSystemElement(opticalSystem_ptr, interactions_ptr);
	oftenUse::print(optSystemElement, 550.0);
	// save the start system
	std::string location = "../tests/testCompareTOMandZemaxOptimizer/E14";
	inportExportData::saveOpticalSystemAsTXT(optSystemElement, 550.0, location, "start_E14");

	// check ref indexes
	bool checkRefIndexes = oftenUse::checkRefractivIndex(optSystemElement);
	workTheSystem.push_back(checkRefIndexes);
	// check the start system
	std::vector<real> rms_Zemax{ 422.633, 457.558, 493.373 };
	bool test = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, mField_vec, mWavelength_FdV_vec, rms_Zemax, mTolerance, compareTOM_Zemax::comEqual);
	workTheSystem.push_back(test);

	//** results optimize Zemax
	real field0_RMS_Z = 22.709;
	real field1_RMS_Z = 16.336;
	real field2_RMS_Z = 31.471;
	std::vector<real> rmsZ = { field0_RMS_Z, field1_RMS_Z,field2_RMS_Z };

	// try all optimization methodes
	saveResultsOptimizationMethodes saveResultsE14 = tryAllOptimizationMethodes(optSystemElement, rmsZ);
	mSaveAllResults.push_back(saveResultsE14);

	// save optimized optical system
	exportAllOpticalSystems(location, saveResultsE14);


	bool returnChecker = Math::checkTrueOfVectorElements(workTheSystem);
	return returnChecker;
}
