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

bool TestGlobalOPD::checkGlobalOPD_superFunction()
{
	// work the system
	std::vector<bool> workTheSystem;

	//bool checkFillASwitPointsToCalcGlobalOPD = checkPointsToFillAS_ToCalcGLobalOPD();
	//workTheSystem.push_back(checkFillASwitPointsToCalcGlobalOPD);

	bool checkFillMatrixWithOPDs = checkFillOPDinMatrix_E0();
	workTheSystem.push_back(checkFillMatrixWithOPDs);

	//// E0
	//bool checkE0 = checkGlobalOPD_E0();
	//workTheSystem.push_back(checkE0);

	//// E1
	//bool checkE1 = checkGlobalOPD_E1();
	//workTheSystem.push_back(checkE1);

	bool checkOPD_superFct = Math::checkTrueOfVectorElements(workTheSystem);
	return checkOPD_superFct;
	
}



bool TestGlobalOPD::checkPointsToFillAS_ToCalcGLobalOPD()
{
	// work the system
	std::vector<bool> workTheSystem;

	//all the surfaces
	SphericalSurface_LLT S0(/*radius*/30.0, /*semiHeight*/10.0, /*Apex of the sphere*/{ 0.0, 0.0, 10.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
	SphericalSurface_LLT S1(/*radius*/30.0, /*semiHeight*/10.0, /*Apex of the sphere*/{ 0.0, 0.0, 20.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
	ApertureStop_LLT S2(/*semi height*/ 2.0, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index*/ 1.0);
	PlanGeometry_LLT S3(/*semiHeight*/5.0, /*point*/{ 0.0,0.0,40.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiveSideA*/ 1.0, /*refractiveSideB*/ 1.0);

	surfacePtr S0_ptr = S0.clone();
	surfacePtr S1_ptr = S1.clone();
	surfacePtr S2_ptr = S2.clone();
	surfacePtr S3_ptr = S3.clone();

	std::vector< surfacePtr> surfacePtr_vec = { S0_ptr ,S1_ptr ,S2_ptr ,S3_ptr };
	std::vector< interaction_ptr > interac_ptr = { mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };

	OpticalSystem_LLT optSys;
	optSys.fillOptSysWithSurfaceAndInteractions(surfacePtr_vec, interac_ptr);

	// test the start system
	bool testStartSystem = oftenUse::checkOptSysLLT_Equal_Better_Zemax(optSys, { 0.0,0.0,0.0 }, 1930.36, 0.01, compareTOM_Zemax::comEqual);
	workTheSystem.push_back(testStartSystem);

	FillApertureStop fillAperStop;
	// fill aperture Stop to calculate OPD
	unsigned int sizeMatrixToCalcGlobalOP = 9;
	std::vector<VectorStructR3> pointsInASToCalcGlobalOPD = fillAperStop.fillApertureStopToCalcGlobalOPD_doNoteUsesThat(optSys.getInforAS(),sizeMatrixToCalcGlobalOP);

	// check points in AS
	VectorStructR3 point_0 = pointsInASToCalcGlobalOPD[0];
	VectorStructR3 ref_point_0 = { 0.0,0.5,30.0 };
	bool check_0 = Math::compareTwoVectorStructR3_tolerance(point_0, ref_point_0, 0.01);
	workTheSystem.push_back(check_0);

	VectorStructR3 point_2 = pointsInASToCalcGlobalOPD[2];
	VectorStructR3 ref_point_2 = { 0.5,0.0,30.0 };
	bool check_2 = Math::compareTwoVectorStructR3_tolerance(point_2, ref_point_2, 0.01);
	workTheSystem.push_back(check_2);

	VectorStructR3 point_4 = pointsInASToCalcGlobalOPD[4];
	VectorStructR3 ref_roint_4 = { 0.0,-0.5,30.0 };
	bool check_4 = Math::compareTwoVectorStructR3_tolerance(point_4, ref_roint_4, 0.01);
	workTheSystem.push_back(check_4);

	VectorStructR3 point_8 = pointsInASToCalcGlobalOPD[8];
	VectorStructR3 ref_point_8 = { 0.0,1.0,30.0 };
	bool check_8 = Math::compareTwoVectorStructR3_tolerance(point_8, ref_point_8, 0.01);
	workTheSystem.push_back(check_8);

	VectorStructR3 point_20 = pointsInASToCalcGlobalOPD[20];
	VectorStructR3 ref_point_20 = { -1.0,0.0,30.0 };
	bool check_20 = Math::compareTwoVectorStructR3_tolerance(point_20, ref_point_20, 0.01);
	workTheSystem.push_back(check_20);

	VectorStructR3 point_24 = pointsInASToCalcGlobalOPD[24];
	VectorStructR3 ref_point_24 = { 0.0,1.5,30.0 };
	bool check_24 = Math::compareTwoVectorStructR3_tolerance(point_24, ref_point_24, 0.01);
	workTheSystem.push_back(check_24);

	VectorStructR3 point_30 = pointsInASToCalcGlobalOPD[30];
	VectorStructR3 ref_point_30 = { 1.5,0.0,30.0 };
	bool check_30 = Math::compareTwoVectorStructR3_tolerance(point_30, ref_point_30, 0.01);
	workTheSystem.push_back(check_30);

	VectorStructR3 point_33 = pointsInASToCalcGlobalOPD[33];
	VectorStructR3 ref_point_33 = { 1.06066, -1.06066,30.0 };
	bool check_33 = Math::compareTwoVectorStructR3_tolerance(point_33, ref_point_33, 0.01);
	workTheSystem.push_back(check_33);

	VectorStructR3 point_45 = pointsInASToCalcGlobalOPD[45];
	VectorStructR3 ref_point_45 = { -1.06066,1.06066,30.0 };
	bool check_45 = Math::compareTwoVectorStructR3_tolerance(point_45, ref_point_45, 0.01);
	workTheSystem.push_back(check_45);


	bool workReturn = Math::checkTrueOfVectorElements(workTheSystem);
	return workReturn;

}

// check fill OPD in Matrix
bool TestGlobalOPD::checkFillOPDinMatrix_E0()
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
	
	// ray aiming
	RayAiming rayAiming;
	std::vector<LightRayStruct> aimedLightRays = rayAiming.rayAimingMany_obj_complete(optSys, pointsInAS, { 0.0,0.0,0.0 }, mLight550, 1.0);

	unsigned int sizeMatrix31 = 31;
	OPD opd_31(/*optical system*/ optSys, /*aimed light ray*/ aimedLightRays, /*obj inf*/objectPoint_inf_obj::obj, sizeMatrix31);
	opd_31.calcGlobalOPD_new(sizeMatrix31);
	// matrix wit global OPD
	cv::Mat globalOPD_00_31 = opd_31.getGlobalOPD();

	// hier sollst du dann eine Funktion schreiben, die über Bilineare Filterung die innere Matrix auffüllt.
	// --> Linda

	// save global OPD 31 in csv
	std::string location31 = "C:/Tracer-Open-Master/tests/testGlobalOPD/refOPDs/checkFillOPDinMatrix";
	std::string fileName31 = "calc00_31";
	inportExportData::exportCV_MatToExcel(globalOPD_00_31, location31, fileName31);
		

	unsigned int sizeMatrix41 = 41;
	OPD opd_41(/*optical system*/ optSys, /*aimed light ray*/ aimedLightRays, /*obj inf*/objectPoint_inf_obj::obj, sizeMatrix41);
	opd_41.calcGlobalOPD_new(sizeMatrix41);
	// matrix wit global OPD
	cv::Mat globalOPD_00_41 = opd_41.getGlobalOPD();

	// save global OPD 41 in csv
	std::string location41 = "C:/Tracer-Open-Master/tests/testGlobalOPD/refOPDs/checkFillOPDinMatrix";
	std::string fileName41 = "calc00_41";
	inportExportData::exportCV_MatToExcel(globalOPD_00_41, location41, fileName41);

	bool workReturn = Math::checkTrueOfVectorElements(workTheSystem);
	return workReturn;
}

