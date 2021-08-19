#include "ImproveImageQuality.h"
#include "..\LowLevelTracing/Math_LLT.h"
#include "Images.h"
#include <fstream>



// inport export
#include "..\Inport_Export_Data\Inport_Export_Data.h"

// images
#include "..\Image\Images.h"



ImproveImageQuality::ImproveImageQuality() {}
ImproveImageQuality::~ImproveImageQuality(){}

ContrastAndGammaStruct ImproveImageQuality::improveImageQuality_contrastAndGamma(cv::Mat const& sharpImage, cv::Mat const& simulatedImage, real const& minAlpha, real const& maxAlpha, int const& alphaSteps, real const& minBeta, real const& maxBeta, int const& stepsBeta, real const& minGamma, real const& maxGamma, int const& stepsGamma)
{
	ContrastAndGammaStruct retunrBestResult_ContrastAndGamm;

	real temp_Alpha;
	real temp_Beta;
	real temp_Gamma;

	cv::Mat new_image = cv::Mat::zeros(simulatedImage.size(), simulatedImage.type());
	double bestResult = Images::calcSumMatrix(Images::PerElementAbsDifference(simulatedImage, sharpImage));

	double tempBestResult = Images::calcSumMatrix(Images::PerElementAbsDifference(new_image, sharpImage));
	real bestAlpha = 0.0;
	real bestBeat = 0.0;
	real bestGamma = 0.0;

	std::vector<real> alpha_vec = Math::linDistriAlongTwoValues_double(minAlpha,maxAlpha,alphaSteps);
	std::vector<real> beta_vec = Math::linDistriAlongTwoValues_double(minBeta, maxBeta, stepsBeta);
	std::vector<real> gamma_vec = Math::linDistriAlongTwoValues_double(minGamma, maxGamma, stepsGamma);

	retunrBestResult_ContrastAndGamm.setImage(simulatedImage);
	retunrBestResult_ContrastAndGamm.setQuality(bestResult);

	for (int alpha_loop = 0; alpha_loop < alpha_vec.size(); ++alpha_loop)
	{
		for (int beta_loop = 0; beta_loop < beta_vec.size(); ++beta_loop)
		{ 
			for (int gamma_loop = 0; gamma_loop < gamma_vec.size(); ++gamma_loop)

			{
				new_image = ImageProcessing::brighContrastAdjust(simulatedImage, alpha_vec.at(alpha_loop), beta_vec.at(beta_loop));
				new_image = ImageProcessing::gammaCorrection(new_image, gamma_vec.at(gamma_loop));
				

				tempBestResult = Images::calcSumMatrix(Images::PerElementAbsDifference(new_image, sharpImage));



				if (tempBestResult < bestResult)
				{
					bestResult = tempBestResult;
					retunrBestResult_ContrastAndGamm.setImage(new_image);
					retunrBestResult_ContrastAndGamm.setQuality(tempBestResult);
					retunrBestResult_ContrastAndGamm.setAlpha(alpha_vec.at(alpha_loop));
					retunrBestResult_ContrastAndGamm.setBeta(beta_vec.at(beta_loop));
					retunrBestResult_ContrastAndGamm.setGamme(gamma_vec.at(gamma_loop));

					real improvement = Images::calcImprovement_noNorming(sharpImage, simulatedImage, new_image);
					retunrBestResult_ContrastAndGamm.setImprovement(improvement);


					retunrBestResult_ContrastAndGamm.exportAsTXTfile();

				}

			}
		}
	}

	real improvement = Images::calcImprovement_noNorming(sharpImage, simulatedImage, retunrBestResult_ContrastAndGamm.getImage());
	retunrBestResult_ContrastAndGamm.setImprovement(improvement);

	return retunrBestResult_ContrastAndGamm;


}

