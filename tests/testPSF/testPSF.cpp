#include "testPSF.h"

#include "..\..\Inport_Export_Data\Inport_Export_Data.h"
#include "..\..\LowLevelTracing\Math_LLT.h"
#include "..\..\Point-Spread Function\Point-Spread Function.h"
#include "..\..\Image\Images.h"



#include "..\..\OpticalSystemElement\OpticalSystemElement.h"
// surface
#include "..\..\SurfaceElements\ApertureStopElement.h"
#include "..\..\SurfaceElements\PlanElement.h"
#include "..\..\SurfaceElements\SphericalElement.h"

// interactions
#include "..\..\LowLevelTracing\Interaction\Absorb_LLT.h"
#include "..\..\LowLevelTracing\Interaction\RefractedRay_LLT.h"
#include "..\..\LowLevelTracing\Interaction\DoNothingInteraction_LLT.h"

// glasses
#include "..\..\Glasses\Glasses.h"

// often use
#include "..\..\oftenUseNamespace\oftenUseNamespace.h"

// fill aperture stop with rays
#include "..\..\FillAptertureStop\FillApertureStop.h"

// ray Aiming
#include "..\..\RayAiming\RayAiming.h"

// OPD
#include "..\..\Analyse\OpticalPathDifference.h"

// Cardinal points
#include "..\..\Analyse\CardinalPoints.h"

// typedef
typedef std::shared_ptr< Element_CR > surfacePtr;
typedef std::shared_ptr< InteractionRay_LLT > interaction_ptr;

	// check methodes 
bool TestPSF::testPSF_superFct()
{
	std::vector<bool> testPSF_vec;



	// test 0
	bool checkTest0 = test0();
	testPSF_vec.push_back(checkTest0);
	// test 1
	bool checkTest1 = test1();
	testPSF_vec.push_back(checkTest1);
	// test 2
	bool checkTest2 = test2();
	testPSF_vec.push_back(checkTest2);
	// test 3
	bool checkTest3 = test3();
	testPSF_vec.push_back(checkTest3);
	// test 4
	bool checkTest4 = test4();
	testPSF_vec.push_back(checkTest4);
	// test 5
	bool checkTest5 = test5();
	testPSF_vec.push_back(checkTest5);
	// test 6
	bool checkTest6 = test6();
	testPSF_vec.push_back(checkTest6);



	bool returnCheck = Math::checkTrueOfVectorElements(testPSF_vec);
	return returnCheck;

}

bool TestPSF::test0()
{
	std::vector<bool> testPSF_vec;
	std::string location = "../tests/testPSF/s0";
	real refAirySize = 7.486;
	real toleranceAiryDisc = 1.0;
	PSF psf;
	real diameterExitPupil_mm = 4.0;
	real distanceEXP_Ima_mm = 22.222;
	real wavelength_nm = 550.0;



	// check OPD 64 64
	cv::Mat OPD00_64 = inportExportData::importTXTtoCVmat(location, "OPD_64_AiryDisc6,744", 64, 64);

	psf.setPaddingFactor(3);
	cv::Mat PSF00_64_P3 = psf.calcPSF_FFT_NEW(OPD00_64);
	Images::saveImage_normalized(location, "PSF00_64_P3", "png", PSF00_64_P3);
	psf.calcSizePerPixel_PSFAtImageSurface_µm(distanceEXP_Ima_mm, wavelength_nm, diameterExitPupil_mm, psf.getPaddingFactor());
	real airyDisc_64_P3 = calcSizeInnerDiscPSF(PSF00_64_P3, psf.getSizePerPixcelAtImaSurface_µm());
	bool checkPF_64_P3 = Math::compareTwoNumbers_tolerance(airyDisc_64_P3, refAirySize, toleranceAiryDisc);
	testPSF_vec.push_back(checkPF_64_P3);

	psf.setPaddingFactor(6);
	cv::Mat PSF00_64_P6 = psf.calcPSF_FFT_NEW(OPD00_64);
	Images::saveImage_normalized(location, "PSF00_64_P6", "png", PSF00_64_P6);
	psf.calcSizePerPixel_PSFAtImageSurface_µm(distanceEXP_Ima_mm, wavelength_nm, diameterExitPupil_mm, psf.getPaddingFactor());
	real airyDisc_64_P6 = calcSizeInnerDiscPSF(PSF00_64_P6, psf.getSizePerPixcelAtImaSurface_µm());
	bool checkPF_64_P6 = Math::compareTwoNumbers_tolerance(airyDisc_64_P6, refAirySize, toleranceAiryDisc);
	testPSF_vec.push_back(checkPF_64_P6);

	psf.setPaddingFactor(12);
	cv::Mat PSF00_64_P12 = psf.calcPSF_FFT_NEW(OPD00_64);
	Images::saveImage_normalized(location, "PSF00_64_P12", "png", PSF00_64_P12);
	psf.calcSizePerPixel_PSFAtImageSurface_µm(distanceEXP_Ima_mm, wavelength_nm, diameterExitPupil_mm, psf.getPaddingFactor());
	real airyDisc_64_P12 = calcSizeInnerDiscPSF(PSF00_64_P12, psf.getSizePerPixcelAtImaSurface_µm());
	bool checkPF_64_P12 = Math::compareTwoNumbers_tolerance(airyDisc_64_P12, refAirySize, toleranceAiryDisc);
	testPSF_vec.push_back(checkPF_64_P12);


	// check OPD 128 128
	cv::Mat OPD00_128 = inportExportData::importTXTtoCVmat(location, "OPD_128_AiryDisc6,744", 128, 128);

	psf.setPaddingFactor(3);
	cv::Mat PSF00_128_P3 = psf.calcPSF_FFT_NEW(OPD00_128);
	Images::saveImage_normalized(location, "PSF00_128_P3", "png", PSF00_128_P3);
	psf.calcSizePerPixel_PSFAtImageSurface_µm(distanceEXP_Ima_mm, wavelength_nm, diameterExitPupil_mm, psf.getPaddingFactor());
	real airyDisc_128_P3 = calcSizeInnerDiscPSF(PSF00_128_P3, psf.getSizePerPixcelAtImaSurface_µm());
	bool checkPF_128_P3 = Math::compareTwoNumbers_tolerance(airyDisc_128_P3, refAirySize, toleranceAiryDisc);
	testPSF_vec.push_back(checkPF_128_P3);

	psf.setPaddingFactor(6);
	cv::Mat PSF00_128_P6 = psf.calcPSF_FFT_NEW(OPD00_128);
	Images::saveImage_normalized(location, "PSF00_128_P6", "png", PSF00_128_P6);
	psf.calcSizePerPixel_PSFAtImageSurface_µm(distanceEXP_Ima_mm, wavelength_nm, diameterExitPupil_mm, psf.getPaddingFactor());
	real airyDisc_128_P6 = calcSizeInnerDiscPSF(PSF00_128_P6, psf.getSizePerPixcelAtImaSurface_µm());
	bool checkPF_128_P6 = Math::compareTwoNumbers_tolerance(airyDisc_128_P6, refAirySize, toleranceAiryDisc);
	testPSF_vec.push_back(checkPF_128_P6);

	psf.setPaddingFactor(12);
	cv::Mat PSF00_128_P12 = psf.calcPSF_FFT_NEW(OPD00_128);
	Images::saveImage_normalized(location, "PSF00_128_P12", "png", PSF00_128_P12);
	psf.calcSizePerPixel_PSFAtImageSurface_µm(distanceEXP_Ima_mm, wavelength_nm, diameterExitPupil_mm, psf.getPaddingFactor());
	real airyDisc_128_P12 = calcSizeInnerDiscPSF(PSF00_128_P12, psf.getSizePerPixcelAtImaSurface_µm());
	bool checkPF_128_P12 = Math::compareTwoNumbers_tolerance(airyDisc_128_P12, refAirySize, toleranceAiryDisc);
	testPSF_vec.push_back(checkPF_128_P12);


	// check OPD 256 256
	cv::Mat OPD011_256 = inportExportData::importTXTtoCVmat(location, "OPD_256_AiryDisc6,744", 256, 256);

	psf.setPaddingFactor(3);
	cv::Mat PSF011_256_P3 = psf.calcPSF_FFT_NEW(OPD011_256);
	Images::saveImage_normalized(location, "PSF011_256_P3", "png", PSF011_256_P3);
	psf.calcSizePerPixel_PSFAtImageSurface_µm(distanceEXP_Ima_mm, wavelength_nm, diameterExitPupil_mm, psf.getPaddingFactor());
	real airyDisc_256_P3 = calcSizeInnerDiscPSF(PSF011_256_P3, psf.getSizePerPixcelAtImaSurface_µm());
	bool checkPF_256_P3 = Math::compareTwoNumbers_tolerance(airyDisc_256_P3, refAirySize, toleranceAiryDisc);
	testPSF_vec.push_back(checkPF_256_P3);

	psf.setPaddingFactor(6);
	cv::Mat PSF011_256_P6 = psf.calcPSF_FFT_NEW(OPD011_256);
	Images::saveImage_normalized(location, "PSF011_256_P6", "png", PSF011_256_P6);
	psf.calcSizePerPixel_PSFAtImageSurface_µm(distanceEXP_Ima_mm, wavelength_nm, diameterExitPupil_mm, psf.getPaddingFactor());
	real airyDisc_256_P6 = calcSizeInnerDiscPSF(PSF011_256_P6, psf.getSizePerPixcelAtImaSurface_µm());
	bool checkPF_256_P6 = Math::compareTwoNumbers_tolerance(airyDisc_256_P6, refAirySize, toleranceAiryDisc);
	testPSF_vec.push_back(checkPF_256_P6);

	psf.setPaddingFactor(12);
	cv::Mat PSF011_256_P12 = psf.calcPSF_FFT_NEW(OPD011_256);
	Images::saveImage_normalized(location, "PSF011_256_P12", "png", PSF011_256_P12);
	psf.calcSizePerPixel_PSFAtImageSurface_µm(distanceEXP_Ima_mm, wavelength_nm, diameterExitPupil_mm, psf.getPaddingFactor());
	real airyDisc_256_P12 = calcSizeInnerDiscPSF(PSF011_256_P12, psf.getSizePerPixcelAtImaSurface_µm());
	bool checkPF_256_P12 = Math::compareTwoNumbers_tolerance(airyDisc_256_P12, refAirySize, toleranceAiryDisc);
	testPSF_vec.push_back(checkPF_256_P12);


	bool returnChecker = Math::checkTrueOfVectorElements(testPSF_vec);
	return returnChecker;
}

