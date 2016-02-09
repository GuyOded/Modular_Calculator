/*
 * DivisionByZeroException.cpp
 *
 *  Created on: Jan 31, 2016
 *      Author: guy
 */

#include "DivisionByZeroException.h"

const std::string DivisionByZeroException::DEFAULT_MSG = "DivisionByZeroException";

DivisionByZeroException::DivisionByZeroException(std::string msg)
:MathException(), m_msg(msg)
	{}

DivisionByZeroException::~DivisionByZeroException() {
}

/**
 *
 * returns a message string regarding the exception that has been thrown
 *
 * @return the combined string of this m_msg and base m_msg
 */
const char* DivisionByZeroException::what() const throw()
{
	std::string base_string = MathException::what();
	base_string += ":" + m_msg;
	return base_string.c_str();
}