ContrastAndGammaStruct ImproveImageQuality::improveImageQuality_contrastAndGamma_multiCore(cv::Mat const& sharpImage, cv::Mat const& simulatedImage, real const& minAlpha, real const& maxAlpha, int const& alphaSteps, real const& minBeta, real const& maxBeta, int const& stepsBeta, real const& minGamma, real const& maxGamma, int const& stepsGamma)
{
	cv::Mat new_image = cv::Mat::zeros(simulatedImage.size(), simulatedImage.type());

	int const& numberCores = 8;
	int const& stepPerCore_s = stepsGamma / numberCores;
	float const& deltaPerCore_gamma = std::abs(maxGamma - minGamma) / numberCores;

	// core 1
	real const& minGamma_1 = minGamma;
	real const& maxGamma_s_1 = minGamma + deltaPerCore_gamma;
	// core 2
	real const& minGamma_2 = maxGamma_s_1;
	real const& maxGamma_s_2 = minGamma + 2 * deltaPerCore_gamma;
	// core 3
	real const& minGamma_3 = maxGamma_s_2;
	real const& maxGamma_s_3 = minGamma + 3 * deltaPerCore_gamma;
	// core 4
	real const& minGamma_4 = maxGamma_s_3;
	real const& maxGamma_s_4 = minGamma + 4 * deltaPerCore_gamma;
	// core 5
	real const& minGamma_5 = maxGamma_s_4;
	real const& maxGamma_s_5 = minGamma + 5 * deltaPerCore_gamma;
	// core 6
	real const& minGamma_6 = maxGamma_s_5;
	real const& maxGamma_s_6 = minGamma + 6 * deltaPerCore_gamma;
	// core 7
	real const& minGamma_7 = maxGamma_s_6;
	real const& maxGamma_s_7 = minGamma + 7 * deltaPerCore_gamma;
	// core 8
	real const& minGamma_8 = maxGamma_s_7;
	real const& maxGamma_s_8 = minGamma + 8 * deltaPerCore_gamma;

	ContrastAndGammaStruct Core_1_Result;
	ContrastAndGammaStruct Core_2_Result;
	ContrastAndGammaStruct Core_3_Result;
	ContrastAndGammaStruct Core_4_Result;
	ContrastAndGammaStruct Core_5_Result;
	ContrastAndGammaStruct Core_6_Result;
	ContrastAndGammaStruct Core_7_Result;
	ContrastAndGammaStruct Core_8_Result;


	#pragma omp parallel sections
		{
	

			Core_1_Result = improveImageQuality_contrastAndGamma(sharpImage, simulatedImage, minAlpha, maxAlpha, alphaSteps, minBeta, maxBeta, stepsBeta, minGamma_1, maxGamma_s_1, stepPerCore_s);
	#pragma omp section
			Core_2_Result = improveImageQuality_contrastAndGamma(sharpImage, simulatedImage, minAlpha, maxAlpha, alphaSteps, minBeta, maxBeta, stepsBeta, minGamma_2, maxGamma_s_2, stepPerCore_s);
	#pragma omp section
			Core_3_Result = improveImageQuality_contrastAndGamma(sharpImage, simulatedImage, minAlpha, maxAlpha, alphaSteps, minBeta, maxBeta, stepsBeta, minGamma_3, maxGamma_s_3, stepPerCore_s);
	#pragma omp section
			Core_4_Result = improveImageQuality_contrastAndGamma(sharpImage, simulatedImage, minAlpha, maxAlpha, alphaSteps, minBeta, maxBeta, stepsBeta, minGamma_4, maxGamma_s_4, stepPerCore_s);
	#pragma omp section
			Core_5_Result = improveImageQuality_contrastAndGamma(sharpImage, simulatedImage, minAlpha, maxAlpha, alphaSteps, minBeta, maxBeta, stepsBeta, minGamma_5, maxGamma_s_5, stepPerCore_s);
	#pragma omp section
			Core_6_Result = improveImageQuality_contrastAndGamma(sharpImage, simulatedImage, minAlpha, maxAlpha, alphaSteps, minBeta, maxBeta, stepsBeta, minGamma_6, maxGamma_s_6, stepPerCore_s);
	#pragma omp section
			Core_7_Result = improveImageQuality_contrastAndGamma(sharpImage, simulatedImage, minAlpha, maxAlpha, alphaSteps, minBeta, maxBeta, stepsBeta, minGamma_7, maxGamma_s_7, stepPerCore_s);
	#pragma omp section
		Core_8_Result = improveImageQuality_contrastAndGamma(sharpImage, simulatedImage, minAlpha, maxAlpha, alphaSteps, minBeta, maxBeta, stepsBeta, minGamma_8, maxGamma_s_8, stepPerCore_s);
	}

	std::vector<ContrastAndGammaStruct> bestAllCores{ Core_1_Result, Core_2_Result, Core_3_Result, Core_4_Result, Core_5_Result, Core_6_Result, Core_7_Result, Core_8_Result };

	real bestQuality = bestAllCores.at(0).getQuality();
	real bestAlpha = bestAllCores.at(0).getAlpha();
	real bestBeta = bestAllCores.at(0).getBeta();
	real bestGamma = bestAllCores.at(0).getGamma();

	ContrastAndGammaStruct returnContrastAndGammaStruct;
	returnContrastAndGammaStruct.setImage(bestAllCores.at(0).getImage());
	returnContrastAndGammaStruct.setQuality(bestQuality);
	returnContrastAndGammaStruct.setAlpha(bestAllCores.at(0).getAlpha());
	returnContrastAndGammaStruct.setBeta(bestAllCores.at(0).getBeta());
	returnContrastAndGammaStruct.setGamme(bestAllCores.at(0).getGamma());

	real tempBestQuality;



	// find best result
	for (int i = 0; i < bestAllCores.size(); ++i)
	{
		tempBestQuality = bestAllCores.at(i).getQuality();

		if (tempBestQuality < bestQuality)
		{
			bestQuality = tempBestQuality;
			returnContrastAndGammaStruct.setImage(bestAllCores.at(i).getImage());
			returnContrastAndGammaStruct.setQuality(tempBestQuality);
			returnContrastAndGammaStruct.setAlpha(bestAllCores.at(i).getAlpha());
			returnContrastAndGammaStruct.setBeta(bestAllCores.at(i).getBeta());
			returnContrastAndGammaStruct.setGamme(bestAllCores.at(i).getGamma());

		}

	}

	real improvement = Images::calcImprovement_noNorming(sharpImage, simulatedImage, returnContrastAndGammaStruct.getImage());
	returnContrastAndGammaStruct.setImprovement(improvement);

	return returnContrastAndGammaStruct;

}