bool TestPSF::test1()
{
	std::vector<bool> testPSF_vec;
	std::string location = "../tests/testPSF/s1";


	real refAirySize = 29.82;
	real toleranceAiryDisc = 1.5;
	PSF psf;
	real diameterExitPupil_mm = 1.0;
	real distanceEXP_Ima_mm = 22.222;
	real wavelength_nm = 550.0;


	// check OPD 64 64
	cv::Mat OPD00_64 = inportExportData::importTXTtoCVmat(location, "OPD_64_AiryDisc29,82", 64, 64);


	psf.setPaddingFactor(6);
	cv::Mat PSF00_64_P6 = psf.calcPSF_FFT_NEW(OPD00_64);
	Images::saveImage_normalized(location, "PSF00_64_P6", "png", PSF00_64_P6);
	psf.calcSizePerPixel_PSFAtImageSurface_µm(distanceEXP_Ima_mm, wavelength_nm, diameterExitPupil_mm, psf.getPaddingFactor());
	real airyDisc_64_P6 = calcSizeInnerDiscPSF(PSF00_64_P6, psf.getSizePerPixcelAtImaSurface_µm());
	bool checkPF_64_P6 = Math::compareTwoNumbers_tolerance(airyDisc_64_P6, refAirySize, toleranceAiryDisc);
	testPSF_vec.push_back(checkPF_64_P6);

	psf.setPaddingFactor(12);
	cv::Mat PSF00_64_P12 = psf.calcPSF_FFT_NEW(OPD00_64);
	Images::saveImage_normalized(location, "PSF00_64_P12", "png", PSF00_64_P12);
	psf.calcSizePerPixel_PSFAtImageSurface_µm(distanceEXP_Ima_mm, wavelength_nm, diameterExitPupil_mm, psf.getPaddingFactor());
	real airyDisc_64_P12 = calcSizeInnerDiscPSF(PSF00_64_P12, psf.getSizePerPixcelAtImaSurface_µm());
	bool checkPF_64_P12 = Math::compareTwoNumbers_tolerance(airyDisc_64_P12, refAirySize, toleranceAiryDisc);
	testPSF_vec.push_back(checkPF_64_P12);


	// check OPD 128 128
	cv::Mat OPD00_128 = inportExportData::importTXTtoCVmat(location, "OPD_128_AiryDisc29,82", 128, 128);

	psf.setPaddingFactor(6);
	cv::Mat PSF00_128_P6 = psf.calcPSF_FFT_NEW(OPD00_128);
	Images::saveImage_normalized(location, "PSF00_128_P6", "png", PSF00_128_P6);
	psf.calcSizePerPixel_PSFAtImageSurface_µm(distanceEXP_Ima_mm, wavelength_nm, diameterExitPupil_mm, psf.getPaddingFactor());
	real airyDisc_128_P6 = calcSizeInnerDiscPSF(PSF00_128_P6, psf.getSizePerPixcelAtImaSurface_µm());
	bool checkPF_128_P6 = Math::compareTwoNumbers_tolerance(airyDisc_128_P6, refAirySize, toleranceAiryDisc);
	testPSF_vec.push_back(checkPF_128_P6);

	psf.setPaddingFactor(12);
	cv::Mat PSF00_128_P12 = psf.calcPSF_FFT_NEW(OPD00_128);
	Images::saveImage_normalized(location, "PSF00_128_P12", "png", PSF00_128_P12);
	psf.calcSizePerPixel_PSFAtImageSurface_µm(distanceEXP_Ima_mm, wavelength_nm, diameterExitPupil_mm, psf.getPaddingFactor());
	real airyDisc_128_P12 = calcSizeInnerDiscPSF(PSF00_128_P12, psf.getSizePerPixcelAtImaSurface_µm());
	bool checkPF_128_P12 = Math::compareTwoNumbers_tolerance(airyDisc_128_P12, refAirySize, toleranceAiryDisc);
	testPSF_vec.push_back(checkPF_128_P12);


	// check OPD 256 256
	cv::Mat OPD00_256 = inportExportData::importTXTtoCVmat(location, "OPD_256_AiryDisc29,82", 256, 256);

	psf.setPaddingFactor(6);
	cv::Mat PSF00_256_P6 = psf.calcPSF_FFT_NEW(OPD00_256);
	Images::saveImage_normalized(location, "PSF00_256_P6", "png", PSF00_256_P6);
	psf.calcSizePerPixel_PSFAtImageSurface_µm(distanceEXP_Ima_mm, wavelength_nm, diameterExitPupil_mm, psf.getPaddingFactor());
	real airyDisc_256_P6 = calcSizeInnerDiscPSF(PSF00_256_P6, psf.getSizePerPixcelAtImaSurface_µm());
	bool checkPF_256_P6 = Math::compareTwoNumbers_tolerance(airyDisc_256_P6, refAirySize, toleranceAiryDisc);
	testPSF_vec.push_back(checkPF_256_P6);

	psf.setPaddingFactor(12);
	cv::Mat PSF00_256_P12 = psf.calcPSF_FFT_NEW(OPD00_256);
	Images::saveImage_normalized(location, "PSF00_256_P12", "png", PSF00_256_P12);
	psf.calcSizePerPixel_PSFAtImageSurface_µm(distanceEXP_Ima_mm, wavelength_nm, diameterExitPupil_mm, psf.getPaddingFactor());
	real airyDisc_256_P12 = calcSizeInnerDiscPSF(PSF00_256_P12, psf.getSizePerPixcelAtImaSurface_µm());
	bool checkPF_256_P12 = Math::compareTwoNumbers_tolerance(airyDisc_256_P12, refAirySize, toleranceAiryDisc);
	testPSF_vec.push_back(checkPF_256_P12);


	bool returnChecker = Math::checkTrueOfVectorElements(testPSF_vec);
	return returnChecker;
}

