#pragma once

#include "opencv2/core/core.hpp"
#include "opencv2/core/mat.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "ImageSimulation.h"
using namespace cv;


class ImageSimulationFunctions
{
public:
	ImageSimulationFunctions() {};
	~ImageSimulationFunctions() {};

	ImageSimulationFunctions(Mat& ObjectMatrix, int GridFactor):
	mObject(ObjectMatrix),
	mGriDFactor(GridFactor)
	{
		ObjectAdapted = ObjectPreprocessing(mObject);
		ObjectGridsMatrix = ObjectGrids(mObject);
	};

	Mat calcPSF(Mat& OPD);
	Mat MagnitudeOfTwochannelsMat(Mat& matrix);
	Mat channelMultiplicationinInterp(Mat Matrix, Mat r, Mat c, Mat rPlus, Mat cPlus, Mat delta_r, Mat delta_c, Mat delta_r_Minus,Mat delta_c_Minus);
	float real_at(Mat& M, int index1, int index2);
	float imaginary_at(Mat& M, int index1, int index2);
	Mat fftshift(Mat& input);
	Mat ifftshiftOneChan(Mat& input);
	Mat ifftshiftTwoChan(Mat& input);
	//get ObjectGrids
	std::vector<std::vector<Mat>> getObjectGrids();
	//Cut not needed edges
	Mat ObjectPreprocessing(Mat& ObjectMatrix);
	//Create a matrix with Grids given rows and cols
	Mat GridMatrix(Mat& ObjectMatrix, int RowMax, int RowMin, int ColMax, int ColMin);
	Mat GridMatrixOutOfImage(Mat& ObjectMatrix, int RowMax, int RowMin, int ColMax, int ColMin);
	//vector with the object Grids
	std::vector<std::vector<Mat>> ObjectGrids(Mat& ObjectMatrix);
	//calculate OTF from PSF
	Mat calcFFT(Mat& PSF);
	//interpolate matrix
	Mat interpImg(Mat& Matrix, double ratio);
	Mat initialInterpplation(Mat& matrixToInterpolate, Mat& rows, Mat& columns);
	Mat multiplyThreeMat(Mat& channel, Mat& Matrix1, Mat& Matrix2);
	//Grids:
	//******ìntepolate OTF
	std::vector<std::vector<Mat>> OTFGrids(Mat& Otf1,Mat& Otf3, Mat& Otf5, Mat& Otf11, Mat& Otf13, Mat& Otf15, 
										   Mat& Otf21, Mat& Otf23, Mat& Otf25);
	//******inverse fourier of interpolated OTF for PSF
	std::vector<std::vector<Mat>> PSFGrids(std::vector<std::vector<Mat>> OtfGrids, double ObjectHeight, double rms);
	//******ìntepolate PSF
	std::vector<std::vector<Mat>> Padded_Interpolated_PSFGrids(std::vector<std::vector<Mat>> PSFGrid, double ObjectHeight, double rms);
	
	//invert OTF
	void inverseFFT(Mat& otf, Mat& inverseotf);

	//convolution
	Mat conv2D(const Mat& input, const Mat& kernel);
	std::vector < std::vector <Mat>> ConvolutionGridsFunction(std::vector<std::vector<Mat>> PSF);

	// Sum simulated image grids
	Mat SimulatedImg(std::vector < std::vector <Mat>> SimulatedImageGrids);

private:
	Mat mObject;
	Mat ObjectAdapted;
	std::vector<std::vector<Mat>> ObjectGridsMatrix;
	Mat mSimulatedImage;
	int mGriDFactor;
	Mat OTFReady;
	Mat MTFReady;
	
};

//show scaled coloured grey Image, to visualize PSF
void showColoured(const String& winname, Mat& IMG, float ratio);
//show Image that can be zoomed
void showImg(const String& winname, Mat& IMG);
//export a matrix to excel sheet
void exportCMatToExcel(cv::Mat matToExport, std::string locationAndfilename);
//read Matrix 128x128 from Text
Mat readCMatFromTxt(std::string locationAndfilename);
