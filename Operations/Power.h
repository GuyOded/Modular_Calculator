/*
 * Power.h
 *
 *  Created on: Feb 1, 2016
 *      Author: guy
 */

#ifndef POWER_H_
#define POWER_H_

#include "CalculatorOperation.h"
#include <string>
#include <vector>

class Power: public CalculatorOperation {
private:
	static const std::string DEFAULT_OP_STRING;
	static const int REQUIRED_PARAMS = 1;
	std::string m_op_string;
public:
	Power(std::string op_string = DEFAULT_OP_STRING);
	virtual ~Power();
	virtual bool supportsOperation(std::string op_string);
	virtual int requiredParameters();
	virtual double calcResult(double curr_val, std::vector<std::string> parameters);
};

#endif /* POWER_H_ */
