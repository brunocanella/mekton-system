#include "pod.hpp"

namespace mekton {

Pod::Pod(string a_description, Model a_model, PtrArmor a_armor_ptr, uint a_extra_space_factor) :
	Servo( Type::Pod, a_description, a_model, a_armor_ptr, a_extra_space_factor ) {
	update();
}

Pod::~Pod() {
}

bool Pod::validate() {
	return validate_minimun_armor() &&
		Servo::validate();
}

bool Pod::validate_minimun_armor() {
	validation_assert(
		m_armor_ptr != nullptr && m_armor_ptr->model().value > 0 &&
		"Pods must have an armor rating of at least one"
	);
}

void Pod::update() {
	uint l_base = m_model.value;

	m_cost = static_cast<decimal>(l_base);
	m_space = l_base * 2;
	m_kills = 0;

	Servo::update();
}

} /*namespace mekton*/
