#pragma once
#include "GlassDispersionFormulas/MaterialSellmeier1.h"

class glass
{
public:
	glass()
	{ };
	~glass() {};

	void loadGlassCatalog_Schott();

	// Air zemax
	MaterialSellmeier1 getAir();

	// F2
	MaterialSellmeier1 get_F2_S1();

	// F5
	MaterialSellmeier1 getF5_S1();

	// K10
	MaterialSellmeier1 getK10_S1();

	// K7
	MaterialSellmeier1 getK7_S1();

	//LAFN7
	MaterialSellmeier1 getLAFN7_S1();

	//LF5
	MaterialSellmeier1 getLF5_S1();

	//LLF1
	MaterialSellmeier1 getLLF1_S1();

	//NBAF10
	MaterialSellmeier1 getNBAF10_S1();

	//NBAF4
	MaterialSellmeier1 getNBAF4_S1();

	//NBAF51
	MaterialSellmeier1 getNBAF51_S1();

	//NBAF52
	MaterialSellmeier1 getNBAF52_S1();

	//NBAK1
	MaterialSellmeier1 getNBAK1_S1();

	//NBAK2
	MaterialSellmeier1 getNBAK2_S1();

	//NBAK4
	MaterialSellmeier1 getNBAK4_S1();

	//NBAK4HT
	MaterialSellmeier1 getNBAK4HT_S1();

	//NBALF4
	MaterialSellmeier1 getNBALF4_S1();

	//NBALF5
	MaterialSellmeier1 getNBALF5_S1();

	//NBASF2
	MaterialSellmeier1 getNBASF2_S1();

	//NBASF64
	MaterialSellmeier1 getNBASF64_S1();

	//NBK10
	MaterialSellmeier1 getNBK10_S1();

	//NBK7
	MaterialSellmeier1 getNBK7_S1();

	//NBK7HT
	MaterialSellmeier1 getNBK7HT_S1();

	//NF2
	MaterialSellmeier1 getNF2_S1();

	//NFK5
	MaterialSellmeier1 getNFK5_S1();

	//NFK51A
	MaterialSellmeier1 getNFK51A_S1();

	//NK5
	MaterialSellmeier1 getNK5_S1();

	//NKF9
	MaterialSellmeier1 getNKF9_S1();

	//NKZFS1
	MaterialSellmeier1 getNKZFS11_S1();

	//NKZFS2
	MaterialSellmeier1 getNKZFS2_S1();

	//NKZFS4
	MaterialSellmeier1 getNKZFS4_S1();

	//NKZFS4HT
	MaterialSellmeier1 getNKZFS4HT_S1();

	//NKZFS5
	MaterialSellmeier1 getNKZFS5_S1();

	//NKZFS8
	MaterialSellmeier1 getNKZFS8_S1();

	//NLAF2
	MaterialSellmeier1 getNLAF2_S1();

	//NLAF21
	MaterialSellmeier1 getNLAF21_S1();

	//NLAF33
	MaterialSellmeier1 getNLAF33_S1();

	//NLAF34
	MaterialSellmeier1 getNLAF34_S1();

	//NLAF35
	MaterialSellmeier1 getNLAF35_S1();

	//NLAF7
	MaterialSellmeier1 getNLAF7_S1();

	//NLAK10
	MaterialSellmeier1 getNLAK10_S1();

	//NLAK12
	MaterialSellmeier1 getNLAK12_S1();

	//NLAK14
	MaterialSellmeier1 getNLAK14_S1();

	//NLAK21
	MaterialSellmeier1 getNLAK21_S1();

	//NLAK22
	MaterialSellmeier1 getNLAK22_S1();

	//NLAK33A
	MaterialSellmeier1 getNLAK33A_S1();

	//NLAK33B
	MaterialSellmeier1 getNLAK33B_S1();

	//NLAK34
	MaterialSellmeier1 getNLAK34_S1();

	//NLAK7
	MaterialSellmeier1 getNLAK7_S1();

	//NLAK8
	MaterialSellmeier1 getNLAK8_S1();

	//NLAK9
	MaterialSellmeier1 getNLAK9_S1();

	//NLASF31A
	MaterialSellmeier1 getNLASF31A_S1();

	//NLASF40
	MaterialSellmeier1 getNLASF40_S1();

	//NLASF41
	MaterialSellmeier1 getNLASF41_S1();

	//NLASF43
	MaterialSellmeier1 getNLASF43_S1();

	//NLASF44
	MaterialSellmeier1 getNLASF44_S1();

	//NLASF45
	MaterialSellmeier1 getNLASF45_S1();

	//NLASF45HT
	MaterialSellmeier1 getNLASF45HT_S1();

	//NLASF46A
	MaterialSellmeier1 getNLASF46A_S1();

	//NLASF46B
	MaterialSellmeier1 getNLASF46B_S1();

	//NLASF9
	MaterialSellmeier1 getNLASF9_S1();

	//NLASF9HT
	MaterialSellmeier1 getNLASF9HT_S1();

	//NPK51
	MaterialSellmeier1 getNPK51_S1();

	//NPK52A
	MaterialSellmeier1 getNPK52A_S1();

	//NPSK3
	MaterialSellmeier1 getNPSK3_S1();

	//NPSK53A
	MaterialSellmeier1 getNPSK53A_S1();

	//NSF1
	MaterialSellmeier1 getNSF1_S1();

	//NSF10
	MaterialSellmeier1 getNSF10_S1();

	//NSF11
	MaterialSellmeier1 getNSF11_S1();

	//NSF14
	MaterialSellmeier1 getNSF14_S1();

	//NSF15
	MaterialSellmeier1 getNSF15_S1();

	//NSF2
	MaterialSellmeier1 getNSF2_S1();

	//NSF4
	MaterialSellmeier1 getNSF4_S1();

	//NSF5
	MaterialSellmeier1 getNSF5_S1();

	//NSF57
	MaterialSellmeier1 getNSF57_S1();

	//NSF57HT
	MaterialSellmeier1 getNSF57HT_S1();

	//NSF57HTULTRA
	MaterialSellmeier1 getNSF57HTULTRA_S1();

	//NSF6
	MaterialSellmeier1 getNSF6_S1();

	//NSF66
	MaterialSellmeier1 getNSF66_S1();

	//NSF6HT
	MaterialSellmeier1 getNSF6HT_S1();

	//NSF6HTULTRA
	MaterialSellmeier1 getNSF6HTULTRA_S1();

	//NSF8
	MaterialSellmeier1 getNSF8_S1();

	//NSK11
	MaterialSellmeier1 getNSK11_S1();

	//NSK14
	MaterialSellmeier1 getNSK14_S1();

	//NSK16
	MaterialSellmeier1 getNSK16_S1();

	//NSK2
	MaterialSellmeier1 getNSK2_S1();

	//NSK2HT
	MaterialSellmeier1 getNSK2HT_S1();

	//NSK4
	MaterialSellmeier1 getNSK4_S1();

	//NSK5
	MaterialSellmeier1 getNSK5_S1();

	//NSSK2
	MaterialSellmeier1 getNSSK2_S1();

