#include "OpticalSystemElement.h"
#include <iostream>

//#include "..\LowLevelTracing/Interaction/RefractedRay_LLT.h"
#include "..\oftenUseNamespace\oftenUseNamespace.h"
#include "..\SurfaceElements\ApertureStopElement.h"

PositionAndElementStruct::PositionAndElementStruct() {}
PositionAndElementStruct::~PositionAndElementStruct() {};

// set position of element in optical system
void PositionAndElementStruct::setPosition(unsigned int pos)
{
	position = pos;
}

// get position of element in optical system
unsigned int PositionAndElementStruct::getPosition()
{
	return position;
}



// set element in optical system
void PositionAndElementStruct::setElementInOptSys_ptr(std::shared_ptr<Element_CR> setElement)
{
	element = setElement;
}

// get element in optical system
std::shared_ptr<Element_CR> PositionAndElementStruct::getElementInOptSys_ptr()
{
	return element;
}







OpticalSystemElement::OpticalSystemElement() {};
OpticalSystemElement::~OpticalSystemElement() {};

//here we take an std::vec  with pointer so the surfaces
//we build the optical system with the default interaction "refraction" 
OpticalSystemElement::OpticalSystemElement(std::vector<std::shared_ptr<Element_CR>> elements_ptr, std::vector<std::shared_ptr<InteractionRay_LLT>> interaction_ptr)
{

	// build the optical system (default is refraction)
	for (unsigned int i = 0; i < elements_ptr.size(); i++)
	{
	fillPosAndElementAndInteraction(i, elements_ptr.at(i), interaction_ptr.at(i));
	}

	// convert the HLT system to LLT
	convertHLTSurfacesToLLTSurfaces();

};

void OpticalSystemElement::setRefractiveIndexAccordingToWavelength(real wavelenght)
{
	unsigned int sizeOptSys = mPosAndElement.size();

	for (unsigned int i = 0; i < sizeOptSys; i++)
	{
		mPosAndElement.at(i).getElementInOptSys_ptr()->calRefIndex_A_and_B_andSet(wavelenght);
	}

	convertSurfacesToLLT();
}


// convert HLT to LLT
void OpticalSystemElement::convertHLTtoLLT()
{
	mOpticalSystem_LLT = getLLTconversion_doConversion();

}

void OpticalSystemElement::printValues() 
{
	std::cout << mPosAndElement[0].getElementInOptSys_ptr().get() << "\n";
	//std::cout << mPosAndElement[0].getIneraction_ptr() << "\n";
	std::cout << mPosAndElement[0].getPosition() << "\n";


}

void OpticalSystemElement::setLength(real len)
{
	lengthOpticalSystem.set(len);
}

real OpticalSystemElement::getLength()
{
	return lengthOpticalSystem.getValue();
}



PositionAndElementStruct OpticalSystemElement::crossPosElement(int a) {
	return mPosAndElement[a];
}


// get pos and interaction LLT
std::vector<PosAndInteractionStruct> OpticalSystemElement::getPosAndInteraction_LLT()
{
	return mPosAndInteraction_LLT;
}


// get pos and intersection
std::vector<PosAndIntsectionSurfaceStruct> OpticalSystemElement::getPosAndIntersection_LLT()
{
	return mPosAndIntersecSurface_LLT;
}


// fill the optical system with elements
void OpticalSystemElement::fillPosAndElementAndInteraction(unsigned int position, std::shared_ptr<Element_CR> element, std::shared_ptr<InteractionRay_LLT> interaction)
{
	PositionAndElementStruct tempPosAndElem;
	tempPosAndElem.setPosition(position);
	tempPosAndElem.setElementInOptSys_ptr(element);

	PosAndInteractionStruct tempPosAndInteraction;
	tempPosAndInteraction.setPosition(position);
	tempPosAndInteraction.setInteractionAtSur(interaction);

	mPosAndElement.push_back(tempPosAndElem);
	mPosAndInteraction_LLT.push_back(tempPosAndInteraction);

}

// get size of optical system
unsigned int OpticalSystemElement::getSizeOptSys()
{
	return mPosAndElement.size();

}

