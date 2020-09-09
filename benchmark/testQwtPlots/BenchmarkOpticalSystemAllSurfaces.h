#pragma once

class OpticalSystemAllSurfaces

{
public:
	OpticalSystemAllSurfaces() {};
	~OpticalSystemAllSurfaces() {};

	bool testQwtPlotsSytem();

private:
	RayTracingQwtPlot* mRayTracingQwtPlotSystem;
	SpotPlotDiagramQwt* mSpotDiagramQwtPlotSystem;

};