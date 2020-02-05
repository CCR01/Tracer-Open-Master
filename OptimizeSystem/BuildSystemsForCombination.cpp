#include "BuildSystemsForCombination.h"

// LLT surface
#include "..\LowLevelTracing\Surfaces\SphericalSurface_LLT.h"
#include "..\LowLevelTracing\Surfaces\ApertureStop_LLT.h"
#include "..\LowLevelTracing\Surfaces\PlanGeometry_LLT.h"
#include "..\LowLevelTracing\Surfaces\AsphericalSurface_LLT.h"

// Element surfaces
#include "..\SurfaceElements\SphericalElement.h"
#include "..\SurfaceElements\ApertureStopElement.h"
#include "..\SurfaceElements\PlanElement.h"
#include "..\SurfaceElements\AsphericalElement.h"

#include "..\Glasses\Glasses.h"

#include <stdio.h>



stepsWithoutMinWithoutMax::stepsWithoutMinWithoutMax() {}
stepsWithoutMinWithoutMax::stepsWithoutMinWithoutMax(unsigned int surfaceNum, real steps, real withoutMin, real withoutMax) :
	mSurfaceNum(surfaceNum),
	mSteps(steps),
	mWithoutMin(withoutMin),
	mWithoutMax(withoutMax)
{}
stepsWithoutMinWithoutMax::~stepsWithoutMinWithoutMax() {};

//get surface num
unsigned int stepsWithoutMinWithoutMax::getSurfaceNum() const&
{
	return mSurfaceNum;
}
//set surface num
void stepsWithoutMinWithoutMax::setSurfaceNum(unsigned int const& surfaceNum)
{
	mSurfaceNum = surfaceNum;
}
//get steps
real stepsWithoutMinWithoutMax::getSteps() const&
{
	return mSteps;
}
//set steps
void stepsWithoutMinWithoutMax::setSteps(real const& steps)
{
	mSteps = steps;
}
//get without min
real stepsWithoutMinWithoutMax::getWithoutMin() const&
{
	return mWithoutMin;
}
//set without min 
void stepsWithoutMinWithoutMax::setWithoutMin(real const& withoutMin)
{
	mWithoutMin = withoutMin;
}
//get without max
real stepsWithoutMinWithoutMax::getWithoutMax() const&
{
	return mWithoutMax;
}
//set without max
void stepsWithoutMinWithoutMax::setWithoutMax(real const& withoutMax)
{
	mWithoutMax = withoutMax;
}

parameterTypeModeStruct::parameterTypeModeStruct() {};
parameterTypeModeStruct::parameterTypeModeStruct(unsigned int surNum, kindOfParameter kindParam, typeModifier typeMode) :
	mSurfaceNumber(surNum),
	mKindParam(kindParam),
	mTypeMode(typeMode)
{}
parameterTypeModeStruct::~parameterTypeModeStruct() {};


unsigned int parameterTypeModeStruct::getSurfaceNum() const&
{
	return mSurfaceNumber;
}
void parameterTypeModeStruct::setSurfaceNum(unsigned int const& surfaceNum)
{
	mSurfaceNumber = surfaceNum;
}

kindOfParameter parameterTypeModeStruct::getKindParam() const&
{
	return mKindParam;
}
void parameterTypeModeStruct::setKindParam(kindOfParameter const& kindParam)
{
	mKindParam = kindParam;
}

typeModifier parameterTypeModeStruct::getTypeMode() const&
{
	return mTypeMode;
}
void parameterTypeModeStruct::setTypeMode(typeModifier const& typeMode)
{
	mTypeMode = typeMode;
}

parameterVariable parameterTypeModeStruct::getParameterVariable()
{
	return mParamVariable;
}
void parameterTypeModeStruct::setParameterVaiable(parameterVariable paraVar)
{
	mParamVariable = paraVar;
}

BuildSystemsForCombination::BuildSystemsForCombination() {}
BuildSystemsForCombination::~BuildSystemsForCombination() {}
BuildSystemsForCombination::BuildSystemsForCombination(OpticalSystemElement optSysEle, std::vector<stepsWithoutMinWithoutMax> addInfosVariable, real primWavelength, buildWhat build) :
	mOptSysEle(optSysEle),
	mAddInfosVar(addInfosVariable),
	mPrimWavelength(primWavelength),
	mBuildWhat(build)
{
	saveDistances();
	checkIfOnePositionIsVariable();
	setRefractiveIndexesAccordingToPrimWavelength();
	saveParaAndVariable();
	buildVectorPossibilitiesVar();
	checkForVariableSurfaces();
	saveVariableSurfaceNum();

	if (mBuildWhat == buildLLT)
	{
		std::cout << "build LLT combo" << std::endl;
		buildVectorForPossibleOpticalSystem_LLT();
		buildOpticalSystemCombination_superFkt_LLT();
		setAllDistances_LLT();
	}
	else if (mBuildWhat == buildElement)
	{
		std::cout << "build Element combo" << std::endl;
		buildVectorForPossibleOpticalSystem_Element();
		buildOpticalSystemCombination_superFkt_Element();
		setAllDistances_Element();


	}
	else if (mBuildWhat == buildLLT_and_Element)
	{
		// TOIT!
		std::cout << "we have to implement functions to build both" << std::endl;
	}

}

void BuildSystemsForCombination::superFct(OpticalSystemElement optSysEle, std::vector<stepsWithoutMinWithoutMax> addInfosVariable, real primWavelength, buildWhat build)
{
	mOptSysEle = optSysEle;
	mAddInfosVar = addInfosVariable;
	mPrimWavelength = primWavelength;
	mBuildWhat = build;

	saveDistances();
	checkIfOnePositionIsVariable();
	setRefractiveIndexesAccordingToPrimWavelength();
	saveParaAndVariable();
	buildVectorPossibilitiesVar();
	checkForVariableSurfaces();
	saveVariableSurfaceNum();

	if (mBuildWhat == buildLLT)
	{
		std::cout << "build LLT combo" << std::endl;
		buildVectorForPossibleOpticalSystem_LLT();
		buildOpticalSystemCombination_superFkt_LLT();
		setAllDistances_LLT();
	}
	else if (mBuildWhat == buildElement)
	{
		std::cout << "build Element combo" << std::endl;
		buildVectorForPossibleOpticalSystem_Element();
		buildOpticalSystemCombination_superFkt_Element();
		setAllDistances_Element();
	}

	else if (mBuildWhat == buildLLT_and_Element)
	{
		// TOIT!
		std::cout << "we have to implement functions to build both" << std::endl;
	}

}

void BuildSystemsForCombination::setRefractiveIndexesAccordingToPrimWavelength()
{
	unsigned int sizeOptSys = mOptSysEle.getPosAndElement().size();

	for (unsigned int i = 0; i < sizeOptSys; i++)
	{
		mOptSysEle.getPosAndElement().at(i).getElementInOptSys_ptr()->calRefIndex_A_and_B_andSet(mPrimWavelength);
	}


}

void BuildSystemsForCombination::checkForVariableSurfaces()
{
	variableSurfaces = 0;

	unsigned int size = mParamVariableStructVec.size();
	for (unsigned int i = 0; i < size; i = i + 2)
	{
		typeModifier tempModeRadius = mParamVariableStructVec.at(i).getTypeMode();
		typeModifier tempModePos = mParamVariableStructVec.at(i + 1).getTypeMode();

		if (tempModeRadius == typeModifierVariable || tempModePos == typeModifierVariable)
		{
			variableSurfaces++;
		}
	}

}

void BuildSystemsForCombination::saveParaAndVariable()
{
	unsigned int numberSurfaces = mOptSysEle.getPosAndElement().size();
	typeModifier tempRadiusMode;
	typeModifier tempPosMode;

	parameterTypeModeStruct tempParaModeStruct_Radius;
	tempParaModeStruct_Radius.setKindParam(radius);

	parameterTypeModeStruct tempParaModeStruct_Pos;
	tempParaModeStruct_Pos.setKindParam(position);

	for (unsigned int i = 0; i < numberSurfaces; i++)
	{

		tempRadiusMode = mOptSysEle.getPosAndElement().at(i).getElementInOptSys_ptr()->getRadiusTypeModifier();
		tempPosMode = mOptSysEle.getPosAndElement().at(i).getElementInOptSys_ptr()->getPointTypeModifier_Z();

		if (tempRadiusMode == typeModifierVariable && tempPosMode == typeModifierFixed)
		{
			tempParaModeStruct_Radius.setParameterVaiable(only_radius_var);
			tempParaModeStruct_Pos.setParameterVaiable(only_radius_var);
		}

		else if (tempRadiusMode == typeModifierFixed && tempPosMode == typeModifierVariable)
		{
			tempParaModeStruct_Radius.setParameterVaiable(only_position_var);
			tempParaModeStruct_Pos.setParameterVaiable(only_position_var);
		}

		else if (tempRadiusMode == typeModifierVariable && tempPosMode == typeModifierVariable)
		{
			tempParaModeStruct_Radius.setParameterVaiable(radiusAndPosition_var);
			tempParaModeStruct_Pos.setParameterVaiable(radiusAndPosition_var);
		}
		else
		{
			tempParaModeStruct_Radius.setParameterVaiable(radiusAndPosFix);
			tempParaModeStruct_Pos.setParameterVaiable(radiusAndPosFix);
		}

		tempParaModeStruct_Radius.setSurfaceNum(i);
		tempParaModeStruct_Radius.setTypeMode(tempRadiusMode);

		tempParaModeStruct_Pos.setSurfaceNum(i);
		tempParaModeStruct_Pos.setTypeMode(tempPosMode);

		mParamVariableStructVec.push_back(tempParaModeStruct_Radius);
		mParamVariableStructVec.push_back(tempParaModeStruct_Pos);



	}


}

void BuildSystemsForCombination::buildVectorPossibilitiesVar()
{
	typeModifier tempTypeMode;
	std::vector<real> tempLinearVec;
	std::vector<real> vecOneValue(1);
	kindOfParameter tempKindParam;
	unsigned int tempSurfaceNum;
	real tempValue;
	real tempMin;
	real tempMax;
	real tempWithoutMin;
	real tempWithoutMax;
	real tempSteps;
	unsigned int counterForSteps = 0;

	for (unsigned int i = 0; i < mParamVariableStructVec.size(); i++)
	{
		tempTypeMode = mParamVariableStructVec.at(i).getTypeMode();
		tempKindParam = mParamVariableStructVec.at(i).getKindParam();
		tempSurfaceNum = mParamVariableStructVec.at(i).getSurfaceNum();

		if (tempTypeMode == typeModifierVariable)
		{


			switch (tempKindParam)
			{
			case radius:
			{
				tempMin = mOptSysEle.getPosAndElement().at(tempSurfaceNum).getElementInOptSys_ptr()->getParameterRadius().getMinimum();
				tempMax = mOptSysEle.getPosAndElement().at(tempSurfaceNum).getElementInOptSys_ptr()->getParameterRadius().getMaximum();
				tempSteps = mAddInfosVar.at(counterForSteps).getSteps();
				tempWithoutMin = mAddInfosVar.at(counterForSteps).getWithoutMin();
				tempWithoutMax = mAddInfosVar.at(counterForSteps).getWithoutMax();
				tempLinearVec = Math::calcVecRealMinMaxSteps_withoutMinMax(tempMin, tempMax, tempSteps, tempWithoutMin, tempWithoutMax);

				mPossibilitiesVariables.push_back(tempLinearVec);
				counterForSteps++;

				break;
			}

			case position:
			{
				tempMin = mOptSysEle.getPosAndElement().at(tempSurfaceNum).getElementInOptSys_ptr()->getParameterPositionZ().getMinimum();
				tempMax = mOptSysEle.getPosAndElement().at(tempSurfaceNum).getElementInOptSys_ptr()->getParameterPositionZ().getMaximum();

				tempSteps = mAddInfosVar.at(counterForSteps).getSteps();
				tempWithoutMin = mAddInfosVar.at(counterForSteps).getWithoutMin();
				tempWithoutMax = mAddInfosVar.at(counterForSteps).getWithoutMax();

				tempLinearVec = Math::calcVecRealMinMaxSteps_withoutMinMax(tempMin, tempMax, tempSteps, tempWithoutMin, tempWithoutMax);
				mPossibilitiesVariables.push_back(tempLinearVec);

				counterForSteps++;

				break;
			}


			default:
				break;
			}

		}

		//		else if (tempTypeMode == typeModifierFixed)
		//		{
		//
		//			switch (tempKindParam)
		//			{
		//			case radius:
		//			{
		//				tempValue = mOptSysEle.getPosAndElement().at(tempSurfaceNum).getElementInOptSys_ptr()->getRadiusElementValue();
		//				vecOneValue.at(0) = tempValue;
		//
		//				mPossibilitiesVariables.push_back(vecOneValue);
		//
		//				break;
		//			}
		//
		//			case position:
		//			{
		//				tempValue = mOptSysEle.getPosAndElement().at(tempSurfaceNum).getElementInOptSys_ptr()->getPointElementValue_Z();
		//				vecOneValue.at(0) = tempValue;
		//
		//				mPossibilitiesVariables.push_back(vecOneValue);
		//
		//				break;
		//			}
		//
		//
		//			default:
		//				break;
		//			}
		//
		//
		//		}
		//
	}

}

void BuildSystemsForCombination::buildVectorForPossibleOpticalSystem_LLT()
{

	SphericalSurface_LLT spherSur_ptr;
	ApertureStop_LLT aperStop_ptr;
	PlanGeometry_LLT planGeo_ptr;
	AsphericalSurface_LLT asphericalSur_ptr;

	std::shared_ptr<SurfaceIntersectionRay_LLT> tempSurfacePointer;

	unsigned int numberSurfaces = mOptSysEle.getPosAndElement().size();
	typeModifier tempTypeMode_Radius;
	typeModifier tempTypeMode_Position;

	real tempRadius;
	real tempSemiHeight;
	VectorStructR3 tempPosition{ 0.0,0.0,0.0 };
	VectorStructR3 tempDirection{ 0.0,0.0,0.0 };
	real tempRefIndex_A;
	real tempRefIndex_B;

	real tempDirection_Z{};

	//SphericalSurface_LLT tempSphericalSurface_LLT;

	unsigned int counterVariables = 0;


	OpticalSystem_LLT tempOpticalSystem_LLT;

	for (unsigned int i = 0; i < numberSurfaces; i++)
	{
		tempTypeMode_Radius = mOptSysEle.getPosAndElement().at(i).getElementInOptSys_ptr()->getRadiusTypeModifier();
		tempTypeMode_Position = mOptSysEle.getPosAndElement().at(i).getElementInOptSys_ptr()->getPointTypeModifier_Z();

		if (tempTypeMode_Radius == typeModifierVariable && tempTypeMode_Position == typeModifierFixed)
		{
			tempSurfacePointer = mOptSysEle.getPosAndIntersection_LLT().at(i).getSurfaceInterRay_ptr();

			tempSemiHeight = mOptSysEle.getPosAndElement().at(i).getElementInOptSys_ptr()->getSemiHeightElementValue();
			tempPosition.setZ(mOptSysEle.getPosAndElement().at(i).getElementInOptSys_ptr()->getPointElementValue_Z());
			tempDirection.setZ(mOptSysEle.getPosAndElement().at(i).getElementInOptSys_ptr()->getDirectionElementValue_Z());
			tempRefIndex_A = mOptSysEle.getPosAndElement().at(i).getElementInOptSys_ptr()->getRefIndexValue_A();
			tempRefIndex_B = mOptSysEle.getPosAndElement().at(i).getElementInOptSys_ptr()->getRefIndexValue_B();

			std::vector<std::shared_ptr<SurfaceIntersectionRay_LLT>> vectorWithSurfacePointer;


			if (typeid(*tempSurfacePointer) == typeid(spherSur_ptr))
			{
				for (unsigned int j = 0; j < mPossibilitiesVariables.at(counterVariables).size(); j++)
				{
					std::shared_ptr<SurfaceIntersectionRay_LLT> tempSphericalSurface_LLT_ptr(new SphericalSurface_LLT);
					SphericalSurface_LLT sphericalSurface_LLT;
					tempRadius = mPossibilitiesVariables.at(counterVariables).at(j);

					tempDirection_Z = mOptSysEle.getPosAndIntersection_LLT()[i].getSurfaceInterRay_ptr()->getDirection().getZ();

					if (tempRadius < 0 && tempDirection_Z < 0
						|| tempRadius > 0 && tempDirection_Z > 0) // both have the same prefix

					{
						sphericalSurface_LLT.setSemiHeight(tempSemiHeight);
						sphericalSurface_LLT.setRadius(std::abs(tempRadius)); // just use the abs of the radius
						sphericalSurface_LLT.setPoint(tempPosition);
						sphericalSurface_LLT.setDirectionSphere(tempDirection);
						sphericalSurface_LLT.setRefractiveIndexSide_A(tempRefIndex_A);
						sphericalSurface_LLT.setRefractiveIndexSide_B(tempRefIndex_B);
						sphericalSurface_LLT.calcCenterSphereAfterRotation();
					}
					else if (tempRadius > 0 && tempDirection_Z < 0
						|| tempRadius < 0 && tempDirection_Z > 0)
					{
						sphericalSurface_LLT.setSemiHeight(tempSemiHeight);
						sphericalSurface_LLT.setRadius(std::abs(tempRadius));
						sphericalSurface_LLT.setPoint(tempPosition);
						sphericalSurface_LLT.setDirectionSphere(-1 * tempDirection); // set direction by -1
						sphericalSurface_LLT.setRefractiveIndexSide_A(tempRefIndex_B); // change the refractive indexes
						sphericalSurface_LLT.setRefractiveIndexSide_B(tempRefIndex_A);
						sphericalSurface_LLT.calcCenterSphereAfterRotation();
					}

					tempSphericalSurface_LLT_ptr = sphericalSurface_LLT.clone();

					vectorWithSurfacePointer.push_back(tempSphericalSurface_LLT_ptr);
				}
			}

			if (typeid(*tempSurfacePointer) == typeid(asphericalSur_ptr))
			{

				// TDOO here we have to build an aspherical Surface -> DOIT!!!
			}

			mVector_vectorWithSurfacePointer_LLT.push_back(vectorWithSurfacePointer);

			counterVariables++;


		}

		else if (tempTypeMode_Position == typeModifierVariable && tempTypeMode_Radius == typeModifierFixed)
		{
			tempSurfacePointer = mOptSysEle.getPosAndIntersection_LLT().at(i).getSurfaceInterRay_ptr();

			tempRadius = mOptSysEle.getPosAndElement().at(i).getElementInOptSys_ptr()->getRadiusElementValue();
			tempSemiHeight = mOptSysEle.getPosAndElement().at(i).getElementInOptSys_ptr()->getSemiHeightElementValue();
			tempDirection.setZ(mOptSysEle.getPosAndElement().at(i).getElementInOptSys_ptr()->getDirectionElementValue_Z());
			tempRefIndex_A = mOptSysEle.getPosAndElement().at(i).getElementInOptSys_ptr()->getRefIndexValue_A();
			tempRefIndex_B = mOptSysEle.getPosAndElement().at(i).getElementInOptSys_ptr()->getRefIndexValue_B();

			std::vector<std::shared_ptr<SurfaceIntersectionRay_LLT>> vectorWithSurfacePointer;


			if (typeid(*tempSurfacePointer) == typeid(spherSur_ptr))
			{
				for (unsigned int j = 0; j < mPossibilitiesVariables.at(counterVariables).size(); j++)
				{
					tempPosition.setZ(mPossibilitiesVariables.at(counterVariables).at(j));
					SphericalSurface_LLT tempSphericalSurface_LLT(tempRadius, tempSemiHeight, tempPosition, tempDirection, tempRefIndex_A, tempRefIndex_B);
					std::shared_ptr<SurfaceIntersectionRay_LLT> surface_ptr = tempSphericalSurface_LLT.clone();

					vectorWithSurfacePointer.push_back(surface_ptr);
				}
			}

			else if (typeid(*tempSurfacePointer) == typeid(aperStop_ptr))
			{
				for (unsigned int j = 0; j < mPossibilitiesVariables.at(counterVariables).size(); j++)
				{
					tempPosition.setZ(mPossibilitiesVariables.at(counterVariables).at(j));
					ApertureStop_LLT tempApertureStop(tempSemiHeight, tempPosition, tempDirection, tempRefIndex_A);
					std::shared_ptr<SurfaceIntersectionRay_LLT> surface_ptr = tempApertureStop.clone();

					vectorWithSurfacePointer.push_back(surface_ptr);
				}
			}

			else if (typeid(*tempSurfacePointer) == typeid(planGeo_ptr))
			{
				for (unsigned int j = 0; j < mPossibilitiesVariables.at(counterVariables).size(); j++)
				{
					tempPosition.setZ(mPossibilitiesVariables.at(counterVariables).at(j));
					PlanGeometry_LLT tempPlanGeo(tempSemiHeight, tempPosition, tempDirection, tempRefIndex_A, tempRefIndex_B);
					std::shared_ptr<SurfaceIntersectionRay_LLT> surface_ptr = tempPlanGeo.clone();

					vectorWithSurfacePointer.push_back(surface_ptr);
				}
			}

			if (typeid(*tempSurfacePointer) == typeid(asphericalSur_ptr))
			{

				// TDOO here we have to build an aspherical Surface -> DOIT!!!
			}



			mVector_vectorWithSurfacePointer_LLT.push_back(vectorWithSurfacePointer);
			counterVariables++;

		}

		else if (tempTypeMode_Radius == typeModifierVariable && tempTypeMode_Position == typeModifierVariable)
		{
			tempSurfacePointer = mOptSysEle.getPosAndIntersection_LLT().at(i).getSurfaceInterRay_ptr();

			tempSemiHeight = mOptSysEle.getPosAndElement().at(i).getElementInOptSys_ptr()->getSemiHeightElementValue();
			tempDirection.setZ(mOptSysEle.getPosAndElement().at(i).getElementInOptSys_ptr()->getDirectionElementValue_Z());
			tempRefIndex_A = mOptSysEle.getPosAndElement().at(i).getElementInOptSys_ptr()->getRefIndexValue_A();
			tempRefIndex_B = mOptSysEle.getPosAndElement().at(i).getElementInOptSys_ptr()->getRefIndexValue_B();

			std::vector<std::shared_ptr<SurfaceIntersectionRay_LLT>> vectorWithSurfacePointer;
			if (typeid(*tempSurfacePointer) == typeid(spherSur_ptr))
			{
				for (unsigned int j = 0; j < mPossibilitiesVariables.at(counterVariables).size(); j++)
				{
					tempRadius = mPossibilitiesVariables.at(counterVariables).at(j);

					for (unsigned int k = 0; k < mPossibilitiesVariables.at(counterVariables + 1).size(); k++)
					{
						tempPosition.setZ(mPossibilitiesVariables.at(counterVariables + 1).at(k));
						SphericalSurface_LLT sphericalSurface_LLT;
						/////////////////////////////////////////////////////////////////////
						/////////////////////////////////////////////////////////////////////
						tempDirection_Z = mOptSysEle.getPosAndIntersection_LLT()[i].getSurfaceInterRay_ptr()->getDirection().getZ();
						if (tempRadius < 0 && tempDirection_Z < 0
							|| tempRadius > 0 && tempDirection_Z > 0) // both have the same prefix
						{
							sphericalSurface_LLT.setSemiHeight(tempSemiHeight);
							sphericalSurface_LLT.setRadius(std::abs(tempRadius)); // just use the abs of the radius
							sphericalSurface_LLT.setPoint(tempPosition);
							sphericalSurface_LLT.setDirectionSphere(tempDirection);
							sphericalSurface_LLT.setRefractiveIndexSide_A(tempRefIndex_A);
							sphericalSurface_LLT.setRefractiveIndexSide_B(tempRefIndex_B);
							sphericalSurface_LLT.calcCenterSphereAfterRotation();
						}
						else if (tempRadius > 0 && tempDirection_Z < 0
							|| tempRadius < 0 && tempDirection_Z > 0)
						{
							sphericalSurface_LLT.setSemiHeight(tempSemiHeight);
							sphericalSurface_LLT.setRadius(std::abs(tempRadius));
							sphericalSurface_LLT.setPoint(tempPosition);
							sphericalSurface_LLT.setDirectionSphere(-1 * tempDirection); // set direction by -1
							sphericalSurface_LLT.setRefractiveIndexSide_A(tempRefIndex_B); // change the refractive indexes
							sphericalSurface_LLT.setRefractiveIndexSide_B(tempRefIndex_A);
							sphericalSurface_LLT.calcCenterSphereAfterRotation();
						}
						/////////////////////////////////////////////////////////////////////
						/////////////////////////////////////////////////////////////////////


						std::shared_ptr<SurfaceIntersectionRay_LLT> surface_ptr = sphericalSurface_LLT.clone();

						vectorWithSurfacePointer.push_back(surface_ptr);

					}


				}

				mVector_vectorWithSurfacePointer_LLT.push_back(vectorWithSurfacePointer);
			}

			if (typeid(*tempSurfacePointer) == typeid(asphericalSur_ptr))
			{

				// TDOO here we have to build an aspherical Surface -> DOIT!!!
			}

			counterVariables = counterVariables + 2;
		}



		else if (tempTypeMode_Radius == typeModifierFixed && tempTypeMode_Position == typeModifierFixed)
		{

			std::vector<std::shared_ptr<SurfaceIntersectionRay_LLT>> vectorWithSurfacePointer(1);
			std::shared_ptr<SurfaceIntersectionRay_LLT> tempSurfacePointer = mOptSysEle.getPosAndIntersection_LLT().at(i).getSurfaceInterRay_ptr();
			vectorWithSurfacePointer.at(0) = tempSurfacePointer;
			mVector_vectorWithSurfacePointer_LLT.push_back(vectorWithSurfacePointer);

		}


	}


}

void BuildSystemsForCombination::buildVectorForPossibleOpticalSystem_Element()
{

	SphericalElement spherSurElement_ptr;
	ApertureStopElement aperStopElement_ptr;
	PlanElement planGeoElement_ptr;
	AsphericalElement asphericalSurElement_ptr;

	std::shared_ptr<Element_CR> tempSurfaceElementPointer;

	unsigned int numberSurfaces = mOptSysEle.getPosAndElement().size();
	typeModifier tempTypeMode_Radius;
	typeModifier tempTypeMode_Position;

	real tempRadius;
	real tempSemiHeight;
	VectorStructR3 tempPosition{ 0.0,0.0,0.0 };
	VectorStructR3 tempDirection{ 0.0,0.0,0.0 };
	MaterialSellmeier1 tempRefIndex_A;
	MaterialSellmeier1 tempRefIndex_B;


	real tempDirection_Z{};

	unsigned int counterVariables = 0;


	//OpticalSystem_LLT tempOpticalSystem_LLT;

	for (unsigned int i = 0; i < numberSurfaces; i++)
	{
		tempTypeMode_Radius = mOptSysEle.getPosAndElement().at(i).getElementInOptSys_ptr()->getRadiusTypeModifier();
		tempTypeMode_Position = mOptSysEle.getPosAndElement().at(i).getElementInOptSys_ptr()->getPointTypeModifier_Z();

		if (tempTypeMode_Radius == typeModifierVariable && tempTypeMode_Position == typeModifierFixed)
		{
			//tempSurfaceElementPointer = mOptSysEle.getPosAndIntersection_LLT().at(i).getSurfaceInterRay_ptr();
			tempSurfaceElementPointer = mOptSysEle.getPosAndElement()[i].getElementInOptSys_ptr();

			tempSemiHeight = mOptSysEle.getPosAndElement().at(i).getElementInOptSys_ptr()->getSemiHeightElementValue();
			tempPosition.setZ(mOptSysEle.getPosAndElement().at(i).getElementInOptSys_ptr()->getPointElementValue_Z());
			tempDirection.setZ(mOptSysEle.getPosAndElement().at(i).getElementInOptSys_ptr()->getDirectionElementValue_Z());
			tempRefIndex_A = mOptSysEle.getPosAndElement()[i].getElementInOptSys_ptr()->getGlassA();
			tempRefIndex_B = mOptSysEle.getPosAndElement()[i].getElementInOptSys_ptr()->getGlassB();

			std::vector<std::shared_ptr<Element_CR>> vectorWithSurfacePointer;
			tempDirection_Z = mOptSysEle.getPosAndIntersection_LLT()[i].getSurfaceInterRay_ptr()->getDirection().getZ();

			if (typeid(*tempSurfaceElementPointer) == typeid(spherSurElement_ptr))
			{
				for (unsigned int j = 0; j < mPossibilitiesVariables.at(counterVariables).size(); j++)
				{
					std::shared_ptr<Element_CR> tempSphericalSurface_Element_ptr(new SphericalElement);
					SphericalElement sphericalSurface_Element;
					tempRadius = mPossibilitiesVariables.at(counterVariables).at(j);

					if (tempRadius < 0 && tempDirection_Z < 0
						|| tempRadius > 0 && tempDirection_Z > 0) // both have the same prefix
					{
						sphericalSurface_Element.setSemiHeightElementValue(tempSemiHeight);
						sphericalSurface_Element.setRadiusElementValue(std::abs(tempRadius)); // just use the abs of the radius
						sphericalSurface_Element.setPointElementValue_X(tempPosition.getX());
						sphericalSurface_Element.setPointElementValue_Y(tempPosition.getY());
						sphericalSurface_Element.setPointElementValue_Z(tempPosition.getZ());
						sphericalSurface_Element.setDirectionValue(tempDirection);
						sphericalSurface_Element.setGlassA(tempRefIndex_A);
						sphericalSurface_Element.setGlassB(tempRefIndex_B);
						//sphericalSurface_Element.calcCenterSphereAfterRotation();
					}
					else if (tempRadius > 0 && tempDirection_Z < 0
						|| tempRadius < 0 && tempDirection_Z > 0)
					{
						sphericalSurface_Element.setSemiHeightElementValue(tempSemiHeight);
						sphericalSurface_Element.setRadiusElementValue(std::abs(tempRadius));
						sphericalSurface_Element.setPointElementValue_X(tempPosition.getX());
						sphericalSurface_Element.setPointElementValue_Y(tempPosition.getY());
						sphericalSurface_Element.setPointElementValue_Z(tempPosition.getZ());
						sphericalSurface_Element.setDirectionValue(-1 * tempDirection); // set direction by -1
						sphericalSurface_Element.setGlassA(tempRefIndex_B); // change the refractive indexes
						sphericalSurface_Element.setGlassB(tempRefIndex_A);
						//sphericalSurface_Element.calcCenterSphereAfterRotation();
					}
					sphericalSurface_Element.buildSurface_LLT();
					sphericalSurface_Element.calcRefIndex_A_andSet(mPrimWavelength);
					sphericalSurface_Element.calcRefIndex_B_andSet(mPrimWavelength);
					tempSphericalSurface_Element_ptr = sphericalSurface_Element.clone();

					vectorWithSurfacePointer.push_back(tempSphericalSurface_Element_ptr);
				}
			}

			if (typeid(*tempSurfaceElementPointer) == typeid(asphericalSurElement_ptr))
			{

				// TDOO here we have to build an aspherical Surface -> DOIT!!!
			}

			mVector_vectorWithSurfacePointer_Element.push_back(vectorWithSurfacePointer);

			counterVariables++;


		}

		else if (tempTypeMode_Position == typeModifierVariable && tempTypeMode_Radius == typeModifierFixed)
		{
			//tempSurfaceElementPointer = mOptSysEle.getPosAndIntersection_LLT().at(i).getSurfaceInterRay_ptr();
			tempSurfaceElementPointer = mOptSysEle.getPosAndElement()[i].getElementInOptSys_ptr();

			tempRadius = mOptSysEle.getPosAndElement().at(i).getElementInOptSys_ptr()->getRadiusElementValue();
			tempSemiHeight = mOptSysEle.getPosAndElement().at(i).getElementInOptSys_ptr()->getSemiHeightElementValue();
			tempDirection.setZ(mOptSysEle.getPosAndElement().at(i).getElementInOptSys_ptr()->getDirectionElementValue_Z());
			tempRefIndex_A = mOptSysEle.getPosAndElement().at(i).getElementInOptSys_ptr()->getGlassA();
			tempRefIndex_B = mOptSysEle.getPosAndElement().at(i).getElementInOptSys_ptr()->getGlassB();

			std::vector<std::shared_ptr<Element_CR>> vectorWithSurfacePointer;


			if (typeid(*tempSurfaceElementPointer) == typeid(spherSurElement_ptr))
			{
				for (unsigned int j = 0; j < mPossibilitiesVariables.at(counterVariables).size(); j++)
				{
					tempPosition.setZ(mPossibilitiesVariables.at(counterVariables).at(j));
					SphericalElement tempSphericalSurface_Element(tempRadius, tempSemiHeight, tempPosition, tempDirection, tempRefIndex_A, tempRefIndex_B);
					tempSphericalSurface_Element.calcRefIndex_A_andSet(mPrimWavelength);
					tempSphericalSurface_Element.calcRefIndex_B_andSet(mPrimWavelength);
					std::shared_ptr<Element_CR> surface_ptr = tempSphericalSurface_Element.clone();

					vectorWithSurfacePointer.push_back(surface_ptr);
				}
			}

			else if (typeid(*tempSurfaceElementPointer) == typeid(aperStopElement_ptr))
			{
				for (unsigned int j = 0; j < mPossibilitiesVariables.at(counterVariables).size(); j++)
				{
					tempPosition.setZ(mPossibilitiesVariables.at(counterVariables).at(j));
					ApertureStopElement tempApertureStop(tempSemiHeight, tempPosition, tempDirection, tempRefIndex_A);
					tempApertureStop.calRefIndex_A_and_B_andSet(mPrimWavelength);

					std::shared_ptr<Element_CR> surface_ptr = tempApertureStop.clone();

					vectorWithSurfacePointer.push_back(surface_ptr);
				}
			}

			else if (typeid(*tempSurfaceElementPointer) == typeid(planGeoElement_ptr))
			{
				for (unsigned int j = 0; j < mPossibilitiesVariables.at(counterVariables).size(); j++)
				{
					tempPosition.setZ(mPossibilitiesVariables.at(counterVariables).at(j));
					PlanElement tempPlanGeoElement(tempSemiHeight, tempPosition, tempDirection, tempRefIndex_A, tempRefIndex_B);
					tempPlanGeoElement.calcRefIndex_A_andSet(mPrimWavelength);
					tempPlanGeoElement.calcRefIndex_B_andSet(mPrimWavelength);
					std::shared_ptr<Element_CR> surface_ptr = tempPlanGeoElement.clone();

					vectorWithSurfacePointer.push_back(surface_ptr);
				}
			}

			if (typeid(*tempSurfaceElementPointer) == typeid(asphericalSurElement_ptr))
			{

				// TDOO here we have to build an aspherical Surface -> DOIT!!!
			}



			mVector_vectorWithSurfacePointer_Element.push_back(vectorWithSurfacePointer);
			counterVariables++;

		}

		else if (tempTypeMode_Radius == typeModifierVariable && tempTypeMode_Position == typeModifierVariable)
		{
			//tempSurfaceElementPointer = mOptSysEle.getPosAndIntersection_LLT().at(i).getSurfaceInterRay_ptr();
			tempSurfaceElementPointer = mOptSysEle.getPosAndElement()[i].getElementInOptSys_ptr();

			tempSemiHeight = mOptSysEle.getPosAndElement().at(i).getElementInOptSys_ptr()->getSemiHeightElementValue();
			tempDirection.setZ(mOptSysEle.getPosAndElement().at(i).getElementInOptSys_ptr()->getDirectionElementValue_Z());
			tempRefIndex_A = mOptSysEle.getPosAndElement().at(i).getElementInOptSys_ptr()->getGlassA();
			tempRefIndex_B = mOptSysEle.getPosAndElement().at(i).getElementInOptSys_ptr()->getGlassB();

			std::vector<std::shared_ptr<Element_CR>> vectorWithSurfacePointer;
			if (typeid(*tempSurfaceElementPointer) == typeid(spherSurElement_ptr))
			{
				for (unsigned int j = 0; j < mPossibilitiesVariables.at(counterVariables).size(); j++)
				{
					tempRadius = mPossibilitiesVariables.at(counterVariables).at(j);

					for (unsigned int k = 0; k < mPossibilitiesVariables.at(counterVariables + 1).size(); k++)
					{
						tempPosition.setZ(mPossibilitiesVariables.at(counterVariables + 1).at(k));
						SphericalElement sphericalSurface_Element;
						/////////////////////////////////////////////////////////////////////
						/////////////////////////////////////////////////////////////////////
						tempDirection_Z = mOptSysEle.getPosAndIntersection_LLT()[i].getSurfaceInterRay_ptr()->getDirection().getZ();

						if (tempRadius < 0 && tempDirection_Z < 0
							|| tempRadius > 0 && tempDirection_Z > 0) // both have the same prefix
						{
							sphericalSurface_Element.setSemiHeightElementValue(tempSemiHeight);
							sphericalSurface_Element.setRadiusElementValue(std::abs(tempRadius)); // just use the abs of the radius
							sphericalSurface_Element.setPointElementValue_X(tempPosition.getX());
							sphericalSurface_Element.setPointElementValue_Y(tempPosition.getY());
							sphericalSurface_Element.setPointElementValue_Z(tempPosition.getZ());
							sphericalSurface_Element.setDirectionValue(tempDirection);
							sphericalSurface_Element.setGlassA(tempRefIndex_A);
							sphericalSurface_Element.setGlassB(tempRefIndex_B);
							//sphericalSurface_Element.calcCenterSphereAfterRotation();
						}
						else if (tempRadius > 0 && tempDirection_Z < 0
							|| tempRadius < 0 && tempDirection_Z > 0)
						{
							sphericalSurface_Element.setSemiHeightElementValue(tempSemiHeight);
							sphericalSurface_Element.setRadiusElementValue(std::abs(tempRadius));
							sphericalSurface_Element.setPointElementValue_X(tempPosition.getX());
							sphericalSurface_Element.setPointElementValue_Y(tempPosition.getY());
							sphericalSurface_Element.setPointElementValue_Z(tempPosition.getZ());
							sphericalSurface_Element.setDirectionValue(-1 * tempDirection); // set direction by -1
							sphericalSurface_Element.setGlassA(tempRefIndex_B); // change the refractive indexes
							sphericalSurface_Element.setGlassB(tempRefIndex_A);
							//sphericalSurface_Element.calcCenterSphereAfterRotation();
						}
						/////////////////////////////////////////////////////////////////////
						/////////////////////////////////////////////////////////////////////
						sphericalSurface_Element.buildSurface_LLT();
						sphericalSurface_Element.calcRefIndex_A_andSet(mPrimWavelength);
						sphericalSurface_Element.calcRefIndex_B_andSet(mPrimWavelength);

						std::shared_ptr<Element_CR> surface_ptr = sphericalSurface_Element.clone();

						vectorWithSurfacePointer.push_back(surface_ptr);

					}


				}

				mVector_vectorWithSurfacePointer_Element.push_back(vectorWithSurfacePointer);
			}

			if (typeid(*tempSurfaceElementPointer) == typeid(asphericalSurElement_ptr))
			{

				// TDOO here we have to build an aspherical Surface -> DOIT!!!
			}

			counterVariables = counterVariables + 2;
		}



		else if (tempTypeMode_Radius == typeModifierFixed && tempTypeMode_Position == typeModifierFixed)
		{

			std::vector<std::shared_ptr<Element_CR>> vectorWithSurfacePointer(1);
			std::shared_ptr<Element_CR> tempSurfacePointer = mOptSysEle.getPosAndElement()[i].getElementInOptSys_ptr();
			vectorWithSurfacePointer.at(0) = tempSurfacePointer;
			mVector_vectorWithSurfacePointer_Element.push_back(vectorWithSurfacePointer);

		}


	}


}

