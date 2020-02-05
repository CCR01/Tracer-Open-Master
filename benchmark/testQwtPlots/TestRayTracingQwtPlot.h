#pragma once
#include <qwt_plot.h>
#include "../../VS-Solution_tracer-open/PlotQwt.h"

class testRayTracingQwtPlot
{
public:
	testRayTracingQwtPlot();
	~testRayTracingQwtPlot();

	bool superFuncTestRayTracingQwtPlot();

	bool testRayTracingQwtPlotE0();
	bool testRayTracingQwtPlotE1();
	bool testRayTracingQwtPlotE2();



private:
	RayTracingQwtPlot* mRayTracingQwtPlotSystem1;
	RayTracingQwtPlot* mRayTracingQwtPlotSystem2;
	RayTracingQwtPlot* mRayTracingQwtPlotSystem3;
};

