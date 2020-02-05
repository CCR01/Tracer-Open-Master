#include "EvaluateManyOptSystems_SeidelCoef.h"

#include "..\LowLevelTracing\Math_LLT.h"
#include "..\Analyse\Seidel Coefficients.h"


real settingsMeritFct_SeidelCoef::getSeidelSum() const
{
	return mSeidelSum;
}
void settingsMeritFct_SeidelCoef::setSeidelSum(const real seidelSUM)
{
	mSeidelSum = seidelSUM;
}
real settingsMeritFct_SeidelCoef::getWeightSeidelSUM() const
{
	return mWeightSeidelSum;
}
void settingsMeritFct_SeidelCoef::setWeightSeidelSUM(const real weightSeidelSum)
{
	mWeightSeidelSum = weightSeidelSum;
}

real settingsMeritFct_SeidelCoef::getSum_S1_sphere() const
{
	return mSum_S1_sphere;
}
void settingsMeritFct_SeidelCoef::setSum_S1_sphere(const real Sum_S1_sphere)
{
	mSum_S1_sphere = Sum_S1_sphere;
}
real settingsMeritFct_SeidelCoef::getWeight_S1_sphere() const
{
	return mWeight_S1_sphere;
}
void settingsMeritFct_SeidelCoef::setWeight_S1_sphere(const real Weight_S1_sphere)
{
	mWeight_S1_sphere = Weight_S1_sphere;
}

real settingsMeritFct_SeidelCoef::getSum_S2_coma() const
{
	return mSum_S2_coma;
}
void settingsMeritFct_SeidelCoef::setSum_S2_coma(const real Sum_S2_coma)
{
	mSum_S2_coma = Sum_S2_coma;
}
real settingsMeritFct_SeidelCoef::getWeight_S2_coma() const
{
	return mWeight_S2_coma;
}
void settingsMeritFct_SeidelCoef::setWeight_S2_coma(const real Weight_S2_coma)
{
	mWeight_S2_coma = Weight_S2_coma;
}

real settingsMeritFct_SeidelCoef::getSum_S3_astigmatism() const
{
	return mSum_S3_astigmatism;
}
void settingsMeritFct_SeidelCoef::setSum_S3_astigmatism(const real Sum_S3_astigmatism)
{
	mSum_S3_astigmatism = Sum_S3_astigmatism;
}
real settingsMeritFct_SeidelCoef::getWeight_S3_astigmatism() const
{
	return mWeight_S3_astigmatism;
}
void settingsMeritFct_SeidelCoef::setWeight_S3_astigmatism(const real Weight_S3_astigmatism)
{
	mWeight_S3_astigmatism = Weight_S3_astigmatism;
}

real settingsMeritFct_SeidelCoef::getSum_S4_fieldCurvature() const
{
	return mSum_S4_fieldCurvature;
}
void settingsMeritFct_SeidelCoef::setSum_S4_fieldCurvature(const real Sum_S4_fieldCurvature)
{
	mSum_S4_fieldCurvature = Sum_S4_fieldCurvature;
}
real settingsMeritFct_SeidelCoef::getWeight_S4_fieldCurvature() const
{
	return mWeight_S4_fieldCurvature;
}
void settingsMeritFct_SeidelCoef::setWeight_S4_fieldCurvature(const real Weight_S4_fieldCurvature)
{
	mWeight_S4_fieldCurvature = Weight_S4_fieldCurvature;
}

real settingsMeritFct_SeidelCoef::getSum_S5_distortion() const
{
	return mSum_S5_distortion;
}
void settingsMeritFct_SeidelCoef::setSum_S5_distortion(const real Sum_S5_distortion)
{
	mSum_S5_distortion = Sum_S5_distortion;
}
real settingsMeritFct_SeidelCoef::getWeight_S5_distortion() const
{
	return mWeight_S5_distortion;
}
void settingsMeritFct_SeidelCoef::setWeight_S5_distortion(const real Weight_S5_distortion)
{
	mWeight_S5_distortion = Weight_S5_distortion;
}

real settingsMeritFct_SeidelCoef::getSum_S6_C1_axialColor() const
{
	return mSum_S6_C1_axialColor;
}
void settingsMeritFct_SeidelCoef::setSum_S6_C1_axialColor(const real Sum_S6_C1_axialColor)
{
	mSum_S6_C1_axialColor = Sum_S6_C1_axialColor;
}
real settingsMeritFct_SeidelCoef::getWeight_S6_C1_axialColor() const
{
	return mWeight_S6_C1_axialColor;
}
void settingsMeritFct_SeidelCoef::setWeight_S6_C1_axialColor(const real Weight_S6_C1_axialColor)
{
	mWeight_S6_C1_axialColor = Weight_S6_C1_axialColor;
}

