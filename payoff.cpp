#include "headers/payoff.h"
#include <algorithm>

PayOffCall::PayOffCall(double Strike_):Strike(Strike_){}
double PayOffCall::operator()(double Spot) const
{
	return std::max(Spot-Strike,0.0);
}

PayOffPut::PayOffPut(double Strike_):Strike(Strike_){}
double PayOffPut::operator()(double Spot) const
{
	return std::max(Strike-Spot,0.0);
}

/*
double PayOff::operator()(double spot) const
{
	switch (TheOptionsType)
	{
		case call:
		    return std::max(spot-Strike, 0.0);

		case put:
		    return std::max(Strike-spot, 0.0);

		default:
		    throw("unknown option type found. ");
	}
}
*/