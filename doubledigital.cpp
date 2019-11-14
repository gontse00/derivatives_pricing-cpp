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