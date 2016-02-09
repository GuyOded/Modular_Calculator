/*
 * Multiplication.h
 *
 *  Created on: Jan 31, 2016
 *      Author: guy
 */

#ifndef MULTIPLICATION_H_
#define MULTIPLICATION_H_

#include "CalculatorOperation.h"
#include <string>
#include <vector>

class Multiplication: public CalculatorOperation {
private:
	static const std::string DEFAULT_OP_STRING;
	static const int REQUIRED_PARAMS = 1;
	std::string m_op_string;
public:
	Multiplication(std::string op_string = DEFAULT_OP_STRING);
	virtual ~Multiplication();
	virtual bool supportsOperation(std::string op_string);
	virtual int requiredParameters();
	virtual double calcResult(double curr_val, std::vector<std::string> parameters);
};

#endif /* MULTIPLICATION_H_ */
