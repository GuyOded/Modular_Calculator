/*
 * basic_functions.cpp
 *
 *  Created on: Jan 28, 2016
 *      Author: guy
 */
#include <string>
#include <sstream>
#include <limits>
#include <iostream>

namespace utility
{
	/**
	 * bool is_str_double(std::string str)
	 *
	 * validates if the given string can be correctly converted to double
	 *
	 * @param str-the string parameter
	 * @return
	 */
	bool is_str_double(std::string str)
	{
		if(str.empty())
			return false;

		bool read_dot = false;//dot as in decimal point
		std::string::size_type i = 0;
		if(str[i] == '-')
			i++;

		//check that the first character is a digit
		if(str[i] > '9' || str[i] < '0')
			return false;

		for(; i < str.size(); ++i)
		{
			//if encountered a second decimal point return false
			if(read_dot && str[i] == '.')
				return false;
			else if(!read_dot && str[i] == '.')
			{
				read_dot = true;
				continue;
			}
			if(str[i] > '9' || str[i] < '0')
				return false;
		}

		return true;
	}

	/**
	 * bool is_overflowed(double d)
	 *
	 * check if the given double is in overflow state
	 *
	 * @param d - a double variable
	 * @return false if d is not overflowed true if it is
	 */
	bool is_overflowed(double d)
	{
		return d == std::numeric_limits<double>::infinity();
	}

	/**
	 * double stod(std::string str) - I couldn't find a standard function in cmath
	 *                                for some reason.
	 *
	 * converts the given string into double
	 *
	 * @param str-the string that is converted to double
	 * @return the converted string in double form
	 */
	double stod(std::string str)
	{
		std::istringstream stm(str);
		double dbl;
		stm >> dbl;
		return dbl;
	}
}
