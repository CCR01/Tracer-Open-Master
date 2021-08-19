#include "TestGlobalOPD.h"

// surfaces
#include "..\..\LowLevelTracing\Surfaces\SphericalSurface_LLT.h"
#include "..\..\LowLevelTracing\Surfaces\ApertureStop_LLT.h"

#include "..\..\FillAptertureStop\FillApertureStop.h"

#include "..\..\Analyse\OpticalPathDifference.h"

#include "..\..\Analyse\CardinalPoints.h"

#include "..\..\oftenUseNamespace\oftenUseNamespace.h"

#include "..\..\Analyse\Spot.h"

#include "..\..\RayAiming\RayAiming.h"

#include "..\..\Inport_Export_Data\Inport_Export_Data.h"

typedef std::shared_ptr<SurfaceIntersectionRay_LLT> surfacePtr;
typedef std::shared_ptr< InteractionRay_LLT > interaction_ptr;


TestGlobalOPD::TestGlobalOPD() { loadImportantparameter(); };
TestGlobalOPD::~TestGlobalOPD() {};

// load important staff
void TestGlobalOPD::loadImportantparameter()
{
	mLight550.setWavelength(550.0);
	mLight550.setTypeLight(typeLight::typeLightRay);
	mLight550.setIntensity(1.0);
	mLight550.setJonesVector({ 0.0,0.0,0.0,0.0 });


	// Ray in the field y = -1
	// single ray tracing
	Ray_LLT chief_Field_negY1({ 0.0,-1.0,0.0 }, { 0.0,1.0,30.0 }, 1.0);
	mChiefLightRay_Field_negY1.setLight_LLT(mLight550);
	mChiefLightRay_Field_negY1.setRay_LLT(chief_Field_negY1);
	mChiefLightRay_Field_negY1.setIsAlive(true);


	Ray_LLT rayE0_0_Field_negY1({ 0.0,-1.0,0.0 }, { -0.5,1.0,30.0 }, 1.0);
	Ray_LLT rayE0_1_Field_negY1({ 0.0,-1.0,0.0 }, { 0.0,2.0,30.0 }, 1.0);
	Ray_LLT rayE0_2_Field_negY1({ 0.0,-1.0,0.0 }, { 1.0,1.0,30.0 }, 1.0);
	Ray_LLT rayE0_3_Field_negY1({ 0.0,-1.0,0.0 }, { -1.0,1.0,30.0 }, 1.0);
	
	LightRayStruct lightRayE0_0_Field_negY1(mLight550, rayE0_0_Field_negY1, 1);
	LightRayStruct lightRayE0_1_Field_negY1(mLight550, rayE0_1_Field_negY1, 1);
	LightRayStruct lightRayE0_2_Field_negY1(mLight550, rayE0_2_Field_negY1, 1);
	LightRayStruct lightRayE0_3_Field_negY1(mLight550, rayE0_3_Field_negY1, 1);

	//__ start check OPD in the field (y=-1) for some rays
	mVecLightRaysE0_Field_negY1.push_back(lightRayE0_0_Field_negY1);
	mVecLightRaysE0_Field_negY1.push_back(lightRayE0_1_Field_negY1);
	mVecLightRaysE0_Field_negY1.push_back(lightRayE0_2_Field_negY1);
	mVecLightRaysE0_Field_negY1.push_back(lightRayE0_3_Field_negY1);

	////exit pupil
	mExitPupilE0.setSemiHeight(/*semiHeight*/20.0);
	mExitPupilE0.setPoint(/*point*/{ 0.0,0.0,240.39052680563 });
	mExitPupilE0.setDirection( /*direction*/{ 0.0,0.0,1.0 });
	mExitPupilE0.setRefractiveIndexSide_A( /*refractiveSideA*/ 1.0);
	mExitPupilE0.setRefractiveIndexSide_B(/*refractiveSideB*/ 1.0);

	mExitPupilE0_ptr = mExitPupilE0.clone();

	mGlasCat.loadGlassCatalog_Schott();
};

typedef std::shared_ptr< SurfaceIntersectionRay_LLT > surfacePtr;
typedef std::shared_ptr< InteractionRay_LLT > interaction_ptr;

bool TestGlobalOPD::checkGlobalOPD_superFunction_obj()
{
	// work the system
	std::vector<bool> workTheSystem;

	bool checkFillMatrixWithOPDs_E0 = checkFillOPDinMatrix_E0_obj();
	workTheSystem.push_back(checkFillMatrixWithOPDs_E0);
	
	// check fill OPD in Matrix (EP before ima surface)
	bool checkFillMatrixWithOPDs_E1 = checkFillOPDinMatrix_E1_obj();
	workTheSystem.push_back(checkFillMatrixWithOPDs_E1);

	// test upsamling OPD
	bool checkUmsamplingOPD = testUpsamplingOPD();
	workTheSystem.push_back(checkUmsamplingOPD);


	bool checkOPD_superFct = Math::checkTrueOfVectorElements(workTheSystem);
	return checkOPD_superFct;
	
}

bool TestGlobalOPD::checkGlobalOPD_superFunction_inf()
{
	// work the system
	std::vector<bool> workTheSystem;

	//// check fill OPD in Matrix (EP behind ima surface)
	//bool chE2 = checkFillOPDinMatrix_E2_inf();
	//workTheSystem.push_back(chE2);

	//// check fill OPD in Matrix (EP behind ima surface)
	//bool chE3 = checkFillOPDinMatrix_E3_inf();
	//workTheSystem.push_back(chE3);

	// check fill OPD in Matrix (EP behind ima surface)
	bool chE4 = checkFillOPDinMatrix_E4_inf();
	workTheSystem.push_back(chE4);

	bool checkOPD_superFct = Math::checkTrueOfVectorElements(workTheSystem);
	return checkOPD_superFct;
}


