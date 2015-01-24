#include "weapon.hpp"

namespace mekton {

/*
Weapon::Weapon(WeaponType a_type,
	string a_name,
		uint a_range,
		sint a_weapon_accuracy,
		sint a_defense_accuracy,
		sint a_damage,
		sint a_shots,
		sint a_burst_value,
		sint a_stopping_power,
		decimal a_cost,
		decimal a_weight,
		uint a_kills,
		uint a_space,
		string a_description
) :
	Subassembly( a_name, a_cost, a_weight, a_kills, a_space, a_description ),
		m_type(a_type),
		m_range(a_range),
		m_weapon_accuracy(a_weapon_accuracy),
		m_defense_accuracy(a_defense_accuracy),
		m_damage(a_damage),
		m_shots(a_shots),
		m_burst_value(a_burst_value),
		m_stopping_power(a_stopping_power) {
}
*/

WeaponType Weapon::type() const {
	return m_type;
}

void Weapon::type(const WeaponType& a_type) {
	m_type = a_type;
}

sint Weapon::damage() const {
	return m_damage;
}

void Weapon::damage(const sint& a_damage) {
	m_damage = a_damage;
}

uint Weapon::range() const {
	return m_range;
}

void Weapon::range(const uint& a_range) {
	m_range = a_range;
}

sint Weapon::accuracy() const {
	return m_accuracy;
}

void Weapon::accuracy(const sint& a_accuracy) {
	m_accuracy = a_accuracy;
}

sint Weapon::shots() const {
	return m_shots;
}

void Weapon::shots(const sint& a_shots) {
	m_shots = a_shots;
}

} /*namespace mekton*/