void BuildSystemsForCombination::buildOpticalSystemCombination_superFkt_LLT()
{
	unsigned int numberSurfaces = mOptSysEle.getPosAndElement().size();

	switch (numberSurfaces)
	{

	case 0:
	{
		std::cout << "there is no surface in your optical system" << std::endl;
		break;
	}

	case 1:
	{
		std::cout << "there is just one surface in your optical system" << std::endl;
		break;
	}

	case 2:
	{
		buildOpticalSystemCombination_2Surfaces_LLT();
		break;
	}

	case 3:
	{
		buildOpticalSystemCombination_3Surfaces_LLT();
		break;
	}

	case 4:
	{
		buildOpticalSystemCombination_4Surfaces_LLT();
		break;
	}
	case 5:
	{
		buildOpticalSystemCombination_5Surfaces_LLT();
		break;
	}
	case 6:
	{
		buildOpticalSystemCombination_6Surfaces_LLT();
		break;
	}
	case 7:
	{
		buildOpticalSystemCombination_7Surfaces_LLT();
		break;
	}
	case 8:
	{
		buildOpticalSystemCombination_8Surfaces_LLT();
		break;
	}
	case 9:
	{
		buildOpticalSystemCombination_9Surfaces_LLT();
		break;
	}
	case 10:
	{
		buildOpticalSystemCombination_10Surfaces_LLT();
		break;
	}
	case 11:
	{
		buildOpticalSystemCombination_11Surfaces_LLT();
		break;
	}
	case 12:
	{
		buildOpticalSystemCombination_12Surfaces_LLT();
		break;
	}
	case 13:
	{
		buildOpticalSystemCombination_13Surfaces_LLT();
		break;
	}
	case 14:
	{
		buildOpticalSystemCombination_14Surfaces_LLT();
		break;
	}
	case 15:
	{
		buildOpticalSystemCombination_15Surfaces_LLT();
		break;
	}
	case 16:
	{
		buildOpticalSystemCombination_16Surfaces_LLT();
		break;
	}
	case 17:
	{
		buildOpticalSystemCombination_17Surfaces_LLT();
		break;
	}
	case 18:
	{
		buildOpticalSystemCombination_18Surfaces_LLT();
		break;
	}
	case 19:
	{
		buildOpticalSystemCombination_19Surfaces_LLT();
		break;
	}
	case 20:
	{
		buildOpticalSystemCombination_20Surfaces_LLT();
		break;
	}

	// TODO Peter: increase that to 20 surfaces

	default:
		break;
	}


}

void BuildSystemsForCombination::buildOpticalSystemCombination_superFkt_Element()
{
	unsigned int numberSurfaces = mOptSysEle.getPosAndElement().size();

	switch (numberSurfaces)
	{

	case 0:
	{
		std::cout << "there is no surface in your optical system" << std::endl;
		break;
	}

	case 1:
	{
		std::cout << "there is just one surface in your optical system" << std::endl;
		break;
	}

	case 2:
	{
		buildOpticalSystemCombination_2Surfaces_Element();
		break;
	}

	case 3:
	{
		buildOpticalSystemCombination_3Surfaces_Element();
		break;
	}

	case 4:
	{
		buildOpticalSystemCombination_4Surfaces_Element();
		break;
	}
	case 5:
	{
		buildOpticalSystemCombination_5Surfaces_Element();
		break;
	}
	case 6:
	{
		buildOpticalSystemCombination_6Surfaces_Element();
		break;
	}
	case 7:
	{
		buildOpticalSystemCombination_7Surfaces_Element();
		break;
	}
	case 8:
	{
		buildOpticalSystemCombination_8Surfaces_Element();
		break;
	}
	case 9:
	{
		buildOpticalSystemCombination_9Surfaces_Element();
		break;
	}
	case 10:
	{
		buildOpticalSystemCombination_10Surfaces_Element();
		break;
	}
	case 11:
	{
		buildOpticalSystemCombination_11Surfaces_Element();
		break;
	}
	case 12:
	{
		buildOpticalSystemCombination_12Surfaces_Element();
		break;
	}
	case 13:
	{
		buildOpticalSystemCombination_13Surfaces_Element();
		break;
	}
	case 14:
	{
		buildOpticalSystemCombination_14Surfaces_Element();
		break;
	}
	case 15:
	{
		buildOpticalSystemCombination_15Surfaces_Element();
		break;
	}
	case 16:
	{
		buildOpticalSystemCombination_16Surfaces_Element();
		break;
	}
	case 17:
	{
		buildOpticalSystemCombination_17Surfaces_Element();
		break;
	}
	case 18:
	{
		buildOpticalSystemCombination_18Surfaces_Element();
		break;
	}
	case 19:
	{
		buildOpticalSystemCombination_19Surfaces_Element();
		break;
	}
	case 20:
	{
		buildOpticalSystemCombination_20Surfaces_Element();
		break;
	}


	default:
		break;
	}


}

void BuildSystemsForCombination::saveVariableSurfaceNum()
{

	for (unsigned int i = 0; i < mParamVariableStructVec.size(); i++)
	{
		if (mParamVariableStructVec.at(i).getTypeMode() == typeModifierVariable)
		{
			mVariableSurfaceNum.push_back(mParamVariableStructVec.at(i).getSurfaceNum());
		}
	}
}



void BuildSystemsForCombination::buildOpticalSystemCombination_2Surfaces_LLT()
{
	unsigned int numberSurfaces = mVector_vectorWithSurfacePointer_LLT.size();


	std::vector<std::shared_ptr<InteractionRay_LLT>> tempInteractions_LLT;
	OpticalSystem_LLT tempOptSys;

	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_0;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_1;


	for (unsigned int a = 0; a < mVector_vectorWithSurfacePointer_LLT.at(0).size(); a++)
	{
		surface_0 = mVector_vectorWithSurfacePointer_LLT.at(0).at(a);
		tempOptSys.fillTracingVectorSurfaces(0, surface_0);
		tempOptSys.fillTracingVectorInteraction(0, mOptSysEle.getPosAndInteraction_LLT().at(0).getInteractionAtSur_ptr());

		for (unsigned int b = 0; b < mVector_vectorWithSurfacePointer_LLT.at(1).size(); b++)
		{
			surface_1 = mVector_vectorWithSurfacePointer_LLT.at(1).at(b);
			tempOptSys.fillTracingVectorSurfaces(1, surface_1);
			tempOptSys.fillTracingVectorInteraction(1, mOptSysEle.getPosAndInteraction_LLT().at(1).getInteractionAtSur_ptr());

			mPossibleOpticalSystem_LLT.push_back(tempOptSys.clone());

			tempOptSys.cleanSurfaceAndInteractionStartAt_i(1);
		}
		//tempOptSys.cleanSurfaceAndInteractionStartAt_i(0);
	}
}

void BuildSystemsForCombination::buildOpticalSystemCombination_2Surfaces_Element()
{
	unsigned int numberSurfaces = mVector_vectorWithSurfacePointer_Element.size();
	//unsigned int numberSurfaces = mVector_vectorWithSurfacePointer_LLT.size();

	//std::vector<std::shared_ptr<InteractionRay_LLT>> tempInteractions_LLT;
	std::vector<std::shared_ptr<Element_CR>> tempInteractions_Element;
	OpticalSystemElement tempOptSysElement;
	//OpticalSystemElement tempOptSys;

	std::shared_ptr<Element_CR> surface_0;
	std::shared_ptr<Element_CR> surface_1;


	for (unsigned int a = 0; a < mVector_vectorWithSurfacePointer_Element.at(0).size(); a++)
	{
		surface_0 = mVector_vectorWithSurfacePointer_Element.at(0).at(a);
		tempOptSysElement.fillPosAndElementAndInteraction(0, surface_0, mOptSysEle.getPosAndInteraction_LLT()[0].getInteractionAtSur_ptr());
		//tempOptSys.fillTracingVectorInteraction(0, mOptSysEle.getPosAndInteraction_LLT().at(0).getInteractionAtSur_ptr());
		//tempOptSys.fillTracingVectorInteraction(0, mOptSysEle.getPosAndElement().at(0).getIneraction_ptr());
		for (unsigned int b = 0; b < mVector_vectorWithSurfacePointer_Element.at(1).size(); b++)
		{
			surface_1 = mVector_vectorWithSurfacePointer_Element.at(1).at(b);
			tempOptSysElement.fillPosAndElementAndInteraction(1, surface_1, mOptSysEle.getPosAndInteraction_LLT()[1].getInteractionAtSur_ptr());
			//tempOptSys.fillTracingVectorInteraction(1, mOptSysEle.getPosAndElement().at(1).getIneraction_ptr());
			//tempOptSys.fillTracingVectorInteraction(1, mOptSysEle.getPosAndInteraction_LLT().at(1).getInteractionAtSur_ptr());

			mPossibleOpticalSys_Element.push_back(tempOptSysElement.getDeepCopyOptSysEle());

			tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(1);
		}
		//tempOptSys.cleanSurfaceAndInteractionStartAt_i(0);
	}
}

void BuildSystemsForCombination::buildOpticalSystemCombination_3Surfaces_LLT()
{
	unsigned int numberSurfaces = mVector_vectorWithSurfacePointer_LLT.size();


	std::vector<std::shared_ptr<InteractionRay_LLT>> tempInteractions_LLT;
	OpticalSystem_LLT tempOptSys;

	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_0;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_1;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_2;


	for (unsigned int a = 0; a < mVector_vectorWithSurfacePointer_LLT.at(0).size(); a++)
	{
		surface_0 = mVector_vectorWithSurfacePointer_LLT.at(0).at(a);
		tempOptSys.fillTracingVectorSurfaces(0, surface_0);
		tempOptSys.fillTracingVectorInteraction(0, mOptSysEle.getPosAndInteraction_LLT().at(0).getInteractionAtSur_ptr());

		for (unsigned int b = 0; b < mVector_vectorWithSurfacePointer_LLT.at(1).size(); b++)
		{
			surface_1 = mVector_vectorWithSurfacePointer_LLT.at(1).at(b);
			tempOptSys.fillTracingVectorSurfaces(1, surface_1);
			tempOptSys.fillTracingVectorInteraction(1, mOptSysEle.getPosAndInteraction_LLT().at(1).getInteractionAtSur_ptr());

			for (unsigned int c = 0; c < mVector_vectorWithSurfacePointer_LLT.at(2).size(); c++)
			{
				surface_2 = mVector_vectorWithSurfacePointer_LLT.at(2).at(c);
				tempOptSys.fillTracingVectorSurfaces(2, surface_2);
				tempOptSys.fillTracingVectorInteraction(2, mOptSysEle.getPosAndInteraction_LLT().at(2).getInteractionAtSur_ptr());

				mPossibleOpticalSystem_LLT.push_back(tempOptSys.clone());

				tempOptSys.cleanSurfaceAndInteractionStartAt_i(2);
			}
			tempOptSys.cleanSurfaceAndInteractionStartAt_i(1);
		}
		//tempOptSys.cleanSurfaceAndInteractionStartAt_i(0);
	}
}

void BuildSystemsForCombination::buildOpticalSystemCombination_3Surfaces_Element()
{
	unsigned int numberSurfaces = mVector_vectorWithSurfacePointer_Element.size();
	//unsigned int numberSurfaces = mVector_vectorWithSurfacePointer_LLT.size();

	//std::vector<std::shared_ptr<InteractionRay_LLT>> tempInteractions_LLT;
	std::vector<std::shared_ptr<Element_CR>> tempInteractions_Element;
	OpticalSystemElement tempOptSysElement;
	//OpticalSystemElement tempOptSys;

	std::shared_ptr<Element_CR> surface_0;
	std::shared_ptr<Element_CR> surface_1;
	std::shared_ptr<Element_CR> surface_2;


	for (unsigned int a = 0; a < mVector_vectorWithSurfacePointer_Element.at(0).size(); a++)
	{
		//surface_0 = mVector_vectorWithSurfacePointer_LLT.at(0).at(a);
		surface_0 = mVector_vectorWithSurfacePointer_Element.at(0).at(a);
		tempOptSysElement.fillPosAndElementAndInteraction(0, surface_0, mOptSysEle.getPosAndInteraction_LLT()[0].getInteractionAtSur_ptr());

		for (unsigned int b = 0; b < mVector_vectorWithSurfacePointer_Element.at(1).size(); b++)
		{
			surface_1 = mVector_vectorWithSurfacePointer_Element.at(1).at(b);
			tempOptSysElement.fillPosAndElementAndInteraction(1, surface_1, mOptSysEle.getPosAndInteraction_LLT()[1].getInteractionAtSur_ptr());

			for (unsigned int c = 0; c < mVector_vectorWithSurfacePointer_Element.at(2).size(); c++)
			{
				surface_2 = mVector_vectorWithSurfacePointer_Element.at(2).at(c);
				tempOptSysElement.fillPosAndElementAndInteraction(2, surface_2, mOptSysEle.getPosAndInteraction_LLT()[2].getInteractionAtSur_ptr());

				mPossibleOpticalSys_Element.push_back(tempOptSysElement.getDeepCopyOptSysEle());

				tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(2);
			}
			tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(1);
		}
		//tempOptSys.cleanSurfaceAndInteractionStartAt_i(0);
	}
}

void BuildSystemsForCombination::buildOpticalSystemCombination_4Surfaces_LLT()
{
	unsigned int numberSurfaces = mVector_vectorWithSurfacePointer_LLT.size();


	std::vector<std::shared_ptr<InteractionRay_LLT>> tempInteractions_LLT;
	OpticalSystem_LLT tempOptSys;

	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_0;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_1;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_2;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_3;


	for (unsigned int a = 0; a < mVector_vectorWithSurfacePointer_LLT.at(0).size(); a++)
	{
		surface_0 = mVector_vectorWithSurfacePointer_LLT.at(0).at(a);
		tempOptSys.fillTracingVectorSurfaces(0, surface_0);
		tempOptSys.fillTracingVectorInteraction(0, mOptSysEle.getPosAndInteraction_LLT().at(0).getInteractionAtSur_ptr());

		for (unsigned int b = 0; b < mVector_vectorWithSurfacePointer_LLT.at(1).size(); b++)
		{
			surface_1 = mVector_vectorWithSurfacePointer_LLT.at(1).at(b);
			tempOptSys.fillTracingVectorSurfaces(1, surface_1);
			tempOptSys.fillTracingVectorInteraction(1, mOptSysEle.getPosAndInteraction_LLT().at(1).getInteractionAtSur_ptr());

			for (unsigned int c = 0; c < mVector_vectorWithSurfacePointer_LLT.at(2).size(); c++)
			{
				surface_2 = mVector_vectorWithSurfacePointer_LLT.at(2).at(c);
				tempOptSys.fillTracingVectorSurfaces(2, surface_2);
				tempOptSys.fillTracingVectorInteraction(2, mOptSysEle.getPosAndInteraction_LLT().at(2).getInteractionAtSur_ptr());

				for (unsigned int d = 0; d < mVector_vectorWithSurfacePointer_LLT.at(3).size(); d++)
				{
					surface_3 = mVector_vectorWithSurfacePointer_LLT.at(3).at(d);
					tempOptSys.fillTracingVectorSurfaces(3, surface_3);
					tempOptSys.fillTracingVectorInteraction(3, mOptSysEle.getPosAndInteraction_LLT().at(3).getInteractionAtSur_ptr());

					mPossibleOpticalSystem_LLT.push_back(tempOptSys.clone());

					tempOptSys.cleanSurfaceAndInteractionStartAt_i(3);
				}
				tempOptSys.cleanSurfaceAndInteractionStartAt_i(2);
			}
			tempOptSys.cleanSurfaceAndInteractionStartAt_i(1);
		}
		//tempOptSys.cleanSurfaceAndInteractionStartAt_i(0);
	}
}

void BuildSystemsForCombination::buildOpticalSystemCombination_4Surfaces_Element()
{
	unsigned int numberSurfaces = mVector_vectorWithSurfacePointer_Element.size();
	//unsigned int numberSurfaces = mVector_vectorWithSurfacePointer_LLT.size();

	//std::vector<std::shared_ptr<InteractionRay_LLT>> tempInteractions_LLT;
	std::vector<std::shared_ptr<Element_CR>> tempInteractions_Element;
	OpticalSystemElement tempOptSysElement;
	//OpticalSystemElement tempOptSys;

	std::shared_ptr<Element_CR> surface_0;
	std::shared_ptr<Element_CR> surface_1;
	std::shared_ptr<Element_CR> surface_2;
	std::shared_ptr<Element_CR> surface_3;


	for (unsigned int a = 0; a < mVector_vectorWithSurfacePointer_Element.at(0).size(); a++)
	{
		surface_0 = mVector_vectorWithSurfacePointer_Element.at(0).at(a);
		tempOptSysElement.fillPosAndElementAndInteraction(0, surface_0, mOptSysEle.getPosAndInteraction_LLT()[0].getInteractionAtSur_ptr());

		for (unsigned int b = 0; b < mVector_vectorWithSurfacePointer_Element.at(1).size(); b++)
		{
			surface_1 = mVector_vectorWithSurfacePointer_Element.at(1).at(b);
			tempOptSysElement.fillPosAndElementAndInteraction(1, surface_1, mOptSysEle.getPosAndInteraction_LLT()[1].getInteractionAtSur_ptr());


			for (unsigned int c = 0; c < mVector_vectorWithSurfacePointer_Element.at(2).size(); c++)
			{
				surface_2 = mVector_vectorWithSurfacePointer_Element.at(2).at(c);
				tempOptSysElement.fillPosAndElementAndInteraction(2, surface_2, mOptSysEle.getPosAndInteraction_LLT()[2].getInteractionAtSur_ptr());

				for (unsigned int d = 0; d < mVector_vectorWithSurfacePointer_Element.at(3).size(); d++)
				{
					surface_3 = mVector_vectorWithSurfacePointer_Element.at(3).at(d);
					tempOptSysElement.fillPosAndElementAndInteraction(3, surface_3, mOptSysEle.getPosAndInteraction_LLT()[3].getInteractionAtSur_ptr());

					mPossibleOpticalSys_Element.push_back(tempOptSysElement.getDeepCopyOptSysEle());

					tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(3);
				}
				tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(2);
			}
			tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(1);
		}
		//tempOptSys.cleanSurfaceAndInteractionStartAt_i(0);
	}
}
void BuildSystemsForCombination::buildOpticalSystemCombination_5Surfaces_LLT()
{
	unsigned int numberSurfaces = mVector_vectorWithSurfacePointer_LLT.size();


	std::vector<std::shared_ptr<InteractionRay_LLT>> tempInteractions_LLT;
	OpticalSystem_LLT tempOptSys;

	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_0;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_1;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_2;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_3;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_4;


	for (unsigned int a = 0; a < mVector_vectorWithSurfacePointer_LLT.at(0).size(); a++)
	{
		surface_0 = mVector_vectorWithSurfacePointer_LLT.at(0).at(a);
		tempOptSys.fillTracingVectorSurfaces(0, surface_0);
		tempOptSys.fillTracingVectorInteraction(0, mOptSysEle.getPosAndInteraction_LLT().at(0).getInteractionAtSur_ptr());

		for (unsigned int b = 0; b < mVector_vectorWithSurfacePointer_LLT.at(1).size(); b++)
		{
			surface_1 = mVector_vectorWithSurfacePointer_LLT.at(1).at(b);
			tempOptSys.fillTracingVectorSurfaces(1, surface_1);
			tempOptSys.fillTracingVectorInteraction(1, mOptSysEle.getPosAndInteraction_LLT().at(1).getInteractionAtSur_ptr());

			for (unsigned int c = 0; c < mVector_vectorWithSurfacePointer_LLT.at(2).size(); c++)
			{
				surface_2 = mVector_vectorWithSurfacePointer_LLT.at(2).at(c);
				tempOptSys.fillTracingVectorSurfaces(2, surface_2);
				tempOptSys.fillTracingVectorInteraction(2, mOptSysEle.getPosAndInteraction_LLT().at(2).getInteractionAtSur_ptr());

				for (unsigned int d = 0; d < mVector_vectorWithSurfacePointer_LLT.at(3).size(); d++)
				{
					surface_3 = mVector_vectorWithSurfacePointer_LLT.at(3).at(d);
					tempOptSys.fillTracingVectorSurfaces(3, surface_3);
					tempOptSys.fillTracingVectorInteraction(3, mOptSysEle.getPosAndInteraction_LLT().at(3).getInteractionAtSur_ptr());

					for (unsigned int e = 0; e < mVector_vectorWithSurfacePointer_LLT.at(4).size(); e++)
					{
						surface_4 = mVector_vectorWithSurfacePointer_LLT.at(4).at(e);
						tempOptSys.fillTracingVectorSurfaces(4, surface_4);
						tempOptSys.fillTracingVectorInteraction(4, mOptSysEle.getPosAndInteraction_LLT().at(4).getInteractionAtSur_ptr());

						mPossibleOpticalSystem_LLT.push_back(tempOptSys.clone());

						tempOptSys.cleanSurfaceAndInteractionStartAt_i(4);

					}
					tempOptSys.cleanSurfaceAndInteractionStartAt_i(3);
				}
				tempOptSys.cleanSurfaceAndInteractionStartAt_i(2);
			}
			tempOptSys.cleanSurfaceAndInteractionStartAt_i(1);
		}
		//tempOptSys.cleanSurfaceAndInteractionStartAt_i(0);
	}


}

void BuildSystemsForCombination::buildOpticalSystemCombination_5Surfaces_Element()
{
	unsigned int numberSurfaces = mVector_vectorWithSurfacePointer_Element.size();
	//unsigned int numberSurfaces = mVector_vectorWithSurfacePointer_LLT.size();

	//std::vector<std::shared_ptr<InteractionRay_LLT>> tempInteractions_LLT;
	std::vector<std::shared_ptr<Element_CR>> tempInteractions_Element;
	OpticalSystemElement tempOptSysElement;
	//OpticalSystemElement tempOptSys;

	std::shared_ptr<Element_CR> surface_0;
	std::shared_ptr<Element_CR> surface_1;
	std::shared_ptr<Element_CR> surface_2;
	std::shared_ptr<Element_CR> surface_3;
	std::shared_ptr<Element_CR> surface_4;


	for (unsigned int a = 0; a < mVector_vectorWithSurfacePointer_Element.at(0).size(); a++)
	{
		surface_0 = mVector_vectorWithSurfacePointer_Element.at(0).at(a);
		tempOptSysElement.fillPosAndElementAndInteraction(0, surface_0, mOptSysEle.getPosAndInteraction_LLT()[0].getInteractionAtSur_ptr());

		for (unsigned int b = 0; b < mVector_vectorWithSurfacePointer_Element.at(1).size(); b++)
		{
			surface_1 = mVector_vectorWithSurfacePointer_Element.at(1).at(b);
			tempOptSysElement.fillPosAndElementAndInteraction(1, surface_1, mOptSysEle.getPosAndInteraction_LLT()[1].getInteractionAtSur_ptr());

			for (unsigned int c = 0; c < mVector_vectorWithSurfacePointer_Element.at(2).size(); c++)
			{
				surface_2 = mVector_vectorWithSurfacePointer_Element.at(2).at(c);
				tempOptSysElement.fillPosAndElementAndInteraction(2, surface_2, mOptSysEle.getPosAndInteraction_LLT()[2].getInteractionAtSur_ptr());

				for (unsigned int d = 0; d < mVector_vectorWithSurfacePointer_Element.at(3).size(); d++)
				{
					surface_3 = mVector_vectorWithSurfacePointer_Element.at(3).at(d);
					tempOptSysElement.fillPosAndElementAndInteraction(3, surface_3, mOptSysEle.getPosAndInteraction_LLT()[3].getInteractionAtSur_ptr());

					for (unsigned int e = 0; e < mVector_vectorWithSurfacePointer_Element.at(4).size(); e++)
					{
						surface_4 = mVector_vectorWithSurfacePointer_Element.at(4).at(e);
						tempOptSysElement.fillPosAndElementAndInteraction(4, surface_4, mOptSysEle.getPosAndInteraction_LLT()[4].getInteractionAtSur_ptr());

						mPossibleOpticalSys_Element.push_back(tempOptSysElement.getDeepCopyOptSysEle());

						tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(4);

					}
					tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(3);
				}
				tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(2);
			}
			tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(1);
		}
		//tempOptSys.cleanSurfaceAndInteractionStartAt_i(0);
	}


}
void BuildSystemsForCombination::buildOpticalSystemCombination_6Surfaces_LLT()
{
	unsigned int numberSurfaces = mVector_vectorWithSurfacePointer_LLT.size();


	std::vector<std::shared_ptr<InteractionRay_LLT>> tempInteractions_LLT;
	OpticalSystem_LLT tempOptSys;

	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_0;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_1;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_2;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_3;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_4;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_5;

	for (unsigned int a = 0; a < mVector_vectorWithSurfacePointer_LLT.at(0).size(); a++)
	{
		surface_0 = mVector_vectorWithSurfacePointer_LLT.at(0).at(a);
		tempOptSys.fillTracingVectorSurfaces(0, surface_0);
		tempOptSys.fillTracingVectorInteraction(0, mOptSysEle.getPosAndInteraction_LLT().at(0).getInteractionAtSur_ptr());

		for (unsigned int b = 0; b < mVector_vectorWithSurfacePointer_LLT.at(1).size(); b++)
		{
			surface_1 = mVector_vectorWithSurfacePointer_LLT.at(1).at(b);
			tempOptSys.fillTracingVectorSurfaces(1, surface_1);
			tempOptSys.fillTracingVectorInteraction(1, mOptSysEle.getPosAndInteraction_LLT().at(1).getInteractionAtSur_ptr());

			for (unsigned int c = 0; c < mVector_vectorWithSurfacePointer_LLT.at(2).size(); c++)
			{
				surface_2 = mVector_vectorWithSurfacePointer_LLT.at(2).at(c);
				tempOptSys.fillTracingVectorSurfaces(2, surface_2);
				tempOptSys.fillTracingVectorInteraction(2, mOptSysEle.getPosAndInteraction_LLT().at(2).getInteractionAtSur_ptr());

				for (unsigned int d = 0; d < mVector_vectorWithSurfacePointer_LLT.at(3).size(); d++)
				{
					surface_3 = mVector_vectorWithSurfacePointer_LLT.at(3).at(d);
					tempOptSys.fillTracingVectorSurfaces(3, surface_3);
					tempOptSys.fillTracingVectorInteraction(3, mOptSysEle.getPosAndInteraction_LLT().at(3).getInteractionAtSur_ptr());

					for (unsigned int e = 0; e < mVector_vectorWithSurfacePointer_LLT.at(4).size(); e++)
					{
						surface_4 = mVector_vectorWithSurfacePointer_LLT.at(4).at(e);
						tempOptSys.fillTracingVectorSurfaces(4, surface_4);
						tempOptSys.fillTracingVectorInteraction(4, mOptSysEle.getPosAndInteraction_LLT().at(4).getInteractionAtSur_ptr());

						for (unsigned int f = 0; f < mVector_vectorWithSurfacePointer_LLT.at(5).size(); f++)
						{
							surface_5 = mVector_vectorWithSurfacePointer_LLT.at(5).at(f);
							tempOptSys.fillTracingVectorSurfaces(5, surface_5);
							tempOptSys.fillTracingVectorInteraction(5, mOptSysEle.getPosAndInteraction_LLT().at(5).getInteractionAtSur_ptr());

							mPossibleOpticalSystem_LLT.push_back(tempOptSys.clone());

							tempOptSys.cleanSurfaceAndInteractionStartAt_i(5);

						}

						tempOptSys.cleanSurfaceAndInteractionStartAt_i(4);

					}
					tempOptSys.cleanSurfaceAndInteractionStartAt_i(3);
				}
				tempOptSys.cleanSurfaceAndInteractionStartAt_i(2);
			}
			tempOptSys.cleanSurfaceAndInteractionStartAt_i(1);
		}
		//tempOptSys.cleanSurfaceAndInteractionStartAt_i(0);
	}


}

void BuildSystemsForCombination::buildOpticalSystemCombination_6Surfaces_Element()
{
	unsigned int numberSurfaces = mVector_vectorWithSurfacePointer_Element.size();
	//unsigned int numberSurfaces = mVector_vectorWithSurfacePointer_LLT.size();

	//std::vector<std::shared_ptr<InteractionRay_LLT>> tempInteractions_LLT;
	std::vector<std::shared_ptr<Element_CR>> tempInteractions_Element;
	OpticalSystemElement tempOptSysElement;
	//OpticalSystemElement tempOptSys;

	std::shared_ptr<Element_CR> surface_0;
	std::shared_ptr<Element_CR> surface_1;
	std::shared_ptr<Element_CR> surface_2;
	std::shared_ptr<Element_CR> surface_3;
	std::shared_ptr<Element_CR> surface_4;
	std::shared_ptr<Element_CR> surface_5;

	for (unsigned int a = 0; a < mVector_vectorWithSurfacePointer_Element.at(0).size(); a++)
	{
		surface_0 = mVector_vectorWithSurfacePointer_Element.at(0).at(a);
		tempOptSysElement.fillPosAndElementAndInteraction(0, surface_0, mOptSysEle.getPosAndInteraction_LLT()[0].getInteractionAtSur_ptr());

		for (unsigned int b = 0; b < mVector_vectorWithSurfacePointer_Element.at(1).size(); b++)
		{
			surface_1 = mVector_vectorWithSurfacePointer_Element.at(1).at(b);
			tempOptSysElement.fillPosAndElementAndInteraction(1, surface_1, mOptSysEle.getPosAndInteraction_LLT()[1].getInteractionAtSur_ptr());

			for (unsigned int c = 0; c < mVector_vectorWithSurfacePointer_Element.at(2).size(); c++)
			{
				surface_2 = mVector_vectorWithSurfacePointer_Element.at(2).at(c);
				tempOptSysElement.fillPosAndElementAndInteraction(2, surface_2, mOptSysEle.getPosAndInteraction_LLT()[2].getInteractionAtSur_ptr());

				for (unsigned int d = 0; d < mVector_vectorWithSurfacePointer_Element.at(3).size(); d++)
				{
					surface_3 = mVector_vectorWithSurfacePointer_Element.at(3).at(d);
					tempOptSysElement.fillPosAndElementAndInteraction(3, surface_3, mOptSysEle.getPosAndInteraction_LLT()[3].getInteractionAtSur_ptr());

					for (unsigned int e = 0; e < mVector_vectorWithSurfacePointer_Element.at(4).size(); e++)
					{
						surface_4 = mVector_vectorWithSurfacePointer_Element.at(4).at(e);
						tempOptSysElement.fillPosAndElementAndInteraction(4, surface_4, mOptSysEle.getPosAndInteraction_LLT()[4].getInteractionAtSur_ptr());

						for (unsigned int f = 0; f < mVector_vectorWithSurfacePointer_Element.at(5).size(); f++)
						{
							surface_5 = mVector_vectorWithSurfacePointer_Element.at(5).at(f);
							tempOptSysElement.fillPosAndElementAndInteraction(5, surface_5, mOptSysEle.getPosAndInteraction_LLT()[5].getInteractionAtSur_ptr());

							mPossibleOpticalSys_Element.push_back(tempOptSysElement.getDeepCopyOptSysEle());

							tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(5);

						}

						tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(4);

					}
					tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(3);
				}
				tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(2);
			}
			tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(1);
		}
		//tempOptSys.cleanSurfaceAndInteractionStartAt_i(0);
	}


}
void BuildSystemsForCombination::buildOpticalSystemCombination_7Surfaces_LLT()
{
	unsigned int numberSurfaces = mVector_vectorWithSurfacePointer_LLT.size();


	std::vector<std::shared_ptr<InteractionRay_LLT>> tempInteractions_LLT;
	OpticalSystem_LLT tempOptSys;

	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_0;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_1;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_2;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_3;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_4;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_5;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_6;

	for (unsigned int a = 0; a < mVector_vectorWithSurfacePointer_LLT.at(0).size(); a++)
	{
		surface_0 = mVector_vectorWithSurfacePointer_LLT.at(0).at(a);
		tempOptSys.fillTracingVectorSurfaces(0, surface_0);
		tempOptSys.fillTracingVectorInteraction(0, mOptSysEle.getPosAndInteraction_LLT().at(0).getInteractionAtSur_ptr());

		for (unsigned int b = 0; b < mVector_vectorWithSurfacePointer_LLT.at(1).size(); b++)
		{
			surface_1 = mVector_vectorWithSurfacePointer_LLT.at(1).at(b);
			tempOptSys.fillTracingVectorSurfaces(1, surface_1);
			tempOptSys.fillTracingVectorInteraction(1, mOptSysEle.getPosAndInteraction_LLT().at(1).getInteractionAtSur_ptr());

			for (unsigned int c = 0; c < mVector_vectorWithSurfacePointer_LLT.at(2).size(); c++)
			{
				surface_2 = mVector_vectorWithSurfacePointer_LLT.at(2).at(c);
				tempOptSys.fillTracingVectorSurfaces(2, surface_2);
				tempOptSys.fillTracingVectorInteraction(2, mOptSysEle.getPosAndInteraction_LLT().at(2).getInteractionAtSur_ptr());

				for (unsigned int d = 0; d < mVector_vectorWithSurfacePointer_LLT.at(3).size(); d++)
				{
					surface_3 = mVector_vectorWithSurfacePointer_LLT.at(3).at(d);
					tempOptSys.fillTracingVectorSurfaces(3, surface_3);
					tempOptSys.fillTracingVectorInteraction(3, mOptSysEle.getPosAndInteraction_LLT().at(3).getInteractionAtSur_ptr());

					for (unsigned int e = 0; e < mVector_vectorWithSurfacePointer_LLT.at(4).size(); e++)
					{
						surface_4 = mVector_vectorWithSurfacePointer_LLT.at(4).at(e);
						tempOptSys.fillTracingVectorSurfaces(4, surface_4);
						tempOptSys.fillTracingVectorInteraction(4, mOptSysEle.getPosAndInteraction_LLT().at(4).getInteractionAtSur_ptr());

						for (unsigned int f = 0; f < mVector_vectorWithSurfacePointer_LLT.at(5).size(); f++)
						{
							surface_5 = mVector_vectorWithSurfacePointer_LLT.at(5).at(f);
							tempOptSys.fillTracingVectorSurfaces(5, surface_5);
							tempOptSys.fillTracingVectorInteraction(5, mOptSysEle.getPosAndInteraction_LLT().at(5).getInteractionAtSur_ptr());

							for (unsigned int g = 0; g < mVector_vectorWithSurfacePointer_LLT.at(6).size(); g++)
							{
								surface_6 = mVector_vectorWithSurfacePointer_LLT.at(6).at(f);
								tempOptSys.fillTracingVectorSurfaces(6, surface_6);
								tempOptSys.fillTracingVectorInteraction(6, mOptSysEle.getPosAndInteraction_LLT().at(6).getInteractionAtSur_ptr());

								mPossibleOpticalSystem_LLT.push_back(tempOptSys.clone());

								tempOptSys.cleanSurfaceAndInteractionStartAt_i(6);
							}
							tempOptSys.cleanSurfaceAndInteractionStartAt_i(5);

						}

						tempOptSys.cleanSurfaceAndInteractionStartAt_i(4);

					}
					tempOptSys.cleanSurfaceAndInteractionStartAt_i(3);
				}
				tempOptSys.cleanSurfaceAndInteractionStartAt_i(2);
			}
			tempOptSys.cleanSurfaceAndInteractionStartAt_i(1);
		}
		//tempOptSys.cleanSurfaceAndInteractionStartAt_i(0);
	}


}

