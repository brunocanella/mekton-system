#include "leg.hpp"

#include "../interfaces/validatable.hpp"

namespace mekton {

Leg::Leg(
	string a_description,
	Model a_model,
	PtrArmor a_armor_ptr,
	uint a_extra_space_factor,
	PtrFoot a_foot_ptr ) :
	Servo( Type::Leg, a_description, a_model, a_armor_ptr, a_extra_space_factor ),
	m_foot_ptr(a_foot_ptr) {
	update();
}

Leg::~Leg() {
}

bool Leg::validate() {
	return Servo::validate();
}

bool Leg::validate_foot() {
	validation_assert( m_foot_ptr != nullptr && "All legs must have a foot" );
}

void Leg::update() {
	uint l_base = m_model.value + 1;

	m_cp = static_cast<decimal>(l_base);
	m_space = l_base;
	m_kills = l_base;
	m_add = static_cast<sint>( (m_model.value - 1) / 2 );

	Servo::update();

	/*if( m_foot_ptr != nullptr ) {
		m_weight += m_foot_ptr->weight();
	}*/
}

PtrFoot Leg::foot_ptr() const {
	return m_foot_ptr;
}

void Leg::foot_ptr(const PtrFoot& a_foot_ptr)
{
	m_foot_ptr = a_foot_ptr;
	update();
}

sint Leg::add() const {
	return m_add;
}

decimal Leg::total_cost() const {
	return Servo::total_cost() +
		( m_foot_ptr == nullptr ? 0 : m_foot_ptr->cp() );
}

decimal Leg::frame_weight() const {
	return Servo::frame_weight() +
		( m_foot_ptr == nullptr ? 0 : m_foot_ptr->cp() );
}

decimal Leg::total_weight() const {
	return Servo::total_weight() +
		( m_foot_ptr == nullptr ? 0 : m_foot_ptr->weight() );
}

sint Leg::free_space() const {
	return Servo::free_space() -
		( m_foot_ptr == nullptr ? 0 : m_foot_ptr->space() );
}

} /*namespace mekton*/
