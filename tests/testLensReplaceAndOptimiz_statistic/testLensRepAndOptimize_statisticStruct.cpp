#include "testLensRepAndOptimize_statisticStruct.h"

saveLRaO_statistic::saveLRaO_statistic(unsigned int numberLensesInOptSys) :
	mNumberOfLensesInOptSys(numberLensesInOptSys)
{
	mNumBestLensWasTaken_DLS.resize(mNumberOfLensesInOptSys);
	mNumBestLensWasTaken_DLS_12.resize(mNumberOfLensesInOptSys);
	mNumBestLensWasTaken_GeneticAndDLS.resize(mNumberOfLensesInOptSys);
	mNumBestLensWasTaken_GeneticAndDLS_12.resize(mNumberOfLensesInOptSys);
};

saveLRaO_statistic::saveLRaO_statistic() {};

saveLRaO_statistic::~saveLRaO_statistic() {};

void saveLRaO_statistic::setMeritVal_DLS(real meritValDLS)
{
	mMeritVal_DLS = meritValDLS;
}
real saveLRaO_statistic::getMeritVaL_DLS()
{
	return mMeritVal_DLS;
}

void saveLRaO_statistic::setMeritVal_DLS_12(real meritValDLS12)
{
	mMeritVal_DLS_12 = meritValDLS12;
}
real saveLRaO_statistic::getMeritVal_DLS_12()
{
	return mMeritVal_DLS_12;
}
void saveLRaO_statistic::setMeritVal_GeneticAndDLS(real meritValGeneticAndDLS)
{
	mMeritVal_GeneticAndDLS = meritValGeneticAndDLS;
}
real saveLRaO_statistic::getMeritVaL_GeneticAndDLS()
{
	return mMeritVal_GeneticAndDLS;
}
void saveLRaO_statistic::setMeritVal_GeneticAndDLS_12(real meritValGeneticAndDLS12)
{
	mMeritVal_GeneticAndDLS_12 = meritValGeneticAndDLS12;
}
real saveLRaO_statistic::getMeritVaL_GeneticAndDLS_12()
{
	return mMeritVal_GeneticAndDLS_12;
}

void saveLRaO_statistic::setDurationTime_DLS(real DurationTimeDLS)
{
	mDurationTime_DLS = DurationTimeDLS;
}
real saveLRaO_statistic::getDurationTime_DLS()
{
	return mDurationTime_DLS;
}

void saveLRaO_statistic::setDurationTime_DLS_12(real DurationTimeDLS12)
{
	mDurationTime_DLS_12 = DurationTimeDLS12;
}
real saveLRaO_statistic::getDurationTime_DLS_12()
{
	return mDurationTime_DLS_12;
}
void saveLRaO_statistic::setDurationTime_GeneticAndDLS(real DurationTimeGeneticAndDLS)
{
	mDurationTime_GeneticAndDLS = DurationTimeGeneticAndDLS;
}
real saveLRaO_statistic::getDurationTime_GeneticAndDLS()
{
	return mDurationTime_GeneticAndDLS;
}
void saveLRaO_statistic::setDurationTime_GeneticAndDLS_12(real DurationTimeGeneticAndDLS12)
{
	mDurationTime_GeneticAndDLS_12 = DurationTimeGeneticAndDLS12;
}
real saveLRaO_statistic::getDurationTime_GeneticAndDLS_12()
{
	return mDurationTime_GeneticAndDLS_12;
}

// set replace sequence
void saveLRaO_statistic::setReplaceSequence(optimizeMethode optiMethod, std::vector<unsigned int> repSeq_vec)
{
	if (optiMethod == optimizeMethode::DLS)
	{
		mReplaceSequence_DLS = repSeq_vec;
	}

	else if (optiMethod == optimizeMethode::DLS_12)
	{
		mReplaceSequence_DLS_12 = repSeq_vec;
	}

	else if (optiMethod == optimizeMethode::GeneticAndDLS)
	{
		mReplaceSequence_GeneticAndDLS = repSeq_vec;
	}

	else if (optiMethod == optimizeMethode::GeneticAndDLS_12)
	{
		mReplaceSequence_GeneticAndDLS_12 = repSeq_vec;
	}


}

std::vector<unsigned int> saveLRaO_statistic::getReplacedSequence(optimizeMethode optiMethode)
{
	if (optiMethode == optimizeMethode::DLS)
	{
		return mReplaceSequence_DLS;
	}

	else if (optiMethode == optimizeMethode::DLS_12)
	{
		return mReplaceSequence_DLS_12;
	}

	else if (optiMethode == optimizeMethode::GeneticAndDLS)
	{
		return mReplaceSequence_GeneticAndDLS;
	}

	else if (optiMethode == optimizeMethode::GeneticAndDLS_12)
	{
		return mReplaceSequence_GeneticAndDLS_12;
	}

}

