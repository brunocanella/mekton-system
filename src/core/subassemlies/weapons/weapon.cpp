#include "weapon.hpp"

namespace mekton {

Weapon::Weapon(
	uint a_damage,
	RangeModifier a_range_mod,
	AccuracyModifier a_accuracy_mod,
	WeaponModifiers a_modifiers,
	WeaponFlags a_flags) :
	m_range_mod( a_range_mod ),
	m_accuracy_mod( a_accuracy_mod ),
	m_damage( a_damage ),
	m_modifiers(a_modifiers),
	m_flags(a_flags) {

	m_modifiers.insert( m_range_mod );
	m_modifiers.insert( m_accuracy_mod );
}

WeaponType Weapon::type() const {
	return m_type;
}

void Weapon::type(const WeaponType& a_type) {
	m_type = a_type;
}

uint Weapon::damage() const {
	return m_damage;
}

void Weapon::damage(const uint& a_damage) {
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

WeaponModifiers& Weapon::modifiers() {
	return m_modifiers;
}

WeaponFlags& Weapon::flags() {
	return m_flags;
}

} /*namespace mekton*/