// test 2
bool TestPSF::test2()
{
	std::vector<bool> testPSF_vec;
	std::string location = "../tests/testPSF/s2";


	real refAirySize = 11.116;
	real toleranceAiryDisc = 1.5;
	PSF psf;
	real diameterExitPupil_mm = 18.0;
	real distanceEXP_Ima_mm = 40.0;
	real wavelength_nm = 2000.0;


	// check OPD 64 64
	cv::Mat OPD00_64 = inportExportData::importTXTtoCVmat(location, "OPD_64_AiryDisc11,116", 64, 64);


	psf.setPaddingFactor(6);
	cv::Mat PSF00_64_P6 = psf.calcPSF_FFT_NEW(OPD00_64);
	Images::saveImage_normalized(location, "PSF00_64_P6", "png", PSF00_64_P6);
	psf.calcSizePerPixel_PSFAtImageSurface_µm(distanceEXP_Ima_mm, wavelength_nm, diameterExitPupil_mm, psf.getPaddingFactor());
	real airyDisc_64_P6 = calcSizeInnerDiscPSF(PSF00_64_P6, psf.getSizePerPixcelAtImaSurface_µm());
	bool checkPF_64_P6 = Math::compareTwoNumbers_tolerance(airyDisc_64_P6, refAirySize, toleranceAiryDisc);
	testPSF_vec.push_back(checkPF_64_P6);

	psf.setPaddingFactor(12);
	cv::Mat PSF00_64_P12 = psf.calcPSF_FFT_NEW(OPD00_64);
	Images::saveImage_normalized(location, "PSF00_64_P12", "png", PSF00_64_P12);
	psf.calcSizePerPixel_PSFAtImageSurface_µm(distanceEXP_Ima_mm, wavelength_nm, diameterExitPupil_mm, psf.getPaddingFactor());
	real airyDisc_64_P12 = calcSizeInnerDiscPSF(PSF00_64_P12, psf.getSizePerPixcelAtImaSurface_µm());
	bool checkPF_64_P12 = Math::compareTwoNumbers_tolerance(airyDisc_64_P12, refAirySize, toleranceAiryDisc);
	testPSF_vec.push_back(checkPF_64_P12);


	// check OPD 128 128
	cv::Mat OPD00_128 = inportExportData::importTXTtoCVmat(location, "OPD_128_AiryDisc11,116", 128, 128);

	psf.setPaddingFactor(6);
	cv::Mat PSF00_128_P6 = psf.calcPSF_FFT_NEW(OPD00_128);
	Images::saveImage_normalized(location, "PSF00_128_P6", "png", PSF00_128_P6);
	psf.calcSizePerPixel_PSFAtImageSurface_µm(distanceEXP_Ima_mm, wavelength_nm, diameterExitPupil_mm, psf.getPaddingFactor());
	real airyDisc_128_P6 = calcSizeInnerDiscPSF(PSF00_128_P6, psf.getSizePerPixcelAtImaSurface_µm());
	bool checkPF_128_P6 = Math::compareTwoNumbers_tolerance(airyDisc_128_P6, refAirySize, toleranceAiryDisc);
	testPSF_vec.push_back(checkPF_128_P6);

	psf.setPaddingFactor(12);
	cv::Mat PSF00_128_P12 = psf.calcPSF_FFT_NEW(OPD00_128);
	Images::saveImage_normalized(location, "PSF00_128_P12", "png", PSF00_128_P12);
	psf.calcSizePerPixel_PSFAtImageSurface_µm(distanceEXP_Ima_mm, wavelength_nm, diameterExitPupil_mm, psf.getPaddingFactor());
	real airyDisc_128_P12 = calcSizeInnerDiscPSF(PSF00_128_P12, psf.getSizePerPixcelAtImaSurface_µm());
	bool checkPF_128_P12 = Math::compareTwoNumbers_tolerance(airyDisc_128_P12, refAirySize, toleranceAiryDisc);
	testPSF_vec.push_back(checkPF_128_P12);


	// check OPD 256 256
	cv::Mat OPD00_256 = inportExportData::importTXTtoCVmat(location, "OPD_256_AiryDisc11,116", 256, 256);

	psf.setPaddingFactor(6);
	cv::Mat PSF00_256_P6 = psf.calcPSF_FFT_NEW(OPD00_256);
	Images::saveImage_normalized(location, "PSF00_256_P6", "png", PSF00_256_P6);
	psf.calcSizePerPixel_PSFAtImageSurface_µm(distanceEXP_Ima_mm, wavelength_nm, diameterExitPupil_mm, psf.getPaddingFactor());
	real airyDisc_256_P6 = calcSizeInnerDiscPSF(PSF00_256_P6, psf.getSizePerPixcelAtImaSurface_µm());
	bool checkPF_256_P6 = Math::compareTwoNumbers_tolerance(airyDisc_256_P6, refAirySize, toleranceAiryDisc);
	testPSF_vec.push_back(checkPF_256_P6);

	psf.setPaddingFactor(12);
	cv::Mat PSF00_256_P12 = psf.calcPSF_FFT_NEW(OPD00_256);
	Images::saveImage_normalized(location, "PSF00_256_P12", "png", PSF00_256_P12);
	psf.calcSizePerPixel_PSFAtImageSurface_µm(distanceEXP_Ima_mm, wavelength_nm, diameterExitPupil_mm, psf.getPaddingFactor());
	real airyDisc_256_P12 = calcSizeInnerDiscPSF(PSF00_256_P12, psf.getSizePerPixcelAtImaSurface_µm());
	bool checkPF_256_P12 = Math::compareTwoNumbers_tolerance(airyDisc_256_P12, refAirySize, toleranceAiryDisc);
	testPSF_vec.push_back(checkPF_256_P12);


	bool returnChecker = Math::checkTrueOfVectorElements(testPSF_vec);
	return returnChecker;
}

