#pragma once
#include"BenchGlasses.h"
#include<vector>
//#include"..\..\basicdefinitions.h"
#include "..\..\Glasses\Glasses.h"
#include "..\..\LowLevelTracing\Math_LLT.h"

bool BenchmarkGlasses::checkGlasses()
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
	//// NICHT VORHANDEn BAF3
	//real resBAF3_S1 = glasses.getBAF3_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkBAF3_S1 = Math::compareTwoNumbers_decimals(1.582670, resBAF3_S1, 4);
	//checkGlasses.push_back(checkBAF3_S1);
	//// NICHT VORHANDEN BAF4
	//real resBAF4_S1 = glasses.getBAF4_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkBAF4_S1 = Math::compareTwoNumbers_decimals(1.605621, resBAF4_S1, 4);
	//checkGlasses.push_back(checkBAF4_S1);
	//// NICHT VORHANDEN BAF8
	//real resBAF8_S1 = glasses.getBAF8_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkBAF8_S1 = Math::compareTwoNumbers_decimals(1.623740, resBAF8_S1, 4);
	//checkGlasses.push_back(checkBAF8_S1);
	//// NICHT VORHANDEN BAF9
	//real resBAF9_S1 = glasses.getBAF9_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkBAF9_S1 = Math::compareTwoNumbers_decimals(1.643276, resBAF9_S1, 4);
	//checkGlasses.push_back(checkBAF9_S1);
	//// NICHT VORHANDEN BAF13
	//real resBAF13_S1 = glasses.getBAF13_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkBAF13_S1 = Math::compareTwoNumbers_decimals(1.668919, resBAF13_S1, 4);
	//checkGlasses.push_back(checkBAF13_S1);
	//// NICHT VORHANDEN BAF50
	//real resBAF50_S1 = glasses.getBAF50_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkBAF50_S1 = Math::compareTwoNumbers_decimals(1.682726, resBAF50_S1, 4);
	//checkGlasses.push_back(checkBAF50_S1);
	//// NICHT VORHANDEN BAF51
	//real resBAF51_S1 = glasses.getBAF51_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkBAF51_S1 = Math::compareTwoNumbers_decimals(1.652242, resBAF51_S1, 4);
	//checkGlasses.push_back(checkBAF51_S1);
	//// NICHT VORHANDEN BAF52
	//real resBAF52_S1 = glasses.getBAF52_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkBAF52_S1 = Math::compareTwoNumbers_decimals(1.608589, resBAF52_S1, 4);
	//checkGlasses.push_back(checkBAF52_S1);
	//BAFN10
	real resBAFN10_S1 = glasses.getBAFN10_S1().calcRefractiveIndexSnellmeier1(587.6);
	bool checkBAFN10_S1 = Math::compareTwoNumbers_decimals(1.670031, resBAFN10_S1, 4);
	checkGlasses.push_back(checkBAFN10_S1);
	////BAFN11
	//real resBAFN11_S1 = glasses.getBAFN11_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkBAFN11_S1 = Math::compareTwoNumbers_decimals(1.666721, resBAFN11_S1, 4);
	//checkGlasses.push_back(checkBAFN11_S1);
	////BAK1
	//real resBAK1_S1 = glasses.getBAK1_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkBAK1_S1 = Math::compareTwoNumbers_decimals(1.572500, resBAK1_S1, 4);
	//checkGlasses.push_back(checkBAK1_S1);
	////BAK2
	//real resBAK2_S1 = glasses.getBAK2_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkBAK2_S1 = Math::compareTwoNumbers_decimals(1.539960, resBAK2_S1, 4);
	//checkGlasses.push_back(checkBAK2_S1);
	////BAK4
	//real resBAK4_S1 = glasses.getBAK4_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkBAK4_S1 = Math::compareTwoNumbers_decimals(1.568830, resBAK4_S1, 4);
	//checkGlasses.push_back(checkBAK4_S1);
	////BAK5
	//real resBAK5_S1 = glasses.getBAK5_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkBAK5_S1 = Math::compareTwoNumbers_decimals(1.556709, resBAK5_S1, 4);
	//checkGlasses.push_back(checkBAK5_S1);
	////BAK50
	//real resBAK50_S1 = glasses.getBAK50_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkBAK50_S1 = Math::compareTwoNumbers_decimals(1.567736, resBAK50_S1, 4);
	//checkGlasses.push_back(checkBAK50_S1);
	////BALF4
	//real resBALF4_S1 = glasses.getBALF4_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkBALF4_S1 = Math::compareTwoNumbers_decimals(1.579569, resBALF4_S1, 4);
	//checkGlasses.push_back(checkBALF4_S1);
	////BALF5
	//real resBALF5_S1 = glasses.getBALF5_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkBALF5_S1 = Math::compareTwoNumbers_decimals(1.547391, resBALF5_S1, 4);
	//checkGlasses.push_back(checkBALF5_S1);
	////BALF50
	//real resBALF50_S1 = glasses.getBALF50_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkBALF50_S1 = Math::compareTwoNumbers_decimals(1.588931, resBALF50_S1, 4);
	//checkGlasses.push_back(checkBALF50_S1);
	////BALKN3
	//real resBALKN3_S1 = glasses.getBALKN3_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkBALKN3_S1 = Math::compareTwoNumbers_decimals(1.518489, resBALKN3_S1, 4);
	//checkGlasses.push_back(checkBALKN3_S1);
	////BASF1
	//real resBASF1_S1 = glasses.getBASF1_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkBASF1_S1 = Math::compareTwoNumbers_decimals(1.626061, resBASF1_S1, 4);
	//checkGlasses.push_back(checkBASF1_S1);
	////BASF2
	//real resBASF2_S1 = glasses.getBASF2_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkBASF2_S1 = Math::compareTwoNumbers_decimals(1.664460, resBASF2_S1, 4);
	//checkGlasses.push_back(checkBASF2_S1);
	////BASF6
	//real resBASF6_S1 = glasses.getBASF6_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkBASF6_S1 = Math::compareTwoNumbers_decimals(1.667551, resBASF6_S1, 5);
	//checkGlasses.push_back(checkBASF6_S1);
	////BASF10
	//real resBASF10_S1 = glasses.getBASF10_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkBASF10_S1 = Math::compareTwoNumbers_decimals(1.650160, resBASF10_S1, 4);
	//checkGlasses.push_back(checkBASF10_S1);
	////BASF12
	//real resBASF12_S1 = glasses.getBASF12_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkBASF12_S1 = Math::compareTwoNumbers_decimals(1.669979, resBASF12_S1, 4);
	//checkGlasses.push_back(checkBASF12_S1);
	////BASF13
	//real resBASF13_S1 = glasses.getBASF13_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkBASF13_S1 = Math::compareTwoNumbers_decimals(1.697610, resBASF13_S1, 4);
	//checkGlasses.push_back(checkBASF13_S1);
	////BASF51
	//real resBASF51_S1 = glasses.getBASF51_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkBASF51_S1 = Math::compareTwoNumbers_decimals(1.723728, resBASF51_S1, 4);
	//checkGlasses.push_back(checkBASF51_S1);
	////BASF52
	//real resBASF52_S1 = glasses.getBASF52_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkBASF52_S1 = Math::compareTwoNumbers_decimals(1.701810, resBASF52_S1, 4);
	//checkGlasses.push_back(checkBASF52_S1);
	////BASF54
	//real resBASF54_S1 = glasses.getBASF54_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkBASF54_S1 = Math::compareTwoNumbers_decimals(1.736270, resBASF54_S1, 4);
	//checkGlasses.push_back(checkBASF54_S1);
	////BASF56
	//real resBASF56_S1 = glasses.getBASF56_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkBASF56_S1 = Math::compareTwoNumbers_decimals(1.657149, resBASF56_S1, 4);
	//checkGlasses.push_back(checkBASF56_S1);
	////BASF57
	//real resBASF57_S1 = glasses.getBASF57_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkBASF57_S1 = Math::compareTwoNumbers_decimals(1.651474, resBASF57_S1, 4);
	//checkGlasses.push_back(checkBASF57_S1);
	////BASF64A
	//real resBASF64A_S1 = glasses.getBASF64A_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkBASF64A_S1 = Math::compareTwoNumbers_decimals(1.704000, resBASF64A_S1, 4);
	//checkGlasses.push_back(checkBASF64A_S1);
	////BK1
	//real resBK1_S1 = glasses.getBK1_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkBK1_S1 = Math::compareTwoNumbers_decimals(1.510091, resBK1_S1, 4);
	//checkGlasses.push_back(checkBK1_S1);
	////BK3
	//real resBK3_S1 = glasses.getBK3_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkBK3_S1 = Math::compareTwoNumbers_decimals(1.498311, resBK3_S1, 4);
	//checkGlasses.push_back(checkBK3_S1);
	////BK6
	//real resBK6_S1 = glasses.getBK6_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkBK6_S1 = Math::compareTwoNumbers_decimals(1.531129, resBK6_S1, 4);
	//checkGlasses.push_back(checkBK6_S1);
	////BK7
	//real resBK7_S1 = glasses.getBK7_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkBK7_S1 = Math::compareTwoNumbers_decimals(1.516800, resBK7_S1, 4);
	//checkGlasses.push_back(checkBK7_S1);
	////BK7HT
	//real resBK7HT_S1 = glasses.getBK7HT_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkBK7HT_S1 = Math::compareTwoNumbers_decimals(1.516330, resBK7HT_S1, 4);
	//checkGlasses.push_back(checkBK7HT_S1);
	////BK8
	//real resBK8_S1 = glasses.getBK8_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkBK8_S1 = Math::compareTwoNumbers_decimals(1.520152, resBK8_S1, 4);
	//checkGlasses.push_back(checkBK8_S1);
	////BK10
	//real resBK10_S1 = glasses.getBK10_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkBK10_S1 = Math::compareTwoNumbers_decimals(1.497821, resBK10_S1, 4);
	//checkGlasses.push_back(checkBK10_S1);
	////F1
	//real resF1_S1 = glasses.getF1_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkF1_S1 = Math::compareTwoNumbers_decimals(1.625882, resF1_S1, 5);
	//checkGlasses.push_back(checkF1_S1);
	////F3
	//real resF3_S1 = glasses.getF3_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkF3_S1 = Math::compareTwoNumbers_decimals(1.612931, resF3_S1, 4);
	//checkGlasses.push_back(checkF3_S1);
	////F4
	//real resF4_S1 = glasses.getF4_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkF4_S1 = Math::compareTwoNumbers_decimals(1.616592, resF4_S1, 4);
	//checkGlasses.push_back(checkF4_S1);
	////F6
	//real resF6_S1 = glasses.getF6_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkF6_S1 = Math::compareTwoNumbers_decimals(1.636359, resF6_S1, 4);
	//checkGlasses.push_back(checkF6_S1);
	////F7
	//real resF7_S1 = glasses.getF7_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkF7_S1 = Math::compareTwoNumbers_decimals(1.625361, resF7_S1, 4);
	//checkGlasses.push_back(checkF7_S1);
	////F8
	//real resF8_S1 = glasses.getF8_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkF8_S1 = Math::compareTwoNumbers_decimals(1.595510, resF8_S1, 4);
	//checkGlasses.push_back(checkF8_S1);
	////F8HT
	//real resF8HT_S1 = glasses.getF8HT_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkF8HT_S1 = Math::compareTwoNumbers_decimals(1.595510, resF8HT_S1, 4);
	//checkGlasses.push_back(checkF8HT_S1);
	////F9
	//real resF9_S1 = glasses.getF9_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkF9_S1 = Math::compareTwoNumbers_decimals(1.620451, resF9_S1, 5);
	//checkGlasses.push_back(checkF9_S1);
	////F13
	//real resF13_S1 = glasses.getF13_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkF13_S1 = Math::compareTwoNumbers_decimals(1.622372, resF13_S1, 4);
	//checkGlasses.push_back(checkF13_S1);
	////F14
	//real resF14_S1 = glasses.getF14_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkF14_S1 = Math::compareTwoNumbers_decimals(1.601401, resF14_S1, 4);
	//checkGlasses.push_back(checkF14_S1);
	////F14HT
	//real resF14HT_S1 = glasses.getF14HT_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkF14HT_S1 = Math::compareTwoNumbers_decimals(1.601389, resF14HT_S1, 4);
	//checkGlasses.push_back(checkF14HT_S1);
	////F15
	//real resF15_S1 = glasses.getF15_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkF15_S1 = Math::compareTwoNumbers_decimals(1.605651, resF15_S1, 5);
	//checkGlasses.push_back(checkF15_S1);
	////FK5
	//real resFK5_S1 = glasses.getFK5_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkFK5_S1 = Math::compareTwoNumbers_decimals(1.487490, resFK5_S1, 4);
	//checkGlasses.push_back(checkFK5_S1);
	////FK51
	//real resFK51_S1 = glasses.getFK51_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkFK51_S1 = Math::compareTwoNumbers_decimals(1.486561, resFK51_S1, 4);
	//checkGlasses.push_back(checkFK51_S1);
	////FK52
	//real resFK52_S1 = glasses.getFK52_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkFK52_S1 = Math::compareTwoNumbers_decimals(1.486052, resFK52_S1, 4);
	//checkGlasses.push_back(checkFK52_S1);
	////FK54
	//real resFK54_S1 = glasses.getFK54_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkFK54_S1 = Math::compareTwoNumbers_decimals(1.437000, resFK54_S1, 4);
	//checkGlasses.push_back(checkFK54_S1);
	////FN11
	//real resFN11_S1 = glasses.getFN11_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkFN11_S1 = Math::compareTwoNumbers_decimals(1.620962, resFN11_S1, 4);
	//checkGlasses.push_back(checkFN11_S1);
	////K3
	//real resK3_S1 = glasses.getK3_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkK3_S1 = Math::compareTwoNumbers_decimals(1.518230, resK3_S1, 4);
	//checkGlasses.push_back(checkK3_S1);
	////K4
	//real resK4_S1 = glasses.getK4_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkK4_S1 = Math::compareTwoNumbers_decimals(1.518952, resK4_S1, 4);
	//checkGlasses.push_back(checkK4_S1);
	////K5
	//real resK5_S1 = glasses.getK5_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkK5_S1 = Math::compareTwoNumbers_decimals(1.522489, resK5_S1, 4);
	//checkGlasses.push_back(checkK5_S1);
	////K5HT
	//real resK5HT_S1 = glasses.getK5HT_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkK5HT_S1 = Math::compareTwoNumbers_decimals(1.522453, resK5HT_S1, 4);
	//checkGlasses.push_back(checkK5HT_S1);
	////K7HT
	//real resK7HT_S1 = glasses.getK7HT_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkK7HT_S1 = Math::compareTwoNumbers_decimals(1.511144, resK7HT_S1, 4);
	//checkGlasses.push_back(checkK7HT_S1);
	////K11
	//real resK11_S1 = glasses.getK11_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkK11_S1 = Math::compareTwoNumbers_decimals(1.500130, resK11_S1, 4);
	//checkGlasses.push_back(resK11_S1);
	////K50
	//real resK50_S1 = glasses.getK50_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkK50_S1 = Math::compareTwoNumbers_decimals(1.522572, resK50_S1, 4);
	//checkGlasses.push_back(checkK50_S1);
	////KF3
	//real resKF3_S1 = glasses.getKF3_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkKF3_S1 = Math::compareTwoNumbers_decimals(1.514540, resKF3_S1, 4);
	//checkGlasses.push_back(checkKF3_S1);
	////KF6
	//real resKF6_S1 = glasses.getKF6_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkKF6_S1 = Math::compareTwoNumbers_decimals(1.517421, resKF6_S1, 4);
	//checkGlasses.push_back(checkKF6_S1);
	////KF9
	//real resKF9_S1 = glasses.getKF9_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkKF9_S1 = Math::compareTwoNumbers_decimals(1.523412, resKF9_S1, 4);
	//checkGlasses.push_back(checkKF9_S1);
	////KZFN1
	//real resKZFN1_S1 = glasses.getKZFN1_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkKZFN1_S1 = Math::compareTwoNumbers_decimals(1.551149, resKZFN1_S1, 4);
	//checkGlasses.push_back(checkKZFN1_S1);
	////KZFN2
	//real resKZFN2_S1 = glasses.getKZFN2_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkKZFN2_S1 = Math::compareTwoNumbers_decimals(1.529440, resKZFN2_S1, 4);
	//checkGlasses.push_back(checkKZFN2_S1);
	////KZFS1
	//real resKZFS1_S1 = glasses.getKZFS1_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkKZFS1_S1 = Math::compareTwoNumbers_decimals(1.613099, resKZFS1_S1, 4);
	//checkGlasses.push_back(checkKZFS1_S1);
	////KZFS6
	//real resKZFS6_S1 = glasses.getKZFS6_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkKZFS6_S1 = Math::compareTwoNumbers_decimals(1.591965, resKZFS6_S1, 4);
	//checkGlasses.push_back(checkKZFS6_S1);
	////KZFS7A
	//real resKZFS7A_S1 = glasses.getKZFS7A_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkKZFS7A_S1 = Math::compareTwoNumbers_decimals(1.680640, resKZFS7A_S1, 4);
	//checkGlasses.push_back(checkKZFS7A_S1);
	////KZFS8
	//real resKZFS8_S1 = glasses.getKZFS8_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkKZFS8_S1 = Math::compareTwoNumbers_decimals(1.720470, resKZFS8_S1, 4);
	//checkGlasses.push_back(checkKZFS8_S1);
	////KZFSN2
	//real resKZFSN2_S1 = glasses.getKZFSN2_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkKZFSN2_S1 = Math::compareTwoNumbers_decimals(1.558361, resKZFSN2_S1, 4);
	//checkGlasses.push_back(checkKZFSN2_S1);
	////KZFSN9
	//real resKZFSN9_S1 = glasses.getKZFSN9_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkKZFSN9_S1 = Math::compareTwoNumbers_decimals(1.598557, resKZFSN9_S1, 4);
	//checkGlasses.push_back(checkKZFSN9_S1);
	////LAF2
	//real resLAF2_S1 = glasses.getLAF2_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkLAF2_S1 = Math::compareTwoNumbers_decimals(1.744002, resLAF2_S1, 4);
	//checkGlasses.push_back(checkLAF2_S1);
	////LAF3
	//real resLAF3_S1 = glasses.getLAF3_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkLAF3_S1 = Math::compareTwoNumbers_decimals(1.716998, resLAF3_S1, 4);
	//checkGlasses.push_back(checkLAF3_S1);
	////LAF9
	//real resLAF9_S1 = glasses.getLAF9_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkLAF9_S1 = Math::compareTwoNumbers_decimals(1.795040, resLAF9_S1, 4);
	//checkGlasses.push_back(checkLAF9_S1);
	////LAF11A
	//real resLAF11A_S1 = glasses.getLAF11A_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkLAF11A_S1 = Math::compareTwoNumbers_decimals(1.756927, resLAF11A_S1, 4);
	//checkGlasses.push_back(checkLAF11A_S1);
	////LAF13
	//real resLAF13_S1 = glasses.getLAF13_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkLAF13_S1 = Math::compareTwoNumbers_decimals(1.775507, resLAF13_S1, 4);
	//checkGlasses.push_back(checkLAF13_S1);
	////LAF20
	//real resLAF20_S1 = glasses.getLAF20_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkLAF20_S1 = Math::compareTwoNumbers_decimals(1.682476, resLAF20_S1, 4);
	//checkGlasses.push_back(checkLAF20_S1);
	////LAF22A
	//real resLAF22A_S1 = glasses.getLAF22A_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkLAF22A_S1 = Math::compareTwoNumbers_decimals(1.781791, resLAF22A_S1, 4);
	//checkGlasses.push_back(checkLAF22A_S1);
	////LAFN8
	//real resLAFN8_S1 = glasses.getLAFN8_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkLAFN8_S1 = Math::compareTwoNumbers_decimals(1.735197, resLAFN8_S1, 4);
	//checkGlasses.push_back(checkLAFN8_S1);
	////LAFN10
	//real resLAFN10_S1 = glasses.getLAFN10_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkLAFN10_S1 = Math::compareTwoNumbers_decimals(1.784432, resLAFN10_S1, 4);
	//checkGlasses.push_back(checkLAFN10_S1);
	////LAFN21
	//real resLAFN21_S1 = glasses.getLAFN21_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkLAFN21_S1 = Math::compareTwoNumbers_decimals(1.788309, resLAFN21_S1, 4);
	//checkGlasses.push_back(checkLAFN21_S1);
	////LAFN23
	//real resLAFN23_S1 = glasses.getLAFN23_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkLAFN23_S1 = Math::compareTwoNumbers_decimals(1.689004, resLAFN23_S1, 4);
	//checkGlasses.push_back(checkLAFN23_S1);
	////LAFN24
	//real resLAFN24_S1 = glasses.getLAFN24_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkLAFN24_S1 = Math::compareTwoNumbers_decimals(1.757191, resLAFN24_S1, 4);
	//checkGlasses.push_back(checkLAFN24_S1);
	////LAFN28
	//real resLAFN28_S1 = glasses.getLAFN28_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkLAFN28_S1 = Math::compareTwoNumbers_decimals(1.773142, resLAFN28_S1, 4);
	//checkGlasses.push_back(checkLAFN28_S1);
	////LAK8
	//real resLAK8_S1 = glasses.getLAK8_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkLAK8_S1 = Math::compareTwoNumbers_decimals(1.713003, resLAK8_S1, 4);
	//checkGlasses.push_back(checkLAK8_S1);
	////LAK9
	//real resLAK9_S1 = glasses.getLAK9_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkLAK9_S1 = Math::compareTwoNumbers_decimals(1.691002, resLAK9_S1, 4);
	//checkGlasses.push_back(checkLAK9_S1);
	////LAK10
	//real resLAK10_S1 = glasses.getLAK10_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkLAK10_S1 = Math::compareTwoNumbers_decimals(1.720000, resLAK10_S1, 4);
	//checkGlasses.push_back(checkLAK10_S1);
	////LAK11
	//real resLAK11_S1 = glasses.getLAK11_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkLAK11_S1 = Math::compareTwoNumbers_decimals(1.658302, resLAK11_S1, 4);
	//checkGlasses.push_back(checkLAK11_S1);
	////LAK16A
	//real resLAK16A_S1 = glasses.getLAK16A_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkLAK16A_S1 = Math::compareTwoNumbers_decimals(1.733501, resLAK16A_S1, 4);
	//checkGlasses.push_back(checkLAK16A_S1);
	////LAK21
	//real resLAK21_S1 = glasses.getLAK21_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkLAK21_S1 = Math::compareTwoNumbers_decimals(1.640495, resLAK21_S1, 4);
	//checkGlasses.push_back(checkLAK21_S1);
	////LAK23
	//real resLAK23_S1 = glasses.getLAK23_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkLAK23_S1 = Math::compareTwoNumbers_decimals(1.668816, resLAK23_S1, 4);
	//checkGlasses.push_back(checkLAK23_S1);
	////LAK28
	//real resLAK28_S1 = glasses.getLAK28_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkLAK28_S1 = Math::compareTwoNumbers_decimals(1.744287, resLAK28_S1, 4);
	//checkGlasses.push_back(checkLAK28_S1);
	////LAK31
	//real resLAK31_S1 = glasses.getLAK31_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkLAK31_S1 = Math::compareTwoNumbers_decimals(1.696732, resLAK31_S1, 4);
	//checkGlasses.push_back(checkLAK31_S1);
	////LAK33
	//real resLAK33_S1 = glasses.getLAK33_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkLAK33_S1 = Math::compareTwoNumbers_decimals(1.753977, resLAK33_S1, 4);
	//checkGlasses.push_back(checkLAK33_S1);
	////LAKL21
	//real resLAKL21_S1 = glasses.getLAKL21_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool check_S1 = Math::compareTwoNumbers_decimals(1.640480, resLAKL21_S1, 4);
	//checkGlasses.push_back(check_S1);
	////LAKN6
	//real resLAKN6_S1 = glasses.getLAKN6_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkLAKN6_S1 = Math::compareTwoNumbers_decimals(1.642499, resLAKN6_S1, 4);
	//checkGlasses.push_back(checkLAKN6_S1);
	////LAKN7
	//real resLAKN7_S1 = glasses.getLAKN7_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkLAKN7_S1 = Math::compareTwoNumbers_decimals(1.651600, resLAKN7_S1, 4);
	//checkGlasses.push_back(checkLAKN7_S1);
	////LAKN12
	//real resLAKN12_S1 = glasses.getLAKN12_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkLAKN12_S1 = Math::compareTwoNumbers_decimals(1.677900, resLAKN12_S1, 4);
	//checkGlasses.push_back(checkLAKN12_S1);
	////LAKN13
	//real resLAKN13_S1 = glasses.getLAKN13_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkLAKN13_S1 = Math::compareTwoNumbers_decimals(1.693501, resLAKN13_S1, 4);
	//checkGlasses.push_back(checkLAKN13_S1);
	////LAKN14
	//real resLAKN14_S1 = glasses.getLAKN14_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkLAKN14_S1 = Math::compareTwoNumbers_decimals(1.696800, resLAKN14_S1, 4);
	//checkGlasses.push_back(checkLAKN14_S1);
	////LAKN22
	//real resLAKN22_S1 = glasses.getLAKN22_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkLAKN22_S1 = Math::compareTwoNumbers_decimals(1.651130, resLAKN22_S1, 4);
	//checkGlasses.push_back(checkLAKN22_S1);
	////LASF3
	//real resLASF3_S1 = glasses.getLASF3_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkLASF3_S1 = Math::compareTwoNumbers_decimals(1.808009, resLASF3_S1, 4);
	//checkGlasses.push_back(checkLASF3_S1);
	////LASF14A
	//real resLASF14A_S1 = glasses.getLASF14A_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkLASF14A_S1 = Math::compareTwoNumbers_decimals(1.822226, resLASF14A_S1, 4);
	//checkGlasses.push_back(checkLASF14A_S1);
	////LASF18A
	//real resLASF18A_S1 = glasses.getLASF18A_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkLASF18A_S1 = Math::compareTwoNumbers_decimals(1.913482, resLASF18A_S1, 4);
	//checkGlasses.push_back(checkLASF18A_S1);
	////LASF32
	//real resLASF32_S1 = glasses.getLASF32_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkLASF32_S1 = Math::compareTwoNumbers_decimals(1.803493, resLASF32_S1, 4);
	//checkGlasses.push_back(checkLASF32_S1);
	////LASF33
	//real resLASF33_S1 = glasses.getLASF33_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkLASF33_S1 = Math::compareTwoNumbers_decimals(1.805958, resLASF33_S1, 4);
	//checkGlasses.push_back(checkLASF33_S1);
	////LASF36A
	//real resLASF36A_S1 = glasses.getLASF36A_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkLASF36A_S1 = Math::compareTwoNumbers_decimals(1.797117, resLASF36A_S1, 4);
	//checkGlasses.push_back(checkLASF36A_S1);
	////LASFN15
	//real resLASFN15_S1 = glasses.getLASFN15_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkLASFN15_S1 = Math::compareTwoNumbers_decimals(1.878001, resLASFN15_S1, 4);
	//checkGlasses.push_back(checkLASFN15_S1);
	////LASFN30
	//real resLASFN30_S1 = glasses.getLASFN30_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkLASFN30_S1 = Math::compareTwoNumbers_decimals(1.803181, resLASFN30_S1, 4);
	//checkGlasses.push_back(checkLASFN30_S1);
	////LASFN31
	//real resLASFN31_S1 = glasses.getLASFN31_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkLASFN31_S1 = Math::compareTwoNumbers_decimals(1.880669, resLASFN31_S1, 4);
	//checkGlasses.push_back(checkLASFN31_S1);
	////LF5HT
	//real resLF5HT_S1 = glasses.getLF5HT_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkLF5HT_S1 = Math::compareTwoNumbers_decimals(1.581483, resLF5HT_S1, 4);
	//checkGlasses.push_back(checkLF5HT_S1);
	////LF6HT
	//real resLF6HT_S1 = glasses.getLF6HT_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkLF6HT_S1 = Math::compareTwoNumbers_decimals(1.567320, resLF6HT_S1, 4);
	//checkGlasses.push_back(checkLF6HT_S1);
	////LF7
	//real resLF7_S1 = glasses.getLF7_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkLF7_S1 = Math::compareTwoNumbers_decimals(1.575011, resLF7_S1, 4);
	//checkGlasses.push_back(checkLF7_S1);
	////LF8
	//real resLF8_S1 = glasses.getLF8_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkLF8_S1 = Math::compareTwoNumbers_decimals(1.564435, resLF8_S1, 4);
	//checkGlasses.push_back(checkLF8_S1);
	////LLF1HT
	//real resLLF1HT_S1 = glasses.getLLF1HT_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkLLF1HT_S1 = Math::compareTwoNumbers_decimals(1.548144, resLLF1HT_S1, 4);
	//checkGlasses.push_back(checkLLF1HT_S1);
	////LLF2
	//real resLLF2_S1 = glasses.getLLF2_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkLLF2_S1 = Math::compareTwoNumbers_decimals(1.540719, resLLF2_S1, 4);
	//checkGlasses.push_back(checkLLF2_S1);
	////LLF6
	//real resLLF6_S1 = glasses.getLLF6_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkLLF6_S1 = Math::compareTwoNumbers_decimals(1.531719, resLLF6_S1, 4);
	//checkGlasses.push_back(checkLLF6_S1);
	////LLF6HT
	//real resLLF6HT_S1 = glasses.getLLF6HT_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkLLF6HT_S1 = Math::compareTwoNumbers_decimals(1.531739, resLLF6HT_S1, 4);
	//checkGlasses.push_back(checkLLF6HT_S1);
	////LLF7
	//real resLLF7_S1 = glasses.getLLF7_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkLLF7_S1 = Math::compareTwoNumbers_decimals(1.548831, resLLF7_S1, 4);
	//checkGlasses.push_back(checkLLF7_S1);
	////NFK56
	//real resNFK56_S1 = glasses.getNFK56_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkNFK56_S1 = Math::compareTwoNumbers_decimals(1.434250, resNFK56_S1, 5);
	//checkGlasses.push_back(checkNFK56_S1);
	////NLAK33
	//real resNLAK33_S1 = glasses.getNLAK33_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkNLAK33_S1 = Math::compareTwoNumbers_decimals(1.753977, resNLAK33_S1, 4);
	//checkGlasses.push_back(checkNLAK33_S1);
	////NLF5
	//real resNLF5_S1 = glasses.getNLF5_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkNLF5_S1 = Math::compareTwoNumbers_decimals(1.581440, resNLF5_S1, 4);
	//checkGlasses.push_back(checkNLF5_S1);
	////NLLF1
	//real resNLLF1_S1 = glasses.getNLLF1_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkNLLF1_S1 = Math::compareTwoNumbers_decimals(1.548140, resNLLF1_S1, 4);
	//checkGlasses.push_back(checkNLLF1_S1);
	////NLLF6
	//real resNLLF6_S1 = glasses.getNLLF6_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkNLLF6_S1 = Math::compareTwoNumbers_decimals(1.531688, resNLLF6_S1, 4);
	//checkGlasses.push_back(checkNLLF6_S1);
	////NPK52
	//real resNPK52_S1 = glasses.getNPK52_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkNPK52_S1 = Math::compareTwoNumbers_decimals(1.497005, resNPK52_S1, 4);
	//checkGlasses.push_back(checkNPK52_S1);
	////NPSK57
	//real resNPSK57_S1 = glasses.getNPSK57_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkNPSK57_S1 = Math::compareTwoNumbers_decimals(1.592400, resNPSK57_S1, 5);
	//checkGlasses.push_back(checkNPSK57_S1);
	////NPSK58
	//real resNPSK58_S1 = glasses.getNPSK58_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkNPSK58_S1 = Math::compareTwoNumbers_decimals(1.569070, resNPSK58_S1, 4);
	//checkGlasses.push_back(checkNPSK58_S1);
	////NSK18
	//real resNSK18_S1 = glasses.getNSK18_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkNSK18_S1 = Math::compareTwoNumbers_decimals(1.638540, resNSK18_S1, 4);
	//checkGlasses.push_back(checkNSK18_S1);
	////PK1
	//real resPK1_S1 = glasses.getPK1_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkPK1_S1 = Math::compareTwoNumbers_decimals(1.503781, resPK1_S1, 4);
	//checkGlasses.push_back(checkPK1_S1);
	////PK2
	//real resPK2_S1 = glasses.getPK2_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkPK2_S1 = Math::compareTwoNumbers_decimals(1.518211, resPK2_S1, 4);
	//checkGlasses.push_back(checkPK2_S1);
	////PK3
	//real resPK3_S1 = glasses.getPK3_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkPK3_S1 = Math::compareTwoNumbers_decimals(1.525419, resPK3_S1, 5);
	//checkGlasses.push_back(checkPK3_S1);
	////PK50
	//real resPK50_S1 = glasses.getPK50_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkPK50_S1 = Math::compareTwoNumbers_decimals(1.520540, resPK50_S1, 4);
	//checkGlasses.push_back(checkPK50_S1);
	////PK51A
	//real resPK51A_S1 = glasses.getPK51A_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkPK51A_S1 = Math::compareTwoNumbers_decimals(1.528554, resPK51A_S1, 4);
	//checkGlasses.push_back(checkPK51A_S1);
	////PSK2
	//real resPSK2_S1 = glasses.getPSK2_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkPSK2_S1 = Math::compareTwoNumbers_decimals(1.568730, resPSK2_S1, 4);
	//checkGlasses.push_back(checkPSK2_S1);
	////PSK3
	//real resPSK3_S1 = glasses.getPSK3_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkPSK3_S1 = Math::compareTwoNumbers_decimals(1.552322, resPSK3_S1, 4);
	//checkGlasses.push_back(checkPSK3_S1);
	////PSK50
	//real resPSK50_S1 = glasses.getPSK50_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkPSK50_S1 = Math::compareTwoNumbers_decimals(1.557529, resPSK50_S1, 4);
	//checkGlasses.push_back(checkPSK50_S1);
	////PSK52
	//real resPSK52_S1 = glasses.getPSK52_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkPSK52_S1 = Math::compareTwoNumbers_decimals(1.603101, resPSK52_S1, 4);
	//checkGlasses.push_back(checkPSK52_S1);
	////PSK53A
	//real resPSK53A_S1 = glasses.getPSK53A_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkPSK53A_S1 = Math::compareTwoNumbers_decimals(1.620141, resPSK53A_S1, 4);
	//checkGlasses.push_back(checkPSK53A_S1);
	////PSK54
	//real resPSK54_S1 = glasses.getPSK54_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkPSK54_S1 = Math::compareTwoNumbers_decimals(1.585990, resPSK54_S1, 4);
	//checkGlasses.push_back(checkPSK54_S1);
	////SF3
	//real resSF3_S1 = glasses.getSF3_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkSF3_S1 = Math::compareTwoNumbers_decimals(1.740002, resSF3_S1, 4);
	//checkGlasses.push_back(checkSF3_S1);
	////SF8
	//real resSF8_S1 = glasses.getSF8_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkSF8_S1 = Math::compareTwoNumbers_decimals(1.688932, resSF8_S1, 4);
	//checkGlasses.push_back(checkSF8_S1);
	////SF9
	//real resSF9_S1 = glasses.getSF9_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkSF9_S1 = Math::compareTwoNumbers_decimals(1.654461, resSF9_S1, 4);
	//checkGlasses.push_back(checkSF9_S1);
	////SF12
	//real resSF12_S1 = glasses.getSF12_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkSF12_S1 = Math::compareTwoNumbers_decimals(1.648310, resSF12_S1, 4);
	//checkGlasses.push_back(checkSF12_S1);
	////SF13
	//real resSF13_S1 = glasses.getSF13_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkSF13_S1 = Math::compareTwoNumbers_decimals(1.740771, resSF13_S1, 4);
	//checkGlasses.push_back(checkSF13_S1);
	////SF16
	//real resSF16_S1 = glasses.getSF16_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkSF16_S1 = Math::compareTwoNumbers_decimals(1.646112, resSF16_S1, 4);
	//checkGlasses.push_back(checkSF16_S1);
	////SF18
	//real resSF18_S1 = glasses.getSF18_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkSF18_S1 = Math::compareTwoNumbers_decimals(1.721510, resSF18_S1, 4);
	//checkGlasses.push_back(checkSF18_S1);
	////SF19
	//real resSF19_S1 = glasses.getSF19_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkSF19_S1 = Math::compareTwoNumbers_decimals(1.666800, resSF19_S1, 4);
	//checkGlasses.push_back(checkSF19_S1);
	////SF53
	//real resSF53_S1 = glasses.getSF53_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkSF53_S1 = Math::compareTwoNumbers_decimals(1.728301, resSF53_S1, 4);
	//checkGlasses.push_back(checkSF53_S1);
	////SF54
	//real resSF54_S1 = glasses.getSF54_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkSF54_S1 = Math::compareTwoNumbers_decimals(1.740800, resSF54_S1, 4);
	//checkGlasses.push_back(checkSF54_S1);
	////SF55
	//real resSF55_S1 = glasses.getSF55_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkSF55_S1 = Math::compareTwoNumbers_decimals(1.761800, resSF55_S1, 4);
	//checkGlasses.push_back(checkSF55_S1);
	////SF57HT
	//real resSF57HT_S1 = glasses.getSF57HT_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkSF57HT_S1 = Math::compareTwoNumbers_decimals(1.846663, resSF57HT_S1, 4);
	//checkGlasses.push_back(checkSF57HT_S1);
	////SF58
	//real resSF58_S1 = glasses.getSF58_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkSF58_S1 = Math::compareTwoNumbers_decimals(1.917613, resSF58_S1, 4);
	//checkGlasses.push_back(checkSF58_S1);
	////SF59
	//real resSF59_S1 = glasses.getSF59_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkSF59_S1 = Math::compareTwoNumbers_decimals(1.952497, resSF59_S1, 4);
	//checkGlasses.push_back(checkSF59_S1);
	////SF63
	//real resSF63_S1 = glasses.getSF63_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkSF63_S1 = Math::compareTwoNumbers_decimals(1.748400, resSF63_S1, 4);
	//checkGlasses.push_back(checkSF63_S1);
	////SF64A
	//real resSF64A_S1 = glasses.getSF64A_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkSF64A_S1 = Math::compareTwoNumbers_decimals(1.705850, resSF64A_S1, 5);
	//checkGlasses.push_back(checkSF64A_S1);
	////SFL4
	//real resSFL4_S1 = glasses.getSFL4_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkSFL4_S1 = Math::compareTwoNumbers_decimals(1.755200, resSFL4_S1, 4);
	//checkGlasses.push_back(checkSFL4_S1);
	////SFL56
	//real resSFL56_S1 = glasses.getSFL56_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkSFL56_S1 = Math::compareTwoNumbers_decimals(1.784700, resSFL56_S1, 4);
	//checkGlasses.push_back(checkSFL56_S1);
	////SK1
	//real resSK1_S1 = glasses.getSK1_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkSK1_S1 = Math::compareTwoNumbers_decimals(1.610250, resSK1_S1, 5);
	//checkGlasses.push_back(checkSK1_S1);
	////SK2
	//real resSK2_S1 = glasses.getSK2_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkSK2_S1 = Math::compareTwoNumbers_decimals(1.607381, resSK2_S1, 4);
	//checkGlasses.push_back(checkSK2_S1);
	////SK3
	//real resSK3_S1 = glasses.getSK3_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkSK3_S1 = Math::compareTwoNumbers_decimals(1.608810, resSK3_S1, 4);
	//checkGlasses.push_back(checkSK3_S1);
	////SK4
	//real resSK4_S1 = glasses.getSK4_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkSK4_S1 = Math::compareTwoNumbers_decimals(1.612720, resSK4_S1, 4);
	//checkGlasses.push_back(checkSK4_S1);
	////SK5
	//real resSK5_S1 = glasses.getSK5_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkSK5_S1 = Math::compareTwoNumbers_decimals(1.589130, resSK5_S1, 4);
	//checkGlasses.push_back(checkSK5_S1);
	////SK6
	//real resSK6_S1 = glasses.getSK6_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkSK6_S1 = Math::compareTwoNumbers_decimals(1.613750, resSK6_S1, 5);
	//checkGlasses.push_back(checkSK6_S1);
	////SK7
	//real resSK7_S1 = glasses.getSK7_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkSK7_S1 = Math::compareTwoNumbers_decimals(1.607290, resSK7_S1, 4);
	//checkGlasses.push_back(checkSK7_S1);
	////SK8
	//real resSK8_S1 = glasses.getSK8_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkSK8_S1 = Math::compareTwoNumbers_decimals(1.611171, resSK8_S1, 4);
	//checkGlasses.push_back(checkSK8_S1);
	////SK10
	//real resSK10_S1 = glasses.getSK10_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkSK10_S1 = Math::compareTwoNumbers_decimals(1.622801, resSK10_S1, 4);
	//checkGlasses.push_back(checkSK10_S1);
	////SK11
	//real resSK11_S1 = glasses.getSK11_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkSK11_S1 = Math::compareTwoNumbers_decimals(1.563840, resSK11_S1, 4);
	//checkGlasses.push_back(checkSK11_S1);
	////SK12
	//real resSK12_S1 = glasses.getSK12_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkSK12_S1 = Math::compareTwoNumbers_decimals(1.583131, resSK12_S1, 4);
	//checkGlasses.push_back(checkSK12_S1);
	////SK13
	//real resSK13_S1 = glasses.getSK13_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkSK13_S1 = Math::compareTwoNumbers_decimals(1.591809, resSK13_S1, 4);
	//checkGlasses.push_back(checkSK13_S1);
	////SK14
	//real resSK14_S1 = glasses.getSK14_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkSK14_S1 = Math::compareTwoNumbers_decimals(1.603110, resSK14_S1, 4);
	//checkGlasses.push_back(checkSK14_S1);
	////SK15
	//real resSK15_S1 = glasses.getSK15_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkSK15_S1 = Math::compareTwoNumbers_decimals(1.622990, resSK15_S1, 4);
	//checkGlasses.push_back(checkSK15_S1);
	////SK16
	//real resSK16_S1 = glasses.getSK16_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkSK16_S1 = Math::compareTwoNumbers_decimals(1.620410, resSK16_S1, 4);
	//checkGlasses.push_back(checkSK16_S1);
	////SK18A
	//real resSK18A_S1 = glasses.getSK18A_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkSK18A_S1 = Math::compareTwoNumbers_decimals(1.638540, resSK18A_S1, 4);
	//checkGlasses.push_back(checkSK18A_S1);
	////SK51
	//real resSK51_S1 = glasses.getSK51_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkSK51_S1 = Math::compareTwoNumbers_decimals(1.620900, resSK51_S1, 4);
	//checkGlasses.push_back(checkSK51_S1);
	////SK55
	//real resSK55_S1 = glasses.getSK55_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkSK55_S1 = Math::compareTwoNumbers_decimals(1.620411, resSK55_S1, 4);
	//checkGlasses.push_back(checkSK55_S1);
	////SSK1
	//real resSSK1_S1 = glasses.getSSK1_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkSSK1_S1 = Math::compareTwoNumbers_decimals(1.617201, resSSK1_S1, 4);
	//checkGlasses.push_back(checkSSK1_S1);
	////SSK2
	//real resSSK2_S1 = glasses.getSSK2_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkSSK2_S1 = Math::compareTwoNumbers_decimals(1.622301, resSSK2_S1, 4);
	//checkGlasses.push_back(checkSSK2_S1);
	////SSK3
	//real resSSK3_S1 = glasses.getSSK3_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkSSK3_S1 = Math::compareTwoNumbers_decimals(1.614837, resSSK3_S1, 4);
	//checkGlasses.push_back(checkSSK3_S1);
	////SSK4A
	//real resSSK4A_S1 = glasses.getSSK4A_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkSSK4A_S1 = Math::compareTwoNumbers_decimals(1.617650, resSSK4A_S1, 5);
	//checkGlasses.push_back(checkSSK4A_S1);
	////SSK50
	//real resSSK50_S1 = glasses.getSSK50_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkSSK50_S1 = Math::compareTwoNumbers_decimals(1.617954, resSSK50_S1, 4);
	//checkGlasses.push_back(checkSSK50_S1);
	////SSK51
	//real resSSK51_S1 = glasses.getSSK51_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkSSK51_S1 = Math::compareTwoNumbers_decimals(1.603607, resSSK51_S1, 4);
	//checkGlasses.push_back(checkSSK51_S1);
	////SSKN5
	//real resSSKN5_S1 = glasses.getSSKN5_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkSSKN5_S1 = Math::compareTwoNumbers_decimals(1.658440, resSSKN5_S1, 4);
	//checkGlasses.push_back(checkSSKN5_S1);
	////SSKN8
	//real resSSKN8_S1 = glasses.getSSKN8_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkSSKN8_S1 = Math::compareTwoNumbers_decimals(1.617720, resSSKN8_S1, 4);
	//checkGlasses.push_back(checkSSKN8_S1);
	////TIF3
	//real resTIF3_S1 = glasses.getTIF3_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkTIF3_S1 = Math::compareTwoNumbers_decimals(1.547649, resTIF3_S1, 4);
	//checkGlasses.push_back(checkTIF3_S1);
	////TIF6
	//real resTIF6_S1 = glasses.getTIF6_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkTIF6_S1 = Math::compareTwoNumbers_decimals(1.616501, resTIF6_S1, 4);
	//checkGlasses.push_back(checkTIF6_S1);
	////TIFN5
	//real resTIFN5_S1 = glasses.getTIFN5_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkTIFN5_S1 = Math::compareTwoNumbers_decimals(1.593555, resTIFN5_S1, 4);
	//checkGlasses.push_back(checkTIFN5_S1);
	////UBK7
	//real resUBK7_S1 = glasses.getUBK7_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkUBK7_S1 = Math::compareTwoNumbers_decimals(1.516801, resUBK7_S1, 4);
	//checkGlasses.push_back(checkUBK7_S1);
	////UK50
	//real resUK50_S1 = glasses.getUK50_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkUK50_S1 = Math::compareTwoNumbers_decimals(1.522571, resUK50_S1, 4);
	//checkGlasses.push_back(checkUK50_S1);
	////ULTRAN20
	//real resULTRAN20_S1 = glasses.getULTRAN20_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkULTRAN20_S1 = Math::compareTwoNumbers_decimals(1.486561, resULTRAN20_S1, 4);
	//checkGlasses.push_back(checkULTRAN20_S1);
	////ULTRAN30
	//real resULTRAN30_S1 = glasses.getULTRAN30_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkULTRAN30_S1 = Math::compareTwoNumbers_decimals(1.548300, resULTRAN30_S1, 4);
	//checkGlasses.push_back(checkULTRAN30_S1);
	////ZK1
	//real resZK1_S1 = glasses.getZK1_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkZK1_S1 = Math::compareTwoNumbers_decimals(1.533149, resZK1_S1, 4);
	//checkGlasses.push_back(checkZK1_S1);
	////ZKN7
	//real resZKN7_S1 = glasses.getZKN7_S1().calcRefractiveIndexSnellmeier1(587.6);
	//bool checkZKN7_S1 = Math::compareTwoNumbers_decimals(1.508469, resZKN7_S1, 4);
	//checkGlasses.push_back(checkZKN7_S1);
		
	bool checkRefIndexGlasses = Math::checkTrueOfVectorElements(checkGlasses);

	return checkRefIndexGlasses;
}