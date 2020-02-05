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
		interaction = curve;
	}
	~PosAndCurveStructToPlot() {};

	int position;
	QwtPlotCurve *interaction = new QwtPlotCurve();

	// set position
	void setPosition(unsigned int const& pos);
	// get position
	unsigned int getPosition() const&;

	// set interaction at surface
	void setCurve(QwtPlotCurve* curve);
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

	//**load parameters of QwtPlot:
//*********************************RayTracing
//get the color of the surfaces in the optical system
	QColor getColorSurfaces();
	//get the thickness of the line of the plotted surfaces 
	double getThicknessSurfaces();
	//change the color of the surfaces to be plotted
	void setColorSurfaces(QColor color);
	//change the thickness of the surfaces to be plotted
	void setThicknessSurfaces(double thickness);
	//add a comment information to the vector of comments to be plotted on the Ray tracing plot
	void AddCommentToRayTracingPlot(QString comment, VectorStructR2 position);
	//return the vector containing the comments to be added to the plot of ray tracing
	std::vector<CommentandPosCommentToPlotInRayTracing> getVectorCommentsRayTracingPlot();
	//***********************************Spot Diagram
	//add a comment information to the vector of the spot diagramm to be plotted
	void AddCommentToSpotDiagramPlot(QString comment, VectorStructR2 position);
	//return the vector containing the comments to be added on the spot diagram
	std::vector<CommentandPosCommentToPlotInRayTracing> getVectorCommentsSpotDiagramPlot();
	//change the color of the airy disk on the spot diagram
	void setAiryDiskColor(QColor AiryDiskColor);
	//get the color of the airydisk curve of the spot diagram
	QColor getAiryDiskColor();
	//change the thickness of the curve of the airydisc
	void setAiryDiskThickness(int AiryDiskThickness);
	//get the thickness of the airydisc curve
	int getAiryDiskThickness();
	//change the color of the Spot Diagram plot
	void setSymbolColorOfSpotDiagrammPoints(QBrush SymbolColor);
	//get the color of the spot diagram plot
	QBrush getSymbolColorOfSpotDiagrammPoints();
	//change the shape of the Spot diagram plot points
	void setSymbolStyleOfSpotDiagrammPoints(QwtSymbol::Style SymbolStyle);
	//get the shape of the Spot diagram plot points
	QwtSymbol::Style getSymbolStyleOfSpotDiagrammPoints();
	//change the color of the contour of the symbol of the spot diagram spots
	void setContourColorSymbolOfSpotDiagrammPoints(QPen SymbolPen);
	//get the color of the contour of the symbol of the spot diagram spots
	QPen getContourColorSymbolOfSpotDiagrammPoints();
	//change the size of the spot diagram curve points
	void setSizeSymbolOfSpotDiagrammPoints(QSize SymbolSize);
	//get the size of the spot diagram curve points
	QSize getSizeSymbolOfSpotDiagrammPoints();
	//change the color of the frame of the spot diagramms
	void setFrameColorOfSpotDiagrammPoints(QPen ColorOfTheFrame);
	//get the color of the frame of the spot diagramms
	QPen getFrameColorOfSpotDiagrammPoints();

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

	QColor mColorSurfaces = { 255,0,0 };
	double mThicknessSurfaces = 2;
	QString mAddedComment;
	VectorStructR2 PositionOfAddedComment;
	QColor mAiryDiskColor = QColor("black");
	int mAiryDiskThickness = 1;
	QBrush mSymbolColorSpotDiagram = QBrush(Qt::blue);
	QwtSymbol::Style mSymbolStyleSpotDiagram = QwtSymbol::Ellipse;
	QPen mSymbolPenSpotDiagram = QPen(Qt::blue, 1);
	QSize mSymbolSizeSpotDiagram = QSize(2, 2);
	QPen mColorOfTheFrameSpotDiagram = QColor("lightGrey");

};