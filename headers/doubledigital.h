#ifndef DOUBLEDIGITAL_H
#define DOUBLEDIGITAL_H
#include "payoff.h"

class PayOffDoubleDigital:public PayOff 
{
public:
	PayOffDoubleDigital(double Low_, double High_);
	virtual double operator()(double Spot) const;

	//Virtual Copy Constructor. We want PayOffCall to be virtually copyable.
	//This method makes acopy of itself(PayOffCall) and returns a pointer to the copy.
	virtual PayOff* clone() const;
	virtual ~PayOffDoubleDigital(){}

private:
	double Low;
	double High;
};
#endif