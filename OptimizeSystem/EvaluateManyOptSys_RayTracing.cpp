#include "EvaluateManyOptSystems_RayTracing.h"

#include "..\SequentialRayTracing\SequentialRayTracer.h"
#include <iostream>

// interpoints last surface
std::vector<VectorStructR3> InterPointsLastSurfaceAndCheckVignetting::getInterPointsLastSurface() const
{
	return mInterPointsLastSurface;
}
void InterPointsLastSurfaceAndCheckVignetting::setInterPointsLastSurface(const std::vector<VectorStructR3>& interpointsLastSurface)
{
	mInterPointsLastSurface = interpointsLastSurface;
}

// vignetting
bool InterPointsLastSurfaceAndCheckVignetting::getIsVignetting()
{
	return mIsVignetting;
}
void InterPointsLastSurfaceAndCheckVignetting::setIsVignetting(bool isVignetting)
{
	mIsVignetting = isVignetting;
}

real settingsMeritFct_RayTracing::getEFL() const
{
	return mEFL;
}
void settingsMeritFct_RayTracing::setEFL(const real efl)
{
	mEFL = efl;
}

// light
Light_LLT settingsMeritFct_RayTracing::getLight(unsigned int number)
{
	return mLightVec[number];
}
void settingsMeritFct_RayTracing::setLight(unsigned int number, Light_LLT light)
{
	mLightVec[number] = light;
}

real settingsMeritFct_RayTracing::getWeightEFL() const
{
	return mWeightEFL;
}
void settingsMeritFct_RayTracing::setWeightEFL(const real weightEFL)
{
	mWeightEFL = weightEFL;
}
real settingsMeritFct_RayTracing::getPP() const
{
	return mPP;
}
void settingsMeritFct_RayTracing::setPP(const real pp)
{
	mPP = pp;
}
real settingsMeritFct_RayTracing::getWeightPP() const
{
	return mWeightPP;
}
void settingsMeritFct_RayTracing::setWeightPP(const real weightPP)
{
	mWeightPP = weightPP;
}
real settingsMeritFct_RayTracing::getAntiPP() const
{
	return mAntiPP;
}
void settingsMeritFct_RayTracing::setAntiPP(const real antiPP)
{
	mAntiPP = antiPP;
}
real settingsMeritFct_RayTracing::getWeightAntiPP() const
{
	return mWeightAntiPP;
}
void settingsMeritFct_RayTracing::setWeightAntiPP(const real weightAntiPP)
{
	mWeightAntiPP = weightAntiPP;
}
real settingsMeritFct_RayTracing::getEXPP_accordingToLastSurface() const
{
	return  mEXPP_accordingToLastSurface;
}
void settingsMeritFct_RayTracing::setEXPP_accordingToLastSurface(const real expp_lastSurface)
{
	mEXPP_accordingToLastSurface = expp_lastSurface;
}
real settingsMeritFct_RayTracing::getWeightEXPP_accordingToLastSurface() const
{
	return mWeightEXPP_accordingToLastSurface;
}
void settingsMeritFct_RayTracing::setWeightEXPP_accordingToLastSurface(const real weightEXPP_accordingToLastSurface)
{
	mWeightEXPP_accordingToLastSurface = weightEXPP_accordingToLastSurface;
}
real settingsMeritFct_RayTracing::getEXPP_global() const
{
	return mEXPP_inGlobalCoordinatSystem;
}
void settingsMeritFct_RayTracing::setEXPP_global(const real exppGlobal)
{
	mEXPP_inGlobalCoordinatSystem = exppGlobal;
}
real settingsMeritFct_RayTracing::getWeightEXPP_global() const
{
	return mWeightEXPP_inGlobalCoordinatSystem;
}
void settingsMeritFct_RayTracing::setWeightEXPP_global(const real weightEXPP_global)
{
	mWeightEXPP_inGlobalCoordinatSystem = weightEXPP_global;
}

