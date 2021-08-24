#include "LensReplace.h"
#include "..\oftenUseNamespace\oftenUseNamespace.h"


thicknessAndPosition::thicknessAndPosition() {};
thicknessAndPosition::~thicknessAndPosition() {};

// position
void thicknessAndPosition::setPosition(unsigned int pos)
{
	mPosition = pos;
}
unsigned int thicknessAndPosition::getPosition()
{
	return mPosition;
}

// thickness Z
void thicknessAndPosition::setThickness_Z(real thickness__Z)
{
	mThickness_Z = thickness__Z;
}
real thicknessAndPosition::getThickness_Z()
{
	return mThickness_Z;
}

// fixed
void thicknessAndPosition::setFixed(bool fixed)
{
	mFixed = fixed;
}
bool thicknessAndPosition::getFixed()
{
	return mFixed;
}

// prefere lens Type
lensTypes prefLensTypeAndFactro::getPrefLensType()
{
	return mLensType;
}
void prefLensTypeAndFactro::setPrefensType(lensTypes lenstype)
{
	mLensType = lenstype;
}
// factor
real prefLensTypeAndFactro::getFactor()
{
	return mFactor;
}
void prefLensTypeAndFactro::setFactor(real factor)
{
	mFactor = factor;
}

// optical system
OpticalSystemElement OptSysEle_Merit_LensType::getOptSysEle()
{
	return mOptSysEle;
}
void OptSysEle_Merit_LensType::setOpticalSystemEle(OpticalSystemElement optSysEle)
{
	mOptSysEle = optSysEle;
}
// merit value
real OptSysEle_Merit_LensType::getMerit()
{
	return mMerit;
}
void OptSysEle_Merit_LensType::setMerit(real merit)
{
	mMerit = merit;
}
// lens type
lensTypes OptSysEle_Merit_LensType::getLensType()
{
	return mLensType;
}
void OptSysEle_Merit_LensType::setLensType(lensTypes lensType)
{
	mLensType = lensType;
}
// name of the lens
std::string OptSysEle_Merit_LensType::getLensCatalog()
{
	return mNameLens;
}
void OptSysEle_Merit_LensType::setLensCatalog(std::string nameLens)
{
	mNameLens = nameLens;
}
// catalog number
unsigned int OptSysEle_Merit_LensType::getCatalogNumber()
{
	return mCatalogNumber;
}
void OptSysEle_Merit_LensType::setCatalogNumber(unsigned int catalogNumber)
{
	mCatalogNumber = catalogNumber;
}
// check parameters
bool OptSysEle_Merit_LensType::getCheckParameters_focalLength()
{
	return mCheckParameters_focalLength;
}
void OptSysEle_Merit_LensType::setCheckParameters_focalLength(bool checkPara)
{
	mCheckParameters_focalLength = checkPara;
}
// check parameters thickness
bool OptSysEle_Merit_LensType::getCheckParameters_thickness()
{
	return mCheckParameters_thickness;
}
void OptSysEle_Merit_LensType::setCheckParameters_thickness(bool checkPara)
{
	mCheckParameters_thickness = checkPara;
}
// check parameters semi height
bool OptSysEle_Merit_LensType::getCheckParameters_semiHeight()
{
	return mCheckParameters_semiHeight;
}
void OptSysEle_Merit_LensType::setCheckParameters_semiHeight(bool checkPara)
{
	mCheckParameters_semiHeight = checkPara;
}
// fliped by 180 degrees
bool OptSysEle_Merit_LensType::getFlipedBy180Degrees()
{
	return mFlipedBy180Degrees;
}
void OptSysEle_Merit_LensType::setFlipedBy180Degrees(bool fliped180Degrees)
{
	mFlipedBy180Degrees = fliped180Degrees;
}
// position in best match lens vec
void OptSysEle_Merit_LensType::setPositionInBestMatchLensVec(unsigned int posInBestMatchVec)
{
	mPosInBestMatchVec = posInBestMatchVec;
}
unsigned int OptSysEle_Merit_LensType::getPositionInBestMatchLensVec()
{
	return mPosInBestMatchVec;
}

// value
real ValueMinMax::getValue()
{
	return mValue;
}
void ValueMinMax::setValue(real value)
{
	mValue = value;
}
// min
real ValueMinMax::getMin()
{
	return mMin;
}

void ValueMinMax::setMin(real min)
{
	mMin = min;
}
// max
real ValueMinMax::getMax()
{
	return mMax;
}
void ValueMinMax::setMax(real max)
{
	mMax = max;
}

// min default
real defaultPara_LensReplace_struct::getMinDefaut_percent_focalLength()
{
	return mMinDefault_focalLength;
}
void defaultPara_LensReplace_struct::setMinDefault_percent_focalLength(real minDefault)
{
	mMinDefault_focalLength = minDefault;
}

real defaultPara_LensReplace_struct::getMinDefaut_percent_thickness()
{
	return mMinDefault_thickness;
}
void defaultPara_LensReplace_struct::setMinDefault_percent_thickness(real minDefault)
{
	mMinDefault_thickness = minDefault;
}
real defaultPara_LensReplace_struct::getMinDefaut_percent_semiHeight()
{
	return mMinDefault_semiHeight;
}
void defaultPara_LensReplace_struct::setMinDefault_percent_semiHeight(real minDefault)
{
	mMinDefault_semiHeight = minDefault;
}

// max default
real defaultPara_LensReplace_struct::getMaxDefaut_percent_focalLength()
{
	return mMaxDefault_focalLength;
}
void defaultPara_LensReplace_struct::setMaxDefault_percent_focalLength(real maxDefault)
{
	mMaxDefault_focalLength = maxDefault;
}
real defaultPara_LensReplace_struct::getMaxDefaut_percent_thickness()
{
	return mMaxDefault_thickness;
}
void defaultPara_LensReplace_struct::setMaxDefault_percent_thickness(real maxDefault)
{
	mMaxDefault_thickness = maxDefault;
}
real defaultPara_LensReplace_struct::getMaxDefaut_percent_semiHeight()
{
	return mMaxDefault_semiHeight;
}
void defaultPara_LensReplace_struct::setMaxDefault_percent_semiHeight(real maxDefault)
{
	mMaxDefault_semiHeight = maxDefault;
}

// load default parameter
void defaultPara_LensReplace_struct::loadDefaultPara(unsigned int NoLenses)
{
	// load default catalog
	std::vector<lensTypes> CatalogToLoad;
	CatalogToLoad.push_back(lensTypes::EO_PosAchromat_MgF_Coated);
	mCatalotToLoad_default = CatalogToLoad;

	setMinDefault_percent_focalLength(10.0);
	setMaxDefault_percent_focalLength(10.0);

	setMinDefault_percent_thickness(20.0);
	setMaxDefault_percent_thickness(20.0);

	setMinDefault_percent_semiHeight(15.0);
	setMaxDefault_percent_semiHeight(15.0);

	setFocalLenght_weight(1.0);
	setTickness_weight(1.0);
	setSemiHeight_weight(1.0);

	// load default min percent focal length
	mMin_default_percent_focalLength.resize(NoLenses);
	std::fill(mMin_default_percent_focalLength.begin(), mMin_default_percent_focalLength.end(), mMinDefault_focalLength);

	// load default max percent focal length
	mMax_default_percent_focalLength.resize(NoLenses);
	std::fill(mMax_default_percent_focalLength.begin(), mMax_default_percent_focalLength.end(), mMaxDefault_focalLength);

	// load default min percent thickness
	mMin_default_percent_thickness.resize(NoLenses);
	std::fill(mMin_default_percent_thickness.begin(), mMin_default_percent_thickness.end(), mMinDefault_thickness);

	// load default max percent thickness
	mMax_default_percent_thickness.resize(NoLenses);
	std::fill(mMax_default_percent_thickness.begin(), mMax_default_percent_thickness.end(), mMaxDefault_thickness);

	// load default min percent semiHeigth
	mMin_default_percent_semiHeight.resize(NoLenses);
	std::fill(mMin_default_percent_semiHeight.begin(), mMin_default_percent_semiHeight.end(), mMinDefault_semiHeight);

	// load default max percent semiHeigth
	mMin_default_percent_semiHeight.resize(NoLenses);
	std::fill(mMin_default_percent_semiHeight.begin(), mMin_default_percent_semiHeight.end(), mMaxDefault_semiHeight);


	// load default focal length
	mWeightFocalLength_default_vec.resize(NoLenses);
	std::fill(mWeightFocalLength_default_vec.begin(), mWeightFocalLength_default_vec.end(), mWeightFocalLengthDefault);

	// load default thickness
	mWeightThickness_default_vec.resize(NoLenses);
	std::fill(mWeightThickness_default_vec.begin(), mWeightThickness_default_vec.end(), mWeightThicknessDefault);

	// load default semi height
	mWeightSemiHeight_default_vec.resize(NoLenses);
	std::fill(mWeightSemiHeight_default_vec.begin(), mWeightSemiHeight_default_vec.end(), mWeightSemiHeightDefault);

	// prefere lens type
	mPrefLensType_vec.resize(NoLenses);
	for (unsigned int i = 0; i < NoLenses; ++i)
	{
		mPrefLensType_vec[i].setPrefensType(lensTypes::EO_PosAchromat_MgF_Coated);
		mPrefLensType_vec[i].setFactor(1.5);
	}

	mRefIndexSurMat = 1.0;
}

// catalogs to load
std::vector<lensTypes> defaultPara_LensReplace_struct::getCatalogToLoad() const
{
	return mCatalotToLoad_default;
}

void defaultPara_LensReplace_struct::getCatalogToLoad(const std::vector<lensTypes>& catalogToLoad)
{
	mCatalotToLoad_default = catalogToLoad;
}

// min percent
void defaultPara_LensReplace_struct::setMinPercent_surface_i_focalLength(unsigned int surfaceNo, real percentMin)
{
	mMin_default_percent_focalLength[surfaceNo] = percentMin;
}
real defaultPara_LensReplace_struct::getMinPercent_surface_i_focalLength(unsigned int surfaceNo)
{
	return mMin_default_percent_focalLength[surfaceNo];
}

// max percent
void defaultPara_LensReplace_struct::setMaxPercent_surface_i_focalLength(unsigned int surfaceNo, real percentMax)
{
	mMax_default_percent_focalLength[surfaceNo] = percentMax;
}
real defaultPara_LensReplace_struct::getMaxPercent_surface_i_focalLength(unsigned int surfaceNo)
{
	return mMax_default_percent_focalLength[surfaceNo];
}

// focal lenght weight
void defaultPara_LensReplace_struct::setFocalLenght_weight(real weight)
{
	mWeightFocalLengthDefault = weight;
}
real defaultPara_LensReplace_struct::getFocalLenght_weight()
{
	return mWeightFocalLengthDefault;
}
// thickness weight
void defaultPara_LensReplace_struct::setTickness_weight(real weight)
{
	mWeightThicknessDefault = weight;
}
real defaultPara_LensReplace_struct::getThickness_weight()
{
	return mWeightThicknessDefault;
}
// semi height weight
void defaultPara_LensReplace_struct::setSemiHeight_weight(real weight)
{
	mWeightSemiHeightDefault = weight;
}
real defaultPara_LensReplace_struct::getSemiHeight_weight()
{
	return mWeightSemiHeightDefault;
}

// weight focal length surface
void defaultPara_LensReplace_struct::setWeightFocalLengthSurface_i(unsigned int surfaceNo, real weight)
{
	mWeightFocalLength_default_vec[surfaceNo] = weight;
}
real defaultPara_LensReplace_struct::getWeightFocalLengthSurface_i(unsigned int surfaceNo)
{
	return mWeightFocalLength_default_vec[surfaceNo];
}
// weight thickenss surface
void defaultPara_LensReplace_struct::setWeightThicknessSurface_i(unsigned int surfaceNo, real weight)
{
	mWeightThickness_default_vec[surfaceNo] = weight;
}
real defaultPara_LensReplace_struct::getWeightThicknessSurface_i(unsigned int surfaceNo)
{
	return mWeightThickness_default_vec[surfaceNo];
}
// weight semiHeight surface
void defaultPara_LensReplace_struct::setWeightSemiHeightSurface_i(unsigned int surfaceNo, real weight)
{
	mWeightSemiHeight_default_vec[surfaceNo] = weight;
}
real defaultPara_LensReplace_struct::getWeightSemiHeightSurface_i(unsigned int surfaceNo)
{
	return mWeightSemiHeight_default_vec[surfaceNo];
}

// min percent surface thickness
void defaultPara_LensReplace_struct::setMinPercent_surface_i_thickness(unsigned int surfaceNo, real percentMin)
{
	mMin_default_percent_thickness[surfaceNo] = percentMin;
}
real defaultPara_LensReplace_struct::getMinPercent_surface_i_thickness(unsigned int surfaceNo)
{
	return mMin_default_percent_thickness[surfaceNo];
}
// max percent surface thickness
void defaultPara_LensReplace_struct::setMaxPercent_surface_i_thickness(unsigned int surfaceNo, real percentMax)
{
	mMax_default_percent_thickness[surfaceNo] = percentMax;
}
real defaultPara_LensReplace_struct::getMaxPercent_surface_i_thickness(unsigned int surfaceNo)
{
	return mMax_default_percent_thickness[surfaceNo];
}


// min percent surface semi height
void  defaultPara_LensReplace_struct::setMinPercent_surface_i_semiHeight(unsigned int surfaceNo, real percentMin)
{
	mMin_default_percent_semiHeight[surfaceNo] = percentMin;
}
real  defaultPara_LensReplace_struct::getMinPercent_surface_i_semiHeight(unsigned int surfaceNo)
{
	return mMin_default_percent_semiHeight[surfaceNo];
}
// max percent surface semi height
void  defaultPara_LensReplace_struct::setMaxPercent_surface_i_semiHeight(unsigned int surfaceNo, real percentMax)
{
	mMax_default_percent_semiHeight[surfaceNo] = percentMax;
}
real  defaultPara_LensReplace_struct::getMaxPercent_surface_i_semiHeight(unsigned int surfaceNo)
{
	return mMax_default_percent_semiHeight[surfaceNo];
}

// pref lens type vec
void defaultPara_LensReplace_struct::setPrefLensTypeSurfaceAndFactorSurface_i(unsigned int surfaceNo, lensTypes prefType, real factor)
{
	mPrefLensType_vec[surfaceNo].setPrefensType(prefType);
	mPrefLensType_vec[surfaceNo].setFactor(factor);
}

prefLensTypeAndFactro defaultPara_LensReplace_struct::getPrefLensTyeAndFactorSurface_i(unsigned int surfaceNo)
{
	return mPrefLensType_vec[surfaceNo];
}

// refrectiv index surrounding material
void defaultPara_LensReplace_struct::setRefIndexSurroundMat(real refIndexSurMat)
{
	mRefIndexSurMat = refIndexSurMat;
}
real defaultPara_LensReplace_struct::getRefIndexSurroundMat()
{
	return mRefIndexSurMat;
}

LensReplace::LensReplace() {}
LensReplace::~LensReplace() {}


//LensReplace::LensReplace(OpticalSystem_LLT opticalSystem_LLT):
//mOpticalSystem_LLT(opticalSystem_LLT)
//{
//	mOptSysLLT_lenses_vec = findLensesInOptSys_LLT(mOpticalSystem_LLT);
//	mNoLenses = mOptSysLLT_lenses_vec.size();
//	mDefaultPara_LensReplace.loadDefaultPara(mNoLenses);
//	mParameterLenses = calcParameterLenses(mOptSysLLT_lenses_vec);
//}

LensReplace::LensReplace(OpticalSystemElement opticalSystemElement) :
	mOpticalSystemEle(opticalSystemElement)
{
	mOpticalSystem_LLT_replaceLens = mOpticalSystemEle.getLLTconversion_doConversion();
	mOptSysLLT_lenses_vec = oftenUse::findLensesInOptSys_LLT(mOpticalSystem_LLT_replaceLens);
	mNoLenses = mOptSysLLT_lenses_vec.size();
	mDefaultPara_LensReplace.loadDefaultPara(mNoLenses);
	mParameterLenses = calcParameterLenses(mOptSysLLT_lenses_vec);
	saveFixedThicknessesLenses();
}



void LensReplace::replaceSuperFuction(OpticalSystemElement optSysEle)
{
	mOpticalSystemEle = optSysEle.getDeepCopyOptSysEle();
	mOpticalSystem_LLT_replaceLens = mOpticalSystemEle.getLLTconversion_doConversion();
	mOptSysLLT_lenses_vec = oftenUse::findLensesInOptSys_LLT(mOpticalSystem_LLT_replaceLens);
	mNoLenses = mOptSysLLT_lenses_vec.size();
	mDefaultPara_LensReplace.loadDefaultPara(mNoLenses);
	mParameterLenses = calcParameterLenses(mOptSysLLT_lenses_vec);
	saveFixedThicknessesLenses();
}

