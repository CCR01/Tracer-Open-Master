#pragma once
#include"testGlasses.h"
#include<vector>
//#include"..\..\basicdefinitions.h"
#include "..\..\Glasses\Glasses.h"
#include "..\..\LowLevelTracing\Math_LLT.h"

testGlasses::testGlasses() {};
testGlasses::~testGlasses() {};

bool testGlasses::checkGlasses()
{
	std::vector<bool> checkGlasses;
	glass glasses;
	glasses.loadGlassCatalog_Schott();
	
	//Air
	real resAir_S1 = glasses.getAir().calcRefractiveIndexSnellmeier1(587.6);
	bool checkAir_S1 = Math::compareTwoNumbers_decimals(1.0, resAir_S1, 4);
	checkGlasses.push_back(checkAir_S1);
	//F2_S1
	real resF2_S1 = glasses.get_F2_S1().calcRefractiveIndexSnellmeier1(587.6);
	bool checkF2_S1 = Math::compareTwoNumbers_decimals(1.620040, resF2_S1, 4);
	checkGlasses.push_back(checkF2_S1);
	//F5_S1
	real resF5_S1 = glasses.getF5_S1().calcRefractiveIndexSnellmeier1(587.6);
	bool checkF5_S1 = Math::compareTwoNumbers_decimals(1.603420, resF5_S1, 4);
	checkGlasses.push_back(checkF5_S1);
	//K10
	real resK10_S1 = glasses.getK10_S1().calcRefractiveIndexSnellmeier1(587.6);
	bool checkK10_S1 = Math::compareTwoNumbers_decimals(1.501371, resK10_S1, 4);
	checkGlasses.push_back(checkK10_S1);
	// K7
	real resK7_S1 = glasses.getK7_S1().calcRefractiveIndexSnellmeier1(587.6);
	bool checkK7_S1 = Math::compareTwoNumbers_decimals(1.511121, resK7_S1, 4);
	checkGlasses.push_back(checkK7_S1);
	//LAFN7
	real resLAFN7_S1 = glasses.getLAFN7_S1().calcRefractiveIndexSnellmeier1(587.6);
	bool checkLAFN7_S1 = Math::compareTwoNumbers_decimals(1.749502, resLAFN7_S1, 4);
	checkGlasses.push_back(checkLAFN7_S1);
	//LF5
	real resLF5_S1 = glasses.getLF5_S1().calcRefractiveIndexSnellmeier1(587.6);
	bool checkLF5_S1 = Math::compareTwoNumbers_decimals(1.581440, resLF5_S1, 4);
	checkGlasses.push_back(checkLF5_S1);
	//LLF1
	real resLLF1_S1 = glasses.getLLF1_S1().calcRefractiveIndexSnellmeier1(587.6);
	bool checkLLF1_S1 = Math::compareTwoNumbers_decimals(1.548140, resLLF1_S1, 4);
	checkGlasses.push_back(checkLLF1_S1);
	//NBAF10
	real resNBAF10_S1 = glasses.getNBAF10_S1().calcRefractiveIndexSnellmeier1(587.6);
	bool checkNBAF10_S1 = Math::compareTwoNumbers_decimals(1.670030, resNBAF10_S1, 4);
	checkGlasses.push_back(checkNBAF10_S1);
	//NBAF4
	real resNBAF4_S1 = glasses.getNBAF4_S1().calcRefractiveIndexSnellmeier1(587.6);
	bool checkNBAF4_S1 = Math::compareTwoNumbers_decimals(1.605683, resNBAF4_S1, 4);
	checkGlasses.push_back(checkNBAF4_S1);
	//NBAF51
	real resNBAF51_S1 = glasses.getNBAF51_S1().calcRefractiveIndexSnellmeier1(587.6);
	bool checkNBAF51_S1 = Math::compareTwoNumbers_decimals(1.652240, resNBAF51_S1, 4);
	checkGlasses.push_back(checkNBAF51_S1);
	//NBAF52
	real resNBAF52_S1 = glasses.getNBAF52_S1().calcRefractiveIndexSnellmeier1(587.6);
	bool checkNBAF52_S1 = Math::compareTwoNumbers_decimals(1.608631, resNBAF52_S1, 4);
	checkGlasses.push_back(checkNBAF52_S1);
	//NBAK1
	real resNBAK1_S1 = glasses.getNBAK1_S1().calcRefractiveIndexSnellmeier1(587.6);
	bool checkNBAK1_S1 = Math::compareTwoNumbers_decimals(1.572500, resNBAK1_S1, 4);
	checkGlasses.push_back(checkNBAK1_S1);
	//NBAK2
	real resNBAK2_S1 = glasses.getNBAK2_S1().calcRefractiveIndexSnellmeier1(587.6);
	bool checkNBAK2_S1 = Math::compareTwoNumbers_decimals(1.539960, resNBAK2_S1, 4);
	checkGlasses.push_back(checkNBAK2_S1);
	//NBAK4
	real resNBAK4_S1 = glasses.getNBAK4_S1().calcRefractiveIndexSnellmeier1(587.6);
	bool checkNBAK4_S1 = Math::compareTwoNumbers_decimals(1.568827, resNBAK4_S1, 4);
	checkGlasses.push_back(checkNBAK4_S1);
	//NBAK4HT
	real resNBAK4HT_S1 = glasses.getNBAK4HT_S1().calcRefractiveIndexSnellmeier1(587.6);
	bool checkNBAK4HT_S1 = Math::compareTwoNumbers_decimals(1.568827, resNBAK4HT_S1, 4);
	checkGlasses.push_back(checkNBAK4HT_S1);
	//NBALF4
	real resNBALF4_S1 = glasses.getNBALF4_S1().calcRefractiveIndexSnellmeier1(587.6);
	bool checkNBALF4_S1 = Math::compareTwoNumbers_decimals(1.579559, resNBALF4_S1, 4);
	checkGlasses.push_back(checkNBALF4_S1);
	//NBALF5
	real resNBALF5_S1 = glasses.getNBALF5_S1().calcRefractiveIndexSnellmeier1(587.6);
	bool checkNBALF5_S1 = Math::compareTwoNumbers_decimals(1.547390, resNBALF5_S1, 4);
	checkGlasses.push_back(checkNBALF5_S1);
	//NBASF2
	real resNBASF2_S1 = glasses.getNBASF2_S1().calcRefractiveIndexSnellmeier1(587.6);
	bool checkNBASF2_S1 = Math::compareTwoNumbers_decimals(1.664460, resNBASF2_S1, 4);
	checkGlasses.push_back(checkNBASF2_S1);
	//NBASF64
	real resNBASF64_S1 = glasses.getNBASF64_S1().calcRefractiveIndexSnellmeier1(587.6);
	bool checkNBASF64_S1 = Math::compareTwoNumbers_decimals(1.704000, resNBASF64_S1, 4);
	checkGlasses.push_back(checkNBASF64_S1);
	//NBK10
	real resNBK10_S1 = glasses.getNBK10_S1().calcRefractiveIndexSnellmeier1(587.6);
	bool checkNBK10_S1 = Math::compareTwoNumbers_decimals(1.497821, resNBK10_S1, 4);
	checkGlasses.push_back(checkNBK10_S1);
	//NBK7
	real resNBK7_S1 = glasses.getNBK7_S1().calcRefractiveIndexSnellmeier1(587.6);
	bool checkNBK7_S1 = Math::compareTwoNumbers_decimals(1.516800, resNBK7_S1, 4);
	checkGlasses.push_back(checkNBK7_S1);
	//NBK7HT
	real resNBK7HT_S1 = glasses.getNBK7HT_S1().calcRefractiveIndexSnellmeier1(587.6);
	bool checkNBK7HT_S1 = Math::compareTwoNumbers_decimals(1.516800, resNBK7HT_S1, 4);
	checkGlasses.push_back(checkNBK7HT_S1);
	//NF2
	real resNF2_S1 = glasses.getNF2_S1().calcRefractiveIndexSnellmeier1(587.6);
	bool checkNF2_S1 = Math::compareTwoNumbers_decimals(1.620053, resNF2_S1, 5);
	checkGlasses.push_back(checkNF2_S1);
	//NFK5
	real resNFK5_S1 = glasses.getNFK5_S1().calcRefractiveIndexSnellmeier1(587.6);
	bool checkNFK5_S1 = Math::compareTwoNumbers_decimals(1.487490, resNFK5_S1, 4);
	checkGlasses.push_back(checkNFK5_S1);	
	//NFK51A
	real resNFK51A_S1 = glasses.getNFK51A_S1().calcRefractiveIndexSnellmeier1(587.6);
	bool checkNFK51A_S1 = Math::compareTwoNumbers_decimals(1.486561, resNFK51A_S1, 4);
	checkGlasses.push_back(checkNFK51A_S1);
	//NK5
	real resNK5_S1 = glasses.getNK5_S1().calcRefractiveIndexSnellmeier1(587.6);
	bool checkNK5_S1 = Math::compareTwoNumbers_decimals(1.522489, resNK5_S1, 4);
	checkGlasses.push_back(checkNK5_S1);
	//NKF9
	real resNKF9_S1 = glasses.getNKF9_S1().calcRefractiveIndexSnellmeier1(587.6);
	bool checkNKF9_S1 = Math::compareTwoNumbers_decimals(1.523459, resNKF9_S1, 4);
	checkGlasses.push_back(checkNKF9_S1);
	//NKZFS11
	real resNKZFS11_S1 = glasses.getNKZFS11_S1().calcRefractiveIndexSnellmeier1(587.6);
	bool checkNKZFS11_S1 = Math::compareTwoNumbers_decimals(1.637750, resNKZFS11_S1, 5);
	checkGlasses.push_back(checkNKZFS11_S1);
	//NKZFS2
	real resNKZFS2_S1 = glasses.getNKZFS2_S1().calcRefractiveIndexSnellmeier1(587.6);
	bool checkNKZFS2_S1 = Math::compareTwoNumbers_decimals(1.558360, resNKZFS2_S1, 4);
	checkGlasses.push_back(checkNKZFS2_S1);
	//NKZFS4
	real resNKZFS4_S1 = glasses.getNKZFS4_S1().calcRefractiveIndexSnellmeier1(587.6);
	bool checkNKZFS4_S1 = Math::compareTwoNumbers_decimals(1.613360, resNKZFS4_S1, 4);
	checkGlasses.push_back(checkNKZFS4_S1);
	//NKZFS4HT
	real resNKZFS4HT_S1 = glasses.getNKZFS4HT_S1().calcRefractiveIndexSnellmeier1(587.6);
	bool checkNKZFS4HT_S1 = Math::compareTwoNumbers_decimals(1.613360, resNKZFS4HT_S1, 4);
	checkGlasses.push_back(checkNKZFS4HT_S1);
	//NKZFS5
	real resNKZFS5_S1 = glasses.getNKZFS5_S1().calcRefractiveIndexSnellmeier1(587.6);
	bool checkNKZFS5_S1 = Math::compareTwoNumbers_decimals(1.654120, resNKZFS5_S1, 4);
	checkGlasses.push_back(checkNKZFS5_S1);
	//NKZFS8
	real resNKZFS8_S1 = glasses.getNKZFS8_S1().calcRefractiveIndexSnellmeier1(587.6);
	bool checkNKZFS8_S1 = Math::compareTwoNumbers_decimals(1.720470, resNKZFS8_S1, 4);
	checkGlasses.push_back(checkNKZFS8_S1);
	//NLAF2
	real resNLAF2_S1 = glasses.getNLAF2_S1().calcRefractiveIndexSnellmeier1(587.6);
	bool checkNLAF2_S1 = Math::compareTwoNumbers_decimals(1.743972, resNLAF2_S1, 4);
	checkGlasses.push_back(checkNLAF2_S1);
	//NLAF218.73448712E+001
	real resNLAF21_S1 = glasses.getNLAF21_S1().calcRefractiveIndexSnellmeier1(587.6);
	bool checkNLAF21_S1 = Math::compareTwoNumbers_decimals(1.788000, resNLAF21_S1, 4);
	checkGlasses.push_back(checkNLAF21_S1);
	//NLAF33
	real resNLAF33_S1 = glasses.getNLAF33_S1().calcRefractiveIndexSnellmeier1(587.6);
	bool checkNLAF33_S1 = Math::compareTwoNumbers_decimals(1.785825, resNLAF33_S1, 4); 
	checkGlasses.push_back(checkNLAF33_S1);
	//NLAF34
	real resNLAF34_S1 = glasses.getNLAF34_S1().calcRefractiveIndexSnellmeier1(587.6);
	bool checkNLAF34_S1 = Math::compareTwoNumbers_decimals(1.772500, resNLAF34_S1, 4);
	checkGlasses.push_back(checkNLAF34_S1);
	//NLAF35
	real resNLAF35_S1 = glasses.getNLAF35_S1().calcRefractiveIndexSnellmeier1(587.6);
	bool checkNLAF35_S1 = Math::compareTwoNumbers_decimals(1.743300, resNLAF35_S1, 4);
	checkGlasses.push_back(checkNLAF35_S1);
	//NLAF7
	real resNLAF7_S1 = glasses.getNLAF7_S1().calcRefractiveIndexSnellmeier1(587.6);
	bool checkNLAF7_S1 = Math::compareTwoNumbers_decimals(1.749500, resNLAF7_S1, 4);
	checkGlasses.push_back(checkNLAF7_S1);
	//NLAK10
	real resNLAK10_S1 = glasses.getNLAK10_S1().calcRefractiveIndexSnellmeier1(587.6);
	bool checkNLAK10_S1 = Math::compareTwoNumbers_decimals(1.720028, resNLAK10_S1, 4);
	checkGlasses.push_back(checkNLAK10_S1);
	//NLAK12
	real resNLAK12_S1 = glasses.getNLAK12_S1().calcRefractiveIndexSnellmeier1(587.6);
	bool checkNLAK12_S1 = Math::compareTwoNumbers_decimals(1.677900, resNLAK12_S1, 4);
	checkGlasses.push_back(checkNLAK12_S1);
	//NLAK14
	real resNLAK14_S1 = glasses.getNLAK14_S1().calcRefractiveIndexSnellmeier1(587.6);
	bool checkNLAK14_S1 = Math::compareTwoNumbers_decimals(1.696800, resNLAK14_S1, 4);
	checkGlasses.push_back(checkNLAK14_S1);
	//NLAK21
	real resNLAK21_S1 = glasses.getNLAK21_S1().calcRefractiveIndexSnellmeier1(587.6);
	bool checkNLAK21_S1 = Math::compareTwoNumbers_decimals(1.640495, resNLAK21_S1, 4); 
	checkGlasses.push_back(checkNLAK21_S1);
	//NLAK22
	real resNLAK22_S1 = glasses.getNLAK22_S1().calcRefractiveIndexSnellmeier1(587.6);
	bool checkNLAK22_S1 = Math::compareTwoNumbers_decimals(1.651130, resNLAK22_S1, 4);
	checkGlasses.push_back(checkNLAK22_S1);
	//NLAK33A
	real resNLAK33A_S1 = glasses.getNLAK33A_S1().calcRefractiveIndexSnellmeier1(587.6);
	bool checkNLAK33A_S1 = Math::compareTwoNumbers_decimals(1.753930, resNLAK33A_S1, 4);
	checkGlasses.push_back(checkNLAK33A_S1);
	//NLAK33B
	real resNLAK33B_S1 = glasses.getNLAK33B_S1().calcRefractiveIndexSnellmeier1(587.6);
	bool checkNLAK33B_S1 = Math::compareTwoNumbers_decimals(1.755000, resNLAK33B_S1, 4);
	checkGlasses.push_back(checkNLAK33B_S1);
	//NLAK34
	real resNLAK34_S1 = glasses.getNLAK34_S1().calcRefractiveIndexSnellmeier1(587.6);
	bool checkNLAK34_S1 = Math::compareTwoNumbers_decimals(1.729160, resNLAK34_S1, 4);
	checkGlasses.push_back(checkNLAK34_S1);
	//NLAK7
	real resNLAK7_S1 = glasses.getNLAK7_S1().calcRefractiveIndexSnellmeier1(587.6);
	bool checkNLAK7_S1 = Math::compareTwoNumbers_decimals(1.651600, resNLAK7_S1, 4);
	checkGlasses.push_back(checkNLAK7_S1);
	//NLAK8
	real resNLAK8_S1 = glasses.getNLAK8_S1().calcRefractiveIndexSnellmeier1(587.6);
	bool checkNLAK8_S1 = Math::compareTwoNumbers_decimals(1.713003, resNLAK8_S1, 4);
	checkGlasses.push_back(checkNLAK8_S1);
	//NLAK9
	real resNLAK9_S1 = glasses.getNLAK9_S1().calcRefractiveIndexSnellmeier1(587.6);
	bool checkNLAK9_S1 = Math::compareTwoNumbers_decimals(1.691002, resNLAK9_S1, 4);
	checkGlasses.push_back(checkNLAK9_S1);
	//NLASF31A
	real resNLASF31A_S1 = glasses.getNLASF31A_S1().calcRefractiveIndexSnellmeier1(587.6);
	bool checkNLASF31A_S1 = Math::compareTwoNumbers_decimals(1.883000, resNLASF31A_S1, 4);
	checkGlasses.push_back(checkNLASF31A_S1);
	//NLASF40
	real resNLASF40_S1 = glasses.getNLASF40_S1().calcRefractiveIndexSnellmeier1(587.6);
	bool checkNLASF40_S1 = Math::compareTwoNumbers_decimals(1.834044, resNLASF40_S1, 4);
	checkGlasses.push_back(checkNLASF40_S1);
	//NLASF41
	real resNLASF41_S1 = glasses.getNLASF41_S1().calcRefractiveIndexSnellmeier1(587.6);
	bool checkNLASF41_S1 = Math::compareTwoNumbers_decimals(1.835010, resNLASF41_S1, 4);
	checkGlasses.push_back(checkNLASF41_S1);
	//NLASF43
	real resNLASF43_S1 = glasses.getNLASF43_S1().calcRefractiveIndexSnellmeier1(587.6);
	bool checkNLASF43_S1 = Math::compareTwoNumbers_decimals(1.806100, resNLASF43_S1, 4);
	checkGlasses.push_back(checkNLASF43_S1);
	//NLASF44
	real resNLASF44_S1 = glasses.getNLASF44_S1().calcRefractiveIndexSnellmeier1(587.6);
	bool checkNLASF44_S1 = Math::compareTwoNumbers_decimals(1.804200, resNLASF44_S1, 4);
	checkGlasses.push_back(checkNLASF44_S1);
	//NLASF45
	real resNLASF45_S1 = glasses.getNLASF45_S1().calcRefractiveIndexSnellmeier1(587.6);
	bool checkNLASF45_S1 = Math::compareTwoNumbers_decimals(1.801070, resNLASF45_S1, 4);
	checkGlasses.push_back(checkNLASF45_S1);
	//NLASF45HT
	real resNLASF45HT_S1 = glasses.getNLASF45HT_S1().calcRefractiveIndexSnellmeier1(587.6);
	bool checkNLASF45HT_S1 = Math::compareTwoNumbers_decimals(1.801070, resNLASF45HT_S1, 4);
	checkGlasses.push_back(checkNLASF45HT_S1);
	//NLASF46A
	real resNLASF46A_S1 = glasses.getNLASF46A_S1().calcRefractiveIndexSnellmeier1(587.6);
	bool checkNLASF46A_S1 = Math::compareTwoNumbers_decimals(1.903660, resNLASF46A_S1, 4); 
	checkGlasses.push_back(checkNLASF46A_S1);
	//NLASF46B
	real resNLASF46B_S1 = glasses.getNLASF46B_S1().calcRefractiveIndexSnellmeier1(587.6);
	bool checkNLASF46B_S1 = Math::compareTwoNumbers_decimals(1.903660, resNLASF46B_S1, 4); 
	checkGlasses.push_back(checkNLASF46B_S1);
	//NLASF9
	real resNLASF9_S1 = glasses.getNLASF9_S1().calcRefractiveIndexSnellmeier1(587.6);
	bool checkNLASF9_S1 = Math::compareTwoNumbers_decimals(1.850249, resNLASF9_S1, 4); 
	checkGlasses.push_back(checkNLASF9_S1);
	//NLASF9HT
	real resNLASF9HT_S1 = glasses.getNLASF9HT_S1().calcRefractiveIndexSnellmeier1(587.6);
	bool checkNLASF9HT_S1 = Math::compareTwoNumbers_decimals(1.850249, resNLASF9HT_S1, 4); 
	checkGlasses.push_back(checkNLASF9HT_S1);
	//NPK51
	real resNPK51_S1 = glasses.getNPK51_S1().calcRefractiveIndexSnellmeier1(587.6);
	bool checkNPK51_S1 = Math::compareTwoNumbers_decimals(1.528554, resNPK51_S1, 4);
	checkGlasses.push_back(checkNPK51_S1);
	//NPK52A
	real resNPK52A_S1 = glasses.getNPK52A_S1().calcRefractiveIndexSnellmeier1(587.6);
	bool checkNPK52A_S1 = Math::compareTwoNumbers_decimals(1.497000, resNPK52A_S1, 4);
	checkGlasses.push_back(checkNPK52A_S1);
	//NPSK3
	real resNPSK3_S1 = glasses.getNPSK3_S1().calcRefractiveIndexSnellmeier1(587.6);
	bool checkNPSK3_S1 = Math::compareTwoNumbers_decimals(1.552322, resNPSK3_S1, 4);
	checkGlasses.push_back(checkNPSK3_S1);
	//NPSK53A
	real resNPSK53A_S1 = glasses.getNPSK53A_S1().calcRefractiveIndexSnellmeier1(587.6);
	bool checkNPSK53A_S1 = Math::compareTwoNumbers_decimals(1.618000, resNPSK53A_S1, 4);
	checkGlasses.push_back(checkNPSK53A_S1);
	//NSF1
	real resNSF1_S1 = glasses.getNSF1_S1().calcRefractiveIndexSnellmeier1(587.6);
	bool checkNSF1_S1 = Math::compareTwoNumbers_decimals(1.717360, resNSF1_S1, 4);
	checkGlasses.push_back(checkNSF1_S1);
	//NSF10
	real resNSF10_S1 = glasses.getNSF10_S1().calcRefractiveIndexSnellmeier1(587.6);
	bool checkNSF10_S1 = Math::compareTwoNumbers_decimals(1.728277, resNSF10_S1, 4); 
	checkGlasses.push_back(checkNSF10_S1);
	//NSF11
	real resNSF11_S1 = glasses.getNSF11_S1().calcRefractiveIndexSnellmeier1(587.6);
	bool checkNSF11_S1 = Math::compareTwoNumbers_decimals(1.784720, resNSF11_S1, 4); 
	checkGlasses.push_back(checkNSF11_S1);
	//NSF14
	real resNSF14_S1 = glasses.getNSF14_S1().calcRefractiveIndexSnellmeier1(587.6);
	bool checkNSF14_S1 = Math::compareTwoNumbers_decimals(1.761820, resNSF14_S1, 4); 
	checkGlasses.push_back(checkNSF14_S1);
	//NSF15
	real resNSF15_S1 = glasses.getNSF15_S1().calcRefractiveIndexSnellmeier1(587.6);
	bool checkNSF15_S1 = Math::compareTwoNumbers_decimals(1.698920, resNSF15_S1, 4);
	checkGlasses.push_back(checkNSF15_S1);
	//NSF2
	real resNSF2_S1 = glasses.getNSF2_S1().calcRefractiveIndexSnellmeier1(587.6);
	bool checkNSF2_S1 = Math::compareTwoNumbers_decimals(1.647690, resNSF2_S1, 4);
	checkGlasses.push_back(checkNSF2_S1);
	//NSF4
	real resNSF4_S1 = glasses.getNSF4_S1().calcRefractiveIndexSnellmeier1(587.6);
	bool checkNSF4_S1 = Math::compareTwoNumbers_decimals(1.755131, resNSF4_S1, 4);
	checkGlasses.push_back(checkNSF4_S1);
	//NSF5
	real resNSF5_S1 = glasses.getNSF5_S1().calcRefractiveIndexSnellmeier1(587.6);
	bool checkNSF5_S1 = Math::compareTwoNumbers_decimals(1.672707, resNSF5_S1, 4); 
	checkGlasses.push_back(checkNSF5_S1);
	//NSF57
	real resNSF57_S1 = glasses.getNSF57_S1().calcRefractiveIndexSnellmeier1(587.6);
	bool checkNSF57_S1 = Math::compareTwoNumbers_decimals(1.846660, resNSF57_S1, 4); 
	checkGlasses.push_back(checkNSF57_S1);
	//NSF57HT
	real resNSF57HT_S1 = glasses.getNSF57HT_S1().calcRefractiveIndexSnellmeier1(587.6);
	bool checkNSF57HT_S1 = Math::compareTwoNumbers_decimals(1.846660, resNSF57HT_S1, 4); 
	checkGlasses.push_back(checkNSF57HT_S1);
	//NSF57HTULTRA
	real resNSF57HTULTRA_S1 = glasses.getNSF57HTULTRA_S1().calcRefractiveIndexSnellmeier1(587.6);
	bool checkNSF57HTULTRA_S1 = Math::compareTwoNumbers_decimals(1.846660, resNSF57HTULTRA_S1, 4); 
	checkGlasses.push_back(checkNSF57HTULTRA_S1);
	//NSF6
	real resNSF6_S1 = glasses.getNSF6_S1().calcRefractiveIndexSnellmeier1(587.6);
	bool checkNSF6_S1 = Math::compareTwoNumbers_decimals(1.805180, resNSF6_S1, 4); 
	checkGlasses.push_back(checkNSF6_S1);
	//NSF66
	real resNSF66_S1 = glasses.getNSF66_S1().calcRefractiveIndexSnellmeier1(587.6);
	bool checkNSF66_S1 = Math::compareTwoNumbers_decimals(1.922860, resNSF66_S1, 4); 
	checkGlasses.push_back(checkNSF66_S1);
	//NSF6HT
	real resNSF6HT_S1 = glasses.getNSF6HT_S1().calcRefractiveIndexSnellmeier1(587.6);
	bool checkNSF6HT_S1 = Math::compareTwoNumbers_decimals(1.80518, resNSF6HT_S1, 4); 
	checkGlasses.push_back(checkNSF6HT_S1);
	//NSF6HTULTRA
	real resNSF6HTULTRA_S1 = glasses.getNSF6HTULTRA_S1().calcRefractiveIndexSnellmeier1(587.6);
	bool checkNSF6HTULTRA_S1 = Math::compareTwoNumbers_decimals(1.805180, resNSF6HTULTRA_S1, 4);
	checkGlasses.push_back(checkNSF6HTULTRA_S1);
	//NSF8
	real resNSF8_S1 = glasses.getNSF8_S1().calcRefractiveIndexSnellmeier1(587.6);
	bool checkNSF8_S1 = Math::compareTwoNumbers_decimals(1.688936, resNSF8_S1, 4);
	checkGlasses.push_back(checkNSF8_S1);
	//NSK11
	real resNSK11_S1 = glasses.getNSK11_S1().calcRefractiveIndexSnellmeier1(587.6);
	bool checkNSK11_S1 = Math::compareTwoNumbers_decimals(1.563840, resNSK11_S1, 4);
	checkGlasses.push_back(checkNSK11_S1);
	//NSK14
	real resNSK14_S1 = glasses.getNSK14_S1().calcRefractiveIndexSnellmeier1(587.6);
	bool checkNSK14_S1 = Math::compareTwoNumbers_decimals(1.603110, resNSK14_S1, 4);
	checkGlasses.push_back(checkNSK14_S1);
	//NSK16
	real resNSK16_S1 = glasses.getNSK16_S1().calcRefractiveIndexSnellmeier1(587.6);
	bool checkNSK16_S1 = Math::compareTwoNumbers_decimals(1.620410, resNSK16_S1, 4);
	checkGlasses.push_back(checkNSK16_S1);
	//NSK2
	real resNSK2_S1 = glasses.getNSK2_S1().calcRefractiveIndexSnellmeier1(587.6);
	bool checkNSK2_S1 = Math::compareTwoNumbers_decimals(1.607381, resNSK2_S1, 4);
	checkGlasses.push_back(checkNSK2_S1);
	//NSK2HT
	real resNSK2HT_S1 = glasses.getNSK2HT_S1().calcRefractiveIndexSnellmeier1(587.6);
	bool checkNSK2HT_S1 = Math::compareTwoNumbers_decimals(1.607381, resNSK2HT_S1, 4);
	checkGlasses.push_back(checkNSK2HT_S1);
	//NSK4
	real resNSK4_S1 = glasses.getNSK4_S1().calcRefractiveIndexSnellmeier1(587.6);
	bool checkNSK4_S1 = Math::compareTwoNumbers_decimals(1.612718, resNSK4_S1, 4);
	checkGlasses.push_back(checkNSK4_S1);
	//NSK5
	real resNSK5_S1 = glasses.getNSK5_S1().calcRefractiveIndexSnellmeier1(587.6);
	bool checkNSK5_S1 = Math::compareTwoNumbers_decimals(1.589130, resNSK5_S1, 4);
	checkGlasses.push_back(checkNSK5_S1);
	//NSSK2
	real resNSSK2_S1 = glasses.getNSSK2_S1().calcRefractiveIndexSnellmeier1(587.6);
	bool checkNSSK2_S1 = Math::compareTwoNumbers_decimals(1.622294, resNSSK2_S1, 4);
	checkGlasses.push_back(checkNSSK2_S1);
	//NSSK5
	real resNSSK5_S1 = glasses.getNSSK5_S1().calcRefractiveIndexSnellmeier1(587.6);
	bool checkNSSK5_S1 = Math::compareTwoNumbers_decimals(1.658440, resNSSK5_S1, 4);
	checkGlasses.push_back(checkNSSK5_S1);
	//NSSK8
	real resNSSK8_S1 = glasses.getNSSK8_S1().calcRefractiveIndexSnellmeier1(587.6);
	bool checkNSSK8_S1 = Math::compareTwoNumbers_decimals(1.617728, resNSSK8_S1, 4);
	checkGlasses.push_back(checkNSSK8_S1);
	//NZK7
	real resNZK7_S1 = glasses.getNZK7_S1().calcRefractiveIndexSnellmeier1(587.6);
	bool checkNZK7_S1 = Math::compareTwoNumbers_decimals(1.508469, resNZK7_S1, 4);
	checkGlasses.push_back(checkNZK7_S1);
	//PLAF37
	real resPLAF37_S1 = glasses.getPLAF37_S1().calcRefractiveIndexSnellmeier1(587.6);
	bool checkPLAF37_S1 = Math::compareTwoNumbers_decimals(1.755500, resPLAF37_S1, 4);
	checkGlasses.push_back(checkPLAF37_S1);
	//PLAK35
	real resPLAK35_S1 = glasses.getPLAK35_S1().calcRefractiveIndexSnellmeier1(587.6);
	bool checkPLAK35_S1 = Math::compareTwoNumbers_decimals(1.693500, resPLAK35_S1, 4);
	checkGlasses.push_back(checkPLAK35_S1);
	//PLASF47
	real resPLASF47_S1 = glasses.getPLASF47_S1().calcRefractiveIndexSnellmeier1(587.6);
	bool checkPLASF47_S1 = Math::compareTwoNumbers_decimals(1.806100, resPLASF47_S1, 4);
	checkGlasses.push_back(checkPLASF47_S1);
	//PLASF50
	real resPLASF50_S1 = glasses.getPLASF50_S1().calcRefractiveIndexSnellmeier1(587.6);
	bool checkPLASF50_S1 = Math::compareTwoNumbers_decimals(1.808600, resPLASF50_S1, 4);
	checkGlasses.push_back(checkPLASF50_S1);
	//
	real resPLASF51_S1 = glasses.getPLASF51_S1().calcRefractiveIndexSnellmeier1(587.6);
	bool checkPLASF51_S1 = Math::compareTwoNumbers_decimals(1.810000, resPLASF51_S1, 4);
	checkGlasses.push_back(checkPLASF51_S1);
	//PSF67
	real resPSF67_S1 = glasses.getPSF67_S1().calcRefractiveIndexSnellmeier1(587.6);
	bool checkPSF67_S1 = Math::compareTwoNumbers_decimals(1.906800, resPSF67_S1, 4);
	checkGlasses.push_back(checkPSF67_S1);
	//PSF68
	real resPSF68_S1 = glasses.getPSF68_S1().calcRefractiveIndexSnellmeier1(587.6);
	bool checkPSF68_S1 = Math::compareTwoNumbers_decimals(2.005200, resPSF68_S1, 4);
	checkGlasses.push_back(checkPSF68_S1);
	//PSF69
	real resPSF69_S1 = glasses.getPSF69_S1().calcRefractiveIndexSnellmeier1(587.6);
	bool checkPSF69_S1 = Math::compareTwoNumbers_decimals(1.72250, resPSF69_S1, 4);
	checkGlasses.push_back(checkPSF69_S1);
	//PSF8
	real resPSF8_S1 = glasses.getPSF8_S1().calcRefractiveIndexSnellmeier1(587.6);
	bool checkPSF8_S1 = Math::compareTwoNumbers_decimals(1.688930, resPSF8_S1, 4);
	checkGlasses.push_back(checkPSF8_S1);
	//PSK57
	real resPSK57_S1 = glasses.getPSK57_S1().calcRefractiveIndexSnellmeier1(587.6);
	bool checPSK57k_S1 = Math::compareTwoNumbers_decimals(1.587000, resPSK57_S1, 4);
	checkGlasses.push_back(checPSK57k_S1);
	//PSK58A
	real resPSK58A_S1 = glasses.getPSK58A_S1().calcRefractiveIndexSnellmeier1(587.6);
	bool checkPSK58A_S1 = Math::compareTwoNumbers_decimals(1.589130, resPSK58A_S1, 4);
	checkGlasses.push_back(checkPSK58A_S1);
	//PSK60
	real resPSK60_S1 = glasses.getPSK60_S1().calcRefractiveIndexSnellmeier1(587.6);
	bool checkPSK60_S1 = Math::compareTwoNumbers_decimals(1.610350, resPSK60_S1, 3);
	checkGlasses.push_back(checkPSK60_S1);
	//SF1
	real resSF1_S1 = glasses.getSF1_S1().calcRefractiveIndexSnellmeier1(587.6);
	bool checkSF1_S1 = Math::compareTwoNumbers_decimals(1.717360, resSF1_S1, 4);
	checkGlasses.push_back(checkSF1_S1);
	//SF10
	real resSF10_S1 = glasses.getSF10_S1().calcRefractiveIndexSnellmeier1(587.6);
	bool checkSF10_S1 = Math::compareTwoNumbers_decimals(1.728250, resSF10_S1, 5);
	checkGlasses.push_back(checkSF10_S1);
	//SF2
	real resSF2_S1 = glasses.getSF2_S1().calcRefractiveIndexSnellmeier1(587.6);
	bool checkSF2_S1 = Math::compareTwoNumbers_decimals(1.647689, resSF2_S1, 4);
	checkGlasses.push_back(checkSF2_S1);
	//SF4
	real resSF4_S1 = glasses.getSF4_S1().calcRefractiveIndexSnellmeier1(587.6);
	bool checkSF4_S1 = Math::compareTwoNumbers_decimals(1.755201, resSF4_S1, 4);
	checkGlasses.push_back(checkSF4_S1);
	//SF5
	real resSF5_S1 = glasses.getSF5_S1().calcRefractiveIndexSnellmeier1(587.6);
	bool checkSF5_S1 = Math::compareTwoNumbers_decimals(1.672697, resSF5_S1, 4);
	checkGlasses.push_back(checkSF5_S1);
	//SF56A
	real resSF56A_S1 = glasses.getSF56A_S1().calcRefractiveIndexSnellmeier1(587.6);
	bool checkSF56A_S1 = Math::compareTwoNumbers_decimals(1.784701, resSF56A_S1, 4);
	checkGlasses.push_back(checkSF56A_S1);
	//SF57
	real resSF57_S1 = glasses.getSF57_S1().calcRefractiveIndexSnellmeier1(587.6);
	bool checkSF57_S1 = Math::compareTwoNumbers_decimals(1.846663, resSF57_S1, 4);
	checkGlasses.push_back(checkSF57_S1);
	//SF6
	real resSF6_S1 = glasses.getSF6_S1().calcRefractiveIndexSnellmeier1(587.6);
	bool checkSF6_S1 = Math::compareTwoNumbers_decimals(1.805182, resSF6_S1, 4);
	checkGlasses.push_back(checkSF6_S1);
	//// NICHT VORHANDEN	 SF6HT
	//real resSF6HT_S1 = glasses.getSF6HT_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkSF6HT_S1 = Math::compareTwoNumbers_decimals(1.805182, resSF6HT_S1, 4);
	//checkGlasses.push_back(checkSF6HT_S1);
	//SF57HTULTRA
	real resSF57HTULTRA_S1 = glasses.getSF57HTULTRA_S1().calcRefractiveIndexSnellmeier1(587.6);
	bool checkSF57HTULTRA_S1 = Math::compareTwoNumbers_decimals(1.846663, resSF57HTULTRA_S1, 4);
	checkGlasses.push_back(checkSF57HTULTRA_S1);
	//PBK7
	real resPBK7_S1 = glasses.getPBK7_S1().calcRefractiveIndexSnellmeier1(587.6);
	bool checkPBK7_S1 = Math::compareTwoNumbers_decimals(1.516400, resPBK7_S1, 4);
	checkGlasses.push_back(checkPBK7_S1);
	//PSK57Q1
	real resPSK57Q1_S1 = glasses.getPSK57Q1_S1().calcRefractiveIndexSnellmeier1(587.6);
	bool checkPSK57Q1_S1 = Math::compareTwoNumbers_decimals(1.586000, resPSK57Q1_S1, 4);
	checkGlasses.push_back(checkPSK57Q1_S1);
	//SF11
	real resSF11_S1 = glasses.getSF11_S1().calcRefractiveIndexSnellmeier1(587.6);
	bool checkSF11_S1 = Math::compareTwoNumbers_decimals(1.784720, resSF11_S1, 4);
	checkGlasses.push_back(checkSF11_S1);
	//LASF35
	real resLASF35_S1 = glasses.getLASF35_S1().calcRefractiveIndexSnellmeier1(587.6);
	bool checkLASF35_S1 = Math::compareTwoNumbers_decimals(2.022040, resLASF35_S1, 4);
	checkGlasses.push_back(checkLASF35_S1);
	//FK3
	real resFK3_S1 = glasses.getFK3_S1().calcRefractiveIndexSnellmeier1(587.6);
	bool checkFK3_S1 = Math::compareTwoNumbers_decimals(1.464500, resFK3_S1, 4);
	checkGlasses.push_back(checkFK3_S1);
	//NSK10
	real resNSK10_S1 = glasses.getNSK10_S1().calcRefractiveIndexSnellmeier1(587.6);
	bool checkNSK10_S1 = Math::compareTwoNumbers_decimals(1.622780, resNSK10_S1, 4);
	checkGlasses.push_back(checkNSK10_S1);
	//NSK15
	real resNSK15_S1 = glasses.getNSK15_S1().calcRefractiveIndexSnellmeier1(587.6);
	bool checkNSK15_S1 = Math::compareTwoNumbers_decimals(1.622960, resNSK15_S1, 4);
	checkGlasses.push_back(checkNSK15_S1);
	//NBAF3
	real resNBAF3_S1 = glasses.getNBAF3_S1().calcRefractiveIndexSnellmeier1(587.6);
	bool checkNBAF3_S1 = Math::compareTwoNumbers_decimals(1.582723, resNBAF3_S1, 4);
	checkGlasses.push_back(checkNBAF3_S1);
	//BAFN6
	real resBAFN6_S1 = glasses.getBAFN6_S1().calcRefractiveIndexSnellmeier1(587.6);
	bool checkBAFN6_S1 = Math::compareTwoNumbers_decimals(1.588999, resBAFN6_S1, 4);
	checkGlasses.push_back(checkBAFN6_S1);
	//NLAF3
	real resNLAF3_S1 = glasses.getNLAF3_S1().calcRefractiveIndexSnellmeier1(587.6);
	bool checkNLAF3_S1 = Math::compareTwoNumbers_decimals(1.716998, resNLAF3_S1, 4);
	checkGlasses.push_back(checkNLAF3_S1);
	//SFL57
	real resSFL57_S1 = glasses.getSFL57_S1().calcRefractiveIndexSnellmeier1(587.6);
	bool checkSFL57_S1 = Math::compareTwoNumbers_decimals(1.84663, resSFL57_S1, 3);
	checkGlasses.push_back(checkSFL57_S1);
	//SFL6
	real resSFL6_S1 = glasses.getSFL6_S1().calcRefractiveIndexSnellmeier1(587.6);
	bool checkSFL6_S1 = Math::compareTwoNumbers_decimals(1.805182, resSFL6_S1, 4);
	checkGlasses.push_back(checkSFL6_S1);
	//NSF19
	real resNSF19_S1 = glasses.getNSF19_S1().calcRefractiveIndexSnellmeier1(587.6);
	bool checkNSF19_S1 = Math::compareTwoNumbers_decimals(1.666789, resNSF19_S1, 4);
	checkGlasses.push_back(checkNSF19_S1);
	//NSF56
	real resNSF56_S1 = glasses.getNSF56_S1().calcRefractiveIndexSnellmeier1(587.6);
	bool checkNSF56_S1 = Math::compareTwoNumbers_decimals(1.784703, resNSF56_S1, 4);
	checkGlasses.push_back(checkNSF56_S1);
	//NSF64
	real resNSF64_S1 = glasses.getNSF64_S1().calcRefractiveIndexSnellmeier1(587.6);
	bool checkNSF64_S1 = Math::compareTwoNumbers_decimals(1.705908, resNSF64_S1, 4);
	checkGlasses.push_back(checkNSF64_S1);
	//NPSK53
	real resNPSK53_S1 = glasses.getNPSK53_S1().calcRefractiveIndexSnellmeier1(587.6);
	bool checkNPSK53_S1 = Math::compareTwoNumbers_decimals(1.620141, resNPSK53_S1, 4);
	checkGlasses.push_back(checkNPSK53_S1);
	//BK7G18
	real resBK7G18_S1 = glasses.getBK7G18_S1().calcRefractiveIndexSnellmeier1(587.6);
	bool checkBK7G18_S1 = Math::compareTwoNumbers_decimals(1.519750, resBK7G18_S1, 5);
	checkGlasses.push_back(checkBK7G18_S1);
	//LF5G19
	real resLF5G19_S1 = glasses.getLF5G19_S1().calcRefractiveIndexSnellmeier1(587.6);
	bool checkLF5G19_S1 = Math::compareTwoNumbers_decimals(1.596550, resLF5G19_S1, 5);
	checkGlasses.push_back(checkLF5G19_S1);
	//LF5G15
	real resLF5G15_S1 = glasses.getLF5G15_S1().calcRefractiveIndexSnellmeier1(587.6);
	bool checkLF5G15_S1 = Math::compareTwoNumbers_decimals(1.583970, resLF5G15_S1, 4);
	checkGlasses.push_back(checkLF5G15_S1);
	//K5G20
	real resK5G20_S1 = glasses.getK5G20_S1().calcRefractiveIndexSnellmeier1(587.6);
	bool checkK5G20_S1 = Math::compareTwoNumbers_decimals(1.523439, resK5G20_S1, 4);
	checkGlasses.push_back(checkK5G20_S1);
	//LAK9G15
	real resLAK9G15_S1 = glasses.getLAK9G15_S1().calcRefractiveIndexSnellmeier1(587.6);
	bool checkLAK9G15_S1 = Math::compareTwoNumbers_decimals(1.690635, resLAK9G15_S1, 4);
	checkGlasses.push_back(checkLAK9G15_S1);
	//F2G12
	real resF2G12_S1 = glasses.getF2G12_S1().calcRefractiveIndexSnellmeier1(587.6);
	bool checkF2G12_S1 = Math::compareTwoNumbers_decimals(1.620721, resF2G12_S1, 4);
	checkGlasses.push_back(checkF2G12_S1);
	//SF6G05
	real resSF6G05_S1 = glasses.getSF6G05_S1().calcRefractiveIndexSnellmeier1(587.6);
	bool checkSF6G05_S1 = Math::compareTwoNumbers_decimals(1.809057, resSF6G05_S1, 4);
	checkGlasses.push_back(checkSF6G05_S1);
	//LASFN9
	real resLASFN9_S1 = glasses.getLASFN9_S1().calcRefractiveIndexSnellmeier1(587.6);
	bool checkLASFN9_S1 = Math::compareTwoNumbers_decimals(1.850255, resLASFN9_S1, 3);
	checkGlasses.push_back(checkLASFN9_S1);
	//LAKL12
	real resLAKL12_S1 = glasses.getLAKL12_S1().calcRefractiveIndexSnellmeier1(587.6);
	bool checkLAKL12_S1 = Math::compareTwoNumbers_decimals(1.677900, resLAKL12_S1, 4);
	checkGlasses.push_back(checkLAKL12_S1);
	//NLASF46
	real resNLASF46_S1 = glasses.getNLASF46_S1().calcRefractiveIndexSnellmeier1(587.6);
	bool checkNLASF46_S1 = Math::compareTwoNumbers_decimals(1.901376, resNLASF46_S1, 4);
	checkGlasses.push_back(checkNLASF46_S1);
	//NLASF31
	real resNLASF31_S1 = glasses.getNLASF31_S1().calcRefractiveIndexSnellmeier1(587.6);
	bool checkNLASF31_S1 = Math::compareTwoNumbers_decimals(1.880669, resNLASF31_S1, 4);
	checkGlasses.push_back(checkNLASF31_S1);
	//NFK51
	real resNFK51_S1 = glasses.getNFK51_S1().calcRefractiveIndexSnellmeier1(587.6);
	bool checkNFK51_S1 = Math::compareTwoNumbers_decimals(1.486561, resNFK51_S1, 4);
	checkGlasses.push_back(checkNFK51_S1);
	//NLAF32
	real resNLAF32_S1 = glasses.getNLAF32_S1().calcRefractiveIndexSnellmeier1(587.6);
	bool checkNLAF32_S1 = Math::compareTwoNumbers_decimals(1.794569, resNLAF32_S1, 4);
	checkGlasses.push_back(checkNLAF32_S1);
	//KZFSN4
	real resKZFSN4_S1 = glasses.getKZFSN4_S1().calcRefractiveIndexSnellmeier1(587.6);
	bool checkKZFSN4_S1 = Math::compareTwoNumbers_decimals(1.613401, resKZFSN4_S1, 4);
	checkGlasses.push_back(checkKZFSN4_S1);
	//SF14
	real resSF14_S1 = glasses.getSF14_S1().calcRefractiveIndexSnellmeier1(587.6);
	bool checkSF14_S1 = Math::compareTwoNumbers_decimals(1.761820, resSF14_S1, 4);
	checkGlasses.push_back(checkSF14_S1);
	//SF15
	real resSF15_S1 = glasses.getSF15_S1().calcRefractiveIndexSnellmeier1(587.6);
	bool checkSF15_S1 = Math::compareTwoNumbers_decimals(1.69892, resSF15_S1, 4);
	checkGlasses.push_back(checkSF15_S1);
	//SF66
	real resSF66_S1 = glasses.getSF66_S1().calcRefractiveIndexSnellmeier1(587.6);
	bool checkSF66_S1 = Math::compareTwoNumbers_decimals(1.92286, resSF66_S1, 4);
	checkGlasses.push_back(checkSF66_S1);
	//LITHOTECCAF2
	real resLITHOTECCAF2_S1 = glasses.getLITHOTECCAF2_S1().calcRefractiveIndexSnellmeier1(587.6);
	bool checkLITHOTECCAF2_S1 = Math::compareTwoNumbers_decimals(1.433848, resLITHOTECCAF2_S1, 4);
	checkGlasses.push_back(checkLITHOTECCAF2_S1);
	//LITHOSILQ
	real resLITHOSILQ_S1 = glasses.getLITHOSILQ_S1().calcRefractiveIndexSnellmeier1(587.6);
	bool checkLITHOSILQ_S1 = Math::compareTwoNumbers_decimals(1.458438, resLITHOSILQ_S1, 4);
	checkGlasses.push_back(checkLITHOSILQ_S1);
	//// NICHT VORHANDEN	 D263TECO
	//real resD263TECO_S1 = glasses.getD263TECO_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkD263TECO_S1 = Math::compareTwoNumbers_decimals(1.523303, resD263TECO_S1, 4);
	//checkGlasses.push_back(checkD263TECO_S1);
	//// NICHT VORHANDEN AF32ECO
	//real resAF32ECO_S1 = glasses.getAF32ECO_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkAF32ECO_S1 = Math::compareTwoNumbers_decimals(1.511531, resAF32ECO_S1, 4);
	//checkGlasses.push_back(checkAF32ECO_S1);
	//KZFS12
	real resKZFS12_S1 = glasses.getKZFS12_S1().calcRefractiveIndexSnellmeier1(587.6);
	bool checkKZFS12_S1 = Math::compareTwoNumbers_decimals(1.696000, resKZFS12_S1, 4);
	checkGlasses.push_back(checkKZFS12_S1);
	//PPK53
	real resPPK53_S1 = glasses.getPPK53_S1().calcRefractiveIndexSnellmeier1(587.6);
	bool checkPPK53_S1 = Math::compareTwoNumbers_decimals(1.526900, resPPK53_S1, 4);
	checkGlasses.push_back(checkPPK53_S1);
	//NLAF36
	real resNLAF36_S1 = glasses.getNLAF36_S1().calcRefractiveIndexSnellmeier1(587.6);
	bool checkNLAF36_S1 = Math::compareTwoNumbers_decimals(1.799518, resNLAF36_S1, 4);
	checkGlasses.push_back(checkNLAF36_S1);
	//FK5HTI
	real resFK5HTI_S1 = glasses.getFK5HTI_S1().calcRefractiveIndexSnellmeier1(587.6);
	bool checkFK5HTI_S1 = Math::compareTwoNumbers_decimals(1.487480, resFK5HTI_S1, 4);
	checkGlasses.push_back(checkFK5HTI_S1);
	//LF5HTI
	real resLF5HTI_S1 = glasses.getLF5HTI_S1().calcRefractiveIndexSnellmeier1(587.6);
	bool checkLF5HTI_S1 = Math::compareTwoNumbers_decimals(1.581443, resLF5HTI_S1, 4);
	checkGlasses.push_back(checkLF5HTI_S1);
	//LLF1HTI
	real resLLF1HTI_S1 = glasses.getLLF1HTI_S1().calcRefractiveIndexSnellmeier1(587.6);
	bool checkLLF1HTI_S1 = Math::compareTwoNumbers_decimals(1.54815, resLLF1HTI_S1, 5);
	checkGlasses.push_back(checkLLF1HTI_S1);
	//NBK7HTI
	real resNBK7HTI_S1 = glasses.getNBK7HTI_S1().calcRefractiveIndexSnellmeier1(587.6);
	bool checkNBK7HTI_S1 = Math::compareTwoNumbers_decimals(1.516800, resNBK7HTI_S1, 4);
	checkGlasses.push_back(checkNBK7HTI_S1);
	//NFK58
	real resNFK58_S1 = glasses.getNFK58_S1().calcRefractiveIndexSnellmeier1(587.6);
	bool checkNFK58_S1 = Math::compareTwoNumbers_decimals(1.456000, resNFK58_S1, 4);
	checkGlasses.push_back(checkNFK58_S1);
	//BAFN10
	real resBAFN10_S1 = glasses.getBAFN10_S1().calcRefractiveIndexSnellmeier1(587.6);
	bool checkBAFN10_S1 = Math::compareTwoNumbers_decimals(1.670031, resBAFN10_S1, 4);
	checkGlasses.push_back(checkBAFN10_S1);
				
	bool checkRefIndexGlasses = Math::checkTrueOfVectorElements(checkGlasses);
	return checkRefIndexGlasses;
}