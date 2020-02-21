#pragma once
#include <vector>
#include "SurfaceIntersectionRay_LLT.h"
#include "Interaction\InteractionRay_LLT.h"
#include "..\Plot\Plot.h"
#include <qwt_plot.h>
#include <qwt_plot_curve.h>
#include "..\Plot\PlotSpotDiagram.h"

struct CommentandPosCommentToPlotInRayTracing
{
	CommentandPosCommentToPlotInRayTracing() {};
	~CommentandPosCommentToPlotInRayTracing() {};
	CommentandPosCommentToPlotInRayTracing(QString Comment, VectorStructR2 PositionComment)
	{
		mComment = Comment;
		mPositionComment = PositionComment;
	}
	QString mComment;
	VectorStructR2 mPositionComment;

	//set Image name
	void setComment(QString Comment);
	//get Image name
	QString getComment();
	// set PlotSpot Diagramm
	void setPositionComment(VectorStructR2 PositionComment);
	//get Plot Spot Diagramm
	VectorStructR2 getPositionComment();

};



struct TitelandPlotSpotDiagramToPlot
{
	TitelandPlotSpotDiagramToPlot() {};
	~TitelandPlotSpotDiagramToPlot() {};
	TitelandPlotSpotDiagramToPlot(std::string imageName, PlotSpotDiagramm* plotSpot)
	{
		mimageName = imageName;
		mplotSpot = plotSpot;
	}
	std::string mimageName;
	PlotSpotDiagramm* mplotSpot;

	//set Image name
	void setImageName(std::string imageName);
	//get Image name
	std::string getImageName();
	// set PlotSpot Diagramm
	void setPlotSpotDiagramm(PlotSpotDiagramm* plotSpot);
	//get Plot Spot Diagramm
	PlotSpotDiagramm* getPlotSpotDiagramm();
};


struct PosAndCurveStructToPlot
{
	PosAndCurveStructToPlot() {};
	PosAndCurveStructToPlot(int pos, QwtPlotCurve *curve)
	{
		position = pos;
		Qwtcurve = curve;
	}
	~PosAndCurveStructToPlot() {};

	int position;
	QwtPlotCurve *Qwtcurve = new QwtPlotCurve();

	// set position
	void setPosition(unsigned int const& pos);
	// get position
	unsigned int getPosition() const&;

	// set interaction at surface
	void setCurve(QwtPlotCurve* const& curve);
	// get interaction at surface
	QwtPlotCurve* getCurve() const&;

};

struct PosAndInteractionStruct
{
	PosAndInteractionStruct();
	PosAndInteractionStruct(int pos, std::shared_ptr<InteractionRay_LLT> intact);
	~PosAndInteractionStruct();
	   
	// set position
	void setPosition(unsigned int const& pos);
	// get position
	unsigned int getPosition() const&;

	// set interaction at surface
	void setInteractionAtSur(std::shared_ptr<InteractionRay_LLT> setInteractionRay_LLT);
	// get interaction at surface
	std::shared_ptr<InteractionRay_LLT> getInteractionAtSur_ptr() const&;

public:
	int mPosition;
	std::shared_ptr<InteractionRay_LLT> mInteraction;

};

struct PosAndIntsectionSurfaceStruct
{
	PosAndIntsectionSurfaceStruct();
	PosAndIntsectionSurfaceStruct(unsigned int const& pos, std::shared_ptr<SurfaceIntersectionRay_LLT> interactinSur);
	~PosAndIntsectionSurfaceStruct();
	
	// set position
	void setPosition(unsigned int const& pos);
	// get position
	unsigned int getPosition() const&;

	// set interacting surface
	void setInteractionSurface_prt(std::shared_ptr<SurfaceIntersectionRay_LLT> setSurInterRay_LLT_ptr);
	// get interaction surface
	std::shared_ptr<SurfaceIntersectionRay_LLT> getSurfaceInterRay_ptr() const&;

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
	void setPosition(unsigned int const& pos);
	// get position
	unsigned int getPosition() const&;

	// set surface to plot 2D
	void setSurfaceToPlo2D_ptr(SurfaceIntersectionRay_LLT* setSurfaceToPlot2D);
	// get surface to plot 2D
	SurfaceIntersectionRay_LLT* getSurfaceToPlot2D_ptr() const&;

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

	// fill the vector with surfaces
	void fillTracingVectorSurfaces(int position, std::shared_ptr<SurfaceIntersectionRay_LLT> interactinSurface);

	// fill the vector with interacions
	void fillTracingVectorInteraction(int position, std::shared_ptr<InteractionRay_LLT> interaction);


	// get position and interaction
	std::vector<PosAndInteractionStruct> getPosAndInteraction();

	// fill in surface at position i
	void fillInSurfaceAndInteracAtPos_i(unsigned int const& position, std::shared_ptr<SurfaceIntersectionRay_LLT> interactinSurface, std::shared_ptr<InteractionRay_LLT> interaction);

	// get number of surfaces in optical system
	unsigned int getNumberOfSurfaces();

	// fill vector to plot optical system 2D
	void fillVectorToPlot2D(unsigned int pos, SurfaceIntersectionRay_LLT* surfaceToPlot2D);

	// get pos and surface to plot 2D
	std::vector<PosAndInteraSurfaceToPlot2D> getPosAndSurfToPlot2D();


	// fill vector to plot optical system 2D using Qwt
	void fillVectorToPlot2DQwt(unsigned int pos, QwtPlotCurve *curve);

	// get pos and surface to plot 2D Qwt
	std::vector<PosAndCurveStructToPlot> getPosAndCurveToPlot2DQwt();

	// get the vector with Spotdiagrams
	std::vector <TitelandPlotSpotDiagramToPlot> getVectorSpotDiagramToPlot();

	// get vector with position and interaction surface
	std::vector<PosAndIntsectionSurfaceStruct> getPosAndInteractingSurface();

	// fill the vector with Spotdiagrams
	void fillVectorSpotDiagramToPlot(std::string imageName, PlotSpotDiagramm* plotSpot);

	//get the max scale of Spot diagrams
	double getMinSpotDiagrammScale();

	OpticalSystem_LLT clone();

	void cleanSurfaceAndInteractionStartAt_i(unsigned int aimSize);

	

	void printAllPositions();
	void printAllRadii();
	void printAllOptSysParameter_LLT(OpticalSystem_LLT optSys_LLT);

	unsigned int getPosApertureStop();
	void clean_optSys_LLT();

private:
	std::vector<PosAndIntsectionSurfaceStruct> mPosAndIntersectionSurfaceVector;
	std::vector<PosAndInteractionStruct> mPosAndInteraction;
	std::vector<PosAndInteraSurfaceToPlot2D> mPosAndSurfaceToPlot2D;

	std::vector<PosAndCurveStructToPlot> mPosAndCurveVector;
	std::vector<TitelandPlotSpotDiagramToPlot> mtitelandSpotDiagramToPlot;
	
	std::vector<CommentandPosCommentToPlotInRayTracing> mCommentandPosCommentToRayTracingPlot;
	std::vector<CommentandPosCommentToPlotInRayTracing> mCommentandPosCommentToSpotDiagramPlot;

	int CurveCounter = 0;
};