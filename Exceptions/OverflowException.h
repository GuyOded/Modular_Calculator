/*
 * OverflowException.h
 *
 *  Created on: Jan 30, 2016
 *      Author: guy
 */

#ifndef OVERFLOWEXCEPTION_H_
#define OVERFLOWEXCEPTION_H_

#include "MathException.h"
#include <string>

class OverflowException: public MathException {
private:
	std::string m_msg;
public:
	OverflowException(std::string msg = "OverflowException");
	virtual ~OverflowException();
	virtual const char* what() const throw();
};

#endif /* OVERFLOWEXCEPTION_H_ */
