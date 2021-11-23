#pragma once

#include "..\LowLevelTracing\OpticalSystem_LLT.h"

// lens catalogs
#include "..\LensCatalog\EdmundOptics\EdmundOpticsLensCatalog.h"
#include "..\LensCatalog\Thorlabs\ThorllabsLensCatalog.h"
#include "..\LensCatalog\Qioptiq\QioptiqLensCatalog.h"

enum class lensTypes { /*Edmund*/ EO_DoubleConvex_VIS_NIR, EO_PosAchromat_MgF_Coated, EO_PlanConvex_VIS_NIR, EO_DoubleConcav_VIS_NIR, EO_PlanConcav_VIS_NIR, 
EO_DoubleConcav_NIR_I, EO_PosAchromat_VIS_NIR,EO_NegAchromat_Broadband_AR_Coated, EO_LargePrecisionAchromat_NoAirSpace, EO_LargePrecisionAchromat_AirSpace, 
EO_HastingsTripletAchromat, EO_SteinheilTripletAchromat,EO_MicroPlanConvex, EO_LargePlanConvexCondensor, 
/*Thorlabs*/ Th_AchromatDoublets_AR_Coated, Th_NBK7_PlanConvex_AR_Coated_400_1100, Th_NBK7_BiConvex_AR_Coated_350_700, Th_NBK7_PlanConcav_AR_Coated_350_700,
Th_NBK7_NSF11_BiConcav_AR_Coated_350_700, Th_NBK7_BestFormSpherical_AR_Coated_350_700, Th_NBK7_PosMeniscus_Uncoated, Th_NBK7_NegMeniscus_Uncoated,
Th_SteinheilTripletAchromat_Visible, Th_HastingsTripletAchromatVisible,
/*Qioptic*/ Qi_PlanConvex_ARB2_VIS, Qi_SymmetricConvex_ARB2_VIS, Qi_PlanConcav_ARB2_VIS, Qi_SymmetricConcav_ARB2_VIS, Qi_PosAchromat_VIS_3_31_ARB2_VIS,
Qi_PosAchromat_VIS_31_40_ARB2_VIS, Qi_NegAchromat_ARB2_VIS
};

//static const char* enum_str_LensCatalog[] ={  /*Edmund*/ "EO_DoubleConvex_VIS_NIR", "EO_PosAchromat_MgF_Coated", "EO_PlanConvex_VIS_NIR", "EO_DoubleConcav_VIS_NIR", "EO_PlanConcav_VIS_NIR",
//"EO_DoubleConcav_NIR_I", "EO_PosAchromat_VIS_NIR", "EO_NegAchromat_Broadband_AR_Coated", "EO_LargePrecisionAchromat_NoAirSpace", "EO_LargePrecisionAchromat_AirSpace",
//"EO_HastingsTripletAchromat", "EO_SteinheilTripletAchromat", "EO_MicroPlanConvex", "EO_LargePlanConvexCondensor",
///*Thorlabs*/ "Th_AchromatDoublets_AR_Coated", "Th_NBK7_PlanConvex_AR_Coated_400_1100", "Th_NBK7_BiConvex_AR_Coated_350_700", "Th_NBK7_PlanConcav_AR_Coated_350_700",
//"Th_NBK7_NSF11_BiConcav_AR_Coated_350_700", "Th_NBK7_BestFormSpherical_AR_Coated_350_700", "Th_NBK7_PosMeniscus_Uncoated", "Th_NBK7_NegMeniscus_Uncoated",
//"Th_SteinheilTripletAchromat_Visible", "Th_HastingsTripletAchromatVisible",
///*Qioptic*/ "Qi_PlanConvex_ARB2_VIS", "Qi_SymmetricConvex_ARB2_VIS", "Qi_PlanConcav_ARB2_VIS", "Qi_SymmetricConcav_ARB2_VIS", "Qi_PosAchromat_VIS_3_31_ARB2_VIS",
//"Qi_PosAchromat_VIS_31_40_ARB2_VIS", "Qi_NegAchromat_ARB2_VIS"
//}; 


