#include "ImageSimulationPlot.h"
#include <iostream>
#include "..\..\Image\ImageSimulation.h"
#include "..\..\Analyse\OpticalPathDifference.h"
#include "..\..\LowLevelTracing\Surfaces\SphericalSurface_LLT.h"
#include "..\..\LowLevelTracing\Surfaces\PlanGeometry_LLT.h"
#include "..\..\LowLevelTracing\OpticalSystem_LLT.h"
#include "..\..\LowLevelTracing\Interaction\RefractedRay_LLT.h"
#include "..\..\SequentialRayTracing\SequentialRayTracer.h"
#include "..\..\LowLevelTracing\Surfaces\ParaxialLens_LLT.h"
#include "..\..\LowLevelTracing\Interaction\DeflectedRayParaxialLens_LLT.h"
#include "..\..\LowLevelTracing\Interaction\DoNothingInteraction_LLT.h"
#include "..\..\FillAptertureStop\FillApertureStop.h"
#include "..\..\Analyse\Spot.h"
#include "..\..\LowLevelTracing\Interaction\Absorb_LLT.h"
#include "..\..\LowLevelTracing\Surfaces\ApertureStop_LLT.h"

#include "..\..\FillAptertureStop\FillApertureStop.h"
#include"Images.h"

Mat ImageSimulationFunctions::calcPSF(Mat& OPD)
{
	return MagnitudeOfTwochannelsMat(calcFFT(OPD));
}
Mat ImageSimulationFunctions::MagnitudeOfTwochannelsMat(Mat& matrix)
{
	Mat chan[2];
	split(matrix, chan);
	Mat mag;
	magnitude(chan[0], chan[1], mag);
	return mag;
}

float ImageSimulationFunctions::imaginary_at(Mat& M, int index1, int index2)
{

	Mat channel[2];
	split(M, channel);
	return channel[1].at<float>(index1, index2);
}

float ImageSimulationFunctions::real_at(Mat& M, int index1, int index2)
{
	
	Mat channel[2];
	split(M, channel);
	return channel[0].at<float>(index1, index2);
}

Mat  ImageSimulationFunctions::fftshift(Mat& input)
{
	int centerX = input.cols / 2;
	int centerY = input.rows / 2;


	Mat q1(input, Rect(0, 0, centerX, centerY));
	Mat q2(input, Rect(centerX, 0, centerX, centerY));
	Mat q3(input, Rect(0, centerY, centerX, centerY));
	Mat q4(input, Rect(centerX, centerY, centerX, centerY));

	Mat SwapMap;
	q1.copyTo(SwapMap);
	q3.copyTo(q1);
	SwapMap.copyTo(q3);

	q2.copyTo(SwapMap);
	q4.copyTo(q2);
	SwapMap.copyTo(q4);

	return input;
}
Mat  ImageSimulationFunctions::ifftshiftTwoChan(Mat& input)
{
	Mat out;
	Mat inChan[2];
	split(input, inChan);
	Mat shiftReal = ifftshiftOneChan(inChan[0]);
	Mat shiftImg = ifftshiftOneChan(inChan[1]);
	Mat outChan[2] = { shiftReal ,shiftImg };
	merge(outChan, 2, out);
	return out;

}

Mat  ImageSimulationFunctions::ifftshiftOneChan(Mat& input)
{
	int centerX = input.cols / 2;
	int centerY = input.rows / 2;


	Mat q1(input, Rect(0, 0, centerX, centerY));
	Mat q2(input, Rect(centerX, 0, centerX, centerY));
	Mat q3(input, Rect(0, centerY, centerX, centerY));
	Mat q4(input, Rect(centerX, centerY, centerX, centerY));

	Mat SwapMap;
	q1.copyTo(SwapMap);
	q4.copyTo(q1);
	SwapMap.copyTo(q4);

	q2.copyTo(SwapMap);
	q3.copyTo(q2);
	SwapMap.copyTo(q3);

	return input;
}