	//NSSK5
	MaterialSellmeier1 getNSSK5_S1();

	//NSSK8
	MaterialSellmeier1 getNSSK8_S1();

	//NZK7
	MaterialSellmeier1 getNZK7_S1();

	//PLAF37
	MaterialSellmeier1 getPLAF37_S1();

	//PLAK35
	MaterialSellmeier1 getPLAK35_S1();

	//PLASF47
	MaterialSellmeier1 getPLASF47_S1();

	//PLASF50
	MaterialSellmeier1 getPLASF50_S1();

	//PLASF51
	MaterialSellmeier1 getPLASF51_S1();

	//PSF67
	MaterialSellmeier1 getPSF67_S1();

	//PSF68
	MaterialSellmeier1 getPSF68_S1();

	//PSF69
	MaterialSellmeier1 getPSF69_S1();

	//PSF8
	MaterialSellmeier1 getPSF8_S1();

	//PSK57
	MaterialSellmeier1 getPSK57_S1();

	//PSK58A
	MaterialSellmeier1 getPSK58A_S1();

	//PSK60
	MaterialSellmeier1 getPSK60_S1();

	//SF1
	MaterialSellmeier1 getSF1_S1();

	//SF10
	MaterialSellmeier1 getSF10_S1();

	//SF2
	MaterialSellmeier1 getSF2_S1();

	//SF4
	MaterialSellmeier1 getSF4_S1();

	//SF5
	MaterialSellmeier1 getSF5_S1();

	//SF56A
	MaterialSellmeier1 getSF56A_S1();

	//SF57 
	MaterialSellmeier1 getSF57_S1();

	//SF6
	MaterialSellmeier1 getSF6_S1();

	//SF6HT
	MaterialSellmeier1 getSF6HT_S1();

	//SF57HTULTRA
	MaterialSellmeier1 getSF57HTULTRA_S1();

	//PBK7
	MaterialSellmeier1 getPBK7_S1();

	//PSK57Q1
	MaterialSellmeier1 getPSK57Q1_S1();

	//SF11
	MaterialSellmeier1 getSF11_S1();

	//LASF35
	MaterialSellmeier1 getLASF35_S1();

	//FK3
	MaterialSellmeier1 getFK3_S1();

	//NSK10
	MaterialSellmeier1 getNSK10_S1();

	//NSK15
	MaterialSellmeier1 getNSK15_S1();

	//NBAF3
	MaterialSellmeier1 getNBAF3_S1();
	
	//BAFN6
	MaterialSellmeier1 getBAFN6_S1();
	
	//NLAF3
	MaterialSellmeier1 getNLAF3_S1();
	
	//SFL57
	MaterialSellmeier1 getSFL57_S1();
	
	//SFL6
	MaterialSellmeier1 getSFL6_S1();
	
	//NSF19
	MaterialSellmeier1 getNSF19_S1();
	
	//NSF56
	MaterialSellmeier1 getNSF56_S1();
	
	//NSF64
	MaterialSellmeier1 getNSF64_S1();
	
	//NPSK53
	MaterialSellmeier1 getNPSK53_S1();
	
	//BK7G18
	MaterialSellmeier1 getBK7G18_S1();
	
	//LF5G19
	MaterialSellmeier1 getLF5G19_S1();
	
	//LF5G15
	MaterialSellmeier1 getLF5G15_S1();
	
	//K5G20
	MaterialSellmeier1 getK5G20_S1();
	
	//LAK9G15
	MaterialSellmeier1 getLAK9G15_S1();
	
	//F2G12
	MaterialSellmeier1 getF2G12_S1();
	
	//SF6G05
	MaterialSellmeier1 getSF6G05_S1();
	
	//LASFN9
	MaterialSellmeier1 getLASFN9_S1();
	
	//LAKL12
	MaterialSellmeier1 getLAKL12_S1();
	
	//NLASF46
	MaterialSellmeier1 getNLASF46_S1();
	
	//NLASF31
	MaterialSellmeier1 getNLASF31_S1();
	
	//NFK51
	MaterialSellmeier1 getNFK51_S1();
	
	//NLAF32
	MaterialSellmeier1 getNLAF32_S1();
	
	//KZFSN4
	MaterialSellmeier1 getKZFSN4_S1();
	
	//SF14
	MaterialSellmeier1 getSF14_S1();
	
	//SF15
	MaterialSellmeier1 getSF15_S1();
	
	//SF66
	MaterialSellmeier1 getSF66_S1();
	
	//LITHOTECCAF2
	MaterialSellmeier1 getLITHOTECCAF2_S1();
	
	//LITHOSILQ
	MaterialSellmeier1 getLITHOSILQ_S1();
	
	////D263TECO
	//MaterialSellmeier1 getD263TECO_S1();
	//
	////AF32ECO
	//MaterialSellmeier1 getAF32ECO_S1();
	
	//KZFS12
	MaterialSellmeier1 getKZFS12_S1();
	
	//PPK53
	MaterialSellmeier1 getPPK53_S1();
	
	//NLAF36
	MaterialSellmeier1 getNLAF36_S1();
	
	//FK5HTI
	MaterialSellmeier1 getFK5HTI_S1();
	
	//LF5HTI
	MaterialSellmeier1 getLF5HTI_S1();
	
	//LLF1HTI
	MaterialSellmeier1 getLLF1HTI_S1();
	
	//NBK7HTI
	MaterialSellmeier1 getNBK7HTI_S1();
	
	//NFK58
	MaterialSellmeier1 getNFK58_S1();
	
