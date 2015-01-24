#ifndef WEAPONTYPE_HPP_
#define WEAPONTYPE_HPP_

#include <typedefs.hpp>
#include <vector>

namespace mekton {

class WeaponType {
public:
	uint value;
	string description;
};

namespace WeaponTypes {
	namespace {
		const std::vector<WeaponType> weapon_types = {
			{ 1, "Beam" },
			{ 2, "Projectile" },
			{ 3, "Missile" },
			{ 4, "Melee" },
			{ 5, "Energy Melee" },
			{ 6, "Shields" }
		};
	}
	extern const WeaponType& Beam;
	extern const WeaponType& Projectile;
	extern const WeaponType& Missiles;
	extern const WeaponType& Melee;
	extern const WeaponType& EnergyMelee;
	extern const WeaponType& Shield;
}

} /*namespace mekton*/

#endif // WEAPONTYPE_HPP_