real settingsMeritFct_SeidelCoef::getSum_S7_C2_lateralColor() const
{
	return mSum_S7_C2_lateralColor;
}
void settingsMeritFct_SeidelCoef::setSum_S7_C2_lateralColor(const real Sum_C2_lateralColor)
{
	mSum_S7_C2_lateralColor = Sum_C2_lateralColor;
}
real settingsMeritFct_SeidelCoef::getWeight_S7_C2_lateralColor() const
{
	return mWeight_S7_C2_lateralColor;
}
void settingsMeritFct_SeidelCoef::setWeight_S7_C2_lateralColor(const real Weight_S7_C2_lateralColor)
{
	mWeight_S7_C2_lateralColor = Weight_S7_C2_lateralColor;
}

real settingsMeritFct_SeidelCoef::getEFL() const
{
	return mEFL;
}
void settingsMeritFct_SeidelCoef::setEFL(const real efl)
{
	mEFL = efl;
}
real settingsMeritFct_SeidelCoef::getWeightEFL() const
{
	return mWeightEFL;
}
void settingsMeritFct_SeidelCoef::setWeightEFL(const real weightEFL)
{
	mWeightEFL = weightEFL;
}
real settingsMeritFct_SeidelCoef::getPP() const
{
	return mPP;
}
void settingsMeritFct_SeidelCoef::setPP(const real pp)
{
	mPP = pp;
}
real settingsMeritFct_SeidelCoef::getWeightPP() const
{
	return mWeightPP;
}
void settingsMeritFct_SeidelCoef::setWeightPP(const real weightPP)
{
	mWeightPP = weightPP;
}
real settingsMeritFct_SeidelCoef::getAntiPP() const
{
	return mAntiPP;
}
void settingsMeritFct_SeidelCoef::setAntiPP(const real antiPP)
{
	mAntiPP = antiPP;
}
real settingsMeritFct_SeidelCoef::getWeightAntiPP() const
{
	return mWeightAntiPP;
}
void settingsMeritFct_SeidelCoef::setWeightAntiPP(const real weightAntiPP)
{
	mWeightAntiPP = weightAntiPP;
}
real settingsMeritFct_SeidelCoef::getEXPP_accordingToLastSurface() const
{
	return  mEXPP_accordingToLastSurface;
}
void settingsMeritFct_SeidelCoef::setEXPP_accordingToLastSurface(const real expp_lastSurface)
{
	mEXPP_accordingToLastSurface = expp_lastSurface;
}
real settingsMeritFct_SeidelCoef::getWeightEXPP_accordingToLastSurface() const
{
	return mWeightEXPP_accordingToLastSurface;
}
void settingsMeritFct_SeidelCoef::setWeightEXPP_accordingToLastSurface(const real weightEXPP_accordingToLastSurface)
{
	mWeightEXPP_accordingToLastSurface = weightEXPP_accordingToLastSurface;
}
real settingsMeritFct_SeidelCoef::getEXPP_global() const
{
	return mEXPP_inGlobalCoordinatSystem;
}
void settingsMeritFct_SeidelCoef::setEXPP_global(const real exppGlobal)
{
	mEXPP_inGlobalCoordinatSystem = exppGlobal;
}
real settingsMeritFct_SeidelCoef::getWeightEXPP_global() const
{
	return mWeightEXPP_inGlobalCoordinatSystem;
}
void settingsMeritFct_SeidelCoef::setWeightEXPP_global(const real weightEXPP_global)
{
	mWeightEXPP_inGlobalCoordinatSystem = weightEXPP_global;
}

real settingsMeritFct_SeidelCoef::getEXPD() const
{
	return mEXPD;
}
void settingsMeritFct_SeidelCoef::setEXPD(const real expd)
{
	mEXPD = expd;
}
real settingsMeritFct_SeidelCoef::getWeightEXPD() const
{
	return mWeightEXPD;
}
void settingsMeritFct_SeidelCoef::setWeightEXPD(const real weightEXPD)
{
	mWeightEXPD = weightEXPD;
}
real settingsMeritFct_SeidelCoef::getMag() const
{
	return mMag;
}
void settingsMeritFct_SeidelCoef::setMag(const real mag)
{
	mMag = mag;
}
real settingsMeritFct_SeidelCoef::getWeightMag() const
{
	return mWeightMag;
}
void settingsMeritFct_SeidelCoef::setWeightMag(const real weightMag)
{
	mWeightMag = weightMag;
}



