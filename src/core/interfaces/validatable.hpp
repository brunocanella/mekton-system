#ifndef VALIDATABLE_HPP_
#define VALIDATABLE_HPP_

#include "typedefs.hpp"

namespace mekton {

/**
 * This macro may only be used inside validation functions.
 */
#define validation_assert( Condition ) \
do { \
	if( !(Condition) ) { \
		string l_str = #Condition; \
		status_error( l_str ); \
		return false; \
	} else { \
		status_validate(); \
		return true;\
	}\
} while(0)

/**
 * @brief Adds a validation status to a class. Mainly used by Servo classes.
 */
class Validatable {
public:
	enum class Status : uint {
		NotYetValidated,
		Error,
		Ok
	};

	Validatable() = default;
	virtual ~Validatable() = default;

	virtual bool validate() = 0;
protected:
	void status_validate();
	void status_invalidate();
	void status_error( const string& a_message );

private:
	/**Holds the validation status of the object*/
	Status m_status = Status::NotYetValidated;
	/**A message to inform the error condition*/
	string m_message = "";
};

} /* namespace mekton */

#endif // VALIDATABLE_HPP_
