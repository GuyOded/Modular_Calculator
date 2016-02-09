/*
 * CalculatorOperation.h
 *
 *	An abstract class that contains three pure virtual functions.
 *	It is the base class of all the calculator operations, hence all
 *	calculator operations must provide an implementation to these
 *	three functions.
 *
 *  Created on: Jan 27, 2016
 *      Author: guy
 */

#ifndef CALCULATOROPERATION_H_
#define CALCULATOROPERATION_H_

#include <string>
#include <vector>

class CalculatorOperation {
public:
	CalculatorOperation();
	virtual ~CalculatorOperation();

	virtual bool supportsOperation(std::string op_string) = 0;
	virtual int requiredParameters() = 0;
	virtual double calcResult(double curr_val, std::vector<std::string> parameters) = 0;
};

#endif /* CALCULATOROPERATION_H_ */
