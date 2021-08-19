#include "testNoise.h"

// math
#include "..\..\LowLevelTracing\Math_LLT.h"

// images
#include "..\..\Image\Images.h"



testNoise::testNoise() 
{
	loadCameraParameter();
}
testNoise::~testNoise() {}

// load camera parameter
void testNoise::loadCameraParameter()
{
	// VistecEco655
	mCaraPara_VistecEco655.setgQWC(12000.0);
	mCaraPara_VistecEco655.setgPS(5.3);
	mCaraPara_VistecEco655.setgDS(38);
	mCaraPara_VistecEco655.setgDS_dt(9.7);
	mCaraPara_VistecEco655.setgDSNU(21.0);
	mCaraPara_VistecEco655.setgDSNU_dt(9.4);
	mCaraPara_VistecEco655.setgPRNU(1.5);
	mCaraPara_VistecEco655.setgRON(15.0);
	mCaraPara_VistecEco655.setgEta400(0.6);
	mCaraPara_VistecEco655.setgEta500(0.7);
	mCaraPara_VistecEco655.setgEta600(0.7);
	mCaraPara_VistecEco655.setgEta700(0.6);
	mCaraPara_VistecEco655.setgEta800(0.5);
	mCaraPara_VistecEco655.setgEta900(0.3);
	mCaraPara_VistecEco655.setgADCFaktor(0.085);
	mCaraPara_VistecEco655.setgASCDynamik(10);
	mCaraPara_VistecEco655.setgNonlinearity(1.0);
	mCaraPara_VistecEco655.setgMin(100.0);
	mCaraPara_VistecEco655.setgMax(900.0);

	// Ximea
	mCaraPara_Ximea.setgQWC(12000.0);
	mCaraPara_Ximea.setgPS(5.3);
	mCaraPara_Ximea.setgDS(25);
	mCaraPara_Ximea.setgDS_dt(9.7);
	mCaraPara_Ximea.setgDSNU(6.0);
	mCaraPara_Ximea.setgDSNU_dt(9.4);
	mCaraPara_Ximea.setgPRNU(1.0);
	mCaraPara_Ximea.setgRON(15.0);
	mCaraPara_Ximea.setgEta400(0.55);
	mCaraPara_Ximea.setgEta500(0.6);
	mCaraPara_Ximea.setgEta600(0.58);
	mCaraPara_Ximea.setgEta700(0.46);
	mCaraPara_Ximea.setgEta800(0.3);
	mCaraPara_Ximea.setgEta900(0.15);
	mCaraPara_Ximea.setgADCFaktor(0.085);
	mCaraPara_Ximea.setgASCDynamik(10);
	mCaraPara_Ximea.setgNonlinearity(1.0);
	mCaraPara_Ximea.setgMin(100.0);
	mCaraPara_Ximea.setgMax(900.0);

}

bool testNoise::testNoise_superFct()
{
	std::vector<bool> test_vec;

	//E0
	bool checkE0 = testNoise_E0();
	test_vec.push_back(checkE0);

	// E1
	bool checkE1 = testNoise_E1();
	test_vec.push_back(checkE1);
	//
	// E2
	bool checkE2 = testNoise_E2();
	test_vec.push_back(checkE2);

	bool returnChecker = Math::checkTrueOfVectorElements(test_vec);
	return returnChecker;

}

