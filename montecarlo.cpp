#include "headers/montecarlo.h"
#include "headers/parameters.h"
#include "headers/random.h"
#include <cmath>

#if !defined(_MSC_VER)
using namespace std;
#endif

double MonteCarlo(
	const VanillaOption& TheOption,
	double Spot,
	const Parameters& Vol,
	const Parameters& r,
	unsigned long N)
{
	double T = TheOption.GetExpiry();
	double variance = Vol.IntegralSquare(0.0, T);
	double rootVariance = sqrt(variance);
	double itoCorrection = -0.5*variance;
	double movedSpot = Spot*exp(r.Integral(0.0,T)+itoCorrection);
	double thisSpot;
	double runningSum = 0;

	for (unsigned long i=0; i<N; i++)
	{
		double thisGaussian = GetOneGaussianByBoxMuller();
		thisSpot = movedSpot*exp(rootVariance*thisGaussian);
		double thisPayOff = TheOption.OptionPayOff(thisSpot);
		runningSum += thisPayOff;
	}
	double mean = runningSum/N;
	mean += exp(-r.Integral(0.0,T));
	return mean;
}
