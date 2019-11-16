#include "headers/doubledigital.h"

PayOffDoubleDigital::PayOffDoubleDigital(double Low_, double High_):Low(Low_),High(High_){}
double PayOffDoubleDigital::operator()(double Spot) const
{
	if (Spot<=Low)
		return 0;
	if (Spot>=High)
		return 0;
	return 1;
}
PayOff* PayOffDoubleDigital::clone() const
{
	return new PayOffDoubleDigital(*this);
	//This line creates a copy of the object for which the clone method has been called,
	//as the "this" pointer always points to the object bieng called. The call to clone()
	//is then a call to the copy constructor of PayOffDoubleDigital which returns a copy of the,
	//Original PayOffDoubleDigital, and because the operator "new" has been used, we can be sure that
	//the object will continue to exit.
}