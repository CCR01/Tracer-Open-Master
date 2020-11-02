#include "testPSF.h"

#include "..\..\Inport_Export_Data\Inport_Export_Data.h"
#include "..\..\LowLevelTracing\Math_LLT.h"
#include "..\..\Point-Spread Function\Point-Spread Function.h"
#include "..\..\Image\Images.h"


	// check methodes 
bool TestPSF::testPSF_superFct()
{
	std::vector<bool> testPSF_vec;

	// test 0
	bool checkTest0 = test0();
	testPSF_vec.push_back(checkTest0);


	bool returnCheck = Math::checkTrueOfVectorElements(testPSF_vec);
	return returnCheck;

}

// test 0
bool TestPSF::test0()
{
	std::vector<bool> testPSF_vec;
	std::string location = "../tests/testPSF/s0";

	// load OPD 63 63
	cv::Mat OPD00_63_63 = inportExportData::importTXTtoCVmat(location, "OPD0_63_63", 63, 63);
	float test00 = OPD00_63_63.at<float>(0, 0);
	float ref00 = 0.0;
	bool check00 = Math::compareTwoNumbers_tolerance(test00, ref00, 0.001);
	testPSF_vec.push_back(check00);

	// load OPD 127 127
	cv::Mat OPD00_127_127 = inportExportData::importTXTtoCVmat(location, "OPD0_127_127", 127, 127);

	// load OPD 255 255
	cv::Mat OPD00_255_255 = inportExportData::importTXTtoCVmat(location, "OPD0_255_255", 255, 255);

	// load OPD 511 511
	cv::Mat OPD00_511_511 = inportExportData::importTXTtoCVmat(location, "OPD0_511_511", 511, 511);

	PSF pfs_fft;
	cv::Mat psf0_63_63 = pfs_fft.calcPSF_FFT_P_Fct(OPD00_63_63);
	cv::Mat psf0_127_127 = pfs_fft.calcPSF_FFT_P_Fct(OPD00_127_127);
	cv::Mat psf0_255_255 = pfs_fft.calcPSF_FFT_P_Fct(OPD00_255_255);
	cv::Mat psf0_511_511 = pfs_fft.calcPSF_FFT_P_Fct(OPD00_511_511);
	
	inportExportData::exportCV_MatToExcel(OPD00_63_63, location, "PSF0");

	// show the pfs
	Images::showImage("psf0_63_63", psf0_63_63);
	Images::showImage("psf0_127_127", psf0_127_127);
	Images::showImage("psf0_255_255", psf0_255_255);
	Images::showImage("psf0_511_511", psf0_511_511);


	bool returnChecker = Math::checkTrueOfVectorElements(testPSF_vec);
	return returnChecker;
}