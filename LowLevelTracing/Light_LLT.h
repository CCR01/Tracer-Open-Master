#pragma once
#include "JonesVector.h"

// Difference light types
enum class typeLight { typeLightRay, typeWaveScalar, typeWaveVectorial, typeGaussian, typeDeath };

class Light_LLT 
{
public: Light_LLT();
		Light_LLT(/*wavelength*/ double wavelength, /*intensity*/ double intensity,/*polarisation*/ JonesVector_LLT polarisation,/*light type*/ typeLight lightType);
		Light_LLT(/*wavelength*/ double wavelength);
		~Light_LLT();

		// set light_LLT
		void set(Light_LLT light_LLT);

		// get wavelength
		double getWavelength() const;
		// set wavelength
		void setWavelength(const double wavelength);

		// get intensity 
		double getIntensity();
		// set intensity
		void setIntensity(double intensity);
		// get jones vector
		JonesVector_LLT getJonesVector() const;
		// set jones vector
		void setJonesVector(const JonesVector_LLT& jonesVector);
		//get light type
		typeLight getTypeLight();
		//set light type
		void setTypeLight(const typeLight lightType);

		// set light to absorb
		void setLightToAbsorb();
		
		void buildDefaultLight();

private:
	double mWavelength{};
	double mIntensity{};
	JonesVector_LLT mPolarisation{};
	typeLight mLightType{};

};