Mat ImageSimulationFunctions::GridMatrixOutOfImage(Mat& ObjectMatrix, int RowMax, int RowMin, int ColMax, int ColMin)
{
	
	Rect region = Rect(RowMin,ColMin,RowMax-RowMin,ColMax-ColMin);
	return ObjectMatrix(region);
}
std::vector<std::vector<Mat>> ImageSimulationFunctions::getObjectGrids()
{
	return ObjectGridsMatrix;
};

Mat ImageSimulationFunctions::conv2D(const Mat& input, const Mat& kernel)
{
	Mat flipped_kernel;
	flip(kernel, flipped_kernel, -1);
	Mat padded;
	int additionalRows = kernel.rows - 1;
	int additionalCols = kernel.cols - 1;
	//copyMakeBorder(input, padded, (additionalRows+1)/2, additionalRows/2,
		//			(additionalCols + 1) / 2, additionalCols/2, BORDER_CONSTANT, Scalar::all(0));
	Point anchor(kernel.cols - kernel.cols / 2 - 1, kernel.rows - kernel.rows / 2 - 1);
	int delta = 0;
	int ddepth = -1;
	Mat result;

	//padded = input;
	Point2i pad (kernel.cols - 1, kernel.rows - 1);
	Rect region = Rect(pad.x / 2, pad.y / 2, padded.cols - pad.x, padded.rows - pad.y);
	filter2D(input, result, ddepth, flipped_kernel, anchor, delta, BORDER_CONSTANT);

	return result;//; (region);
}


Mat ImageSimulationFunctions::SimulatedImg(std::vector < std::vector <Mat>> SimulatedImageGrids)
{
	Mat SimulatedImgMat (SimulatedImageGrids[0][0].size(), SimulatedImageGrids[0][0].type());
	Mat channelImg[3];
	Mat dummyDarkMatrix= Mat::zeros(SimulatedImageGrids[0][0].size(), SimulatedImageGrids[0][0].type());
	split(dummyDarkMatrix, channelImg);

	
	for (unsigned int i = 0; i < mGriDFactor; i++)
		{
			for (unsigned int j = 0; j < mGriDFactor; j++)
			{
				Mat channelGrid[3];
				split( SimulatedImageGrids[i][j], channelGrid);
				channelImg[0] += channelGrid[0];
				channelImg[1] += channelGrid[1];
				channelImg[2] += channelGrid[2];
			}

		}
	
	double min, max;
	minMaxLoc(channelImg[0], &min, &max);

	for (unsigned int j = 1; j < 3; j++)
	{
		double min0, max0;
		minMaxLoc(channelImg[j], &min0, &max0);
		
		if (max0 > max)
			max = max0;
		
	}

	for (unsigned int j = 0; j < 3; j++)
	{
		double ratio = 255.0 / max;
		channelImg[j] *= ratio;
	}
	merge(channelImg, 3, SimulatedImgMat);

	Mat new_image = Mat::zeros(SimulatedImgMat.size(), SimulatedImgMat.type());

	double alpha = 1.0; /*< Simple contrast control */
	int beta = 0;       /*< Simple brightness control */

	for (int y = 0; y < SimulatedImgMat.rows; y++) {
		for (int x = 0; x < SimulatedImgMat.cols; x++) {
			for (int c = 0; c < SimulatedImgMat.channels(); c++) {
				new_image.at<Vec3b>(y, x)[c] =
					saturate_cast<uchar>(alpha*SimulatedImgMat.at<Vec3b>(y, x)[c] + beta);
			}
		}
	}


	return new_image;
}



std::vector < std::vector <Mat>> ImageSimulationFunctions::ConvolutionGridsFunction(std::vector<std::vector<Mat>> PSF)
{
	std::vector < std::vector <Mat>> SimulatedIMG;


	for (unsigned int n = 0; n < mGriDFactor; n++)
	{
		std::vector<Mat> Column;

		for (unsigned int m = 0; m < mGriDFactor; m++)
		{
			Mat M =conv2D(ObjectGridsMatrix[n][m], PSF[n][m]);
			Column.push_back(M);
		}
		SimulatedIMG.push_back(Column);
	}
	return SimulatedIMG;
}