//bestParameterStruct_detailEnhance ImproveImageQuality::improveImageQuality_ditailEnhance_multiCore(cv::Mat const sharpImage, cv::Mat const simulatedImage, float const minSigmar_s, float const maxSigmar_s, int const stepsSigmar_s, float const minSigmar_r, float const maxSigmar_r, int const stepsSigmar_r)
//{
//	cv::Mat new_image = cv::Mat::zeros(simulatedImage.size(), simulatedImage.type());
//
//	int numberCores = 8;
//	int stepPerCore_s = stepsSigmar_s / numberCores;
//	float deltaPerCore_s = std::abs(maxSigmar_s - minSigmar_s) / numberCores;
//
//	// core 1
//	float minSigmar_s_1 = minSigmar_s;
//	float  maxSigmar_s_1 = minSigmar_s + deltaPerCore_s;
//	// core 2
//	float minSigmar_s_2 = maxSigmar_s_1;
//	float maxSigmar_s_2 = minSigmar_s + 2 * deltaPerCore_s;
//	// core 3
//	float minSigmar_s_3 = maxSigmar_s_2;
//	float maxSigmar_s_3 = minSigmar_s + 3 * deltaPerCore_s;
//	// core 4
//	float minSigmar_s_4 = maxSigmar_s_3;
//	float maxSigmar_s_4 = minSigmar_s + 4 * deltaPerCore_s;
//	// core 5
//	float minSigmar_s_5 = maxSigmar_s_4;
//	float maxSigmar_s_5 = minSigmar_s + 5 * deltaPerCore_s;
//	// core 6
//	float minSigmar_s_6 = maxSigmar_s_5 ;
//	float maxSigmar_s_6 = minSigmar_s + 6 * deltaPerCore_s;
//	// core 7
//	float minSigmar_s_7 = maxSigmar_s_6;
//	float maxSigmar_s_7 = minSigmar_s + 7 * deltaPerCore_s;
//	// core 8
//	float minSigmar_s_8 = maxSigmar_s_7;
//	float maxSigmar_s_8 = minSigmar_s + 8 * deltaPerCore_s;
//
//
//	bestParameterStruct_detailEnhance Core_1_Result;
//	bestParameterStruct_detailEnhance Core_2_Result;
//	bestParameterStruct_detailEnhance Core_3_Result;
//	bestParameterStruct_detailEnhance Core_4_Result;
//	bestParameterStruct_detailEnhance Core_5_Result;
//	bestParameterStruct_detailEnhance Core_6_Result;
//	bestParameterStruct_detailEnhance Core_7_Result;
//	bestParameterStruct_detailEnhance Core_8_Result;
//
//	#pragma omp parallel
//	#pragma omp sections
//	{
//		#pragma omp section
//		Core_1_Result = improveImageQuality_ditailEnhance(sharpImage, simulatedImage, minSigmar_s_1, maxSigmar_s_1, stepPerCore_s, minSigmar_r, maxSigmar_r, stepsSigmar_r);
//		#pragma omp section
//		Core_2_Result = improveImageQuality_ditailEnhance(sharpImage, simulatedImage, minSigmar_s_2, maxSigmar_s_2, stepPerCore_s, minSigmar_r, maxSigmar_r, stepsSigmar_r);
//		#pragma omp section
// 		Core_3_Result = improveImageQuality_ditailEnhance(sharpImage, simulatedImage, minSigmar_s_3, maxSigmar_s_3, stepPerCore_s, minSigmar_r, maxSigmar_r, stepsSigmar_r);
//		#pragma omp section
//		Core_4_Result = improveImageQuality_ditailEnhance(sharpImage, simulatedImage, minSigmar_s_4, maxSigmar_s_4, stepPerCore_s, minSigmar_r, maxSigmar_r, stepsSigmar_r);
//		#pragma omp section
//		Core_5_Result = improveImageQuality_ditailEnhance(sharpImage, simulatedImage, minSigmar_s_5, maxSigmar_s_5, stepPerCore_s, minSigmar_r, maxSigmar_r, stepsSigmar_r);
//		#pragma omp section
//		Core_6_Result = improveImageQuality_ditailEnhance(sharpImage, simulatedImage, minSigmar_s_6, maxSigmar_s_6, stepPerCore_s, minSigmar_r, maxSigmar_r, stepsSigmar_r);
//		#pragma omp section
//		Core_7_Result = improveImageQuality_ditailEnhance(sharpImage, simulatedImage, minSigmar_s_7, maxSigmar_s_7, stepPerCore_s, minSigmar_r, maxSigmar_r, stepsSigmar_r);
//		#pragma omp section
//		Core_8_Result = improveImageQuality_ditailEnhance(sharpImage, simulatedImage, minSigmar_s_8, maxSigmar_s_8, stepPerCore_s, minSigmar_r, maxSigmar_r, stepsSigmar_r);
//	}
//
//	std::vector<bestParameterStruct_detailEnhance> bestAllCores{Core_1_Result, Core_2_Result, Core_3_Result, Core_4_Result, Core_5_Result, Core_6_Result, Core_7_Result, Core_8_Result };
//
//	//// debug
//	//Images::showImage_inputUint8("1", Core_1_Result.getImage());
//	//Images::showImage_inputUint8("2", Core_8_Result.getImage());
//
//	real minDif = bestAllCores.at(0).getDifference();
//	float bestSigmar_s = bestAllCores.at(0).getSigmar_s();
//	float bestSigmar_r = bestAllCores.at(0).getSigmar_r();
//	
//	bestParameterStruct_detailEnhance returnDetailEnhanceStruct;
//	returnDetailEnhanceStruct.setImage(bestAllCores.at(0).getImage());
//	returnDetailEnhanceStruct.setDifference(minDif);
//	returnDetailEnhanceStruct.setSigmar_s(bestAllCores.at(0).getSigmar_s());
//	returnDetailEnhanceStruct.setSigmar_r(bestAllCores.at(0).getSigmar_r());
//
//	real tempMinDif;
//	
//	
//	// find best result
//	for (int i = 0; i < bestAllCores.size(); ++i)
//	{
//		tempMinDif = bestAllCores.at(i).getDifference();
//
//		if (tempMinDif < minDif)
//		{
//			minDif = tempMinDif;
//			returnDetailEnhanceStruct.setImage(bestAllCores.at(i).getImage());
//			returnDetailEnhanceStruct.setDifference(tempMinDif);
//			returnDetailEnhanceStruct.setSigmar_s(bestAllCores.at(i).getSigmar_s());
//			returnDetailEnhanceStruct.setSigmar_r(bestAllCores.at(i).getSigmar_r());
//			
//		}
//
// 	}
//
//	real improvement = Images::calcImprovement_noNorming(sharpImage, simulatedImage, returnDetailEnhanceStruct.getImage());
//	returnDetailEnhanceStruct.setImprovement(improvement);
//
//	return returnDetailEnhanceStruct;
//}



