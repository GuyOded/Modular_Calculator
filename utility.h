/*
 * basic_functions.h
 *
 *  Created on: Jan 28, 2016
 *      Author: guy
 */

#ifndef UTILITY_H_
#define UTILITY_H_

namespace utility
{
	bool is_str_double(std::string str);
	double stod(std::string str);
	bool is_overflowed(double d);
}

#endif /* UTILITY_H_ */
