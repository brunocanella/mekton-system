#ifndef WEAPONS_BEAM_RANGE_HPP_
#define WEAPONS_BEAM_RANGE_HPP_

#include <typedefs.hpp>
#include <vector>

#include "../weapon_modifier.hpp"

namespace mekton {
namespace Weapons {
namespace Beam {

class Range : public WeaponModifier<decimal> {
public:
	using WeaponModifier::WeaponModifier;
	virtual ~Range() = default;

	class hidden { public:
		static std::vector<Range> data;
	};

	static Range& percent_25;
	static Range& percent_50;
	static Range& percent_75;
	static Range& percent_100;
	static Range& percent_125;
	static Range& percent_150;
	static Range& percent_175;
	static Range& percent_200;
	static Range& percent_250;
	static Range& percent_300;
};

} /*namespace Beam*/
} /*namespace Weapons*/
} /*namespace mekton*/

#endif // WEAPONS_BEAM_RANGE_HPP_