std::vector<std::vector<Mat>>  ImageSimulationFunctions::Padded_Interpolated_PSFGrids(std::vector<std::vector<Mat>> PSFGrids, double ObjectHeight, double rms)
{
	std::vector<std::vector<Mat>> PaddedPSFGrids;
	double numberOfPixelPSF = 128;
	double numberOfImgPixel = ObjectAdapted.rows;
	float Conversion_factor = (ObjectHeight/rms)*(numberOfPixelPSF/numberOfImgPixel);
	float New_psf_size = numberOfPixelPSF * Conversion_factor;
	std::cout<< "Conversion_factor "<< Conversion_factor << std::endl;
	//padding psf matrix for the same factor
	int padding = floor((New_psf_size - numberOfPixelPSF) / 2);
	
	//sampling 
	for (unsigned int n = 0; n < mGriDFactor; n++)
	{
			std::vector<Mat> Column;
			for (unsigned int m = 0; m < mGriDFactor; m++)
			{
				Mat M=PSFGrids[n][m];
				Mat padded;
				copyMakeBorder(M, padded, padding, padding, padding, padding, BORDER_CONSTANT, Scalar::all(0));
				float factorInterp = numberOfImgPixel / padded.rows;
				Mat interpPadded;
				interpPadded = interpImg(padded, factorInterp);
				Column.push_back(interpPadded);
			}
			PaddedPSFGrids.push_back(Column);
	}
	std::cout << "end Padding PSF" << std::endl << std::endl;
	return PaddedPSFGrids;
}

void ImageSimulationFunctions::inverseFFT(Mat& otf, Mat& inverseotf)
{
	Mat inverse;
	Mat toinverse = ifftshiftOneChan(otf);
	//Mat chan[] = { Mat::zeros(otf.size(),CV_32F),Mat::zeros(otf.size(),CV_32F) };
	//merge(chan, 2, inverse);
	idft(toinverse, inverse, DFT_COMPLEX_OUTPUT + DFT_COMPLEX_INPUT + DFT_SCALE,0);
	inverse = ifftshiftOneChan(inverse);
	inverseotf = inverse;
}

std::vector<std::vector<Mat>> ImageSimulationFunctions::PSFGrids(std::vector<std::vector<Mat>> OtfGrids , double ObjectHeight, double rms)
{
	std::vector<std::vector<Mat>> PSFGrids;

	for (unsigned int n = 0; n < mGriDFactor; n++)
	{
		std::vector<Mat> Column;
		
		for (unsigned int m = 0; m < mGriDFactor; m++)
		{
			Mat M;
			Mat toInvertMatrix=OtfGrids[n][m];
			inverseFFT(toInvertMatrix,M);
			Mat mag = MagnitudeOfTwochannelsMat(M);
			Column.push_back(mag);
		}
		PSFGrids.push_back(Column);
	}

	std::vector<std::vector<Mat>> PSF_grids_padded = Padded_Interpolated_PSFGrids(PSFGrids, ObjectHeight, rms);
	//std::cout << "Padded PSF 0 " << PSF_grids_padded[0][0].rows << "x" << PSF_grids_padded[0][0].cols << std::endl;
	return PSF_grids_padded;
}

