#pragma once
#include "..\Plot\Plot.h"
#include "..\SequentialRayTracing\SequentialRayTracer.h"
#include "..\LowLevelTracing\OpticalSystem_LLT.h"


class Plot2D
{
public:
	Plot2D() {};
	Plot2D(OpticalSystem_LLT OptSys, SequentialRayTracing SeqRayTrac, cv::Mat image, unsigned int scale, unsigned int thickness, unsigned int lineType);
	Plot2D(OpticalSystemElement OptSysElement, SequentialRayTracing SeqRayTrac, cv::Mat image, unsigned int scale, unsigned int thickness, unsigned int lineType);
	~Plot2D() {};
	
	void plotOpticalSystem2D();
	void plotRays();

private:

	OpticalSystemElement mOptSys_Ele;
	OpticalSystem_LLT mOptSys_LLT;
	SequentialRayTracing mSeqRayTrac;
	cv::Mat mImage;
	unsigned int mScale;
	unsigned int mThickness;
	unsigned int mLineType;
	


};

