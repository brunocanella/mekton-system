#ifndef WEAPONDAMAGE_HPP_
#define WEAPONDAMAGE_HPP_

#include <typedefs.hpp>

namespace mekton {

class WeaponDamage {
public:
	WeaponDamage( uint a_damage, decimal a_cost, uint a_range );
	virtual ~WeaponDamage() = default;

	uint damage;
	decimal cost;
	uint range;
};

} /*namespace mekton*/

#endif // WEAPONDAMAGE_HPP_