std::vector<std::vector<Mat>>  ImageSimulationFunctions::OTFGrids(Mat& Otf1, Mat& Otf3, Mat& Otf5, Mat& Otf11, Mat& Otf13, Mat& Otf15,
	Mat& Otf21, Mat& Otf23, Mat& Otf25)
{
	std::vector<std::vector<Mat>> OtfGridMatrix;
	std::vector<std::vector<Mat>> OtfGridMatrixReal;
	std::vector<std::vector<Mat>> OtfGridMatrixImaginary;
	double UpSimplingFactor = mGriDFactor / 3;
	
	for (unsigned int n = 0; n < mGriDFactor; n++)
	{
		std::vector<Mat> ColumnReal;
		Mat MReal = Mat::zeros(128, 128, CV_32F);
		for (unsigned int m = 0; m < mGriDFactor; m++)
		{
			ColumnReal.push_back(MReal);
		}
		
		OtfGridMatrixReal.push_back(ColumnReal);
		
	}

	for (unsigned int n = 0; n < mGriDFactor; n++)
	{
		std::vector<Mat> ColumnImg;
		Mat M = Mat::zeros(128, 128, CV_32F);
		for (unsigned int m = 0; m < mGriDFactor; m++)
		{
			ColumnImg.push_back(M);
		}

		
		OtfGridMatrixImaginary.push_back(ColumnImg);
	}


	for (unsigned int i = 0; i < 128; i++)
	{
		for (unsigned int j = 0; j < 128; j++)
		{

			float M_data_real[10] = { real_at(Otf1,i,j),   real_at(Otf3,i,j),   real_at(Otf5,i,j),
									   real_at(Otf11,i,j),  real_at(Otf13,i,j),  real_at(Otf15,i,j),
									   real_at(Otf21,i,j),  real_at(Otf23,i,j),  real_at(Otf25,i,j) };
			cv::Mat M_real = cv::Mat(3, 3, CV_32F, M_data_real);
			Mat M_up_real = interpImg(M_real, UpSimplingFactor);


			for (unsigned int k = 0; k < mGriDFactor; k++)
			{
				for (unsigned int l = 0; l < mGriDFactor; l++)
				{
					float x = M_up_real.at<float>(k, l);
					OtfGridMatrixReal[k][l].at<float>(i, j) = x;
				}
			}

		}
	}
	
	

	for (unsigned int i = 0; i < 128; i++)
		{
			for (unsigned int j = 0; j < 128; j++)
			{
			

			float M_data_imaginary[10] = { imaginary_at(Otf1,i,j),   imaginary_at(Otf3,i,j),   imaginary_at(Otf5,i,j),
								 imaginary_at(Otf11,i,j),  imaginary_at(Otf13,i,j),  imaginary_at(Otf15,i,j),
								 imaginary_at(Otf21,i,j),  imaginary_at(Otf23,i,j),  imaginary_at(Otf25,i,j) };
			cv::Mat M_imaginary = cv::Mat(3, 3, CV_32F, M_data_imaginary);
			Mat M_up_imaginary = interpImg(M_imaginary, UpSimplingFactor);

		

				for (unsigned int n = 0; n < mGriDFactor; n++)
				{
					for (unsigned int m = 0; m < mGriDFactor; m++)
					{
					
					float x = M_up_imaginary.at<float>(n, m);
					OtfGridMatrixImaginary[n][m].at<float>(i, j) = M_up_imaginary.at<float>(n, m);
					
					}
				}

			}

	}

	

	for (unsigned int a = 0; a < mGriDFactor; a++)
	{
		std::vector<Mat> Column;
		for (unsigned int b = 0; b < mGriDFactor; b++)
		{
			Mat channels[2];
			channels[0] = OtfGridMatrixReal[a][b];
			channels[1] = OtfGridMatrixImaginary[a][b];
			Mat M_up;
			merge(channels, 2, M_up);
			Column.push_back(M_up);
		}

		OtfGridMatrix.push_back(Column);
		
	}
	

	return OtfGridMatrix;
}
Mat ImageSimulationFunctions::multiplyThreeMat(Mat& channel, Mat& Matrix1, Mat& Matrix2)
{
	Mat tmp;
	multiply(channel, Matrix1, tmp, 1);
	multiply(tmp, Matrix2, tmp, 1);
	return tmp;
}

Mat ImageSimulationFunctions::initialInterpplation(Mat& matrixToInterpolate, Mat& rows, Mat& columns)
{
	Mat interpolatedMatrix(Size(rows.rows,columns.cols),matrixToInterpolate.type());

	for (unsigned int r = 0; r < rows.rows ; r++)
	{
		for (unsigned int c = 0; c < columns.cols; c++)
		{
			int yIndex=rows.at<float>(r,c)-1;
			int xIndex=columns.at<float>(r,c)-1;
			interpolatedMatrix.at<float>(r, c) = matrixToInterpolate.at<float>(xIndex,yIndex);
		}
	}

	return interpolatedMatrix;
}