real settingsMeritFct_RayTracing::getEXPD() const
{
	return mEXPD;
}
void settingsMeritFct_RayTracing::setEXPD(const real expd)
{
	mEXPD = expd;
}
real settingsMeritFct_RayTracing::getWeightEXPD() const
{
	return mWeightEXPD;
}
void settingsMeritFct_RayTracing::setWeightEXPD(const real weightEXPD)
{
	mWeightEXPD = weightEXPD;
}
real settingsMeritFct_RayTracing::getMag() const
{
	return mMag;
}
void settingsMeritFct_RayTracing::setMag(const real mag)
{
	mMag = mag;
}
real settingsMeritFct_RayTracing::getWeightMag() const
{
	return mWeightMag;
}
void settingsMeritFct_RayTracing::setWeightMag(const real weightMag)
{
	mWeightMag = weightMag;
}

// rings
unsigned int settingsMeritFct_RayTracing::getRings()
{
	return mRings;
}
void settingsMeritFct_RayTracing::setRings(unsigned int rings)
{
	mRings = rings;
}
// arms
unsigned int settingsMeritFct_RayTracing::getArms()
{
	return mArms;
}
void settingsMeritFct_RayTracing::setArms(unsigned int arms)
{
	mArms = arms;
}
// field
unsigned int settingsMeritFct_RayTracing::getWeightField(unsigned int number)
{
	return mWeightFieldsVec[number];
}
void settingsMeritFct_RayTracing::setWeightField(unsigned int number, unsigned int weight)
{
	mWeightFieldsVec[number] = weight;
}
// wavelength
unsigned int settingsMeritFct_RayTracing::getWeightWavelength(unsigned int number)
{ 
	return mWeightWavelengthVec[number];
}	

void settingsMeritFct_RayTracing::setWeightWavelength(unsigned int number, unsigned int weight)
{
	mWeightWavelengthVec[number] = weight;
}

void settingsMeritFct_RayTracing::resizeVector(/*number wavelenght*/ unsigned int numWave, /*number fields*/ unsigned int numField)
{
	mLightVec.resize(numWave);
	mWeightWavelengthVec.resize(numWave);
	mWeightFieldsVec.resize(numField);
	
}

EvaluateManyOptSys_RayTracing::EvaluateManyOptSys_RayTracing() {}

EvaluateManyOptSys_RayTracing::~EvaluateManyOptSys_RayTracing() {}

EvaluateManyOptSys_RayTracing::EvaluateManyOptSys_RayTracing(OpticalSystemElement optSysEle, std::vector<stepsWithoutMinWithoutMax> addInfosVariables, std::vector<VectorStructR3> fields, std::vector<real> wavelenght_vec) :
mOptSysEle(optSysEle),
mAddInfosVariables(addInfosVariables),
mFields(fields),
mWavelenght_vec(wavelenght_vec)
{
	mPrimeWavelength = mWavelenght_vec[0];
	mOptSysEle.setRefractiveIndexAccordingToWavelength(mPrimeWavelength);
	loadDefaultSettings();
	mSystemForCombinationsElement.superFct(mOptSysEle, mAddInfosVariables, mPrimeWavelength, buildElement);
	calcMetitValueAllOptSys();
	findBestOptSys();

}


void EvaluateManyOptSys_RayTracing::loadDefaultSettings()
{
	mSettingsMeritFct.resizeVector(mWavelenght_vec.size(), mFields.size());
	mSettingsMeritFct.setEFL(std::numeric_limits<double>::quiet_NaN());
	mSettingsMeritFct.setWeightEFL(0.0);
	mSettingsMeritFct.setPP(std::numeric_limits<double>::quiet_NaN());
	mSettingsMeritFct.setWeightPP(0.0);
	mSettingsMeritFct.setAntiPP(std::numeric_limits<double>::quiet_NaN());
	mSettingsMeritFct.setWeightAntiPP(0.0);
	mSettingsMeritFct.setEXPP_accordingToLastSurface(std::numeric_limits<double>::quiet_NaN());
	mSettingsMeritFct.setWeightEXPP_accordingToLastSurface(0.0);
	mSettingsMeritFct.setEXPD(std::numeric_limits<double>::quiet_NaN());
	mSettingsMeritFct.setWeightEXPD(0.0);
	mSettingsMeritFct.setEXPP_global(std::numeric_limits<double>::quiet_NaN());
	mSettingsMeritFct.setWeightEXPP_global(0.0);
	mSettingsMeritFct.setMag(std::numeric_limits<double>::quiet_NaN());
	mSettingsMeritFct.setWeightEXPP_global(0.0);

	mSettingsMeritFct.setRings(6);
	mSettingsMeritFct.setArms(8);
	





	unsigned int numberField = mFields.size();
	for (unsigned int i = 0; i < numberField; ++i)
	{
		mSettingsMeritFct.setWeightField(i, 1);
	}

	unsigned int numberWavelengths = mWavelenght_vec.size();
	for (unsigned int i = 0; i < numberWavelengths; ++i)
	{
		mSettingsMeritFct.setWeightWavelength(i, 1);

		JonesVector_LLT tempJones(0.0, 0.0, 0.0, 0.0);
		typeLight tempType = typeLightRay;
		Light_LLT tempLight_LLT(mWavelenght_vec[i], 1.0, tempJones, tempType, 1);

		mSettingsMeritFct.setLight(i,tempLight_LLT);

	}

}