void BuildSystemsForCombination::buildOpticalSystemCombination_7Surfaces_Element()
{
	unsigned int numberSurfaces = mVector_vectorWithSurfacePointer_Element.size();
	//unsigned int numberSurfaces = mVector_vectorWithSurfacePointer_LLT.size();

	//std::vector<std::shared_ptr<InteractionRay_LLT>> tempInteractions_LLT;
	std::vector<std::shared_ptr<Element_CR>> tempInteractions_Element;
	OpticalSystemElement tempOptSysElement;
	//OpticalSystemElement tempOptSys;

	std::shared_ptr<Element_CR> surface_0;
	std::shared_ptr<Element_CR> surface_1;
	std::shared_ptr<Element_CR> surface_2;
	std::shared_ptr<Element_CR> surface_3;
	std::shared_ptr<Element_CR> surface_4;
	std::shared_ptr<Element_CR> surface_5;
	std::shared_ptr<Element_CR> surface_6;

	for (unsigned int a = 0; a < mVector_vectorWithSurfacePointer_Element.at(0).size(); a++)
	{
		surface_0 = mVector_vectorWithSurfacePointer_Element.at(0).at(a);
		tempOptSysElement.fillPosAndElementAndInteraction(0, surface_0, mOptSysEle.getPosAndInteraction_LLT()[0].getInteractionAtSur_ptr());

		for (unsigned int b = 0; b < mVector_vectorWithSurfacePointer_Element.at(1).size(); b++)
		{
			surface_1 = mVector_vectorWithSurfacePointer_Element.at(1).at(b);
			tempOptSysElement.fillPosAndElementAndInteraction(1, surface_1, mOptSysEle.getPosAndInteraction_LLT()[1].getInteractionAtSur_ptr());

			for (unsigned int c = 0; c < mVector_vectorWithSurfacePointer_Element.at(2).size(); c++)
			{
				surface_2 = mVector_vectorWithSurfacePointer_Element.at(2).at(c);
				tempOptSysElement.fillPosAndElementAndInteraction(2, surface_2, mOptSysEle.getPosAndInteraction_LLT()[2].getInteractionAtSur_ptr());

				for (unsigned int d = 0; d < mVector_vectorWithSurfacePointer_Element.at(3).size(); d++)
				{
					surface_3 = mVector_vectorWithSurfacePointer_Element.at(3).at(d);
					tempOptSysElement.fillPosAndElementAndInteraction(3, surface_3, mOptSysEle.getPosAndInteraction_LLT()[3].getInteractionAtSur_ptr());

					for (unsigned int e = 0; e < mVector_vectorWithSurfacePointer_Element.at(4).size(); e++)
					{
						surface_4 = mVector_vectorWithSurfacePointer_Element.at(4).at(e);
						tempOptSysElement.fillPosAndElementAndInteraction(4, surface_4, mOptSysEle.getPosAndInteraction_LLT()[4].getInteractionAtSur_ptr());

						for (unsigned int f = 0; f < mVector_vectorWithSurfacePointer_Element.at(5).size(); f++)
						{
							surface_5 = mVector_vectorWithSurfacePointer_Element.at(5).at(f);
							tempOptSysElement.fillPosAndElementAndInteraction(5, surface_5, mOptSysEle.getPosAndInteraction_LLT()[5].getInteractionAtSur_ptr());

							for (unsigned int g = 0; g < mVector_vectorWithSurfacePointer_Element.at(6).size(); g++)
							{
								surface_6 = mVector_vectorWithSurfacePointer_Element.at(6).at(f);
								tempOptSysElement.fillPosAndElementAndInteraction(6, surface_6, mOptSysEle.getPosAndInteraction_LLT()[6].getInteractionAtSur_ptr());

								mPossibleOpticalSys_Element.push_back(tempOptSysElement.getDeepCopyOptSysEle());

								tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(6);
							}
							tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(5);

						}

						tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(4);

					}
					tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(3);
				}
				tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(2);
			}
			tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(1);
		}
		//tempOptSys.cleanSurfaceAndInteractionStartAt_i(0);
	}


}
void BuildSystemsForCombination::buildOpticalSystemCombination_8Surfaces_LLT()
{
	unsigned int numberSurfaces = mVector_vectorWithSurfacePointer_LLT.size();


	std::vector<std::shared_ptr<InteractionRay_LLT>> tempInteractions_LLT;
	OpticalSystem_LLT tempOptSys;

	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_0;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_1;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_2;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_3;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_4;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_5;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_6;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_7;

	for (unsigned int a = 0; a < mVector_vectorWithSurfacePointer_LLT.at(0).size(); a++)
	{
		surface_0 = mVector_vectorWithSurfacePointer_LLT.at(0).at(a);
		tempOptSys.fillTracingVectorSurfaces(0, surface_0);
		tempOptSys.fillTracingVectorInteraction(0, mOptSysEle.getPosAndInteraction_LLT().at(0).getInteractionAtSur_ptr());

		for (unsigned int b = 0; b < mVector_vectorWithSurfacePointer_LLT.at(1).size(); b++)
		{
			surface_1 = mVector_vectorWithSurfacePointer_LLT.at(1).at(b);
			tempOptSys.fillTracingVectorSurfaces(1, surface_1);
			tempOptSys.fillTracingVectorInteraction(1, mOptSysEle.getPosAndInteraction_LLT().at(1).getInteractionAtSur_ptr());

			for (unsigned int c = 0; c < mVector_vectorWithSurfacePointer_LLT.at(2).size(); c++)
			{
				surface_2 = mVector_vectorWithSurfacePointer_LLT.at(2).at(c);
				tempOptSys.fillTracingVectorSurfaces(2, surface_2);
				tempOptSys.fillTracingVectorInteraction(2, mOptSysEle.getPosAndInteraction_LLT().at(2).getInteractionAtSur_ptr());

				for (unsigned int d = 0; d < mVector_vectorWithSurfacePointer_LLT.at(3).size(); d++)
				{
					surface_3 = mVector_vectorWithSurfacePointer_LLT.at(3).at(d);
					tempOptSys.fillTracingVectorSurfaces(3, surface_3);
					tempOptSys.fillTracingVectorInteraction(3, mOptSysEle.getPosAndInteraction_LLT().at(3).getInteractionAtSur_ptr());

					for (unsigned int e = 0; e < mVector_vectorWithSurfacePointer_LLT.at(4).size(); e++)
					{
						surface_4 = mVector_vectorWithSurfacePointer_LLT.at(4).at(e);
						tempOptSys.fillTracingVectorSurfaces(4, surface_4);
						tempOptSys.fillTracingVectorInteraction(4, mOptSysEle.getPosAndInteraction_LLT().at(4).getInteractionAtSur_ptr());

						for (unsigned int f = 0; f < mVector_vectorWithSurfacePointer_LLT.at(5).size(); f++)
						{
							surface_5 = mVector_vectorWithSurfacePointer_LLT.at(5).at(f);
							tempOptSys.fillTracingVectorSurfaces(5, surface_5);
							tempOptSys.fillTracingVectorInteraction(5, mOptSysEle.getPosAndInteraction_LLT().at(5).getInteractionAtSur_ptr());

							for (unsigned int g = 0; g < mVector_vectorWithSurfacePointer_LLT.at(6).size(); g++)
							{
								surface_6 = mVector_vectorWithSurfacePointer_LLT.at(6).at(g);
								tempOptSys.fillTracingVectorSurfaces(6, surface_6);
								tempOptSys.fillTracingVectorInteraction(6, mOptSysEle.getPosAndInteraction_LLT().at(6).getInteractionAtSur_ptr());

								for (unsigned int h = 0; h < mVector_vectorWithSurfacePointer_LLT.at(7).size(); h++)
								{
									surface_7 = mVector_vectorWithSurfacePointer_LLT.at(7).at(h);
									tempOptSys.fillTracingVectorSurfaces(7, surface_7);
									tempOptSys.fillTracingVectorInteraction(7, mOptSysEle.getPosAndInteraction_LLT().at(7).getInteractionAtSur_ptr());
									mPossibleOpticalSystem_LLT.push_back(tempOptSys.clone());

									tempOptSys.cleanSurfaceAndInteractionStartAt_i(7);
								}


								tempOptSys.cleanSurfaceAndInteractionStartAt_i(6);
							}
							tempOptSys.cleanSurfaceAndInteractionStartAt_i(5);

						}

						tempOptSys.cleanSurfaceAndInteractionStartAt_i(4);

					}
					tempOptSys.cleanSurfaceAndInteractionStartAt_i(3);
				}
				tempOptSys.cleanSurfaceAndInteractionStartAt_i(2);
			}
			tempOptSys.cleanSurfaceAndInteractionStartAt_i(1);
		}
		//tempOptSys.cleanSurfaceAndInteractionStartAt_i(0);
	}


}

void BuildSystemsForCombination::buildOpticalSystemCombination_8Surfaces_Element()
{
	unsigned int numberSurfaces = mVector_vectorWithSurfacePointer_Element.size();
	//unsigned int numberSurfaces = mVector_vectorWithSurfacePointer_LLT.size();

	//std::vector<std::shared_ptr<InteractionRay_LLT>> tempInteractions_LLT;
	std::vector<std::shared_ptr<Element_CR>> tempInteractions_Element;
	OpticalSystemElement tempOptSysElement;
	//OpticalSystemElement tempOptSys;

	std::shared_ptr<Element_CR> surface_0;
	std::shared_ptr<Element_CR> surface_1;
	std::shared_ptr<Element_CR> surface_2;
	std::shared_ptr<Element_CR> surface_3;
	std::shared_ptr<Element_CR> surface_4;
	std::shared_ptr<Element_CR> surface_5;
	std::shared_ptr<Element_CR> surface_6;
	std::shared_ptr<Element_CR> surface_7;

	for (unsigned int a = 0; a < mVector_vectorWithSurfacePointer_Element.at(0).size(); a++)
	{
		surface_0 = mVector_vectorWithSurfacePointer_Element.at(0).at(a);
		tempOptSysElement.fillPosAndElementAndInteraction(0, surface_0, mOptSysEle.getPosAndInteraction_LLT()[0].getInteractionAtSur_ptr());

		for (unsigned int b = 0; b < mVector_vectorWithSurfacePointer_Element.at(1).size(); b++)
		{
			surface_1 = mVector_vectorWithSurfacePointer_Element.at(1).at(b);
			tempOptSysElement.fillPosAndElementAndInteraction(1, surface_1, mOptSysEle.getPosAndInteraction_LLT()[1].getInteractionAtSur_ptr());

			for (unsigned int c = 0; c < mVector_vectorWithSurfacePointer_Element.at(2).size(); c++)
			{
				surface_2 = mVector_vectorWithSurfacePointer_Element.at(2).at(c);
				tempOptSysElement.fillPosAndElementAndInteraction(2, surface_2, mOptSysEle.getPosAndInteraction_LLT()[2].getInteractionAtSur_ptr());

				for (unsigned int d = 0; d < mVector_vectorWithSurfacePointer_Element.at(3).size(); d++)
				{
					surface_3 = mVector_vectorWithSurfacePointer_Element.at(3).at(d);
					tempOptSysElement.fillPosAndElementAndInteraction(3, surface_3, mOptSysEle.getPosAndInteraction_LLT()[3].getInteractionAtSur_ptr());

					for (unsigned int e = 0; e < mVector_vectorWithSurfacePointer_Element.at(4).size(); e++)
					{
						surface_4 = mVector_vectorWithSurfacePointer_Element.at(4).at(e);
						tempOptSysElement.fillPosAndElementAndInteraction(4, surface_4, mOptSysEle.getPosAndInteraction_LLT()[4].getInteractionAtSur_ptr());

						for (unsigned int f = 0; f < mVector_vectorWithSurfacePointer_Element.at(5).size(); f++)
						{
							surface_5 = mVector_vectorWithSurfacePointer_Element.at(5).at(f);
							tempOptSysElement.fillPosAndElementAndInteraction(5, surface_5, mOptSysEle.getPosAndInteraction_LLT()[5].getInteractionAtSur_ptr());

							for (unsigned int g = 0; g < mVector_vectorWithSurfacePointer_Element.at(6).size(); g++)
							{
								surface_6 = mVector_vectorWithSurfacePointer_Element.at(6).at(g);
								tempOptSysElement.fillPosAndElementAndInteraction(6, surface_6, mOptSysEle.getPosAndInteraction_LLT()[6].getInteractionAtSur_ptr());

								for (unsigned int h = 0; h < mVector_vectorWithSurfacePointer_Element.at(7).size(); h++)
								{
									surface_7 = mVector_vectorWithSurfacePointer_Element.at(7).at(h);
									tempOptSysElement.fillPosAndElementAndInteraction(7, surface_7, mOptSysEle.getPosAndInteraction_LLT()[7].getInteractionAtSur_ptr());


									mPossibleOpticalSys_Element.push_back(tempOptSysElement.getDeepCopyOptSysEle());
								}


								tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(6);
							}
							tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(5);

						}

						tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(4);

					}
					tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(3);
				}
				tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(2);
			}
			tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(1);
		}
		//tempOptSys.cleanSurfaceAndInteractionStartAt_i(0);
	}


}
void BuildSystemsForCombination::buildOpticalSystemCombination_9Surfaces_LLT()
{
	unsigned int numberSurfaces = mVector_vectorWithSurfacePointer_LLT.size();


	std::vector<std::shared_ptr<InteractionRay_LLT>> tempInteractions_LLT;
	OpticalSystem_LLT tempOptSys;

	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_0;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_1;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_2;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_3;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_4;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_5;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_6;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_7;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_8;

	for (unsigned int a = 0; a < mVector_vectorWithSurfacePointer_LLT.at(0).size(); a++)
	{
		surface_0 = mVector_vectorWithSurfacePointer_LLT.at(0).at(a);
		tempOptSys.fillTracingVectorSurfaces(0, surface_0);
		tempOptSys.fillTracingVectorInteraction(0, mOptSysEle.getPosAndInteraction_LLT().at(0).getInteractionAtSur_ptr());

		for (unsigned int b = 0; b < mVector_vectorWithSurfacePointer_LLT.at(1).size(); b++)
		{
			surface_1 = mVector_vectorWithSurfacePointer_LLT.at(1).at(b);
			tempOptSys.fillTracingVectorSurfaces(1, surface_1);
			tempOptSys.fillTracingVectorInteraction(1, mOptSysEle.getPosAndInteraction_LLT().at(1).getInteractionAtSur_ptr());

			for (unsigned int c = 0; c < mVector_vectorWithSurfacePointer_LLT.at(2).size(); c++)
			{
				surface_2 = mVector_vectorWithSurfacePointer_LLT.at(2).at(c);
				tempOptSys.fillTracingVectorSurfaces(2, surface_2);
				tempOptSys.fillTracingVectorInteraction(2, mOptSysEle.getPosAndInteraction_LLT().at(2).getInteractionAtSur_ptr());

				for (unsigned int d = 0; d < mVector_vectorWithSurfacePointer_LLT.at(3).size(); d++)
				{
					surface_3 = mVector_vectorWithSurfacePointer_LLT.at(3).at(d);
					tempOptSys.fillTracingVectorSurfaces(3, surface_3);
					tempOptSys.fillTracingVectorInteraction(3, mOptSysEle.getPosAndInteraction_LLT().at(3).getInteractionAtSur_ptr());

					for (unsigned int e = 0; e < mVector_vectorWithSurfacePointer_LLT.at(4).size(); e++)
					{
						surface_4 = mVector_vectorWithSurfacePointer_LLT.at(4).at(e);
						tempOptSys.fillTracingVectorSurfaces(4, surface_4);
						tempOptSys.fillTracingVectorInteraction(4, mOptSysEle.getPosAndInteraction_LLT().at(4).getInteractionAtSur_ptr());

						for (unsigned int f = 0; f < mVector_vectorWithSurfacePointer_LLT.at(5).size(); f++)
						{
							surface_5 = mVector_vectorWithSurfacePointer_LLT.at(5).at(f);
							tempOptSys.fillTracingVectorSurfaces(5, surface_5);
							tempOptSys.fillTracingVectorInteraction(5, mOptSysEle.getPosAndInteraction_LLT().at(5).getInteractionAtSur_ptr());

							for (unsigned int g = 0; g < mVector_vectorWithSurfacePointer_LLT.at(6).size(); g++)
							{
								surface_6 = mVector_vectorWithSurfacePointer_LLT.at(6).at(g);
								tempOptSys.fillTracingVectorSurfaces(6, surface_6);
								tempOptSys.fillTracingVectorInteraction(6, mOptSysEle.getPosAndInteraction_LLT().at(6).getInteractionAtSur_ptr());

								for (unsigned int h = 0; h < mVector_vectorWithSurfacePointer_LLT.at(7).size(); h++)
								{
									surface_7 = mVector_vectorWithSurfacePointer_LLT.at(7).at(h);
									tempOptSys.fillTracingVectorSurfaces(7, surface_7);
									tempOptSys.fillTracingVectorInteraction(7, mOptSysEle.getPosAndInteraction_LLT().at(7).getInteractionAtSur_ptr());

									for (unsigned int i = 0; i < mVector_vectorWithSurfacePointer_LLT.at(8).size(); i++)
									{
										surface_8 = mVector_vectorWithSurfacePointer_LLT.at(8).at(i);
										tempOptSys.fillTracingVectorSurfaces(8, surface_8);
										tempOptSys.fillTracingVectorInteraction(8, mOptSysEle.getPosAndInteraction_LLT().at(8).getInteractionAtSur_ptr());

										mPossibleOpticalSystem_LLT.push_back(tempOptSys.clone());

										tempOptSys.cleanSurfaceAndInteractionStartAt_i(8);
									}

									tempOptSys.cleanSurfaceAndInteractionStartAt_i(7);
								}


								tempOptSys.cleanSurfaceAndInteractionStartAt_i(6);
							}
							tempOptSys.cleanSurfaceAndInteractionStartAt_i(5);

						}

						tempOptSys.cleanSurfaceAndInteractionStartAt_i(4);

					}
					tempOptSys.cleanSurfaceAndInteractionStartAt_i(3);
				}
				tempOptSys.cleanSurfaceAndInteractionStartAt_i(2);
			}
			tempOptSys.cleanSurfaceAndInteractionStartAt_i(1);
		}
		//tempOptSys.cleanSurfaceAndInteractionStartAt_i(0);
	}


}

void BuildSystemsForCombination::buildOpticalSystemCombination_9Surfaces_Element()
{
	unsigned int numberSurfaces = mVector_vectorWithSurfacePointer_Element.size();
	//unsigned int numberSurfaces = mVector_vectorWithSurfacePointer_LLT.size();

	//std::vector<std::shared_ptr<InteractionRay_LLT>> tempInteractions_LLT;
	std::vector<std::shared_ptr<Element_CR>> tempInteractions_Element;
	OpticalSystemElement tempOptSysElement;
	//OpticalSystemElement tempOptSys;

	std::shared_ptr<Element_CR> surface_0;
	std::shared_ptr<Element_CR> surface_1;
	std::shared_ptr<Element_CR> surface_2;
	std::shared_ptr<Element_CR> surface_3;
	std::shared_ptr<Element_CR> surface_4;
	std::shared_ptr<Element_CR> surface_5;
	std::shared_ptr<Element_CR> surface_6;
	std::shared_ptr<Element_CR> surface_7;
	std::shared_ptr<Element_CR> surface_8;

	for (unsigned int a = 0; a < mVector_vectorWithSurfacePointer_Element.at(0).size(); a++)
	{
		surface_0 = mVector_vectorWithSurfacePointer_Element.at(0).at(a);
		tempOptSysElement.fillPosAndElementAndInteraction(0, surface_0, mOptSysEle.getPosAndInteraction_LLT()[0].getInteractionAtSur_ptr());

		for (unsigned int b = 0; b < mVector_vectorWithSurfacePointer_Element.at(1).size(); b++)
		{
			surface_1 = mVector_vectorWithSurfacePointer_Element.at(1).at(b);
			tempOptSysElement.fillPosAndElementAndInteraction(1, surface_1, mOptSysEle.getPosAndInteraction_LLT()[1].getInteractionAtSur_ptr());

			for (unsigned int c = 0; c < mVector_vectorWithSurfacePointer_Element.at(2).size(); c++)
			{
				surface_2 = mVector_vectorWithSurfacePointer_Element.at(2).at(c);
				tempOptSysElement.fillPosAndElementAndInteraction(2, surface_2, mOptSysEle.getPosAndInteraction_LLT()[2].getInteractionAtSur_ptr());

				for (unsigned int d = 0; d < mVector_vectorWithSurfacePointer_Element.at(3).size(); d++)
				{
					surface_3 = mVector_vectorWithSurfacePointer_Element.at(3).at(d);
					tempOptSysElement.fillPosAndElementAndInteraction(3, surface_3, mOptSysEle.getPosAndInteraction_LLT()[3].getInteractionAtSur_ptr());

					for (unsigned int e = 0; e < mVector_vectorWithSurfacePointer_Element.at(4).size(); e++)
					{
						surface_4 = mVector_vectorWithSurfacePointer_Element.at(4).at(e);
						tempOptSysElement.fillPosAndElementAndInteraction(4, surface_4, mOptSysEle.getPosAndInteraction_LLT()[4].getInteractionAtSur_ptr());

						for (unsigned int f = 0; f < mVector_vectorWithSurfacePointer_Element.at(5).size(); f++)
						{
							surface_5 = mVector_vectorWithSurfacePointer_Element.at(5).at(f);
							tempOptSysElement.fillPosAndElementAndInteraction(5, surface_5, mOptSysEle.getPosAndInteraction_LLT()[5].getInteractionAtSur_ptr());

							for (unsigned int g = 0; g < mVector_vectorWithSurfacePointer_Element.at(6).size(); g++)
							{
								surface_6 = mVector_vectorWithSurfacePointer_Element.at(6).at(g);
								tempOptSysElement.fillPosAndElementAndInteraction(6, surface_6, mOptSysEle.getPosAndInteraction_LLT()[6].getInteractionAtSur_ptr());

								for (unsigned int h = 0; h < mVector_vectorWithSurfacePointer_Element.at(7).size(); h++)
								{
									surface_7 = mVector_vectorWithSurfacePointer_Element.at(7).at(h);
									tempOptSysElement.fillPosAndElementAndInteraction(7, surface_7, mOptSysEle.getPosAndInteraction_LLT()[7].getInteractionAtSur_ptr());

									for (unsigned int i = 0; i < mVector_vectorWithSurfacePointer_Element.at(8).size(); i++)
									{
										surface_8 = mVector_vectorWithSurfacePointer_Element.at(8).at(i);
										tempOptSysElement.fillPosAndElementAndInteraction(8, surface_8, mOptSysEle.getPosAndInteraction_LLT()[8].getInteractionAtSur_ptr());

										mPossibleOpticalSys_Element.push_back(tempOptSysElement.getDeepCopyOptSysEle());

										tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(8);
									}

									tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(7);
								}


								tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(6);
							}
							tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(5);

						}

						tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(4);

					}
					tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(3);
				}
				tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(2);
			}
			tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(1);
		}
		//tempOptSys.cleanSurfaceAndInteractionStartAt_i(0);
	}


}

void BuildSystemsForCombination::buildOpticalSystemCombination_10Surfaces_LLT()
{
	unsigned int numberSurfaces = mVector_vectorWithSurfacePointer_LLT.size();


	std::vector<std::shared_ptr<InteractionRay_LLT>> tempInteractions_LLT;
	OpticalSystem_LLT tempOptSys;

	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_0;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_1;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_2;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_3;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_4;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_5;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_6;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_7;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_8;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_9;

	for (unsigned int a = 0; a < mVector_vectorWithSurfacePointer_LLT.at(0).size(); a++)
	{
		surface_0 = mVector_vectorWithSurfacePointer_LLT.at(0).at(a);
		tempOptSys.fillTracingVectorSurfaces(0, surface_0);
		tempOptSys.fillTracingVectorInteraction(0, mOptSysEle.getPosAndInteraction_LLT().at(0).getInteractionAtSur_ptr());

		for (unsigned int b = 0; b < mVector_vectorWithSurfacePointer_LLT.at(1).size(); b++)
		{
			surface_1 = mVector_vectorWithSurfacePointer_LLT.at(1).at(b);
			tempOptSys.fillTracingVectorSurfaces(1, surface_1);
			tempOptSys.fillTracingVectorInteraction(1, mOptSysEle.getPosAndInteraction_LLT().at(1).getInteractionAtSur_ptr());

			for (unsigned int c = 0; c < mVector_vectorWithSurfacePointer_LLT.at(2).size(); c++)
			{
				surface_2 = mVector_vectorWithSurfacePointer_LLT.at(2).at(c);
				tempOptSys.fillTracingVectorSurfaces(2, surface_2);
				tempOptSys.fillTracingVectorInteraction(2, mOptSysEle.getPosAndInteraction_LLT().at(2).getInteractionAtSur_ptr());

				for (unsigned int d = 0; d < mVector_vectorWithSurfacePointer_LLT.at(3).size(); d++)
				{
					surface_3 = mVector_vectorWithSurfacePointer_LLT.at(3).at(d);
					tempOptSys.fillTracingVectorSurfaces(3, surface_3);
					tempOptSys.fillTracingVectorInteraction(3, mOptSysEle.getPosAndInteraction_LLT().at(3).getInteractionAtSur_ptr());

					for (unsigned int e = 0; e < mVector_vectorWithSurfacePointer_LLT.at(4).size(); e++)
					{
						surface_4 = mVector_vectorWithSurfacePointer_LLT.at(4).at(e);
						tempOptSys.fillTracingVectorSurfaces(4, surface_4);
						tempOptSys.fillTracingVectorInteraction(4, mOptSysEle.getPosAndInteraction_LLT().at(4).getInteractionAtSur_ptr());

						for (unsigned int f = 0; f < mVector_vectorWithSurfacePointer_LLT.at(5).size(); f++)
						{
							surface_5 = mVector_vectorWithSurfacePointer_LLT.at(5).at(f);
							tempOptSys.fillTracingVectorSurfaces(5, surface_5);
							tempOptSys.fillTracingVectorInteraction(5, mOptSysEle.getPosAndInteraction_LLT().at(5).getInteractionAtSur_ptr());

							for (unsigned int g = 0; g < mVector_vectorWithSurfacePointer_LLT.at(6).size(); g++)
							{
								surface_6 = mVector_vectorWithSurfacePointer_LLT.at(6).at(g);
								tempOptSys.fillTracingVectorSurfaces(6, surface_6);
								tempOptSys.fillTracingVectorInteraction(6, mOptSysEle.getPosAndInteraction_LLT().at(6).getInteractionAtSur_ptr());

								for (unsigned int h = 0; h < mVector_vectorWithSurfacePointer_LLT.at(7).size(); h++)
								{
									surface_7 = mVector_vectorWithSurfacePointer_LLT.at(7).at(h);
									tempOptSys.fillTracingVectorSurfaces(7, surface_7);
									tempOptSys.fillTracingVectorInteraction(7, mOptSysEle.getPosAndInteraction_LLT().at(7).getInteractionAtSur_ptr());

									for (unsigned int i = 0; i < mVector_vectorWithSurfacePointer_LLT.at(8).size(); i++)
									{
										surface_8 = mVector_vectorWithSurfacePointer_LLT.at(8).at(i);
										tempOptSys.fillTracingVectorSurfaces(8, surface_8);
										tempOptSys.fillTracingVectorInteraction(8, mOptSysEle.getPosAndInteraction_LLT().at(8).getInteractionAtSur_ptr());

										for (unsigned int j = 0; j < mVector_vectorWithSurfacePointer_LLT.at(9).size(); j++)
										{
											surface_9 = mVector_vectorWithSurfacePointer_LLT.at(9).at(j);
											tempOptSys.fillTracingVectorSurfaces(9, surface_9);
											tempOptSys.fillTracingVectorInteraction(9, mOptSysEle.getPosAndInteraction_LLT().at(9).getInteractionAtSur_ptr());

											mPossibleOpticalSystem_LLT.push_back(tempOptSys.clone());

											tempOptSys.cleanSurfaceAndInteractionStartAt_i(9);
										}


										tempOptSys.cleanSurfaceAndInteractionStartAt_i(8);
									}


									tempOptSys.cleanSurfaceAndInteractionStartAt_i(7);
								}


								tempOptSys.cleanSurfaceAndInteractionStartAt_i(6);
							}
							tempOptSys.cleanSurfaceAndInteractionStartAt_i(5);

						}

						tempOptSys.cleanSurfaceAndInteractionStartAt_i(4);

					}
					tempOptSys.cleanSurfaceAndInteractionStartAt_i(3);
				}
				tempOptSys.cleanSurfaceAndInteractionStartAt_i(2);
			}
			tempOptSys.cleanSurfaceAndInteractionStartAt_i(1);
		}
		//tempOptSys.cleanSurfaceAndInteractionStartAt_i(0);
	}


}

