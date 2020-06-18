#include "Glasses.h"

glass::glass() {};
glass::~glass() {};

void glass::loadGlassCatalog_Schott()
{
	Air.setParameterAndCalcVd_Ve("Schott", "Air", 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0); // refractive index is 1
	F2_S1.setParameterAndCalcVd_Ve("Schott", "F2", 1.34533, 0.00997744, 0.209073, 0.0470451, 0.937357, 111.887, 1.51e-06, 1.56e-08, -2.78e-11, 9.34e-07, 1.04e-09, 0.25, 0.32, 2.5, 1, 1, 2.3, 0);
	F5_S1.setParameterAndCalcVd_Ve("Schott", "F5", 1.31045, 0.00958633, 0.196034, 0.0457628, 0.96613, 115.012, 2.13e-06, 1.65e-08, -6.98e-11, 1.02e-06, 6.56e-10, 0.208, 0.32, 2.5, 1, 1, 2.3, 0);
	K10_S1.setParameterAndCalcVd_Ve("Schott", "K10", 1.15687, 0.00809424, 0.0642625, 0.0386051, 0.872376, 104.748, 4.86e-06, 1.72e-08, -3.02e-11, 3.82e-07, 4.53e-10, 0.26, 0.3, 2.5, 1, 1, 1, 0);
	K7_S1.setParameterAndCalcVd_Ve("Schott", "K7", 1.12736, 0.00720342, 0.124412, 0.0269836, 0.827101, 100.385, -1.67e-06, 8.8e-09, -2.86e-11, 5.42e-07, 7.81e-10, 0.172, 0.31, 2.5, 3, 2, 1, 0);
	LAFN7_S1.setParameterAndCalcVd_Ve("Schott", "LAFN7", 1.66843, 0.010316, 0.298513, 0.0469216, 1.07744, 82.5079, 7.27e-06, 1.31e-08, -3.32e-11, 8.88e-07, 9.32e-10, 0.248, 0.35, 2.5, 3, 53.3, 2.2, 1);
	LF5_S1.setParameterAndCalcVd_Ve("Schott", "LF5", 1.28036, 0.00929854, 0.163506, 0.0449136, 0.89393, 110.494, -2.27e-06, 9.71e-09, -2.83e-11, 8.36e-07, 9.95e-10, 0.228, 0.32, 2.325, 2, 1, 2.3, 0);
	LLF1_S1.setParameterAndCalcVd_Ve("Schott", "LLF1", 1.2164, 0.00857807, 0.133665, 0.0420143, 0.883399, 107.593, 3.25e-07, 1.74e-08, -6.12e-11, 6.53e-07, 2.58e-10, 0.233, 0.31, 2.5, 1, 1, 2, 0);
	NBAF10_S1.setParameterAndCalcVd_Ve("Schott", "N-BAF10", 1.58515, 0.00926681, 0.143559, 0.042449, 1.08521, 105.614, 3.79e-06, 1.28e-08, -1.42e-11, 5.84e-07, 7.6e-10, 0.22, 0.35, 2.5, 1, 4.3, 1.3, 0);
	NBAF4_S1.setParameterAndCalcVd_Ve("Schott", "N-BAF4", 1.42056, 0.00942015, 0.102721, 0.0531087, 1.14381, 110.279, 9.39e-07, 1.24e-08, -9e-12, 6.17e-07, 8.42e-10, 0.242, 0.365, 2.5, 1, 1, 1.2, 0);
	NBAF51_S1.setParameterAndCalcVd_Ve("Schott", "N-BAF51", 1.51504, 0.00942735, 0.153622, 0.0430827, 1.15428, 124.89, -2.84e-07, 1.04e-08, -1.8e-11, 7.01e-07, 8.47e-10, 0.219, 0.35, 2.5, 2, 5.4, 1.3, 0);
	NBAF52_S1.setParameterAndCalcVd_Ve("Schott", "N-BAF52", 1.43903, 0.009078, 0.0967046, 0.0508212, 1.09876, 105.692, 1.15e-06, 1.27e-08, -5.08e-12, 5.64e-07, 6.38e-10, 0.238, 0.365, 2.5, 1, 1, 1.3, 0);
	NBAK1_S1.setParameterAndCalcVd_Ve("Schott", "N-BAK1", 1.12366, 0.00644743, 0.309277, 0.0222284, 0.881512, 107.298, 1.86e-07, 1.29e-08, -1.87e-11, 5.25e-07, 5.46e-10, 0.182, 0.3, 2.5, 2, 3.3, 1.2, 1);
	NBAK2_S1.setParameterAndCalcVd_Ve("Schott", "N-BAK2", 1.01662, 0.00592384, 0.319903, 0.0203828, 0.937233, 113.118, -1.45e-06, 1.1e-08, 4.89e-12, 5.16e-07, 3.05e-10, 0.164, 0.3, 2.5, 2, 1, 1, 0);
	NBAK4_S1.setParameterAndCalcVd_Ve("Schott", "N-BAK4", 1.28835, 0.00779981, 0.132818, 0.0315631, 0.945395, 105.966, 3.06e-06, 1.44e-08, -2.23e-11, 5.46e-07, 6.05e-10, 0.189, 0.334, 2.5, 1, 1.2, 1, 0);
	NBAK4HT_S1.setParameterAndCalcVd_Ve("Schott", "N-BAK4HT", 1.28835, 0.00779981, 0.132818, 0.0315631, 0.945395, 105.966, 3.06e-06, 1.44e-08, -2.23e-11, 5.46e-07, 6.05e-10, 0.189, 0.334, 2.5, 1, 1.2, 1, 0);
	NBALF4_S1.setParameterAndCalcVd_Ve("Schott", "N-BALF4", 1.31004, 0.00796596, 0.142038, 0.0330672, 0.964929, 109.197, 5.33e-06, 1.47e-08, -1.58e-11, 5.75e-07, 6.58e-10, 0.195, 0.35, 2.5, 1, 1, 1, 0);
	NBALF5_S1.setParameterAndCalcVd_Ve("Schott", "N-BALF5", 1.28386, 0.00825816, 0.0719301, 0.044192, 1.05049, 107.097, 1.14e-06, 1.29e-08, -1.46e-11, 5.02e-07, 5.87e-10, 0.219, 0.35, 2.5, 1, 1, 2, 0);
	NBASF2_S1.setParameterAndCalcVd_Ve("Schott", "N-BASF2", 1.53652, 0.0108436, 0.156971, 0.0562279, 1.30197, 131.34, 1.89e-06, 1.22e-08, -1.61e-11, 7.77e-07, 9.96e-10, 0.256, 0.37, 2.5, 1, 1, 1, 0);
	NBASF64_S1.setParameterAndCalcVd_Ve("Schott", "N-BASF64", 1.65554, 0.0104486, 0.17132, 0.0499395, 1.33664, 118.961, 1.6e-06, 1.02e-08, -2.68e-11, 7.87e-07, 9.65e-10, 0.229, 0.365, 2.5, 1, 3.2, 1.2, 0);
	NBK10_S1.setParameterAndCalcVd_Ve("Schott", "N-BK10", 0.888308, 0.00516901, 0.328964, 0.016119, 0.984611, 99.7575, 3.32e-06, 1.72e-08, -2.05e-11, 3.57e-07, 3.9e-10, 0.169, 0.29, 2.5, 1, 1, 1, 0);
	NBK7_S1.setParameterAndCalcVd_Ve("Schott", "N-BK7", 1.03961, 0.0060007, 0.231792, 0.0200179, 1.01047, 103.561, 1.86e-06, 1.31e-08, -1.37e-11, 4.34e-07, 6.27e-10, 0.17, 0.3, 2.5, 1, 1, 2.3, 0);
	NBK7HT_S1.setParameterAndCalcVd_Ve("Schott", "N-BK7HT", 1.03961, 0.0060007, 0.231792, 0.0200179, 1.01047, 103.561, 1.86e-06, 1.31e-08, -1.37e-11, 4.34e-07, 6.27e-10, 0.17, 0.3, 2.5, 1, 1, 2.3, 0);
	NF2_S1.setParameterAndCalcVd_Ve("Schott", "N-F2", 1.39757, 0.00995906, 0.159201, 0.0546932, 1.26865, 119.248, 4.62e-07, 1.17e-08, -2.35e-11, 7.47e-07, 9.81e-10, 0.263, 0.365, 2.5, 1, 1, 1, 0);
	NFK5_S1.setParameterAndCalcVd_Ve("Schott", "N-FK5", 0.844309, 0.00475112, 0.344148, 0.0149815, 0.91079, 97.86, -7.24e-06, 1.58e-08, -9.51e-12, 3.51e-07, 4.61e-10, 0.156, 0.26, 2.5, 2, 4, 2, 1);
	NFK51A_S1.setParameterAndCalcVd_Ve("Schott", "N-FK51A", 0.971248, 0.00472302, 0.216901, 0.0153576, 0.904652, 168.681, -1.83e-05, -7.89e-09, -1.63e-12, 3.74e-07, 3.46e-10, 0.15, 0.29, 2.5, 1, 52.3, 2.2, 0);
	NK5_S1.setParameterAndCalcVd_Ve("Schott", "N-K5", 1.08512, 0.006611, 0.199562, 0.0241109, 0.930512, 111.983, -4.13e-07, 1.03e-08, -3.4e-11, 4.73e-07, 5.19e-10, 0.213, 0.31, 2.5, 1, 1, 1, 0);
	NKF9_S1.setParameterAndCalcVd_Ve("Schott", "N-KF9", 1.19287, 0.00839155, 0.0893347, 0.0404011, 0.92082, 112.572, -1.66e-06, 8.44e-09, -1.01e-11, 6.1e-07, 6.96e-10, 0.217, 0.35, 2.5, 1, 1, 1, 0);
	NKZFS11_S1.setParameterAndCalcVd_Ve("Schott", "N-KZFS11", 1.33222, 0.00840298, 0.289242, 0.034424, 1.15162, 88.4311, 3.34e-06, 1.16e-08, -1.8e-11, 6.32e-07, 7.21e-10, 0.206, 0.31, 2.5, 1, 3.4, 1, 1);
	NKZFS2_S1.setParameterAndCalcVd_Ve("Schott", "N-KZFS2", 1.23698, 0.00747171, 0.153569, 0.0308054, 0.903976, 70.1731, 6.77e-06, 1.31e-08, -1.23e-11, 3.84e-07, 5.51e-10, 0.196, 0.31, 2.5, 1, 52.3, 4.3, 4);
	NKZFS4_S1.setParameterAndCalcVd_Ve("Schott", "N-KZFS4", 1.35055, 0.00876282, 0.197576, 0.0371767, 1.09963, 90.3867, 1.81e-06, 1.16e-08, -7.99e-12, 6.2e-07, 7.94e-10, 0.205, 0.334, 2.5, 1, 3.4, 1.2, 1);
	NKZFS4HT_S1.setParameterAndCalcVd_Ve("Schott", "N-KZFS4HT", 1.35055, 0.00876282, 0.197576, 0.0371767, 1.09963, 90.3867, 1.81e-06, 1.16e-08, -7.99e-12, 6.2e-07, 7.94e-10, 0.205, 0.32, 2.5, 1, 3.4, 1.2, 1);
	NKZFS5_S1.setParameterAndCalcVd_Ve("Schott", "N-KZFS5", 1.47461, 0.00986144, 0.193584, 0.0445478, 1.2659, 106.436, 4.54e-06, 1.19e-08, 2.93e-12, 6.89e-07, 8.6e-10, 0.23, 0.334, 2.5, 1, 1, 1, 0);
	NKZFS8_S1.setParameterAndCalcVd_Ve("Schott", "N-KZFS8", 1.62694, 0.0108809, 0.243699, 0.0494208, 1.62007, 131.009, 7.93e-07, 6.47e-09, -5e-12, 7.71e-07, 1.01e-09, 0.254, 0.334, 2.5, 1, 1, 1, 0);
	NLAF2_S1.setParameterAndCalcVd_Ve("Schott", "N-LAF2", 1.80984, 0.0101712, 0.157296, 0.0442432, 1.093, 100.688, -3.64e-06, 9.2e-09, -6e-12, 6.43e-07, 6.11e-10, 0.22, 0.35, 2.5, 2, 52.2, 1, 3);
	NLAF21_S1.setParameterAndCalcVd_Ve("Schott", "N-LAF21", 1.87135, 0.00933322, 0.250783, 0.0345638, 1.22049, 83.2405, 3.11e-06, 1.13e-08, -2.07e-11, 5.88e-07, 6.32e-10, 0.199, 0.334, 2.5, 1, 51.3, 1, 1);
	NLAF33_S1.setParameterAndCalcVd_Ve("Schott", "N-LAF33", 1.79653, 0.00927313, 0.311578, 0.0358201, 1.15982, 87.3449, 8.17e-06, 1.24e-08, -1.65e-11, 7.11e-07, 8.59e-10, 0.21, 0.32, 2.5, 1, 52.2, 1, 2);
	NLAF34_S1.setParameterAndCalcVd_Ve("Schott", "N-LAF34", 1.75837, 0.0087281, 0.313538, 0.0293021, 1.18925, 85.1781, 3.89e-06, 1.02e-08, -1.91e-11, 5.88e-07, 7.57e-10, 0.181, 0.31, 2.5, 1, 51.3, 1, 1);
	NLAF35_S1.setParameterAndCalcVd_Ve("Schott", "N-LAF35", 1.51697, 0.00750943, 0.455875, 0.0260047, 1.07469, 80.5945, 8.98e-06, 1.26e-08, -1.23e-11, 6.24e-07, 6.86e-10, 0.194, 0.31, 2.5, 2, 52.3, 1, 1);
	NLAF7_S1.setParameterAndCalcVd_Ve("Schott", "N-LAF7", 1.74029, 0.0107926, 0.226711, 0.0538627, 1.32526, 106.269, 9.21e-07, 1.1e-08, -1.75e-11, 7.67e-07, 1.1e-09, 0.264, 0.365, 2.5, 1, 51.3, 1.2, 2);
	NLAK10_S1.setParameterAndCalcVd_Ve("Schott", "N-LAK10", 1.72878, 0.00886015, 0.169258, 0.0363417, 1.19387, 82.9009, 4.1e-06, 1.23e-08, -7.85e-12, 5.08e-07, 5.76e-10, 0.205, 0.35, 2.5, 2, 52.3, 1, 2);
	NLAK12_S1.setParameterAndCalcVd_Ve("Schott", "N-LAK12", 1.17366, 0.00577032, 0.588992, 0.0200402, 0.978014, 95.4873, -5.67e-06, 8.27e-09, 1.27e-12, 5.25e-07, 6.3e-10, 0.162, 0.32, 2.5, 3, 53.3, 3.3, 1);
	NLAK14_S1.setParameterAndCalcVd_Ve("Schott", "N-LAK14", 1.50781, 0.00746099, 0.318867, 0.0242025, 1.14287, 80.9565, 2.68e-06, 1.15e-08, -1.44e-11, 3.72e-07, 5.53e-10, 0.226, 0.31, 2.5, 3, 52.3, 1, 2);
	NLAK21_S1.setParameterAndCalcVd_Ve("Schott", "N-LAK21", 1.22718, 0.00602076, 0.420784, 0.0196863, 1.01285, 88.437, -2.36e-06, 1.15e-08, 1.11e-11, 3.1e-07, 2.78e-10, 0.234, 0.32, 2.5, 4, 53.2, 4.3, 2);
	NLAK22_S1.setParameterAndCalcVd_Ve("Schott", "N-LAK22", 1.1423, 0.00585779, 0.535138, 0.0198546, 1.04088, 100.834, 1.36e-06, 1.49e-08, -1.29e-11, 3.41e-07, 2.09e-10, 0.262, 0.31, 2.5, 2, 51.2, 1, 2);
	NLAK33A_S1.setParameterAndCalcVd_Ve("Schott", "N-LAK33A", 1.44117, 0.00680934, 0.57175, 0.0222292, 1.16605, 80.938, 2.63e-06, 1.11e-08, -3.92e-12, 5.02e-07, 5.08e-10, 0.188, 0.32, 2.5, 1, 51, 1, 1);
	NLAK33B_S1.setParameterAndCalcVd_Ve("Schott", "N-LAK33B", 1.42289, 0.00670283, 0.593661, 0.0219416, 1.16135, 80.7408, 2.77e-06, 1.24e-08, 1.22e-11, 5.19e-07, 6.02e-10, 0.184, 0.3, 2.5, 1, 51.3, 1, 1);
	NLAK34_S1.setParameterAndCalcVd_Ve("Schott", "N-LAK34", 1.26661, 0.00589278, 0.665919, 0.0197509, 1.12496, 78.8894, 1.96e-06, 9.65e-09, 4.4e-12, 4.91e-07, 5.28e-10, 0.161, 0.29, 2.5, 1, 52.3, 1, 0);
	NLAK7_S1.setParameterAndCalcVd_Ve("Schott", "N-LAK7", 1.2368, 0.00610106, 0.445052, 0.0201388, 1.01746, 90.638, -3.4e-06, 1.17e-08, 2.38e-11, 4.96e-07, 4.44e-10, 0.107, 0.29, 2.5, 3, 53.3, 3.3, 2);
	NLAK8_S1.setParameterAndCalcVd_Ve("Schott", "N-LAK8", 1.33183, 0.00620024, 0.546623, 0.0216465, 1.19084, 82.5828, 4.1e-06, 1.25e-08, -1.6e-11, 4.3e-07, 6.29e-10, 0.213, 0.31, 2.5, 3, 52.3, 1, 2);
	NLAK9_S1.setParameterAndCalcVd_Ve("Schott", "N-LAK9", 1.46232, 0.0072427, 0.3444, 0.0243353, 1.15508, 85.4687, 2.11e-06, 1.11e-08, 1.82e-12, 4.74e-07, -3.47e-10, 0.146, 0.3, 2.5, 3, 52, 1.2, 3);
	NLASF31A_S1.setParameterAndCalcVd_Ve("Schott", "N-LASF31A", 1.96485, 0.0098206, 0.475231, 0.0344713, 1.4836, 110.74, 1.67e-06, 8.9e-09, -8.73e-12, 7.47e-07, 7.46e-10, 0.207, 0.25, 2.5, 1, 2.3, 1, 0);
	NLASF40_S1.setParameterAndCalcVd_Ve("Schott", "N-LASF40", 1.9855, 0.0109583, 0.274057, 0.0474552, 1.28946, 96.9085, 8.1e-06, 1.25e-08, -1.73e-11, 8.27e-07, 1.08e-09, 0.238, 0.365, 2.5, 1, 51.2, 1, 1);
	NLASF41_S1.setParameterAndCalcVd_Ve("Schott", "N-LASF41", 1.86348, 0.00910368, 0.413307, 0.0339247, 1.35785, 93.3581, 3.03e-06, 1.04e-08, -1.3e-11, 6.62e-07, 7.82e-10, 0.209, 0.334, 2.5, 1, 4, 1, 1);
	NLASF43_S1.setParameterAndCalcVd_Ve("Schott", "N-LASF43", 1.93503, 0.0104001, 0.236629, 0.0447505, 1.26291, 87.4376, 4.77e-06, 1.14e-08, -2.68e-12, 6.62e-07, 8.84e-10, 0.234, 0.35, 2.5, 1, 51.3, 1, 1);
	NLASF44_S1.setParameterAndCalcVd_Ve("Schott", "N-LASF44", 1.78897, 0.00872506, 0.386759, 0.0308085, 1.30506, 92.7744, 3.32e-06, 1.12e-08, -8.52e-12, 5.88e-07, 7.13e-10, 0.209, 0.334, 2.5, 1, 4, 1, 1);
	NLASF45_S1.setParameterAndCalcVd_Ve("Schott", "N-LASF45", 1.8714, 0.0112172, 0.267778, 0.0505135, 1.7303, 147.107, 2.78e-06, 8.73e-09, -2.65e-11, 8.24e-07, 1.15e-09, 0.255, 0.365, 2.5, 1, 3.2, 1, 0);
	NLASF45HT_S1.setParameterAndCalcVd_Ve("Schott", "N-LASF45HT", 1.8714, 0.0112172, 0.267778, 0.0505135, 1.7303, 147.107, 2.78e-06, 8.73e-09, -2.65e-11, 8.24e-07, 1.15e-09, 0.255, 0.365, 2.5, 1, 3.2, 1, 0);
	NLASF46A_S1.setParameterAndCalcVd_Ve("Schott", "N-LASF46A", 2.16702, 0.0123596, 0.319813, 0.056061, 1.66004, 107.048, 3.53e-06, 1.24e-08, -1.87e-11, 8.39e-07, 1.04e-09, 0.275, 0.37, 2.5, 1, 3, 1, 0);
	NLASF46B_S1.setParameterAndCalcVd_Ve("Schott", "N-LASF46B", 2.17989, 0.0125805, 0.306495, 0.0567191, 1.56882, 105.317, 5.98e-06, 1.3e-08, -3.5e-12, 9.13e-07, 1.24e-09, 0.267, 0.365, 2.5, 1, 3.3, 1, 0);
	NLASF9_S1.setParameterAndCalcVd_Ve("Schott", "N-LASF9", 2.0003, 0.0121426, 0.298927, 0.0538736, 1.80692, 156.531, 1.05e-06, 1.02e-08, -2.38e-11, 9.19e-07, 1.18e-09, 0.257, 0.365, 2.5, 1, 2, 1, 0);
	NLASF9HT_S1.setParameterAndCalcVd_Ve("Schott", "N-LASF9HT", 2.0003, 0.0121426, 0.298927, 0.0538736, 1.80692, 156.531, 1.05e-06, 1.02e-08, -2.38e-11, 9.19e-07, 1.18e-09, 0.257, 0.365, 2.5, 1, 2, 1, 0);
	NPK51_S1.setParameterAndCalcVd_Ve("Schott", "N-PK51", 1.15611, 0.00585597, 0.153229, 0.0194072, 0.785619, 140.537, -1.98e-05, -6.06e-09, 1.6e-11, 4.16e-07, 5.01e-10, 0.134, 0.3, 2.5, 1, 52.3, 3.3, 0);
	NPK52A_S1.setParameterAndCalcVd_Ve("Schott", "N-PK52A", 1.02961, 0.005168, 0.188051, 0.0166659, 0.736488, 138.964, -1.97e-05, -5.5e-09, 5.28e-12, 3.6e-07, 2.45e-10, 0.172, 0.29, 2.5, 1, 52.3, 3.3, 0);
	NPSK3_S1.setParameterAndCalcVd_Ve("Schott", "N-PSK3", 0.887272, 0.00469824, 0.489592, 0.0161818, 1.04865, 104.375, 2.03e-06, 1.19e-08, 2.46e-11, 3.14e-07, 2.45e-10, 0.235, 0.3, 2.5, 3, 2.2, 2, 0);
	NPSK53A_S1.setParameterAndCalcVd_Ve("Schott", "N-PSK53A", 1.38122, 0.00706416, 0.196746, 0.0233251, 0.886089, 97.4847, -9.28e-06, 7.19e-09, 1.45e-12, 4.06e-07, 3.17e-10, 0.19, 0.32, 2.5, 1, 53.3, 2.3, 1);
	NSF1_S1.setParameterAndCalcVd_Ve("Schott", "N-SF1", 1.60865, 0.0119655, 0.237726, 0.059059, 1.51531, 135.522, -3.72e-06, 8.05e-09, -1.71e-11, 8.98e-07, 1.34e-09, 0.276, 0.37, 2.5, 1, 1, 1, 0);
	NSF10_S1.setParameterAndCalcVd_Ve("Schott", "N-SF10", 1.62154, 0.0122241, 0.256288, 0.0595737, 1.64448, 147.469, -4.68e-06, 7.41e-09, -1.89e-11, 9.49e-07, 1.42e-09, 0.279, 0.38, 2.5, 1, 1, 1, 0);
	NSF11_S1.setParameterAndCalcVd_Ve("Schott", "N-SF11", 1.7376, 0.0131887, 0.313747, 0.0623068, 1.89878, 155.236, -3.56e-06, 9.2e-09, -2.1e-11, 9.65e-07, 1.44e-09, 0.294, 0.37, 2.5, 1, 1, 1, 0);
	NSF14_S1.setParameterAndCalcVd_Ve("Schott", "N-SF14", 1.69022, 0.0130512, 0.28887, 0.0613692, 1.70452, 149.518, -5.56e-06, 7.09e-09, -1.09e-11, 9.85e-07, 1.39e-09, 0.287, 0.365, 2.5, 1, 1, 1, 0);
	NSF15_S1.setParameterAndCalcVd_Ve("Schott", "N-SF15", 1.57056, 0.0116507, 0.218987, 0.0597857, 1.50824, 132.709, -7.15e-07, 1.04e-08, -2.62e-11, 8.56e-07, 1.29e-09, 0.281, 0.37, 2.5, 1, 1, 1, 0);
	NSF2_S1.setParameterAndCalcVd_Ve("Schott", "N-SF2", 1.47343, 0.0109019, 0.163682, 0.0585684, 1.36921, 127.405, 3.1e-06, 1.75e-08, 6.62e-11, 7.51e-07, 8.99e-10, 0.277, 0.365, 2.5, 1, 1, 1.2, 0);
	NSF4_S1.setParameterAndCalcVd_Ve("Schott", "N-SF4", 1.6778, 0.0126793, 0.28285, 0.0602038, 1.63539, 145.76, -4.88e-06, 6.57e-09, -2.72e-11, 9.67e-07, 1.48e-09, 0.282, 0.365, 2.5, 1, 1.3, 1, 0);
	NSF5_S1.setParameterAndCalcVd_Ve("Schott", "N-SF5", 1.52482, 0.0112548, 0.187086, 0.0588995, 1.42729, 129.142, -2.51e-07, 1.07e-08, -2.4e-11, 7.85e-07, 1.15e-09, 0.278, 0.37, 2.5, 1, 1, 1, 0);
	NSF57_S1.setParameterAndCalcVd_Ve("Schott", "N-SF57", 1.87544, 0.014175, 0.373757, 0.064051, 2.30002, 177.39, -4.51e-06, 8.73e-09, -1.64e-11, 1.07e-06, 1.57e-09, 0.295, 0.37, 2.5, 1, 1, 1, 0);
	NSF57HT_S1.setParameterAndCalcVd_Ve("Schott", "N-SF57HT", 1.87544, 0.014175, 0.373757, 0.064051, 2.30002, 177.39, -4.51e-06, 8.73e-09, -1.64e-11, 1.07e-06, 1.57e-09, 0.295, 0.37, 2.5, 1, 1, 1, 0);
	NSF57HTULTRA_S1.setParameterAndCalcVd_Ve("Schott", "N-SF57HTultra", 1.87544, 0.014175, 0.373757, 0.064051, 2.30002, 177.39, -4.51e-06, 8.73e-09, -1.64e-11, 1.07e-06, 1.57e-09, 0.295, 0.37, 2.5, 1, 1, 1, 0);
	NSF6_S1.setParameterAndCalcVd_Ve("Schott", "N-SF6", 1.77932, 0.0133714, 0.33815, 0.0617534, 2.08734, 174.018, -4.93e-06, 7.02e-09, -2.4e-11, 9.84e-07, 1.54e-09, 0.29, 0.37, 2.5, 1, 2, 1, 0);
	NSF66_S1.setParameterAndCalcVd_Ve("Schott", "N-SF66", 2.0246, 0.0147053, 0.470187, 0.0692998, 2.5997, 161.818, -4.3e-06, 1.15e-08, 4.31e-11, 9.62e-07, 1.62e-09, 0.322, 0.39, 2.5, 1, 1, 1, 0);
	NSF6HT_S1.setParameterAndCalcVd_Ve("Schott", "N-SF6HT", 1.77932, 0.0133714, 0.33815, 0.0617534, 2.08734, 174.018, -4.93e-06, 7.02e-09, -2.4e-11, 9.84e-07, 1.54e-09, 0.29, 0.37, 2.5, 1, 2, 1, 0);
	NSF6HTULTRA_S1.setParameterAndCalcVd_Ve("Schott", "N-SF6HTultra", 1.77932, 0.0133714, 0.33815, 0.0617534, 2.08734, 174.018, -4.93e-06, 7.02e-09, -2.4e-11, 9.84e-07, 1.54e-09, 0.29, 0.37, 2.5, 1, 2, 1, 0);
	NSF8_S1.setParameterAndCalcVd_Ve("Schott", "N-SF8", 1.55076, 0.0114338, 0.209817, 0.0582726, 1.46205, 133.242, -1.94e-06, 9.7e-09, -2.34e-11, 8.32e-07, 1.15e-09, 0.276, 0.37, 2.5, 1, 1, 1, 0);
	NSK11_S1.setParameterAndCalcVd_Ve("Schott", "N-SK11", 1.17964, 0.00680282, 0.229817, 0.0219737, 0.93579, 101.513, 2.14e-06, 1.27e-08, -7.21e-11, 3.51e-07, 5.41e-10, 0.238, 0.3, 2.5, 2, 2, 1, 0);
	NSK14_S1.setParameterAndCalcVd_Ve("Schott", "N-SK14", 0.936155, 0.00461717, 0.594052, 0.0168859, 1.04375, 103.736, 1.58e-06, 1.22e-08, -8.04e-12, 4.46e-07, 5.22e-10, 0.15, 0.31, 2.5, 4, 51.3, 2, 2);
	NSK16_S1.setParameterAndCalcVd_Ve("Schott", "N-SK16", 1.34318, 0.00704687, 0.241144, 0.0229005, 0.994318, 92.7509, -2.37e-08, 1.32e-08, -1.29e-11, 4.09e-07, 5.17e-10, 0.17, 0.31, 2.5, 4, 53.3, 3.3, 4);
	NSK2_S1.setParameterAndCalcVd_Ve("Schott", "N-SK2", 1.28189, 0.00727192, 0.257738, 0.0242824, 0.968186, 110.378, 3.8e-06, 1.41e-08, 2.28e-11, 6.44e-07, 8.03e-11, 0.108, 0.31, 2.5, 2, 2.2, 1, 0);
	NSK2HT_S1.setParameterAndCalcVd_Ve("Schott", "N-SK2HT", 1.28189, 0.00727192, 0.257738, 0.0242824, 0.968186, 110.378, 3.8e-06, 1.41e-08, 2.28e-11, 6.44e-07, 8.03e-11, 0.108, 0.31, 2.5, 2, 2.2, 1, 0);
	NSK4_S1.setParameterAndCalcVd_Ve("Schott", "N-SK4", 1.32994, 0.00716874, 0.228543, 0.0246456, 0.988465, 100.886, 7.96e-07, 1.3e-08, -1.31e-11, 4.36e-07, 6.01e-10, 0.179, 0.334, 2.5, 3, 51.2, 2, 1);
	NSK5_S1.setParameterAndCalcVd_Ve("Schott", "N-SK5", 0.991464, 0.0052273, 0.495982, 0.0172734, 0.987394, 98.3595, 3.5e-06, 1.22e-08, 6.38e-11, 2.46e-07, -3.34e-11, 0.278, 0.3, 2.5, 3, 4.4, 2, 1);
	NSSK2_S1.setParameterAndCalcVd_Ve("Schott", "N-SSK2", 1.4306, 0.00823983, 0.153151, 0.0333737, 1.01391, 106.871, 5.21e-06, 1.34e-08, -1.01e-11, 5.21e-07, 5.87e-10, 0.199, 0.35, 2.5, 1, 1.2, 1, 0);
	NSSK5_S1.setParameterAndCalcVd_Ve("Schott", "N-SSK5", 1.59223, 0.00920285, 0.103521, 0.042353, 1.05174, 106.927, 7.29e-07, 1.17e-08, -1.5e-11, 6.08e-07, 7.66e-10, 0.189, 0.35, 2.5, 2, 52.2, 2.2, 3);
	NSSK8_S1.setParameterAndCalcVd_Ve("Schott", "N-SSK8", 1.44858, 0.0086931, 0.117966, 0.0421567, 1.06938, 111.301, 5.34e-07, 1.27e-08, -1.75e-11, 5.4e-07, 7.05e-10, 0.224, 0.35, 2.5, 1, 1, 1.3, 0);
	NZK7_S1.setParameterAndCalcVd_Ve("Schott", "N-ZK7", 1.07715, 0.00676602, 0.168079, 0.0230643, 0.85189, 89.0499, 1.15e-05, 1.73e-08, -8.06e-11, 4.32e-07, 7.05e-10, 0.179, 0.3, 2.5, 1, 2, 1.2, 0);
	PLAF37_S1.setParameterAndCalcVd_Ve("Schott", "P-LAF37", 1.76003, 0.00938006, 0.248287, 0.0360537, 1.15935, 86.4325, 0, 0, 0, 0, 0, 0, 0.32, 2.5, 2, 53.3, 1.3, 5);
	PLAK35_S1.setParameterAndCalcVd_Ve("Schott", "P-LAK35", 1.39324, 0.0071596, 0.418883, 0.0233637, 1.04381, 88.3284, -1.9e-06, 7.99e-09, 7.76e-12, 5.64e-07, 6.57e-10, 0.185, 0.3, 2.5, 2, 53.3, 1.3, 5);
	PLASF47_S1.setParameterAndCalcVd_Ve("Schott", "P-LASF47", 1.85543, 0.0100328, 0.315855, 0.0387095, 1.28562, 94.5422, 7.87e-06, 1.09e-08, -1.56e-11, 7.58e-07, 8.92e-10, 0.218, 0.334, 2.5, 1, 51.4, 1, 1);
	PLASF50_S1.setParameterAndCalcVd_Ve("Schott", "P-LASF50", 1.84911, 0.00999235, 0.329829, 0.0387438, 1.30401, 95.8968, 8.04e-06, 1.2e-08, -2.19e-11, 8.2e-07, 9.08e-10, 0.209, 0.334, 2.5, 1, 51.3, 1, 1);
	PLASF51_S1.setParameterAndCalcVd_Ve("Schott", "P-LASF51", 1.84569, 0.00988496, 0.339002, 0.0378097, 1.32419, 97.8415, 7.79e-06, 1.1e-08, -2.03e-11, 7.86e-07, 8.78e-10, 0.215, 0.334, 2.5, 1, 51.3, 1, 1);
	PSF67_S1.setParameterAndCalcVd_Ve("Schott", "P-SF67", 1.97464, 0.0145772, 0.467096, 0.066979, 2.43154, 157.445, 4.82e-07, 1.15e-08, -9.95e-12, 1.15e-06, 1.65e-09, 0.315, 0.39, 2.5, 1, 1, 1.3, 0);
	PSF68_S1.setParameterAndCalcVd_Ve("Schott", "P-SF68", 2.33301, 0.0168838, 0.452961, 0.0716086, 1.25172, 118.707, 1.55e-05, 2.3e-08, -3.46e-11, 2.76e-06, 2.93e-09, 0.297, 0.42, 2.5, 1, 53.3, 2.3, 5);
	PSF69_S1.setParameterAndCalcVd_Ve("Schott", "P-SF69", 1.62595, 0.0121697, 0.235928, 0.060071, 1.67435, 145.652, -2.55e-06, 5.68e-09, -2.85e-11, 9.5e-07, 1.54e-09, 0.275, 0.365, 2.5, 1, 1, 1.2, 0);
	PSF8_S1.setParameterAndCalcVd_Ve("Schott", "P-SF8", 1.5537, 0.0116583, 0.206333, 0.0582088, 1.39709, 130.748, -4.27e-06, 8.16e-09, -2e-11, 9.02e-07, 1.22e-09, 0.272, 0.365, 2.5, 1, 1, 1.2, 0);
	PSK57_S1.setParameterAndCalcVd_Ve("Schott", "P-SK57", 1.31053, 0.00740877, 0.169376, 0.0254563, 1.10988, 107.751, 2.6e-06, 9.4e-09, -2.3e-11, 4.9e-07, 5.96e-10, 0.178, 0.32, 2.5, 4, 52.3, 2, 3);
	PSK58A_S1.setParameterAndCalcVd_Ve("Schott", "P-SK58A", 1.31678, 0.00720717, 0.171155, 0.024566, 1.12501, 102.74, 3.16e-06, 1.23e-08, -1.08e-11, 4.41e-07, 3.2e-10, 0.176, 0.32, 2.5, 3, 53.4, 2.3, 5);
	PSK60_S1.setParameterAndCalcVd_Ve("Schott", "P-SK60", 1.4079, 0.00784382, 0.143381, 0.0287769, 1.16514, 105.373, 2.41e-06, 9.52e-09, -8.08e-12, 4.72e-07, 6.22e-10, 0.193, 0.3, 2.5, 3, 53.4, 2.3, 5);
	SF1_S1.setParameterAndCalcVd_Ve("Schott", "SF1", 1.55913, 0.0121481, 0.284246, 0.0534549, 0.968843, 112.175, 4.84e-06, 1.7e-08, -4.52e-11, 1.38e-06, 1.26e-09, 0.259, 0.35, 2.5, 2, 3.2, 2.3, 1);
	SF10_S1.setParameterAndCalcVd_Ve("Schott", "SF10", 1.61626, 0.0127535, 0.259229, 0.0581984, 1.07762, 116.608, 5.31e-06, 1.59e-08, -4.07e-11, 1.28e-06, 1.32e-09, 0.27, 0.38, 2.5, 1, 1, 1.2, 0);
	SF2_S1.setParameterAndCalcVd_Ve("Schott", "SF2", 1.40302, 0.0105795, 0.231768, 0.0493227, 0.939057, 112.406, 1.1e-06, 1.75e-08, -1.29e-11, 1.08e-06, 1.03e-09, 0.249, 0.35, 2.5, 1, 2, 2.3, 0);
	SF4_S1.setParameterAndCalcVd_Ve("Schott", "SF4", 1.61958, 0.0125502, 0.339493, 0.054456, 1.02567, 117.652, 5.6e-06, 1.7e-08, -5.27e-11, 1.54e-06, 1.46e-09, 0.266, 0.365, 2.5, 1, 4.3, 2.3, 2);
	SF5_S1.setParameterAndCalcVd_Ve("Schott", "SF5", 1.46142, 0.0111826, 0.247713, 0.0508595, 0.949996, 112.042, 2.59e-06, 1.76e-08, -2.03e-11, 1.17e-06, 1.09e-09, 0.255, 0.35, 2.5, 1, 2, 2.3, 1);
	SF56A_S1.setParameterAndCalcVd_Ve("Schott", "SF56A", 1.70579, 0.0133875, 0.344223, 0.0579562, 1.09602, 121.616, 6.02e-06, 1.7e-08, -2.61e-11, 1.63e-06, 1.59e-09, 0.269, 0.37, 2.5, 1, 3.2, 2.2, 1);
	SF57_S1.setParameterAndCalcVd_Ve("Schott", "SF57", 1.81651, 0.0143704, 0.428894, 0.0592801, 1.07186, 121.42, 7.26e-06, 1.88e-08, -5.14e-11, 1.96e-06, 1.79e-09, 0.276, 0.37, 2.5, 2, 52.3, 2.3, 5);
	SF6_S1.setParameterAndCalcVd_Ve("Schott", "SF6", 1.72448, 0.0134872, 0.390105, 0.0569318, 1.04573, 118.557, 6.69e-06, 1.78e-08, -3.36e-11, 1.77e-06, 1.7e-09, 0.269, 0.365, 2.5, 2, 51.3, 2.3, 3);
	SF6HT_S1.setParameterAndCalcVd_Ve("Schott", "SF6HT", 1.72448482, 0.01348719470, 0.390104889, 0.0569318095, 1.045728580, 118.5571850, 6.69E-06, 1.78E-08, -3.36E-11, 1.77E-06, 1.70E-09, 0.269, 0.35, 2.5, 2, 51.3, 2.3, 3);
	SF57HTULTRA_S1.setParameterAndCalcVd_Ve("Schott", "N-SF57HTultra", 1.87544, 0.014175, 0.373757, 0.064051, 2.30002, 177.39, -4.51e-06, 8.73e-09, -1.64e-11, 1.07e-06, 1.57e-09, 0.295, 0.37, 2.5, 1, 1, 1, 0);
	PBK7_S1.setParameterAndCalcVd_Ve("Schott", "P-BK7", 1.18319, 0.00722142, 0.0871756, 0.0268217, 1.03134, 101.702, 0, 0, 0, 0, 0, 0, 0.31, 2.5, 1, 1, 2.3, 0);
	PSK57Q1_S1.setParameterAndCalcVd_Ve("Schott", "P-SK57Q1", 1.30536, 0.00736409, 0.171434, 0.0255786, 1.10117, 106.726, 0, 0, 0, 0, 0, 0, 0.31, 2.5, 4, 52.3, 2, 3);
	SF11_S1.setParameterAndCalcVd_Ve("Schott", "SF11", 1.73848, 0.0136069, 0.311169, 0.061596, 1.17491, 121.923, 1.12e-05, 1.81e-08, -5.03e-11, 1.46e-06, 1.58e-09, 0.282, 0.39, 2.5, 1, 1, 1.2, 0);
	LASF35_S1.setParameterAndCalcVd_Ve("Schott", "LASF35", 2.45506, 0.013567, 0.453006, 0.0545803, 2.38513, 167.905, 1.43e-07, 8.71e-09, -2.71e-11, 1.02e-06, 1.5e-09, 0.263, 0.37, 2.5, 1, 1.3, 1, 0);
	FK3_S1.setParameterAndCalcVd_Ve("Schott", "FK3", 0.973347, 0.00640795, 0.146642, 0.0205653, 0.679304, 80.4965, -4.9e-06, 1.23e-08, -1.19e-10, 3.45e-07, 7.72e-10, 0.18, 0.3, 2.5, 2, 52.4, 2, 3);
	NSK10_S1.setParameterAndCalcVd_Ve("Schott", "N-SK10", 1.34972, 0.00736272, 0.238588, 0.0253765, 0.966734, 103.503, 5.05e-07, 1.16e-08, -1.53e-11, 4.9e-07, 5.1e-10, 0.183, 0.334, 2.5, 3, 52.2, 2, 3);
	NSK15_S1.setParameterAndCalcVd_Ve("Schott", "N-SK15", 1.30418, 0.00695051, 0.285841, 0.0232024, 0.974782, 99.0169, 4.92e-07, 1.2e-08, -2.96e-12, 4.66e-07, 5.16e-10, 0.179, 0.334, 2.5, 3, 52.2, 2, 3);
	NBAF3_S1.setParameterAndCalcVd_Ve("Schott", "N-BAF3", 1.3486, 0.00871493, 0.107644, 0.0478406, 1.13207, 112.936, 1.4e-06, 1.24e-08, -9.39e-12, 5.91e-07, 7.44e-10, 0.235, 0.365, 2.5, 1, 1, 1, 0);
	BAFN6_S1.setParameterAndCalcVd_Ve("Schott", "BAFN6", 1.36719, 0.00882821, 0.10908, 0.0438732, 1.02108, 113.586, 1.34e-06, 1.34e-08, -5.5e-11, 4.95e-07, 3.62e-10, 0.265, 0.35, 2.325, 2, 2, 2, 0);
	NLAF3_S1.setParameterAndCalcVd_Ve("Schott", "N-LAF3", 1.73156, 0.00953834, 0.150874, 0.0407887, 1.06587, 98.0759, -2.35e-06, 1.07e-08, -9.38e-12, 5.72e-07, 6.01e-10, 0.22, 0.35, 2.5, 2, 52.3, 1.2, 3);
	SFL57_S1.setParameterAndCalcVd_Ve("Schott", "SFL57", 1.88742, 0.0145939, 0.360534, 0.0648199, 2.26189, 176.062, -3.63e-06, 8.61e-09, -9.98e-12, 1.1e-06, 1.69e-09, 0.293, 0.39, 2.5, 1, 1.3, 1, 0);
	SFL6_S1.setParameterAndCalcVd_Ve("Schott", "SFL6", 1.78922, 0.0135164, 0.328427, 0.062273, 2.01639, 168.015, -5.26e-06, 7.41e-09, -1.89e-11, 1.02e-06, 1.62e-09, 0.288, 0.37, 2.325, 1, 2, 1, 0);
	NSF19_S1.setParameterAndCalcVd_Ve("Schott", "N-SF19", 1.52005, 0.0109614, 0.175739, 0.0593248, 1.43623, 126.795, 1.32e-06, 1.22e-08, -1.36e-11, 7.64e-07, 1.09e-09, 0.279, 0.37, 2.5, 1, 1, 1.2, 0);
	NSF56_S1.setParameterAndCalcVd_Ve("Schott", "N-SF56", 1.73562, 0.0129625, 0.317487, 0.0612884, 1.95398, 161.559, -4.13e-06, 7.65e-09, -1.12e-11, 9.9e-07, 1.57e-09, 0.287, 0.38, 2.5, 1, 1, 1.3, 0);
	NSF64_S1.setParameterAndCalcVd_Ve("Schott", "N-SF64", 1.59164, 0.0118623, 0.219908, 0.0594585, 1.46929, 133.311, -2.06e-06, 9.78e-09, -1.67e-11, 8.67e-07, 1.23e-09, 0.279, 0.37, 2.5, 1, 1, 1.2, 0);
	NPSK53_S1.setParameterAndCalcVd_Ve("Schott", "N-PSK53", 1.34341, 0.00675074, 0.241418, 0.0219911, 0.952897, 103.551, -9.29e-06, 5.78e-09, 8.87e-13, 4.59e-07, 5.86e-10, 0.155, 0.31, 2.5, 2, 52.3, 1.2, 1);
	BK7G18_S1.setParameterAndCalcVd_Ve("Schott", "BK7G18", 1.26539, 0.00813104, 0.0144191, 0.0543303, 1.00323, 102.821, 1.52e-06, 1.37e-08, -1.26e-11, 4.36e-07, 4.17e-10, 0.194, 0.38, 2.5, 1, 1, 2, 0);
	LF5G19_S1.setParameterAndCalcVd_Ve("Schott", "LF5G19", 1.34611, 0.00971744, 0.142428, 0.0501912, 0.900477, 111.96, -8.15e-06, 1.34e-08, -9.22e-12, 8.57e-07, 8.26e-10, 0.243, 0.4, 2.5, 2, 3.4, 2.2, 2);
	LF5G15_S1.setParameterAndCalcVd_Ve("Schott", "LF5G15", 1.28887, 0.00920016, 0.162819, 0.0456954, 10.558, 1275.44, 0, 0, 0, 0, 0, 0, 0.38, 2.5, 2, 1, 1.3, 0);
	K5G20_S1.setParameterAndCalcVd_Ve("Schott", "K5G20", 1.14094, 0.00694945, 0.145001, 0.0310574, 37.4706, 4536.26, -2.22e-06, 8.45e-09, -3.31e-11, 5.44e-07, 4.95e-10, 0.214, 0.37, 2.5, 3, 1, 1, 0);
	LAK9G15_S1.setParameterAndCalcVd_Ve("Schott", "LAK9G15", 1.28774, 0.00557542, 0.518245, 0.022368, 26.1756, 1892.25, 0, 0, 0, 0, 0, 0, 0.38, 2.5, 1, 53, 1.3, 2);
	F2G12_S1.setParameterAndCalcVd_Ve("Schott", "F2G12", 1.34702, 0.00980851, 0.210038, 0.0471788, 19.5351, 2279.15, 0, 0, 0, 0, 0, 0, 0.39, 2.5, 1, 1, 1.3, 0);
	SF6G05_S1.setParameterAndCalcVd_Ve("Schott", "SF6G05", 1.62114, 0.0113479, 0.506586, 0.053584, 10.4032, 1118.84, 6.9e-06, 1.76e-08, -3.17e-11, 1.89e-06, 1.5e-09, 0.256, 0.46, 2.5, 4, 51.3, 2.3, 3);
	LASFN9_S1.setParameterAndCalcVd_Ve("Schott", "LASFN9", 1.97888, 0.0118537, 0.320435, 0.0527382, 1.92901, 166.257, 9.44e-07, 1.14e-08, -1.87e-11, 9.22e-07, 1.22e-09, 0.255, 0.365, 2.5, 2, 2, 1, 0);
	LAKL12_S1.setParameterAndCalcVd_Ve("Schott", "LAKL12", 1.28115, 0.0063644, 0.482608, 0.0213764, 1.16554, 93.2772, 2.26e-06, 1.05e-08, -8.4e-12, 4.57e-07, 5.86e-10, 0.21, 0.32, 2.5, 3, 53.3, 2.2, 3);
	NLASF46_S1.setParameterAndCalcVd_Ve("Schott", "N-LASF46", 2.18074, 0.0125642, 0.298979, 0.05647, 1.6219, 105.663, 3.6e-06, 1.2e-08, -2.68e-11, 8.42e-07, 1.15e-09, 0.272, 0.38, 2.5, 1, 3.3, 1, 0);
	NLASF31_S1.setParameterAndCalcVd_Ve("Schott", "N-LASF31", 1.71317, 0.00819172, 0.718575, 0.0297802, 1.72332, 138.461, 2.29e-06, 8.93e-09, -1.59e-11, 6.52e-07, 8.09e-10, 0.236, 0.32, 2.5, 1, 2, 1, 0);
	NFK51_S1.setParameterAndCalcVd_Ve("Schott", "N-FK51", 0.971248, 0.00472302, 0.216901, 0.0153576, 0.904652, 168.681, -1.83e-05, -7.89e-09, -1.63e-12, 3.74e-07, 3.46e-10, 0.15, 0.29, 2.5, 2, 52.3, 2.2, 0);
	NLAF32_S1.setParameterAndCalcVd_Ve("Schott", "N-LAF32", 1.91731, 0.009786, 0.22402, 0.0386141, 1.22087, 84.6431, 3.8e-06, 1.1e-08, -1.83e-11, 6.37e-07, 8.03e-10, 0.196, 0.35, 2.5, 1, 51.2, 1, 1);
	KZFSN4_S1.setParameterAndCalcVd_Ve("Schott", "KZFSN4", 1.37994, 0.0089116, 0.168497, 0.0405334, 0.874886, 69.6628, 6.01e-06, 1.3e-08, -7.94e-11, 4.05e-07, 7.23e-10, 0.272, 0.31, 2.5, 3, 52.3, 4.3, 2);
	SF14_S1.setParameterAndCalcVd_Ve("Schott", "SF14", 1.69183, 0.0133152, 0.28592, 0.0612647, 1.12595, 118.405, 8.85e-06, 1.81e-08, -4.12e-11, 1.39e-06, 1.53e-09, 0.279, 0.39, 2.5, 1, 1, 1.2, 0);
	SF15_S1.setParameterAndCalcVd_Ve("Schott", "SF15", 1.57055634, 0.01165070140, 0.218987094, 0.0597856897, 1.508240170, 132.7093390, 2.91e-06, 1.69e-08, -3.77e-11, 1.1e-06, 1.07e-09, 0.278, 0.37, 2.5, 1, 1, 1.2, 0);
	SF66_S1.setParameterAndCalcVd_Ve("Schott", "SF66", 2.02459760, 0.01470532250, 0.470187196, 0.0692998276, 2.599704330, 161.8176010, 0, 0, 0, 0, 0, 0, 0.39, 2.5, 2, 53.4, 2.3, 5);
	LITHOTECCAF2_S1.setParameterAndCalcVd_Ve("Schott", "LITHOTEC-CAF2", 0.617617, 0.00275382, 0.421118, 0.0105901, 3.79711, 1182.67, -3.18e-05, -2.31e-08, 4.13e-11, 3.35e-07, 1.91e-10, 0.192, 0.25, 2.5, 1, 4.5, 2.3, 0);
	LITHOSILQ_S1.setParameterAndCalcVd_Ve("Schott", "LITHOSIL-Q", 0.670711, 0.00449192, 0.433323, 0.0132813, 0.877379, 95.89, 2.06e-05, 2.51e-08, -2.47e-11, 3.12e-07, 4.22e-10, 0.16, 0.25, 2.5, 1, 1, 1, 0);
	KZFS12_S1.setParameterAndCalcVd_Ve("Schott", "KZFS12", 1.55625, 0.0102013, 0.239769, 0.0469278, 0.947888, 69.8371, 4.36e-06, 1.32e-08, -1.81e-11, 6.86e-07, 6.81e-10, 0.253, 0.35, 2.5, 4, 53.3, 4.3, 1);
	PPK53_S1.setParameterAndCalcVd_Ve("Schott", "P-PK53", 0.960317, 0.00531033, 0.340437, 0.0175073, 0.777866, 106.875, -1.65e-05, -5.14e-10, -2.02e-11, 4.11e-07, 4.17e-10, 0.208, 0.32, 2.5, 2, 51, 4.3, 1);
	NLAF36_S1.setParameterAndCalcVd_Ve("Schott", "N-LAF36", 1.85744, 0.00982397, 0.294099, 0.0384309, 1.16615, 89.3985, 8.72e-06, 1.12e-08, -1.38e-11, 7.81e-07, 9.48e-10, 0.212, 0.35, 2.5, 1, 52.3, 1, 2);
	FK5HTI_S1.setParameterAndCalcVd_Ve("Schott", "FK5HTi", 0.909362, 0.00520142, 0.279077, 0.0158938, 0.891813, 95.9109, -7.47e-06, 1.58e-08, -1.23e-11, 3.58e-07, 4.03e-10, 0.164, 0.25, 2.5, 2, 4, 2, 1);
	LF5HTI_S1.setParameterAndCalcVd_Ve("Schott", "LF5HTi", 1.28553, 0.00939886, 0.158358, 0.0452567, 0.892175, 110.545, -2.26e-06, 1.17e-08, -4.14e-11, 8.24e-07, 7.78e-10, 0.232, 0.31, 2.5, 2, 1, 2.3, 0);
	LLF1HTI_S1.setParameterAndCalcVd_Ve("Schott", "LLF1HTi", 1.2251, 0.00870432, 0.125156, 0.0427325, 0.892237, 108.05, 2.55e-07, 1.41e-08, -3.32e-11, 6.74e-07, 6.27e-10, 0.227, 0.3, 2.5, 1, 1, 2, 0);
	NBK7HTI_S1.setParameterAndCalcVd_Ve("Schott", "N-BK7HTi", 1.03961, 0.0060007, 0.231792, 0.0200179, 1.01047, 103.561, 1.86e-06, 1.31e-08, -1.37e-11, 4.34e-07, 6.27e-10, 0.17, 0.3, 2.5, 1, 1, 2.3, 0);
	NFK58_S1.setParameterAndCalcVd_Ve("Schott", "N-FK58", 0.738043, 0.00339066, 0.363372, 0.0117551, 0.989296, 212.842, -2.05e-05, -6.33e-09, 4.13e-11, 3.84e-07, 1.63e-10, 0.073, 0.26, 2.5, 1, 52.3, 3.3, 1);
	BAFN10_S1.setParameterAndCalcVd_Ve("Schott", "BAFN10", 1.58514950, 0.00926681282, 0.143559385, 0.0424489805, 1.085212690, 105.6135730, 1.34e-06, 1.34E-08, -5.5e-11, 4.95e-07, 3.62e-10, 0.265, 0.35, 2.325, 2, 2, 2, 0);
	
}

