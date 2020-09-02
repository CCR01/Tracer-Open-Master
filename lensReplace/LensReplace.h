#pragma once

#include "..\LowLevelTracing\OpticalSystem_LLT.h"

#include "..\LensCatalog\EdmundOptics\EdmundOpticsLensCatalog.h"

enum class lensTypes { DConvexL, posAchromat, PConvexL, DConcavL, PConcavL };


struct prefLensTypeAndFactro
{
public:
	// prefere lens Type
	lensTypes getPrefLensType();
	void setPrefensType(lensTypes lenstype);
	// factor
	real getFactor();
	void setFactor(real factor);

private:
	lensTypes mLensType;
	real mFactor;

};

struct OptSysEle_Merit_LensType
{
public:

	// optical system
	OpticalSystemElement getOptSysEle();
	void setOpticalSystemEle(OpticalSystemElement optSysEle);
	// merit value
	real getMerit();
	void setMerit(real merit);
	// lens type
	lensTypes getLensType();
	void setLensType(lensTypes lensType);
	// name of the lens
	std::string getLensCatalog();
	void setLensCatalog(std::string nameLens);
	// catalog number
	unsigned int getCatalogNumber();
	void setCatalogNumber(unsigned int catalogNumber);

private:
	OpticalSystemElement mOptSysEle{};
	real mMerit{};
	lensTypes mLensType{};
	std::string mNameLens{};
	unsigned int mCatalogNumber{};
};

struct ValueMinMax
{
public:

	// value
	real getValue();
	void setValue(real value);
	// min
	real getMin();
	void setMin(real min);
	// max
	real getMax();
	void setMax(real max);

private:
	real mValue;
	real mMin;
	real mMax;

};


struct parameterLens
{
public:
	// focal lenght
	ValueMinMax getFocalLengthMinMax();
	void setFocalLengthMinMax(real focalLength, real min, real max);
	// thickness
	ValueMinMax getThicknessMinMax();
	void setThicknessMinMax(real thickness, real min, real max);
	// semi height
	ValueMinMax getSemiHeightMinMax();
	void setSemiHeigthMinMax(real semiHeight, real min, real max);
	// calculate the min value
	real calcMinValue(real value, real percent);
	// calculate the max value
	real calcMaxValue(real value, real percent);

private:
	ValueMinMax mFocalLenthMinMax;
	ValueMinMax mThicknessMinMax;
	ValueMinMax mSemiHeightMinMax;

};


struct defaultPara_LensReplace_struct
{
public:

	// load default parameter
	void loadDefaultPara(unsigned int NoLenses);

	// catalogs to load
	std::vector<lensTypes> getCatalogToLoad() const;
	void getCatalogToLoad(const std::vector<lensTypes>& catalogToLoad);

	// min default
	real getMinDefaut_percent();
	void setMinDefault_percent(real minDefault);

	// max default
	real getMaxDefaut_percent();
	void setMaxDefault_percent(real maxDefault);

	// min percent surface
	void setMinPercent_surface_i(unsigned int surfaceNo, real percentMin);
	real getMinPercent_surface_i(unsigned int surfaceNo);

	// max percent surface
	void setMaxPercent_surface_i(unsigned int surfaceNo, real percentMax);
	real getMaxPercent_surface_i(unsigned int surfaceNo);

	// focal lenght weight
	void setFocalLenght_weight(real weight);
	real getFocalLenght_weight();
	// thickness weight
	void setTickness_weight(real weight);
	real getThickness_weight();
	// semi height weight
	void setSemiHeight_weight(real weight);
	real getSemiHeight_weight();

	// weight focal length surface
	void setWeightFocalLengthSurface_i(unsigned int surfaceNo, real weight);
	real getWeightFocalLengthSurface_i(unsigned int surfaceNo);
	// weight thickenss surface
	void setWeightThicknessSurface_i(unsigned int surfaceNo, real weight);
	real getWeightThicknessSurface_i(unsigned int surfaceNo);
	// weight semiHeight surface
	void setWeightSemiHeightSurface_i(unsigned int surfaceNo, real weight);
	real getWeightSemiHeightSurface_i(unsigned int surfaceNo);

	// pref lens type vec
	void setPrefLensTypeSurfaceAndFactorSurface_i(unsigned int surfaceNo, lensTypes prefType, real factor);
	prefLensTypeAndFactro getPrefLensTyeAndFactorSurface_i(unsigned int surfaceNo);

private:
	std::vector<lensTypes> mCatalotToLoad_default;
	real mMinDefault;
	real mMaxDefault;
	std::vector<real> mMin_default_percent;
	std::vector<real> mMax_default_percent;

