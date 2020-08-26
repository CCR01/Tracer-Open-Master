#pragma once

#include <qwt_plot.h>


class testRayFanQwtPlot
{
public:
	testRayFanQwtPlot() {};;
	~testRayFanQwtPlot() {};

	bool superFuncTestRayFanQwtPlot();

	bool testRayFanQwtPlotE0();
	bool testRayFanQwtPlotE1();
	bool testRayFanQwtPlotE2();




private:
	QwtPlot* mRayFanQwtPlotSystem0;
	QwtPlot* mRayFanQwtPlotSystem1;
	QwtPlot* mRayFanQwtPlotSystem2;
};