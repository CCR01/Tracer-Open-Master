#pragma once

#include "OpticalSystem_LLT.h"
#include <qwt_plot.h>
#include <qwt_plot_curve.h>
#include "Surfaces/ApertureStop_LLT.h"


// pos AS
unsigned int infosAS::getPosAS()
{
	return mPosAS;
}
void infosAS::setPosAS(unsigned int posAS)
{
	mPosAS = posAS;
}
// semiHeight AS
real infosAS::getSemiHeightAS()
{
	return mSemiHeightAS;
}
void infosAS::setSemiHeightAS(real semiHeightAS)
{
	mSemiHeightAS = semiHeightAS;
}

// point AS
VectorStructR3 infosAS::getPointAS()
{
	return mPointAS;
}
void infosAS::setPointAS(VectorStructR3 pointAS)
{
	mPointAS = pointAS;
}
// direction
VectorStructR3 infosAS::getDirAS()
{
	return mDirectionAS;
}
void infosAS::setDirAS(VectorStructR3 dirAS)
{
	mDirectionAS = dirAS;
}


PosAndIntsectionSurfaceStruct::PosAndIntsectionSurfaceStruct() {};
PosAndIntsectionSurfaceStruct::PosAndIntsectionSurfaceStruct(unsigned int const pos, std::shared_ptr<SurfaceIntersectionRay_LLT> interactinSur) :
	mPosition(pos),
	mInteractinSurface(interactinSur)
{}
PosAndIntsectionSurfaceStruct::~PosAndIntsectionSurfaceStruct()
{
	//delete mInteractinSurface;
};


// set position
void PosAndIntsectionSurfaceStruct::setPosition(unsigned int const pos)
{
	mPosition = pos;
}

// get position
unsigned int PosAndIntsectionSurfaceStruct::getPosition() const
{
	return mPosition;
}



// set interacting surface
void PosAndIntsectionSurfaceStruct::setInteractionSurface_prt(std::shared_ptr<SurfaceIntersectionRay_LLT> setSurInterRay_LLT_ptr)
{
	mInteractinSurface = setSurInterRay_LLT_ptr;
}


// get interaction surface
std::shared_ptr<SurfaceIntersectionRay_LLT> PosAndIntsectionSurfaceStruct::getSurfaceInterRay_ptr() const
{
	return mInteractinSurface;
}

PosAndIntsectionSurfaceStruct PosAndIntsectionSurfaceStruct::clone()
{
	std::shared_ptr<SurfaceIntersectionRay_LLT> newSurface_ptr = mInteractinSurface->clone();
	int newPos = mPosition;

	PosAndIntsectionSurfaceStruct newPosAndSurface(newPos, newSurface_ptr);

	return newPosAndSurface;

}

PosAndInteractionStruct::PosAndInteractionStruct() {};
PosAndInteractionStruct::PosAndInteractionStruct(int pos, std::shared_ptr<InteractionRay_LLT> intact) :
mPosition(pos),
mInteraction(intact)
{}

PosAndInteractionStruct::~PosAndInteractionStruct() 
{
	//delete mInteraction;
}

// set position
void PosAndInteractionStruct::setPosition(unsigned int const pos)
{
	mPosition = pos;
}
// get position
unsigned int PosAndInteractionStruct::getPosition() const
{
	return mPosition;
}

// set interaction at surface
void PosAndInteractionStruct::setInteractionAtSur(std::shared_ptr<InteractionRay_LLT> setInteractionRay_LLT_ptr)
{
	mInteraction = setInteractionRay_LLT_ptr;
}
// get interaction at surface
std::shared_ptr<InteractionRay_LLT> PosAndInteractionStruct::getInteractionAtSur_ptr() const
{
	return mInteraction;
}

PosAndInteraSurfaceToPlot2D::PosAndInteraSurfaceToPlot2D() {};
PosAndInteraSurfaceToPlot2D::PosAndInteraSurfaceToPlot2D(int pos, SurfaceIntersectionRay_LLT* surfaceToPlot2D_ptr) :
	mPosition(pos),
	mPlotSur_ptr(surfaceToPlot2D_ptr)
{}
PosAndInteraSurfaceToPlot2D::~PosAndInteraSurfaceToPlot2D()
{
	//delete mPlotSur_ptr;
};

