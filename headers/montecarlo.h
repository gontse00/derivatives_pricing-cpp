#ifndef MONTECARLO_H
#define MONTECARLO_H

#include "payoff.h"
/*Monte Carlo Fuction Declaration*/ 
double MonteCarlo(
	const PayOff& thePayOff,
	double T,
	double S_O,
	double vol,
	double r,
	unsigned long N);
#endif