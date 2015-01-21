#include "validatable.hpp"

#include <stdexcept>

namespace mekton {

void Validatable::status_validate()
{
	m_status = Status::Ok;
}

void Validatable::status_invalidate()
{
	m_status = Status::NotYetValidated;
}

void Validatable::status_error( const string& a_message )
{
	m_status = Status::Error;
	m_message = a_message;
}

} /* namespace mekton */