//E0
bool testNoise::testNoise_E0()
{
	std::vector<bool> test_vec;

	std::string location = "../tests/testNoise/E0";

	// load gray image
	std::string locationImagesGray = "../images/gray/elefant_150x150.png";
	cv::Mat greyMat = cv::imread(locationImagesGray, cv::IMREAD_GRAYSCALE); // Source image
	//std::string cameraParametes = "../tests/testNoise(E0/ximea.txt";


	Noise noise;
	noise.noiseSuperFunction_grayImage(greyMat,mCaraPara_VistecEco655,21,0.002,/*Frage: welcher Wert passt hier*/ 0.035,550.0, true);

	cv::Mat imageWithNoise = noise.getImageWithNoise_Gray_uint8_normed();

	// debug
	//Images::showImage_inputUint8("image with noise", imageWithNoise);

	// save the image
	Images::saveImage_normalized(location, "imageWithNoise", "png", imageWithNoise);

	// make noise visable
	cv::Mat noiseImage = greyMat - imageWithNoise;
	cv::normalize(noiseImage, noiseImage, 0, 255, cv::NORM_MINMAX);
	Images::saveImage_normalized(location, "noise", "png", noiseImage);

	// check values in image 
	std::vector<bool> compare;

	int valInitialIma_0 = greyMat.at<uchar>(25, 26);
	int valNoiseIma_0 = imageWithNoise.at<uchar>(25, 26);
	bool check_0 = valInitialIma_0 != valNoiseIma_0;
	compare.push_back(check_0);

	int valInitialIma_1 = greyMat.at<uchar>(2, 12);
	int valNoiseIma_1 = imageWithNoise.at<uchar>(2, 12);
	bool check_1 = valInitialIma_1 !=valNoiseIma_1;
	compare.push_back(check_1);

	int valInitialIma_2 = greyMat.at<uchar>(13, 55);
	int valNoiseIma_2 = imageWithNoise.at<uchar>(13, 55);
	bool check_2 = valInitialIma_2 !=valNoiseIma_2;
	compare.push_back(check_2);

	int valInitialIma_3 = greyMat.at<uchar>(85, 66);
	int valNoiseIma_3 = imageWithNoise.at<uchar>(85, 66);
	bool check_3 = valInitialIma_3 != valNoiseIma_3;
	compare.push_back(check_3);

	int valInitialIma_4 = greyMat.at<uchar>(36, 45);
	int valNoiseIma_4 = imageWithNoise.at<uchar>(36, 45);
	bool check_4 = valInitialIma_4 != valNoiseIma_4;
	compare.push_back(check_4);

	int valInitialIma_5 = greyMat.at<uchar>(21, 52);
	int valNoiseIma_5 = imageWithNoise.at<uchar>(21, 52);
	bool check_5 = valInitialIma_5 !=valNoiseIma_5;
	compare.push_back(check_5);


	int tureCouner = 0;
	for (unsigned int i = 0; i < compare.size(); ++i)
	{
		if (compare[i] == true)
		{
			tureCouner = ++ tureCouner;
		}
	}

	if (tureCouner >= 3)
	{
		test_vec.push_back(true);
	}
	else
	{
		test_vec.push_back(false);
	}

	bool returnChecker = Math::checkTrueOfVectorElements(test_vec);
	return returnChecker;

}

//E1
bool testNoise::testNoise_E1()
{
	std::vector<bool> test_vec;
	std::string location = "../tests/testNoise/E1";

	// load gray image
	std::string locationImagesGray = "../images/gray/elefant_sharp_gray_small.png";
	cv::Mat greyMat = cv::imread(locationImagesGray, cv::IMREAD_GRAYSCALE); // Source image
	//std::string cameraParametes = "../tests/testNoise(E0/ximea.txt";

	Noise noiseE1;
	noiseE1.noiseSuperFunction_grayImage(greyMat, mCaraPara_Ximea, 21, 0.002,/*Frage: welcher Wert passt hier*/ 0.035, 550.0, true);

	cv::Mat imageWithNoise = noiseE1.getImageWithNoise_Gray_uint8_normed();

	// save the image
	Images::saveImage_normalized(location, "imageWithNoise", "png", imageWithNoise);

	// make noise visable
	cv::Mat noiseImage = greyMat - imageWithNoise;
	cv::normalize(noiseImage, noiseImage, 0, 255, cv::NORM_MINMAX);
	Images::saveImage_normalized(location, "noise", "png", noiseImage);


	// check values in image 
	std::vector<bool> compare;

	int valInitialIma_0 = greyMat.at<uchar>(12, 23);
	int valNoiseIma_0 = imageWithNoise.at<uchar>(12, 23);
	bool check_0 = valInitialIma_0 != valNoiseIma_0;
	compare.push_back(check_0);

	int valInitialIma_1 = greyMat.at<uchar>(8, 9);
	int valNoiseIma_1 = imageWithNoise.at<uchar>(8, 9);
	bool check_1 = valInitialIma_1 != valNoiseIma_1;
	compare.push_back(check_1);

	int valInitialIma_2 = greyMat.at<uchar>(45, 56);
	int valNoiseIma_2 = imageWithNoise.at<uchar>(45, 56);
	bool check_2 = valInitialIma_2 != valNoiseIma_2;
	compare.push_back(check_2);

	int valInitialIma_3 = greyMat.at<uchar>(85, 66);
	int valNoiseIma_3 = imageWithNoise.at<uchar>(85, 66);
	bool check_3 = valInitialIma_3 != valNoiseIma_3;
	compare.push_back(check_3);

	int valInitialIma_4 = greyMat.at<uchar>(36, 45);
	int valNoiseIma_4 = imageWithNoise.at<uchar>(36, 45);
	bool check_4 = valInitialIma_4 != valNoiseIma_4;
	compare.push_back(check_4);

	int valInitialIma_5 = greyMat.at<uchar>(21, 52);
	int valNoiseIma_5 = imageWithNoise.at<uchar>(21, 52);
	bool check_5 = valInitialIma_5 != valNoiseIma_5;
	compare.push_back(check_5);


	int tureCouner = 0;
	for (unsigned int i = 0; i < compare.size(); ++i)
	{
		if (compare[i] == true)
		{
			tureCouner = ++tureCouner;
		}
	}

	if (tureCouner >= 3)
	{
		test_vec.push_back(true);
	}
	else
	{
		test_vec.push_back(false);
	}


	bool returnChecker = Math::checkTrueOfVectorElements(test_vec);
	return returnChecker;
}