// set position
void PosAndInteraSurfaceToPlot2D::setPosition(unsigned int const pos)
{
	mPosition = pos;
}

// get position
unsigned int PosAndInteraSurfaceToPlot2D::getPosition() const
{
	return mPosition;
}

// set surface to plot 2D
void PosAndInteraSurfaceToPlot2D::setSurfaceToPlo2D_ptr(SurfaceIntersectionRay_LLT* setSurfaceToPlot2D)
{
	mPlotSur_ptr = setSurfaceToPlot2D;
}

// get surface to plot 2D
SurfaceIntersectionRay_LLT* PosAndInteraSurfaceToPlot2D::getSurfaceToPlot2D_ptr() const
{
	return mPlotSur_ptr;
}

OpticalSystem_LLT::OpticalSystem_LLT() {};
OpticalSystem_LLT::OpticalSystem_LLT(std::vector<PosAndIntsectionSurfaceStruct> posAndIntersecSur, std::vector<PosAndInteractionStruct> posAndInteraction) :
	mPosAndIntersectionSurfaceVector(posAndIntersecSur),
	mPosAndInteraction(posAndInteraction)
{}
OpticalSystem_LLT::OpticalSystem_LLT(std::vector<std::shared_ptr<SurfaceIntersectionRay_LLT>> interactinSurface, std::vector<std::shared_ptr<InteractionRay_LLT>> interaction)
{
	unsigned int size = interactinSurface.size();
	mPosAndIntersectionSurfaceVector.resize(size);
	mPosAndInteraction.resize(size);

	for (unsigned int i = 0; i < size; ++i)
	{
		mPosAndIntersectionSurfaceVector[i].setPosition(i);
		mPosAndIntersectionSurfaceVector[i].setInteractionSurface_prt(interactinSurface[i]);

		mPosAndInteraction[i].setPosition(i);
		mPosAndInteraction[i].setInteractionAtSur(interaction[i]);

	}
}

OpticalSystem_LLT::~OpticalSystem_LLT() {};


// fill vector with surface and interacting datas
void OpticalSystem_LLT::fillVectorSurfaceAndInteractingData(int position, std::shared_ptr<SurfaceIntersectionRay_LLT> interactinSurface, std::shared_ptr<InteractionRay_LLT> interaction)
{

	fillTracingVectorSurfaces(position, interactinSurface);
	fillTracingVectorInteraction(position, interaction);
}

// fill vector with surface and interacting datas
void OpticalSystem_LLT::fillVectorSurfaceAndInteractingData(int position, SurfaceIntersectionRay_LLT* interactinSurface, std::shared_ptr<InteractionRay_LLT> interaction)
{
	std::shared_ptr< SurfaceIntersectionRay_LLT > surface_ptr;
	surface_ptr = interactinSurface->clone();

	fillTracingVectorSurfaces(position, surface_ptr);
	fillTracingVectorInteraction(position, interaction);
}

// fill optical system with surfaces and interaction
void OpticalSystem_LLT::fillOptSysWithSurfaceAndInteractions(std::vector< std::shared_ptr<SurfaceIntersectionRay_LLT>> surface_vec, std::vector< std::shared_ptr<InteractionRay_LLT>> interaction_vec)
{
	unsigned int sizeOptSys = surface_vec.size();
	for (unsigned int i = 0; i < sizeOptSys; ++i)
	{
		fillVectorSurfaceAndInteractingData(i, surface_vec[i], interaction_vec[i]);
	}

}

// fill the vector with the surfaces
void OpticalSystem_LLT::fillTracingVectorSurfaces(int position, std::shared_ptr<SurfaceIntersectionRay_LLT> interactingSurface)
{
	//mTracingVectorSurfaces.push_back (interactingSurface);
	PosAndIntsectionSurfaceStruct TempPosAndInteraSurface;
	TempPosAndInteraSurface.setPosition(position);
	TempPosAndInteraSurface.setInteractionSurface_prt(interactingSurface);
	mPosAndIntersectionSurfaceVector.push_back(TempPosAndInteraSurface);
}



