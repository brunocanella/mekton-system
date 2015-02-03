#include "weapon_modifier.hpp"

#include "weapon.hpp"

namespace mekton {

IWeaponModifier::IWeaponModifier(
	decimal a_cost_modifier
) :
	m_cost_modifier(a_cost_modifier) {
}

void IWeaponModifier::mod( Weapon& a_this ) {
	a_this.m_cost *= m_cost_modifier;
}

void IWeaponModifier::unmod( Weapon& a_this ) {
	a_this.m_cost /= m_cost_modifier;
}

bool IWeaponModifier::operator <(const IWeaponModifier& a_rhs) const {
	return this < &a_rhs;
}

} /*namespace mekton*/