void BuildSystemsForCombination::buildOpticalSystemCombination_10Surfaces_Element()
{
	unsigned int numberSurfaces = mVector_vectorWithSurfacePointer_Element.size();
	//unsigned int numberSurfaces = mVector_vectorWithSurfacePointer_LLT.size();

	//std::vector<std::shared_ptr<InteractionRay_LLT>> tempInteractions_LLT;
	std::vector<std::shared_ptr<Element_CR>> tempInteractions_Element;
	OpticalSystemElement tempOptSysElement;
	//OpticalSystemElement tempOptSys;

	std::shared_ptr<Element_CR> surface_0;
	std::shared_ptr<Element_CR> surface_1;
	std::shared_ptr<Element_CR> surface_2;
	std::shared_ptr<Element_CR> surface_3;
	std::shared_ptr<Element_CR> surface_4;
	std::shared_ptr<Element_CR> surface_5;
	std::shared_ptr<Element_CR> surface_6;
	std::shared_ptr<Element_CR> surface_7;
	std::shared_ptr<Element_CR> surface_8;
	std::shared_ptr<Element_CR> surface_9;

	for (unsigned int a = 0; a < mVector_vectorWithSurfacePointer_Element.at(0).size(); a++)
	{
		surface_0 = mVector_vectorWithSurfacePointer_Element.at(0).at(a);
		tempOptSysElement.fillPosAndElementAndInteraction(0, surface_0, mOptSysEle.getPosAndInteraction_LLT()[0].getInteractionAtSur_ptr());

		for (unsigned int b = 0; b < mVector_vectorWithSurfacePointer_Element.at(1).size(); b++)
		{
			surface_1 = mVector_vectorWithSurfacePointer_Element.at(1).at(b);
			tempOptSysElement.fillPosAndElementAndInteraction(1, surface_1, mOptSysEle.getPosAndInteraction_LLT()[1].getInteractionAtSur_ptr());

			for (unsigned int c = 0; c < mVector_vectorWithSurfacePointer_Element.at(2).size(); c++)
			{
				surface_2 = mVector_vectorWithSurfacePointer_Element.at(2).at(c);
				tempOptSysElement.fillPosAndElementAndInteraction(2, surface_2, mOptSysEle.getPosAndInteraction_LLT()[2].getInteractionAtSur_ptr());

				for (unsigned int d = 0; d < mVector_vectorWithSurfacePointer_Element.at(3).size(); d++)
				{
					surface_3 = mVector_vectorWithSurfacePointer_Element.at(3).at(d);
					tempOptSysElement.fillPosAndElementAndInteraction(3, surface_3, mOptSysEle.getPosAndInteraction_LLT()[3].getInteractionAtSur_ptr());

					for (unsigned int e = 0; e < mVector_vectorWithSurfacePointer_Element.at(4).size(); e++)
					{
						surface_4 = mVector_vectorWithSurfacePointer_Element.at(4).at(e);
						tempOptSysElement.fillPosAndElementAndInteraction(4, surface_4, mOptSysEle.getPosAndInteraction_LLT()[4].getInteractionAtSur_ptr());

						for (unsigned int f = 0; f < mVector_vectorWithSurfacePointer_Element.at(5).size(); f++)
						{
							surface_5 = mVector_vectorWithSurfacePointer_Element.at(5).at(f);
							tempOptSysElement.fillPosAndElementAndInteraction(5, surface_5, mOptSysEle.getPosAndInteraction_LLT()[5].getInteractionAtSur_ptr());

							for (unsigned int g = 0; g < mVector_vectorWithSurfacePointer_Element.at(6).size(); g++)
							{
								surface_6 = mVector_vectorWithSurfacePointer_Element.at(6).at(g);
								tempOptSysElement.fillPosAndElementAndInteraction(6, surface_6, mOptSysEle.getPosAndInteraction_LLT()[6].getInteractionAtSur_ptr());

								for (unsigned int h = 0; h < mVector_vectorWithSurfacePointer_Element.at(7).size(); h++)
								{
									surface_7 = mVector_vectorWithSurfacePointer_Element.at(7).at(h);
									tempOptSysElement.fillPosAndElementAndInteraction(7, surface_7, mOptSysEle.getPosAndInteraction_LLT()[7].getInteractionAtSur_ptr());

									for (unsigned int i = 0; i < mVector_vectorWithSurfacePointer_Element.at(8).size(); i++)
									{
										surface_8 = mVector_vectorWithSurfacePointer_Element.at(8).at(i);
										tempOptSysElement.fillPosAndElementAndInteraction(8, surface_8, mOptSysEle.getPosAndInteraction_LLT()[8].getInteractionAtSur_ptr());

										for (unsigned int j = 0; j < mVector_vectorWithSurfacePointer_Element.at(9).size(); j++)
										{
											surface_9 = mVector_vectorWithSurfacePointer_Element.at(9).at(j);
											tempOptSysElement.fillPosAndElementAndInteraction(9, surface_9, mOptSysEle.getPosAndInteraction_LLT()[9].getInteractionAtSur_ptr());

											mPossibleOpticalSys_Element.push_back(tempOptSysElement.getDeepCopyOptSysEle());

											tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(9);
										}


										tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(8);
									}


									tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(7);
								}


								tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(6);
							}
							tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(5);

						}

						tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(4);

					}
					tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(3);
				}
				tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(2);
			}
			tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(1);
		}
		//tempOptSys.cleanSurfaceAndInteractionStartAt_i(0);
	}


}
void BuildSystemsForCombination::buildOpticalSystemCombination_11Surfaces_LLT()
{
	unsigned int numberSurfaces = mVector_vectorWithSurfacePointer_LLT.size();


	std::vector<std::shared_ptr<InteractionRay_LLT>> tempInteractions_LLT;
	OpticalSystem_LLT tempOptSys;

	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_0;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_1;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_2;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_3;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_4;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_5;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_6;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_7;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_8;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_9;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_10;

	for (unsigned int a = 0; a < mVector_vectorWithSurfacePointer_LLT.at(0).size(); a++)
	{
		surface_0 = mVector_vectorWithSurfacePointer_LLT.at(0).at(a);
		tempOptSys.fillTracingVectorSurfaces(0, surface_0);
		tempOptSys.fillTracingVectorInteraction(0, mOptSysEle.getPosAndInteraction_LLT().at(0).getInteractionAtSur_ptr());

		for (unsigned int b = 0; b < mVector_vectorWithSurfacePointer_LLT.at(1).size(); b++)
		{
			surface_1 = mVector_vectorWithSurfacePointer_LLT.at(1).at(b);
			tempOptSys.fillTracingVectorSurfaces(1, surface_1);
			tempOptSys.fillTracingVectorInteraction(1, mOptSysEle.getPosAndInteraction_LLT().at(1).getInteractionAtSur_ptr());

			for (unsigned int c = 0; c < mVector_vectorWithSurfacePointer_LLT.at(2).size(); c++)
			{
				surface_2 = mVector_vectorWithSurfacePointer_LLT.at(2).at(c);
				tempOptSys.fillTracingVectorSurfaces(2, surface_2);
				tempOptSys.fillTracingVectorInteraction(2, mOptSysEle.getPosAndInteraction_LLT().at(2).getInteractionAtSur_ptr());

				for (unsigned int d = 0; d < mVector_vectorWithSurfacePointer_LLT.at(3).size(); d++)
				{
					surface_3 = mVector_vectorWithSurfacePointer_LLT.at(3).at(d);
					tempOptSys.fillTracingVectorSurfaces(3, surface_3);
					tempOptSys.fillTracingVectorInteraction(3, mOptSysEle.getPosAndInteraction_LLT().at(3).getInteractionAtSur_ptr());

					for (unsigned int e = 0; e < mVector_vectorWithSurfacePointer_LLT.at(4).size(); e++)
					{
						surface_4 = mVector_vectorWithSurfacePointer_LLT.at(4).at(e);
						tempOptSys.fillTracingVectorSurfaces(4, surface_4);
						tempOptSys.fillTracingVectorInteraction(4, mOptSysEle.getPosAndInteraction_LLT().at(4).getInteractionAtSur_ptr());

						for (unsigned int f = 0; f < mVector_vectorWithSurfacePointer_LLT.at(5).size(); f++)
						{
							surface_5 = mVector_vectorWithSurfacePointer_LLT.at(5).at(f);
							tempOptSys.fillTracingVectorSurfaces(5, surface_5);
							tempOptSys.fillTracingVectorInteraction(5, mOptSysEle.getPosAndInteraction_LLT().at(5).getInteractionAtSur_ptr());

							for (unsigned int g = 0; g < mVector_vectorWithSurfacePointer_LLT.at(6).size(); g++)
							{
								surface_6 = mVector_vectorWithSurfacePointer_LLT.at(6).at(g);
								tempOptSys.fillTracingVectorSurfaces(6, surface_6);
								tempOptSys.fillTracingVectorInteraction(6, mOptSysEle.getPosAndInteraction_LLT().at(6).getInteractionAtSur_ptr());

								for (unsigned int h = 0; h < mVector_vectorWithSurfacePointer_LLT.at(7).size(); h++)
								{
									surface_7 = mVector_vectorWithSurfacePointer_LLT.at(7).at(h);
									tempOptSys.fillTracingVectorSurfaces(7, surface_7);
									tempOptSys.fillTracingVectorInteraction(7, mOptSysEle.getPosAndInteraction_LLT().at(7).getInteractionAtSur_ptr());

									for (unsigned int i = 0; i < mVector_vectorWithSurfacePointer_LLT.at(8).size(); i++)
									{
										surface_8 = mVector_vectorWithSurfacePointer_LLT.at(8).at(i);
										tempOptSys.fillTracingVectorSurfaces(8, surface_8);
										tempOptSys.fillTracingVectorInteraction(8, mOptSysEle.getPosAndInteraction_LLT().at(8).getInteractionAtSur_ptr());

										for (unsigned int j = 0; j < mVector_vectorWithSurfacePointer_LLT.at(9).size(); j++)
										{
											surface_9 = mVector_vectorWithSurfacePointer_LLT.at(9).at(j);
											tempOptSys.fillTracingVectorSurfaces(9, surface_9);
											tempOptSys.fillTracingVectorInteraction(9, mOptSysEle.getPosAndInteraction_LLT().at(9).getInteractionAtSur_ptr());

											for (unsigned int i = 0; i < mVector_vectorWithSurfacePointer_LLT.at(10).size(); i++)
											{
												surface_10 = mVector_vectorWithSurfacePointer_LLT.at(10).at(i);
												tempOptSys.fillTracingVectorSurfaces(10, surface_10);
												tempOptSys.fillTracingVectorInteraction(10, mOptSysEle.getPosAndInteraction_LLT().at(10).getInteractionAtSur_ptr());


												mPossibleOpticalSystem_LLT.push_back(tempOptSys.clone());

												tempOptSys.cleanSurfaceAndInteractionStartAt_i(10);
											}
											tempOptSys.cleanSurfaceAndInteractionStartAt_i(9);
										}


										tempOptSys.cleanSurfaceAndInteractionStartAt_i(8);
									}


									tempOptSys.cleanSurfaceAndInteractionStartAt_i(7);
								}


								tempOptSys.cleanSurfaceAndInteractionStartAt_i(6);
							}
							tempOptSys.cleanSurfaceAndInteractionStartAt_i(5);

						}

						tempOptSys.cleanSurfaceAndInteractionStartAt_i(4);

					}
					tempOptSys.cleanSurfaceAndInteractionStartAt_i(3);
				}
				tempOptSys.cleanSurfaceAndInteractionStartAt_i(2);
			}
			tempOptSys.cleanSurfaceAndInteractionStartAt_i(1);
		}
		//tempOptSys.cleanSurfaceAndInteractionStartAt_i(0);
	}


}
void BuildSystemsForCombination::buildOpticalSystemCombination_11Surfaces_Element()
{
	unsigned int numberSurfaces = mVector_vectorWithSurfacePointer_Element.size();
	//unsigned int numberSurfaces = mVector_vectorWithSurfacePointer_LLT.size();

	//std::vector<std::shared_ptr<InteractionRay_LLT>> tempInteractions_LLT;
	std::vector<std::shared_ptr<Element_CR>> tempInteractions_Element;
	OpticalSystemElement tempOptSysElement;
	//OpticalSystemElement tempOptSys;

	std::shared_ptr<Element_CR> surface_0;
	std::shared_ptr<Element_CR> surface_1;
	std::shared_ptr<Element_CR> surface_2;
	std::shared_ptr<Element_CR> surface_3;
	std::shared_ptr<Element_CR> surface_4;
	std::shared_ptr<Element_CR> surface_5;
	std::shared_ptr<Element_CR> surface_6;
	std::shared_ptr<Element_CR> surface_7;
	std::shared_ptr<Element_CR> surface_8;
	std::shared_ptr<Element_CR> surface_9;
	std::shared_ptr<Element_CR> surface_10;

	for (unsigned int a = 0; a < mVector_vectorWithSurfacePointer_Element.at(0).size(); a++)
	{
		surface_0 = mVector_vectorWithSurfacePointer_Element.at(0).at(a);
		tempOptSysElement.fillPosAndElementAndInteraction(0, surface_0, mOptSysEle.getPosAndInteraction_LLT()[0].getInteractionAtSur_ptr());

		for (unsigned int b = 0; b < mVector_vectorWithSurfacePointer_Element.at(1).size(); b++)
		{
			surface_1 = mVector_vectorWithSurfacePointer_Element.at(1).at(b);
			tempOptSysElement.fillPosAndElementAndInteraction(1, surface_1, mOptSysEle.getPosAndInteraction_LLT()[1].getInteractionAtSur_ptr());

			for (unsigned int c = 0; c < mVector_vectorWithSurfacePointer_Element.at(2).size(); c++)
			{
				surface_2 = mVector_vectorWithSurfacePointer_Element.at(2).at(c);
				tempOptSysElement.fillPosAndElementAndInteraction(2, surface_2, mOptSysEle.getPosAndInteraction_LLT()[2].getInteractionAtSur_ptr());

				for (unsigned int d = 0; d < mVector_vectorWithSurfacePointer_Element.at(3).size(); d++)
				{
					surface_3 = mVector_vectorWithSurfacePointer_Element.at(3).at(d);
					tempOptSysElement.fillPosAndElementAndInteraction(3, surface_3, mOptSysEle.getPosAndInteraction_LLT()[3].getInteractionAtSur_ptr());

					for (unsigned int e = 0; e < mVector_vectorWithSurfacePointer_Element.at(4).size(); e++)
					{
						surface_4 = mVector_vectorWithSurfacePointer_Element.at(4).at(e);
						tempOptSysElement.fillPosAndElementAndInteraction(4, surface_4, mOptSysEle.getPosAndInteraction_LLT()[4].getInteractionAtSur_ptr());

						for (unsigned int f = 0; f < mVector_vectorWithSurfacePointer_Element.at(5).size(); f++)
						{
							surface_5 = mVector_vectorWithSurfacePointer_Element.at(5).at(f);
							tempOptSysElement.fillPosAndElementAndInteraction(5, surface_5, mOptSysEle.getPosAndInteraction_LLT()[5].getInteractionAtSur_ptr());

							for (unsigned int g = 0; g < mVector_vectorWithSurfacePointer_Element.at(6).size(); g++)
							{
								surface_6 = mVector_vectorWithSurfacePointer_Element.at(6).at(g);
								tempOptSysElement.fillPosAndElementAndInteraction(6, surface_6, mOptSysEle.getPosAndInteraction_LLT()[6].getInteractionAtSur_ptr());

								for (unsigned int h = 0; h < mVector_vectorWithSurfacePointer_Element.at(7).size(); h++)
								{
									surface_7 = mVector_vectorWithSurfacePointer_Element.at(7).at(h);
									tempOptSysElement.fillPosAndElementAndInteraction(7, surface_7, mOptSysEle.getPosAndInteraction_LLT()[7].getInteractionAtSur_ptr());

									for (unsigned int i = 0; i < mVector_vectorWithSurfacePointer_Element.at(8).size(); i++)
									{
										surface_8 = mVector_vectorWithSurfacePointer_Element.at(8).at(i);
										tempOptSysElement.fillPosAndElementAndInteraction(8, surface_8, mOptSysEle.getPosAndInteraction_LLT()[8].getInteractionAtSur_ptr());

										for (unsigned int j = 0; j < mVector_vectorWithSurfacePointer_Element.at(9).size(); j++)
										{

											surface_9 = mVector_vectorWithSurfacePointer_Element.at(9).at(j);
											tempOptSysElement.fillPosAndElementAndInteraction(9, surface_9, mOptSysEle.getPosAndInteraction_LLT()[9].getInteractionAtSur_ptr());

											for (unsigned int i = 0; i < mVector_vectorWithSurfacePointer_Element.at(10).size(); i++)
											{
												surface_10 = mVector_vectorWithSurfacePointer_Element.at(10).at(i);
												tempOptSysElement.fillPosAndElementAndInteraction(10, surface_10, mOptSysEle.getPosAndInteraction_LLT()[10].getInteractionAtSur_ptr());

												mPossibleOpticalSys_Element.push_back(tempOptSysElement.getDeepCopyOptSysEle());

												tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(10);
											}
											tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(9);
										}


										tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(8);
									}


									tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(7);
								}


								tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(6);
							}
							tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(5);

						}

						tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(4);

					}
					tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(3);
				}
				tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(2);
			}
			tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(1);
		}
		//tempOptSys.cleanSurfaceAndInteractionStartAt_i(0);
	}


}
void BuildSystemsForCombination::buildOpticalSystemCombination_12Surfaces_LLT()
{
	unsigned int numberSurfaces = mVector_vectorWithSurfacePointer_LLT.size();


	std::vector<std::shared_ptr<InteractionRay_LLT>> tempInteractions_LLT;
	OpticalSystem_LLT tempOptSys;

	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_0;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_1;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_2;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_3;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_4;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_5;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_6;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_7;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_8;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_9;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_10;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_11;

	for (unsigned int a = 0; a < mVector_vectorWithSurfacePointer_LLT.at(0).size(); a++)
	{
		surface_0 = mVector_vectorWithSurfacePointer_LLT.at(0).at(a);
		tempOptSys.fillTracingVectorSurfaces(0, surface_0);
		tempOptSys.fillTracingVectorInteraction(0, mOptSysEle.getPosAndInteraction_LLT().at(0).getInteractionAtSur_ptr());

		for (unsigned int b = 0; b < mVector_vectorWithSurfacePointer_LLT.at(1).size(); b++)
		{
			surface_1 = mVector_vectorWithSurfacePointer_LLT.at(1).at(b);
			tempOptSys.fillTracingVectorSurfaces(1, surface_1);
			tempOptSys.fillTracingVectorInteraction(1, mOptSysEle.getPosAndInteraction_LLT().at(1).getInteractionAtSur_ptr());

			for (unsigned int c = 0; c < mVector_vectorWithSurfacePointer_LLT.at(2).size(); c++)
			{
				surface_2 = mVector_vectorWithSurfacePointer_LLT.at(2).at(c);
				tempOptSys.fillTracingVectorSurfaces(2, surface_2);
				tempOptSys.fillTracingVectorInteraction(2, mOptSysEle.getPosAndInteraction_LLT().at(2).getInteractionAtSur_ptr());

				for (unsigned int d = 0; d < mVector_vectorWithSurfacePointer_LLT.at(3).size(); d++)
				{
					surface_3 = mVector_vectorWithSurfacePointer_LLT.at(3).at(d);
					tempOptSys.fillTracingVectorSurfaces(3, surface_3);
					tempOptSys.fillTracingVectorInteraction(3, mOptSysEle.getPosAndInteraction_LLT().at(3).getInteractionAtSur_ptr());

					for (unsigned int e = 0; e < mVector_vectorWithSurfacePointer_LLT.at(4).size(); e++)
					{
						surface_4 = mVector_vectorWithSurfacePointer_LLT.at(4).at(e);
						tempOptSys.fillTracingVectorSurfaces(4, surface_4);
						tempOptSys.fillTracingVectorInteraction(4, mOptSysEle.getPosAndInteraction_LLT().at(4).getInteractionAtSur_ptr());

						for (unsigned int f = 0; f < mVector_vectorWithSurfacePointer_LLT.at(5).size(); f++)
						{
							surface_5 = mVector_vectorWithSurfacePointer_LLT.at(5).at(f);
							tempOptSys.fillTracingVectorSurfaces(5, surface_5);
							tempOptSys.fillTracingVectorInteraction(5, mOptSysEle.getPosAndInteraction_LLT().at(5).getInteractionAtSur_ptr());

							for (unsigned int g = 0; g < mVector_vectorWithSurfacePointer_LLT.at(6).size(); g++)
							{
								surface_6 = mVector_vectorWithSurfacePointer_LLT.at(6).at(g);
								tempOptSys.fillTracingVectorSurfaces(6, surface_6);
								tempOptSys.fillTracingVectorInteraction(6, mOptSysEle.getPosAndInteraction_LLT().at(6).getInteractionAtSur_ptr());

								for (unsigned int h = 0; h < mVector_vectorWithSurfacePointer_LLT.at(7).size(); h++)
								{
									surface_7 = mVector_vectorWithSurfacePointer_LLT.at(7).at(h);
									tempOptSys.fillTracingVectorSurfaces(7, surface_7);
									tempOptSys.fillTracingVectorInteraction(7, mOptSysEle.getPosAndInteraction_LLT().at(7).getInteractionAtSur_ptr());

									for (unsigned int i = 0; i < mVector_vectorWithSurfacePointer_LLT.at(8).size(); i++)
									{
										surface_8 = mVector_vectorWithSurfacePointer_LLT.at(8).at(i);
										tempOptSys.fillTracingVectorSurfaces(8, surface_8);
										tempOptSys.fillTracingVectorInteraction(8, mOptSysEle.getPosAndInteraction_LLT().at(8).getInteractionAtSur_ptr());

										for (unsigned int j = 0; j < mVector_vectorWithSurfacePointer_LLT.at(9).size(); j++)
										{
											surface_9 = mVector_vectorWithSurfacePointer_LLT.at(9).at(j);
											tempOptSys.fillTracingVectorSurfaces(9, surface_9);
											tempOptSys.fillTracingVectorInteraction(9, mOptSysEle.getPosAndInteraction_LLT().at(9).getInteractionAtSur_ptr());

											for (unsigned int i = 0; i < mVector_vectorWithSurfacePointer_LLT.at(10).size(); i++)
											{
												surface_10 = mVector_vectorWithSurfacePointer_LLT.at(10).at(i);
												tempOptSys.fillTracingVectorSurfaces(10, surface_10);
												tempOptSys.fillTracingVectorInteraction(10, mOptSysEle.getPosAndInteraction_LLT().at(10).getInteractionAtSur_ptr());

												for (unsigned int j = 0; j < mVector_vectorWithSurfacePointer_LLT.at(11).size(); j++)
												{
													surface_11 = mVector_vectorWithSurfacePointer_LLT.at(11).at(j);
													tempOptSys.fillTracingVectorSurfaces(11, surface_11);
													tempOptSys.fillTracingVectorInteraction(11, mOptSysEle.getPosAndInteraction_LLT().at(11).getInteractionAtSur_ptr());

													mPossibleOpticalSystem_LLT.push_back(tempOptSys.clone());

													tempOptSys.cleanSurfaceAndInteractionStartAt_i(11);
												}
												tempOptSys.cleanSurfaceAndInteractionStartAt_i(10);
											}
											tempOptSys.cleanSurfaceAndInteractionStartAt_i(9);
										}


										tempOptSys.cleanSurfaceAndInteractionStartAt_i(8);
									}


									tempOptSys.cleanSurfaceAndInteractionStartAt_i(7);
								}


								tempOptSys.cleanSurfaceAndInteractionStartAt_i(6);
							}
							tempOptSys.cleanSurfaceAndInteractionStartAt_i(5);

						}

						tempOptSys.cleanSurfaceAndInteractionStartAt_i(4);

					}
					tempOptSys.cleanSurfaceAndInteractionStartAt_i(3);
				}
				tempOptSys.cleanSurfaceAndInteractionStartAt_i(2);
			}
			tempOptSys.cleanSurfaceAndInteractionStartAt_i(1);
		}
		//tempOptSys.cleanSurfaceAndInteractionStartAt_i(0);
	}


}
void BuildSystemsForCombination::buildOpticalSystemCombination_12Surfaces_Element()
{
	unsigned int numberSurfaces = mVector_vectorWithSurfacePointer_Element.size();
	//unsigned int numberSurfaces = mVector_vectorWithSurfacePointer_LLT.size();

	//std::vector<std::shared_ptr<InteractionRay_LLT>> tempInteractions_LLT;
	std::vector<std::shared_ptr<Element_CR>> tempInteractions_Element;
	OpticalSystemElement tempOptSysElement;
	//OpticalSystemElement tempOptSys;

	std::shared_ptr<Element_CR> surface_0;
	std::shared_ptr<Element_CR> surface_1;
	std::shared_ptr<Element_CR> surface_2;
	std::shared_ptr<Element_CR> surface_3;
	std::shared_ptr<Element_CR> surface_4;
	std::shared_ptr<Element_CR> surface_5;
	std::shared_ptr<Element_CR> surface_6;
	std::shared_ptr<Element_CR> surface_7;
	std::shared_ptr<Element_CR> surface_8;
	std::shared_ptr<Element_CR> surface_9;
	std::shared_ptr<Element_CR> surface_10;
	std::shared_ptr<Element_CR> surface_11;

	for (unsigned int a = 0; a < mVector_vectorWithSurfacePointer_Element.at(0).size(); a++)
	{
		surface_0 = mVector_vectorWithSurfacePointer_Element.at(0).at(a);
		tempOptSysElement.fillPosAndElementAndInteraction(0, surface_0, mOptSysEle.getPosAndInteraction_LLT()[0].getInteractionAtSur_ptr());

		for (unsigned int b = 0; b < mVector_vectorWithSurfacePointer_Element.at(1).size(); b++)
		{
			surface_1 = mVector_vectorWithSurfacePointer_Element.at(1).at(b);
			tempOptSysElement.fillPosAndElementAndInteraction(1, surface_1, mOptSysEle.getPosAndInteraction_LLT()[1].getInteractionAtSur_ptr());

			for (unsigned int c = 0; c < mVector_vectorWithSurfacePointer_Element.at(2).size(); c++)
			{
				surface_2 = mVector_vectorWithSurfacePointer_Element.at(2).at(c);
				tempOptSysElement.fillPosAndElementAndInteraction(2, surface_2, mOptSysEle.getPosAndInteraction_LLT()[2].getInteractionAtSur_ptr());

				for (unsigned int d = 0; d < mVector_vectorWithSurfacePointer_Element.at(3).size(); d++)
				{
					surface_3 = mVector_vectorWithSurfacePointer_Element.at(3).at(d);
					tempOptSysElement.fillPosAndElementAndInteraction(3, surface_3, mOptSysEle.getPosAndInteraction_LLT()[3].getInteractionAtSur_ptr());

					for (unsigned int e = 0; e < mVector_vectorWithSurfacePointer_Element.at(4).size(); e++)
					{
						surface_4 = mVector_vectorWithSurfacePointer_Element.at(4).at(e);
						tempOptSysElement.fillPosAndElementAndInteraction(4, surface_4, mOptSysEle.getPosAndInteraction_LLT()[4].getInteractionAtSur_ptr());

						for (unsigned int f = 0; f < mVector_vectorWithSurfacePointer_Element.at(5).size(); f++)
						{
							surface_5 = mVector_vectorWithSurfacePointer_Element.at(5).at(f);
							tempOptSysElement.fillPosAndElementAndInteraction(5, surface_5, mOptSysEle.getPosAndInteraction_LLT()[5].getInteractionAtSur_ptr());

							for (unsigned int g = 0; g < mVector_vectorWithSurfacePointer_Element.at(6).size(); g++)
							{
								surface_6 = mVector_vectorWithSurfacePointer_Element.at(6).at(g);
								tempOptSysElement.fillPosAndElementAndInteraction(6, surface_6, mOptSysEle.getPosAndInteraction_LLT()[6].getInteractionAtSur_ptr());

								for (unsigned int h = 0; h < mVector_vectorWithSurfacePointer_Element.at(7).size(); h++)
								{
									surface_7 = mVector_vectorWithSurfacePointer_Element.at(7).at(h);
									tempOptSysElement.fillPosAndElementAndInteraction(7, surface_7, mOptSysEle.getPosAndInteraction_LLT()[7].getInteractionAtSur_ptr());

									for (unsigned int i = 0; i < mVector_vectorWithSurfacePointer_Element.at(8).size(); i++)
									{
										surface_8 = mVector_vectorWithSurfacePointer_Element.at(8).at(i);
										tempOptSysElement.fillPosAndElementAndInteraction(8, surface_8, mOptSysEle.getPosAndInteraction_LLT()[8].getInteractionAtSur_ptr());

										for (unsigned int j = 0; j < mVector_vectorWithSurfacePointer_Element.at(9).size(); j++)
										{

											surface_9 = mVector_vectorWithSurfacePointer_Element.at(9).at(j);
											tempOptSysElement.fillPosAndElementAndInteraction(9, surface_9, mOptSysEle.getPosAndInteraction_LLT()[9].getInteractionAtSur_ptr());

											for (unsigned int i = 0; i < mVector_vectorWithSurfacePointer_Element.at(10).size(); i++)
											{
												surface_10 = mVector_vectorWithSurfacePointer_Element.at(10).at(i);
												tempOptSysElement.fillPosAndElementAndInteraction(10, surface_10, mOptSysEle.getPosAndInteraction_LLT()[10].getInteractionAtSur_ptr());

												for (unsigned int j = 0; j < mVector_vectorWithSurfacePointer_Element.at(11).size(); j++)
												{

													surface_11 = mVector_vectorWithSurfacePointer_Element.at(11).at(j);
													tempOptSysElement.fillPosAndElementAndInteraction(11, surface_11, mOptSysEle.getPosAndInteraction_LLT()[11].getInteractionAtSur_ptr());

													mPossibleOpticalSys_Element.push_back(tempOptSysElement.getDeepCopyOptSysEle());

													tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(11);
												}
												tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(10);
											}
											tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(9);
										}


										tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(8);
									}


									tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(7);
								}


								tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(6);
							}
							tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(5);

						}

						tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(4);

					}
					tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(3);
				}
				tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(2);
			}
			tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(1);
		}
		//tempOptSys.cleanSurfaceAndInteractionStartAt_i(0);
	}
}

void BuildSystemsForCombination::buildOpticalSystemCombination_13Surfaces_LLT()
{
	unsigned int numberSurfaces = mVector_vectorWithSurfacePointer_LLT.size();


	std::vector<std::shared_ptr<InteractionRay_LLT>> tempInteractions_LLT;
	OpticalSystem_LLT tempOptSys;

	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_0;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_1;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_2;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_3;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_4;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_5;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_6;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_7;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_8;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_9;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_10;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_11;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_12;

	for (unsigned int a = 0; a < mVector_vectorWithSurfacePointer_LLT.at(0).size(); a++)
	{
		surface_0 = mVector_vectorWithSurfacePointer_LLT.at(0).at(a);
		tempOptSys.fillTracingVectorSurfaces(0, surface_0);
		tempOptSys.fillTracingVectorInteraction(0, mOptSysEle.getPosAndInteraction_LLT().at(0).getInteractionAtSur_ptr());

		for (unsigned int b = 0; b < mVector_vectorWithSurfacePointer_LLT.at(1).size(); b++)
		{
			surface_1 = mVector_vectorWithSurfacePointer_LLT.at(1).at(b);
			tempOptSys.fillTracingVectorSurfaces(1, surface_1);
			tempOptSys.fillTracingVectorInteraction(1, mOptSysEle.getPosAndInteraction_LLT().at(1).getInteractionAtSur_ptr());

			for (unsigned int c = 0; c < mVector_vectorWithSurfacePointer_LLT.at(2).size(); c++)
			{
				surface_2 = mVector_vectorWithSurfacePointer_LLT.at(2).at(c);
				tempOptSys.fillTracingVectorSurfaces(2, surface_2);
				tempOptSys.fillTracingVectorInteraction(2, mOptSysEle.getPosAndInteraction_LLT().at(2).getInteractionAtSur_ptr());

				for (unsigned int d = 0; d < mVector_vectorWithSurfacePointer_LLT.at(3).size(); d++)
				{
					surface_3 = mVector_vectorWithSurfacePointer_LLT.at(3).at(d);
					tempOptSys.fillTracingVectorSurfaces(3, surface_3);
					tempOptSys.fillTracingVectorInteraction(3, mOptSysEle.getPosAndInteraction_LLT().at(3).getInteractionAtSur_ptr());

					for (unsigned int e = 0; e < mVector_vectorWithSurfacePointer_LLT.at(4).size(); e++)
					{
						surface_4 = mVector_vectorWithSurfacePointer_LLT.at(4).at(e);
						tempOptSys.fillTracingVectorSurfaces(4, surface_4);
						tempOptSys.fillTracingVectorInteraction(4, mOptSysEle.getPosAndInteraction_LLT().at(4).getInteractionAtSur_ptr());

						for (unsigned int f = 0; f < mVector_vectorWithSurfacePointer_LLT.at(5).size(); f++)
						{
							surface_5 = mVector_vectorWithSurfacePointer_LLT.at(5).at(f);
							tempOptSys.fillTracingVectorSurfaces(5, surface_5);
							tempOptSys.fillTracingVectorInteraction(5, mOptSysEle.getPosAndInteraction_LLT().at(5).getInteractionAtSur_ptr());

							for (unsigned int g = 0; g < mVector_vectorWithSurfacePointer_LLT.at(6).size(); g++)
							{
								surface_6 = mVector_vectorWithSurfacePointer_LLT.at(6).at(g);
								tempOptSys.fillTracingVectorSurfaces(6, surface_6);
								tempOptSys.fillTracingVectorInteraction(6, mOptSysEle.getPosAndInteraction_LLT().at(6).getInteractionAtSur_ptr());

								for (unsigned int h = 0; h < mVector_vectorWithSurfacePointer_LLT.at(7).size(); h++)
								{
									surface_7 = mVector_vectorWithSurfacePointer_LLT.at(7).at(h);
									tempOptSys.fillTracingVectorSurfaces(7, surface_7);
									tempOptSys.fillTracingVectorInteraction(7, mOptSysEle.getPosAndInteraction_LLT().at(7).getInteractionAtSur_ptr());

									for (unsigned int i = 0; i < mVector_vectorWithSurfacePointer_LLT.at(8).size(); i++)
									{
										surface_8 = mVector_vectorWithSurfacePointer_LLT.at(8).at(i);
										tempOptSys.fillTracingVectorSurfaces(8, surface_8);
										tempOptSys.fillTracingVectorInteraction(8, mOptSysEle.getPosAndInteraction_LLT().at(8).getInteractionAtSur_ptr());

										for (unsigned int j = 0; j < mVector_vectorWithSurfacePointer_LLT.at(9).size(); j++)
										{
											surface_9 = mVector_vectorWithSurfacePointer_LLT.at(9).at(j);
											tempOptSys.fillTracingVectorSurfaces(9, surface_9);
											tempOptSys.fillTracingVectorInteraction(9, mOptSysEle.getPosAndInteraction_LLT().at(9).getInteractionAtSur_ptr());

											for (unsigned int i = 0; i < mVector_vectorWithSurfacePointer_LLT.at(10).size(); i++)
											{
												surface_10 = mVector_vectorWithSurfacePointer_LLT.at(10).at(i);
												tempOptSys.fillTracingVectorSurfaces(10, surface_10);
												tempOptSys.fillTracingVectorInteraction(10, mOptSysEle.getPosAndInteraction_LLT().at(10).getInteractionAtSur_ptr());

												for (unsigned int j = 0; j < mVector_vectorWithSurfacePointer_LLT.at(11).size(); j++)
												{
													surface_11 = mVector_vectorWithSurfacePointer_LLT.at(11).at(j);
													tempOptSys.fillTracingVectorSurfaces(11, surface_11);
													tempOptSys.fillTracingVectorInteraction(11, mOptSysEle.getPosAndInteraction_LLT().at(11).getInteractionAtSur_ptr());

													for (unsigned int i = 0; i < mVector_vectorWithSurfacePointer_LLT.at(12).size(); i++)
													{
														surface_12 = mVector_vectorWithSurfacePointer_LLT.at(12).at(i);
														tempOptSys.fillTracingVectorSurfaces(12, surface_12);
														tempOptSys.fillTracingVectorInteraction(12, mOptSysEle.getPosAndInteraction_LLT().at(12).getInteractionAtSur_ptr());

														mPossibleOpticalSystem_LLT.push_back(tempOptSys.clone());

														tempOptSys.cleanSurfaceAndInteractionStartAt_i(12);
													}
													tempOptSys.cleanSurfaceAndInteractionStartAt_i(11);
												}
												tempOptSys.cleanSurfaceAndInteractionStartAt_i(10);
											}
											tempOptSys.cleanSurfaceAndInteractionStartAt_i(9);
										}


										tempOptSys.cleanSurfaceAndInteractionStartAt_i(8);
									}


									tempOptSys.cleanSurfaceAndInteractionStartAt_i(7);
								}


								tempOptSys.cleanSurfaceAndInteractionStartAt_i(6);
							}
							tempOptSys.cleanSurfaceAndInteractionStartAt_i(5);

						}

						tempOptSys.cleanSurfaceAndInteractionStartAt_i(4);

					}
					tempOptSys.cleanSurfaceAndInteractionStartAt_i(3);
				}
				tempOptSys.cleanSurfaceAndInteractionStartAt_i(2);
			}
			tempOptSys.cleanSurfaceAndInteractionStartAt_i(1);
		}
		//tempOptSys.cleanSurfaceAndInteractionStartAt_i(0);
	}


}
void BuildSystemsForCombination::buildOpticalSystemCombination_13Surfaces_Element()
{
	unsigned int numberSurfaces = mVector_vectorWithSurfacePointer_Element.size();
	//unsigned int numberSurfaces = mVector_vectorWithSurfacePointer_LLT.size();

	//std::vector<std::shared_ptr<InteractionRay_LLT>> tempInteractions_LLT;
	std::vector<std::shared_ptr<Element_CR>> tempInteractions_Element;
	OpticalSystemElement tempOptSysElement;
	//OpticalSystemElement tempOptSys;

	std::shared_ptr<Element_CR> surface_0;
	std::shared_ptr<Element_CR> surface_1;
	std::shared_ptr<Element_CR> surface_2;
	std::shared_ptr<Element_CR> surface_3;
	std::shared_ptr<Element_CR> surface_4;
	std::shared_ptr<Element_CR> surface_5;
	std::shared_ptr<Element_CR> surface_6;
	std::shared_ptr<Element_CR> surface_7;
	std::shared_ptr<Element_CR> surface_8;
	std::shared_ptr<Element_CR> surface_9;
	std::shared_ptr<Element_CR> surface_10;
	std::shared_ptr<Element_CR> surface_11;
	std::shared_ptr<Element_CR> surface_12;

	for (unsigned int a = 0; a < mVector_vectorWithSurfacePointer_Element.at(0).size(); a++)
	{
		surface_0 = mVector_vectorWithSurfacePointer_Element.at(0).at(a);
		tempOptSysElement.fillPosAndElementAndInteraction(0, surface_0, mOptSysEle.getPosAndInteraction_LLT()[0].getInteractionAtSur_ptr());

		for (unsigned int b = 0; b < mVector_vectorWithSurfacePointer_Element.at(1).size(); b++)
		{
			surface_1 = mVector_vectorWithSurfacePointer_Element.at(1).at(b);
			tempOptSysElement.fillPosAndElementAndInteraction(1, surface_1, mOptSysEle.getPosAndInteraction_LLT()[1].getInteractionAtSur_ptr());

			for (unsigned int c = 0; c < mVector_vectorWithSurfacePointer_Element.at(2).size(); c++)
			{
				surface_2 = mVector_vectorWithSurfacePointer_Element.at(2).at(c);
				tempOptSysElement.fillPosAndElementAndInteraction(2, surface_2, mOptSysEle.getPosAndInteraction_LLT()[2].getInteractionAtSur_ptr());

				for (unsigned int d = 0; d < mVector_vectorWithSurfacePointer_Element.at(3).size(); d++)
				{
					surface_3 = mVector_vectorWithSurfacePointer_Element.at(3).at(d);
					tempOptSysElement.fillPosAndElementAndInteraction(3, surface_3, mOptSysEle.getPosAndInteraction_LLT()[3].getInteractionAtSur_ptr());

					for (unsigned int e = 0; e < mVector_vectorWithSurfacePointer_Element.at(4).size(); e++)
					{
						surface_4 = mVector_vectorWithSurfacePointer_Element.at(4).at(e);
						tempOptSysElement.fillPosAndElementAndInteraction(4, surface_4, mOptSysEle.getPosAndInteraction_LLT()[4].getInteractionAtSur_ptr());

						for (unsigned int f = 0; f < mVector_vectorWithSurfacePointer_Element.at(5).size(); f++)
						{
							surface_5 = mVector_vectorWithSurfacePointer_Element.at(5).at(f);
							tempOptSysElement.fillPosAndElementAndInteraction(5, surface_5, mOptSysEle.getPosAndInteraction_LLT()[5].getInteractionAtSur_ptr());

							for (unsigned int g = 0; g < mVector_vectorWithSurfacePointer_Element.at(6).size(); g++)
							{
								surface_6 = mVector_vectorWithSurfacePointer_Element.at(6).at(g);
								tempOptSysElement.fillPosAndElementAndInteraction(6, surface_6, mOptSysEle.getPosAndInteraction_LLT()[6].getInteractionAtSur_ptr());

								for (unsigned int h = 0; h < mVector_vectorWithSurfacePointer_Element.at(7).size(); h++)
								{
									surface_7 = mVector_vectorWithSurfacePointer_Element.at(7).at(h);
									tempOptSysElement.fillPosAndElementAndInteraction(7, surface_7, mOptSysEle.getPosAndInteraction_LLT()[7].getInteractionAtSur_ptr());

									for (unsigned int i = 0; i < mVector_vectorWithSurfacePointer_Element.at(8).size(); i++)
									{
										surface_8 = mVector_vectorWithSurfacePointer_Element.at(8).at(i);
										tempOptSysElement.fillPosAndElementAndInteraction(8, surface_8, mOptSysEle.getPosAndInteraction_LLT()[8].getInteractionAtSur_ptr());

										for (unsigned int j = 0; j < mVector_vectorWithSurfacePointer_Element.at(9).size(); j++)
										{

											surface_9 = mVector_vectorWithSurfacePointer_Element.at(9).at(j);
											tempOptSysElement.fillPosAndElementAndInteraction(9, surface_9, mOptSysEle.getPosAndInteraction_LLT()[9].getInteractionAtSur_ptr());

											for (unsigned int i = 0; i < mVector_vectorWithSurfacePointer_Element.at(10).size(); i++)
											{
												surface_10 = mVector_vectorWithSurfacePointer_Element.at(10).at(i);
												tempOptSysElement.fillPosAndElementAndInteraction(10, surface_10, mOptSysEle.getPosAndInteraction_LLT()[10].getInteractionAtSur_ptr());

												for (unsigned int j = 0; j < mVector_vectorWithSurfacePointer_Element.at(11).size(); j++)
												{

													surface_11 = mVector_vectorWithSurfacePointer_Element.at(11).at(j);
													tempOptSysElement.fillPosAndElementAndInteraction(11, surface_11, mOptSysEle.getPosAndInteraction_LLT()[11].getInteractionAtSur_ptr());

													for (unsigned int i = 0; i < mVector_vectorWithSurfacePointer_Element.at(12).size(); i++)
													{
														surface_12 = mVector_vectorWithSurfacePointer_Element.at(12).at(i);
														tempOptSysElement.fillPosAndElementAndInteraction(12, surface_12, mOptSysEle.getPosAndInteraction_LLT()[12].getInteractionAtSur_ptr());

														mPossibleOpticalSys_Element.push_back(tempOptSysElement.getDeepCopyOptSysEle());

														tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(12);
													}
													tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(11);
												}
												tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(10);
											}
											tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(9);
										}


										tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(8);
									}


									tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(7);
								}


								tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(6);
							}
							tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(5);

						}

						tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(4);

					}
					tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(3);
				}
				tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(2);
			}
			tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(1);
		}
		//tempOptSys.cleanSurfaceAndInteractionStartAt_i(0);
	}


}

