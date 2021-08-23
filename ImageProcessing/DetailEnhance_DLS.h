#pragma once

// open cv
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/calib3d/calib3d.hpp>
//#include <opencv2/imgcodecs.hpp>
#include <opencv2/photo.hpp>

// important structs
#include "..\LowLevelTracing\ImportantStructures.h"

struct loadParameterDetailEnhance_DLS
{
public:
	loadParameterDetailEnhance_DLS();
	~loadParameterDetailEnhance_DLS();

	// damping factor
	float getDampingFactor();
	void setDampingFactor(real dampingFactor);
	// start S
	float getStartS();
	void setStartS(float startS);
	// start R
	float getStartR();
	void setStartR(float startR);
	// min S
	float getMinS();
	void setMinS(float minS);
	// max S
	float getMaxS();
	void setMaxS(float maxS);
	// min R
	float getMinR();
	void setMinR(float minR);
	// max R
	float getMaxR();
	void setMaxR(float maxR);
	// deviation value R
	float getDeviationValR();
	void setDeviationValR(float devValR);
	// deviation value S
	float getDeviationValS();
	void setDeviationValS(float devValS);
	// start factor getting better
	float getStartFactorBetter();
	void setStartFactorBetter(float startFactorBetter);
	// start factor getting worse
	float getStartFactorWorse();
	void setStartFactorWorse(float startFactorBetter);
	// max iterations
	unsigned int getMaxInterations();
	void setMaxInterations(unsigned int maxIterations);
	// max getting worst
	unsigned int getMaxGettingWorst();
	void setMaxGettingWorst(unsigned int gettingWorst);
	// max boarder violation
	unsigned int getMaxBoarderViolations();
	void setMaxBoarderViolations(unsigned int maxBoarderViolations);
	// max steps S
	float getMaxStepsS();
	void setMaxStepsS(float maxStepsS);
	// max steps R
	float getMaxStepsR();
	void setMaxStepsR(float maxStepsR);

private:
	float mDampingFactor{};
	float mStartS;
	float mStartR;
	float mMinS;
	float mMaxS;
	float mMinR;
	float mMaxR;
	float mDeviationValue_R;
	float mDeviationValue_S;
	float mStartFactorBetter;
	float mStartFactorWorse;
	unsigned int mMaxIterations;
	unsigned int mMaxGettingWorst;
	unsigned int mMaxBoarderViolations;
	float mMaxStepsS;
	float mMaxStepsR;
};

class  DetailEnhance_DLS_ThisIsNOTworking
{
public:
	DetailEnhance_DLS_ThisIsNOTworking();
	~DetailEnhance_DLS_ThisIsNOTworking();

	void loadParameterDLS_DLS();
	void detailEnhanceSuperFunc_DLS(cv::Mat /*blured image*/ bluredIma, cv::Mat /*sharp image*/ sharpIma);
	void calcDifference();
	void calcDeviationR();
	void calcDeviationS();
	void calcDampNum_A_T_A();
	void calcA_T_F0();
	void calcDeltaSandR();
	void checkForImprovement();
	bool checkLoop();
	void checkBoarderViolations();
	void checkForMaxSteps();

	cv::Mat getDetailEnhanceIma();

private:
	loadParameterDetailEnhance_DLS mLoadParaDE_DLS;

	cv::Mat mBluredIma;
	cv::Mat mSharpIma;
	cv::Mat mDetailEnhIma;

	std::vector<std::vector<float>> mDampNum_A_T_A{};

	std::vector<std::vector<float>> mInverseDampNum_A_T_A;
	std::vector<float> mA_T_F0;
	float mTempR;
	float mTempS;
	float mTempDeltaR;
	float mTempDeltaS;

	float mDeviationR;
	float mDeviationS;
	
	cv::Mat mTempDifMat;
	int mTempDif;

	float mDampingNum;

	std::vector<std::vector<float>> mInverse_A_T_F0;

	std::vector<int> mSaveDif{};
	bool mImprovement{};
	float mTempFactorBetter{};
	float mTempFactorWorse{};
	int mInterationCounter{};
	int mWorseCounter{};
	int mBorderVioloationCounter{};
};

