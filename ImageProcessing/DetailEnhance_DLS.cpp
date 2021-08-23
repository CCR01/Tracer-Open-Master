#include "DetailEnhance_DLS.h"

//images
#include "..\Image\Images.h"

// math
#include "..\LowLevelTracing\Math_LLT.h"

loadParameterDetailEnhance_DLS::loadParameterDetailEnhance_DLS() {};
loadParameterDetailEnhance_DLS::~loadParameterDetailEnhance_DLS() {};

// damping factor
float loadParameterDetailEnhance_DLS::getDampingFactor()
{
	return mDampingFactor;
}
void loadParameterDetailEnhance_DLS::setDampingFactor(real dampingFactor)
{
	mDampingFactor = dampingFactor;
}
// start S
float loadParameterDetailEnhance_DLS::getStartS()
{
	return mStartS;
}
void loadParameterDetailEnhance_DLS::setStartS(float startS)
{
	mStartS = startS;
}
// start R
float loadParameterDetailEnhance_DLS::getStartR()
{
	return mStartR;
}
void loadParameterDetailEnhance_DLS::setStartR(float startR)
{
	mStartR = startR;
}
// min S
float loadParameterDetailEnhance_DLS::getMinS()
{
	return mMinS;
}
void loadParameterDetailEnhance_DLS::setMinS(float minS)
{
	mMinS = minS;
}
// max S
float loadParameterDetailEnhance_DLS::getMaxS()
{
	return mMaxS;
}
void loadParameterDetailEnhance_DLS::setMaxS(float maxS)
{
	mMaxS = maxS;
}
// min R
float loadParameterDetailEnhance_DLS::getMinR()
{
	return mMinR;
}
void loadParameterDetailEnhance_DLS::setMinR(float minR)
{
	mMinR = minR;
}
// max R
float loadParameterDetailEnhance_DLS::getMaxR()
{
	return mMaxR;
}
void loadParameterDetailEnhance_DLS::setMaxR(float maxR)
{
	mMaxR = maxR;
}
// deviation value R
float loadParameterDetailEnhance_DLS::getDeviationValR()
{
	return mDeviationValue_R;
}
void loadParameterDetailEnhance_DLS::setDeviationValR(float devValR)
{
	mDeviationValue_R = devValR;
}
// deviation value R
float loadParameterDetailEnhance_DLS::getDeviationValS()
{
	return mDeviationValue_S;
}
void loadParameterDetailEnhance_DLS::setDeviationValS(float devValS)
{
	mDeviationValue_S = devValS;
}
// start factor getting better
float loadParameterDetailEnhance_DLS::getStartFactorBetter()
{
	return mStartFactorBetter;
}
void loadParameterDetailEnhance_DLS::setStartFactorBetter(float startFactorBetter)
{
	mStartFactorBetter = startFactorBetter;
}
// start factor getting worse
float loadParameterDetailEnhance_DLS::getStartFactorWorse()
{
	return mStartFactorWorse;
}
void loadParameterDetailEnhance_DLS::setStartFactorWorse(float startFactorBetter)
{
	mStartFactorWorse = startFactorBetter;
}
// max iterations
unsigned int loadParameterDetailEnhance_DLS::getMaxInterations()
{
	return mMaxIterations;
}
void loadParameterDetailEnhance_DLS::setMaxInterations(unsigned int maxIterations)
{
	mMaxIterations = maxIterations;
}
// max getting worst
unsigned int loadParameterDetailEnhance_DLS::getMaxGettingWorst()
{
	return mMaxGettingWorst;
}
void loadParameterDetailEnhance_DLS::setMaxGettingWorst(unsigned int gettingWorst)
{
	mMaxGettingWorst = gettingWorst;
}
// max boarder violation
unsigned int loadParameterDetailEnhance_DLS::getMaxBoarderViolations()
{
	return mMaxBoarderViolations;
}
void loadParameterDetailEnhance_DLS::setMaxBoarderViolations(unsigned int maxBoarderViolations)
{
	mMaxBoarderViolations = maxBoarderViolations;
}
// max steps S
float loadParameterDetailEnhance_DLS::getMaxStepsS()
{
	return mMaxStepsS;
}
void loadParameterDetailEnhance_DLS::setMaxStepsS(float maxStepsS)
{
	mMaxStepsS = maxStepsS;
}
// max steps R
float loadParameterDetailEnhance_DLS::getMaxStepsR()
{
	return mMaxStepsR;
}
void loadParameterDetailEnhance_DLS::setMaxStepsR(float maxStepsR)
{
	mMaxStepsR = maxStepsR;
}

DetailEnhance_DLS_ThisIsNOTworking::DetailEnhance_DLS_ThisIsNOTworking() { loadParameterDLS_DLS(); }
DetailEnhance_DLS_ThisIsNOTworking::~DetailEnhance_DLS_ThisIsNOTworking(){}

