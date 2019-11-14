#ifndef DOUBLEDIGITAL_H
#define DOUBLEDIGITAL_H
#include "payoff.h"

class PayOffDoubleDigital:public PayOff 
{
public:
	PayOffDoubleDigital(double Low_, double High_);
	virtual double operator()(double Spot) const;
	virtual ~PayOffDoubleDigital(){}
private:
	double Low;
	double High;
};
#endif