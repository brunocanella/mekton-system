#ifndef WARNING_HPP_
#define WARNING_HPP_

#include <string>
#include <sstream>
#include <exception>

class Warning : public std::exception {
public:
	Warning( std::string a_message ) : std::exception(), m_message(a_message) {}
	virtual ~Warning() = default;

	const char* what() { return m_message.c_str(); }
private:
	std::string m_message;
};

/**
 * Throws a Warning for the cases when the given condition fails.
 */
#define warning( a_condition ) \
do { \
	if( !(a_condition) ) { \
		std::stringstream l_string; \
		l_string << #a_condition; \
		l_string << ", file " << __FILE__; \
		l_string << ", line " << __LINE__; \
		throw Warning( l_string.str() ); \
	} \
} while(0)


#endif // WARNING_HPP_
