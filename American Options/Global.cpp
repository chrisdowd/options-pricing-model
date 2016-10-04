#define _USE_MATH_DEFINES
#include <cmath>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <sstream>
#include <cmath>
#include <stdlib.h>
#include <vector>
#include "AmericanOption.h"
#include "Global.h"
#include "Data.h"

using namespace std;

double PerpetualCall (double K, double S, double sig, double r, double b) // Function callculates perpetual American Call options.
{
	double sig2 = sig*sig;
	double fac = b/sig2 - 0.5; fac *= fac;
	double y1 = 0.5 - b/sig2 + sqrt(fac + 2.0*r/sig2);
	
	if (1.0 == y1)
		return S;
	
	double fac2 = ((y1 - 1.0)*S) / (y1 * K);
	double c = K * pow(fac2, y1) / (y1 - 1.0);
	
	return c;
}

double PerpetualPut (double K, double S, double sig, double r, double b) // Function callculates perpetual American Put options.
{
	double sig2 = sig*sig;
	double fac = b/sig2 - 0.5; fac *= fac;
	double y2 = 0.5 - b/sig2 - sqrt(fac + 2.0*r/sig2);
	
	if (0.0 == y2)
		return S;
	
	double fac2 = ((y2 - 1.0)*S) / (y2 * K);
	double p = K * pow(fac2, y2) / (1.0 - y2);
	
	return p;
}