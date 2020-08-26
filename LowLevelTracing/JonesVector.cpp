#include "JonesVector.h"

JonesVector_LLT::JonesVector_LLT() {};

JonesVector_LLT::JonesVector_LLT(double ra, double ia, double rb, double ib) :
	mRa(ra),
	mIa(ia),
	mRb(rb),
	mIb(ib)
{}

JonesVector_LLT::~JonesVector_LLT() {};

// ra
double JonesVector_LLT::getRa()
{
	return mRa;
}
void JonesVector_LLT::setRA(double ra)
{
	mRa = ra;
}
// ia
double JonesVector_LLT::getIa()
{
	return mIa;
}
void JonesVector_LLT::setIa(double ia)
{
	mIa = ia;
}
// rb
double JonesVector_LLT::getRb()
{
	return mRb;
}
void JonesVector_LLT::setRb(double rb)
{
	mRb = rb;
}
// ib
double JonesVector_LLT::getIb()
{
	return mIb;
}
void JonesVector_LLT::setIb(double ib)
{
	mIb = ib;
}