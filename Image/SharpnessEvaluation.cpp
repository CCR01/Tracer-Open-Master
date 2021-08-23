#include "SharpnessEvaluation.h"

// often use
#include "..\oftenUseNamespace\oftenUseNamespace.h"

// images
#include "..\Image\Images.h"

SharpnessEvaluation::SharpnessEvaluation() {}

SharpnessEvaluation::~SharpnessEvaluation() {}

// there are different methodes to evaluate the sharpness of an image
// Some of them can be found here: https://programmersought.com/article/6657657740/
// We used the code from there and modyfied it for our purpose

// Brenner
// from https://programmersought.com/article/6657657740/
real SharpnessEvaluation::sharpnessEval_brenner_gray8UN(cv::Mat& gray_img)
{
	if (gray_img.channels() == 3)
	{
		oftenUse::errorProtocol_stopSystem("this is not a gray image", "Brenner - SharpnessEvaluation.cpp", 0, true);
	}

	double result = .0f;
	for (int i = 0; i < gray_img.rows; ++i)
	{
		uchar* data = gray_img.ptr<uchar>(i);
		for (int j = 0; j < gray_img.cols - 2; ++j) {
			result += pow(data[j + 2] - data[j], 2);
		}
	}

	return result / gray_img.total();
}

real SharpnessEvaluation::sharpnessEval_brenner_colorUN(cv::Mat& color_ima)
{
	// split color image
	std::vector<cv::Mat> grayIma_vec = Images::splitImageBGR(color_ima);

	// blue
	cv::Mat ima_blue = grayIma_vec[0];
	// green
	cv::Mat ima_green = grayIma_vec[1];
	// red
	cv::Mat ima_red = grayIma_vec[2];

	real sharpness_blue = sharpnessEval_brenner_gray8UN(ima_blue);
	real sharpness_green = sharpnessEval_brenner_gray8UN(ima_green);
	real sharpness_red = sharpnessEval_brenner_gray8UN(ima_red);

	real totalSharpness = (sharpness_blue + sharpness_green + sharpness_red) / 3.0;

	return totalSharpness;
}

// Tenengrad gradient method
// from https://programmersought.com/article/6657657740/
real SharpnessEvaluation::sharpnessEval_tenengrad_gray8UN(cv::Mat& gray_ima)
{
	if (gray_ima.channels() == 3)
	{
		oftenUse::errorProtocol_stopSystem("this is not a gray image", "Tenengrad - SharpnessEvaluation.cpp", 0, true);
	}

	cv::Mat sobel_x, sobel_y, G;

	// Calculate the gradient in the x / y direction
	cv::Sobel(gray_ima, sobel_x, CV_32FC1, 1, 0);
	cv::Sobel(gray_ima, sobel_y, CV_32FC1, 0, 1);
	cv::multiply(sobel_x, sobel_x, sobel_x);
	cv::multiply(sobel_y, sobel_y, sobel_y);
	cv::Mat sqrt_mat = sobel_x + sobel_y;
	cv::sqrt(sqrt_mat, G);

	return cv::mean(G)[0];
}

real SharpnessEvaluation::sharpnessEval_tenegrad_colorUN(cv::Mat& color_ima)
{
	// split color image
	std::vector<cv::Mat> grayIma_vec = Images::splitImageBGR(color_ima);

	// blue
	cv::Mat ima_blue = grayIma_vec[0];
	// green
	cv::Mat ima_green = grayIma_vec[1];
	// red
	cv::Mat ima_red = grayIma_vec[2];

	real sharpness_blue = sharpnessEval_tenengrad_gray8UN(ima_blue);
	real sharpness_green = sharpnessEval_tenengrad_gray8UN(ima_green);
	real sharpness_red = sharpnessEval_tenengrad_gray8UN(ima_red);

	real totalSharpness = (sharpness_blue + sharpness_green + sharpness_red) / 3.0;

	return totalSharpness;
}

// Laplacian gradient function
// from https://programmersought.com/article/6657657740/
real SharpnessEvaluation::sharpnessEval_laplacian_gray8UN(cv::Mat& gray_ima)
{
	if (gray_ima.channels() == 3)
	{
		oftenUse::errorProtocol_stopSystem("this is not a gray image", "Laplacian - SharpnessEvaluation.cpp", 0, true);
	}

	cv::Mat lap_image;
	cv::Laplacian(gray_ima, lap_image, CV_32FC1);
	lap_image = cv::abs(lap_image);

	return cv::mean(lap_image)[0];
}