void BuildSystemsForCombination::buildOpticalSystemCombination_14Surfaces_LLT()
{
	unsigned int numberSurfaces = mVector_vectorWithSurfacePointer_LLT.size();


	std::vector<std::shared_ptr<InteractionRay_LLT>> tempInteractions_LLT;
	OpticalSystem_LLT tempOptSys;

	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_0;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_1;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_2;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_3;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_4;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_5;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_6;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_7;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_8;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_9;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_10;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_11;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_12;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_13;

	for (unsigned int a = 0; a < mVector_vectorWithSurfacePointer_LLT.at(0).size(); a++)
	{
		surface_0 = mVector_vectorWithSurfacePointer_LLT.at(0).at(a);
		tempOptSys.fillTracingVectorSurfaces(0, surface_0);
		tempOptSys.fillTracingVectorInteraction(0, mOptSysEle.getPosAndInteraction_LLT().at(0).getInteractionAtSur_ptr());

		for (unsigned int b = 0; b < mVector_vectorWithSurfacePointer_LLT.at(1).size(); b++)
		{
			surface_1 = mVector_vectorWithSurfacePointer_LLT.at(1).at(b);
			tempOptSys.fillTracingVectorSurfaces(1, surface_1);
			tempOptSys.fillTracingVectorInteraction(1, mOptSysEle.getPosAndInteraction_LLT().at(1).getInteractionAtSur_ptr());

			for (unsigned int c = 0; c < mVector_vectorWithSurfacePointer_LLT.at(2).size(); c++)
			{
				surface_2 = mVector_vectorWithSurfacePointer_LLT.at(2).at(c);
				tempOptSys.fillTracingVectorSurfaces(2, surface_2);
				tempOptSys.fillTracingVectorInteraction(2, mOptSysEle.getPosAndInteraction_LLT().at(2).getInteractionAtSur_ptr());

				for (unsigned int d = 0; d < mVector_vectorWithSurfacePointer_LLT.at(3).size(); d++)
				{
					surface_3 = mVector_vectorWithSurfacePointer_LLT.at(3).at(d);
					tempOptSys.fillTracingVectorSurfaces(3, surface_3);
					tempOptSys.fillTracingVectorInteraction(3, mOptSysEle.getPosAndInteraction_LLT().at(3).getInteractionAtSur_ptr());

					for (unsigned int e = 0; e < mVector_vectorWithSurfacePointer_LLT.at(4).size(); e++)
					{
						surface_4 = mVector_vectorWithSurfacePointer_LLT.at(4).at(e);
						tempOptSys.fillTracingVectorSurfaces(4, surface_4);
						tempOptSys.fillTracingVectorInteraction(4, mOptSysEle.getPosAndInteraction_LLT().at(4).getInteractionAtSur_ptr());

						for (unsigned int f = 0; f < mVector_vectorWithSurfacePointer_LLT.at(5).size(); f++)
						{
							surface_5 = mVector_vectorWithSurfacePointer_LLT.at(5).at(f);
							tempOptSys.fillTracingVectorSurfaces(5, surface_5);
							tempOptSys.fillTracingVectorInteraction(5, mOptSysEle.getPosAndInteraction_LLT().at(5).getInteractionAtSur_ptr());

							for (unsigned int g = 0; g < mVector_vectorWithSurfacePointer_LLT.at(6).size(); g++)
							{
								surface_6 = mVector_vectorWithSurfacePointer_LLT.at(6).at(g);
								tempOptSys.fillTracingVectorSurfaces(6, surface_6);
								tempOptSys.fillTracingVectorInteraction(6, mOptSysEle.getPosAndInteraction_LLT().at(6).getInteractionAtSur_ptr());

								for (unsigned int h = 0; h < mVector_vectorWithSurfacePointer_LLT.at(7).size(); h++)
								{
									surface_7 = mVector_vectorWithSurfacePointer_LLT.at(7).at(h);
									tempOptSys.fillTracingVectorSurfaces(7, surface_7);
									tempOptSys.fillTracingVectorInteraction(7, mOptSysEle.getPosAndInteraction_LLT().at(7).getInteractionAtSur_ptr());

									for (unsigned int i = 0; i < mVector_vectorWithSurfacePointer_LLT.at(8).size(); i++)
									{
										surface_8 = mVector_vectorWithSurfacePointer_LLT.at(8).at(i);
										tempOptSys.fillTracingVectorSurfaces(8, surface_8);
										tempOptSys.fillTracingVectorInteraction(8, mOptSysEle.getPosAndInteraction_LLT().at(8).getInteractionAtSur_ptr());

										for (unsigned int j = 0; j < mVector_vectorWithSurfacePointer_LLT.at(9).size(); j++)
										{
											surface_9 = mVector_vectorWithSurfacePointer_LLT.at(9).at(j);
											tempOptSys.fillTracingVectorSurfaces(9, surface_9);
											tempOptSys.fillTracingVectorInteraction(9, mOptSysEle.getPosAndInteraction_LLT().at(9).getInteractionAtSur_ptr());

											for (unsigned int i = 0; i < mVector_vectorWithSurfacePointer_LLT.at(10).size(); i++)
											{
												surface_10 = mVector_vectorWithSurfacePointer_LLT.at(10).at(i);
												tempOptSys.fillTracingVectorSurfaces(10, surface_10);
												tempOptSys.fillTracingVectorInteraction(10, mOptSysEle.getPosAndInteraction_LLT().at(10).getInteractionAtSur_ptr());

												for (unsigned int j = 0; j < mVector_vectorWithSurfacePointer_LLT.at(11).size(); j++)
												{
													surface_11 = mVector_vectorWithSurfacePointer_LLT.at(11).at(j);
													tempOptSys.fillTracingVectorSurfaces(11, surface_11);
													tempOptSys.fillTracingVectorInteraction(11, mOptSysEle.getPosAndInteraction_LLT().at(11).getInteractionAtSur_ptr());

													for (unsigned int i = 0; i < mVector_vectorWithSurfacePointer_LLT.at(12).size(); i++)
													{
														surface_12 = mVector_vectorWithSurfacePointer_LLT.at(12).at(i);
														tempOptSys.fillTracingVectorSurfaces(12, surface_12);
														tempOptSys.fillTracingVectorInteraction(12, mOptSysEle.getPosAndInteraction_LLT().at(12).getInteractionAtSur_ptr());

														for (unsigned int j = 0; j < mVector_vectorWithSurfacePointer_LLT.at(13).size(); j++)
														{
															surface_13 = mVector_vectorWithSurfacePointer_LLT.at(13).at(j);
															tempOptSys.fillTracingVectorSurfaces(13, surface_13);
															tempOptSys.fillTracingVectorInteraction(13, mOptSysEle.getPosAndInteraction_LLT().at(13).getInteractionAtSur_ptr());

															mPossibleOpticalSystem_LLT.push_back(tempOptSys.clone());

															tempOptSys.cleanSurfaceAndInteractionStartAt_i(13);
														}
														tempOptSys.cleanSurfaceAndInteractionStartAt_i(12);
													}
													tempOptSys.cleanSurfaceAndInteractionStartAt_i(11);
												}
												tempOptSys.cleanSurfaceAndInteractionStartAt_i(10);
											}
											tempOptSys.cleanSurfaceAndInteractionStartAt_i(9);
										}


										tempOptSys.cleanSurfaceAndInteractionStartAt_i(8);
									}


									tempOptSys.cleanSurfaceAndInteractionStartAt_i(7);
								}


								tempOptSys.cleanSurfaceAndInteractionStartAt_i(6);
							}
							tempOptSys.cleanSurfaceAndInteractionStartAt_i(5);

						}

						tempOptSys.cleanSurfaceAndInteractionStartAt_i(4);

					}
					tempOptSys.cleanSurfaceAndInteractionStartAt_i(3);
				}
				tempOptSys.cleanSurfaceAndInteractionStartAt_i(2);
			}
			tempOptSys.cleanSurfaceAndInteractionStartAt_i(1);
		}
		//tempOptSys.cleanSurfaceAndInteractionStartAt_i(0);
	}


}
void BuildSystemsForCombination::buildOpticalSystemCombination_14Surfaces_Element()
{
	unsigned int numberSurfaces = mVector_vectorWithSurfacePointer_Element.size();
	//unsigned int numberSurfaces = mVector_vectorWithSurfacePointer_LLT.size();

	//std::vector<std::shared_ptr<InteractionRay_LLT>> tempInteractions_LLT;
	std::vector<std::shared_ptr<Element_CR>> tempInteractions_Element;
	OpticalSystemElement tempOptSysElement;
	//OpticalSystemElement tempOptSys;

	std::shared_ptr<Element_CR> surface_0;
	std::shared_ptr<Element_CR> surface_1;
	std::shared_ptr<Element_CR> surface_2;
	std::shared_ptr<Element_CR> surface_3;
	std::shared_ptr<Element_CR> surface_4;
	std::shared_ptr<Element_CR> surface_5;
	std::shared_ptr<Element_CR> surface_6;
	std::shared_ptr<Element_CR> surface_7;
	std::shared_ptr<Element_CR> surface_8;
	std::shared_ptr<Element_CR> surface_9;
	std::shared_ptr<Element_CR> surface_10;
	std::shared_ptr<Element_CR> surface_11;
	std::shared_ptr<Element_CR> surface_12;
	std::shared_ptr<Element_CR> surface_13;

	for (unsigned int a = 0; a < mVector_vectorWithSurfacePointer_Element.at(0).size(); a++)
	{
		surface_0 = mVector_vectorWithSurfacePointer_Element.at(0).at(a);
		tempOptSysElement.fillPosAndElementAndInteraction(0, surface_0, mOptSysEle.getPosAndInteraction_LLT()[0].getInteractionAtSur_ptr());

		for (unsigned int b = 0; b < mVector_vectorWithSurfacePointer_Element.at(1).size(); b++)
		{
			surface_1 = mVector_vectorWithSurfacePointer_Element.at(1).at(b);
			tempOptSysElement.fillPosAndElementAndInteraction(1, surface_1, mOptSysEle.getPosAndInteraction_LLT()[1].getInteractionAtSur_ptr());

			for (unsigned int c = 0; c < mVector_vectorWithSurfacePointer_Element.at(2).size(); c++)
			{
				surface_2 = mVector_vectorWithSurfacePointer_Element.at(2).at(c);
				tempOptSysElement.fillPosAndElementAndInteraction(2, surface_2, mOptSysEle.getPosAndInteraction_LLT()[2].getInteractionAtSur_ptr());

				for (unsigned int d = 0; d < mVector_vectorWithSurfacePointer_Element.at(3).size(); d++)
				{
					surface_3 = mVector_vectorWithSurfacePointer_Element.at(3).at(d);
					tempOptSysElement.fillPosAndElementAndInteraction(3, surface_3, mOptSysEle.getPosAndInteraction_LLT()[3].getInteractionAtSur_ptr());

					for (unsigned int e = 0; e < mVector_vectorWithSurfacePointer_Element.at(4).size(); e++)
					{
						surface_4 = mVector_vectorWithSurfacePointer_Element.at(4).at(e);
						tempOptSysElement.fillPosAndElementAndInteraction(4, surface_4, mOptSysEle.getPosAndInteraction_LLT()[4].getInteractionAtSur_ptr());

						for (unsigned int f = 0; f < mVector_vectorWithSurfacePointer_Element.at(5).size(); f++)
						{
							surface_5 = mVector_vectorWithSurfacePointer_Element.at(5).at(f);
							tempOptSysElement.fillPosAndElementAndInteraction(5, surface_5, mOptSysEle.getPosAndInteraction_LLT()[5].getInteractionAtSur_ptr());

							for (unsigned int g = 0; g < mVector_vectorWithSurfacePointer_Element.at(6).size(); g++)
							{
								surface_6 = mVector_vectorWithSurfacePointer_Element.at(6).at(g);
								tempOptSysElement.fillPosAndElementAndInteraction(6, surface_6, mOptSysEle.getPosAndInteraction_LLT()[6].getInteractionAtSur_ptr());

								for (unsigned int h = 0; h < mVector_vectorWithSurfacePointer_Element.at(7).size(); h++)
								{
									surface_7 = mVector_vectorWithSurfacePointer_Element.at(7).at(h);
									tempOptSysElement.fillPosAndElementAndInteraction(7, surface_7, mOptSysEle.getPosAndInteraction_LLT()[7].getInteractionAtSur_ptr());

									for (unsigned int i = 0; i < mVector_vectorWithSurfacePointer_Element.at(8).size(); i++)
									{
										surface_8 = mVector_vectorWithSurfacePointer_Element.at(8).at(i);
										tempOptSysElement.fillPosAndElementAndInteraction(8, surface_8, mOptSysEle.getPosAndInteraction_LLT()[8].getInteractionAtSur_ptr());

										for (unsigned int j = 0; j < mVector_vectorWithSurfacePointer_Element.at(9).size(); j++)
										{

											surface_9 = mVector_vectorWithSurfacePointer_Element.at(9).at(j);
											tempOptSysElement.fillPosAndElementAndInteraction(9, surface_9, mOptSysEle.getPosAndInteraction_LLT()[9].getInteractionAtSur_ptr());

											for (unsigned int i = 0; i < mVector_vectorWithSurfacePointer_Element.at(10).size(); i++)
											{
												surface_10 = mVector_vectorWithSurfacePointer_Element.at(10).at(i);
												tempOptSysElement.fillPosAndElementAndInteraction(10, surface_10, mOptSysEle.getPosAndInteraction_LLT()[10].getInteractionAtSur_ptr());

												for (unsigned int j = 0; j < mVector_vectorWithSurfacePointer_Element.at(11).size(); j++)
												{

													surface_11 = mVector_vectorWithSurfacePointer_Element.at(11).at(j);
													tempOptSysElement.fillPosAndElementAndInteraction(11, surface_11, mOptSysEle.getPosAndInteraction_LLT()[11].getInteractionAtSur_ptr());

													for (unsigned int i = 0; i < mVector_vectorWithSurfacePointer_Element.at(12).size(); i++)
													{
														surface_12 = mVector_vectorWithSurfacePointer_Element.at(10).at(i);
														tempOptSysElement.fillPosAndElementAndInteraction(12, surface_12, mOptSysEle.getPosAndInteraction_LLT()[12].getInteractionAtSur_ptr());

														for (unsigned int j = 0; j < mVector_vectorWithSurfacePointer_Element.at(13).size(); j++)
														{

															surface_13 = mVector_vectorWithSurfacePointer_Element.at(13).at(j);
															tempOptSysElement.fillPosAndElementAndInteraction(13, surface_13, mOptSysEle.getPosAndInteraction_LLT()[13].getInteractionAtSur_ptr());

															mPossibleOpticalSys_Element.push_back(tempOptSysElement.getDeepCopyOptSysEle());

															tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(13);
														}
														tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(12);
													}
													tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(11);
												}
												tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(10);
											}
											tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(9);
										}


										tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(8);
									}


									tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(7);
								}


								tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(6);
							}
							tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(5);

						}

						tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(4);

					}
					tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(3);
				}
				tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(2);
			}
			tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(1);
		}
		//tempOptSys.cleanSurfaceAndInteractionStartAt_i(0);
	}


}
void BuildSystemsForCombination::buildOpticalSystemCombination_15Surfaces_LLT()
{
	unsigned int numberSurfaces = mVector_vectorWithSurfacePointer_LLT.size();


	std::vector<std::shared_ptr<InteractionRay_LLT>> tempInteractions_LLT;
	OpticalSystem_LLT tempOptSys;

	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_0;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_1;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_2;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_3;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_4;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_5;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_6;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_7;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_8;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_9;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_10;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_11;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_12;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_13;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_14;

	for (unsigned int a = 0; a < mVector_vectorWithSurfacePointer_LLT.at(0).size(); a++)
	{
		surface_0 = mVector_vectorWithSurfacePointer_LLT.at(0).at(a);
		tempOptSys.fillTracingVectorSurfaces(0, surface_0);
		tempOptSys.fillTracingVectorInteraction(0, mOptSysEle.getPosAndInteraction_LLT().at(0).getInteractionAtSur_ptr());

		for (unsigned int b = 0; b < mVector_vectorWithSurfacePointer_LLT.at(1).size(); b++)
		{
			surface_1 = mVector_vectorWithSurfacePointer_LLT.at(1).at(b);
			tempOptSys.fillTracingVectorSurfaces(1, surface_1);
			tempOptSys.fillTracingVectorInteraction(1, mOptSysEle.getPosAndInteraction_LLT().at(1).getInteractionAtSur_ptr());

			for (unsigned int c = 0; c < mVector_vectorWithSurfacePointer_LLT.at(2).size(); c++)
			{
				surface_2 = mVector_vectorWithSurfacePointer_LLT.at(2).at(c);
				tempOptSys.fillTracingVectorSurfaces(2, surface_2);
				tempOptSys.fillTracingVectorInteraction(2, mOptSysEle.getPosAndInteraction_LLT().at(2).getInteractionAtSur_ptr());

				for (unsigned int d = 0; d < mVector_vectorWithSurfacePointer_LLT.at(3).size(); d++)
				{
					surface_3 = mVector_vectorWithSurfacePointer_LLT.at(3).at(d);
					tempOptSys.fillTracingVectorSurfaces(3, surface_3);
					tempOptSys.fillTracingVectorInteraction(3, mOptSysEle.getPosAndInteraction_LLT().at(3).getInteractionAtSur_ptr());

					for (unsigned int e = 0; e < mVector_vectorWithSurfacePointer_LLT.at(4).size(); e++)
					{
						surface_4 = mVector_vectorWithSurfacePointer_LLT.at(4).at(e);
						tempOptSys.fillTracingVectorSurfaces(4, surface_4);
						tempOptSys.fillTracingVectorInteraction(4, mOptSysEle.getPosAndInteraction_LLT().at(4).getInteractionAtSur_ptr());

						for (unsigned int f = 0; f < mVector_vectorWithSurfacePointer_LLT.at(5).size(); f++)
						{
							surface_5 = mVector_vectorWithSurfacePointer_LLT.at(5).at(f);
							tempOptSys.fillTracingVectorSurfaces(5, surface_5);
							tempOptSys.fillTracingVectorInteraction(5, mOptSysEle.getPosAndInteraction_LLT().at(5).getInteractionAtSur_ptr());

							for (unsigned int g = 0; g < mVector_vectorWithSurfacePointer_LLT.at(6).size(); g++)
							{
								surface_6 = mVector_vectorWithSurfacePointer_LLT.at(6).at(g);
								tempOptSys.fillTracingVectorSurfaces(6, surface_6);
								tempOptSys.fillTracingVectorInteraction(6, mOptSysEle.getPosAndInteraction_LLT().at(6).getInteractionAtSur_ptr());

								for (unsigned int h = 0; h < mVector_vectorWithSurfacePointer_LLT.at(7).size(); h++)
								{
									surface_7 = mVector_vectorWithSurfacePointer_LLT.at(7).at(h);
									tempOptSys.fillTracingVectorSurfaces(7, surface_7);
									tempOptSys.fillTracingVectorInteraction(7, mOptSysEle.getPosAndInteraction_LLT().at(7).getInteractionAtSur_ptr());

									for (unsigned int i = 0; i < mVector_vectorWithSurfacePointer_LLT.at(8).size(); i++)
									{
										surface_8 = mVector_vectorWithSurfacePointer_LLT.at(8).at(i);
										tempOptSys.fillTracingVectorSurfaces(8, surface_8);
										tempOptSys.fillTracingVectorInteraction(8, mOptSysEle.getPosAndInteraction_LLT().at(8).getInteractionAtSur_ptr());

										for (unsigned int j = 0; j < mVector_vectorWithSurfacePointer_LLT.at(9).size(); j++)
										{
											surface_9 = mVector_vectorWithSurfacePointer_LLT.at(9).at(j);
											tempOptSys.fillTracingVectorSurfaces(9, surface_9);
											tempOptSys.fillTracingVectorInteraction(9, mOptSysEle.getPosAndInteraction_LLT().at(9).getInteractionAtSur_ptr());

											for (unsigned int i = 0; i < mVector_vectorWithSurfacePointer_LLT.at(10).size(); i++)
											{
												surface_10 = mVector_vectorWithSurfacePointer_LLT.at(10).at(i);
												tempOptSys.fillTracingVectorSurfaces(10, surface_10);
												tempOptSys.fillTracingVectorInteraction(10, mOptSysEle.getPosAndInteraction_LLT().at(10).getInteractionAtSur_ptr());

												for (unsigned int j = 0; j < mVector_vectorWithSurfacePointer_LLT.at(11).size(); j++)
												{
													surface_11 = mVector_vectorWithSurfacePointer_LLT.at(11).at(j);
													tempOptSys.fillTracingVectorSurfaces(11, surface_11);
													tempOptSys.fillTracingVectorInteraction(11, mOptSysEle.getPosAndInteraction_LLT().at(11).getInteractionAtSur_ptr());

													for (unsigned int i = 0; i < mVector_vectorWithSurfacePointer_LLT.at(12).size(); i++)
													{
														surface_12 = mVector_vectorWithSurfacePointer_LLT.at(12).at(i);
														tempOptSys.fillTracingVectorSurfaces(12, surface_12);
														tempOptSys.fillTracingVectorInteraction(12, mOptSysEle.getPosAndInteraction_LLT().at(12).getInteractionAtSur_ptr());

														for (unsigned int j = 0; j < mVector_vectorWithSurfacePointer_LLT.at(13).size(); j++)
														{
															surface_13 = mVector_vectorWithSurfacePointer_LLT.at(13).at(j);
															tempOptSys.fillTracingVectorSurfaces(13, surface_13);
															tempOptSys.fillTracingVectorInteraction(13, mOptSysEle.getPosAndInteraction_LLT().at(13).getInteractionAtSur_ptr());

															for (unsigned int i = 0; i < mVector_vectorWithSurfacePointer_LLT.at(14).size(); i++)
															{
																surface_14 = mVector_vectorWithSurfacePointer_LLT.at(14).at(i);
																tempOptSys.fillTracingVectorSurfaces(14, surface_14);
																tempOptSys.fillTracingVectorInteraction(14, mOptSysEle.getPosAndInteraction_LLT().at(14).getInteractionAtSur_ptr());

																mPossibleOpticalSystem_LLT.push_back(tempOptSys.clone());

																tempOptSys.cleanSurfaceAndInteractionStartAt_i(14);
															}
															tempOptSys.cleanSurfaceAndInteractionStartAt_i(13);
														}
														tempOptSys.cleanSurfaceAndInteractionStartAt_i(12);
													}
													tempOptSys.cleanSurfaceAndInteractionStartAt_i(11);
												}
												tempOptSys.cleanSurfaceAndInteractionStartAt_i(10);
											}
											tempOptSys.cleanSurfaceAndInteractionStartAt_i(9);
										}


										tempOptSys.cleanSurfaceAndInteractionStartAt_i(8);
									}


									tempOptSys.cleanSurfaceAndInteractionStartAt_i(7);
								}


								tempOptSys.cleanSurfaceAndInteractionStartAt_i(6);
							}
							tempOptSys.cleanSurfaceAndInteractionStartAt_i(5);

						}

						tempOptSys.cleanSurfaceAndInteractionStartAt_i(4);

					}
					tempOptSys.cleanSurfaceAndInteractionStartAt_i(3);
				}
				tempOptSys.cleanSurfaceAndInteractionStartAt_i(2);
			}
			tempOptSys.cleanSurfaceAndInteractionStartAt_i(1);
		}
		//tempOptSys.cleanSurfaceAndInteractionStartAt_i(0);
	}


}
void BuildSystemsForCombination::buildOpticalSystemCombination_15Surfaces_Element()
{
	unsigned int numberSurfaces = mVector_vectorWithSurfacePointer_Element.size();
	//unsigned int numberSurfaces = mVector_vectorWithSurfacePointer_LLT.size();

	//std::vector<std::shared_ptr<InteractionRay_LLT>> tempInteractions_LLT;
	std::vector<std::shared_ptr<Element_CR>> tempInteractions_Element;
	OpticalSystemElement tempOptSysElement;
	//OpticalSystemElement tempOptSys;

	std::shared_ptr<Element_CR> surface_0;
	std::shared_ptr<Element_CR> surface_1;
	std::shared_ptr<Element_CR> surface_2;
	std::shared_ptr<Element_CR> surface_3;
	std::shared_ptr<Element_CR> surface_4;
	std::shared_ptr<Element_CR> surface_5;
	std::shared_ptr<Element_CR> surface_6;
	std::shared_ptr<Element_CR> surface_7;
	std::shared_ptr<Element_CR> surface_8;
	std::shared_ptr<Element_CR> surface_9;
	std::shared_ptr<Element_CR> surface_10;
	std::shared_ptr<Element_CR> surface_11;
	std::shared_ptr<Element_CR> surface_12;
	std::shared_ptr<Element_CR> surface_13;
	std::shared_ptr<Element_CR> surface_14;

	for (unsigned int a = 0; a < mVector_vectorWithSurfacePointer_Element.at(0).size(); a++)
	{
		surface_0 = mVector_vectorWithSurfacePointer_Element.at(0).at(a);
		tempOptSysElement.fillPosAndElementAndInteraction(0, surface_0, mOptSysEle.getPosAndInteraction_LLT()[0].getInteractionAtSur_ptr());

		for (unsigned int b = 0; b < mVector_vectorWithSurfacePointer_Element.at(1).size(); b++)
		{
			surface_1 = mVector_vectorWithSurfacePointer_Element.at(1).at(b);
			tempOptSysElement.fillPosAndElementAndInteraction(1, surface_1, mOptSysEle.getPosAndInteraction_LLT()[1].getInteractionAtSur_ptr());

			for (unsigned int c = 0; c < mVector_vectorWithSurfacePointer_Element.at(2).size(); c++)
			{
				surface_2 = mVector_vectorWithSurfacePointer_Element.at(2).at(c);
				tempOptSysElement.fillPosAndElementAndInteraction(2, surface_2, mOptSysEle.getPosAndInteraction_LLT()[2].getInteractionAtSur_ptr());

				for (unsigned int d = 0; d < mVector_vectorWithSurfacePointer_Element.at(3).size(); d++)
				{
					surface_3 = mVector_vectorWithSurfacePointer_Element.at(3).at(d);
					tempOptSysElement.fillPosAndElementAndInteraction(3, surface_3, mOptSysEle.getPosAndInteraction_LLT()[3].getInteractionAtSur_ptr());

					for (unsigned int e = 0; e < mVector_vectorWithSurfacePointer_Element.at(4).size(); e++)
					{
						surface_4 = mVector_vectorWithSurfacePointer_Element.at(4).at(e);
						tempOptSysElement.fillPosAndElementAndInteraction(4, surface_4, mOptSysEle.getPosAndInteraction_LLT()[4].getInteractionAtSur_ptr());

						for (unsigned int f = 0; f < mVector_vectorWithSurfacePointer_Element.at(5).size(); f++)
						{
							surface_5 = mVector_vectorWithSurfacePointer_Element.at(5).at(f);
							tempOptSysElement.fillPosAndElementAndInteraction(5, surface_5, mOptSysEle.getPosAndInteraction_LLT()[5].getInteractionAtSur_ptr());

							for (unsigned int g = 0; g < mVector_vectorWithSurfacePointer_Element.at(6).size(); g++)
							{
								surface_6 = mVector_vectorWithSurfacePointer_Element.at(6).at(g);
								tempOptSysElement.fillPosAndElementAndInteraction(6, surface_6, mOptSysEle.getPosAndInteraction_LLT()[6].getInteractionAtSur_ptr());

								for (unsigned int h = 0; h < mVector_vectorWithSurfacePointer_Element.at(7).size(); h++)
								{
									surface_7 = mVector_vectorWithSurfacePointer_Element.at(7).at(h);
									tempOptSysElement.fillPosAndElementAndInteraction(7, surface_7, mOptSysEle.getPosAndInteraction_LLT()[7].getInteractionAtSur_ptr());

									for (unsigned int i = 0; i < mVector_vectorWithSurfacePointer_Element.at(8).size(); i++)
									{
										surface_8 = mVector_vectorWithSurfacePointer_Element.at(8).at(i);
										tempOptSysElement.fillPosAndElementAndInteraction(8, surface_8, mOptSysEle.getPosAndInteraction_LLT()[8].getInteractionAtSur_ptr());

										for (unsigned int j = 0; j < mVector_vectorWithSurfacePointer_Element.at(9).size(); j++)
										{

											surface_9 = mVector_vectorWithSurfacePointer_Element.at(9).at(j);
											tempOptSysElement.fillPosAndElementAndInteraction(9, surface_9, mOptSysEle.getPosAndInteraction_LLT()[9].getInteractionAtSur_ptr());

											for (unsigned int i = 0; i < mVector_vectorWithSurfacePointer_Element.at(10).size(); i++)
											{
												surface_10 = mVector_vectorWithSurfacePointer_Element.at(10).at(i);
												tempOptSysElement.fillPosAndElementAndInteraction(10, surface_10, mOptSysEle.getPosAndInteraction_LLT()[10].getInteractionAtSur_ptr());

												for (unsigned int j = 0; j < mVector_vectorWithSurfacePointer_Element.at(11).size(); j++)
												{

													surface_11 = mVector_vectorWithSurfacePointer_Element.at(11).at(j);
													tempOptSysElement.fillPosAndElementAndInteraction(11, surface_11, mOptSysEle.getPosAndInteraction_LLT()[11].getInteractionAtSur_ptr());

													for (unsigned int i = 0; i < mVector_vectorWithSurfacePointer_Element.at(12).size(); i++)
													{
														surface_12 = mVector_vectorWithSurfacePointer_Element.at(10).at(i);
														tempOptSysElement.fillPosAndElementAndInteraction(12, surface_12, mOptSysEle.getPosAndInteraction_LLT()[12].getInteractionAtSur_ptr());

														for (unsigned int j = 0; j < mVector_vectorWithSurfacePointer_Element.at(13).size(); j++)
														{

															surface_13 = mVector_vectorWithSurfacePointer_Element.at(13).at(j);
															tempOptSysElement.fillPosAndElementAndInteraction(13, surface_13, mOptSysEle.getPosAndInteraction_LLT()[13].getInteractionAtSur_ptr());


															for (unsigned int i = 0; i < mVector_vectorWithSurfacePointer_Element.at(14).size(); i++)
															{
																surface_14 = mVector_vectorWithSurfacePointer_Element.at(14).at(i);
																tempOptSysElement.fillPosAndElementAndInteraction(14, surface_14, mOptSysEle.getPosAndInteraction_LLT()[14].getInteractionAtSur_ptr());

																mPossibleOpticalSys_Element.push_back(tempOptSysElement.getDeepCopyOptSysEle());

																tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(14);
															}
															tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(13);
														}
														tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(12);
													}
													tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(11);
												}
												tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(10);
											}
											tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(9);
										}


										tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(8);
									}


									tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(7);
								}


								tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(6);
							}
							tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(5);

						}

						tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(4);

					}
					tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(3);
				}
				tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(2);
			}
			tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(1);
		}
		//tempOptSys.cleanSurfaceAndInteractionStartAt_i(0);
	}


}

