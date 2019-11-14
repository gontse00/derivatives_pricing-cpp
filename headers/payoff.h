#ifndef PAYOFF_H
#define PAYOFF_H
/*Payoff Class Definition*/ 

class PayOff
{
public:
	enum OptionType {call, put};
	PayOff(double Strike_, OptionType TheOptionsType_);
	double operator()(double Spot) const;
private:
	double Strike;
	OptionType TheOptionsType;
};
#endif