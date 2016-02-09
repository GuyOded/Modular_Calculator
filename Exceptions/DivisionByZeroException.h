/*
 * DivisionByZeroException.h
 *
 *  Created on: Jan 31, 2016
 *      Author: guy
 */

#ifndef DIVISIONBYZEROEXCEPTION_H_
#define DIVISIONBYZEROEXCEPTION_H_

#include "MathException.h"
#include <string>

class DivisionByZeroException: public MathException {
private:
	std::string m_msg;
	static const std::string DEFAULT_MSG;
public:
	DivisionByZeroException(std::string msg = DEFAULT_MSG);
	virtual ~DivisionByZeroException();
	virtual const char* what() const throw();
};

#endif /* DIVISIONBYZEROEXCEPTION_H_ */
