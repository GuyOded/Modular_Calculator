/*
 * Addition.cpp
 *
 *  Created on: Jan 27, 2016
 *      Author: guy
 */

#include "Addition.h"

#include <string>
#include "../Exceptions/Exceptions.h"
#include "../utility.h"

const std::string Addition::DEFAULT_OP_STRING = "+";

Addition::Addition(std::string op_string) : m_op_string(op_string) {
}

Addition::~Addition() {
}

/**
 * virtual int requiredParameters()
 *
 * @return the amount of parameters required by the operation
 */
int Addition::requiredParameters()
{
	return Addition::REQUIRED_PARAMS;
}

/**
 * virtual bool supportsOperation(std::string op_string)
 *
 * checks if the given string is supported by the operation
 *
 * @param op_string - a given string parameter
 * @return true if the given string equals to the operation string
 */
bool Addition::supportsOperation(std::string op_string)
{
	return op_string == m_op_string;
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
double Addition::calcResult(double curr_val, std::vector<std::string> params)
{
	double value = 0.0;

	//throw NaNException if the input isn't a number
	//Can you suggest a better way to implement this part(maybe a Macro)?
	//This if is super repetitive, how is it avoidable?
	if(!utility::is_str_double(params[0]))
	{
		NaNException ne;
		std::string position;
		GET_CODE_POSITION(position);
		ne.appendOrigin(position);
		throw ne;
	}

	value = utility::stod(params[0]);
	//throw OverflowException if the operation result is overflowed
	if(utility::is_overflowed(curr_val + value))
	{
		OverflowException oe;
		std::string position;
		GET_CODE_POSITION(position);
		oe.appendOrigin(position);
		throw oe;
	}


	return curr_val + value;
}

