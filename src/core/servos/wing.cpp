#include "wing.hpp"

namespace mekton {

Wing::Wing(
	string a_description,
	Model a_model,
	PtrArmor a_armor_ptr,
	uint a_extra_space_factor) :
	Servo( Type::Wing, a_description, a_model, a_armor_ptr, a_extra_space_factor ) {
	update();
}

Wing::~Wing() {
}

bool Wing::validate() {
	return Servo::validate();
}

void Wing::update() {
	uint l_base = m_model.value;

	m_cp = static_cast<decimal>(l_base);
	m_space = l_base;
	m_kills = l_base;

	Servo::update();
}

} /* namespace mekton */
