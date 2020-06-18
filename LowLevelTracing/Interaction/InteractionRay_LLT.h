#include "..\Ray_LLT.h"
#include <vector>
#include <iostream>

#pragma once


struct LightRayStruct
{
public:
	LightRayStruct();
	LightRayStruct(VectorStructR3 origin, VectorStructR3 direction, real refractivIndex);
	LightRayStruct(/*light*/ Light_LLT iLight, /*ray*/ Ray_LLT iRay);
	LightRayStruct(/*light*/ Light_LLT iLight, /*ray*/ Ray_LLT iRay, /*is alive*/ bool i_Alive);
	~LightRayStruct();

	// get Ray_LLT
	Ray_LLT getRay_LLT() const;
	// set Ray_LLT
	void setRay_LLT(Ray_LLT& const raySet);
	// ray origin
	void setRayOrigin(VectorStructR3 rayOrigin);
	// ray direction unit
	void setRayDirectionUni(VectorStructR3 rayDirection);
	// currecnt refractiv index ray
	void setCurrentRefractivIndex(real curRefIndex);

	//get Light_LLT
	Light_LLT getLight_LLT() const;
	//set Light_LLT
	void setLight_LLT(Light_LLT& const lightSet);
	// wavelength
	void setLightWavelength(real wavelenght);
	// get is LightRay alive
	bool getIsAlive() const;
	// set is LightRay alive
	void setIsAlive(const bool& alive);

	// set light ray absorb
	void setLightRayAbsorb();

private:
	Ray_LLT mRay{};
	Light_LLT mLight{};
	bool mIsAlive{};

};

struct RaysRangeStruct
{
public:
	RaysRangeStruct();
	RaysRangeStruct(unsigned int const min, unsigned int const max);
	~RaysRangeStruct();

	// min
	unsigned int getMin();
	void setMin(unsigned int min);
	// max 
	unsigned int getMax();
	void setMax(unsigned int max);

private:
	unsigned int mMin{};
	unsigned int mMax{};
};

class InteractionRay_LLT {
public:
	InteractionRay_LLT();
	virtual ~InteractionRay_LLT();

	virtual std::shared_ptr<InteractionRay_LLT> clone() = 0;
	virtual RaysRangeStruct howManyRays() = 0;
	virtual std::vector<LightRayStruct> calcInteraction(const IntersectInformationStruct& IntersectInfo) = 0;


};


