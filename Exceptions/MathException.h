/*
 * MathException.h
 *
 *  Created on: Jan 30, 2016
 *      Author: guy
 */

#ifndef MATHEXCEPTION_H_
#define MATHEXCEPTION_H_
#include <exception>
#include <string>

class MathException: public std::exception{
private:
	std::string m_origin;//The original place the exception was thrown form
	std::string m_msg;//The message attached to the exception
public:
	MathException(std::string msg = "MathException");
	virtual ~MathException();
	virtual const char* what() const throw();
	std::string originatedAt() const throw();
	void appendOrigin(std::string str);
};

#endif /* MATHEXCEPTION_H_ */