// get glasses

// Air Zemax
MaterialSellmeier1 glass::getAir()
{
	return Air;
}


//F2
MaterialSellmeier1 glass::get_F2_S1()
{
	return F2_S1;
}

// F5
MaterialSellmeier1 glass::getF5_S1()
{
	return F5_S1;
}

// K10
MaterialSellmeier1 glass::getK10_S1()
{
	return K10_S1;
}

// K7
MaterialSellmeier1 glass::getK7_S1()
{
	return K7_S1;
}

//LAFN7
MaterialSellmeier1 glass::getLAFN7_S1()
{
	return LAFN7_S1;
}

//LF5
MaterialSellmeier1 glass::getLF5_S1()
{
	return LF5_S1;
}

//LLF1
MaterialSellmeier1 glass::getLLF1_S1()
{
	return LLF1_S1;
}

//NBAF10
MaterialSellmeier1 glass::getNBAF10_S1()
{
	return NBAF10_S1;
}

//NBAF4
MaterialSellmeier1 glass::getNBAF4_S1()
{
	return NBAF4_S1;
}

//NBAF51
MaterialSellmeier1 glass::getNBAF51_S1()
{
	return NBAF51_S1;
}

//NBAF52
MaterialSellmeier1 glass::getNBAF52_S1()
{
	return NBAF52_S1;
}