void LensReplace::replaceSuperFuction(OpticalSystem_LLT optSys_LLT)
{
	mOpticalSystem_LLT_replaceLens = optSys_LLT.clone();
	mOptSysLLT_lenses_vec = oftenUse::findLensesInOptSys_LLT(mOpticalSystem_LLT_replaceLens);
	mNoLenses = mOptSysLLT_lenses_vec.size();
	mDefaultPara_LensReplace.loadDefaultPara(mNoLenses);
	mParameterLenses = calcParameterLenses(mOptSysLLT_lenses_vec);
	saveFixedThicknessesLenses_doNotUseThatFct();
}

void LensReplace::setOptSys_LLT(OpticalSystem_LLT optSys_LLT)
{
	mOpticalSystem_LLT_replaceLens = optSys_LLT;
}

void LensReplace::setOpticalSystemEle(OpticalSystemElement optSysEle)
{
	mOpticalSystemEle = optSysEle.getDeepCopyOptSysEle();
}

// focal lenght
ValueMinMax parameterLens::getFocalLengthMinMax()
{
	return mFocalLenthMinMax;
}
void parameterLens::setFocalLengthMinMax(real focalLength, real min, real max)
{
	mFocalLenthMinMax.setValue(focalLength);
	mFocalLenthMinMax.setMin(min);
	mFocalLenthMinMax.setMax(max);
}
// thickness
ValueMinMax parameterLens::getThicknessMinMax()
{
	return mThicknessMinMax;
}
void parameterLens::setThicknessMinMax(real thickness, real min, real max)
{
	mThicknessMinMax.setValue(thickness);
	mThicknessMinMax.setMin(min);
	mThicknessMinMax.setMax(max);
}
// semi height
ValueMinMax parameterLens::getSemiHeightMinMax()
{
	return mSemiHeightMinMax;
}
void parameterLens::setSemiHeigthMinMax(real semiHeight, real min, real max)
{
	mSemiHeightMinMax.setValue(semiHeight);
	mSemiHeightMinMax.setMin(min);
	mSemiHeightMinMax.setMax(max);
}

// calculate the min value
real parameterLens::calcMinValue(real value, real percent)
{
	return (100 - percent) * value / 100;
}

// calculate the max value
real parameterLens::calcMaxValue(real value, real percent)
{
	return (100 + percent) * value / 100;
}



void LensReplace::loadLensCata(std::vector<lensTypes> loadLensCatalogEO)
{
	mLoadLensCatalogEO = loadLensCatalogEO;

	//DConvexL
	bool load_DConvexL = findCatalog(mLoadLensCatalogEO, lensTypes::EO_DoubleConvex_VIS_NIR);
	if (load_DConvexL)
	{
		mEOLensCatalog.loadLensCatalogEO_double_convex_lenses();
		mAll_EO_DoubleConvex_VIS_NIR = mEOLensCatalog.getAll_DoubleConvexLenses();
	}
	//posAchromat
	bool load_posAchromat = findCatalog(mLoadLensCatalogEO, lensTypes::EO_PosAchromat_MgF_Coated);
	if (load_posAchromat)
	{
		mEOLensCatalog.loadLensCatalogEO_achroamticLensesMgF();
		mAll_EO_PosAchromat_MgF_Coated = mEOLensCatalog.getAll_achroamticLensesMgF();
	}
	//PConvexL
	bool load_PConvexL = findCatalog(mLoadLensCatalogEO, lensTypes::EO_PlanConvex_VIS_NIR);
	if (load_PConvexL)
	{
		mEOLensCatalog.loadLensCatalogEO_plan_convex_lenses_VIS_NIR();
		mAll_EO_PlanConvex_VIS_NIR = mEOLensCatalog.getAll_PlanConvexLenses();
	}
	//DConcavL
	bool load_DConcavL = findCatalog(mLoadLensCatalogEO, lensTypes::EO_DoubleConcav_VIS_NIR);
	if (load_DConcavL)
	{
		mEOLensCatalog.loadLensCatalogEO_double_concav_lenses_VIS_NIR();
		mAll_EO_DoubleConcav_VIS_NIR = mEOLensCatalog.getAll_DoubleConcavLenses();
	}
	//PConcavL
	bool load_PConcavL = findCatalog(mLoadLensCatalogEO, lensTypes::EO_PlanConcav_VIS_NIR);
	if (load_PConcavL)
	{
		mEOLensCatalog.loadLensCatalogEO_plan_concav_lenses_VIS_NIR();
		mAll_EO_PlanConcav_VIS_NIR = mEOLensCatalog.getAll_PlanConcavLenses();

	}

}

void LensReplace::load_ALL_LensCatalogs()
{
	/*EdmundOptics*/
	mEOLensCatalog.loadLensCatalogEO_achroamticLensesMgF();
	mEOLensCatalog.loadLensCatalogEO_achroamticLenses_VIS_NIR_Coating();
	mEOLensCatalog.loadLensCatalogEO_Broadband_AR_Coated_Negative_Achromatic_Lenses();
	mEOLensCatalog.loadLensCatalogEO_double_concav_lenses_NIR_I();
	mEOLensCatalog.loadLensCatalogEO_double_concav_lenses_VIS_NIR();
	mEOLensCatalog.loadLensCatalogEO_double_convex_lenses();
	mEOLensCatalog.loadLensCatalogEO_Hastings_Triplet_Achromatic_Lenses();
	mEOLensCatalog.loadLensCatalogEO_Large_PCX_Condenser_Lenses();
	mEOLensCatalog.loadLensCatalogEO_Large_Precision_Achromatic_Lenses_Airspace01mm();
	mEOLensCatalog.loadLensCatalogEO_Large_Precision_Achromatic_Lenses_NoAirspace();
	mEOLensCatalog.loadLensCatalogEO_Micro_Plano_Convex_PCX_Lenses();
	mEOLensCatalog.loadLensCatalogEO_plan_concav_lenses_VIS_NIR();
	mEOLensCatalog.loadLensCatalogEO_plan_convex_lenses_VIS_NIR();
	mEOLensCatalog.loadLensCatalogEO_Steinheil_Triplet_Achromatic_Lenses();

	/*Thorlabs*/
	mThorlabsLensCatalog.loadLensCatalogThorlabs_1Zoll_N_BK7_Best_Form_Spherical_Lenses_AR_Coating_350_700_nm();
	mThorlabsLensCatalog.loadLensCatalogThorlabs_1Zoll_N_BK7_Negative_Meniscus_Lenses_Uncoated();
	mThorlabsLensCatalog.loadLensCatalogThorlabs_Achromativ_Doublets_AR_Coated_lenses();
	mThorlabsLensCatalog.loadLensCatalogThorlabs_Hastings_Triplet_Achromatic_Lenses_Visible();
	mThorlabsLensCatalog.loadLensCatalogThorlabs_N_BK7_and_N_SF11_Bi_Concave_Lenses_AR_Coating_350_700_nm();
	mThorlabsLensCatalog.loadLensCatalogThorlabs_N_BK7_Bi_Convex_Lenses_AR_Coating_350_700_nm();
	mThorlabsLensCatalog.loadLensCatalogThorlabs_N_BK7_Plano_Concave_Lenses_AR_Coating_350_700_nm();
	mThorlabsLensCatalog.loadLensCatalogThorlabs_N_BK7_Plano_Convex_Lenses_AR_Coating_400_1100_nm();
	mThorlabsLensCatalog.loadLensCatalogThorlabs_N_BK7_Positive_Meniscus_Lenses_Uncoated();
	mThorlabsLensCatalog.loadLensCatalogThorlabs_Steinheil_Triplet_Achromatic_Lenses_Visible();

	/*Qioptiq*/
	mQioptiqLensCatalog.loadLensCatalogQioptiq_Achromats_Negative_Unmounted_ARB2_VIS();
	mQioptiqLensCatalog.loadLensCatalogQioptiq_Achromats_VIS_Positive_dia_3_mm_to_31_5_mm_unmounted_N_BK7_ARB2_VIS();
	mQioptiqLensCatalog.loadLensCatalogQioptiq_Achromats_VIS_Positive_from_40_mm_diameter_unmounted_N_BK7_ARB2_VIS();
	mQioptiqLensCatalog.loadLensCatalogQioptiq_PlanoConvex_lenses_unmounted_ARB2_VIS();
	mQioptiqLensCatalog.loadLensCatalogQioptiq_Plano_concave_lenses_unmounted_N_BK7_ARB2_VIS();
	mQioptiqLensCatalog.loadLensCatalogQioptiq_Symmetric_concave_lenses_unmounted_N_BK7_ARB2_VIS();
	mQioptiqLensCatalog.loadLensCatalogQioptiq_Symmetric_convex_lenses_unmounted_ARB2_VIS();


	// save lenses from edmund optics in vector
	mAll_EO_DoubleConvex_VIS_NIR = mEOLensCatalog.getAll_DoubleConvexLenses();
	mAll_EO_PosAchromat_MgF_Coated = mEOLensCatalog.getAll_achroamticLensesMgF(); 
	mAll_EO_PlanConvex_VIS_NIR = mEOLensCatalog.getAll_PlanConvexLenses(); 
	mAll_EO_DoubleConcav_VIS_NIR = mEOLensCatalog.getAll_DoubleConcavLenses(); 
	mAll_EO_PlanConcav_VIS_NIR = mEOLensCatalog.getAll_PlanConcavLenses(); 
	mAll_EO_DoubleConcav_NIR_I = mEOLensCatalog.getAll_LensCatalogEO_double_concav_lenses_NIR_I();
	mAll_EO_PosAchromat_VIS_NIR = mEOLensCatalog.getAll_LensCatalogEO_achroamticLenses_VIS_NIR_Coating();
	mAll_EO_NegAchromat_Broadband_AR_Coated = mEOLensCatalog.getAll_LensCatalogEO_Broadband_AR_Coated_Negative_Achromatic_Lenses();
	mAll_EO_LargePrecisionAchromat_NoAirSpace = mEOLensCatalog.getAll_LensCatalogEO_Large_Precision_Achromatic_Lenses_NoAirspace();
	mAll_EO_LargePrecisionAchromat_AirSpace = mEOLensCatalog.getAll_LensCatalogEO_Large_Precision_Achromatic_Lenses_Airspace01mm();
	mAll_EO_HastingsTripletAchromat = mEOLensCatalog.getAll_LensCatalogEO_Hastings_Triplet_Achromatic_Lenses();
	mAll_EO_SteinheilTripletAchromat = mEOLensCatalog.getAll_LensCatalogEO_Steinheil_Triplet_Achromatic_Lenses();
	mAll_EO_MicroPlanConvex = mEOLensCatalog.getAll_Micro_Plano_Convex_PCX_Lenses();
	mAll_EO_LargePlanConvexCondensor = mEOLensCatalog.getAll_Large_PCX_Condenser_Lenses();

	// save lenses from thorlabs in vector
	mAll_Th_AchromatDoublets_AR_Coated = mThorlabsLensCatalog.getAll_Thorlabs_Achromativ_Doublets_AR_Coated_lenses();
	mAll_Th_NBK7_PlanConvex_AR_Coated_400_1100 = mThorlabsLensCatalog.getAll_Thorlabs_N_BK7_Plano_Convex_Lenses_AR_Coating_400_1100_nm();
	mAll_Th_NBK7_BiConvex_AR_Coated_350_700 = mThorlabsLensCatalog.getAll_Thorlabs_N_BK7_Bi_Convex_Lenses_AR_Coating_350_700_nm();
	mAll_Th_NBK7_PlanConcav_AR_Coated_350_700 = mThorlabsLensCatalog.getAll_Thorlabs_N_BK7_Plano_Concave_Lenses_AR_Coating_350_700_nm();
	mAll_Th_NBK7_NSF11_BiConcav_AR_Coated_350_700 = mThorlabsLensCatalog.getAll_Thorlabs_N_BK7_and_N_SF11_BiSConcave_Lenses_AR_Coating_350_700_nm();
	mAll_Th_NBK7_BestFormSpherical_AR_Coated_350_700 = mThorlabsLensCatalog.getAll_Thorlabs_1Zoll_N_BK7_Best_Form_Spherical_Lenses_AR_Coating_350_700_nm();
	mAll_Th_NBK7_PosMeniscus_Uncoated = mThorlabsLensCatalog.getAll_Thorlabs_N_BK7_Positive_Meniscus_Lenses_Uncoated();
	mAll_Th_NBK7_NegMeniscus_Uncoated = mThorlabsLensCatalog.getAll_1Zoll_N_BK7_Negative_Meniscus_Lenses_Uncoated();
	mAll_Th_SteinheilTripletAchromat_Visible = mThorlabsLensCatalog.getAll_Steinheil_Triplet_Achromatic_Lenses_Visible();
	mAll_Th_HastingsTripletAchromatVisible = mThorlabsLensCatalog.getAll_Hastings_Triplet_Achromatic_Lenses_Visible();

	// save lenses from qioptiq in vector
	mAll_Qi_PlanConvex_ARB2_VIS = mQioptiqLensCatalog.getAll_Qioptiq_PlanoConvex_lenses_unmounted_ARB2_VIS();
	mAll_Qi_SymmetricConvex_ARB2_VIS = mQioptiqLensCatalog.getAll_Symmetric_convex_lenses_unmounted_ARB2_VIS();
	mAll_Qi_PlanConcav_ARB2_VIS = mQioptiqLensCatalog.getAll_Plano_concave_lenses_unmounted_N_BK7_ARB2_VIS();
	mAll_Qi_SymmetricConcav_ARB2_VIS = mQioptiqLensCatalog.getAll_Symmetric_concave_lenses_unmounted_N_BK7_ARB2_VIS();
	mAll_Qi_PosAchromat_VIS_3_31_ARB2_VIS = mQioptiqLensCatalog.getAll_Achromats_VIS_Positive_dia_3_mm_to_31_5_mm_unmounted_N_BK7_ARB2_VIS();
	mAll_Qi_PosAchromat_VIS_31_40_ARB2_VIS = mQioptiqLensCatalog.getAll_Achromats_VIS_Positive_from_40_mm_diameter_unmounted_N_BK7_ARB2_VIS();
	mAll_Qi_NegAchromat_ARB2_VIS = mQioptiqLensCatalog.getAll_Achromats_Negative_Unmounted_ARB2_VIS();

	/*Edmund*/
	mLoadLensCatalogEO.push_back(lensTypes::EO_DoubleConvex_VIS_NIR);
	mLoadLensCatalogEO.push_back(lensTypes::EO_PosAchromat_MgF_Coated);
	mLoadLensCatalogEO.push_back(lensTypes::EO_PlanConvex_VIS_NIR);
	mLoadLensCatalogEO.push_back(lensTypes::EO_DoubleConcav_VIS_NIR);
	mLoadLensCatalogEO.push_back(lensTypes::EO_PlanConcav_VIS_NIR);
	mLoadLensCatalogEO.push_back(lensTypes::EO_DoubleConcav_NIR_I);
	mLoadLensCatalogEO.push_back(lensTypes::EO_PosAchromat_VIS_NIR);
	mLoadLensCatalogEO.push_back(lensTypes::EO_NegAchromat_Broadband_AR_Coated);
	mLoadLensCatalogEO.push_back(lensTypes::EO_LargePrecisionAchromat_NoAirSpace);
	mLoadLensCatalogEO.push_back(lensTypes::EO_LargePrecisionAchromat_AirSpace);
	mLoadLensCatalogEO.push_back(lensTypes::EO_HastingsTripletAchromat);
	mLoadLensCatalogEO.push_back(lensTypes::EO_SteinheilTripletAchromat);
	mLoadLensCatalogEO.push_back(lensTypes::EO_MicroPlanConvex);
	mLoadLensCatalogEO.push_back(lensTypes::EO_LargePlanConvexCondensor);

	/*Thorlabs*/
	mLoadLensCatalogThorlabs.push_back(lensTypes::Th_AchromatDoublets_AR_Coated);
	mLoadLensCatalogThorlabs.push_back(lensTypes::Th_NBK7_PlanConvex_AR_Coated_400_1100);
	mLoadLensCatalogThorlabs.push_back(lensTypes::Th_NBK7_BiConvex_AR_Coated_350_700);
	mLoadLensCatalogThorlabs.push_back(lensTypes::Th_NBK7_PlanConcav_AR_Coated_350_700);
	mLoadLensCatalogThorlabs.push_back(lensTypes::Th_NBK7_NSF11_BiConcav_AR_Coated_350_700);
	mLoadLensCatalogThorlabs.push_back(lensTypes::Th_NBK7_BestFormSpherical_AR_Coated_350_700);
	mLoadLensCatalogThorlabs.push_back(lensTypes::Th_NBK7_PosMeniscus_Uncoated);
	mLoadLensCatalogThorlabs.push_back(lensTypes::Th_NBK7_NegMeniscus_Uncoated);
	mLoadLensCatalogThorlabs.push_back(lensTypes::Th_SteinheilTripletAchromat_Visible);
	mLoadLensCatalogThorlabs.push_back(lensTypes::Th_HastingsTripletAchromatVisible);

	/*Qioptic*/
	mLoadLensCatalogQioptiq.push_back(lensTypes::Qi_PlanConvex_ARB2_VIS);
	mLoadLensCatalogQioptiq.push_back(lensTypes::Qi_SymmetricConvex_ARB2_VIS);
	mLoadLensCatalogQioptiq.push_back(lensTypes::Qi_PlanConcav_ARB2_VIS);
	mLoadLensCatalogQioptiq.push_back(lensTypes::Qi_SymmetricConcav_ARB2_VIS);
	mLoadLensCatalogQioptiq.push_back(lensTypes::Qi_PosAchromat_VIS_3_31_ARB2_VIS);
	mLoadLensCatalogQioptiq.push_back(lensTypes::Qi_PosAchromat_VIS_31_40_ARB2_VIS);
	mLoadLensCatalogQioptiq.push_back(lensTypes::Qi_NegAchromat_ARB2_VIS);

}