bilateralFilterStruct ImproveImageQuality::improveImageQuality_bilateralFilter(cv::Mat const& sharpImage, cv::Mat simulatedImage , int const& minD, int const& maxD, int const& stepsD, double const& minSimgaColor, double const& maxSigmaColor, int const& stepsSigmaColor, double const& minSigmaSpace, double const& maxSigmaSpace, double const& stepsSigmaSpace, int const& boarderType)
{
	bilateralFilterStruct retunrBestResult_bilateralFilter;

	std::vector<int> d_vec = Math::linDistriAlongTwoValues_int(minD, maxD, stepsD);
	std::vector<real> sigmaColor_vec = Math::linDistriAlongTwoValues_double(minSimgaColor, maxSigmaColor, stepsSigmaColor);
	std::vector<real> sigmaSpace_vec = Math::linDistriAlongTwoValues_double(minSigmaSpace, maxSigmaSpace, stepsSigmaSpace);


	cv::Mat new_image = cv::Mat::zeros(simulatedImage.size(), simulatedImage.type());

	int bestD;
	real bestSigmaColor;
	real bestSigmaSpace;

	double bestQuality = Images::calcSumMatrix(Images::PerElementAbsDifference(simulatedImage, sharpImage));
	double tempBestQuality = Images::calcSumMatrix(Images::PerElementAbsDifference(new_image, sharpImage));

	retunrBestResult_bilateralFilter.setImage(simulatedImage);
	retunrBestResult_bilateralFilter.setQuality(bestQuality);

	for (int d_loop = 0; d_loop < d_vec.size(); d_loop++)
	{
		for (int color_loop = 0; color_loop < sigmaColor_vec.size(); color_loop++)
		{
			for (int space_loop = 0; space_loop < sigmaSpace_vec.size(); space_loop++)
			{
			
				new_image = ImageProcessing::bilateralFilter(simulatedImage, d_vec.at(d_loop), sigmaColor_vec.at(color_loop), sigmaSpace_vec.at(space_loop), boarderType);

				tempBestQuality = Images::calcSumMatrix(Images::PerElementAbsDifference(new_image, sharpImage));

				//std::cout << "_______________" << std::endl;
				//std::cout << "d " << d_vec.at(d_loop) << std::endl;
				//std::cout << "sigma color " << sigmaColor_vec.at(color_loop) << std::endl;
				//std::cout << "sigma space " << sigmaSpace_vec.at(space_loop) << std::endl;
				//std::cout << "tempBestResult - best result " << tempBestQuality - bestQuality << std::endl;
				//std::cout << "_______________" << std::endl;

				if (tempBestQuality < bestQuality)
				{
					bestQuality = tempBestQuality;
					retunrBestResult_bilateralFilter.setImage(new_image);
					retunrBestResult_bilateralFilter.setQuality(tempBestQuality);
					retunrBestResult_bilateralFilter.setD(d_vec.at(d_loop));
					retunrBestResult_bilateralFilter.setSigmarColor(sigmaColor_vec.at(color_loop));
					retunrBestResult_bilateralFilter.setSigmaSpace(sigmaSpace_vec.at(space_loop));
					retunrBestResult_bilateralFilter.setBoarderType(boarderType);

					real improvement = Images::calcImprovement_noNorming(sharpImage, simulatedImage, new_image);
					retunrBestResult_bilateralFilter.setImprovement(improvement);

					retunrBestResult_bilateralFilter.exportAsTXTfile();
				}


			}

		}
	}

	real improvement = Images::calcImprovement_noNorming(sharpImage, simulatedImage, retunrBestResult_bilateralFilter.getImage());
	retunrBestResult_bilateralFilter.setImprovement(improvement);

	return retunrBestResult_bilateralFilter;
}