real SharpnessEvaluation::sharpnessEval_laplacian_colorUN(cv::Mat& color_ima)
{
	// split color image
	std::vector<cv::Mat> grayIma_vec = Images::splitImageBGR(color_ima);

	// blue
	cv::Mat ima_blue = grayIma_vec[0];
	// green
	cv::Mat ima_green = grayIma_vec[1];
	// red
	cv::Mat ima_red = grayIma_vec[2];

	real sharpness_blue = sharpnessEval_laplacian_gray8UN(ima_blue);
	real sharpness_green = sharpnessEval_laplacian_gray8UN(ima_green);
	real sharpness_red = sharpnessEval_laplacian_gray8UN(ima_red);

	real totalSharpness = (sharpness_blue + sharpness_green + sharpness_red) / 3.0;

	return totalSharpness;
}

// SMD function
// from https://programmersought.com/article/6657657740/
real SharpnessEvaluation::sharpnessEval_SMD_gray8UN(cv::Mat& gray_ima)
{


	if (gray_ima.channels() == 3)
	{
		oftenUse::errorProtocol_stopSystem("this is not a gray image", "SMD - SharpnessEvaluation.cpp", 0, true);
	}

	cv::Mat smd_image_x, smd_image_y, G;
	cv::Mat kernel_x(3, 3, CV_32F, cv::Scalar(0));
	kernel_x.at<float>(1, 2) = -1.0;
	kernel_x.at<float>(1, 1) = 1.0;
	cv::Mat kernel_y(3, 3, CV_32F, cv::Scalar(0));
	kernel_y.at<float>(0, 1) = -1.0;
	kernel_y.at<float>(1, 1) = 1.0;
	cv::filter2D(gray_ima, smd_image_x, gray_ima.depth(), kernel_x);
	cv::filter2D(gray_ima, smd_image_y, gray_ima.depth(), kernel_y);

	smd_image_x = cv::abs(smd_image_x);
	smd_image_y = cv::abs(smd_image_y);
	G = smd_image_x + smd_image_y;

	return cv::mean(G)[0];
}
real SharpnessEvaluation::sharpnessEval_SMD_colorUN(cv::Mat& color_ima)
{
	// split color image
	std::vector<cv::Mat> grayIma_vec = Images::splitImageBGR(color_ima);

	// blue
	cv::Mat ima_blue = grayIma_vec[0];
	// green
	cv::Mat ima_green = grayIma_vec[1];
	// red
	cv::Mat ima_red = grayIma_vec[2];

	real sharpness_blue = sharpnessEval_SMD_gray8UN(ima_blue);
	real sharpness_green = sharpnessEval_SMD_gray8UN(ima_green);
	real sharpness_red = sharpnessEval_SMD_gray8UN(ima_red);

	real totalSharpness = (sharpness_blue + sharpness_green + sharpness_red) / 3.0;

	return totalSharpness;
}

//  SMD2 function
// from https://programmersought.com/article/6657657740/
real SharpnessEvaluation::sharpnessEval_SMD2_gray8UN(cv::Mat& gray_ima)
{
	if (gray_ima.channels() == 3)
	{
		oftenUse::errorProtocol_stopSystem("this is not a gray image", "SMD2 - SharpnessEvaluation.cpp", 0, true);
	}

	cv::Mat smd_image_x, smd_image_y, G;
	cv::Mat kernel_x(3, 3, CV_32F, cv::Scalar(0));
	kernel_x.at<float>(1, 2) = -1.0;
	kernel_x.at<float>(1, 1) = 1.0;
	cv::Mat kernel_y(3, 3, CV_32F, cv::Scalar(0));
	kernel_y.at<float>(1, 1) = 1.0;
	kernel_y.at<float>(2, 1) = -1.0;
	cv::filter2D(gray_ima, smd_image_x, gray_ima.depth(), kernel_x);
	cv::filter2D(gray_ima, smd_image_y, gray_ima.depth(), kernel_y);

	smd_image_x = cv::abs(smd_image_x);
	smd_image_y = cv::abs(smd_image_y);
	cv::multiply(smd_image_x, smd_image_y, G);

	return cv::mean(G)[0];
}

