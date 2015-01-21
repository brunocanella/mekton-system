#include "frame.hpp"

#include <numeric>

namespace mekton {

Frame::Frame( const BodyFormData& a_bodyform, string a_description, Servos a_servos ) :
	m_bodyform(a_bodyform),
	m_description(a_description),
	m_servos( a_servos ) {
}

Frame::~Frame() {
}

BodyFormData Frame::bodyform() const {
	return m_bodyform;
}

string Frame::description() const {
    return m_description;
}

void Frame::description(const string& a_description) {
	m_description = a_description;
}

decimal Frame::total_weight() const {
	return std::accumulate( m_servos.begin(), m_servos.end(), 0.f, [](decimal a_total, const PtrServo& a_servo) {
		return a_total + a_servo->total_weight();
	});
}

decimal Frame::frame_weight() const {
	return std::accumulate( m_servos.begin(), m_servos.end(), 0.f, [](decimal a_total, const PtrServo& a_servo) {
		return a_total + a_servo->frame_weight();
	});
}

decimal Frame::servo_weight() const {
	return std::accumulate( m_servos.begin(), m_servos.end(), 0.f, [](decimal a_total, const PtrServo& a_servo) {
		return a_total + a_servo->weight();
	});
}

decimal Frame::armor_weight() const {
	return std::accumulate( m_servos.begin(), m_servos.end(), 0.f, [](decimal a_total, const PtrServo& a_servo) {
		return a_total + ( a_servo->armor_ptr() == nullptr ? 0.f : a_servo->armor_ptr()->weight() );
	});
}

Servos& Frame::servos() {
	return m_servos;
}

} /*namespace mekton*/