Mat ImageSimulationFunctions::interpImg(Mat& Matrix, double ratio)
{

	Mat out(Matrix.size(),Matrix.type());
	Matrix.convertTo(Matrix, CV_32FC3);
	int in_columns = Matrix.cols;
	int in_rows = Matrix.rows;
	int out_columns = in_columns * ratio;
	int out_rows = in_rows * ratio;

	Mat c (out_rows, out_columns, CV_32F);
	Mat delta_c(out_rows, out_columns, CV_32F);
	Mat r (out_rows, out_columns, CV_32F);
	Mat delta_r (out_rows, out_columns, CV_32F);

	
	for (unsigned int i = 0; i < out_columns; i++)
	{
		for (unsigned int j = 0; j < out_rows; j++)
		{
			double cf_Value = (j+1) / ratio;
			double c_Value = floor(cf_Value);
			if (c_Value > 1)
			{
				c.at<float>(i, j) = c_Value;
			}
			
			else c.at<float>(i, j) = 1;

			if (c_Value > in_rows - 1)
			{
				c.at<float>(i, j) = in_rows - 1;
			}
			
			double rf_Value = (j + 1) / ratio;
			int r_Value = floor(rf_Value);


			if (r_Value > 1)
			{
				r.at<float>(j, i) = r_Value;
			}
			else r.at<float>(j, i) = 1;

			if (r_Value > in_columns - 1)
			{
				r.at<float>(j, i) = in_columns - 1;
			}

			delta_c.at<float>(i, j) = cf_Value - c.at<float>(i, j);
			delta_r.at<float>(j, i) = rf_Value - r.at<float>(j, i);
		}
	}
	Mat rPlus = r + Scalar(1);
	Mat cPlus = c + Scalar(1);

	Mat delta_c_Minus = Scalar(1) - delta_c;
	Mat delta_r_Minus = Scalar(1) - delta_r;
	
	if (Matrix.channels() == 1)
	{
		out = channelMultiplicationinInterp(Matrix, r, c, rPlus, cPlus, delta_r, delta_c, delta_r_Minus, delta_c_Minus);
	}

	if (Matrix.channels() == 2)
	{ 
		Mat splitChannels[2];
		split(Matrix, splitChannels);
		Mat outReal= channelMultiplicationinInterp(splitChannels[0], r, c, rPlus, cPlus, delta_r, delta_c, delta_r_Minus, delta_c_Minus);
		Mat outImg = channelMultiplicationinInterp(splitChannels[1], r, c, rPlus, cPlus, delta_r, delta_c, delta_r_Minus, delta_c_Minus);
		Mat outChannels[2];
		outChannels[0] = ifftshiftOneChan(outReal);
		outChannels[1] = ifftshiftOneChan(outImg);
		merge(outChannels, 2, out);
	}
		
	
	return out;
}

Mat ImageSimulationFunctions::channelMultiplicationinInterp(Mat Matrix,Mat r,Mat c,Mat rPlus, Mat cPlus, Mat delta_r, Mat delta_c, Mat delta_r_Minus,Mat delta_c_Minus)
{
	Mat A_Influence = initialInterpplation(Matrix, r, c);
	Mat C_Influence = initialInterpplation(Matrix, rPlus, c);
	Mat B_Influence = initialInterpplation(Matrix, r, cPlus);
	Mat D_Influence = initialInterpplation(Matrix, rPlus, cPlus);

	Mat Temporary = multiplyThreeMat(A_Influence, delta_r_Minus, delta_c_Minus) +
		multiplyThreeMat(C_Influence, delta_r, delta_c_Minus) +
		multiplyThreeMat(B_Influence, delta_r_Minus, delta_c) +
		multiplyThreeMat(D_Influence, delta_r, delta_c);
	Temporary = Temporary.t();
	Mat out = Temporary;
	return out;
}

Mat ImageSimulationFunctions::calcFFT(Mat& PSF)
{
	Mat PSFfloat;
	PSF.convertTo(PSFfloat, CV_32F);
	PSFfloat = ifftshiftOneChan(PSFfloat);
	//expand PSF to optimum size
	Mat padded;
	//expand input image to optimal size
	int m = getOptimalDFTSize(PSFfloat.rows);
	int n = getOptimalDFTSize(PSFfloat.cols); 
	// on the border add zero values
	copyMakeBorder(PSFfloat, padded, 0, m - PSFfloat.rows, 0, n - PSFfloat.cols, BORDER_CONSTANT, Scalar::all(0));
	//take DFT
	Mat OTFcomplex[2] = {padded,Mat::zeros(padded.size(),CV_32F)};
	Mat DFTready;
	Mat dftOfOriginal;
	merge(OTFcomplex, 2, DFTready);
	dft(DFTready, dftOfOriginal, DFT_COMPLEX_OUTPUT);
	dftOfOriginal = ifftshiftOneChan(dftOfOriginal);
	return dftOfOriginal;
}