real SharpnessEvaluation::sharpnessEval_SMD2_colorUN(cv::Mat& color_ima)
{
	// split color image
	std::vector<cv::Mat> grayIma_vec = Images::splitImageBGR(color_ima);

	// blue
	cv::Mat ima_blue = grayIma_vec[0];
	// green
	cv::Mat ima_green = grayIma_vec[1];
	// red
	cv::Mat ima_red = grayIma_vec[2];

	real sharpness_blue = sharpnessEval_SMD2_gray8UN(ima_blue);
	real sharpness_green = sharpnessEval_SMD2_gray8UN(ima_green);
	real sharpness_red = sharpnessEval_SMD2_gray8UN(ima_red);

	real totalSharpness = (sharpness_blue + sharpness_green + sharpness_red) / 3.0;

	return totalSharpness;
}

// energy gradient function
// from https://programmersought.com/article/6657657740/
real SharpnessEvaluation::sharpnessEval_EnergyGradFct_gray8UN(cv::Mat& gray_ima)
{


	if (gray_ima.channels() == 3)
	{
		oftenUse::errorProtocol_stopSystem("this is not a gray image", "EnergyGradFct - SharpnessEvaluation.cpp", 0, true);
	}

	cv::Mat smd_image_x, smd_image_y, G;
	cv::Mat kernel_x(3, 3, CV_32F, cv::Scalar(0));
	kernel_x.at<float>(1, 2) = -1.0;
	kernel_x.at<float>(1, 1) = 1.0;
	cv::Mat kernel_y(3, 3, CV_32F, cv::Scalar(0));
	kernel_y.at<float>(1, 1) = 1.0;
	kernel_y.at<float>(2, 1) = -1.0;
	cv::filter2D(gray_ima, smd_image_x, gray_ima.depth(), kernel_x);
	cv::filter2D(gray_ima, smd_image_y, gray_ima.depth(), kernel_y);

	cv::multiply(smd_image_x, smd_image_x, smd_image_x);
	cv::multiply(smd_image_y, smd_image_y, smd_image_y);
	G = smd_image_x + smd_image_y;

	return cv::mean(G)[0];

}
real SharpnessEvaluation::sharpnessEval_EnergyGradFct_colorUN(cv::Mat& color_ima)
{
	// split color image
	std::vector<cv::Mat> grayIma_vec = Images::splitImageBGR(color_ima);

	// blue
	cv::Mat ima_blue = grayIma_vec[0];
	// green
	cv::Mat ima_green = grayIma_vec[1];
	// red
	cv::Mat ima_red = grayIma_vec[2];

	real sharpness_blue = sharpnessEval_EnergyGradFct_gray8UN(ima_blue);
	real sharpness_green = sharpnessEval_EnergyGradFct_gray8UN(ima_green);
	real sharpness_red = sharpnessEval_EnergyGradFct_gray8UN(ima_red);

	real totalSharpness = (sharpness_blue + sharpness_green + sharpness_red) / 3.0;

	return totalSharpness;
}

// EAV point sharpness algorithm function
// from https://programmersought.com/article/6657657740/
real SharpnessEvaluation::sharpnessEval_EVA_gray8UN(cv::Mat& gray_ima)
{

	if (gray_ima.channels() == 3)
	{
		oftenUse::errorProtocol_stopSystem("this is not a gray image", "EVA - SharpnessEvaluation.cpp", 0, true);
	}

	cv::Mat smd_image_x, smd_image_y, G;
	double result = .0f;
	for (int i = 1; i < gray_ima.rows - 1; ++i)
	{
		uchar* prev = gray_ima.ptr<uchar>(i - 1);
		uchar* cur = gray_ima.ptr<uchar>(i);
		uchar* next = gray_ima.ptr<uchar>(i + 1);
		for (int j = 0; j < gray_ima.cols; ++j) {
			result += (abs(prev[j - 1] - cur[i]) * 0.7 + abs(prev[j] - cur[j]) + abs(prev[j + 1] - cur[j]) * 0.7 +
				abs(next[j - 1] - cur[j]) * 0.7 + abs(next[j] - cur[j]) + abs(next[j + 1] - cur[j]) * 0.7 +
				abs(cur[j - 1] - cur[j]) + abs(cur[j + 1] - cur[j]));
		}
	}

	return result / gray_ima.total();
}

