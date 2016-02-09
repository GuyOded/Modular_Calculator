/*
 * MathException.cpp
 *
 *  Created on: Jan 30, 2016
 *      Author: guy
 */

#include "MathException.h"
#include <string>

MathException::MathException(std::string msg): m_msg(msg) {
	m_origin = "";
}

MathException::~MathException() {
}

/**
 * @return the location the exception was thrown from
 */
std::string MathException::originatedAt() const throw()
{
	return m_origin;
}

/**
 * @return the message that the exception carries
 */
const char* MathException::what() const throw(){
	return m_msg.c_str();
}

/**
 * adds a string to the back of m_origin - where the exception
 * was thrown
 *
 * @param str
 */
void MathException::appendOrigin(std::string str)
{
	m_origin = str + m_origin;
}