//NBAK1
MaterialSellmeier1 glass::getNBAK1_S1()
{
	return NBAK1_S1;
}

//NBAK2
MaterialSellmeier1 glass::getNBAK2_S1()
{
	return NBAK2_S1;
}

//NBAK4
MaterialSellmeier1 glass::getNBAK4_S1()
{
	return NBAK4_S1;
}

//NBAK4HT
MaterialSellmeier1 glass::getNBAK4HT_S1()
{
	return NBAK4HT_S1;
}

//NBALF4
MaterialSellmeier1 glass::getNBALF4_S1()
{
	return NBALF4_S1;
}

//NBALF5
MaterialSellmeier1 glass::getNBALF5_S1()
{
	return NBALF5_S1;
}

//NBASF2
MaterialSellmeier1 glass::getNBASF2_S1()
{
	return NBASF2_S1;
}

//NBASF64
MaterialSellmeier1 glass::getNBASF64_S1()
{
	return NBASF64_S1;
}

//NBK10
MaterialSellmeier1 glass::getNBK10_S1()
{
	return NBK10_S1;
}

//NBK7
MaterialSellmeier1 glass::getNBK7_S1()
{
	return NBK7_S1;
}

//NBK7HT
MaterialSellmeier1 glass::getNBK7HT_S1()
{
	return NBK7HT_S1;
}

