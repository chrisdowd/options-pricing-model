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
#include "EuropeanOption.h"
#include "Data.h"

using namespace std;

int main()
{
	cout << "Black-Scholes Test" << endl << endl << endl;

	cout << "Batch 1: T = 0.25, K = 65, sig = 0.30, r = 0.08, S = 60 (then C = 2.13293, P = 5.84584)." << endl << endl;
	
	EuropeanOption Batch1; OptionData Batcha; // Create EuropeanOption and OptionData objects.
	Batcha.T = .25, Batcha.k = 65, Batcha.sig = .30, Batcha.r = (.08), Batch1.S(60), Batcha.b = (.08); // Input Batch 1 values into OptionData and S setter.

	cout << "Batch 1 Has a Call Option Price of: $" << Batch1.CallValue(Batcha) << endl;
	cout << "Batch 1 Has a Put Option Price of: $" << Batch1.PutValue(Batcha) << endl << endl;
	
	cout << "Batch 2: T = 1.0, K = 100, sig = 0.2, r = 0.0, S = 100 (then C = 7.96632, P = 7.96632)." << endl << endl;

	EuropeanOption Batch2; OptionData Batchb; // Create EuropeanOption and OptionData objects.
	Batchb.T = (1.0), Batchb.k = (100), Batchb.sig = (.2), Batchb.r = (0.0), Batch2.S(100), Batchb.b = (0.0); // Input Batch 2 values into OptionData and S setter.

	cout << "Batch 2 Has a Call Option Price of: $" << Batch2.CallValue(Batchb) << endl;
	cout << "Batch 2 Has a Put Option Price of: $" << Batch2.PutValue(Batchb) << endl << endl;

	cout << "Batch 3: T = 1.0, K = 10, sig = 0.50, r = 0.12, S = 5 (C = 0.204121, P = 4.0733)." << endl << endl;

	EuropeanOption Batch3; OptionData Batchc; // Create EuropeanOption and OptionData objects.
	Batchc.T = (1), Batchc.k = (10), Batchc.sig = (.50), Batchc.r = (.12), Batch3.S(5), Batchc.b = (.12); // Input Batch 3 values into OptionData and S setter.

	cout << "Batch 3 Has a Call Option Price of: $" << Batch3.CallValue(Batchc) << endl;
	cout << "Batch 3 Has a Put Option Price of: $" << Batch3.PutValue(Batchc) << endl << endl;

	cout << "Batch 4: T = 30.0, K = 100.0, sig = 0.30, r = 0.08, S = 100.0 (C = 92.1749, P = 1.24651)." << endl << endl;

	EuropeanOption Batch4; OptionData Batchd; // Create EuropeanOption and OptionData objects.
	Batchd.T = (30), Batchd.k = (100), Batchd.sig = (.30), Batchd.r = (.08), Batch4.S(100), Batchd.b = (.08); // Input Batch 4 values into OptionData and S setter.

	cout << "Batch 4 Has a Call Option Price of: $" << Batch4.CallValue(Batchd) << endl;
	cout << "Batch 4 Has a Put Option Price of: $" << Batch4.PutValue(Batchd) << endl << endl << endl;

	cout << "Put-Call Parity Test" << endl << endl << endl;

	cout << "Batch 1: T = 0.25, K = 65, sig = 0.30, r = 0.08, S = 60 (then C = 2.13293, P = 5.84584)." << endl << endl;

	Batch1.callprice(2.13293), Batch1.putprice(5.84584); // Set Call and Put Values for use in Put-Call Parity.
	cout << "Batch 1 Has a Put-Call Parity Call Option Price of: $" << Batch1.CallParityPrice(Batcha) << endl;
	cout << "Batch 1 Has a Put-Call Parity Put Option Price of: $" << Batch1.PutParityPrice(Batcha) << endl << endl;

	cout << "Batch 2: T = 1.0, K = 100, sig = 0.2, r = 0.0, S = 100 (then C = 7.96632, P = 7.96632)." << endl << endl;
	
	Batch2.callprice(7.96632), Batch2.putprice(7.96632); // Set Call and Put Values for use in Put-Call Parity.
	cout << "Batch 2 Has a Put-Call Parity Call Option Price of: $" << Batch2.CallParityPrice(Batchb) << endl;
	cout << "Batch 2 Has a Put-Call Parity Put Option Price of: $" << Batch2.PutParityPrice(Batchb) << endl << endl;

	cout << "Batch 3: T = 1.0, K = 10, sig = 0.50, r = 0.12, S = 5 (C = 0.204121, P = 4.0733)." << endl << endl;
	
	Batch3.callprice(0.204121), Batch3.putprice(4.0733); // Set Call and Put Values for use in Put-Call Parity.
	cout << "Batch 3 Has a Put-Call Parity Call Option Price of: $" << Batch3.CallParityPrice(Batchc) << endl;
	cout << "Batch 3 Has a Put-Call Parity Put Option Price of: $" << Batch3.PutParityPrice(Batchc) << endl << endl;

	cout << "Batch 4: T = 30.0, K = 100.0, sig = 0.30, r = 0.08, S = 100.0 (C = 92.1749, P = 1.24651)." << endl << endl;
	
	Batch4.callprice(92.1749), Batch4.putprice(1.24651); // Set Call and Put Values for use in Put-Call Parity.
	cout << "Batch 4 Has a Put-Call Parity Call Option Price of: $" << Batch4.CallParityPrice(Batchd) << endl;
	cout << "Batch 4 Has a Put-Call Parity Put Option Price of: $" << Batch4.PutParityPrice(Batchd) << endl << endl << endl;

	cout << "A.1.d" << endl << endl << endl;

	EuropeanOption Batch5; OptionData Batche; // Create EuropeanOption and OptionData objects.
	Batche.T = (1), Batche.k = (100), Batche.sig = (.2), Batche.r = (.00), Batche.b = (.00); // Input Batch 5 values into OptionData.

	double AssetPrice = 100; // Declare variable to set Asset price.
	
	double Start = 0; // Declare variable to use begin vector.
	double End = 20; // Declare variable to use to end vector.
	double Interval = 1; // Declare variable to measure intervals between values in vecor.
	
	std::vector<double> CallPrice = Batch5.CallValue(Batche, AssetPrice, Start, End, Interval); // CallPrice vector will return result of CallValue mesher function.

	for (int i = 0; i <= 20; i++) // Iterate through the intervals.
	{
		cout << "Asset Price of $" << AssetPrice+i << " has a Call Option Price of $"; // Cout the current asset price.
		cout << CallPrice[i] << endl; // Return the result for each iteration in the mesh function.
	}

	cout << endl << endl;

	Start = 0; // Reset Start variable
	End = 20; // Reset End variable
	Interval = 1; // Reset Interval variable

	std::vector<double> PutPrice = Batch5.PutValue(Batche, AssetPrice, Start, End, Interval); // PutPrice vector will return result of PutValue mesher function.

	for (int i = 0; i <= 20; i++) // Iterate through the intervals.
	{
		cout << "Asset Price of $" << AssetPrice+i << " has a Call Option Price of $"; // Cout the current asset price.
		cout << PutPrice[i] << endl; // Return the result for each iteration in the mesh function.
	}

	cout << endl << endl << "A.1.e.i" << endl << endl << endl;

	AssetPrice = 100; // Reset AssetPrice variable
	double ExpiryTime = 1; // Declare variable for time till expiration
	Start = 0;  // Reset Start variable
	End = 10; // Reset End variable
	Interval = 1; // Reset Interval variable

	std::vector<double> ExpiryCallPrice = Batch5.CallValue(Batche, AssetPrice, ExpiryTime, Start, End, Interval); // ExpiryCallPrice vector will return result of CallValue mesher function.

	for (int i = 0; i < 10; i++) // Iterate through the intervals.
	{
		cout << "ExpiryTime of " << ExpiryTime+i << " has a Call Option Price of $"; // Cout the current expiry time.
		cout << ExpiryCallPrice[i] << endl; // Return the result for each iteration in the mesh function.
	}

	cout << endl << endl;

	ExpiryTime = 1; // Reset variable for time till expiration
	Start = 0; // Reset Start variable
	End = 10; // Reset End variable
	Interval = 1; // Reset Interval variable

	std::vector<double> ExpiryPutPrice = Batch5.PutValue(Batche, AssetPrice, ExpiryTime, Start, End, Interval); // ExpiryPutPrice vector will return result of CallValue mesher function.

	for (int i = 0; i < 10; i++) // Iterate through the intervals.
	{
		cout << "ExpiryTime of " << ExpiryTime+i << " has a Put Option Price of $"; // Cout the current expiry time.
		cout << ExpiryPutPrice[i] << endl; // Return the result for each iteration in the mesh function.
	}

	cout << endl << endl << "A.1.e.ii" << endl << endl << endl;

	ExpiryTime = 1; // Reset variable for time till expiration
	Start = 0; // Reset Start variable
	End = 1; // Reset End variable
	Interval = .1; // Reset Interval variable
	double Volatility = .05; // Declare variable for Volatility.

	std::vector<double> VolatilityCallPrice = Batch5.CallValue(Batche, AssetPrice, ExpiryTime, Volatility, Start, End, Interval); // VolatilityCallPrice vector will return result of CallValue mesher function.

	for (int i = 0; i <= 9; i++) // Iterate through the intervals.
	{
		cout << "Volatility of " << Volatility << " has a Call Option Price of $"; // Cout the current expiry time.
		cout << VolatilityCallPrice[i] << endl; // Return the result for each iteration in the mesh function.
		Volatility = Volatility + Interval;
	}

	cout << endl << endl;

	Start = 0; // Reset Start variable
	End = 1; // Reset End variable
	Interval = .1; // Reset Interval variable
	Volatility = .05; // Declare variable for Volatility.

	std::vector<double> VolatilityPutPrice = Batch5.PutValue(Batche, AssetPrice, ExpiryTime, Volatility, Start, End, Interval); // VolatilityPutPrice vector will return result of CallValue mesher function.

	for (int i = 0; i <= 9; i++) // Iterate through the intervals.
	{
		cout << "Volatility of " << Volatility << " has a Put Option Price of $"; // Cout the current expiry time.
		cout << VolatilityPutPrice[i] << endl; // Return the result for each iteration in the mesh function.
		Volatility = Volatility + Interval;
	}

	cout << endl << endl << "A.2.a" << endl << endl << endl;

	cout << "Data Set: K = 100, S = 105, T = 0.5, r = 0.1, b = 0 and sig = 0.36" << endl << endl;

	cout << "CallGama: " << CallGamma(100, 0.5, 0.1, 0.36, 105, 0) << endl; // CallGamma function with new Data Set inputs.
	cout << "PutGamma: " << PutGamma(100, 0.5, 0.1, 0.36, 105, 0) << endl; // PutGamma function with new Data Set inputs.
	cout << "CallDelta: " << CallDelta(100, 0.5, 0.1, 0.36, 105, 0) << endl; // CallDelta function with new Data Set inputs.
	cout << "PutDelta: " << PutDelta(100, 0.5, 0.1, 0.36, 105, 0) << endl << endl; // PutDelta function with new Data Set inputs.

	cout << endl << "A.2.b" << endl << endl << endl;

	AssetPrice = 105; // Reset AssetPrice variable
	Start = 0; // Reset Start variable
	End = 20; // Reset End variable
	Interval = 1; // Reset Interval variable
	
	std::vector<double> CallDeltaPrice = CallDelta(100, 0.5, 0.1, 0.36, 105, 0, Start, End, Interval); // CallDeltaPrice vector will return result of CallDelta mesher function.

	for (int i = 0; i <= 20; i++) // Iterate through the intervals.
	{
		cout << "Asset Price of $" << AssetPrice+i << " has a CallDelta of: ";
		cout << CallDeltaPrice[i] << endl; // Return the result for each iteration in the mesh function.
	}

	cout << endl << endl << "A.2.c" << endl << endl << endl;

	cout << "CallDeltaApprox: " << CallDeltaApprox(100, 0.5, 0.1, 0.36, 105, 0, .1) << endl; // Outputs value for approximations of CallDelta.
	cout << "CallDeltaApprox: " << CallDeltaApprox(100, 0.5, 0.1, 0.36, 105, 0, .3) << endl;
	cout << "CallDeltaApprox: " << CallDeltaApprox(100, 0.5, 0.1, 0.36, 105, 0, .7) << endl;
	cout << "CallDeltaApprox: " << CallDeltaApprox(100, 0.5, 0.1, 0.36, 105, 0, 1) << endl;
	cout << "CallDeltaApprox: " << CallDeltaApprox(100, 0.5, 0.1, 0.36, 105, 0, 5) << endl;
	cout << "CallDeltaApprox: " << CallDeltaApprox(100, 0.5, 0.1, 0.36, 105, 0, 10) << endl << endl;

	cout << "PutDeltaApprox: " << PutDeltaApprox(100, 0.5, 0.1, 0.36, 105, 0, .1) << endl; // Outputs value for approximations of PutDelta.
	cout << "PutDeltaApprox: " << PutDeltaApprox(100, 0.5, 0.1, 0.36, 105, 0, .3) << endl;
	cout << "PutDeltaApprox: " << PutDeltaApprox(100, 0.5, 0.1, 0.36, 105, 0, .7) << endl;
	cout << "PutDeltaApprox: " << PutDeltaApprox(100, 0.5, 0.1, 0.36, 105, 0, 1) << endl;
	cout << "PutDeltaApprox: " << PutDeltaApprox(100, 0.5, 0.1, 0.36, 105, 0, 5) << endl;
	cout << "PutDeltaApprox: " << PutDeltaApprox(100, 0.5, 0.1, 0.36, 105, 0, 10) << endl << endl;
	
	cout << "CallGammaApprox: " << CallGammaApprox(100, 0.5, 0.1, 0.36, 105, 0, .1) << endl; // Outputs value for approximations of CallGamma.
	cout << "CallGammaApprox: " << CallGammaApprox(100, 0.5, 0.1, 0.36, 105, 0, .3) << endl;
	cout << "CallGammaApprox: " << CallGammaApprox(100, 0.5, 0.1, 0.36, 105, 0, .7) << endl;
	cout << "CallGammaApprox: " << CallGammaApprox(100, 0.5, 0.1, 0.36, 105, 0, 1) << endl;
	cout << "CallGammaApprox: " << CallGammaApprox(100, 0.5, 0.1, 0.36, 105, 0, 5) << endl;
	cout << "CallGammaApprox: " << CallGammaApprox(100, 0.5, 0.1, 0.36, 105, 0, 10) << endl << endl;

	cout << "PutGammaApprox: " << PutGammaApprox(100, 0.5, 0.1, 0.36, 105, 0, .1) << endl; // Outputs value for approximations of PutGamma.
	cout << "PutGammaApprox: " << PutGammaApprox(100, 0.5, 0.1, 0.36, 105, 0, .3) << endl;
	cout << "PutGammaApprox: " << PutGammaApprox(100, 0.5, 0.1, 0.36, 105, 0, .7) << endl;
	cout << "PutGammaApprox: " << PutGammaApprox(100, 0.5, 0.1, 0.36, 105, 0, 1) << endl;
	cout << "PutGammaApprox: " << PutGammaApprox(100, 0.5, 0.1, 0.36, 105, 0, 5) << endl;
	cout << "PutGammaApprox: " << PutGammaApprox(100, 0.5, 0.1, 0.36, 105, 0, 10) << endl << endl;

	return 0;

}