// test 3
bool TestPSF::test3()
{
	std::vector<bool> testPSF_vec;
	std::string location = "../tests/testPSF/s3";


	real refAirySize = 48.8;
	real toleranceAiryDisc = 1.5;
	PSF psf;
	real diameterExitPupil_mm = 0.343;
	real distanceEXP_Ima_mm = 68.571;
	real wavelength_nm = 100.0;


	// check OPD 64 64
	cv::Mat OPD00_64 = inportExportData::importTXTtoCVmat(location, "OPD_64_AiryDisc48,8", 64, 64);


	psf.setPaddingFactor(12);
	cv::Mat PSF00_64_P12 = psf.calcPSF_FFT_NEW(OPD00_64);
	Images::saveImage_normalized(location, "PSF00_64_P12", "png", PSF00_64_P12);
	psf.calcSizePerPixel_PSFAtImageSurface_µm(distanceEXP_Ima_mm, wavelength_nm, diameterExitPupil_mm, psf.getPaddingFactor());
	real airyDisc_64_P12 = calcSizeInnerDiscPSF(PSF00_64_P12, psf.getSizePerPixcelAtImaSurface_µm());
	bool checkPF_64_P12 = Math::compareTwoNumbers_tolerance(airyDisc_64_P12, refAirySize, toleranceAiryDisc);
	testPSF_vec.push_back(checkPF_64_P12);


	// check OPD 128 128
	cv::Mat OPD00_128 = inportExportData::importTXTtoCVmat(location, "OPD_128_AiryDisc48,8", 128, 128);

	psf.setPaddingFactor(12);
	cv::Mat PSF00_128_P12 = psf.calcPSF_FFT_NEW(OPD00_128);
	Images::saveImage_normalized(location, "PSF00_128_P12", "png", PSF00_128_P12);
	psf.calcSizePerPixel_PSFAtImageSurface_µm(distanceEXP_Ima_mm, wavelength_nm, diameterExitPupil_mm, psf.getPaddingFactor());
	real airyDisc_128_P12 = calcSizeInnerDiscPSF(PSF00_128_P12, psf.getSizePerPixcelAtImaSurface_µm());
	bool checkPF_128_P12 = Math::compareTwoNumbers_tolerance(airyDisc_128_P12, refAirySize, toleranceAiryDisc);
	testPSF_vec.push_back(checkPF_128_P12);


	// check OPD 256 256
	cv::Mat OPD00_256 = inportExportData::importTXTtoCVmat(location, "OPD_256_AiryDisc48,8", 256, 256);

	psf.setPaddingFactor(12);
	cv::Mat PSF00_256_P12 = psf.calcPSF_FFT_NEW(OPD00_256);
	Images::saveImage_normalized(location, "PSF00_256_P12", "png", PSF00_256_P12);
	psf.calcSizePerPixel_PSFAtImageSurface_µm(distanceEXP_Ima_mm, wavelength_nm, diameterExitPupil_mm, psf.getPaddingFactor());
	real airyDisc_256_P12 = calcSizeInnerDiscPSF(PSF00_256_P12, psf.getSizePerPixcelAtImaSurface_µm());
	bool checkPF_256_P12 = Math::compareTwoNumbers_tolerance(airyDisc_256_P12, refAirySize, toleranceAiryDisc);
	testPSF_vec.push_back(checkPF_256_P12);


	bool returnChecker = Math::checkTrueOfVectorElements(testPSF_vec);
	return returnChecker;
}

