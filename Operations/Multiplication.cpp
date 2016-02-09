/*
 * Multiplication.cpp
 *
 *  Created on: Jan 31, 2016
 *      Author: guy
 */

#include "Multiplication.h"
#include "../Exceptions/Exceptions.h"
#include <string>
#include <vector>

#include "../utility.h"

const std::string Multiplication::DEFAULT_OP_STRING = "*";

Multiplication::Multiplication(std::string op_string) : m_op_string(op_string) {
}

Multiplication::~Multiplication() {
}

/**
 * virtual bool supportsOperation(std::string op_string)
 *
 * checks if the given string is supported by the operation
 *
 * @param op_string - a given string parameter
 * @return true if the given string equals to the operation string
 */
bool Multiplication::supportsOperation(std::string op_string)
{
	return m_op_string == op_string;
}

/**
 * virtual int requiredParameters()
 *
 *@return the amount of parameters required by the operation
 */
int Multiplication::requiredParameters()
{
	return Multiplication::REQUIRED_PARAMS;
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
double Multiplication::calcResult(double curr_val,
		std::vector<std::string> parameters)
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
	if(utility::is_overflowed(input * curr_val))
	{
		OverflowException oe;
		std::string position;
		GET_CODE_POSITION(position);
		oe.appendOrigin(position);
		throw oe;
	}

	return input * curr_val;
}