// from https://programmersought.com/article/6657657740/
real SharpnessEvaluation::sharpnessEval_EVA_colorUN(cv::Mat& color_ima)
{
	// split color image
	std::vector<cv::Mat> grayIma_vec = Images::splitImageBGR(color_ima);

	// blue
	cv::Mat ima_blue = grayIma_vec[0];
	// green
	cv::Mat ima_green = grayIma_vec[1];
	// red
	cv::Mat ima_red = grayIma_vec[2];

	real sharpness_blue = sharpnessEval_EVA_gray8UN(ima_blue);
	real sharpness_green = sharpnessEval_EVA_gray8UN(ima_green);
	real sharpness_red = sharpnessEval_EVA_gray8UN(ima_red);

	real totalSharpness = (sharpness_blue + sharpness_green + sharpness_red) / 3.0;

	return totalSharpness;
}

// NRSS gradient structure similarity
// from https://programmersought.com/article/6657657740/
real SharpnessEvaluation::sharpnessEval_NRSS_gray8UN(cv::Mat& gray_ima)
{


	if (gray_ima.channels() == 3)
	{
		oftenUse::errorProtocol_stopSystem("this is not a gray image", "NRSS - SharpnessEvaluation.cpp", 0, true);
	}

	cv::Mat Ir, G, Gr;
	// Construct a reference image
	cv::GaussianBlur(gray_ima, Ir, cv::Size(7, 7), 6, 6);

	// Extract the gradient information of the image and reference image
	cv::Sobel(gray_ima, G, CV_32FC1, 1, 1);//calculate the original image sobel gradient
	cv::Sobel(Ir, Gr, CV_32FC1, 1, 1);//calculate the sobel gradient of the constructor

	// Find the N image blocks with the most gradient information in the gradient image G, n = 64 (that is, the size is divided into 8x8)
	// Calculate the width / height of each small square
	int block_cols = G.cols * 2 / 9;
	int block_rows = G.rows * 2 / 9;
	// Get the block with the largest variance
	cv::Mat best_G, best_Gr;
	float max_stddev = .0f;
	int pos = 0;
	for (int i = 0; i < 64; ++i) {
		int left_x = (i % 8) * (block_cols / 2);
		int left_y = (i / 8) * (block_rows / 2);
		int right_x = left_x + block_cols;
		int right_y = left_y + block_rows;

		if (left_x < 0) left_x = 0;
		if (left_y < 0) left_y = 0;
		if (right_x >= G.cols) right_x = G.cols - 1;
		if (right_y >= G.rows) right_y = G.rows - 1;

		cv::Rect roi(left_x, left_y, right_x - left_x, right_y - left_y);
		cv::Mat temp = G(roi).clone();
		cv::Scalar mean, stddev;
		cv::meanStdDev(temp, mean, stddev);
		if (stddev.val[0] > max_stddev) {
			max_stddev = static_cast<float>(stddev.val[0]);
			pos = i;
			best_G = temp;
			best_Gr = Gr(roi).clone();
		}
	}

	// Calculate the structural clarity NRSS
	double result = 1 - ssim(best_G, best_Gr);

	return result;
}

// from https://programmersought.com/article/6657657740/
real SharpnessEvaluation::ssim(cv::Mat& i1, cv::Mat& i2)
{
	const double C1 = 6.5025, C2 = 58.5225;
	int d = CV_32F;
	cv::Mat I1, I2;
	i1.convertTo(I1, d);
	i2.convertTo(I2, d);
	cv::Mat I1_2 = I1.mul(I1);
	cv::Mat I2_2 = I2.mul(I2);
	cv::Mat I1_I2 = I1.mul(I2);
	cv::Mat mu1, mu2;
	GaussianBlur(I1, mu1, cv::Size(11, 11), 1.5);
	GaussianBlur(I2, mu2, cv::Size(11, 11), 1.5);
	cv::Mat mu1_2 = mu1.mul(mu1);
	cv::Mat mu2_2 = mu2.mul(mu2);
	cv::Mat mu1_mu2 = mu1.mul(mu2);
	cv::Mat sigma1_2, sigam2_2, sigam12;
	GaussianBlur(I1_2, sigma1_2, cv::Size(11, 11), 1.5);
	sigma1_2 -= mu1_2;
	GaussianBlur(I2_2, sigam2_2, cv::Size(11, 11), 1.5);
	sigam2_2 -= mu2_2;
	GaussianBlur(I1_I2, sigam12, cv::Size(11, 11), 1.5);
	sigam12 -= mu1_mu2;
	cv::Mat t1, t2, t3;
	t1 = 2 * mu1_mu2 + C1;
	t2 = 2 * sigam12 + C2;
	t3 = t1.mul(t2);

	t1 = mu1_2 + mu2_2 + C1;
	t2 = sigma1_2 + sigam2_2 + C2;
	t1 = t1.mul(t2);

	cv::Mat ssim_map;
	divide(t3, t1, ssim_map);
	cv::Scalar mssim = cv::mean(ssim_map);

	double ssim = (mssim.val[0] + mssim.val[1] + mssim.val[2]) / 3;
	return ssim;
}

