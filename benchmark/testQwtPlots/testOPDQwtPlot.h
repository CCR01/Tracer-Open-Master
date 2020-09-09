#pragma once
#include <qwt_plot.h>


class testOPDQwtPlot
{
public:
	testOPDQwtPlot();
	~testOPDQwtPlot();

	bool superFuncTestOPDQwtPlot();

	bool testOPDQwtPlotE0();
	bool testOPDQwtPlotE1();
	bool testOPDQwtPlotE2();
	bool testOPDQwtPlotE3();



private:
	QwtPlot* mOPDQwtPlotSystem0;
	QwtPlot* mOPDQwtPlotSystem1;
	QwtPlot* mOPDQwtPlotSystem2;
	QwtPlot* mOPDQwtPlotSystem3;
};