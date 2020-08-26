#include "PlotParameterQwt.h"

void CommentandPosCommentToPlot::setComment(QString Comment)
{
	mComment = Comment;
}

//get Image name
QString CommentandPosCommentToPlot::getComment()
{
	return mComment;
}
// set PlotSpot Diagramm
void CommentandPosCommentToPlot::setPositionComment(VectorStructR2 PositionComment)
{
	mPositionComment = PositionComment;
}
//get Plot Spot Diagramm
VectorStructR2 CommentandPosCommentToPlot::getPositionComment()
{
	return mPositionComment;
}


//load parameters of QwtPlot
QColor PlotParameterQwt::getColorSurfaces()
{
	return mColorSurfaces;
}


double PlotParameterQwt::getThicknessSurfaces()
{
	return mThicknessSurfaces;
}

void PlotParameterQwt::setColorSurfaces(QColor color)
{
	mColorSurfaces = color;
}

void PlotParameterQwt::setThicknessSurfaces(double thickness)
{
	mThicknessSurfaces = thickness;
}

void PlotParameterQwt::AddCommentToRayTracingPlot(QString comment, VectorStructR2 position)
{
	CommentandPosCommentToPlot CommentInfo;
	CommentInfo.setComment(comment);
	CommentInfo.setPositionComment(position);
	mCommentandPosCommentToRayTracingPlot.push_back(CommentInfo);
}

std::vector<CommentandPosCommentToPlot> PlotParameterQwt::getVectorCommentsRayTracingPlot()
{
	return mCommentandPosCommentToRayTracingPlot;
}

void PlotParameterQwt::AddCommentToSpotDiagramPlot(QString comment, VectorStructR2 position)
{
	CommentandPosCommentToPlot CommentInfo;
	CommentInfo.setComment(comment);
	CommentInfo.setPositionComment(position);
	mCommentandPosCommentToSpotDiagramPlot.push_back(CommentInfo);
}

std::vector<CommentandPosCommentToPlot> PlotParameterQwt::getVectorCommentsSpotDiagramPlot()
{
	return mCommentandPosCommentToSpotDiagramPlot;
}

void PlotParameterQwt::setAiryDiskColor(QColor AiryDiskColor)
{
	mAiryDiskColor = AiryDiskColor;
}

QColor PlotParameterQwt::getAiryDiskColor()
{
	return mAiryDiskColor;
}

void PlotParameterQwt::setAiryDiskThickness(int AiryDiskThickness)
{
	mAiryDiskThickness = AiryDiskThickness;
}

int PlotParameterQwt::getAiryDiskThickness()
{
	return mAiryDiskThickness;
}

void PlotParameterQwt::setSymbolColorOfSpotDiagrammPoints(QBrush SymbolColor)
{
	mSymbolColorSpotDiagram = SymbolColor;
}
QBrush PlotParameterQwt::getSymbolColorOfSpotDiagrammPoints()
{
	return mSymbolColorSpotDiagram;
}
void PlotParameterQwt::setSymbolStyleOfSpotDiagrammPoints(QwtSymbol::Style SymbolStyle)
{
	mSymbolStyleSpotDiagram = SymbolStyle;
}
QwtSymbol::Style PlotParameterQwt::getSymbolStyleOfSpotDiagrammPoints()
{
	return mSymbolStyleSpotDiagram;
}
void PlotParameterQwt::setContourColorSymbolOfSpotDiagrammPoints(QPen SymbolPen)
{
	mSymbolPenSpotDiagram = SymbolPen;
}
QPen PlotParameterQwt::getContourColorSymbolOfSpotDiagrammPoints()
{
	return mSymbolPenSpotDiagram;
}
void PlotParameterQwt::setSizeSymbolOfSpotDiagrammPoints(QSize SymbolSize)
{
	mSymbolSizeSpotDiagram = SymbolSize;
}
QSize PlotParameterQwt::getSizeSymbolOfSpotDiagrammPoints()
{
	return mSymbolSizeSpotDiagram;
}

