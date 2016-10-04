#define _USE_MATH_DEFINES
#include <cmath>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <sstream>
#include <cmath>
#include <stdlib.h>
#include <vector>
#include "Global.h"
#include "AmericanOption.h"
#include "Data.h"

using namespace std;

int main()
{
	cout << "B.a" << endl << endl << endl;

	cout << "Enter Option Parameters: " << endl;
	double K, S, sig , r, b; // Variables are created to accept option Parameters for user input.
	cout << "K: "; cin >> K;
	cout << "S: "; cin >> S;
	cout << "sig: "; cin >> sig;
	cout << "r: "; cin >> r;
	cout << "b: "; cin >> b;
	
	cout << "Price, put, " << ", S: " << PerpetualPut (K, S, sig, r, b) << endl; // User parameters are entered into global function PerpetualPut to get put value.
	cout << "Price, call, " << ", S: " << PerpetualCall (K, S, sig, r, b); // User parameters are entered into global function PerpetualCall to get call value.

	cout << endl << endl << "B.b" << endl << endl << endl;

	cout << "K = 100, sig = 0.1, r = 0.1, b = 0.02, S = 110 (check C = 18.5035, P = 3.03106)." << endl << endl;

	OptionData Batch;
	Batch.k = (100), Batch.sig = (0.1), Batch.r = (0.1), Batch.b = (0.02), Batch.s = (110); // Parameters are entered into OptionData.

	AmericanOption NewBatch; // NewBatch object is created.

	cout << "Perpetual Call Option Value: " << NewBatch.CallValue(Batch) << endl;
	cout << "Perpetual Put Option Value: " << NewBatch.PutValue(Batch) << endl;

	cout << endl << "B.c" << endl << endl << endl;

	double AssetPrice = 110; // Variable AssetPrice is equal to 110;
	double Start = 0; // Variable Start is equal to 0;
	double End = 20; // Variable End is equal to 20;
	double Interval = 1; // Variable Interval is equal to 1;

	std::vector<double> CallPrice = NewBatch.CallValue(Batch, AssetPrice, Start, End, Interval); // CallPrice vector will return result of CallValue mesher function.

	for (int i = 0; i <= 20; i++) // Iterate through the intervals.
	{
		cout << "Asset Price of $" << AssetPrice+i << " has a Call Option Price of $"; // Cout the current asset price.
		cout << CallPrice[i] << endl; // Return the result for each iteration in the mesh function.
	}

	cout << endl << endl;

	Start = 0; // Reset Start variable
	End = 20; // Reset End variable
	Interval = 1; // Reset Interval variable

	std::vector<double> PutPrice = NewBatch.PutValue(Batch, AssetPrice, Start, End, Interval); // PutPrice vector will return result of PutValue mesher function.

	for (int i = 0; i <= 20; i++) // Iterate through the intervals.
	{
		cout << "Asset Price of $" << AssetPrice+i << " has a Put Option Price of $"; // Cout the current asset price.
		cout << PutPrice[i] << endl; // Return the result for each iteration in the mesh function.
	}

	return 0;

}