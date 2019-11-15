#ifndef MONTECARLO_H
#define MONTECARLO_H

#include "vanilla.h"
/*Monte Carlo Fuction Declaration*/ 
double MonteCarlo(
	const VanillaOption& TheOption,
	double S_O,
	double vol,
	double r,
	unsigned long N);
#endif