//NF2
MaterialSellmeier1 glass::getNF2_S1()
{
	return NF2_S1;
}

//NFK5
MaterialSellmeier1 glass::getNFK5_S1()
{
	return NFK5_S1;
}

//NFK51A
MaterialSellmeier1 glass::getNFK51A_S1()
{
	return NFK51A_S1;
}

//NK5
MaterialSellmeier1 glass::getNK5_S1()
{
	return NK5_S1;
}

//NKF9
MaterialSellmeier1 glass::getNKF9_S1()
{
	return NKF9_S1;
}

//NKZFS1
MaterialSellmeier1 glass::getNKZFS11_S1()
{
	return NKZFS11_S1;
}

//NKZFS2
MaterialSellmeier1 glass::getNKZFS2_S1()
{
	return NKZFS2_S1;
}

//NKZFS4
MaterialSellmeier1 glass::getNKZFS4_S1()
{
	return NKZFS4_S1;
}

//NKZFS4HT
MaterialSellmeier1 glass::getNKZFS4HT_S1()
{
	return NKZFS4HT_S1;
}

//NKZFS5
MaterialSellmeier1 glass::getNKZFS5_S1()
{
	return NKZFS5_S1;
}

//NKZFS8
MaterialSellmeier1 glass::getNKZFS8_S1()
{
	return NKZFS8_S1;
}