enum class replaceSequence { leftToRight, RightToLeft, maxSeidelAberLens, minSeidelAberLens, allPossibleSequences, givenSequence };

struct thicknessAndPosition
{
public:
	thicknessAndPosition();
	~thicknessAndPosition();

	// position
	void setPosition(unsigned int pos);
	unsigned int getPosition();

	// thickness Z
	void setThickness_Z(real thickness__Z);
	real getThickness_Z();

	// fixed
	void setFixed(bool fixed);
	bool getFixed();

private:
	unsigned int mPosition;
	real mThickness_Z;
	bool mFixed;
};

struct prefLensTypeAndFactro
{
public:
	// prefere lens Type
	std::vector<lensTypes> getPrefLensType();
	void setPrefensType(std::vector<lensTypes> lenstype);
	// factor
	real getFactor();
	void setFactor(real factor);

private:
	std::vector<lensTypes> mLensType;
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
	std::string getCatalogNumber();
	void setCatalogNumber(std::string catalogNumber);
	// check parameters focalLength
	bool getCheckParameters_focalLength();
	void setCheckParameters_focalLength(bool checkPara);
	// check parameters thickness
	bool getCheckParameters_thickness();
	void setCheckParameters_thickness(bool checkPara);
	// check parameters semi height
	bool getCheckParameters_semiHeight();
	void setCheckParameters_semiHeight(bool checkPara);
	// fliped by 180 degrees
	bool getFlipedBy180Degrees();
	void setFlipedBy180Degrees(bool fliped180Degrees);
	// position in best match lens vec
	void setPositionInBestMatchLensVec(unsigned int posInBestMatchVec);
	unsigned int getPositionInBestMatchLensVec();

	// export data to txt
	void exportDataToTXT(std::string location, std::string name);

private:
	OpticalSystemElement mOptSysEle{};
	real mMerit{};
	lensTypes mLensType{};
	std::string mNameLens{};
	std::string mCatalogNumber{};

	bool mCheckParameters_focalLength{};
	bool mCheckParameters_thickness{};
	bool mCheckParameters_semiHeight{};

	bool mFlipedBy180Degrees{};

	unsigned int mPosInBestMatchVec{};
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
	real getMinDefaut_percent_focalLength();
	void setMinDefault_percent_focalLength(real minDefault);
	real getMinDefaut_percent_thickness();
	void setMinDefault_percent_thickness(real minDefault);
	real getMinDefaut_percent_semiHeight();
	void setMinDefault_percent_semiHeight(real minDefault);

	// max default
	real getMaxDefaut_percent_focalLength();
	void setMaxDefault_percent_focalLength(real maxDefault);
	real getMaxDefaut_percent_thickness();
	void setMaxDefault_percent_thickness(real maxDefault);
	real getMaxDefaut_percent_semiHeight();
	void setMaxDefault_percent_semiHeight(real maxDefault);

	// *** FOCAL LENGTH *** //
	// min percent surface focal length
	void setMinPercent_surface_i_focalLength(unsigned int surfaceNo, real percentMin);
	real getMinPercent_surface_i_focalLength(unsigned int surfaceNo);
	// max percent surface focal length
	void setMaxPercent_surface_i_focalLength(unsigned int surfaceNo, real percentMax);
	real getMaxPercent_surface_i_focalLength(unsigned int surfaceNo);
	// focal lenght weight
	void setFocalLenght_weight(real weight);
	real getFocalLenght_weight();
	// weight focal length surface
	void setWeightFocalLengthSurface_i(unsigned int surfaceNo, real weight);
	real getWeightFocalLengthSurface_i(unsigned int surfaceNo);
	// *** *** //