void DetailEnhance_DLS_ThisIsNOTworking::loadParameterDLS_DLS()
{
	mLoadParaDE_DLS.setDampingFactor(2000.0);
	mLoadParaDE_DLS.setStartR(0.5);
	mLoadParaDE_DLS.setStartS(1.0);
	mLoadParaDE_DLS.setMinR(0.0);
	mLoadParaDE_DLS.setMaxR(1.0);
	mLoadParaDE_DLS.setMinS(0.0);
	mLoadParaDE_DLS.setMaxS(200.0);
	mLoadParaDE_DLS.setDeviationValR(0.01);
	mLoadParaDE_DLS.setDeviationValS(0.01);
	mLoadParaDE_DLS.setStartFactorBetter(0.4);
	mLoadParaDE_DLS.setStartFactorWorse(0.9);
	mLoadParaDE_DLS.setMaxInterations(50);
	mLoadParaDE_DLS.setMaxGettingWorst(25);
	mLoadParaDE_DLS.setMaxBoarderViolations(10);
	mLoadParaDE_DLS.setMaxStepsS(10.0);
	mLoadParaDE_DLS.setMaxStepsR(1.0);

}

void DetailEnhance_DLS_ThisIsNOTworking::detailEnhanceSuperFunc_DLS(cv::Mat /*blured image*/ bluredIma, cv::Mat /*sharp image*/ sharpIma)
{
	mBluredIma = bluredIma;
	mSharpIma = sharpIma;
	mTempS = mLoadParaDE_DLS.getStartS();
	mTempR = mLoadParaDE_DLS.getStartR();
	mDampingNum = 1 / (1 + std::pow(mLoadParaDE_DLS.getDampingFactor(), 2));

	mTempFactorBetter = mLoadParaDE_DLS.getStartFactorBetter();
	mTempFactorWorse = mLoadParaDE_DLS.getStartFactorWorse();

	mDampNum_A_T_A.resize(2);
	mDampNum_A_T_A[0].resize(2);
	mDampNum_A_T_A[1].resize(2);
	mA_T_F0.resize(2);

	mInterationCounter = 0;
	mWorseCounter = 0;
	mBorderVioloationCounter = 0;
	mImprovement = true;

	cv::detailEnhance(mBluredIma, mDetailEnhIma, mTempS, mTempR);

	calcDifference();
	mSaveDif.push_back(mTempDif);

	//mDetailEnhIma = cv::Mat::zeros(mBluredIma.size(), mBluredIma.type());
	while (checkLoop())
	{
	
		

		calcDeviationS();
		calcDeviationR();
	
		calcDeltaSandR();

		// debug
		// mTempS = mTempS - mTempDeltaS;
		std::cout << "tempS" << mTempS << std::endl;
		mTempR = mTempR - mTempDeltaR;
		// debug
		// std::cout << "tempR" << mTempR << std::endl;
		checkForMaxSteps();
		checkBoarderViolations();

		cv::detailEnhance(mBluredIma, mDetailEnhIma, mTempS, mTempR);

		calcDifference();
		mSaveDif.push_back(mTempDif);

		// debug
		std::cout << "temp Dif: " << mTempDif << std::endl;

		checkForImprovement();

		if (mImprovement)
		{
			mDampingNum = mDampingNum * mTempFactorBetter;
			++mInterationCounter;
		}

		else // no improvement
		{
			mTempS = mTempS + mTempDeltaS;
			mTempR = mTempR + mTempDeltaR;
			mDampingNum = mDampingNum * mTempFactorWorse;
			++mInterationCounter;
			++mWorseCounter;
		}
	}
	



}

void DetailEnhance_DLS_ThisIsNOTworking::checkForMaxSteps()
{
	if (mTempDeltaS > mLoadParaDE_DLS.getMaxStepsS())
	{
		mTempDeltaS = mLoadParaDE_DLS.getMaxStepsS();
	}
	else if (std::abs(mTempDeltaS) > mLoadParaDE_DLS.getMaxStepsS())
	{
		mTempDeltaS = -mLoadParaDE_DLS.getMaxStepsS();
	}

	if (mTempDeltaR > mLoadParaDE_DLS.getMaxStepsR())
	{
		mTempDeltaR = mLoadParaDE_DLS.getMaxStepsR();
	}
	else if (std::abs(mTempDeltaR) > mLoadParaDE_DLS.getMaxStepsR())
	{
		mTempDeltaR = -mLoadParaDE_DLS.getMaxStepsR();
	}
}

bool DetailEnhance_DLS_ThisIsNOTworking::checkLoop()
{
	bool checker = true;

	if (mLoadParaDE_DLS.getMaxInterations() < mInterationCounter)
	{
		checker = false;
	}
	else if (mLoadParaDE_DLS.getMaxGettingWorst() < mWorseCounter)
	{
		checker = false;
	}
	if (mLoadParaDE_DLS.getMaxBoarderViolations() < mBorderVioloationCounter)
	{
		checker = false;
	}



	return checker;

}