//NLAF2
MaterialSellmeier1 glass::getNLAF2_S1()
{
	return NLAF2_S1;
}

//NLAF21
MaterialSellmeier1 glass::getNLAF21_S1()
{
	return NLAF21_S1;
}

//NLAF33
MaterialSellmeier1 glass::getNLAF33_S1()
{
	return NLAF33_S1;
}

//NLAF34
MaterialSellmeier1 glass::getNLAF34_S1()
{
	return NLAF34_S1;
}

//NLAF35
MaterialSellmeier1 glass::getNLAF35_S1()
{
	return NLAF35_S1;
}

//NLAF7
MaterialSellmeier1 glass::getNLAF7_S1()

{
	return NLAF7_S1;
}

//NLAK10
MaterialSellmeier1 glass::getNLAK10_S1()
{
	return NLAK10_S1;
}

//NLAK12
MaterialSellmeier1 glass::getNLAK12_S1()
{
	return NLAK12_S1;
}

//NLAK14
MaterialSellmeier1 glass::getNLAK14_S1()
{
	return NLAK14_S1;
}

//NLAK21
MaterialSellmeier1 glass::getNLAK21_S1()
{
	return NLAK21_S1;
}

//NLAK22
MaterialSellmeier1 glass::getNLAK22_S1()
{
	return NLAK22_S1;
}