bool LensReplace::findCatalog(std::vector<lensTypes> loadLensCatalogEO_vec, lensTypes toLoadCatalog)
{

	bool checker = false;
	if (std::find(loadLensCatalogEO_vec.begin(), loadLensCatalogEO_vec.end(), toLoadCatalog) != loadLensCatalogEO_vec.end())
	{
		checker = true;
	}

	return checker;
}



real LensReplace::calcFocalLenghtOptSys(OpticalSystem_LLT optSys_LLT)
{
	std::vector<std::vector<real>> systemMatrix;
	systemMatrix.resize(2);
	systemMatrix[0].resize(2);
	systemMatrix[1].resize(2);

	std::vector<std::vector<std::vector<real>>> AllMatrix;

	// temp propagation matrix
	std::vector<std::vector<real>> tempMatrix_propagation;
	tempMatrix_propagation.resize(2);
	tempMatrix_propagation[0].resize(2);
	tempMatrix_propagation[1].resize(2);
	tempMatrix_propagation[0][0] = 1.0;
	tempMatrix_propagation[0][1] = 0.0;
	tempMatrix_propagation[1][1] = 1.0;

	// temp refraction matrix
	std::vector<std::vector<real>> tempMatrix_refraction;
	tempMatrix_refraction.resize(2);
	tempMatrix_refraction[0].resize(2);
	tempMatrix_refraction[1].resize(2);
	tempMatrix_refraction[0][0] = 1.0;
	tempMatrix_refraction[1][0] = 0.0;


	unsigned int size = optSys_LLT.getPosAndInteractingSurface().size() - 1;

	real tempPosSufaceZ;
	real tempPosSurfaceZ_befor;
	real tempDistance;


	std::shared_ptr<SurfaceIntersectionRay_LLT> tempSurface_ptr;
	real tempRadius;
	real tempDirection_Z;
	real tempN;
	real tempN_;
	bool changer = true;

	// calc all refraction matrix
	for (int i = size; i >= 0; --i)
	{
		tempSurface_ptr = optSys_LLT.getPosAndInteractingSurface()[i].getSurfaceInterRay_ptr();

		tempDirection_Z = tempSurface_ptr->getDirection().getZ();
		if (tempDirection_Z > 0)
		{
			tempN = tempSurface_ptr->getRefractiveIndex_A();
			tempN_ = tempSurface_ptr->getRefractiveIndex_B();
			tempRadius = tempSurface_ptr->getRadius();
		}
		else // tempDirection < 0
		{
			tempN = tempSurface_ptr->getRefractiveIndex_B();
			tempN_ = tempSurface_ptr->getRefractiveIndex_A();
			tempRadius = -1.0 * tempSurface_ptr->getRadius();
		}

		tempMatrix_refraction[1][1] = tempN / tempN_;
		tempMatrix_refraction[0][1] = (tempN - tempN_) / (tempRadius * tempN_);

		//Math::printSystemMatrix2x2(tempMatrix_refraction);

		AllMatrix.push_back(tempMatrix_refraction);



		if (i > 0)
		{
			optSys_LLT.getPosAndInteractingSurface()[size].getSurfaceInterRay_ptr();

			tempPosSufaceZ = tempSurface_ptr->getPoint().getZ();
			tempPosSurfaceZ_befor = optSys_LLT.getPosAndInteractingSurface()[i - 1].getSurfaceInterRay_ptr()->getPoint().getZ();
			tempDistance = tempPosSufaceZ - tempPosSurfaceZ_befor;
			tempMatrix_propagation[1][0] = tempDistance;
			AllMatrix.push_back(tempMatrix_propagation);
			//Math::printSystemMatrix2x2(tempMatrix_propagation);

		}




	}

	unsigned int sizeAllMatrix = AllMatrix.size();
	systemMatrix = AllMatrix[0];
	//Math::printSystemMatrix2x2(systemMatrix);

	for (unsigned int i = 1; i < sizeAllMatrix; ++i)
	{
		systemMatrix = Math::multiplyTwoSystemMatrixes2x2(systemMatrix, AllMatrix[i]);
		//Math::printSystemMatrix2x2(systemMatrix);
	}

	return -1 / systemMatrix[0][1];
}


real LensReplace::calculateThickness_Z(OpticalSystem_LLT optSys_LLT)
{
	unsigned sizeOptSys = optSys_LLT.getPosAndInteractingSurface().size();

	real pointFirstSurface_Z;
	real pointLastSurface_Z;
	real thickness;

	pointFirstSurface_Z = optSys_LLT.getPosAndInteractingSurface()[0].getSurfaceInterRay_ptr()->getPoint().getZ();
	pointLastSurface_Z = optSys_LLT.getPosAndInteractingSurface()[sizeOptSys - 1].getSurfaceInterRay_ptr()->getPoint().getZ();

	return pointLastSurface_Z - pointFirstSurface_Z;

}

real LensReplace::calcMaxSemiHeigh(OpticalSystem_LLT optSys_LLT)
{
	unsigned sizeOptSys = optSys_LLT.getPosAndInteractingSurface().size();
	real tempSemiHeight{};
	real saveSemiHeigt = optSys_LLT.getPosAndInteractingSurface()[0].getSurfaceInterRay_ptr()->getSemiHeight();

	for (unsigned int i = 1; i < sizeOptSys; ++i)
	{
		tempSemiHeight = optSys_LLT.getPosAndInteractingSurface()[i].getSurfaceInterRay_ptr()->getSemiHeight();

		if (tempSemiHeight > saveSemiHeigt)
		{
			saveSemiHeigt = tempSemiHeight;
		}
	}

	return saveSemiHeigt;
}





std::vector<parameterLens> LensReplace::calcParameterLenses(std::vector<OpticalSystem_LLT> lensesInOptSys)
{

	unsigned int numLens = lensesInOptSys.size();
	std::vector<parameterLens> returnParameterLens;
	returnParameterLens.resize(numLens);

	OpticalSystem_LLT tempOptSys_LLT_lens;
	real focalLength_temp;
	real minFocalLenght_temp;
	real maxFocalLenght_temp;
	real maxSemiHeight_temp;
	real max_min_semiHeight_temp;
	real max_max_semiHeight_temp;
	real thickness_temp;
	real thickness_max_temp;
	real thickness_min_temp;

	parameterLens parameter_temp;

	real minPercent;
	real maxPercent;
	real tempMinValue{};
	real tempMaxValue{};

	for (unsigned int i = 0; i < numLens; ++i)
	{
		tempOptSys_LLT_lens = lensesInOptSys[i];

		minPercent = mDefaultPara_LensReplace.getMinPercent_surface_i_focalLength(i);
		maxPercent = mDefaultPara_LensReplace.getMaxPercent_surface_i_focalLength(i);

		focalLength_temp = calcFocalLenghtOptSys(tempOptSys_LLT_lens);
		maxSemiHeight_temp = calcMaxSemiHeigh(tempOptSys_LLT_lens);
		thickness_temp = calculateThickness_Z(tempOptSys_LLT_lens);

		// focal length
		minFocalLenght_temp = parameter_temp.calcMinValue(focalLength_temp, minPercent);
		maxFocalLenght_temp = parameter_temp.calcMaxValue(focalLength_temp, maxPercent);
		returnParameterLens[i].setFocalLengthMinMax(focalLength_temp, minFocalLenght_temp, maxFocalLenght_temp);

		// thickness
		thickness_min_temp = parameter_temp.calcMinValue(thickness_temp, minPercent);
		thickness_max_temp = parameter_temp.calcMaxValue(thickness_temp, minPercent);
		returnParameterLens[i].setThicknessMinMax(thickness_temp, thickness_min_temp, thickness_max_temp);

		// semi Height
		max_min_semiHeight_temp = parameter_temp.calcMinValue(maxSemiHeight_temp, minPercent);
		max_max_semiHeight_temp = parameter_temp.calcMaxValue(maxSemiHeight_temp, maxPercent);
		returnParameterLens[i].setSemiHeigthMinMax(maxSemiHeight_temp, max_min_semiHeight_temp, max_max_semiHeight_temp);


	}

	return returnParameterLens;
}

std::vector<parameterLens> LensReplace::getParameterLenses()
{
	return mParameterLenses;
}


std::vector<OptSysEle_Merit_LensType> LensReplace::findOptSysEle_lens_inCatalog_TwoSurfaces(parameterLens paraLens, std::vector<LensesTwoSurfaces> AllLensesTwoSurfaces, real weightFocal, real weightThickness, real weightSemiHeight)
{

	std::vector<OptSysEle_Merit_LensType> returnOptSysEle_Merit_vec{};
	OptSysEle_Merit_LensType tempOptSysEle_Merit{};
	OpticalSystemElement tempOptSysEle{};
	std::string tempCatalog{};
	unsigned int tempCatalogNumer{};

	// focal lenght
	real focaLengthParam = paraLens.getFocalLengthMinMax().getValue();
	real minFocalLengthParam = paraLens.getFocalLengthMinMax().getMin();
	real maxFocalLengthParam = paraLens.getFocalLengthMinMax().getMax();

	// semi height
	real semiHeightParam = paraLens.getSemiHeightMinMax().getValue();
	real minSemiHeightParam = paraLens.getSemiHeightMinMax().getMin();
	real maxSemiHeightParam = paraLens.getSemiHeightMinMax().getMax();

	// thickness
	real thicknessParam = paraLens.getThicknessMinMax().getValue();
	real minThicknessParam = paraLens.getThicknessMinMax().getMin();
	real maxThicknessParam = paraLens.getThicknessMinMax().getMax();

	real focalLenghtCatLens_temp;
	real semiHeightCatLens_temp;
	real thicknessCatLens_temp;


	unsigned int numberLenses = AllLensesTwoSurfaces.size();

	// parameter to save
	real tempMerit;
	bool tempCheckPara_focalLength;
	bool tempCheckPara_thickness;
	bool tempCheckPara_semiHeight;


	returnOptSysEle_Merit_vec.resize(numberLenses);
	for (unsigned int i = 0; i < numberLenses; ++i)
	{
		focalLenghtCatLens_temp = AllLensesTwoSurfaces[i].getFocalLength();
		thicknessCatLens_temp = AllLensesTwoSurfaces[i].getThickness();
		semiHeightCatLens_temp = AllLensesTwoSurfaces[i].getDiameter() / 2.0;


		tempMerit = calcualteMerit_lens(focaLengthParam, thicknessParam, semiHeightParam, focalLenghtCatLens_temp, weightFocal, thicknessCatLens_temp, weightThickness, semiHeightCatLens_temp, weightSemiHeight);
		// check focal length
		tempCheckPara_focalLength = checkValueMinMax(focalLenghtCatLens_temp, minFocalLengthParam, maxFocalLengthParam);
		// check thickness
		tempCheckPara_thickness = checkValueMinMax(thicknessCatLens_temp, minThicknessParam, maxThicknessParam);
		// check semi height
		tempCheckPara_semiHeight = checkValueMinMax(semiHeightCatLens_temp, minSemiHeightParam, maxSemiHeightParam);


		// save lens and parameter in vector
		tempOptSysEle = AllLensesTwoSurfaces[i].getHLT_TwoSurfaces().getDeepCopyOptSysEle();
		tempCatalog = AllLensesTwoSurfaces[i].getLensCatalog();
		tempCatalogNumer = AllLensesTwoSurfaces[i].getCatalogNumber();

		tempOptSysEle_Merit.setOpticalSystemEle(tempOptSysEle);
		tempOptSysEle_Merit.setCatalogNumber(tempCatalogNumer);
		tempOptSysEle_Merit.setLensCatalog(tempCatalog);
		tempOptSysEle_Merit.setMerit(tempMerit);
		tempOptSysEle_Merit.setCheckParameters_focalLength(tempCheckPara_focalLength);
		tempOptSysEle_Merit.setCheckParameters_thickness(tempCheckPara_thickness);
		tempOptSysEle_Merit.setCheckParameters_semiHeight(tempCheckPara_semiHeight);
		tempOptSysEle_Merit.setFlipedBy180Degrees(false);

		if (tempOptSysEle.getPosAndElement().size() == 0)
		{
			tempOptSysEle_Merit.setMerit(oftenUse::getInfReal());
		}

		returnOptSysEle_Merit_vec[i] = tempOptSysEle_Merit;

	}

	return returnOptSysEle_Merit_vec;
}

std::vector<OptSysEle_Merit_LensType>  LensReplace::findOptSysEle_lens_inCatalog_ThreeSurfaces(parameterLens paraLens, std::vector<LensThreeSurfaces> AllLensesThreeSurfaces, real weightFocal, real weightThickness, real weightSemiHeight)
{
	std::vector<OptSysEle_Merit_LensType> returnOptSysEle_Merit_vec{};
	OptSysEle_Merit_LensType tempOptSysEle_Merit{};
	OpticalSystemElement tempOptSysEle{};
	std::string tempLensCatalog{};
	unsigned int tempLensNumber{};

	// focal lenght
	real focaLengthParam = paraLens.getFocalLengthMinMax().getValue();
	real minFocalLengthParam = paraLens.getFocalLengthMinMax().getMin();
	real maxFocalLengthParam = paraLens.getFocalLengthMinMax().getMax();

	// semi height
	real semiHeightParam = paraLens.getSemiHeightMinMax().getValue();
	real minSemiHeightParam = paraLens.getSemiHeightMinMax().getMin();
	real maxSemiHeightParam = paraLens.getSemiHeightMinMax().getMax();

	// thickness
	real thicknessParam = paraLens.getThicknessMinMax().getValue();
	real minThicknessParam = paraLens.getThicknessMinMax().getMin();
	real maxThicknessParam = paraLens.getThicknessMinMax().getMax();

	real focalLenghtCatLens_temp;
	real semiHeightCatLens_temp;
	real thicknessCatLens_temp;


	unsigned int numberLenses = AllLensesThreeSurfaces.size();
	// parameters to save
	real tempMerit;
	bool tempCheckPara_focalLength;
	bool tempCheckPara_thickness;
	bool tempCheckPara_semiHeight;


	returnOptSysEle_Merit_vec.resize(numberLenses);
	for (unsigned int i = 0; i < numberLenses; ++i)
	{
		focalLenghtCatLens_temp = AllLensesThreeSurfaces[i].getFocalLength();
		thicknessCatLens_temp = AllLensesThreeSurfaces[i].getFirstThickness() + AllLensesThreeSurfaces[i].getSecondThickness();
		semiHeightCatLens_temp = AllLensesThreeSurfaces[i].getDiameter() / 2.0;

		tempMerit = calcualteMerit_lens(focaLengthParam, thicknessParam, semiHeightParam, focalLenghtCatLens_temp, weightFocal, thicknessCatLens_temp, weightThickness, semiHeightCatLens_temp, weightSemiHeight);
		// check focal length
		tempCheckPara_focalLength = checkValueMinMax(focalLenghtCatLens_temp, minFocalLengthParam, maxFocalLengthParam);
		// check thickness
		tempCheckPara_thickness = checkValueMinMax(thicknessCatLens_temp, minThicknessParam, maxThicknessParam);
		// check semi height
		tempCheckPara_semiHeight = checkValueMinMax(semiHeightCatLens_temp, minSemiHeightParam, maxSemiHeightParam);

		tempOptSysEle = AllLensesThreeSurfaces[i].getHLT_ThreeSurfaces().getDeepCopyOptSysEle();
		tempLensCatalog = AllLensesThreeSurfaces[i].getLensCatalog();
		tempLensNumber = AllLensesThreeSurfaces[i].getCatalogNumber();

		tempOptSysEle_Merit.setOpticalSystemEle(tempOptSysEle);
		tempOptSysEle_Merit.setLensCatalog(tempLensCatalog);
		tempOptSysEle_Merit.setCatalogNumber(tempLensNumber);
		tempOptSysEle_Merit.setMerit(tempMerit);
		tempOptSysEle_Merit.setCheckParameters_focalLength(tempCheckPara_focalLength);
		tempOptSysEle_Merit.setCheckParameters_thickness(tempCheckPara_thickness);
		tempOptSysEle_Merit.setCheckParameters_semiHeight(tempCheckPara_semiHeight);
		tempOptSysEle_Merit.setFlipedBy180Degrees(false);

		if (tempOptSysEle.getPosAndElement().size() == 0)
		{
			tempOptSysEle_Merit.setMerit(oftenUse::getInfReal());
		}

		returnOptSysEle_Merit_vec[i] = tempOptSysEle_Merit;
	}




	return returnOptSysEle_Merit_vec;
}