real SharpnessEvaluation::sharpnessEval_NRSS_colorUN(cv::Mat& color_ima)
{
	// split color image
	std::vector<cv::Mat> grayIma_vec = Images::splitImageBGR(color_ima);

	// blue
	cv::Mat ima_blue = grayIma_vec[0];
	// green
	cv::Mat ima_green = grayIma_vec[1];
	// red
	cv::Mat ima_red = grayIma_vec[2];

	real sharpness_blue = sharpnessEval_NRSS_gray8UN(ima_blue);
	real sharpness_green = sharpnessEval_NRSS_gray8UN(ima_green);
	real sharpness_red = sharpnessEval_NRSS_gray8UN(ima_red);

	real totalSharpness = (sharpness_blue + sharpness_green + sharpness_red) / 3.0;

	return totalSharpness;
}

// from https://programmersought.com/article/6657657740/
real SharpnessEvaluation::sharpnessEval_blur_noise_IQA_gray8UN(cv::Mat& gray_ima)
{
	if (gray_ima.channels() == 3)
	{
		oftenUse::errorProtocol_stopSystem("this is not a gray image", "IQA - SharpnessEvaluation.cpp", 0, true);
	}

	//1, fuzzy detection
	float blur_mean = 0.f, blur_ratio = 0.f;
	comput_blur_IQA(gray_ima, blur_mean, blur_ratio);

	//2, noise point detection
	float noise_mean = 0.f, noise_ratio = 0.f;
	compute_noise_IQA(gray_ima, noise_mean, noise_ratio);

	//3, combination of noise and blur
	double result = 1 - (blur_mean + 0.95 * blur_ratio + 0.3 * noise_mean + 0.75 * noise_ratio);
	return result;
}

// from https://programmersought.com/article/6657657740/
void SharpnessEvaluation::comput_blur_IQA(cv::Mat& src, float& blur_mean, float& blur_ratio)
{
	cv::Mat gray_img = src.clone();
	// Calculate the horizontal / vertical difference to obtain the gradient map
	cv::Mat grad_h, grad_v;
	cv::Mat kernel_h = cv::Mat::zeros(cv::Size(3, 3), CV_32FC1);
	kernel_h.at<float>(0, 1) = -1;
	kernel_h.at<float>(2, 1) = 1;
	cv::filter2D(gray_img, grad_h, CV_32FC1, kernel_h);
	cv::Mat kernel_v = cv::Mat::zeros(cv::Size(3, 3), CV_32FC1);
	kernel_v.at<float>(1, 0) = -1;
	kernel_v.at<float>(1, 2) = 1;
	cv::filter2D(gray_img, grad_v, CV_32FC1, kernel_v);

	// Get candidate edge points
	// Filter conditions : D_h > D_mean
	float mean = static_cast<float>(cv::mean(grad_v)[0]);
	cv::Mat mask = grad_h > mean;
	mask = mask / 255;
	mask.convertTo(mask, CV_32FC1);
	cv::Mat C_h;
	cv::multiply(grad_h, mask, C_h);


	// Further screening edge points
		//Filter condition: C_h(x,y) > C_h(x,y-1) and C_h(x,y) > C_h(x,y+1)
	cv::Mat edge = cv::Mat::zeros(C_h.rows, C_h.cols, CV_8UC1);
	for (int i = 1; i < C_h.rows - 1; ++i) {
		float* prev = C_h.ptr<float>(i - 1);
		float* cur = C_h.ptr<float>(i);
		float* next = C_h.ptr<float>(i + 1);
		uchar* data = edge.ptr<uchar>(i);
		for (int j = 0; j < C_h.cols; ++j) {
			if (prev[j] < cur[j] && next[j] < cur[j]) {
				data[j] = 1;
			}
		}
	}

	// Check whether the edge points are blurred
	// Get infrared blur
	cv::Mat A_h = grad_h / 2;
	cv::Mat BR_h = cv::Mat(gray_img.size(), CV_32FC1);
	gray_img.convertTo(gray_img, CV_32FC1);
	cv::absdiff(gray_img, A_h, BR_h);
	cv::divide(BR_h, A_h, BR_h);
	cv::Mat A_v = grad_v / 2;
	cv::Mat BR_v;
	cv::absdiff(gray_img, A_v, BR_v);
	cv::divide(BR_v, A_v, BR_v);

	cv::Mat inv_blur = cv::Mat::zeros(BR_v.rows, BR_v.cols, CV_32FC1);
	for (int i = 0; i < inv_blur.rows; ++i) {
		float* data_v = BR_v.ptr<float>(i);
		float* data = inv_blur.ptr<float>(i);
		float* data_h = BR_h.ptr<float>(i);
		for (int j = 0; j < inv_blur.cols; ++j) {
			data[j] = data_v[j] > data_h[j] ? data_v[j] : data_h[j];
		}
	}
	// Get the final blur point
	cv::Mat blur = inv_blur < 0.1 / 255;
	blur.convertTo(blur, CV_32FC1);

	// Calculate the mean and proportion of edge blur
	int sum_inv_blur = cv::countNonZero(inv_blur);
	int sum_blur = cv::countNonZero(blur);
	int sum_edge = cv::countNonZero(edge);
	blur_mean = static_cast<float>(sum_inv_blur) / sum_blur;
	blur_ratio = static_cast<float>(sum_blur) / sum_edge;
}

