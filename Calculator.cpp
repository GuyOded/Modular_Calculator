/*
 * Calculator.cpp
 *
 *  Created on: Jan 29, 2016
 *      Author: guy
 */

#include "Calculator.h"
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "Exceptions/Exceptions.h"
#include "Operations/Operations.h"

//TODO: Split parseOperation
//TODO: Add check local commands function
//TODO: start documenting

const std::string Calculator::DEFAULT_TERMINATION_STRING = "Off";

/**
 * Calculator(std::string termString = Calculator::DEFAULT_TERMINATION_STRING)
 *
 * a normal constructor
 *
 * @param term_string-The string that will turn off the calculator "Off" by default
 */
Calculator::Calculator(std::string term_string) : m_terminate(term_string) {
	m_mem = 0.0;
	m_on = true;
	m_operations[0] = new Addition();
	m_operations[1] = new Subtraction();
	m_operations[2] = new Multiplication();
	m_operations[3] = new Division();
	m_operations[4] = new Set();
	m_operations[5] = new Power();
	m_operations[6] = new Sqrt();
}

/**
 * virtual ~Calculator()
 *
 * destructor
 *
 * deletes elements of m_operations
 *
 */
Calculator::~Calculator() {
	for(CalculatorOperation *op_pointer:m_operations)
	{
		delete op_pointer;
	}
}

/**
 * void start()
 *
 * The main function that takes the input from the user and handles it.
 * Basically it is the main loop.
 */
void Calculator::start()
{
	std::string line = "";

	std::cout << "Welcome to Modular Calculator\n";

	while(m_on)
	{
		std::cout << "---> ";
		std::getline(std::cin, line);
		m_on = parseOperation(line);
		if(m_on)
			std::cout << "Current value: " << m_mem << std::endl;
	}
}

/**
 * bool parseOperation(std::string& input_line)
 *
 * Finds a matching operation to the one requested by the user and
 * from the operations list: m_operations saves it to a
 * provided pointer by reference
 *
 * @param op_string-searches a matching operation string in m_operations
 * @param cal_op-if a matching operation is found cal_op will save the value
 * @return true if a matching operation is found false otherwise
 */
bool Calculator::findOpstring(std::string& op_string, CalculatorOperation*& cal_op) const
{
	for(CalculatorOperation *c:m_operations)
	{
		if(c->supportsOperation(op_string))
		{
			cal_op = c;
			return true;
		}
	}
	return false;
}

/**
 * bool validateParameters(int paramsLength, CalculatorOperation *const cal_op) const
 *
 * Checks if the number of parameters given by the user equals to
 * the number of parameters required by the operation
 *
 * @param params_length-number of parameters
 * @param cal_op-the operation that the user typed
 * @return true if the number of params_length equals
 * 		   to the number of parameters required by the operations
 */
bool Calculator::validateParameters(int params_length, CalculatorOperation *const cal_op) const
{
	int required_params = cal_op->requiredParameters();
	if(params_length != required_params)
	{
		std::cout << "Wrong number of parameters. Got: " << params_length
				  << " Expected: " << required_params << std::endl;
		return false;
	}
	return true;
}

/**
 * void updateMem(CalculatorOperation*& cal_op, std::vector<std::string> parameters)
 *
 * Safely calls the operation's calcResult function - catches any
 * exceptions that may be thrown and handles them
 *
 * @param cal_op-The operation that is being called
 * @param parameters-The parameters given by the user(if any)
 */
void Calculator::updateMem(CalculatorOperation*& cal_op, std::vector<std::string> parameters)
{
	double try_result;
	try
	{
		try_result = cal_op->calcResult(m_mem, parameters);
	}
	catch(const MathException& me)
	{
		std::cout << me.what() << std::endl;
		if(DEBUG)
		{
			//prints where in the code the exception was thrown
			std::cout << me.originatedAt() << "\n";
		}
		return;
	}
	m_mem = try_result;
}

/**
 * bool parseOperation(std::string& input_line)
 *
 * Parse the input line and validates everything
 * (that function may be too long)
 *
 * @param input_line - line that has been read from std input
 * @return false if the command read was m_terminate - thus the calculator
 * 		   needs to be turned off
 */
bool Calculator::parseOperation(std::string& input_line)
{
	//Prevent "unlimited" line length
	if(input_line.size() > Calculator::MAX_INPUT_LENGTH)
	{
		std::cout << "Input too long" << std::endl;
		return true;
	}
	if(DEBUG)
		std::cout << input_line << std::endl;

	std::istringstream ss(input_line);
	std::vector<std::string> parameters;

	//extract operation string from input line
	std::string op_string = "";
	ss >> op_string;
	if(DEBUG)
		std::cout << "opstring = " << op_string << "\n";

	if(op_string == m_terminate)
		return false;

	CalculatorOperation *cal_op = NULL;
	if(!findOpstring(op_string, cal_op))
	{
		std::cout << "Unknown operation: " << op_string << std::endl;
		return true;
	}

	//extract parameters into vector
	std::string param = "";
	while(ss >> param)
		parameters.push_back(param);

	if(DEBUG)
		printParams(parameters);

	if(!validateParameters(parameters.size(), cal_op))
		return true;

	//safely update the memory - handle exceptions
	updateMem(cal_op, parameters);

	return true;
}

/**
 * void printParams(std::vector<std::string> parameters) const
 *
 * For debugging purposes
 *
 * prints the parameters to standard output, for debug purposes
 *
 * @param parameters-vector of parameters
 */
void Calculator::printParams(std::vector<std::string> parameters) const
{
	int i = 0;
	for(std::vector<std::string>::iterator it = parameters.begin();
			it != parameters.end(); ++it, ++i)
	{
		std::cout << i << ": " << *it << "\n";
	}

	std::cout << std::endl;
}
