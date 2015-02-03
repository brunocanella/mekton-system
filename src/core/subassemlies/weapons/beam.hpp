#ifndef BEAM_WEAPON_HPP_
#define BEAM_WEAPON_HPP_

#include "weapon.hpp"

namespace mekton {

class Beam : public Weapon {
public:
	class Shots : public WeaponModifierField<uint> {
		using WeaponModifierField::WeaponModifierField;
	};

	class WarmupTime : public WeaponModifierField<uint> {
		using WeaponModifierField::WeaponModifierField;
	};

	class WideAngle : public WeaponModifierField<string> {
		using WeaponModifierField::WeaponModifierField;
	};

	class BurstValue : public WeaponModifierField<uint> {
		using WeaponModifierField::WeaponModifierField;
	};

	class ClipFed : public WeaponFlag { public:
		ClipFed() : WeaponFlag( 0.9, "Clip Fed", "Weapon uses ammunition." ) {}
	};

	class AntiMissileOnly : public WeaponFlag { public:
		AntiMissileOnly() : WeaponFlag( 1.0, "Anti-Missile", "Can only be used against missiles" ){}
	};

	class AntiMissileVariable : public WeaponFlag { public:
		AntiMissileVariable() : WeaponFlag( 1.8, "Anti-Missile Variable", "Can hit normal targets, as well as missiles." ) {}
	};

	class AntiPersonnelOnly : public WeaponFlag { public:
		AntiPersonnelOnly() : WeaponFlag( 1.0, "Anti-Personnel", "Can only hit human targets or roadstrikers" ) {}
	};

	class AntiPersonnelVariable : public WeaponFlag { public:
		AntiPersonnelVariable() : WeaponFlag( 1.8, "Anti-Personnel Variable", "Can hit normal targets, as well as humans and roadstrikers" ) {}
	};

	class AntiMissilePersonnel : public WeaponFlag { public:
		AntiMissilePersonnel() : WeaponFlag( 1.8, "Anti-Missile & Personnel", "Can hit missiles, humans and/or roadstrikers" ) {}
	};

	class AllPurpose : WeaponFlag { public:
		AllPurpose() : WeaponFlag( 2.6, "All-Purpose", "Can hit normal targets, missiles, humans and/or roadstrikers" ) {}
	};

public:
	Beam(
		uint a_damage,
		RangeModifier a_range_mod,
		AccuracyModifier a_accuracy_mod,
		WeaponModifiers a_modifiers,
		WeaponFlags a_flags
	);
};

} /*namespace mekton*/


#endif // BEAM_WEAPON_HPP_