EvaluateManyOptSystems_SeidelCoef::EvaluateManyOptSystems_SeidelCoef() {};

EvaluateManyOptSystems_SeidelCoef::~EvaluateManyOptSystems_SeidelCoef() {};

EvaluateManyOptSystems_SeidelCoef::EvaluateManyOptSystems_SeidelCoef(OpticalSystemElement optSysEle, std::vector<stepsWithoutMinWithoutMax> addInfosVariables, std::vector<VectorStructR3> fields, std::vector<real> wavelenght_vec) :
	mOptSysEle(optSysEle),
	mAddInfosVariables(addInfosVariables),
	mFields(fields),
	mWavelenght_vec(wavelenght_vec)
{
	mPrimeWavelength = mWavelenght_vec[0];
	mOptSysEle.setRefractiveIndexAccordingToWavelength(mPrimeWavelength);
	loadDefaultSettings();
	mSystemForCombinationsElement.superFct(mOptSysEle, mAddInfosVariables, mPrimeWavelength, buildElement);
	getHeighestFieldPoint_Y();
	calcAllSeidelCoefficients(mSystemForCombinationsElement.getAllPosOptSys_Element());
	calcBestOptSys_withSysForCom();
}

EvaluateManyOptSystems_SeidelCoef::EvaluateManyOptSystems_SeidelCoef(std::vector<OpticalSystemElement> optSysEle_vec, std::vector<VectorStructR3> fields, std::vector<real> wavelenght_vec) :
	mOptSysEle_vec(optSysEle_vec),
	mFields(fields),
	mWavelenght_vec(wavelenght_vec)
{
	loadDefaultSettings();
	getHeighestFieldPoint_Y();
	calcAllSeidelCoefficients(optSysEle_vec);
}


void EvaluateManyOptSystems_SeidelCoef::loadDefaultSettings()
{

	// according to: EvaluateManyOptSystems_ParaxialDistances::loadDefaultSettingsMeritFct()
	mSettingMeritFunction.setSeidelSum(std::numeric_limits<double>::quiet_NaN());
	mSettingMeritFunction.setWeightSeidelSUM(1.0);
	mSettingMeritFunction.setSum_S1_sphere(std::numeric_limits<double>::quiet_NaN());
	mSettingMeritFunction.setWeight_S1_sphere(1.0);
	mSettingMeritFunction.setSum_S2_coma(std::numeric_limits<double>::quiet_NaN());
	mSettingMeritFunction.setWeight_S2_coma(1.0);
	mSettingMeritFunction.setSum_S3_astigmatism(std::numeric_limits<double>::quiet_NaN());
	mSettingMeritFunction.setWeight_S3_astigmatism(1.0);
	mSettingMeritFunction.setSum_S4_fieldCurvature(std::numeric_limits<double>::quiet_NaN());
	mSettingMeritFunction.setWeight_S4_fieldCurvature(1.0);
	mSettingMeritFunction.setSum_S5_distortion(std::numeric_limits<double>::quiet_NaN());
	mSettingMeritFunction.setWeight_S5_distortion(1.0);
	mSettingMeritFunction.setSum_S6_C1_axialColor(std::numeric_limits<double>::quiet_NaN());
	mSettingMeritFunction.setWeight_S6_C1_axialColor(1.0);
	mSettingMeritFunction.setSum_S7_C2_lateralColor(std::numeric_limits<double>::quiet_NaN());
	mSettingMeritFunction.setWeight_S7_C2_lateralColor(1.0);
	mSettingMeritFunction.setEFL(std::numeric_limits<double>::quiet_NaN());
	mSettingMeritFunction.setWeightEFL(0.0);
	mSettingMeritFunction.setPP(std::numeric_limits<double>::quiet_NaN());
	mSettingMeritFunction.setWeightPP(0.0);
	mSettingMeritFunction.setAntiPP(std::numeric_limits<double>::quiet_NaN());
	mSettingMeritFunction.setWeightAntiPP(0.0);
	mSettingMeritFunction.setEXPP_accordingToLastSurface(std::numeric_limits<double>::quiet_NaN());
	mSettingMeritFunction.setWeightEXPP_accordingToLastSurface(0.0);
	mSettingMeritFunction.setEXPD(std::numeric_limits<double>::quiet_NaN());
	mSettingMeritFunction.setWeightEXPD(0.0);
	mSettingMeritFunction.setEXPP_global(std::numeric_limits<double>::quiet_NaN());
	mSettingMeritFunction.setWeightEXPP_global(0.0);
	mSettingMeritFunction.setMag(std::numeric_limits<double>::quiet_NaN());
	mSettingMeritFunction.setWeightEXPP_global(0.0);

}

