#include "headers/payoff.h"
#include <algorithm>

PayOffCall::PayOffCall(double Strike_):Strike(Strike_){}
double PayOffCall::operator()(double Spot) const
{
	return std::max(Spot-Strike,0.0);
}
PayOff* PayOffCall::clone() const
{
	return new PayOffCall(*this);
	//This line creates a copy of the object for which the clone method has been called,
	//as the "this" pointer always points to the object bieng called. The call to clone()
	//is then a call to the copy constructor of PayOffCall which returns a copy of the,
	//Original payOffCall, and because the operator "new" has been used, we can be sure that
	//the object will continue to exit.
} 

PayOffPut::PayOffPut(double Strike_):Strike(Strike_){}
double PayOffPut::operator()(double Spot) const
{
	return std::max(Strike-Spot,0.0);
}
PayOff* PayOffPut::clone() const
{
	return new PayOffPut(*this);
	//This line creates a copy of the object for which the clone method has been called,
	//as the "this" pointer always points to the object bieng called. The call to clone()
	//is then a call to the copy constructor of PayOffPut which returns a copy of the,
	//Original PayOffPut, and because the operator "new" has been used, we can be sure that
	//the object will continue to exit. 
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