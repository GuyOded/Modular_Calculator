/*
 * Division.h
 *
 *  Created on: Feb 1, 2016
 *      Author: guy
 */

#ifndef DIVISION_H_
#define DIVISION_H_

#include "CalculatorOperation.h"
#include <string>
#include <vector>

class Division: public CalculatorOperation {
private:
	static const std::string DEFAULT_OP_STRING;
	static const int REQUIRED_PARAMS = 1;
	std::string m_op_string;
public:
	Division(std::string op_string = DEFAULT_OP_STRING);
	virtual ~Division();
	virtual bool supportsOperation(std::string op_string);
	virtual int requiredParameters();
	virtual double calcResult(double curr_val,
							  std::vector<std::string> parameters);
};

#endif /* DIVISION_H_ */
