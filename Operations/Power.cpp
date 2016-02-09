/*
 * Power.cpp
 *
 *  Created on: Feb 1, 2016
 *      Author: guy
 */

#include "Power.h"
#include <string>
#include <vector>
#include <cmath>
#include "../Exceptions/Exceptions.h"
#include "../utility.h"

const std::string Power::DEFAULT_OP_STRING = "^";

Power::Power(std::string op_string) : m_op_string(op_string) {
}

Power::~Power() {
}

/**
 * virtual bool supportsOperation(std::string op_string)
 *
 * checks if the given string is supported by the operation
 *
 * @param op_string - a given string parameter
 * @return true if the given string equals to the operation string
 */
bool Power::supportsOperation(std::string op_string)
{
	return m_op_string == op_string;
}

/**
 * virtual int requiredParameters()
 *
 *@return the amount of parameters required by the operation
 */
int Power::requiredParameters()
{
	return Power::REQUIRED_PARAMS;
}

/**
 * virtual double calcResult(double curr_val,
 *							  std::vector<std::string> params)
 *
 * calculates the result of the operation given a current value unless an exception
 * is thrown in the process.
 *
 * @param curr_val-the current value thats held by the calculator
 * @param params-vector of the parameters the user input
 * @return the result of the computation
 */
double Power::calcResult(double curr_val, std::vector<std::string> parameters)
{
	if(!utility::is_str_double(parameters[0]))
	{
		NaNException ne;
		std::string position;
		GET_CODE_POSITION(position);
		ne.appendOrigin(position);
		throw ne;
	}

	double input = utility::stod(parameters[0]);
	double result = std::pow(curr_val, input);
	//Assuming that the compilers works according to IEEE standard
	if(result != result)
	{
		NaNException ne("NaNException: bad power");
		std::string position;
		GET_CODE_POSITION(position);
		ne.appendOrigin(position);
		throw ne;
	}
	if(utility::is_overflowed(result))
	{
		OverflowException oe;
		std::string position;
		GET_CODE_POSITION(position);
		oe.appendOrigin(position);
		throw oe;
	}

	return result;
}