// get position and element
std::vector<PositionAndElementStruct> OpticalSystemElement::getPosAndElement()
{
	return mPosAndElement;
}



// convert just surfaces
/*Peter*/ void OpticalSystemElement::convertSurfacesToLLT()
{
	unsigned int size = mPosAndElement.size();
	mPosAndIntersecSurface_LLT.clear();

	for (unsigned int i = 0; i < size; i++)
	{
		mPosAndElement.at(i).getElementInOptSys_ptr()->buildSurface_LLT();
		std::shared_ptr<SurfaceIntersectionRay_LLT> surfaceInterac_ptr = mPosAndElement.at(i).getElementInOptSys_ptr()->getSurfaceForLLT_ptr();

		//SurfaceIntersectionRay_LLT* surfaceInterac_ptr_new = new SurfaceIntersectionRay_LLT(*surfaceInterac_ptr);

		PosAndIntsectionSurfaceStruct PosAndInteractionSurface;
		PosAndInteractionSurface.setInteractionSurface_prt(surfaceInterac_ptr);
		PosAndInteractionSurface.setPosition(i);
		mPosAndIntersecSurface_LLT.push_back(PosAndInteractionSurface);
	}



}


// get LLT convertion
OpticalSystem_LLT OpticalSystemElement::getLLTconversion_doConversion()
{
	OpticalSystem_LLT returnOpticalSystemLLT;
	unsigned int size = mPosAndElement.size();

	
	mPosAndIntersecSurface_LLT.clear();
	//mPosAndInteraction_LLT.clear();


	for(unsigned int i = 0; i < size; i++)
	{

		mPosAndElement.at(i).getElementInOptSys_ptr()->buildSurface_LLT();
		std::shared_ptr<SurfaceIntersectionRay_LLT> surfaceInterac_ptr = mPosAndElement.at(i).getElementInOptSys_ptr()->getSurfaceForLLT_ptr();

		//SurfaceIntersectionRay_LLT* surfaceInterac_ptr_new = new SurfaceIntersectionRay_LLT(*surfaceInterac_ptr);

		PosAndIntsectionSurfaceStruct PosAndInteractionSurface;
		PosAndInteractionSurface.setInteractionSurface_prt(surfaceInterac_ptr);
		PosAndInteractionSurface.setPosition(i);
		mPosAndIntersecSurface_LLT.push_back(PosAndInteractionSurface);

		
		std::shared_ptr<InteractionRay_LLT> interaction_ptr = mPosAndInteraction_LLT.at(i).getInteractionAtSur_ptr();
		PosAndInteractionStruct posAndInteractionStruct;
		posAndInteractionStruct.setInteractionAtSur(interaction_ptr);
		posAndInteractionStruct.setPosition(i);
		mPosAndInteraction_LLT.push_back(posAndInteractionStruct);
				

		returnOpticalSystemLLT.fillVectorSurfaceAndInteractingData(i, surfaceInterac_ptr, interaction_ptr);
	}


	return returnOpticalSystemLLT;
}

void OpticalSystemElement::convertHLTSurfacesToLLTSurfaces()
{
	unsigned int size = mPosAndElement.size();
	
	mPosAndIntersecSurface_LLT.clear();
	//mPosAndInteraction_LLT.clear();


	for (unsigned int i = 0; i < size; i++)
	{

		mPosAndElement.at(i).getElementInOptSys_ptr()->buildSurface_LLT();
		std::shared_ptr<SurfaceIntersectionRay_LLT> surfaceInterac_ptr = mPosAndElement.at(i).getElementInOptSys_ptr()->getSurfaceForLLT_ptr();

		//SurfaceIntersectionRay_LLT* surfaceInterac_ptr_new = new SurfaceIntersectionRay_LLT(*surfaceInterac_ptr);

		PosAndIntsectionSurfaceStruct PosAndInteractionSurface;
		PosAndInteractionSurface.setInteractionSurface_prt(surfaceInterac_ptr);
		PosAndInteractionSurface.setPosition(i);
		mPosAndIntersecSurface_LLT.push_back(PosAndInteractionSurface);


	}

}


