/*
 * NaNException.h
 *
 *  Created on: Jan 31, 2016
 *      Author: guy
 */

#ifndef NANEXCEPTION_H_
#define NANEXCEPTION_H_

#include "MathException.h"
#include <string>

class NaNException: public MathException {
private:
	std::string m_msg;
	static const std::string DEFAULT_MSG;
public:
	NaNException(std::string msg=DEFAULT_MSG);
	virtual ~NaNException();
	virtual const char* what() const throw();
};

#endif /* NANEXCEPTION_H_ */
