#include "TestGlobalOPD.h"

// surfaces
#include "..\..\LowLevelTracing\Surfaces\SphericalSurface_LLT.h"
#include "..\..\LowLevelTracing\Surfaces\ApertureStop_LLT.h"

#include "..\..\FillAptertureStop\FillApertureStop.h"

#include "..\..\Analyse\OpticalPathDifference.h"

#include "..\..\Analyse\CardinalPoints.h"



#include "..\..\Analyse\Spot.h"

typedef std::shared_ptr< SurfaceIntersectionRay_LLT > surfacePtr_LLT;


TestGlobalOPD::TestGlobalOPD() { loadImportantparameter(); };
TestGlobalOPD::~TestGlobalOPD() {};

// load important staff
void TestGlobalOPD::loadImportantparameter()
{
	mLight.setWavelength(550.0);
	mLight.setTypeLight(typeLight::typeLightRay);
	mLight.setIntensity(1.0);
	mLight.setJonesVector({ 0.0,0.0,0.0,0.0 });


	// Ray in the field y = -1
	// single ray tracing
	Ray_LLT chief_Field_negY1({ 0.0,-1.0,0.0 }, { 0.0,1.0,30.0 }, 1.0);
	mChiefLightRay_Field_negY1.setLight_LLT(mLight);
	mChiefLightRay_Field_negY1.setRay_LLT(chief_Field_negY1);
	mChiefLightRay_Field_negY1.setIsAlive(true);


	Ray_LLT rayE0_0_Field_negY1({ 0.0,-1.0,0.0 }, { -0.5,1.0,30.0 }, 1.0);
	Ray_LLT rayE0_1_Field_negY1({ 0.0,-1.0,0.0 }, { 0.0,2.0,30.0 }, 1.0);
	Ray_LLT rayE0_2_Field_negY1({ 0.0,-1.0,0.0 }, { 1.0,1.0,30.0 }, 1.0);
	Ray_LLT rayE0_3_Field_negY1({ 0.0,-1.0,0.0 }, { -1.0,1.0,30.0 }, 1.0);
	
	LightRayStruct lightRayE0_0_Field_negY1(mLight, rayE0_0_Field_negY1, 1);
	LightRayStruct lightRayE0_1_Field_negY1(mLight, rayE0_1_Field_negY1, 1);
	LightRayStruct lightRayE0_2_Field_negY1(mLight, rayE0_2_Field_negY1, 1);
	LightRayStruct lightRayE0_3_Field_negY1(mLight, rayE0_3_Field_negY1, 1);

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


bool TestGlobalOPD::checkGlobalOPD_superFunction()
{
	// work the system
	std::vector<bool> workTheSystem;

	// E0
	bool checkE0 = checkE0_OPD();
	workTheSystem.push_back(checkE0);

	//// E1
	//bool checkE1 = checkE1_OPD();
	//workTheSystem.push_back(checkE1);

	bool checkOPD_superFct = Math::checkTrueOfVectorElements(workTheSystem);
	return checkOPD_superFct;
	
}

bool TestGlobalOPD::checkE0_OPD()
{
	// work the system
	std::vector<bool> workTheSystem;

	//all the surfaces
	ApertureStop_LLT A0(/*semi height*/ 1.0, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index*/ 1.0);
	SphericalSurface_LLT S1(/*radius*/35.63357445153594, /*semiHeight*/4.0, /*Apex of the sphere*/{ 0.0, 0.0, 50.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
	SphericalSurface_LLT S2(/*radius*/30.0, /*semiHeight*/4.0, /*Apex of the sphere*/{ 0.0, 0.0, 55.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
	SphericalSurface_LLT S3(/*radius*/50.0, /*semiHeight*/4.0, /*Apex of the sphere*/{ 0.0, 0.0, 56.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
	SphericalSurface_LLT S4(/*radius*/46.72413691553324, /*semiHeight*/4.0, /*Apex of the sphere*/{ 0.0, 0.0, 61.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
	PlanGeometry_LLT S5(/*semiHeight*/5.0, /*point*/{ 0.0,0.0,91.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiveSideA*/ 1.0, /*refractiveSideB*/ 1.0);

	// build the optical system
	OpticalSystem_LLT optSysE0;
	optSysE0.fillVectorSurfaceAndInteractingData(0, A0.clone(), mDoNothing.clone());
	optSysE0.fillVectorSurfaceAndInteractingData(1, S1.clone(), mRefrac.clone());
	optSysE0.fillVectorSurfaceAndInteractingData(2, S2.clone(), mRefrac.clone());
	optSysE0.fillVectorSurfaceAndInteractingData(3, S3.clone(), mRefrac.clone());
	optSysE0.fillVectorSurfaceAndInteractingData(4, S4.clone(), mRefrac.clone());
	optSysE0.fillVectorSurfaceAndInteractingData(5, S5.clone(), mDoNothing.clone()); // the callculate the ray to the exit pupil
																					// the image surface is not allowed so be "absorb"


	// single ray tracing
	Ray_LLT cheif({ 0.0,0.0,0.0 }, { 0.0,0.0,30.0 }, 1.0);
	Ray_LLT rayE0_0({ 0.0,0.0,0.0 }, { 0.0,1.0,30.0 }, 1.0);
	Ray_LLT rayE0_1({ 0.0,0.0,0.0 }, { 0.0,-0.5,30.0 }, 1.0);
	Ray_LLT rayE0_2({ 0.0,0.0,0.0 }, { -1.0,0.0,30.0 }, 1.0);
	Ray_LLT rayE0_3({ 0.0,0.0,0.0 }, { 0.5,0.5,30.0 }, 1.0);
	Ray_LLT rayE0_4({ 0.0,0.0,0.0 }, { -0.5,0.5,30.0 }, 1.0);
	Ray_LLT rayE0_5({ 0.0,0.0,0.0 }, { 0.3,-0.7,30.0 }, 1.0);

	LightRayStruct chiefLightRay(mLight, cheif, 1);
	LightRayStruct lightRayE0_0(mLight, rayE0_0, 1);
	LightRayStruct lightRayE0_1(mLight, rayE0_1, 1);
	LightRayStruct lightRayE0_2(mLight, rayE0_2, 1);
	LightRayStruct lightRayE0_3(mLight, rayE0_3, 1);
	LightRayStruct lightRayE0_4(mLight, rayE0_4, 1);
	LightRayStruct lightRayE0_5(mLight, rayE0_5, 1);

	std::vector<LightRayStruct> vecLightRaysE0{ lightRayE0_0, lightRayE0_1, lightRayE0_2, lightRayE0_3 };
	SequentialRayTracing seqTraceE0_single(optSysE0);
	seqTraceE0_single.seqRayTracingWithVectorOfLightRays(vecLightRaysE0);

	//___
	//check if the system works 
	IntersectInformationStruct interInfosPoint0 = seqTraceE0_single.getAllInterInfosOfSurf_i(5).at(0);
	VectorStructR3 checkInterPoint0 = { 0.0,-3.0317900054E-003,91.0 };
	bool checkcheckInterP0 = Math::compareTwoVectorStructR3_decimals(interInfosPoint0.getIntersectionPoint(), checkInterPoint0, 6);
	workTheSystem.push_back(checkcheckInterP0);
	IntersectInformationStruct interInfosPoint1 = seqTraceE0_single.getAllInterInfosOfSurf_i(5).at(1);
	VectorStructR3 checkInterPoint1 = { 0.0,-1.8961760243E-003,91.0 };
	bool checkcheckInterP1 = Math::compareTwoVectorStructR3_decimals(interInfosPoint1.getIntersectionPoint(), checkInterPoint1, 6);
	workTheSystem.push_back(checkcheckInterP1);
	IntersectInformationStruct interInfosPoint2 = seqTraceE0_single.getAllInterInfosOfSurf_i(5).at(2);
	VectorStructR3 checkInterPoint2 = { 3.0317900054E-003,0.0,91.0 };
	VectorStructR3 interPoint2 = interInfosPoint2.getIntersectionPoint();
	bool checkcheckInterP2 = Math::compareTwoVectorStructR3_decimals(interPoint2, checkInterPoint2, 5);
	workTheSystem.push_back(checkcheckInterP2);
	IntersectInformationStruct interInfosPoint3 = seqTraceE0_single.getAllInterInfosOfSurf_i(5).at(3);
	VectorStructR3 checkInterPoint3 = { 7.6245887800E-004,7.6245887800E-004,91.0 };
	bool checkcheckInterP3 = Math::compareTwoVectorStructR3_decimals(interInfosPoint3.getIntersectionPoint(), checkInterPoint3, 6);
	workTheSystem.push_back(checkcheckInterP3);




	//___ test opt achse
	// test rays to calculate OPD
	std::vector<LightRayStruct> lightRay{ lightRayE0_0, lightRayE0_1, lightRayE0_2 ,lightRayE0_3, lightRayE0_4, lightRayE0_5 };
	// calc global OPD optical achse 
	OPD OPDglobalE0_optAchse(/*exit pupil*/ mExitPupilE0_ptr,  /*optical system*/ optSysE0,	/*fill apertur stop with light ray*/ lightRay, /*chief ray*/ chiefLightRay, /*scalling*/ 0);
	std::vector<real> checkOPD = OPDglobalE0_optAchse.getVecWithAllCalcGlobalOPD();
	std::vector<real> zemaxDataOPD = { -0.071713617204,-0.058155102772, -0.071713617204, -0.089671465399, -0.089671465399,-0.094086891382 };
	bool checkerOPD = Math::compareTwoSTDVecors_decimals(checkOPD, zemaxDataOPD, 8);
	workTheSystem.push_back(checkerOPD);
	//___ end test opt achse

	//__ start check gloabl OPD on optical axis
	// fill aperture stop with many lightrays
	FillApertureStop fillAperStopE0_optAxis({ 0.0,0.0,0.0 }, 1, { 0.0,0.0,30.0 }, { 0.0,0.0,1.0 }, /*rings*/6, /*arms*/8, 1.0, mLight);
	// calc global OPD optical field (y=1) for some rays
	OPD OPDglobalE0_optAxis(/*exit pupil*/ mExitPupilE0_ptr,  /*optical system*/ optSysE0,
		/*fill apertur stop with light ray*/ fillAperStopE0_optAxis.getVectorWithLightRays(), /*chief ray*/ fillAperStopE0_optAxis.getVectorWithLightRays().at(0), /*scalling*/ 0);
	OPDglobalE0_optAxis.exportCV_MatToExcel(OPDglobalE0_optAxis.getGlobalOPD(), "D:\OPDglobalE0_optAxis_0.csv");
	//__ end check gloabl OPD in the field (y=1) for many ray

	// Ray in the field y = 1
	// single ray tracing
	Ray_LLT cheif_Field({ 0.0,1.0,0.0 }, { 0.0,-1.0,30.0 }, 1.0);
	Ray_LLT rayE0_0_Field({ 0.0,1.0,0.0 }, { 0.0,0.0,30.0 }, 1.0);
	Ray_LLT rayE0_1_Field({ 0.0,1.0,0.0 }, { 0.0,-2.0,30.0 }, 1.0);
	Ray_LLT rayE0_2_Field({ 0.0,1.0,0.0 }, { 0.0,-1.0,30.0 }, 1.0);
	Ray_LLT rayE0_3_Field({ 0.0,1.0,0.0 }, { -1.0,-1.0,30.0 }, 1.0);
	LightRayStruct chiefLightRay_Field(mLight, cheif_Field, 1);
	LightRayStruct lightRayE0_0_Field(mLight, rayE0_0_Field, 1);
	LightRayStruct lightRayE0_1_Field(mLight, rayE0_1_Field, 1);
	LightRayStruct lightRayE0_2_Field(mLight, rayE0_2_Field, 1);
	LightRayStruct lightRayE0_3_Field(mLight, rayE0_3_Field, 1);

	//__ start check OPD in the field (y=1) for some rays
	std::vector<LightRayStruct> vecLightRaysE0_Field_posY1{ lightRayE0_0_Field, lightRayE0_1_Field, lightRayE0_2_Field, lightRayE0_3_Field };
	// calc global OPD optical field for many rays
	OPD OPDglobalE1_Field_singleRays(/*exit pupil*/ mExitPupilE0_ptr,  /*optical system*/ optSysE0,
		/*fill apertur stop with light ray*/ vecLightRaysE0_Field_posY1, /*chief ray*/ chiefLightRay_Field, /*scalling*/ 0);
	std::vector<real> checkOPD_Field_ZemaxData = { -0.146699120754,0.4827546459793,0.0, 0.0188381446773 };
	std::vector<real> checkOPD_Field = OPDglobalE1_Field_singleRays.getVecWithAllCalcGlobalOPD();
	bool checkOPD_Field_work = Math::compareTwoSTDVecors_decimals(checkOPD_Field_ZemaxData, checkOPD_Field, 8);
	workTheSystem.push_back(checkOPD_Field_work);
	//__ end check OPD in the field for some rays


	//__ start check gloabl OPD in the field (y=1) for many ray
	// fill aperture stop with many lightrays
	FillApertureStop fillAperStopE0_field_posY1({ 0.0,1.0,0.0 }, 1, { 0.0,0.0,30.0 }, { 0.0,0.0,1.0 }, /*rings*/6, /*arms*/8, 1.0, mLight);
	// calc global OPD optical field (y=1) for some rays
	OPD OPDglobalE0_Y1_Field(/*exit pupil*/ mExitPupilE0_ptr,  /*optical system*/ optSysE0,
		/*fill apertur stop with light ray*/ fillAperStopE0_field_posY1.getVectorWithLightRays(), /*chief ray*/ fillAperStopE0_field_posY1.getVectorWithLightRays().at(0), /*scalling*/ 0);
	OPDglobalE0_Y1_Field.exportCV_MatToExcel(OPDglobalE0_Y1_Field.getGlobalOPD(), "D:\OPDglobalE0_Y1_Field_0.csv");
	//__ end check gloabl OPD in the field (y=1) for many ray




	// calc global OPD optical field for some rays
	OPD OPDglobalE1_Field_singleRays_negY1(/*exit pupil*/ mExitPupilE0_ptr,  /*optical system*/ optSysE0,
		/*fill apertur stop with light ray*/ mVecLightRaysE0_Field_negY1, /*chief ray*/ mChiefLightRay_Field_negY1, /*scalling*/ 0);
	std::vector<real> checkOPD_Field_ZemaxData_negY = { -0.038248433070,0.4827546459849,0.0188381446769, 0.018838144673 };
	std::vector<real> checkOPD_Field_negY = OPDglobalE1_Field_singleRays_negY1.getVecWithAllCalcGlobalOPD();
	bool checkOPD_Field_work_negY = Math::compareTwoSTDVecors_decimals(checkOPD_Field_ZemaxData_negY, checkOPD_Field_negY, 8);
	workTheSystem.push_back(checkOPD_Field_work_negY);
	//__ end check OPD in the field for some rays

	//__ start check gloabl OPD in the field (y=-1) for many ray
	// fill aperture stop with many lightrays
	FillApertureStop fillAperStopE0_field_negY1({ 0.0,-1.0,0.0 }, 1, { 0.0,0.0,30.0 }, { 0.0,0.0,1.0 }, /*rings*/6, /*arms*/8, 1.0, mLight);
	// calc global OPD optical field (y=-1) for some rays
	OPD OPDglobalE0_negY1_Field(/*exit pupil*/ mExitPupilE0_ptr,  /*optical system*/ optSysE0,
		/*fill apertur stop with light ray*/ fillAperStopE0_field_negY1.getVectorWithLightRays(), /*chief ray*/ fillAperStopE0_field_negY1.getVectorWithLightRays().at(0), /*scalling*/ 0);
	OPDglobalE0_negY1_Field.exportCV_MatToExcel(OPDglobalE0_negY1_Field.getGlobalOPD(), "D:\OPDglobalE0_negY1_Field_0.csv");
	//__ end check gloabl OPD in the field (y=-1) for many ray

	// Ray in the field x = 1.0 y = 1.0
	// single ray tracing
	Ray_LLT cheif_Field_XYpos({ 1.0,1.0,0.0 }, { -1.0,-1.0,30.0 }, 1.0);
	Ray_LLT rayE0_0_Field_XYpos({ 1.0,1.0,0.0 }, { -1.0,-1.5,30.0 }, 1.0);
	Ray_LLT rayE0_1_Field_XYpos({ 1.0,1.0,0.0 }, { -1.0,-2.0,30.0 }, 1.0);
	Ray_LLT rayE0_2_Field_XYpos({ 1.0,1.0,0.0 }, { -1.5,-1.5,30.0 }, 1.0);
	Ray_LLT rayE0_3_Field_XYpos({ 1.0,1.0,0.0 }, { -1.5,-1.0,30.0 }, 1.0);
	LightRayStruct chiefLightRay_Field_XYpos(mLight, cheif_Field_XYpos, 1);
	LightRayStruct lightRayE0_0_Field_XYpos(mLight, rayE0_0_Field_XYpos, 1);
	LightRayStruct lightRayE0_1_Field_XYpos(mLight, rayE0_1_Field_XYpos, 1);
	LightRayStruct lightRayE0_2_Field_XYpos(mLight, rayE0_2_Field_XYpos, 1);
	LightRayStruct lightRayE0_3_Field_XYpos(mLight, rayE0_3_Field_XYpos, 1);

	//__ start check OPD in the field (x = 1.0, y = 1.0) for some rays
	std::vector<LightRayStruct> vecLightRaysE0_Field_XYpos{ lightRayE0_0_Field_XYpos, lightRayE0_1_Field_XYpos, lightRayE0_2_Field_XYpos, lightRayE0_3_Field_XYpos };
	// calc global OPD optical field for some rays
	OPD OPDglobalE1_Field_singleRays_XYpos(/*exit pupil*/ mExitPupilE0_ptr,  /*optical system*/ optSysE0,
		/*fill apertur stop with light ray*/ vecLightRaysE0_Field_XYpos, /*chief ray*/ chiefLightRay_Field_XYpos, /*scalling*/ 0);
	std::vector<real> checkOPD_Field_ZemaxData_XYpos = { 0.062100829309,0.5767754231156,0.3052008045207,0.0621008239309 };
	std::vector<real> checkOPD_Field_XYpos = OPDglobalE1_Field_singleRays_XYpos.getVecWithAllCalcGlobalOPD();
	bool checkOPD_Field_work_XYpos = Math::compareTwoSTDVecors_decimals(checkOPD_Field_ZemaxData_XYpos, checkOPD_Field_XYpos, 7);
	workTheSystem.push_back(checkOPD_Field_work_XYpos);
	//__ end check OPD in the field for some rays

	//__ start check gloabl OPD in the field (x = 1.0, y = 1.0) for many ray
	// fill aperture stop with many lightrays
	FillApertureStop fillAperStopE0_field_XYpos({ 1.0,1.0,0.0 }, 1, { 0.0,0.0,30.0 }, { 0.0,0.0,1.0 }, /*rings*/6, /*arms*/8, 1.0, mLight);
	// calc global OPD optical field (x=1.0, y=1.0) for some rays
	OPD OPDglobalE0_X1Y1_Field(/*exit pupil*/ mExitPupilE0_ptr,  /*optical system*/ optSysE0,
		/*fill apertur stop with light ray*/ fillAperStopE0_field_XYpos.getVectorWithLightRays(), /*chief ray*/ fillAperStopE0_field_XYpos.getVectorWithLightRays().at(0), /*scalling*/ 0);
	OPDglobalE0_X1Y1_Field.exportCV_MatToExcel(OPDglobalE0_X1Y1_Field.getGlobalOPD(), "D:\OPDglobalE0_X1Y1_Field_0.csv");
	//__ end check gloabl OPD in the field (y=-1) for many ray

	// Ray in the field x = -0.5 y = -0.5
	// single ray tracing
	Ray_LLT cheif_Field_XYneg({ -0.5,-0.5,0.0 }, { 0.5, 0.5,30.0 }, 1.0);
	Ray_LLT rayE0_0_Field_XYneg({ -0.5,-0.5,0.0 }, { 1.0,0.5,30.0 }, 1.0);
	Ray_LLT rayE0_1_Field_XYneg({ -0.5,-0.5,0.0 }, { 0.0,0.0,30.0 }, 1.0);
	Ray_LLT rayE0_2_Field_XYneg({ -0.5,-0.5,0.0 }, { -0.5,0.5,30.0 }, 1.0);
	Ray_LLT rayE0_3_Field_XYneg({ -0.5,-0.5,0.0 }, { 1.0,1.0,30.0 }, 1.0);
	LightRayStruct chiefLightRay_Field_XYneg(mLight, cheif_Field_XYneg, 1);
	LightRayStruct lightRayE0_0_Field_XYneg(mLight, rayE0_0_Field_XYneg, 1);
	LightRayStruct lightRayE0_1_Field_XYneg(mLight, rayE0_1_Field_XYneg, 1);
	LightRayStruct lightRayE0_2_Field_XYneg(mLight, rayE0_2_Field_XYneg, 1);
	LightRayStruct lightRayE0_3_Field_XYneg(mLight, rayE0_3_Field_XYneg, 1);

	//__ start check OPD in the field (x = -0.5, y = -0.5) for some rays
	std::vector<LightRayStruct> vecLightRaysE0_Field_XYneg{ lightRayE0_0_Field_XYneg, lightRayE0_1_Field_XYneg, lightRayE0_2_Field_XYneg, lightRayE0_3_Field_XYneg };
	// calc global OPD optical field for some rays
	OPD OPDglobalE1_Field_singleRays_XYneg(/*exit pupil*/ mExitPupilE0_ptr,  /*optical system*/ optSysE0,
		/*fill apertur stop with light ray*/ vecLightRaysE0_Field_XYneg, /*chief ray*/ chiefLightRay_Field_XYneg, /*scalling*/ 0);
	std::vector<real> checkOPD_Field_ZemaxData_XYneg = { -0.018726908708, -0.108114901143,-0.145494692733, 0.0466498123334 };
	std::vector<real> checkOPD_Field_XYneg = OPDglobalE1_Field_singleRays_XYneg.getVecWithAllCalcGlobalOPD();
	bool checkOPD_Field_work_XYneg = Math::compareTwoSTDVecors_decimals(checkOPD_Field_ZemaxData_XYneg, checkOPD_Field_XYneg, 8);
	workTheSystem.push_back(checkOPD_Field_work_XYneg);
	//__ end check OPD in the field for some rays

	//__ start check gloabl OPD in the field (x = -0.5, y = -0.5) for many ray
	// fill aperture stop with many lightrays
	FillApertureStop fillAperStopE0_field_XYneg({ -0.5,-0.5,0.0 }, 1, { 0.0,0.0,30.0 }, { 0.0,0.0,1.0 }, /*rings*/6, /*arms*/8, 1.0, mLight);
	// calc global OPD optical field (x=-0.5, y=-0.5) for some rays
	OPD OPDglobalE0_negX5negY5_Field(/*exit pupil*/ mExitPupilE0_ptr,  /*optical system*/ optSysE0,
		/*fill apertur stop with light ray*/ fillAperStopE0_field_XYneg.getVectorWithLightRays(), /*chief ray*/ fillAperStopE0_field_XYneg.getVectorWithLightRays().at(0), /*scalling*/ 0);
	OPDglobalE0_negX5negY5_Field.exportCV_MatToExcel(OPDglobalE0_negX5negY5_Field.getGlobalOPD(), "D:\OPDglobalE0_negX5negY5_Field_0.csv");
	//__ end check gloabl OPD in the field (y=-1) for many ray


	//___ test opt achse
	// test rays to calculate OPD
	// calc global OPD optical achse 
	OPD OPDglobalE0_optAchse_1(/*exit pupil*/ mExitPupilE0_ptr,  /*optical system*/ optSysE0,
		/*fill apertur stop with light ray*/ lightRay, /*chief ray*/ chiefLightRay, /*scalling*/ 1);
	std::vector<real> checkOPD_1 = OPDglobalE0_optAchse_1.getVecWithAllCalcGlobalOPD();
	bool checkerOPD_1 = Math::compareTwoSTDVecors_decimals(checkOPD_1, zemaxDataOPD, 8);
	workTheSystem.push_back(checkerOPD_1);
	//___ end test opt achse

	//__ start check gloabl OPD on optical axis
	// calc global OPD optical field (y=1) for some rays
	OPD OPDglobalE0_optAxis_1(/*exit pupil*/ mExitPupilE0_ptr,  /*optical system*/ optSysE0,
		/*fill apertur stop with light ray*/ fillAperStopE0_optAxis.getVectorWithLightRays(), /*chief ray*/ fillAperStopE0_optAxis.getVectorWithLightRays().at(0), /*scalling*/ 1);
	OPDglobalE0_optAxis_1.exportCV_MatToExcel(OPDglobalE0_optAxis_1.getGlobalOPD(), "D:\OPDglobalE0_optAxis_1.csv");
	//__ end check gloabl OPD in the field (y=1) for many ray

	// calc global OPD optical field for many rays
	OPD OPDglobalE1_Field_singleRays_1(/*exit pupil*/ mExitPupilE0_ptr,  /*optical system*/ optSysE0,
		/*fill apertur stop with light ray*/ vecLightRaysE0_Field_posY1, /*chief ray*/ chiefLightRay_Field, /*scalling*/ 1);
	std::vector<real> checkOPD_Field_1 = OPDglobalE1_Field_singleRays_1.getVecWithAllCalcGlobalOPD();
	bool check_singleRays_1 = Math::compareTwoSTDVecors_decimals(checkOPD_Field_ZemaxData, checkOPD_Field_1, 8);
	workTheSystem.push_back(check_singleRays_1);
	//__ end check OPD in the field for some rays


	//__ start check gloabl OPD in the field (y=1) for many ray
	// calc global OPD optical field (y=1) for some rays
	OPD OPDglobalE0_Y1_Field_1(/*exit pupil*/ mExitPupilE0_ptr,  /*optical system*/ optSysE0,
		/*fill apertur stop with light ray*/ fillAperStopE0_field_posY1.getVectorWithLightRays(), /*chief ray*/ fillAperStopE0_field_posY1.getVectorWithLightRays().at(0), /*scalling*/ 1);
	OPDglobalE0_Y1_Field_1.exportCV_MatToExcel(OPDglobalE0_Y1_Field_1.getGlobalOPD(), "D:\OPDglobalE0_Y1_Field_1.csv");
	//__ end check gloabl OPD in the field (y=1) for many ray

	//__ start check OPD in the field (y=-1) for some rays
	// calc global OPD optical field for some rays
	OPD OPDglobalE1_Field_singleRays_negY1_1(/*exit pupil*/ mExitPupilE0_ptr,  /*optical system*/ optSysE0,
		/*fill apertur stop with light ray*/ mVecLightRaysE0_Field_negY1, /*chief ray*/ mChiefLightRay_Field_negY1, /*scalling*/ 1);
	std::vector<real> checkOPD_Field_negY_1 = OPDglobalE1_Field_singleRays_negY1_1.getVecWithAllCalcGlobalOPD();
	bool checkOPD_Field_work_negY_1 = Math::compareTwoSTDVecors_decimals(checkOPD_Field_ZemaxData_negY, checkOPD_Field_negY_1, 8);
	workTheSystem.push_back(checkOPD_Field_work_negY_1);
	//__ end check OPD in the field for some rays

	//__ start check gloabl OPD in the field (y=-1) for many ray
	// calc global OPD optical field (y=-1) for some rays
	OPD OPDglobalE0_negY1_Field_1(/*exit pupil*/ mExitPupilE0_ptr,  /*optical system*/ optSysE0,
		/*fill apertur stop with light ray*/ fillAperStopE0_field_negY1.getVectorWithLightRays(), /*chief ray*/ fillAperStopE0_field_negY1.getVectorWithLightRays().at(0), /*scalling*/ 1);
	OPDglobalE0_negY1_Field_1.exportCV_MatToExcel(OPDglobalE0_negY1_Field_1.getGlobalOPD(), "D:\OPDglobalE0_negY1_Field_1.csv");
	//__ end check gloabl OPD in the field (y=-1) for many ray

	//__ start check OPD in the field (x = 1.0, y = 1.0) for some rays
	// calc global OPD optical field for some rays
	OPD OPDglobalE1_Field_singleRays_XYpos_1(/*exit pupil*/ mExitPupilE0_ptr,  /*optical system*/ optSysE0,
		/*fill apertur stop with light ray*/ vecLightRaysE0_Field_XYpos, /*chief ray*/ chiefLightRay_Field_XYpos, /*scalling*/ 1);
	std::vector<real> checkOPD_Field_XYpos_1 = OPDglobalE1_Field_singleRays_XYpos_1.getVecWithAllCalcGlobalOPD();
	bool checkOPD_Field_work_XYpos_1 = Math::compareTwoSTDVecors_decimals(checkOPD_Field_ZemaxData_XYpos, checkOPD_Field_XYpos_1, 7);
	workTheSystem.push_back(checkOPD_Field_work_XYpos_1);
	//__ end check OPD in the field for some rays

	//__ start check gloabl OPD in the field (x = 1.0, y = 1.0) for many ray
	// calc global OPD optical field (x=1.0, y=1.0) for some rays
	OPD OPDglobalE0_X1Y1_Field_1(/*exit pupil*/ mExitPupilE0_ptr,  /*optical system*/ optSysE0,
		/*fill apertur stop with light ray*/ fillAperStopE0_field_XYpos.getVectorWithLightRays(), /*chief ray*/ fillAperStopE0_field_XYpos.getVectorWithLightRays().at(0), /*scalling*/ 1);
	OPDglobalE0_X1Y1_Field_1.exportCV_MatToExcel(OPDglobalE0_X1Y1_Field_1.getGlobalOPD(), "D:\OPDglobalE0_X1Y1_Field_1.csv");
	//__ end check gloabl OPD in the field (y=-1) for many ray

	//__ start check OPD in the field (x = -0.5, y = -0.5) for some rays
	// calc global OPD optical field for some rays
	OPD OPDglobalE1_Field_singleRays_XYneg_1(/*exit pupil*/ mExitPupilE0_ptr,  /*optical system*/ optSysE0,
		/*fill apertur stop with light ray*/ vecLightRaysE0_Field_XYneg, /*chief ray*/ chiefLightRay_Field_XYneg, /*scalling*/ 1);
	std::vector<real> checkOPD_Field_XYneg_1 = OPDglobalE1_Field_singleRays_XYneg_1.getVecWithAllCalcGlobalOPD();
	bool checkOPD_Field_work_XYneg_1 = Math::compareTwoSTDVecors_decimals(checkOPD_Field_ZemaxData_XYneg, checkOPD_Field_XYneg_1, 8);
	workTheSystem.push_back(checkOPD_Field_work_XYneg_1);
	//__ end check OPD in the field for some rays

	//__ start check gloabl OPD in the field (x = -0.5, y = -0.5) for many ray
	// calc global OPD optical field (x=-0.5, y=-0.5) for some rays
	OPD OPDglobalE0_negX5negY5_Field_1(/*exit pupil*/ mExitPupilE0_ptr,  /*optical system*/ optSysE0,
		/*fill apertur stop with light ray*/ fillAperStopE0_field_XYneg.getVectorWithLightRays(), /*chief ray*/ fillAperStopE0_field_XYneg.getVectorWithLightRays().at(0), /*scalling*/ 1);
	OPDglobalE0_negX5negY5_Field_1.exportCV_MatToExcel(OPDglobalE0_negX5negY5_Field_1.getGlobalOPD(), "D:\OPDglobalE0_negX5negY5_Field_1.csv");
	//__ end check gloabl OPD in the field (y=-1) for many ray

	bool workReturn = Math::checkTrueOfVectorElements(workTheSystem);
	return workReturn;
}

bool TestGlobalOPD::checkE1_OPD()
{
	// work the system
	std::vector<bool> workTheSystem;

	//all the surfaces
	ApertureStop_LLT A0_E1(/*semi height*/ 1.0, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index*/ 1.0);
	SphericalSurface_LLT S1_E1(/*radius*/15.0, /*semiHeight*/4.0, /*Apex of the sphere*/{ 0.0, 0.0, 31.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
	SphericalSurface_LLT S2_E1(/*radius*/15.0, /*semiHeight*/4.0, /*Apex of the sphere*/{ 0.0, 0.0, 36.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
	SphericalSurface_LLT S3_E1(/*radius*/50.0, /*semiHeight*/4.0, /*Apex of the sphere*/{ 0.0, 0.0, 37.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.5, /*refIndexSideB*/1.0);
	SphericalSurface_LLT S4_E1(/*radius*/50.0, /*semiHeight*/4.0, /*Apex of the sphere*/{ 0.0, 0.0, 42.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.5, /*refIndexSideB*/1.0);
	PlanGeometry_LLT S5_E1(/*semiHeight*/5.0, /*point*/{ 0.0,0.0,96.54836003 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiveSideA*/ 1.0, /*refractiveSideB*/ 1.0);

	// build the optical system E1
	OpticalSystem_LLT optSysE1;
	optSysE1.fillVectorSurfaceAndInteractingData(0, &A0_E1, mDoNothing.clone());
	optSysE1.fillVectorSurfaceAndInteractingData(1, &S1_E1, mRefrac.clone());
	optSysE1.fillVectorSurfaceAndInteractingData(2, &S2_E1, mRefrac.clone());
	optSysE1.fillVectorSurfaceAndInteractingData(3, &S3_E1, mRefrac.clone());
	optSysE1.fillVectorSurfaceAndInteractingData(4, &S4_E1, mRefrac.clone());
	optSysE1.fillVectorSurfaceAndInteractingData(5, &S5_E1, mDoNothing.clone()); // the callculate the ray to the exit pupil
																		// the image surface is not allowed so be "absorb"

	//	//exit pupil
	PlanGeometry_LLT exitPupilE1(/*semiHeight*/3.0, /*point*/{ 0.0,0.0,33.66459016 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiveSideA*/ 1.0, /*refractiveSideB*/ 1.0);
	surfacePtr_LLT exitPupilE1_ptr = exitPupilE1.clone();

	// ___ test opt achse
	// single ray tracing
	Ray_LLT cheifE1({ 0.0,0.0,0.0 }, { 0.0,0.0,30.0 }, 1.0);
	Ray_LLT rayE1_0({ 0.0,0.0,0.0 }, { 0.0,1.0,30.0 }, 1.0);
	Ray_LLT rayE1_1({ 0.0,0.0,0.0 }, { 0.0,-0.5,30.0 }, 1.0);
	Ray_LLT rayE1_2({ 0.0,0.0,0.0 }, { -1.0,0.0,30.0 }, 1.0);
	Ray_LLT rayE1_3({ 0.0,0.0,0.0 }, { 0.5,0.5,30.0 }, 1.0);
	Ray_LLT rayE1_4({ 0.0,0.0,0.0 }, { -0.5,0.5,30.0 }, 1.0);
	Ray_LLT rayE1_5({ 0.0,0.0,0.0 }, { 0.3,-0.7,30.0 }, 1.0);

	LightRayStruct chiefLightRayE1_optA(mLight, cheifE1, 1);
	LightRayStruct lightRayE1_0(mLight, rayE1_0, 1);
	LightRayStruct lightRayE1_1(mLight, rayE1_1, 1);
	LightRayStruct lightRayE1_2(mLight, rayE1_2, 1);
	LightRayStruct lightRayE1_3(mLight, rayE1_3, 1);
	LightRayStruct lightRayE1_4(mLight, rayE1_4, 1);
	LightRayStruct lightRayE1_5(mLight, rayE1_5, 1);

	// test rays to calculate OPD
	std::vector<LightRayStruct> lightRayE1_optAchse{ lightRayE1_0, lightRayE1_1, lightRayE1_2 ,lightRayE1_3, lightRayE1_4, lightRayE1_5 };
	// calc global OPD optical achse 
	OPD OPDglobalE1_optAchse(/*exit pupil*/ exitPupilE1_ptr,  /*optical system*/ optSysE1,
		/*fill apertur stop with light ray*/ lightRayE1_optAchse, /*chief ray*/ chiefLightRayE1_optA, /*scalling*/ 0);
	std::vector<real> checkOPDE1_optA = OPDglobalE1_optAchse.getVecWithAllCalcGlobalOPD();
	std::vector<real> zemaxDataOPD_E1_optA = { -0.067509415903,-0.046105687280, -0.067509415903,-0.072794092752,-0.072794092752,-0.077216790741 };
	bool checkerOPD_E1_optA = Math::compareTwoSTDVecors_decimals(checkOPDE1_optA, zemaxDataOPD_E1_optA, 8);
	workTheSystem.push_back(checkerOPD_E1_optA);
	//___ end test opt achse

	//__ start check gloabl OPD on opt achses
	//fill aperture stop with many lightrays
	FillApertureStop fillAperStopE1_optAchse({ 0.0,0.0,0.0 }, 1, { 0.0,0.0,30.0 }, { 0.0,0.0,1.0 }, /*rings*/6, /*arms*/8, 1.0, mLight);
	// calc global OPD on optical achse for many rays
	OPD OPDglobalE1_optAchse_full(/*exit pupil*/ exitPupilE1_ptr,  /*optical system*/ optSysE1,
		/*fill apertur stop with light ray*/ fillAperStopE1_optAchse.getVectorWithLightRays(), /*chief ray*/ fillAperStopE1_optAchse.getVectorWithLightRays().at(0), /*scalling*/ 0);
	OPDglobalE1_optAchse_full.exportCV_MatToExcel(OPDglobalE1_optAchse_full.getGlobalOPD(), "D:\OPDglobal_E1_optAchse_0.csv");
	//__ end check gloabl OPD in the field (y=-1) for many ray


	// ___ test field y=1
	// single ray tracing
	Ray_LLT cheifE1_Y1({ 0.0,1.0,0.0 }, { 0.0,-1.0,30.0 }, 1.0);
	Ray_LLT rayE1_0_Y1({ 0.0,1.0,0.0 }, { 0.0,0.0,30.0 }, 1.0);
	Ray_LLT rayE1_1_Y1({ 0.0,1.0,0.0 }, { 0.0,-0.5,30.0 }, 1.0);
	Ray_LLT rayE1_2_Y1({ 0.0,1.0,0.0 }, { -1.0,-1.0,30.0 }, 1.0);
	Ray_LLT rayE1_3_Y1({ 0.0,1.0,0.0 }, { -0.5,-1.5,30.0 }, 1.0);
	Ray_LLT rayE1_4_Y1({ 0.0,1.0,0.0 }, { 1.0,-1.0,30.0 }, 1.0);
	Ray_LLT rayE1_5_Y1({ 0.0,1.0,0.0 }, { 0.5,-1.0,30.0 }, 1.0);

	LightRayStruct chiefLightRayE1_Y1(mLight, cheifE1_Y1, 1);
	LightRayStruct lightRayE1_0_Y1(mLight, rayE1_0_Y1, 1);
	LightRayStruct lightRayE1_1_Y1(mLight, rayE1_1_Y1, 1);
	LightRayStruct lightRayE1_2_Y1(mLight, rayE1_2_Y1, 1);
	LightRayStruct lightRayE1_3_Y1(mLight, rayE1_3_Y1, 1);
	LightRayStruct lightRayE1_4_Y1(mLight, rayE1_4_Y1, 1);
	LightRayStruct lightRayE1_5_Y1(mLight, rayE1_5_Y1, 1);

	// test rays to calculate OPD
	std::vector<LightRayStruct> lightRayE1_Y1{ lightRayE1_0_Y1, lightRayE1_1_Y1, lightRayE1_2_Y1, lightRayE1_3_Y1, lightRayE1_4_Y1, lightRayE1_5_Y1 };
	// calc global OPD optical achse for some rays
	OPD OPDglobalE1_Y1(/*exit pupil*/ exitPupilE1_ptr,  /*optical system*/ optSysE1,
		/*fill apertur stop with light ray*/ lightRayE1_Y1, /*chief ray*/ chiefLightRayE1_Y1, /*scalling*/ 0);
	std::vector<real> checkOPDE1_Y1 = OPDglobalE1_Y1.getVecWithAllCalcGlobalOPD();
	std::vector<real> zemaxDataOPD_E1_Y1 = { -0.068577489049,-0.035967400776, -0.029568213264,-0.022017747126,-0.029568213264,-0.036648487857 };
	bool checkerOPD_E1_Y1 = Math::compareTwoSTDVecors_decimals(checkOPDE1_Y1, zemaxDataOPD_E1_Y1, 7);
	workTheSystem.push_back(checkerOPD_E1_Y1);
	//___ end test opt achse

	//__ start check gloabl OPD on opt axis
	//fill aperture stop with many lightrays
	FillApertureStop fillAperStopE1_Y1({ 0.0,1.0,0.0 }, 1, { 0.0,0.0,30.0 }, { 0.0,0.0,1.0 }, /*rings*/6, /*arms*/8, 1.0, mLight);
	// calc global OPD on optical achse for many rays
	OPD OPDglobalE1_Y1_full(/*exit pupil*/ exitPupilE1_ptr,  /*optical system*/ optSysE1,
		/*fill apertur stop with light ray*/ fillAperStopE1_Y1.getVectorWithLightRays(), /*chief ray*/ fillAperStopE1_Y1.getVectorWithLightRays().at(0), /*scalling*/ 0);
	OPDglobalE1_Y1_full.exportCV_MatToExcel(OPDglobalE1_Y1_full.getGlobalOPD(), "D:\OPDglobal_E1_Y1_full_0.csv");
	//__ end check gloabl OPD in the field  for many ray

	// ___ test field x=-1
	// single ray tracing
	Ray_LLT cheifE1_negX1({ -1.0,0.0,0.0 }, { 1.0,0.0,30.0 }, 1.0);
	Ray_LLT rayE1_0_negX1({ -1.0,0.0,0.0 }, { 0.0,0.0,30.0 }, 1.0);
	Ray_LLT rayE1_1_negX1({ -1.0,0.0,0.0 }, { 1.0,-0.5,30.0 }, 1.0);
	Ray_LLT rayE1_2_negX1({ -1.0,0.0,0.0 }, { 2.0, 0.0,30.0 }, 1.0);
	Ray_LLT rayE1_3_negX1({ -1.0,0.0,0.0 }, { 0.5,0.5,30.0 }, 1.0);
	Ray_LLT rayE1_4_negX1({ -1.0,0.0,0.0 }, { 1.0,-1.0,30.0 }, 1.0);
	Ray_LLT rayE1_5_negX1({ -1.0,0.0,0.0 }, { 0.5,-0.5,30.0 }, 1.0);

	LightRayStruct chiefLightRayE1_negX1(mLight, cheifE1_negX1, 1);
	LightRayStruct lightRayE1_0_negX1(mLight, rayE1_0_negX1, 1);
	LightRayStruct lightRayE1_1_negX1(mLight, rayE1_1_negX1, 1);
	LightRayStruct lightRayE1_2_negX1(mLight, rayE1_2_negX1, 1);
	LightRayStruct lightRayE1_3_negX1(mLight, rayE1_3_negX1, 1);
	LightRayStruct lightRayE1_4_negX1(mLight, rayE1_4_negX1, 1);
	LightRayStruct lightRayE1_5_negX1(mLight, rayE1_5_negX1, 1);

	// test rays to calculate OPD
	std::vector<LightRayStruct> lightRayE1_negX1{ lightRayE1_0_negX1, lightRayE1_1_negX1, lightRayE1_2_negX1, lightRayE1_3_negX1, lightRayE1_4_negX1, lightRayE1_5_negX1 };
	// calc global OPD optical achse for some rays
	OPD OPDglobalE1_negX1(/*exit pupil*/ exitPupilE1_ptr,  /*optical system*/ optSysE1,
		/*fill apertur stop with light ray*/ lightRayE1_negX1, /*chief ray*/ chiefLightRayE1_negX1, /*scalling*/ 0);
	std::vector<real> checkOPDE1_negX1 = OPDglobalE1_negX1.getVecWithAllCalcGlobalOPD();
	std::vector<real> zemaxDataOPD_E1_negX1 = { -0.068577489049, -0.036648487857, 0.0982230102171, -0.063571219811, -0.029568213267, -0.063571219811 };
	bool checkerOPD_E1_negX1 = Math::compareTwoSTDVecors_decimals(checkOPDE1_negX1, zemaxDataOPD_E1_negX1, 7);
	workTheSystem.push_back(checkerOPD_E1_negX1);


	//__ start check gloabl OPD on opt axis
	//fill aperture stop with many lightrays
	FillApertureStop fillAperStopE1_negX1({ -1.0,0.0,0.0 }, 1, { 0.0,0.0,30.0 }, { 0.0,0.0,1.0 }, /*rings*/6, /*arms*/8, 1.0, mLight);
	// calc global OPD on optical achse for many rays
	OPD OPDglobalE1_negX1_full(/*exit pupil*/ exitPupilE1_ptr,  /*optical system*/ optSysE1,
		/*fill apertur stop with light ray*/ fillAperStopE1_negX1.getVectorWithLightRays(), /*chief ray*/ fillAperStopE1_negX1.getVectorWithLightRays().at(0), /*scalling*/ 0);
	OPDglobalE1_negX1_full.exportCV_MatToExcel(OPDglobalE1_negX1_full.getGlobalOPD(), "D:\OPDglobal_E1_negX1_full_0.csv");
	//__ end check gloabl OPD in the field (x=-1) for many ray

	// ___ test field x=-0.5 y=0.5
	// single ray tracing
	Ray_LLT cheifE1_negX5posY5({ -0.5,0.5,0.0 }, { 0.5,-0.5,30.0 }, 1.0);
	Ray_LLT rayE1_0_negX5posY5({ -0.5,0.5,0.0 }, { 0.0,0.0,30.0 }, 1.0);
	Ray_LLT rayE1_1_negX5posY5({ -0.5,0.5,0.0 }, { 1.0,-0.5,30.0 }, 1.0);
	Ray_LLT rayE1_2_negX5posY5({ -0.5,0.5,0.0 }, { 1.0, 0.0,30.0 }, 1.0);
	Ray_LLT rayE1_3_negX5posY5({ -0.5,0.5,0.0 }, { 0.5,0.5,30.0 }, 1.0);
	Ray_LLT rayE1_4_negX5posY5({ -0.5,0.5,0.0 }, { 1.5, -0.5,30.0 }, 1.0);
	Ray_LLT rayE1_5_negX5posY5({ -0.5,0.5,0.0 }, { 0.5,-1.5,30.0 }, 1.0);

	LightRayStruct chiefLightRayE1_negX5posY5(mLight, cheifE1_negX5posY5, 1);
	LightRayStruct lightRayE1_0_negX5posY5(mLight, rayE1_0_negX5posY5, 1);
	LightRayStruct lightRayE1_1_negX5posY5(mLight, rayE1_1_negX5posY5, 1);
	LightRayStruct lightRayE1_2_negX5posY5(mLight, rayE1_2_negX5posY5, 1);
	LightRayStruct lightRayE1_3_negX5posY5(mLight, rayE1_3_negX5posY5, 1);
	LightRayStruct lightRayE1_4_negX5posY5(mLight, rayE1_4_negX5posY5, 1);
	LightRayStruct lightRayE1_5_negX5posY5(mLight, rayE1_5_negX5posY5, 1);

	// test rays to calculate OPD
	std::vector<LightRayStruct> lightRayE1_negX5posY5{ lightRayE1_0_negX5posY5, lightRayE1_1_negX5posY5, lightRayE1_2_negX5posY5, lightRayE1_3_negX5posY5, lightRayE1_4_negX5posY5, lightRayE1_5_negX5posY5 };
	// calc global OPD optical achse for some rays
	OPD OPDglobalE1_negX5posY5(/*exit pupil*/ exitPupilE1_ptr,  /*optical system*/ optSysE1,
		/*fill apertur stop with light ray*/ lightRayE1_negX5posY5, /*chief ray*/ chiefLightRayE1_negX5posY5, /*scalling*/ 0);
	std::vector<real> checkOPDE1_negX5posY5 = OPDglobalE1_negX5posY5.getVecWithAllCalcGlobalOPD();
	std::vector<real> zemaxDataOPD_E1_negX5posY5 = { -0.073021394003,-0.033426559927, -0.063324279640, -0.079115477159, 4.26228059E-003, 4.26228059E-003 };
	bool checkerOPD_E1_negX5posY5 = Math::compareTwoSTDVecors_decimals(checkOPDE1_negX5posY5, zemaxDataOPD_E1_negX5posY5, 6);
	workTheSystem.push_back(checkerOPD_E1_negX5posY5);

	//__ start check gloabl OPD on opt axis
	//fill aperture stop with many lightrays
	FillApertureStop fillAperStopE1_negX5posY5({ -0.5,0.5,0.0 }, 1, { 0.0,0.0,30.0 }, { 0.0,0.0,1.0 }, /*rings*/6, /*arms*/8, 1.0, mLight);
	// calc global OPD on optical achse for many rays
	OPD OPDglobalE1_negX5posY5_full(/*exit pupil*/ exitPupilE1_ptr,  /*optical system*/ optSysE1,
		/*fill apertur stop with light ray*/ fillAperStopE1_negX5posY5.getVectorWithLightRays(), /*chief ray*/ fillAperStopE1_negX5posY5.getVectorWithLightRays().at(0), /*scalling*/ 0);
	OPDglobalE1_negX5posY5_full.exportCV_MatToExcel(OPDglobalE1_negX5posY5_full.getGlobalOPD(), "D:\OPDglobal_E1_negX5posY5_full_0.csv");
	//__ end check gloabl OPD in the field (x=-1) for many ray


	// ___ test field x=0.5 y=0.5
	// single ray tracing
	Ray_LLT cheifE1_posX5posY5({ 0.5,0.5,0.0 }, { -0.5,-0.5,30.0 }, 1.0);
	Ray_LLT rayE1_0_posX5posY5({ 0.5,0.5,0.0 }, { 0.0,0.0,30.0 }, 1.0);
	Ray_LLT rayE1_1_posX5posY5({ 0.5,0.5,0.0 }, { -1.0,-0.5,30.0 }, 1.0);
	Ray_LLT rayE1_2_posX5posY5({ 0.5,0.5,0.0 }, { -1.0, 0.0,30.0 }, 1.0);
	Ray_LLT rayE1_3_posX5posY5({ 0.5,0.5,0.0 }, { -0.5,0.5,30.0 }, 1.0);
	Ray_LLT rayE1_4_posX5posY5({ 0.5,0.5,0.0 }, { -1.5, -0.5,30.0 }, 1.0);
	Ray_LLT rayE1_5_posX5posY5({ 0.5,0.5,0.0 }, { -0.5,-1.5,30.0 }, 1.0);
	Ray_LLT rayE1_6_posX5posY5({ 0.5,0.5,0.0 }, { 0.5,-0.5,30.0 }, 1.0);

	LightRayStruct chiefLightRayE1_posX5posY5(mLight, cheifE1_posX5posY5, 1);
	LightRayStruct lightRayE1_0_posX5posY5(mLight, rayE1_0_posX5posY5, 1);
	LightRayStruct lightRayE1_1_posX5posY5(mLight, rayE1_1_posX5posY5, 1);
	LightRayStruct lightRayE1_2_posX5posY5(mLight, rayE1_2_posX5posY5, 1);
	LightRayStruct lightRayE1_3_posX5posY5(mLight, rayE1_3_posX5posY5, 1);
	LightRayStruct lightRayE1_4_posX5posY5(mLight, rayE1_4_posX5posY5, 1);
	LightRayStruct lightRayE1_5_posX5posY5(mLight, rayE1_5_posX5posY5, 1);
	LightRayStruct lightRayE1_6_posX5posY5(mLight, rayE1_6_posX5posY5, 1);

	// test rays to calculate OPD
	std::vector<LightRayStruct> lightRayE1_posX5posY5{ lightRayE1_0_posX5posY5, lightRayE1_1_posX5posY5, lightRayE1_2_posX5posY5, lightRayE1_3_posX5posY5, lightRayE1_4_posX5posY5, lightRayE1_5_posX5posY5, lightRayE1_6_posX5posY5 };
	// calc global OPD optical achse for some rays
	OPD OPDglobalE1_posX5posY5(/*exit pupil*/ exitPupilE1_ptr,  /*optical system*/ optSysE1,
		/*fill apertur stop with light ray*/ lightRayE1_posX5posY5, /*chief ray*/ chiefLightRayE1_posX5posY5, /*scalling*/ 0);
	std::vector<real> checkOPDE1_posX5posY5 = OPDglobalE1_posX5posY5.getVecWithAllCalcGlobalOPD();
	std::vector<real> zemaxDataOPD_E1_posX5posY5 = { -0.073021394003,-0.033426559927, -0.063324279640, -0.079115477159, 4.26228059E-003, 4.26228059E-003, -0.079115477159 };
	bool checkerOPD_E1_posX5posY5 = Math::compareTwoSTDVecors_decimals(checkOPDE1_posX5posY5, zemaxDataOPD_E1_posX5posY5, 6);
	workTheSystem.push_back(checkerOPD_E1_posX5posY5);

	//__ start check gloabl OPD on opt axis
	//fill aperture stop with many lightrays
	FillApertureStop fillAperStopE1_posX5posY5({ 0.5,0.5,0.0 }, 1, { 0.0,0.0,30.0 }, { 0.0,0.0,1.0 }, /*rings*/6, /*arms*/8, 1.0, mLight);
	// calc global OPD on optical achse for many rays
	OPD OPDglobalE1_posX5posY5_full(/*exit pupil*/ exitPupilE1_ptr,  /*optical system*/ optSysE1,
		/*fill apertur stop with light ray*/ fillAperStopE1_posX5posY5.getVectorWithLightRays(), /*chief ray*/ fillAperStopE1_posX5posY5.getVectorWithLightRays().at(0), /*scalling*/ 0);
	OPDglobalE1_posX5posY5_full.exportCV_MatToExcel(OPDglobalE1_posX5posY5_full.getGlobalOPD(), "D:\OPDglobal_E1_posX5posY5_full_0.csv");
	//__ end check gloabl OPD in the field for many ray


	// ___ test field x=-1.0 y=-1.0
	// single ray tracing
	Ray_LLT cheifE1_negX1negY1({ -1.0,-1.0,0.0 }, { 1.0,1.0,30.0 }, 1.0);
	Ray_LLT rayE1_0_negX1negY1({ -1.0,-1.0,0.0 }, { 0.0,1.0,30.0 }, 1.0);
	Ray_LLT rayE1_1_negX1negY1({ -1.0,-1.0,0.0 }, { 1.0,0.5,30.0 }, 1.0);
	Ray_LLT rayE1_2_negX1negY1({ -1.0,-1.0,0.0 }, { 1.0, 0.0,30.0 }, 1.0);
	Ray_LLT rayE1_3_negX1negY1({ -1.0,-1.0,0.0 }, { 0.5,0.5,30.0 }, 1.0);
	Ray_LLT rayE1_4_negX1negY1({ -1.0,-1.0,0.0 }, { 1.5, 0.5,30.0 }, 1.0);
	Ray_LLT rayE1_5_negX1negY1({ -1.0,-1.0,0.0 }, { 0.5,1.5,30.0 }, 1.0);
	Ray_LLT rayE1_6_negX1negY1({ -1.0,-1.0,0.0 }, { 1.5, 1.0,30.0 }, 1.0);

	LightRayStruct chiefLightRayE1_negX1negY1(mLight, cheifE1_negX1negY1, 1);
	LightRayStruct lightRayE1_0_negX1negY1(mLight, rayE1_0_negX1negY1, 1);
	LightRayStruct lightRayE1_1_negX1negY1(mLight, rayE1_1_negX1negY1, 1);
	LightRayStruct lightRayE1_2_negX1negY1(mLight, rayE1_2_negX1negY1, 1);
	LightRayStruct lightRayE1_3_negX1negY1(mLight, rayE1_3_negX1negY1, 1);
	LightRayStruct lightRayE1_4_negX1negY1(mLight, rayE1_4_negX1negY1, 1);
	LightRayStruct lightRayE1_5_negX1negY1(mLight, rayE1_5_negX1negY1, 1);
	LightRayStruct lightRayE1_6_negX1negY1(mLight, rayE1_6_negX1negY1, 1);

	// test rays to calculate OPD
	std::vector<LightRayStruct> lightRayE1_negX1negY1{ lightRayE1_0_negX1negY1, lightRayE1_1_negX1negY1, lightRayE1_2_negX1negY1, lightRayE1_3_negX1negY1, lightRayE1_4_negX1negY1, lightRayE1_5_negX1negY1, lightRayE1_6_negX1negY1 };
	// calc global OPD optical achse for some rays
	OPD OPDglobalE1_negX1negY1(/*exit pupil*/ exitPupilE1_ptr,  /*optical system*/ optSysE1,
		/*fill apertur stop with light ray*/ lightRayE1_negX1negY1, /*chief ray*/ chiefLightRayE1_negX1negY1, /*scalling*/ 0);
	std::vector<real> checkOPDE1_negX1negY1 = OPDglobalE1_negX1negY1.getVecWithAllCalcGlobalOPD();
	std::vector<real> zemaxDataOPD_E1_negX1negY1 = { -0.030794167181, -0.026544479355,-0.030794167181,  -0.032326281304,-0.034954574372, 0.034954574372, -5.7937563E-003 };
	bool checkerOPD_E1_negX1negY1 = Math::compareTwoSTDVecors_decimals(checkOPDE1_negX1negY1, zemaxDataOPD_E1_negX1negY1, 6);
	workTheSystem.push_back(checkerOPD_E1_negX1negY1);

	//__ start check gloabl OPD on opt axis
	//fill aperture stop with many lightrays
	FillApertureStop fillAperStopE1_negX1negY1({ -1.0,-1.0,0.0 }, 1, { 0.0,0.0,30.0 }, { 0.0,0.0,1.0 }, /*rings*/6, /*arms*/8, 1.0, mLight);
	// calc global OPD on optical achse for many rays
	OPD OPDglobalE1_negX1negY1_full(/*exit pupil*/ exitPupilE1_ptr,  /*optical system*/ optSysE1,
		/*fill apertur stop with light ray*/ fillAperStopE1_negX1negY1.getVectorWithLightRays(), /*chief ray*/ fillAperStopE1_negX1negY1.getVectorWithLightRays().at(0), /*scalling*/ 0);
	OPDglobalE1_negX1negY1_full.exportCV_MatToExcel(OPDglobalE1_negX1negY1_full.getGlobalOPD(), "D:\OPDglobal_E1_negX1negY1_full_0.csv");
	//__ end check gloabl OPD in the field for many rayB

	//***************************************************************************************************************************
	//*********** next we set the scalling to 1 *********************************************************************************
	//***************************************************************************************************************************


	

	//**********************************************************************************
	//**********************************************************************************
	//**********************************************************************************
	// next optical system
	// here is the exitpupil bevor the image surface
	//**********************************************************************************
	//**********************************************************************************
	//**********************************************************************************

	// test rays to calculate OPD
	// calc global OPD optical achse 
	OPD OPDglobalE1_optAchse_1(/*exit pupil*/ exitPupilE1_ptr,  /*optical system*/ optSysE1,
		/*fill apertur stop with light ray*/ lightRayE1_optAchse, /*chief ray*/ chiefLightRayE1_optA, /*scalling*/ 1);
	std::vector<real> checkOPDE1_optA_1 = OPDglobalE1_optAchse_1.getVecWithAllCalcGlobalOPD();
	bool checkerOPD_E1_optA_1 = Math::compareTwoSTDVecors_decimals(checkOPDE1_optA_1, zemaxDataOPD_E1_optA, 8);
	workTheSystem.push_back(checkerOPD_E1_optA_1);
	//___ end test opt achse

	//__ start check gloabl OPD on opt achses
	// calc global OPD on optical achse for many rays
	OPD OPDglobalE1_optAchse_full_1(/*exit pupil*/ exitPupilE1_ptr,  /*optical system*/ optSysE1,
		/*fill apertur stop with light ray*/ fillAperStopE1_optAchse.getVectorWithLightRays(), /*chief ray*/ fillAperStopE1_optAchse.getVectorWithLightRays().at(0), /*scalling*/ 1);
	OPDglobalE1_optAchse_full_1.exportCV_MatToExcel(OPDglobalE1_optAchse_full_1.getGlobalOPD(), "D:\OPDglobal_E1_optAchse_1.csv");
	//__ end check gloabl OPD in the field (y=-1) for many ray


	// test rays to calculate OPD
	// calc global OPD optical achse for some rays
	OPD OPDglobalE1_Y1_1(/*exit pupil*/ exitPupilE1_ptr,  /*optical system*/ optSysE1,
		/*fill apertur stop with light ray*/ lightRayE1_Y1, /*chief ray*/ chiefLightRayE1_Y1, /*scalling*/ 1);
	std::vector<real> checkOPDE1_Y1_1 = OPDglobalE1_Y1_1.getVecWithAllCalcGlobalOPD();
	bool checkerOPD_E1_Y1_1 = Math::compareTwoSTDVecors_decimals(checkOPDE1_Y1_1, zemaxDataOPD_E1_Y1, 7);
	workTheSystem.push_back(checkerOPD_E1_Y1_1);
	//___ end test opt achse

	//__ start check gloabl OPD on opt axis
	// calc global OPD on optical achse for many rays
	OPD OPDglobalE1_Y1_full_1(/*exit pupil*/ exitPupilE1_ptr,  /*optical system*/ optSysE1,
		/*fill apertur stop with light ray*/ fillAperStopE1_Y1.getVectorWithLightRays(), /*chief ray*/ fillAperStopE1_Y1.getVectorWithLightRays().at(0), /*scalling*/ 1);
	OPDglobalE1_Y1_full_1.exportCV_MatToExcel(OPDglobalE1_Y1_full_1.getGlobalOPD(), "D:\OPDglobal_E1_Y1_full_1.csv");
	//__ end check gloabl OPD in the field  for many ray

	// test rays to calculate OPD
	// calc global OPD optical achse for some rays
	OPD OPDglobalE1_negX1_1(/*exit pupil*/ exitPupilE1_ptr,  /*optical system*/ optSysE1,
		/*fill apertur stop with light ray*/ lightRayE1_negX1, /*chief ray*/ chiefLightRayE1_negX1, /*scalling*/ 1);
	std::vector<real> checkOPDE1_negX1_1 = OPDglobalE1_negX1_1.getVecWithAllCalcGlobalOPD();
	bool checkerOPD_E1_negX1_1 = Math::compareTwoSTDVecors_decimals(checkOPDE1_negX1_1, zemaxDataOPD_E1_negX1, 7);
	workTheSystem.push_back(checkerOPD_E1_negX1_1);

	//__ start check gloabl OPD on opt axis
	// calc global OPD on optical achse for many rays
	OPD OPDglobalE1_negX1_full_1(/*exit pupil*/ exitPupilE1_ptr,  /*optical system*/ optSysE1,
		/*fill apertur stop with light ray*/ fillAperStopE1_negX1.getVectorWithLightRays(), /*chief ray*/ fillAperStopE1_negX1.getVectorWithLightRays().at(0), /*scalling*/ 1);
	OPDglobalE1_negX1_full_1.exportCV_MatToExcel(OPDglobalE1_negX1_full_1.getGlobalOPD(), "D:\OPDglobal_E1_negX1_full_1.csv");
	//__ end check gloabl OPD in the field (x=-1) for many ray


	// test rays to calculate OPD
	// calc global OPD optical achse for some rays
	OPD OPDglobalE1_negX5posY5_1(/*exit pupil*/ exitPupilE1_ptr,  /*optical system*/ optSysE1,
		/*fill apertur stop with light ray*/ lightRayE1_negX5posY5, /*chief ray*/ chiefLightRayE1_negX5posY5, /*scalling*/ 1);
	std::vector<real> checkOPDE1_negX5posY5_1 = OPDglobalE1_negX5posY5_1.getVecWithAllCalcGlobalOPD();
	bool checkerOPD_E1_negX5posY5_1 = Math::compareTwoSTDVecors_decimals(checkOPDE1_negX5posY5_1, zemaxDataOPD_E1_negX5posY5, 6);
	workTheSystem.push_back(checkerOPD_E1_negX5posY5_1);

	//__ start check gloabl OPD on opt axis
	// calc global OPD on optical achse for many rays
	OPD OPDglobalE1_negX5posY5_full_1(/*exit pupil*/ exitPupilE1_ptr,  /*optical system*/ optSysE1,
		/*fill apertur stop with light ray*/ fillAperStopE1_negX5posY5.getVectorWithLightRays(), /*chief ray*/ fillAperStopE1_negX5posY5.getVectorWithLightRays().at(0), /*scalling*/ 1);
	OPDglobalE1_negX5posY5_full_1.exportCV_MatToExcel(OPDglobalE1_negX5posY5_full_1.getGlobalOPD(), "D:\OPDglobal_E1_negX5posY5_full_1.csv");
	//__ end check gloabl OPD in the field (x=-1) for many ray

	// test rays to calculate OPD
	// calc global OPD optical achse for some rays
	OPD OPDglobalE1_posX5posY5_1(/*exit pupil*/ exitPupilE1_ptr,  /*optical system*/ optSysE1,
		/*fill apertur stop with light ray*/ lightRayE1_posX5posY5, /*chief ray*/ chiefLightRayE1_posX5posY5, /*scalling*/ 1);
	std::vector<real> checkOPDE1_posX5posY5_1 = OPDglobalE1_posX5posY5_1.getVecWithAllCalcGlobalOPD();
	bool checkerOPD_E1_posX5posY5_1 = Math::compareTwoSTDVecors_decimals(checkOPDE1_posX5posY5_1, zemaxDataOPD_E1_posX5posY5, 6);
	workTheSystem.push_back(checkerOPD_E1_posX5posY5_1);

	//__ start check gloabl OPD on opt axis
	// calc global OPD on optical achse for many rays
	OPD OPDglobalE1_posX5posY5_full_1(/*exit pupil*/ exitPupilE1_ptr,  /*optical system*/ optSysE1,
		/*fill apertur stop with light ray*/ fillAperStopE1_posX5posY5.getVectorWithLightRays(), /*chief ray*/ fillAperStopE1_posX5posY5.getVectorWithLightRays().at(0), /*scalling*/ 1);
	OPDglobalE1_posX5posY5_full_1.exportCV_MatToExcel(OPDglobalE1_posX5posY5_full_1.getGlobalOPD(), "D:\OPDglobal_E1_posX5posY5_full_1.csv");
	//__ end check gloabl OPD in the field for many ray


	// test rays to calculate OPD
	// calc global OPD optical achse for some rays
	OPD OPDglobalE1_negX1negY1_1(/*exit pupil*/ exitPupilE1_ptr,  /*optical system*/ optSysE1,
		/*fill apertur stop with light ray*/ lightRayE1_negX1negY1, /*chief ray*/ chiefLightRayE1_negX1negY1, /*scalling*/ 1);
	std::vector<real> checkOPDE1_negX1negY1_1 = OPDglobalE1_negX1negY1_1.getVecWithAllCalcGlobalOPD();
	bool checkerOPD_E1_negX1negY1_1 = Math::compareTwoSTDVecors_decimals(checkOPDE1_negX1negY1_1, zemaxDataOPD_E1_negX1negY1, 6);
	workTheSystem.push_back(checkerOPD_E1_negX1negY1_1);

	//__ start check gloabl OPD on opt axis
	// calc global OPD on optical achse for many rays
	OPD OPDglobalE1_negX1negY1_full_1(/*exit pupil*/ exitPupilE1_ptr,  /*optical system*/ optSysE1,
		/*fill apertur stop with light ray*/ fillAperStopE1_negX1negY1.getVectorWithLightRays(), /*chief ray*/ fillAperStopE1_negX1negY1.getVectorWithLightRays().at(0), /*scalling*/ 1);
	OPDglobalE1_negX1negY1_full_1.exportCV_MatToExcel(OPDglobalE1_negX1negY1_full_1.getGlobalOPD(), "D:\OPDglobal_E1_negX1negY1_full_1.csv");
	//__ end check gloabl OPD in the field for many rayB

	bool workReturn = Math::checkTrueOfVectorElements(workTheSystem);
	return workReturn;

}