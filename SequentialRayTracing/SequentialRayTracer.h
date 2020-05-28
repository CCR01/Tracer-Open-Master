#pragma once
//#include "..\LowLevelTracing\OpticalSystem_LLT.h"
#include "..\LowLevelTracing\Math_LLT.h"
#include "..\LowLevelTracing\Ray_LLT.h"
#include <vector>

#include "..\OpticalSystemElement\OpticalSystemElement.h"
//#include "..\RayAiming\RayAiming.h"


struct IntersectInfosAndPosSurfaceAndTotalSteps
{

public:

	IntersectInfosAndPosSurfaceAndTotalSteps();
	~IntersectInfosAndPosSurfaceAndTotalSteps();

	// get intersection infos
	IntersectInformationStruct getIntersecInfos() const;
	// set intersection infos
	void setIntersectionInfos(IntersectInformationStruct const setIntersectinfos);

	// set position
	void setPosition(unsigned int const pos);
	// get position
	unsigned int getPosition() const;

	// set total  steps
	void setTotalSteps(real const totSte);
	// get total steps 
	real getTotalSteps() const;

	// no intersection point
	void setNoIntersectionPoint();

private:
	IntersectInformationStruct mIntersectInfos{};
	unsigned int mPosition{};
	real mTotalSteps{};


};

struct saveResultsSeqRayTrace_parallel
{
	saveResultsSeqRayTrace_parallel();
	~saveResultsSeqRayTrace_parallel();

	std::vector<VectorStructR3> getStartPointsOfLightRay();
	void setStartPointsOfLightRay(std::vector<VectorStructR3> startPointsLightRay);
	std::vector <IntersectInfosAndPosSurfaceAndTotalSteps> getIntersectInfosAndPosSurfaceAndTotalSteps();
	void setIntersectInfosAndPosSurfaceAndTotalSteps(std::vector <IntersectInfosAndPosSurfaceAndTotalSteps> intInfos_Pos_totStep_NotFiltered);
	std::vector <std::vector<LightRayStruct>> getLightRayStructNotFiltered();
	void setLightRayStructNotFiltered(std::vector <std::vector<LightRayStruct>> lightRayStructNotFiltered);
	std::vector <IntersectInfosAndPosSurfaceAndTotalSteps> getInterInfosAndPosSurAndTotStep();
	void setInterInfosAndPosSurAndTotStep(std::vector <IntersectInfosAndPosSurfaceAndTotalSteps> interInfosAndPosSurAndTotStep);

private:

	std::vector<VectorStructR3> mStartPointOfLightRays;
	std::vector <IntersectInfosAndPosSurfaceAndTotalSteps> mSaveIntInfos_Pos_totStep_NotFiltered; //there are all intersection points also them with surface side N
	std::vector <std::vector<LightRayStruct>> mSaveLightRayStructsNotFiltered; //there are all intersection points also them with surface side N
	std::vector <IntersectInfosAndPosSurfaceAndTotalSteps> mSaveInterInfos_PosSur_TotSteps;
};

class SequentialRayTracing {
public:
	SequentialRayTracing();
	SequentialRayTracing(OpticalSystem_LLT opticalSystem);
	SequentialRayTracing(OpticalSystem_LLT opticalSystem, unsigned int traToSur);
	SequentialRayTracing(OpticalSystemElement opticalSysElement);
	SequentialRayTracing(OpticalSystemElement opticalSysElement, LightRayStruct LightRay);
	SequentialRayTracing(OpticalSystemElement /*optical system element*/ opticalSysElement, VectorStructR3 /*start point lightRay*/ startPointLightRay, unsigned int /*rings*/ rings, unsigned int /*arms*/ arms, real /*refractive index*/ refIndex, Light_LLT mLight);
	SequentialRayTracing(OpticalSystemElement /*optical system element*/ opticalSysElement, VectorStructR3 /*start point lightRay*/ startPointLightRay, unsigned int /*rings*/ rings, unsigned int /*arms*/ arms, real /*refractive index*/ refIndex, std::vector<Light_LLT> light_vec);
	~SequentialRayTracing();

	// do sequential ray tracing
	void sequentialRayTracing(LightRayStruct LightRaySt);

	// do sequential ray tracing with an vector of many LightRay
	void seqRayTracingWithVectorOfLightRays(const std::vector<LightRayStruct>& LightRayStVec);

	// print all IntersectInfos from sequential raytracing
	void printAllIntersectInfosSRT();

	// get all intersection points from SRT
	std::vector<VectorStructR3> getAllIntersectionPointsSRT();

	// print all intersection points
	void printAllIntersectionPoints();

	// get all intersection points of surface i
	std::vector<IntersectInformationStruct> getAllInterInfosOfSurf_i(unsigned int const surfaceNo);

	// filter for all real intersection points
	std::vector <IntersectInfosAndPosSurfaceAndTotalSteps> filterAllRealIntersecPoints(std::vector <IntersectInfosAndPosSurfaceAndTotalSteps>);

	// print all intersection points at surface i
	void printAllInterInfosAtSurface_i(unsigned int const surfaceNo);

	// get all intersection points at surface i
	std::vector<VectorStructR3> getAllInterPointsAtSurf_i_notFiltered(unsigned int const surfaceNo);

