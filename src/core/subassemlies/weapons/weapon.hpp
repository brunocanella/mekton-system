#ifndef WEAPON_HPP_
#define WEAPON_HPP_

#include "../subassembly.hpp"
#include "weapon_type.hpp"
#include "weapon_modifier.hpp"
#include "weapon_flag.hpp"

namespace mekton {

class Weapon : public Subassembly {
public: // Friends and weapon modifiers
	friend class IWeaponModifier;
	template<typename> friend class WeaponModifier;

	class RangeModifier : public WeaponModifierProduct<decimal> {
	public:
		RangeModifier( decimal a_multiplier, decimal a_cost_multiplier ) :
			WeaponModifierProduct( a_multiplier, a_cost_multiplier, &Weapon::m_range ) {
		}
	};

	class AccuracyModifier : public WeaponModifierSum<sint> {
	public:
		AccuracyModifier( sint a_adder, decimal a_cost_multiplier ) :
			WeaponModifierSum( a_adder, a_cost_multiplier, &Weapon::m_accuracy ) {
		}
	};

public: // Constructor & Methods
	Weapon(
		uint a_damage,
		RangeModifier a_range_mod,
		AccuracyModifier a_accuracy_mod,
		WeaponModifiers a_modifiers,
		WeaponFlags a_flags
	);
	virtual ~Weapon() = default;

	WeaponType type() const;
	void type(const WeaponType& a_type);

	uint damage() const;
	void damage(const uint& a_damage);

	uint range() const;
	void range(const uint& a_range);

	sint accuracy() const;
	void accuracy(const sint& a_accuracy);

	WeaponModifiers& modifiers();

	WeaponFlags& flags();

protected:
	RangeModifier m_range_mod;
	AccuracyModifier m_accuracy_mod;

	WeaponType m_type;
	uint m_damage;
	decimal m_range;
	sint m_accuracy;

	WeaponModifiers m_modifiers;
	WeaponFlags m_flags;
};

} /*namespace mekton*/

#endif // WEAPON_HPP_