	// *** THICKNESS *** //
	// min percent surface thickness
	void setMinPercent_surface_i_thickness(unsigned int surfaceNo, real percentMin);
	real getMinPercent_surface_i_thickness(unsigned int surfaceNo);
	// max percent surface thickness
	void setMaxPercent_surface_i_thickness(unsigned int surfaceNo, real percentMax);
	real getMaxPercent_surface_i_thickness(unsigned int surfaceNo);
	// weight thickenss surface
	void setWeightThicknessSurface_i(unsigned int surfaceNo, real weight);
	real getWeightThicknessSurface_i(unsigned int surfaceNo);
	// thickness weight
	void setTickness_weight(real weight);
	real getThickness_weight();


	// *** SEMI HEIGHT *** //
	// min percent surface semi height
	void setMinPercent_surface_i_semiHeight(unsigned int surfaceNo, real percentMin);
	real getMinPercent_surface_i_semiHeight(unsigned int surfaceNo);
	// max percent surface semi height
	void setMaxPercent_surface_i_semiHeight(unsigned int surfaceNo, real percentMax);
	real getMaxPercent_surface_i_semiHeight(unsigned int surfaceNo);
	// weight semiHeight surface
	void setWeightSemiHeightSurface_i(unsigned int surfaceNo, real weight);
	real getWeightSemiHeightSurface_i(unsigned int surfaceNo);
	// semi height weight
	void setSemiHeight_weight(real weight);
	real getSemiHeight_weight();


	// pref lens type vec
	void setPrefLensTypeSurfaceAndFactorSurface_i(unsigned int surfaceNo, std::vector<lensTypes> prefType, real factor);
	prefLensTypeAndFactro getPrefLensTyeAndFactorSurface_i(unsigned int surfaceNo);

	// refrectiv index surrounding material
	void setRefIndexSurroundMat(real refIndexSurMat);
	real getRefIndexSurroundMat();

private:
	std::vector<lensTypes> mCatalotToLoad_default;
	real mMinDefault_focalLength;
	real mMaxDefault_focalLength;
	real mMinDefault_thickness;
	real mMaxDefault_thickness;
	real mMinDefault_semiHeight;
	real mMaxDefault_semiHeight;

	std::vector<real> mMin_default_percent_focalLength;
	std::vector<real> mMax_default_percent_focalLength;
	std::vector<real> mWeightFocalLength_default_vec;
	real mWeightFocalLengthDefault;

	std::vector<real> mMin_default_percent_thickness;
	std::vector<real> mMax_default_percent_thickness;
	std::vector<real> mWeightThickness_default_vec;
	real mWeightThicknessDefault;

	std::vector<real> mMin_default_percent_semiHeight;
	std::vector<real> mMax_default_percent_semiHeight;
	std::vector<real> mWeightSemiHeight_default_vec;
	real mWeightSemiHeightDefault;

	std::vector<prefLensTypeAndFactro> mPrefLensType_vec;

	real mRefIndexSurMat;
};

class  LensReplace
{
public:
	LensReplace();
	//LensReplace(OpticalSystem_LLT opticalSystem_LLT);
	LensReplace(OpticalSystemElement opticalSystemElement);
	~LensReplace();

	void replaceLensesAccordingToLensReplaceSequence_superFct(/*replace sequence*/ replaceSequence lensRepSequence, /*number best fit lenses*/ unsigned numberBestFitLenses);


	void saveFixedThicknessesLenses_doNotUseThatFct();
	void saveFixedThicknessesLenses();
	void reloadThicknessesAndFixed();
	
	// load lens Catalogs
	void loadLensCata(std::vector<lensTypes> loadLensCatalogEO);
	void load_ALL_LensCatalogs();
	
	bool findCatalog(std::vector<lensTypes> loadLensCatalog_vec, lensTypes toLoadCatalog);

	// calculate focal lenght
	real calcFocalLenghtOptSys(OpticalSystem_LLT optSys_LLT);
	// calculate thickness
	real calculateThickness_Z(OpticalSystem_LLT optSys_LLT);
	// calculate semi height
	real calcMaxSemiHeigh(OpticalSystem_LLT optSys_LLT);