	////B270
	////MaterialSellmeier1 getB270_S1(); this galss is missing 
	//// -> there must be an error in the Sellmeier constats...
	//// we get an other result for the refractive index than Zemax
	//// TODO: solve this problem and add class B270!!!
	//
	////BAF3
	//MaterialSellmeier1 getBAF3_S1();
	//
	////BAF4
	//MaterialSellmeier1 getBAF4_S1();
	//
	////BAF8
	//MaterialSellmeier1 getBAF8_S1();
	//
	////BAF9
	//MaterialSellmeier1 getBAF9_S1();
	//
	////BAF13
	//MaterialSellmeier1 getBAF13_S1();
	//
	////BAF50
	//MaterialSellmeier1 getBAF50_S1();
	//
	////BAF51
	//MaterialSellmeier1 getBAF51_S1();
	//
	////BAF52
	//MaterialSellmeier1 getBAF52_S1();
	//
	//BAFN10
	MaterialSellmeier1 getBAFN10_S1();
	//
	////BAFN11
	//MaterialSellmeier1 getBAFN11_S1();
	//
	////BAK1
	//MaterialSellmeier1 getBAK1_S1();
	//
	////BAK2
	//MaterialSellmeier1 getBAK2_S1();
	//
	////BAK4
	//MaterialSellmeier1 getBAK4_S1();
	//
	////BAK5
	//MaterialSellmeier1 getBAK5_S1();
	//
	////BAK50
	//MaterialSellmeier1 getBAK50_S1();
	//
	////BALF4
	//MaterialSellmeier1 getBALF4_S1();
	//
	////BALF5
	//MaterialSellmeier1 getBALF5_S1();
	//
	////BALF50
	//MaterialSellmeier1 getBALF50_S1();
	//
	////BALKN3
	//MaterialSellmeier1 getBALKN3_S1();
	//
	////BASF1
	//MaterialSellmeier1 getBASF1_S1();
	//
	////BASF2
	//MaterialSellmeier1 getBASF2_S1();
	//
	////BASF6
	//MaterialSellmeier1 getBASF6_S1();
	//
	////BASF10
	//MaterialSellmeier1 getBASF10_S1();
	//
	////BASF12
	//MaterialSellmeier1 getBASF12_S1();
	//
	////BASF13
	//MaterialSellmeier1 getBASF13_S1();
	//
	////BASF51
	//MaterialSellmeier1 getBASF51_S1();
	//
	////BASF52
	//MaterialSellmeier1 getBASF52_S1();
	//
	////BASF54
	//MaterialSellmeier1 getBASF54_S1();
	//
	////BASF56
	//MaterialSellmeier1 getBASF56_S1();
	//
	////BASF57
	//MaterialSellmeier1 getBASF57_S1();
	//
	////BASF64A
	//MaterialSellmeier1 getBASF64A_S1();
	//
	////BK1
	//MaterialSellmeier1 getBK1_S1();
	//
	////BK3
	//MaterialSellmeier1 getBK3_S1();
	//
	////BK6
	//MaterialSellmeier1 getBK6_S1();
	//
	////BK7
	//MaterialSellmeier1 getBK7_S1();
	//
	////BK7HT
	//MaterialSellmeier1 getBK7HT_S1();
	//
	////BK8
	//MaterialSellmeier1 getBK8_S1();
	//
	////BK10
	//MaterialSellmeier1 getBK10_S1();
	//
	////F1
	//MaterialSellmeier1 getF1_S1();
	//
	////F3
	//MaterialSellmeier1 getF3_S1();
	//
	////F4
	//MaterialSellmeier1 getF4_S1();
	//
	////F6
	//MaterialSellmeier1 getF6_S1();
	//
	////F7
	//MaterialSellmeier1 getF7_S1();
	//
	////F8
	//MaterialSellmeier1 getF8_S1();
	//
	////F8HT
	//MaterialSellmeier1 getF8HT_S1();
	//
	////F9
	//MaterialSellmeier1 getF9_S1();
	//
	////F13
	//MaterialSellmeier1 getF13_S1();
	//
	////F14
	//MaterialSellmeier1 getF14_S1();
	//
	////F14_HT
	//MaterialSellmeier1 getF14HT_S1();
	//
	////F15
	//MaterialSellmeier1 getF15_S1();
	//
	////FK5
	//MaterialSellmeier1 getFK5_S1();
	//
	////FK51
	//MaterialSellmeier1 getFK51_S1();
	//
	////FK52
	//MaterialSellmeier1 getFK52_S1();
	//
	////FK54
	//MaterialSellmeier1 getFK54_S1();
	//
	////FN11
	//MaterialSellmeier1 getFN11_S1();
	//
	////K3
	//MaterialSellmeier1 getK3_S1();
	//
	////K4
	//MaterialSellmeier1 getK4_S1();
	//
	////K5
	//MaterialSellmeier1 getK5_S1();
	//
	////K5HT
	//MaterialSellmeier1 getK5HT_S1();
	//
	////K7HT
	//MaterialSellmeier1 getK7HT_S1();
	//
	////K11
	//MaterialSellmeier1 getK11_S1();
	//
	////K50
	//MaterialSellmeier1 getK50_S1();
	//
	////KF3
	//MaterialSellmeier1 getKF3_S1();
	//
	////KF6
	//MaterialSellmeier1 getKF6_S1();
	//
	////KF9
	//MaterialSellmeier1 getKF9_S1();
	//
	////KZFN1
	//MaterialSellmeier1 getKZFN1_S1();
	//
	////KZFN2
	//MaterialSellmeier1 getKZFN2_S1();
	//
	////KZFS1
	//MaterialSellmeier1 getKZFS1_S1();
	//
	////KZFS6
	//MaterialSellmeier1 getKZFS6_S1();
	//
	////KZFS7A
	//MaterialSellmeier1 getKZFS7A_S1();
	//
	////KZFS8
	//MaterialSellmeier1 getKZFS8_S1();
	//
	////KZFSN2
	//MaterialSellmeier1 getKZFSN2_S1();
	//
	////KZFSN9
	//MaterialSellmeier1 getKZFSN9_S1();
	//
	////LAF2
	//MaterialSellmeier1 getLAF2_S1();
	//
	////LAF3
	//MaterialSellmeier1 getLAF3_S1();
	//
	////LAF9
	//MaterialSellmeier1 getLAF9_S1();
	//
	////LAF11A
	//MaterialSellmeier1 getLAF11A_S1();
	//
	////LAF13
	//MaterialSellmeier1 getLAF13_S1();
	//
	////LAF20
	//MaterialSellmeier1 getLAF20_S1();
	//
	////LAF22A
	//MaterialSellmeier1 getLAF22A_S1();
	//
	////LAFN8
	//MaterialSellmeier1 getLAFN8_S1();
	//
	////LAFN10
	//MaterialSellmeier1 getLAFN10_S1();
	//
	////LAFN21
	//MaterialSellmeier1 getLAFN21_S1();
	//
	////LAFN23
	//MaterialSellmeier1 getLAFN23_S1();
	//
	////LAFN24
	//MaterialSellmeier1 getLAFN24_S1();
	//
	////LAFN28
	//MaterialSellmeier1 getLAFN28_S1();
	//
	////LAK8
	//MaterialSellmeier1 getLAK8_S1();
	//
	////LAK9
	//MaterialSellmeier1 getLAK9_S1();
	//
	////LAK10
	//MaterialSellmeier1 getLAK10_S1();
	//
	////LAK11
	//MaterialSellmeier1 getLAK11_S1();
	//
	////LAK16A
	//MaterialSellmeier1 getLAK16A_S1();
	//
	////LAK21
	//MaterialSellmeier1 getLAK21_S1();
	//
	////LAK23
	//MaterialSellmeier1 getLAK23_S1();
	//
	////LAK28
	//MaterialSellmeier1 getLAK28_S1();
	//
	////LAK31
	//MaterialSellmeier1 getLAK31_S1();
	//
	////LAK33
	//MaterialSellmeier1 getLAK33_S1();
	//
	////LAKL21
	//MaterialSellmeier1 getLAKL21_S1();
	//
	////LAKN6
	//MaterialSellmeier1 getLAKN6_S1();
	//
	////LAKN7
	//MaterialSellmeier1 getLAKN7_S1();
	//
	////LAKN12
	//MaterialSellmeier1 getLAKN12_S1();
	//
	////LAKN13
	//MaterialSellmeier1 getLAKN13_S1();
	//
	////LAKN14
	//MaterialSellmeier1 getLAKN14_S1();
	//
	////LAKN22
	//MaterialSellmeier1 getLAKN22_S1();
	//
	////LASF3
	//MaterialSellmeier1 getLASF3_S1();
	//
	////LASF14A
	//MaterialSellmeier1 getLASF14A_S1();
	//
	////LASF18A
	//MaterialSellmeier1 getLASF18A_S1();
	//
	////LASF32
	//MaterialSellmeier1 getLASF32_S1();
	//
	////LASF33
	//MaterialSellmeier1 getLASF33_S1();
	//
	////LASF36A
	//MaterialSellmeier1 getLASF36A_S1();
	//
	////LASFN15
	//MaterialSellmeier1 getLASFN15_S1();
	//
	////LASFN30
	//MaterialSellmeier1 getLASFN30_S1();
	//
	////LASFN31
	//MaterialSellmeier1 getLASFN31_S1();
	//
	////LF5HT
	//MaterialSellmeier1 getLF5HT_S1();
	//
	////LF6HT
	//MaterialSellmeier1 getLF6HT_S1();
	//
	////LF7
	//MaterialSellmeier1 getLF7_S1();
	//
	////LF8
	//MaterialSellmeier1 getLF8_S1();
	//
	////LLF1HT
	//MaterialSellmeier1 getLLF1HT_S1();
	//
	////LLF2
	//MaterialSellmeier1 getLLF2_S1();
	//
	////LLF6
	//MaterialSellmeier1 getLLF6_S1();
	//
	////LLF6HT
	//MaterialSellmeier1 getLLF6HT_S1();
	//
	////LLF7
	//MaterialSellmeier1 getLLF7_S1();
	//
	////NFK56
	//MaterialSellmeier1 getNFK56_S1();
	//
	////NLAK33
	//MaterialSellmeier1 getNLAK33_S1();
	//
	////NLF5
	//MaterialSellmeier1 getNLF5_S1();
	//
	////NLLF1
	//MaterialSellmeier1 getNLLF1_S1();
	//
	////NLLF6
	//MaterialSellmeier1 getNLLF6_S1();
	//
	////NPK52
	//MaterialSellmeier1 getNPK52_S1();
	//
	////NPSK57
	//MaterialSellmeier1 getNPSK57_S1();
	//
	////NPSK58
	//MaterialSellmeier1 getNPSK58_S1();
	//
	////NSK18
	//MaterialSellmeier1 getNSK18_S1();
	//
	////PK1
	//MaterialSellmeier1 getPK1_S1();
	//
	////PK2
	//MaterialSellmeier1 getPK2_S1();
	//
	////PK3
	//MaterialSellmeier1 getPK3_S1();
	//
	////PK50
	//MaterialSellmeier1 getPK50_S1();
	//
	////PK51A
	//MaterialSellmeier1 getPK51A_S1();
	//
	////PSK2
	//MaterialSellmeier1 getPSK2_S1();
	//
	////PSK3
	//MaterialSellmeier1 getPSK3_S1();
	//
	////PSK50
	//MaterialSellmeier1 getPSK50_S1();
	//
	////PSK52
	//MaterialSellmeier1 getPSK52_S1();
	//
	////PSK53A
	//MaterialSellmeier1 getPSK53A_S1();
	//
	////PSK54
	//MaterialSellmeier1 getPSK54_S1();
	//
	////SF3
	//MaterialSellmeier1 getSF3_S1();
	//
	////SF8
	//MaterialSellmeier1 getSF8_S1();
	//
	////SF9
	//MaterialSellmeier1 getSF9_S1();
	//
	////SF12
	//MaterialSellmeier1 getSF12_S1();
	//
	////SF13
	//MaterialSellmeier1 getSF13_S1();
	//
	////SF16
	//MaterialSellmeier1 getSF16_S1();
	//
	////SF18
	//MaterialSellmeier1 getSF18_S1();
	//
	////SF19
	//MaterialSellmeier1 getSF19_S1();
	//
	////SF53
	//MaterialSellmeier1 getSF53_S1();
	//
	////SF54
	//MaterialSellmeier1 getSF54_S1();
	//
	////SF55
	//MaterialSellmeier1 getSF55_S1();
	//
	////SF57HT
	//MaterialSellmeier1 getSF57HT_S1();
	//
	////SF58
	//MaterialSellmeier1 getSF58_S1();
	//
	////SF59
	//MaterialSellmeier1 getSF59_S1();
	//
	////SF63
	//MaterialSellmeier1 getSF63_S1();
	//
	////SF64A
	//MaterialSellmeier1 getSF64A_S1();
	//
	////SFL4
	//MaterialSellmeier1 getSFL4_S1();
	//
	////SFL56
	//MaterialSellmeier1 getSFL56_S1();
	//
	////SK1
	//MaterialSellmeier1 getSK1_S1();
	//
	////SK2
	//MaterialSellmeier1 getSK2_S1();
	//
	////SK3
	//MaterialSellmeier1 getSK3_S1();
	//
	////SK4
	//MaterialSellmeier1 getSK4_S1();
	//
	////SK5
	//MaterialSellmeier1 getSK5_S1();
	//
	////SK6
	//MaterialSellmeier1 getSK6_S1();
	//
	////SK7
	//MaterialSellmeier1 getSK7_S1();
	//
	////SK8
	//MaterialSellmeier1 getSK8_S1();
	//
	////SK10
	//MaterialSellmeier1 getSK10_S1();
	//
	////SK11
	//MaterialSellmeier1 getSK11_S1();
	//
	////SK12
	//MaterialSellmeier1 getSK12_S1();
	//
	////SK13
	//MaterialSellmeier1 getSK13_S1();
	//
	////SK14
	//MaterialSellmeier1 getSK14_S1();
	//
	////SK15
	//MaterialSellmeier1 getSK15_S1();
	//
	////SK16
	//MaterialSellmeier1 getSK16_S1();
	//
	////SK18A
	//MaterialSellmeier1 getSK18A_S1();
	//
	////SK51
	//MaterialSellmeier1 getSK51_S1();
	//
	////SK55
	//MaterialSellmeier1 getSK55_S1();
	//
	////SSK1
	//MaterialSellmeier1 getSSK1_S1();
	//
	////SSK2
	//MaterialSellmeier1 getSSK2_S1();
	//
	////SSK3
	//MaterialSellmeier1 getSSK3_S1();
	//
	////SSK4A
	//MaterialSellmeier1 getSSK4A_S1();
	//
	////SSK50
	//MaterialSellmeier1 getSSK50_S1();
	//
	////SSK51
	//MaterialSellmeier1 getSSK51_S1();
	//
	////SSKN5
	//MaterialSellmeier1 getSSKN5_S1();
	//
	////SSKN8
	//MaterialSellmeier1 getSSKN8_S1();
	//
	////TIF3
	//MaterialSellmeier1 getTIF3_S1();
	//
	////TIF6
	//MaterialSellmeier1 getTIF6_S1();
	//
	////TIFN5
	//MaterialSellmeier1 getTIFN5_S1();
	//
	////UBK7
	//MaterialSellmeier1 getUBK7_S1();
	//
	////UK50
	//MaterialSellmeier1 getUK50_S1();
	//
	////ULTRAN20
	//MaterialSellmeier1 getULTRAN20_S1();
	//
	////ULTRAN30
	//MaterialSellmeier1 getULTRAN30_S1();
	//
	////ZK1
	//MaterialSellmeier1 getZK1_S1();
	//
	////ZKN7
	//MaterialSellmeier1 getZKN7_S1();
	//
	//
private:
	
