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
#include "AmericanOption.h"

using namespace std;

double PerpetualCall (double K, double S, double sig, double r, double b); // Function callculates perpetual American Call options.
double PerpetualPut (double K, double S, double sig, double r, double b); // Function callculates perpetual American Put options.

#endif
