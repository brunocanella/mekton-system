#include "arm.hpp"

namespace mekton {

Arm::Arm(string a_description,
	Model a_model,
	PtrArmor a_armor_ptr,
	uint a_extra_space_factor,
	PtrHand a_hand_ptr) :
	Servo( Servo::Type::Arm, a_description, a_model, a_armor_ptr, a_extra_space_factor ),
	m_hand_ptr(a_hand_ptr) {
	update();
}

Arm::~Arm() {
}

bool Arm::validate() {
	return Servo::validate();
}

void Arm::update() {
	uint l_base = m_model.value + 1;

	m_cost = static_cast<decimal>(l_base);
	m_space = l_base;
	m_kills = l_base;

	m_add = static_cast<sint>( (m_model.value - 1) / 3 );
	m_throw_dist = 3 + static_cast<uint>( (m_model.value - 1) / 2 );

	Servo::update();

	/*if( m_hand_ptr != nullptr ) {
		m_weight += m_hand_ptr->weight();
	}*/
}

PtrHand Arm::hand_ptr() const
{
	return m_hand_ptr;
}

void Arm::hand_ptr(const PtrHand& a_hand_ptr)
{
	m_hand_ptr = a_hand_ptr;
	update();
}

sint Arm::add() const {
	return m_add;
}

uint Arm::throw_dist() const {
	return m_throw_dist;
}

decimal Arm::total_cost() const {
	return Servo::total_cost() +
		( m_hand_ptr == nullptr ? 0 : m_hand_ptr->cost() );
}

decimal Arm::frame_weight() const {
	return Servo::frame_weight() +
		( m_hand_ptr == nullptr ? 0 : m_hand_ptr->cost() );
}

decimal Arm::total_weight() const {
	return Servo::total_weight() +
		( m_hand_ptr == nullptr ? 0 : m_hand_ptr->weight() );
}

sint Arm::free_space() const {
	return Servo::free_space() -
		( m_hand_ptr == nullptr ? 0 : m_hand_ptr->space() );
}

} /* namespace mekton */
