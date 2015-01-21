#ifndef PROPERTY_HPP
#define PROPERTY_HPP

#include <ostream>
#include <functional>

template <typename T> class Property {
public:
	Property() = default;
	Property( T a_value ) : m_value(a_value) {
	}

	T & operator = (const T &i) {
		m_value = i;
		if( on_after_set ) {
			on_after_set();
		}
		return m_value;
	}

	// Implicit conversion back to T.
	operator T const & () const {
		return m_value;
	}

	friend std::ostream& operator<<( std::ostream &a_stream, const Property<T>& a_rhs )
	{
		a_stream << a_rhs.m_value;
		return a_stream;
	}

	friend bool operator==( const Property<T>& a_lhs, const T& a_rhs ) {
		return a_lhs.m_value == a_rhs;
	}

	std::function<void()> on_after_set;
private:
	T m_value;
};

#endif // PROPERTY_HPP