bilateralFilterStruct ImproveImageQuality::improveImageQuality_bilateralFilter_multiCore(cv::Mat const& sharpImage, cv::Mat simulatedImage, int const& minD, int const& maxD, int const& stepsD, double const& minSimgaColor, double const& maxSigmaColor, int const& stepsSigmaColor, double const& minSigmaSpace, double const& maxSigmaSpace, double const& stepsSigmaSpace, int const& boarderType)
{

	cv::Mat new_image = cv::Mat::zeros(simulatedImage.size(), simulatedImage.type());

	int const& numberCores = 8;

	int const& stepPerCore = ceil(stepsSigmaSpace / numberCores);
	float const& deltaPerCore_s = std::abs(maxSigmaSpace - minSigmaSpace) / numberCores;


	// core 1
	real const& minSigmaSapace_1 = minSigmaSpace;
	real const& maxSigmaSapace_1 = minSigmaSpace + deltaPerCore_s;
	// core 2
	real const& minSigmaSapace_2 = maxSigmaSapace_1;
	real const& maxSigmaSapace_2 = minSigmaSpace + 2 * deltaPerCore_s;
	// core 3
	real const& minSigmaSapace_3 = maxSigmaSapace_2;
	real const& maxSigmaSapace_3 = minSigmaSpace + 3 * deltaPerCore_s;
	// core 4
	real const& minSigmaSapace_4 = maxSigmaSapace_3;
	real const& maxSigmaSapace_4 = minSigmaSpace + 4 * deltaPerCore_s;
	// core 5
	real const& minSigmaSapace_5 = maxSigmaSapace_4;
	real const& maxSigmaSapace_5 = minSigmaSpace + 5 * deltaPerCore_s;
	// core 6
	real const& minSigmaSapace_6 = maxSigmaSapace_5;
	real const& maxSigmaSapace_6 = minSigmaSpace + 6 * deltaPerCore_s;
	// core 7
	real const& minSigmaSapace_7 = maxSigmaSapace_6;
	real const& maxSigmaSapace_7 = minSigmaSpace + 7 * deltaPerCore_s;
	// core 8
	real const& minSigmaSapace_8 = maxSigmaSapace_7;
	real const& maxSigmaSapace_8 = minSigmaSpace + 8 * deltaPerCore_s;


	bilateralFilterStruct Core_1_Result;
	bilateralFilterStruct Core_2_Result;
	bilateralFilterStruct Core_3_Result;
	bilateralFilterStruct Core_4_Result;
	bilateralFilterStruct Core_5_Result;
	bilateralFilterStruct Core_6_Result;
	bilateralFilterStruct Core_7_Result;
	bilateralFilterStruct Core_8_Result;

	#pragma omp parallel
	#pragma omp sections
	{
		#pragma omp section
		Core_1_Result = improveImageQuality_bilateralFilter(sharpImage, simulatedImage, minD, maxD, stepsD, minSimgaColor, maxSigmaColor, stepsSigmaColor, minSigmaSapace_1, maxSigmaSapace_1, stepPerCore,boarderType);
		#pragma omp section
		Core_2_Result = improveImageQuality_bilateralFilter(sharpImage, simulatedImage, minD, maxD, stepsD, minSimgaColor, maxSigmaColor, stepsSigmaColor, minSigmaSapace_2, maxSigmaSapace_2, stepPerCore, boarderType);
		#pragma omp section
		Core_3_Result = improveImageQuality_bilateralFilter(sharpImage, simulatedImage, minD, maxD, stepsD, minSimgaColor, maxSigmaColor, stepsSigmaColor, minSigmaSapace_3, maxSigmaSapace_3, stepPerCore, boarderType);
		#pragma omp section
		Core_4_Result = improveImageQuality_bilateralFilter(sharpImage, simulatedImage, minD, maxD, stepsD, minSimgaColor, maxSigmaColor, stepsSigmaColor, minSigmaSapace_4, maxSigmaSapace_4, stepPerCore, boarderType);
		#pragma omp section
		Core_5_Result = improveImageQuality_bilateralFilter(sharpImage, simulatedImage, minD, maxD, stepsD, minSimgaColor, maxSigmaColor, stepsSigmaColor, minSigmaSapace_5, maxSigmaSapace_5, stepPerCore, boarderType);
		#pragma omp section
		Core_6_Result = improveImageQuality_bilateralFilter(sharpImage, simulatedImage, minD, maxD, stepsD, minSimgaColor, maxSigmaColor, stepsSigmaColor, minSigmaSapace_6, maxSigmaSapace_6, stepPerCore, boarderType);
		#pragma omp section
		Core_7_Result = improveImageQuality_bilateralFilter(sharpImage, simulatedImage, minD, maxD, stepsD, minSimgaColor, maxSigmaColor, stepsSigmaColor, minSigmaSapace_7, maxSigmaSapace_7, stepPerCore, boarderType);
		#pragma omp section
		Core_8_Result = improveImageQuality_bilateralFilter(sharpImage, simulatedImage, minD, maxD, stepsD, minSimgaColor, maxSigmaColor, stepsSigmaColor, minSigmaSapace_8, maxSigmaSapace_8, stepPerCore, boarderType);
	}

	std::vector<bilateralFilterStruct> bestAllCores{ Core_1_Result, Core_2_Result, Core_3_Result, Core_4_Result, Core_5_Result, Core_6_Result, Core_7_Result, Core_8_Result };

	real bestQuality = bestAllCores.at(0).getQuality();
	int bestD = bestAllCores.at(0).getD();
	real bestSigmaColor = bestAllCores.at(0).getSigmaColor();
	real bestSigmarSpace = bestAllCores.at(0).getSigmaSpace();
	int bestBoarderType = bestAllCores.at(0).getBoarderType();
	
	bilateralFilterStruct returnbilateralFilterStruct;
	returnbilateralFilterStruct.setImage(simulatedImage);
	returnbilateralFilterStruct.setImage(bestAllCores.at(0).getImage());
	returnbilateralFilterStruct.setQuality(bestQuality);
	returnbilateralFilterStruct.setD(bestAllCores.at(0).getD());
	returnbilateralFilterStruct.setSigmarColor(bestAllCores.at(0).getSigmaColor());
	returnbilateralFilterStruct.setSigmaSpace(bestAllCores.at(0).getSigmaSpace());
	returnbilateralFilterStruct.setBoarderType(bestAllCores.at(0).getBoarderType());

	real tempBestQuality;
	
	// find best result
	for (int i = 0; i < bestAllCores.size(); ++i)
	{
		tempBestQuality = bestAllCores.at(i).getQuality();

		if (tempBestQuality < bestQuality)
		{
			bestQuality = tempBestQuality;
			returnbilateralFilterStruct.setImage(bestAllCores.at(i).getImage());
			returnbilateralFilterStruct.setQuality(tempBestQuality);
			returnbilateralFilterStruct.setD(bestAllCores.at(i).getD());
			returnbilateralFilterStruct.setSigmarColor(bestAllCores.at(i).getSigmaColor());
			returnbilateralFilterStruct.setSigmaSpace(bestAllCores.at(i).getSigmaSpace());
			returnbilateralFilterStruct.setBoarderType(bestAllCores.at(i).getBoarderType());

		}

	}

	real improvement = Images::calcImprovement_noNorming(sharpImage, simulatedImage, returnbilateralFilterStruct.getImage());
	returnbilateralFilterStruct.setImprovement(improvement);

	return returnbilateralFilterStruct;

}