//NLAK33A
MaterialSellmeier1 glass::getNLAK33A_S1()
{
	return NLAK33A_S1;
}

//NLAK33B
MaterialSellmeier1 glass::getNLAK33B_S1()
{
	return NLAK33B_S1;
}

//NLAK34
MaterialSellmeier1 glass::getNLAK34_S1()
{
	return NLAK34_S1;
}

//NLAK7
MaterialSellmeier1 glass::getNLAK7_S1()
{
	return NLAK7_S1;
}

//NLAK8
MaterialSellmeier1 glass::getNLAK8_S1()
{
	return NLAK8_S1;
}

//NLAK9
MaterialSellmeier1 glass::getNLAK9_S1()
{
	return NLAK9_S1;
}

//NLASF31A
MaterialSellmeier1 glass::getNLASF31A_S1()
{
	return NLASF31A_S1;
}

//NLASF40
MaterialSellmeier1 glass::getNLASF40_S1()
{
	return NLASF40_S1;
}

//NLASF41
MaterialSellmeier1 glass::getNLASF41_S1()
{
	return NLASF41_S1;
}

//NLASF43
MaterialSellmeier1 glass::getNLASF43_S1()
{
	return NLASF43_S1;
}

//NLASF44
MaterialSellmeier1 glass::getNLASF44_S1()
{
	return NLASF44_S1;
}

