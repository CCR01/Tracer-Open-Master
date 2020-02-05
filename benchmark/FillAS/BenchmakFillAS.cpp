#include "BenchmarkFillAS.h"
#include <iostream>
#include "..\..\LowLevelTracing\Surfaces\SphericalSurface_LLT.h"
#include "..\..\LowLevelTracing\Surfaces\PlanGeometry_LLT.h"
#include "..\..\LowLevelTracing\Interaction\RefractedRay_LLT.h"
#include "..\..\LowLevelTracing\Interaction\Absorb_LLT.h"
#include "..\..\Analyse\Spot.h"

// check methodes of class FillEntrancePupilWithLightRays
bool BenchmarkFillAS::chekMethodesFillAS()
{
	std::vector<bool> checkMethodesFillAperStop;

	// check calcRotationMatrixAroundVector
	
	// rotate matrix around vector 
	Matrix3x3AndExist rotate_X_Axis = Math::calcRotationMatrixAroundVector({ /*Vektor um den rotiert wird*/ 1.0,0.0,0.0 }, /*Winkel um den man rotiert*/ PI);
	double  matrixCheck_X_Rotaion[3][3] = { /*Rotations Matrix - Werte auf 10 Nachkommastellen eintragen*/ /*Spalte1*/ {1.0,0.0,0.0}, /*Spalte2*/ {0.0,-1.0,0.0}, /*Spalte3*/ {0.0,0.0,-1.0} };
	bool check_X_Rotation = Math::compareRoundedTwoMatrices3x3(rotate_X_Axis.Matrix, matrixCheck_X_Rotaion, 10);
	checkMethodesFillAperStop.push_back(check_X_Rotation);

	// rotate matrix around y-axis
	Matrix3x3AndExist rotate_Y_Axis = Math::calcRotationMatrixAroundVector({ 0.0,1.0,0.0 }, PI);
	double  matrixCheck_Y_Rotaion[3][3] = { { -1.0,0.0,0.0 },{ 0.0,1.0,0.0 },{ 0.0,0.0,-1.0} };
	bool check_Y_Rotation = Math::compareRoundedTwoMatrices3x3(rotate_Y_Axis.Matrix, matrixCheck_Y_Rotaion, 10);
	checkMethodesFillAperStop.push_back(check_Y_Rotation);
	
	// rotation matrix around z-axis
	Matrix3x3AndExist rotate_Z_Axis = Math::calcRotationMatrixAroundVector({ 0.0,0.0,1.0 }, PI);
	double matrixCheck_Z_Rotaion[3][3] = { { -1.0,0.0,0.0 },{ 0.0,-1.0,0.0 },{ 0.0,0.0,1.0 } };
	bool check_Z_Rotation = Math::compareRoundedTwoMatrices3x3(rotate_Z_Axis.Matrix, matrixCheck_Z_Rotaion, 10);
	checkMethodesFillAperStop.push_back(check_Z_Rotation);

	// rotate matrix around vector {1.5,5.0,3.0} 
	Matrix3x3AndExist rotate_1_Axis = Math::calcRotationMatrixAroundVector({ 1.5,5.0,3.0 }, PI / 9);
	double matrixCheck_1_Rotation[3][3] = { { 1.0753842240,1.4783657741,-1.4387175102 },{ -0.5737550859,2.4473771011,1.4176409032 },{ 1.9814839231,0.3915804732,1.4824590337 } };
	bool check_1_Rotation = Math::compareRoundedTwoMatrices3x3(rotate_1_Axis.Matrix, matrixCheck_1_Rotation, 9);
	checkMethodesFillAperStop.push_back(check_1_Rotation);


	// rotate matrix around vector {-0.25,-7.8,-15.4} 
	Matrix3x3AndExist rotate_2_Axis = Math::calcRotationMatrixAroundVector({ -0.25,-7.8,-15.4 }, PI / 7);
	double matrixCheck_2_Rotation[3][3] = { { 0.9071583137,-6.4886988748,3.7655630237 },{ 6.8749202900,6.9260229447,11.7871486528 },{ -3.0030233065,12.0040905223,24.3871921562 } };
	bool check_2_Rotation = Math::compareRoundedTwoMatrices3x3(rotate_2_Axis.Matrix, matrixCheck_2_Rotation, 10);
	checkMethodesFillAperStop.push_back(check_2_Rotation);


	// rotate matrix around vector {-5.867,0.62,12.81} 
	Matrix3x3AndExist rotate_3_Axis = Math::calcRotationMatrixAroundVector({ -5.867,0.62,12.81 }, PI / 9);
	double matrixCheck_3_Rotation[3][3] = { { 3.0155744725,4.1619075318,-4.7445301641 },{ -4.6006485402,0.9628747774,-1.5276589137 },{ -4.3204251863,2.4856054481, 10.8358983510 } };
	bool check_3_Rotation = Math::compareRoundedTwoMatrices3x3(rotate_3_Axis.Matrix, matrixCheck_3_Rotation, 10);
	checkMethodesFillAperStop.push_back(check_3_Rotation);


	// rotate matrix around vector {14.73,-23.29,0.392} 
	Matrix3x3AndExist rotate_4_Axis = Math::calcRotationMatrixAroundVector({ 14.73,-23.29,0.392 }, PI / 7);
	double matrixCheck_4_Rotation[3][3] = { { 22.3880407894,-33.8037061046,10.6769738858 },{ -34.1438709561,54.6178415679,5.4869849311 },{ -9.5333306823,-7.2952300233,0.9161863878 } };
	bool check_4_Rotation = Math::compareRoundedTwoMatrices3x3(rotate_4_Axis.Matrix, matrixCheck_4_Rotation, 10);
	checkMethodesFillAperStop.push_back(check_4_Rotation);

	// rotate matrix around vector {17.23,4.07,-3.97} 
	Matrix3x3AndExist rotate_5_Axis = Math::calcRotationMatrixAroundVector({ 17.23,4.07,-3.97 }, PI / 4);
	double matrixCheck_5_Rotation[3][3] = { { 87.6591660407,17.7322452305,-22.9127287352 },{ 23.3466730731,5.5588536615,7.4509104996 },{ -17.1568795364,-16.9159891801,5.3233675136 } };
	bool check_5_Rotation = Math::compareRoundedTwoMatrices3x3(rotate_5_Axis.Matrix, matrixCheck_5_Rotation, 9);
	checkMethodesFillAperStop.push_back(check_5_Rotation);

	// rotate matrix around vector {-5.21,-10.5,3} 
	Matrix3x3AndExist rotate_6_Axis = Math::calcRotationMatrixAroundVector({ -5.21,-10.5,3 }, PI / 4);
	double matrixCheck_6_Rotation[3][3] = { { 8.6574296020,18.1440438787,2.8467001924 },{ 13.9014031916,32.9985841554,-12.9101627226 },{ -12.0025422125,-5.5421100626,3.3431457505 } };
	bool check_6_Rotation = Math::compareRoundedTwoMatrices3x3(rotate_6_Axis.Matrix, matrixCheck_6_Rotation, 8);
	checkMethodesFillAperStop.push_back(check_6_Rotation);

	// rotate matrix around vector {7.91,-17.4,-2,13} 
	Matrix3x3AndExist rotate_7_Axis =  Math::calcRotationMatrixAroundVector({ 7.91,-17.4,-2.13 }, PI / 2);
	double matrixCheck_7_Rotation[3][3] = { { 62.5681000000,-139.7640000000,0.5517000000 },{ -135.5040000000,302.7600000000,44.9720000000 },{ -34.2483000000,29.1520000000, 4.5369000000 } };
	bool check_7_Rotation = Math::compareRoundedTwoMatrices3x3(rotate_7_Axis.Matrix, matrixCheck_7_Rotation, 8);
	checkMethodesFillAperStop.push_back(check_7_Rotation);

	// rotate matrix around vector {-8.2,56,-0.79} 
	Matrix3x3AndExist rotate_8_Axis = Math::calcRotationMatrixAroundVector({ -8.2,56,-0.79 }, PI / 2);
	double matrixCheck_8_Rotation[3][3] = { { 67.2400000000,-459.9900000000,-49.5220000000 },{ -458.410000000,3136.000000000,-52.4400000000 },{ 62.4780000000,-36.040000000,0.6241000000 } };
	bool check_8_Rotation = Math::compareRoundedTwoMatrices3x3(rotate_8_Axis.Matrix, matrixCheck_8_Rotation, 8);
	checkMethodesFillAperStop.push_back(check_8_Rotation);

	// rotate matrix around vector {0.234,1.527,0.981} 
	Matrix3x3AndExist rotate_9_Axis = Math::calcRotationMatrixAroundVector({ 0.234,1.527,0.981 }, PI / 3);
	double matrixCheck_9_Rotation[3][3] = { { 0.5273780000,1.0282299211,-1.2076437916 },{ -0.6709119211,1.66586450000,0.9516434445 },{ 1.4371977916,0.54634355555,0.9811805000 } };
	bool check_9_Rotation = Math::compareRoundedTwoMatrices3x3(rotate_9_Axis.Matrix, matrixCheck_9_Rotation, 8);
	checkMethodesFillAperStop.push_back(check_9_Rotation);

	// rotate matrix around vector {-13.2,103.1,79.8} 
	Matrix3x3AndExist rotate_10_Axis = Math::calcRotationMatrixAroundVector({ -13.2,103.1,79.8 }, PI *3 / 2 );
	double matrixCheck_10_Rotation[3][3] = { { 174.2400000000,-1440.7200000000,-950.2600000000 },{ -1281.1200000000,10629.6100000000,8240.5800000000 },{ -1156.4600000000,8214.180000000,6368.0400000000 } };
	bool check_10_Rotation = Math::compareRoundedTwoMatrices3x3(rotate_10_Axis.Matrix, matrixCheck_10_Rotation, 8);
	checkMethodesFillAperStop.push_back(check_10_Rotation);

	// rotate matrix around vector {0.358,-67.2,121.9} 
	Matrix3x3AndExist rotate_11_Axis = Math::calcRotationMatrixAroundVector({ 0.358,-67.2,121.9 }, PI *3 / 2 );
	double matrixCheck_11_Rotation[3][3] = { { 0.1281640000,-145.9576000000,-23.5598000000 },{ 97.8424000000,4515.8400000000,-8192.0380000000 },{ 110.8402000000,-8191.3220000000,14859.61000000000 } };
	bool check_11_Rotation = Math::compareRoundedTwoMatrices3x3(rotate_11_Axis.Matrix, matrixCheck_11_Rotation, 8);
	checkMethodesFillAperStop.push_back(check_11_Rotation);

	// rotate matrix around vector {0.322,20.4,-12.11} 
	Matrix3x3AndExist rotate_12_Axis = Math::calcRotationMatrixAroundVector({ 0.322,20.4,-12.11 }, PI / 6);
	double matrixCheck_12_Rotation[3][3] = { { 0.8799164258,-5.1749476724,-10.7224232200 },{ 6.9350523276,56.6208933649,-32.9366201475 },{ 9.6775767800,-33.2586201475,20.5136812854 } };
	bool check_12_Rotation = Math::compareRoundedTwoMatrices3x3(rotate_12_Axis.Matrix, matrixCheck_12_Rotation, 8);
	checkMethodesFillAperStop.push_back(check_12_Rotation);


	// rotate matrix around vector {-22.36,-7,0.22} 
	Matrix3x3AndExist rotate_13_Axis = Math::calcRotationMatrixAroundVector({ -22.36,-7,0.22 }, PI / 6);
	double matrixCheck_13_Rotation[3][3] = { { 67.8492506838,21.0797037997,2.8409521663 },{ 20.8597037997,7.4307806183,-11.3863208782 },{ -4.1590478337,10.9736791218,0.8725097742 } };
	bool check_13_Rotation = Math::compareRoundedTwoMatrices3x3(rotate_13_Axis.Matrix, matrixCheck_13_Rotation, 10);
	checkMethodesFillAperStop.push_back(check_13_Rotation);

	// rotate matrix around vector {33.2,-25.78,-10.04} 
	Matrix3x3AndExist rotate_14_Axis = Math::calcRotationMatrixAroundVector({ 33.2,-25.78,-10.04 }, PI *4 / 3);
	double matrixCheck_14_Rotation[3][3] = { { 1652.8600000000,-1275.1491049460,-522.3181349096 },{ -1292.5388950540,996.4126000000,359.4947565944 },{ -477.6658650904,416.9988434056,150.7024000000 } };
	bool check_14_Rotation = Math::compareRoundedTwoMatrices3x3(rotate_14_Axis.Matrix, matrixCheck_14_Rotation, 8);
	checkMethodesFillAperStop.push_back(check_14_Rotation);
	
	// rotate matrix around vector {-65.7,2.25,11.8} 
	Matrix3x3AndExist rotate_15_Axis = Math::calcRotationMatrixAroundVector({ -65.7,2.25,11.8 }, PI *4 / 3);
	double matrixCheck_15_Rotation[3][3] = { { 6474.2350000000,-231.9565997647,-1160.9414428415 },{ -211.5184002353,7.0937500000,96.7228690286 },{ -1164.8385571585,-17.0728690286,208.3600000000 } };
	bool check_15_Rotation = Math::compareRoundedTwoMatrices3x3(rotate_15_Axis.Matrix, matrixCheck_15_Rotation, 8);
	checkMethodesFillAperStop.push_back(check_15_Rotation);

	// rotate matrix around vector {-4.475,8.9,-0.33} 
	Matrix3x3AndExist rotate_16_Axis = Math::calcRotationMatrixAroundVector({ -4.475,8.9,-0.33 }, PI / 5);
	double matrixCheck_16_Rotation[3][3] = { { 4.6335710464,-7.8003447898,-4.9492545918 },{ -7.4124065233,15.9367808699,-3.1912560915 },{ 5.5133228990,2.0694219165,0.8298150437 } };
	bool check_16_Rotation = Math::compareRoundedTwoMatrices3x3(rotate_16_Axis.Matrix, matrixCheck_16_Rotation, 8);
	checkMethodesFillAperStop.push_back(check_16_Rotation);

	// rotate matrix around vector {-34.6,-58.2,-2.33} 
	Matrix3x3AndExist rotate_17_Axis = Math::calcRotationMatrixAroundVector({ -34.6,-58.2,-2.33 }, PI / 5);
	double matrixCheck_17_Rotation[3][3] = { { 229.4462320085,383.2167584494,49.6057696309 },{ 385.9558377251,647.7142929678,5.5610717315 },{ -18.8124337359,46.2358111901,1.8458446336 } };
	bool check_17_Rotation = Math::compareRoundedTwoMatrices3x3(rotate_17_Axis.Matrix, matrixCheck_17_Rotation, 4);
	checkMethodesFillAperStop.push_back(check_17_Rotation);

	// rotate matrix around vector {0,3.78,10.11} 
	Matrix3x3AndExist rotate_18_Axis = Math::calcRotationMatrixAroundVector({ 0,3.78,10.11 }, PI *2 / 5);
	double matrixCheck_18_Rotation[3][3] = { { 0.3090169944,9.6151813797,-3.5949936316 },{ -9.6151813797,10.1820585719,26.4064683464 },{ 3.5949936316,26.4064683464,70.9358410636 } };
	bool check_18_Rotation = Math::compareRoundedTwoMatrices3x3(rotate_18_Axis.Matrix, matrixCheck_18_Rotation, 6);
	checkMethodesFillAperStop.push_back(check_18_Rotation);

	// rotate matrix around vector {17.91,0,4.34} 
	Matrix3x3AndExist rotate_19_Axis = Math::calcRotationMatrixAroundVector({ 17.91,0,4.34 }, PI *2 / 5 );
	double matrixCheck_19_Rotation[3][3] = { { 221.9543228410,4.1275852807,53.7096944374 },{ -4.1275852807,0.3090169944,17.0334222068 },{ 53.7096944374,-17.0334222068,13.3240964951 } };
	bool check_19_Rotation = Math::compareRoundedTwoMatrices3x3(rotate_19_Axis.Matrix, matrixCheck_19_Rotation, 8);
	checkMethodesFillAperStop.push_back(check_19_Rotation);

	// rotate matrix around vector {7.98,22.3,0} 
	Matrix3x3AndExist rotate_20_Axis = Math::calcRotationMatrixAroundVector({ 7.98,22.3,0 }, PI *3 / 7 );
	double matrixCheck_20_Rotation[3][3] = { { 49.7326988512,138.3555097187,-21.7408924417 },{ 138.3555097187,386.8550856868,7.7799247392 },{ 21.7408924417,-7.7799247392,0.2225209340 } };
	bool check_20_Rotation = Math::compareRoundedTwoMatrices3x3(rotate_20_Axis.Matrix, matrixCheck_20_Rotation, 8);
	checkMethodesFillAperStop.push_back(check_20_Rotation);


	// rotate matrix around vector {0,-57.1,31.57} 
	Matrix3x3AndExist rotate_21_Axis = Math::calcRotationMatrixAroundVector({ 0,-57.1,31.57 }, PI * 3 / 7 );
	double matrixCheck_21_Rotation[3][3] = { { 0.2225209340,30.7784741876,55.6683837856 },{ -30.7784741876,2535.1230426535, -1401.5203059665 },{ -55.6683837856,-1401.5203059665,775.1086165445 } };
	bool check_21_Rotation = Math::compareRoundedTwoMatrices3x3(rotate_21_Axis.Matrix, matrixCheck_21_Rotation, 8);
	checkMethodesFillAperStop.push_back(check_21_Rotation);

	// rotate matrix around vector {14.37,0,-2.64} 
	Matrix3x3AndExist rotate_22_Axis = Math::calcRotationMatrixAroundVector({ 14.37,0,-2.64 }, PI * 7 / 3 );
	double matrixCheck_22_Rotation[3][3] = { { 103.7484500000,-2.2863070660,-18.9684000000 },{ 2.2863070660,0.50000000000,12.4447850524 },{ -18.9684000000,-12.4447850524,3.9848000000 } };
	bool check_22_Rotation = Math::compareRoundedTwoMatrices3x3(rotate_22_Axis.Matrix, matrixCheck_22_Rotation, 8);
	checkMethodesFillAperStop.push_back(check_21_Rotation);

	// rotate matrix around vector {46.78,-0.53,0} 
	Matrix3x3AndExist rotate_23_Axis = Math::calcRotationMatrixAroundVector({ 46.78,-0.53,0 }, PI / 8);
	double matrixCheck_23_Rotation[3][3] = { { 167.5035051780,-1.8872851986,0.2028222192 },{ -1.8872851986,0.9452617718,17.9019309660 },{ -0.2028222192,-17.9019309660,0.9238795325 } };
	bool check_23_Rotation = Math::compareRoundedTwoMatrices3x3(rotate_23_Axis.Matrix, matrixCheck_23_Rotation, 8);
	checkMethodesFillAperStop.push_back(check_22_Rotation);

	// rotate matrix around vector {-2.77,9.53,0} 
	Matrix3x3AndExist rotate_24_Axis = Math::calcRotationMatrixAroundVector({ -2.77,9.53,0 }, PI / 8);
	double matrixCheck_24_Rotation[3][3] = { { 1.5079442675,-2.0094357128,-3.6469731104 },{ -2.0094357128,7.8372088983,-1.0600331077 },{ 3.6469731104,1.0600331077,0.9238795325 } };
	bool check_24_Rotation = Math::compareRoundedTwoMatrices3x3(rotate_24_Axis.Matrix, matrixCheck_24_Rotation, 8);
	checkMethodesFillAperStop.push_back(check_23_Rotation);

	// rotate matrix around vector {34.73,0,-8.66} 
	Matrix3x3AndExist rotate_25_Axis = Math::calcRotationMatrixAroundVector({ 34.73,0,-8.66 }, PI / 8);
	double matrixCheck_25_Rotation[3][3] = { { 92.7383245527,-3.3140385243,-22.8941288187 },{ 3.3140385243,0.9238795325,13.2905956060 },{ -22.8941288187,-13.2905956060,6.6325796641 } };
	bool check_25_Rotation = Math::compareRoundedTwoMatrices3x3(rotate_25_Axis.Matrix, matrixCheck_25_Rotation, 10);
	checkMethodesFillAperStop.push_back(check_24_Rotation);

	

	RefractedRay_LLT refrac;
	Absorb_LLT absorb;
	Light_LLT light;
	light.setWavelength(550.0);

	SphericalSurface_LLT S0(/*radius*/20.0, /*semiHeight*/9.5, /*Apex of the sphere*/{ 0.0, 0.0, 50.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
	SphericalSurface_LLT S1(/*radius*/20.0, /*semiHeight*/9.5, /*Apex of the sphere*/{ 0.0, 0.0, 55.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
	PlanGeometry_LLT S2(/*semiHeight*/10.0, /*point*/{ 0.0,0.0,70.81519757297157 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiveSideA*/ 1.0, /*refractiveSideB*/ 1.0);
	
	OpticalSystem_LLT optSysE0;
	optSysE0.fillVectorSurfaceAndInteractingData(0, &S0, refrac.clone());
	optSysE0.fillVectorSurfaceAndInteractingData(1, &S1, refrac.clone());
	optSysE0.fillVectorSurfaceAndInteractingData(2, &S2, absorb.clone());

	FillApertureStop fillWithRay_optAchse(0,0, 2, { 0.0,0.0,50.0 }, { 0.0,0.0,1.0 }, /*rings*/6, /*arms*/8, 1.5,light);
	SequentialRayTracing seqTraceE0_optAchse(optSysE0);
	seqTraceE0_optAchse.seqRayTracingWithVectorOfLightRays(fillWithRay_optAchse.getVectorWithLightRays());
	Spot spotE0_optAchese(seqTraceE0_optAchse.getAllInterPointsAtSurf_i(2), seqTraceE0_optAchse.getAllInterPointsAtSurf_i(2).at(0));
	bool checkE0_optAchse = Math::compareTwoNumbers(spotE0_optAchese.getRMS_mm(), 0.228095, 6);
	checkMethodesFillAperStop.push_back(checkE0_optAchse);

	FillApertureStop fillWithRay_field_Y10(0, 10, 2, { 0.0,0.0,50.0 }, { 0.0,0.0,1.0 }, /*rings*/6, /*arms*/8, 1.5, light);
	SequentialRayTracing seqTraceE0_field_Y10(optSysE0);
	seqTraceE0_field_Y10.seqRayTracingWithVectorOfLightRays(fillWithRay_field_Y10.getVectorWithLightRays());
	Spot spotE0_field_Y10(seqTraceE0_field_Y10.getAllInterPointsAtSurf_i(2), seqTraceE0_field_Y10.getAllInterPointsAtSurf_i(2).at(0));
	bool checkE0_field_Y10 = Math::compareTwoNumbers(spotE0_field_Y10.getRMS_mm(), 0.189995, 6);
	checkMethodesFillAperStop.push_back(checkE0_field_Y10);

	FillApertureStop fillWithRay_field_Yneg20(0, -20, 2, { 0.0,0.0,50.0 }, { 0.0,0.0,1.0 }, /*rings*/6, /*arms*/8, 1.5, light);
	SequentialRayTracing seqTraceE0_field_Yneg20(optSysE0);
	seqTraceE0_field_Yneg20.seqRayTracingWithVectorOfLightRays(fillWithRay_field_Yneg20.getVectorWithLightRays());
	Spot spotE0_field_Yneg20(seqTraceE0_field_Yneg20.getAllInterPointsAtSurf_i(2), seqTraceE0_field_Yneg20.getAllInterPointsAtSurf_i(2).at(0));
	bool checkE0_field_Yneg20 = Math::compareTwoNumbers(spotE0_field_Yneg20.getRMS_mm(), 0.093580, 6);
	checkMethodesFillAperStop.push_back(checkE0_field_Yneg20);
	
	FillApertureStop fillWithRay_field_X5(5, 0, 2, { 0.0,0.0,50.0 }, { 0.0,0.0,1.0 }, /*rings*/6, /*arms*/8, 1.5, light);
	SequentialRayTracing seqTraceE0_field_X5(optSysE0);
	seqTraceE0_field_X5.seqRayTracingWithVectorOfLightRays(fillWithRay_field_X5.getVectorWithLightRays());
	Spot spotE0_field_X5(seqTraceE0_field_X5.getAllInterPointsAtSurf_i(2), seqTraceE0_field_X5.getAllInterPointsAtSurf_i(2).at(0));
	bool checkE0_field_X5 = Math::compareTwoNumbers(spotE0_field_X5.getRMS_mm(), 0.218570, 6);
	checkMethodesFillAperStop.push_back(checkE0_field_X5);

	FillApertureStop fillWithRay_field_Xneg15(-15, 0, 2, { 0.0,0.0,50.0 }, { 0.0,0.0,1.0 }, /*rings*/6, /*arms*/8, 1.5, light);
	SequentialRayTracing seqTraceE0_field_Xneg15(optSysE0);
	seqTraceE0_field_Xneg15.seqRayTracingWithVectorOfLightRays(fillWithRay_field_Xneg15.getVectorWithLightRays());
	Spot spotE0_field_Xneg15(seqTraceE0_field_Xneg15.getAllInterPointsAtSurf_i(2), seqTraceE0_field_Xneg15.getAllInterPointsAtSurf_i(2).at(0));
	bool checkE0_field_Xneg15 = Math::compareTwoNumbers(spotE0_field_Xneg15.getRMS_mm(), 0.143635, 6);
	checkMethodesFillAperStop.push_back(checkE0_field_Xneg15);

	FillApertureStop fillWithRay_field_Xneg5_Y5(-5, 5, 2, { 0.0,0.0,50.0 }, { 0.0,0.0,1.0 }, /*rings*/6, /*arms*/8, 1.5, light);
	SequentialRayTracing seqTraceE0_field_Xneg5_Y5(optSysE0);
	seqTraceE0_field_Xneg5_Y5.seqRayTracingWithVectorOfLightRays(fillWithRay_field_Xneg5_Y5.getVectorWithLightRays());
	Spot spotE0_field_Xneg5_Y5(seqTraceE0_field_Xneg5_Y5.getAllInterPointsAtSurf_i(2), seqTraceE0_field_Xneg5_Y5.getAllInterPointsAtSurf_i(2).at(0));
	bool checkE0_field_Xneg5_Y5 = Math::compareTwoNumbers(spotE0_field_Xneg5_Y5.getRMS_mm(), 0.209132, 6);
	checkMethodesFillAperStop.push_back(checkE0_field_Xneg5_Y5);

	FillApertureStop fillWithRay_field_X10_Yneg15(10, -15, 2, { 0.0,0.0,50.0 }, { 0.0,0.0,1.0 }, /*rings*/6, /*arms*/8, 1.5, light);
	SequentialRayTracing seqTraceE0_field_X10_Yneg15(optSysE0);
	seqTraceE0_field_X10_Yneg15.seqRayTracingWithVectorOfLightRays(fillWithRay_field_X10_Yneg15.getVectorWithLightRays());
	Spot spotE0_field_XnegX10_Yneg15(seqTraceE0_field_X10_Yneg15.getAllInterPointsAtSurf_i(2), seqTraceE0_field_X10_Yneg15.getAllInterPointsAtSurf_i(2).at(0));
	bool checkE0_field_X10_Yneg15 = Math::compareTwoNumbers(spotE0_field_XnegX10_Yneg15.getRMS_mm(), 0.113528, 6);
	checkMethodesFillAperStop.push_back(checkE0_field_X10_Yneg15);


	// *****************************************************************************************************************
	bool output = Math::checkTrueOfVectorElements(checkMethodesFillAperStop);
	return output;
	// *****************************************************************************************************************

}