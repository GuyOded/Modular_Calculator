/*
 * NaNException.cpp
 *
 *  Created on: Jan 31, 2016
 *      Author: guy
 */

#include "NaNException.h"
#include <string>

const std::string NaNException::DEFAULT_MSG = "NaNException";

NaNException::NaNException(std::string msg)
	:MathException(), m_msg(msg) {
}

NaNException::~NaNException() {
}

/**
 *
 * returns a message string regarding the exception that has been thrown
 *
 * @return the combined string of this m_msg and base m_msg
 */
const char* NaNException::what() const throw()
{
	std::string base_what = MathException::what();
	base_what += ":" + m_msg;
	return base_what.c_str();
}