void BuildSystemsForCombination::buildOpticalSystemCombination_16Surfaces_LLT()
{
	unsigned int numberSurfaces = mVector_vectorWithSurfacePointer_LLT.size();


	std::vector<std::shared_ptr<InteractionRay_LLT>> tempInteractions_LLT;
	OpticalSystem_LLT tempOptSys;

	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_0;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_1;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_2;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_3;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_4;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_5;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_6;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_7;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_8;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_9;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_10;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_11;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_12;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_13;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_14;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_15;

	for (unsigned int a = 0; a < mVector_vectorWithSurfacePointer_LLT.at(0).size(); a++)
	{
		surface_0 = mVector_vectorWithSurfacePointer_LLT.at(0).at(a);
		tempOptSys.fillTracingVectorSurfaces(0, surface_0);
		tempOptSys.fillTracingVectorInteraction(0, mOptSysEle.getPosAndInteraction_LLT().at(0).getInteractionAtSur_ptr());

		for (unsigned int b = 0; b < mVector_vectorWithSurfacePointer_LLT.at(1).size(); b++)
		{
			surface_1 = mVector_vectorWithSurfacePointer_LLT.at(1).at(b);
			tempOptSys.fillTracingVectorSurfaces(1, surface_1);
			tempOptSys.fillTracingVectorInteraction(1, mOptSysEle.getPosAndInteraction_LLT().at(1).getInteractionAtSur_ptr());

			for (unsigned int c = 0; c < mVector_vectorWithSurfacePointer_LLT.at(2).size(); c++)
			{
				surface_2 = mVector_vectorWithSurfacePointer_LLT.at(2).at(c);
				tempOptSys.fillTracingVectorSurfaces(2, surface_2);
				tempOptSys.fillTracingVectorInteraction(2, mOptSysEle.getPosAndInteraction_LLT().at(2).getInteractionAtSur_ptr());

				for (unsigned int d = 0; d < mVector_vectorWithSurfacePointer_LLT.at(3).size(); d++)
				{
					surface_3 = mVector_vectorWithSurfacePointer_LLT.at(3).at(d);
					tempOptSys.fillTracingVectorSurfaces(3, surface_3);
					tempOptSys.fillTracingVectorInteraction(3, mOptSysEle.getPosAndInteraction_LLT().at(3).getInteractionAtSur_ptr());

					for (unsigned int e = 0; e < mVector_vectorWithSurfacePointer_LLT.at(4).size(); e++)
					{
						surface_4 = mVector_vectorWithSurfacePointer_LLT.at(4).at(e);
						tempOptSys.fillTracingVectorSurfaces(4, surface_4);
						tempOptSys.fillTracingVectorInteraction(4, mOptSysEle.getPosAndInteraction_LLT().at(4).getInteractionAtSur_ptr());

						for (unsigned int f = 0; f < mVector_vectorWithSurfacePointer_LLT.at(5).size(); f++)
						{
							surface_5 = mVector_vectorWithSurfacePointer_LLT.at(5).at(f);
							tempOptSys.fillTracingVectorSurfaces(5, surface_5);
							tempOptSys.fillTracingVectorInteraction(5, mOptSysEle.getPosAndInteraction_LLT().at(5).getInteractionAtSur_ptr());

							for (unsigned int g = 0; g < mVector_vectorWithSurfacePointer_LLT.at(6).size(); g++)
							{
								surface_6 = mVector_vectorWithSurfacePointer_LLT.at(6).at(g);
								tempOptSys.fillTracingVectorSurfaces(6, surface_6);
								tempOptSys.fillTracingVectorInteraction(6, mOptSysEle.getPosAndInteraction_LLT().at(6).getInteractionAtSur_ptr());

								for (unsigned int h = 0; h < mVector_vectorWithSurfacePointer_LLT.at(7).size(); h++)
								{
									surface_7 = mVector_vectorWithSurfacePointer_LLT.at(7).at(h);
									tempOptSys.fillTracingVectorSurfaces(7, surface_7);
									tempOptSys.fillTracingVectorInteraction(7, mOptSysEle.getPosAndInteraction_LLT().at(7).getInteractionAtSur_ptr());

									for (unsigned int i = 0; i < mVector_vectorWithSurfacePointer_LLT.at(8).size(); i++)
									{
										surface_8 = mVector_vectorWithSurfacePointer_LLT.at(8).at(i);
										tempOptSys.fillTracingVectorSurfaces(8, surface_8);
										tempOptSys.fillTracingVectorInteraction(8, mOptSysEle.getPosAndInteraction_LLT().at(8).getInteractionAtSur_ptr());

										for (unsigned int j = 0; j < mVector_vectorWithSurfacePointer_LLT.at(9).size(); j++)
										{
											surface_9 = mVector_vectorWithSurfacePointer_LLT.at(9).at(j);
											tempOptSys.fillTracingVectorSurfaces(9, surface_9);
											tempOptSys.fillTracingVectorInteraction(9, mOptSysEle.getPosAndInteraction_LLT().at(9).getInteractionAtSur_ptr());

											for (unsigned int i = 0; i < mVector_vectorWithSurfacePointer_LLT.at(10).size(); i++)
											{
												surface_10 = mVector_vectorWithSurfacePointer_LLT.at(10).at(i);
												tempOptSys.fillTracingVectorSurfaces(10, surface_10);
												tempOptSys.fillTracingVectorInteraction(10, mOptSysEle.getPosAndInteraction_LLT().at(10).getInteractionAtSur_ptr());

												for (unsigned int j = 0; j < mVector_vectorWithSurfacePointer_LLT.at(11).size(); j++)
												{
													surface_11 = mVector_vectorWithSurfacePointer_LLT.at(11).at(j);
													tempOptSys.fillTracingVectorSurfaces(11, surface_11);
													tempOptSys.fillTracingVectorInteraction(11, mOptSysEle.getPosAndInteraction_LLT().at(11).getInteractionAtSur_ptr());

													for (unsigned int i = 0; i < mVector_vectorWithSurfacePointer_LLT.at(12).size(); i++)
													{
														surface_12 = mVector_vectorWithSurfacePointer_LLT.at(12).at(i);
														tempOptSys.fillTracingVectorSurfaces(12, surface_12);
														tempOptSys.fillTracingVectorInteraction(12, mOptSysEle.getPosAndInteraction_LLT().at(12).getInteractionAtSur_ptr());

														for (unsigned int j = 0; j < mVector_vectorWithSurfacePointer_LLT.at(13).size(); j++)
														{
															surface_13 = mVector_vectorWithSurfacePointer_LLT.at(13).at(j);
															tempOptSys.fillTracingVectorSurfaces(13, surface_13);
															tempOptSys.fillTracingVectorInteraction(13, mOptSysEle.getPosAndInteraction_LLT().at(13).getInteractionAtSur_ptr());

															for (unsigned int i = 0; i < mVector_vectorWithSurfacePointer_LLT.at(14).size(); i++)
															{
																surface_14 = mVector_vectorWithSurfacePointer_LLT.at(14).at(i);
																tempOptSys.fillTracingVectorSurfaces(14, surface_14);
																tempOptSys.fillTracingVectorInteraction(14, mOptSysEle.getPosAndInteraction_LLT().at(14).getInteractionAtSur_ptr());



																for (unsigned int j = 0; j < mVector_vectorWithSurfacePointer_LLT.at(15).size(); j++)
																{
																	surface_15 = mVector_vectorWithSurfacePointer_LLT.at(15).at(j);
																	tempOptSys.fillTracingVectorSurfaces(15, surface_15);
																	tempOptSys.fillTracingVectorInteraction(15, mOptSysEle.getPosAndInteraction_LLT().at(15).getInteractionAtSur_ptr());

																	mPossibleOpticalSystem_LLT.push_back(tempOptSys.clone());

																	tempOptSys.cleanSurfaceAndInteractionStartAt_i(15);

																}
																tempOptSys.cleanSurfaceAndInteractionStartAt_i(14);
															}
															tempOptSys.cleanSurfaceAndInteractionStartAt_i(13);
														}
														tempOptSys.cleanSurfaceAndInteractionStartAt_i(12);
													}
													tempOptSys.cleanSurfaceAndInteractionStartAt_i(11);
												}
												tempOptSys.cleanSurfaceAndInteractionStartAt_i(10);
											}
											tempOptSys.cleanSurfaceAndInteractionStartAt_i(9);
										}


										tempOptSys.cleanSurfaceAndInteractionStartAt_i(8);
									}


									tempOptSys.cleanSurfaceAndInteractionStartAt_i(7);
								}


								tempOptSys.cleanSurfaceAndInteractionStartAt_i(6);
							}
							tempOptSys.cleanSurfaceAndInteractionStartAt_i(5);

						}

						tempOptSys.cleanSurfaceAndInteractionStartAt_i(4);

					}
					tempOptSys.cleanSurfaceAndInteractionStartAt_i(3);
				}
				tempOptSys.cleanSurfaceAndInteractionStartAt_i(2);
			}
			tempOptSys.cleanSurfaceAndInteractionStartAt_i(1);
		}
		//tempOptSys.cleanSurfaceAndInteractionStartAt_i(0);
	}


}
void BuildSystemsForCombination::buildOpticalSystemCombination_16Surfaces_Element()
{
	unsigned int numberSurfaces = mVector_vectorWithSurfacePointer_Element.size();
	//unsigned int numberSurfaces = mVector_vectorWithSurfacePointer_LLT.size();

	//std::vector<std::shared_ptr<InteractionRay_LLT>> tempInteractions_LLT;
	std::vector<std::shared_ptr<Element_CR>> tempInteractions_Element;
	OpticalSystemElement tempOptSysElement;
	//OpticalSystemElement tempOptSys;

	std::shared_ptr<Element_CR> surface_0;
	std::shared_ptr<Element_CR> surface_1;
	std::shared_ptr<Element_CR> surface_2;
	std::shared_ptr<Element_CR> surface_3;
	std::shared_ptr<Element_CR> surface_4;
	std::shared_ptr<Element_CR> surface_5;
	std::shared_ptr<Element_CR> surface_6;
	std::shared_ptr<Element_CR> surface_7;
	std::shared_ptr<Element_CR> surface_8;
	std::shared_ptr<Element_CR> surface_9;
	std::shared_ptr<Element_CR> surface_10;
	std::shared_ptr<Element_CR> surface_11;
	std::shared_ptr<Element_CR> surface_12;
	std::shared_ptr<Element_CR> surface_13;
	std::shared_ptr<Element_CR> surface_14;
	std::shared_ptr<Element_CR> surface_15;

	for (unsigned int a = 0; a < mVector_vectorWithSurfacePointer_Element.at(0).size(); a++)
	{
		surface_0 = mVector_vectorWithSurfacePointer_Element.at(0).at(a);
		tempOptSysElement.fillPosAndElementAndInteraction(0, surface_0, mOptSysEle.getPosAndInteraction_LLT()[0].getInteractionAtSur_ptr());

		for (unsigned int b = 0; b < mVector_vectorWithSurfacePointer_Element.at(1).size(); b++)
		{
			surface_1 = mVector_vectorWithSurfacePointer_Element.at(1).at(b);
			tempOptSysElement.fillPosAndElementAndInteraction(1, surface_1, mOptSysEle.getPosAndInteraction_LLT()[1].getInteractionAtSur_ptr());

			for (unsigned int c = 0; c < mVector_vectorWithSurfacePointer_Element.at(2).size(); c++)
			{
				surface_2 = mVector_vectorWithSurfacePointer_Element.at(2).at(c);
				tempOptSysElement.fillPosAndElementAndInteraction(2, surface_2, mOptSysEle.getPosAndInteraction_LLT()[2].getInteractionAtSur_ptr());

				for (unsigned int d = 0; d < mVector_vectorWithSurfacePointer_Element.at(3).size(); d++)
				{
					surface_3 = mVector_vectorWithSurfacePointer_Element.at(3).at(d);
					tempOptSysElement.fillPosAndElementAndInteraction(3, surface_3, mOptSysEle.getPosAndInteraction_LLT()[3].getInteractionAtSur_ptr());

					for (unsigned int e = 0; e < mVector_vectorWithSurfacePointer_Element.at(4).size(); e++)
					{
						surface_4 = mVector_vectorWithSurfacePointer_Element.at(4).at(e);
						tempOptSysElement.fillPosAndElementAndInteraction(4, surface_4, mOptSysEle.getPosAndInteraction_LLT()[4].getInteractionAtSur_ptr());

						for (unsigned int f = 0; f < mVector_vectorWithSurfacePointer_Element.at(5).size(); f++)
						{
							surface_5 = mVector_vectorWithSurfacePointer_Element.at(5).at(f);
							tempOptSysElement.fillPosAndElementAndInteraction(5, surface_5, mOptSysEle.getPosAndInteraction_LLT()[5].getInteractionAtSur_ptr());

							for (unsigned int g = 0; g < mVector_vectorWithSurfacePointer_Element.at(6).size(); g++)
							{
								surface_6 = mVector_vectorWithSurfacePointer_Element.at(6).at(g);
								tempOptSysElement.fillPosAndElementAndInteraction(6, surface_6, mOptSysEle.getPosAndInteraction_LLT()[6].getInteractionAtSur_ptr());

								for (unsigned int h = 0; h < mVector_vectorWithSurfacePointer_Element.at(7).size(); h++)
								{
									surface_7 = mVector_vectorWithSurfacePointer_Element.at(7).at(h);
									tempOptSysElement.fillPosAndElementAndInteraction(7, surface_7, mOptSysEle.getPosAndInteraction_LLT()[7].getInteractionAtSur_ptr());

									for (unsigned int i = 0; i < mVector_vectorWithSurfacePointer_Element.at(8).size(); i++)
									{
										surface_8 = mVector_vectorWithSurfacePointer_Element.at(8).at(i);
										tempOptSysElement.fillPosAndElementAndInteraction(8, surface_8, mOptSysEle.getPosAndInteraction_LLT()[8].getInteractionAtSur_ptr());

										for (unsigned int j = 0; j < mVector_vectorWithSurfacePointer_Element.at(9).size(); j++)
										{

											surface_9 = mVector_vectorWithSurfacePointer_Element.at(9).at(j);
											tempOptSysElement.fillPosAndElementAndInteraction(9, surface_9, mOptSysEle.getPosAndInteraction_LLT()[9].getInteractionAtSur_ptr());

											for (unsigned int i = 0; i < mVector_vectorWithSurfacePointer_Element.at(10).size(); i++)
											{
												surface_10 = mVector_vectorWithSurfacePointer_Element.at(10).at(i);
												tempOptSysElement.fillPosAndElementAndInteraction(10, surface_10, mOptSysEle.getPosAndInteraction_LLT()[10].getInteractionAtSur_ptr());

												for (unsigned int j = 0; j < mVector_vectorWithSurfacePointer_Element.at(11).size(); j++)
												{

													surface_11 = mVector_vectorWithSurfacePointer_Element.at(11).at(j);
													tempOptSysElement.fillPosAndElementAndInteraction(11, surface_11, mOptSysEle.getPosAndInteraction_LLT()[11].getInteractionAtSur_ptr());

													for (unsigned int i = 0; i < mVector_vectorWithSurfacePointer_Element.at(12).size(); i++)
													{
														surface_12 = mVector_vectorWithSurfacePointer_Element.at(10).at(i);
														tempOptSysElement.fillPosAndElementAndInteraction(12, surface_12, mOptSysEle.getPosAndInteraction_LLT()[12].getInteractionAtSur_ptr());

														for (unsigned int j = 0; j < mVector_vectorWithSurfacePointer_Element.at(13).size(); j++)
														{

															surface_13 = mVector_vectorWithSurfacePointer_Element.at(13).at(j);
															tempOptSysElement.fillPosAndElementAndInteraction(13, surface_13, mOptSysEle.getPosAndInteraction_LLT()[13].getInteractionAtSur_ptr());


															for (unsigned int i = 0; i < mVector_vectorWithSurfacePointer_Element.at(14).size(); i++)
															{
																surface_14 = mVector_vectorWithSurfacePointer_Element.at(14).at(i);
																tempOptSysElement.fillPosAndElementAndInteraction(14, surface_14, mOptSysEle.getPosAndInteraction_LLT()[14].getInteractionAtSur_ptr());

																for (unsigned int j = 0; j < mVector_vectorWithSurfacePointer_Element.at(15).size(); j++)
																{

																	surface_15 = mVector_vectorWithSurfacePointer_Element.at(15).at(j);
																	tempOptSysElement.fillPosAndElementAndInteraction(15, surface_15, mOptSysEle.getPosAndInteraction_LLT()[15].getInteractionAtSur_ptr());

																	mPossibleOpticalSys_Element.push_back(tempOptSysElement.getDeepCopyOptSysEle());

																	tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(15);
																}
																tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(14);
															}
															tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(13);
														}
														tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(12);
													}
													tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(11);
												}
												tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(10);
											}
											tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(9);
										}


										tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(8);
									}


									tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(7);
								}


								tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(6);
							}
							tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(5);

						}

						tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(4);

					}
					tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(3);
				}
				tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(2);
			}
			tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(1);
		}
		//tempOptSys.cleanSurfaceAndInteractionStartAt_i(0);
	}


}
void BuildSystemsForCombination::buildOpticalSystemCombination_17Surfaces_LLT()
{
	unsigned int numberSurfaces = mVector_vectorWithSurfacePointer_LLT.size();


	std::vector<std::shared_ptr<InteractionRay_LLT>> tempInteractions_LLT;
	OpticalSystem_LLT tempOptSys;

	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_0;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_1;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_2;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_3;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_4;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_5;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_6;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_7;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_8;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_9;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_10;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_11;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_12;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_13;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_14;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_15;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_16;

	for (unsigned int a = 0; a < mVector_vectorWithSurfacePointer_LLT.at(0).size(); a++)
	{
		surface_0 = mVector_vectorWithSurfacePointer_LLT.at(0).at(a);
		tempOptSys.fillTracingVectorSurfaces(0, surface_0);
		tempOptSys.fillTracingVectorInteraction(0, mOptSysEle.getPosAndInteraction_LLT().at(0).getInteractionAtSur_ptr());

		for (unsigned int b = 0; b < mVector_vectorWithSurfacePointer_LLT.at(1).size(); b++)
		{
			surface_1 = mVector_vectorWithSurfacePointer_LLT.at(1).at(b);
			tempOptSys.fillTracingVectorSurfaces(1, surface_1);
			tempOptSys.fillTracingVectorInteraction(1, mOptSysEle.getPosAndInteraction_LLT().at(1).getInteractionAtSur_ptr());

			for (unsigned int c = 0; c < mVector_vectorWithSurfacePointer_LLT.at(2).size(); c++)
			{
				surface_2 = mVector_vectorWithSurfacePointer_LLT.at(2).at(c);
				tempOptSys.fillTracingVectorSurfaces(2, surface_2);
				tempOptSys.fillTracingVectorInteraction(2, mOptSysEle.getPosAndInteraction_LLT().at(2).getInteractionAtSur_ptr());

				for (unsigned int d = 0; d < mVector_vectorWithSurfacePointer_LLT.at(3).size(); d++)
				{
					surface_3 = mVector_vectorWithSurfacePointer_LLT.at(3).at(d);
					tempOptSys.fillTracingVectorSurfaces(3, surface_3);
					tempOptSys.fillTracingVectorInteraction(3, mOptSysEle.getPosAndInteraction_LLT().at(3).getInteractionAtSur_ptr());

					for (unsigned int e = 0; e < mVector_vectorWithSurfacePointer_LLT.at(4).size(); e++)
					{
						surface_4 = mVector_vectorWithSurfacePointer_LLT.at(4).at(e);
						tempOptSys.fillTracingVectorSurfaces(4, surface_4);
						tempOptSys.fillTracingVectorInteraction(4, mOptSysEle.getPosAndInteraction_LLT().at(4).getInteractionAtSur_ptr());

						for (unsigned int f = 0; f < mVector_vectorWithSurfacePointer_LLT.at(5).size(); f++)
						{
							surface_5 = mVector_vectorWithSurfacePointer_LLT.at(5).at(f);
							tempOptSys.fillTracingVectorSurfaces(5, surface_5);
							tempOptSys.fillTracingVectorInteraction(5, mOptSysEle.getPosAndInteraction_LLT().at(5).getInteractionAtSur_ptr());

							for (unsigned int g = 0; g < mVector_vectorWithSurfacePointer_LLT.at(6).size(); g++)
							{
								surface_6 = mVector_vectorWithSurfacePointer_LLT.at(6).at(g);
								tempOptSys.fillTracingVectorSurfaces(6, surface_6);
								tempOptSys.fillTracingVectorInteraction(6, mOptSysEle.getPosAndInteraction_LLT().at(6).getInteractionAtSur_ptr());

								for (unsigned int h = 0; h < mVector_vectorWithSurfacePointer_LLT.at(7).size(); h++)
								{
									surface_7 = mVector_vectorWithSurfacePointer_LLT.at(7).at(h);
									tempOptSys.fillTracingVectorSurfaces(7, surface_7);
									tempOptSys.fillTracingVectorInteraction(7, mOptSysEle.getPosAndInteraction_LLT().at(7).getInteractionAtSur_ptr());

									for (unsigned int i = 0; i < mVector_vectorWithSurfacePointer_LLT.at(8).size(); i++)
									{
										surface_8 = mVector_vectorWithSurfacePointer_LLT.at(8).at(i);
										tempOptSys.fillTracingVectorSurfaces(8, surface_8);
										tempOptSys.fillTracingVectorInteraction(8, mOptSysEle.getPosAndInteraction_LLT().at(8).getInteractionAtSur_ptr());

										for (unsigned int j = 0; j < mVector_vectorWithSurfacePointer_LLT.at(9).size(); j++)
										{
											surface_9 = mVector_vectorWithSurfacePointer_LLT.at(9).at(j);
											tempOptSys.fillTracingVectorSurfaces(9, surface_9);
											tempOptSys.fillTracingVectorInteraction(9, mOptSysEle.getPosAndInteraction_LLT().at(9).getInteractionAtSur_ptr());

											for (unsigned int i = 0; i < mVector_vectorWithSurfacePointer_LLT.at(10).size(); i++)
											{
												surface_10 = mVector_vectorWithSurfacePointer_LLT.at(10).at(i);
												tempOptSys.fillTracingVectorSurfaces(10, surface_10);
												tempOptSys.fillTracingVectorInteraction(10, mOptSysEle.getPosAndInteraction_LLT().at(10).getInteractionAtSur_ptr());

												for (unsigned int j = 0; j < mVector_vectorWithSurfacePointer_LLT.at(11).size(); j++)
												{
													surface_11 = mVector_vectorWithSurfacePointer_LLT.at(11).at(j);
													tempOptSys.fillTracingVectorSurfaces(11, surface_11);
													tempOptSys.fillTracingVectorInteraction(11, mOptSysEle.getPosAndInteraction_LLT().at(11).getInteractionAtSur_ptr());

													for (unsigned int i = 0; i < mVector_vectorWithSurfacePointer_LLT.at(12).size(); i++)
													{
														surface_12 = mVector_vectorWithSurfacePointer_LLT.at(12).at(i);
														tempOptSys.fillTracingVectorSurfaces(12, surface_12);
														tempOptSys.fillTracingVectorInteraction(12, mOptSysEle.getPosAndInteraction_LLT().at(12).getInteractionAtSur_ptr());

														for (unsigned int j = 0; j < mVector_vectorWithSurfacePointer_LLT.at(13).size(); j++)
														{
															surface_13 = mVector_vectorWithSurfacePointer_LLT.at(13).at(j);
															tempOptSys.fillTracingVectorSurfaces(13, surface_13);
															tempOptSys.fillTracingVectorInteraction(13, mOptSysEle.getPosAndInteraction_LLT().at(13).getInteractionAtSur_ptr());

															for (unsigned int i = 0; i < mVector_vectorWithSurfacePointer_LLT.at(14).size(); i++)
															{
																surface_14 = mVector_vectorWithSurfacePointer_LLT.at(14).at(i);
																tempOptSys.fillTracingVectorSurfaces(14, surface_14);
																tempOptSys.fillTracingVectorInteraction(14, mOptSysEle.getPosAndInteraction_LLT().at(14).getInteractionAtSur_ptr());



																for (unsigned int j = 0; j < mVector_vectorWithSurfacePointer_LLT.at(15).size(); j++)
																{
																	surface_15 = mVector_vectorWithSurfacePointer_LLT.at(15).at(j);
																	tempOptSys.fillTracingVectorSurfaces(15, surface_15);
																	tempOptSys.fillTracingVectorInteraction(15, mOptSysEle.getPosAndInteraction_LLT().at(15).getInteractionAtSur_ptr());

																	for (unsigned int i = 0; i < mVector_vectorWithSurfacePointer_LLT.at(16).size(); i++)
																	{
																		surface_16 = mVector_vectorWithSurfacePointer_LLT.at(16).at(i);
																		tempOptSys.fillTracingVectorSurfaces(16, surface_16);
																		tempOptSys.fillTracingVectorInteraction(16, mOptSysEle.getPosAndInteraction_LLT().at(16).getInteractionAtSur_ptr());

																		mPossibleOpticalSystem_LLT.push_back(tempOptSys.clone());

																		tempOptSys.cleanSurfaceAndInteractionStartAt_i(16);
																	}
																	tempOptSys.cleanSurfaceAndInteractionStartAt_i(15);

																}
																tempOptSys.cleanSurfaceAndInteractionStartAt_i(14);
															}
															tempOptSys.cleanSurfaceAndInteractionStartAt_i(13);
														}
														tempOptSys.cleanSurfaceAndInteractionStartAt_i(12);
													}
													tempOptSys.cleanSurfaceAndInteractionStartAt_i(11);
												}
												tempOptSys.cleanSurfaceAndInteractionStartAt_i(10);
											}
											tempOptSys.cleanSurfaceAndInteractionStartAt_i(9);
										}


										tempOptSys.cleanSurfaceAndInteractionStartAt_i(8);
									}


									tempOptSys.cleanSurfaceAndInteractionStartAt_i(7);
								}


								tempOptSys.cleanSurfaceAndInteractionStartAt_i(6);
							}
							tempOptSys.cleanSurfaceAndInteractionStartAt_i(5);

						}

						tempOptSys.cleanSurfaceAndInteractionStartAt_i(4);

					}
					tempOptSys.cleanSurfaceAndInteractionStartAt_i(3);
				}
				tempOptSys.cleanSurfaceAndInteractionStartAt_i(2);
			}
			tempOptSys.cleanSurfaceAndInteractionStartAt_i(1);
		}
		//tempOptSys.cleanSurfaceAndInteractionStartAt_i(0);
	}


}
void BuildSystemsForCombination::buildOpticalSystemCombination_17Surfaces_Element()
{
	unsigned int numberSurfaces = mVector_vectorWithSurfacePointer_Element.size();
	//unsigned int numberSurfaces = mVector_vectorWithSurfacePointer_LLT.size();

	//std::vector<std::shared_ptr<InteractionRay_LLT>> tempInteractions_LLT;
	std::vector<std::shared_ptr<Element_CR>> tempInteractions_Element;
	OpticalSystemElement tempOptSysElement;
	//OpticalSystemElement tempOptSys;

	std::shared_ptr<Element_CR> surface_0;
	std::shared_ptr<Element_CR> surface_1;
	std::shared_ptr<Element_CR> surface_2;
	std::shared_ptr<Element_CR> surface_3;
	std::shared_ptr<Element_CR> surface_4;
	std::shared_ptr<Element_CR> surface_5;
	std::shared_ptr<Element_CR> surface_6;
	std::shared_ptr<Element_CR> surface_7;
	std::shared_ptr<Element_CR> surface_8;
	std::shared_ptr<Element_CR> surface_9;
	std::shared_ptr<Element_CR> surface_10;
	std::shared_ptr<Element_CR> surface_11;
	std::shared_ptr<Element_CR> surface_12;
	std::shared_ptr<Element_CR> surface_13;
	std::shared_ptr<Element_CR> surface_14;
	std::shared_ptr<Element_CR> surface_15;
	std::shared_ptr<Element_CR> surface_16;

	for (unsigned int a = 0; a < mVector_vectorWithSurfacePointer_Element.at(0).size(); a++)
	{
		surface_0 = mVector_vectorWithSurfacePointer_Element.at(0).at(a);
		tempOptSysElement.fillPosAndElementAndInteraction(0, surface_0, mOptSysEle.getPosAndInteraction_LLT()[0].getInteractionAtSur_ptr());

		for (unsigned int b = 0; b < mVector_vectorWithSurfacePointer_Element.at(1).size(); b++)
		{
			surface_1 = mVector_vectorWithSurfacePointer_Element.at(1).at(b);
			tempOptSysElement.fillPosAndElementAndInteraction(1, surface_1, mOptSysEle.getPosAndInteraction_LLT()[1].getInteractionAtSur_ptr());

			for (unsigned int c = 0; c < mVector_vectorWithSurfacePointer_Element.at(2).size(); c++)
			{
				surface_2 = mVector_vectorWithSurfacePointer_Element.at(2).at(c);
				tempOptSysElement.fillPosAndElementAndInteraction(2, surface_2, mOptSysEle.getPosAndInteraction_LLT()[2].getInteractionAtSur_ptr());

				for (unsigned int d = 0; d < mVector_vectorWithSurfacePointer_Element.at(3).size(); d++)
				{
					surface_3 = mVector_vectorWithSurfacePointer_Element.at(3).at(d);
					tempOptSysElement.fillPosAndElementAndInteraction(3, surface_3, mOptSysEle.getPosAndInteraction_LLT()[3].getInteractionAtSur_ptr());

					for (unsigned int e = 0; e < mVector_vectorWithSurfacePointer_Element.at(4).size(); e++)
					{
						surface_4 = mVector_vectorWithSurfacePointer_Element.at(4).at(e);
						tempOptSysElement.fillPosAndElementAndInteraction(4, surface_4, mOptSysEle.getPosAndInteraction_LLT()[4].getInteractionAtSur_ptr());

						for (unsigned int f = 0; f < mVector_vectorWithSurfacePointer_Element.at(5).size(); f++)
						{
							surface_5 = mVector_vectorWithSurfacePointer_Element.at(5).at(f);
							tempOptSysElement.fillPosAndElementAndInteraction(5, surface_5, mOptSysEle.getPosAndInteraction_LLT()[5].getInteractionAtSur_ptr());

							for (unsigned int g = 0; g < mVector_vectorWithSurfacePointer_Element.at(6).size(); g++)
							{
								surface_6 = mVector_vectorWithSurfacePointer_Element.at(6).at(g);
								tempOptSysElement.fillPosAndElementAndInteraction(6, surface_6, mOptSysEle.getPosAndInteraction_LLT()[6].getInteractionAtSur_ptr());

								for (unsigned int h = 0; h < mVector_vectorWithSurfacePointer_Element.at(7).size(); h++)
								{
									surface_7 = mVector_vectorWithSurfacePointer_Element.at(7).at(h);
									tempOptSysElement.fillPosAndElementAndInteraction(7, surface_7, mOptSysEle.getPosAndInteraction_LLT()[7].getInteractionAtSur_ptr());

									for (unsigned int i = 0; i < mVector_vectorWithSurfacePointer_Element.at(8).size(); i++)
									{
										surface_8 = mVector_vectorWithSurfacePointer_Element.at(8).at(i);
										tempOptSysElement.fillPosAndElementAndInteraction(8, surface_8, mOptSysEle.getPosAndInteraction_LLT()[8].getInteractionAtSur_ptr());

										for (unsigned int j = 0; j < mVector_vectorWithSurfacePointer_Element.at(9).size(); j++)
										{

											surface_9 = mVector_vectorWithSurfacePointer_Element.at(9).at(j);
											tempOptSysElement.fillPosAndElementAndInteraction(9, surface_9, mOptSysEle.getPosAndInteraction_LLT()[9].getInteractionAtSur_ptr());

											for (unsigned int i = 0; i < mVector_vectorWithSurfacePointer_Element.at(10).size(); i++)
											{
												surface_10 = mVector_vectorWithSurfacePointer_Element.at(10).at(i);
												tempOptSysElement.fillPosAndElementAndInteraction(10, surface_10, mOptSysEle.getPosAndInteraction_LLT()[10].getInteractionAtSur_ptr());

												for (unsigned int j = 0; j < mVector_vectorWithSurfacePointer_Element.at(11).size(); j++)
												{

													surface_11 = mVector_vectorWithSurfacePointer_Element.at(11).at(j);
													tempOptSysElement.fillPosAndElementAndInteraction(11, surface_11, mOptSysEle.getPosAndInteraction_LLT()[11].getInteractionAtSur_ptr());

													for (unsigned int i = 0; i < mVector_vectorWithSurfacePointer_Element.at(12).size(); i++)
													{
														surface_12 = mVector_vectorWithSurfacePointer_Element.at(10).at(i);
														tempOptSysElement.fillPosAndElementAndInteraction(12, surface_12, mOptSysEle.getPosAndInteraction_LLT()[12].getInteractionAtSur_ptr());

														for (unsigned int j = 0; j < mVector_vectorWithSurfacePointer_Element.at(13).size(); j++)
														{

															surface_13 = mVector_vectorWithSurfacePointer_Element.at(13).at(j);
															tempOptSysElement.fillPosAndElementAndInteraction(13, surface_13, mOptSysEle.getPosAndInteraction_LLT()[13].getInteractionAtSur_ptr());


															for (unsigned int i = 0; i < mVector_vectorWithSurfacePointer_Element.at(14).size(); i++)
															{
																surface_14 = mVector_vectorWithSurfacePointer_Element.at(14).at(i);
																tempOptSysElement.fillPosAndElementAndInteraction(14, surface_14, mOptSysEle.getPosAndInteraction_LLT()[14].getInteractionAtSur_ptr());

																for (unsigned int j = 0; j < mVector_vectorWithSurfacePointer_Element.at(15).size(); j++)
																{

																	surface_15 = mVector_vectorWithSurfacePointer_Element.at(15).at(j);
																	tempOptSysElement.fillPosAndElementAndInteraction(15, surface_15, mOptSysEle.getPosAndInteraction_LLT()[15].getInteractionAtSur_ptr());


																	for (unsigned int i = 0; i < mVector_vectorWithSurfacePointer_Element.at(16).size(); i++)
																	{
																		surface_16 = mVector_vectorWithSurfacePointer_Element.at(16).at(i);
																		tempOptSysElement.fillPosAndElementAndInteraction(16, surface_16, mOptSysEle.getPosAndInteraction_LLT()[16].getInteractionAtSur_ptr());

																		mPossibleOpticalSys_Element.push_back(tempOptSysElement.getDeepCopyOptSysEle());

																		tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(16);
																	}
																	tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(15);
																}
																tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(14);
															}
															tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(13);
														}
														tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(12);
													}
													tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(11);
												}
												tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(10);
											}
											tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(9);
										}


										tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(8);
									}


									tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(7);
								}


								tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(6);
							}
							tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(5);

						}

						tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(4);

					}
					tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(3);
				}
				tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(2);
			}
			tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(1);
		}
		//tempOptSys.cleanSurfaceAndInteractionStartAt_i(0);
	}


}
void BuildSystemsForCombination::buildOpticalSystemCombination_18Surfaces_LLT()
{
	unsigned int numberSurfaces = mVector_vectorWithSurfacePointer_LLT.size();


	std::vector<std::shared_ptr<InteractionRay_LLT>> tempInteractions_LLT;
	OpticalSystem_LLT tempOptSys;

	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_0;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_1;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_2;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_3;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_4;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_5;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_6;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_7;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_8;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_9;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_10;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_11;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_12;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_13;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_14;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_15;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_16;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_17;

	for (unsigned int a = 0; a < mVector_vectorWithSurfacePointer_LLT.at(0).size(); a++)
	{
		surface_0 = mVector_vectorWithSurfacePointer_LLT.at(0).at(a);
		tempOptSys.fillTracingVectorSurfaces(0, surface_0);
		tempOptSys.fillTracingVectorInteraction(0, mOptSysEle.getPosAndInteraction_LLT().at(0).getInteractionAtSur_ptr());

		for (unsigned int b = 0; b < mVector_vectorWithSurfacePointer_LLT.at(1).size(); b++)
		{
			surface_1 = mVector_vectorWithSurfacePointer_LLT.at(1).at(b);
			tempOptSys.fillTracingVectorSurfaces(1, surface_1);
			tempOptSys.fillTracingVectorInteraction(1, mOptSysEle.getPosAndInteraction_LLT().at(1).getInteractionAtSur_ptr());

			for (unsigned int c = 0; c < mVector_vectorWithSurfacePointer_LLT.at(2).size(); c++)
			{
				surface_2 = mVector_vectorWithSurfacePointer_LLT.at(2).at(c);
				tempOptSys.fillTracingVectorSurfaces(2, surface_2);
				tempOptSys.fillTracingVectorInteraction(2, mOptSysEle.getPosAndInteraction_LLT().at(2).getInteractionAtSur_ptr());

				for (unsigned int d = 0; d < mVector_vectorWithSurfacePointer_LLT.at(3).size(); d++)
				{
					surface_3 = mVector_vectorWithSurfacePointer_LLT.at(3).at(d);
					tempOptSys.fillTracingVectorSurfaces(3, surface_3);
					tempOptSys.fillTracingVectorInteraction(3, mOptSysEle.getPosAndInteraction_LLT().at(3).getInteractionAtSur_ptr());

					for (unsigned int e = 0; e < mVector_vectorWithSurfacePointer_LLT.at(4).size(); e++)
					{
						surface_4 = mVector_vectorWithSurfacePointer_LLT.at(4).at(e);
						tempOptSys.fillTracingVectorSurfaces(4, surface_4);
						tempOptSys.fillTracingVectorInteraction(4, mOptSysEle.getPosAndInteraction_LLT().at(4).getInteractionAtSur_ptr());

						for (unsigned int f = 0; f < mVector_vectorWithSurfacePointer_LLT.at(5).size(); f++)
						{
							surface_5 = mVector_vectorWithSurfacePointer_LLT.at(5).at(f);
							tempOptSys.fillTracingVectorSurfaces(5, surface_5);
							tempOptSys.fillTracingVectorInteraction(5, mOptSysEle.getPosAndInteraction_LLT().at(5).getInteractionAtSur_ptr());

							for (unsigned int g = 0; g < mVector_vectorWithSurfacePointer_LLT.at(6).size(); g++)
							{
								surface_6 = mVector_vectorWithSurfacePointer_LLT.at(6).at(g);
								tempOptSys.fillTracingVectorSurfaces(6, surface_6);
								tempOptSys.fillTracingVectorInteraction(6, mOptSysEle.getPosAndInteraction_LLT().at(6).getInteractionAtSur_ptr());

								for (unsigned int h = 0; h < mVector_vectorWithSurfacePointer_LLT.at(7).size(); h++)
								{
									surface_7 = mVector_vectorWithSurfacePointer_LLT.at(7).at(h);
									tempOptSys.fillTracingVectorSurfaces(7, surface_7);
									tempOptSys.fillTracingVectorInteraction(7, mOptSysEle.getPosAndInteraction_LLT().at(7).getInteractionAtSur_ptr());

									for (unsigned int i = 0; i < mVector_vectorWithSurfacePointer_LLT.at(8).size(); i++)
									{
										surface_8 = mVector_vectorWithSurfacePointer_LLT.at(8).at(i);
										tempOptSys.fillTracingVectorSurfaces(8, surface_8);
										tempOptSys.fillTracingVectorInteraction(8, mOptSysEle.getPosAndInteraction_LLT().at(8).getInteractionAtSur_ptr());

										for (unsigned int j = 0; j < mVector_vectorWithSurfacePointer_LLT.at(9).size(); j++)
										{
											surface_9 = mVector_vectorWithSurfacePointer_LLT.at(9).at(j);
											tempOptSys.fillTracingVectorSurfaces(9, surface_9);
											tempOptSys.fillTracingVectorInteraction(9, mOptSysEle.getPosAndInteraction_LLT().at(9).getInteractionAtSur_ptr());

											for (unsigned int i = 0; i < mVector_vectorWithSurfacePointer_LLT.at(10).size(); i++)
											{
												surface_10 = mVector_vectorWithSurfacePointer_LLT.at(10).at(i);
												tempOptSys.fillTracingVectorSurfaces(10, surface_10);
												tempOptSys.fillTracingVectorInteraction(10, mOptSysEle.getPosAndInteraction_LLT().at(10).getInteractionAtSur_ptr());

												for (unsigned int j = 0; j < mVector_vectorWithSurfacePointer_LLT.at(11).size(); j++)
												{
													surface_11 = mVector_vectorWithSurfacePointer_LLT.at(11).at(j);
													tempOptSys.fillTracingVectorSurfaces(11, surface_11);
													tempOptSys.fillTracingVectorInteraction(11, mOptSysEle.getPosAndInteraction_LLT().at(11).getInteractionAtSur_ptr());

													for (unsigned int i = 0; i < mVector_vectorWithSurfacePointer_LLT.at(12).size(); i++)
													{
														surface_12 = mVector_vectorWithSurfacePointer_LLT.at(12).at(i);
														tempOptSys.fillTracingVectorSurfaces(12, surface_12);
														tempOptSys.fillTracingVectorInteraction(12, mOptSysEle.getPosAndInteraction_LLT().at(12).getInteractionAtSur_ptr());

														for (unsigned int j = 0; j < mVector_vectorWithSurfacePointer_LLT.at(13).size(); j++)
														{
															surface_13 = mVector_vectorWithSurfacePointer_LLT.at(13).at(j);
															tempOptSys.fillTracingVectorSurfaces(13, surface_13);
															tempOptSys.fillTracingVectorInteraction(13, mOptSysEle.getPosAndInteraction_LLT().at(13).getInteractionAtSur_ptr());

															for (unsigned int i = 0; i < mVector_vectorWithSurfacePointer_LLT.at(14).size(); i++)
															{
																surface_14 = mVector_vectorWithSurfacePointer_LLT.at(14).at(i);
																tempOptSys.fillTracingVectorSurfaces(14, surface_14);
																tempOptSys.fillTracingVectorInteraction(14, mOptSysEle.getPosAndInteraction_LLT().at(14).getInteractionAtSur_ptr());



																for (unsigned int j = 0; j < mVector_vectorWithSurfacePointer_LLT.at(15).size(); j++)
																{
																	surface_15 = mVector_vectorWithSurfacePointer_LLT.at(15).at(j);
																	tempOptSys.fillTracingVectorSurfaces(15, surface_15);
																	tempOptSys.fillTracingVectorInteraction(15, mOptSysEle.getPosAndInteraction_LLT().at(15).getInteractionAtSur_ptr());

																	for (unsigned int i = 0; i < mVector_vectorWithSurfacePointer_LLT.at(16).size(); i++)
																	{
																		surface_16 = mVector_vectorWithSurfacePointer_LLT.at(16).at(i);
																		tempOptSys.fillTracingVectorSurfaces(16, surface_16);
																		tempOptSys.fillTracingVectorInteraction(16, mOptSysEle.getPosAndInteraction_LLT().at(16).getInteractionAtSur_ptr());

																		for (unsigned int j = 0; j < mVector_vectorWithSurfacePointer_LLT.at(17).size(); j++)
																		{
																			surface_17 = mVector_vectorWithSurfacePointer_LLT.at(17).at(j);
																			tempOptSys.fillTracingVectorSurfaces(17, surface_17);
																			tempOptSys.fillTracingVectorInteraction(17, mOptSysEle.getPosAndInteraction_LLT().at(17).getInteractionAtSur_ptr());

																			mPossibleOpticalSystem_LLT.push_back(tempOptSys.clone());

																			tempOptSys.cleanSurfaceAndInteractionStartAt_i(17);
																		}
																		tempOptSys.cleanSurfaceAndInteractionStartAt_i(16);
																	}
																	tempOptSys.cleanSurfaceAndInteractionStartAt_i(15);

																}
																tempOptSys.cleanSurfaceAndInteractionStartAt_i(14);
															}
															tempOptSys.cleanSurfaceAndInteractionStartAt_i(13);
														}
														tempOptSys.cleanSurfaceAndInteractionStartAt_i(12);
													}
													tempOptSys.cleanSurfaceAndInteractionStartAt_i(11);
												}
												tempOptSys.cleanSurfaceAndInteractionStartAt_i(10);
											}
											tempOptSys.cleanSurfaceAndInteractionStartAt_i(9);
										}


										tempOptSys.cleanSurfaceAndInteractionStartAt_i(8);
									}


									tempOptSys.cleanSurfaceAndInteractionStartAt_i(7);
								}


								tempOptSys.cleanSurfaceAndInteractionStartAt_i(6);
							}
							tempOptSys.cleanSurfaceAndInteractionStartAt_i(5);

						}

						tempOptSys.cleanSurfaceAndInteractionStartAt_i(4);

					}
					tempOptSys.cleanSurfaceAndInteractionStartAt_i(3);
				}
				tempOptSys.cleanSurfaceAndInteractionStartAt_i(2);
			}
			tempOptSys.cleanSurfaceAndInteractionStartAt_i(1);
		}
		//tempOptSys.cleanSurfaceAndInteractionStartAt_i(0);
	}


}
void BuildSystemsForCombination::buildOpticalSystemCombination_18Surfaces_Element()
{
	unsigned int numberSurfaces = mVector_vectorWithSurfacePointer_Element.size();
	//unsigned int numberSurfaces = mVector_vectorWithSurfacePointer_LLT.size();

	//std::vector<std::shared_ptr<InteractionRay_LLT>> tempInteractions_LLT;
	std::vector<std::shared_ptr<Element_CR>> tempInteractions_Element;
	OpticalSystemElement tempOptSysElement;
	//OpticalSystemElement tempOptSys;

	std::shared_ptr<Element_CR> surface_0;
	std::shared_ptr<Element_CR> surface_1;
	std::shared_ptr<Element_CR> surface_2;
	std::shared_ptr<Element_CR> surface_3;
	std::shared_ptr<Element_CR> surface_4;
	std::shared_ptr<Element_CR> surface_5;
	std::shared_ptr<Element_CR> surface_6;
	std::shared_ptr<Element_CR> surface_7;
	std::shared_ptr<Element_CR> surface_8;
	std::shared_ptr<Element_CR> surface_9;
	std::shared_ptr<Element_CR> surface_10;
	std::shared_ptr<Element_CR> surface_11;
	std::shared_ptr<Element_CR> surface_12;
	std::shared_ptr<Element_CR> surface_13;
	std::shared_ptr<Element_CR> surface_14;
	std::shared_ptr<Element_CR> surface_15;
	std::shared_ptr<Element_CR> surface_16;
	std::shared_ptr<Element_CR> surface_17;

	for (unsigned int a = 0; a < mVector_vectorWithSurfacePointer_Element.at(0).size(); a++)
	{
		surface_0 = mVector_vectorWithSurfacePointer_Element.at(0).at(a);
		tempOptSysElement.fillPosAndElementAndInteraction(0, surface_0, mOptSysEle.getPosAndInteraction_LLT()[0].getInteractionAtSur_ptr());

		for (unsigned int b = 0; b < mVector_vectorWithSurfacePointer_Element.at(1).size(); b++)
		{
			surface_1 = mVector_vectorWithSurfacePointer_Element.at(1).at(b);
			tempOptSysElement.fillPosAndElementAndInteraction(1, surface_1, mOptSysEle.getPosAndInteraction_LLT()[1].getInteractionAtSur_ptr());

			for (unsigned int c = 0; c < mVector_vectorWithSurfacePointer_Element.at(2).size(); c++)
			{
				surface_2 = mVector_vectorWithSurfacePointer_Element.at(2).at(c);
				tempOptSysElement.fillPosAndElementAndInteraction(2, surface_2, mOptSysEle.getPosAndInteraction_LLT()[2].getInteractionAtSur_ptr());

				for (unsigned int d = 0; d < mVector_vectorWithSurfacePointer_Element.at(3).size(); d++)
				{
					surface_3 = mVector_vectorWithSurfacePointer_Element.at(3).at(d);
					tempOptSysElement.fillPosAndElementAndInteraction(3, surface_3, mOptSysEle.getPosAndInteraction_LLT()[3].getInteractionAtSur_ptr());

					for (unsigned int e = 0; e < mVector_vectorWithSurfacePointer_Element.at(4).size(); e++)
					{
						surface_4 = mVector_vectorWithSurfacePointer_Element.at(4).at(e);
						tempOptSysElement.fillPosAndElementAndInteraction(4, surface_4, mOptSysEle.getPosAndInteraction_LLT()[4].getInteractionAtSur_ptr());

						for (unsigned int f = 0; f < mVector_vectorWithSurfacePointer_Element.at(5).size(); f++)
						{
							surface_5 = mVector_vectorWithSurfacePointer_Element.at(5).at(f);
							tempOptSysElement.fillPosAndElementAndInteraction(5, surface_5, mOptSysEle.getPosAndInteraction_LLT()[5].getInteractionAtSur_ptr());

							for (unsigned int g = 0; g < mVector_vectorWithSurfacePointer_Element.at(6).size(); g++)
							{
								surface_6 = mVector_vectorWithSurfacePointer_Element.at(6).at(g);
								tempOptSysElement.fillPosAndElementAndInteraction(6, surface_6, mOptSysEle.getPosAndInteraction_LLT()[6].getInteractionAtSur_ptr());

								for (unsigned int h = 0; h < mVector_vectorWithSurfacePointer_Element.at(7).size(); h++)
								{
									surface_7 = mVector_vectorWithSurfacePointer_Element.at(7).at(h);
									tempOptSysElement.fillPosAndElementAndInteraction(7, surface_7, mOptSysEle.getPosAndInteraction_LLT()[7].getInteractionAtSur_ptr());

									for (unsigned int i = 0; i < mVector_vectorWithSurfacePointer_Element.at(8).size(); i++)
									{
										surface_8 = mVector_vectorWithSurfacePointer_Element.at(8).at(i);
										tempOptSysElement.fillPosAndElementAndInteraction(8, surface_8, mOptSysEle.getPosAndInteraction_LLT()[8].getInteractionAtSur_ptr());

										for (unsigned int j = 0; j < mVector_vectorWithSurfacePointer_Element.at(9).size(); j++)
										{

											surface_9 = mVector_vectorWithSurfacePointer_Element.at(9).at(j);
											tempOptSysElement.fillPosAndElementAndInteraction(9, surface_9, mOptSysEle.getPosAndInteraction_LLT()[9].getInteractionAtSur_ptr());

											for (unsigned int i = 0; i < mVector_vectorWithSurfacePointer_Element.at(10).size(); i++)
											{
												surface_10 = mVector_vectorWithSurfacePointer_Element.at(10).at(i);
												tempOptSysElement.fillPosAndElementAndInteraction(10, surface_10, mOptSysEle.getPosAndInteraction_LLT()[10].getInteractionAtSur_ptr());

												for (unsigned int j = 0; j < mVector_vectorWithSurfacePointer_Element.at(11).size(); j++)
												{

													surface_11 = mVector_vectorWithSurfacePointer_Element.at(11).at(j);
													tempOptSysElement.fillPosAndElementAndInteraction(11, surface_11, mOptSysEle.getPosAndInteraction_LLT()[11].getInteractionAtSur_ptr());

													for (unsigned int i = 0; i < mVector_vectorWithSurfacePointer_Element.at(12).size(); i++)
													{
														surface_12 = mVector_vectorWithSurfacePointer_Element.at(10).at(i);
														tempOptSysElement.fillPosAndElementAndInteraction(12, surface_12, mOptSysEle.getPosAndInteraction_LLT()[12].getInteractionAtSur_ptr());

														for (unsigned int j = 0; j < mVector_vectorWithSurfacePointer_Element.at(13).size(); j++)
														{

															surface_13 = mVector_vectorWithSurfacePointer_Element.at(13).at(j);
															tempOptSysElement.fillPosAndElementAndInteraction(13, surface_13, mOptSysEle.getPosAndInteraction_LLT()[13].getInteractionAtSur_ptr());


															for (unsigned int i = 0; i < mVector_vectorWithSurfacePointer_Element.at(14).size(); i++)
															{
																surface_14 = mVector_vectorWithSurfacePointer_Element.at(14).at(i);
																tempOptSysElement.fillPosAndElementAndInteraction(14, surface_14, mOptSysEle.getPosAndInteraction_LLT()[14].getInteractionAtSur_ptr());

																for (unsigned int j = 0; j < mVector_vectorWithSurfacePointer_Element.at(15).size(); j++)
																{

																	surface_15 = mVector_vectorWithSurfacePointer_Element.at(15).at(j);
																	tempOptSysElement.fillPosAndElementAndInteraction(15, surface_15, mOptSysEle.getPosAndInteraction_LLT()[15].getInteractionAtSur_ptr());


																	for (unsigned int i = 0; i < mVector_vectorWithSurfacePointer_Element.at(16).size(); i++)
																	{
																		surface_16 = mVector_vectorWithSurfacePointer_Element.at(16).at(i);
																		tempOptSysElement.fillPosAndElementAndInteraction(16, surface_16, mOptSysEle.getPosAndInteraction_LLT()[16].getInteractionAtSur_ptr());

																		for (unsigned int j = 0; j < mVector_vectorWithSurfacePointer_Element.at(17).size(); j++)
																		{

																			surface_17 = mVector_vectorWithSurfacePointer_Element.at(17).at(j);
																			tempOptSysElement.fillPosAndElementAndInteraction(17, surface_17, mOptSysEle.getPosAndInteraction_LLT()[17].getInteractionAtSur_ptr());

																			mPossibleOpticalSys_Element.push_back(tempOptSysElement.getDeepCopyOptSysEle());

																			tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(17);
																		}
																		tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(16);
																	}
																	tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(15);
																}
																tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(14);
															}
															tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(13);
														}
														tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(12);
													}
													tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(11);
												}
												tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(10);
											}
											tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(9);
										}


										tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(8);
									}


									tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(7);
								}


								tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(6);
							}
							tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(5);

						}

						tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(4);

					}
					tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(3);
				}
				tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(2);
			}
			tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(1);
		}
		//tempOptSys.cleanSurfaceAndInteractionStartAt_i(0);
	}


}
void BuildSystemsForCombination::buildOpticalSystemCombination_19Surfaces_LLT()
{
	unsigned int numberSurfaces = mVector_vectorWithSurfacePointer_LLT.size();


	std::vector<std::shared_ptr<InteractionRay_LLT>> tempInteractions_LLT;
	OpticalSystem_LLT tempOptSys;

	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_0;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_1;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_2;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_3;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_4;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_5;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_6;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_7;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_8;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_9;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_10;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_11;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_12;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_13;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_14;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_15;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_16;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_17;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_18;

	for (unsigned int a = 0; a < mVector_vectorWithSurfacePointer_LLT.at(0).size(); a++)
	{
		surface_0 = mVector_vectorWithSurfacePointer_LLT.at(0).at(a);
		tempOptSys.fillTracingVectorSurfaces(0, surface_0);
		tempOptSys.fillTracingVectorInteraction(0, mOptSysEle.getPosAndInteraction_LLT().at(0).getInteractionAtSur_ptr());

		for (unsigned int b = 0; b < mVector_vectorWithSurfacePointer_LLT.at(1).size(); b++)
		{
			surface_1 = mVector_vectorWithSurfacePointer_LLT.at(1).at(b);
			tempOptSys.fillTracingVectorSurfaces(1, surface_1);
			tempOptSys.fillTracingVectorInteraction(1, mOptSysEle.getPosAndInteraction_LLT().at(1).getInteractionAtSur_ptr());

			for (unsigned int c = 0; c < mVector_vectorWithSurfacePointer_LLT.at(2).size(); c++)
			{
				surface_2 = mVector_vectorWithSurfacePointer_LLT.at(2).at(c);
				tempOptSys.fillTracingVectorSurfaces(2, surface_2);
				tempOptSys.fillTracingVectorInteraction(2, mOptSysEle.getPosAndInteraction_LLT().at(2).getInteractionAtSur_ptr());

				for (unsigned int d = 0; d < mVector_vectorWithSurfacePointer_LLT.at(3).size(); d++)
				{
					surface_3 = mVector_vectorWithSurfacePointer_LLT.at(3).at(d);
					tempOptSys.fillTracingVectorSurfaces(3, surface_3);
					tempOptSys.fillTracingVectorInteraction(3, mOptSysEle.getPosAndInteraction_LLT().at(3).getInteractionAtSur_ptr());

					for (unsigned int e = 0; e < mVector_vectorWithSurfacePointer_LLT.at(4).size(); e++)
					{
						surface_4 = mVector_vectorWithSurfacePointer_LLT.at(4).at(e);
						tempOptSys.fillTracingVectorSurfaces(4, surface_4);
						tempOptSys.fillTracingVectorInteraction(4, mOptSysEle.getPosAndInteraction_LLT().at(4).getInteractionAtSur_ptr());

						for (unsigned int f = 0; f < mVector_vectorWithSurfacePointer_LLT.at(5).size(); f++)
						{
							surface_5 = mVector_vectorWithSurfacePointer_LLT.at(5).at(f);
							tempOptSys.fillTracingVectorSurfaces(5, surface_5);
							tempOptSys.fillTracingVectorInteraction(5, mOptSysEle.getPosAndInteraction_LLT().at(5).getInteractionAtSur_ptr());

							for (unsigned int g = 0; g < mVector_vectorWithSurfacePointer_LLT.at(6).size(); g++)
							{
								surface_6 = mVector_vectorWithSurfacePointer_LLT.at(6).at(g);
								tempOptSys.fillTracingVectorSurfaces(6, surface_6);
								tempOptSys.fillTracingVectorInteraction(6, mOptSysEle.getPosAndInteraction_LLT().at(6).getInteractionAtSur_ptr());

								for (unsigned int h = 0; h < mVector_vectorWithSurfacePointer_LLT.at(7).size(); h++)
								{
									surface_7 = mVector_vectorWithSurfacePointer_LLT.at(7).at(h);
									tempOptSys.fillTracingVectorSurfaces(7, surface_7);
									tempOptSys.fillTracingVectorInteraction(7, mOptSysEle.getPosAndInteraction_LLT().at(7).getInteractionAtSur_ptr());

									for (unsigned int i = 0; i < mVector_vectorWithSurfacePointer_LLT.at(8).size(); i++)
									{
										surface_8 = mVector_vectorWithSurfacePointer_LLT.at(8).at(i);
										tempOptSys.fillTracingVectorSurfaces(8, surface_8);
										tempOptSys.fillTracingVectorInteraction(8, mOptSysEle.getPosAndInteraction_LLT().at(8).getInteractionAtSur_ptr());

										for (unsigned int j = 0; j < mVector_vectorWithSurfacePointer_LLT.at(9).size(); j++)
										{
											surface_9 = mVector_vectorWithSurfacePointer_LLT.at(9).at(j);
											tempOptSys.fillTracingVectorSurfaces(9, surface_9);
											tempOptSys.fillTracingVectorInteraction(9, mOptSysEle.getPosAndInteraction_LLT().at(9).getInteractionAtSur_ptr());

											for (unsigned int i = 0; i < mVector_vectorWithSurfacePointer_LLT.at(10).size(); i++)
											{
												surface_10 = mVector_vectorWithSurfacePointer_LLT.at(10).at(i);
												tempOptSys.fillTracingVectorSurfaces(10, surface_10);
												tempOptSys.fillTracingVectorInteraction(10, mOptSysEle.getPosAndInteraction_LLT().at(10).getInteractionAtSur_ptr());

												for (unsigned int j = 0; j < mVector_vectorWithSurfacePointer_LLT.at(11).size(); j++)
												{
													surface_11 = mVector_vectorWithSurfacePointer_LLT.at(11).at(j);
													tempOptSys.fillTracingVectorSurfaces(11, surface_11);
													tempOptSys.fillTracingVectorInteraction(11, mOptSysEle.getPosAndInteraction_LLT().at(11).getInteractionAtSur_ptr());

													for (unsigned int i = 0; i < mVector_vectorWithSurfacePointer_LLT.at(12).size(); i++)
													{
														surface_12 = mVector_vectorWithSurfacePointer_LLT.at(12).at(i);
														tempOptSys.fillTracingVectorSurfaces(12, surface_12);
														tempOptSys.fillTracingVectorInteraction(12, mOptSysEle.getPosAndInteraction_LLT().at(12).getInteractionAtSur_ptr());

														for (unsigned int j = 0; j < mVector_vectorWithSurfacePointer_LLT.at(13).size(); j++)
														{
															surface_13 = mVector_vectorWithSurfacePointer_LLT.at(13).at(j);
															tempOptSys.fillTracingVectorSurfaces(13, surface_13);
															tempOptSys.fillTracingVectorInteraction(13, mOptSysEle.getPosAndInteraction_LLT().at(13).getInteractionAtSur_ptr());

															for (unsigned int i = 0; i < mVector_vectorWithSurfacePointer_LLT.at(14).size(); i++)
															{
																surface_14 = mVector_vectorWithSurfacePointer_LLT.at(14).at(i);
																tempOptSys.fillTracingVectorSurfaces(14, surface_14);
																tempOptSys.fillTracingVectorInteraction(14, mOptSysEle.getPosAndInteraction_LLT().at(14).getInteractionAtSur_ptr());



																for (unsigned int j = 0; j < mVector_vectorWithSurfacePointer_LLT.at(15).size(); j++)
																{
																	surface_15 = mVector_vectorWithSurfacePointer_LLT.at(15).at(j);
																	tempOptSys.fillTracingVectorSurfaces(15, surface_15);
																	tempOptSys.fillTracingVectorInteraction(15, mOptSysEle.getPosAndInteraction_LLT().at(15).getInteractionAtSur_ptr());

																	for (unsigned int i = 0; i < mVector_vectorWithSurfacePointer_LLT.at(16).size(); i++)
																	{
																		surface_16 = mVector_vectorWithSurfacePointer_LLT.at(16).at(i);
																		tempOptSys.fillTracingVectorSurfaces(16, surface_16);
																		tempOptSys.fillTracingVectorInteraction(16, mOptSysEle.getPosAndInteraction_LLT().at(16).getInteractionAtSur_ptr());

																		for (unsigned int j = 0; j < mVector_vectorWithSurfacePointer_LLT.at(17).size(); j++)
																		{
																			surface_17 = mVector_vectorWithSurfacePointer_LLT.at(17).at(j);
																			tempOptSys.fillTracingVectorSurfaces(17, surface_17);
																			tempOptSys.fillTracingVectorInteraction(17, mOptSysEle.getPosAndInteraction_LLT().at(17).getInteractionAtSur_ptr());

																			for (unsigned int i = 0; i < mVector_vectorWithSurfacePointer_LLT.at(18).size(); i++)
																			{
																				surface_18 = mVector_vectorWithSurfacePointer_LLT.at(18).at(i);
																				tempOptSys.fillTracingVectorSurfaces(18, surface_18);
																				tempOptSys.fillTracingVectorInteraction(18, mOptSysEle.getPosAndInteraction_LLT().at(18).getInteractionAtSur_ptr());

																				mPossibleOpticalSystem_LLT.push_back(tempOptSys.clone());

																				tempOptSys.cleanSurfaceAndInteractionStartAt_i(18);
																			}
																			tempOptSys.cleanSurfaceAndInteractionStartAt_i(17);
																		}
																		tempOptSys.cleanSurfaceAndInteractionStartAt_i(16);
																	}
																	tempOptSys.cleanSurfaceAndInteractionStartAt_i(15);

																}
																tempOptSys.cleanSurfaceAndInteractionStartAt_i(14);
															}
															tempOptSys.cleanSurfaceAndInteractionStartAt_i(13);
														}
														tempOptSys.cleanSurfaceAndInteractionStartAt_i(12);
													}
													tempOptSys.cleanSurfaceAndInteractionStartAt_i(11);
												}
												tempOptSys.cleanSurfaceAndInteractionStartAt_i(10);
											}
											tempOptSys.cleanSurfaceAndInteractionStartAt_i(9);
										}


										tempOptSys.cleanSurfaceAndInteractionStartAt_i(8);
									}


									tempOptSys.cleanSurfaceAndInteractionStartAt_i(7);
								}


								tempOptSys.cleanSurfaceAndInteractionStartAt_i(6);
							}
							tempOptSys.cleanSurfaceAndInteractionStartAt_i(5);

						}

						tempOptSys.cleanSurfaceAndInteractionStartAt_i(4);

					}
					tempOptSys.cleanSurfaceAndInteractionStartAt_i(3);
				}
				tempOptSys.cleanSurfaceAndInteractionStartAt_i(2);
			}
			tempOptSys.cleanSurfaceAndInteractionStartAt_i(1);
		}
		//tempOptSys.cleanSurfaceAndInteractionStartAt_i(0);
	}


}
void BuildSystemsForCombination::buildOpticalSystemCombination_19Surfaces_Element()
{
	unsigned int numberSurfaces = mVector_vectorWithSurfacePointer_Element.size();
	//unsigned int numberSurfaces = mVector_vectorWithSurfacePointer_LLT.size();

	//std::vector<std::shared_ptr<InteractionRay_LLT>> tempInteractions_LLT;
	std::vector<std::shared_ptr<Element_CR>> tempInteractions_Element;
	OpticalSystemElement tempOptSysElement;
	//OpticalSystemElement tempOptSys;

	std::shared_ptr<Element_CR> surface_0;
	std::shared_ptr<Element_CR> surface_1;
	std::shared_ptr<Element_CR> surface_2;
	std::shared_ptr<Element_CR> surface_3;
	std::shared_ptr<Element_CR> surface_4;
	std::shared_ptr<Element_CR> surface_5;
	std::shared_ptr<Element_CR> surface_6;
	std::shared_ptr<Element_CR> surface_7;
	std::shared_ptr<Element_CR> surface_8;
	std::shared_ptr<Element_CR> surface_9;
	std::shared_ptr<Element_CR> surface_10;
	std::shared_ptr<Element_CR> surface_11;
	std::shared_ptr<Element_CR> surface_12;
	std::shared_ptr<Element_CR> surface_13;
	std::shared_ptr<Element_CR> surface_14;
	std::shared_ptr<Element_CR> surface_15;
	std::shared_ptr<Element_CR> surface_16;
	std::shared_ptr<Element_CR> surface_17;
	std::shared_ptr<Element_CR> surface_18;

	for (unsigned int a = 0; a < mVector_vectorWithSurfacePointer_Element.at(0).size(); a++)
	{
		surface_0 = mVector_vectorWithSurfacePointer_Element.at(0).at(a);
		tempOptSysElement.fillPosAndElementAndInteraction(0, surface_0, mOptSysEle.getPosAndInteraction_LLT()[0].getInteractionAtSur_ptr());

		for (unsigned int b = 0; b < mVector_vectorWithSurfacePointer_Element.at(1).size(); b++)
		{
			surface_1 = mVector_vectorWithSurfacePointer_Element.at(1).at(b);
			tempOptSysElement.fillPosAndElementAndInteraction(1, surface_1, mOptSysEle.getPosAndInteraction_LLT()[1].getInteractionAtSur_ptr());

			for (unsigned int c = 0; c < mVector_vectorWithSurfacePointer_Element.at(2).size(); c++)
			{
				surface_2 = mVector_vectorWithSurfacePointer_Element.at(2).at(c);
				tempOptSysElement.fillPosAndElementAndInteraction(2, surface_2, mOptSysEle.getPosAndInteraction_LLT()[2].getInteractionAtSur_ptr());

				for (unsigned int d = 0; d < mVector_vectorWithSurfacePointer_Element.at(3).size(); d++)
				{
					surface_3 = mVector_vectorWithSurfacePointer_Element.at(3).at(d);
					tempOptSysElement.fillPosAndElementAndInteraction(3, surface_3, mOptSysEle.getPosAndInteraction_LLT()[3].getInteractionAtSur_ptr());

					for (unsigned int e = 0; e < mVector_vectorWithSurfacePointer_Element.at(4).size(); e++)
					{
						surface_4 = mVector_vectorWithSurfacePointer_Element.at(4).at(e);
						tempOptSysElement.fillPosAndElementAndInteraction(4, surface_4, mOptSysEle.getPosAndInteraction_LLT()[4].getInteractionAtSur_ptr());

						for (unsigned int f = 0; f < mVector_vectorWithSurfacePointer_Element.at(5).size(); f++)
						{
							surface_5 = mVector_vectorWithSurfacePointer_Element.at(5).at(f);
							tempOptSysElement.fillPosAndElementAndInteraction(5, surface_5, mOptSysEle.getPosAndInteraction_LLT()[5].getInteractionAtSur_ptr());

							for (unsigned int g = 0; g < mVector_vectorWithSurfacePointer_Element.at(6).size(); g++)
							{
								surface_6 = mVector_vectorWithSurfacePointer_Element.at(6).at(g);
								tempOptSysElement.fillPosAndElementAndInteraction(6, surface_6, mOptSysEle.getPosAndInteraction_LLT()[6].getInteractionAtSur_ptr());

								for (unsigned int h = 0; h < mVector_vectorWithSurfacePointer_Element.at(7).size(); h++)
								{
									surface_7 = mVector_vectorWithSurfacePointer_Element.at(7).at(h);
									tempOptSysElement.fillPosAndElementAndInteraction(7, surface_7, mOptSysEle.getPosAndInteraction_LLT()[7].getInteractionAtSur_ptr());

									for (unsigned int i = 0; i < mVector_vectorWithSurfacePointer_Element.at(8).size(); i++)
									{
										surface_8 = mVector_vectorWithSurfacePointer_Element.at(8).at(i);
										tempOptSysElement.fillPosAndElementAndInteraction(8, surface_8, mOptSysEle.getPosAndInteraction_LLT()[8].getInteractionAtSur_ptr());

										for (unsigned int j = 0; j < mVector_vectorWithSurfacePointer_Element.at(9).size(); j++)
										{

											surface_9 = mVector_vectorWithSurfacePointer_Element.at(9).at(j);
											tempOptSysElement.fillPosAndElementAndInteraction(9, surface_9, mOptSysEle.getPosAndInteraction_LLT()[9].getInteractionAtSur_ptr());

											for (unsigned int i = 0; i < mVector_vectorWithSurfacePointer_Element.at(10).size(); i++)
											{
												surface_10 = mVector_vectorWithSurfacePointer_Element.at(10).at(i);
												tempOptSysElement.fillPosAndElementAndInteraction(10, surface_10, mOptSysEle.getPosAndInteraction_LLT()[10].getInteractionAtSur_ptr());

												for (unsigned int j = 0; j < mVector_vectorWithSurfacePointer_Element.at(11).size(); j++)
												{

													surface_11 = mVector_vectorWithSurfacePointer_Element.at(11).at(j);
													tempOptSysElement.fillPosAndElementAndInteraction(11, surface_11, mOptSysEle.getPosAndInteraction_LLT()[11].getInteractionAtSur_ptr());

													for (unsigned int i = 0; i < mVector_vectorWithSurfacePointer_Element.at(12).size(); i++)
													{
														surface_12 = mVector_vectorWithSurfacePointer_Element.at(10).at(i);
														tempOptSysElement.fillPosAndElementAndInteraction(12, surface_12, mOptSysEle.getPosAndInteraction_LLT()[12].getInteractionAtSur_ptr());

														for (unsigned int j = 0; j < mVector_vectorWithSurfacePointer_Element.at(13).size(); j++)
														{

															surface_13 = mVector_vectorWithSurfacePointer_Element.at(13).at(j);
															tempOptSysElement.fillPosAndElementAndInteraction(13, surface_13, mOptSysEle.getPosAndInteraction_LLT()[13].getInteractionAtSur_ptr());


															for (unsigned int i = 0; i < mVector_vectorWithSurfacePointer_Element.at(14).size(); i++)
															{
																surface_14 = mVector_vectorWithSurfacePointer_Element.at(14).at(i);
																tempOptSysElement.fillPosAndElementAndInteraction(14, surface_14, mOptSysEle.getPosAndInteraction_LLT()[14].getInteractionAtSur_ptr());

																for (unsigned int j = 0; j < mVector_vectorWithSurfacePointer_Element.at(15).size(); j++)
																{

																	surface_15 = mVector_vectorWithSurfacePointer_Element.at(15).at(j);
																	tempOptSysElement.fillPosAndElementAndInteraction(15, surface_15, mOptSysEle.getPosAndInteraction_LLT()[15].getInteractionAtSur_ptr());


																	for (unsigned int i = 0; i < mVector_vectorWithSurfacePointer_Element.at(16).size(); i++)
																	{
																		surface_16 = mVector_vectorWithSurfacePointer_Element.at(16).at(i);
																		tempOptSysElement.fillPosAndElementAndInteraction(16, surface_16, mOptSysEle.getPosAndInteraction_LLT()[16].getInteractionAtSur_ptr());

																		for (unsigned int j = 0; j < mVector_vectorWithSurfacePointer_Element.at(17).size(); j++)
																		{

																			surface_17 = mVector_vectorWithSurfacePointer_Element.at(17).at(j);
																			tempOptSysElement.fillPosAndElementAndInteraction(17, surface_17, mOptSysEle.getPosAndInteraction_LLT()[17].getInteractionAtSur_ptr());

																			for (unsigned int i = 0; i < mVector_vectorWithSurfacePointer_Element.at(18).size(); i++)
																			{
																				surface_18 = mVector_vectorWithSurfacePointer_Element.at(18).at(i);
																				tempOptSysElement.fillPosAndElementAndInteraction(18, surface_18, mOptSysEle.getPosAndInteraction_LLT()[18].getInteractionAtSur_ptr());

																				mPossibleOpticalSys_Element.push_back(tempOptSysElement.getDeepCopyOptSysEle());

																				tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(18);
																			}
																			tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(17);
																		}
																		tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(16);
																	}
																	tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(15);
																}
																tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(14);
															}
															tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(13);
														}
														tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(12);
													}
													tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(11);
												}
												tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(10);
											}
											tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(9);
										}


										tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(8);
									}


									tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(7);
								}


								tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(6);
							}
							tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(5);

						}

						tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(4);

					}
					tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(3);
				}
				tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(2);
			}
			tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(1);
		}
		//tempOptSys.cleanSurfaceAndInteractionStartAt_i(0);
	}


}
void BuildSystemsForCombination::buildOpticalSystemCombination_20Surfaces_LLT()
{
	unsigned int numberSurfaces = mVector_vectorWithSurfacePointer_LLT.size();


	std::vector<std::shared_ptr<InteractionRay_LLT>> tempInteractions_LLT;
	OpticalSystem_LLT tempOptSys;

	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_0;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_1;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_2;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_3;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_4;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_5;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_6;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_7;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_8;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_9;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_10;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_11;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_12;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_13;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_14;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_15;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_16;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_17;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_18;
	std::shared_ptr<SurfaceIntersectionRay_LLT> surface_19;

	for (unsigned int a = 0; a < mVector_vectorWithSurfacePointer_LLT.at(0).size(); a++)
	{
		surface_0 = mVector_vectorWithSurfacePointer_LLT.at(0).at(a);
		tempOptSys.fillTracingVectorSurfaces(0, surface_0);
		tempOptSys.fillTracingVectorInteraction(0, mOptSysEle.getPosAndInteraction_LLT().at(0).getInteractionAtSur_ptr());

		for (unsigned int b = 0; b < mVector_vectorWithSurfacePointer_LLT.at(1).size(); b++)
		{
			surface_1 = mVector_vectorWithSurfacePointer_LLT.at(1).at(b);
			tempOptSys.fillTracingVectorSurfaces(1, surface_1);
			tempOptSys.fillTracingVectorInteraction(1, mOptSysEle.getPosAndInteraction_LLT().at(1).getInteractionAtSur_ptr());

			for (unsigned int c = 0; c < mVector_vectorWithSurfacePointer_LLT.at(2).size(); c++)
			{
				surface_2 = mVector_vectorWithSurfacePointer_LLT.at(2).at(c);
				tempOptSys.fillTracingVectorSurfaces(2, surface_2);
				tempOptSys.fillTracingVectorInteraction(2, mOptSysEle.getPosAndInteraction_LLT().at(2).getInteractionAtSur_ptr());

				for (unsigned int d = 0; d < mVector_vectorWithSurfacePointer_LLT.at(3).size(); d++)
				{
					surface_3 = mVector_vectorWithSurfacePointer_LLT.at(3).at(d);
					tempOptSys.fillTracingVectorSurfaces(3, surface_3);
					tempOptSys.fillTracingVectorInteraction(3, mOptSysEle.getPosAndInteraction_LLT().at(3).getInteractionAtSur_ptr());

					for (unsigned int e = 0; e < mVector_vectorWithSurfacePointer_LLT.at(4).size(); e++)
					{
						surface_4 = mVector_vectorWithSurfacePointer_LLT.at(4).at(e);
						tempOptSys.fillTracingVectorSurfaces(4, surface_4);
						tempOptSys.fillTracingVectorInteraction(4, mOptSysEle.getPosAndInteraction_LLT().at(4).getInteractionAtSur_ptr());

						for (unsigned int f = 0; f < mVector_vectorWithSurfacePointer_LLT.at(5).size(); f++)
						{
							surface_5 = mVector_vectorWithSurfacePointer_LLT.at(5).at(f);
							tempOptSys.fillTracingVectorSurfaces(5, surface_5);
							tempOptSys.fillTracingVectorInteraction(5, mOptSysEle.getPosAndInteraction_LLT().at(5).getInteractionAtSur_ptr());

							for (unsigned int g = 0; g < mVector_vectorWithSurfacePointer_LLT.at(6).size(); g++)
							{
								surface_6 = mVector_vectorWithSurfacePointer_LLT.at(6).at(g);
								tempOptSys.fillTracingVectorSurfaces(6, surface_6);
								tempOptSys.fillTracingVectorInteraction(6, mOptSysEle.getPosAndInteraction_LLT().at(6).getInteractionAtSur_ptr());

								for (unsigned int h = 0; h < mVector_vectorWithSurfacePointer_LLT.at(7).size(); h++)
								{
									surface_7 = mVector_vectorWithSurfacePointer_LLT.at(7).at(h);
									tempOptSys.fillTracingVectorSurfaces(7, surface_7);
									tempOptSys.fillTracingVectorInteraction(7, mOptSysEle.getPosAndInteraction_LLT().at(7).getInteractionAtSur_ptr());

									for (unsigned int i = 0; i < mVector_vectorWithSurfacePointer_LLT.at(8).size(); i++)
									{
										surface_8 = mVector_vectorWithSurfacePointer_LLT.at(8).at(i);
										tempOptSys.fillTracingVectorSurfaces(8, surface_8);
										tempOptSys.fillTracingVectorInteraction(8, mOptSysEle.getPosAndInteraction_LLT().at(8).getInteractionAtSur_ptr());

										for (unsigned int j = 0; j < mVector_vectorWithSurfacePointer_LLT.at(9).size(); j++)
										{
											surface_9 = mVector_vectorWithSurfacePointer_LLT.at(9).at(j);
											tempOptSys.fillTracingVectorSurfaces(9, surface_9);
											tempOptSys.fillTracingVectorInteraction(9, mOptSysEle.getPosAndInteraction_LLT().at(9).getInteractionAtSur_ptr());

											for (unsigned int i = 0; i < mVector_vectorWithSurfacePointer_LLT.at(10).size(); i++)
											{
												surface_10 = mVector_vectorWithSurfacePointer_LLT.at(10).at(i);
												tempOptSys.fillTracingVectorSurfaces(10, surface_10);
												tempOptSys.fillTracingVectorInteraction(10, mOptSysEle.getPosAndInteraction_LLT().at(10).getInteractionAtSur_ptr());

												for (unsigned int j = 0; j < mVector_vectorWithSurfacePointer_LLT.at(11).size(); j++)
												{
													surface_11 = mVector_vectorWithSurfacePointer_LLT.at(11).at(j);
													tempOptSys.fillTracingVectorSurfaces(11, surface_11);
													tempOptSys.fillTracingVectorInteraction(11, mOptSysEle.getPosAndInteraction_LLT().at(11).getInteractionAtSur_ptr());

													for (unsigned int i = 0; i < mVector_vectorWithSurfacePointer_LLT.at(12).size(); i++)
													{
														surface_12 = mVector_vectorWithSurfacePointer_LLT.at(12).at(i);
														tempOptSys.fillTracingVectorSurfaces(12, surface_12);
														tempOptSys.fillTracingVectorInteraction(12, mOptSysEle.getPosAndInteraction_LLT().at(12).getInteractionAtSur_ptr());

														for (unsigned int j = 0; j < mVector_vectorWithSurfacePointer_LLT.at(13).size(); j++)
														{
															surface_13 = mVector_vectorWithSurfacePointer_LLT.at(13).at(j);
															tempOptSys.fillTracingVectorSurfaces(13, surface_13);
															tempOptSys.fillTracingVectorInteraction(13, mOptSysEle.getPosAndInteraction_LLT().at(13).getInteractionAtSur_ptr());

															for (unsigned int i = 0; i < mVector_vectorWithSurfacePointer_LLT.at(14).size(); i++)
															{
																surface_14 = mVector_vectorWithSurfacePointer_LLT.at(14).at(i);
																tempOptSys.fillTracingVectorSurfaces(14, surface_14);
																tempOptSys.fillTracingVectorInteraction(14, mOptSysEle.getPosAndInteraction_LLT().at(14).getInteractionAtSur_ptr());



																for (unsigned int j = 0; j < mVector_vectorWithSurfacePointer_LLT.at(15).size(); j++)
																{
																	surface_15 = mVector_vectorWithSurfacePointer_LLT.at(15).at(j);
																	tempOptSys.fillTracingVectorSurfaces(15, surface_15);
																	tempOptSys.fillTracingVectorInteraction(15, mOptSysEle.getPosAndInteraction_LLT().at(15).getInteractionAtSur_ptr());

																	for (unsigned int i = 0; i < mVector_vectorWithSurfacePointer_LLT.at(16).size(); i++)
																	{
																		surface_16 = mVector_vectorWithSurfacePointer_LLT.at(16).at(i);
																		tempOptSys.fillTracingVectorSurfaces(16, surface_16);
																		tempOptSys.fillTracingVectorInteraction(16, mOptSysEle.getPosAndInteraction_LLT().at(16).getInteractionAtSur_ptr());

																		for (unsigned int j = 0; j < mVector_vectorWithSurfacePointer_LLT.at(17).size(); j++)
																		{
																			surface_17 = mVector_vectorWithSurfacePointer_LLT.at(17).at(j);
																			tempOptSys.fillTracingVectorSurfaces(17, surface_17);
																			tempOptSys.fillTracingVectorInteraction(17, mOptSysEle.getPosAndInteraction_LLT().at(17).getInteractionAtSur_ptr());

																			for (unsigned int i = 0; i < mVector_vectorWithSurfacePointer_LLT.at(18).size(); i++)
																			{
																				surface_18 = mVector_vectorWithSurfacePointer_LLT.at(18).at(i);
																				tempOptSys.fillTracingVectorSurfaces(18, surface_18);
																				tempOptSys.fillTracingVectorInteraction(18, mOptSysEle.getPosAndInteraction_LLT().at(18).getInteractionAtSur_ptr());


																				for (unsigned int j = 0; j < mVector_vectorWithSurfacePointer_LLT.at(19).size(); j++)
																				{
																					surface_19 = mVector_vectorWithSurfacePointer_LLT.at(19).at(j);
																					tempOptSys.fillTracingVectorSurfaces(19, surface_19);
																					tempOptSys.fillTracingVectorInteraction(19, mOptSysEle.getPosAndInteraction_LLT().at(19).getInteractionAtSur_ptr());

																					mPossibleOpticalSystem_LLT.push_back(tempOptSys.clone());

																					tempOptSys.cleanSurfaceAndInteractionStartAt_i(19);
																				}
																				tempOptSys.cleanSurfaceAndInteractionStartAt_i(18);
																			}
																			tempOptSys.cleanSurfaceAndInteractionStartAt_i(17);
																		}
																		tempOptSys.cleanSurfaceAndInteractionStartAt_i(16);
																	}
																	tempOptSys.cleanSurfaceAndInteractionStartAt_i(15);

																}
																tempOptSys.cleanSurfaceAndInteractionStartAt_i(14);
															}
															tempOptSys.cleanSurfaceAndInteractionStartAt_i(13);
														}
														tempOptSys.cleanSurfaceAndInteractionStartAt_i(12);
													}
													tempOptSys.cleanSurfaceAndInteractionStartAt_i(11);
												}
												tempOptSys.cleanSurfaceAndInteractionStartAt_i(10);
											}
											tempOptSys.cleanSurfaceAndInteractionStartAt_i(9);
										}


										tempOptSys.cleanSurfaceAndInteractionStartAt_i(8);
									}


									tempOptSys.cleanSurfaceAndInteractionStartAt_i(7);
								}


								tempOptSys.cleanSurfaceAndInteractionStartAt_i(6);
							}
							tempOptSys.cleanSurfaceAndInteractionStartAt_i(5);

						}

						tempOptSys.cleanSurfaceAndInteractionStartAt_i(4);

					}
					tempOptSys.cleanSurfaceAndInteractionStartAt_i(3);
				}
				tempOptSys.cleanSurfaceAndInteractionStartAt_i(2);
			}
			tempOptSys.cleanSurfaceAndInteractionStartAt_i(1);
		}
		//tempOptSys.cleanSurfaceAndInteractionStartAt_i(0);
	}


}
void BuildSystemsForCombination::buildOpticalSystemCombination_20Surfaces_Element()
{
	unsigned int numberSurfaces = mVector_vectorWithSurfacePointer_Element.size();
	//unsigned int numberSurfaces = mVector_vectorWithSurfacePointer_LLT.size();

	//std::vector<std::shared_ptr<InteractionRay_LLT>> tempInteractions_LLT;
	std::vector<std::shared_ptr<Element_CR>> tempInteractions_Element;
	OpticalSystemElement tempOptSysElement;
	//OpticalSystemElement tempOptSys;

	std::shared_ptr<Element_CR> surface_0;
	std::shared_ptr<Element_CR> surface_1;
	std::shared_ptr<Element_CR> surface_2;
	std::shared_ptr<Element_CR> surface_3;
	std::shared_ptr<Element_CR> surface_4;
	std::shared_ptr<Element_CR> surface_5;
	std::shared_ptr<Element_CR> surface_6;
	std::shared_ptr<Element_CR> surface_7;
	std::shared_ptr<Element_CR> surface_8;
	std::shared_ptr<Element_CR> surface_9;
	std::shared_ptr<Element_CR> surface_10;
	std::shared_ptr<Element_CR> surface_11;
	std::shared_ptr<Element_CR> surface_12;
	std::shared_ptr<Element_CR> surface_13;
	std::shared_ptr<Element_CR> surface_14;
	std::shared_ptr<Element_CR> surface_15;
	std::shared_ptr<Element_CR> surface_16;
	std::shared_ptr<Element_CR> surface_17;
	std::shared_ptr<Element_CR> surface_18;
	std::shared_ptr<Element_CR> surface_19;

	for (unsigned int a = 0; a < mVector_vectorWithSurfacePointer_Element.at(0).size(); a++)
	{
		surface_0 = mVector_vectorWithSurfacePointer_Element.at(0).at(a);
		tempOptSysElement.fillPosAndElementAndInteraction(0, surface_0, mOptSysEle.getPosAndInteraction_LLT()[0].getInteractionAtSur_ptr());

		for (unsigned int b = 0; b < mVector_vectorWithSurfacePointer_Element.at(1).size(); b++)
		{
			surface_1 = mVector_vectorWithSurfacePointer_Element.at(1).at(b);
			tempOptSysElement.fillPosAndElementAndInteraction(1, surface_1, mOptSysEle.getPosAndInteraction_LLT()[1].getInteractionAtSur_ptr());

			for (unsigned int c = 0; c < mVector_vectorWithSurfacePointer_Element.at(2).size(); c++)
			{
				surface_2 = mVector_vectorWithSurfacePointer_Element.at(2).at(c);
				tempOptSysElement.fillPosAndElementAndInteraction(2, surface_2, mOptSysEle.getPosAndInteraction_LLT()[2].getInteractionAtSur_ptr());

				for (unsigned int d = 0; d < mVector_vectorWithSurfacePointer_Element.at(3).size(); d++)
				{
					surface_3 = mVector_vectorWithSurfacePointer_Element.at(3).at(d);
					tempOptSysElement.fillPosAndElementAndInteraction(3, surface_3, mOptSysEle.getPosAndInteraction_LLT()[3].getInteractionAtSur_ptr());

					for (unsigned int e = 0; e < mVector_vectorWithSurfacePointer_Element.at(4).size(); e++)
					{
						surface_4 = mVector_vectorWithSurfacePointer_Element.at(4).at(e);
						tempOptSysElement.fillPosAndElementAndInteraction(4, surface_4, mOptSysEle.getPosAndInteraction_LLT()[4].getInteractionAtSur_ptr());

						for (unsigned int f = 0; f < mVector_vectorWithSurfacePointer_Element.at(5).size(); f++)
						{
							surface_5 = mVector_vectorWithSurfacePointer_Element.at(5).at(f);
							tempOptSysElement.fillPosAndElementAndInteraction(5, surface_5, mOptSysEle.getPosAndInteraction_LLT()[5].getInteractionAtSur_ptr());

							for (unsigned int g = 0; g < mVector_vectorWithSurfacePointer_Element.at(6).size(); g++)
							{
								surface_6 = mVector_vectorWithSurfacePointer_Element.at(6).at(g);
								tempOptSysElement.fillPosAndElementAndInteraction(6, surface_6, mOptSysEle.getPosAndInteraction_LLT()[6].getInteractionAtSur_ptr());

								for (unsigned int h = 0; h < mVector_vectorWithSurfacePointer_Element.at(7).size(); h++)
								{
									surface_7 = mVector_vectorWithSurfacePointer_Element.at(7).at(h);
									tempOptSysElement.fillPosAndElementAndInteraction(7, surface_7, mOptSysEle.getPosAndInteraction_LLT()[7].getInteractionAtSur_ptr());

									for (unsigned int i = 0; i < mVector_vectorWithSurfacePointer_Element.at(8).size(); i++)
									{
										surface_8 = mVector_vectorWithSurfacePointer_Element.at(8).at(i);
										tempOptSysElement.fillPosAndElementAndInteraction(8, surface_8, mOptSysEle.getPosAndInteraction_LLT()[8].getInteractionAtSur_ptr());

										for (unsigned int j = 0; j < mVector_vectorWithSurfacePointer_Element.at(9).size(); j++)
										{

											surface_9 = mVector_vectorWithSurfacePointer_Element.at(9).at(j);
											tempOptSysElement.fillPosAndElementAndInteraction(9, surface_9, mOptSysEle.getPosAndInteraction_LLT()[9].getInteractionAtSur_ptr());

											for (unsigned int i = 0; i < mVector_vectorWithSurfacePointer_Element.at(10).size(); i++)
											{
												surface_10 = mVector_vectorWithSurfacePointer_Element.at(10).at(i);
												tempOptSysElement.fillPosAndElementAndInteraction(10, surface_10, mOptSysEle.getPosAndInteraction_LLT()[10].getInteractionAtSur_ptr());

												for (unsigned int j = 0; j < mVector_vectorWithSurfacePointer_Element.at(11).size(); j++)
												{

													surface_11 = mVector_vectorWithSurfacePointer_Element.at(11).at(j);
													tempOptSysElement.fillPosAndElementAndInteraction(11, surface_11, mOptSysEle.getPosAndInteraction_LLT()[11].getInteractionAtSur_ptr());

													for (unsigned int i = 0; i < mVector_vectorWithSurfacePointer_Element.at(12).size(); i++)
													{
														surface_12 = mVector_vectorWithSurfacePointer_Element.at(10).at(i);
														tempOptSysElement.fillPosAndElementAndInteraction(12, surface_12, mOptSysEle.getPosAndInteraction_LLT()[12].getInteractionAtSur_ptr());

														for (unsigned int j = 0; j < mVector_vectorWithSurfacePointer_Element.at(13).size(); j++)
														{

															surface_13 = mVector_vectorWithSurfacePointer_Element.at(13).at(j);
															tempOptSysElement.fillPosAndElementAndInteraction(13, surface_13, mOptSysEle.getPosAndInteraction_LLT()[13].getInteractionAtSur_ptr());


															for (unsigned int i = 0; i < mVector_vectorWithSurfacePointer_Element.at(14).size(); i++)
															{
																surface_14 = mVector_vectorWithSurfacePointer_Element.at(14).at(i);
																tempOptSysElement.fillPosAndElementAndInteraction(14, surface_14, mOptSysEle.getPosAndInteraction_LLT()[14].getInteractionAtSur_ptr());

																for (unsigned int j = 0; j < mVector_vectorWithSurfacePointer_Element.at(15).size(); j++)
																{

																	surface_15 = mVector_vectorWithSurfacePointer_Element.at(15).at(j);
																	tempOptSysElement.fillPosAndElementAndInteraction(15, surface_15, mOptSysEle.getPosAndInteraction_LLT()[15].getInteractionAtSur_ptr());


																	for (unsigned int i = 0; i < mVector_vectorWithSurfacePointer_Element.at(16).size(); i++)
																	{
																		surface_16 = mVector_vectorWithSurfacePointer_Element.at(16).at(i);
																		tempOptSysElement.fillPosAndElementAndInteraction(16, surface_16, mOptSysEle.getPosAndInteraction_LLT()[16].getInteractionAtSur_ptr());

																		for (unsigned int j = 0; j < mVector_vectorWithSurfacePointer_Element.at(17).size(); j++)
																		{

																			surface_17 = mVector_vectorWithSurfacePointer_Element.at(17).at(j);
																			tempOptSysElement.fillPosAndElementAndInteraction(17, surface_17, mOptSysEle.getPosAndInteraction_LLT()[17].getInteractionAtSur_ptr());

																			for (unsigned int i = 0; i < mVector_vectorWithSurfacePointer_Element.at(18).size(); i++)
																			{
																				surface_18 = mVector_vectorWithSurfacePointer_Element.at(18).at(i);
																				tempOptSysElement.fillPosAndElementAndInteraction(18, surface_18, mOptSysEle.getPosAndInteraction_LLT()[18].getInteractionAtSur_ptr());

																				for (unsigned int j = 0; j < mVector_vectorWithSurfacePointer_Element.at(19).size(); j++)
																				{

																					surface_19 = mVector_vectorWithSurfacePointer_Element.at(19).at(j);
																					tempOptSysElement.fillPosAndElementAndInteraction(19, surface_19, mOptSysEle.getPosAndInteraction_LLT()[19].getInteractionAtSur_ptr());

																					mPossibleOpticalSys_Element.push_back(tempOptSysElement.getDeepCopyOptSysEle());

																					tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(19);
																				}
																				tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(18);
																			}
																			tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(17);
																		}
																		tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(16);
																	}
																	tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(15);
																}
																tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(14);
															}
															tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(13);
														}
														tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(12);
													}
													tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(11);
												}
												tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(10);
											}
											tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(9);
										}


										tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(8);
									}


									tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(7);
								}


								tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(6);
							}
							tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(5);

						}

						tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(4);

					}
					tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(3);
				}
				tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(2);
			}
			tempOptSysElement.cleanSurfaceAndInteractionStartAt_i(1);
		}
		//tempOptSys.cleanSurfaceAndInteractionStartAt_i(0);
	}


}
void BuildSystemsForCombination::checkIfOnePositionIsVariable()
{
	isOnePositionVariable = false;
	unsigned int sizeOptSys = mOptSysEle.getPosAndElement().size();
	typeModifier tempTypeMode;

	for (unsigned int i = 0; i < sizeOptSys; i++)
	{
		tempTypeMode = mOptSysEle.getPosAndElement().at(i).getElementInOptSys_ptr()->getPointTypeModifier_Z();

		if (tempTypeMode == typeModifierVariable)
		{
			isOnePositionVariable = true;
		}
	}

}

