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
	virtual ~PayOff(){}

	virtual PayOff* clone() const=0;
	//Pure Virtual Copy Constructor. We want PayOff to be virtually copyable.
	//This method makes a copy of itself(PayOff) and returns a pointer to the copy.
	//it is a pure virtual method so its implemention will be defined in subsequent
	//inherited classes(PayOffCall,PayOffPut,PayOffDoubleDigital, etc.) 

private:
};

class PayOffCall:public PayOff
{
public:
	PayOffCall(double Strike_);
	virtual double operator()(double Spot) const;
	virtual ~PayOffCall(){}

	virtual PayOff* clone() const;
	//Virtual Copy Constructor. We want PayOffCall to be virtually copyable.
	//This method makes a copy of itself(PayOffCall) and returns a pointer to the copy.

private:
	double Strike;
};

class PayOffPut:public PayOff
{
public:
	PayOffPut(double Strike_);
	virtual double operator()(double Spot) const;
	virtual ~PayOffPut(){}

	virtual PayOff* clone() const;
	//Virtual Copy Constructor. We want PayOffPut to be virtually copyable.
	//This method makes a copy of itself(PayOffPut) and returns a pointer to the copy.

private:
	double Strike;
};
#endif