void EvaluateManyOptSystems_SeidelCoef::calcAllSeidelCoefficients(std::vector<OpticalSystemElement> optSysEle_vec)
{
	unsigned int length = optSysEle_vec.size();
	mAllSeidelCoefficients.resize(length);
	mAllMeritValues.resize(length);

	real tempEFFL{};
	LightRayStruct tempMarginalRay{};
	LightRayStruct tempChiefRay{};
	OpticalSystemElement tempOptSys_Ele{};
	real tempLagrangeInvariant{};
	bool tempAperInlens = 0;
	SeidelCoefficients tempSeidelCoef{};

	real tempMeritValue;

	// first we calcualte all cardinal points and merit values
	for (unsigned int i = 0; i < length; ++i)
	{
		// get temp opt sys ele
		tempOptSys_Ele = optSysEle_vec[i];
		//tempOptSys_Ele.setRefractiveIndexAccordingToWavelength(mPrimeWavelength);
		// TODO: we just need the EFFL to calculate the seidel coeffizients 
		// -> write a function that just calc the EFFL and not all cardinal points --> TOD CR: DO that later!
		// ***calc EFL
		CardinalPoints tempCardinal(tempOptSys_Ele.getOptSys_LLT_buildSystem());
		tempEFFL = tempCardinal.getEFL();

		// *** calc marginal ray
		tempMarginalRay = findMarginalRay_obj(tempOptSys_Ele);

		// *** calc cheif ray
		tempChiefRay = findChiefRay_obj(tempOptSys_Ele);

		// *** calc lagrange invariant
		tempLagrangeInvariant = calcLagrangeInvariant(tempMarginalRay);

		// *** calc pos Aper Stop
		unsigned int posAperStop = tempOptSys_Ele.getOptSys_LLT_buildSystem().getPosApertureStop();

		// *** calc temp seidel coef
		tempSeidelCoef.calcSeidelCoef_superFuction(tempOptSys_Ele, tempChiefRay, tempMarginalRay, mWavelenght_vec, posAperStop, tempEFFL, tempLagrangeInvariant, tempAperInlens);

		mAllSeidelCoefficients[i] = tempSeidelCoef;

		tempMeritValue = calcMeritValue(tempSeidelCoef, tempCardinal);

		mAllMeritValues[i] = tempMeritValue;
	}

}