std::vector<OptSysEle_Merit_LensType>  LensReplace::findOptSysEle_lens_inCatalog_FourSurfaces(parameterLens paraLens, std::vector<LensFourSurfaces> AllLensesFourSurfaces, real weightFocal, real weightThickness, real weightSemiHeight)
{
	std::vector<OptSysEle_Merit_LensType> returnOptSysEle_Merit_vec{};
	OptSysEle_Merit_LensType tempOptSysEle_Merit{};
	OpticalSystemElement tempOptSysEle{};
	std::string tempLensCatalog{};
	unsigned int tempLensNumber{};

	// focal lenght
	real focaLengthParam = paraLens.getFocalLengthMinMax().getValue();
	real minFocalLengthParam = paraLens.getFocalLengthMinMax().getMin();
	real maxFocalLengthParam = paraLens.getFocalLengthMinMax().getMax();

	// semi height
	real semiHeightParam = paraLens.getSemiHeightMinMax().getValue();
	real minSemiHeightParam = paraLens.getSemiHeightMinMax().getMin();
	real maxSemiHeightParam = paraLens.getSemiHeightMinMax().getMax();

	// thickness
	real thicknessParam = paraLens.getThicknessMinMax().getValue();
	real minThicknessParam = paraLens.getThicknessMinMax().getMin();
	real maxThicknessParam = paraLens.getThicknessMinMax().getMax();

	real focalLenghtCatLens_temp;
	real semiHeightCatLens_temp;
	real thicknessCatLens_temp;


	unsigned int numberLenses = AllLensesFourSurfaces.size();
	// parameters to save
	real tempMerit;
	bool tempCheckPara_focalLength;
	bool tempCheckPara_thickness;
	bool tempCheckPara_semiHeight;


	returnOptSysEle_Merit_vec.resize(numberLenses);
	for (unsigned int i = 0; i < numberLenses; ++i)
	{
		focalLenghtCatLens_temp = AllLensesFourSurfaces[i].getFocalLength();
		thicknessCatLens_temp = AllLensesFourSurfaces[i].getFirstThickness() + AllLensesFourSurfaces[i].getSecondThickness() + AllLensesFourSurfaces[i].getThirdThickness();
		semiHeightCatLens_temp = AllLensesFourSurfaces[i].getDiameter() / 2.0;

		tempMerit = calcualteMerit_lens(focaLengthParam, thicknessParam, semiHeightParam, focalLenghtCatLens_temp, weightFocal, thicknessCatLens_temp, weightThickness, semiHeightCatLens_temp, weightSemiHeight);
		// check focal length
		tempCheckPara_focalLength = checkValueMinMax(focalLenghtCatLens_temp, minFocalLengthParam, maxFocalLengthParam);
		// check thickness
		tempCheckPara_thickness = checkValueMinMax(thicknessCatLens_temp, minThicknessParam, maxThicknessParam);
		// check semi height
		tempCheckPara_semiHeight = checkValueMinMax(semiHeightCatLens_temp, minSemiHeightParam, maxSemiHeightParam);

		tempOptSysEle = AllLensesFourSurfaces[i].getHLT_FourSurfaces().getDeepCopyOptSysEle();
		tempLensCatalog = AllLensesFourSurfaces[i].getLensCatalog();
		tempLensNumber = AllLensesFourSurfaces[i].getCatalogNumber();

		tempOptSysEle_Merit.setOpticalSystemEle(tempOptSysEle);
		tempOptSysEle_Merit.setLensCatalog(tempLensCatalog);
		tempOptSysEle_Merit.setCatalogNumber(tempLensNumber);
		tempOptSysEle_Merit.setMerit(tempMerit);
		tempOptSysEle_Merit.setCheckParameters_focalLength(tempCheckPara_focalLength);
		tempOptSysEle_Merit.setCheckParameters_thickness(tempCheckPara_thickness);
		tempOptSysEle_Merit.setCheckParameters_semiHeight(tempCheckPara_semiHeight);
		tempOptSysEle_Merit.setFlipedBy180Degrees(false);

		if (tempOptSysEle.getPosAndElement().size() == 0)
		{
			tempOptSysEle_Merit.setMerit(oftenUse::getInfReal());
		}

		returnOptSysEle_Merit_vec[i] = tempOptSysEle_Merit;
	}

	return returnOptSysEle_Merit_vec;
}

real LensReplace::calcualteMerit(real target, real is, real weight)
{
	return 1.0/weight * std::abs((target - is) / target);
}



real LensReplace::calcualteMerit_lens(real focalParam, real thicknessParam, real semiHeightParam, real focalTemp, real focalWeight, real thicknessTemp, real thicknessWeight, real semiHeightTemp, real semiHeightWeight)
{
	real veryHeighNumber = oftenUse::getInfReal();

	real returnMeritLens;
	real meritFocalLenght;
	real meritThickness;
	real meritSeminHeight;

	meritFocalLenght = calcualteMerit(focalParam, focalTemp, focalWeight);
	meritThickness = calcualteMerit(thicknessParam, thicknessTemp, thicknessWeight);
	meritSeminHeight = calcualteMerit(semiHeightParam, semiHeightTemp, semiHeightWeight);

	returnMeritLens = meritFocalLenght + meritThickness + meritSeminHeight;

	return returnMeritLens;
}

OptSysEle_Merit_LensType LensReplace::checkLensCatalogsForBestFitLens(/*number lens*/ unsigned int lensNo,/*parameter lens*/ parameterLens paraLens)
{
	real veryHeighNumber = oftenUse::getInfReal();
	std::vector<OptSysEle_Merit_LensType> OptSysEleMerit_LensType_vec;

	std::vector<OptSysEle_Merit_LensType> DConvexL_opt_merit_type_vec;
	std::vector<OptSysEle_Merit_LensType> PosAchromat_opt_merit_type_vec;
	std::vector<OptSysEle_Merit_LensType> PConvexL_opt_merit_type_vec;
	std::vector<OptSysEle_Merit_LensType> DConcavL_opt_merit_type_vec;
	std::vector<OptSysEle_Merit_LensType> PConcavL_opt_merit_type_vec;


	real weightFocal = mDefaultPara_LensReplace.getWeightFocalLengthSurface_i(lensNo);
	real weightThickness = mDefaultPara_LensReplace.getWeightThicknessSurface_i(lensNo);
	real weightSemiHeight = mDefaultPara_LensReplace.getWeightSemiHeightSurface_i(lensNo);

	lensTypes prefLensType = mDefaultPara_LensReplace.getPrefLensTyeAndFactorSurface_i(lensNo).getPrefLensType();
	real prefFactor = mDefaultPara_LensReplace.getPrefLensTyeAndFactorSurface_i(lensNo).getFactor();

	//DConvexL
	bool load_DConvexL = findCatalog(mLoadLensCatalogEO, lensTypes::EO_DoubleConvex_VIS_NIR);
	if (load_DConvexL)
	{
		DConvexL_opt_merit_type_vec = findOptSysEle_lens_inCatalog_TwoSurfaces(paraLens, mAll_EO_DoubleConvex_VIS_NIR, weightFocal, weightThickness, weightSemiHeight);

		for (unsigned int i = 0; i < DConvexL_opt_merit_type_vec.size(); ++i)
		{
			DConvexL_opt_merit_type_vec[i].setLensType(lensTypes::EO_DoubleConvex_VIS_NIR);
		}

		if (prefLensType == lensTypes::EO_DoubleConvex_VIS_NIR)
		{
			for (unsigned int i = 0; i < DConvexL_opt_merit_type_vec.size(); ++i)
			{
				DConvexL_opt_merit_type_vec[i].setMerit(DConvexL_opt_merit_type_vec[i].getMerit() / prefFactor);
			}
		}

		OptSysEleMerit_LensType_vec.insert(OptSysEleMerit_LensType_vec.end(), DConvexL_opt_merit_type_vec.begin(), DConvexL_opt_merit_type_vec.end());
	}
	//posAchromat
	bool load_posAchromat = findCatalog(mLoadLensCatalogEO, lensTypes::EO_PosAchromat_MgF_Coated);

	if (load_posAchromat)
	{
		PosAchromat_opt_merit_type_vec = findOptSysEle_lens_inCatalog_ThreeSurfaces(paraLens, mAll_EO_PosAchromat_MgF_Coated, weightFocal, weightThickness, weightSemiHeight);

		for (unsigned int i = 0; i < PosAchromat_opt_merit_type_vec.size(); ++i)
		{
			PosAchromat_opt_merit_type_vec[i].setLensType(lensTypes::EO_PosAchromat_MgF_Coated);
		}

		if (prefLensType == lensTypes::EO_PosAchromat_MgF_Coated)
		{
			for (unsigned int i = 0; i < PosAchromat_opt_merit_type_vec.size(); ++i)
			{
				PosAchromat_opt_merit_type_vec[i].setMerit(PosAchromat_opt_merit_type_vec[i].getMerit() / prefFactor);
			}
		}

		OptSysEleMerit_LensType_vec.insert(OptSysEleMerit_LensType_vec.end(), PosAchromat_opt_merit_type_vec.begin(), PosAchromat_opt_merit_type_vec.end());
	}
	//PConvexL
	bool load_PConvexL = findCatalog(mLoadLensCatalogEO, lensTypes::EO_PlanConvex_VIS_NIR);
	if (load_PConvexL)
	{
		PConvexL_opt_merit_type_vec = findOptSysEle_lens_inCatalog_TwoSurfaces(paraLens, mAll_EO_PlanConvex_VIS_NIR, weightFocal, weightThickness, weightSemiHeight);

		for (unsigned int i = 0; i < PConvexL_opt_merit_type_vec.size(); ++i)
		{
			PConvexL_opt_merit_type_vec[i].setLensType(lensTypes::EO_PlanConvex_VIS_NIR);
		}

		if (prefLensType == lensTypes::EO_PlanConvex_VIS_NIR)
		{
			for (unsigned int i = 0; i < PConvexL_opt_merit_type_vec.size(); ++i)
			{
				PConvexL_opt_merit_type_vec[i].setMerit(PConvexL_opt_merit_type_vec[i].getMerit() / prefFactor);
			}

		}

		OptSysEleMerit_LensType_vec.insert(OptSysEleMerit_LensType_vec.end(), PConvexL_opt_merit_type_vec.begin(), PConvexL_opt_merit_type_vec.end());
	}
	//DConcavL
	bool load_DConcavL = findCatalog(mLoadLensCatalogEO, lensTypes::EO_DoubleConcav_VIS_NIR);
	if (load_DConcavL)
	{
		DConcavL_opt_merit_type_vec = findOptSysEle_lens_inCatalog_TwoSurfaces(paraLens, mAll_EO_DoubleConcav_VIS_NIR, weightFocal, weightThickness, weightSemiHeight);
		for (unsigned int i = 0; i < DConcavL_opt_merit_type_vec.size(); ++i)
		{
			DConcavL_opt_merit_type_vec[i].setLensType(lensTypes::EO_DoubleConcav_VIS_NIR);
		}

		if (prefLensType == lensTypes::EO_DoubleConcav_VIS_NIR)
		{
			for (unsigned int i = 0; i < DConcavL_opt_merit_type_vec.size(); ++i)
			{
				DConcavL_opt_merit_type_vec[i].setMerit(DConcavL_opt_merit_type_vec[i].getMerit() / prefFactor);
			}

		}

		OptSysEleMerit_LensType_vec.insert(OptSysEleMerit_LensType_vec.end(), DConcavL_opt_merit_type_vec.begin(), DConcavL_opt_merit_type_vec.end());
	}
	//PConcavL
	bool load_PConcavL = findCatalog(mLoadLensCatalogEO, lensTypes::EO_PlanConcav_VIS_NIR);
	if (load_PConcavL)
	{
		PConcavL_opt_merit_type_vec = findOptSysEle_lens_inCatalog_TwoSurfaces(paraLens, mAll_EO_PlanConcav_VIS_NIR, weightFocal, weightThickness, weightSemiHeight);
		for (unsigned int i = 0; i < PConcavL_opt_merit_type_vec.size(); ++i)
		{
			PConcavL_opt_merit_type_vec[i].setLensType(lensTypes::EO_PlanConcav_VIS_NIR);
		}
		if (prefLensType == lensTypes::EO_DoubleConcav_VIS_NIR)
		{
			for (unsigned int i = 0; i < PConcavL_opt_merit_type_vec.size(); ++i)
			{
				PConcavL_opt_merit_type_vec[i].setMerit(PConcavL_opt_merit_type_vec[i].getMerit() / prefFactor);
			}
		}
		OptSysEleMerit_LensType_vec.insert(OptSysEleMerit_LensType_vec.end(), PConcavL_opt_merit_type_vec.begin(), PConcavL_opt_merit_type_vec.end());
	}

	// find best optical system
	real tempMeritValue = oftenUse::getInfReal();
	real bestMeritValue = oftenUse::getInfReal();
	unsigned posBestMeritVal;
	for (unsigned int i = 0; i < OptSysEleMerit_LensType_vec.size(); ++i)
	{
		tempMeritValue = OptSysEleMerit_LensType_vec[i].getMerit();

		if (bestMeritValue > tempMeritValue)
		{
			bestMeritValue = tempMeritValue;
			posBestMeritVal = i;
		}
	}


	return  OptSysEleMerit_LensType_vec[posBestMeritVal];
}