	std::vector<real> mWeightFocalLength_default_vec;
	real mWeightFocalLengthDefault;
	std::vector<real> mWeightThickness_default_vec;
	real mWeightThicknessDefault;
	std::vector<real> mWeightSemiHeight_default_vec;
	real mWeightSemiHeightDefault;

	std::vector<prefLensTypeAndFactro> mPrefLensType_vec;
};

class  LensReplace
{
public:
	 LensReplace();
	 //LensReplace(OpticalSystem_LLT opticalSystem_LLT);
	 LensReplace(OpticalSystemElement opticalSystemElement);
	~ LensReplace();
	
	void saveFixedThicknessesLenses();
	void loadLensCata(std::vector<lensTypes> loadLensCatalogEO);
	bool findCatalog(std::vector<lensTypes> loadLensCatalogEO_vec, lensTypes toLoadCatalog);

	// calculate focal lenght
	real calcFocalLenghtOptSys(OpticalSystem_LLT optSys_LLT);
	// calculate thickness
	real calculateThickness_Z(OpticalSystem_LLT optSys_LLT);
	// calculate semi height
	real calcMaxSemiHeigh(OpticalSystem_LLT optSys_LLT);

	// find lenses in optical system
	std::vector<OpticalSystem_LLT> findLensesInOptSys_LLT(OpticalSystem_LLT optSys_LLT);

	std::vector<parameterLens> calcParameterLenses(std::vector<OpticalSystem_LLT> lensesInOptSys);
	std::vector<parameterLens> getParameterLenses();

	void setOptSys_LLT(OpticalSystem_LLT optSys_LLT);

	OptSysEle_Merit_LensType findOptSysEle_lens_inCatalog_TwoSurfaces(parameterLens paraLens, std::vector<LensesTwoSurfaces> AllLensesTwoSurfaces, real weightFocal, real weightThickness, real weightSemiHeight);
	OptSysEle_Merit_LensType findOptSysEle_lens_inCatalog_ThreeSurfaces(parameterLens paraLens, std::vector<LensThreeSurfaces> AllLensesThreeSurfaces, real weightFocal, real weightThickness, real weightSemiHeight);

	OptSysEle_Merit_LensType checkLensCatalogsForBestFitLens(/*lens number*/ unsigned int lensNo, /*parameter lens*/ parameterLens paraLens);
	OptSysEle_Merit_LensType getBestOptSys(std::vector<OptSysEle_Merit_LensType> optSysEle_merit_lensType_vec);

	real calcualteMerit(real target, real is, real weight);
	real calcualteMerit_lens(real focalParam, real minFocalParam, real maxFocalParam, 
	real thicknessParam, real minThicknessParam, real maxThicknessParam, real semiHeightParam, real minSemiHeightParam, 
	real maxSemiHeightParam, real focalTemp, real focalWeight, real thicknessTemp, real thicknessWeight, real semiHeightTemp, real semiHeightWeigh);

	void replaceLens(unsigned int lensNo, OpticalSystemElement fillInOptSysEle);

	void replaceSuperFuction();

	OpticalSystemElement getOpticalSysEle();

private:
	OpticalSystemElement mOpticalSystemEle;
	OpticalSystem_LLT mOpticalSystem_LLT;
	EdmundOpticsLensCatalog mEOLensCatalog;
	std::vector<lensTypes> mLoadLensCatalogEO;

	std::vector<LensesTwoSurfaces> mAll_DoubleConvexLenses; //https://www.edmundoptics.de/f/vis-nir-coated-double-convex-dcx-lenses/13504/
	std::vector<LensThreeSurfaces> mAll_AchromaticLensesMgF; //https://www.edmundoptics.de/f/MgFsub2sub-Coated-Achromatic-Lenses/12006/
	std::vector<LensesTwoSurfaces> mAll_PlanConvexLenses; //https://www.edmundoptics.de/f/vis-nir-coated-plano-convex-pcx-lenses/12278/
	std::vector<LensesTwoSurfaces> mAll_DoubleConcavLenses; //https://www.edmundoptics.de/f/vis-nir-coated-double-concave-dcv-lenses/13540/
	std::vector<LensesTwoSurfaces> mAll_PlanConcavLenses; //https://www.edmundoptics.de/f/vis-nir-coated-plano-concave-pcv-lenses/13512/

	defaultPara_LensReplace_struct mDefaultPara_LensReplace;
	std::vector<OpticalSystem_LLT> mOptSysLLT_lenses_vec;
	std::vector<parameterLens> mParameterLenses;
	unsigned mNoLenses;

	OpticalSystemElement replacedOptSysEle;

	std::vector<real> mThicknessesLenses_vec_Fixed;
};

