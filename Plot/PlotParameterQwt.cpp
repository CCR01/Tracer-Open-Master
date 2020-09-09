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

void PlotParameterQwt::setSymbolColorOfSpotDiagrammPoints(QBrush SymbolColor, int WavelengthNumber)
{
	mSymbolColorSpotDiagramVector[WavelengthNumber - 1] = SymbolColor;
}
QBrush PlotParameterQwt::getSymbolColorOfSpotDiagrammPoints(int Wavelengthnumber)
{
	return mSymbolColorSpotDiagramVector[Wavelengthnumber - 1];
}
void PlotParameterQwt::setSymbolStyleOfSpotDiagrammPoints(QwtSymbol::Style SymbolStyle, int Wavelengthnumber)
{
	mSymbolStyleSpotDiagramVector[Wavelengthnumber - 1] = SymbolStyle;
}
QwtSymbol::Style PlotParameterQwt::getSymbolStyleOfSpotDiagrammPoints(int Wavelengthnumber)
{
	return mSymbolStyleSpotDiagramVector[Wavelengthnumber - 1];
}
void PlotParameterQwt::setContourColorSymbolOfSpotDiagrammPoints(QPen SymbolPen, int numberOfWavelength)
{
	mSymbolPenSpotDiagramVector[numberOfWavelength - 1] = SymbolPen;
}
QPen PlotParameterQwt::getContourColorSymbolOfSpotDiagrammPoints(int numberOfWavelength)
{
	return mSymbolPenSpotDiagramVector[numberOfWavelength - 1];
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

void PlotParameterQwt::setOPDSymbolColor(QBrush SymbolColor, int Wavelengthnumber)
{
	mSymbolColorOPD[Wavelengthnumber - 1] = SymbolColor;
}
QBrush PlotParameterQwt::getOPDSymbolColor(int Wavelengthnumber)
{
	return mSymbolColorOPD[Wavelengthnumber - 1];
}
void PlotParameterQwt::setOPDSymbolStyle(QwtSymbol::Style SymbolStyle, int Wavelength)
{
	mSymbolStyleOPD[Wavelength - 1] = SymbolStyle;
}
QwtSymbol::Style PlotParameterQwt::getOPDSymbolStyle(int Wavelength)
{
	return mSymbolStyleOPD[Wavelength - 1];
}
void PlotParameterQwt::setOPDContourColorSymbol(QPen SymbolPen, int Wavelength)
{
	mSymbolPenOPD[Wavelength - 1] = SymbolPen;
}
QPen PlotParameterQwt::getOPDContourColorSymbol(int Wavelength)
{
	return mSymbolPenOPD[Wavelength - 1];
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

void PlotParameterQwt::setRayFanSymbolColor(QBrush SymbolColor, int Wavelength)
{
	mSymbolColorRayFan.at(Wavelength - 1) = SymbolColor;
}
QBrush PlotParameterQwt::getRayFanSymbolColor(int Wavelength)
{
	return mSymbolColorRayFan.at(Wavelength - 1);
}
void PlotParameterQwt::setRayFanSymbolStyle(QwtSymbol::Style SymbolStyle, int Wavelength)
{
	mSymbolStyleRayFan.at(Wavelength - 1) = SymbolStyle;
}
QwtSymbol::Style PlotParameterQwt::getRayFanSymbolStyle(int Wavelength)
{
	return mSymbolStyleRayFan.at(Wavelength - 1);
}
void PlotParameterQwt::setRayFanContourColorSymbol(QPen SymbolPen, int Wavelength)
{
	mSymbolPenRayFan.at(Wavelength - 1) = SymbolPen;
}
QPen PlotParameterQwt::getRayFanContourColorSymbol(int Wavelength)
{
	return mSymbolPenRayFan.at(Wavelength - 1);
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
