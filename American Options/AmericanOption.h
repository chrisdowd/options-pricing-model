#ifndef AMERICANOPTION_hpp
#define AMERICANOPTION_hpp

#define _USE_MATH_DEFINES
#include <cmath>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <sstream>
#include <cmath>
#include <stdlib.h>
#include <vector>
#include "Data.h"

using namespace std;

class AmericanOption
{
private:
	double m_S; // Private data member for AssetPrice.
	double CallPrice; // Private data member for Price of a Call Option.
	double PutPrice; // Private data member for Price of a Put Option.

public:
	AmericanOption(); // Default construtor.
	AmericanOption(const AmericanOption& source); // Copy constructor.
	~AmericanOption(); // Default destructor.

	double CallValue(OptionData& source); // CallValue to return perpetual call function in global functions.
	double PutValue(OptionData& source); // PutValue to return perpetual put function in global functions.

	std::vector<double> CallValue(OptionData& source, double AssetPrice, double Start, double End, double Interval); // Mesher function for changing Assetprice of call option.
	std::vector<double> PutValue(OptionData& source, double AssetPrice, double Start, double End, double Interval); // Mesher function for changing Assetprice of put option.
	
	AmericanOption& operator = (const AmericanOption& source); // Assignment operator.
	friend ostream& operator << (ostream& os, const AmericanOption& p); // Send to ostream.
};

#endif