	// Air
	MaterialSellmeier1 Air;
	
	// F2 
	MaterialSellmeier1 F2_S1;
	
	// F5
	MaterialSellmeier1 F5_S1;
	
	// K10
	MaterialSellmeier1 K10_S1;
	
	// K7
	MaterialSellmeier1 K7_S1;
	
	//LAFN7
	MaterialSellmeier1 LAFN7_S1;
	
	//LF5
	MaterialSellmeier1 LF5_S1;
	
	//LLF1
	MaterialSellmeier1 LLF1_S1;
	
	//NBAF10
	MaterialSellmeier1 NBAF10_S1;
	
	//NBAF4
	MaterialSellmeier1 NBAF4_S1;
	
	//NBAF51
	MaterialSellmeier1 NBAF51_S1;
	
	//NBAF52
	MaterialSellmeier1 NBAF52_S1;
	
	//NBAK1
	MaterialSellmeier1 NBAK1_S1;
	
	//NBAK2
	MaterialSellmeier1 NBAK2_S1;
	
	//NBAK4
	MaterialSellmeier1 NBAK4_S1;
	
	//NBAK4HT
	MaterialSellmeier1 NBAK4HT_S1;
	
	//NBALF4
	MaterialSellmeier1 NBALF4_S1;
	
	//NBALF5
	MaterialSellmeier1 NBALF5_S1;
	
