#ifndef PAYOFF_H
#define PAYOFF_H
/*Payoff Class Definition*/ 

/*
chapter 2 payoff class
class PayOff
{
public:
	enum OptionType {call, put};
	PayOff(double Strike_, OptionType TheOptionsType_);
	double operator()(double Spot) const;
private:
	double Strike;
	OptionType TheOptionsType;
};*/
/* 
chapter 3 payoff class
*/

class PayOff
{
public:
	PayOff(){};
	virtual double operator()(double Spot) const=0;
	virtual ~PayOff(){};

private:
};

class PayOffCall:public PayOff
{
public:
	PayOffCall(double Strike_);
	virtual double operator()(double Spot) const;
	virtual ~PayOffCall(){}

private:
	double Strike;
};

class PayOffPut:public PayOff
{
public:
	PayOffPut(double Strike_);
	virtual double operator()(double Spot) const;
	virtual ~PayOffPut(){};

private:
	double Strike;
};
#endif