// fill the array with interacions
void  OpticalSystem_LLT::fillTracingVectorInteraction(int position, std::shared_ptr<InteractionRay_LLT> interaction)
{
	PosAndInteractionStruct TempPosAndInteraction;
	TempPosAndInteraction.setPosition(position);
	TempPosAndInteraction.setInteractionAtSur(interaction);
	mPosAndInteraction.push_back(TempPosAndInteraction);

}

// get vector with position and interaction surface
std::vector<PosAndIntsectionSurfaceStruct> OpticalSystem_LLT::getPosAndInteractingSurface()
{
	return mPosAndIntersectionSurfaceVector;
}

// get position and interaction
std::vector<PosAndInteractionStruct> OpticalSystem_LLT::getPosAndInteraction()
{
	return mPosAndInteraction;
}

// fill in surface at position i
void OpticalSystem_LLT::fillInSurfaceAndInteracAtPos_i(unsigned int const position, std::shared_ptr<SurfaceIntersectionRay_LLT> interactinSurface, std::shared_ptr<InteractionRay_LLT> interaction)
{
	std::vector<PosAndIntsectionSurfaceStruct> tempPosAndIntersectionSurfaceVector;
	std::vector<PosAndInteractionStruct> tempmPosAndInteraction;
	unsigned int counter = 0;

	PosAndIntsectionSurfaceStruct newSurface(position, interactinSurface);
	PosAndInteractionStruct newInteraction(position, interaction);

	unsigned int interation;
	if (mPosAndInteraction.size() > position)
	{
		for (unsigned int i = 0; i < mPosAndInteraction.size(); i++)
		{
			unsigned int tempPos = mPosAndIntersectionSurfaceVector.at(i).getPosition();
			if (position == tempPos)
			{
				tempPosAndIntersectionSurfaceVector.push_back(newSurface);
				tempmPosAndInteraction.push_back(newInteraction);
				mPosAndIntersectionSurfaceVector.at(i).setPosition(tempPos + 1);
				tempPosAndIntersectionSurfaceVector.push_back(mPosAndIntersectionSurfaceVector.at(i));
				mPosAndInteraction.at(i).setPosition(tempPos + 1);
				tempmPosAndInteraction.push_back(mPosAndInteraction.at(i));
				counter++;
			}

			else
			{

				tempPosAndIntersectionSurfaceVector.push_back(mPosAndIntersectionSurfaceVector.at(i));
				tempPosAndIntersectionSurfaceVector.at(i + counter).setPosition(i + counter);
				tempmPosAndInteraction.push_back(mPosAndInteraction.at(i));
				tempmPosAndInteraction.at(i + counter).setPosition(i + counter);
			}

		}

		mPosAndIntersectionSurfaceVector = tempPosAndIntersectionSurfaceVector;
		mPosAndInteraction = tempmPosAndInteraction;

	}

	else // we have to set the last surface to the end
	{
		mPosAndIntersectionSurfaceVector.push_back(newSurface);
		mPosAndInteraction.push_back(newInteraction);
		mPosAndIntersectionSurfaceVector.at(position - 1).setPosition(position - 1);
		mPosAndInteraction.at(position - 1).setPosition(position - 1);
	}




}


// get number of surfaces in optical system
unsigned int OpticalSystem_LLT::getNumberOfSurfaces()
{
	return mPosAndIntersectionSurfaceVector.size() - 1;
}

// fill vector to plot optical system 2D
void OpticalSystem_LLT::fillVectorToPlot2D(unsigned int pos, SurfaceIntersectionRay_LLT* surfaceToPlot2D)
{
	PosAndInteraSurfaceToPlot2D tempPosAndSurToPlot;
	tempPosAndSurToPlot.setPosition(pos);
	tempPosAndSurToPlot.setSurfaceToPlo2D_ptr(surfaceToPlot2D);
	mPosAndSurfaceToPlot2D.push_back(tempPosAndSurToPlot);


}