	//NBASF2
	MaterialSellmeier1 NBASF2_S1;
	
	//NBASF64
	MaterialSellmeier1 NBASF64_S1;
	
	//NBK10
	MaterialSellmeier1 NBK10_S1;
	
	//NBK7
	MaterialSellmeier1 NBK7_S1;
	
	//NBK7HT
	MaterialSellmeier1 NBK7HT_S1;
	
	//NF2
	MaterialSellmeier1 NF2_S1;
	
	//NFK5
	MaterialSellmeier1 NFK5_S1;
	
	//NFK51A
	MaterialSellmeier1 NFK51A_S1;
	
	//NK5
	MaterialSellmeier1 NK5_S1;
	
	//NKF9
	MaterialSellmeier1 NKF9_S1;
	
	//NKZFS11
	MaterialSellmeier1 NKZFS11_S1;
	
	//NKZFS2
	MaterialSellmeier1 NKZFS2_S1;
	
	//NKZFS4
	MaterialSellmeier1 NKZFS4_S1;
	
	//NKZFS4HT
	MaterialSellmeier1 NKZFS4HT_S1;
	
	//NKZFS5
	MaterialSellmeier1 NKZFS5_S1;
	
	//NKZFS8
	MaterialSellmeier1 NKZFS8_S1;
	
	//NLAF2
	MaterialSellmeier1 NLAF2_S1;
	
	//NLAF21
	MaterialSellmeier1 NLAF21_S1;
	
	//NLAF33
	MaterialSellmeier1 NLAF33_S1;
	
	//NLAF34
	MaterialSellmeier1 NLAF34_S1;
	
	//NLAF35
	MaterialSellmeier1 NLAF35_S1;
	
	//NLAF7
	MaterialSellmeier1 NLAF7_S1;
	
	//NLAK10
	MaterialSellmeier1 NLAK10_S1;
	
	//NLAK12
	MaterialSellmeier1 NLAK12_S1;
	
	//NLAK14
	MaterialSellmeier1 NLAK14_S1;
	
	//NLAK21
	MaterialSellmeier1 NLAK21_S1;
	
	//NLAK22
	MaterialSellmeier1 NLAK22_S1;
	
	//NLAK33A
	MaterialSellmeier1 NLAK33A_S1;
	
	//NLAK33B
	MaterialSellmeier1 NLAK33B_S1;
	
	//NLAK34
	MaterialSellmeier1 NLAK34_S1;
	
	//NLAK7
	MaterialSellmeier1 NLAK7_S1;
	
	//NLAK8
	MaterialSellmeier1 NLAK8_S1;
	
	//NLAK9
	MaterialSellmeier1 NLAK9_S1;
	
	//NLASF31A
	MaterialSellmeier1 NLASF31A_S1;
	
	//NLASF40
	MaterialSellmeier1 NLASF40_S1;
	
	//NLASF41
	MaterialSellmeier1 NLASF41_S1;
	
	//NLASF43
	MaterialSellmeier1 NLASF43_S1;
	
	//NLASF44
	MaterialSellmeier1 NLASF44_S1;
	
	//NLASF45
	MaterialSellmeier1 NLASF45_S1;
	
	//NLASF45HT
	MaterialSellmeier1 NLASF45HT_S1;
	
	//NLASF46A
	MaterialSellmeier1 NLASF46A_S1;
	
	//NLASF46B
	MaterialSellmeier1 NLASF46B_S1;
	
	//NLASF9
	MaterialSellmeier1 NLASF9_S1;
	
	//NLASF9HT
	MaterialSellmeier1 NLASF9HT_S1;
	
	//NPK51
	MaterialSellmeier1 NPK51_S1;
	
	//NPK52A
	MaterialSellmeier1 NPK52A_S1;
	
	//NPSK3
	MaterialSellmeier1 NPSK3_S1;
	
	//NPSK53A
	MaterialSellmeier1 NPSK53A_S1;
	
	//NSF1
	MaterialSellmeier1 NSF1_S1;
	
	//NSF10
	MaterialSellmeier1 NSF10_S1;
	
	//NSF11
	MaterialSellmeier1 NSF11_S1;
	
	//NSF14
	MaterialSellmeier1 NSF14_S1;
	
	//NSF15
	MaterialSellmeier1 NSF15_S1;
	
	//NSF2
	MaterialSellmeier1 NSF2_S1;
	
	//NSF4
	MaterialSellmeier1 NSF4_S1;
	
	//NSF5
	MaterialSellmeier1 NSF5_S1;
	
	//NSF57
	MaterialSellmeier1 NSF57_S1;
	
	//NSF57HT
	MaterialSellmeier1 NSF57HT_S1;
	
	//NSF57HTULTRA
	MaterialSellmeier1 NSF57HTULTRA_S1;
	
	//NSF6
	MaterialSellmeier1 NSF6_S1;
	
	//NSF66
	MaterialSellmeier1 NSF66_S1;
	
	//NSF6HT
	MaterialSellmeier1 NSF6HT_S1;
	
	//NSF6HTULTRA
	MaterialSellmeier1 NSF6HTULTRA_S1;
	
	//NSF8
	MaterialSellmeier1 NSF8_S1;
	
	//NSK11
	MaterialSellmeier1 NSK11_S1;
	
	//NSK14
	MaterialSellmeier1 NSK14_S1;
	
	//NSK16
	MaterialSellmeier1 NSK16_S1;
	
