#ifndef WEAPONS_BEAM_FLAG_HPP
#define WEAPONS_BEAM_FLAG_HPP

#include "../weapon_flag.hpp"

#include <vector>
#include <typedefs.hpp>

namespace mekton {
namespace Weapons {
namespace Beam {

class Flag : public WeaponFlag {
public:
	using WeaponFlag::WeaponFlag;
	virtual ~Flag();

	static Flag fragile;
	static Flag long_range;
	static Flag hydro;
	static Flag mega_beam;
	static Flag disruptor;
};

typedef std::vector<Flag> Flags;

} /*namespace Beam*/
} /*namespace Weapons*/
} /*namespace mekton*/

#endif // WEAPONS_BEAM_FLAG_HPP