// get pos and surface to plot 2D
std::vector<PosAndInteraSurfaceToPlot2D> OpticalSystem_LLT::getPosAndSurfToPlot2D()
{
	return mPosAndSurfaceToPlot2D;
}







OpticalSystem_LLT OpticalSystem_LLT::clone()
{
	std::shared_ptr<SurfaceIntersectionRay_LLT> tempSurface_ptr;
	PosAndIntsectionSurfaceStruct tempPosAndSurface;
	std::vector<PosAndIntsectionSurfaceStruct> tempSurfaceVec;

	std::shared_ptr<InteractionRay_LLT> tempInteraction_ptr;
	PosAndInteractionStruct tempPosAndInteraction;
	std::vector<PosAndInteractionStruct> tempInteractionvec;



	for (unsigned int i = 0; i < mPosAndIntersectionSurfaceVector.size(); i++)
	{
		tempSurface_ptr = mPosAndIntersectionSurfaceVector.at(i).getSurfaceInterRay_ptr()->clone();
		tempInteraction_ptr = mPosAndInteraction.at(i).getInteractionAtSur_ptr()->clone();

		tempPosAndSurface.setInteractionSurface_prt(tempSurface_ptr);
		tempPosAndSurface.setPosition(mPosAndIntersectionSurfaceVector.at(i).getPosition());

		tempPosAndInteraction.setInteractionAtSur(tempInteraction_ptr);
		tempPosAndInteraction.setPosition(mPosAndInteraction.at(i).getPosition());

		tempSurfaceVec.push_back(tempPosAndSurface);
		tempInteractionvec.push_back(tempPosAndInteraction);

	}

	OpticalSystem_LLT returnOptSys_LLT(tempSurfaceVec, tempInteractionvec);

	return returnOptSys_LLT;
}


void OpticalSystem_LLT::cleanSurfaceAndInteractionStartAt_i(unsigned int aimSize)
{
	//std::vector<PosAndIntsectionSurfaceStruct>::iterator end = mPosAndIntersectionSurfaceVector.size();
	aimSize--;
	std::vector<PosAndIntsectionSurfaceStruct>::iterator endSurface = mPosAndIntersectionSurfaceVector.end();
	std::vector<PosAndIntsectionSurfaceStruct>::iterator startSurface = mPosAndIntersectionSurfaceVector.begin();

	for (unsigned int i = 0; aimSize >= i; i++)
	{
		startSurface++;
	}
	mPosAndIntersectionSurfaceVector.erase(startSurface, endSurface);
	//mPosAndIntersectionSurfaceVector.reserve(aimSize);
	std::vector<PosAndInteractionStruct>::iterator endInterac = mPosAndInteraction.end();
	std::vector<PosAndInteractionStruct>::iterator startIntera = mPosAndInteraction.begin();


	for (unsigned int j = 0; aimSize >= j; j++)
	{
		startIntera++;
	}


	mPosAndInteraction.erase(startIntera, endInterac);
	//mPosAndInteraction.reserve(aimSize);



}



 void OpticalSystem_LLT::printAllPositions()
{
	VectorStructR3 tempPos;

	for (unsigned int i = 0; i < mPosAndIntersectionSurfaceVector.size(); ++i)
	{
		tempPos = mPosAndIntersectionSurfaceVector[i].getSurfaceInterRay_ptr()->getPoint();
		std::cout << "position surface " << i << " ";
		tempPos.print();
	}

}

void OpticalSystem_LLT::printAllRadii()
{
	real tempRadius;
	int prefix = 1;

	for (unsigned int i = 0; i < mPosAndIntersectionSurfaceVector.size(); ++i)
	{
		if (mPosAndIntersectionSurfaceVector[i].getSurfaceInterRay_ptr()->getDirection().getZ() < 0)
		{
			prefix = -1;
		}

		tempRadius = prefix * mPosAndIntersectionSurfaceVector[i].getSurfaceInterRay_ptr()->getRadius();
		std::cout << "surface num " << i << " radius: " << tempRadius << std::endl;

		prefix = 1;
	}

}

