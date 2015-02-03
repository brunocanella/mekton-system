#include "beam.hpp"

#include <cmath>

namespace mekton {

Beam::Beam(
	uint a_damage,
	RangeModifier a_range_mod,
	AccuracyModifier a_accuracy_mod,
	WeaponModifiers a_modifiers,
	WeaponFlags a_flags
) :
	Weapon( a_damage, a_range_mod, a_accuracy_mod, a_modifiers, a_flags )
{
	m_range = std::round( std::sqrt( static_cast<decimal>(a_damage) ) * 4.0	);
	m_cost = static_cast<decimal>(a_damage) * 1.5f;
}

} /*namespace mekton*/