real EvaluateManyOptSys_RayTracing::calcMeritValue(real conRMS, OpticalSystemElement optSysEle)
{	

	// TODO write a function to check wheater we have to calculat the cardinal points!
	// --> to save calculation time
	CardinalPoints cardinalPoints(optSysEle.getOptSys_LLT_buildSystem());

	// TODO: Mayby we can set this comparsion value for every individual merid value;
	real comparisonValue = 1.0;

	real conEFL = 0;
	real conPP = 0;
	real conAntiPP = 0;
	real conEXPP_accordingToLastSurface = 0;
	real conEXPP_inGlobalCoordinatSystem = 0;
	real conEXPD = 0;
	real conMag = 0;

	// EFL
	if (std::isnan(mSettingsMeritFct.getEFL()))
	{
		mSettingsMeritFct.setWeightEFL(0.0);
	}
	else
	{
		conEFL = calcContributionMerit(mSettingsMeritFct.getWeightEFL(), mSettingsMeritFct.getEFL(), cardinalPoints.getEFL(), comparisonValue);
	}

	// PP
	if (std::isnan(mSettingsMeritFct.getPP()))
	{
		mSettingsMeritFct.setWeightPP(0.0);
	}
	else
	{
		conPP = calcContributionMerit(mSettingsMeritFct.getWeightPP(), mSettingsMeritFct.getPP(), cardinalPoints.getPrincipaPlan(), comparisonValue);
	}

	// AntiPP
	if (std::isnan(mSettingsMeritFct.getAntiPP()))
	{
		mSettingsMeritFct.setWeightAntiPP(0.0);
	}
	else
	{
		conAntiPP = calcContributionMerit(mSettingsMeritFct.getWeightAntiPP(), mSettingsMeritFct.getAntiPP(), cardinalPoints.getAntiPP(), comparisonValue);
	}

	// EXPP_accordingToLastSurface
	if (std::isnan(mSettingsMeritFct.getEXPP_accordingToLastSurface()))
	{
		mSettingsMeritFct.setWeightEXPP_accordingToLastSurface(0.0);
	}
	else
	{
		conEXPP_accordingToLastSurface = calcContributionMerit(mSettingsMeritFct.getWeightEXPP_accordingToLastSurface(), mSettingsMeritFct.getEXPP_accordingToLastSurface(), cardinalPoints.getExitPupilPosition_lastSurface(), comparisonValue);
	}

	// EXPP_inGlobalCoordinatSystem
	if (std::isnan(mSettingsMeritFct.getEXPP_global()))
	{
		mSettingsMeritFct.setWeightEXPP_global(0.0);
	}
	else
	{
		conEXPP_inGlobalCoordinatSystem = calcContributionMerit(mSettingsMeritFct.getWeightEXPP_global(), mSettingsMeritFct.getEXPP_global(), cardinalPoints.getExitPupilPosition_globalCoori(), comparisonValue);
	}

	// EXPD
	if (std::isnan(mSettingsMeritFct.getEXPD()))
	{
		mSettingsMeritFct.setWeightEXPD(0.0);
	}
	else
	{
		conEXPD = calcContributionMerit(mSettingsMeritFct.getWeightEXPD(), mSettingsMeritFct.getEXPD(), cardinalPoints.getExitPupilDiameter(), comparisonValue);
	}

	// conMag
	if (std::isnan(mSettingsMeritFct.getMag()))
	{
		mSettingsMeritFct.setWeightMag(0.0);
	}
	else
	{
		conMag = calcContributionMerit(mSettingsMeritFct.getWeightMag(), mSettingsMeritFct.getMag(), cardinalPoints.getMagnification(), comparisonValue);
	}



	real meritValue = conEFL + conPP + conAntiPP + conEXPP_accordingToLastSurface + conEXPP_inGlobalCoordinatSystem + conEXPD + conMag + conRMS;

	return meritValue;

}