std::vector<OptSysEle_Merit_LensType> LensReplace::checkLensCatalogsForBestFitLenses_many(/*lens number*/ unsigned int lensNo, /*parameter lens*/ parameterLens paraLens, /*number best fit lenses*/ unsigned int numberLenses)
{
	real veryHeighNumber = oftenUse::getInfReal();
	std::vector<OptSysEle_Merit_LensType> OptSysEleMerit_LensType_vec;

	/*edmund optic*/
	std::vector<OptSysEle_Merit_LensType> EO_DoubleConvex_VIS_NIR_vec;
	std::vector<OptSysEle_Merit_LensType> EO_PosAchromat_MgF_Coated_vec;
	std::vector<OptSysEle_Merit_LensType> EO_PlanConvex_VIS_NIR_vec;
	std::vector<OptSysEle_Merit_LensType> EO_DoubleConcav_VIS_NIR_vec;
	std::vector<OptSysEle_Merit_LensType> EO_PlanConcav_VIS_NIR_vec;
	std::vector<OptSysEle_Merit_LensType> EO_DoubleConcav_NIR_I_vec;
	std::vector<OptSysEle_Merit_LensType> EO_PosAchromat_VIS_NIR_vec;
	std::vector<OptSysEle_Merit_LensType> EO_NegAchromat_Broadband_AR_Coated_vec;
	std::vector<OptSysEle_Merit_LensType> EO_LargePrecisionAchromat_NoAirSpace_vec;
	std::vector<OptSysEle_Merit_LensType> EO_LargePrecisionAchromat_AirSpace_vec;
	std::vector<OptSysEle_Merit_LensType> EO_HastingsTripletAchromat_vec;
	std::vector<OptSysEle_Merit_LensType> EO_SteinheilTripletAchromat_vec;
	std::vector<OptSysEle_Merit_LensType> EO_MicroPlanConvex_vec;
	std::vector<OptSysEle_Merit_LensType> EO_LargePlanConvexCondensor_vec;
	/*thorlabs*/
	std::vector<OptSysEle_Merit_LensType> Th_AchromatDoublets_AR_Coated_vec;
	std::vector<OptSysEle_Merit_LensType> Th_NBK7_PlanConvex_AR_Coated_400_1100_vec;
	std::vector<OptSysEle_Merit_LensType> Th_NBK7_BiConvex_AR_Coated_350_700_vec;
	std::vector<OptSysEle_Merit_LensType> Th_NBK7_PlanConcav_AR_Coated_350_700_vec;
	std::vector<OptSysEle_Merit_LensType> Th_NBK7_NSF11_BiConcav_AR_Coated_350_700_vec;
	std::vector<OptSysEle_Merit_LensType> Th_NBK7_BestFormSpherical_AR_Coated_350_700_vec;
	std::vector<OptSysEle_Merit_LensType> Th_NBK7_PosMeniscus_Uncoated_vec;
	std::vector<OptSysEle_Merit_LensType> Th_NBK7_NegMeniscus_Uncoated_vec;
	std::vector<OptSysEle_Merit_LensType> Th_SteinheilTripletAchromat_Visible_vec;
	std::vector<OptSysEle_Merit_LensType> Th_HastingsTripletAchromatVisible_vec;
	/*Qioptiq*/
	std::vector<OptSysEle_Merit_LensType> Qi_PlanConvex_ARB2_VIS_vec;
	std::vector<OptSysEle_Merit_LensType> Qi_SymmetricConvex_ARB2_VIS_vec;
	std::vector<OptSysEle_Merit_LensType> Qi_PlanConcav_ARB2_VIS_vec;
	std::vector<OptSysEle_Merit_LensType> Qi_SymmetricConcav_ARB2_VIS_vec;
	std::vector<OptSysEle_Merit_LensType> Qi_PosAchromat_VIS_3_31_ARB2_VIS_vec;
	std::vector<OptSysEle_Merit_LensType> Qi_PosAchromat_VIS_31_40_ARB2_VIS_vec;
	std::vector<OptSysEle_Merit_LensType> Qi_NegAchromat_ARB2_VIS_vec;


	real weightFocal = mDefaultPara_LensReplace.getWeightFocalLengthSurface_i(lensNo);
	real weightThickness = mDefaultPara_LensReplace.getWeightThicknessSurface_i(lensNo);
	real weightSemiHeight = mDefaultPara_LensReplace.getWeightSemiHeightSurface_i(lensNo);

	lensTypes prefLensType = mDefaultPara_LensReplace.getPrefLensTyeAndFactorSurface_i(lensNo).getPrefLensType();
	real prefFactor = mDefaultPara_LensReplace.getPrefLensTyeAndFactorSurface_i(lensNo).getFactor();

	/*EdmundOptics*/

	//EO_DoubleConvex_VIS_NIR
	bool load_EO_DoubleConvex_VIS_NIR = findCatalog(mLoadLensCatalogEO, lensTypes::EO_DoubleConvex_VIS_NIR);
	if (load_EO_DoubleConvex_VIS_NIR)
	{
		EO_DoubleConvex_VIS_NIR_vec = findOptSysEle_lens_inCatalog_TwoSurfaces(paraLens, mAll_EO_DoubleConvex_VIS_NIR, weightFocal, weightThickness, weightSemiHeight);

		for (unsigned int i = 0; i < EO_DoubleConvex_VIS_NIR_vec.size(); ++i)
		{
			EO_DoubleConvex_VIS_NIR_vec[i].setLensType(lensTypes::EO_DoubleConvex_VIS_NIR);
		}

		if (prefLensType == lensTypes::EO_DoubleConvex_VIS_NIR)
		{
			for (unsigned int i = 0; i < EO_DoubleConvex_VIS_NIR_vec.size(); ++i)
			{
				EO_DoubleConvex_VIS_NIR_vec[i].setMerit(EO_DoubleConvex_VIS_NIR_vec[i].getMerit() / prefFactor);
			}
		}

		OptSysEleMerit_LensType_vec.insert(OptSysEleMerit_LensType_vec.end(), EO_DoubleConvex_VIS_NIR_vec.begin(), EO_DoubleConvex_VIS_NIR_vec.end());
	}
	//EO_PosAchromat_MgF_Coated
	bool load_EO_PosAchromat_MgF_Coated = findCatalog(mLoadLensCatalogEO, lensTypes::EO_PosAchromat_MgF_Coated);

	if (load_EO_PosAchromat_MgF_Coated)
	{
		EO_PosAchromat_MgF_Coated_vec = findOptSysEle_lens_inCatalog_ThreeSurfaces(paraLens, mAll_EO_PosAchromat_MgF_Coated, weightFocal, weightThickness, weightSemiHeight);

		for (unsigned int i = 0; i < EO_PosAchromat_MgF_Coated_vec.size(); ++i)
		{
			EO_PosAchromat_MgF_Coated_vec[i].setLensType(lensTypes::EO_PosAchromat_MgF_Coated);
		}

		if (prefLensType == lensTypes::EO_PosAchromat_MgF_Coated)
		{
			for (unsigned int i = 0; i < EO_PosAchromat_MgF_Coated_vec.size(); ++i)
			{
				EO_PosAchromat_MgF_Coated_vec[i].setMerit(EO_PosAchromat_MgF_Coated_vec[i].getMerit() / prefFactor);
			}
		}

		OptSysEleMerit_LensType_vec.insert(OptSysEleMerit_LensType_vec.end(), EO_PosAchromat_MgF_Coated_vec.begin(), EO_PosAchromat_MgF_Coated_vec.end());
	}
	//EO_PlanConvex_VIS_NIR
	bool load_EO_PlanConvex_VIS_NIR = findCatalog(mLoadLensCatalogEO, lensTypes::EO_PlanConvex_VIS_NIR);
	if (load_EO_PlanConvex_VIS_NIR)
	{
		EO_PlanConvex_VIS_NIR_vec = findOptSysEle_lens_inCatalog_TwoSurfaces(paraLens, mAll_EO_PlanConvex_VIS_NIR, weightFocal, weightThickness, weightSemiHeight);

		for (unsigned int i = 0; i < EO_PlanConvex_VIS_NIR_vec.size(); ++i)
		{
			EO_PlanConvex_VIS_NIR_vec[i].setLensType(lensTypes::EO_PlanConvex_VIS_NIR);
		}

		if (prefLensType == lensTypes::EO_PlanConvex_VIS_NIR)
		{
			for (unsigned int i = 0; i < EO_PlanConvex_VIS_NIR_vec.size(); ++i)
			{
				EO_PlanConvex_VIS_NIR_vec[i].setMerit(EO_PlanConvex_VIS_NIR_vec[i].getMerit() / prefFactor);
			}

		}

		OptSysEleMerit_LensType_vec.insert(OptSysEleMerit_LensType_vec.end(), EO_PlanConvex_VIS_NIR_vec.begin(), EO_PlanConvex_VIS_NIR_vec.end());
	}

	//EO_DoubleConcav_VIS_NIR
	bool load_EO_DoubleConcav_VIS_NIR = findCatalog(mLoadLensCatalogEO, lensTypes::EO_DoubleConcav_VIS_NIR);
	if (load_EO_DoubleConcav_VIS_NIR)
	{
		EO_DoubleConcav_VIS_NIR_vec = findOptSysEle_lens_inCatalog_TwoSurfaces(paraLens, mAll_EO_DoubleConcav_VIS_NIR, weightFocal, weightThickness, weightSemiHeight);
		for (unsigned int i = 0; i < EO_DoubleConcav_VIS_NIR_vec.size(); ++i)
		{
			EO_DoubleConcav_VIS_NIR_vec[i].setLensType(lensTypes::EO_DoubleConcav_VIS_NIR);
		}

		if (prefLensType == lensTypes::EO_DoubleConcav_VIS_NIR)
		{
			for (unsigned int i = 0; i < EO_DoubleConcav_VIS_NIR_vec.size(); ++i)
			{
				EO_DoubleConcav_VIS_NIR_vec[i].setMerit(EO_DoubleConcav_VIS_NIR_vec[i].getMerit() / prefFactor);
			}

		}

		OptSysEleMerit_LensType_vec.insert(OptSysEleMerit_LensType_vec.end(), EO_DoubleConcav_VIS_NIR_vec.begin(), EO_DoubleConcav_VIS_NIR_vec.end());
	}

	//EO_PlanConcav_VIS_NIR
	bool load_EO_PlanConcav_VIS_NIR = findCatalog(mLoadLensCatalogEO, lensTypes::EO_PlanConcav_VIS_NIR);
	if (load_EO_PlanConcav_VIS_NIR)
	{
		EO_PlanConcav_VIS_NIR_vec = findOptSysEle_lens_inCatalog_TwoSurfaces(paraLens, mAll_EO_PlanConcav_VIS_NIR, weightFocal, weightThickness, weightSemiHeight);
		for (unsigned int i = 0; i < EO_PlanConcav_VIS_NIR_vec.size(); ++i)
		{
			EO_PlanConcav_VIS_NIR_vec[i].setLensType(lensTypes::EO_PlanConcav_VIS_NIR);
		}
		if (prefLensType == lensTypes::EO_DoubleConcav_VIS_NIR)
		{
			for (unsigned int i = 0; i < EO_PlanConcav_VIS_NIR_vec.size(); ++i)
			{
				EO_PlanConcav_VIS_NIR_vec[i].setMerit(EO_PlanConcav_VIS_NIR_vec[i].getMerit() / prefFactor);
			}
		}
		OptSysEleMerit_LensType_vec.insert(OptSysEleMerit_LensType_vec.end(), EO_PlanConcav_VIS_NIR_vec.begin(), EO_PlanConcav_VIS_NIR_vec.end());
	}

	//EO_DoubleConcav_NIR_I
	bool load_EO_DoubleConcav_NIR_I = findCatalog(mLoadLensCatalogEO, lensTypes::EO_DoubleConcav_NIR_I);
	if (load_EO_DoubleConcav_NIR_I)
	{
		EO_DoubleConcav_NIR_I_vec = findOptSysEle_lens_inCatalog_TwoSurfaces(paraLens, mAll_EO_DoubleConcav_VIS_NIR, weightFocal, weightThickness, weightSemiHeight);
		for (unsigned int i = 0; i < EO_DoubleConcav_NIR_I_vec.size(); ++i)
		{
			EO_DoubleConcav_NIR_I_vec[i].setLensType(lensTypes::EO_DoubleConcav_NIR_I);
		}
		if (prefLensType == lensTypes::EO_DoubleConcav_NIR_I)
		{
			for (unsigned int i = 0; i < EO_DoubleConcav_NIR_I_vec.size(); ++i)
			{
				EO_DoubleConcav_NIR_I_vec[i].setMerit(EO_DoubleConcav_NIR_I_vec[i].getMerit() / prefFactor);
			}
		}
		OptSysEleMerit_LensType_vec.insert(OptSysEleMerit_LensType_vec.end(), EO_DoubleConcav_NIR_I_vec.begin(), EO_DoubleConcav_NIR_I_vec.end());
	}

	//EO_PosAchromat_VIS_NIR
	bool load_EO_PosAchromat_VIS_NIR = findCatalog(mLoadLensCatalogEO, lensTypes::EO_PosAchromat_VIS_NIR);
	if (load_EO_PosAchromat_VIS_NIR)
	{
		EO_PosAchromat_VIS_NIR_vec = findOptSysEle_lens_inCatalog_ThreeSurfaces(paraLens, mAll_EO_PosAchromat_VIS_NIR, weightFocal, weightThickness, weightSemiHeight);
		for (unsigned int i = 0; i < EO_PosAchromat_VIS_NIR_vec.size(); ++i)
		{
			EO_PosAchromat_VIS_NIR_vec[i].setLensType(lensTypes::EO_PosAchromat_VIS_NIR);
		}
		if (prefLensType == lensTypes::EO_PosAchromat_VIS_NIR)
		{
			for (unsigned int i = 0; i < EO_PosAchromat_VIS_NIR_vec.size(); ++i)
			{
				EO_PosAchromat_VIS_NIR_vec[i].setMerit(EO_PosAchromat_VIS_NIR_vec[i].getMerit() / prefFactor);
			}
		}
		OptSysEleMerit_LensType_vec.insert(OptSysEleMerit_LensType_vec.end(), EO_PosAchromat_VIS_NIR_vec.begin(), EO_PosAchromat_VIS_NIR_vec.end());
	}

	//EO_NegAchromat_Broadband_AR_Coated
	bool load_EO_NegAchromat_Broadband_AR_Coated = findCatalog(mLoadLensCatalogEO, lensTypes::EO_NegAchromat_Broadband_AR_Coated);
	if (load_EO_NegAchromat_Broadband_AR_Coated)
	{
		EO_NegAchromat_Broadband_AR_Coated_vec = findOptSysEle_lens_inCatalog_ThreeSurfaces(paraLens, mAll_EO_NegAchromat_Broadband_AR_Coated, weightFocal, weightThickness, weightSemiHeight);
		for (unsigned int i = 0; i < EO_NegAchromat_Broadband_AR_Coated_vec.size(); ++i)
		{
			EO_NegAchromat_Broadband_AR_Coated_vec[i].setLensType(lensTypes::EO_NegAchromat_Broadband_AR_Coated);
		}
		if (prefLensType == lensTypes::EO_NegAchromat_Broadband_AR_Coated)
		{
			for (unsigned int i = 0; i < EO_NegAchromat_Broadband_AR_Coated_vec.size(); ++i)
			{
				EO_NegAchromat_Broadband_AR_Coated_vec[i].setMerit(EO_NegAchromat_Broadband_AR_Coated_vec[i].getMerit() / prefFactor);
			}
		}
		OptSysEleMerit_LensType_vec.insert(OptSysEleMerit_LensType_vec.end(), EO_NegAchromat_Broadband_AR_Coated_vec.begin(), EO_NegAchromat_Broadband_AR_Coated_vec.end());
	}

	//EO_LargePrecisionAchromat_NoAirSpace
	bool load_EO_LargePrecisionAchromat_NoAirSpace = findCatalog(mLoadLensCatalogEO, lensTypes::EO_LargePrecisionAchromat_NoAirSpace);
	if (load_EO_LargePrecisionAchromat_NoAirSpace)
	{
		EO_LargePrecisionAchromat_NoAirSpace_vec = findOptSysEle_lens_inCatalog_ThreeSurfaces(paraLens, mAll_EO_LargePrecisionAchromat_NoAirSpace, weightFocal, weightThickness, weightSemiHeight);
		for (unsigned int i = 0; i < EO_LargePrecisionAchromat_NoAirSpace_vec.size(); ++i)
		{
			EO_LargePrecisionAchromat_NoAirSpace_vec[i].setLensType(lensTypes::EO_LargePrecisionAchromat_NoAirSpace);
		}
		if (prefLensType == lensTypes::EO_LargePrecisionAchromat_NoAirSpace)
		{
			for (unsigned int i = 0; i < EO_LargePrecisionAchromat_NoAirSpace_vec.size(); ++i)
			{
				EO_LargePrecisionAchromat_NoAirSpace_vec[i].setMerit(EO_LargePrecisionAchromat_NoAirSpace_vec[i].getMerit() / prefFactor);
			}
		}
		OptSysEleMerit_LensType_vec.insert(OptSysEleMerit_LensType_vec.end(), EO_LargePrecisionAchromat_NoAirSpace_vec.begin(), EO_LargePrecisionAchromat_NoAirSpace_vec.end());
	}

	//EO_LargePrecisionAchromat_AirSpace
	bool load_EO_LargePrecisionAchromat_AirSpace = findCatalog(mLoadLensCatalogEO, lensTypes::EO_LargePrecisionAchromat_AirSpace);
	if (load_EO_LargePrecisionAchromat_AirSpace)
	{
		EO_LargePrecisionAchromat_AirSpace_vec = findOptSysEle_lens_inCatalog_FourSurfaces(paraLens, mAll_EO_LargePrecisionAchromat_AirSpace, weightFocal, weightThickness, weightSemiHeight);
		for (unsigned int i = 0; i < EO_LargePrecisionAchromat_AirSpace_vec.size(); ++i)
		{
			EO_LargePrecisionAchromat_AirSpace_vec[i].setLensType(lensTypes::EO_LargePrecisionAchromat_AirSpace);
		}
		if (prefLensType == lensTypes::EO_LargePrecisionAchromat_AirSpace)
		{
			for (unsigned int i = 0; i < EO_LargePrecisionAchromat_AirSpace_vec.size(); ++i)
			{
				EO_LargePrecisionAchromat_AirSpace_vec[i].setMerit(EO_LargePrecisionAchromat_AirSpace_vec[i].getMerit() / prefFactor);
			}
		}
		OptSysEleMerit_LensType_vec.insert(OptSysEleMerit_LensType_vec.end(), EO_LargePrecisionAchromat_AirSpace_vec.begin(), EO_LargePrecisionAchromat_AirSpace_vec.end());
	}

	//EO_HastingsTripletAchromate
	bool load_EO_HastingsTripletAchromat = findCatalog(mLoadLensCatalogEO, lensTypes::EO_HastingsTripletAchromat); 
	if (load_EO_HastingsTripletAchromat)
	{
		EO_HastingsTripletAchromat_vec = findOptSysEle_lens_inCatalog_FourSurfaces(paraLens, mAll_EO_HastingsTripletAchromat, weightFocal, weightThickness, weightSemiHeight);
		for (unsigned int i = 0; i < EO_HastingsTripletAchromat_vec.size(); ++i)
		{
			EO_HastingsTripletAchromat_vec[i].setLensType(lensTypes::EO_HastingsTripletAchromat);
		}
		if (prefLensType == lensTypes::EO_HastingsTripletAchromat)
		{
			for (unsigned int i = 0; i < EO_HastingsTripletAchromat_vec.size(); ++i)
			{
				EO_HastingsTripletAchromat_vec[i].setMerit(EO_HastingsTripletAchromat_vec[i].getMerit() / prefFactor);
			}
		}
		OptSysEleMerit_LensType_vec.insert(OptSysEleMerit_LensType_vec.end(), EO_HastingsTripletAchromat_vec.begin(), EO_HastingsTripletAchromat_vec.end());
	}

	//EO_SteinheilTripletAchromat
	bool load_EO_SteinheilTripletAchromat = findCatalog(mLoadLensCatalogEO, lensTypes::EO_SteinheilTripletAchromat);
	if (load_EO_SteinheilTripletAchromat)
	{
		EO_SteinheilTripletAchromat_vec = findOptSysEle_lens_inCatalog_FourSurfaces(paraLens, mAll_EO_SteinheilTripletAchromat, weightFocal, weightThickness, weightSemiHeight);
		for (unsigned int i = 0; i < EO_SteinheilTripletAchromat_vec.size(); ++i)
		{
			EO_SteinheilTripletAchromat_vec[i].setLensType(lensTypes::EO_SteinheilTripletAchromat);
		}
		if (prefLensType == lensTypes::EO_SteinheilTripletAchromat)
		{
			for (unsigned int i = 0; i < EO_SteinheilTripletAchromat_vec.size(); ++i)
			{
				EO_SteinheilTripletAchromat_vec[i].setMerit(EO_SteinheilTripletAchromat_vec[i].getMerit() / prefFactor);
			}
		}
		OptSysEleMerit_LensType_vec.insert(OptSysEleMerit_LensType_vec.end(), EO_SteinheilTripletAchromat_vec.begin(), EO_SteinheilTripletAchromat_vec.end());
	}

	//EO_MicroPlanConvex
	bool load_EO_MicroPlanConvex = findCatalog(mLoadLensCatalogEO, lensTypes::EO_MicroPlanConvex);
	if (load_EO_MicroPlanConvex)
	{
		EO_MicroPlanConvex_vec = findOptSysEle_lens_inCatalog_TwoSurfaces(paraLens, mAll_EO_MicroPlanConvex, weightFocal, weightThickness, weightSemiHeight);
		for (unsigned int i = 0; i < EO_MicroPlanConvex_vec.size(); ++i)
		{
			EO_MicroPlanConvex_vec[i].setLensType(lensTypes::EO_MicroPlanConvex);
		}
		if (prefLensType == lensTypes::EO_MicroPlanConvex)
		{
			for (unsigned int i = 0; i < EO_MicroPlanConvex_vec.size(); ++i)
			{
				EO_MicroPlanConvex_vec[i].setMerit(EO_MicroPlanConvex_vec[i].getMerit() / prefFactor);
			}
		}
		OptSysEleMerit_LensType_vec.insert(OptSysEleMerit_LensType_vec.end(), EO_MicroPlanConvex_vec.begin(), EO_MicroPlanConvex_vec.end());
	}

	//EO_LargePlanConvexCondensor
	bool load_EO_LargePlanConvexCondensor = findCatalog(mLoadLensCatalogEO, lensTypes::EO_LargePlanConvexCondensor);
	if (load_EO_LargePlanConvexCondensor)
	{
		EO_LargePlanConvexCondensor_vec = findOptSysEle_lens_inCatalog_TwoSurfaces(paraLens, mAll_EO_LargePlanConvexCondensor, weightFocal, weightThickness, weightSemiHeight);
		for (unsigned int i = 0; i < EO_LargePlanConvexCondensor_vec.size(); ++i)
		{
			EO_LargePlanConvexCondensor_vec[i].setLensType(lensTypes::EO_LargePlanConvexCondensor);
		}
		if (prefLensType == lensTypes::EO_LargePlanConvexCondensor)
		{
			for (unsigned int i = 0; i < EO_LargePlanConvexCondensor_vec.size(); ++i)
			{
				EO_LargePlanConvexCondensor_vec[i].setMerit(EO_LargePlanConvexCondensor_vec[i].getMerit() / prefFactor);
			}
		}
		OptSysEleMerit_LensType_vec.insert(OptSysEleMerit_LensType_vec.end(), EO_LargePlanConvexCondensor_vec.begin(), EO_LargePlanConvexCondensor_vec.end());
	}

	/*Thorlabs*/

	//Th_AchromatDoublets_AR_Coated
	bool load_Th_AchromatDoublets_AR_Coated = findCatalog(mLoadLensCatalogThorlabs , lensTypes::Th_AchromatDoublets_AR_Coated);
	if (load_Th_AchromatDoublets_AR_Coated)
	{
		Th_AchromatDoublets_AR_Coated_vec = findOptSysEle_lens_inCatalog_ThreeSurfaces(paraLens, mAll_Th_AchromatDoublets_AR_Coated, weightFocal, weightThickness, weightSemiHeight);
		for (unsigned int i = 0; i < Th_AchromatDoublets_AR_Coated_vec.size(); ++i)
		{
			Th_AchromatDoublets_AR_Coated_vec[i].setLensType(lensTypes::Th_AchromatDoublets_AR_Coated);
		}
		if (prefLensType == lensTypes::Th_AchromatDoublets_AR_Coated)
		{
			for (unsigned int i = 0; i < Th_AchromatDoublets_AR_Coated_vec.size(); ++i)
			{
				Th_AchromatDoublets_AR_Coated_vec[i].setMerit(Th_AchromatDoublets_AR_Coated_vec[i].getMerit() / prefFactor);
			}
		}
		OptSysEleMerit_LensType_vec.insert(OptSysEleMerit_LensType_vec.end(), Th_AchromatDoublets_AR_Coated_vec.begin(), Th_AchromatDoublets_AR_Coated_vec.end());
	}

	//Th_NBK7_PlanConvex_AR_Coated_400_1100
	bool load_Th_NBK7_PlanConvex_AR_Coated_400_1100 = findCatalog(mLoadLensCatalogThorlabs, lensTypes::Th_NBK7_PlanConvex_AR_Coated_400_1100);
	if (load_Th_NBK7_PlanConvex_AR_Coated_400_1100)
	{
		Th_NBK7_PlanConvex_AR_Coated_400_1100_vec = findOptSysEle_lens_inCatalog_TwoSurfaces(paraLens, mAll_Th_NBK7_PlanConvex_AR_Coated_400_1100, weightFocal, weightThickness, weightSemiHeight);
		for (unsigned int i = 0; i < Th_NBK7_PlanConvex_AR_Coated_400_1100_vec.size(); ++i)
		{
			Th_NBK7_PlanConvex_AR_Coated_400_1100_vec[i].setLensType(lensTypes::Th_NBK7_PlanConvex_AR_Coated_400_1100);
		}
		if (prefLensType == lensTypes::Th_NBK7_PlanConvex_AR_Coated_400_1100)
		{
			for (unsigned int i = 0; i < Th_NBK7_PlanConvex_AR_Coated_400_1100_vec.size(); ++i)
			{
				Th_NBK7_PlanConvex_AR_Coated_400_1100_vec[i].setMerit(Th_NBK7_PlanConvex_AR_Coated_400_1100_vec[i].getMerit() / prefFactor);
			}
		}
		OptSysEleMerit_LensType_vec.insert(OptSysEleMerit_LensType_vec.end(), Th_NBK7_PlanConvex_AR_Coated_400_1100_vec.begin(), Th_NBK7_PlanConvex_AR_Coated_400_1100_vec.end());
	}

	//Th_NBK7_BiConvex_AR_Coated_350_700
	bool load_Th_NBK7_BiConvex_AR_Coated_350_700 = findCatalog(mLoadLensCatalogThorlabs, lensTypes::Th_NBK7_BiConvex_AR_Coated_350_700);
	if (load_Th_NBK7_BiConvex_AR_Coated_350_700)
	{
		Th_NBK7_BiConvex_AR_Coated_350_700_vec = findOptSysEle_lens_inCatalog_TwoSurfaces(paraLens, mAll_Th_NBK7_BiConvex_AR_Coated_350_700, weightFocal, weightThickness, weightSemiHeight);
		for (unsigned int i = 0; i < Th_NBK7_BiConvex_AR_Coated_350_700_vec.size(); ++i)
		{
			Th_NBK7_BiConvex_AR_Coated_350_700_vec[i].setLensType(lensTypes::Th_NBK7_BiConvex_AR_Coated_350_700);
		}
		if (prefLensType == lensTypes::Th_NBK7_BiConvex_AR_Coated_350_700)
		{
			for (unsigned int i = 0; i < Th_NBK7_BiConvex_AR_Coated_350_700_vec.size(); ++i)
			{
				Th_NBK7_BiConvex_AR_Coated_350_700_vec[i].setMerit(Th_NBK7_BiConvex_AR_Coated_350_700_vec[i].getMerit() / prefFactor);
			}
		}
		OptSysEleMerit_LensType_vec.insert(OptSysEleMerit_LensType_vec.end(), Th_NBK7_BiConvex_AR_Coated_350_700_vec.begin(), Th_NBK7_BiConvex_AR_Coated_350_700_vec.end());
	}

	//Th_NBK7_PlanConcav_AR_Coated_350_700
	bool load_Th_NBK7_PlanConcav_AR_Coated_350_700 = findCatalog(mLoadLensCatalogThorlabs, lensTypes::Th_NBK7_PlanConcav_AR_Coated_350_700);
	if (load_Th_NBK7_PlanConcav_AR_Coated_350_700)
	{
		Th_NBK7_PlanConcav_AR_Coated_350_700_vec = findOptSysEle_lens_inCatalog_TwoSurfaces(paraLens, mAll_Th_NBK7_PlanConcav_AR_Coated_350_700, weightFocal, weightThickness, weightSemiHeight);
		for (unsigned int i = 0; i < Th_NBK7_PlanConcav_AR_Coated_350_700_vec.size(); ++i)
		{
			Th_NBK7_PlanConcav_AR_Coated_350_700_vec[i].setLensType(lensTypes::Th_NBK7_PlanConcav_AR_Coated_350_700);
		}
		if (prefLensType == lensTypes::Th_NBK7_PlanConcav_AR_Coated_350_700)
		{
			for (unsigned int i = 0; i < Th_NBK7_PlanConcav_AR_Coated_350_700_vec.size(); ++i)
			{
				Th_NBK7_PlanConcav_AR_Coated_350_700_vec[i].setMerit(Th_NBK7_PlanConcav_AR_Coated_350_700_vec[i].getMerit() / prefFactor);
			}
		}
		OptSysEleMerit_LensType_vec.insert(OptSysEleMerit_LensType_vec.end(), Th_NBK7_PlanConcav_AR_Coated_350_700_vec.begin(), Th_NBK7_PlanConcav_AR_Coated_350_700_vec.end());
	}

	//Th_NBK7_NSF11_BiConcav_AR_Coated_350_700
	bool load_Th_NBK7_NSF11_BiConcav_AR_Coated_350_700 = findCatalog(mLoadLensCatalogThorlabs, lensTypes::Th_NBK7_NSF11_BiConcav_AR_Coated_350_700);
	if (load_Th_NBK7_NSF11_BiConcav_AR_Coated_350_700)
	{
		Th_NBK7_NSF11_BiConcav_AR_Coated_350_700_vec = findOptSysEle_lens_inCatalog_TwoSurfaces(paraLens, mAll_Th_NBK7_NSF11_BiConcav_AR_Coated_350_700, weightFocal, weightThickness, weightSemiHeight);
		for (unsigned int i = 0; i < Th_NBK7_NSF11_BiConcav_AR_Coated_350_700_vec.size(); ++i)
		{
			Th_NBK7_NSF11_BiConcav_AR_Coated_350_700_vec[i].setLensType(lensTypes::Th_NBK7_NSF11_BiConcav_AR_Coated_350_700);
		}
		if (prefLensType == lensTypes::Th_NBK7_NSF11_BiConcav_AR_Coated_350_700)
		{
			for (unsigned int i = 0; i < Th_NBK7_NSF11_BiConcav_AR_Coated_350_700_vec.size(); ++i)
			{
				Th_NBK7_NSF11_BiConcav_AR_Coated_350_700_vec[i].setMerit(Th_NBK7_NSF11_BiConcav_AR_Coated_350_700_vec[i].getMerit() / prefFactor);
			}
		}
		OptSysEleMerit_LensType_vec.insert(OptSysEleMerit_LensType_vec.end(), Th_NBK7_NSF11_BiConcav_AR_Coated_350_700_vec.begin(), Th_NBK7_NSF11_BiConcav_AR_Coated_350_700_vec.end());
	}

	//Th_NBK7_BestFormSpherical_AR_Coated_350_700
	bool load_Th_NBK7_BestFormSpherical_AR_Coated_350_700 = findCatalog(mLoadLensCatalogThorlabs, lensTypes::Th_NBK7_BestFormSpherical_AR_Coated_350_700);
	if (load_Th_NBK7_BestFormSpherical_AR_Coated_350_700)
	{
		Th_NBK7_BestFormSpherical_AR_Coated_350_700_vec = findOptSysEle_lens_inCatalog_TwoSurfaces(paraLens, mAll_Th_NBK7_BestFormSpherical_AR_Coated_350_700, weightFocal, weightThickness, weightSemiHeight);
		for (unsigned int i = 0; i < Th_NBK7_BestFormSpherical_AR_Coated_350_700_vec.size(); ++i)
		{
			Th_NBK7_BestFormSpherical_AR_Coated_350_700_vec[i].setLensType(lensTypes::Th_NBK7_BestFormSpherical_AR_Coated_350_700);
		}
		if (prefLensType == lensTypes::Th_NBK7_BestFormSpherical_AR_Coated_350_700)
		{
			for (unsigned int i = 0; i < Th_NBK7_BestFormSpherical_AR_Coated_350_700_vec.size(); ++i)
			{
				Th_NBK7_BestFormSpherical_AR_Coated_350_700_vec[i].setMerit(Th_NBK7_BestFormSpherical_AR_Coated_350_700_vec[i].getMerit() / prefFactor);
			}
		}
		OptSysEleMerit_LensType_vec.insert(OptSysEleMerit_LensType_vec.end(), Th_NBK7_BestFormSpherical_AR_Coated_350_700_vec.begin(), Th_NBK7_BestFormSpherical_AR_Coated_350_700_vec.end());
	}

	//Th_NBK7_PosMeniscus_Uncoated
	bool load_Th_NBK7_PosMeniscus_Uncoated = findCatalog(mLoadLensCatalogThorlabs, lensTypes::Th_NBK7_PosMeniscus_Uncoated);
	if (load_Th_NBK7_PosMeniscus_Uncoated)
	{
		Th_NBK7_PosMeniscus_Uncoated_vec = findOptSysEle_lens_inCatalog_TwoSurfaces(paraLens, mAll_Th_NBK7_PosMeniscus_Uncoated, weightFocal, weightThickness, weightSemiHeight);
		for (unsigned int i = 0; i < Th_NBK7_PosMeniscus_Uncoated_vec.size(); ++i)
		{
			Th_NBK7_PosMeniscus_Uncoated_vec[i].setLensType(lensTypes::Th_NBK7_PosMeniscus_Uncoated);
		}
		if (prefLensType == lensTypes::Th_NBK7_PosMeniscus_Uncoated)
		{
			for (unsigned int i = 0; i < Th_NBK7_PosMeniscus_Uncoated_vec.size(); ++i)
			{
				Th_NBK7_PosMeniscus_Uncoated_vec[i].setMerit(Th_NBK7_PosMeniscus_Uncoated_vec[i].getMerit() / prefFactor);
			}
		}
		OptSysEleMerit_LensType_vec.insert(OptSysEleMerit_LensType_vec.end(), Th_NBK7_PosMeniscus_Uncoated_vec.begin(), Th_NBK7_PosMeniscus_Uncoated_vec.end());
	}

	//Th_NBK7_NegMeniscus_Uncoated
	bool load_Th_NBK7_NegMeniscus_Uncoated = findCatalog(mLoadLensCatalogThorlabs, lensTypes::Th_NBK7_NegMeniscus_Uncoated);
	if (load_Th_NBK7_NegMeniscus_Uncoated)
	{
		Th_NBK7_NegMeniscus_Uncoated_vec = findOptSysEle_lens_inCatalog_TwoSurfaces(paraLens, mAll_Th_NBK7_NegMeniscus_Uncoated, weightFocal, weightThickness, weightSemiHeight);
		for (unsigned int i = 0; i < Th_NBK7_NegMeniscus_Uncoated_vec.size(); ++i)
		{
			Th_NBK7_NegMeniscus_Uncoated_vec[i].setLensType(lensTypes::Th_NBK7_NegMeniscus_Uncoated);
		}
		if (prefLensType == lensTypes::Th_NBK7_NegMeniscus_Uncoated)
		{
			for (unsigned int i = 0; i < Th_NBK7_NegMeniscus_Uncoated_vec.size(); ++i)
			{
				Th_NBK7_NegMeniscus_Uncoated_vec[i].setMerit(Th_NBK7_NegMeniscus_Uncoated_vec[i].getMerit() / prefFactor);
			}
		}
		OptSysEleMerit_LensType_vec.insert(OptSysEleMerit_LensType_vec.end(), Th_NBK7_NegMeniscus_Uncoated_vec.begin(), Th_NBK7_NegMeniscus_Uncoated_vec.end());
	}

	//Th_SteinheilTripletAchromat_Visible
	bool load_Th_SteinheilTripletAchromat_Visible = findCatalog(mLoadLensCatalogThorlabs, lensTypes::Th_SteinheilTripletAchromat_Visible);
	if (load_Th_SteinheilTripletAchromat_Visible)
	{
		Th_SteinheilTripletAchromat_Visible_vec = findOptSysEle_lens_inCatalog_FourSurfaces(paraLens, mAll_Th_SteinheilTripletAchromat_Visible, weightFocal, weightThickness, weightSemiHeight);
		for (unsigned int i = 0; i < Th_SteinheilTripletAchromat_Visible_vec.size(); ++i)
		{
			Th_SteinheilTripletAchromat_Visible_vec[i].setLensType(lensTypes::Th_SteinheilTripletAchromat_Visible);
		}
		if (prefLensType == lensTypes::Th_SteinheilTripletAchromat_Visible)
		{
			for (unsigned int i = 0; i < Th_SteinheilTripletAchromat_Visible_vec.size(); ++i)
			{
				Th_SteinheilTripletAchromat_Visible_vec[i].setMerit(Th_SteinheilTripletAchromat_Visible_vec[i].getMerit() / prefFactor);
			}
		}
		OptSysEleMerit_LensType_vec.insert(OptSysEleMerit_LensType_vec.end(), Th_SteinheilTripletAchromat_Visible_vec.begin(), Th_SteinheilTripletAchromat_Visible_vec.end());
	}

	//Th_HastingsTripletAchromatVisible
	bool load_Th_HastingsTripletAchromatVisible = findCatalog(mLoadLensCatalogThorlabs, lensTypes::Th_HastingsTripletAchromatVisible);
	if (load_Th_HastingsTripletAchromatVisible)
	{
		Th_HastingsTripletAchromatVisible_vec = findOptSysEle_lens_inCatalog_FourSurfaces(paraLens, mAll_Th_HastingsTripletAchromatVisible, weightFocal, weightThickness, weightSemiHeight);
		for (unsigned int i = 0; i < Th_HastingsTripletAchromatVisible_vec.size(); ++i)
		{
			Th_HastingsTripletAchromatVisible_vec[i].setLensType(lensTypes::Th_HastingsTripletAchromatVisible);
		}
		if (prefLensType == lensTypes::Th_HastingsTripletAchromatVisible)
		{
			for (unsigned int i = 0; i < Th_HastingsTripletAchromatVisible_vec.size(); ++i)
			{
				Th_HastingsTripletAchromatVisible_vec[i].setMerit(Th_HastingsTripletAchromatVisible_vec[i].getMerit() / prefFactor);
			}
		}
		OptSysEleMerit_LensType_vec.insert(OptSysEleMerit_LensType_vec.end(), Th_HastingsTripletAchromatVisible_vec.begin(), Th_HastingsTripletAchromatVisible_vec.end());
	}

	/*Qioptiq*/

	//Qi_PlanConvex_ARB2_VIS
	bool load_Qi_PlanConvex_ARB2_VIS = findCatalog(mLoadLensCatalogQioptiq, lensTypes::Qi_PlanConvex_ARB2_VIS);
	if (load_Qi_PlanConvex_ARB2_VIS)
	{
		Qi_PlanConvex_ARB2_VIS_vec = findOptSysEle_lens_inCatalog_TwoSurfaces(paraLens, mAll_Qi_PlanConvex_ARB2_VIS, weightFocal, weightThickness, weightSemiHeight);
		for (unsigned int i = 0; i < Qi_PlanConvex_ARB2_VIS_vec.size(); ++i)
		{
			Qi_PlanConvex_ARB2_VIS_vec[i].setLensType(lensTypes::Qi_PlanConvex_ARB2_VIS);
		}
		if (prefLensType == lensTypes::Qi_PlanConvex_ARB2_VIS)
		{
			for (unsigned int i = 0; i < Qi_PlanConvex_ARB2_VIS_vec.size(); ++i)
			{
				Qi_PlanConvex_ARB2_VIS_vec[i].setMerit(Qi_PlanConvex_ARB2_VIS_vec[i].getMerit() / prefFactor);
			}
		}
		OptSysEleMerit_LensType_vec.insert(OptSysEleMerit_LensType_vec.end(), Qi_PlanConvex_ARB2_VIS_vec.begin(), Qi_PlanConvex_ARB2_VIS_vec.end());
	}

	//Qi_SymmetricConvex_ARB2_VIS
	bool load_Qi_SymmetricConvex_ARB2_VIS = findCatalog(mLoadLensCatalogQioptiq, lensTypes::Qi_SymmetricConvex_ARB2_VIS);
	if (load_Qi_SymmetricConvex_ARB2_VIS)
	{
		Qi_SymmetricConvex_ARB2_VIS_vec = findOptSysEle_lens_inCatalog_TwoSurfaces(paraLens, mAll_Qi_SymmetricConvex_ARB2_VIS, weightFocal, weightThickness, weightSemiHeight);
		for (unsigned int i = 0; i < Qi_SymmetricConvex_ARB2_VIS_vec.size(); ++i)
		{
			Qi_SymmetricConvex_ARB2_VIS_vec[i].setLensType(lensTypes::Qi_SymmetricConvex_ARB2_VIS);
		}
		if (prefLensType == lensTypes::Qi_SymmetricConvex_ARB2_VIS)
		{
			for (unsigned int i = 0; i < Qi_SymmetricConvex_ARB2_VIS_vec.size(); ++i)
			{
				Qi_SymmetricConvex_ARB2_VIS_vec[i].setMerit(Qi_SymmetricConvex_ARB2_VIS_vec[i].getMerit() / prefFactor);
			}
		}
		OptSysEleMerit_LensType_vec.insert(OptSysEleMerit_LensType_vec.end(), Qi_SymmetricConvex_ARB2_VIS_vec.begin(), Qi_SymmetricConvex_ARB2_VIS_vec.end());
	}

	//Qi_PlanConcav_ARB2_VIS
	bool load_Qi_PlanConcav_ARB2_VIS = findCatalog(mLoadLensCatalogQioptiq, lensTypes::Qi_PlanConcav_ARB2_VIS);
	if (load_Qi_PlanConcav_ARB2_VIS)
	{
		Qi_PlanConcav_ARB2_VIS_vec = findOptSysEle_lens_inCatalog_TwoSurfaces(paraLens, mAll_Qi_PlanConcav_ARB2_VIS, weightFocal, weightThickness, weightSemiHeight);
		for (unsigned int i = 0; i < Qi_PlanConcav_ARB2_VIS_vec.size(); ++i)
		{
			Qi_PlanConcav_ARB2_VIS_vec[i].setLensType(lensTypes::Qi_PlanConcav_ARB2_VIS);
		}
		if (prefLensType == lensTypes::Qi_PlanConcav_ARB2_VIS)
		{
			for (unsigned int i = 0; i < Qi_PlanConcav_ARB2_VIS_vec.size(); ++i)
			{
				Qi_PlanConcav_ARB2_VIS_vec[i].setMerit(Qi_PlanConcav_ARB2_VIS_vec[i].getMerit() / prefFactor);
			}
		}
		OptSysEleMerit_LensType_vec.insert(OptSysEleMerit_LensType_vec.end(), Qi_PlanConcav_ARB2_VIS_vec.begin(), Qi_PlanConcav_ARB2_VIS_vec.end());
	}

	//Qi_SymmetricConcav_ARB2_VIS
	bool load_Qi_SymmetricConcav_ARB2_VIS = findCatalog(mLoadLensCatalogQioptiq, lensTypes::Qi_SymmetricConcav_ARB2_VIS);
	if (load_Qi_SymmetricConcav_ARB2_VIS)
	{
		Qi_SymmetricConcav_ARB2_VIS_vec = findOptSysEle_lens_inCatalog_TwoSurfaces(paraLens, mAll_Qi_SymmetricConcav_ARB2_VIS, weightFocal, weightThickness, weightSemiHeight);
		for (unsigned int i = 0; i < Qi_SymmetricConcav_ARB2_VIS_vec.size(); ++i)
		{
			Qi_SymmetricConcav_ARB2_VIS_vec[i].setLensType(lensTypes::Qi_SymmetricConcav_ARB2_VIS);
		}
		if (prefLensType == lensTypes::Qi_SymmetricConcav_ARB2_VIS)
		{
			for (unsigned int i = 0; i < Qi_SymmetricConcav_ARB2_VIS_vec.size(); ++i)
			{
				Qi_SymmetricConcav_ARB2_VIS_vec[i].setMerit(Qi_SymmetricConcav_ARB2_VIS_vec[i].getMerit() / prefFactor);
			}
		}
		OptSysEleMerit_LensType_vec.insert(OptSysEleMerit_LensType_vec.end(), Qi_SymmetricConcav_ARB2_VIS_vec.begin(), Qi_SymmetricConcav_ARB2_VIS_vec.end());
	}

	//Qi_PosAchromat_VIS_3_31_ARB2_VIS
	bool load_Qi_PosAchromat_VIS_3_31_ARB2_VIS = findCatalog(mLoadLensCatalogQioptiq, lensTypes::Qi_PosAchromat_VIS_3_31_ARB2_VIS);
	if (load_Qi_PosAchromat_VIS_3_31_ARB2_VIS)
	{
		Qi_PosAchromat_VIS_3_31_ARB2_VIS_vec = findOptSysEle_lens_inCatalog_ThreeSurfaces(paraLens, mAll_Qi_PosAchromat_VIS_3_31_ARB2_VIS, weightFocal, weightThickness, weightSemiHeight);
		for (unsigned int i = 0; i < Qi_PosAchromat_VIS_3_31_ARB2_VIS_vec.size(); ++i)
		{
			Qi_PosAchromat_VIS_3_31_ARB2_VIS_vec[i].setLensType(lensTypes::Qi_PosAchromat_VIS_3_31_ARB2_VIS);
		}
		if (prefLensType == lensTypes::Qi_PosAchromat_VIS_3_31_ARB2_VIS)
		{
			for (unsigned int i = 0; i < Qi_PosAchromat_VIS_3_31_ARB2_VIS_vec.size(); ++i)
			{
				Qi_PosAchromat_VIS_3_31_ARB2_VIS_vec[i].setMerit(Qi_PosAchromat_VIS_3_31_ARB2_VIS_vec[i].getMerit() / prefFactor);
			}
		}
		OptSysEleMerit_LensType_vec.insert(OptSysEleMerit_LensType_vec.end(), Qi_PosAchromat_VIS_3_31_ARB2_VIS_vec.begin(), Qi_PosAchromat_VIS_3_31_ARB2_VIS_vec.end());
	}

	//Qi_PosAchromat_VIS_31_40_ARB2_VIS
	bool load_Qi_PosAchromat_VIS_31_40_ARB2_VIS = findCatalog(mLoadLensCatalogQioptiq, lensTypes::Qi_PosAchromat_VIS_31_40_ARB2_VIS);
	if (load_Qi_PosAchromat_VIS_31_40_ARB2_VIS)
	{
		Qi_PosAchromat_VIS_31_40_ARB2_VIS_vec = findOptSysEle_lens_inCatalog_ThreeSurfaces(paraLens, mAll_Qi_PosAchromat_VIS_31_40_ARB2_VIS, weightFocal, weightThickness, weightSemiHeight);
		for (unsigned int i = 0; i < Qi_PosAchromat_VIS_31_40_ARB2_VIS_vec.size(); ++i)
		{
			Qi_PosAchromat_VIS_31_40_ARB2_VIS_vec[i].setLensType(lensTypes::Qi_PosAchromat_VIS_31_40_ARB2_VIS);
		}
		if (prefLensType == lensTypes::Qi_PosAchromat_VIS_31_40_ARB2_VIS)
		{
			for (unsigned int i = 0; i < Qi_PosAchromat_VIS_31_40_ARB2_VIS_vec.size(); ++i)
			{
				Qi_PosAchromat_VIS_31_40_ARB2_VIS_vec[i].setMerit(Qi_PosAchromat_VIS_31_40_ARB2_VIS_vec[i].getMerit() / prefFactor);
			}
		}
		OptSysEleMerit_LensType_vec.insert(OptSysEleMerit_LensType_vec.end(), Qi_PosAchromat_VIS_31_40_ARB2_VIS_vec.begin(), Qi_PosAchromat_VIS_31_40_ARB2_VIS_vec.end());
	}

	//Qi_NegAchromat_ARB2_VIS
	bool load_Qi_NegAchromat_ARB2_VIS = findCatalog(mLoadLensCatalogQioptiq, lensTypes::Qi_NegAchromat_ARB2_VIS);
	if (load_Qi_NegAchromat_ARB2_VIS)
	{
		Qi_NegAchromat_ARB2_VIS_vec = findOptSysEle_lens_inCatalog_ThreeSurfaces(paraLens, mAll_Qi_NegAchromat_ARB2_VIS, weightFocal, weightThickness, weightSemiHeight);
		for (unsigned int i = 0; i < Qi_NegAchromat_ARB2_VIS_vec.size(); ++i)
		{
			Qi_NegAchromat_ARB2_VIS_vec[i].setLensType(lensTypes::Qi_NegAchromat_ARB2_VIS);
		}
		if (prefLensType == lensTypes::Qi_NegAchromat_ARB2_VIS)
		{
			for (unsigned int i = 0; i < Qi_NegAchromat_ARB2_VIS_vec.size(); ++i)
			{
				Qi_NegAchromat_ARB2_VIS_vec[i].setMerit(Qi_NegAchromat_ARB2_VIS_vec[i].getMerit() / prefFactor);
			}
		}
		OptSysEleMerit_LensType_vec.insert(OptSysEleMerit_LensType_vec.end(), Qi_NegAchromat_ARB2_VIS_vec.begin(), Qi_NegAchromat_ARB2_VIS_vec.end());
	}



	std::vector<OptSysEle_Merit_LensType> bestOptSys_vec = getBestOptSys(OptSysEleMerit_LensType_vec, numberLenses);

	return  bestOptSys_vec;
}

