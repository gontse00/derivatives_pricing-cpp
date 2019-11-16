#include "headers/vanilla.h"
/*
VanillaOption::VanillaOption(const PayOff& ThePayOff_, double Expiry_):Expiry(Expiry_)
{
	ThePayOffPtr = ThePayOff_.clone();
}

double VanillaOption::GetExpiry() const
{
	return Expiry;
}

double VanillaOption::OptionPayOff(double Spot) const
{
	return (*ThePayOffPtr)(Spot);
}

VanillaOption::VanillaOption(const VanillaOption& original)
{
	Expiry = original.Expiry;
	ThePayOffPtr = original.ThePayOffPtr->clone();

	//This copy constructor method copies the value of Expiry from the original into the copy.
	//For the poiter, we call the clone method generating a copy of the PayOff object which we 
	//store in the copy's pointer. The data of original and its copy with not be equal since the 
	//pointers will have different values. We do nt want thePayOffPtr to be using the original 
	//Payoff object. 
}

VanillaOption& VanillaOption::operator=(const VanillaOption& original)
{
	if (this!=&original)
	{
		Expiry = original.Expiry;
		delete ThePayOffPtr;
		ThePayOffPtr = original.ThePayOffPtr->clone();
	}
	return *this;
	//The 1st thing to notice about the assignment operator is that the return type is of 
	//VanillaOption&. The 2nd point is that the first thing we do is check against self-assignment.
	//The rest of the assignment operator is a combination of destructor and copy constructor.
	//The destructor is needed to get rid of the PayOff object which was owned before. The constructor
	//part clones the pointed to object so the new version of the assignment part has its own copy 
	//of the object as desired. 
}

VanillaOption::~VanillaOption()
{
	delete ThePayOffPtr;
}
*/

VanillaOption::VanillaOption(const PayOffBridge& ThePayOff_, double Expiry_):ThePayOff(ThePayOff_),Expiry(Expiry_)
{

}

double VanillaOption::GetExpiry() const
{
	return Expiry;
}

double VanillaOption::OptionPayOff(double Spot) const
{
	return ThePayOff(Spot);
}