	// get all intersection points at surfaces i and intensity of lightRay;
	std::vector<pointAndIntensity> getAllInterPointsAndIntensityAtSurface_i(unsigned int const surfaceNo);

	// get intersection point i at Surface i not filtered
	VectorStructR3 getInterPoint_i_atSurface_i_notFiltered(unsigned int const interPointNo, unsigned int const surfaceNo);

	// get all intersection points of surface i not filtered
	std::vector<IntersectInformationStruct> getAllInterInfosOfSurf_i_notFiltered(unsigned int const surfaceNo);

	// get all intersection points of surface i filtered
	std::vector<VectorStructR3> getAllInterPointsAtSurface_i_filtered(unsigned int const surfaceNo);

	// get semi height of surface i
	double getSemiHeightOfSurface_i(unsigned int i);

	// get point of surface i
	VectorStructR3 getPointSurface_i(unsigned int i);

	// get direction of surface_i
	VectorStructR3 getDirectionSurface_i(unsigned int i);

	// clear all traced rays 
	void clearAllTracedRays();

	// get IntersectInfos, PosSurface and TotalSteps
	std::vector <IntersectInfosAndPosSurfaceAndTotalSteps> getInterInf_PosSurface_TotalSteps_ofSur_i(unsigned int const surfaceNo);

	// get all total optical path lenth to surface i
	std::vector<real> getTotalOptPathLenthToSurface_i(unsigned int surfaceNo);

	// build many lightRay along x achse (y = 0) 
	static std::vector<LightRayStruct> lightRayAlongX(VectorStructR3 startPoint, unsigned int numberLightRay, real zPos, real minX, real maxX, real wavelength, real curRefInd);
	// build many lightRay along y achse (x = 0) 
	static std::vector<LightRayStruct> lightRayAlongY(VectorStructR3 startPoint, unsigned int numberLightRay, real zPos, real minY, real maxY, real wavelength, real curRefInd);

	// get all start points
	std::vector<VectorStructR3> getStartPoints();

	// set the optical system
	void setOpticalSystem(OpticalSystem_LLT optSysLLT);
	void setOpticalSystem(OpticalSystemElement optSysHLT);

	// set trace to surface
	void setTraceToSurface(unsigned int traceToSurface);

	// find position of aperture stop
	unsigned int findPosApertureStop(OpticalSystem_LLT optSys_LLT);

	//void seqRayTracingWithVectorOfLightRays_parallel(std::vector<LightRayStruct> const LightRayStVec);

	std::vector<std::vector<LightRayStruct>> divVecWithLightRay(std::vector<LightRayStruct> lightRayStVec);

	void setRefractivIndexOptSys(real wavelength);

	void resizeAllRelevantVectorsAndSetConst_Element();
	void resizeAllRelevantVectorsAndSetConst_LLT();

private:

	OpticalSystemElement mOptSysEle{};
	OpticalSystem_LLT mOpticalSystem_LLT{};
	unsigned int mTraceToSurface_i{};

	std::vector<Light_LLT> mLight_LLT_vec{};
	std::vector<VectorStructR3> referencePoints{};

	LightRayStruct mLightRay{};
	std::vector<LightRayStruct> mStdVecLightRayStruct{};

	std::vector <IntersectInfosAndPosSurfaceAndTotalSteps> mSaveIntInfos_Pos_totStep_NotFiltered{}; //there are all intersection points also them with surface side N
	std::vector <IntersectInfosAndPosSurfaceAndTotalSteps> mSaveInterInfos_PosSur_TotSteps{};
	std::vector <std::vector<LightRayStruct>> mSaveLightRayStructsNotFiltered{}; //there are all intersection points also them with surface side N

	std::vector<VectorStructR3> mStartPointOfLightRays{};
	unsigned int mPositionApertureStop;

	Ray_LLT mRay{};
	Light_LLT mLight{};
	IntersectInfosAndPosSurfaceAndTotalSteps mTempInterInfos_Pos_totStep{};
	unsigned int mSizeOfVector{};
	IntersectInfosAndPosSurfaceAndTotalSteps mNoInterPointAndPos{};
	real mSaveTotalSteps{};
	std::vector<LightRayStruct> mTempLightRay_vec{};

};





struct SequentialRayTracingandColorStruct
{
	SequentialRayTracingandColorStruct();
	~SequentialRayTracingandColorStruct();
	SequentialRayTracingandColorStruct(SequentialRayTracing* SeqRayTrac, QColor color);
	SequentialRayTracing* mSeqRayTrac;
	QColor mColor;

	// set Color
	void setColor(QColor const color);
	// get Color
	QColor getColor() const;

	// set SequentialRayTracing
	void setSequentialRayTracing(SequentialRayTracing* SeqRayTrac);
	// get SequentialRayTracing
	SequentialRayTracing* getSequentialRayTracing() const;

};

class RayTracingSystem
{
public:
	RayTracingSystem() {};
	//fill vector with Rays to plot
	void fillVectorRayTracing(SequentialRayTracing* SeqRayTrac, QColor color);

	//get vector with Rays to plot
	std::vector<SequentialRayTracingandColorStruct> getVectorRayTracing();


private:
	std::vector<SequentialRayTracingandColorStruct> mSeqRayTracAndColorStruct;
};