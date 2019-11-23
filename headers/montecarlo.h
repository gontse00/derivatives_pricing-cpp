#ifndef MONTECARLO_H
#define MONTECARLO_H

#include "vanilla.h"
#include "parameters.h"
/*Monte Carlo Fuction Declaration*/ 
double MonteCarlo(
	const VanillaOption& TheOption,
	double Spot,
	const Parameters& vol,
	const Parameters& r,
	unsigned long N);
#endif