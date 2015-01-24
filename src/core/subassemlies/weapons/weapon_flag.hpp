#ifndef WEAPONFLAG_HPP
#define WEAPONFLAG_HPP

#include <typedefs.hpp>

namespace mekton {

class WeaponFlag {
public:
	WeaponFlag( decimal a_cost_multiplier, string a_name, string a_description = "" );
	virtual ~WeaponFlag() = default;

	decimal cost_multiplier;
	string name;
	string description;
};

/*
class Weapon {
public:
	Weapon( bool a_throwable ) : throwable( 0.6, "throwable", a_throwable) {
		throwable.description = "Enables you to throw your melee weapon";
	}
	WeaponFlag throwable;
};

void foo() {
	WeaponFlag throwable( 0.6, "throwable", false );

	throwable = true;

	if( throwable ) {
		throwable = false;
	}
}
*/

} /*namespace mekton*/

#endif // WEAPONFLAG_HPP
