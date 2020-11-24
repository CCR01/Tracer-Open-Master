#pragma once

#include "opencv2/core/mat.hpp"

class PSF
{
public:
	PSF();
	~PSF();

	cv::Mat calcPSF_FFT_P_Fct(cv::Mat& OPD);
	cv::Mat MagnitudeOfTwochannelsMat(cv::Mat& matrix);
	cv::Mat ifftshiftOneChan(cv::Mat& input);

private:

};