// get LLT opt sys
OpticalSystem_LLT OpticalSystemElement::getOpticalSystem_LLT()
{
	return mOpticalSystem_LLT;
}

// clear mPosAndInteraction_LLT
void OpticalSystemElement::clear_mPosAndInteraction_LLT()
{
	mPosAndInteraction_LLT.clear();
}

// clear mPosAndIntersecSurface_LLT
void OpticalSystemElement::clear_mPosAndIntersecSurface_LLT()
{
	mPosAndIntersecSurface_LLT.clear();
}

// get optical system element
OpticalSystemElement OpticalSystemElement::getOpticalSystemElement()
{
	OpticalSystemElement returnOpticalSysEle;
	std::shared_ptr<Element_CR> tempEle_ptr;
	std::shared_ptr<InteractionRay_LLT> tempInteraction_ptr;

	for (unsigned int i = 0; i < mPosAndElement.size(); i++)
	{
		tempEle_ptr = mPosAndElement.at(i).getElementInOptSys_ptr();
		
		tempInteraction_ptr = mPosAndInteraction_LLT.at(i).getInteractionAtSur_ptr();

		returnOpticalSysEle.fillPosAndElementAndInteraction(i, tempEle_ptr, tempInteraction_ptr);
		
	}
	returnOpticalSysEle.convertHLTSurfacesToLLTSurfaces();
	return returnOpticalSysEle;
}

// get deep copy of the optical system element
OpticalSystemElement OpticalSystemElement::getDeepCopyOptSysEle()
{
	OpticalSystemElement returnDeepCopyOptSys;
	std::shared_ptr<Element_CR> tempEle_ptr;
	std::shared_ptr<Element_CR> deepCopyEle_ptr;

	std::shared_ptr<InteractionRay_LLT> tempInteraction_ptr;


	for (unsigned int i = 0; i < mPosAndElement.size(); i++)
	{
		tempEle_ptr = mPosAndElement.at(i).getElementInOptSys_ptr();
		deepCopyEle_ptr = tempEle_ptr->getDeepCopyElement_ptr(mPosAndElement.at(i).getElementInOptSys_ptr());

		tempInteraction_ptr = mPosAndInteraction_LLT.at(i).getInteractionAtSur_ptr();
	
		returnDeepCopyOptSys.fillPosAndElementAndInteraction(i, deepCopyEle_ptr, tempInteraction_ptr);
	}
	returnDeepCopyOptSys.convertHLTSurfacesToLLTSurfaces();

	return returnDeepCopyOptSys;

}

void OpticalSystemElement::cleanSurfaceAndInteractionStartAt_i(unsigned int aimSize)
{

	aimSize--;
	std::vector<PositionAndElementStruct>::iterator endSurface = mPosAndElement.end();
	std::vector<PositionAndElementStruct>::iterator startSurface = mPosAndElement.begin();

	for (unsigned int i = 0; aimSize >= i; i++)
	{
		startSurface++;
	}
	mPosAndElement.erase(startSurface, endSurface);



}

