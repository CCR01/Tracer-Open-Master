#include "LensReplace.h"
#include "..\oftenUseNamespace\oftenUseNamespace.h"

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
real defaultPara_LensReplace_struct::getMinDefaut_percent()
{
	return mMinDefault;
}
void defaultPara_LensReplace_struct::setMinDefault_percent(real minDefault)
{
	mMinDefault = minDefault;
}

// max default
real defaultPara_LensReplace_struct::getMaxDefaut_percent()
{
	return mMaxDefault;
}
void defaultPara_LensReplace_struct::setMaxDefault_percent(real maxDefault)
{
	mMaxDefault = maxDefault;
}

// load default parameter
void defaultPara_LensReplace_struct::loadDefaultPara(unsigned int NoLenses)
{
	// load default catalog
	std::vector<lensTypes> CatalogToLoad;
	CatalogToLoad.push_back(lensTypes::posAchromat);
	mCatalotToLoad_default = CatalogToLoad;

	setMinDefault_percent(10.0);
	setMaxDefault_percent(10.0);

	setFocalLenght_weight(1.0);
	setTickness_weight(1.0);
	setSemiHeight_weight(1.0);

	// load default min percent
	mMin_default_percent.resize(NoLenses);
	std::fill(mMin_default_percent.begin(), mMin_default_percent.end(), mMinDefault);

	// load default max percent
	mMax_default_percent.resize(NoLenses);
	std::fill(mMax_default_percent.begin(), mMax_default_percent.end(), mMaxDefault);

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
		mPrefLensType_vec[i].setPrefensType(lensTypes::posAchromat);
		mPrefLensType_vec[i].setFactor(1.5);
	}

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
void defaultPara_LensReplace_struct::setMinPercent_surface_i(unsigned int surfaceNo, real percentMin)
{
	mMin_default_percent[surfaceNo] = percentMin;
}
real defaultPara_LensReplace_struct::getMinPercent_surface_i(unsigned int surfaceNo)
{
	return mMin_default_percent[surfaceNo];
}

// max percent
void defaultPara_LensReplace_struct::setMaxPercent_surface_i(unsigned int surfaceNo, real percentMax)
{
	mMax_default_percent[surfaceNo] = percentMax;
}
real defaultPara_LensReplace_struct::getMaxPercent_surface_i(unsigned int surfaceNo)
{
	return mMax_default_percent[surfaceNo];
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

LensReplace::LensReplace(){}
LensReplace::~LensReplace(){}


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
	mOpticalSystem_LLT = mOpticalSystemEle.getLLTconversion_doConversion();
	mOptSysLLT_lenses_vec = findLensesInOptSys_LLT(mOpticalSystem_LLT);
	mNoLenses = mOptSysLLT_lenses_vec.size();
	mDefaultPara_LensReplace.loadDefaultPara(mNoLenses);
	mParameterLenses = calcParameterLenses(mOptSysLLT_lenses_vec);
}

void LensReplace::replaceSuperFuction()
{
	mOptSysLLT_lenses_vec = findLensesInOptSys_LLT(mOpticalSystem_LLT);
	mNoLenses = mOptSysLLT_lenses_vec.size();
	mDefaultPara_LensReplace.loadDefaultPara(mNoLenses);
	mParameterLenses = calcParameterLenses(mOptSysLLT_lenses_vec);
}

