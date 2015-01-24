#ifndef WEAPONS_BEAM_MODIFIER_HPP
#define WEAPONS_BEAM_MODIFIER_HPP

#include "../weapon_modifier.hpp"

#include <vector>
#include <typedefs.hpp>

namespace mekton {
namespace Weapons {
namespace Beam {

class Modifier : public WeaponModifier {
public:
	using WeaponModifier::WeaponModifier;
	virtual ~Modifier();

	static Modifier fragile;
	static Modifier long_range;
	static Modifier hydro;
	static Modifier mega_beam;
	static Modifier disruptor;
};

typedef std::vector<Modifier> Modifiers;

} /*namespace Beam*/
} /*namespace Weapons*/
} /*namespace mekton*/

#endif // WEAPONS_BEAM_MODIFIER_HPP
