#ifndef EUROPEANOPTION_hpp
#define EUROPEANOPTION_hpp

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

class EuropeanOption
{
private:
	double m_S; // Private data member for AssetPrice.
	double CallPrice; // Private data member for Price of a Call Option.
	double PutPrice; // Private data member for Price of a Put Option.

public:
	EuropeanOption(); // Default construtor.
	EuropeanOption(const EuropeanOption& source); // Copy constructor.
	~EuropeanOption(); // Default destructor.

	void S(double x) {m_S = x;}; // Set Asset Price.

	void callprice(double x) {CallPrice = x;}; // Set Call Price
	void putprice(double x) {PutPrice = x;}; // Set Put Price

	EuropeanOption& operator = (const EuropeanOption& source); // Assignment operator.

	double CallValue(OptionData& source); // CallValue to return exact pricing method in global functions.
	double PutValue(OptionData& source); // PutValue to return exact pricing method in global functions.

	double PutParityPrice(OptionData& source); // PutParityPrice to return Put-Call Parity method in global functions.
	double CallParityPrice(OptionData& source); // CallParityPrice to return Put-Call Parity method in global functions.

	friend ostream& operator << (ostream& os, const EuropeanOption& p); // Send to ostream.

	std::vector<double> CallValue(OptionData& source, double AssetPrice, double Start, double End, double Interval); // Mesher function for changing Assetprice of call option.
	std::vector<double> PutValue(OptionData& source, double AssetPrice, double Start, double End, double Interval); // Mesher function for changing Assetprice of put option.

	std::vector<double> CallValue(OptionData& source, double AssetPrice, double ExpiryTime, double Start, double End, double Interval); // Mesher function for changing ExpiryTime of call option.
	std::vector<double> PutValue(OptionData& source, double AssetPrice, double ExpiryTime, double Start, double End, double Interval); // Mesher function for changing ExpiryTime of put option.

	std::vector<double> CallValue(OptionData& source, double AssetPrice, double ExpiryTime, double Volatility, double Start, double End, double Interval); // Mesher function for changing Volatility of call option.
	std::vector<double> PutValue(OptionData& source, double AssetPrice, double ExpiryTime, double Volatility, double Start, double End, double Interval); // Mesher function for changing Volatility of put option.

};

#endif