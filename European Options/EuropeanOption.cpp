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
#include "Global.h"
#include "Data.h"

using namespace std;

EuropeanOption::EuropeanOption() : m_S(100.00) // Default construtor.
{
}

EuropeanOption::EuropeanOption(const EuropeanOption& source) : m_S(source.m_S) // Copy constructor.
{
}

EuropeanOption::~EuropeanOption() // Default destructor.
{
}

EuropeanOption& EuropeanOption::operator= (const EuropeanOption& source) // Assignment operator.
{
	if(this == &source)
	{
		return *this;
    }
	*this = source;
	return *this;
}

double EuropeanOption::CallValue(OptionData& source) // CallValue to return exact pricing method in global functions.
{
	return CallOption(source.k, source.T, source.r, source.sig, m_S, source.b);
}

double EuropeanOption::PutValue(OptionData& source) // PutValue to return exact pricing method in global functions.
{
	return PutOption(source.k, source.T, source.r, source.sig, m_S, source.b);
}

double EuropeanOption::CallParityPrice(OptionData& source) // PutParityPrice to return Put-Call Parity method in global functions.
{
	return CallParity(source.k, source.T, source.r, m_S, PutPrice);
}

double EuropeanOption::PutParityPrice(OptionData& source) // CallParityPrice to return Put-Call Parity method in global functions.
{
	return PutParity(source.k, source.T, source.r, m_S, CallPrice);
}

ostream& operator << (ostream& os, const EuropeanOption& source) // Send to ostream.
{
	os << "AssetPrice(" << source.m_S << ")" << endl << endl;
    return os;
}

std::vector<double> EuropeanOption::CallValue(OptionData& source, double AssetPrice, double Start, double End, double Interval)  // Mesher function for changing Assetprice of call option.
{
	m_S = (AssetPrice);

	vector<double> value;
	
	for (Start; Start <= End; Start = Start+Interval)
	{
		m_S = (AssetPrice+Start);
		value.push_back(CallOption(source.k, source.T, source.r, source.sig, m_S, source.b));
	}
	return value;
}

std::vector<double> EuropeanOption::PutValue(OptionData& source, double AssetPrice, double Start, double End, double Interval) // Mesher function for changing Assetprice of put option.
{
	m_S = (AssetPrice);

	vector<double> value;
	
	for (Start; Start <= End; Start = Start+Interval)
	{
		m_S = (AssetPrice+Start);
		value.push_back(PutOption(source.k, source.T, source.r, source.sig, m_S, source.b));
	}
	return value;
}

std::vector<double> EuropeanOption::CallValue(OptionData& source, double AssetPrice, double ExpiryTime, double Start, double End, double Interval) // Mesher function for changing ExpiryTime of call option.
{
	m_S = (AssetPrice);

	vector<double> value;
	
	for (Start; Start <= End; Start = Start+Interval)
	{
		double T = (ExpiryTime+Start);
		value.push_back(CallOption(source.k, T, source.r, source.sig, m_S, source.b));
	}
	return value;
}

std::vector<double> EuropeanOption::PutValue(OptionData& source, double AssetPrice, double ExpiryTime, double Start, double End, double Interval) // Mesher function for changing ExpiryTime of put option.
{
	m_S = (AssetPrice);

	vector<double> value;
	
	for (Start; Start <= End; Start = Start+Interval)
	{
		double T = (ExpiryTime+Start);
		value.push_back(PutOption(source.k, T, source.r, source.sig, m_S, source.b));
	}
	return value;
}

std::vector<double> EuropeanOption::CallValue(OptionData& source, double AssetPrice, double ExpiryTime, double Volatility, double Start, double End, double Interval) // Mesher function for changing Volatility of call option.
{
	m_S = (AssetPrice);
	double T = ExpiryTime;

	vector<double> value;
	
	for (Start; Start <= End; Start = Start+Interval)
	{
		double sig = (Volatility + Start);
		value.push_back(CallOption(source.k, T, source.r, sig, m_S, source.b));
	}
	return value;
}

std::vector<double> EuropeanOption::PutValue(OptionData& source, double AssetPrice, double ExpiryTime, double Volatility, double Start, double End, double Interval) // Mesher function for changing Volatility of put option.
{
	m_S = (AssetPrice);
	double T = ExpiryTime;

	vector<double> value;
	
	for (Start; Start <= End; Start = Start+Interval)
	{
		double sig = (Volatility + Start);
		value.push_back(PutOption(source.k, T, source.r, sig, m_S, source.b));
	}
	return value;
}