medianBlurStruct ImproveImageQuality::improveImageQuality_medianBlur(cv::Mat const& sharpImage, cv::Mat const& simulatedImage, std::vector<int> const& kernelSize_vec)
{

	medianBlurStruct returnBestResult_medianBlur;
	
	cv::Mat new_image = cv::Mat::zeros(simulatedImage.size(), simulatedImage.type());


	double bestResult = Images::calcSumMatrix(Images::PerElementAbsDifference(simulatedImage, sharpImage));

	double tempBestResult = Images::calcSumMatrix(Images::PerElementAbsDifference(new_image, sharpImage));

	returnBestResult_medianBlur.setImage(simulatedImage);
	returnBestResult_medianBlur.setQuality(bestResult);
	returnBestResult_medianBlur.setKernelSize(0);

	for (int kernelSize_loop = 0; kernelSize_loop < kernelSize_vec.size(); kernelSize_loop++)
	{

		new_image = ImageProcessing::MedianBlurFilter(simulatedImage, kernelSize_vec.at(kernelSize_loop));
		tempBestResult = Images::calcSumMatrix(Images::PerElementAbsDifference(new_image, sharpImage));

		if (tempBestResult < bestResult)
		{
			bestResult = tempBestResult;
			returnBestResult_medianBlur.setImage(new_image);
			returnBestResult_medianBlur.setQuality(tempBestResult);
			returnBestResult_medianBlur.setKernelSize(kernelSize_vec.at(kernelSize_loop));

			real improvement = Images::calcImprovement_noNorming(sharpImage, simulatedImage, new_image);
			returnBestResult_medianBlur.setImprovement(improvement);

			returnBestResult_medianBlur.exportAsTXTfile();
		}

		//std::cout << "_______________" << std::endl;
		//std::cout << "kernel size " << kernelSize_vec.at(kernelSize_loop) << std::endl;
		//std::cout << "_______________" << std::endl;
	}

	real improvement = Images::calcImprovement_noNorming(sharpImage, simulatedImage, returnBestResult_medianBlur.getImage());
	returnBestResult_medianBlur.setImprovement(improvement);

	return returnBestResult_medianBlur;

}