	//NSK2
	MaterialSellmeier1 NSK2_S1;
	
	//NSK2HT
	MaterialSellmeier1 NSK2HT_S1;
	
	//NSK4
	MaterialSellmeier1 NSK4_S1;
	
	//NSK5
	MaterialSellmeier1 NSK5_S1;
	
	//NSSK2
	MaterialSellmeier1 NSSK2_S1;
	
	//NSSK5
	MaterialSellmeier1 NSSK5_S1;
	
	//NSSK8
	MaterialSellmeier1 NSSK8_S1;
	
	//NZK7
	MaterialSellmeier1 NZK7_S1;
	
	//PLAF37
	MaterialSellmeier1 PLAF37_S1;
	
	//PLAK35
	MaterialSellmeier1 PLAK35_S1;
	
	//PLASF47
	MaterialSellmeier1 PLASF47_S1;
	
	//PLASF50
	MaterialSellmeier1 PLASF50_S1;
	
	//PLASF51
	MaterialSellmeier1 PLASF51_S1;
	
	//PSF67
	MaterialSellmeier1 PSF67_S1;
	
	//PSF68
	MaterialSellmeier1 PSF68_S1;
	
	//PSF69
	MaterialSellmeier1 PSF69_S1;
	
	//PSF8
	MaterialSellmeier1 PSF8_S1;
	
	//PSK57
	MaterialSellmeier1 PSK57_S1;
	
	//PSK58A
	MaterialSellmeier1 PSK58A_S1;
	
	//PSK60
	MaterialSellmeier1 PSK60_S1;
	
	//SF1
	MaterialSellmeier1 SF1_S1;
	
	//SF10
	MaterialSellmeier1 SF10_S1;
	
	//SF2
	MaterialSellmeier1 SF2_S1;
	
	//SF4
	MaterialSellmeier1 SF4_S1;
	
	//SF5
	MaterialSellmeier1 SF5_S1;
	
	//SF56A
	MaterialSellmeier1 SF56A_S1;
	
	//SF57 
	MaterialSellmeier1 SF57_S1;
	
	//SF6
	MaterialSellmeier1 SF6_S1;
	
	//SF6HT
	MaterialSellmeier1 SF6HT_S1;
	
	//SF57HTULTRA
	MaterialSellmeier1 SF57HTULTRA_S1;
	
	//PBK7
	MaterialSellmeier1 PBK7_S1;
	
	//PSK57Q1
	MaterialSellmeier1 PSK57Q1_S1;
	
	//SF11
	MaterialSellmeier1 SF11_S1;
	
	//LASF35
	MaterialSellmeier1 LASF35_S1;
	
	//FK3
	MaterialSellmeier1 FK3_S1;
	
	//NSK10
	MaterialSellmeier1 NSK10_S1;
	
	//NSK15
	MaterialSellmeier1 NSK15_S1;
	
	//NBAF3
	MaterialSellmeier1 NBAF3_S1;
	
	//BAFN6
	MaterialSellmeier1 BAFN6_S1;
	
	//NLAF3
	MaterialSellmeier1 NLAF3_S1;
	
	//SFL57
	MaterialSellmeier1 SFL57_S1;
	
	//SFL6
	MaterialSellmeier1 SFL6_S1;
	
	//NSF19
	MaterialSellmeier1 NSF19_S1;
	
	//NSF56
	MaterialSellmeier1 NSF56_S1;
	
	//NSF64
	MaterialSellmeier1 NSF64_S1;
	
	//NPSK53
	MaterialSellmeier1 NPSK53_S1;
	
	//BK7G18
	MaterialSellmeier1 BK7G18_S1;
	
	//LF5G19
	MaterialSellmeier1 LF5G19_S1;
	
	//LF5G15
	MaterialSellmeier1 LF5G15_S1;
	
	//K5G20
	MaterialSellmeier1 K5G20_S1;
	
	//LAK9G15
	MaterialSellmeier1 LAK9G15_S1;
	
	//F2G12
	MaterialSellmeier1 F2G12_S1;
	
	//SF6G05
	MaterialSellmeier1 SF6G05_S1;
	
	//LASFN9
	MaterialSellmeier1 LASFN9_S1;
	
	//LAKL12
	MaterialSellmeier1 LAKL12_S1;
	
	//NLASF46
	MaterialSellmeier1 NLASF46_S1;
	
	//NLASF31
	MaterialSellmeier1 NLASF31_S1;
	
	//NFK51
	MaterialSellmeier1 NFK51_S1;
	
	//NLAF32
	MaterialSellmeier1 NLAF32_S1;
	
	//KZFSN4
	MaterialSellmeier1 KZFSN4_S1;
	
	//SF14
	MaterialSellmeier1 SF14_S1;
	
	//SF15
	MaterialSellmeier1 SF15_S1;
	
	//SF66
	MaterialSellmeier1 SF66_S1;
	
	//LITHOTECCAF2
	MaterialSellmeier1 LITHOTECCAF2_S1;
	
	//LITHOSILQ
	MaterialSellmeier1 LITHOSILQ_S1;
	
	////D263TECO
	//MaterialSellmeier1 D263TECO_S1;
	//
	////AF32ECO
	//MaterialSellmeier1 AF32ECO_S1;
	
	//KZFS12
	MaterialSellmeier1 KZFS12_S1;
	
	//PPK53
	MaterialSellmeier1 PPK53_S1;
	
	//NLAF36
	MaterialSellmeier1 NLAF36_S1;
	
	//FK5HTI
	MaterialSellmeier1 FK5HTI_S1;
	
	//LF5HTI
	MaterialSellmeier1 LF5HTI_S1;
	
	//LLF1HTI
	MaterialSellmeier1 LLF1HTI_S1;
	
	//NBK7HTI
	MaterialSellmeier1 NBK7HTI_S1;
	
	//NFK58
	MaterialSellmeier1 NFK58_S1;
	
