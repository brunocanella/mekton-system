#ifndef ENSURE_HPP_
#define ENSURE_HPP_

#include <stdexcept>
#include <sstream>

/**
 * Behaves like an assert function, but it throws an runtime_error exception
 */
#define ensure( a_condition ) \
do { \
	if( !(a_condition) ) { \
		std::stringstream l_string; \
		l_string << #a_condition; \
		l_string << ", file " << __FILE__; \
		l_string << ", line " << __LINE__; \
		throw std::runtime_error( l_string.str() ); \
	} \
} while(0)

#endif // ENSURE_HPP_
