#include "OpticalSystemPlots.h"

void SequentialRayTracingandColorStruct::setColor(QColor const& color)
{
	mColor = color;
}

QColor SequentialRayTracingandColorStruct::getColor() const&
{
	return mColor;
}

void SequentialRayTracingandColorStruct::setSequentialRayTracing(SequentialRayTracing* SeqRayTrac)
{
	mSeqRayTrac = SeqRayTrac;
}

SequentialRayTracing* SequentialRayTracingandColorStruct::getSequentialRayTracing() const&
{
	return mSeqRayTrac;
}


//get vector ray fan diagrams
std::vector< std::vector<PlotRayFan*>> OpticalSystemCurves::getVectorRayFanDiagram()
{
	return mVectorRayPlotDiagramm;
}

// fill the vector with Spotdiagrams
void OpticalSystemCurves::fillVectorRayFanDiagramToPlot(PlotRayFan* plotRayFan, int numberOfWavelengths)
{
	mVectorRayPlotDiagramm[numberOfWavelengths - 1].push_back(plotRayFan);
}

double  OpticalSystemCurves::getMaxRayFanScale()
{
	double maxScale = mVectorRayPlotDiagramm.at(0).at(0)->getScaleRayFanPlot();

	for (unsigned int j = 0; j < mVectorRayPlotDiagramm.size(); j++)
	{
		for (unsigned int i = 0; i < mVectorRayPlotDiagramm[j].size(); i++)
		{

		if (mVectorRayPlotDiagramm.at(j).at(i)->getScaleRayFanPlot() < maxScale)
		   {
			maxScale = mVectorRayPlotDiagramm.at(j).at(i)->getScaleRayFanPlot();
		   }
	    }
	}
	return maxScale;
}

// fill the vector with rayFan
void OpticalSystemCurves::fillVectorplotOPDDiagramToPlot(PlotOPD* plotOPD, int numberOfWavelengths)
{
	mVectorOPDPlotDiagramm[numberOfWavelengths - 1].push_back(plotOPD);
}


//fill the vector with the raytracing 
void  OpticalSystemCurves::fillVectorRayTracSurfaces(QwtPlotCurve* SurfaceCurvePtr)
{
	mVectorRayTracSurfaces.push_back(SurfaceCurvePtr);
}
//get vector raytracing
std::vector<QwtPlotCurve*>  OpticalSystemCurves::getVectorRayTracSurfaces()
{
	return mVectorRayTracSurfaces;
}

void OpticalSystemCurves::fillVectorSequentialRayTracing(SequentialRayTracing* SeqRayTrac, QColor color)
{
	SequentialRayTracingandColorStruct SeqRayTracAndColorStruct;
	SeqRayTracAndColorStruct.setColor(color);
	SeqRayTracAndColorStruct.setSequentialRayTracing(SeqRayTrac);
	mVectorSeqRayTracPtrAndColor.push_back(SeqRayTracAndColorStruct);

}

std::vector<SequentialRayTracingandColorStruct> OpticalSystemCurves::getVectorSeqRayTracingAndColor()
{
	return mVectorSeqRayTracPtrAndColor;
}

void OpticalSystemCurves::fillVectorSpotDiagramm(PlotSpotDiagramm* PlotSpot,  int WavelengthNumber)
{
	
	mVectorPlotSpotDiagramm[WavelengthNumber-1].push_back(PlotSpot);
}

std::vector< std::vector< PlotSpotDiagramm*>> OpticalSystemCurves::getVectorSpotDiagramm()
{
	return mVectorPlotSpotDiagramm;
}

double OpticalSystemCurves::getMaxSpotDiagrammScale()
{
	double maxScale = mVectorPlotSpotDiagramm[0].at(0)->calculateScaleSpotDia();

	for (unsigned int j = 0; j < mVectorPlotSpotDiagramm.size(); j++)
	{
		for (unsigned int i = 0; i < mVectorPlotSpotDiagramm[j].size(); i++)
		{
			if (mVectorPlotSpotDiagramm[j].at(i)->calculateScaleSpotDia() > maxScale)
			{
				maxScale = mVectorPlotSpotDiagramm[j].at(i)->calculateScaleSpotDia();
			}
		}
	}
	return maxScale;
}

void OpticalSystemCurves::giveNumberWavelengthsSpotDiagram(int numberOfWavelengths)
{
	for (unsigned int i = 0; i < numberOfWavelengths; i++)
	{
		mVectorPlotSpotDiagramm.push_back(std::vector<PlotSpotDiagramm*>());
	}
}

void OpticalSystemCurves::giveNumberWavelengthsRayFan(int numberOfWavelengths)
{
	for (unsigned int i = 0; i < numberOfWavelengths; i++)
	{
		mVectorRayPlotDiagramm.push_back(std::vector<PlotRayFan*>());
	}
}

//get vector ray fan diagrams
std::vector < std::vector<PlotOPD*>> OpticalSystemCurves::getVectorOPDDiagram()
{
	return mVectorOPDPlotDiagramm;
}

//get min Scale Ray Fan
double OpticalSystemCurves::getMaxOPDPlotScale() {

	double maxScale = mVectorOPDPlotDiagramm[0].at(0)->getScaleOPDPlot();
	
	for (unsigned int j = 0; j < mVectorPlotSpotDiagramm.size(); j++)
	{
		for (unsigned int i = 0; i < mVectorOPDPlotDiagramm[j].size(); i++)
		{
			if (mVectorOPDPlotDiagramm[j].at(i)->getScaleOPDPlot() >= maxScale)
			{
				maxScale = mVectorOPDPlotDiagramm[j].at(i)->getScaleOPDPlot();
			}
		}
	}
	return maxScale;
}


//give number of Wavelengths OPD
void OpticalSystemCurves::giveNumberWavelengthsOPD(int numberOfWavelengths)
{
	for (unsigned int i = 0; i < numberOfWavelengths; i++)
	{
		mVectorOPDPlotDiagramm.push_back(std::vector<PlotOPD*>());
	}
}