real EvaluateManyOptSystems_SeidelCoef::calcMeritValue(SeidelCoefficients seidelCoef, CardinalPoints cardinaPoints)
{

	// TODO: Mayby we can set this comparsion value for every individual merid value;
	real comparisonValue = 1.0;

	real conEFL = 0;
	real conPP = 0;
	real conAntiPP = 0;
	real conEXPP_accordingToLastSurface = 0;
	real conEXPP_inGlobalCoordinatSystem = 0;
	real conEXPD = 0;
	real conMag = 0;


	real conSum_S1_sphere = 0;
	real conSum_S2_coma = 0;
	real conSum_S3_astigmatism = 0;
	real conSum_S4_fieldCurvature = 0;
	real conSum_S5_distortion = 0;
	real conSum_S6_C1_axialColor = 0;
	real conSum_S7_C2_lateralColor = 0;

	real conSeidelSum = 0;

	// EFL
	if (std::isnan(mSettingMeritFunction.getEFL()))
	{
		mSettingMeritFunction.setWeightEFL(0.0);
	}
	else
	{
		conEFL = calcContributionMerit(mSettingMeritFunction.getWeightEFL(), mSettingMeritFunction.getEFL(), cardinaPoints.getEFL(), comparisonValue);
	}

	// PP
	if (std::isnan(mSettingMeritFunction.getPP()))
	{
		mSettingMeritFunction.setWeightPP(0.0);
	}
	else
	{
		conPP = calcContributionMerit(mSettingMeritFunction.getWeightPP(), mSettingMeritFunction.getPP(), cardinaPoints.getPrincipaPlan(), comparisonValue);
	}

	// AntiPP
	if (std::isnan(mSettingMeritFunction.getAntiPP()))
	{
		mSettingMeritFunction.setWeightAntiPP(0.0);
	}
	else
	{
		conAntiPP = calcContributionMerit(mSettingMeritFunction.getWeightAntiPP(), mSettingMeritFunction.getAntiPP(), cardinaPoints.getAntiPP(), comparisonValue);
	}

	// EXPP_accordingToLastSurface
	if (std::isnan(mSettingMeritFunction.getEXPP_accordingToLastSurface()))
	{
		mSettingMeritFunction.setWeightEXPP_accordingToLastSurface(0.0);
	}
	else
	{
		conEXPP_accordingToLastSurface = calcContributionMerit(mSettingMeritFunction.getWeightEXPP_accordingToLastSurface(), mSettingMeritFunction.getEXPP_accordingToLastSurface(), cardinaPoints.getExitPupilPosition_lastSurface(), comparisonValue);
	}

	// EXPP_inGlobalCoordinatSystem
	if (std::isnan(mSettingMeritFunction.getEXPP_global()))
	{
		mSettingMeritFunction.setWeightEXPP_global(0.0);
	}
	else
	{
		conEXPP_inGlobalCoordinatSystem = calcContributionMerit(mSettingMeritFunction.getWeightEXPP_global(), mSettingMeritFunction.getEXPP_global(), cardinaPoints.getExitPupilPosition_globalCoori(), comparisonValue);
	}

	// EXPD
	if (std::isnan(mSettingMeritFunction.getEXPD()))
	{
		mSettingMeritFunction.setWeightEXPD(0.0);
	}
	else
	{
		conEXPD = calcContributionMerit(mSettingMeritFunction.getWeightEXPD(), mSettingMeritFunction.getEXPD(), cardinaPoints.getExitPupilDiameter(), comparisonValue);
	}

	// conMag
	if (std::isnan(mSettingMeritFunction.getMag()))
	{
		mSettingMeritFunction.setWeightMag(0.0);
	}
	else
	{
		conMag = calcContributionMerit(mSettingMeritFunction.getWeightMag(), mSettingMeritFunction.getMag(), cardinaPoints.getMagnification(), comparisonValue);
	}


	// S1
	if (std::isnan(mSettingMeritFunction.getSum_S1_sphere()))
	{
		conSum_S1_sphere = mSettingMeritFunction.getWeight_S1_sphere() * seidelCoef.getS1sum()*comparisonValue;
	}
	else
	{
		conSum_S1_sphere = mSettingMeritFunction.getWeight_S1_sphere() * mSettingMeritFunction.getSum_S1_sphere() * comparisonValue;
	}

	// S2
	if (std::isnan(mSettingMeritFunction.getSum_S2_coma()))
	{
		conSum_S2_coma = mSettingMeritFunction.getWeight_S2_coma() * seidelCoef.getS2sum()*comparisonValue;
	}
	else
	{
		conSum_S2_coma = mSettingMeritFunction.getWeight_S2_coma() * mSettingMeritFunction.getSum_S2_coma() * comparisonValue;
	}

	// S3
	if (std::isnan(mSettingMeritFunction.getSum_S3_astigmatism()))
	{
		conSum_S3_astigmatism = mSettingMeritFunction.getWeight_S3_astigmatism() * seidelCoef.getS3sum()*comparisonValue;
	}
	else
	{
		conSum_S3_astigmatism = mSettingMeritFunction.getWeight_S3_astigmatism() * mSettingMeritFunction.getSum_S3_astigmatism() * comparisonValue;
	}

	// S4
	if (std::isnan(mSettingMeritFunction.getSum_S4_fieldCurvature()))
	{
		conSum_S4_fieldCurvature = mSettingMeritFunction.getWeight_S4_fieldCurvature() * seidelCoef.getS4sum()*comparisonValue;
	}
	else
	{
		conSum_S4_fieldCurvature = mSettingMeritFunction.getWeight_S4_fieldCurvature() * mSettingMeritFunction.getSum_S4_fieldCurvature() * comparisonValue;
	}

	// S5
	if (std::isnan(mSettingMeritFunction.getSum_S5_distortion()))
	{
		conSum_S5_distortion = mSettingMeritFunction.getWeight_S5_distortion() * seidelCoef.getS5sum()*comparisonValue;
	}
	else
	{
		conSum_S5_distortion = mSettingMeritFunction.getWeight_S5_distortion() * mSettingMeritFunction.getSum_S5_distortion() * comparisonValue;
	}

	// S6_C1
	if (std::isnan(mSettingMeritFunction.getSum_S6_C1_axialColor()))
	{
		conSum_S6_C1_axialColor = mSettingMeritFunction.getWeight_S6_C1_axialColor() * seidelCoef.getS6C1sum()*comparisonValue;
	}
	else
	{
		conSum_S6_C1_axialColor = mSettingMeritFunction.getWeight_S6_C1_axialColor() * mSettingMeritFunction.getSum_S6_C1_axialColor() * comparisonValue;
	}
	// S7_C2
	if (std::isnan(mSettingMeritFunction.getSum_S7_C2_lateralColor()))
	{
		conSum_S7_C2_lateralColor = mSettingMeritFunction.getWeight_S7_C2_lateralColor() * seidelCoef.getS7C2sum()*comparisonValue;
	}
	else
	{
		conSum_S7_C2_lateralColor = mSettingMeritFunction.getWeight_S7_C2_lateralColor() * mSettingMeritFunction.getSum_S7_C2_lateralColor() * comparisonValue;
	}


	if (std::isnan(mSettingMeritFunction.getSeidelSum()))
	{
		conSeidelSum = mSettingMeritFunction.getWeightSeidelSUM() * (conSum_S1_sphere + conSum_S2_coma + conSum_S3_astigmatism + conSum_S4_fieldCurvature + conSum_S5_distortion + conSum_S6_C1_axialColor + conSum_S7_C2_lateralColor) * comparisonValue;
	}
	else
	{
		conSeidelSum = mSettingMeritFunction.getWeightSeidelSUM() * mSettingMeritFunction.getSeidelSum()*comparisonValue;
	}


	real tempMeritValue = conEFL + conPP + conAntiPP + conEXPP_accordingToLastSurface + conEXPP_inGlobalCoordinatSystem + conEXPD + conMag + conSum_S1_sphere + conSum_S2_coma + conSum_S3_astigmatism +
		conSum_S4_fieldCurvature + conSum_S5_distortion + conSum_S6_C1_axialColor + conSum_S7_C2_lateralColor + conSeidelSum;

	return tempMeritValue;
}



