#pragma once
#include <vector>
#include "SurfaceIntersectionRay_LLT.h"
#include "Interaction\InteractionRay_LLT.h"
#include "..\Plot\Plot.h"
#include <qwt_plot.h>
#include <qwt_plot_curve.h>
#include "..\Analyse\Spot.h"


struct infosAS
{
public:

	// pos AS
	unsigned int getPosAS();
	void setPosAS(unsigned int posAS);
	// semiHeight AS
	real getSemiHeightAS();
	void setSemiHeightAS(real semiHeightAS);
	// point AS
	VectorStructR3 getPointAS();
	void setPointAS(VectorStructR3 pointAS);
	// direction
	VectorStructR3 getDirAS();
	void setDirAS(VectorStructR3 dirAS);


private:
	unsigned mPosAS;
	real mSemiHeightAS;
	VectorStructR3 mPointAS;
	VectorStructR3 mDirectionAS;
};





struct PosAndInteractionStruct
{
	PosAndInteractionStruct();
	PosAndInteractionStruct(int pos, std::shared_ptr<InteractionRay_LLT> intact);
	~PosAndInteractionStruct();
	   
	// set position
	void setPosition(unsigned int const pos);
	// get position
	unsigned int getPosition() const;

	// set interaction at surface
	void setInteractionAtSur(std::shared_ptr<InteractionRay_LLT> setInteractionRay_LLT);
	// get interaction at surface
	std::shared_ptr<InteractionRay_LLT> getInteractionAtSur_ptr() const;

public:
	int mPosition;
	std::shared_ptr<InteractionRay_LLT> mInteraction;

};

struct PosAndIntsectionSurfaceStruct
{
	PosAndIntsectionSurfaceStruct();
	PosAndIntsectionSurfaceStruct(unsigned int const pos, std::shared_ptr<SurfaceIntersectionRay_LLT> interactinSur);
	PosAndIntsectionSurfaceStruct clone();
	~PosAndIntsectionSurfaceStruct();
	
	// set position
	void setPosition(unsigned int const pos);
	// get position
	unsigned int getPosition() const;

	// set interacting surface
	void setInteractionSurface_prt(std::shared_ptr<SurfaceIntersectionRay_LLT> setSurInterRay_LLT_ptr);
	// get interaction surface
	std::shared_ptr<SurfaceIntersectionRay_LLT> getSurfaceInterRay_ptr() const;

	

public:
	int mPosition;
	std::shared_ptr<SurfaceIntersectionRay_LLT> mInteractinSurface;

};

struct PosAndInteraSurfaceToPlot2D
{
	PosAndInteraSurfaceToPlot2D();
	PosAndInteraSurfaceToPlot2D(int pos, SurfaceIntersectionRay_LLT* surfaceToPlot2D_ptr);
	~PosAndInteraSurfaceToPlot2D();

	// set position
	void setPosition(unsigned int const pos);
	// get position
	unsigned int getPosition() const;

	// set surface to plot 2D
	void setSurfaceToPlo2D_ptr(SurfaceIntersectionRay_LLT* setSurfaceToPlot2D);
	// get surface to plot 2D
	SurfaceIntersectionRay_LLT* getSurfaceToPlot2D_ptr() const;

public:
	int mPosition;
	SurfaceIntersectionRay_LLT* mPlotSur_ptr;

};



class OpticalSystem_LLT
{
public:
	OpticalSystem_LLT();
	OpticalSystem_LLT(std::vector<PosAndIntsectionSurfaceStruct> posAndIntersecSur, std::vector<PosAndInteractionStruct> posAndInteraction);
	OpticalSystem_LLT(std::vector<std::shared_ptr<SurfaceIntersectionRay_LLT>> interactinSurface, std::vector<std::shared_ptr<InteractionRay_LLT>> interaction);
	~OpticalSystem_LLT();

	// fill vector with surface and interacting datas
	void fillVectorSurfaceAndInteractingData(int position, std::shared_ptr<SurfaceIntersectionRay_LLT> interactinSurface, std::shared_ptr<InteractionRay_LLT> interaction);
	void fillVectorSurfaceAndInteractingData(int position, SurfaceIntersectionRay_LLT* interactinSurface, std::shared_ptr<InteractionRay_LLT> interaction); // better is the function above with shared pointes

	// fill optical system with surfaces and interaction
	void fillOptSysWithSurfaceAndInteractions(std::vector< std::shared_ptr<SurfaceIntersectionRay_LLT>> surface_vec, std::vector< std::shared_ptr<InteractionRay_LLT>> interaction_vec);

	// fill the vector with surfaces
	void fillTracingVectorSurfaces(int position, std::shared_ptr<SurfaceIntersectionRay_LLT> interactinSurface);

	// fill the vector with interacions
	void fillTracingVectorInteraction(int position, std::shared_ptr<InteractionRay_LLT> interaction);


	// get position and interaction
	std::vector<PosAndInteractionStruct> getPosAndInteraction();

	// fill in surface at position i
	void fillInSurfaceAndInteracAtPos_i(unsigned int const position, std::shared_ptr<SurfaceIntersectionRay_LLT> interactinSurface, std::shared_ptr<InteractionRay_LLT> interaction);

	// get number of surfaces in optical system
	unsigned int getNumberOfSurfaces();

	// fill vector to plot optical system 2D
	void fillVectorToPlot2D(unsigned int pos, SurfaceIntersectionRay_LLT* surfaceToPlot2D);

	// get pos and surface to plot 2D
	std::vector<PosAndInteraSurfaceToPlot2D> getPosAndSurfToPlot2D();


	// fill vector to plot optical system 2D using Qwt
	void fillVectorToPlot2DQwt(unsigned int pos, QwtPlotCurve *curve);


	// get vector with position and interaction surface
	std::vector<PosAndIntsectionSurfaceStruct> getPosAndInteractingSurface();


	//get the max scale of Spot diagrams
	double getMinSpotDiagrammScale();

	OpticalSystem_LLT clone();

	void cleanSurfaceAndInteractionStartAt_i(unsigned int aimSize);

	void setInteractionOfSurface_i(unsigned int surfaceNumber, std::shared_ptr<InteractionRay_LLT> interactinSurface);

	void printAllPositions();
	void printAllRadii();
	void printAllOptSysParameter_LLT(OpticalSystem_LLT optSys_LLT);

	unsigned int getPosApertureStop();
	void clean_optSys_LLT();

	infosAS getInforAS();

private:
	std::vector<PosAndIntsectionSurfaceStruct> mPosAndIntersectionSurfaceVector;
	std::vector<PosAndInteractionStruct> mPosAndInteraction;
	std::vector<PosAndInteraSurfaceToPlot2D> mPosAndSurfaceToPlot2D;
	int CurveCounter = 0;
};