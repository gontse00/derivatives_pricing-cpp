#include <iostream>
#include "headers/montecarlo.h"
using namespace std;

int main()
{
	double T = 1;
	double K = 100;
	double S_O = 100;
	double vol = 0.2;
	double r = 0.05;
	unsigned long N = 100000;

	PayOffCall call(K);
	PayOffPut put(K);

	double resultcall = MonteCarlo(call, T, S_O, vol, r, N);
	double resultput = MonteCarlo(put, T, S_O, vol, r, N);
	cout << resultcall << endl;
	cout << resultput << endl;
	return 0;
}