// test 4
bool TestPSF::test4()
{
	std::vector<bool> testPSF_vec;
	std::string location = "../tests/testPSF/s4";
	real distanceEXP_ImaSurface_mm = 78.127;
	real wavelength_nm = 550.0;
	real EXPD_mm = 11.672;
	real tolerance = 1.0;

	// load OPD 64 64
	cv::Mat OPD00_64_64 = inportExportData::importTXTtoCVmat(location, "OPD0_64_64", 64, 64);

	// load OPD 128 12
	cv::Mat OPD00_128_128 = inportExportData::importTXTtoCVmat(location, "OPD0_128_128", 128, 128);

	// load OPD 256 256
	cv::Mat OPD00_256_256 = inportExportData::importTXTtoCVmat(location, "OPD0_256_256", 256, 256);
	
	// load OPD 512 512
	cv::Mat OPD00_512_512 = inportExportData::importTXTtoCVmat(location, "OPD0_512_512", 512, 512);

	PSF psf;

	// check 64
	cv::Mat PSF0_64_exitPupil = psf.calcPSF_FFT_NEW(OPD00_64_64);
	real targetPixelSize_64_1µm = 1.0;
	cv::Mat normPSF_targetPixelSize_64 = psf.normPSFtoTargetPixelSize_AtImaSurface(PSF0_64_exitPupil, targetPixelSize_64_1µm, distanceEXP_ImaSurface_mm, wavelength_nm, EXPD_mm, psf.getPaddingFactor());
	cv::Mat refPSF0_64_delta1µm = inportExportData::importTXTtoCVmat(location, "refPSF0_64_64_delta1µm", 64, 64);
	real sumRefPSF0_64_delta1µm = cv::sum(refPSF0_64_delta1µm)[0];
	Images::saveImage_normalized(location, "normPSF_targetPixelSize_64","png", normPSF_targetPixelSize_64);
	Images::saveImage_normalized(location, "refPSF0_64_delta1µm","png", refPSF0_64_delta1µm);
	real sizeInnerDisc_normPSF_64 = calcSizeInnerDiscPSF(normPSF_targetPixelSize_64, targetPixelSize_64_1µm);
	real sizeInnerDisc_refPSF_64 = calcSizeInnerDiscPSF(refPSF0_64_delta1µm, targetPixelSize_64_1µm);
	bool checkPSF0_64 = Math::compareTwoNumbers_tolerance(sizeInnerDisc_normPSF_64, sizeInnerDisc_refPSF_64, tolerance);
	testPSF_vec.push_back(checkPSF0_64);

	// check 128
	cv::Mat PSF0_128_exitPupil = psf.calcPSF_FFT_NEW(OPD00_128_128);
	real targetPixelSize_128_03µm = 0.3;
	cv::Mat normPSF_targetPixelSize_128 = psf.normPSFtoTargetPixelSize_AtImaSurface(PSF0_128_exitPupil, targetPixelSize_128_03µm, distanceEXP_ImaSurface_mm, wavelength_nm, EXPD_mm, psf.getPaddingFactor());
	cv::Mat refPSF0_128_delta03µm = inportExportData::importTXTtoCVmat(location, "refPSF0_128_128_delta0,3µm", 128, 128);
	real sumRefPSF0_128_delta03µm = cv::sum(refPSF0_128_delta03µm)[0];
	Images::saveImage_normalized(location, "normPSF_targetPixelSize_128", "png", normPSF_targetPixelSize_128);
	Images::saveImage_normalized(location, "refPSF0_128_delta0,3µm", "png", refPSF0_128_delta03µm);
	real sizeInnerDisc_normPSF_128 = calcSizeInnerDiscPSF(normPSF_targetPixelSize_128, targetPixelSize_128_03µm);
	real sizeInnerDisc_refPSF_128 = calcSizeInnerDiscPSF(refPSF0_128_delta03µm, targetPixelSize_128_03µm);
	bool checkPSF0_128 = Math::compareTwoNumbers_tolerance(sizeInnerDisc_normPSF_128, sizeInnerDisc_refPSF_128, tolerance);
	testPSF_vec.push_back(checkPSF0_128);

	// check 256
	cv::Mat PSF0_256_exitPupil = psf.calcPSF_FFT_NEW(OPD00_256_256);
	real targetPixelSize_256_15µm = 1.5;
	cv::Mat normPSF_targetPixelSize_256 = psf.normPSFtoTargetPixelSize_AtImaSurface(PSF0_256_exitPupil, targetPixelSize_256_15µm, distanceEXP_ImaSurface_mm, wavelength_nm, EXPD_mm, psf.getPaddingFactor());
	cv::Mat refPSF0_256_delta15µm = inportExportData::importTXTtoCVmat(location, "refPSF0_256_256_delta1,5µm", 256, 256);
	real sumRefPSF0_256_delta15µm = cv::sum(refPSF0_256_delta15µm)[0];
	Images::saveImage_normalized(location, "normPSF_targetPixelSize_256", "png", normPSF_targetPixelSize_256);
	Images::saveImage_normalized(location, "refPSF0_256_delta1,5µm", "png", refPSF0_256_delta15µm);
	real sizeInnerDisc_normPSF_256 = calcSizeInnerDiscPSF(normPSF_targetPixelSize_256, targetPixelSize_256_15µm);
	real sizeInnerDisc_refPSF_256 = calcSizeInnerDiscPSF(refPSF0_256_delta15µm, targetPixelSize_256_15µm);
	bool checkPSF0_256 = Math::compareTwoNumbers_tolerance(sizeInnerDisc_normPSF_256, sizeInnerDisc_refPSF_256, tolerance);
	testPSF_vec.push_back(checkPSF0_256);

	// check 512
	cv::Mat PSF0_512_exitPupil = psf.calcPSF_FFT_NEW(OPD00_512_512);
	real targetPixelSize_512_0123µm = 0.123;
	cv::Mat normPSF_targetPixelSize_512 = psf.normPSFtoTargetPixelSize_AtImaSurface(PSF0_512_exitPupil, targetPixelSize_512_0123µm, distanceEXP_ImaSurface_mm, wavelength_nm, EXPD_mm, psf.getPaddingFactor());
	cv::Mat refPSF0_512_delta0123µm = inportExportData::importTXTtoCVmat(location, "refPSF0_512_512_delta0,123µm", 512, 512);
	Images::saveImage_normalized(location, "normPSF_targetPixelSize_512", "png", normPSF_targetPixelSize_512);
	Images::saveImage_normalized(location, "refPSF0_512_delta0,123µm", "png", refPSF0_512_delta0123µm);
	real sizeInnerDisc_normPSF_512 = calcSizeInnerDiscPSF(normPSF_targetPixelSize_512, targetPixelSize_512_0123µm);
	real sizeInnerDisc_refPSF_512 = calcSizeInnerDiscPSF(refPSF0_512_delta0123µm, targetPixelSize_512_0123µm);
	bool checkPSF0_512 = Math::compareTwoNumbers_tolerance(sizeInnerDisc_normPSF_512, sizeInnerDisc_refPSF_512, tolerance);
	testPSF_vec.push_back(checkPSF0_512);

	if(false)
	{
		// show the norm and ref PFS

		// 64
		Images::showImage_inputReal_normTheImage("normPSF_targetPixelSize_64", normPSF_targetPixelSize_64);
		Images::showImage_inputReal_normTheImage("refPSF0_64_delta1µm", refPSF0_64_delta1µm);
		
		// 128
		Images::showImage_inputReal_normTheImage("normPSF_targetPixelSize_128", normPSF_targetPixelSize_128);
		Images::showImage_inputReal_normTheImage("refPSF0_128_delta0,3µm", refPSF0_128_delta03µm);

		// 256
		Images::showImage_inputReal_normTheImage("normPSF_targetPixelSize_256", normPSF_targetPixelSize_256);
		Images::showImage_inputReal_normTheImage("refPSF0_256_delta1", refPSF0_256_delta15µm);

		// 512		
		Images::showImage_inputReal_normTheImage("normPSF_targetPixelSize_512", normPSF_targetPixelSize_512);
		Images::showImage_inputReal_normTheImage("refPSF0_512_delta0123µm", refPSF0_512_delta0123µm);

	}



	bool returnChecker = Math::checkTrueOfVectorElements(testPSF_vec);
	return returnChecker;
}