void BuildSystemsForCombination::saveDistances()
{
	unsigned int sizeOptSys = mOptSysEle.getPosAndElement().size();

	real tempPosBefore = 0;
	real tempPosAfter;
	real temDistance;

	for (unsigned int i = 0; i < sizeOptSys; i++)
	{
		tempPosAfter = mOptSysEle.getPosAndElement().at(i).getElementInOptSys_ptr()->getPointElementValue_Z();
		temDistance = tempPosAfter - tempPosBefore;
		mSaveDistances.push_back(temDistance);
		tempPosBefore = tempPosAfter;

	}
}

void BuildSystemsForCombination::setAllDistances_LLT()
{


	if (isOnePositionVariable)
	{
		unsigned int sizeOptSys = mOptSysEle.getPosAndElement().size();
		real tempPosBefore = 0.0;
		real tempPosAfter;
		real temDistance;
		typeModifier tempTypeMode;;

		for (unsigned int k = 0; k < mPossibleOpticalSystem_LLT.size(); k++)
		{

			for (unsigned int i = 1; i < sizeOptSys; i++)
			{
				tempTypeMode = mOptSysEle.getPosAndElement().at(i).getElementInOptSys_ptr()->getPointTypeModifier_Z();

				if (tempTypeMode == typeModifierFixed)
				{
					tempPosBefore = mPossibleOpticalSystem_LLT.at(k).getPosAndInteractingSurface().at(i - 1).getSurfaceInterRay_ptr()->getPoint().getZ();
					tempPosAfter = tempPosBefore + mSaveDistances.at(i);
					mPossibleOpticalSystem_LLT.at(k).getPosAndInteractingSurface().at(i).getSurfaceInterRay_ptr()->setPosition({ 0.0,0.0,tempPosAfter });
				}


			}
		}


	}

}