	////BAF3
	//MaterialSellmeier1 BAF3_S1;
	//
	////BAF4
	//MaterialSellmeier1 BAF4_S1;
	//
	////BAF8
	//MaterialSellmeier1 BAF8_S1;
	//
	////BAF9
	//MaterialSellmeier1 BAF9_S1;
	//
	////BAF13
	//MaterialSellmeier1 BAF13_S1;
	//
	////BAF50
	//MaterialSellmeier1 BAF50_S1;
	//
	////BAF51
	//MaterialSellmeier1 BAF51_S1;
	//
	////BAF52
	//MaterialSellmeier1 BAF52_S1;
	//
	//BAFN10
	MaterialSellmeier1 BAFN10_S1;
	//
	////BAFN11
	//MaterialSellmeier1 BAFN11_S1;
	//
	////BAK1
	//MaterialSellmeier1 BAK1_S1;
	//
	////BAK2
	//MaterialSellmeier1 BAK2_S1;
	//
	////BAK4
	//MaterialSellmeier1 BAK4_S1;
	//
	////BAK5
	//MaterialSellmeier1 BAK5_S1;
	//
	////BAK50
	//MaterialSellmeier1 BAK50_S1;
	//
	////BALF4
	//MaterialSellmeier1 BALF4_S1;
	//
	////BALF5
	//MaterialSellmeier1 BALF5_S1;
	//
	////BALF50
	//MaterialSellmeier1 BALF50_S1;
	//
	////BALKN3
	//MaterialSellmeier1 BALKN3_S1;
	//
	////BASF1
	//MaterialSellmeier1 BASF1_S1;
	//
	////BASF2
	//MaterialSellmeier1 BASF2_S1;
	//
	////BASF6
	//MaterialSellmeier1 BASF6_S1;
	//
	////BASF10
	//MaterialSellmeier1 BASF10_S1;
	//
	////BASF12
	//MaterialSellmeier1 BASF12_S1;
	//
	////BASF13
	//MaterialSellmeier1 BASF13_S1;
	//
	////BASF51
	//MaterialSellmeier1 BASF51_S1;
	//
	////BASF52
	//MaterialSellmeier1 BASF52_S1;
	//
	////BASF54
	//MaterialSellmeier1 BASF54_S1;
	//
	////BASF56
	//MaterialSellmeier1 BASF56_S1;
	//
	////BASF57
	//MaterialSellmeier1 BASF57_S1;
	//
	////BASF64A
	//MaterialSellmeier1 BASF64A_S1;
	//
	////BK1
	//MaterialSellmeier1 BK1_S1;
	//
	////BK3
	//MaterialSellmeier1 BK3_S1;
	//
	////BK6
	//MaterialSellmeier1 BK6_S1;
	//
	////BK7
	//MaterialSellmeier1 BK7_S1;
	//
	////BK7HT
	//MaterialSellmeier1 BK7HT_S1;
	//
	////BK8
	//MaterialSellmeier1 BK8_S1;
	//
	////BK10
	//MaterialSellmeier1 BK10_S1;
	//
	////F1
	//MaterialSellmeier1 F1_S1;
	//
	////F3
	//MaterialSellmeier1 F3_S1;
	//
	////F4
	//MaterialSellmeier1 F4_S1;
	//
	////F6
	//MaterialSellmeier1 F6_S1;
	//
	////F7
	//MaterialSellmeier1 F7_S1;
	//
	////F8
	//MaterialSellmeier1 F8_S1;
	//
	////F8HT
	//MaterialSellmeier1 F8HT_S1;
	//
	////F9
	//MaterialSellmeier1 F9_S1;
	//
	////F13
	//MaterialSellmeier1 F13_S1;
	//
	////F14
	//MaterialSellmeier1 F14_S1;
	//
	////F14_HT
	//MaterialSellmeier1 F14HT_S1;
	//
	////F15
	//MaterialSellmeier1 F15_S1;
	//
	////FK5
	//MaterialSellmeier1 FK5_S1;
	//
	////FK51
	//MaterialSellmeier1 FK51_S1;
	//
	////FK52
	//MaterialSellmeier1 FK52_S1;
	//
	////FK54
	//MaterialSellmeier1 FK54_S1;
	//
	////FN11
	//MaterialSellmeier1 FN11_S1;
	//
	////K3
	//MaterialSellmeier1 K3_S1;
	//
	////K4
	//MaterialSellmeier1 K4_S1;
	//
	////K5
	//MaterialSellmeier1 K5_S1;
	//
	////K5HT
	//MaterialSellmeier1 K5HT_S1;
	//
	////K7HT
	//MaterialSellmeier1 K7HT_S1;
	//
	////K11
	//MaterialSellmeier1 K11_S1;
	//
	////K50
	//MaterialSellmeier1 K50_S1;
	//
	////KF3
	//MaterialSellmeier1 KF3_S1;
	//
	////KF6
	//MaterialSellmeier1 KF6_S1;
	//
	////KF9
	//MaterialSellmeier1 KF9_S1;
	//
	////KZFN1
	//MaterialSellmeier1 KZFN1_S1;
	//
	////KZFN2
	//MaterialSellmeier1 KZFN2_S1;
	//
	////KZFS1
	//MaterialSellmeier1 KZFS1_S1;
	//
	////KZFS6
	//MaterialSellmeier1 KZFS6_S1;
	//
	////KZFS7A
	//MaterialSellmeier1 KZFS7A_S1;
	//
	////KZFS8
	//MaterialSellmeier1 KZFS8_S1;
	//
	////KZFSN2
	//MaterialSellmeier1 KZFSN2_S1;
	//
	////KZFSN9
	//MaterialSellmeier1 KZFSN9_S1;
	//
	////LAF2
	//MaterialSellmeier1 LAF2_S1;
	//
	////LAF3
	//MaterialSellmeier1 LAF3_S1;
	//
	////LAF9
	//MaterialSellmeier1 LAF9_S1;
	//
	////LAF11A
	//MaterialSellmeier1 LAF11A_S1;
	//
	////LAF13
	//MaterialSellmeier1 LAF13_S1;
	//
	////LAF20
	//MaterialSellmeier1 LAF20_S1;
	//
	////LAF22A
	//MaterialSellmeier1 LAF22A_S1;
	//
	////LAFN8
	//MaterialSellmeier1 LAFN8_S1;
	//
	////LAFN10
	//MaterialSellmeier1 LAFN10_S1;
	//
	////LAFN21
	//MaterialSellmeier1 LAFN21_S1;
	//
	////LAFN23
	//MaterialSellmeier1 LAFN23_S1;
	//
	////LAFN24
	//MaterialSellmeier1 LAFN24_S1;
	//
	////LAFN28
	//MaterialSellmeier1 LAFN28_S1;
	//
	////LAK8
	//MaterialSellmeier1 LAK8_S1;
	//
	////LAK9
	//MaterialSellmeier1 LAK9_S1;
	//
	////LAK10
	//MaterialSellmeier1 LAK10_S1;
	//
	////LAK11
	//MaterialSellmeier1 LAK11_S1;
	//
	////LAK16A
	//MaterialSellmeier1 LAK16A_S1;
	//
	////LAK21
	//MaterialSellmeier1 LAK21_S1;
	//
	////LAK23
	//MaterialSellmeier1 LAK23_S1;
	//
	////LAK28
	//MaterialSellmeier1 LAK28_S1;
	//
	////LAK31
	//MaterialSellmeier1 LAK31_S1;
	//
	////LAK33
	//MaterialSellmeier1 LAK33_S1;
	//
	////LAKL21
	//MaterialSellmeier1 LAKL21_S1;
	//
	////LAKN6
	//MaterialSellmeier1 LAKN6_S1;
	//
	////LAKN7
	//MaterialSellmeier1 LAKN7_S1;
	//
	////LAKN12
	//MaterialSellmeier1 LAKN12_S1;
	//
	////LAKN13
	//MaterialSellmeier1 LAKN13_S1;
	//
	////LAKN14
	//MaterialSellmeier1 LAKN14_S1;
	//
	////LAKN22
	//MaterialSellmeier1 LAKN22_S1;
	//
	////LASF3
	//MaterialSellmeier1 LASF3_S1;
	//
	////LASF14A
	//MaterialSellmeier1 LASF14A_S1;
	//
	////LASF18A
	//MaterialSellmeier1 LASF18A_S1;
	//
	////LASF32
	//MaterialSellmeier1 LASF32_S1;
	//
	////LASF33
	//MaterialSellmeier1 LASF33_S1;
	//
	////LASF36A
	//MaterialSellmeier1 LASF36A_S1;
	//
	////LASFN15
	//MaterialSellmeier1 LASFN15_S1;
	//
	////LASFN30
	//MaterialSellmeier1 LASFN30_S1;
	//
	////LASFN31
	//MaterialSellmeier1 LASFN31_S1;
	//
	////LF5HT
	//MaterialSellmeier1 LF5HT_S1;
	//
	////LF6HT
	//MaterialSellmeier1 LF6HT_S1;
	//
	////LF7
	//MaterialSellmeier1 LF7_S1;
	//
	////LF8
	//MaterialSellmeier1 LF8_S1;
	//
	////LLF1HT
	//MaterialSellmeier1 LLF1HT_S1;
	//
	////LLF2
	//MaterialSellmeier1 LLF2_S1;
	//
	////LLF6
	//MaterialSellmeier1 LLF6_S1;
	//
	////LLF6HT
	//MaterialSellmeier1 LLF6HT_S1;
	//
	////LLF7
	//MaterialSellmeier1 LLF7_S1;
	//
	////NFK56
	//MaterialSellmeier1 NFK56_S1;
	//
	////NLAK33
	//MaterialSellmeier1 NLAK33_S1;
	//
	////NLF5
	//MaterialSellmeier1 NLF5_S1;
	//
	////NLLF1
	//MaterialSellmeier1 NLLF1_S1;
	//
	////NLLF6
	//MaterialSellmeier1 NLLF6_S1;
	//
	////NPK52
	//MaterialSellmeier1 NPK52_S1;
	//
	////NPSK57
	//MaterialSellmeier1 NPSK57_S1;
	//
	////NPSK58
	//MaterialSellmeier1 NPSK58_S1;
	//
	////NSK18
	//MaterialSellmeier1 NSK18_S1;
	//
	////PK1
	//MaterialSellmeier1 PK1_S1;
	//
	////PK2
	//MaterialSellmeier1 PK2_S1;
	//
	////PK3
	//MaterialSellmeier1 PK3_S1;
	//
	////PK50
	//MaterialSellmeier1 PK50_S1;
	//
	////PK51A
	//MaterialSellmeier1 PK51A_S1;
	//
	////PSK2
	//MaterialSellmeier1 PSK2_S1;
	//
	////PSK3
	//MaterialSellmeier1 PSK3_S1;
	//
	////PSK50
	//MaterialSellmeier1 PSK50_S1;
	//
	////PSK52
	//MaterialSellmeier1 PSK52_S1;
	//
	////PSK53A
	//MaterialSellmeier1 PSK53A_S1;
	//
	////PSK54
	//MaterialSellmeier1 PSK54_S1;
	//
	////SF3
	//MaterialSellmeier1 SF3_S1;
	//
	////SF8
	//MaterialSellmeier1 SF8_S1;
	//
	////SF9
	//MaterialSellmeier1 SF9_S1;
	//
	////SF12
	//MaterialSellmeier1 SF12_S1;
	//
	////SF13
	//MaterialSellmeier1 SF13_S1;
	//
	////SF16
	//MaterialSellmeier1 SF16_S1;
	//
	////SF18
	//MaterialSellmeier1 SF18_S1;
	//
	////SF19
	//MaterialSellmeier1 SF19_S1;
	//
	////SF53
	//MaterialSellmeier1 SF53_S1;
	//
	////SF54
	//MaterialSellmeier1 SF54_S1;
	//
	////SF55
	//MaterialSellmeier1 SF55_S1;
	//
	////SF57HT
	//MaterialSellmeier1 SF57HT_S1;
	//
	////SF58
	//MaterialSellmeier1 SF58_S1;
	//
	////SF59
	//MaterialSellmeier1 SF59_S1;
	//
	////SF63
	//MaterialSellmeier1 SF63_S1;
	//
	////SF64A
	//MaterialSellmeier1 SF64A_S1;
	//
	////SFL4
	//MaterialSellmeier1 SFL4_S1;
	//
	////SFL56
	//MaterialSellmeier1 SFL56_S1;
	//
	////SK1
	//MaterialSellmeier1 SK1_S1;
	//
	////SK2
	//MaterialSellmeier1 SK2_S1;
	//
	////SK3
	//MaterialSellmeier1 SK3_S1;
	//
	////SK4
	//MaterialSellmeier1 SK4_S1;
	//
	////SK5
	//MaterialSellmeier1 SK5_S1;
	//
	////SK6
	//MaterialSellmeier1 SK6_S1;
	//
	////SK7
	//MaterialSellmeier1 SK7_S1;
	//
	////SK8
	//MaterialSellmeier1 SK8_S1;
	//
	////SK10
	//MaterialSellmeier1 SK10_S1;
	//
	////SK11
	//MaterialSellmeier1 SK11_S1;
	//
	////SK12
	//MaterialSellmeier1 SK12_S1;
	//
	////SK13
	//MaterialSellmeier1 SK13_S1;
	//
	////SK14
	//MaterialSellmeier1 SK14_S1;
	//
	////SK15
	//MaterialSellmeier1 SK15_S1;
	//
	////SK16
	//MaterialSellmeier1 SK16_S1;
	//
	////SK18A
	//MaterialSellmeier1 SK18A_S1;
	//
	////SK51
	//MaterialSellmeier1 SK51_S1;
	//
	////SK55
	//MaterialSellmeier1 SK55_S1;
	//
	////SSK1
	//MaterialSellmeier1 SSK1_S1;
	//
	////SSK2
	//MaterialSellmeier1 SSK2_S1;
	//
	////SSK3
	//MaterialSellmeier1 SSK3_S1;
	//
	////SSK4A
	//MaterialSellmeier1 SSK4A_S1;
	//
	////SSK50
	//MaterialSellmeier1 SSK50_S1;
	//
	////SSK51
	//MaterialSellmeier1 SSK51_S1;
	//
	////SSKN5
	//MaterialSellmeier1 SSKN5_S1;
	//
	////SSKN8
	//MaterialSellmeier1 SSKN8_S1;
	//
	////TIF3
	//MaterialSellmeier1 TIF3_S1;
	//
	////TIF6
	//MaterialSellmeier1 TIF6_S1;
	//
	////TIFN5
	//MaterialSellmeier1 TIFN5_S1;
	//
	////UBK7
	//MaterialSellmeier1 UBK7_S1;
	//
	////UK50
	//MaterialSellmeier1 UK50_S1;
	//
	////ULTRAN20
	//MaterialSellmeier1 ULTRAN20_S1;
	//
	////ULTRAN30
	//MaterialSellmeier1 ULTRAN30_S1;
	//
	////ZK1
	//MaterialSellmeier1 ZK1_S1;
	//
	////ZKN7
	//MaterialSellmeier1 ZKN7_S1;

};