void LensReplace::setOptSys_LLT(OpticalSystem_LLT optSys_LLT)
{
	mOpticalSystem_LLT = optSys_LLT;
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
	return (100- percent) * value / 100;
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
	bool load_DConvexL = findCatalog(mLoadLensCatalogEO, lensTypes::DConvexL);
	if (load_DConvexL)
	{
		mEOLensCatalog.loadLensCatalogEO_double_convex_lenses();
		mAll_DoubleConvexLenses = mEOLensCatalog.getAll_DoubleConvexLenses();
	}
	//posAchromat
	bool load_posAchromat = findCatalog(mLoadLensCatalogEO, lensTypes::posAchromat);
	if (load_posAchromat)
	{
		mEOLensCatalog.loadLensCatalogEO_achroamticLensesMgF();
		mAll_AchromaticLensesMgF = mEOLensCatalog.getAll_achroamticLensesMgF();
	}
	//PConvexL
	bool load_PConvexL = findCatalog(mLoadLensCatalogEO, lensTypes::PConvexL);
	if (load_PConvexL)
	{
		mEOLensCatalog.loadLensCatalogEO_plan_convex_lenses_VIS_NIR();
		mAll_PlanConvexLenses = mEOLensCatalog.getAll_PlanConvexLenses();
	}
	//DConcavL
	bool load_DConcavL = findCatalog(mLoadLensCatalogEO, lensTypes::DConcavL);
	if (load_DConcavL)
	{
		mEOLensCatalog.loadLensCatalogEO_double_concav_lenses_VIS_NIR();
		mAll_DoubleConcavLenses = mEOLensCatalog.getAll_DoubleConcavLenses();
	}
	//PConcavL
	bool load_PConcavL = findCatalog(mLoadLensCatalogEO, lensTypes::PConcavL);
	if (load_PConcavL)
	{
		mEOLensCatalog.loadLensCatalogEO_plan_concav_lenses_VIS_NIR();
		mAll_PlanConcavLenses = mEOLensCatalog.getAll_PlanConcavLenses();

	}
	   
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

	return - 1 / systemMatrix[0][1];
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

// find lenses in optical system
std::vector<OpticalSystem_LLT> LensReplace::findLensesInOptSys_LLT(OpticalSystem_LLT optSys_LLT)
{
	std::vector<OpticalSystem_LLT> optSys_lenses_LLT_vec;
	real tolerance = 0.0001;

	OpticalSystem_LLT tempOptSys_lens_LLT;

	unsigned sizeOptSys = optSys_LLT.getPosAndInteractingSurface().size();

	// surfaces before
	std::shared_ptr<SurfaceIntersectionRay_LLT> Surface_ptr_before = optSys_LLT.getPosAndInteractingSurface()[0].getSurfaceInterRay_ptr();
	real direction_Z_before = Surface_ptr_before->getDirection().getZ();
	real refIndex_A_before = Surface_ptr_before->getRefractiveIndex_A();
	real refIndex_B_before = Surface_ptr_before->getRefractiveIndex_B();

	unsigned int tempPos;

	if(std::abs(refIndex_A_before - 1.0) > tolerance || std::abs(refIndex_B_before - 1.0) > tolerance)
	{ 
		tempPos = optSys_LLT.getPosAndInteractingSurface()[0].getPosition();
		tempOptSys_lens_LLT.fillVectorSurfaceAndInteractingData(tempPos, Surface_ptr_before, optSys_LLT.getPosAndInteraction()[0].getInteractionAtSur_ptr());
	}

	// surfaces after
	std::shared_ptr<SurfaceIntersectionRay_LLT> Surface_ptr_temp;
	real direction_Z_temp;
	real refIndex_A_temp;
	real refIndex_B_temp;
	
	bool isThereALens = true;
	unsigned int sizeTempLens;
	std::shared_ptr<InteractionRay_LLT> Interaction_ptr_temp;
	real refIndexAir = 1.0;

	for (unsigned int i = 1; i < sizeOptSys; ++i)
	{
		tempPos = optSys_LLT.getPosAndInteractingSurface()[i].getPosition();
		Surface_ptr_temp = optSys_LLT.getPosAndInteractingSurface()[i].getSurfaceInterRay_ptr();
		direction_Z_temp = Surface_ptr_temp->getDirection().getZ();
		refIndex_A_temp = Surface_ptr_temp->getRefractiveIndex_A();
		refIndex_B_temp = Surface_ptr_temp->getRefractiveIndex_B();

		Interaction_ptr_temp = optSys_LLT.getPosAndInteraction()[i].getInteractionAtSur_ptr();

		// lens type 0
		if (direction_Z_before > 0 && direction_Z_temp < 0)
		{
			if((refIndex_B_before - refIndexAir) < tolerance && (refIndex_B_temp -refIndexAir) < tolerance && tempOptSys_lens_LLT.getPosAndInteractingSurface().size() > 0) // there is no lens
			{
				optSys_lenses_LLT_vec.push_back(tempOptSys_lens_LLT);
				tempOptSys_lens_LLT.clean_optSys_LLT();
			}
			
			if (std::abs(refIndex_B_before - refIndex_B_temp) < tolerance) // there is a lens
			{
				sizeTempLens = tempOptSys_lens_LLT.getPosAndInteractingSurface().size();
				tempOptSys_lens_LLT.fillVectorSurfaceAndInteractingData(tempPos, Surface_ptr_temp, Interaction_ptr_temp);
			}
		}

		// lens type 1
		else if (direction_Z_before < 0 && direction_Z_temp < 0)
		{
			if ((refIndex_A_before - refIndexAir) < tolerance && (refIndex_B_temp - refIndexAir) < tolerance && tempOptSys_lens_LLT.getPosAndInteractingSurface().size() > 0) // there is no lens
			{
				optSys_lenses_LLT_vec.push_back(tempOptSys_lens_LLT);
				tempOptSys_lens_LLT.clean_optSys_LLT();
			}

			if (std::abs(refIndex_A_before - refIndex_B_temp) < tolerance) // there is a lens
			{
				sizeTempLens = tempOptSys_lens_LLT.getPosAndInteractingSurface().size();
				tempOptSys_lens_LLT.fillVectorSurfaceAndInteractingData(tempPos, Surface_ptr_temp, Interaction_ptr_temp);
			}

		}

		// lens type 2
		else if (direction_Z_before > 0 && direction_Z_temp > 0)
		{
			if ((refIndex_B_before - refIndexAir) < tolerance && (refIndex_A_temp - refIndexAir) < tolerance && tempOptSys_lens_LLT.getPosAndInteractingSurface().size()>0) // there is no lens
			{
				optSys_lenses_LLT_vec.push_back(tempOptSys_lens_LLT);
				tempOptSys_lens_LLT.clean_optSys_LLT();
			}
			
			if (std::abs(refIndex_B_before - refIndex_A_temp) < tolerance) // there is a lens
			{
				sizeTempLens = tempOptSys_lens_LLT.getPosAndInteractingSurface().size();
				tempOptSys_lens_LLT.fillVectorSurfaceAndInteractingData(tempPos, Surface_ptr_temp, Interaction_ptr_temp);
			}

		}

		// lens type 3
		else if (direction_Z_before < 0 && direction_Z_temp > 0)
		{
			if ((refIndex_A_before - refIndexAir) < tolerance && (refIndex_A_temp - refIndexAir) < tolerance && tempOptSys_lens_LLT.getPosAndInteractingSurface().size() > 0) // there is no lens
			{
				optSys_lenses_LLT_vec.push_back(tempOptSys_lens_LLT);
				tempOptSys_lens_LLT.clean_optSys_LLT();
			}

			if (std::abs(refIndex_A_before - refIndex_A_temp) < tolerance) // there is a lens
			{
				sizeTempLens = tempOptSys_lens_LLT.getPosAndInteractingSurface().size();
				tempOptSys_lens_LLT.fillVectorSurfaceAndInteractingData(tempPos, Surface_ptr_temp, Interaction_ptr_temp);
			}

		}

		// surfaces before
		Surface_ptr_before = Surface_ptr_temp;
		direction_Z_before = direction_Z_temp;
		refIndex_A_before = refIndex_A_temp;
		refIndex_B_before = refIndex_B_temp;

	}

	if (optSys_lenses_LLT_vec.size() == 0)
	{
		optSys_lenses_LLT_vec.push_back(tempOptSys_lens_LLT);
	}

	return optSys_lenses_LLT_vec;
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

		minPercent = mDefaultPara_LensReplace.getMinPercent_surface_i(i);
		maxPercent = mDefaultPara_LensReplace.getMaxPercent_surface_i(i);

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


OptSysEle_Merit_LensType LensReplace::findOptSysEle_lens_inCatalog_TwoSurfaces(parameterLens paraLens, std::vector<LensesTwoSurfaces> AllLensesTwoSurfaces, real weightFocal, real weightThickness, real weightSemiHeight)
{

	OptSysEle_Merit_LensType returnOptSysEle_Merit;

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
	real tempMerit;
	std::vector<real> allMeritLenses;
	allMeritLenses.resize(numberLenses);

	for (unsigned int i = 0; i < numberLenses; ++i)
	{
		focalLenghtCatLens_temp = AllLensesTwoSurfaces[i].getFocalLength();
		semiHeightCatLens_temp = AllLensesTwoSurfaces[i].getDiameter() / 2.0;
		thicknessCatLens_temp = AllLensesTwoSurfaces[i].getThickness();

		tempMerit = calcualteMerit_lens(focaLengthParam, minFocalLengthParam, maxFocalLengthParam, weightFocal, thicknessParam, minThicknessParam, maxThicknessParam, weightThickness, semiHeightParam, minSemiHeightParam, maxSemiHeightParam, weightSemiHeight, focalLenghtCatLens_temp, thicknessCatLens_temp, semiHeightCatLens_temp);

		allMeritLenses[i] = tempMerit;
	}
	
	unsigned int posLowestMertitFalue = Math::posMinValueInVector(allMeritLenses);
	real returnMerit= Math::minValueOfVector(allMeritLenses);

	if (Math::checkValuesHeigherThan(99999999999.0, allMeritLenses))
	{
		std::cout << "no lens fit the recirements" << std::endl;
	}



	OpticalSystemElement returnOptSysEle = AllLensesTwoSurfaces[posLowestMertitFalue].getHLT_TwoSurfaces().getDeepCopyOptSysEle();
	std::string catalog = AllLensesTwoSurfaces[posLowestMertitFalue].getLensCatalog();
	unsigned int catalogNumer = AllLensesTwoSurfaces[posLowestMertitFalue].getCatalogNumber();
	//std::string nameBestFitLens = AllLensesTwoSurfaces[posLowestMertitFalue].get

	returnOptSysEle_Merit.setOpticalSystemEle(returnOptSysEle);
	returnOptSysEle_Merit.setMerit(returnMerit);
	returnOptSysEle_Merit.setCatalogNumber(catalogNumer);
	returnOptSysEle_Merit.setLensCatalog(catalog);

	return returnOptSysEle_Merit;
}

OptSysEle_Merit_LensType LensReplace::findOptSysEle_lens_inCatalog_ThreeSurfaces(parameterLens paraLens, std::vector<LensThreeSurfaces> AllLensesThreeSurfaces, real weightFocal, real weightThickness, real weightSemiHeight)
{
	OptSysEle_Merit_LensType returnOptSysEle_Merit;

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
	real tempMerit;
	std::vector<real> allMeritLenses;
	allMeritLenses.resize(numberLenses);

	for (unsigned int i = 0; i < numberLenses; ++i)
	{
		focalLenghtCatLens_temp = AllLensesThreeSurfaces[i].getFocalLength();
		semiHeightCatLens_temp = AllLensesThreeSurfaces[i].getDiameter() / 2.0;
		thicknessCatLens_temp = AllLensesThreeSurfaces[i].getFirstThickness() + AllLensesThreeSurfaces[i].getSecondThickness();

		tempMerit = calcualteMerit_lens(focaLengthParam, minFocalLengthParam, maxFocalLengthParam, weightFocal, thicknessParam, minThicknessParam, maxThicknessParam, weightThickness, semiHeightParam, minSemiHeightParam, maxSemiHeightParam, weightSemiHeight, focalLenghtCatLens_temp, thicknessCatLens_temp, semiHeightCatLens_temp);

		allMeritLenses[i] = tempMerit;
	}

	unsigned int posLowestMertitFalue = Math::posMinValueInVector(allMeritLenses);
	real returnMerit = Math::minValueOfVector(allMeritLenses);

	if (Math::checkValuesHeigherThan(99999999999.0, allMeritLenses))
	{
		std::cout << "no lens fit the recirements" << std::endl;
	}


	OpticalSystemElement returnOptSysEle = AllLensesThreeSurfaces[posLowestMertitFalue].getHLT_ThreeSurfaces().getDeepCopyOptSysEle();
	std::string lensCatalog = AllLensesThreeSurfaces[posLowestMertitFalue].getLensCatalog();
	unsigned int lensNumber = AllLensesThreeSurfaces[posLowestMertitFalue].getCatalogNumber();

	returnOptSysEle_Merit.setOpticalSystemEle(returnOptSysEle);
	returnOptSysEle_Merit.setMerit(returnMerit);
	returnOptSysEle_Merit.setLensCatalog(lensCatalog);
	returnOptSysEle_Merit.setCatalogNumber(lensNumber);

	return returnOptSysEle_Merit;
}

real LensReplace::calcualteMerit(real target, real is, real weight)
{
	return weight * std::abs((target - is) / target);
}



real LensReplace::calcualteMerit_lens(real focalParam, real minFocalParam, real maxFocalParam, real focalWeight, real thicknessParam, real minThicknessParam, real maxThicknessParam, real thicknessWeight, real semiHeightParam, real minSemiHeightParam, real maxSemiHeightParam, real semiHeightWeight, real focalTemp,real thicknessTemp, real semiHeightTemp)
{
	real veryHeighNumber = oftenUse::getInfReal();

	real returnMeritLens;
	real meritFocalLenght = veryHeighNumber;
	real meritThickness = veryHeighNumber;
	real meritSeminHeight = veryHeighNumber;

	bool fitFocalLenght = false;
	bool fitThickness = false;
	bool fitSemiHeight = false;

	// check focal lenght
	if(minFocalParam < focalTemp < maxFocalParam)
	{
		meritFocalLenght = calcualteMerit(focalParam, focalTemp, focalWeight);
		fitFocalLenght = true;
	}
	// check thickness
	if(minThicknessParam < thicknessTemp < maxThicknessParam)
	{
		meritThickness = calcualteMerit(thicknessParam, thicknessTemp, thicknessWeight);
		fitThickness = true;
	}
	// check semi Height
	if (minSemiHeightParam < semiHeightTemp < maxSemiHeightParam)
	{
		meritSeminHeight = calcualteMerit(semiHeightParam, semiHeightTemp, semiHeightWeight);
		fitSemiHeight = true;
	}
	

	if (fitFocalLenght && fitThickness && fitSemiHeight)
	{
		returnMeritLens = meritFocalLenght + meritThickness + meritSeminHeight;
	}
	else
	{
		return veryHeighNumber;
	}
	

	return returnMeritLens;
}

OptSysEle_Merit_LensType LensReplace::checkLensCatalogsForBestFitLens(/*number lens*/ unsigned int lensNo,/*parameter lens*/ parameterLens paraLens)
{
	real veryHeighNumber = oftenUse::getInfReal();
	std::vector<OptSysEle_Merit_LensType> OptSysEleMertit_LensType_vec;

	OptSysEle_Merit_LensType DConvexL_opt_mertir_type;
	DConvexL_opt_mertir_type.setMerit(veryHeighNumber);
	OptSysEle_Merit_LensType PosAchromat_opt_mertir_type;
	PosAchromat_opt_mertir_type.setMerit(veryHeighNumber);
	OptSysEle_Merit_LensType PConvexL_opt_mertir_type;
	PConvexL_opt_mertir_type.setMerit(veryHeighNumber);
	OptSysEle_Merit_LensType DConcavL_opt_mertir_type;
	DConcavL_opt_mertir_type.setMerit(veryHeighNumber);
	OptSysEle_Merit_LensType PConcavL_opt_mertir_type;
	PConcavL_opt_mertir_type.setMerit(veryHeighNumber);


	real weightFocal = mDefaultPara_LensReplace.getWeightFocalLengthSurface_i(lensNo);
	real weightThickness = mDefaultPara_LensReplace.getWeightThicknessSurface_i(lensNo);
	real weightSemiHeight = mDefaultPara_LensReplace.getWeightSemiHeightSurface_i(lensNo);

	lensTypes prefLensType = mDefaultPara_LensReplace.getPrefLensTyeAndFactorSurface_i(lensNo).getPrefLensType();
	real prefFactor = mDefaultPara_LensReplace.getPrefLensTyeAndFactorSurface_i(lensNo).getFactor();

	//DConvexL
	bool load_DConvexL = findCatalog(mLoadLensCatalogEO, lensTypes::DConvexL);
	if (load_DConvexL)
	{
		DConvexL_opt_mertir_type = findOptSysEle_lens_inCatalog_TwoSurfaces(paraLens, mAll_DoubleConvexLenses, weightFocal, weightThickness, weightSemiHeight);
		DConvexL_opt_mertir_type.setLensType(lensTypes::DConvexL);
		if (prefLensType == lensTypes::DConvexL)
		{
			DConvexL_opt_mertir_type.setMerit(DConvexL_opt_mertir_type.getMerit() / prefFactor);
		}

		OptSysEleMertit_LensType_vec.push_back(DConvexL_opt_mertir_type);
	}
	//posAchromat
	bool load_posAchromat = findCatalog(mLoadLensCatalogEO, lensTypes::posAchromat);

	if (load_posAchromat)
	{
		PosAchromat_opt_mertir_type = findOptSysEle_lens_inCatalog_ThreeSurfaces(paraLens, mAll_AchromaticLensesMgF, weightFocal, weightThickness, weightSemiHeight);
		PosAchromat_opt_mertir_type.setLensType(lensTypes::posAchromat);
		if (prefLensType == lensTypes::posAchromat)
		{
			PosAchromat_opt_mertir_type.setMerit(PosAchromat_opt_mertir_type.getMerit() / prefFactor);
		}

		OptSysEleMertit_LensType_vec.push_back(PosAchromat_opt_mertir_type);
	}
	//PConvexL
	bool load_PConvexL = findCatalog(mLoadLensCatalogEO, lensTypes::PConvexL);
	if (load_PConvexL)
	{
		PConvexL_opt_mertir_type = findOptSysEle_lens_inCatalog_TwoSurfaces(paraLens, mAll_PlanConvexLenses, weightFocal, weightThickness, weightSemiHeight);
		PConvexL_opt_mertir_type.setLensType(lensTypes::PConvexL);
		if (prefLensType == lensTypes::PConvexL)
		{
			PConvexL_opt_mertir_type.setMerit(PConvexL_opt_mertir_type.getMerit() / prefFactor);
		}

		OptSysEleMertit_LensType_vec.push_back(PConvexL_opt_mertir_type);
	}
	//DConcavL
	bool load_DConcavL = findCatalog(mLoadLensCatalogEO, lensTypes::DConcavL);
	if (load_DConcavL)
	{
		DConcavL_opt_mertir_type = findOptSysEle_lens_inCatalog_TwoSurfaces(paraLens, mAll_DoubleConcavLenses, weightFocal, weightThickness, weightSemiHeight);
		DConcavL_opt_mertir_type.setLensType(lensTypes::DConcavL);
		if (prefLensType == lensTypes::DConcavL)
		{
			DConcavL_opt_mertir_type.setMerit(DConcavL_opt_mertir_type.getMerit() / prefFactor);
		}
		OptSysEleMertit_LensType_vec.push_back(DConcavL_opt_mertir_type);
	}
	//PConcavL
	bool load_PConcavL = findCatalog(mLoadLensCatalogEO, lensTypes::PConcavL);
	if (load_PConcavL)
	{
		PConcavL_opt_mertir_type = findOptSysEle_lens_inCatalog_TwoSurfaces(paraLens, mAll_PlanConcavLenses, weightFocal, weightThickness, weightSemiHeight);
		PConcavL_opt_mertir_type.setLensType(lensTypes::PConcavL);
		if (prefLensType == lensTypes::DConcavL)
		{
			PConcavL_opt_mertir_type.setMerit(PConcavL_opt_mertir_type.getMerit() / prefFactor);
		}
		OptSysEleMertit_LensType_vec.push_back(PConcavL_opt_mertir_type);
	}

	return getBestOptSys(OptSysEleMertit_LensType_vec);
}


OptSysEle_Merit_LensType LensReplace::getBestOptSys(std::vector<OptSysEle_Merit_LensType> optSysEle_merit_lensType_vec)
{
	unsigned int numOptSys = optSysEle_merit_lensType_vec.size();
	real bestMeritValue = optSysEle_merit_lensType_vec[0].getMerit();
	OpticalSystemElement bestOptSysEle = optSysEle_merit_lensType_vec[0].getOptSysEle();
	
	unsigned int counter = 0;

	real tempMeritValue;
	for (unsigned int i = 1; i < numOptSys; ++i)
	{
		tempMeritValue = optSysEle_merit_lensType_vec[i].getMerit();

		if (tempMeritValue < bestMeritValue)
		{
			bestMeritValue = tempMeritValue;
			counter = i;
		}
	}

	return optSysEle_merit_lensType_vec[counter];
}

void LensReplace::replaceLens(unsigned int lensNo, OpticalSystemElement fillInOptSysEle)
{
	std::vector<unsigned int> lensNumbersToReplace;
	unsigned int posLensToReplace;
	unsigned int size = mOptSysLLT_lenses_vec[lensNo].getPosAndInteractingSurface().size();

	for (unsigned int i = 0; i < size; ++i)
	{
		posLensToReplace = mOptSysLLT_lenses_vec[lensNo].getPosAndInteractingSurface()[i].getPosition();
		lensNumbersToReplace.push_back(posLensToReplace);
	}

	
	real pos_Z_firstSurface = mOpticalSystemEle.getPosAndElement()[lensNumbersToReplace[0]].getElementInOptSys_ptr()->getPointElementValue_Z();
	// calc thicknessToPos0
	std::vector<real> thicknesToSurface0;
	thicknesToSurface0.push_back(0.0);
	real thicknessBefore;
	real tempThicknessTotal;
	for (unsigned int i = 1; i < lensNumbersToReplace.size(); ++i)
	{
		tempThicknessTotal = fillInOptSysEle.getPosAndElement()[i].getElementInOptSys_ptr()->getPointElementValue_Z();
		thicknesToSurface0.push_back(tempThicknessTotal);
	}

	
	int lastPos = lensNumbersToReplace.back();
	mOpticalSystemEle.delSurfaceNumber_from_TO(lensNumbersToReplace[0], lastPos);

	for(unsigned int i=0; i< lensNumbersToReplace.size();++i)
	{ 
		fillInOptSysEle.getPosAndElement()[i].getElementInOptSys_ptr()->setPointElementValue_Z(pos_Z_firstSurface + thicknesToSurface0[i]);
		mOpticalSystemEle.fillInElementAndInteractionAtPos_i(lensNumbersToReplace[i], fillInOptSysEle.getPosAndElement()[i].getElementInOptSys_ptr(), fillInOptSysEle.getPosAndInteraction_LLT()[i].getInteractionAtSur_ptr());

	}

}

void LensReplace::saveFixedThicknessesLenses()
{
	real surroundingrefractiveIndex = 1.0;
	// surfaces before
	std::shared_ptr<SurfaceIntersectionRay_LLT> Surface_ptr_before = mOpticalSystem_LLT.getPosAndInteractingSurface()[0].getSurfaceInterRay_ptr();
	// position of first surface must be fixed
	mThicknessesLenses_vec_Fixed.push_back(Surface_ptr_before->getPoint().getZ());

	unsigned int sizeOptSys = mOpticalSystem_LLT.getPosAndInteractingSurface().size();

	std::shared_ptr<SurfaceIntersectionRay_LLT> tempSurface_ptr;
	for (unsigned int i = 0; i < sizeOptSys; ++i)
	{
		//tempSurface_ptr

		// hier gehts dann weiter!!!
		// wir müssten die Abstände zwischen den Linsen nach der Ersetung konstant lassen
		// falls refIndex A || redIndex B == surroundingrefractiveIndex --> muss der Abstand gespeichert werden
		// speichere alle Abstände zwischen den Linsen um diese nach der Ersetzung einzustellen!
	}



}

OpticalSystemElement LensReplace::getOpticalSysEle()
{
	return mOpticalSystemEle;
}