std::vector<OptSysEle_Merit_LensType> LensReplace::getBestOptSys(std::vector<OptSysEle_Merit_LensType> optSysEle_merit_lensType_vec, unsigned int numberSystem)
{
	unsigned int numOptSys = optSysEle_merit_lensType_vec.size();
	real bestMeritValue = optSysEle_merit_lensType_vec[0].getMerit();
	OpticalSystemElement bestOptSysEle = optSysEle_merit_lensType_vec[0].getOptSysEle();

	unsigned int counter = 0;
	std::vector<OptSysEle_Merit_LensType> bestMetchOptSys_vec;
	bestMetchOptSys_vec.resize(numberSystem);

	real tempMeritValue{};
	for (unsigned int numSys = 0; numSys < numberSystem; ++numSys)
	{
		for (unsigned int i = 1; i < numOptSys; ++i)
		{
			tempMeritValue = optSysEle_merit_lensType_vec[i].getMerit();

			if (bestMeritValue > tempMeritValue)
			{
				bestMeritValue = tempMeritValue;
				counter = i;
			}

		}

		bestMetchOptSys_vec[numSys] = optSysEle_merit_lensType_vec[counter];
		bestMetchOptSys_vec[numSys].setPositionInBestMatchLensVec(numSys);
		optSysEle_merit_lensType_vec[counter].setMerit(oftenUse::getInfReal());
		bestMeritValue = oftenUse::getInfReal();
	}

	return bestMetchOptSys_vec;
}

