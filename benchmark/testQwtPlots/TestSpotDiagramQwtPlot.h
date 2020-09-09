#pragma once
#include <qwt_plot.h>



class testSpotDiagramQwtPlot
{
public:
	testSpotDiagramQwtPlot();
	~testSpotDiagramQwtPlot();

	bool superFuncTestSpotDiagramQwtPlot();

	bool testSpotDiagramQwtPlotE0();
	bool testSpotDiagramQwtPlotE1();
	bool testSpotDiagramQwtPlotE2();
	bool testSpotDiagramQwtPlotE3();


private:

	QwtPlot* mSpotDiagramQwtPlotSystem0;
	QwtPlot* mSpotDiagramQwtPlotSystem1;
	QwtPlot* mSpotDiagramQwtPlotSystem2;
	QwtPlot* mSpotDiagramQwtPlotSystem3;
};
