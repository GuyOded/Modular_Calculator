/*
 * Subtraction.h
 *
 *  Created on: Jan 31, 2016
 *      Author: guy
 */

#ifndef SUBTRACTION_H_
#define SUBTRACTION_H_

#include "CalculatorOperation.h"
#include <string>

class Subtraction: public CalculatorOperation {
private:
	static const std::string DEFAULT_OP_STRING;
	static const int REQUIRED_PARAMS = 1;
	std::string m_op_string;
public:
	Subtraction(std::string op_string = DEFAULT_OP_STRING);
	virtual ~Subtraction();
	virtual bool supportsOperation(std::string op_string);
	virtual int requiredParameters();
	virtual double calcResult(double curr_val, std::vector<std::string> parameters);
};

#endif /* SUBTRACTION_H_ */
