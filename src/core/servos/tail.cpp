#include "tail.hpp"

namespace mekton {

Tail::Tail(
	string a_description,
	Model a_model,
	PtrArmor a_armor_ptr,
	uint a_extra_space_factor) :
	Servo( Type::Tail, a_description, a_model, a_armor_ptr, a_extra_space_factor ) {
	update();
}

Tail::~Tail() {
}

bool Tail::validate() {
	return Servo::validate();
}

void Tail::update() {
	uint l_base = m_model.value;

	m_cost = static_cast<decimal>(l_base);
	m_space = l_base;
	m_kills = l_base;

	Servo::update();
}

} /* namespace mekton */