///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void EvaluateManyOptSystems_SeidelCoef::getHeighestFieldPoint_Y()
{
	mHeighestFieldPoint = mFields[0];
	real tempFiledPoint_Y = 0;

	for (unsigned int i = 1; i < mFields.size(); ++i)
	{
		tempFiledPoint_Y = mFields[i].getY();

		if (tempFiledPoint_Y > mHeighestFieldPoint.getY())
		{
			mHeighestFieldPoint = mFields[i];
		}

	}

}

LightRayStruct EvaluateManyOptSystems_SeidelCoef::findMarginalRay_obj(OpticalSystemElement optSys_Ele)
{

	// find position apterture stop
	OpticalSystem_LLT tempOptSys_LLT = optSys_Ele.getOptSys_LLT_buildSystem();
	unsigned int posApertureStop = tempOptSys_LLT.getPosApertureStop();

	// find semi height aperture stop
	real semiHeightApertureStop = tempOptSys_LLT.getPosAndInteractingSurface()[posApertureStop].getSurfaceInterRay_ptr()->getSemiHeight();

	// find point aperture stop
	VectorStructR3 pointAperStop = tempOptSys_LLT.getPosAndInteractingSurface()[posApertureStop].getSurfaceInterRay_ptr()->getPoint();

	// build marginal ray
	VectorStructR3 startPointMarginalRay = { 0.0,0.0,0.0 };
	real BoundaryAperStop_Y = pointAperStop.getY() + semiHeightApertureStop;

	VectorStructR3 BoundaryPointAperStop = pointAperStop;
	BoundaryPointAperStop.setY(BoundaryAperStop_Y);



	// *** ATTENTION *** ///
	// -> if the aperture stop is not the first surface, we have to do ray aiming to find the marginal ray
	// -> TODO: implement ray aiming to fint direction of margina ray!
	VectorStructR3 directionMarginaRay = BoundaryPointAperStop - startPointMarginalRay;
	// *** --- *** ///


	Ray_LLT marginalRay(/*origin*/ startPointMarginalRay,/*direction*/directionMarginaRay,/*refractive index*/ 1.0);

	Light_LLT light;
	light.setWavelength(mWavelenght_vec[0]);
	light.setIntensity(1.0);
	light.setIsAlive(1);

	LightRayStruct tempMarginalRay(light, marginalRay, 1.0);

	return tempMarginalRay;

}

