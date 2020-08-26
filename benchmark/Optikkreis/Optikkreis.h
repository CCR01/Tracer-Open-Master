#pragma once


// optical system
#include "..\..\OpticalSystemElement\OpticalSystemElement.h"

// sequential ray tracing
#include "..\..\SequentialRayTracing\SequentialRayTracer.h"

// optimizer
#include "..\..\OptimizeSystem\OptimizeOpticalSystem.h"

class Optikkreis
{
public:
	Optikkreis();
	~Optikkreis();

	bool systemForOptikkreis();
	bool plotSpotDiagramme_startSystem(std::vector<Spot> spot_vec);
	bool testTheSystem(OpticalSystemElement optSysEle);
	bool plotStartSystemOK(OpticalSystemElement optSysEle, std::vector<SequentialRayTracing> seqTrace_vec);
	bool plotOptimizedSystemOK(OpticalSystemElement optSysEle, std::vector<SequentialRayTracing> seqTrace_vec);
	bool plotSpotDiagramme_optimizedSystem(std::vector<Spot> spot_vec);

	void printBasics(OptimizeOpticalSystem optimizedOptSys);


private:

};