	std::vector<parameterLens> calcParameterLenses(std::vector<OpticalSystem_LLT> lensesInOptSys);
	std::vector<parameterLens> getParameterLenses();

	void setOptSys_LLT(OpticalSystem_LLT optSys_LLT);
	void setOpticalSystemEle(OpticalSystemElement optSysEle);

	std::vector<OptSysEle_Merit_LensType> findOptSysEle_lens_inCatalog_TwoSurfaces(parameterLens paraLens, std::vector<LensesTwoSurfaces> AllLensesTwoSurfaces, real weightFocal, real weightThickness, real weightSemiHeight);
	std::vector<OptSysEle_Merit_LensType>  findOptSysEle_lens_inCatalog_ThreeSurfaces(parameterLens paraLens, std::vector<LensThreeSurfaces> AllLensesThreeSurfaces, real weightFocal, real weightThickness, real weightSemiHeight);
	std::vector<OptSysEle_Merit_LensType>  findOptSysEle_lens_inCatalog_FourSurfaces(parameterLens paraLens, std::vector<LensFourSurfaces> AllLensesFourSurfaces, real weightFocal, real weightThickness, real weightSemiHeight);

	OptSysEle_Merit_LensType checkLensCatalogsForBestFitLens(/*lens number*/ unsigned int lensNo, /*parameter lens*/ parameterLens paraLens);
	std::vector<OptSysEle_Merit_LensType> checkLensCatalogsForBestFitLenses_many(/*lens number*/ unsigned int lensNo, /*parameter lens*/ parameterLens paraLens, /*number best fit lenses*/ unsigned int numberLenses);
	std::vector<OptSysEle_Merit_LensType>  getBestOptSys(std::vector<OptSysEle_Merit_LensType> optSysEle_merit_lensType_vec, unsigned int numberSystems);

	real calcualteMerit(real target, real is, real weight);
	real calcualteMerit_lens(real focalParam, real thicknessParam, real semiHeightParam, real focalTemp, real focalWeight, real thicknessTemp, real thicknessWeight, real semiHeightTemp, real semiHeightWeight);

	void replaceLens(unsigned int lensNo, OpticalSystemElement fillInOptSysEle);

	void replaceSuperFuction(OpticalSystemElement optSysEle);
	void replaceSuperFuction(OpticalSystem_LLT optSys_LLT);

	OpticalSystemElement getOpticalSysEle_replacedLens();
	OpticalSystemElement getOpticalSysEle_startSystem();
	std::vector<OpticalSystemElement> getOpticalSysEle_replacedLens_vec();

	bool checkValueMinMax(real val, real min, real max);

	void adjustThicknessesAccordingToFixed();

	// *** set default parameters
	// refrectiv index surrounding material
	void setRefIndexSurroundMat(real refIndexSurMat);
	real getRefIndexSurroundMat();
	// ***

	void checkForThicknessVariablesInSurroundingMaterialAndAdjust();



private:
	OpticalSystemElement mOpticalSystemEle;
	OpticalSystemElement mOpticalSystemEle_replaceLens;
	OpticalSystem_LLT mOpticalSystem_LLT_replaceLens;

	// lens catalogs
	EdmundOpticsLensCatalog mEOLensCatalog{};
	ThorlabsLensCatalog mThorlabsLensCatalog{};
	QioptiqLensCatalog mQioptiqLensCatalog{};


	std::vector<lensTypes> mLoadLensCatalogEO;
	std::vector<lensTypes> mLoadLensCatalogThorlabs;
	std::vector<lensTypes> mLoadLensCatalogQioptiq;