LightRayStruct EvaluateManyOptSystems_SeidelCoef::findChiefRay_obj(OpticalSystemElement optSys_Ele)
{
	// find position apterture stop
	OpticalSystem_LLT tempOptSys_LLT = optSys_Ele.getOptSys_LLT_buildSystem();
	unsigned int posApertureStop = tempOptSys_LLT.getPosApertureStop();

	// find point aperture stop
	VectorStructR3 pointAperStop = tempOptSys_LLT.getPosAndInteractingSurface()[posApertureStop].getSurfaceInterRay_ptr()->getPoint();

	// build chief ray
	VectorStructR3 startPointChiefRay = mHeighestFieldPoint;

	// *** ATTENTION *** ///
	// -> if the aperture stop is not the first surface, we have to do ray aiming to find the chief ray
	// -> TODO: implement ray aiming to fint direction of chief ray!
	VectorStructR3 directionChiefRay = pointAperStop - startPointChiefRay;
	// *** --- *** ///


	Ray_LLT chiefRay(/*origin*/ startPointChiefRay,/*direction*/directionChiefRay,/*refractive index*/ 1.0);

	Light_LLT light;
	light.setWavelength(mWavelenght_vec[0]);
	light.setIntensity(1.0);
	light.setIsAlive(1);

	LightRayStruct tempChiefRay(light, chiefRay, 1.0);

	return tempChiefRay;
}

real EvaluateManyOptSystems_SeidelCoef::calcLagrangeInvariant(LightRayStruct marginalLightRay)
{
	real lagrangeInvariant;
	real refractiveIndexinFrontOfApertureStop = 1.0;

	// TODO: find a methode to check if the lagrage invariant is neg or pos? -> set prefix!
	real marginalRay_angle = -marginalLightRay.getRay_LLT().getDirectionRayUnit().getY() / marginalLightRay.getRay_LLT().getDirectionRayUnit().getZ();

	lagrangeInvariant = refractiveIndexinFrontOfApertureStop * mHeighestFieldPoint.getY() * marginalRay_angle;

	return lagrangeInvariant;
}

real EvaluateManyOptSystems_SeidelCoef::calcContributionMerit(real const& weight, real const& targetValue, real const& currentValue, real const& comparsion)
{
	return weight * std::abs((targetValue - currentValue) / targetValue) / comparsion;
}


void EvaluateManyOptSystems_SeidelCoef::calcBestOptSys_withSysForCom()
{
	// find smallest merit value
	//mAllMeritValues

	int posBestMeritValue;
	real minMeritValue;

	std::vector<real>::iterator resultMin = std::min_element(std::begin(mAllMeritValues), std::end(mAllMeritValues));
	posBestMeritValue = std::distance(std::begin(mAllMeritValues), resultMin);
	minMeritValue = mAllMeritValues.at(posBestMeritValue);

	// find system to smallest merit Value
	mBestOptSys = mSystemForCombinationsElement.getAllPosOptSys_Element()[posBestMeritValue].getOpticalSystemElement();

}

OpticalSystemElement EvaluateManyOptSystems_SeidelCoef::calcBestOptSys_OptSysVec()
{
	// find smallest merit value
	//mAllMeritValues

	int posBestMeritValue;
	real minMeritValue;

	std::vector<real>::iterator resultMin = std::min_element(std::begin(mAllMeritValues), std::end(mAllMeritValues));
	posBestMeritValue = std::distance(std::begin(mAllMeritValues), resultMin);
	minMeritValue = mAllMeritValues.at(posBestMeritValue);

	// find system to smallest merit Value
	OpticalSystemElement returnBestOptSys = mOptSysEle_vec[posBestMeritValue].getOpticalSystemElement();

	return returnBestOptSys;

}

OpticalSystemElement EvaluateManyOptSystems_SeidelCoef::getBestOptSys()
{
	return mBestOptSys;
}
