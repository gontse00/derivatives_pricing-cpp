#include <iostream>
#include "headers/montecarlo.h"
using namespace std;

int main()
{
	double T = 1;
	double K = 100;
	double S_O = 120;
	double vol = 0.2;
	double r = 0.05;
	unsigned long N = 100000;

	/*
	PayOffCall call(K);
	PayOffPut put(K);

	double resultcall = MonteCarlo(call, T, S_O, vol, r, N);
	double resultput = MonteCarlo(put, T, S_O, vol, r, N);
	cout << resultcall << endl;
	cout << resultput << endl;
	*/
	unsigned long optiontype;
	cout << "Enter 0 for call and 1 for put ";
	cin >> optiontype;

	PayOff *thePayOffPtr;
	if (optiontype==0)
		thePayOffPtr = new PayOffCall(K);
	else
		thePayOffPtr = new PayOffPut(K);

	double result = MonteCarlo(*thePayOffPtr,T,S_O,vol,r,N);
	cout << result << endl;

	double tmp;
	cin >> tmp;
	delete thePayOffPtr;
	return 0;
}