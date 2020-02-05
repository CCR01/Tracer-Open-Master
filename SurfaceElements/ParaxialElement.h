#pragma once

#include "../LowLevelTracing/ImportantStructures.h"
#include "../Element_CR.h"
#include "../LowLevelTracing/RefractedRay_LLT.h"
#include "../LowLevelTracing/LLT_Package.h"
#include "../LowLevelTracing/ParaxialLens_LLT.h"
#include "../parameter.h"

class ParaxialElement : Element_CR {
public:
	ParaxialElement() {};
	ParaxialElement(double semiHeight, VectorStructR3 point, VectorStructR3 direction, double focalLength, double refractiveSideA, double refractiveSideB) :
		mSemiHeightParaxialParam(semiHeight),
		mPointParaxialParam(point),
		mDirectionParaxialParam(direction),
		mDirectionParaxialUnitParam(Math::unitVector(direction)),
		mFocalLenghtParaxialParam(focalLength),
		mRefractiveIndexA_ParaxialParam(refractiveSideA),
		mRefractiveIndexB_ParaxialParam(refractiveSideB)
	{
		buildParaxialLens_LLT();
	};
	~ParaxialElement() {};

	LLT_Package getLLT_Package(); //TODO: nullptr? Subelements -> Vector?

	// we need a low level System for ray tracing
	void buildParaxialLens_LLT();
	ParaxialLens_LLT getParaxialLens_LLT(); // Just fo debugging

private:
	ParaxialLens_LLT mParaxialLens_LLT;

	// TODO!!!
	// add LLT interaction --> have to be switchable
	RefractedRay_LLT mRefraction_LLT;

	Parameter<real> mSemiHeightParaxialParam;
	Parameter<VectorStructR3> mPointParaxialParam;
	Parameter<VectorStructR3> mDirectionParaxialParam;
	Parameter<VectorStructR3> mDirectionParaxialUnitParam;
	Parameter<real> mFocalLenghtParaxialParam;
	Parameter<real> mRefractiveIndexA_ParaxialParam;
	Parameter<real> mRefractiveIndexB_ParaxialParam;

};