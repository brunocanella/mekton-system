#ifndef FRAME_HPP_
#define FRAME_HPP_

#include <typedefs.hpp>
#include "bodyform.hpp"
#include "../servos/servos.hpp"

namespace mekton {

class Frame {
public:
	Frame( const BodyFormData& a_bodyform, string a_description , Servos a_servos );
	virtual ~Frame();

	BodyFormData bodyform() const;

	string description() const;
	void description(const string& a_description);

	Servos& servos();

	decimal total_weight() const;

	decimal frame_weight() const;

	decimal servo_weight() const;

	decimal armor_weight() const;
private:

	const BodyFormData& m_bodyform;
	string m_description;

	Servos m_servos;
};

}

#endif // FRAME_HPP_
