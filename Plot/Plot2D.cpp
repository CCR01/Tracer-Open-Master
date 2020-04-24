#include "Plot2D.h"

Plot2D::Plot2D(OpticalSystem_LLT OptSys, SequentialRayTracing SeqRayTrac, cv::Mat image, unsigned int scale, unsigned int thickness, unsigned int lineType) :
	mOptSys_LLT(OptSys),
	mSeqRayTrac(SeqRayTrac),
	mImage(image),
	mScale(scale),
	mThickness(thickness),
	mLineType(lineType)
{};

Plot2D::Plot2D(OpticalSystemElement OptSysElement, SequentialRayTracing SeqRayTrac, cv::Mat image, unsigned int scale, unsigned int thickness, unsigned int lineType):
	mOptSys_Ele(OptSysElement),
	mOptSys_LLT(mOptSys_Ele.getOpticalSystem_LLT()),
	mSeqRayTrac(SeqRayTrac),
	mImage(image),
	mScale(scale),
	mThickness(thickness),
	mLineType(lineType)
{};

// plot optical system
void Plot2D::plotOpticalSystem2D()
{
	for (unsigned int i = 0; i < mOptSys_LLT.getPosAndInteractingSurface().size(); i++)
	{
		mOptSys_LLT.getPosAndSurfToPlot2D().at(i).getSurfaceToPlot2D_ptr()->plot2D(mImage, mScale, mLineType, mThickness);
	}

}	


// plot the rays
void Plot2D::plotRays()
{
	
	unsigned int height = mImage.rows;
	unsigned int i = 0;
	unsigned int counter = 0;
	unsigned numRay = 0;
	unsigned int boarterLeft = 50;

	for (numRay; numRay < mSeqRayTrac.getAllIntersectionPointsSRT().size(); numRay)
	{

	
		for (i ; numRay < mSeqRayTrac.getAllIntersectionPointsSRT().size(); i++)
		{
			real yStart = mSeqRayTrac.getStartPoints().at(i).getY();
			real zStart = mSeqRayTrac.getStartPoints().at(i).getZ();

			int yStartPlot = height/2 - yStart * mScale;
			int zStartPlot = boarterLeft + zStart * mScale;
			cv::Point start(zStartPlot, yStartPlot);


			// TODO: hier muss ich mir noch was schönes überlegen!!!
			cv::Point test(0.0, 0.0);
			cv::Scalar color;

			if (yStart == 0.0)
			{
				color = { 255,0,0 };
			}

			if (yStart == 1.0)
			{
				color = { 0,255,0 };
			}
			
			if (yStart == 2.0)
			{
				color = { 0,0,255 };
			}
			
			unsigned int atSurface = 0;

			for (unsigned int j = 0; j <= mOptSys_LLT.getNumberOfSurfaces(); j++)
			{
				
				real tempY = mSeqRayTrac.getAllInterPointsAtSurf_i_notFiltered(atSurface).at(counter).getY();
				real tempX = mSeqRayTrac.getAllInterPointsAtSurf_i_notFiltered(atSurface).at(counter).getZ();
				
				int tempYplot = height/2 - tempY * mScale;
				int tempXplot = boarterLeft + tempX * mScale;
				cv::Point end(tempXplot, tempYplot);

				PlotCarsten::line(mImage, start, end, color, mLineType, mThickness/2);

				// start point is end point from last ray
				start = end;
				// got to next surface
				atSurface++;
				
				numRay++;

			}

			counter++;

		}
	}
}