// check fill OPD in Matrix
bool TestGlobalOPD::checkFillOPDinMatrix_E0_obj()
{
	// work the system
	std::vector<bool> workTheSystem;

	//all the surfaces
	ApertureStop_LLT S0(/*semi height*/ 1.0, /*point*/{ 0.0,0.0,5.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index*/ 1.0);
	SphericalSurface_LLT S1(/*radius*/30.0, /*semiHeight*/10.0, /*Apex of the sphere*/{ 0.0, 0.0, 15.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
	SphericalSurface_LLT S2(/*radius*/30.0, /*semiHeight*/10.0, /*Apex of the sphere*/{ 0.0, 0.0, 25.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
	SphericalSurface_LLT S3(/*radius*/15.0, /*semiHeight*/10.0, /*Apex of the sphere*/{ 0.0, 0.0, 35.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
	SphericalSurface_LLT S4(/*radius*/15.0, /*semiHeight*/10.0, /*Apex of the sphere*/{ 0.0, 0.0, 45.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
	PlanGeometry_LLT S5(/*semiHeight*/5.0, /*point*/{ 0.0,0.0,60.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiveSideA*/ 1.0, /*refractiveSideB*/ 1.0);

	std::vector< surfacePtr> surfacePtr_vec = {S0.clone(),S1.clone(),S2.clone() ,S3.clone(),S4.clone(),S5.clone()};
	std::vector< interaction_ptr > interac_ptr = {mDoNothing.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(),mRefrac.clone(), mAbsorb.clone() };

	OpticalSystem_LLT optSys;
	optSys.fillOptSysWithSurfaceAndInteractions(surfacePtr_vec, interac_ptr);

	// test the start system
	bool testStartSystem = oftenUse::checkOptSysLLT_Equal_Better_Zemax(optSys, { 0.0,0.0,0.0 }, 370.916, 0.01, compareTOM_Zemax::comEqual);
	workTheSystem.push_back(testStartSystem);

	// fill aperture stop with points
	FillApertureStop fillAS;
	infosAS infAS = optSys.getInforAS();
	std::vector<VectorStructR3> pointsInAS = fillAS.fillAS_withPoints(6, infAS.getPointAS(),infAS.getDirAS(),infAS.getSemiHeightAS());
	
	// ray aimingb
	RayAiming rayAiming;
	std::vector<LightRayStruct> aimedLightRays = rayAiming.rayAimingMany_obj_complete(optSys, pointsInAS, { 0.0,0.0,0.0 }, mLight550);

	unsigned int sizeMatrix31 = 31;
	OPD opd_31(/*optical system*/ optSys, /*aimed light ray*/ aimedLightRays, /*obj inf*/objectPoint_inf_obj::obj, sizeMatrix31);
	opd_31.calcGlobalOPD_new();
	// matrix wit global OPD
	cv::Mat globalOPD_00_31 = opd_31.getGlobalOPD_deepCopy();

	// hier sollst du dann eine Funktion schreiben, die über Bilineare Filterung die innere Matrix auffüllt.
	// --> Linda

	// save global OPD 31 in csv
	std::string location31 = "C:/Tracer-Open-Master/tests/testGlobalOPD/refOPDs/checkFillOPDinMatrix";
	std::string fileName31 = "calc00_31";
	inportExportData::exportCV_MatToExcel(globalOPD_00_31, location31, fileName31);
		

	unsigned int sizeMatrix41 = 41;
	OPD opd_41(/*optical system*/ optSys, /*aimed light ray*/ aimedLightRays, /*obj inf*/objectPoint_inf_obj::obj, sizeMatrix41);
	opd_41.calcGlobalOPD_new();
	// matrix wit global OPD
	cv::Mat globalOPD_00_41 = opd_41.getGlobalOPD_deepCopy();

	// save global OPD 41 in csv
	std::string location41 = "C:/Tracer-Open-Master/tests/testGlobalOPD/refOPDs/checkFillOPDinMatrix";
	std::string fileName41 = "calc00_41";
	inportExportData::exportCV_MatToExcel(globalOPD_00_41, location41, fileName41);

	bool check0 = compareResultsCalcSingleAndGlobalOPDsoptSys_obj(/*opt sys*/ optSys,/*start point ray*/{ 0.0,0.0,0.0 }, /*PX*/ 0.7, /*PY*/ 0.4,/*light*/ mLight550, 0.01);
	workTheSystem.push_back(check0);

	bool check1 = compareResultsCalcSingleAndGlobalOPDsoptSys_obj(/*opt sys*/ optSys,/*start point ray*/{ 0.5,1.0,0.0 }, /*PX*/ 0.3, /*PY*/ -0.3,/*light*/ mLight550, 0.01);
	workTheSystem.push_back(check1);

	bool check2 = compareResultsCalcSingleAndGlobalOPDsoptSys_obj(/*opt sys*/ optSys,/*start point ray*/{ -0.2,-1.0,0.0 }, /*PX*/ 0.5, /*PY*/ -0.5,/*light*/ mLight550, 0.01);
	workTheSystem.push_back(check2);

	bool check3 = compareResultsCalcSingleAndGlobalOPDsoptSys_obj(/*opt sys*/ optSys,/*start point ray*/{ -0.8,-0.5,0.0 }, /*PX*/ 0.3, /*PY*/ 0.4,/*light*/ mLight550, 0.01);
	workTheSystem.push_back(check3);

	bool check4 = compareResultsCalcSingleAndGlobalOPDsoptSys_obj(/*opt sys*/ optSys,/*start point ray*/{ 0.2, 0.8,0.0 }, /*PX*/ -0.6, /*PY*/ -0.3,/*light*/ mLight550, 0.01);
	workTheSystem.push_back(check4);

	bool workReturn = Math::checkTrueOfVectorElements(workTheSystem);
	return workReturn;
}

// check fill OPD in Matrix (EP before ima surface)
bool TestGlobalOPD::checkFillOPDinMatrix_E1_obj()
{
	// work the system
	std::vector<bool> workTheSystem;

	//all the surfaces
	ApertureStop_LLT S0(/*semi height*/ 1.0, /*point*/{ 0.0,0.0,20.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index*/ 1.0);
	SphericalSurface_LLT S1(/*radius*/100.0, /*semiHeight*/5.0, /*Apex of the sphere*/{ 0.0, 0.0, 25.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.5, /*refIndexSideB*/1.0);
	SphericalSurface_LLT S2(/*radius*/100.0, /*semiHeight*/5.0, /*Apex of the sphere*/{ 0.0, 0.0, 35.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.5, /*refIndexSideB*/1.0);
	SphericalSurface_LLT S3(/*radius*/30.0, /*semiHeight*/5.0, /*Apex of the sphere*/{ 0.0, 0.0, 45.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.6);
	SphericalSurface_LLT S4(/*radius*/30.0, /*semiHeight*/5.0, /*Apex of the sphere*/{ 0.0, 0.0, 55.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.6);
	PlanGeometry_LLT S5(/*semiHeight*/5.0, /*point*/{ 0.0,0.0,65.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiveSideA*/ 1.0, /*refractiveSideB*/ 1.0);

	std::vector< surfacePtr> surfacePtr_vec = { S0.clone(),S1.clone(),S2.clone() ,S3.clone(),S4.clone(),S5.clone() };
	std::vector< interaction_ptr > interac_ptr = { mDoNothing.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(),mRefrac.clone(), mAbsorb.clone() };

	OpticalSystem_LLT optSys;
	optSys.fillOptSysWithSurfaceAndInteractions(surfacePtr_vec, interac_ptr);

	// test the start system
	bool testStartSystem = oftenUse::checkOptSysLLT_Equal_Better_Zemax(optSys, { 0.0,0.0,0.0 }, 1592.73, 0.01, compareTOM_Zemax::comEqual);
	workTheSystem.push_back(testStartSystem);

	// fill aperture stop with points
	FillApertureStop fillAS;
	infosAS infAS = optSys.getInforAS();
	std::vector<VectorStructR3> pointsInAS = fillAS.fillAS_withPoints(6, infAS.getPointAS(), infAS.getDirAS(), infAS.getSemiHeightAS());


	OPD testOPDE1;

	real OPD0505 = testOPDE1.OPD_singelRay_obj(optSys, { 0.0,0.0,0.0 }, 0.5, 0.5, mLight550);
	real refOPD0505 = -34.982;
	bool checkOPD0505 = Math::compareTwoNumbers_tolerance(OPD0505, refOPD0505, 0.01);
	workTheSystem.push_back(checkOPD0505);
	
	real OPDneg03Neg07 = testOPDE1.OPD_singelRay_obj(optSys, { 0.0,0.0,0.0 }, -0.3, -0.7, mLight550);
	real refOPDneg03neg07 = -40.653;
	bool checkOPDneg03neg07 = Math::compareTwoNumbers_tolerance(OPDneg03Neg07, refOPDneg03neg07, 0.01);
	workTheSystem.push_back(checkOPDneg03neg07);

	// ray aiming
	RayAiming rayAiming;
	std::vector<LightRayStruct> aimedLightRays = rayAiming.rayAimingMany_obj_complete(optSys, pointsInAS, { 0.0,0.0,0.0 }, mLight550);

	unsigned int sizeMatrix31 = 31;
	OPD opd_31(/*optical system*/ optSys, /*aimed light ray*/ aimedLightRays, /*obj inf*/objectPoint_inf_obj::obj, sizeMatrix31);
	opd_31.calcGlobalOPD_new();
	// matrix wit global OPD
	cv::Mat globalOPD_00_31 = opd_31.getGlobalOPD_deepCopy();

	// save global OPD 31 in csv
	std::string location31 = "../tests/testGlobalOPD/refOPDs/checkFillOPDinMatrix";
	std::string fileName31 = "calc00_E1_31";
	inportExportData::exportCV_MatToExcel(globalOPD_00_31, location31, fileName31);

	// test 1
	Ray_LLT ray0({ 0.0,0.0,0.0 }, { 0.707,0.707,20 }, 1);
	LightRayStruct lightRay0(mLight550, ray0, true);
	std::vector<LightRayStruct> aimedLightRay0{ lightRay0 };
	OPD opd_0(/*optical system*/ optSys, /*aimed light ray*/ aimedLightRay0, /*obj inf*/objectPoint_inf_obj::obj, 1);
	opd_0.calcGlobalOPD_new();
	cv::Mat testOPD0 = opd_0.getGlobalOPD_deepCopy();
	real checkOPD0 = testOPD0.at<real>(0, 0);

	real refOPD0 = -70.744;
	bool checker0 = Math::compareTwoNumbers_tolerance(checkOPD0, refOPD0, 0.01);


	bool check0 = compareResultsCalcSingleAndGlobalOPDsoptSys_obj(/*opt sys*/ optSys,/*start point ray*/{ 0.0,0.0,0.0 }, /*PX*/ 0.7, /*PY*/ 0.4,/*light*/ mLight550, 0.01);
	workTheSystem.push_back(check0);

	bool check1 = compareResultsCalcSingleAndGlobalOPDsoptSys_obj(/*opt sys*/ optSys,/*start point ray*/{ 0.5,1.0,0.0 }, /*PX*/ 0.3, /*PY*/ -0.3,/*light*/ mLight550, 0.01);
	workTheSystem.push_back(check1);

	bool check2 = compareResultsCalcSingleAndGlobalOPDsoptSys_obj(/*opt sys*/ optSys,/*start point ray*/{ -0.2,-1.0,0.0 }, /*PX*/ 0.5, /*PY*/ -0.5,/*light*/ mLight550, 0.01);
	workTheSystem.push_back(check2);

	bool check3 = compareResultsCalcSingleAndGlobalOPDsoptSys_obj(/*opt sys*/ optSys,/*start point ray*/{ -1.2,-1.0,0.0 }, /*PX*/ 0.3, /*PY*/ 0.4,/*light*/ mLight550, 0.01);
	workTheSystem.push_back(check3);

	bool check4 = compareResultsCalcSingleAndGlobalOPDsoptSys_obj(/*opt sys*/ optSys,/*start point ray*/{ 0.2, 0.8,0.0 }, /*PX*/ -0.6, /*PY*/ -0.3,/*light*/ mLight550, 0.01);
	workTheSystem.push_back(check4);

	bool workReturn = Math::checkTrueOfVectorElements(workTheSystem);
	return workReturn;

}

bool TestGlobalOPD::checkFillOPDinMatrix_E2_inf()
{
	// work the system
	std::vector<bool> workTheSystem;
	real tolerance = 0.01;

	SphericalSurface_LLT S0(/*radius*/100.0, /*semiHeight*/10.0, /*Apex of the sphere*/{ 0.0, 0.0, 0.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
	SphericalSurface_LLT S1(/*radius*/100.0, /*semiHeight*/10.0, /*Apex of the sphere*/{ 0.0, 0.0, 10.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.5, /*refIndexSideB*/1.0);
	ApertureStop_LLT S2(/*semi height*/ 5.0, /*point*/{ 0.0,0.0,20.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ 1.0);
	SphericalSurface_LLT S3(/*radius*/33.0, /*semiHeight*/10.0, /*Apex of the sphere*/{ 0.0, 0.0, 70.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.6);
	SphericalSurface_LLT S4(/*radius*/50.0, /*semiHeight*/10.0, /*Apex of the sphere*/{ 0.0, 0.0, 80.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.6);
	PlanGeometry_LLT S5(/*semiHeight*/10.0, /*point*/{ 0.0,0.0,110.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiveSideA*/ 1.0, /*refractiveSideB*/ 1.0);

	std::vector<surfacePtr> surfaces_vec = { S0.clone(), S1.clone(), S2.clone(), S3.clone(), S4.clone(), S5.clone() };
	std::vector<interaction_ptr> interaction_vec{ mRefrac.clone(), mRefrac.clone(), mDoNothing.clone(), mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };

	// build the optical system
	OpticalSystem_LLT OptSys;
	OptSys.fillOptSysWithSurfaceAndInteractions(surfaces_vec, interaction_vec);

	// check the start system
	std::vector<real> fieldAngle_X{ 0.0, 1.0, -2.0 };
	std::vector<real> fieldAngle_Y{ 0.0, 1.0, -2.0 };
	std::vector<real> rms_vec{ 21.191, 40.500, 81.858 };

	bool checkStartSys = oftenUse::checkOptSysLLT_Equal_Better_Zemax(OptSys, fieldAngle_X, fieldAngle_Y, rms_vec, 0.01, compareTOM_Zemax::comEqual);
	workTheSystem.push_back(checkStartSys);

	
	real angle_X_0 = 0.0;
	real angle_Y_0 = 1.0;
	real pupilPos_X_0 = 0.5;
	real pupilPos_Y_0 = 0.5;
	bool check_0 = compareResultsCalcSingleAndGlobalOPDsoptSys_inf(/*opt sys*/ OptSys,/*angle X*/ angle_X_0, /*angle Y*/ angle_Y_0, /*PX*/ pupilPos_X_0, /*PY*/ pupilPos_Y_0,/*light*/ mLight550, tolerance);
	workTheSystem.push_back(check_0);

	real angle_X_1 = 0.5;
	real angle_Y_1 = -0.3;
	real pupilPos_X_1 = 0.7;
	real pupilPos_Y_1 = -0.2;
	bool check_1 = compareResultsCalcSingleAndGlobalOPDsoptSys_inf(/*opt sys*/ OptSys,/*angle X*/ angle_X_1, /*angle Y*/ angle_Y_1, /*PX*/ pupilPos_X_1, /*PY*/ pupilPos_Y_1,/*light*/ mLight550, tolerance);
	workTheSystem.push_back(check_1);

	real angle_X_2 = -1.2;
	real angle_Y_2 = -0.1;
	real pupilPos_X_2 = -0.6;
	real pupilPos_Y_2 = -0.3;
	bool check_2 = compareResultsCalcSingleAndGlobalOPDsoptSys_inf(/*opt sys*/ OptSys,/*angle X*/ angle_X_2, /*angle Y*/ angle_Y_2, /*PX*/ pupilPos_X_2, /*PY*/ pupilPos_Y_2,/*light*/ mLight550, tolerance);
	workTheSystem.push_back(check_2);

	real angle_X_3 = 1.2;
	real angle_Y_3 = 0.0;
	real pupilPos_X_3 = 0.0;
	real pupilPos_Y_3 = 1.0;
	bool check_3 = compareResultsCalcSingleAndGlobalOPDsoptSys_inf(/*opt sys*/ OptSys,/*angle X*/ angle_X_3, /*angle Y*/ angle_Y_3, /*PX*/ pupilPos_X_3, /*PY*/ pupilPos_Y_3,/*light*/ mLight550, tolerance);
	workTheSystem.push_back(check_3);

	real angle_X_4 = 0.8;
	real angle_Y_4 = 0.7;
	real pupilPos_X_4 = -1.0;
	real pupilPos_Y_4 = 0.0;
	bool check_4 = compareResultsCalcSingleAndGlobalOPDsoptSys_inf(/*opt sys*/ OptSys,/*angle X*/ angle_X_4, /*angle Y*/ angle_Y_4, /*PX*/ pupilPos_X_4, /*PY*/ pupilPos_Y_4,/*light*/ mLight550, tolerance);
	workTheSystem.push_back(check_4);

	real angle_X_5 = 1.5;
	real angle_Y_5 = 1.2;
	real pupilPos_X_5 = -0.8;
	real pupilPos_Y_5 = 0.1;
	bool check_5 = compareResultsCalcSingleAndGlobalOPDsoptSys_inf(/*opt sys*/ OptSys,/*angle X*/ angle_X_5, /*angle Y*/ angle_Y_5, /*PX*/ pupilPos_X_5, /*PY*/ pupilPos_Y_5,/*light*/ mLight550, tolerance);
	workTheSystem.push_back(check_5);


	bool workReturn = Math::checkTrueOfVectorElements(workTheSystem);
	return workReturn;
}

// check fill OPD in Matrix (EP before ima surface)
bool TestGlobalOPD::checkFillOPDinMatrix_E3_inf()
{

	// work the system
	std::vector<bool> workTheSystem;
	real tolerance = 0.01;

	SphericalSurface_LLT S0(/*radius*/50.0, /*semiHeight*/10.0, /*Apex of the sphere*/{ 0.0, 0.0, 0.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
	SphericalSurface_LLT S1(/*radius*/50.0, /*semiHeight*/10.0, /*Apex of the sphere*/{ 0.0, 0.0, 10.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
	ApertureStop_LLT S2(/*semi height*/ 6.0, /*point*/{ 0.0,0.0,20.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ 1.0);
	SphericalSurface_LLT S3(/*radius*/33.0, /*semiHeight*/10.0, /*Apex of the sphere*/{ 0.0, 0.0, 30.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.6);
	SphericalSurface_LLT S4(/*radius*/50.0, /*semiHeight*/10.0, /*Apex of the sphere*/{ 0.0, 0.0, 40.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.6);
	PlanGeometry_LLT S5(/*semiHeight*/10.0, /*point*/{ 0.0,0.0, 50.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiveSideA*/ 1.0, /*refractiveSideB*/ 1.0);

	std::vector<surfacePtr> surfaces_vec = { S0.clone(), S1.clone(), S2.clone(), S3.clone(), S4.clone(), S5.clone() };
	std::vector<interaction_ptr> interaction_vec{ mRefrac.clone(), mRefrac.clone(), mDoNothing.clone(), mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };

	// build the optical system
	OpticalSystem_LLT OptSys;
	OptSys.fillOptSysWithSurfaceAndInteractions(surfaces_vec, interaction_vec);

	// check the start system
	std::vector<real> fieldAngle_X{ 0.0, 1.0, -2.0 };
	std::vector<real> fieldAngle_Y{ 0.0, 1.0, 2.0 };
	std::vector<real> rms_vec{ 62.022, 73.793, 104.284 };

	bool checkStartSys = oftenUse::checkOptSysLLT_Equal_Better_Zemax(OptSys, fieldAngle_X, fieldAngle_Y, rms_vec, 0.01, compareTOM_Zemax::comEqual);
	workTheSystem.push_back(checkStartSys);

	real angle_X_0 = 0.0;
	real angle_Y_0 = 1.0;
	real pupilPos_X_0 = 0.5;
	real pupilPos_Y_0 = 0.5;
	bool check_0 = compareResultsCalcSingleAndGlobalOPDsoptSys_inf(/*opt sys*/ OptSys,/*angle X*/ angle_X_0, /*angle Y*/ angle_Y_0, /*PX*/ pupilPos_X_0, /*PY*/ pupilPos_Y_0,/*light*/ mLight550, tolerance);
	workTheSystem.push_back(check_0);

	real angle_X_1 = 1.0;
	real angle_Y_1 = -1.0;
	real pupilPos_X_1 = 0.3;
	real pupilPos_Y_1 = 0.7;
	bool check_1 = compareResultsCalcSingleAndGlobalOPDsoptSys_inf(/*opt sys*/ OptSys,/*angle X*/ angle_X_1, /*angle Y*/ angle_Y_1, /*PX*/ pupilPos_X_1, /*PY*/ pupilPos_Y_1,/*light*/ mLight550, tolerance);
	workTheSystem.push_back(check_1);

	real angle_X_2 = -1.0;
	real angle_Y_2 = -1.0;
	real pupilPos_X_2 = 1.0;
	real pupilPos_Y_2 = 0.0;
	bool check_2 = compareResultsCalcSingleAndGlobalOPDsoptSys_inf(/*opt sys*/ OptSys,/*angle X*/ angle_X_2, /*angle Y*/ angle_Y_2, /*PX*/ pupilPos_X_2, /*PY*/ pupilPos_Y_2,/*light*/ mLight550, tolerance);
	workTheSystem.push_back(check_2);

	real angle_X_3 = 0.0;
	real angle_Y_3 = -0.3;
	real pupilPos_X_3 = -0.2;
	real pupilPos_Y_3 = 0.4;
	bool check_3 = compareResultsCalcSingleAndGlobalOPDsoptSys_inf(/*opt sys*/ OptSys,/*angle X*/ angle_X_3, /*angle Y*/ angle_Y_3, /*PX*/ pupilPos_X_3, /*PY*/ pupilPos_Y_3,/*light*/ mLight550, tolerance);
	workTheSystem.push_back(check_3);

	real angle_X_4 = 1.2;
	real angle_Y_4 = -1.3;
	real pupilPos_X_4 = -0.9;
	real pupilPos_Y_4 = 0.05;
	bool check_4 = compareResultsCalcSingleAndGlobalOPDsoptSys_inf(/*opt sys*/ OptSys,/*angle X*/ angle_X_4, /*angle Y*/ angle_Y_4, /*PX*/ pupilPos_X_4, /*PY*/ pupilPos_Y_4,/*light*/ mLight550, tolerance);
	workTheSystem.push_back(check_4);

	real angle_X_5 = -0.8;
	real angle_Y_5 = 1.1;
	real pupilPos_X_5 = -0.5;
	real pupilPos_Y_5 = 0.35;
	bool check_5 = compareResultsCalcSingleAndGlobalOPDsoptSys_inf(/*opt sys*/ OptSys,/*angle X*/ angle_X_5, /*angle Y*/ angle_Y_5, /*PX*/ pupilPos_X_5, /*PY*/ pupilPos_Y_5,/*light*/ mLight550, tolerance);
	workTheSystem.push_back(check_5);

	bool workReturn = Math::checkTrueOfVectorElements(workTheSystem);
	return workReturn;

}

bool TestGlobalOPD::checkFillOPDinMatrix_E4_inf()
{
	// work the system
	std::vector<bool> workTheSystem;
	real tolerance = 0.01;


	SphericalSurface_LLT S0(/*radius*/100.0, /*semiHeight*/10.0, /*Apex of the sphere*/{ 0.0, 0.0, 0.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.6);
	SphericalSurface_LLT S1(/*radius*/100.0, /*semiHeight*/10.0, /*Apex of the sphere*/{ 0.0, 0.0, 10.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.6);
	ApertureStop_LLT S2(/*semi height*/ 3.0, /*point*/{ 0.0,0.0,20.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ 1.0);
	SphericalSurface_LLT S3(/*radius*/15.0, /*semiHeight*/10.0, /*Apex of the sphere*/{ 0.0, 0.0, 30.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
	SphericalSurface_LLT S4(/*radius*/20.0, /*semiHeight*/10.0, /*Apex of the sphere*/{ 0.0, 0.0, 40.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
	PlanGeometry_LLT S5(/*semiHeight*/10.0, /*point*/{ 0.0,0.0, 50.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiveSideA*/ 1.0, /*refractiveSideB*/ 1.0);

	std::vector<surfacePtr> surfaces_vec = { S0.clone(), S1.clone(), S2.clone(), S3.clone(), S4.clone(), S5.clone() };
	std::vector<interaction_ptr> interaction_vec{ mRefrac.clone(), mRefrac.clone(), mDoNothing.clone(), mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };


	// build the optical system
	OpticalSystem_LLT OptSys;
	OptSys.fillOptSysWithSurfaceAndInteractions(surfaces_vec, interaction_vec);

	// check the start system
	std::vector<real> fieldAngle_X{ 0.0, 0.5, -0.3 };
	std::vector<real> fieldAngle_Y{ 0.0, 0.5, -0.3 };
	std::vector<real> rms_vec{ 14.641, 15.113, 14.810 };

	bool checkStartSys = oftenUse::checkOptSysLLT_Equal_Better_Zemax(OptSys, fieldAngle_X, fieldAngle_Y, rms_vec, 0.1, compareTOM_Zemax::comEqual);
	workTheSystem.push_back(checkStartSys);

	real angle_X_0 = 0.0;
	real angle_Y_0 = 0.2;
	real pupilPos_X_0 = 0.5;
	real pupilPos_Y_0 = 0.5;
	bool check_0 = compareResultsCalcSingleAndGlobalOPDsoptSys_inf(/*opt sys*/ OptSys,/*angle X*/ angle_X_0, /*angle Y*/ angle_Y_0, /*PX*/ pupilPos_X_0, /*PY*/ pupilPos_Y_0,/*light*/ mLight550, tolerance);
	workTheSystem.push_back(check_0);

	real angle_X_1 = 0.0;
	real angle_Y_1 = -0.1;
	real pupilPos_X_1 = 0.3;
	real pupilPos_Y_1 = 0.7;
	bool check_1 = compareResultsCalcSingleAndGlobalOPDsoptSys_inf(/*opt sys*/ OptSys,/*angle X*/ angle_X_1, /*angle Y*/ angle_Y_1, /*PX*/ pupilPos_X_1, /*PY*/ pupilPos_Y_1,/*light*/ mLight550, tolerance);
	workTheSystem.push_back(check_1);

	real angle_X_2 = -0.3;
	real angle_Y_2 = -0.1;
	real pupilPos_X_2 = 1.0;
	real pupilPos_Y_2 = 0.0;
	bool check_2 = compareResultsCalcSingleAndGlobalOPDsoptSys_inf(/*opt sys*/ OptSys,/*angle X*/ angle_X_2, /*angle Y*/ angle_Y_2, /*PX*/ pupilPos_X_2, /*PY*/ pupilPos_Y_2,/*light*/ mLight550, tolerance);
	workTheSystem.push_back(check_2);

	real angle_X_3 = 0.2;
	real angle_Y_3 = -0.3;
	real pupilPos_X_3 = -0.2;
	real pupilPos_Y_3 = 0.4;
	bool check_3 = compareResultsCalcSingleAndGlobalOPDsoptSys_inf(/*opt sys*/ OptSys,/*angle X*/ angle_X_3, /*angle Y*/ angle_Y_3, /*PX*/ pupilPos_X_3, /*PY*/ pupilPos_Y_3,/*light*/ mLight550, tolerance);
	workTheSystem.push_back(check_3);

	real angle_X_4 = 0.2;
	real angle_Y_4 = -0.3;
	real pupilPos_X_4 = -0.9;
	real pupilPos_Y_4 = 0.05;
	bool check_4 = compareResultsCalcSingleAndGlobalOPDsoptSys_inf(/*opt sys*/ OptSys,/*angle X*/ angle_X_4, /*angle Y*/ angle_Y_4, /*PX*/ pupilPos_X_4, /*PY*/ pupilPos_Y_4,/*light*/ mLight550, tolerance);
	workTheSystem.push_back(check_4);

	real angle_X_5 = -0.3;
	real angle_Y_5 = 0.1;
	real pupilPos_X_5 = -0.5;
	real pupilPos_Y_5 = 0.35;
	bool check_5 = compareResultsCalcSingleAndGlobalOPDsoptSys_inf(/*opt sys*/ OptSys,/*angle X*/ angle_X_5, /*angle Y*/ angle_Y_5, /*PX*/ pupilPos_X_5, /*PY*/ pupilPos_Y_5,/*light*/ mLight550, tolerance);
	workTheSystem.push_back(check_5);

	bool workReturn = Math::checkTrueOfVectorElements(workTheSystem);
	return workReturn;

}

// compare results calc single and global OPD obj
bool TestGlobalOPD::compareResultsCalcSingleAndGlobalOPDsoptSys_obj(/*opt sys*/OpticalSystem_LLT optSys,/*start point ray*/ VectorStructR3 startPointRay, /*PX*/real PX, /*PY*/real PY,/*light*/ Light_LLT light, real tolerance)
{
	bool checker;

	// calculate OPD single ray
	OPD OPD_SingleRay;
	real opdSingle = OPD_SingleRay.OPD_singelRay_obj(optSys, startPointRay, PX, PY, light);

	// get the wanted ray
	LightRayStruct wantedLightRay = OPD_SingleRay.getWantedLightRay();
	std::vector<LightRayStruct> wantedLightRay_vec{ wantedLightRay };

	// calculate OPD using global OPD function
	OPD OPD_global(/*optical system*/ optSys, /*aimed light ray*/ wantedLightRay_vec, /*obj inf*/objectPoint_inf_obj::obj, 1);
	OPD_global.setFirstAimedRayIsChiefRay(false);
	OPD_global.calcGlobalOPD_new();
	cv::Mat testOPD0 = OPD_global.getGlobalOPD_deepCopy();
	real checkOPD0 = testOPD0.at<real>(0, 0);

	checker = Math::compareTwoNumbers_tolerance(opdSingle, checkOPD0, tolerance);
	return checker;

}

// compare results calc single and global OPD inf
bool TestGlobalOPD::compareResultsCalcSingleAndGlobalOPDsoptSys_inf(OpticalSystem_LLT optSys, real angle_X, real angle_Y, real PX, real PY, Light_LLT light, real tolerance)
{

	bool checker;

	// calculate OPD single ray
	OPD OPD_SingleRay;
	real opdSingle = OPD_SingleRay.OPD_singelRay_inf(optSys, angle_X, angle_Y, PX, PY, light);

	// get the wanted ray
	LightRayStruct wantedLightRay = OPD_SingleRay.getWantedLightRay();
	std::vector<LightRayStruct> wantedLightRay_vec{ wantedLightRay };

	std::vector<VectorStructR3> pointsInAS;
	VectorStructR3 tempPointInAs{ OPD_SingleRay.getPosX_inApStop(), OPD_SingleRay.getPosY_inApStop(), OPD_SingleRay.getPosZ_inApStop() };
	pointsInAS.push_back(tempPointInAs);

	// calculate OPD using global OPD function
	OPD OPD_global(/*optical system*/ optSys, /*points in Aperture Stop*/ pointsInAS, /*light*/ light,  /*obj inf*/objectPoint_inf_obj::inf, /*size matrix with OPDs*/ 1);
	OPD_global.setFirstAimedRayIsChiefRay(false);
	OPD_global.setFieldAngleChiefRay_X(angle_X);
	OPD_global.setFieldAngleChiefRay_Y(angle_Y);
	OPD_global.calcGlobalOPD_new();
	cv::Mat testOPD0 = OPD_global.getGlobalOPD_deepCopy();
	real checkOPD0 = testOPD0.at<real>(0, 0);

	checker = Math::compareTwoNumbers_tolerance(opdSingle, checkOPD0, tolerance);
	return checker;
}



// test upsamling OPD
bool TestGlobalOPD::testUpsamplingOPD()
{
	std::vector<bool> workTheSystem;
	std::string location = "../tests/testGlobalOPD/upsamplingOPD";
	
	
	std::string name_0 = "0";
	cv::Mat loadedOPD_0 = inportExportData::importTXTtoCVmat(location, name_0, 14, 14);
	
	OPD test0;
	test0.setGlobalOPD(loadedOPD_0);
	
	test0.bilinearInterpolToFillHolesInOPDmatrix();
	
	cv::Mat upsampledOPDmatrix_0 = test0.getUpsampledGlobalOPD_deepCopy();
	inportExportData::exportCV_MatToExcel(upsampledOPDmatrix_0, location, "0upsampled");
	
	// check the matrix 0
	real ref0 = 1;
	real calc0 = upsampledOPDmatrix_0.at<real>(0, 0);
	bool check0 = Math::compareTwoNumbers_tolerance(ref0, calc0, 0.001);
	workTheSystem.push_back(check0);
	
	real ref1 = 37.5;
	real calc1 = upsampledOPDmatrix_0.at<real>(5, 3);
	bool check1 = Math::compareTwoNumbers_tolerance(ref1, calc1, 0.001);
	workTheSystem.push_back(check1);
	
	real ref2 = 0.0;
	real calc2 = upsampledOPDmatrix_0.at<real>(7, 7);
	bool check2 = Math::compareTwoNumbers_tolerance(ref2, calc2, 0.001);
	workTheSystem.push_back(check2);
	
	real ref3 = 0.0;
	real calc3 = upsampledOPDmatrix_0.at<real>(12, 13);
	bool check3 = Math::compareTwoNumbers_tolerance(ref3, calc3, 0.001);
	workTheSystem.push_back(check3);
	
	real ref4 = 47.0;
	real calc4 = upsampledOPDmatrix_0.at<real>(13, 8);
	bool check4 = Math::compareTwoNumbers_tolerance(ref4, calc4, 0.001);
	workTheSystem.push_back(check4);
	
	// check the matrix 1
	std::string name_1 = "1";
	cv::Mat loadedOPD_1 = inportExportData::importTXTtoCVmat(location, name_1, 14, 14);
	
	OPD test1;
	test1.setGlobalOPD(loadedOPD_1);
	
	test1.bilinearInterpolToFillHolesInOPDmatrix();
	
	cv::Mat upsampledOPDmatrix_1 = test1.getUpsampledGlobalOPD_deepCopy();
	inportExportData::exportCV_MatToExcel(upsampledOPDmatrix_1, location, "1upsampled");
	
	// check the matrix 1
	real ref5 = 999.0;
	real calc5 = upsampledOPDmatrix_1.at<real>(3, 11);
	bool check5 = Math::compareTwoNumbers_tolerance(ref5, calc5, 0.001);
	workTheSystem.push_back(check5);
	
	real ref6 = 26.5;
	real calc6 = upsampledOPDmatrix_1.at<real>(7, 2);
	bool check6 = Math::compareTwoNumbers_tolerance(ref6, calc6, 0.001);
	workTheSystem.push_back(check6);
	
	real ref7 = 32.0;
	real calc7 = upsampledOPDmatrix_1.at<real>(4, 6);
	bool check7 = Math::compareTwoNumbers_tolerance(ref7, calc7, 0.001);
	workTheSystem.push_back(check7);
	
	real ref8 = 512.25;
	real calc8 = upsampledOPDmatrix_1.at<real>(9, 7);
	bool check8 = Math::compareTwoNumbers_tolerance(ref8, calc8, 0.001);
	workTheSystem.push_back(check8);
	
	real ref9 = 0.0;
	real calc9 = upsampledOPDmatrix_1.at<real>(13, 12);
	bool check9 = Math::compareTwoNumbers_tolerance(ref9, calc9, 0.001);
	workTheSystem.push_back(check9);

	// load a real OPD
	std::string name_2 = "2";
	cv::Mat loadedOPD_2 = inportExportData::importTXTtoCVmat(location, name_2, 41, 41);

	OPD test2;
	test2.setGlobalOPD(loadedOPD_2);

	test2.bilinearInterpolToFillHolesInOPDmatrix();

	cv::Mat upsampledOPDmatrix_2 = test2.getUpsampledGlobalOPD_deepCopy();
	inportExportData::exportCV_MatToExcel(upsampledOPDmatrix_2, location, "2upsampled");

	//// check the matrix 1
	real ref10 = 0.0;
	real calc10 = upsampledOPDmatrix_2.at<real>(8, 2);
	bool check10 = Math::compareTwoNumbers_tolerance(ref10, calc10, 0.001);
	workTheSystem.push_back(check10);
	
	real ref11 = -144.385;
	real calc11 = upsampledOPDmatrix_2.at<real>(20, 0);
	bool check11 = Math::compareTwoNumbers_tolerance(ref11, calc11, 0.001);
	workTheSystem.push_back(check11);
	
	real ref12 = -105.857;
	real calc12 = upsampledOPDmatrix_2.at<real>(15, 7);
	bool check12 = Math::compareTwoNumbers_tolerance(ref12, calc12, 0.001);
	workTheSystem.push_back(check12);
	
	real ref13 = -9.90761;
	real calc13 = upsampledOPDmatrix_2.at<real>(19, 18);
	bool check13 = Math::compareTwoNumbers_tolerance(ref13, calc13, 0.001);
	workTheSystem.push_back(check13);
	
	real ref14 = -102.524;
	real calc14 = upsampledOPDmatrix_2.at<real>(29, 30);
	bool check14 = Math::compareTwoNumbers_tolerance(ref14, calc14, 0.001);
	workTheSystem.push_back(check14);

	bool workReturn = Math::checkTrueOfVectorElements(workTheSystem);
	return workReturn;
}