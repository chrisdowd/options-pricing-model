#ifndef GLOBAL_hpp
#define GLOBAL_hpp

#define _USE_MATH_DEFINES
#include <cmath>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <sstream>
#include <cmath>
#include <stdlib.h>
#include <vector>
#include "EuropeanOption.h"

using namespace std;

double N(double x); // Normal distribution function.
double n(double x); // Normal pdf function.
double CallOption(double K, double T, double r, double sig, double S, double b); // Returns Black-Scholes Formula for call option.
double PutOption(double K, double T, double r, double sig, double S, double b); // Returns Black-Scholes Formula for put option.

double PutParity(double K, double T, double r, double S, double CallPrice); // Returns Put-Call Partity with Put input.
double CallParity(double K, double T, double r, double S, double PutPrice); // Returns Put-Call Partity with Call input.

double CallDelta(double K, double T, double r, double sig, double S, double b); // Returns CallDelta function.
double PutDelta(double K, double T, double r, double sig, double S, double b); // Returns PutDelta function.
double CallGamma(double K, double T, double r, double sig, double S, double b); // Returns CallGamma function.
double PutGamma(double K, double T, double r, double sig, double S, double b); // Returns PutGamma function.

std::vector<double> CallDelta(double K, double T, double r, double sig, double S, double b, double Start, double End, double Interval); // Returns CallDelta mesher array.

double CallDeltaApprox(double K, double T, double r, double sig, double S, double b, double h); // Returns CallDelta Approximation.
double PutDeltaApprox(double K, double T, double r, double sig, double S, double b, double h); // Returns PutDelta Approximation.
double CallGammaApprox(double K, double T, double r, double sig, double S, double b, double h); // Returns CallGamma Approximation.
double PutGammaApprox(double K, double T, double r, double sig, double S, double b, double h); // Returns PutGamma Approximation.

#endif
