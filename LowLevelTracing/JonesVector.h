#pragma once
//#include "ImportantStructures.h"

class JonesVector_LLT 
{
public:
	JonesVector_LLT();
	JonesVector_LLT(double ra, double ia, double rb, double ib);
	~JonesVector_LLT();

	// ra
	double getRa();
	void setRA(double ra);
	// ia
	double getIa();
	void setIa(double ia);
	// rb
	double getRb();
	void setRb(double rb);
	// ib
	double getIb();
	void setIb(double ib);


private:
	double mRa{};
	double mIa{};
	double mRb{};
	double mIb{};
};