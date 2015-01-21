#ifndef BODYFORM_HPP
#define BODYFORM_HPP

#include <typedefs.hpp>
#include <vector>

namespace mekton {

class BodyFormData {
public:
	string description;
};

namespace BodyForm {
	namespace {
		const std::vector<BodyFormData> bodyforms = {
			{ "Mekton" },
			{ "MechaBeast" },
			{ "MechaTank" },
			{ "MechaFighter" },
		};
	}
	extern const BodyFormData& Mekton;
	extern const BodyFormData& MechaBeast;
	extern const BodyFormData& MechaTank;
	extern const BodyFormData& MechaFighter;
}

} /*namespace mekton*/

#endif // BODYFORM_HPP