//E2
bool testNoise::testNoise_E2()
{
	std::vector<bool> test_vec;
	std::string location = "../tests/testNoise/E2";

	// load gray image
	std::string locationImagesColor = "../images/color/useThatImages/useThat/elefant_sharp_250x188.png";
	cv::Mat colorMat = cv::imread(locationImagesColor, cv::IMREAD_COLOR); // Source image
	//std::string cameraParametes = "../tests/testNoise(E0/ximea.txt";

	Noise noise;
	std::vector<float> wavelength{ 400.0, 550.0, 700.0 };
	noise.noiseSuperFunction_colorImage(colorMat, mCaraPara_Ximea, 21, 0.002,/*Frage: welcher Wert passt hier*/ 0.035, wavelength, true);

	cv::Mat imageWithNoise = noise.getImageWithNoise_Color_uint8_normed();

	// save the image
	Images::saveImage_normalized(location, "imageWithNoise", "png", imageWithNoise);

	// make noise visable
	cv::Mat noiseImage = colorMat - imageWithNoise;
	cv::normalize(noiseImage, noiseImage, 0, 255, cv::NORM_MINMAX);
	Images::saveImage_normalized(location, "noise", "png", noiseImage);

	// check values in image 
	std::vector<bool> compare;

	int valInitialIma_0 = colorMat.at<cv::Vec3b>(12, 23)[0];
	int valNoiseIma_0 = imageWithNoise.at<cv::Vec3b>(12, 23)[0];
	bool check_0 = valInitialIma_0 != valNoiseIma_0;
	compare.push_back(check_0);

	int valInitialIma_1 = colorMat.at<cv::Vec3b>(8, 9)[0];
	int valNoiseIma_1 = imageWithNoise.at<cv::Vec3b>(8, 9)[0];
	bool check_1 = valInitialIma_1 != valNoiseIma_1;
	compare.push_back(check_1);

	int valInitialIma_2 = colorMat.at<cv::Vec3b>(45, 56)[1];
	int valNoiseIma_2 = imageWithNoise.at<cv::Vec3b>(45, 56)[1];
	bool check_2 = valInitialIma_2 != valNoiseIma_2;
	compare.push_back(check_2);

	int valInitialIma_3 = colorMat.at<cv::Vec3b>(85, 66)[1];
	int valNoiseIma_3 = imageWithNoise.at<cv::Vec3b>(85, 66)[1];
	bool check_3 = valInitialIma_3 != valNoiseIma_3;
	compare.push_back(check_3);

	int valInitialIma_4 = colorMat.at<cv::Vec3b>(36, 45)[2];
	int valNoiseIma_4 = imageWithNoise.at<cv::Vec3b>(36, 45)[2];
	bool check_4 = valInitialIma_4 != valNoiseIma_4;
	compare.push_back(check_4);

	int valInitialIma_5 = colorMat.at<cv::Vec3b>(21, 52)[2];
	int valNoiseIma_5 = imageWithNoise.at<cv::Vec3b>(21, 52)[2];
	bool check_5 = valInitialIma_5 != valNoiseIma_5;
	compare.push_back(check_5);


	int tureCouner = 0;
	for (unsigned int i = 0; i < compare.size(); ++i)
	{
		if (compare[i] == true)
		{
			tureCouner = ++tureCouner;
		}
	}

	if (tureCouner >= 3)
	{
		test_vec.push_back(true);
	}
	else
	{
		test_vec.push_back(false);
	}

	bool returnChecker = Math::checkTrueOfVectorElements(test_vec);
	return returnChecker;
}