//NLASF45
MaterialSellmeier1 glass::getNLASF45_S1()
{
	return NLASF45_S1;
}

//NLASF45HT
MaterialSellmeier1 glass::getNLASF45HT_S1()
{
	return NLASF45HT_S1;
}

//NLASF46A
MaterialSellmeier1 glass::getNLASF46A_S1()
{
	return NLASF46A_S1;
}

//NLASF46B
MaterialSellmeier1 glass::getNLASF46B_S1()
{
	return NLASF46B_S1;
}

//NLASF9
MaterialSellmeier1 glass::getNLASF9_S1()
{
	return NLASF9_S1;
}

//NLASF9HT
MaterialSellmeier1 glass::getNLASF9HT_S1()
{
	return NLASF9HT_S1;
}

//NPK51
MaterialSellmeier1 glass::getNPK51_S1()
{
	return NPK51_S1;
}

//NPK52A
MaterialSellmeier1 glass::getNPK52A_S1()
{
	return NPK52A_S1;
}

//NPSK3
MaterialSellmeier1 glass::getNPSK3_S1()
{
	return NPSK3_S1;
}

//NPSK53A
MaterialSellmeier1 glass::getNPSK53A_S1()
{
	return NPSK53A_S1;
}

//NSF1
MaterialSellmeier1 glass::getNSF1_S1()
{
	return NSF1_S1;
}

//NSF10
MaterialSellmeier1 glass::getNSF10_S1()
{
	return NSF10_S1;
}

//NSF11
MaterialSellmeier1 glass::getNSF11_S1()
{
	return NSF11_S1;
}

//NSF14
MaterialSellmeier1 glass::getNSF14_S1()
{
	return NSF14_S1;
}

//NSF15
MaterialSellmeier1 glass::getNSF15_S1()
{
	return NSF15_S1;
}

//NSF2
MaterialSellmeier1 glass::getNSF2_S1()
{
	return NSF2_S1;
}

//NSF4
MaterialSellmeier1 glass::getNSF4_S1()
{
	return NSF4_S1;
}

//NSF5
MaterialSellmeier1 glass::getNSF5_S1()
{
	return NSF5_S1;
}

//NSF57
MaterialSellmeier1 glass::getNSF57_S1()
{
	return NSF57_S1;
}

//NSF57HT
MaterialSellmeier1 glass::getNSF57HT_S1()
{
	return NSF57HT_S1;
}

//NSF57HTULTRA
MaterialSellmeier1 glass::getNSF57HTULTRA_S1()
{
	return NSF57HTULTRA_S1;
}

//NSF6
MaterialSellmeier1 glass::getNSF6_S1()
{
	return NSF6_S1;
}

//NSF66
MaterialSellmeier1 glass::getNSF66_S1()
{
	return NSF66_S1;
}

//NSF6HT
MaterialSellmeier1 glass::getNSF6HT_S1()
{
	return NSF6HT_S1;
}