// reverste optical system
OpticalSystemElement OpticalSystemElement::reverseOptSysEle(OpticalSystemElement optSysEle)
{
	real tempDirection_Z;
	unsigned int sizeOptSys = optSysEle.getPosAndElement().size();
	OpticalSystemElement OptSys = optSysEle.getDeepCopyOptSysEle();


	std::vector<real> directions_Z;
	directions_Z.resize(sizeOptSys);
	std::vector<real> point_Z;
	point_Z.resize(sizeOptSys);
	//std::vector<std::shared_ptr<InteractionRay_LLT>> interaction_vec;
	//interaction_vec.resize(sizeOptSys);

	for (int i = 0; i < sizeOptSys; ++i)
	{

		directions_Z[i] = OptSys.getPosAndElement()[i].getElementInOptSys_ptr()->getDirectionElementValue_Z();
		point_Z[i] = OptSys.getPosAndElement()[i].getElementInOptSys_ptr()->getPointElementValue_Z();
		//interaction_vec[i] = OptSys.getPosAndInteraction_LLT()[i].getInteractionAtSur_ptr();
	}

	// calculate thickness
	std::vector<real> thickness(sizeOptSys);
	thickness[0] = 0;
	real posBefore_Z = point_Z[0];
	real tempPos_Z;
	for (unsigned int i = 0; i < sizeOptSys - 1; ++i)
	{
		tempPos_Z = point_Z[i + 1];
		thickness[i] = tempPos_Z - posBefore_Z;
		posBefore_Z = tempPos_Z;
	}

	unsigned int thicknessCounter = thickness.size() - 1;
	std::vector<real>newPoint(sizeOptSys);
	for (unsigned int i = 0; i < sizeOptSys; ++i)
	{
		if (i > 0)
		{
			point_Z[i] = newPoint[i-1];
		}

		newPoint[i] = thickness[thicknessCounter] + point_Z[i];
		--thicknessCounter;

	}

	//std::rotate(newPoint.rbegin(), newPoint.rbegin() + 1, newPoint.rend());
	unsigned int pointCounter = sizeOptSys - 1;
	for (int i = 0; i < sizeOptSys; ++i)
	{
		OptSys.getPosAndElement()[i].getElementInOptSys_ptr()->setDirectionZ_value(directions_Z[i] * -1);
		//OptSys

		OptSys.getPosAndElement()[i].getElementInOptSys_ptr()->setPointElementValue_Z(newPoint[pointCounter]);
		pointCounter--;
	}

	OpticalSystemElement returnOptSysEle;
	unsigned newPoscounter = 0;

	std::shared_ptr< Element_CR > tempElement_ptr;
	std::shared_ptr< InteractionRay_LLT > tempInteraction_ptr;

	for (int i = sizeOptSys - 1; i >= 0; --i)
	{

		tempElement_ptr = OptSys.getPosAndElement()[i].getElementInOptSys_ptr();
		tempInteraction_ptr = OptSys.getPosAndInteraction_LLT()[i].getInteractionAtSur_ptr();

		returnOptSysEle.fillPosAndElementAndInteraction(newPoscounter, tempElement_ptr->clone(), tempInteraction_ptr->clone());

		++newPoscounter;
	}

	// TODO: here it would be enough only convert the directions_Z
	returnOptSysEle.convertHLTSurfacesToLLTSurfaces();

	return returnOptSysEle;
}

