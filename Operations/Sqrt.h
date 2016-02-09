/*
 * Sqrt.h
 *
 *  Created on: Feb 1, 2016
 *      Author: guy
 */

#ifndef SQRT_H_
#define SQRT_H_

#include "CalculatorOperation.h"
#include <string>
#include <vector>

class Sqrt: public CalculatorOperation {
private:
	static const std::string DEFAULT_OP_STRING;
	static const int REQUIRED_PARAMS = 0;
	std::string m_op_string;
public:
	Sqrt(std::string op_string = DEFAULT_OP_STRING);
	virtual ~Sqrt();
	virtual bool supportsOperation(std::string op_string);
		virtual int requiredParameters();
		virtual double calcResult(double curr_val, std::vector<std::string> parameters);
};

#endif /* SQRT_H_ */
