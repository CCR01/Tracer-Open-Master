#pragma once

#include "OpticalSystem_LLT.h"
#include <qwt_plot.h>
#include <qwt_plot_curve.h>
#include "Surfaces/ApertureStop_LLT.h"

void TitelandPlotSpotDiagramToPlot::setImageName(std::string imageName)
{
	mimageName = imageName;
}



void TitelandPlotSpotDiagramToPlot::setPlotSpotDiagramm(PlotSpotDiagramm* plotSpot)
{
	mplotSpot = plotSpot;
};


PlotSpotDiagramm* TitelandPlotSpotDiagramToPlot::getPlotSpotDiagramm()
{
	return mplotSpot;
}

void PosAndCurveStructToPlot::setPosition(unsigned int const& pos)
{
	position = pos;
}

// get position
unsigned int PosAndCurveStructToPlot::getPosition() const&
{
	return position;
}

// set interacting surface
void PosAndCurveStructToPlot::setCurve(QwtPlotCurve * curve)
{
	interaction = curve;
}


// get interaction surface
QwtPlotCurve*  PosAndCurveStructToPlot::getCurve() const&
{
	return interaction;
};

PosAndIntsectionSurfaceStruct::PosAndIntsectionSurfaceStruct() {};
PosAndIntsectionSurfaceStruct::PosAndIntsectionSurfaceStruct(unsigned int const& pos, std::shared_ptr<SurfaceIntersectionRay_LLT> interactinSur) :
	mPosition(pos),
	mInteractinSurface(interactinSur)
{}
PosAndIntsectionSurfaceStruct::~PosAndIntsectionSurfaceStruct()
{
	//delete mInteractinSurface;
};


// set position
void PosAndIntsectionSurfaceStruct::setPosition(unsigned int const& pos)
{
	mPosition = pos;
}

// get position
unsigned int PosAndIntsectionSurfaceStruct::getPosition() const&
{
	return mPosition;
}



// set interacting surface
void PosAndIntsectionSurfaceStruct::setInteractionSurface_prt(std::shared_ptr<SurfaceIntersectionRay_LLT> setSurInterRay_LLT_ptr)
{
	mInteractinSurface = setSurInterRay_LLT_ptr;
}