void PlotParameterQwt::setFrameColorOfSpotDiagrammPoints(QPen ColorOfTheFrame)
{
	mColorOfTheFrameSpotDiagram = ColorOfTheFrame;
}
QPen PlotParameterQwt::getFrameColorOfSpotDiagrammPoints()
{
	return mColorOfTheFrameSpotDiagram;
}



void PlotParameterQwt::AddCommentToOPDPlot(QString comment, VectorStructR2 position)
{
	CommentandPosCommentToPlot CommentInfo;
	CommentInfo.setComment(comment);
	CommentInfo.setPositionComment(position);
	mCommentandPosCommentToOPDPlot.push_back(CommentInfo);
}

std::vector<CommentandPosCommentToPlot> PlotParameterQwt::getOPDVectorComments()
{
	return mCommentandPosCommentToOPDPlot;
}

void PlotParameterQwt::setOPDSymbolColor(QBrush SymbolColor)
{
	mSymbolColorOPD = SymbolColor;
}
QBrush PlotParameterQwt::getOPDSymbolColor()
{
	return mSymbolColorOPD;
}
void PlotParameterQwt::setOPDSymbolStyle(QwtSymbol::Style SymbolStyle)
{
	mSymbolStyleOPD = SymbolStyle;
}
QwtSymbol::Style PlotParameterQwt::getOPDSymbolStyle()
{
	return mSymbolStyleOPD;
}
void PlotParameterQwt::setOPDContourColorSymbol(QPen SymbolPen)
{
	mSymbolPenOPD = SymbolPen;
}
QPen PlotParameterQwt::getOPDContourColorSymbol()
{
	return mSymbolPenOPD;
}
void PlotParameterQwt::setOPDSizeSymbol(QSize SymbolSize)
{
	mSymbolSizeOPD = SymbolSize;
}
QSize PlotParameterQwt::getOPDSizeSymbol()
{
	return mSymbolSizeOPD;
}

void PlotParameterQwt::setOPDFrameColor(QPen ColorOfTheFrame)
{
	mColorOfTheFrameOPD = ColorOfTheFrame;
}
QPen PlotParameterQwt::getOPDFrameColor()
{
	return mColorOfTheFrameOPD;
}


void PlotParameterQwt::AddCommentToRayFanPlot(QString comment, VectorStructR2 position)
{
	CommentandPosCommentToPlot CommentInfo;
	CommentInfo.setComment(comment);
	CommentInfo.setPositionComment(position);
	mCommentandPosCommentToRayFanPlot.push_back(CommentInfo);
}

std::vector<CommentandPosCommentToPlot> PlotParameterQwt::getRayFanVectorComments()
{
	return mCommentandPosCommentToRayFanPlot;
}

void PlotParameterQwt::setRayFanSymbolColor(QBrush SymbolColor)
{
	mSymbolColorRayFan = SymbolColor;
}
QBrush PlotParameterQwt::getRayFanSymbolColor()
{
	return mSymbolColorRayFan;
}
void PlotParameterQwt::setRayFanSymbolStyle(QwtSymbol::Style SymbolStyle)
{
	mSymbolStyleRayFan = SymbolStyle;
}
QwtSymbol::Style PlotParameterQwt::getRayFanSymbolStyle()
{
	return mSymbolStyleRayFan;
}
void PlotParameterQwt::setRayFanContourColorSymbol(QPen SymbolPen)
{
	mSymbolPenRayFan = SymbolPen;
}
QPen PlotParameterQwt::getRayFanContourColorSymbol()
{
	return mSymbolPenRayFan;
}
void PlotParameterQwt::setRayFanSizeSymbol(QSize SymbolSize)
{
	mSymbolSizeRayFan = SymbolSize;
}
QSize PlotParameterQwt::getRayFanSizeSymbol()
{
	return mSymbolSizeRayFan;
}

void PlotParameterQwt::setRayFanFrameColor(QPen ColorOfTheFrame)
{
	mColorOfTheFrameRayFan = ColorOfTheFrame;
}
QPen PlotParameterQwt::getRayFanFrameColor()
{
	return mColorOfTheFrameRayFan;
}
