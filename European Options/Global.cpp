#define _USE_MATH_DEFINES
#include <cmath>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <sstream>
#include <cmath>
#include <stdlib.h>
#include <vector>
#include <boost/math/distributions/normal.hpp>
#include <boost/math/distributions.hpp>
#include "EuropeanOption.h"
#include "Global.h"
#include "Data.h"

using namespace std;
using namespace boost::math;

double N(double x) // Normal distribution function.
{
	normal_distribution<> myNormal(0.0, 1.0); 
	return cdf(myNormal, x);
}

double n(double x) // Normal pdf function.
{
	normal_distribution<> myNormal(0.0, 1.0); 
	return pdf(myNormal, x);
}


double CallOption(double K, double T, double r, double sig, double S, double b) // Returns Black-Scholes Formula for call option.
{
	double CallPrice;
	double temp = sig * sqrt(T);

	double d1 = ( log(S/K) + (b+ (sig*sig)*0.5) * T )/ temp;
	double d2 = d1 - temp;

	CallPrice = (S * exp((b-r)*T) * N(d1)  - (K * exp(-r * T) * N(d2)));

	return CallPrice;
}

double PutOption(double K, double T, double r, double sig, double S, double b) // Returns Black-Scholes Formula for put option.
{
	double PutPrice;

	double temp = sig * sqrt(T);
	double d1 = ( log(S/K) + (b+ (sig*sig)*0.5 ) * T )/ temp;
	double d2 = d1 - temp;

	PutPrice = (K * exp(-r * T)* N(-d2)) - (S * exp((b-r)*T) * N(-d1));

	return PutPrice;
}

double PutParity(double K, double T, double r, double S, double CallPrice) // Returns Put-Call Partity with Put input.
{
	double PutPrice;

	PutPrice = CallPrice + (K * exp(-r * T)) - S;
	
	return PutPrice;
}

double CallParity(double K, double T, double r, double S, double PutPrice) // Returns Put-Call Partity with Call input.
{
	double CallPrice;

	CallPrice = PutPrice + S - (K * exp(-r * T));

	return CallPrice;

}

double CallDelta(double K, double T, double r, double sig, double S, double b) // Returns CallDelta function.
{
	double tmp = sig * sqrt(T);

	double d1 = (log(S/K) + (b + (sig*sig)*0.5 ) * T )/ tmp;

	return exp((b-r)*T) * N(d1);
}

double PutDelta(double K, double T, double r, double sig, double S, double b) // Returns PutDelta function.
{
	double tmp = sig * sqrt(T);

	double d1 = ( log(S/K) + (b + (sig*sig)*0.5 ) * T )/ tmp;

	return exp((b-r)*T) * (N(d1) - 1.0);
}

double CallGamma(double K, double T, double r, double sig, double S, double b) // Returns CallGamma function.
{
	double tmp = sig * sqrt(T);

	double d1 = ( log(S/K) + (b + (sig*sig)*0.5 ) * T )/ tmp;
	double d2 = d1 - tmp;

	return ( n(d1) * exp((b-r)*T) ) / (S * tmp);
}

double PutGamma(double K, double T, double r, double sig, double S, double b) // Returns PutGamma function.
{
	return CallGamma(K, T, r, sig, S, b);
}

std::vector<double> CallDelta(double K, double T, double r, double sig, double S, double b, double Start, double End, double Interval) // Returns CallDelta mesher array.
{
	vector<double> value;
	
	for (Start; Start <= End; Start = Start+Interval)
	{
		value.push_back(CallDelta(K, T, r, sig, S++, b));
	}
	return value;
}

double CallDeltaApprox(double K, double T, double r, double sig, double S, double b, double h) // Returns CallDelta Approximation.
{
	double VPlus = CallOption(K, T, r, sig, S+h, b);
	double VMinus = CallOption(K, T, r, sig, S-h, b);

	return ( (VPlus) - (VMinus) ) / (2.0 * h);
}

double PutDeltaApprox(double K, double T, double r, double sig, double S, double b, double h) // Returns PutDelta Approximation.
{
	double VPlus = PutOption(K, T, r, sig, S+h, b);
	double VMinus = PutOption(K, T, r, sig, S-h, b);

	return ( (VPlus) - (VMinus) ) / (2.0 * h);
}


double CallGammaApprox(double K, double T, double r, double sig, double S, double b, double h) // Returns CallGamma Approximation.
{
	double V = CallOption(K, T, r, sig, S, b);
	double VPlus = CallOption(K, T, r, sig, S+h, b);
	double VMinus = CallOption(K, T, r, sig, S-h, b);

	return ( (VPlus) - (2*(V)) + (VMinus) ) / (h * h);
}

double PutGammaApprox(double K, double T, double r, double sig, double S, double b, double h) // Returns PutGamma Approximation.
{
	double V = PutOption(K, T, r, sig, S, b);
	double VPlus = PutOption(K, T, r, sig, S+h, b);
	double VMinus = PutOption(K, T, r, sig, S-h, b);

	return ( (VPlus) - (2*(V)) + (VMinus) ) / (h * h);
}