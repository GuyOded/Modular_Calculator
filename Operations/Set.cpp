/*
 * Set.cpp
 *
 *  Created on: Feb 1, 2016
 *      Author: guy
 */

#include "Set.h"
#include <string>
#include <vector>
#include "../Exceptions/Exceptions.h"
#include "../utility.h"

const std::string Set::DEFAULT_OP_STRING = "Set";

Set::Set(std::string op_string) : m_op_string(op_string){
}

Set::~Set() {
}

/**
 * virtual int requiredParameters()
 *
 *@return the amount of parameters required by the operation
 */
int Set::requiredParameters()
{
	return Set::REQUIRED_PARAMS;
}

/**
 * virtual bool supportsOperation(std::string op_string)
 *
 * checks if the given string is supported by the operation
 *
 * @param op_string - a given string parameter
 * @return true if the given string equals to the operation string
 */
bool Set::supportsOperation(std::string op_string)
{
	return m_op_string == op_string;
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
double Set::calcResult(double curr_val, std::vector<std::string> parameters)
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
	if(utility::is_overflowed(input))
	{
		OverflowException oe;
		std::string position;
		GET_CODE_POSITION(position);
		oe.appendOrigin(position);
		throw oe;
	}

	return input;
}