bool BuildSystemsForCombination::checkDistances()
{
	bool returnChecker = true;
	real tempPosBefore;
	real tempPos;
	real tempDistance;

	typeModifier tempTypeMode;

	for (unsigned int i = 0; i < mPossibleOpticalSystem_LLT.size(); i++)
	{
		tempPosBefore = 0.0;
		tempPos = 0.0;

		for (unsigned int k = 0; k < mOptSysEle.getPosAndElement().size(); k++)
		{
			tempPos = mPossibleOpticalSystem_LLT.at(i).getPosAndInteractingSurface().at(k).getSurfaceInterRay_ptr()->getPoint().getZ();
			tempDistance = tempPos - tempPosBefore;

			tempTypeMode = mOptSysEle.getPosAndElement().at(k).getElementInOptSys_ptr()->getPointTypeModifier_Z();

			if (tempTypeMode = typeModifierFixed)
			{
				if (tempDistance != mSaveDistances.at(k))
				{
					returnChecker = false;
				}
			}

			tempPosBefore = tempPos;

		}
	}

	return returnChecker;
}

bool BuildSystemsForCombination::checkInteractions()
{
	bool returnChecker = true;
	std::shared_ptr<InteractionRay_LLT> tempInteraction;
	std::shared_ptr<InteractionRay_LLT> interactionMainOptSys;

	for (unsigned int i = 0; i < mPossibleOpticalSystem_LLT.size(); i++)
	{


		for (unsigned int k = 0; k < mOptSysEle.getPosAndElement().size(); k++)
		{
			tempInteraction = mPossibleOpticalSystem_LLT.at(i).getPosAndInteraction().at(k).getInteractionAtSur_ptr();
			interactionMainOptSys = mOptSysEle.getPosAndInteraction_LLT().at(k).getInteractionAtSur_ptr();

			if (typeid(tempInteraction) != typeid(interactionMainOptSys))
			{
				returnChecker = false;
			}

		}
	}

	return returnChecker;
}

bool BuildSystemsForCombination::checkCombinations_LLT(unsigned int expectedVectorSize, std::vector<unsigned int> expectedCombination_vec)
{
	bool checkerVectorSize = true;;
	bool checkerExpectedCombinations = true;
	bool returnChecker = false;

	if (expectedVectorSize != mVector_vectorWithSurfacePointer_LLT.size())
	{
		checkerVectorSize = false;
	}

	for (unsigned int i = 0; i < expectedCombination_vec.size(); i++)
	{
		if (expectedCombination_vec.at(i) != mVector_vectorWithSurfacePointer_LLT.at(i).size())
		{
			checkerExpectedCombinations = false;
		}
	}


	if (checkerVectorSize == true && checkerExpectedCombinations == true)
	{
		returnChecker = true;
	}

	return returnChecker;
}

bool BuildSystemsForCombination::checkCombination_Element(unsigned int expectedVectorSize, std::vector<unsigned int> expectedCombination_vec)
{
	bool checkerVectorSize = true;;
	bool checkerExpectedCombinations = true;
	bool returnChecker = false;

	if (expectedVectorSize != mVector_vectorWithSurfacePointer_Element.size())
	{
		checkerVectorSize = false;
	}

	for (unsigned int i = 0; i < expectedCombination_vec.size(); i++)
	{
		if (expectedCombination_vec.at(i) != mVector_vectorWithSurfacePointer_Element.at(i).size())
		{
			checkerExpectedCombinations = false;
		}
	}


	if (checkerVectorSize == true && checkerExpectedCombinations == true)
	{
		returnChecker = true;
	}

	return returnChecker;
}


bool BuildSystemsForCombination::checkCombiRadiusPosAtSurface_n(unsigned int surfaceNum, std::vector<real> radius_vec, std::vector<real> pos_vec, real tolerance)
{
	bool returnChecker = true;
	real tempRadius;
	real tempPos_Z;

	for (unsigned int i = 0; i < mPossibleOpticalSystem_LLT.size(); i++)
	{
		tempRadius = mPossibleOpticalSystem_LLT.at(i).getPosAndInteractingSurface().at(surfaceNum).getSurfaceInterRay_ptr()->getRadius();
		tempPos_Z = mPossibleOpticalSystem_LLT.at(i).getPosAndInteractingSurface().at(surfaceNum).getSurfaceInterRay_ptr()->getPoint().getZ();

		//std::cout << "tempRadius: " << tempRadius << std::endl;
		//std::cout << "checkRadius: " << radius_vec.at(i) << std::endl;
		//
		//std::cout << "tempPosZ: " << tempPos_Z << std::endl;
		//std::cout << "checkPosZ: " << pos_vec.at(i) << std::endl;

		if (std::abs(radius_vec.at(i) - tempRadius) > tolerance)
		{
			returnChecker = false;
		}

		if (std::abs(pos_vec.at(i) != tempPos_Z) > tolerance)
		{
			returnChecker = false;
		}

	}

	return returnChecker;

}

bool BuildSystemsForCombination::checkCombiRadiusAtSurface(unsigned int surfaceNum, std::vector<real> radius_vec, real tolerance)
{
	bool returnChecker = true;
	real tempRadius{};
	real tempDirection_Z = 1;
	int prefix = 1;

	for (unsigned int i = 0; i < mPossibleOpticalSystem_LLT.size(); i++)
	{
		tempRadius = mPossibleOpticalSystem_LLT.at(i).getPosAndInteractingSurface().at(surfaceNum).getSurfaceInterRay_ptr()->getRadius();
		tempDirection_Z = mPossibleOpticalSystem_LLT.at(i).getPosAndInteractingSurface().at(surfaceNum).getSurfaceInterRay_ptr()->getDirection().getZ();

		if (tempDirection_Z < 0.0)
		{
			prefix = -1;
		}

		tempRadius = tempRadius * prefix;

		if (std::abs(radius_vec.at(i) - tempRadius) > tolerance)
		{
			returnChecker = false;
		}

		prefix = 1;

	}

	return returnChecker;
}

bool BuildSystemsForCombination::checkCombiPosAtSurface(unsigned int surfaceNum, std::vector<real> pos_vec, real tolerance)
{
	bool returnChecker = true;
	real tempPos_Z;

	for (unsigned int i = 0; i < mPossibleOpticalSystem_LLT.size(); i++)
	{
		tempPos_Z = mPossibleOpticalSystem_LLT.at(i).getPosAndInteractingSurface().at(surfaceNum).getSurfaceInterRay_ptr()->getPoint().getZ();

		if (std::abs(pos_vec.at(i) - tempPos_Z) > tolerance)
		{
			returnChecker = false;
		}

	}

	return returnChecker;
}

// get all possible optical systems LLT
std::vector<OpticalSystem_LLT> BuildSystemsForCombination::getAllPosOptSys_LLT()
{
	return mPossibleOpticalSystem_LLT;
}

void BuildSystemsForCombination::setAllDistances_Element()
{
	if (isOnePositionVariable)
	{
		unsigned int sizeOptSys = mOptSysEle.getPosAndElement().size();
		real tempPosBefore = 0.0;
		real tempPosAfter;
		real temDistance;
		typeModifier tempTypeMode;;

		for (unsigned int k = 0; k < mPossibleOpticalSys_Element.size(); k++)
		{

			for (unsigned int i = 1; i < sizeOptSys; i++)
			{
				tempTypeMode = mOptSysEle.getPosAndElement().at(i).getElementInOptSys_ptr()->getPointTypeModifier_Z();

				if (tempTypeMode == typeModifierFixed)
				{
					tempPosBefore = mPossibleOpticalSys_Element[k].getPosAndElement().at(i - 1).getElementInOptSys_ptr()->getPointElementValue_Z();
					tempPosAfter = tempPosBefore + mSaveDistances.at(i);
					mPossibleOpticalSys_Element.at(k).getPosAndElement()[i].getElementInOptSys_ptr()->setPointElementValue_Z(tempPosAfter);
				}


			}
		}


	}


}


// get all possible optical system element
std::vector<OpticalSystemElement> BuildSystemsForCombination::getAllPosOptSys_Element()
{
	return mPossibleOpticalSys_Element;
}


void BuildSystemsForCombination::clearAll()
{
	mParamVariableStructVec.clear();
	mParamVariableStructVec.resize(0);

	mAddInfosVar.clear();
	mAddInfosVar.resize(0);

	mPossibilitiesVariables.clear();
	mPossibilitiesVariables.resize(0);


	mVariableSurfaceNum.clear();;
	mVariableSurfaceNum.resize(0);

	mVector_vectorWithSurfacePointer_LLT.clear();;
	mVector_vectorWithSurfacePointer_LLT.resize(0);

	mVector_vectorWithSurfacePointer_Element.clear();;
	mVector_vectorWithSurfacePointer_Element.resize(0);

	mPossibleOpticalSystem_LLT.clear();;
	mPossibleOpticalSystem_LLT.resize(0);

	mPossibleOpticalSys_Element.clear();;
	mPossibleOpticalSys_Element.resize(0);

	mSaveDistances.clear();
	mSaveDistances.resize(0);

}