void DetailEnhance_DLS_ThisIsNOTworking::calcDifference()
{
	cv::absdiff(mSharpIma, mDetailEnhIma, mTempDifMat);
	mTempDif = Images::calcSumMatrix(mTempDifMat);

	mTempDif = mTempDif / 100;
}

void DetailEnhance_DLS_ThisIsNOTworking::calcDeviationR()
{
	cv::detailEnhance(mBluredIma, mDetailEnhIma, mTempS, mTempR);
	calcDifference();
	int diffPos0 = mTempDif;

	mTempR = mTempR + mLoadParaDE_DLS.getDeviationValR();

	cv::detailEnhance(mBluredIma, mDetailEnhIma, mTempS, mTempR);
	calcDifference();
	int diffPos1 = mTempDif;

	mDeviationR = (diffPos1 - diffPos0) / mLoadParaDE_DLS.getDeviationValR();

	if (mDeviationR == 0)
	{
		mDeviationR = 0.001;
	}

	mTempR = mTempR - mLoadParaDE_DLS.getDeviationValR();

}

void DetailEnhance_DLS_ThisIsNOTworking::calcDeviationS()
{
	cv::detailEnhance(mBluredIma, mDetailEnhIma, mTempS, mTempR);
	calcDifference();
	int diffPos0 = mTempDif;

	mTempS = mTempS + mLoadParaDE_DLS.getDeviationValS();
	
	cv::detailEnhance(mBluredIma, mDetailEnhIma, mTempS, mTempR);
	calcDifference();

	int diffPos1 = mTempDif;

	mDeviationS = (diffPos1 - diffPos0) / mLoadParaDE_DLS.getDeviationValS();

	if (mDeviationS == 0)
	{
		mDeviationS = 0.001;
	}

	mTempS = mTempS - mLoadParaDE_DLS.getDeviationValS();
}

void DetailEnhance_DLS_ThisIsNOTworking::calcDampNum_A_T_A()
{
	mDampNum_A_T_A[0][0] = mDampingNum * std::pow(mDeviationS, 2);
	mDampNum_A_T_A[0][1] = mDampingNum * mDeviationS * mDeviationR;
	mDampNum_A_T_A[1][0] = mDampNum_A_T_A[0][1];
	mDampNum_A_T_A[1][1] = mDampingNum * std::pow(mDeviationR, 2);
}

void DetailEnhance_DLS_ThisIsNOTworking::calcA_T_F0()
{
	mA_T_F0[0] = mDeviationS * mTempDif;
	mA_T_F0[1] = mDeviationR * mTempDif;
}

void DetailEnhance_DLS_ThisIsNOTworking::calcDeltaSandR()
{
	mTempDeltaS = - mDampingNum * mDeviationS * mTempDif;
	mTempDeltaR = - mDampingNum *mDeviationR * mTempDif;
}

void DetailEnhance_DLS_ThisIsNOTworking::checkForImprovement()
{
	unsigned int sizeSaveDif = mSaveDif.size();
	unsigned int posLastSafe = sizeSaveDif - 1;
	unsigned int posBeforeLastSave = sizeSaveDif - 2;

	float diffLast = mSaveDif[posLastSafe];
	float diffBeforeLast = mSaveDif[posBeforeLastSave];

	if (diffLast < diffBeforeLast)
	{
		mImprovement = true;
	}
	else
	{
		mImprovement = false;
	}
}

void DetailEnhance_DLS_ThisIsNOTworking::checkBoarderViolations()
{
	if (mLoadParaDE_DLS.getMinS() > mTempS)
	{
		mTempDeltaS = mTempDeltaS + mTempS + std::abs(mLoadParaDE_DLS.getMinS());
		mTempS = mLoadParaDE_DLS.getMinS();
		++mBorderVioloationCounter;
		
	}

	else if (mLoadParaDE_DLS.getMaxS() < mTempS)
	{
		mTempDeltaS = mTempDeltaS - mTempS + std::abs(mLoadParaDE_DLS.getMaxS()) ;
		mTempS = mLoadParaDE_DLS.getMaxS();
		++mBorderVioloationCounter;
	
	}

	if (mLoadParaDE_DLS.getMinR() > mTempR)
	{
		mTempDeltaR = mTempDeltaR + mTempR + std::abs(mLoadParaDE_DLS.getMinR());
		mTempR = mLoadParaDE_DLS.getMinR();
		++mBorderVioloationCounter;
	}

	else if (mLoadParaDE_DLS.getMaxR() < mTempR)
	{
		mTempDeltaR = mTempDeltaR - mTempR + std::abs(mLoadParaDE_DLS.getMaxR()) ;
		mTempR = mLoadParaDE_DLS.getMaxR();
		++mBorderVioloationCounter;
	
	}
}

cv::Mat DetailEnhance_DLS_ThisIsNOTworking::getDetailEnhanceIma()
{
	return mDetailEnhIma;
}