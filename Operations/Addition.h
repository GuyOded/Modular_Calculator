/*
 * Addition.h
 *
 *  Created on: Jan 27, 2016
 *      Author: guy
 */

#ifndef ADDITION_H_
#define ADDITION_H_

#include "CalculatorOperation.h"
#include <string>
#include <vector>

class Addition: public CalculatorOperation {
private:
	static const int REQUIRED_PARAMS = 1; //represents the number of parameters required by the operation
	static const std::string DEFAULT_OP_STRING; //a default operation string to all instances
	std::string m_op_string;
public:
	Addition(std::string op_string = DEFAULT_OP_STRING);
	virtual ~Addition();
	virtual int requiredParameters();
	virtual bool supportsOperation(std::string op_string);
	virtual double calcResult(double curr_val,
							  std::vector<std::string> params);
};

#endif /* ADDITION_H_ */