// fill in Element at position i
void OpticalSystemElement::fillInElementAndInteractionAtPos_i(unsigned int pos, std::shared_ptr<Element_CR> element_prt, std::shared_ptr<InteractionRay_LLT> interaction)
{
	unsigned int size = mPosAndElement.size() + 1;

	std::vector<PositionAndElementStruct> posAndElement_vec(size);
	std::vector<PosAndInteractionStruct> posAndInteraction_LLT_vec(size);
	std::vector<PosAndIntsectionSurfaceStruct> posAndIntersecSurface_LLT_vec(size);

	if (pos > size - 1)
	{
		pos = size - 1;
	}
	for (unsigned int i = 0; i < size; ++i)
	{
		if (i < pos)
		{
			posAndElement_vec[i] = mPosAndElement[i];
			posAndInteraction_LLT_vec[i]=mPosAndInteraction_LLT[i];
			posAndIntersecSurface_LLT_vec[i]=mPosAndIntersecSurface_LLT[i];
		}
		else if (i == pos)
		{
			posAndElement_vec[i].setElementInOptSys_ptr(element_prt);
			posAndElement_vec[i].setPosition(i);

			posAndInteraction_LLT_vec[i].setInteractionAtSur(interaction);
			posAndInteraction_LLT_vec[i].setPosition(i);

			element_prt->buildSurface_LLT();
			posAndIntersecSurface_LLT_vec[i].setInteractionSurface_prt(element_prt->getSurfaceForLLT_ptr());
			posAndIntersecSurface_LLT_vec[i].setPosition(i);
		}
		else if (i > pos)
		{
			posAndElement_vec[i] = mPosAndElement[i-1];
			posAndElement_vec[i].setPosition(i);

			posAndInteraction_LLT_vec[i] = mPosAndInteraction_LLT[i-1];
			posAndInteraction_LLT_vec[i].setPosition(i);

			posAndIntersecSurface_LLT_vec[i] = mPosAndIntersecSurface_LLT[i-1];
			posAndIntersecSurface_LLT_vec[i].setPosition(i);
		}

	}

	mPosAndElement = posAndElement_vec;
	mPosAndInteraction_LLT = posAndInteraction_LLT_vec;
	mPosAndIntersecSurface_LLT = posAndIntersecSurface_LLT_vec;
}

 OpticalSystem_LLT OpticalSystemElement::getOptSys_LLT_buildSystem()
{
	OpticalSystem_LLT returnOptSys_LLT{};
	unsigned int size = mPosAndElement.size();

	for (unsigned int i = 0; i < size; ++i)
	{

		std::shared_ptr<SurfaceIntersectionRay_LLT> surface_ptr = mPosAndIntersecSurface_LLT.at(i).getSurfaceInterRay_ptr();
		std::shared_ptr<InteractionRay_LLT> interaction_ptr = mPosAndInteraction_LLT.at(i).getInteractionAtSur_ptr();


		returnOptSys_LLT.fillVectorSurfaceAndInteractingData(i, surface_ptr->clone(), interaction_ptr->clone());
	}

	return returnOptSys_LLT;
}

 OpticalSystemElement OpticalSystemElement::convertOptSys_LLT_T0_OptSys_HLT(OpticalSystemElement optSys_Ele, OpticalSystem_LLT optSys_LLT)
 {
	 OpticalSystemElement retunrOptSysEle;
	 unsigned int sizeOptSys = optSys_LLT.getPosAndInteractingSurface().size();

	 OpticalSystemElement useOptSysEle;

	 std::shared_ptr<SurfaceIntersectionRay_LLT> tempSurfaceLLT_ptr;
	 std::shared_ptr<InteractionRay_LLT> tempInteraction_ptr;
	 std::shared_ptr<Element_CR> tempElement_ptr{};
	 std::shared_ptr<Element_CR> saveElement_ptr{};
	 real tempDirectionZ_Element;
	 real tempDirectionZ_LLT;

	 MaterialSellmeier1 glassA;
	 MaterialSellmeier1 glassB;

	 for (unsigned int i = 0; i < sizeOptSys; ++i)
	 {
		 tempSurfaceLLT_ptr = optSys_LLT.getPosAndInteractingSurface()[i].getSurfaceInterRay_ptr();
		 tempElement_ptr = optSys_Ele.getPosAndElement()[i].getElementInOptSys_ptr();

		 glassA = tempElement_ptr->getGlassA();
		 glassB = tempElement_ptr->getGlassB();

		 tempDirectionZ_Element = tempElement_ptr->getDirectionElementValue_Z();
		 tempDirectionZ_LLT = tempSurfaceLLT_ptr->getDirection().getZ();

		 if (oftenUse::checkSamePrefixTwoVal(tempDirectionZ_Element, tempDirectionZ_LLT))
		 {
			 saveElement_ptr = tempElement_ptr->buildElement(tempSurfaceLLT_ptr, glassA, glassB);
		 }
		 else // HLT and LLT have difference prefix
		 {
			 saveElement_ptr = tempElement_ptr->buildElement(tempSurfaceLLT_ptr, glassB, glassA);
		 }

		 tempInteraction_ptr = optSys_LLT.getPosAndInteraction()[i].getInteractionAtSur_ptr();

		 retunrOptSysEle.fillPosAndElementAndInteraction(i, saveElement_ptr, tempInteraction_ptr);

	 }

	 retunrOptSysEle.convertSurfacesToLLT();

	 return retunrOptSysEle;
 }

 OpticalSystemElement OpticalSystemElement::setRefractivIndexAccWave(OpticalSystemElement optSysEle, real wavelength)
 {
	 unsigned int sizeOptSys = optSysEle.getPosAndElement().size();

	 for (unsigned int i = 0; i < sizeOptSys; ++i)
	 {
		 optSysEle.getPosAndElement()[i].getElementInOptSys_ptr()->calRefIndex_A_and_B_andSet(wavelength);
	 }
	 return optSysEle;
 }

 std::vector<OpticalSystemElement> OpticalSystemElement::setRefractivIndexOptSysEle(std::vector<OpticalSystemElement> optSysEleVec, real waveLength)
 {
	 unsigned int sizeOptSysEleVec = optSysEleVec.size();

	 for (unsigned int i = 0; i < sizeOptSysEleVec; i++)
	 {
		 setRefractivIndexAccWave(optSysEleVec[i], waveLength);
	 }

	 return optSysEleVec;
 }

 void OpticalSystemElement::setNewElement_vec(std::vector<std::shared_ptr<Element_CR>> elements_ptr)
 {
	 mPosAndElement.clear();
	 mPosAndElement.resize(0);
	 mPosAndIntersecSurface_LLT.clear();
	 mPosAndIntersecSurface_LLT.resize(0);

	 // build the optical system (default is refraction)
	 for (unsigned int i = 0; i < elements_ptr.size(); i++)
	 {
		 fillPosAndElement(i, elements_ptr.at(i));
	 }

	 // convert the HLT system to LLT
	 convertSurfacesToLLT();


 }

 // fill pos and element
 void OpticalSystemElement::fillPosAndElement(unsigned int position, std::shared_ptr<Element_CR> element)
 {
	 PositionAndElementStruct tempPosAndElem;
	 tempPosAndElem.setPosition(position);
	 tempPosAndElem.setElementInOptSys_ptr(element);

	 mPosAndElement.push_back(tempPosAndElem);

 }


 OpticalSystemElement OpticalSystemElement::convertOptSys_LLT_T0_OptSys_HLT(OpticalSystemElement optSysStart_Ele, OpticalSystem_LLT bestOptSys_LLT, std::vector<parameterTypeModeStruct> parameter, std::vector< stepsWithoutMinWithoutMax> stepsWitoutMinMax)
 {

	 OpticalSystem_LLT bestOptSys_LLT_inter = bestOptSys_LLT.clone();
	 OpticalSystemElement bestOptSysEle = optSysStart_Ele.convertOptSys_LLT_T0_OptSys_HLT(optSysStart_Ele, bestOptSys_LLT_inter);

	 unsigned int numberParamer = parameter.size();
	 kindOfParameter tempParameter;
	 unsigned int tempPosParameter;

	 real tempV;
	 real tempWithoutMin;
	 real tempWithoutMax;
	 real tempStep;

	 real tempV_min;
	 real tempV_max;

	 for (unsigned int i = 0; i < numberParamer; i++)
	 {
		 tempParameter = parameter[i].getKindParam();
		 tempPosParameter = parameter[i].getSurfaceNum();
		 tempStep = stepsWitoutMinMax[i].getSteps();
		 tempWithoutMin = stepsWitoutMinMax[i].getWithoutMin();
		 tempWithoutMax = stepsWitoutMinMax[i].getWithoutMax();

		 if (tempParameter == radius)
		 {
			 tempV = bestOptSys_LLT_inter.getPosAndInteractingSurface()[tempPosParameter].getSurfaceInterRay_ptr()->getRadius();

			 tempV_min = tempV - tempStep;
			 tempV_max = tempV + tempStep;

			 if (tempV_min < tempWithoutMin)
			 {
				 tempV_min = tempWithoutMin;
			 }

			 if (tempV_max > tempWithoutMax)
			 {
				 tempV_max = tempWithoutMax;
			 }


			 bestOptSysEle.getPosAndElement()[tempPosParameter].getElementInOptSys_ptr()->setParameterRadius(tempV_min, tempV_max, 0.0, typeModifierVariable);

		 }

		 else if (tempParameter == position)
		 {
			 tempV = bestOptSys_LLT_inter.getPosAndInteractingSurface()[tempPosParameter].getSurfaceInterRay_ptr()->getPoint().getZ();

			 tempV_min = tempV - tempStep;
			 tempV_max = tempV + tempStep;

			 if (tempV_min < tempWithoutMin)
			 {
				 tempV_min = tempWithoutMin;
			 }

			 if (tempV_max > tempWithoutMax)
			 {
				 tempV_max = tempWithoutMax;
			 }

			 bestOptSysEle.getPosAndElement()[tempPosParameter].getElementInOptSys_ptr()->setParameterPointZ(tempV_min, tempV_max, 0.0, typeModifierVariable);
		 }



	 }

	 return bestOptSysEle;

 }


 void OpticalSystemElement::delSurfaceNumber_from_TO(int startSurfaceNo, int endSurfaceNo)
 {
	 std::vector<PositionAndElementStruct> posAndElement_vec;
	 PositionAndElementStruct posAndElement;
	 std::vector<PosAndInteractionStruct> posAndInteraction_LLT_vec;
	 PosAndInteractionStruct posAndInteraction_LLT;
	 std::vector<PosAndIntsectionSurfaceStruct> posAndIntersecSurface_LLT_vec;
	 PosAndIntsectionSurfaceStruct posAndIntersecSurface_LLT;

	 int size = mPosAndElement.size();
	 int tempSurfaceNum;
	
	 for (unsigned int i = 0; i < size; i++)
	 {
		 tempSurfaceNum = mPosAndElement[i].getPosition();

		 if (startSurfaceNo <= tempSurfaceNum && tempSurfaceNum <= endSurfaceNo)
		 {
			 std::cout << "surface deleted" << std::endl;
		 }

		 else // do no delete the surface
		 {
			 posAndElement = mPosAndElement[i];
			 posAndElement_vec.push_back(posAndElement);

			 posAndInteraction_LLT = mPosAndInteraction_LLT[i];
			 posAndInteraction_LLT_vec.push_back(posAndInteraction_LLT);

			 posAndIntersecSurface_LLT = mPosAndIntersecSurface_LLT[i];
			 posAndIntersecSurface_LLT_vec.push_back(posAndIntersecSurface_LLT);
		 }

	 }

	 // set new positions
	 unsigned int newSize = posAndElement_vec.size();
	 for (unsigned int i = 0; i < newSize; i++)
	 {
		 posAndElement_vec[i].setPosition(i);
		 posAndInteraction_LLT_vec[i].setPosition(i);
		 posAndIntersecSurface_LLT_vec[i].setPosition(i);
	 }

	 mPosAndElement = posAndElement_vec;
	 mPosAndInteraction_LLT = posAndInteraction_LLT_vec;
	 mPosAndIntersecSurface_LLT = posAndIntersecSurface_LLT_vec;

 }

 unsigned int OpticalSystemElement::getPosApertureStop()
 {
	
	 unsigned int sizeOfOptSys = mPosAndElement.size();
	 std::shared_ptr<Element_CR> tempSurface_ptr;
	 ApertureStopElement apertureStop_ptr;


	 for (unsigned int i = 0; i < sizeOfOptSys; i++)
	 {
		 tempSurface_ptr = mPosAndElement[i].getElementInOptSys_ptr();

		 if (typeid(*tempSurface_ptr) == typeid(apertureStop_ptr))
		 {
			 return i;
		 }

	 }

	 std::cout << "there is no aperture stop in your optical system!!!" << std::endl;
	 return oftenUse::getInfInt();

	
 }

 infosAS OpticalSystemElement::getInfoAS()
 {
	 infosAS returnInfosAS;

	 unsigned int posAS = getPosApertureStop();
	 returnInfosAS.setPosAS(posAS);
	 
	 std::shared_ptr<Element_CR> apertureStop_ptr = mPosAndElement[posAS].getElementInOptSys_ptr();

	 real semiHeightAS = apertureStop_ptr->getSemiHeightElementValue();
	 returnInfosAS.setSemiHeightAS(semiHeightAS);
	 
	 VectorStructR3 pointAS;
	 real pointAS_Z = apertureStop_ptr->getPointElementValue_Z();
	 pointAS.setX(0.0);
	 pointAS.setY(0.0);
	 pointAS.setZ(pointAS_Z);
	 returnInfosAS.setPointAS(pointAS);

	 VectorStructR3 directionAS;
	 real diractionAS_Z	 = apertureStop_ptr->getDirectionElementValue_Z();
	 directionAS.setX(0.0);
	 directionAS.setY(0.0);
	 directionAS.setZ(diractionAS_Z);
	 returnInfosAS.setDirAS(directionAS);

	 return returnInfosAS;
 }