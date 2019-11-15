#ifndef VANILLA_1_H
#define VANILLA_1_H

#include "payoff.h"

class VanillaOption
{
public:
	VanillaOption(const PayOff& ThePayOff_, double Expiry);
    VanillaOption(const VanillaOption& original);
    VanillaOption& operator=(const VanillaOption& original);
    ~VanillaOption();

	double GetExpiry() const;
	double OptionPayOff(double Spot) const;

private:
	double Expiry;
	PayOff* ThePayOffPtr;
};
#endif