std::vector<std::vector<Mat>> ImageSimulationFunctions::ObjectGrids(Mat& ObjectMatrix)
{
	Mat ObjectAdapted = ObjectPreprocessing(ObjectMatrix);
	std::vector<std::vector<Mat>> ObjectGridMatrix;
	int newRow = ceil(ObjectAdapted.rows / mGriDFactor);
	int newCol = ceil(ObjectAdapted.cols / mGriDFactor);

	for (unsigned int i = 0; i < mGriDFactor; i++)
	{
		std::vector<Mat> firstColumn;
		ObjectGridMatrix.push_back(firstColumn);
		for (unsigned int j = 0; j < mGriDFactor; j++)
		{
			Mat subMatrix = GridMatrix(ObjectAdapted, i*newRow, (i+1)*newRow, j*newCol, (j+1)*newCol);
			ObjectGridMatrix[i].push_back(subMatrix);
		}
		
	}
	return ObjectGridMatrix;

}

Mat ImageSimulationFunctions::GridMatrix(Mat& ObjectMatrix, int RowMin, int RowMax, int ColMin, int ColMax)
{
	Mat GridMat=Mat::zeros(ObjectMatrix.size(), ObjectMatrix.type());

	for (unsigned int r = 0; r < ObjectMatrix.rows; r++)
	{
		for (unsigned int c = 0; c < ObjectMatrix.cols; c++)
		{
			if ((r >= RowMin) && (r <= RowMax) && (c >= ColMin) && (c <= ColMax))
			{
				GridMat.at<cv::Vec3b>(r, c) = ObjectMatrix.at<cv::Vec3b>(r, c);
			}
		}
	}

	return GridMat;
}

Mat ImageSimulationFunctions::ObjectPreprocessing(Mat& ObjectMatrix)
{
	Mat ProcessedObjectMatrix;
	int a = ObjectMatrix.size().height;
	a = a - (a % mGriDFactor);
	int b = ObjectMatrix.size().width;
	b = b - (b % mGriDFactor);

	cv::Rect ROI(0, 0, b, a);
	ProcessedObjectMatrix = ObjectMatrix(ROI);
	return ProcessedObjectMatrix;
}

void showImg(const String& winname, Mat& IMG)
{
	namedWindow(winname, CV_WINDOW_FREERATIO);
	resizeWindow(winname, IMG.cols, IMG.rows);
	imshow(winname, IMG);
	waitKey(0);
}

// export a cv::mat to excel
void exportCMatToExcel(cv::Mat matToExport, std::string locationAndfilename)
{

	std::ofstream outData;
	outData.open(locationAndfilename, std::ios::app);
	outData << matToExport << std::endl;
}


Mat readCMatFromTxt(std::string locationAndfilename)
{
	
	using namespace std;
	ifstream infile(locationAndfilename.c_str());
	std::vector<std::vector<float> > numbers;

	std::string temp;

	while (std::getline(infile, temp)) {
		std::istringstream buffer(temp);
		std::vector<float> line((std::istream_iterator<float>(buffer)),
			std::istream_iterator<float>());

		numbers.push_back(line);
	}


	// Now add all the data into a Mat element
	Mat vect = Mat::zeros(128, 128, CV_32FC1);
	// Loop over vectors and add the data
	for (int rows = 0; rows < 128; rows++) {
		for (int cols = 0; cols < 128; cols++) 
		{
			vect.at<float>(rows, cols) = numbers[rows][cols];
			
		}
	}
	
	return vect;

}

void showColoured(const String& winname, Mat& IMG, float ratio)
{
	Mat display;
	IMG.convertTo(display, CV_8UC1, 255.0 / ratio, 0);
	applyColorMap(display, display, cv::COLORMAP_JET);
	imshow(winname, display);
	waitKey(0);
}