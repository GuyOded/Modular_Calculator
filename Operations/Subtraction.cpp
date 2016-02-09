/*
 * Subtraction.cpp
 *
 *  Created on: Jan 31, 2016
 *      Author: guy
 */

#include "Subtraction.h"
#include <string>
#include <sstream>
#include "../Exceptions/Exceptions.h"
#include "../utility.h"

const std::string Subtraction::DEFAULT_OP_STRING = "-";

Subtraction::Subtraction(std::string op_string) : m_op_string(op_string) {
}

Subtraction::~Subtraction() {
}

/**
 * virtual bool supportsOperation(std::string op_string)
 *
 * checks if the given string is supported by the operation
 *
 * @param op_string - a given string parameter
 * @return true if the given string equals to the operation string
 */
bool Subtraction::supportsOperation(std::string op_string)
{
	return m_op_string == op_string;
}

/**
 * virtual int requiredParameters()
 *
 * @return the amount of parameters required by the operation
 */
int Subtraction::requiredParameters()
{
	return Subtraction::REQUIRED_PARAMS;
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
double Subtraction::calcResult(double curr_val, std::vector<std::string> parameters)
{
	//verify that input parameter is double, throw exception
	if(!utility::is_str_double(parameters[0]))
	{
		NaNException ne;
		std::string position;
		GET_CODE_POSITION(position);
		ne.appendOrigin(position);
		throw ne;
	}

	//convert string to double
	double input_num = utility::stod(parameters[0]);
	//overflow protection
	if(utility::is_overflowed(curr_val - input_num))
	{
		OverflowException oe;
		std::string position;
		GET_CODE_POSITION(position);
		oe.appendOrigin(position);
		throw oe;
	}
	return curr_val - input_num;
}