void LensReplace::replaceLens(unsigned int lensNo, OpticalSystemElement fillInOptSysEle)
{
	mOpticalSystemEle_replaceLens = mOpticalSystemEle.getDeepCopyOptSysEle();

	std::vector<unsigned int> lensNumbersToReplace;
	unsigned int saveLensNumbersToReplace;

	unsigned int posLensToReplace;
	unsigned int size = mOptSysLLT_lenses_vec[lensNo].getPosAndInteractingSurface().size();

	for (unsigned int i = 0; i < size; ++i)
	{
		posLensToReplace = mOptSysLLT_lenses_vec[lensNo].getPosAndInteractingSurface()[i].getPosition();
		lensNumbersToReplace.push_back(posLensToReplace);

		if (i < size - 1)
		{
			mThicknessesAndPos_vec[posLensToReplace].setFixed(true);
		}

	}

	saveLensNumbersToReplace = lensNumbersToReplace.size();

	if (lensNumbersToReplace.size() != fillInOptSysEle.getPosAndElement().size())
	{

		if (lensNumbersToReplace.size() > fillInOptSysEle.getPosAndElement().size())
		{
			int remove = lensNumbersToReplace.size() - fillInOptSysEle.getPosAndElement().size();
			// remove
			bool checker = true;
			int interation = 1;
			while (checker)
			{
				mThicknessesAndPos_vec.erase(mThicknessesAndPos_vec.begin() + lensNumbersToReplace[1]);
				++interation;

				if (interation > remove)
				{
					checker = false;
				}
			}

			// adjust positions
			for (unsigned int pos = 0; pos < mThicknessesAndPos_vec.size(); ++pos)
			{
				mThicknessesAndPos_vec[pos].setPosition(pos);
			}


		}

		else
		{
			int add = fillInOptSysEle.getPosAndElement().size() - lensNumbersToReplace.size();
			thicknessAndPosition tempThicknessAndPos;
			tempThicknessAndPos.setFixed(true);
			tempThicknessAndPos.setPosition(99);
			tempThicknessAndPos.setThickness_Z(99.0);
			// add new thicknesse
			for (unsigned int i = 0; i < add; ++i)
			{
				mThicknessesAndPos_vec.insert(mThicknessesAndPos_vec.begin() + lensNumbersToReplace.back() + i, tempThicknessAndPos);

			}

			// adjust positions
			for (unsigned int pos = 0; pos < mThicknessesAndPos_vec.size(); ++pos)
			{
				mThicknessesAndPos_vec[pos].setPosition(pos);
			}

		}
	}

	real pos_Z_firstSurface = mOpticalSystemEle_replaceLens.getPosAndElement()[lensNumbersToReplace[0]].getElementInOptSys_ptr()->getPointElementValue_Z();
	// calc thicknessToPos0
	std::vector<real> thicknesToSurface0;
	thicknesToSurface0.push_back(0.0);
	real thicknessBefore;
	real tempThicknessTotal;
	for (unsigned int i = 1; i < fillInOptSysEle.getPosAndElement().size(); ++i)
	{
		tempThicknessTotal = fillInOptSysEle.getPosAndElement()[i].getElementInOptSys_ptr()->getPointElementValue_Z();
		thicknesToSurface0.push_back(tempThicknessTotal);
	}


	int lastPosLensToReplace = lensNumbersToReplace.back();
	Parameter<real> paraPosZSurfaceToReplace = mOpticalSystemEle_replaceLens.getPosAndElement()[lastPosLensToReplace].getElementInOptSys_ptr()->getParameterPositionZ();
	unsigned int sizeFillInSys = fillInOptSysEle.getPosAndElement().size();
	fillInOptSysEle.getPosAndElement()[sizeFillInSys - 1].getElementInOptSys_ptr()->setParameterPointZ(paraPosZSurfaceToReplace.getMinimum(), paraPosZSurfaceToReplace.getMaximum(), paraPosZSurfaceToReplace.getStdDev(), paraPosZSurfaceToReplace.getModifier());
	
	mOpticalSystemEle_replaceLens.delSurfaceNumber_from_TO(lensNumbersToReplace[0], lastPosLensToReplace);
	
	if (fillInOptSysEle.getPosAndElement().size() > lensNumbersToReplace.size())
	{
		int add = fillInOptSysEle.getPosAndElement().size() - lensNumbersToReplace.size();
		for (unsigned int i = 0; i < add; ++i)
		{
			lensNumbersToReplace.push_back(lensNumbersToReplace.back() + 1);

		}
	}

	for (unsigned int i = 0; i < fillInOptSysEle.getPosAndElement().size(); ++i)
	{
		fillInOptSysEle.getPosAndElement()[i].getElementInOptSys_ptr()->setPointElementValue_Z(pos_Z_firstSurface + thicknesToSurface0[i]);
		mOpticalSystemEle_replaceLens.fillInElementAndInteractionAtPos_i(lensNumbersToReplace[i], fillInOptSysEle.getPosAndElement()[i].getElementInOptSys_ptr(), fillInOptSysEle.getPosAndInteraction_LLT()[i].getInteractionAtSur_ptr());

	}

	mOpticalSystem_LLT_replaceLens = mOpticalSystemEle_replaceLens.getOptSys_LLT_buildSystem();

	//debug
	//oftenUse::print(mOpticalSystem_LLT_replaceLens);

	if (saveLensNumbersToReplace != fillInOptSysEle.getPosAndElement().size())
	{
		mOptSysLLT_lenses_vec = oftenUse::findLensesInOptSys_LLT(mOpticalSystem_LLT_replaceLens);
	}
}