real EvaluateManyOptSys_RayTracing::calcContributionMerit(real const& weight, real const& targetValue, real const& currentValue, real const& comparsion)
{
	return weight * std::abs((targetValue - currentValue) / targetValue) / comparsion;
}

real EvaluateManyOptSys_RayTracing::doRayTracingOptlSystemAndCalcRMScon(OpticalSystemElement optSysEle)
{
	real RMSmean = 0;
	VectorStructR3 tempField;
	real tempWeightField;
	Spot tempSpot;
	unsigned lastSurface = optSysEle.getPosAndInteraction_LLT().size() - 1;

	std::vector<real> allRMS_weight;
	real tempRMS;
	real weightFieldRMS;

	unsigned int numberField = mFields.size();

	for (unsigned int i = 0; i < numberField; ++i)
	{

		tempField = mFields[i];
		tempWeightField = mSettingsMeritFct.getWeightField(i);
		SequentialRayTracing seqTrac(/*optical system element*/ optSysEle, /*start point lightRay*/tempField, /*rings*/ mSettingsMeritFct.getRings(), /*arms*/ mSettingsMeritFct.getArms(), /*refractive index TODO: what happen if the ray start in a glass???*/ 1.0, mSettingsMeritFct.getLight(i));

		// check for vignetting
		if (seqTrac.getAllInterPointsAtSurf_i(lastSurface).size() != seqTrac.getStartPoints().size())
		{
			// there must be vignetting
			return 9999999999999999999999999999999999.0; // very heigh merit value
		}

		// the first wavelength is the reference point (intersection point chief ray at the image surface)
		Spot tempSpot(seqTrac.getAllInterPointsAndIntensityAtSurface_i(lastSurface), seqTrac.getAllInterPointsAtSurf_i(lastSurface).at(0));
		tempRMS = tempSpot.getRMS_µm();
		weightFieldRMS = tempWeightField * tempRMS;
		allRMS_weight.push_back(weightFieldRMS);

	}

	for (unsigned int i = 0; i < allRMS_weight.size(); i++)
	{
		RMSmean = RMSmean + allRMS_weight.at(i);
	}


	return RMSmean;


}

void EvaluateManyOptSys_RayTracing::calcMetitValueAllOptSys()
{
	unsigned int numberOptSys = mSystemForCombinationsElement.getAllPosOptSys_Element().size();
	OpticalSystemElement tempOptSysEle{};
	real tempRMSCon{};
	real tempMerit;

	for (unsigned int i = 0; i < numberOptSys; ++i)
	{
		tempOptSysEle = mSystemForCombinationsElement.getAllPosOptSys_Element()[i].getDeepCopyOptSysEle();

		// just for debugging
		//tempOptSysEle.getOptSys_LLT_buildSystem().printAllOptSysParameter_LLT(tempOptSysEle.getOptSys_LLT_buildSystem());
		//std::cout << "calc merit from system: " << i << " total system num: " << numberOptSys << std::endl;

		tempRMSCon = doRayTracingOptlSystemAndCalcRMScon(tempOptSysEle);
		tempMerit = calcMeritValue(tempRMSCon, tempOptSysEle);

		mAllMeritValues.push_back(tempMerit);
	}

}


void EvaluateManyOptSys_RayTracing::findBestOptSys()
{
	int posBestMeritValue;
	real minMeritValue;

	std::vector<real>::iterator resultMin = std::min_element(std::begin(mAllMeritValues), std::end(mAllMeritValues));
	posBestMeritValue = std::distance(std::begin(mAllMeritValues), resultMin);
	minMeritValue = mAllMeritValues.at(posBestMeritValue);

	// find system to smallest merit Value
	mBestOptSysEle = mSystemForCombinationsElement.getAllPosOptSys_Element()[posBestMeritValue].getOpticalSystemElement();
}
OpticalSystemElement EvaluateManyOptSys_RayTracing::getBestOptSys()
{
	return mBestOptSysEle;
}

BuildSystemsForCombination EvaluateManyOptSys_RayTracing::getSysForCom()
{
	return mSystemForCombinationsElement;	
}