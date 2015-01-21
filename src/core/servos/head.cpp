#include "head.hpp"

namespace mekton {

Head::Head(
	string a_description,
	Model a_model,
	PtrArmor a_armor_ptr,
	uint a_extra_space_factor) :
	Servo( Type::Head, a_description, a_model, a_armor_ptr, a_extra_space_factor ) {
	update();
}

Head::~Head() {
}

bool Head::validate() {
	return Servo::validate();
}

void Head::update() {
	uint l_base = m_model.value;

	m_cost = static_cast<decimal>(l_base);
	m_space = l_base;
	m_kills = l_base;

	Servo::update();
}

} /* namespace mekton */
