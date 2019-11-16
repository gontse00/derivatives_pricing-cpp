#ifndef VANILLA_1_H
#define VANILLA_1_H

#include "payoffbridge.h" 
/*#include "payoff.h"
VanillaOption Class without PayOffBridge
class VanillaOption
{
public:
	VanillaOption(const PayOff& ThePayOff_, double Expiry);
	//Constructor with params()
    VanillaOption(const VanillaOption& original);
    //Copy constructor.
    VanillaOption& operator=(const VanillaOption& original);
    //Assignment Operator member
    ~VanillaOption();
    //Destructor
    //Copy Constructor, Assingment Operator and Destructo make up the rule of 3,
    //Rule of three says that if one of the three is needed then all three are needed.

	double GetExpiry() const;
	double OptionPayOff(double Spot) const;

private:
	double Expiry;
	PayOff* ThePayOffPtr;
};
*/

class VanillaOption
{
public:
	VanillaOption(const PayOffBridge& ThePayOff_, double Expiry);
	double OptionPayOff(double Spot) const;
	double GetExpiry() const;

private:
	double Expiry;
	PayOffBridge ThePayOff;
};
#endif

