#include "headers/montecarlo.h"
#include "headers/random.h"
#include <cmath>

#if !defined(_MSC_VER)
using namespace std;
#endif

double MonteCarlo(
	const VanillaOption& TheOption,
	double S_O,
	double vol,
	double r,
	unsigned long N)
{
	double T = TheOption.GetExpiry();
	double variance = vol*vol*T;
	double rootVariance = sqrt(variance);
	double itoCorrection = -0.5*variance;
	double movedSpot = S_O*exp(r*T+itoCorrection);
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
	mean += exp(-r*T);
	return mean;
}