	/*EdmundOptics*/
	std::vector<LensesTwoSurfaces> mAll_EO_DoubleConvex_VIS_NIR; //https://www.edmundoptics.de/f/vis-nir-coated-double-convex-dcx-lenses/13504/
	std::vector<LensThreeSurfaces> mAll_EO_PosAchromat_MgF_Coated; //https://www.edmundoptics.de/f/MgFsub2sub-Coated-Achromatic-Lenses/12006/
	std::vector<LensesTwoSurfaces> mAll_EO_PlanConvex_VIS_NIR; //https://www.edmundoptics.de/f/vis-nir-coated-plano-convex-pcx-lenses/12278/
	std::vector<LensesTwoSurfaces> mAll_EO_DoubleConcav_VIS_NIR; //https://www.edmundoptics.de/f/vis-nir-coated-double-concave-dcv-lenses/13540/
	std::vector<LensesTwoSurfaces> mAll_EO_PlanConcav_VIS_NIR; //https://www.edmundoptics.de/f/vis-nir-coated-plano-concave-pcv-lenses/13512/
	std::vector<LensesTwoSurfaces> mAll_EO_DoubleConcav_NIR_I;
	std::vector<LensThreeSurfaces> mAll_EO_PosAchromat_VIS_NIR;
	std::vector<LensThreeSurfaces> mAll_EO_NegAchromat_Broadband_AR_Coated;
	std::vector<LensThreeSurfaces> mAll_EO_LargePrecisionAchromat_NoAirSpace;
	std::vector<LensFourSurfaces> mAll_EO_LargePrecisionAchromat_AirSpace;
	std::vector<LensFourSurfaces> mAll_EO_HastingsTripletAchromat;
	std::vector<LensFourSurfaces> mAll_EO_SteinheilTripletAchromat;
	std::vector<LensesTwoSurfaces> mAll_EO_MicroPlanConvex;
	std::vector<LensesTwoSurfaces> mAll_EO_LargePlanConvexCondensor;
	/*Thorlabs*/
	std::vector<LensThreeSurfaces> mAll_Th_AchromatDoublets_AR_Coated;
	std::vector<LensesTwoSurfaces> mAll_Th_NBK7_PlanConvex_AR_Coated_400_1100;
	std::vector<LensesTwoSurfaces> mAll_Th_NBK7_BiConvex_AR_Coated_350_700;
	std::vector<LensesTwoSurfaces> mAll_Th_NBK7_PlanConcav_AR_Coated_350_700;
	std::vector<LensesTwoSurfaces> mAll_Th_NBK7_NSF11_BiConcav_AR_Coated_350_700;
	std::vector<LensesTwoSurfaces> mAll_Th_NBK7_BestFormSpherical_AR_Coated_350_700;
	std::vector<LensesTwoSurfaces> mAll_Th_NBK7_PosMeniscus_Uncoated;
	std::vector<LensesTwoSurfaces> mAll_Th_NBK7_NegMeniscus_Uncoated;
	std::vector<LensFourSurfaces> mAll_Th_SteinheilTripletAchromat_Visible;
	std::vector<LensFourSurfaces> mAll_Th_HastingsTripletAchromatVisible;
	/*Qioptiq*/
	std::vector<LensesTwoSurfaces> mAll_Qi_PlanConvex_ARB2_VIS;
	std::vector<LensesTwoSurfaces> mAll_Qi_SymmetricConvex_ARB2_VIS;
	std::vector<LensesTwoSurfaces> mAll_Qi_PlanConcav_ARB2_VIS;
	std::vector<LensesTwoSurfaces> mAll_Qi_SymmetricConcav_ARB2_VIS;
	std::vector<LensThreeSurfaces> mAll_Qi_PosAchromat_VIS_3_31_ARB2_VIS;
	std::vector<LensThreeSurfaces> mAll_Qi_PosAchromat_VIS_31_40_ARB2_VIS;
	std::vector<LensThreeSurfaces> mAll_Qi_NegAchromat_ARB2_VIS;
	

	defaultPara_LensReplace_struct mDefaultPara_LensReplace;
	std::vector<OpticalSystem_LLT> mOptSysLLT_lenses_vec;
	std::vector<parameterLens> mParameterLenses;
	unsigned mNoLenses;



	std::vector<thicknessAndPosition> mThicknessesAndPos_vec;

	std::vector<OpticalSystemElement> mReplacedOptSysEle_vec{};
};