void LensReplace::saveFixedThicknessesLenses_doNotUseThatFct()
{
	real tolerance = 0.000001;


	unsigned int sizeOptSys = mOpticalSystem_LLT_replaceLens.getPosAndInteractingSurface().size();

	std::shared_ptr<SurfaceIntersectionRay_LLT> tempSurface_ptr;
	real tempRefIndex_A;
	real tempRefIndex_B;
	real tempDirection_Z;

	std::shared_ptr<SurfaceIntersectionRay_LLT> tempSurfacePlusOne_ptr;
	real tempRefIndexPlusOne_A;
	real tempRefIndexPlusOne_B;
	real tempDirectionPlusOne;

	real tempThickness;
	real refIndexSurMat = mDefaultPara_LensReplace.getRefIndexSurroundMat();

	thicknessAndPosition tempThickAndPos;
	for (unsigned int i = 0; i < sizeOptSys - 1; ++i)
	{
		tempSurface_ptr = mOpticalSystem_LLT_replaceLens.getPosAndInteractingSurface()[i].getSurfaceInterRay_ptr();
		tempSurfacePlusOne_ptr = mOpticalSystem_LLT_replaceLens.getPosAndInteractingSurface()[i + 1].getSurfaceInterRay_ptr();

		tempDirection_Z = tempSurface_ptr->getDirection().getZ();
		tempDirectionPlusOne = tempSurfacePlusOne_ptr->getDirection().getZ();

		tempRefIndex_A = tempSurface_ptr->getRefractiveIndex_A();
		tempRefIndex_B = tempSurface_ptr->getRefractiveIndex_B();

		tempRefIndexPlusOne_A = tempSurfacePlusOne_ptr->getRefractiveIndex_A();
		tempRefIndexPlusOne_B = tempSurfacePlusOne_ptr->getRefractiveIndex_B();

		//// check for aperture stop
		//if (std::abs(tempRefIndex_A - tempRefIndex_B) < tolerance && i != sizeOptSys - 1)
		//{
		//	tempThickAndPos.setPosition(i);
		//	
		//	tempThickness = tempSurfacePlusOne_ptr->getPoint().getZ() - tempSurface_ptr->getPoint().getZ();
		//	tempThickAndPos.setThickness_Z(tempThickness);
		//
		//	mThicknessesAndPos_vec_Fixed.push_back(tempThickAndPos);
		//}

		// case 0: concave - air - concave
		if (tempDirection_Z > 0 && tempDirectionPlusOne < 0)
		{
			if (std::abs(tempRefIndex_B - refIndexSurMat) < tolerance && std::abs(tempRefIndexPlusOne_B - refIndexSurMat) < tolerance)
			{
				tempThickAndPos.setPosition(i);
				tempThickness = tempSurfacePlusOne_ptr->getPoint().getZ() - tempSurface_ptr->getPoint().getZ();
				tempThickAndPos.setThickness_Z(tempThickness);

				mThicknessesAndPos_vec.push_back(tempThickAndPos);
			}
		}

		// case 1: convex - air - concave
		else if (tempDirection_Z < 0 && tempDirectionPlusOne < 0)
		{
			if (std::abs(tempRefIndex_A - refIndexSurMat) < tolerance && std::abs(tempRefIndexPlusOne_B - refIndexSurMat) < tolerance)
			{
				tempThickAndPos.setPosition(i);
				tempThickness = tempSurfacePlusOne_ptr->getPoint().getZ() - tempSurface_ptr->getPoint().getZ();
				tempThickAndPos.setThickness_Z(tempThickness);

				mThicknessesAndPos_vec.push_back(tempThickAndPos);
			}

		}

		// case 2: concave - air - convex
		else if (tempDirection_Z > 0 && tempDirectionPlusOne > 0)
		{
			if (std::abs(tempRefIndex_B - refIndexSurMat) < tolerance && std::abs(tempRefIndexPlusOne_A - refIndexSurMat) < tolerance)
			{
				tempThickAndPos.setPosition(i);
				tempThickness = tempSurfacePlusOne_ptr->getPoint().getZ() - tempSurface_ptr->getPoint().getZ();
				tempThickAndPos.setThickness_Z(tempThickness);

				mThicknessesAndPos_vec.push_back(tempThickAndPos);
			}

		}

		// case 3: convex - air - convex
		else if (tempDirection_Z < 0 && tempDirectionPlusOne > 0)
		{
			if (std::abs(tempRefIndex_A - refIndexSurMat) < tolerance && std::abs(tempRefIndexPlusOne_A - refIndexSurMat) < tolerance)
			{
				tempThickAndPos.setPosition(i);
				tempThickness = tempSurfacePlusOne_ptr->getPoint().getZ() - tempSurface_ptr->getPoint().getZ();
				tempThickAndPos.setThickness_Z(tempThickness);

				mThicknessesAndPos_vec.push_back(tempThickAndPos);
			}
		}


	}



}

void LensReplace::saveFixedThicknessesLenses()
{
	unsigned int sizeOptSys = mOpticalSystem_LLT_replaceLens.getPosAndInteractingSurface().size();

	real tempPosZ;
	real tempPosPlusOneZ;
	real tempThickness;

	mThicknessesAndPos_vec.resize(sizeOptSys - 1);

	thicknessAndPosition tempThickAndPos;
	for (unsigned int i = 0; i < sizeOptSys - 1; ++i)
	{
		tempPosZ = mOpticalSystem_LLT_replaceLens.getPosAndInteractingSurface()[i].getSurfaceInterRay_ptr()->getPoint().getZ();
		tempPosPlusOneZ = mOpticalSystem_LLT_replaceLens.getPosAndInteractingSurface()[i + 1].getSurfaceInterRay_ptr()->getPoint().getZ();

		tempThickness = tempPosPlusOneZ - tempPosZ;
		tempThickAndPos.setPosition(i);
		tempThickAndPos.setThickness_Z(tempThickness);
		tempThickAndPos.setFixed(false);

		mThicknessesAndPos_vec[i] = tempThickAndPos;

		// debug
		// std::cout << "tempThickness :" << tempThickness << std::endl;
	}


}

void LensReplace::reloadThicknessesAndFixed()
{
	unsigned int sizeOptSys = mOpticalSystem_LLT_replaceLens.getPosAndInteractingSurface().size();

	real tempPosZ;
	real tempPosPlusOneZ;
	real tempThickness;


	thicknessAndPosition tempThickAndPos;
	for (unsigned int i = 0; i < sizeOptSys - 1; ++i)
	{
		tempPosZ = mOpticalSystem_LLT_replaceLens.getPosAndInteractingSurface()[i].getSurfaceInterRay_ptr()->getPoint().getZ();
		tempPosPlusOneZ = mOpticalSystem_LLT_replaceLens.getPosAndInteractingSurface()[i + 1].getSurfaceInterRay_ptr()->getPoint().getZ();

		tempThickness = tempPosPlusOneZ - tempPosZ;
		tempThickAndPos.setPosition(i);
		tempThickAndPos.setThickness_Z(tempThickness);
		tempThickAndPos.setFixed(mThicknessesAndPos_vec[i].getFixed());

		mThicknessesAndPos_vec[i] = tempThickAndPos;

		// debug
		// std::cout << "tempThickness :" << tempThickness << std::endl;
	}
}

OpticalSystemElement LensReplace::getOpticalSysEle_replacedLens()
{
	return mOpticalSystemEle_replaceLens;
}
OpticalSystemElement LensReplace::getOpticalSysEle_startSystem()
{
	return mOpticalSystemEle;
}
std::vector<OpticalSystemElement> LensReplace::getOpticalSysEle_replacedLens_vec()
{
	return mReplacedOptSysEle_vec;
}

bool LensReplace::checkValueMinMax(real val, real min, real max)
{
	bool checkMin = val > min;
	bool checkMax = val < max;

	bool checker = checkMin && checkMax;

	return checker;
}


void LensReplace::adjustThicknessesAccordingToFixed()
{
	unsigned int sizeFixThicknesses = mThicknessesAndPos_vec.size();

	unsigned int tempPos;
	real tempThicknessFixed;

	real tempPos_Z;
	real tempNewPosPlusOne_Z;

	VectorStructR3 tempPosVec = { 0.0,0.0,0.0 };
	bool tempFixed;

	for (unsigned int i = 0; i < sizeFixThicknesses; ++i)
	{
		tempFixed = mThicknessesAndPos_vec[i].getFixed();
		if (tempFixed == false)
		{
			tempPos = mThicknessesAndPos_vec[i].getPosition();
			tempThicknessFixed = mThicknessesAndPos_vec[i].getThickness_Z();

			tempPos_Z = mOpticalSystem_LLT_replaceLens.getPosAndInteractingSurface()[tempPos].getSurfaceInterRay_ptr()->getPoint().getZ();
			tempNewPosPlusOne_Z = tempPos_Z + tempThicknessFixed;
			tempPosVec.setZ(tempNewPosPlusOne_Z);

			// optical system LLT
			mOpticalSystem_LLT_replaceLens.getPosAndInteractingSurface()[tempPos + 1].getSurfaceInterRay_ptr()->setPosition(tempPosVec);

			// optical system element
			mOpticalSystemEle_replaceLens.getPosAndElement()[tempPos + 1].getElementInOptSys_ptr()->setPointElementValue_Z(tempNewPosPlusOne_Z);
			mOpticalSystemEle_replaceLens.getPosAndIntersection_LLT()[tempPos + 1].getSurfaceInterRay_ptr()->setPosition(tempPosVec);
		}

	}

	// reloaded thicknesses according to temp optical system
	reloadThicknessesAndFixed();

}

// *** set default parameters
// refrectiv index surrounding material
void LensReplace::setRefIndexSurroundMat(real refIndexSurMat)
{
	mDefaultPara_LensReplace.setRefIndexSurroundMat(refIndexSurMat);
}
real LensReplace::getRefIndexSurroundMat()
{
	return mDefaultPara_LensReplace.getRefIndexSurroundMat();
}
// ***

void LensReplace::replaceLensesAccordingToLensReplaceSequence_superFct(/*replace sequence*/ replaceSequence lensRepSequence, /*number best fit lenses*/ unsigned numberBestFitLenses)
{
	unsigned int nextLensNoToReplace{};
	std::vector<OptSysEle_Merit_LensType> optSysEle_Merit_LensType_vec;

	unsigned int counter = 0;
	unsigned maxOptSys = numberBestFitLenses * mParameterLenses.size();
	mReplacedOptSysEle_vec.resize(maxOptSys);
	for (unsigned int i = 0; i < mParameterLenses.size(); ++i)
	{

		if (lensRepSequence == replaceSequence::leftToRight)
		{
			nextLensNoToReplace = i;
		}

		if (lensRepSequence == replaceSequence::RightToLeft)
		{
			// DOIT
		}

		if (lensRepSequence == replaceSequence::maxSeidelAberLens)
		{
			// DOIT
		}

		if (lensRepSequence == replaceSequence::minSeidelAberLens)
		{
			// DOIT
		}

		optSysEle_Merit_LensType_vec = checkLensCatalogsForBestFitLenses_many(/*lens number*/nextLensNoToReplace, /*parameter lens*/ mParameterLenses[nextLensNoToReplace],/*number best fit lenses*/ numberBestFitLenses);

		for (unsigned int numberLens = 0; numberLens < optSysEle_Merit_LensType_vec.size(); ++numberLens)
		{
			replaceLens(nextLensNoToReplace, optSysEle_Merit_LensType_vec[numberLens].getOptSysEle());
			// debug
			//oftenUse::print(mOpticalSystemEle_replaceLens, 550.0);

			adjustThicknessesAccordingToFixed();
			//oftenUse::print(mOpticalSystemEle_replaceLens, 550.0);

			mReplacedOptSysEle_vec[counter] = mOpticalSystemEle_replaceLens.getDeepCopyOptSysEle();
			++counter;
		}
	}


}

void LensReplace::checkForThicknessVariablesInSurroundingMaterialAndAdjust()
{
	unsigned int sizeOptSys = mOpticalSystemEle.getPosAndElement().size();
	mOpticalSystemEle.setRefractiveIndexAccordingToWavelength(550.0);
	real refIndexSurroundingMaterial = oftenUse::getStartRefIndex(mOpticalSystemEle.getLLTconversion_doConversion());
	typeModifier tempTypeModifyThickness{};

	for (unsigned int i = 0; i < sizeOptSys; ++i)
	{
		tempTypeModifyThickness = mOpticalSystemEle.getPosAndElement()[i].getElementInOptSys_ptr()->getPointTypeModifier_Z();

		if (tempTypeModifyThickness == typeModifier::typeModifierVariable)
		{

		}
	}

}