// test 5
bool TestPSF::test5()
{
	std::vector<bool> testPSF_vec{};
	std::string location = "../tests/testPSF/s5";
	real toleranceRMS = 0.5;
	real tolerancePSF_disc = 2.0;

	DoNothingInteraction_LLT doNothing{};
	RefractedRay_LLT refrac{};
	Absorb_LLT absorb{};

	// load glass catalog
	glass glasses;
	glasses.loadGlassCatalog_Schott();

	// test system
	// build the optical system
	ApertureStopElement AperStop0(/* semi height*/1.0, /*point*/{ 0.0,0.0,20.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAir());
	SphericalElement Sphere1(/*radius*/ 28.499, /*semi height*/ 5.0, /*point*/{ 0.0,0.0,25.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNBK7_S1());
	SphericalElement Sphere2(/*radius*/ 18.6536584, /*semi height*/ 5.0, /*point*/{ 0.0,0.0,35.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNBK7_S1());
	SphericalElement Sphere3(/*radius*/ 11.89971042, /*semi height*/ 5.0, /*point*/{ 0.0,0.0,45.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNBAF10_S1());
	SphericalElement Sphere4(/*radius*/ 67.7882275, /*semi height*/ 5.0, /*point*/{ 0.0,0.0,55.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getNBAF10_S1(), /*refractive index B*/glasses.getAir());
	PlanElement Plan5(/*semi height*/ 5.0, /*point*/{ 0.0,0.0,65.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAir(), /*refractive index B*/ glasses.getAir());
	
	surfacePtr AperStop_ptr = AperStop0.clone();
	surfacePtr Sphere1_ptr = Sphere1.clone();
	surfacePtr Sphere2_ptr = Sphere2.clone();
	surfacePtr Sphere3_ptr = Sphere3.clone();
	surfacePtr Sphere4_ptr = Sphere4.clone();
	surfacePtr Plan5_ptr = Plan5.clone();
	
	std::vector<surfacePtr> opticalSystem_ptr{ AperStop_ptr, Sphere1_ptr, Sphere2_ptr, Sphere3_ptr, Sphere4_ptr, Plan5_ptr };
	std::vector<interaction_ptr> interactions_ptr{ doNothing.clone(), refrac.clone(), refrac.clone(), refrac.clone(), refrac.clone(), absorb.clone() };
	
	//	build optical system
	OpticalSystemElement optSysEle(opticalSystem_ptr, interactions_ptr);
	
	// test the system
	std::vector<VectorStructR3> objectPoints{ {0.0,0.0,0.0}, {0.0,1.0,0.0}, {1.0,1.0,0.0} };
	real wavelength_550 = 550.0;
	std::vector<real> wavelength550_vec{ wavelength_550 };
	std::vector<real> rms_Zemax{ 1.486,7.429,12.642 };
	bool testStart = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSysEle, objectPoints, wavelength550_vec, rms_Zemax, 0.01, compareTOM_Zemax::comEqual);
	testPSF_vec.push_back(testStart);
	
	
	
			
	
	// *** PSF 550 128 0
	unsigned int sizeMatrixOPD_128 = 128;
	PSF psf0_550_128{};
	real targetPixelSize_128_05µm = 0.5;
	psf0_550_128.setTargetPixelSize_µm(targetPixelSize_128_05µm);
	psf0_550_128.calculatePSF_superFunction(optSysEle, wavelength_550, { 0.0,0.0,0.0 });
	
	// check OPD
	cv::Mat globalOPD_0_550_128 = psf0_550_128.getGlobalOPD_deepCopy();
	cv::Mat normGlobalOPD_0_550_128;
	cv::normalize(globalOPD_0_550_128, normGlobalOPD_0_550_128, 0.0, 255.0, cv::NORM_MINMAX);
	Images::saveImage_normalized(location, "globalOPD_0_550_128", "png", normGlobalOPD_0_550_128);
	// sample up global OPD
	cv::Mat globalOPD_0_550_128_sampledUp = psf0_550_128.getGlobalOPD_sampledUP_deepCopy();
	cv::Mat normGlobalOPD_0_550_128_sampledUp;
	cv::normalize(globalOPD_0_550_128_sampledUp, normGlobalOPD_0_550_128_sampledUp, 0.0, 255.0, cv::NORM_MINMAX);
	Images::saveImage_normalized(location, "normGlobalOPD_0_550_128_sampledUp", "png", normGlobalOPD_0_550_128_sampledUp);
	// ***
		
	// check PSF
	cv::Mat normPSF_targetPixelSize_550_128 = psf0_550_128.getPSF_imaSurface_targetSize();
	cv::Mat refPSF0_550_128_delta05µm = inportExportData::importTXTtoCVmat(location, "refPSF0_128_delta0,5µm", sizeMatrixOPD_128, sizeMatrixOPD_128);
	Images::saveImage_normalized(location, "normPSF_targetPixelSize_550", "png", normPSF_targetPixelSize_550_128);
	Images::saveImage_normalized(location, "refPSF0_128_delta05µm,123µm", "png", refPSF0_550_128_delta05µm);
	real sizeInnerDisc_normPSF_550_128 = calcSizeInnerDiscPSF(normPSF_targetPixelSize_550_128, targetPixelSize_128_05µm);
	real sizeInnerDisc_refPSF_550_128 = calcSizeInnerDiscPSF(refPSF0_550_128_delta05µm, targetPixelSize_128_05µm);
	bool checkPSF0_550_128 = Math::compareTwoNumbers_tolerance(sizeInnerDisc_normPSF_550_128, sizeInnerDisc_refPSF_550_128, tolerancePSF_disc);
	testPSF_vec.push_back(checkPSF0_550_128);
	// **

	
	
	//
	//// *** PSF11 550 512 
	unsigned int sizeMatrixOPD_512 = 512;
	PSF psf11_550_512{};
	real targetPixelSize_512_01µm = 0.1;
	psf11_550_512.setMaxInteraBilinInterpolation(10);
	psf11_550_512.setPaddingFactor(6);
	psf11_550_512.setRayDensity(60);
	psf11_550_512.setTargetPixelSize_µm(targetPixelSize_512_01µm);
	psf11_550_512.setSizeMatrixOPD(sizeMatrixOPD_512);
	psf11_550_512.calculatePSF_superFunction(optSysEle, wavelength_550, { 1.0,1.0,0.0 });

	// check OPD
	cv::Mat globalOPD_0_550_512 = psf11_550_512.getGlobalOPD_deepCopy();
	cv::Mat normGlobalOPD_0_550_512;
	cv::normalize(globalOPD_0_550_512, normGlobalOPD_0_550_512, 0.0, 255.0, cv::NORM_MINMAX);
	Images::saveImage_normalized(location, "normGlobalOPD_0_550_512", "png", normGlobalOPD_0_550_512);
	cv::Mat globalOPD_0_550_512_sampledUp = psf11_550_512.getGlobalOPD_sampledUP_deepCopy();
	cv::Mat normGlobalOPD_0_550_512_sampledUp;
	cv::normalize(globalOPD_0_550_512_sampledUp, normGlobalOPD_0_550_512_sampledUp, 0.0, 255.0, cv::NORM_MINMAX);
	Images::saveImage_normalized(location, "normGlobalOPD_0_550_sampledUp", "png", normGlobalOPD_0_550_512_sampledUp);
	// ***
	
	
	// check PSF
	cv::Mat normPSF_targetPixelSize_550_512 = psf11_550_512.getPSF_imaSurface_targetSize();
	cv::Mat refPSF0_550_512_delta01µm = inportExportData::importTXTtoCVmat(location, "refPSF11_512_delta0,1µm", sizeMatrixOPD_512, sizeMatrixOPD_512);
	Images::saveImage_normalized(location, "normPSF_targetPixelSize_550_512", "png", normPSF_targetPixelSize_550_512);
	Images::saveImage_normalized(location, "refPSF0_550_512_delta01µm", "png", refPSF0_550_512_delta01µm);
	real sizeInnerDisc_normPSF_550_512 = calcSizeInnerDiscPSF(normPSF_targetPixelSize_550_512, targetPixelSize_512_01µm);
	std::cout << "calc size: " << sizeInnerDisc_normPSF_550_512 << std::endl;
	real sizeInnerDisc_refPSF_550_512 = calcSizeInnerDiscPSF(refPSF0_550_512_delta01µm, targetPixelSize_512_01µm);
	std::cout << "ref size: " << sizeInnerDisc_refPSF_550_512 << std::endl;
	bool checkPSF0_512 = Math::compareTwoNumbers_tolerance(sizeInnerDisc_normPSF_550_512, sizeInnerDisc_refPSF_550_512, tolerancePSF_disc + 4);
	testPSF_vec.push_back(checkPSF0_512);
	// ***

	bool returnChecker = Math::checkTrueOfVectorElements(testPSF_vec);
	return returnChecker;
}


// test 6
bool TestPSF::test6()
{
	std::vector<bool> testPSF_vec{};
	std::string location = "../tests/testPSF/s6";
	real toleranceRMS = 0.1;
	real tolerancePSF_disc = 2.0;

	DoNothingInteraction_LLT doNothing{};
	RefractedRay_LLT refrac{};
	Absorb_LLT absorb{};

	// load glass catalog
	glass glasses;
	glasses.loadGlassCatalog_Schott();

	// test system
	// build the optical system
	ApertureStopElement AperStop0(/* semi height*/1.0, /*point*/{ 0.0,0.0,20.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAir());
	SphericalElement Sphere1(/*radius*/ 30.0, /*semi height*/ 5.0, /*point*/{ 0.0,0.0,25.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNBK7_S1());
	SphericalElement Sphere2(/*radius*/ 15.0, /*semi height*/ 5.0, /*point*/{ 0.0,0.0,35.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNBK7_S1());
	SphericalElement Sphere3(/*radius*/ 13.98472992, /*semi height*/ 5.0, /*point*/{ 0.0,0.0,45.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNBAF10_S1());
	SphericalElement Sphere4(/*radius*/ 155.9420692, /*semi height*/ 5.0, /*point*/{ 0.0,0.0,55.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getNBAF10_S1(), /*refractive index B*/glasses.getAir());
	PlanElement Plan5(/*semi height*/ 5.0, /*point*/{ 0.0,0.0,65.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAir(), /*refractive index B*/ glasses.getAir());

	surfacePtr AperStop_ptr = AperStop0.clone();
	surfacePtr Sphere1_ptr = Sphere1.clone();
	surfacePtr Sphere2_ptr = Sphere2.clone();
	surfacePtr Sphere3_ptr = Sphere3.clone();
	surfacePtr Sphere4_ptr = Sphere4.clone();
	surfacePtr Plan5_ptr = Plan5.clone();

	std::vector<surfacePtr> opticalSystem_ptr{ AperStop_ptr, Sphere1_ptr, Sphere2_ptr, Sphere3_ptr, Sphere4_ptr, Plan5_ptr };
	std::vector<interaction_ptr> interactions_ptr{ doNothing.clone(), refrac.clone(), refrac.clone(), refrac.clone(), refrac.clone(), absorb.clone() };

	//	build optical system
	OpticalSystemElement optSysEle(opticalSystem_ptr, interactions_ptr);

	// test the system
	std::vector<VectorStructR3> objectPoints{ {1.0,1.0,0.0}, {-1.0,1.0,0.0}, {-1.0,-1.0,0.0} , {1.0,-1.0,0.0}, {0.0,0.0,0.0} };
	real wavelength_800 = 800.0;
	std::vector<real> wavelength800_vec{ wavelength_800 };
	std::vector<real> rms_Zemax{ 7.696,7.696,7.696, 7.696, 2.140 };
	bool testStart = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSysEle, objectPoints, wavelength800_vec, rms_Zemax, 0.01, compareTOM_Zemax::comEqual);
	testPSF_vec.push_back(testStart);

	CardinalPoints carPoints(optSysEle, wavelength_800, objectPoint_inf_obj::obj);
	real distanceEXP_ImaSurface_mm = carPoints.getEXPP_lastSurface();
	real refDisEXP_lastSurface = 76.31034845;
	testPSF_vec.push_back(Math::compareTwoNumbers_tolerance(distanceEXP_ImaSurface_mm, refDisEXP_lastSurface, toleranceRMS));
	real EXPD_mm = carPoints.getEXPD();
	real refEXPD = 11.50100086;
	testPSF_vec.push_back(Math::compareTwoNumbers_tolerance(EXPD_mm, refEXPD, toleranceRMS));


	
	
	//// *** PSF 800 128 
	unsigned int sizeMatrixOPD_128 = 128;
	PSF psf_800_128{};
	real targetPixelSize_05µm = 0.5;
	psf_800_128.setMaxInteraBilinInterpolation(4);
	psf_800_128.setPaddingFactor(6);
	psf_800_128.setRayDensity(30);
	psf_800_128.setTargetPixelSize_µm(targetPixelSize_05µm);
	psf_800_128.setSizeMatrixOPD(sizeMatrixOPD_128);

	// 1 1
	psf_800_128.calculatePSF_superFunction(optSysEle, wavelength_800, { 1.0,1.0,0.0 });
	// check
	cv::Mat normPSF_05_11 = psf_800_128.getPSF_imaSurface_targetSize();
	cv::Mat refNomrPSF_05_11 = inportExportData::importTXTtoCVmat(location, "refNomrPSF_05_11", sizeMatrixOPD_128, sizeMatrixOPD_128);
	Images::saveImage_normalized(location, "normPSF_05_11", "png", normPSF_05_11);
	Images::saveImage_normalized(location, "refNomrPSF_05_11", "png", refNomrPSF_05_11);
	real sizeInnerDisc_normPSF_05_11 = calcSizeInnerDiscPSF(normPSF_05_11, targetPixelSize_05µm);
	real sizeInnerDisc_refPSF_05_11 = calcSizeInnerDiscPSF(refNomrPSF_05_11, targetPixelSize_05µm);
	bool checkPSF_11 = Math::compareTwoNumbers_tolerance(sizeInnerDisc_normPSF_05_11, sizeInnerDisc_refPSF_05_11, tolerancePSF_disc);
	testPSF_vec.push_back(checkPSF_11);

	// neg 1 1
	psf_800_128.calculatePSF_superFunction(optSysEle, wavelength_800, { -1.0,1.0,0.0 });
	// check
	cv::Mat normPSF_05_neg11 = psf_800_128.getPSF_imaSurface_targetSize();
	cv::Mat refNomrPSF_05_neg11 = inportExportData::importTXTtoCVmat(location, "refNomrPSF_05_neg11", sizeMatrixOPD_128, sizeMatrixOPD_128);
	Images::saveImage_normalized(location, "normPSF_05_neg11", "png", normPSF_05_neg11);
	Images::saveImage_normalized(location, "refNomrPSF_05_neg11", "png", refNomrPSF_05_neg11);
	real sizeInnerDisc_normPSF_05_neg11 = calcSizeInnerDiscPSF(normPSF_05_neg11, targetPixelSize_05µm);
	real sizeInnerDisc_refPSF_05_neg11 = calcSizeInnerDiscPSF(refNomrPSF_05_neg11, targetPixelSize_05µm);
	bool checkPSF_neg11 = Math::compareTwoNumbers_tolerance(sizeInnerDisc_normPSF_05_neg11, sizeInnerDisc_refPSF_05_neg11, tolerancePSF_disc);
	testPSF_vec.push_back(checkPSF_neg11);

	// neg 1 neg 1
	psf_800_128.calculatePSF_superFunction(optSysEle, wavelength_800, { -1.0,-1.0,0.0 });
	// check
	cv::Mat normPSF_05_neg1neg1 = psf_800_128.getPSF_imaSurface_targetSize();
	cv::Mat refNomrPSF_05_neg1neg1 = inportExportData::importTXTtoCVmat(location, "refNomrPSF_05_neg1neg1", sizeMatrixOPD_128, sizeMatrixOPD_128);
	Images::saveImage_normalized(location, "normPSF_05_neg1neg1", "png", normPSF_05_neg1neg1);
	Images::saveImage_normalized(location, "refNomrPSF_05_neg1neg1", "png", refNomrPSF_05_neg1neg1);
	real sizeInnerDisc_normPSF_05_neg1neg1 = calcSizeInnerDiscPSF(normPSF_05_neg1neg1, targetPixelSize_05µm);
	real sizeInnerDisc_refPSF_05_neg1neg1 = calcSizeInnerDiscPSF(refNomrPSF_05_neg1neg1, targetPixelSize_05µm);
	bool checkPSF_neg1neg1 = Math::compareTwoNumbers_tolerance(sizeInnerDisc_normPSF_05_neg1neg1, sizeInnerDisc_refPSF_05_neg1neg1, tolerancePSF_disc);
	testPSF_vec.push_back(checkPSF_neg1neg1);

	// 1 neg 1
	psf_800_128.calculatePSF_superFunction(optSysEle, wavelength_800, { 1.0,-1.0,0.0 });
	// check
	cv::Mat normPSF_05_1neg1 = psf_800_128.getPSF_imaSurface_targetSize();
	cv::Mat refNomrPSF_05_1neg1 = inportExportData::importTXTtoCVmat(location, "refNomrPSF_05_1neg1", sizeMatrixOPD_128, sizeMatrixOPD_128);
	Images::saveImage_normalized(location, "normPSF_05_1neg1", "png", normPSF_05_1neg1);
	Images::saveImage_normalized(location, "refNomrPSF_05_1neg1", "png", refNomrPSF_05_1neg1);
	real sizeInnerDisc_normPSF_05_1neg1 = calcSizeInnerDiscPSF(normPSF_05_1neg1, targetPixelSize_05µm);
	real sizeInnerDisc_refPSF_05_1neg1 = calcSizeInnerDiscPSF(refNomrPSF_05_1neg1, targetPixelSize_05µm);
	bool checkPSF_1neg1 = Math::compareTwoNumbers_tolerance(sizeInnerDisc_normPSF_05_1neg1, sizeInnerDisc_refPSF_05_1neg1, tolerancePSF_disc);
	testPSF_vec.push_back(checkPSF_1neg1);

	// 00
	psf_800_128.calculatePSF_superFunction(optSysEle, wavelength_800, { 0.0,0.0,0.0 });
	// check
	cv::Mat normPSF_05_00 = psf_800_128.getPSF_imaSurface_targetSize();
	cv::Mat refNomrPSF_05_00 = inportExportData::importTXTtoCVmat(location, "refNomrPSF_05_00", sizeMatrixOPD_128, sizeMatrixOPD_128);
	Images::saveImage_normalized(location, "normPSF_05_00", "png", normPSF_05_00);
	Images::saveImage_normalized(location, "refNomrPSF_05_00", "png", refNomrPSF_05_00);
	real sizeInnerDisc_normPSF_05_00 = calcSizeInnerDiscPSF(normPSF_05_00, targetPixelSize_05µm);
	real sizeInnerDisc_refPSF_05_00 = calcSizeInnerDiscPSF(refNomrPSF_05_00, targetPixelSize_05µm);
	bool checkPSF_00 = Math::compareTwoNumbers_tolerance(sizeInnerDisc_normPSF_05_00, sizeInnerDisc_refPSF_05_00, tolerancePSF_disc);
	testPSF_vec.push_back(checkPSF_00);

	bool returnChecker = Math::checkTrueOfVectorElements(testPSF_vec);
	return returnChecker;
}

// calculate airy disc according to Pixel Size -> only valid for diffraction limited images
double TestPSF::calcSizeInnerDiscPSF(cv::Mat difLim_PSF, double pixlSize)
{
	unsigned int sizePSF = difLim_PSF.size().height;



	//Initialize m
	double minVal;
	double maxVal;
	cv::Point minLoc;
	cv::Point maxLoc;

	cv::minMaxLoc(difLim_PSF, &minVal, &maxVal, &minLoc, &maxLoc);
	



	real tempCompareVal_posDir = maxVal;
	real tempCompareVal_negDir = maxVal;

	unsigned int tempCoordinateCol_neg = maxLoc.x - 1;
	unsigned int tempCoordinateCol_pos = maxLoc.x + 1;
	unsigned int middlePoint_Row = maxLoc.y;

	real tempValCol_negDir{};

	bool checkerNegDirection = true;
	unsigned int stepCounter_negDirection = 0;

	while (checkerNegDirection)
	{
		tempValCol_negDir = difLim_PSF.at<real>(middlePoint_Row, tempCoordinateCol_neg);

		if (tempValCol_negDir > tempCompareVal_negDir) // && tempValCol_posDir > tempCompareVal_posDir)
		{
			checkerNegDirection = false;
		}

		if (tempValCol_negDir < tempCompareVal_negDir)
		{
			tempCompareVal_negDir = tempValCol_negDir;
			++stepCounter_negDirection;
		}

		--tempCoordinateCol_neg;
	}

	bool checker_PosDirection = true;
	unsigned int stepCounter_posDirection = 0;
	real tempValCol_posDir{};

	while (checker_PosDirection)
	{
		tempValCol_posDir = difLim_PSF.at<real>(middlePoint_Row, tempCoordinateCol_pos);

		if (tempValCol_posDir > tempCompareVal_posDir) // && tempValCol_posDir > tempCompareVal_posDir)
		{
			checker_PosDirection = false;
		}

		if (tempValCol_posDir < tempCompareVal_posDir)
		{
			tempCompareVal_posDir = tempValCol_posDir;
			++stepCounter_posDirection;
		}

		++tempCoordinateCol_pos;	
	}


	real airySize = 2.0 * (real)((stepCounter_negDirection + stepCounter_posDirection) / 2)* pixlSize;

	return airySize;

}