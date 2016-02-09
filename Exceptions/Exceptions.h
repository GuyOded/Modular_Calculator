/*
 * Exceptions.h
 *
 *  Created on: Jan 30, 2016
 *      Author: guy
 */

#ifndef EXCEPTIONS_H_
#define EXCEPTIONS_H_

#include "MathException.h"
#include "OverflowException.h"
#include "NaNException.h"
#include "DivisionByZeroException.h"

#include <sstream>

//This macro is usually associated with my exceptions
#define GET_CODE_POSITION(s) do{std::stringstream ss("");\
								ss  << "In " << __FILE__ << ":" << __LINE__;\
								ss << " " << __FUNCTION__ << "\n";\
								getline(ss, s);\
							   }while(0)
#endif /* EXCEPTIONS_H_ */
