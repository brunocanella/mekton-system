#include "weapon_flag.hpp"

namespace mekton {

WeaponFlag::WeaponFlag(decimal a_cost_multiplier, string a_name, string a_description) :
	cost_multiplier(a_cost_multiplier),
	name(a_name),
	description(a_description) {
}

} /*namespace mekton*/
