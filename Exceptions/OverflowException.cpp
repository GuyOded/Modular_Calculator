/*
 * OverflowException.cpp
 *
 *  Created on: Jan 30, 2016
 *      Author: guy
 */

#include "OverflowException.h"

OverflowException::OverflowException(std::string msg)
	:MathException(), m_msg(msg) {

}

OverflowException::~OverflowException() {
}

/**
 *
 * returns a message string regarding the exception that has been thrown
 *
 * @return the combined string of this m_msg and base m_msg
 */
const char* OverflowException::what() const throw()
{
	std::string base_what = MathException::what();
	base_what += ":" + m_msg;
	return base_what.c_str();
}