void saveLRaO_statistic::setBestLensNumberWasTaken(optimizeMethode optiMethode, std::vector<unsigned int> bestLensNumberWasTaken)
{
	if (optiMethode == optimizeMethode::DLS)
	{
		mNumBestLensWasTaken_DLS = bestLensNumberWasTaken;
	}

	else if (optiMethode == optimizeMethode::DLS_12)
	{
		mNumBestLensWasTaken_DLS_12 = bestLensNumberWasTaken;
	}

	else if (optiMethode == optimizeMethode::GeneticAndDLS)
	{
		mNumBestLensWasTaken_GeneticAndDLS = bestLensNumberWasTaken;
	}

	else if (optiMethode == optimizeMethode::GeneticAndDLS_12)
	{
		mNumBestLensWasTaken_GeneticAndDLS_12 = bestLensNumberWasTaken;
	}
}

std::vector<unsigned int> saveLRaO_statistic::getBestLensNumberWasTaken(optimizeMethode optiMethode)
{
	if (optiMethode == optimizeMethode::DLS)
	{
		return mNumBestLensWasTaken_DLS;
	}

	else if (optiMethode == optimizeMethode::DLS_12)
	{
		return mNumBestLensWasTaken_DLS_12;
	}

	else if (optiMethode == optimizeMethode::GeneticAndDLS)
	{
		return mNumBestLensWasTaken_GeneticAndDLS;
	}

	else if (optiMethode == optimizeMethode::GeneticAndDLS_12)
	{
		return mNumBestLensWasTaken_GeneticAndDLS_12;
	}
}

void saveLRaO_statistic::resizeBestLensNumberWasTaken(unsigned int numberLenses)
{
	mNumBestLensWasTaken_DLS.resize(numberLenses);
	mNumBestLensWasTaken_DLS_12.resize(numberLenses);
	mNumBestLensWasTaken_GeneticAndDLS.resize(numberLenses);
	mNumBestLensWasTaken_GeneticAndDLS_12.resize(numberLenses);
}


unsigned int saveLRaO_statistic::getNumberOfLensesInOptSys()
{
	return mNumberOfLensesInOptSys;
}
void saveLRaO_statistic::setNumberOfLensesInOptSys(unsigned int numberOfLenses)
{
	mNumberOfLensesInOptSys = numberOfLenses;
}

void saveLRaO_statistic::setExample(std::string example)
{
	mExample = example;
}
std::string saveLRaO_statistic::getExample()
{
	return mExample;
}


void saveLRaO_GeneticAndDLS_12_statistic::setMeritVal_GeneticAndDLS_12(real meritValGeneticAndDLS12)
{
	mMeritVal_GeneticAndDLS_12 = meritValGeneticAndDLS12;
}
real  saveLRaO_GeneticAndDLS_12_statistic::getMeritVaL_GeneticAndDLS_12()
{
	return mMeritVal_GeneticAndDLS_12;
}

void  saveLRaO_GeneticAndDLS_12_statistic::setDurationTime_GeneticAndDLS_12(real DurationTimeGeneticAndDLS12)
{
	mDurationTime_GeneticAndDLS_12 = DurationTimeGeneticAndDLS12;
}
real  saveLRaO_GeneticAndDLS_12_statistic::getDurationTime_GeneticAndDLS_12()
{
	return mDurationTime_GeneticAndDLS_12;
}

void  saveLRaO_GeneticAndDLS_12_statistic::setReplaceSequence_GeneticAndDLS(std::vector<unsigned int> repSeq_vec)
{
	mReplaceSequence_GeneticAndDLS_12 = repSeq_vec;
}
std::vector<unsigned int>  saveLRaO_GeneticAndDLS_12_statistic::getReplacedSequence_GeneticAndDLS12()
{
	return mReplaceSequence_GeneticAndDLS_12;
}

void  saveLRaO_GeneticAndDLS_12_statistic::setBestLensNumberWasTaken(std::vector<unsigned int> bestLensNumberWasTaken)
{
	mNumBestLensWasTaken_GeneticAndDLS_12 = bestLensNumberWasTaken;
}
std::vector<unsigned int> saveLRaO_GeneticAndDLS_12_statistic::getBestLensNumberWasTaken()
{
	return mNumBestLensWasTaken_GeneticAndDLS_12;
}
void  saveLRaO_GeneticAndDLS_12_statistic::resizeBestLensNumberWasTaken(unsigned int numberLenses)
{
	mNumBestLensWasTaken_GeneticAndDLS_12.resize(numberLenses);
}

unsigned int  saveLRaO_GeneticAndDLS_12_statistic::getNumberOfLensesInOptSys()
{
	return mNumberOfLensesInOptSys;
}
void  saveLRaO_GeneticAndDLS_12_statistic::setNumberOfLensesInOptSys(unsigned int numberOfLenses)
{
	mNumberOfLensesInOptSys = numberOfLenses;
}

void  saveLRaO_GeneticAndDLS_12_statistic::setExample(std::string example)
{
	mExample = example;
}
std::string  saveLRaO_GeneticAndDLS_12_statistic::getExample()
{
	return mExample;
}