// from https://programmersought.com/article/6657657740/
void SharpnessEvaluation::compute_noise_IQA(cv::Mat& gray_img, float& noise_mean, float& noise_ratio)
{
	//The effect of mean filtering to remove noise on edge detection
	cv::Mat blur_img;
	cv::blur(gray_img, blur_img, cv::Size(3, 3));

	// Perform vertical edge detection
	cv::Mat grad_h, grad_v;
	cv::Mat kernel_h = cv::Mat::zeros(cv::Size(3, 3), CV_32FC1);
	kernel_h.at<float>(0, 1) = -1;
	kernel_h.at<float>(2, 1) = 1;
	cv::filter2D(gray_img, grad_h, CV_32FC1, kernel_h);
	cv::Mat kernel_v = cv::Mat::zeros(cv::Size(3, 3), CV_32FC1);
	kernel_v.at<float>(1, 0) = -1;
	kernel_v.at<float>(1, 2) = 1;
	cv::filter2D(gray_img, grad_v, CV_32FC1, kernel_v);

	// Screen candidate points
	//The mean of the horizontal/vertical gradient
	float D_h_mean = .0f, D_v_mean = .0f;
	D_h_mean = static_cast<float>(cv::mean(grad_h)[0]);
	D_v_mean = static_cast<float>(cv::mean(grad_v)[0]);

	// Get candidate noise points
	cv::Mat N_cand = cv::Mat::zeros(gray_img.rows, gray_img.cols, CV_32FC1);
	for (int i = 0; i < gray_img.rows; ++i) {
		float* data_h = grad_h.ptr<float>(i);
		float* data_v = grad_v.ptr<float>(i);
		float* data = N_cand.ptr<float>(i);
		for (int j = 0; j < gray_img.cols; ++j) {
			if (data_v[j] < D_v_mean && data_h[j] < D_h_mean) {
				data[j] = data_v[j] > data_h[j] ? data_v[j] : data_h[j];
			}
		}
	}

	//The final noise point
	float N_cand_mean = static_cast<float>(cv::mean(N_cand)[0]);
	cv::Mat mask = (N_cand > N_cand_mean) / 255;
	mask.convertTo(mask, CV_32FC1);
	cv::Mat N;
	cv::multiply(N_cand, mask, N);

	// Calculate the mean and ratio of noise
	float sum_noise = static_cast<float>(cv::sum(N)[0]);
	int sum_noise_cnt = cv::countNonZero(N);
	noise_mean = sum_noise / (sum_noise_cnt + 0.0001);
	noise_ratio = static_cast<float>(sum_noise_cnt) / N.total();

}


