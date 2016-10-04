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
#include "AmericanOption.h"
#include "Global.h"
#include "Data.h"

using namespace std;
using namespace boost::math;

AmericanOption::AmericanOption() : m_S(100.00) // Default construtor.
{
}

AmericanOption::AmericanOption(const AmericanOption& source) : m_S(source.m_S) // Copy constructor.
{
}

AmericanOption::~AmericanOption() // Default destructor.
{
}

double AmericanOption::CallValue(OptionData& source) // CallValue to return perpetual call function in global functions.
{
	return PerpetualCall(source.k, source.s, source.sig, source.r, source.b);
}

double AmericanOption::PutValue(OptionData& source) // PutValue to return perpetual put function in global functions.
{
	return PerpetualPut(source.k, source.s, source.sig, source.r, source.b);
}

std::vector<double> AmericanOption::CallValue(OptionData& source, double AssetPrice, double Start, double End, double Interval)  // Mesher function for changing Assetprice of call option.
{
	m_S = (AssetPrice);

	vector<double> value;
	
	for (Start; Start <= End; Start = Start+Interval)
	{
		m_S = (AssetPrice+Start);
		value.push_back(PerpetualCall(source.k, m_S, source.sig, source.r, source.b));
	}
	return value;
}

std::vector<double> AmericanOption::PutValue(OptionData& source, double AssetPrice, double Start, double End, double Interval) // Mesher function for changing Assetprice of put option.
{
	m_S = (AssetPrice);

	vector<double> value;
	
	for (Start; Start <= End; Start = Start+Interval)
	{
		m_S = (AssetPrice+Start);
		value.push_back(PerpetualPut(source.k, m_S, source.sig, source.r, source.b));
	}
	return value;
}

AmericanOption& AmericanOption::operator= (const AmericanOption& source) // Assignment operator.
{
	if(this == &source)
	{
		return *this;
    }
	*this = source;
	return *this;
}

ostream& operator << (ostream& os, const AmericanOption& source) // Send to ostream.
{
	os << "AssetPrice(" << source.m_S << ")" << endl << endl;
    return os;
}

