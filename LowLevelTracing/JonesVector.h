#pragma once

class JonesVector_LLT {
public:
	JonesVector_LLT() {};
	JonesVector_LLT(double ra, double ia, double rb, double ib):
		mRa(ra),
		mIa(ia),
		mRb(rb),
		mIb(ib)
	{}

	~JonesVector_LLT() {};

	// TODO Question: set und get Funktionen schreiben!

private:
	double mRa;
	double mIa;
	double mRb;
	double mIb;
};