#include <iostream>
#include "headers/montecarlo.h"
#include "headers/doubledigital.h"
#include "headers/vanilla.h"
#include "headers/parameters.h"
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

	double T = 1.0;
	double K = 110;
	double Low = 100;
	double High = 120;
	double Spot = 110;
	ParametersConstant VolParam(0.2);
	ParametersConstant rParam(0.05);
	unsigned long N = 100000;

	PayOffDoubleDigital thePayOffDoubleDigital(Low, High);
	PayOffCall thePayOffCall(K);
	PayOffPut thepayOffPut(K);

	VanillaOption theOption1(thePayOffDoubleDigital, T);
	VanillaOption theOption2(thePayOffCall, T);
	VanillaOption theOption3(thepayOffPut, T);

	double result1 = MonteCarlo(theOption1,Spot,VolParam,rParam,N);
	double result2 = MonteCarlo(theOption2,Spot,VolParam,rParam,N);
	double result3 = MonteCarlo(theOption3,Spot,VolParam,rParam,N);
	
	cout << "The Double Digital Price :"<< result1 << endl;
	cout << "The Call Price           :"<< result2 << endl;
	cout << "The Put Price            :"<< result3 << endl;

	double tmp;
	cin >> tmp;
	return 0;
}