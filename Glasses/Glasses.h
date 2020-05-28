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
	
	//NFK58
	MaterialSellmeier1 getBAFN10_S1();

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
	
	//BAFN10
	MaterialSellmeier1 BAFN10_S1;
	
};





