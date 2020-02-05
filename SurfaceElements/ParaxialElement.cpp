#include "ParaxialElement.h"

// we need a low level System for ray tracing
void ParaxialElement::buildParaxialLens_LLT()
{
	mParaxialLens_LLT.setSemiHeightParaxialLens(mSemiHeightParaxialParam.getValue());
	mParaxialLens_LLT.setPointParaxialLens(mPointParaxialParam.getValue());
	mParaxialLens_LLT.setDirectionParaxialLens(mDirectionParaxialParam.getValue());
	mParaxialLens_LLT.setDirectionParaxialLensUNIT(mDirectionParaxialUnitParam.getValue());
	mParaxialLens_LLT.setFocalLengthParaxialLens(mFocalLenghtParaxialParam.getValue());
	mParaxialLens_LLT.setRefractiveSideAParaxialLens(mRefractiveIndexA_ParaxialParam.getValue());
	mParaxialLens_LLT.setRefractiveSideBParaxialLens(mRefractiveIndexB_ParaxialParam.getValue());
}


// get the paraxial lens in LLT formate
ParaxialLens_LLT ParaxialElement::getParaxialLens_LLT()
{
	return mParaxialLens_LLT;
}

// get the LLT package
LLT_Package ParaxialElement::getLLT_Package()
{
	return LLT_Package{ &mParaxialLens_LLT ,&mRefraction_LLT };
}
