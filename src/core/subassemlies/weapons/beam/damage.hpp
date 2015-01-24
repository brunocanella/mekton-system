#ifndef WEAPONS_BEAM_DAMAGE_HPP_
#define WEAPONS_BEAM_DAMAGE_HPP_

#include <vector>

#include "../weapon_damage.hpp"


namespace mekton {
namespace Weapons {
namespace Beam {

class Damage : public WeaponDamage {
public:
	using WeaponDamage::WeaponDamage;
	virtual ~Damage() = default;

	class hidden { public:
	   static std::vector<Damage> data;
	};

	static Damage& kills_1;
	static Damage& kills_2;
	static Damage& kills_3;
	static Damage& kills_4;
	static Damage& kills_5;
	static Damage& kills_6;
	static Damage& kills_7;
	static Damage& kills_8;
	static Damage& kills_9;
	static Damage& kills_10;
	static Damage& kills_11;
	static Damage& kills_12;
	static Damage& kills_13;
	static Damage& kills_14;
	static Damage& kills_15;
	static Damage& kills_16;
	static Damage& kills_17;
	static Damage& kills_18;
	static Damage& kills_19;
	static Damage& kills_20;
};

} /*namespace Beam*/
} /*namespace Weapons*/
} /*namespace mekton*/


#endif // WEAPONS_BEAM_DAMAGE_HPP_