unsigned int OpticalSystem_LLT::getPosApertureStop()
{
	unsigned int sizeOfOptSys = mPosAndIntersectionSurfaceVector.size();
	std::shared_ptr<SurfaceIntersectionRay_LLT> tempSurface_ptr;  
	ApertureStop_LLT apertureStop_ptr;


	for (unsigned int i = 0; i < sizeOfOptSys; i++)
	{
		tempSurface_ptr = mPosAndIntersectionSurfaceVector[i].getSurfaceInterRay_ptr();

		if (typeid(*tempSurface_ptr) == typeid(apertureStop_ptr))
		{
			return i;
		}

	}

	std::cout << "there is no aperture stop in your optical system!!!" << std::endl;

	return 999999999;

}


void OpticalSystem_LLT::clean_optSys_LLT()
{
	mPosAndIntersectionSurfaceVector.clear();
	mPosAndInteraction.clear();
	mPosAndSurfaceToPlot2D.clear();


}

void OpticalSystem_LLT::printAllOptSysParameter_LLT(OpticalSystem_LLT optSys_LLT)
{
	unsigned int size = optSys_LLT.getPosAndInteractingSurface().size();
	std::shared_ptr<SurfaceIntersectionRay_LLT> tempSurface_ptr;
	std::shared_ptr<SurfaceIntersectionRay_LLT> tempSurface_ptr_next;

	real tempRadius;
	real tempPoint_Z;
	real tempPoint_Z_next;
	real tempDirection_Z;
	real semiHeight;
	real tempPointZ = 0;
	real thickness = 0;

	for (unsigned int i = 0; i < size; i++)
	{
		tempSurface_ptr = optSys_LLT.getPosAndInteractingSurface()[i].getSurfaceInterRay_ptr();


		// get radius
		tempRadius = tempSurface_ptr->getRadius();
		tempDirection_Z = tempSurface_ptr->getDirection().getZ();
		if (tempDirection_Z < 0)
		{
			tempRadius = -1 * tempRadius;
		}

		// get tempPoint
		if (i < size - 1)
		{
			tempSurface_ptr_next = optSys_LLT.getPosAndInteractingSurface()[i + 1].getSurfaceInterRay_ptr();
			tempPoint_Z = tempSurface_ptr->getPoint().getZ();
			tempPoint_Z_next = tempSurface_ptr_next->getPoint().getZ();
		}
		else
		{
			tempPoint_Z = 99.0;
			tempPoint_Z_next = 99.0;
		}

		thickness = tempPoint_Z_next - tempPoint_Z;

		// get semiHeight
		semiHeight = tempSurface_ptr->getSemiHeight();

		std::cout << "surface: " << i << "   radius: " << tempRadius << "   thickness: " << thickness << "   semi height: " << semiHeight << std::endl;

	}
}

infosAS OpticalSystem_LLT::getInforAS()
{

	infosAS returnInfosAS;

	unsigned int posAS = getPosApertureStop();
	returnInfosAS.setPosAS(posAS);
	real semiHeightAS = mPosAndIntersectionSurfaceVector[posAS].getSurfaceInterRay_ptr()->getSemiHeight();
	returnInfosAS.setSemiHeightAS(semiHeightAS);
	VectorStructR3 pointAS = mPosAndIntersectionSurfaceVector[posAS].getSurfaceInterRay_ptr()->getPoint();
	returnInfosAS.setPointAS(pointAS);
	VectorStructR3 directionAS = mPosAndIntersectionSurfaceVector[posAS].getSurfaceInterRay_ptr()->getDirection();
	returnInfosAS.setDirAS(directionAS);

	return returnInfosAS;

}

void OpticalSystem_LLT::setInteractionOfSurface_i(unsigned int surfaceNumber, std::shared_ptr<InteractionRay_LLT> interactinSurface)
{
	mPosAndInteraction[surfaceNumber].setInteractionAtSur(interactinSurface);
}