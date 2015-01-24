#ifndef WEAPON_HPP_
#define WEAPON_HPP_

#include "../subassembly.hpp"
#include "weapon_type.hpp"

namespace mekton {

class Weapon : public Subassembly {
public:
	Weapon( WeaponType a_type, string a_name, uint a_range, sint a_weapon_accuracy, sint a_defense_accuracy, sint a_damage, sint a_shots, sint a_burst_value, sint a_stopping_power, decimal a_cost, decimal a_weight, uint a_kills, uint a_space, string a_description);
	virtual ~Weapon() = default;

	WeaponType type() const;
	void type(const WeaponType& a_type);

	sint damage() const;
	void damage(const sint& a_damage);

	uint range() const;
	void range(const uint& a_range);

	sint accuracy() const;
	void accuracy(const sint& a_accuracy);

	sint shots() const;
	void shots(const sint& a_shots);
protected:
	WeaponType m_type;
	sint m_damage;
	uint m_range;
	sint m_accuracy;
	sint m_shots;
};

} /*namespace mekton*/

#endif // WEAPON_HPP_