//NSF6HTULTRA
MaterialSellmeier1 glass::getNSF6HTULTRA_S1()
{
	return NSF6HTULTRA_S1;
}

//NSF8
MaterialSellmeier1 glass::getNSF8_S1()
{
	return NSF8_S1;
}

//NSK11
MaterialSellmeier1 glass::getNSK11_S1()
{
	return NSK11_S1;
}

//NSK14
MaterialSellmeier1 glass::getNSK14_S1()
{
	return NSK14_S1;
}

//NSK16
MaterialSellmeier1 glass::getNSK16_S1()
{
	return NSK16_S1;
}

//NSK2
MaterialSellmeier1 glass::getNSK2_S1()
{
	return NSK2_S1;
}

//NSK2HT
MaterialSellmeier1 glass::getNSK2HT_S1()
{
	return NSK2HT_S1;
}

//NSK4
MaterialSellmeier1 glass::getNSK4_S1()
{
	return NSK4_S1;
}

//NSK5
MaterialSellmeier1 glass::getNSK5_S1()
{
	return NSK5_S1;
}

//NSSK2
MaterialSellmeier1 glass::getNSSK2_S1()
{
	return NSSK2_S1;
}

//NSSK5
MaterialSellmeier1 glass::getNSSK5_S1()
{
	return NSSK5_S1;
}

//NSSK8
MaterialSellmeier1 glass::getNSSK8_S1()
{
	return NSSK8_S1;
}

//NZK7
MaterialSellmeier1 glass::getNZK7_S1()
{
	return NZK7_S1;
}

//PLAF37
MaterialSellmeier1 glass::getPLAF37_S1()
{
	return PLAF37_S1;
}

//PLAK35
MaterialSellmeier1 glass::getPLAK35_S1()
{
	return PLAK35_S1;
}

//PLASF47
MaterialSellmeier1 glass::getPLASF47_S1()
{
	return PLASF47_S1;
}

//PLASF50
MaterialSellmeier1 glass::getPLASF50_S1()
{
	return PLASF50_S1;
}

//PLASF51
MaterialSellmeier1 glass::getPLASF51_S1()
{
	return PLASF51_S1;
}

//PSF67
MaterialSellmeier1 glass::getPSF67_S1()
{
	return PSF67_S1;
}

//PSF68
MaterialSellmeier1 glass::getPSF68_S1()
{
	return PSF68_S1;
}

//PSF69
MaterialSellmeier1 glass::getPSF69_S1()
{
	return PSF69_S1;
}

//PSF8
MaterialSellmeier1 glass::getPSF8_S1()
{
	return PSF8_S1;
}

//PSK57
MaterialSellmeier1 glass::getPSK57_S1()
{
	return PSK57_S1;
}

//PSK58A
MaterialSellmeier1 glass::getPSK58A_S1()
{
	return PSK58A_S1;
}

//PSK60
MaterialSellmeier1 glass::getPSK60_S1()
{
	return PSK60_S1;
}

//SF1
MaterialSellmeier1 glass::getSF1_S1()
{
	return SF1_S1;
}

//SF10
MaterialSellmeier1 glass::getSF10_S1()
{
	return SF10_S1;
}

//SF2
MaterialSellmeier1 glass::getSF2_S1()
{
	return SF2_S1;
}

//SF4
MaterialSellmeier1 glass::getSF4_S1()
{
	return SF4_S1;
}

//SF5
MaterialSellmeier1 glass::getSF5_S1()
{
	return SF5_S1;
}

//SF56A
MaterialSellmeier1 glass::getSF56A_S1()
{
	return SF56A_S1;
}

//SF57 
MaterialSellmeier1 glass::getSF57_S1()
{
	return SF57_S1;
}

//SF6
MaterialSellmeier1 glass::getSF6_S1()
{
	return SF6_S1;
}

//SF6HT
MaterialSellmeier1 glass::getSF6HT_S1()
{
	return SF6HT_S1;
}

//SF57HTULTRA
MaterialSellmeier1 glass::getSF57HTULTRA_S1()
{
	return SF57HTULTRA_S1;
}

//PBK7
MaterialSellmeier1 glass::getPBK7_S1()
{
	return PBK7_S1;
}

//PSK57Q1
MaterialSellmeier1 glass::getPSK57Q1_S1()
{
	return PSK57Q1_S1;
}

//SF11
MaterialSellmeier1 glass::getSF11_S1()
{
	return SF11_S1;
}

//LASF35
MaterialSellmeier1 glass::getLASF35_S1()
{
	return LASF35_S1;
}

//FK3
MaterialSellmeier1 glass::getFK3_S1()
{
	return FK3_S1;
}

//NSK10
MaterialSellmeier1 glass::getNSK10_S1()
{
	return NSK10_S1;
}

//NSK15
MaterialSellmeier1 glass::getNSK15_S1()
{
	return NSK15_S1;
}

//NBAF3
MaterialSellmeier1 glass::getNBAF3_S1()
{
	return NBAF3_S1;
}

//BAFN6
MaterialSellmeier1 glass::getBAFN6_S1()
{
	return BAFN6_S1;
}

//NLAF3
MaterialSellmeier1 glass::getNLAF3_S1()
{
	return NLAF3_S1;
}

//SFL57
MaterialSellmeier1 glass::getSFL57_S1()
{
	return SFL57_S1;
}

//SFL6
MaterialSellmeier1 glass::getSFL6_S1()
{
	return SFL6_S1;
}

//NSF19
MaterialSellmeier1 glass::getNSF19_S1()
{
	return NSF19_S1;
}

//NSF56
MaterialSellmeier1 glass::getNSF56_S1()
{
	return NSF56_S1;
}

//NSF64
MaterialSellmeier1 glass::getNSF64_S1()
{
	return NSF64_S1;
}

//NPSK53
MaterialSellmeier1 glass::getNPSK53_S1()
{
	return NPSK53_S1;
}

//BK7G18
MaterialSellmeier1 glass::getBK7G18_S1()
{
	return BK7G18_S1;
}

//LF5G19
MaterialSellmeier1 glass::getLF5G19_S1()
{
	return LF5G19_S1;
}

//LF5G15
MaterialSellmeier1 glass::getLF5G15_S1()
{
	return LF5G15_S1;
}

//K5G20
MaterialSellmeier1 glass::getK5G20_S1()
{
	return K5G20_S1;
}

//LAK9G15
MaterialSellmeier1 glass::getLAK9G15_S1()
{
	return LAK9G15_S1;
}

//F2G12
MaterialSellmeier1 glass::getF2G12_S1()
{
	return F2G12_S1;
}

//SF6G05
MaterialSellmeier1 glass::getSF6G05_S1()
{
	return SF6G05_S1;
}

//LASFN9
MaterialSellmeier1 glass::getLASFN9_S1()
{
	return LASFN9_S1;
}

//LAKL12
MaterialSellmeier1 glass::getLAKL12_S1()
{
	return LAKL12_S1;
}

//NLASF46
MaterialSellmeier1 glass::getNLASF46_S1()
{
	return NLASF46_S1;
}

//NLASF31
MaterialSellmeier1 glass::getNLASF31_S1()
{
	return NLASF31_S1;
}

//NFK51
MaterialSellmeier1 glass::getNFK51_S1()
{
	return NFK51_S1;
}

//NLAF32
MaterialSellmeier1 glass::getNLAF32_S1()
{
	return NLAF32_S1;
}

//KZFSN4
MaterialSellmeier1 glass::getKZFSN4_S1()
{
	return KZFSN4_S1;
}

//SF14
MaterialSellmeier1 glass::getSF14_S1()
{
	return SF14_S1;
}

//SF15
MaterialSellmeier1 glass::getSF15_S1()
{
	return SF15_S1;
}

//SF66
MaterialSellmeier1 glass::getSF66_S1()
{
	return SF66_S1;
}

//LITHOTECCAF2
MaterialSellmeier1 glass::getLITHOTECCAF2_S1()
{
	return LITHOTECCAF2_S1;
}

//LITHOSILQ
MaterialSellmeier1 glass::getLITHOSILQ_S1()
{
	return LITHOSILQ_S1;
}

////D263TECO
//MaterialSellmeier1 glass::getD263TECO_S1()
//{
//	return D263TECO_S1;
//}
//
////AF32ECO
//MaterialSellmeier1 glass::getAF32ECO_S1()
//{
//	return AF32ECO_S1;
//}

//KZFS12
MaterialSellmeier1 glass::getKZFS12_S1()
{
	return KZFS12_S1;
}

//PPK53
MaterialSellmeier1 glass::getPPK53_S1()
{
	return PPK53_S1;
}

//NLAF36
MaterialSellmeier1 glass::getNLAF36_S1()
{
	return NLAF36_S1;
}

//FK5HTI
MaterialSellmeier1 glass::getFK5HTI_S1()
{
	return FK5HTI_S1;
}

//LF5HTI
MaterialSellmeier1 glass::getLF5HTI_S1()
{
	return LF5HTI_S1;
}

//LLF1HTI
MaterialSellmeier1 glass::getLLF1HTI_S1()
{
	return LLF1HTI_S1;
}

//NBK7HTI
MaterialSellmeier1 glass::getNBK7HTI_S1()
{
	return NBK7HTI_S1;
}

//NFK58
MaterialSellmeier1 glass::getNFK58_S1()
{
	return NFK58_S1;
}


//BAFN10
MaterialSellmeier1 glass::getBAFN10_S1()
{
	return BAFN10_S1;
}
