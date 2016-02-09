/*
 * Calculator.h
 *
 *  Created on: Jan 29, 2016
 *      Author: guy
 */

#ifndef CALCULATOR_H_
#define CALCULATOR_H_
#include <string>
#include <vector>
#include "Operations/CalculatorOperation.h"

//Should it be a static variable? I don't think so...
const bool DEBUG = false;//for debugging purposes-if true
						 //the parameters and input line will be
						 //printed each line input, plus

class Calculator {
private:
	double m_mem; //mem as in memory
	bool m_on; //as long as this boolean is true keep requesting input
			   //from the user
	CalculatorOperation *m_operations[7]; //The array that keeps all the operations
									      //It's elements are allocated dynamically
	void printParams(std::vector<std::string> parameters) const;
	static const std::string DEFAULT_TERMINATION_STRING;
	static const int MAX_INPUT_LENGTH = 20; //Maximum characters
	const std::string m_terminate;
	void updateMem(CalculatorOperation*& cal_op, std::vector<std::string> parameters);

	//Copy constructor and assignment operator
	//These aren't defined to prevent use and minimize
	//risk of double deletion of m_operations, therefore they are declared as private
	Calculator(const Calculator& calc);
	Calculator& operator =(const Calculator& calc);

public:
	Calculator(std::string termString = Calculator::DEFAULT_TERMINATION_STRING);
	virtual ~Calculator();
	void start();
	bool parseOperation(std::string& input_line);
	bool findOpstring(std::string& op_string, CalculatorOperation*& cal_op) const;
	bool validateParameters(int paramsLength, CalculatorOperation *const cal_op) const;
};

#endif /* CALCULATOR_H_ */