real SharpnessEvaluation::sharpnessEval_blur_noise_IQA_colorUN(cv::Mat& color_ima)
{
	// split color image
	std::vector<cv::Mat> grayIma_vec = Images::splitImageBGR(color_ima);

	// blue
	cv::Mat ima_blue = grayIma_vec[0];
	// green
	cv::Mat ima_green = grayIma_vec[1];
	// red
	cv::Mat ima_red = grayIma_vec[2];

	real sharpness_blue = sharpnessEval_blur_noise_IQA_gray8UN(ima_blue);
	real sharpness_green = sharpnessEval_blur_noise_IQA_gray8UN(ima_green);
	real sharpness_red = sharpnessEval_blur_noise_IQA_gray8UN(ima_red);

	real totalSharpness = (sharpness_blue + sharpness_green + sharpness_red) / 3.0;

	return totalSharpness;
}



real SharpnessEvaluation::calculateSharpness_superFct(sharpnessEvalMethode sharpEvalMeth, cv::Mat ima)
{
	real sharpness{};

	// Brenner color
	if (sharpEvalMeth == sharpnessEvalMethode::Brenner)
	{
		if (ima.channels() == 3)
		{
			sharpness = sharpnessEval_brenner_colorUN(ima);
		}
		else
		{
			sharpness = sharpnessEval_brenner_gray8UN(ima);
		}
	}

	// Tenengrad color
	else if (sharpEvalMeth == sharpnessEvalMethode::Tenengrad)
	{
		if (ima.channels() == 3)
		{
			sharpness = sharpnessEval_tenegrad_colorUN(ima);
		}
		else
		{
			sharpness = sharpnessEval_tenengrad_gray8UN(ima);
		}

	}

	// Laplacian color
	else if (sharpEvalMeth == sharpnessEvalMethode::Laplacian)
	{
		if (ima.channels() == 3)
		{
			sharpness = sharpnessEval_laplacian_colorUN(ima);
		}
		else
		{
			sharpness = sharpnessEval_laplacian_gray8UN(ima);
		}
	}

	// SMD
	else if (sharpEvalMeth == sharpnessEvalMethode::SMD)
	{
		if (ima.channels() == 3)
		{
			sharpness = sharpnessEval_SMD_colorUN(ima);
		}
		else
		{
			sharpness = sharpnessEval_SMD_gray8UN(ima);
		}

	}

	// SMD 2
	else if (sharpEvalMeth == sharpnessEvalMethode::SMD2)
	{
		if (ima.channels() == 3)
		{
			sharpness = sharpnessEval_SMD2_colorUN(ima);
		}
		else
		{
			sharpness = sharpnessEval_SMD2_gray8UN(ima);
		}

	}

	// Energy Grad Fct
	else if (sharpEvalMeth == sharpnessEvalMethode::EnergyGradFct)
	{
		if (ima.channels() == 3)
		{
			sharpness = sharpnessEval_EnergyGradFct_colorUN(ima);
		}
		else
		{
			sharpness = sharpnessEval_EnergyGradFct_gray8UN(ima);
		}
	}

	// EVA
	else if (sharpEvalMeth == sharpnessEvalMethode::EVA)
	{
		if (ima.channels() == 3)
		{
			sharpness = sharpnessEval_EVA_colorUN(ima);
		}
		else
		{
			sharpness = sharpnessEval_EVA_gray8UN(ima);
		}
	}

	// NRSS
	else if (sharpEvalMeth == sharpnessEvalMethode::NRSS)
	{
		if (ima.channels() == 3)
		{
			sharpness = sharpnessEval_NRSS_colorUN(ima);
		}
		else
		{
			sharpness = sharpnessEval_NRSS_gray8UN(ima);
		}

	}

	// BlurAndNoise
	else if (sharpEvalMeth == sharpnessEvalMethode::BlurAndNoise)
	{
		if (ima.channels() == 3)
		{
			sharpness = sharpnessEval_blur_noise_IQA_colorUN(ima);
		}
		else
		{
			sharpness = sharpnessEval_blur_noise_IQA_gray8UN(ima);
		}

	}

	else
	{
		oftenUse::errorProtocol_stopSystem("Attention! No valid sharpness evaluation methode selectet.", "SharpnessEvaluation.cpp", 0, true);
	}

	return sharpness;
}