#include <iostream>
#include "headers/montecarlo.h"
#include "headers/doubledigital.h"
#include "headers/vanilla.h"
using namespace std;

int main()
{
	/*
	double T = 1;
	double K = 100;
	double S_O = 120;
	double vol = 0.2;
	double r = 0.05;
	unsigned long N = 100000;

	
	PayOffCall call(K);
	PayOffPut put(K);

	double resultcall = MonteCarlo(call, T, S_O, vol, r, N);
	double resultput = MonteCarlo(put, T, S_O, vol, r, N);
	cout << resultcall << endl;
	cout << resultput << endl;
	*/

	double T = 1;
	double Low = 100;
	double High = 120;
	double S_O = 110;
	double vol = 0.2;
	double r = 0.05;
	unsigned long N = 100000;

	PayOffDoubleDigital thePayOff(Low, High);
	VanillaOption theOption(thePayOff, T);
	double result = MonteCarlo(theOption,S_O,vol,r,N);
	cout << result << endl;

	double tmp;
	cin >> tmp;
	return 0;
}