#pragma once

// lens replace and optimize
#include "..\..\..\LensReplaceAndOptimize\LensReplaceAndOptimize.h"

struct saveLRaO_statistic
{
public:
	saveLRaO_statistic(unsigned int numberLensesInOptSys);
	saveLRaO_statistic();
	~saveLRaO_statistic();

	void setMeritVal_DLS(real meritValDLS);
	real getMeritVaL_DLS();

	void setMeritVal_DLS_12(real meritValDLS12);
	real getMeritVal_DLS_12();

	void setMeritVal_GeneticAndDLS(real meritValGeneticAndDLS);
	real getMeritVaL_GeneticAndDLS();

	void setMeritVal_GeneticAndDLS_12(real meritValGeneticAndDLS12);
	real getMeritVaL_GeneticAndDLS_12();

	void setDurationTime_DLS(real DurationTimeDLS);
	real getDurationTime_DLS();

	void setDurationTime_DLS_12(real DurationTimeDLS12);
	real getDurationTime_DLS_12();

	void setDurationTime_GeneticAndDLS(real DurationTimeGeneticAndDLS);
	real getDurationTime_GeneticAndDLS();

	void setDurationTime_GeneticAndDLS_12(real DurationTimeGeneticAndDLS12);
	real getDurationTime_GeneticAndDLS_12();


	// replace sequence
	void setReplaceSequence(optimizeMethode optiMethode, std::vector<unsigned int> repSeq_vec);
	std::vector<unsigned int> getReplacedSequence(optimizeMethode optiMethode);

	void setBestLensNumberWasTaken(optimizeMethode optiMethode, std::vector<unsigned int> bestLensNumberWasTaken);
	std::vector<unsigned int> getBestLensNumberWasTaken(optimizeMethode optiMethode);
	void resizeBestLensNumberWasTaken(unsigned int numberLenses);

	unsigned int getNumberOfLensesInOptSys();
	void setNumberOfLensesInOptSys(unsigned int numberOfLenses);

	void setExample(std::string example);
	std::string getExample();

private:

	// example
	std::string mExample{};

	// merit values
	real mMeritVal_DLS{};
	real mMeritVal_DLS_12{};
	real mMeritVal_GeneticAndDLS{};
	real mMeritVal_GeneticAndDLS_12{};

	// duration times
	real mDurationTime_DLS{};
	real mDurationTime_DLS_12{};
	real mDurationTime_GeneticAndDLS{};
	real mDurationTime_GeneticAndDLS_12{};

	// replace sequences
	std::vector<unsigned int> mReplaceSequence_DLS;
	std::vector<unsigned int> mReplaceSequence_DLS_12;
	std::vector<unsigned int> mReplaceSequence_GeneticAndDLS;
	std::vector<unsigned int> mReplaceSequence_GeneticAndDLS_12;

	// number of best lens was taken
	std::vector<unsigned int> mNumBestLensWasTaken_DLS{};
	std::vector<unsigned int> mNumBestLensWasTaken_DLS_12{};
	std::vector<unsigned int> mNumBestLensWasTaken_GeneticAndDLS{};
	std::vector<unsigned int> mNumBestLensWasTaken_GeneticAndDLS_12{};

	// number of lenses in optical system
	unsigned int mNumberOfLensesInOptSys{};

};

struct saveLRaO_GeneticAndDLS_12_statistic
{
public:
	
	void setMeritVal_GeneticAndDLS_12(real meritValGeneticAndDLS12);
	real getMeritVaL_GeneticAndDLS_12();

	void setDurationTime_GeneticAndDLS_12(real DurationTimeGeneticAndDLS12);
	real getDurationTime_GeneticAndDLS_12();
	
	void setReplaceSequence_GeneticAndDLS(std::vector<unsigned int> repSeq_vec);
	std::vector<unsigned int> getReplacedSequence_GeneticAndDLS12();

	void setBestLensNumberWasTaken(std::vector<unsigned int> bestLensNumberWasTaken);
	std::vector<unsigned int> getBestLensNumberWasTaken();
	void resizeBestLensNumberWasTaken(unsigned int numberLenses);

	unsigned int getNumberOfLensesInOptSys();
	void setNumberOfLensesInOptSys(unsigned int numberOfLenses);

	void setExample(std::string example);
	std::string getExample();


private:
	// example
	std::string mExample{};
	// merit values
	real mMeritVal_GeneticAndDLS_12{};
	// duration times
	real mDurationTime_GeneticAndDLS_12{};
	// replace sequences
	std::vector<unsigned int> mReplaceSequence_GeneticAndDLS_12;
	// number of best lens was taken
	std::vector<unsigned int> mNumBestLensWasTaken_GeneticAndDLS_12{};
	// number of lenses in optical system
	unsigned int mNumberOfLensesInOptSys{};

};