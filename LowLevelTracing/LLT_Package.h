#pragma once
#include "SurfaceIntersectionRay_LLT.h"
#include "Interaction\InteractionRay_LLT.h"


struct LLT_Package {
	SurfaceIntersectionRay_LLT* surface_ptr;
	InteractionRay_LLT* interaction_ptr;

};