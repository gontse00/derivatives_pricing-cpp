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
	//Pure Virtual Copy Constructor. We want PayOff to be virtually copyable.
	//This method makes a copy of itself(PayOff) and returns a pointer to the copy.
	//it is a pure virtual method so its implemention will be defined in subsequent
	//inherited classes(PayOffCall,PayOffPut,PayOffDoubleDigital, etc.) 
	virtual PayOff* clone() const=0;

private:
};

class PayOffCall:public PayOff
{
public:
	PayOffCall(double Strike_);
	virtual double operator()(double Spot) const;
	virtual ~PayOffCall(){}
	//Virtual Copy Constructor. We want PayOffCall to be virtually copyable.
	//This method makes acopy of itself(PayOffCall) and returns a pointer to the copy.
	virtual PayOff* clone() const;

private:
	double Strike;
};

class PayOffPut:public PayOff
{
public:
	PayOffPut(double Strike_);
	virtual double operator()(double Spot) const;
	virtual ~PayOffPut(){}
    //Virtual Copy Constructor. We want PayOffCall to be virtually copyable.
	//This method makes acopy of itself(PayOffCall) and returns a pointer to the copy.
	virtual PayOff* clone() const;

private:
	double Strike;
};
#endif