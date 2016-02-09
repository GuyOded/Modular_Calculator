/*
 * Set.h
 *
 *  Created on: Feb 1, 2016
 *      Author: guy
 */

#ifndef SET_H_
#define SET_H_

#include "CalculatorOperation.h"
#include <string>
#include <vector>

class Set: public CalculatorOperation {
private:
	static const std::string DEFAULT_OP_STRING;
	static const int REQUIRED_PARAMS = 1;
	std::string m_op_string;
public:
	Set(std::string op_string = DEFAULT_OP_STRING);
	virtual ~Set();
	virtual bool supportsOperation(std::string op_string);
	virtual int requiredParameters();
	virtual double calcResult(double curr_val, std::vector<std::string> parameters);
};

#endif /* SET_H_ */
