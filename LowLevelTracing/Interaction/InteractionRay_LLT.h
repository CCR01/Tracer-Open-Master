#include "..\ImportantStructures.h"
#include "..\Ray_LLT.h"
#include <vector>
#include <iostream>

#pragma once


struct LightRayStruct
{
	LightRayStruct() {};
	LightRayStruct(/*light*/ Light_LLT iLight, /*ray*/ Ray_LLT iRay, /*is alive*/ unsigned int i_Alive)
	{

		light = iLight;
		ray = iRay;
		isAlive = i_Alive;
	}
	~LightRayStruct() {};

	Ray_LLT ray;
	Light_LLT light;
	unsigned int isAlive = 1;
	// get Ray_LLT
	Ray_LLT getRay_LLT() const&;
	// set Ray_LLT
	void setRay_LLT(Ray_LLT const& raySet);
	//get Light_LLT
	Light_LLT getLight_LLT() const&;
	//set Light_LLT
	void setLight_LLT(Light_LLT const& lightSet);
	// get is LightRay alive
	int getIsAlive() const&;
	// set is LightRay alive
	void setIsAlive(int const& alive);

};

class InteractionRay_LLT {
public:
	InteractionRay_LLT() {};
	virtual ~InteractionRay_LLT() {};
	virtual std::shared_ptr<InteractionRay_LLT> clone() = 0;

	struct RaysRangeStruct 
	{
		unsigned int min;
		unsigned int max;
	};

	virtual RaysRangeStruct howManyRays() = 0;
	
	virtual std::vector<LightRayStruct> calcInteraction(IntersectInformationStruct IntersectInfo) = 0;


};