// get interaction surface
std::shared_ptr<SurfaceIntersectionRay_LLT> PosAndIntsectionSurfaceStruct::getSurfaceInterRay_ptr() const&
{
	return mInteractinSurface;
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
void PosAndInteractionStruct::setPosition(unsigned int const& pos)
{
	mPosition = pos;
}
// get position
unsigned int PosAndInteractionStruct::getPosition() const&
{
	return mPosition;
}

// set interaction at surface
void PosAndInteractionStruct::setInteractionAtSur(std::shared_ptr<InteractionRay_LLT> setInteractionRay_LLT_ptr)
{
	mInteraction = setInteractionRay_LLT_ptr;
}
// get interaction at surface
std::shared_ptr<InteractionRay_LLT> PosAndInteractionStruct::getInteractionAtSur_ptr() const&
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
void PosAndInteraSurfaceToPlot2D::setPosition(unsigned int const& pos)
{
	mPosition = pos;
}

// get position
unsigned int PosAndInteraSurfaceToPlot2D::getPosition() const&
{
	return mPosition;
}

// set surface to plot 2D
void PosAndInteraSurfaceToPlot2D::setSurfaceToPlo2D_ptr(SurfaceIntersectionRay_LLT* setSurfaceToPlot2D)
{
	mPlotSur_ptr = setSurfaceToPlot2D;
}

// get surface to plot 2D
SurfaceIntersectionRay_LLT* PosAndInteraSurfaceToPlot2D::getSurfaceToPlot2D_ptr() const&
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
void OpticalSystem_LLT::fillInSurfaceAndInteracAtPos_i(unsigned int const& position, std::shared_ptr<SurfaceIntersectionRay_LLT> interactinSurface, std::shared_ptr<InteractionRay_LLT> interaction)
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






void OpticalSystem_LLT::fillVectorToPlot2DQwt(unsigned int pos, QwtPlotCurve* curve)
{
	PosAndCurveStructToPlot tempPosAndSurToPlot;
	tempPosAndSurToPlot.setPosition(pos);
	tempPosAndSurToPlot.setCurve(curve);
	mPosAndCurveVector.push_back(tempPosAndSurToPlot);
	CurveCounter++;
}




// get pos and surface to plot 2D qwt

std::vector<PosAndCurveStructToPlot> OpticalSystem_LLT::getPosAndCurveToPlot2DQwt()
{
	return mPosAndCurveVector;
}


void OpticalSystem_LLT::fillVectorSpotDiagramToPlot(std::string imageName, PlotSpotDiagramm* plotSpot)
{
	TitelandPlotSpotDiagramToPlot titelandSpotDiagramToPlot;
	titelandSpotDiagramToPlot.setImageName(imageName);
	titelandSpotDiagramToPlot.setPlotSpotDiagramm(plotSpot);
	mtitelandSpotDiagramToPlot.push_back(titelandSpotDiagramToPlot);
}

std::vector < TitelandPlotSpotDiagramToPlot> OpticalSystem_LLT::getVectorSpotDiagramToPlot()
{
	return mtitelandSpotDiagramToPlot;
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

void CommentandPosCommentToPlotInRayTracing::setComment(QString Comment)
{
	mComment = Comment;
}
//get Image name
QString CommentandPosCommentToPlotInRayTracing::getComment()
{
	return mComment;
}
// set PlotSpot Diagramm
void CommentandPosCommentToPlotInRayTracing::setPositionComment(VectorStructR2 PositionComment)
{
	mPositionComment = PositionComment;
}
//get Plot Spot Diagramm
VectorStructR2 CommentandPosCommentToPlotInRayTracing::getPositionComment()
{
	return mPositionComment;
}


std::string TitelandPlotSpotDiagramToPlot::getImageName()
{
	return mimageName;
}



//load parameters of QwtPlot
QColor OpticalSystem_LLT::getColorSurfaces()
{
	return mColorSurfaces;
}


double OpticalSystem_LLT::getThicknessSurfaces()
{
	return mThicknessSurfaces;
}

void OpticalSystem_LLT::setColorSurfaces(QColor color)
{
	mColorSurfaces = color;

}

void OpticalSystem_LLT::setThicknessSurfaces(double thickness)
{
	mThicknessSurfaces = thickness;
}

void OpticalSystem_LLT::AddCommentToRayTracingPlot(QString comment, VectorStructR2 position)
{
	CommentandPosCommentToPlotInRayTracing CommentInfo;
	CommentInfo.setComment(comment);
	CommentInfo.setPositionComment(position);
	mCommentandPosCommentToRayTracingPlot.push_back(CommentInfo);
}

std::vector<CommentandPosCommentToPlotInRayTracing> OpticalSystem_LLT::getVectorCommentsRayTracingPlot()
{
	return mCommentandPosCommentToRayTracingPlot;
}

void OpticalSystem_LLT::AddCommentToSpotDiagramPlot(QString comment, VectorStructR2 position)
{
	CommentandPosCommentToPlotInRayTracing CommentInfo;
	CommentInfo.setComment(comment);
	CommentInfo.setPositionComment(position);
	mCommentandPosCommentToSpotDiagramPlot.push_back(CommentInfo);
}

std::vector<CommentandPosCommentToPlotInRayTracing> OpticalSystem_LLT::getVectorCommentsSpotDiagramPlot()
{
	return mCommentandPosCommentToSpotDiagramPlot;
}

void OpticalSystem_LLT::setAiryDiskColor(QColor AiryDiskColor)
{
	mAiryDiskColor = AiryDiskColor;
}

QColor OpticalSystem_LLT::getAiryDiskColor()
{
	return mAiryDiskColor;
}

void OpticalSystem_LLT::setAiryDiskThickness(int AiryDiskThickness)
{
	mAiryDiskThickness = AiryDiskThickness;
}

int OpticalSystem_LLT::getAiryDiskThickness()
{
	return mAiryDiskThickness;
}

void OpticalSystem_LLT::setSymbolColorOfSpotDiagrammPoints(QBrush SymbolColor)
{
	mSymbolColorSpotDiagram = SymbolColor;
}
QBrush OpticalSystem_LLT::getSymbolColorOfSpotDiagrammPoints()
{
	return mSymbolColorSpotDiagram;
}
void OpticalSystem_LLT::setSymbolStyleOfSpotDiagrammPoints(QwtSymbol::Style SymbolStyle)
{
	mSymbolStyleSpotDiagram = SymbolStyle;
}
QwtSymbol::Style OpticalSystem_LLT::getSymbolStyleOfSpotDiagrammPoints()
{
	return mSymbolStyleSpotDiagram;
}
void OpticalSystem_LLT::setContourColorSymbolOfSpotDiagrammPoints(QPen SymbolPen)
{
	mSymbolPenSpotDiagram = SymbolPen;
}
QPen OpticalSystem_LLT::getContourColorSymbolOfSpotDiagrammPoints()
{
	return mSymbolPenSpotDiagram;
}
void OpticalSystem_LLT::setSizeSymbolOfSpotDiagrammPoints(QSize SymbolSize)
{
	mSymbolSizeSpotDiagram = SymbolSize;
}
QSize OpticalSystem_LLT::getSizeSymbolOfSpotDiagrammPoints()
{
	return mSymbolSizeSpotDiagram;
}

void OpticalSystem_LLT::setFrameColorOfSpotDiagrammPoints(QPen ColorOfTheFrame)
{
	mColorOfTheFrameSpotDiagram = ColorOfTheFrame;
}
QPen OpticalSystem_LLT::getFrameColorOfSpotDiagrammPoints()
{
	return mColorOfTheFrameSpotDiagram;
}

double OpticalSystem_LLT::getMinSpotDiagrammScale()
{
	double maxScale = mtitelandSpotDiagramToPlot.at(0).getPlotSpotDiagramm()->calculateScaleSpotDia();

	for (unsigned int i = 0; i < mtitelandSpotDiagramToPlot.size(); i++)
	{
		if (mtitelandSpotDiagramToPlot.at(i).getPlotSpotDiagramm()->calculateScaleSpotDia() > maxScale)
		{
			maxScale = mtitelandSpotDiagramToPlot.at(i).getPlotSpotDiagramm()->calculateScaleSpotDia();
		}
	}

	return maxScale;
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

	mPosAndCurveVector.clear();
	mtitelandSpotDiagramToPlot.clear();

	mCommentandPosCommentToRayTracingPlot.clear();
	mCommentandPosCommentToSpotDiagramPlot.clear();


}

/*Peter*/ void OpticalSystem_LLT::printAllOptSysParameter_LLT(OpticalSystem_LLT optSys_LLT)
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