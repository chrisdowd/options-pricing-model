#ifndef DATA_hpp
#define DATA_hpp

#define _USE_MATH_DEFINES
#include <cmath>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <sstream>
#include <cmath>
#include <stdlib.h>
#include <vector>

using namespace std;

struct OptionData // OptionData to store option parameters except for the AssetPrice.
{
	double k;
	double T;
	double r;
	double sig;
	double b;
};

#endif