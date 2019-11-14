#include <iostream>
#include "headers/montecarlo.h"
using namespace std;

int main()
{
	double T = 1;
	double K = 100;
	double S_O = 200;
	double vol = 0.2;
	double r = 0.05;
	unsigned long N = 100000;

	PayOff call(K,PayOff::call);

	double result = MonteCarlo(call, T, S_O, vol, r, N);
	cout << result << endl;
	return 0;
}