#pragma once
#include <qwt_plot.h>
#include "..\..\Plot\PlotQwt.h"

class testRayTracingQwtPlot
{
public:
	testRayTracingQwtPlot();
	~testRayTracingQwtPlot();

	bool superFuncTestRayTracingQwtPlot();

	bool testRayTracingQwtPlotE0();
	bool testRayTracingQwtPlotE1();
	bool testRayTracingQwtPlotE2();
	bool testRayTracingQwtPlotE3();


private:
	RayTracingQwtPlot* mRayTracingQwtPlotSystem0;
	RayTracingQwtPlot* mRayTracingQwtPlotSystem1;
	RayTracingQwtPlot* mRayTracingQwtPlotSystem2;
};

